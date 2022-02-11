static bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return true ;
}
static unsigned long F_2 ( struct V_4 * V_4 )
{
int V_5 ;
V_5 = F_3 ( V_4 , V_6 ) +
F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_5 += F_3 ( V_4 , V_8 ) +
F_3 ( V_4 , V_9 ) ;
return V_5 ;
}
bool F_5 ( struct V_4 * V_4 )
{
return F_3 ( V_4 , V_10 ) <
F_2 ( V_4 ) * 6 ;
}
static unsigned long F_6 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( ! F_7 () )
return F_8 ( V_11 , V_13 ) ;
return F_3 ( F_9 ( V_11 ) , V_14 + V_13 ) ;
}
int F_10 ( struct V_15 * V_15 )
{
T_1 V_16 = sizeof( * V_15 -> V_17 ) ;
if ( V_18 == 1 )
V_15 -> V_19 &= ~ V_20 ;
if ( V_15 -> V_19 & V_20 )
V_16 *= V_18 ;
V_15 -> V_17 = F_11 ( V_16 , V_21 ) ;
if ( ! V_15 -> V_17 )
return - V_22 ;
F_12 ( & V_23 ) ;
F_13 ( & V_15 -> V_24 , & V_25 ) ;
F_14 ( & V_23 ) ;
return 0 ;
}
void F_15 ( struct V_15 * V_15 )
{
F_12 ( & V_23 ) ;
F_16 ( & V_15 -> V_24 ) ;
F_14 ( & V_23 ) ;
F_17 ( V_15 -> V_17 ) ;
}
static unsigned long F_18 ( struct V_26 * V_27 ,
struct V_15 * V_15 ,
unsigned long V_28 ,
unsigned long V_29 )
{
unsigned long V_30 = 0 ;
unsigned long long V_31 ;
long V_32 ;
long V_33 ;
long V_5 ;
long V_34 ;
int V_35 = V_27 -> V_35 ;
long V_36 = V_15 -> V_37 ? V_15 -> V_37
: V_38 ;
V_33 = V_15 -> V_39 ( V_15 , V_27 ) ;
if ( V_33 == 0 )
return 0 ;
V_5 = F_19 ( & V_15 -> V_17 [ V_35 ] , 0 ) ;
V_32 = V_5 ;
V_31 = ( 4 * V_28 ) / V_15 -> V_40 ;
V_31 *= V_33 ;
F_20 ( V_31 , V_29 + 1 ) ;
V_32 += V_31 ;
if ( V_32 < 0 ) {
F_21 ( L_1 ,
V_15 -> V_41 , V_32 ) ;
V_32 = V_33 ;
}
if ( V_31 < V_33 / 4 )
V_32 = F_22 ( V_32 , V_33 / 2 ) ;
if ( V_32 > V_33 * 2 )
V_32 = V_33 * 2 ;
F_23 ( V_15 , V_27 , V_5 ,
V_28 , V_29 ,
V_33 , V_31 , V_32 ) ;
while ( V_32 >= V_36 ||
V_32 >= V_33 ) {
unsigned long V_42 ;
unsigned long V_43 = F_22 ( V_36 , V_32 ) ;
V_27 -> V_43 = V_43 ;
V_42 = V_15 -> V_41 ( V_15 , V_27 ) ;
if ( V_42 == V_44 )
break;
V_30 += V_42 ;
F_24 ( V_45 , V_43 ) ;
V_32 -= V_43 ;
F_25 () ;
}
if ( V_32 > 0 )
V_34 = F_26 ( V_32 ,
& V_15 -> V_17 [ V_35 ] ) ;
else
V_34 = F_27 ( & V_15 -> V_17 [ V_35 ] ) ;
F_28 ( V_15 , V_35 , V_30 , V_5 , V_34 , V_32 ) ;
return V_30 ;
}
static unsigned long F_29 ( T_2 V_46 , int V_35 ,
struct V_47 * V_48 ,
unsigned long V_28 ,
unsigned long V_29 )
{
struct V_15 * V_15 ;
unsigned long V_30 = 0 ;
if ( V_48 && ! F_30 ( V_48 ) )
return 0 ;
if ( V_28 == 0 )
V_28 = V_49 ;
if ( ! F_31 ( & V_23 ) ) {
V_30 = 1 ;
goto V_50;
}
F_32 (shrinker, &shrinker_list, list) {
struct V_26 V_2 = {
. V_46 = V_46 ,
. V_35 = V_35 ,
. V_48 = V_48 ,
} ;
if ( V_48 && ! ( V_15 -> V_19 & V_51 ) )
continue;
if ( ! ( V_15 -> V_19 & V_20 ) )
V_2 . V_35 = 0 ;
V_30 += F_18 ( & V_2 , V_15 , V_28 , V_29 ) ;
}
F_33 ( & V_23 ) ;
V_50:
F_25 () ;
return V_30 ;
}
void F_34 ( int V_35 )
{
unsigned long V_30 ;
do {
struct V_47 * V_48 = NULL ;
V_30 = 0 ;
do {
V_30 += F_29 ( V_21 , V_35 , V_48 ,
1000 , 1000 ) ;
} while ( ( V_48 = F_35 ( NULL , V_48 , NULL ) ) != NULL );
} while ( V_30 > 10 );
}
void F_36 ( void )
{
int V_35 ;
F_37 (nid)
F_34 ( V_35 ) ;
}
static inline int F_38 ( struct V_52 * V_52 )
{
return F_39 ( V_52 ) - F_40 ( V_52 ) == 2 ;
}
static int F_41 ( struct V_53 * V_54 ,
struct V_1 * V_2 )
{
if ( V_55 -> V_19 & V_56 )
return 1 ;
if ( ! F_42 ( V_54 ) )
return 1 ;
if ( V_54 == V_55 -> V_53 )
return 1 ;
return 0 ;
}
static void F_43 ( struct V_57 * V_58 ,
struct V_52 * V_52 , int error )
{
F_44 ( V_52 ) ;
if ( F_45 ( V_52 ) == V_58 )
F_46 ( V_58 , error ) ;
F_47 ( V_52 ) ;
}
static T_3 F_48 ( struct V_52 * V_52 , struct V_57 * V_58 ,
struct V_1 * V_2 )
{
if ( ! F_38 ( V_52 ) )
return V_59 ;
if ( ! V_58 ) {
if ( F_40 ( V_52 ) ) {
if ( F_49 ( V_52 ) ) {
F_50 ( V_52 ) ;
F_51 ( L_2 , V_60 ) ;
return V_61 ;
}
}
return V_59 ;
}
if ( V_58 -> V_62 -> V_63 == NULL )
return V_64 ;
if ( ! F_41 ( F_52 ( V_58 -> V_65 ) , V_2 ) )
return V_59 ;
if ( F_53 ( V_52 ) ) {
int V_66 ;
struct V_67 V_68 = {
. V_69 = V_70 ,
. V_71 = V_49 ,
. V_72 = 0 ,
. V_73 = V_74 ,
. V_75 = 1 ,
} ;
F_54 ( V_52 ) ;
V_66 = V_58 -> V_62 -> V_63 ( V_52 , & V_68 ) ;
if ( V_66 < 0 )
F_43 ( V_58 , V_52 , V_66 ) ;
if ( V_66 == V_76 ) {
F_55 ( V_52 ) ;
return V_64 ;
}
if ( ! F_56 ( V_52 ) ) {
F_55 ( V_52 ) ;
}
F_57 ( V_52 , F_58 ( V_52 ) ) ;
F_59 ( V_52 , V_77 ) ;
return V_78 ;
}
return V_61 ;
}
static int F_60 ( struct V_57 * V_58 , struct V_52 * V_52 ,
bool V_79 )
{
F_61 ( ! F_62 ( V_52 ) ) ;
F_61 ( V_58 != F_45 ( V_52 ) ) ;
F_63 ( & V_58 -> V_80 ) ;
if ( ! F_64 ( V_52 , 2 ) )
goto V_81;
if ( F_65 ( F_66 ( V_52 ) ) ) {
F_67 ( V_52 , 2 ) ;
goto V_81;
}
if ( F_68 ( V_52 ) ) {
T_4 V_82 = { . V_83 = F_69 (page) } ;
F_70 ( V_52 , V_82 ) ;
F_71 ( V_52 ) ;
F_72 ( & V_58 -> V_80 ) ;
F_73 ( V_82 ) ;
} else {
void (* F_74)( struct V_52 * );
void * V_84 = NULL ;
F_74 = V_58 -> V_62 -> F_74 ;
if ( V_79 && F_75 ( V_52 ) &&
! F_76 ( V_58 ) )
V_84 = F_77 ( V_58 , V_52 ) ;
F_78 ( V_52 , V_84 ) ;
F_72 ( & V_58 -> V_80 ) ;
if ( F_74 != NULL )
F_74 ( V_52 ) ;
}
return 1 ;
V_81:
F_72 ( & V_58 -> V_80 ) ;
return 0 ;
}
int F_79 ( struct V_57 * V_58 , struct V_52 * V_52 )
{
if ( F_60 ( V_58 , V_52 , false ) ) {
F_67 ( V_52 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_80 ( struct V_52 * V_52 )
{
bool V_85 ;
int V_86 = F_81 ( V_52 ) ;
F_82 ( F_83 ( V_52 ) , V_52 ) ;
V_87:
F_84 ( V_52 ) ;
if ( F_85 ( V_52 ) ) {
V_85 = false ;
F_86 ( V_52 ) ;
} else {
V_85 = true ;
F_87 ( V_52 ) ;
F_88 () ;
}
if ( V_85 && F_85 ( V_52 ) ) {
if ( ! F_89 ( V_52 ) ) {
F_90 ( V_52 ) ;
goto V_87;
}
}
if ( V_86 && ! V_85 )
F_91 ( V_88 ) ;
else if ( ! V_86 && V_85 )
F_91 ( V_89 ) ;
F_90 ( V_52 ) ;
}
static enum V_90 F_92 ( struct V_52 * V_52 ,
struct V_1 * V_2 )
{
int V_91 , V_92 ;
unsigned long V_93 ;
V_91 = F_93 ( V_52 , 1 , V_2 -> V_3 ,
& V_93 ) ;
V_92 = F_94 ( V_52 ) ;
if ( V_93 & V_94 )
return V_95 ;
if ( V_91 ) {
if ( F_95 ( V_52 ) )
return V_96 ;
F_96 ( V_52 ) ;
if ( V_92 || V_91 > 1 )
return V_96 ;
if ( V_93 & V_97 )
return V_96 ;
return V_98 ;
}
if ( V_92 && ! F_95 ( V_52 ) )
return V_99 ;
return V_95 ;
}
static void F_97 ( struct V_52 * V_52 ,
bool * V_100 , bool * V_101 )
{
struct V_57 * V_58 ;
if ( ! F_75 ( V_52 ) ) {
* V_100 = false ;
* V_101 = false ;
return;
}
* V_100 = F_66 ( V_52 ) ;
* V_101 = F_56 ( V_52 ) ;
if ( ! F_40 ( V_52 ) )
return;
V_58 = F_45 ( V_52 ) ;
if ( V_58 && V_58 -> V_62 -> V_102 )
V_58 -> V_62 -> V_102 ( V_52 , V_100 , V_101 ) ;
}
static unsigned long F_98 ( struct V_103 * V_104 ,
struct V_4 * V_4 ,
struct V_1 * V_2 ,
enum V_105 V_105 ,
unsigned long * V_106 ,
unsigned long * V_107 ,
unsigned long * V_108 ,
unsigned long * V_109 ,
unsigned long * V_110 ,
bool V_111 )
{
F_99 ( V_112 ) ;
F_99 ( V_113 ) ;
int V_114 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
unsigned long V_117 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
F_25 () ;
while ( ! F_100 ( V_104 ) ) {
struct V_57 * V_58 ;
struct V_52 * V_52 ;
int V_121 ;
enum V_90 V_122 = V_99 ;
bool V_100 , V_101 ;
F_25 () ;
V_52 = F_101 ( V_104 ) ;
F_16 ( & V_52 -> V_13 ) ;
if ( ! F_102 ( V_52 ) )
goto V_123;
F_82 ( F_103 ( V_52 ) , V_52 ) ;
F_82 ( F_104 ( V_52 ) != V_4 , V_52 ) ;
V_2 -> V_28 ++ ;
if ( F_65 ( ! F_85 ( V_52 ) ) )
goto V_124;
if ( ! V_2 -> V_125 && F_105 ( V_52 ) )
goto V_126;
if ( F_105 ( V_52 ) || F_68 ( V_52 ) )
V_2 -> V_28 ++ ;
V_121 = ( V_2 -> V_46 & V_127 ) ||
( F_68 ( V_52 ) && ( V_2 -> V_46 & V_128 ) ) ;
F_97 ( V_52 , & V_100 , & V_101 ) ;
if ( V_100 || V_101 )
V_116 ++ ;
if ( V_100 && ! V_101 )
V_115 ++ ;
V_58 = F_45 ( V_52 ) ;
if ( ( ( V_100 || V_101 ) && V_58 &&
F_42 ( F_52 ( V_58 -> V_65 ) ) ) ||
( V_101 && F_106 ( V_52 ) ) )
V_117 ++ ;
if ( F_56 ( V_52 ) ) {
if ( F_107 () &&
F_106 ( V_52 ) &&
F_108 ( V_129 , & V_4 -> V_19 ) ) {
V_120 ++ ;
goto V_126;
} else if ( F_1 ( V_2 ) ||
! F_106 ( V_52 ) || ! ( V_2 -> V_46 & V_128 ) ) {
F_54 ( V_52 ) ;
V_119 ++ ;
goto V_126;
} else {
F_109 ( V_52 ) ;
}
}
if ( ! V_111 )
V_122 = F_92 ( V_52 , V_2 ) ;
switch ( V_122 ) {
case V_96 :
goto V_130;
case V_98 :
goto V_126;
case V_95 :
case V_99 :
;
}
if ( F_110 ( V_52 ) && ! F_68 ( V_52 ) ) {
if ( ! ( V_2 -> V_46 & V_128 ) )
goto V_126;
if ( ! F_111 ( V_52 , V_104 ) )
goto V_130;
V_121 = 1 ;
V_58 = F_45 ( V_52 ) ;
}
if ( F_105 ( V_52 ) && V_58 ) {
switch ( F_112 ( V_52 , V_105 ) ) {
case V_131 :
goto V_130;
case V_132 :
goto V_126;
case V_133 :
goto V_124;
case V_134 :
;
}
}
if ( F_66 ( V_52 ) ) {
if ( F_75 ( V_52 ) &&
( ! F_107 () ||
! F_108 ( V_135 , & V_4 -> V_19 ) ) ) {
F_59 ( V_52 , V_136 ) ;
F_54 ( V_52 ) ;
goto V_126;
}
if ( V_122 == V_99 )
goto V_126;
if ( ! V_121 )
goto V_126;
if ( ! V_2 -> V_137 )
goto V_126;
switch ( F_48 ( V_52 , V_58 , V_2 ) ) {
case V_59 :
goto V_126;
case V_64 :
goto V_130;
case V_78 :
if ( F_56 ( V_52 ) )
goto V_123;
if ( F_66 ( V_52 ) )
goto V_123;
if ( ! F_102 ( V_52 ) )
goto V_123;
if ( F_66 ( V_52 ) || F_56 ( V_52 ) )
goto V_126;
V_58 = F_45 ( V_52 ) ;
case V_61 :
;
}
}
if ( F_40 ( V_52 ) ) {
if ( ! F_113 ( V_52 , V_2 -> V_46 ) )
goto V_130;
if ( ! V_58 && F_39 ( V_52 ) == 1 ) {
F_47 ( V_52 ) ;
if ( F_114 ( V_52 ) )
goto V_138;
else {
V_118 ++ ;
continue;
}
}
}
if ( ! V_58 || ! F_60 ( V_58 , V_52 , true ) )
goto V_126;
F_115 ( V_52 ) ;
V_138:
V_118 ++ ;
F_116 ( & V_52 -> V_13 , & V_113 ) ;
continue;
V_124:
if ( F_68 ( V_52 ) )
F_117 ( V_52 ) ;
F_47 ( V_52 ) ;
F_80 ( V_52 ) ;
continue;
V_130:
if ( F_68 ( V_52 ) && F_118 () )
F_117 ( V_52 ) ;
F_82 ( F_103 ( V_52 ) , V_52 ) ;
F_119 ( V_52 ) ;
V_114 ++ ;
V_126:
F_47 ( V_52 ) ;
V_123:
F_116 ( & V_52 -> V_13 , & V_112 ) ;
F_82 ( F_83 ( V_52 ) || F_81 ( V_52 ) , V_52 ) ;
}
F_120 ( & V_113 ) ;
F_121 ( & V_113 , true ) ;
F_122 ( & V_112 , V_104 ) ;
F_24 ( V_139 , V_114 ) ;
* V_106 += V_116 ;
* V_108 += V_117 ;
* V_107 += V_115 ;
* V_109 += V_119 ;
* V_110 += V_120 ;
return V_118 ;
}
unsigned long F_123 ( struct V_4 * V_4 ,
struct V_103 * V_104 )
{
struct V_1 V_2 = {
. V_46 = V_21 ,
. V_140 = V_141 ,
. V_125 = 1 ,
} ;
unsigned long V_42 , V_142 , V_143 , V_144 , V_145 , V_146 ;
struct V_52 * V_52 , * V_147 ;
F_99 ( V_148 ) ;
F_124 (page, next, page_list, lru) {
if ( F_75 ( V_52 ) && ! F_66 ( V_52 ) &&
! F_125 ( V_52 ) ) {
F_126 ( V_52 ) ;
F_127 ( & V_52 -> V_13 , & V_148 ) ;
}
}
V_42 = F_98 ( & V_148 , V_4 , & V_2 ,
V_149 | V_150 ,
& V_142 , & V_143 , & V_144 , & V_145 , & V_146 , true ) ;
F_122 ( & V_148 , V_104 ) ;
F_128 ( V_4 , V_151 , - V_42 ) ;
return V_42 ;
}
int F_129 ( struct V_52 * V_52 , T_5 V_152 )
{
int V_42 = - V_153 ;
if ( ! F_83 ( V_52 ) )
return V_42 ;
if ( F_81 ( V_52 ) && ! ( V_152 & V_154 ) )
return V_42 ;
V_42 = - V_155 ;
if ( V_152 & ( V_156 | V_157 ) ) {
if ( F_56 ( V_52 ) )
return V_42 ;
if ( F_66 ( V_52 ) ) {
struct V_57 * V_58 ;
if ( V_152 & V_156 )
return V_42 ;
V_58 = F_45 ( V_52 ) ;
if ( V_58 && ! V_58 -> V_62 -> V_158 )
return V_42 ;
}
}
if ( ( V_152 & V_159 ) && F_105 ( V_52 ) )
return V_42 ;
if ( F_130 ( F_131 ( V_52 ) ) ) {
F_132 ( V_52 ) ;
V_42 = 0 ;
}
return V_42 ;
}
static unsigned long F_133 ( unsigned long V_43 ,
struct V_11 * V_11 , struct V_103 * V_160 ,
unsigned long * V_28 , struct V_1 * V_2 ,
T_5 V_152 , enum V_12 V_13 )
{
struct V_103 * V_161 = & V_11 -> V_162 [ V_13 ] ;
unsigned long V_163 = 0 ;
unsigned long V_164 ;
for ( V_164 = 0 ; V_164 < V_43 && ! F_100 ( V_161 ) ; V_164 ++ ) {
struct V_52 * V_52 ;
int V_165 ;
V_52 = F_101 ( V_161 ) ;
F_134 ( V_52 , V_161 , V_19 ) ;
F_82 ( ! F_83 ( V_52 ) , V_52 ) ;
switch ( F_129 ( V_52 , V_152 ) ) {
case 0 :
V_165 = F_135 ( V_52 ) ;
F_136 ( V_11 , V_13 , - V_165 ) ;
F_127 ( & V_52 -> V_13 , V_160 ) ;
V_163 += V_165 ;
break;
case - V_155 :
F_127 ( & V_52 -> V_13 , V_161 ) ;
continue;
default:
F_137 () ;
}
}
* V_28 = V_164 ;
F_138 ( V_2 -> V_166 , V_43 , V_164 ,
V_163 , V_152 , F_139 ( V_13 ) ) ;
return V_163 ;
}
int F_89 ( struct V_52 * V_52 )
{
int V_42 = - V_155 ;
F_82 ( ! F_39 ( V_52 ) , V_52 ) ;
if ( F_83 ( V_52 ) ) {
struct V_4 * V_4 = F_104 ( V_52 ) ;
struct V_11 * V_11 ;
F_63 ( & V_4 -> V_167 ) ;
V_11 = F_140 ( V_52 , V_4 ) ;
if ( F_83 ( V_52 ) ) {
int V_13 = F_141 ( V_52 ) ;
F_142 ( V_52 ) ;
F_132 ( V_52 ) ;
F_143 ( V_52 , V_11 , V_13 ) ;
V_42 = 0 ;
}
F_72 ( & V_4 -> V_167 ) ;
}
return V_42 ;
}
static int F_144 ( struct V_4 * V_4 , int V_168 ,
struct V_1 * V_2 )
{
unsigned long V_169 , V_170 ;
if ( F_107 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_168 ) {
V_169 = F_3 ( V_4 , V_7 ) ;
V_170 = F_3 ( V_4 , V_151 ) ;
} else {
V_169 = F_3 ( V_4 , V_9 ) ;
V_170 = F_3 ( V_4 , V_171 ) ;
}
if ( ( V_2 -> V_46 & V_172 ) == V_172 )
V_169 >>= 3 ;
return V_170 > V_169 ;
}
static T_6 void
F_145 ( struct V_11 * V_11 , struct V_103 * V_104 )
{
struct V_173 * V_174 = & V_11 -> V_174 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_99 ( V_175 ) ;
while ( ! F_100 ( V_104 ) ) {
struct V_52 * V_52 = F_101 ( V_104 ) ;
int V_13 ;
F_82 ( F_83 ( V_52 ) , V_52 ) ;
F_16 ( & V_52 -> V_13 ) ;
if ( F_65 ( ! F_85 ( V_52 ) ) ) {
F_72 ( & V_4 -> V_167 ) ;
F_80 ( V_52 ) ;
F_63 ( & V_4 -> V_167 ) ;
continue;
}
V_11 = F_140 ( V_52 , V_4 ) ;
F_146 ( V_52 ) ;
V_13 = F_141 ( V_52 ) ;
F_147 ( V_52 , V_11 , V_13 ) ;
if ( F_148 ( V_13 ) ) {
int V_168 = F_139 ( V_13 ) ;
int V_176 = F_135 ( V_52 ) ;
V_174 -> V_177 [ V_168 ] += V_176 ;
}
if ( F_114 ( V_52 ) ) {
F_149 ( V_52 ) ;
F_150 ( V_52 ) ;
F_143 ( V_52 , V_11 , V_13 ) ;
if ( F_65 ( F_151 ( V_52 ) ) ) {
F_72 ( & V_4 -> V_167 ) ;
F_152 ( V_52 ) ;
( * F_153 ( V_52 ) ) ( V_52 ) ;
F_63 ( & V_4 -> V_167 ) ;
} else
F_116 ( & V_52 -> V_13 , & V_175 ) ;
}
}
F_122 ( & V_175 , V_104 ) ;
}
static int F_154 ( void )
{
return ! ( V_55 -> V_19 & V_178 ) ||
V_55 -> V_53 == NULL ||
F_42 ( V_55 -> V_53 ) ;
}
static T_6 unsigned long
F_155 ( unsigned long V_43 , struct V_11 * V_11 ,
struct V_1 * V_2 , enum V_12 V_13 )
{
F_99 ( V_104 ) ;
unsigned long V_28 ;
unsigned long V_118 = 0 ;
unsigned long V_163 ;
unsigned long V_116 = 0 ;
unsigned long V_117 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
T_5 V_179 = 0 ;
int V_168 = F_139 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
struct V_173 * V_174 = & V_11 -> V_174 ;
while ( F_65 ( F_144 ( V_4 , V_168 , V_2 ) ) ) {
F_156 ( V_180 , V_181 / 10 ) ;
if ( F_157 ( V_55 ) )
return V_49 ;
}
F_158 () ;
if ( ! V_2 -> V_125 )
V_179 |= V_159 ;
if ( ! V_2 -> V_137 )
V_179 |= V_156 ;
F_63 ( & V_4 -> V_167 ) ;
V_163 = F_133 ( V_43 , V_11 , & V_104 ,
& V_28 , V_2 , V_179 , V_13 ) ;
F_159 ( V_4 , V_14 + V_13 , - V_163 ) ;
F_159 ( V_4 , V_171 + V_168 , V_163 ) ;
if ( F_1 ( V_2 ) ) {
F_159 ( V_4 , V_10 , V_28 ) ;
if ( F_107 () )
F_160 ( V_182 , V_4 , V_28 ) ;
else
F_160 ( V_183 , V_4 , V_28 ) ;
}
F_72 ( & V_4 -> V_167 ) ;
if ( V_163 == 0 )
return 0 ;
V_118 = F_98 ( & V_104 , V_4 , V_2 , V_149 ,
& V_116 , & V_115 , & V_117 ,
& V_119 , & V_120 ,
false ) ;
F_63 ( & V_4 -> V_167 ) ;
V_174 -> V_184 [ V_168 ] += V_163 ;
if ( F_1 ( V_2 ) ) {
if ( F_107 () )
F_160 ( V_185 , V_4 ,
V_118 ) ;
else
F_160 ( V_186 , V_4 ,
V_118 ) ;
}
F_145 ( V_11 , & V_104 ) ;
F_159 ( V_4 , V_171 + V_168 , - V_163 ) ;
F_72 ( & V_4 -> V_167 ) ;
F_120 ( & V_104 ) ;
F_121 ( & V_104 , true ) ;
if ( V_119 && V_119 == V_163 )
F_161 ( V_129 , & V_4 -> V_19 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_116 && V_116 == V_117 )
F_161 ( V_187 , & V_4 -> V_19 ) ;
if ( V_115 == V_163 )
F_161 ( V_135 , & V_4 -> V_19 ) ;
if ( V_120 && F_154 () )
F_156 ( V_180 , V_181 / 10 ) ;
}
if ( ! V_2 -> V_188 && ! F_107 () &&
F_154 () )
F_162 ( V_4 , V_180 , V_181 / 10 ) ;
F_163 ( V_4 -> V_189 -> V_190 ,
F_164 ( V_4 ) ,
V_28 , V_118 ,
V_2 -> V_140 ,
F_165 ( V_168 ) ) ;
return V_118 ;
}
static void F_166 ( struct V_11 * V_11 ,
struct V_103 * V_24 ,
struct V_103 * V_175 ,
enum V_12 V_13 )
{
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_191 = 0 ;
struct V_52 * V_52 ;
int V_165 ;
while ( ! F_100 ( V_24 ) ) {
V_52 = F_101 ( V_24 ) ;
V_11 = F_140 ( V_52 , V_4 ) ;
F_82 ( F_83 ( V_52 ) , V_52 ) ;
F_146 ( V_52 ) ;
V_165 = F_135 ( V_52 ) ;
F_136 ( V_11 , V_13 , V_165 ) ;
F_127 ( & V_52 -> V_13 , & V_11 -> V_162 [ V_13 ] ) ;
V_191 += V_165 ;
if ( F_114 ( V_52 ) ) {
F_149 ( V_52 ) ;
F_150 ( V_52 ) ;
F_143 ( V_52 , V_11 , V_13 ) ;
if ( F_65 ( F_151 ( V_52 ) ) ) {
F_72 ( & V_4 -> V_167 ) ;
F_152 ( V_52 ) ;
( * F_153 ( V_52 ) ) ( V_52 ) ;
F_63 ( & V_4 -> V_167 ) ;
} else
F_116 ( & V_52 -> V_13 , V_175 ) ;
}
}
F_159 ( V_4 , V_14 + V_13 , V_191 ) ;
if ( ! F_148 ( V_13 ) )
F_167 ( V_192 , V_191 ) ;
}
static void F_168 ( unsigned long V_43 ,
struct V_11 * V_11 ,
struct V_1 * V_2 ,
enum V_12 V_13 )
{
unsigned long V_163 ;
unsigned long V_28 ;
unsigned long V_93 ;
F_99 ( V_193 ) ;
F_99 ( V_194 ) ;
F_99 ( V_195 ) ;
struct V_52 * V_52 ;
struct V_173 * V_174 = & V_11 -> V_174 ;
unsigned long V_196 = 0 ;
T_5 V_179 = 0 ;
int V_168 = F_139 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_158 () ;
if ( ! V_2 -> V_125 )
V_179 |= V_159 ;
if ( ! V_2 -> V_137 )
V_179 |= V_156 ;
F_63 ( & V_4 -> V_167 ) ;
V_163 = F_133 ( V_43 , V_11 , & V_193 ,
& V_28 , V_2 , V_179 , V_13 ) ;
if ( F_1 ( V_2 ) )
F_159 ( V_4 , V_10 , V_28 ) ;
V_174 -> V_184 [ V_168 ] += V_163 ;
F_160 ( V_197 , V_4 , V_28 ) ;
F_159 ( V_4 , V_14 + V_13 , - V_163 ) ;
F_159 ( V_4 , V_171 + V_168 , V_163 ) ;
F_72 ( & V_4 -> V_167 ) ;
while ( ! F_100 ( & V_193 ) ) {
F_25 () ;
V_52 = F_101 ( & V_193 ) ;
F_16 ( & V_52 -> V_13 ) ;
if ( F_65 ( ! F_85 ( V_52 ) ) ) {
F_80 ( V_52 ) ;
continue;
}
if ( F_65 ( V_198 ) ) {
if ( F_40 ( V_52 ) && F_102 ( V_52 ) ) {
if ( F_40 ( V_52 ) )
F_113 ( V_52 , 0 ) ;
F_47 ( V_52 ) ;
}
}
if ( F_93 ( V_52 , 0 , V_2 -> V_3 ,
& V_93 ) ) {
V_196 += F_135 ( V_52 ) ;
if ( ( V_93 & V_97 ) && F_75 ( V_52 ) ) {
F_116 ( & V_52 -> V_13 , & V_194 ) ;
continue;
}
}
F_126 ( V_52 ) ;
F_116 ( & V_52 -> V_13 , & V_195 ) ;
}
F_63 ( & V_4 -> V_167 ) ;
V_174 -> V_177 [ V_168 ] += V_196 ;
F_166 ( V_11 , & V_194 , & V_193 , V_13 ) ;
F_166 ( V_11 , & V_195 , & V_193 , V_13 - V_199 ) ;
F_159 ( V_4 , V_171 + V_168 , - V_163 ) ;
F_72 ( & V_4 -> V_167 ) ;
F_120 ( & V_193 ) ;
F_121 ( & V_193 , true ) ;
}
static int F_169 ( struct V_4 * V_4 )
{
unsigned long V_200 , V_169 ;
V_200 = F_3 ( V_4 , V_8 ) ;
V_169 = F_3 ( V_4 , V_9 ) ;
if ( V_169 * V_4 -> V_201 < V_200 )
return 1 ;
return 0 ;
}
static int F_170 ( struct V_11 * V_11 )
{
if ( ! V_202 )
return 0 ;
if ( ! F_7 () )
return F_171 ( V_11 ) ;
return F_169 ( F_9 ( V_11 ) ) ;
}
static inline int F_170 ( struct V_11 * V_11 )
{
return 0 ;
}
static int F_172 ( struct V_11 * V_11 )
{
unsigned long V_169 ;
unsigned long V_200 ;
V_169 = F_6 ( V_11 , V_203 ) ;
V_200 = F_6 ( V_11 , V_204 ) ;
return V_200 > V_169 ;
}
static int F_173 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( F_139 ( V_13 ) )
return F_172 ( V_11 ) ;
else
return F_170 ( V_11 ) ;
}
static unsigned long F_174 ( enum V_12 V_13 , unsigned long V_43 ,
struct V_11 * V_11 , struct V_1 * V_2 )
{
if ( F_148 ( V_13 ) ) {
if ( F_173 ( V_11 , V_13 ) )
F_168 ( V_43 , V_11 , V_2 , V_13 ) ;
return 0 ;
}
return F_155 ( V_43 , V_11 , V_2 , V_13 ) ;
}
static void F_175 ( struct V_11 * V_11 , int V_205 ,
struct V_1 * V_2 , unsigned long * V_5 ,
unsigned long * V_206 )
{
struct V_173 * V_174 = & V_11 -> V_174 ;
T_7 V_207 [ 2 ] ;
T_7 V_208 = 0 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_209 , V_210 ;
enum V_211 V_211 ;
unsigned long V_212 , V_168 ;
bool V_213 = false ;
unsigned long V_214 , V_215 ;
enum V_12 V_13 ;
bool V_216 ;
int V_217 ;
if ( F_107 () ) {
if ( ! F_5 ( V_4 ) )
V_213 = true ;
if ( ! F_176 ( V_11 ) )
V_213 = true ;
}
if ( ! F_1 ( V_2 ) )
V_213 = true ;
if ( ! V_2 -> V_218 || ( F_4 () <= 0 ) ) {
V_211 = V_219 ;
goto V_50;
}
if ( ! F_1 ( V_2 ) && ! V_205 ) {
V_211 = V_219 ;
goto V_50;
}
if ( ! V_2 -> V_140 && V_205 ) {
V_211 = V_220 ;
goto V_50;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_221 ;
unsigned long V_222 ;
V_222 = F_3 ( V_4 , V_223 ) ;
V_221 = F_3 ( V_4 , V_6 ) +
F_3 ( V_4 , V_7 ) ;
if ( F_65 ( V_221 + V_222 <= F_177 ( V_4 ) ) ) {
V_211 = V_224 ;
goto V_50;
}
}
if ( ! F_172 ( V_11 ) ) {
V_211 = V_219 ;
goto V_50;
}
V_211 = V_225 ;
V_209 = V_205 ;
V_210 = 200 - V_209 ;
V_212 = F_6 ( V_11 , V_226 ) +
F_6 ( V_11 , V_227 ) ;
V_168 = F_6 ( V_11 , V_204 ) +
F_6 ( V_11 , V_203 ) ;
F_63 ( & V_4 -> V_167 ) ;
if ( F_65 ( V_174 -> V_184 [ 0 ] > V_212 / 4 ) ) {
V_174 -> V_184 [ 0 ] /= 2 ;
V_174 -> V_177 [ 0 ] /= 2 ;
}
if ( F_65 ( V_174 -> V_184 [ 1 ] > V_168 / 4 ) ) {
V_174 -> V_184 [ 1 ] /= 2 ;
V_174 -> V_177 [ 1 ] /= 2 ;
}
V_214 = V_209 * ( V_174 -> V_184 [ 0 ] + 1 ) ;
V_214 /= V_174 -> V_177 [ 0 ] + 1 ;
V_215 = V_210 * ( V_174 -> V_184 [ 1 ] + 1 ) ;
V_215 /= V_174 -> V_177 [ 1 ] + 1 ;
F_72 ( & V_4 -> V_167 ) ;
V_207 [ 0 ] = V_214 ;
V_207 [ 1 ] = V_215 ;
V_208 = V_214 + V_215 + 1 ;
V_50:
V_216 = false ;
for ( V_217 = 0 ; ! V_216 && V_217 < 2 ; V_217 ++ ) {
* V_206 = 0 ;
F_178 (lru) {
int V_168 = F_139 ( V_13 ) ;
unsigned long V_16 ;
unsigned long V_164 ;
V_16 = F_6 ( V_11 , V_13 ) ;
V_164 = V_16 >> V_2 -> V_140 ;
if ( ! V_164 && V_217 && V_213 )
V_164 = F_22 ( V_16 , V_49 ) ;
switch ( V_211 ) {
case V_220 :
break;
case V_225 :
V_164 = F_179 ( V_164 * V_207 [ V_168 ] ,
V_208 ) ;
break;
case V_219 :
case V_224 :
if ( ( V_211 == V_219 ) != V_168 ) {
V_16 = 0 ;
V_164 = 0 ;
}
break;
default:
F_137 () ;
}
* V_206 += V_16 ;
V_5 [ V_13 ] = V_164 ;
V_216 |= ! ! V_164 ;
}
}
}
static void F_180 ( struct V_11 * V_11 , int V_205 ,
struct V_1 * V_2 , unsigned long * V_206 )
{
unsigned long V_5 [ V_228 ] ;
unsigned long V_229 [ V_228 ] ;
unsigned long V_43 ;
enum V_12 V_13 ;
unsigned long V_118 = 0 ;
unsigned long V_230 = V_2 -> V_230 ;
struct V_231 V_232 ;
bool V_233 ;
F_175 ( V_11 , V_205 , V_2 , V_5 , V_206 ) ;
memcpy ( V_229 , V_5 , sizeof( V_5 ) ) ;
V_233 = ( F_1 ( V_2 ) && ! F_107 () &&
V_2 -> V_140 == V_141 ) ;
F_181 ( & V_232 ) ;
while ( V_5 [ V_227 ] || V_5 [ V_204 ] ||
V_5 [ V_203 ] ) {
unsigned long V_234 , V_235 , V_236 ;
unsigned long V_28 ;
F_178 (lru) {
if ( V_5 [ V_13 ] ) {
V_43 = F_22 ( V_5 [ V_13 ] , V_49 ) ;
V_5 [ V_13 ] -= V_43 ;
V_118 += F_174 ( V_13 , V_43 ,
V_11 , V_2 ) ;
}
}
if ( V_118 < V_230 || V_233 )
continue;
V_235 = V_5 [ V_203 ] + V_5 [ V_204 ] ;
V_234 = V_5 [ V_227 ] + V_5 [ V_226 ] ;
if ( ! V_235 || ! V_234 )
break;
if ( V_235 > V_234 ) {
unsigned long V_237 = V_229 [ V_227 ] +
V_229 [ V_226 ] + 1 ;
V_13 = V_238 ;
V_236 = V_234 * 100 / V_237 ;
} else {
unsigned long V_237 = V_229 [ V_203 ] +
V_229 [ V_204 ] + 1 ;
V_13 = V_239 ;
V_236 = V_235 * 100 / V_237 ;
}
V_5 [ V_13 ] = 0 ;
V_5 [ V_13 + V_199 ] = 0 ;
V_13 = ( V_13 == V_239 ) ? V_238 : V_239 ;
V_28 = V_229 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_229 [ V_13 ] * ( 100 - V_236 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_28 ) ;
V_13 += V_199 ;
V_28 = V_229 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_229 [ V_13 ] * ( 100 - V_236 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_28 ) ;
V_233 = true ;
}
F_182 ( & V_232 ) ;
V_2 -> V_118 += V_118 ;
if ( F_170 ( V_11 ) )
F_168 ( V_49 , V_11 ,
V_2 , V_226 ) ;
F_183 ( V_2 -> V_46 ) ;
}
static bool F_184 ( struct V_1 * V_2 )
{
if ( F_185 ( V_240 ) && V_2 -> V_166 &&
( V_2 -> V_166 > V_241 ||
V_2 -> V_140 < V_141 - 2 ) )
return true ;
return false ;
}
static inline bool F_186 ( struct V_4 * V_4 ,
unsigned long V_118 ,
unsigned long V_28 ,
struct V_1 * V_2 )
{
unsigned long V_242 ;
unsigned long V_243 ;
if ( ! F_184 ( V_2 ) )
return false ;
if ( V_2 -> V_46 & V_244 ) {
if ( ! V_118 && ! V_28 )
return false ;
} else {
if ( ! V_118 )
return false ;
}
V_242 = ( 2UL << V_2 -> V_166 ) ;
V_243 = F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_243 += F_3 ( V_4 , V_9 ) ;
if ( V_2 -> V_118 < V_242 &&
V_243 > V_242 )
return true ;
switch ( F_187 ( V_4 , V_2 -> V_166 , 0 , 0 ) ) {
case V_245 :
case V_246 :
return false ;
default:
return true ;
}
}
static bool F_188 ( struct V_4 * V_4 , struct V_1 * V_2 ,
bool V_247 )
{
struct V_248 * V_248 = V_55 -> V_248 ;
unsigned long V_118 , V_28 ;
bool V_249 = false ;
do {
struct V_47 * V_250 = V_2 -> V_3 ;
struct V_251 V_252 = {
. V_4 = V_4 ,
. V_140 = V_2 -> V_140 ,
} ;
unsigned long V_253 = 0 ;
struct V_47 * V_48 ;
V_118 = V_2 -> V_118 ;
V_28 = V_2 -> V_28 ;
V_48 = F_35 ( V_250 , NULL , & V_252 ) ;
do {
unsigned long V_206 ;
unsigned long V_254 ;
struct V_11 * V_11 ;
int V_205 ;
if ( F_189 ( V_250 , V_48 ) ) {
if ( ! V_2 -> V_255 )
continue;
F_190 ( V_48 , V_256 , 1 ) ;
}
V_11 = F_191 ( V_4 , V_48 ) ;
V_205 = F_192 ( V_48 ) ;
V_254 = V_2 -> V_28 ;
F_180 ( V_11 , V_205 , V_2 , & V_206 ) ;
V_253 += V_206 ;
if ( V_48 && V_247 )
F_29 ( V_2 -> V_46 , F_193 ( V_4 ) ,
V_48 , V_2 -> V_28 - V_254 ,
V_206 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_118 >= V_2 -> V_230 ) {
F_194 ( V_250 , V_48 ) ;
break;
}
} while ( ( V_48 = F_35 ( V_250 , V_48 , & V_252 ) ) );
if ( F_1 ( V_2 ) && V_247 )
F_29 ( V_2 -> V_46 , F_193 ( V_4 ) , NULL ,
V_2 -> V_28 - V_28 ,
V_253 ) ;
if ( V_248 ) {
V_2 -> V_118 += V_248 -> V_257 ;
V_248 -> V_257 = 0 ;
}
F_195 ( V_2 -> V_46 , V_2 -> V_3 ,
V_2 -> V_28 - V_28 ,
V_2 -> V_118 - V_118 ) ;
if ( V_2 -> V_118 - V_118 )
V_249 = true ;
} while ( F_186 ( V_4 , V_2 -> V_118 - V_118 ,
V_2 -> V_28 - V_28 , V_2 ) );
return V_249 ;
}
static inline bool F_196 ( struct V_4 * V_4 , int V_166 )
{
unsigned long V_258 , V_259 ;
bool V_260 ;
V_258 = F_22 ( F_197 ( V_4 ) , F_198 (
V_4 -> V_261 , V_262 ) ) ;
V_259 = F_177 ( V_4 ) + V_258 + ( 2UL << V_166 ) ;
V_260 = F_199 ( V_4 , 0 , V_259 , 0 , 0 ) ;
if ( F_200 ( V_4 , V_166 ) )
return V_260 ;
if ( F_187 ( V_4 , V_166 , 0 , 0 ) == V_263 )
return false ;
return V_260 ;
}
static bool F_201 ( struct V_264 * V_264 , struct V_1 * V_2 )
{
struct V_265 * V_266 ;
struct V_4 * V_4 ;
unsigned long V_267 ;
unsigned long V_268 ;
T_2 V_269 ;
enum V_270 V_271 = F_202 ( V_2 -> V_46 ) ;
bool V_249 = false ;
V_269 = V_2 -> V_46 ;
if ( V_198 )
V_2 -> V_46 |= V_272 ;
F_203 (zone, z, zonelist,
requested_highidx, sc->nodemask) {
enum V_270 V_273 ;
if ( ! F_204 ( V_4 ) )
continue;
V_273 = V_271 ;
while ( ! F_204 ( V_4 -> V_189 -> V_274 +
V_273 ) )
V_273 -- ;
if ( F_1 ( V_2 ) ) {
if ( ! F_205 ( V_4 ,
V_21 | V_275 ) )
continue;
if ( V_2 -> V_140 != V_141 &&
! F_5 ( V_4 ) )
continue;
if ( F_185 ( V_240 ) &&
V_2 -> V_166 > V_241 &&
F_206 ( V_266 ) <= V_271 &&
F_196 ( V_4 , V_2 -> V_166 ) ) {
V_2 -> F_196 = true ;
continue;
}
V_268 = 0 ;
V_267 = F_207 ( V_4 ,
V_2 -> V_166 , V_2 -> V_46 ,
& V_268 ) ;
V_2 -> V_118 += V_267 ;
V_2 -> V_28 += V_268 ;
if ( V_267 )
V_249 = true ;
}
if ( F_188 ( V_4 , V_2 , F_164 ( V_4 ) == V_273 ) )
V_249 = true ;
if ( F_1 ( V_2 ) &&
! V_249 && F_5 ( V_4 ) )
V_249 = true ;
}
V_2 -> V_46 = V_269 ;
return V_249 ;
}
static unsigned long F_208 ( struct V_264 * V_264 ,
struct V_1 * V_2 )
{
int V_276 = V_2 -> V_140 ;
unsigned long V_277 = 0 ;
unsigned long V_278 ;
bool V_279 ;
V_280:
F_209 () ;
if ( F_1 ( V_2 ) )
F_91 ( V_281 ) ;
do {
F_210 ( V_2 -> V_46 , V_2 -> V_3 ,
V_2 -> V_140 ) ;
V_2 -> V_28 = 0 ;
V_279 = F_201 ( V_264 , V_2 ) ;
V_277 += V_2 -> V_28 ;
if ( V_2 -> V_118 >= V_2 -> V_230 )
break;
if ( V_2 -> F_196 )
break;
if ( V_2 -> V_140 < V_141 - 2 )
V_2 -> V_137 = 1 ;
V_278 = V_2 -> V_230 + V_2 -> V_230 / 2 ;
if ( V_277 > V_278 ) {
F_211 ( V_282 ? 0 : V_277 ,
V_283 ) ;
V_2 -> V_137 = 1 ;
}
} while ( -- V_2 -> V_140 >= 0 );
F_212 () ;
if ( V_2 -> V_118 )
return V_2 -> V_118 ;
if ( V_2 -> F_196 )
return 1 ;
if ( ! V_2 -> V_255 ) {
V_2 -> V_140 = V_276 ;
V_2 -> V_255 = 1 ;
goto V_280;
}
if ( V_279 )
return 1 ;
return 0 ;
}
static bool F_213 ( T_8 * V_284 )
{
struct V_4 * V_4 ;
unsigned long V_285 = 0 ;
unsigned long V_113 = 0 ;
int V_286 ;
bool V_287 ;
for ( V_286 = 0 ; V_286 <= V_288 ; V_286 ++ ) {
V_4 = & V_284 -> V_274 [ V_286 ] ;
if ( ! F_204 ( V_4 ) )
continue;
V_285 += F_214 ( V_4 ) ;
V_113 += F_3 ( V_4 , V_223 ) ;
}
if ( ! V_285 )
return true ;
V_287 = V_113 > V_285 / 2 ;
if ( ! V_287 && F_215 ( & V_284 -> V_289 ) ) {
V_284 -> V_273 = F_22 ( V_284 -> V_273 ,
(enum V_270 ) V_288 ) ;
F_216 ( & V_284 -> V_289 ) ;
}
return V_287 ;
}
static bool F_217 ( T_2 V_46 , struct V_264 * V_264 ,
T_9 * V_290 )
{
struct V_265 * V_266 ;
struct V_4 * V_4 ;
T_8 * V_284 = NULL ;
if ( V_55 -> V_19 & V_291 )
goto V_50;
if ( F_157 ( V_55 ) )
goto V_50;
F_203 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_164 ( V_4 ) > V_288 )
continue;
V_284 = V_4 -> V_189 ;
if ( F_213 ( V_284 ) )
goto V_50;
break;
}
if ( ! V_284 )
goto V_50;
F_91 ( V_292 ) ;
if ( ! ( V_46 & V_127 ) ) {
F_218 ( V_284 -> V_293 ,
F_213 ( V_284 ) , V_181 ) ;
goto V_294;
}
F_219 ( V_4 -> V_189 -> V_293 ,
F_213 ( V_284 ) ) ;
V_294:
if ( F_157 ( V_55 ) )
return true ;
V_50:
return false ;
}
unsigned long F_220 ( struct V_264 * V_264 , int V_166 ,
T_2 V_46 , T_9 * V_290 )
{
unsigned long V_118 ;
struct V_1 V_2 = {
. V_230 = V_49 ,
. V_46 = ( V_46 = F_221 ( V_46 ) ) ,
. V_166 = V_166 ,
. V_290 = V_290 ,
. V_140 = V_141 ,
. V_137 = ! V_282 ,
. V_125 = 1 ,
. V_218 = 1 ,
} ;
if ( F_217 ( V_46 , V_264 , V_290 ) )
return 1 ;
F_222 ( V_166 ,
V_2 . V_137 ,
V_46 ) ;
V_118 = F_208 ( V_264 , & V_2 ) ;
F_223 ( V_118 ) ;
return V_118 ;
}
unsigned long F_224 ( struct V_47 * V_48 ,
T_2 V_46 , bool V_295 ,
struct V_4 * V_4 ,
unsigned long * V_28 )
{
struct V_1 V_2 = {
. V_230 = V_49 ,
. V_3 = V_48 ,
. V_137 = ! V_282 ,
. V_125 = 1 ,
. V_218 = ! V_295 ,
} ;
struct V_11 * V_11 = F_191 ( V_4 , V_48 ) ;
int V_205 = F_192 ( V_48 ) ;
unsigned long V_206 ;
V_2 . V_46 = ( V_46 & V_296 ) |
( V_297 & ~ V_296 ) ;
F_225 ( V_2 . V_166 ,
V_2 . V_137 ,
V_2 . V_46 ) ;
F_180 ( V_11 , V_205 , & V_2 , & V_206 ) ;
F_226 ( V_2 . V_118 ) ;
* V_28 = V_2 . V_28 ;
return V_2 . V_118 ;
}
unsigned long F_227 ( struct V_47 * V_48 ,
unsigned long V_165 ,
T_2 V_46 ,
bool V_218 )
{
struct V_264 * V_264 ;
unsigned long V_118 ;
int V_35 ;
struct V_1 V_2 = {
. V_230 = F_228 ( V_165 , V_49 ) ,
. V_46 = ( V_46 & V_296 ) |
( V_297 & ~ V_296 ) ,
. V_3 = V_48 ,
. V_140 = V_141 ,
. V_137 = ! V_282 ,
. V_125 = 1 ,
. V_218 = V_218 ,
} ;
V_35 = F_229 ( V_48 ) ;
V_264 = F_230 ( V_35 ) -> V_298 ;
F_231 ( 0 ,
V_2 . V_137 ,
V_2 . V_46 ) ;
V_118 = F_208 ( V_264 , & V_2 ) ;
F_232 ( V_118 ) ;
return V_118 ;
}
static void F_233 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_47 * V_48 ;
if ( ! V_202 )
return;
V_48 = F_35 ( NULL , NULL , NULL ) ;
do {
struct V_11 * V_11 = F_191 ( V_4 , V_48 ) ;
if ( F_170 ( V_11 ) )
F_168 ( V_49 , V_11 ,
V_2 , V_226 ) ;
V_48 = F_35 ( NULL , V_48 , NULL ) ;
} while ( V_48 );
}
static bool F_234 ( struct V_4 * V_4 , int V_166 ,
unsigned long V_258 , int V_273 )
{
if ( ! F_199 ( V_4 , V_166 , F_177 ( V_4 ) +
V_258 , V_273 , 0 ) )
return false ;
if ( F_185 ( V_240 ) && V_166 && F_187 ( V_4 ,
V_166 , 0 , V_273 ) == V_263 )
return false ;
return true ;
}
static bool F_235 ( T_8 * V_284 , int V_166 , int V_273 )
{
unsigned long V_261 = 0 ;
unsigned long V_299 = 0 ;
int V_286 ;
for ( V_286 = 0 ; V_286 <= V_273 ; V_286 ++ ) {
struct V_4 * V_4 = V_284 -> V_274 + V_286 ;
if ( ! F_204 ( V_4 ) )
continue;
V_261 += V_4 -> V_261 ;
if ( ! F_5 ( V_4 ) ) {
V_299 += V_4 -> V_261 ;
continue;
}
if ( F_234 ( V_4 , V_166 , 0 , V_286 ) )
V_299 += V_4 -> V_261 ;
else if ( ! V_166 )
return false ;
}
if ( V_166 )
return V_299 >= ( V_261 >> 2 ) ;
else
return true ;
}
static bool F_236 ( T_8 * V_284 , int V_166 , long V_300 ,
int V_273 )
{
if ( V_300 )
return false ;
if ( F_215 ( & V_284 -> V_293 ) )
F_237 ( & V_284 -> V_293 ) ;
return F_235 ( V_284 , V_166 , V_273 ) ;
}
static bool F_238 ( struct V_4 * V_4 ,
int V_273 ,
struct V_1 * V_2 ,
unsigned long * V_301 )
{
int V_302 = V_2 -> V_166 ;
unsigned long V_258 ;
bool V_303 ;
V_2 -> V_230 = F_228 ( V_49 , F_177 ( V_4 ) ) ;
if ( F_185 ( V_240 ) && V_2 -> V_166 &&
F_187 ( V_4 , V_2 -> V_166 , 0 , V_273 )
!= V_263 )
V_302 = 0 ;
V_258 = F_22 ( F_197 ( V_4 ) , F_198 (
V_4 -> V_261 , V_262 ) ) ;
V_303 = ( V_198 && F_239 ( V_4 ) ) ;
if ( ! V_303 && F_234 ( V_4 , V_302 ,
V_258 , V_273 ) )
return true ;
F_188 ( V_4 , V_2 , F_164 ( V_4 ) == V_273 ) ;
* V_301 += V_2 -> V_230 ;
F_240 ( V_129 , & V_4 -> V_19 ) ;
if ( F_5 ( V_4 ) &&
F_234 ( V_4 , V_302 , 0 , V_273 ) ) {
F_240 ( V_187 , & V_4 -> V_19 ) ;
F_240 ( V_135 , & V_4 -> V_19 ) ;
}
return V_2 -> V_28 >= V_2 -> V_230 ;
}
static unsigned long F_241 ( T_8 * V_284 , int V_166 ,
int * V_273 )
{
int V_286 ;
int V_304 = 0 ;
unsigned long V_267 ;
unsigned long V_268 ;
struct V_1 V_2 = {
. V_46 = V_21 ,
. V_166 = V_166 ,
. V_140 = V_141 ,
. V_137 = ! V_282 ,
. V_125 = 1 ,
. V_218 = 1 ,
} ;
F_91 ( V_305 ) ;
do {
unsigned long V_301 = 0 ;
bool V_306 = true ;
bool V_307 = ( V_166 > 0 ) ;
V_2 . V_118 = 0 ;
for ( V_286 = V_284 -> V_308 - 1 ; V_286 >= 0 ; V_286 -- ) {
struct V_4 * V_4 = V_284 -> V_274 + V_286 ;
if ( ! F_204 ( V_4 ) )
continue;
if ( V_2 . V_140 != V_141 &&
! F_5 ( V_4 ) )
continue;
F_233 ( V_4 , & V_2 ) ;
if ( V_198 && F_242 ( V_286 ) ) {
V_304 = V_286 ;
break;
}
if ( ! F_234 ( V_4 , V_166 , 0 , 0 ) ) {
V_304 = V_286 ;
break;
} else {
F_240 ( V_187 , & V_4 -> V_19 ) ;
F_240 ( V_135 , & V_4 -> V_19 ) ;
}
}
if ( V_286 < 0 )
goto V_50;
for ( V_286 = 0 ; V_286 <= V_304 ; V_286 ++ ) {
struct V_4 * V_4 = V_284 -> V_274 + V_286 ;
if ( ! F_204 ( V_4 ) )
continue;
if ( V_307 &&
F_243 ( V_4 , V_166 ,
F_197 ( V_4 ) ,
* V_273 , 0 ) )
V_307 = false ;
}
if ( V_2 . V_140 < V_141 - 2 )
V_2 . V_137 = 1 ;
for ( V_286 = 0 ; V_286 <= V_304 ; V_286 ++ ) {
struct V_4 * V_4 = V_284 -> V_274 + V_286 ;
if ( ! F_204 ( V_4 ) )
continue;
if ( V_2 . V_140 != V_141 &&
! F_5 ( V_4 ) )
continue;
V_2 . V_28 = 0 ;
V_268 = 0 ;
V_267 = F_207 ( V_4 ,
V_166 , V_2 . V_46 ,
& V_268 ) ;
V_2 . V_118 += V_267 ;
if ( F_238 ( V_4 , V_304 ,
& V_2 , & V_301 ) )
V_306 = false ;
}
if ( F_215 ( & V_284 -> V_293 ) &&
F_213 ( V_284 ) )
F_237 ( & V_284 -> V_293 ) ;
if ( V_166 && V_2 . V_118 >= 2UL << V_166 )
V_166 = V_2 . V_166 = 0 ;
if ( F_244 () || F_245 () )
break;
if ( V_307 && V_2 . V_118 > V_301 )
F_246 ( V_284 , V_166 ) ;
if ( V_306 || ! V_2 . V_118 )
V_2 . V_140 -- ;
} while ( V_2 . V_140 >= 1 &&
! F_235 ( V_284 , V_166 , * V_273 ) );
V_50:
* V_273 = V_304 ;
return V_166 ;
}
static void F_247 ( T_8 * V_284 , int V_166 , int V_273 )
{
long V_300 = 0 ;
F_248 ( V_309 ) ;
if ( F_249 ( V_55 ) || F_245 () )
return;
F_250 ( & V_284 -> V_289 , & V_309 , V_310 ) ;
if ( F_236 ( V_284 , V_166 , V_300 , V_273 ) ) {
V_300 = F_251 ( V_181 / 10 ) ;
F_252 ( & V_284 -> V_289 , & V_309 ) ;
F_250 ( & V_284 -> V_289 , & V_309 , V_310 ) ;
}
if ( F_236 ( V_284 , V_166 , V_300 , V_273 ) ) {
F_253 ( V_284 -> V_190 ) ;
F_254 ( V_284 , V_311 ) ;
F_255 ( V_284 ) ;
if ( ! F_245 () )
F_256 () ;
F_254 ( V_284 , V_312 ) ;
} else {
if ( V_300 )
F_91 ( V_313 ) ;
else
F_91 ( V_314 ) ;
}
F_252 ( & V_284 -> V_289 , & V_309 ) ;
}
static int F_257 ( void * V_315 )
{
unsigned long V_166 , V_316 ;
unsigned V_317 ;
int V_273 , V_318 ;
int V_319 ;
T_8 * V_284 = ( T_8 * ) V_315 ;
struct V_320 * V_321 = V_55 ;
struct V_248 V_248 = {
. V_257 = 0 ,
} ;
const struct V_322 * V_322 = F_258 ( V_284 -> V_190 ) ;
F_259 ( V_21 ) ;
if ( ! F_260 ( V_322 ) )
F_261 ( V_321 , V_322 ) ;
V_55 -> V_248 = & V_248 ;
V_321 -> V_19 |= V_323 | V_56 | V_324 ;
F_262 () ;
V_166 = V_316 = 0 ;
V_317 = 0 ;
V_273 = V_318 = V_284 -> V_308 - 1 ;
V_319 = V_273 ;
for ( ; ; ) {
bool V_42 ;
if ( V_319 >= V_318 &&
V_317 == V_316 ) {
V_316 = V_284 -> V_325 ;
V_318 = V_284 -> V_273 ;
V_284 -> V_325 = 0 ;
V_284 -> V_273 = V_284 -> V_308 - 1 ;
}
if ( V_166 < V_316 || V_273 > V_318 ) {
V_166 = V_316 ;
V_273 = V_318 ;
} else {
F_247 ( V_284 , V_317 ,
V_319 ) ;
V_166 = V_284 -> V_325 ;
V_273 = V_284 -> V_273 ;
V_316 = V_166 ;
V_318 = V_273 ;
V_284 -> V_325 = 0 ;
V_284 -> V_273 = V_284 -> V_308 - 1 ;
}
V_42 = F_244 () ;
if ( F_245 () )
break;
if ( ! V_42 ) {
F_263 ( V_284 -> V_190 , V_166 ) ;
V_319 = V_273 ;
V_317 = F_241 ( V_284 , V_166 ,
& V_319 ) ;
}
}
V_321 -> V_19 &= ~ ( V_323 | V_56 | V_324 ) ;
V_55 -> V_248 = NULL ;
F_264 () ;
return 0 ;
}
void F_265 ( struct V_4 * V_4 , int V_166 , enum V_270 V_273 )
{
T_8 * V_284 ;
if ( ! F_204 ( V_4 ) )
return;
if ( ! F_205 ( V_4 , V_21 | V_275 ) )
return;
V_284 = V_4 -> V_189 ;
if ( V_284 -> V_325 < V_166 ) {
V_284 -> V_325 = V_166 ;
V_284 -> V_273 = F_22 ( V_284 -> V_273 , V_273 ) ;
}
if ( ! F_215 ( & V_284 -> V_289 ) )
return;
if ( F_234 ( V_4 , V_166 , 0 , 0 ) )
return;
F_266 ( V_284 -> V_190 , F_164 ( V_4 ) , V_166 ) ;
F_216 ( & V_284 -> V_289 ) ;
}
unsigned long F_267 ( unsigned long V_230 )
{
struct V_248 V_248 ;
struct V_1 V_2 = {
. V_230 = V_230 ,
. V_46 = V_297 ,
. V_140 = V_141 ,
. V_137 = 1 ,
. V_125 = 1 ,
. V_218 = 1 ,
. V_188 = 1 ,
} ;
struct V_264 * V_264 = F_268 ( F_269 () , V_2 . V_46 ) ;
struct V_320 * V_315 = V_55 ;
unsigned long V_118 ;
V_315 -> V_19 |= V_323 ;
F_259 ( V_2 . V_46 ) ;
V_248 . V_257 = 0 ;
V_315 -> V_248 = & V_248 ;
V_118 = F_208 ( V_264 , & V_2 ) ;
V_315 -> V_248 = NULL ;
F_264 () ;
V_315 -> V_19 &= ~ V_323 ;
return V_118 ;
}
static int F_270 ( struct V_326 * V_327 , unsigned long V_328 ,
void * V_329 )
{
int V_35 ;
if ( V_328 == V_330 || V_328 == V_331 ) {
F_271 (nid, N_MEMORY) {
T_8 * V_284 = F_230 ( V_35 ) ;
const struct V_322 * V_332 ;
V_332 = F_258 ( V_284 -> V_190 ) ;
if ( F_272 ( V_333 , V_332 ) < V_334 )
F_261 ( V_284 -> F_257 , V_332 ) ;
}
}
return V_335 ;
}
int F_273 ( int V_35 )
{
T_8 * V_284 = F_230 ( V_35 ) ;
int V_42 = 0 ;
if ( V_284 -> F_257 )
return 0 ;
V_284 -> F_257 = F_274 ( F_257 , V_284 , L_3 , V_35 ) ;
if ( F_275 ( V_284 -> F_257 ) ) {
F_61 ( V_336 == V_337 ) ;
F_21 ( L_4 , V_35 ) ;
V_42 = F_276 ( V_284 -> F_257 ) ;
V_284 -> F_257 = NULL ;
}
return V_42 ;
}
void F_277 ( int V_35 )
{
struct V_320 * F_257 = F_230 ( V_35 ) -> F_257 ;
if ( F_257 ) {
F_278 ( F_257 ) ;
F_230 ( V_35 ) -> F_257 = NULL ;
}
}
static int T_10 F_279 ( void )
{
int V_35 ;
F_280 () ;
F_271 (nid, N_MEMORY)
F_273 ( V_35 ) ;
F_281 ( F_270 , 0 ) ;
return 0 ;
}
static inline unsigned long F_282 ( struct V_4 * V_4 )
{
unsigned long V_338 = F_3 ( V_4 , V_339 ) ;
unsigned long V_340 = F_3 ( V_4 , V_7 ) +
F_3 ( V_4 , V_6 ) ;
return ( V_340 > V_338 ) ? ( V_340 - V_338 ) : 0 ;
}
static long F_283 ( struct V_4 * V_4 )
{
long V_341 ;
long V_31 = 0 ;
if ( V_342 & V_343 )
V_341 = F_3 ( V_4 , V_344 ) ;
else
V_341 = F_282 ( V_4 ) ;
if ( ! ( V_342 & V_345 ) )
V_31 += F_3 ( V_4 , V_346 ) ;
if ( F_65 ( V_31 > V_341 ) )
V_31 = V_341 ;
return V_341 - V_31 ;
}
static int F_284 ( struct V_4 * V_4 , T_2 V_46 , unsigned int V_166 )
{
const unsigned long V_165 = 1 << V_166 ;
struct V_320 * V_315 = V_55 ;
struct V_248 V_248 ;
struct V_1 V_2 = {
. V_230 = F_228 ( V_165 , V_49 ) ,
. V_46 = ( V_46 = F_221 ( V_46 ) ) ,
. V_166 = V_166 ,
. V_140 = V_347 ,
. V_137 = ! ! ( V_342 & V_345 ) ,
. V_125 = ! ! ( V_342 & V_343 ) ,
. V_218 = 1 ,
} ;
F_25 () ;
V_315 -> V_19 |= V_323 | V_56 ;
F_259 ( V_46 ) ;
V_248 . V_257 = 0 ;
V_315 -> V_248 = & V_248 ;
if ( F_283 ( V_4 ) > V_4 -> V_348 ) {
do {
F_188 ( V_4 , & V_2 , true ) ;
} while ( V_2 . V_118 < V_165 && -- V_2 . V_140 >= 0 );
}
V_315 -> V_248 = NULL ;
V_55 -> V_19 &= ~ ( V_323 | V_56 ) ;
F_264 () ;
return V_2 . V_118 >= V_165 ;
}
int F_285 ( struct V_4 * V_4 , T_2 V_46 , unsigned int V_166 )
{
int V_190 ;
int V_42 ;
if ( F_283 ( V_4 ) <= V_4 -> V_348 &&
F_3 ( V_4 , V_349 ) <= V_4 -> V_350 )
return V_351 ;
if ( ! F_5 ( V_4 ) )
return V_351 ;
if ( ! ( V_46 & V_352 ) || ( V_55 -> V_19 & V_323 ) )
return V_353 ;
V_190 = F_193 ( V_4 ) ;
if ( F_286 ( V_190 , V_354 ) && V_190 != F_269 () )
return V_353 ;
if ( F_287 ( V_355 , & V_4 -> V_19 ) )
return V_353 ;
V_42 = F_284 ( V_4 , V_46 , V_166 ) ;
F_240 ( V_355 , & V_4 -> V_19 ) ;
if ( ! V_42 )
F_91 ( V_356 ) ;
return V_42 ;
}
int F_85 ( struct V_52 * V_52 )
{
return ! F_288 ( F_45 ( V_52 ) ) && ! F_289 ( V_52 ) ;
}
void F_290 ( struct V_52 * * V_357 , int V_165 )
{
struct V_11 * V_11 ;
struct V_4 * V_4 = NULL ;
int V_358 = 0 ;
int V_359 = 0 ;
int V_286 ;
for ( V_286 = 0 ; V_286 < V_165 ; V_286 ++ ) {
struct V_52 * V_52 = V_357 [ V_286 ] ;
struct V_4 * V_360 ;
V_358 ++ ;
V_360 = F_104 ( V_52 ) ;
if ( V_360 != V_4 ) {
if ( V_4 )
F_72 ( & V_4 -> V_167 ) ;
V_4 = V_360 ;
F_63 ( & V_4 -> V_167 ) ;
}
V_11 = F_140 ( V_52 , V_4 ) ;
if ( ! F_83 ( V_52 ) || ! F_81 ( V_52 ) )
continue;
if ( F_85 ( V_52 ) ) {
enum V_12 V_13 = F_291 ( V_52 ) ;
F_82 ( F_103 ( V_52 ) , V_52 ) ;
F_84 ( V_52 ) ;
F_143 ( V_52 , V_11 , V_361 ) ;
F_147 ( V_52 , V_11 , V_13 ) ;
V_359 ++ ;
}
}
if ( V_4 ) {
F_167 ( V_88 , V_359 ) ;
F_167 ( V_362 , V_358 ) ;
F_72 ( & V_4 -> V_167 ) ;
}
}
