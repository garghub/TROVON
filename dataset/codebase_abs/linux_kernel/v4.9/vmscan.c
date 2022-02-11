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
unsigned long F_11 ( struct V_22 * V_22 , enum V_23 V_24 )
{
if ( ! F_12 () )
return F_13 ( V_22 , V_24 ) ;
return F_14 ( F_15 ( V_22 ) , V_25 + V_24 ) ;
}
int F_16 ( struct V_26 * V_26 )
{
T_1 V_27 = sizeof( * V_26 -> V_28 ) ;
if ( V_26 -> V_29 & V_30 )
V_27 *= V_31 ;
V_26 -> V_28 = F_17 ( V_27 , V_32 ) ;
if ( ! V_26 -> V_28 )
return - V_33 ;
F_18 ( & V_34 ) ;
F_19 ( & V_26 -> V_35 , & V_36 ) ;
F_20 ( & V_34 ) ;
return 0 ;
}
void F_21 ( struct V_26 * V_26 )
{
F_18 ( & V_34 ) ;
F_22 ( & V_26 -> V_35 ) ;
F_20 ( & V_34 ) ;
F_23 ( V_26 -> V_28 ) ;
}
static unsigned long F_24 ( struct V_37 * V_38 ,
struct V_26 * V_26 ,
unsigned long V_39 ,
unsigned long V_40 )
{
unsigned long V_41 = 0 ;
unsigned long long V_42 ;
long V_43 ;
long V_44 ;
long V_8 ;
long V_45 ;
int V_46 = V_38 -> V_46 ;
long V_47 = V_26 -> V_48 ? V_26 -> V_48
: V_49 ;
V_44 = V_26 -> V_50 ( V_26 , V_38 ) ;
if ( V_44 == 0 )
return 0 ;
V_8 = F_25 ( & V_26 -> V_28 [ V_46 ] , 0 ) ;
V_43 = V_8 ;
V_42 = ( 4 * V_39 ) / V_26 -> V_51 ;
V_42 *= V_44 ;
F_26 ( V_42 , V_40 + 1 ) ;
V_43 += V_42 ;
if ( V_43 < 0 ) {
F_27 ( L_1 ,
V_26 -> V_52 , V_43 ) ;
V_43 = V_44 ;
}
if ( V_42 < V_44 / 4 )
V_43 = F_28 ( V_43 , V_44 / 2 ) ;
if ( V_43 > V_44 * 2 )
V_43 = V_44 * 2 ;
F_29 ( V_26 , V_38 , V_8 ,
V_39 , V_40 ,
V_44 , V_42 , V_43 ) ;
while ( V_43 >= V_47 ||
V_43 >= V_44 ) {
unsigned long V_53 ;
unsigned long V_54 = F_28 ( V_47 , V_43 ) ;
V_38 -> V_54 = V_54 ;
V_53 = V_26 -> V_52 ( V_26 , V_38 ) ;
if ( V_53 == V_55 )
break;
V_41 += V_53 ;
F_30 ( V_56 , V_54 ) ;
V_43 -= V_54 ;
F_31 () ;
}
if ( V_43 > 0 )
V_45 = F_32 ( V_43 ,
& V_26 -> V_28 [ V_46 ] ) ;
else
V_45 = F_33 ( & V_26 -> V_28 [ V_46 ] ) ;
F_34 ( V_26 , V_46 , V_41 , V_8 , V_45 , V_43 ) ;
return V_41 ;
}
static unsigned long F_35 ( T_2 V_57 , int V_46 ,
struct V_4 * V_5 ,
unsigned long V_39 ,
unsigned long V_40 )
{
struct V_26 * V_26 ;
unsigned long V_41 = 0 ;
if ( V_5 && ( ! F_36 () || ! F_37 ( V_5 ) ) )
return 0 ;
if ( V_39 == 0 )
V_39 = V_58 ;
if ( ! F_38 ( & V_34 ) ) {
V_41 = 1 ;
goto V_59;
}
F_39 (shrinker, &shrinker_list, list) {
struct V_37 V_2 = {
. V_57 = V_57 ,
. V_46 = V_46 ,
. V_5 = V_5 ,
} ;
if ( F_36 () &&
! ! V_5 != ! ! ( V_26 -> V_29 & V_60 ) )
continue;
if ( ! ( V_26 -> V_29 & V_30 ) )
V_2 . V_46 = 0 ;
V_41 += F_24 ( & V_2 , V_26 , V_39 , V_40 ) ;
}
F_40 ( & V_34 ) ;
V_59:
F_31 () ;
return V_41 ;
}
void F_41 ( int V_46 )
{
unsigned long V_41 ;
do {
struct V_4 * V_5 = NULL ;
V_41 = 0 ;
do {
V_41 += F_35 ( V_32 , V_46 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_42 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_41 > 10 );
}
void F_43 ( void )
{
int V_46 ;
F_44 (nid)
F_41 ( V_46 ) ;
}
static inline int F_45 ( struct V_61 * V_61 )
{
return F_46 ( V_61 ) - F_47 ( V_61 ) == 2 ;
}
static int F_48 ( struct V_62 * V_62 , struct V_1 * V_2 )
{
if ( V_63 -> V_29 & V_64 )
return 1 ;
if ( ! F_49 ( V_62 ) )
return 1 ;
if ( F_50 ( V_62 ) == V_63 -> V_65 )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_66 * V_67 ,
struct V_61 * V_61 , int error )
{
F_52 ( V_61 ) ;
if ( F_53 ( V_61 ) == V_67 )
F_54 ( V_67 , error ) ;
F_55 ( V_61 ) ;
}
static T_3 F_56 ( struct V_61 * V_61 , struct V_66 * V_67 ,
struct V_1 * V_2 )
{
if ( ! F_45 ( V_61 ) )
return V_68 ;
if ( ! V_67 ) {
if ( F_47 ( V_61 ) ) {
if ( F_57 ( V_61 ) ) {
F_58 ( V_61 ) ;
F_59 ( L_2 , V_69 ) ;
return V_70 ;
}
}
return V_68 ;
}
if ( V_67 -> V_71 -> V_72 == NULL )
return V_73 ;
if ( ! F_48 ( V_67 -> V_74 , V_2 ) )
return V_68 ;
if ( F_60 ( V_61 ) ) {
int V_75 ;
struct V_76 V_77 = {
. V_78 = V_79 ,
. V_80 = V_58 ,
. V_81 = 0 ,
. V_82 = V_83 ,
. V_84 = 1 ,
} ;
F_61 ( V_61 ) ;
V_75 = V_67 -> V_71 -> V_72 ( V_61 , & V_77 ) ;
if ( V_75 < 0 )
F_51 ( V_67 , V_61 , V_75 ) ;
if ( V_75 == V_85 ) {
F_62 ( V_61 ) ;
return V_73 ;
}
if ( ! F_63 ( V_61 ) ) {
F_62 ( V_61 ) ;
}
F_64 ( V_61 ) ;
F_65 ( V_61 , V_86 ) ;
return V_87 ;
}
return V_70 ;
}
static int F_66 ( struct V_66 * V_67 , struct V_61 * V_61 ,
bool V_88 )
{
unsigned long V_29 ;
F_67 ( ! F_68 ( V_61 ) ) ;
F_67 ( V_67 != F_53 ( V_61 ) ) ;
F_69 ( & V_67 -> V_89 , V_29 ) ;
if ( ! F_70 ( V_61 , 2 ) )
goto V_90;
if ( F_71 ( F_72 ( V_61 ) ) ) {
F_73 ( V_61 , 2 ) ;
goto V_90;
}
if ( F_74 ( V_61 ) ) {
T_4 V_91 = { . V_92 = F_75 (page) } ;
F_76 ( V_61 , V_91 ) ;
F_77 ( V_61 ) ;
F_78 ( & V_67 -> V_89 , V_29 ) ;
F_79 ( V_91 ) ;
} else {
void (* F_80)( struct V_61 * );
void * V_93 = NULL ;
F_80 = V_67 -> V_71 -> F_80 ;
if ( V_88 && F_81 ( V_61 ) &&
! F_82 ( V_67 ) && ! F_83 ( V_67 ) )
V_93 = F_84 ( V_67 , V_61 ) ;
F_85 ( V_61 , V_93 ) ;
F_78 ( & V_67 -> V_89 , V_29 ) ;
if ( F_80 != NULL )
F_80 ( V_61 ) ;
}
return 1 ;
V_90:
F_78 ( & V_67 -> V_89 , V_29 ) ;
return 0 ;
}
int F_86 ( struct V_66 * V_67 , struct V_61 * V_61 )
{
if ( F_66 ( V_67 , V_61 , false ) ) {
F_73 ( V_61 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_87 ( struct V_61 * V_61 )
{
bool V_94 ;
int V_95 = F_88 ( V_61 ) ;
F_89 ( F_90 ( V_61 ) , V_61 ) ;
V_96:
F_91 ( V_61 ) ;
if ( F_92 ( V_61 ) ) {
V_94 = false ;
F_93 ( V_61 ) ;
} else {
V_94 = true ;
F_94 ( V_61 ) ;
F_95 () ;
}
if ( V_94 && F_92 ( V_61 ) ) {
if ( ! F_96 ( V_61 ) ) {
F_97 ( V_61 ) ;
goto V_96;
}
}
if ( V_95 && ! V_94 )
F_98 ( V_97 ) ;
else if ( ! V_95 && V_94 )
F_98 ( V_98 ) ;
F_97 ( V_61 ) ;
}
static enum V_99 F_99 ( struct V_61 * V_61 ,
struct V_1 * V_2 )
{
int V_100 , V_101 ;
unsigned long V_102 ;
V_100 = F_100 ( V_61 , 1 , V_2 -> V_3 ,
& V_102 ) ;
V_101 = F_101 ( V_61 ) ;
if ( V_102 & V_103 )
return V_104 ;
if ( V_100 ) {
if ( F_102 ( V_61 ) )
return V_105 ;
F_103 ( V_61 ) ;
if ( V_101 || V_100 > 1 )
return V_105 ;
if ( V_102 & V_106 )
return V_105 ;
return V_107 ;
}
if ( V_101 && ! F_102 ( V_61 ) )
return V_108 ;
return V_104 ;
}
static void F_104 ( struct V_61 * V_61 ,
bool * V_109 , bool * V_110 )
{
struct V_66 * V_67 ;
if ( ! F_81 ( V_61 ) ) {
* V_109 = false ;
* V_110 = false ;
return;
}
* V_109 = F_72 ( V_61 ) ;
* V_110 = F_63 ( V_61 ) ;
if ( ! F_47 ( V_61 ) )
return;
V_67 = F_53 ( V_61 ) ;
if ( V_67 && V_67 -> V_71 -> V_111 )
V_67 -> V_71 -> V_111 ( V_61 , V_109 , V_110 ) ;
}
static unsigned long F_105 ( struct V_112 * V_113 ,
struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_114 V_114 ,
unsigned long * V_115 ,
unsigned long * V_116 ,
unsigned long * V_117 ,
unsigned long * V_118 ,
unsigned long * V_119 ,
bool V_120 )
{
F_106 ( V_121 ) ;
F_106 ( V_122 ) ;
int V_123 = 0 ;
unsigned long V_124 = 0 ;
unsigned long V_125 = 0 ;
unsigned long V_126 = 0 ;
unsigned long V_127 = 0 ;
unsigned long V_128 = 0 ;
unsigned long V_129 = 0 ;
F_31 () ;
while ( ! F_107 ( V_113 ) ) {
struct V_66 * V_67 ;
struct V_61 * V_61 ;
int V_130 ;
enum V_99 V_131 = V_108 ;
bool V_109 , V_110 ;
bool V_132 = false ;
int V_53 = V_133 ;
F_31 () ;
V_61 = F_108 ( V_113 ) ;
F_22 ( & V_61 -> V_24 ) ;
if ( ! F_109 ( V_61 ) )
goto V_134;
F_89 ( F_110 ( V_61 ) , V_61 ) ;
V_2 -> V_39 ++ ;
if ( F_71 ( ! F_92 ( V_61 ) ) )
goto V_135;
if ( ! V_2 -> V_136 && F_111 ( V_61 ) )
goto V_137;
if ( F_111 ( V_61 ) || F_74 ( V_61 ) )
V_2 -> V_39 ++ ;
V_130 = ( V_2 -> V_57 & V_138 ) ||
( F_74 ( V_61 ) && ( V_2 -> V_57 & V_139 ) ) ;
F_104 ( V_61 , & V_109 , & V_110 ) ;
if ( V_109 || V_110 )
V_125 ++ ;
if ( V_109 && ! V_110 )
V_124 ++ ;
V_67 = F_53 ( V_61 ) ;
if ( ( ( V_109 || V_110 ) && V_67 &&
F_49 ( V_67 -> V_74 ) ) ||
( V_110 && F_112 ( V_61 ) ) )
V_126 ++ ;
if ( F_63 ( V_61 ) ) {
if ( F_113 () &&
F_112 ( V_61 ) &&
F_114 ( V_140 , & V_14 -> V_29 ) ) {
V_129 ++ ;
goto V_137;
} else if ( F_2 ( V_2 ) ||
! F_112 ( V_61 ) || ! V_130 ) {
F_61 ( V_61 ) ;
V_128 ++ ;
goto V_137;
} else {
F_55 ( V_61 ) ;
F_115 ( V_61 ) ;
F_19 ( & V_61 -> V_24 , V_113 ) ;
continue;
}
}
if ( ! V_120 )
V_131 = F_99 ( V_61 , V_2 ) ;
switch ( V_131 ) {
case V_105 :
goto V_141;
case V_107 :
goto V_137;
case V_104 :
case V_108 :
;
}
if ( F_116 ( V_61 ) && ! F_74 ( V_61 ) ) {
if ( ! ( V_2 -> V_57 & V_139 ) )
goto V_137;
if ( ! F_117 ( V_61 , V_113 ) )
goto V_141;
V_132 = true ;
V_130 = 1 ;
V_67 = F_53 ( V_61 ) ;
} else if ( F_71 ( F_118 ( V_61 ) ) ) {
if ( F_119 ( V_61 , V_113 ) )
goto V_137;
}
F_89 ( F_118 ( V_61 ) , V_61 ) ;
if ( F_111 ( V_61 ) && V_67 ) {
switch ( V_53 = F_120 ( V_61 , V_132 ?
( V_114 | V_142 | V_143 ) :
( V_114 | V_142 ) ) ) {
case V_144 :
goto V_141;
case V_145 :
goto V_137;
case V_146 :
goto V_135;
case V_147 :
goto V_132;
case V_133 :
;
}
}
if ( F_72 ( V_61 ) ) {
if ( F_81 ( V_61 ) &&
( ! F_113 () ||
! F_114 ( V_148 , & V_14 -> V_29 ) ) ) {
F_65 ( V_61 , V_149 ) ;
F_61 ( V_61 ) ;
goto V_137;
}
if ( V_131 == V_108 )
goto V_137;
if ( ! V_130 )
goto V_137;
if ( ! V_2 -> V_150 )
goto V_137;
F_121 () ;
switch ( F_56 ( V_61 , V_67 , V_2 ) ) {
case V_68 :
goto V_137;
case V_73 :
goto V_141;
case V_87 :
if ( F_63 ( V_61 ) )
goto V_134;
if ( F_72 ( V_61 ) )
goto V_134;
if ( ! F_109 ( V_61 ) )
goto V_134;
if ( F_72 ( V_61 ) || F_63 ( V_61 ) )
goto V_137;
V_67 = F_53 ( V_61 ) ;
case V_70 :
;
}
}
if ( F_47 ( V_61 ) ) {
if ( ! F_122 ( V_61 , V_2 -> V_57 ) )
goto V_141;
if ( ! V_67 && F_46 ( V_61 ) == 1 ) {
F_55 ( V_61 ) ;
if ( F_123 ( V_61 ) )
goto V_151;
else {
V_127 ++ ;
continue;
}
}
}
V_132:
if ( ! V_67 || ! F_66 ( V_67 , V_61 , true ) )
goto V_137;
F_124 ( V_61 ) ;
V_151:
if ( V_53 == V_147 )
F_98 ( V_152 ) ;
V_127 ++ ;
F_125 ( & V_61 -> V_24 , & V_122 ) ;
continue;
V_135:
if ( F_74 ( V_61 ) )
F_126 ( V_61 ) ;
F_55 ( V_61 ) ;
F_125 ( & V_61 -> V_24 , & V_121 ) ;
continue;
V_141:
if ( F_74 ( V_61 ) && F_127 ( V_61 ) )
F_126 ( V_61 ) ;
F_89 ( F_110 ( V_61 ) , V_61 ) ;
F_128 ( V_61 ) ;
V_123 ++ ;
V_137:
F_55 ( V_61 ) ;
V_134:
F_125 ( & V_61 -> V_24 , & V_121 ) ;
F_89 ( F_90 ( V_61 ) || F_88 ( V_61 ) , V_61 ) ;
}
F_129 ( & V_122 ) ;
F_130 () ;
F_131 ( & V_122 , true ) ;
F_132 ( & V_121 , V_113 ) ;
F_30 ( V_153 , V_123 ) ;
* V_115 += V_125 ;
* V_117 += V_126 ;
* V_116 += V_124 ;
* V_118 += V_128 ;
* V_119 += V_129 ;
return V_127 ;
}
unsigned long F_133 ( struct V_7 * V_7 ,
struct V_112 * V_113 )
{
struct V_1 V_2 = {
. V_57 = V_32 ,
. V_154 = V_155 ,
. V_136 = 1 ,
} ;
unsigned long V_53 , V_156 , V_157 , V_158 , V_159 , V_160 ;
struct V_61 * V_61 , * V_161 ;
F_106 ( V_162 ) ;
F_134 (page, next, page_list, lru) {
if ( F_81 ( V_61 ) && ! F_72 ( V_61 ) &&
! F_135 ( V_61 ) ) {
F_136 ( V_61 ) ;
F_137 ( & V_61 -> V_24 , & V_162 ) ;
}
}
V_53 = F_105 ( & V_162 , V_7 -> V_163 , & V_2 ,
V_164 | V_165 ,
& V_156 , & V_157 , & V_158 , & V_159 , & V_160 , true ) ;
F_132 ( & V_162 , V_113 ) ;
F_138 ( V_7 -> V_163 , V_17 , - V_53 ) ;
return V_53 ;
}
int F_139 ( struct V_61 * V_61 , T_5 V_166 )
{
int V_53 = - V_167 ;
if ( ! F_90 ( V_61 ) )
return V_53 ;
if ( F_88 ( V_61 ) && ! ( V_166 & V_168 ) )
return V_53 ;
V_53 = - V_169 ;
if ( V_166 & ( V_170 | V_171 ) ) {
if ( F_63 ( V_61 ) )
return V_53 ;
if ( F_72 ( V_61 ) ) {
struct V_66 * V_67 ;
if ( V_166 & V_170 )
return V_53 ;
V_67 = F_53 ( V_61 ) ;
if ( V_67 && ! V_67 -> V_71 -> V_172 )
return V_53 ;
}
}
if ( ( V_166 & V_173 ) && F_111 ( V_61 ) )
return V_53 ;
if ( F_140 ( F_141 ( V_61 ) ) ) {
F_142 ( V_61 ) ;
V_53 = 0 ;
}
return V_53 ;
}
static T_6 void F_143 ( struct V_22 * V_22 ,
enum V_23 V_24 , unsigned long * V_174 ,
unsigned long V_175 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ ) {
if ( ! V_174 [ V_176 ] )
continue;
F_144 ( V_22 , V_24 , V_176 , - V_174 [ V_176 ] ) ;
}
#ifdef F_145
F_146 ( V_22 , V_24 , - V_175 ) ;
#endif
}
static unsigned long F_147 ( unsigned long V_54 ,
struct V_22 * V_22 , struct V_112 * V_178 ,
unsigned long * V_39 , struct V_1 * V_2 ,
T_5 V_166 , enum V_23 V_24 )
{
struct V_112 * V_179 = & V_22 -> V_180 [ V_24 ] ;
unsigned long V_175 = 0 ;
unsigned long V_174 [ V_177 ] = { 0 } ;
unsigned long V_181 [ V_177 ] = { 0 , } ;
unsigned long V_182 , V_183 ;
F_106 ( V_184 ) ;
for ( V_182 = 0 ; V_182 < V_54 && V_175 < V_54 &&
! F_107 ( V_179 ) ; ) {
struct V_61 * V_61 ;
V_61 = F_108 ( V_179 ) ;
F_148 ( V_61 , V_179 , V_29 ) ;
F_89 ( ! F_90 ( V_61 ) , V_61 ) ;
if ( F_149 ( V_61 ) > V_2 -> V_185 ) {
F_137 ( & V_61 -> V_24 , & V_184 ) ;
V_181 [ F_149 ( V_61 ) ] ++ ;
continue;
}
V_182 ++ ;
switch ( F_139 ( V_61 , V_166 ) ) {
case 0 :
V_183 = F_150 ( V_61 ) ;
V_175 += V_183 ;
V_174 [ F_149 ( V_61 ) ] += V_183 ;
F_137 ( & V_61 -> V_24 , V_178 ) ;
break;
case - V_169 :
F_137 ( & V_61 -> V_24 , V_179 ) ;
continue;
default:
F_151 () ;
}
}
if ( ! F_107 ( & V_184 ) ) {
int V_176 ;
unsigned long V_186 = 0 ;
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ ) {
if ( ! V_181 [ V_176 ] )
continue;
F_152 ( V_187 , V_176 , V_181 [ V_176 ] ) ;
V_186 += V_181 [ V_176 ] ;
}
V_182 += F_107 ( V_179 ) ? V_186 : V_186 >> 2 ;
F_132 ( & V_184 , V_179 ) ;
}
* V_39 = V_182 ;
F_153 ( V_2 -> V_185 , V_2 -> V_188 , V_54 , V_182 ,
V_175 , V_166 , F_154 ( V_24 ) ) ;
F_143 ( V_22 , V_24 , V_174 , V_175 ) ;
return V_175 ;
}
int F_96 ( struct V_61 * V_61 )
{
int V_53 = - V_169 ;
F_89 ( ! F_46 ( V_61 ) , V_61 ) ;
F_155 ( F_156 ( V_61 ) , L_3 ) ;
if ( F_90 ( V_61 ) ) {
struct V_7 * V_7 = F_157 ( V_61 ) ;
struct V_22 * V_22 ;
F_158 ( F_159 ( V_7 ) ) ;
V_22 = F_160 ( V_61 , V_7 -> V_163 ) ;
if ( F_90 ( V_61 ) ) {
int V_24 = F_161 ( V_61 ) ;
F_162 ( V_61 ) ;
F_142 ( V_61 ) ;
F_163 ( V_61 , V_22 , V_24 ) ;
V_53 = 0 ;
}
F_164 ( F_159 ( V_7 ) ) ;
}
return V_53 ;
}
static int F_165 ( struct V_13 * V_14 , int V_189 ,
struct V_1 * V_2 )
{
unsigned long V_190 , V_191 ;
if ( F_113 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_189 ) {
V_190 = F_14 ( V_14 , V_16 ) ;
V_191 = F_14 ( V_14 , V_17 ) ;
} else {
V_190 = F_14 ( V_14 , V_19 ) ;
V_191 = F_14 ( V_14 , V_20 ) ;
}
if ( ( V_2 -> V_57 & ( V_139 | V_138 ) ) == ( V_139 | V_138 ) )
V_190 >>= 3 ;
return V_191 > V_190 ;
}
static T_7 void
F_166 ( struct V_22 * V_22 , struct V_112 * V_113 )
{
struct V_192 * V_193 = & V_22 -> V_193 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
F_106 ( V_194 ) ;
while ( ! F_107 ( V_113 ) ) {
struct V_61 * V_61 = F_108 ( V_113 ) ;
int V_24 ;
F_89 ( F_90 ( V_61 ) , V_61 ) ;
F_22 ( & V_61 -> V_24 ) ;
if ( F_71 ( ! F_92 ( V_61 ) ) ) {
F_164 ( & V_14 -> V_195 ) ;
F_87 ( V_61 ) ;
F_158 ( & V_14 -> V_195 ) ;
continue;
}
V_22 = F_160 ( V_61 , V_14 ) ;
F_167 ( V_61 ) ;
V_24 = F_161 ( V_61 ) ;
F_168 ( V_61 , V_22 , V_24 ) ;
if ( F_169 ( V_24 ) ) {
int V_189 = F_154 ( V_24 ) ;
int V_196 = F_150 ( V_61 ) ;
V_193 -> V_197 [ V_189 ] += V_196 ;
}
if ( F_123 ( V_61 ) ) {
F_170 ( V_61 ) ;
F_171 ( V_61 ) ;
F_163 ( V_61 , V_22 , V_24 ) ;
if ( F_71 ( F_172 ( V_61 ) ) ) {
F_164 ( & V_14 -> V_195 ) ;
F_173 ( V_61 ) ;
( * F_174 ( V_61 ) ) ( V_61 ) ;
F_158 ( & V_14 -> V_195 ) ;
} else
F_125 ( & V_61 -> V_24 , & V_194 ) ;
}
}
F_132 ( & V_194 , V_113 ) ;
}
static int F_175 ( void )
{
return ! ( V_63 -> V_29 & V_198 ) ||
V_63 -> V_65 == NULL ||
F_176 ( V_63 -> V_65 ) ;
}
static bool F_177 ( struct V_22 * V_22 ,
struct V_1 * V_2 , enum V_23 V_24 )
{
int V_176 ;
struct V_7 * V_7 ;
int V_189 = F_154 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
if ( ! F_1 ( V_2 ) )
return true ;
for ( V_176 = V_2 -> V_185 ; V_176 >= 0 ; V_176 -- ) {
V_7 = & V_14 -> V_199 [ V_176 ] ;
if ( ! F_178 ( V_7 ) )
continue;
if ( F_6 ( V_7 , V_200 +
V_201 * V_189 ) >= V_58 )
return true ;
}
return false ;
}
static T_7 unsigned long
F_179 ( unsigned long V_54 , struct V_22 * V_22 ,
struct V_1 * V_2 , enum V_23 V_24 )
{
F_106 ( V_113 ) ;
unsigned long V_39 ;
unsigned long V_127 = 0 ;
unsigned long V_175 ;
unsigned long V_125 = 0 ;
unsigned long V_126 = 0 ;
unsigned long V_124 = 0 ;
unsigned long V_128 = 0 ;
unsigned long V_129 = 0 ;
T_5 V_202 = 0 ;
int V_189 = F_154 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
struct V_192 * V_193 = & V_22 -> V_193 ;
if ( ! F_177 ( V_22 , V_2 , V_24 ) )
return 0 ;
while ( F_71 ( F_165 ( V_14 , V_189 , V_2 ) ) ) {
F_180 ( V_203 , V_204 / 10 ) ;
if ( F_181 ( V_63 ) )
return V_58 ;
}
F_182 () ;
if ( ! V_2 -> V_136 )
V_202 |= V_173 ;
if ( ! V_2 -> V_150 )
V_202 |= V_170 ;
F_158 ( & V_14 -> V_195 ) ;
V_175 = F_147 ( V_54 , V_22 , & V_113 ,
& V_39 , V_2 , V_202 , V_24 ) ;
F_183 ( V_14 , V_20 + V_189 , V_175 ) ;
V_193 -> V_205 [ V_189 ] += V_175 ;
if ( F_1 ( V_2 ) ) {
F_183 ( V_14 , V_21 , V_39 ) ;
if ( F_113 () )
F_184 ( V_206 , V_39 ) ;
else
F_184 ( V_207 , V_39 ) ;
}
F_164 ( & V_14 -> V_195 ) ;
if ( V_175 == 0 )
return 0 ;
V_127 = F_105 ( & V_113 , V_14 , V_2 , V_164 ,
& V_125 , & V_124 , & V_126 ,
& V_128 , & V_129 ,
false ) ;
F_158 ( & V_14 -> V_195 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_113 () )
F_184 ( V_208 , V_127 ) ;
else
F_184 ( V_209 , V_127 ) ;
}
F_166 ( V_22 , & V_113 ) ;
F_183 ( V_14 , V_20 + V_189 , - V_175 ) ;
F_164 ( & V_14 -> V_195 ) ;
F_129 ( & V_113 ) ;
F_131 ( & V_113 , true ) ;
if ( V_128 && V_128 == V_175 )
F_185 ( V_140 , & V_14 -> V_29 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_125 && V_125 == V_126 )
F_185 ( V_210 , & V_14 -> V_29 ) ;
if ( V_124 == V_175 )
F_185 ( V_148 , & V_14 -> V_29 ) ;
if ( V_129 && F_175 () )
F_180 ( V_203 , V_204 / 10 ) ;
}
if ( ! V_2 -> V_211 && ! F_113 () &&
F_175 () )
F_186 ( V_14 , V_203 , V_204 / 10 ) ;
F_187 ( V_14 -> V_212 ,
V_39 , V_127 ,
V_2 -> V_154 , V_189 ) ;
return V_127 ;
}
static void F_188 ( struct V_22 * V_22 ,
struct V_112 * V_35 ,
struct V_112 * V_194 ,
enum V_23 V_24 )
{
struct V_13 * V_14 = F_15 ( V_22 ) ;
unsigned long V_213 = 0 ;
struct V_61 * V_61 ;
int V_183 ;
while ( ! F_107 ( V_35 ) ) {
V_61 = F_108 ( V_35 ) ;
V_22 = F_160 ( V_61 , V_14 ) ;
F_89 ( F_90 ( V_61 ) , V_61 ) ;
F_167 ( V_61 ) ;
V_183 = F_150 ( V_61 ) ;
F_189 ( V_22 , V_24 , F_149 ( V_61 ) , V_183 ) ;
F_137 ( & V_61 -> V_24 , & V_22 -> V_180 [ V_24 ] ) ;
V_213 += V_183 ;
if ( F_123 ( V_61 ) ) {
F_170 ( V_61 ) ;
F_171 ( V_61 ) ;
F_163 ( V_61 , V_22 , V_24 ) ;
if ( F_71 ( F_172 ( V_61 ) ) ) {
F_164 ( & V_14 -> V_195 ) ;
F_173 ( V_61 ) ;
( * F_174 ( V_61 ) ) ( V_61 ) ;
F_158 ( & V_14 -> V_195 ) ;
} else
F_125 ( & V_61 -> V_24 , V_194 ) ;
}
}
if ( ! F_169 ( V_24 ) )
F_184 ( V_214 , V_213 ) ;
}
static void F_190 ( unsigned long V_54 ,
struct V_22 * V_22 ,
struct V_1 * V_2 ,
enum V_23 V_24 )
{
unsigned long V_175 ;
unsigned long V_39 ;
unsigned long V_102 ;
F_106 ( V_215 ) ;
F_106 ( V_216 ) ;
F_106 ( V_217 ) ;
struct V_61 * V_61 ;
struct V_192 * V_193 = & V_22 -> V_193 ;
unsigned long V_218 = 0 ;
T_5 V_202 = 0 ;
int V_189 = F_154 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
F_182 () ;
if ( ! V_2 -> V_136 )
V_202 |= V_173 ;
if ( ! V_2 -> V_150 )
V_202 |= V_170 ;
F_158 ( & V_14 -> V_195 ) ;
V_175 = F_147 ( V_54 , V_22 , & V_215 ,
& V_39 , V_2 , V_202 , V_24 ) ;
F_183 ( V_14 , V_20 + V_189 , V_175 ) ;
V_193 -> V_205 [ V_189 ] += V_175 ;
if ( F_1 ( V_2 ) )
F_183 ( V_14 , V_21 , V_39 ) ;
F_184 ( V_219 , V_39 ) ;
F_164 ( & V_14 -> V_195 ) ;
while ( ! F_107 ( & V_215 ) ) {
F_31 () ;
V_61 = F_108 ( & V_215 ) ;
F_22 ( & V_61 -> V_24 ) ;
if ( F_71 ( ! F_92 ( V_61 ) ) ) {
F_87 ( V_61 ) ;
continue;
}
if ( F_71 ( V_220 ) ) {
if ( F_47 ( V_61 ) && F_109 ( V_61 ) ) {
if ( F_47 ( V_61 ) )
F_122 ( V_61 , 0 ) ;
F_55 ( V_61 ) ;
}
}
if ( F_100 ( V_61 , 0 , V_2 -> V_3 ,
& V_102 ) ) {
V_218 += F_150 ( V_61 ) ;
if ( ( V_102 & V_106 ) && F_81 ( V_61 ) ) {
F_125 ( & V_61 -> V_24 , & V_216 ) ;
continue;
}
}
F_136 ( V_61 ) ;
F_125 ( & V_61 -> V_24 , & V_217 ) ;
}
F_158 ( & V_14 -> V_195 ) ;
V_193 -> V_197 [ V_189 ] += V_218 ;
F_188 ( V_22 , & V_216 , & V_215 , V_24 ) ;
F_188 ( V_22 , & V_217 , & V_215 , V_24 - V_221 ) ;
F_183 ( V_14 , V_20 + V_189 , - V_175 ) ;
F_164 ( & V_14 -> V_195 ) ;
F_129 ( & V_215 ) ;
F_131 ( & V_215 , true ) ;
}
static bool F_191 ( struct V_22 * V_22 , bool V_189 ,
struct V_1 * V_2 )
{
unsigned long V_222 ;
unsigned long V_190 ;
unsigned long V_223 ;
unsigned long V_224 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
int V_176 ;
if ( ! V_189 && ! V_225 )
return false ;
V_190 = F_11 ( V_22 , V_189 * V_201 ) ;
V_223 = F_11 ( V_22 , V_189 * V_201 + V_221 ) ;
for ( V_176 = V_2 -> V_185 + 1 ; V_176 < V_177 ; V_176 ++ ) {
struct V_7 * V_7 = & V_14 -> V_199 [ V_176 ] ;
unsigned long V_226 , V_227 ;
if ( ! F_178 ( V_7 ) )
continue;
V_226 = F_192 ( V_7 ,
V_200 + ( V_189 * V_201 ) ) ;
V_227 = F_192 ( V_7 ,
V_200 + ( V_189 * V_201 ) + V_221 ) ;
V_190 -= F_28 ( V_190 , V_226 ) ;
V_223 -= F_28 ( V_223 , V_227 ) ;
}
V_224 = ( V_190 + V_223 ) >> ( 30 - V_228 ) ;
if ( V_224 )
V_222 = F_193 ( 10 * V_224 ) ;
else
V_222 = 1 ;
return V_190 * V_222 < V_223 ;
}
static unsigned long F_194 ( enum V_23 V_24 , unsigned long V_54 ,
struct V_22 * V_22 , struct V_1 * V_2 )
{
if ( F_169 ( V_24 ) ) {
if ( F_191 ( V_22 , F_154 ( V_24 ) , V_2 ) )
F_190 ( V_54 , V_22 , V_2 , V_24 ) ;
return 0 ;
}
return F_179 ( V_54 , V_22 , V_2 , V_24 ) ;
}
static void F_195 ( struct V_22 * V_22 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_229 )
{
int V_230 = F_196 ( V_5 ) ;
struct V_192 * V_193 = & V_22 -> V_193 ;
T_8 V_231 [ 2 ] ;
T_8 V_232 = 0 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
unsigned long V_233 , V_234 ;
enum V_235 V_235 ;
unsigned long V_236 , V_189 ;
bool V_237 = false ;
unsigned long V_238 , V_239 ;
enum V_23 V_24 ;
bool V_240 ;
int V_241 ;
if ( F_113 () ) {
if ( ! F_10 ( V_14 ) )
V_237 = true ;
if ( ! F_37 ( V_5 ) )
V_237 = true ;
}
if ( ! F_1 ( V_2 ) )
V_237 = true ;
if ( ! V_2 -> V_242 || F_197 ( V_5 ) <= 0 ) {
V_235 = V_243 ;
goto V_59;
}
if ( ! F_1 ( V_2 ) && ! V_230 ) {
V_235 = V_243 ;
goto V_59;
}
if ( ! V_2 -> V_154 && V_230 ) {
V_235 = V_244 ;
goto V_59;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_245 ;
unsigned long V_246 ;
int V_247 ;
unsigned long V_248 = 0 ;
V_246 = F_198 ( V_14 -> V_212 , V_249 ) ;
V_245 = F_14 ( V_14 , V_15 ) +
F_14 ( V_14 , V_16 ) ;
for ( V_247 = 0 ; V_247 < V_177 ; V_247 ++ ) {
struct V_7 * V_7 = & V_14 -> V_199 [ V_247 ] ;
if ( ! F_178 ( V_7 ) )
continue;
V_248 += F_199 ( V_7 ) ;
}
if ( F_71 ( V_245 + V_246 <= V_248 ) ) {
V_235 = V_250 ;
goto V_59;
}
}
if ( ! F_191 ( V_22 , true , V_2 ) &&
F_11 ( V_22 , V_251 ) >> V_2 -> V_154 ) {
V_235 = V_243 ;
goto V_59;
}
V_235 = V_252 ;
V_233 = V_230 ;
V_234 = 200 - V_233 ;
V_236 = F_11 ( V_22 , V_253 ) +
F_11 ( V_22 , V_254 ) ;
V_189 = F_11 ( V_22 , V_255 ) +
F_11 ( V_22 , V_251 ) ;
F_158 ( & V_14 -> V_195 ) ;
if ( F_71 ( V_193 -> V_205 [ 0 ] > V_236 / 4 ) ) {
V_193 -> V_205 [ 0 ] /= 2 ;
V_193 -> V_197 [ 0 ] /= 2 ;
}
if ( F_71 ( V_193 -> V_205 [ 1 ] > V_189 / 4 ) ) {
V_193 -> V_205 [ 1 ] /= 2 ;
V_193 -> V_197 [ 1 ] /= 2 ;
}
V_238 = V_233 * ( V_193 -> V_205 [ 0 ] + 1 ) ;
V_238 /= V_193 -> V_197 [ 0 ] + 1 ;
V_239 = V_234 * ( V_193 -> V_205 [ 1 ] + 1 ) ;
V_239 /= V_193 -> V_197 [ 1 ] + 1 ;
F_164 ( & V_14 -> V_195 ) ;
V_231 [ 0 ] = V_238 ;
V_231 [ 1 ] = V_239 ;
V_232 = V_238 + V_239 + 1 ;
V_59:
V_240 = false ;
for ( V_241 = 0 ; ! V_240 && V_241 < 2 ; V_241 ++ ) {
* V_229 = 0 ;
F_200 (lru) {
int V_189 = F_154 ( V_24 ) ;
unsigned long V_27 ;
unsigned long V_182 ;
V_27 = F_11 ( V_22 , V_24 ) ;
V_182 = V_27 >> V_2 -> V_154 ;
if ( ! V_182 && V_241 && V_237 )
V_182 = F_28 ( V_27 , V_58 ) ;
switch ( V_235 ) {
case V_244 :
break;
case V_252 :
V_182 = F_201 ( V_182 * V_231 [ V_189 ] ,
V_232 ) ;
break;
case V_243 :
case V_250 :
if ( ( V_235 == V_243 ) != V_189 ) {
V_27 = 0 ;
V_182 = 0 ;
}
break;
default:
F_151 () ;
}
* V_229 += V_27 ;
V_8 [ V_24 ] = V_182 ;
V_240 |= ! ! V_182 ;
}
}
}
static void F_202 ( struct V_13 * V_14 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_229 )
{
struct V_22 * V_22 = F_203 ( V_14 , V_5 ) ;
unsigned long V_8 [ V_256 ] ;
unsigned long V_257 [ V_256 ] ;
unsigned long V_54 ;
enum V_23 V_24 ;
unsigned long V_127 = 0 ;
unsigned long V_258 = V_2 -> V_258 ;
struct V_259 V_260 ;
bool V_261 ;
F_195 ( V_22 , V_5 , V_2 , V_8 , V_229 ) ;
memcpy ( V_257 , V_8 , sizeof( V_8 ) ) ;
V_261 = ( F_1 ( V_2 ) && ! F_113 () &&
V_2 -> V_154 == V_155 ) ;
F_204 ( & V_260 ) ;
while ( V_8 [ V_254 ] || V_8 [ V_255 ] ||
V_8 [ V_251 ] ) {
unsigned long V_262 , V_263 , V_264 ;
unsigned long V_39 ;
F_200 (lru) {
if ( V_8 [ V_24 ] ) {
V_54 = F_28 ( V_8 [ V_24 ] , V_58 ) ;
V_8 [ V_24 ] -= V_54 ;
V_127 += F_194 ( V_24 , V_54 ,
V_22 , V_2 ) ;
}
}
F_31 () ;
if ( V_127 < V_258 || V_261 )
continue;
V_263 = V_8 [ V_251 ] + V_8 [ V_255 ] ;
V_262 = V_8 [ V_254 ] + V_8 [ V_253 ] ;
if ( ! V_263 || ! V_262 )
break;
if ( V_263 > V_262 ) {
unsigned long V_265 = V_257 [ V_254 ] +
V_257 [ V_253 ] + 1 ;
V_24 = V_266 ;
V_264 = V_262 * 100 / V_265 ;
} else {
unsigned long V_265 = V_257 [ V_251 ] +
V_257 [ V_255 ] + 1 ;
V_24 = V_201 ;
V_264 = V_263 * 100 / V_265 ;
}
V_8 [ V_24 ] = 0 ;
V_8 [ V_24 + V_221 ] = 0 ;
V_24 = ( V_24 == V_201 ) ? V_266 : V_201 ;
V_39 = V_257 [ V_24 ] - V_8 [ V_24 ] ;
V_8 [ V_24 ] = V_257 [ V_24 ] * ( 100 - V_264 ) / 100 ;
V_8 [ V_24 ] -= F_28 ( V_8 [ V_24 ] , V_39 ) ;
V_24 += V_221 ;
V_39 = V_257 [ V_24 ] - V_8 [ V_24 ] ;
V_8 [ V_24 ] = V_257 [ V_24 ] * ( 100 - V_264 ) / 100 ;
V_8 [ V_24 ] -= F_28 ( V_8 [ V_24 ] , V_39 ) ;
V_261 = true ;
}
F_205 ( & V_260 ) ;
V_2 -> V_127 += V_127 ;
if ( F_191 ( V_22 , false , V_2 ) )
F_190 ( V_58 , V_22 ,
V_2 , V_253 ) ;
}
static bool F_206 ( struct V_1 * V_2 )
{
if ( F_207 ( V_267 ) && V_2 -> V_188 &&
( V_2 -> V_188 > V_268 ||
V_2 -> V_154 < V_155 - 2 ) )
return true ;
return false ;
}
static inline bool F_208 ( struct V_13 * V_14 ,
unsigned long V_127 ,
unsigned long V_39 ,
struct V_1 * V_2 )
{
unsigned long V_269 ;
unsigned long V_270 ;
int V_247 ;
if ( ! F_206 ( V_2 ) )
return false ;
if ( V_2 -> V_57 & V_271 ) {
if ( ! V_127 && ! V_39 )
return false ;
} else {
if ( ! V_127 )
return false ;
}
V_269 = F_209 ( V_2 -> V_188 ) ;
V_270 = F_14 ( V_14 , V_16 ) ;
if ( F_7 () > 0 )
V_270 += F_14 ( V_14 , V_19 ) ;
if ( V_2 -> V_127 < V_269 &&
V_270 > V_269 )
return true ;
for ( V_247 = 0 ; V_247 <= V_2 -> V_185 ; V_247 ++ ) {
struct V_7 * V_7 = & V_14 -> V_199 [ V_247 ] ;
if ( ! F_178 ( V_7 ) )
continue;
switch ( F_210 ( V_7 , V_2 -> V_188 , 0 , V_2 -> V_185 ) ) {
case V_272 :
case V_273 :
return false ;
default:
;
}
}
return true ;
}
static bool F_211 ( T_9 * V_14 , struct V_1 * V_2 )
{
struct V_274 * V_274 = V_63 -> V_274 ;
unsigned long V_127 , V_39 ;
bool V_275 = false ;
do {
struct V_4 * V_276 = V_2 -> V_3 ;
struct V_277 V_278 = {
. V_14 = V_14 ,
. V_154 = V_2 -> V_154 ,
} ;
unsigned long V_279 = 0 ;
struct V_4 * V_5 ;
V_127 = V_2 -> V_127 ;
V_39 = V_2 -> V_39 ;
V_5 = F_42 ( V_276 , NULL , & V_278 ) ;
do {
unsigned long V_229 ;
unsigned long V_88 ;
unsigned long V_280 ;
if ( F_212 ( V_276 , V_5 ) ) {
if ( ! V_2 -> V_281 )
continue;
F_213 ( V_5 , V_282 , 1 ) ;
}
V_88 = V_2 -> V_127 ;
V_280 = V_2 -> V_39 ;
F_202 ( V_14 , V_5 , V_2 , & V_229 ) ;
V_279 += V_229 ;
if ( V_5 )
F_35 ( V_2 -> V_57 , V_14 -> V_212 ,
V_5 , V_2 -> V_39 - V_280 ,
V_229 ) ;
F_214 ( V_2 -> V_57 , V_5 , false ,
V_2 -> V_39 - V_280 ,
V_2 -> V_127 - V_88 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_127 >= V_2 -> V_258 ) {
F_215 ( V_276 , V_5 ) ;
break;
}
} while ( ( V_5 = F_42 ( V_276 , V_5 , & V_278 ) ) );
if ( F_1 ( V_2 ) )
F_35 ( V_2 -> V_57 , V_14 -> V_212 , NULL ,
V_2 -> V_39 - V_39 ,
V_279 ) ;
if ( V_274 ) {
V_2 -> V_127 += V_274 -> V_283 ;
V_274 -> V_283 = 0 ;
}
F_214 ( V_2 -> V_57 , V_2 -> V_3 , true ,
V_2 -> V_39 - V_39 ,
V_2 -> V_127 - V_127 ) ;
if ( V_2 -> V_127 - V_127 )
V_275 = true ;
} while ( F_208 ( V_14 , V_2 -> V_127 - V_127 ,
V_2 -> V_39 - V_39 , V_2 ) );
return V_275 ;
}
static inline bool F_216 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
unsigned long V_284 ;
enum V_285 V_286 ;
V_286 = F_210 ( V_7 , V_2 -> V_188 , 0 , V_2 -> V_185 ) ;
if ( V_286 == V_272 )
return true ;
if ( V_286 == V_287 )
return false ;
V_284 = F_199 ( V_7 ) + F_209 ( V_2 -> V_188 ) ;
return F_217 ( V_7 , 0 , V_284 , V_2 -> V_185 ) ;
}
static void F_218 ( struct V_288 * V_288 , struct V_1 * V_2 )
{
struct V_289 * V_247 ;
struct V_7 * V_7 ;
unsigned long V_290 ;
unsigned long V_291 ;
T_2 V_292 ;
T_9 * V_293 = NULL ;
V_292 = V_2 -> V_57 ;
if ( V_220 ) {
V_2 -> V_57 |= V_294 ;
V_2 -> V_185 = F_219 ( V_2 -> V_57 ) ;
}
F_220 (zone, z, zonelist,
sc->reclaim_idx, sc->nodemask) {
if ( F_1 ( V_2 ) ) {
if ( ! F_221 ( V_7 ,
V_32 | V_295 ) )
continue;
if ( V_2 -> V_154 != V_155 &&
! F_10 ( V_7 -> V_163 ) )
continue;
if ( F_207 ( V_267 ) &&
V_2 -> V_188 > V_268 &&
F_216 ( V_7 , V_2 ) ) {
V_2 -> F_216 = true ;
continue;
}
if ( V_7 -> V_163 == V_293 )
continue;
V_291 = 0 ;
V_290 = F_222 ( V_7 -> V_163 ,
V_2 -> V_188 , V_2 -> V_57 ,
& V_291 ) ;
V_2 -> V_127 += V_290 ;
V_2 -> V_39 += V_291 ;
}
if ( V_7 -> V_163 == V_293 )
continue;
V_293 = V_7 -> V_163 ;
F_211 ( V_7 -> V_163 , V_2 ) ;
}
V_2 -> V_57 = V_292 ;
}
static unsigned long F_223 ( struct V_288 * V_288 ,
struct V_1 * V_2 )
{
int V_296 = V_2 -> V_154 ;
unsigned long V_297 = 0 ;
unsigned long V_298 ;
V_299:
F_224 () ;
if ( F_1 ( V_2 ) )
F_152 ( V_300 , V_2 -> V_185 , 1 ) ;
do {
F_225 ( V_2 -> V_57 , V_2 -> V_3 ,
V_2 -> V_154 ) ;
V_2 -> V_39 = 0 ;
F_218 ( V_288 , V_2 ) ;
V_297 += V_2 -> V_39 ;
if ( V_2 -> V_127 >= V_2 -> V_258 )
break;
if ( V_2 -> F_216 )
break;
if ( V_2 -> V_154 < V_155 - 2 )
V_2 -> V_150 = 1 ;
V_298 = V_2 -> V_258 + V_2 -> V_258 / 2 ;
if ( V_297 > V_298 ) {
F_226 ( V_301 ? 0 : V_297 ,
V_302 ) ;
V_2 -> V_150 = 1 ;
}
} while ( -- V_2 -> V_154 >= 0 );
F_227 () ;
if ( V_2 -> V_127 )
return V_2 -> V_127 ;
if ( V_2 -> F_216 )
return 1 ;
if ( ! V_2 -> V_281 ) {
V_2 -> V_154 = V_296 ;
V_2 -> V_281 = 1 ;
goto V_299;
}
return 0 ;
}
static bool F_228 ( T_9 * V_14 )
{
struct V_7 * V_7 ;
unsigned long V_303 = 0 ;
unsigned long V_122 = 0 ;
int V_304 ;
bool V_305 ;
for ( V_304 = 0 ; V_304 <= V_306 ; V_304 ++ ) {
V_7 = & V_14 -> V_199 [ V_304 ] ;
if ( ! F_178 ( V_7 ) ||
F_8 ( V_14 ) == 0 )
continue;
V_303 += F_229 ( V_7 ) ;
V_122 += F_192 ( V_7 , V_249 ) ;
}
if ( ! V_303 )
return true ;
V_305 = V_122 > V_303 / 2 ;
if ( ! V_305 && F_230 ( & V_14 -> V_307 ) ) {
V_14 -> V_308 = F_28 ( V_14 -> V_308 ,
(enum V_309 ) V_306 ) ;
F_231 ( & V_14 -> V_307 ) ;
}
return V_305 ;
}
static bool F_232 ( T_2 V_57 , struct V_288 * V_288 ,
T_10 * V_310 )
{
struct V_289 * V_247 ;
struct V_7 * V_7 ;
T_9 * V_14 = NULL ;
if ( V_63 -> V_29 & V_311 )
goto V_59;
if ( F_181 ( V_63 ) )
goto V_59;
F_220 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_233 ( V_7 ) > V_306 )
continue;
V_14 = V_7 -> V_163 ;
if ( F_228 ( V_14 ) )
goto V_59;
break;
}
if ( ! V_14 )
goto V_59;
F_98 ( V_312 ) ;
if ( ! ( V_57 & V_138 ) ) {
F_234 ( V_14 -> V_313 ,
F_228 ( V_14 ) , V_204 ) ;
goto V_314;
}
F_235 ( V_7 -> V_163 -> V_313 ,
F_228 ( V_14 ) ) ;
V_314:
if ( F_181 ( V_63 ) )
return true ;
V_59:
return false ;
}
unsigned long F_236 ( struct V_288 * V_288 , int V_188 ,
T_2 V_57 , T_10 * V_310 )
{
unsigned long V_127 ;
struct V_1 V_2 = {
. V_258 = V_58 ,
. V_57 = ( V_57 = F_237 ( V_57 ) ) ,
. V_185 = F_219 ( V_57 ) ,
. V_188 = V_188 ,
. V_310 = V_310 ,
. V_154 = V_155 ,
. V_150 = ! V_301 ,
. V_136 = 1 ,
. V_242 = 1 ,
} ;
if ( F_232 ( V_57 , V_288 , V_310 ) )
return 1 ;
F_238 ( V_188 ,
V_2 . V_150 ,
V_57 ,
V_2 . V_185 ) ;
V_127 = F_223 ( V_288 , & V_2 ) ;
F_239 ( V_127 ) ;
return V_127 ;
}
unsigned long F_240 ( struct V_4 * V_5 ,
T_2 V_57 , bool V_315 ,
T_9 * V_14 ,
unsigned long * V_39 )
{
struct V_1 V_2 = {
. V_258 = V_58 ,
. V_3 = V_5 ,
. V_150 = ! V_301 ,
. V_136 = 1 ,
. V_185 = V_177 - 1 ,
. V_242 = ! V_315 ,
} ;
unsigned long V_229 ;
V_2 . V_57 = ( V_57 & V_316 ) |
( V_317 & ~ V_316 ) ;
F_241 ( V_2 . V_188 ,
V_2 . V_150 ,
V_2 . V_57 ,
V_2 . V_185 ) ;
F_202 ( V_14 , V_5 , & V_2 , & V_229 ) ;
F_242 ( V_2 . V_127 ) ;
* V_39 = V_2 . V_39 ;
return V_2 . V_127 ;
}
unsigned long F_243 ( struct V_4 * V_5 ,
unsigned long V_183 ,
T_2 V_57 ,
bool V_242 )
{
struct V_288 * V_288 ;
unsigned long V_127 ;
int V_46 ;
struct V_1 V_2 = {
. V_258 = F_244 ( V_183 , V_58 ) ,
. V_57 = ( V_57 & V_316 ) |
( V_317 & ~ V_316 ) ,
. V_185 = V_177 - 1 ,
. V_3 = V_5 ,
. V_154 = V_155 ,
. V_150 = ! V_301 ,
. V_136 = 1 ,
. V_242 = V_242 ,
} ;
V_46 = F_245 ( V_5 ) ;
V_288 = & F_246 ( V_46 ) -> V_318 [ V_319 ] ;
F_247 ( 0 ,
V_2 . V_150 ,
V_2 . V_57 ,
V_2 . V_185 ) ;
V_63 -> V_29 |= V_320 ;
V_127 = F_223 ( V_288 , & V_2 ) ;
V_63 -> V_29 &= ~ V_320 ;
F_248 ( V_127 ) ;
return V_127 ;
}
static void F_249 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_225 )
return;
V_5 = F_42 ( NULL , NULL , NULL ) ;
do {
struct V_22 * V_22 = F_203 ( V_14 , V_5 ) ;
if ( F_191 ( V_22 , false , V_2 ) )
F_190 ( V_58 , V_22 ,
V_2 , V_253 ) ;
V_5 = F_42 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_250 ( struct V_7 * V_7 , int V_188 , int V_321 )
{
unsigned long V_322 = F_199 ( V_7 ) ;
if ( ! F_217 ( V_7 , V_188 , V_322 , V_321 ) )
return false ;
F_251 ( V_210 , & V_7 -> V_163 -> V_29 ) ;
F_251 ( V_148 , & V_7 -> V_163 -> V_29 ) ;
return true ;
}
static bool F_252 ( T_9 * V_14 , int V_188 , int V_321 )
{
int V_304 ;
if ( F_230 ( & V_14 -> V_313 ) )
F_253 ( & V_14 -> V_313 ) ;
for ( V_304 = 0 ; V_304 <= V_321 ; V_304 ++ ) {
struct V_7 * V_7 = V_14 -> V_199 + V_304 ;
if ( ! F_178 ( V_7 ) )
continue;
if ( ! F_250 ( V_7 , V_188 , V_321 ) )
return false ;
}
return true ;
}
static bool F_254 ( T_9 * V_14 ,
struct V_1 * V_2 )
{
struct V_7 * V_7 ;
int V_247 ;
V_2 -> V_258 = 0 ;
for ( V_247 = 0 ; V_247 <= V_2 -> V_185 ; V_247 ++ ) {
V_7 = V_14 -> V_199 + V_247 ;
if ( ! F_178 ( V_7 ) )
continue;
V_2 -> V_258 += F_244 ( F_199 ( V_7 ) , V_58 ) ;
}
F_211 ( V_14 , V_2 ) ;
if ( V_2 -> V_188 && V_2 -> V_127 >= F_209 ( V_2 -> V_188 ) )
V_2 -> V_188 = 0 ;
return V_2 -> V_39 >= V_2 -> V_258 ;
}
static int F_255 ( T_9 * V_14 , int V_188 , int V_321 )
{
int V_304 ;
unsigned long V_290 ;
unsigned long V_291 ;
struct V_7 * V_7 ;
struct V_1 V_2 = {
. V_57 = V_32 ,
. V_188 = V_188 ,
. V_154 = V_155 ,
. V_150 = ! V_301 ,
. V_136 = 1 ,
. V_242 = 1 ,
} ;
F_98 ( V_323 ) ;
do {
bool V_324 = true ;
V_2 . V_127 = 0 ;
V_2 . V_185 = V_321 ;
if ( V_220 ) {
for ( V_304 = V_177 - 1 ; V_304 >= 0 ; V_304 -- ) {
V_7 = V_14 -> V_199 + V_304 ;
if ( ! F_178 ( V_7 ) )
continue;
V_2 . V_185 = V_304 ;
break;
}
}
for ( V_304 = V_321 ; V_304 >= 0 ; V_304 -- ) {
V_7 = V_14 -> V_199 + V_304 ;
if ( ! F_178 ( V_7 ) )
continue;
if ( F_250 ( V_7 , V_2 . V_188 , V_321 ) )
goto V_59;
}
F_249 ( V_14 , & V_2 ) ;
if ( V_2 . V_154 < V_155 - 2 || ! F_10 ( V_14 ) )
V_2 . V_150 = 1 ;
V_2 . V_39 = 0 ;
V_291 = 0 ;
V_290 = F_222 ( V_14 , V_2 . V_188 ,
V_2 . V_57 , & V_291 ) ;
V_2 . V_127 += V_290 ;
if ( F_254 ( V_14 , & V_2 ) )
V_324 = false ;
if ( F_230 ( & V_14 -> V_313 ) &&
F_228 ( V_14 ) )
F_253 ( & V_14 -> V_313 ) ;
if ( F_256 () || F_257 () )
break;
if ( V_324 || ! V_2 . V_127 )
V_2 . V_154 -- ;
} while ( V_2 . V_154 >= 1 );
V_59:
return V_2 . V_188 ;
}
static void F_258 ( T_9 * V_14 , int V_325 , int V_326 ,
unsigned int V_321 )
{
long V_327 = 0 ;
F_259 ( V_328 ) ;
if ( F_260 ( V_63 ) || F_257 () )
return;
F_261 ( & V_14 -> V_307 , & V_328 , V_329 ) ;
if ( F_252 ( V_14 , V_326 , V_321 ) ) {
F_262 ( V_14 ) ;
F_263 ( V_14 , V_325 , V_321 ) ;
V_327 = F_264 ( V_204 / 10 ) ;
if ( V_327 ) {
V_14 -> V_308 = F_244 ( V_14 -> V_308 , V_321 ) ;
V_14 -> V_330 = F_244 ( V_14 -> V_330 , V_326 ) ;
}
F_265 ( & V_14 -> V_307 , & V_328 ) ;
F_261 ( & V_14 -> V_307 , & V_328 , V_329 ) ;
}
if ( ! V_327 &&
F_252 ( V_14 , V_326 , V_321 ) ) {
F_266 ( V_14 -> V_212 ) ;
F_267 ( V_14 , V_331 ) ;
if ( ! F_257 () )
F_268 () ;
F_267 ( V_14 , V_332 ) ;
} else {
if ( V_327 )
F_98 ( V_333 ) ;
else
F_98 ( V_334 ) ;
}
F_265 ( & V_14 -> V_307 , & V_328 ) ;
}
static int F_269 ( void * V_335 )
{
unsigned int V_325 , V_326 , V_321 ;
T_9 * V_14 = ( T_9 * ) V_335 ;
struct V_336 * V_337 = V_63 ;
struct V_274 V_274 = {
. V_283 = 0 ,
} ;
const struct V_338 * V_338 = F_270 ( V_14 -> V_212 ) ;
F_271 ( V_32 ) ;
if ( ! F_272 ( V_338 ) )
F_273 ( V_337 , V_338 ) ;
V_63 -> V_274 = & V_274 ;
V_337 -> V_29 |= V_320 | V_64 | V_339 ;
F_274 () ;
V_14 -> V_330 = V_325 = V_326 = 0 ;
V_14 -> V_308 = V_321 = 0 ;
for ( ; ; ) {
bool V_53 ;
V_340:
F_258 ( V_14 , V_325 , V_326 ,
V_321 ) ;
V_325 = V_326 = V_14 -> V_330 ;
V_321 = V_14 -> V_308 ;
V_14 -> V_330 = 0 ;
V_14 -> V_308 = 0 ;
V_53 = F_256 () ;
if ( F_257 () )
break;
if ( V_53 )
continue;
F_275 ( V_14 -> V_212 , V_321 ,
V_325 ) ;
V_326 = F_255 ( V_14 , V_325 , V_321 ) ;
if ( V_326 < V_325 )
goto V_340;
V_325 = V_326 = V_14 -> V_330 ;
V_321 = V_14 -> V_308 ;
}
V_337 -> V_29 &= ~ ( V_320 | V_64 | V_339 ) ;
V_63 -> V_274 = NULL ;
F_276 () ;
return 0 ;
}
void F_277 ( struct V_7 * V_7 , int V_188 , enum V_309 V_321 )
{
T_9 * V_14 ;
int V_247 ;
if ( ! F_178 ( V_7 ) )
return;
if ( ! F_221 ( V_7 , V_32 | V_295 ) )
return;
V_14 = V_7 -> V_163 ;
V_14 -> V_308 = F_244 ( V_14 -> V_308 , V_321 ) ;
V_14 -> V_330 = F_244 ( V_14 -> V_330 , V_188 ) ;
if ( ! F_230 ( & V_14 -> V_307 ) )
return;
for ( V_247 = 0 ; V_247 <= V_321 ; V_247 ++ ) {
V_7 = V_14 -> V_199 + V_247 ;
if ( ! F_178 ( V_7 ) )
continue;
if ( F_250 ( V_7 , V_188 , V_321 ) )
return;
}
F_278 ( V_14 -> V_212 , F_233 ( V_7 ) , V_188 ) ;
F_231 ( & V_14 -> V_307 ) ;
}
unsigned long F_279 ( unsigned long V_258 )
{
struct V_274 V_274 ;
struct V_1 V_2 = {
. V_258 = V_258 ,
. V_57 = V_317 ,
. V_185 = V_177 - 1 ,
. V_154 = V_155 ,
. V_150 = 1 ,
. V_136 = 1 ,
. V_242 = 1 ,
. V_211 = 1 ,
} ;
struct V_288 * V_288 = F_280 ( F_281 () , V_2 . V_57 ) ;
struct V_336 * V_335 = V_63 ;
unsigned long V_127 ;
V_335 -> V_29 |= V_320 ;
F_271 ( V_2 . V_57 ) ;
V_274 . V_283 = 0 ;
V_335 -> V_274 = & V_274 ;
V_127 = F_223 ( V_288 , & V_2 ) ;
V_335 -> V_274 = NULL ;
F_276 () ;
V_335 -> V_29 &= ~ V_320 ;
return V_127 ;
}
static int F_282 ( struct V_341 * V_342 , unsigned long V_343 ,
void * V_344 )
{
int V_46 ;
if ( V_343 == V_345 || V_343 == V_346 ) {
F_283 (nid, N_MEMORY) {
T_9 * V_14 = F_246 ( V_46 ) ;
const struct V_338 * V_347 ;
V_347 = F_270 ( V_14 -> V_212 ) ;
if ( F_284 ( V_348 , V_347 ) < V_349 )
F_273 ( V_14 -> F_269 , V_347 ) ;
}
}
return V_350 ;
}
int F_285 ( int V_46 )
{
T_9 * V_14 = F_246 ( V_46 ) ;
int V_53 = 0 ;
if ( V_14 -> F_269 )
return 0 ;
V_14 -> F_269 = F_286 ( F_269 , V_14 , L_4 , V_46 ) ;
if ( F_287 ( V_14 -> F_269 ) ) {
F_67 ( V_351 == V_352 ) ;
F_27 ( L_5 , V_46 ) ;
V_53 = F_288 ( V_14 -> F_269 ) ;
V_14 -> F_269 = NULL ;
}
return V_53 ;
}
void F_289 ( int V_46 )
{
struct V_336 * F_269 = F_246 ( V_46 ) -> F_269 ;
if ( F_269 ) {
F_290 ( F_269 ) ;
F_246 ( V_46 ) -> F_269 = NULL ;
}
}
static int T_11 F_291 ( void )
{
int V_46 ;
F_292 () ;
F_283 (nid, N_MEMORY)
F_285 ( V_46 ) ;
F_293 ( F_282 , 0 ) ;
return 0 ;
}
static inline unsigned long F_294 ( struct V_13 * V_14 )
{
unsigned long V_353 = F_14 ( V_14 , V_354 ) ;
unsigned long V_355 = F_14 ( V_14 , V_16 ) +
F_14 ( V_14 , V_15 ) ;
return ( V_355 > V_353 ) ? ( V_355 - V_353 ) : 0 ;
}
static unsigned long F_295 ( struct V_13 * V_14 )
{
unsigned long V_356 ;
unsigned long V_42 = 0 ;
if ( V_357 & V_358 )
V_356 = F_14 ( V_14 , V_359 ) ;
else
V_356 = F_294 ( V_14 ) ;
if ( ! ( V_357 & V_360 ) )
V_42 += F_14 ( V_14 , V_361 ) ;
if ( F_71 ( V_42 > V_356 ) )
V_42 = V_356 ;
return V_356 - V_42 ;
}
static int F_296 ( struct V_13 * V_14 , T_2 V_57 , unsigned int V_188 )
{
const unsigned long V_183 = 1 << V_188 ;
struct V_336 * V_335 = V_63 ;
struct V_274 V_274 ;
int V_321 = F_219 ( V_57 ) ;
struct V_1 V_2 = {
. V_258 = F_244 ( V_183 , V_58 ) ,
. V_57 = ( V_57 = F_237 ( V_57 ) ) ,
. V_188 = V_188 ,
. V_154 = V_362 ,
. V_150 = ! ! ( V_357 & V_360 ) ,
. V_136 = ! ! ( V_357 & V_358 ) ,
. V_242 = 1 ,
. V_185 = V_321 ,
} ;
F_31 () ;
V_335 -> V_29 |= V_320 | V_64 ;
F_271 ( V_57 ) ;
V_274 . V_283 = 0 ;
V_335 -> V_274 = & V_274 ;
if ( F_295 ( V_14 ) > V_14 -> V_363 ) {
do {
F_211 ( V_14 , & V_2 ) ;
} while ( V_2 . V_127 < V_183 && -- V_2 . V_154 >= 0 );
}
V_335 -> V_274 = NULL ;
V_63 -> V_29 &= ~ ( V_320 | V_64 ) ;
F_276 () ;
return V_2 . V_127 >= V_183 ;
}
int F_297 ( struct V_13 * V_14 , T_2 V_57 , unsigned int V_188 )
{
int V_53 ;
if ( F_295 ( V_14 ) <= V_14 -> V_363 &&
F_198 ( V_14 -> V_212 , V_364 ) <= V_14 -> V_365 )
return V_366 ;
if ( ! F_10 ( V_14 ) )
return V_366 ;
if ( ! F_298 ( V_57 ) || ( V_63 -> V_29 & V_320 ) )
return V_367 ;
if ( F_299 ( V_14 -> V_212 , V_368 ) && V_14 -> V_212 != F_281 () )
return V_367 ;
if ( F_300 ( V_369 , & V_14 -> V_29 ) )
return V_367 ;
V_53 = F_296 ( V_14 , V_57 , V_188 ) ;
F_251 ( V_369 , & V_14 -> V_29 ) ;
if ( ! V_53 )
F_98 ( V_370 ) ;
return V_53 ;
}
int F_92 ( struct V_61 * V_61 )
{
return ! F_301 ( F_53 ( V_61 ) ) && ! F_302 ( V_61 ) ;
}
void F_303 ( struct V_61 * * V_371 , int V_183 )
{
struct V_22 * V_22 ;
struct V_13 * V_14 = NULL ;
int V_372 = 0 ;
int V_373 = 0 ;
int V_304 ;
for ( V_304 = 0 ; V_304 < V_183 ; V_304 ++ ) {
struct V_61 * V_61 = V_371 [ V_304 ] ;
struct V_13 * V_374 = F_304 ( V_61 ) ;
V_372 ++ ;
if ( V_374 != V_14 ) {
if ( V_14 )
F_164 ( & V_14 -> V_195 ) ;
V_14 = V_374 ;
F_158 ( & V_14 -> V_195 ) ;
}
V_22 = F_160 ( V_61 , V_14 ) ;
if ( ! F_90 ( V_61 ) || ! F_88 ( V_61 ) )
continue;
if ( F_92 ( V_61 ) ) {
enum V_23 V_24 = F_305 ( V_61 ) ;
F_89 ( F_110 ( V_61 ) , V_61 ) ;
F_91 ( V_61 ) ;
F_163 ( V_61 , V_22 , V_375 ) ;
F_168 ( V_61 , V_22 , V_24 ) ;
V_373 ++ ;
}
}
if ( V_14 ) {
F_184 ( V_97 , V_373 ) ;
F_184 ( V_376 , V_372 ) ;
F_164 ( & V_14 -> V_195 ) ;
}
}
