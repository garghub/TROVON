static void F_1 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 ;
if ( V_1 ) {
V_4 = V_1 -> V_5 ;
if ( V_4 == NULL ) {
F_2 ( 1 , L_1 ) ;
return;
}
if ( V_4 -> V_6 )
F_2 ( 1 , L_2 ) ;
if ( V_4 -> V_7 . V_8 )
F_2 ( 1 , L_3 ) ;
if ( V_4 -> V_7 . V_9 )
F_2 ( 1 , L_4 ) ;
}
}
static inline void F_1 ( struct V_1 * V_1 , char * V_2 )
{
}
static void
F_3 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_10 * V_10 , * V_16 ;
struct V_17 * V_17 ;
struct V_18 * V_19 = V_11 -> V_20 -> V_21 ;
struct V_22 * V_23 = F_4 ( V_19 ) ;
F_2 ( 1 , L_5 , V_24 , V_13 -> V_13 ) ;
if ( V_11 -> V_25 && V_11 -> V_25 -> V_26 )
V_11 -> V_25 -> V_26 ( V_11 , V_11 -> V_20 , V_13 ) ;
else
V_13 -> V_27 = F_5 ( V_13 -> V_13 , V_13 -> V_28 ) ;
V_10 = F_6 ( V_11 , V_13 ) ;
if ( V_10 ) {
int V_29 ;
V_17 = V_10 -> V_20 ;
if ( V_17 ) {
if ( ! ( V_23 -> V_30 & V_31 ) )
V_15 -> V_32 = F_7 ( V_17 ) -> V_33 ;
if ( F_7 ( V_17 ) -> V_33 == V_15 -> V_32 ) {
F_8 ( V_17 , V_15 ) ;
goto V_34;
}
}
V_29 = F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
if ( V_29 )
return;
}
V_10 = F_11 ( V_11 , V_13 ) ;
if ( ! V_10 )
return;
V_17 = F_12 ( V_19 , V_15 ) ;
if ( ! V_17 )
goto V_34;
V_16 = F_13 ( V_10 , V_17 ) ;
if ( V_16 && ! F_14 ( V_16 ) )
F_10 ( V_16 ) ;
V_34:
F_10 ( V_10 ) ;
}
static void
F_15 ( struct V_14 * V_15 , struct V_22 * V_23 )
{
V_15 -> V_35 = V_23 -> V_36 ;
V_15 -> V_37 = V_23 -> V_38 ;
if ( V_15 -> V_39 & V_40 ) {
V_15 -> V_41 = V_42 | V_23 -> V_43 ;
V_15 -> V_44 = V_45 ;
} else {
V_15 -> V_41 = V_46 | V_23 -> V_47 ;
V_15 -> V_44 = V_48 ;
}
if ( V_15 -> V_39 & V_49 )
V_15 -> V_41 &= ~ V_50 ;
if ( V_23 -> V_30 & V_51 )
V_15 -> V_52 |= V_53 ;
if ( V_23 -> V_30 & V_54 &&
V_15 -> V_39 & V_55 ) {
if ( V_15 -> V_56 == 0 ) {
V_15 -> V_41 &= ~ V_57 ;
V_15 -> V_41 |= V_58 ;
V_15 -> V_44 = V_59 ;
} else {
V_15 -> V_52 |= V_53 ;
}
}
}
void
F_16 ( struct V_14 * V_15 , T_1 * V_60 ,
struct V_22 * V_23 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_39 = F_17 ( V_60 -> V_61 ) ;
V_15 -> V_56 = F_18 ( V_60 -> V_62 ) ;
V_15 -> V_63 = F_18 ( V_60 -> V_64 ) ;
V_15 -> V_65 = F_18 ( V_60 -> V_66 ) ;
V_15 -> V_67 = F_19 ( V_60 -> V_68 ) ;
V_15 -> V_69 = F_19 ( V_60 -> V_70 ) ;
V_15 -> V_71 = F_19 ( V_60 -> V_72 ) ;
F_15 ( V_15 , V_23 ) ;
}
static void
F_20 ( struct V_14 * V_15 , T_2 * V_60 ,
struct V_22 * V_23 )
{
int V_73 = F_21 ( V_23 ) -> V_74 -> V_75 -> V_76 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_67 = F_22 ( V_60 -> V_77 ,
V_60 -> V_68 , V_73 ) ;
V_15 -> V_69 = F_22 ( V_60 -> V_78 ,
V_60 -> V_72 , V_73 ) ;
V_15 -> V_71 = F_22 ( V_60 -> V_78 ,
V_60 -> V_72 , V_73 ) ;
V_15 -> V_39 = F_23 ( V_60 -> V_79 ) ;
V_15 -> V_63 = F_17 ( V_60 -> V_64 ) ;
V_15 -> V_56 = F_17 ( V_60 -> V_80 ) ;
F_15 ( V_15 , V_23 ) ;
}
static int
F_24 ( const unsigned int V_81 , struct V_1 * V_1 )
{
T_3 V_82 ;
int V_83 = 0 ;
char * V_84 = NULL ;
struct V_3 * V_85 ;
struct V_22 * V_23 = F_4 ( V_1 -> V_86 . V_10 -> V_87 ) ;
struct V_88 * V_89 = NULL ;
struct V_90 * V_91 ;
struct V_92 * V_75 ;
if ( V_1 -> V_5 == NULL ) {
V_89 = F_25 ( V_23 ) ;
if ( F_14 ( V_89 ) )
return F_26 ( V_89 ) ;
V_85 = F_27 ( sizeof( struct V_3 ) , V_93 ) ;
if ( V_85 == NULL ) {
V_83 = - V_94 ;
goto V_95;
}
V_1 -> V_5 = V_85 ;
V_85 -> V_89 = F_28 ( V_89 ) ;
V_91 = F_29 ( V_89 ) ;
} else {
V_85 = V_1 -> V_5 ;
V_91 = F_29 ( V_85 -> V_89 ) ;
}
V_75 = V_91 -> V_74 -> V_75 ;
if ( ! V_75 -> V_96 -> V_97 ) {
V_83 = - V_98 ;
goto V_95;
}
V_85 -> V_6 = true ;
V_85 -> V_7 . V_8 = false ;
V_84 = F_30 ( V_1 -> V_86 . V_10 ) ;
if ( V_84 == NULL ) {
V_83 = - V_94 ;
goto V_95;
}
F_2 ( 1 , L_6 , V_84 , V_1 -> V_99 ) ;
V_100:
if ( V_91 -> V_101 )
V_85 -> V_7 . V_102 = V_103 ;
else if ( ( V_91 -> V_74 -> V_104 &
V_91 -> V_74 -> V_75 -> V_105 -> V_106 ) == 0 ) {
V_85 -> V_7 . V_102 = V_107 ;
} else if ( V_23 -> V_30 & V_31 ) {
V_85 -> V_7 . V_102 = V_108 ;
} else {
V_85 -> V_7 . V_102 = V_109 ;
}
V_82 = V_110 | V_111 ;
if ( F_31 ( V_23 ) )
V_82 |= V_112 ;
V_83 = V_75 -> V_96 -> V_97 ( V_81 , V_91 , V_84 , V_23 ,
& V_85 -> V_113 , V_82 ,
& V_85 -> V_7 ) ;
if ( V_83 == 0 )
V_85 -> V_6 = false ;
else if ( ( V_83 == - V_114 ) &&
( V_23 -> V_30 & V_31 ) ) {
V_23 -> V_30 &= ~ V_31 ;
goto V_100;
}
V_95:
F_32 ( V_84 ) ;
F_33 ( V_89 ) ;
return V_83 ;
}
static int F_34 ( const char * V_115 )
{
int V_28 ;
const T_4 * V_116 = ( const T_4 * ) V_115 ;
for ( V_28 = 0 ; V_28 <= V_117 ; V_28 ++ ) {
if ( V_116 [ V_28 ] == 0 )
return V_28 << 1 ;
}
F_2 ( 1 , L_7 ) ;
return V_28 << 1 ;
}
static char * F_35 ( char * V_118 , char * V_119 , int V_120 )
{
char * V_121 ;
T_1 * V_122 = ( T_1 * ) V_118 ;
if ( V_120 == V_107 ) {
T_2 * V_123 ;
V_123 = ( T_2 * ) V_122 ;
V_121 = V_118 + sizeof( T_2 ) +
V_123 -> V_124 ;
} else
V_121 = V_118 + F_17 ( V_122 -> V_125 ) ;
F_2 ( 1 , L_8 , V_121 , V_118 ) ;
if ( V_121 >= V_119 ) {
F_36 ( 1 , L_9 ,
V_121 , V_119 , V_118 ) ;
return NULL ;
} else if ( ( ( V_120 == V_107 ) &&
( V_121 + sizeof( T_2 ) > V_119 ) )
|| ( ( V_120 != V_107 ) &&
( V_121 + sizeof( T_1 ) > V_119 ) ) ) {
F_36 ( 1 , L_10 ,
V_121 , V_119 ) ;
return NULL ;
} else
return V_121 ;
}
static void F_37 ( struct V_126 * V_127 ,
const T_5 * V_60 , bool V_128 )
{
V_127 -> V_13 = & V_60 -> V_129 [ 0 ] ;
if ( V_128 )
V_127 -> V_130 = F_34 ( V_127 -> V_13 ) ;
else
V_127 -> V_130 = F_38 ( V_127 -> V_13 , V_117 ) ;
V_127 -> V_131 = V_60 -> V_132 ;
V_127 -> V_133 = F_18 ( V_60 -> V_134 . V_135 ) ;
}
static void F_39 ( struct V_126 * V_127 ,
const T_1 * V_60 )
{
V_127 -> V_13 = & V_60 -> V_129 [ 0 ] ;
V_127 -> V_130 = F_17 ( V_60 -> V_124 ) ;
V_127 -> V_131 = V_60 -> V_136 ;
}
static void F_40 ( struct V_126 * V_127 ,
const T_6 * V_60 )
{
V_127 -> V_13 = & V_60 -> V_129 [ 0 ] ;
V_127 -> V_130 = F_17 ( V_60 -> V_124 ) ;
V_127 -> V_131 = V_60 -> V_136 ;
}
static void F_41 ( struct V_126 * V_127 ,
const T_7 * V_60 )
{
V_127 -> V_13 = & V_60 -> V_129 [ 0 ] ;
V_127 -> V_130 = F_17 ( V_60 -> V_124 ) ;
V_127 -> V_131 = V_60 -> V_136 ;
V_127 -> V_133 = F_18 ( V_60 -> V_135 ) ;
}
static void F_42 ( struct V_126 * V_127 ,
const T_8 * V_60 )
{
V_127 -> V_13 = & V_60 -> V_129 [ 0 ] ;
V_127 -> V_130 = F_17 ( V_60 -> V_124 ) ;
V_127 -> V_131 = V_60 -> V_136 ;
}
static void F_43 ( struct V_126 * V_127 ,
const T_2 * V_60 )
{
V_127 -> V_13 = & V_60 -> V_129 [ 0 ] ;
V_127 -> V_130 = V_60 -> V_124 ;
V_127 -> V_131 = V_60 -> V_132 ;
}
static int F_44 ( struct V_126 * V_127 , const void * V_60 ,
T_9 V_120 , bool V_128 )
{
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
switch ( V_120 ) {
case V_103 :
F_37 ( V_127 , V_60 , V_128 ) ;
break;
case V_109 :
F_39 ( V_127 , V_60 ) ;
break;
case V_137 :
F_40 ( V_127 , V_60 ) ;
break;
case V_108 :
F_41 ( V_127 , V_60 ) ;
break;
case V_138 :
F_42 ( V_127 , V_60 ) ;
break;
case V_107 :
F_43 ( V_127 , V_60 ) ;
break;
default:
F_2 ( 1 , L_11 , V_120 ) ;
return - V_139 ;
}
return 0 ;
}
static int F_45 ( struct V_126 * V_127 , bool V_128 )
{
int V_83 = 0 ;
if ( ! V_127 -> V_13 )
return 0 ;
if ( V_128 ) {
T_4 * V_140 = ( T_4 * ) V_127 -> V_13 ;
if ( V_127 -> V_130 == 2 ) {
if ( V_140 [ 0 ] == V_141 )
V_83 = 1 ;
} else if ( V_127 -> V_130 == 4 ) {
if ( V_140 [ 0 ] == V_141 &&
V_140 [ 1 ] == V_141 )
V_83 = 2 ;
}
} else {
if ( V_127 -> V_130 == 1 ) {
if ( V_127 -> V_13 [ 0 ] == '.' )
V_83 = 1 ;
} else if ( V_127 -> V_130 == 2 ) {
if ( V_127 -> V_13 [ 0 ] == '.' && V_127 -> V_13 [ 1 ] == '.' )
V_83 = 2 ;
}
}
return V_83 ;
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = V_1 -> V_86 . V_10 -> V_20 ;
struct V_142 * V_143 = F_7 ( V_17 ) ;
if ( V_143 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_47 ( const char * V_144 ,
struct V_3 * V_145 )
{
struct V_126 V_127 ;
int V_83 ;
V_83 = F_44 ( & V_127 , V_144 , V_145 -> V_7 . V_102 ,
V_145 -> V_7 . V_146 ) ;
if ( ! V_83 ) {
V_145 -> V_7 . V_147 = V_127 . V_13 ;
V_145 -> V_7 . V_148 = V_127 . V_130 ;
V_145 -> V_7 . V_131 = V_127 . V_131 ;
}
return V_83 ;
}
static int
F_48 ( const unsigned int V_81 , struct V_90 * V_91 ,
struct V_1 * V_1 , char * * V_144 , int * V_149 )
{
T_3 V_82 ;
int V_83 = 0 ;
int V_150 = 0 ;
T_10 V_151 ;
T_10 V_152 = V_1 -> V_99 ;
struct V_3 * V_153 = V_1 -> V_5 ;
struct V_22 * V_23 = F_4 ( V_1 -> V_86 . V_10 -> V_87 ) ;
struct V_92 * V_75 = V_91 -> V_74 -> V_75 ;
if ( ! V_75 -> V_96 -> V_97 || ! V_75 -> V_96 -> V_154 )
return - V_98 ;
if ( ( V_153 == NULL ) || ( V_144 == NULL ) || ( V_149 == NULL ) )
return - V_155 ;
* V_144 = NULL ;
V_151 = V_153 -> V_7 . V_156 -
V_153 -> V_7 . V_157 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_152 < V_153 -> V_7 . V_156 ) &&
F_46 ( V_1 ) ) || ( V_152 < V_151 ) ) {
F_2 ( 1 , L_13 ) ;
F_49 ( & V_158 ) ;
if ( ! V_153 -> V_7 . V_8 && ! V_153 -> V_6 ) {
V_153 -> V_6 = true ;
F_50 ( & V_158 ) ;
if ( V_75 -> V_96 -> V_159 )
V_75 -> V_96 -> V_159 ( V_81 , V_91 , & V_153 -> V_113 ) ;
} else
F_50 ( & V_158 ) ;
if ( V_153 -> V_7 . V_160 ) {
F_2 ( 1 , L_14 ) ;
if ( V_153 -> V_7 . V_161 )
F_51 ( V_153 -> V_7 .
V_160 ) ;
else
F_52 ( V_153 -> V_7 .
V_160 ) ;
V_153 -> V_7 . V_160 = NULL ;
}
V_83 = F_24 ( V_81 , V_1 ) ;
if ( V_83 ) {
F_2 ( 1 , L_15 ,
V_83 ) ;
return V_83 ;
}
if ( V_153 -> V_7 . V_162 )
F_47 ( V_153 -> V_7 . V_162 , V_153 ) ;
}
V_82 = V_110 | V_111 ;
if ( F_31 ( V_23 ) )
V_82 |= V_112 ;
while ( ( V_152 >= V_153 -> V_7 . V_156 ) &&
( V_83 == 0 ) && ! V_153 -> V_7 . V_8 ) {
F_2 ( 1 , L_16 ) ;
V_83 = V_75 -> V_96 -> V_154 ( V_81 , V_91 , & V_153 -> V_113 ,
V_82 ,
& V_153 -> V_7 ) ;
if ( V_153 -> V_7 . V_162 )
F_47 ( V_153 -> V_7 . V_162 , V_153 ) ;
if ( V_83 )
return - V_155 ;
}
if ( V_152 < V_153 -> V_7 . V_156 ) {
int V_163 ;
char * V_164 ;
char * V_119 = V_153 -> V_7 . V_160 +
V_75 -> V_96 -> V_165 (
V_153 -> V_7 . V_160 ) ;
V_164 = V_153 -> V_7 . V_166 ;
V_151 = V_153 -> V_7 . V_156
- V_153 -> V_7 . V_157 ;
V_150 = V_152 - V_151 ;
F_2 ( 1 , L_17 , V_150 ) ;
for ( V_163 = 0 ; ( V_163 < ( V_150 ) ) && ( V_164 != NULL ) ; V_163 ++ ) {
V_164 = F_35 ( V_164 , V_119 ,
V_153 -> V_7 . V_102 ) ;
}
if ( ( V_164 == NULL ) && ( V_163 < V_150 ) ) {
F_36 ( 1 , L_18
L_19 , V_150 ,
V_152 , V_83 ) ;
}
V_83 = 0 ;
* V_144 = V_164 ;
} else {
F_2 ( 1 , L_20 ) ;
return 0 ;
}
if ( V_150 >= V_153 -> V_7 . V_157 ) {
F_2 ( 1 , L_21 ) ;
* V_149 = 0 ;
} else
* V_149 = V_153 -> V_7 . V_157 - V_150 ;
return V_83 ;
}
static int F_53 ( char * V_167 , struct V_1 * V_1 , T_11 V_168 ,
void * V_169 , char * V_170 , unsigned int V_171 )
{
struct V_3 * V_145 = V_1 -> V_5 ;
struct V_18 * V_19 = V_1 -> V_86 . V_10 -> V_87 ;
struct V_22 * V_23 = F_4 ( V_19 ) ;
struct V_126 V_127 = { NULL , } ;
struct V_14 V_15 ;
struct V_12 V_13 ;
int V_83 = 0 ;
T_12 V_133 ;
V_83 = F_44 ( & V_127 , V_167 , V_145 -> V_7 . V_102 ,
V_145 -> V_7 . V_146 ) ;
if ( V_83 )
return V_83 ;
if ( V_127 . V_130 > V_171 ) {
F_36 ( 1 , L_22 ,
V_127 . V_130 ) ;
return - V_139 ;
}
if ( F_45 ( & V_127 , V_145 -> V_7 . V_146 ) )
return 0 ;
if ( V_145 -> V_7 . V_146 ) {
struct V_172 * V_173 = V_23 -> V_174 ;
V_13 . V_13 = V_170 ;
V_13 . V_28 =
F_54 ( ( char * ) V_13 . V_13 , ( T_4 * ) V_127 . V_13 ,
V_175 ,
F_55 ( V_176 , V_127 . V_130 ,
( V_176 ) V_171 ) , V_173 ,
V_23 -> V_30 &
V_177 ) ;
V_13 . V_28 -= F_56 ( V_173 ) ;
} else {
V_13 . V_13 = V_127 . V_13 ;
V_13 . V_28 = V_127 . V_130 ;
}
switch ( V_145 -> V_7 . V_102 ) {
case V_103 :
F_57 ( & V_15 ,
& ( ( T_5 * ) V_167 ) -> V_134 ,
V_23 ) ;
break;
case V_107 :
F_20 ( & V_15 ,
( T_2 * ) V_167 ,
V_23 ) ;
break;
default:
F_16 ( & V_15 ,
( T_1 * ) V_167 ,
V_23 ) ;
break;
}
if ( V_127 . V_133 && ( V_23 -> V_30 & V_31 ) ) {
V_15 . V_32 = V_127 . V_133 ;
} else {
V_15 . V_32 = F_58 ( V_19 , V_178 ) ;
F_59 ( V_23 ) ;
}
if ( ( V_23 -> V_30 & V_179 ) &&
F_60 ( & V_15 ) )
V_15 . V_52 |= V_53 ;
F_3 ( V_1 -> V_180 , & V_13 , & V_15 ) ;
V_133 = F_61 ( V_15 . V_32 ) ;
V_83 = V_168 ( V_169 , V_13 . V_13 , V_13 . V_28 , V_1 -> V_99 , V_133 ,
V_15 . V_44 ) ;
return V_83 ;
}
int F_62 ( struct V_1 * V_1 , void * V_181 , T_11 V_168 )
{
int V_83 = 0 ;
unsigned int V_81 ;
int V_163 ;
struct V_90 * V_91 ;
struct V_3 * V_85 = NULL ;
char * V_144 ;
int V_182 = 0 ;
char * V_183 = NULL ;
char * V_119 ;
unsigned int V_171 ;
V_81 = F_63 () ;
if ( V_1 -> V_5 == NULL ) {
V_83 = F_24 ( V_81 , V_1 ) ;
F_2 ( 1 , L_23 , V_83 ) ;
if ( V_83 )
goto V_184;
}
switch ( ( int ) V_1 -> V_99 ) {
case 0 :
if ( V_168 ( V_181 , L_24 , 1 , V_1 -> V_99 ,
V_1 -> V_86 . V_10 -> V_20 -> V_185 , V_45 ) < 0 ) {
F_36 ( 1 , L_25 ) ;
V_83 = - V_94 ;
break;
}
V_1 -> V_99 ++ ;
case 1 :
if ( V_168 ( V_181 , L_26 , 2 , V_1 -> V_99 ,
F_64 ( V_1 -> V_86 . V_10 ) , V_45 ) < 0 ) {
F_36 ( 1 , L_27 ) ;
V_83 = - V_94 ;
break;
}
V_1 -> V_99 ++ ;
default:
if ( V_1 -> V_5 == NULL ) {
V_83 = - V_139 ;
F_65 ( V_81 ) ;
return V_83 ;
}
V_85 = V_1 -> V_5 ;
if ( V_85 -> V_7 . V_8 ) {
if ( V_85 -> V_7 . V_9 ) {
F_2 ( 1 , L_28 ) ;
V_83 = 0 ;
break;
}
}
V_91 = F_29 ( V_85 -> V_89 ) ;
V_83 = F_48 ( V_81 , V_91 , V_1 , & V_144 ,
& V_182 ) ;
if ( V_83 ) {
F_2 ( 1 , L_29 , V_83 ) ;
goto V_184;
} else if ( V_144 != NULL ) {
F_2 ( 1 , L_30 , V_1 -> V_99 ) ;
} else {
F_2 ( 1 , L_31 ) ;
goto V_184;
}
F_2 ( 1 , L_32 ,
V_182 , V_85 -> V_7 . V_160 ) ;
V_171 = V_91 -> V_74 -> V_75 -> V_96 -> V_165 (
V_85 -> V_7 . V_160 ) ;
V_119 = V_85 -> V_7 . V_160 + V_171 ;
V_183 = F_66 ( V_175 , V_93 ) ;
if ( V_183 == NULL ) {
V_83 = - V_94 ;
break;
}
for ( V_163 = 0 ; ( V_163 < V_182 ) && ( V_83 == 0 ) ; V_163 ++ ) {
if ( V_144 == NULL ) {
F_36 ( 1 , L_33 ,
V_182 , V_163 ) ;
break;
}
V_83 = F_53 ( V_144 , V_1 , V_168 ,
V_181 , V_183 , V_171 ) ;
if ( V_83 == - V_186 ) {
V_83 = 0 ;
break;
}
V_1 -> V_99 ++ ;
if ( V_1 -> V_99 ==
V_85 -> V_7 . V_156 ) {
F_2 ( 1 , L_34 ,
V_1 -> V_99 , V_183 ) ;
F_47 ( V_144 , V_85 ) ;
break;
} else
V_144 =
F_35 ( V_144 , V_119 ,
V_85 -> V_7 . V_102 ) ;
}
F_32 ( V_183 ) ;
break;
}
V_184:
F_65 ( V_81 ) ;
return V_83 ;
}
