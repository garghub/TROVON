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
V_43 -> V_44 = V_61 ;
V_60 = V_32 -> V_59 ( V_32 , V_43 ) ;
if ( V_60 == V_62 )
break;
V_46 += V_60 ;
F_32 ( V_63 , V_43 -> V_44 ) ;
V_48 -= V_43 -> V_44 ;
V_55 += V_43 -> V_44 ;
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
int V_69 = F_48 ( V_68 ) && F_49 ( V_68 ) ?
V_70 : 1 ;
return F_50 ( V_68 ) - F_51 ( V_68 ) == 1 + V_69 ;
}
static int F_52 ( struct V_71 * V_71 , struct V_1 * V_2 )
{
if ( V_72 -> V_34 & V_73 )
return 1 ;
if ( ! F_53 ( V_71 ) )
return 1 ;
if ( F_54 ( V_71 ) == V_72 -> V_74 )
return 1 ;
return 0 ;
}
static void F_55 ( struct V_75 * V_76 ,
struct V_68 * V_68 , int error )
{
F_56 ( V_68 ) ;
if ( F_57 ( V_68 ) == V_76 )
F_58 ( V_76 , error ) ;
F_59 ( V_68 ) ;
}
static T_3 F_60 ( struct V_68 * V_68 , struct V_75 * V_76 ,
struct V_1 * V_2 )
{
if ( ! F_47 ( V_68 ) )
return V_77 ;
if ( ! V_76 ) {
if ( F_51 ( V_68 ) ) {
if ( F_61 ( V_68 ) ) {
F_62 ( V_68 ) ;
F_63 ( L_2 , V_78 ) ;
return V_79 ;
}
}
return V_77 ;
}
if ( V_76 -> V_80 -> V_81 == NULL )
return V_82 ;
if ( ! F_52 ( V_76 -> V_83 , V_2 ) )
return V_77 ;
if ( F_64 ( V_68 ) ) {
int V_84 ;
struct V_85 V_86 = {
. V_87 = V_88 ,
. V_89 = V_65 ,
. V_90 = 0 ,
. V_91 = V_92 ,
. V_93 = 1 ,
} ;
F_65 ( V_68 ) ;
V_84 = V_76 -> V_80 -> V_81 ( V_68 , & V_86 ) ;
if ( V_84 < 0 )
F_55 ( V_76 , V_68 , V_84 ) ;
if ( V_84 == V_94 ) {
F_66 ( V_68 ) ;
return V_82 ;
}
if ( ! F_67 ( V_68 ) ) {
F_66 ( V_68 ) ;
}
F_68 ( V_68 ) ;
F_69 ( V_68 , V_95 ) ;
return V_96 ;
}
return V_79 ;
}
static int F_70 ( struct V_75 * V_76 , struct V_68 * V_68 ,
bool V_97 )
{
unsigned long V_34 ;
int V_98 ;
F_71 ( ! F_72 ( V_68 ) ) ;
F_71 ( V_76 != F_57 ( V_68 ) ) ;
F_73 ( & V_76 -> V_99 , V_34 ) ;
if ( F_74 ( F_48 ( V_68 ) ) && F_49 ( V_68 ) )
V_98 = 1 + V_70 ;
else
V_98 = 2 ;
if ( ! F_75 ( V_68 , V_98 ) )
goto V_100;
if ( F_74 ( F_76 ( V_68 ) ) ) {
F_77 ( V_68 , V_98 ) ;
goto V_100;
}
if ( F_49 ( V_68 ) ) {
T_4 V_101 = { . V_102 = F_78 (page) } ;
F_79 ( V_68 , V_101 ) ;
F_80 ( V_68 ) ;
F_81 ( & V_76 -> V_99 , V_34 ) ;
F_82 ( V_68 , V_101 ) ;
} else {
void (* F_83)( struct V_68 * );
void * V_103 = NULL ;
F_83 = V_76 -> V_80 -> F_83 ;
if ( V_97 && F_84 ( V_68 ) &&
! F_85 ( V_76 ) && ! F_86 ( V_76 ) )
V_103 = F_87 ( V_76 , V_68 ) ;
F_88 ( V_68 , V_103 ) ;
F_81 ( & V_76 -> V_99 , V_34 ) ;
if ( F_83 != NULL )
F_83 ( V_68 ) ;
}
return 1 ;
V_100:
F_81 ( & V_76 -> V_99 , V_34 ) ;
return 0 ;
}
int F_89 ( struct V_75 * V_76 , struct V_68 * V_68 )
{
if ( F_70 ( V_76 , V_68 , false ) ) {
F_77 ( V_68 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_90 ( struct V_68 * V_68 )
{
bool V_104 ;
int V_105 = F_91 ( V_68 ) ;
F_92 ( F_93 ( V_68 ) , V_68 ) ;
V_106:
F_94 ( V_68 ) ;
if ( F_95 ( V_68 ) ) {
V_104 = false ;
F_96 ( V_68 ) ;
} else {
V_104 = true ;
F_97 ( V_68 ) ;
F_98 () ;
}
if ( V_104 && F_95 ( V_68 ) ) {
if ( ! F_99 ( V_68 ) ) {
F_100 ( V_68 ) ;
goto V_106;
}
}
if ( V_105 && ! V_104 )
F_101 ( V_107 ) ;
else if ( ! V_105 && V_104 )
F_101 ( V_108 ) ;
F_100 ( V_68 ) ;
}
static enum V_109 F_102 ( struct V_68 * V_68 ,
struct V_1 * V_2 )
{
int V_110 , V_111 ;
unsigned long V_112 ;
V_110 = F_103 ( V_68 , 1 , V_2 -> V_3 ,
& V_112 ) ;
V_111 = F_104 ( V_68 ) ;
if ( V_112 & V_113 )
return V_114 ;
if ( V_110 ) {
if ( F_105 ( V_68 ) )
return V_115 ;
F_106 ( V_68 ) ;
if ( V_111 || V_110 > 1 )
return V_115 ;
if ( V_112 & V_116 )
return V_115 ;
return V_117 ;
}
if ( V_111 && ! F_105 ( V_68 ) )
return V_118 ;
return V_114 ;
}
static void F_107 ( struct V_68 * V_68 ,
bool * V_119 , bool * V_120 )
{
struct V_75 * V_76 ;
if ( ! F_84 ( V_68 ) ||
( F_108 ( V_68 ) && ! F_105 ( V_68 ) ) ) {
* V_119 = false ;
* V_120 = false ;
return;
}
* V_119 = F_76 ( V_68 ) ;
* V_120 = F_67 ( V_68 ) ;
if ( ! F_51 ( V_68 ) )
return;
V_76 = F_57 ( V_68 ) ;
if ( V_76 && V_76 -> V_80 -> V_121 )
V_76 -> V_80 -> V_121 ( V_68 , V_119 , V_120 ) ;
}
static unsigned long F_109 ( struct V_122 * V_123 ,
struct V_13 * V_14 ,
struct V_1 * V_2 ,
enum V_124 V_124 ,
struct V_125 * V_126 ,
bool V_127 )
{
F_110 ( V_128 ) ;
F_110 ( V_129 ) ;
int V_130 = 0 ;
unsigned V_131 = 0 ;
unsigned V_132 = 0 ;
unsigned V_133 = 0 ;
unsigned V_134 = 0 ;
unsigned V_135 = 0 ;
unsigned V_136 = 0 ;
unsigned V_137 = 0 ;
unsigned V_138 = 0 ;
F_33 () ;
while ( ! F_111 ( V_123 ) ) {
struct V_75 * V_76 ;
struct V_68 * V_68 ;
int V_139 ;
enum V_109 V_140 = V_118 ;
bool V_119 , V_120 ;
F_33 () ;
V_68 = F_112 ( V_123 ) ;
F_25 ( & V_68 -> V_23 ) ;
if ( ! F_113 ( V_68 ) )
goto V_141;
F_92 ( F_114 ( V_68 ) , V_68 ) ;
V_2 -> V_44 ++ ;
if ( F_74 ( ! F_95 ( V_68 ) ) )
goto V_142;
if ( ! V_2 -> V_143 && F_115 ( V_68 ) )
goto V_144;
if ( ( F_115 ( V_68 ) || F_49 ( V_68 ) ) &&
! ( F_108 ( V_68 ) && ! F_105 ( V_68 ) ) )
V_2 -> V_44 ++ ;
V_139 = ( V_2 -> V_64 & V_145 ) ||
( F_49 ( V_68 ) && ( V_2 -> V_64 & V_146 ) ) ;
F_107 ( V_68 , & V_119 , & V_120 ) ;
if ( V_119 || V_120 )
V_132 ++ ;
if ( V_119 && ! V_120 )
V_131 ++ ;
V_76 = F_57 ( V_68 ) ;
if ( ( ( V_119 || V_120 ) && V_76 &&
F_53 ( V_76 -> V_83 ) ) ||
( V_120 && F_116 ( V_68 ) ) )
V_133 ++ ;
if ( F_67 ( V_68 ) ) {
if ( F_117 () &&
F_116 ( V_68 ) &&
F_118 ( V_147 , & V_14 -> V_34 ) ) {
V_136 ++ ;
goto V_142;
} else if ( F_2 ( V_2 ) ||
! F_116 ( V_68 ) || ! V_139 ) {
F_65 ( V_68 ) ;
V_135 ++ ;
goto V_142;
} else {
F_59 ( V_68 ) ;
F_119 ( V_68 ) ;
F_22 ( & V_68 -> V_23 , V_123 ) ;
continue;
}
}
if ( ! V_127 )
V_140 = F_102 ( V_68 , V_2 ) ;
switch ( V_140 ) {
case V_115 :
goto V_142;
case V_117 :
V_137 ++ ;
goto V_144;
case V_114 :
case V_118 :
;
}
if ( F_108 ( V_68 ) && F_105 ( V_68 ) ) {
if ( ! F_49 ( V_68 ) ) {
if ( ! ( V_2 -> V_64 & V_146 ) )
goto V_144;
if ( F_48 ( V_68 ) ) {
if ( ! F_120 ( V_68 , NULL ) )
goto V_142;
if ( ! F_121 ( V_68 ) &&
F_122 ( V_68 ,
V_123 ) )
goto V_142;
}
if ( ! F_123 ( V_68 ) ) {
if ( ! F_48 ( V_68 ) )
goto V_142;
if ( F_122 ( V_68 ,
V_123 ) )
goto V_142;
#ifdef F_124
F_101 ( V_148 ) ;
#endif
if ( ! F_123 ( V_68 ) )
goto V_142;
}
V_139 = 1 ;
V_76 = F_57 ( V_68 ) ;
}
} else if ( F_74 ( F_48 ( V_68 ) ) ) {
if ( F_122 ( V_68 , V_123 ) )
goto V_144;
}
if ( F_115 ( V_68 ) ) {
enum V_124 V_34 = V_124 | V_149 ;
if ( F_74 ( F_48 ( V_68 ) ) )
V_34 |= V_150 ;
if ( ! F_125 ( V_68 , V_34 ) ) {
V_138 ++ ;
goto V_142;
}
}
if ( F_76 ( V_68 ) ) {
if ( F_84 ( V_68 ) &&
( ! F_117 () || ! F_116 ( V_68 ) ||
! F_118 ( V_151 , & V_14 -> V_34 ) ) ) {
F_69 ( V_68 , V_152 ) ;
F_65 ( V_68 ) ;
goto V_142;
}
if ( V_140 == V_118 )
goto V_144;
if ( ! V_139 )
goto V_144;
if ( ! V_2 -> V_153 )
goto V_144;
F_126 () ;
switch ( F_60 ( V_68 , V_76 , V_2 ) ) {
case V_77 :
goto V_144;
case V_82 :
goto V_142;
case V_96 :
if ( F_67 ( V_68 ) )
goto V_141;
if ( F_76 ( V_68 ) )
goto V_141;
if ( ! F_113 ( V_68 ) )
goto V_141;
if ( F_76 ( V_68 ) || F_67 ( V_68 ) )
goto V_144;
V_76 = F_57 ( V_68 ) ;
case V_79 :
;
}
}
if ( F_51 ( V_68 ) ) {
if ( ! F_127 ( V_68 , V_2 -> V_64 ) )
goto V_142;
if ( ! V_76 && F_50 ( V_68 ) == 1 ) {
F_59 ( V_68 ) ;
if ( F_128 ( V_68 ) )
goto V_154;
else {
V_134 ++ ;
continue;
}
}
}
if ( F_108 ( V_68 ) && ! F_105 ( V_68 ) ) {
if ( ! F_75 ( V_68 , 1 ) )
goto V_144;
if ( F_76 ( V_68 ) ) {
F_77 ( V_68 , 1 ) ;
goto V_144;
}
F_101 ( V_155 ) ;
F_129 ( V_68 , V_155 ) ;
} else if ( ! V_76 || ! F_70 ( V_76 , V_68 , true ) )
goto V_144;
F_130 ( V_68 ) ;
V_154:
V_134 ++ ;
if ( F_74 ( F_48 ( V_68 ) ) ) {
F_131 ( V_68 ) ;
( * F_132 ( V_68 ) ) ( V_68 ) ;
} else
F_133 ( & V_68 -> V_23 , & V_129 ) ;
continue;
V_142:
if ( F_49 ( V_68 ) && ( F_134 ( V_68 ) ||
F_135 ( V_68 ) ) )
F_136 ( V_68 ) ;
F_92 ( F_114 ( V_68 ) , V_68 ) ;
if ( ! F_135 ( V_68 ) ) {
F_137 ( V_68 ) ;
V_130 ++ ;
F_129 ( V_68 , V_156 ) ;
}
V_144:
F_59 ( V_68 ) ;
V_141:
F_133 ( & V_68 -> V_23 , & V_128 ) ;
F_92 ( F_93 ( V_68 ) || F_91 ( V_68 ) , V_68 ) ;
}
F_138 ( & V_129 ) ;
F_139 () ;
F_140 ( & V_129 , true ) ;
F_141 ( & V_128 , V_123 ) ;
F_32 ( V_156 , V_130 ) ;
if ( V_126 ) {
V_126 -> V_132 = V_132 ;
V_126 -> V_133 = V_133 ;
V_126 -> V_131 = V_131 ;
V_126 -> V_135 = V_135 ;
V_126 -> V_136 = V_136 ;
V_126 -> V_157 = V_130 ;
V_126 -> V_137 = V_137 ;
V_126 -> V_138 = V_138 ;
}
return V_134 ;
}
unsigned long F_142 ( struct V_7 * V_7 ,
struct V_122 * V_123 )
{
struct V_1 V_2 = {
. V_64 = V_37 ,
. V_158 = V_159 ,
. V_143 = 1 ,
} ;
unsigned long V_60 ;
struct V_68 * V_68 , * V_160 ;
F_110 ( V_161 ) ;
F_143 (page, next, page_list, lru) {
if ( F_84 ( V_68 ) && ! F_76 ( V_68 ) &&
! F_144 ( V_68 ) ) {
F_145 ( V_68 ) ;
F_146 ( & V_68 -> V_23 , & V_161 ) ;
}
}
V_60 = F_109 ( & V_161 , V_7 -> V_162 , & V_2 ,
V_163 , NULL , true ) ;
F_141 ( & V_161 , V_123 ) ;
F_147 ( V_7 -> V_162 , V_17 , - V_60 ) ;
return V_60 ;
}
int F_148 ( struct V_68 * V_68 , T_5 V_164 )
{
int V_60 = - V_165 ;
if ( ! F_93 ( V_68 ) )
return V_60 ;
if ( F_91 ( V_68 ) && ! ( V_164 & V_166 ) )
return V_60 ;
V_60 = - V_167 ;
if ( V_164 & V_168 ) {
if ( F_67 ( V_68 ) )
return V_60 ;
if ( F_76 ( V_68 ) ) {
struct V_75 * V_76 ;
V_76 = F_57 ( V_68 ) ;
if ( V_76 && ! V_76 -> V_80 -> V_169 )
return V_60 ;
}
}
if ( ( V_164 & V_170 ) && F_115 ( V_68 ) )
return V_60 ;
if ( F_149 ( F_150 ( V_68 ) ) ) {
F_151 ( V_68 ) ;
V_60 = 0 ;
}
return V_60 ;
}
static T_6 void F_152 ( struct V_21 * V_21 ,
enum V_22 V_23 , unsigned long * V_171 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( ! V_171 [ V_26 ] )
continue;
F_153 ( V_21 , V_23 , V_26 , - V_171 [ V_26 ] ) ;
#ifdef F_154
F_155 ( V_21 , V_23 , V_26 , - V_171 [ V_26 ] ) ;
#endif
}
}
static unsigned long F_156 ( unsigned long V_61 ,
struct V_21 * V_21 , struct V_122 * V_172 ,
unsigned long * V_44 , struct V_1 * V_2 ,
T_5 V_164 , enum V_22 V_23 )
{
struct V_122 * V_173 = & V_21 -> V_174 [ V_23 ] ;
unsigned long V_175 = 0 ;
unsigned long V_171 [ V_28 ] = { 0 } ;
unsigned long V_176 [ V_28 ] = { 0 , } ;
unsigned long V_177 = 0 ;
unsigned long V_178 , V_48 , V_179 ;
F_110 ( V_180 ) ;
V_178 = 0 ;
for ( V_48 = 0 ;
V_178 < V_61 && V_175 < V_61 && ! F_111 ( V_173 ) ;
V_48 ++ ) {
struct V_68 * V_68 ;
V_68 = F_112 ( V_173 ) ;
F_157 ( V_68 , V_173 , V_34 ) ;
F_92 ( ! F_93 ( V_68 ) , V_68 ) ;
if ( F_158 ( V_68 ) > V_2 -> V_181 ) {
F_146 ( & V_68 -> V_23 , & V_180 ) ;
V_176 [ F_158 ( V_68 ) ] ++ ;
continue;
}
V_178 ++ ;
switch ( F_148 ( V_68 , V_164 ) ) {
case 0 :
V_179 = F_159 ( V_68 ) ;
V_175 += V_179 ;
V_171 [ F_158 ( V_68 ) ] += V_179 ;
F_146 ( & V_68 -> V_23 , V_172 ) ;
break;
case - V_167 :
F_146 ( & V_68 -> V_23 , V_173 ) ;
continue;
default:
F_160 () ;
}
}
if ( ! F_111 ( & V_180 ) ) {
int V_26 ;
F_141 ( & V_180 , V_173 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( ! V_176 [ V_26 ] )
continue;
F_161 ( V_182 , V_26 , V_176 [ V_26 ] ) ;
V_177 += V_176 [ V_26 ] ;
}
}
* V_44 = V_48 ;
F_162 ( V_2 -> V_181 , V_2 -> V_183 , V_61 ,
V_48 , V_177 , V_175 , V_164 , V_23 ) ;
F_152 ( V_21 , V_23 , V_171 ) ;
return V_175 ;
}
int F_99 ( struct V_68 * V_68 )
{
int V_60 = - V_167 ;
F_92 ( ! F_50 ( V_68 ) , V_68 ) ;
F_163 ( F_164 ( V_68 ) , L_3 ) ;
if ( F_93 ( V_68 ) ) {
struct V_7 * V_7 = F_165 ( V_68 ) ;
struct V_21 * V_21 ;
F_166 ( F_167 ( V_7 ) ) ;
V_21 = F_168 ( V_68 , V_7 -> V_162 ) ;
if ( F_93 ( V_68 ) ) {
int V_23 = F_169 ( V_68 ) ;
F_170 ( V_68 ) ;
F_151 ( V_68 ) ;
F_171 ( V_68 , V_21 , V_23 ) ;
V_60 = 0 ;
}
F_172 ( F_167 ( V_7 ) ) ;
}
return V_60 ;
}
static int F_173 ( struct V_13 * V_14 , int V_184 ,
struct V_1 * V_2 )
{
unsigned long V_185 , V_186 ;
if ( F_117 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_184 ) {
V_185 = F_13 ( V_14 , V_16 ) ;
V_186 = F_13 ( V_14 , V_17 ) ;
} else {
V_185 = F_13 ( V_14 , V_19 ) ;
V_186 = F_13 ( V_14 , V_20 ) ;
}
if ( ( V_2 -> V_64 & ( V_146 | V_145 ) ) == ( V_146 | V_145 ) )
V_185 >>= 3 ;
return V_186 > V_185 ;
}
static T_7 void
F_174 ( struct V_21 * V_21 , struct V_122 * V_123 )
{
struct V_187 * V_125 = & V_21 -> V_125 ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
F_110 ( V_188 ) ;
while ( ! F_111 ( V_123 ) ) {
struct V_68 * V_68 = F_112 ( V_123 ) ;
int V_23 ;
F_92 ( F_93 ( V_68 ) , V_68 ) ;
F_25 ( & V_68 -> V_23 ) ;
if ( F_74 ( ! F_95 ( V_68 ) ) ) {
F_172 ( & V_14 -> V_189 ) ;
F_90 ( V_68 ) ;
F_166 ( & V_14 -> V_189 ) ;
continue;
}
V_21 = F_168 ( V_68 , V_14 ) ;
F_175 ( V_68 ) ;
V_23 = F_169 ( V_68 ) ;
F_176 ( V_68 , V_21 , V_23 ) ;
if ( F_177 ( V_23 ) ) {
int V_184 = F_178 ( V_23 ) ;
int V_190 = F_159 ( V_68 ) ;
V_125 -> V_191 [ V_184 ] += V_190 ;
}
if ( F_128 ( V_68 ) ) {
F_179 ( V_68 ) ;
F_180 ( V_68 ) ;
F_171 ( V_68 , V_21 , V_23 ) ;
if ( F_74 ( F_181 ( V_68 ) ) ) {
F_172 ( & V_14 -> V_189 ) ;
F_131 ( V_68 ) ;
( * F_132 ( V_68 ) ) ( V_68 ) ;
F_166 ( & V_14 -> V_189 ) ;
} else
F_133 ( & V_68 -> V_23 , & V_188 ) ;
}
}
F_141 ( & V_188 , V_123 ) ;
}
static int F_182 ( void )
{
return ! ( V_72 -> V_34 & V_192 ) ||
V_72 -> V_74 == NULL ||
F_183 ( V_72 -> V_74 ) ;
}
static T_7 unsigned long
F_184 ( unsigned long V_61 , struct V_21 * V_21 ,
struct V_1 * V_2 , enum V_22 V_23 )
{
F_110 ( V_123 ) ;
unsigned long V_44 ;
unsigned long V_134 = 0 ;
unsigned long V_175 ;
struct V_125 V_126 = {} ;
T_5 V_193 = 0 ;
int V_184 = F_178 ( V_23 ) ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
struct V_187 * V_125 = & V_21 -> V_125 ;
bool V_194 = false ;
while ( F_74 ( F_173 ( V_14 , V_184 , V_2 ) ) ) {
if ( V_194 )
return 0 ;
F_185 ( 100 ) ;
V_194 = true ;
if ( F_186 ( V_72 ) )
return V_65 ;
}
F_187 () ;
if ( ! V_2 -> V_143 )
V_193 |= V_170 ;
F_166 ( & V_14 -> V_189 ) ;
V_175 = F_156 ( V_61 , V_21 , & V_123 ,
& V_44 , V_2 , V_193 , V_23 ) ;
F_188 ( V_14 , V_20 + V_184 , V_175 ) ;
V_125 -> V_195 [ V_184 ] += V_175 ;
if ( F_117 () ) {
if ( F_1 ( V_2 ) )
F_189 ( V_196 , V_44 ) ;
F_190 ( F_191 ( V_21 ) , V_196 ,
V_44 ) ;
} else {
if ( F_1 ( V_2 ) )
F_189 ( V_197 , V_44 ) ;
F_190 ( F_191 ( V_21 ) , V_197 ,
V_44 ) ;
}
F_172 ( & V_14 -> V_189 ) ;
if ( V_175 == 0 )
return 0 ;
V_134 = F_109 ( & V_123 , V_14 , V_2 , 0 ,
& V_126 , false ) ;
F_166 ( & V_14 -> V_189 ) ;
if ( F_117 () ) {
if ( F_1 ( V_2 ) )
F_189 ( V_198 , V_134 ) ;
F_190 ( F_191 ( V_21 ) , V_198 ,
V_134 ) ;
} else {
if ( F_1 ( V_2 ) )
F_189 ( V_199 , V_134 ) ;
F_190 ( F_191 ( V_21 ) , V_199 ,
V_134 ) ;
}
F_174 ( V_21 , & V_123 ) ;
F_188 ( V_14 , V_20 + V_184 , - V_175 ) ;
F_172 ( & V_14 -> V_189 ) ;
F_138 ( & V_123 ) ;
F_140 ( & V_123 , true ) ;
if ( V_126 . V_135 && V_126 . V_135 == V_175 )
F_192 ( V_147 , & V_14 -> V_34 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_126 . V_132 && V_126 . V_132 == V_126 . V_133 )
F_192 ( V_200 , & V_14 -> V_34 ) ;
if ( V_126 . V_131 == V_175 ) {
F_193 ( 0 , V_201 ) ;
F_192 ( V_151 , & V_14 -> V_34 ) ;
}
if ( V_126 . V_136 && F_182 () )
F_194 ( V_202 , V_203 / 10 ) ;
}
if ( ! V_2 -> V_204 && ! F_117 () &&
F_182 () )
F_195 ( V_14 , V_202 , V_203 / 10 ) ;
F_196 ( V_14 -> V_205 ,
V_44 , V_134 ,
V_126 . V_132 , V_126 . V_135 ,
V_126 . V_133 , V_126 . V_136 ,
V_126 . V_157 , V_126 . V_137 ,
V_126 . V_138 ,
V_2 -> V_158 , V_184 ) ;
return V_134 ;
}
static unsigned F_197 ( struct V_21 * V_21 ,
struct V_122 * V_40 ,
struct V_122 * V_188 ,
enum V_22 V_23 )
{
struct V_13 * V_14 = F_14 ( V_21 ) ;
struct V_68 * V_68 ;
int V_179 ;
int V_206 = 0 ;
while ( ! F_111 ( V_40 ) ) {
V_68 = F_112 ( V_40 ) ;
V_21 = F_168 ( V_68 , V_14 ) ;
F_92 ( F_93 ( V_68 ) , V_68 ) ;
F_175 ( V_68 ) ;
V_179 = F_159 ( V_68 ) ;
F_198 ( V_21 , V_23 , F_158 ( V_68 ) , V_179 ) ;
F_146 ( & V_68 -> V_23 , & V_21 -> V_174 [ V_23 ] ) ;
if ( F_128 ( V_68 ) ) {
F_179 ( V_68 ) ;
F_180 ( V_68 ) ;
F_171 ( V_68 , V_21 , V_23 ) ;
if ( F_74 ( F_181 ( V_68 ) ) ) {
F_172 ( & V_14 -> V_189 ) ;
F_131 ( V_68 ) ;
( * F_132 ( V_68 ) ) ( V_68 ) ;
F_166 ( & V_14 -> V_189 ) ;
} else
F_133 ( & V_68 -> V_23 , V_188 ) ;
} else {
V_206 += V_179 ;
}
}
if ( ! F_177 ( V_23 ) ) {
F_189 ( V_207 , V_206 ) ;
F_190 ( F_191 ( V_21 ) , V_207 ,
V_206 ) ;
}
return V_206 ;
}
static void F_199 ( unsigned long V_61 ,
struct V_21 * V_21 ,
struct V_1 * V_2 ,
enum V_22 V_23 )
{
unsigned long V_175 ;
unsigned long V_44 ;
unsigned long V_112 ;
F_110 ( V_208 ) ;
F_110 ( V_209 ) ;
F_110 ( V_210 ) ;
struct V_68 * V_68 ;
struct V_187 * V_125 = & V_21 -> V_125 ;
unsigned V_211 , V_157 ;
unsigned V_212 = 0 ;
T_5 V_193 = 0 ;
int V_184 = F_178 ( V_23 ) ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
F_187 () ;
if ( ! V_2 -> V_143 )
V_193 |= V_170 ;
F_166 ( & V_14 -> V_189 ) ;
V_175 = F_156 ( V_61 , V_21 , & V_208 ,
& V_44 , V_2 , V_193 , V_23 ) ;
F_188 ( V_14 , V_20 + V_184 , V_175 ) ;
V_125 -> V_195 [ V_184 ] += V_175 ;
F_189 ( V_213 , V_44 ) ;
F_190 ( F_191 ( V_21 ) , V_213 , V_44 ) ;
F_172 ( & V_14 -> V_189 ) ;
while ( ! F_111 ( & V_208 ) ) {
F_33 () ;
V_68 = F_112 ( & V_208 ) ;
F_25 ( & V_68 -> V_23 ) ;
if ( F_74 ( ! F_95 ( V_68 ) ) ) {
F_90 ( V_68 ) ;
continue;
}
if ( F_74 ( V_214 ) ) {
if ( F_51 ( V_68 ) && F_113 ( V_68 ) ) {
if ( F_51 ( V_68 ) )
F_127 ( V_68 , 0 ) ;
F_59 ( V_68 ) ;
}
}
if ( F_103 ( V_68 , 0 , V_2 -> V_3 ,
& V_112 ) ) {
V_212 += F_159 ( V_68 ) ;
if ( ( V_112 & V_116 ) && F_84 ( V_68 ) ) {
F_133 ( & V_68 -> V_23 , & V_209 ) ;
continue;
}
}
F_145 ( V_68 ) ;
F_133 ( & V_68 -> V_23 , & V_210 ) ;
}
F_166 ( & V_14 -> V_189 ) ;
V_125 -> V_191 [ V_184 ] += V_212 ;
V_157 = F_197 ( V_21 , & V_209 , & V_208 , V_23 ) ;
V_211 = F_197 ( V_21 , & V_210 , & V_208 , V_23 - V_215 ) ;
F_188 ( V_14 , V_20 + V_184 , - V_175 ) ;
F_172 ( & V_14 -> V_189 ) ;
F_138 ( & V_208 ) ;
F_140 ( & V_208 , true ) ;
F_200 ( V_14 -> V_205 , V_175 , V_157 ,
V_211 , V_212 , V_2 -> V_158 , V_184 ) ;
}
static bool F_201 ( struct V_21 * V_21 , bool V_184 ,
struct V_4 * V_5 ,
struct V_1 * V_2 , bool V_216 )
{
enum V_22 V_217 = V_184 * V_218 + V_215 ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
enum V_22 V_219 = V_184 * V_218 ;
unsigned long V_185 , V_220 ;
unsigned long V_221 ;
unsigned long V_222 ;
unsigned long V_223 ;
if ( ! V_184 && ! V_224 )
return false ;
V_185 = F_10 ( V_21 , V_219 , V_2 -> V_181 ) ;
V_220 = F_10 ( V_21 , V_217 , V_2 -> V_181 ) ;
if ( V_5 )
V_222 = F_202 ( V_5 , V_225 ) ;
else
V_222 = F_13 ( V_14 , V_225 ) ;
if ( V_184 && V_216 && V_21 -> V_222 != V_222 ) {
V_221 = 0 ;
} else {
V_223 = ( V_185 + V_220 ) >> ( 30 - V_226 ) ;
if ( V_223 )
V_221 = F_203 ( 10 * V_223 ) ;
else
V_221 = 1 ;
}
if ( V_216 )
F_204 ( V_14 -> V_205 , V_2 -> V_181 ,
F_10 ( V_21 , V_219 , V_28 ) , V_185 ,
F_10 ( V_21 , V_217 , V_28 ) , V_220 ,
V_221 , V_184 ) ;
return V_185 * V_221 < V_220 ;
}
static unsigned long F_205 ( enum V_22 V_23 , unsigned long V_61 ,
struct V_21 * V_21 , struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_177 ( V_23 ) ) {
if ( F_201 ( V_21 , F_178 ( V_23 ) ,
V_5 , V_2 , true ) )
F_199 ( V_61 , V_21 , V_2 , V_23 ) ;
return 0 ;
}
return F_184 ( V_61 , V_21 , V_2 , V_23 ) ;
}
static void F_206 ( struct V_21 * V_21 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_227 )
{
int V_228 = F_207 ( V_5 ) ;
struct V_187 * V_125 = & V_21 -> V_125 ;
T_8 V_229 [ 2 ] ;
T_8 V_230 = 0 ;
struct V_13 * V_14 = F_14 ( V_21 ) ;
unsigned long V_231 , V_232 ;
enum V_233 V_233 ;
unsigned long V_234 , V_184 ;
unsigned long V_235 , V_236 ;
enum V_22 V_23 ;
if ( ! V_2 -> V_237 || F_208 ( V_5 ) <= 0 ) {
V_233 = V_238 ;
goto V_66;
}
if ( ! F_1 ( V_2 ) && ! V_228 ) {
V_233 = V_238 ;
goto V_66;
}
if ( ! V_2 -> V_158 && V_228 ) {
V_233 = V_239 ;
goto V_66;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_240 ;
unsigned long V_241 ;
int V_242 ;
unsigned long V_243 = 0 ;
V_241 = F_209 ( V_14 -> V_205 , V_244 ) ;
V_240 = F_13 ( V_14 , V_15 ) +
F_13 ( V_14 , V_16 ) ;
for ( V_242 = 0 ; V_242 < V_28 ; V_242 ++ ) {
struct V_7 * V_7 = & V_14 -> V_29 [ V_242 ] ;
if ( ! F_15 ( V_7 ) )
continue;
V_243 += F_210 ( V_7 ) ;
}
if ( F_74 ( V_240 + V_241 <= V_243 ) ) {
if ( ! F_201 ( V_21 , false , V_5 , V_2 , false ) &&
F_10 ( V_21 , V_245 , V_2 -> V_181 )
>> V_2 -> V_158 ) {
V_233 = V_246 ;
goto V_66;
}
}
}
if ( ! F_201 ( V_21 , true , V_5 , V_2 , false ) &&
F_10 ( V_21 , V_247 , V_2 -> V_181 ) >> V_2 -> V_158 ) {
V_233 = V_238 ;
goto V_66;
}
V_233 = V_248 ;
V_231 = V_228 ;
V_232 = 200 - V_231 ;
V_234 = F_10 ( V_21 , V_249 , V_28 ) +
F_10 ( V_21 , V_245 , V_28 ) ;
V_184 = F_10 ( V_21 , V_250 , V_28 ) +
F_10 ( V_21 , V_247 , V_28 ) ;
F_166 ( & V_14 -> V_189 ) ;
if ( F_74 ( V_125 -> V_195 [ 0 ] > V_234 / 4 ) ) {
V_125 -> V_195 [ 0 ] /= 2 ;
V_125 -> V_191 [ 0 ] /= 2 ;
}
if ( F_74 ( V_125 -> V_195 [ 1 ] > V_184 / 4 ) ) {
V_125 -> V_195 [ 1 ] /= 2 ;
V_125 -> V_191 [ 1 ] /= 2 ;
}
V_235 = V_231 * ( V_125 -> V_195 [ 0 ] + 1 ) ;
V_235 /= V_125 -> V_191 [ 0 ] + 1 ;
V_236 = V_232 * ( V_125 -> V_195 [ 1 ] + 1 ) ;
V_236 /= V_125 -> V_191 [ 1 ] + 1 ;
F_172 ( & V_14 -> V_189 ) ;
V_229 [ 0 ] = V_235 ;
V_229 [ 1 ] = V_236 ;
V_230 = V_235 + V_236 + 1 ;
V_66:
* V_227 = 0 ;
F_211 (lru) {
int V_184 = F_178 ( V_23 ) ;
unsigned long V_30 ;
unsigned long V_178 ;
V_30 = F_10 ( V_21 , V_23 , V_2 -> V_181 ) ;
V_178 = V_30 >> V_2 -> V_158 ;
if ( ! V_178 && ! F_39 ( V_5 ) )
V_178 = F_18 ( V_30 , V_65 ) ;
switch ( V_233 ) {
case V_239 :
break;
case V_248 :
V_178 = F_212 ( V_178 * V_229 [ V_184 ] ,
V_230 ) ;
break;
case V_238 :
case V_246 :
if ( ( V_233 == V_238 ) != V_184 ) {
V_30 = 0 ;
V_178 = 0 ;
}
break;
default:
F_160 () ;
}
* V_227 += V_30 ;
V_8 [ V_23 ] = V_178 ;
}
}
static void F_213 ( struct V_13 * V_14 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_227 )
{
struct V_21 * V_21 = F_214 ( V_14 , V_5 ) ;
unsigned long V_8 [ V_251 ] ;
unsigned long V_252 [ V_251 ] ;
unsigned long V_61 ;
enum V_22 V_23 ;
unsigned long V_134 = 0 ;
unsigned long V_253 = V_2 -> V_253 ;
struct V_254 V_255 ;
bool V_256 ;
F_206 ( V_21 , V_5 , V_2 , V_8 , V_227 ) ;
memcpy ( V_252 , V_8 , sizeof( V_8 ) ) ;
V_256 = ( F_1 ( V_2 ) && ! F_117 () &&
V_2 -> V_158 == V_159 ) ;
F_215 ( & V_255 ) ;
while ( V_8 [ V_245 ] || V_8 [ V_250 ] ||
V_8 [ V_247 ] ) {
unsigned long V_257 , V_258 , V_259 ;
unsigned long V_44 ;
F_211 (lru) {
if ( V_8 [ V_23 ] ) {
V_61 = F_18 ( V_8 [ V_23 ] , V_65 ) ;
V_8 [ V_23 ] -= V_61 ;
V_134 += F_205 ( V_23 , V_61 ,
V_21 , V_5 , V_2 ) ;
}
}
F_33 () ;
if ( V_134 < V_253 || V_256 )
continue;
V_258 = V_8 [ V_247 ] + V_8 [ V_250 ] ;
V_257 = V_8 [ V_245 ] + V_8 [ V_249 ] ;
if ( ! V_258 || ! V_257 )
break;
if ( V_258 > V_257 ) {
unsigned long V_260 = V_252 [ V_245 ] +
V_252 [ V_249 ] + 1 ;
V_23 = V_261 ;
V_259 = V_257 * 100 / V_260 ;
} else {
unsigned long V_260 = V_252 [ V_247 ] +
V_252 [ V_250 ] + 1 ;
V_23 = V_218 ;
V_259 = V_258 * 100 / V_260 ;
}
V_8 [ V_23 ] = 0 ;
V_8 [ V_23 + V_215 ] = 0 ;
V_23 = ( V_23 == V_218 ) ? V_261 : V_218 ;
V_44 = V_252 [ V_23 ] - V_8 [ V_23 ] ;
V_8 [ V_23 ] = V_252 [ V_23 ] * ( 100 - V_259 ) / 100 ;
V_8 [ V_23 ] -= F_18 ( V_8 [ V_23 ] , V_44 ) ;
V_23 += V_215 ;
V_44 = V_252 [ V_23 ] - V_8 [ V_23 ] ;
V_8 [ V_23 ] = V_252 [ V_23 ] * ( 100 - V_259 ) / 100 ;
V_8 [ V_23 ] -= F_18 ( V_8 [ V_23 ] , V_44 ) ;
V_256 = true ;
}
F_216 ( & V_255 ) ;
V_2 -> V_134 += V_134 ;
if ( F_201 ( V_21 , false , V_5 , V_2 , true ) )
F_199 ( V_65 , V_21 ,
V_2 , V_249 ) ;
}
static bool F_217 ( struct V_1 * V_2 )
{
if ( F_218 ( V_262 ) && V_2 -> V_183 &&
( V_2 -> V_183 > V_263 ||
V_2 -> V_158 < V_159 - 2 ) )
return true ;
return false ;
}
static inline bool F_219 ( struct V_13 * V_14 ,
unsigned long V_134 ,
unsigned long V_44 ,
struct V_1 * V_2 )
{
unsigned long V_264 ;
unsigned long V_265 ;
int V_242 ;
if ( ! F_217 ( V_2 ) )
return false ;
if ( V_2 -> V_64 & V_266 ) {
if ( ! V_134 && ! V_44 )
return false ;
} else {
if ( ! V_134 )
return false ;
}
V_264 = F_220 ( V_2 -> V_183 ) ;
V_265 = F_13 ( V_14 , V_16 ) ;
if ( F_7 () > 0 )
V_265 += F_13 ( V_14 , V_19 ) ;
if ( V_2 -> V_134 < V_264 &&
V_265 > V_264 )
return true ;
for ( V_242 = 0 ; V_242 <= V_2 -> V_181 ; V_242 ++ ) {
struct V_7 * V_7 = & V_14 -> V_29 [ V_242 ] ;
if ( ! F_15 ( V_7 ) )
continue;
switch ( F_221 ( V_7 , V_2 -> V_183 , 0 , V_2 -> V_181 ) ) {
case V_267 :
case V_268 :
return false ;
default:
;
}
}
return true ;
}
static bool F_222 ( T_9 * V_14 , struct V_1 * V_2 )
{
struct V_269 * V_269 = V_72 -> V_269 ;
unsigned long V_134 , V_44 ;
bool V_270 = false ;
do {
struct V_4 * V_271 = V_2 -> V_3 ;
struct V_272 V_273 = {
. V_14 = V_14 ,
. V_158 = V_2 -> V_158 ,
} ;
unsigned long V_274 = 0 ;
struct V_4 * V_5 ;
V_134 = V_2 -> V_134 ;
V_44 = V_2 -> V_44 ;
V_5 = F_44 ( V_271 , NULL , & V_273 ) ;
do {
unsigned long V_227 ;
unsigned long V_97 ;
unsigned long V_55 ;
if ( F_223 ( V_271 , V_5 ) ) {
if ( ! V_2 -> V_275 ) {
V_2 -> V_276 = 1 ;
continue;
}
F_224 ( V_5 , V_277 ) ;
}
V_97 = V_2 -> V_134 ;
V_55 = V_2 -> V_44 ;
F_213 ( V_14 , V_5 , V_2 , & V_227 ) ;
V_274 += V_227 ;
if ( V_5 )
F_37 ( V_2 -> V_64 , V_14 -> V_205 ,
V_5 , V_2 -> V_44 - V_55 ,
V_227 ) ;
F_225 ( V_2 -> V_64 , V_5 , false ,
V_2 -> V_44 - V_55 ,
V_2 -> V_134 - V_97 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_134 >= V_2 -> V_253 ) {
F_226 ( V_271 , V_5 ) ;
break;
}
} while ( ( V_5 = F_44 ( V_271 , V_5 , & V_273 ) ) );
if ( F_1 ( V_2 ) )
F_37 ( V_2 -> V_64 , V_14 -> V_205 , NULL ,
V_2 -> V_44 - V_44 ,
V_274 ) ;
if ( V_269 ) {
V_2 -> V_134 += V_269 -> V_278 ;
V_269 -> V_278 = 0 ;
}
F_225 ( V_2 -> V_64 , V_2 -> V_3 , true ,
V_2 -> V_44 - V_44 ,
V_2 -> V_134 - V_134 ) ;
if ( V_2 -> V_134 - V_134 )
V_270 = true ;
} while ( F_219 ( V_14 , V_2 -> V_134 - V_134 ,
V_2 -> V_44 - V_44 , V_2 ) );
if ( V_270 )
V_14 -> V_279 = 0 ;
return V_270 ;
}
static inline bool F_227 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
unsigned long V_280 ;
enum V_281 V_282 ;
V_282 = F_221 ( V_7 , V_2 -> V_183 , 0 , V_2 -> V_181 ) ;
if ( V_282 == V_267 )
return true ;
if ( V_282 == V_283 )
return false ;
V_280 = F_210 ( V_7 ) + F_220 ( V_2 -> V_183 ) ;
return F_228 ( V_7 , 0 , V_280 , V_2 -> V_181 ) ;
}
static void F_229 ( struct V_284 * V_284 , struct V_1 * V_2 )
{
struct V_285 * V_242 ;
struct V_7 * V_7 ;
unsigned long V_286 ;
unsigned long V_287 ;
T_2 V_288 ;
T_9 * V_289 = NULL ;
V_288 = V_2 -> V_64 ;
if ( V_214 ) {
V_2 -> V_64 |= V_290 ;
V_2 -> V_181 = F_230 ( V_2 -> V_64 ) ;
}
F_231 (zone, z, zonelist,
sc->reclaim_idx, sc->nodemask) {
if ( F_1 ( V_2 ) ) {
if ( ! F_232 ( V_7 ,
V_37 | V_291 ) )
continue;
if ( F_218 ( V_262 ) &&
V_2 -> V_183 > V_263 &&
F_227 ( V_7 , V_2 ) ) {
V_2 -> F_227 = true ;
continue;
}
if ( V_7 -> V_162 == V_289 )
continue;
V_287 = 0 ;
V_286 = F_233 ( V_7 -> V_162 ,
V_2 -> V_183 , V_2 -> V_64 ,
& V_287 ) ;
V_2 -> V_134 += V_286 ;
V_2 -> V_44 += V_287 ;
}
if ( V_7 -> V_162 == V_289 )
continue;
V_289 = V_7 -> V_162 ;
F_222 ( V_7 -> V_162 , V_2 ) ;
}
V_2 -> V_64 = V_288 ;
}
static void F_234 ( struct V_4 * V_292 , T_9 * V_14 )
{
struct V_4 * V_5 ;
V_5 = F_44 ( V_292 , NULL , NULL ) ;
do {
unsigned long V_222 ;
struct V_21 * V_21 ;
if ( V_5 )
V_222 = F_202 ( V_5 , V_225 ) ;
else
V_222 = F_13 ( V_14 , V_225 ) ;
V_21 = F_214 ( V_14 , V_5 ) ;
V_21 -> V_222 = V_222 ;
} while ( ( V_5 = F_44 ( V_292 , V_5 , NULL ) ) );
}
static unsigned long F_235 ( struct V_284 * V_284 ,
struct V_1 * V_2 )
{
int V_293 = V_2 -> V_158 ;
T_9 * V_289 ;
struct V_285 * V_242 ;
struct V_7 * V_7 ;
V_294:
F_236 () ;
if ( F_1 ( V_2 ) )
F_161 ( V_295 , V_2 -> V_181 , 1 ) ;
do {
F_237 ( V_2 -> V_64 , V_2 -> V_3 ,
V_2 -> V_158 ) ;
V_2 -> V_44 = 0 ;
F_229 ( V_284 , V_2 ) ;
if ( V_2 -> V_134 >= V_2 -> V_253 )
break;
if ( V_2 -> F_227 )
break;
if ( V_2 -> V_158 < V_159 - 2 )
V_2 -> V_153 = 1 ;
} while ( -- V_2 -> V_158 >= 0 );
V_289 = NULL ;
F_231 (zone, z, zonelist, sc->reclaim_idx,
sc->nodemask) {
if ( V_7 -> V_162 == V_289 )
continue;
V_289 = V_7 -> V_162 ;
F_234 ( V_2 -> V_3 , V_7 -> V_162 ) ;
}
F_238 () ;
if ( V_2 -> V_134 )
return V_2 -> V_134 ;
if ( V_2 -> F_227 )
return 1 ;
if ( V_2 -> V_276 ) {
V_2 -> V_158 = V_293 ;
V_2 -> V_275 = 1 ;
V_2 -> V_276 = 0 ;
goto V_294;
}
return 0 ;
}
static bool F_239 ( T_9 * V_14 )
{
struct V_7 * V_7 ;
unsigned long V_296 = 0 ;
unsigned long V_129 = 0 ;
int V_297 ;
bool V_298 ;
if ( V_14 -> V_279 >= V_299 )
return true ;
for ( V_297 = 0 ; V_297 <= V_300 ; V_297 ++ ) {
V_7 = & V_14 -> V_29 [ V_297 ] ;
if ( ! F_15 ( V_7 ) )
continue;
if ( ! F_5 ( V_7 ) )
continue;
V_296 += F_240 ( V_7 ) ;
V_129 += F_17 ( V_7 , V_244 ) ;
}
if ( ! V_296 )
return true ;
V_298 = V_129 > V_296 / 2 ;
if ( ! V_298 && F_241 ( & V_14 -> V_301 ) ) {
V_14 -> V_302 = F_18 ( V_14 -> V_302 ,
(enum V_303 ) V_300 ) ;
F_242 ( & V_14 -> V_301 ) ;
}
return V_298 ;
}
static bool F_243 ( T_2 V_64 , struct V_284 * V_284 ,
T_10 * V_304 )
{
struct V_285 * V_242 ;
struct V_7 * V_7 ;
T_9 * V_14 = NULL ;
if ( V_72 -> V_34 & V_305 )
goto V_66;
if ( F_186 ( V_72 ) )
goto V_66;
F_231 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( V_24 ( V_7 ) > V_300 )
continue;
V_14 = V_7 -> V_162 ;
if ( F_239 ( V_14 ) )
goto V_66;
break;
}
if ( ! V_14 )
goto V_66;
F_101 ( V_306 ) ;
if ( ! ( V_64 & V_145 ) ) {
F_244 ( V_14 -> V_307 ,
F_239 ( V_14 ) , V_203 ) ;
goto V_308;
}
F_245 ( V_7 -> V_162 -> V_307 ,
F_239 ( V_14 ) ) ;
V_308:
if ( F_186 ( V_72 ) )
return true ;
V_66:
return false ;
}
unsigned long F_246 ( struct V_284 * V_284 , int V_183 ,
T_2 V_64 , T_10 * V_304 )
{
unsigned long V_134 ;
struct V_1 V_2 = {
. V_253 = V_65 ,
. V_64 = F_247 ( V_64 ) ,
. V_181 = F_230 ( V_64 ) ,
. V_183 = V_183 ,
. V_304 = V_304 ,
. V_158 = V_159 ,
. V_153 = ! V_309 ,
. V_143 = 1 ,
. V_237 = 1 ,
} ;
if ( F_243 ( V_2 . V_64 , V_284 , V_304 ) )
return 1 ;
F_248 ( V_183 ,
V_2 . V_153 ,
V_2 . V_64 ,
V_2 . V_181 ) ;
V_134 = F_235 ( V_284 , & V_2 ) ;
F_249 ( V_134 ) ;
return V_134 ;
}
unsigned long F_250 ( struct V_4 * V_5 ,
T_2 V_64 , bool V_310 ,
T_9 * V_14 ,
unsigned long * V_44 )
{
struct V_1 V_2 = {
. V_253 = V_65 ,
. V_3 = V_5 ,
. V_153 = ! V_309 ,
. V_143 = 1 ,
. V_181 = V_28 - 1 ,
. V_237 = ! V_310 ,
} ;
unsigned long V_227 ;
V_2 . V_64 = ( V_64 & V_311 ) |
( V_312 & ~ V_311 ) ;
F_251 ( V_2 . V_183 ,
V_2 . V_153 ,
V_2 . V_64 ,
V_2 . V_181 ) ;
F_213 ( V_14 , V_5 , & V_2 , & V_227 ) ;
F_252 ( V_2 . V_134 ) ;
* V_44 = V_2 . V_44 ;
return V_2 . V_134 ;
}
unsigned long F_253 ( struct V_4 * V_5 ,
unsigned long V_179 ,
T_2 V_64 ,
bool V_237 )
{
struct V_284 * V_284 ;
unsigned long V_134 ;
int V_51 ;
unsigned int V_313 ;
struct V_1 V_2 = {
. V_253 = F_254 ( V_179 , V_65 ) ,
. V_64 = ( F_247 ( V_64 ) & V_311 ) |
( V_312 & ~ V_311 ) ,
. V_181 = V_28 - 1 ,
. V_3 = V_5 ,
. V_158 = V_159 ,
. V_153 = ! V_309 ,
. V_143 = 1 ,
. V_237 = V_237 ,
} ;
V_51 = F_255 ( V_5 ) ;
V_284 = & F_256 ( V_51 ) -> V_314 [ V_315 ] ;
F_257 ( 0 ,
V_2 . V_153 ,
V_2 . V_64 ,
V_2 . V_181 ) ;
V_313 = F_258 () ;
V_134 = F_235 ( V_284 , & V_2 ) ;
F_259 ( V_313 ) ;
F_260 ( V_134 ) ;
return V_134 ;
}
static void F_261 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_224 )
return;
V_5 = F_44 ( NULL , NULL , NULL ) ;
do {
struct V_21 * V_21 = F_214 ( V_14 , V_5 ) ;
if ( F_201 ( V_21 , false , V_5 , V_2 , true ) )
F_199 ( V_65 , V_21 ,
V_2 , V_249 ) ;
V_5 = F_44 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_262 ( T_9 * V_14 , int V_183 , int V_316 )
{
int V_297 ;
unsigned long V_317 = - 1 ;
struct V_7 * V_7 ;
for ( V_297 = 0 ; V_297 <= V_316 ; V_297 ++ ) {
V_7 = V_14 -> V_29 + V_297 ;
if ( ! F_15 ( V_7 ) )
continue;
V_317 = F_210 ( V_7 ) ;
if ( F_228 ( V_7 , V_183 , V_317 , V_316 ) )
return true ;
}
if ( V_317 == - 1 )
return true ;
return false ;
}
static void F_263 ( T_9 * V_14 )
{
F_264 ( V_200 , & V_14 -> V_34 ) ;
F_264 ( V_151 , & V_14 -> V_34 ) ;
F_264 ( V_147 , & V_14 -> V_34 ) ;
}
static bool F_265 ( T_9 * V_14 , int V_183 , int V_316 )
{
if ( F_241 ( & V_14 -> V_307 ) )
F_266 ( & V_14 -> V_307 ) ;
if ( V_14 -> V_279 >= V_299 )
return true ;
if ( F_262 ( V_14 , V_183 , V_316 ) ) {
F_263 ( V_14 ) ;
return true ;
}
return false ;
}
static bool F_267 ( T_9 * V_14 ,
struct V_1 * V_2 )
{
struct V_7 * V_7 ;
int V_242 ;
V_2 -> V_253 = 0 ;
for ( V_242 = 0 ; V_242 <= V_2 -> V_181 ; V_242 ++ ) {
V_7 = V_14 -> V_29 + V_242 ;
if ( ! F_15 ( V_7 ) )
continue;
V_2 -> V_253 += F_254 ( F_210 ( V_7 ) , V_65 ) ;
}
F_222 ( V_14 , V_2 ) ;
if ( V_2 -> V_183 && V_2 -> V_134 >= F_220 ( V_2 -> V_183 ) )
V_2 -> V_183 = 0 ;
return V_2 -> V_44 >= V_2 -> V_253 ;
}
static int F_268 ( T_9 * V_14 , int V_183 , int V_316 )
{
int V_297 ;
unsigned long V_286 ;
unsigned long V_287 ;
struct V_7 * V_7 ;
struct V_1 V_2 = {
. V_64 = V_37 ,
. V_183 = V_183 ,
. V_158 = V_159 ,
. V_153 = ! V_309 ,
. V_143 = 1 ,
. V_237 = 1 ,
} ;
F_101 ( V_318 ) ;
do {
unsigned long V_134 = V_2 . V_134 ;
bool V_319 = true ;
V_2 . V_181 = V_316 ;
if ( V_214 ) {
for ( V_297 = V_28 - 1 ; V_297 >= 0 ; V_297 -- ) {
V_7 = V_14 -> V_29 + V_297 ;
if ( ! F_15 ( V_7 ) )
continue;
V_2 . V_181 = V_297 ;
break;
}
}
if ( F_262 ( V_14 , V_2 . V_183 , V_316 ) )
goto V_66;
F_261 ( V_14 , & V_2 ) ;
if ( V_2 . V_158 < V_159 - 2 )
V_2 . V_153 = 1 ;
V_2 . V_44 = 0 ;
V_287 = 0 ;
V_286 = F_233 ( V_14 , V_2 . V_183 ,
V_2 . V_64 , & V_287 ) ;
V_2 . V_134 += V_286 ;
if ( F_267 ( V_14 , & V_2 ) )
V_319 = false ;
if ( F_241 ( & V_14 -> V_307 ) &&
F_239 ( V_14 ) )
F_266 ( & V_14 -> V_307 ) ;
if ( F_269 () || F_270 () )
break;
V_134 = V_2 . V_134 - V_134 ;
if ( V_319 || ! V_134 )
V_2 . V_158 -- ;
} while ( V_2 . V_158 >= 1 );
if ( ! V_2 . V_134 )
V_14 -> V_279 ++ ;
V_66:
F_234 ( NULL , V_14 ) ;
return V_2 . V_183 ;
}
static enum V_303 V_302 ( T_9 * V_14 ,
enum V_303 V_316 )
{
if ( V_14 -> V_302 == V_28 )
return V_316 ;
return F_254 ( V_14 -> V_302 , V_316 ) ;
}
static void F_271 ( T_9 * V_14 , int V_320 , int V_321 ,
unsigned int V_316 )
{
long V_322 = 0 ;
F_272 ( V_323 ) ;
if ( F_273 ( V_72 ) || F_270 () )
return;
F_274 ( & V_14 -> V_301 , & V_323 , V_324 ) ;
if ( F_265 ( V_14 , V_321 , V_316 ) ) {
F_275 ( V_14 ) ;
F_276 ( V_14 , V_320 , V_316 ) ;
V_322 = F_277 ( V_203 / 10 ) ;
if ( V_322 ) {
V_14 -> V_302 = V_302 ( V_14 , V_316 ) ;
V_14 -> V_325 = F_254 ( V_14 -> V_325 , V_321 ) ;
}
F_278 ( & V_14 -> V_301 , & V_323 ) ;
F_274 ( & V_14 -> V_301 , & V_323 , V_324 ) ;
}
if ( ! V_322 &&
F_265 ( V_14 , V_321 , V_316 ) ) {
F_279 ( V_14 -> V_205 ) ;
F_280 ( V_14 , V_326 ) ;
if ( ! F_270 () )
F_281 () ;
F_280 ( V_14 , V_327 ) ;
} else {
if ( V_322 )
F_101 ( V_328 ) ;
else
F_101 ( V_329 ) ;
}
F_278 ( & V_14 -> V_301 , & V_323 ) ;
}
static int F_282 ( void * V_330 )
{
unsigned int V_320 , V_321 ;
unsigned int V_316 = V_28 - 1 ;
T_9 * V_14 = ( T_9 * ) V_330 ;
struct V_331 * V_332 = V_72 ;
struct V_269 V_269 = {
. V_278 = 0 ,
} ;
const struct V_333 * V_333 = F_283 ( V_14 -> V_205 ) ;
if ( ! F_284 ( V_333 ) )
F_285 ( V_332 , V_333 ) ;
V_72 -> V_269 = & V_269 ;
V_332 -> V_34 |= V_334 | V_73 | V_335 ;
F_286 () ;
V_14 -> V_325 = 0 ;
V_14 -> V_302 = V_28 ;
for ( ; ; ) {
bool V_60 ;
V_320 = V_321 = V_14 -> V_325 ;
V_316 = V_302 ( V_14 , V_316 ) ;
V_336:
F_271 ( V_14 , V_320 , V_321 ,
V_316 ) ;
V_320 = V_321 = V_14 -> V_325 ;
V_316 = V_302 ( V_14 , 0 ) ;
V_14 -> V_325 = 0 ;
V_14 -> V_302 = V_28 ;
V_60 = F_269 () ;
if ( F_270 () )
break;
if ( V_60 )
continue;
F_287 ( V_14 -> V_205 , V_316 ,
V_320 ) ;
F_288 ( V_37 ) ;
V_321 = F_268 ( V_14 , V_320 , V_316 ) ;
F_289 ( V_37 ) ;
if ( V_321 < V_320 )
goto V_336;
}
V_332 -> V_34 &= ~ ( V_334 | V_73 | V_335 ) ;
V_72 -> V_269 = NULL ;
return 0 ;
}
void F_290 ( struct V_7 * V_7 , int V_183 , enum V_303 V_316 )
{
T_9 * V_14 ;
if ( ! F_15 ( V_7 ) )
return;
if ( ! F_232 ( V_7 , V_37 | V_291 ) )
return;
V_14 = V_7 -> V_162 ;
V_14 -> V_302 = V_302 ( V_14 ,
V_316 ) ;
V_14 -> V_325 = F_254 ( V_14 -> V_325 , V_183 ) ;
if ( ! F_241 ( & V_14 -> V_301 ) )
return;
if ( V_14 -> V_279 >= V_299 )
return;
if ( F_262 ( V_14 , V_183 , V_316 ) )
return;
F_291 ( V_14 -> V_205 , V_316 , V_183 ) ;
F_242 ( & V_14 -> V_301 ) ;
}
unsigned long F_292 ( unsigned long V_253 )
{
struct V_269 V_269 ;
struct V_1 V_2 = {
. V_253 = V_253 ,
. V_64 = V_312 ,
. V_181 = V_28 - 1 ,
. V_158 = V_159 ,
. V_153 = 1 ,
. V_143 = 1 ,
. V_237 = 1 ,
. V_204 = 1 ,
} ;
struct V_284 * V_284 = F_293 ( F_294 () , V_2 . V_64 ) ;
struct V_331 * V_330 = V_72 ;
unsigned long V_134 ;
unsigned int V_313 ;
V_313 = F_258 () ;
F_288 ( V_2 . V_64 ) ;
V_269 . V_278 = 0 ;
V_330 -> V_269 = & V_269 ;
V_134 = F_235 ( V_284 , & V_2 ) ;
V_330 -> V_269 = NULL ;
F_289 ( V_2 . V_64 ) ;
F_259 ( V_313 ) ;
return V_134 ;
}
static int F_295 ( unsigned int V_337 )
{
int V_51 ;
F_296 (nid, N_MEMORY) {
T_9 * V_14 = F_256 ( V_51 ) ;
const struct V_333 * V_338 ;
V_338 = F_283 ( V_14 -> V_205 ) ;
if ( F_297 ( V_339 , V_338 ) < V_340 )
F_285 ( V_14 -> F_282 , V_338 ) ;
}
return 0 ;
}
int F_298 ( int V_51 )
{
T_9 * V_14 = F_256 ( V_51 ) ;
int V_60 = 0 ;
if ( V_14 -> F_282 )
return 0 ;
V_14 -> F_282 = F_299 ( F_282 , V_14 , L_4 , V_51 ) ;
if ( F_300 ( V_14 -> F_282 ) ) {
F_71 ( V_341 < V_342 ) ;
F_30 ( L_5 , V_51 ) ;
V_60 = F_301 ( V_14 -> F_282 ) ;
V_14 -> F_282 = NULL ;
}
return V_60 ;
}
void F_302 ( int V_51 )
{
struct V_331 * F_282 = F_256 ( V_51 ) -> F_282 ;
if ( F_282 ) {
F_303 ( F_282 ) ;
F_256 ( V_51 ) -> F_282 = NULL ;
}
}
static int T_11 F_304 ( void )
{
int V_51 , V_60 ;
F_305 () ;
F_296 (nid, N_MEMORY)
F_298 ( V_51 ) ;
V_60 = F_306 ( V_343 ,
L_6 , F_295 ,
NULL ) ;
F_307 ( V_60 < 0 ) ;
return 0 ;
}
static inline unsigned long F_308 ( struct V_13 * V_14 )
{
unsigned long V_344 = F_13 ( V_14 , V_345 ) ;
unsigned long V_346 = F_13 ( V_14 , V_16 ) +
F_13 ( V_14 , V_15 ) ;
return ( V_346 > V_344 ) ? ( V_346 - V_344 ) : 0 ;
}
static unsigned long F_309 ( struct V_13 * V_14 )
{
unsigned long V_347 ;
unsigned long V_47 = 0 ;
if ( V_348 & V_349 )
V_347 = F_13 ( V_14 , V_350 ) ;
else
V_347 = F_308 ( V_14 ) ;
if ( ! ( V_348 & V_351 ) )
V_47 += F_13 ( V_14 , V_352 ) ;
if ( F_74 ( V_47 > V_347 ) )
V_47 = V_347 ;
return V_347 - V_47 ;
}
static int F_310 ( struct V_13 * V_14 , T_2 V_64 , unsigned int V_183 )
{
const unsigned long V_179 = 1 << V_183 ;
struct V_331 * V_330 = V_72 ;
struct V_269 V_269 ;
unsigned int V_313 ;
struct V_1 V_2 = {
. V_253 = F_254 ( V_179 , V_65 ) ,
. V_64 = F_247 ( V_64 ) ,
. V_183 = V_183 ,
. V_158 = V_353 ,
. V_153 = ! ! ( V_348 & V_351 ) ,
. V_143 = ! ! ( V_348 & V_349 ) ,
. V_237 = 1 ,
. V_181 = F_230 ( V_64 ) ,
} ;
F_33 () ;
V_313 = F_258 () ;
V_330 -> V_34 |= V_73 ;
F_288 ( V_2 . V_64 ) ;
V_269 . V_278 = 0 ;
V_330 -> V_269 = & V_269 ;
if ( F_309 ( V_14 ) > V_14 -> V_354 ) {
do {
F_222 ( V_14 , & V_2 ) ;
} while ( V_2 . V_134 < V_179 && -- V_2 . V_158 >= 0 );
}
V_330 -> V_269 = NULL ;
F_289 ( V_64 ) ;
V_72 -> V_34 &= ~ V_73 ;
F_259 ( V_313 ) ;
return V_2 . V_134 >= V_179 ;
}
int F_311 ( struct V_13 * V_14 , T_2 V_64 , unsigned int V_183 )
{
int V_60 ;
if ( F_309 ( V_14 ) <= V_14 -> V_354 &&
F_13 ( V_14 , V_355 ) <= V_14 -> V_356 )
return V_357 ;
if ( ! F_312 ( V_64 ) || ( V_72 -> V_34 & V_334 ) )
return V_358 ;
if ( F_313 ( V_14 -> V_205 , V_359 ) && V_14 -> V_205 != F_294 () )
return V_358 ;
if ( F_314 ( V_360 , & V_14 -> V_34 ) )
return V_358 ;
V_60 = F_310 ( V_14 , V_64 , V_183 ) ;
F_264 ( V_360 , & V_14 -> V_34 ) ;
if ( ! V_60 )
F_101 ( V_361 ) ;
return V_60 ;
}
int F_95 ( struct V_68 * V_68 )
{
return ! F_315 ( F_57 ( V_68 ) ) && ! F_135 ( V_68 ) ;
}
void F_316 ( struct V_68 * * V_362 , int V_179 )
{
struct V_21 * V_21 ;
struct V_13 * V_14 = NULL ;
int V_363 = 0 ;
int V_364 = 0 ;
int V_297 ;
for ( V_297 = 0 ; V_297 < V_179 ; V_297 ++ ) {
struct V_68 * V_68 = V_362 [ V_297 ] ;
struct V_13 * V_365 = F_317 ( V_68 ) ;
V_363 ++ ;
if ( V_365 != V_14 ) {
if ( V_14 )
F_172 ( & V_14 -> V_189 ) ;
V_14 = V_365 ;
F_166 ( & V_14 -> V_189 ) ;
}
V_21 = F_168 ( V_68 , V_14 ) ;
if ( ! F_93 ( V_68 ) || ! F_91 ( V_68 ) )
continue;
if ( F_95 ( V_68 ) ) {
enum V_22 V_23 = F_318 ( V_68 ) ;
F_92 ( F_114 ( V_68 ) , V_68 ) ;
F_94 ( V_68 ) ;
F_171 ( V_68 , V_21 , V_366 ) ;
F_176 ( V_68 , V_21 , V_23 ) ;
V_364 ++ ;
}
}
if ( V_14 ) {
F_189 ( V_107 , V_364 ) ;
F_189 ( V_367 , V_363 ) ;
F_172 ( & V_14 -> V_189 ) ;
}
}
