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
} else {
V_16 -> V_44 = V_50 | V_24 -> V_51 ;
V_16 -> V_47 = V_52 ;
}
if ( V_16 -> V_42 & V_53 )
V_16 -> V_44 &= ~ V_54 ;
if ( V_24 -> V_27 & V_55 )
V_16 -> V_32 |= V_33 ;
if ( V_24 -> V_27 & V_56 &&
V_16 -> V_42 & V_57 ) {
if ( V_16 -> V_58 == 0 ) {
V_16 -> V_44 &= ~ V_59 ;
V_16 -> V_44 |= V_60 ;
V_16 -> V_47 = V_61 ;
} else {
V_16 -> V_32 |= V_33 ;
}
}
}
void
F_19 ( struct V_15 * V_16 , T_1 * V_62 ,
struct V_23 * V_24 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_42 = F_20 ( V_62 -> V_63 ) ;
V_16 -> V_58 = F_21 ( V_62 -> V_64 ) ;
V_16 -> V_65 = F_21 ( V_62 -> V_66 ) ;
V_16 -> V_67 = F_21 ( V_62 -> V_68 ) ;
V_16 -> V_69 = F_22 ( V_62 -> V_70 ) ;
V_16 -> V_71 = F_22 ( V_62 -> V_72 ) ;
V_16 -> V_73 = F_22 ( V_62 -> V_74 ) ;
F_18 ( V_16 , V_24 ) ;
}
static void
F_23 ( struct V_15 * V_16 , T_2 * V_62 ,
struct V_23 * V_24 )
{
int V_75 = F_17 ( V_24 ) -> V_76 -> V_77 -> V_78 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_69 = F_24 ( V_62 -> V_79 ,
V_62 -> V_70 , V_75 ) ;
V_16 -> V_71 = F_24 ( V_62 -> V_80 ,
V_62 -> V_74 , V_75 ) ;
V_16 -> V_73 = F_24 ( V_62 -> V_80 ,
V_62 -> V_74 , V_75 ) ;
V_16 -> V_42 = F_25 ( V_62 -> V_81 ) ;
V_16 -> V_65 = F_20 ( V_62 -> V_66 ) ;
V_16 -> V_58 = F_20 ( V_62 -> V_82 ) ;
F_18 ( V_16 , V_24 ) ;
}
static int
F_26 ( const unsigned int V_83 , struct V_1 * V_1 )
{
T_3 V_84 ;
int V_85 = 0 ;
char * V_86 = NULL ;
struct V_3 * V_87 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_88 . V_11 -> V_89 ) ;
struct V_90 * V_91 = NULL ;
struct V_34 * V_35 ;
struct V_92 * V_77 ;
if ( V_1 -> V_5 == NULL ) {
V_91 = F_27 ( V_24 ) ;
if ( F_7 ( V_91 ) )
return F_28 ( V_91 ) ;
V_87 = F_29 ( sizeof( struct V_3 ) , V_93 ) ;
if ( V_87 == NULL ) {
V_85 = - V_94 ;
goto V_95;
}
V_1 -> V_5 = V_87 ;
V_87 -> V_91 = F_30 ( V_91 ) ;
V_35 = F_31 ( V_91 ) ;
} else {
V_87 = V_1 -> V_5 ;
V_35 = F_31 ( V_87 -> V_91 ) ;
}
V_77 = V_35 -> V_76 -> V_77 ;
if ( ! V_77 -> V_96 -> V_97 ) {
V_85 = - V_98 ;
goto V_95;
}
V_87 -> V_7 = true ;
V_87 -> V_8 . V_9 = false ;
V_86 = F_32 ( V_1 -> V_88 . V_11 ) ;
if ( V_86 == NULL ) {
V_85 = - V_94 ;
goto V_95;
}
F_2 ( V_6 , L_6 , V_86 , V_1 -> V_99 ) ;
V_100:
if ( V_35 -> V_101 )
V_87 -> V_8 . V_102 = V_103 ;
else if ( ( V_35 -> V_76 -> V_104 &
V_35 -> V_76 -> V_77 -> V_105 -> V_106 ) == 0 ) {
V_87 -> V_8 . V_102 = V_107 ;
} else if ( V_24 -> V_27 & V_28 ) {
V_87 -> V_8 . V_102 = V_108 ;
} else {
V_87 -> V_8 . V_102 = V_109 ;
}
V_84 = V_110 | V_111 ;
if ( F_33 ( V_24 ) )
V_84 |= V_112 ;
V_85 = V_77 -> V_96 -> V_97 ( V_83 , V_35 , V_86 , V_24 ,
& V_87 -> V_113 , V_84 ,
& V_87 -> V_8 ) ;
if ( V_85 == 0 )
V_87 -> V_7 = false ;
else if ( ( V_85 == - V_114 ) &&
( V_24 -> V_27 & V_28 ) ) {
V_24 -> V_27 &= ~ V_28 ;
goto V_100;
}
V_95:
F_34 ( V_86 ) ;
F_35 ( V_91 ) ;
return V_85 ;
}
static int F_36 ( const char * V_115 )
{
int V_116 ;
const T_4 * V_117 = ( const T_4 * ) V_115 ;
for ( V_116 = 0 ; V_116 <= V_118 ; V_116 ++ ) {
if ( V_117 [ V_116 ] == 0 )
return V_116 << 1 ;
}
F_2 ( V_6 , L_7 ) ;
return V_116 << 1 ;
}
static char * F_37 ( char * V_119 , char * V_120 , int V_121 )
{
char * V_122 ;
T_1 * V_123 = ( T_1 * ) V_119 ;
if ( V_121 == V_107 ) {
T_2 * V_124 ;
V_124 = ( T_2 * ) V_123 ;
V_122 = V_119 + sizeof( T_2 ) +
V_124 -> V_125 ;
} else
V_122 = V_119 + F_20 ( V_123 -> V_126 ) ;
F_2 ( V_6 , L_8 , V_122 , V_119 ) ;
if ( V_122 >= V_120 ) {
F_2 ( V_127 , L_9 ,
V_122 , V_120 , V_119 ) ;
return NULL ;
} else if ( ( ( V_121 == V_107 ) &&
( V_122 + sizeof( T_2 ) > V_120 ) )
|| ( ( V_121 != V_107 ) &&
( V_122 + sizeof( T_1 ) > V_120 ) ) ) {
F_2 ( V_127 , L_10 ,
V_122 , V_120 ) ;
return NULL ;
} else
return V_122 ;
}
static void F_38 ( struct V_128 * V_129 ,
const T_5 * V_62 , bool V_130 )
{
V_129 -> V_14 = & V_62 -> V_131 [ 0 ] ;
if ( V_130 )
V_129 -> V_132 = F_36 ( V_129 -> V_14 ) ;
else
V_129 -> V_132 = F_39 ( V_129 -> V_14 , V_118 ) ;
V_129 -> V_133 = V_62 -> V_134 ;
V_129 -> V_135 = F_21 ( V_62 -> V_136 . V_137 ) ;
}
static void F_40 ( struct V_128 * V_129 ,
const T_1 * V_62 )
{
V_129 -> V_14 = & V_62 -> V_131 [ 0 ] ;
V_129 -> V_132 = F_20 ( V_62 -> V_125 ) ;
V_129 -> V_133 = V_62 -> V_138 ;
}
static void F_41 ( struct V_128 * V_129 ,
const T_6 * V_62 )
{
V_129 -> V_14 = & V_62 -> V_131 [ 0 ] ;
V_129 -> V_132 = F_20 ( V_62 -> V_125 ) ;
V_129 -> V_133 = V_62 -> V_138 ;
}
static void F_42 ( struct V_128 * V_129 ,
const T_7 * V_62 )
{
V_129 -> V_14 = & V_62 -> V_131 [ 0 ] ;
V_129 -> V_132 = F_20 ( V_62 -> V_125 ) ;
V_129 -> V_133 = V_62 -> V_138 ;
V_129 -> V_135 = F_21 ( V_62 -> V_137 ) ;
}
static void F_43 ( struct V_128 * V_129 ,
const T_8 * V_62 )
{
V_129 -> V_14 = & V_62 -> V_131 [ 0 ] ;
V_129 -> V_132 = F_20 ( V_62 -> V_125 ) ;
V_129 -> V_133 = V_62 -> V_138 ;
}
static void F_44 ( struct V_128 * V_129 ,
const T_2 * V_62 )
{
V_129 -> V_14 = & V_62 -> V_131 [ 0 ] ;
V_129 -> V_132 = V_62 -> V_125 ;
V_129 -> V_133 = V_62 -> V_134 ;
}
static int F_45 ( struct V_128 * V_129 , const void * V_62 ,
T_9 V_121 , bool V_130 )
{
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
switch ( V_121 ) {
case V_103 :
F_38 ( V_129 , V_62 , V_130 ) ;
break;
case V_109 :
F_40 ( V_129 , V_62 ) ;
break;
case V_139 :
F_41 ( V_129 , V_62 ) ;
break;
case V_108 :
F_42 ( V_129 , V_62 ) ;
break;
case V_140 :
F_43 ( V_129 , V_62 ) ;
break;
case V_107 :
F_44 ( V_129 , V_62 ) ;
break;
default:
F_2 ( V_6 , L_11 , V_121 ) ;
return - V_141 ;
}
return 0 ;
}
static int F_46 ( struct V_128 * V_129 , bool V_130 )
{
int V_85 = 0 ;
if ( ! V_129 -> V_14 )
return 0 ;
if ( V_130 ) {
T_4 * V_142 = ( T_4 * ) V_129 -> V_14 ;
if ( V_129 -> V_132 == 2 ) {
if ( V_142 [ 0 ] == V_143 )
V_85 = 1 ;
} else if ( V_129 -> V_132 == 4 ) {
if ( V_142 [ 0 ] == V_143 &&
V_142 [ 1 ] == V_143 )
V_85 = 2 ;
}
} else {
if ( V_129 -> V_132 == 1 ) {
if ( V_129 -> V_14 [ 0 ] == '.' )
V_85 = 1 ;
} else if ( V_129 -> V_132 == 2 ) {
if ( V_129 -> V_14 [ 0 ] == '.' && V_129 -> V_14 [ 1 ] == '.' )
V_85 = 2 ;
}
}
return V_85 ;
}
static int F_47 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = F_48 ( V_1 ) ;
struct V_144 * V_145 = F_8 ( V_18 ) ;
if ( V_145 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_49 ( const char * V_146 ,
struct V_3 * V_147 )
{
struct V_128 V_129 ;
int V_85 ;
V_85 = F_45 ( & V_129 , V_146 , V_147 -> V_8 . V_102 ,
V_147 -> V_8 . V_148 ) ;
if ( ! V_85 ) {
V_147 -> V_8 . V_149 = V_129 . V_14 ;
V_147 -> V_8 . V_150 = V_129 . V_132 ;
V_147 -> V_8 . V_133 = V_129 . V_133 ;
}
return V_85 ;
}
static int
F_50 ( const unsigned int V_83 , struct V_34 * V_35 , T_10 V_151 ,
struct V_1 * V_1 , char * * V_146 , int * V_152 )
{
T_3 V_84 ;
int V_85 = 0 ;
int V_153 = 0 ;
T_10 V_154 ;
T_10 V_155 = V_151 ;
struct V_3 * V_156 = V_1 -> V_5 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_88 . V_11 -> V_89 ) ;
struct V_92 * V_77 = V_35 -> V_76 -> V_77 ;
if ( ! V_77 -> V_96 -> V_97 || ! V_77 -> V_96 -> V_157 )
return - V_98 ;
if ( ( V_156 == NULL ) || ( V_146 == NULL ) || ( V_152 == NULL ) )
return - V_158 ;
* V_146 = NULL ;
V_154 = V_156 -> V_8 . V_159 -
V_156 -> V_8 . V_160 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_155 < V_156 -> V_8 . V_159 ) &&
F_47 ( V_1 ) ) || ( V_155 < V_154 ) ) {
F_2 ( V_6 , L_13 ) ;
F_51 ( & V_161 ) ;
if ( ! V_156 -> V_8 . V_9 && ! V_156 -> V_7 ) {
V_156 -> V_7 = true ;
F_52 ( & V_161 ) ;
if ( V_77 -> V_96 -> V_162 )
V_77 -> V_96 -> V_162 ( V_83 , V_35 , & V_156 -> V_113 ) ;
} else
F_52 ( & V_161 ) ;
if ( V_156 -> V_8 . V_163 ) {
F_2 ( V_6 , L_14 ) ;
if ( V_156 -> V_8 . V_164 )
F_53 ( V_156 -> V_8 .
V_163 ) ;
else
F_54 ( V_156 -> V_8 .
V_163 ) ;
V_156 -> V_8 . V_163 = NULL ;
}
V_85 = F_26 ( V_83 , V_1 ) ;
if ( V_85 ) {
F_2 ( V_6 , L_15 ,
V_85 ) ;
return V_85 ;
}
if ( V_156 -> V_8 . V_165 )
F_49 ( V_156 -> V_8 . V_165 , V_156 ) ;
}
V_84 = V_110 | V_111 ;
if ( F_33 ( V_24 ) )
V_84 |= V_112 ;
while ( ( V_155 >= V_156 -> V_8 . V_159 ) &&
( V_85 == 0 ) && ! V_156 -> V_8 . V_9 ) {
F_2 ( V_6 , L_16 ) ;
V_85 = V_77 -> V_96 -> V_157 ( V_83 , V_35 , & V_156 -> V_113 ,
V_84 ,
& V_156 -> V_8 ) ;
if ( V_156 -> V_8 . V_165 )
F_49 ( V_156 -> V_8 . V_165 , V_156 ) ;
if ( V_85 )
return - V_158 ;
}
if ( V_155 < V_156 -> V_8 . V_159 ) {
int V_166 ;
char * V_167 ;
char * V_120 = V_156 -> V_8 . V_163 +
V_77 -> V_96 -> V_168 (
V_156 -> V_8 . V_163 ) ;
V_167 = V_156 -> V_8 . V_169 ;
V_154 = V_156 -> V_8 . V_159
- V_156 -> V_8 . V_160 ;
V_153 = V_155 - V_154 ;
F_2 ( V_6 , L_17 , V_153 ) ;
for ( V_166 = 0 ; ( V_166 < ( V_153 ) ) && ( V_167 != NULL ) ; V_166 ++ ) {
V_167 = F_37 ( V_167 , V_120 ,
V_156 -> V_8 . V_102 ) ;
}
if ( ( V_167 == NULL ) && ( V_166 < V_153 ) ) {
F_2 ( V_127 , L_18 ,
V_153 , V_155 , V_85 ) ;
}
V_85 = 0 ;
* V_146 = V_167 ;
} else {
F_2 ( V_6 , L_19 ) ;
return 0 ;
}
if ( V_153 >= V_156 -> V_8 . V_160 ) {
F_2 ( V_6 , L_20 ) ;
* V_152 = 0 ;
} else
* V_152 = V_156 -> V_8 . V_160 - V_153 ;
return V_85 ;
}
static int F_55 ( char * V_170 , struct V_1 * V_1 ,
struct V_171 * V_172 ,
char * V_173 , unsigned int V_174 )
{
struct V_3 * V_147 = V_1 -> V_5 ;
struct V_19 * V_20 = V_1 -> V_88 . V_11 -> V_89 ;
struct V_23 * V_24 = F_4 ( V_20 ) ;
struct V_128 V_129 = { NULL , } ;
struct V_15 V_16 ;
struct V_13 V_14 ;
int V_85 = 0 ;
T_11 V_135 ;
V_85 = F_45 ( & V_129 , V_170 , V_147 -> V_8 . V_102 ,
V_147 -> V_8 . V_148 ) ;
if ( V_85 )
return V_85 ;
if ( V_129 . V_132 > V_174 ) {
F_2 ( V_127 , L_21 ,
V_129 . V_132 ) ;
return - V_141 ;
}
if ( F_46 ( & V_129 , V_147 -> V_8 . V_148 ) )
return 0 ;
if ( V_147 -> V_8 . V_148 ) {
struct V_175 * V_176 = V_24 -> V_177 ;
V_14 . V_14 = V_173 ;
V_14 . V_116 =
F_56 ( ( char * ) V_14 . V_14 , ( T_4 * ) V_129 . V_14 ,
V_178 ,
F_57 ( V_179 , V_129 . V_132 ,
( V_179 ) V_174 ) , V_176 ,
V_24 -> V_27 &
V_180 ) ;
V_14 . V_116 -= F_58 ( V_176 ) ;
} else {
V_14 . V_14 = V_129 . V_14 ;
V_14 . V_116 = V_129 . V_132 ;
}
switch ( V_147 -> V_8 . V_102 ) {
case V_103 :
F_59 ( & V_16 ,
& ( ( T_5 * ) V_170 ) -> V_136 ,
V_24 ) ;
break;
case V_107 :
F_23 ( & V_16 ,
( T_2 * ) V_170 ,
V_24 ) ;
break;
default:
F_19 ( & V_16 ,
( T_1 * ) V_170 ,
V_24 ) ;
break;
}
if ( V_129 . V_135 && ( V_24 -> V_27 & V_28 ) ) {
V_16 . V_29 = V_129 . V_135 ;
} else {
V_16 . V_29 = F_60 ( V_20 , V_181 ) ;
F_61 ( V_24 ) ;
}
if ( ( V_24 -> V_27 & V_182 ) &&
F_62 ( & V_16 ) )
V_16 . V_32 |= V_33 ;
F_3 ( V_1 -> V_183 , & V_14 , & V_16 ) ;
V_135 = F_63 ( V_16 . V_29 ) ;
return ! F_64 ( V_172 , V_14 . V_14 , V_14 . V_116 , V_135 , V_16 . V_47 ) ;
}
int F_65 ( struct V_1 * V_1 , struct V_171 * V_172 )
{
int V_85 = 0 ;
unsigned int V_83 ;
int V_166 ;
struct V_34 * V_35 ;
struct V_3 * V_87 = NULL ;
char * V_146 ;
int V_184 = 0 ;
char * V_185 = NULL ;
char * V_120 ;
unsigned int V_174 ;
V_83 = F_66 () ;
if ( V_1 -> V_5 == NULL ) {
V_85 = F_26 ( V_83 , V_1 ) ;
F_2 ( V_6 , L_22 , V_85 ) ;
if ( V_85 )
goto V_186;
}
if ( ! F_67 ( V_1 , V_172 ) )
goto V_186;
if ( V_1 -> V_5 == NULL ) {
V_85 = - V_141 ;
goto V_186;
}
V_87 = V_1 -> V_5 ;
if ( V_87 -> V_8 . V_9 ) {
if ( V_87 -> V_8 . V_10 ) {
F_2 ( V_6 , L_23 ) ;
V_85 = 0 ;
goto V_186;
}
}
V_35 = F_31 ( V_87 -> V_91 ) ;
V_85 = F_50 ( V_83 , V_35 , V_172 -> V_151 , V_1 , & V_146 ,
& V_184 ) ;
if ( V_85 ) {
F_2 ( V_6 , L_24 , V_85 ) ;
goto V_186;
} else if ( V_146 != NULL ) {
F_2 ( V_6 , L_25 , V_172 -> V_151 ) ;
} else {
F_2 ( V_6 , L_26 ) ;
goto V_186;
}
F_2 ( V_6 , L_27 ,
V_184 , V_87 -> V_8 . V_163 ) ;
V_174 = V_35 -> V_76 -> V_77 -> V_96 -> V_168 (
V_87 -> V_8 . V_163 ) ;
V_120 = V_87 -> V_8 . V_163 + V_174 ;
V_185 = F_68 ( V_178 , V_93 ) ;
if ( V_185 == NULL ) {
V_85 = - V_94 ;
goto V_186;
}
for ( V_166 = 0 ; V_166 < V_184 ; V_166 ++ ) {
if ( V_146 == NULL ) {
F_2 ( V_127 , L_28 ,
V_184 , V_166 ) ;
break;
}
V_85 = F_55 ( V_146 , V_1 , V_172 ,
V_185 , V_174 ) ;
if ( V_85 ) {
if ( V_85 > 0 )
V_85 = 0 ;
break;
}
V_172 -> V_151 ++ ;
if ( V_172 -> V_151 ==
V_87 -> V_8 . V_159 ) {
F_2 ( V_6 , L_29 ,
V_172 -> V_151 , V_185 ) ;
F_49 ( V_146 , V_87 ) ;
break;
} else
V_146 =
F_37 ( V_146 , V_120 ,
V_87 -> V_8 . V_102 ) ;
}
F_34 ( V_185 ) ;
V_186:
F_69 ( V_83 ) ;
return V_85 ;
}
