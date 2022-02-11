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
if ( F_4 ( V_5 -> V_6 . V_7 ) )
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
static unsigned long F_5 ( struct V_8 * V_8 )
{
int V_9 ;
V_9 = F_6 ( V_8 , V_10 ) +
F_6 ( V_8 , V_11 ) ;
if ( F_7 () > 0 )
V_9 += F_6 ( V_8 , V_12 ) +
F_6 ( V_8 , V_13 ) ;
return V_9 ;
}
bool F_8 ( struct V_8 * V_8 )
{
return F_6 ( V_8 , V_14 ) <
F_5 ( V_8 ) * 6 ;
}
static unsigned long F_9 ( struct V_15 * V_15 , enum V_16 V_17 )
{
if ( ! F_10 () )
return F_11 ( V_15 , V_17 ) ;
return F_6 ( F_12 ( V_15 ) , V_18 + V_17 ) ;
}
int F_13 ( struct V_19 * V_19 )
{
T_1 V_20 = sizeof( * V_19 -> V_21 ) ;
if ( V_22 == 1 )
V_19 -> V_23 &= ~ V_24 ;
if ( V_19 -> V_23 & V_24 )
V_20 *= V_22 ;
V_19 -> V_21 = F_14 ( V_20 , V_25 ) ;
if ( ! V_19 -> V_21 )
return - V_26 ;
F_15 ( & V_27 ) ;
F_16 ( & V_19 -> V_28 , & V_29 ) ;
F_17 ( & V_27 ) ;
return 0 ;
}
void F_18 ( struct V_19 * V_19 )
{
F_15 ( & V_27 ) ;
F_19 ( & V_19 -> V_28 ) ;
F_17 ( & V_27 ) ;
F_20 ( V_19 -> V_21 ) ;
}
static unsigned long F_21 ( struct V_30 * V_31 ,
struct V_19 * V_19 ,
unsigned long V_32 ,
unsigned long V_33 )
{
unsigned long V_34 = 0 ;
unsigned long long V_35 ;
long V_36 ;
long V_37 ;
long V_9 ;
long V_38 ;
int V_39 = V_31 -> V_39 ;
long V_40 = V_19 -> V_41 ? V_19 -> V_41
: V_42 ;
V_37 = V_19 -> V_43 ( V_19 , V_31 ) ;
if ( V_37 == 0 )
return 0 ;
V_9 = F_22 ( & V_19 -> V_21 [ V_39 ] , 0 ) ;
V_36 = V_9 ;
V_35 = ( 4 * V_32 ) / V_19 -> V_44 ;
V_35 *= V_37 ;
F_23 ( V_35 , V_33 + 1 ) ;
V_36 += V_35 ;
if ( V_36 < 0 ) {
F_24 ( L_1 ,
V_19 -> V_45 , V_36 ) ;
V_36 = V_37 ;
}
if ( V_35 < V_37 / 4 )
V_36 = F_25 ( V_36 , V_37 / 2 ) ;
if ( V_36 > V_37 * 2 )
V_36 = V_37 * 2 ;
F_26 ( V_19 , V_31 , V_9 ,
V_32 , V_33 ,
V_37 , V_35 , V_36 ) ;
while ( V_36 >= V_40 ||
V_36 >= V_37 ) {
unsigned long V_46 ;
unsigned long V_47 = F_25 ( V_40 , V_36 ) ;
V_31 -> V_47 = V_47 ;
V_46 = V_19 -> V_45 ( V_19 , V_31 ) ;
if ( V_46 == V_48 )
break;
V_34 += V_46 ;
F_27 ( V_49 , V_47 ) ;
V_36 -= V_47 ;
F_28 () ;
}
if ( V_36 > 0 )
V_38 = F_29 ( V_36 ,
& V_19 -> V_21 [ V_39 ] ) ;
else
V_38 = F_30 ( & V_19 -> V_21 [ V_39 ] ) ;
F_31 ( V_19 , V_39 , V_34 , V_9 , V_38 , V_36 ) ;
return V_34 ;
}
static unsigned long F_32 ( T_2 V_50 , int V_39 ,
struct V_4 * V_5 ,
unsigned long V_32 ,
unsigned long V_33 )
{
struct V_19 * V_19 ;
unsigned long V_34 = 0 ;
if ( V_5 && ! F_33 ( V_5 ) )
return 0 ;
if ( V_32 == 0 )
V_32 = V_51 ;
if ( ! F_34 ( & V_27 ) ) {
V_34 = 1 ;
goto V_52;
}
F_35 (shrinker, &shrinker_list, list) {
struct V_30 V_2 = {
. V_50 = V_50 ,
. V_39 = V_39 ,
. V_5 = V_5 ,
} ;
if ( V_5 && ! ( V_19 -> V_23 & V_53 ) )
continue;
if ( ! ( V_19 -> V_23 & V_24 ) )
V_2 . V_39 = 0 ;
V_34 += F_21 ( & V_2 , V_19 , V_32 , V_33 ) ;
}
F_36 ( & V_27 ) ;
V_52:
F_28 () ;
return V_34 ;
}
void F_37 ( int V_39 )
{
unsigned long V_34 ;
do {
struct V_4 * V_5 = NULL ;
V_34 = 0 ;
do {
V_34 += F_32 ( V_25 , V_39 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_38 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_34 > 10 );
}
void F_39 ( void )
{
int V_39 ;
F_40 (nid)
F_37 ( V_39 ) ;
}
static inline int F_41 ( struct V_54 * V_54 )
{
return F_42 ( V_54 ) - F_43 ( V_54 ) == 2 ;
}
static int F_44 ( struct V_55 * V_55 , struct V_1 * V_2 )
{
if ( V_56 -> V_23 & V_57 )
return 1 ;
if ( ! F_45 ( V_55 ) )
return 1 ;
if ( F_46 ( V_55 ) == V_56 -> V_58 )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_59 * V_60 ,
struct V_54 * V_54 , int error )
{
F_48 ( V_54 ) ;
if ( F_49 ( V_54 ) == V_60 )
F_50 ( V_60 , error ) ;
F_51 ( V_54 ) ;
}
static T_3 F_52 ( struct V_54 * V_54 , struct V_59 * V_60 ,
struct V_1 * V_2 )
{
if ( ! F_41 ( V_54 ) )
return V_61 ;
if ( ! V_60 ) {
if ( F_43 ( V_54 ) ) {
if ( F_53 ( V_54 ) ) {
F_54 ( V_54 ) ;
F_55 ( L_2 , V_62 ) ;
return V_63 ;
}
}
return V_61 ;
}
if ( V_60 -> V_64 -> V_65 == NULL )
return V_66 ;
if ( ! F_44 ( V_60 -> V_67 , V_2 ) )
return V_61 ;
if ( F_56 ( V_54 ) ) {
int V_68 ;
struct V_69 V_70 = {
. V_71 = V_72 ,
. V_73 = V_51 ,
. V_74 = 0 ,
. V_75 = V_76 ,
. V_77 = 1 ,
} ;
F_57 ( V_54 ) ;
V_68 = V_60 -> V_64 -> V_65 ( V_54 , & V_70 ) ;
if ( V_68 < 0 )
F_47 ( V_60 , V_54 , V_68 ) ;
if ( V_68 == V_78 ) {
F_58 ( V_54 ) ;
return V_66 ;
}
if ( ! F_59 ( V_54 ) ) {
F_58 ( V_54 ) ;
}
F_60 ( V_54 , F_61 ( V_54 ) ) ;
F_62 ( V_54 , V_79 ) ;
return V_80 ;
}
return V_63 ;
}
static int F_63 ( struct V_59 * V_60 , struct V_54 * V_54 ,
bool V_81 )
{
unsigned long V_23 ;
struct V_4 * V_5 ;
F_64 ( ! F_65 ( V_54 ) ) ;
F_64 ( V_60 != F_49 ( V_54 ) ) ;
V_5 = F_66 ( V_54 ) ;
F_67 ( & V_60 -> V_82 , V_23 ) ;
if ( ! F_68 ( V_54 , 2 ) )
goto V_83;
if ( F_69 ( F_70 ( V_54 ) ) ) {
F_71 ( V_54 , 2 ) ;
goto V_83;
}
if ( F_72 ( V_54 ) ) {
T_4 V_84 = { . V_85 = F_73 (page) } ;
F_74 ( V_54 , V_84 ) ;
F_75 ( V_54 ) ;
F_76 ( & V_60 -> V_82 , V_23 ) ;
F_77 ( V_5 ) ;
F_78 ( V_84 ) ;
} else {
void (* F_79)( struct V_54 * );
void * V_86 = NULL ;
F_79 = V_60 -> V_64 -> F_79 ;
if ( V_81 && F_80 ( V_54 ) &&
! F_81 ( V_60 ) )
V_86 = F_82 ( V_60 , V_54 ) ;
F_83 ( V_54 , V_86 , V_5 ) ;
F_76 ( & V_60 -> V_82 , V_23 ) ;
F_77 ( V_5 ) ;
if ( F_79 != NULL )
F_79 ( V_54 ) ;
}
return 1 ;
V_83:
F_76 ( & V_60 -> V_82 , V_23 ) ;
F_77 ( V_5 ) ;
return 0 ;
}
int F_84 ( struct V_59 * V_60 , struct V_54 * V_54 )
{
if ( F_63 ( V_60 , V_54 , false ) ) {
F_71 ( V_54 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_85 ( struct V_54 * V_54 )
{
bool V_87 ;
int V_88 = F_86 ( V_54 ) ;
F_87 ( F_88 ( V_54 ) , V_54 ) ;
V_89:
F_89 ( V_54 ) ;
if ( F_90 ( V_54 ) ) {
V_87 = false ;
F_91 ( V_54 ) ;
} else {
V_87 = true ;
F_92 ( V_54 ) ;
F_93 () ;
}
if ( V_87 && F_90 ( V_54 ) ) {
if ( ! F_94 ( V_54 ) ) {
F_95 ( V_54 ) ;
goto V_89;
}
}
if ( V_88 && ! V_87 )
F_96 ( V_90 ) ;
else if ( ! V_88 && V_87 )
F_96 ( V_91 ) ;
F_95 ( V_54 ) ;
}
static enum V_92 F_97 ( struct V_54 * V_54 ,
struct V_1 * V_2 )
{
int V_93 , V_94 ;
unsigned long V_95 ;
V_93 = F_98 ( V_54 , 1 , V_2 -> V_3 ,
& V_95 ) ;
V_94 = F_99 ( V_54 ) ;
if ( V_95 & V_96 )
return V_97 ;
if ( V_93 ) {
if ( F_100 ( V_54 ) )
return V_98 ;
F_101 ( V_54 ) ;
if ( V_94 || V_93 > 1 )
return V_98 ;
if ( V_95 & V_99 )
return V_98 ;
return V_100 ;
}
if ( V_94 && ! F_100 ( V_54 ) )
return V_101 ;
return V_97 ;
}
static void F_102 ( struct V_54 * V_54 ,
bool * V_102 , bool * V_103 )
{
struct V_59 * V_60 ;
if ( ! F_80 ( V_54 ) ) {
* V_102 = false ;
* V_103 = false ;
return;
}
* V_102 = F_70 ( V_54 ) ;
* V_103 = F_59 ( V_54 ) ;
if ( ! F_43 ( V_54 ) )
return;
V_60 = F_49 ( V_54 ) ;
if ( V_60 && V_60 -> V_64 -> V_104 )
V_60 -> V_64 -> V_104 ( V_54 , V_102 , V_103 ) ;
}
static unsigned long F_103 ( struct V_105 * V_106 ,
struct V_8 * V_8 ,
struct V_1 * V_2 ,
enum V_107 V_107 ,
unsigned long * V_108 ,
unsigned long * V_109 ,
unsigned long * V_110 ,
unsigned long * V_111 ,
unsigned long * V_112 ,
bool V_113 )
{
F_104 ( V_114 ) ;
F_104 ( V_115 ) ;
int V_116 = 0 ;
unsigned long V_117 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
unsigned long V_121 = 0 ;
unsigned long V_122 = 0 ;
F_28 () ;
while ( ! F_105 ( V_106 ) ) {
struct V_59 * V_60 ;
struct V_54 * V_54 ;
int V_123 ;
enum V_92 V_124 = V_101 ;
bool V_102 , V_103 ;
F_28 () ;
V_54 = F_106 ( V_106 ) ;
F_19 ( & V_54 -> V_17 ) ;
if ( ! F_107 ( V_54 ) )
goto V_125;
F_87 ( F_108 ( V_54 ) , V_54 ) ;
F_87 ( F_109 ( V_54 ) != V_8 , V_54 ) ;
V_2 -> V_32 ++ ;
if ( F_69 ( ! F_90 ( V_54 ) ) )
goto V_126;
if ( ! V_2 -> V_127 && F_110 ( V_54 ) )
goto V_128;
if ( F_110 ( V_54 ) || F_72 ( V_54 ) )
V_2 -> V_32 ++ ;
V_123 = ( V_2 -> V_50 & V_129 ) ||
( F_72 ( V_54 ) && ( V_2 -> V_50 & V_130 ) ) ;
F_102 ( V_54 , & V_102 , & V_103 ) ;
if ( V_102 || V_103 )
V_118 ++ ;
if ( V_102 && ! V_103 )
V_117 ++ ;
V_60 = F_49 ( V_54 ) ;
if ( ( ( V_102 || V_103 ) && V_60 &&
F_45 ( V_60 -> V_67 ) ) ||
( V_103 && F_111 ( V_54 ) ) )
V_119 ++ ;
if ( F_59 ( V_54 ) ) {
if ( F_112 () &&
F_111 ( V_54 ) &&
F_113 ( V_131 , & V_8 -> V_23 ) ) {
V_122 ++ ;
goto V_128;
} else if ( F_2 ( V_2 ) ||
! F_111 ( V_54 ) || ! V_123 ) {
F_57 ( V_54 ) ;
V_121 ++ ;
goto V_128;
} else {
F_51 ( V_54 ) ;
F_114 ( V_54 ) ;
F_16 ( & V_54 -> V_17 , V_106 ) ;
continue;
}
}
if ( ! V_113 )
V_124 = F_97 ( V_54 , V_2 ) ;
switch ( V_124 ) {
case V_98 :
goto V_132;
case V_100 :
goto V_128;
case V_97 :
case V_101 :
;
}
if ( F_115 ( V_54 ) && ! F_72 ( V_54 ) ) {
if ( ! ( V_2 -> V_50 & V_130 ) )
goto V_128;
if ( ! F_116 ( V_54 , V_106 ) )
goto V_132;
V_123 = 1 ;
V_60 = F_49 ( V_54 ) ;
}
if ( F_110 ( V_54 ) && V_60 ) {
switch ( F_117 ( V_54 ,
V_107 | V_133 ) ) {
case V_134 :
goto V_132;
case V_135 :
goto V_128;
case V_136 :
goto V_126;
case V_137 :
;
}
}
if ( F_70 ( V_54 ) ) {
if ( F_80 ( V_54 ) &&
( ! F_112 () ||
! F_113 ( V_138 , & V_8 -> V_23 ) ) ) {
F_62 ( V_54 , V_139 ) ;
F_57 ( V_54 ) ;
goto V_128;
}
if ( V_124 == V_101 )
goto V_128;
if ( ! V_123 )
goto V_128;
if ( ! V_2 -> V_140 )
goto V_128;
F_118 () ;
switch ( F_52 ( V_54 , V_60 , V_2 ) ) {
case V_61 :
goto V_128;
case V_66 :
goto V_132;
case V_80 :
if ( F_59 ( V_54 ) )
goto V_125;
if ( F_70 ( V_54 ) )
goto V_125;
if ( ! F_107 ( V_54 ) )
goto V_125;
if ( F_70 ( V_54 ) || F_59 ( V_54 ) )
goto V_128;
V_60 = F_49 ( V_54 ) ;
case V_63 :
;
}
}
if ( F_43 ( V_54 ) ) {
if ( ! F_119 ( V_54 , V_2 -> V_50 ) )
goto V_132;
if ( ! V_60 && F_42 ( V_54 ) == 1 ) {
F_51 ( V_54 ) ;
if ( F_120 ( V_54 ) )
goto V_141;
else {
V_120 ++ ;
continue;
}
}
}
if ( ! V_60 || ! F_63 ( V_60 , V_54 , true ) )
goto V_128;
F_121 ( V_54 ) ;
V_141:
V_120 ++ ;
F_122 ( & V_54 -> V_17 , & V_115 ) ;
continue;
V_126:
if ( F_72 ( V_54 ) )
F_123 ( V_54 ) ;
F_51 ( V_54 ) ;
F_122 ( & V_54 -> V_17 , & V_114 ) ;
continue;
V_132:
if ( F_72 ( V_54 ) && F_124 () )
F_123 ( V_54 ) ;
F_87 ( F_108 ( V_54 ) , V_54 ) ;
F_125 ( V_54 ) ;
V_116 ++ ;
V_128:
F_51 ( V_54 ) ;
V_125:
F_122 ( & V_54 -> V_17 , & V_114 ) ;
F_87 ( F_88 ( V_54 ) || F_86 ( V_54 ) , V_54 ) ;
}
F_126 ( & V_115 ) ;
F_127 () ;
F_128 ( & V_115 , true ) ;
F_129 ( & V_114 , V_106 ) ;
F_27 ( V_142 , V_116 ) ;
* V_108 += V_118 ;
* V_110 += V_119 ;
* V_109 += V_117 ;
* V_111 += V_121 ;
* V_112 += V_122 ;
return V_120 ;
}
unsigned long F_130 ( struct V_8 * V_8 ,
struct V_105 * V_106 )
{
struct V_1 V_2 = {
. V_50 = V_25 ,
. V_143 = V_144 ,
. V_127 = 1 ,
} ;
unsigned long V_46 , V_145 , V_146 , V_147 , V_148 , V_149 ;
struct V_54 * V_54 , * V_150 ;
F_104 ( V_151 ) ;
F_131 (page, next, page_list, lru) {
if ( F_80 ( V_54 ) && ! F_70 ( V_54 ) &&
! F_132 ( V_54 ) ) {
F_133 ( V_54 ) ;
F_134 ( & V_54 -> V_17 , & V_151 ) ;
}
}
V_46 = F_103 ( & V_151 , V_8 , & V_2 ,
V_152 | V_153 ,
& V_145 , & V_146 , & V_147 , & V_148 , & V_149 , true ) ;
F_129 ( & V_151 , V_106 ) ;
F_135 ( V_8 , V_154 , - V_46 ) ;
return V_46 ;
}
int F_136 ( struct V_54 * V_54 , T_5 V_155 )
{
int V_46 = - V_156 ;
if ( ! F_88 ( V_54 ) )
return V_46 ;
if ( F_86 ( V_54 ) && ! ( V_155 & V_157 ) )
return V_46 ;
V_46 = - V_158 ;
if ( V_155 & ( V_159 | V_160 ) ) {
if ( F_59 ( V_54 ) )
return V_46 ;
if ( F_70 ( V_54 ) ) {
struct V_59 * V_60 ;
if ( V_155 & V_159 )
return V_46 ;
V_60 = F_49 ( V_54 ) ;
if ( V_60 && ! V_60 -> V_64 -> V_161 )
return V_46 ;
}
}
if ( ( V_155 & V_162 ) && F_110 ( V_54 ) )
return V_46 ;
if ( F_137 ( F_138 ( V_54 ) ) ) {
F_139 ( V_54 ) ;
V_46 = 0 ;
}
return V_46 ;
}
static unsigned long F_140 ( unsigned long V_47 ,
struct V_15 * V_15 , struct V_105 * V_163 ,
unsigned long * V_32 , struct V_1 * V_2 ,
T_5 V_155 , enum V_16 V_17 )
{
struct V_105 * V_164 = & V_15 -> V_165 [ V_17 ] ;
unsigned long V_166 = 0 ;
unsigned long V_167 ;
for ( V_167 = 0 ; V_167 < V_47 && V_166 < V_47 &&
! F_105 ( V_164 ) ; V_167 ++ ) {
struct V_54 * V_54 ;
int V_168 ;
V_54 = F_106 ( V_164 ) ;
F_141 ( V_54 , V_164 , V_23 ) ;
F_87 ( ! F_88 ( V_54 ) , V_54 ) ;
switch ( F_136 ( V_54 , V_155 ) ) {
case 0 :
V_168 = F_142 ( V_54 ) ;
F_143 ( V_15 , V_17 , - V_168 ) ;
F_134 ( & V_54 -> V_17 , V_163 ) ;
V_166 += V_168 ;
break;
case - V_158 :
F_134 ( & V_54 -> V_17 , V_164 ) ;
continue;
default:
F_144 () ;
}
}
* V_32 = V_167 ;
F_145 ( V_2 -> V_169 , V_47 , V_167 ,
V_166 , V_155 , F_146 ( V_17 ) ) ;
return V_166 ;
}
int F_94 ( struct V_54 * V_54 )
{
int V_46 = - V_158 ;
F_87 ( ! F_42 ( V_54 ) , V_54 ) ;
if ( F_88 ( V_54 ) ) {
struct V_8 * V_8 = F_109 ( V_54 ) ;
struct V_15 * V_15 ;
F_147 ( & V_8 -> V_170 ) ;
V_15 = F_148 ( V_54 , V_8 ) ;
if ( F_88 ( V_54 ) ) {
int V_17 = F_149 ( V_54 ) ;
F_150 ( V_54 ) ;
F_139 ( V_54 ) ;
F_151 ( V_54 , V_15 , V_17 ) ;
V_46 = 0 ;
}
F_152 ( & V_8 -> V_170 ) ;
}
return V_46 ;
}
static int F_153 ( struct V_8 * V_8 , int V_171 ,
struct V_1 * V_2 )
{
unsigned long V_172 , V_173 ;
if ( F_112 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_171 ) {
V_172 = F_6 ( V_8 , V_11 ) ;
V_173 = F_6 ( V_8 , V_154 ) ;
} else {
V_172 = F_6 ( V_8 , V_13 ) ;
V_173 = F_6 ( V_8 , V_174 ) ;
}
if ( ( V_2 -> V_50 & V_175 ) == V_175 )
V_172 >>= 3 ;
return V_173 > V_172 ;
}
static T_6 void
F_154 ( struct V_15 * V_15 , struct V_105 * V_106 )
{
struct V_176 * V_177 = & V_15 -> V_177 ;
struct V_8 * V_8 = F_12 ( V_15 ) ;
F_104 ( V_178 ) ;
while ( ! F_105 ( V_106 ) ) {
struct V_54 * V_54 = F_106 ( V_106 ) ;
int V_17 ;
F_87 ( F_88 ( V_54 ) , V_54 ) ;
F_19 ( & V_54 -> V_17 ) ;
if ( F_69 ( ! F_90 ( V_54 ) ) ) {
F_152 ( & V_8 -> V_170 ) ;
F_85 ( V_54 ) ;
F_147 ( & V_8 -> V_170 ) ;
continue;
}
V_15 = F_148 ( V_54 , V_8 ) ;
F_155 ( V_54 ) ;
V_17 = F_149 ( V_54 ) ;
F_156 ( V_54 , V_15 , V_17 ) ;
if ( F_157 ( V_17 ) ) {
int V_171 = F_146 ( V_17 ) ;
int V_179 = F_142 ( V_54 ) ;
V_177 -> V_180 [ V_171 ] += V_179 ;
}
if ( F_120 ( V_54 ) ) {
F_158 ( V_54 ) ;
F_159 ( V_54 ) ;
F_151 ( V_54 , V_15 , V_17 ) ;
if ( F_69 ( F_160 ( V_54 ) ) ) {
F_152 ( & V_8 -> V_170 ) ;
F_161 ( V_54 ) ;
( * F_162 ( V_54 ) ) ( V_54 ) ;
F_147 ( & V_8 -> V_170 ) ;
} else
F_122 ( & V_54 -> V_17 , & V_178 ) ;
}
}
F_129 ( & V_178 , V_106 ) ;
}
static int F_163 ( void )
{
return ! ( V_56 -> V_23 & V_181 ) ||
V_56 -> V_58 == NULL ||
F_164 ( V_56 -> V_58 ) ;
}
static T_6 unsigned long
F_165 ( unsigned long V_47 , struct V_15 * V_15 ,
struct V_1 * V_2 , enum V_16 V_17 )
{
F_104 ( V_106 ) ;
unsigned long V_32 ;
unsigned long V_120 = 0 ;
unsigned long V_166 ;
unsigned long V_118 = 0 ;
unsigned long V_119 = 0 ;
unsigned long V_117 = 0 ;
unsigned long V_121 = 0 ;
unsigned long V_122 = 0 ;
T_5 V_182 = 0 ;
int V_171 = F_146 ( V_17 ) ;
struct V_8 * V_8 = F_12 ( V_15 ) ;
struct V_176 * V_177 = & V_15 -> V_177 ;
while ( F_69 ( F_153 ( V_8 , V_171 , V_2 ) ) ) {
F_166 ( V_183 , V_184 / 10 ) ;
if ( F_167 ( V_56 ) )
return V_51 ;
}
F_168 () ;
if ( ! V_2 -> V_127 )
V_182 |= V_162 ;
if ( ! V_2 -> V_140 )
V_182 |= V_159 ;
F_147 ( & V_8 -> V_170 ) ;
V_166 = F_140 ( V_47 , V_15 , & V_106 ,
& V_32 , V_2 , V_182 , V_17 ) ;
F_169 ( V_8 , V_18 + V_17 , - V_166 ) ;
F_169 ( V_8 , V_174 + V_171 , V_166 ) ;
if ( F_1 ( V_2 ) ) {
F_169 ( V_8 , V_14 , V_32 ) ;
if ( F_112 () )
F_170 ( V_185 , V_8 , V_32 ) ;
else
F_170 ( V_186 , V_8 , V_32 ) ;
}
F_152 ( & V_8 -> V_170 ) ;
if ( V_166 == 0 )
return 0 ;
V_120 = F_103 ( & V_106 , V_8 , V_2 , V_152 ,
& V_118 , & V_117 , & V_119 ,
& V_121 , & V_122 ,
false ) ;
F_147 ( & V_8 -> V_170 ) ;
V_177 -> V_187 [ V_171 ] += V_166 ;
if ( F_1 ( V_2 ) ) {
if ( F_112 () )
F_170 ( V_188 , V_8 ,
V_120 ) ;
else
F_170 ( V_189 , V_8 ,
V_120 ) ;
}
F_154 ( V_15 , & V_106 ) ;
F_169 ( V_8 , V_174 + V_171 , - V_166 ) ;
F_152 ( & V_8 -> V_170 ) ;
F_126 ( & V_106 ) ;
F_128 ( & V_106 , true ) ;
if ( V_121 && V_121 == V_166 )
F_171 ( V_131 , & V_8 -> V_23 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_118 && V_118 == V_119 )
F_171 ( V_190 , & V_8 -> V_23 ) ;
if ( V_117 == V_166 )
F_171 ( V_138 , & V_8 -> V_23 ) ;
if ( V_122 && F_163 () )
F_166 ( V_183 , V_184 / 10 ) ;
}
if ( ! V_2 -> V_191 && ! F_112 () &&
F_163 () )
F_172 ( V_8 , V_183 , V_184 / 10 ) ;
F_173 ( V_8 -> V_192 -> V_193 ,
F_174 ( V_8 ) ,
V_32 , V_120 ,
V_2 -> V_143 ,
F_175 ( V_171 ) ) ;
return V_120 ;
}
static void F_176 ( struct V_15 * V_15 ,
struct V_105 * V_28 ,
struct V_105 * V_178 ,
enum V_16 V_17 )
{
struct V_8 * V_8 = F_12 ( V_15 ) ;
unsigned long V_194 = 0 ;
struct V_54 * V_54 ;
int V_168 ;
while ( ! F_105 ( V_28 ) ) {
V_54 = F_106 ( V_28 ) ;
V_15 = F_148 ( V_54 , V_8 ) ;
F_87 ( F_88 ( V_54 ) , V_54 ) ;
F_155 ( V_54 ) ;
V_168 = F_142 ( V_54 ) ;
F_143 ( V_15 , V_17 , V_168 ) ;
F_134 ( & V_54 -> V_17 , & V_15 -> V_165 [ V_17 ] ) ;
V_194 += V_168 ;
if ( F_120 ( V_54 ) ) {
F_158 ( V_54 ) ;
F_159 ( V_54 ) ;
F_151 ( V_54 , V_15 , V_17 ) ;
if ( F_69 ( F_160 ( V_54 ) ) ) {
F_152 ( & V_8 -> V_170 ) ;
F_161 ( V_54 ) ;
( * F_162 ( V_54 ) ) ( V_54 ) ;
F_147 ( & V_8 -> V_170 ) ;
} else
F_122 ( & V_54 -> V_17 , V_178 ) ;
}
}
F_169 ( V_8 , V_18 + V_17 , V_194 ) ;
if ( ! F_157 ( V_17 ) )
F_177 ( V_195 , V_194 ) ;
}
static void F_178 ( unsigned long V_47 ,
struct V_15 * V_15 ,
struct V_1 * V_2 ,
enum V_16 V_17 )
{
unsigned long V_166 ;
unsigned long V_32 ;
unsigned long V_95 ;
F_104 ( V_196 ) ;
F_104 ( V_197 ) ;
F_104 ( V_198 ) ;
struct V_54 * V_54 ;
struct V_176 * V_177 = & V_15 -> V_177 ;
unsigned long V_199 = 0 ;
T_5 V_182 = 0 ;
int V_171 = F_146 ( V_17 ) ;
struct V_8 * V_8 = F_12 ( V_15 ) ;
F_168 () ;
if ( ! V_2 -> V_127 )
V_182 |= V_162 ;
if ( ! V_2 -> V_140 )
V_182 |= V_159 ;
F_147 ( & V_8 -> V_170 ) ;
V_166 = F_140 ( V_47 , V_15 , & V_196 ,
& V_32 , V_2 , V_182 , V_17 ) ;
if ( F_1 ( V_2 ) )
F_169 ( V_8 , V_14 , V_32 ) ;
V_177 -> V_187 [ V_171 ] += V_166 ;
F_170 ( V_200 , V_8 , V_32 ) ;
F_169 ( V_8 , V_18 + V_17 , - V_166 ) ;
F_169 ( V_8 , V_174 + V_171 , V_166 ) ;
F_152 ( & V_8 -> V_170 ) ;
while ( ! F_105 ( & V_196 ) ) {
F_28 () ;
V_54 = F_106 ( & V_196 ) ;
F_19 ( & V_54 -> V_17 ) ;
if ( F_69 ( ! F_90 ( V_54 ) ) ) {
F_85 ( V_54 ) ;
continue;
}
if ( F_69 ( V_201 ) ) {
if ( F_43 ( V_54 ) && F_107 ( V_54 ) ) {
if ( F_43 ( V_54 ) )
F_119 ( V_54 , 0 ) ;
F_51 ( V_54 ) ;
}
}
if ( F_98 ( V_54 , 0 , V_2 -> V_3 ,
& V_95 ) ) {
V_199 += F_142 ( V_54 ) ;
if ( ( V_95 & V_99 ) && F_80 ( V_54 ) ) {
F_122 ( & V_54 -> V_17 , & V_197 ) ;
continue;
}
}
F_133 ( V_54 ) ;
F_122 ( & V_54 -> V_17 , & V_198 ) ;
}
F_147 ( & V_8 -> V_170 ) ;
V_177 -> V_180 [ V_171 ] += V_199 ;
F_176 ( V_15 , & V_197 , & V_196 , V_17 ) ;
F_176 ( V_15 , & V_198 , & V_196 , V_17 - V_202 ) ;
F_169 ( V_8 , V_174 + V_171 , - V_166 ) ;
F_152 ( & V_8 -> V_170 ) ;
F_126 ( & V_196 ) ;
F_128 ( & V_196 , true ) ;
}
static int F_179 ( struct V_8 * V_8 )
{
unsigned long V_203 , V_172 ;
V_203 = F_6 ( V_8 , V_12 ) ;
V_172 = F_6 ( V_8 , V_13 ) ;
if ( V_172 * V_8 -> V_204 < V_203 )
return 1 ;
return 0 ;
}
static int F_180 ( struct V_15 * V_15 )
{
if ( ! V_205 )
return 0 ;
if ( ! F_10 () )
return F_181 ( V_15 ) ;
return F_179 ( F_12 ( V_15 ) ) ;
}
static inline int F_180 ( struct V_15 * V_15 )
{
return 0 ;
}
static int F_182 ( struct V_15 * V_15 )
{
unsigned long V_172 ;
unsigned long V_203 ;
V_172 = F_9 ( V_15 , V_206 ) ;
V_203 = F_9 ( V_15 , V_207 ) ;
return V_203 > V_172 ;
}
static int F_183 ( struct V_15 * V_15 , enum V_16 V_17 )
{
if ( F_146 ( V_17 ) )
return F_182 ( V_15 ) ;
else
return F_180 ( V_15 ) ;
}
static unsigned long F_184 ( enum V_16 V_17 , unsigned long V_47 ,
struct V_15 * V_15 , struct V_1 * V_2 )
{
if ( F_157 ( V_17 ) ) {
if ( F_183 ( V_15 , V_17 ) )
F_178 ( V_47 , V_15 , V_2 , V_17 ) ;
return 0 ;
}
return F_165 ( V_47 , V_15 , V_2 , V_17 ) ;
}
static void F_185 ( struct V_15 * V_15 , int V_208 ,
struct V_1 * V_2 , unsigned long * V_9 ,
unsigned long * V_209 )
{
struct V_176 * V_177 = & V_15 -> V_177 ;
T_7 V_210 [ 2 ] ;
T_7 V_211 = 0 ;
struct V_8 * V_8 = F_12 ( V_15 ) ;
unsigned long V_212 , V_213 ;
enum V_214 V_214 ;
unsigned long V_215 , V_171 ;
bool V_216 = false ;
unsigned long V_217 , V_218 ;
enum V_16 V_17 ;
bool V_219 ;
int V_220 ;
if ( F_112 () ) {
if ( ! F_8 ( V_8 ) )
V_216 = true ;
if ( ! F_186 ( V_15 ) )
V_216 = true ;
}
if ( ! F_1 ( V_2 ) )
V_216 = true ;
if ( ! V_2 -> V_221 || ( F_7 () <= 0 ) ) {
V_214 = V_222 ;
goto V_52;
}
if ( ! F_1 ( V_2 ) && ! V_208 ) {
V_214 = V_222 ;
goto V_52;
}
if ( ! V_2 -> V_143 && V_208 ) {
V_214 = V_223 ;
goto V_52;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_224 ;
unsigned long V_225 ;
V_225 = F_6 ( V_8 , V_226 ) ;
V_224 = F_6 ( V_8 , V_10 ) +
F_6 ( V_8 , V_11 ) ;
if ( F_69 ( V_224 + V_225 <= F_187 ( V_8 ) ) ) {
V_214 = V_227 ;
goto V_52;
}
}
if ( ! F_182 ( V_15 ) ) {
V_214 = V_222 ;
goto V_52;
}
V_214 = V_228 ;
V_212 = V_208 ;
V_213 = 200 - V_212 ;
V_215 = F_9 ( V_15 , V_229 ) +
F_9 ( V_15 , V_230 ) ;
V_171 = F_9 ( V_15 , V_207 ) +
F_9 ( V_15 , V_206 ) ;
F_147 ( & V_8 -> V_170 ) ;
if ( F_69 ( V_177 -> V_187 [ 0 ] > V_215 / 4 ) ) {
V_177 -> V_187 [ 0 ] /= 2 ;
V_177 -> V_180 [ 0 ] /= 2 ;
}
if ( F_69 ( V_177 -> V_187 [ 1 ] > V_171 / 4 ) ) {
V_177 -> V_187 [ 1 ] /= 2 ;
V_177 -> V_180 [ 1 ] /= 2 ;
}
V_217 = V_212 * ( V_177 -> V_187 [ 0 ] + 1 ) ;
V_217 /= V_177 -> V_180 [ 0 ] + 1 ;
V_218 = V_213 * ( V_177 -> V_187 [ 1 ] + 1 ) ;
V_218 /= V_177 -> V_180 [ 1 ] + 1 ;
F_152 ( & V_8 -> V_170 ) ;
V_210 [ 0 ] = V_217 ;
V_210 [ 1 ] = V_218 ;
V_211 = V_217 + V_218 + 1 ;
V_52:
V_219 = false ;
for ( V_220 = 0 ; ! V_219 && V_220 < 2 ; V_220 ++ ) {
* V_209 = 0 ;
F_188 (lru) {
int V_171 = F_146 ( V_17 ) ;
unsigned long V_20 ;
unsigned long V_167 ;
V_20 = F_9 ( V_15 , V_17 ) ;
V_167 = V_20 >> V_2 -> V_143 ;
if ( ! V_167 && V_220 && V_216 )
V_167 = F_25 ( V_20 , V_51 ) ;
switch ( V_214 ) {
case V_223 :
break;
case V_228 :
V_167 = F_189 ( V_167 * V_210 [ V_171 ] ,
V_211 ) ;
break;
case V_222 :
case V_227 :
if ( ( V_214 == V_222 ) != V_171 ) {
V_20 = 0 ;
V_167 = 0 ;
}
break;
default:
F_144 () ;
}
* V_209 += V_20 ;
V_9 [ V_17 ] = V_167 ;
V_219 |= ! ! V_167 ;
}
}
}
static void F_190 ( void )
{
V_56 -> V_231 . V_232 = false ;
}
static inline void F_190 ( void )
{
}
static void F_191 ( struct V_15 * V_15 , int V_208 ,
struct V_1 * V_2 , unsigned long * V_209 )
{
unsigned long V_9 [ V_233 ] ;
unsigned long V_234 [ V_233 ] ;
unsigned long V_47 ;
enum V_16 V_17 ;
unsigned long V_120 = 0 ;
unsigned long V_235 = V_2 -> V_235 ;
struct V_236 V_237 ;
bool V_238 ;
F_185 ( V_15 , V_208 , V_2 , V_9 , V_209 ) ;
memcpy ( V_234 , V_9 , sizeof( V_9 ) ) ;
V_238 = ( F_1 ( V_2 ) && ! F_112 () &&
V_2 -> V_143 == V_144 ) ;
F_190 () ;
F_192 ( & V_237 ) ;
while ( V_9 [ V_230 ] || V_9 [ V_207 ] ||
V_9 [ V_206 ] ) {
unsigned long V_239 , V_240 , V_241 ;
unsigned long V_32 ;
F_188 (lru) {
if ( V_9 [ V_17 ] ) {
V_47 = F_25 ( V_9 [ V_17 ] , V_51 ) ;
V_9 [ V_17 ] -= V_47 ;
V_120 += F_184 ( V_17 , V_47 ,
V_15 , V_2 ) ;
}
}
if ( V_120 < V_235 || V_238 )
continue;
V_240 = V_9 [ V_206 ] + V_9 [ V_207 ] ;
V_239 = V_9 [ V_230 ] + V_9 [ V_229 ] ;
if ( ! V_240 || ! V_239 )
break;
if ( V_240 > V_239 ) {
unsigned long V_242 = V_234 [ V_230 ] +
V_234 [ V_229 ] + 1 ;
V_17 = V_243 ;
V_241 = V_239 * 100 / V_242 ;
} else {
unsigned long V_242 = V_234 [ V_206 ] +
V_234 [ V_207 ] + 1 ;
V_17 = V_244 ;
V_241 = V_240 * 100 / V_242 ;
}
V_9 [ V_17 ] = 0 ;
V_9 [ V_17 + V_202 ] = 0 ;
V_17 = ( V_17 == V_244 ) ? V_243 : V_244 ;
V_32 = V_234 [ V_17 ] - V_9 [ V_17 ] ;
V_9 [ V_17 ] = V_234 [ V_17 ] * ( 100 - V_241 ) / 100 ;
V_9 [ V_17 ] -= F_25 ( V_9 [ V_17 ] , V_32 ) ;
V_17 += V_202 ;
V_32 = V_234 [ V_17 ] - V_9 [ V_17 ] ;
V_9 [ V_17 ] = V_234 [ V_17 ] * ( 100 - V_241 ) / 100 ;
V_9 [ V_17 ] -= F_25 ( V_9 [ V_17 ] , V_32 ) ;
V_238 = true ;
}
F_193 ( & V_237 ) ;
V_2 -> V_120 += V_120 ;
if ( F_180 ( V_15 ) )
F_178 ( V_51 , V_15 ,
V_2 , V_229 ) ;
F_194 ( V_2 -> V_50 ) ;
}
static bool F_195 ( struct V_1 * V_2 )
{
if ( F_196 ( V_245 ) && V_2 -> V_169 &&
( V_2 -> V_169 > V_246 ||
V_2 -> V_143 < V_144 - 2 ) )
return true ;
return false ;
}
static inline bool F_197 ( struct V_8 * V_8 ,
unsigned long V_120 ,
unsigned long V_32 ,
struct V_1 * V_2 )
{
unsigned long V_247 ;
unsigned long V_248 ;
if ( ! F_195 ( V_2 ) )
return false ;
if ( V_2 -> V_50 & V_249 ) {
if ( ! V_120 && ! V_32 )
return false ;
} else {
if ( ! V_120 )
return false ;
}
V_247 = ( 2UL << V_2 -> V_169 ) ;
V_248 = F_6 ( V_8 , V_11 ) ;
if ( F_7 () > 0 )
V_248 += F_6 ( V_8 , V_13 ) ;
if ( V_2 -> V_120 < V_247 &&
V_248 > V_247 )
return true ;
switch ( F_198 ( V_8 , V_2 -> V_169 , 0 , 0 ) ) {
case V_250 :
case V_251 :
return false ;
default:
return true ;
}
}
static bool F_199 ( struct V_8 * V_8 , struct V_1 * V_2 ,
bool V_252 )
{
struct V_253 * V_253 = V_56 -> V_253 ;
unsigned long V_120 , V_32 ;
bool V_254 = false ;
do {
struct V_4 * V_255 = V_2 -> V_3 ;
struct V_256 V_257 = {
. V_8 = V_8 ,
. V_143 = V_2 -> V_143 ,
} ;
unsigned long V_258 = 0 ;
struct V_4 * V_5 ;
V_120 = V_2 -> V_120 ;
V_32 = V_2 -> V_32 ;
V_5 = F_38 ( V_255 , NULL , & V_257 ) ;
do {
unsigned long V_209 ;
unsigned long V_259 ;
struct V_15 * V_15 ;
int V_208 ;
if ( F_200 ( V_255 , V_5 ) ) {
if ( ! V_2 -> V_260 )
continue;
F_201 ( V_5 , V_261 , 1 ) ;
}
V_15 = F_202 ( V_8 , V_5 ) ;
V_208 = F_203 ( V_5 ) ;
V_259 = V_2 -> V_32 ;
F_191 ( V_15 , V_208 , V_2 , & V_209 ) ;
V_258 += V_209 ;
if ( V_5 && V_252 )
F_32 ( V_2 -> V_50 , F_204 ( V_8 ) ,
V_5 , V_2 -> V_32 - V_259 ,
V_209 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_120 >= V_2 -> V_235 ) {
F_205 ( V_255 , V_5 ) ;
break;
}
} while ( ( V_5 = F_38 ( V_255 , V_5 , & V_257 ) ) );
if ( F_1 ( V_2 ) && V_252 )
F_32 ( V_2 -> V_50 , F_204 ( V_8 ) , NULL ,
V_2 -> V_32 - V_32 ,
V_258 ) ;
if ( V_253 ) {
V_2 -> V_120 += V_253 -> V_262 ;
V_253 -> V_262 = 0 ;
}
F_206 ( V_2 -> V_50 , V_2 -> V_3 ,
V_2 -> V_32 - V_32 ,
V_2 -> V_120 - V_120 ) ;
if ( V_2 -> V_120 - V_120 )
V_254 = true ;
} while ( F_197 ( V_8 , V_2 -> V_120 - V_120 ,
V_2 -> V_32 - V_32 , V_2 ) );
return V_254 ;
}
static inline bool F_207 ( struct V_8 * V_8 , int V_169 )
{
unsigned long V_263 , V_264 ;
bool V_265 ;
V_263 = F_25 ( F_208 ( V_8 ) , F_209 (
V_8 -> V_266 , V_267 ) ) ;
V_264 = F_187 ( V_8 ) + V_263 + ( 2UL << V_169 ) ;
V_265 = F_210 ( V_8 , 0 , V_264 , 0 , 0 ) ;
if ( F_211 ( V_8 , V_169 ) )
return V_265 ;
if ( F_198 ( V_8 , V_169 , 0 , 0 ) == V_268 )
return false ;
return V_265 ;
}
static bool F_212 ( struct V_269 * V_269 , struct V_1 * V_2 )
{
struct V_270 * V_271 ;
struct V_8 * V_8 ;
unsigned long V_272 ;
unsigned long V_273 ;
T_2 V_274 ;
enum V_275 V_276 = F_213 ( V_2 -> V_50 ) ;
bool V_254 = false ;
V_274 = V_2 -> V_50 ;
if ( V_201 )
V_2 -> V_50 |= V_277 ;
F_214 (zone, z, zonelist,
requested_highidx, sc->nodemask) {
enum V_275 V_278 ;
if ( ! F_215 ( V_8 ) )
continue;
V_278 = V_276 ;
while ( ! F_215 ( V_8 -> V_192 -> V_279 +
V_278 ) )
V_278 -- ;
if ( F_1 ( V_2 ) ) {
if ( ! F_216 ( V_8 ,
V_25 | V_280 ) )
continue;
if ( V_2 -> V_143 != V_144 &&
! F_8 ( V_8 ) )
continue;
if ( F_196 ( V_245 ) &&
V_2 -> V_169 > V_246 &&
F_217 ( V_271 ) <= V_276 &&
F_207 ( V_8 , V_2 -> V_169 ) ) {
V_2 -> F_207 = true ;
continue;
}
V_273 = 0 ;
V_272 = F_218 ( V_8 ,
V_2 -> V_169 , V_2 -> V_50 ,
& V_273 ) ;
V_2 -> V_120 += V_272 ;
V_2 -> V_32 += V_273 ;
if ( V_272 )
V_254 = true ;
}
if ( F_199 ( V_8 , V_2 , F_174 ( V_8 ) == V_278 ) )
V_254 = true ;
if ( F_1 ( V_2 ) &&
! V_254 && F_8 ( V_8 ) )
V_254 = true ;
}
V_2 -> V_50 = V_274 ;
return V_254 ;
}
static unsigned long F_219 ( struct V_269 * V_269 ,
struct V_1 * V_2 )
{
int V_281 = V_2 -> V_143 ;
unsigned long V_282 = 0 ;
unsigned long V_283 ;
bool V_284 ;
V_285:
F_220 () ;
if ( F_1 ( V_2 ) )
F_96 ( V_286 ) ;
do {
F_221 ( V_2 -> V_50 , V_2 -> V_3 ,
V_2 -> V_143 ) ;
V_2 -> V_32 = 0 ;
V_284 = F_212 ( V_269 , V_2 ) ;
V_282 += V_2 -> V_32 ;
if ( V_2 -> V_120 >= V_2 -> V_235 )
break;
if ( V_2 -> F_207 )
break;
if ( V_2 -> V_143 < V_144 - 2 )
V_2 -> V_140 = 1 ;
V_283 = V_2 -> V_235 + V_2 -> V_235 / 2 ;
if ( V_282 > V_283 ) {
F_222 ( V_287 ? 0 : V_282 ,
V_288 ) ;
V_2 -> V_140 = 1 ;
}
} while ( -- V_2 -> V_143 >= 0 );
F_223 () ;
if ( V_2 -> V_120 )
return V_2 -> V_120 ;
if ( V_2 -> F_207 )
return 1 ;
if ( ! V_2 -> V_260 ) {
V_2 -> V_143 = V_281 ;
V_2 -> V_260 = 1 ;
goto V_285;
}
if ( V_284 )
return 1 ;
return 0 ;
}
static bool F_224 ( T_8 * V_289 )
{
struct V_8 * V_8 ;
unsigned long V_290 = 0 ;
unsigned long V_115 = 0 ;
int V_291 ;
bool V_292 ;
for ( V_291 = 0 ; V_291 <= V_293 ; V_291 ++ ) {
V_8 = & V_289 -> V_279 [ V_291 ] ;
if ( ! F_215 ( V_8 ) ||
F_5 ( V_8 ) == 0 )
continue;
V_290 += F_225 ( V_8 ) ;
V_115 += F_6 ( V_8 , V_226 ) ;
}
if ( ! V_290 )
return true ;
V_292 = V_115 > V_290 / 2 ;
if ( ! V_292 && F_226 ( & V_289 -> V_294 ) ) {
V_289 -> V_278 = F_25 ( V_289 -> V_278 ,
(enum V_275 ) V_293 ) ;
F_227 ( & V_289 -> V_294 ) ;
}
return V_292 ;
}
static bool F_228 ( T_2 V_50 , struct V_269 * V_269 ,
T_9 * V_295 )
{
struct V_270 * V_271 ;
struct V_8 * V_8 ;
T_8 * V_289 = NULL ;
if ( V_56 -> V_23 & V_296 )
goto V_52;
if ( F_167 ( V_56 ) )
goto V_52;
F_214 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_174 ( V_8 ) > V_293 )
continue;
V_289 = V_8 -> V_192 ;
if ( F_224 ( V_289 ) )
goto V_52;
break;
}
if ( ! V_289 )
goto V_52;
F_96 ( V_297 ) ;
if ( ! ( V_50 & V_129 ) ) {
F_229 ( V_289 -> V_298 ,
F_224 ( V_289 ) , V_184 ) ;
goto V_299;
}
F_230 ( V_8 -> V_192 -> V_298 ,
F_224 ( V_289 ) ) ;
V_299:
if ( F_167 ( V_56 ) )
return true ;
V_52:
return false ;
}
unsigned long F_231 ( struct V_269 * V_269 , int V_169 ,
T_2 V_50 , T_9 * V_295 )
{
unsigned long V_120 ;
struct V_1 V_2 = {
. V_235 = V_51 ,
. V_50 = ( V_50 = F_232 ( V_50 ) ) ,
. V_169 = V_169 ,
. V_295 = V_295 ,
. V_143 = V_144 ,
. V_140 = ! V_287 ,
. V_127 = 1 ,
. V_221 = 1 ,
} ;
if ( F_228 ( V_50 , V_269 , V_295 ) )
return 1 ;
F_233 ( V_169 ,
V_2 . V_140 ,
V_50 ) ;
V_120 = F_219 ( V_269 , & V_2 ) ;
F_234 ( V_120 ) ;
return V_120 ;
}
unsigned long F_235 ( struct V_4 * V_5 ,
T_2 V_50 , bool V_300 ,
struct V_8 * V_8 ,
unsigned long * V_32 )
{
struct V_1 V_2 = {
. V_235 = V_51 ,
. V_3 = V_5 ,
. V_140 = ! V_287 ,
. V_127 = 1 ,
. V_221 = ! V_300 ,
} ;
struct V_15 * V_15 = F_202 ( V_8 , V_5 ) ;
int V_208 = F_203 ( V_5 ) ;
unsigned long V_209 ;
V_2 . V_50 = ( V_50 & V_301 ) |
( V_302 & ~ V_301 ) ;
F_236 ( V_2 . V_169 ,
V_2 . V_140 ,
V_2 . V_50 ) ;
F_191 ( V_15 , V_208 , & V_2 , & V_209 ) ;
F_237 ( V_2 . V_120 ) ;
* V_32 = V_2 . V_32 ;
return V_2 . V_120 ;
}
unsigned long F_238 ( struct V_4 * V_5 ,
unsigned long V_168 ,
T_2 V_50 ,
bool V_221 )
{
struct V_269 * V_269 ;
unsigned long V_120 ;
int V_39 ;
struct V_1 V_2 = {
. V_235 = F_239 ( V_168 , V_51 ) ,
. V_50 = ( V_50 & V_301 ) |
( V_302 & ~ V_301 ) ,
. V_3 = V_5 ,
. V_143 = V_144 ,
. V_140 = ! V_287 ,
. V_127 = 1 ,
. V_221 = V_221 ,
} ;
V_39 = F_240 ( V_5 ) ;
V_269 = F_241 ( V_39 ) -> V_303 ;
F_242 ( 0 ,
V_2 . V_140 ,
V_2 . V_50 ) ;
V_120 = F_219 ( V_269 , & V_2 ) ;
F_243 ( V_120 ) ;
return V_120 ;
}
static void F_244 ( struct V_8 * V_8 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_205 )
return;
V_5 = F_38 ( NULL , NULL , NULL ) ;
do {
struct V_15 * V_15 = F_202 ( V_8 , V_5 ) ;
if ( F_180 ( V_15 ) )
F_178 ( V_51 , V_15 ,
V_2 , V_229 ) ;
V_5 = F_38 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_245 ( struct V_8 * V_8 , int V_169 ,
unsigned long V_263 , int V_278 )
{
if ( ! F_210 ( V_8 , V_169 , F_187 ( V_8 ) +
V_263 , V_278 , 0 ) )
return false ;
if ( F_196 ( V_245 ) && V_169 && F_198 ( V_8 ,
V_169 , 0 , V_278 ) == V_268 )
return false ;
return true ;
}
static bool F_246 ( T_8 * V_289 , int V_169 , int V_278 )
{
unsigned long V_266 = 0 ;
unsigned long V_304 = 0 ;
int V_291 ;
for ( V_291 = 0 ; V_291 <= V_278 ; V_291 ++ ) {
struct V_8 * V_8 = V_289 -> V_279 + V_291 ;
if ( ! F_215 ( V_8 ) )
continue;
V_266 += V_8 -> V_266 ;
if ( ! F_8 ( V_8 ) ) {
V_304 += V_8 -> V_266 ;
continue;
}
if ( F_245 ( V_8 , V_169 , 0 , V_291 ) )
V_304 += V_8 -> V_266 ;
else if ( ! V_169 )
return false ;
}
if ( V_169 )
return V_304 >= ( V_266 >> 2 ) ;
else
return true ;
}
static bool F_247 ( T_8 * V_289 , int V_169 , long V_305 ,
int V_278 )
{
if ( V_305 )
return false ;
if ( F_226 ( & V_289 -> V_298 ) )
F_248 ( & V_289 -> V_298 ) ;
return F_246 ( V_289 , V_169 , V_278 ) ;
}
static bool F_249 ( struct V_8 * V_8 ,
int V_278 ,
struct V_1 * V_2 ,
unsigned long * V_306 )
{
int V_307 = V_2 -> V_169 ;
unsigned long V_263 ;
bool V_308 ;
V_2 -> V_235 = F_239 ( V_51 , F_187 ( V_8 ) ) ;
if ( F_196 ( V_245 ) && V_2 -> V_169 &&
F_198 ( V_8 , V_2 -> V_169 , 0 , V_278 )
!= V_268 )
V_307 = 0 ;
V_263 = F_25 ( F_208 ( V_8 ) , F_209 (
V_8 -> V_266 , V_267 ) ) ;
V_308 = ( V_201 && F_250 ( V_8 ) ) ;
if ( ! V_308 && F_245 ( V_8 , V_307 ,
V_263 , V_278 ) )
return true ;
F_199 ( V_8 , V_2 , F_174 ( V_8 ) == V_278 ) ;
* V_306 += V_2 -> V_235 ;
F_251 ( V_131 , & V_8 -> V_23 ) ;
if ( F_8 ( V_8 ) &&
F_245 ( V_8 , V_307 , 0 , V_278 ) ) {
F_251 ( V_190 , & V_8 -> V_23 ) ;
F_251 ( V_138 , & V_8 -> V_23 ) ;
}
return V_2 -> V_32 >= V_2 -> V_235 ;
}
static unsigned long F_252 ( T_8 * V_289 , int V_169 ,
int * V_278 )
{
int V_291 ;
int V_309 = 0 ;
unsigned long V_272 ;
unsigned long V_273 ;
struct V_1 V_2 = {
. V_50 = V_25 ,
. V_169 = V_169 ,
. V_143 = V_144 ,
. V_140 = ! V_287 ,
. V_127 = 1 ,
. V_221 = 1 ,
} ;
F_96 ( V_310 ) ;
do {
unsigned long V_306 = 0 ;
bool V_311 = true ;
bool V_312 = ( V_169 > 0 ) ;
V_2 . V_120 = 0 ;
for ( V_291 = V_289 -> V_313 - 1 ; V_291 >= 0 ; V_291 -- ) {
struct V_8 * V_8 = V_289 -> V_279 + V_291 ;
if ( ! F_215 ( V_8 ) )
continue;
if ( V_2 . V_143 != V_144 &&
! F_8 ( V_8 ) )
continue;
F_244 ( V_8 , & V_2 ) ;
if ( V_201 && F_253 ( V_291 ) ) {
V_309 = V_291 ;
break;
}
if ( ! F_245 ( V_8 , V_169 , 0 , 0 ) ) {
V_309 = V_291 ;
break;
} else {
F_251 ( V_190 , & V_8 -> V_23 ) ;
F_251 ( V_138 , & V_8 -> V_23 ) ;
}
}
if ( V_291 < 0 )
goto V_52;
for ( V_291 = 0 ; V_291 <= V_309 ; V_291 ++ ) {
struct V_8 * V_8 = V_289 -> V_279 + V_291 ;
if ( ! F_215 ( V_8 ) )
continue;
if ( V_312 &&
F_254 ( V_8 , V_169 ,
F_208 ( V_8 ) ,
* V_278 , 0 ) )
V_312 = false ;
}
if ( V_2 . V_143 < V_144 - 2 )
V_2 . V_140 = 1 ;
for ( V_291 = 0 ; V_291 <= V_309 ; V_291 ++ ) {
struct V_8 * V_8 = V_289 -> V_279 + V_291 ;
if ( ! F_215 ( V_8 ) )
continue;
if ( V_2 . V_143 != V_144 &&
! F_8 ( V_8 ) )
continue;
V_2 . V_32 = 0 ;
V_273 = 0 ;
V_272 = F_218 ( V_8 ,
V_169 , V_2 . V_50 ,
& V_273 ) ;
V_2 . V_120 += V_272 ;
if ( F_249 ( V_8 , V_309 ,
& V_2 , & V_306 ) )
V_311 = false ;
}
if ( F_226 ( & V_289 -> V_298 ) &&
F_224 ( V_289 ) )
F_248 ( & V_289 -> V_298 ) ;
if ( V_169 && V_2 . V_120 >= 2UL << V_169 )
V_169 = V_2 . V_169 = 0 ;
if ( F_255 () || F_256 () )
break;
if ( V_312 && V_2 . V_120 > V_306 )
F_257 ( V_289 , V_169 ) ;
if ( V_311 || ! V_2 . V_120 )
V_2 . V_143 -- ;
} while ( V_2 . V_143 >= 1 &&
! F_246 ( V_289 , V_169 , * V_278 ) );
V_52:
* V_278 = V_309 ;
return V_169 ;
}
static void F_258 ( T_8 * V_289 , int V_169 , int V_278 )
{
long V_305 = 0 ;
F_259 ( V_314 ) ;
if ( F_260 ( V_56 ) || F_256 () )
return;
F_261 ( & V_289 -> V_294 , & V_314 , V_315 ) ;
if ( F_247 ( V_289 , V_169 , V_305 , V_278 ) ) {
V_305 = F_262 ( V_184 / 10 ) ;
F_263 ( & V_289 -> V_294 , & V_314 ) ;
F_261 ( & V_289 -> V_294 , & V_314 , V_315 ) ;
}
if ( F_247 ( V_289 , V_169 , V_305 , V_278 ) ) {
F_264 ( V_289 -> V_193 ) ;
F_265 ( V_289 , V_316 ) ;
F_266 ( V_289 ) ;
if ( ! F_256 () )
F_267 () ;
F_265 ( V_289 , V_317 ) ;
} else {
if ( V_305 )
F_96 ( V_318 ) ;
else
F_96 ( V_319 ) ;
}
F_263 ( & V_289 -> V_294 , & V_314 ) ;
}
static int F_268 ( void * V_320 )
{
unsigned long V_169 , V_321 ;
unsigned V_322 ;
int V_278 , V_323 ;
int V_324 ;
T_8 * V_289 = ( T_8 * ) V_320 ;
struct V_325 * V_326 = V_56 ;
struct V_253 V_253 = {
. V_262 = 0 ,
} ;
const struct V_327 * V_327 = F_269 ( V_289 -> V_193 ) ;
F_270 ( V_25 ) ;
if ( ! F_271 ( V_327 ) )
F_272 ( V_326 , V_327 ) ;
V_56 -> V_253 = & V_253 ;
V_326 -> V_23 |= V_328 | V_57 | V_329 ;
F_273 () ;
V_169 = V_321 = 0 ;
V_322 = 0 ;
V_278 = V_323 = V_289 -> V_313 - 1 ;
V_324 = V_278 ;
for ( ; ; ) {
bool V_46 ;
if ( V_324 >= V_323 &&
V_322 == V_321 ) {
V_321 = V_289 -> V_330 ;
V_323 = V_289 -> V_278 ;
V_289 -> V_330 = 0 ;
V_289 -> V_278 = V_289 -> V_313 - 1 ;
}
if ( V_169 < V_321 || V_278 > V_323 ) {
V_169 = V_321 ;
V_278 = V_323 ;
} else {
F_258 ( V_289 , V_322 ,
V_324 ) ;
V_169 = V_289 -> V_330 ;
V_278 = V_289 -> V_278 ;
V_321 = V_169 ;
V_323 = V_278 ;
V_289 -> V_330 = 0 ;
V_289 -> V_278 = V_289 -> V_313 - 1 ;
}
V_46 = F_255 () ;
if ( F_256 () )
break;
if ( ! V_46 ) {
F_274 ( V_289 -> V_193 , V_169 ) ;
V_324 = V_278 ;
V_322 = F_252 ( V_289 , V_169 ,
& V_324 ) ;
}
}
V_326 -> V_23 &= ~ ( V_328 | V_57 | V_329 ) ;
V_56 -> V_253 = NULL ;
F_275 () ;
return 0 ;
}
void F_276 ( struct V_8 * V_8 , int V_169 , enum V_275 V_278 )
{
T_8 * V_289 ;
if ( ! F_215 ( V_8 ) )
return;
if ( ! F_216 ( V_8 , V_25 | V_280 ) )
return;
V_289 = V_8 -> V_192 ;
if ( V_289 -> V_330 < V_169 ) {
V_289 -> V_330 = V_169 ;
V_289 -> V_278 = F_25 ( V_289 -> V_278 , V_278 ) ;
}
if ( ! F_226 ( & V_289 -> V_294 ) )
return;
if ( F_245 ( V_8 , V_169 , 0 , 0 ) )
return;
F_277 ( V_289 -> V_193 , F_174 ( V_8 ) , V_169 ) ;
F_227 ( & V_289 -> V_294 ) ;
}
unsigned long F_278 ( unsigned long V_235 )
{
struct V_253 V_253 ;
struct V_1 V_2 = {
. V_235 = V_235 ,
. V_50 = V_302 ,
. V_143 = V_144 ,
. V_140 = 1 ,
. V_127 = 1 ,
. V_221 = 1 ,
. V_191 = 1 ,
} ;
struct V_269 * V_269 = F_279 ( F_280 () , V_2 . V_50 ) ;
struct V_325 * V_320 = V_56 ;
unsigned long V_120 ;
V_320 -> V_23 |= V_328 ;
F_270 ( V_2 . V_50 ) ;
V_253 . V_262 = 0 ;
V_320 -> V_253 = & V_253 ;
V_120 = F_219 ( V_269 , & V_2 ) ;
V_320 -> V_253 = NULL ;
F_275 () ;
V_320 -> V_23 &= ~ V_328 ;
return V_120 ;
}
static int F_281 ( struct V_331 * V_332 , unsigned long V_333 ,
void * V_334 )
{
int V_39 ;
if ( V_333 == V_335 || V_333 == V_336 ) {
F_282 (nid, N_MEMORY) {
T_8 * V_289 = F_241 ( V_39 ) ;
const struct V_327 * V_337 ;
V_337 = F_269 ( V_289 -> V_193 ) ;
if ( F_283 ( V_338 , V_337 ) < V_339 )
F_272 ( V_289 -> F_268 , V_337 ) ;
}
}
return V_340 ;
}
int F_284 ( int V_39 )
{
T_8 * V_289 = F_241 ( V_39 ) ;
int V_46 = 0 ;
if ( V_289 -> F_268 )
return 0 ;
V_289 -> F_268 = F_285 ( F_268 , V_289 , L_3 , V_39 ) ;
if ( F_286 ( V_289 -> F_268 ) ) {
F_64 ( V_341 == V_342 ) ;
F_24 ( L_4 , V_39 ) ;
V_46 = F_287 ( V_289 -> F_268 ) ;
V_289 -> F_268 = NULL ;
}
return V_46 ;
}
void F_288 ( int V_39 )
{
struct V_325 * F_268 = F_241 ( V_39 ) -> F_268 ;
if ( F_268 ) {
F_289 ( F_268 ) ;
F_241 ( V_39 ) -> F_268 = NULL ;
}
}
static int T_10 F_290 ( void )
{
int V_39 ;
F_291 () ;
F_282 (nid, N_MEMORY)
F_284 ( V_39 ) ;
F_292 ( F_281 , 0 ) ;
return 0 ;
}
static inline unsigned long F_293 ( struct V_8 * V_8 )
{
unsigned long V_343 = F_6 ( V_8 , V_344 ) ;
unsigned long V_345 = F_6 ( V_8 , V_11 ) +
F_6 ( V_8 , V_10 ) ;
return ( V_345 > V_343 ) ? ( V_345 - V_343 ) : 0 ;
}
static long F_294 ( struct V_8 * V_8 )
{
long V_346 ;
long V_35 = 0 ;
if ( V_347 & V_348 )
V_346 = F_6 ( V_8 , V_349 ) ;
else
V_346 = F_293 ( V_8 ) ;
if ( ! ( V_347 & V_350 ) )
V_35 += F_6 ( V_8 , V_351 ) ;
if ( F_69 ( V_35 > V_346 ) )
V_35 = V_346 ;
return V_346 - V_35 ;
}
static int F_295 ( struct V_8 * V_8 , T_2 V_50 , unsigned int V_169 )
{
const unsigned long V_168 = 1 << V_169 ;
struct V_325 * V_320 = V_56 ;
struct V_253 V_253 ;
struct V_1 V_2 = {
. V_235 = F_239 ( V_168 , V_51 ) ,
. V_50 = ( V_50 = F_232 ( V_50 ) ) ,
. V_169 = V_169 ,
. V_143 = V_352 ,
. V_140 = ! ! ( V_347 & V_350 ) ,
. V_127 = ! ! ( V_347 & V_348 ) ,
. V_221 = 1 ,
} ;
F_28 () ;
V_320 -> V_23 |= V_328 | V_57 ;
F_270 ( V_50 ) ;
V_253 . V_262 = 0 ;
V_320 -> V_253 = & V_253 ;
if ( F_294 ( V_8 ) > V_8 -> V_353 ) {
do {
F_199 ( V_8 , & V_2 , true ) ;
} while ( V_2 . V_120 < V_168 && -- V_2 . V_143 >= 0 );
}
V_320 -> V_253 = NULL ;
V_56 -> V_23 &= ~ ( V_328 | V_57 ) ;
F_275 () ;
return V_2 . V_120 >= V_168 ;
}
int F_296 ( struct V_8 * V_8 , T_2 V_50 , unsigned int V_169 )
{
int V_193 ;
int V_46 ;
if ( F_294 ( V_8 ) <= V_8 -> V_353 &&
F_6 ( V_8 , V_354 ) <= V_8 -> V_355 )
return V_356 ;
if ( ! F_8 ( V_8 ) )
return V_356 ;
if ( ! ( V_50 & V_357 ) || ( V_56 -> V_23 & V_328 ) )
return V_358 ;
V_193 = F_204 ( V_8 ) ;
if ( F_297 ( V_193 , V_359 ) && V_193 != F_280 () )
return V_358 ;
if ( F_298 ( V_360 , & V_8 -> V_23 ) )
return V_358 ;
V_46 = F_295 ( V_8 , V_50 , V_169 ) ;
F_251 ( V_360 , & V_8 -> V_23 ) ;
if ( ! V_46 )
F_96 ( V_361 ) ;
return V_46 ;
}
int F_90 ( struct V_54 * V_54 )
{
return ! F_299 ( F_49 ( V_54 ) ) && ! F_300 ( V_54 ) ;
}
void F_301 ( struct V_54 * * V_362 , int V_168 )
{
struct V_15 * V_15 ;
struct V_8 * V_8 = NULL ;
int V_363 = 0 ;
int V_364 = 0 ;
int V_291 ;
for ( V_291 = 0 ; V_291 < V_168 ; V_291 ++ ) {
struct V_54 * V_54 = V_362 [ V_291 ] ;
struct V_8 * V_365 ;
V_363 ++ ;
V_365 = F_109 ( V_54 ) ;
if ( V_365 != V_8 ) {
if ( V_8 )
F_152 ( & V_8 -> V_170 ) ;
V_8 = V_365 ;
F_147 ( & V_8 -> V_170 ) ;
}
V_15 = F_148 ( V_54 , V_8 ) ;
if ( ! F_88 ( V_54 ) || ! F_86 ( V_54 ) )
continue;
if ( F_90 ( V_54 ) ) {
enum V_16 V_17 = F_302 ( V_54 ) ;
F_87 ( F_108 ( V_54 ) , V_54 ) ;
F_89 ( V_54 ) ;
F_151 ( V_54 , V_15 , V_366 ) ;
F_156 ( V_54 , V_15 , V_17 ) ;
V_364 ++ ;
}
}
if ( V_8 ) {
F_177 ( V_90 , V_364 ) ;
F_177 ( V_367 , V_363 ) ;
F_152 ( & V_8 -> V_170 ) ;
}
}
