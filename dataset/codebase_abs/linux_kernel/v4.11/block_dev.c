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
V_5 -> V_160 = & V_161 ;
F_136 ( & V_150 -> V_3 ) ;
F_133 ( & V_5 -> V_103 ) ;
}
static void F_137 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
F_138 ( & V_2 -> V_162 ) ;
F_139 ( V_2 ) ;
F_140 ( V_2 ) ;
F_7 ( & V_163 ) ;
F_141 ( & V_5 -> V_158 ) ;
F_8 ( & V_163 ) ;
if ( V_5 -> V_160 != & V_161 ) {
F_142 ( V_5 -> V_160 ) ;
V_5 -> V_160 = & V_161 ;
}
}
static struct V_164 * F_143 ( struct V_165 * V_166 ,
int V_115 , const char * V_167 , void * V_168 )
{
struct V_164 * V_169 ;
V_169 = F_144 ( V_166 , L_8 , & V_170 , NULL , V_171 ) ;
if ( ! F_145 ( V_169 ) )
V_169 -> V_172 -> V_173 |= V_174 ;
return V_169 ;
}
void T_6 F_146 ( void )
{
int V_146 ;
static struct V_175 * V_176 ;
V_151 = F_147 ( L_9 , sizeof( struct V_1 ) ,
0 , ( V_177 | V_178 |
V_179 | V_180 | V_181 ) ,
F_132 ) ;
V_146 = F_148 ( & V_182 ) ;
if ( V_146 )
F_149 ( L_10 ) ;
V_176 = F_150 ( & V_182 ) ;
if ( F_145 ( V_176 ) )
F_149 ( L_11 ) ;
V_183 = V_176 -> V_184 ;
}
static inline unsigned long F_151 ( T_7 V_185 )
{
return F_152 ( V_185 ) + F_153 ( V_185 ) ;
}
static int F_154 ( struct V_2 * V_2 , void * V_168 )
{
return F_1 ( V_2 ) -> V_5 . V_186 == * ( T_7 * ) V_168 ;
}
static int F_155 ( struct V_2 * V_2 , void * V_168 )
{
F_1 ( V_2 ) -> V_5 . V_186 = * ( T_7 * ) V_168 ;
return 0 ;
}
void F_156 ( T_7 V_185 )
{
struct V_2 * V_2 ;
V_2 = F_157 ( V_183 , F_151 ( V_185 ) , F_154 , & V_185 ) ;
if ( V_2 ) {
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
}
}
struct V_4 * F_160 ( T_7 V_185 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_161 ( V_183 , F_151 ( V_185 ) ,
F_154 , F_155 , & V_185 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_17 & V_187 ) {
V_5 -> V_188 = NULL ;
V_5 -> V_189 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_29 = F_162 ( V_2 ) ;
V_5 -> V_190 = 0 ;
V_5 -> V_191 = 0 ;
V_2 -> V_192 = V_193 ;
V_2 -> V_194 = V_185 ;
V_2 -> V_195 = V_5 ;
V_2 -> V_162 . V_196 = & V_197 ;
F_163 ( & V_2 -> V_162 , V_198 ) ;
F_7 ( & V_163 ) ;
F_164 ( & V_5 -> V_158 , & V_199 ) ;
F_8 ( & V_163 ) ;
F_165 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_166 ( struct V_4 * V_5 )
{
F_167 ( V_5 -> V_14 ) ;
return V_5 ;
}
long F_168 ( void )
{
struct V_4 * V_5 ;
long V_15 = 0 ;
F_7 ( & V_163 ) ;
F_169 (bdev, &all_bdevs, bd_list) {
V_15 += V_5 -> V_14 -> V_23 -> V_24 ;
}
F_8 ( & V_163 ) ;
return V_15 ;
}
void F_170 ( struct V_4 * V_5 )
{
F_159 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_171 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_163 ) ;
V_5 = V_2 -> V_195 ;
if ( V_5 && ! F_172 ( V_5 -> V_14 ) ) {
F_166 ( V_5 ) ;
F_8 ( & V_163 ) ;
return V_5 ;
}
F_8 ( & V_163 ) ;
if ( V_5 )
F_173 ( V_2 ) ;
V_5 = F_160 ( V_2 -> V_194 ) ;
if ( V_5 ) {
F_7 ( & V_163 ) ;
if ( ! V_2 -> V_195 ) {
F_166 ( V_5 ) ;
V_2 -> V_195 = V_5 ;
V_2 -> V_23 = V_5 -> V_14 -> V_23 ;
}
F_8 ( & V_163 ) ;
}
return V_5 ;
}
void F_173 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_163 ) ;
if ( ! F_174 ( V_2 -> V_200 ) )
V_5 = V_2 -> V_195 ;
V_2 -> V_195 = NULL ;
V_2 -> V_23 = & V_2 -> V_162 ;
F_8 ( & V_163 ) ;
if ( V_5 )
F_170 ( V_5 ) ;
}
static bool F_175 ( struct V_4 * V_5 , struct V_4 * V_201 ,
void * V_202 )
{
if ( V_5 -> V_203 == V_202 )
return true ;
else if ( V_5 -> V_203 != NULL )
return false ;
else if ( V_201 == V_5 )
return true ;
else if ( V_201 -> V_203 == F_175 )
return true ;
else if ( V_201 -> V_203 != NULL )
return false ;
else
return true ;
}
static int F_176 ( struct V_4 * V_5 ,
struct V_4 * V_201 , void * V_202 )
{
V_204:
if ( ! F_175 ( V_5 , V_201 , V_202 ) )
return - V_205 ;
if ( V_201 -> V_206 ) {
T_8 * V_207 = F_177 ( & V_201 -> V_206 , 0 ) ;
F_178 ( V_101 ) ;
F_179 ( V_207 , & V_101 , V_82 ) ;
F_8 ( & V_163 ) ;
F_180 () ;
F_181 ( V_207 , & V_101 ) ;
F_7 ( & V_163 ) ;
goto V_204;
}
return 0 ;
}
static struct V_4 * F_182 ( struct V_4 * V_5 ,
void * V_202 )
{
struct V_208 * V_209 ;
struct V_4 * V_201 ;
int V_210 , V_146 ;
F_118 () ;
V_209 = F_183 ( V_5 -> V_186 , & V_210 ) ;
if ( ! V_209 )
return F_88 ( - V_144 ) ;
if ( V_210 )
V_201 = F_184 ( V_209 , 0 ) ;
else
V_201 = F_166 ( V_5 ) ;
F_185 ( V_209 -> V_131 -> V_211 ) ;
F_186 ( V_209 ) ;
if ( ! V_201 )
return F_88 ( - V_72 ) ;
F_7 ( & V_163 ) ;
V_146 = F_176 ( V_5 , V_201 , V_202 ) ;
if ( V_146 == 0 ) {
V_201 -> V_206 = V_202 ;
F_8 ( & V_163 ) ;
return V_201 ;
} else {
F_8 ( & V_163 ) ;
F_170 ( V_201 ) ;
return F_88 ( V_146 ) ;
}
}
static struct V_212 * F_187 ( struct V_4 * V_5 ,
struct V_208 * V_209 )
{
struct V_212 * V_202 ;
F_169 (holder, &bdev->bd_holder_disks, list)
if ( V_202 -> V_209 == V_209 )
return V_202 ;
return NULL ;
}
static int F_188 ( struct V_213 * V_214 , struct V_213 * V_215 )
{
return F_189 ( V_214 , V_215 , F_190 ( V_215 ) ) ;
}
static void F_191 ( struct V_213 * V_214 , struct V_213 * V_215 )
{
F_192 ( V_214 , F_190 ( V_215 ) ) ;
}
int F_193 ( struct V_4 * V_5 , struct V_208 * V_209 )
{
struct V_212 * V_202 ;
int V_15 = 0 ;
F_84 ( & V_5 -> V_157 ) ;
F_194 ( ! V_5 -> V_203 ) ;
if ( F_195 ( ! V_209 -> V_216 || ! V_5 -> V_139 -> V_217 ) )
goto V_218;
V_202 = F_187 ( V_5 , V_209 ) ;
if ( V_202 ) {
V_202 -> V_219 ++ ;
goto V_218;
}
V_202 = F_196 ( sizeof( * V_202 ) , V_71 ) ;
if ( ! V_202 ) {
V_15 = - V_72 ;
goto V_218;
}
F_134 ( & V_202 -> V_220 ) ;
V_202 -> V_209 = V_209 ;
V_202 -> V_219 = 1 ;
V_15 = F_188 ( V_209 -> V_216 , & F_197 ( V_5 -> V_139 ) -> V_221 ) ;
if ( V_15 )
goto V_222;
V_15 = F_188 ( V_5 -> V_139 -> V_217 , & F_198 ( V_209 ) -> V_221 ) ;
if ( V_15 )
goto V_223;
F_199 ( V_5 -> V_139 -> V_217 ) ;
F_164 ( & V_202 -> V_220 , & V_5 -> V_159 ) ;
goto V_218;
V_223:
F_191 ( V_209 -> V_216 , & F_197 ( V_5 -> V_139 ) -> V_221 ) ;
V_222:
F_53 ( V_202 ) ;
V_218:
F_85 ( & V_5 -> V_157 ) ;
return V_15 ;
}
void F_200 ( struct V_4 * V_5 , struct V_208 * V_209 )
{
struct V_212 * V_202 ;
F_84 ( & V_5 -> V_157 ) ;
V_202 = F_187 ( V_5 , V_209 ) ;
if ( ! F_194 ( V_202 == NULL ) && ! -- V_202 -> V_219 ) {
F_191 ( V_209 -> V_216 , & F_197 ( V_5 -> V_139 ) -> V_221 ) ;
F_191 ( V_5 -> V_139 -> V_217 ,
& F_198 ( V_209 ) -> V_221 ) ;
F_201 ( V_5 -> V_139 -> V_217 ) ;
F_141 ( & V_202 -> V_220 ) ;
F_53 ( V_202 ) ;
}
F_85 ( & V_5 -> V_157 ) ;
}
static void F_202 ( struct V_4 * V_5 , bool V_224 )
{
if ( F_203 ( V_5 , V_224 ) ) {
F_204 ( V_225 L_12
L_13 ,
V_5 -> V_130 ? V_5 -> V_130 -> V_226 : L_14 ) ;
}
if ( ! V_5 -> V_130 )
return;
if ( F_205 ( V_5 -> V_130 ) )
V_5 -> V_191 = 1 ;
}
void F_206 ( struct V_208 * V_209 , struct V_4 * V_5 )
{
T_4 V_227 , V_228 ;
V_227 = ( T_4 ) F_207 ( V_209 ) << 9 ;
V_228 = F_104 ( V_5 -> V_14 ) ;
if ( V_227 != V_228 ) {
F_204 ( V_229
L_15 ,
V_209 -> V_226 , V_228 , V_227 ) ;
F_208 ( V_5 -> V_14 , V_227 ) ;
F_202 ( V_5 , false ) ;
}
}
int F_209 ( struct V_208 * V_209 )
{
struct V_4 * V_5 ;
int V_15 = 0 ;
if ( V_209 -> V_131 -> F_209 )
V_15 = V_209 -> V_131 -> F_209 ( V_209 ) ;
F_210 ( V_209 ) ;
V_5 = F_184 ( V_209 , 0 ) ;
if ( ! V_5 )
return V_15 ;
F_84 ( & V_5 -> V_157 ) ;
F_206 ( V_209 , V_5 ) ;
V_5 -> V_191 = 0 ;
F_85 ( & V_5 -> V_157 ) ;
F_170 ( V_5 ) ;
return V_15 ;
}
int F_211 ( struct V_4 * V_5 )
{
struct V_208 * V_209 = V_5 -> V_130 ;
const struct V_128 * V_230 = V_209 -> V_131 ;
unsigned int V_231 ;
V_231 = F_212 ( V_209 , V_232 |
V_233 ) ;
if ( ! ( V_231 & V_232 ) )
return 0 ;
F_202 ( V_5 , true ) ;
if ( V_230 -> F_209 )
V_230 -> F_209 ( V_5 -> V_130 ) ;
return 1 ;
}
void F_213 ( struct V_4 * V_5 , T_4 V_26 )
{
unsigned V_234 = F_21 ( V_5 ) ;
F_102 ( V_5 -> V_14 ) ;
F_208 ( V_5 -> V_14 , V_26 ) ;
F_105 ( V_5 -> V_14 ) ;
while ( V_234 < V_27 ) {
if ( V_26 & V_234 )
break;
V_234 <<= 1 ;
}
V_5 -> V_29 = V_234 ;
V_5 -> V_14 -> V_30 = F_23 ( V_234 ) ;
}
static int F_214 ( struct V_4 * V_5 , T_9 V_235 , int V_236 )
{
struct V_208 * V_209 ;
struct V_237 * V_211 ;
int V_15 ;
int V_210 ;
int V_238 = 0 ;
if ( V_235 & V_239 )
V_238 |= V_240 ;
if ( V_235 & V_241 )
V_238 |= V_242 ;
if ( ! V_236 ) {
V_15 = F_215 ( V_5 -> V_14 , V_238 ) ;
if ( V_15 != 0 ) {
F_170 ( V_5 ) ;
return V_15 ;
}
}
V_243:
V_15 = - V_144 ;
V_209 = F_183 ( V_5 -> V_186 , & V_210 ) ;
if ( ! V_209 )
goto V_105;
V_211 = V_209 -> V_131 -> V_211 ;
F_216 ( V_209 ) ;
F_217 ( & V_5 -> V_157 , V_236 ) ;
if ( ! V_5 -> V_244 ) {
V_5 -> V_130 = V_209 ;
V_5 -> V_134 = V_209 -> V_245 ;
V_5 -> V_188 = V_5 ;
if ( V_5 -> V_160 == & V_161 )
V_5 -> V_160 = F_218 ( V_209 -> V_245 -> V_246 ) ;
if ( ! V_210 ) {
V_15 = - V_144 ;
V_5 -> V_139 = F_219 ( V_209 , V_210 ) ;
if ( ! V_5 -> V_139 )
goto V_247;
V_15 = 0 ;
if ( V_209 -> V_131 -> V_248 ) {
V_15 = V_209 -> V_131 -> V_248 ( V_5 , V_235 ) ;
if ( V_15 == - V_249 ) {
F_220 ( V_5 -> V_139 ) ;
V_5 -> V_139 = NULL ;
V_5 -> V_130 = NULL ;
V_5 -> V_134 = NULL ;
F_85 ( & V_5 -> V_157 ) ;
F_221 ( V_209 ) ;
F_186 ( V_209 ) ;
F_185 ( V_211 ) ;
goto V_243;
}
}
if ( ! V_15 )
F_213 ( V_5 , ( T_4 ) F_207 ( V_209 ) << 9 ) ;
if ( V_5 -> V_191 ) {
if ( ! V_15 )
F_222 ( V_209 , V_5 ) ;
else if ( V_15 == - V_250 )
F_223 ( V_209 , V_5 ) ;
}
if ( V_15 )
goto V_247;
} else {
struct V_4 * V_201 ;
V_201 = F_184 ( V_209 , 0 ) ;
V_15 = - V_72 ;
if ( ! V_201 )
goto V_247;
F_224 ( V_236 ) ;
V_15 = F_214 ( V_201 , V_235 , 1 ) ;
if ( V_15 )
goto V_247;
V_5 -> V_188 = V_201 ;
V_5 -> V_139 = F_219 ( V_209 , V_210 ) ;
if ( ! ( V_209 -> V_115 & V_251 ) ||
! V_5 -> V_139 || ! V_5 -> V_139 -> V_149 ) {
V_15 = - V_144 ;
goto V_247;
}
F_213 ( V_5 , ( T_4 ) V_5 -> V_139 -> V_149 << 9 ) ;
}
} else {
if ( V_5 -> V_188 == V_5 ) {
V_15 = 0 ;
if ( V_5 -> V_130 -> V_131 -> V_248 )
V_15 = V_5 -> V_130 -> V_131 -> V_248 ( V_5 , V_235 ) ;
if ( V_5 -> V_191 ) {
if ( ! V_15 )
F_222 ( V_5 -> V_130 , V_5 ) ;
else if ( V_15 == - V_250 )
F_223 ( V_5 -> V_130 , V_5 ) ;
}
if ( V_15 )
goto V_252;
}
F_186 ( V_209 ) ;
F_185 ( V_211 ) ;
}
V_5 -> V_244 ++ ;
if ( V_236 )
V_5 -> V_190 ++ ;
F_85 ( & V_5 -> V_157 ) ;
F_221 ( V_209 ) ;
return 0 ;
V_247:
F_220 ( V_5 -> V_139 ) ;
V_5 -> V_130 = NULL ;
V_5 -> V_139 = NULL ;
V_5 -> V_134 = NULL ;
F_142 ( V_5 -> V_160 ) ;
V_5 -> V_160 = & V_161 ;
if ( V_5 != V_5 -> V_188 )
F_225 ( V_5 -> V_188 , V_235 , 1 ) ;
V_5 -> V_188 = NULL ;
V_252:
F_85 ( & V_5 -> V_157 ) ;
F_221 ( V_209 ) ;
F_186 ( V_209 ) ;
F_185 ( V_211 ) ;
V_105:
F_170 ( V_5 ) ;
return V_15 ;
}
int F_226 ( struct V_4 * V_5 , T_9 V_235 , void * V_202 )
{
struct V_4 * V_201 = NULL ;
int V_102 ;
F_194 ( ( V_235 & V_253 ) && ! V_202 ) ;
if ( ( V_235 & V_253 ) && V_202 ) {
V_201 = F_182 ( V_5 , V_202 ) ;
if ( F_145 ( V_201 ) ) {
F_170 ( V_5 ) ;
return F_227 ( V_201 ) ;
}
}
V_102 = F_214 ( V_5 , V_235 , 0 ) ;
if ( V_201 ) {
struct V_208 * V_209 = V_201 -> V_130 ;
F_84 ( & V_5 -> V_157 ) ;
F_7 ( & V_163 ) ;
if ( ! V_102 ) {
F_224 ( ! F_175 ( V_5 , V_201 , V_202 ) ) ;
V_201 -> V_254 ++ ;
V_201 -> V_203 = F_175 ;
V_5 -> V_254 ++ ;
V_5 -> V_203 = V_202 ;
}
F_224 ( V_201 -> V_206 != V_202 ) ;
V_201 -> V_206 = NULL ;
F_228 ( & V_201 -> V_206 , 0 ) ;
F_8 ( & V_163 ) ;
if ( ! V_102 && ( V_235 & V_241 ) && ! V_5 -> V_255 &&
( V_209 -> V_115 & V_256 ) ) {
V_5 -> V_255 = true ;
F_216 ( V_209 ) ;
}
F_85 ( & V_5 -> V_157 ) ;
F_170 ( V_201 ) ;
}
return V_102 ;
}
struct V_4 * F_229 ( const char * V_257 , T_9 V_235 ,
void * V_202 )
{
struct V_4 * V_5 ;
int V_146 ;
V_5 = F_230 ( V_257 ) ;
if ( F_145 ( V_5 ) )
return V_5 ;
V_146 = F_226 ( V_5 , V_235 , V_202 ) ;
if ( V_146 )
return F_88 ( V_146 ) ;
if ( ( V_235 & V_241 ) && F_231 ( V_5 ) ) {
F_232 ( V_5 , V_235 ) ;
return F_88 ( - V_258 ) ;
}
return V_5 ;
}
struct V_4 * F_233 ( T_7 V_185 , T_9 V_235 , void * V_202 )
{
struct V_4 * V_5 ;
int V_146 ;
V_5 = F_160 ( V_185 ) ;
if ( ! V_5 )
return F_88 ( - V_72 ) ;
V_146 = F_226 ( V_5 , V_235 , V_202 ) ;
if ( V_146 )
return F_88 ( V_146 ) ;
return V_5 ;
}
static int F_234 ( struct V_2 * V_2 , struct V_41 * V_122 )
{
struct V_4 * V_5 ;
V_122 -> V_259 |= V_260 ;
if ( V_122 -> V_259 & V_261 )
V_122 -> V_262 |= V_263 ;
if ( V_122 -> V_259 & V_264 )
V_122 -> V_262 |= V_253 ;
if ( ( V_122 -> V_259 & V_265 ) == 3 )
V_122 -> V_262 |= V_266 ;
V_5 = F_171 ( V_2 ) ;
if ( V_5 == NULL )
return - V_72 ;
V_122 -> V_42 = V_5 -> V_14 -> V_23 ;
return F_226 ( V_5 , V_122 -> V_262 , V_122 ) ;
}
static void F_225 ( struct V_4 * V_5 , T_9 V_235 , int V_236 )
{
struct V_208 * V_209 = V_5 -> V_130 ;
struct V_4 * V_267 = NULL ;
F_217 ( & V_5 -> V_157 , V_236 ) ;
if ( V_236 )
V_5 -> V_190 -- ;
if ( ! -- V_5 -> V_244 ) {
F_194 ( V_5 -> V_254 ) ;
F_22 ( V_5 ) ;
F_12 ( V_5 ) ;
F_6 ( V_5 ) ;
F_235 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_188 == V_5 ) {
if ( V_209 -> V_131 -> V_268 )
V_209 -> V_131 -> V_268 ( V_209 , V_235 ) ;
}
if ( ! V_5 -> V_244 ) {
struct V_237 * V_211 = V_209 -> V_131 -> V_211 ;
F_220 ( V_5 -> V_139 ) ;
V_5 -> V_139 = NULL ;
V_5 -> V_130 = NULL ;
if ( V_5 != V_5 -> V_188 )
V_267 = V_5 -> V_188 ;
V_5 -> V_188 = NULL ;
F_186 ( V_209 ) ;
F_185 ( V_211 ) ;
}
F_85 ( & V_5 -> V_157 ) ;
F_170 ( V_5 ) ;
if ( V_267 )
F_225 ( V_267 , V_235 , 1 ) ;
}
void F_232 ( struct V_4 * V_5 , T_9 V_235 )
{
F_84 ( & V_5 -> V_157 ) ;
if ( V_235 & V_253 ) {
bool V_269 ;
F_7 ( & V_163 ) ;
F_194 ( -- V_5 -> V_254 < 0 ) ;
F_194 ( -- V_5 -> V_188 -> V_254 < 0 ) ;
if ( ( V_269 = ! V_5 -> V_254 ) )
V_5 -> V_203 = NULL ;
if ( ! V_5 -> V_188 -> V_254 )
V_5 -> V_188 -> V_203 = NULL ;
F_8 ( & V_163 ) ;
if ( V_269 && V_5 -> V_255 ) {
F_221 ( V_5 -> V_130 ) ;
V_5 -> V_255 = false ;
}
}
F_236 ( V_5 -> V_130 , V_232 ) ;
F_85 ( & V_5 -> V_157 ) ;
F_225 ( V_5 , V_235 , 0 ) ;
}
static int F_237 ( struct V_2 * V_2 , struct V_41 * V_122 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_122 ) ) ;
F_232 ( V_5 , V_122 -> V_262 ) ;
return 0 ;
}
static long F_238 ( struct V_41 * V_41 , unsigned V_270 , unsigned long V_271 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
T_9 V_235 = V_41 -> V_262 ;
if ( V_41 -> V_259 & V_261 )
V_235 |= V_263 ;
else
V_235 &= ~ V_263 ;
return F_239 ( V_5 , V_235 , V_270 , V_271 ) ;
}
T_3 F_240 ( struct V_44 * V_45 , struct V_57 * V_214 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_104 ( V_14 ) ;
struct V_93 V_94 ;
T_3 V_15 ;
if ( F_231 ( F_3 ( V_14 ) ) )
return - V_272 ;
if ( ! F_241 ( V_214 ) )
return 0 ;
if ( V_45 -> V_67 >= V_26 )
return - V_273 ;
F_242 ( V_214 , V_26 - V_45 -> V_67 ) ;
F_63 ( & V_94 ) ;
V_15 = F_243 ( V_45 , V_214 ) ;
if ( V_15 > 0 )
V_15 = F_244 ( V_45 , V_15 ) ;
F_70 ( & V_94 ) ;
return V_15 ;
}
T_3 F_245 ( struct V_44 * V_45 , struct V_57 * V_215 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_104 ( V_14 ) ;
T_4 V_66 = V_45 -> V_67 ;
if ( V_66 >= V_26 )
return 0 ;
V_26 -= V_66 ;
F_242 ( V_215 , V_26 ) ;
return F_246 ( V_45 , V_215 ) ;
}
static int F_247 ( struct V_109 * V_109 , T_10 V_101 )
{
struct V_6 * V_274 = F_1 ( V_109 -> V_22 -> V_43 ) -> V_5 . V_189 ;
if ( V_274 && V_274 -> V_106 -> V_275 )
return V_274 -> V_106 -> V_275 ( V_274 , V_109 , V_101 ) ;
return F_248 ( V_109 ) ;
}
static int F_249 ( struct V_21 * V_22 ,
struct V_110 * V_111 )
{
if ( F_250 ( V_22 ) ) {
struct V_4 * V_5 = F_3 ( V_22 -> V_43 ) ;
return F_251 ( V_22 , V_5 , V_111 ) ;
}
return F_252 ( V_22 , V_111 ) ;
}
static long F_253 ( struct V_41 * V_41 , int V_235 , T_4 V_123 ,
T_4 V_114 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
struct V_276 * V_277 = F_46 ( V_5 ) ;
struct V_21 * V_22 ;
T_4 V_124 = V_123 + V_114 - 1 ;
T_4 V_278 ;
int error ;
if ( V_235 & ~ V_279 )
return - V_126 ;
V_278 = F_104 ( V_5 -> V_14 ) ;
if ( V_123 >= V_278 )
return - V_28 ;
if ( V_124 >= V_278 ) {
if ( V_235 & V_280 ) {
V_114 = V_278 - V_123 ;
V_124 = V_123 + V_114 - 1 ;
} else
return - V_28 ;
}
if ( ( V_123 | V_114 ) & ( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
V_22 = V_5 -> V_14 -> V_23 ;
F_254 ( V_22 , V_123 , V_124 ) ;
switch ( V_235 ) {
case V_281 :
case V_281 | V_280 :
error = F_255 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , false ) ;
break;
case V_282 | V_280 :
if ( ! F_256 ( V_277 ) || ! V_277 -> V_283 . V_284 )
return - V_126 ;
error = F_257 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , 0 ) ;
break;
case V_282 | V_280 | V_285 :
if ( ! F_256 ( V_277 ) )
return - V_126 ;
error = F_257 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , 0 ) ;
break;
default:
return - V_126 ;
}
if ( error )
return error ;
return F_258 ( V_22 ,
V_123 >> V_286 ,
V_124 >> V_286 ) ;
}
int F_259 ( struct V_4 * V_5 , unsigned V_270 , unsigned long V_271 )
{
int V_102 ;
T_11 V_287 = F_260 () ;
F_261 ( V_288 ) ;
V_102 = F_239 ( V_5 , 0 , V_270 , V_271 ) ;
F_261 ( V_287 ) ;
return V_102 ;
}
struct V_4 * F_230 ( const char * V_289 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_257 V_257 ;
int error ;
if ( ! V_289 || ! * V_289 )
return F_88 ( - V_28 ) ;
error = F_262 ( V_289 , V_290 , & V_257 ) ;
if ( error )
return F_88 ( error ) ;
V_2 = F_263 ( V_257 . V_164 ) ;
error = - V_291 ;
if ( ! F_264 ( V_2 -> V_192 ) )
goto V_292;
error = - V_258 ;
if ( ! F_265 ( & V_257 ) )
goto V_292;
error = - V_72 ;
V_5 = F_171 ( V_2 ) ;
if ( ! V_5 )
goto V_292;
V_105:
F_266 ( & V_257 ) ;
return V_5 ;
V_292:
V_5 = F_88 ( error ) ;
goto V_105;
}
int F_203 ( struct V_4 * V_5 , bool V_224 )
{
struct V_6 * V_7 = F_80 ( V_5 ) ;
int V_102 = 0 ;
if ( V_7 ) {
F_267 ( V_7 ) ;
V_102 = F_268 ( V_7 , V_224 ) ;
F_82 ( V_7 ) ;
}
F_15 ( V_5 ) ;
return V_102 ;
}
void F_269 ( void (* F_270)( struct V_4 * , void * ) , void * V_271 )
{
struct V_2 * V_2 , * V_293 = NULL ;
F_7 ( & V_183 -> V_294 ) ;
F_169 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_4 * V_5 ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 & ( V_295 | V_296 | V_187 ) ||
V_22 -> V_24 == 0 ) {
F_8 ( & V_2 -> V_16 ) ;
continue;
}
F_271 ( V_2 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_183 -> V_294 ) ;
F_159 ( V_293 ) ;
V_293 = V_2 ;
V_5 = F_3 ( V_2 ) ;
F_84 ( & V_5 -> V_157 ) ;
if ( V_5 -> V_244 )
F_270 ( V_5 , V_271 ) ;
F_85 ( & V_5 -> V_157 ) ;
F_7 ( & V_183 -> V_294 ) ;
}
F_8 ( & V_183 -> V_294 ) ;
F_159 ( V_293 ) ;
}
