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
static void
F_15 ( struct V_15 * V_16 , struct V_23 * V_24 )
{
V_16 -> V_34 = V_24 -> V_35 ;
V_16 -> V_36 = V_24 -> V_37 ;
if ( V_16 -> V_38 & V_39 ) {
V_16 -> V_40 = V_41 | V_24 -> V_42 ;
V_16 -> V_43 = V_44 ;
} else {
V_16 -> V_40 = V_45 | V_24 -> V_46 ;
V_16 -> V_43 = V_47 ;
}
if ( V_16 -> V_38 & V_48 )
V_16 -> V_32 |= V_33 ;
V_16 -> V_32 |= V_49 ;
if ( V_16 -> V_38 & V_50 )
V_16 -> V_40 &= ~ V_51 ;
if ( V_24 -> V_27 & V_52 )
V_16 -> V_32 |= V_33 ;
if ( V_24 -> V_27 & V_53 &&
V_16 -> V_38 & V_54 ) {
if ( V_16 -> V_55 == 0 ) {
V_16 -> V_40 &= ~ V_56 ;
V_16 -> V_40 |= V_57 ;
V_16 -> V_43 = V_58 ;
} else {
V_16 -> V_32 |= V_33 ;
}
}
}
void
F_16 ( struct V_15 * V_16 , T_1 * V_59 ,
struct V_23 * V_24 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_38 = F_17 ( V_59 -> V_60 ) ;
V_16 -> V_55 = F_18 ( V_59 -> V_61 ) ;
V_16 -> V_62 = F_18 ( V_59 -> V_63 ) ;
V_16 -> V_64 = F_18 ( V_59 -> V_65 ) ;
V_16 -> V_66 = F_19 ( V_59 -> V_67 ) ;
V_16 -> V_68 = F_19 ( V_59 -> V_69 ) ;
V_16 -> V_70 = F_19 ( V_59 -> V_71 ) ;
F_15 ( V_16 , V_24 ) ;
}
static void
F_20 ( struct V_15 * V_16 , T_2 * V_59 ,
struct V_23 * V_24 )
{
int V_72 = F_21 ( V_24 ) -> V_73 -> V_74 -> V_75 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_66 = F_22 ( V_59 -> V_76 ,
V_59 -> V_67 , V_72 ) ;
V_16 -> V_68 = F_22 ( V_59 -> V_77 ,
V_59 -> V_71 , V_72 ) ;
V_16 -> V_70 = F_22 ( V_59 -> V_77 ,
V_59 -> V_71 , V_72 ) ;
V_16 -> V_38 = F_23 ( V_59 -> V_78 ) ;
V_16 -> V_62 = F_17 ( V_59 -> V_63 ) ;
V_16 -> V_55 = F_17 ( V_59 -> V_79 ) ;
F_15 ( V_16 , V_24 ) ;
}
static int
F_24 ( const unsigned int V_80 , struct V_1 * V_1 )
{
T_3 V_81 ;
int V_82 = 0 ;
char * V_83 = NULL ;
struct V_3 * V_84 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_85 . V_11 -> V_86 ) ;
struct V_87 * V_88 = NULL ;
struct V_89 * V_90 ;
struct V_91 * V_74 ;
if ( V_1 -> V_5 == NULL ) {
V_88 = F_25 ( V_24 ) ;
if ( F_7 ( V_88 ) )
return F_26 ( V_88 ) ;
V_84 = F_27 ( sizeof( struct V_3 ) , V_92 ) ;
if ( V_84 == NULL ) {
V_82 = - V_93 ;
goto V_94;
}
V_1 -> V_5 = V_84 ;
V_84 -> V_88 = F_28 ( V_88 ) ;
V_90 = F_29 ( V_88 ) ;
} else {
V_84 = V_1 -> V_5 ;
V_90 = F_29 ( V_84 -> V_88 ) ;
}
V_74 = V_90 -> V_73 -> V_74 ;
if ( ! V_74 -> V_95 -> V_96 ) {
V_82 = - V_97 ;
goto V_94;
}
V_84 -> V_7 = true ;
V_84 -> V_8 . V_9 = false ;
V_83 = F_30 ( V_1 -> V_85 . V_11 ) ;
if ( V_83 == NULL ) {
V_82 = - V_93 ;
goto V_94;
}
F_2 ( V_6 , L_6 , V_83 , V_1 -> V_98 ) ;
V_99:
if ( V_90 -> V_100 )
V_84 -> V_8 . V_101 = V_102 ;
else if ( ( V_90 -> V_73 -> V_103 &
V_90 -> V_73 -> V_74 -> V_104 -> V_105 ) == 0 ) {
V_84 -> V_8 . V_101 = V_106 ;
} else if ( V_24 -> V_27 & V_28 ) {
V_84 -> V_8 . V_101 = V_107 ;
} else {
V_84 -> V_8 . V_101 = V_108 ;
}
V_81 = V_109 | V_110 ;
if ( F_31 ( V_24 ) )
V_81 |= V_111 ;
V_82 = V_74 -> V_95 -> V_96 ( V_80 , V_90 , V_83 , V_24 ,
& V_84 -> V_112 , V_81 ,
& V_84 -> V_8 ) ;
if ( V_82 == 0 )
V_84 -> V_7 = false ;
else if ( ( V_82 == - V_113 ) &&
( V_24 -> V_27 & V_28 ) ) {
V_24 -> V_27 &= ~ V_28 ;
goto V_99;
}
V_94:
F_32 ( V_83 ) ;
F_33 ( V_88 ) ;
return V_82 ;
}
static int F_34 ( const char * V_114 )
{
int V_115 ;
const T_4 * V_116 = ( const T_4 * ) V_114 ;
for ( V_115 = 0 ; V_115 <= V_117 ; V_115 ++ ) {
if ( V_116 [ V_115 ] == 0 )
return V_115 << 1 ;
}
F_2 ( V_6 , L_7 ) ;
return V_115 << 1 ;
}
static char * F_35 ( char * V_118 , char * V_119 , int V_120 )
{
char * V_121 ;
T_1 * V_122 = ( T_1 * ) V_118 ;
if ( V_120 == V_106 ) {
T_2 * V_123 ;
V_123 = ( T_2 * ) V_122 ;
V_121 = V_118 + sizeof( T_2 ) +
V_123 -> V_124 ;
} else
V_121 = V_118 + F_17 ( V_122 -> V_125 ) ;
F_2 ( V_6 , L_8 , V_121 , V_118 ) ;
if ( V_121 >= V_119 ) {
F_2 ( V_126 , L_9 ,
V_121 , V_119 , V_118 ) ;
return NULL ;
} else if ( ( ( V_120 == V_106 ) &&
( V_121 + sizeof( T_2 ) > V_119 ) )
|| ( ( V_120 != V_106 ) &&
( V_121 + sizeof( T_1 ) > V_119 ) ) ) {
F_2 ( V_126 , L_10 ,
V_121 , V_119 ) ;
return NULL ;
} else
return V_121 ;
}
static void F_36 ( struct V_127 * V_128 ,
const T_5 * V_59 , bool V_129 )
{
V_128 -> V_14 = & V_59 -> V_130 [ 0 ] ;
if ( V_129 )
V_128 -> V_131 = F_34 ( V_128 -> V_14 ) ;
else
V_128 -> V_131 = F_37 ( V_128 -> V_14 , V_117 ) ;
V_128 -> V_132 = V_59 -> V_133 ;
V_128 -> V_134 = F_18 ( V_59 -> V_135 . V_136 ) ;
}
static void F_38 ( struct V_127 * V_128 ,
const T_1 * V_59 )
{
V_128 -> V_14 = & V_59 -> V_130 [ 0 ] ;
V_128 -> V_131 = F_17 ( V_59 -> V_124 ) ;
V_128 -> V_132 = V_59 -> V_137 ;
}
static void F_39 ( struct V_127 * V_128 ,
const T_6 * V_59 )
{
V_128 -> V_14 = & V_59 -> V_130 [ 0 ] ;
V_128 -> V_131 = F_17 ( V_59 -> V_124 ) ;
V_128 -> V_132 = V_59 -> V_137 ;
}
static void F_40 ( struct V_127 * V_128 ,
const T_7 * V_59 )
{
V_128 -> V_14 = & V_59 -> V_130 [ 0 ] ;
V_128 -> V_131 = F_17 ( V_59 -> V_124 ) ;
V_128 -> V_132 = V_59 -> V_137 ;
V_128 -> V_134 = F_18 ( V_59 -> V_136 ) ;
}
static void F_41 ( struct V_127 * V_128 ,
const T_8 * V_59 )
{
V_128 -> V_14 = & V_59 -> V_130 [ 0 ] ;
V_128 -> V_131 = F_17 ( V_59 -> V_124 ) ;
V_128 -> V_132 = V_59 -> V_137 ;
}
static void F_42 ( struct V_127 * V_128 ,
const T_2 * V_59 )
{
V_128 -> V_14 = & V_59 -> V_130 [ 0 ] ;
V_128 -> V_131 = V_59 -> V_124 ;
V_128 -> V_132 = V_59 -> V_133 ;
}
static int F_43 ( struct V_127 * V_128 , const void * V_59 ,
T_9 V_120 , bool V_129 )
{
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
switch ( V_120 ) {
case V_102 :
F_36 ( V_128 , V_59 , V_129 ) ;
break;
case V_108 :
F_38 ( V_128 , V_59 ) ;
break;
case V_138 :
F_39 ( V_128 , V_59 ) ;
break;
case V_107 :
F_40 ( V_128 , V_59 ) ;
break;
case V_139 :
F_41 ( V_128 , V_59 ) ;
break;
case V_106 :
F_42 ( V_128 , V_59 ) ;
break;
default:
F_2 ( V_6 , L_11 , V_120 ) ;
return - V_140 ;
}
return 0 ;
}
static int F_44 ( struct V_127 * V_128 , bool V_129 )
{
int V_82 = 0 ;
if ( ! V_128 -> V_14 )
return 0 ;
if ( V_129 ) {
T_4 * V_141 = ( T_4 * ) V_128 -> V_14 ;
if ( V_128 -> V_131 == 2 ) {
if ( V_141 [ 0 ] == V_142 )
V_82 = 1 ;
} else if ( V_128 -> V_131 == 4 ) {
if ( V_141 [ 0 ] == V_142 &&
V_141 [ 1 ] == V_142 )
V_82 = 2 ;
}
} else {
if ( V_128 -> V_131 == 1 ) {
if ( V_128 -> V_14 [ 0 ] == '.' )
V_82 = 1 ;
} else if ( V_128 -> V_131 == 2 ) {
if ( V_128 -> V_14 [ 0 ] == '.' && V_128 -> V_14 [ 1 ] == '.' )
V_82 = 2 ;
}
}
return V_82 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = F_46 ( V_1 ) ;
struct V_143 * V_144 = F_8 ( V_18 ) ;
if ( V_144 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_47 ( const char * V_145 ,
struct V_3 * V_146 )
{
struct V_127 V_128 ;
int V_82 ;
V_82 = F_43 ( & V_128 , V_145 , V_146 -> V_8 . V_101 ,
V_146 -> V_8 . V_147 ) ;
if ( ! V_82 ) {
V_146 -> V_8 . V_148 = V_128 . V_14 ;
V_146 -> V_8 . V_149 = V_128 . V_131 ;
V_146 -> V_8 . V_132 = V_128 . V_132 ;
}
return V_82 ;
}
static int
F_48 ( const unsigned int V_80 , struct V_89 * V_90 , T_10 V_150 ,
struct V_1 * V_1 , char * * V_145 , int * V_151 )
{
T_3 V_81 ;
int V_82 = 0 ;
int V_152 = 0 ;
T_10 V_153 ;
T_10 V_154 = V_150 ;
struct V_3 * V_155 = V_1 -> V_5 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_85 . V_11 -> V_86 ) ;
struct V_91 * V_74 = V_90 -> V_73 -> V_74 ;
if ( ! V_74 -> V_95 -> V_96 || ! V_74 -> V_95 -> V_156 )
return - V_97 ;
if ( ( V_155 == NULL ) || ( V_145 == NULL ) || ( V_151 == NULL ) )
return - V_157 ;
* V_145 = NULL ;
V_153 = V_155 -> V_8 . V_158 -
V_155 -> V_8 . V_159 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_154 < V_155 -> V_8 . V_158 ) &&
F_45 ( V_1 ) ) || ( V_154 < V_153 ) ) {
F_2 ( V_6 , L_13 ) ;
F_49 ( & V_160 ) ;
if ( V_74 -> V_95 -> V_161 ( V_155 ) ) {
V_155 -> V_7 = true ;
F_50 ( & V_160 ) ;
if ( V_74 -> V_95 -> V_162 )
V_74 -> V_95 -> V_162 ( V_80 , V_90 , & V_155 -> V_112 ) ;
} else
F_50 ( & V_160 ) ;
if ( V_155 -> V_8 . V_163 ) {
F_2 ( V_6 , L_14 ) ;
if ( V_155 -> V_8 . V_164 )
F_51 ( V_155 -> V_8 .
V_163 ) ;
else
F_52 ( V_155 -> V_8 .
V_163 ) ;
V_155 -> V_8 . V_163 = NULL ;
}
V_82 = F_24 ( V_80 , V_1 ) ;
if ( V_82 ) {
F_2 ( V_6 , L_15 ,
V_82 ) ;
return V_82 ;
}
if ( V_155 -> V_8 . V_165 )
F_47 ( V_155 -> V_8 . V_165 , V_155 ) ;
}
V_81 = V_109 | V_110 ;
if ( F_31 ( V_24 ) )
V_81 |= V_111 ;
while ( ( V_154 >= V_155 -> V_8 . V_158 ) &&
( V_82 == 0 ) && ! V_155 -> V_8 . V_9 ) {
F_2 ( V_6 , L_16 ) ;
V_82 = V_74 -> V_95 -> V_156 ( V_80 , V_90 , & V_155 -> V_112 ,
V_81 ,
& V_155 -> V_8 ) ;
if ( V_155 -> V_8 . V_165 )
F_47 ( V_155 -> V_8 . V_165 , V_155 ) ;
if ( V_82 )
return - V_157 ;
}
if ( V_154 < V_155 -> V_8 . V_158 ) {
int V_166 ;
char * V_167 ;
char * V_119 = V_155 -> V_8 . V_163 +
V_74 -> V_95 -> V_168 (
V_155 -> V_8 . V_163 ) ;
V_167 = V_155 -> V_8 . V_169 ;
V_153 = V_155 -> V_8 . V_158
- V_155 -> V_8 . V_159 ;
V_152 = V_154 - V_153 ;
F_2 ( V_6 , L_17 , V_152 ) ;
for ( V_166 = 0 ; ( V_166 < ( V_152 ) ) && ( V_167 != NULL ) ; V_166 ++ ) {
V_167 = F_35 ( V_167 , V_119 ,
V_155 -> V_8 . V_101 ) ;
}
if ( ( V_167 == NULL ) && ( V_166 < V_152 ) ) {
F_2 ( V_126 , L_18 ,
V_152 , V_154 , V_82 ) ;
}
V_82 = 0 ;
* V_145 = V_167 ;
} else {
F_2 ( V_6 , L_19 ) ;
return 0 ;
}
if ( V_152 >= V_155 -> V_8 . V_159 ) {
F_2 ( V_6 , L_20 ) ;
* V_151 = 0 ;
} else
* V_151 = V_155 -> V_8 . V_159 - V_152 ;
return V_82 ;
}
static int F_53 ( char * V_170 , struct V_1 * V_1 ,
struct V_171 * V_172 ,
char * V_173 , unsigned int V_174 )
{
struct V_3 * V_146 = V_1 -> V_5 ;
struct V_19 * V_20 = V_1 -> V_85 . V_11 -> V_86 ;
struct V_23 * V_24 = F_4 ( V_20 ) ;
struct V_127 V_128 = { NULL , } ;
struct V_15 V_16 ;
struct V_13 V_14 ;
int V_82 = 0 ;
T_11 V_134 ;
V_82 = F_43 ( & V_128 , V_170 , V_146 -> V_8 . V_101 ,
V_146 -> V_8 . V_147 ) ;
if ( V_82 )
return V_82 ;
if ( V_128 . V_131 > V_174 ) {
F_2 ( V_126 , L_21 ,
V_128 . V_131 ) ;
return - V_140 ;
}
if ( F_44 ( & V_128 , V_146 -> V_8 . V_147 ) )
return 0 ;
if ( V_146 -> V_8 . V_147 ) {
struct V_175 * V_176 = V_24 -> V_177 ;
V_14 . V_14 = V_173 ;
V_14 . V_115 =
F_54 ( ( char * ) V_14 . V_14 , ( T_4 * ) V_128 . V_14 ,
V_178 ,
F_55 ( V_179 , V_128 . V_131 ,
( V_179 ) V_174 ) , V_176 ,
V_24 -> V_27 &
V_180 ) ;
V_14 . V_115 -= F_56 ( V_176 ) ;
} else {
V_14 . V_14 = V_128 . V_14 ;
V_14 . V_115 = V_128 . V_131 ;
}
switch ( V_146 -> V_8 . V_101 ) {
case V_102 :
F_57 ( & V_16 ,
& ( ( T_5 * ) V_170 ) -> V_135 ,
V_24 ) ;
break;
case V_106 :
F_20 ( & V_16 ,
( T_2 * ) V_170 ,
V_24 ) ;
break;
default:
F_16 ( & V_16 ,
( T_1 * ) V_170 ,
V_24 ) ;
break;
}
if ( V_128 . V_134 && ( V_24 -> V_27 & V_28 ) ) {
V_16 . V_29 = V_128 . V_134 ;
} else {
V_16 . V_29 = F_58 ( V_20 , V_181 ) ;
F_59 ( V_24 ) ;
}
if ( ( V_24 -> V_27 & V_182 ) &&
F_60 ( & V_16 ) )
V_16 . V_32 |= V_33 ;
F_3 ( V_1 -> V_183 , & V_14 , & V_16 ) ;
V_134 = F_61 ( V_16 . V_29 ) ;
return ! F_62 ( V_172 , V_14 . V_14 , V_14 . V_115 , V_134 , V_16 . V_43 ) ;
}
int F_63 ( struct V_1 * V_1 , struct V_171 * V_172 )
{
int V_82 = 0 ;
unsigned int V_80 ;
int V_166 ;
struct V_89 * V_90 ;
struct V_3 * V_84 = NULL ;
char * V_145 ;
int V_184 = 0 ;
char * V_185 = NULL ;
char * V_119 ;
unsigned int V_174 ;
V_80 = F_64 () ;
if ( V_1 -> V_5 == NULL ) {
V_82 = F_24 ( V_80 , V_1 ) ;
F_2 ( V_6 , L_22 , V_82 ) ;
if ( V_82 )
goto V_186;
}
if ( ! F_65 ( V_1 , V_172 ) )
goto V_186;
if ( V_1 -> V_5 == NULL ) {
V_82 = - V_140 ;
goto V_186;
}
V_84 = V_1 -> V_5 ;
if ( V_84 -> V_8 . V_9 ) {
if ( V_84 -> V_8 . V_10 ) {
F_2 ( V_6 , L_23 ) ;
V_82 = 0 ;
goto V_186;
}
}
V_90 = F_29 ( V_84 -> V_88 ) ;
V_82 = F_48 ( V_80 , V_90 , V_172 -> V_150 , V_1 , & V_145 ,
& V_184 ) ;
if ( V_82 ) {
F_2 ( V_6 , L_24 , V_82 ) ;
goto V_186;
} else if ( V_145 != NULL ) {
F_2 ( V_6 , L_25 , V_172 -> V_150 ) ;
} else {
F_2 ( V_6 , L_26 ) ;
goto V_186;
}
F_2 ( V_6 , L_27 ,
V_184 , V_84 -> V_8 . V_163 ) ;
V_174 = V_90 -> V_73 -> V_74 -> V_95 -> V_168 (
V_84 -> V_8 . V_163 ) ;
V_119 = V_84 -> V_8 . V_163 + V_174 ;
V_185 = F_66 ( V_178 , V_92 ) ;
if ( V_185 == NULL ) {
V_82 = - V_93 ;
goto V_186;
}
for ( V_166 = 0 ; V_166 < V_184 ; V_166 ++ ) {
if ( V_145 == NULL ) {
F_2 ( V_126 , L_28 ,
V_184 , V_166 ) ;
break;
}
V_82 = F_53 ( V_145 , V_1 , V_172 ,
V_185 , V_174 ) ;
if ( V_82 ) {
if ( V_82 > 0 )
V_82 = 0 ;
break;
}
V_172 -> V_150 ++ ;
if ( V_172 -> V_150 ==
V_84 -> V_8 . V_158 ) {
F_2 ( V_6 , L_29 ,
V_172 -> V_150 , V_185 ) ;
F_47 ( V_145 , V_84 ) ;
break;
} else
V_145 =
F_35 ( V_145 , V_119 ,
V_84 -> V_8 . V_101 ) ;
}
F_32 ( V_185 ) ;
V_186:
F_67 ( V_80 ) ;
return V_82 ;
}
