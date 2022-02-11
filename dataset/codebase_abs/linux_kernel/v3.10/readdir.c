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
V_16 -> V_32 = V_24 -> V_33 ;
V_16 -> V_34 = V_24 -> V_35 ;
if ( V_16 -> V_36 & V_37 ) {
V_16 -> V_38 = V_39 | V_24 -> V_40 ;
V_16 -> V_41 = V_42 ;
} else {
V_16 -> V_38 = V_43 | V_24 -> V_44 ;
V_16 -> V_41 = V_45 ;
}
if ( V_16 -> V_36 & V_46 )
V_16 -> V_38 &= ~ V_47 ;
if ( V_24 -> V_27 & V_48 )
V_16 -> V_49 |= V_50 ;
if ( V_24 -> V_27 & V_51 &&
V_16 -> V_36 & V_52 ) {
if ( V_16 -> V_53 == 0 ) {
V_16 -> V_38 &= ~ V_54 ;
V_16 -> V_38 |= V_55 ;
V_16 -> V_41 = V_56 ;
} else {
V_16 -> V_49 |= V_50 ;
}
}
}
void
F_16 ( struct V_15 * V_16 , T_1 * V_57 ,
struct V_23 * V_24 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_36 = F_17 ( V_57 -> V_58 ) ;
V_16 -> V_53 = F_18 ( V_57 -> V_59 ) ;
V_16 -> V_60 = F_18 ( V_57 -> V_61 ) ;
V_16 -> V_62 = F_18 ( V_57 -> V_63 ) ;
V_16 -> V_64 = F_19 ( V_57 -> V_65 ) ;
V_16 -> V_66 = F_19 ( V_57 -> V_67 ) ;
V_16 -> V_68 = F_19 ( V_57 -> V_69 ) ;
F_15 ( V_16 , V_24 ) ;
}
static void
F_20 ( struct V_15 * V_16 , T_2 * V_57 ,
struct V_23 * V_24 )
{
int V_70 = F_21 ( V_24 ) -> V_71 -> V_72 -> V_73 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_64 = F_22 ( V_57 -> V_74 ,
V_57 -> V_65 , V_70 ) ;
V_16 -> V_66 = F_22 ( V_57 -> V_75 ,
V_57 -> V_69 , V_70 ) ;
V_16 -> V_68 = F_22 ( V_57 -> V_75 ,
V_57 -> V_69 , V_70 ) ;
V_16 -> V_36 = F_23 ( V_57 -> V_76 ) ;
V_16 -> V_60 = F_17 ( V_57 -> V_61 ) ;
V_16 -> V_53 = F_17 ( V_57 -> V_77 ) ;
F_15 ( V_16 , V_24 ) ;
}
static int
F_24 ( const unsigned int V_78 , struct V_1 * V_1 )
{
T_3 V_79 ;
int V_80 = 0 ;
char * V_81 = NULL ;
struct V_3 * V_82 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_83 . V_11 -> V_84 ) ;
struct V_85 * V_86 = NULL ;
struct V_87 * V_88 ;
struct V_89 * V_72 ;
if ( V_1 -> V_5 == NULL ) {
V_86 = F_25 ( V_24 ) ;
if ( F_7 ( V_86 ) )
return F_26 ( V_86 ) ;
V_82 = F_27 ( sizeof( struct V_3 ) , V_90 ) ;
if ( V_82 == NULL ) {
V_80 = - V_91 ;
goto V_92;
}
V_1 -> V_5 = V_82 ;
V_82 -> V_86 = F_28 ( V_86 ) ;
V_88 = F_29 ( V_86 ) ;
} else {
V_82 = V_1 -> V_5 ;
V_88 = F_29 ( V_82 -> V_86 ) ;
}
V_72 = V_88 -> V_71 -> V_72 ;
if ( ! V_72 -> V_93 -> V_94 ) {
V_80 = - V_95 ;
goto V_92;
}
V_82 -> V_7 = true ;
V_82 -> V_8 . V_9 = false ;
V_81 = F_30 ( V_1 -> V_83 . V_11 ) ;
if ( V_81 == NULL ) {
V_80 = - V_91 ;
goto V_92;
}
F_2 ( V_6 , L_6 , V_81 , V_1 -> V_96 ) ;
V_97:
if ( V_88 -> V_98 )
V_82 -> V_8 . V_99 = V_100 ;
else if ( ( V_88 -> V_71 -> V_101 &
V_88 -> V_71 -> V_72 -> V_102 -> V_103 ) == 0 ) {
V_82 -> V_8 . V_99 = V_104 ;
} else if ( V_24 -> V_27 & V_28 ) {
V_82 -> V_8 . V_99 = V_105 ;
} else {
V_82 -> V_8 . V_99 = V_106 ;
}
V_79 = V_107 | V_108 ;
if ( F_31 ( V_24 ) )
V_79 |= V_109 ;
V_80 = V_72 -> V_93 -> V_94 ( V_78 , V_88 , V_81 , V_24 ,
& V_82 -> V_110 , V_79 ,
& V_82 -> V_8 ) ;
if ( V_80 == 0 )
V_82 -> V_7 = false ;
else if ( ( V_80 == - V_111 ) &&
( V_24 -> V_27 & V_28 ) ) {
V_24 -> V_27 &= ~ V_28 ;
goto V_97;
}
V_92:
F_32 ( V_81 ) ;
F_33 ( V_86 ) ;
return V_80 ;
}
static int F_34 ( const char * V_112 )
{
int V_113 ;
const T_4 * V_114 = ( const T_4 * ) V_112 ;
for ( V_113 = 0 ; V_113 <= V_115 ; V_113 ++ ) {
if ( V_114 [ V_113 ] == 0 )
return V_113 << 1 ;
}
F_2 ( V_6 , L_7 ) ;
return V_113 << 1 ;
}
static char * F_35 ( char * V_116 , char * V_117 , int V_118 )
{
char * V_119 ;
T_1 * V_120 = ( T_1 * ) V_116 ;
if ( V_118 == V_104 ) {
T_2 * V_121 ;
V_121 = ( T_2 * ) V_120 ;
V_119 = V_116 + sizeof( T_2 ) +
V_121 -> V_122 ;
} else
V_119 = V_116 + F_17 ( V_120 -> V_123 ) ;
F_2 ( V_6 , L_8 , V_119 , V_116 ) ;
if ( V_119 >= V_117 ) {
F_2 ( V_124 , L_9 ,
V_119 , V_117 , V_116 ) ;
return NULL ;
} else if ( ( ( V_118 == V_104 ) &&
( V_119 + sizeof( T_2 ) > V_117 ) )
|| ( ( V_118 != V_104 ) &&
( V_119 + sizeof( T_1 ) > V_117 ) ) ) {
F_2 ( V_124 , L_10 ,
V_119 , V_117 ) ;
return NULL ;
} else
return V_119 ;
}
static void F_36 ( struct V_125 * V_126 ,
const T_5 * V_57 , bool V_127 )
{
V_126 -> V_14 = & V_57 -> V_128 [ 0 ] ;
if ( V_127 )
V_126 -> V_129 = F_34 ( V_126 -> V_14 ) ;
else
V_126 -> V_129 = F_37 ( V_126 -> V_14 , V_115 ) ;
V_126 -> V_130 = V_57 -> V_131 ;
V_126 -> V_132 = F_18 ( V_57 -> V_133 . V_134 ) ;
}
static void F_38 ( struct V_125 * V_126 ,
const T_1 * V_57 )
{
V_126 -> V_14 = & V_57 -> V_128 [ 0 ] ;
V_126 -> V_129 = F_17 ( V_57 -> V_122 ) ;
V_126 -> V_130 = V_57 -> V_135 ;
}
static void F_39 ( struct V_125 * V_126 ,
const T_6 * V_57 )
{
V_126 -> V_14 = & V_57 -> V_128 [ 0 ] ;
V_126 -> V_129 = F_17 ( V_57 -> V_122 ) ;
V_126 -> V_130 = V_57 -> V_135 ;
}
static void F_40 ( struct V_125 * V_126 ,
const T_7 * V_57 )
{
V_126 -> V_14 = & V_57 -> V_128 [ 0 ] ;
V_126 -> V_129 = F_17 ( V_57 -> V_122 ) ;
V_126 -> V_130 = V_57 -> V_135 ;
V_126 -> V_132 = F_18 ( V_57 -> V_134 ) ;
}
static void F_41 ( struct V_125 * V_126 ,
const T_8 * V_57 )
{
V_126 -> V_14 = & V_57 -> V_128 [ 0 ] ;
V_126 -> V_129 = F_17 ( V_57 -> V_122 ) ;
V_126 -> V_130 = V_57 -> V_135 ;
}
static void F_42 ( struct V_125 * V_126 ,
const T_2 * V_57 )
{
V_126 -> V_14 = & V_57 -> V_128 [ 0 ] ;
V_126 -> V_129 = V_57 -> V_122 ;
V_126 -> V_130 = V_57 -> V_131 ;
}
static int F_43 ( struct V_125 * V_126 , const void * V_57 ,
T_9 V_118 , bool V_127 )
{
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
switch ( V_118 ) {
case V_100 :
F_36 ( V_126 , V_57 , V_127 ) ;
break;
case V_106 :
F_38 ( V_126 , V_57 ) ;
break;
case V_136 :
F_39 ( V_126 , V_57 ) ;
break;
case V_105 :
F_40 ( V_126 , V_57 ) ;
break;
case V_137 :
F_41 ( V_126 , V_57 ) ;
break;
case V_104 :
F_42 ( V_126 , V_57 ) ;
break;
default:
F_2 ( V_6 , L_11 , V_118 ) ;
return - V_138 ;
}
return 0 ;
}
static int F_44 ( struct V_125 * V_126 , bool V_127 )
{
int V_80 = 0 ;
if ( ! V_126 -> V_14 )
return 0 ;
if ( V_127 ) {
T_4 * V_139 = ( T_4 * ) V_126 -> V_14 ;
if ( V_126 -> V_129 == 2 ) {
if ( V_139 [ 0 ] == V_140 )
V_80 = 1 ;
} else if ( V_126 -> V_129 == 4 ) {
if ( V_139 [ 0 ] == V_140 &&
V_139 [ 1 ] == V_140 )
V_80 = 2 ;
}
} else {
if ( V_126 -> V_129 == 1 ) {
if ( V_126 -> V_14 [ 0 ] == '.' )
V_80 = 1 ;
} else if ( V_126 -> V_129 == 2 ) {
if ( V_126 -> V_14 [ 0 ] == '.' && V_126 -> V_14 [ 1 ] == '.' )
V_80 = 2 ;
}
}
return V_80 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = F_46 ( V_1 ) ;
struct V_141 * V_142 = F_8 ( V_18 ) ;
if ( V_142 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_47 ( const char * V_143 ,
struct V_3 * V_144 )
{
struct V_125 V_126 ;
int V_80 ;
V_80 = F_43 ( & V_126 , V_143 , V_144 -> V_8 . V_99 ,
V_144 -> V_8 . V_145 ) ;
if ( ! V_80 ) {
V_144 -> V_8 . V_146 = V_126 . V_14 ;
V_144 -> V_8 . V_147 = V_126 . V_129 ;
V_144 -> V_8 . V_130 = V_126 . V_130 ;
}
return V_80 ;
}
static int
F_48 ( const unsigned int V_78 , struct V_87 * V_88 ,
struct V_1 * V_1 , char * * V_143 , int * V_148 )
{
T_3 V_79 ;
int V_80 = 0 ;
int V_149 = 0 ;
T_10 V_150 ;
T_10 V_151 = V_1 -> V_96 ;
struct V_3 * V_152 = V_1 -> V_5 ;
struct V_23 * V_24 = F_4 ( V_1 -> V_83 . V_11 -> V_84 ) ;
struct V_89 * V_72 = V_88 -> V_71 -> V_72 ;
if ( ! V_72 -> V_93 -> V_94 || ! V_72 -> V_93 -> V_153 )
return - V_95 ;
if ( ( V_152 == NULL ) || ( V_143 == NULL ) || ( V_148 == NULL ) )
return - V_154 ;
* V_143 = NULL ;
V_150 = V_152 -> V_8 . V_155 -
V_152 -> V_8 . V_156 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_151 < V_152 -> V_8 . V_155 ) &&
F_45 ( V_1 ) ) || ( V_151 < V_150 ) ) {
F_2 ( V_6 , L_13 ) ;
F_49 ( & V_157 ) ;
if ( ! V_152 -> V_8 . V_9 && ! V_152 -> V_7 ) {
V_152 -> V_7 = true ;
F_50 ( & V_157 ) ;
if ( V_72 -> V_93 -> V_158 )
V_72 -> V_93 -> V_158 ( V_78 , V_88 , & V_152 -> V_110 ) ;
} else
F_50 ( & V_157 ) ;
if ( V_152 -> V_8 . V_159 ) {
F_2 ( V_6 , L_14 ) ;
if ( V_152 -> V_8 . V_160 )
F_51 ( V_152 -> V_8 .
V_159 ) ;
else
F_52 ( V_152 -> V_8 .
V_159 ) ;
V_152 -> V_8 . V_159 = NULL ;
}
V_80 = F_24 ( V_78 , V_1 ) ;
if ( V_80 ) {
F_2 ( V_6 , L_15 ,
V_80 ) ;
return V_80 ;
}
if ( V_152 -> V_8 . V_161 )
F_47 ( V_152 -> V_8 . V_161 , V_152 ) ;
}
V_79 = V_107 | V_108 ;
if ( F_31 ( V_24 ) )
V_79 |= V_109 ;
while ( ( V_151 >= V_152 -> V_8 . V_155 ) &&
( V_80 == 0 ) && ! V_152 -> V_8 . V_9 ) {
F_2 ( V_6 , L_16 ) ;
V_80 = V_72 -> V_93 -> V_153 ( V_78 , V_88 , & V_152 -> V_110 ,
V_79 ,
& V_152 -> V_8 ) ;
if ( V_152 -> V_8 . V_161 )
F_47 ( V_152 -> V_8 . V_161 , V_152 ) ;
if ( V_80 )
return - V_154 ;
}
if ( V_151 < V_152 -> V_8 . V_155 ) {
int V_162 ;
char * V_163 ;
char * V_117 = V_152 -> V_8 . V_159 +
V_72 -> V_93 -> V_164 (
V_152 -> V_8 . V_159 ) ;
V_163 = V_152 -> V_8 . V_165 ;
V_150 = V_152 -> V_8 . V_155
- V_152 -> V_8 . V_156 ;
V_149 = V_151 - V_150 ;
F_2 ( V_6 , L_17 , V_149 ) ;
for ( V_162 = 0 ; ( V_162 < ( V_149 ) ) && ( V_163 != NULL ) ; V_162 ++ ) {
V_163 = F_35 ( V_163 , V_117 ,
V_152 -> V_8 . V_99 ) ;
}
if ( ( V_163 == NULL ) && ( V_162 < V_149 ) ) {
F_2 ( V_124 , L_18 ,
V_149 , V_151 , V_80 ) ;
}
V_80 = 0 ;
* V_143 = V_163 ;
} else {
F_2 ( V_6 , L_19 ) ;
return 0 ;
}
if ( V_149 >= V_152 -> V_8 . V_156 ) {
F_2 ( V_6 , L_20 ) ;
* V_148 = 0 ;
} else
* V_148 = V_152 -> V_8 . V_156 - V_149 ;
return V_80 ;
}
static int F_53 ( char * V_166 , struct V_1 * V_1 , T_11 V_167 ,
void * V_168 , char * V_169 , unsigned int V_170 )
{
struct V_3 * V_144 = V_1 -> V_5 ;
struct V_19 * V_20 = V_1 -> V_83 . V_11 -> V_84 ;
struct V_23 * V_24 = F_4 ( V_20 ) ;
struct V_125 V_126 = { NULL , } ;
struct V_15 V_16 ;
struct V_13 V_14 ;
int V_80 = 0 ;
T_12 V_132 ;
V_80 = F_43 ( & V_126 , V_166 , V_144 -> V_8 . V_99 ,
V_144 -> V_8 . V_145 ) ;
if ( V_80 )
return V_80 ;
if ( V_126 . V_129 > V_170 ) {
F_2 ( V_124 , L_21 ,
V_126 . V_129 ) ;
return - V_138 ;
}
if ( F_44 ( & V_126 , V_144 -> V_8 . V_145 ) )
return 0 ;
if ( V_144 -> V_8 . V_145 ) {
struct V_171 * V_172 = V_24 -> V_173 ;
V_14 . V_14 = V_169 ;
V_14 . V_113 =
F_54 ( ( char * ) V_14 . V_14 , ( T_4 * ) V_126 . V_14 ,
V_174 ,
F_55 ( V_175 , V_126 . V_129 ,
( V_175 ) V_170 ) , V_172 ,
V_24 -> V_27 &
V_176 ) ;
V_14 . V_113 -= F_56 ( V_172 ) ;
} else {
V_14 . V_14 = V_126 . V_14 ;
V_14 . V_113 = V_126 . V_129 ;
}
switch ( V_144 -> V_8 . V_99 ) {
case V_100 :
F_57 ( & V_16 ,
& ( ( T_5 * ) V_166 ) -> V_133 ,
V_24 ) ;
break;
case V_104 :
F_20 ( & V_16 ,
( T_2 * ) V_166 ,
V_24 ) ;
break;
default:
F_16 ( & V_16 ,
( T_1 * ) V_166 ,
V_24 ) ;
break;
}
if ( V_126 . V_132 && ( V_24 -> V_27 & V_28 ) ) {
V_16 . V_29 = V_126 . V_132 ;
} else {
V_16 . V_29 = F_58 ( V_20 , V_177 ) ;
F_59 ( V_24 ) ;
}
if ( ( V_24 -> V_27 & V_178 ) &&
F_60 ( & V_16 ) )
V_16 . V_49 |= V_50 ;
F_3 ( V_1 -> V_179 , & V_14 , & V_16 ) ;
V_132 = F_61 ( V_16 . V_29 ) ;
V_80 = V_167 ( V_168 , V_14 . V_14 , V_14 . V_113 , V_1 -> V_96 , V_132 ,
V_16 . V_41 ) ;
return V_80 ;
}
int F_62 ( struct V_1 * V_1 , void * V_180 , T_11 V_167 )
{
int V_80 = 0 ;
unsigned int V_78 ;
int V_162 ;
struct V_87 * V_88 ;
struct V_3 * V_82 = NULL ;
char * V_143 ;
int V_181 = 0 ;
char * V_182 = NULL ;
char * V_117 ;
unsigned int V_170 ;
V_78 = F_63 () ;
if ( V_1 -> V_5 == NULL ) {
V_80 = F_24 ( V_78 , V_1 ) ;
F_2 ( V_6 , L_22 , V_80 ) ;
if ( V_80 )
goto V_183;
}
switch ( ( int ) V_1 -> V_96 ) {
case 0 :
if ( V_167 ( V_180 , L_23 , 1 , V_1 -> V_96 ,
F_46 ( V_1 ) -> V_184 , V_42 ) < 0 ) {
F_2 ( V_124 , L_24 ) ;
V_80 = - V_91 ;
break;
}
V_1 -> V_96 ++ ;
case 1 :
if ( V_167 ( V_180 , L_25 , 2 , V_1 -> V_96 ,
F_64 ( V_1 -> V_83 . V_11 ) , V_42 ) < 0 ) {
F_2 ( V_124 , L_26 ) ;
V_80 = - V_91 ;
break;
}
V_1 -> V_96 ++ ;
default:
if ( V_1 -> V_5 == NULL ) {
V_80 = - V_138 ;
F_65 ( V_78 ) ;
return V_80 ;
}
V_82 = V_1 -> V_5 ;
if ( V_82 -> V_8 . V_9 ) {
if ( V_82 -> V_8 . V_10 ) {
F_2 ( V_6 , L_27 ) ;
V_80 = 0 ;
break;
}
}
V_88 = F_29 ( V_82 -> V_86 ) ;
V_80 = F_48 ( V_78 , V_88 , V_1 , & V_143 ,
& V_181 ) ;
if ( V_80 ) {
F_2 ( V_6 , L_28 , V_80 ) ;
goto V_183;
} else if ( V_143 != NULL ) {
F_2 ( V_6 , L_29 , V_1 -> V_96 ) ;
} else {
F_2 ( V_6 , L_30 ) ;
goto V_183;
}
F_2 ( V_6 , L_31 ,
V_181 , V_82 -> V_8 . V_159 ) ;
V_170 = V_88 -> V_71 -> V_72 -> V_93 -> V_164 (
V_82 -> V_8 . V_159 ) ;
V_117 = V_82 -> V_8 . V_159 + V_170 ;
V_182 = F_66 ( V_174 , V_90 ) ;
if ( V_182 == NULL ) {
V_80 = - V_91 ;
break;
}
for ( V_162 = 0 ; ( V_162 < V_181 ) && ( V_80 == 0 ) ; V_162 ++ ) {
if ( V_143 == NULL ) {
F_2 ( V_124 , L_32 ,
V_181 , V_162 ) ;
break;
}
V_80 = F_53 ( V_143 , V_1 , V_167 ,
V_180 , V_182 , V_170 ) ;
if ( V_80 == - V_185 ) {
V_80 = 0 ;
break;
}
V_1 -> V_96 ++ ;
if ( V_1 -> V_96 ==
V_82 -> V_8 . V_155 ) {
F_2 ( V_6 , L_33 ,
V_1 -> V_96 , V_182 ) ;
F_47 ( V_143 , V_82 ) ;
break;
} else
V_143 =
F_35 ( V_143 , V_117 ,
V_82 -> V_8 . V_99 ) ;
}
F_32 ( V_182 ) ;
break;
}
V_183:
F_65 ( V_78 ) ;
return V_80 ;
}
