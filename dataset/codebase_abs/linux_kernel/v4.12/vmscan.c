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
unsigned long F_10 ( struct V_21 * V_21 , enum V_22 V_23 , int V_24 )
{
unsigned long V_25 ;
int V_26 ;
if ( ! F_11 () )
V_25 = F_12 ( V_21 , V_23 ) ;
else
V_25 = F_13 ( F_14 ( V_21 ) , V_27 + V_23 ) ;
for ( V_26 = V_24 + 1 ; V_26 < V_28 ; V_26 ++ ) {
struct V_7 * V_7 = & F_14 ( V_21 ) -> V_29 [ V_26 ] ;
unsigned long V_30 ;
if ( ! F_15 ( V_7 ) )
continue;
if ( ! F_11 () )
V_30 = F_16 ( V_21 , V_23 , V_26 ) ;
else
V_30 = F_17 ( & F_14 ( V_21 ) -> V_29 [ V_26 ] ,
V_31 + V_23 ) ;
V_25 -= F_18 ( V_30 , V_25 ) ;
}
return V_25 ;
}
int F_19 ( struct V_32 * V_32 )
{
T_1 V_30 = sizeof( * V_32 -> V_33 ) ;
if ( V_32 -> V_34 & V_35 )
V_30 *= V_36 ;
V_32 -> V_33 = F_20 ( V_30 , V_37 ) ;
if ( ! V_32 -> V_33 )
return - V_38 ;
F_21 ( & V_39 ) ;
F_22 ( & V_32 -> V_40 , & V_41 ) ;
F_23 ( & V_39 ) ;
return 0 ;
}
void F_24 ( struct V_32 * V_32 )
{
F_21 ( & V_39 ) ;
F_25 ( & V_32 -> V_40 ) ;
F_23 ( & V_39 ) ;
F_26 ( V_32 -> V_33 ) ;
}
static unsigned long F_27 ( struct V_42 * V_43 ,
struct V_32 * V_32 ,
unsigned long V_44 ,
unsigned long V_45 )
{
unsigned long V_46 = 0 ;
unsigned long long V_47 ;
long V_48 ;
long V_49 ;
long V_8 ;
long V_50 ;
int V_51 = V_43 -> V_51 ;
long V_52 = V_32 -> V_53 ? V_32 -> V_53
: V_54 ;
long V_55 = 0 , V_56 ;
V_49 = V_32 -> V_57 ( V_32 , V_43 ) ;
if ( V_49 == 0 )
return 0 ;
V_8 = F_28 ( & V_32 -> V_33 [ V_51 ] , 0 ) ;
V_48 = V_8 ;
V_47 = ( 4 * V_44 ) / V_32 -> V_58 ;
V_47 *= V_49 ;
F_29 ( V_47 , V_45 + 1 ) ;
V_48 += V_47 ;
if ( V_48 < 0 ) {
F_30 ( L_1 ,
V_32 -> V_59 , V_48 ) ;
V_48 = V_49 ;
V_56 = V_8 ;
} else
V_56 = V_48 ;
if ( V_47 < V_49 / 4 )
V_48 = F_18 ( V_48 , V_49 / 2 ) ;
if ( V_48 > V_49 * 2 )
V_48 = V_49 * 2 ;
F_31 ( V_32 , V_43 , V_8 ,
V_44 , V_45 ,
V_49 , V_47 , V_48 ) ;
while ( V_48 >= V_52 ||
V_48 >= V_49 ) {
unsigned long V_60 ;
unsigned long V_61 = F_18 ( V_52 , V_48 ) ;
V_43 -> V_61 = V_61 ;
V_60 = V_32 -> V_59 ( V_32 , V_43 ) ;
if ( V_60 == V_62 )
break;
V_46 += V_60 ;
F_32 ( V_63 , V_61 ) ;
V_48 -= V_61 ;
V_55 += V_61 ;
F_33 () ;
}
if ( V_56 >= V_55 )
V_56 -= V_55 ;
else
V_56 = 0 ;
if ( V_56 > 0 )
V_50 = F_34 ( V_56 ,
& V_32 -> V_33 [ V_51 ] ) ;
else
V_50 = F_35 ( & V_32 -> V_33 [ V_51 ] ) ;
F_36 ( V_32 , V_51 , V_46 , V_8 , V_50 , V_48 ) ;
return V_46 ;
}
static unsigned long F_37 ( T_2 V_64 , int V_51 ,
struct V_4 * V_5 ,
unsigned long V_44 ,
unsigned long V_45 )
{
struct V_32 * V_32 ;
unsigned long V_46 = 0 ;
if ( V_5 && ( ! F_38 () || ! F_39 ( V_5 ) ) )
return 0 ;
if ( V_44 == 0 )
V_44 = V_65 ;
if ( ! F_40 ( & V_39 ) ) {
V_46 = 1 ;
goto V_66;
}
F_41 (shrinker, &shrinker_list, list) {
struct V_42 V_2 = {
. V_64 = V_64 ,
. V_51 = V_51 ,
. V_5 = V_5 ,
} ;
if ( F_38 () &&
! ! V_5 != ! ! ( V_32 -> V_34 & V_67 ) )
continue;
if ( ! ( V_32 -> V_34 & V_35 ) )
V_2 . V_51 = 0 ;
V_46 += F_27 ( & V_2 , V_32 , V_44 , V_45 ) ;
}
F_42 ( & V_39 ) ;
V_66:
F_33 () ;
return V_46 ;
}
void F_43 ( int V_51 )
{
unsigned long V_46 ;
do {
struct V_4 * V_5 = NULL ;
V_46 = 0 ;
do {
V_46 += F_37 ( V_37 , V_51 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_44 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_46 > 10 );
}
void F_45 ( void )
{
int V_51 ;
F_46 (nid)
F_43 ( V_51 ) ;
}
static inline int F_47 ( struct V_68 * V_68 )
{
return F_48 ( V_68 ) - F_49 ( V_68 ) == 2 ;
}
static int F_50 ( struct V_69 * V_69 , struct V_1 * V_2 )
{
if ( V_70 -> V_34 & V_71 )
return 1 ;
if ( ! F_51 ( V_69 ) )
return 1 ;
if ( F_52 ( V_69 ) == V_70 -> V_72 )
return 1 ;
return 0 ;
}
static void F_53 ( struct V_73 * V_74 ,
struct V_68 * V_68 , int error )
{
F_54 ( V_68 ) ;
if ( F_55 ( V_68 ) == V_74 )
F_56 ( V_74 , error ) ;
F_57 ( V_68 ) ;
}
static T_3 F_58 ( struct V_68 * V_68 , struct V_73 * V_74 ,
struct V_1 * V_2 )
{
if ( ! F_47 ( V_68 ) )
return V_75 ;
if ( ! V_74 ) {
if ( F_49 ( V_68 ) ) {
if ( F_59 ( V_68 ) ) {
F_60 ( V_68 ) ;
F_61 ( L_2 , V_76 ) ;
return V_77 ;
}
}
return V_75 ;
}
if ( V_74 -> V_78 -> V_79 == NULL )
return V_80 ;
if ( ! F_50 ( V_74 -> V_81 , V_2 ) )
return V_75 ;
if ( F_62 ( V_68 ) ) {
int V_82 ;
struct V_83 V_84 = {
. V_85 = V_86 ,
. V_87 = V_65 ,
. V_88 = 0 ,
. V_89 = V_90 ,
. V_91 = 1 ,
} ;
F_63 ( V_68 ) ;
V_82 = V_74 -> V_78 -> V_79 ( V_68 , & V_84 ) ;
if ( V_82 < 0 )
F_53 ( V_74 , V_68 , V_82 ) ;
if ( V_82 == V_92 ) {
F_64 ( V_68 ) ;
return V_80 ;
}
if ( ! F_65 ( V_68 ) ) {
F_64 ( V_68 ) ;
}
F_66 ( V_68 ) ;
F_67 ( V_68 , V_93 ) ;
return V_94 ;
}
return V_77 ;
}
static int F_68 ( struct V_73 * V_74 , struct V_68 * V_68 ,
bool V_95 )
{
unsigned long V_34 ;
F_69 ( ! F_70 ( V_68 ) ) ;
F_69 ( V_74 != F_55 ( V_68 ) ) ;
F_71 ( & V_74 -> V_96 , V_34 ) ;
if ( ! F_72 ( V_68 , 2 ) )
goto V_97;
if ( F_73 ( F_74 ( V_68 ) ) ) {
F_75 ( V_68 , 2 ) ;
goto V_97;
}
if ( F_76 ( V_68 ) ) {
T_4 V_98 = { . V_99 = F_77 (page) } ;
F_78 ( V_68 , V_98 ) ;
F_79 ( V_68 ) ;
F_80 ( & V_74 -> V_96 , V_34 ) ;
F_81 ( V_98 ) ;
} else {
void (* F_82)( struct V_68 * );
void * V_100 = NULL ;
F_82 = V_74 -> V_78 -> F_82 ;
if ( V_95 && F_83 ( V_68 ) &&
! F_84 ( V_74 ) && ! F_85 ( V_74 ) )
V_100 = F_86 ( V_74 , V_68 ) ;
F_87 ( V_68 , V_100 ) ;
F_80 ( & V_74 -> V_96 , V_34 ) ;
if ( F_82 != NULL )
F_82 ( V_68 ) ;
}
return 1 ;
V_97:
F_80 ( & V_74 -> V_96 , V_34 ) ;
return 0 ;
}
int F_88 ( struct V_73 * V_74 , struct V_68 * V_68 )
{
if ( F_68 ( V_74 , V_68 , false ) ) {
F_75 ( V_68 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_89 ( struct V_68 * V_68 )
{
bool V_101 ;
int V_102 = F_90 ( V_68 ) ;
F_91 ( F_92 ( V_68 ) , V_68 ) ;
V_103:
F_93 ( V_68 ) ;
if ( F_94 ( V_68 ) ) {
V_101 = false ;
F_95 ( V_68 ) ;
} else {
V_101 = true ;
F_96 ( V_68 ) ;
F_97 () ;
}
if ( V_101 && F_94 ( V_68 ) ) {
if ( ! F_98 ( V_68 ) ) {
F_99 ( V_68 ) ;
goto V_103;
}
}
if ( V_102 && ! V_101 )
F_100 ( V_104 ) ;
else if ( ! V_102 && V_101 )
F_100 ( V_105 ) ;
F_99 ( V_68 ) ;
}
static enum V_106 F_101 ( struct V_68 * V_68 ,
struct V_1 * V_2 )
{
int V_107 , V_108 ;
unsigned long V_109 ;
V_107 = F_102 ( V_68 , 1 , V_2 -> V_3 ,
& V_109 ) ;
V_108 = F_103 ( V_68 ) ;
if ( V_109 & V_110 )
return V_111 ;
if ( V_107 ) {
if ( F_104 ( V_68 ) )
return V_112 ;
F_105 ( V_68 ) ;
if ( V_108 || V_107 > 1 )
return V_112 ;
if ( V_109 & V_113 )
return V_112 ;
return V_114 ;
}
if ( V_108 && ! F_104 ( V_68 ) )
return V_115 ;
return V_111 ;
}
static void F_106 ( struct V_68 * V_68 ,
bool * V_116 , bool * V_117 )
{
struct V_73 * V_74 ;
if ( ! F_83 ( V_68 ) ||
( F_107 ( V_68 ) && ! F_104 ( V_68 ) ) ) {
* V_116 = false ;
* V_117 = false ;
return;
}
* V_116 = F_74 ( V_68 ) ;
* V_117 = F_65 ( V_68 ) ;
if ( ! F_49 ( V_68 ) )
return;
V_74 = F_55 ( V_68 ) ;
if ( V_74 && V_74 -> V_78 -> V_118 )
V_74 -> V_78 -> V_118 ( V_68 , V_116 , V_117 ) ;
}
static unsigned long F_108 ( struct V_119 * V_120 ,
struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_121 V_121 ,
struct V_122 * V_123 ,
bool V_124 )
{
F_109 ( V_125 ) ;
F_109 ( V_126 ) ;
int V_127 = 0 ;
unsigned V_128 = 0 ;
unsigned V_129 = 0 ;
unsigned V_130 = 0 ;
unsigned V_131 = 0 ;
unsigned V_132 = 0 ;
unsigned V_133 = 0 ;
unsigned V_134 = 0 ;
unsigned V_135 = 0 ;
F_33 () ;
while ( ! F_110 ( V_120 ) ) {
struct V_73 * V_74 ;
struct V_68 * V_68 ;
int V_136 ;
enum V_106 V_137 = V_115 ;
bool V_116 , V_117 ;
F_33 () ;
V_68 = F_111 ( V_120 ) ;
F_25 ( & V_68 -> V_23 ) ;
if ( ! F_112 ( V_68 ) )
goto V_138;
F_91 ( F_113 ( V_68 ) , V_68 ) ;
V_2 -> V_44 ++ ;
if ( F_73 ( ! F_94 ( V_68 ) ) )
goto V_139;
if ( ! V_2 -> V_140 && F_114 ( V_68 ) )
goto V_141;
if ( ( F_114 ( V_68 ) || F_76 ( V_68 ) ) &&
! ( F_107 ( V_68 ) && ! F_104 ( V_68 ) ) )
V_2 -> V_44 ++ ;
V_136 = ( V_2 -> V_64 & V_142 ) ||
( F_76 ( V_68 ) && ( V_2 -> V_64 & V_143 ) ) ;
F_106 ( V_68 , & V_116 , & V_117 ) ;
if ( V_116 || V_117 )
V_129 ++ ;
if ( V_116 && ! V_117 )
V_128 ++ ;
V_74 = F_55 ( V_68 ) ;
if ( ( ( V_116 || V_117 ) && V_74 &&
F_51 ( V_74 -> V_81 ) ) ||
( V_117 && F_115 ( V_68 ) ) )
V_130 ++ ;
if ( F_65 ( V_68 ) ) {
if ( F_116 () &&
F_115 ( V_68 ) &&
F_117 ( V_144 , & V_14 -> V_34 ) ) {
V_133 ++ ;
goto V_139;
} else if ( F_2 ( V_2 ) ||
! F_115 ( V_68 ) || ! V_136 ) {
F_63 ( V_68 ) ;
V_132 ++ ;
goto V_139;
} else {
F_57 ( V_68 ) ;
F_118 ( V_68 ) ;
F_22 ( & V_68 -> V_23 , V_120 ) ;
continue;
}
}
if ( ! V_124 )
V_137 = F_101 ( V_68 , V_2 ) ;
switch ( V_137 ) {
case V_112 :
goto V_139;
case V_114 :
V_134 ++ ;
goto V_141;
case V_111 :
case V_115 :
;
}
if ( F_107 ( V_68 ) && F_104 ( V_68 ) &&
! F_76 ( V_68 ) ) {
if ( ! ( V_2 -> V_64 & V_143 ) )
goto V_141;
if ( ! F_119 ( V_68 , V_120 ) )
goto V_139;
V_136 = 1 ;
V_74 = F_55 ( V_68 ) ;
} else if ( F_73 ( F_120 ( V_68 ) ) ) {
if ( F_121 ( V_68 , V_120 ) )
goto V_141;
}
F_91 ( F_120 ( V_68 ) , V_68 ) ;
if ( F_114 ( V_68 ) ) {
if ( ! F_122 ( V_68 , V_121 | V_145 ) ) {
V_135 ++ ;
goto V_139;
}
}
if ( F_74 ( V_68 ) ) {
if ( F_83 ( V_68 ) &&
( ! F_116 () || ! F_115 ( V_68 ) ||
! F_117 ( V_146 , & V_14 -> V_34 ) ) ) {
F_67 ( V_68 , V_147 ) ;
F_63 ( V_68 ) ;
goto V_139;
}
if ( V_137 == V_115 )
goto V_141;
if ( ! V_136 )
goto V_141;
if ( ! V_2 -> V_148 )
goto V_141;
F_123 () ;
switch ( F_58 ( V_68 , V_74 , V_2 ) ) {
case V_75 :
goto V_141;
case V_80 :
goto V_139;
case V_94 :
if ( F_65 ( V_68 ) )
goto V_138;
if ( F_74 ( V_68 ) )
goto V_138;
if ( ! F_112 ( V_68 ) )
goto V_138;
if ( F_74 ( V_68 ) || F_65 ( V_68 ) )
goto V_141;
V_74 = F_55 ( V_68 ) ;
case V_77 :
;
}
}
if ( F_49 ( V_68 ) ) {
if ( ! F_124 ( V_68 , V_2 -> V_64 ) )
goto V_139;
if ( ! V_74 && F_48 ( V_68 ) == 1 ) {
F_57 ( V_68 ) ;
if ( F_125 ( V_68 ) )
goto V_149;
else {
V_131 ++ ;
continue;
}
}
}
if ( F_107 ( V_68 ) && ! F_104 ( V_68 ) ) {
if ( ! F_72 ( V_68 , 1 ) )
goto V_141;
if ( F_74 ( V_68 ) ) {
F_75 ( V_68 , 1 ) ;
goto V_141;
}
F_100 ( V_150 ) ;
} else if ( ! V_74 || ! F_68 ( V_74 , V_68 , true ) )
goto V_141;
F_126 ( V_68 ) ;
V_149:
V_131 ++ ;
F_127 ( & V_68 -> V_23 , & V_126 ) ;
continue;
V_139:
if ( F_76 ( V_68 ) && ( F_128 ( V_68 ) ||
F_129 ( V_68 ) ) )
F_130 ( V_68 ) ;
F_91 ( F_113 ( V_68 ) , V_68 ) ;
if ( ! F_129 ( V_68 ) ) {
F_131 ( V_68 ) ;
V_127 ++ ;
}
V_141:
F_57 ( V_68 ) ;
V_138:
F_127 ( & V_68 -> V_23 , & V_125 ) ;
F_91 ( F_92 ( V_68 ) || F_90 ( V_68 ) , V_68 ) ;
}
F_132 ( & V_126 ) ;
F_133 () ;
F_134 ( & V_126 , true ) ;
F_135 ( & V_125 , V_120 ) ;
F_32 ( V_151 , V_127 ) ;
if ( V_123 ) {
V_123 -> V_129 = V_129 ;
V_123 -> V_130 = V_130 ;
V_123 -> V_128 = V_128 ;
V_123 -> V_132 = V_132 ;
V_123 -> V_133 = V_133 ;
V_123 -> V_152 = V_127 ;
V_123 -> V_134 = V_134 ;
V_123 -> V_135 = V_135 ;
}
return V_131 ;
}
unsigned long F_136 ( struct V_7 * V_7 ,
struct V_119 * V_120 )
{
struct V_1 V_2 = {
. V_64 = V_37 ,
. V_153 = V_154 ,
. V_140 = 1 ,
} ;
unsigned long V_60 ;
struct V_68 * V_68 , * V_155 ;
F_109 ( V_156 ) ;
F_137 (page, next, page_list, lru) {
if ( F_83 ( V_68 ) && ! F_74 ( V_68 ) &&
! F_138 ( V_68 ) ) {
F_139 ( V_68 ) ;
F_140 ( & V_68 -> V_23 , & V_156 ) ;
}
}
V_60 = F_108 ( & V_156 , V_7 -> V_157 , & V_2 ,
V_158 , NULL , true ) ;
F_135 ( & V_156 , V_120 ) ;
F_141 ( V_7 -> V_157 , V_17 , - V_60 ) ;
return V_60 ;
}
int F_142 ( struct V_68 * V_68 , T_5 V_159 )
{
int V_60 = - V_160 ;
if ( ! F_92 ( V_68 ) )
return V_60 ;
if ( F_90 ( V_68 ) && ! ( V_159 & V_161 ) )
return V_60 ;
V_60 = - V_162 ;
if ( V_159 & V_163 ) {
if ( F_65 ( V_68 ) )
return V_60 ;
if ( F_74 ( V_68 ) ) {
struct V_73 * V_74 ;
V_74 = F_55 ( V_68 ) ;
if ( V_74 && ! V_74 -> V_78 -> V_164 )
return V_60 ;
}
}
if ( ( V_159 & V_165 ) && F_114 ( V_68 ) )
return V_60 ;
if ( F_143 ( F_144 ( V_68 ) ) ) {
F_145 ( V_68 ) ;
V_60 = 0 ;
}
return V_60 ;
}
static T_6 void F_146 ( struct V_21 * V_21 ,
enum V_22 V_23 , unsigned long * V_166 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( ! V_166 [ V_26 ] )
continue;
F_147 ( V_21 , V_23 , V_26 , - V_166 [ V_26 ] ) ;
#ifdef F_148
F_149 ( V_21 , V_23 , V_26 , - V_166 [ V_26 ] ) ;
#endif
}
}
static unsigned long F_150 ( unsigned long V_61 ,
struct V_21 * V_21 , struct V_119 * V_167 ,
unsigned long * V_44 , struct V_1 * V_2 ,
T_5 V_159 , enum V_22 V_23 )
{
struct V_119 * V_168 = & V_21 -> V_169 [ V_23 ] ;
unsigned long V_170 = 0 ;
unsigned long V_166 [ V_28 ] = { 0 } ;
unsigned long V_171 [ V_28 ] = { 0 , } ;
unsigned long V_172 = 0 ;
unsigned long V_173 , V_48 , V_174 ;
F_109 ( V_175 ) ;
V_173 = 0 ;
for ( V_48 = 0 ;
V_173 < V_61 && V_170 < V_61 && ! F_110 ( V_168 ) ;
V_48 ++ ) {
struct V_68 * V_68 ;
V_68 = F_111 ( V_168 ) ;
F_151 ( V_68 , V_168 , V_34 ) ;
F_91 ( ! F_92 ( V_68 ) , V_68 ) ;
if ( F_152 ( V_68 ) > V_2 -> V_176 ) {
F_140 ( & V_68 -> V_23 , & V_175 ) ;
V_171 [ F_152 ( V_68 ) ] ++ ;
continue;
}
V_173 ++ ;
switch ( F_142 ( V_68 , V_159 ) ) {
case 0 :
V_174 = F_153 ( V_68 ) ;
V_170 += V_174 ;
V_166 [ F_152 ( V_68 ) ] += V_174 ;
F_140 ( & V_68 -> V_23 , V_167 ) ;
break;
case - V_162 :
F_140 ( & V_68 -> V_23 , V_168 ) ;
continue;
default:
F_154 () ;
}
}
if ( ! F_110 ( & V_175 ) ) {
int V_26 ;
F_135 ( & V_175 , V_168 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( ! V_171 [ V_26 ] )
continue;
F_155 ( V_177 , V_26 , V_171 [ V_26 ] ) ;
V_172 += V_171 [ V_26 ] ;
}
}
* V_44 = V_48 ;
F_156 ( V_2 -> V_176 , V_2 -> V_178 , V_61 ,
V_48 , V_172 , V_170 , V_159 , V_23 ) ;
F_146 ( V_21 , V_23 , V_166 ) ;
return V_170 ;
}
int F_98 ( struct V_68 * V_68 )
{
int V_60 = - V_162 ;
F_91 ( ! F_48 ( V_68 ) , V_68 ) ;
F_157 ( F_158 ( V_68 ) , L_3 ) ;
if ( F_92 ( V_68 ) ) {
struct V_7 * V_7 = F_159 ( V_68 ) ;
struct V_21 * V_21 ;
F_160 ( F_161 ( V_7 ) ) ;
V_21 = F_162 ( V_68 , V_7 -> V_157 ) ;
if ( F_92 ( V_68 ) ) {
int V_23 = F_163 ( V_68 ) ;
F_164 ( V_68 ) ;
F_145 ( V_68 ) ;
F_165 ( V_68 , V_21 , V_23 ) ;
V_60 = 0 ;
}
F_166 ( F_161 ( V_7 ) ) ;
}
return V_60 ;
}
static int F_167 ( struct V_13 * V_14 , int V_179 ,
struct V_1 * V_2 )
{
unsigned long V_180 , V_181 ;
if ( F_116 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_179 ) {
V_180 = F_13 ( V_14 , V_16 ) ;
V_181 = F_13 ( V_14 , V_17 ) ;
} else {
V_180 = F_13 ( V_14 , V_19 ) ;
V_181 = F_13 ( V_14 , V_20 ) ;
}
if ( ( V_2 -> V_64 & ( V_143 | V_142 ) ) == ( V_143 | V_142 ) )
V_180 >>= 3 ;
return V_181 > V_180 ;
}
static T_7 void
F_168 ( struct V_21 * V_21 , struct V_119 * V_120 )
{
struct V_182 * V_122 = & V_21 -> V_122 ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
F_109 ( V_183 ) ;
while ( ! F_110 ( V_120 ) ) {
struct V_68 * V_68 = F_111 ( V_120 ) ;
int V_23 ;
F_91 ( F_92 ( V_68 ) , V_68 ) ;
F_25 ( & V_68 -> V_23 ) ;
if ( F_73 ( ! F_94 ( V_68 ) ) ) {
F_166 ( & V_14 -> V_184 ) ;
F_89 ( V_68 ) ;
F_160 ( & V_14 -> V_184 ) ;
continue;
}
V_21 = F_162 ( V_68 , V_14 ) ;
F_169 ( V_68 ) ;
V_23 = F_163 ( V_68 ) ;
F_170 ( V_68 , V_21 , V_23 ) ;
if ( F_171 ( V_23 ) ) {
int V_179 = F_172 ( V_23 ) ;
int V_185 = F_153 ( V_68 ) ;
V_122 -> V_186 [ V_179 ] += V_185 ;
}
if ( F_125 ( V_68 ) ) {
F_173 ( V_68 ) ;
F_174 ( V_68 ) ;
F_165 ( V_68 , V_21 , V_23 ) ;
if ( F_73 ( F_175 ( V_68 ) ) ) {
F_166 ( & V_14 -> V_184 ) ;
F_176 ( V_68 ) ;
( * F_177 ( V_68 ) ) ( V_68 ) ;
F_160 ( & V_14 -> V_184 ) ;
} else
F_127 ( & V_68 -> V_23 , & V_183 ) ;
}
}
F_135 ( & V_183 , V_120 ) ;
}
static int F_178 ( void )
{
return ! ( V_70 -> V_34 & V_187 ) ||
V_70 -> V_72 == NULL ||
F_179 ( V_70 -> V_72 ) ;
}
static T_7 unsigned long
F_180 ( unsigned long V_61 , struct V_21 * V_21 ,
struct V_1 * V_2 , enum V_22 V_23 )
{
F_109 ( V_120 ) ;
unsigned long V_44 ;
unsigned long V_131 = 0 ;
unsigned long V_170 ;
struct V_122 V_123 = {} ;
T_5 V_188 = 0 ;
int V_179 = F_172 ( V_23 ) ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
struct V_182 * V_122 = & V_21 -> V_122 ;
while ( F_73 ( F_167 ( V_14 , V_179 , V_2 ) ) ) {
F_181 ( V_189 , V_190 / 10 ) ;
if ( F_182 ( V_70 ) )
return V_65 ;
}
F_183 () ;
if ( ! V_2 -> V_140 )
V_188 |= V_165 ;
F_160 ( & V_14 -> V_184 ) ;
V_170 = F_150 ( V_61 , V_21 , & V_120 ,
& V_44 , V_2 , V_188 , V_23 ) ;
F_184 ( V_14 , V_20 + V_179 , V_170 ) ;
V_122 -> V_191 [ V_179 ] += V_170 ;
if ( F_1 ( V_2 ) ) {
if ( F_116 () )
F_185 ( V_192 , V_44 ) ;
else
F_185 ( V_193 , V_44 ) ;
}
F_166 ( & V_14 -> V_184 ) ;
if ( V_170 == 0 )
return 0 ;
V_131 = F_108 ( & V_120 , V_14 , V_2 , 0 ,
& V_123 , false ) ;
F_160 ( & V_14 -> V_184 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_116 () )
F_185 ( V_194 , V_131 ) ;
else
F_185 ( V_195 , V_131 ) ;
}
F_168 ( V_21 , & V_120 ) ;
F_184 ( V_14 , V_20 + V_179 , - V_170 ) ;
F_166 ( & V_14 -> V_184 ) ;
F_132 ( & V_120 ) ;
F_134 ( & V_120 , true ) ;
if ( V_123 . V_132 && V_123 . V_132 == V_170 )
F_186 ( V_144 , & V_14 -> V_34 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_123 . V_129 && V_123 . V_129 == V_123 . V_130 )
F_186 ( V_196 , & V_14 -> V_34 ) ;
if ( V_123 . V_128 == V_170 ) {
F_187 ( 0 , V_197 ) ;
F_186 ( V_146 , & V_14 -> V_34 ) ;
}
if ( V_123 . V_133 && F_178 () )
F_181 ( V_189 , V_190 / 10 ) ;
}
if ( ! V_2 -> V_198 && ! F_116 () &&
F_178 () )
F_188 ( V_14 , V_189 , V_190 / 10 ) ;
F_189 ( V_14 -> V_199 ,
V_44 , V_131 ,
V_123 . V_129 , V_123 . V_132 ,
V_123 . V_130 , V_123 . V_133 ,
V_123 . V_152 , V_123 . V_134 ,
V_123 . V_135 ,
V_2 -> V_153 , V_179 ) ;
return V_131 ;
}
static unsigned F_190 ( struct V_21 * V_21 ,
struct V_119 * V_40 ,
struct V_119 * V_183 ,
enum V_22 V_23 )
{
struct V_13 * V_14 = F_14 ( V_21 ) ;
struct V_68 * V_68 ;
int V_174 ;
int V_200 = 0 ;
while ( ! F_110 ( V_40 ) ) {
V_68 = F_111 ( V_40 ) ;
V_21 = F_162 ( V_68 , V_14 ) ;
F_91 ( F_92 ( V_68 ) , V_68 ) ;
F_169 ( V_68 ) ;
V_174 = F_153 ( V_68 ) ;
F_191 ( V_21 , V_23 , F_152 ( V_68 ) , V_174 ) ;
F_140 ( & V_68 -> V_23 , & V_21 -> V_169 [ V_23 ] ) ;
if ( F_125 ( V_68 ) ) {
F_173 ( V_68 ) ;
F_174 ( V_68 ) ;
F_165 ( V_68 , V_21 , V_23 ) ;
if ( F_73 ( F_175 ( V_68 ) ) ) {
F_166 ( & V_14 -> V_184 ) ;
F_176 ( V_68 ) ;
( * F_177 ( V_68 ) ) ( V_68 ) ;
F_160 ( & V_14 -> V_184 ) ;
} else
F_127 ( & V_68 -> V_23 , V_183 ) ;
} else {
V_200 += V_174 ;
}
}
if ( ! F_171 ( V_23 ) )
F_185 ( V_201 , V_200 ) ;
return V_200 ;
}
static void F_192 ( unsigned long V_61 ,
struct V_21 * V_21 ,
struct V_1 * V_2 ,
enum V_22 V_23 )
{
unsigned long V_170 ;
unsigned long V_44 ;
unsigned long V_109 ;
F_109 ( V_202 ) ;
F_109 ( V_203 ) ;
F_109 ( V_204 ) ;
struct V_68 * V_68 ;
struct V_182 * V_122 = & V_21 -> V_122 ;
unsigned V_205 , V_152 ;
unsigned V_206 = 0 ;
T_5 V_188 = 0 ;
int V_179 = F_172 ( V_23 ) ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
F_183 () ;
if ( ! V_2 -> V_140 )
V_188 |= V_165 ;
F_160 ( & V_14 -> V_184 ) ;
V_170 = F_150 ( V_61 , V_21 , & V_202 ,
& V_44 , V_2 , V_188 , V_23 ) ;
F_184 ( V_14 , V_20 + V_179 , V_170 ) ;
V_122 -> V_191 [ V_179 ] += V_170 ;
F_185 ( V_207 , V_44 ) ;
F_166 ( & V_14 -> V_184 ) ;
while ( ! F_110 ( & V_202 ) ) {
F_33 () ;
V_68 = F_111 ( & V_202 ) ;
F_25 ( & V_68 -> V_23 ) ;
if ( F_73 ( ! F_94 ( V_68 ) ) ) {
F_89 ( V_68 ) ;
continue;
}
if ( F_73 ( V_208 ) ) {
if ( F_49 ( V_68 ) && F_112 ( V_68 ) ) {
if ( F_49 ( V_68 ) )
F_124 ( V_68 , 0 ) ;
F_57 ( V_68 ) ;
}
}
if ( F_102 ( V_68 , 0 , V_2 -> V_3 ,
& V_109 ) ) {
V_206 += F_153 ( V_68 ) ;
if ( ( V_109 & V_113 ) && F_83 ( V_68 ) ) {
F_127 ( & V_68 -> V_23 , & V_203 ) ;
continue;
}
}
F_139 ( V_68 ) ;
F_127 ( & V_68 -> V_23 , & V_204 ) ;
}
F_160 ( & V_14 -> V_184 ) ;
V_122 -> V_186 [ V_179 ] += V_206 ;
V_152 = F_190 ( V_21 , & V_203 , & V_202 , V_23 ) ;
V_205 = F_190 ( V_21 , & V_204 , & V_202 , V_23 - V_209 ) ;
F_184 ( V_14 , V_20 + V_179 , - V_170 ) ;
F_166 ( & V_14 -> V_184 ) ;
F_132 ( & V_202 ) ;
F_134 ( & V_202 , true ) ;
F_193 ( V_14 -> V_199 , V_170 , V_152 ,
V_205 , V_206 , V_2 -> V_153 , V_179 ) ;
}
static bool F_194 ( struct V_21 * V_21 , bool V_179 ,
struct V_4 * V_5 ,
struct V_1 * V_2 , bool V_210 )
{
enum V_22 V_211 = V_179 * V_212 + V_209 ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
enum V_22 V_213 = V_179 * V_212 ;
unsigned long V_180 , V_214 ;
unsigned long V_215 ;
unsigned long V_216 ;
unsigned long V_217 ;
if ( ! V_179 && ! V_218 )
return false ;
V_180 = F_10 ( V_21 , V_213 , V_2 -> V_176 ) ;
V_214 = F_10 ( V_21 , V_211 , V_2 -> V_176 ) ;
if ( V_5 )
V_216 = F_195 ( V_5 , V_219 ) ;
else
V_216 = F_13 ( V_14 , V_219 ) ;
if ( V_179 && V_210 && V_21 -> V_216 != V_216 ) {
V_215 = 0 ;
} else {
V_217 = ( V_180 + V_214 ) >> ( 30 - V_220 ) ;
if ( V_217 )
V_215 = F_196 ( 10 * V_217 ) ;
else
V_215 = 1 ;
}
if ( V_210 )
F_197 ( V_14 -> V_199 , V_2 -> V_176 ,
F_10 ( V_21 , V_213 , V_28 ) , V_180 ,
F_10 ( V_21 , V_211 , V_28 ) , V_214 ,
V_215 , V_179 ) ;
return V_180 * V_215 < V_214 ;
}
static unsigned long F_198 ( enum V_22 V_23 , unsigned long V_61 ,
struct V_21 * V_21 , struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_171 ( V_23 ) ) {
if ( F_194 ( V_21 , F_172 ( V_23 ) ,
V_5 , V_2 , true ) )
F_192 ( V_61 , V_21 , V_2 , V_23 ) ;
return 0 ;
}
return F_180 ( V_61 , V_21 , V_2 , V_23 ) ;
}
static void F_199 ( struct V_21 * V_21 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_221 )
{
int V_222 = F_200 ( V_5 ) ;
struct V_182 * V_122 = & V_21 -> V_122 ;
T_8 V_223 [ 2 ] ;
T_8 V_224 = 0 ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
unsigned long V_225 , V_226 ;
enum V_227 V_227 ;
unsigned long V_228 , V_179 ;
unsigned long V_229 , V_230 ;
enum V_22 V_23 ;
if ( ! V_2 -> V_231 || F_201 ( V_5 ) <= 0 ) {
V_227 = V_232 ;
goto V_66;
}
if ( ! F_1 ( V_2 ) && ! V_222 ) {
V_227 = V_232 ;
goto V_66;
}
if ( ! V_2 -> V_153 && V_222 ) {
V_227 = V_233 ;
goto V_66;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_234 ;
unsigned long V_235 ;
int V_236 ;
unsigned long V_237 = 0 ;
V_235 = F_202 ( V_14 -> V_199 , V_238 ) ;
V_234 = F_13 ( V_14 , V_15 ) +
F_13 ( V_14 , V_16 ) ;
for ( V_236 = 0 ; V_236 < V_28 ; V_236 ++ ) {
struct V_7 * V_7 = & V_14 -> V_29 [ V_236 ] ;
if ( ! F_15 ( V_7 ) )
continue;
V_237 += F_203 ( V_7 ) ;
}
if ( F_73 ( V_234 + V_235 <= V_237 ) ) {
V_227 = V_239 ;
goto V_66;
}
}
if ( ! F_194 ( V_21 , true , V_5 , V_2 , false ) &&
F_10 ( V_21 , V_240 , V_2 -> V_176 ) >> V_2 -> V_153 ) {
V_227 = V_232 ;
goto V_66;
}
V_227 = V_241 ;
V_225 = V_222 ;
V_226 = 200 - V_225 ;
V_228 = F_10 ( V_21 , V_242 , V_28 ) +
F_10 ( V_21 , V_243 , V_28 ) ;
V_179 = F_10 ( V_21 , V_244 , V_28 ) +
F_10 ( V_21 , V_240 , V_28 ) ;
F_160 ( & V_14 -> V_184 ) ;
if ( F_73 ( V_122 -> V_191 [ 0 ] > V_228 / 4 ) ) {
V_122 -> V_191 [ 0 ] /= 2 ;
V_122 -> V_186 [ 0 ] /= 2 ;
}
if ( F_73 ( V_122 -> V_191 [ 1 ] > V_179 / 4 ) ) {
V_122 -> V_191 [ 1 ] /= 2 ;
V_122 -> V_186 [ 1 ] /= 2 ;
}
V_229 = V_225 * ( V_122 -> V_191 [ 0 ] + 1 ) ;
V_229 /= V_122 -> V_186 [ 0 ] + 1 ;
V_230 = V_226 * ( V_122 -> V_191 [ 1 ] + 1 ) ;
V_230 /= V_122 -> V_186 [ 1 ] + 1 ;
F_166 ( & V_14 -> V_184 ) ;
V_223 [ 0 ] = V_229 ;
V_223 [ 1 ] = V_230 ;
V_224 = V_229 + V_230 + 1 ;
V_66:
* V_221 = 0 ;
F_204 (lru) {
int V_179 = F_172 ( V_23 ) ;
unsigned long V_30 ;
unsigned long V_173 ;
V_30 = F_10 ( V_21 , V_23 , V_2 -> V_176 ) ;
V_173 = V_30 >> V_2 -> V_153 ;
if ( ! V_173 && ! F_39 ( V_5 ) )
V_173 = F_18 ( V_30 , V_65 ) ;
switch ( V_227 ) {
case V_233 :
break;
case V_241 :
V_173 = F_205 ( V_173 * V_223 [ V_179 ] ,
V_224 ) ;
break;
case V_232 :
case V_239 :
if ( ( V_227 == V_232 ) != V_179 ) {
V_30 = 0 ;
V_173 = 0 ;
}
break;
default:
F_154 () ;
}
* V_221 += V_30 ;
V_8 [ V_23 ] = V_173 ;
}
}
static void F_206 ( struct V_13 * V_14 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_221 )
{
struct V_21 * V_21 = F_207 ( V_14 , V_5 ) ;
unsigned long V_8 [ V_245 ] ;
unsigned long V_246 [ V_245 ] ;
unsigned long V_61 ;
enum V_22 V_23 ;
unsigned long V_131 = 0 ;
unsigned long V_247 = V_2 -> V_247 ;
struct V_248 V_249 ;
bool V_250 ;
F_199 ( V_21 , V_5 , V_2 , V_8 , V_221 ) ;
memcpy ( V_246 , V_8 , sizeof( V_8 ) ) ;
V_250 = ( F_1 ( V_2 ) && ! F_116 () &&
V_2 -> V_153 == V_154 ) ;
F_208 ( & V_249 ) ;
while ( V_8 [ V_243 ] || V_8 [ V_244 ] ||
V_8 [ V_240 ] ) {
unsigned long V_251 , V_252 , V_253 ;
unsigned long V_44 ;
F_204 (lru) {
if ( V_8 [ V_23 ] ) {
V_61 = F_18 ( V_8 [ V_23 ] , V_65 ) ;
V_8 [ V_23 ] -= V_61 ;
V_131 += F_198 ( V_23 , V_61 ,
V_21 , V_5 , V_2 ) ;
}
}
F_33 () ;
if ( V_131 < V_247 || V_250 )
continue;
V_252 = V_8 [ V_240 ] + V_8 [ V_244 ] ;
V_251 = V_8 [ V_243 ] + V_8 [ V_242 ] ;
if ( ! V_252 || ! V_251 )
break;
if ( V_252 > V_251 ) {
unsigned long V_254 = V_246 [ V_243 ] +
V_246 [ V_242 ] + 1 ;
V_23 = V_255 ;
V_253 = V_251 * 100 / V_254 ;
} else {
unsigned long V_254 = V_246 [ V_240 ] +
V_246 [ V_244 ] + 1 ;
V_23 = V_212 ;
V_253 = V_252 * 100 / V_254 ;
}
V_8 [ V_23 ] = 0 ;
V_8 [ V_23 + V_209 ] = 0 ;
V_23 = ( V_23 == V_212 ) ? V_255 : V_212 ;
V_44 = V_246 [ V_23 ] - V_8 [ V_23 ] ;
V_8 [ V_23 ] = V_246 [ V_23 ] * ( 100 - V_253 ) / 100 ;
V_8 [ V_23 ] -= F_18 ( V_8 [ V_23 ] , V_44 ) ;
V_23 += V_209 ;
V_44 = V_246 [ V_23 ] - V_8 [ V_23 ] ;
V_8 [ V_23 ] = V_246 [ V_23 ] * ( 100 - V_253 ) / 100 ;
V_8 [ V_23 ] -= F_18 ( V_8 [ V_23 ] , V_44 ) ;
V_250 = true ;
}
F_209 ( & V_249 ) ;
V_2 -> V_131 += V_131 ;
if ( F_194 ( V_21 , false , V_5 , V_2 , true ) )
F_192 ( V_65 , V_21 ,
V_2 , V_242 ) ;
}
static bool F_210 ( struct V_1 * V_2 )
{
if ( F_211 ( V_256 ) && V_2 -> V_178 &&
( V_2 -> V_178 > V_257 ||
V_2 -> V_153 < V_154 - 2 ) )
return true ;
return false ;
}
static inline bool F_212 ( struct V_13 * V_14 ,
unsigned long V_131 ,
unsigned long V_44 ,
struct V_1 * V_2 )
{
unsigned long V_258 ;
unsigned long V_259 ;
int V_236 ;
if ( ! F_210 ( V_2 ) )
return false ;
if ( V_2 -> V_64 & V_260 ) {
if ( ! V_131 && ! V_44 )
return false ;
} else {
if ( ! V_131 )
return false ;
}
V_258 = F_213 ( V_2 -> V_178 ) ;
V_259 = F_13 ( V_14 , V_16 ) ;
if ( F_7 () > 0 )
V_259 += F_13 ( V_14 , V_19 ) ;
if ( V_2 -> V_131 < V_258 &&
V_259 > V_258 )
return true ;
for ( V_236 = 0 ; V_236 <= V_2 -> V_176 ; V_236 ++ ) {
struct V_7 * V_7 = & V_14 -> V_29 [ V_236 ] ;
if ( ! F_15 ( V_7 ) )
continue;
switch ( F_214 ( V_7 , V_2 -> V_178 , 0 , V_2 -> V_176 ) ) {
case V_261 :
case V_262 :
return false ;
default:
;
}
}
return true ;
}
static bool F_215 ( T_9 * V_14 , struct V_1 * V_2 )
{
struct V_263 * V_263 = V_70 -> V_263 ;
unsigned long V_131 , V_44 ;
bool V_264 = false ;
do {
struct V_4 * V_265 = V_2 -> V_3 ;
struct V_266 V_267 = {
. V_14 = V_14 ,
. V_153 = V_2 -> V_153 ,
} ;
unsigned long V_268 = 0 ;
struct V_4 * V_5 ;
V_131 = V_2 -> V_131 ;
V_44 = V_2 -> V_44 ;
V_5 = F_44 ( V_265 , NULL , & V_267 ) ;
do {
unsigned long V_221 ;
unsigned long V_95 ;
unsigned long V_55 ;
if ( F_216 ( V_265 , V_5 ) ) {
if ( ! V_2 -> V_269 ) {
V_2 -> V_270 = 1 ;
continue;
}
F_217 ( V_5 , V_271 ) ;
}
V_95 = V_2 -> V_131 ;
V_55 = V_2 -> V_44 ;
F_206 ( V_14 , V_5 , V_2 , & V_221 ) ;
V_268 += V_221 ;
if ( V_5 )
F_37 ( V_2 -> V_64 , V_14 -> V_199 ,
V_5 , V_2 -> V_44 - V_55 ,
V_221 ) ;
F_218 ( V_2 -> V_64 , V_5 , false ,
V_2 -> V_44 - V_55 ,
V_2 -> V_131 - V_95 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_131 >= V_2 -> V_247 ) {
F_219 ( V_265 , V_5 ) ;
break;
}
} while ( ( V_5 = F_44 ( V_265 , V_5 , & V_267 ) ) );
if ( F_1 ( V_2 ) )
F_37 ( V_2 -> V_64 , V_14 -> V_199 , NULL ,
V_2 -> V_44 - V_44 ,
V_268 ) ;
if ( V_263 ) {
V_2 -> V_131 += V_263 -> V_272 ;
V_263 -> V_272 = 0 ;
}
F_218 ( V_2 -> V_64 , V_2 -> V_3 , true ,
V_2 -> V_44 - V_44 ,
V_2 -> V_131 - V_131 ) ;
if ( V_2 -> V_131 - V_131 )
V_264 = true ;
} while ( F_212 ( V_14 , V_2 -> V_131 - V_131 ,
V_2 -> V_44 - V_44 , V_2 ) );
if ( V_264 )
V_14 -> V_273 = 0 ;
return V_264 ;
}
static inline bool F_220 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
unsigned long V_274 ;
enum V_275 V_276 ;
V_276 = F_214 ( V_7 , V_2 -> V_178 , 0 , V_2 -> V_176 ) ;
if ( V_276 == V_261 )
return true ;
if ( V_276 == V_277 )
return false ;
V_274 = F_203 ( V_7 ) + F_213 ( V_2 -> V_178 ) ;
return F_221 ( V_7 , 0 , V_274 , V_2 -> V_176 ) ;
}
static void F_222 ( struct V_278 * V_278 , struct V_1 * V_2 )
{
struct V_279 * V_236 ;
struct V_7 * V_7 ;
unsigned long V_280 ;
unsigned long V_281 ;
T_2 V_282 ;
T_9 * V_283 = NULL ;
V_282 = V_2 -> V_64 ;
if ( V_208 ) {
V_2 -> V_64 |= V_284 ;
V_2 -> V_176 = F_223 ( V_2 -> V_64 ) ;
}
F_224 (zone, z, zonelist,
sc->reclaim_idx, sc->nodemask) {
if ( F_1 ( V_2 ) ) {
if ( ! F_225 ( V_7 ,
V_37 | V_285 ) )
continue;
if ( F_211 ( V_256 ) &&
V_2 -> V_178 > V_257 &&
F_220 ( V_7 , V_2 ) ) {
V_2 -> F_220 = true ;
continue;
}
if ( V_7 -> V_157 == V_283 )
continue;
V_281 = 0 ;
V_280 = F_226 ( V_7 -> V_157 ,
V_2 -> V_178 , V_2 -> V_64 ,
& V_281 ) ;
V_2 -> V_131 += V_280 ;
V_2 -> V_44 += V_281 ;
}
if ( V_7 -> V_157 == V_283 )
continue;
V_283 = V_7 -> V_157 ;
F_215 ( V_7 -> V_157 , V_2 ) ;
}
V_2 -> V_64 = V_282 ;
}
static void F_227 ( struct V_4 * V_286 , T_9 * V_14 )
{
struct V_4 * V_5 ;
V_5 = F_44 ( V_286 , NULL , NULL ) ;
do {
unsigned long V_216 ;
struct V_21 * V_21 ;
if ( V_5 )
V_216 = F_195 ( V_5 , V_219 ) ;
else
V_216 = F_13 ( V_14 , V_219 ) ;
V_21 = F_207 ( V_14 , V_5 ) ;
V_21 -> V_216 = V_216 ;
} while ( ( V_5 = F_44 ( V_286 , V_5 , NULL ) ) );
}
static unsigned long F_228 ( struct V_278 * V_278 ,
struct V_1 * V_2 )
{
int V_287 = V_2 -> V_153 ;
T_9 * V_283 ;
struct V_279 * V_236 ;
struct V_7 * V_7 ;
V_288:
F_229 () ;
if ( F_1 ( V_2 ) )
F_155 ( V_289 , V_2 -> V_176 , 1 ) ;
do {
F_230 ( V_2 -> V_64 , V_2 -> V_3 ,
V_2 -> V_153 ) ;
V_2 -> V_44 = 0 ;
F_222 ( V_278 , V_2 ) ;
if ( V_2 -> V_131 >= V_2 -> V_247 )
break;
if ( V_2 -> F_220 )
break;
if ( V_2 -> V_153 < V_154 - 2 )
V_2 -> V_148 = 1 ;
} while ( -- V_2 -> V_153 >= 0 );
V_283 = NULL ;
F_224 (zone, z, zonelist, sc->reclaim_idx,
sc->nodemask) {
if ( V_7 -> V_157 == V_283 )
continue;
V_283 = V_7 -> V_157 ;
F_227 ( V_2 -> V_3 , V_7 -> V_157 ) ;
}
F_231 () ;
if ( V_2 -> V_131 )
return V_2 -> V_131 ;
if ( V_2 -> F_220 )
return 1 ;
if ( V_2 -> V_270 ) {
V_2 -> V_153 = V_287 ;
V_2 -> V_269 = 1 ;
V_2 -> V_270 = 0 ;
goto V_288;
}
return 0 ;
}
static bool F_232 ( T_9 * V_14 )
{
struct V_7 * V_7 ;
unsigned long V_290 = 0 ;
unsigned long V_126 = 0 ;
int V_291 ;
bool V_292 ;
if ( V_14 -> V_273 >= V_293 )
return true ;
for ( V_291 = 0 ; V_291 <= V_294 ; V_291 ++ ) {
V_7 = & V_14 -> V_29 [ V_291 ] ;
if ( ! F_15 ( V_7 ) )
continue;
if ( ! F_5 ( V_7 ) )
continue;
V_290 += F_233 ( V_7 ) ;
V_126 += F_17 ( V_7 , V_238 ) ;
}
if ( ! V_290 )
return true ;
V_292 = V_126 > V_290 / 2 ;
if ( ! V_292 && F_234 ( & V_14 -> V_295 ) ) {
V_14 -> V_296 = F_18 ( V_14 -> V_296 ,
(enum V_297 ) V_294 ) ;
F_235 ( & V_14 -> V_295 ) ;
}
return V_292 ;
}
static bool F_236 ( T_2 V_64 , struct V_278 * V_278 ,
T_10 * V_298 )
{
struct V_279 * V_236 ;
struct V_7 * V_7 ;
T_9 * V_14 = NULL ;
if ( V_70 -> V_34 & V_299 )
goto V_66;
if ( F_182 ( V_70 ) )
goto V_66;
F_224 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( V_24 ( V_7 ) > V_294 )
continue;
V_14 = V_7 -> V_157 ;
if ( F_232 ( V_14 ) )
goto V_66;
break;
}
if ( ! V_14 )
goto V_66;
F_100 ( V_300 ) ;
if ( ! ( V_64 & V_142 ) ) {
F_237 ( V_14 -> V_301 ,
F_232 ( V_14 ) , V_190 ) ;
goto V_302;
}
F_238 ( V_7 -> V_157 -> V_301 ,
F_232 ( V_14 ) ) ;
V_302:
if ( F_182 ( V_70 ) )
return true ;
V_66:
return false ;
}
unsigned long F_239 ( struct V_278 * V_278 , int V_178 ,
T_2 V_64 , T_10 * V_298 )
{
unsigned long V_131 ;
struct V_1 V_2 = {
. V_247 = V_65 ,
. V_64 = ( V_64 = F_240 ( V_64 ) ) ,
. V_176 = F_223 ( V_64 ) ,
. V_178 = V_178 ,
. V_298 = V_298 ,
. V_153 = V_154 ,
. V_148 = ! V_303 ,
. V_140 = 1 ,
. V_231 = 1 ,
} ;
if ( F_236 ( V_64 , V_278 , V_298 ) )
return 1 ;
F_241 ( V_178 ,
V_2 . V_148 ,
V_64 ,
V_2 . V_176 ) ;
V_131 = F_228 ( V_278 , & V_2 ) ;
F_242 ( V_131 ) ;
return V_131 ;
}
unsigned long F_243 ( struct V_4 * V_5 ,
T_2 V_64 , bool V_304 ,
T_9 * V_14 ,
unsigned long * V_44 )
{
struct V_1 V_2 = {
. V_247 = V_65 ,
. V_3 = V_5 ,
. V_148 = ! V_303 ,
. V_140 = 1 ,
. V_176 = V_28 - 1 ,
. V_231 = ! V_304 ,
} ;
unsigned long V_221 ;
V_2 . V_64 = ( V_64 & V_305 ) |
( V_306 & ~ V_305 ) ;
F_244 ( V_2 . V_178 ,
V_2 . V_148 ,
V_2 . V_64 ,
V_2 . V_176 ) ;
F_206 ( V_14 , V_5 , & V_2 , & V_221 ) ;
F_245 ( V_2 . V_131 ) ;
* V_44 = V_2 . V_44 ;
return V_2 . V_131 ;
}
unsigned long F_246 ( struct V_4 * V_5 ,
unsigned long V_174 ,
T_2 V_64 ,
bool V_231 )
{
struct V_278 * V_278 ;
unsigned long V_131 ;
int V_51 ;
unsigned int V_307 ;
struct V_1 V_2 = {
. V_247 = F_247 ( V_174 , V_65 ) ,
. V_64 = ( F_240 ( V_64 ) & V_305 ) |
( V_306 & ~ V_305 ) ,
. V_176 = V_28 - 1 ,
. V_3 = V_5 ,
. V_153 = V_154 ,
. V_148 = ! V_303 ,
. V_140 = 1 ,
. V_231 = V_231 ,
} ;
V_51 = F_248 ( V_5 ) ;
V_278 = & F_249 ( V_51 ) -> V_308 [ V_309 ] ;
F_250 ( 0 ,
V_2 . V_148 ,
V_2 . V_64 ,
V_2 . V_176 ) ;
V_307 = F_251 () ;
V_131 = F_228 ( V_278 , & V_2 ) ;
F_252 ( V_307 ) ;
F_253 ( V_131 ) ;
return V_131 ;
}
static void F_254 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_218 )
return;
V_5 = F_44 ( NULL , NULL , NULL ) ;
do {
struct V_21 * V_21 = F_207 ( V_14 , V_5 ) ;
if ( F_194 ( V_21 , false , V_5 , V_2 , true ) )
F_192 ( V_65 , V_21 ,
V_2 , V_242 ) ;
V_5 = F_44 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_255 ( T_9 * V_14 , int V_178 , int V_310 )
{
int V_291 ;
unsigned long V_311 = - 1 ;
struct V_7 * V_7 ;
for ( V_291 = 0 ; V_291 <= V_310 ; V_291 ++ ) {
V_7 = V_14 -> V_29 + V_291 ;
if ( ! F_15 ( V_7 ) )
continue;
V_311 = F_203 ( V_7 ) ;
if ( F_221 ( V_7 , V_178 , V_311 , V_310 ) )
return true ;
}
if ( V_311 == - 1 )
return true ;
return false ;
}
static void F_256 ( T_9 * V_14 )
{
F_257 ( V_196 , & V_14 -> V_34 ) ;
F_257 ( V_146 , & V_14 -> V_34 ) ;
F_257 ( V_144 , & V_14 -> V_34 ) ;
}
static bool F_258 ( T_9 * V_14 , int V_178 , int V_310 )
{
if ( F_234 ( & V_14 -> V_301 ) )
F_259 ( & V_14 -> V_301 ) ;
if ( V_14 -> V_273 >= V_293 )
return true ;
if ( F_255 ( V_14 , V_178 , V_310 ) ) {
F_256 ( V_14 ) ;
return true ;
}
return false ;
}
static bool F_260 ( T_9 * V_14 ,
struct V_1 * V_2 )
{
struct V_7 * V_7 ;
int V_236 ;
V_2 -> V_247 = 0 ;
for ( V_236 = 0 ; V_236 <= V_2 -> V_176 ; V_236 ++ ) {
V_7 = V_14 -> V_29 + V_236 ;
if ( ! F_15 ( V_7 ) )
continue;
V_2 -> V_247 += F_247 ( F_203 ( V_7 ) , V_65 ) ;
}
F_215 ( V_14 , V_2 ) ;
if ( V_2 -> V_178 && V_2 -> V_131 >= F_213 ( V_2 -> V_178 ) )
V_2 -> V_178 = 0 ;
return V_2 -> V_44 >= V_2 -> V_247 ;
}
static int F_261 ( T_9 * V_14 , int V_178 , int V_310 )
{
int V_291 ;
unsigned long V_280 ;
unsigned long V_281 ;
struct V_7 * V_7 ;
struct V_1 V_2 = {
. V_64 = V_37 ,
. V_178 = V_178 ,
. V_153 = V_154 ,
. V_148 = ! V_303 ,
. V_140 = 1 ,
. V_231 = 1 ,
} ;
F_100 ( V_312 ) ;
do {
unsigned long V_131 = V_2 . V_131 ;
bool V_313 = true ;
V_2 . V_176 = V_310 ;
if ( V_208 ) {
for ( V_291 = V_28 - 1 ; V_291 >= 0 ; V_291 -- ) {
V_7 = V_14 -> V_29 + V_291 ;
if ( ! F_15 ( V_7 ) )
continue;
V_2 . V_176 = V_291 ;
break;
}
}
if ( F_255 ( V_14 , V_2 . V_178 , V_310 ) )
goto V_66;
F_254 ( V_14 , & V_2 ) ;
if ( V_2 . V_153 < V_154 - 2 )
V_2 . V_148 = 1 ;
V_2 . V_44 = 0 ;
V_281 = 0 ;
V_280 = F_226 ( V_14 , V_2 . V_178 ,
V_2 . V_64 , & V_281 ) ;
V_2 . V_131 += V_280 ;
if ( F_260 ( V_14 , & V_2 ) )
V_313 = false ;
if ( F_234 ( & V_14 -> V_301 ) &&
F_232 ( V_14 ) )
F_259 ( & V_14 -> V_301 ) ;
if ( F_262 () || F_263 () )
break;
V_131 = V_2 . V_131 - V_131 ;
if ( V_313 || ! V_131 )
V_2 . V_153 -- ;
} while ( V_2 . V_153 >= 1 );
if ( ! V_2 . V_131 )
V_14 -> V_273 ++ ;
V_66:
F_227 ( NULL , V_14 ) ;
return V_2 . V_178 ;
}
static enum V_297 V_296 ( T_9 * V_14 ,
enum V_297 V_310 )
{
if ( V_14 -> V_296 == V_28 )
return V_310 ;
return F_247 ( V_14 -> V_296 , V_310 ) ;
}
static void F_264 ( T_9 * V_14 , int V_314 , int V_315 ,
unsigned int V_310 )
{
long V_316 = 0 ;
F_265 ( V_317 ) ;
if ( F_266 ( V_70 ) || F_263 () )
return;
F_267 ( & V_14 -> V_295 , & V_317 , V_318 ) ;
if ( F_258 ( V_14 , V_315 , V_310 ) ) {
F_268 ( V_14 ) ;
F_269 ( V_14 , V_314 , V_310 ) ;
V_316 = F_270 ( V_190 / 10 ) ;
if ( V_316 ) {
V_14 -> V_296 = V_296 ( V_14 , V_310 ) ;
V_14 -> V_319 = F_247 ( V_14 -> V_319 , V_315 ) ;
}
F_271 ( & V_14 -> V_295 , & V_317 ) ;
F_267 ( & V_14 -> V_295 , & V_317 , V_318 ) ;
}
if ( ! V_316 &&
F_258 ( V_14 , V_315 , V_310 ) ) {
F_272 ( V_14 -> V_199 ) ;
F_273 ( V_14 , V_320 ) ;
if ( ! F_263 () )
F_274 () ;
F_273 ( V_14 , V_321 ) ;
} else {
if ( V_316 )
F_100 ( V_322 ) ;
else
F_100 ( V_323 ) ;
}
F_271 ( & V_14 -> V_295 , & V_317 ) ;
}
static int F_275 ( void * V_324 )
{
unsigned int V_314 , V_315 ;
unsigned int V_310 = V_28 - 1 ;
T_9 * V_14 = ( T_9 * ) V_324 ;
struct V_325 * V_326 = V_70 ;
struct V_263 V_263 = {
. V_272 = 0 ,
} ;
const struct V_327 * V_327 = F_276 ( V_14 -> V_199 ) ;
F_277 ( V_37 ) ;
if ( ! F_278 ( V_327 ) )
F_279 ( V_326 , V_327 ) ;
V_70 -> V_263 = & V_263 ;
V_326 -> V_34 |= V_328 | V_71 | V_329 ;
F_280 () ;
V_14 -> V_319 = 0 ;
V_14 -> V_296 = V_28 ;
for ( ; ; ) {
bool V_60 ;
V_314 = V_315 = V_14 -> V_319 ;
V_310 = V_296 ( V_14 , V_310 ) ;
V_330:
F_264 ( V_14 , V_314 , V_315 ,
V_310 ) ;
V_314 = V_315 = V_14 -> V_319 ;
V_310 = V_296 ( V_14 , 0 ) ;
V_14 -> V_319 = 0 ;
V_14 -> V_296 = V_28 ;
V_60 = F_262 () ;
if ( F_263 () )
break;
if ( V_60 )
continue;
F_281 ( V_14 -> V_199 , V_310 ,
V_314 ) ;
V_315 = F_261 ( V_14 , V_314 , V_310 ) ;
if ( V_315 < V_314 )
goto V_330;
}
V_326 -> V_34 &= ~ ( V_328 | V_71 | V_329 ) ;
V_70 -> V_263 = NULL ;
F_282 () ;
return 0 ;
}
void F_283 ( struct V_7 * V_7 , int V_178 , enum V_297 V_310 )
{
T_9 * V_14 ;
if ( ! F_15 ( V_7 ) )
return;
if ( ! F_225 ( V_7 , V_37 | V_285 ) )
return;
V_14 = V_7 -> V_157 ;
V_14 -> V_296 = V_296 ( V_14 ,
V_310 ) ;
V_14 -> V_319 = F_247 ( V_14 -> V_319 , V_178 ) ;
if ( ! F_234 ( & V_14 -> V_295 ) )
return;
if ( V_14 -> V_273 >= V_293 )
return;
if ( F_255 ( V_14 , V_178 , V_310 ) )
return;
F_284 ( V_14 -> V_199 , V_310 , V_178 ) ;
F_235 ( & V_14 -> V_295 ) ;
}
unsigned long F_285 ( unsigned long V_247 )
{
struct V_263 V_263 ;
struct V_1 V_2 = {
. V_247 = V_247 ,
. V_64 = V_306 ,
. V_176 = V_28 - 1 ,
. V_153 = V_154 ,
. V_148 = 1 ,
. V_140 = 1 ,
. V_231 = 1 ,
. V_198 = 1 ,
} ;
struct V_278 * V_278 = F_286 ( F_287 () , V_2 . V_64 ) ;
struct V_325 * V_324 = V_70 ;
unsigned long V_131 ;
unsigned int V_307 ;
V_307 = F_251 () ;
F_277 ( V_2 . V_64 ) ;
V_263 . V_272 = 0 ;
V_324 -> V_263 = & V_263 ;
V_131 = F_228 ( V_278 , & V_2 ) ;
V_324 -> V_263 = NULL ;
F_282 () ;
F_252 ( V_307 ) ;
return V_131 ;
}
static int F_288 ( unsigned int V_331 )
{
int V_51 ;
F_289 (nid, N_MEMORY) {
T_9 * V_14 = F_249 ( V_51 ) ;
const struct V_327 * V_332 ;
V_332 = F_276 ( V_14 -> V_199 ) ;
if ( F_290 ( V_333 , V_332 ) < V_334 )
F_279 ( V_14 -> F_275 , V_332 ) ;
}
return 0 ;
}
int F_291 ( int V_51 )
{
T_9 * V_14 = F_249 ( V_51 ) ;
int V_60 = 0 ;
if ( V_14 -> F_275 )
return 0 ;
V_14 -> F_275 = F_292 ( F_275 , V_14 , L_4 , V_51 ) ;
if ( F_293 ( V_14 -> F_275 ) ) {
F_69 ( V_335 == V_336 ) ;
F_30 ( L_5 , V_51 ) ;
V_60 = F_294 ( V_14 -> F_275 ) ;
V_14 -> F_275 = NULL ;
}
return V_60 ;
}
void F_295 ( int V_51 )
{
struct V_325 * F_275 = F_249 ( V_51 ) -> F_275 ;
if ( F_275 ) {
F_296 ( F_275 ) ;
F_249 ( V_51 ) -> F_275 = NULL ;
}
}
static int T_11 F_297 ( void )
{
int V_51 , V_60 ;
F_298 () ;
F_289 (nid, N_MEMORY)
F_291 ( V_51 ) ;
V_60 = F_299 ( V_337 ,
L_6 , F_288 ,
NULL ) ;
F_300 ( V_60 < 0 ) ;
return 0 ;
}
static inline unsigned long F_301 ( struct V_13 * V_14 )
{
unsigned long V_338 = F_13 ( V_14 , V_339 ) ;
unsigned long V_340 = F_13 ( V_14 , V_16 ) +
F_13 ( V_14 , V_15 ) ;
return ( V_340 > V_338 ) ? ( V_340 - V_338 ) : 0 ;
}
static unsigned long F_302 ( struct V_13 * V_14 )
{
unsigned long V_341 ;
unsigned long V_47 = 0 ;
if ( V_342 & V_343 )
V_341 = F_13 ( V_14 , V_344 ) ;
else
V_341 = F_301 ( V_14 ) ;
if ( ! ( V_342 & V_345 ) )
V_47 += F_13 ( V_14 , V_346 ) ;
if ( F_73 ( V_47 > V_341 ) )
V_47 = V_341 ;
return V_341 - V_47 ;
}
static int F_303 ( struct V_13 * V_14 , T_2 V_64 , unsigned int V_178 )
{
const unsigned long V_174 = 1 << V_178 ;
struct V_325 * V_324 = V_70 ;
struct V_263 V_263 ;
int V_310 = F_223 ( V_64 ) ;
unsigned int V_307 ;
struct V_1 V_2 = {
. V_247 = F_247 ( V_174 , V_65 ) ,
. V_64 = ( V_64 = F_240 ( V_64 ) ) ,
. V_178 = V_178 ,
. V_153 = V_347 ,
. V_148 = ! ! ( V_342 & V_345 ) ,
. V_140 = ! ! ( V_342 & V_343 ) ,
. V_231 = 1 ,
. V_176 = V_310 ,
} ;
F_33 () ;
V_307 = F_251 () ;
V_324 -> V_34 |= V_71 ;
F_277 ( V_64 ) ;
V_263 . V_272 = 0 ;
V_324 -> V_263 = & V_263 ;
if ( F_302 ( V_14 ) > V_14 -> V_348 ) {
do {
F_215 ( V_14 , & V_2 ) ;
} while ( V_2 . V_131 < V_174 && -- V_2 . V_153 >= 0 );
}
V_324 -> V_263 = NULL ;
V_70 -> V_34 &= ~ V_71 ;
F_252 ( V_307 ) ;
F_282 () ;
return V_2 . V_131 >= V_174 ;
}
int F_304 ( struct V_13 * V_14 , T_2 V_64 , unsigned int V_178 )
{
int V_60 ;
if ( F_302 ( V_14 ) <= V_14 -> V_348 &&
F_202 ( V_14 -> V_199 , V_349 ) <= V_14 -> V_350 )
return V_351 ;
if ( ! F_305 ( V_64 ) || ( V_70 -> V_34 & V_328 ) )
return V_352 ;
if ( F_306 ( V_14 -> V_199 , V_353 ) && V_14 -> V_199 != F_287 () )
return V_352 ;
if ( F_307 ( V_354 , & V_14 -> V_34 ) )
return V_352 ;
V_60 = F_303 ( V_14 , V_64 , V_178 ) ;
F_257 ( V_354 , & V_14 -> V_34 ) ;
if ( ! V_60 )
F_100 ( V_355 ) ;
return V_60 ;
}
int F_94 ( struct V_68 * V_68 )
{
return ! F_308 ( F_55 ( V_68 ) ) && ! F_129 ( V_68 ) ;
}
void F_309 ( struct V_68 * * V_356 , int V_174 )
{
struct V_21 * V_21 ;
struct V_13 * V_14 = NULL ;
int V_357 = 0 ;
int V_358 = 0 ;
int V_291 ;
for ( V_291 = 0 ; V_291 < V_174 ; V_291 ++ ) {
struct V_68 * V_68 = V_356 [ V_291 ] ;
struct V_13 * V_359 = F_310 ( V_68 ) ;
V_357 ++ ;
if ( V_359 != V_14 ) {
if ( V_14 )
F_166 ( & V_14 -> V_184 ) ;
V_14 = V_359 ;
F_160 ( & V_14 -> V_184 ) ;
}
V_21 = F_162 ( V_68 , V_14 ) ;
if ( ! F_92 ( V_68 ) || ! F_90 ( V_68 ) )
continue;
if ( F_94 ( V_68 ) ) {
enum V_22 V_23 = F_311 ( V_68 ) ;
F_91 ( F_113 ( V_68 ) , V_68 ) ;
F_93 ( V_68 ) ;
F_165 ( V_68 , V_21 , V_360 ) ;
F_170 ( V_68 , V_21 , V_23 ) ;
V_358 ++ ;
}
}
if ( V_14 ) {
F_185 ( V_104 , V_358 ) ;
F_185 ( V_361 , V_357 ) ;
F_166 ( & V_14 -> V_184 ) ;
}
}
