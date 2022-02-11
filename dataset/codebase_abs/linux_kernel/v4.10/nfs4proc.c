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
static void F_16 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
const struct V_53 * V_54 = V_14 -> V_55 -> V_56 ;
V_54 -> V_57 ( V_14 , V_50 , V_52 ) ;
}
static void F_17 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
V_50 -> type = V_58 ;
F_16 ( V_14 , V_50 , V_52 ) ;
}
static void F_18 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 )
{
T_4 V_59 ;
F_19 ( & V_59 , V_50 ) ;
F_17 ( V_14 , & V_59 , V_52 ) ;
}
static long F_20 ( long * V_60 )
{
long V_61 ;
if ( ! V_60 )
return V_62 ;
if ( * V_60 <= 0 )
* V_60 = V_63 ;
if ( * V_60 > V_62 )
* V_60 = V_62 ;
V_61 = * V_60 ;
* V_60 <<= 1 ;
return V_61 ;
}
static int F_21 ( struct V_64 * V_65 , long * V_60 )
{
int V_66 = 0 ;
F_22 () ;
F_23 (
F_20 ( V_60 ) ) ;
if ( F_24 ( V_67 ) )
V_66 = - V_68 ;
return V_66 ;
}
static int F_25 ( struct V_13 * V_14 ,
int V_69 , struct V_70 * V_71 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_73 * V_74 = V_71 -> V_74 ;
const T_4 * V_50 = V_71 -> V_50 ;
struct V_2 * V_2 = V_71 -> V_2 ;
int V_61 = V_69 ;
V_71 -> V_75 = 0 ;
V_71 -> V_76 = 0 ;
V_71 -> V_77 = 0 ;
if ( V_50 == NULL && V_74 != NULL )
V_50 = & V_74 -> V_50 ;
switch( V_69 ) {
case 0 :
return 0 ;
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
if ( V_2 != NULL && V_50 != NULL ) {
F_26 ( V_2 ,
V_50 ) ;
goto V_82;
}
case - V_83 :
if ( V_2 ) {
int V_8 ;
V_8 = F_27 ( V_2 ,
V_50 ) ;
if ( V_8 == 0 )
goto V_82;
if ( V_50 != NULL && V_50 -> type == V_84 ) {
V_71 -> V_77 = 1 ;
break;
}
}
if ( V_74 == NULL )
break;
V_61 = F_28 ( V_14 , V_74 ) ;
if ( V_61 < 0 )
break;
goto V_82;
case - V_85 :
case - V_86 :
F_29 ( V_72 ) ;
goto V_82;
case - V_87 :
V_61 = F_30 ( V_14 ) ;
if ( V_61 < 0 )
break;
goto V_82;
case - V_88 :
F_31 ( V_72 ) ;
goto V_82;
#if F_32 ( V_89 )
case - V_90 :
case - V_91 :
case - V_92 :
case - V_93 :
case - V_94 :
case - V_95 :
case - V_96 :
F_8 ( L_4 , V_34 ,
V_69 ) ;
F_33 ( V_72 -> V_97 , V_69 ) ;
goto V_82;
#endif
case - V_32 :
if ( V_71 -> V_60 > V_98 ) {
V_61 = - V_33 ;
break;
}
case - V_99 :
F_34 ( V_14 , V_100 ) ;
case - V_101 :
case - V_19 :
case - V_20 :
V_71 -> V_75 = 1 ;
return 0 ;
case - V_102 :
case - V_103 :
V_71 -> V_77 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_104 & V_105 ) {
V_14 -> V_104 &= ~ V_105 ;
V_71 -> V_77 = 1 ;
F_35 ( V_106 L_5
L_6
L_7
L_8 ,
V_14 -> V_55 -> V_107 ) ;
}
}
return F_7 ( V_61 ) ;
V_82:
V_71 -> V_76 = 1 ;
return 0 ;
}
int F_36 ( struct V_13 * V_14 , int V_69 , struct V_70 * V_71 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
int V_61 ;
V_61 = F_25 ( V_14 , V_69 , V_71 ) ;
if ( V_71 -> V_75 ) {
V_61 = F_21 ( V_14 -> V_108 , & V_71 -> V_60 ) ;
goto V_109;
}
if ( V_71 -> V_76 ) {
V_61 = F_37 ( V_72 ) ;
if ( F_38 ( V_110 , & V_14 -> V_111 ) )
return - V_35 ;
goto V_109;
}
return V_61 ;
V_109:
if ( V_61 == 0 )
V_71 -> V_77 = 1 ;
return V_61 ;
}
static int
F_39 ( struct V_112 * V_113 , struct V_13 * V_14 ,
int V_69 , struct V_70 * V_71 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
int V_61 ;
V_61 = F_25 ( V_14 , V_69 , V_71 ) ;
if ( V_71 -> V_75 ) {
F_40 ( V_113 , F_20 ( & V_71 -> V_60 ) ) ;
goto V_109;
}
if ( V_71 -> V_76 ) {
F_41 ( & V_72 -> V_114 , V_113 , NULL ) ;
if ( F_38 ( V_115 , & V_72 -> V_116 ) == 0 )
F_42 ( & V_72 -> V_114 , V_113 ) ;
goto V_109;
}
if ( F_38 ( V_110 , & V_14 -> V_111 ) )
V_61 = - V_35 ;
return V_61 ;
V_109:
if ( V_61 == 0 )
V_71 -> V_77 = 1 ;
return V_61 ;
}
static int
F_43 ( struct V_112 * V_113 , struct V_13 * V_14 ,
struct V_73 * V_74 , long * V_60 )
{
struct V_70 V_71 = {
. V_74 = V_74 ,
} ;
if ( V_113 -> V_117 >= 0 )
return 0 ;
if ( V_60 )
V_71 . V_60 = * V_60 ;
V_113 -> V_117 = F_39 ( V_113 , V_14 ,
V_113 -> V_117 ,
& V_71 ) ;
if ( V_71 . V_75 && V_60 )
* V_60 = V_71 . V_60 ;
if ( V_71 . V_77 )
return - V_118 ;
return 0 ;
}
static bool F_44 ( struct V_55 * V_72 )
{
T_5 V_119 = V_72 -> V_120 -> V_121 -> V_122 ;
if ( V_119 == V_123 ||
V_119 == V_124 )
return true ;
return false ;
}
static void F_45 ( struct V_55 * V_72 , unsigned long V_125 )
{
F_46 ( & V_72 -> V_126 ) ;
if ( F_47 ( V_72 -> V_127 , V_125 ) )
V_72 -> V_127 = V_125 ;
F_48 ( & V_72 -> V_126 ) ;
}
static void F_49 ( const struct V_13 * V_14 , unsigned long V_125 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
if ( ! F_50 ( V_72 ) )
F_45 ( V_72 , V_125 ) ;
}
void F_51 ( struct V_128 * args ,
struct V_129 * V_66 , int V_130 )
{
args -> V_131 = NULL ;
args -> V_132 = V_130 ;
args -> V_133 = 0 ;
V_66 -> V_134 = NULL ;
}
static void F_52 ( struct V_128 * args )
{
args -> V_133 = 1 ;
}
int F_53 ( struct V_135 * V_136 ,
struct V_128 * args ,
struct V_129 * V_66 ,
struct V_112 * V_113 )
{
struct V_137 * V_138 ;
if ( V_66 -> V_134 != NULL )
goto V_139;
F_46 ( & V_136 -> V_140 ) ;
if ( F_54 ( V_136 ) && ! args -> V_133 )
goto V_141;
V_138 = F_55 ( V_136 ) ;
if ( F_56 ( V_138 ) ) {
if ( V_138 == F_57 ( - V_142 ) )
V_113 -> V_143 = V_98 >> 2 ;
goto V_141;
}
F_48 ( & V_136 -> V_140 ) ;
V_138 -> V_144 = args -> V_133 ? 1 : 0 ;
args -> V_131 = V_138 ;
V_66 -> V_134 = V_138 ;
V_139:
F_58 ( V_113 ) ;
return 0 ;
V_141:
if ( args -> V_133 )
F_59 ( & V_136 -> V_145 , V_113 ,
NULL , V_146 ) ;
else
F_41 ( & V_136 -> V_145 , V_113 , NULL ) ;
F_48 ( & V_136 -> V_140 ) ;
return - V_118 ;
}
static void F_60 ( struct V_129 * V_66 )
{
struct V_137 * V_138 = V_66 -> V_134 ;
struct V_135 * V_136 ;
V_136 = V_138 -> V_147 ;
F_46 ( & V_136 -> V_140 ) ;
if ( ! F_61 ( V_136 , V_138 ) )
F_62 ( V_136 , V_138 ) ;
F_48 ( & V_136 -> V_140 ) ;
V_66 -> V_134 = NULL ;
}
static int F_63 ( struct V_112 * V_113 ,
struct V_129 * V_66 )
{
if ( V_66 -> V_134 != NULL )
F_60 ( V_66 ) ;
return 1 ;
}
static void F_64 ( struct V_129 * V_66 )
{
struct V_148 * V_149 ;
struct V_135 * V_136 ;
struct V_137 * V_138 = V_66 -> V_134 ;
bool V_150 = false ;
V_136 = V_138 -> V_147 ;
V_149 = V_136 -> V_149 ;
if ( V_138 -> V_151 )
V_138 -> V_152 ++ ;
V_138 -> V_151 = 0 ;
F_46 ( & V_136 -> V_140 ) ;
if ( V_136 -> V_153 > V_136 -> V_154 )
V_150 = true ;
if ( F_61 ( V_136 , V_138 ) ) {
V_150 = false ;
goto V_155;
}
F_62 ( V_136 , V_138 ) ;
if ( V_136 -> V_153 != V_156 )
V_150 = false ;
V_155:
F_48 ( & V_136 -> V_140 ) ;
V_66 -> V_134 = NULL ;
if ( V_150 )
F_65 ( V_149 -> V_72 ) ;
if ( F_66 ( & V_136 -> V_157 ) )
F_67 ( & V_136 -> V_157 ) ;
}
static int F_68 ( struct V_112 * V_113 ,
struct V_129 * V_66 )
{
struct V_148 * V_149 ;
struct V_137 * V_138 = V_66 -> V_134 ;
struct V_55 * V_72 ;
bool V_158 = false ;
int V_61 = 1 ;
if ( V_138 == NULL )
goto V_159;
if ( ! F_69 ( V_113 ) )
goto V_160;
V_149 = V_138 -> V_147 -> V_149 ;
if ( V_138 -> V_158 ) {
V_138 -> V_158 = 0 ;
V_158 = true ;
}
F_70 ( V_149 , V_66 ) ;
switch ( V_66 -> V_161 ) {
case 0 :
if ( V_113 -> V_117 == - V_21 && V_158 ) {
++ V_138 -> V_152 ;
goto V_162;
}
V_138 -> V_151 = 1 ;
V_72 = V_149 -> V_72 ;
F_45 ( V_72 , V_66 -> V_163 ) ;
F_71 ( V_72 , V_66 -> V_164 ,
! ! V_138 -> V_144 ) ;
F_72 ( V_138 -> V_147 , V_138 , V_66 ) ;
break;
case 1 :
V_138 -> V_158 = 1 ;
goto V_160;
case - V_99 :
F_8 ( L_9 ,
V_34 ,
V_138 -> V_165 ,
V_138 -> V_152 ) ;
goto V_109;
case - V_91 :
goto V_162;
case - V_96 :
if ( V_158 ) {
++ V_138 -> V_152 ;
goto V_162;
}
if ( V_138 -> V_152 != 1 ) {
V_138 -> V_152 = 1 ;
goto V_162;
}
break;
case - V_95 :
++ V_138 -> V_152 ;
goto V_162;
case - V_94 :
case - V_90 :
F_33 ( V_149 , V_66 -> V_161 ) ;
goto V_162;
default:
V_138 -> V_151 = 1 ;
}
V_160:
F_8 ( L_10 , V_34 , V_66 -> V_161 ) ;
V_159:
return V_61 ;
V_162:
if ( F_73 ( V_113 ) ) {
F_64 ( V_66 ) ;
V_113 -> V_117 = 0 ;
V_61 = 0 ;
}
goto V_160;
V_109:
if ( ! F_74 ( V_113 ) )
goto V_160;
F_40 ( V_113 , V_62 ) ;
return 0 ;
}
int F_75 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
if ( ! F_68 ( V_113 , V_66 ) )
return 0 ;
if ( V_66 -> V_134 != NULL )
F_64 ( V_66 ) ;
return 1 ;
}
static int F_76 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
if ( V_66 -> V_134 == NULL )
return 1 ;
if ( V_66 -> V_134 -> V_147 -> V_149 != NULL )
return F_68 ( V_113 , V_66 ) ;
return F_63 ( V_113 , V_66 ) ;
}
static void F_77 ( struct V_129 * V_66 )
{
if ( V_66 -> V_134 != NULL ) {
if ( V_66 -> V_134 -> V_147 -> V_149 != NULL )
F_64 ( V_66 ) ;
else
F_60 ( V_66 ) ;
}
}
int F_78 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
if ( V_66 -> V_134 == NULL )
return 1 ;
if ( ! V_66 -> V_134 -> V_147 -> V_149 )
return F_63 ( V_113 , V_66 ) ;
return F_75 ( V_113 , V_66 ) ;
}
int F_79 ( struct V_148 * V_149 ,
struct V_128 * args ,
struct V_129 * V_66 ,
struct V_112 * V_113 )
{
struct V_137 * V_138 ;
struct V_135 * V_136 ;
F_8 ( L_11 , V_34 ) ;
if ( V_66 -> V_134 != NULL )
goto V_166;
V_136 = & V_149 -> V_167 ;
V_113 -> V_143 = 0 ;
F_46 ( & V_136 -> V_140 ) ;
if ( F_38 ( V_168 , & V_136 -> V_169 ) &&
! args -> V_133 ) {
F_8 ( L_12 , V_34 ) ;
goto V_141;
}
V_138 = F_55 ( V_136 ) ;
if ( F_56 ( V_138 ) ) {
if ( V_138 == F_57 ( - V_142 ) )
V_113 -> V_143 = V_98 >> 2 ;
F_8 ( L_13 , V_34 ) ;
goto V_141;
}
F_48 ( & V_136 -> V_140 ) ;
V_138 -> V_144 = args -> V_133 ? 1 : 0 ;
args -> V_131 = V_138 ;
F_8 ( L_14 , V_34 ,
V_138 -> V_165 , V_138 -> V_152 ) ;
V_66 -> V_134 = V_138 ;
V_66 -> V_163 = V_170 ;
V_66 -> V_164 = 0 ;
V_66 -> V_161 = 1 ;
F_80 ( V_149 , args ) ;
V_166:
F_58 ( V_113 ) ;
return 0 ;
V_141:
if ( args -> V_133 )
F_59 ( & V_136 -> V_145 , V_113 ,
NULL , V_146 ) ;
else
F_41 ( & V_136 -> V_145 , V_113 , NULL ) ;
F_48 ( & V_136 -> V_140 ) ;
return - V_118 ;
}
static int F_81 ( const struct V_13 * V_14 ,
struct V_128 * args ,
struct V_129 * V_66 ,
struct V_112 * V_113 )
{
struct V_148 * V_149 = F_82 ( V_14 ) ;
int V_61 = 0 ;
if ( ! V_149 )
return F_53 ( V_14 -> V_55 -> V_171 ,
args , V_66 , V_113 ) ;
F_8 ( L_15 ,
V_34 , V_149 -> V_72 , V_149 , V_66 -> V_134 ?
V_66 -> V_134 -> V_165 : V_156 ) ;
V_61 = F_79 ( V_149 , args , V_66 , V_113 ) ;
F_8 ( L_16 , V_34 , V_61 ) ;
return V_61 ;
}
static void F_83 ( struct V_112 * V_113 , void * V_172 )
{
struct V_173 * V_174 = V_172 ;
struct V_148 * V_149 = F_82 ( V_174 -> V_175 ) ;
F_8 ( L_17 , V_34 , V_174 -> V_175 ) ;
F_79 ( V_149 , V_174 -> V_176 , V_174 -> V_177 , V_113 ) ;
}
static void F_84 ( struct V_112 * V_113 , void * V_172 )
{
struct V_173 * V_174 = V_172 ;
F_75 ( V_113 , V_174 -> V_177 ) ;
}
static int F_81 ( const struct V_13 * V_14 ,
struct V_128 * args ,
struct V_129 * V_66 ,
struct V_112 * V_113 )
{
return F_53 ( V_14 -> V_55 -> V_171 ,
args , V_66 , V_113 ) ;
}
static int F_76 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
return F_63 ( V_113 , V_66 ) ;
}
static void F_77 ( struct V_129 * V_66 )
{
if ( V_66 -> V_134 != NULL )
F_60 ( V_66 ) ;
}
int F_78 ( struct V_112 * V_113 ,
struct V_129 * V_66 )
{
return F_63 ( V_113 , V_66 ) ;
}
static void F_85 ( struct V_112 * V_113 , void * V_172 )
{
struct V_173 * V_174 = V_172 ;
F_81 ( V_174 -> V_175 ,
V_174 -> V_176 , V_174 -> V_177 , V_113 ) ;
}
static void F_86 ( struct V_112 * V_113 , void * V_172 )
{
struct V_173 * V_174 = V_172 ;
F_78 ( V_113 , V_174 -> V_177 ) ;
}
static int F_87 ( struct V_64 * V_65 ,
struct V_13 * V_14 ,
struct V_178 * V_179 ,
struct V_128 * args ,
struct V_129 * V_66 )
{
int V_61 ;
struct V_112 * V_113 ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_173 V_174 = {
. V_175 = V_14 ,
. V_176 = args ,
. V_177 = V_66 ,
} ;
struct V_180 V_181 = {
. V_182 = V_65 ,
. V_178 = V_179 ,
. V_183 = V_72 -> V_56 -> V_184 ,
. V_185 = & V_174
} ;
V_113 = F_88 ( & V_181 ) ;
if ( F_56 ( V_113 ) )
V_61 = F_89 ( V_113 ) ;
else {
V_61 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
}
return V_61 ;
}
int F_91 ( struct V_64 * V_65 ,
struct V_13 * V_14 ,
struct V_178 * V_179 ,
struct V_128 * args ,
struct V_129 * V_66 ,
int V_130 )
{
F_51 ( args , V_66 , V_130 ) ;
return F_87 ( V_65 , V_14 , V_179 , args , V_66 ) ;
}
static void F_92 ( struct V_2 * V_3 , struct V_186 * V_187 ,
unsigned long V_125 )
{
struct V_188 * V_189 = F_93 ( V_3 ) ;
F_46 ( & V_3 -> V_190 ) ;
V_189 -> V_191 |= V_192 | V_193 ;
if ( V_187 -> V_194 && V_187 -> V_195 == V_3 -> V_196 ) {
V_189 -> V_191 &= ~ V_197 ;
V_189 -> V_198 = V_170 ;
} else {
F_94 ( V_3 ) ;
if ( V_187 -> V_195 != V_3 -> V_196 )
V_189 -> V_191 |= V_199 |
V_200 ;
}
V_3 -> V_196 = V_187 -> V_201 ;
V_189 -> V_202 = V_125 ;
V_189 -> V_203 = F_95 () ;
F_96 ( V_3 ) ;
F_48 ( & V_3 -> V_190 ) ;
}
static bool F_97 ( struct V_13 * V_14 ,
int V_8 , struct V_70 * V_71 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_104 & V_204 ) )
return false ;
V_14 -> V_104 &= ~ V_204 ;
V_71 -> V_77 = 1 ;
return true ;
}
static T_1
F_98 ( struct V_13 * V_14 ,
T_6 V_205 , int V_206 )
{
T_1 V_66 = 0 ;
switch ( V_205 & ( V_207 | V_208 ) ) {
case V_207 :
V_66 = V_209 ;
break;
case V_208 :
V_66 = V_210 ;
break;
case V_207 | V_208 :
V_66 = V_211 ;
}
if ( ! ( V_14 -> V_104 & V_204 ) )
goto V_160;
if ( V_206 & V_212 )
V_66 |= V_213 ;
V_160:
return V_66 ;
}
static enum V_214
F_99 ( struct V_13 * V_14 ,
enum V_214 V_215 )
{
if ( V_14 -> V_104 & V_204 )
return V_215 ;
switch ( V_215 ) {
default:
return V_215 ;
case V_216 :
return V_217 ;
case V_218 :
return V_219 ;
case V_220 :
return V_221 ;
}
}
static void F_100 ( struct V_222 * V_41 )
{
V_41 -> V_223 . V_224 = & V_41 -> V_224 ;
V_41 -> V_223 . V_225 = V_41 -> V_225 ;
V_41 -> V_223 . V_226 = V_41 -> V_227 . V_226 ;
V_41 -> V_228 . V_226 = V_41 -> V_229 . V_226 ;
V_41 -> V_223 . V_14 = V_41 -> V_227 . V_14 ;
V_41 -> V_223 . V_230 = V_41 -> V_227 . V_231 ;
F_101 ( & V_41 -> V_224 ) ;
F_102 ( & V_41 -> V_224 , & V_41 -> V_232 , & V_41 -> V_233 ) ;
}
static struct V_222 * F_103 ( struct V_4 * V_4 ,
struct V_234 * V_235 , T_6 V_205 , int V_236 ,
const struct V_5 * V_237 ,
struct V_1 * V_7 ,
enum V_214 V_215 ,
T_7 V_238 )
{
struct V_4 * V_239 = F_104 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_239 ) ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_240 * ( * V_241 ) ( struct V_242 * , T_7 ) ;
struct V_222 * V_41 ;
V_41 = F_106 ( sizeof( * V_41 ) , V_238 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_225 = F_107 ( V_14 , V_238 ) ;
if ( F_56 ( V_41 -> V_225 ) )
goto V_243;
V_41 -> V_244 = F_107 ( V_14 , V_238 ) ;
if ( F_56 ( V_41 -> V_244 ) )
goto V_245;
V_241 = V_14 -> V_55 -> V_56 -> V_241 ;
V_41 -> V_227 . V_226 = V_241 ( & V_235 -> V_246 , V_238 ) ;
if ( F_56 ( V_41 -> V_227 . V_226 ) )
goto V_247;
F_108 ( V_4 -> V_248 ) ;
V_41 -> V_4 = F_109 ( V_4 ) ;
V_41 -> V_3 = V_239 ;
V_41 -> V_249 = V_235 ;
F_110 ( & V_235 -> V_250 ) ;
V_41 -> V_227 . V_251 = V_236 ;
V_41 -> V_227 . V_205 = V_205 & ( V_207 | V_208 ) ;
V_41 -> V_227 . V_252 = F_111 () ;
V_41 -> V_227 . V_215 = F_99 ( V_14 , V_215 ) ;
V_41 -> V_227 . V_253 = F_98 ( V_14 ,
V_205 , V_236 ) ;
if ( ! ( V_236 & V_254 ) ) {
switch ( V_41 -> V_227 . V_215 ) {
default:
break;
case V_217 :
case V_216 :
V_41 -> V_227 . V_231 = V_255 |
V_256 |
V_257 |
V_258 ;
}
}
V_41 -> V_227 . V_259 = V_14 -> V_55 -> V_260 ;
V_41 -> V_227 . V_261 . V_262 = F_112 ( V_235 -> V_246 . V_262 ) ;
V_41 -> V_227 . V_261 . V_263 = V_235 -> V_246 . V_264 ;
V_41 -> V_227 . V_265 = & V_4 -> V_11 ;
V_41 -> V_227 . V_14 = V_14 ;
V_41 -> V_227 . V_266 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_227 . V_267 = & V_268 [ 0 ] ;
V_41 -> V_227 . V_7 = F_113 ( V_41 -> V_244 , V_7 ) ;
switch ( V_41 -> V_227 . V_215 ) {
case V_217 :
case V_219 :
case V_221 :
V_41 -> V_227 . V_269 = F_114 ( V_3 ) ;
break;
case V_270 :
case V_216 :
case V_218 :
case V_220 :
V_41 -> V_227 . V_269 = F_114 ( F_14 ( V_4 ) ) ;
}
if ( V_237 != NULL && V_237 -> V_271 != 0 ) {
T_8 V_272 [ 2 ] ;
V_41 -> V_227 . V_273 . V_237 = & V_41 -> V_237 ;
memcpy ( & V_41 -> V_237 , V_237 , sizeof( V_41 -> V_237 ) ) ;
V_272 [ 0 ] = V_170 ;
V_272 [ 1 ] = V_67 -> V_274 ;
memcpy ( V_41 -> V_227 . V_273 . V_37 . V_174 , V_272 ,
sizeof( V_41 -> V_227 . V_273 . V_37 . V_174 ) ) ;
}
V_41 -> V_229 . V_269 = & V_41 -> V_223 . V_269 ;
V_41 -> V_229 . V_50 = & V_41 -> V_223 . V_50 ;
V_41 -> V_229 . V_226 = V_41 -> V_227 . V_226 ;
F_100 ( V_41 ) ;
F_115 ( & V_41 -> V_275 ) ;
return V_41 ;
V_247:
F_116 ( V_41 -> V_244 ) ;
V_245:
F_116 ( V_41 -> V_225 ) ;
V_243:
F_117 ( V_41 ) ;
V_8:
F_118 ( V_239 ) ;
return NULL ;
}
static void F_119 ( struct V_275 * V_275 )
{
struct V_222 * V_41 = F_120 ( V_275 ,
struct V_222 , V_275 ) ;
struct V_276 * V_277 = V_41 -> V_4 -> V_248 ;
F_121 ( V_41 -> V_227 . V_226 ) ;
F_77 ( & V_41 -> V_223 . V_177 ) ;
if ( V_41 -> V_74 != NULL )
F_122 ( V_41 -> V_74 ) ;
F_123 ( V_41 -> V_249 ) ;
F_116 ( V_41 -> V_244 ) ;
F_116 ( V_41 -> V_225 ) ;
F_118 ( V_41 -> V_3 ) ;
F_118 ( V_41 -> V_4 ) ;
F_124 ( V_277 ) ;
F_125 ( & V_41 -> V_224 ) ;
F_117 ( V_41 -> V_224 . V_278 ) ;
F_117 ( V_41 ) ;
}
static void F_126 ( struct V_222 * V_41 )
{
if ( V_41 != NULL )
F_127 ( & V_41 -> V_275 , F_119 ) ;
}
static int F_128 ( struct V_112 * V_113 )
{
int V_61 ;
V_61 = F_129 ( V_113 ) ;
return V_61 ;
}
static bool F_130 ( struct V_73 * V_74 ,
T_6 V_205 )
{
switch( V_205 & ( V_207 | V_208 ) ) {
case V_207 | V_208 :
return V_74 -> V_279 != 0 ;
case V_208 :
return V_74 -> V_280 != 0 ;
case V_207 :
return V_74 -> V_281 != 0 ;
}
F_131 ( 1 ) ;
return false ;
}
static int F_132 ( struct V_73 * V_74 , T_6 V_282 , int V_283 )
{
int V_61 = 0 ;
if ( V_283 & ( V_254 | V_284 ) )
goto V_160;
switch ( V_282 & ( V_207 | V_208 ) ) {
case V_207 :
V_61 |= F_38 ( V_285 , & V_74 -> V_236 ) != 0
&& V_74 -> V_281 != 0 ;
break;
case V_208 :
V_61 |= F_38 ( V_286 , & V_74 -> V_236 ) != 0
&& V_74 -> V_280 != 0 ;
break;
case V_207 | V_208 :
V_61 |= F_38 ( V_287 , & V_74 -> V_236 ) != 0
&& V_74 -> V_279 != 0 ;
}
V_160:
return V_61 ;
}
static int F_133 ( struct V_288 * V_289 , T_6 V_205 ,
enum V_214 V_215 )
{
if ( V_289 == NULL )
return 0 ;
if ( ( V_289 -> type & V_205 ) != V_205 )
return 0 ;
if ( F_38 ( V_290 , & V_289 -> V_236 ) )
return 0 ;
switch ( V_215 ) {
case V_217 :
case V_216 :
break;
case V_270 :
if ( ! F_38 ( V_291 , & V_289 -> V_236 ) )
break;
default:
return 0 ;
}
F_134 ( V_289 ) ;
return 1 ;
}
static void F_135 ( struct V_73 * V_74 , T_6 V_205 )
{
switch ( V_205 ) {
case V_208 :
V_74 -> V_280 ++ ;
break;
case V_207 :
V_74 -> V_281 ++ ;
break;
case V_207 | V_208 :
V_74 -> V_279 ++ ;
}
F_136 ( V_74 , V_74 -> V_74 | V_205 ) ;
}
static bool F_137 ( struct V_73 * V_74 )
{
if ( V_74 -> V_281 && ! F_38 ( V_285 , & V_74 -> V_236 ) )
return true ;
if ( V_74 -> V_280 && ! F_38 ( V_286 , & V_74 -> V_236 ) )
return true ;
if ( V_74 -> V_279 && ! F_38 ( V_287 , & V_74 -> V_236 ) )
return true ;
return false ;
}
static void F_138 ( struct V_73 * V_74 )
{
struct V_55 * V_72 = V_74 -> V_249 -> V_292 -> V_55 ;
bool V_293 = false ;
if ( F_139 ( V_285 , & V_74 -> V_236 ) && V_74 -> V_281 )
V_293 = true ;
if ( F_139 ( V_286 , & V_74 -> V_236 ) && V_74 -> V_280 )
V_293 = true ;
if ( F_139 ( V_287 , & V_74 -> V_236 ) && V_74 -> V_279 )
V_293 = true ;
if ( V_293 )
F_140 ( V_72 , V_74 ) ;
}
static bool F_141 ( struct V_73 * V_74 ,
const T_4 * V_50 , T_4 * V_294 )
{
if ( F_142 ( V_295 , & V_74 -> V_236 ) == 0 )
return true ;
if ( ! F_143 ( V_50 , & V_74 -> V_296 ) ) {
F_19 ( V_294 , & V_74 -> V_296 ) ;
F_138 ( V_74 ) ;
return true ;
}
if ( F_144 ( V_50 , & V_74 -> V_296 ) )
return true ;
return false ;
}
static void F_145 ( struct V_73 * V_74 )
{
if ( ! ( V_74 -> V_280 || V_74 -> V_281 || V_74 -> V_279 ) )
return;
if ( V_74 -> V_280 )
F_146 ( V_286 , & V_74 -> V_236 ) ;
if ( V_74 -> V_281 )
F_146 ( V_285 , & V_74 -> V_236 ) ;
if ( V_74 -> V_279 )
F_146 ( V_287 , & V_74 -> V_236 ) ;
F_146 ( V_295 , & V_74 -> V_236 ) ;
}
static void F_147 ( struct V_73 * V_74 ,
T_4 * V_50 , T_6 V_205 )
{
F_148 ( V_287 , & V_74 -> V_236 ) ;
switch ( V_205 & ( V_207 | V_208 ) ) {
case V_208 :
F_148 ( V_285 , & V_74 -> V_236 ) ;
break;
case V_207 :
F_148 ( V_286 , & V_74 -> V_236 ) ;
break;
case 0 :
F_148 ( V_285 , & V_74 -> V_236 ) ;
F_148 ( V_286 , & V_74 -> V_236 ) ;
F_148 ( V_295 , & V_74 -> V_236 ) ;
}
if ( V_50 == NULL )
return;
if ( F_143 ( V_50 , & V_74 -> V_296 ) &&
! F_144 ( V_50 , & V_74 -> V_296 ) ) {
F_145 ( V_74 ) ;
return;
}
if ( F_38 ( V_297 , & V_74 -> V_236 ) == 0 )
F_19 ( & V_74 -> V_50 , V_50 ) ;
F_19 ( & V_74 -> V_296 , V_50 ) ;
}
static void F_149 ( struct V_73 * V_74 ,
T_4 * V_298 ,
T_4 * V_50 , T_6 V_205 )
{
F_150 ( & V_74 -> V_299 ) ;
if ( F_151 ( V_74 , V_298 ) )
F_147 ( V_74 , V_50 , V_205 ) ;
F_152 ( & V_74 -> V_299 ) ;
if ( F_38 ( V_300 , & V_74 -> V_236 ) )
F_153 ( V_74 -> V_249 -> V_292 -> V_55 ) ;
}
static void F_154 ( struct V_73 * V_74 ,
const T_4 * V_50 , T_6 V_205 ,
T_4 * V_294 )
{
switch ( V_205 ) {
case V_207 :
F_146 ( V_285 , & V_74 -> V_236 ) ;
break;
case V_208 :
F_146 ( V_286 , & V_74 -> V_236 ) ;
break;
case V_207 | V_208 :
F_146 ( V_287 , & V_74 -> V_236 ) ;
}
if ( ! F_141 ( V_74 , V_50 , V_294 ) )
return;
if ( F_38 ( V_297 , & V_74 -> V_236 ) == 0 )
F_19 ( & V_74 -> V_50 , V_50 ) ;
F_19 ( & V_74 -> V_296 , V_50 ) ;
}
static void F_155 ( struct V_73 * V_74 ,
const T_4 * V_296 ,
const T_4 * V_301 ,
T_6 V_205 ,
T_4 * V_294 )
{
F_46 ( & V_74 -> V_249 -> V_302 ) ;
F_150 ( & V_74 -> V_299 ) ;
if ( V_301 != NULL ) {
F_19 ( & V_74 -> V_50 , V_301 ) ;
F_146 ( V_297 , & V_74 -> V_236 ) ;
}
if ( V_296 != NULL )
F_154 ( V_74 , V_296 , V_205 , V_294 ) ;
F_152 ( & V_74 -> V_299 ) ;
F_135 ( V_74 , V_205 ) ;
F_48 ( & V_74 -> V_249 -> V_302 ) ;
}
static int F_156 ( struct V_73 * V_74 ,
const T_4 * V_296 ,
const T_4 * V_289 ,
T_6 V_205 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_288 * V_303 ;
T_4 V_294 = { } ;
int V_61 = 0 ;
V_205 &= ( V_207 | V_208 ) ;
F_157 () ;
V_303 = F_158 ( V_189 -> V_289 ) ;
if ( V_303 == NULL )
goto V_304;
F_46 ( & V_303 -> V_305 ) ;
if ( F_158 ( V_189 -> V_289 ) != V_303 ||
F_38 ( V_290 , & V_303 -> V_236 ) ||
( V_303 -> type & V_205 ) != V_205 )
goto V_306;
if ( V_289 == NULL )
V_289 = & V_303 -> V_50 ;
else if ( ! F_159 ( & V_303 -> V_50 , V_289 ) )
goto V_306;
F_134 ( V_303 ) ;
F_155 ( V_74 , V_296 , & V_303 -> V_50 ,
V_205 , & V_294 ) ;
V_61 = 1 ;
V_306:
F_48 ( & V_303 -> V_305 ) ;
V_304:
F_160 () ;
if ( ! V_61 && V_296 != NULL ) {
F_155 ( V_74 , V_296 , NULL , V_205 , & V_294 ) ;
V_61 = 1 ;
}
if ( F_38 ( V_300 , & V_74 -> V_236 ) )
F_153 ( V_72 ) ;
if ( V_294 . type != 0 )
F_16 ( V_14 , & V_294 ,
V_74 -> V_249 -> V_307 ) ;
return V_61 ;
}
static bool F_161 ( struct V_308 * V_309 ,
const T_4 * V_50 )
{
struct V_73 * V_74 = V_309 -> V_310 ;
bool V_61 = false ;
F_46 ( & V_74 -> V_311 ) ;
if ( ! F_143 ( V_50 , & V_309 -> V_312 ) )
goto V_313;
if ( ! F_144 ( V_50 , & V_309 -> V_312 ) )
goto V_313;
F_19 ( & V_309 -> V_312 , V_50 ) ;
V_61 = true ;
V_313:
F_48 ( & V_74 -> V_311 ) ;
return V_61 ;
}
static void F_162 ( struct V_2 * V_2 , T_6 V_205 )
{
struct V_288 * V_289 ;
F_157 () ;
V_289 = F_158 ( F_93 ( V_2 ) -> V_289 ) ;
if ( V_289 == NULL || ( V_289 -> type & V_205 ) == V_205 ) {
F_160 () ;
return;
}
F_160 () ;
F_163 ( V_2 ) ;
}
static struct V_73 * F_164 ( struct V_222 * V_314 )
{
struct V_73 * V_74 = V_314 -> V_74 ;
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_288 * V_289 ;
int V_283 = V_314 -> V_227 . V_251 ;
T_6 V_205 = V_314 -> V_227 . V_205 ;
enum V_214 V_215 = V_314 -> V_227 . V_215 ;
T_4 V_50 ;
int V_61 = - V_118 ;
for (; ; ) {
F_46 ( & V_74 -> V_249 -> V_302 ) ;
if ( F_132 ( V_74 , V_205 , V_283 ) ) {
F_135 ( V_74 , V_205 ) ;
F_48 ( & V_74 -> V_249 -> V_302 ) ;
goto V_315;
}
F_48 ( & V_74 -> V_249 -> V_302 ) ;
F_157 () ;
V_289 = F_158 ( V_189 -> V_289 ) ;
if ( ! F_133 ( V_289 , V_205 , V_215 ) ) {
F_160 () ;
break;
}
F_19 ( & V_50 , & V_289 -> V_50 ) ;
F_160 () ;
F_165 ( V_314 -> V_227 . V_226 ) ;
if ( ! V_314 -> V_316 ) {
V_61 = F_166 ( V_74 -> V_2 , V_74 -> V_249 -> V_307 , V_283 ) ;
if ( V_61 != 0 )
goto V_160;
}
V_61 = - V_118 ;
if ( F_156 ( V_74 , NULL , & V_50 , V_205 ) )
goto V_315;
}
V_160:
return F_57 ( V_61 ) ;
V_315:
F_110 ( & V_74 -> V_49 ) ;
return V_74 ;
}
static void
F_167 ( struct V_222 * V_174 , struct V_73 * V_74 )
{
struct V_55 * V_72 = F_105 ( V_74 -> V_2 ) -> V_55 ;
struct V_288 * V_289 ;
int V_317 = 0 ;
F_157 () ;
V_289 = F_158 ( F_93 ( V_74 -> V_2 ) -> V_289 ) ;
if ( V_289 )
V_317 = V_289 -> V_236 ;
F_160 () ;
switch ( V_174 -> V_227 . V_215 ) {
default:
break;
case V_219 :
case V_218 :
F_168 ( L_18
L_19
L_20 ,
V_72 -> V_107 ) ;
return;
}
if ( ( V_317 & 1UL << V_291 ) == 0 )
F_169 ( V_74 -> V_2 ,
V_174 -> V_249 -> V_307 ,
& V_174 -> V_223 ) ;
else
F_170 ( V_74 -> V_2 ,
V_174 -> V_249 -> V_307 ,
& V_174 -> V_223 ) ;
}
static struct V_73 *
F_171 ( struct V_222 * V_174 )
{
struct V_2 * V_2 = V_174 -> V_74 -> V_2 ;
struct V_73 * V_74 = V_174 -> V_74 ;
int V_61 ;
if ( ! V_174 -> V_318 ) {
if ( V_174 -> V_319 ) {
V_61 = V_174 -> V_319 ;
goto V_8;
}
goto V_320;
}
V_61 = F_172 ( V_2 , & V_174 -> V_224 ) ;
if ( V_61 )
goto V_8;
if ( V_174 -> V_223 . V_321 != 0 )
F_167 ( V_174 , V_74 ) ;
V_320:
F_156 ( V_74 , & V_174 -> V_223 . V_50 , NULL ,
V_174 -> V_227 . V_205 ) ;
F_110 ( & V_74 -> V_49 ) ;
return V_74 ;
V_8:
return F_57 ( V_61 ) ;
}
static struct V_73 *
F_173 ( struct V_222 * V_174 )
{
struct V_2 * V_2 ;
struct V_73 * V_74 = NULL ;
int V_61 ;
if ( ! V_174 -> V_318 ) {
V_74 = F_164 ( V_174 ) ;
F_174 ( V_174 -> V_74 ) ;
goto V_160;
}
V_61 = - V_118 ;
if ( ! ( V_174 -> V_224 . V_322 & V_323 ) )
goto V_8;
V_2 = F_175 ( V_174 -> V_3 -> V_248 , & V_174 -> V_223 . V_269 , & V_174 -> V_224 , V_174 -> V_225 ) ;
V_61 = F_89 ( V_2 ) ;
if ( F_56 ( V_2 ) )
goto V_8;
V_61 = - V_142 ;
V_74 = F_176 ( V_2 , V_174 -> V_249 ) ;
if ( V_74 == NULL )
goto V_324;
if ( V_174 -> V_223 . V_321 != 0 )
F_167 ( V_174 , V_74 ) ;
F_156 ( V_74 , & V_174 -> V_223 . V_50 , NULL ,
V_174 -> V_227 . V_205 ) ;
F_177 ( V_2 ) ;
V_160:
F_165 ( V_174 -> V_227 . V_226 ) ;
return V_74 ;
V_324:
F_177 ( V_2 ) ;
V_8:
return F_57 ( V_61 ) ;
}
static struct V_73 *
F_178 ( struct V_222 * V_174 )
{
struct V_73 * V_61 ;
if ( V_174 -> V_227 . V_215 == V_270 )
V_61 = F_171 ( V_174 ) ;
else
V_61 = F_173 ( V_174 ) ;
F_77 ( & V_174 -> V_223 . V_177 ) ;
return V_61 ;
}
static struct V_325 * F_179 ( struct V_73 * V_74 )
{
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_325 * V_326 ;
F_46 ( & V_74 -> V_2 -> V_190 ) ;
F_180 (ctx, &nfsi->open_files, list) {
if ( V_326 -> V_74 != V_74 )
continue;
F_181 ( V_326 ) ;
F_48 ( & V_74 -> V_2 -> V_190 ) ;
return V_326 ;
}
F_48 ( & V_74 -> V_2 -> V_190 ) ;
return F_57 ( - V_327 ) ;
}
static struct V_222 * F_182 ( struct V_325 * V_326 ,
struct V_73 * V_74 , enum V_214 V_215 )
{
struct V_222 * V_314 ;
V_314 = F_103 ( V_326 -> V_4 , V_74 -> V_249 , 0 , 0 ,
NULL , NULL , V_215 , V_328 ) ;
if ( V_314 == NULL )
return F_57 ( - V_142 ) ;
V_314 -> V_74 = V_74 ;
F_110 ( & V_74 -> V_49 ) ;
return V_314 ;
}
static int F_183 ( struct V_222 * V_314 ,
T_6 V_205 )
{
struct V_73 * V_329 ;
int V_61 ;
if ( ! F_130 ( V_314 -> V_74 , V_205 ) )
return 0 ;
V_314 -> V_227 . V_251 = 0 ;
V_314 -> V_227 . V_205 = V_205 ;
V_314 -> V_227 . V_253 = F_98 (
F_184 ( V_314 -> V_4 -> V_248 ) ,
V_205 , 0 ) ;
memset ( & V_314 -> V_223 , 0 , sizeof( V_314 -> V_223 ) ) ;
memset ( & V_314 -> V_228 , 0 , sizeof( V_314 -> V_228 ) ) ;
F_100 ( V_314 ) ;
V_61 = F_185 ( V_314 ) ;
if ( V_61 != 0 )
return V_61 ;
V_329 = F_178 ( V_314 ) ;
if ( F_56 ( V_329 ) )
return F_89 ( V_329 ) ;
if ( V_329 != V_314 -> V_74 )
V_61 = - V_330 ;
F_186 ( V_329 , V_205 ) ;
return V_61 ;
}
static int F_187 ( struct V_222 * V_314 , struct V_73 * V_74 )
{
int V_61 ;
F_148 ( V_287 , & V_74 -> V_236 ) ;
F_148 ( V_286 , & V_74 -> V_236 ) ;
F_148 ( V_285 , & V_74 -> V_236 ) ;
F_148 ( V_297 , & V_74 -> V_236 ) ;
F_148 ( V_295 , & V_74 -> V_236 ) ;
F_188 () ;
V_61 = F_183 ( V_314 , V_207 | V_208 ) ;
if ( V_61 != 0 )
return V_61 ;
V_61 = F_183 ( V_314 , V_208 ) ;
if ( V_61 != 0 )
return V_61 ;
V_61 = F_183 ( V_314 , V_207 ) ;
if ( V_61 != 0 )
return V_61 ;
if ( F_38 ( V_297 , & V_74 -> V_236 ) == 0 &&
! F_159 ( & V_74 -> V_50 , & V_74 -> V_296 ) ) {
F_150 ( & V_74 -> V_299 ) ;
if ( F_38 ( V_297 , & V_74 -> V_236 ) == 0 )
F_19 ( & V_74 -> V_50 , & V_74 -> V_296 ) ;
F_152 ( & V_74 -> V_299 ) ;
}
return 0 ;
}
static int F_189 ( struct V_325 * V_326 , struct V_73 * V_74 )
{
struct V_288 * V_289 ;
struct V_222 * V_314 ;
T_6 V_321 = 0 ;
int V_331 ;
V_314 = F_182 ( V_326 , V_74 ,
V_270 ) ;
if ( F_56 ( V_314 ) )
return F_89 ( V_314 ) ;
F_157 () ;
V_289 = F_158 ( F_93 ( V_74 -> V_2 ) -> V_289 ) ;
if ( V_289 != NULL && F_38 ( V_291 , & V_289 -> V_236 ) != 0 )
V_321 = V_289 -> type ;
F_160 () ;
V_314 -> V_227 . V_273 . V_321 = V_321 ;
V_331 = F_187 ( V_314 , V_74 ) ;
F_126 ( V_314 ) ;
return V_331 ;
}
static int F_190 ( struct V_325 * V_326 , struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_189 ( V_326 , V_74 ) ;
F_191 ( V_326 , 0 , V_8 ) ;
if ( F_97 ( V_14 , V_8 , & V_71 ) )
continue;
if ( V_8 != - V_99 )
break;
F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_192 ( struct V_234 * V_235 , struct V_73 * V_74 )
{
struct V_325 * V_326 ;
int V_61 ;
V_326 = F_179 ( V_74 ) ;
if ( F_56 ( V_326 ) )
return - V_118 ;
V_61 = F_190 ( V_326 , V_74 ) ;
F_193 ( V_326 ) ;
return V_61 ;
}
static int F_194 ( struct V_13 * V_14 , struct V_73 * V_74 , const T_4 * V_50 , int V_8 )
{
switch ( V_8 ) {
default:
F_35 ( V_332 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_327 :
case - V_118 :
case - V_330 :
break;
case - V_90 :
case - V_91 :
case - V_92 :
case - V_93 :
case - V_94 :
F_146 ( V_297 , & V_74 -> V_236 ) ;
F_33 ( V_14 -> V_55 -> V_97 , V_8 ) ;
return - V_118 ;
case - V_86 :
case - V_85 :
F_146 ( V_297 , & V_74 -> V_236 ) ;
F_29 ( V_14 -> V_55 ) ;
return - V_118 ;
case - V_87 :
F_30 ( V_14 ) ;
return - V_118 ;
case - V_88 :
F_31 ( V_14 -> V_55 ) ;
return - V_118 ;
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
case - V_83 :
F_26 ( V_74 -> V_2 ,
V_50 ) ;
F_28 ( V_14 , V_74 ) ;
return - V_118 ;
case - V_99 :
case - V_101 :
F_146 ( V_297 , & V_74 -> V_236 ) ;
F_195 ( 1 ) ;
return - V_118 ;
case - V_142 :
case - V_333 :
return 0 ;
}
return V_8 ;
}
int F_196 ( struct V_325 * V_326 ,
struct V_73 * V_74 , const T_4 * V_50 ,
T_6 type )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_222 * V_314 ;
int V_8 = 0 ;
V_314 = F_182 ( V_326 , V_74 ,
V_218 ) ;
if ( F_56 ( V_314 ) )
return F_89 ( V_314 ) ;
F_19 ( & V_314 -> V_227 . V_273 . V_289 , V_50 ) ;
F_150 ( & V_74 -> V_299 ) ;
F_19 ( & V_74 -> V_50 , & V_74 -> V_296 ) ;
F_152 ( & V_74 -> V_299 ) ;
F_148 ( V_297 , & V_74 -> V_236 ) ;
switch ( type & ( V_207 | V_208 ) ) {
case V_207 | V_208 :
case V_208 :
V_8 = F_183 ( V_314 , V_207 | V_208 ) ;
if ( V_8 )
break;
V_8 = F_183 ( V_314 , V_208 ) ;
if ( V_8 )
break;
case V_207 :
V_8 = F_183 ( V_314 , V_207 ) ;
}
F_126 ( V_314 ) ;
return F_194 ( V_14 , V_74 , V_50 , V_8 ) ;
}
static void F_197 ( struct V_112 * V_113 , void * V_172 )
{
struct V_222 * V_174 = V_172 ;
F_53 ( V_174 -> V_227 . V_14 -> V_55 -> V_171 ,
& V_174 -> V_229 . V_176 , & V_174 -> V_228 . V_177 , V_113 ) ;
}
static void F_198 ( struct V_112 * V_113 , void * V_172 )
{
struct V_222 * V_174 = V_172 ;
F_63 ( V_113 , & V_174 -> V_228 . V_177 ) ;
V_174 -> V_319 = V_113 -> V_117 ;
if ( V_174 -> V_319 == 0 ) {
F_19 ( & V_174 -> V_223 . V_50 , & V_174 -> V_228 . V_50 ) ;
F_199 ( & V_174 -> V_249 -> V_246 , 0 ) ;
F_49 ( V_174 -> V_223 . V_14 , V_174 -> V_125 ) ;
V_174 -> V_318 = 1 ;
}
}
static void F_200 ( void * V_172 )
{
struct V_222 * V_174 = V_172 ;
struct V_73 * V_74 = NULL ;
if ( V_174 -> V_334 == 0 )
goto V_335;
if ( ! V_174 -> V_318 )
goto V_335;
V_74 = F_178 ( V_174 ) ;
if ( ! F_56 ( V_74 ) )
F_186 ( V_74 , V_174 -> V_227 . V_205 ) ;
V_335:
F_126 ( V_174 ) ;
}
static int F_201 ( struct V_222 * V_174 )
{
struct V_13 * V_14 = F_105 ( F_14 ( V_174 -> V_3 ) ) ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_338 ] ,
. V_339 = & V_174 -> V_229 ,
. V_340 = & V_174 -> V_228 ,
. V_51 = V_174 -> V_249 -> V_307 ,
} ;
struct V_180 V_341 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_342 ,
. V_185 = V_174 ,
. V_343 = V_344 ,
. V_236 = V_345 ,
} ;
int V_331 ;
F_51 ( & V_174 -> V_229 . V_176 , & V_174 -> V_228 . V_177 , 1 ) ;
F_202 ( & V_174 -> V_275 ) ;
V_174 -> V_318 = 0 ;
V_174 -> V_319 = 0 ;
V_174 -> V_125 = V_170 ;
if ( V_174 -> V_316 )
F_52 ( & V_174 -> V_229 . V_176 ) ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_331 = F_128 ( V_113 ) ;
if ( V_331 != 0 ) {
V_174 -> V_334 = 1 ;
F_203 () ;
} else
V_331 = V_174 -> V_319 ;
F_90 ( V_113 ) ;
return V_331 ;
}
static void F_204 ( struct V_112 * V_113 , void * V_172 )
{
struct V_222 * V_174 = V_172 ;
struct V_234 * V_235 = V_174 -> V_249 ;
struct V_55 * V_72 = V_235 -> V_292 -> V_55 ;
enum V_214 V_215 = V_174 -> V_227 . V_215 ;
if ( F_205 ( V_174 -> V_227 . V_226 , V_113 ) != 0 )
goto V_346;
if ( V_174 -> V_74 != NULL ) {
struct V_288 * V_289 ;
if ( F_132 ( V_174 -> V_74 , V_174 -> V_227 . V_205 , V_174 -> V_227 . V_251 ) )
goto V_347;
F_157 () ;
V_289 = F_158 ( F_93 ( V_174 -> V_74 -> V_2 ) -> V_289 ) ;
if ( F_133 ( V_289 , V_174 -> V_227 . V_205 , V_215 ) )
goto V_348;
F_160 () ;
}
V_174 -> V_227 . V_259 = V_72 -> V_260 ;
switch ( V_215 ) {
default:
break;
case V_270 :
case V_218 :
case V_220 :
V_174 -> V_227 . V_267 = & V_349 [ 0 ] ;
case V_216 :
V_113 -> V_350 . V_336 = & V_337 [ V_351 ] ;
F_206 ( & V_174 -> V_223 . V_269 , V_174 -> V_227 . V_269 ) ;
}
V_174 -> V_125 = V_170 ;
if ( F_81 ( V_174 -> V_227 . V_14 ,
& V_174 -> V_227 . V_176 ,
& V_174 -> V_223 . V_177 ,
V_113 ) != 0 )
F_165 ( V_174 -> V_227 . V_226 ) ;
V_174 -> V_227 . V_352 = V_353 ;
if ( V_174 -> V_227 . V_251 & V_254 ) {
V_174 -> V_227 . V_352 = V_354 ;
if ( F_207 ( V_72 ) )
V_174 -> V_227 . V_352 = V_355 ;
else if ( V_72 -> V_56 -> V_356 > 0 )
V_174 -> V_227 . V_352 = V_357 ;
}
return;
V_348:
F_174 ( V_174 -> V_74 ) ;
F_160 () ;
V_347:
V_113 -> V_358 = NULL ;
V_346:
F_78 ( V_113 , & V_174 -> V_223 . V_177 ) ;
}
static void F_208 ( struct V_112 * V_113 , void * V_172 )
{
struct V_222 * V_174 = V_172 ;
V_174 -> V_319 = V_113 -> V_117 ;
if ( ! F_76 ( V_113 , & V_174 -> V_223 . V_177 ) )
return;
if ( V_113 -> V_117 == 0 ) {
if ( V_174 -> V_223 . V_224 -> V_322 & V_359 ) {
switch ( V_174 -> V_223 . V_224 -> V_282 & V_360 ) {
case V_361 :
break;
case V_362 :
V_174 -> V_319 = - V_363 ;
break;
case V_364 :
V_174 -> V_319 = - V_365 ;
break;
default:
V_174 -> V_319 = - V_366 ;
}
}
F_49 ( V_174 -> V_223 . V_14 , V_174 -> V_125 ) ;
if ( ! ( V_174 -> V_223 . V_367 & V_368 ) )
F_199 ( & V_174 -> V_249 -> V_246 , 0 ) ;
}
V_174 -> V_318 = 1 ;
}
static void F_209 ( void * V_172 )
{
struct V_222 * V_174 = V_172 ;
struct V_73 * V_74 = NULL ;
if ( V_174 -> V_334 == 0 )
goto V_335;
if ( V_174 -> V_319 != 0 || ! V_174 -> V_318 )
goto V_335;
if ( V_174 -> V_223 . V_367 & V_368 )
goto V_335;
V_74 = F_178 ( V_174 ) ;
if ( ! F_56 ( V_74 ) )
F_186 ( V_74 , V_174 -> V_227 . V_205 ) ;
V_335:
F_126 ( V_174 ) ;
}
static int F_210 ( struct V_222 * V_174 , int V_369 )
{
struct V_2 * V_3 = F_14 ( V_174 -> V_3 ) ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_370 * V_227 = & V_174 -> V_227 ;
struct V_371 * V_223 = & V_174 -> V_223 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_372 ] ,
. V_339 = V_227 ,
. V_340 = V_223 ,
. V_51 = V_174 -> V_249 -> V_307 ,
} ;
struct V_180 V_341 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_373 ,
. V_185 = V_174 ,
. V_343 = V_344 ,
. V_236 = V_345 ,
} ;
int V_331 ;
F_51 ( & V_227 -> V_176 , & V_223 -> V_177 , 1 ) ;
F_202 ( & V_174 -> V_275 ) ;
V_174 -> V_318 = 0 ;
V_174 -> V_319 = 0 ;
V_174 -> V_334 = 0 ;
V_174 -> V_316 = 0 ;
if ( V_369 ) {
F_52 ( & V_227 -> V_176 ) ;
V_174 -> V_316 = 1 ;
}
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_331 = F_128 ( V_113 ) ;
if ( V_331 != 0 ) {
V_174 -> V_334 = 1 ;
F_203 () ;
} else
V_331 = V_174 -> V_319 ;
F_90 ( V_113 ) ;
return V_331 ;
}
static int F_185 ( struct V_222 * V_174 )
{
struct V_2 * V_3 = F_14 ( V_174 -> V_3 ) ;
struct V_371 * V_223 = & V_174 -> V_223 ;
int V_331 ;
V_331 = F_210 ( V_174 , 1 ) ;
if ( V_331 != 0 || ! V_174 -> V_318 )
return V_331 ;
F_211 ( F_105 ( V_3 ) , & V_174 -> V_224 ) ;
if ( V_223 -> V_367 & V_368 ) {
V_331 = F_201 ( V_174 ) ;
if ( V_331 != 0 )
return V_331 ;
}
return V_331 ;
}
static int F_212 ( struct V_51 * V_52 ,
struct V_222 * V_314 ,
struct V_73 * V_74 , T_6 V_205 ,
int V_206 )
{
struct V_374 V_375 ;
T_1 V_376 ;
if ( V_314 -> V_223 . V_377 == 0 )
return 0 ;
V_376 = 0 ;
if ( V_206 & V_378 ) {
V_376 = V_379 ;
} else if ( ( V_205 & V_207 ) && ! V_314 -> V_380 )
V_376 = V_381 ;
V_375 . V_52 = V_52 ;
V_375 . V_170 = V_170 ;
F_213 ( & V_375 , V_314 -> V_223 . V_382 ) ;
F_214 ( V_74 -> V_2 , & V_375 ) ;
if ( ( V_376 & ~ V_375 . V_376 & ( V_381 | V_379 ) ) == 0 )
return 0 ;
F_186 ( V_74 , V_205 ) ;
return - V_29 ;
}
static int F_215 ( struct V_222 * V_174 )
{
struct V_2 * V_3 = F_14 ( V_174 -> V_3 ) ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_370 * V_227 = & V_174 -> V_227 ;
struct V_371 * V_223 = & V_174 -> V_223 ;
int V_331 ;
V_331 = F_210 ( V_174 , 0 ) ;
if ( ! V_174 -> V_318 )
return V_331 ;
if ( V_331 != 0 ) {
if ( V_331 == - V_26 &&
! ( V_227 -> V_251 & V_383 ) )
return - V_327 ;
return V_331 ;
}
F_211 ( V_14 , & V_174 -> V_224 ) ;
if ( V_227 -> V_251 & V_383 ) {
if ( V_227 -> V_251 & V_254 )
V_174 -> V_380 = 1 ;
else if ( V_223 -> V_187 . V_195 != V_223 -> V_187 . V_201 )
V_174 -> V_380 = 1 ;
if ( V_174 -> V_380 || V_3 -> V_196 != V_223 -> V_187 . V_201 )
F_92 ( V_3 , & V_223 -> V_187 ,
V_223 -> V_224 -> V_384 ) ;
}
if ( ( V_223 -> V_367 & V_385 ) == 0 )
V_14 -> V_104 &= ~ V_386 ;
if( V_223 -> V_367 & V_368 ) {
V_331 = F_201 ( V_174 ) ;
if ( V_331 != 0 )
return V_331 ;
}
if ( ! ( V_223 -> V_224 -> V_322 & V_323 ) )
F_216 ( V_14 , & V_223 -> V_269 , V_223 -> V_224 , V_223 -> V_225 ) ;
return 0 ;
}
static int F_217 ( struct V_13 * V_14 )
{
return F_218 ( V_14 -> V_55 ) ;
}
static int F_219 ( struct V_325 * V_326 , struct V_73 * V_74 )
{
struct V_222 * V_314 ;
int V_61 ;
V_314 = F_182 ( V_326 , V_74 ,
V_216 ) ;
if ( F_56 ( V_314 ) )
return F_89 ( V_314 ) ;
V_61 = F_187 ( V_314 , V_74 ) ;
if ( V_61 == - V_330 )
F_220 ( V_326 -> V_4 ) ;
F_126 ( V_314 ) ;
return V_61 ;
}
static int F_221 ( struct V_325 * V_326 , struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_219 ( V_326 , V_74 ) ;
F_222 ( V_326 , 0 , V_8 ) ;
if ( F_97 ( V_14 , V_8 , & V_71 ) )
continue;
switch ( V_8 ) {
default:
goto V_160;
case - V_101 :
case - V_99 :
F_36 ( V_14 , V_8 , & V_71 ) ;
V_8 = 0 ;
}
} while ( V_71 . V_77 );
V_160:
return V_8 ;
}
static int F_223 ( struct V_234 * V_235 , struct V_73 * V_74 )
{
struct V_325 * V_326 ;
int V_61 ;
V_326 = F_179 ( V_74 ) ;
if ( F_56 ( V_326 ) )
return - V_118 ;
V_61 = F_221 ( V_326 , V_74 ) ;
F_193 ( V_326 ) ;
return V_61 ;
}
static void F_224 ( struct V_73 * V_74 ,
const T_4 * V_50 )
{
F_225 ( V_74 -> V_2 , V_50 ) ;
F_150 ( & V_74 -> V_299 ) ;
F_19 ( & V_74 -> V_50 , & V_74 -> V_296 ) ;
F_152 ( & V_74 -> V_299 ) ;
F_148 ( V_297 , & V_74 -> V_236 ) ;
}
static void F_226 ( struct V_73 * V_74 )
{
if ( F_227 ( F_93 ( V_74 -> V_2 ) -> V_289 ) != NULL )
F_224 ( V_74 , NULL ) ;
}
static int F_228 ( struct V_234 * V_235 , struct V_73 * V_74 )
{
F_226 ( V_74 ) ;
return F_223 ( V_235 , V_74 ) ;
}
static int F_229 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
return - V_81 ;
}
static int F_230 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
int V_331 ;
switch ( V_50 -> type ) {
default:
break;
case V_387 :
case V_388 :
return - V_81 ;
case V_58 :
goto V_335;
}
V_331 = F_231 ( V_14 , V_50 , V_52 ) ;
switch ( V_331 ) {
case - V_80 :
case - V_79 :
case - V_78 :
break;
default:
return V_331 ;
}
V_335:
F_232 ( V_14 , V_50 , V_52 , true ) ;
return - V_80 ;
}
static void F_233 ( struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
T_4 V_50 ;
struct V_288 * V_289 ;
struct V_51 * V_52 ;
int V_331 ;
F_157 () ;
V_289 = F_158 ( F_93 ( V_74 -> V_2 ) -> V_289 ) ;
if ( V_289 == NULL ) {
F_160 () ;
return;
}
F_19 ( & V_50 , & V_289 -> V_50 ) ;
if ( F_38 ( V_389 , & V_289 -> V_236 ) ) {
F_160 () ;
F_224 ( V_74 , & V_50 ) ;
return;
}
if ( ! F_139 ( V_390 , & V_289 -> V_236 ) ) {
F_160 () ;
return;
}
V_52 = F_234 ( V_289 -> V_52 ) ;
F_160 () ;
V_331 = F_230 ( V_14 , & V_50 , V_52 ) ;
F_235 ( V_74 , NULL , V_331 ) ;
if ( V_331 == - V_80 || V_331 == - V_81 )
F_224 ( V_74 , & V_50 ) ;
F_236 ( V_52 ) ;
}
static int F_237 ( struct V_73 * V_74 )
{
int V_331 , V_61 = V_391 ;
struct V_308 * V_309 , * V_392 = NULL ;
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
if ( ! F_38 ( V_393 , & V_74 -> V_236 ) )
goto V_160;
F_46 ( & V_74 -> V_311 ) ;
F_180 (lsp, &state->lock_states, ls_locks) {
if ( F_38 ( V_394 , & V_309 -> V_395 ) ) {
struct V_51 * V_52 = V_309 -> V_310 -> V_249 -> V_307 ;
F_110 ( & V_309 -> V_396 ) ;
F_48 ( & V_74 -> V_311 ) ;
F_238 ( V_392 ) ;
V_392 = V_309 ;
V_331 = F_230 ( V_14 ,
& V_309 -> V_312 ,
V_52 ) ;
F_239 ( V_74 , V_309 , V_331 ) ;
if ( V_331 == - V_80 ||
V_331 == - V_81 ) {
F_148 ( V_394 , & V_309 -> V_395 ) ;
V_309 -> V_312 . type = V_387 ;
if ( ! V_397 )
F_146 ( V_398 , & V_309 -> V_395 ) ;
} else if ( V_331 != V_391 ) {
V_61 = V_331 ;
F_238 ( V_392 ) ;
goto V_160;
}
F_46 ( & V_74 -> V_311 ) ;
}
}
F_48 ( & V_74 -> V_311 ) ;
F_238 ( V_392 ) ;
V_160:
return V_61 ;
}
static int F_240 ( struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
T_4 * V_50 = & V_74 -> V_296 ;
struct V_51 * V_52 = V_74 -> V_249 -> V_307 ;
int V_331 ;
if ( F_38 ( V_295 , & V_74 -> V_236 ) == 0 ) {
if ( F_38 ( V_297 , & V_74 -> V_236 ) == 0 ) {
if ( F_241 ( V_74 -> V_2 , V_74 -> V_74 ) )
return V_391 ;
return - V_83 ;
}
return - V_81 ;
}
V_331 = F_230 ( V_14 , V_50 , V_52 ) ;
F_242 ( V_74 , NULL , V_331 ) ;
if ( V_331 == - V_80 || V_331 == - V_81 ) {
F_148 ( V_285 , & V_74 -> V_236 ) ;
F_148 ( V_286 , & V_74 -> V_236 ) ;
F_148 ( V_287 , & V_74 -> V_236 ) ;
F_148 ( V_295 , & V_74 -> V_236 ) ;
V_50 -> type = V_387 ;
}
if ( V_331 != V_391 )
return V_331 ;
if ( F_137 ( V_74 ) )
return - V_83 ;
return V_391 ;
}
static int F_243 ( struct V_234 * V_235 , struct V_73 * V_74 )
{
int V_331 ;
F_233 ( V_74 ) ;
V_331 = F_237 ( V_74 ) ;
if ( V_331 != V_391 )
return V_331 ;
V_331 = F_240 ( V_74 ) ;
if ( V_331 != V_391 )
V_331 = F_223 ( V_235 , V_74 ) ;
return V_331 ;
}
static inline void F_244 ( struct V_222 * V_314 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_399 = V_314 -> V_223 . V_399 ;
if ( ( V_399 [ 1 ] & V_400 ) &&
! ( V_6 -> V_271 & V_401 ) )
V_6 -> V_271 |= V_402 ;
if ( ( V_399 [ 1 ] & V_403 ) &&
! ( V_6 -> V_271 & V_404 ) )
V_6 -> V_271 |= V_405 ;
if ( V_314 -> V_227 . V_352 != V_354 &&
V_399 [ 1 ] & V_406 )
V_6 -> V_271 &= ~ V_407 ;
if ( V_399 [ 2 ] & V_408 )
* V_7 = NULL ;
}
static int F_245 ( struct V_222 * V_314 ,
T_6 V_205 ,
int V_236 ,
struct V_325 * V_326 )
{
struct V_234 * V_235 = V_314 -> V_249 ;
struct V_13 * V_14 = V_235 -> V_292 ;
struct V_4 * V_4 ;
struct V_73 * V_74 ;
unsigned int V_409 ;
int V_61 ;
V_409 = F_246 ( & V_235 -> V_410 ) ;
V_61 = F_215 ( V_314 ) ;
if ( V_61 != 0 )
goto V_160;
V_74 = F_178 ( V_314 ) ;
V_61 = F_89 ( V_74 ) ;
if ( F_56 ( V_74 ) )
goto V_160;
if ( V_14 -> V_104 & V_386 )
F_146 ( V_411 , & V_74 -> V_236 ) ;
if ( V_314 -> V_223 . V_367 & V_412 )
F_146 ( V_413 , & V_74 -> V_236 ) ;
V_4 = V_314 -> V_4 ;
if ( F_247 ( V_4 ) ) {
struct V_4 * V_414 ;
F_220 ( V_4 ) ;
V_414 = F_248 ( V_4 , V_74 -> V_2 ) ;
if ( ! V_414 )
V_414 = F_249 ( F_250 ( V_74 -> V_2 ) , V_4 ) ;
if ( V_414 ) {
F_118 ( V_326 -> V_4 ) ;
V_326 -> V_4 = V_4 = V_414 ;
}
F_251 ( V_4 ,
F_252 ( F_14 ( V_314 -> V_3 ) ) ) ;
}
V_61 = F_212 ( V_235 -> V_307 , V_314 , V_74 , V_205 , V_236 ) ;
if ( V_61 != 0 )
goto V_160;
V_326 -> V_74 = V_74 ;
if ( F_14 ( V_4 ) == V_74 -> V_2 ) {
F_253 ( V_326 ) ;
if ( F_254 ( & V_235 -> V_410 , V_409 ) )
F_28 ( V_14 , V_74 ) ;
}
V_160:
return V_61 ;
}
static int F_255 ( struct V_2 * V_3 ,
struct V_325 * V_326 ,
int V_236 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_415 )
{
struct V_234 * V_235 ;
struct V_73 * V_74 = NULL ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_222 * V_314 ;
struct V_4 * V_4 = V_326 -> V_4 ;
struct V_51 * V_52 = V_326 -> V_52 ;
struct V_416 * * V_417 = & V_326 -> V_278 ;
T_6 V_205 = V_326 -> V_282 & ( V_207 | V_208 | V_418 ) ;
enum V_214 V_215 = V_217 ;
struct V_1 * V_419 = NULL ;
int V_331 ;
V_331 = - V_142 ;
V_235 = F_256 ( V_14 , V_52 , V_420 ) ;
if ( V_235 == NULL ) {
F_8 ( L_23 ) ;
goto V_421;
}
V_331 = F_217 ( V_14 ) ;
if ( V_331 != 0 )
goto V_422;
if ( F_257 ( V_4 ) )
F_162 ( F_14 ( V_4 ) , V_205 ) ;
V_331 = - V_142 ;
if ( F_257 ( V_4 ) )
V_215 = V_216 ;
V_314 = F_103 ( V_4 , V_235 , V_205 , V_236 , V_6 ,
V_7 , V_215 , V_420 ) ;
if ( V_314 == NULL )
goto V_422;
if ( V_7 ) {
V_419 = F_107 ( V_14 , V_420 ) ;
if ( F_56 ( V_419 ) ) {
V_331 = F_89 ( V_419 ) ;
goto V_423;
}
}
if ( V_14 -> V_15 [ 2 ] & V_424 ) {
if ( ! V_314 -> V_224 . V_278 ) {
V_314 -> V_224 . V_278 = F_258 () ;
if ( ! V_314 -> V_224 . V_278 )
goto V_247;
}
V_314 -> V_227 . V_267 = & V_425 [ 0 ] ;
}
if ( F_257 ( V_4 ) )
V_314 -> V_74 = F_176 ( F_14 ( V_4 ) , V_235 ) ;
V_331 = F_245 ( V_314 , V_205 , V_236 , V_326 ) ;
if ( V_331 != 0 )
goto V_247;
V_74 = V_326 -> V_74 ;
if ( ( V_314 -> V_227 . V_251 & ( V_383 | V_254 ) ) == ( V_383 | V_254 ) &&
( V_314 -> V_227 . V_352 != V_355 ) ) {
F_244 ( V_314 , V_6 , & V_7 ) ;
if ( V_6 -> V_271 & V_426 ) {
F_101 ( V_314 -> V_223 . V_224 ) ;
V_331 = F_259 ( V_74 -> V_2 , V_52 ,
V_314 -> V_223 . V_224 , V_6 ,
V_326 , V_7 , V_419 ) ;
if ( V_331 == 0 ) {
F_260 ( V_74 -> V_2 , V_6 ,
V_314 -> V_223 . V_224 ) ;
F_261 ( V_74 -> V_2 , V_314 -> V_223 . V_224 , V_419 ) ;
}
}
}
if ( V_415 && V_314 -> V_380 )
* V_415 |= V_427 ;
if ( F_262 ( V_417 , V_314 -> V_224 . V_278 , V_14 ) ) {
* V_417 = V_314 -> V_224 . V_278 ;
V_314 -> V_224 . V_278 = NULL ;
}
F_116 ( V_419 ) ;
F_126 ( V_314 ) ;
F_123 ( V_235 ) ;
return 0 ;
V_247:
F_116 ( V_419 ) ;
V_423:
F_126 ( V_314 ) ;
V_422:
F_123 ( V_235 ) ;
V_421:
return V_331 ;
}
static struct V_73 * F_263 ( struct V_2 * V_3 ,
struct V_325 * V_326 ,
int V_236 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_415 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_70 V_71 = { } ;
struct V_73 * V_66 ;
int V_331 ;
do {
V_331 = F_255 ( V_3 , V_326 , V_236 , V_6 , V_7 , V_415 ) ;
V_66 = V_326 -> V_74 ;
F_264 ( V_326 , V_236 , V_331 ) ;
if ( V_331 == 0 )
break;
if ( V_331 == - V_428 ) {
F_265 ( L_5
L_24 ,
F_105 ( V_3 ) -> V_55 -> V_107 ) ;
V_71 . V_77 = 1 ;
continue;
}
if ( V_331 == - V_81 ) {
V_71 . V_77 = 1 ;
continue;
}
if ( V_331 == - V_118 ) {
V_71 . V_77 = 1 ;
continue;
}
if ( F_97 ( V_14 , V_331 , & V_71 ) )
continue;
V_66 = F_57 ( F_36 ( V_14 ,
V_331 , & V_71 ) ) ;
} while ( V_71 . V_77 );
return V_66 ;
}
static int F_266 ( struct V_2 * V_2 ,
struct V_429 * V_430 ,
struct V_431 * V_66 ,
struct V_51 * V_52 ,
struct V_325 * V_326 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_432 ] ,
. V_339 = V_430 ,
. V_340 = V_66 ,
. V_51 = V_52 ,
} ;
struct V_51 * V_433 = NULL ;
unsigned long V_125 = V_170 ;
T_6 V_205 ;
bool V_434 ;
int V_331 ;
F_101 ( V_66 -> V_435 ) ;
V_434 = ( V_430 -> V_436 -> V_271 & V_437 ) ? true : false ;
V_205 = V_434 ? V_208 : V_207 ;
if ( F_267 ( V_2 , V_205 , & V_430 -> V_50 , & V_433 ) ) {
} else if ( V_434 && V_326 != NULL ) {
struct V_438 * V_439 ;
if ( ! F_268 ( V_326 -> V_74 ) )
return - V_440 ;
V_439 = F_269 ( V_326 ) ;
if ( F_56 ( V_439 ) )
return F_89 ( V_439 ) ;
V_331 = F_270 ( V_326 -> V_74 , V_208 , V_439 ,
& V_430 -> V_50 , & V_433 ) ;
F_271 ( V_439 ) ;
if ( V_331 == - V_35 )
return - V_440 ;
} else
F_19 ( & V_430 -> V_50 , & V_441 ) ;
if ( V_433 )
V_179 . V_51 = V_433 ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_430 -> V_176 , & V_66 -> V_177 , 1 ) ;
F_236 ( V_433 ) ;
if ( V_331 == 0 && V_326 != NULL )
F_49 ( V_14 , V_125 ) ;
F_272 ( V_2 , & V_430 -> V_50 , V_331 ) ;
return V_331 ;
}
static int F_259 ( struct V_2 * V_2 , struct V_51 * V_52 ,
struct V_442 * V_435 , struct V_5 * V_6 ,
struct V_325 * V_326 , struct V_1 * V_443 ,
struct V_1 * V_419 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_73 * V_74 = V_326 ? V_326 -> V_74 : NULL ;
struct V_429 V_430 = {
. V_269 = F_114 ( V_2 ) ,
. V_436 = V_6 ,
. V_14 = V_14 ,
. V_266 = V_14 -> V_15 ,
. V_7 = V_443 ,
} ;
struct V_431 V_66 = {
. V_435 = V_435 ,
. V_7 = V_419 ,
. V_14 = V_14 ,
} ;
struct V_70 V_71 = {
. V_74 = V_74 ,
. V_2 = V_2 ,
. V_50 = & V_430 . V_50 ,
} ;
int V_8 ;
V_430 . V_266 = F_6 ( V_14 , V_443 ) ;
if ( V_443 )
V_430 . V_266 = F_6 ( V_14 , V_419 ) ;
do {
V_8 = F_266 ( V_2 , & V_430 , & V_66 , V_52 , V_326 ) ;
switch ( V_8 ) {
case - V_83 :
if ( ! ( V_6 -> V_271 & V_437 ) ) {
F_273 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_55 -> V_107 ) ;
}
if ( V_74 && ! ( V_74 -> V_74 & V_208 ) ) {
V_8 = - V_440 ;
if ( V_6 -> V_271 & V_444 )
V_8 = - V_29 ;
goto V_160;
}
}
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
V_160:
return V_8 ;
}
static bool
F_274 ( struct V_2 * V_2 , struct V_112 * V_113 )
{
if ( V_2 == NULL || ! F_275 ( V_2 ) )
return false ;
return F_276 ( V_2 , V_113 ) ;
}
static void F_277 ( void * V_174 )
{
struct V_445 * V_172 = V_174 ;
struct V_234 * V_235 = V_172 -> V_74 -> V_249 ;
struct V_276 * V_277 = V_172 -> V_74 -> V_2 -> V_446 ;
if ( V_172 -> V_447 . V_448 )
F_278 ( & V_172 -> V_447 . V_430 , & V_172 -> V_447 . V_66 ,
V_172 -> V_66 . V_449 ) ;
F_122 ( V_172 -> V_74 ) ;
F_121 ( V_172 -> V_430 . V_226 ) ;
F_123 ( V_235 ) ;
F_124 ( V_277 ) ;
F_117 ( V_172 ) ;
}
static void F_279 ( struct V_112 * V_113 , void * V_174 )
{
struct V_445 * V_172 = V_174 ;
struct V_73 * V_74 = V_172 -> V_74 ;
struct V_13 * V_14 = F_105 ( V_172 -> V_2 ) ;
T_4 * V_450 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_78 ( V_113 , & V_172 -> V_66 . V_177 ) )
return;
F_280 ( V_74 , & V_172 -> V_430 , & V_172 -> V_66 , V_113 -> V_117 ) ;
if ( V_172 -> V_430 . V_451 && V_113 -> V_117 != 0 ) {
switch ( V_172 -> V_66 . V_449 ) {
default:
V_172 -> V_66 . V_449 = - V_452 ;
break;
case 0 :
V_172 -> V_430 . V_451 = NULL ;
V_172 -> V_66 . V_453 = NULL ;
break;
case - V_79 :
case - V_78 :
case - V_80 :
case - V_81 :
case - V_103 :
case - V_454 :
case - V_23 :
V_172 -> V_430 . V_451 = NULL ;
V_172 -> V_66 . V_453 = NULL ;
V_172 -> V_66 . V_449 = 0 ;
F_73 ( V_113 ) ;
return;
}
}
switch ( V_113 -> V_117 ) {
case 0 :
V_450 = & V_172 -> V_66 . V_50 ;
F_49 ( V_14 , V_172 -> V_125 ) ;
break;
case - V_455 :
if ( V_172 -> V_430 . V_266 != NULL ) {
V_172 -> V_430 . V_266 = NULL ;
V_172 -> V_66 . V_435 = NULL ;
V_113 -> V_117 = 0 ;
F_73 ( V_113 ) ;
goto V_456;
}
break;
case - V_79 :
case - V_85 :
case - V_80 :
F_18 ( V_14 ,
& V_172 -> V_430 . V_50 ,
V_113 -> V_350 . V_51 ) ;
case - V_103 :
case - V_81 :
if ( ! F_159 ( & V_172 -> V_430 . V_50 ,
& V_74 -> V_296 ) ) {
F_73 ( V_113 ) ;
goto V_456;
}
if ( V_172 -> V_430 . V_205 == 0 )
break;
default:
if ( F_43 ( V_113 , V_14 , V_74 , NULL ) == - V_118 ) {
F_73 ( V_113 ) ;
goto V_456;
}
}
F_149 ( V_74 , & V_172 -> V_430 . V_50 ,
V_450 , V_172 -> V_430 . V_205 ) ;
V_456:
F_165 ( V_172 -> V_430 . V_226 ) ;
F_172 ( V_172 -> V_2 , & V_172 -> V_435 ) ;
F_8 ( L_30 , V_34 , V_113 -> V_117 ) ;
}
static void F_281 ( struct V_112 * V_113 , void * V_174 )
{
struct V_445 * V_172 = V_174 ;
struct V_73 * V_74 = V_172 -> V_74 ;
struct V_2 * V_2 = V_172 -> V_2 ;
bool V_457 , V_458 , V_459 ;
int V_460 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_205 ( V_172 -> V_430 . V_226 , V_113 ) != 0 )
goto V_346;
V_113 -> V_350 . V_336 = & V_337 [ V_461 ] ;
F_46 ( & V_74 -> V_249 -> V_302 ) ;
V_459 = F_38 ( V_287 , & V_74 -> V_236 ) ;
V_457 = F_38 ( V_285 , & V_74 -> V_236 ) ;
V_458 = F_38 ( V_286 , & V_74 -> V_236 ) ;
F_19 ( & V_172 -> V_430 . V_50 , & V_74 -> V_296 ) ;
V_172 -> V_430 . V_205 = 0 ;
if ( V_74 -> V_279 == 0 ) {
if ( V_74 -> V_281 == 0 )
V_460 |= V_457 ;
else if ( V_457 )
V_172 -> V_430 . V_205 |= V_207 ;
if ( V_74 -> V_280 == 0 )
V_460 |= V_458 ;
else if ( V_458 )
V_172 -> V_430 . V_205 |= V_208 ;
if ( V_172 -> V_430 . V_205 != ( V_207 | V_208 ) )
V_460 |= V_459 ;
} else if ( V_459 )
V_172 -> V_430 . V_205 |= V_207 | V_208 ;
if ( ! F_268 ( V_74 ) ||
F_38 ( V_295 , & V_74 -> V_236 ) == 0 )
V_460 = 0 ;
F_48 ( & V_74 -> V_249 -> V_302 ) ;
if ( ! V_460 ) {
goto V_347;
}
if ( ! V_172 -> V_447 . V_448 && F_274 ( V_2 , V_113 ) ) {
F_165 ( V_172 -> V_430 . V_226 ) ;
goto V_346;
}
if ( V_172 -> V_430 . V_205 == 0 )
V_113 -> V_350 . V_336 = & V_337 [ V_462 ] ;
if ( V_172 -> V_430 . V_205 == 0 || V_172 -> V_430 . V_205 == V_207 ) {
if ( ! F_241 ( V_2 , V_207 ) )
V_172 -> V_430 . V_266 = F_105 ( V_2 ) -> V_463 ;
else
V_172 -> V_430 . V_266 = NULL ;
}
V_172 -> V_430 . V_253 =
F_98 ( F_105 ( V_2 ) ,
V_172 -> V_430 . V_205 , 0 ) ;
if ( V_172 -> V_66 . V_435 == NULL )
V_172 -> V_430 . V_266 = NULL ;
else if ( V_172 -> V_430 . V_266 == NULL )
V_172 -> V_66 . V_435 = NULL ;
V_172 -> V_125 = V_170 ;
if ( F_81 ( F_105 ( V_2 ) ,
& V_172 -> V_430 . V_176 ,
& V_172 -> V_66 . V_177 ,
V_113 ) != 0 )
F_165 ( V_172 -> V_430 . V_226 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_347:
V_113 -> V_358 = NULL ;
V_346:
F_78 ( V_113 , & V_172 -> V_66 . V_177 ) ;
}
int F_282 ( struct V_73 * V_74 , T_7 V_238 , int V_464 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_240 * ( * V_241 ) ( struct V_242 * , T_7 ) ;
struct V_445 * V_172 ;
struct V_234 * V_235 = V_74 -> V_249 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_462 ] ,
. V_51 = V_74 -> V_249 -> V_307 ,
} ;
struct V_180 V_341 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_465 ,
. V_343 = V_344 ,
. V_236 = V_345 ,
} ;
int V_331 = - V_142 ;
F_283 ( V_14 -> V_55 , V_466 ,
& V_341 . V_182 , & V_179 ) ;
V_172 = F_106 ( sizeof( * V_172 ) , V_238 ) ;
if ( V_172 == NULL )
goto V_160;
F_51 ( & V_172 -> V_430 . V_176 , & V_172 -> V_66 . V_177 , 1 ) ;
V_172 -> V_2 = V_74 -> V_2 ;
V_172 -> V_74 = V_74 ;
V_172 -> V_430 . V_269 = F_114 ( V_74 -> V_2 ) ;
V_241 = V_14 -> V_55 -> V_56 -> V_241 ;
V_172 -> V_430 . V_226 = V_241 ( & V_74 -> V_249 -> V_246 , V_238 ) ;
if ( F_56 ( V_172 -> V_430 . V_226 ) )
goto V_467;
F_101 ( & V_172 -> V_435 ) ;
V_172 -> V_430 . V_205 = 0 ;
V_172 -> V_447 . V_430 . V_468 = & V_172 -> V_447 . V_468 ;
V_172 -> V_66 . V_435 = & V_172 -> V_435 ;
V_172 -> V_66 . V_226 = V_172 -> V_430 . V_226 ;
V_172 -> V_66 . V_14 = V_14 ;
V_172 -> V_66 . V_449 = - V_452 ;
V_172 -> V_447 . V_448 = F_284 ( V_74 -> V_2 ,
& V_172 -> V_447 . V_430 , & V_172 -> V_447 . V_66 , V_179 . V_51 ) ;
if ( V_172 -> V_447 . V_448 ) {
V_172 -> V_430 . V_451 = & V_172 -> V_447 . V_430 ;
V_172 -> V_66 . V_453 = & V_172 -> V_447 . V_66 ;
}
F_108 ( V_172 -> V_2 -> V_446 ) ;
V_179 . V_339 = & V_172 -> V_430 ;
V_179 . V_340 = & V_172 -> V_66 ;
V_341 . V_185 = V_172 ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_331 = 0 ;
if ( V_464 )
V_331 = F_129 ( V_113 ) ;
F_90 ( V_113 ) ;
return V_331 ;
V_467:
F_117 ( V_172 ) ;
V_160:
F_122 ( V_74 ) ;
F_123 ( V_235 ) ;
return V_331 ;
}
static struct V_2 *
F_285 ( struct V_2 * V_3 , struct V_325 * V_326 ,
int V_251 , struct V_5 * V_469 , int * V_415 )
{
struct V_73 * V_74 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_326 -> V_4 , V_469 , & V_17 ) ;
V_74 = F_263 ( V_3 , V_326 , V_251 , V_469 , V_7 , V_415 ) ;
F_4 ( V_7 ) ;
if ( F_56 ( V_74 ) )
return F_286 ( V_74 ) ;
return V_74 -> V_2 ;
}
static void F_287 ( struct V_325 * V_326 , int V_470 )
{
if ( V_326 -> V_74 == NULL )
return;
if ( V_470 )
F_288 ( V_326 -> V_74 , V_326 -> V_282 ) ;
else
F_186 ( V_326 -> V_74 , V_326 -> V_282 ) ;
}
static int F_289 ( struct V_13 * V_14 , struct V_471 * V_472 )
{
T_1 V_266 [ 3 ] = {} , V_473 = V_14 -> V_55 -> V_474 ;
struct V_475 args = {
. V_472 = V_472 ,
. V_266 = V_266 ,
} ;
struct V_476 V_66 = {} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_477 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
int V_331 ;
V_266 [ 0 ] = V_478 |
V_479 |
V_480 |
V_481 |
V_482 ;
if ( V_473 )
V_266 [ 2 ] = V_483 ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_331 == 0 ) {
switch ( V_473 ) {
case 0 :
V_66 . V_15 [ 1 ] &= V_484 ;
V_66 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_66 . V_15 [ 2 ] &= V_485 ;
break;
case 2 :
V_66 . V_15 [ 2 ] &= V_486 ;
}
memcpy ( V_14 -> V_15 , V_66 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_104 &= ~ ( V_487 | V_488 |
V_489 | V_490 |
V_491 | V_492 | V_493 |
V_494 | V_495 |
V_496 | V_497 |
V_9 ) ;
if ( V_66 . V_15 [ 0 ] & V_498 &&
V_66 . V_499 & V_500 )
V_14 -> V_104 |= V_487 ;
if ( V_66 . V_501 != 0 )
V_14 -> V_104 |= V_488 ;
if ( V_66 . V_502 != 0 )
V_14 -> V_104 |= V_489 ;
if ( V_66 . V_15 [ 0 ] & V_45 )
V_14 -> V_104 |= V_490 ;
if ( V_66 . V_15 [ 1 ] & V_406 )
V_14 -> V_104 |= V_491 ;
if ( V_66 . V_15 [ 1 ] & V_503 )
V_14 -> V_104 |= V_492 ;
if ( V_66 . V_15 [ 1 ] & V_504 )
V_14 -> V_104 |= V_493 ;
if ( V_66 . V_15 [ 1 ] & V_505 )
V_14 -> V_104 |= V_494 ;
if ( V_66 . V_15 [ 1 ] & V_400 )
V_14 -> V_104 |= V_495 ;
if ( V_66 . V_15 [ 1 ] & V_506 )
V_14 -> V_104 |= V_496 ;
if ( V_66 . V_15 [ 1 ] & V_403 )
V_14 -> V_104 |= V_497 ;
#ifdef F_290
if ( V_66 . V_15 [ 2 ] & V_408 )
V_14 -> V_104 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_66 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_408 ;
memcpy ( V_14 -> V_463 , V_66 . V_15 , sizeof( V_14 -> V_463 ) ) ;
V_14 -> V_463 [ 0 ] &= V_507 | V_508 ;
V_14 -> V_463 [ 1 ] &= V_506 | V_403 ;
V_14 -> V_463 [ 2 ] = 0 ;
memcpy ( V_14 -> V_509 , V_66 . V_509 ,
sizeof( V_14 -> V_509 ) ) ;
V_14 -> V_499 = V_66 . V_499 ;
V_14 -> V_510 = V_66 . V_510 ;
}
return V_331 ;
}
int F_291 ( struct V_13 * V_14 , struct V_471 * V_472 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_289 ( V_14 , V_472 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_292 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 )
{
T_1 V_266 [ 3 ] ;
struct V_513 args = {
. V_266 = V_266 ,
} ;
struct V_514 V_66 = {
. V_14 = V_14 ,
. V_435 = V_512 -> V_435 ,
. V_269 = V_472 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_515 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
V_266 [ 0 ] = V_268 [ 0 ] ;
V_266 [ 1 ] = V_268 [ 1 ] ;
V_266 [ 2 ] = V_268 [ 2 ] & ~ V_408 ;
F_101 ( V_512 -> V_435 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_293 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_292 ( V_14 , V_472 , V_512 ) ;
F_294 ( V_14 , V_472 , V_512 -> V_435 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_160;
default:
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
}
} while ( V_71 . V_77 );
V_160:
return V_8 ;
}
static int F_295 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 , T_5 V_119 )
{
struct V_516 V_517 = {
. V_518 = V_119 ,
} ;
struct V_519 * V_520 ;
int V_61 ;
V_520 = F_296 ( & V_517 , V_14 -> V_108 ) ;
if ( F_56 ( V_520 ) ) {
V_61 = - V_29 ;
goto V_160;
}
V_61 = F_293 ( V_14 , V_472 , V_512 ) ;
V_160:
return V_61 ;
}
static int F_297 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 )
{
static const T_5 V_521 [] = {
V_124 ,
V_123 ,
V_522 ,
V_523 ,
V_524 ,
} ;
int V_331 = - V_24 ;
T_9 V_525 ;
if ( V_14 -> V_526 . V_527 > 0 ) {
for ( V_525 = 0 ; V_525 < V_14 -> V_526 . V_527 ; V_525 ++ ) {
V_331 = F_295 ( V_14 , V_472 , V_512 ,
V_14 -> V_526 . V_528 [ V_525 ] ) ;
if ( V_331 == - V_22 || V_331 == - V_29 )
continue;
break;
}
} else {
for ( V_525 = 0 ; V_525 < F_298 ( V_521 ) ; V_525 ++ ) {
V_331 = F_295 ( V_14 , V_472 , V_512 ,
V_521 [ V_525 ] ) ;
if ( V_331 == - V_22 || V_331 == - V_29 )
continue;
break;
}
}
if ( V_331 == - V_29 )
V_331 = - V_24 ;
return V_331 ;
}
int F_299 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 ,
bool V_529 )
{
int V_331 = 0 ;
if ( ! V_529 )
V_331 = F_293 ( V_14 , V_472 , V_512 ) ;
if ( V_529 || V_331 == V_22 )
V_331 = V_14 -> V_55 -> V_56 -> V_530 ( V_14 ,
V_472 , V_512 ) ;
if ( V_331 == 0 )
V_331 = F_291 ( V_14 , V_472 ) ;
if ( V_331 == 0 )
V_331 = F_300 ( V_14 , V_472 , V_512 ) ;
return F_7 ( V_331 ) ;
}
static int F_301 ( struct V_13 * V_14 , struct V_471 * V_531 ,
struct V_511 * V_512 )
{
int error ;
struct V_442 * V_435 = V_512 -> V_435 ;
struct V_1 * V_7 = NULL ;
error = F_291 ( V_14 , V_531 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_107 ( V_14 , V_420 ) ;
if ( F_56 ( V_7 ) )
return F_89 ( V_7 ) ;
error = F_216 ( V_14 , V_531 , V_435 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_247;
}
if ( V_435 -> V_322 & V_532 &&
! F_302 ( & V_14 -> V_533 , & V_435 -> V_533 ) )
memcpy ( & V_14 -> V_533 , & V_435 -> V_533 , sizeof( V_14 -> V_533 ) ) ;
V_247:
F_116 ( V_7 ) ;
return error ;
}
static int F_303 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_534 * V_265 , struct V_442 * V_435 ,
struct V_471 * V_472 )
{
int V_331 = - V_142 ;
struct V_535 * V_535 = NULL ;
struct V_536 * V_537 = NULL ;
V_535 = F_304 ( V_420 ) ;
if ( V_535 == NULL )
goto V_160;
V_537 = F_305 ( sizeof( struct V_536 ) , V_420 ) ;
if ( V_537 == NULL )
goto V_160;
V_331 = F_306 ( V_108 , V_3 , V_265 , V_537 , V_535 ) ;
if ( V_331 != 0 )
goto V_160;
if ( F_302 ( & F_105 ( V_3 ) -> V_533 , & V_537 -> V_435 . V_533 ) ) {
F_8 ( L_34
L_35 , V_34 , V_265 -> V_265 ) ;
V_331 = - V_87 ;
goto V_160;
}
F_307 ( & V_537 -> V_435 ) ;
memcpy ( V_435 , & V_537 -> V_435 , sizeof( struct V_442 ) ) ;
memset ( V_472 , 0 , sizeof( struct V_471 ) ) ;
V_160:
if ( V_535 )
F_308 ( V_535 ) ;
F_117 ( V_537 ) ;
return V_331 ;
}
static int F_309 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_538 args = {
. V_269 = V_472 ,
. V_266 = V_14 -> V_15 ,
} ;
struct V_539 V_66 = {
. V_435 = V_435 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_540 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
args . V_266 = F_6 ( V_14 , V_7 ) ;
F_101 ( V_435 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_216 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_309 ( V_14 , V_472 , V_435 , V_7 ) ;
F_310 ( V_14 , V_472 , V_435 , V_8 ) ;
V_8 = F_36 ( V_14 , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_311 ( struct V_4 * V_4 , struct V_442 * V_435 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_51 * V_52 = NULL ;
struct V_325 * V_326 = NULL ;
struct V_1 * V_7 = NULL ;
int V_331 ;
if ( F_312 ( V_2 ) &&
V_6 -> V_271 & V_437 &&
V_6 -> V_541 < F_313 ( V_2 ) )
F_314 ( V_2 ) ;
F_101 ( V_435 ) ;
if ( V_6 -> V_271 & V_444 )
V_6 -> V_271 &= ~ ( V_405 | V_542 ) ;
if ( ( V_6 -> V_271 & ~ ( V_543 | V_444 ) ) == 0 )
return 0 ;
if ( V_6 -> V_271 & V_543 ) {
V_326 = F_315 ( V_6 -> V_544 ) ;
if ( V_326 )
V_52 = V_326 -> V_52 ;
}
V_7 = F_107 ( F_105 ( V_2 ) , V_420 ) ;
if ( F_56 ( V_7 ) )
return F_89 ( V_7 ) ;
V_331 = F_259 ( V_2 , V_52 , V_435 , V_6 , V_326 , NULL , V_7 ) ;
if ( V_331 == 0 ) {
F_260 ( V_2 , V_6 , V_435 ) ;
F_261 ( V_2 , V_435 , V_7 ) ;
}
F_116 ( V_7 ) ;
return V_331 ;
}
static int F_316 ( struct V_64 * V_65 , struct V_2 * V_3 ,
const struct V_534 * V_265 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
int V_331 ;
struct V_545 args = {
. V_266 = V_14 -> V_15 ,
. V_546 = F_114 ( V_3 ) ,
. V_265 = V_265 ,
} ;
struct V_514 V_66 = {
. V_14 = V_14 ,
. V_435 = V_435 ,
. V_7 = V_7 ,
. V_269 = V_472 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_547 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
args . V_266 = F_6 ( V_14 , V_7 ) ;
F_101 ( V_435 ) ;
F_8 ( L_36 , V_265 -> V_265 ) ;
V_331 = F_91 ( V_65 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
F_8 ( L_37 , V_331 ) ;
return V_331 ;
}
static void F_317 ( struct V_442 * V_435 )
{
V_435 -> V_322 |= V_359 | V_548 |
V_549 | V_550 ;
V_435 -> V_282 = V_364 | V_551 | V_552 ;
V_435 -> V_553 = 2 ;
}
static int F_318 ( struct V_64 * * V_65 , struct V_2 * V_3 ,
const struct V_534 * V_265 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_70 V_71 = { } ;
struct V_64 * V_108 = * V_65 ;
int V_8 ;
do {
V_8 = F_316 ( V_108 , V_3 , V_265 , V_472 , V_435 , V_7 ) ;
F_319 ( V_3 , V_265 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_327 ;
goto V_160;
case - V_87 :
V_8 = F_303 ( V_108 , V_3 , V_265 , V_435 , V_472 ) ;
if ( V_8 == - V_87 )
V_8 = F_36 ( F_105 ( V_3 ) , V_8 , & V_71 ) ;
goto V_160;
case - V_22 :
V_8 = - V_24 ;
if ( V_108 != * V_65 )
goto V_160;
V_108 = F_320 ( V_108 , V_3 , V_265 ) ;
if ( F_56 ( V_108 ) )
return F_89 ( V_108 ) ;
V_71 . V_77 = 1 ;
break;
default:
V_8 = F_36 ( F_105 ( V_3 ) , V_8 , & V_71 ) ;
}
} while ( V_71 . V_77 );
V_160:
if ( V_8 == 0 )
* V_65 = V_108 ;
else if ( V_108 != * V_65 )
F_321 ( V_108 ) ;
return V_8 ;
}
static int F_322 ( struct V_2 * V_3 , const struct V_534 * V_265 ,
struct V_471 * V_472 , struct V_442 * V_435 ,
struct V_1 * V_7 )
{
int V_331 ;
struct V_64 * V_108 = F_323 ( V_3 ) ;
V_331 = F_318 ( & V_108 , V_3 , V_265 , V_472 , V_435 , V_7 ) ;
if ( V_108 != F_323 ( V_3 ) ) {
F_321 ( V_108 ) ;
F_317 ( V_435 ) ;
}
return V_331 ;
}
struct V_64 *
F_324 ( struct V_2 * V_3 , const struct V_534 * V_265 ,
struct V_471 * V_472 , struct V_442 * V_435 )
{
struct V_64 * V_108 = F_323 ( V_3 ) ;
int V_331 ;
V_331 = F_318 ( & V_108 , V_3 , V_265 , V_472 , V_435 , NULL ) ;
if ( V_331 < 0 )
return F_57 ( V_331 ) ;
return ( V_108 == F_323 ( V_3 ) ) ? F_325 ( V_108 ) : V_108 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_374 * V_554 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_555 args = {
. V_269 = F_114 ( V_2 ) ,
. V_266 = V_14 -> V_463 ,
} ;
struct V_556 V_66 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_557 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_554 -> V_52 ,
} ;
int V_282 = V_554 -> V_376 ;
int V_331 = 0 ;
if ( V_282 & V_381 )
args . V_231 |= V_255 ;
if ( F_327 ( V_2 -> V_558 ) ) {
if ( V_282 & V_559 )
args . V_231 |= V_256 | V_257 | V_560 ;
if ( V_282 & V_379 )
args . V_231 |= V_561 ;
} else {
if ( V_282 & V_559 )
args . V_231 |= V_256 | V_257 ;
if ( V_282 & V_379 )
args . V_231 |= V_258 ;
}
V_66 . V_435 = F_328 () ;
if ( V_66 . V_435 == NULL )
return - V_142 ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( ! V_331 ) {
F_213 ( V_554 , V_66 . V_231 ) ;
F_172 ( V_2 , V_66 . V_435 ) ;
}
F_329 ( V_66 . V_435 ) ;
return V_331 ;
}
static int F_330 ( struct V_2 * V_2 , struct V_374 * V_554 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_326 ( V_2 , V_554 ) ;
F_331 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_332 ( struct V_2 * V_2 , struct V_535 * V_535 ,
unsigned int V_48 , unsigned int V_562 )
{
struct V_563 args = {
. V_269 = F_114 ( V_2 ) ,
. V_48 = V_48 ,
. V_562 = V_562 ,
. V_42 = & V_535 ,
} ;
struct V_564 V_66 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_565 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
return F_91 ( F_105 ( V_2 ) -> V_108 , F_105 ( V_2 ) , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_333 ( struct V_2 * V_2 , struct V_535 * V_535 ,
unsigned int V_48 , unsigned int V_562 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_332 ( V_2 , V_535 , V_48 , V_562 ) ;
F_334 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_335 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_236 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_1 V_17 , * V_443 = NULL ;
struct V_325 * V_326 ;
struct V_73 * V_74 ;
int V_331 = 0 ;
V_326 = F_336 ( V_4 , V_207 , NULL ) ;
if ( F_56 ( V_326 ) )
return F_89 ( V_326 ) ;
V_443 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_566 ) )
V_6 -> V_10 &= ~ F_111 () ;
V_74 = F_263 ( V_3 , V_326 , V_236 , V_6 , V_443 , NULL ) ;
if ( F_56 ( V_74 ) ) {
V_331 = F_89 ( V_74 ) ;
goto V_160;
}
V_160:
F_4 ( V_443 ) ;
F_193 ( V_326 ) ;
return V_331 ;
}
static int F_337 ( struct V_2 * V_3 , const struct V_534 * V_265 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_567 args = {
. V_269 = F_114 ( V_3 ) ,
. V_265 = * V_265 ,
} ;
struct V_568 V_66 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_569 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
unsigned long V_125 = V_170 ;
int V_331 ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 1 ) ;
if ( V_331 == 0 )
F_92 ( V_3 , & V_66 . V_187 , V_125 ) ;
return V_331 ;
}
static int F_338 ( struct V_2 * V_3 , const struct V_534 * V_265 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_337 ( V_3 , V_265 ) ;
F_339 ( V_3 , V_265 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_340 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_567 * args = V_179 -> V_339 ;
struct V_568 * V_66 = V_179 -> V_340 ;
V_66 -> V_14 = V_14 ;
V_179 -> V_336 = & V_337 [ V_569 ] ;
F_51 ( & args -> V_176 , & V_66 -> V_177 , 1 ) ;
F_101 ( V_66 -> V_570 ) ;
}
static void F_341 ( struct V_112 * V_113 , struct V_571 * V_174 )
{
F_81 ( F_184 ( V_174 -> V_4 -> V_248 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_342 ( struct V_112 * V_113 , struct V_2 * V_3 )
{
struct V_571 * V_174 = V_113 -> V_572 ;
struct V_568 * V_66 = & V_174 -> V_66 ;
if ( ! F_78 ( V_113 , & V_66 -> V_177 ) )
return 0 ;
if ( F_43 ( V_113 , V_66 -> V_14 , NULL ,
& V_174 -> V_60 ) == - V_118 )
return 0 ;
if ( V_113 -> V_117 == 0 )
F_92 ( V_3 , & V_66 -> V_187 , V_66 -> V_570 -> V_384 ) ;
return 1 ;
}
static void F_343 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_573 * V_430 = V_179 -> V_339 ;
struct V_574 * V_66 = V_179 -> V_340 ;
V_179 -> V_336 = & V_337 [ V_575 ] ;
V_66 -> V_14 = V_14 ;
F_51 ( & V_430 -> V_176 , & V_66 -> V_177 , 1 ) ;
}
static void F_344 ( struct V_112 * V_113 , struct V_576 * V_174 )
{
F_81 ( F_105 ( V_174 -> V_577 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_345 ( struct V_112 * V_113 , struct V_2 * V_577 ,
struct V_2 * V_578 )
{
struct V_576 * V_174 = V_113 -> V_572 ;
struct V_574 * V_66 = & V_174 -> V_66 ;
if ( ! F_78 ( V_113 , & V_66 -> V_177 ) )
return 0 ;
if ( F_43 ( V_113 , V_66 -> V_14 , NULL , & V_174 -> V_60 ) == - V_118 )
return 0 ;
if ( V_113 -> V_117 == 0 ) {
F_92 ( V_577 , & V_66 -> V_579 , V_66 -> V_580 -> V_384 ) ;
if ( V_578 != V_577 )
F_92 ( V_578 , & V_66 -> V_581 , V_66 -> V_582 -> V_384 ) ;
}
return 1 ;
}
static int F_346 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_534 * V_265 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_583 V_430 = {
. V_269 = F_114 ( V_2 ) ,
. V_546 = F_114 ( V_3 ) ,
. V_265 = V_265 ,
. V_266 = V_14 -> V_15 ,
} ;
struct V_584 V_66 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_585 ] ,
. V_339 = & V_430 ,
. V_340 = & V_66 ,
} ;
int V_331 = - V_142 ;
V_66 . V_435 = F_328 () ;
if ( V_66 . V_435 == NULL )
goto V_160;
V_66 . V_7 = F_107 ( V_14 , V_420 ) ;
if ( F_56 ( V_66 . V_7 ) ) {
V_331 = F_89 ( V_66 . V_7 ) ;
goto V_160;
}
V_430 . V_266 = F_6 ( V_14 , V_66 . V_7 ) ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_430 . V_176 , & V_66 . V_177 , 1 ) ;
if ( ! V_331 ) {
F_92 ( V_3 , & V_66 . V_187 , V_66 . V_435 -> V_384 ) ;
V_331 = F_347 ( V_2 , V_66 . V_435 ) ;
if ( ! V_331 )
F_261 ( V_2 , V_66 . V_435 , V_66 . V_7 ) ;
}
F_116 ( V_66 . V_7 ) ;
V_160:
F_329 ( V_66 . V_435 ) ;
return V_331 ;
}
static int F_348 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_534 * V_265 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( F_105 ( V_2 ) ,
F_346 ( V_2 , V_3 , V_265 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static struct V_586 * F_349 ( struct V_2 * V_3 ,
const struct V_534 * V_265 , struct V_5 * V_6 , T_1 V_587 )
{
struct V_586 * V_174 ;
V_174 = F_106 ( sizeof( * V_174 ) , V_420 ) ;
if ( V_174 != NULL ) {
struct V_13 * V_14 = F_105 ( V_3 ) ;
V_174 -> V_7 = F_107 ( V_14 , V_420 ) ;
if ( F_56 ( V_174 -> V_7 ) )
goto V_335;
V_174 -> V_179 . V_336 = & V_337 [ V_588 ] ;
V_174 -> V_179 . V_339 = & V_174 -> V_430 ;
V_174 -> V_179 . V_340 = & V_174 -> V_66 ;
V_174 -> V_430 . V_546 = F_114 ( V_3 ) ;
V_174 -> V_430 . V_14 = V_14 ;
V_174 -> V_430 . V_265 = V_265 ;
V_174 -> V_430 . V_237 = V_6 ;
V_174 -> V_430 . V_587 = V_587 ;
V_174 -> V_430 . V_266 = F_6 ( V_14 , V_174 -> V_7 ) ;
V_174 -> V_430 . V_252 = F_111 () ;
V_174 -> V_66 . V_14 = V_14 ;
V_174 -> V_66 . V_269 = & V_174 -> V_269 ;
V_174 -> V_66 . V_435 = & V_174 -> V_435 ;
V_174 -> V_66 . V_7 = V_174 -> V_7 ;
F_101 ( V_174 -> V_66 . V_435 ) ;
}
return V_174 ;
V_335:
F_117 ( V_174 ) ;
return NULL ;
}
static int F_350 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_586 * V_174 )
{
int V_331 = F_91 ( F_105 ( V_3 ) -> V_108 , F_105 ( V_3 ) , & V_174 -> V_179 ,
& V_174 -> V_430 . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
if ( V_331 == 0 ) {
F_92 ( V_3 , & V_174 -> V_66 . V_589 ,
V_174 -> V_66 . V_435 -> V_384 ) ;
V_331 = F_351 ( V_4 , V_174 -> V_66 . V_269 , V_174 -> V_66 . V_435 , V_174 -> V_66 . V_7 ) ;
}
return V_331 ;
}
static void F_352 ( struct V_586 * V_174 )
{
F_116 ( V_174 -> V_7 ) ;
F_117 ( V_174 ) ;
}
static int F_353 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_535 * V_535 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_586 * V_174 ;
int V_331 = - V_590 ;
if ( V_12 > V_591 )
goto V_160;
V_331 = - V_142 ;
V_174 = F_349 ( V_3 , & V_4 -> V_11 , V_6 , V_592 ) ;
if ( V_174 == NULL )
goto V_160;
V_174 -> V_179 . V_336 = & V_337 [ V_593 ] ;
V_174 -> V_430 . V_273 . V_594 . V_42 = & V_535 ;
V_174 -> V_430 . V_273 . V_594 . V_12 = V_12 ;
V_174 -> V_430 . V_7 = V_7 ;
V_331 = F_350 ( V_3 , V_4 , V_174 ) ;
F_352 ( V_174 ) ;
V_160:
return V_331 ;
}
static int F_354 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_535 * V_535 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_353 ( V_3 , V_4 , V_535 , V_12 , V_6 , V_7 ) ;
F_355 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_356 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_586 * V_174 ;
int V_331 = - V_142 ;
V_174 = F_349 ( V_3 , & V_4 -> V_11 , V_6 , V_595 ) ;
if ( V_174 == NULL )
goto V_160;
V_174 -> V_430 . V_7 = V_7 ;
V_331 = F_350 ( V_3 , V_4 , V_174 ) ;
F_352 ( V_174 ) ;
V_160:
return V_331 ;
}
static int F_357 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_566 ) )
V_6 -> V_10 &= ~ F_111 () ;
do {
V_8 = F_356 ( V_3 , V_4 , V_6 , V_7 ) ;
F_358 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_359 ( struct V_4 * V_4 , struct V_51 * V_52 ,
T_2 V_36 , struct V_535 * * V_42 , unsigned int V_49 , int V_596 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_269 = F_114 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_266 = F_105 ( F_14 ( V_4 ) ) -> V_15 ,
. V_596 = V_596 ,
} ;
struct V_597 V_66 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_598 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_331 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_93 ( V_3 ) -> V_599 , V_4 , & args ) ;
V_66 . V_48 = args . V_48 ;
V_331 = F_91 ( F_105 ( V_3 ) -> V_108 , F_105 ( V_3 ) , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_331 >= 0 ) {
memcpy ( F_93 ( V_3 ) -> V_599 , V_66 . V_37 . V_174 , V_600 ) ;
V_331 += args . V_48 ;
}
F_360 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_331 ) ;
return V_331 ;
}
static int F_361 ( struct V_4 * V_4 , struct V_51 * V_52 ,
T_2 V_36 , struct V_535 * * V_42 , unsigned int V_49 , int V_596 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_359 ( V_4 , V_52 , V_36 ,
V_42 , V_49 , V_596 ) ;
F_362 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_36 ( F_105 ( F_14 ( V_4 ) ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_363 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_601 )
{
struct V_586 * V_174 ;
int V_282 = V_6 -> V_10 ;
int V_331 = - V_142 ;
V_174 = F_349 ( V_3 , & V_4 -> V_11 , V_6 , V_602 ) ;
if ( V_174 == NULL )
goto V_160;
if ( F_364 ( V_282 ) )
V_174 -> V_430 . V_587 = V_603 ;
else if ( F_365 ( V_282 ) ) {
V_174 -> V_430 . V_587 = V_604 ;
V_174 -> V_430 . V_273 . V_605 . V_606 = F_366 ( V_601 ) ;
V_174 -> V_430 . V_273 . V_605 . V_607 = F_367 ( V_601 ) ;
}
else if ( F_368 ( V_282 ) ) {
V_174 -> V_430 . V_587 = V_608 ;
V_174 -> V_430 . V_273 . V_605 . V_606 = F_366 ( V_601 ) ;
V_174 -> V_430 . V_273 . V_605 . V_607 = F_367 ( V_601 ) ;
} else if ( ! F_369 ( V_282 ) ) {
V_331 = - V_27 ;
goto V_335;
}
V_174 -> V_430 . V_7 = V_7 ;
V_331 = F_350 ( V_3 , V_4 , V_174 ) ;
V_335:
F_352 ( V_174 ) ;
V_160:
return V_331 ;
}
static int F_370 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_601 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_566 ) )
V_6 -> V_10 &= ~ F_111 () ;
do {
V_8 = F_363 ( V_3 , V_4 , V_6 , V_7 , V_601 ) ;
F_371 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_372 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_609 * V_610 )
{
struct V_611 args = {
. V_269 = V_472 ,
. V_266 = V_14 -> V_15 ,
} ;
struct V_612 V_66 = {
. V_610 = V_610 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_613 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
F_101 ( V_610 -> V_435 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_373 ( struct V_13 * V_14 , struct V_471 * V_472 , struct V_609 * V_610 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_372 ( V_14 , V_472 , V_610 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_374 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_614 )
{
struct V_615 args = {
. V_269 = V_472 ,
. V_266 = V_14 -> V_15 ,
} ;
struct V_616 V_66 = {
. V_614 = V_614 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_617 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_300 ( struct V_13 * V_14 , struct V_471 * V_472 , struct V_511 * V_614 )
{
struct V_70 V_71 = { } ;
unsigned long V_618 = V_170 ;
int V_8 ;
do {
V_8 = F_374 ( V_14 , V_472 , V_614 ) ;
F_375 ( V_14 , V_472 , V_614 -> V_435 , V_8 ) ;
if ( V_8 == 0 ) {
F_376 ( V_14 -> V_55 ,
V_614 -> V_619 * V_98 ,
V_618 ) ;
break;
}
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_377 ( struct V_13 * V_14 , struct V_471 * V_472 , struct V_511 * V_614 )
{
int error ;
F_101 ( V_614 -> V_435 ) ;
error = F_300 ( V_14 , V_472 , V_614 ) ;
if ( error == 0 ) {
V_14 -> V_620 = V_614 -> V_621 ;
F_378 ( V_14 , V_472 , V_614 ) ;
}
return error ;
}
static int F_379 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_622 * V_623 )
{
struct V_624 args = {
. V_269 = V_472 ,
. V_266 = V_14 -> V_15 ,
} ;
struct V_625 V_66 = {
. V_623 = V_623 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_626 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
if ( ( args . V_266 [ 0 ] & V_627 [ 0 ] ) == 0 ) {
memset ( V_623 , 0 , sizeof( * V_623 ) ) ;
return 0 ;
}
F_101 ( V_623 -> V_435 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_380 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_622 * V_623 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_379 ( V_14 , V_472 , V_623 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
int F_381 ( T_4 * V_50 ,
const struct V_325 * V_326 ,
const struct V_438 * V_439 ,
T_6 V_205 )
{
return F_270 ( V_326 -> V_74 , V_205 , V_439 , V_50 , NULL ) ;
}
static bool F_382 ( T_4 * V_50 ,
const struct V_325 * V_326 ,
const struct V_438 * V_439 ,
T_6 V_205 )
{
T_4 V_628 ;
if ( F_381 ( & V_628 , V_326 , V_439 , V_205 ) == - V_35 )
return true ;
return F_159 ( V_50 , & V_628 ) ;
}
static bool F_383 ( int V_8 )
{
switch ( V_8 ) {
case - V_78 :
case - V_79 :
case - V_81 :
case - V_85 :
case - V_103 :
case - V_83 :
case - V_80 :
return true ;
}
return false ;
}
static int F_384 ( struct V_112 * V_113 , struct V_629 * V_630 )
{
struct V_13 * V_14 = F_105 ( V_630 -> V_2 ) ;
F_385 ( V_630 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
struct V_70 V_71 = {
. V_2 = V_630 -> V_2 ,
. V_74 = V_630 -> args . V_631 -> V_74 ,
. V_50 = & V_630 -> args . V_50 ,
} ;
V_113 -> V_117 = F_39 ( V_113 ,
V_14 , V_113 -> V_117 , & V_71 ) ;
if ( V_71 . V_77 ) {
F_73 ( V_113 ) ;
return - V_118 ;
}
}
if ( V_113 -> V_117 > 0 )
F_49 ( V_14 , V_630 -> V_125 ) ;
return 0 ;
}
static bool F_386 ( struct V_112 * V_113 ,
struct V_632 * args )
{
if ( ! F_383 ( V_113 -> V_117 ) ||
F_382 ( & args -> V_50 ,
args -> V_631 ,
args -> V_633 ,
V_207 ) )
return false ;
F_73 ( V_113 ) ;
return true ;
}
static int F_387 ( struct V_112 * V_113 , struct V_629 * V_630 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_78 ( V_113 , & V_630 -> V_66 . V_177 ) )
return - V_118 ;
if ( F_386 ( V_113 , & V_630 -> args ) )
return - V_118 ;
if ( V_113 -> V_117 > 0 )
F_360 ( V_630 -> V_2 ) ;
return V_630 -> V_634 ? V_630 -> V_634 ( V_113 , V_630 ) :
F_384 ( V_113 , V_630 ) ;
}
static void F_388 ( struct V_629 * V_630 ,
struct V_178 * V_179 )
{
V_630 -> V_125 = V_170 ;
if ( ! V_630 -> V_634 )
V_630 -> V_634 = F_384 ;
V_179 -> V_336 = & V_337 [ V_635 ] ;
F_51 ( & V_630 -> args . V_176 , & V_630 -> V_66 . V_177 , 0 ) ;
}
static int F_389 ( struct V_112 * V_113 ,
struct V_629 * V_630 )
{
if ( F_81 ( F_105 ( V_630 -> V_2 ) ,
& V_630 -> args . V_176 ,
& V_630 -> V_66 . V_177 ,
V_113 ) )
return 0 ;
if ( F_381 ( & V_630 -> args . V_50 , V_630 -> args . V_631 ,
V_630 -> args . V_633 ,
V_630 -> V_636 -> V_637 ) == - V_35 )
return - V_35 ;
if ( F_390 ( F_38 ( V_638 , & V_630 -> args . V_631 -> V_236 ) ) )
return - V_35 ;
return 0 ;
}
static int F_391 ( struct V_112 * V_113 ,
struct V_629 * V_630 )
{
struct V_2 * V_2 = V_630 -> V_2 ;
F_392 ( V_630 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
struct V_70 V_71 = {
. V_2 = V_630 -> V_2 ,
. V_74 = V_630 -> args . V_631 -> V_74 ,
. V_50 = & V_630 -> args . V_50 ,
} ;
V_113 -> V_117 = F_39 ( V_113 ,
F_105 ( V_2 ) , V_113 -> V_117 ,
& V_71 ) ;
if ( V_71 . V_77 ) {
F_73 ( V_113 ) ;
return - V_118 ;
}
}
if ( V_113 -> V_117 >= 0 ) {
F_49 ( F_105 ( V_2 ) , V_630 -> V_125 ) ;
F_393 ( V_630 ) ;
}
return 0 ;
}
static bool F_394 ( struct V_112 * V_113 ,
struct V_632 * args )
{
if ( ! F_383 ( V_113 -> V_117 ) ||
F_382 ( & args -> V_50 ,
args -> V_631 ,
args -> V_633 ,
V_208 ) )
return false ;
F_73 ( V_113 ) ;
return true ;
}
static int F_395 ( struct V_112 * V_113 , struct V_629 * V_630 )
{
if ( ! F_78 ( V_113 , & V_630 -> V_66 . V_177 ) )
return - V_118 ;
if ( F_394 ( V_113 , & V_630 -> args ) )
return - V_118 ;
return V_630 -> V_634 ? V_630 -> V_634 ( V_113 , V_630 ) :
F_391 ( V_113 , V_630 ) ;
}
static
bool F_396 ( struct V_629 * V_630 )
{
if ( V_630 -> V_639 != NULL || V_630 -> V_640 != NULL )
return false ;
return F_241 ( V_630 -> V_2 , V_207 ) == 0 ;
}
static void F_397 ( struct V_629 * V_630 ,
struct V_178 * V_179 )
{
struct V_13 * V_14 = F_105 ( V_630 -> V_2 ) ;
if ( ! F_396 ( V_630 ) ) {
V_630 -> args . V_266 = NULL ;
V_630 -> V_66 . V_435 = NULL ;
} else
V_630 -> args . V_266 = V_14 -> V_463 ;
if ( ! V_630 -> V_634 )
V_630 -> V_634 = F_391 ;
V_630 -> V_66 . V_14 = V_14 ;
V_630 -> V_125 = V_170 ;
V_179 -> V_336 = & V_337 [ V_641 ] ;
F_51 ( & V_630 -> args . V_176 , & V_630 -> V_66 . V_177 , 1 ) ;
}
static void F_398 ( struct V_112 * V_113 , struct V_642 * V_174 )
{
F_81 ( F_105 ( V_174 -> V_2 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_399 ( struct V_112 * V_113 , struct V_642 * V_174 )
{
struct V_2 * V_2 = V_174 -> V_2 ;
F_400 ( V_174 , V_113 -> V_117 ) ;
if ( F_43 ( V_113 , F_105 ( V_2 ) ,
NULL , NULL ) == - V_118 ) {
F_73 ( V_113 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_401 ( struct V_112 * V_113 , struct V_642 * V_174 )
{
if ( ! F_78 ( V_113 , & V_174 -> V_66 . V_177 ) )
return - V_118 ;
return V_174 -> V_643 ( V_113 , V_174 ) ;
}
static void F_402 ( struct V_642 * V_174 , struct V_178 * V_179 )
{
struct V_13 * V_14 = F_105 ( V_174 -> V_2 ) ;
if ( V_174 -> V_643 == NULL )
V_174 -> V_643 = F_399 ;
V_174 -> V_66 . V_14 = V_14 ;
V_179 -> V_336 = & V_337 [ V_644 ] ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
}
static void F_403 ( void * V_172 )
{
struct V_645 * V_174 = V_172 ;
struct V_55 * V_72 = V_174 -> V_108 ;
if ( F_404 ( & V_72 -> V_646 ) > 1 )
F_405 ( V_72 ) ;
F_406 ( V_72 ) ;
F_117 ( V_174 ) ;
}
static void F_407 ( struct V_112 * V_113 , void * V_172 )
{
struct V_645 * V_174 = V_172 ;
struct V_55 * V_72 = V_174 -> V_108 ;
unsigned long V_125 = V_174 -> V_125 ;
F_408 ( V_72 , V_113 -> V_117 ) ;
switch ( V_113 -> V_117 ) {
case 0 :
break;
case - V_88 :
F_31 ( V_72 ) ;
break;
default:
if ( F_38 ( V_647 , & V_72 -> V_648 ) == 0 )
return;
if ( V_113 -> V_117 != V_649 ) {
F_29 ( V_72 ) ;
return;
}
F_409 ( V_72 ) ;
}
F_45 ( V_72 , V_125 ) ;
}
static int F_410 ( struct V_55 * V_72 , struct V_51 * V_52 , unsigned V_650 )
{
struct V_178 V_179 = {
. V_336 = & V_337 [ V_651 ] ,
. V_339 = V_72 ,
. V_51 = V_52 ,
} ;
struct V_645 * V_174 ;
if ( V_650 == 0 )
return 0 ;
if ( ! F_411 ( & V_72 -> V_646 ) )
return - V_35 ;
V_174 = F_305 ( sizeof( * V_174 ) , V_328 ) ;
if ( V_174 == NULL )
return - V_142 ;
V_174 -> V_108 = V_72 ;
V_174 -> V_125 = V_170 ;
return F_412 ( V_72 -> V_120 , & V_179 , V_652 ,
& V_653 , V_174 ) ;
}
static int F_413 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_336 = & V_337 [ V_651 ] ,
. V_339 = V_72 ,
. V_51 = V_52 ,
} ;
unsigned long V_618 = V_170 ;
int V_331 ;
V_331 = F_414 ( V_72 -> V_120 , & V_179 , V_652 ) ;
if ( V_331 < 0 )
return V_331 ;
F_45 ( V_72 , V_618 ) ;
return 0 ;
}
static inline int F_415 ( struct V_13 * V_14 )
{
return V_14 -> V_104 & V_487 ;
}
static int F_416 ( const void * V_654 , T_9 V_655 ,
struct V_535 * * V_42 )
{
struct V_535 * V_656 , * * V_657 ;
int V_658 = 0 ;
T_9 V_12 ;
V_657 = V_42 ;
do {
V_12 = F_417 ( T_9 , V_659 , V_655 ) ;
V_656 = F_304 ( V_420 ) ;
if ( V_656 == NULL )
goto V_660;
memcpy ( F_418 ( V_656 ) , V_654 , V_12 ) ;
V_654 += V_12 ;
V_655 -= V_12 ;
* V_42 ++ = V_656 ;
V_658 ++ ;
} while ( V_655 != 0 );
return V_658 ;
V_660:
for(; V_658 > 0 ; V_658 -- )
F_308 ( V_657 [ V_658 - 1 ] ) ;
return - V_142 ;
}
static void F_419 ( struct V_2 * V_2 , struct V_661 * V_662 )
{
struct V_188 * V_189 = F_93 ( V_2 ) ;
F_46 ( & V_2 -> V_190 ) ;
F_117 ( V_189 -> V_663 ) ;
V_189 -> V_663 = V_662 ;
F_48 ( & V_2 -> V_190 ) ;
}
static void F_420 ( struct V_2 * V_2 )
{
F_419 ( V_2 , NULL ) ;
}
static inline T_11 F_421 ( struct V_2 * V_2 , char * V_654 , T_9 V_655 )
{
struct V_188 * V_189 = F_93 ( V_2 ) ;
struct V_661 * V_662 ;
int V_61 = - V_327 ;
F_46 ( & V_2 -> V_190 ) ;
V_662 = V_189 -> V_663 ;
if ( V_662 == NULL )
goto V_160;
if ( V_654 == NULL )
goto V_664;
if ( V_662 -> V_665 == 0 )
goto V_160;
V_61 = - V_666 ;
if ( V_662 -> V_12 > V_655 )
goto V_160;
memcpy ( V_654 , V_662 -> V_174 , V_662 -> V_12 ) ;
V_664:
V_61 = V_662 -> V_12 ;
V_160:
F_48 ( & V_2 -> V_190 ) ;
return V_61 ;
}
static void F_422 ( struct V_2 * V_2 , struct V_535 * * V_42 , T_9 V_48 , T_9 V_667 )
{
struct V_661 * V_662 ;
T_9 V_655 = sizeof( * V_662 ) + V_667 ;
if ( V_655 <= V_659 ) {
V_662 = F_305 ( V_655 , V_420 ) ;
if ( V_662 == NULL )
goto V_160;
V_662 -> V_665 = 1 ;
F_423 ( V_662 -> V_174 , V_42 , V_48 , V_667 ) ;
} else {
V_662 = F_305 ( sizeof( * V_662 ) , V_420 ) ;
if ( V_662 == NULL )
goto V_160;
V_662 -> V_665 = 0 ;
}
V_662 -> V_12 = V_667 ;
V_160:
F_419 ( V_2 , V_662 ) ;
}
static T_11 F_424 ( struct V_2 * V_2 , void * V_654 , T_9 V_655 )
{
struct V_535 * V_42 [ V_668 ] = { NULL , } ;
struct V_669 args = {
. V_269 = F_114 ( V_2 ) ,
. V_670 = V_42 ,
. V_667 = V_655 ,
} ;
struct V_671 V_66 = {
. V_667 = V_655 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_672 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
unsigned int V_673 = F_425 ( V_655 , V_659 ) ;
int V_61 = - V_142 , V_525 ;
if ( V_673 == 0 )
V_673 = 1 ;
if ( V_673 > F_298 ( V_42 ) )
return - V_666 ;
for ( V_525 = 0 ; V_525 < V_673 ; V_525 ++ ) {
V_42 [ V_525 ] = F_304 ( V_420 ) ;
if ( ! V_42 [ V_525 ] )
goto V_335;
}
V_66 . V_674 = F_304 ( V_420 ) ;
if ( ! V_66 . V_674 )
goto V_335;
args . V_667 = V_673 * V_659 ;
F_8 ( L_40 ,
V_34 , V_654 , V_655 , V_673 , args . V_667 ) ;
V_61 = F_91 ( F_105 ( V_2 ) -> V_108 , F_105 ( V_2 ) ,
& V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_61 )
goto V_335;
if ( V_66 . V_675 & V_676 ) {
if ( V_654 == NULL )
goto V_677;
V_61 = - V_666 ;
goto V_335;
}
F_422 ( V_2 , V_42 , V_66 . V_678 , V_66 . V_667 ) ;
if ( V_654 ) {
if ( V_66 . V_667 > V_655 ) {
V_61 = - V_666 ;
goto V_335;
}
F_423 ( V_654 , V_42 , V_66 . V_678 , V_66 . V_667 ) ;
}
V_677:
V_61 = V_66 . V_667 ;
V_335:
for ( V_525 = 0 ; V_525 < V_673 ; V_525 ++ )
if ( V_42 [ V_525 ] )
F_308 ( V_42 [ V_525 ] ) ;
if ( V_66 . V_674 )
F_308 ( V_66 . V_674 ) ;
return V_61 ;
}
static T_11 F_426 ( struct V_2 * V_2 , void * V_654 , T_9 V_655 )
{
struct V_70 V_71 = { } ;
T_11 V_61 ;
do {
V_61 = F_424 ( V_2 , V_654 , V_655 ) ;
F_427 ( V_2 , V_61 ) ;
if ( V_61 >= 0 )
break;
V_61 = F_36 ( F_105 ( V_2 ) , V_61 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_61 ;
}
static T_11 F_428 ( struct V_2 * V_2 , void * V_654 , T_9 V_655 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
int V_61 ;
if ( ! F_415 ( V_14 ) )
return - V_679 ;
V_61 = F_429 ( V_14 , V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( F_93 ( V_2 ) -> V_191 & V_200 )
F_430 ( V_2 ) ;
V_61 = F_421 ( V_2 , V_654 , V_655 ) ;
if ( V_61 != - V_327 )
return V_61 ;
return F_426 ( V_2 , V_654 , V_655 ) ;
}
static int F_431 ( struct V_2 * V_2 , const void * V_654 , T_9 V_655 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_535 * V_42 [ V_668 ] ;
struct V_680 V_430 = {
. V_269 = F_114 ( V_2 ) ,
. V_670 = V_42 ,
. V_667 = V_655 ,
} ;
struct V_681 V_66 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_682 ] ,
. V_339 = & V_430 ,
. V_340 = & V_66 ,
} ;
unsigned int V_673 = F_425 ( V_655 , V_659 ) ;
int V_61 , V_525 ;
if ( ! F_415 ( V_14 ) )
return - V_679 ;
if ( V_673 > F_298 ( V_42 ) )
return - V_666 ;
V_525 = F_416 ( V_654 , V_655 , V_430 . V_670 ) ;
if ( V_525 < 0 )
return V_525 ;
F_163 ( V_2 ) ;
V_61 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_430 . V_176 , & V_66 . V_177 , 1 ) ;
for (; V_525 > 0 ; V_525 -- )
F_432 ( V_42 [ V_525 - 1 ] ) ;
F_46 ( & V_2 -> V_190 ) ;
F_93 ( V_2 ) -> V_191 |= V_192 ;
F_48 ( & V_2 -> V_190 ) ;
F_433 ( V_2 ) ;
F_430 ( V_2 ) ;
return V_61 ;
}
static int F_434 ( struct V_2 * V_2 , const void * V_654 , T_9 V_655 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_431 ( V_2 , V_654 , V_655 ) ;
F_435 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_436 ( struct V_2 * V_2 , void * V_654 ,
T_9 V_655 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_442 V_435 ;
struct V_1 V_7 = { 0 , 0 , V_655 , V_654 } ;
T_1 V_266 [ 3 ] = { 0 , 0 , V_408 } ;
struct V_538 V_430 = {
. V_269 = F_114 ( V_2 ) ,
. V_266 = V_266 ,
} ;
struct V_539 V_66 = {
. V_435 = & V_435 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_540 ] ,
. V_339 = & V_430 ,
. V_340 = & V_66 ,
} ;
int V_61 ;
F_101 ( & V_435 ) ;
V_61 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_430 . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_61 )
return V_61 ;
if ( ! ( V_435 . V_322 & V_683 ) )
return - V_327 ;
if ( V_655 < V_7 . V_12 )
return - V_666 ;
return 0 ;
}
static int F_437 ( struct V_2 * V_2 , void * V_654 ,
T_9 V_655 )
{
struct V_70 V_71 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_679 ;
do {
V_8 = F_436 ( V_2 , V_654 , V_655 ) ;
F_438 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_439 ( struct V_2 * V_2 ,
struct V_1 * V_443 ,
struct V_442 * V_435 ,
struct V_1 * V_419 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
const T_1 V_266 [ 3 ] = { 0 , 0 , V_408 } ;
struct V_429 V_430 = {
. V_269 = F_114 ( V_2 ) ,
. V_436 = & V_6 ,
. V_14 = V_14 ,
. V_266 = V_266 ,
. V_7 = V_443 ,
} ;
struct V_431 V_66 = {
. V_435 = V_435 ,
. V_7 = V_419 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_432 ] ,
. V_339 = & V_430 ,
. V_340 = & V_66 ,
} ;
int V_331 ;
F_19 ( & V_430 . V_50 , & V_441 ) ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_430 . V_176 , & V_66 . V_177 , 1 ) ;
if ( V_331 )
F_8 ( L_41 , V_34 , V_331 ) ;
return V_331 ;
}
static int F_440 ( struct V_2 * V_2 ,
struct V_1 * V_443 ,
struct V_442 * V_435 ,
struct V_1 * V_419 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_439 ( V_2 , V_443 ,
V_435 , V_419 ) ;
F_441 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_442 ( struct V_2 * V_2 , const void * V_654 , T_9 V_655 )
{
struct V_1 V_443 , * V_419 = NULL ;
struct V_442 V_435 ;
struct V_51 * V_52 ;
int V_331 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_679 ;
F_101 ( & V_435 ) ;
V_443 . V_684 = 0 ;
V_443 . V_685 = 0 ;
V_443 . V_7 = ( char * ) V_654 ;
V_443 . V_12 = V_655 ;
V_52 = F_443 () ;
if ( F_56 ( V_52 ) )
return F_89 ( V_52 ) ;
V_419 = F_107 ( F_105 ( V_2 ) , V_420 ) ;
if ( F_56 ( V_419 ) ) {
V_331 = - F_89 ( V_419 ) ;
goto V_160;
}
V_331 = F_440 ( V_2 , & V_443 , & V_435 , V_419 ) ;
if ( V_331 == 0 )
F_261 ( V_2 , & V_435 , V_419 ) ;
F_116 ( V_419 ) ;
V_160:
F_236 ( V_52 ) ;
return V_331 ;
}
static void F_444 ( const struct V_55 * V_72 ,
T_12 * V_686 )
{
T_3 V_272 [ 2 ] ;
if ( F_38 ( V_687 , & V_72 -> V_116 ) ) {
V_272 [ 0 ] = F_445 ( V_688 ) ;
V_272 [ 1 ] = F_445 ( V_688 ) ;
} else {
struct V_689 * V_690 = F_446 ( V_72 -> V_691 , V_692 ) ;
T_2 V_693 = F_112 ( V_690 -> V_694 ) ;
V_272 [ 0 ] = F_445 ( V_693 >> 32 ) ;
V_272 [ 1 ] = F_445 ( V_693 ) ;
}
memcpy ( V_686 -> V_174 , V_272 , sizeof( V_686 -> V_174 ) ) ;
}
static int
F_447 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_695 ;
if ( V_72 -> V_696 != NULL )
return 0 ;
F_157 () ;
V_12 = 14 + strlen ( V_72 -> V_697 ) + 1 +
strlen ( F_448 ( V_72 -> V_120 , V_698 ) ) +
1 +
strlen ( F_448 ( V_72 -> V_120 , V_699 ) ) +
1 ;
F_160 () ;
if ( V_12 > V_700 + 1 )
return - V_27 ;
V_695 = F_305 ( V_12 , V_420 ) ;
if ( ! V_695 )
return - V_142 ;
F_157 () ;
F_449 ( V_695 , V_12 , L_42 ,
V_72 -> V_697 ,
F_448 ( V_72 -> V_120 , V_698 ) ,
F_448 ( V_72 -> V_120 , V_699 ) ) ;
F_160 () ;
V_72 -> V_696 = V_695 ;
return 0 ;
}
static int
F_450 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_695 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_701 ) + 1 +
strlen ( V_72 -> V_120 -> V_702 ) + 1 ;
if ( V_12 > V_700 + 1 )
return - V_27 ;
V_695 = F_305 ( V_12 , V_420 ) ;
if ( ! V_695 )
return - V_142 ;
F_449 ( V_695 , V_12 , L_43 ,
V_72 -> V_703 -> V_704 , V_72 -> V_474 ,
V_701 ,
V_72 -> V_120 -> V_702 ) ;
V_72 -> V_696 = V_695 ;
return 0 ;
}
static int
F_451 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_695 ;
if ( V_72 -> V_696 != NULL )
return 0 ;
if ( V_701 [ 0 ] != '\0' )
return F_450 ( V_72 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_72 -> V_120 -> V_702 ) + 1 ;
if ( V_12 > V_700 + 1 )
return - V_27 ;
V_695 = F_305 ( V_12 , V_420 ) ;
if ( ! V_695 )
return - V_142 ;
F_449 ( V_695 , V_12 , L_44 ,
V_72 -> V_703 -> V_704 , V_72 -> V_474 ,
V_72 -> V_120 -> V_702 ) ;
V_72 -> V_696 = V_695 ;
return 0 ;
}
static unsigned int
F_452 ( const struct V_55 * V_72 , char * V_654 , T_9 V_12 )
{
if ( strchr ( V_72 -> V_697 , ':' ) != NULL )
return F_449 ( V_654 , V_12 , L_45 ) ;
else
return F_449 ( V_654 , V_12 , L_46 ) ;
}
static void F_453 ( struct V_112 * V_113 , void * V_172 )
{
struct V_705 * V_706 = V_172 ;
if ( V_113 -> V_117 == 0 )
V_706 -> V_707 = F_234 ( V_113 -> V_708 -> V_709 ) ;
}
int F_454 ( struct V_55 * V_72 , T_1 V_710 ,
unsigned short V_711 , struct V_51 * V_52 ,
struct V_712 * V_66 )
{
T_12 V_713 ;
struct V_705 V_714 = {
. V_713 = & V_713 ,
. V_715 = V_710 ,
. V_716 = V_72 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_717 ] ,
. V_339 = & V_714 ,
. V_340 = V_66 ,
. V_51 = V_52 ,
} ;
struct V_112 * V_113 ;
struct V_180 V_341 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_718 ,
. V_185 = & V_714 ,
. V_236 = V_652 ,
} ;
int V_331 ;
F_444 ( V_72 , & V_713 ) ;
if ( F_38 ( V_719 , & V_72 -> V_720 ) )
V_331 = F_451 ( V_72 ) ;
else
V_331 = F_447 ( V_72 ) ;
if ( V_331 )
goto V_160;
V_714 . V_721 =
F_452 ( V_72 ,
V_714 . V_722 ,
sizeof( V_714 . V_722 ) ) ;
V_714 . V_723 = F_449 ( V_714 . V_724 ,
sizeof( V_714 . V_724 ) , L_47 ,
V_72 -> V_697 , V_711 >> 8 , V_711 & 255 ) ;
F_8 ( L_48 ,
V_72 -> V_120 -> V_121 -> V_725 -> V_726 ,
V_72 -> V_696 ) ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) ) {
V_331 = F_89 ( V_113 ) ;
goto V_160;
}
V_331 = V_113 -> V_117 ;
if ( V_714 . V_707 ) {
V_72 -> V_727 = F_455 ( V_714 . V_707 ) ;
F_236 ( V_714 . V_707 ) ;
}
F_90 ( V_113 ) ;
V_160:
F_456 ( V_72 , V_331 ) ;
F_8 ( L_49 , V_331 ) ;
return V_331 ;
}
int F_457 ( struct V_55 * V_72 ,
struct V_712 * V_430 ,
struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_336 = & V_337 [ V_728 ] ,
. V_339 = V_430 ,
. V_51 = V_52 ,
} ;
int V_331 ;
F_8 ( L_50 ,
V_72 -> V_120 -> V_121 -> V_725 -> V_726 ,
V_72 -> V_260 ) ;
V_331 = F_414 ( V_72 -> V_120 , & V_179 , V_652 ) ;
F_458 ( V_72 , V_331 ) ;
F_8 ( L_51 , V_331 ) ;
return V_331 ;
}
static void F_459 ( struct V_112 * V_113 , void * V_172 )
{
struct V_729 * V_174 = V_172 ;
if ( ! F_78 ( V_113 , & V_174 -> V_66 . V_177 ) )
return;
F_460 ( & V_174 -> args , & V_174 -> V_66 , V_113 -> V_117 ) ;
if ( V_174 -> args . V_451 && V_113 -> V_117 != 0 ) {
switch( V_174 -> V_66 . V_449 ) {
default:
V_174 -> V_66 . V_449 = - V_452 ;
break;
case 0 :
V_174 -> args . V_451 = NULL ;
V_174 -> V_66 . V_453 = NULL ;
break;
case - V_79 :
case - V_78 :
case - V_80 :
case - V_81 :
case - V_103 :
case - V_454 :
case - V_23 :
V_174 -> args . V_451 = NULL ;
V_174 -> V_66 . V_453 = NULL ;
V_174 -> V_66 . V_449 = 0 ;
F_73 ( V_113 ) ;
return;
}
}
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_174 -> V_66 . V_14 , V_174 -> V_125 ) ;
break;
case - V_79 :
case - V_78 :
case - V_80 :
F_18 ( V_174 -> V_66 . V_14 ,
V_174 -> args . V_50 ,
V_113 -> V_350 . V_51 ) ;
case - V_81 :
case - V_103 :
case - V_85 :
V_113 -> V_117 = 0 ;
break;
case - V_455 :
if ( V_174 -> args . V_266 ) {
V_174 -> args . V_266 = NULL ;
V_174 -> V_66 . V_435 = NULL ;
V_113 -> V_117 = 0 ;
F_73 ( V_113 ) ;
return;
}
default:
if ( F_43 ( V_113 , V_174 -> V_66 . V_14 ,
NULL , NULL ) == - V_118 ) {
F_73 ( V_113 ) ;
return;
}
}
V_174 -> V_319 = V_113 -> V_117 ;
}
static void F_461 ( void * V_172 )
{
struct V_729 * V_174 = V_172 ;
struct V_2 * V_2 = V_174 -> V_2 ;
if ( V_2 ) {
if ( V_174 -> V_447 . V_448 )
F_278 ( & V_174 -> V_447 . V_430 , & V_174 -> V_447 . V_66 ,
V_174 -> V_66 . V_449 ) ;
F_462 ( V_2 , & V_174 -> V_435 ) ;
F_463 ( V_2 ) ;
}
F_117 ( V_172 ) ;
}
static void F_464 ( struct V_112 * V_113 , void * V_174 )
{
struct V_729 * V_730 ;
V_730 = (struct V_729 * ) V_174 ;
if ( ! V_730 -> V_447 . V_448 && F_274 ( V_730 -> V_2 , V_113 ) )
return;
F_81 ( V_730 -> V_66 . V_14 ,
& V_730 -> args . V_176 ,
& V_730 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_465 ( struct V_2 * V_2 , struct V_51 * V_52 , const T_4 * V_50 , int V_731 )
{
struct V_729 * V_174 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_732 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_733 ,
. V_236 = V_345 ,
} ;
int V_331 = 0 ;
V_174 = F_106 ( sizeof( * V_174 ) , V_328 ) ;
if ( V_174 == NULL )
return - V_142 ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
F_283 ( V_14 -> V_55 ,
V_466 ,
& V_341 . V_182 , & V_179 ) ;
V_174 -> args . V_472 = & V_174 -> V_269 ;
V_174 -> args . V_50 = & V_174 -> V_50 ;
V_174 -> args . V_266 = V_14 -> V_463 ;
F_206 ( & V_174 -> V_269 , F_114 ( V_2 ) ) ;
F_19 ( & V_174 -> V_50 , V_50 ) ;
V_174 -> V_66 . V_435 = & V_174 -> V_435 ;
V_174 -> V_66 . V_14 = V_14 ;
V_174 -> V_66 . V_449 = - V_452 ;
V_174 -> V_447 . V_430 . V_468 = & V_174 -> V_447 . V_468 ;
F_101 ( V_174 -> V_66 . V_435 ) ;
V_174 -> V_125 = V_170 ;
V_174 -> V_319 = 0 ;
V_174 -> V_447 . V_448 = F_284 ( V_2 , & V_174 -> V_447 . V_430 , & V_174 -> V_447 . V_66 , V_52 ) ;
V_174 -> V_2 = F_466 ( V_2 ) ;
if ( V_174 -> V_2 ) {
if ( V_174 -> V_447 . V_448 ) {
V_174 -> args . V_451 = & V_174 -> V_447 . V_430 ;
V_174 -> V_66 . V_453 = & V_174 -> V_447 . V_66 ;
}
} else if ( V_174 -> V_447 . V_448 ) {
F_278 ( & V_174 -> V_447 . V_430 , & V_174 -> V_447 . V_66 , 0 ) ;
V_174 -> V_447 . V_448 = false ;
}
V_341 . V_185 = V_174 ;
V_179 . V_339 = & V_174 -> args ;
V_179 . V_340 = & V_174 -> V_66 ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
if ( ! V_731 )
goto V_160;
V_331 = F_128 ( V_113 ) ;
if ( V_331 != 0 )
goto V_160;
V_331 = V_174 -> V_319 ;
V_160:
F_90 ( V_113 ) ;
return V_331 ;
}
int F_467 ( struct V_2 * V_2 , struct V_51 * V_52 , const T_4 * V_50 , int V_731 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_465 ( V_2 , V_52 , V_50 , V_731 ) ;
F_468 ( V_2 , V_50 , V_8 ) ;
switch ( V_8 ) {
case - V_85 :
case - V_80 :
case 0 :
return 0 ;
}
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_469 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_736 )
{
struct V_2 * V_2 = V_74 -> V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_737 V_430 = {
. V_269 = F_114 ( V_2 ) ,
. V_738 = V_736 ,
} ;
struct V_739 V_66 = {
. V_740 = V_736 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_741 ] ,
. V_339 = & V_430 ,
. V_340 = & V_66 ,
. V_51 = V_74 -> V_249 -> V_307 ,
} ;
struct V_308 * V_309 ;
int V_331 ;
V_430 . V_742 . V_259 = V_72 -> V_260 ;
V_331 = F_470 ( V_74 , V_736 ) ;
if ( V_331 != 0 )
goto V_160;
V_309 = V_736 -> V_743 . V_744 . V_249 ;
V_430 . V_742 . V_261 = V_309 -> V_745 . V_264 ;
V_430 . V_742 . V_746 = V_14 -> V_746 ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_430 . V_176 , & V_66 . V_177 , 1 ) ;
switch ( V_331 ) {
case 0 :
V_736 -> V_747 = V_748 ;
break;
case - V_333 :
V_331 = 0 ;
}
V_736 -> V_749 -> V_750 ( V_736 ) ;
V_736 -> V_749 = NULL ;
V_160:
return V_331 ;
}
static int F_471 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_736 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_469 ( V_74 , V_734 , V_736 ) ;
F_472 ( V_736 , V_74 , V_734 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_74 -> V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static struct V_751 * F_473 ( struct V_735 * V_738 ,
struct V_325 * V_326 ,
struct V_308 * V_309 ,
struct V_240 * V_226 )
{
struct V_751 * V_41 ;
struct V_2 * V_2 = V_309 -> V_310 -> V_2 ;
V_41 = F_106 ( sizeof( * V_41 ) , V_328 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_430 . V_269 = F_114 ( V_2 ) ;
V_41 -> V_430 . V_738 = & V_41 -> V_738 ;
V_41 -> V_430 . V_226 = V_226 ;
V_41 -> V_66 . V_226 = V_226 ;
V_41 -> V_309 = V_309 ;
F_110 ( & V_309 -> V_396 ) ;
V_41 -> V_326 = F_181 ( V_326 ) ;
memcpy ( & V_41 -> V_738 , V_738 , sizeof( V_41 -> V_738 ) ) ;
V_41 -> V_14 = F_105 ( V_2 ) ;
return V_41 ;
}
static void F_474 ( void * V_174 )
{
struct V_751 * V_172 = V_174 ;
F_121 ( V_172 -> V_430 . V_226 ) ;
F_238 ( V_172 -> V_309 ) ;
F_193 ( V_172 -> V_326 ) ;
F_117 ( V_172 ) ;
}
static void F_475 ( struct V_112 * V_113 , void * V_174 )
{
struct V_751 * V_172 = V_174 ;
if ( ! F_78 ( V_113 , & V_172 -> V_66 . V_177 ) )
return;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_172 -> V_14 , V_172 -> V_125 ) ;
F_476 ( V_172 -> V_309 -> V_310 -> V_2 , & V_172 -> V_738 ) ;
if ( F_161 ( V_172 -> V_309 ,
& V_172 -> V_66 . V_50 ) )
break;
case - V_79 :
case - V_80 :
F_18 ( V_172 -> V_14 ,
& V_172 -> V_430 . V_50 ,
V_113 -> V_350 . V_51 ) ;
case - V_81 :
case - V_103 :
case - V_85 :
if ( ! F_159 ( & V_172 -> V_430 . V_50 ,
& V_172 -> V_309 -> V_312 ) )
F_73 ( V_113 ) ;
break;
default:
if ( F_43 ( V_113 , V_172 -> V_14 ,
NULL , NULL ) == - V_118 )
F_73 ( V_113 ) ;
}
F_165 ( V_172 -> V_430 . V_226 ) ;
}
static void F_477 ( struct V_112 * V_113 , void * V_174 )
{
struct V_751 * V_172 = V_174 ;
if ( F_205 ( V_172 -> V_430 . V_226 , V_113 ) != 0 )
goto V_346;
F_19 ( & V_172 -> V_430 . V_50 , & V_172 -> V_309 -> V_312 ) ;
if ( F_38 ( V_394 , & V_172 -> V_309 -> V_395 ) == 0 ) {
goto V_347;
}
V_172 -> V_125 = V_170 ;
if ( F_81 ( V_172 -> V_14 ,
& V_172 -> V_430 . V_176 ,
& V_172 -> V_66 . V_177 ,
V_113 ) != 0 )
F_165 ( V_172 -> V_430 . V_226 ) ;
return;
V_347:
V_113 -> V_358 = NULL ;
V_346:
F_78 ( V_113 , & V_172 -> V_66 . V_177 ) ;
}
static struct V_112 * F_478 ( struct V_735 * V_738 ,
struct V_325 * V_326 ,
struct V_308 * V_309 ,
struct V_240 * V_226 )
{
struct V_751 * V_174 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_752 ] ,
. V_51 = V_326 -> V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = F_323 ( V_309 -> V_310 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_753 ,
. V_343 = V_344 ,
. V_236 = V_345 ,
} ;
F_283 ( F_105 ( V_309 -> V_310 -> V_2 ) -> V_55 ,
V_466 , & V_341 . V_182 , & V_179 ) ;
V_738 -> V_747 = V_748 ;
V_174 = F_473 ( V_738 , V_326 , V_309 , V_226 ) ;
if ( V_174 == NULL ) {
F_121 ( V_226 ) ;
return F_57 ( - V_142 ) ;
}
F_51 ( & V_174 -> V_430 . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
V_179 . V_339 = & V_174 -> V_430 ;
V_179 . V_340 = & V_174 -> V_66 ;
V_341 . V_185 = V_174 ;
return F_88 ( & V_341 ) ;
}
static int F_479 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_736 )
{
struct V_2 * V_2 = V_74 -> V_2 ;
struct V_234 * V_235 = V_74 -> V_249 ;
struct V_188 * V_189 = F_93 ( V_2 ) ;
struct V_240 * V_226 ;
struct V_308 * V_309 ;
struct V_112 * V_113 ;
struct V_240 * ( * V_241 ) ( struct V_242 * , T_7 ) ;
int V_331 = 0 ;
unsigned char V_754 = V_736 -> V_754 ;
V_331 = F_470 ( V_74 , V_736 ) ;
V_736 -> V_754 |= V_755 ;
F_480 ( & V_235 -> V_756 ) ;
F_481 ( & V_189 -> V_757 ) ;
if ( F_476 ( V_2 , V_736 ) == - V_327 ) {
F_482 ( & V_189 -> V_757 ) ;
F_483 ( & V_235 -> V_756 ) ;
goto V_160;
}
F_482 ( & V_189 -> V_757 ) ;
F_483 ( & V_235 -> V_756 ) ;
if ( V_331 != 0 )
goto V_160;
V_309 = V_736 -> V_743 . V_744 . V_249 ;
if ( F_38 ( V_394 , & V_309 -> V_395 ) == 0 )
goto V_160;
V_241 = F_105 ( V_2 ) -> V_55 -> V_56 -> V_241 ;
V_226 = V_241 ( & V_309 -> V_745 , V_420 ) ;
V_331 = - V_142 ;
if ( F_56 ( V_226 ) )
goto V_160;
V_113 = F_478 ( V_736 , F_315 ( V_736 -> V_758 ) , V_309 , V_226 ) ;
V_331 = F_89 ( V_113 ) ;
if ( F_56 ( V_113 ) )
goto V_160;
V_331 = F_128 ( V_113 ) ;
F_90 ( V_113 ) ;
V_160:
V_736 -> V_754 = V_754 ;
F_484 ( V_736 , V_74 , V_759 , V_331 ) ;
return V_331 ;
}
static struct V_760 * F_485 ( struct V_735 * V_738 ,
struct V_325 * V_326 , struct V_308 * V_309 ,
T_7 V_238 )
{
struct V_760 * V_41 ;
struct V_2 * V_2 = V_309 -> V_310 -> V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_240 * ( * V_241 ) ( struct V_242 * , T_7 ) ;
V_41 = F_106 ( sizeof( * V_41 ) , V_238 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_430 . V_269 = F_114 ( V_2 ) ;
V_41 -> V_430 . V_738 = & V_41 -> V_738 ;
V_41 -> V_430 . V_761 = F_486 ( & V_309 -> V_310 -> V_249 -> V_246 , V_238 ) ;
if ( F_56 ( V_41 -> V_430 . V_761 ) )
goto V_335;
V_241 = V_14 -> V_55 -> V_56 -> V_241 ;
V_41 -> V_430 . V_762 = V_241 ( & V_309 -> V_745 , V_238 ) ;
if ( F_56 ( V_41 -> V_430 . V_762 ) )
goto V_763;
V_41 -> V_430 . V_742 . V_259 = V_14 -> V_55 -> V_260 ;
V_41 -> V_430 . V_742 . V_261 = V_309 -> V_745 . V_264 ;
V_41 -> V_430 . V_742 . V_746 = V_14 -> V_746 ;
V_41 -> V_66 . V_762 = V_41 -> V_430 . V_762 ;
V_41 -> V_309 = V_309 ;
V_41 -> V_14 = V_14 ;
F_110 ( & V_309 -> V_396 ) ;
V_41 -> V_326 = F_181 ( V_326 ) ;
memcpy ( & V_41 -> V_738 , V_738 , sizeof( V_41 -> V_738 ) ) ;
return V_41 ;
V_763:
F_121 ( V_41 -> V_430 . V_761 ) ;
V_335:
F_117 ( V_41 ) ;
return NULL ;
}
static void F_487 ( struct V_112 * V_113 , void * V_172 )
{
struct V_760 * V_174 = V_172 ;
struct V_73 * V_74 = V_174 -> V_309 -> V_310 ;
F_8 ( L_29 , V_34 ) ;
if ( F_205 ( V_174 -> V_430 . V_762 , V_113 ) != 0 )
goto V_346;
if ( ! F_38 ( V_394 , & V_174 -> V_309 -> V_395 ) ) {
if ( F_205 ( V_174 -> V_430 . V_761 , V_113 ) != 0 ) {
goto V_764;
}
F_19 ( & V_174 -> V_430 . V_296 ,
& V_74 -> V_296 ) ;
V_174 -> V_430 . V_765 = 1 ;
V_174 -> V_66 . V_761 = V_174 -> V_430 . V_761 ;
} else {
V_174 -> V_430 . V_765 = 0 ;
F_19 ( & V_174 -> V_430 . V_766 ,
& V_174 -> V_309 -> V_312 ) ;
}
if ( ! F_268 ( V_74 ) ) {
V_174 -> V_319 = - V_440 ;
V_113 -> V_358 = NULL ;
goto V_767;
}
V_174 -> V_125 = V_170 ;
if ( F_81 ( V_174 -> V_14 ,
& V_174 -> V_430 . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) == 0 )
return;
V_767:
F_165 ( V_174 -> V_430 . V_761 ) ;
V_764:
F_165 ( V_174 -> V_430 . V_762 ) ;
V_346:
F_78 ( V_113 , & V_174 -> V_66 . V_177 ) ;
F_8 ( L_52 , V_34 , V_174 -> V_319 ) ;
}
static void F_488 ( struct V_112 * V_113 , void * V_172 )
{
struct V_760 * V_174 = V_172 ;
struct V_308 * V_309 = V_174 -> V_309 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_78 ( V_113 , & V_174 -> V_66 . V_177 ) )
return;
V_174 -> V_319 = V_113 -> V_117 ;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( F_105 ( F_14 ( V_174 -> V_326 -> V_4 ) ) ,
V_174 -> V_125 ) ;
if ( V_174 -> V_430 . V_768 ) {
V_174 -> V_738 . V_754 &= ~ ( V_769 | V_770 ) ;
if ( F_476 ( V_309 -> V_310 -> V_2 , & V_174 -> V_738 ) < 0 ) {
F_73 ( V_113 ) ;
break;
}
}
if ( V_174 -> V_430 . V_765 != 0 ) {
F_199 ( & V_309 -> V_745 , 0 ) ;
F_19 ( & V_309 -> V_312 , & V_174 -> V_66 . V_50 ) ;
F_146 ( V_394 , & V_309 -> V_395 ) ;
} else if ( ! F_161 ( V_309 , & V_174 -> V_66 . V_50 ) )
F_73 ( V_113 ) ;
break;
case - V_81 :
case - V_103 :
case - V_85 :
case - V_80 :
if ( V_174 -> V_430 . V_765 != 0 ) {
if ( ! F_159 ( & V_174 -> V_430 . V_296 ,
& V_309 -> V_310 -> V_296 ) )
F_73 ( V_113 ) ;
} else if ( ! F_159 ( & V_174 -> V_430 . V_766 ,
& V_309 -> V_312 ) )
F_73 ( V_113 ) ;
}
F_8 ( L_30 , V_34 , V_174 -> V_319 ) ;
}
static void F_489 ( void * V_172 )
{
struct V_760 * V_174 = V_172 ;
F_8 ( L_29 , V_34 ) ;
F_121 ( V_174 -> V_430 . V_761 ) ;
if ( V_174 -> V_334 != 0 ) {
struct V_112 * V_113 ;
V_113 = F_478 ( & V_174 -> V_738 , V_174 -> V_326 , V_174 -> V_309 ,
V_174 -> V_430 . V_762 ) ;
if ( ! F_56 ( V_113 ) )
F_490 ( V_113 ) ;
F_8 ( L_53 , V_34 ) ;
} else
F_121 ( V_174 -> V_430 . V_762 ) ;
F_238 ( V_174 -> V_309 ) ;
F_193 ( V_174 -> V_326 ) ;
F_117 ( V_174 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_491 ( struct V_13 * V_14 , struct V_308 * V_309 , int V_765 , int error )
{
switch ( error ) {
case - V_79 :
case - V_80 :
case - V_81 :
V_309 -> V_745 . V_236 &= ~ V_771 ;
if ( V_765 != 0 ||
F_38 ( V_394 , & V_309 -> V_395 ) != 0 )
F_28 ( V_14 , V_309 -> V_310 ) ;
break;
case - V_85 :
V_309 -> V_745 . V_236 &= ~ V_771 ;
F_29 ( V_14 -> V_55 ) ;
} ;
}
static int F_492 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_738 , int V_772 )
{
struct V_760 * V_174 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_773 ] ,
. V_51 = V_74 -> V_249 -> V_307 ,
} ;
struct V_180 V_341 = {
. V_182 = F_323 ( V_74 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_774 ,
. V_343 = V_344 ,
. V_236 = V_345 ,
} ;
int V_61 ;
F_8 ( L_29 , V_34 ) ;
V_174 = F_485 ( V_738 , F_315 ( V_738 -> V_758 ) ,
V_738 -> V_743 . V_744 . V_249 ,
V_772 == V_775 ? V_420 : V_328 ) ;
if ( V_174 == NULL )
return - V_142 ;
if ( F_493 ( V_734 ) )
V_174 -> V_430 . V_776 = 1 ;
F_51 ( & V_174 -> V_430 . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
V_179 . V_339 = & V_174 -> V_430 ;
V_179 . V_340 = & V_174 -> V_66 ;
V_341 . V_185 = V_174 ;
if ( V_772 > V_775 ) {
if ( V_772 == V_777 )
V_174 -> V_430 . V_778 = V_777 ;
F_52 ( & V_174 -> V_430 . V_176 ) ;
} else
V_174 -> V_430 . V_768 = 1 ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_61 = F_128 ( V_113 ) ;
if ( V_61 == 0 ) {
V_61 = V_174 -> V_319 ;
if ( V_61 )
F_491 ( V_174 -> V_14 , V_174 -> V_309 ,
V_174 -> V_430 . V_765 , V_61 ) ;
} else
V_174 -> V_334 = 1 ;
F_90 ( V_113 ) ;
F_8 ( L_30 , V_34 , V_61 ) ;
F_494 ( V_738 , V_74 , & V_174 -> V_66 . V_50 , V_734 , V_61 ) ;
return V_61 ;
}
static int F_495 ( struct V_73 * V_74 , struct V_735 * V_736 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = {
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_38 ( V_297 , & V_74 -> V_236 ) != 0 )
return 0 ;
V_8 = F_492 ( V_74 , V_759 , V_736 , V_777 ) ;
if ( V_8 != - V_99 )
break;
F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_496 ( struct V_73 * V_74 , struct V_735 * V_736 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = {
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
V_8 = F_470 ( V_74 , V_736 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_397 ) {
F_146 ( V_398 , & V_736 -> V_743 . V_744 . V_249 -> V_395 ) ;
return 0 ;
}
do {
if ( F_38 ( V_297 , & V_74 -> V_236 ) != 0 )
return 0 ;
V_8 = F_492 ( V_74 , V_759 , V_736 , V_779 ) ;
switch ( V_8 ) {
default:
goto V_160;
case - V_101 :
case - V_99 :
F_36 ( V_14 , V_8 , & V_71 ) ;
V_8 = 0 ;
}
} while ( V_71 . V_77 );
V_160:
return V_8 ;
}
static int F_497 ( struct V_73 * V_74 , struct V_735 * V_736 )
{
struct V_308 * V_309 ;
int V_331 ;
V_331 = F_470 ( V_74 , V_736 ) ;
if ( V_331 != 0 )
return V_331 ;
V_309 = V_736 -> V_743 . V_744 . V_249 ;
if ( F_38 ( V_394 , & V_309 -> V_395 ) ||
F_38 ( V_398 , & V_309 -> V_395 ) )
return 0 ;
V_331 = F_496 ( V_74 , V_736 ) ;
return V_331 ;
}
static int F_498 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_736 )
{
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_234 * V_235 = V_74 -> V_249 ;
unsigned char V_754 = V_736 -> V_754 ;
int V_331 ;
V_736 -> V_754 |= V_770 ;
V_331 = F_476 ( V_74 -> V_2 , V_736 ) ;
if ( V_331 < 0 )
goto V_160;
F_480 ( & V_235 -> V_756 ) ;
F_481 ( & V_189 -> V_757 ) ;
if ( F_38 ( V_297 , & V_74 -> V_236 ) ) {
V_736 -> V_754 = V_754 & ~ V_769 ;
V_331 = F_476 ( V_74 -> V_2 , V_736 ) ;
F_482 ( & V_189 -> V_757 ) ;
F_483 ( & V_235 -> V_756 ) ;
goto V_160;
}
F_482 ( & V_189 -> V_757 ) ;
F_483 ( & V_235 -> V_756 ) ;
V_331 = F_492 ( V_74 , V_734 , V_736 , V_775 ) ;
V_160:
V_736 -> V_754 = V_754 ;
return V_331 ;
}
static int F_499 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_736 )
{
struct V_70 V_71 = {
. V_74 = V_74 ,
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_498 ( V_74 , V_734 , V_736 ) ;
if ( V_8 == - V_333 )
V_8 = - V_118 ;
V_8 = F_36 ( F_105 ( V_74 -> V_2 ) ,
V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_500 ( struct V_73 * V_74 , int V_734 ,
struct V_735 * V_736 )
{
int V_331 = - V_68 ;
unsigned long V_60 = V_780 ;
while( ! F_501 () ) {
V_331 = F_499 ( V_74 , V_734 , V_736 ) ;
if ( ( V_331 != - V_118 ) || F_502 ( V_734 ) )
break;
F_503 ( V_60 ) ;
V_60 *= 2 ;
V_60 = F_417 (unsigned long, NFS4_LOCK_MAXTIMEOUT, timeout) ;
V_331 = - V_68 ;
}
return V_331 ;
}
static int
F_504 ( T_13 * V_464 , unsigned int V_282 , int V_236 , void * V_781 )
{
int V_61 ;
struct V_782 * V_783 = V_781 ;
struct V_784 * V_785 = V_464 -> V_786 ;
struct V_787 * V_788 = & V_783 -> V_789 ,
* V_790 = V_785 -> V_249 ;
if ( V_788 -> V_259 != V_790 -> V_259 ||
V_788 -> V_261 != V_790 -> V_261 ||
V_788 -> V_746 != V_790 -> V_746 )
return 0 ;
if ( F_505 ( F_114 ( V_785 -> V_2 ) , & V_783 -> V_791 ) )
return 0 ;
V_785 -> V_792 = true ;
V_464 -> V_786 = V_785 -> V_113 ;
V_61 = F_506 ( V_464 , V_282 , V_236 , V_781 ) ;
V_464 -> V_786 = V_785 ;
return V_61 ;
}
static int
F_507 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_736 )
{
int V_331 = - V_68 ;
unsigned long V_236 ;
struct V_308 * V_309 = V_736 -> V_743 . V_744 . V_249 ;
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
T_14 * V_793 = & V_72 -> V_794 ;
struct V_787 V_249 = { . V_259 = V_72 -> V_260 ,
. V_261 = V_309 -> V_745 . V_264 ,
. V_746 = V_14 -> V_746 } ;
struct V_784 V_785 = { . V_113 = V_67 ,
. V_2 = V_74 -> V_2 ,
. V_249 = & V_249 ,
. V_792 = false } ;
T_13 V_464 ;
if ( ! F_38 ( V_413 , & V_74 -> V_236 ) )
return F_500 ( V_74 , V_734 , V_736 ) ;
F_508 ( & V_464 ) ;
V_464 . V_786 = & V_785 ;
V_464 . V_795 = F_504 ;
F_509 ( V_793 , & V_464 ) ;
while( ! F_501 () ) {
V_331 = F_499 ( V_74 , V_734 , V_736 ) ;
if ( ( V_331 != - V_118 ) || F_502 ( V_734 ) )
break;
V_331 = - V_68 ;
F_510 ( & V_793 -> V_305 , V_236 ) ;
if ( V_785 . V_792 ) {
F_511 ( & V_793 -> V_305 , V_236 ) ;
continue;
}
F_512 ( V_796 ) ;
F_511 ( & V_793 -> V_305 , V_236 ) ;
F_503 ( V_797 ) ;
}
F_513 ( V_793 , & V_464 ) ;
return V_331 ;
}
static inline int
F_507 ( struct V_73 * V_74 , int V_734 , struct V_735 * V_736 )
{
return F_500 ( V_74 , V_734 , V_736 ) ;
}
static int
F_514 ( struct V_798 * V_799 , int V_734 , struct V_735 * V_736 )
{
struct V_325 * V_326 ;
struct V_73 * V_74 ;
int V_331 ;
V_326 = F_315 ( V_799 ) ;
V_74 = V_326 -> V_74 ;
if ( V_736 -> V_800 < 0 || V_736 -> V_801 < 0 )
return - V_27 ;
if ( F_515 ( V_734 ) ) {
if ( V_74 != NULL )
return F_471 ( V_74 , V_802 , V_736 ) ;
return 0 ;
}
if ( ! ( F_502 ( V_734 ) || F_493 ( V_734 ) ) )
return - V_27 ;
if ( V_736 -> V_747 == V_748 ) {
if ( V_74 != NULL )
return F_479 ( V_74 , V_734 , V_736 ) ;
return 0 ;
}
if ( V_74 == NULL )
return - V_803 ;
if ( ( V_736 -> V_754 & V_804 ) &&
! F_38 ( V_411 , & V_74 -> V_236 ) )
return - V_803 ;
switch ( V_736 -> V_747 ) {
case V_805 :
if ( ! ( V_799 -> V_806 & V_207 ) )
return - V_440 ;
break;
case V_807 :
if ( ! ( V_799 -> V_806 & V_208 ) )
return - V_440 ;
}
V_331 = F_470 ( V_74 , V_736 ) ;
if ( V_331 != 0 )
return V_331 ;
return F_507 ( V_74 , V_734 , V_736 ) ;
}
int F_516 ( struct V_735 * V_738 , struct V_73 * V_74 , const T_4 * V_50 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
int V_8 ;
V_8 = F_470 ( V_74 , V_738 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_492 ( V_74 , V_759 , V_738 , V_775 ) ;
return F_194 ( V_14 , V_74 , V_50 , V_8 ) ;
}
static void F_517 ( struct V_112 * V_113 , void * V_172 )
{
struct V_808 * V_174 = V_172 ;
struct V_13 * V_14 = V_174 -> V_14 ;
F_53 ( V_14 -> V_55 -> V_171 ,
& V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , V_113 ) ;
V_174 -> args . V_742 . V_259 = V_14 -> V_55 -> V_260 ;
V_174 -> V_125 = V_170 ;
}
static void F_518 ( struct V_112 * V_113 , void * V_172 )
{
struct V_808 * V_174 = V_172 ;
struct V_13 * V_14 = V_174 -> V_14 ;
F_63 ( V_113 , & V_174 -> V_66 . V_177 ) ;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_14 , V_174 -> V_125 ) ;
break;
case - V_86 :
case - V_80 :
F_29 ( V_14 -> V_55 ) ;
break;
case - V_88 :
case - V_99 :
if ( F_43 ( V_113 , V_14 ,
NULL , NULL ) == - V_118 )
F_73 ( V_113 ) ;
}
}
static void F_519 ( void * V_172 )
{
struct V_808 * V_174 = V_172 ;
F_520 ( V_174 -> V_14 , V_174 -> V_309 ) ;
F_117 ( V_172 ) ;
}
static void
F_521 ( struct V_13 * V_14 , struct V_308 * V_309 )
{
struct V_808 * V_174 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_809 ] ,
} ;
if ( V_14 -> V_55 -> V_56 -> V_356 != 0 )
return;
V_174 = F_305 ( sizeof( * V_174 ) , V_328 ) ;
if ( ! V_174 )
return;
V_174 -> V_309 = V_309 ;
V_174 -> V_14 = V_14 ;
V_174 -> args . V_742 . V_259 = V_14 -> V_55 -> V_260 ;
V_174 -> args . V_742 . V_261 = V_309 -> V_745 . V_264 ;
V_174 -> args . V_742 . V_746 = V_14 -> V_746 ;
V_179 . V_339 = & V_174 -> args ;
V_179 . V_340 = & V_174 -> V_66 ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 0 ) ;
F_412 ( V_14 -> V_108 , & V_179 , 0 , & V_810 , V_174 ) ;
}
static int F_522 ( const struct V_811 * V_812 ,
struct V_4 * V_813 , struct V_2 * V_2 ,
const char * V_781 , const void * V_654 ,
T_9 V_655 , int V_236 )
{
return F_434 ( V_2 , V_654 , V_655 ) ;
}
static int F_523 ( const struct V_811 * V_812 ,
struct V_4 * V_813 , struct V_2 * V_2 ,
const char * V_781 , void * V_654 , T_9 V_655 )
{
return F_428 ( V_2 , V_654 , V_655 ) ;
}
static bool F_524 ( struct V_4 * V_4 )
{
return F_415 ( F_105 ( F_14 ( V_4 ) ) ) ;
}
static int F_525 ( const struct V_811 * V_812 ,
struct V_4 * V_813 , struct V_2 * V_2 ,
const char * V_781 , const void * V_654 ,
T_9 V_655 , int V_236 )
{
if ( F_526 ( V_781 ) )
return F_442 ( V_2 , V_654 , V_655 ) ;
return - V_679 ;
}
static int F_527 ( const struct V_811 * V_812 ,
struct V_4 * V_813 , struct V_2 * V_2 ,
const char * V_781 , void * V_654 , T_9 V_655 )
{
if ( F_526 ( V_781 ) )
return F_437 ( V_2 , V_654 , V_655 ) ;
return - V_679 ;
}
static T_11
F_528 ( struct V_2 * V_2 , char * V_814 , T_9 V_815 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_529 ( V_2 , V_814 , V_815 ) ;
if ( V_815 && V_12 > V_815 )
return - V_666 ;
}
return V_12 ;
}
static T_11
F_528 ( struct V_2 * V_2 , char * V_814 , T_9 V_815 )
{
return 0 ;
}
static void F_307 ( struct V_442 * V_435 )
{
if ( ! ( ( ( V_435 -> V_322 & V_816 ) ||
( V_435 -> V_322 & V_817 ) ) &&
( V_435 -> V_322 & V_532 ) &&
( V_435 -> V_322 & V_818 ) ) )
return;
V_435 -> V_322 |= V_359 | V_548 |
V_549 | V_819 ;
V_435 -> V_282 = V_364 | V_551 | V_552 ;
V_435 -> V_553 = 2 ;
}
static int F_530 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_534 * V_265 ,
struct V_536 * V_820 ,
struct V_535 * V_535 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
T_1 V_266 [ 3 ] = {
[ 0 ] = V_821 | V_822 ,
} ;
struct V_823 args = {
. V_546 = F_114 ( V_3 ) ,
. V_265 = V_265 ,
. V_535 = V_535 ,
. V_266 = V_266 ,
} ;
struct V_824 V_66 = {
. V_820 = V_820 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_825 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
int V_331 ;
F_8 ( L_54 , V_34 ) ;
if ( F_105 ( V_3 ) -> V_15 [ 1 ] & V_826 )
V_266 [ 1 ] |= V_826 ;
else
V_266 [ 0 ] |= V_45 ;
F_101 ( & V_820 -> V_435 ) ;
V_820 -> V_14 = V_14 ;
V_820 -> V_827 = 0 ;
V_331 = F_91 ( V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
F_8 ( L_55 , V_34 , V_331 ) ;
return V_331 ;
}
int F_306 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_534 * V_265 ,
struct V_536 * V_820 ,
struct V_535 * V_535 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_530 ( V_108 , V_3 , V_265 ,
V_820 , V_535 ) ;
F_531 ( V_3 , V_265 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_532 ( struct V_2 * V_2 ,
struct V_536 * V_537 ,
struct V_535 * V_535 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
T_1 V_266 [ 2 ] = {
[ 0 ] = V_821 | V_822 ,
} ;
struct V_823 args = {
. V_259 = V_14 -> V_55 -> V_260 ,
. V_269 = F_114 ( V_2 ) ,
. V_535 = V_535 ,
. V_266 = V_266 ,
. V_828 = 1 ,
. V_829 = 1 ,
} ;
struct V_824 V_66 = {
. V_820 = V_537 ,
. V_828 = 1 ,
. V_829 = 1 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_825 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
unsigned long V_618 = V_170 ;
int V_331 ;
F_101 ( & V_537 -> V_435 ) ;
V_537 -> V_14 = V_14 ;
V_537 -> V_827 = 0 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_331 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
if ( V_331 )
return V_331 ;
F_49 ( V_14 , V_618 ) ;
return 0 ;
}
static int F_533 ( struct V_2 * V_2 ,
struct V_536 * V_537 ,
struct V_535 * V_535 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
T_1 V_266 [ 2 ] = {
[ 0 ] = V_821 | V_822 ,
} ;
struct V_823 args = {
. V_269 = F_114 ( V_2 ) ,
. V_535 = V_535 ,
. V_266 = V_266 ,
. V_828 = 1 ,
} ;
struct V_824 V_66 = {
. V_820 = V_537 ,
. V_828 = 1 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_825 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_331 ;
F_101 ( & V_537 -> V_435 ) ;
V_537 -> V_14 = V_14 ;
V_537 -> V_827 = 0 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_331 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
if ( V_331 == V_830 &&
V_66 . V_177 . V_164 & V_831 )
V_331 = - V_88 ;
return V_331 ;
}
int F_534 ( struct V_2 * V_2 ,
struct V_536 * V_537 ,
struct V_535 * V_535 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
const struct V_832 * V_54 =
V_72 -> V_56 -> V_833 ;
struct V_70 V_71 = { } ;
int V_331 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_533 . V_834 ,
( unsigned long long ) V_14 -> V_533 . V_835 ,
V_72 -> V_107 ) ;
F_535 ( F_114 ( V_2 ) , V_34 ) ;
do {
V_331 = V_54 -> V_836 ( V_2 , V_537 , V_535 , V_52 ) ;
if ( V_331 != - V_99 )
break;
F_36 ( V_14 , V_331 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_331 ;
}
static int F_536 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = F_105 ( V_2 ) -> V_55 ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_837 args = {
. V_269 = F_114 ( V_2 ) ,
. V_259 = V_72 -> V_260 ,
. V_829 = 1 ,
} ;
struct V_838 V_66 = {
. V_829 = 1 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_839 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
unsigned long V_618 = V_170 ;
int V_331 ;
V_66 . V_269 = F_537 () ;
if ( V_66 . V_269 == NULL )
return - V_142 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_331 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
F_538 ( V_66 . V_269 ) ;
if ( V_331 )
return V_331 ;
F_45 ( V_72 , V_618 ) ;
return 0 ;
}
static int F_539 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_837 args = {
. V_269 = F_114 ( V_2 ) ,
} ;
struct V_838 V_66 = {
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_839 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_331 ;
V_66 . V_269 = F_537 () ;
if ( V_66 . V_269 == NULL )
return - V_142 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_331 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
F_538 ( V_66 . V_269 ) ;
if ( V_331 == V_830 &&
V_66 . V_177 . V_164 & V_831 )
V_331 = - V_88 ;
return V_331 ;
}
int F_540 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
const struct V_832 * V_54 =
V_72 -> V_56 -> V_833 ;
struct V_70 V_71 = { } ;
int V_331 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_533 . V_834 ,
( unsigned long long ) V_14 -> V_533 . V_835 ,
V_72 -> V_107 ) ;
F_535 ( F_114 ( V_2 ) , V_34 ) ;
do {
V_331 = V_54 -> V_840 ( V_2 , V_52 ) ;
if ( V_331 != - V_99 )
break;
F_36 ( V_14 , V_331 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_331 ;
}
static int F_541 ( struct V_2 * V_3 , const struct V_534 * V_265 , struct V_841 * V_528 , bool V_842 )
{
int V_331 ;
struct V_843 args = {
. V_546 = F_114 ( V_3 ) ,
. V_265 = V_265 ,
} ;
struct V_844 V_66 = {
. V_528 = V_528 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_845 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
struct V_64 * V_65 = F_105 ( V_3 ) -> V_108 ;
struct V_51 * V_52 = NULL ;
if ( V_842 ) {
V_65 = F_105 ( V_3 ) -> V_55 -> V_120 ;
V_52 = F_542 ( F_105 ( V_3 ) -> V_55 ) ;
V_179 . V_51 = V_52 ;
}
F_8 ( L_57 , V_265 -> V_265 ) ;
F_283 ( F_105 ( V_3 ) -> V_55 ,
V_846 , & V_65 , & V_179 ) ;
V_331 = F_91 ( V_65 , F_105 ( V_3 ) , & V_179 , & args . V_176 ,
& V_66 . V_177 , 0 ) ;
F_8 ( L_58 , V_331 ) ;
if ( V_52 )
F_236 ( V_52 ) ;
return V_331 ;
}
int F_543 ( struct V_2 * V_3 , const struct V_534 * V_265 ,
struct V_841 * V_528 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( F_105 ( V_3 ) -> V_55 ) )
V_8 = F_541 ( V_3 , V_265 , V_528 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_541 ( V_3 , V_265 , V_528 , false ) ;
F_544 ( V_3 , V_265 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_545 ( T_1 V_236 )
{
if ( V_236 & ~ V_847 )
goto V_848;
if ( ( V_236 & V_849 ) &&
( V_236 & V_850 ) )
goto V_848;
if ( ! ( V_236 & ( V_851 ) ) )
goto V_848;
return V_391 ;
V_848:
return - V_852 ;
}
static bool
F_546 ( struct V_853 * V_854 ,
struct V_853 * V_855 )
{
if ( V_854 -> V_856 == V_855 -> V_856 &&
memcmp ( V_854 -> V_857 , V_855 -> V_857 , V_854 -> V_856 ) == 0 )
return true ;
return false ;
}
static void
F_547 ( struct V_112 * V_113 , void * V_172 )
{
}
static
int F_548 ( struct V_64 * V_65 ,
struct V_858 * V_859 ,
struct V_55 * V_72 ,
struct V_51 * V_52 )
{
int V_331 ;
struct V_860 args = {
. V_108 = V_72 ,
. V_3 = V_861 ,
} ;
struct V_862 V_66 ;
struct V_178 V_179 = {
. V_336 =
& V_337 [ V_863 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = V_65 ,
. V_858 = V_859 ,
. V_183 = & V_864 ,
. V_178 = & V_179 ,
. V_236 = V_652 ,
} ;
struct V_112 * V_113 ;
F_8 ( L_11 , V_34 ) ;
F_549 ( & args . V_865 , & V_72 -> V_97 -> V_866 ) ;
if ( ! ( V_72 -> V_97 -> V_236 & V_867 ) )
args . V_3 = V_868 ;
if ( V_859 != F_227 ( V_65 -> V_869 ) )
args . V_3 = V_868 ;
V_113 = F_88 ( & V_341 ) ;
if ( ! F_56 ( V_113 ) ) {
V_331 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
} else
V_331 = F_89 ( V_113 ) ;
F_550 ( V_72 , V_331 ) ;
if ( V_331 == 0 ) {
if ( memcmp ( V_66 . V_865 . V_174 ,
V_72 -> V_97 -> V_866 . V_174 , V_870 ) ) {
F_8 ( L_59 , V_34 ) ;
V_331 = - V_35 ;
goto V_160;
}
if ( ( V_66 . V_3 & args . V_3 ) != V_66 . V_3 || V_66 . V_3 == 0 ) {
F_8 ( L_60 ,
V_34 ) ;
V_331 = - V_35 ;
goto V_160;
}
if ( V_66 . V_871 != args . V_871 ) {
F_8 ( L_61 ,
V_34 ) ;
V_331 = - V_35 ;
goto V_160;
}
}
V_160:
F_8 ( L_62 , V_34 , V_331 ) ;
return V_331 ;
}
static int
F_551 ( struct V_64 * V_65 ,
struct V_858 * V_859 ,
void * V_172 )
{
struct V_872 * V_41 = V_172 ;
return F_548 ( V_65 , V_859 , V_41 -> V_72 , V_41 -> V_52 ) ;
}
int F_552 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_872 V_174 = {
. V_72 = V_72 ,
. V_52 = V_52 ,
} ;
return F_553 ( V_72 -> V_120 ,
F_551 , & V_174 ) ;
}
static int F_554 ( struct V_55 * V_72 ,
struct V_873 * V_235 )
{
static const T_1 V_874 [ V_875 ] = {
[ 1 ] = 1 << ( V_876 - 32 ) |
1 << ( V_877 - 32 ) |
1 << ( V_878 - 32 ) |
1 << ( V_879 - 32 ) |
1 << ( V_880 - 32 )
} ;
unsigned int V_525 ;
if ( V_235 -> V_881 == V_882 ) {
F_555 ( V_883 , L_63 ) ;
for ( V_525 = 0 ; V_525 <= V_884 ; V_525 ++ ) {
if ( F_38 ( V_525 , V_235 -> V_885 . V_273 . V_886 ) )
F_555 ( V_883 , L_64 , V_525 ) ;
if ( F_38 ( V_525 , V_235 -> V_887 . V_273 . V_886 ) )
F_555 ( V_883 , L_65 , V_525 ) ;
}
for ( V_525 = 0 ; V_525 < V_875 ; V_525 ++ ) {
if ( V_235 -> V_885 . V_273 . V_888 [ V_525 ] & ~ V_874 [ V_525 ] ) {
F_555 ( V_883 , L_66 ) ;
return - V_27 ;
}
}
if ( F_38 ( V_876 , V_235 -> V_885 . V_273 . V_886 ) &&
F_38 ( V_878 , V_235 -> V_885 . V_273 . V_886 ) &&
F_38 ( V_879 , V_235 -> V_885 . V_273 . V_886 ) &&
F_38 ( V_880 , V_235 -> V_885 . V_273 . V_886 ) ) {
F_555 ( V_883 , L_67 ) ;
F_555 ( V_883 , L_68 ) ;
F_146 ( V_889 , & V_72 -> V_890 ) ;
} else {
F_555 ( V_883 , L_66 ) ;
return - V_27 ;
}
if ( F_38 ( V_891 , V_235 -> V_887 . V_273 . V_886 ) &&
F_38 ( V_892 , V_235 -> V_887 . V_273 . V_886 ) &&
F_38 ( V_893 , V_235 -> V_887 . V_273 . V_886 ) &&
F_38 ( V_894 , V_235 -> V_887 . V_273 . V_886 ) ) {
F_555 ( V_883 , L_69 ) ;
F_146 ( V_466 , & V_72 -> V_890 ) ;
}
if ( F_38 ( V_895 , V_235 -> V_887 . V_273 . V_886 ) ) {
F_555 ( V_883 , L_70 ) ;
F_146 ( V_896 ,
& V_72 -> V_890 ) ;
}
if ( F_38 ( V_897 , V_235 -> V_887 . V_273 . V_886 ) &&
F_38 ( V_898 , V_235 -> V_887 . V_273 . V_886 ) ) {
F_555 ( V_883 , L_71 ) ;
F_146 ( V_846 , & V_72 -> V_890 ) ;
}
if ( F_38 ( V_899 , V_235 -> V_887 . V_273 . V_886 ) &&
F_38 ( V_900 , V_235 -> V_887 . V_273 . V_886 ) ) {
F_555 ( V_883 , L_72 ) ;
F_146 ( V_901 , & V_72 -> V_890 ) ;
}
if ( F_38 ( V_902 , V_235 -> V_887 . V_273 . V_886 ) ) {
F_555 ( V_883 , L_73 ) ;
F_146 ( V_903 , & V_72 -> V_890 ) ;
}
if ( F_38 ( V_904 , V_235 -> V_887 . V_273 . V_886 ) ) {
F_555 ( V_883 , L_74 ) ;
F_146 ( V_905 , & V_72 -> V_890 ) ;
}
}
return 0 ;
}
static void F_556 ( struct V_112 * V_113 , void * V_174 )
{
struct V_906 * V_907 =
(struct V_906 * ) V_174 ;
struct V_55 * V_72 = V_907 -> args . V_108 ;
int V_331 = V_113 -> V_117 ;
F_557 ( V_72 , V_331 ) ;
if ( V_331 == 0 )
V_331 = F_545 ( V_907 -> V_66 . V_236 ) ;
if ( V_907 -> V_859 && V_331 == 0 ) {
V_331 = F_558 ( V_72 , & V_907 -> V_66 ,
V_907 -> V_859 ) ;
goto V_160;
}
if ( V_331 == 0 )
V_331 = F_554 ( V_72 , & V_907 -> V_66 . V_908 ) ;
if ( V_331 == 0 ) {
V_72 -> V_260 = V_907 -> V_66 . V_259 ;
V_72 -> V_909 = V_907 -> V_66 . V_236 ;
if ( ! ( V_907 -> V_66 . V_236 & V_910 ) ) {
F_148 ( V_911 ,
& V_72 -> V_97 -> V_912 ) ;
V_72 -> V_913 = V_907 -> V_66 . V_226 ;
}
F_117 ( V_72 -> V_914 ) ;
V_72 -> V_914 = V_907 -> V_66 . V_915 ;
V_907 -> V_66 . V_915 = NULL ;
F_117 ( V_72 -> V_916 ) ;
V_72 -> V_916 = V_907 -> V_66 . V_917 ;
V_907 -> V_66 . V_917 = NULL ;
if ( V_72 -> V_918 != NULL &&
! F_546 ( V_72 -> V_918 ,
V_907 -> V_66 . V_857 ) ) {
F_8 ( L_75 ,
V_34 ) ;
F_146 ( V_919 , & V_72 -> V_116 ) ;
F_117 ( V_72 -> V_918 ) ;
V_72 -> V_918 = NULL ;
}
if ( V_72 -> V_918 == NULL ) {
V_72 -> V_918 = V_907 -> V_66 . V_857 ;
V_907 -> V_66 . V_857 = NULL ;
}
memcpy ( V_72 -> V_920 . V_174 , V_907 -> args . V_37 -> V_174 ,
sizeof( V_72 -> V_920 . V_174 ) ) ;
}
V_160:
V_907 -> V_319 = V_331 ;
return;
}
static void F_559 ( void * V_174 )
{
struct V_906 * V_907 =
(struct V_906 * ) V_174 ;
F_406 ( V_907 -> args . V_108 ) ;
if ( V_907 -> V_859 ) {
F_560 ( V_907 -> V_859 ) ;
F_561 ( V_907 -> args . V_108 -> V_120 ) ;
}
F_117 ( V_907 -> V_66 . V_917 ) ;
F_117 ( V_907 -> V_66 . V_857 ) ;
F_117 ( V_907 -> V_66 . V_915 ) ;
F_117 ( V_907 ) ;
}
static int F_562 ( struct V_55 * V_72 , struct V_51 * V_52 ,
T_1 V_921 , struct V_858 * V_859 )
{
T_12 V_37 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_922 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = V_72 -> V_120 ,
. V_183 = & V_923 ,
. V_178 = & V_179 ,
. V_236 = V_345 | V_652 ,
} ;
struct V_906 * V_172 ;
struct V_112 * V_113 ;
int V_331 = - V_35 ;
if ( ! F_411 ( & V_72 -> V_646 ) )
goto V_160;
V_331 = - V_142 ;
V_172 = F_106 ( sizeof( * V_172 ) , V_328 ) ;
if ( ! V_172 )
goto V_160;
if ( ! V_859 )
F_444 ( V_72 , & V_37 ) ;
V_331 = F_451 ( V_72 ) ;
if ( V_331 )
goto V_924;
F_8 ( L_76 ,
V_72 -> V_120 -> V_121 -> V_725 -> V_726 ,
V_72 -> V_696 ) ;
V_172 -> V_66 . V_915 = F_106 ( sizeof( struct V_925 ) ,
V_328 ) ;
V_331 = - V_142 ;
if ( F_390 ( V_172 -> V_66 . V_915 == NULL ) )
goto V_924;
V_172 -> V_66 . V_857 = F_106 ( sizeof( struct V_853 ) ,
V_328 ) ;
if ( F_390 ( V_172 -> V_66 . V_857 == NULL ) )
goto V_926;
V_172 -> V_66 . V_917 = F_106 ( sizeof( struct V_927 ) , V_328 ) ;
if ( F_390 ( V_172 -> V_66 . V_917 == NULL ) )
goto V_928;
switch ( V_921 ) {
case V_929 :
V_172 -> args . V_908 . V_881 = V_929 ;
break;
case V_882 :
V_172 -> args . V_908 = V_930 ;
break;
default:
F_131 ( 1 ) ;
V_331 = - V_27 ;
goto V_931;
}
if ( V_859 ) {
V_172 -> V_859 = V_859 ;
V_341 . V_858 = V_859 ;
V_341 . V_236 =
V_932 | V_933 | V_345 ;
V_172 -> args . V_37 = & V_72 -> V_920 ;
} else {
V_172 -> args . V_37 = & V_37 ;
}
V_172 -> args . V_108 = V_72 ;
#ifdef F_563
V_172 -> args . V_236 = V_934 |
V_935 |
V_936 ,
#else
V_172 -> args . V_236 = V_934 |
V_935 ,
#endif
V_179 . V_339 = & V_172 -> args ;
V_179 . V_340 = & V_172 -> V_66 ;
V_341 . V_185 = V_172 ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) ) {
V_331 = F_89 ( V_113 ) ;
goto V_931;
}
if ( ! V_859 ) {
V_331 = F_129 ( V_113 ) ;
if ( ! V_331 )
V_331 = V_172 -> V_319 ;
} else
V_331 = V_172 -> V_319 ;
F_90 ( V_113 ) ;
V_160:
if ( V_72 -> V_916 != NULL )
F_8 ( L_77
L_78 ,
V_72 -> V_916 -> V_937 , V_72 -> V_916 -> V_265 ,
V_72 -> V_916 -> V_938 . V_939 ,
V_72 -> V_916 -> V_938 . V_940 ) ;
F_8 ( L_79 , V_331 ) ;
return V_331 ;
V_931:
F_117 ( V_172 -> V_66 . V_917 ) ;
V_928:
F_117 ( V_172 -> V_66 . V_857 ) ;
V_926:
F_117 ( V_172 -> V_66 . V_915 ) ;
V_924:
F_117 ( V_172 ) ;
goto V_160;
}
int F_564 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
T_5 V_941 = V_72 -> V_120 -> V_121 -> V_122 ;
int V_331 ;
if ( V_941 == V_123 ||
V_941 == V_124 ) {
V_331 = F_562 ( V_72 , V_52 , V_882 , NULL ) ;
if ( ! V_331 )
return 0 ;
}
return F_562 ( V_72 , V_52 , V_929 , NULL ) ;
}
int F_565 ( struct V_64 * V_65 , struct V_858 * V_859 ,
void * V_174 )
{
struct V_942 * V_943 = (struct V_942 * ) V_174 ;
T_1 V_921 ;
F_8 ( L_80 , V_34 ,
V_859 -> V_944 [ V_698 ] ) ;
V_921 = ( V_943 -> V_72 -> V_890 == 0 ? V_929 : V_882 ) ;
return F_562 ( V_943 -> V_72 , V_943 -> V_52 , V_921 , V_859 ) ;
}
static int F_566 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_336 = & V_337 [ V_945 ] ,
. V_339 = V_72 ,
. V_51 = V_52 ,
} ;
int V_331 ;
V_331 = F_414 ( V_72 -> V_120 , & V_179 , V_652 ) ;
F_567 ( V_72 , V_331 ) ;
if ( V_331 )
F_8 ( L_81
L_82 , V_331 , V_72 -> V_107 ) ;
return V_331 ;
}
static int F_568 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
unsigned int V_946 ;
int V_61 ;
for ( V_946 = V_947 ; V_946 != 0 ; V_946 -- ) {
V_61 = F_566 ( V_72 , V_52 ) ;
switch ( V_61 ) {
case - V_99 :
case - V_948 :
F_195 ( 1 ) ;
break;
default:
return V_61 ;
}
}
return 0 ;
}
int F_569 ( struct V_55 * V_72 )
{
struct V_51 * V_52 ;
int V_61 = 0 ;
if ( V_72 -> V_56 -> V_356 < 1 )
goto V_160;
if ( V_72 -> V_909 == 0 )
goto V_160;
if ( V_72 -> V_949 )
goto V_160;
V_52 = F_542 ( V_72 ) ;
V_61 = F_568 ( V_72 , V_52 ) ;
if ( V_52 )
F_236 ( V_52 ) ;
switch ( V_61 ) {
case 0 :
case - V_86 :
V_72 -> V_909 = 0 ;
}
V_160:
return V_61 ;
}
static void F_570 ( struct V_112 * V_113 ,
void * V_172 )
{
struct V_950 * V_174 =
(struct V_950 * ) V_172 ;
F_8 ( L_11 , V_34 ) ;
F_79 ( V_174 -> V_72 -> V_97 ,
& V_174 -> args -> V_951 ,
& V_174 -> V_66 -> V_952 ,
V_113 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_571 ( struct V_112 * V_113 , void * V_172 )
{
struct V_950 * V_174 =
(struct V_950 * ) V_172 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_75 ( V_113 , & V_174 -> V_66 -> V_952 ) )
return;
switch ( V_113 -> V_117 ) {
case - V_99 :
case - V_101 :
F_8 ( L_84 , V_34 , V_113 -> V_117 ) ;
F_40 ( V_113 , V_63 ) ;
V_113 -> V_117 = 0 ;
case - V_102 :
F_73 ( V_113 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
int F_572 ( struct V_55 * V_72 , struct V_511 * V_614 )
{
struct V_112 * V_113 ;
struct V_953 args ;
struct V_954 V_66 = {
. V_955 = V_614 ,
} ;
struct V_950 V_174 = {
. args = & args ,
. V_66 = & V_66 ,
. V_72 = V_72 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_956 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
struct V_180 V_181 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_957 ,
. V_185 = & V_174 ,
. V_236 = V_652 ,
} ;
int V_331 ;
F_51 ( & args . V_951 , & V_66 . V_952 , 0 ) ;
F_52 ( & args . V_951 ) ;
F_8 ( L_11 , V_34 ) ;
V_113 = F_88 ( & V_181 ) ;
if ( F_56 ( V_113 ) )
V_331 = F_89 ( V_113 ) ;
else {
V_331 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
}
F_8 ( L_85 , V_34 , V_331 ) ;
return V_331 ;
}
static void F_573 ( struct V_958 * args ,
struct V_64 * V_65 )
{
unsigned int V_959 , V_960 ;
unsigned int V_961 = F_574 ( V_65 ) ;
V_959 = V_962 + V_963 ;
V_960 = V_962 + V_964 ;
args -> V_965 . V_959 = V_959 ;
args -> V_965 . V_960 = V_960 ;
args -> V_965 . V_966 = V_967 ;
args -> V_965 . V_968 = V_969 ;
F_8 ( L_86
L_87 ,
V_34 ,
args -> V_965 . V_959 , args -> V_965 . V_960 ,
args -> V_965 . V_966 , args -> V_965 . V_968 ) ;
args -> V_970 . V_959 = V_961 ;
args -> V_970 . V_960 = V_961 ;
args -> V_970 . V_971 = 0 ;
args -> V_970 . V_966 = V_972 ;
args -> V_970 . V_968 = F_417 (unsigned short, max_session_cb_slots, 1 ) ;
F_8 ( L_88
L_89 ,
V_34 ,
args -> V_970 . V_959 , args -> V_970 . V_960 ,
args -> V_970 . V_971 , args -> V_970 . V_966 ,
args -> V_970 . V_968 ) ;
}
static int F_575 ( struct V_958 * args ,
struct V_973 * V_66 )
{
struct V_974 * V_975 = & args -> V_965 ;
struct V_974 * V_976 = & V_66 -> V_965 ;
if ( V_976 -> V_960 > V_975 -> V_960 )
return - V_27 ;
if ( V_976 -> V_966 < V_975 -> V_966 )
return - V_27 ;
if ( V_976 -> V_968 == 0 )
return - V_27 ;
if ( V_976 -> V_968 > V_977 )
V_976 -> V_968 = V_977 ;
return 0 ;
}
static int F_576 ( struct V_958 * args ,
struct V_973 * V_66 )
{
struct V_974 * V_975 = & args -> V_970 ;
struct V_974 * V_976 = & V_66 -> V_970 ;
if ( ! ( V_66 -> V_236 & V_867 ) )
goto V_160;
if ( V_976 -> V_959 > V_975 -> V_959 )
return - V_27 ;
if ( V_976 -> V_960 < V_975 -> V_960 )
return - V_27 ;
if ( V_976 -> V_971 > V_975 -> V_971 )
return - V_27 ;
if ( V_976 -> V_966 > V_975 -> V_966 )
return - V_27 ;
if ( V_976 -> V_968 > V_975 -> V_968 )
return - V_27 ;
V_160:
return 0 ;
}
static int F_577 ( struct V_958 * args ,
struct V_973 * V_66 )
{
int V_61 ;
V_61 = F_575 ( args , V_66 ) ;
if ( V_61 )
return V_61 ;
return F_576 ( args , V_66 ) ;
}
static void F_578 ( struct V_148 * V_149 ,
struct V_973 * V_66 )
{
F_549 ( & V_149 -> V_866 , & V_66 -> V_865 ) ;
V_149 -> V_72 -> V_909 |= V_910 ;
F_146 ( V_911 , & V_149 -> V_912 ) ;
V_149 -> V_236 = V_66 -> V_236 ;
memcpy ( & V_149 -> V_965 , & V_66 -> V_965 , sizeof( V_149 -> V_965 ) ) ;
if ( V_66 -> V_236 & V_867 )
memcpy ( & V_149 -> V_970 , & V_66 -> V_970 ,
sizeof( V_149 -> V_970 ) ) ;
}
static int F_579 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_148 * V_149 = V_72 -> V_97 ;
struct V_958 args = {
. V_108 = V_72 ,
. V_259 = V_72 -> V_260 ,
. V_226 = V_72 -> V_913 ,
. V_978 = V_979 ,
} ;
struct V_973 V_66 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_980 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_331 ;
F_573 ( & args , V_72 -> V_120 ) ;
args . V_236 = ( V_981 | V_867 ) ;
V_331 = F_414 ( V_149 -> V_72 -> V_120 , & V_179 , V_652 ) ;
F_580 ( V_72 , V_331 ) ;
switch ( V_331 ) {
case - V_86 :
case - V_99 :
case - V_982 :
case - V_29 :
case - V_118 :
goto V_160;
} ;
V_72 -> V_913 ++ ;
if ( ! V_331 ) {
V_331 = F_577 ( & args , & V_66 ) ;
if ( V_331 )
goto V_160;
F_578 ( V_149 , & V_66 ) ;
}
V_160:
return V_331 ;
}
int F_581 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
int V_331 ;
unsigned * V_983 ;
struct V_148 * V_149 = V_72 -> V_97 ;
F_8 ( L_90 , V_34 , V_72 , V_149 ) ;
V_331 = F_579 ( V_72 , V_52 ) ;
if ( V_331 )
goto V_160;
V_331 = F_582 ( V_149 ) ;
F_8 ( L_91 , V_331 ) ;
if ( V_331 )
goto V_160;
V_983 = ( unsigned * ) & V_149 -> V_866 . V_174 [ 0 ] ;
F_8 ( L_92 , V_34 ,
V_72 -> V_913 , V_983 [ 0 ] , V_983 [ 1 ] , V_983 [ 2 ] , V_983 [ 3 ] ) ;
V_160:
F_8 ( L_83 , V_34 ) ;
return V_331 ;
}
int F_583 ( struct V_148 * V_149 ,
struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_336 = & V_337 [ V_984 ] ,
. V_339 = V_149 ,
. V_51 = V_52 ,
} ;
int V_331 = 0 ;
F_8 ( L_93 ) ;
if ( ! F_139 ( V_911 , & V_149 -> V_912 ) )
return 0 ;
V_331 = F_414 ( V_149 -> V_72 -> V_120 , & V_179 , V_652 ) ;
F_584 ( V_149 -> V_72 , V_331 ) ;
if ( V_331 )
F_8 ( L_94
L_95 , V_331 ) ;
F_8 ( L_96 ) ;
return V_331 ;
}
static void F_585 ( void * V_174 )
{
struct V_985 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
if ( F_404 ( & V_72 -> V_646 ) > 1 )
F_405 ( V_72 ) ;
F_406 ( V_72 ) ;
F_117 ( V_172 ) ;
}
static int F_586 ( struct V_112 * V_113 , struct V_55 * V_72 )
{
switch( V_113 -> V_117 ) {
case - V_99 :
F_40 ( V_113 , V_62 ) ;
return - V_118 ;
default:
F_29 ( V_72 ) ;
}
return 0 ;
}
static void F_587 ( struct V_112 * V_113 , void * V_174 )
{
struct V_985 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
if ( ! F_75 ( V_113 , V_113 -> V_350 . V_340 ) )
return;
F_588 ( V_72 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
F_8 ( L_97 , V_34 , V_113 -> V_117 ) ;
if ( F_404 ( & V_72 -> V_646 ) == 1 )
goto V_160;
if ( F_586 ( V_113 , V_72 ) == - V_118 ) {
F_73 ( V_113 ) ;
return;
}
}
F_8 ( L_98 , V_34 , V_113 -> V_350 . V_51 ) ;
V_160:
F_8 ( L_83 , V_34 ) ;
}
static void F_589 ( struct V_112 * V_113 , void * V_174 )
{
struct V_985 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
struct V_128 * args ;
struct V_129 * V_66 ;
args = V_113 -> V_350 . V_339 ;
V_66 = V_113 -> V_350 . V_340 ;
F_79 ( V_72 -> V_97 , args , V_66 , V_113 ) ;
}
static struct V_112 * F_590 ( struct V_55 * V_72 ,
struct V_51 * V_52 ,
bool V_986 )
{
struct V_985 * V_172 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_987 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_988 ,
. V_236 = V_345 | V_652 ,
} ;
if ( ! F_411 ( & V_72 -> V_646 ) )
return F_57 ( - V_35 ) ;
V_172 = F_106 ( sizeof( * V_172 ) , V_328 ) ;
if ( V_172 == NULL ) {
F_406 ( V_72 ) ;
return F_57 ( - V_142 ) ;
}
F_51 ( & V_172 -> args , & V_172 -> V_66 , 0 ) ;
if ( V_986 )
F_52 ( & V_172 -> args ) ;
V_179 . V_339 = & V_172 -> args ;
V_179 . V_340 = & V_172 -> V_66 ;
V_172 -> V_72 = V_72 ;
V_341 . V_185 = V_172 ;
return F_88 ( & V_341 ) ;
}
static int F_591 ( struct V_55 * V_72 , struct V_51 * V_52 , unsigned V_650 )
{
struct V_112 * V_113 ;
int V_61 = 0 ;
if ( ( V_650 & V_989 ) == 0 )
return - V_118 ;
V_113 = F_590 ( V_72 , V_52 , false ) ;
if ( F_56 ( V_113 ) )
V_61 = F_89 ( V_113 ) ;
else
F_490 ( V_113 ) ;
F_8 ( L_16 , V_34 , V_61 ) ;
return V_61 ;
}
static int F_592 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_112 * V_113 ;
int V_61 ;
V_113 = F_590 ( V_72 , V_52 , true ) ;
if ( F_56 ( V_113 ) ) {
V_61 = F_89 ( V_113 ) ;
goto V_160;
}
V_61 = F_129 ( V_113 ) ;
if ( ! V_61 )
V_61 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
V_160:
F_8 ( L_16 , V_34 , V_61 ) ;
return V_61 ;
}
static void F_593 ( struct V_112 * V_113 , void * V_174 )
{
struct V_990 * V_172 = V_174 ;
F_79 ( V_172 -> V_72 -> V_97 ,
& V_172 -> V_430 . V_176 ,
& V_172 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_594 ( struct V_112 * V_113 , struct V_55 * V_72 )
{
switch( V_113 -> V_117 ) {
case 0 :
case - V_991 :
case - V_23 :
break;
case - V_99 :
F_40 ( V_113 , V_62 ) ;
case - V_102 :
return - V_118 ;
default:
F_29 ( V_72 ) ;
}
return 0 ;
}
static void F_595 ( struct V_112 * V_113 , void * V_174 )
{
struct V_990 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
struct V_129 * V_66 = & V_172 -> V_66 . V_177 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_75 ( V_113 , V_66 ) )
return;
F_596 ( V_72 , V_113 -> V_117 ) ;
if ( F_594 ( V_113 , V_72 ) == - V_118 ) {
F_73 ( V_113 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_597 ( void * V_174 )
{
struct V_990 * V_172 = V_174 ;
F_117 ( V_172 ) ;
}
static int F_598 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_990 * V_172 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_992 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_993 ,
. V_236 = V_345 ,
} ;
int V_331 = - V_142 ;
F_8 ( L_11 , V_34 ) ;
V_172 = F_106 ( sizeof( * V_172 ) , V_328 ) ;
if ( V_172 == NULL )
goto V_160;
V_172 -> V_72 = V_72 ;
V_172 -> V_430 . V_994 = 0 ;
F_51 ( & V_172 -> V_430 . V_176 , & V_172 -> V_66 . V_177 , 0 ) ;
F_52 ( & V_172 -> V_430 . V_176 ) ;
V_179 . V_339 = & V_172 -> V_430 ;
V_179 . V_340 = & V_172 -> V_66 ;
V_341 . V_185 = V_172 ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) ) {
V_331 = F_89 ( V_113 ) ;
goto V_160;
}
V_331 = F_128 ( V_113 ) ;
if ( V_331 == 0 )
V_331 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
return 0 ;
V_160:
F_8 ( L_16 , V_34 , V_331 ) ;
return V_331 ;
}
static void
F_599 ( struct V_112 * V_113 , void * V_172 )
{
struct V_995 * V_996 = V_172 ;
struct V_13 * V_14 = F_105 ( V_996 -> args . V_2 ) ;
struct V_148 * V_149 = F_82 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_79 ( V_149 , & V_996 -> args . V_176 ,
& V_996 -> V_66 . V_177 , V_113 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_600 ( struct V_112 * V_113 , void * V_172 )
{
struct V_995 * V_996 = V_172 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_113 , & V_996 -> V_66 . V_177 ) ;
F_8 ( L_83 , V_34 ) ;
}
static int
F_601 ( struct V_112 * V_113 ,
struct V_995 * V_996 , struct V_70 * V_71 )
{
struct V_2 * V_2 = V_996 -> args . V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_997 * V_998 ;
int V_999 = V_113 -> V_117 ;
int V_8 , V_331 = 0 ;
F_602 ( V_1000 ) ;
F_8 ( L_99 , V_34 , - V_113 -> V_117 ) ;
switch ( V_999 ) {
case 0 :
goto V_160;
case - V_1001 :
V_331 = - V_1002 ;
goto V_160;
case - V_1003 :
V_331 = - V_1004 ;
goto V_160;
case - V_19 :
if ( V_996 -> args . V_1005 == 0 ) {
V_331 = - V_1004 ;
goto V_160;
}
V_331 = - V_33 ;
break;
case - V_20 :
V_331 = - V_1006 ;
break;
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
V_71 -> V_60 = 0 ;
F_46 ( & V_2 -> V_190 ) ;
V_998 = F_93 ( V_2 ) -> V_1007 ;
if ( ! V_998 || F_38 ( V_1008 , & V_998 -> V_1009 ) ||
F_143 ( & V_996 -> args . V_50 ,
& V_996 -> args . V_326 -> V_74 -> V_50 ) ) {
F_48 ( & V_2 -> V_190 ) ;
V_71 -> V_74 = V_996 -> args . V_326 -> V_74 ;
V_71 -> V_50 = & V_996 -> args . V_50 ;
break;
}
F_603 ( V_998 , & V_1000 ) ;
F_48 ( & V_2 -> V_190 ) ;
F_604 ( & V_1000 ) ;
V_331 = - V_118 ;
goto V_160;
}
F_77 ( & V_996 -> V_66 . V_177 ) ;
V_8 = F_36 ( V_14 , V_999 , V_71 ) ;
if ( ! V_331 ) {
if ( V_71 -> V_77 )
V_331 = - V_118 ;
else
V_331 = V_8 ;
}
V_160:
F_8 ( L_83 , V_34 ) ;
return V_331 ;
}
static T_9 F_605 ( struct V_13 * V_14 )
{
T_1 V_960 = V_14 -> V_55 -> V_97 -> V_965 . V_960 ;
return F_606 ( 0 , V_960 ) ;
}
static void F_607 ( struct V_535 * * V_42 , T_9 V_1010 )
{
int V_525 ;
if ( ! V_42 )
return;
for ( V_525 = 0 ; V_525 < V_1010 ; V_525 ++ ) {
if ( ! V_42 [ V_525 ] )
break;
F_308 ( V_42 [ V_525 ] ) ;
}
F_117 ( V_42 ) ;
}
static struct V_535 * * F_608 ( T_9 V_1010 , T_7 V_1011 )
{
struct V_535 * * V_42 ;
int V_525 ;
V_42 = F_609 ( V_1010 , sizeof( struct V_535 * ) , V_1011 ) ;
if ( ! V_42 ) {
F_8 ( L_100 , V_34 , V_1010 ) ;
return NULL ;
}
for ( V_525 = 0 ; V_525 < V_1010 ; V_525 ++ ) {
V_42 [ V_525 ] = F_304 ( V_1011 ) ;
if ( ! V_42 [ V_525 ] ) {
F_8 ( L_101 , V_34 ) ;
F_607 ( V_42 , V_1010 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_610 ( void * V_172 )
{
struct V_995 * V_996 = V_172 ;
struct V_2 * V_2 = V_996 -> args . V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
T_9 V_1012 = F_605 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_607 ( V_996 -> args . V_1007 . V_42 , V_1012 ) ;
F_611 ( F_93 ( V_2 ) -> V_1007 ) ;
F_193 ( V_996 -> args . V_326 ) ;
F_117 ( V_172 ) ;
F_8 ( L_83 , V_34 ) ;
}
struct V_1013 *
F_612 ( struct V_995 * V_996 , long * V_60 , T_7 V_1011 )
{
struct V_2 * V_2 = V_996 -> args . V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
T_9 V_1012 = F_605 ( V_14 ) ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_1014 ] ,
. V_339 = & V_996 -> args ,
. V_340 = & V_996 -> V_66 ,
. V_51 = V_996 -> V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_1015 ,
. V_185 = V_996 ,
. V_236 = V_345 ,
} ;
struct V_1013 * V_1016 = NULL ;
struct V_70 V_71 = {
. V_2 = V_2 ,
. V_60 = * V_60 ,
} ;
int V_331 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_613 ( F_93 ( V_2 ) -> V_1007 ) ;
V_996 -> args . V_1007 . V_42 = F_608 ( V_1012 , V_1011 ) ;
if ( ! V_996 -> args . V_1007 . V_42 ) {
F_610 ( V_996 ) ;
return F_57 ( - V_142 ) ;
}
V_996 -> args . V_1007 . V_562 = V_1012 * V_659 ;
V_996 -> V_66 . V_1017 = & V_996 -> args . V_1007 ;
V_996 -> V_66 . V_177 . V_134 = NULL ;
F_51 ( & V_996 -> args . V_176 , & V_996 -> V_66 . V_177 , 0 ) ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_286 ( V_113 ) ;
V_331 = F_128 ( V_113 ) ;
if ( V_331 == 0 ) {
V_331 = F_601 ( V_113 , V_996 , & V_71 ) ;
* V_60 = V_71 . V_60 ;
}
F_614 ( V_996 -> args . V_326 ,
& V_996 -> args . V_1018 ,
& V_996 -> V_66 . V_1018 ,
& V_996 -> V_66 . V_50 ,
V_331 ) ;
if ( V_331 == 0 && V_996 -> V_66 . V_1017 -> V_12 )
V_1016 = F_615 ( V_996 ) ;
F_77 ( & V_996 -> V_66 . V_177 ) ;
F_90 ( V_113 ) ;
F_8 ( L_16 , V_34 , V_331 ) ;
if ( V_331 )
return F_57 ( V_331 ) ;
return V_1016 ;
}
static void
F_616 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1019 * V_1020 = V_172 ;
F_8 ( L_11 , V_34 ) ;
F_79 ( V_1020 -> V_72 -> V_97 ,
& V_1020 -> args . V_176 ,
& V_1020 -> V_66 . V_177 ,
V_113 ) ;
}
static void F_617 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1019 * V_1020 = V_172 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_68 ( V_113 , & V_1020 -> V_66 . V_177 ) )
return;
V_14 = F_105 ( V_1020 -> args . V_2 ) ;
switch ( V_113 -> V_117 ) {
default:
V_113 -> V_117 = 0 ;
case 0 :
break;
case - V_99 :
if ( F_43 ( V_113 , V_14 , NULL , NULL ) != - V_118 )
break;
F_77 ( & V_1020 -> V_66 . V_177 ) ;
F_73 ( V_113 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_618 ( void * V_172 )
{
struct V_1019 * V_1020 = V_172 ;
struct V_997 * V_998 = V_1020 -> args . V_1007 ;
F_8 ( L_11 , V_34 ) ;
F_619 ( V_998 , & V_1020 -> args . V_50 , & V_1020 -> args . V_1018 ,
V_1020 -> V_66 . V_1021 ? & V_1020 -> V_66 . V_50 : NULL ) ;
F_77 ( & V_1020 -> V_66 . V_177 ) ;
if ( V_1020 -> V_468 . V_54 && V_1020 -> V_468 . V_54 -> free )
V_1020 -> V_468 . V_54 -> free ( & V_1020 -> V_468 ) ;
F_611 ( V_1020 -> args . V_1007 ) ;
F_463 ( V_1020 -> V_2 ) ;
F_117 ( V_172 ) ;
F_8 ( L_83 , V_34 ) ;
}
int F_620 ( struct V_1019 * V_1020 , bool V_1022 )
{
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_1023 ] ,
. V_339 = & V_1020 -> args ,
. V_340 = & V_1020 -> V_66 ,
. V_51 = V_1020 -> V_52 ,
} ;
struct V_180 V_341 = {
. V_182 = F_105 ( V_1020 -> args . V_2 ) -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_1024 ,
. V_185 = V_1020 ,
} ;
int V_331 = 0 ;
F_283 ( F_105 ( V_1020 -> args . V_2 ) -> V_55 ,
V_896 ,
& V_341 . V_182 , & V_179 ) ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_1022 ) {
V_1020 -> V_2 = F_466 ( V_1020 -> args . V_2 ) ;
if ( ! V_1020 -> V_2 ) {
F_618 ( V_1020 ) ;
return - V_118 ;
}
V_341 . V_236 |= V_345 ;
}
F_51 ( & V_1020 -> args . V_176 , & V_1020 -> V_66 . V_177 , 1 ) ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
if ( V_1022 )
V_331 = V_113 -> V_117 ;
F_621 ( V_1020 -> args . V_2 , & V_1020 -> args . V_50 , V_331 ) ;
F_8 ( L_16 , V_34 , V_331 ) ;
F_90 ( V_113 ) ;
return V_331 ;
}
static int
F_622 ( struct V_13 * V_14 ,
struct V_1025 * V_1026 ,
struct V_51 * V_52 )
{
struct V_1027 args = {
. V_1026 = V_1026 ,
. V_1028 = V_1029 |
V_1030 ,
} ;
struct V_1031 V_66 = {
. V_1026 = V_1026 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_1032 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_331 ;
F_8 ( L_11 , V_34 ) ;
V_331 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_66 . V_1033 & ~ args . V_1028 )
F_8 ( L_102 , V_34 ) ;
if ( V_66 . V_1033 != args . V_1028 )
V_1026 -> V_1034 = 1 ;
F_8 ( L_16 , V_34 , V_331 ) ;
return V_331 ;
}
int F_623 ( struct V_13 * V_14 ,
struct V_1025 * V_1026 ,
struct V_51 * V_52 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_622 ( V_14 , V_1026 , V_52 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_624 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1035 * V_174 = V_172 ;
struct V_13 * V_14 = F_105 ( V_174 -> args . V_2 ) ;
struct V_148 * V_149 = F_82 ( V_14 ) ;
F_79 ( V_149 ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static void
F_625 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1035 * V_174 = V_172 ;
struct V_13 * V_14 = F_105 ( V_174 -> args . V_2 ) ;
if ( ! F_75 ( V_113 , & V_174 -> V_66 . V_177 ) )
return;
switch ( V_113 -> V_117 ) {
case - V_78 :
case - V_1036 :
case - V_1003 :
case - V_101 :
V_113 -> V_117 = 0 ;
case 0 :
break;
default:
if ( F_43 ( V_113 , V_14 , NULL , NULL ) == - V_118 ) {
F_73 ( V_113 ) ;
return;
}
}
}
static void F_626 ( void * V_172 )
{
struct V_1035 * V_174 = V_172 ;
F_627 ( V_174 ) ;
F_462 ( V_174 -> args . V_2 ,
V_174 -> V_66 . V_435 ) ;
F_236 ( V_174 -> V_52 ) ;
F_463 ( V_174 -> V_2 ) ;
F_117 ( V_174 ) ;
}
int
F_628 ( struct V_1035 * V_174 , bool V_1022 )
{
struct V_178 V_179 = {
. V_336 = & V_337 [ V_1037 ] ,
. V_339 = & V_174 -> args ,
. V_340 = & V_174 -> V_66 ,
. V_51 = V_174 -> V_52 ,
} ;
struct V_180 V_341 = {
. V_113 = & V_174 -> V_113 ,
. V_182 = F_323 ( V_174 -> args . V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_1038 ,
. V_185 = V_174 ,
} ;
struct V_112 * V_113 ;
int V_331 = 0 ;
F_8 ( L_103
L_104 , V_1022 ,
V_174 -> args . V_1039 ,
V_174 -> args . V_2 -> V_1040 ) ;
if ( ! V_1022 ) {
V_174 -> V_2 = F_466 ( V_174 -> args . V_2 ) ;
if ( V_174 -> V_2 == NULL ) {
F_626 ( V_174 ) ;
return - V_118 ;
}
V_341 . V_236 = V_345 ;
}
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
V_113 = F_88 ( & V_341 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
if ( V_1022 )
V_331 = V_113 -> V_117 ;
F_629 ( V_174 -> args . V_2 , & V_174 -> args . V_50 , V_331 ) ;
F_8 ( L_105 , V_34 , V_331 ) ;
F_90 ( V_113 ) ;
return V_331 ;
}
static int
F_630 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 ,
struct V_841 * V_528 , bool V_842 )
{
struct V_1041 args = {
. V_1042 = V_1043 ,
} ;
struct V_844 V_66 = {
. V_528 = V_528 ,
} ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_1044 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
} ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_51 * V_52 = NULL ;
int V_331 ;
if ( V_842 ) {
V_65 = V_14 -> V_55 -> V_120 ;
V_52 = F_542 ( V_14 -> V_55 ) ;
V_179 . V_51 = V_52 ;
}
F_8 ( L_11 , V_34 ) ;
V_331 = F_91 ( V_65 , V_14 , & V_179 , & args . V_176 ,
& V_66 . V_177 , 0 ) ;
F_8 ( L_16 , V_34 , V_331 ) ;
if ( V_52 )
F_236 ( V_52 ) ;
return V_331 ;
}
static int
F_631 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 , struct V_841 * V_528 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( V_14 -> V_55 ) )
V_8 = F_630 ( V_14 , V_472 , V_512 ,
V_528 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_630 ( V_14 , V_472 , V_512 ,
V_528 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_1045 :
goto V_160;
default:
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
}
} while ( V_71 . V_77 );
V_160:
return V_8 ;
}
static int
F_632 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_511 * V_512 )
{
int V_8 ;
struct V_535 * V_535 ;
T_5 V_119 = V_1046 ;
struct V_841 * V_528 ;
struct V_1047 * V_1048 ;
int V_525 ;
V_535 = F_304 ( V_420 ) ;
if ( ! V_535 ) {
V_8 = - V_142 ;
goto V_160;
}
V_528 = F_418 ( V_535 ) ;
V_8 = F_631 ( V_14 , V_472 , V_512 , V_528 ) ;
if ( V_8 == - V_22 || V_8 == - V_1045 ) {
V_8 = F_297 ( V_14 , V_472 , V_512 ) ;
goto V_1049;
}
if ( V_8 )
goto V_1049;
for ( V_525 = 0 ; V_525 < V_528 -> V_1050 ; V_525 ++ ) {
V_1048 = & V_528 -> V_528 [ V_525 ] ;
switch ( V_1048 -> V_119 ) {
case V_524 :
case V_523 :
case V_1051 :
V_119 = F_633 ( V_1048 -> V_119 ,
& V_1048 -> V_1052 ) ;
break;
default:
V_119 = V_1046 ;
break;
}
if ( ! F_634 ( & V_14 -> V_526 , V_119 ) )
V_119 = V_1046 ;
if ( V_119 != V_1046 ) {
V_8 = F_295 ( V_14 , V_472 ,
V_512 , V_119 ) ;
if ( ! V_8 )
break;
}
}
if ( V_119 == V_1046 )
V_8 = - V_24 ;
V_1049:
F_432 ( V_535 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_160:
return V_8 ;
}
static int F_635 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
int V_331 ;
struct V_1053 args = {
. V_50 = V_50 ,
} ;
struct V_1054 V_66 ;
struct V_178 V_179 = {
. V_336 = & V_337 [ V_1055 ] ,
. V_339 = & args ,
. V_340 = & V_66 ,
. V_51 = V_52 ,
} ;
struct V_64 * V_182 = V_14 -> V_108 ;
F_283 ( V_14 -> V_55 , V_901 ,
& V_182 , & V_179 ) ;
F_8 ( L_106 , V_50 ) ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_331 = F_87 ( V_182 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
if ( V_331 != V_391 ) {
F_8 ( L_107 , V_331 ) ;
return V_331 ;
}
F_8 ( L_108 , - V_66 . V_331 ) ;
return - V_66 . V_331 ;
}
static void F_636 ( struct V_13 * V_14 ,
int V_8 , struct V_70 * V_71 )
{
V_71 -> V_77 = 0 ;
switch( V_8 ) {
case - V_99 :
case - V_102 :
F_36 ( V_14 , V_8 , V_71 ) ;
break;
case - V_90 :
case - V_91 :
case - V_92 :
case - V_93 :
case - V_94 :
F_25 ( V_14 , V_8 , V_71 ) ;
}
}
static int F_231 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_635 ( V_14 , V_50 , V_52 ) ;
F_636 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_637 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1056 * V_174 = V_172 ;
F_79 ( F_82 ( V_174 -> V_14 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static void F_638 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1056 * V_174 = V_172 ;
F_75 ( V_113 , & V_174 -> V_66 . V_177 ) ;
switch ( V_113 -> V_117 ) {
case - V_99 :
if ( F_43 ( V_113 , V_174 -> V_14 , NULL , NULL ) == - V_118 )
F_73 ( V_113 ) ;
}
}
static void F_639 ( void * V_172 )
{
F_117 ( V_172 ) ;
}
static struct V_112 * F_640 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 ,
bool V_144 )
{
struct V_178 V_179 = {
. V_336 = & V_337 [ V_1057 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_181 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_1058 ,
. V_236 = V_345 ,
} ;
struct V_1056 * V_174 ;
F_283 ( V_14 -> V_55 , V_901 ,
& V_181 . V_182 , & V_179 ) ;
F_8 ( L_109 , V_50 ) ;
V_174 = F_305 ( sizeof( * V_174 ) , V_328 ) ;
if ( ! V_174 )
return F_57 ( - V_142 ) ;
V_174 -> V_14 = V_14 ;
F_19 ( & V_174 -> args . V_50 , V_50 ) ;
V_181 . V_185 = V_174 ;
V_179 . V_339 = & V_174 -> args ;
V_179 . V_340 = & V_174 -> V_66 ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
if ( V_144 )
F_52 ( & V_174 -> args . V_176 ) ;
return F_88 ( & V_181 ) ;
}
static int F_232 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 ,
bool V_1059 )
{
struct V_112 * V_113 ;
V_113 = F_640 ( V_14 , V_50 , V_52 , V_1059 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
F_90 ( V_113 ) ;
return 0 ;
}
static void
F_641 ( struct V_13 * V_14 , struct V_308 * V_309 )
{
struct V_51 * V_52 = V_309 -> V_310 -> V_249 -> V_307 ;
F_232 ( V_14 , & V_309 -> V_312 , V_52 , false ) ;
F_520 ( V_14 , V_309 ) ;
}
static bool F_642 ( const T_4 * V_1060 ,
const T_4 * V_1061 )
{
if ( V_1060 -> type != V_1061 -> type )
return false ;
if ( memcmp ( V_1060 -> V_1062 , V_1061 -> V_1062 , sizeof( V_1060 -> V_1062 ) ) != 0 )
return false ;
if ( V_1060 -> V_226 == V_1061 -> V_226 )
return true ;
if ( V_1060 -> V_226 == 0 || V_1061 -> V_226 == 0 )
return true ;
return false ;
}
static bool F_643 ( const T_4 * V_1060 ,
const T_4 * V_1061 )
{
return F_159 ( V_1060 , V_1061 ) ;
}
static struct V_240 *
F_644 ( struct V_242 * V_1063 , T_7 V_1064 )
{
return NULL ;
}
static T_11 F_645 ( struct V_4 * V_4 , char * V_814 , T_9 V_1010 )
{
T_11 error , V_1065 ;
error = F_646 ( V_4 , V_814 , V_1010 ) ;
if ( error < 0 )
return error ;
if ( V_814 ) {
V_814 += error ;
V_1010 -= error ;
}
V_1065 = F_528 ( F_14 ( V_4 ) , V_814 , V_1010 ) ;
if ( V_1065 < 0 )
return V_1065 ;
return error + V_1065 ;
}
