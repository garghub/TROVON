static void F_1 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 ;
if ( V_1 ) {
V_4 = V_1 -> V_5 ;
if ( V_4 == NULL ) {
F_2 ( V_6 , L_1 ) ;
return;
}
if ( V_4 -> V_7 )
F_2 ( V_6 , L_2 ) ;
if ( V_4 -> V_8 . V_9 )
F_2 ( V_6 , L_3 ) ;
if ( V_4 -> V_8 . V_10 )
F_2 ( V_6 , L_4 ) ;
}
}
static inline void F_1 ( struct V_1 * V_1 , char * V_2 )
{
}
static void
F_3 ( struct V_11 * V_12 , struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_11 * V_11 , * V_17 ;
struct V_18 * V_18 ;
struct V_19 * V_20 = V_12 -> V_21 -> V_22 ;
struct V_23 * V_24 = F_4 ( V_20 ) ;
F_2 ( V_6 , L_5 , V_25 , V_14 -> V_14 ) ;
V_11 = F_5 ( V_12 , V_14 ) ;
if ( F_6 ( F_7 ( V_11 ) ) )
return;
if ( V_11 ) {
int V_26 ;
V_18 = V_11 -> V_21 ;
if ( V_18 ) {
if ( ! ( V_24 -> V_27 & V_28 ) )
V_16 -> V_29 = F_8 ( V_18 ) -> V_30 ;
if ( F_8 ( V_18 ) -> V_30 == V_16 -> V_29 ) {
F_9 ( V_18 , V_16 ) ;
goto V_31;
}
}
V_26 = F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
if ( V_26 )
return;
}
if ( V_16 -> V_32 & V_33 )
return;
V_11 = F_12 ( V_12 , V_14 ) ;
if ( ! V_11 )
return;
V_18 = F_13 ( V_20 , V_16 ) ;
if ( ! V_18 )
goto V_31;
V_17 = F_14 ( V_11 , V_18 ) ;
if ( V_17 && ! F_7 ( V_17 ) )
F_11 ( V_17 ) ;
V_31:
F_11 ( V_11 ) ;
}
static bool
F_15 ( struct V_23 * V_24 )
{
#ifdef F_16
struct V_34 * V_35 = F_17 ( V_24 ) ;
if ( V_35 -> V_36 & V_37 )
return true ;
#endif
return false ;
}
static void
F_18 ( struct V_15 * V_16 , struct V_23 * V_24 )
{
V_16 -> V_38 = V_24 -> V_39 ;
V_16 -> V_40 = V_24 -> V_41 ;
if ( V_16 -> V_42 & V_43 ) {
V_16 -> V_44 = V_45 | V_24 -> V_46 ;
V_16 -> V_47 = V_48 ;
if ( F_15 ( V_24 ) &&
( V_16 -> V_42 & V_49 ) )
V_16 -> V_32 |= V_33 ;
} else if ( V_16 -> V_42 & V_49 ) {
V_16 -> V_44 = V_50 ;
V_16 -> V_47 = V_51 ;
} else {
V_16 -> V_44 = V_52 | V_24 -> V_53 ;
V_16 -> V_47 = V_54 ;
}
V_16 -> V_32 |= V_55 ;
if ( V_16 -> V_42 & V_56 )
V_16 -> V_44 &= ~ V_57 ;
if ( V_24 -> V_27 & V_58 )
V_16 -> V_32 |= V_33 ;
if ( V_24 -> V_27 & V_59 &&
V_16 -> V_42 & V_60 ) {
if ( V_16 -> V_61 == 0 ) {
V_16 -> V_44 &= ~ V_62 ;
V_16 -> V_44 |= V_63 ;
V_16 -> V_47 = V_64 ;
} else {
V_16 -> V_32 |= V_33 ;
}
}
}
void
F_19 ( struct V_15 * V_16 , T_1 * V_65 ,
struct V_23 * V_24 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_42 = F_20 ( V_65 -> V_66 ) ;
V_16 -> V_61 = F_21 ( V_65 -> V_67 ) ;
V_16 -> V_68 = F_21 ( V_65 -> V_69 ) ;
V_16 -> V_70 = F_21 ( V_65 -> V_71 ) ;
V_16 -> V_72 = F_22 ( V_65 -> V_73 ) ;
V_16 -> V_74 = F_22 ( V_65 -> V_75 ) ;
V_16 -> V_76 = F_22 ( V_65 -> V_77 ) ;
F_18 ( V_16 , V_24 ) ;
}
static void
F_23 ( struct V_15 * V_16 , T_2 * V_65 ,
struct V_23 * V_24 )
{
int V_78 = F_17 ( V_24 ) -> V_79 -> V_80 -> V_81 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_72 = F_24 ( V_65 -> V_82 ,
V_65 -> V_73 , V_78 ) ;
V_16 -> V_74 = F_24 ( V_65 -> V_83 ,
V_65 -> V_77 , V_78 ) ;
V_16 -> V_76 = F_24 ( V_65 -> V_83 ,
V_65 -> V_77 , V_78 ) ;
V_16 -> V_42 = F_25 ( V_65 -> V_84 ) ;
V_16 -> V_68 = F_20 ( V_65 -> V_69 ) ;
V_16 -> V_61 = F_20 ( V_65 -> V_85 ) ;
F_18 ( V_16 , V_24 ) ;
}
static int
F_26 ( const unsigned int V_86 , struct V_1 * V_1 )
{
T_3 V_87 ;
int V_88 = 0 ;
char * V_89 = NULL ;
struct V_3 * V_90 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_91 . V_11 -> V_92 ) ;
struct V_93 * V_94 = NULL ;
struct V_34 * V_35 ;
struct V_95 * V_80 ;
if ( V_1 -> V_5 == NULL ) {
V_94 = F_27 ( V_24 ) ;
if ( F_7 ( V_94 ) )
return F_28 ( V_94 ) ;
V_90 = F_29 ( sizeof( struct V_3 ) , V_96 ) ;
if ( V_90 == NULL ) {
V_88 = - V_97 ;
goto V_98;
}
V_1 -> V_5 = V_90 ;
V_90 -> V_94 = F_30 ( V_94 ) ;
V_35 = F_31 ( V_94 ) ;
} else {
V_90 = V_1 -> V_5 ;
V_35 = F_31 ( V_90 -> V_94 ) ;
}
V_80 = V_35 -> V_79 -> V_80 ;
if ( ! V_80 -> V_99 -> V_100 ) {
V_88 = - V_101 ;
goto V_98;
}
V_90 -> V_7 = true ;
V_90 -> V_8 . V_9 = false ;
V_89 = F_32 ( V_1 -> V_91 . V_11 ) ;
if ( V_89 == NULL ) {
V_88 = - V_97 ;
goto V_98;
}
F_2 ( V_6 , L_6 , V_89 , V_1 -> V_102 ) ;
V_103:
if ( V_35 -> V_104 )
V_90 -> V_8 . V_105 = V_106 ;
else if ( ( V_35 -> V_79 -> V_107 &
V_35 -> V_79 -> V_80 -> V_108 -> V_109 ) == 0 ) {
V_90 -> V_8 . V_105 = V_110 ;
} else if ( V_24 -> V_27 & V_28 ) {
V_90 -> V_8 . V_105 = V_111 ;
} else {
V_90 -> V_8 . V_105 = V_112 ;
}
V_87 = V_113 | V_114 ;
if ( F_33 ( V_24 ) )
V_87 |= V_115 ;
V_88 = V_80 -> V_99 -> V_100 ( V_86 , V_35 , V_89 , V_24 ,
& V_90 -> V_116 , V_87 ,
& V_90 -> V_8 ) ;
if ( V_88 == 0 )
V_90 -> V_7 = false ;
else if ( ( V_88 == - V_117 ) &&
( V_24 -> V_27 & V_28 ) ) {
V_24 -> V_27 &= ~ V_28 ;
goto V_103;
}
V_98:
F_34 ( V_89 ) ;
F_35 ( V_94 ) ;
return V_88 ;
}
static int F_36 ( const char * V_118 )
{
int V_119 ;
const T_4 * V_120 = ( const T_4 * ) V_118 ;
for ( V_119 = 0 ; V_119 <= V_121 ; V_119 ++ ) {
if ( V_120 [ V_119 ] == 0 )
return V_119 << 1 ;
}
F_2 ( V_6 , L_7 ) ;
return V_119 << 1 ;
}
static char * F_37 ( char * V_122 , char * V_123 , int V_124 )
{
char * V_125 ;
T_1 * V_126 = ( T_1 * ) V_122 ;
if ( V_124 == V_110 ) {
T_2 * V_127 ;
V_127 = ( T_2 * ) V_126 ;
V_125 = V_122 + sizeof( T_2 ) +
V_127 -> V_128 ;
} else
V_125 = V_122 + F_20 ( V_126 -> V_129 ) ;
F_2 ( V_6 , L_8 , V_125 , V_122 ) ;
if ( V_125 >= V_123 ) {
F_2 ( V_130 , L_9 ,
V_125 , V_123 , V_122 ) ;
return NULL ;
} else if ( ( ( V_124 == V_110 ) &&
( V_125 + sizeof( T_2 ) > V_123 ) )
|| ( ( V_124 != V_110 ) &&
( V_125 + sizeof( T_1 ) > V_123 ) ) ) {
F_2 ( V_130 , L_10 ,
V_125 , V_123 ) ;
return NULL ;
} else
return V_125 ;
}
static void F_38 ( struct V_131 * V_132 ,
const T_5 * V_65 , bool V_133 )
{
V_132 -> V_14 = & V_65 -> V_134 [ 0 ] ;
if ( V_133 )
V_132 -> V_135 = F_36 ( V_132 -> V_14 ) ;
else
V_132 -> V_135 = F_39 ( V_132 -> V_14 , V_121 ) ;
V_132 -> V_136 = V_65 -> V_137 ;
V_132 -> V_138 = F_21 ( V_65 -> V_139 . V_140 ) ;
}
static void F_40 ( struct V_131 * V_132 ,
const T_1 * V_65 )
{
V_132 -> V_14 = & V_65 -> V_134 [ 0 ] ;
V_132 -> V_135 = F_20 ( V_65 -> V_128 ) ;
V_132 -> V_136 = V_65 -> V_141 ;
}
static void F_41 ( struct V_131 * V_132 ,
const T_6 * V_65 )
{
V_132 -> V_14 = & V_65 -> V_134 [ 0 ] ;
V_132 -> V_135 = F_20 ( V_65 -> V_128 ) ;
V_132 -> V_136 = V_65 -> V_141 ;
}
static void F_42 ( struct V_131 * V_132 ,
const T_7 * V_65 )
{
V_132 -> V_14 = & V_65 -> V_134 [ 0 ] ;
V_132 -> V_135 = F_20 ( V_65 -> V_128 ) ;
V_132 -> V_136 = V_65 -> V_141 ;
V_132 -> V_138 = F_21 ( V_65 -> V_140 ) ;
}
static void F_43 ( struct V_131 * V_132 ,
const T_8 * V_65 )
{
V_132 -> V_14 = & V_65 -> V_134 [ 0 ] ;
V_132 -> V_135 = F_20 ( V_65 -> V_128 ) ;
V_132 -> V_136 = V_65 -> V_141 ;
}
static void F_44 ( struct V_131 * V_132 ,
const T_2 * V_65 )
{
V_132 -> V_14 = & V_65 -> V_134 [ 0 ] ;
V_132 -> V_135 = V_65 -> V_128 ;
V_132 -> V_136 = V_65 -> V_137 ;
}
static int F_45 ( struct V_131 * V_132 , const void * V_65 ,
T_9 V_124 , bool V_133 )
{
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
switch ( V_124 ) {
case V_106 :
F_38 ( V_132 , V_65 , V_133 ) ;
break;
case V_112 :
F_40 ( V_132 , V_65 ) ;
break;
case V_142 :
F_41 ( V_132 , V_65 ) ;
break;
case V_111 :
F_42 ( V_132 , V_65 ) ;
break;
case V_143 :
F_43 ( V_132 , V_65 ) ;
break;
case V_110 :
F_44 ( V_132 , V_65 ) ;
break;
default:
F_2 ( V_6 , L_11 , V_124 ) ;
return - V_144 ;
}
return 0 ;
}
static int F_46 ( struct V_131 * V_132 , bool V_133 )
{
int V_88 = 0 ;
if ( ! V_132 -> V_14 )
return 0 ;
if ( V_133 ) {
T_4 * V_145 = ( T_4 * ) V_132 -> V_14 ;
if ( V_132 -> V_135 == 2 ) {
if ( V_145 [ 0 ] == V_146 )
V_88 = 1 ;
} else if ( V_132 -> V_135 == 4 ) {
if ( V_145 [ 0 ] == V_146 &&
V_145 [ 1 ] == V_146 )
V_88 = 2 ;
}
} else {
if ( V_132 -> V_135 == 1 ) {
if ( V_132 -> V_14 [ 0 ] == '.' )
V_88 = 1 ;
} else if ( V_132 -> V_135 == 2 ) {
if ( V_132 -> V_14 [ 0 ] == '.' && V_132 -> V_14 [ 1 ] == '.' )
V_88 = 2 ;
}
}
return V_88 ;
}
static int F_47 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = F_48 ( V_1 ) ;
struct V_147 * V_148 = F_8 ( V_18 ) ;
if ( V_148 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_49 ( const char * V_149 ,
struct V_3 * V_150 )
{
struct V_131 V_132 ;
int V_88 ;
V_88 = F_45 ( & V_132 , V_149 , V_150 -> V_8 . V_105 ,
V_150 -> V_8 . V_151 ) ;
if ( ! V_88 ) {
V_150 -> V_8 . V_152 = V_132 . V_14 ;
V_150 -> V_8 . V_153 = V_132 . V_135 ;
V_150 -> V_8 . V_136 = V_132 . V_136 ;
}
return V_88 ;
}
static int
F_50 ( const unsigned int V_86 , struct V_34 * V_35 , T_10 V_154 ,
struct V_1 * V_1 , char * * V_149 , int * V_155 )
{
T_3 V_87 ;
int V_88 = 0 ;
int V_156 = 0 ;
T_10 V_157 ;
T_10 V_158 = V_154 ;
struct V_3 * V_159 = V_1 -> V_5 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_91 . V_11 -> V_92 ) ;
struct V_95 * V_80 = V_35 -> V_79 -> V_80 ;
if ( ! V_80 -> V_99 -> V_100 || ! V_80 -> V_99 -> V_160 )
return - V_101 ;
if ( ( V_159 == NULL ) || ( V_149 == NULL ) || ( V_155 == NULL ) )
return - V_161 ;
* V_149 = NULL ;
V_157 = V_159 -> V_8 . V_162 -
V_159 -> V_8 . V_163 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_158 < V_159 -> V_8 . V_162 ) &&
F_47 ( V_1 ) ) || ( V_158 < V_157 ) ) {
F_2 ( V_6 , L_13 ) ;
F_51 ( & V_164 ) ;
if ( ! V_159 -> V_8 . V_9 && ! V_159 -> V_7 ) {
V_159 -> V_7 = true ;
F_52 ( & V_164 ) ;
if ( V_80 -> V_99 -> V_165 )
V_80 -> V_99 -> V_165 ( V_86 , V_35 , & V_159 -> V_116 ) ;
} else
F_52 ( & V_164 ) ;
if ( V_159 -> V_8 . V_166 ) {
F_2 ( V_6 , L_14 ) ;
if ( V_159 -> V_8 . V_167 )
F_53 ( V_159 -> V_8 .
V_166 ) ;
else
F_54 ( V_159 -> V_8 .
V_166 ) ;
V_159 -> V_8 . V_166 = NULL ;
}
V_88 = F_26 ( V_86 , V_1 ) ;
if ( V_88 ) {
F_2 ( V_6 , L_15 ,
V_88 ) ;
return V_88 ;
}
if ( V_159 -> V_8 . V_168 )
F_49 ( V_159 -> V_8 . V_168 , V_159 ) ;
}
V_87 = V_113 | V_114 ;
if ( F_33 ( V_24 ) )
V_87 |= V_115 ;
while ( ( V_158 >= V_159 -> V_8 . V_162 ) &&
( V_88 == 0 ) && ! V_159 -> V_8 . V_9 ) {
F_2 ( V_6 , L_16 ) ;
V_88 = V_80 -> V_99 -> V_160 ( V_86 , V_35 , & V_159 -> V_116 ,
V_87 ,
& V_159 -> V_8 ) ;
if ( V_159 -> V_8 . V_168 )
F_49 ( V_159 -> V_8 . V_168 , V_159 ) ;
if ( V_88 )
return - V_161 ;
}
if ( V_158 < V_159 -> V_8 . V_162 ) {
int V_169 ;
char * V_170 ;
char * V_123 = V_159 -> V_8 . V_166 +
V_80 -> V_99 -> V_171 (
V_159 -> V_8 . V_166 ) ;
V_170 = V_159 -> V_8 . V_172 ;
V_157 = V_159 -> V_8 . V_162
- V_159 -> V_8 . V_163 ;
V_156 = V_158 - V_157 ;
F_2 ( V_6 , L_17 , V_156 ) ;
for ( V_169 = 0 ; ( V_169 < ( V_156 ) ) && ( V_170 != NULL ) ; V_169 ++ ) {
V_170 = F_37 ( V_170 , V_123 ,
V_159 -> V_8 . V_105 ) ;
}
if ( ( V_170 == NULL ) && ( V_169 < V_156 ) ) {
F_2 ( V_130 , L_18 ,
V_156 , V_158 , V_88 ) ;
}
V_88 = 0 ;
* V_149 = V_170 ;
} else {
F_2 ( V_6 , L_19 ) ;
return 0 ;
}
if ( V_156 >= V_159 -> V_8 . V_163 ) {
F_2 ( V_6 , L_20 ) ;
* V_155 = 0 ;
} else
* V_155 = V_159 -> V_8 . V_163 - V_156 ;
return V_88 ;
}
static int F_55 ( char * V_173 , struct V_1 * V_1 ,
struct V_174 * V_175 ,
char * V_176 , unsigned int V_177 )
{
struct V_3 * V_150 = V_1 -> V_5 ;
struct V_19 * V_20 = V_1 -> V_91 . V_11 -> V_92 ;
struct V_23 * V_24 = F_4 ( V_20 ) ;
struct V_131 V_132 = { NULL , } ;
struct V_15 V_16 ;
struct V_13 V_14 ;
int V_88 = 0 ;
T_11 V_138 ;
V_88 = F_45 ( & V_132 , V_173 , V_150 -> V_8 . V_105 ,
V_150 -> V_8 . V_151 ) ;
if ( V_88 )
return V_88 ;
if ( V_132 . V_135 > V_177 ) {
F_2 ( V_130 , L_21 ,
V_132 . V_135 ) ;
return - V_144 ;
}
if ( F_46 ( & V_132 , V_150 -> V_8 . V_151 ) )
return 0 ;
if ( V_150 -> V_8 . V_151 ) {
struct V_178 * V_179 = V_24 -> V_180 ;
V_14 . V_14 = V_176 ;
V_14 . V_119 =
F_56 ( ( char * ) V_14 . V_14 , ( T_4 * ) V_132 . V_14 ,
V_181 ,
F_57 ( V_182 , V_132 . V_135 ,
( V_182 ) V_177 ) , V_179 ,
V_24 -> V_27 &
V_183 ) ;
V_14 . V_119 -= F_58 ( V_179 ) ;
} else {
V_14 . V_14 = V_132 . V_14 ;
V_14 . V_119 = V_132 . V_135 ;
}
switch ( V_150 -> V_8 . V_105 ) {
case V_106 :
F_59 ( & V_16 ,
& ( ( T_5 * ) V_173 ) -> V_139 ,
V_24 ) ;
break;
case V_110 :
F_23 ( & V_16 ,
( T_2 * ) V_173 ,
V_24 ) ;
break;
default:
F_19 ( & V_16 ,
( T_1 * ) V_173 ,
V_24 ) ;
break;
}
if ( V_132 . V_138 && ( V_24 -> V_27 & V_28 ) ) {
V_16 . V_29 = V_132 . V_138 ;
} else {
V_16 . V_29 = F_60 ( V_20 , V_184 ) ;
F_61 ( V_24 ) ;
}
if ( ( V_24 -> V_27 & V_185 ) &&
F_62 ( & V_16 ) )
V_16 . V_32 |= V_33 ;
F_3 ( V_1 -> V_186 , & V_14 , & V_16 ) ;
V_138 = F_63 ( V_16 . V_29 ) ;
return ! F_64 ( V_175 , V_14 . V_14 , V_14 . V_119 , V_138 , V_16 . V_47 ) ;
}
int F_65 ( struct V_1 * V_1 , struct V_174 * V_175 )
{
int V_88 = 0 ;
unsigned int V_86 ;
int V_169 ;
struct V_34 * V_35 ;
struct V_3 * V_90 = NULL ;
char * V_149 ;
int V_187 = 0 ;
char * V_188 = NULL ;
char * V_123 ;
unsigned int V_177 ;
V_86 = F_66 () ;
if ( V_1 -> V_5 == NULL ) {
V_88 = F_26 ( V_86 , V_1 ) ;
F_2 ( V_6 , L_22 , V_88 ) ;
if ( V_88 )
goto V_189;
}
if ( ! F_67 ( V_1 , V_175 ) )
goto V_189;
if ( V_1 -> V_5 == NULL ) {
V_88 = - V_144 ;
goto V_189;
}
V_90 = V_1 -> V_5 ;
if ( V_90 -> V_8 . V_9 ) {
if ( V_90 -> V_8 . V_10 ) {
F_2 ( V_6 , L_23 ) ;
V_88 = 0 ;
goto V_189;
}
}
V_35 = F_31 ( V_90 -> V_94 ) ;
V_88 = F_50 ( V_86 , V_35 , V_175 -> V_154 , V_1 , & V_149 ,
& V_187 ) ;
if ( V_88 ) {
F_2 ( V_6 , L_24 , V_88 ) ;
goto V_189;
} else if ( V_149 != NULL ) {
F_2 ( V_6 , L_25 , V_175 -> V_154 ) ;
} else {
F_2 ( V_6 , L_26 ) ;
goto V_189;
}
F_2 ( V_6 , L_27 ,
V_187 , V_90 -> V_8 . V_166 ) ;
V_177 = V_35 -> V_79 -> V_80 -> V_99 -> V_171 (
V_90 -> V_8 . V_166 ) ;
V_123 = V_90 -> V_8 . V_166 + V_177 ;
V_188 = F_68 ( V_181 , V_96 ) ;
if ( V_188 == NULL ) {
V_88 = - V_97 ;
goto V_189;
}
for ( V_169 = 0 ; V_169 < V_187 ; V_169 ++ ) {
if ( V_149 == NULL ) {
F_2 ( V_130 , L_28 ,
V_187 , V_169 ) ;
break;
}
V_88 = F_55 ( V_149 , V_1 , V_175 ,
V_188 , V_177 ) ;
if ( V_88 ) {
if ( V_88 > 0 )
V_88 = 0 ;
break;
}
V_175 -> V_154 ++ ;
if ( V_175 -> V_154 ==
V_90 -> V_8 . V_162 ) {
F_2 ( V_6 , L_29 ,
V_175 -> V_154 , V_188 ) ;
F_49 ( V_149 , V_90 ) ;
break;
} else
V_149 =
F_37 ( V_149 , V_123 ,
V_90 -> V_8 . V_105 ) ;
}
F_34 ( V_188 ) ;
V_189:
F_69 ( V_86 ) ;
return V_88 ;
}
