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
V_53 . V_76 = V_45 -> V_77 ;
V_53 . V_56 = V_78 ;
V_53 . V_79 = F_30 ;
V_15 = F_37 ( & V_53 , V_58 ) ;
if ( F_38 ( V_15 ) )
return V_15 ;
V_15 = V_53 . V_74 . V_80 ;
if ( F_39 ( V_58 ) == V_81 ) {
V_53 . V_82 = V_83 ;
if ( F_40 ( V_58 ) )
V_68 = true ;
} else {
V_53 . V_82 = F_29 ( V_45 ) ;
F_41 ( V_15 ) ;
}
V_69 = F_42 ( & V_53 ) ;
for (; ; ) {
F_43 ( V_84 ) ;
if ( ! F_44 ( V_53 . V_56 ) )
break;
if ( ! ( V_45 -> V_50 & V_85 ) ||
! F_45 ( F_46 ( V_5 ) , V_69 ) )
F_47 () ;
}
F_48 ( V_86 ) ;
F_49 (bvec, &bio, i) {
if ( V_68 && ! F_50 ( V_65 -> V_87 ) )
F_51 ( V_65 -> V_87 ) ;
F_52 ( V_65 -> V_87 ) ;
}
if ( V_64 != V_62 )
F_53 ( V_64 ) ;
if ( F_38 ( V_53 . V_88 ) )
V_15 = F_54 ( V_53 . V_88 ) ;
F_55 ( & V_53 ) ;
return V_15 ;
}
static void F_56 ( struct V_53 * V_53 )
{
struct V_89 * V_90 = V_53 -> V_56 ;
bool V_68 = V_90 -> V_68 ;
if ( V_90 -> V_91 && ! F_57 ( & V_90 -> V_92 ) ) {
if ( V_53 -> V_88 && ! V_90 -> V_53 . V_88 )
V_90 -> V_53 . V_88 = V_53 -> V_88 ;
} else {
if ( ! V_90 -> V_93 ) {
struct V_44 * V_45 = V_90 -> V_45 ;
T_3 V_15 ;
if ( F_58 ( ! V_90 -> V_53 . V_88 ) ) {
V_15 = V_90 -> V_26 ;
V_45 -> V_67 += V_15 ;
} else {
V_15 = F_54 ( V_90 -> V_53 . V_88 ) ;
}
V_90 -> V_45 -> V_94 ( V_45 , V_15 , 0 ) ;
F_59 ( & V_90 -> V_53 ) ;
} else {
struct V_54 * V_55 = V_90 -> V_55 ;
F_31 ( V_90 -> V_55 , NULL ) ;
F_32 ( V_55 ) ;
}
}
if ( V_68 ) {
F_60 ( V_53 ) ;
} else {
struct V_61 * V_65 ;
int V_70 ;
F_49 (bvec, bio, i)
F_52 ( V_65 -> V_87 ) ;
F_59 ( V_53 ) ;
}
}
static T_3
F_61 ( struct V_44 * V_45 , struct V_57 * V_58 , int V_59 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_2 = F_28 ( V_41 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
struct V_95 V_96 ;
struct V_89 * V_90 ;
struct V_53 * V_53 ;
bool V_97 = ( F_39 ( V_58 ) == V_81 ) , V_93 ;
T_4 V_66 = V_45 -> V_67 ;
T_5 V_69 = V_98 ;
int V_15 = 0 ;
if ( ( V_66 | F_34 ( V_58 ) ) &
( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
V_53 = F_62 ( V_71 , V_59 , V_99 ) ;
F_63 ( V_53 ) ;
V_90 = F_2 ( V_53 , struct V_89 , V_53 ) ;
V_90 -> V_93 = V_93 = F_64 ( V_45 ) ;
if ( V_90 -> V_93 )
V_90 -> V_55 = V_78 ;
else
V_90 -> V_45 = V_45 ;
V_90 -> V_26 = 0 ;
V_90 -> V_91 = false ;
V_90 -> V_68 = V_97 && ( V_58 -> type == V_100 ) ;
F_65 ( & V_96 ) ;
for (; ; ) {
V_53 -> V_73 = V_5 ;
V_53 -> V_74 . V_75 = V_66 >> 9 ;
V_53 -> V_76 = V_45 -> V_77 ;
V_53 -> V_56 = V_90 ;
V_53 -> V_79 = F_56 ;
V_15 = F_37 ( V_53 , V_58 ) ;
if ( F_38 ( V_15 ) ) {
V_53 -> V_88 = V_101 ;
F_66 ( V_53 ) ;
break;
}
if ( V_97 ) {
V_53 -> V_82 = V_83 ;
if ( V_90 -> V_68 )
F_67 ( V_53 ) ;
} else {
V_53 -> V_82 = F_29 ( V_45 ) ;
F_41 ( V_53 -> V_74 . V_80 ) ;
}
V_90 -> V_26 += V_53 -> V_74 . V_80 ;
V_66 += V_53 -> V_74 . V_80 ;
V_59 = F_68 ( V_58 , V_102 ) ;
if ( ! V_59 ) {
V_69 = F_42 ( V_53 ) ;
break;
}
if ( ! V_90 -> V_91 ) {
V_90 -> V_91 = true ;
F_69 ( & V_90 -> V_92 , 2 ) ;
} else {
F_70 ( & V_90 -> V_92 ) ;
}
F_42 ( V_53 ) ;
V_53 = F_71 ( V_71 , V_59 ) ;
}
F_72 ( & V_96 ) ;
if ( ! V_93 )
return - V_103 ;
for (; ; ) {
F_43 ( V_84 ) ;
if ( ! F_44 ( V_90 -> V_55 ) )
break;
if ( ! ( V_45 -> V_50 & V_85 ) ||
! F_45 ( F_46 ( V_5 ) , V_69 ) )
F_47 () ;
}
F_48 ( V_86 ) ;
if ( ! V_15 )
V_15 = F_54 ( V_90 -> V_53 . V_88 ) ;
if ( F_58 ( ! V_15 ) )
V_15 = V_90 -> V_26 ;
F_59 ( & V_90 -> V_53 ) ;
return V_15 ;
}
static T_3
F_73 ( struct V_44 * V_45 , struct V_57 * V_58 )
{
int V_59 ;
V_59 = F_68 ( V_58 , V_102 + 1 ) ;
if ( ! V_59 )
return 0 ;
if ( F_64 ( V_45 ) && V_59 <= V_102 )
return F_33 ( V_45 , V_58 , V_59 ) ;
return F_61 ( V_45 , V_58 , F_74 ( V_59 , V_102 ) ) ;
}
static T_6 int F_75 ( void )
{
V_99 = F_76 ( 4 , F_77 ( struct V_89 , V_53 ) , V_104 ) ;
if ( ! V_99 )
return - V_72 ;
return 0 ;
}
int F_78 ( struct V_4 * V_5 , int V_105 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_105 )
return F_79 ( V_5 -> V_14 -> V_23 ) ;
return F_80 ( V_5 -> V_14 -> V_23 ) ;
}
int F_22 ( struct V_4 * V_5 )
{
return F_78 ( V_5 , 1 ) ;
}
int F_81 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_82 ( V_5 ) ;
if ( V_7 ) {
int V_106 = F_83 ( V_7 ) ;
F_84 ( V_7 ) ;
return V_106 ;
}
return F_22 ( V_5 ) ;
}
struct V_6 * F_85 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_86 ( & V_5 -> V_107 ) ;
if ( ++ V_5 -> V_108 > 1 ) {
V_7 = F_82 ( V_5 ) ;
if ( V_7 )
F_84 ( V_7 ) ;
F_87 ( & V_5 -> V_107 ) ;
return V_7 ;
}
V_7 = F_88 ( V_5 ) ;
if ( ! V_7 )
goto V_109;
if ( V_7 -> V_110 -> V_111 )
error = V_7 -> V_110 -> V_111 ( V_7 ) ;
else
error = V_111 ( V_7 ) ;
if ( error ) {
F_89 ( V_7 ) ;
V_5 -> V_108 -- ;
F_87 ( & V_5 -> V_107 ) ;
return F_90 ( error ) ;
}
F_89 ( V_7 ) ;
V_109:
F_22 ( V_5 ) ;
F_87 ( & V_5 -> V_107 ) ;
return V_7 ;
}
int F_91 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
int error = - V_28 ;
F_86 ( & V_5 -> V_107 ) ;
if ( ! V_5 -> V_108 )
goto V_109;
error = 0 ;
if ( -- V_5 -> V_108 > 0 )
goto V_109;
if ( ! V_7 )
goto V_109;
if ( V_7 -> V_110 -> V_112 )
error = V_7 -> V_110 -> V_112 ( V_7 ) ;
else
error = V_112 ( V_7 ) ;
if ( error )
V_5 -> V_108 ++ ;
V_109:
F_87 ( & V_5 -> V_107 ) ;
return error ;
}
static int F_92 ( struct V_113 * V_113 , struct V_114 * V_115 )
{
return F_93 ( V_113 , F_26 , V_115 ) ;
}
static int F_94 ( struct V_41 * V_41 , struct V_113 * V_113 )
{
return F_95 ( V_113 , F_26 ) ;
}
static int F_96 ( struct V_41 * V_41 , struct V_21 * V_22 ,
struct V_116 * V_117 , unsigned V_59 )
{
return F_97 ( V_22 , V_117 , V_59 , F_26 ) ;
}
static int F_98 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_66 , unsigned V_118 , unsigned V_119 ,
struct V_113 * * V_120 , void * * V_121 )
{
return F_99 ( V_22 , V_66 , V_118 , V_119 , V_120 ,
F_26 ) ;
}
static int F_100 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_66 , unsigned V_118 , unsigned V_122 ,
struct V_113 * V_113 , void * V_121 )
{
int V_15 ;
V_15 = F_101 ( V_41 , V_22 , V_66 , V_118 , V_122 , V_113 , V_121 ) ;
F_102 ( V_113 ) ;
F_52 ( V_113 ) ;
return V_15 ;
}
static T_4 F_103 ( struct V_41 * V_41 , T_4 V_123 , int V_124 )
{
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_125 ;
F_104 ( V_14 ) ;
V_125 = F_105 ( V_41 , V_123 , V_124 , F_106 ( V_14 ) ) ;
F_107 ( V_14 ) ;
return V_125 ;
}
int F_108 ( struct V_41 * V_126 , T_4 V_127 , T_4 V_128 , int V_129 )
{
struct V_2 * V_14 = F_28 ( V_126 ) ;
struct V_4 * V_5 = F_3 ( V_14 ) ;
int error ;
error = F_109 ( V_126 , V_127 , V_128 ) ;
if ( error )
return error ;
error = F_110 ( V_5 , V_71 , NULL ) ;
if ( error == - V_130 )
error = 0 ;
return error ;
}
int F_111 ( struct V_4 * V_5 , T_2 V_131 ,
struct V_113 * V_113 )
{
const struct V_132 * V_133 = V_5 -> V_134 -> V_135 ;
int V_136 = - V_130 ;
if ( ! V_133 -> V_137 || F_112 ( V_5 ) )
return V_136 ;
V_136 = F_113 ( V_5 -> V_138 , false ) ;
if ( V_136 )
return V_136 ;
V_136 = V_133 -> V_137 ( V_5 , V_131 + F_114 ( V_5 ) , V_113 , false ) ;
F_115 ( V_5 -> V_138 ) ;
return V_136 ;
}
int F_116 ( struct V_4 * V_5 , T_2 V_131 ,
struct V_113 * V_113 , struct V_114 * V_115 )
{
int V_136 ;
const struct V_132 * V_133 = V_5 -> V_134 -> V_135 ;
if ( ! V_133 -> V_137 || F_112 ( V_5 ) )
return - V_130 ;
V_136 = F_113 ( V_5 -> V_138 , false ) ;
if ( V_136 )
return V_136 ;
F_117 ( V_113 ) ;
V_136 = V_133 -> V_137 ( V_5 , V_131 + F_114 ( V_5 ) , V_113 , true ) ;
if ( V_136 )
F_118 ( V_113 ) ;
else
F_102 ( V_113 ) ;
F_115 ( V_5 -> V_138 ) ;
return V_136 ;
}
static struct V_2 * F_119 ( struct V_6 * V_7 )
{
struct V_1 * V_139 = F_120 ( V_140 , V_71 ) ;
if ( ! V_139 )
return NULL ;
return & V_139 -> V_3 ;
}
static void F_121 ( struct V_141 * V_142 )
{
struct V_2 * V_2 = F_2 ( V_142 , struct V_2 , V_143 ) ;
struct V_1 * V_144 = F_1 ( V_2 ) ;
F_122 ( V_140 , V_144 ) ;
}
static void F_123 ( struct V_2 * V_2 )
{
F_124 ( & V_2 -> V_143 , F_121 ) ;
}
static void F_125 ( void * V_145 )
{
struct V_1 * V_139 = (struct V_1 * ) V_145 ;
struct V_4 * V_5 = & V_139 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_126 ( & V_5 -> V_146 ) ;
F_127 ( & V_5 -> V_147 ) ;
#ifdef F_128
F_127 ( & V_5 -> V_148 ) ;
#endif
V_5 -> V_149 = & V_150 ;
F_129 ( & V_139 -> V_3 ) ;
F_126 ( & V_5 -> V_107 ) ;
}
static void F_130 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
F_131 ( & V_2 -> V_151 ) ;
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
F_7 ( & V_152 ) ;
F_134 ( & V_5 -> V_147 ) ;
F_8 ( & V_152 ) ;
F_135 ( V_2 ) ;
if ( V_5 -> V_149 != & V_150 ) {
F_136 ( V_5 -> V_149 ) ;
V_5 -> V_149 = & V_150 ;
}
}
static struct V_153 * F_137 ( struct V_154 * V_155 ,
int V_119 , const char * V_156 , void * V_157 )
{
struct V_153 * V_158 ;
V_158 = F_138 ( V_155 , L_4 , & V_159 , NULL , V_160 ) ;
if ( ! F_139 ( V_158 ) )
V_158 -> V_161 -> V_162 |= V_163 ;
return V_158 ;
}
void T_6 F_140 ( void )
{
int V_164 ;
static struct V_165 * V_166 ;
V_140 = F_141 ( L_5 , sizeof( struct V_1 ) ,
0 , ( V_167 | V_168 |
V_169 | V_170 | V_171 ) ,
F_125 ) ;
V_164 = F_142 ( & V_172 ) ;
if ( V_164 )
F_143 ( L_6 ) ;
V_166 = F_144 ( & V_172 ) ;
if ( F_139 ( V_166 ) )
F_143 ( L_7 ) ;
V_173 = V_166 -> V_174 ;
}
static inline unsigned long F_145 ( T_7 V_175 )
{
return F_146 ( V_175 ) + F_147 ( V_175 ) ;
}
static int F_148 ( struct V_2 * V_2 , void * V_157 )
{
return F_1 ( V_2 ) -> V_5 . V_176 == * ( T_7 * ) V_157 ;
}
static int F_149 ( struct V_2 * V_2 , void * V_157 )
{
F_1 ( V_2 ) -> V_5 . V_176 = * ( T_7 * ) V_157 ;
return 0 ;
}
void F_150 ( T_7 V_175 )
{
struct V_2 * V_2 ;
V_2 = F_151 ( V_173 , F_145 ( V_175 ) , F_148 , & V_175 ) ;
if ( V_2 ) {
F_152 ( V_2 ) ;
F_153 ( V_2 ) ;
}
}
struct V_4 * F_154 ( T_7 V_175 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_155 ( V_173 , F_145 ( V_175 ) ,
F_148 , F_149 , & V_175 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_17 & V_177 ) {
V_5 -> V_178 = NULL ;
V_5 -> V_179 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_29 = F_156 ( V_2 ) ;
V_5 -> V_180 = 0 ;
V_5 -> V_181 = 0 ;
V_2 -> V_182 = V_183 ;
V_2 -> V_184 = V_175 ;
V_2 -> V_185 = V_5 ;
V_2 -> V_151 . V_186 = & V_187 ;
F_157 ( & V_2 -> V_151 , V_188 ) ;
F_7 ( & V_152 ) ;
F_158 ( & V_5 -> V_147 , & V_189 ) ;
F_8 ( & V_152 ) ;
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
F_7 ( & V_152 ) ;
F_163 (bdev, &all_bdevs, bd_list) {
V_15 += V_5 -> V_14 -> V_23 -> V_24 ;
}
F_8 ( & V_152 ) ;
return V_15 ;
}
void F_164 ( struct V_4 * V_5 )
{
F_153 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_165 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_152 ) ;
V_5 = V_2 -> V_185 ;
if ( V_5 && ! F_166 ( V_5 -> V_14 ) ) {
F_160 ( V_5 ) ;
F_8 ( & V_152 ) ;
return V_5 ;
}
F_8 ( & V_152 ) ;
if ( V_5 )
F_167 ( V_2 ) ;
V_5 = F_154 ( V_2 -> V_184 ) ;
if ( V_5 ) {
F_7 ( & V_152 ) ;
if ( ! V_2 -> V_185 ) {
F_160 ( V_5 ) ;
V_2 -> V_185 = V_5 ;
V_2 -> V_23 = V_5 -> V_14 -> V_23 ;
}
F_8 ( & V_152 ) ;
}
return V_5 ;
}
void F_167 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_152 ) ;
if ( ! F_168 ( V_2 -> V_190 ) )
V_5 = V_2 -> V_185 ;
V_2 -> V_185 = NULL ;
V_2 -> V_23 = & V_2 -> V_151 ;
F_8 ( & V_152 ) ;
if ( V_5 )
F_164 ( V_5 ) ;
}
static bool F_169 ( struct V_4 * V_5 , struct V_4 * V_191 ,
void * V_192 )
{
if ( V_5 -> V_193 == V_192 )
return true ;
else if ( V_5 -> V_193 != NULL )
return false ;
else if ( V_191 == V_5 )
return true ;
else if ( V_191 -> V_193 == F_169 )
return true ;
else if ( V_191 -> V_193 != NULL )
return false ;
else
return true ;
}
static int F_170 ( struct V_4 * V_5 ,
struct V_4 * V_191 , void * V_192 )
{
V_194:
if ( ! F_169 ( V_5 , V_191 , V_192 ) )
return - V_195 ;
if ( V_191 -> V_196 ) {
T_8 * V_197 = F_171 ( & V_191 -> V_196 , 0 ) ;
F_172 ( V_105 ) ;
F_173 ( V_197 , & V_105 , V_84 ) ;
F_8 ( & V_152 ) ;
F_174 () ;
F_175 ( V_197 , & V_105 ) ;
F_7 ( & V_152 ) ;
goto V_194;
}
return 0 ;
}
static struct V_4 * F_176 ( struct V_4 * V_5 ,
void * V_192 )
{
struct V_198 * V_199 ;
struct V_4 * V_191 ;
int V_200 , V_164 ;
F_177 () ;
V_199 = F_178 ( V_5 -> V_176 , & V_200 ) ;
if ( ! V_199 )
return F_90 ( - V_201 ) ;
if ( V_200 )
V_191 = F_179 ( V_199 , 0 ) ;
else
V_191 = F_160 ( V_5 ) ;
F_180 ( V_199 -> V_135 -> V_202 ) ;
F_181 ( V_199 ) ;
if ( ! V_191 )
return F_90 ( - V_72 ) ;
F_7 ( & V_152 ) ;
V_164 = F_170 ( V_5 , V_191 , V_192 ) ;
if ( V_164 == 0 ) {
V_191 -> V_196 = V_192 ;
F_8 ( & V_152 ) ;
return V_191 ;
} else {
F_8 ( & V_152 ) ;
F_164 ( V_191 ) ;
return F_90 ( V_164 ) ;
}
}
static struct V_203 * F_182 ( struct V_4 * V_5 ,
struct V_198 * V_199 )
{
struct V_203 * V_192 ;
F_163 (holder, &bdev->bd_holder_disks, list)
if ( V_192 -> V_199 == V_199 )
return V_192 ;
return NULL ;
}
static int F_183 ( struct V_204 * V_205 , struct V_204 * V_206 )
{
return F_184 ( V_205 , V_206 , F_185 ( V_206 ) ) ;
}
static void F_186 ( struct V_204 * V_205 , struct V_204 * V_206 )
{
F_187 ( V_205 , F_185 ( V_206 ) ) ;
}
int F_188 ( struct V_4 * V_5 , struct V_198 * V_199 )
{
struct V_203 * V_192 ;
int V_15 = 0 ;
F_86 ( & V_5 -> V_146 ) ;
F_189 ( ! V_5 -> V_193 ) ;
if ( F_190 ( ! V_199 -> V_207 || ! V_5 -> V_208 -> V_209 ) )
goto V_210;
V_192 = F_182 ( V_5 , V_199 ) ;
if ( V_192 ) {
V_192 -> V_211 ++ ;
goto V_210;
}
V_192 = F_191 ( sizeof( * V_192 ) , V_71 ) ;
if ( ! V_192 ) {
V_15 = - V_72 ;
goto V_210;
}
F_127 ( & V_192 -> V_212 ) ;
V_192 -> V_199 = V_199 ;
V_192 -> V_211 = 1 ;
V_15 = F_183 ( V_199 -> V_207 , & F_192 ( V_5 -> V_208 ) -> V_213 ) ;
if ( V_15 )
goto V_214;
V_15 = F_183 ( V_5 -> V_208 -> V_209 , & F_193 ( V_199 ) -> V_213 ) ;
if ( V_15 )
goto V_215;
F_194 ( V_5 -> V_208 -> V_209 ) ;
F_158 ( & V_192 -> V_212 , & V_5 -> V_148 ) ;
goto V_210;
V_215:
F_186 ( V_199 -> V_207 , & F_192 ( V_5 -> V_208 ) -> V_213 ) ;
V_214:
F_53 ( V_192 ) ;
V_210:
F_87 ( & V_5 -> V_146 ) ;
return V_15 ;
}
void F_195 ( struct V_4 * V_5 , struct V_198 * V_199 )
{
struct V_203 * V_192 ;
F_86 ( & V_5 -> V_146 ) ;
V_192 = F_182 ( V_5 , V_199 ) ;
if ( ! F_189 ( V_192 == NULL ) && ! -- V_192 -> V_211 ) {
F_186 ( V_199 -> V_207 , & F_192 ( V_5 -> V_208 ) -> V_213 ) ;
F_186 ( V_5 -> V_208 -> V_209 ,
& F_193 ( V_199 ) -> V_213 ) ;
F_196 ( V_5 -> V_208 -> V_209 ) ;
F_134 ( & V_192 -> V_212 ) ;
F_53 ( V_192 ) ;
}
F_87 ( & V_5 -> V_146 ) ;
}
static void F_197 ( struct V_4 * V_5 , bool V_216 )
{
if ( F_198 ( V_5 , V_216 ) ) {
F_199 ( V_217 L_8
L_9 ,
V_5 -> V_134 ? V_5 -> V_134 -> V_218 : L_10 ) ;
}
if ( ! V_5 -> V_134 )
return;
if ( F_200 ( V_5 -> V_134 ) )
V_5 -> V_181 = 1 ;
}
void F_201 ( struct V_198 * V_199 , struct V_4 * V_5 )
{
T_4 V_219 , V_220 ;
V_219 = ( T_4 ) F_202 ( V_199 ) << 9 ;
V_220 = F_106 ( V_5 -> V_14 ) ;
if ( V_219 != V_220 ) {
F_199 ( V_221
L_11 ,
V_199 -> V_218 , V_220 , V_219 ) ;
F_203 ( V_5 -> V_14 , V_219 ) ;
F_197 ( V_5 , false ) ;
}
}
int F_204 ( struct V_198 * V_199 )
{
struct V_4 * V_5 ;
int V_15 = 0 ;
if ( V_199 -> V_135 -> F_204 )
V_15 = V_199 -> V_135 -> F_204 ( V_199 ) ;
V_5 = F_179 ( V_199 , 0 ) ;
if ( ! V_5 )
return V_15 ;
F_86 ( & V_5 -> V_146 ) ;
F_201 ( V_199 , V_5 ) ;
V_5 -> V_181 = 0 ;
F_87 ( & V_5 -> V_146 ) ;
F_164 ( V_5 ) ;
return V_15 ;
}
int F_205 ( struct V_4 * V_5 )
{
struct V_198 * V_199 = V_5 -> V_134 ;
const struct V_132 * V_222 = V_199 -> V_135 ;
unsigned int V_223 ;
V_223 = F_206 ( V_199 , V_224 |
V_225 ) ;
if ( ! ( V_223 & V_224 ) )
return 0 ;
F_197 ( V_5 , true ) ;
if ( V_222 -> F_204 )
V_222 -> F_204 ( V_5 -> V_134 ) ;
return 1 ;
}
void F_207 ( struct V_4 * V_5 , T_4 V_26 )
{
unsigned V_226 = F_21 ( V_5 ) ;
F_104 ( V_5 -> V_14 ) ;
F_203 ( V_5 -> V_14 , V_26 ) ;
F_107 ( V_5 -> V_14 ) ;
while ( V_226 < V_27 ) {
if ( V_26 & V_226 )
break;
V_226 <<= 1 ;
}
V_5 -> V_29 = V_226 ;
V_5 -> V_14 -> V_30 = F_23 ( V_226 ) ;
}
static int F_208 ( struct V_4 * V_5 , T_9 V_227 , int V_228 )
{
struct V_198 * V_199 ;
struct V_229 * V_202 ;
int V_15 ;
int V_200 ;
int V_230 = 0 ;
if ( V_227 & V_231 )
V_230 |= V_232 ;
if ( V_227 & V_233 )
V_230 |= V_234 ;
if ( ! V_228 ) {
V_15 = F_209 ( V_5 -> V_14 , V_230 ) ;
if ( V_15 != 0 ) {
F_164 ( V_5 ) ;
return V_15 ;
}
}
V_235:
V_15 = - V_201 ;
V_199 = F_178 ( V_5 -> V_176 , & V_200 ) ;
if ( ! V_199 )
goto V_109;
V_202 = V_199 -> V_135 -> V_202 ;
F_210 ( V_199 ) ;
F_211 ( & V_5 -> V_146 , V_228 ) ;
if ( ! V_5 -> V_236 ) {
V_5 -> V_134 = V_199 ;
V_5 -> V_138 = V_199 -> V_237 ;
V_5 -> V_178 = V_5 ;
if ( ! V_200 ) {
V_15 = - V_201 ;
V_5 -> V_208 = F_212 ( V_199 , V_200 ) ;
if ( ! V_5 -> V_208 )
goto V_238;
V_15 = 0 ;
if ( V_199 -> V_135 -> V_239 ) {
V_15 = V_199 -> V_135 -> V_239 ( V_5 , V_227 ) ;
if ( V_15 == - V_240 ) {
F_213 ( V_5 -> V_208 ) ;
V_5 -> V_208 = NULL ;
V_5 -> V_134 = NULL ;
V_5 -> V_138 = NULL ;
F_87 ( & V_5 -> V_146 ) ;
F_214 ( V_199 ) ;
F_181 ( V_199 ) ;
F_180 ( V_202 ) ;
goto V_235;
}
}
if ( ! V_15 )
F_207 ( V_5 , ( T_4 ) F_202 ( V_199 ) << 9 ) ;
if ( V_5 -> V_181 ) {
if ( ! V_15 )
F_215 ( V_199 , V_5 ) ;
else if ( V_15 == - V_241 )
F_216 ( V_199 , V_5 ) ;
}
if ( V_15 )
goto V_238;
} else {
struct V_4 * V_191 ;
V_191 = F_179 ( V_199 , 0 ) ;
V_15 = - V_72 ;
if ( ! V_191 )
goto V_238;
F_217 ( V_228 ) ;
V_15 = F_208 ( V_191 , V_227 , 1 ) ;
if ( V_15 )
goto V_238;
V_5 -> V_178 = V_191 ;
V_5 -> V_208 = F_212 ( V_199 , V_200 ) ;
if ( ! ( V_199 -> V_119 & V_242 ) ||
! V_5 -> V_208 || ! V_5 -> V_208 -> V_243 ) {
V_15 = - V_201 ;
goto V_238;
}
F_207 ( V_5 , ( T_4 ) V_5 -> V_208 -> V_243 << 9 ) ;
}
if ( V_5 -> V_149 == & V_150 )
V_5 -> V_149 = F_218 ( V_199 -> V_237 -> V_244 ) ;
} else {
if ( V_5 -> V_178 == V_5 ) {
V_15 = 0 ;
if ( V_5 -> V_134 -> V_135 -> V_239 )
V_15 = V_5 -> V_134 -> V_135 -> V_239 ( V_5 , V_227 ) ;
if ( V_5 -> V_181 ) {
if ( ! V_15 )
F_215 ( V_5 -> V_134 , V_5 ) ;
else if ( V_15 == - V_241 )
F_216 ( V_5 -> V_134 , V_5 ) ;
}
if ( V_15 )
goto V_245;
}
F_181 ( V_199 ) ;
F_180 ( V_202 ) ;
}
V_5 -> V_236 ++ ;
if ( V_228 )
V_5 -> V_180 ++ ;
F_87 ( & V_5 -> V_146 ) ;
F_214 ( V_199 ) ;
return 0 ;
V_238:
F_213 ( V_5 -> V_208 ) ;
V_5 -> V_134 = NULL ;
V_5 -> V_208 = NULL ;
V_5 -> V_138 = NULL ;
if ( V_5 != V_5 -> V_178 )
F_219 ( V_5 -> V_178 , V_227 , 1 ) ;
V_5 -> V_178 = NULL ;
V_245:
F_87 ( & V_5 -> V_146 ) ;
F_214 ( V_199 ) ;
F_181 ( V_199 ) ;
F_180 ( V_202 ) ;
V_109:
F_164 ( V_5 ) ;
return V_15 ;
}
int F_220 ( struct V_4 * V_5 , T_9 V_227 , void * V_192 )
{
struct V_4 * V_191 = NULL ;
int V_106 ;
F_189 ( ( V_227 & V_246 ) && ! V_192 ) ;
if ( ( V_227 & V_246 ) && V_192 ) {
V_191 = F_176 ( V_5 , V_192 ) ;
if ( F_139 ( V_191 ) ) {
F_164 ( V_5 ) ;
return F_221 ( V_191 ) ;
}
}
V_106 = F_208 ( V_5 , V_227 , 0 ) ;
if ( V_191 ) {
struct V_198 * V_199 = V_191 -> V_134 ;
F_86 ( & V_5 -> V_146 ) ;
F_7 ( & V_152 ) ;
if ( ! V_106 ) {
F_217 ( ! F_169 ( V_5 , V_191 , V_192 ) ) ;
V_191 -> V_247 ++ ;
V_191 -> V_193 = F_169 ;
V_5 -> V_247 ++ ;
V_5 -> V_193 = V_192 ;
}
F_217 ( V_191 -> V_196 != V_192 ) ;
V_191 -> V_196 = NULL ;
F_222 ( & V_191 -> V_196 , 0 ) ;
F_8 ( & V_152 ) ;
if ( ! V_106 && ( V_227 & V_233 ) && ! V_5 -> V_248 &&
( V_199 -> V_119 & V_249 ) ) {
V_5 -> V_248 = true ;
F_210 ( V_199 ) ;
}
F_87 ( & V_5 -> V_146 ) ;
F_164 ( V_191 ) ;
}
return V_106 ;
}
struct V_4 * F_223 ( const char * V_250 , T_9 V_227 ,
void * V_192 )
{
struct V_4 * V_5 ;
int V_164 ;
V_5 = F_224 ( V_250 ) ;
if ( F_139 ( V_5 ) )
return V_5 ;
V_164 = F_220 ( V_5 , V_227 , V_192 ) ;
if ( V_164 )
return F_90 ( V_164 ) ;
if ( ( V_227 & V_233 ) && F_225 ( V_5 ) ) {
F_226 ( V_5 , V_227 ) ;
return F_90 ( - V_251 ) ;
}
return V_5 ;
}
struct V_4 * F_227 ( T_7 V_175 , T_9 V_227 , void * V_192 )
{
struct V_4 * V_5 ;
int V_164 ;
V_5 = F_154 ( V_175 ) ;
if ( ! V_5 )
return F_90 ( - V_72 ) ;
V_164 = F_220 ( V_5 , V_227 , V_192 ) ;
if ( V_164 )
return F_90 ( V_164 ) ;
return V_5 ;
}
static int F_228 ( struct V_2 * V_2 , struct V_41 * V_126 )
{
struct V_4 * V_5 ;
V_126 -> V_252 |= V_253 ;
if ( V_126 -> V_252 & V_254 )
V_126 -> V_255 |= V_256 ;
if ( V_126 -> V_252 & V_257 )
V_126 -> V_255 |= V_246 ;
if ( ( V_126 -> V_252 & V_258 ) == 3 )
V_126 -> V_255 |= V_259 ;
V_5 = F_165 ( V_2 ) ;
if ( V_5 == NULL )
return - V_72 ;
V_126 -> V_42 = V_5 -> V_14 -> V_23 ;
V_126 -> V_260 = F_229 ( V_126 -> V_42 ) ;
return F_220 ( V_5 , V_126 -> V_255 , V_126 ) ;
}
static void F_219 ( struct V_4 * V_5 , T_9 V_227 , int V_228 )
{
struct V_198 * V_199 = V_5 -> V_134 ;
struct V_4 * V_261 = NULL ;
F_211 ( & V_5 -> V_146 , V_228 ) ;
if ( V_228 )
V_5 -> V_180 -- ;
if ( ! -- V_5 -> V_236 ) {
F_189 ( V_5 -> V_247 ) ;
F_22 ( V_5 ) ;
F_12 ( V_5 ) ;
F_6 ( V_5 ) ;
}
if ( V_5 -> V_178 == V_5 ) {
if ( V_199 -> V_135 -> V_262 )
V_199 -> V_135 -> V_262 ( V_199 , V_227 ) ;
}
if ( ! V_5 -> V_236 ) {
struct V_229 * V_202 = V_199 -> V_135 -> V_202 ;
F_213 ( V_5 -> V_208 ) ;
V_5 -> V_208 = NULL ;
V_5 -> V_134 = NULL ;
if ( V_5 != V_5 -> V_178 )
V_261 = V_5 -> V_178 ;
V_5 -> V_178 = NULL ;
F_181 ( V_199 ) ;
F_180 ( V_202 ) ;
}
F_87 ( & V_5 -> V_146 ) ;
F_164 ( V_5 ) ;
if ( V_261 )
F_219 ( V_261 , V_227 , 1 ) ;
}
void F_226 ( struct V_4 * V_5 , T_9 V_227 )
{
F_86 ( & V_5 -> V_146 ) ;
if ( V_227 & V_246 ) {
bool V_263 ;
F_7 ( & V_152 ) ;
F_189 ( -- V_5 -> V_247 < 0 ) ;
F_189 ( -- V_5 -> V_178 -> V_247 < 0 ) ;
if ( ( V_263 = ! V_5 -> V_247 ) )
V_5 -> V_193 = NULL ;
if ( ! V_5 -> V_178 -> V_247 )
V_5 -> V_178 -> V_193 = NULL ;
F_8 ( & V_152 ) ;
if ( V_263 && V_5 -> V_248 ) {
F_214 ( V_5 -> V_134 ) ;
V_5 -> V_248 = false ;
}
}
F_230 ( V_5 -> V_134 , V_224 ) ;
F_87 ( & V_5 -> V_146 ) ;
F_219 ( V_5 , V_227 , 0 ) ;
}
static int F_231 ( struct V_2 * V_2 , struct V_41 * V_126 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_126 ) ) ;
F_226 ( V_5 , V_126 -> V_255 ) ;
return 0 ;
}
static long F_232 ( struct V_41 * V_41 , unsigned V_264 , unsigned long V_265 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
T_9 V_227 = V_41 -> V_255 ;
if ( V_41 -> V_252 & V_254 )
V_227 |= V_256 ;
else
V_227 &= ~ V_256 ;
return F_233 ( V_5 , V_227 , V_264 , V_265 ) ;
}
T_3 F_234 ( struct V_44 * V_45 , struct V_57 * V_205 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_106 ( V_14 ) ;
struct V_95 V_96 ;
T_3 V_15 ;
if ( F_225 ( F_3 ( V_14 ) ) )
return - V_266 ;
if ( ! F_235 ( V_205 ) )
return 0 ;
if ( V_45 -> V_67 >= V_26 )
return - V_267 ;
F_236 ( V_205 , V_26 - V_45 -> V_67 ) ;
F_65 ( & V_96 ) ;
V_15 = F_237 ( V_45 , V_205 ) ;
if ( V_15 > 0 )
V_15 = F_238 ( V_45 , V_15 ) ;
F_72 ( & V_96 ) ;
return V_15 ;
}
T_3 F_239 ( struct V_44 * V_45 , struct V_57 * V_206 )
{
struct V_41 * V_41 = V_45 -> V_60 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_106 ( V_14 ) ;
T_4 V_66 = V_45 -> V_67 ;
if ( V_66 >= V_26 )
return 0 ;
V_26 -= V_66 ;
F_236 ( V_206 , V_26 ) ;
return F_240 ( V_45 , V_206 ) ;
}
static int F_241 ( struct V_113 * V_113 , T_10 V_105 )
{
struct V_6 * V_268 = F_1 ( V_113 -> V_22 -> V_43 ) -> V_5 . V_179 ;
if ( V_268 && V_268 -> V_110 -> V_269 )
return V_268 -> V_110 -> V_269 ( V_268 , V_113 , V_105 ) ;
return F_242 ( V_113 ) ;
}
static int F_243 ( struct V_21 * V_22 ,
struct V_114 * V_115 )
{
if ( F_244 ( V_22 ) ) {
struct V_4 * V_5 = F_3 ( V_22 -> V_43 ) ;
return F_245 ( V_22 , V_5 , V_115 ) ;
}
return F_246 ( V_22 , V_115 ) ;
}
static long F_247 ( struct V_41 * V_41 , int V_227 , T_4 V_127 ,
T_4 V_118 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
struct V_21 * V_22 ;
T_4 V_128 = V_127 + V_118 - 1 ;
T_4 V_270 ;
int error ;
if ( V_227 & ~ V_271 )
return - V_130 ;
V_270 = F_106 ( V_5 -> V_14 ) ;
if ( V_127 >= V_270 )
return - V_28 ;
if ( V_128 >= V_270 ) {
if ( V_227 & V_272 ) {
V_118 = V_270 - V_127 ;
V_128 = V_127 + V_118 - 1 ;
} else
return - V_28 ;
}
if ( ( V_127 | V_118 ) & ( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
V_22 = V_5 -> V_14 -> V_23 ;
F_248 ( V_22 , V_127 , V_128 ) ;
switch ( V_227 ) {
case V_273 :
case V_273 | V_272 :
error = F_249 ( V_5 , V_127 >> 9 , V_118 >> 9 ,
V_71 , V_274 ) ;
break;
case V_275 | V_272 :
error = F_249 ( V_5 , V_127 >> 9 , V_118 >> 9 ,
V_71 , V_276 ) ;
break;
case V_275 | V_272 | V_277 :
error = F_250 ( V_5 , V_127 >> 9 , V_118 >> 9 ,
V_71 , 0 ) ;
break;
default:
return - V_130 ;
}
if ( error )
return error ;
return F_251 ( V_22 ,
V_127 >> V_278 ,
V_128 >> V_278 ) ;
}
int F_252 ( struct V_4 * V_5 , unsigned V_264 , unsigned long V_265 )
{
int V_106 ;
T_11 V_279 = F_253 () ;
F_254 ( V_280 ) ;
V_106 = F_233 ( V_5 , 0 , V_264 , V_265 ) ;
F_254 ( V_279 ) ;
return V_106 ;
}
struct V_4 * F_224 ( const char * V_281 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_250 V_250 ;
int error ;
if ( ! V_281 || ! * V_281 )
return F_90 ( - V_28 ) ;
error = F_255 ( V_281 , V_282 , & V_250 ) ;
if ( error )
return F_90 ( error ) ;
V_2 = F_256 ( V_250 . V_153 ) ;
error = - V_283 ;
if ( ! F_257 ( V_2 -> V_182 ) )
goto V_284;
error = - V_251 ;
if ( ! F_258 ( & V_250 ) )
goto V_284;
error = - V_72 ;
V_5 = F_165 ( V_2 ) ;
if ( ! V_5 )
goto V_284;
V_109:
F_259 ( & V_250 ) ;
return V_5 ;
V_284:
V_5 = F_90 ( error ) ;
goto V_109;
}
int F_198 ( struct V_4 * V_5 , bool V_216 )
{
struct V_6 * V_7 = F_82 ( V_5 ) ;
int V_106 = 0 ;
if ( V_7 ) {
F_260 ( V_7 ) ;
V_106 = F_261 ( V_7 , V_216 ) ;
F_84 ( V_7 ) ;
}
F_15 ( V_5 ) ;
return V_106 ;
}
void F_262 ( void (* F_263)( struct V_4 * , void * ) , void * V_265 )
{
struct V_2 * V_2 , * V_285 = NULL ;
F_7 ( & V_173 -> V_286 ) ;
F_163 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_4 * V_5 ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 & ( V_287 | V_288 | V_177 ) ||
V_22 -> V_24 == 0 ) {
F_8 ( & V_2 -> V_16 ) ;
continue;
}
F_264 ( V_2 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_173 -> V_286 ) ;
F_153 ( V_285 ) ;
V_285 = V_2 ;
V_5 = F_3 ( V_2 ) ;
F_86 ( & V_5 -> V_146 ) ;
if ( V_5 -> V_236 )
F_263 ( V_5 , V_265 ) ;
F_87 ( & V_5 -> V_146 ) ;
F_7 ( & V_173 -> V_286 ) ;
}
F_8 ( & V_173 -> V_286 ) ;
F_153 ( V_285 ) ;
}
