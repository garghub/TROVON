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
unsigned long F_16 ( struct V_22 * V_22 , enum V_23 V_24 ,
int V_26 )
{
if ( ! F_12 () )
return F_17 ( V_22 , V_24 , V_26 ) ;
return F_18 ( & F_15 ( V_22 ) -> V_27 [ V_26 ] ,
V_28 + V_24 ) ;
}
int F_19 ( struct V_29 * V_29 )
{
T_1 V_30 = sizeof( * V_29 -> V_31 ) ;
if ( V_29 -> V_32 & V_33 )
V_30 *= V_34 ;
V_29 -> V_31 = F_20 ( V_30 , V_35 ) ;
if ( ! V_29 -> V_31 )
return - V_36 ;
F_21 ( & V_37 ) ;
F_22 ( & V_29 -> V_38 , & V_39 ) ;
F_23 ( & V_37 ) ;
return 0 ;
}
void F_24 ( struct V_29 * V_29 )
{
F_21 ( & V_37 ) ;
F_25 ( & V_29 -> V_38 ) ;
F_23 ( & V_37 ) ;
F_26 ( V_29 -> V_31 ) ;
}
static unsigned long F_27 ( struct V_40 * V_41 ,
struct V_29 * V_29 ,
unsigned long V_42 ,
unsigned long V_43 )
{
unsigned long V_44 = 0 ;
unsigned long long V_45 ;
long V_46 ;
long V_47 ;
long V_8 ;
long V_48 ;
int V_49 = V_41 -> V_49 ;
long V_50 = V_29 -> V_51 ? V_29 -> V_51
: V_52 ;
long V_53 = 0 , V_54 ;
V_47 = V_29 -> V_55 ( V_29 , V_41 ) ;
if ( V_47 == 0 )
return 0 ;
V_8 = F_28 ( & V_29 -> V_31 [ V_49 ] , 0 ) ;
V_46 = V_8 ;
V_45 = ( 4 * V_42 ) / V_29 -> V_56 ;
V_45 *= V_47 ;
F_29 ( V_45 , V_43 + 1 ) ;
V_46 += V_45 ;
if ( V_46 < 0 ) {
F_30 ( L_1 ,
V_29 -> V_57 , V_46 ) ;
V_46 = V_47 ;
V_54 = V_8 ;
} else
V_54 = V_46 ;
if ( V_45 < V_47 / 4 )
V_46 = F_31 ( V_46 , V_47 / 2 ) ;
if ( V_46 > V_47 * 2 )
V_46 = V_47 * 2 ;
F_32 ( V_29 , V_41 , V_8 ,
V_42 , V_43 ,
V_47 , V_45 , V_46 ) ;
while ( V_46 >= V_50 ||
V_46 >= V_47 ) {
unsigned long V_58 ;
unsigned long V_59 = F_31 ( V_50 , V_46 ) ;
V_41 -> V_59 = V_59 ;
V_58 = V_29 -> V_57 ( V_29 , V_41 ) ;
if ( V_58 == V_60 )
break;
V_44 += V_58 ;
F_33 ( V_61 , V_59 ) ;
V_46 -= V_59 ;
V_53 += V_59 ;
F_34 () ;
}
if ( V_54 >= V_53 )
V_54 -= V_53 ;
else
V_54 = 0 ;
if ( V_54 > 0 )
V_48 = F_35 ( V_54 ,
& V_29 -> V_31 [ V_49 ] ) ;
else
V_48 = F_36 ( & V_29 -> V_31 [ V_49 ] ) ;
F_37 ( V_29 , V_49 , V_44 , V_8 , V_48 , V_46 ) ;
return V_44 ;
}
static unsigned long F_38 ( T_2 V_62 , int V_49 ,
struct V_4 * V_5 ,
unsigned long V_42 ,
unsigned long V_43 )
{
struct V_29 * V_29 ;
unsigned long V_44 = 0 ;
if ( V_5 && ( ! F_39 () || ! F_40 ( V_5 ) ) )
return 0 ;
if ( V_42 == 0 )
V_42 = V_63 ;
if ( ! F_41 ( & V_37 ) ) {
V_44 = 1 ;
goto V_64;
}
F_42 (shrinker, &shrinker_list, list) {
struct V_40 V_2 = {
. V_62 = V_62 ,
. V_49 = V_49 ,
. V_5 = V_5 ,
} ;
if ( F_39 () &&
! ! V_5 != ! ! ( V_29 -> V_32 & V_65 ) )
continue;
if ( ! ( V_29 -> V_32 & V_33 ) )
V_2 . V_49 = 0 ;
V_44 += F_27 ( & V_2 , V_29 , V_42 , V_43 ) ;
}
F_43 ( & V_37 ) ;
V_64:
F_34 () ;
return V_44 ;
}
void F_44 ( int V_49 )
{
unsigned long V_44 ;
do {
struct V_4 * V_5 = NULL ;
V_44 = 0 ;
do {
V_44 += F_38 ( V_35 , V_49 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_45 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_44 > 10 );
}
void F_46 ( void )
{
int V_49 ;
F_47 (nid)
F_44 ( V_49 ) ;
}
static inline int F_48 ( struct V_66 * V_66 )
{
return F_49 ( V_66 ) - F_50 ( V_66 ) == 2 ;
}
static int F_51 ( struct V_67 * V_67 , struct V_1 * V_2 )
{
if ( V_68 -> V_32 & V_69 )
return 1 ;
if ( ! F_52 ( V_67 ) )
return 1 ;
if ( F_53 ( V_67 ) == V_68 -> V_70 )
return 1 ;
return 0 ;
}
static void F_54 ( struct V_71 * V_72 ,
struct V_66 * V_66 , int error )
{
F_55 ( V_66 ) ;
if ( F_56 ( V_66 ) == V_72 )
F_57 ( V_72 , error ) ;
F_58 ( V_66 ) ;
}
static T_3 F_59 ( struct V_66 * V_66 , struct V_71 * V_72 ,
struct V_1 * V_2 )
{
if ( ! F_48 ( V_66 ) )
return V_73 ;
if ( ! V_72 ) {
if ( F_50 ( V_66 ) ) {
if ( F_60 ( V_66 ) ) {
F_61 ( V_66 ) ;
F_62 ( L_2 , V_74 ) ;
return V_75 ;
}
}
return V_73 ;
}
if ( V_72 -> V_76 -> V_77 == NULL )
return V_78 ;
if ( ! F_51 ( V_72 -> V_79 , V_2 ) )
return V_73 ;
if ( F_63 ( V_66 ) ) {
int V_80 ;
struct V_81 V_82 = {
. V_83 = V_84 ,
. V_85 = V_63 ,
. V_86 = 0 ,
. V_87 = V_88 ,
. V_89 = 1 ,
} ;
F_64 ( V_66 ) ;
V_80 = V_72 -> V_76 -> V_77 ( V_66 , & V_82 ) ;
if ( V_80 < 0 )
F_54 ( V_72 , V_66 , V_80 ) ;
if ( V_80 == V_90 ) {
F_65 ( V_66 ) ;
return V_78 ;
}
if ( ! F_66 ( V_66 ) ) {
F_65 ( V_66 ) ;
}
F_67 ( V_66 ) ;
F_68 ( V_66 , V_91 ) ;
return V_92 ;
}
return V_75 ;
}
static int F_69 ( struct V_71 * V_72 , struct V_66 * V_66 ,
bool V_93 )
{
unsigned long V_32 ;
F_70 ( ! F_71 ( V_66 ) ) ;
F_70 ( V_72 != F_56 ( V_66 ) ) ;
F_72 ( & V_72 -> V_94 , V_32 ) ;
if ( ! F_73 ( V_66 , 2 ) )
goto V_95;
if ( F_74 ( F_75 ( V_66 ) ) ) {
F_76 ( V_66 , 2 ) ;
goto V_95;
}
if ( F_77 ( V_66 ) ) {
T_4 V_96 = { . V_97 = F_78 (page) } ;
F_79 ( V_66 , V_96 ) ;
F_80 ( V_66 ) ;
F_81 ( & V_72 -> V_94 , V_32 ) ;
F_82 ( V_96 ) ;
} else {
void (* F_83)( struct V_66 * );
void * V_98 = NULL ;
F_83 = V_72 -> V_76 -> F_83 ;
if ( V_93 && F_84 ( V_66 ) &&
! F_85 ( V_72 ) && ! F_86 ( V_72 ) )
V_98 = F_87 ( V_72 , V_66 ) ;
F_88 ( V_66 , V_98 ) ;
F_81 ( & V_72 -> V_94 , V_32 ) ;
if ( F_83 != NULL )
F_83 ( V_66 ) ;
}
return 1 ;
V_95:
F_81 ( & V_72 -> V_94 , V_32 ) ;
return 0 ;
}
int F_89 ( struct V_71 * V_72 , struct V_66 * V_66 )
{
if ( F_69 ( V_72 , V_66 , false ) ) {
F_76 ( V_66 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_90 ( struct V_66 * V_66 )
{
bool V_99 ;
int V_100 = F_91 ( V_66 ) ;
F_92 ( F_93 ( V_66 ) , V_66 ) ;
V_101:
F_94 ( V_66 ) ;
if ( F_95 ( V_66 ) ) {
V_99 = false ;
F_96 ( V_66 ) ;
} else {
V_99 = true ;
F_97 ( V_66 ) ;
F_98 () ;
}
if ( V_99 && F_95 ( V_66 ) ) {
if ( ! F_99 ( V_66 ) ) {
F_100 ( V_66 ) ;
goto V_101;
}
}
if ( V_100 && ! V_99 )
F_101 ( V_102 ) ;
else if ( ! V_100 && V_99 )
F_101 ( V_103 ) ;
F_100 ( V_66 ) ;
}
static enum V_104 F_102 ( struct V_66 * V_66 ,
struct V_1 * V_2 )
{
int V_105 , V_106 ;
unsigned long V_107 ;
V_105 = F_103 ( V_66 , 1 , V_2 -> V_3 ,
& V_107 ) ;
V_106 = F_104 ( V_66 ) ;
if ( V_107 & V_108 )
return V_109 ;
if ( V_105 ) {
if ( F_105 ( V_66 ) )
return V_110 ;
F_106 ( V_66 ) ;
if ( V_106 || V_105 > 1 )
return V_110 ;
if ( V_107 & V_111 )
return V_110 ;
return V_112 ;
}
if ( V_106 && ! F_105 ( V_66 ) )
return V_113 ;
return V_109 ;
}
static void F_107 ( struct V_66 * V_66 ,
bool * V_114 , bool * V_115 )
{
struct V_71 * V_72 ;
if ( ! F_84 ( V_66 ) ) {
* V_114 = false ;
* V_115 = false ;
return;
}
* V_114 = F_75 ( V_66 ) ;
* V_115 = F_66 ( V_66 ) ;
if ( ! F_50 ( V_66 ) )
return;
V_72 = F_56 ( V_66 ) ;
if ( V_72 && V_72 -> V_76 -> V_116 )
V_72 -> V_76 -> V_116 ( V_66 , V_114 , V_115 ) ;
}
static unsigned long F_108 ( struct V_117 * V_118 ,
struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_119 V_119 ,
unsigned long * V_120 ,
unsigned long * V_121 ,
unsigned long * V_122 ,
unsigned long * V_123 ,
unsigned long * V_124 ,
bool V_125 )
{
F_109 ( V_126 ) ;
F_109 ( V_127 ) ;
int V_128 = 0 ;
unsigned long V_129 = 0 ;
unsigned long V_130 = 0 ;
unsigned long V_131 = 0 ;
unsigned long V_132 = 0 ;
unsigned long V_133 = 0 ;
unsigned long V_134 = 0 ;
F_34 () ;
while ( ! F_110 ( V_118 ) ) {
struct V_71 * V_72 ;
struct V_66 * V_66 ;
int V_135 ;
enum V_104 V_136 = V_113 ;
bool V_114 , V_115 ;
bool V_137 = false ;
int V_58 = V_138 ;
F_34 () ;
V_66 = F_111 ( V_118 ) ;
F_25 ( & V_66 -> V_24 ) ;
if ( ! F_112 ( V_66 ) )
goto V_139;
F_92 ( F_113 ( V_66 ) , V_66 ) ;
V_2 -> V_42 ++ ;
if ( F_74 ( ! F_95 ( V_66 ) ) )
goto V_140;
if ( ! V_2 -> V_141 && F_114 ( V_66 ) )
goto V_142;
if ( F_114 ( V_66 ) || F_77 ( V_66 ) )
V_2 -> V_42 ++ ;
V_135 = ( V_2 -> V_62 & V_143 ) ||
( F_77 ( V_66 ) && ( V_2 -> V_62 & V_144 ) ) ;
F_107 ( V_66 , & V_114 , & V_115 ) ;
if ( V_114 || V_115 )
V_130 ++ ;
if ( V_114 && ! V_115 )
V_129 ++ ;
V_72 = F_56 ( V_66 ) ;
if ( ( ( V_114 || V_115 ) && V_72 &&
F_52 ( V_72 -> V_79 ) ) ||
( V_115 && F_115 ( V_66 ) ) )
V_131 ++ ;
if ( F_66 ( V_66 ) ) {
if ( F_116 () &&
F_115 ( V_66 ) &&
F_117 ( V_145 , & V_14 -> V_32 ) ) {
V_134 ++ ;
goto V_142;
} else if ( F_2 ( V_2 ) ||
! F_115 ( V_66 ) || ! V_135 ) {
F_64 ( V_66 ) ;
V_133 ++ ;
goto V_142;
} else {
F_58 ( V_66 ) ;
F_118 ( V_66 ) ;
F_22 ( & V_66 -> V_24 , V_118 ) ;
continue;
}
}
if ( ! V_125 )
V_136 = F_102 ( V_66 , V_2 ) ;
switch ( V_136 ) {
case V_110 :
goto V_146;
case V_112 :
goto V_142;
case V_109 :
case V_113 :
;
}
if ( F_119 ( V_66 ) && ! F_77 ( V_66 ) ) {
if ( ! ( V_2 -> V_62 & V_144 ) )
goto V_142;
if ( ! F_120 ( V_66 , V_118 ) )
goto V_146;
V_137 = true ;
V_135 = 1 ;
V_72 = F_56 ( V_66 ) ;
} else if ( F_74 ( F_121 ( V_66 ) ) ) {
if ( F_122 ( V_66 , V_118 ) )
goto V_142;
}
F_92 ( F_121 ( V_66 ) , V_66 ) ;
if ( F_114 ( V_66 ) && V_72 ) {
switch ( V_58 = F_123 ( V_66 , V_137 ?
( V_119 | V_147 | V_148 ) :
( V_119 | V_147 ) ) ) {
case V_149 :
goto V_146;
case V_150 :
goto V_142;
case V_151 :
goto V_140;
case V_152 :
goto V_137;
case V_138 :
;
}
}
if ( F_75 ( V_66 ) ) {
if ( F_84 ( V_66 ) &&
( ! F_116 () ||
! F_117 ( V_153 , & V_14 -> V_32 ) ) ) {
F_68 ( V_66 , V_154 ) ;
F_64 ( V_66 ) ;
goto V_142;
}
if ( V_136 == V_113 )
goto V_142;
if ( ! V_135 )
goto V_142;
if ( ! V_2 -> V_155 )
goto V_142;
F_124 () ;
switch ( F_59 ( V_66 , V_72 , V_2 ) ) {
case V_73 :
goto V_142;
case V_78 :
goto V_146;
case V_92 :
if ( F_66 ( V_66 ) )
goto V_139;
if ( F_75 ( V_66 ) )
goto V_139;
if ( ! F_112 ( V_66 ) )
goto V_139;
if ( F_75 ( V_66 ) || F_66 ( V_66 ) )
goto V_142;
V_72 = F_56 ( V_66 ) ;
case V_75 :
;
}
}
if ( F_50 ( V_66 ) ) {
if ( ! F_125 ( V_66 , V_2 -> V_62 ) )
goto V_146;
if ( ! V_72 && F_49 ( V_66 ) == 1 ) {
F_58 ( V_66 ) ;
if ( F_126 ( V_66 ) )
goto V_156;
else {
V_132 ++ ;
continue;
}
}
}
V_137:
if ( ! V_72 || ! F_69 ( V_72 , V_66 , true ) )
goto V_142;
F_127 ( V_66 ) ;
V_156:
if ( V_58 == V_152 )
F_101 ( V_157 ) ;
V_132 ++ ;
F_128 ( & V_66 -> V_24 , & V_127 ) ;
continue;
V_140:
if ( F_77 ( V_66 ) )
F_129 ( V_66 ) ;
F_58 ( V_66 ) ;
F_128 ( & V_66 -> V_24 , & V_126 ) ;
continue;
V_146:
if ( F_77 ( V_66 ) && F_130 ( V_66 ) )
F_129 ( V_66 ) ;
F_92 ( F_113 ( V_66 ) , V_66 ) ;
F_131 ( V_66 ) ;
V_128 ++ ;
V_142:
F_58 ( V_66 ) ;
V_139:
F_128 ( & V_66 -> V_24 , & V_126 ) ;
F_92 ( F_93 ( V_66 ) || F_91 ( V_66 ) , V_66 ) ;
}
F_132 ( & V_127 ) ;
F_133 () ;
F_134 ( & V_127 , true ) ;
F_135 ( & V_126 , V_118 ) ;
F_33 ( V_158 , V_128 ) ;
* V_120 += V_130 ;
* V_122 += V_131 ;
* V_121 += V_129 ;
* V_123 += V_133 ;
* V_124 += V_134 ;
return V_132 ;
}
unsigned long F_136 ( struct V_7 * V_7 ,
struct V_117 * V_118 )
{
struct V_1 V_2 = {
. V_62 = V_35 ,
. V_159 = V_160 ,
. V_141 = 1 ,
} ;
unsigned long V_58 , V_161 , V_162 , V_163 , V_164 , V_165 ;
struct V_66 * V_66 , * V_166 ;
F_109 ( V_167 ) ;
F_137 (page, next, page_list, lru) {
if ( F_84 ( V_66 ) && ! F_75 ( V_66 ) &&
! F_138 ( V_66 ) ) {
F_139 ( V_66 ) ;
F_140 ( & V_66 -> V_24 , & V_167 ) ;
}
}
V_58 = F_108 ( & V_167 , V_7 -> V_168 , & V_2 ,
V_169 | V_170 ,
& V_161 , & V_162 , & V_163 , & V_164 , & V_165 , true ) ;
F_135 ( & V_167 , V_118 ) ;
F_141 ( V_7 -> V_168 , V_17 , - V_58 ) ;
return V_58 ;
}
int F_142 ( struct V_66 * V_66 , T_5 V_171 )
{
int V_58 = - V_172 ;
if ( ! F_93 ( V_66 ) )
return V_58 ;
if ( F_91 ( V_66 ) && ! ( V_171 & V_173 ) )
return V_58 ;
V_58 = - V_174 ;
if ( V_171 & ( V_175 | V_176 ) ) {
if ( F_66 ( V_66 ) )
return V_58 ;
if ( F_75 ( V_66 ) ) {
struct V_71 * V_72 ;
if ( V_171 & V_175 )
return V_58 ;
V_72 = F_56 ( V_66 ) ;
if ( V_72 && ! V_72 -> V_76 -> V_177 )
return V_58 ;
}
}
if ( ( V_171 & V_178 ) && F_114 ( V_66 ) )
return V_58 ;
if ( F_143 ( F_144 ( V_66 ) ) ) {
F_145 ( V_66 ) ;
V_58 = 0 ;
}
return V_58 ;
}
static T_6 void F_146 ( struct V_22 * V_22 ,
enum V_23 V_24 , unsigned long * V_179 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_181 ; V_180 ++ ) {
if ( ! V_179 [ V_180 ] )
continue;
F_147 ( V_22 , V_24 , V_180 , - V_179 [ V_180 ] ) ;
#ifdef F_148
F_149 ( V_22 , V_24 , V_180 , - V_179 [ V_180 ] ) ;
#endif
}
}
static unsigned long F_150 ( unsigned long V_59 ,
struct V_22 * V_22 , struct V_117 * V_182 ,
unsigned long * V_42 , struct V_1 * V_2 ,
T_5 V_171 , enum V_23 V_24 )
{
struct V_117 * V_183 = & V_22 -> V_184 [ V_24 ] ;
unsigned long V_185 = 0 ;
unsigned long V_179 [ V_181 ] = { 0 } ;
unsigned long V_186 [ V_181 ] = { 0 , } ;
unsigned long V_187 , V_188 ;
F_109 ( V_189 ) ;
for ( V_187 = 0 ; V_187 < V_59 && V_185 < V_59 &&
! F_110 ( V_183 ) ; ) {
struct V_66 * V_66 ;
V_66 = F_111 ( V_183 ) ;
F_151 ( V_66 , V_183 , V_32 ) ;
F_92 ( ! F_93 ( V_66 ) , V_66 ) ;
if ( F_152 ( V_66 ) > V_2 -> V_190 ) {
F_140 ( & V_66 -> V_24 , & V_189 ) ;
V_186 [ F_152 ( V_66 ) ] ++ ;
continue;
}
V_187 ++ ;
switch ( F_142 ( V_66 , V_171 ) ) {
case 0 :
V_188 = F_153 ( V_66 ) ;
V_185 += V_188 ;
V_179 [ F_152 ( V_66 ) ] += V_188 ;
F_140 ( & V_66 -> V_24 , V_182 ) ;
break;
case - V_174 :
F_140 ( & V_66 -> V_24 , V_183 ) ;
continue;
default:
F_154 () ;
}
}
if ( ! F_110 ( & V_189 ) ) {
int V_180 ;
unsigned long V_191 = 0 ;
for ( V_180 = 0 ; V_180 < V_181 ; V_180 ++ ) {
if ( ! V_186 [ V_180 ] )
continue;
F_155 ( V_192 , V_180 , V_186 [ V_180 ] ) ;
V_191 += V_186 [ V_180 ] ;
}
V_187 += F_110 ( V_183 ) ? V_191 : V_191 >> 2 ;
F_135 ( & V_189 , V_183 ) ;
}
* V_42 = V_187 ;
F_156 ( V_2 -> V_190 , V_2 -> V_193 , V_59 , V_187 ,
V_185 , V_171 , F_157 ( V_24 ) ) ;
F_146 ( V_22 , V_24 , V_179 ) ;
return V_185 ;
}
int F_99 ( struct V_66 * V_66 )
{
int V_58 = - V_174 ;
F_92 ( ! F_49 ( V_66 ) , V_66 ) ;
F_158 ( F_159 ( V_66 ) , L_3 ) ;
if ( F_93 ( V_66 ) ) {
struct V_7 * V_7 = F_160 ( V_66 ) ;
struct V_22 * V_22 ;
F_161 ( F_162 ( V_7 ) ) ;
V_22 = F_163 ( V_66 , V_7 -> V_168 ) ;
if ( F_93 ( V_66 ) ) {
int V_24 = F_164 ( V_66 ) ;
F_165 ( V_66 ) ;
F_145 ( V_66 ) ;
F_166 ( V_66 , V_22 , V_24 ) ;
V_58 = 0 ;
}
F_167 ( F_162 ( V_7 ) ) ;
}
return V_58 ;
}
static int F_168 ( struct V_13 * V_14 , int V_194 ,
struct V_1 * V_2 )
{
unsigned long V_195 , V_196 ;
if ( F_116 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_194 ) {
V_195 = F_14 ( V_14 , V_16 ) ;
V_196 = F_14 ( V_14 , V_17 ) ;
} else {
V_195 = F_14 ( V_14 , V_19 ) ;
V_196 = F_14 ( V_14 , V_20 ) ;
}
if ( ( V_2 -> V_62 & ( V_144 | V_143 ) ) == ( V_144 | V_143 ) )
V_195 >>= 3 ;
return V_196 > V_195 ;
}
static T_7 void
F_169 ( struct V_22 * V_22 , struct V_117 * V_118 )
{
struct V_197 * V_198 = & V_22 -> V_198 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
F_109 ( V_199 ) ;
while ( ! F_110 ( V_118 ) ) {
struct V_66 * V_66 = F_111 ( V_118 ) ;
int V_24 ;
F_92 ( F_93 ( V_66 ) , V_66 ) ;
F_25 ( & V_66 -> V_24 ) ;
if ( F_74 ( ! F_95 ( V_66 ) ) ) {
F_167 ( & V_14 -> V_200 ) ;
F_90 ( V_66 ) ;
F_161 ( & V_14 -> V_200 ) ;
continue;
}
V_22 = F_163 ( V_66 , V_14 ) ;
F_170 ( V_66 ) ;
V_24 = F_164 ( V_66 ) ;
F_171 ( V_66 , V_22 , V_24 ) ;
if ( F_172 ( V_24 ) ) {
int V_194 = F_157 ( V_24 ) ;
int V_201 = F_153 ( V_66 ) ;
V_198 -> V_202 [ V_194 ] += V_201 ;
}
if ( F_126 ( V_66 ) ) {
F_173 ( V_66 ) ;
F_174 ( V_66 ) ;
F_166 ( V_66 , V_22 , V_24 ) ;
if ( F_74 ( F_175 ( V_66 ) ) ) {
F_167 ( & V_14 -> V_200 ) ;
F_176 ( V_66 ) ;
( * F_177 ( V_66 ) ) ( V_66 ) ;
F_161 ( & V_14 -> V_200 ) ;
} else
F_128 ( & V_66 -> V_24 , & V_199 ) ;
}
}
F_135 ( & V_199 , V_118 ) ;
}
static int F_178 ( void )
{
return ! ( V_68 -> V_32 & V_203 ) ||
V_68 -> V_70 == NULL ||
F_179 ( V_68 -> V_70 ) ;
}
static bool F_180 ( struct V_22 * V_22 ,
struct V_1 * V_2 , enum V_23 V_24 )
{
int V_180 ;
struct V_7 * V_7 ;
int V_194 = F_157 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
if ( ! F_1 ( V_2 ) )
return true ;
for ( V_180 = V_2 -> V_190 ; V_180 >= 0 ; V_180 -- ) {
V_7 = & V_14 -> V_27 [ V_180 ] ;
if ( ! F_181 ( V_7 ) )
continue;
if ( F_6 ( V_7 , V_28 +
V_204 * V_194 ) >= V_63 )
return true ;
}
return false ;
}
static T_7 unsigned long
F_182 ( unsigned long V_59 , struct V_22 * V_22 ,
struct V_1 * V_2 , enum V_23 V_24 )
{
F_109 ( V_118 ) ;
unsigned long V_42 ;
unsigned long V_132 = 0 ;
unsigned long V_185 ;
unsigned long V_130 = 0 ;
unsigned long V_131 = 0 ;
unsigned long V_129 = 0 ;
unsigned long V_133 = 0 ;
unsigned long V_134 = 0 ;
T_5 V_205 = 0 ;
int V_194 = F_157 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
struct V_197 * V_198 = & V_22 -> V_198 ;
if ( ! F_180 ( V_22 , V_2 , V_24 ) )
return 0 ;
while ( F_74 ( F_168 ( V_14 , V_194 , V_2 ) ) ) {
F_183 ( V_206 , V_207 / 10 ) ;
if ( F_184 ( V_68 ) )
return V_63 ;
}
F_185 () ;
if ( ! V_2 -> V_141 )
V_205 |= V_178 ;
if ( ! V_2 -> V_155 )
V_205 |= V_175 ;
F_161 ( & V_14 -> V_200 ) ;
V_185 = F_150 ( V_59 , V_22 , & V_118 ,
& V_42 , V_2 , V_205 , V_24 ) ;
F_186 ( V_14 , V_20 + V_194 , V_185 ) ;
V_198 -> V_208 [ V_194 ] += V_185 ;
if ( F_1 ( V_2 ) ) {
F_186 ( V_14 , V_21 , V_42 ) ;
if ( F_116 () )
F_187 ( V_209 , V_42 ) ;
else
F_187 ( V_210 , V_42 ) ;
}
F_167 ( & V_14 -> V_200 ) ;
if ( V_185 == 0 )
return 0 ;
V_132 = F_108 ( & V_118 , V_14 , V_2 , V_169 ,
& V_130 , & V_129 , & V_131 ,
& V_133 , & V_134 ,
false ) ;
F_161 ( & V_14 -> V_200 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_116 () )
F_187 ( V_211 , V_132 ) ;
else
F_187 ( V_212 , V_132 ) ;
}
F_169 ( V_22 , & V_118 ) ;
F_186 ( V_14 , V_20 + V_194 , - V_185 ) ;
F_167 ( & V_14 -> V_200 ) ;
F_132 ( & V_118 ) ;
F_134 ( & V_118 , true ) ;
if ( V_133 && V_133 == V_185 )
F_188 ( V_145 , & V_14 -> V_32 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_130 && V_130 == V_131 )
F_188 ( V_213 , & V_14 -> V_32 ) ;
if ( V_129 == V_185 )
F_188 ( V_153 , & V_14 -> V_32 ) ;
if ( V_134 && F_178 () )
F_183 ( V_206 , V_207 / 10 ) ;
}
if ( ! V_2 -> V_214 && ! F_116 () &&
F_178 () )
F_189 ( V_14 , V_206 , V_207 / 10 ) ;
F_190 ( V_14 -> V_215 ,
V_42 , V_132 ,
V_2 -> V_159 , V_194 ) ;
return V_132 ;
}
static void F_191 ( struct V_22 * V_22 ,
struct V_117 * V_38 ,
struct V_117 * V_199 ,
enum V_23 V_24 )
{
struct V_13 * V_14 = F_15 ( V_22 ) ;
unsigned long V_216 = 0 ;
struct V_66 * V_66 ;
int V_188 ;
while ( ! F_110 ( V_38 ) ) {
V_66 = F_111 ( V_38 ) ;
V_22 = F_163 ( V_66 , V_14 ) ;
F_92 ( F_93 ( V_66 ) , V_66 ) ;
F_170 ( V_66 ) ;
V_188 = F_153 ( V_66 ) ;
F_192 ( V_22 , V_24 , F_152 ( V_66 ) , V_188 ) ;
F_140 ( & V_66 -> V_24 , & V_22 -> V_184 [ V_24 ] ) ;
V_216 += V_188 ;
if ( F_126 ( V_66 ) ) {
F_173 ( V_66 ) ;
F_174 ( V_66 ) ;
F_166 ( V_66 , V_22 , V_24 ) ;
if ( F_74 ( F_175 ( V_66 ) ) ) {
F_167 ( & V_14 -> V_200 ) ;
F_176 ( V_66 ) ;
( * F_177 ( V_66 ) ) ( V_66 ) ;
F_161 ( & V_14 -> V_200 ) ;
} else
F_128 ( & V_66 -> V_24 , V_199 ) ;
}
}
if ( ! F_172 ( V_24 ) )
F_187 ( V_217 , V_216 ) ;
}
static void F_193 ( unsigned long V_59 ,
struct V_22 * V_22 ,
struct V_1 * V_2 ,
enum V_23 V_24 )
{
unsigned long V_185 ;
unsigned long V_42 ;
unsigned long V_107 ;
F_109 ( V_218 ) ;
F_109 ( V_219 ) ;
F_109 ( V_220 ) ;
struct V_66 * V_66 ;
struct V_197 * V_198 = & V_22 -> V_198 ;
unsigned long V_221 = 0 ;
T_5 V_205 = 0 ;
int V_194 = F_157 ( V_24 ) ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
F_185 () ;
if ( ! V_2 -> V_141 )
V_205 |= V_178 ;
if ( ! V_2 -> V_155 )
V_205 |= V_175 ;
F_161 ( & V_14 -> V_200 ) ;
V_185 = F_150 ( V_59 , V_22 , & V_218 ,
& V_42 , V_2 , V_205 , V_24 ) ;
F_186 ( V_14 , V_20 + V_194 , V_185 ) ;
V_198 -> V_208 [ V_194 ] += V_185 ;
if ( F_1 ( V_2 ) )
F_186 ( V_14 , V_21 , V_42 ) ;
F_187 ( V_222 , V_42 ) ;
F_167 ( & V_14 -> V_200 ) ;
while ( ! F_110 ( & V_218 ) ) {
F_34 () ;
V_66 = F_111 ( & V_218 ) ;
F_25 ( & V_66 -> V_24 ) ;
if ( F_74 ( ! F_95 ( V_66 ) ) ) {
F_90 ( V_66 ) ;
continue;
}
if ( F_74 ( V_223 ) ) {
if ( F_50 ( V_66 ) && F_112 ( V_66 ) ) {
if ( F_50 ( V_66 ) )
F_125 ( V_66 , 0 ) ;
F_58 ( V_66 ) ;
}
}
if ( F_103 ( V_66 , 0 , V_2 -> V_3 ,
& V_107 ) ) {
V_221 += F_153 ( V_66 ) ;
if ( ( V_107 & V_111 ) && F_84 ( V_66 ) ) {
F_128 ( & V_66 -> V_24 , & V_219 ) ;
continue;
}
}
F_139 ( V_66 ) ;
F_128 ( & V_66 -> V_24 , & V_220 ) ;
}
F_161 ( & V_14 -> V_200 ) ;
V_198 -> V_202 [ V_194 ] += V_221 ;
F_191 ( V_22 , & V_219 , & V_218 , V_24 ) ;
F_191 ( V_22 , & V_220 , & V_218 , V_24 - V_224 ) ;
F_186 ( V_14 , V_20 + V_194 , - V_185 ) ;
F_167 ( & V_14 -> V_200 ) ;
F_132 ( & V_218 ) ;
F_134 ( & V_218 , true ) ;
}
static bool F_194 ( struct V_22 * V_22 , bool V_194 ,
struct V_1 * V_2 )
{
unsigned long V_225 ;
unsigned long V_195 ;
unsigned long V_226 ;
unsigned long V_227 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
int V_180 ;
if ( ! V_194 && ! V_228 )
return false ;
V_195 = F_11 ( V_22 , V_194 * V_204 ) ;
V_226 = F_11 ( V_22 , V_194 * V_204 + V_224 ) ;
for ( V_180 = V_2 -> V_190 + 1 ; V_180 < V_181 ; V_180 ++ ) {
struct V_7 * V_7 = & V_14 -> V_27 [ V_180 ] ;
unsigned long V_229 , V_230 ;
if ( ! F_181 ( V_7 ) )
continue;
V_229 = F_16 ( V_22 , V_194 * V_204 , V_180 ) ;
V_230 = F_16 ( V_22 , ( V_194 * V_204 ) + V_224 , V_180 ) ;
V_195 -= F_31 ( V_195 , V_229 ) ;
V_226 -= F_31 ( V_226 , V_230 ) ;
}
V_227 = ( V_195 + V_226 ) >> ( 30 - V_231 ) ;
if ( V_227 )
V_225 = F_195 ( 10 * V_227 ) ;
else
V_225 = 1 ;
return V_195 * V_225 < V_226 ;
}
static unsigned long F_196 ( enum V_23 V_24 , unsigned long V_59 ,
struct V_22 * V_22 , struct V_1 * V_2 )
{
if ( F_172 ( V_24 ) ) {
if ( F_194 ( V_22 , F_157 ( V_24 ) , V_2 ) )
F_193 ( V_59 , V_22 , V_2 , V_24 ) ;
return 0 ;
}
return F_182 ( V_59 , V_22 , V_2 , V_24 ) ;
}
static void F_197 ( struct V_22 * V_22 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_232 )
{
int V_233 = F_198 ( V_5 ) ;
struct V_197 * V_198 = & V_22 -> V_198 ;
T_8 V_234 [ 2 ] ;
T_8 V_235 = 0 ;
struct V_13 * V_14 = F_15 ( V_22 ) ;
unsigned long V_236 , V_237 ;
enum V_238 V_238 ;
unsigned long V_239 , V_194 ;
bool V_240 = false ;
unsigned long V_241 , V_242 ;
enum V_23 V_24 ;
bool V_243 ;
int V_244 ;
if ( F_116 () ) {
if ( ! F_10 ( V_14 ) )
V_240 = true ;
if ( ! F_40 ( V_5 ) )
V_240 = true ;
}
if ( ! F_1 ( V_2 ) )
V_240 = true ;
if ( ! V_2 -> V_245 || F_199 ( V_5 ) <= 0 ) {
V_238 = V_246 ;
goto V_64;
}
if ( ! F_1 ( V_2 ) && ! V_233 ) {
V_238 = V_246 ;
goto V_64;
}
if ( ! V_2 -> V_159 && V_233 ) {
V_238 = V_247 ;
goto V_64;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_248 ;
unsigned long V_249 ;
int V_250 ;
unsigned long V_251 = 0 ;
V_249 = F_200 ( V_14 -> V_215 , V_252 ) ;
V_248 = F_14 ( V_14 , V_15 ) +
F_14 ( V_14 , V_16 ) ;
for ( V_250 = 0 ; V_250 < V_181 ; V_250 ++ ) {
struct V_7 * V_7 = & V_14 -> V_27 [ V_250 ] ;
if ( ! F_181 ( V_7 ) )
continue;
V_251 += F_201 ( V_7 ) ;
}
if ( F_74 ( V_248 + V_249 <= V_251 ) ) {
V_238 = V_253 ;
goto V_64;
}
}
if ( ! F_194 ( V_22 , true , V_2 ) &&
F_11 ( V_22 , V_254 ) >> V_2 -> V_159 ) {
V_238 = V_246 ;
goto V_64;
}
V_238 = V_255 ;
V_236 = V_233 ;
V_237 = 200 - V_236 ;
V_239 = F_11 ( V_22 , V_256 ) +
F_11 ( V_22 , V_257 ) ;
V_194 = F_11 ( V_22 , V_258 ) +
F_11 ( V_22 , V_254 ) ;
F_161 ( & V_14 -> V_200 ) ;
if ( F_74 ( V_198 -> V_208 [ 0 ] > V_239 / 4 ) ) {
V_198 -> V_208 [ 0 ] /= 2 ;
V_198 -> V_202 [ 0 ] /= 2 ;
}
if ( F_74 ( V_198 -> V_208 [ 1 ] > V_194 / 4 ) ) {
V_198 -> V_208 [ 1 ] /= 2 ;
V_198 -> V_202 [ 1 ] /= 2 ;
}
V_241 = V_236 * ( V_198 -> V_208 [ 0 ] + 1 ) ;
V_241 /= V_198 -> V_202 [ 0 ] + 1 ;
V_242 = V_237 * ( V_198 -> V_208 [ 1 ] + 1 ) ;
V_242 /= V_198 -> V_202 [ 1 ] + 1 ;
F_167 ( & V_14 -> V_200 ) ;
V_234 [ 0 ] = V_241 ;
V_234 [ 1 ] = V_242 ;
V_235 = V_241 + V_242 + 1 ;
V_64:
V_243 = false ;
for ( V_244 = 0 ; ! V_243 && V_244 < 2 ; V_244 ++ ) {
* V_232 = 0 ;
F_202 (lru) {
int V_194 = F_157 ( V_24 ) ;
unsigned long V_30 ;
unsigned long V_187 ;
V_30 = F_11 ( V_22 , V_24 ) ;
V_187 = V_30 >> V_2 -> V_159 ;
if ( ! V_187 && V_244 && V_240 )
V_187 = F_31 ( V_30 , V_63 ) ;
switch ( V_238 ) {
case V_247 :
break;
case V_255 :
V_187 = F_203 ( V_187 * V_234 [ V_194 ] ,
V_235 ) ;
break;
case V_246 :
case V_253 :
if ( ( V_238 == V_246 ) != V_194 ) {
V_30 = 0 ;
V_187 = 0 ;
}
break;
default:
F_154 () ;
}
* V_232 += V_30 ;
V_8 [ V_24 ] = V_187 ;
V_243 |= ! ! V_187 ;
}
}
}
static void F_204 ( struct V_13 * V_14 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_232 )
{
struct V_22 * V_22 = F_205 ( V_14 , V_5 ) ;
unsigned long V_8 [ V_259 ] ;
unsigned long V_260 [ V_259 ] ;
unsigned long V_59 ;
enum V_23 V_24 ;
unsigned long V_132 = 0 ;
unsigned long V_261 = V_2 -> V_261 ;
struct V_262 V_263 ;
bool V_264 ;
F_197 ( V_22 , V_5 , V_2 , V_8 , V_232 ) ;
memcpy ( V_260 , V_8 , sizeof( V_8 ) ) ;
V_264 = ( F_1 ( V_2 ) && ! F_116 () &&
V_2 -> V_159 == V_160 ) ;
F_206 ( & V_263 ) ;
while ( V_8 [ V_257 ] || V_8 [ V_258 ] ||
V_8 [ V_254 ] ) {
unsigned long V_265 , V_266 , V_267 ;
unsigned long V_42 ;
F_202 (lru) {
if ( V_8 [ V_24 ] ) {
V_59 = F_31 ( V_8 [ V_24 ] , V_63 ) ;
V_8 [ V_24 ] -= V_59 ;
V_132 += F_196 ( V_24 , V_59 ,
V_22 , V_2 ) ;
}
}
F_34 () ;
if ( V_132 < V_261 || V_264 )
continue;
V_266 = V_8 [ V_254 ] + V_8 [ V_258 ] ;
V_265 = V_8 [ V_257 ] + V_8 [ V_256 ] ;
if ( ! V_266 || ! V_265 )
break;
if ( V_266 > V_265 ) {
unsigned long V_268 = V_260 [ V_257 ] +
V_260 [ V_256 ] + 1 ;
V_24 = V_269 ;
V_267 = V_265 * 100 / V_268 ;
} else {
unsigned long V_268 = V_260 [ V_254 ] +
V_260 [ V_258 ] + 1 ;
V_24 = V_204 ;
V_267 = V_266 * 100 / V_268 ;
}
V_8 [ V_24 ] = 0 ;
V_8 [ V_24 + V_224 ] = 0 ;
V_24 = ( V_24 == V_204 ) ? V_269 : V_204 ;
V_42 = V_260 [ V_24 ] - V_8 [ V_24 ] ;
V_8 [ V_24 ] = V_260 [ V_24 ] * ( 100 - V_267 ) / 100 ;
V_8 [ V_24 ] -= F_31 ( V_8 [ V_24 ] , V_42 ) ;
V_24 += V_224 ;
V_42 = V_260 [ V_24 ] - V_8 [ V_24 ] ;
V_8 [ V_24 ] = V_260 [ V_24 ] * ( 100 - V_267 ) / 100 ;
V_8 [ V_24 ] -= F_31 ( V_8 [ V_24 ] , V_42 ) ;
V_264 = true ;
}
F_207 ( & V_263 ) ;
V_2 -> V_132 += V_132 ;
if ( F_194 ( V_22 , false , V_2 ) )
F_193 ( V_63 , V_22 ,
V_2 , V_256 ) ;
}
static bool F_208 ( struct V_1 * V_2 )
{
if ( F_209 ( V_270 ) && V_2 -> V_193 &&
( V_2 -> V_193 > V_271 ||
V_2 -> V_159 < V_160 - 2 ) )
return true ;
return false ;
}
static inline bool F_210 ( struct V_13 * V_14 ,
unsigned long V_132 ,
unsigned long V_42 ,
struct V_1 * V_2 )
{
unsigned long V_272 ;
unsigned long V_273 ;
int V_250 ;
if ( ! F_208 ( V_2 ) )
return false ;
if ( V_2 -> V_62 & V_274 ) {
if ( ! V_132 && ! V_42 )
return false ;
} else {
if ( ! V_132 )
return false ;
}
V_272 = F_211 ( V_2 -> V_193 ) ;
V_273 = F_14 ( V_14 , V_16 ) ;
if ( F_7 () > 0 )
V_273 += F_14 ( V_14 , V_19 ) ;
if ( V_2 -> V_132 < V_272 &&
V_273 > V_272 )
return true ;
for ( V_250 = 0 ; V_250 <= V_2 -> V_190 ; V_250 ++ ) {
struct V_7 * V_7 = & V_14 -> V_27 [ V_250 ] ;
if ( ! F_181 ( V_7 ) )
continue;
switch ( F_212 ( V_7 , V_2 -> V_193 , 0 , V_2 -> V_190 ) ) {
case V_275 :
case V_276 :
return false ;
default:
;
}
}
return true ;
}
static bool F_213 ( T_9 * V_14 , struct V_1 * V_2 )
{
struct V_277 * V_277 = V_68 -> V_277 ;
unsigned long V_132 , V_42 ;
bool V_278 = false ;
do {
struct V_4 * V_279 = V_2 -> V_3 ;
struct V_280 V_281 = {
. V_14 = V_14 ,
. V_159 = V_2 -> V_159 ,
} ;
unsigned long V_282 = 0 ;
struct V_4 * V_5 ;
V_132 = V_2 -> V_132 ;
V_42 = V_2 -> V_42 ;
V_5 = F_45 ( V_279 , NULL , & V_281 ) ;
do {
unsigned long V_232 ;
unsigned long V_93 ;
unsigned long V_53 ;
if ( F_214 ( V_279 , V_5 ) ) {
if ( ! V_2 -> V_283 )
continue;
F_215 ( V_5 , V_284 , 1 ) ;
}
V_93 = V_2 -> V_132 ;
V_53 = V_2 -> V_42 ;
F_204 ( V_14 , V_5 , V_2 , & V_232 ) ;
V_282 += V_232 ;
if ( V_5 )
F_38 ( V_2 -> V_62 , V_14 -> V_215 ,
V_5 , V_2 -> V_42 - V_53 ,
V_232 ) ;
F_216 ( V_2 -> V_62 , V_5 , false ,
V_2 -> V_42 - V_53 ,
V_2 -> V_132 - V_93 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_132 >= V_2 -> V_261 ) {
F_217 ( V_279 , V_5 ) ;
break;
}
} while ( ( V_5 = F_45 ( V_279 , V_5 , & V_281 ) ) );
if ( F_1 ( V_2 ) )
F_38 ( V_2 -> V_62 , V_14 -> V_215 , NULL ,
V_2 -> V_42 - V_42 ,
V_282 ) ;
if ( V_277 ) {
V_2 -> V_132 += V_277 -> V_285 ;
V_277 -> V_285 = 0 ;
}
F_216 ( V_2 -> V_62 , V_2 -> V_3 , true ,
V_2 -> V_42 - V_42 ,
V_2 -> V_132 - V_132 ) ;
if ( V_2 -> V_132 - V_132 )
V_278 = true ;
} while ( F_210 ( V_14 , V_2 -> V_132 - V_132 ,
V_2 -> V_42 - V_42 , V_2 ) );
return V_278 ;
}
static inline bool F_218 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
unsigned long V_286 ;
enum V_287 V_288 ;
V_288 = F_212 ( V_7 , V_2 -> V_193 , 0 , V_2 -> V_190 ) ;
if ( V_288 == V_275 )
return true ;
if ( V_288 == V_289 )
return false ;
V_286 = F_201 ( V_7 ) + F_211 ( V_2 -> V_193 ) ;
return F_219 ( V_7 , 0 , V_286 , V_2 -> V_190 ) ;
}
static void F_220 ( struct V_290 * V_290 , struct V_1 * V_2 )
{
struct V_291 * V_250 ;
struct V_7 * V_7 ;
unsigned long V_292 ;
unsigned long V_293 ;
T_2 V_294 ;
T_9 * V_295 = NULL ;
V_294 = V_2 -> V_62 ;
if ( V_223 ) {
V_2 -> V_62 |= V_296 ;
V_2 -> V_190 = F_221 ( V_2 -> V_62 ) ;
}
F_222 (zone, z, zonelist,
sc->reclaim_idx, sc->nodemask) {
if ( F_1 ( V_2 ) ) {
if ( ! F_223 ( V_7 ,
V_35 | V_297 ) )
continue;
if ( V_2 -> V_159 != V_160 &&
! F_10 ( V_7 -> V_168 ) )
continue;
if ( F_209 ( V_270 ) &&
V_2 -> V_193 > V_271 &&
F_218 ( V_7 , V_2 ) ) {
V_2 -> F_218 = true ;
continue;
}
if ( V_7 -> V_168 == V_295 )
continue;
V_293 = 0 ;
V_292 = F_224 ( V_7 -> V_168 ,
V_2 -> V_193 , V_2 -> V_62 ,
& V_293 ) ;
V_2 -> V_132 += V_292 ;
V_2 -> V_42 += V_293 ;
}
if ( V_7 -> V_168 == V_295 )
continue;
V_295 = V_7 -> V_168 ;
F_213 ( V_7 -> V_168 , V_2 ) ;
}
V_2 -> V_62 = V_294 ;
}
static unsigned long F_225 ( struct V_290 * V_290 ,
struct V_1 * V_2 )
{
int V_298 = V_2 -> V_159 ;
unsigned long V_299 = 0 ;
unsigned long V_300 ;
V_301:
F_226 () ;
if ( F_1 ( V_2 ) )
F_155 ( V_302 , V_2 -> V_190 , 1 ) ;
do {
F_227 ( V_2 -> V_62 , V_2 -> V_3 ,
V_2 -> V_159 ) ;
V_2 -> V_42 = 0 ;
F_220 ( V_290 , V_2 ) ;
V_299 += V_2 -> V_42 ;
if ( V_2 -> V_132 >= V_2 -> V_261 )
break;
if ( V_2 -> F_218 )
break;
if ( V_2 -> V_159 < V_160 - 2 )
V_2 -> V_155 = 1 ;
V_300 = V_2 -> V_261 + V_2 -> V_261 / 2 ;
if ( V_299 > V_300 ) {
F_228 ( V_303 ? 0 : V_299 ,
V_304 ) ;
V_2 -> V_155 = 1 ;
}
} while ( -- V_2 -> V_159 >= 0 );
F_229 () ;
if ( V_2 -> V_132 )
return V_2 -> V_132 ;
if ( V_2 -> F_218 )
return 1 ;
if ( ! V_2 -> V_283 ) {
V_2 -> V_159 = V_298 ;
V_2 -> V_283 = 1 ;
goto V_301;
}
return 0 ;
}
static bool F_230 ( T_9 * V_14 )
{
struct V_7 * V_7 ;
unsigned long V_305 = 0 ;
unsigned long V_127 = 0 ;
int V_306 ;
bool V_307 ;
for ( V_306 = 0 ; V_306 <= V_308 ; V_306 ++ ) {
V_7 = & V_14 -> V_27 [ V_306 ] ;
if ( ! F_181 ( V_7 ) ||
F_8 ( V_14 ) == 0 )
continue;
V_305 += F_231 ( V_7 ) ;
V_127 += F_18 ( V_7 , V_252 ) ;
}
if ( ! V_305 )
return true ;
V_307 = V_127 > V_305 / 2 ;
if ( ! V_307 && F_232 ( & V_14 -> V_309 ) ) {
V_14 -> V_310 = F_31 ( V_14 -> V_310 ,
(enum V_311 ) V_308 ) ;
F_233 ( & V_14 -> V_309 ) ;
}
return V_307 ;
}
static bool F_234 ( T_2 V_62 , struct V_290 * V_290 ,
T_10 * V_312 )
{
struct V_291 * V_250 ;
struct V_7 * V_7 ;
T_9 * V_14 = NULL ;
if ( V_68 -> V_32 & V_313 )
goto V_64;
if ( F_184 ( V_68 ) )
goto V_64;
F_222 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( V_26 ( V_7 ) > V_308 )
continue;
V_14 = V_7 -> V_168 ;
if ( F_230 ( V_14 ) )
goto V_64;
break;
}
if ( ! V_14 )
goto V_64;
F_101 ( V_314 ) ;
if ( ! ( V_62 & V_143 ) ) {
F_235 ( V_14 -> V_315 ,
F_230 ( V_14 ) , V_207 ) ;
goto V_316;
}
F_236 ( V_7 -> V_168 -> V_315 ,
F_230 ( V_14 ) ) ;
V_316:
if ( F_184 ( V_68 ) )
return true ;
V_64:
return false ;
}
unsigned long F_237 ( struct V_290 * V_290 , int V_193 ,
T_2 V_62 , T_10 * V_312 )
{
unsigned long V_132 ;
struct V_1 V_2 = {
. V_261 = V_63 ,
. V_62 = ( V_62 = F_238 ( V_62 ) ) ,
. V_190 = F_221 ( V_62 ) ,
. V_193 = V_193 ,
. V_312 = V_312 ,
. V_159 = V_160 ,
. V_155 = ! V_303 ,
. V_141 = 1 ,
. V_245 = 1 ,
} ;
if ( F_234 ( V_62 , V_290 , V_312 ) )
return 1 ;
F_239 ( V_193 ,
V_2 . V_155 ,
V_62 ,
V_2 . V_190 ) ;
V_132 = F_225 ( V_290 , & V_2 ) ;
F_240 ( V_132 ) ;
return V_132 ;
}
unsigned long F_241 ( struct V_4 * V_5 ,
T_2 V_62 , bool V_317 ,
T_9 * V_14 ,
unsigned long * V_42 )
{
struct V_1 V_2 = {
. V_261 = V_63 ,
. V_3 = V_5 ,
. V_155 = ! V_303 ,
. V_141 = 1 ,
. V_190 = V_181 - 1 ,
. V_245 = ! V_317 ,
} ;
unsigned long V_232 ;
V_2 . V_62 = ( V_62 & V_318 ) |
( V_319 & ~ V_318 ) ;
F_242 ( V_2 . V_193 ,
V_2 . V_155 ,
V_2 . V_62 ,
V_2 . V_190 ) ;
F_204 ( V_14 , V_5 , & V_2 , & V_232 ) ;
F_243 ( V_2 . V_132 ) ;
* V_42 = V_2 . V_42 ;
return V_2 . V_132 ;
}
unsigned long F_244 ( struct V_4 * V_5 ,
unsigned long V_188 ,
T_2 V_62 ,
bool V_245 )
{
struct V_290 * V_290 ;
unsigned long V_132 ;
int V_49 ;
struct V_1 V_2 = {
. V_261 = F_245 ( V_188 , V_63 ) ,
. V_62 = ( V_62 & V_318 ) |
( V_319 & ~ V_318 ) ,
. V_190 = V_181 - 1 ,
. V_3 = V_5 ,
. V_159 = V_160 ,
. V_155 = ! V_303 ,
. V_141 = 1 ,
. V_245 = V_245 ,
} ;
V_49 = F_246 ( V_5 ) ;
V_290 = & F_247 ( V_49 ) -> V_320 [ V_321 ] ;
F_248 ( 0 ,
V_2 . V_155 ,
V_2 . V_62 ,
V_2 . V_190 ) ;
V_68 -> V_32 |= V_322 ;
V_132 = F_225 ( V_290 , & V_2 ) ;
V_68 -> V_32 &= ~ V_322 ;
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
struct V_22 * V_22 = F_205 ( V_14 , V_5 ) ;
if ( F_194 ( V_22 , false , V_2 ) )
F_193 ( V_63 , V_22 ,
V_2 , V_256 ) ;
V_5 = F_45 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_251 ( struct V_7 * V_7 , int V_193 , int V_323 )
{
unsigned long V_324 = F_201 ( V_7 ) ;
if ( ! F_219 ( V_7 , V_193 , V_324 , V_323 ) )
return false ;
F_252 ( V_213 , & V_7 -> V_168 -> V_32 ) ;
F_252 ( V_153 , & V_7 -> V_168 -> V_32 ) ;
return true ;
}
static bool F_253 ( T_9 * V_14 , int V_193 , int V_323 )
{
int V_306 ;
if ( F_232 ( & V_14 -> V_315 ) )
F_254 ( & V_14 -> V_315 ) ;
for ( V_306 = 0 ; V_306 <= V_323 ; V_306 ++ ) {
struct V_7 * V_7 = V_14 -> V_27 + V_306 ;
if ( ! F_181 ( V_7 ) )
continue;
if ( ! F_251 ( V_7 , V_193 , V_323 ) )
return false ;
}
return true ;
}
static bool F_255 ( T_9 * V_14 ,
struct V_1 * V_2 )
{
struct V_7 * V_7 ;
int V_250 ;
V_2 -> V_261 = 0 ;
for ( V_250 = 0 ; V_250 <= V_2 -> V_190 ; V_250 ++ ) {
V_7 = V_14 -> V_27 + V_250 ;
if ( ! F_181 ( V_7 ) )
continue;
V_2 -> V_261 += F_245 ( F_201 ( V_7 ) , V_63 ) ;
}
F_213 ( V_14 , V_2 ) ;
if ( V_2 -> V_193 && V_2 -> V_132 >= F_211 ( V_2 -> V_193 ) )
V_2 -> V_193 = 0 ;
return V_2 -> V_42 >= V_2 -> V_261 ;
}
static int F_256 ( T_9 * V_14 , int V_193 , int V_323 )
{
int V_306 ;
unsigned long V_292 ;
unsigned long V_293 ;
struct V_7 * V_7 ;
struct V_1 V_2 = {
. V_62 = V_35 ,
. V_193 = V_193 ,
. V_159 = V_160 ,
. V_155 = ! V_303 ,
. V_141 = 1 ,
. V_245 = 1 ,
} ;
F_101 ( V_325 ) ;
do {
bool V_326 = true ;
V_2 . V_132 = 0 ;
V_2 . V_190 = V_323 ;
if ( V_223 ) {
for ( V_306 = V_181 - 1 ; V_306 >= 0 ; V_306 -- ) {
V_7 = V_14 -> V_27 + V_306 ;
if ( ! F_181 ( V_7 ) )
continue;
V_2 . V_190 = V_306 ;
break;
}
}
for ( V_306 = V_323 ; V_306 >= 0 ; V_306 -- ) {
V_7 = V_14 -> V_27 + V_306 ;
if ( ! F_181 ( V_7 ) )
continue;
if ( F_251 ( V_7 , V_2 . V_193 , V_323 ) )
goto V_64;
}
F_250 ( V_14 , & V_2 ) ;
if ( V_2 . V_159 < V_160 - 2 || ! F_10 ( V_14 ) )
V_2 . V_155 = 1 ;
V_2 . V_42 = 0 ;
V_293 = 0 ;
V_292 = F_224 ( V_14 , V_2 . V_193 ,
V_2 . V_62 , & V_293 ) ;
V_2 . V_132 += V_292 ;
if ( F_255 ( V_14 , & V_2 ) )
V_326 = false ;
if ( F_232 ( & V_14 -> V_315 ) &&
F_230 ( V_14 ) )
F_254 ( & V_14 -> V_315 ) ;
if ( F_257 () || F_258 () )
break;
if ( V_326 || ! V_2 . V_132 )
V_2 . V_159 -- ;
} while ( V_2 . V_159 >= 1 );
V_64:
return V_2 . V_193 ;
}
static void F_259 ( T_9 * V_14 , int V_327 , int V_328 ,
unsigned int V_323 )
{
long V_329 = 0 ;
F_260 ( V_330 ) ;
if ( F_261 ( V_68 ) || F_258 () )
return;
F_262 ( & V_14 -> V_309 , & V_330 , V_331 ) ;
if ( F_253 ( V_14 , V_328 , V_323 ) ) {
F_263 ( V_14 ) ;
F_264 ( V_14 , V_327 , V_323 ) ;
V_329 = F_265 ( V_207 / 10 ) ;
if ( V_329 ) {
V_14 -> V_310 = F_245 ( V_14 -> V_310 , V_323 ) ;
V_14 -> V_332 = F_245 ( V_14 -> V_332 , V_328 ) ;
}
F_266 ( & V_14 -> V_309 , & V_330 ) ;
F_262 ( & V_14 -> V_309 , & V_330 , V_331 ) ;
}
if ( ! V_329 &&
F_253 ( V_14 , V_328 , V_323 ) ) {
F_267 ( V_14 -> V_215 ) ;
F_268 ( V_14 , V_333 ) ;
if ( ! F_258 () )
F_269 () ;
F_268 ( V_14 , V_334 ) ;
} else {
if ( V_329 )
F_101 ( V_335 ) ;
else
F_101 ( V_336 ) ;
}
F_266 ( & V_14 -> V_309 , & V_330 ) ;
}
static int F_270 ( void * V_337 )
{
unsigned int V_327 , V_328 , V_323 ;
T_9 * V_14 = ( T_9 * ) V_337 ;
struct V_338 * V_339 = V_68 ;
struct V_277 V_277 = {
. V_285 = 0 ,
} ;
const struct V_340 * V_340 = F_271 ( V_14 -> V_215 ) ;
F_272 ( V_35 ) ;
if ( ! F_273 ( V_340 ) )
F_274 ( V_339 , V_340 ) ;
V_68 -> V_277 = & V_277 ;
V_339 -> V_32 |= V_322 | V_69 | V_341 ;
F_275 () ;
V_14 -> V_332 = V_327 = V_328 = 0 ;
V_14 -> V_310 = V_323 = 0 ;
for ( ; ; ) {
bool V_58 ;
V_342:
F_259 ( V_14 , V_327 , V_328 ,
V_323 ) ;
V_327 = V_328 = V_14 -> V_332 ;
V_323 = V_14 -> V_310 ;
V_14 -> V_332 = 0 ;
V_14 -> V_310 = 0 ;
V_58 = F_257 () ;
if ( F_258 () )
break;
if ( V_58 )
continue;
F_276 ( V_14 -> V_215 , V_323 ,
V_327 ) ;
V_328 = F_256 ( V_14 , V_327 , V_323 ) ;
if ( V_328 < V_327 )
goto V_342;
V_327 = V_328 = V_14 -> V_332 ;
V_323 = V_14 -> V_310 ;
}
V_339 -> V_32 &= ~ ( V_322 | V_69 | V_341 ) ;
V_68 -> V_277 = NULL ;
F_277 () ;
return 0 ;
}
void F_278 ( struct V_7 * V_7 , int V_193 , enum V_311 V_323 )
{
T_9 * V_14 ;
int V_250 ;
if ( ! F_181 ( V_7 ) )
return;
if ( ! F_223 ( V_7 , V_35 | V_297 ) )
return;
V_14 = V_7 -> V_168 ;
V_14 -> V_310 = F_245 ( V_14 -> V_310 , V_323 ) ;
V_14 -> V_332 = F_245 ( V_14 -> V_332 , V_193 ) ;
if ( ! F_232 ( & V_14 -> V_309 ) )
return;
for ( V_250 = 0 ; V_250 <= V_323 ; V_250 ++ ) {
V_7 = V_14 -> V_27 + V_250 ;
if ( ! F_181 ( V_7 ) )
continue;
if ( F_251 ( V_7 , V_193 , V_323 ) )
return;
}
F_279 ( V_14 -> V_215 , V_26 ( V_7 ) , V_193 ) ;
F_233 ( & V_14 -> V_309 ) ;
}
unsigned long F_280 ( unsigned long V_261 )
{
struct V_277 V_277 ;
struct V_1 V_2 = {
. V_261 = V_261 ,
. V_62 = V_319 ,
. V_190 = V_181 - 1 ,
. V_159 = V_160 ,
. V_155 = 1 ,
. V_141 = 1 ,
. V_245 = 1 ,
. V_214 = 1 ,
} ;
struct V_290 * V_290 = F_281 ( F_282 () , V_2 . V_62 ) ;
struct V_338 * V_337 = V_68 ;
unsigned long V_132 ;
V_337 -> V_32 |= V_322 ;
F_272 ( V_2 . V_62 ) ;
V_277 . V_285 = 0 ;
V_337 -> V_277 = & V_277 ;
V_132 = F_225 ( V_290 , & V_2 ) ;
V_337 -> V_277 = NULL ;
F_277 () ;
V_337 -> V_32 &= ~ V_322 ;
return V_132 ;
}
static int F_283 ( unsigned int V_343 )
{
int V_49 ;
F_284 (nid, N_MEMORY) {
T_9 * V_14 = F_247 ( V_49 ) ;
const struct V_340 * V_344 ;
V_344 = F_271 ( V_14 -> V_215 ) ;
if ( F_285 ( V_345 , V_344 ) < V_346 )
F_274 ( V_14 -> F_270 , V_344 ) ;
}
return 0 ;
}
int F_286 ( int V_49 )
{
T_9 * V_14 = F_247 ( V_49 ) ;
int V_58 = 0 ;
if ( V_14 -> F_270 )
return 0 ;
V_14 -> F_270 = F_287 ( F_270 , V_14 , L_4 , V_49 ) ;
if ( F_288 ( V_14 -> F_270 ) ) {
F_70 ( V_347 == V_348 ) ;
F_30 ( L_5 , V_49 ) ;
V_58 = F_289 ( V_14 -> F_270 ) ;
V_14 -> F_270 = NULL ;
}
return V_58 ;
}
void F_290 ( int V_49 )
{
struct V_338 * F_270 = F_247 ( V_49 ) -> F_270 ;
if ( F_270 ) {
F_291 ( F_270 ) ;
F_247 ( V_49 ) -> F_270 = NULL ;
}
}
static int T_11 F_292 ( void )
{
int V_49 , V_58 ;
F_293 () ;
F_284 (nid, N_MEMORY)
F_286 ( V_49 ) ;
V_58 = F_294 ( V_349 ,
L_6 , F_283 ,
NULL ) ;
F_295 ( V_58 < 0 ) ;
return 0 ;
}
static inline unsigned long F_296 ( struct V_13 * V_14 )
{
unsigned long V_350 = F_14 ( V_14 , V_351 ) ;
unsigned long V_352 = F_14 ( V_14 , V_16 ) +
F_14 ( V_14 , V_15 ) ;
return ( V_352 > V_350 ) ? ( V_352 - V_350 ) : 0 ;
}
static unsigned long F_297 ( struct V_13 * V_14 )
{
unsigned long V_353 ;
unsigned long V_45 = 0 ;
if ( V_354 & V_355 )
V_353 = F_14 ( V_14 , V_356 ) ;
else
V_353 = F_296 ( V_14 ) ;
if ( ! ( V_354 & V_357 ) )
V_45 += F_14 ( V_14 , V_358 ) ;
if ( F_74 ( V_45 > V_353 ) )
V_45 = V_353 ;
return V_353 - V_45 ;
}
static int F_298 ( struct V_13 * V_14 , T_2 V_62 , unsigned int V_193 )
{
const unsigned long V_188 = 1 << V_193 ;
struct V_338 * V_337 = V_68 ;
struct V_277 V_277 ;
int V_323 = F_221 ( V_62 ) ;
struct V_1 V_2 = {
. V_261 = F_245 ( V_188 , V_63 ) ,
. V_62 = ( V_62 = F_238 ( V_62 ) ) ,
. V_193 = V_193 ,
. V_159 = V_359 ,
. V_155 = ! ! ( V_354 & V_357 ) ,
. V_141 = ! ! ( V_354 & V_355 ) ,
. V_245 = 1 ,
. V_190 = V_323 ,
} ;
F_34 () ;
V_337 -> V_32 |= V_322 | V_69 ;
F_272 ( V_62 ) ;
V_277 . V_285 = 0 ;
V_337 -> V_277 = & V_277 ;
if ( F_297 ( V_14 ) > V_14 -> V_360 ) {
do {
F_213 ( V_14 , & V_2 ) ;
} while ( V_2 . V_132 < V_188 && -- V_2 . V_159 >= 0 );
}
V_337 -> V_277 = NULL ;
V_68 -> V_32 &= ~ ( V_322 | V_69 ) ;
F_277 () ;
return V_2 . V_132 >= V_188 ;
}
int F_299 ( struct V_13 * V_14 , T_2 V_62 , unsigned int V_193 )
{
int V_58 ;
if ( F_297 ( V_14 ) <= V_14 -> V_360 &&
F_200 ( V_14 -> V_215 , V_361 ) <= V_14 -> V_362 )
return V_363 ;
if ( ! F_10 ( V_14 ) )
return V_363 ;
if ( ! F_300 ( V_62 ) || ( V_68 -> V_32 & V_322 ) )
return V_364 ;
if ( F_301 ( V_14 -> V_215 , V_365 ) && V_14 -> V_215 != F_282 () )
return V_364 ;
if ( F_302 ( V_366 , & V_14 -> V_32 ) )
return V_364 ;
V_58 = F_298 ( V_14 , V_62 , V_193 ) ;
F_252 ( V_366 , & V_14 -> V_32 ) ;
if ( ! V_58 )
F_101 ( V_367 ) ;
return V_58 ;
}
int F_95 ( struct V_66 * V_66 )
{
return ! F_303 ( F_56 ( V_66 ) ) && ! F_304 ( V_66 ) ;
}
void F_305 ( struct V_66 * * V_368 , int V_188 )
{
struct V_22 * V_22 ;
struct V_13 * V_14 = NULL ;
int V_369 = 0 ;
int V_370 = 0 ;
int V_306 ;
for ( V_306 = 0 ; V_306 < V_188 ; V_306 ++ ) {
struct V_66 * V_66 = V_368 [ V_306 ] ;
struct V_13 * V_371 = F_306 ( V_66 ) ;
V_369 ++ ;
if ( V_371 != V_14 ) {
if ( V_14 )
F_167 ( & V_14 -> V_200 ) ;
V_14 = V_371 ;
F_161 ( & V_14 -> V_200 ) ;
}
V_22 = F_163 ( V_66 , V_14 ) ;
if ( ! F_93 ( V_66 ) || ! F_91 ( V_66 ) )
continue;
if ( F_95 ( V_66 ) ) {
enum V_23 V_24 = F_307 ( V_66 ) ;
F_92 ( F_113 ( V_66 ) , V_66 ) ;
F_94 ( V_66 ) ;
F_166 ( V_66 , V_22 , V_372 ) ;
F_171 ( V_66 , V_22 , V_24 ) ;
V_370 ++ ;
}
}
if ( V_14 ) {
F_187 ( V_102 , V_370 ) ;
F_187 ( V_373 , V_369 ) ;
F_167 ( & V_14 -> V_200 ) ;
}
}
