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
static void F_92 ( struct V_2 * V_3 , struct V_186 * V_187 )
{
struct V_188 * V_189 = F_93 ( V_3 ) ;
F_46 ( & V_3 -> V_190 ) ;
V_189 -> V_191 |= V_192 | V_193 ;
if ( ! V_187 -> V_194 || V_187 -> V_195 != V_3 -> V_196 )
F_94 ( V_3 ) ;
V_3 -> V_196 = V_187 -> V_197 ;
V_189 -> V_198 = F_95 () ;
F_96 ( V_3 ) ;
F_48 ( & V_3 -> V_190 ) ;
}
static bool F_97 ( struct V_13 * V_14 ,
int V_8 , struct V_70 * V_71 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_104 & V_199 ) )
return false ;
V_14 -> V_104 &= ~ V_199 ;
V_71 -> V_77 = 1 ;
return true ;
}
static T_1
F_98 ( struct V_13 * V_14 ,
T_6 V_200 , int V_201 )
{
T_1 V_66 = 0 ;
switch ( V_200 & ( V_202 | V_203 ) ) {
case V_202 :
V_66 = V_204 ;
break;
case V_203 :
V_66 = V_205 ;
break;
case V_202 | V_203 :
V_66 = V_206 ;
}
if ( ! ( V_14 -> V_104 & V_199 ) )
goto V_160;
if ( V_201 & V_207 )
V_66 |= V_208 ;
V_160:
return V_66 ;
}
static enum V_209
F_99 ( struct V_13 * V_14 ,
enum V_209 V_210 )
{
if ( V_14 -> V_104 & V_199 )
return V_210 ;
switch ( V_210 ) {
default:
return V_210 ;
case V_211 :
return V_212 ;
case V_213 :
return V_214 ;
case V_215 :
return V_216 ;
}
}
static void F_100 ( struct V_217 * V_41 )
{
V_41 -> V_218 . V_219 = & V_41 -> V_219 ;
V_41 -> V_218 . V_220 = V_41 -> V_220 ;
V_41 -> V_218 . V_221 = V_41 -> V_222 . V_221 ;
V_41 -> V_223 . V_221 = V_41 -> V_224 . V_221 ;
V_41 -> V_218 . V_14 = V_41 -> V_222 . V_14 ;
V_41 -> V_218 . V_225 = V_41 -> V_222 . V_226 ;
F_101 ( & V_41 -> V_219 ) ;
F_102 ( & V_41 -> V_219 , & V_41 -> V_227 , & V_41 -> V_228 ) ;
}
static struct V_217 * F_103 ( struct V_4 * V_4 ,
struct V_229 * V_230 , T_6 V_200 , int V_231 ,
const struct V_5 * V_232 ,
struct V_1 * V_7 ,
enum V_209 V_210 ,
T_7 V_233 )
{
struct V_4 * V_234 = F_104 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_234 ) ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_235 * ( * V_236 ) ( struct V_237 * , T_7 ) ;
struct V_217 * V_41 ;
V_41 = F_106 ( sizeof( * V_41 ) , V_233 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_220 = F_107 ( V_14 , V_233 ) ;
if ( F_56 ( V_41 -> V_220 ) )
goto V_238;
V_41 -> V_239 = F_107 ( V_14 , V_233 ) ;
if ( F_56 ( V_41 -> V_239 ) )
goto V_240;
V_236 = V_14 -> V_55 -> V_56 -> V_236 ;
V_41 -> V_222 . V_221 = V_236 ( & V_230 -> V_241 , V_233 ) ;
if ( F_56 ( V_41 -> V_222 . V_221 ) )
goto V_242;
F_108 ( V_4 -> V_243 ) ;
V_41 -> V_4 = F_109 ( V_4 ) ;
V_41 -> V_3 = V_234 ;
V_41 -> V_244 = V_230 ;
F_110 ( & V_230 -> V_245 ) ;
V_41 -> V_222 . V_246 = V_231 ;
V_41 -> V_222 . V_200 = V_200 & ( V_202 | V_203 ) ;
V_41 -> V_222 . V_247 = F_98 ( V_14 ,
V_200 , V_231 ) ;
if ( ! ( V_231 & V_248 ) ) {
V_41 -> V_222 . V_226 = V_249 | V_250 |
V_251 | V_252 ;
}
V_41 -> V_222 . V_253 = V_14 -> V_55 -> V_254 ;
V_41 -> V_222 . V_255 . V_256 = F_111 ( V_230 -> V_241 . V_256 ) ;
V_41 -> V_222 . V_255 . V_257 = V_230 -> V_241 . V_258 ;
V_41 -> V_222 . V_259 = & V_4 -> V_11 ;
V_41 -> V_222 . V_14 = V_14 ;
V_41 -> V_222 . V_260 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_222 . V_261 = & V_262 [ 0 ] ;
V_41 -> V_222 . V_7 = F_112 ( V_41 -> V_239 , V_7 ) ;
V_41 -> V_222 . V_210 = F_99 ( V_14 , V_210 ) ;
switch ( V_41 -> V_222 . V_210 ) {
case V_212 :
case V_214 :
case V_216 :
V_41 -> V_222 . V_263 = F_113 ( V_3 ) ;
break;
case V_264 :
case V_211 :
case V_213 :
case V_215 :
V_41 -> V_222 . V_263 = F_113 ( F_14 ( V_4 ) ) ;
}
if ( V_232 != NULL && V_232 -> V_265 != 0 ) {
T_8 V_266 [ 2 ] ;
V_41 -> V_222 . V_267 . V_232 = & V_41 -> V_232 ;
memcpy ( & V_41 -> V_232 , V_232 , sizeof( V_41 -> V_232 ) ) ;
V_266 [ 0 ] = V_170 ;
V_266 [ 1 ] = V_67 -> V_268 ;
memcpy ( V_41 -> V_222 . V_267 . V_37 . V_174 , V_266 ,
sizeof( V_41 -> V_222 . V_267 . V_37 . V_174 ) ) ;
}
V_41 -> V_224 . V_263 = & V_41 -> V_218 . V_263 ;
V_41 -> V_224 . V_50 = & V_41 -> V_218 . V_50 ;
V_41 -> V_224 . V_221 = V_41 -> V_222 . V_221 ;
F_100 ( V_41 ) ;
F_114 ( & V_41 -> V_269 ) ;
return V_41 ;
V_242:
F_115 ( V_41 -> V_239 ) ;
V_240:
F_115 ( V_41 -> V_220 ) ;
V_238:
F_116 ( V_41 ) ;
V_8:
F_117 ( V_234 ) ;
return NULL ;
}
static void F_118 ( struct V_269 * V_269 )
{
struct V_217 * V_41 = F_119 ( V_269 ,
struct V_217 , V_269 ) ;
struct V_270 * V_271 = V_41 -> V_4 -> V_243 ;
F_120 ( V_41 -> V_222 . V_221 ) ;
F_77 ( & V_41 -> V_218 . V_177 ) ;
if ( V_41 -> V_74 != NULL )
F_121 ( V_41 -> V_74 ) ;
F_122 ( V_41 -> V_244 ) ;
F_115 ( V_41 -> V_239 ) ;
F_115 ( V_41 -> V_220 ) ;
F_117 ( V_41 -> V_3 ) ;
F_117 ( V_41 -> V_4 ) ;
F_123 ( V_271 ) ;
F_124 ( & V_41 -> V_219 ) ;
F_116 ( V_41 -> V_219 . V_272 ) ;
F_116 ( V_41 ) ;
}
static void F_125 ( struct V_217 * V_41 )
{
if ( V_41 != NULL )
F_126 ( & V_41 -> V_269 , F_118 ) ;
}
static int F_127 ( struct V_112 * V_113 )
{
int V_61 ;
V_61 = F_128 ( V_113 ) ;
return V_61 ;
}
static bool F_129 ( struct V_73 * V_74 ,
T_6 V_200 )
{
switch( V_200 & ( V_202 | V_203 ) ) {
case V_202 | V_203 :
return V_74 -> V_273 != 0 ;
case V_203 :
return V_74 -> V_274 != 0 ;
case V_202 :
return V_74 -> V_275 != 0 ;
}
F_130 ( 1 ) ;
return false ;
}
static int F_131 ( struct V_73 * V_74 , T_6 V_276 , int V_277 )
{
int V_61 = 0 ;
if ( V_277 & ( V_248 | V_278 ) )
goto V_160;
switch ( V_276 & ( V_202 | V_203 ) ) {
case V_202 :
V_61 |= F_38 ( V_279 , & V_74 -> V_231 ) != 0
&& V_74 -> V_275 != 0 ;
break;
case V_203 :
V_61 |= F_38 ( V_280 , & V_74 -> V_231 ) != 0
&& V_74 -> V_274 != 0 ;
break;
case V_202 | V_203 :
V_61 |= F_38 ( V_281 , & V_74 -> V_231 ) != 0
&& V_74 -> V_273 != 0 ;
}
V_160:
return V_61 ;
}
static int F_132 ( struct V_282 * V_283 , T_6 V_200 ,
enum V_209 V_210 )
{
if ( V_283 == NULL )
return 0 ;
if ( ( V_283 -> type & V_200 ) != V_200 )
return 0 ;
if ( F_38 ( V_284 , & V_283 -> V_231 ) )
return 0 ;
switch ( V_210 ) {
case V_212 :
case V_211 :
break;
case V_264 :
if ( ! F_38 ( V_285 , & V_283 -> V_231 ) )
break;
default:
return 0 ;
}
F_133 ( V_283 ) ;
return 1 ;
}
static void F_134 ( struct V_73 * V_74 , T_6 V_200 )
{
switch ( V_200 ) {
case V_203 :
V_74 -> V_274 ++ ;
break;
case V_202 :
V_74 -> V_275 ++ ;
break;
case V_202 | V_203 :
V_74 -> V_273 ++ ;
}
F_135 ( V_74 , V_74 -> V_74 | V_200 ) ;
}
static bool F_136 ( struct V_73 * V_74 )
{
if ( V_74 -> V_275 && ! F_38 ( V_279 , & V_74 -> V_231 ) )
return true ;
if ( V_74 -> V_274 && ! F_38 ( V_280 , & V_74 -> V_231 ) )
return true ;
if ( V_74 -> V_273 && ! F_38 ( V_281 , & V_74 -> V_231 ) )
return true ;
return false ;
}
static void F_137 ( struct V_73 * V_74 )
{
struct V_55 * V_72 = V_74 -> V_244 -> V_286 -> V_55 ;
bool V_287 = false ;
if ( F_138 ( V_279 , & V_74 -> V_231 ) && V_74 -> V_275 )
V_287 = true ;
if ( F_138 ( V_280 , & V_74 -> V_231 ) && V_74 -> V_274 )
V_287 = true ;
if ( F_138 ( V_281 , & V_74 -> V_231 ) && V_74 -> V_273 )
V_287 = true ;
if ( V_287 )
F_139 ( V_72 , V_74 ) ;
}
static bool F_140 ( struct V_73 * V_74 ,
const T_4 * V_50 , T_4 * V_288 )
{
if ( F_141 ( V_289 , & V_74 -> V_231 ) == 0 )
return true ;
if ( ! F_142 ( V_50 , & V_74 -> V_290 ) ) {
F_19 ( V_288 , & V_74 -> V_290 ) ;
F_137 ( V_74 ) ;
return true ;
}
if ( F_143 ( V_50 , & V_74 -> V_290 ) )
return true ;
return false ;
}
static void F_144 ( struct V_73 * V_74 )
{
if ( ! ( V_74 -> V_274 || V_74 -> V_275 || V_74 -> V_273 ) )
return;
if ( V_74 -> V_274 )
F_145 ( V_280 , & V_74 -> V_231 ) ;
if ( V_74 -> V_275 )
F_145 ( V_279 , & V_74 -> V_231 ) ;
if ( V_74 -> V_273 )
F_145 ( V_281 , & V_74 -> V_231 ) ;
F_145 ( V_289 , & V_74 -> V_231 ) ;
}
static void F_146 ( struct V_73 * V_74 ,
T_4 * V_50 , T_6 V_200 )
{
F_147 ( V_281 , & V_74 -> V_231 ) ;
switch ( V_200 & ( V_202 | V_203 ) ) {
case V_203 :
F_147 ( V_279 , & V_74 -> V_231 ) ;
break;
case V_202 :
F_147 ( V_280 , & V_74 -> V_231 ) ;
break;
case 0 :
F_147 ( V_279 , & V_74 -> V_231 ) ;
F_147 ( V_280 , & V_74 -> V_231 ) ;
F_147 ( V_289 , & V_74 -> V_231 ) ;
}
if ( V_50 == NULL )
return;
if ( F_142 ( V_50 , & V_74 -> V_290 ) &&
! F_143 ( V_50 , & V_74 -> V_290 ) ) {
F_144 ( V_74 ) ;
return;
}
if ( F_38 ( V_291 , & V_74 -> V_231 ) == 0 )
F_19 ( & V_74 -> V_50 , V_50 ) ;
F_19 ( & V_74 -> V_290 , V_50 ) ;
}
static void F_148 ( struct V_73 * V_74 ,
T_4 * V_292 ,
T_4 * V_50 , T_6 V_200 )
{
F_149 ( & V_74 -> V_293 ) ;
if ( F_150 ( V_74 , V_292 ) )
F_146 ( V_74 , V_50 , V_200 ) ;
F_151 ( & V_74 -> V_293 ) ;
if ( F_38 ( V_294 , & V_74 -> V_231 ) )
F_152 ( V_74 -> V_244 -> V_286 -> V_55 ) ;
}
static void F_153 ( struct V_73 * V_74 ,
const T_4 * V_50 , T_6 V_200 ,
T_4 * V_288 )
{
switch ( V_200 ) {
case V_202 :
F_145 ( V_279 , & V_74 -> V_231 ) ;
break;
case V_203 :
F_145 ( V_280 , & V_74 -> V_231 ) ;
break;
case V_202 | V_203 :
F_145 ( V_281 , & V_74 -> V_231 ) ;
}
if ( ! F_140 ( V_74 , V_50 , V_288 ) )
return;
if ( F_38 ( V_291 , & V_74 -> V_231 ) == 0 )
F_19 ( & V_74 -> V_50 , V_50 ) ;
F_19 ( & V_74 -> V_290 , V_50 ) ;
}
static void F_154 ( struct V_73 * V_74 ,
const T_4 * V_290 ,
const T_4 * V_295 ,
T_6 V_200 ,
T_4 * V_288 )
{
F_46 ( & V_74 -> V_244 -> V_296 ) ;
F_149 ( & V_74 -> V_293 ) ;
if ( V_295 != NULL ) {
F_19 ( & V_74 -> V_50 , V_295 ) ;
F_145 ( V_291 , & V_74 -> V_231 ) ;
}
if ( V_290 != NULL )
F_153 ( V_74 , V_290 , V_200 , V_288 ) ;
F_151 ( & V_74 -> V_293 ) ;
F_134 ( V_74 , V_200 ) ;
F_48 ( & V_74 -> V_244 -> V_296 ) ;
}
static int F_155 ( struct V_73 * V_74 ,
const T_4 * V_290 ,
const T_4 * V_283 ,
T_6 V_200 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_282 * V_297 ;
T_4 V_288 = { } ;
int V_61 = 0 ;
V_200 &= ( V_202 | V_203 ) ;
F_156 () ;
V_297 = F_157 ( V_189 -> V_283 ) ;
if ( V_297 == NULL )
goto V_298;
F_46 ( & V_297 -> V_299 ) ;
if ( F_157 ( V_189 -> V_283 ) != V_297 ||
F_38 ( V_284 , & V_297 -> V_231 ) ||
( V_297 -> type & V_200 ) != V_200 )
goto V_300;
if ( V_283 == NULL )
V_283 = & V_297 -> V_50 ;
else if ( ! F_158 ( & V_297 -> V_50 , V_283 ) )
goto V_300;
F_133 ( V_297 ) ;
F_154 ( V_74 , V_290 , & V_297 -> V_50 ,
V_200 , & V_288 ) ;
V_61 = 1 ;
V_300:
F_48 ( & V_297 -> V_299 ) ;
V_298:
F_159 () ;
if ( ! V_61 && V_290 != NULL ) {
F_154 ( V_74 , V_290 , NULL , V_200 , & V_288 ) ;
V_61 = 1 ;
}
if ( F_38 ( V_294 , & V_74 -> V_231 ) )
F_152 ( V_72 ) ;
if ( V_288 . type != 0 )
F_16 ( V_14 , & V_288 ,
V_74 -> V_244 -> V_301 ) ;
return V_61 ;
}
static bool F_160 ( struct V_302 * V_303 ,
const T_4 * V_50 )
{
struct V_73 * V_74 = V_303 -> V_304 ;
bool V_61 = false ;
F_46 ( & V_74 -> V_305 ) ;
if ( ! F_142 ( V_50 , & V_303 -> V_306 ) )
goto V_307;
if ( ! F_143 ( V_50 , & V_303 -> V_306 ) )
goto V_307;
F_19 ( & V_303 -> V_306 , V_50 ) ;
V_61 = true ;
V_307:
F_48 ( & V_74 -> V_305 ) ;
return V_61 ;
}
static void F_161 ( struct V_2 * V_2 , T_6 V_200 )
{
struct V_282 * V_283 ;
F_156 () ;
V_283 = F_157 ( F_93 ( V_2 ) -> V_283 ) ;
if ( V_283 == NULL || ( V_283 -> type & V_200 ) == V_200 ) {
F_159 () ;
return;
}
F_159 () ;
F_162 ( V_2 ) ;
}
static struct V_73 * F_163 ( struct V_217 * V_308 )
{
struct V_73 * V_74 = V_308 -> V_74 ;
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_282 * V_283 ;
int V_277 = V_308 -> V_222 . V_246 ;
T_6 V_200 = V_308 -> V_222 . V_200 ;
enum V_209 V_210 = V_308 -> V_222 . V_210 ;
T_4 V_50 ;
int V_61 = - V_118 ;
for (; ; ) {
F_46 ( & V_74 -> V_244 -> V_296 ) ;
if ( F_131 ( V_74 , V_200 , V_277 ) ) {
F_134 ( V_74 , V_200 ) ;
F_48 ( & V_74 -> V_244 -> V_296 ) ;
goto V_309;
}
F_48 ( & V_74 -> V_244 -> V_296 ) ;
F_156 () ;
V_283 = F_157 ( V_189 -> V_283 ) ;
if ( ! F_132 ( V_283 , V_200 , V_210 ) ) {
F_159 () ;
break;
}
F_19 ( & V_50 , & V_283 -> V_50 ) ;
F_159 () ;
F_164 ( V_308 -> V_222 . V_221 ) ;
if ( ! V_308 -> V_310 ) {
V_61 = F_165 ( V_74 -> V_2 , V_74 -> V_244 -> V_301 , V_277 ) ;
if ( V_61 != 0 )
goto V_160;
}
V_61 = - V_118 ;
if ( F_155 ( V_74 , NULL , & V_50 , V_200 ) )
goto V_309;
}
V_160:
return F_57 ( V_61 ) ;
V_309:
F_110 ( & V_74 -> V_49 ) ;
return V_74 ;
}
static void
F_166 ( struct V_217 * V_174 , struct V_73 * V_74 )
{
struct V_55 * V_72 = F_105 ( V_74 -> V_2 ) -> V_55 ;
struct V_282 * V_283 ;
int V_311 = 0 ;
F_156 () ;
V_283 = F_157 ( F_93 ( V_74 -> V_2 ) -> V_283 ) ;
if ( V_283 )
V_311 = V_283 -> V_231 ;
F_159 () ;
switch ( V_174 -> V_222 . V_210 ) {
default:
break;
case V_214 :
case V_213 :
F_167 ( L_18
L_19
L_20 ,
V_72 -> V_107 ) ;
return;
}
if ( ( V_311 & 1UL << V_285 ) == 0 )
F_168 ( V_74 -> V_2 ,
V_174 -> V_244 -> V_301 ,
& V_174 -> V_218 ) ;
else
F_169 ( V_74 -> V_2 ,
V_174 -> V_244 -> V_301 ,
& V_174 -> V_218 ) ;
}
static struct V_73 *
F_170 ( struct V_217 * V_174 )
{
struct V_2 * V_2 = V_174 -> V_74 -> V_2 ;
struct V_73 * V_74 = V_174 -> V_74 ;
int V_61 ;
if ( ! V_174 -> V_312 ) {
if ( V_174 -> V_313 ) {
V_61 = V_174 -> V_313 ;
goto V_8;
}
goto V_314;
}
V_61 = F_171 ( V_2 , & V_174 -> V_219 ) ;
if ( V_61 )
goto V_8;
if ( V_174 -> V_218 . V_315 != 0 )
F_166 ( V_174 , V_74 ) ;
V_314:
F_155 ( V_74 , & V_174 -> V_218 . V_50 , NULL ,
V_174 -> V_222 . V_200 ) ;
F_110 ( & V_74 -> V_49 ) ;
return V_74 ;
V_8:
return F_57 ( V_61 ) ;
}
static struct V_73 *
F_172 ( struct V_217 * V_174 )
{
struct V_2 * V_2 ;
struct V_73 * V_74 = NULL ;
int V_61 ;
if ( ! V_174 -> V_312 ) {
V_74 = F_163 ( V_174 ) ;
F_173 ( V_174 -> V_74 ) ;
goto V_160;
}
V_61 = - V_118 ;
if ( ! ( V_174 -> V_219 . V_316 & V_317 ) )
goto V_8;
V_2 = F_174 ( V_174 -> V_3 -> V_243 , & V_174 -> V_218 . V_263 , & V_174 -> V_219 , V_174 -> V_220 ) ;
V_61 = F_89 ( V_2 ) ;
if ( F_56 ( V_2 ) )
goto V_8;
V_61 = - V_142 ;
V_74 = F_175 ( V_2 , V_174 -> V_244 ) ;
if ( V_74 == NULL )
goto V_318;
if ( V_174 -> V_218 . V_315 != 0 )
F_166 ( V_174 , V_74 ) ;
F_155 ( V_74 , & V_174 -> V_218 . V_50 , NULL ,
V_174 -> V_222 . V_200 ) ;
F_176 ( V_2 ) ;
V_160:
F_164 ( V_174 -> V_222 . V_221 ) ;
return V_74 ;
V_318:
F_176 ( V_2 ) ;
V_8:
return F_57 ( V_61 ) ;
}
static struct V_73 *
F_177 ( struct V_217 * V_174 )
{
struct V_73 * V_61 ;
if ( V_174 -> V_222 . V_210 == V_264 )
V_61 = F_170 ( V_174 ) ;
else
V_61 = F_172 ( V_174 ) ;
F_77 ( & V_174 -> V_218 . V_177 ) ;
return V_61 ;
}
static struct V_319 * F_178 ( struct V_73 * V_74 )
{
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_319 * V_320 ;
F_46 ( & V_74 -> V_2 -> V_190 ) ;
F_179 (ctx, &nfsi->open_files, list) {
if ( V_320 -> V_74 != V_74 )
continue;
F_180 ( V_320 ) ;
F_48 ( & V_74 -> V_2 -> V_190 ) ;
return V_320 ;
}
F_48 ( & V_74 -> V_2 -> V_190 ) ;
return F_57 ( - V_321 ) ;
}
static struct V_217 * F_181 ( struct V_319 * V_320 ,
struct V_73 * V_74 , enum V_209 V_210 )
{
struct V_217 * V_308 ;
V_308 = F_103 ( V_320 -> V_4 , V_74 -> V_244 , 0 , 0 ,
NULL , NULL , V_210 , V_322 ) ;
if ( V_308 == NULL )
return F_57 ( - V_142 ) ;
V_308 -> V_74 = V_74 ;
F_110 ( & V_74 -> V_49 ) ;
return V_308 ;
}
static int F_182 ( struct V_217 * V_308 ,
T_6 V_200 )
{
struct V_73 * V_323 ;
int V_61 ;
if ( ! F_129 ( V_308 -> V_74 , V_200 ) )
return 0 ;
V_308 -> V_222 . V_246 = 0 ;
V_308 -> V_222 . V_200 = V_200 ;
V_308 -> V_222 . V_247 = F_98 (
F_183 ( V_308 -> V_4 -> V_243 ) ,
V_200 , 0 ) ;
memset ( & V_308 -> V_218 , 0 , sizeof( V_308 -> V_218 ) ) ;
memset ( & V_308 -> V_223 , 0 , sizeof( V_308 -> V_223 ) ) ;
F_100 ( V_308 ) ;
V_61 = F_184 ( V_308 ) ;
if ( V_61 != 0 )
return V_61 ;
V_323 = F_177 ( V_308 ) ;
if ( F_56 ( V_323 ) )
return F_89 ( V_323 ) ;
if ( V_323 != V_308 -> V_74 )
V_61 = - V_324 ;
F_185 ( V_323 , V_200 ) ;
return V_61 ;
}
static int F_186 ( struct V_217 * V_308 , struct V_73 * V_74 )
{
int V_61 ;
F_147 ( V_281 , & V_74 -> V_231 ) ;
F_147 ( V_280 , & V_74 -> V_231 ) ;
F_147 ( V_279 , & V_74 -> V_231 ) ;
F_147 ( V_291 , & V_74 -> V_231 ) ;
F_147 ( V_289 , & V_74 -> V_231 ) ;
F_187 () ;
V_61 = F_182 ( V_308 , V_202 | V_203 ) ;
if ( V_61 != 0 )
return V_61 ;
V_61 = F_182 ( V_308 , V_203 ) ;
if ( V_61 != 0 )
return V_61 ;
V_61 = F_182 ( V_308 , V_202 ) ;
if ( V_61 != 0 )
return V_61 ;
if ( F_38 ( V_291 , & V_74 -> V_231 ) == 0 &&
! F_158 ( & V_74 -> V_50 , & V_74 -> V_290 ) ) {
F_149 ( & V_74 -> V_293 ) ;
if ( F_38 ( V_291 , & V_74 -> V_231 ) == 0 )
F_19 ( & V_74 -> V_50 , & V_74 -> V_290 ) ;
F_151 ( & V_74 -> V_293 ) ;
}
return 0 ;
}
static int F_188 ( struct V_319 * V_320 , struct V_73 * V_74 )
{
struct V_282 * V_283 ;
struct V_217 * V_308 ;
T_6 V_315 = 0 ;
int V_325 ;
V_308 = F_181 ( V_320 , V_74 ,
V_264 ) ;
if ( F_56 ( V_308 ) )
return F_89 ( V_308 ) ;
F_156 () ;
V_283 = F_157 ( F_93 ( V_74 -> V_2 ) -> V_283 ) ;
if ( V_283 != NULL && F_38 ( V_285 , & V_283 -> V_231 ) != 0 )
V_315 = V_283 -> type ;
F_159 () ;
V_308 -> V_222 . V_267 . V_315 = V_315 ;
V_325 = F_186 ( V_308 , V_74 ) ;
F_125 ( V_308 ) ;
return V_325 ;
}
static int F_189 ( struct V_319 * V_320 , struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_188 ( V_320 , V_74 ) ;
F_190 ( V_320 , 0 , V_8 ) ;
if ( F_97 ( V_14 , V_8 , & V_71 ) )
continue;
if ( V_8 != - V_99 )
break;
F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_191 ( struct V_229 * V_230 , struct V_73 * V_74 )
{
struct V_319 * V_320 ;
int V_61 ;
V_320 = F_178 ( V_74 ) ;
if ( F_56 ( V_320 ) )
return - V_118 ;
V_61 = F_189 ( V_320 , V_74 ) ;
F_192 ( V_320 ) ;
return V_61 ;
}
static int F_193 ( struct V_13 * V_14 , struct V_73 * V_74 , const T_4 * V_50 , int V_8 )
{
switch ( V_8 ) {
default:
F_35 ( V_326 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_321 :
case - V_118 :
case - V_324 :
break;
case - V_90 :
case - V_91 :
case - V_92 :
case - V_93 :
case - V_94 :
F_145 ( V_291 , & V_74 -> V_231 ) ;
F_33 ( V_14 -> V_55 -> V_97 , V_8 ) ;
return - V_118 ;
case - V_86 :
case - V_85 :
F_145 ( V_291 , & V_74 -> V_231 ) ;
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
F_145 ( V_291 , & V_74 -> V_231 ) ;
F_194 ( 1 ) ;
return - V_118 ;
case - V_142 :
case - V_327 :
return 0 ;
}
return V_8 ;
}
int F_195 ( struct V_319 * V_320 ,
struct V_73 * V_74 , const T_4 * V_50 ,
T_6 type )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_217 * V_308 ;
int V_8 = 0 ;
V_308 = F_181 ( V_320 , V_74 ,
V_213 ) ;
if ( F_56 ( V_308 ) )
return F_89 ( V_308 ) ;
F_19 ( & V_308 -> V_222 . V_267 . V_283 , V_50 ) ;
F_149 ( & V_74 -> V_293 ) ;
F_19 ( & V_74 -> V_50 , & V_74 -> V_290 ) ;
F_151 ( & V_74 -> V_293 ) ;
F_147 ( V_291 , & V_74 -> V_231 ) ;
switch ( type & ( V_202 | V_203 ) ) {
case V_202 | V_203 :
case V_203 :
V_8 = F_182 ( V_308 , V_202 | V_203 ) ;
if ( V_8 )
break;
V_8 = F_182 ( V_308 , V_203 ) ;
if ( V_8 )
break;
case V_202 :
V_8 = F_182 ( V_308 , V_202 ) ;
}
F_125 ( V_308 ) ;
return F_193 ( V_14 , V_74 , V_50 , V_8 ) ;
}
static void F_196 ( struct V_112 * V_113 , void * V_172 )
{
struct V_217 * V_174 = V_172 ;
F_53 ( V_174 -> V_222 . V_14 -> V_55 -> V_171 ,
& V_174 -> V_224 . V_176 , & V_174 -> V_223 . V_177 , V_113 ) ;
}
static void F_197 ( struct V_112 * V_113 , void * V_172 )
{
struct V_217 * V_174 = V_172 ;
F_63 ( V_113 , & V_174 -> V_223 . V_177 ) ;
V_174 -> V_313 = V_113 -> V_117 ;
if ( V_174 -> V_313 == 0 ) {
F_19 ( & V_174 -> V_218 . V_50 , & V_174 -> V_223 . V_50 ) ;
F_198 ( & V_174 -> V_244 -> V_241 , 0 ) ;
F_49 ( V_174 -> V_218 . V_14 , V_174 -> V_125 ) ;
V_174 -> V_312 = 1 ;
}
}
static void F_199 ( void * V_172 )
{
struct V_217 * V_174 = V_172 ;
struct V_73 * V_74 = NULL ;
if ( V_174 -> V_328 == 0 )
goto V_329;
if ( ! V_174 -> V_312 )
goto V_329;
V_74 = F_177 ( V_174 ) ;
if ( ! F_56 ( V_74 ) )
F_185 ( V_74 , V_174 -> V_222 . V_200 ) ;
V_329:
F_125 ( V_174 ) ;
}
static int F_200 ( struct V_217 * V_174 )
{
struct V_13 * V_14 = F_105 ( F_14 ( V_174 -> V_3 ) ) ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_332 ] ,
. V_333 = & V_174 -> V_224 ,
. V_334 = & V_174 -> V_223 ,
. V_51 = V_174 -> V_244 -> V_301 ,
} ;
struct V_180 V_335 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_336 ,
. V_185 = V_174 ,
. V_337 = V_338 ,
. V_231 = V_339 ,
} ;
int V_325 ;
F_51 ( & V_174 -> V_224 . V_176 , & V_174 -> V_223 . V_177 , 1 ) ;
F_201 ( & V_174 -> V_269 ) ;
V_174 -> V_312 = 0 ;
V_174 -> V_313 = 0 ;
V_174 -> V_125 = V_170 ;
if ( V_174 -> V_310 )
F_52 ( & V_174 -> V_224 . V_176 ) ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_325 = F_127 ( V_113 ) ;
if ( V_325 != 0 ) {
V_174 -> V_328 = 1 ;
F_202 () ;
} else
V_325 = V_174 -> V_313 ;
F_90 ( V_113 ) ;
return V_325 ;
}
static void F_203 ( struct V_112 * V_113 , void * V_172 )
{
struct V_217 * V_174 = V_172 ;
struct V_229 * V_230 = V_174 -> V_244 ;
struct V_55 * V_72 = V_230 -> V_286 -> V_55 ;
enum V_209 V_210 = V_174 -> V_222 . V_210 ;
if ( F_204 ( V_174 -> V_222 . V_221 , V_113 ) != 0 )
goto V_340;
if ( V_174 -> V_74 != NULL ) {
struct V_282 * V_283 ;
if ( F_131 ( V_174 -> V_74 , V_174 -> V_222 . V_200 , V_174 -> V_222 . V_246 ) )
goto V_341;
F_156 () ;
V_283 = F_157 ( F_93 ( V_174 -> V_74 -> V_2 ) -> V_283 ) ;
if ( F_132 ( V_283 , V_174 -> V_222 . V_200 , V_210 ) )
goto V_342;
F_159 () ;
}
V_174 -> V_222 . V_253 = V_72 -> V_254 ;
switch ( V_210 ) {
default:
break;
case V_264 :
case V_213 :
case V_215 :
V_174 -> V_222 . V_261 = & V_343 [ 0 ] ;
case V_211 :
V_113 -> V_344 . V_330 = & V_331 [ V_345 ] ;
F_205 ( & V_174 -> V_218 . V_263 , V_174 -> V_222 . V_263 ) ;
}
V_174 -> V_125 = V_170 ;
if ( F_81 ( V_174 -> V_222 . V_14 ,
& V_174 -> V_222 . V_176 ,
& V_174 -> V_218 . V_177 ,
V_113 ) != 0 )
F_164 ( V_174 -> V_222 . V_221 ) ;
V_174 -> V_222 . V_346 = V_347 ;
if ( V_174 -> V_222 . V_246 & V_248 ) {
V_174 -> V_222 . V_346 = V_348 ;
if ( F_206 ( V_72 ) )
V_174 -> V_222 . V_346 = V_349 ;
else if ( V_72 -> V_56 -> V_350 > 0 )
V_174 -> V_222 . V_346 = V_351 ;
}
return;
V_342:
F_173 ( V_174 -> V_74 ) ;
F_159 () ;
V_341:
V_113 -> V_352 = NULL ;
V_340:
F_78 ( V_113 , & V_174 -> V_218 . V_177 ) ;
}
static void F_207 ( struct V_112 * V_113 , void * V_172 )
{
struct V_217 * V_174 = V_172 ;
V_174 -> V_313 = V_113 -> V_117 ;
if ( ! F_76 ( V_113 , & V_174 -> V_218 . V_177 ) )
return;
if ( V_113 -> V_117 == 0 ) {
if ( V_174 -> V_218 . V_219 -> V_316 & V_353 ) {
switch ( V_174 -> V_218 . V_219 -> V_276 & V_354 ) {
case V_355 :
break;
case V_356 :
V_174 -> V_313 = - V_357 ;
break;
case V_358 :
V_174 -> V_313 = - V_359 ;
break;
default:
V_174 -> V_313 = - V_360 ;
}
}
F_49 ( V_174 -> V_218 . V_14 , V_174 -> V_125 ) ;
if ( ! ( V_174 -> V_218 . V_361 & V_362 ) )
F_198 ( & V_174 -> V_244 -> V_241 , 0 ) ;
}
V_174 -> V_312 = 1 ;
}
static void F_208 ( void * V_172 )
{
struct V_217 * V_174 = V_172 ;
struct V_73 * V_74 = NULL ;
if ( V_174 -> V_328 == 0 )
goto V_329;
if ( V_174 -> V_313 != 0 || ! V_174 -> V_312 )
goto V_329;
if ( V_174 -> V_218 . V_361 & V_362 )
goto V_329;
V_74 = F_177 ( V_174 ) ;
if ( ! F_56 ( V_74 ) )
F_185 ( V_74 , V_174 -> V_222 . V_200 ) ;
V_329:
F_125 ( V_174 ) ;
}
static int F_209 ( struct V_217 * V_174 , int V_363 )
{
struct V_2 * V_3 = F_14 ( V_174 -> V_3 ) ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_364 * V_222 = & V_174 -> V_222 ;
struct V_365 * V_218 = & V_174 -> V_218 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_366 ] ,
. V_333 = V_222 ,
. V_334 = V_218 ,
. V_51 = V_174 -> V_244 -> V_301 ,
} ;
struct V_180 V_335 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_367 ,
. V_185 = V_174 ,
. V_337 = V_338 ,
. V_231 = V_339 ,
} ;
int V_325 ;
F_51 ( & V_222 -> V_176 , & V_218 -> V_177 , 1 ) ;
F_201 ( & V_174 -> V_269 ) ;
V_174 -> V_312 = 0 ;
V_174 -> V_313 = 0 ;
V_174 -> V_328 = 0 ;
V_174 -> V_310 = 0 ;
if ( V_363 ) {
F_52 ( & V_222 -> V_176 ) ;
V_174 -> V_310 = 1 ;
}
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_325 = F_127 ( V_113 ) ;
if ( V_325 != 0 ) {
V_174 -> V_328 = 1 ;
F_202 () ;
} else
V_325 = V_174 -> V_313 ;
F_90 ( V_113 ) ;
return V_325 ;
}
static int F_184 ( struct V_217 * V_174 )
{
struct V_2 * V_3 = F_14 ( V_174 -> V_3 ) ;
struct V_365 * V_218 = & V_174 -> V_218 ;
int V_325 ;
V_325 = F_209 ( V_174 , 1 ) ;
if ( V_325 != 0 || ! V_174 -> V_312 )
return V_325 ;
F_210 ( F_105 ( V_3 ) , & V_174 -> V_219 ) ;
if ( V_218 -> V_361 & V_362 ) {
V_325 = F_200 ( V_174 ) ;
if ( V_325 != 0 )
return V_325 ;
}
return V_325 ;
}
static int F_211 ( struct V_51 * V_52 ,
struct V_217 * V_308 ,
struct V_73 * V_74 , T_6 V_200 ,
int V_201 )
{
struct V_368 V_369 ;
T_1 V_370 ;
if ( V_308 -> V_218 . V_371 == 0 )
return 0 ;
V_370 = 0 ;
if ( V_201 & V_372 ) {
V_370 = V_373 ;
} else if ( ( V_200 & V_202 ) && ! V_308 -> V_374 )
V_370 = V_375 ;
V_369 . V_52 = V_52 ;
V_369 . V_170 = V_170 ;
F_212 ( & V_369 , V_308 -> V_218 . V_376 ) ;
F_213 ( V_74 -> V_2 , & V_369 ) ;
if ( ( V_370 & ~ V_369 . V_370 & ( V_375 | V_373 ) ) == 0 )
return 0 ;
F_185 ( V_74 , V_200 ) ;
return - V_29 ;
}
static int F_214 ( struct V_217 * V_174 )
{
struct V_2 * V_3 = F_14 ( V_174 -> V_3 ) ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_364 * V_222 = & V_174 -> V_222 ;
struct V_365 * V_218 = & V_174 -> V_218 ;
int V_325 ;
V_325 = F_209 ( V_174 , 0 ) ;
if ( ! V_174 -> V_312 )
return V_325 ;
if ( V_325 != 0 ) {
if ( V_325 == - V_26 &&
! ( V_222 -> V_246 & V_377 ) )
return - V_321 ;
return V_325 ;
}
F_210 ( V_14 , & V_174 -> V_219 ) ;
if ( V_222 -> V_246 & V_377 ) {
F_92 ( V_3 , & V_218 -> V_187 ) ;
if ( V_222 -> V_246 & V_248 )
V_174 -> V_374 = 1 ;
else if ( V_218 -> V_187 . V_195 != V_218 -> V_187 . V_197 )
V_174 -> V_374 = 1 ;
}
if ( ( V_218 -> V_361 & V_378 ) == 0 )
V_14 -> V_104 &= ~ V_379 ;
if( V_218 -> V_361 & V_362 ) {
V_325 = F_200 ( V_174 ) ;
if ( V_325 != 0 )
return V_325 ;
}
if ( ! ( V_218 -> V_219 -> V_316 & V_317 ) )
F_215 ( V_14 , & V_218 -> V_263 , V_218 -> V_219 , V_218 -> V_220 ) ;
return 0 ;
}
static int F_216 ( struct V_13 * V_14 )
{
return F_217 ( V_14 -> V_55 ) ;
}
static int F_218 ( struct V_319 * V_320 , struct V_73 * V_74 )
{
struct V_217 * V_308 ;
int V_61 ;
V_308 = F_181 ( V_320 , V_74 ,
V_211 ) ;
if ( F_56 ( V_308 ) )
return F_89 ( V_308 ) ;
V_61 = F_186 ( V_308 , V_74 ) ;
if ( V_61 == - V_324 )
F_219 ( V_320 -> V_4 ) ;
F_125 ( V_308 ) ;
return V_61 ;
}
static int F_220 ( struct V_319 * V_320 , struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_218 ( V_320 , V_74 ) ;
F_221 ( V_320 , 0 , V_8 ) ;
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
static int F_222 ( struct V_229 * V_230 , struct V_73 * V_74 )
{
struct V_319 * V_320 ;
int V_61 ;
V_320 = F_178 ( V_74 ) ;
if ( F_56 ( V_320 ) )
return - V_118 ;
V_61 = F_220 ( V_320 , V_74 ) ;
F_192 ( V_320 ) ;
return V_61 ;
}
static void F_223 ( struct V_73 * V_74 ,
const T_4 * V_50 )
{
F_224 ( V_74 -> V_2 , V_50 ) ;
F_149 ( & V_74 -> V_293 ) ;
F_19 ( & V_74 -> V_50 , & V_74 -> V_290 ) ;
F_151 ( & V_74 -> V_293 ) ;
F_147 ( V_291 , & V_74 -> V_231 ) ;
}
static void F_225 ( struct V_73 * V_74 )
{
if ( F_226 ( F_93 ( V_74 -> V_2 ) -> V_283 ) != NULL )
F_223 ( V_74 , NULL ) ;
}
static int F_227 ( struct V_229 * V_230 , struct V_73 * V_74 )
{
F_225 ( V_74 ) ;
return F_222 ( V_230 , V_74 ) ;
}
static int F_228 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
return - V_81 ;
}
static int F_229 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
int V_325 ;
switch ( V_50 -> type ) {
default:
break;
case V_380 :
case V_381 :
return - V_81 ;
case V_58 :
goto V_329;
}
V_325 = F_230 ( V_14 , V_50 , V_52 ) ;
switch ( V_325 ) {
case - V_80 :
case - V_79 :
case - V_78 :
break;
default:
return V_325 ;
}
V_329:
F_231 ( V_14 , V_50 , V_52 , true ) ;
return - V_80 ;
}
static void F_232 ( struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
T_4 V_50 ;
struct V_282 * V_283 ;
struct V_51 * V_52 ;
int V_325 ;
F_156 () ;
V_283 = F_157 ( F_93 ( V_74 -> V_2 ) -> V_283 ) ;
if ( V_283 == NULL ) {
F_159 () ;
return;
}
F_19 ( & V_50 , & V_283 -> V_50 ) ;
if ( F_38 ( V_382 , & V_283 -> V_231 ) ) {
F_159 () ;
F_223 ( V_74 , & V_50 ) ;
return;
}
if ( ! F_138 ( V_383 , & V_283 -> V_231 ) ) {
F_159 () ;
return;
}
V_52 = F_233 ( V_283 -> V_52 ) ;
F_159 () ;
V_325 = F_229 ( V_14 , & V_50 , V_52 ) ;
F_234 ( V_74 , NULL , V_325 ) ;
if ( V_325 == - V_80 || V_325 == - V_81 )
F_223 ( V_74 , & V_50 ) ;
F_235 ( V_52 ) ;
}
static int F_236 ( struct V_73 * V_74 )
{
int V_325 , V_61 = V_384 ;
struct V_302 * V_303 , * V_385 = NULL ;
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
if ( ! F_38 ( V_386 , & V_74 -> V_231 ) )
goto V_160;
F_46 ( & V_74 -> V_305 ) ;
F_179 (lsp, &state->lock_states, ls_locks) {
if ( F_38 ( V_387 , & V_303 -> V_388 ) ) {
struct V_51 * V_52 = V_303 -> V_304 -> V_244 -> V_301 ;
F_110 ( & V_303 -> V_389 ) ;
F_48 ( & V_74 -> V_305 ) ;
F_237 ( V_385 ) ;
V_385 = V_303 ;
V_325 = F_229 ( V_14 ,
& V_303 -> V_306 ,
V_52 ) ;
F_238 ( V_74 , V_303 , V_325 ) ;
if ( V_325 == - V_80 ||
V_325 == - V_81 ) {
F_147 ( V_387 , & V_303 -> V_388 ) ;
V_303 -> V_306 . type = V_380 ;
if ( ! V_390 )
F_145 ( V_391 , & V_303 -> V_388 ) ;
} else if ( V_325 != V_384 ) {
V_61 = V_325 ;
F_237 ( V_385 ) ;
goto V_160;
}
F_46 ( & V_74 -> V_305 ) ;
}
}
F_48 ( & V_74 -> V_305 ) ;
F_237 ( V_385 ) ;
V_160:
return V_61 ;
}
static int F_239 ( struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
T_4 * V_50 = & V_74 -> V_290 ;
struct V_51 * V_52 = V_74 -> V_244 -> V_301 ;
int V_325 ;
if ( F_38 ( V_289 , & V_74 -> V_231 ) == 0 ) {
if ( F_38 ( V_291 , & V_74 -> V_231 ) == 0 ) {
if ( F_240 ( V_74 -> V_2 , V_74 -> V_74 ) )
return V_384 ;
return - V_83 ;
}
return - V_81 ;
}
V_325 = F_229 ( V_14 , V_50 , V_52 ) ;
F_241 ( V_74 , NULL , V_325 ) ;
if ( V_325 == - V_80 || V_325 == - V_81 ) {
F_147 ( V_279 , & V_74 -> V_231 ) ;
F_147 ( V_280 , & V_74 -> V_231 ) ;
F_147 ( V_281 , & V_74 -> V_231 ) ;
F_147 ( V_289 , & V_74 -> V_231 ) ;
V_50 -> type = V_380 ;
}
if ( V_325 != V_384 )
return V_325 ;
if ( F_136 ( V_74 ) )
return - V_83 ;
return V_384 ;
}
static int F_242 ( struct V_229 * V_230 , struct V_73 * V_74 )
{
int V_325 ;
F_232 ( V_74 ) ;
V_325 = F_236 ( V_74 ) ;
if ( V_325 != V_384 )
return V_325 ;
V_325 = F_239 ( V_74 ) ;
if ( V_325 != V_384 )
V_325 = F_222 ( V_230 , V_74 ) ;
return V_325 ;
}
static inline void F_243 ( struct V_217 * V_308 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_392 = V_308 -> V_218 . V_392 ;
if ( ( V_392 [ 1 ] & V_393 ) &&
! ( V_6 -> V_265 & V_394 ) )
V_6 -> V_265 |= V_395 ;
if ( ( V_392 [ 1 ] & V_396 ) &&
! ( V_6 -> V_265 & V_397 ) )
V_6 -> V_265 |= V_398 ;
if ( ( V_392 [ 1 ] & V_399 ) )
V_6 -> V_265 &= ~ V_400 ;
if ( V_392 [ 2 ] & V_401 )
* V_7 = NULL ;
}
static int F_244 ( struct V_217 * V_308 ,
T_6 V_200 ,
int V_231 ,
struct V_319 * V_320 )
{
struct V_229 * V_230 = V_308 -> V_244 ;
struct V_13 * V_14 = V_230 -> V_286 ;
struct V_4 * V_4 ;
struct V_73 * V_74 ;
unsigned int V_402 ;
int V_61 ;
V_402 = F_245 ( & V_230 -> V_403 ) ;
V_61 = F_214 ( V_308 ) ;
if ( V_61 != 0 )
goto V_160;
V_74 = F_177 ( V_308 ) ;
V_61 = F_89 ( V_74 ) ;
if ( F_56 ( V_74 ) )
goto V_160;
if ( V_14 -> V_104 & V_379 )
F_145 ( V_404 , & V_74 -> V_231 ) ;
if ( V_308 -> V_218 . V_361 & V_405 )
F_145 ( V_406 , & V_74 -> V_231 ) ;
V_4 = V_308 -> V_4 ;
if ( F_246 ( V_4 ) ) {
struct V_4 * V_407 ;
F_219 ( V_4 ) ;
V_407 = F_247 ( V_4 , V_74 -> V_2 ) ;
if ( ! V_407 )
V_407 = F_248 ( F_249 ( V_74 -> V_2 ) , V_4 ) ;
if ( V_407 ) {
F_117 ( V_320 -> V_4 ) ;
V_320 -> V_4 = V_4 = V_407 ;
}
F_250 ( V_4 ,
F_251 ( F_14 ( V_308 -> V_3 ) ) ) ;
}
V_61 = F_211 ( V_230 -> V_301 , V_308 , V_74 , V_200 , V_231 ) ;
if ( V_61 != 0 )
goto V_160;
V_320 -> V_74 = V_74 ;
if ( F_14 ( V_4 ) == V_74 -> V_2 ) {
F_252 ( V_320 ) ;
if ( F_253 ( & V_230 -> V_403 , V_402 ) )
F_28 ( V_14 , V_74 ) ;
}
V_160:
return V_61 ;
}
static int F_254 ( struct V_2 * V_3 ,
struct V_319 * V_320 ,
int V_231 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_408 )
{
struct V_229 * V_230 ;
struct V_73 * V_74 = NULL ;
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_217 * V_308 ;
struct V_4 * V_4 = V_320 -> V_4 ;
struct V_51 * V_52 = V_320 -> V_52 ;
struct V_409 * * V_410 = & V_320 -> V_272 ;
T_6 V_200 = V_320 -> V_276 & ( V_202 | V_203 | V_411 ) ;
enum V_209 V_210 = V_212 ;
struct V_1 * V_412 = NULL ;
int V_325 ;
V_325 = - V_142 ;
V_230 = F_255 ( V_14 , V_52 , V_413 ) ;
if ( V_230 == NULL ) {
F_8 ( L_23 ) ;
goto V_414;
}
V_325 = F_216 ( V_14 ) ;
if ( V_325 != 0 )
goto V_415;
if ( F_256 ( V_4 ) )
F_161 ( F_14 ( V_4 ) , V_200 ) ;
V_325 = - V_142 ;
if ( F_256 ( V_4 ) )
V_210 = V_211 ;
V_308 = F_103 ( V_4 , V_230 , V_200 , V_231 , V_6 ,
V_7 , V_210 , V_413 ) ;
if ( V_308 == NULL )
goto V_415;
if ( V_7 ) {
V_412 = F_107 ( V_14 , V_413 ) ;
if ( F_56 ( V_412 ) ) {
V_325 = F_89 ( V_412 ) ;
goto V_416;
}
}
if ( V_14 -> V_15 [ 2 ] & V_417 ) {
if ( ! V_308 -> V_219 . V_272 ) {
V_308 -> V_219 . V_272 = F_257 () ;
if ( ! V_308 -> V_219 . V_272 )
goto V_242;
}
V_308 -> V_222 . V_261 = & V_418 [ 0 ] ;
}
if ( F_256 ( V_4 ) )
V_308 -> V_74 = F_175 ( F_14 ( V_4 ) , V_230 ) ;
V_325 = F_244 ( V_308 , V_200 , V_231 , V_320 ) ;
if ( V_325 != 0 )
goto V_242;
V_74 = V_320 -> V_74 ;
if ( ( V_308 -> V_222 . V_246 & ( V_377 | V_248 ) ) == ( V_377 | V_248 ) &&
( V_308 -> V_222 . V_346 != V_349 ) ) {
F_243 ( V_308 , V_6 , & V_7 ) ;
if ( V_6 -> V_265 & V_419 ) {
F_101 ( V_308 -> V_218 . V_219 ) ;
V_325 = F_258 ( V_74 -> V_2 , V_52 ,
V_308 -> V_218 . V_219 , V_6 ,
V_74 , V_7 , V_412 ) ;
if ( V_325 == 0 ) {
F_259 ( V_74 -> V_2 , V_6 ,
V_308 -> V_218 . V_219 ) ;
F_260 ( V_74 -> V_2 , V_308 -> V_218 . V_219 , V_412 ) ;
}
}
}
if ( V_408 && V_308 -> V_374 )
* V_408 |= V_420 ;
if ( F_261 ( V_410 , V_308 -> V_219 . V_272 , V_14 ) ) {
* V_410 = V_308 -> V_219 . V_272 ;
V_308 -> V_219 . V_272 = NULL ;
}
F_115 ( V_412 ) ;
F_125 ( V_308 ) ;
F_122 ( V_230 ) ;
return 0 ;
V_242:
F_115 ( V_412 ) ;
V_416:
F_125 ( V_308 ) ;
V_415:
F_122 ( V_230 ) ;
V_414:
return V_325 ;
}
static struct V_73 * F_262 ( struct V_2 * V_3 ,
struct V_319 * V_320 ,
int V_231 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_408 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_70 V_71 = { } ;
struct V_73 * V_66 ;
int V_325 ;
do {
V_325 = F_254 ( V_3 , V_320 , V_231 , V_6 , V_7 , V_408 ) ;
V_66 = V_320 -> V_74 ;
F_263 ( V_320 , V_231 , V_325 ) ;
if ( V_325 == 0 )
break;
if ( V_325 == - V_421 ) {
F_264 ( L_5
L_24 ,
F_105 ( V_3 ) -> V_55 -> V_107 ) ;
V_71 . V_77 = 1 ;
continue;
}
if ( V_325 == - V_81 ) {
V_71 . V_77 = 1 ;
continue;
}
if ( V_325 == - V_118 ) {
V_71 . V_77 = 1 ;
continue;
}
if ( F_97 ( V_14 , V_325 , & V_71 ) )
continue;
V_66 = F_57 ( F_36 ( V_14 ,
V_325 , & V_71 ) ) ;
} while ( V_71 . V_77 );
return V_66 ;
}
static int F_265 ( struct V_2 * V_2 ,
struct V_422 * V_423 ,
struct V_424 * V_66 ,
struct V_51 * V_52 ,
struct V_73 * V_74 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_425 ] ,
. V_333 = V_423 ,
. V_334 = V_66 ,
. V_51 = V_52 ,
} ;
struct V_51 * V_426 = NULL ;
unsigned long V_125 = V_170 ;
T_6 V_200 ;
bool V_427 ;
int V_325 ;
F_101 ( V_66 -> V_428 ) ;
V_427 = ( V_423 -> V_429 -> V_265 & V_430 ) ? true : false ;
V_200 = V_427 ? V_203 : V_202 ;
if ( F_266 ( V_2 , V_200 , & V_423 -> V_50 , & V_426 ) ) {
} else if ( V_427 && V_74 != NULL ) {
struct V_431 V_432 = {
. V_433 = V_67 -> V_434 ,
. V_435 = V_67 -> V_436 ,
} ;
if ( ! F_267 ( V_74 ) )
return - V_437 ;
if ( F_268 ( V_74 , V_203 , & V_432 ,
& V_423 -> V_50 , & V_426 ) == - V_35 )
return - V_437 ;
} else
F_19 ( & V_423 -> V_50 , & V_438 ) ;
if ( V_426 )
V_179 . V_51 = V_426 ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_423 -> V_176 , & V_66 -> V_177 , 1 ) ;
F_235 ( V_426 ) ;
if ( V_325 == 0 && V_74 != NULL )
F_49 ( V_14 , V_125 ) ;
F_269 ( V_2 , & V_423 -> V_50 , V_325 ) ;
return V_325 ;
}
static int F_258 ( struct V_2 * V_2 , struct V_51 * V_52 ,
struct V_439 * V_428 , struct V_5 * V_6 ,
struct V_73 * V_74 , struct V_1 * V_440 ,
struct V_1 * V_412 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_422 V_423 = {
. V_263 = F_113 ( V_2 ) ,
. V_429 = V_6 ,
. V_14 = V_14 ,
. V_260 = V_14 -> V_15 ,
. V_7 = V_440 ,
} ;
struct V_424 V_66 = {
. V_428 = V_428 ,
. V_7 = V_412 ,
. V_14 = V_14 ,
} ;
struct V_70 V_71 = {
. V_74 = V_74 ,
. V_2 = V_2 ,
. V_50 = & V_423 . V_50 ,
} ;
int V_8 ;
V_423 . V_260 = F_6 ( V_14 , V_440 ) ;
if ( V_440 )
V_423 . V_260 = F_6 ( V_14 , V_412 ) ;
do {
V_8 = F_265 ( V_2 , & V_423 , & V_66 , V_52 , V_74 ) ;
switch ( V_8 ) {
case - V_83 :
if ( ! ( V_6 -> V_265 & V_430 ) ) {
F_270 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_55 -> V_107 ) ;
}
if ( V_74 && ! ( V_74 -> V_74 & V_203 ) ) {
V_8 = - V_437 ;
if ( V_6 -> V_265 & V_441 )
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
F_271 ( struct V_2 * V_2 , struct V_112 * V_113 )
{
if ( V_2 == NULL || ! F_272 ( V_2 ) )
return false ;
return F_273 ( V_2 , V_113 ) ;
}
static void F_274 ( void * V_174 )
{
struct V_442 * V_172 = V_174 ;
struct V_229 * V_230 = V_172 -> V_74 -> V_244 ;
struct V_270 * V_271 = V_172 -> V_74 -> V_2 -> V_443 ;
if ( V_172 -> V_444 )
F_275 ( V_172 -> V_74 -> V_2 ) ;
F_121 ( V_172 -> V_74 ) ;
F_120 ( V_172 -> V_423 . V_221 ) ;
F_122 ( V_230 ) ;
F_123 ( V_271 ) ;
F_116 ( V_172 ) ;
}
static void F_276 ( struct V_112 * V_113 , void * V_174 )
{
struct V_442 * V_172 = V_174 ;
struct V_73 * V_74 = V_172 -> V_74 ;
struct V_13 * V_14 = F_105 ( V_172 -> V_2 ) ;
T_4 * V_445 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_78 ( V_113 , & V_172 -> V_66 . V_177 ) )
return;
F_277 ( V_74 , & V_172 -> V_423 , & V_172 -> V_66 , V_113 -> V_117 ) ;
switch ( V_113 -> V_117 ) {
case 0 :
V_445 = & V_172 -> V_66 . V_50 ;
if ( V_172 -> V_444 )
F_278 ( V_74 -> V_2 ,
V_172 -> V_446 ) ;
F_49 ( V_14 , V_172 -> V_125 ) ;
break;
case - V_79 :
case - V_85 :
case - V_80 :
F_18 ( V_14 ,
& V_172 -> V_423 . V_50 ,
V_113 -> V_344 . V_51 ) ;
case - V_103 :
case - V_81 :
if ( ! F_158 ( & V_172 -> V_423 . V_50 ,
& V_74 -> V_290 ) ) {
F_73 ( V_113 ) ;
goto V_447;
}
if ( V_172 -> V_423 . V_200 == 0 )
break;
default:
if ( F_43 ( V_113 , V_14 , V_74 , NULL ) == - V_118 ) {
F_73 ( V_113 ) ;
goto V_447;
}
}
F_148 ( V_74 , & V_172 -> V_423 . V_50 ,
V_445 , V_172 -> V_423 . V_200 ) ;
V_447:
F_164 ( V_172 -> V_423 . V_221 ) ;
F_171 ( V_172 -> V_2 , V_172 -> V_66 . V_428 ) ;
F_8 ( L_30 , V_34 , V_113 -> V_117 ) ;
}
static void F_279 ( struct V_112 * V_113 , void * V_174 )
{
struct V_442 * V_172 = V_174 ;
struct V_73 * V_74 = V_172 -> V_74 ;
struct V_2 * V_2 = V_172 -> V_2 ;
bool V_448 , V_449 , V_450 ;
int V_451 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_204 ( V_172 -> V_423 . V_221 , V_113 ) != 0 )
goto V_340;
V_113 -> V_344 . V_330 = & V_331 [ V_452 ] ;
F_46 ( & V_74 -> V_244 -> V_296 ) ;
V_450 = F_38 ( V_281 , & V_74 -> V_231 ) ;
V_448 = F_38 ( V_279 , & V_74 -> V_231 ) ;
V_449 = F_38 ( V_280 , & V_74 -> V_231 ) ;
F_19 ( & V_172 -> V_423 . V_50 , & V_74 -> V_290 ) ;
V_172 -> V_423 . V_200 = 0 ;
if ( V_74 -> V_273 == 0 ) {
if ( V_74 -> V_275 == 0 )
V_451 |= V_448 ;
else if ( V_448 )
V_172 -> V_423 . V_200 |= V_202 ;
if ( V_74 -> V_274 == 0 )
V_451 |= V_449 ;
else if ( V_449 )
V_172 -> V_423 . V_200 |= V_203 ;
if ( V_172 -> V_423 . V_200 != ( V_202 | V_203 ) )
V_451 |= V_450 ;
} else if ( V_450 )
V_172 -> V_423 . V_200 |= V_202 | V_203 ;
if ( ! F_267 ( V_74 ) ||
F_38 ( V_289 , & V_74 -> V_231 ) == 0 )
V_451 = 0 ;
F_48 ( & V_74 -> V_244 -> V_296 ) ;
if ( ! V_451 ) {
goto V_341;
}
if ( F_271 ( V_2 , V_113 ) ) {
F_164 ( V_172 -> V_423 . V_221 ) ;
goto V_340;
}
if ( V_172 -> V_423 . V_200 == 0 )
V_113 -> V_344 . V_330 = & V_331 [ V_453 ] ;
if ( V_172 -> V_444 )
F_280 ( V_2 , & V_172 -> V_446 ) ;
V_172 -> V_423 . V_247 =
F_98 ( F_105 ( V_2 ) ,
V_172 -> V_423 . V_200 , 0 ) ;
F_101 ( V_172 -> V_66 . V_428 ) ;
V_172 -> V_125 = V_170 ;
if ( F_81 ( F_105 ( V_2 ) ,
& V_172 -> V_423 . V_176 ,
& V_172 -> V_66 . V_177 ,
V_113 ) != 0 )
F_164 ( V_172 -> V_423 . V_221 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_341:
V_113 -> V_352 = NULL ;
V_340:
F_78 ( V_113 , & V_172 -> V_66 . V_177 ) ;
}
static bool F_281 ( struct V_2 * V_2 )
{
if ( ! F_272 ( V_2 ) )
return false ;
return F_282 ( V_2 ) ;
}
int F_283 ( struct V_73 * V_74 , T_7 V_233 , int V_454 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_235 * ( * V_236 ) ( struct V_237 * , T_7 ) ;
struct V_442 * V_172 ;
struct V_229 * V_230 = V_74 -> V_244 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_453 ] ,
. V_51 = V_74 -> V_244 -> V_301 ,
} ;
struct V_180 V_335 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_455 ,
. V_337 = V_338 ,
. V_231 = V_339 ,
} ;
int V_325 = - V_142 ;
F_284 ( V_14 -> V_55 , V_456 ,
& V_335 . V_182 , & V_179 ) ;
V_172 = F_106 ( sizeof( * V_172 ) , V_233 ) ;
if ( V_172 == NULL )
goto V_160;
F_51 ( & V_172 -> V_423 . V_176 , & V_172 -> V_66 . V_177 , 1 ) ;
V_172 -> V_2 = V_74 -> V_2 ;
V_172 -> V_74 = V_74 ;
V_172 -> V_423 . V_263 = F_113 ( V_74 -> V_2 ) ;
V_236 = V_14 -> V_55 -> V_56 -> V_236 ;
V_172 -> V_423 . V_221 = V_236 ( & V_74 -> V_244 -> V_241 , V_233 ) ;
if ( F_56 ( V_172 -> V_423 . V_221 ) )
goto V_457;
V_172 -> V_423 . V_200 = 0 ;
V_172 -> V_423 . V_260 = V_14 -> V_458 ;
V_172 -> V_66 . V_428 = & V_172 -> V_428 ;
V_172 -> V_66 . V_221 = V_172 -> V_423 . V_221 ;
V_172 -> V_66 . V_14 = V_14 ;
V_172 -> V_444 = F_281 ( V_74 -> V_2 ) ;
F_108 ( V_172 -> V_2 -> V_443 ) ;
V_179 . V_333 = & V_172 -> V_423 ;
V_179 . V_334 = & V_172 -> V_66 ;
V_335 . V_185 = V_172 ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_325 = 0 ;
if ( V_454 )
V_325 = F_128 ( V_113 ) ;
F_90 ( V_113 ) ;
return V_325 ;
V_457:
F_116 ( V_172 ) ;
V_160:
F_121 ( V_74 ) ;
F_122 ( V_230 ) ;
return V_325 ;
}
static struct V_2 *
F_285 ( struct V_2 * V_3 , struct V_319 * V_320 ,
int V_246 , struct V_5 * V_459 , int * V_408 )
{
struct V_73 * V_74 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_320 -> V_4 , V_459 , & V_17 ) ;
V_74 = F_262 ( V_3 , V_320 , V_246 , V_459 , V_7 , V_408 ) ;
F_4 ( V_7 ) ;
if ( F_56 ( V_74 ) )
return F_286 ( V_74 ) ;
return V_74 -> V_2 ;
}
static void F_287 ( struct V_319 * V_320 , int V_460 )
{
if ( V_320 -> V_74 == NULL )
return;
if ( V_460 )
F_288 ( V_320 -> V_74 , V_320 -> V_276 ) ;
else
F_185 ( V_320 -> V_74 , V_320 -> V_276 ) ;
}
static int F_289 ( struct V_13 * V_14 , struct V_461 * V_462 )
{
T_1 V_260 [ 3 ] = {} , V_463 = V_14 -> V_55 -> V_464 ;
struct V_465 args = {
. V_462 = V_462 ,
. V_260 = V_260 ,
} ;
struct V_466 V_66 = {} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_467 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
int V_325 ;
V_260 [ 0 ] = V_468 |
V_469 |
V_470 |
V_471 |
V_472 ;
if ( V_463 )
V_260 [ 2 ] = V_473 ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_325 == 0 ) {
switch ( V_463 ) {
case 0 :
V_66 . V_15 [ 1 ] &= V_474 ;
V_66 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_66 . V_15 [ 2 ] &= V_475 ;
break;
case 2 :
V_66 . V_15 [ 2 ] &= V_476 ;
}
memcpy ( V_14 -> V_15 , V_66 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_104 &= ~ ( V_477 | V_478 |
V_479 | V_480 |
V_481 | V_482 | V_483 |
V_484 | V_485 |
V_486 | V_487 |
V_9 ) ;
if ( V_66 . V_15 [ 0 ] & V_488 &&
V_66 . V_489 & V_490 )
V_14 -> V_104 |= V_477 ;
if ( V_66 . V_491 != 0 )
V_14 -> V_104 |= V_478 ;
if ( V_66 . V_492 != 0 )
V_14 -> V_104 |= V_479 ;
if ( V_66 . V_15 [ 0 ] & V_45 )
V_14 -> V_104 |= V_480 ;
if ( V_66 . V_15 [ 1 ] & V_399 )
V_14 -> V_104 |= V_481 ;
if ( V_66 . V_15 [ 1 ] & V_493 )
V_14 -> V_104 |= V_482 ;
if ( V_66 . V_15 [ 1 ] & V_494 )
V_14 -> V_104 |= V_483 ;
if ( V_66 . V_15 [ 1 ] & V_495 )
V_14 -> V_104 |= V_484 ;
if ( V_66 . V_15 [ 1 ] & V_393 )
V_14 -> V_104 |= V_485 ;
if ( V_66 . V_15 [ 1 ] & V_496 )
V_14 -> V_104 |= V_486 ;
if ( V_66 . V_15 [ 1 ] & V_396 )
V_14 -> V_104 |= V_487 ;
#ifdef F_290
if ( V_66 . V_15 [ 2 ] & V_401 )
V_14 -> V_104 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_66 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_401 ;
memcpy ( V_14 -> V_458 , V_66 . V_15 , sizeof( V_14 -> V_458 ) ) ;
V_14 -> V_458 [ 0 ] &= V_497 | V_498 ;
V_14 -> V_458 [ 1 ] &= V_496 | V_396 ;
V_14 -> V_458 [ 2 ] = 0 ;
memcpy ( V_14 -> V_499 , V_66 . V_499 ,
sizeof( V_14 -> V_499 ) ) ;
V_14 -> V_489 = V_66 . V_489 ;
V_14 -> V_500 = V_66 . V_500 ;
}
return V_325 ;
}
int F_291 ( struct V_13 * V_14 , struct V_461 * V_462 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_289 ( V_14 , V_462 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_292 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 )
{
T_1 V_260 [ 3 ] ;
struct V_503 args = {
. V_260 = V_260 ,
} ;
struct V_504 V_66 = {
. V_14 = V_14 ,
. V_428 = V_502 -> V_428 ,
. V_263 = V_462 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_505 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
V_260 [ 0 ] = V_262 [ 0 ] ;
V_260 [ 1 ] = V_262 [ 1 ] ;
V_260 [ 2 ] = V_262 [ 2 ] & ~ V_401 ;
F_101 ( V_502 -> V_428 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_293 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_292 ( V_14 , V_462 , V_502 ) ;
F_294 ( V_14 , V_462 , V_502 -> V_428 , V_8 ) ;
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
static int F_295 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 , T_5 V_119 )
{
struct V_506 V_507 = {
. V_508 = V_119 ,
} ;
struct V_509 * V_510 ;
int V_61 ;
V_510 = F_296 ( & V_507 , V_14 -> V_108 ) ;
if ( F_56 ( V_510 ) ) {
V_61 = - V_29 ;
goto V_160;
}
V_61 = F_293 ( V_14 , V_462 , V_502 ) ;
V_160:
return V_61 ;
}
static int F_297 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 )
{
static const T_5 V_511 [] = {
V_124 ,
V_123 ,
V_512 ,
V_513 ,
V_514 ,
} ;
int V_325 = - V_24 ;
T_9 V_515 ;
if ( V_14 -> V_516 . V_517 > 0 ) {
for ( V_515 = 0 ; V_515 < V_14 -> V_516 . V_517 ; V_515 ++ ) {
V_325 = F_295 ( V_14 , V_462 , V_502 ,
V_14 -> V_516 . V_518 [ V_515 ] ) ;
if ( V_325 == - V_22 || V_325 == - V_29 )
continue;
break;
}
} else {
for ( V_515 = 0 ; V_515 < F_298 ( V_511 ) ; V_515 ++ ) {
V_325 = F_295 ( V_14 , V_462 , V_502 ,
V_511 [ V_515 ] ) ;
if ( V_325 == - V_22 || V_325 == - V_29 )
continue;
break;
}
}
if ( V_325 == - V_29 )
V_325 = - V_24 ;
return V_325 ;
}
int F_299 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 ,
bool V_519 )
{
int V_325 = 0 ;
if ( ! V_519 )
V_325 = F_293 ( V_14 , V_462 , V_502 ) ;
if ( V_519 || V_325 == V_22 )
V_325 = V_14 -> V_55 -> V_56 -> V_520 ( V_14 ,
V_462 , V_502 ) ;
if ( V_325 == 0 )
V_325 = F_291 ( V_14 , V_462 ) ;
if ( V_325 == 0 )
V_325 = F_300 ( V_14 , V_462 , V_502 ) ;
return F_7 ( V_325 ) ;
}
static int F_301 ( struct V_13 * V_14 , struct V_461 * V_521 ,
struct V_501 * V_502 )
{
int error ;
struct V_439 * V_428 = V_502 -> V_428 ;
struct V_1 * V_7 = NULL ;
error = F_291 ( V_14 , V_521 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_107 ( V_14 , V_413 ) ;
if ( F_56 ( V_7 ) )
return F_89 ( V_7 ) ;
error = F_215 ( V_14 , V_521 , V_428 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_242;
}
if ( V_428 -> V_316 & V_522 &&
! F_302 ( & V_14 -> V_523 , & V_428 -> V_523 ) )
memcpy ( & V_14 -> V_523 , & V_428 -> V_523 , sizeof( V_14 -> V_523 ) ) ;
V_242:
F_115 ( V_7 ) ;
return error ;
}
static int F_303 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_524 * V_259 , struct V_439 * V_428 ,
struct V_461 * V_462 )
{
int V_325 = - V_142 ;
struct V_525 * V_525 = NULL ;
struct V_526 * V_527 = NULL ;
V_525 = F_304 ( V_413 ) ;
if ( V_525 == NULL )
goto V_160;
V_527 = F_305 ( sizeof( struct V_526 ) , V_413 ) ;
if ( V_527 == NULL )
goto V_160;
V_325 = F_306 ( V_108 , V_3 , V_259 , V_527 , V_525 ) ;
if ( V_325 != 0 )
goto V_160;
if ( F_302 ( & F_105 ( V_3 ) -> V_523 , & V_527 -> V_428 . V_523 ) ) {
F_8 ( L_34
L_35 , V_34 , V_259 -> V_259 ) ;
V_325 = - V_87 ;
goto V_160;
}
F_307 ( & V_527 -> V_428 ) ;
memcpy ( V_428 , & V_527 -> V_428 , sizeof( struct V_439 ) ) ;
memset ( V_462 , 0 , sizeof( struct V_461 ) ) ;
V_160:
if ( V_525 )
F_308 ( V_525 ) ;
F_116 ( V_527 ) ;
return V_325 ;
}
static int F_309 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_439 * V_428 , struct V_1 * V_7 )
{
struct V_528 args = {
. V_263 = V_462 ,
. V_260 = V_14 -> V_15 ,
} ;
struct V_529 V_66 = {
. V_428 = V_428 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_530 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
args . V_260 = F_6 ( V_14 , V_7 ) ;
F_101 ( V_428 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_215 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_439 * V_428 , struct V_1 * V_7 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_309 ( V_14 , V_462 , V_428 , V_7 ) ;
F_310 ( V_14 , V_462 , V_428 , V_8 ) ;
V_8 = F_36 ( V_14 , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_311 ( struct V_4 * V_4 , struct V_439 * V_428 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_51 * V_52 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_1 * V_7 = NULL ;
int V_325 ;
if ( F_312 ( V_2 ) &&
V_6 -> V_265 & V_430 &&
V_6 -> V_531 < F_313 ( V_2 ) )
F_314 ( V_2 ) ;
F_101 ( V_428 ) ;
if ( V_6 -> V_265 & V_441 )
V_6 -> V_265 &= ~ ( V_398 | V_532 ) ;
if ( ( V_6 -> V_265 & ~ ( V_533 | V_441 ) ) == 0 )
return 0 ;
if ( V_6 -> V_265 & V_533 ) {
struct V_319 * V_320 ;
V_320 = F_315 ( V_6 -> V_534 ) ;
if ( V_320 ) {
V_52 = V_320 -> V_52 ;
V_74 = V_320 -> V_74 ;
}
}
V_7 = F_107 ( F_105 ( V_2 ) , V_413 ) ;
if ( F_56 ( V_7 ) )
return F_89 ( V_7 ) ;
V_325 = F_258 ( V_2 , V_52 , V_428 , V_6 , V_74 , NULL , V_7 ) ;
if ( V_325 == 0 ) {
F_259 ( V_2 , V_6 , V_428 ) ;
F_260 ( V_2 , V_428 , V_7 ) ;
}
F_115 ( V_7 ) ;
return V_325 ;
}
static int F_316 ( struct V_64 * V_65 , struct V_2 * V_3 ,
const struct V_524 * V_259 , struct V_461 * V_462 ,
struct V_439 * V_428 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
int V_325 ;
struct V_535 args = {
. V_260 = V_14 -> V_15 ,
. V_536 = F_113 ( V_3 ) ,
. V_259 = V_259 ,
} ;
struct V_504 V_66 = {
. V_14 = V_14 ,
. V_428 = V_428 ,
. V_7 = V_7 ,
. V_263 = V_462 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_537 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
args . V_260 = F_6 ( V_14 , V_7 ) ;
F_101 ( V_428 ) ;
F_8 ( L_36 , V_259 -> V_259 ) ;
V_325 = F_91 ( V_65 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
F_8 ( L_37 , V_325 ) ;
return V_325 ;
}
static void F_317 ( struct V_439 * V_428 )
{
V_428 -> V_316 |= V_353 | V_538 |
V_539 | V_540 ;
V_428 -> V_276 = V_358 | V_541 | V_542 ;
V_428 -> V_543 = 2 ;
}
static int F_318 ( struct V_64 * * V_65 , struct V_2 * V_3 ,
const struct V_524 * V_259 , struct V_461 * V_462 ,
struct V_439 * V_428 , struct V_1 * V_7 )
{
struct V_70 V_71 = { } ;
struct V_64 * V_108 = * V_65 ;
int V_8 ;
do {
V_8 = F_316 ( V_108 , V_3 , V_259 , V_462 , V_428 , V_7 ) ;
F_319 ( V_3 , V_259 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_321 ;
goto V_160;
case - V_87 :
V_8 = F_303 ( V_108 , V_3 , V_259 , V_428 , V_462 ) ;
if ( V_8 == - V_87 )
V_8 = F_36 ( F_105 ( V_3 ) , V_8 , & V_71 ) ;
goto V_160;
case - V_22 :
V_8 = - V_24 ;
if ( V_108 != * V_65 )
goto V_160;
V_108 = F_320 ( V_108 , V_3 , V_259 ) ;
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
static int F_322 ( struct V_2 * V_3 , const struct V_524 * V_259 ,
struct V_461 * V_462 , struct V_439 * V_428 ,
struct V_1 * V_7 )
{
int V_325 ;
struct V_64 * V_108 = F_323 ( V_3 ) ;
V_325 = F_318 ( & V_108 , V_3 , V_259 , V_462 , V_428 , V_7 ) ;
if ( V_108 != F_323 ( V_3 ) ) {
F_321 ( V_108 ) ;
F_317 ( V_428 ) ;
}
return V_325 ;
}
struct V_64 *
F_324 ( struct V_2 * V_3 , const struct V_524 * V_259 ,
struct V_461 * V_462 , struct V_439 * V_428 )
{
struct V_64 * V_108 = F_323 ( V_3 ) ;
int V_325 ;
V_325 = F_318 ( & V_108 , V_3 , V_259 , V_462 , V_428 , NULL ) ;
if ( V_325 < 0 )
return F_57 ( V_325 ) ;
return ( V_108 == F_323 ( V_3 ) ) ? F_325 ( V_108 ) : V_108 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_368 * V_544 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_545 args = {
. V_263 = F_113 ( V_2 ) ,
. V_260 = V_14 -> V_458 ,
} ;
struct V_546 V_66 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_547 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_544 -> V_52 ,
} ;
int V_276 = V_544 -> V_370 ;
int V_325 = 0 ;
if ( V_276 & V_375 )
args . V_226 |= V_249 ;
if ( F_327 ( V_2 -> V_548 ) ) {
if ( V_276 & V_549 )
args . V_226 |= V_250 | V_251 | V_550 ;
if ( V_276 & V_373 )
args . V_226 |= V_551 ;
} else {
if ( V_276 & V_549 )
args . V_226 |= V_250 | V_251 ;
if ( V_276 & V_373 )
args . V_226 |= V_252 ;
}
V_66 . V_428 = F_328 () ;
if ( V_66 . V_428 == NULL )
return - V_142 ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( ! V_325 ) {
F_212 ( V_544 , V_66 . V_226 ) ;
F_171 ( V_2 , V_66 . V_428 ) ;
}
F_329 ( V_66 . V_428 ) ;
return V_325 ;
}
static int F_330 ( struct V_2 * V_2 , struct V_368 * V_544 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_326 ( V_2 , V_544 ) ;
F_331 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_332 ( struct V_2 * V_2 , struct V_525 * V_525 ,
unsigned int V_48 , unsigned int V_552 )
{
struct V_553 args = {
. V_263 = F_113 ( V_2 ) ,
. V_48 = V_48 ,
. V_552 = V_552 ,
. V_42 = & V_525 ,
} ;
struct V_554 V_66 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_555 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
return F_91 ( F_105 ( V_2 ) -> V_108 , F_105 ( V_2 ) , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_333 ( struct V_2 * V_2 , struct V_525 * V_525 ,
unsigned int V_48 , unsigned int V_552 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_332 ( V_2 , V_525 , V_48 , V_552 ) ;
F_334 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_335 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_231 )
{
struct V_1 V_17 , * V_440 = NULL ;
struct V_319 * V_320 ;
struct V_73 * V_74 ;
int V_325 = 0 ;
V_320 = F_336 ( V_4 , V_202 ) ;
if ( F_56 ( V_320 ) )
return F_89 ( V_320 ) ;
V_440 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_337 () ;
V_74 = F_262 ( V_3 , V_320 , V_231 , V_6 , V_440 , NULL ) ;
if ( F_56 ( V_74 ) ) {
V_325 = F_89 ( V_74 ) ;
goto V_160;
}
V_160:
F_4 ( V_440 ) ;
F_192 ( V_320 ) ;
return V_325 ;
}
static int F_338 ( struct V_2 * V_3 , const struct V_524 * V_259 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_556 args = {
. V_263 = F_113 ( V_3 ) ,
. V_259 = * V_259 ,
} ;
struct V_557 V_66 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_558 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
int V_325 ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 1 ) ;
if ( V_325 == 0 )
F_92 ( V_3 , & V_66 . V_187 ) ;
return V_325 ;
}
static int F_339 ( struct V_2 * V_3 , const struct V_524 * V_259 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_338 ( V_3 , V_259 ) ;
F_340 ( V_3 , V_259 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_341 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_556 * args = V_179 -> V_333 ;
struct V_557 * V_66 = V_179 -> V_334 ;
V_66 -> V_14 = V_14 ;
V_179 -> V_330 = & V_331 [ V_558 ] ;
F_51 ( & args -> V_176 , & V_66 -> V_177 , 1 ) ;
F_101 ( V_66 -> V_559 ) ;
}
static void F_342 ( struct V_112 * V_113 , struct V_560 * V_174 )
{
F_81 ( F_183 ( V_174 -> V_4 -> V_243 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_343 ( struct V_112 * V_113 , struct V_2 * V_3 )
{
struct V_560 * V_174 = V_113 -> V_561 ;
struct V_557 * V_66 = & V_174 -> V_66 ;
if ( ! F_78 ( V_113 , & V_66 -> V_177 ) )
return 0 ;
if ( F_43 ( V_113 , V_66 -> V_14 , NULL ,
& V_174 -> V_60 ) == - V_118 )
return 0 ;
F_92 ( V_3 , & V_66 -> V_187 ) ;
return 1 ;
}
static void F_344 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
struct V_562 * V_423 = V_179 -> V_333 ;
struct V_563 * V_66 = V_179 -> V_334 ;
V_179 -> V_330 = & V_331 [ V_564 ] ;
V_66 -> V_14 = V_14 ;
F_51 ( & V_423 -> V_176 , & V_66 -> V_177 , 1 ) ;
}
static void F_345 ( struct V_112 * V_113 , struct V_565 * V_174 )
{
F_81 ( F_105 ( V_174 -> V_566 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_346 ( struct V_112 * V_113 , struct V_2 * V_566 ,
struct V_2 * V_567 )
{
struct V_565 * V_174 = V_113 -> V_561 ;
struct V_563 * V_66 = & V_174 -> V_66 ;
if ( ! F_78 ( V_113 , & V_66 -> V_177 ) )
return 0 ;
if ( F_43 ( V_113 , V_66 -> V_14 , NULL , & V_174 -> V_60 ) == - V_118 )
return 0 ;
F_92 ( V_566 , & V_66 -> V_568 ) ;
F_92 ( V_567 , & V_66 -> V_569 ) ;
return 1 ;
}
static int F_347 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_524 * V_259 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_570 V_423 = {
. V_263 = F_113 ( V_2 ) ,
. V_536 = F_113 ( V_3 ) ,
. V_259 = V_259 ,
. V_260 = V_14 -> V_15 ,
} ;
struct V_571 V_66 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_572 ] ,
. V_333 = & V_423 ,
. V_334 = & V_66 ,
} ;
int V_325 = - V_142 ;
V_66 . V_428 = F_328 () ;
if ( V_66 . V_428 == NULL )
goto V_160;
V_66 . V_7 = F_107 ( V_14 , V_413 ) ;
if ( F_56 ( V_66 . V_7 ) ) {
V_325 = F_89 ( V_66 . V_7 ) ;
goto V_160;
}
V_423 . V_260 = F_6 ( V_14 , V_66 . V_7 ) ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_423 . V_176 , & V_66 . V_177 , 1 ) ;
if ( ! V_325 ) {
F_92 ( V_3 , & V_66 . V_187 ) ;
V_325 = F_348 ( V_2 , V_66 . V_428 ) ;
if ( ! V_325 )
F_260 ( V_2 , V_66 . V_428 , V_66 . V_7 ) ;
}
F_115 ( V_66 . V_7 ) ;
V_160:
F_329 ( V_66 . V_428 ) ;
return V_325 ;
}
static int F_349 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_524 * V_259 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( F_105 ( V_2 ) ,
F_347 ( V_2 , V_3 , V_259 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static struct V_573 * F_350 ( struct V_2 * V_3 ,
const struct V_524 * V_259 , struct V_5 * V_6 , T_1 V_574 )
{
struct V_573 * V_174 ;
V_174 = F_106 ( sizeof( * V_174 ) , V_413 ) ;
if ( V_174 != NULL ) {
struct V_13 * V_14 = F_105 ( V_3 ) ;
V_174 -> V_7 = F_107 ( V_14 , V_413 ) ;
if ( F_56 ( V_174 -> V_7 ) )
goto V_329;
V_174 -> V_179 . V_330 = & V_331 [ V_575 ] ;
V_174 -> V_179 . V_333 = & V_174 -> V_423 ;
V_174 -> V_179 . V_334 = & V_174 -> V_66 ;
V_174 -> V_423 . V_536 = F_113 ( V_3 ) ;
V_174 -> V_423 . V_14 = V_14 ;
V_174 -> V_423 . V_259 = V_259 ;
V_174 -> V_423 . V_232 = V_6 ;
V_174 -> V_423 . V_574 = V_574 ;
V_174 -> V_423 . V_260 = F_6 ( V_14 , V_174 -> V_7 ) ;
V_174 -> V_66 . V_14 = V_14 ;
V_174 -> V_66 . V_263 = & V_174 -> V_263 ;
V_174 -> V_66 . V_428 = & V_174 -> V_428 ;
V_174 -> V_66 . V_7 = V_174 -> V_7 ;
F_101 ( V_174 -> V_66 . V_428 ) ;
}
return V_174 ;
V_329:
F_116 ( V_174 ) ;
return NULL ;
}
static int F_351 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_573 * V_174 )
{
int V_325 = F_91 ( F_105 ( V_3 ) -> V_108 , F_105 ( V_3 ) , & V_174 -> V_179 ,
& V_174 -> V_423 . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
if ( V_325 == 0 ) {
F_92 ( V_3 , & V_174 -> V_66 . V_576 ) ;
V_325 = F_352 ( V_4 , V_174 -> V_66 . V_263 , V_174 -> V_66 . V_428 , V_174 -> V_66 . V_7 ) ;
}
return V_325 ;
}
static void F_353 ( struct V_573 * V_174 )
{
F_115 ( V_174 -> V_7 ) ;
F_116 ( V_174 ) ;
}
static int F_354 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_525 * V_525 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_573 * V_174 ;
int V_325 = - V_577 ;
if ( V_12 > V_578 )
goto V_160;
V_325 = - V_142 ;
V_174 = F_350 ( V_3 , & V_4 -> V_11 , V_6 , V_579 ) ;
if ( V_174 == NULL )
goto V_160;
V_174 -> V_179 . V_330 = & V_331 [ V_580 ] ;
V_174 -> V_423 . V_267 . V_581 . V_42 = & V_525 ;
V_174 -> V_423 . V_267 . V_581 . V_12 = V_12 ;
V_174 -> V_423 . V_7 = V_7 ;
V_325 = F_351 ( V_3 , V_4 , V_174 ) ;
F_353 ( V_174 ) ;
V_160:
return V_325 ;
}
static int F_355 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_525 * V_525 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_354 ( V_3 , V_4 , V_525 , V_12 , V_6 , V_7 ) ;
F_356 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_357 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_573 * V_174 ;
int V_325 = - V_142 ;
V_174 = F_350 ( V_3 , & V_4 -> V_11 , V_6 , V_582 ) ;
if ( V_174 == NULL )
goto V_160;
V_174 -> V_423 . V_7 = V_7 ;
V_325 = F_351 ( V_3 , V_4 , V_174 ) ;
F_353 ( V_174 ) ;
V_160:
return V_325 ;
}
static int F_358 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_337 () ;
do {
V_8 = F_357 ( V_3 , V_4 , V_6 , V_7 ) ;
F_359 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_360 ( struct V_4 * V_4 , struct V_51 * V_52 ,
T_2 V_36 , struct V_525 * * V_42 , unsigned int V_49 , int V_583 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_263 = F_113 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_260 = F_105 ( F_14 ( V_4 ) ) -> V_15 ,
. V_583 = V_583 ,
} ;
struct V_584 V_66 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_585 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_325 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_93 ( V_3 ) -> V_586 , V_4 , & args ) ;
V_66 . V_48 = args . V_48 ;
V_325 = F_91 ( F_105 ( V_3 ) -> V_108 , F_105 ( V_3 ) , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_325 >= 0 ) {
memcpy ( F_93 ( V_3 ) -> V_586 , V_66 . V_37 . V_174 , V_587 ) ;
V_325 += args . V_48 ;
}
F_361 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_325 ) ;
return V_325 ;
}
static int F_362 ( struct V_4 * V_4 , struct V_51 * V_52 ,
T_2 V_36 , struct V_525 * * V_42 , unsigned int V_49 , int V_583 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_360 ( V_4 , V_52 , V_36 ,
V_42 , V_49 , V_583 ) ;
F_363 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_36 ( F_105 ( F_14 ( V_4 ) ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_364 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_588 )
{
struct V_573 * V_174 ;
int V_276 = V_6 -> V_10 ;
int V_325 = - V_142 ;
V_174 = F_350 ( V_3 , & V_4 -> V_11 , V_6 , V_589 ) ;
if ( V_174 == NULL )
goto V_160;
if ( F_365 ( V_276 ) )
V_174 -> V_423 . V_574 = V_590 ;
else if ( F_366 ( V_276 ) ) {
V_174 -> V_423 . V_574 = V_591 ;
V_174 -> V_423 . V_267 . V_592 . V_593 = F_367 ( V_588 ) ;
V_174 -> V_423 . V_267 . V_592 . V_594 = F_368 ( V_588 ) ;
}
else if ( F_369 ( V_276 ) ) {
V_174 -> V_423 . V_574 = V_595 ;
V_174 -> V_423 . V_267 . V_592 . V_593 = F_367 ( V_588 ) ;
V_174 -> V_423 . V_267 . V_592 . V_594 = F_368 ( V_588 ) ;
} else if ( ! F_370 ( V_276 ) ) {
V_325 = - V_27 ;
goto V_329;
}
V_174 -> V_423 . V_7 = V_7 ;
V_325 = F_351 ( V_3 , V_4 , V_174 ) ;
V_329:
F_353 ( V_174 ) ;
V_160:
return V_325 ;
}
static int F_371 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_588 )
{
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_337 () ;
do {
V_8 = F_364 ( V_3 , V_4 , V_6 , V_7 , V_588 ) ;
F_372 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_373 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_596 * V_597 )
{
struct V_598 args = {
. V_263 = V_462 ,
. V_260 = V_14 -> V_15 ,
} ;
struct V_599 V_66 = {
. V_597 = V_597 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_600 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
F_101 ( V_597 -> V_428 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_374 ( struct V_13 * V_14 , struct V_461 * V_462 , struct V_596 * V_597 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_373 ( V_14 , V_462 , V_597 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_375 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_601 )
{
struct V_602 args = {
. V_263 = V_462 ,
. V_260 = V_14 -> V_15 ,
} ;
struct V_603 V_66 = {
. V_601 = V_601 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_604 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_300 ( struct V_13 * V_14 , struct V_461 * V_462 , struct V_501 * V_601 )
{
struct V_70 V_71 = { } ;
unsigned long V_605 = V_170 ;
int V_8 ;
do {
V_8 = F_375 ( V_14 , V_462 , V_601 ) ;
F_376 ( V_14 , V_462 , V_601 -> V_428 , V_8 ) ;
if ( V_8 == 0 ) {
F_377 ( V_14 -> V_55 ,
V_601 -> V_606 * V_98 ,
V_605 ) ;
break;
}
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_378 ( struct V_13 * V_14 , struct V_461 * V_462 , struct V_501 * V_601 )
{
int error ;
F_101 ( V_601 -> V_428 ) ;
error = F_300 ( V_14 , V_462 , V_601 ) ;
if ( error == 0 ) {
V_14 -> V_607 = V_601 -> V_608 ;
F_379 ( V_14 , V_462 , V_601 ) ;
}
return error ;
}
static int F_380 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_609 * V_610 )
{
struct V_611 args = {
. V_263 = V_462 ,
. V_260 = V_14 -> V_15 ,
} ;
struct V_612 V_66 = {
. V_610 = V_610 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_613 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
if ( ( args . V_260 [ 0 ] & V_614 [ 0 ] ) == 0 ) {
memset ( V_610 , 0 , sizeof( * V_610 ) ) ;
return 0 ;
}
F_101 ( V_610 -> V_428 ) ;
return F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
}
static int F_381 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_609 * V_610 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_380 ( V_14 , V_462 , V_610 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
int F_382 ( T_4 * V_50 ,
const struct V_319 * V_320 ,
const struct V_615 * V_616 ,
T_6 V_200 )
{
const struct V_431 * V_432 = NULL ;
if ( V_616 != NULL )
V_432 = & V_616 -> V_432 ;
return F_268 ( V_320 -> V_74 , V_200 , V_432 , V_50 , NULL ) ;
}
static bool F_383 ( T_4 * V_50 ,
const struct V_319 * V_320 ,
const struct V_615 * V_616 ,
T_6 V_200 )
{
T_4 V_617 ;
if ( F_382 ( & V_617 , V_320 , V_616 , V_200 ) == - V_35 )
return true ;
return F_158 ( V_50 , & V_617 ) ;
}
static bool F_384 ( int V_8 )
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
static int F_385 ( struct V_112 * V_113 , struct V_618 * V_619 )
{
struct V_13 * V_14 = F_105 ( V_619 -> V_2 ) ;
F_386 ( V_619 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
struct V_70 V_71 = {
. V_2 = V_619 -> V_2 ,
. V_74 = V_619 -> args . V_620 -> V_74 ,
. V_50 = & V_619 -> args . V_50 ,
} ;
V_113 -> V_117 = F_39 ( V_113 ,
V_14 , V_113 -> V_117 , & V_71 ) ;
if ( V_71 . V_77 ) {
F_73 ( V_113 ) ;
return - V_118 ;
}
}
if ( V_113 -> V_117 > 0 )
F_49 ( V_14 , V_619 -> V_125 ) ;
return 0 ;
}
static bool F_387 ( struct V_112 * V_113 ,
struct V_621 * args )
{
if ( ! F_384 ( V_113 -> V_117 ) ||
F_383 ( & args -> V_50 ,
args -> V_620 ,
args -> V_622 ,
V_202 ) )
return false ;
F_73 ( V_113 ) ;
return true ;
}
static int F_388 ( struct V_112 * V_113 , struct V_618 * V_619 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_78 ( V_113 , & V_619 -> V_66 . V_177 ) )
return - V_118 ;
if ( F_387 ( V_113 , & V_619 -> args ) )
return - V_118 ;
if ( V_113 -> V_117 > 0 )
F_361 ( V_619 -> V_2 ) ;
return V_619 -> V_623 ? V_619 -> V_623 ( V_113 , V_619 ) :
F_385 ( V_113 , V_619 ) ;
}
static void F_389 ( struct V_618 * V_619 ,
struct V_178 * V_179 )
{
V_619 -> V_125 = V_170 ;
if ( ! V_619 -> V_623 )
V_619 -> V_623 = F_385 ;
V_179 -> V_330 = & V_331 [ V_624 ] ;
F_51 ( & V_619 -> args . V_176 , & V_619 -> V_66 . V_177 , 0 ) ;
}
static int F_390 ( struct V_112 * V_113 ,
struct V_618 * V_619 )
{
if ( F_81 ( F_105 ( V_619 -> V_2 ) ,
& V_619 -> args . V_176 ,
& V_619 -> V_66 . V_177 ,
V_113 ) )
return 0 ;
if ( F_382 ( & V_619 -> args . V_50 , V_619 -> args . V_620 ,
V_619 -> args . V_622 ,
V_619 -> V_625 -> V_626 ) == - V_35 )
return - V_35 ;
if ( F_391 ( F_38 ( V_627 , & V_619 -> args . V_620 -> V_231 ) ) )
return - V_35 ;
return 0 ;
}
static int F_392 ( struct V_112 * V_113 ,
struct V_618 * V_619 )
{
struct V_2 * V_2 = V_619 -> V_2 ;
F_393 ( V_619 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
struct V_70 V_71 = {
. V_2 = V_619 -> V_2 ,
. V_74 = V_619 -> args . V_620 -> V_74 ,
. V_50 = & V_619 -> args . V_50 ,
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
F_49 ( F_105 ( V_2 ) , V_619 -> V_125 ) ;
F_394 ( V_619 ) ;
}
return 0 ;
}
static bool F_395 ( struct V_112 * V_113 ,
struct V_621 * args )
{
if ( ! F_384 ( V_113 -> V_117 ) ||
F_383 ( & args -> V_50 ,
args -> V_620 ,
args -> V_622 ,
V_203 ) )
return false ;
F_73 ( V_113 ) ;
return true ;
}
static int F_396 ( struct V_112 * V_113 , struct V_618 * V_619 )
{
if ( ! F_78 ( V_113 , & V_619 -> V_66 . V_177 ) )
return - V_118 ;
if ( F_395 ( V_113 , & V_619 -> args ) )
return - V_118 ;
return V_619 -> V_623 ? V_619 -> V_623 ( V_113 , V_619 ) :
F_392 ( V_113 , V_619 ) ;
}
static
bool F_397 ( struct V_618 * V_619 )
{
if ( V_619 -> V_628 != NULL || V_619 -> V_629 != NULL )
return false ;
return F_240 ( V_619 -> V_2 , V_202 ) == 0 ;
}
static void F_398 ( struct V_618 * V_619 ,
struct V_178 * V_179 )
{
struct V_13 * V_14 = F_105 ( V_619 -> V_2 ) ;
if ( ! F_397 ( V_619 ) ) {
V_619 -> args . V_260 = NULL ;
V_619 -> V_66 . V_428 = NULL ;
} else
V_619 -> args . V_260 = V_14 -> V_458 ;
if ( ! V_619 -> V_623 )
V_619 -> V_623 = F_392 ;
V_619 -> V_66 . V_14 = V_14 ;
V_619 -> V_125 = V_170 ;
V_179 -> V_330 = & V_331 [ V_630 ] ;
F_51 ( & V_619 -> args . V_176 , & V_619 -> V_66 . V_177 , 1 ) ;
}
static void F_399 ( struct V_112 * V_113 , struct V_631 * V_174 )
{
F_81 ( F_105 ( V_174 -> V_2 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_400 ( struct V_112 * V_113 , struct V_631 * V_174 )
{
struct V_2 * V_2 = V_174 -> V_2 ;
F_401 ( V_174 , V_113 -> V_117 ) ;
if ( F_43 ( V_113 , F_105 ( V_2 ) ,
NULL , NULL ) == - V_118 ) {
F_73 ( V_113 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_402 ( struct V_112 * V_113 , struct V_631 * V_174 )
{
if ( ! F_78 ( V_113 , & V_174 -> V_66 . V_177 ) )
return - V_118 ;
return V_174 -> V_632 ( V_113 , V_174 ) ;
}
static void F_403 ( struct V_631 * V_174 , struct V_178 * V_179 )
{
struct V_13 * V_14 = F_105 ( V_174 -> V_2 ) ;
if ( V_174 -> V_632 == NULL )
V_174 -> V_632 = F_400 ;
V_174 -> V_66 . V_14 = V_14 ;
V_179 -> V_330 = & V_331 [ V_633 ] ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
}
static void F_404 ( void * V_172 )
{
struct V_634 * V_174 = V_172 ;
struct V_55 * V_72 = V_174 -> V_108 ;
if ( F_405 ( & V_72 -> V_635 ) > 1 )
F_406 ( V_72 ) ;
F_407 ( V_72 ) ;
F_116 ( V_174 ) ;
}
static void F_408 ( struct V_112 * V_113 , void * V_172 )
{
struct V_634 * V_174 = V_172 ;
struct V_55 * V_72 = V_174 -> V_108 ;
unsigned long V_125 = V_174 -> V_125 ;
F_409 ( V_72 , V_113 -> V_117 ) ;
switch ( V_113 -> V_117 ) {
case 0 :
break;
case - V_88 :
F_31 ( V_72 ) ;
break;
default:
if ( F_38 ( V_636 , & V_72 -> V_637 ) == 0 )
return;
if ( V_113 -> V_117 != V_638 ) {
F_29 ( V_72 ) ;
return;
}
F_410 ( V_72 ) ;
}
F_45 ( V_72 , V_125 ) ;
}
static int F_411 ( struct V_55 * V_72 , struct V_51 * V_52 , unsigned V_639 )
{
struct V_178 V_179 = {
. V_330 = & V_331 [ V_640 ] ,
. V_333 = V_72 ,
. V_51 = V_52 ,
} ;
struct V_634 * V_174 ;
if ( V_639 == 0 )
return 0 ;
if ( ! F_412 ( & V_72 -> V_635 ) )
return - V_35 ;
V_174 = F_305 ( sizeof( * V_174 ) , V_322 ) ;
if ( V_174 == NULL )
return - V_142 ;
V_174 -> V_108 = V_72 ;
V_174 -> V_125 = V_170 ;
return F_413 ( V_72 -> V_120 , & V_179 , V_641 ,
& V_642 , V_174 ) ;
}
static int F_414 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_330 = & V_331 [ V_640 ] ,
. V_333 = V_72 ,
. V_51 = V_52 ,
} ;
unsigned long V_605 = V_170 ;
int V_325 ;
V_325 = F_415 ( V_72 -> V_120 , & V_179 , V_641 ) ;
if ( V_325 < 0 )
return V_325 ;
F_45 ( V_72 , V_605 ) ;
return 0 ;
}
static inline int F_416 ( struct V_13 * V_14 )
{
return V_14 -> V_104 & V_477 ;
}
static int F_417 ( const void * V_643 , T_9 V_644 ,
struct V_525 * * V_42 )
{
struct V_525 * V_645 , * * V_646 ;
int V_647 = 0 ;
T_9 V_12 ;
V_646 = V_42 ;
do {
V_12 = F_418 ( T_9 , V_648 , V_644 ) ;
V_645 = F_304 ( V_413 ) ;
if ( V_645 == NULL )
goto V_649;
memcpy ( F_419 ( V_645 ) , V_643 , V_12 ) ;
V_643 += V_12 ;
V_644 -= V_12 ;
* V_42 ++ = V_645 ;
V_647 ++ ;
} while ( V_644 != 0 );
return V_647 ;
V_649:
for(; V_647 > 0 ; V_647 -- )
F_308 ( V_646 [ V_647 - 1 ] ) ;
return - V_142 ;
}
static void F_420 ( struct V_2 * V_2 , struct V_650 * V_651 )
{
struct V_188 * V_189 = F_93 ( V_2 ) ;
F_46 ( & V_2 -> V_190 ) ;
F_116 ( V_189 -> V_652 ) ;
V_189 -> V_652 = V_651 ;
F_48 ( & V_2 -> V_190 ) ;
}
static void F_421 ( struct V_2 * V_2 )
{
F_420 ( V_2 , NULL ) ;
}
static inline T_11 F_422 ( struct V_2 * V_2 , char * V_643 , T_9 V_644 )
{
struct V_188 * V_189 = F_93 ( V_2 ) ;
struct V_650 * V_651 ;
int V_61 = - V_321 ;
F_46 ( & V_2 -> V_190 ) ;
V_651 = V_189 -> V_652 ;
if ( V_651 == NULL )
goto V_160;
if ( V_643 == NULL )
goto V_653;
if ( V_651 -> V_654 == 0 )
goto V_160;
V_61 = - V_655 ;
if ( V_651 -> V_12 > V_644 )
goto V_160;
memcpy ( V_643 , V_651 -> V_174 , V_651 -> V_12 ) ;
V_653:
V_61 = V_651 -> V_12 ;
V_160:
F_48 ( & V_2 -> V_190 ) ;
return V_61 ;
}
static void F_423 ( struct V_2 * V_2 , struct V_525 * * V_42 , T_9 V_48 , T_9 V_656 )
{
struct V_650 * V_651 ;
T_9 V_644 = sizeof( * V_651 ) + V_656 ;
if ( V_644 <= V_648 ) {
V_651 = F_305 ( V_644 , V_413 ) ;
if ( V_651 == NULL )
goto V_160;
V_651 -> V_654 = 1 ;
F_424 ( V_651 -> V_174 , V_42 , V_48 , V_656 ) ;
} else {
V_651 = F_305 ( sizeof( * V_651 ) , V_413 ) ;
if ( V_651 == NULL )
goto V_160;
V_651 -> V_654 = 0 ;
}
V_651 -> V_12 = V_656 ;
V_160:
F_420 ( V_2 , V_651 ) ;
}
static T_11 F_425 ( struct V_2 * V_2 , void * V_643 , T_9 V_644 )
{
struct V_525 * V_42 [ V_657 ] = { NULL , } ;
struct V_658 args = {
. V_263 = F_113 ( V_2 ) ,
. V_659 = V_42 ,
. V_656 = V_644 ,
} ;
struct V_660 V_66 = {
. V_656 = V_644 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_661 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
unsigned int V_662 = F_426 ( V_644 , V_648 ) ;
int V_61 = - V_142 , V_515 ;
if ( V_662 == 0 )
V_662 = 1 ;
if ( V_662 > F_298 ( V_42 ) )
return - V_655 ;
for ( V_515 = 0 ; V_515 < V_662 ; V_515 ++ ) {
V_42 [ V_515 ] = F_304 ( V_413 ) ;
if ( ! V_42 [ V_515 ] )
goto V_329;
}
V_66 . V_663 = F_304 ( V_413 ) ;
if ( ! V_66 . V_663 )
goto V_329;
args . V_656 = V_662 * V_648 ;
F_8 ( L_40 ,
V_34 , V_643 , V_644 , V_662 , args . V_656 ) ;
V_61 = F_91 ( F_105 ( V_2 ) -> V_108 , F_105 ( V_2 ) ,
& V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_61 )
goto V_329;
if ( V_66 . V_664 & V_665 ) {
if ( V_643 == NULL )
goto V_666;
V_61 = - V_655 ;
goto V_329;
}
F_423 ( V_2 , V_42 , V_66 . V_667 , V_66 . V_656 ) ;
if ( V_643 ) {
if ( V_66 . V_656 > V_644 ) {
V_61 = - V_655 ;
goto V_329;
}
F_424 ( V_643 , V_42 , V_66 . V_667 , V_66 . V_656 ) ;
}
V_666:
V_61 = V_66 . V_656 ;
V_329:
for ( V_515 = 0 ; V_515 < V_662 ; V_515 ++ )
if ( V_42 [ V_515 ] )
F_308 ( V_42 [ V_515 ] ) ;
if ( V_66 . V_663 )
F_308 ( V_66 . V_663 ) ;
return V_61 ;
}
static T_11 F_427 ( struct V_2 * V_2 , void * V_643 , T_9 V_644 )
{
struct V_70 V_71 = { } ;
T_11 V_61 ;
do {
V_61 = F_425 ( V_2 , V_643 , V_644 ) ;
F_428 ( V_2 , V_61 ) ;
if ( V_61 >= 0 )
break;
V_61 = F_36 ( F_105 ( V_2 ) , V_61 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_61 ;
}
static T_11 F_429 ( struct V_2 * V_2 , void * V_643 , T_9 V_644 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
int V_61 ;
if ( ! F_416 ( V_14 ) )
return - V_668 ;
V_61 = F_430 ( V_14 , V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( F_93 ( V_2 ) -> V_191 & V_669 )
F_431 ( V_2 ) ;
V_61 = F_422 ( V_2 , V_643 , V_644 ) ;
if ( V_61 != - V_321 )
return V_61 ;
return F_427 ( V_2 , V_643 , V_644 ) ;
}
static int F_432 ( struct V_2 * V_2 , const void * V_643 , T_9 V_644 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_525 * V_42 [ V_657 ] ;
struct V_670 V_423 = {
. V_263 = F_113 ( V_2 ) ,
. V_659 = V_42 ,
. V_656 = V_644 ,
} ;
struct V_671 V_66 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_672 ] ,
. V_333 = & V_423 ,
. V_334 = & V_66 ,
} ;
unsigned int V_662 = F_426 ( V_644 , V_648 ) ;
int V_61 , V_515 ;
if ( ! F_416 ( V_14 ) )
return - V_668 ;
if ( V_662 > F_298 ( V_42 ) )
return - V_655 ;
V_515 = F_417 ( V_643 , V_644 , V_423 . V_659 ) ;
if ( V_515 < 0 )
return V_515 ;
F_162 ( V_2 ) ;
V_61 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_423 . V_176 , & V_66 . V_177 , 1 ) ;
for (; V_515 > 0 ; V_515 -- )
F_433 ( V_42 [ V_515 - 1 ] ) ;
F_46 ( & V_2 -> V_190 ) ;
F_93 ( V_2 ) -> V_191 |= V_192 ;
F_48 ( & V_2 -> V_190 ) ;
F_434 ( V_2 ) ;
F_431 ( V_2 ) ;
return V_61 ;
}
static int F_435 ( struct V_2 * V_2 , const void * V_643 , T_9 V_644 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_432 ( V_2 , V_643 , V_644 ) ;
F_436 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_437 ( struct V_2 * V_2 , void * V_643 ,
T_9 V_644 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_439 V_428 ;
struct V_1 V_7 = { 0 , 0 , V_644 , V_643 } ;
T_1 V_260 [ 3 ] = { 0 , 0 , V_401 } ;
struct V_528 V_423 = {
. V_263 = F_113 ( V_2 ) ,
. V_260 = V_260 ,
} ;
struct V_529 V_66 = {
. V_428 = & V_428 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_530 ] ,
. V_333 = & V_423 ,
. V_334 = & V_66 ,
} ;
int V_61 ;
F_101 ( & V_428 ) ;
V_61 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_423 . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_61 )
return V_61 ;
if ( ! ( V_428 . V_316 & V_673 ) )
return - V_321 ;
if ( V_644 < V_7 . V_12 )
return - V_655 ;
return 0 ;
}
static int F_438 ( struct V_2 * V_2 , void * V_643 ,
T_9 V_644 )
{
struct V_70 V_71 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_668 ;
do {
V_8 = F_437 ( V_2 , V_643 , V_644 ) ;
F_439 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_440 ( struct V_2 * V_2 ,
struct V_1 * V_440 ,
struct V_439 * V_428 ,
struct V_1 * V_412 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
const T_1 V_260 [ 3 ] = { 0 , 0 , V_401 } ;
struct V_422 V_423 = {
. V_263 = F_113 ( V_2 ) ,
. V_429 = & V_6 ,
. V_14 = V_14 ,
. V_260 = V_260 ,
. V_7 = V_440 ,
} ;
struct V_424 V_66 = {
. V_428 = V_428 ,
. V_7 = V_412 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_425 ] ,
. V_333 = & V_423 ,
. V_334 = & V_66 ,
} ;
int V_325 ;
F_19 ( & V_423 . V_50 , & V_438 ) ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_423 . V_176 , & V_66 . V_177 , 1 ) ;
if ( V_325 )
F_8 ( L_41 , V_34 , V_325 ) ;
return V_325 ;
}
static int F_441 ( struct V_2 * V_2 ,
struct V_1 * V_440 ,
struct V_439 * V_428 ,
struct V_1 * V_412 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_440 ( V_2 , V_440 ,
V_428 , V_412 ) ;
F_442 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_443 ( struct V_2 * V_2 , const void * V_643 , T_9 V_644 )
{
struct V_1 V_440 , * V_412 = NULL ;
struct V_439 V_428 ;
struct V_51 * V_52 ;
int V_325 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_668 ;
F_101 ( & V_428 ) ;
V_440 . V_674 = 0 ;
V_440 . V_675 = 0 ;
V_440 . V_7 = ( char * ) V_643 ;
V_440 . V_12 = V_644 ;
V_52 = F_444 () ;
if ( F_56 ( V_52 ) )
return F_89 ( V_52 ) ;
V_412 = F_107 ( F_105 ( V_2 ) , V_413 ) ;
if ( F_56 ( V_412 ) ) {
V_325 = - F_89 ( V_412 ) ;
goto V_160;
}
V_325 = F_441 ( V_2 , & V_440 , & V_428 , V_412 ) ;
if ( V_325 == 0 )
F_260 ( V_2 , & V_428 , V_412 ) ;
F_115 ( V_412 ) ;
V_160:
F_235 ( V_52 ) ;
return V_325 ;
}
static void F_445 ( const struct V_55 * V_72 ,
T_12 * V_676 )
{
T_3 V_266 [ 2 ] ;
if ( F_38 ( V_677 , & V_72 -> V_116 ) ) {
V_266 [ 0 ] = F_446 ( V_678 ) ;
V_266 [ 1 ] = F_446 ( V_678 ) ;
} else {
struct V_679 * V_680 = F_447 ( V_72 -> V_681 , V_682 ) ;
T_2 V_683 = F_111 ( V_680 -> V_684 ) ;
V_266 [ 0 ] = F_446 ( V_683 >> 32 ) ;
V_266 [ 1 ] = F_446 ( V_683 ) ;
}
memcpy ( V_676 -> V_174 , V_266 , sizeof( V_676 -> V_174 ) ) ;
}
static int
F_448 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_685 ;
if ( V_72 -> V_686 != NULL )
return 0 ;
F_156 () ;
V_12 = 14 + strlen ( V_72 -> V_687 ) + 1 +
strlen ( F_449 ( V_72 -> V_120 , V_688 ) ) +
1 +
strlen ( F_449 ( V_72 -> V_120 , V_689 ) ) +
1 ;
F_159 () ;
if ( V_12 > V_690 + 1 )
return - V_27 ;
V_685 = F_305 ( V_12 , V_413 ) ;
if ( ! V_685 )
return - V_142 ;
F_156 () ;
F_450 ( V_685 , V_12 , L_42 ,
V_72 -> V_687 ,
F_449 ( V_72 -> V_120 , V_688 ) ,
F_449 ( V_72 -> V_120 , V_689 ) ) ;
F_159 () ;
V_72 -> V_686 = V_685 ;
return 0 ;
}
static int
F_451 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_685 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_691 ) + 1 +
strlen ( V_72 -> V_120 -> V_692 ) + 1 ;
if ( V_12 > V_690 + 1 )
return - V_27 ;
V_685 = F_305 ( V_12 , V_413 ) ;
if ( ! V_685 )
return - V_142 ;
F_450 ( V_685 , V_12 , L_43 ,
V_72 -> V_693 -> V_694 , V_72 -> V_464 ,
V_691 ,
V_72 -> V_120 -> V_692 ) ;
V_72 -> V_686 = V_685 ;
return 0 ;
}
static int
F_452 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_685 ;
if ( V_72 -> V_686 != NULL )
return 0 ;
if ( V_691 [ 0 ] != '\0' )
return F_451 ( V_72 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_72 -> V_120 -> V_692 ) + 1 ;
if ( V_12 > V_690 + 1 )
return - V_27 ;
V_685 = F_305 ( V_12 , V_413 ) ;
if ( ! V_685 )
return - V_142 ;
F_450 ( V_685 , V_12 , L_44 ,
V_72 -> V_693 -> V_694 , V_72 -> V_464 ,
V_72 -> V_120 -> V_692 ) ;
V_72 -> V_686 = V_685 ;
return 0 ;
}
static unsigned int
F_453 ( const struct V_55 * V_72 , char * V_643 , T_9 V_12 )
{
if ( strchr ( V_72 -> V_687 , ':' ) != NULL )
return F_450 ( V_643 , V_12 , L_45 ) ;
else
return F_450 ( V_643 , V_12 , L_46 ) ;
}
static void F_454 ( struct V_112 * V_113 , void * V_172 )
{
struct V_695 * V_696 = V_172 ;
if ( V_113 -> V_117 == 0 )
V_696 -> V_697 = F_233 ( V_113 -> V_698 -> V_699 ) ;
}
int F_455 ( struct V_55 * V_72 , T_1 V_700 ,
unsigned short V_701 , struct V_51 * V_52 ,
struct V_702 * V_66 )
{
T_12 V_703 ;
struct V_695 V_704 = {
. V_703 = & V_703 ,
. V_705 = V_700 ,
. V_706 = V_72 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_707 ] ,
. V_333 = & V_704 ,
. V_334 = V_66 ,
. V_51 = V_52 ,
} ;
struct V_112 * V_113 ;
struct V_180 V_335 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_708 ,
. V_185 = & V_704 ,
. V_231 = V_641 ,
} ;
int V_325 ;
F_445 ( V_72 , & V_703 ) ;
if ( F_38 ( V_709 , & V_72 -> V_710 ) )
V_325 = F_452 ( V_72 ) ;
else
V_325 = F_448 ( V_72 ) ;
if ( V_325 )
goto V_160;
V_704 . V_711 =
F_453 ( V_72 ,
V_704 . V_712 ,
sizeof( V_704 . V_712 ) ) ;
V_704 . V_713 = F_450 ( V_704 . V_714 ,
sizeof( V_704 . V_714 ) , L_47 ,
V_72 -> V_687 , V_701 >> 8 , V_701 & 255 ) ;
F_8 ( L_48 ,
V_72 -> V_120 -> V_121 -> V_715 -> V_716 ,
V_72 -> V_686 ) ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) ) {
V_325 = F_89 ( V_113 ) ;
goto V_160;
}
V_325 = V_113 -> V_117 ;
if ( V_704 . V_697 ) {
V_72 -> V_717 = F_456 ( V_704 . V_697 ) ;
F_235 ( V_704 . V_697 ) ;
}
F_90 ( V_113 ) ;
V_160:
F_457 ( V_72 , V_325 ) ;
F_8 ( L_49 , V_325 ) ;
return V_325 ;
}
int F_458 ( struct V_55 * V_72 ,
struct V_702 * V_423 ,
struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_330 = & V_331 [ V_718 ] ,
. V_333 = V_423 ,
. V_51 = V_52 ,
} ;
int V_325 ;
F_8 ( L_50 ,
V_72 -> V_120 -> V_121 -> V_715 -> V_716 ,
V_72 -> V_254 ) ;
V_325 = F_415 ( V_72 -> V_120 , & V_179 , V_641 ) ;
F_459 ( V_72 , V_325 ) ;
F_8 ( L_51 , V_325 ) ;
return V_325 ;
}
static void F_460 ( struct V_112 * V_113 , void * V_172 )
{
struct V_719 * V_174 = V_172 ;
if ( ! F_78 ( V_113 , & V_174 -> V_66 . V_177 ) )
return;
F_461 ( & V_174 -> args , & V_174 -> V_66 , V_113 -> V_117 ) ;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_174 -> V_66 . V_14 , V_174 -> V_125 ) ;
break;
case - V_79 :
case - V_78 :
case - V_80 :
F_18 ( V_174 -> V_66 . V_14 ,
V_174 -> args . V_50 ,
V_113 -> V_344 . V_51 ) ;
case - V_81 :
case - V_103 :
case - V_85 :
V_113 -> V_117 = 0 ;
break;
default:
if ( F_43 ( V_113 , V_174 -> V_66 . V_14 ,
NULL , NULL ) == - V_118 ) {
F_73 ( V_113 ) ;
return;
}
}
V_174 -> V_313 = V_113 -> V_117 ;
if ( V_174 -> V_444 && V_174 -> V_313 == 0 )
F_278 ( V_174 -> V_2 , V_174 -> V_446 ) ;
}
static void F_462 ( void * V_172 )
{
struct V_719 * V_174 = V_172 ;
struct V_2 * V_2 = V_174 -> V_2 ;
if ( V_2 ) {
if ( V_174 -> V_444 )
F_275 ( V_2 ) ;
F_463 ( V_2 ) ;
}
F_116 ( V_172 ) ;
}
static void F_464 ( struct V_112 * V_113 , void * V_174 )
{
struct V_719 * V_720 ;
V_720 = (struct V_719 * ) V_174 ;
if ( F_271 ( V_720 -> V_2 , V_113 ) )
return;
if ( V_720 -> V_444 )
F_280 ( V_720 -> V_2 , & V_720 -> V_446 ) ;
F_81 ( V_720 -> V_66 . V_14 ,
& V_720 -> args . V_176 ,
& V_720 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_465 ( struct V_2 * V_2 , struct V_51 * V_52 , const T_4 * V_50 , int V_721 )
{
struct V_719 * V_174 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_722 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_723 ,
. V_231 = V_339 ,
} ;
int V_325 = 0 ;
V_174 = F_106 ( sizeof( * V_174 ) , V_322 ) ;
if ( V_174 == NULL )
return - V_142 ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
F_284 ( V_14 -> V_55 ,
V_456 ,
& V_335 . V_182 , & V_179 ) ;
V_174 -> args . V_462 = & V_174 -> V_263 ;
V_174 -> args . V_50 = & V_174 -> V_50 ;
V_174 -> args . V_260 = V_14 -> V_458 ;
F_205 ( & V_174 -> V_263 , F_113 ( V_2 ) ) ;
F_19 ( & V_174 -> V_50 , V_50 ) ;
V_174 -> V_66 . V_428 = & V_174 -> V_428 ;
V_174 -> V_66 . V_14 = V_14 ;
F_101 ( V_174 -> V_66 . V_428 ) ;
V_174 -> V_125 = V_170 ;
V_174 -> V_313 = 0 ;
V_174 -> V_2 = F_466 ( V_2 ) ;
if ( V_174 -> V_2 )
V_174 -> V_444 = F_281 ( V_2 ) ;
V_335 . V_185 = V_174 ;
V_179 . V_333 = & V_174 -> args ;
V_179 . V_334 = & V_174 -> V_66 ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
if ( ! V_721 )
goto V_160;
V_325 = F_127 ( V_113 ) ;
if ( V_325 != 0 )
goto V_160;
V_325 = V_174 -> V_313 ;
if ( V_325 == 0 )
F_467 ( V_2 , & V_174 -> V_428 ) ;
else
F_171 ( V_2 , & V_174 -> V_428 ) ;
V_160:
F_90 ( V_113 ) ;
return V_325 ;
}
int F_468 ( struct V_2 * V_2 , struct V_51 * V_52 , const T_4 * V_50 , int V_721 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_465 ( V_2 , V_52 , V_50 , V_721 ) ;
F_469 ( V_2 , V_50 , V_8 ) ;
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
static int F_470 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_726 )
{
struct V_2 * V_2 = V_74 -> V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_727 V_423 = {
. V_263 = F_113 ( V_2 ) ,
. V_728 = V_726 ,
} ;
struct V_729 V_66 = {
. V_730 = V_726 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_731 ] ,
. V_333 = & V_423 ,
. V_334 = & V_66 ,
. V_51 = V_74 -> V_244 -> V_301 ,
} ;
struct V_302 * V_303 ;
int V_325 ;
V_423 . V_732 . V_253 = V_72 -> V_254 ;
V_325 = F_471 ( V_74 , V_726 ) ;
if ( V_325 != 0 )
goto V_160;
V_303 = V_726 -> V_733 . V_734 . V_244 ;
V_423 . V_732 . V_255 = V_303 -> V_735 . V_258 ;
V_423 . V_732 . V_736 = V_14 -> V_736 ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & V_423 . V_176 , & V_66 . V_177 , 1 ) ;
switch ( V_325 ) {
case 0 :
V_726 -> V_737 = V_738 ;
break;
case - V_327 :
V_325 = 0 ;
}
V_726 -> V_739 -> V_740 ( V_726 ) ;
V_726 -> V_739 = NULL ;
V_160:
return V_325 ;
}
static int F_472 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_726 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_470 ( V_74 , V_724 , V_726 ) ;
F_473 ( V_726 , V_74 , V_724 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_74 -> V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static struct V_741 * F_474 ( struct V_725 * V_728 ,
struct V_319 * V_320 ,
struct V_302 * V_303 ,
struct V_235 * V_221 )
{
struct V_741 * V_41 ;
struct V_2 * V_2 = V_303 -> V_304 -> V_2 ;
V_41 = F_106 ( sizeof( * V_41 ) , V_322 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_423 . V_263 = F_113 ( V_2 ) ;
V_41 -> V_423 . V_728 = & V_41 -> V_728 ;
V_41 -> V_423 . V_221 = V_221 ;
V_41 -> V_66 . V_221 = V_221 ;
V_41 -> V_303 = V_303 ;
F_110 ( & V_303 -> V_389 ) ;
V_41 -> V_320 = F_180 ( V_320 ) ;
memcpy ( & V_41 -> V_728 , V_728 , sizeof( V_41 -> V_728 ) ) ;
V_41 -> V_14 = F_105 ( V_2 ) ;
return V_41 ;
}
static void F_475 ( void * V_174 )
{
struct V_741 * V_172 = V_174 ;
F_120 ( V_172 -> V_423 . V_221 ) ;
F_237 ( V_172 -> V_303 ) ;
F_192 ( V_172 -> V_320 ) ;
F_116 ( V_172 ) ;
}
static void F_476 ( struct V_112 * V_113 , void * V_174 )
{
struct V_741 * V_172 = V_174 ;
if ( ! F_78 ( V_113 , & V_172 -> V_66 . V_177 ) )
return;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_172 -> V_14 , V_172 -> V_125 ) ;
F_477 ( V_172 -> V_303 -> V_304 -> V_2 , & V_172 -> V_728 ) ;
if ( F_160 ( V_172 -> V_303 ,
& V_172 -> V_66 . V_50 ) )
break;
case - V_79 :
case - V_80 :
F_18 ( V_172 -> V_14 ,
& V_172 -> V_423 . V_50 ,
V_113 -> V_344 . V_51 ) ;
case - V_81 :
case - V_103 :
case - V_85 :
if ( ! F_158 ( & V_172 -> V_423 . V_50 ,
& V_172 -> V_303 -> V_306 ) )
F_73 ( V_113 ) ;
break;
default:
if ( F_43 ( V_113 , V_172 -> V_14 ,
NULL , NULL ) == - V_118 )
F_73 ( V_113 ) ;
}
F_164 ( V_172 -> V_423 . V_221 ) ;
}
static void F_478 ( struct V_112 * V_113 , void * V_174 )
{
struct V_741 * V_172 = V_174 ;
if ( F_204 ( V_172 -> V_423 . V_221 , V_113 ) != 0 )
goto V_340;
F_19 ( & V_172 -> V_423 . V_50 , & V_172 -> V_303 -> V_306 ) ;
if ( F_38 ( V_387 , & V_172 -> V_303 -> V_388 ) == 0 ) {
goto V_341;
}
V_172 -> V_125 = V_170 ;
if ( F_81 ( V_172 -> V_14 ,
& V_172 -> V_423 . V_176 ,
& V_172 -> V_66 . V_177 ,
V_113 ) != 0 )
F_164 ( V_172 -> V_423 . V_221 ) ;
return;
V_341:
V_113 -> V_352 = NULL ;
V_340:
F_78 ( V_113 , & V_172 -> V_66 . V_177 ) ;
}
static struct V_112 * F_479 ( struct V_725 * V_728 ,
struct V_319 * V_320 ,
struct V_302 * V_303 ,
struct V_235 * V_221 )
{
struct V_741 * V_174 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_742 ] ,
. V_51 = V_320 -> V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = F_323 ( V_303 -> V_304 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_743 ,
. V_337 = V_338 ,
. V_231 = V_339 ,
} ;
F_284 ( F_105 ( V_303 -> V_304 -> V_2 ) -> V_55 ,
V_456 , & V_335 . V_182 , & V_179 ) ;
V_728 -> V_737 = V_738 ;
V_174 = F_474 ( V_728 , V_320 , V_303 , V_221 ) ;
if ( V_174 == NULL ) {
F_120 ( V_221 ) ;
return F_57 ( - V_142 ) ;
}
F_51 ( & V_174 -> V_423 . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
V_179 . V_333 = & V_174 -> V_423 ;
V_179 . V_334 = & V_174 -> V_66 ;
V_335 . V_185 = V_174 ;
return F_88 ( & V_335 ) ;
}
static int F_480 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_726 )
{
struct V_2 * V_2 = V_74 -> V_2 ;
struct V_229 * V_230 = V_74 -> V_244 ;
struct V_188 * V_189 = F_93 ( V_2 ) ;
struct V_235 * V_221 ;
struct V_302 * V_303 ;
struct V_112 * V_113 ;
struct V_235 * ( * V_236 ) ( struct V_237 * , T_7 ) ;
int V_325 = 0 ;
unsigned char V_744 = V_726 -> V_744 ;
V_325 = F_471 ( V_74 , V_726 ) ;
V_726 -> V_744 |= V_745 ;
F_481 ( & V_230 -> V_746 ) ;
F_482 ( & V_189 -> V_747 ) ;
if ( F_477 ( V_2 , V_726 ) == - V_321 ) {
F_483 ( & V_189 -> V_747 ) ;
F_484 ( & V_230 -> V_746 ) ;
goto V_160;
}
F_483 ( & V_189 -> V_747 ) ;
F_484 ( & V_230 -> V_746 ) ;
if ( V_325 != 0 )
goto V_160;
V_303 = V_726 -> V_733 . V_734 . V_244 ;
if ( F_38 ( V_387 , & V_303 -> V_388 ) == 0 )
goto V_160;
V_236 = F_105 ( V_2 ) -> V_55 -> V_56 -> V_236 ;
V_221 = V_236 ( & V_303 -> V_735 , V_413 ) ;
V_325 = - V_142 ;
if ( F_56 ( V_221 ) )
goto V_160;
V_113 = F_479 ( V_726 , F_315 ( V_726 -> V_748 ) , V_303 , V_221 ) ;
V_325 = F_89 ( V_113 ) ;
if ( F_56 ( V_113 ) )
goto V_160;
V_325 = F_127 ( V_113 ) ;
F_90 ( V_113 ) ;
V_160:
V_726 -> V_744 = V_744 ;
F_485 ( V_726 , V_74 , V_749 , V_325 ) ;
return V_325 ;
}
static struct V_750 * F_486 ( struct V_725 * V_728 ,
struct V_319 * V_320 , struct V_302 * V_303 ,
T_7 V_233 )
{
struct V_750 * V_41 ;
struct V_2 * V_2 = V_303 -> V_304 -> V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_235 * ( * V_236 ) ( struct V_237 * , T_7 ) ;
V_41 = F_106 ( sizeof( * V_41 ) , V_233 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_423 . V_263 = F_113 ( V_2 ) ;
V_41 -> V_423 . V_728 = & V_41 -> V_728 ;
V_41 -> V_423 . V_751 = F_487 ( & V_303 -> V_304 -> V_244 -> V_241 , V_233 ) ;
if ( F_56 ( V_41 -> V_423 . V_751 ) )
goto V_329;
V_236 = V_14 -> V_55 -> V_56 -> V_236 ;
V_41 -> V_423 . V_752 = V_236 ( & V_303 -> V_735 , V_233 ) ;
if ( F_56 ( V_41 -> V_423 . V_752 ) )
goto V_753;
V_41 -> V_423 . V_732 . V_253 = V_14 -> V_55 -> V_254 ;
V_41 -> V_423 . V_732 . V_255 = V_303 -> V_735 . V_258 ;
V_41 -> V_423 . V_732 . V_736 = V_14 -> V_736 ;
V_41 -> V_66 . V_752 = V_41 -> V_423 . V_752 ;
V_41 -> V_303 = V_303 ;
V_41 -> V_14 = V_14 ;
F_110 ( & V_303 -> V_389 ) ;
V_41 -> V_320 = F_180 ( V_320 ) ;
F_488 ( V_728 -> V_748 ) ;
memcpy ( & V_41 -> V_728 , V_728 , sizeof( V_41 -> V_728 ) ) ;
return V_41 ;
V_753:
F_120 ( V_41 -> V_423 . V_751 ) ;
V_329:
F_116 ( V_41 ) ;
return NULL ;
}
static void F_489 ( struct V_112 * V_113 , void * V_172 )
{
struct V_750 * V_174 = V_172 ;
struct V_73 * V_74 = V_174 -> V_303 -> V_304 ;
F_8 ( L_29 , V_34 ) ;
if ( F_204 ( V_174 -> V_423 . V_752 , V_113 ) != 0 )
goto V_340;
if ( ! F_38 ( V_387 , & V_174 -> V_303 -> V_388 ) ) {
if ( F_204 ( V_174 -> V_423 . V_751 , V_113 ) != 0 ) {
goto V_754;
}
F_19 ( & V_174 -> V_423 . V_290 ,
& V_74 -> V_290 ) ;
V_174 -> V_423 . V_755 = 1 ;
V_174 -> V_66 . V_751 = V_174 -> V_423 . V_751 ;
} else {
V_174 -> V_423 . V_755 = 0 ;
F_19 ( & V_174 -> V_423 . V_756 ,
& V_174 -> V_303 -> V_306 ) ;
}
if ( ! F_267 ( V_74 ) ) {
V_174 -> V_313 = - V_437 ;
V_113 -> V_352 = NULL ;
goto V_757;
}
V_174 -> V_125 = V_170 ;
if ( F_81 ( V_174 -> V_14 ,
& V_174 -> V_423 . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) == 0 )
return;
V_757:
F_164 ( V_174 -> V_423 . V_751 ) ;
V_754:
F_164 ( V_174 -> V_423 . V_752 ) ;
V_340:
F_78 ( V_113 , & V_174 -> V_66 . V_177 ) ;
F_8 ( L_52 , V_34 , V_174 -> V_313 ) ;
}
static void F_490 ( struct V_112 * V_113 , void * V_172 )
{
struct V_750 * V_174 = V_172 ;
struct V_302 * V_303 = V_174 -> V_303 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_78 ( V_113 , & V_174 -> V_66 . V_177 ) )
return;
V_174 -> V_313 = V_113 -> V_117 ;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( F_105 ( F_14 ( V_174 -> V_320 -> V_4 ) ) ,
V_174 -> V_125 ) ;
if ( V_174 -> V_423 . V_758 ) {
V_174 -> V_728 . V_744 &= ~ ( V_759 | V_760 ) ;
if ( F_477 ( V_303 -> V_304 -> V_2 , & V_174 -> V_728 ) < 0 ) {
F_73 ( V_113 ) ;
break;
}
}
if ( V_174 -> V_423 . V_755 != 0 ) {
F_198 ( & V_303 -> V_735 , 0 ) ;
F_19 ( & V_303 -> V_306 , & V_174 -> V_66 . V_50 ) ;
F_145 ( V_387 , & V_303 -> V_388 ) ;
} else if ( ! F_160 ( V_303 , & V_174 -> V_66 . V_50 ) )
F_73 ( V_113 ) ;
break;
case - V_81 :
case - V_103 :
case - V_85 :
case - V_80 :
if ( V_174 -> V_423 . V_755 != 0 ) {
if ( ! F_158 ( & V_174 -> V_423 . V_290 ,
& V_303 -> V_304 -> V_290 ) )
F_73 ( V_113 ) ;
} else if ( ! F_158 ( & V_174 -> V_423 . V_756 ,
& V_303 -> V_306 ) )
F_73 ( V_113 ) ;
}
F_8 ( L_30 , V_34 , V_174 -> V_313 ) ;
}
static void F_491 ( void * V_172 )
{
struct V_750 * V_174 = V_172 ;
F_8 ( L_29 , V_34 ) ;
F_120 ( V_174 -> V_423 . V_751 ) ;
if ( V_174 -> V_328 != 0 ) {
struct V_112 * V_113 ;
V_113 = F_479 ( & V_174 -> V_728 , V_174 -> V_320 , V_174 -> V_303 ,
V_174 -> V_423 . V_752 ) ;
if ( ! F_56 ( V_113 ) )
F_492 ( V_113 ) ;
F_8 ( L_53 , V_34 ) ;
} else
F_120 ( V_174 -> V_423 . V_752 ) ;
F_237 ( V_174 -> V_303 ) ;
F_192 ( V_174 -> V_320 ) ;
F_493 ( V_174 -> V_728 . V_748 ) ;
F_116 ( V_174 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_494 ( struct V_13 * V_14 , struct V_302 * V_303 , int V_755 , int error )
{
switch ( error ) {
case - V_79 :
case - V_80 :
case - V_81 :
V_303 -> V_735 . V_231 &= ~ V_761 ;
if ( V_755 != 0 ||
F_38 ( V_387 , & V_303 -> V_388 ) != 0 )
F_28 ( V_14 , V_303 -> V_304 ) ;
break;
case - V_85 :
V_303 -> V_735 . V_231 &= ~ V_761 ;
F_29 ( V_14 -> V_55 ) ;
} ;
}
static int F_495 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_728 , int V_762 )
{
struct V_750 * V_174 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_763 ] ,
. V_51 = V_74 -> V_244 -> V_301 ,
} ;
struct V_180 V_335 = {
. V_182 = F_323 ( V_74 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_764 ,
. V_337 = V_338 ,
. V_231 = V_339 ,
} ;
int V_61 ;
F_8 ( L_29 , V_34 ) ;
V_174 = F_486 ( V_728 , F_315 ( V_728 -> V_748 ) ,
V_728 -> V_733 . V_734 . V_244 ,
V_762 == V_765 ? V_413 : V_322 ) ;
if ( V_174 == NULL )
return - V_142 ;
if ( F_496 ( V_724 ) )
V_174 -> V_423 . V_766 = 1 ;
F_51 ( & V_174 -> V_423 . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
V_179 . V_333 = & V_174 -> V_423 ;
V_179 . V_334 = & V_174 -> V_66 ;
V_335 . V_185 = V_174 ;
if ( V_762 > V_765 ) {
if ( V_762 == V_767 )
V_174 -> V_423 . V_768 = V_767 ;
F_52 ( & V_174 -> V_423 . V_176 ) ;
} else
V_174 -> V_423 . V_758 = 1 ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
V_61 = F_127 ( V_113 ) ;
if ( V_61 == 0 ) {
V_61 = V_174 -> V_313 ;
if ( V_61 )
F_494 ( V_174 -> V_14 , V_174 -> V_303 ,
V_174 -> V_423 . V_755 , V_61 ) ;
} else
V_174 -> V_328 = 1 ;
F_90 ( V_113 ) ;
F_8 ( L_30 , V_34 , V_61 ) ;
F_497 ( V_728 , V_74 , & V_174 -> V_66 . V_50 , V_724 , V_61 ) ;
return V_61 ;
}
static int F_498 ( struct V_73 * V_74 , struct V_725 * V_726 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = {
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_38 ( V_291 , & V_74 -> V_231 ) != 0 )
return 0 ;
V_8 = F_495 ( V_74 , V_749 , V_726 , V_767 ) ;
if ( V_8 != - V_99 )
break;
F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_499 ( struct V_73 * V_74 , struct V_725 * V_726 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_70 V_71 = {
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
V_8 = F_471 ( V_74 , V_726 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_390 ) {
F_145 ( V_391 , & V_726 -> V_733 . V_734 . V_244 -> V_388 ) ;
return 0 ;
}
do {
if ( F_38 ( V_291 , & V_74 -> V_231 ) != 0 )
return 0 ;
V_8 = F_495 ( V_74 , V_749 , V_726 , V_769 ) ;
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
static int F_500 ( struct V_73 * V_74 , struct V_725 * V_726 )
{
struct V_302 * V_303 ;
int V_325 ;
V_325 = F_471 ( V_74 , V_726 ) ;
if ( V_325 != 0 )
return V_325 ;
V_303 = V_726 -> V_733 . V_734 . V_244 ;
if ( F_38 ( V_387 , & V_303 -> V_388 ) ||
F_38 ( V_391 , & V_303 -> V_388 ) )
return 0 ;
V_325 = F_499 ( V_74 , V_726 ) ;
return V_325 ;
}
static int F_501 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_726 )
{
struct V_188 * V_189 = F_93 ( V_74 -> V_2 ) ;
struct V_229 * V_230 = V_74 -> V_244 ;
unsigned char V_744 = V_726 -> V_744 ;
int V_325 ;
V_726 -> V_744 |= V_760 ;
V_325 = F_477 ( V_74 -> V_2 , V_726 ) ;
if ( V_325 < 0 )
goto V_160;
F_481 ( & V_230 -> V_746 ) ;
F_482 ( & V_189 -> V_747 ) ;
if ( F_38 ( V_291 , & V_74 -> V_231 ) ) {
V_726 -> V_744 = V_744 & ~ V_759 ;
V_325 = F_477 ( V_74 -> V_2 , V_726 ) ;
F_483 ( & V_189 -> V_747 ) ;
F_484 ( & V_230 -> V_746 ) ;
goto V_160;
}
F_483 ( & V_189 -> V_747 ) ;
F_484 ( & V_230 -> V_746 ) ;
V_325 = F_495 ( V_74 , V_724 , V_726 , V_765 ) ;
V_160:
V_726 -> V_744 = V_744 ;
return V_325 ;
}
static int F_502 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_726 )
{
struct V_70 V_71 = {
. V_74 = V_74 ,
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_501 ( V_74 , V_724 , V_726 ) ;
if ( V_8 == - V_327 )
V_8 = - V_118 ;
V_8 = F_36 ( F_105 ( V_74 -> V_2 ) ,
V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_503 ( struct V_73 * V_74 , int V_724 ,
struct V_725 * V_726 )
{
int V_325 = - V_68 ;
unsigned long V_60 = V_770 ;
while( ! F_504 () ) {
V_325 = F_502 ( V_74 , V_724 , V_726 ) ;
if ( ( V_325 != - V_118 ) || F_505 ( V_724 ) )
break;
F_506 ( V_60 ) ;
V_60 *= 2 ;
V_60 = F_418 (unsigned long, NFS4_LOCK_MAXTIMEOUT, timeout) ;
V_325 = - V_68 ;
}
return V_325 ;
}
static int
F_507 ( T_13 * V_454 , unsigned int V_276 , int V_231 , void * V_771 )
{
int V_61 ;
struct V_772 * V_773 = V_771 ;
struct V_774 * V_775 = V_454 -> V_776 ;
struct V_777 * V_778 = & V_773 -> V_779 ,
* V_780 = V_775 -> V_244 ;
if ( V_778 -> V_253 != V_780 -> V_253 ||
V_778 -> V_255 != V_780 -> V_255 ||
V_778 -> V_736 != V_780 -> V_736 )
return 0 ;
if ( F_508 ( F_113 ( V_775 -> V_2 ) , & V_773 -> V_781 ) )
return 0 ;
V_775 -> V_782 = true ;
V_454 -> V_776 = V_775 -> V_113 ;
V_61 = F_509 ( V_454 , V_276 , V_231 , V_771 ) ;
V_454 -> V_776 = V_775 ;
return V_61 ;
}
static int
F_510 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_726 )
{
int V_325 = - V_68 ;
unsigned long V_231 ;
struct V_302 * V_303 = V_726 -> V_733 . V_734 . V_244 ;
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
T_14 * V_783 = & V_72 -> V_784 ;
struct V_777 V_244 = { . V_253 = V_72 -> V_254 ,
. V_255 = V_303 -> V_735 . V_258 ,
. V_736 = V_14 -> V_736 } ;
struct V_774 V_775 = { . V_113 = V_67 ,
. V_2 = V_74 -> V_2 ,
. V_244 = & V_244 ,
. V_782 = false } ;
T_13 V_454 ;
if ( ! F_38 ( V_406 , & V_74 -> V_231 ) )
return F_503 ( V_74 , V_724 , V_726 ) ;
F_511 ( & V_454 ) ;
V_454 . V_776 = & V_775 ;
V_454 . V_785 = F_507 ;
F_512 ( V_783 , & V_454 ) ;
while( ! F_504 () ) {
V_325 = F_502 ( V_74 , V_724 , V_726 ) ;
if ( ( V_325 != - V_118 ) || F_505 ( V_724 ) )
break;
V_325 = - V_68 ;
F_513 ( & V_783 -> V_299 , V_231 ) ;
if ( V_775 . V_782 ) {
F_514 ( & V_783 -> V_299 , V_231 ) ;
continue;
}
F_515 ( V_786 ) ;
F_514 ( & V_783 -> V_299 , V_231 ) ;
F_506 ( V_787 ) ;
}
F_516 ( V_783 , & V_454 ) ;
return V_325 ;
}
static inline int
F_510 ( struct V_73 * V_74 , int V_724 , struct V_725 * V_726 )
{
return F_503 ( V_74 , V_724 , V_726 ) ;
}
static int
F_517 ( struct V_788 * V_789 , int V_724 , struct V_725 * V_726 )
{
struct V_319 * V_320 ;
struct V_73 * V_74 ;
int V_325 ;
V_320 = F_315 ( V_789 ) ;
V_74 = V_320 -> V_74 ;
if ( V_726 -> V_790 < 0 || V_726 -> V_791 < 0 )
return - V_27 ;
if ( F_518 ( V_724 ) ) {
if ( V_74 != NULL )
return F_472 ( V_74 , V_792 , V_726 ) ;
return 0 ;
}
if ( ! ( F_505 ( V_724 ) || F_496 ( V_724 ) ) )
return - V_27 ;
if ( V_726 -> V_737 == V_738 ) {
if ( V_74 != NULL )
return F_480 ( V_74 , V_724 , V_726 ) ;
return 0 ;
}
if ( V_74 == NULL )
return - V_793 ;
if ( ( V_726 -> V_744 & V_794 ) &&
! F_38 ( V_404 , & V_74 -> V_231 ) )
return - V_793 ;
switch ( V_726 -> V_737 ) {
case V_795 :
if ( ! ( V_789 -> V_796 & V_202 ) )
return - V_437 ;
break;
case V_797 :
if ( ! ( V_789 -> V_796 & V_203 ) )
return - V_437 ;
}
V_325 = F_471 ( V_74 , V_726 ) ;
if ( V_325 != 0 )
return V_325 ;
return F_510 ( V_74 , V_724 , V_726 ) ;
}
int F_519 ( struct V_725 * V_728 , struct V_73 * V_74 , const T_4 * V_50 )
{
struct V_13 * V_14 = F_105 ( V_74 -> V_2 ) ;
int V_8 ;
V_8 = F_471 ( V_74 , V_728 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_495 ( V_74 , V_749 , V_728 , V_765 ) ;
return F_193 ( V_14 , V_74 , V_50 , V_8 ) ;
}
static void F_520 ( struct V_112 * V_113 , void * V_172 )
{
struct V_798 * V_174 = V_172 ;
struct V_13 * V_14 = V_174 -> V_14 ;
F_53 ( V_14 -> V_55 -> V_171 ,
& V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , V_113 ) ;
V_174 -> args . V_732 . V_253 = V_14 -> V_55 -> V_254 ;
V_174 -> V_125 = V_170 ;
}
static void F_521 ( struct V_112 * V_113 , void * V_172 )
{
struct V_798 * V_174 = V_172 ;
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
static void F_522 ( void * V_172 )
{
struct V_798 * V_174 = V_172 ;
F_523 ( V_174 -> V_14 , V_174 -> V_303 ) ;
F_116 ( V_172 ) ;
}
static void
F_524 ( struct V_13 * V_14 , struct V_302 * V_303 )
{
struct V_798 * V_174 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_799 ] ,
} ;
if ( V_14 -> V_55 -> V_56 -> V_350 != 0 )
return;
V_174 = F_305 ( sizeof( * V_174 ) , V_322 ) ;
if ( ! V_174 )
return;
V_174 -> V_303 = V_303 ;
V_174 -> V_14 = V_14 ;
V_174 -> args . V_732 . V_253 = V_14 -> V_55 -> V_254 ;
V_174 -> args . V_732 . V_255 = V_303 -> V_735 . V_258 ;
V_174 -> args . V_732 . V_736 = V_14 -> V_736 ;
V_179 . V_333 = & V_174 -> args ;
V_179 . V_334 = & V_174 -> V_66 ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 0 ) ;
F_413 ( V_14 -> V_108 , & V_179 , 0 , & V_800 , V_174 ) ;
}
static int F_525 ( const struct V_801 * V_802 ,
struct V_4 * V_803 , struct V_2 * V_2 ,
const char * V_771 , const void * V_643 ,
T_9 V_644 , int V_231 )
{
return F_435 ( V_2 , V_643 , V_644 ) ;
}
static int F_526 ( const struct V_801 * V_802 ,
struct V_4 * V_803 , struct V_2 * V_2 ,
const char * V_771 , void * V_643 , T_9 V_644 )
{
return F_429 ( V_2 , V_643 , V_644 ) ;
}
static bool F_527 ( struct V_4 * V_4 )
{
return F_416 ( F_105 ( F_14 ( V_4 ) ) ) ;
}
static int F_528 ( const struct V_801 * V_802 ,
struct V_4 * V_803 , struct V_2 * V_2 ,
const char * V_771 , const void * V_643 ,
T_9 V_644 , int V_231 )
{
if ( F_529 ( V_771 ) )
return F_443 ( V_2 , V_643 , V_644 ) ;
return - V_668 ;
}
static int F_530 ( const struct V_801 * V_802 ,
struct V_4 * V_803 , struct V_2 * V_2 ,
const char * V_771 , void * V_643 , T_9 V_644 )
{
if ( F_529 ( V_771 ) )
return F_438 ( V_2 , V_643 , V_644 ) ;
return - V_668 ;
}
static T_11
F_531 ( struct V_2 * V_2 , char * V_804 , T_9 V_805 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_532 ( V_2 , V_804 , V_805 ) ;
if ( V_805 && V_12 > V_805 )
return - V_655 ;
}
return V_12 ;
}
static T_11
F_531 ( struct V_2 * V_2 , char * V_804 , T_9 V_805 )
{
return 0 ;
}
static void F_307 ( struct V_439 * V_428 )
{
if ( ! ( ( ( V_428 -> V_316 & V_806 ) ||
( V_428 -> V_316 & V_807 ) ) &&
( V_428 -> V_316 & V_522 ) &&
( V_428 -> V_316 & V_808 ) ) )
return;
V_428 -> V_316 |= V_353 | V_538 |
V_539 | V_809 ;
V_428 -> V_276 = V_358 | V_541 | V_542 ;
V_428 -> V_543 = 2 ;
}
static int F_533 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_524 * V_259 ,
struct V_526 * V_810 ,
struct V_525 * V_525 )
{
struct V_13 * V_14 = F_105 ( V_3 ) ;
T_1 V_260 [ 3 ] = {
[ 0 ] = V_811 | V_812 ,
} ;
struct V_813 args = {
. V_536 = F_113 ( V_3 ) ,
. V_259 = V_259 ,
. V_525 = V_525 ,
. V_260 = V_260 ,
} ;
struct V_814 V_66 = {
. V_810 = V_810 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_815 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
int V_325 ;
F_8 ( L_54 , V_34 ) ;
if ( F_105 ( V_3 ) -> V_15 [ 1 ] & V_816 )
V_260 [ 1 ] |= V_816 ;
else
V_260 [ 0 ] |= V_45 ;
F_101 ( & V_810 -> V_428 ) ;
V_810 -> V_14 = V_14 ;
V_810 -> V_817 = 0 ;
V_325 = F_91 ( V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
F_8 ( L_55 , V_34 , V_325 ) ;
return V_325 ;
}
int F_306 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_524 * V_259 ,
struct V_526 * V_810 ,
struct V_525 * V_525 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_533 ( V_108 , V_3 , V_259 ,
V_810 , V_525 ) ;
F_534 ( V_3 , V_259 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_535 ( struct V_2 * V_2 ,
struct V_526 * V_527 ,
struct V_525 * V_525 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
T_1 V_260 [ 2 ] = {
[ 0 ] = V_811 | V_812 ,
} ;
struct V_813 args = {
. V_253 = V_14 -> V_55 -> V_254 ,
. V_263 = F_113 ( V_2 ) ,
. V_525 = V_525 ,
. V_260 = V_260 ,
. V_818 = 1 ,
. V_819 = 1 ,
} ;
struct V_814 V_66 = {
. V_810 = V_527 ,
. V_818 = 1 ,
. V_819 = 1 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_815 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
unsigned long V_605 = V_170 ;
int V_325 ;
F_101 ( & V_527 -> V_428 ) ;
V_527 -> V_14 = V_14 ;
V_527 -> V_817 = 0 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_325 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
if ( V_325 )
return V_325 ;
F_49 ( V_14 , V_605 ) ;
return 0 ;
}
static int F_536 ( struct V_2 * V_2 ,
struct V_526 * V_527 ,
struct V_525 * V_525 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
T_1 V_260 [ 2 ] = {
[ 0 ] = V_811 | V_812 ,
} ;
struct V_813 args = {
. V_263 = F_113 ( V_2 ) ,
. V_525 = V_525 ,
. V_260 = V_260 ,
. V_818 = 1 ,
} ;
struct V_814 V_66 = {
. V_810 = V_527 ,
. V_818 = 1 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_815 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_325 ;
F_101 ( & V_527 -> V_428 ) ;
V_527 -> V_14 = V_14 ;
V_527 -> V_817 = 0 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_325 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
if ( V_325 == V_820 &&
V_66 . V_177 . V_164 & V_821 )
V_325 = - V_88 ;
return V_325 ;
}
int F_537 ( struct V_2 * V_2 ,
struct V_526 * V_527 ,
struct V_525 * V_525 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
const struct V_822 * V_54 =
V_72 -> V_56 -> V_823 ;
struct V_70 V_71 = { } ;
int V_325 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_523 . V_824 ,
( unsigned long long ) V_14 -> V_523 . V_825 ,
V_72 -> V_107 ) ;
F_538 ( F_113 ( V_2 ) , V_34 ) ;
do {
V_325 = V_54 -> V_826 ( V_2 , V_527 , V_525 , V_52 ) ;
if ( V_325 != - V_99 )
break;
F_36 ( V_14 , V_325 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_325 ;
}
static int F_539 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = F_105 ( V_2 ) -> V_55 ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_827 args = {
. V_263 = F_113 ( V_2 ) ,
. V_253 = V_72 -> V_254 ,
. V_819 = 1 ,
} ;
struct V_828 V_66 = {
. V_819 = 1 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_829 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
unsigned long V_605 = V_170 ;
int V_325 ;
V_66 . V_263 = F_540 () ;
if ( V_66 . V_263 == NULL )
return - V_142 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_325 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
F_541 ( V_66 . V_263 ) ;
if ( V_325 )
return V_325 ;
F_45 ( V_72 , V_605 ) ;
return 0 ;
}
static int F_542 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_827 args = {
. V_263 = F_113 ( V_2 ) ,
} ;
struct V_828 V_66 = {
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_829 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_325 ;
V_66 . V_263 = F_540 () ;
if ( V_66 . V_263 == NULL )
return - V_142 ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_325 = F_87 ( V_65 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
F_541 ( V_66 . V_263 ) ;
if ( V_325 == V_820 &&
V_66 . V_177 . V_164 & V_821 )
V_325 = - V_88 ;
return V_325 ;
}
int F_543 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
const struct V_822 * V_54 =
V_72 -> V_56 -> V_823 ;
struct V_70 V_71 = { } ;
int V_325 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_523 . V_824 ,
( unsigned long long ) V_14 -> V_523 . V_825 ,
V_72 -> V_107 ) ;
F_538 ( F_113 ( V_2 ) , V_34 ) ;
do {
V_325 = V_54 -> V_830 ( V_2 , V_52 ) ;
if ( V_325 != - V_99 )
break;
F_36 ( V_14 , V_325 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_325 ;
}
static int F_544 ( struct V_2 * V_3 , const struct V_524 * V_259 , struct V_831 * V_518 , bool V_832 )
{
int V_325 ;
struct V_833 args = {
. V_536 = F_113 ( V_3 ) ,
. V_259 = V_259 ,
} ;
struct V_834 V_66 = {
. V_518 = V_518 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_835 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
struct V_64 * V_65 = F_105 ( V_3 ) -> V_108 ;
struct V_51 * V_52 = NULL ;
if ( V_832 ) {
V_65 = F_105 ( V_3 ) -> V_55 -> V_120 ;
V_52 = F_545 ( F_105 ( V_3 ) -> V_55 ) ;
V_179 . V_51 = V_52 ;
}
F_8 ( L_57 , V_259 -> V_259 ) ;
F_284 ( F_105 ( V_3 ) -> V_55 ,
V_836 , & V_65 , & V_179 ) ;
V_325 = F_91 ( V_65 , F_105 ( V_3 ) , & V_179 , & args . V_176 ,
& V_66 . V_177 , 0 ) ;
F_8 ( L_58 , V_325 ) ;
if ( V_52 )
F_235 ( V_52 ) ;
return V_325 ;
}
int F_546 ( struct V_2 * V_3 , const struct V_524 * V_259 ,
struct V_831 * V_518 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( F_105 ( V_3 ) -> V_55 ) )
V_8 = F_544 ( V_3 , V_259 , V_518 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_544 ( V_3 , V_259 , V_518 , false ) ;
F_547 ( V_3 , V_259 , V_8 ) ;
V_8 = F_36 ( F_105 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_548 ( T_1 V_231 )
{
if ( V_231 & ~ V_837 )
goto V_838;
if ( ( V_231 & V_839 ) &&
( V_231 & V_840 ) )
goto V_838;
if ( ! ( V_231 & ( V_841 ) ) )
goto V_838;
return V_384 ;
V_838:
return - V_842 ;
}
static bool
F_549 ( struct V_843 * V_844 ,
struct V_843 * V_845 )
{
if ( V_844 -> V_846 == V_845 -> V_846 &&
memcmp ( V_844 -> V_847 , V_845 -> V_847 , V_844 -> V_846 ) == 0 )
return true ;
return false ;
}
static void
F_550 ( struct V_112 * V_113 , void * V_172 )
{
}
static
int F_551 ( struct V_64 * V_65 ,
struct V_848 * V_849 ,
struct V_55 * V_72 ,
struct V_51 * V_52 )
{
int V_325 ;
struct V_850 args = {
. V_108 = V_72 ,
. V_3 = V_851 ,
} ;
struct V_852 V_66 ;
struct V_178 V_179 = {
. V_330 =
& V_331 [ V_853 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = V_65 ,
. V_848 = V_849 ,
. V_183 = & V_854 ,
. V_178 = & V_179 ,
. V_231 = V_641 ,
} ;
struct V_112 * V_113 ;
F_8 ( L_11 , V_34 ) ;
F_552 ( & args . V_855 , & V_72 -> V_97 -> V_856 ) ;
if ( ! ( V_72 -> V_97 -> V_231 & V_857 ) )
args . V_3 = V_858 ;
if ( V_849 != F_226 ( V_65 -> V_859 ) )
args . V_3 = V_858 ;
V_113 = F_88 ( & V_335 ) ;
if ( ! F_56 ( V_113 ) ) {
V_325 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
} else
V_325 = F_89 ( V_113 ) ;
F_553 ( V_72 , V_325 ) ;
if ( V_325 == 0 ) {
if ( memcmp ( V_66 . V_855 . V_174 ,
V_72 -> V_97 -> V_856 . V_174 , V_860 ) ) {
F_8 ( L_59 , V_34 ) ;
V_325 = - V_35 ;
goto V_160;
}
if ( ( V_66 . V_3 & args . V_3 ) != V_66 . V_3 || V_66 . V_3 == 0 ) {
F_8 ( L_60 ,
V_34 ) ;
V_325 = - V_35 ;
goto V_160;
}
if ( V_66 . V_861 != args . V_861 ) {
F_8 ( L_61 ,
V_34 ) ;
V_325 = - V_35 ;
goto V_160;
}
}
V_160:
F_8 ( L_62 , V_34 , V_325 ) ;
return V_325 ;
}
static int
F_554 ( struct V_64 * V_65 ,
struct V_848 * V_849 ,
void * V_172 )
{
struct V_862 * V_41 = V_172 ;
return F_551 ( V_65 , V_849 , V_41 -> V_72 , V_41 -> V_52 ) ;
}
int F_555 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_862 V_174 = {
. V_72 = V_72 ,
. V_52 = V_52 ,
} ;
return F_556 ( V_72 -> V_120 ,
F_554 , & V_174 ) ;
}
static int F_557 ( struct V_55 * V_72 ,
struct V_863 * V_230 )
{
static const T_1 V_864 [ V_865 ] = {
[ 1 ] = 1 << ( V_866 - 32 ) |
1 << ( V_867 - 32 ) |
1 << ( V_868 - 32 ) |
1 << ( V_869 - 32 ) |
1 << ( V_870 - 32 )
} ;
unsigned int V_515 ;
if ( V_230 -> V_871 == V_872 ) {
F_558 ( V_873 , L_63 ) ;
for ( V_515 = 0 ; V_515 <= V_874 ; V_515 ++ ) {
if ( F_38 ( V_515 , V_230 -> V_875 . V_267 . V_876 ) )
F_558 ( V_873 , L_64 , V_515 ) ;
if ( F_38 ( V_515 , V_230 -> V_877 . V_267 . V_876 ) )
F_558 ( V_873 , L_65 , V_515 ) ;
}
for ( V_515 = 0 ; V_515 < V_865 ; V_515 ++ ) {
if ( V_230 -> V_875 . V_267 . V_878 [ V_515 ] & ~ V_864 [ V_515 ] ) {
F_558 ( V_873 , L_66 ) ;
return - V_27 ;
}
}
if ( F_38 ( V_866 , V_230 -> V_875 . V_267 . V_876 ) &&
F_38 ( V_868 , V_230 -> V_875 . V_267 . V_876 ) &&
F_38 ( V_869 , V_230 -> V_875 . V_267 . V_876 ) &&
F_38 ( V_870 , V_230 -> V_875 . V_267 . V_876 ) ) {
F_558 ( V_873 , L_67 ) ;
F_558 ( V_873 , L_68 ) ;
F_145 ( V_879 , & V_72 -> V_880 ) ;
} else {
F_558 ( V_873 , L_66 ) ;
return - V_27 ;
}
if ( F_38 ( V_881 , V_230 -> V_877 . V_267 . V_876 ) &&
F_38 ( V_882 , V_230 -> V_877 . V_267 . V_876 ) &&
F_38 ( V_883 , V_230 -> V_877 . V_267 . V_876 ) &&
F_38 ( V_884 , V_230 -> V_877 . V_267 . V_876 ) ) {
F_558 ( V_873 , L_69 ) ;
F_145 ( V_456 , & V_72 -> V_880 ) ;
}
if ( F_38 ( V_885 , V_230 -> V_877 . V_267 . V_876 ) ) {
F_558 ( V_873 , L_70 ) ;
F_145 ( V_886 ,
& V_72 -> V_880 ) ;
}
if ( F_38 ( V_887 , V_230 -> V_877 . V_267 . V_876 ) &&
F_38 ( V_888 , V_230 -> V_877 . V_267 . V_876 ) ) {
F_558 ( V_873 , L_71 ) ;
F_145 ( V_836 , & V_72 -> V_880 ) ;
}
if ( F_38 ( V_889 , V_230 -> V_877 . V_267 . V_876 ) &&
F_38 ( V_890 , V_230 -> V_877 . V_267 . V_876 ) ) {
F_558 ( V_873 , L_72 ) ;
F_145 ( V_891 , & V_72 -> V_880 ) ;
}
if ( F_38 ( V_892 , V_230 -> V_877 . V_267 . V_876 ) ) {
F_558 ( V_873 , L_73 ) ;
F_145 ( V_893 , & V_72 -> V_880 ) ;
}
if ( F_38 ( V_894 , V_230 -> V_877 . V_267 . V_876 ) ) {
F_558 ( V_873 , L_74 ) ;
F_145 ( V_895 , & V_72 -> V_880 ) ;
}
}
return 0 ;
}
static void F_559 ( struct V_112 * V_113 , void * V_174 )
{
struct V_896 * V_897 =
(struct V_896 * ) V_174 ;
struct V_55 * V_72 = V_897 -> args . V_108 ;
int V_325 = V_113 -> V_117 ;
F_560 ( V_72 , V_325 ) ;
if ( V_325 == 0 )
V_325 = F_548 ( V_897 -> V_66 . V_231 ) ;
if ( V_897 -> V_849 && V_325 == 0 ) {
V_325 = F_561 ( V_72 , & V_897 -> V_66 ,
V_897 -> V_849 ) ;
goto V_160;
}
if ( V_325 == 0 )
V_325 = F_557 ( V_72 , & V_897 -> V_66 . V_898 ) ;
if ( V_325 == 0 ) {
V_72 -> V_254 = V_897 -> V_66 . V_253 ;
V_72 -> V_899 = V_897 -> V_66 . V_231 ;
if ( ! ( V_897 -> V_66 . V_231 & V_900 ) ) {
F_147 ( V_901 ,
& V_72 -> V_97 -> V_902 ) ;
V_72 -> V_903 = V_897 -> V_66 . V_221 ;
}
F_116 ( V_72 -> V_904 ) ;
V_72 -> V_904 = V_897 -> V_66 . V_905 ;
V_897 -> V_66 . V_905 = NULL ;
F_116 ( V_72 -> V_906 ) ;
V_72 -> V_906 = V_897 -> V_66 . V_907 ;
V_897 -> V_66 . V_907 = NULL ;
if ( V_72 -> V_908 != NULL &&
! F_549 ( V_72 -> V_908 ,
V_897 -> V_66 . V_847 ) ) {
F_8 ( L_75 ,
V_34 ) ;
F_145 ( V_909 , & V_72 -> V_116 ) ;
F_116 ( V_72 -> V_908 ) ;
V_72 -> V_908 = NULL ;
}
if ( V_72 -> V_908 == NULL ) {
V_72 -> V_908 = V_897 -> V_66 . V_847 ;
V_897 -> V_66 . V_847 = NULL ;
}
memcpy ( V_72 -> V_910 . V_174 , V_897 -> args . V_37 -> V_174 ,
sizeof( V_72 -> V_910 . V_174 ) ) ;
}
V_160:
V_897 -> V_313 = V_325 ;
return;
}
static void F_562 ( void * V_174 )
{
struct V_896 * V_897 =
(struct V_896 * ) V_174 ;
F_407 ( V_897 -> args . V_108 ) ;
if ( V_897 -> V_849 ) {
F_563 ( V_897 -> V_849 ) ;
F_564 ( V_897 -> args . V_108 -> V_120 ) ;
}
F_116 ( V_897 -> V_66 . V_907 ) ;
F_116 ( V_897 -> V_66 . V_847 ) ;
F_116 ( V_897 -> V_66 . V_905 ) ;
F_116 ( V_897 ) ;
}
static int F_565 ( struct V_55 * V_72 , struct V_51 * V_52 ,
T_1 V_911 , struct V_848 * V_849 )
{
T_12 V_37 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_912 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = V_72 -> V_120 ,
. V_183 = & V_913 ,
. V_178 = & V_179 ,
. V_231 = V_339 | V_641 ,
} ;
struct V_896 * V_172 ;
struct V_112 * V_113 ;
int V_325 = - V_35 ;
if ( ! F_412 ( & V_72 -> V_635 ) )
goto V_160;
V_325 = - V_142 ;
V_172 = F_106 ( sizeof( * V_172 ) , V_322 ) ;
if ( ! V_172 )
goto V_160;
if ( ! V_849 )
F_445 ( V_72 , & V_37 ) ;
V_325 = F_452 ( V_72 ) ;
if ( V_325 )
goto V_914;
F_8 ( L_76 ,
V_72 -> V_120 -> V_121 -> V_715 -> V_716 ,
V_72 -> V_686 ) ;
V_172 -> V_66 . V_905 = F_106 ( sizeof( struct V_915 ) ,
V_322 ) ;
V_325 = - V_142 ;
if ( F_391 ( V_172 -> V_66 . V_905 == NULL ) )
goto V_914;
V_172 -> V_66 . V_847 = F_106 ( sizeof( struct V_843 ) ,
V_322 ) ;
if ( F_391 ( V_172 -> V_66 . V_847 == NULL ) )
goto V_916;
V_172 -> V_66 . V_907 = F_106 ( sizeof( struct V_917 ) , V_322 ) ;
if ( F_391 ( V_172 -> V_66 . V_907 == NULL ) )
goto V_918;
switch ( V_911 ) {
case V_919 :
V_172 -> args . V_898 . V_871 = V_919 ;
break;
case V_872 :
V_172 -> args . V_898 = V_920 ;
break;
default:
F_130 ( 1 ) ;
V_325 = - V_27 ;
goto V_921;
}
if ( V_849 ) {
V_172 -> V_849 = V_849 ;
V_335 . V_848 = V_849 ;
V_335 . V_231 =
V_922 | V_923 | V_339 ;
V_172 -> args . V_37 = & V_72 -> V_910 ;
} else {
V_172 -> args . V_37 = & V_37 ;
}
V_172 -> args . V_108 = V_72 ;
#ifdef F_566
V_172 -> args . V_231 = V_924 |
V_925 |
V_926 ,
#else
V_172 -> args . V_231 = V_924 |
V_925 ,
#endif
V_179 . V_333 = & V_172 -> args ;
V_179 . V_334 = & V_172 -> V_66 ;
V_335 . V_185 = V_172 ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) ) {
V_325 = F_89 ( V_113 ) ;
goto V_921;
}
if ( ! V_849 ) {
V_325 = F_128 ( V_113 ) ;
if ( ! V_325 )
V_325 = V_172 -> V_313 ;
} else
V_325 = V_172 -> V_313 ;
F_90 ( V_113 ) ;
V_160:
if ( V_72 -> V_906 != NULL )
F_8 ( L_77
L_78 ,
V_72 -> V_906 -> V_927 , V_72 -> V_906 -> V_259 ,
V_72 -> V_906 -> V_928 . V_929 ,
V_72 -> V_906 -> V_928 . V_930 ) ;
F_8 ( L_79 , V_325 ) ;
return V_325 ;
V_921:
F_116 ( V_172 -> V_66 . V_907 ) ;
V_918:
F_116 ( V_172 -> V_66 . V_847 ) ;
V_916:
F_116 ( V_172 -> V_66 . V_905 ) ;
V_914:
F_116 ( V_172 ) ;
goto V_160;
}
int F_567 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
T_5 V_931 = V_72 -> V_120 -> V_121 -> V_122 ;
int V_325 ;
if ( V_931 == V_123 ||
V_931 == V_124 ) {
V_325 = F_565 ( V_72 , V_52 , V_872 , NULL ) ;
if ( ! V_325 )
return 0 ;
}
return F_565 ( V_72 , V_52 , V_919 , NULL ) ;
}
int F_568 ( struct V_64 * V_65 , struct V_848 * V_849 ,
void * V_174 )
{
struct V_932 * V_933 = (struct V_932 * ) V_174 ;
T_1 V_911 ;
F_8 ( L_80 , V_34 ,
V_849 -> V_934 [ V_688 ] ) ;
V_911 = ( V_933 -> V_72 -> V_880 == 0 ? V_919 : V_872 ) ;
return F_565 ( V_933 -> V_72 , V_933 -> V_52 , V_911 , V_849 ) ;
}
static int F_569 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_330 = & V_331 [ V_935 ] ,
. V_333 = V_72 ,
. V_51 = V_52 ,
} ;
int V_325 ;
V_325 = F_415 ( V_72 -> V_120 , & V_179 , V_641 ) ;
F_570 ( V_72 , V_325 ) ;
if ( V_325 )
F_8 ( L_81
L_82 , V_325 , V_72 -> V_107 ) ;
return V_325 ;
}
static int F_571 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
unsigned int V_936 ;
int V_61 ;
for ( V_936 = V_937 ; V_936 != 0 ; V_936 -- ) {
V_61 = F_569 ( V_72 , V_52 ) ;
switch ( V_61 ) {
case - V_99 :
case - V_938 :
F_194 ( 1 ) ;
break;
default:
return V_61 ;
}
}
return 0 ;
}
int F_572 ( struct V_55 * V_72 )
{
struct V_51 * V_52 ;
int V_61 = 0 ;
if ( V_72 -> V_56 -> V_350 < 1 )
goto V_160;
if ( V_72 -> V_899 == 0 )
goto V_160;
if ( V_72 -> V_939 )
goto V_160;
V_52 = F_545 ( V_72 ) ;
V_61 = F_571 ( V_72 , V_52 ) ;
if ( V_52 )
F_235 ( V_52 ) ;
switch ( V_61 ) {
case 0 :
case - V_86 :
V_72 -> V_899 = 0 ;
}
V_160:
return V_61 ;
}
static void F_573 ( struct V_112 * V_113 ,
void * V_172 )
{
struct V_940 * V_174 =
(struct V_940 * ) V_172 ;
F_8 ( L_11 , V_34 ) ;
F_79 ( V_174 -> V_72 -> V_97 ,
& V_174 -> args -> V_941 ,
& V_174 -> V_66 -> V_942 ,
V_113 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_574 ( struct V_112 * V_113 , void * V_172 )
{
struct V_940 * V_174 =
(struct V_940 * ) V_172 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_75 ( V_113 , & V_174 -> V_66 -> V_942 ) )
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
int F_575 ( struct V_55 * V_72 , struct V_501 * V_601 )
{
struct V_112 * V_113 ;
struct V_943 args ;
struct V_944 V_66 = {
. V_945 = V_601 ,
} ;
struct V_940 V_174 = {
. args = & args ,
. V_66 = & V_66 ,
. V_72 = V_72 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_946 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
struct V_180 V_181 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_947 ,
. V_185 = & V_174 ,
. V_231 = V_641 ,
} ;
int V_325 ;
F_51 ( & args . V_941 , & V_66 . V_942 , 0 ) ;
F_52 ( & args . V_941 ) ;
F_8 ( L_11 , V_34 ) ;
V_113 = F_88 ( & V_181 ) ;
if ( F_56 ( V_113 ) )
V_325 = F_89 ( V_113 ) ;
else {
V_325 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
}
F_8 ( L_85 , V_34 , V_325 ) ;
return V_325 ;
}
static void F_576 ( struct V_948 * args ,
struct V_64 * V_65 )
{
unsigned int V_949 , V_950 ;
unsigned int V_951 = F_577 ( V_65 ) ;
V_949 = V_952 + V_953 ;
V_950 = V_952 + V_954 ;
args -> V_955 . V_949 = V_949 ;
args -> V_955 . V_950 = V_950 ;
args -> V_955 . V_956 = V_957 ;
args -> V_955 . V_958 = V_959 ;
F_8 ( L_86
L_87 ,
V_34 ,
args -> V_955 . V_949 , args -> V_955 . V_950 ,
args -> V_955 . V_956 , args -> V_955 . V_958 ) ;
args -> V_960 . V_949 = V_951 ;
args -> V_960 . V_950 = V_951 ;
args -> V_960 . V_961 = 0 ;
args -> V_960 . V_956 = V_962 ;
args -> V_960 . V_958 = F_418 (unsigned short, max_session_cb_slots, 1 ) ;
F_8 ( L_88
L_89 ,
V_34 ,
args -> V_960 . V_949 , args -> V_960 . V_950 ,
args -> V_960 . V_961 , args -> V_960 . V_956 ,
args -> V_960 . V_958 ) ;
}
static int F_578 ( struct V_948 * args ,
struct V_963 * V_66 )
{
struct V_964 * V_965 = & args -> V_955 ;
struct V_964 * V_966 = & V_66 -> V_955 ;
if ( V_966 -> V_950 > V_965 -> V_950 )
return - V_27 ;
if ( V_966 -> V_956 < V_965 -> V_956 )
return - V_27 ;
if ( V_966 -> V_958 == 0 )
return - V_27 ;
if ( V_966 -> V_958 > V_967 )
V_966 -> V_958 = V_967 ;
return 0 ;
}
static int F_579 ( struct V_948 * args ,
struct V_963 * V_66 )
{
struct V_964 * V_965 = & args -> V_960 ;
struct V_964 * V_966 = & V_66 -> V_960 ;
if ( ! ( V_66 -> V_231 & V_857 ) )
goto V_160;
if ( V_966 -> V_949 > V_965 -> V_949 )
return - V_27 ;
if ( V_966 -> V_950 < V_965 -> V_950 )
return - V_27 ;
if ( V_966 -> V_961 > V_965 -> V_961 )
return - V_27 ;
if ( V_966 -> V_956 > V_965 -> V_956 )
return - V_27 ;
if ( V_966 -> V_958 > V_965 -> V_958 )
return - V_27 ;
V_160:
return 0 ;
}
static int F_580 ( struct V_948 * args ,
struct V_963 * V_66 )
{
int V_61 ;
V_61 = F_578 ( args , V_66 ) ;
if ( V_61 )
return V_61 ;
return F_579 ( args , V_66 ) ;
}
static void F_581 ( struct V_148 * V_149 ,
struct V_963 * V_66 )
{
F_552 ( & V_149 -> V_856 , & V_66 -> V_855 ) ;
V_149 -> V_72 -> V_899 |= V_900 ;
F_145 ( V_901 , & V_149 -> V_902 ) ;
V_149 -> V_231 = V_66 -> V_231 ;
memcpy ( & V_149 -> V_955 , & V_66 -> V_955 , sizeof( V_149 -> V_955 ) ) ;
if ( V_66 -> V_231 & V_857 )
memcpy ( & V_149 -> V_960 , & V_66 -> V_960 ,
sizeof( V_149 -> V_960 ) ) ;
}
static int F_582 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_148 * V_149 = V_72 -> V_97 ;
struct V_948 args = {
. V_108 = V_72 ,
. V_253 = V_72 -> V_254 ,
. V_221 = V_72 -> V_903 ,
. V_968 = V_969 ,
} ;
struct V_963 V_66 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_970 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_325 ;
F_576 ( & args , V_72 -> V_120 ) ;
args . V_231 = ( V_971 | V_857 ) ;
V_325 = F_415 ( V_149 -> V_72 -> V_120 , & V_179 , V_641 ) ;
F_583 ( V_72 , V_325 ) ;
switch ( V_325 ) {
case - V_86 :
case - V_99 :
case - V_972 :
case - V_29 :
case - V_118 :
goto V_160;
} ;
V_72 -> V_903 ++ ;
if ( ! V_325 ) {
V_325 = F_580 ( & args , & V_66 ) ;
if ( V_325 )
goto V_160;
F_581 ( V_149 , & V_66 ) ;
}
V_160:
return V_325 ;
}
int F_584 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
int V_325 ;
unsigned * V_973 ;
struct V_148 * V_149 = V_72 -> V_97 ;
F_8 ( L_90 , V_34 , V_72 , V_149 ) ;
V_325 = F_582 ( V_72 , V_52 ) ;
if ( V_325 )
goto V_160;
V_325 = F_585 ( V_149 ) ;
F_8 ( L_91 , V_325 ) ;
if ( V_325 )
goto V_160;
V_973 = ( unsigned * ) & V_149 -> V_856 . V_174 [ 0 ] ;
F_8 ( L_92 , V_34 ,
V_72 -> V_903 , V_973 [ 0 ] , V_973 [ 1 ] , V_973 [ 2 ] , V_973 [ 3 ] ) ;
V_160:
F_8 ( L_83 , V_34 ) ;
return V_325 ;
}
int F_586 ( struct V_148 * V_149 ,
struct V_51 * V_52 )
{
struct V_178 V_179 = {
. V_330 = & V_331 [ V_974 ] ,
. V_333 = V_149 ,
. V_51 = V_52 ,
} ;
int V_325 = 0 ;
F_8 ( L_93 ) ;
if ( ! F_138 ( V_901 , & V_149 -> V_902 ) )
return 0 ;
V_325 = F_415 ( V_149 -> V_72 -> V_120 , & V_179 , V_641 ) ;
F_587 ( V_149 -> V_72 , V_325 ) ;
if ( V_325 )
F_8 ( L_94
L_95 , V_325 ) ;
F_8 ( L_96 ) ;
return V_325 ;
}
static void F_588 ( void * V_174 )
{
struct V_975 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
if ( F_405 ( & V_72 -> V_635 ) > 1 )
F_406 ( V_72 ) ;
F_407 ( V_72 ) ;
F_116 ( V_172 ) ;
}
static int F_589 ( struct V_112 * V_113 , struct V_55 * V_72 )
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
static void F_590 ( struct V_112 * V_113 , void * V_174 )
{
struct V_975 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
if ( ! F_75 ( V_113 , V_113 -> V_344 . V_334 ) )
return;
F_591 ( V_72 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
F_8 ( L_97 , V_34 , V_113 -> V_117 ) ;
if ( F_405 ( & V_72 -> V_635 ) == 1 )
goto V_160;
if ( F_589 ( V_113 , V_72 ) == - V_118 ) {
F_73 ( V_113 ) ;
return;
}
}
F_8 ( L_98 , V_34 , V_113 -> V_344 . V_51 ) ;
V_160:
F_8 ( L_83 , V_34 ) ;
}
static void F_592 ( struct V_112 * V_113 , void * V_174 )
{
struct V_975 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
struct V_128 * args ;
struct V_129 * V_66 ;
args = V_113 -> V_344 . V_333 ;
V_66 = V_113 -> V_344 . V_334 ;
F_79 ( V_72 -> V_97 , args , V_66 , V_113 ) ;
}
static struct V_112 * F_593 ( struct V_55 * V_72 ,
struct V_51 * V_52 ,
bool V_976 )
{
struct V_975 * V_172 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_977 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_978 ,
. V_231 = V_339 | V_641 ,
} ;
if ( ! F_412 ( & V_72 -> V_635 ) )
return F_57 ( - V_35 ) ;
V_172 = F_106 ( sizeof( * V_172 ) , V_322 ) ;
if ( V_172 == NULL ) {
F_407 ( V_72 ) ;
return F_57 ( - V_142 ) ;
}
F_51 ( & V_172 -> args , & V_172 -> V_66 , 0 ) ;
if ( V_976 )
F_52 ( & V_172 -> args ) ;
V_179 . V_333 = & V_172 -> args ;
V_179 . V_334 = & V_172 -> V_66 ;
V_172 -> V_72 = V_72 ;
V_335 . V_185 = V_172 ;
return F_88 ( & V_335 ) ;
}
static int F_594 ( struct V_55 * V_72 , struct V_51 * V_52 , unsigned V_639 )
{
struct V_112 * V_113 ;
int V_61 = 0 ;
if ( ( V_639 & V_979 ) == 0 )
return - V_118 ;
V_113 = F_593 ( V_72 , V_52 , false ) ;
if ( F_56 ( V_113 ) )
V_61 = F_89 ( V_113 ) ;
else
F_492 ( V_113 ) ;
F_8 ( L_16 , V_34 , V_61 ) ;
return V_61 ;
}
static int F_595 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_112 * V_113 ;
int V_61 ;
V_113 = F_593 ( V_72 , V_52 , true ) ;
if ( F_56 ( V_113 ) ) {
V_61 = F_89 ( V_113 ) ;
goto V_160;
}
V_61 = F_128 ( V_113 ) ;
if ( ! V_61 )
V_61 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
V_160:
F_8 ( L_16 , V_34 , V_61 ) ;
return V_61 ;
}
static void F_596 ( struct V_112 * V_113 , void * V_174 )
{
struct V_980 * V_172 = V_174 ;
F_79 ( V_172 -> V_72 -> V_97 ,
& V_172 -> V_423 . V_176 ,
& V_172 -> V_66 . V_177 ,
V_113 ) ;
}
static int F_597 ( struct V_112 * V_113 , struct V_55 * V_72 )
{
switch( V_113 -> V_117 ) {
case 0 :
case - V_981 :
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
static void F_598 ( struct V_112 * V_113 , void * V_174 )
{
struct V_980 * V_172 = V_174 ;
struct V_55 * V_72 = V_172 -> V_72 ;
struct V_129 * V_66 = & V_172 -> V_66 . V_177 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_75 ( V_113 , V_66 ) )
return;
F_599 ( V_72 , V_113 -> V_117 ) ;
if ( F_597 ( V_113 , V_72 ) == - V_118 ) {
F_73 ( V_113 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_600 ( void * V_174 )
{
struct V_980 * V_172 = V_174 ;
F_116 ( V_172 ) ;
}
static int F_601 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_980 * V_172 ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_982 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = V_72 -> V_120 ,
. V_178 = & V_179 ,
. V_183 = & V_983 ,
. V_231 = V_339 ,
} ;
int V_325 = - V_142 ;
F_8 ( L_11 , V_34 ) ;
V_172 = F_106 ( sizeof( * V_172 ) , V_322 ) ;
if ( V_172 == NULL )
goto V_160;
V_172 -> V_72 = V_72 ;
V_172 -> V_423 . V_984 = 0 ;
F_51 ( & V_172 -> V_423 . V_176 , & V_172 -> V_66 . V_177 , 0 ) ;
F_52 ( & V_172 -> V_423 . V_176 ) ;
V_179 . V_333 = & V_172 -> V_423 ;
V_179 . V_334 = & V_172 -> V_66 ;
V_335 . V_185 = V_172 ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) ) {
V_325 = F_89 ( V_113 ) ;
goto V_160;
}
V_325 = F_127 ( V_113 ) ;
if ( V_325 == 0 )
V_325 = V_113 -> V_117 ;
F_90 ( V_113 ) ;
return 0 ;
V_160:
F_8 ( L_16 , V_34 , V_325 ) ;
return V_325 ;
}
static void
F_602 ( struct V_112 * V_113 , void * V_172 )
{
struct V_985 * V_986 = V_172 ;
struct V_13 * V_14 = F_105 ( V_986 -> args . V_2 ) ;
struct V_148 * V_149 = F_82 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_79 ( V_149 , & V_986 -> args . V_176 ,
& V_986 -> V_66 . V_177 , V_113 ) ;
F_8 ( L_83 , V_34 ) ;
}
static void F_603 ( struct V_112 * V_113 , void * V_172 )
{
struct V_985 * V_986 = V_172 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_113 , & V_986 -> V_66 . V_177 ) ;
F_8 ( L_83 , V_34 ) ;
}
static int
F_604 ( struct V_112 * V_113 ,
struct V_985 * V_986 , struct V_70 * V_71 )
{
struct V_2 * V_2 = V_986 -> args . V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
struct V_987 * V_988 ;
int V_989 = V_113 -> V_117 ;
int V_8 , V_325 = 0 ;
F_605 ( V_990 ) ;
F_8 ( L_99 , V_34 , - V_113 -> V_117 ) ;
switch ( V_989 ) {
case 0 :
goto V_160;
case - V_991 :
V_325 = - V_992 ;
goto V_160;
case - V_993 :
V_325 = - V_994 ;
goto V_160;
case - V_19 :
if ( V_986 -> args . V_995 == 0 ) {
V_325 = - V_994 ;
goto V_160;
}
V_325 = - V_33 ;
break;
case - V_20 :
V_325 = - V_996 ;
break;
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
V_71 -> V_60 = 0 ;
F_46 ( & V_2 -> V_190 ) ;
V_988 = F_93 ( V_2 ) -> V_997 ;
if ( ! V_988 || F_38 ( V_998 , & V_988 -> V_999 ) ||
F_142 ( & V_986 -> args . V_50 ,
& V_986 -> args . V_320 -> V_74 -> V_50 ) ) {
F_48 ( & V_2 -> V_190 ) ;
V_71 -> V_74 = V_986 -> args . V_320 -> V_74 ;
V_71 -> V_50 = & V_986 -> args . V_50 ;
break;
}
F_606 ( V_988 , & V_990 ) ;
F_48 ( & V_2 -> V_190 ) ;
F_607 ( & V_990 ) ;
V_325 = - V_118 ;
goto V_160;
}
V_8 = F_36 ( V_14 , V_989 , V_71 ) ;
if ( ! V_325 ) {
if ( V_71 -> V_77 )
V_325 = - V_118 ;
else
V_325 = V_8 ;
}
V_160:
F_8 ( L_83 , V_34 ) ;
return V_325 ;
}
static T_9 F_608 ( struct V_13 * V_14 )
{
T_1 V_950 = V_14 -> V_55 -> V_97 -> V_955 . V_950 ;
return F_609 ( 0 , V_950 ) ;
}
static void F_610 ( struct V_525 * * V_42 , T_9 V_1000 )
{
int V_515 ;
if ( ! V_42 )
return;
for ( V_515 = 0 ; V_515 < V_1000 ; V_515 ++ ) {
if ( ! V_42 [ V_515 ] )
break;
F_308 ( V_42 [ V_515 ] ) ;
}
F_116 ( V_42 ) ;
}
static struct V_525 * * F_611 ( T_9 V_1000 , T_7 V_1001 )
{
struct V_525 * * V_42 ;
int V_515 ;
V_42 = F_612 ( V_1000 , sizeof( struct V_525 * ) , V_1001 ) ;
if ( ! V_42 ) {
F_8 ( L_100 , V_34 , V_1000 ) ;
return NULL ;
}
for ( V_515 = 0 ; V_515 < V_1000 ; V_515 ++ ) {
V_42 [ V_515 ] = F_304 ( V_1001 ) ;
if ( ! V_42 [ V_515 ] ) {
F_8 ( L_101 , V_34 ) ;
F_610 ( V_42 , V_1000 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_613 ( void * V_172 )
{
struct V_985 * V_986 = V_172 ;
struct V_2 * V_2 = V_986 -> args . V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
T_9 V_1002 = F_608 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_610 ( V_986 -> args . V_997 . V_42 , V_1002 ) ;
F_614 ( F_93 ( V_2 ) -> V_997 ) ;
F_192 ( V_986 -> args . V_320 ) ;
F_116 ( V_172 ) ;
F_8 ( L_83 , V_34 ) ;
}
struct V_1003 *
F_615 ( struct V_985 * V_986 , long * V_60 , T_7 V_1001 )
{
struct V_2 * V_2 = V_986 -> args . V_2 ;
struct V_13 * V_14 = F_105 ( V_2 ) ;
T_9 V_1002 = F_608 ( V_14 ) ;
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_1004 ] ,
. V_333 = & V_986 -> args ,
. V_334 = & V_986 -> V_66 ,
. V_51 = V_986 -> V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_1005 ,
. V_185 = V_986 ,
. V_231 = V_339 ,
} ;
struct V_1003 * V_1006 = NULL ;
struct V_70 V_71 = {
. V_2 = V_2 ,
. V_60 = * V_60 ,
} ;
int V_325 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_616 ( F_93 ( V_2 ) -> V_997 ) ;
V_986 -> args . V_997 . V_42 = F_611 ( V_1002 , V_1001 ) ;
if ( ! V_986 -> args . V_997 . V_42 ) {
F_613 ( V_986 ) ;
return F_57 ( - V_142 ) ;
}
V_986 -> args . V_997 . V_552 = V_1002 * V_648 ;
V_986 -> V_66 . V_1007 = & V_986 -> args . V_997 ;
V_986 -> V_66 . V_177 . V_134 = NULL ;
F_51 ( & V_986 -> args . V_176 , & V_986 -> V_66 . V_177 , 0 ) ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_286 ( V_113 ) ;
V_325 = F_127 ( V_113 ) ;
if ( V_325 == 0 ) {
V_325 = F_604 ( V_113 , V_986 , & V_71 ) ;
* V_60 = V_71 . V_60 ;
}
F_617 ( V_986 -> args . V_320 ,
& V_986 -> args . V_1008 ,
& V_986 -> V_66 . V_1008 ,
& V_986 -> V_66 . V_50 ,
V_325 ) ;
if ( V_325 == 0 && V_986 -> V_66 . V_1007 -> V_12 )
V_1006 = F_618 ( V_986 ) ;
F_77 ( & V_986 -> V_66 . V_177 ) ;
F_90 ( V_113 ) ;
F_8 ( L_16 , V_34 , V_325 ) ;
if ( V_325 )
return F_57 ( V_325 ) ;
return V_1006 ;
}
static void
F_619 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1009 * V_1010 = V_172 ;
F_8 ( L_11 , V_34 ) ;
F_79 ( V_1010 -> V_72 -> V_97 ,
& V_1010 -> args . V_176 ,
& V_1010 -> V_66 . V_177 ,
V_113 ) ;
}
static void F_620 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1009 * V_1010 = V_172 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_68 ( V_113 , & V_1010 -> V_66 . V_177 ) )
return;
V_14 = F_105 ( V_1010 -> args . V_2 ) ;
switch ( V_113 -> V_117 ) {
default:
V_113 -> V_117 = 0 ;
case 0 :
break;
case - V_99 :
if ( F_43 ( V_113 , V_14 , NULL , NULL ) != - V_118 )
break;
F_77 ( & V_1010 -> V_66 . V_177 ) ;
F_73 ( V_113 ) ;
return;
}
F_8 ( L_83 , V_34 ) ;
}
static void F_621 ( void * V_172 )
{
struct V_1009 * V_1010 = V_172 ;
struct V_987 * V_988 = V_1010 -> args . V_997 ;
F_605 ( V_288 ) ;
F_8 ( L_11 , V_34 ) ;
F_46 ( & V_988 -> V_1011 -> V_190 ) ;
if ( V_1010 -> V_66 . V_1012 ) {
F_622 ( V_988 , & V_288 ,
& V_1010 -> args . V_1008 ,
F_623 ( V_1010 -> args . V_50 . V_221 ) ) ;
F_624 ( V_988 , & V_1010 -> V_66 . V_50 , true ) ;
} else
F_606 ( V_988 , & V_288 ) ;
F_625 ( V_988 ) ;
F_48 ( & V_988 -> V_1011 -> V_190 ) ;
F_77 ( & V_1010 -> V_66 . V_177 ) ;
F_607 ( & V_288 ) ;
F_614 ( V_1010 -> args . V_997 ) ;
F_463 ( V_1010 -> V_2 ) ;
F_116 ( V_172 ) ;
F_8 ( L_83 , V_34 ) ;
}
int F_626 ( struct V_1009 * V_1010 , bool V_1013 )
{
struct V_112 * V_113 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_1014 ] ,
. V_333 = & V_1010 -> args ,
. V_334 = & V_1010 -> V_66 ,
. V_51 = V_1010 -> V_52 ,
} ;
struct V_180 V_335 = {
. V_182 = F_105 ( V_1010 -> args . V_2 ) -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_1015 ,
. V_185 = V_1010 ,
} ;
int V_325 = 0 ;
F_284 ( F_105 ( V_1010 -> args . V_2 ) -> V_55 ,
V_886 ,
& V_335 . V_182 , & V_179 ) ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_1013 ) {
V_1010 -> V_2 = F_466 ( V_1010 -> args . V_2 ) ;
if ( ! V_1010 -> V_2 ) {
F_621 ( V_1010 ) ;
return - V_118 ;
}
V_335 . V_231 |= V_339 ;
}
F_51 ( & V_1010 -> args . V_176 , & V_1010 -> V_66 . V_177 , 1 ) ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
if ( V_1013 )
V_325 = V_113 -> V_117 ;
F_627 ( V_1010 -> args . V_2 , & V_1010 -> args . V_50 , V_325 ) ;
F_8 ( L_16 , V_34 , V_325 ) ;
F_90 ( V_113 ) ;
return V_325 ;
}
static int
F_628 ( struct V_13 * V_14 ,
struct V_1016 * V_1017 ,
struct V_51 * V_52 )
{
struct V_1018 args = {
. V_1017 = V_1017 ,
. V_1019 = V_1020 |
V_1021 ,
} ;
struct V_1022 V_66 = {
. V_1017 = V_1017 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_1023 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_325 ;
F_8 ( L_11 , V_34 ) ;
V_325 = F_91 ( V_14 -> V_108 , V_14 , & V_179 , & args . V_176 , & V_66 . V_177 , 0 ) ;
if ( V_66 . V_1024 & ~ args . V_1019 )
F_8 ( L_102 , V_34 ) ;
if ( V_66 . V_1024 != args . V_1019 )
V_1017 -> V_1025 = 1 ;
F_8 ( L_16 , V_34 , V_325 ) ;
return V_325 ;
}
int F_629 ( struct V_13 * V_14 ,
struct V_1016 * V_1017 ,
struct V_51 * V_52 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_628 ( V_14 , V_1017 , V_52 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_630 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1026 * V_174 = V_172 ;
struct V_13 * V_14 = F_105 ( V_174 -> args . V_2 ) ;
struct V_148 * V_149 = F_82 ( V_14 ) ;
F_79 ( V_149 ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static void
F_631 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1026 * V_174 = V_172 ;
struct V_13 * V_14 = F_105 ( V_174 -> args . V_2 ) ;
if ( ! F_75 ( V_113 , & V_174 -> V_66 . V_177 ) )
return;
switch ( V_113 -> V_117 ) {
case - V_78 :
case - V_1027 :
case - V_993 :
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
static void F_632 ( void * V_172 )
{
struct V_1026 * V_174 = V_172 ;
F_633 ( V_174 ) ;
F_467 ( V_174 -> args . V_2 ,
V_174 -> V_66 . V_428 ) ;
F_235 ( V_174 -> V_52 ) ;
F_463 ( V_174 -> V_2 ) ;
F_116 ( V_174 ) ;
}
int
F_634 ( struct V_1026 * V_174 , bool V_1013 )
{
struct V_178 V_179 = {
. V_330 = & V_331 [ V_1028 ] ,
. V_333 = & V_174 -> args ,
. V_334 = & V_174 -> V_66 ,
. V_51 = V_174 -> V_52 ,
} ;
struct V_180 V_335 = {
. V_113 = & V_174 -> V_113 ,
. V_182 = F_323 ( V_174 -> args . V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_1029 ,
. V_185 = V_174 ,
} ;
struct V_112 * V_113 ;
int V_325 = 0 ;
F_8 ( L_103
L_104 , V_1013 ,
V_174 -> args . V_1030 ,
V_174 -> args . V_2 -> V_1031 ) ;
if ( ! V_1013 ) {
V_174 -> V_2 = F_466 ( V_174 -> args . V_2 ) ;
if ( V_174 -> V_2 == NULL ) {
F_632 ( V_174 ) ;
return - V_118 ;
}
V_335 . V_231 = V_339 ;
}
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
V_113 = F_88 ( & V_335 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
if ( V_1013 )
V_325 = V_113 -> V_117 ;
F_635 ( V_174 -> args . V_2 , & V_174 -> args . V_50 , V_325 ) ;
F_8 ( L_105 , V_34 , V_325 ) ;
F_90 ( V_113 ) ;
return V_325 ;
}
static int
F_636 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 ,
struct V_831 * V_518 , bool V_832 )
{
struct V_1032 args = {
. V_1033 = V_1034 ,
} ;
struct V_834 V_66 = {
. V_518 = V_518 ,
} ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_1035 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
} ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_51 * V_52 = NULL ;
int V_325 ;
if ( V_832 ) {
V_65 = V_14 -> V_55 -> V_120 ;
V_52 = F_545 ( V_14 -> V_55 ) ;
V_179 . V_51 = V_52 ;
}
F_8 ( L_11 , V_34 ) ;
V_325 = F_91 ( V_65 , V_14 , & V_179 , & args . V_176 ,
& V_66 . V_177 , 0 ) ;
F_8 ( L_16 , V_34 , V_325 ) ;
if ( V_52 )
F_235 ( V_52 ) ;
return V_325 ;
}
static int
F_637 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 , struct V_831 * V_518 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( V_14 -> V_55 ) )
V_8 = F_636 ( V_14 , V_462 , V_502 ,
V_518 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_636 ( V_14 , V_462 , V_502 ,
V_518 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_1036 :
goto V_160;
default:
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
}
} while ( V_71 . V_77 );
V_160:
return V_8 ;
}
static int
F_638 ( struct V_13 * V_14 , struct V_461 * V_462 ,
struct V_501 * V_502 )
{
int V_8 ;
struct V_525 * V_525 ;
T_5 V_119 = V_1037 ;
struct V_831 * V_518 ;
struct V_1038 * V_1039 ;
int V_515 ;
V_525 = F_304 ( V_413 ) ;
if ( ! V_525 ) {
V_8 = - V_142 ;
goto V_160;
}
V_518 = F_419 ( V_525 ) ;
V_8 = F_637 ( V_14 , V_462 , V_502 , V_518 ) ;
if ( V_8 == - V_22 || V_8 == - V_1036 ) {
V_8 = F_297 ( V_14 , V_462 , V_502 ) ;
goto V_1040;
}
if ( V_8 )
goto V_1040;
for ( V_515 = 0 ; V_515 < V_518 -> V_1041 ; V_515 ++ ) {
V_1039 = & V_518 -> V_518 [ V_515 ] ;
switch ( V_1039 -> V_119 ) {
case V_514 :
case V_513 :
case V_1042 :
V_119 = F_639 ( V_1039 -> V_119 ,
& V_1039 -> V_1043 ) ;
break;
default:
V_119 = V_1037 ;
break;
}
if ( ! F_640 ( & V_14 -> V_516 , V_119 ) )
V_119 = V_1037 ;
if ( V_119 != V_1037 ) {
V_8 = F_295 ( V_14 , V_462 ,
V_502 , V_119 ) ;
if ( ! V_8 )
break;
}
}
if ( V_119 == V_1037 )
V_8 = - V_24 ;
V_1040:
F_433 ( V_525 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_160:
return V_8 ;
}
static int F_641 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
int V_325 ;
struct V_1044 args = {
. V_50 = V_50 ,
} ;
struct V_1045 V_66 ;
struct V_178 V_179 = {
. V_330 = & V_331 [ V_1046 ] ,
. V_333 = & args ,
. V_334 = & V_66 ,
. V_51 = V_52 ,
} ;
struct V_64 * V_182 = V_14 -> V_108 ;
F_284 ( V_14 -> V_55 , V_891 ,
& V_182 , & V_179 ) ;
F_8 ( L_106 , V_50 ) ;
F_51 ( & args . V_176 , & V_66 . V_177 , 0 ) ;
F_52 ( & args . V_176 ) ;
V_325 = F_87 ( V_182 , V_14 , & V_179 ,
& args . V_176 , & V_66 . V_177 ) ;
if ( V_325 != V_384 ) {
F_8 ( L_107 , V_325 ) ;
return V_325 ;
}
F_8 ( L_108 , - V_66 . V_325 ) ;
return - V_66 . V_325 ;
}
static void F_642 ( struct V_13 * V_14 ,
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
static int F_230 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_641 ( V_14 , V_50 , V_52 ) ;
F_642 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_643 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1047 * V_174 = V_172 ;
F_79 ( F_82 ( V_174 -> V_14 ) ,
& V_174 -> args . V_176 ,
& V_174 -> V_66 . V_177 ,
V_113 ) ;
}
static void F_644 ( struct V_112 * V_113 , void * V_172 )
{
struct V_1047 * V_174 = V_172 ;
F_75 ( V_113 , & V_174 -> V_66 . V_177 ) ;
switch ( V_113 -> V_117 ) {
case - V_99 :
if ( F_43 ( V_113 , V_174 -> V_14 , NULL , NULL ) == - V_118 )
F_73 ( V_113 ) ;
}
}
static void F_645 ( void * V_172 )
{
F_116 ( V_172 ) ;
}
static struct V_112 * F_646 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 ,
bool V_144 )
{
struct V_178 V_179 = {
. V_330 = & V_331 [ V_1048 ] ,
. V_51 = V_52 ,
} ;
struct V_180 V_181 = {
. V_182 = V_14 -> V_108 ,
. V_178 = & V_179 ,
. V_183 = & V_1049 ,
. V_231 = V_339 ,
} ;
struct V_1047 * V_174 ;
F_284 ( V_14 -> V_55 , V_891 ,
& V_181 . V_182 , & V_179 ) ;
F_8 ( L_109 , V_50 ) ;
V_174 = F_305 ( sizeof( * V_174 ) , V_322 ) ;
if ( ! V_174 )
return F_57 ( - V_142 ) ;
V_174 -> V_14 = V_14 ;
F_19 ( & V_174 -> args . V_50 , V_50 ) ;
V_181 . V_185 = V_174 ;
V_179 . V_333 = & V_174 -> args ;
V_179 . V_334 = & V_174 -> V_66 ;
F_51 ( & V_174 -> args . V_176 , & V_174 -> V_66 . V_177 , 1 ) ;
if ( V_144 )
F_52 ( & V_174 -> args . V_176 ) ;
return F_88 ( & V_181 ) ;
}
static int F_231 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 ,
bool V_1050 )
{
struct V_112 * V_113 ;
V_113 = F_646 ( V_14 , V_50 , V_52 , V_1050 ) ;
if ( F_56 ( V_113 ) )
return F_89 ( V_113 ) ;
F_90 ( V_113 ) ;
return 0 ;
}
static void
F_647 ( struct V_13 * V_14 , struct V_302 * V_303 )
{
struct V_51 * V_52 = V_303 -> V_304 -> V_244 -> V_301 ;
F_231 ( V_14 , & V_303 -> V_306 , V_52 , false ) ;
F_523 ( V_14 , V_303 ) ;
}
static bool F_648 ( const T_4 * V_1051 ,
const T_4 * V_1052 )
{
if ( V_1051 -> type != V_1052 -> type )
return false ;
if ( memcmp ( V_1051 -> V_1053 , V_1052 -> V_1053 , sizeof( V_1051 -> V_1053 ) ) != 0 )
return false ;
if ( V_1051 -> V_221 == V_1052 -> V_221 )
return true ;
if ( V_1051 -> V_221 == 0 || V_1052 -> V_221 == 0 )
return true ;
return false ;
}
static bool F_649 ( const T_4 * V_1051 ,
const T_4 * V_1052 )
{
return F_158 ( V_1051 , V_1052 ) ;
}
static struct V_235 *
F_650 ( struct V_237 * V_1054 , T_7 V_1055 )
{
return NULL ;
}
static T_11 F_651 ( struct V_4 * V_4 , char * V_804 , T_9 V_1000 )
{
T_11 error , V_1056 ;
error = F_652 ( V_4 , V_804 , V_1000 ) ;
if ( error < 0 )
return error ;
if ( V_804 ) {
V_804 += error ;
V_1000 -= error ;
}
V_1056 = F_531 ( F_14 ( V_4 ) , V_804 , V_1000 ) ;
if ( V_1056 < 0 )
return V_1056 ;
return error + V_1056 ;
}
