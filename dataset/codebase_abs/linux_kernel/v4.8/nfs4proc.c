static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
int V_8 ;
if ( V_7 == NULL )
return NULL ;
if ( F_2 ( V_3 , V_9 ) == 0 )
return NULL ;
V_8 = F_3 ( V_4 , V_6 -> V_10 ,
& V_4 -> V_11 , ( void * * ) & V_7 -> V_7 , & V_7 -> V_12 ) ;
if ( V_8 == 0 )
return V_7 ;
return NULL ;
}
static inline void
F_4 ( struct V_1 * V_7 )
{
if ( V_7 )
F_5 ( V_7 -> V_7 , V_7 -> V_12 ) ;
}
static inline T_1 * F_6 ( struct V_13 * V_14 , struct V_1 * V_7 )
{
if ( V_7 )
return V_14 -> V_15 ;
return V_14 -> V_16 ;
}
static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_17 )
{ return NULL ; }
static inline void
F_4 ( struct V_1 * V_7 )
{ return; }
static inline T_1 *
F_6 ( struct V_13 * V_14 , struct V_1 * V_7 )
{ return V_14 -> V_15 ; }
static int F_7 ( int V_8 )
{
if ( V_8 >= - 1000 )
return V_8 ;
switch ( V_8 ) {
case - V_18 :
case - V_19 :
case - V_20 :
return - V_21 ;
case - V_22 :
case - V_23 :
return - V_24 ;
case - V_25 :
case - V_26 :
return - V_27 ;
case - V_28 :
return - V_29 ;
case - V_30 :
return - V_31 ;
case - V_32 :
return - V_33 ;
default:
F_8 ( L_1 ,
V_34 , - V_8 ) ;
break;
}
return - V_35 ;
}
static void F_9 ( T_2 V_36 , T_3 * V_37 , struct V_4 * V_4 ,
struct V_38 * V_39 )
{
T_3 * V_40 , * V_41 ;
if ( V_36 > 2 ) {
V_39 -> V_36 = V_36 ;
memcpy ( & V_39 -> V_37 , V_37 , sizeof( V_39 -> V_37 ) ) ;
return;
}
V_39 -> V_36 = 0 ;
memset ( & V_39 -> V_37 , 0 , sizeof( V_39 -> V_37 ) ) ;
if ( V_36 == 2 )
return;
V_40 = V_41 = F_10 ( * V_39 -> V_42 ) ;
if ( V_36 == 0 ) {
* V_41 ++ = V_43 ;
* V_41 ++ = V_44 ;
* V_41 ++ = V_43 ;
* V_41 ++ = V_43 ;
memcpy ( V_41 , L_2 , 4 ) ;
V_41 ++ ;
* V_41 ++ = V_43 ;
* V_41 ++ = F_11 ( V_45 ) ;
* V_41 ++ = F_11 ( 8 ) ;
V_41 = F_12 ( V_41 , F_13 ( F_14 ( V_4 ) ) ) ;
}
* V_41 ++ = V_43 ;
* V_41 ++ = V_44 ;
* V_41 ++ = V_46 ;
* V_41 ++ = V_46 ;
memcpy ( V_41 , L_3 , 4 ) ;
V_41 ++ ;
* V_41 ++ = V_43 ;
* V_41 ++ = F_11 ( V_45 ) ;
* V_41 ++ = F_11 ( 8 ) ;
V_41 = F_12 ( V_41 , F_13 ( F_14 ( V_4 -> V_47 ) ) ) ;
V_39 -> V_48 = ( char * ) V_41 - ( char * ) V_40 ;
V_39 -> V_49 -= V_39 -> V_48 ;
F_15 ( V_40 ) ;
}
static long F_16 ( long * V_50 )
{
long V_51 ;
if ( ! V_50 )
return V_52 ;
if ( * V_50 <= 0 )
* V_50 = V_53 ;
if ( * V_50 > V_52 )
* V_50 = V_52 ;
V_51 = * V_50 ;
* V_50 <<= 1 ;
return V_51 ;
}
static int F_17 ( struct V_54 * V_55 , long * V_50 )
{
int V_56 = 0 ;
F_18 () ;
F_19 (
F_16 ( V_50 ) ) ;
if ( F_20 ( V_57 ) )
V_56 = - V_58 ;
return V_56 ;
}
static int F_21 ( struct V_13 * V_14 ,
int V_59 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_64 * V_65 = V_61 -> V_65 ;
const T_4 * V_66 = V_61 -> V_66 ;
struct V_2 * V_2 = V_61 -> V_2 ;
int V_51 = V_59 ;
V_61 -> V_67 = 0 ;
V_61 -> V_68 = 0 ;
V_61 -> V_69 = 0 ;
switch( V_59 ) {
case 0 :
return 0 ;
case - V_70 :
case - V_71 :
case - V_72 :
case - V_73 :
if ( V_2 ) {
int V_8 ;
V_8 = F_22 ( V_2 ,
V_66 ) ;
if ( V_8 == 0 )
goto V_74;
if ( V_66 != NULL && V_66 -> type == V_75 ) {
V_61 -> V_69 = 1 ;
break;
}
}
if ( V_65 == NULL )
break;
V_51 = F_23 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
goto V_74;
case - V_76 :
if ( V_65 != NULL ) {
V_51 = F_23 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
}
case - V_77 :
case - V_78 :
F_24 ( V_63 ) ;
goto V_74;
case - V_79 :
V_51 = F_25 ( V_14 ) ;
if ( V_51 < 0 )
break;
goto V_74;
case - V_80 :
F_26 ( V_63 ) ;
goto V_74;
#if F_27 ( V_81 )
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
case - V_87 :
case - V_88 :
F_8 ( L_4 , V_34 ,
V_59 ) ;
F_28 ( V_63 -> V_89 , V_59 ) ;
goto V_74;
#endif
case - V_32 :
if ( V_61 -> V_50 > V_90 ) {
V_51 = - V_33 ;
break;
}
case - V_91 :
F_29 ( V_14 , V_92 ) ;
case - V_93 :
case - V_19 :
case - V_20 :
V_61 -> V_67 = 1 ;
return 0 ;
case - V_94 :
case - V_95 :
V_61 -> V_69 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_96 & V_97 ) {
V_14 -> V_96 &= ~ V_97 ;
V_61 -> V_69 = 1 ;
F_30 ( V_98 L_5
L_6
L_7
L_8 ,
V_14 -> V_62 -> V_99 ) ;
}
}
return F_7 ( V_51 ) ;
V_74:
V_61 -> V_68 = 1 ;
return 0 ;
}
int F_31 ( struct V_13 * V_14 , int V_59 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
int V_51 ;
V_51 = F_21 ( V_14 , V_59 , V_61 ) ;
if ( V_61 -> V_67 ) {
V_51 = F_17 ( V_14 -> V_100 , & V_61 -> V_50 ) ;
goto V_101;
}
if ( V_61 -> V_68 ) {
V_51 = F_32 ( V_63 ) ;
if ( F_33 ( V_102 , & V_14 -> V_103 ) )
return - V_35 ;
goto V_101;
}
return V_51 ;
V_101:
if ( V_51 == 0 )
V_61 -> V_69 = 1 ;
return V_51 ;
}
static int
F_34 ( struct V_104 * V_105 , struct V_13 * V_14 ,
int V_59 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
int V_51 ;
V_51 = F_21 ( V_14 , V_59 , V_61 ) ;
if ( V_61 -> V_67 ) {
F_35 ( V_105 , F_16 ( & V_61 -> V_50 ) ) ;
goto V_101;
}
if ( V_61 -> V_68 ) {
F_36 ( & V_63 -> V_106 , V_105 , NULL ) ;
if ( F_33 ( V_107 , & V_63 -> V_108 ) == 0 )
F_37 ( & V_63 -> V_106 , V_105 ) ;
goto V_101;
}
if ( F_33 ( V_102 , & V_14 -> V_103 ) )
V_51 = - V_35 ;
return V_51 ;
V_101:
if ( V_51 == 0 )
V_61 -> V_69 = 1 ;
return V_51 ;
}
static int
F_38 ( struct V_104 * V_105 , struct V_13 * V_14 ,
struct V_64 * V_65 , long * V_50 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
} ;
if ( V_105 -> V_109 >= 0 )
return 0 ;
if ( V_50 )
V_61 . V_50 = * V_50 ;
V_105 -> V_109 = F_34 ( V_105 , V_14 ,
V_105 -> V_109 ,
& V_61 ) ;
if ( V_61 . V_67 && V_50 )
* V_50 = V_61 . V_50 ;
if ( V_61 . V_69 )
return - V_110 ;
return 0 ;
}
static bool F_39 ( struct V_62 * V_63 )
{
T_5 V_111 = V_63 -> V_112 -> V_113 -> V_114 ;
if ( V_111 == V_115 ||
V_111 == V_116 )
return true ;
return false ;
}
static void F_40 ( struct V_62 * V_63 , unsigned long V_117 )
{
F_41 ( & V_63 -> V_118 ) ;
if ( F_42 ( V_63 -> V_119 , V_117 ) )
V_63 -> V_119 = V_117 ;
F_43 ( & V_63 -> V_118 ) ;
}
static void F_44 ( const struct V_13 * V_14 , unsigned long V_117 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
if ( ! F_45 ( V_63 ) )
F_40 ( V_63 , V_117 ) ;
}
void F_46 ( struct V_120 * args ,
struct V_121 * V_56 , int V_122 )
{
args -> V_123 = NULL ;
args -> V_124 = V_122 ;
args -> V_125 = 0 ;
V_56 -> V_126 = NULL ;
}
static void F_47 ( struct V_120 * args )
{
args -> V_125 = 1 ;
}
int F_48 ( struct V_127 * V_128 ,
struct V_120 * args ,
struct V_121 * V_56 ,
struct V_104 * V_105 )
{
struct V_129 * V_130 ;
if ( V_56 -> V_126 != NULL )
goto V_131;
F_41 ( & V_128 -> V_132 ) ;
if ( F_49 ( V_128 ) && ! args -> V_125 )
goto V_133;
V_130 = F_50 ( V_128 ) ;
if ( F_51 ( V_130 ) ) {
if ( V_130 == F_52 ( - V_134 ) )
V_105 -> V_135 = V_90 >> 2 ;
goto V_133;
}
F_43 ( & V_128 -> V_132 ) ;
args -> V_123 = V_130 ;
V_56 -> V_126 = V_130 ;
V_131:
F_53 ( V_105 ) ;
return 0 ;
V_133:
if ( args -> V_125 )
F_54 ( & V_128 -> V_136 , V_105 ,
NULL , V_137 ) ;
else
F_36 ( & V_128 -> V_136 , V_105 , NULL ) ;
F_43 ( & V_128 -> V_132 ) ;
return - V_110 ;
}
static void F_55 ( struct V_121 * V_56 )
{
struct V_129 * V_130 = V_56 -> V_126 ;
struct V_127 * V_128 ;
V_128 = V_130 -> V_138 ;
F_41 ( & V_128 -> V_132 ) ;
if ( ! F_56 ( V_128 , V_130 ) )
F_57 ( V_128 , V_130 ) ;
F_43 ( & V_128 -> V_132 ) ;
V_56 -> V_126 = NULL ;
}
static int F_58 ( struct V_104 * V_105 ,
struct V_121 * V_56 )
{
if ( V_56 -> V_126 != NULL )
F_55 ( V_56 ) ;
return 1 ;
}
static void F_59 ( struct V_121 * V_56 )
{
struct V_139 * V_140 ;
struct V_127 * V_128 ;
struct V_129 * V_130 = V_56 -> V_126 ;
bool V_141 = false ;
V_128 = V_130 -> V_138 ;
V_140 = V_128 -> V_140 ;
if ( V_130 -> V_142 )
V_130 -> V_143 ++ ;
V_130 -> V_142 = 0 ;
F_41 ( & V_128 -> V_132 ) ;
if ( V_128 -> V_144 > V_128 -> V_145 )
V_141 = true ;
if ( F_56 ( V_128 , V_130 ) ) {
V_141 = false ;
goto V_146;
}
F_57 ( V_128 , V_130 ) ;
if ( V_128 -> V_144 != V_147 )
V_141 = false ;
V_146:
F_43 ( & V_128 -> V_132 ) ;
V_56 -> V_126 = NULL ;
if ( V_141 )
F_60 ( V_140 -> V_63 ) ;
if ( F_61 ( & V_128 -> V_148 ) )
F_62 ( & V_128 -> V_148 ) ;
}
static int F_63 ( struct V_104 * V_105 ,
struct V_121 * V_56 )
{
struct V_139 * V_140 ;
struct V_129 * V_130 = V_56 -> V_126 ;
struct V_62 * V_63 ;
bool V_149 = false ;
int V_51 = 1 ;
if ( V_130 == NULL )
goto V_150;
if ( ! F_64 ( V_105 ) )
goto V_151;
V_140 = V_130 -> V_138 -> V_140 ;
if ( V_130 -> V_149 ) {
V_130 -> V_149 = 0 ;
V_149 = true ;
}
F_65 ( V_140 , V_56 ) ;
switch ( V_56 -> V_152 ) {
case 0 :
V_130 -> V_142 = 1 ;
V_63 = V_140 -> V_63 ;
F_40 ( V_63 , V_56 -> V_153 ) ;
F_66 ( V_63 , V_56 -> V_154 ) ;
F_67 ( V_130 -> V_138 , V_130 , V_56 ) ;
break;
case 1 :
V_130 -> V_149 = 1 ;
goto V_151;
case - V_91 :
F_8 ( L_9 ,
V_34 ,
V_130 -> V_155 ,
V_130 -> V_143 ) ;
goto V_101;
case - V_83 :
goto V_156;
case - V_88 :
if ( V_149 ) {
++ V_130 -> V_143 ;
goto V_156;
}
if ( V_130 -> V_143 != 1 ) {
V_130 -> V_143 = 1 ;
goto V_156;
}
break;
case - V_87 :
++ V_130 -> V_143 ;
goto V_156;
default:
V_130 -> V_142 = 1 ;
}
V_151:
F_8 ( L_10 , V_34 , V_56 -> V_152 ) ;
V_150:
return V_51 ;
V_156:
if ( F_68 ( V_105 ) ) {
F_59 ( V_56 ) ;
V_105 -> V_109 = 0 ;
V_51 = 0 ;
}
goto V_151;
V_101:
if ( ! F_69 ( V_105 ) )
goto V_151;
F_35 ( V_105 , V_52 ) ;
return 0 ;
}
int F_70 ( struct V_104 * V_105 , struct V_121 * V_56 )
{
if ( ! F_63 ( V_105 , V_56 ) )
return 0 ;
if ( V_56 -> V_126 != NULL )
F_59 ( V_56 ) ;
return 1 ;
}
static int F_71 ( struct V_104 * V_105 , struct V_121 * V_56 )
{
if ( V_56 -> V_126 == NULL )
return 1 ;
if ( V_56 -> V_126 -> V_138 -> V_140 != NULL )
return F_63 ( V_105 , V_56 ) ;
return F_58 ( V_105 , V_56 ) ;
}
static void F_72 ( struct V_121 * V_56 )
{
if ( V_56 -> V_126 != NULL ) {
if ( V_56 -> V_126 -> V_138 -> V_140 != NULL )
F_59 ( V_56 ) ;
else
F_55 ( V_56 ) ;
}
}
int F_73 ( struct V_104 * V_105 , struct V_121 * V_56 )
{
if ( V_56 -> V_126 == NULL )
return 1 ;
if ( ! V_56 -> V_126 -> V_138 -> V_140 )
return F_58 ( V_105 , V_56 ) ;
return F_70 ( V_105 , V_56 ) ;
}
int F_74 ( struct V_139 * V_140 ,
struct V_120 * args ,
struct V_121 * V_56 ,
struct V_104 * V_105 )
{
struct V_129 * V_130 ;
struct V_127 * V_128 ;
F_8 ( L_11 , V_34 ) ;
if ( V_56 -> V_126 != NULL )
goto V_157;
V_128 = & V_140 -> V_158 ;
V_105 -> V_135 = 0 ;
F_41 ( & V_128 -> V_132 ) ;
if ( F_33 ( V_159 , & V_128 -> V_160 ) &&
! args -> V_125 ) {
F_8 ( L_12 , V_34 ) ;
goto V_133;
}
V_130 = F_50 ( V_128 ) ;
if ( F_51 ( V_130 ) ) {
if ( V_130 == F_52 ( - V_134 ) )
V_105 -> V_135 = V_90 >> 2 ;
F_8 ( L_13 , V_34 ) ;
goto V_133;
}
F_43 ( & V_128 -> V_132 ) ;
args -> V_123 = V_130 ;
F_8 ( L_14 , V_34 ,
V_130 -> V_155 , V_130 -> V_143 ) ;
V_56 -> V_126 = V_130 ;
V_56 -> V_153 = V_161 ;
V_56 -> V_154 = 0 ;
V_56 -> V_152 = 1 ;
F_75 ( V_140 , args ) ;
V_157:
F_53 ( V_105 ) ;
return 0 ;
V_133:
if ( args -> V_125 )
F_54 ( & V_128 -> V_136 , V_105 ,
NULL , V_137 ) ;
else
F_36 ( & V_128 -> V_136 , V_105 , NULL ) ;
F_43 ( & V_128 -> V_132 ) ;
return - V_110 ;
}
static int F_76 ( const struct V_13 * V_14 ,
struct V_120 * args ,
struct V_121 * V_56 ,
struct V_104 * V_105 )
{
struct V_139 * V_140 = F_77 ( V_14 ) ;
int V_51 = 0 ;
if ( ! V_140 )
return F_48 ( V_14 -> V_62 -> V_162 ,
args , V_56 , V_105 ) ;
F_8 ( L_15 ,
V_34 , V_140 -> V_63 , V_140 , V_56 -> V_126 ?
V_56 -> V_126 -> V_155 : V_147 ) ;
V_51 = F_74 ( V_140 , args , V_56 , V_105 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_78 ( struct V_104 * V_105 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
struct V_139 * V_140 = F_77 ( V_165 -> V_166 ) ;
F_8 ( L_17 , V_34 , V_165 -> V_166 ) ;
F_74 ( V_140 , V_165 -> V_167 , V_165 -> V_168 , V_105 ) ;
}
static void F_79 ( struct V_104 * V_105 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_70 ( V_105 , V_165 -> V_168 ) ;
}
static int F_76 ( const struct V_13 * V_14 ,
struct V_120 * args ,
struct V_121 * V_56 ,
struct V_104 * V_105 )
{
return F_48 ( V_14 -> V_62 -> V_162 ,
args , V_56 , V_105 ) ;
}
static int F_71 ( struct V_104 * V_105 , struct V_121 * V_56 )
{
return F_58 ( V_105 , V_56 ) ;
}
static void F_72 ( struct V_121 * V_56 )
{
if ( V_56 -> V_126 != NULL )
F_55 ( V_56 ) ;
}
int F_73 ( struct V_104 * V_105 ,
struct V_121 * V_56 )
{
return F_58 ( V_105 , V_56 ) ;
}
static void F_80 ( struct V_104 * V_105 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_76 ( V_165 -> V_166 ,
V_165 -> V_167 , V_165 -> V_168 , V_105 ) ;
}
static void F_81 ( struct V_104 * V_105 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_73 ( V_105 , V_165 -> V_168 ) ;
}
static int F_82 ( struct V_54 * V_55 ,
struct V_13 * V_14 ,
struct V_169 * V_170 ,
struct V_120 * args ,
struct V_121 * V_56 )
{
int V_51 ;
struct V_104 * V_105 ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_164 V_165 = {
. V_166 = V_14 ,
. V_167 = args ,
. V_168 = V_56 ,
} ;
struct V_171 V_172 = {
. V_173 = V_55 ,
. V_169 = V_170 ,
. V_174 = V_63 -> V_175 -> V_176 ,
. V_177 = & V_165
} ;
V_105 = F_83 ( & V_172 ) ;
if ( F_51 ( V_105 ) )
V_51 = F_84 ( V_105 ) ;
else {
V_51 = V_105 -> V_109 ;
F_85 ( V_105 ) ;
}
return V_51 ;
}
int F_86 ( struct V_54 * V_55 ,
struct V_13 * V_14 ,
struct V_169 * V_170 ,
struct V_120 * args ,
struct V_121 * V_56 ,
int V_122 )
{
F_46 ( args , V_56 , V_122 ) ;
return F_82 ( V_55 , V_14 , V_170 , args , V_56 ) ;
}
static void F_87 ( struct V_2 * V_3 , struct V_178 * V_179 )
{
struct V_180 * V_181 = F_88 ( V_3 ) ;
F_41 ( & V_3 -> V_182 ) ;
V_181 -> V_183 |= V_184 | V_185 ;
if ( ! V_179 -> V_186 || V_179 -> V_187 != V_3 -> V_188 )
F_89 ( V_3 ) ;
V_3 -> V_188 = V_179 -> V_189 ;
V_181 -> V_190 = F_90 () ;
F_91 ( V_3 ) ;
F_43 ( & V_3 -> V_182 ) ;
}
static bool F_92 ( struct V_13 * V_14 ,
int V_8 , struct V_60 * V_61 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_96 & V_191 ) )
return false ;
V_14 -> V_96 &= ~ V_191 ;
V_61 -> V_69 = 1 ;
return true ;
}
static T_1
F_93 ( struct V_13 * V_14 ,
T_6 V_192 , int V_193 )
{
T_1 V_56 = 0 ;
switch ( V_192 & ( V_194 | V_195 ) ) {
case V_194 :
V_56 = V_196 ;
break;
case V_195 :
V_56 = V_197 ;
break;
case V_194 | V_195 :
V_56 = V_198 ;
}
if ( ! ( V_14 -> V_96 & V_191 ) )
goto V_151;
if ( V_193 & V_199 )
V_56 |= V_200 ;
V_151:
return V_56 ;
}
static enum V_201
F_94 ( struct V_13 * V_14 ,
enum V_201 V_202 )
{
if ( V_14 -> V_96 & V_191 )
return V_202 ;
switch ( V_202 ) {
default:
return V_202 ;
case V_203 :
return V_204 ;
case V_205 :
return V_206 ;
case V_207 :
return V_208 ;
}
}
static void F_95 ( struct V_209 * V_41 )
{
V_41 -> V_210 . V_211 = & V_41 -> V_211 ;
V_41 -> V_210 . V_212 = V_41 -> V_212 ;
V_41 -> V_210 . V_213 = V_41 -> V_214 . V_213 ;
V_41 -> V_215 . V_213 = V_41 -> V_216 . V_213 ;
V_41 -> V_210 . V_14 = V_41 -> V_214 . V_14 ;
V_41 -> V_210 . V_217 = V_41 -> V_214 . V_218 ;
F_96 ( & V_41 -> V_211 ) ;
F_97 ( & V_41 -> V_211 , & V_41 -> V_219 , & V_41 -> V_220 ) ;
}
static struct V_209 * F_98 ( struct V_4 * V_4 ,
struct V_221 * V_222 , T_6 V_192 , int V_223 ,
const struct V_5 * V_224 ,
struct V_1 * V_7 ,
enum V_201 V_202 ,
T_7 V_225 )
{
struct V_4 * V_226 = F_99 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_226 ) ;
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_227 * ( * V_228 ) ( struct V_229 * , T_7 ) ;
struct V_209 * V_41 ;
V_41 = F_101 ( sizeof( * V_41 ) , V_225 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_212 = F_102 ( V_14 , V_225 ) ;
if ( F_51 ( V_41 -> V_212 ) )
goto V_230;
V_41 -> V_231 = F_102 ( V_14 , V_225 ) ;
if ( F_51 ( V_41 -> V_231 ) )
goto V_232;
V_228 = V_14 -> V_62 -> V_175 -> V_228 ;
V_41 -> V_214 . V_213 = V_228 ( & V_222 -> V_233 , V_225 ) ;
if ( F_51 ( V_41 -> V_214 . V_213 ) )
goto V_234;
F_103 ( V_4 -> V_235 ) ;
V_41 -> V_4 = F_104 ( V_4 ) ;
V_41 -> V_3 = V_226 ;
V_41 -> V_236 = V_222 ;
F_105 ( & V_222 -> V_237 ) ;
V_41 -> V_214 . V_238 = V_223 ;
V_41 -> V_214 . V_192 = V_192 & ( V_194 | V_195 ) ;
V_41 -> V_214 . V_239 = F_93 ( V_14 ,
V_192 , V_223 ) ;
if ( ! ( V_223 & V_240 ) ) {
V_41 -> V_214 . V_218 = V_241 | V_242 |
V_243 | V_244 ;
}
V_41 -> V_214 . V_245 = V_14 -> V_62 -> V_246 ;
V_41 -> V_214 . V_247 . V_248 = F_106 ( V_222 -> V_233 . V_248 ) ;
V_41 -> V_214 . V_247 . V_249 = V_222 -> V_233 . V_250 ;
V_41 -> V_214 . V_251 = & V_4 -> V_11 ;
V_41 -> V_214 . V_14 = V_14 ;
V_41 -> V_214 . V_252 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_214 . V_253 = & V_254 [ 0 ] ;
V_41 -> V_214 . V_7 = F_107 ( V_41 -> V_231 , V_7 ) ;
V_41 -> V_214 . V_202 = F_94 ( V_14 , V_202 ) ;
switch ( V_41 -> V_214 . V_202 ) {
case V_204 :
case V_206 :
case V_208 :
V_41 -> V_214 . V_255 = F_108 ( V_3 ) ;
break;
case V_256 :
case V_203 :
case V_205 :
case V_207 :
V_41 -> V_214 . V_255 = F_108 ( F_14 ( V_4 ) ) ;
}
if ( V_224 != NULL && V_224 -> V_257 != 0 ) {
T_8 V_258 [ 2 ] ;
V_41 -> V_214 . V_259 . V_224 = & V_41 -> V_224 ;
memcpy ( & V_41 -> V_224 , V_224 , sizeof( V_41 -> V_224 ) ) ;
V_258 [ 0 ] = V_161 ;
V_258 [ 1 ] = V_57 -> V_260 ;
memcpy ( V_41 -> V_214 . V_259 . V_37 . V_165 , V_258 ,
sizeof( V_41 -> V_214 . V_259 . V_37 . V_165 ) ) ;
}
V_41 -> V_216 . V_255 = & V_41 -> V_210 . V_255 ;
V_41 -> V_216 . V_66 = & V_41 -> V_210 . V_66 ;
V_41 -> V_216 . V_213 = V_41 -> V_214 . V_213 ;
F_95 ( V_41 ) ;
F_109 ( & V_41 -> V_261 ) ;
return V_41 ;
V_234:
F_110 ( V_41 -> V_231 ) ;
V_232:
F_110 ( V_41 -> V_212 ) ;
V_230:
F_111 ( V_41 ) ;
V_8:
F_112 ( V_226 ) ;
return NULL ;
}
static void F_113 ( struct V_261 * V_261 )
{
struct V_209 * V_41 = F_114 ( V_261 ,
struct V_209 , V_261 ) ;
struct V_262 * V_263 = V_41 -> V_4 -> V_235 ;
F_115 ( V_41 -> V_214 . V_213 ) ;
F_72 ( & V_41 -> V_210 . V_168 ) ;
if ( V_41 -> V_65 != NULL )
F_116 ( V_41 -> V_65 ) ;
F_117 ( V_41 -> V_236 ) ;
F_110 ( V_41 -> V_231 ) ;
F_110 ( V_41 -> V_212 ) ;
F_112 ( V_41 -> V_3 ) ;
F_112 ( V_41 -> V_4 ) ;
F_118 ( V_263 ) ;
F_119 ( & V_41 -> V_211 ) ;
F_111 ( V_41 -> V_211 . V_264 ) ;
F_111 ( V_41 ) ;
}
static void F_120 ( struct V_209 * V_41 )
{
if ( V_41 != NULL )
F_121 ( & V_41 -> V_261 , F_113 ) ;
}
static int F_122 ( struct V_104 * V_105 )
{
int V_51 ;
V_51 = F_123 ( V_105 ) ;
return V_51 ;
}
static bool F_124 ( struct V_64 * V_65 ,
T_6 V_192 )
{
switch( V_192 & ( V_194 | V_195 ) ) {
case V_194 | V_195 :
return V_65 -> V_265 != 0 ;
case V_195 :
return V_65 -> V_266 != 0 ;
case V_194 :
return V_65 -> V_267 != 0 ;
}
F_125 ( 1 ) ;
return false ;
}
static int F_126 ( struct V_64 * V_65 , T_6 V_268 , int V_269 )
{
int V_51 = 0 ;
if ( V_269 & ( V_240 | V_270 ) )
goto V_151;
switch ( V_268 & ( V_194 | V_195 ) ) {
case V_194 :
V_51 |= F_33 ( V_271 , & V_65 -> V_223 ) != 0
&& V_65 -> V_267 != 0 ;
break;
case V_195 :
V_51 |= F_33 ( V_272 , & V_65 -> V_223 ) != 0
&& V_65 -> V_266 != 0 ;
break;
case V_194 | V_195 :
V_51 |= F_33 ( V_273 , & V_65 -> V_223 ) != 0
&& V_65 -> V_265 != 0 ;
}
V_151:
return V_51 ;
}
static int F_127 ( struct V_274 * V_275 , T_6 V_192 ,
enum V_201 V_202 )
{
if ( V_275 == NULL )
return 0 ;
if ( ( V_275 -> type & V_192 ) != V_192 )
return 0 ;
if ( F_33 ( V_276 , & V_275 -> V_223 ) )
return 0 ;
switch ( V_202 ) {
case V_204 :
case V_203 :
break;
case V_256 :
if ( ! F_33 ( V_277 , & V_275 -> V_223 ) )
break;
default:
return 0 ;
}
F_128 ( V_275 ) ;
return 1 ;
}
static void F_129 ( struct V_64 * V_65 , T_6 V_192 )
{
switch ( V_192 ) {
case V_195 :
V_65 -> V_266 ++ ;
break;
case V_194 :
V_65 -> V_267 ++ ;
break;
case V_194 | V_195 :
V_65 -> V_265 ++ ;
}
F_130 ( V_65 , V_65 -> V_65 | V_192 ) ;
}
static void F_131 ( struct V_64 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_236 -> V_278 -> V_62 ;
bool V_279 = false ;
if ( F_132 ( V_271 , & V_65 -> V_223 ) && V_65 -> V_267 )
V_279 = true ;
if ( F_132 ( V_272 , & V_65 -> V_223 ) && V_65 -> V_266 )
V_279 = true ;
if ( F_132 ( V_273 , & V_65 -> V_223 ) && V_65 -> V_265 )
V_279 = true ;
if ( V_279 )
F_133 ( V_63 , V_65 ) ;
}
static bool F_134 ( struct V_64 * V_65 ,
T_4 * V_66 )
{
if ( F_135 ( V_280 , & V_65 -> V_223 ) == 0 )
return true ;
if ( ! F_136 ( V_66 , & V_65 -> V_281 ) ) {
F_131 ( V_65 ) ;
return true ;
}
if ( F_137 ( V_66 , & V_65 -> V_281 ) )
return true ;
return false ;
}
static void F_138 ( struct V_64 * V_65 )
{
if ( ! ( V_65 -> V_266 || V_65 -> V_267 || V_65 -> V_265 ) )
return;
if ( V_65 -> V_266 )
F_139 ( V_272 , & V_65 -> V_223 ) ;
if ( V_65 -> V_267 )
F_139 ( V_271 , & V_65 -> V_223 ) ;
if ( V_65 -> V_265 )
F_139 ( V_273 , & V_65 -> V_223 ) ;
F_139 ( V_280 , & V_65 -> V_223 ) ;
}
static void F_140 ( struct V_64 * V_65 ,
T_4 * V_282 ,
T_4 * V_66 , T_6 V_192 )
{
F_141 ( V_273 , & V_65 -> V_223 ) ;
switch ( V_192 & ( V_194 | V_195 ) ) {
case V_195 :
F_141 ( V_271 , & V_65 -> V_223 ) ;
break;
case V_194 :
F_141 ( V_272 , & V_65 -> V_223 ) ;
break;
case 0 :
F_141 ( V_271 , & V_65 -> V_223 ) ;
F_141 ( V_272 , & V_65 -> V_223 ) ;
F_141 ( V_280 , & V_65 -> V_223 ) ;
}
if ( V_66 == NULL )
return;
if ( ! F_136 ( V_282 , & V_65 -> V_281 ) ||
( F_136 ( V_66 , & V_65 -> V_281 ) &&
! F_137 ( V_66 , & V_65 -> V_281 ) ) ) {
F_138 ( V_65 ) ;
return;
}
if ( F_33 ( V_283 , & V_65 -> V_223 ) == 0 )
F_142 ( & V_65 -> V_66 , V_66 ) ;
F_142 ( & V_65 -> V_281 , V_66 ) ;
}
static void F_143 ( struct V_64 * V_65 ,
T_4 * V_282 ,
T_4 * V_66 , T_6 V_192 )
{
F_144 ( & V_65 -> V_284 ) ;
F_140 ( V_65 , V_282 , V_66 , V_192 ) ;
F_145 ( & V_65 -> V_284 ) ;
if ( F_33 ( V_285 , & V_65 -> V_223 ) )
F_146 ( V_65 -> V_236 -> V_278 -> V_62 ) ;
}
static void F_147 ( struct V_64 * V_65 , T_4 * V_66 , T_6 V_192 )
{
switch ( V_192 ) {
case V_194 :
F_139 ( V_271 , & V_65 -> V_223 ) ;
break;
case V_195 :
F_139 ( V_272 , & V_65 -> V_223 ) ;
break;
case V_194 | V_195 :
F_139 ( V_273 , & V_65 -> V_223 ) ;
}
if ( ! F_134 ( V_65 , V_66 ) )
return;
if ( F_33 ( V_283 , & V_65 -> V_223 ) == 0 )
F_142 ( & V_65 -> V_66 , V_66 ) ;
F_142 ( & V_65 -> V_281 , V_66 ) ;
}
static void F_148 ( struct V_64 * V_65 , T_4 * V_281 , const T_4 * V_286 , T_6 V_192 )
{
F_41 ( & V_65 -> V_236 -> V_287 ) ;
F_144 ( & V_65 -> V_284 ) ;
if ( V_286 != NULL ) {
F_142 ( & V_65 -> V_66 , V_286 ) ;
F_139 ( V_283 , & V_65 -> V_223 ) ;
}
if ( V_281 != NULL )
F_147 ( V_65 , V_281 , V_192 ) ;
F_145 ( & V_65 -> V_284 ) ;
F_129 ( V_65 , V_192 ) ;
F_43 ( & V_65 -> V_236 -> V_287 ) ;
}
static int F_149 ( struct V_64 * V_65 , T_4 * V_281 , T_4 * V_275 , T_6 V_192 )
{
struct V_180 * V_181 = F_88 ( V_65 -> V_2 ) ;
struct V_274 * V_288 ;
int V_51 = 0 ;
V_192 &= ( V_194 | V_195 ) ;
F_150 () ;
V_288 = F_151 ( V_181 -> V_275 ) ;
if ( V_288 == NULL )
goto V_289;
F_41 ( & V_288 -> V_290 ) ;
if ( F_151 ( V_181 -> V_275 ) != V_288 ||
F_33 ( V_276 , & V_288 -> V_223 ) ||
( V_288 -> type & V_192 ) != V_192 )
goto V_291;
if ( V_275 == NULL )
V_275 = & V_288 -> V_66 ;
else if ( ! F_152 ( & V_288 -> V_66 , V_275 ) )
goto V_291;
F_128 ( V_288 ) ;
F_148 ( V_65 , V_281 , & V_288 -> V_66 , V_192 ) ;
V_51 = 1 ;
V_291:
F_43 ( & V_288 -> V_290 ) ;
V_289:
F_153 () ;
if ( ! V_51 && V_281 != NULL ) {
F_148 ( V_65 , V_281 , NULL , V_192 ) ;
V_51 = 1 ;
}
if ( F_33 ( V_285 , & V_65 -> V_223 ) )
F_146 ( V_65 -> V_236 -> V_278 -> V_62 ) ;
return V_51 ;
}
static bool F_154 ( struct V_292 * V_293 ,
const T_4 * V_66 )
{
struct V_64 * V_65 = V_293 -> V_294 ;
bool V_51 = false ;
F_41 ( & V_65 -> V_295 ) ;
if ( ! F_136 ( V_66 , & V_293 -> V_296 ) )
goto V_297;
if ( ! F_137 ( V_66 , & V_293 -> V_296 ) )
goto V_297;
F_142 ( & V_293 -> V_296 , V_66 ) ;
V_51 = true ;
V_297:
F_43 ( & V_65 -> V_295 ) ;
return V_51 ;
}
static void F_155 ( struct V_2 * V_2 , T_6 V_192 )
{
struct V_274 * V_275 ;
F_150 () ;
V_275 = F_151 ( F_88 ( V_2 ) -> V_275 ) ;
if ( V_275 == NULL || ( V_275 -> type & V_192 ) == V_192 ) {
F_153 () ;
return;
}
F_153 () ;
F_156 ( V_2 ) ;
}
static struct V_64 * F_157 ( struct V_209 * V_298 )
{
struct V_64 * V_65 = V_298 -> V_65 ;
struct V_180 * V_181 = F_88 ( V_65 -> V_2 ) ;
struct V_274 * V_275 ;
int V_269 = V_298 -> V_214 . V_238 ;
T_6 V_192 = V_298 -> V_214 . V_192 ;
enum V_201 V_202 = V_298 -> V_214 . V_202 ;
T_4 V_66 ;
int V_51 = - V_110 ;
for (; ; ) {
F_41 ( & V_65 -> V_236 -> V_287 ) ;
if ( F_126 ( V_65 , V_192 , V_269 ) ) {
F_129 ( V_65 , V_192 ) ;
F_43 ( & V_65 -> V_236 -> V_287 ) ;
goto V_299;
}
F_43 ( & V_65 -> V_236 -> V_287 ) ;
F_150 () ;
V_275 = F_151 ( V_181 -> V_275 ) ;
if ( ! F_127 ( V_275 , V_192 , V_202 ) ) {
F_153 () ;
break;
}
F_142 ( & V_66 , & V_275 -> V_66 ) ;
F_153 () ;
F_158 ( V_298 -> V_214 . V_213 ) ;
if ( ! V_298 -> V_300 ) {
V_51 = F_159 ( V_65 -> V_2 , V_65 -> V_236 -> V_301 , V_269 ) ;
if ( V_51 != 0 )
goto V_151;
}
V_51 = - V_110 ;
if ( F_149 ( V_65 , NULL , & V_66 , V_192 ) )
goto V_299;
}
V_151:
return F_52 ( V_51 ) ;
V_299:
F_105 ( & V_65 -> V_49 ) ;
return V_65 ;
}
static void
F_160 ( struct V_209 * V_165 , struct V_64 * V_65 )
{
struct V_62 * V_63 = F_100 ( V_65 -> V_2 ) -> V_62 ;
struct V_274 * V_275 ;
int V_302 = 0 ;
F_150 () ;
V_275 = F_151 ( F_88 ( V_65 -> V_2 ) -> V_275 ) ;
if ( V_275 )
V_302 = V_275 -> V_223 ;
F_153 () ;
switch ( V_165 -> V_214 . V_202 ) {
default:
break;
case V_206 :
case V_205 :
F_161 ( L_18
L_19
L_20 ,
V_63 -> V_99 ) ;
return;
}
if ( ( V_302 & 1UL << V_277 ) == 0 )
F_162 ( V_65 -> V_2 ,
V_165 -> V_236 -> V_301 ,
& V_165 -> V_210 ) ;
else
F_163 ( V_65 -> V_2 ,
V_165 -> V_236 -> V_301 ,
& V_165 -> V_210 ) ;
}
static struct V_64 *
F_164 ( struct V_209 * V_165 )
{
struct V_2 * V_2 = V_165 -> V_65 -> V_2 ;
struct V_64 * V_65 = V_165 -> V_65 ;
int V_51 ;
if ( ! V_165 -> V_303 ) {
if ( V_165 -> V_304 ) {
V_51 = V_165 -> V_304 ;
goto V_8;
}
goto V_305;
}
V_51 = F_165 ( V_2 , & V_165 -> V_211 ) ;
if ( V_51 )
goto V_8;
if ( V_165 -> V_210 . V_306 != 0 )
F_160 ( V_165 , V_65 ) ;
V_305:
F_149 ( V_65 , & V_165 -> V_210 . V_66 , NULL ,
V_165 -> V_214 . V_192 ) ;
F_105 ( & V_65 -> V_49 ) ;
return V_65 ;
V_8:
return F_52 ( V_51 ) ;
}
static struct V_64 *
F_166 ( struct V_209 * V_165 )
{
struct V_2 * V_2 ;
struct V_64 * V_65 = NULL ;
int V_51 ;
if ( ! V_165 -> V_303 ) {
V_65 = F_157 ( V_165 ) ;
F_167 ( V_165 -> V_65 ) ;
goto V_151;
}
V_51 = - V_110 ;
if ( ! ( V_165 -> V_211 . V_307 & V_308 ) )
goto V_8;
V_2 = F_168 ( V_165 -> V_3 -> V_235 , & V_165 -> V_210 . V_255 , & V_165 -> V_211 , V_165 -> V_212 ) ;
V_51 = F_84 ( V_2 ) ;
if ( F_51 ( V_2 ) )
goto V_8;
V_51 = - V_134 ;
V_65 = F_169 ( V_2 , V_165 -> V_236 ) ;
if ( V_65 == NULL )
goto V_309;
if ( V_165 -> V_210 . V_306 != 0 )
F_160 ( V_165 , V_65 ) ;
F_149 ( V_65 , & V_165 -> V_210 . V_66 , NULL ,
V_165 -> V_214 . V_192 ) ;
F_170 ( V_2 ) ;
V_151:
F_158 ( V_165 -> V_214 . V_213 ) ;
return V_65 ;
V_309:
F_170 ( V_2 ) ;
V_8:
return F_52 ( V_51 ) ;
}
static struct V_64 *
F_171 ( struct V_209 * V_165 )
{
struct V_64 * V_51 ;
if ( V_165 -> V_214 . V_202 == V_256 )
V_51 = F_164 ( V_165 ) ;
else
V_51 = F_166 ( V_165 ) ;
F_72 ( & V_165 -> V_210 . V_168 ) ;
return V_51 ;
}
static struct V_310 * F_172 ( struct V_64 * V_65 )
{
struct V_180 * V_181 = F_88 ( V_65 -> V_2 ) ;
struct V_310 * V_311 ;
F_41 ( & V_65 -> V_2 -> V_182 ) ;
F_173 (ctx, &nfsi->open_files, list) {
if ( V_311 -> V_65 != V_65 )
continue;
F_174 ( V_311 ) ;
F_43 ( & V_65 -> V_2 -> V_182 ) ;
return V_311 ;
}
F_43 ( & V_65 -> V_2 -> V_182 ) ;
return F_52 ( - V_312 ) ;
}
static struct V_209 * F_175 ( struct V_310 * V_311 ,
struct V_64 * V_65 , enum V_201 V_202 )
{
struct V_209 * V_298 ;
V_298 = F_98 ( V_311 -> V_4 , V_65 -> V_236 , 0 , 0 ,
NULL , NULL , V_202 , V_313 ) ;
if ( V_298 == NULL )
return F_52 ( - V_134 ) ;
V_298 -> V_65 = V_65 ;
F_105 ( & V_65 -> V_49 ) ;
return V_298 ;
}
static int F_176 ( struct V_209 * V_298 ,
T_6 V_192 )
{
struct V_64 * V_314 ;
int V_51 ;
if ( ! F_124 ( V_298 -> V_65 , V_192 ) )
return 0 ;
V_298 -> V_214 . V_238 = 0 ;
V_298 -> V_214 . V_192 = V_192 ;
V_298 -> V_214 . V_239 = F_93 (
F_177 ( V_298 -> V_4 -> V_235 ) ,
V_192 , 0 ) ;
memset ( & V_298 -> V_210 , 0 , sizeof( V_298 -> V_210 ) ) ;
memset ( & V_298 -> V_215 , 0 , sizeof( V_298 -> V_215 ) ) ;
F_95 ( V_298 ) ;
V_51 = F_178 ( V_298 ) ;
if ( V_51 != 0 )
return V_51 ;
V_314 = F_171 ( V_298 ) ;
if ( F_51 ( V_314 ) )
return F_84 ( V_314 ) ;
if ( V_314 != V_298 -> V_65 )
V_51 = - V_315 ;
F_179 ( V_314 , V_192 ) ;
return V_51 ;
}
static int F_180 ( struct V_209 * V_298 , struct V_64 * V_65 )
{
int V_51 ;
F_141 ( V_273 , & V_65 -> V_223 ) ;
F_141 ( V_272 , & V_65 -> V_223 ) ;
F_141 ( V_271 , & V_65 -> V_223 ) ;
F_141 ( V_283 , & V_65 -> V_223 ) ;
F_141 ( V_280 , & V_65 -> V_223 ) ;
F_181 () ;
V_51 = F_176 ( V_298 , V_194 | V_195 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_176 ( V_298 , V_195 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_176 ( V_298 , V_194 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( F_33 ( V_283 , & V_65 -> V_223 ) == 0 &&
! F_152 ( & V_65 -> V_66 , & V_65 -> V_281 ) ) {
F_144 ( & V_65 -> V_284 ) ;
if ( F_33 ( V_283 , & V_65 -> V_223 ) == 0 )
F_142 ( & V_65 -> V_66 , & V_65 -> V_281 ) ;
F_145 ( & V_65 -> V_284 ) ;
}
return 0 ;
}
static int F_182 ( struct V_310 * V_311 , struct V_64 * V_65 )
{
struct V_274 * V_275 ;
struct V_209 * V_298 ;
T_6 V_306 = 0 ;
int V_316 ;
V_298 = F_175 ( V_311 , V_65 ,
V_256 ) ;
if ( F_51 ( V_298 ) )
return F_84 ( V_298 ) ;
F_150 () ;
V_275 = F_151 ( F_88 ( V_65 -> V_2 ) -> V_275 ) ;
if ( V_275 != NULL && F_33 ( V_277 , & V_275 -> V_223 ) != 0 )
V_306 = V_275 -> type ;
F_153 () ;
V_298 -> V_214 . V_259 . V_306 = V_306 ;
V_316 = F_180 ( V_298 , V_65 ) ;
F_120 ( V_298 ) ;
return V_316 ;
}
static int F_183 ( struct V_310 * V_311 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_182 ( V_311 , V_65 ) ;
F_184 ( V_311 , 0 , V_8 ) ;
if ( F_92 ( V_14 , V_8 , & V_61 ) )
continue;
if ( V_8 != - V_91 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_185 ( struct V_221 * V_222 , struct V_64 * V_65 )
{
struct V_310 * V_311 ;
int V_51 ;
V_311 = F_172 ( V_65 ) ;
if ( F_51 ( V_311 ) )
return - V_110 ;
V_51 = F_183 ( V_311 , V_65 ) ;
F_186 ( V_311 ) ;
return V_51 ;
}
static int F_187 ( struct V_13 * V_14 , struct V_64 * V_65 , const T_4 * V_66 , int V_8 )
{
switch ( V_8 ) {
default:
F_30 ( V_317 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_312 :
case - V_110 :
case - V_315 :
break;
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
F_139 ( V_283 , & V_65 -> V_223 ) ;
F_28 ( V_14 -> V_62 -> V_89 , V_8 ) ;
return - V_110 ;
case - V_78 :
case - V_77 :
F_139 ( V_283 , & V_65 -> V_223 ) ;
case - V_76 :
F_24 ( V_14 -> V_62 ) ;
return - V_110 ;
case - V_79 :
F_25 ( V_14 ) ;
return - V_110 ;
case - V_80 :
F_26 ( V_14 -> V_62 ) ;
return - V_110 ;
case - V_71 :
case - V_72 :
case - V_73 :
case - V_70 :
F_188 ( V_65 -> V_2 ,
V_66 ) ;
F_23 ( V_14 , V_65 ) ;
return - V_110 ;
case - V_91 :
case - V_93 :
F_139 ( V_283 , & V_65 -> V_223 ) ;
F_189 ( 1 ) ;
return - V_110 ;
case - V_134 :
case - V_318 :
return 0 ;
}
return V_8 ;
}
int F_190 ( struct V_310 * V_311 ,
struct V_64 * V_65 , const T_4 * V_66 ,
T_6 type )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
struct V_209 * V_298 ;
int V_8 = 0 ;
V_298 = F_175 ( V_311 , V_65 ,
V_205 ) ;
if ( F_51 ( V_298 ) )
return F_84 ( V_298 ) ;
F_142 ( & V_298 -> V_214 . V_259 . V_275 , V_66 ) ;
F_144 ( & V_65 -> V_284 ) ;
F_142 ( & V_65 -> V_66 , & V_65 -> V_281 ) ;
F_145 ( & V_65 -> V_284 ) ;
F_141 ( V_283 , & V_65 -> V_223 ) ;
switch ( type & ( V_194 | V_195 ) ) {
case V_194 | V_195 :
case V_195 :
V_8 = F_176 ( V_298 , V_194 | V_195 ) ;
if ( V_8 )
break;
V_8 = F_176 ( V_298 , V_195 ) ;
if ( V_8 )
break;
case V_194 :
V_8 = F_176 ( V_298 , V_194 ) ;
}
F_120 ( V_298 ) ;
return F_187 ( V_14 , V_65 , V_66 , V_8 ) ;
}
static void F_191 ( struct V_104 * V_105 , void * V_163 )
{
struct V_209 * V_165 = V_163 ;
F_48 ( V_165 -> V_214 . V_14 -> V_62 -> V_162 ,
& V_165 -> V_216 . V_167 , & V_165 -> V_215 . V_168 , V_105 ) ;
}
static void F_192 ( struct V_104 * V_105 , void * V_163 )
{
struct V_209 * V_165 = V_163 ;
F_58 ( V_105 , & V_165 -> V_215 . V_168 ) ;
V_165 -> V_304 = V_105 -> V_109 ;
if ( V_165 -> V_304 == 0 ) {
F_142 ( & V_165 -> V_210 . V_66 , & V_165 -> V_215 . V_66 ) ;
F_193 ( & V_165 -> V_236 -> V_233 , 0 ) ;
F_44 ( V_165 -> V_210 . V_14 , V_165 -> V_117 ) ;
V_165 -> V_303 = 1 ;
}
}
static void F_194 ( void * V_163 )
{
struct V_209 * V_165 = V_163 ;
struct V_64 * V_65 = NULL ;
if ( V_165 -> V_319 == 0 )
goto V_320;
if ( ! V_165 -> V_303 )
goto V_320;
V_65 = F_171 ( V_165 ) ;
if ( ! F_51 ( V_65 ) )
F_179 ( V_65 , V_165 -> V_214 . V_192 ) ;
V_320:
F_120 ( V_165 ) ;
}
static int F_195 ( struct V_209 * V_165 )
{
struct V_13 * V_14 = F_100 ( F_14 ( V_165 -> V_3 ) ) ;
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_323 ] ,
. V_324 = & V_165 -> V_216 ,
. V_325 = & V_165 -> V_215 ,
. V_326 = V_165 -> V_236 -> V_301 ,
} ;
struct V_171 V_327 = {
. V_173 = V_14 -> V_100 ,
. V_169 = & V_170 ,
. V_174 = & V_328 ,
. V_177 = V_165 ,
. V_329 = V_330 ,
. V_223 = V_331 ,
} ;
int V_316 ;
F_46 ( & V_165 -> V_216 . V_167 , & V_165 -> V_215 . V_168 , 1 ) ;
F_196 ( & V_165 -> V_261 ) ;
V_165 -> V_303 = 0 ;
V_165 -> V_304 = 0 ;
V_165 -> V_117 = V_161 ;
if ( V_165 -> V_300 )
F_47 ( & V_165 -> V_216 . V_167 ) ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
V_316 = F_122 ( V_105 ) ;
if ( V_316 != 0 ) {
V_165 -> V_319 = 1 ;
F_197 () ;
} else
V_316 = V_165 -> V_304 ;
F_85 ( V_105 ) ;
return V_316 ;
}
static void F_198 ( struct V_104 * V_105 , void * V_163 )
{
struct V_209 * V_165 = V_163 ;
struct V_221 * V_222 = V_165 -> V_236 ;
struct V_62 * V_63 = V_222 -> V_278 -> V_62 ;
enum V_201 V_202 = V_165 -> V_214 . V_202 ;
if ( F_199 ( V_165 -> V_214 . V_213 , V_105 ) != 0 )
goto V_332;
if ( V_165 -> V_65 != NULL ) {
struct V_274 * V_275 ;
if ( F_126 ( V_165 -> V_65 , V_165 -> V_214 . V_192 , V_165 -> V_214 . V_238 ) )
goto V_333;
F_150 () ;
V_275 = F_151 ( F_88 ( V_165 -> V_65 -> V_2 ) -> V_275 ) ;
if ( F_127 ( V_275 , V_165 -> V_214 . V_192 , V_202 ) )
goto V_334;
F_153 () ;
}
V_165 -> V_214 . V_245 = V_63 -> V_246 ;
switch ( V_202 ) {
default:
break;
case V_256 :
case V_205 :
case V_207 :
V_165 -> V_214 . V_253 = & V_335 [ 0 ] ;
case V_203 :
V_105 -> V_336 . V_321 = & V_322 [ V_337 ] ;
F_200 ( & V_165 -> V_210 . V_255 , V_165 -> V_214 . V_255 ) ;
}
V_165 -> V_117 = V_161 ;
if ( F_76 ( V_165 -> V_214 . V_14 ,
& V_165 -> V_214 . V_167 ,
& V_165 -> V_210 . V_168 ,
V_105 ) != 0 )
F_158 ( V_165 -> V_214 . V_213 ) ;
V_165 -> V_214 . V_338 = V_339 ;
if ( V_165 -> V_214 . V_238 & V_240 ) {
V_165 -> V_214 . V_338 = V_340 ;
if ( F_201 ( V_63 ) )
V_165 -> V_214 . V_338 = V_341 ;
else if ( V_63 -> V_175 -> V_342 > 0 )
V_165 -> V_214 . V_338 = V_343 ;
}
return;
V_334:
F_167 ( V_165 -> V_65 ) ;
F_153 () ;
V_333:
V_105 -> V_344 = NULL ;
V_332:
F_73 ( V_105 , & V_165 -> V_210 . V_168 ) ;
}
static void F_202 ( struct V_104 * V_105 , void * V_163 )
{
struct V_209 * V_165 = V_163 ;
V_165 -> V_304 = V_105 -> V_109 ;
if ( ! F_71 ( V_105 , & V_165 -> V_210 . V_168 ) )
return;
if ( V_105 -> V_109 == 0 ) {
if ( V_165 -> V_210 . V_211 -> V_307 & V_345 ) {
switch ( V_165 -> V_210 . V_211 -> V_268 & V_346 ) {
case V_347 :
break;
case V_348 :
V_165 -> V_304 = - V_349 ;
break;
case V_350 :
V_165 -> V_304 = - V_351 ;
break;
default:
V_165 -> V_304 = - V_352 ;
}
}
F_44 ( V_165 -> V_210 . V_14 , V_165 -> V_117 ) ;
if ( ! ( V_165 -> V_210 . V_353 & V_354 ) )
F_193 ( & V_165 -> V_236 -> V_233 , 0 ) ;
}
V_165 -> V_303 = 1 ;
}
static void F_203 ( void * V_163 )
{
struct V_209 * V_165 = V_163 ;
struct V_64 * V_65 = NULL ;
if ( V_165 -> V_319 == 0 )
goto V_320;
if ( V_165 -> V_304 != 0 || ! V_165 -> V_303 )
goto V_320;
if ( V_165 -> V_210 . V_353 & V_354 )
goto V_320;
V_65 = F_171 ( V_165 ) ;
if ( ! F_51 ( V_65 ) )
F_179 ( V_65 , V_165 -> V_214 . V_192 ) ;
V_320:
F_120 ( V_165 ) ;
}
static int F_204 ( struct V_209 * V_165 , int V_355 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_356 * V_214 = & V_165 -> V_214 ;
struct V_357 * V_210 = & V_165 -> V_210 ;
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_358 ] ,
. V_324 = V_214 ,
. V_325 = V_210 ,
. V_326 = V_165 -> V_236 -> V_301 ,
} ;
struct V_171 V_327 = {
. V_173 = V_14 -> V_100 ,
. V_169 = & V_170 ,
. V_174 = & V_359 ,
. V_177 = V_165 ,
. V_329 = V_330 ,
. V_223 = V_331 ,
} ;
int V_316 ;
F_46 ( & V_214 -> V_167 , & V_210 -> V_168 , 1 ) ;
F_196 ( & V_165 -> V_261 ) ;
V_165 -> V_303 = 0 ;
V_165 -> V_304 = 0 ;
V_165 -> V_319 = 0 ;
V_165 -> V_300 = 0 ;
if ( V_355 ) {
F_47 ( & V_214 -> V_167 ) ;
V_165 -> V_300 = 1 ;
}
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
V_316 = F_122 ( V_105 ) ;
if ( V_316 != 0 ) {
V_165 -> V_319 = 1 ;
F_197 () ;
} else
V_316 = V_165 -> V_304 ;
F_85 ( V_105 ) ;
return V_316 ;
}
static int F_178 ( struct V_209 * V_165 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_357 * V_210 = & V_165 -> V_210 ;
int V_316 ;
V_316 = F_204 ( V_165 , 1 ) ;
if ( V_316 != 0 || ! V_165 -> V_303 )
return V_316 ;
F_205 ( F_100 ( V_3 ) , & V_165 -> V_211 ) ;
if ( V_210 -> V_353 & V_354 ) {
V_316 = F_195 ( V_165 ) ;
if ( V_316 != 0 )
return V_316 ;
}
return V_316 ;
}
static int F_206 ( struct V_326 * V_360 ,
struct V_209 * V_298 ,
struct V_64 * V_65 , T_6 V_192 ,
int V_193 )
{
struct V_361 V_362 ;
T_1 V_363 ;
if ( V_298 -> V_210 . V_364 == 0 )
return 0 ;
V_363 = 0 ;
if ( V_193 & V_365 ) {
V_363 = V_366 ;
} else if ( ( V_192 & V_194 ) && ! V_298 -> V_367 )
V_363 = V_368 ;
V_362 . V_360 = V_360 ;
V_362 . V_161 = V_161 ;
F_207 ( & V_362 , V_298 -> V_210 . V_369 ) ;
F_208 ( V_65 -> V_2 , & V_362 ) ;
if ( ( V_363 & ~ V_362 . V_363 & ( V_368 | V_366 ) ) == 0 )
return 0 ;
F_179 ( V_65 , V_192 ) ;
return - V_29 ;
}
static int F_209 ( struct V_209 * V_165 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_356 * V_214 = & V_165 -> V_214 ;
struct V_357 * V_210 = & V_165 -> V_210 ;
int V_316 ;
V_316 = F_204 ( V_165 , 0 ) ;
if ( ! V_165 -> V_303 )
return V_316 ;
if ( V_316 != 0 ) {
if ( V_316 == - V_26 &&
! ( V_214 -> V_238 & V_370 ) )
return - V_312 ;
return V_316 ;
}
F_205 ( V_14 , & V_165 -> V_211 ) ;
if ( V_214 -> V_238 & V_370 ) {
F_87 ( V_3 , & V_210 -> V_179 ) ;
if ( V_214 -> V_238 & V_240 )
V_165 -> V_367 = 1 ;
else if ( V_210 -> V_179 . V_187 != V_210 -> V_179 . V_189 )
V_165 -> V_367 = 1 ;
}
if ( ( V_210 -> V_353 & V_371 ) == 0 )
V_14 -> V_96 &= ~ V_372 ;
if( V_210 -> V_353 & V_354 ) {
V_316 = F_195 ( V_165 ) ;
if ( V_316 != 0 )
return V_316 ;
}
if ( ! ( V_210 -> V_211 -> V_307 & V_308 ) )
F_210 ( V_14 , & V_210 -> V_255 , V_210 -> V_211 , V_210 -> V_212 ) ;
return 0 ;
}
static int F_211 ( struct V_13 * V_14 )
{
return F_212 ( V_14 -> V_62 ) ;
}
static int F_213 ( struct V_310 * V_311 , struct V_64 * V_65 )
{
struct V_209 * V_298 ;
int V_51 ;
V_298 = F_175 ( V_311 , V_65 ,
V_203 ) ;
if ( F_51 ( V_298 ) )
return F_84 ( V_298 ) ;
V_51 = F_180 ( V_298 , V_65 ) ;
if ( V_51 == - V_315 )
F_214 ( V_311 -> V_4 ) ;
F_120 ( V_298 ) ;
return V_51 ;
}
static int F_215 ( struct V_310 * V_311 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_213 ( V_311 , V_65 ) ;
F_216 ( V_311 , 0 , V_8 ) ;
if ( F_92 ( V_14 , V_8 , & V_61 ) )
continue;
switch ( V_8 ) {
default:
goto V_151;
case - V_93 :
case - V_91 :
F_31 ( V_14 , V_8 , & V_61 ) ;
V_8 = 0 ;
}
} while ( V_61 . V_69 );
V_151:
return V_8 ;
}
static int F_217 ( struct V_221 * V_222 , struct V_64 * V_65 )
{
struct V_310 * V_311 ;
int V_51 ;
V_311 = F_172 ( V_65 ) ;
if ( F_51 ( V_311 ) )
return - V_110 ;
V_51 = F_215 ( V_311 , V_65 ) ;
F_186 ( V_311 ) ;
return V_51 ;
}
static void F_218 ( struct V_64 * V_65 )
{
F_219 ( V_65 -> V_2 ) ;
F_144 ( & V_65 -> V_284 ) ;
F_142 ( & V_65 -> V_66 , & V_65 -> V_281 ) ;
F_145 ( & V_65 -> V_284 ) ;
F_141 ( V_283 , & V_65 -> V_223 ) ;
}
static void F_220 ( struct V_64 * V_65 )
{
if ( F_221 ( F_88 ( V_65 -> V_2 ) -> V_275 ) != NULL )
F_218 ( V_65 ) ;
}
static int F_222 ( struct V_221 * V_222 , struct V_64 * V_65 )
{
F_220 ( V_65 ) ;
return F_217 ( V_222 , V_65 ) ;
}
static void F_223 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
T_4 V_66 ;
struct V_274 * V_275 ;
struct V_326 * V_360 ;
int V_316 ;
F_150 () ;
V_275 = F_151 ( F_88 ( V_65 -> V_2 ) -> V_275 ) ;
if ( V_275 == NULL ) {
F_153 () ;
return;
}
F_142 ( & V_66 , & V_275 -> V_66 ) ;
V_360 = F_224 ( V_275 -> V_360 ) ;
F_153 () ;
V_316 = F_225 ( V_14 , & V_66 , V_360 ) ;
F_226 ( V_65 , NULL , V_316 ) ;
if ( V_316 != V_373 ) {
if ( V_316 != - V_73 )
F_227 ( V_14 , & V_66 , V_360 ) ;
F_218 ( V_65 ) ;
}
F_228 ( V_360 ) ;
}
static int F_229 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
T_4 * V_66 = & V_65 -> V_281 ;
struct V_326 * V_360 = V_65 -> V_236 -> V_301 ;
int V_316 ;
if ( ( F_33 ( V_271 , & V_65 -> V_223 ) == 0 ) &&
( F_33 ( V_272 , & V_65 -> V_223 ) == 0 ) &&
( F_33 ( V_273 , & V_65 -> V_223 ) == 0 ) )
return - V_73 ;
V_316 = F_225 ( V_14 , V_66 , V_360 ) ;
F_230 ( V_65 , NULL , V_316 ) ;
if ( V_316 != V_373 ) {
if ( V_316 != - V_73 )
F_227 ( V_14 , V_66 , V_360 ) ;
F_141 ( V_271 , & V_65 -> V_223 ) ;
F_141 ( V_272 , & V_65 -> V_223 ) ;
F_141 ( V_273 , & V_65 -> V_223 ) ;
F_141 ( V_280 , & V_65 -> V_223 ) ;
}
return V_316 ;
}
static int F_231 ( struct V_221 * V_222 , struct V_64 * V_65 )
{
int V_316 ;
F_223 ( V_65 ) ;
V_316 = F_229 ( V_65 ) ;
if ( V_316 != V_373 )
V_316 = F_217 ( V_222 , V_65 ) ;
return V_316 ;
}
static inline void F_232 ( struct V_209 * V_298 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_374 = V_298 -> V_210 . V_374 ;
if ( ( V_374 [ 1 ] & V_375 ) &&
! ( V_6 -> V_257 & V_376 ) )
V_6 -> V_257 |= V_377 ;
if ( ( V_374 [ 1 ] & V_378 ) &&
! ( V_6 -> V_257 & V_379 ) )
V_6 -> V_257 |= V_380 ;
if ( ( V_374 [ 1 ] & V_381 ) )
V_6 -> V_257 &= ~ V_382 ;
if ( V_374 [ 2 ] & V_383 )
* V_7 = NULL ;
}
static int F_233 ( struct V_209 * V_298 ,
T_6 V_192 ,
int V_223 ,
struct V_310 * V_311 )
{
struct V_221 * V_222 = V_298 -> V_236 ;
struct V_13 * V_14 = V_222 -> V_278 ;
struct V_4 * V_4 ;
struct V_64 * V_65 ;
unsigned int V_384 ;
int V_51 ;
V_384 = F_234 ( & V_222 -> V_385 ) ;
V_51 = F_209 ( V_298 ) ;
if ( V_51 != 0 )
goto V_151;
V_65 = F_171 ( V_298 ) ;
V_51 = F_84 ( V_65 ) ;
if ( F_51 ( V_65 ) )
goto V_151;
if ( V_14 -> V_96 & V_372 )
F_139 ( V_386 , & V_65 -> V_223 ) ;
V_4 = V_298 -> V_4 ;
if ( F_235 ( V_4 ) ) {
struct V_4 * V_387 ;
F_214 ( V_4 ) ;
V_387 = F_236 ( V_4 , V_65 -> V_2 ) ;
if ( ! V_387 )
V_387 = F_237 ( F_238 ( V_65 -> V_2 ) , V_4 ) ;
if ( V_387 ) {
F_112 ( V_311 -> V_4 ) ;
V_311 -> V_4 = V_4 = V_387 ;
}
F_239 ( V_4 ,
F_240 ( F_14 ( V_298 -> V_3 ) ) ) ;
}
V_51 = F_206 ( V_222 -> V_301 , V_298 , V_65 , V_192 , V_223 ) ;
if ( V_51 != 0 )
goto V_151;
V_311 -> V_65 = V_65 ;
if ( F_14 ( V_4 ) == V_65 -> V_2 ) {
F_241 ( V_311 ) ;
if ( F_242 ( & V_222 -> V_385 , V_384 ) )
F_23 ( V_14 , V_65 ) ;
}
V_151:
return V_51 ;
}
static int F_243 ( struct V_2 * V_3 ,
struct V_310 * V_311 ,
int V_223 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_388 )
{
struct V_221 * V_222 ;
struct V_64 * V_65 = NULL ;
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_209 * V_298 ;
struct V_4 * V_4 = V_311 -> V_4 ;
struct V_326 * V_360 = V_311 -> V_360 ;
struct V_389 * * V_390 = & V_311 -> V_264 ;
T_6 V_192 = V_311 -> V_268 & ( V_194 | V_195 | V_391 ) ;
enum V_201 V_202 = V_204 ;
struct V_1 * V_392 = NULL ;
int V_316 ;
V_316 = - V_134 ;
V_222 = F_244 ( V_14 , V_360 , V_393 ) ;
if ( V_222 == NULL ) {
F_8 ( L_23 ) ;
goto V_394;
}
V_316 = F_211 ( V_14 ) ;
if ( V_316 != 0 )
goto V_395;
if ( F_245 ( V_4 ) )
F_155 ( F_14 ( V_4 ) , V_192 ) ;
V_316 = - V_134 ;
if ( F_245 ( V_4 ) )
V_202 = V_203 ;
V_298 = F_98 ( V_4 , V_222 , V_192 , V_223 , V_6 ,
V_7 , V_202 , V_393 ) ;
if ( V_298 == NULL )
goto V_395;
if ( V_7 ) {
V_392 = F_102 ( V_14 , V_393 ) ;
if ( F_51 ( V_392 ) ) {
V_316 = F_84 ( V_392 ) ;
goto V_396;
}
}
if ( V_14 -> V_15 [ 2 ] & V_397 ) {
if ( ! V_298 -> V_211 . V_264 ) {
V_298 -> V_211 . V_264 = F_246 () ;
if ( ! V_298 -> V_211 . V_264 )
goto V_234;
}
V_298 -> V_214 . V_253 = & V_398 [ 0 ] ;
}
if ( F_245 ( V_4 ) )
V_298 -> V_65 = F_169 ( F_14 ( V_4 ) , V_222 ) ;
V_316 = F_233 ( V_298 , V_192 , V_223 , V_311 ) ;
if ( V_316 != 0 )
goto V_234;
V_65 = V_311 -> V_65 ;
if ( ( V_298 -> V_214 . V_238 & ( V_370 | V_240 ) ) == ( V_370 | V_240 ) &&
( V_298 -> V_214 . V_338 != V_341 ) ) {
F_232 ( V_298 , V_6 , & V_7 ) ;
if ( V_6 -> V_257 & V_399 ) {
F_96 ( V_298 -> V_210 . V_211 ) ;
V_316 = F_247 ( V_65 -> V_2 , V_360 ,
V_298 -> V_210 . V_211 , V_6 ,
V_65 , V_7 , V_392 ) ;
if ( V_316 == 0 ) {
F_248 ( V_65 -> V_2 , V_6 ,
V_298 -> V_210 . V_211 ) ;
F_249 ( V_65 -> V_2 , V_298 -> V_210 . V_211 , V_392 ) ;
}
}
}
if ( V_388 && V_298 -> V_367 )
* V_388 |= V_400 ;
if ( F_250 ( V_390 , V_298 -> V_211 . V_264 , V_14 ) ) {
* V_390 = V_298 -> V_211 . V_264 ;
V_298 -> V_211 . V_264 = NULL ;
}
F_110 ( V_392 ) ;
F_120 ( V_298 ) ;
F_117 ( V_222 ) ;
return 0 ;
V_234:
F_110 ( V_392 ) ;
V_396:
F_120 ( V_298 ) ;
V_395:
F_117 ( V_222 ) ;
V_394:
return V_316 ;
}
static struct V_64 * F_251 ( struct V_2 * V_3 ,
struct V_310 * V_311 ,
int V_223 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_388 )
{
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_60 V_61 = { } ;
struct V_64 * V_56 ;
int V_316 ;
do {
V_316 = F_243 ( V_3 , V_311 , V_223 , V_6 , V_7 , V_388 ) ;
V_56 = V_311 -> V_65 ;
F_252 ( V_311 , V_223 , V_316 ) ;
if ( V_316 == 0 )
break;
if ( V_316 == - V_401 ) {
F_253 ( L_5
L_24 ,
F_100 ( V_3 ) -> V_62 -> V_99 ) ;
V_61 . V_69 = 1 ;
continue;
}
if ( V_316 == - V_73 ) {
V_61 . V_69 = 1 ;
continue;
}
if ( V_316 == - V_110 ) {
V_61 . V_69 = 1 ;
continue;
}
if ( F_92 ( V_14 , V_316 , & V_61 ) )
continue;
V_56 = F_52 ( F_31 ( V_14 ,
V_316 , & V_61 ) ) ;
} while ( V_61 . V_69 );
return V_56 ;
}
static int F_254 ( struct V_2 * V_2 ,
struct V_402 * V_403 ,
struct V_404 * V_56 ,
struct V_326 * V_360 ,
struct V_64 * V_65 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_405 ] ,
. V_324 = V_403 ,
. V_325 = V_56 ,
. V_326 = V_360 ,
} ;
struct V_326 * V_406 = NULL ;
unsigned long V_117 = V_161 ;
T_6 V_192 ;
bool V_407 ;
int V_316 ;
F_96 ( V_56 -> V_408 ) ;
V_407 = ( V_403 -> V_409 -> V_257 & V_410 ) ? true : false ;
V_192 = V_407 ? V_195 : V_194 ;
if ( F_255 ( V_2 , V_192 , & V_403 -> V_66 , & V_406 ) ) {
} else if ( V_407 && V_65 != NULL ) {
struct V_411 V_412 = {
. V_413 = V_57 -> V_414 ,
. V_415 = V_57 -> V_416 ,
} ;
if ( ! F_256 ( V_65 ) )
return - V_417 ;
if ( F_257 ( V_65 , V_195 , & V_412 ,
& V_403 -> V_66 , & V_406 ) == - V_35 )
return - V_417 ;
} else
F_142 ( & V_403 -> V_66 , & V_418 ) ;
if ( V_406 )
V_170 . V_326 = V_406 ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & V_403 -> V_167 , & V_56 -> V_168 , 1 ) ;
F_228 ( V_406 ) ;
if ( V_316 == 0 && V_65 != NULL )
F_44 ( V_14 , V_117 ) ;
F_258 ( V_2 , & V_403 -> V_66 , V_316 ) ;
return V_316 ;
}
static int F_247 ( struct V_2 * V_2 , struct V_326 * V_360 ,
struct V_419 * V_408 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_420 ,
struct V_1 * V_392 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_402 V_403 = {
. V_255 = F_108 ( V_2 ) ,
. V_409 = V_6 ,
. V_14 = V_14 ,
. V_252 = V_14 -> V_15 ,
. V_7 = V_420 ,
} ;
struct V_404 V_56 = {
. V_408 = V_408 ,
. V_7 = V_392 ,
. V_14 = V_14 ,
} ;
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_2 ,
. V_66 = & V_403 . V_66 ,
} ;
int V_8 ;
V_403 . V_252 = F_6 ( V_14 , V_420 ) ;
if ( V_420 )
V_403 . V_252 = F_6 ( V_14 , V_392 ) ;
do {
V_8 = F_254 ( V_2 , & V_403 , & V_56 , V_360 , V_65 ) ;
switch ( V_8 ) {
case - V_70 :
if ( ! ( V_6 -> V_257 & V_410 ) ) {
F_259 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_62 -> V_99 ) ;
}
if ( V_65 && ! ( V_65 -> V_65 & V_195 ) ) {
V_8 = - V_417 ;
if ( V_6 -> V_257 & V_421 )
V_8 = - V_29 ;
goto V_151;
}
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_69 );
V_151:
return V_8 ;
}
static bool
F_260 ( struct V_2 * V_2 , struct V_104 * V_105 )
{
if ( V_2 == NULL || ! F_261 ( V_2 ) )
return false ;
return F_262 ( V_2 , V_105 ) ;
}
static void F_263 ( void * V_165 )
{
struct V_422 * V_163 = V_165 ;
struct V_221 * V_222 = V_163 -> V_65 -> V_236 ;
struct V_262 * V_263 = V_163 -> V_65 -> V_2 -> V_423 ;
if ( V_163 -> V_424 )
F_264 ( V_163 -> V_65 -> V_2 ) ;
F_116 ( V_163 -> V_65 ) ;
F_115 ( V_163 -> V_403 . V_213 ) ;
F_117 ( V_222 ) ;
F_118 ( V_263 ) ;
F_111 ( V_163 ) ;
}
static void F_265 ( struct V_104 * V_105 , void * V_165 )
{
struct V_422 * V_163 = V_165 ;
struct V_64 * V_65 = V_163 -> V_65 ;
struct V_13 * V_14 = F_100 ( V_163 -> V_2 ) ;
T_4 * V_425 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_73 ( V_105 , & V_163 -> V_56 . V_168 ) )
return;
F_266 ( V_65 , & V_163 -> V_403 , & V_163 -> V_56 , V_105 -> V_109 ) ;
switch ( V_105 -> V_109 ) {
case 0 :
V_425 = & V_163 -> V_56 . V_66 ;
if ( V_163 -> V_424 )
F_267 ( V_65 -> V_2 ,
V_163 -> V_426 ) ;
F_44 ( V_14 , V_163 -> V_117 ) ;
break;
case - V_72 :
case - V_77 :
case - V_95 :
case - V_73 :
case - V_76 :
if ( ! F_152 ( & V_163 -> V_403 . V_66 ,
& V_65 -> V_281 ) ) {
F_68 ( V_105 ) ;
goto V_427;
}
if ( V_163 -> V_403 . V_192 == 0 )
break;
default:
if ( F_38 ( V_105 , V_14 , V_65 , NULL ) == - V_110 ) {
F_68 ( V_105 ) ;
goto V_427;
}
}
F_143 ( V_65 , & V_163 -> V_403 . V_66 ,
V_425 , V_163 -> V_403 . V_192 ) ;
V_427:
F_158 ( V_163 -> V_403 . V_213 ) ;
F_165 ( V_163 -> V_2 , V_163 -> V_56 . V_408 ) ;
F_8 ( L_30 , V_34 , V_105 -> V_109 ) ;
}
static void F_268 ( struct V_104 * V_105 , void * V_165 )
{
struct V_422 * V_163 = V_165 ;
struct V_64 * V_65 = V_163 -> V_65 ;
struct V_2 * V_2 = V_163 -> V_2 ;
bool V_428 , V_429 , V_430 ;
int V_431 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_199 ( V_163 -> V_403 . V_213 , V_105 ) != 0 )
goto V_332;
V_105 -> V_336 . V_321 = & V_322 [ V_432 ] ;
F_41 ( & V_65 -> V_236 -> V_287 ) ;
V_430 = F_33 ( V_273 , & V_65 -> V_223 ) ;
V_428 = F_33 ( V_271 , & V_65 -> V_223 ) ;
V_429 = F_33 ( V_272 , & V_65 -> V_223 ) ;
F_142 ( & V_163 -> V_403 . V_66 , & V_65 -> V_281 ) ;
V_163 -> V_403 . V_192 = 0 ;
if ( V_65 -> V_265 == 0 ) {
if ( V_65 -> V_267 == 0 )
V_431 |= V_428 ;
else if ( V_428 )
V_163 -> V_403 . V_192 |= V_194 ;
if ( V_65 -> V_266 == 0 )
V_431 |= V_429 ;
else if ( V_429 )
V_163 -> V_403 . V_192 |= V_195 ;
if ( V_163 -> V_403 . V_192 != ( V_194 | V_195 ) )
V_431 |= V_430 ;
} else if ( V_430 )
V_163 -> V_403 . V_192 |= V_194 | V_195 ;
if ( ! F_256 ( V_65 ) )
V_431 = 0 ;
F_43 ( & V_65 -> V_236 -> V_287 ) ;
if ( ! V_431 ) {
goto V_333;
}
if ( F_260 ( V_2 , V_105 ) ) {
F_158 ( V_163 -> V_403 . V_213 ) ;
goto V_332;
}
if ( V_163 -> V_403 . V_192 == 0 )
V_105 -> V_336 . V_321 = & V_322 [ V_433 ] ;
if ( V_163 -> V_424 )
F_269 ( V_2 , & V_163 -> V_426 ) ;
V_163 -> V_403 . V_239 =
F_93 ( F_100 ( V_2 ) ,
V_163 -> V_403 . V_192 , 0 ) ;
F_96 ( V_163 -> V_56 . V_408 ) ;
V_163 -> V_117 = V_161 ;
if ( F_76 ( F_100 ( V_2 ) ,
& V_163 -> V_403 . V_167 ,
& V_163 -> V_56 . V_168 ,
V_105 ) != 0 )
F_158 ( V_163 -> V_403 . V_213 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_333:
V_105 -> V_344 = NULL ;
V_332:
F_73 ( V_105 , & V_163 -> V_56 . V_168 ) ;
}
static bool F_270 ( struct V_2 * V_2 )
{
if ( ! F_261 ( V_2 ) )
return false ;
return F_271 ( V_2 ) ;
}
int F_272 ( struct V_64 * V_65 , T_7 V_225 , int V_434 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
struct V_227 * ( * V_228 ) ( struct V_229 * , T_7 ) ;
struct V_422 * V_163 ;
struct V_221 * V_222 = V_65 -> V_236 ;
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_433 ] ,
. V_326 = V_65 -> V_236 -> V_301 ,
} ;
struct V_171 V_327 = {
. V_173 = V_14 -> V_100 ,
. V_169 = & V_170 ,
. V_174 = & V_435 ,
. V_329 = V_330 ,
. V_223 = V_331 ,
} ;
int V_316 = - V_134 ;
F_273 ( V_14 -> V_62 , V_436 ,
& V_327 . V_173 , & V_170 ) ;
V_163 = F_101 ( sizeof( * V_163 ) , V_225 ) ;
if ( V_163 == NULL )
goto V_151;
F_46 ( & V_163 -> V_403 . V_167 , & V_163 -> V_56 . V_168 , 1 ) ;
V_163 -> V_2 = V_65 -> V_2 ;
V_163 -> V_65 = V_65 ;
V_163 -> V_403 . V_255 = F_108 ( V_65 -> V_2 ) ;
V_228 = V_14 -> V_62 -> V_175 -> V_228 ;
V_163 -> V_403 . V_213 = V_228 ( & V_65 -> V_236 -> V_233 , V_225 ) ;
if ( F_51 ( V_163 -> V_403 . V_213 ) )
goto V_437;
V_163 -> V_403 . V_192 = 0 ;
V_163 -> V_403 . V_252 = V_14 -> V_438 ;
V_163 -> V_56 . V_408 = & V_163 -> V_408 ;
V_163 -> V_56 . V_213 = V_163 -> V_403 . V_213 ;
V_163 -> V_56 . V_14 = V_14 ;
V_163 -> V_424 = F_270 ( V_65 -> V_2 ) ;
F_103 ( V_163 -> V_2 -> V_423 ) ;
V_170 . V_324 = & V_163 -> V_403 ;
V_170 . V_325 = & V_163 -> V_56 ;
V_327 . V_177 = V_163 ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
V_316 = 0 ;
if ( V_434 )
V_316 = F_123 ( V_105 ) ;
F_85 ( V_105 ) ;
return V_316 ;
V_437:
F_111 ( V_163 ) ;
V_151:
F_116 ( V_65 ) ;
F_117 ( V_222 ) ;
return V_316 ;
}
static struct V_2 *
F_274 ( struct V_2 * V_3 , struct V_310 * V_311 ,
int V_238 , struct V_5 * V_439 , int * V_388 )
{
struct V_64 * V_65 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_311 -> V_4 , V_439 , & V_17 ) ;
V_65 = F_251 ( V_3 , V_311 , V_238 , V_439 , V_7 , V_388 ) ;
F_4 ( V_7 ) ;
if ( F_51 ( V_65 ) )
return F_275 ( V_65 ) ;
return V_65 -> V_2 ;
}
static void F_276 ( struct V_310 * V_311 , int V_440 )
{
if ( V_311 -> V_65 == NULL )
return;
if ( V_440 )
F_277 ( V_311 -> V_65 , V_311 -> V_268 ) ;
else
F_179 ( V_311 -> V_65 , V_311 -> V_268 ) ;
}
static int F_278 ( struct V_13 * V_14 , struct V_441 * V_442 )
{
T_1 V_252 [ 3 ] = {} , V_443 = V_14 -> V_62 -> V_444 ;
struct V_445 args = {
. V_442 = V_442 ,
. V_252 = V_252 ,
} ;
struct V_446 V_56 = {} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_447 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
int V_316 ;
V_252 [ 0 ] = V_448 |
V_449 |
V_450 |
V_451 |
V_452 ;
if ( V_443 )
V_252 [ 2 ] = V_453 ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
if ( V_316 == 0 ) {
switch ( V_443 ) {
case 0 :
V_56 . V_15 [ 1 ] &= V_454 ;
V_56 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_56 . V_15 [ 2 ] &= V_455 ;
break;
case 2 :
V_56 . V_15 [ 2 ] &= V_456 ;
}
memcpy ( V_14 -> V_15 , V_56 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_96 &= ~ ( V_457 | V_458 |
V_459 | V_460 |
V_461 | V_462 | V_463 |
V_464 | V_465 |
V_466 | V_467 |
V_9 ) ;
if ( V_56 . V_15 [ 0 ] & V_468 &&
V_56 . V_469 & V_470 )
V_14 -> V_96 |= V_457 ;
if ( V_56 . V_471 != 0 )
V_14 -> V_96 |= V_458 ;
if ( V_56 . V_472 != 0 )
V_14 -> V_96 |= V_459 ;
if ( V_56 . V_15 [ 0 ] & V_45 )
V_14 -> V_96 |= V_460 ;
if ( V_56 . V_15 [ 1 ] & V_381 )
V_14 -> V_96 |= V_461 ;
if ( V_56 . V_15 [ 1 ] & V_473 )
V_14 -> V_96 |= V_462 ;
if ( V_56 . V_15 [ 1 ] & V_474 )
V_14 -> V_96 |= V_463 ;
if ( V_56 . V_15 [ 1 ] & V_475 )
V_14 -> V_96 |= V_464 ;
if ( V_56 . V_15 [ 1 ] & V_375 )
V_14 -> V_96 |= V_465 ;
if ( V_56 . V_15 [ 1 ] & V_476 )
V_14 -> V_96 |= V_466 ;
if ( V_56 . V_15 [ 1 ] & V_378 )
V_14 -> V_96 |= V_467 ;
#ifdef F_279
if ( V_56 . V_15 [ 2 ] & V_383 )
V_14 -> V_96 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_56 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_383 ;
memcpy ( V_14 -> V_438 , V_56 . V_15 , sizeof( V_14 -> V_438 ) ) ;
V_14 -> V_438 [ 0 ] &= V_477 | V_478 ;
V_14 -> V_438 [ 1 ] &= V_476 | V_378 ;
V_14 -> V_438 [ 2 ] = 0 ;
memcpy ( V_14 -> V_479 , V_56 . V_479 ,
sizeof( V_14 -> V_479 ) ) ;
V_14 -> V_469 = V_56 . V_469 ;
V_14 -> V_480 = V_56 . V_480 ;
}
return V_316 ;
}
int F_280 ( struct V_13 * V_14 , struct V_441 * V_442 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_278 ( V_14 , V_442 ) ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_281 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 )
{
T_1 V_252 [ 3 ] ;
struct V_483 args = {
. V_252 = V_252 ,
} ;
struct V_484 V_56 = {
. V_14 = V_14 ,
. V_408 = V_482 -> V_408 ,
. V_255 = V_442 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_485 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
V_252 [ 0 ] = V_254 [ 0 ] ;
V_252 [ 1 ] = V_254 [ 1 ] ;
V_252 [ 2 ] = V_254 [ 2 ] & ~ V_383 ;
F_96 ( V_482 -> V_408 ) ;
return F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
}
static int F_282 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_281 ( V_14 , V_442 , V_482 ) ;
F_283 ( V_14 , V_442 , V_482 -> V_408 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_151;
default:
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_69 );
V_151:
return V_8 ;
}
static int F_284 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 , T_5 V_111 )
{
struct V_486 V_487 = {
. V_488 = V_111 ,
} ;
struct V_489 * V_490 ;
int V_51 ;
V_490 = F_285 ( & V_487 , V_14 -> V_100 ) ;
if ( F_51 ( V_490 ) ) {
V_51 = - V_29 ;
goto V_151;
}
V_51 = F_282 ( V_14 , V_442 , V_482 ) ;
V_151:
return V_51 ;
}
static int F_286 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 )
{
static const T_5 V_491 [] = {
V_116 ,
V_115 ,
V_492 ,
V_493 ,
V_494 ,
} ;
int V_316 = - V_24 ;
T_9 V_495 ;
if ( V_14 -> V_496 . V_497 > 0 ) {
for ( V_495 = 0 ; V_495 < V_14 -> V_496 . V_497 ; V_495 ++ ) {
V_316 = F_284 ( V_14 , V_442 , V_482 ,
V_14 -> V_496 . V_498 [ V_495 ] ) ;
if ( V_316 == - V_22 || V_316 == - V_29 )
continue;
break;
}
} else {
for ( V_495 = 0 ; V_495 < F_287 ( V_491 ) ; V_495 ++ ) {
V_316 = F_284 ( V_14 , V_442 , V_482 ,
V_491 [ V_495 ] ) ;
if ( V_316 == - V_22 || V_316 == - V_29 )
continue;
break;
}
}
if ( V_316 == - V_29 )
V_316 = - V_24 ;
return V_316 ;
}
int F_288 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 ,
bool V_499 )
{
int V_316 = 0 ;
if ( ! V_499 )
V_316 = F_282 ( V_14 , V_442 , V_482 ) ;
if ( V_499 || V_316 == V_22 )
V_316 = V_14 -> V_62 -> V_175 -> V_500 ( V_14 ,
V_442 , V_482 ) ;
if ( V_316 == 0 )
V_316 = F_280 ( V_14 , V_442 ) ;
if ( V_316 == 0 )
V_316 = F_289 ( V_14 , V_442 , V_482 ) ;
return F_7 ( V_316 ) ;
}
static int F_290 ( struct V_13 * V_14 , struct V_441 * V_501 ,
struct V_481 * V_482 )
{
int error ;
struct V_419 * V_408 = V_482 -> V_408 ;
struct V_1 * V_7 = NULL ;
error = F_280 ( V_14 , V_501 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_102 ( V_14 , V_393 ) ;
if ( F_51 ( V_7 ) )
return F_84 ( V_7 ) ;
error = F_210 ( V_14 , V_501 , V_408 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_234;
}
if ( V_408 -> V_307 & V_502 &&
! F_291 ( & V_14 -> V_503 , & V_408 -> V_503 ) )
memcpy ( & V_14 -> V_503 , & V_408 -> V_503 , sizeof( V_14 -> V_503 ) ) ;
V_234:
F_110 ( V_7 ) ;
return error ;
}
static int F_292 ( struct V_54 * V_100 , struct V_2 * V_3 ,
const struct V_504 * V_251 , struct V_419 * V_408 ,
struct V_441 * V_442 )
{
int V_316 = - V_134 ;
struct V_505 * V_505 = NULL ;
struct V_506 * V_507 = NULL ;
V_505 = F_293 ( V_393 ) ;
if ( V_505 == NULL )
goto V_151;
V_507 = F_294 ( sizeof( struct V_506 ) , V_393 ) ;
if ( V_507 == NULL )
goto V_151;
V_316 = F_295 ( V_100 , V_3 , V_251 , V_507 , V_505 ) ;
if ( V_316 != 0 )
goto V_151;
if ( F_291 ( & F_100 ( V_3 ) -> V_503 , & V_507 -> V_408 . V_503 ) ) {
F_8 ( L_34
L_35 , V_34 , V_251 -> V_251 ) ;
V_316 = - V_79 ;
goto V_151;
}
F_296 ( & V_507 -> V_408 ) ;
memcpy ( V_408 , & V_507 -> V_408 , sizeof( struct V_419 ) ) ;
memset ( V_442 , 0 , sizeof( struct V_441 ) ) ;
V_151:
if ( V_505 )
F_297 ( V_505 ) ;
F_111 ( V_507 ) ;
return V_316 ;
}
static int F_298 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_419 * V_408 , struct V_1 * V_7 )
{
struct V_508 args = {
. V_255 = V_442 ,
. V_252 = V_14 -> V_15 ,
} ;
struct V_509 V_56 = {
. V_408 = V_408 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_510 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
args . V_252 = F_6 ( V_14 , V_7 ) ;
F_96 ( V_408 ) ;
return F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
}
static int F_210 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_419 * V_408 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_298 ( V_14 , V_442 , V_408 , V_7 ) ;
F_299 ( V_14 , V_442 , V_408 , V_8 ) ;
V_8 = F_31 ( V_14 , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int
F_300 ( struct V_4 * V_4 , struct V_419 * V_408 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_326 * V_360 = NULL ;
struct V_64 * V_65 = NULL ;
struct V_1 * V_7 = NULL ;
int V_316 ;
if ( F_301 ( V_2 ) &&
V_6 -> V_257 & V_410 &&
V_6 -> V_511 < F_302 ( V_2 ) )
F_303 ( V_2 ) ;
F_96 ( V_408 ) ;
if ( V_6 -> V_257 & V_421 )
V_6 -> V_257 &= ~ ( V_380 | V_512 ) ;
if ( ( V_6 -> V_257 & ~ ( V_513 | V_421 ) ) == 0 )
return 0 ;
if ( V_6 -> V_257 & V_513 ) {
struct V_310 * V_311 ;
V_311 = F_304 ( V_6 -> V_514 ) ;
if ( V_311 ) {
V_360 = V_311 -> V_360 ;
V_65 = V_311 -> V_65 ;
}
}
V_7 = F_102 ( F_100 ( V_2 ) , V_393 ) ;
if ( F_51 ( V_7 ) )
return F_84 ( V_7 ) ;
V_316 = F_247 ( V_2 , V_360 , V_408 , V_6 , V_65 , NULL , V_7 ) ;
if ( V_316 == 0 ) {
F_248 ( V_2 , V_6 , V_408 ) ;
F_249 ( V_2 , V_408 , V_7 ) ;
}
F_110 ( V_7 ) ;
return V_316 ;
}
static int F_305 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_504 * V_251 , struct V_441 * V_442 ,
struct V_419 * V_408 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_100 ( V_3 ) ;
int V_316 ;
struct V_515 args = {
. V_252 = V_14 -> V_15 ,
. V_516 = F_108 ( V_3 ) ,
. V_251 = V_251 ,
} ;
struct V_484 V_56 = {
. V_14 = V_14 ,
. V_408 = V_408 ,
. V_7 = V_7 ,
. V_255 = V_442 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_517 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
args . V_252 = F_6 ( V_14 , V_7 ) ;
F_96 ( V_408 ) ;
F_8 ( L_36 , V_251 -> V_251 ) ;
V_316 = F_86 ( V_55 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
F_8 ( L_37 , V_316 ) ;
return V_316 ;
}
static void F_306 ( struct V_419 * V_408 )
{
V_408 -> V_307 |= V_345 | V_518 |
V_519 | V_520 ;
V_408 -> V_268 = V_350 | V_521 | V_522 ;
V_408 -> V_523 = 2 ;
}
static int F_307 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
const struct V_504 * V_251 , struct V_441 * V_442 ,
struct V_419 * V_408 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
struct V_54 * V_100 = * V_55 ;
int V_8 ;
do {
V_8 = F_305 ( V_100 , V_3 , V_251 , V_442 , V_408 , V_7 ) ;
F_308 ( V_3 , V_251 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_312 ;
goto V_151;
case - V_79 :
V_8 = F_292 ( V_100 , V_3 , V_251 , V_408 , V_442 ) ;
if ( V_8 == - V_79 )
V_8 = F_31 ( F_100 ( V_3 ) , V_8 , & V_61 ) ;
goto V_151;
case - V_22 :
V_8 = - V_24 ;
if ( V_100 != * V_55 )
goto V_151;
V_100 = F_309 ( V_100 , V_3 , V_251 ) ;
if ( F_51 ( V_100 ) )
return F_84 ( V_100 ) ;
V_61 . V_69 = 1 ;
break;
default:
V_8 = F_31 ( F_100 ( V_3 ) , V_8 , & V_61 ) ;
}
} while ( V_61 . V_69 );
V_151:
if ( V_8 == 0 )
* V_55 = V_100 ;
else if ( V_100 != * V_55 )
F_310 ( V_100 ) ;
return V_8 ;
}
static int F_311 ( struct V_2 * V_3 , const struct V_504 * V_251 ,
struct V_441 * V_442 , struct V_419 * V_408 ,
struct V_1 * V_7 )
{
int V_316 ;
struct V_54 * V_100 = F_312 ( V_3 ) ;
V_316 = F_307 ( & V_100 , V_3 , V_251 , V_442 , V_408 , V_7 ) ;
if ( V_100 != F_312 ( V_3 ) ) {
F_310 ( V_100 ) ;
F_306 ( V_408 ) ;
}
return V_316 ;
}
struct V_54 *
F_313 ( struct V_2 * V_3 , const struct V_504 * V_251 ,
struct V_441 * V_442 , struct V_419 * V_408 )
{
struct V_54 * V_100 = F_312 ( V_3 ) ;
int V_316 ;
V_316 = F_307 ( & V_100 , V_3 , V_251 , V_442 , V_408 , NULL ) ;
if ( V_316 < 0 )
return F_52 ( V_316 ) ;
return ( V_100 == F_312 ( V_3 ) ) ? F_314 ( V_100 ) : V_100 ;
}
static int F_315 ( struct V_2 * V_2 , struct V_361 * V_524 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_525 args = {
. V_255 = F_108 ( V_2 ) ,
. V_252 = V_14 -> V_438 ,
} ;
struct V_526 V_56 = {
. V_14 = V_14 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_527 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_524 -> V_360 ,
} ;
int V_268 = V_524 -> V_363 ;
int V_316 = 0 ;
if ( V_268 & V_368 )
args . V_218 |= V_241 ;
if ( F_316 ( V_2 -> V_528 ) ) {
if ( V_268 & V_529 )
args . V_218 |= V_242 | V_243 | V_530 ;
if ( V_268 & V_366 )
args . V_218 |= V_531 ;
} else {
if ( V_268 & V_529 )
args . V_218 |= V_242 | V_243 ;
if ( V_268 & V_366 )
args . V_218 |= V_244 ;
}
V_56 . V_408 = F_317 () ;
if ( V_56 . V_408 == NULL )
return - V_134 ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
if ( ! V_316 ) {
F_207 ( V_524 , V_56 . V_218 ) ;
F_165 ( V_2 , V_56 . V_408 ) ;
}
F_318 ( V_56 . V_408 ) ;
return V_316 ;
}
static int F_319 ( struct V_2 * V_2 , struct V_361 * V_524 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_315 ( V_2 , V_524 ) ;
F_320 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_321 ( struct V_2 * V_2 , struct V_505 * V_505 ,
unsigned int V_48 , unsigned int V_532 )
{
struct V_533 args = {
. V_255 = F_108 ( V_2 ) ,
. V_48 = V_48 ,
. V_532 = V_532 ,
. V_42 = & V_505 ,
} ;
struct V_534 V_56 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_535 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
return F_86 ( F_100 ( V_2 ) -> V_100 , F_100 ( V_2 ) , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
}
static int F_322 ( struct V_2 * V_2 , struct V_505 * V_505 ,
unsigned int V_48 , unsigned int V_532 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_321 ( V_2 , V_505 , V_48 , V_532 ) ;
F_323 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int
F_324 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_223 )
{
struct V_1 V_17 , * V_420 = NULL ;
struct V_310 * V_311 ;
struct V_64 * V_65 ;
int V_316 = 0 ;
V_311 = F_325 ( V_4 , V_194 ) ;
if ( F_51 ( V_311 ) )
return F_84 ( V_311 ) ;
V_420 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_326 () ;
V_65 = F_251 ( V_3 , V_311 , V_223 , V_6 , V_420 , NULL ) ;
if ( F_51 ( V_65 ) ) {
V_316 = F_84 ( V_65 ) ;
goto V_151;
}
V_151:
F_4 ( V_420 ) ;
F_186 ( V_311 ) ;
return V_316 ;
}
static int F_327 ( struct V_2 * V_3 , const struct V_504 * V_251 )
{
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_536 args = {
. V_255 = F_108 ( V_3 ) ,
. V_251 = * V_251 ,
} ;
struct V_537 V_56 = {
. V_14 = V_14 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_538 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
int V_316 ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 1 ) ;
if ( V_316 == 0 )
F_87 ( V_3 , & V_56 . V_179 ) ;
return V_316 ;
}
static int F_328 ( struct V_2 * V_3 , const struct V_504 * V_251 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_327 ( V_3 , V_251 ) ;
F_329 ( V_3 , V_251 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static void F_330 ( struct V_169 * V_170 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_536 * args = V_170 -> V_324 ;
struct V_537 * V_56 = V_170 -> V_325 ;
V_56 -> V_14 = V_14 ;
V_170 -> V_321 = & V_322 [ V_538 ] ;
F_46 ( & args -> V_167 , & V_56 -> V_168 , 1 ) ;
F_96 ( V_56 -> V_539 ) ;
}
static void F_331 ( struct V_104 * V_105 , struct V_540 * V_165 )
{
F_76 ( F_177 ( V_165 -> V_4 -> V_235 ) ,
& V_165 -> args . V_167 ,
& V_165 -> V_56 . V_168 ,
V_105 ) ;
}
static int F_332 ( struct V_104 * V_105 , struct V_2 * V_3 )
{
struct V_540 * V_165 = V_105 -> V_541 ;
struct V_537 * V_56 = & V_165 -> V_56 ;
if ( ! F_73 ( V_105 , & V_56 -> V_168 ) )
return 0 ;
if ( F_38 ( V_105 , V_56 -> V_14 , NULL ,
& V_165 -> V_50 ) == - V_110 )
return 0 ;
F_87 ( V_3 , & V_56 -> V_179 ) ;
return 1 ;
}
static void F_333 ( struct V_169 * V_170 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_100 ( V_3 ) ;
struct V_542 * V_403 = V_170 -> V_324 ;
struct V_543 * V_56 = V_170 -> V_325 ;
V_170 -> V_321 = & V_322 [ V_544 ] ;
V_56 -> V_14 = V_14 ;
F_46 ( & V_403 -> V_167 , & V_56 -> V_168 , 1 ) ;
}
static void F_334 ( struct V_104 * V_105 , struct V_545 * V_165 )
{
F_76 ( F_100 ( V_165 -> V_546 ) ,
& V_165 -> args . V_167 ,
& V_165 -> V_56 . V_168 ,
V_105 ) ;
}
static int F_335 ( struct V_104 * V_105 , struct V_2 * V_546 ,
struct V_2 * V_547 )
{
struct V_545 * V_165 = V_105 -> V_541 ;
struct V_543 * V_56 = & V_165 -> V_56 ;
if ( ! F_73 ( V_105 , & V_56 -> V_168 ) )
return 0 ;
if ( F_38 ( V_105 , V_56 -> V_14 , NULL , & V_165 -> V_50 ) == - V_110 )
return 0 ;
F_87 ( V_546 , & V_56 -> V_548 ) ;
F_87 ( V_547 , & V_56 -> V_549 ) ;
return 1 ;
}
static int F_336 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_504 * V_251 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_550 V_403 = {
. V_255 = F_108 ( V_2 ) ,
. V_516 = F_108 ( V_3 ) ,
. V_251 = V_251 ,
. V_252 = V_14 -> V_15 ,
} ;
struct V_551 V_56 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_552 ] ,
. V_324 = & V_403 ,
. V_325 = & V_56 ,
} ;
int V_316 = - V_134 ;
V_56 . V_408 = F_317 () ;
if ( V_56 . V_408 == NULL )
goto V_151;
V_56 . V_7 = F_102 ( V_14 , V_393 ) ;
if ( F_51 ( V_56 . V_7 ) ) {
V_316 = F_84 ( V_56 . V_7 ) ;
goto V_151;
}
V_403 . V_252 = F_6 ( V_14 , V_56 . V_7 ) ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & V_403 . V_167 , & V_56 . V_168 , 1 ) ;
if ( ! V_316 ) {
F_87 ( V_3 , & V_56 . V_179 ) ;
V_316 = F_337 ( V_2 , V_56 . V_408 ) ;
if ( ! V_316 )
F_249 ( V_2 , V_56 . V_408 , V_56 . V_7 ) ;
}
F_110 ( V_56 . V_7 ) ;
V_151:
F_318 ( V_56 . V_408 ) ;
return V_316 ;
}
static int F_338 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_504 * V_251 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( F_100 ( V_2 ) ,
F_336 ( V_2 , V_3 , V_251 ) ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static struct V_553 * F_339 ( struct V_2 * V_3 ,
const struct V_504 * V_251 , struct V_5 * V_6 , T_1 V_554 )
{
struct V_553 * V_165 ;
V_165 = F_101 ( sizeof( * V_165 ) , V_393 ) ;
if ( V_165 != NULL ) {
struct V_13 * V_14 = F_100 ( V_3 ) ;
V_165 -> V_7 = F_102 ( V_14 , V_393 ) ;
if ( F_51 ( V_165 -> V_7 ) )
goto V_320;
V_165 -> V_170 . V_321 = & V_322 [ V_555 ] ;
V_165 -> V_170 . V_324 = & V_165 -> V_403 ;
V_165 -> V_170 . V_325 = & V_165 -> V_56 ;
V_165 -> V_403 . V_516 = F_108 ( V_3 ) ;
V_165 -> V_403 . V_14 = V_14 ;
V_165 -> V_403 . V_251 = V_251 ;
V_165 -> V_403 . V_224 = V_6 ;
V_165 -> V_403 . V_554 = V_554 ;
V_165 -> V_403 . V_252 = F_6 ( V_14 , V_165 -> V_7 ) ;
V_165 -> V_56 . V_14 = V_14 ;
V_165 -> V_56 . V_255 = & V_165 -> V_255 ;
V_165 -> V_56 . V_408 = & V_165 -> V_408 ;
V_165 -> V_56 . V_7 = V_165 -> V_7 ;
F_96 ( V_165 -> V_56 . V_408 ) ;
}
return V_165 ;
V_320:
F_111 ( V_165 ) ;
return NULL ;
}
static int F_340 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_553 * V_165 )
{
int V_316 = F_86 ( F_100 ( V_3 ) -> V_100 , F_100 ( V_3 ) , & V_165 -> V_170 ,
& V_165 -> V_403 . V_167 , & V_165 -> V_56 . V_168 , 1 ) ;
if ( V_316 == 0 ) {
F_87 ( V_3 , & V_165 -> V_56 . V_556 ) ;
V_316 = F_341 ( V_4 , V_165 -> V_56 . V_255 , V_165 -> V_56 . V_408 , V_165 -> V_56 . V_7 ) ;
}
return V_316 ;
}
static void F_342 ( struct V_553 * V_165 )
{
F_110 ( V_165 -> V_7 ) ;
F_111 ( V_165 ) ;
}
static int F_343 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_505 * V_505 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_553 * V_165 ;
int V_316 = - V_557 ;
if ( V_12 > V_558 )
goto V_151;
V_316 = - V_134 ;
V_165 = F_339 ( V_3 , & V_4 -> V_11 , V_6 , V_559 ) ;
if ( V_165 == NULL )
goto V_151;
V_165 -> V_170 . V_321 = & V_322 [ V_560 ] ;
V_165 -> V_403 . V_259 . V_561 . V_42 = & V_505 ;
V_165 -> V_403 . V_259 . V_561 . V_12 = V_12 ;
V_165 -> V_403 . V_7 = V_7 ;
V_316 = F_340 ( V_3 , V_4 , V_165 ) ;
F_342 ( V_165 ) ;
V_151:
return V_316 ;
}
static int F_344 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_505 * V_505 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_343 ( V_3 , V_4 , V_505 , V_12 , V_6 , V_7 ) ;
F_345 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_346 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_553 * V_165 ;
int V_316 = - V_134 ;
V_165 = F_339 ( V_3 , & V_4 -> V_11 , V_6 , V_562 ) ;
if ( V_165 == NULL )
goto V_151;
V_165 -> V_403 . V_7 = V_7 ;
V_316 = F_340 ( V_3 , V_4 , V_165 ) ;
F_342 ( V_165 ) ;
V_151:
return V_316 ;
}
static int F_347 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_326 () ;
do {
V_8 = F_346 ( V_3 , V_4 , V_6 , V_7 ) ;
F_348 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_349 ( struct V_4 * V_4 , struct V_326 * V_360 ,
T_2 V_36 , struct V_505 * * V_42 , unsigned int V_49 , int V_563 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_255 = F_108 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_252 = F_100 ( F_14 ( V_4 ) ) -> V_15 ,
. V_563 = V_563 ,
} ;
struct V_564 V_56 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_565 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
int V_316 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_88 ( V_3 ) -> V_566 , V_4 , & args ) ;
V_56 . V_48 = args . V_48 ;
V_316 = F_86 ( F_100 ( V_3 ) -> V_100 , F_100 ( V_3 ) , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
if ( V_316 >= 0 ) {
memcpy ( F_88 ( V_3 ) -> V_566 , V_56 . V_37 . V_165 , V_567 ) ;
V_316 += args . V_48 ;
}
F_350 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_316 ) ;
return V_316 ;
}
static int F_351 ( struct V_4 * V_4 , struct V_326 * V_360 ,
T_2 V_36 , struct V_505 * * V_42 , unsigned int V_49 , int V_563 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_349 ( V_4 , V_360 , V_36 ,
V_42 , V_49 , V_563 ) ;
F_352 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_31 ( F_100 ( F_14 ( V_4 ) ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_353 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_568 )
{
struct V_553 * V_165 ;
int V_268 = V_6 -> V_10 ;
int V_316 = - V_134 ;
V_165 = F_339 ( V_3 , & V_4 -> V_11 , V_6 , V_569 ) ;
if ( V_165 == NULL )
goto V_151;
if ( F_354 ( V_268 ) )
V_165 -> V_403 . V_554 = V_570 ;
else if ( F_355 ( V_268 ) ) {
V_165 -> V_403 . V_554 = V_571 ;
V_165 -> V_403 . V_259 . V_572 . V_573 = F_356 ( V_568 ) ;
V_165 -> V_403 . V_259 . V_572 . V_574 = F_357 ( V_568 ) ;
}
else if ( F_358 ( V_268 ) ) {
V_165 -> V_403 . V_554 = V_575 ;
V_165 -> V_403 . V_259 . V_572 . V_573 = F_356 ( V_568 ) ;
V_165 -> V_403 . V_259 . V_572 . V_574 = F_357 ( V_568 ) ;
} else if ( ! F_359 ( V_268 ) ) {
V_316 = - V_27 ;
goto V_320;
}
V_165 -> V_403 . V_7 = V_7 ;
V_316 = F_340 ( V_3 , V_4 , V_165 ) ;
V_320:
F_342 ( V_165 ) ;
V_151:
return V_316 ;
}
static int F_360 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_568 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_326 () ;
do {
V_8 = F_353 ( V_3 , V_4 , V_6 , V_7 , V_568 ) ;
F_361 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_362 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_576 * V_577 )
{
struct V_578 args = {
. V_255 = V_442 ,
. V_252 = V_14 -> V_15 ,
} ;
struct V_579 V_56 = {
. V_577 = V_577 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_580 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
F_96 ( V_577 -> V_408 ) ;
return F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
}
static int F_363 ( struct V_13 * V_14 , struct V_441 * V_442 , struct V_576 * V_577 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_362 ( V_14 , V_442 , V_577 ) ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_364 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_581 )
{
struct V_582 args = {
. V_255 = V_442 ,
. V_252 = V_14 -> V_15 ,
} ;
struct V_583 V_56 = {
. V_581 = V_581 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_584 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
return F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
}
static int F_289 ( struct V_13 * V_14 , struct V_441 * V_442 , struct V_481 * V_581 )
{
struct V_60 V_61 = { } ;
unsigned long V_585 = V_161 ;
int V_8 ;
do {
V_8 = F_364 ( V_14 , V_442 , V_581 ) ;
F_365 ( V_14 , V_442 , V_581 -> V_408 , V_8 ) ;
if ( V_8 == 0 ) {
F_366 ( V_14 -> V_62 ,
V_581 -> V_586 * V_90 ,
V_585 ) ;
break;
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_367 ( struct V_13 * V_14 , struct V_441 * V_442 , struct V_481 * V_581 )
{
int error ;
F_96 ( V_581 -> V_408 ) ;
error = F_289 ( V_14 , V_442 , V_581 ) ;
if ( error == 0 ) {
V_14 -> V_587 = V_581 -> V_588 ;
F_368 ( V_14 , V_442 , V_581 -> V_589 ) ;
}
return error ;
}
static int F_369 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_590 * V_591 )
{
struct V_592 args = {
. V_255 = V_442 ,
. V_252 = V_14 -> V_15 ,
} ;
struct V_593 V_56 = {
. V_591 = V_591 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_594 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
if ( ( args . V_252 [ 0 ] & V_595 [ 0 ] ) == 0 ) {
memset ( V_591 , 0 , sizeof( * V_591 ) ) ;
return 0 ;
}
F_96 ( V_591 -> V_408 ) ;
return F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
}
static int F_370 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_590 * V_591 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_369 ( V_14 , V_442 , V_591 ) ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
int F_371 ( T_4 * V_66 ,
const struct V_310 * V_311 ,
const struct V_596 * V_597 ,
T_6 V_192 )
{
const struct V_411 * V_412 = NULL ;
if ( V_597 != NULL )
V_412 = & V_597 -> V_412 ;
return F_257 ( V_311 -> V_65 , V_192 , V_412 , V_66 , NULL ) ;
}
static bool F_372 ( T_4 * V_66 ,
const struct V_310 * V_311 ,
const struct V_596 * V_597 ,
T_6 V_192 )
{
T_4 V_598 ;
if ( F_371 ( & V_598 , V_311 , V_597 , V_192 ) == - V_35 )
return true ;
return F_152 ( V_66 , & V_598 ) ;
}
static bool F_373 ( int V_8 )
{
switch ( V_8 ) {
case - V_71 :
case - V_72 :
case - V_73 :
case - V_77 :
case - V_95 :
case - V_70 :
case - V_76 :
return true ;
}
return false ;
}
void F_374 ( struct V_599 * V_600 )
{
F_350 ( V_600 -> V_2 ) ;
}
static int F_375 ( struct V_104 * V_105 , struct V_599 * V_600 )
{
struct V_13 * V_14 = F_100 ( V_600 -> V_2 ) ;
F_376 ( V_600 , V_105 -> V_109 ) ;
if ( F_38 ( V_105 , V_14 ,
V_600 -> args . V_601 -> V_65 ,
NULL ) == - V_110 ) {
F_68 ( V_105 ) ;
return - V_110 ;
}
F_374 ( V_600 ) ;
if ( V_105 -> V_109 > 0 )
F_44 ( V_14 , V_600 -> V_117 ) ;
return 0 ;
}
static bool F_377 ( struct V_104 * V_105 ,
struct V_602 * args )
{
if ( ! F_373 ( V_105 -> V_109 ) ||
F_372 ( & args -> V_66 ,
args -> V_601 ,
args -> V_603 ,
V_194 ) )
return false ;
F_68 ( V_105 ) ;
return true ;
}
static int F_378 ( struct V_104 * V_105 , struct V_599 * V_600 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_73 ( V_105 , & V_600 -> V_56 . V_168 ) )
return - V_110 ;
if ( F_377 ( V_105 , & V_600 -> args ) )
return - V_110 ;
return V_600 -> V_604 ? V_600 -> V_604 ( V_105 , V_600 ) :
F_375 ( V_105 , V_600 ) ;
}
static void F_379 ( struct V_599 * V_600 ,
struct V_169 * V_170 )
{
V_600 -> V_117 = V_161 ;
if ( ! V_600 -> V_604 )
V_600 -> V_604 = F_375 ;
V_170 -> V_321 = & V_322 [ V_605 ] ;
F_46 ( & V_600 -> args . V_167 , & V_600 -> V_56 . V_168 , 0 ) ;
}
static int F_380 ( struct V_104 * V_105 ,
struct V_599 * V_600 )
{
if ( F_76 ( F_100 ( V_600 -> V_2 ) ,
& V_600 -> args . V_167 ,
& V_600 -> V_56 . V_168 ,
V_105 ) )
return 0 ;
if ( F_371 ( & V_600 -> args . V_66 , V_600 -> args . V_601 ,
V_600 -> args . V_603 ,
V_600 -> V_606 -> V_607 ) == - V_35 )
return - V_35 ;
if ( F_381 ( F_33 ( V_608 , & V_600 -> args . V_601 -> V_223 ) ) )
return - V_35 ;
return 0 ;
}
static int F_382 ( struct V_104 * V_105 ,
struct V_599 * V_600 )
{
struct V_2 * V_2 = V_600 -> V_2 ;
F_383 ( V_600 , V_105 -> V_109 ) ;
if ( F_38 ( V_105 , F_100 ( V_2 ) ,
V_600 -> args . V_601 -> V_65 ,
NULL ) == - V_110 ) {
F_68 ( V_105 ) ;
return - V_110 ;
}
if ( V_105 -> V_109 >= 0 ) {
F_44 ( F_100 ( V_2 ) , V_600 -> V_117 ) ;
F_384 ( V_600 ) ;
}
return 0 ;
}
static bool F_385 ( struct V_104 * V_105 ,
struct V_602 * args )
{
if ( ! F_373 ( V_105 -> V_109 ) ||
F_372 ( & args -> V_66 ,
args -> V_601 ,
args -> V_603 ,
V_195 ) )
return false ;
F_68 ( V_105 ) ;
return true ;
}
static int F_386 ( struct V_104 * V_105 , struct V_599 * V_600 )
{
if ( ! F_73 ( V_105 , & V_600 -> V_56 . V_168 ) )
return - V_110 ;
if ( F_385 ( V_105 , & V_600 -> args ) )
return - V_110 ;
return V_600 -> V_604 ? V_600 -> V_604 ( V_105 , V_600 ) :
F_382 ( V_105 , V_600 ) ;
}
static
bool F_387 ( struct V_599 * V_600 )
{
if ( V_600 -> V_609 != NULL || V_600 -> V_610 != NULL )
return false ;
return F_388 ( V_600 -> V_2 , V_194 ) == 0 ;
}
static void F_389 ( struct V_599 * V_600 ,
struct V_169 * V_170 )
{
struct V_13 * V_14 = F_100 ( V_600 -> V_2 ) ;
if ( ! F_387 ( V_600 ) ) {
V_600 -> args . V_252 = NULL ;
V_600 -> V_56 . V_408 = NULL ;
} else
V_600 -> args . V_252 = V_14 -> V_438 ;
if ( ! V_600 -> V_604 )
V_600 -> V_604 = F_382 ;
V_600 -> V_56 . V_14 = V_14 ;
V_600 -> V_117 = V_161 ;
V_170 -> V_321 = & V_322 [ V_611 ] ;
F_46 ( & V_600 -> args . V_167 , & V_600 -> V_56 . V_168 , 1 ) ;
}
static void F_390 ( struct V_104 * V_105 , struct V_612 * V_165 )
{
F_76 ( F_100 ( V_165 -> V_2 ) ,
& V_165 -> args . V_167 ,
& V_165 -> V_56 . V_168 ,
V_105 ) ;
}
static int F_391 ( struct V_104 * V_105 , struct V_612 * V_165 )
{
struct V_2 * V_2 = V_165 -> V_2 ;
F_392 ( V_165 , V_105 -> V_109 ) ;
if ( F_38 ( V_105 , F_100 ( V_2 ) ,
NULL , NULL ) == - V_110 ) {
F_68 ( V_105 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_393 ( struct V_104 * V_105 , struct V_612 * V_165 )
{
if ( ! F_73 ( V_105 , & V_165 -> V_56 . V_168 ) )
return - V_110 ;
return V_165 -> V_613 ( V_105 , V_165 ) ;
}
static void F_394 ( struct V_612 * V_165 , struct V_169 * V_170 )
{
struct V_13 * V_14 = F_100 ( V_165 -> V_2 ) ;
if ( V_165 -> V_613 == NULL )
V_165 -> V_613 = F_391 ;
V_165 -> V_56 . V_14 = V_14 ;
V_170 -> V_321 = & V_322 [ V_614 ] ;
F_46 ( & V_165 -> args . V_167 , & V_165 -> V_56 . V_168 , 1 ) ;
}
static void F_395 ( void * V_163 )
{
struct V_615 * V_165 = V_163 ;
struct V_62 * V_63 = V_165 -> V_100 ;
if ( F_396 ( & V_63 -> V_616 ) > 1 )
F_397 ( V_63 ) ;
F_398 ( V_63 ) ;
F_111 ( V_165 ) ;
}
static void F_399 ( struct V_104 * V_105 , void * V_163 )
{
struct V_615 * V_165 = V_163 ;
struct V_62 * V_63 = V_165 -> V_100 ;
unsigned long V_117 = V_165 -> V_117 ;
F_400 ( V_63 , V_105 -> V_109 ) ;
switch ( V_105 -> V_109 ) {
case 0 :
break;
case - V_80 :
F_26 ( V_63 ) ;
break;
default:
if ( F_33 ( V_617 , & V_63 -> V_618 ) == 0 )
return;
if ( V_105 -> V_109 != V_619 ) {
F_24 ( V_63 ) ;
return;
}
F_401 ( V_63 ) ;
}
F_40 ( V_63 , V_117 ) ;
}
static int F_402 ( struct V_62 * V_63 , struct V_326 * V_360 , unsigned V_620 )
{
struct V_169 V_170 = {
. V_321 = & V_322 [ V_621 ] ,
. V_324 = V_63 ,
. V_326 = V_360 ,
} ;
struct V_615 * V_165 ;
if ( V_620 == 0 )
return 0 ;
if ( ! F_403 ( & V_63 -> V_616 ) )
return - V_35 ;
V_165 = F_294 ( sizeof( * V_165 ) , V_313 ) ;
if ( V_165 == NULL )
return - V_134 ;
V_165 -> V_100 = V_63 ;
V_165 -> V_117 = V_161 ;
return F_404 ( V_63 -> V_112 , & V_170 , V_622 ,
& V_623 , V_165 ) ;
}
static int F_405 ( struct V_62 * V_63 , struct V_326 * V_360 )
{
struct V_169 V_170 = {
. V_321 = & V_322 [ V_621 ] ,
. V_324 = V_63 ,
. V_326 = V_360 ,
} ;
unsigned long V_585 = V_161 ;
int V_316 ;
V_316 = F_406 ( V_63 -> V_112 , & V_170 , V_622 ) ;
if ( V_316 < 0 )
return V_316 ;
F_40 ( V_63 , V_585 ) ;
return 0 ;
}
static inline int F_407 ( struct V_13 * V_14 )
{
return V_14 -> V_96 & V_457 ;
}
static int F_408 ( const void * V_624 , T_9 V_625 ,
struct V_505 * * V_42 )
{
struct V_505 * V_626 , * * V_627 ;
int V_628 = 0 ;
T_9 V_12 ;
V_627 = V_42 ;
do {
V_12 = F_409 ( T_9 , V_629 , V_625 ) ;
V_626 = F_293 ( V_393 ) ;
if ( V_626 == NULL )
goto V_630;
memcpy ( F_410 ( V_626 ) , V_624 , V_12 ) ;
V_624 += V_12 ;
V_625 -= V_12 ;
* V_42 ++ = V_626 ;
V_628 ++ ;
} while ( V_625 != 0 );
return V_628 ;
V_630:
for(; V_628 > 0 ; V_628 -- )
F_297 ( V_627 [ V_628 - 1 ] ) ;
return - V_134 ;
}
static void F_411 ( struct V_2 * V_2 , struct V_631 * V_632 )
{
struct V_180 * V_181 = F_88 ( V_2 ) ;
F_41 ( & V_2 -> V_182 ) ;
F_111 ( V_181 -> V_633 ) ;
V_181 -> V_633 = V_632 ;
F_43 ( & V_2 -> V_182 ) ;
}
static void F_412 ( struct V_2 * V_2 )
{
F_411 ( V_2 , NULL ) ;
}
static inline T_11 F_413 ( struct V_2 * V_2 , char * V_624 , T_9 V_625 )
{
struct V_180 * V_181 = F_88 ( V_2 ) ;
struct V_631 * V_632 ;
int V_51 = - V_312 ;
F_41 ( & V_2 -> V_182 ) ;
V_632 = V_181 -> V_633 ;
if ( V_632 == NULL )
goto V_151;
if ( V_624 == NULL )
goto V_634;
if ( V_632 -> V_635 == 0 )
goto V_151;
V_51 = - V_636 ;
if ( V_632 -> V_12 > V_625 )
goto V_151;
memcpy ( V_624 , V_632 -> V_165 , V_632 -> V_12 ) ;
V_634:
V_51 = V_632 -> V_12 ;
V_151:
F_43 ( & V_2 -> V_182 ) ;
return V_51 ;
}
static void F_414 ( struct V_2 * V_2 , struct V_505 * * V_42 , T_9 V_48 , T_9 V_637 )
{
struct V_631 * V_632 ;
T_9 V_625 = sizeof( * V_632 ) + V_637 ;
if ( V_625 <= V_629 ) {
V_632 = F_294 ( V_625 , V_393 ) ;
if ( V_632 == NULL )
goto V_151;
V_632 -> V_635 = 1 ;
F_415 ( V_632 -> V_165 , V_42 , V_48 , V_637 ) ;
} else {
V_632 = F_294 ( sizeof( * V_632 ) , V_393 ) ;
if ( V_632 == NULL )
goto V_151;
V_632 -> V_635 = 0 ;
}
V_632 -> V_12 = V_637 ;
V_151:
F_411 ( V_2 , V_632 ) ;
}
static T_11 F_416 ( struct V_2 * V_2 , void * V_624 , T_9 V_625 )
{
struct V_505 * V_42 [ V_638 ] = { NULL , } ;
struct V_639 args = {
. V_255 = F_108 ( V_2 ) ,
. V_640 = V_42 ,
. V_637 = V_625 ,
} ;
struct V_641 V_56 = {
. V_637 = V_625 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_642 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
unsigned int V_643 = F_417 ( V_625 , V_629 ) ;
int V_51 = - V_134 , V_495 ;
if ( V_643 == 0 )
V_643 = 1 ;
if ( V_643 > F_287 ( V_42 ) )
return - V_636 ;
for ( V_495 = 0 ; V_495 < V_643 ; V_495 ++ ) {
V_42 [ V_495 ] = F_293 ( V_393 ) ;
if ( ! V_42 [ V_495 ] )
goto V_320;
}
V_56 . V_644 = F_293 ( V_393 ) ;
if ( ! V_56 . V_644 )
goto V_320;
args . V_637 = V_643 * V_629 ;
F_8 ( L_40 ,
V_34 , V_624 , V_625 , V_643 , args . V_637 ) ;
V_51 = F_86 ( F_100 ( V_2 ) -> V_100 , F_100 ( V_2 ) ,
& V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
if ( V_51 )
goto V_320;
if ( V_56 . V_645 & V_646 ) {
if ( V_624 == NULL )
goto V_647;
V_51 = - V_636 ;
goto V_320;
}
F_414 ( V_2 , V_42 , V_56 . V_648 , V_56 . V_637 ) ;
if ( V_624 ) {
if ( V_56 . V_637 > V_625 ) {
V_51 = - V_636 ;
goto V_320;
}
F_415 ( V_624 , V_42 , V_56 . V_648 , V_56 . V_637 ) ;
}
V_647:
V_51 = V_56 . V_637 ;
V_320:
for ( V_495 = 0 ; V_495 < V_643 ; V_495 ++ )
if ( V_42 [ V_495 ] )
F_297 ( V_42 [ V_495 ] ) ;
if ( V_56 . V_644 )
F_297 ( V_56 . V_644 ) ;
return V_51 ;
}
static T_11 F_418 ( struct V_2 * V_2 , void * V_624 , T_9 V_625 )
{
struct V_60 V_61 = { } ;
T_11 V_51 ;
do {
V_51 = F_416 ( V_2 , V_624 , V_625 ) ;
F_419 ( V_2 , V_51 ) ;
if ( V_51 >= 0 )
break;
V_51 = F_31 ( F_100 ( V_2 ) , V_51 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_51 ;
}
static T_11 F_420 ( struct V_2 * V_2 , void * V_624 , T_9 V_625 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
int V_51 ;
if ( ! F_407 ( V_14 ) )
return - V_649 ;
V_51 = F_421 ( V_14 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_88 ( V_2 ) -> V_183 & V_650 )
F_422 ( V_2 ) ;
V_51 = F_413 ( V_2 , V_624 , V_625 ) ;
if ( V_51 != - V_312 )
return V_51 ;
return F_418 ( V_2 , V_624 , V_625 ) ;
}
static int F_423 ( struct V_2 * V_2 , const void * V_624 , T_9 V_625 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_505 * V_42 [ V_638 ] ;
struct V_651 V_403 = {
. V_255 = F_108 ( V_2 ) ,
. V_640 = V_42 ,
. V_637 = V_625 ,
} ;
struct V_652 V_56 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_653 ] ,
. V_324 = & V_403 ,
. V_325 = & V_56 ,
} ;
unsigned int V_643 = F_417 ( V_625 , V_629 ) ;
int V_51 , V_495 ;
if ( ! F_407 ( V_14 ) )
return - V_649 ;
if ( V_643 > F_287 ( V_42 ) )
return - V_636 ;
V_495 = F_408 ( V_624 , V_625 , V_403 . V_640 ) ;
if ( V_495 < 0 )
return V_495 ;
F_156 ( V_2 ) ;
V_51 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & V_403 . V_167 , & V_56 . V_168 , 1 ) ;
for (; V_495 > 0 ; V_495 -- )
F_424 ( V_42 [ V_495 - 1 ] ) ;
F_41 ( & V_2 -> V_182 ) ;
F_88 ( V_2 ) -> V_183 |= V_184 ;
F_43 ( & V_2 -> V_182 ) ;
F_425 ( V_2 ) ;
F_422 ( V_2 ) ;
return V_51 ;
}
static int F_426 ( struct V_2 * V_2 , const void * V_624 , T_9 V_625 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_423 ( V_2 , V_624 , V_625 ) ;
F_427 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_428 ( struct V_2 * V_2 , void * V_624 ,
T_9 V_625 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_419 V_408 ;
struct V_1 V_7 = { 0 , 0 , V_625 , V_624 } ;
T_1 V_252 [ 3 ] = { 0 , 0 , V_383 } ;
struct V_508 V_403 = {
. V_255 = F_108 ( V_2 ) ,
. V_252 = V_252 ,
} ;
struct V_509 V_56 = {
. V_408 = & V_408 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_510 ] ,
. V_324 = & V_403 ,
. V_325 = & V_56 ,
} ;
int V_51 ;
F_96 ( & V_408 ) ;
V_51 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & V_403 . V_167 , & V_56 . V_168 , 0 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( V_408 . V_307 & V_654 ) )
return - V_312 ;
if ( V_625 < V_7 . V_12 )
return - V_636 ;
return 0 ;
}
static int F_429 ( struct V_2 * V_2 , void * V_624 ,
T_9 V_625 )
{
struct V_60 V_61 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_649 ;
do {
V_8 = F_428 ( V_2 , V_624 , V_625 ) ;
F_430 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_431 ( struct V_2 * V_2 ,
struct V_1 * V_420 ,
struct V_419 * V_408 ,
struct V_1 * V_392 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_100 ( V_2 ) ;
const T_1 V_252 [ 3 ] = { 0 , 0 , V_383 } ;
struct V_402 V_403 = {
. V_255 = F_108 ( V_2 ) ,
. V_409 = & V_6 ,
. V_14 = V_14 ,
. V_252 = V_252 ,
. V_7 = V_420 ,
} ;
struct V_404 V_56 = {
. V_408 = V_408 ,
. V_7 = V_392 ,
. V_14 = V_14 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_405 ] ,
. V_324 = & V_403 ,
. V_325 = & V_56 ,
} ;
int V_316 ;
F_142 ( & V_403 . V_66 , & V_418 ) ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & V_403 . V_167 , & V_56 . V_168 , 1 ) ;
if ( V_316 )
F_8 ( L_41 , V_34 , V_316 ) ;
return V_316 ;
}
static int F_432 ( struct V_2 * V_2 ,
struct V_1 * V_420 ,
struct V_419 * V_408 ,
struct V_1 * V_392 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_431 ( V_2 , V_420 ,
V_408 , V_392 ) ;
F_433 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int
F_434 ( struct V_2 * V_2 , const void * V_624 , T_9 V_625 )
{
struct V_1 V_420 , * V_392 = NULL ;
struct V_419 V_408 ;
struct V_326 * V_360 ;
int V_316 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_649 ;
F_96 ( & V_408 ) ;
V_420 . V_655 = 0 ;
V_420 . V_656 = 0 ;
V_420 . V_7 = ( char * ) V_624 ;
V_420 . V_12 = V_625 ;
V_360 = F_435 () ;
if ( F_51 ( V_360 ) )
return F_84 ( V_360 ) ;
V_392 = F_102 ( F_100 ( V_2 ) , V_393 ) ;
if ( F_51 ( V_392 ) ) {
V_316 = - F_84 ( V_392 ) ;
goto V_151;
}
V_316 = F_432 ( V_2 , & V_420 , & V_408 , V_392 ) ;
if ( V_316 == 0 )
F_249 ( V_2 , & V_408 , V_392 ) ;
F_110 ( V_392 ) ;
V_151:
F_228 ( V_360 ) ;
return V_316 ;
}
static void F_436 ( const struct V_62 * V_63 ,
T_12 * V_657 )
{
T_3 V_258 [ 2 ] ;
if ( F_33 ( V_658 , & V_63 -> V_108 ) ) {
V_258 [ 0 ] = 0 ;
V_258 [ 1 ] = F_437 ( V_659 + 1 ) ;
} else {
struct V_660 * V_661 = F_438 ( V_63 -> V_662 , V_663 ) ;
V_258 [ 0 ] = F_437 ( V_661 -> V_664 . V_665 ) ;
V_258 [ 1 ] = F_437 ( V_661 -> V_664 . V_666 ) ;
}
memcpy ( V_657 -> V_165 , V_258 , sizeof( V_657 -> V_165 ) ) ;
}
static int
F_439 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_667 ;
if ( V_63 -> V_668 != NULL )
return 0 ;
F_150 () ;
V_12 = 14 + strlen ( V_63 -> V_669 ) + 1 +
strlen ( F_440 ( V_63 -> V_112 , V_670 ) ) +
1 +
strlen ( F_440 ( V_63 -> V_112 , V_671 ) ) +
1 ;
F_153 () ;
if ( V_12 > V_672 + 1 )
return - V_27 ;
V_667 = F_294 ( V_12 , V_393 ) ;
if ( ! V_667 )
return - V_134 ;
F_150 () ;
F_441 ( V_667 , V_12 , L_42 ,
V_63 -> V_669 ,
F_440 ( V_63 -> V_112 , V_670 ) ,
F_440 ( V_63 -> V_112 , V_671 ) ) ;
F_153 () ;
V_63 -> V_668 = V_667 ;
return 0 ;
}
static int
F_442 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_667 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_673 ) + 1 +
strlen ( V_63 -> V_112 -> V_674 ) + 1 ;
if ( V_12 > V_672 + 1 )
return - V_27 ;
V_667 = F_294 ( V_12 , V_393 ) ;
if ( ! V_667 )
return - V_134 ;
F_441 ( V_667 , V_12 , L_43 ,
V_63 -> V_675 -> V_676 , V_63 -> V_444 ,
V_673 ,
V_63 -> V_112 -> V_674 ) ;
V_63 -> V_668 = V_667 ;
return 0 ;
}
static int
F_443 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_667 ;
if ( V_63 -> V_668 != NULL )
return 0 ;
if ( V_673 [ 0 ] != '\0' )
return F_442 ( V_63 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_63 -> V_112 -> V_674 ) + 1 ;
if ( V_12 > V_672 + 1 )
return - V_27 ;
V_667 = F_294 ( V_12 , V_393 ) ;
if ( ! V_667 )
return - V_134 ;
F_441 ( V_667 , V_12 , L_44 ,
V_63 -> V_675 -> V_676 , V_63 -> V_444 ,
V_63 -> V_112 -> V_674 ) ;
V_63 -> V_668 = V_667 ;
return 0 ;
}
static unsigned int
F_444 ( const struct V_62 * V_63 , char * V_624 , T_9 V_12 )
{
if ( strchr ( V_63 -> V_669 , ':' ) != NULL )
return F_441 ( V_624 , V_12 , L_45 ) ;
else
return F_441 ( V_624 , V_12 , L_46 ) ;
}
static void F_445 ( struct V_104 * V_105 , void * V_163 )
{
struct V_677 * V_678 = V_163 ;
if ( V_105 -> V_109 == 0 )
V_678 -> V_679 = F_224 ( V_105 -> V_680 -> V_681 ) ;
}
int F_446 ( struct V_62 * V_63 , T_1 V_682 ,
unsigned short V_683 , struct V_326 * V_360 ,
struct V_684 * V_56 )
{
T_12 V_685 ;
struct V_677 V_686 = {
. V_685 = & V_685 ,
. V_687 = V_682 ,
. V_688 = V_63 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_689 ] ,
. V_324 = & V_686 ,
. V_325 = V_56 ,
. V_326 = V_360 ,
} ;
struct V_104 * V_105 ;
struct V_171 V_327 = {
. V_173 = V_63 -> V_112 ,
. V_169 = & V_170 ,
. V_174 = & V_690 ,
. V_177 = & V_686 ,
. V_223 = V_622 ,
} ;
int V_316 ;
F_436 ( V_63 , & V_685 ) ;
if ( F_33 ( V_691 , & V_63 -> V_692 ) )
V_316 = F_443 ( V_63 ) ;
else
V_316 = F_439 ( V_63 ) ;
if ( V_316 )
goto V_151;
V_686 . V_693 =
F_444 ( V_63 ,
V_686 . V_694 ,
sizeof( V_686 . V_694 ) ) ;
V_686 . V_695 = F_441 ( V_686 . V_696 ,
sizeof( V_686 . V_696 ) , L_47 ,
V_63 -> V_669 , V_683 >> 8 , V_683 & 255 ) ;
F_8 ( L_48 ,
V_63 -> V_112 -> V_113 -> V_697 -> V_698 ,
V_63 -> V_668 ) ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) ) {
V_316 = F_84 ( V_105 ) ;
goto V_151;
}
V_316 = V_105 -> V_109 ;
if ( V_686 . V_679 ) {
V_63 -> V_699 = F_447 ( V_686 . V_679 ) ;
F_228 ( V_686 . V_679 ) ;
}
F_85 ( V_105 ) ;
V_151:
F_448 ( V_63 , V_316 ) ;
F_8 ( L_49 , V_316 ) ;
return V_316 ;
}
int F_449 ( struct V_62 * V_63 ,
struct V_684 * V_403 ,
struct V_326 * V_360 )
{
struct V_169 V_170 = {
. V_321 = & V_322 [ V_700 ] ,
. V_324 = V_403 ,
. V_326 = V_360 ,
} ;
int V_316 ;
F_8 ( L_50 ,
V_63 -> V_112 -> V_113 -> V_697 -> V_698 ,
V_63 -> V_246 ) ;
V_316 = F_406 ( V_63 -> V_112 , & V_170 , V_622 ) ;
F_450 ( V_63 , V_316 ) ;
F_8 ( L_51 , V_316 ) ;
return V_316 ;
}
static void F_451 ( struct V_104 * V_105 , void * V_163 )
{
struct V_701 * V_165 = V_163 ;
if ( ! F_73 ( V_105 , & V_165 -> V_56 . V_168 ) )
return;
F_452 ( & V_165 -> args , & V_165 -> V_56 , V_105 -> V_109 ) ;
switch ( V_105 -> V_109 ) {
case 0 :
F_44 ( V_165 -> V_56 . V_14 , V_165 -> V_117 ) ;
case - V_72 :
case - V_71 :
case - V_73 :
case - V_95 :
case - V_77 :
case - V_76 :
V_105 -> V_109 = 0 ;
if ( V_165 -> V_424 )
F_267 ( V_165 -> V_2 , V_165 -> V_426 ) ;
break;
default:
if ( F_38 ( V_105 , V_165 -> V_56 . V_14 ,
NULL , NULL ) == - V_110 ) {
F_68 ( V_105 ) ;
return;
}
}
V_165 -> V_304 = V_105 -> V_109 ;
}
static void F_453 ( void * V_163 )
{
struct V_701 * V_165 = V_163 ;
struct V_2 * V_2 = V_165 -> V_2 ;
if ( V_2 ) {
if ( V_165 -> V_424 )
F_264 ( V_2 ) ;
F_454 ( V_2 ) ;
}
F_111 ( V_163 ) ;
}
static void F_455 ( struct V_104 * V_105 , void * V_165 )
{
struct V_701 * V_702 ;
V_702 = (struct V_701 * ) V_165 ;
if ( F_260 ( V_702 -> V_2 , V_105 ) )
return;
if ( V_702 -> V_424 )
F_269 ( V_702 -> V_2 , & V_702 -> V_426 ) ;
F_76 ( V_702 -> V_56 . V_14 ,
& V_702 -> args . V_167 ,
& V_702 -> V_56 . V_168 ,
V_105 ) ;
}
static int F_456 ( struct V_2 * V_2 , struct V_326 * V_360 , const T_4 * V_66 , int V_703 )
{
struct V_701 * V_165 ;
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_704 ] ,
. V_326 = V_360 ,
} ;
struct V_171 V_327 = {
. V_173 = V_14 -> V_100 ,
. V_169 = & V_170 ,
. V_174 = & V_705 ,
. V_223 = V_331 ,
} ;
int V_316 = 0 ;
V_165 = F_101 ( sizeof( * V_165 ) , V_313 ) ;
if ( V_165 == NULL )
return - V_134 ;
F_46 ( & V_165 -> args . V_167 , & V_165 -> V_56 . V_168 , 1 ) ;
F_273 ( V_14 -> V_62 ,
V_436 ,
& V_327 . V_173 , & V_170 ) ;
V_165 -> args . V_442 = & V_165 -> V_255 ;
V_165 -> args . V_66 = & V_165 -> V_66 ;
V_165 -> args . V_252 = V_14 -> V_438 ;
F_200 ( & V_165 -> V_255 , F_108 ( V_2 ) ) ;
F_142 ( & V_165 -> V_66 , V_66 ) ;
V_165 -> V_56 . V_408 = & V_165 -> V_408 ;
V_165 -> V_56 . V_14 = V_14 ;
F_96 ( V_165 -> V_56 . V_408 ) ;
V_165 -> V_117 = V_161 ;
V_165 -> V_304 = 0 ;
V_165 -> V_2 = F_457 ( V_2 ) ;
if ( V_165 -> V_2 )
V_165 -> V_424 = F_270 ( V_2 ) ;
V_327 . V_177 = V_165 ;
V_170 . V_324 = & V_165 -> args ;
V_170 . V_325 = & V_165 -> V_56 ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
if ( ! V_703 )
goto V_151;
V_316 = F_122 ( V_105 ) ;
if ( V_316 != 0 )
goto V_151;
V_316 = V_165 -> V_304 ;
if ( V_316 == 0 )
F_458 ( V_2 , & V_165 -> V_408 ) ;
else
F_165 ( V_2 , & V_165 -> V_408 ) ;
V_151:
F_85 ( V_105 ) ;
return V_316 ;
}
int F_459 ( struct V_2 * V_2 , struct V_326 * V_360 , const T_4 * V_66 , int V_703 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_456 ( V_2 , V_360 , V_66 , V_703 ) ;
F_460 ( V_2 , V_66 , V_8 ) ;
switch ( V_8 ) {
case - V_77 :
case - V_76 :
case 0 :
return 0 ;
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static unsigned long
F_461 ( unsigned long V_50 )
{
F_19 ( V_50 ) ;
V_50 <<= 1 ;
if ( V_50 > V_706 )
return V_706 ;
return V_50 ;
}
static int F_462 ( struct V_64 * V_65 , int V_707 , struct V_708 * V_709 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_710 V_403 = {
. V_255 = F_108 ( V_2 ) ,
. V_711 = V_709 ,
} ;
struct V_712 V_56 = {
. V_713 = V_709 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_714 ] ,
. V_324 = & V_403 ,
. V_325 = & V_56 ,
. V_326 = V_65 -> V_236 -> V_301 ,
} ;
struct V_292 * V_293 ;
int V_316 ;
V_403 . V_715 . V_245 = V_63 -> V_246 ;
V_316 = F_463 ( V_65 , V_709 ) ;
if ( V_316 != 0 )
goto V_151;
V_293 = V_709 -> V_716 . V_717 . V_236 ;
V_403 . V_715 . V_247 = V_293 -> V_718 . V_250 ;
V_403 . V_715 . V_719 = V_14 -> V_719 ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & V_403 . V_167 , & V_56 . V_168 , 1 ) ;
switch ( V_316 ) {
case 0 :
V_709 -> V_720 = V_721 ;
break;
case - V_318 :
V_316 = 0 ;
}
V_709 -> V_722 -> V_723 ( V_709 ) ;
V_709 -> V_722 = NULL ;
V_151:
return V_316 ;
}
static int F_464 ( struct V_64 * V_65 , int V_707 , struct V_708 * V_709 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_462 ( V_65 , V_707 , V_709 ) ;
F_465 ( V_709 , V_65 , V_707 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_65 -> V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_466 ( struct V_2 * V_2 , struct V_708 * V_711 )
{
return F_467 ( V_2 , V_711 ) ;
}
static struct V_724 * F_468 ( struct V_708 * V_711 ,
struct V_310 * V_311 ,
struct V_292 * V_293 ,
struct V_227 * V_213 )
{
struct V_724 * V_41 ;
struct V_2 * V_2 = V_293 -> V_294 -> V_2 ;
V_41 = F_101 ( sizeof( * V_41 ) , V_313 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_403 . V_255 = F_108 ( V_2 ) ;
V_41 -> V_403 . V_711 = & V_41 -> V_711 ;
V_41 -> V_403 . V_213 = V_213 ;
V_41 -> V_56 . V_213 = V_213 ;
V_41 -> V_293 = V_293 ;
F_105 ( & V_293 -> V_725 ) ;
V_41 -> V_311 = F_174 ( V_311 ) ;
memcpy ( & V_41 -> V_711 , V_711 , sizeof( V_41 -> V_711 ) ) ;
V_41 -> V_14 = F_100 ( V_2 ) ;
return V_41 ;
}
static void F_469 ( void * V_165 )
{
struct V_724 * V_163 = V_165 ;
F_115 ( V_163 -> V_403 . V_213 ) ;
F_470 ( V_163 -> V_293 ) ;
F_186 ( V_163 -> V_311 ) ;
F_111 ( V_163 ) ;
}
static void F_471 ( struct V_104 * V_105 , void * V_165 )
{
struct V_724 * V_163 = V_165 ;
if ( ! F_73 ( V_105 , & V_163 -> V_56 . V_168 ) )
return;
switch ( V_105 -> V_109 ) {
case 0 :
F_44 ( V_163 -> V_14 , V_163 -> V_117 ) ;
F_466 ( V_163 -> V_293 -> V_294 -> V_2 , & V_163 -> V_711 ) ;
if ( F_154 ( V_163 -> V_293 ,
& V_163 -> V_56 . V_66 ) )
break;
case - V_73 :
case - V_95 :
case - V_77 :
case - V_76 :
if ( ! F_152 ( & V_163 -> V_403 . V_66 ,
& V_163 -> V_293 -> V_296 ) )
F_68 ( V_105 ) ;
break;
default:
if ( F_38 ( V_105 , V_163 -> V_14 ,
NULL , NULL ) == - V_110 )
F_68 ( V_105 ) ;
}
F_158 ( V_163 -> V_403 . V_213 ) ;
}
static void F_472 ( struct V_104 * V_105 , void * V_165 )
{
struct V_724 * V_163 = V_165 ;
if ( F_199 ( V_163 -> V_403 . V_213 , V_105 ) != 0 )
goto V_332;
F_142 ( & V_163 -> V_403 . V_66 , & V_163 -> V_293 -> V_296 ) ;
if ( F_33 ( V_726 , & V_163 -> V_293 -> V_727 ) == 0 ) {
goto V_333;
}
V_163 -> V_117 = V_161 ;
if ( F_76 ( V_163 -> V_14 ,
& V_163 -> V_403 . V_167 ,
& V_163 -> V_56 . V_168 ,
V_105 ) != 0 )
F_158 ( V_163 -> V_403 . V_213 ) ;
return;
V_333:
V_105 -> V_344 = NULL ;
V_332:
F_73 ( V_105 , & V_163 -> V_56 . V_168 ) ;
}
static struct V_104 * F_473 ( struct V_708 * V_711 ,
struct V_310 * V_311 ,
struct V_292 * V_293 ,
struct V_227 * V_213 )
{
struct V_724 * V_165 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_728 ] ,
. V_326 = V_311 -> V_360 ,
} ;
struct V_171 V_327 = {
. V_173 = F_312 ( V_293 -> V_294 -> V_2 ) ,
. V_169 = & V_170 ,
. V_174 = & V_729 ,
. V_329 = V_330 ,
. V_223 = V_331 ,
} ;
F_273 ( F_100 ( V_293 -> V_294 -> V_2 ) -> V_62 ,
V_436 , & V_327 . V_173 , & V_170 ) ;
V_711 -> V_720 = V_721 ;
V_165 = F_468 ( V_711 , V_311 , V_293 , V_213 ) ;
if ( V_165 == NULL ) {
F_115 ( V_213 ) ;
return F_52 ( - V_134 ) ;
}
F_46 ( & V_165 -> V_403 . V_167 , & V_165 -> V_56 . V_168 , 1 ) ;
V_170 . V_324 = & V_165 -> V_403 ;
V_170 . V_325 = & V_165 -> V_56 ;
V_327 . V_177 = V_165 ;
return F_83 ( & V_327 ) ;
}
static int F_474 ( struct V_64 * V_65 , int V_707 , struct V_708 * V_709 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_221 * V_222 = V_65 -> V_236 ;
struct V_180 * V_181 = F_88 ( V_2 ) ;
struct V_227 * V_213 ;
struct V_292 * V_293 ;
struct V_104 * V_105 ;
struct V_227 * ( * V_228 ) ( struct V_229 * , T_7 ) ;
int V_316 = 0 ;
unsigned char V_730 = V_709 -> V_730 ;
V_316 = F_463 ( V_65 , V_709 ) ;
V_709 -> V_730 |= V_731 ;
F_475 ( & V_222 -> V_732 ) ;
F_476 ( & V_181 -> V_733 ) ;
if ( F_466 ( V_2 , V_709 ) == - V_312 ) {
F_477 ( & V_181 -> V_733 ) ;
F_478 ( & V_222 -> V_732 ) ;
goto V_151;
}
F_477 ( & V_181 -> V_733 ) ;
F_478 ( & V_222 -> V_732 ) ;
if ( V_316 != 0 )
goto V_151;
V_293 = V_709 -> V_716 . V_717 . V_236 ;
if ( F_33 ( V_726 , & V_293 -> V_727 ) == 0 )
goto V_151;
V_228 = F_100 ( V_2 ) -> V_62 -> V_175 -> V_228 ;
V_213 = V_228 ( & V_293 -> V_718 , V_393 ) ;
V_316 = - V_134 ;
if ( F_51 ( V_213 ) )
goto V_151;
V_105 = F_473 ( V_709 , F_304 ( V_709 -> V_734 ) , V_293 , V_213 ) ;
V_316 = F_84 ( V_105 ) ;
if ( F_51 ( V_105 ) )
goto V_151;
V_316 = F_122 ( V_105 ) ;
F_85 ( V_105 ) ;
V_151:
V_709 -> V_730 = V_730 ;
F_479 ( V_709 , V_65 , V_735 , V_316 ) ;
return V_316 ;
}
static struct V_736 * F_480 ( struct V_708 * V_711 ,
struct V_310 * V_311 , struct V_292 * V_293 ,
T_7 V_225 )
{
struct V_736 * V_41 ;
struct V_2 * V_2 = V_293 -> V_294 -> V_2 ;
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_227 * ( * V_228 ) ( struct V_229 * , T_7 ) ;
V_41 = F_101 ( sizeof( * V_41 ) , V_225 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_403 . V_255 = F_108 ( V_2 ) ;
V_41 -> V_403 . V_711 = & V_41 -> V_711 ;
V_41 -> V_403 . V_737 = F_481 ( & V_293 -> V_294 -> V_236 -> V_233 , V_225 ) ;
if ( F_51 ( V_41 -> V_403 . V_737 ) )
goto V_320;
V_228 = V_14 -> V_62 -> V_175 -> V_228 ;
V_41 -> V_403 . V_738 = V_228 ( & V_293 -> V_718 , V_225 ) ;
if ( F_51 ( V_41 -> V_403 . V_738 ) )
goto V_739;
V_41 -> V_403 . V_715 . V_245 = V_14 -> V_62 -> V_246 ;
V_41 -> V_403 . V_715 . V_247 = V_293 -> V_718 . V_250 ;
V_41 -> V_403 . V_715 . V_719 = V_14 -> V_719 ;
V_41 -> V_56 . V_738 = V_41 -> V_403 . V_738 ;
V_41 -> V_293 = V_293 ;
V_41 -> V_14 = V_14 ;
F_105 ( & V_293 -> V_725 ) ;
V_41 -> V_311 = F_174 ( V_311 ) ;
F_482 ( V_711 -> V_734 ) ;
memcpy ( & V_41 -> V_711 , V_711 , sizeof( V_41 -> V_711 ) ) ;
return V_41 ;
V_739:
F_115 ( V_41 -> V_403 . V_737 ) ;
V_320:
F_111 ( V_41 ) ;
return NULL ;
}
static void F_483 ( struct V_104 * V_105 , void * V_163 )
{
struct V_736 * V_165 = V_163 ;
struct V_64 * V_65 = V_165 -> V_293 -> V_294 ;
F_8 ( L_29 , V_34 ) ;
if ( F_199 ( V_165 -> V_403 . V_738 , V_105 ) != 0 )
goto V_332;
if ( ! F_33 ( V_726 , & V_165 -> V_293 -> V_727 ) ) {
if ( F_199 ( V_165 -> V_403 . V_737 , V_105 ) != 0 ) {
goto V_740;
}
F_142 ( & V_165 -> V_403 . V_281 ,
& V_65 -> V_281 ) ;
V_165 -> V_403 . V_741 = 1 ;
V_165 -> V_56 . V_737 = V_165 -> V_403 . V_737 ;
} else {
V_165 -> V_403 . V_741 = 0 ;
F_142 ( & V_165 -> V_403 . V_742 ,
& V_165 -> V_293 -> V_296 ) ;
}
if ( ! F_256 ( V_65 ) ) {
V_165 -> V_304 = - V_417 ;
V_105 -> V_344 = NULL ;
goto V_743;
}
V_165 -> V_117 = V_161 ;
if ( F_76 ( V_165 -> V_14 ,
& V_165 -> V_403 . V_167 ,
& V_165 -> V_56 . V_168 ,
V_105 ) == 0 )
return;
V_743:
F_158 ( V_165 -> V_403 . V_737 ) ;
V_740:
F_158 ( V_165 -> V_403 . V_738 ) ;
V_332:
F_73 ( V_105 , & V_165 -> V_56 . V_168 ) ;
F_8 ( L_52 , V_34 , V_165 -> V_304 ) ;
}
static void F_484 ( struct V_104 * V_105 , void * V_163 )
{
struct V_736 * V_165 = V_163 ;
struct V_292 * V_293 = V_165 -> V_293 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_73 ( V_105 , & V_165 -> V_56 . V_168 ) )
return;
V_165 -> V_304 = V_105 -> V_109 ;
switch ( V_105 -> V_109 ) {
case 0 :
F_44 ( F_100 ( F_14 ( V_165 -> V_311 -> V_4 ) ) ,
V_165 -> V_117 ) ;
if ( V_165 -> V_403 . V_744 ) {
V_165 -> V_711 . V_730 &= ~ ( V_745 | V_746 ) ;
if ( F_466 ( V_293 -> V_294 -> V_2 , & V_165 -> V_711 ) < 0 ) {
F_68 ( V_105 ) ;
break;
}
}
if ( V_165 -> V_403 . V_741 != 0 ) {
F_193 ( & V_293 -> V_718 , 0 ) ;
F_142 ( & V_293 -> V_296 , & V_165 -> V_56 . V_66 ) ;
F_139 ( V_726 , & V_293 -> V_727 ) ;
} else if ( ! F_154 ( V_293 , & V_165 -> V_56 . V_66 ) )
F_68 ( V_105 ) ;
break;
case - V_73 :
case - V_95 :
case - V_77 :
case - V_76 :
if ( V_165 -> V_403 . V_741 != 0 ) {
if ( ! F_152 ( & V_165 -> V_403 . V_281 ,
& V_293 -> V_294 -> V_281 ) )
F_68 ( V_105 ) ;
} else if ( ! F_152 ( & V_165 -> V_403 . V_742 ,
& V_293 -> V_296 ) )
F_68 ( V_105 ) ;
}
F_8 ( L_30 , V_34 , V_165 -> V_304 ) ;
}
static void F_485 ( void * V_163 )
{
struct V_736 * V_165 = V_163 ;
F_8 ( L_29 , V_34 ) ;
F_115 ( V_165 -> V_403 . V_737 ) ;
if ( V_165 -> V_319 != 0 ) {
struct V_104 * V_105 ;
V_105 = F_473 ( & V_165 -> V_711 , V_165 -> V_311 , V_165 -> V_293 ,
V_165 -> V_403 . V_738 ) ;
if ( ! F_51 ( V_105 ) )
F_486 ( V_105 ) ;
F_8 ( L_53 , V_34 ) ;
} else
F_115 ( V_165 -> V_403 . V_738 ) ;
F_470 ( V_165 -> V_293 ) ;
F_186 ( V_165 -> V_311 ) ;
F_487 ( V_165 -> V_711 . V_734 ) ;
F_111 ( V_165 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_488 ( struct V_13 * V_14 , struct V_292 * V_293 , int V_741 , int error )
{
switch ( error ) {
case - V_72 :
case - V_73 :
V_293 -> V_718 . V_223 &= ~ V_747 ;
if ( V_741 != 0 ||
F_33 ( V_726 , & V_293 -> V_727 ) != 0 )
F_23 ( V_14 , V_293 -> V_294 ) ;
break;
case - V_77 :
V_293 -> V_718 . V_223 &= ~ V_747 ;
case - V_76 :
F_24 ( V_14 -> V_62 ) ;
} ;
}
static int F_489 ( struct V_64 * V_65 , int V_707 , struct V_708 * V_711 , int V_748 )
{
struct V_736 * V_165 ;
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_749 ] ,
. V_326 = V_65 -> V_236 -> V_301 ,
} ;
struct V_171 V_327 = {
. V_173 = F_312 ( V_65 -> V_2 ) ,
. V_169 = & V_170 ,
. V_174 = & V_750 ,
. V_329 = V_330 ,
. V_223 = V_331 ,
} ;
int V_51 ;
F_8 ( L_29 , V_34 ) ;
V_165 = F_480 ( V_711 , F_304 ( V_711 -> V_734 ) ,
V_711 -> V_716 . V_717 . V_236 ,
V_748 == V_751 ? V_393 : V_313 ) ;
if ( V_165 == NULL )
return - V_134 ;
if ( F_490 ( V_707 ) )
V_165 -> V_403 . V_752 = 1 ;
F_46 ( & V_165 -> V_403 . V_167 , & V_165 -> V_56 . V_168 , 1 ) ;
V_170 . V_324 = & V_165 -> V_403 ;
V_170 . V_325 = & V_165 -> V_56 ;
V_327 . V_177 = V_165 ;
if ( V_748 > V_751 ) {
if ( V_748 == V_753 )
V_165 -> V_403 . V_754 = V_753 ;
F_47 ( & V_165 -> V_403 . V_167 ) ;
} else
V_165 -> V_403 . V_744 = 1 ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
V_51 = F_122 ( V_105 ) ;
if ( V_51 == 0 ) {
V_51 = V_165 -> V_304 ;
if ( V_51 )
F_488 ( V_165 -> V_14 , V_165 -> V_293 ,
V_165 -> V_403 . V_741 , V_51 ) ;
} else
V_165 -> V_319 = 1 ;
F_85 ( V_105 ) ;
F_8 ( L_30 , V_34 , V_51 ) ;
F_491 ( V_711 , V_65 , & V_165 -> V_56 . V_66 , V_707 , V_51 ) ;
return V_51 ;
}
static int F_492 ( struct V_64 * V_65 , struct V_708 * V_709 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_33 ( V_283 , & V_65 -> V_223 ) != 0 )
return 0 ;
V_8 = F_489 ( V_65 , V_735 , V_709 , V_753 ) ;
if ( V_8 != - V_91 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_493 ( struct V_64 * V_65 , struct V_708 * V_709 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
V_8 = F_463 ( V_65 , V_709 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_755 ) {
F_139 ( V_756 , & V_709 -> V_716 . V_717 . V_236 -> V_727 ) ;
return 0 ;
}
do {
if ( F_33 ( V_283 , & V_65 -> V_223 ) != 0 )
return 0 ;
V_8 = F_489 ( V_65 , V_735 , V_709 , V_757 ) ;
switch ( V_8 ) {
default:
goto V_151;
case - V_93 :
case - V_91 :
F_31 ( V_14 , V_8 , & V_61 ) ;
V_8 = 0 ;
}
} while ( V_61 . V_69 );
V_151:
return V_8 ;
}
static int F_494 ( struct V_64 * V_65 )
{
int V_316 , V_51 = - V_73 ;
struct V_292 * V_293 ;
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
F_173 (lsp, &state->lock_states, ls_locks) {
if ( F_33 ( V_726 , & V_293 -> V_727 ) ) {
struct V_326 * V_360 = V_293 -> V_294 -> V_236 -> V_301 ;
V_316 = F_225 ( V_14 ,
& V_293 -> V_296 ,
V_360 ) ;
F_495 ( V_65 , V_293 , V_316 ) ;
if ( V_316 != V_373 ) {
if ( V_316 != - V_73 )
F_227 ( V_14 ,
& V_293 -> V_296 ,
V_360 ) ;
F_141 ( V_726 , & V_293 -> V_727 ) ;
V_51 = V_316 ;
}
}
} ;
return V_51 ;
}
static int F_496 ( struct V_64 * V_65 , struct V_708 * V_709 )
{
int V_316 = V_373 ;
if ( F_33 ( V_758 , & V_65 -> V_223 ) )
V_316 = F_494 ( V_65 ) ;
if ( V_316 != V_373 )
V_316 = F_493 ( V_65 , V_709 ) ;
return V_316 ;
}
static int F_497 ( struct V_64 * V_65 , int V_707 , struct V_708 * V_709 )
{
struct V_180 * V_181 = F_88 ( V_65 -> V_2 ) ;
struct V_221 * V_222 = V_65 -> V_236 ;
unsigned char V_730 = V_709 -> V_730 ;
int V_316 = - V_759 ;
if ( ( V_730 & V_760 ) &&
! F_33 ( V_386 , & V_65 -> V_223 ) )
goto V_151;
V_316 = F_463 ( V_65 , V_709 ) ;
if ( V_316 != 0 )
goto V_151;
V_709 -> V_730 |= V_746 ;
V_316 = F_466 ( V_65 -> V_2 , V_709 ) ;
if ( V_316 < 0 )
goto V_151;
F_475 ( & V_222 -> V_732 ) ;
F_476 ( & V_181 -> V_733 ) ;
if ( F_33 ( V_283 , & V_65 -> V_223 ) ) {
V_709 -> V_730 = V_730 & ~ V_745 ;
V_316 = F_466 ( V_65 -> V_2 , V_709 ) ;
F_477 ( & V_181 -> V_733 ) ;
F_478 ( & V_222 -> V_732 ) ;
goto V_151;
}
F_477 ( & V_181 -> V_733 ) ;
F_478 ( & V_222 -> V_732 ) ;
V_316 = F_489 ( V_65 , V_707 , V_709 , V_751 ) ;
V_151:
V_709 -> V_730 = V_730 ;
return V_316 ;
}
static int F_498 ( struct V_64 * V_65 , int V_707 , struct V_708 * V_709 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_497 ( V_65 , V_707 , V_709 ) ;
if ( V_8 == - V_318 )
V_8 = - V_110 ;
V_8 = F_31 ( F_100 ( V_65 -> V_2 ) ,
V_8 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int
F_499 ( struct V_761 * V_762 , int V_707 , struct V_708 * V_709 )
{
struct V_310 * V_311 ;
struct V_64 * V_65 ;
unsigned long V_50 = V_763 ;
int V_316 ;
V_311 = F_304 ( V_762 ) ;
V_65 = V_311 -> V_65 ;
if ( V_709 -> V_764 < 0 || V_709 -> V_765 < 0 )
return - V_27 ;
if ( F_500 ( V_707 ) ) {
if ( V_65 != NULL )
return F_464 ( V_65 , V_766 , V_709 ) ;
return 0 ;
}
if ( ! ( F_501 ( V_707 ) || F_490 ( V_707 ) ) )
return - V_27 ;
if ( V_709 -> V_720 == V_721 ) {
if ( V_65 != NULL )
return F_474 ( V_65 , V_707 , V_709 ) ;
return 0 ;
}
if ( V_65 == NULL )
return - V_759 ;
switch ( V_709 -> V_720 ) {
case V_767 :
if ( ! ( V_762 -> V_768 & V_194 ) )
return - V_417 ;
break;
case V_769 :
if ( ! ( V_762 -> V_768 & V_195 ) )
return - V_417 ;
}
do {
V_316 = F_498 ( V_65 , V_707 , V_709 ) ;
if ( ( V_316 != - V_110 ) || F_501 ( V_707 ) )
break;
V_50 = F_461 ( V_50 ) ;
V_316 = - V_58 ;
if ( F_502 () )
break;
} while( V_316 < 0 );
return V_316 ;
}
int F_503 ( struct V_708 * V_711 , struct V_64 * V_65 , const T_4 * V_66 )
{
struct V_13 * V_14 = F_100 ( V_65 -> V_2 ) ;
int V_8 ;
V_8 = F_463 ( V_65 , V_711 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_489 ( V_65 , V_735 , V_711 , V_751 ) ;
return F_187 ( V_14 , V_65 , V_66 , V_8 ) ;
}
static void F_504 ( struct V_104 * V_105 , void * V_163 )
{
struct V_770 * V_165 = V_163 ;
struct V_13 * V_14 = V_165 -> V_14 ;
F_48 ( V_14 -> V_62 -> V_162 ,
& V_165 -> args . V_167 , & V_165 -> V_56 . V_168 , V_105 ) ;
V_165 -> args . V_715 . V_245 = V_14 -> V_62 -> V_246 ;
V_165 -> V_117 = V_161 ;
}
static void F_505 ( struct V_104 * V_105 , void * V_163 )
{
struct V_770 * V_165 = V_163 ;
struct V_13 * V_14 = V_165 -> V_14 ;
F_58 ( V_105 , & V_165 -> V_56 . V_168 ) ;
switch ( V_105 -> V_109 ) {
case 0 :
F_44 ( V_14 , V_165 -> V_117 ) ;
break;
case - V_78 :
case - V_76 :
F_24 ( V_14 -> V_62 ) ;
break;
case - V_80 :
case - V_91 :
if ( F_38 ( V_105 , V_14 ,
NULL , NULL ) == - V_110 )
F_68 ( V_105 ) ;
}
}
static void F_506 ( void * V_163 )
{
struct V_770 * V_165 = V_163 ;
F_507 ( V_165 -> V_14 , V_165 -> V_293 ) ;
F_111 ( V_163 ) ;
}
static void
F_508 ( struct V_13 * V_14 , struct V_292 * V_293 )
{
struct V_770 * V_165 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_771 ] ,
} ;
if ( V_14 -> V_62 -> V_175 -> V_342 != 0 )
return;
V_165 = F_294 ( sizeof( * V_165 ) , V_313 ) ;
if ( ! V_165 )
return;
V_165 -> V_293 = V_293 ;
V_165 -> V_14 = V_14 ;
V_165 -> args . V_715 . V_245 = V_14 -> V_62 -> V_246 ;
V_165 -> args . V_715 . V_247 = V_293 -> V_718 . V_250 ;
V_165 -> args . V_715 . V_719 = V_14 -> V_719 ;
V_170 . V_324 = & V_165 -> args ;
V_170 . V_325 = & V_165 -> V_56 ;
F_46 ( & V_165 -> args . V_167 , & V_165 -> V_56 . V_168 , 0 ) ;
F_404 ( V_14 -> V_100 , & V_170 , 0 , & V_772 , V_165 ) ;
}
static int F_509 ( const struct V_773 * V_774 ,
struct V_4 * V_775 , struct V_2 * V_2 ,
const char * V_776 , const void * V_624 ,
T_9 V_625 , int V_223 )
{
return F_426 ( V_2 , V_624 , V_625 ) ;
}
static int F_510 ( const struct V_773 * V_774 ,
struct V_4 * V_775 , struct V_2 * V_2 ,
const char * V_776 , void * V_624 , T_9 V_625 )
{
return F_420 ( V_2 , V_624 , V_625 ) ;
}
static bool F_511 ( struct V_4 * V_4 )
{
return F_407 ( F_100 ( F_14 ( V_4 ) ) ) ;
}
static int F_512 ( const struct V_773 * V_774 ,
struct V_4 * V_775 , struct V_2 * V_2 ,
const char * V_776 , const void * V_624 ,
T_9 V_625 , int V_223 )
{
if ( F_513 ( V_776 ) )
return F_434 ( V_2 , V_624 , V_625 ) ;
return - V_649 ;
}
static int F_514 ( const struct V_773 * V_774 ,
struct V_4 * V_775 , struct V_2 * V_2 ,
const char * V_776 , void * V_624 , T_9 V_625 )
{
if ( F_513 ( V_776 ) )
return F_429 ( V_2 , V_624 , V_625 ) ;
return - V_649 ;
}
static T_11
F_515 ( struct V_2 * V_2 , char * V_777 , T_9 V_778 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_516 ( V_2 , V_777 , V_778 ) ;
if ( V_778 && V_12 > V_778 )
return - V_636 ;
}
return V_12 ;
}
static T_11
F_515 ( struct V_2 * V_2 , char * V_777 , T_9 V_778 )
{
return 0 ;
}
static void F_296 ( struct V_419 * V_408 )
{
if ( ! ( ( ( V_408 -> V_307 & V_779 ) ||
( V_408 -> V_307 & V_780 ) ) &&
( V_408 -> V_307 & V_502 ) &&
( V_408 -> V_307 & V_781 ) ) )
return;
V_408 -> V_307 |= V_345 | V_518 |
V_519 | V_782 ;
V_408 -> V_268 = V_350 | V_521 | V_522 ;
V_408 -> V_523 = 2 ;
}
static int F_517 ( struct V_54 * V_100 , struct V_2 * V_3 ,
const struct V_504 * V_251 ,
struct V_506 * V_783 ,
struct V_505 * V_505 )
{
struct V_13 * V_14 = F_100 ( V_3 ) ;
T_1 V_252 [ 3 ] = {
[ 0 ] = V_784 | V_785 ,
} ;
struct V_786 args = {
. V_516 = F_108 ( V_3 ) ,
. V_251 = V_251 ,
. V_505 = V_505 ,
. V_252 = V_252 ,
} ;
struct V_787 V_56 = {
. V_783 = V_783 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_788 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
int V_316 ;
F_8 ( L_54 , V_34 ) ;
if ( F_100 ( V_3 ) -> V_15 [ 1 ] & V_789 )
V_252 [ 1 ] |= V_789 ;
else
V_252 [ 0 ] |= V_45 ;
F_96 ( & V_783 -> V_408 ) ;
V_783 -> V_14 = V_14 ;
V_783 -> V_790 = 0 ;
V_316 = F_86 ( V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
F_8 ( L_55 , V_34 , V_316 ) ;
return V_316 ;
}
int F_295 ( struct V_54 * V_100 , struct V_2 * V_3 ,
const struct V_504 * V_251 ,
struct V_506 * V_783 ,
struct V_505 * V_505 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_517 ( V_100 , V_3 , V_251 ,
V_783 , V_505 ) ;
F_518 ( V_3 , V_251 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_519 ( struct V_2 * V_2 ,
struct V_506 * V_507 ,
struct V_505 * V_505 , struct V_326 * V_360 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_100 ;
T_1 V_252 [ 2 ] = {
[ 0 ] = V_784 | V_785 ,
} ;
struct V_786 args = {
. V_245 = V_14 -> V_62 -> V_246 ,
. V_255 = F_108 ( V_2 ) ,
. V_505 = V_505 ,
. V_252 = V_252 ,
. V_791 = 1 ,
. V_792 = 1 ,
} ;
struct V_787 V_56 = {
. V_783 = V_507 ,
. V_791 = 1 ,
. V_792 = 1 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_788 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
unsigned long V_585 = V_161 ;
int V_316 ;
F_96 ( & V_507 -> V_408 ) ;
V_507 -> V_14 = V_14 ;
V_507 -> V_790 = 0 ;
F_46 ( & args . V_167 , & V_56 . V_168 , 0 ) ;
F_47 ( & args . V_167 ) ;
V_316 = F_82 ( V_55 , V_14 , & V_170 ,
& args . V_167 , & V_56 . V_168 ) ;
if ( V_316 )
return V_316 ;
F_44 ( V_14 , V_585 ) ;
return 0 ;
}
static int F_520 ( struct V_2 * V_2 ,
struct V_506 * V_507 ,
struct V_505 * V_505 , struct V_326 * V_360 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_100 ;
T_1 V_252 [ 2 ] = {
[ 0 ] = V_784 | V_785 ,
} ;
struct V_786 args = {
. V_255 = F_108 ( V_2 ) ,
. V_505 = V_505 ,
. V_252 = V_252 ,
. V_791 = 1 ,
} ;
struct V_787 V_56 = {
. V_783 = V_507 ,
. V_791 = 1 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_788 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
int V_316 ;
F_96 ( & V_507 -> V_408 ) ;
V_507 -> V_14 = V_14 ;
V_507 -> V_790 = 0 ;
F_46 ( & args . V_167 , & V_56 . V_168 , 0 ) ;
F_47 ( & args . V_167 ) ;
V_316 = F_82 ( V_55 , V_14 , & V_170 ,
& args . V_167 , & V_56 . V_168 ) ;
if ( V_316 == V_793 &&
V_56 . V_168 . V_154 & V_794 )
V_316 = - V_80 ;
return V_316 ;
}
int F_521 ( struct V_2 * V_2 ,
struct V_506 * V_507 ,
struct V_505 * V_505 , struct V_326 * V_360 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_795 * V_796 =
V_63 -> V_175 -> V_797 ;
struct V_60 V_61 = { } ;
int V_316 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_503 . V_798 ,
( unsigned long long ) V_14 -> V_503 . V_799 ,
V_63 -> V_99 ) ;
F_522 ( F_108 ( V_2 ) , V_34 ) ;
do {
V_316 = V_796 -> V_800 ( V_2 , V_507 , V_505 , V_360 ) ;
if ( V_316 != - V_91 )
break;
F_31 ( V_14 , V_316 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_316 ;
}
static int F_523 ( struct V_2 * V_2 , struct V_326 * V_360 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_62 * V_63 = F_100 ( V_2 ) -> V_62 ;
struct V_54 * V_55 = V_14 -> V_100 ;
struct V_801 args = {
. V_255 = F_108 ( V_2 ) ,
. V_245 = V_63 -> V_246 ,
. V_792 = 1 ,
} ;
struct V_802 V_56 = {
. V_792 = 1 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_803 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
unsigned long V_585 = V_161 ;
int V_316 ;
V_56 . V_255 = F_524 () ;
if ( V_56 . V_255 == NULL )
return - V_134 ;
F_46 ( & args . V_167 , & V_56 . V_168 , 0 ) ;
F_47 ( & args . V_167 ) ;
V_316 = F_82 ( V_55 , V_14 , & V_170 ,
& args . V_167 , & V_56 . V_168 ) ;
F_525 ( V_56 . V_255 ) ;
if ( V_316 )
return V_316 ;
F_40 ( V_63 , V_585 ) ;
return 0 ;
}
static int F_526 ( struct V_2 * V_2 , struct V_326 * V_360 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_100 ;
struct V_801 args = {
. V_255 = F_108 ( V_2 ) ,
} ;
struct V_802 V_56 = {
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_803 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
int V_316 ;
V_56 . V_255 = F_524 () ;
if ( V_56 . V_255 == NULL )
return - V_134 ;
F_46 ( & args . V_167 , & V_56 . V_168 , 0 ) ;
F_47 ( & args . V_167 ) ;
V_316 = F_82 ( V_55 , V_14 , & V_170 ,
& args . V_167 , & V_56 . V_168 ) ;
F_525 ( V_56 . V_255 ) ;
if ( V_316 == V_793 &&
V_56 . V_168 . V_154 & V_794 )
V_316 = - V_80 ;
return V_316 ;
}
int F_527 ( struct V_2 * V_2 , struct V_326 * V_360 )
{
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_795 * V_796 =
V_63 -> V_175 -> V_797 ;
struct V_60 V_61 = { } ;
int V_316 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_503 . V_798 ,
( unsigned long long ) V_14 -> V_503 . V_799 ,
V_63 -> V_99 ) ;
F_522 ( F_108 ( V_2 ) , V_34 ) ;
do {
V_316 = V_796 -> V_804 ( V_2 , V_360 ) ;
if ( V_316 != - V_91 )
break;
F_31 ( V_14 , V_316 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_316 ;
}
static int F_528 ( struct V_2 * V_3 , const struct V_504 * V_251 , struct V_805 * V_498 , bool V_806 )
{
int V_316 ;
struct V_807 args = {
. V_516 = F_108 ( V_3 ) ,
. V_251 = V_251 ,
} ;
struct V_808 V_56 = {
. V_498 = V_498 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_809 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
struct V_54 * V_55 = F_100 ( V_3 ) -> V_100 ;
struct V_326 * V_360 = NULL ;
if ( V_806 ) {
V_55 = F_100 ( V_3 ) -> V_62 -> V_112 ;
V_360 = F_529 ( F_100 ( V_3 ) -> V_62 ) ;
V_170 . V_326 = V_360 ;
}
F_8 ( L_57 , V_251 -> V_251 ) ;
F_273 ( F_100 ( V_3 ) -> V_62 ,
V_810 , & V_55 , & V_170 ) ;
V_316 = F_86 ( V_55 , F_100 ( V_3 ) , & V_170 , & args . V_167 ,
& V_56 . V_168 , 0 ) ;
F_8 ( L_58 , V_316 ) ;
if ( V_360 )
F_228 ( V_360 ) ;
return V_316 ;
}
int F_530 ( struct V_2 * V_3 , const struct V_504 * V_251 ,
struct V_805 * V_498 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( F_100 ( V_3 ) -> V_62 ) )
V_8 = F_528 ( V_3 , V_251 , V_498 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_528 ( V_3 , V_251 , V_498 , false ) ;
F_531 ( V_3 , V_251 , V_8 ) ;
V_8 = F_31 ( F_100 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static int F_532 ( T_1 V_223 )
{
if ( V_223 & ~ V_811 )
goto V_812;
if ( ( V_223 & V_813 ) &&
( V_223 & V_814 ) )
goto V_812;
if ( ! ( V_223 & ( V_815 ) ) )
goto V_812;
return V_373 ;
V_812:
return - V_816 ;
}
static bool
F_533 ( struct V_817 * V_818 ,
struct V_817 * V_819 )
{
if ( V_818 -> V_820 == V_819 -> V_820 &&
memcmp ( V_818 -> V_821 , V_819 -> V_821 , V_818 -> V_820 ) == 0 )
return true ;
return false ;
}
static void
F_534 ( struct V_104 * V_105 , void * V_163 )
{
}
static
int F_535 ( struct V_54 * V_55 ,
struct V_822 * V_823 ,
struct V_62 * V_63 ,
struct V_326 * V_360 )
{
int V_316 ;
struct V_824 args = {
. V_100 = V_63 ,
. V_3 = V_825 ,
} ;
struct V_826 V_56 ;
struct V_169 V_170 = {
. V_321 =
& V_322 [ V_827 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
struct V_171 V_327 = {
. V_173 = V_55 ,
. V_822 = V_823 ,
. V_174 = & V_828 ,
. V_169 = & V_170 ,
. V_223 = V_622 ,
} ;
struct V_104 * V_105 ;
F_8 ( L_11 , V_34 ) ;
F_536 ( & args . V_829 , & V_63 -> V_89 -> V_830 ) ;
if ( ! ( V_63 -> V_89 -> V_223 & V_831 ) )
args . V_3 = V_832 ;
if ( V_823 != F_221 ( V_55 -> V_833 ) )
args . V_3 = V_832 ;
V_105 = F_83 ( & V_327 ) ;
if ( ! F_51 ( V_105 ) ) {
V_316 = V_105 -> V_109 ;
F_85 ( V_105 ) ;
} else
V_316 = F_84 ( V_105 ) ;
F_537 ( V_63 , V_316 ) ;
if ( V_316 == 0 ) {
if ( memcmp ( V_56 . V_829 . V_165 ,
V_63 -> V_89 -> V_830 . V_165 , V_834 ) ) {
F_8 ( L_59 , V_34 ) ;
V_316 = - V_35 ;
goto V_151;
}
if ( ( V_56 . V_3 & args . V_3 ) != V_56 . V_3 || V_56 . V_3 == 0 ) {
F_8 ( L_60 ,
V_34 ) ;
V_316 = - V_35 ;
goto V_151;
}
if ( V_56 . V_835 != args . V_835 ) {
F_8 ( L_61 ,
V_34 ) ;
V_316 = - V_35 ;
goto V_151;
}
}
V_151:
F_8 ( L_62 , V_34 , V_316 ) ;
return V_316 ;
}
static int
F_538 ( struct V_54 * V_55 ,
struct V_822 * V_823 ,
void * V_163 )
{
struct V_836 * V_41 = V_163 ;
return F_535 ( V_55 , V_823 , V_41 -> V_63 , V_41 -> V_360 ) ;
}
int F_539 ( struct V_62 * V_63 , struct V_326 * V_360 )
{
struct V_836 V_165 = {
. V_63 = V_63 ,
. V_360 = V_360 ,
} ;
return F_540 ( V_63 -> V_112 ,
F_538 , & V_165 ) ;
}
static int F_541 ( struct V_62 * V_63 ,
struct V_837 * V_222 )
{
static const T_1 V_838 [ V_839 ] = {
[ 1 ] = 1 << ( V_840 - 32 ) |
1 << ( V_841 - 32 ) |
1 << ( V_842 - 32 ) |
1 << ( V_843 - 32 ) |
1 << ( V_844 - 32 )
} ;
unsigned int V_495 ;
if ( V_222 -> V_845 == V_846 ) {
F_542 ( V_847 , L_63 ) ;
for ( V_495 = 0 ; V_495 <= V_848 ; V_495 ++ ) {
if ( F_33 ( V_495 , V_222 -> V_849 . V_259 . V_850 ) )
F_542 ( V_847 , L_64 , V_495 ) ;
if ( F_33 ( V_495 , V_222 -> V_851 . V_259 . V_850 ) )
F_542 ( V_847 , L_65 , V_495 ) ;
}
for ( V_495 = 0 ; V_495 < V_839 ; V_495 ++ ) {
if ( V_222 -> V_849 . V_259 . V_852 [ V_495 ] & ~ V_838 [ V_495 ] ) {
F_542 ( V_847 , L_66 ) ;
return - V_27 ;
}
}
if ( F_33 ( V_840 , V_222 -> V_849 . V_259 . V_850 ) &&
F_33 ( V_842 , V_222 -> V_849 . V_259 . V_850 ) &&
F_33 ( V_843 , V_222 -> V_849 . V_259 . V_850 ) &&
F_33 ( V_844 , V_222 -> V_849 . V_259 . V_850 ) ) {
F_542 ( V_847 , L_67 ) ;
F_542 ( V_847 , L_68 ) ;
F_139 ( V_853 , & V_63 -> V_854 ) ;
} else {
F_542 ( V_847 , L_66 ) ;
return - V_27 ;
}
if ( F_33 ( V_855 , V_222 -> V_851 . V_259 . V_850 ) &&
F_33 ( V_856 , V_222 -> V_851 . V_259 . V_850 ) &&
F_33 ( V_857 , V_222 -> V_851 . V_259 . V_850 ) &&
F_33 ( V_858 , V_222 -> V_851 . V_259 . V_850 ) ) {
F_542 ( V_847 , L_69 ) ;
F_139 ( V_436 , & V_63 -> V_854 ) ;
}
if ( F_33 ( V_859 , V_222 -> V_851 . V_259 . V_850 ) ) {
F_542 ( V_847 , L_70 ) ;
F_139 ( V_860 ,
& V_63 -> V_854 ) ;
}
if ( F_33 ( V_861 , V_222 -> V_851 . V_259 . V_850 ) &&
F_33 ( V_862 , V_222 -> V_851 . V_259 . V_850 ) ) {
F_542 ( V_847 , L_71 ) ;
F_139 ( V_810 , & V_63 -> V_854 ) ;
}
if ( F_33 ( V_863 , V_222 -> V_851 . V_259 . V_850 ) &&
F_33 ( V_864 , V_222 -> V_851 . V_259 . V_850 ) ) {
F_542 ( V_847 , L_72 ) ;
F_139 ( V_865 , & V_63 -> V_854 ) ;
}
if ( F_33 ( V_866 , V_222 -> V_851 . V_259 . V_850 ) ) {
F_542 ( V_847 , L_73 ) ;
F_139 ( V_867 , & V_63 -> V_854 ) ;
}
if ( F_33 ( V_868 , V_222 -> V_851 . V_259 . V_850 ) ) {
F_542 ( V_847 , L_74 ) ;
F_139 ( V_869 , & V_63 -> V_854 ) ;
}
}
return 0 ;
}
static int F_543 ( struct V_62 * V_63 , struct V_326 * V_360 ,
T_1 V_870 )
{
T_12 V_37 ;
struct V_871 args = {
. V_37 = & V_37 ,
. V_100 = V_63 ,
#ifdef F_544
. V_223 = V_872 |
V_873 |
V_874 ,
#else
. V_223 = V_872 |
V_873 ,
#endif
} ;
struct V_875 V_56 = {
0
} ;
int V_316 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_876 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
F_436 ( V_63 , & V_37 ) ;
V_316 = F_443 ( V_63 ) ;
if ( V_316 )
goto V_151;
F_8 ( L_75 ,
V_63 -> V_112 -> V_113 -> V_697 -> V_698 ,
V_63 -> V_668 ) ;
V_56 . V_877 = F_101 ( sizeof( struct V_878 ) ,
V_313 ) ;
if ( F_381 ( V_56 . V_877 == NULL ) ) {
V_316 = - V_134 ;
goto V_151;
}
V_56 . V_821 = F_101 ( sizeof( struct V_817 ) ,
V_313 ) ;
if ( F_381 ( V_56 . V_821 == NULL ) ) {
V_316 = - V_134 ;
goto V_879;
}
V_56 . V_880 = F_101 ( sizeof( struct V_881 ) , V_313 ) ;
if ( F_381 ( V_56 . V_880 == NULL ) ) {
V_316 = - V_134 ;
goto V_882;
}
switch ( V_870 ) {
case V_883 :
args . V_884 . V_845 = V_883 ;
break;
case V_846 :
args . V_884 = V_885 ;
break;
default:
F_125 ( 1 ) ;
V_316 = - V_27 ;
goto V_886;
}
V_316 = F_406 ( V_63 -> V_112 , & V_170 , V_622 ) ;
F_545 ( V_63 , V_316 ) ;
if ( V_316 == 0 )
V_316 = F_532 ( V_56 . V_223 ) ;
if ( V_316 == 0 )
V_316 = F_541 ( V_63 , & V_56 . V_884 ) ;
if ( V_316 == 0 ) {
V_63 -> V_246 = V_56 . V_245 ;
V_63 -> V_887 = V_56 . V_223 ;
if ( ! ( V_56 . V_223 & V_888 ) ) {
F_141 ( V_889 ,
& V_63 -> V_89 -> V_890 ) ;
V_63 -> V_891 = V_56 . V_213 ;
}
F_111 ( V_63 -> V_892 ) ;
V_63 -> V_892 = V_56 . V_877 ;
V_56 . V_877 = NULL ;
F_111 ( V_63 -> V_893 ) ;
V_63 -> V_893 = V_56 . V_880 ;
V_56 . V_880 = NULL ;
if ( V_63 -> V_894 != NULL &&
! F_533 ( V_63 -> V_894 ,
V_56 . V_821 ) ) {
F_8 ( L_76 ,
V_34 ) ;
F_139 ( V_895 , & V_63 -> V_108 ) ;
F_111 ( V_63 -> V_894 ) ;
V_63 -> V_894 = NULL ;
}
if ( V_63 -> V_894 == NULL ) {
V_63 -> V_894 = V_56 . V_821 ;
V_56 . V_821 = NULL ;
}
}
V_886:
F_111 ( V_56 . V_880 ) ;
V_882:
F_111 ( V_56 . V_821 ) ;
V_879:
F_111 ( V_56 . V_877 ) ;
V_151:
if ( V_63 -> V_893 != NULL )
F_8 ( L_77
L_78 ,
V_63 -> V_893 -> V_896 , V_63 -> V_893 -> V_251 ,
V_63 -> V_893 -> V_897 . V_898 ,
V_63 -> V_893 -> V_897 . V_899 ) ;
F_8 ( L_79 , V_316 ) ;
return V_316 ;
}
int F_546 ( struct V_62 * V_63 , struct V_326 * V_360 )
{
T_5 V_900 = V_63 -> V_112 -> V_113 -> V_114 ;
int V_316 ;
if ( V_900 == V_115 ||
V_900 == V_116 ) {
V_316 = F_543 ( V_63 , V_360 , V_846 ) ;
if ( ! V_316 )
return 0 ;
}
return F_543 ( V_63 , V_360 , V_883 ) ;
}
static int F_547 ( struct V_62 * V_63 ,
struct V_326 * V_360 )
{
struct V_169 V_170 = {
. V_321 = & V_322 [ V_901 ] ,
. V_324 = V_63 ,
. V_326 = V_360 ,
} ;
int V_316 ;
V_316 = F_406 ( V_63 -> V_112 , & V_170 , V_622 ) ;
F_548 ( V_63 , V_316 ) ;
if ( V_316 )
F_8 ( L_80
L_81 , V_316 , V_63 -> V_99 ) ;
return V_316 ;
}
static int F_549 ( struct V_62 * V_63 ,
struct V_326 * V_360 )
{
unsigned int V_902 ;
int V_51 ;
for ( V_902 = V_903 ; V_902 != 0 ; V_902 -- ) {
V_51 = F_547 ( V_63 , V_360 ) ;
switch ( V_51 ) {
case - V_91 :
case - V_904 :
F_189 ( 1 ) ;
break;
default:
return V_51 ;
}
}
return 0 ;
}
int F_550 ( struct V_62 * V_63 )
{
struct V_326 * V_360 ;
int V_51 = 0 ;
if ( V_63 -> V_175 -> V_342 < 1 )
goto V_151;
if ( V_63 -> V_887 == 0 )
goto V_151;
if ( V_63 -> V_905 )
goto V_151;
V_360 = F_529 ( V_63 ) ;
V_51 = F_549 ( V_63 , V_360 ) ;
if ( V_360 )
F_228 ( V_360 ) ;
switch ( V_51 ) {
case 0 :
case - V_78 :
V_63 -> V_887 = 0 ;
}
V_151:
return V_51 ;
}
static void F_551 ( struct V_104 * V_105 ,
void * V_163 )
{
struct V_906 * V_165 =
(struct V_906 * ) V_163 ;
F_8 ( L_11 , V_34 ) ;
F_74 ( V_165 -> V_63 -> V_89 ,
& V_165 -> args -> V_907 ,
& V_165 -> V_56 -> V_908 ,
V_105 ) ;
F_8 ( L_82 , V_34 ) ;
}
static void F_552 ( struct V_104 * V_105 , void * V_163 )
{
struct V_906 * V_165 =
(struct V_906 * ) V_163 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_70 ( V_105 , & V_165 -> V_56 -> V_908 ) )
return;
switch ( V_105 -> V_109 ) {
case - V_91 :
case - V_93 :
F_8 ( L_83 , V_34 , V_105 -> V_109 ) ;
F_35 ( V_105 , V_53 ) ;
V_105 -> V_109 = 0 ;
case - V_94 :
F_68 ( V_105 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
int F_553 ( struct V_62 * V_63 , struct V_481 * V_581 )
{
struct V_104 * V_105 ;
struct V_909 args ;
struct V_910 V_56 = {
. V_911 = V_581 ,
} ;
struct V_906 V_165 = {
. args = & args ,
. V_56 = & V_56 ,
. V_63 = V_63 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_912 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
struct V_171 V_172 = {
. V_173 = V_63 -> V_112 ,
. V_169 = & V_170 ,
. V_174 = & V_913 ,
. V_177 = & V_165 ,
. V_223 = V_622 ,
} ;
int V_316 ;
F_46 ( & args . V_907 , & V_56 . V_908 , 0 ) ;
F_47 ( & args . V_907 ) ;
F_8 ( L_11 , V_34 ) ;
V_105 = F_83 ( & V_172 ) ;
if ( F_51 ( V_105 ) )
V_316 = F_84 ( V_105 ) ;
else {
V_316 = V_105 -> V_109 ;
F_85 ( V_105 ) ;
}
F_8 ( L_84 , V_34 , V_316 ) ;
return V_316 ;
}
static void F_554 ( struct V_914 * args ,
struct V_54 * V_55 )
{
unsigned int V_915 , V_916 ;
unsigned int V_917 = F_555 ( V_55 ) ;
V_915 = V_918 + V_919 ;
V_916 = V_918 + V_920 ;
args -> V_921 . V_915 = V_915 ;
args -> V_921 . V_916 = V_916 ;
args -> V_921 . V_922 = V_923 ;
args -> V_921 . V_924 = V_925 ;
F_8 ( L_85
L_86 ,
V_34 ,
args -> V_921 . V_915 , args -> V_921 . V_916 ,
args -> V_921 . V_922 , args -> V_921 . V_924 ) ;
args -> V_926 . V_915 = V_917 ;
args -> V_926 . V_916 = V_917 ;
args -> V_926 . V_927 = 0 ;
args -> V_926 . V_922 = V_928 ;
args -> V_926 . V_924 = V_929 ;
F_8 ( L_87
L_88 ,
V_34 ,
args -> V_926 . V_915 , args -> V_926 . V_916 ,
args -> V_926 . V_927 , args -> V_926 . V_922 ,
args -> V_926 . V_924 ) ;
}
static int F_556 ( struct V_914 * args ,
struct V_930 * V_56 )
{
struct V_931 * V_932 = & args -> V_921 ;
struct V_931 * V_933 = & V_56 -> V_921 ;
if ( V_933 -> V_916 > V_932 -> V_916 )
return - V_27 ;
if ( V_933 -> V_922 < V_932 -> V_922 )
return - V_27 ;
if ( V_933 -> V_924 == 0 )
return - V_27 ;
if ( V_933 -> V_924 > V_934 )
V_933 -> V_924 = V_934 ;
return 0 ;
}
static int F_557 ( struct V_914 * args ,
struct V_930 * V_56 )
{
struct V_931 * V_932 = & args -> V_926 ;
struct V_931 * V_933 = & V_56 -> V_926 ;
if ( ! ( V_56 -> V_223 & V_831 ) )
goto V_151;
if ( V_933 -> V_915 > V_932 -> V_915 )
return - V_27 ;
if ( V_933 -> V_916 < V_932 -> V_916 )
return - V_27 ;
if ( V_933 -> V_927 > V_932 -> V_927 )
return - V_27 ;
if ( V_933 -> V_922 != V_932 -> V_922 )
return - V_27 ;
if ( V_933 -> V_924 != V_932 -> V_924 )
return - V_27 ;
V_151:
return 0 ;
}
static int F_558 ( struct V_914 * args ,
struct V_930 * V_56 )
{
int V_51 ;
V_51 = F_556 ( args , V_56 ) ;
if ( V_51 )
return V_51 ;
return F_557 ( args , V_56 ) ;
}
static void F_559 ( struct V_139 * V_140 ,
struct V_930 * V_56 )
{
F_536 ( & V_140 -> V_830 , & V_56 -> V_829 ) ;
V_140 -> V_63 -> V_887 |= V_888 ;
F_139 ( V_889 , & V_140 -> V_890 ) ;
V_140 -> V_223 = V_56 -> V_223 ;
memcpy ( & V_140 -> V_921 , & V_56 -> V_921 , sizeof( V_140 -> V_921 ) ) ;
if ( V_56 -> V_223 & V_831 )
memcpy ( & V_140 -> V_926 , & V_56 -> V_926 ,
sizeof( V_140 -> V_926 ) ) ;
}
static int F_560 ( struct V_62 * V_63 ,
struct V_326 * V_360 )
{
struct V_139 * V_140 = V_63 -> V_89 ;
struct V_914 args = {
. V_100 = V_63 ,
. V_245 = V_63 -> V_246 ,
. V_213 = V_63 -> V_891 ,
. V_935 = V_936 ,
} ;
struct V_930 V_56 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_937 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
int V_316 ;
F_554 ( & args , V_63 -> V_112 ) ;
args . V_223 = ( V_938 | V_831 ) ;
V_316 = F_406 ( V_140 -> V_63 -> V_112 , & V_170 , V_622 ) ;
F_561 ( V_63 , V_316 ) ;
switch ( V_316 ) {
case - V_78 :
case - V_91 :
case - V_939 :
case - V_29 :
case - V_110 :
goto V_151;
} ;
V_63 -> V_891 ++ ;
if ( ! V_316 ) {
V_316 = F_558 ( & args , & V_56 ) ;
if ( V_316 )
goto V_151;
F_559 ( V_140 , & V_56 ) ;
}
V_151:
return V_316 ;
}
int F_562 ( struct V_62 * V_63 , struct V_326 * V_360 )
{
int V_316 ;
unsigned * V_940 ;
struct V_139 * V_140 = V_63 -> V_89 ;
F_8 ( L_89 , V_34 , V_63 , V_140 ) ;
V_316 = F_560 ( V_63 , V_360 ) ;
if ( V_316 )
goto V_151;
V_316 = F_563 ( V_140 ) ;
F_8 ( L_90 , V_316 ) ;
if ( V_316 )
goto V_151;
V_940 = ( unsigned * ) & V_140 -> V_830 . V_165 [ 0 ] ;
F_8 ( L_91 , V_34 ,
V_63 -> V_891 , V_940 [ 0 ] , V_940 [ 1 ] , V_940 [ 2 ] , V_940 [ 3 ] ) ;
V_151:
F_8 ( L_82 , V_34 ) ;
return V_316 ;
}
int F_564 ( struct V_139 * V_140 ,
struct V_326 * V_360 )
{
struct V_169 V_170 = {
. V_321 = & V_322 [ V_941 ] ,
. V_324 = V_140 ,
. V_326 = V_360 ,
} ;
int V_316 = 0 ;
F_8 ( L_92 ) ;
if ( ! F_132 ( V_889 , & V_140 -> V_890 ) )
return 0 ;
V_316 = F_406 ( V_140 -> V_63 -> V_112 , & V_170 , V_622 ) ;
F_565 ( V_140 -> V_63 , V_316 ) ;
if ( V_316 )
F_8 ( L_93
L_94 , V_316 ) ;
F_8 ( L_95 ) ;
return V_316 ;
}
static void F_566 ( void * V_165 )
{
struct V_942 * V_163 = V_165 ;
struct V_62 * V_63 = V_163 -> V_63 ;
if ( F_396 ( & V_63 -> V_616 ) > 1 )
F_397 ( V_63 ) ;
F_398 ( V_63 ) ;
F_111 ( V_163 ) ;
}
static int F_567 ( struct V_104 * V_105 , struct V_62 * V_63 )
{
switch( V_105 -> V_109 ) {
case - V_91 :
F_35 ( V_105 , V_52 ) ;
return - V_110 ;
default:
F_24 ( V_63 ) ;
}
return 0 ;
}
static void F_568 ( struct V_104 * V_105 , void * V_165 )
{
struct V_942 * V_163 = V_165 ;
struct V_62 * V_63 = V_163 -> V_63 ;
if ( ! F_70 ( V_105 , V_105 -> V_336 . V_325 ) )
return;
F_569 ( V_63 , V_105 -> V_109 ) ;
if ( V_105 -> V_109 < 0 ) {
F_8 ( L_96 , V_34 , V_105 -> V_109 ) ;
if ( F_396 ( & V_63 -> V_616 ) == 1 )
goto V_151;
if ( F_567 ( V_105 , V_63 ) == - V_110 ) {
F_68 ( V_105 ) ;
return;
}
}
F_8 ( L_97 , V_34 , V_105 -> V_336 . V_326 ) ;
V_151:
F_8 ( L_82 , V_34 ) ;
}
static void F_570 ( struct V_104 * V_105 , void * V_165 )
{
struct V_942 * V_163 = V_165 ;
struct V_62 * V_63 = V_163 -> V_63 ;
struct V_120 * args ;
struct V_121 * V_56 ;
args = V_105 -> V_336 . V_324 ;
V_56 = V_105 -> V_336 . V_325 ;
F_74 ( V_63 -> V_89 , args , V_56 , V_105 ) ;
}
static struct V_104 * F_571 ( struct V_62 * V_63 ,
struct V_326 * V_360 ,
bool V_943 )
{
struct V_942 * V_163 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_944 ] ,
. V_326 = V_360 ,
} ;
struct V_171 V_327 = {
. V_173 = V_63 -> V_112 ,
. V_169 = & V_170 ,
. V_174 = & V_945 ,
. V_223 = V_331 | V_622 ,
} ;
if ( ! F_403 ( & V_63 -> V_616 ) )
return F_52 ( - V_35 ) ;
V_163 = F_101 ( sizeof( * V_163 ) , V_313 ) ;
if ( V_163 == NULL ) {
F_398 ( V_63 ) ;
return F_52 ( - V_134 ) ;
}
F_46 ( & V_163 -> args , & V_163 -> V_56 , 0 ) ;
if ( V_943 )
F_47 ( & V_163 -> args ) ;
V_170 . V_324 = & V_163 -> args ;
V_170 . V_325 = & V_163 -> V_56 ;
V_163 -> V_63 = V_63 ;
V_327 . V_177 = V_163 ;
return F_83 ( & V_327 ) ;
}
static int F_572 ( struct V_62 * V_63 , struct V_326 * V_360 , unsigned V_620 )
{
struct V_104 * V_105 ;
int V_51 = 0 ;
if ( ( V_620 & V_946 ) == 0 )
return - V_110 ;
V_105 = F_571 ( V_63 , V_360 , false ) ;
if ( F_51 ( V_105 ) )
V_51 = F_84 ( V_105 ) ;
else
F_486 ( V_105 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_573 ( struct V_62 * V_63 , struct V_326 * V_360 )
{
struct V_104 * V_105 ;
int V_51 ;
V_105 = F_571 ( V_63 , V_360 , true ) ;
if ( F_51 ( V_105 ) ) {
V_51 = F_84 ( V_105 ) ;
goto V_151;
}
V_51 = F_123 ( V_105 ) ;
if ( ! V_51 )
V_51 = V_105 -> V_109 ;
F_85 ( V_105 ) ;
V_151:
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_574 ( struct V_104 * V_105 , void * V_165 )
{
struct V_947 * V_163 = V_165 ;
F_74 ( V_163 -> V_63 -> V_89 ,
& V_163 -> V_403 . V_167 ,
& V_163 -> V_56 . V_168 ,
V_105 ) ;
}
static int F_575 ( struct V_104 * V_105 , struct V_62 * V_63 )
{
switch( V_105 -> V_109 ) {
case 0 :
case - V_948 :
case - V_23 :
break;
case - V_91 :
F_35 ( V_105 , V_52 ) ;
case - V_94 :
return - V_110 ;
default:
F_24 ( V_63 ) ;
}
return 0 ;
}
static void F_576 ( struct V_104 * V_105 , void * V_165 )
{
struct V_947 * V_163 = V_165 ;
struct V_62 * V_63 = V_163 -> V_63 ;
struct V_121 * V_56 = & V_163 -> V_56 . V_168 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_70 ( V_105 , V_56 ) )
return;
F_577 ( V_63 , V_105 -> V_109 ) ;
if ( F_575 ( V_105 , V_63 ) == - V_110 ) {
F_68 ( V_105 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
static void F_578 ( void * V_165 )
{
struct V_947 * V_163 = V_165 ;
F_111 ( V_163 ) ;
}
static int F_579 ( struct V_62 * V_63 ,
struct V_326 * V_360 )
{
struct V_947 * V_163 ;
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_949 ] ,
. V_326 = V_360 ,
} ;
struct V_171 V_327 = {
. V_173 = V_63 -> V_112 ,
. V_169 = & V_170 ,
. V_174 = & V_950 ,
. V_223 = V_331 ,
} ;
int V_316 = - V_134 ;
F_8 ( L_11 , V_34 ) ;
V_163 = F_101 ( sizeof( * V_163 ) , V_313 ) ;
if ( V_163 == NULL )
goto V_151;
V_163 -> V_63 = V_63 ;
V_163 -> V_403 . V_951 = 0 ;
F_46 ( & V_163 -> V_403 . V_167 , & V_163 -> V_56 . V_168 , 0 ) ;
F_47 ( & V_163 -> V_403 . V_167 ) ;
V_170 . V_324 = & V_163 -> V_403 ;
V_170 . V_325 = & V_163 -> V_56 ;
V_327 . V_177 = V_163 ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) ) {
V_316 = F_84 ( V_105 ) ;
goto V_151;
}
V_316 = F_122 ( V_105 ) ;
if ( V_316 == 0 )
V_316 = V_105 -> V_109 ;
F_85 ( V_105 ) ;
return 0 ;
V_151:
F_8 ( L_16 , V_34 , V_316 ) ;
return V_316 ;
}
static void
F_580 ( struct V_104 * V_105 , void * V_163 )
{
struct V_952 * V_953 = V_163 ;
struct V_13 * V_14 = F_100 ( V_953 -> args . V_2 ) ;
struct V_139 * V_140 = F_77 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_74 ( V_140 , & V_953 -> args . V_167 ,
& V_953 -> V_56 . V_168 , V_105 ) ;
F_8 ( L_82 , V_34 ) ;
}
static void F_581 ( struct V_104 * V_105 , void * V_163 )
{
struct V_952 * V_953 = V_163 ;
F_8 ( L_11 , V_34 ) ;
F_63 ( V_105 , & V_953 -> V_56 . V_168 ) ;
F_8 ( L_82 , V_34 ) ;
}
static int
F_582 ( struct V_104 * V_105 ,
struct V_952 * V_953 , struct V_60 * V_61 )
{
struct V_2 * V_2 = V_953 -> args . V_2 ;
struct V_13 * V_14 = F_100 ( V_2 ) ;
struct V_954 * V_955 ;
int V_956 = V_105 -> V_109 ;
int V_8 , V_316 = 0 ;
F_583 ( V_957 ) ;
F_8 ( L_98 , V_34 , - V_105 -> V_109 ) ;
switch ( V_956 ) {
case 0 :
goto V_151;
case - V_958 :
V_316 = - V_959 ;
goto V_151;
case - V_960 :
V_316 = - V_961 ;
goto V_151;
case - V_19 :
if ( V_953 -> args . V_962 == 0 ) {
V_316 = - V_961 ;
goto V_151;
}
V_316 = - V_33 ;
break;
case - V_20 :
V_316 = - V_963 ;
break;
case - V_76 :
case - V_73 :
V_61 -> V_50 = 0 ;
F_41 ( & V_2 -> V_182 ) ;
V_955 = F_88 ( V_2 ) -> V_964 ;
if ( ! V_955 || F_33 ( V_965 , & V_955 -> V_966 ) ||
F_136 ( & V_953 -> args . V_66 ,
& V_953 -> args . V_311 -> V_65 -> V_66 ) ) {
F_43 ( & V_2 -> V_182 ) ;
V_61 -> V_65 = V_953 -> args . V_311 -> V_65 ;
break;
}
F_584 ( V_955 , & V_957 ) ;
F_43 ( & V_2 -> V_182 ) ;
F_585 ( & V_957 ) ;
V_316 = - V_110 ;
goto V_151;
}
V_8 = F_31 ( V_14 , V_956 , V_61 ) ;
if ( ! V_316 ) {
if ( V_61 -> V_69 )
V_316 = - V_110 ;
else
V_316 = V_8 ;
}
V_151:
F_8 ( L_82 , V_34 ) ;
return V_316 ;
}
static T_9 F_586 ( struct V_13 * V_14 )
{
T_1 V_916 = V_14 -> V_62 -> V_89 -> V_921 . V_916 ;
return F_587 ( 0 , V_916 ) ;
}
static void F_588 ( struct V_505 * * V_42 , T_9 V_967 )
{
int V_495 ;
if ( ! V_42 )
return;
for ( V_495 = 0 ; V_495 < V_967 ; V_495 ++ ) {
if ( ! V_42 [ V_495 ] )
break;
F_297 ( V_42 [ V_495 ] ) ;
}
F_111 ( V_42 ) ;
}
static struct V_505 * * F_589 ( T_9 V_967 , T_7 V_968 )
{
struct V_505 * * V_42 ;
int V_495 ;
V_42 = F_590 ( V_967 , sizeof( struct V_505 * ) , V_968 ) ;
if ( ! V_42 ) {
F_8 ( L_99 , V_34 , V_967 ) ;
return NULL ;
}
for ( V_495 = 0 ; V_495 < V_967 ; V_495 ++ ) {
V_42 [ V_495 ] = F_293 ( V_968 ) ;
if ( ! V_42 [ V_495 ] ) {
F_8 ( L_100 , V_34 ) ;
F_588 ( V_42 , V_967 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_591 ( void * V_163 )
{
struct V_952 * V_953 = V_163 ;
struct V_2 * V_2 = V_953 -> args . V_2 ;
struct V_13 * V_14 = F_100 ( V_2 ) ;
T_9 V_969 = F_586 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_588 ( V_953 -> args . V_964 . V_42 , V_969 ) ;
F_592 ( F_88 ( V_2 ) -> V_964 ) ;
F_186 ( V_953 -> args . V_311 ) ;
F_111 ( V_163 ) ;
F_8 ( L_82 , V_34 ) ;
}
struct V_970 *
F_593 ( struct V_952 * V_953 , long * V_50 , T_7 V_968 )
{
struct V_2 * V_2 = V_953 -> args . V_2 ;
struct V_13 * V_14 = F_100 ( V_2 ) ;
T_9 V_969 = F_586 ( V_14 ) ;
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_971 ] ,
. V_324 = & V_953 -> args ,
. V_325 = & V_953 -> V_56 ,
. V_326 = V_953 -> V_360 ,
} ;
struct V_171 V_327 = {
. V_173 = V_14 -> V_100 ,
. V_169 = & V_170 ,
. V_174 = & V_972 ,
. V_177 = V_953 ,
. V_223 = V_331 ,
} ;
struct V_970 * V_973 = NULL ;
struct V_60 V_61 = {
. V_2 = V_2 ,
. V_50 = * V_50 ,
} ;
int V_316 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_594 ( F_88 ( V_2 ) -> V_964 ) ;
V_953 -> args . V_964 . V_42 = F_589 ( V_969 , V_968 ) ;
if ( ! V_953 -> args . V_964 . V_42 ) {
F_591 ( V_953 ) ;
return F_52 ( - V_134 ) ;
}
V_953 -> args . V_964 . V_532 = V_969 * V_629 ;
V_953 -> V_56 . V_974 = & V_953 -> args . V_964 ;
V_953 -> V_56 . V_168 . V_126 = NULL ;
F_46 ( & V_953 -> args . V_167 , & V_953 -> V_56 . V_168 , 0 ) ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_275 ( V_105 ) ;
V_316 = F_122 ( V_105 ) ;
if ( V_316 == 0 ) {
V_316 = F_582 ( V_105 , V_953 , & V_61 ) ;
* V_50 = V_61 . V_50 ;
}
F_595 ( V_953 -> args . V_311 ,
& V_953 -> args . V_975 ,
& V_953 -> V_56 . V_975 ,
& V_953 -> V_56 . V_66 ,
V_316 ) ;
if ( V_316 == 0 && V_953 -> V_56 . V_974 -> V_12 )
V_973 = F_596 ( V_953 ) ;
F_72 ( & V_953 -> V_56 . V_168 ) ;
F_85 ( V_105 ) ;
F_8 ( L_16 , V_34 , V_316 ) ;
if ( V_316 )
return F_52 ( V_316 ) ;
return V_973 ;
}
static void
F_597 ( struct V_104 * V_105 , void * V_163 )
{
struct V_976 * V_977 = V_163 ;
F_8 ( L_11 , V_34 ) ;
F_74 ( V_977 -> V_63 -> V_89 ,
& V_977 -> args . V_167 ,
& V_977 -> V_56 . V_168 ,
V_105 ) ;
}
static void F_598 ( struct V_104 * V_105 , void * V_163 )
{
struct V_976 * V_977 = V_163 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_63 ( V_105 , & V_977 -> V_56 . V_168 ) )
return;
V_14 = F_100 ( V_977 -> args . V_2 ) ;
switch ( V_105 -> V_109 ) {
default:
V_105 -> V_109 = 0 ;
case 0 :
break;
case - V_91 :
if ( F_38 ( V_105 , V_14 , NULL , NULL ) != - V_110 )
break;
F_72 ( & V_977 -> V_56 . V_168 ) ;
F_68 ( V_105 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
static void F_599 ( void * V_163 )
{
struct V_976 * V_977 = V_163 ;
struct V_954 * V_955 = V_977 -> args . V_964 ;
F_583 ( V_978 ) ;
F_8 ( L_11 , V_34 ) ;
F_41 ( & V_955 -> V_979 -> V_182 ) ;
if ( V_977 -> V_56 . V_980 ) {
F_600 ( V_955 , & V_978 ,
& V_977 -> args . V_975 ,
F_601 ( V_977 -> args . V_66 . V_213 ) ) ;
F_602 ( V_955 , & V_977 -> V_56 . V_66 , true ) ;
} else
F_584 ( V_955 , & V_978 ) ;
F_603 ( V_955 ) ;
F_43 ( & V_955 -> V_979 -> V_182 ) ;
F_72 ( & V_977 -> V_56 . V_168 ) ;
F_585 ( & V_978 ) ;
F_592 ( V_977 -> args . V_964 ) ;
F_454 ( V_977 -> V_2 ) ;
F_111 ( V_163 ) ;
F_8 ( L_82 , V_34 ) ;
}
int F_604 ( struct V_976 * V_977 , bool V_981 )
{
struct V_104 * V_105 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_982 ] ,
. V_324 = & V_977 -> args ,
. V_325 = & V_977 -> V_56 ,
. V_326 = V_977 -> V_360 ,
} ;
struct V_171 V_327 = {
. V_173 = F_100 ( V_977 -> args . V_2 ) -> V_100 ,
. V_169 = & V_170 ,
. V_174 = & V_983 ,
. V_177 = V_977 ,
} ;
int V_316 = 0 ;
F_273 ( F_100 ( V_977 -> args . V_2 ) -> V_62 ,
V_860 ,
& V_327 . V_173 , & V_170 ) ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_981 ) {
V_977 -> V_2 = F_457 ( V_977 -> args . V_2 ) ;
if ( ! V_977 -> V_2 ) {
F_599 ( V_977 ) ;
return - V_110 ;
}
V_327 . V_223 |= V_331 ;
}
F_46 ( & V_977 -> args . V_167 , & V_977 -> V_56 . V_168 , 1 ) ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
if ( V_981 )
V_316 = V_105 -> V_109 ;
F_605 ( V_977 -> args . V_2 , & V_977 -> args . V_66 , V_316 ) ;
F_8 ( L_16 , V_34 , V_316 ) ;
F_85 ( V_105 ) ;
return V_316 ;
}
static int
F_606 ( struct V_13 * V_14 ,
struct V_984 * V_985 ,
struct V_326 * V_360 )
{
struct V_986 args = {
. V_985 = V_985 ,
. V_987 = V_988 |
V_989 ,
} ;
struct V_990 V_56 = {
. V_985 = V_985 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_991 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
int V_316 ;
F_8 ( L_11 , V_34 ) ;
V_316 = F_86 ( V_14 -> V_100 , V_14 , & V_170 , & args . V_167 , & V_56 . V_168 , 0 ) ;
if ( V_56 . V_992 & ~ args . V_987 )
F_8 ( L_101 , V_34 ) ;
if ( V_56 . V_992 != args . V_987 )
V_985 -> V_993 = 1 ;
F_8 ( L_16 , V_34 , V_316 ) ;
return V_316 ;
}
int F_607 ( struct V_13 * V_14 ,
struct V_984 * V_985 ,
struct V_326 * V_360 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_606 ( V_14 , V_985 , V_360 ) ,
& V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static void F_608 ( struct V_104 * V_105 , void * V_163 )
{
struct V_994 * V_165 = V_163 ;
struct V_13 * V_14 = F_100 ( V_165 -> args . V_2 ) ;
struct V_139 * V_140 = F_77 ( V_14 ) ;
F_74 ( V_140 ,
& V_165 -> args . V_167 ,
& V_165 -> V_56 . V_168 ,
V_105 ) ;
}
static void
F_609 ( struct V_104 * V_105 , void * V_163 )
{
struct V_994 * V_165 = V_163 ;
struct V_13 * V_14 = F_100 ( V_165 -> args . V_2 ) ;
if ( ! F_70 ( V_105 , & V_165 -> V_56 . V_168 ) )
return;
switch ( V_105 -> V_109 ) {
case - V_71 :
case - V_995 :
case - V_960 :
case - V_93 :
V_105 -> V_109 = 0 ;
case 0 :
break;
default:
if ( F_38 ( V_105 , V_14 , NULL , NULL ) == - V_110 ) {
F_68 ( V_105 ) ;
return;
}
}
}
static void F_610 ( void * V_163 )
{
struct V_994 * V_165 = V_163 ;
F_611 ( V_165 ) ;
F_458 ( V_165 -> args . V_2 ,
V_165 -> V_56 . V_408 ) ;
F_228 ( V_165 -> V_360 ) ;
F_454 ( V_165 -> V_2 ) ;
F_111 ( V_165 ) ;
}
int
F_612 ( struct V_994 * V_165 , bool V_981 )
{
struct V_169 V_170 = {
. V_321 = & V_322 [ V_996 ] ,
. V_324 = & V_165 -> args ,
. V_325 = & V_165 -> V_56 ,
. V_326 = V_165 -> V_360 ,
} ;
struct V_171 V_327 = {
. V_105 = & V_165 -> V_105 ,
. V_173 = F_312 ( V_165 -> args . V_2 ) ,
. V_169 = & V_170 ,
. V_174 = & V_997 ,
. V_177 = V_165 ,
} ;
struct V_104 * V_105 ;
int V_316 = 0 ;
F_8 ( L_102
L_103 , V_981 ,
V_165 -> args . V_998 ,
V_165 -> args . V_2 -> V_999 ) ;
if ( ! V_981 ) {
V_165 -> V_2 = F_457 ( V_165 -> args . V_2 ) ;
if ( V_165 -> V_2 == NULL ) {
F_610 ( V_165 ) ;
return - V_110 ;
}
V_327 . V_223 = V_331 ;
}
F_46 ( & V_165 -> args . V_167 , & V_165 -> V_56 . V_168 , 1 ) ;
V_105 = F_83 ( & V_327 ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
if ( V_981 )
V_316 = V_105 -> V_109 ;
F_613 ( V_165 -> args . V_2 , & V_165 -> args . V_66 , V_316 ) ;
F_8 ( L_104 , V_34 , V_316 ) ;
F_85 ( V_105 ) ;
return V_316 ;
}
static int
F_614 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 ,
struct V_805 * V_498 , bool V_806 )
{
struct V_1000 args = {
. V_1001 = V_1002 ,
} ;
struct V_808 V_56 = {
. V_498 = V_498 ,
} ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_1003 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
} ;
struct V_54 * V_55 = V_14 -> V_100 ;
struct V_326 * V_360 = NULL ;
int V_316 ;
if ( V_806 ) {
V_55 = V_14 -> V_62 -> V_112 ;
V_360 = F_529 ( V_14 -> V_62 ) ;
V_170 . V_326 = V_360 ;
}
F_8 ( L_11 , V_34 ) ;
V_316 = F_86 ( V_55 , V_14 , & V_170 , & args . V_167 ,
& V_56 . V_168 , 0 ) ;
F_8 ( L_16 , V_34 , V_316 ) ;
if ( V_360 )
F_228 ( V_360 ) ;
return V_316 ;
}
static int
F_615 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 , struct V_805 * V_498 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( V_14 -> V_62 ) )
V_8 = F_614 ( V_14 , V_442 , V_482 ,
V_498 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_614 ( V_14 , V_442 , V_482 ,
V_498 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_1004 :
goto V_151;
default:
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_69 );
V_151:
return V_8 ;
}
static int
F_616 ( struct V_13 * V_14 , struct V_441 * V_442 ,
struct V_481 * V_482 )
{
int V_8 ;
struct V_505 * V_505 ;
T_5 V_111 = V_1005 ;
struct V_805 * V_498 ;
struct V_1006 * V_1007 ;
int V_495 ;
V_505 = F_293 ( V_393 ) ;
if ( ! V_505 ) {
V_8 = - V_134 ;
goto V_151;
}
V_498 = F_410 ( V_505 ) ;
V_8 = F_615 ( V_14 , V_442 , V_482 , V_498 ) ;
if ( V_8 == - V_22 || V_8 == - V_1004 ) {
V_8 = F_286 ( V_14 , V_442 , V_482 ) ;
goto V_1008;
}
if ( V_8 )
goto V_1008;
for ( V_495 = 0 ; V_495 < V_498 -> V_1009 ; V_495 ++ ) {
V_1007 = & V_498 -> V_498 [ V_495 ] ;
switch ( V_1007 -> V_111 ) {
case V_494 :
case V_493 :
case V_1010 :
V_111 = F_617 ( V_1007 -> V_111 ,
& V_1007 -> V_1011 ) ;
break;
default:
V_111 = V_1005 ;
break;
}
if ( ! F_618 ( & V_14 -> V_496 , V_111 ) )
V_111 = V_1005 ;
if ( V_111 != V_1005 ) {
V_8 = F_284 ( V_14 , V_442 ,
V_482 , V_111 ) ;
if ( ! V_8 )
break;
}
}
if ( V_111 == V_1005 )
V_8 = - V_24 ;
V_1008:
F_424 ( V_505 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_151:
return V_8 ;
}
static int F_619 ( struct V_13 * V_14 ,
T_4 * V_66 ,
struct V_326 * V_360 )
{
int V_316 ;
struct V_1012 args = {
. V_66 = V_66 ,
} ;
struct V_1013 V_56 ;
struct V_169 V_170 = {
. V_321 = & V_322 [ V_1014 ] ,
. V_324 = & args ,
. V_325 = & V_56 ,
. V_326 = V_360 ,
} ;
struct V_54 * V_173 = V_14 -> V_100 ;
F_273 ( V_14 -> V_62 , V_865 ,
& V_173 , & V_170 ) ;
F_8 ( L_105 , V_66 ) ;
F_46 ( & args . V_167 , & V_56 . V_168 , 0 ) ;
F_47 ( & args . V_167 ) ;
V_316 = F_82 ( V_173 , V_14 , & V_170 ,
& args . V_167 , & V_56 . V_168 ) ;
if ( V_316 != V_373 ) {
F_8 ( L_106 , V_316 ) ;
return V_316 ;
}
F_8 ( L_107 , - V_56 . V_316 ) ;
return - V_56 . V_316 ;
}
static int F_225 ( struct V_13 * V_14 ,
T_4 * V_66 ,
struct V_326 * V_360 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_619 ( V_14 , V_66 , V_360 ) ;
if ( V_8 != - V_91 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_69 );
return V_8 ;
}
static void F_620 ( struct V_104 * V_105 , void * V_163 )
{
struct V_1015 * V_165 = V_163 ;
F_74 ( F_77 ( V_165 -> V_14 ) ,
& V_165 -> args . V_167 ,
& V_165 -> V_56 . V_168 ,
V_105 ) ;
}
static void F_621 ( struct V_104 * V_105 , void * V_163 )
{
struct V_1015 * V_165 = V_163 ;
F_70 ( V_105 , & V_165 -> V_56 . V_168 ) ;
switch ( V_105 -> V_109 ) {
case - V_91 :
if ( F_38 ( V_105 , V_165 -> V_14 , NULL , NULL ) == - V_110 )
F_68 ( V_105 ) ;
}
}
static void F_622 ( void * V_163 )
{
F_111 ( V_163 ) ;
}
static struct V_104 * F_623 ( struct V_13 * V_14 ,
T_4 * V_66 ,
struct V_326 * V_360 ,
bool V_1016 )
{
struct V_169 V_170 = {
. V_321 = & V_322 [ V_1017 ] ,
. V_326 = V_360 ,
} ;
struct V_171 V_172 = {
. V_173 = V_14 -> V_100 ,
. V_169 = & V_170 ,
. V_174 = & V_1018 ,
. V_223 = V_331 ,
} ;
struct V_1015 * V_165 ;
F_273 ( V_14 -> V_62 , V_865 ,
& V_172 . V_173 , & V_170 ) ;
F_8 ( L_108 , V_66 ) ;
V_165 = F_294 ( sizeof( * V_165 ) , V_313 ) ;
if ( ! V_165 )
return F_52 ( - V_134 ) ;
V_165 -> V_14 = V_14 ;
F_142 ( & V_165 -> args . V_66 , V_66 ) ;
V_172 . V_177 = V_165 ;
V_170 . V_324 = & V_165 -> args ;
V_170 . V_325 = & V_165 -> V_56 ;
F_46 ( & V_165 -> args . V_167 , & V_165 -> V_56 . V_168 , 0 ) ;
if ( V_1016 )
F_47 ( & V_165 -> args . V_167 ) ;
return F_83 ( & V_172 ) ;
}
static int F_227 ( struct V_13 * V_14 ,
T_4 * V_66 ,
struct V_326 * V_360 )
{
struct V_104 * V_105 ;
int V_51 ;
V_105 = F_623 ( V_14 , V_66 , V_360 , true ) ;
if ( F_51 ( V_105 ) )
return F_84 ( V_105 ) ;
V_51 = F_123 ( V_105 ) ;
if ( ! V_51 )
V_51 = V_105 -> V_109 ;
F_85 ( V_105 ) ;
return V_51 ;
}
static void
F_624 ( struct V_13 * V_14 , struct V_292 * V_293 )
{
struct V_104 * V_105 ;
struct V_326 * V_360 = V_293 -> V_294 -> V_236 -> V_301 ;
V_105 = F_623 ( V_14 , & V_293 -> V_296 , V_360 , false ) ;
F_507 ( V_14 , V_293 ) ;
if ( F_51 ( V_105 ) )
return;
F_85 ( V_105 ) ;
}
static bool F_625 ( const T_4 * V_1019 ,
const T_4 * V_1020 )
{
if ( V_1019 -> type != V_1020 -> type )
return false ;
if ( memcmp ( V_1019 -> V_1021 , V_1020 -> V_1021 , sizeof( V_1019 -> V_1021 ) ) != 0 )
return false ;
if ( V_1019 -> V_213 == V_1020 -> V_213 )
return true ;
if ( V_1019 -> V_213 == 0 || V_1020 -> V_213 == 0 )
return true ;
return false ;
}
static bool F_626 ( const T_4 * V_1019 ,
const T_4 * V_1020 )
{
return F_152 ( V_1019 , V_1020 ) ;
}
static struct V_227 *
F_627 ( struct V_229 * V_1022 , T_7 V_1023 )
{
return NULL ;
}
static T_11 F_628 ( struct V_4 * V_4 , char * V_777 , T_9 V_967 )
{
T_11 error , V_1024 ;
error = F_629 ( V_4 , V_777 , V_967 ) ;
if ( error < 0 )
return error ;
if ( V_777 ) {
V_777 += error ;
V_967 -= error ;
}
V_1024 = F_515 ( F_14 ( V_4 ) , V_777 , V_967 ) ;
if ( V_1024 < 0 )
return V_1024 ;
return error + V_1024 ;
}
