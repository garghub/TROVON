static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
struct V_4 * F_3 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_5 ;
}
void F_4 ( struct V_6 * V_7 , const char * V_8 , const char * V_9 , ... )
{
struct V_10 V_11 ;
T_1 args ;
va_start ( args , V_9 ) ;
V_11 . V_9 = V_9 ;
V_11 . V_12 = & args ;
F_5 ( L_1 , V_8 , V_7 -> V_13 , & V_11 ) ;
va_end ( args ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_2 * V_2 = V_5 -> V_14 ;
int V_15 ;
F_7 ( & V_2 -> V_16 ) ;
while ( V_2 -> V_17 & V_18 ) {
F_8 ( & V_2 -> V_16 ) ;
V_15 = F_9 ( V_2 , true ) ;
if ( V_15 ) {
char V_19 [ V_20 ] ;
F_10 ( L_2
L_3 ,
F_11 ( V_5 , V_19 ) , V_15 ) ;
}
F_7 ( & V_2 -> V_16 ) ;
}
F_8 ( & V_2 -> V_16 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_21 * V_22 = V_5 -> V_14 -> V_23 ;
if ( V_22 -> V_24 == 0 && V_22 -> V_25 == 0 )
return;
F_13 () ;
F_14 ( V_22 , 0 ) ;
}
void F_15 ( struct V_4 * V_5 )
{
struct V_21 * V_22 = V_5 -> V_14 -> V_23 ;
if ( V_22 -> V_24 == 0 )
return;
F_13 () ;
F_16 () ;
F_17 ( V_22 , 0 , - 1 ) ;
F_18 ( V_22 ) ;
}
int F_19 ( struct V_4 * V_5 , int V_26 )
{
if ( V_26 > V_27 || V_26 < 512 || ! F_20 ( V_26 ) )
return - V_28 ;
if ( V_26 < F_21 ( V_5 ) )
return - V_28 ;
if ( V_5 -> V_29 != V_26 ) {
F_22 ( V_5 ) ;
V_5 -> V_29 = V_26 ;
V_5 -> V_14 -> V_30 = F_23 ( V_26 ) ;
F_12 ( V_5 ) ;
}
return 0 ;
}
int F_24 ( struct V_6 * V_7 , int V_26 )
{
if ( F_19 ( V_7 -> V_31 , V_26 ) )
return 0 ;
V_7 -> V_32 = V_26 ;
V_7 -> V_33 = F_23 ( V_26 ) ;
return V_7 -> V_32 ;
}
int F_25 ( struct V_6 * V_7 , int V_26 )
{
int V_34 = F_21 ( V_7 -> V_31 ) ;
if ( V_26 < V_34 )
V_26 = V_34 ;
return F_24 ( V_7 , V_26 ) ;
}
static int
F_26 ( struct V_2 * V_2 , T_2 V_35 ,
struct V_36 * V_37 , int V_38 )
{
V_37 -> V_39 = F_3 ( V_2 ) ;
V_37 -> V_40 = V_35 ;
F_27 ( V_37 ) ;
return 0 ;
}
static struct V_2 * F_28 ( struct V_41 * V_41 )
{
return V_41 -> V_42 -> V_43 ;
}
static unsigned int F_29 ( struct V_44 * V_45 )
{
unsigned int V_46 = V_47 | V_48 | V_49 ;
if ( V_45 -> V_50 & V_51 )
V_46 |= V_52 ;
return V_46 ;
}
static void F_30 ( struct V_53 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_56 ;
F_31 ( V_53 -> V_56 , NULL ) ;
F_32 ( V_55 ) ;
}
static T_3
F_33 ( struct V_44 * V_45 , struct V_57 * V_58 ,
int V_59 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
struct V_61 V_62 [ V_63 ] , * V_64 , * V_65 ;
T_4 V_66 = V_45 -> V_67 ;
bool V_68 = false ;
struct V_53 V_53 ;
T_3 V_15 ;
T_5 V_69 ;
int V_70 ;
if ( ( V_66 | F_34 ( V_58 ) ) &
( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
if ( V_59 <= V_63 )
V_64 = V_62 ;
else {
V_64 = F_35 ( V_59 * sizeof( struct V_61 ) , V_71 ) ;
if ( ! V_64 )
return - V_72 ;
}
F_36 ( & V_53 , V_64 , V_59 ) ;
V_53 . V_73 = V_5 ;
V_53 . V_74 . V_75 = V_66 >> 9 ;
V_53 . V_56 = V_76 ;
V_53 . V_77 = F_30 ;
V_15 = F_37 ( & V_53 , V_58 ) ;
if ( F_38 ( V_15 ) )
return V_15 ;
V_15 = V_53 . V_74 . V_78 ;
if ( F_39 ( V_58 ) == V_79 ) {
V_53 . V_80 = V_81 ;
if ( F_40 ( V_58 ) )
V_68 = true ;
} else {
V_53 . V_80 = F_29 ( V_45 ) ;
F_41 ( V_15 ) ;
}
V_69 = F_42 ( & V_53 ) ;
for (; ; ) {
F_43 ( V_82 ) ;
if ( ! F_44 ( V_53 . V_56 ) )
break;
if ( ! ( V_45 -> V_50 & V_83 ) ||
! F_45 ( F_46 ( V_5 ) , V_69 ) )
F_47 () ;
}
F_48 ( V_84 ) ;
F_49 (bvec, &bio, i) {
if ( V_68 && ! F_50 ( V_65 -> V_85 ) )
F_51 ( V_65 -> V_85 ) ;
F_52 ( V_65 -> V_85 ) ;
}
if ( V_64 != V_62 )
F_53 ( V_64 ) ;
if ( F_38 ( V_53 . V_86 ) )
return V_53 . V_86 ;
return V_15 ;
}
static void F_54 ( struct V_53 * V_53 )
{
struct V_87 * V_88 = V_53 -> V_56 ;
bool V_68 = V_88 -> V_68 ;
if ( V_88 -> V_89 && ! F_55 ( & V_88 -> V_90 ) ) {
if ( V_53 -> V_86 && ! V_88 -> V_53 . V_86 )
V_88 -> V_53 . V_86 = V_53 -> V_86 ;
} else {
if ( ! V_88 -> V_91 ) {
struct V_44 * V_45 = V_88 -> V_45 ;
T_3 V_15 = V_88 -> V_53 . V_86 ;
if ( F_56 ( ! V_15 ) ) {
V_15 = V_88 -> V_26 ;
V_45 -> V_67 += V_15 ;
}
V_88 -> V_45 -> V_92 ( V_45 , V_15 , 0 ) ;
F_57 ( & V_88 -> V_53 ) ;
} else {
struct V_54 * V_55 = V_88 -> V_55 ;
F_31 ( V_88 -> V_55 , NULL ) ;
F_32 ( V_55 ) ;
}
}
if ( V_68 ) {
F_58 ( V_53 ) ;
} else {
struct V_61 * V_65 ;
int V_70 ;
F_49 (bvec, bio, i)
F_52 ( V_65 -> V_85 ) ;
F_57 ( V_53 ) ;
}
}
static T_3
F_59 ( struct V_44 * V_45 , struct V_57 * V_58 , int V_59 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_2 = F_28 ( V_41 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
struct V_93 V_94 ;
struct V_87 * V_88 ;
struct V_53 * V_53 ;
bool V_95 = ( F_39 ( V_58 ) == V_79 ) , V_91 ;
T_4 V_66 = V_45 -> V_67 ;
T_5 V_69 = V_96 ;
int V_15 ;
if ( ( V_66 | F_34 ( V_58 ) ) &
( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
V_53 = F_60 ( V_71 , V_59 , V_97 ) ;
F_61 ( V_53 ) ;
V_88 = F_2 ( V_53 , struct V_87 , V_53 ) ;
V_88 -> V_91 = V_91 = F_62 ( V_45 ) ;
if ( V_88 -> V_91 )
V_88 -> V_55 = V_76 ;
else
V_88 -> V_45 = V_45 ;
V_88 -> V_26 = 0 ;
V_88 -> V_89 = false ;
V_88 -> V_68 = V_95 && ( V_58 -> type == V_98 ) ;
F_63 ( & V_94 ) ;
for (; ; ) {
V_53 -> V_73 = V_5 ;
V_53 -> V_74 . V_75 = V_66 >> 9 ;
V_53 -> V_56 = V_88 ;
V_53 -> V_77 = F_54 ;
V_15 = F_37 ( V_53 , V_58 ) ;
if ( F_38 ( V_15 ) ) {
V_53 -> V_86 = V_15 ;
F_64 ( V_53 ) ;
break;
}
if ( V_95 ) {
V_53 -> V_80 = V_81 ;
if ( V_88 -> V_68 )
F_65 ( V_53 ) ;
} else {
V_53 -> V_80 = F_29 ( V_45 ) ;
F_41 ( V_53 -> V_74 . V_78 ) ;
}
V_88 -> V_26 += V_53 -> V_74 . V_78 ;
V_66 += V_53 -> V_74 . V_78 ;
V_59 = F_66 ( V_58 , V_99 ) ;
if ( ! V_59 ) {
V_69 = F_42 ( V_53 ) ;
break;
}
if ( ! V_88 -> V_89 ) {
V_88 -> V_89 = true ;
F_67 ( & V_88 -> V_90 , 2 ) ;
} else {
F_68 ( & V_88 -> V_90 ) ;
}
F_42 ( V_53 ) ;
V_53 = F_69 ( V_71 , V_59 ) ;
}
F_70 ( & V_94 ) ;
if ( ! V_91 )
return - V_100 ;
for (; ; ) {
F_43 ( V_82 ) ;
if ( ! F_44 ( V_88 -> V_55 ) )
break;
if ( ! ( V_45 -> V_50 & V_83 ) ||
! F_45 ( F_46 ( V_5 ) , V_69 ) )
F_47 () ;
}
F_48 ( V_84 ) ;
V_15 = V_88 -> V_53 . V_86 ;
if ( F_56 ( ! V_15 ) )
V_15 = V_88 -> V_26 ;
F_57 ( & V_88 -> V_53 ) ;
return V_15 ;
}
static T_3
F_71 ( struct V_44 * V_45 , struct V_57 * V_58 )
{
int V_59 ;
V_59 = F_66 ( V_58 , V_99 + 1 ) ;
if ( ! V_59 )
return 0 ;
if ( F_62 ( V_45 ) && V_59 <= V_99 )
return F_33 ( V_45 , V_58 , V_59 ) ;
return F_59 ( V_45 , V_58 , F_72 ( V_59 , V_99 ) ) ;
}
static T_6 int F_73 ( void )
{
V_97 = F_74 ( 4 , F_75 ( struct V_87 , V_53 ) ) ;
if ( ! V_97 )
return - V_72 ;
return 0 ;
}
int F_76 ( struct V_4 * V_5 , int V_101 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_101 )
return F_77 ( V_5 -> V_14 -> V_23 ) ;
return F_78 ( V_5 -> V_14 -> V_23 ) ;
}
int F_22 ( struct V_4 * V_5 )
{
return F_76 ( V_5 , 1 ) ;
}
int F_79 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_80 ( V_5 ) ;
if ( V_7 ) {
int V_102 = F_81 ( V_7 ) ;
F_82 ( V_7 ) ;
return V_102 ;
}
return F_22 ( V_5 ) ;
}
struct V_6 * F_83 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_84 ( & V_5 -> V_103 ) ;
if ( ++ V_5 -> V_104 > 1 ) {
V_7 = F_80 ( V_5 ) ;
if ( V_7 )
F_82 ( V_7 ) ;
F_85 ( & V_5 -> V_103 ) ;
return V_7 ;
}
V_7 = F_86 ( V_5 ) ;
if ( ! V_7 )
goto V_105;
if ( V_7 -> V_106 -> V_107 )
error = V_7 -> V_106 -> V_107 ( V_7 ) ;
else
error = V_107 ( V_7 ) ;
if ( error ) {
F_87 ( V_7 ) ;
V_5 -> V_104 -- ;
F_85 ( & V_5 -> V_103 ) ;
return F_88 ( error ) ;
}
F_87 ( V_7 ) ;
V_105:
F_22 ( V_5 ) ;
F_85 ( & V_5 -> V_103 ) ;
return V_7 ;
}
int F_89 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
int error = - V_28 ;
F_84 ( & V_5 -> V_103 ) ;
if ( ! V_5 -> V_104 )
goto V_105;
error = 0 ;
if ( -- V_5 -> V_104 > 0 )
goto V_105;
if ( ! V_7 )
goto V_105;
if ( V_7 -> V_106 -> V_108 )
error = V_7 -> V_106 -> V_108 ( V_7 ) ;
else
error = V_108 ( V_7 ) ;
if ( error )
V_5 -> V_104 ++ ;
V_105:
F_85 ( & V_5 -> V_103 ) ;
return error ;
}
static int F_90 ( struct V_109 * V_109 , struct V_110 * V_111 )
{
return F_91 ( V_109 , F_26 , V_111 ) ;
}
static int F_92 ( struct V_41 * V_41 , struct V_109 * V_109 )
{
return F_93 ( V_109 , F_26 ) ;
}
static int F_94 ( struct V_41 * V_41 , struct V_21 * V_22 ,
struct V_112 * V_113 , unsigned V_59 )
{
return F_95 ( V_22 , V_113 , V_59 , F_26 ) ;
}
static int F_96 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_66 , unsigned V_114 , unsigned V_115 ,
struct V_109 * * V_116 , void * * V_117 )
{
return F_97 ( V_22 , V_66 , V_114 , V_115 , V_116 ,
F_26 ) ;
}
static int F_98 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_66 , unsigned V_114 , unsigned V_118 ,
struct V_109 * V_109 , void * V_117 )
{
int V_15 ;
V_15 = F_99 ( V_41 , V_22 , V_66 , V_114 , V_118 , V_109 , V_117 ) ;
F_100 ( V_109 ) ;
F_52 ( V_109 ) ;
return V_15 ;
}
static T_4 F_101 ( struct V_41 * V_41 , T_4 V_119 , int V_120 )
{
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_121 ;
F_102 ( V_14 ) ;
V_121 = F_103 ( V_41 , V_119 , V_120 , F_104 ( V_14 ) ) ;
F_105 ( V_14 ) ;
return V_121 ;
}
int F_106 ( struct V_41 * V_122 , T_4 V_123 , T_4 V_124 , int V_125 )
{
struct V_2 * V_14 = F_28 ( V_122 ) ;
struct V_4 * V_5 = F_3 ( V_14 ) ;
int error ;
error = F_107 ( V_122 -> V_42 , V_123 , V_124 ) ;
if ( error )
return error ;
error = F_108 ( V_5 , V_71 , NULL ) ;
if ( error == - V_126 )
error = 0 ;
return error ;
}
int F_109 ( struct V_4 * V_5 , T_2 V_127 ,
struct V_109 * V_109 )
{
const struct V_128 * V_129 = V_5 -> V_130 -> V_131 ;
int V_132 = - V_126 ;
if ( ! V_129 -> V_133 || F_110 ( V_5 ) )
return V_132 ;
V_132 = F_111 ( V_5 -> V_134 , false ) ;
if ( V_132 )
return V_132 ;
V_132 = V_129 -> V_133 ( V_5 , V_127 + F_112 ( V_5 ) , V_109 , false ) ;
F_113 ( V_5 -> V_134 ) ;
return V_132 ;
}
int F_114 ( struct V_4 * V_5 , T_2 V_127 ,
struct V_109 * V_109 , struct V_110 * V_111 )
{
int V_132 ;
const struct V_128 * V_129 = V_5 -> V_130 -> V_131 ;
if ( ! V_129 -> V_133 || F_110 ( V_5 ) )
return - V_126 ;
V_132 = F_111 ( V_5 -> V_134 , false ) ;
if ( V_132 )
return V_132 ;
F_115 ( V_109 ) ;
V_132 = V_129 -> V_133 ( V_5 , V_127 + F_112 ( V_5 ) , V_109 , true ) ;
if ( V_132 )
F_116 ( V_109 ) ;
else
F_100 ( V_109 ) ;
F_113 ( V_5 -> V_134 ) ;
return V_132 ;
}
long F_117 ( struct V_4 * V_5 , struct V_135 * V_136 )
{
T_2 V_127 = V_136 -> V_127 ;
long V_137 , V_26 = V_136 -> V_26 ;
const struct V_128 * V_129 = V_5 -> V_130 -> V_131 ;
F_118 () ;
if ( V_26 < 0 )
return V_26 ;
if ( ! F_119 ( F_46 ( V_5 ) ) || ! V_129 -> V_138 )
return - V_126 ;
if ( ( V_127 + F_120 ( V_26 , 512 ) ) >
F_121 ( V_5 -> V_139 ) )
return - V_140 ;
V_127 += F_112 ( V_5 ) ;
if ( V_127 % ( V_27 / 512 ) )
return - V_28 ;
V_137 = V_129 -> V_138 ( V_5 , V_127 , & V_136 -> V_141 , & V_136 -> V_142 , V_26 ) ;
if ( ! V_137 )
return - V_140 ;
if ( V_137 > 0 && V_137 & ~ V_143 )
return - V_144 ;
return F_72 ( V_137 , V_26 ) ;
}
int F_122 ( struct V_6 * V_7 , int V_145 )
{
struct V_135 V_136 = {
. V_127 = 0 ,
. V_26 = V_27 ,
} ;
int V_146 ;
if ( V_145 != V_27 ) {
F_123 ( V_7 , V_147 , L_4 ) ;
return - V_28 ;
}
V_146 = F_117 ( V_7 -> V_31 , & V_136 ) ;
if ( V_146 < 0 ) {
switch ( V_146 ) {
case - V_126 :
F_123 ( V_7 , V_147 ,
L_5 ) ;
break;
case - V_28 :
F_123 ( V_7 , V_147 ,
L_6 ) ;
break;
default:
F_123 ( V_7 , V_147 ,
L_7 , V_146 ) ;
}
return V_146 ;
}
return 0 ;
}
bool F_124 ( struct V_4 * V_5 )
{
struct V_135 V_136 = {
. V_26 = V_27 ,
} ;
if ( ! F_125 ( V_148 ) )
return false ;
V_136 . V_127 = 0 ;
if ( F_117 ( V_5 , & V_136 ) < 0 )
return false ;
V_136 . V_127 = V_5 -> V_139 -> V_149 - ( V_27 / 512 ) ;
if ( F_117 ( V_5 , & V_136 ) < 0 )
return false ;
return true ;
}
static struct V_2 * F_126 ( struct V_6 * V_7 )
{
struct V_1 * V_150 = F_127 ( V_151 , V_71 ) ;
if ( ! V_150 )
return NULL ;
return & V_150 -> V_3 ;
}
static void F_128 ( struct V_152 * V_153 )
{
struct V_2 * V_2 = F_2 ( V_153 , struct V_2 , V_154 ) ;
struct V_1 * V_155 = F_1 ( V_2 ) ;
F_129 ( V_151 , V_155 ) ;
}
static void F_130 ( struct V_2 * V_2 )
{
F_131 ( & V_2 -> V_154 , F_128 ) ;
}
static void F_132 ( void * V_156 )
{
struct V_1 * V_150 = (struct V_1 * ) V_156 ;
struct V_4 * V_5 = & V_150 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_133 ( & V_5 -> V_157 ) ;
F_134 ( & V_5 -> V_158 ) ;
#ifdef F_135
F_134 ( & V_5 -> V_159 ) ;
#endif
F_136 ( & V_150 -> V_3 ) ;
F_133 ( & V_5 -> V_103 ) ;
}
static void F_137 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
F_138 ( & V_2 -> V_160 ) ;
F_139 ( V_2 ) ;
F_140 ( V_2 ) ;
F_7 ( & V_161 ) ;
F_141 ( & V_5 -> V_158 ) ;
F_8 ( & V_161 ) ;
}
static struct V_162 * F_142 ( struct V_163 * V_164 ,
int V_115 , const char * V_165 , void * V_166 )
{
struct V_162 * V_167 ;
V_167 = F_143 ( V_164 , L_8 , & V_168 , NULL , V_169 ) ;
if ( ! F_144 ( V_167 ) )
V_167 -> V_170 -> V_171 |= V_172 ;
return V_167 ;
}
void T_6 F_145 ( void )
{
int V_146 ;
static struct V_173 * V_174 ;
V_151 = F_146 ( L_9 , sizeof( struct V_1 ) ,
0 , ( V_175 | V_176 |
V_177 | V_178 | V_179 ) ,
F_132 ) ;
V_146 = F_147 ( & V_180 ) ;
if ( V_146 )
F_148 ( L_10 ) ;
V_174 = F_149 ( & V_180 ) ;
if ( F_144 ( V_174 ) )
F_148 ( L_11 ) ;
V_181 = V_174 -> V_182 ;
}
static inline unsigned long F_150 ( T_7 V_183 )
{
return F_151 ( V_183 ) + F_152 ( V_183 ) ;
}
static int F_153 ( struct V_2 * V_2 , void * V_166 )
{
return F_1 ( V_2 ) -> V_5 . V_184 == * ( T_7 * ) V_166 ;
}
static int F_154 ( struct V_2 * V_2 , void * V_166 )
{
F_1 ( V_2 ) -> V_5 . V_184 = * ( T_7 * ) V_166 ;
return 0 ;
}
struct V_4 * F_155 ( T_7 V_183 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_156 ( V_181 , F_150 ( V_183 ) ,
F_153 , F_154 , & V_183 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_17 & V_185 ) {
V_5 -> V_186 = NULL ;
V_5 -> V_187 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_29 = ( 1 << V_2 -> V_30 ) ;
V_5 -> V_188 = 0 ;
V_5 -> V_189 = 0 ;
V_2 -> V_190 = V_191 ;
V_2 -> V_192 = V_183 ;
V_2 -> V_193 = V_5 ;
V_2 -> V_160 . V_194 = & V_195 ;
F_157 ( & V_2 -> V_160 , V_196 ) ;
F_7 ( & V_161 ) ;
F_158 ( & V_5 -> V_158 , & V_197 ) ;
F_8 ( & V_161 ) ;
F_159 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_160 ( struct V_4 * V_5 )
{
F_161 ( V_5 -> V_14 ) ;
return V_5 ;
}
long F_162 ( void )
{
struct V_4 * V_5 ;
long V_15 = 0 ;
F_7 ( & V_161 ) ;
F_163 (bdev, &all_bdevs, bd_list) {
V_15 += V_5 -> V_14 -> V_23 -> V_24 ;
}
F_8 ( & V_161 ) ;
return V_15 ;
}
void F_164 ( struct V_4 * V_5 )
{
F_165 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_166 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_161 ) ;
V_5 = V_2 -> V_193 ;
if ( V_5 ) {
F_160 ( V_5 ) ;
F_8 ( & V_161 ) ;
return V_5 ;
}
F_8 ( & V_161 ) ;
V_5 = F_155 ( V_2 -> V_192 ) ;
if ( V_5 ) {
F_7 ( & V_161 ) ;
if ( ! V_2 -> V_193 ) {
F_160 ( V_5 ) ;
V_2 -> V_193 = V_5 ;
V_2 -> V_23 = V_5 -> V_14 -> V_23 ;
}
F_8 ( & V_161 ) ;
}
return V_5 ;
}
void F_167 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_161 ) ;
if ( ! F_168 ( V_2 -> V_198 ) )
V_5 = V_2 -> V_193 ;
V_2 -> V_193 = NULL ;
V_2 -> V_23 = & V_2 -> V_160 ;
F_8 ( & V_161 ) ;
if ( V_5 )
F_164 ( V_5 ) ;
}
static bool F_169 ( struct V_4 * V_5 , struct V_4 * V_199 ,
void * V_200 )
{
if ( V_5 -> V_201 == V_200 )
return true ;
else if ( V_5 -> V_201 != NULL )
return false ;
else if ( V_199 == V_5 )
return true ;
else if ( V_199 -> V_201 == F_169 )
return true ;
else if ( V_199 -> V_201 != NULL )
return false ;
else
return true ;
}
static int F_170 ( struct V_4 * V_5 ,
struct V_4 * V_199 , void * V_200 )
{
V_202:
if ( ! F_169 ( V_5 , V_199 , V_200 ) )
return - V_203 ;
if ( V_199 -> V_204 ) {
T_8 * V_205 = F_171 ( & V_199 -> V_204 , 0 ) ;
F_172 ( V_101 ) ;
F_173 ( V_205 , & V_101 , V_82 ) ;
F_8 ( & V_161 ) ;
F_174 () ;
F_175 ( V_205 , & V_101 ) ;
F_7 ( & V_161 ) ;
goto V_202;
}
return 0 ;
}
static struct V_4 * F_176 ( struct V_4 * V_5 ,
void * V_200 )
{
struct V_206 * V_207 ;
struct V_4 * V_199 ;
int V_208 , V_146 ;
F_118 () ;
V_207 = F_177 ( V_5 -> V_184 , & V_208 ) ;
if ( ! V_207 )
return F_88 ( - V_144 ) ;
if ( V_208 )
V_199 = F_178 ( V_207 , 0 ) ;
else
V_199 = F_160 ( V_5 ) ;
F_179 ( V_207 -> V_131 -> V_209 ) ;
F_180 ( V_207 ) ;
if ( ! V_199 )
return F_88 ( - V_72 ) ;
F_7 ( & V_161 ) ;
V_146 = F_170 ( V_5 , V_199 , V_200 ) ;
if ( V_146 == 0 ) {
V_199 -> V_204 = V_200 ;
F_8 ( & V_161 ) ;
return V_199 ;
} else {
F_8 ( & V_161 ) ;
F_164 ( V_199 ) ;
return F_88 ( V_146 ) ;
}
}
static struct V_210 * F_181 ( struct V_4 * V_5 ,
struct V_206 * V_207 )
{
struct V_210 * V_200 ;
F_163 (holder, &bdev->bd_holder_disks, list)
if ( V_200 -> V_207 == V_207 )
return V_200 ;
return NULL ;
}
static int F_182 ( struct V_211 * V_212 , struct V_211 * V_213 )
{
return F_183 ( V_212 , V_213 , F_184 ( V_213 ) ) ;
}
static void F_185 ( struct V_211 * V_212 , struct V_211 * V_213 )
{
F_186 ( V_212 , F_184 ( V_213 ) ) ;
}
int F_187 ( struct V_4 * V_5 , struct V_206 * V_207 )
{
struct V_210 * V_200 ;
int V_15 = 0 ;
F_84 ( & V_5 -> V_157 ) ;
F_188 ( ! V_5 -> V_201 ) ;
if ( F_189 ( ! V_207 -> V_214 || ! V_5 -> V_139 -> V_215 ) )
goto V_216;
V_200 = F_181 ( V_5 , V_207 ) ;
if ( V_200 ) {
V_200 -> V_217 ++ ;
goto V_216;
}
V_200 = F_190 ( sizeof( * V_200 ) , V_71 ) ;
if ( ! V_200 ) {
V_15 = - V_72 ;
goto V_216;
}
F_134 ( & V_200 -> V_218 ) ;
V_200 -> V_207 = V_207 ;
V_200 -> V_217 = 1 ;
V_15 = F_182 ( V_207 -> V_214 , & F_191 ( V_5 -> V_139 ) -> V_219 ) ;
if ( V_15 )
goto V_220;
V_15 = F_182 ( V_5 -> V_139 -> V_215 , & F_192 ( V_207 ) -> V_219 ) ;
if ( V_15 )
goto V_221;
F_193 ( V_5 -> V_139 -> V_215 ) ;
F_158 ( & V_200 -> V_218 , & V_5 -> V_159 ) ;
goto V_216;
V_221:
F_185 ( V_207 -> V_214 , & F_191 ( V_5 -> V_139 ) -> V_219 ) ;
V_220:
F_53 ( V_200 ) ;
V_216:
F_85 ( & V_5 -> V_157 ) ;
return V_15 ;
}
void F_194 ( struct V_4 * V_5 , struct V_206 * V_207 )
{
struct V_210 * V_200 ;
F_84 ( & V_5 -> V_157 ) ;
V_200 = F_181 ( V_5 , V_207 ) ;
if ( ! F_188 ( V_200 == NULL ) && ! -- V_200 -> V_217 ) {
F_185 ( V_207 -> V_214 , & F_191 ( V_5 -> V_139 ) -> V_219 ) ;
F_185 ( V_5 -> V_139 -> V_215 ,
& F_192 ( V_207 ) -> V_219 ) ;
F_195 ( V_5 -> V_139 -> V_215 ) ;
F_141 ( & V_200 -> V_218 ) ;
F_53 ( V_200 ) ;
}
F_85 ( & V_5 -> V_157 ) ;
}
static void F_196 ( struct V_4 * V_5 , bool V_222 )
{
if ( F_197 ( V_5 , V_222 ) ) {
F_198 ( V_223 L_12
L_13 ,
V_5 -> V_130 ? V_5 -> V_130 -> V_224 : L_14 ) ;
}
if ( ! V_5 -> V_130 )
return;
if ( F_199 ( V_5 -> V_130 ) )
V_5 -> V_189 = 1 ;
}
void F_200 ( struct V_206 * V_207 , struct V_4 * V_5 )
{
T_4 V_225 , V_226 ;
V_225 = ( T_4 ) F_201 ( V_207 ) << 9 ;
V_226 = F_104 ( V_5 -> V_14 ) ;
if ( V_225 != V_226 ) {
F_198 ( V_227
L_15 ,
V_207 -> V_224 , V_226 , V_225 ) ;
F_202 ( V_5 -> V_14 , V_225 ) ;
F_196 ( V_5 , false ) ;
}
}
int F_203 ( struct V_206 * V_207 )
{
struct V_4 * V_5 ;
int V_15 = 0 ;
if ( V_207 -> V_131 -> F_203 )
V_15 = V_207 -> V_131 -> F_203 ( V_207 ) ;
F_204 ( V_207 ) ;
V_5 = F_178 ( V_207 , 0 ) ;
if ( ! V_5 )
return V_15 ;
F_84 ( & V_5 -> V_157 ) ;
F_200 ( V_207 , V_5 ) ;
V_5 -> V_189 = 0 ;
F_85 ( & V_5 -> V_157 ) ;
F_164 ( V_5 ) ;
return V_15 ;
}
int F_205 ( struct V_4 * V_5 )
{
struct V_206 * V_207 = V_5 -> V_130 ;
const struct V_128 * V_228 = V_207 -> V_131 ;
unsigned int V_229 ;
V_229 = F_206 ( V_207 , V_230 |
V_231 ) ;
if ( ! ( V_229 & V_230 ) )
return 0 ;
F_196 ( V_5 , true ) ;
if ( V_228 -> F_203 )
V_228 -> F_203 ( V_5 -> V_130 ) ;
return 1 ;
}
void F_207 ( struct V_4 * V_5 , T_4 V_26 )
{
unsigned V_232 = F_21 ( V_5 ) ;
F_102 ( V_5 -> V_14 ) ;
F_202 ( V_5 -> V_14 , V_26 ) ;
F_105 ( V_5 -> V_14 ) ;
while ( V_232 < V_27 ) {
if ( V_26 & V_232 )
break;
V_232 <<= 1 ;
}
V_5 -> V_29 = V_232 ;
V_5 -> V_14 -> V_30 = F_23 ( V_232 ) ;
}
static int F_208 ( struct V_4 * V_5 , T_9 V_233 , int V_234 )
{
struct V_206 * V_207 ;
struct V_235 * V_209 ;
int V_15 ;
int V_208 ;
int V_236 = 0 ;
if ( V_233 & V_237 )
V_236 |= V_238 ;
if ( V_233 & V_239 )
V_236 |= V_240 ;
if ( ! V_234 ) {
V_15 = F_209 ( V_5 -> V_14 , V_236 ) ;
if ( V_15 != 0 ) {
F_164 ( V_5 ) ;
return V_15 ;
}
}
V_241:
V_15 = - V_144 ;
V_207 = F_177 ( V_5 -> V_184 , & V_208 ) ;
if ( ! V_207 )
goto V_105;
V_209 = V_207 -> V_131 -> V_209 ;
F_210 ( V_207 ) ;
F_211 ( & V_5 -> V_157 , V_234 ) ;
if ( ! V_5 -> V_242 ) {
V_5 -> V_130 = V_207 ;
V_5 -> V_134 = V_207 -> V_243 ;
V_5 -> V_186 = V_5 ;
if ( ! V_208 ) {
V_15 = - V_144 ;
V_5 -> V_139 = F_212 ( V_207 , V_208 ) ;
if ( ! V_5 -> V_139 )
goto V_244;
V_15 = 0 ;
if ( V_207 -> V_131 -> V_245 ) {
V_15 = V_207 -> V_131 -> V_245 ( V_5 , V_233 ) ;
if ( V_15 == - V_246 ) {
F_213 ( V_5 -> V_139 ) ;
V_5 -> V_139 = NULL ;
V_5 -> V_130 = NULL ;
V_5 -> V_134 = NULL ;
F_85 ( & V_5 -> V_157 ) ;
F_214 ( V_207 ) ;
F_180 ( V_207 ) ;
F_179 ( V_209 ) ;
goto V_241;
}
}
if ( ! V_15 )
F_207 ( V_5 , ( T_4 ) F_201 ( V_207 ) << 9 ) ;
if ( V_5 -> V_189 ) {
if ( ! V_15 )
F_215 ( V_207 , V_5 ) ;
else if ( V_15 == - V_247 )
F_216 ( V_207 , V_5 ) ;
}
if ( V_15 )
goto V_244;
} else {
struct V_4 * V_199 ;
V_199 = F_178 ( V_207 , 0 ) ;
V_15 = - V_72 ;
if ( ! V_199 )
goto V_244;
F_217 ( V_234 ) ;
V_15 = F_208 ( V_199 , V_233 , 1 ) ;
if ( V_15 )
goto V_244;
V_5 -> V_186 = V_199 ;
V_5 -> V_139 = F_212 ( V_207 , V_208 ) ;
if ( ! ( V_207 -> V_115 & V_248 ) ||
! V_5 -> V_139 || ! V_5 -> V_139 -> V_149 ) {
V_15 = - V_144 ;
goto V_244;
}
F_207 ( V_5 , ( T_4 ) V_5 -> V_139 -> V_149 << 9 ) ;
}
} else {
if ( V_5 -> V_186 == V_5 ) {
V_15 = 0 ;
if ( V_5 -> V_130 -> V_131 -> V_245 )
V_15 = V_5 -> V_130 -> V_131 -> V_245 ( V_5 , V_233 ) ;
if ( V_5 -> V_189 ) {
if ( ! V_15 )
F_215 ( V_5 -> V_130 , V_5 ) ;
else if ( V_15 == - V_247 )
F_216 ( V_5 -> V_130 , V_5 ) ;
}
if ( V_15 )
goto V_249;
}
F_180 ( V_207 ) ;
F_179 ( V_209 ) ;
}
V_5 -> V_242 ++ ;
if ( V_234 )
V_5 -> V_188 ++ ;
F_85 ( & V_5 -> V_157 ) ;
F_214 ( V_207 ) ;
return 0 ;
V_244:
F_213 ( V_5 -> V_139 ) ;
V_5 -> V_130 = NULL ;
V_5 -> V_139 = NULL ;
V_5 -> V_134 = NULL ;
if ( V_5 != V_5 -> V_186 )
F_218 ( V_5 -> V_186 , V_233 , 1 ) ;
V_5 -> V_186 = NULL ;
V_249:
F_85 ( & V_5 -> V_157 ) ;
F_214 ( V_207 ) ;
F_180 ( V_207 ) ;
F_179 ( V_209 ) ;
V_105:
F_164 ( V_5 ) ;
return V_15 ;
}
int F_219 ( struct V_4 * V_5 , T_9 V_233 , void * V_200 )
{
struct V_4 * V_199 = NULL ;
int V_102 ;
F_188 ( ( V_233 & V_250 ) && ! V_200 ) ;
if ( ( V_233 & V_250 ) && V_200 ) {
V_199 = F_176 ( V_5 , V_200 ) ;
if ( F_144 ( V_199 ) ) {
F_164 ( V_5 ) ;
return F_220 ( V_199 ) ;
}
}
V_102 = F_208 ( V_5 , V_233 , 0 ) ;
if ( V_199 ) {
struct V_206 * V_207 = V_199 -> V_130 ;
F_84 ( & V_5 -> V_157 ) ;
F_7 ( & V_161 ) ;
if ( ! V_102 ) {
F_217 ( ! F_169 ( V_5 , V_199 , V_200 ) ) ;
V_199 -> V_251 ++ ;
V_199 -> V_201 = F_169 ;
V_5 -> V_251 ++ ;
V_5 -> V_201 = V_200 ;
}
F_217 ( V_199 -> V_204 != V_200 ) ;
V_199 -> V_204 = NULL ;
F_221 ( & V_199 -> V_204 , 0 ) ;
F_8 ( & V_161 ) ;
if ( ! V_102 && ( V_233 & V_239 ) && ! V_5 -> V_252 &&
( V_207 -> V_115 & V_253 ) ) {
V_5 -> V_252 = true ;
F_210 ( V_207 ) ;
}
F_85 ( & V_5 -> V_157 ) ;
F_164 ( V_199 ) ;
}
return V_102 ;
}
struct V_4 * F_222 ( const char * V_254 , T_9 V_233 ,
void * V_200 )
{
struct V_4 * V_5 ;
int V_146 ;
V_5 = F_223 ( V_254 ) ;
if ( F_144 ( V_5 ) )
return V_5 ;
V_146 = F_219 ( V_5 , V_233 , V_200 ) ;
if ( V_146 )
return F_88 ( V_146 ) ;
if ( ( V_233 & V_239 ) && F_224 ( V_5 ) ) {
F_225 ( V_5 , V_233 ) ;
return F_88 ( - V_255 ) ;
}
return V_5 ;
}
struct V_4 * F_226 ( T_7 V_183 , T_9 V_233 , void * V_200 )
{
struct V_4 * V_5 ;
int V_146 ;
V_5 = F_155 ( V_183 ) ;
if ( ! V_5 )
return F_88 ( - V_72 ) ;
V_146 = F_219 ( V_5 , V_233 , V_200 ) ;
if ( V_146 )
return F_88 ( V_146 ) ;
return V_5 ;
}
static int F_227 ( struct V_2 * V_2 , struct V_41 * V_122 )
{
struct V_4 * V_5 ;
V_122 -> V_256 |= V_257 ;
if ( V_122 -> V_256 & V_258 )
V_122 -> V_259 |= V_260 ;
if ( V_122 -> V_256 & V_261 )
V_122 -> V_259 |= V_250 ;
if ( ( V_122 -> V_256 & V_262 ) == 3 )
V_122 -> V_259 |= V_263 ;
V_5 = F_166 ( V_2 ) ;
if ( V_5 == NULL )
return - V_72 ;
V_122 -> V_42 = V_5 -> V_14 -> V_23 ;
return F_219 ( V_5 , V_122 -> V_259 , V_122 ) ;
}
static void F_218 ( struct V_4 * V_5 , T_9 V_233 , int V_234 )
{
struct V_206 * V_207 = V_5 -> V_130 ;
struct V_4 * V_264 = NULL ;
F_211 ( & V_5 -> V_157 , V_234 ) ;
if ( V_234 )
V_5 -> V_188 -- ;
if ( ! -- V_5 -> V_242 ) {
F_188 ( V_5 -> V_251 ) ;
F_22 ( V_5 ) ;
F_12 ( V_5 ) ;
F_6 ( V_5 ) ;
F_228 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_186 == V_5 ) {
if ( V_207 -> V_131 -> V_265 )
V_207 -> V_131 -> V_265 ( V_207 , V_233 ) ;
}
if ( ! V_5 -> V_242 ) {
struct V_235 * V_209 = V_207 -> V_131 -> V_209 ;
F_213 ( V_5 -> V_139 ) ;
V_5 -> V_139 = NULL ;
V_5 -> V_130 = NULL ;
if ( V_5 != V_5 -> V_186 )
V_264 = V_5 -> V_186 ;
V_5 -> V_186 = NULL ;
F_180 ( V_207 ) ;
F_179 ( V_209 ) ;
}
F_85 ( & V_5 -> V_157 ) ;
F_164 ( V_5 ) ;
if ( V_264 )
F_218 ( V_264 , V_233 , 1 ) ;
}
void F_225 ( struct V_4 * V_5 , T_9 V_233 )
{
F_84 ( & V_5 -> V_157 ) ;
if ( V_233 & V_250 ) {
bool V_266 ;
F_7 ( & V_161 ) ;
F_188 ( -- V_5 -> V_251 < 0 ) ;
F_188 ( -- V_5 -> V_186 -> V_251 < 0 ) ;
if ( ( V_266 = ! V_5 -> V_251 ) )
V_5 -> V_201 = NULL ;
if ( ! V_5 -> V_186 -> V_251 )
V_5 -> V_186 -> V_201 = NULL ;
F_8 ( & V_161 ) ;
if ( V_266 && V_5 -> V_252 ) {
F_214 ( V_5 -> V_130 ) ;
V_5 -> V_252 = false ;
}
}
F_229 ( V_5 -> V_130 , V_230 ) ;
F_85 ( & V_5 -> V_157 ) ;
F_218 ( V_5 , V_233 , 0 ) ;
}
static int F_230 ( struct V_2 * V_2 , struct V_41 * V_122 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_122 ) ) ;
F_225 ( V_5 , V_122 -> V_259 ) ;
return 0 ;
}
static long F_231 ( struct V_41 * V_41 , unsigned V_267 , unsigned long V_268 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
T_9 V_233 = V_41 -> V_259 ;
if ( V_41 -> V_256 & V_258 )
V_233 |= V_260 ;
else
V_233 &= ~ V_260 ;
return F_232 ( V_5 , V_233 , V_267 , V_268 ) ;
}
T_3 F_233 ( struct V_44 * V_45 , struct V_57 * V_212 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_104 ( V_14 ) ;
struct V_93 V_94 ;
T_3 V_15 ;
if ( F_224 ( F_3 ( V_14 ) ) )
return - V_269 ;
if ( ! F_234 ( V_212 ) )
return 0 ;
if ( V_45 -> V_67 >= V_26 )
return - V_270 ;
F_235 ( V_212 , V_26 - V_45 -> V_67 ) ;
F_63 ( & V_94 ) ;
V_15 = F_236 ( V_45 , V_212 ) ;
if ( V_15 > 0 )
V_15 = F_237 ( V_45 , V_15 ) ;
F_70 ( & V_94 ) ;
return V_15 ;
}
T_3 F_238 ( struct V_44 * V_45 , struct V_57 * V_213 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_104 ( V_14 ) ;
T_4 V_66 = V_45 -> V_67 ;
if ( V_66 >= V_26 )
return 0 ;
V_26 -= V_66 ;
F_235 ( V_213 , V_26 ) ;
return F_239 ( V_45 , V_213 ) ;
}
static int F_240 ( struct V_109 * V_109 , T_10 V_101 )
{
struct V_6 * V_271 = F_1 ( V_109 -> V_22 -> V_43 ) -> V_5 . V_187 ;
if ( V_271 && V_271 -> V_106 -> V_272 )
return V_271 -> V_106 -> V_272 ( V_271 , V_109 , V_101 ) ;
return F_241 ( V_109 ) ;
}
static int F_242 ( struct V_21 * V_22 ,
struct V_110 * V_111 )
{
if ( F_243 ( V_22 ) ) {
struct V_4 * V_5 = F_3 ( V_22 -> V_43 ) ;
return F_244 ( V_22 , V_5 , V_111 ) ;
}
return F_245 ( V_22 , V_111 ) ;
}
static long F_246 ( struct V_41 * V_41 , int V_233 , T_4 V_123 ,
T_4 V_114 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
struct V_273 * V_274 = F_46 ( V_5 ) ;
struct V_21 * V_22 ;
T_4 V_124 = V_123 + V_114 - 1 ;
T_4 V_275 ;
int error ;
if ( V_233 & ~ V_276 )
return - V_126 ;
V_275 = F_104 ( V_5 -> V_14 ) ;
if ( V_123 >= V_275 )
return - V_28 ;
if ( V_124 >= V_275 ) {
if ( V_233 & V_277 ) {
V_114 = V_275 - V_123 ;
V_124 = V_123 + V_114 - 1 ;
} else
return - V_28 ;
}
if ( ( V_123 | V_114 ) & ( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
V_22 = V_5 -> V_14 -> V_23 ;
F_247 ( V_22 , V_123 , V_124 ) ;
switch ( V_233 ) {
case V_278 :
case V_278 | V_277 :
error = F_248 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , false ) ;
break;
case V_279 | V_277 :
if ( ! F_249 ( V_274 ) || ! V_274 -> V_280 . V_281 )
return - V_126 ;
error = F_250 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , 0 ) ;
break;
case V_279 | V_277 | V_282 :
if ( ! F_249 ( V_274 ) )
return - V_126 ;
error = F_250 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , 0 ) ;
break;
default:
return - V_126 ;
}
if ( error )
return error ;
return F_251 ( V_22 ,
V_123 >> V_283 ,
V_124 >> V_283 ) ;
}
int F_252 ( struct V_4 * V_5 , unsigned V_267 , unsigned long V_268 )
{
int V_102 ;
T_11 V_284 = F_253 () ;
F_254 ( V_285 ) ;
V_102 = F_232 ( V_5 , 0 , V_267 , V_268 ) ;
F_254 ( V_284 ) ;
return V_102 ;
}
struct V_4 * F_223 ( const char * V_286 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_254 V_254 ;
int error ;
if ( ! V_286 || ! * V_286 )
return F_88 ( - V_28 ) ;
error = F_255 ( V_286 , V_287 , & V_254 ) ;
if ( error )
return F_88 ( error ) ;
V_2 = F_256 ( V_254 . V_162 ) ;
error = - V_288 ;
if ( ! F_257 ( V_2 -> V_190 ) )
goto V_289;
error = - V_255 ;
if ( ! F_258 ( & V_254 ) )
goto V_289;
error = - V_72 ;
V_5 = F_166 ( V_2 ) ;
if ( ! V_5 )
goto V_289;
V_105:
F_259 ( & V_254 ) ;
return V_5 ;
V_289:
V_5 = F_88 ( error ) ;
goto V_105;
}
int F_197 ( struct V_4 * V_5 , bool V_222 )
{
struct V_6 * V_7 = F_80 ( V_5 ) ;
int V_102 = 0 ;
if ( V_7 ) {
F_260 ( V_7 ) ;
V_102 = F_261 ( V_7 , V_222 ) ;
F_82 ( V_7 ) ;
}
F_15 ( V_5 ) ;
return V_102 ;
}
void F_262 ( void (* F_263)( struct V_4 * , void * ) , void * V_268 )
{
struct V_2 * V_2 , * V_290 = NULL ;
F_7 ( & V_181 -> V_291 ) ;
F_163 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_4 * V_5 ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 & ( V_292 | V_293 | V_185 ) ||
V_22 -> V_24 == 0 ) {
F_8 ( & V_2 -> V_16 ) ;
continue;
}
F_264 ( V_2 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_181 -> V_291 ) ;
F_165 ( V_290 ) ;
V_290 = V_2 ;
V_5 = F_3 ( V_2 ) ;
F_84 ( & V_5 -> V_157 ) ;
if ( V_5 -> V_242 )
F_263 ( V_5 , V_268 ) ;
F_85 ( & V_5 -> V_157 ) ;
F_7 ( & V_181 -> V_291 ) ;
}
F_8 ( & V_181 -> V_291 ) ;
F_165 ( V_290 ) ;
}
