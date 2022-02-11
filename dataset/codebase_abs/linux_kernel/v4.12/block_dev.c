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
if ( V_22 -> V_24 ) {
F_13 () ;
F_16 () ;
F_17 ( V_22 , 0 , - 1 ) ;
}
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
V_15 = V_53 . V_86 ;
F_54 ( & V_53 ) ;
return V_15 ;
}
static void F_55 ( struct V_53 * V_53 )
{
struct V_87 * V_88 = V_53 -> V_56 ;
bool V_68 = V_88 -> V_68 ;
if ( V_88 -> V_89 && ! F_56 ( & V_88 -> V_90 ) ) {
if ( V_53 -> V_86 && ! V_88 -> V_53 . V_86 )
V_88 -> V_53 . V_86 = V_53 -> V_86 ;
} else {
if ( ! V_88 -> V_91 ) {
struct V_44 * V_45 = V_88 -> V_45 ;
T_3 V_15 = V_88 -> V_53 . V_86 ;
if ( F_57 ( ! V_15 ) ) {
V_15 = V_88 -> V_26 ;
V_45 -> V_67 += V_15 ;
}
V_88 -> V_45 -> V_92 ( V_45 , V_15 , 0 ) ;
F_58 ( & V_88 -> V_53 ) ;
} else {
struct V_54 * V_55 = V_88 -> V_55 ;
F_31 ( V_88 -> V_55 , NULL ) ;
F_32 ( V_55 ) ;
}
}
if ( V_68 ) {
F_59 ( V_53 ) ;
} else {
struct V_61 * V_65 ;
int V_70 ;
F_49 (bvec, bio, i)
F_52 ( V_65 -> V_85 ) ;
F_58 ( V_53 ) ;
}
}
static T_3
F_60 ( struct V_44 * V_45 , struct V_57 * V_58 , int V_59 )
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
V_53 = F_61 ( V_71 , V_59 , V_97 ) ;
F_62 ( V_53 ) ;
V_88 = F_2 ( V_53 , struct V_87 , V_53 ) ;
V_88 -> V_91 = V_91 = F_63 ( V_45 ) ;
if ( V_88 -> V_91 )
V_88 -> V_55 = V_76 ;
else
V_88 -> V_45 = V_45 ;
V_88 -> V_26 = 0 ;
V_88 -> V_89 = false ;
V_88 -> V_68 = V_95 && ( V_58 -> type == V_98 ) ;
F_64 ( & V_94 ) ;
for (; ; ) {
V_53 -> V_73 = V_5 ;
V_53 -> V_74 . V_75 = V_66 >> 9 ;
V_53 -> V_56 = V_88 ;
V_53 -> V_77 = F_55 ;
V_15 = F_37 ( V_53 , V_58 ) ;
if ( F_38 ( V_15 ) ) {
V_53 -> V_86 = V_15 ;
F_65 ( V_53 ) ;
break;
}
if ( V_95 ) {
V_53 -> V_80 = V_81 ;
if ( V_88 -> V_68 )
F_66 ( V_53 ) ;
} else {
V_53 -> V_80 = F_29 ( V_45 ) ;
F_41 ( V_53 -> V_74 . V_78 ) ;
}
V_88 -> V_26 += V_53 -> V_74 . V_78 ;
V_66 += V_53 -> V_74 . V_78 ;
V_59 = F_67 ( V_58 , V_99 ) ;
if ( ! V_59 ) {
V_69 = F_42 ( V_53 ) ;
break;
}
if ( ! V_88 -> V_89 ) {
V_88 -> V_89 = true ;
F_68 ( & V_88 -> V_90 , 2 ) ;
} else {
F_69 ( & V_88 -> V_90 ) ;
}
F_42 ( V_53 ) ;
V_53 = F_70 ( V_71 , V_59 ) ;
}
F_71 ( & V_94 ) ;
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
if ( F_57 ( ! V_15 ) )
V_15 = V_88 -> V_26 ;
F_58 ( & V_88 -> V_53 ) ;
return V_15 ;
}
static T_3
F_72 ( struct V_44 * V_45 , struct V_57 * V_58 )
{
int V_59 ;
V_59 = F_67 ( V_58 , V_99 + 1 ) ;
if ( ! V_59 )
return 0 ;
if ( F_63 ( V_45 ) && V_59 <= V_99 )
return F_33 ( V_45 , V_58 , V_59 ) ;
return F_60 ( V_45 , V_58 , F_73 ( V_59 , V_99 ) ) ;
}
static T_6 int F_74 ( void )
{
V_97 = F_75 ( 4 , F_76 ( struct V_87 , V_53 ) ) ;
if ( ! V_97 )
return - V_72 ;
return 0 ;
}
int F_77 ( struct V_4 * V_5 , int V_101 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_101 )
return F_78 ( V_5 -> V_14 -> V_23 ) ;
return F_79 ( V_5 -> V_14 -> V_23 ) ;
}
int F_22 ( struct V_4 * V_5 )
{
return F_77 ( V_5 , 1 ) ;
}
int F_80 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_81 ( V_5 ) ;
if ( V_7 ) {
int V_102 = F_82 ( V_7 ) ;
F_83 ( V_7 ) ;
return V_102 ;
}
return F_22 ( V_5 ) ;
}
struct V_6 * F_84 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_85 ( & V_5 -> V_103 ) ;
if ( ++ V_5 -> V_104 > 1 ) {
V_7 = F_81 ( V_5 ) ;
if ( V_7 )
F_83 ( V_7 ) ;
F_86 ( & V_5 -> V_103 ) ;
return V_7 ;
}
V_7 = F_87 ( V_5 ) ;
if ( ! V_7 )
goto V_105;
if ( V_7 -> V_106 -> V_107 )
error = V_7 -> V_106 -> V_107 ( V_7 ) ;
else
error = V_107 ( V_7 ) ;
if ( error ) {
F_88 ( V_7 ) ;
V_5 -> V_104 -- ;
F_86 ( & V_5 -> V_103 ) ;
return F_89 ( error ) ;
}
F_88 ( V_7 ) ;
V_105:
F_22 ( V_5 ) ;
F_86 ( & V_5 -> V_103 ) ;
return V_7 ;
}
int F_90 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
int error = - V_28 ;
F_85 ( & V_5 -> V_103 ) ;
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
F_86 ( & V_5 -> V_103 ) ;
return error ;
}
static int F_91 ( struct V_109 * V_109 , struct V_110 * V_111 )
{
return F_92 ( V_109 , F_26 , V_111 ) ;
}
static int F_93 ( struct V_41 * V_41 , struct V_109 * V_109 )
{
return F_94 ( V_109 , F_26 ) ;
}
static int F_95 ( struct V_41 * V_41 , struct V_21 * V_22 ,
struct V_112 * V_113 , unsigned V_59 )
{
return F_96 ( V_22 , V_113 , V_59 , F_26 ) ;
}
static int F_97 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_66 , unsigned V_114 , unsigned V_115 ,
struct V_109 * * V_116 , void * * V_117 )
{
return F_98 ( V_22 , V_66 , V_114 , V_115 , V_116 ,
F_26 ) ;
}
static int F_99 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_66 , unsigned V_114 , unsigned V_118 ,
struct V_109 * V_109 , void * V_117 )
{
int V_15 ;
V_15 = F_100 ( V_41 , V_22 , V_66 , V_114 , V_118 , V_109 , V_117 ) ;
F_101 ( V_109 ) ;
F_52 ( V_109 ) ;
return V_15 ;
}
static T_4 F_102 ( struct V_41 * V_41 , T_4 V_119 , int V_120 )
{
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_121 ;
F_103 ( V_14 ) ;
V_121 = F_104 ( V_41 , V_119 , V_120 , F_105 ( V_14 ) ) ;
F_106 ( V_14 ) ;
return V_121 ;
}
int F_107 ( struct V_41 * V_122 , T_4 V_123 , T_4 V_124 , int V_125 )
{
struct V_2 * V_14 = F_28 ( V_122 ) ;
struct V_4 * V_5 = F_3 ( V_14 ) ;
int error ;
error = F_108 ( V_122 -> V_42 , V_123 , V_124 ) ;
if ( error )
return error ;
error = F_109 ( V_5 , V_71 , NULL ) ;
if ( error == - V_126 )
error = 0 ;
return error ;
}
int F_110 ( struct V_4 * V_5 , T_2 V_127 ,
struct V_109 * V_109 )
{
const struct V_128 * V_129 = V_5 -> V_130 -> V_131 ;
int V_132 = - V_126 ;
if ( ! V_129 -> V_133 || F_111 ( V_5 ) )
return V_132 ;
V_132 = F_112 ( V_5 -> V_134 , false ) ;
if ( V_132 )
return V_132 ;
V_132 = V_129 -> V_133 ( V_5 , V_127 + F_113 ( V_5 ) , V_109 , false ) ;
F_114 ( V_5 -> V_134 ) ;
return V_132 ;
}
int F_115 ( struct V_4 * V_5 , T_2 V_127 ,
struct V_109 * V_109 , struct V_110 * V_111 )
{
int V_132 ;
const struct V_128 * V_129 = V_5 -> V_130 -> V_131 ;
if ( ! V_129 -> V_133 || F_111 ( V_5 ) )
return - V_126 ;
V_132 = F_112 ( V_5 -> V_134 , false ) ;
if ( V_132 )
return V_132 ;
F_116 ( V_109 ) ;
V_132 = V_129 -> V_133 ( V_5 , V_127 + F_113 ( V_5 ) , V_109 , true ) ;
if ( V_132 )
F_117 ( V_109 ) ;
else
F_101 ( V_109 ) ;
F_114 ( V_5 -> V_134 ) ;
return V_132 ;
}
static struct V_2 * F_118 ( struct V_6 * V_7 )
{
struct V_1 * V_135 = F_119 ( V_136 , V_71 ) ;
if ( ! V_135 )
return NULL ;
return & V_135 -> V_3 ;
}
static void F_120 ( struct V_137 * V_138 )
{
struct V_2 * V_2 = F_2 ( V_138 , struct V_2 , V_139 ) ;
struct V_1 * V_140 = F_1 ( V_2 ) ;
F_121 ( V_136 , V_140 ) ;
}
static void F_122 ( struct V_2 * V_2 )
{
F_123 ( & V_2 -> V_139 , F_120 ) ;
}
static void F_124 ( void * V_141 )
{
struct V_1 * V_135 = (struct V_1 * ) V_141 ;
struct V_4 * V_5 = & V_135 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_125 ( & V_5 -> V_142 ) ;
F_126 ( & V_5 -> V_143 ) ;
#ifdef F_127
F_126 ( & V_5 -> V_144 ) ;
#endif
V_5 -> V_145 = & V_146 ;
F_128 ( & V_135 -> V_3 ) ;
F_125 ( & V_5 -> V_103 ) ;
}
static void F_129 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
F_130 ( & V_2 -> V_147 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_7 ( & V_148 ) ;
F_133 ( & V_5 -> V_143 ) ;
F_8 ( & V_148 ) ;
F_134 ( V_2 ) ;
if ( V_5 -> V_145 != & V_146 ) {
F_135 ( V_5 -> V_145 ) ;
V_5 -> V_145 = & V_146 ;
}
}
static struct V_149 * F_136 ( struct V_150 * V_151 ,
int V_115 , const char * V_152 , void * V_153 )
{
struct V_149 * V_154 ;
V_154 = F_137 ( V_151 , L_4 , & V_155 , NULL , V_156 ) ;
if ( ! F_138 ( V_154 ) )
V_154 -> V_157 -> V_158 |= V_159 ;
return V_154 ;
}
void T_6 F_139 ( void )
{
int V_160 ;
static struct V_161 * V_162 ;
V_136 = F_140 ( L_5 , sizeof( struct V_1 ) ,
0 , ( V_163 | V_164 |
V_165 | V_166 | V_167 ) ,
F_124 ) ;
V_160 = F_141 ( & V_168 ) ;
if ( V_160 )
F_142 ( L_6 ) ;
V_162 = F_143 ( & V_168 ) ;
if ( F_138 ( V_162 ) )
F_142 ( L_7 ) ;
V_169 = V_162 -> V_170 ;
}
static inline unsigned long F_144 ( T_7 V_171 )
{
return F_145 ( V_171 ) + F_146 ( V_171 ) ;
}
static int F_147 ( struct V_2 * V_2 , void * V_153 )
{
return F_1 ( V_2 ) -> V_5 . V_172 == * ( T_7 * ) V_153 ;
}
static int F_148 ( struct V_2 * V_2 , void * V_153 )
{
F_1 ( V_2 ) -> V_5 . V_172 = * ( T_7 * ) V_153 ;
return 0 ;
}
void F_149 ( T_7 V_171 )
{
struct V_2 * V_2 ;
V_2 = F_150 ( V_169 , F_144 ( V_171 ) , F_147 , & V_171 ) ;
if ( V_2 ) {
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
}
}
struct V_4 * F_153 ( T_7 V_171 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_154 ( V_169 , F_144 ( V_171 ) ,
F_147 , F_148 , & V_171 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_17 & V_173 ) {
V_5 -> V_174 = NULL ;
V_5 -> V_175 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_29 = F_155 ( V_2 ) ;
V_5 -> V_176 = 0 ;
V_5 -> V_177 = 0 ;
V_2 -> V_178 = V_179 ;
V_2 -> V_180 = V_171 ;
V_2 -> V_181 = V_5 ;
V_2 -> V_147 . V_182 = & V_183 ;
F_156 ( & V_2 -> V_147 , V_184 ) ;
F_7 ( & V_148 ) ;
F_157 ( & V_5 -> V_143 , & V_185 ) ;
F_8 ( & V_148 ) ;
F_158 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_159 ( struct V_4 * V_5 )
{
F_160 ( V_5 -> V_14 ) ;
return V_5 ;
}
long F_161 ( void )
{
struct V_4 * V_5 ;
long V_15 = 0 ;
F_7 ( & V_148 ) ;
F_162 (bdev, &all_bdevs, bd_list) {
V_15 += V_5 -> V_14 -> V_23 -> V_24 ;
}
F_8 ( & V_148 ) ;
return V_15 ;
}
void F_163 ( struct V_4 * V_5 )
{
F_152 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_164 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_148 ) ;
V_5 = V_2 -> V_181 ;
if ( V_5 && ! F_165 ( V_5 -> V_14 ) ) {
F_159 ( V_5 ) ;
F_8 ( & V_148 ) ;
return V_5 ;
}
F_8 ( & V_148 ) ;
if ( V_5 )
F_166 ( V_2 ) ;
V_5 = F_153 ( V_2 -> V_180 ) ;
if ( V_5 ) {
F_7 ( & V_148 ) ;
if ( ! V_2 -> V_181 ) {
F_159 ( V_5 ) ;
V_2 -> V_181 = V_5 ;
V_2 -> V_23 = V_5 -> V_14 -> V_23 ;
}
F_8 ( & V_148 ) ;
}
return V_5 ;
}
void F_166 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_148 ) ;
if ( ! F_167 ( V_2 -> V_186 ) )
V_5 = V_2 -> V_181 ;
V_2 -> V_181 = NULL ;
V_2 -> V_23 = & V_2 -> V_147 ;
F_8 ( & V_148 ) ;
if ( V_5 )
F_163 ( V_5 ) ;
}
static bool F_168 ( struct V_4 * V_5 , struct V_4 * V_187 ,
void * V_188 )
{
if ( V_5 -> V_189 == V_188 )
return true ;
else if ( V_5 -> V_189 != NULL )
return false ;
else if ( V_187 == V_5 )
return true ;
else if ( V_187 -> V_189 == F_168 )
return true ;
else if ( V_187 -> V_189 != NULL )
return false ;
else
return true ;
}
static int F_169 ( struct V_4 * V_5 ,
struct V_4 * V_187 , void * V_188 )
{
V_190:
if ( ! F_168 ( V_5 , V_187 , V_188 ) )
return - V_191 ;
if ( V_187 -> V_192 ) {
T_8 * V_193 = F_170 ( & V_187 -> V_192 , 0 ) ;
F_171 ( V_101 ) ;
F_172 ( V_193 , & V_101 , V_82 ) ;
F_8 ( & V_148 ) ;
F_173 () ;
F_174 ( V_193 , & V_101 ) ;
F_7 ( & V_148 ) ;
goto V_190;
}
return 0 ;
}
static struct V_4 * F_175 ( struct V_4 * V_5 ,
void * V_188 )
{
struct V_194 * V_195 ;
struct V_4 * V_187 ;
int V_196 , V_160 ;
F_176 () ;
V_195 = F_177 ( V_5 -> V_172 , & V_196 ) ;
if ( ! V_195 )
return F_89 ( - V_197 ) ;
if ( V_196 )
V_187 = F_178 ( V_195 , 0 ) ;
else
V_187 = F_159 ( V_5 ) ;
F_179 ( V_195 -> V_131 -> V_198 ) ;
F_180 ( V_195 ) ;
if ( ! V_187 )
return F_89 ( - V_72 ) ;
F_7 ( & V_148 ) ;
V_160 = F_169 ( V_5 , V_187 , V_188 ) ;
if ( V_160 == 0 ) {
V_187 -> V_192 = V_188 ;
F_8 ( & V_148 ) ;
return V_187 ;
} else {
F_8 ( & V_148 ) ;
F_163 ( V_187 ) ;
return F_89 ( V_160 ) ;
}
}
static struct V_199 * F_181 ( struct V_4 * V_5 ,
struct V_194 * V_195 )
{
struct V_199 * V_188 ;
F_162 (holder, &bdev->bd_holder_disks, list)
if ( V_188 -> V_195 == V_195 )
return V_188 ;
return NULL ;
}
static int F_182 ( struct V_200 * V_201 , struct V_200 * V_202 )
{
return F_183 ( V_201 , V_202 , F_184 ( V_202 ) ) ;
}
static void F_185 ( struct V_200 * V_201 , struct V_200 * V_202 )
{
F_186 ( V_201 , F_184 ( V_202 ) ) ;
}
int F_187 ( struct V_4 * V_5 , struct V_194 * V_195 )
{
struct V_199 * V_188 ;
int V_15 = 0 ;
F_85 ( & V_5 -> V_142 ) ;
F_188 ( ! V_5 -> V_189 ) ;
if ( F_189 ( ! V_195 -> V_203 || ! V_5 -> V_204 -> V_205 ) )
goto V_206;
V_188 = F_181 ( V_5 , V_195 ) ;
if ( V_188 ) {
V_188 -> V_207 ++ ;
goto V_206;
}
V_188 = F_190 ( sizeof( * V_188 ) , V_71 ) ;
if ( ! V_188 ) {
V_15 = - V_72 ;
goto V_206;
}
F_126 ( & V_188 -> V_208 ) ;
V_188 -> V_195 = V_195 ;
V_188 -> V_207 = 1 ;
V_15 = F_182 ( V_195 -> V_203 , & F_191 ( V_5 -> V_204 ) -> V_209 ) ;
if ( V_15 )
goto V_210;
V_15 = F_182 ( V_5 -> V_204 -> V_205 , & F_192 ( V_195 ) -> V_209 ) ;
if ( V_15 )
goto V_211;
F_193 ( V_5 -> V_204 -> V_205 ) ;
F_157 ( & V_188 -> V_208 , & V_5 -> V_144 ) ;
goto V_206;
V_211:
F_185 ( V_195 -> V_203 , & F_191 ( V_5 -> V_204 ) -> V_209 ) ;
V_210:
F_53 ( V_188 ) ;
V_206:
F_86 ( & V_5 -> V_142 ) ;
return V_15 ;
}
void F_194 ( struct V_4 * V_5 , struct V_194 * V_195 )
{
struct V_199 * V_188 ;
F_85 ( & V_5 -> V_142 ) ;
V_188 = F_181 ( V_5 , V_195 ) ;
if ( ! F_188 ( V_188 == NULL ) && ! -- V_188 -> V_207 ) {
F_185 ( V_195 -> V_203 , & F_191 ( V_5 -> V_204 ) -> V_209 ) ;
F_185 ( V_5 -> V_204 -> V_205 ,
& F_192 ( V_195 ) -> V_209 ) ;
F_195 ( V_5 -> V_204 -> V_205 ) ;
F_133 ( & V_188 -> V_208 ) ;
F_53 ( V_188 ) ;
}
F_86 ( & V_5 -> V_142 ) ;
}
static void F_196 ( struct V_4 * V_5 , bool V_212 )
{
if ( F_197 ( V_5 , V_212 ) ) {
F_198 ( V_213 L_8
L_9 ,
V_5 -> V_130 ? V_5 -> V_130 -> V_214 : L_10 ) ;
}
if ( ! V_5 -> V_130 )
return;
if ( F_199 ( V_5 -> V_130 ) )
V_5 -> V_177 = 1 ;
}
void F_200 ( struct V_194 * V_195 , struct V_4 * V_5 )
{
T_4 V_215 , V_216 ;
V_215 = ( T_4 ) F_201 ( V_195 ) << 9 ;
V_216 = F_105 ( V_5 -> V_14 ) ;
if ( V_215 != V_216 ) {
F_198 ( V_217
L_11 ,
V_195 -> V_214 , V_216 , V_215 ) ;
F_202 ( V_5 -> V_14 , V_215 ) ;
F_196 ( V_5 , false ) ;
}
}
int F_203 ( struct V_194 * V_195 )
{
struct V_4 * V_5 ;
int V_15 = 0 ;
if ( V_195 -> V_131 -> F_203 )
V_15 = V_195 -> V_131 -> F_203 ( V_195 ) ;
V_5 = F_178 ( V_195 , 0 ) ;
if ( ! V_5 )
return V_15 ;
F_85 ( & V_5 -> V_142 ) ;
F_200 ( V_195 , V_5 ) ;
V_5 -> V_177 = 0 ;
F_86 ( & V_5 -> V_142 ) ;
F_163 ( V_5 ) ;
return V_15 ;
}
int F_204 ( struct V_4 * V_5 )
{
struct V_194 * V_195 = V_5 -> V_130 ;
const struct V_128 * V_218 = V_195 -> V_131 ;
unsigned int V_219 ;
V_219 = F_205 ( V_195 , V_220 |
V_221 ) ;
if ( ! ( V_219 & V_220 ) )
return 0 ;
F_196 ( V_5 , true ) ;
if ( V_218 -> F_203 )
V_218 -> F_203 ( V_5 -> V_130 ) ;
return 1 ;
}
void F_206 ( struct V_4 * V_5 , T_4 V_26 )
{
unsigned V_222 = F_21 ( V_5 ) ;
F_103 ( V_5 -> V_14 ) ;
F_202 ( V_5 -> V_14 , V_26 ) ;
F_106 ( V_5 -> V_14 ) ;
while ( V_222 < V_27 ) {
if ( V_26 & V_222 )
break;
V_222 <<= 1 ;
}
V_5 -> V_29 = V_222 ;
V_5 -> V_14 -> V_30 = F_23 ( V_222 ) ;
}
static int F_207 ( struct V_4 * V_5 , T_9 V_223 , int V_224 )
{
struct V_194 * V_195 ;
struct V_225 * V_198 ;
int V_15 ;
int V_196 ;
int V_226 = 0 ;
if ( V_223 & V_227 )
V_226 |= V_228 ;
if ( V_223 & V_229 )
V_226 |= V_230 ;
if ( ! V_224 ) {
V_15 = F_208 ( V_5 -> V_14 , V_226 ) ;
if ( V_15 != 0 ) {
F_163 ( V_5 ) ;
return V_15 ;
}
}
V_231:
V_15 = - V_197 ;
V_195 = F_177 ( V_5 -> V_172 , & V_196 ) ;
if ( ! V_195 )
goto V_105;
V_198 = V_195 -> V_131 -> V_198 ;
F_209 ( V_195 ) ;
F_210 ( & V_5 -> V_142 , V_224 ) ;
if ( ! V_5 -> V_232 ) {
V_5 -> V_130 = V_195 ;
V_5 -> V_134 = V_195 -> V_233 ;
V_5 -> V_174 = V_5 ;
if ( ! V_196 ) {
V_15 = - V_197 ;
V_5 -> V_204 = F_211 ( V_195 , V_196 ) ;
if ( ! V_5 -> V_204 )
goto V_234;
V_15 = 0 ;
if ( V_195 -> V_131 -> V_235 ) {
V_15 = V_195 -> V_131 -> V_235 ( V_5 , V_223 ) ;
if ( V_15 == - V_236 ) {
F_212 ( V_5 -> V_204 ) ;
V_5 -> V_204 = NULL ;
V_5 -> V_130 = NULL ;
V_5 -> V_134 = NULL ;
F_86 ( & V_5 -> V_142 ) ;
F_213 ( V_195 ) ;
F_180 ( V_195 ) ;
F_179 ( V_198 ) ;
goto V_231;
}
}
if ( ! V_15 )
F_206 ( V_5 , ( T_4 ) F_201 ( V_195 ) << 9 ) ;
if ( V_5 -> V_177 ) {
if ( ! V_15 )
F_214 ( V_195 , V_5 ) ;
else if ( V_15 == - V_237 )
F_215 ( V_195 , V_5 ) ;
}
if ( V_15 )
goto V_234;
} else {
struct V_4 * V_187 ;
V_187 = F_178 ( V_195 , 0 ) ;
V_15 = - V_72 ;
if ( ! V_187 )
goto V_234;
F_216 ( V_224 ) ;
V_15 = F_207 ( V_187 , V_223 , 1 ) ;
if ( V_15 )
goto V_234;
V_5 -> V_174 = V_187 ;
V_5 -> V_204 = F_211 ( V_195 , V_196 ) ;
if ( ! ( V_195 -> V_115 & V_238 ) ||
! V_5 -> V_204 || ! V_5 -> V_204 -> V_239 ) {
V_15 = - V_197 ;
goto V_234;
}
F_206 ( V_5 , ( T_4 ) V_5 -> V_204 -> V_239 << 9 ) ;
}
if ( V_5 -> V_145 == & V_146 )
V_5 -> V_145 = F_217 ( V_195 -> V_233 -> V_240 ) ;
} else {
if ( V_5 -> V_174 == V_5 ) {
V_15 = 0 ;
if ( V_5 -> V_130 -> V_131 -> V_235 )
V_15 = V_5 -> V_130 -> V_131 -> V_235 ( V_5 , V_223 ) ;
if ( V_5 -> V_177 ) {
if ( ! V_15 )
F_214 ( V_5 -> V_130 , V_5 ) ;
else if ( V_15 == - V_237 )
F_215 ( V_5 -> V_130 , V_5 ) ;
}
if ( V_15 )
goto V_241;
}
F_180 ( V_195 ) ;
F_179 ( V_198 ) ;
}
V_5 -> V_232 ++ ;
if ( V_224 )
V_5 -> V_176 ++ ;
F_86 ( & V_5 -> V_142 ) ;
F_213 ( V_195 ) ;
return 0 ;
V_234:
F_212 ( V_5 -> V_204 ) ;
V_5 -> V_130 = NULL ;
V_5 -> V_204 = NULL ;
V_5 -> V_134 = NULL ;
if ( V_5 != V_5 -> V_174 )
F_218 ( V_5 -> V_174 , V_223 , 1 ) ;
V_5 -> V_174 = NULL ;
V_241:
F_86 ( & V_5 -> V_142 ) ;
F_213 ( V_195 ) ;
F_180 ( V_195 ) ;
F_179 ( V_198 ) ;
V_105:
F_163 ( V_5 ) ;
return V_15 ;
}
int F_219 ( struct V_4 * V_5 , T_9 V_223 , void * V_188 )
{
struct V_4 * V_187 = NULL ;
int V_102 ;
F_188 ( ( V_223 & V_242 ) && ! V_188 ) ;
if ( ( V_223 & V_242 ) && V_188 ) {
V_187 = F_175 ( V_5 , V_188 ) ;
if ( F_138 ( V_187 ) ) {
F_163 ( V_5 ) ;
return F_220 ( V_187 ) ;
}
}
V_102 = F_207 ( V_5 , V_223 , 0 ) ;
if ( V_187 ) {
struct V_194 * V_195 = V_187 -> V_130 ;
F_85 ( & V_5 -> V_142 ) ;
F_7 ( & V_148 ) ;
if ( ! V_102 ) {
F_216 ( ! F_168 ( V_5 , V_187 , V_188 ) ) ;
V_187 -> V_243 ++ ;
V_187 -> V_189 = F_168 ;
V_5 -> V_243 ++ ;
V_5 -> V_189 = V_188 ;
}
F_216 ( V_187 -> V_192 != V_188 ) ;
V_187 -> V_192 = NULL ;
F_221 ( & V_187 -> V_192 , 0 ) ;
F_8 ( & V_148 ) ;
if ( ! V_102 && ( V_223 & V_229 ) && ! V_5 -> V_244 &&
( V_195 -> V_115 & V_245 ) ) {
V_5 -> V_244 = true ;
F_209 ( V_195 ) ;
}
F_86 ( & V_5 -> V_142 ) ;
F_163 ( V_187 ) ;
}
return V_102 ;
}
struct V_4 * F_222 ( const char * V_246 , T_9 V_223 ,
void * V_188 )
{
struct V_4 * V_5 ;
int V_160 ;
V_5 = F_223 ( V_246 ) ;
if ( F_138 ( V_5 ) )
return V_5 ;
V_160 = F_219 ( V_5 , V_223 , V_188 ) ;
if ( V_160 )
return F_89 ( V_160 ) ;
if ( ( V_223 & V_229 ) && F_224 ( V_5 ) ) {
F_225 ( V_5 , V_223 ) ;
return F_89 ( - V_247 ) ;
}
return V_5 ;
}
struct V_4 * F_226 ( T_7 V_171 , T_9 V_223 , void * V_188 )
{
struct V_4 * V_5 ;
int V_160 ;
V_5 = F_153 ( V_171 ) ;
if ( ! V_5 )
return F_89 ( - V_72 ) ;
V_160 = F_219 ( V_5 , V_223 , V_188 ) ;
if ( V_160 )
return F_89 ( V_160 ) ;
return V_5 ;
}
static int F_227 ( struct V_2 * V_2 , struct V_41 * V_122 )
{
struct V_4 * V_5 ;
V_122 -> V_248 |= V_249 ;
if ( V_122 -> V_248 & V_250 )
V_122 -> V_251 |= V_252 ;
if ( V_122 -> V_248 & V_253 )
V_122 -> V_251 |= V_242 ;
if ( ( V_122 -> V_248 & V_254 ) == 3 )
V_122 -> V_251 |= V_255 ;
V_5 = F_164 ( V_2 ) ;
if ( V_5 == NULL )
return - V_72 ;
V_122 -> V_42 = V_5 -> V_14 -> V_23 ;
return F_219 ( V_5 , V_122 -> V_251 , V_122 ) ;
}
static void F_218 ( struct V_4 * V_5 , T_9 V_223 , int V_224 )
{
struct V_194 * V_195 = V_5 -> V_130 ;
struct V_4 * V_256 = NULL ;
F_210 ( & V_5 -> V_142 , V_224 ) ;
if ( V_224 )
V_5 -> V_176 -- ;
if ( ! -- V_5 -> V_232 ) {
F_188 ( V_5 -> V_243 ) ;
F_22 ( V_5 ) ;
F_12 ( V_5 ) ;
F_6 ( V_5 ) ;
}
if ( V_5 -> V_174 == V_5 ) {
if ( V_195 -> V_131 -> V_257 )
V_195 -> V_131 -> V_257 ( V_195 , V_223 ) ;
}
if ( ! V_5 -> V_232 ) {
struct V_225 * V_198 = V_195 -> V_131 -> V_198 ;
F_212 ( V_5 -> V_204 ) ;
V_5 -> V_204 = NULL ;
V_5 -> V_130 = NULL ;
if ( V_5 != V_5 -> V_174 )
V_256 = V_5 -> V_174 ;
V_5 -> V_174 = NULL ;
F_180 ( V_195 ) ;
F_179 ( V_198 ) ;
}
F_86 ( & V_5 -> V_142 ) ;
F_163 ( V_5 ) ;
if ( V_256 )
F_218 ( V_256 , V_223 , 1 ) ;
}
void F_225 ( struct V_4 * V_5 , T_9 V_223 )
{
F_85 ( & V_5 -> V_142 ) ;
if ( V_223 & V_242 ) {
bool V_258 ;
F_7 ( & V_148 ) ;
F_188 ( -- V_5 -> V_243 < 0 ) ;
F_188 ( -- V_5 -> V_174 -> V_243 < 0 ) ;
if ( ( V_258 = ! V_5 -> V_243 ) )
V_5 -> V_189 = NULL ;
if ( ! V_5 -> V_174 -> V_243 )
V_5 -> V_174 -> V_189 = NULL ;
F_8 ( & V_148 ) ;
if ( V_258 && V_5 -> V_244 ) {
F_213 ( V_5 -> V_130 ) ;
V_5 -> V_244 = false ;
}
}
F_228 ( V_5 -> V_130 , V_220 ) ;
F_86 ( & V_5 -> V_142 ) ;
F_218 ( V_5 , V_223 , 0 ) ;
}
static int F_229 ( struct V_2 * V_2 , struct V_41 * V_122 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_122 ) ) ;
F_225 ( V_5 , V_122 -> V_251 ) ;
return 0 ;
}
static long F_230 ( struct V_41 * V_41 , unsigned V_259 , unsigned long V_260 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
T_9 V_223 = V_41 -> V_251 ;
if ( V_41 -> V_248 & V_250 )
V_223 |= V_252 ;
else
V_223 &= ~ V_252 ;
return F_231 ( V_5 , V_223 , V_259 , V_260 ) ;
}
T_3 F_232 ( struct V_44 * V_45 , struct V_57 * V_201 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_105 ( V_14 ) ;
struct V_93 V_94 ;
T_3 V_15 ;
if ( F_224 ( F_3 ( V_14 ) ) )
return - V_261 ;
if ( ! F_233 ( V_201 ) )
return 0 ;
if ( V_45 -> V_67 >= V_26 )
return - V_262 ;
F_234 ( V_201 , V_26 - V_45 -> V_67 ) ;
F_64 ( & V_94 ) ;
V_15 = F_235 ( V_45 , V_201 ) ;
if ( V_15 > 0 )
V_15 = F_236 ( V_45 , V_15 ) ;
F_71 ( & V_94 ) ;
return V_15 ;
}
T_3 F_237 ( struct V_44 * V_45 , struct V_57 * V_202 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_105 ( V_14 ) ;
T_4 V_66 = V_45 -> V_67 ;
if ( V_66 >= V_26 )
return 0 ;
V_26 -= V_66 ;
F_234 ( V_202 , V_26 ) ;
return F_238 ( V_45 , V_202 ) ;
}
static int F_239 ( struct V_109 * V_109 , T_10 V_101 )
{
struct V_6 * V_263 = F_1 ( V_109 -> V_22 -> V_43 ) -> V_5 . V_175 ;
if ( V_263 && V_263 -> V_106 -> V_264 )
return V_263 -> V_106 -> V_264 ( V_263 , V_109 , V_101 ) ;
return F_240 ( V_109 ) ;
}
static int F_241 ( struct V_21 * V_22 ,
struct V_110 * V_111 )
{
if ( F_242 ( V_22 ) ) {
struct V_4 * V_5 = F_3 ( V_22 -> V_43 ) ;
return F_243 ( V_22 , V_5 , V_111 ) ;
}
return F_244 ( V_22 , V_111 ) ;
}
static long F_245 ( struct V_41 * V_41 , int V_223 , T_4 V_123 ,
T_4 V_114 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
struct V_21 * V_22 ;
T_4 V_124 = V_123 + V_114 - 1 ;
T_4 V_265 ;
int error ;
if ( V_223 & ~ V_266 )
return - V_126 ;
V_265 = F_105 ( V_5 -> V_14 ) ;
if ( V_123 >= V_265 )
return - V_28 ;
if ( V_124 >= V_265 ) {
if ( V_223 & V_267 ) {
V_114 = V_265 - V_123 ;
V_124 = V_123 + V_114 - 1 ;
} else
return - V_28 ;
}
if ( ( V_123 | V_114 ) & ( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
V_22 = V_5 -> V_14 -> V_23 ;
F_246 ( V_22 , V_123 , V_124 ) ;
switch ( V_223 ) {
case V_268 :
case V_268 | V_267 :
error = F_247 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , V_269 ) ;
break;
case V_270 | V_267 :
error = F_247 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , V_271 ) ;
break;
case V_270 | V_267 | V_272 :
error = F_248 ( V_5 , V_123 >> 9 , V_114 >> 9 ,
V_71 , 0 ) ;
break;
default:
return - V_126 ;
}
if ( error )
return error ;
return F_249 ( V_22 ,
V_123 >> V_273 ,
V_124 >> V_273 ) ;
}
int F_250 ( struct V_4 * V_5 , unsigned V_259 , unsigned long V_260 )
{
int V_102 ;
T_11 V_274 = F_251 () ;
F_252 ( V_275 ) ;
V_102 = F_231 ( V_5 , 0 , V_259 , V_260 ) ;
F_252 ( V_274 ) ;
return V_102 ;
}
struct V_4 * F_223 ( const char * V_276 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_246 V_246 ;
int error ;
if ( ! V_276 || ! * V_276 )
return F_89 ( - V_28 ) ;
error = F_253 ( V_276 , V_277 , & V_246 ) ;
if ( error )
return F_89 ( error ) ;
V_2 = F_254 ( V_246 . V_149 ) ;
error = - V_278 ;
if ( ! F_255 ( V_2 -> V_178 ) )
goto V_279;
error = - V_247 ;
if ( ! F_256 ( & V_246 ) )
goto V_279;
error = - V_72 ;
V_5 = F_164 ( V_2 ) ;
if ( ! V_5 )
goto V_279;
V_105:
F_257 ( & V_246 ) ;
return V_5 ;
V_279:
V_5 = F_89 ( error ) ;
goto V_105;
}
int F_197 ( struct V_4 * V_5 , bool V_212 )
{
struct V_6 * V_7 = F_81 ( V_5 ) ;
int V_102 = 0 ;
if ( V_7 ) {
F_258 ( V_7 ) ;
V_102 = F_259 ( V_7 , V_212 ) ;
F_83 ( V_7 ) ;
}
F_15 ( V_5 ) ;
return V_102 ;
}
void F_260 ( void (* F_261)( struct V_4 * , void * ) , void * V_260 )
{
struct V_2 * V_2 , * V_280 = NULL ;
F_7 ( & V_169 -> V_281 ) ;
F_162 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_4 * V_5 ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 & ( V_282 | V_283 | V_173 ) ||
V_22 -> V_24 == 0 ) {
F_8 ( & V_2 -> V_16 ) ;
continue;
}
F_262 ( V_2 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_169 -> V_281 ) ;
F_152 ( V_280 ) ;
V_280 = V_2 ;
V_5 = F_3 ( V_2 ) ;
F_85 ( & V_5 -> V_142 ) ;
if ( V_5 -> V_232 )
F_261 ( V_5 , V_260 ) ;
F_86 ( & V_5 -> V_142 ) ;
F_7 ( & V_169 -> V_281 ) ;
}
F_8 ( & V_169 -> V_281 ) ;
F_152 ( V_280 ) ;
}
