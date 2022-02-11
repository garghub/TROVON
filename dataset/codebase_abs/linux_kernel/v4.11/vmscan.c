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
F_6 ( V_7 , V_10 ) ;
if ( F_7 () > 0 )
V_8 += F_6 ( V_7 , V_11 ) +
F_6 ( V_7 , V_12 ) ;
return V_8 ;
}
unsigned long F_8 ( struct V_13 * V_14 )
{
unsigned long V_8 ;
V_8 = F_9 ( V_14 , V_15 ) +
F_9 ( V_14 , V_16 ) +
F_9 ( V_14 , V_17 ) ;
if ( F_7 () > 0 )
V_8 += F_9 ( V_14 , V_18 ) +
F_9 ( V_14 , V_19 ) +
F_9 ( V_14 , V_20 ) ;
return V_8 ;
}
bool F_10 ( struct V_13 * V_14 )
{
return F_9 ( V_14 , V_21 ) <
F_8 ( V_14 ) * 6 ;
}
unsigned long F_11 ( struct V_22 * V_22 , enum V_23 V_24 , int V_25 )
{
unsigned long V_26 ;
int V_27 ;
if ( ! F_12 () )
V_26 = F_13 ( V_22 , V_24 ) ;
else
V_26 = F_14 ( F_15 ( V_22 ) , V_28 + V_24 ) ;
for ( V_27 = V_25 + 1 ; V_27 < V_29 ; V_27 ++ ) {
struct V_7 * V_7 = & F_15 ( V_22 ) -> V_30 [ V_27 ] ;
unsigned long V_31 ;
if ( ! F_16 ( V_7 ) )
continue;
if ( ! F_12 () )
V_31 = F_17 ( V_22 , V_24 , V_27 ) ;
else
V_31 = F_18 ( & F_15 ( V_22 ) -> V_30 [ V_27 ] ,
V_32 + V_24 ) ;
V_26 -= F_19 ( V_31 , V_26 ) ;
}
return V_26 ;
}
int F_20 ( struct V_33 * V_33 )
{
T_1 V_31 = sizeof( * V_33 -> V_34 ) ;
if ( V_33 -> V_35 & V_36 )
V_31 *= V_37 ;
V_33 -> V_34 = F_21 ( V_31 , V_38 ) ;
if ( ! V_33 -> V_34 )
return - V_39 ;
F_22 ( & V_40 ) ;
F_23 ( & V_33 -> V_41 , & V_42 ) ;
F_24 ( & V_40 ) ;
return 0 ;
}
void F_25 ( struct V_33 * V_33 )
{
F_22 ( & V_40 ) ;
F_26 ( & V_33 -> V_41 ) ;
F_24 ( & V_40 ) ;
F_27 ( V_33 -> V_34 ) ;
}
static unsigned long F_28 ( struct V_43 * V_44 ,
struct V_33 * V_33 ,
unsigned long V_45 ,
unsigned long V_46 )
{
unsigned long V_47 = 0 ;
unsigned long long V_48 ;
long V_49 ;
long V_50 ;
long V_8 ;
long V_51 ;
int V_52 = V_44 -> V_52 ;
long V_53 = V_33 -> V_54 ? V_33 -> V_54
: V_55 ;
long V_56 = 0 , V_57 ;
V_50 = V_33 -> V_58 ( V_33 , V_44 ) ;
if ( V_50 == 0 )
return 0 ;
V_8 = F_29 ( & V_33 -> V_34 [ V_52 ] , 0 ) ;
V_49 = V_8 ;
V_48 = ( 4 * V_45 ) / V_33 -> V_59 ;
V_48 *= V_50 ;
F_30 ( V_48 , V_46 + 1 ) ;
V_49 += V_48 ;
if ( V_49 < 0 ) {
F_31 ( L_1 ,
V_33 -> V_60 , V_49 ) ;
V_49 = V_50 ;
V_57 = V_8 ;
} else
V_57 = V_49 ;
if ( V_48 < V_50 / 4 )
V_49 = F_19 ( V_49 , V_50 / 2 ) ;
if ( V_49 > V_50 * 2 )
V_49 = V_50 * 2 ;
F_32 ( V_33 , V_44 , V_8 ,
V_45 , V_46 ,
V_50 , V_48 , V_49 ) ;
while ( V_49 >= V_53 ||
V_49 >= V_50 ) {
unsigned long V_61 ;
unsigned long V_62 = F_19 ( V_53 , V_49 ) ;
V_44 -> V_62 = V_62 ;
V_61 = V_33 -> V_60 ( V_33 , V_44 ) ;
if ( V_61 == V_63 )
break;
V_47 += V_61 ;
F_33 ( V_64 , V_62 ) ;
V_49 -= V_62 ;
V_56 += V_62 ;
F_34 () ;
}
if ( V_57 >= V_56 )
V_57 -= V_56 ;
else
V_57 = 0 ;
if ( V_57 > 0 )
V_51 = F_35 ( V_57 ,
& V_33 -> V_34 [ V_52 ] ) ;
else
V_51 = F_36 ( & V_33 -> V_34 [ V_52 ] ) ;
F_37 ( V_33 , V_52 , V_47 , V_8 , V_51 , V_49 ) ;
return V_47 ;
}
static unsigned long F_38 ( T_2 V_65 , int V_52 ,
struct V_4 * V_5 ,
unsigned long V_45 ,
unsigned long V_46 )
{
struct V_33 * V_33 ;
unsigned long V_47 = 0 ;
if ( V_5 && ( ! F_39 () || ! F_40 ( V_5 ) ) )
return 0 ;
if ( V_45 == 0 )
V_45 = V_66 ;
if ( ! F_41 ( & V_40 ) ) {
V_47 = 1 ;
goto V_67;
}
F_42 (shrinker, &shrinker_list, list) {
struct V_43 V_2 = {
. V_65 = V_65 ,
. V_52 = V_52 ,
. V_5 = V_5 ,
} ;
if ( F_39 () &&
! ! V_5 != ! ! ( V_33 -> V_35 & V_68 ) )
continue;
if ( ! ( V_33 -> V_35 & V_36 ) )
V_2 . V_52 = 0 ;
V_47 += F_28 ( & V_2 , V_33 , V_45 , V_46 ) ;
}
F_43 ( & V_40 ) ;
V_67:
F_34 () ;
return V_47 ;
}
void F_44 ( int V_52 )
{
unsigned long V_47 ;
do {
struct V_4 * V_5 = NULL ;
V_47 = 0 ;
do {
V_47 += F_38 ( V_38 , V_52 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_45 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_47 > 10 );
}
void F_46 ( void )
{
int V_52 ;
F_47 (nid)
F_44 ( V_52 ) ;
}
static inline int F_48 ( struct V_69 * V_69 )
{
return F_49 ( V_69 ) - F_50 ( V_69 ) == 2 ;
}
static int F_51 ( struct V_70 * V_70 , struct V_1 * V_2 )
{
if ( V_71 -> V_35 & V_72 )
return 1 ;
if ( ! F_52 ( V_70 ) )
return 1 ;
if ( F_53 ( V_70 ) == V_71 -> V_73 )
return 1 ;
return 0 ;
}
static void F_54 ( struct V_74 * V_75 ,
struct V_69 * V_69 , int error )
{
F_55 ( V_69 ) ;
if ( F_56 ( V_69 ) == V_75 )
F_57 ( V_75 , error ) ;
F_58 ( V_69 ) ;
}
static T_3 F_59 ( struct V_69 * V_69 , struct V_74 * V_75 ,
struct V_1 * V_2 )
{
if ( ! F_48 ( V_69 ) )
return V_76 ;
if ( ! V_75 ) {
if ( F_50 ( V_69 ) ) {
if ( F_60 ( V_69 ) ) {
F_61 ( V_69 ) ;
F_62 ( L_2 , V_77 ) ;
return V_78 ;
}
}
return V_76 ;
}
if ( V_75 -> V_79 -> V_80 == NULL )
return V_81 ;
if ( ! F_51 ( V_75 -> V_82 , V_2 ) )
return V_76 ;
if ( F_63 ( V_69 ) ) {
int V_83 ;
struct V_84 V_85 = {
. V_86 = V_87 ,
. V_88 = V_66 ,
. V_89 = 0 ,
. V_90 = V_91 ,
. V_92 = 1 ,
} ;
F_64 ( V_69 ) ;
V_83 = V_75 -> V_79 -> V_80 ( V_69 , & V_85 ) ;
if ( V_83 < 0 )
F_54 ( V_75 , V_69 , V_83 ) ;
if ( V_83 == V_93 ) {
F_65 ( V_69 ) ;
return V_81 ;
}
if ( ! F_66 ( V_69 ) ) {
F_65 ( V_69 ) ;
}
F_67 ( V_69 ) ;
F_68 ( V_69 , V_94 ) ;
return V_95 ;
}
return V_78 ;
}
static int F_69 ( struct V_74 * V_75 , struct V_69 * V_69 ,
bool V_96 )
{
unsigned long V_35 ;
F_70 ( ! F_71 ( V_69 ) ) ;
F_70 ( V_75 != F_56 ( V_69 ) ) ;
F_72 ( & V_75 -> V_97 , V_35 ) ;
if ( ! F_73 ( V_69 , 2 ) )
goto V_98;
if ( F_74 ( F_75 ( V_69 ) ) ) {
F_76 ( V_69 , 2 ) ;
goto V_98;
}
if ( F_77 ( V_69 ) ) {
T_4 V_99 = { . V_100 = F_78 (page) } ;
F_79 ( V_69 , V_99 ) ;
F_80 ( V_69 ) ;
F_81 ( & V_75 -> V_97 , V_35 ) ;
F_82 ( V_99 ) ;
} else {
void (* F_83)( struct V_69 * );
void * V_101 = NULL ;
F_83 = V_75 -> V_79 -> F_83 ;
if ( V_96 && F_84 ( V_69 ) &&
! F_85 ( V_75 ) && ! F_86 ( V_75 ) )
V_101 = F_87 ( V_75 , V_69 ) ;
F_88 ( V_69 , V_101 ) ;
F_81 ( & V_75 -> V_97 , V_35 ) ;
if ( F_83 != NULL )
F_83 ( V_69 ) ;
}
return 1 ;
V_98:
F_81 ( & V_75 -> V_97 , V_35 ) ;
return 0 ;
}
int F_89 ( struct V_74 * V_75 , struct V_69 * V_69 )
{
if ( F_69 ( V_75 , V_69 , false ) ) {
F_76 ( V_69 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_90 ( struct V_69 * V_69 )
{
bool V_102 ;
int V_103 = F_91 ( V_69 ) ;
F_92 ( F_93 ( V_69 ) , V_69 ) ;
V_104:
F_94 ( V_69 ) ;
if ( F_95 ( V_69 ) ) {
V_102 = false ;
F_96 ( V_69 ) ;
} else {
V_102 = true ;
F_97 ( V_69 ) ;
F_98 () ;
}
if ( V_102 && F_95 ( V_69 ) ) {
if ( ! F_99 ( V_69 ) ) {
F_100 ( V_69 ) ;
goto V_104;
}
}
if ( V_103 && ! V_102 )
F_101 ( V_105 ) ;
else if ( ! V_103 && V_102 )
F_101 ( V_106 ) ;
F_100 ( V_69 ) ;
}
static enum V_107 F_102 ( struct V_69 * V_69 ,
struct V_1 * V_2 )
{
int V_108 , V_109 ;
unsigned long V_110 ;
V_108 = F_103 ( V_69 , 1 , V_2 -> V_3 ,
& V_110 ) ;
V_109 = F_104 ( V_69 ) ;
if ( V_110 & V_111 )
return V_112 ;
if ( V_108 ) {
if ( F_105 ( V_69 ) )
return V_113 ;
F_106 ( V_69 ) ;
if ( V_109 || V_108 > 1 )
return V_113 ;
if ( V_110 & V_114 )
return V_113 ;
return V_115 ;
}
if ( V_109 && ! F_105 ( V_69 ) )
return V_116 ;
return V_112 ;
}
static void F_107 ( struct V_69 * V_69 ,
bool * V_117 , bool * V_118 )
{
struct V_74 * V_75 ;
if ( ! F_84 ( V_69 ) ) {
* V_117 = false ;
* V_118 = false ;
return;
}
* V_117 = F_75 ( V_69 ) ;
* V_118 = F_66 ( V_69 ) ;
if ( ! F_50 ( V_69 ) )
return;
V_75 = F_56 ( V_69 ) ;
if ( V_75 && V_75 -> V_79 -> V_119 )
V_75 -> V_79 -> V_119 ( V_69 , V_117 , V_118 ) ;
}
static unsigned long F_108 ( struct V_120 * V_121 ,
struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_122 V_122 ,
struct V_123 * V_124 ,
bool V_125 )
{
F_109 ( V_126 ) ;
F_109 ( V_127 ) ;
int V_128 = 0 ;
unsigned V_129 = 0 ;
unsigned V_130 = 0 ;
unsigned V_131 = 0 ;
unsigned V_132 = 0 ;
unsigned V_133 = 0 ;
unsigned V_134 = 0 ;
unsigned V_135 = 0 ;
unsigned V_136 = 0 ;
F_34 () ;
while ( ! F_110 ( V_121 ) ) {
struct V_74 * V_75 ;
struct V_69 * V_69 ;
int V_137 ;
enum V_107 V_138 = V_116 ;
bool V_117 , V_118 ;
bool V_139 = false ;
int V_61 = V_140 ;
F_34 () ;
V_69 = F_111 ( V_121 ) ;
F_26 ( & V_69 -> V_24 ) ;
if ( ! F_112 ( V_69 ) )
goto V_141;
F_92 ( F_113 ( V_69 ) , V_69 ) ;
V_2 -> V_45 ++ ;
if ( F_74 ( ! F_95 ( V_69 ) ) )
goto V_142;
if ( ! V_2 -> V_143 && F_114 ( V_69 ) )
goto V_144;
if ( F_114 ( V_69 ) || F_77 ( V_69 ) )
V_2 -> V_45 ++ ;
V_137 = ( V_2 -> V_65 & V_145 ) ||
( F_77 ( V_69 ) && ( V_2 -> V_65 & V_146 ) ) ;
F_107 ( V_69 , & V_117 , & V_118 ) ;
if ( V_117 || V_118 )
V_130 ++ ;
if ( V_117 && ! V_118 )
V_129 ++ ;
V_75 = F_56 ( V_69 ) ;
if ( ( ( V_117 || V_118 ) && V_75 &&
F_52 ( V_75 -> V_82 ) ) ||
( V_118 && F_115 ( V_69 ) ) )
V_131 ++ ;
if ( F_66 ( V_69 ) ) {
if ( F_116 () &&
F_115 ( V_69 ) &&
F_117 ( V_147 , & V_14 -> V_35 ) ) {
V_134 ++ ;
goto V_148;
} else if ( F_2 ( V_2 ) ||
! F_115 ( V_69 ) || ! V_137 ) {
F_64 ( V_69 ) ;
V_133 ++ ;
goto V_148;
} else {
F_58 ( V_69 ) ;
F_118 ( V_69 ) ;
F_23 ( & V_69 -> V_24 , V_121 ) ;
continue;
}
}
if ( ! V_125 )
V_138 = F_102 ( V_69 , V_2 ) ;
switch ( V_138 ) {
case V_113 :
goto V_148;
case V_115 :
V_135 ++ ;
goto V_144;
case V_112 :
case V_116 :
;
}
if ( F_119 ( V_69 ) && ! F_77 ( V_69 ) ) {
if ( ! ( V_2 -> V_65 & V_146 ) )
goto V_144;
if ( ! F_120 ( V_69 , V_121 ) )
goto V_148;
V_139 = true ;
V_137 = 1 ;
V_75 = F_56 ( V_69 ) ;
} else if ( F_74 ( F_121 ( V_69 ) ) ) {
if ( F_122 ( V_69 , V_121 ) )
goto V_144;
}
F_92 ( F_121 ( V_69 ) , V_69 ) ;
if ( F_114 ( V_69 ) && V_75 ) {
switch ( V_61 = F_123 ( V_69 , V_139 ?
( V_122 | V_149 | V_150 ) :
( V_122 | V_149 ) ) ) {
case V_151 :
V_136 ++ ;
goto V_148;
case V_152 :
goto V_144;
case V_153 :
goto V_142;
case V_154 :
goto V_139;
case V_140 :
;
}
}
if ( F_75 ( V_69 ) ) {
if ( F_84 ( V_69 ) &&
( ! F_116 () || ! F_115 ( V_69 ) ||
! F_117 ( V_155 , & V_14 -> V_35 ) ) ) {
F_68 ( V_69 , V_156 ) ;
F_64 ( V_69 ) ;
goto V_148;
}
if ( V_138 == V_116 )
goto V_144;
if ( ! V_137 )
goto V_144;
if ( ! V_2 -> V_157 )
goto V_144;
F_124 () ;
switch ( F_59 ( V_69 , V_75 , V_2 ) ) {
case V_76 :
goto V_144;
case V_81 :
goto V_148;
case V_95 :
if ( F_66 ( V_69 ) )
goto V_141;
if ( F_75 ( V_69 ) )
goto V_141;
if ( ! F_112 ( V_69 ) )
goto V_141;
if ( F_75 ( V_69 ) || F_66 ( V_69 ) )
goto V_144;
V_75 = F_56 ( V_69 ) ;
case V_78 :
;
}
}
if ( F_50 ( V_69 ) ) {
if ( ! F_125 ( V_69 , V_2 -> V_65 ) )
goto V_148;
if ( ! V_75 && F_49 ( V_69 ) == 1 ) {
F_58 ( V_69 ) ;
if ( F_126 ( V_69 ) )
goto V_158;
else {
V_132 ++ ;
continue;
}
}
}
V_139:
if ( ! V_75 || ! F_69 ( V_75 , V_69 , true ) )
goto V_144;
F_127 ( V_69 ) ;
V_158:
if ( V_61 == V_154 )
F_101 ( V_159 ) ;
V_132 ++ ;
F_128 ( & V_69 -> V_24 , & V_127 ) ;
continue;
V_142:
if ( F_77 ( V_69 ) )
F_129 ( V_69 ) ;
F_58 ( V_69 ) ;
F_128 ( & V_69 -> V_24 , & V_126 ) ;
continue;
V_148:
if ( F_77 ( V_69 ) && F_130 ( V_69 ) )
F_129 ( V_69 ) ;
F_92 ( F_113 ( V_69 ) , V_69 ) ;
F_131 ( V_69 ) ;
V_128 ++ ;
V_144:
F_58 ( V_69 ) ;
V_141:
F_128 ( & V_69 -> V_24 , & V_126 ) ;
F_92 ( F_93 ( V_69 ) || F_91 ( V_69 ) , V_69 ) ;
}
F_132 ( & V_127 ) ;
F_133 () ;
F_134 ( & V_127 , true ) ;
F_135 ( & V_126 , V_121 ) ;
F_33 ( V_160 , V_128 ) ;
if ( V_124 ) {
V_124 -> V_130 = V_130 ;
V_124 -> V_131 = V_131 ;
V_124 -> V_129 = V_129 ;
V_124 -> V_133 = V_133 ;
V_124 -> V_134 = V_134 ;
V_124 -> V_161 = V_128 ;
V_124 -> V_135 = V_135 ;
V_124 -> V_136 = V_136 ;
}
return V_132 ;
}
unsigned long F_136 ( struct V_7 * V_7 ,
struct V_120 * V_121 )
{
struct V_1 V_2 = {
. V_65 = V_38 ,
. V_162 = V_163 ,
. V_143 = 1 ,
} ;
unsigned long V_61 ;
struct V_69 * V_69 , * V_164 ;
F_109 ( V_165 ) ;
F_137 (page, next, page_list, lru) {
if ( F_84 ( V_69 ) && ! F_75 ( V_69 ) &&
! F_138 ( V_69 ) ) {
F_139 ( V_69 ) ;
F_140 ( & V_69 -> V_24 , & V_165 ) ;
}
}
V_61 = F_108 ( & V_165 , V_7 -> V_166 , & V_2 ,
V_167 | V_168 , NULL , true ) ;
F_135 ( & V_165 , V_121 ) ;
F_141 ( V_7 -> V_166 , V_17 , - V_61 ) ;
return V_61 ;
}
int F_142 ( struct V_69 * V_69 , T_5 V_169 )
{
int V_61 = - V_170 ;
if ( ! F_93 ( V_69 ) )
return V_61 ;
if ( F_91 ( V_69 ) && ! ( V_169 & V_171 ) )
return V_61 ;
V_61 = - V_172 ;
if ( V_169 & V_173 ) {
if ( F_66 ( V_69 ) )
return V_61 ;
if ( F_75 ( V_69 ) ) {
struct V_74 * V_75 ;
V_75 = F_56 ( V_69 ) ;
if ( V_75 && ! V_75 -> V_79 -> V_174 )
return V_61 ;
}
}
if ( ( V_169 & V_175 ) && F_114 ( V_69 ) )
return V_61 ;
if ( F_143 ( F_144 ( V_69 ) ) ) {
F_145 ( V_69 ) ;
V_61 = 0 ;
}
return V_61 ;
}
static T_6 void F_146 ( struct V_22 * V_22 ,
enum V_23 V_24 , unsigned long * V_176 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( ! V_176 [ V_27 ] )
continue;
F_147 ( V_22 , V_24 , V_27 , - V_176 [ V_27 ] ) ;
#ifdef F_148
F_149 ( V_22 , V_24 , V_27 , - V_176 [ V_27 ] ) ;
#endif
}
}
static unsigned long F_150 ( unsigned long V_62 ,
struct V_22 * V_22 , struct V_120 * V_177 ,
unsigned long * V_45 , struct V_1 * V_2 ,
T_5 V_169 , enum V_23 V_24 )
{
struct V_120 * V_178 = & V_22 -> V_179 [ V_24 ] ;
unsigned long V_180 = 0 ;
unsigned long V_176 [ V_29 ] = { 0 } ;
unsigned long V_181 [ V_29 ] = { 0 , } ;
unsigned long V_182 = 0 , V_183 = 0 ;
unsigned long V_184 , V_185 ;
F_109 ( V_186 ) ;
for ( V_184 = 0 ; V_184 < V_62 && V_180 < V_62 &&
! F_110 ( V_178 ) ; ) {
struct V_69 * V_69 ;
V_69 = F_111 ( V_178 ) ;
F_151 ( V_69 , V_178 , V_35 ) ;
F_92 ( ! F_93 ( V_69 ) , V_69 ) ;
if ( F_152 ( V_69 ) > V_2 -> V_187 ) {
F_140 ( & V_69 -> V_24 , & V_186 ) ;
V_181 [ F_152 ( V_69 ) ] ++ ;
continue;
}
V_184 ++ ;
switch ( F_142 ( V_69 , V_169 ) ) {
case 0 :
V_185 = F_153 ( V_69 ) ;
V_180 += V_185 ;
V_176 [ F_152 ( V_69 ) ] += V_185 ;
F_140 ( & V_69 -> V_24 , V_177 ) ;
break;
case - V_172 :
F_140 ( & V_69 -> V_24 , V_178 ) ;
continue;
default:
F_154 () ;
}
}
if ( ! F_110 ( & V_186 ) ) {
int V_27 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( ! V_181 [ V_27 ] )
continue;
F_155 ( V_188 , V_27 , V_181 [ V_27 ] ) ;
V_182 += V_181 [ V_27 ] ;
}
V_183 = F_110 ( V_178 ) ? V_182 : V_182 >> 2 ;
F_135 ( & V_186 , V_178 ) ;
}
* V_45 = V_184 + V_183 ;
F_156 ( V_2 -> V_187 , V_2 -> V_189 , V_62 ,
V_184 , V_182 , V_180 , V_169 , V_24 ) ;
F_146 ( V_22 , V_24 , V_176 ) ;
return V_180 ;
}
int F_99 ( struct V_69 * V_69 )
{
int V_61 = - V_172 ;
F_92 ( ! F_49 ( V_69 ) , V_69 ) ;
F_157 ( F_158 ( V_69 ) , L_3 ) ;
if ( F_93 ( V_69 ) ) {
struct V_7 * V_7 = F_159 ( V_69 ) ;
struct V_22 * V_22 ;
F_160 ( F_161 ( V_7 ) ) ;
V_22 = F_162 ( V_69 , V_7 -> V_166 ) ;
if ( F_93 ( V_69 ) ) {
int V_24 = F_163 ( V_69 ) ;
F_164 ( V_69 ) ;
F_145 ( V_69 ) ;
F_165 ( V_69 , V_22 , V_24 ) ;
V_61 = 0 ;
}
F_166 ( F_161 ( V_7 ) ) ;
}
return V_61 ;
}
static int F_167 ( struct V_13 * V_14 , int V_190 ,
struct V_1 * V_2 )
{
unsigned long V_191 , V_192 ;
if ( F_116 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_190 ) {
V_191 = F_14 ( V_14 , V_16 ) ;
V_192 = F_14 ( V_14 , V_17 ) ;
} else {
V_191 = F_14 ( V_14 , V_19 ) ;
V_192 = F_14 ( V_14 , V_20 ) ;
}
if ( ( V_2 -> V_65 & ( V_146 | V_145 ) ) == ( V_146 | V_145 ) )
V_191 >>= 3 ;
return V_192 > V_191 ;
}
static T_7 void
F_168 ( struct V_22 * V_22 , struct V_120 * V_121 )
{
struct V_193 * V_123 = & V_22 -> V_123 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
F_109 ( V_194 ) ;
while ( ! F_110 ( V_121 ) ) {
struct V_69 * V_69 = F_111 ( V_121 ) ;
int V_24 ;
F_92 ( F_93 ( V_69 ) , V_69 ) ;
F_26 ( & V_69 -> V_24 ) ;
if ( F_74 ( ! F_95 ( V_69 ) ) ) {
F_166 ( & V_14 -> V_195 ) ;
F_90 ( V_69 ) ;
F_160 ( & V_14 -> V_195 ) ;
continue;
}
V_22 = F_162 ( V_69 , V_14 ) ;
F_169 ( V_69 ) ;
V_24 = F_163 ( V_69 ) ;
F_170 ( V_69 , V_22 , V_24 ) ;
if ( F_171 ( V_24 ) ) {
int V_190 = F_172 ( V_24 ) ;
int V_196 = F_153 ( V_69 ) ;
V_123 -> V_197 [ V_190 ] += V_196 ;
}
if ( F_126 ( V_69 ) ) {
F_173 ( V_69 ) ;
F_174 ( V_69 ) ;
F_165 ( V_69 , V_22 , V_24 ) ;
if ( F_74 ( F_175 ( V_69 ) ) ) {
F_166 ( & V_14 -> V_195 ) ;
F_176 ( V_69 ) ;
( * F_177 ( V_69 ) ) ( V_69 ) ;
F_160 ( & V_14 -> V_195 ) ;
} else
F_128 ( & V_69 -> V_24 , & V_194 ) ;
}
}
F_135 ( & V_194 , V_121 ) ;
}
static int F_178 ( void )
{
return ! ( V_71 -> V_35 & V_198 ) ||
V_71 -> V_73 == NULL ||
F_179 ( V_71 -> V_73 ) ;
}
static T_7 unsigned long
F_180 ( unsigned long V_62 , struct V_22 * V_22 ,
struct V_1 * V_2 , enum V_23 V_24 )
{
F_109 ( V_121 ) ;
unsigned long V_45 ;
unsigned long V_132 = 0 ;
unsigned long V_180 ;
struct V_123 V_124 = {} ;
T_5 V_199 = 0 ;
int V_190 = F_172 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
struct V_193 * V_123 = & V_22 -> V_123 ;
while ( F_74 ( F_167 ( V_14 , V_190 , V_2 ) ) ) {
F_181 ( V_200 , V_201 / 10 ) ;
if ( F_182 ( V_71 ) )
return V_66 ;
}
F_183 () ;
if ( ! V_2 -> V_143 )
V_199 |= V_175 ;
F_160 ( & V_14 -> V_195 ) ;
V_180 = F_150 ( V_62 , V_22 , & V_121 ,
& V_45 , V_2 , V_199 , V_24 ) ;
F_184 ( V_14 , V_20 + V_190 , V_180 ) ;
V_123 -> V_202 [ V_190 ] += V_180 ;
if ( F_1 ( V_2 ) ) {
F_184 ( V_14 , V_21 , V_45 ) ;
if ( F_116 () )
F_185 ( V_203 , V_45 ) ;
else
F_185 ( V_204 , V_45 ) ;
}
F_166 ( & V_14 -> V_195 ) ;
if ( V_180 == 0 )
return 0 ;
V_132 = F_108 ( & V_121 , V_14 , V_2 , V_167 ,
& V_124 , false ) ;
F_160 ( & V_14 -> V_195 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_116 () )
F_185 ( V_205 , V_132 ) ;
else
F_185 ( V_206 , V_132 ) ;
}
F_168 ( V_22 , & V_121 ) ;
F_184 ( V_14 , V_20 + V_190 , - V_180 ) ;
F_166 ( & V_14 -> V_195 ) ;
F_132 ( & V_121 ) ;
F_134 ( & V_121 , true ) ;
if ( V_124 . V_133 && V_124 . V_133 == V_180 )
F_186 ( V_147 , & V_14 -> V_35 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_124 . V_130 && V_124 . V_130 == V_124 . V_131 )
F_186 ( V_207 , & V_14 -> V_35 ) ;
if ( V_124 . V_129 == V_180 ) {
F_187 ( 0 , V_208 ) ;
F_186 ( V_155 , & V_14 -> V_35 ) ;
}
if ( V_124 . V_134 && F_178 () )
F_181 ( V_200 , V_201 / 10 ) ;
}
if ( ! V_2 -> V_209 && ! F_116 () &&
F_178 () )
F_188 ( V_14 , V_200 , V_201 / 10 ) ;
F_189 ( V_14 -> V_210 ,
V_45 , V_132 ,
V_124 . V_130 , V_124 . V_133 ,
V_124 . V_131 , V_124 . V_134 ,
V_124 . V_161 , V_124 . V_135 ,
V_124 . V_136 ,
V_2 -> V_162 , V_190 ) ;
return V_132 ;
}
static unsigned F_190 ( struct V_22 * V_22 ,
struct V_120 * V_41 ,
struct V_120 * V_194 ,
enum V_23 V_24 )
{
struct V_13 * V_14 = F_15 ( V_22 ) ;
struct V_69 * V_69 ;
int V_185 ;
int V_211 = 0 ;
while ( ! F_110 ( V_41 ) ) {
V_69 = F_111 ( V_41 ) ;
V_22 = F_162 ( V_69 , V_14 ) ;
F_92 ( F_93 ( V_69 ) , V_69 ) ;
F_169 ( V_69 ) ;
V_185 = F_153 ( V_69 ) ;
F_191 ( V_22 , V_24 , F_152 ( V_69 ) , V_185 ) ;
F_140 ( & V_69 -> V_24 , & V_22 -> V_179 [ V_24 ] ) ;
if ( F_126 ( V_69 ) ) {
F_173 ( V_69 ) ;
F_174 ( V_69 ) ;
F_165 ( V_69 , V_22 , V_24 ) ;
if ( F_74 ( F_175 ( V_69 ) ) ) {
F_166 ( & V_14 -> V_195 ) ;
F_176 ( V_69 ) ;
( * F_177 ( V_69 ) ) ( V_69 ) ;
F_160 ( & V_14 -> V_195 ) ;
} else
F_128 ( & V_69 -> V_24 , V_194 ) ;
} else {
V_211 += V_185 ;
}
}
if ( ! F_171 ( V_24 ) )
F_185 ( V_212 , V_211 ) ;
return V_211 ;
}
static void F_192 ( unsigned long V_62 ,
struct V_22 * V_22 ,
struct V_1 * V_2 ,
enum V_23 V_24 )
{
unsigned long V_180 ;
unsigned long V_45 ;
unsigned long V_110 ;
F_109 ( V_213 ) ;
F_109 ( V_214 ) ;
F_109 ( V_215 ) ;
struct V_69 * V_69 ;
struct V_193 * V_123 = & V_22 -> V_123 ;
unsigned V_216 , V_161 ;
unsigned V_217 = 0 ;
T_5 V_199 = 0 ;
int V_190 = F_172 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
F_183 () ;
if ( ! V_2 -> V_143 )
V_199 |= V_175 ;
F_160 ( & V_14 -> V_195 ) ;
V_180 = F_150 ( V_62 , V_22 , & V_213 ,
& V_45 , V_2 , V_199 , V_24 ) ;
F_184 ( V_14 , V_20 + V_190 , V_180 ) ;
V_123 -> V_202 [ V_190 ] += V_180 ;
if ( F_1 ( V_2 ) )
F_184 ( V_14 , V_21 , V_45 ) ;
F_185 ( V_218 , V_45 ) ;
F_166 ( & V_14 -> V_195 ) ;
while ( ! F_110 ( & V_213 ) ) {
F_34 () ;
V_69 = F_111 ( & V_213 ) ;
F_26 ( & V_69 -> V_24 ) ;
if ( F_74 ( ! F_95 ( V_69 ) ) ) {
F_90 ( V_69 ) ;
continue;
}
if ( F_74 ( V_219 ) ) {
if ( F_50 ( V_69 ) && F_112 ( V_69 ) ) {
if ( F_50 ( V_69 ) )
F_125 ( V_69 , 0 ) ;
F_58 ( V_69 ) ;
}
}
if ( F_103 ( V_69 , 0 , V_2 -> V_3 ,
& V_110 ) ) {
V_217 += F_153 ( V_69 ) ;
if ( ( V_110 & V_114 ) && F_84 ( V_69 ) ) {
F_128 ( & V_69 -> V_24 , & V_214 ) ;
continue;
}
}
F_139 ( V_69 ) ;
F_128 ( & V_69 -> V_24 , & V_215 ) ;
}
F_160 ( & V_14 -> V_195 ) ;
V_123 -> V_197 [ V_190 ] += V_217 ;
V_161 = F_190 ( V_22 , & V_214 , & V_213 , V_24 ) ;
V_216 = F_190 ( V_22 , & V_215 , & V_213 , V_24 - V_220 ) ;
F_184 ( V_14 , V_20 + V_190 , - V_180 ) ;
F_166 ( & V_14 -> V_195 ) ;
F_132 ( & V_213 ) ;
F_134 ( & V_213 , true ) ;
F_193 ( V_14 -> V_210 , V_180 , V_161 ,
V_216 , V_217 , V_2 -> V_162 , V_190 ) ;
}
static bool F_194 ( struct V_22 * V_22 , bool V_190 ,
struct V_1 * V_2 , bool V_221 )
{
unsigned long V_222 ;
unsigned long V_191 , V_223 ;
enum V_23 V_224 = V_190 * V_225 ;
enum V_23 V_226 = V_190 * V_225 + V_220 ;
unsigned long V_227 ;
if ( ! V_190 && ! V_228 )
return false ;
V_191 = F_11 ( V_22 , V_224 , V_2 -> V_187 ) ;
V_223 = F_11 ( V_22 , V_226 , V_2 -> V_187 ) ;
V_227 = ( V_191 + V_223 ) >> ( 30 - V_229 ) ;
if ( V_227 )
V_222 = F_195 ( 10 * V_227 ) ;
else
V_222 = 1 ;
if ( V_221 )
F_196 ( F_15 ( V_22 ) -> V_210 ,
V_2 -> V_187 ,
F_11 ( V_22 , V_224 , V_29 ) , V_191 ,
F_11 ( V_22 , V_226 , V_29 ) , V_223 ,
V_222 , V_190 ) ;
return V_191 * V_222 < V_223 ;
}
static unsigned long F_197 ( enum V_23 V_24 , unsigned long V_62 ,
struct V_22 * V_22 , struct V_1 * V_2 )
{
if ( F_171 ( V_24 ) ) {
if ( F_194 ( V_22 , F_172 ( V_24 ) , V_2 , true ) )
F_192 ( V_62 , V_22 , V_2 , V_24 ) ;
return 0 ;
}
return F_180 ( V_62 , V_22 , V_2 , V_24 ) ;
}
static void F_198 ( struct V_22 * V_22 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_230 )
{
int V_231 = F_199 ( V_5 ) ;
struct V_193 * V_123 = & V_22 -> V_123 ;
T_8 V_232 [ 2 ] ;
T_8 V_233 = 0 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
unsigned long V_234 , V_235 ;
enum V_236 V_236 ;
unsigned long V_237 , V_190 ;
bool V_238 = false ;
unsigned long V_239 , V_240 ;
enum V_23 V_24 ;
bool V_241 ;
int V_242 ;
if ( F_116 () ) {
if ( ! F_10 ( V_14 ) )
V_238 = true ;
if ( ! F_40 ( V_5 ) )
V_238 = true ;
}
if ( ! F_1 ( V_2 ) )
V_238 = true ;
if ( ! V_2 -> V_243 || F_200 ( V_5 ) <= 0 ) {
V_236 = V_244 ;
goto V_67;
}
if ( ! F_1 ( V_2 ) && ! V_231 ) {
V_236 = V_244 ;
goto V_67;
}
if ( ! V_2 -> V_162 && V_231 ) {
V_236 = V_245 ;
goto V_67;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_246 ;
unsigned long V_247 ;
int V_248 ;
unsigned long V_249 = 0 ;
V_247 = F_201 ( V_14 -> V_210 , V_250 ) ;
V_246 = F_14 ( V_14 , V_15 ) +
F_14 ( V_14 , V_16 ) ;
for ( V_248 = 0 ; V_248 < V_29 ; V_248 ++ ) {
struct V_7 * V_7 = & V_14 -> V_30 [ V_248 ] ;
if ( ! F_16 ( V_7 ) )
continue;
V_249 += F_202 ( V_7 ) ;
}
if ( F_74 ( V_246 + V_247 <= V_249 ) ) {
V_236 = V_251 ;
goto V_67;
}
}
if ( ! F_194 ( V_22 , true , V_2 , false ) &&
F_11 ( V_22 , V_252 , V_2 -> V_187 ) >> V_2 -> V_162 ) {
V_236 = V_244 ;
goto V_67;
}
V_236 = V_253 ;
V_234 = V_231 ;
V_235 = 200 - V_234 ;
V_237 = F_11 ( V_22 , V_254 , V_29 ) +
F_11 ( V_22 , V_255 , V_29 ) ;
V_190 = F_11 ( V_22 , V_256 , V_29 ) +
F_11 ( V_22 , V_252 , V_29 ) ;
F_160 ( & V_14 -> V_195 ) ;
if ( F_74 ( V_123 -> V_202 [ 0 ] > V_237 / 4 ) ) {
V_123 -> V_202 [ 0 ] /= 2 ;
V_123 -> V_197 [ 0 ] /= 2 ;
}
if ( F_74 ( V_123 -> V_202 [ 1 ] > V_190 / 4 ) ) {
V_123 -> V_202 [ 1 ] /= 2 ;
V_123 -> V_197 [ 1 ] /= 2 ;
}
V_239 = V_234 * ( V_123 -> V_202 [ 0 ] + 1 ) ;
V_239 /= V_123 -> V_197 [ 0 ] + 1 ;
V_240 = V_235 * ( V_123 -> V_202 [ 1 ] + 1 ) ;
V_240 /= V_123 -> V_197 [ 1 ] + 1 ;
F_166 ( & V_14 -> V_195 ) ;
V_232 [ 0 ] = V_239 ;
V_232 [ 1 ] = V_240 ;
V_233 = V_239 + V_240 + 1 ;
V_67:
V_241 = false ;
for ( V_242 = 0 ; ! V_241 && V_242 < 2 ; V_242 ++ ) {
* V_230 = 0 ;
F_203 (lru) {
int V_190 = F_172 ( V_24 ) ;
unsigned long V_31 ;
unsigned long V_184 ;
V_31 = F_11 ( V_22 , V_24 , V_2 -> V_187 ) ;
V_184 = V_31 >> V_2 -> V_162 ;
if ( ! V_184 && V_242 && V_238 )
V_184 = F_19 ( V_31 , V_66 ) ;
switch ( V_236 ) {
case V_245 :
break;
case V_253 :
V_184 = F_204 ( V_184 * V_232 [ V_190 ] ,
V_233 ) ;
break;
case V_244 :
case V_251 :
if ( ( V_236 == V_244 ) != V_190 ) {
V_31 = 0 ;
V_184 = 0 ;
}
break;
default:
F_154 () ;
}
* V_230 += V_31 ;
V_8 [ V_24 ] = V_184 ;
V_241 |= ! ! V_184 ;
}
}
}
static void F_205 ( struct V_13 * V_14 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_230 )
{
struct V_22 * V_22 = F_206 ( V_14 , V_5 ) ;
unsigned long V_8 [ V_257 ] ;
unsigned long V_258 [ V_257 ] ;
unsigned long V_62 ;
enum V_23 V_24 ;
unsigned long V_132 = 0 ;
unsigned long V_259 = V_2 -> V_259 ;
struct V_260 V_261 ;
bool V_262 ;
F_198 ( V_22 , V_5 , V_2 , V_8 , V_230 ) ;
memcpy ( V_258 , V_8 , sizeof( V_8 ) ) ;
V_262 = ( F_1 ( V_2 ) && ! F_116 () &&
V_2 -> V_162 == V_163 ) ;
F_207 ( & V_261 ) ;
while ( V_8 [ V_255 ] || V_8 [ V_256 ] ||
V_8 [ V_252 ] ) {
unsigned long V_263 , V_264 , V_265 ;
unsigned long V_45 ;
F_203 (lru) {
if ( V_8 [ V_24 ] ) {
V_62 = F_19 ( V_8 [ V_24 ] , V_66 ) ;
V_8 [ V_24 ] -= V_62 ;
V_132 += F_197 ( V_24 , V_62 ,
V_22 , V_2 ) ;
}
}
F_34 () ;
if ( V_132 < V_259 || V_262 )
continue;
V_264 = V_8 [ V_252 ] + V_8 [ V_256 ] ;
V_263 = V_8 [ V_255 ] + V_8 [ V_254 ] ;
if ( ! V_264 || ! V_263 )
break;
if ( V_264 > V_263 ) {
unsigned long V_266 = V_258 [ V_255 ] +
V_258 [ V_254 ] + 1 ;
V_24 = V_267 ;
V_265 = V_263 * 100 / V_266 ;
} else {
unsigned long V_266 = V_258 [ V_252 ] +
V_258 [ V_256 ] + 1 ;
V_24 = V_225 ;
V_265 = V_264 * 100 / V_266 ;
}
V_8 [ V_24 ] = 0 ;
V_8 [ V_24 + V_220 ] = 0 ;
V_24 = ( V_24 == V_225 ) ? V_267 : V_225 ;
V_45 = V_258 [ V_24 ] - V_8 [ V_24 ] ;
V_8 [ V_24 ] = V_258 [ V_24 ] * ( 100 - V_265 ) / 100 ;
V_8 [ V_24 ] -= F_19 ( V_8 [ V_24 ] , V_45 ) ;
V_24 += V_220 ;
V_45 = V_258 [ V_24 ] - V_8 [ V_24 ] ;
V_8 [ V_24 ] = V_258 [ V_24 ] * ( 100 - V_265 ) / 100 ;
V_8 [ V_24 ] -= F_19 ( V_8 [ V_24 ] , V_45 ) ;
V_262 = true ;
}
F_208 ( & V_261 ) ;
V_2 -> V_132 += V_132 ;
if ( F_194 ( V_22 , false , V_2 , true ) )
F_192 ( V_66 , V_22 ,
V_2 , V_254 ) ;
}
static bool F_209 ( struct V_1 * V_2 )
{
if ( F_210 ( V_268 ) && V_2 -> V_189 &&
( V_2 -> V_189 > V_269 ||
V_2 -> V_162 < V_163 - 2 ) )
return true ;
return false ;
}
static inline bool F_211 ( struct V_13 * V_14 ,
unsigned long V_132 ,
unsigned long V_45 ,
struct V_1 * V_2 )
{
unsigned long V_270 ;
unsigned long V_271 ;
int V_248 ;
if ( ! F_209 ( V_2 ) )
return false ;
if ( V_2 -> V_65 & V_272 ) {
if ( ! V_132 && ! V_45 )
return false ;
} else {
if ( ! V_132 )
return false ;
}
V_270 = F_212 ( V_2 -> V_189 ) ;
V_271 = F_14 ( V_14 , V_16 ) ;
if ( F_7 () > 0 )
V_271 += F_14 ( V_14 , V_19 ) ;
if ( V_2 -> V_132 < V_270 &&
V_271 > V_270 )
return true ;
for ( V_248 = 0 ; V_248 <= V_2 -> V_187 ; V_248 ++ ) {
struct V_7 * V_7 = & V_14 -> V_30 [ V_248 ] ;
if ( ! F_16 ( V_7 ) )
continue;
switch ( F_213 ( V_7 , V_2 -> V_189 , 0 , V_2 -> V_187 ) ) {
case V_273 :
case V_274 :
return false ;
default:
;
}
}
return true ;
}
static bool F_214 ( T_9 * V_14 , struct V_1 * V_2 )
{
struct V_275 * V_275 = V_71 -> V_275 ;
unsigned long V_132 , V_45 ;
bool V_276 = false ;
do {
struct V_4 * V_277 = V_2 -> V_3 ;
struct V_278 V_279 = {
. V_14 = V_14 ,
. V_162 = V_2 -> V_162 ,
} ;
unsigned long V_280 = 0 ;
struct V_4 * V_5 ;
V_132 = V_2 -> V_132 ;
V_45 = V_2 -> V_45 ;
V_5 = F_45 ( V_277 , NULL , & V_279 ) ;
do {
unsigned long V_230 ;
unsigned long V_96 ;
unsigned long V_56 ;
if ( F_215 ( V_277 , V_5 ) ) {
if ( ! V_2 -> V_281 )
continue;
F_216 ( V_5 , V_282 , 1 ) ;
}
V_96 = V_2 -> V_132 ;
V_56 = V_2 -> V_45 ;
F_205 ( V_14 , V_5 , V_2 , & V_230 ) ;
V_280 += V_230 ;
if ( V_5 )
F_38 ( V_2 -> V_65 , V_14 -> V_210 ,
V_5 , V_2 -> V_45 - V_56 ,
V_230 ) ;
F_217 ( V_2 -> V_65 , V_5 , false ,
V_2 -> V_45 - V_56 ,
V_2 -> V_132 - V_96 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_132 >= V_2 -> V_259 ) {
F_218 ( V_277 , V_5 ) ;
break;
}
} while ( ( V_5 = F_45 ( V_277 , V_5 , & V_279 ) ) );
if ( F_1 ( V_2 ) )
F_38 ( V_2 -> V_65 , V_14 -> V_210 , NULL ,
V_2 -> V_45 - V_45 ,
V_280 ) ;
if ( V_275 ) {
V_2 -> V_132 += V_275 -> V_283 ;
V_275 -> V_283 = 0 ;
}
F_217 ( V_2 -> V_65 , V_2 -> V_3 , true ,
V_2 -> V_45 - V_45 ,
V_2 -> V_132 - V_132 ) ;
if ( V_2 -> V_132 - V_132 )
V_276 = true ;
} while ( F_211 ( V_14 , V_2 -> V_132 - V_132 ,
V_2 -> V_45 - V_45 , V_2 ) );
return V_276 ;
}
static inline bool F_219 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
unsigned long V_284 ;
enum V_285 V_286 ;
V_286 = F_213 ( V_7 , V_2 -> V_189 , 0 , V_2 -> V_187 ) ;
if ( V_286 == V_273 )
return true ;
if ( V_286 == V_287 )
return false ;
V_284 = F_202 ( V_7 ) + F_212 ( V_2 -> V_189 ) ;
return F_220 ( V_7 , 0 , V_284 , V_2 -> V_187 ) ;
}
static void F_221 ( struct V_288 * V_288 , struct V_1 * V_2 )
{
struct V_289 * V_248 ;
struct V_7 * V_7 ;
unsigned long V_290 ;
unsigned long V_291 ;
T_2 V_292 ;
T_9 * V_293 = NULL ;
V_292 = V_2 -> V_65 ;
if ( V_219 ) {
V_2 -> V_65 |= V_294 ;
V_2 -> V_187 = F_222 ( V_2 -> V_65 ) ;
}
F_223 (zone, z, zonelist,
sc->reclaim_idx, sc->nodemask) {
if ( F_1 ( V_2 ) ) {
if ( ! F_224 ( V_7 ,
V_38 | V_295 ) )
continue;
if ( V_2 -> V_162 != V_163 &&
! F_10 ( V_7 -> V_166 ) )
continue;
if ( F_210 ( V_268 ) &&
V_2 -> V_189 > V_269 &&
F_219 ( V_7 , V_2 ) ) {
V_2 -> F_219 = true ;
continue;
}
if ( V_7 -> V_166 == V_293 )
continue;
V_291 = 0 ;
V_290 = F_225 ( V_7 -> V_166 ,
V_2 -> V_189 , V_2 -> V_65 ,
& V_291 ) ;
V_2 -> V_132 += V_290 ;
V_2 -> V_45 += V_291 ;
}
if ( V_7 -> V_166 == V_293 )
continue;
V_293 = V_7 -> V_166 ;
F_214 ( V_7 -> V_166 , V_2 ) ;
}
V_2 -> V_65 = V_292 ;
}
static unsigned long F_226 ( struct V_288 * V_288 ,
struct V_1 * V_2 )
{
int V_296 = V_2 -> V_162 ;
V_297:
F_227 () ;
if ( F_1 ( V_2 ) )
F_155 ( V_298 , V_2 -> V_187 , 1 ) ;
do {
F_228 ( V_2 -> V_65 , V_2 -> V_3 ,
V_2 -> V_162 ) ;
V_2 -> V_45 = 0 ;
F_221 ( V_288 , V_2 ) ;
if ( V_2 -> V_132 >= V_2 -> V_259 )
break;
if ( V_2 -> F_219 )
break;
if ( V_2 -> V_162 < V_163 - 2 )
V_2 -> V_157 = 1 ;
} while ( -- V_2 -> V_162 >= 0 );
F_229 () ;
if ( V_2 -> V_132 )
return V_2 -> V_132 ;
if ( V_2 -> F_219 )
return 1 ;
if ( ! V_2 -> V_281 ) {
V_2 -> V_162 = V_296 ;
V_2 -> V_281 = 1 ;
goto V_297;
}
return 0 ;
}
static bool F_230 ( T_9 * V_14 )
{
struct V_7 * V_7 ;
unsigned long V_299 = 0 ;
unsigned long V_127 = 0 ;
int V_300 ;
bool V_301 ;
for ( V_300 = 0 ; V_300 <= V_302 ; V_300 ++ ) {
V_7 = & V_14 -> V_30 [ V_300 ] ;
if ( ! F_16 ( V_7 ) ||
F_8 ( V_14 ) == 0 )
continue;
V_299 += F_231 ( V_7 ) ;
V_127 += F_18 ( V_7 , V_250 ) ;
}
if ( ! V_299 )
return true ;
V_301 = V_127 > V_299 / 2 ;
if ( ! V_301 && F_232 ( & V_14 -> V_303 ) ) {
V_14 -> V_304 = F_19 ( V_14 -> V_304 ,
(enum V_305 ) V_302 ) ;
F_233 ( & V_14 -> V_303 ) ;
}
return V_301 ;
}
static bool F_234 ( T_2 V_65 , struct V_288 * V_288 ,
T_10 * V_306 )
{
struct V_289 * V_248 ;
struct V_7 * V_7 ;
T_9 * V_14 = NULL ;
if ( V_71 -> V_35 & V_307 )
goto V_67;
if ( F_182 ( V_71 ) )
goto V_67;
F_223 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( V_25 ( V_7 ) > V_302 )
continue;
V_14 = V_7 -> V_166 ;
if ( F_230 ( V_14 ) )
goto V_67;
break;
}
if ( ! V_14 )
goto V_67;
F_101 ( V_308 ) ;
if ( ! ( V_65 & V_145 ) ) {
F_235 ( V_14 -> V_309 ,
F_230 ( V_14 ) , V_201 ) ;
goto V_310;
}
F_236 ( V_7 -> V_166 -> V_309 ,
F_230 ( V_14 ) ) ;
V_310:
if ( F_182 ( V_71 ) )
return true ;
V_67:
return false ;
}
unsigned long F_237 ( struct V_288 * V_288 , int V_189 ,
T_2 V_65 , T_10 * V_306 )
{
unsigned long V_132 ;
struct V_1 V_2 = {
. V_259 = V_66 ,
. V_65 = ( V_65 = F_238 ( V_65 ) ) ,
. V_187 = F_222 ( V_65 ) ,
. V_189 = V_189 ,
. V_306 = V_306 ,
. V_162 = V_163 ,
. V_157 = ! V_311 ,
. V_143 = 1 ,
. V_243 = 1 ,
} ;
if ( F_234 ( V_65 , V_288 , V_306 ) )
return 1 ;
F_239 ( V_189 ,
V_2 . V_157 ,
V_65 ,
V_2 . V_187 ) ;
V_132 = F_226 ( V_288 , & V_2 ) ;
F_240 ( V_132 ) ;
return V_132 ;
}
unsigned long F_241 ( struct V_4 * V_5 ,
T_2 V_65 , bool V_312 ,
T_9 * V_14 ,
unsigned long * V_45 )
{
struct V_1 V_2 = {
. V_259 = V_66 ,
. V_3 = V_5 ,
. V_157 = ! V_311 ,
. V_143 = 1 ,
. V_187 = V_29 - 1 ,
. V_243 = ! V_312 ,
} ;
unsigned long V_230 ;
V_2 . V_65 = ( V_65 & V_313 ) |
( V_314 & ~ V_313 ) ;
F_242 ( V_2 . V_189 ,
V_2 . V_157 ,
V_2 . V_65 ,
V_2 . V_187 ) ;
F_205 ( V_14 , V_5 , & V_2 , & V_230 ) ;
F_243 ( V_2 . V_132 ) ;
* V_45 = V_2 . V_45 ;
return V_2 . V_132 ;
}
unsigned long F_244 ( struct V_4 * V_5 ,
unsigned long V_185 ,
T_2 V_65 ,
bool V_243 )
{
struct V_288 * V_288 ;
unsigned long V_132 ;
int V_52 ;
struct V_1 V_2 = {
. V_259 = F_245 ( V_185 , V_66 ) ,
. V_65 = ( V_65 & V_313 ) |
( V_314 & ~ V_313 ) ,
. V_187 = V_29 - 1 ,
. V_3 = V_5 ,
. V_162 = V_163 ,
. V_157 = ! V_311 ,
. V_143 = 1 ,
. V_243 = V_243 ,
} ;
V_52 = F_246 ( V_5 ) ;
V_288 = & F_247 ( V_52 ) -> V_315 [ V_316 ] ;
F_248 ( 0 ,
V_2 . V_157 ,
V_2 . V_65 ,
V_2 . V_187 ) ;
V_71 -> V_35 |= V_317 ;
V_132 = F_226 ( V_288 , & V_2 ) ;
V_71 -> V_35 &= ~ V_317 ;
F_249 ( V_132 ) ;
return V_132 ;
}
static void F_250 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_228 )
return;
V_5 = F_45 ( NULL , NULL , NULL ) ;
do {
struct V_22 * V_22 = F_206 ( V_14 , V_5 ) ;
if ( F_194 ( V_22 , false , V_2 , true ) )
F_192 ( V_66 , V_22 ,
V_2 , V_254 ) ;
V_5 = F_45 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_251 ( struct V_7 * V_7 , int V_189 , int V_318 )
{
unsigned long V_319 = F_202 ( V_7 ) ;
if ( ! F_220 ( V_7 , V_189 , V_319 , V_318 ) )
return false ;
F_252 ( V_207 , & V_7 -> V_166 -> V_35 ) ;
F_252 ( V_155 , & V_7 -> V_166 -> V_35 ) ;
F_252 ( V_147 , & V_7 -> V_166 -> V_35 ) ;
return true ;
}
static bool F_253 ( T_9 * V_14 , int V_189 , int V_318 )
{
int V_300 ;
if ( F_232 ( & V_14 -> V_309 ) )
F_254 ( & V_14 -> V_309 ) ;
for ( V_300 = 0 ; V_300 <= V_318 ; V_300 ++ ) {
struct V_7 * V_7 = V_14 -> V_30 + V_300 ;
if ( ! F_16 ( V_7 ) )
continue;
if ( ! F_251 ( V_7 , V_189 , V_318 ) )
return false ;
}
return true ;
}
static bool F_255 ( T_9 * V_14 ,
struct V_1 * V_2 )
{
struct V_7 * V_7 ;
int V_248 ;
V_2 -> V_259 = 0 ;
for ( V_248 = 0 ; V_248 <= V_2 -> V_187 ; V_248 ++ ) {
V_7 = V_14 -> V_30 + V_248 ;
if ( ! F_16 ( V_7 ) )
continue;
V_2 -> V_259 += F_245 ( F_202 ( V_7 ) , V_66 ) ;
}
F_214 ( V_14 , V_2 ) ;
if ( V_2 -> V_189 && V_2 -> V_132 >= F_212 ( V_2 -> V_189 ) )
V_2 -> V_189 = 0 ;
return V_2 -> V_45 >= V_2 -> V_259 ;
}
static int F_256 ( T_9 * V_14 , int V_189 , int V_318 )
{
int V_300 ;
unsigned long V_290 ;
unsigned long V_291 ;
struct V_7 * V_7 ;
struct V_1 V_2 = {
. V_65 = V_38 ,
. V_189 = V_189 ,
. V_162 = V_163 ,
. V_157 = ! V_311 ,
. V_143 = 1 ,
. V_243 = 1 ,
} ;
F_101 ( V_320 ) ;
do {
bool V_321 = true ;
V_2 . V_132 = 0 ;
V_2 . V_187 = V_318 ;
if ( V_219 ) {
for ( V_300 = V_29 - 1 ; V_300 >= 0 ; V_300 -- ) {
V_7 = V_14 -> V_30 + V_300 ;
if ( ! F_16 ( V_7 ) )
continue;
V_2 . V_187 = V_300 ;
break;
}
}
for ( V_300 = V_318 ; V_300 >= 0 ; V_300 -- ) {
V_7 = V_14 -> V_30 + V_300 ;
if ( ! F_16 ( V_7 ) )
continue;
if ( F_251 ( V_7 , V_2 . V_189 , V_318 ) )
goto V_67;
}
F_250 ( V_14 , & V_2 ) ;
if ( V_2 . V_162 < V_163 - 2 || ! F_10 ( V_14 ) )
V_2 . V_157 = 1 ;
V_2 . V_45 = 0 ;
V_291 = 0 ;
V_290 = F_225 ( V_14 , V_2 . V_189 ,
V_2 . V_65 , & V_291 ) ;
V_2 . V_132 += V_290 ;
if ( F_255 ( V_14 , & V_2 ) )
V_321 = false ;
if ( F_232 ( & V_14 -> V_309 ) &&
F_230 ( V_14 ) )
F_254 ( & V_14 -> V_309 ) ;
if ( F_257 () || F_258 () )
break;
if ( V_321 || ! V_2 . V_132 )
V_2 . V_162 -- ;
} while ( V_2 . V_162 >= 1 );
V_67:
return V_2 . V_189 ;
}
static void F_259 ( T_9 * V_14 , int V_322 , int V_323 ,
unsigned int V_318 )
{
long V_324 = 0 ;
F_260 ( V_325 ) ;
if ( F_261 ( V_71 ) || F_258 () )
return;
F_262 ( & V_14 -> V_303 , & V_325 , V_326 ) ;
if ( F_253 ( V_14 , V_323 , V_318 ) ) {
F_263 ( V_14 ) ;
F_264 ( V_14 , V_322 , V_318 ) ;
V_324 = F_265 ( V_201 / 10 ) ;
if ( V_324 ) {
V_14 -> V_304 = F_245 ( V_14 -> V_304 , V_318 ) ;
V_14 -> V_327 = F_245 ( V_14 -> V_327 , V_323 ) ;
}
F_266 ( & V_14 -> V_303 , & V_325 ) ;
F_262 ( & V_14 -> V_303 , & V_325 , V_326 ) ;
}
if ( ! V_324 &&
F_253 ( V_14 , V_323 , V_318 ) ) {
F_267 ( V_14 -> V_210 ) ;
F_268 ( V_14 , V_328 ) ;
if ( ! F_258 () )
F_269 () ;
F_268 ( V_14 , V_329 ) ;
} else {
if ( V_324 )
F_101 ( V_330 ) ;
else
F_101 ( V_331 ) ;
}
F_266 ( & V_14 -> V_303 , & V_325 ) ;
}
static int F_270 ( void * V_332 )
{
unsigned int V_322 , V_323 , V_318 ;
T_9 * V_14 = ( T_9 * ) V_332 ;
struct V_333 * V_334 = V_71 ;
struct V_275 V_275 = {
. V_283 = 0 ,
} ;
const struct V_335 * V_335 = F_271 ( V_14 -> V_210 ) ;
F_272 ( V_38 ) ;
if ( ! F_273 ( V_335 ) )
F_274 ( V_334 , V_335 ) ;
V_71 -> V_275 = & V_275 ;
V_334 -> V_35 |= V_317 | V_72 | V_336 ;
F_275 () ;
V_14 -> V_327 = V_322 = V_323 = 0 ;
V_14 -> V_304 = V_318 = 0 ;
for ( ; ; ) {
bool V_61 ;
V_337:
F_259 ( V_14 , V_322 , V_323 ,
V_318 ) ;
V_322 = V_323 = V_14 -> V_327 ;
V_318 = V_14 -> V_304 ;
V_14 -> V_327 = 0 ;
V_14 -> V_304 = 0 ;
V_61 = F_257 () ;
if ( F_258 () )
break;
if ( V_61 )
continue;
F_276 ( V_14 -> V_210 , V_318 ,
V_322 ) ;
V_323 = F_256 ( V_14 , V_322 , V_318 ) ;
if ( V_323 < V_322 )
goto V_337;
V_322 = V_323 = V_14 -> V_327 ;
V_318 = V_14 -> V_304 ;
}
V_334 -> V_35 &= ~ ( V_317 | V_72 | V_336 ) ;
V_71 -> V_275 = NULL ;
F_277 () ;
return 0 ;
}
void F_278 ( struct V_7 * V_7 , int V_189 , enum V_305 V_318 )
{
T_9 * V_14 ;
int V_248 ;
if ( ! F_16 ( V_7 ) )
return;
if ( ! F_224 ( V_7 , V_38 | V_295 ) )
return;
V_14 = V_7 -> V_166 ;
V_14 -> V_304 = F_245 ( V_14 -> V_304 , V_318 ) ;
V_14 -> V_327 = F_245 ( V_14 -> V_327 , V_189 ) ;
if ( ! F_232 ( & V_14 -> V_303 ) )
return;
for ( V_248 = 0 ; V_248 <= V_318 ; V_248 ++ ) {
V_7 = V_14 -> V_30 + V_248 ;
if ( ! F_16 ( V_7 ) )
continue;
if ( F_251 ( V_7 , V_189 , V_318 ) )
return;
}
F_279 ( V_14 -> V_210 , V_25 ( V_7 ) , V_189 ) ;
F_233 ( & V_14 -> V_303 ) ;
}
unsigned long F_280 ( unsigned long V_259 )
{
struct V_275 V_275 ;
struct V_1 V_2 = {
. V_259 = V_259 ,
. V_65 = V_314 ,
. V_187 = V_29 - 1 ,
. V_162 = V_163 ,
. V_157 = 1 ,
. V_143 = 1 ,
. V_243 = 1 ,
. V_209 = 1 ,
} ;
struct V_288 * V_288 = F_281 ( F_282 () , V_2 . V_65 ) ;
struct V_333 * V_332 = V_71 ;
unsigned long V_132 ;
V_332 -> V_35 |= V_317 ;
F_272 ( V_2 . V_65 ) ;
V_275 . V_283 = 0 ;
V_332 -> V_275 = & V_275 ;
V_132 = F_226 ( V_288 , & V_2 ) ;
V_332 -> V_275 = NULL ;
F_277 () ;
V_332 -> V_35 &= ~ V_317 ;
return V_132 ;
}
static int F_283 ( unsigned int V_338 )
{
int V_52 ;
F_284 (nid, N_MEMORY) {
T_9 * V_14 = F_247 ( V_52 ) ;
const struct V_335 * V_339 ;
V_339 = F_271 ( V_14 -> V_210 ) ;
if ( F_285 ( V_340 , V_339 ) < V_341 )
F_274 ( V_14 -> F_270 , V_339 ) ;
}
return 0 ;
}
int F_286 ( int V_52 )
{
T_9 * V_14 = F_247 ( V_52 ) ;
int V_61 = 0 ;
if ( V_14 -> F_270 )
return 0 ;
V_14 -> F_270 = F_287 ( F_270 , V_14 , L_4 , V_52 ) ;
if ( F_288 ( V_14 -> F_270 ) ) {
F_70 ( V_342 == V_343 ) ;
F_31 ( L_5 , V_52 ) ;
V_61 = F_289 ( V_14 -> F_270 ) ;
V_14 -> F_270 = NULL ;
}
return V_61 ;
}
void F_290 ( int V_52 )
{
struct V_333 * F_270 = F_247 ( V_52 ) -> F_270 ;
if ( F_270 ) {
F_291 ( F_270 ) ;
F_247 ( V_52 ) -> F_270 = NULL ;
}
}
static int T_11 F_292 ( void )
{
int V_52 , V_61 ;
F_293 () ;
F_284 (nid, N_MEMORY)
F_286 ( V_52 ) ;
V_61 = F_294 ( V_344 ,
L_6 , F_283 ,
NULL ) ;
F_295 ( V_61 < 0 ) ;
return 0 ;
}
static inline unsigned long F_296 ( struct V_13 * V_14 )
{
unsigned long V_345 = F_14 ( V_14 , V_346 ) ;
unsigned long V_347 = F_14 ( V_14 , V_16 ) +
F_14 ( V_14 , V_15 ) ;
return ( V_347 > V_345 ) ? ( V_347 - V_345 ) : 0 ;
}
static unsigned long F_297 ( struct V_13 * V_14 )
{
unsigned long V_348 ;
unsigned long V_48 = 0 ;
if ( V_349 & V_350 )
V_348 = F_14 ( V_14 , V_351 ) ;
else
V_348 = F_296 ( V_14 ) ;
if ( ! ( V_349 & V_352 ) )
V_48 += F_14 ( V_14 , V_353 ) ;
if ( F_74 ( V_48 > V_348 ) )
V_48 = V_348 ;
return V_348 - V_48 ;
}
static int F_298 ( struct V_13 * V_14 , T_2 V_65 , unsigned int V_189 )
{
const unsigned long V_185 = 1 << V_189 ;
struct V_333 * V_332 = V_71 ;
struct V_275 V_275 ;
int V_318 = F_222 ( V_65 ) ;
struct V_1 V_2 = {
. V_259 = F_245 ( V_185 , V_66 ) ,
. V_65 = ( V_65 = F_238 ( V_65 ) ) ,
. V_189 = V_189 ,
. V_162 = V_354 ,
. V_157 = ! ! ( V_349 & V_352 ) ,
. V_143 = ! ! ( V_349 & V_350 ) ,
. V_243 = 1 ,
. V_187 = V_318 ,
} ;
F_34 () ;
V_332 -> V_35 |= V_317 | V_72 ;
F_272 ( V_65 ) ;
V_275 . V_283 = 0 ;
V_332 -> V_275 = & V_275 ;
if ( F_297 ( V_14 ) > V_14 -> V_355 ) {
do {
F_214 ( V_14 , & V_2 ) ;
} while ( V_2 . V_132 < V_185 && -- V_2 . V_162 >= 0 );
}
V_332 -> V_275 = NULL ;
V_71 -> V_35 &= ~ ( V_317 | V_72 ) ;
F_277 () ;
return V_2 . V_132 >= V_185 ;
}
int F_299 ( struct V_13 * V_14 , T_2 V_65 , unsigned int V_189 )
{
int V_61 ;
if ( F_297 ( V_14 ) <= V_14 -> V_355 &&
F_201 ( V_14 -> V_210 , V_356 ) <= V_14 -> V_357 )
return V_358 ;
if ( ! F_10 ( V_14 ) )
return V_358 ;
if ( ! F_300 ( V_65 ) || ( V_71 -> V_35 & V_317 ) )
return V_359 ;
if ( F_301 ( V_14 -> V_210 , V_360 ) && V_14 -> V_210 != F_282 () )
return V_359 ;
if ( F_302 ( V_361 , & V_14 -> V_35 ) )
return V_359 ;
V_61 = F_298 ( V_14 , V_65 , V_189 ) ;
F_252 ( V_361 , & V_14 -> V_35 ) ;
if ( ! V_61 )
F_101 ( V_362 ) ;
return V_61 ;
}
int F_95 ( struct V_69 * V_69 )
{
return ! F_303 ( F_56 ( V_69 ) ) && ! F_304 ( V_69 ) ;
}
void F_305 ( struct V_69 * * V_363 , int V_185 )
{
struct V_22 * V_22 ;
struct V_13 * V_14 = NULL ;
int V_364 = 0 ;
int V_365 = 0 ;
int V_300 ;
for ( V_300 = 0 ; V_300 < V_185 ; V_300 ++ ) {
struct V_69 * V_69 = V_363 [ V_300 ] ;
struct V_13 * V_366 = F_306 ( V_69 ) ;
V_364 ++ ;
if ( V_366 != V_14 ) {
if ( V_14 )
F_166 ( & V_14 -> V_195 ) ;
V_14 = V_366 ;
F_160 ( & V_14 -> V_195 ) ;
}
V_22 = F_162 ( V_69 , V_14 ) ;
if ( ! F_93 ( V_69 ) || ! F_91 ( V_69 ) )
continue;
if ( F_95 ( V_69 ) ) {
enum V_23 V_24 = F_307 ( V_69 ) ;
F_92 ( F_113 ( V_69 ) , V_69 ) ;
F_94 ( V_69 ) ;
F_165 ( V_69 , V_22 , V_367 ) ;
F_170 ( V_69 , V_22 , V_24 ) ;
V_365 ++ ;
}
}
if ( V_14 ) {
F_185 ( V_105 , V_365 ) ;
F_185 ( V_368 , V_364 ) ;
F_166 ( & V_14 -> V_195 ) ;
}
}
