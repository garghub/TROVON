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
static struct V_10 *
F_3 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_10 * V_10 , * V_16 ;
struct V_17 * V_17 ;
struct V_18 * V_19 = V_11 -> V_20 -> V_21 ;
F_2 ( 1 , L_5 , V_13 -> V_13 ) ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_23 )
V_11 -> V_22 -> V_23 ( V_11 , V_11 -> V_20 , V_13 ) ;
else
V_13 -> V_24 = F_4 ( V_13 -> V_13 , V_13 -> V_25 ) ;
V_10 = F_5 ( V_11 , V_13 ) ;
if ( V_10 ) {
int V_26 ;
V_17 = V_10 -> V_20 ;
if ( V_17 && F_6 ( V_17 ) -> V_27 == V_15 -> V_28 ) {
F_7 ( V_17 , V_15 ) ;
return V_10 ;
}
V_26 = F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
if ( V_26 )
return NULL ;
}
V_10 = F_10 ( V_11 , V_13 ) ;
if ( V_10 == NULL )
return NULL ;
V_17 = F_11 ( V_19 , V_15 ) ;
if ( ! V_17 ) {
F_9 ( V_10 ) ;
return NULL ;
}
V_16 = F_12 ( V_10 , V_17 ) ;
if ( V_16 != NULL ) {
F_9 ( V_10 ) ;
if ( F_13 ( V_16 ) )
return NULL ;
V_10 = V_16 ;
}
return V_10 ;
}
static void
F_14 ( struct V_14 * V_15 , struct V_29 * V_30 )
{
V_15 -> V_31 = V_30 -> V_32 ;
V_15 -> V_33 = V_30 -> V_34 ;
if ( V_15 -> V_35 & V_36 ) {
V_15 -> V_37 = V_38 | V_30 -> V_39 ;
V_15 -> V_40 = V_41 ;
} else {
V_15 -> V_37 = V_42 | V_30 -> V_43 ;
V_15 -> V_40 = V_44 ;
}
if ( V_15 -> V_35 & V_45 )
V_15 -> V_37 &= ~ V_46 ;
if ( V_30 -> V_47 & V_48 &&
V_15 -> V_35 & V_49 ) {
if ( V_15 -> V_50 == 0 ) {
V_15 -> V_37 &= ~ V_51 ;
V_15 -> V_37 |= V_52 ;
V_15 -> V_40 = V_53 ;
} else {
V_15 -> V_54 |= V_55 ;
}
}
}
void
F_15 ( struct V_14 * V_15 , T_1 * V_56 ,
struct V_29 * V_30 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_35 = F_16 ( V_56 -> V_57 ) ;
V_15 -> V_50 = F_17 ( V_56 -> V_58 ) ;
V_15 -> V_59 = F_17 ( V_56 -> V_60 ) ;
V_15 -> V_61 = F_17 ( V_56 -> V_62 ) ;
V_15 -> V_63 = F_18 ( V_56 -> V_64 ) ;
V_15 -> V_65 = F_18 ( V_56 -> V_66 ) ;
V_15 -> V_67 = F_18 ( V_56 -> V_68 ) ;
F_14 ( V_15 , V_30 ) ;
}
static void
F_19 ( struct V_14 * V_15 , T_2 * V_56 ,
struct V_29 * V_30 )
{
int V_69 = F_20 ( V_30 ) -> V_70 -> V_71 -> V_72 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_63 = F_21 ( V_56 -> V_73 ,
V_56 -> V_64 , V_69 ) ;
V_15 -> V_65 = F_21 ( V_56 -> V_74 ,
V_56 -> V_68 , V_69 ) ;
V_15 -> V_67 = F_21 ( V_56 -> V_74 ,
V_56 -> V_68 , V_69 ) ;
V_15 -> V_35 = F_22 ( V_56 -> V_75 ) ;
V_15 -> V_59 = F_16 ( V_56 -> V_60 ) ;
V_15 -> V_50 = F_16 ( V_56 -> V_76 ) ;
F_14 ( V_15 , V_30 ) ;
}
static int
F_23 ( const unsigned int V_77 , struct V_1 * V_1 )
{
T_3 V_78 ;
int V_79 = 0 ;
char * V_80 = NULL ;
struct V_3 * V_81 ;
struct V_29 * V_30 = F_24 ( V_1 -> V_82 . V_10 -> V_83 ) ;
struct V_84 * V_85 = NULL ;
struct V_86 * V_87 ;
struct V_88 * V_71 ;
if ( V_1 -> V_5 == NULL ) {
V_85 = F_25 ( V_30 ) ;
if ( F_13 ( V_85 ) )
return F_26 ( V_85 ) ;
V_81 = F_27 ( sizeof( struct V_3 ) , V_89 ) ;
if ( V_81 == NULL ) {
V_79 = - V_90 ;
goto V_91;
}
V_1 -> V_5 = V_81 ;
V_81 -> V_85 = F_28 ( V_85 ) ;
V_87 = F_29 ( V_85 ) ;
} else {
V_81 = V_1 -> V_5 ;
V_87 = F_29 ( V_81 -> V_85 ) ;
}
V_71 = V_87 -> V_70 -> V_71 ;
if ( ! V_71 -> V_92 -> V_93 ) {
V_79 = - V_94 ;
goto V_91;
}
V_81 -> V_6 = true ;
V_81 -> V_7 . V_8 = false ;
V_80 = F_30 ( V_1 -> V_82 . V_10 ) ;
if ( V_80 == NULL ) {
V_79 = - V_90 ;
goto V_91;
}
F_2 ( 1 , L_6 , V_80 , V_1 -> V_95 ) ;
V_96:
if ( V_87 -> V_97 )
V_81 -> V_7 . V_98 = V_99 ;
else if ( ( V_87 -> V_70 -> V_100 &
V_87 -> V_70 -> V_71 -> V_101 -> V_102 ) == 0 ) {
V_81 -> V_7 . V_98 = V_103 ;
} else if ( V_30 -> V_47 & V_104 ) {
V_81 -> V_7 . V_98 = V_105 ;
} else {
V_81 -> V_7 . V_98 = V_106 ;
}
V_78 = V_107 | V_108 ;
if ( F_31 ( V_30 ) )
V_78 |= V_109 ;
V_79 = V_71 -> V_92 -> V_93 ( V_77 , V_87 , V_80 , V_30 ,
& V_81 -> V_110 , V_78 ,
& V_81 -> V_7 ) ;
if ( V_79 == 0 )
V_81 -> V_6 = false ;
else if ( ( V_79 == - V_111 ) &&
( V_30 -> V_47 & V_104 ) ) {
V_30 -> V_47 &= ~ V_104 ;
goto V_96;
}
V_91:
F_32 ( V_80 ) ;
F_33 ( V_85 ) ;
return V_79 ;
}
static int F_34 ( const char * V_112 )
{
int V_25 ;
const T_4 * V_113 = ( const T_4 * ) V_112 ;
for ( V_25 = 0 ; V_25 <= V_114 ; V_25 ++ ) {
if ( V_113 [ V_25 ] == 0 )
return V_25 << 1 ;
}
F_2 ( 1 , L_7 ) ;
return V_25 << 1 ;
}
static char * F_35 ( char * V_115 , char * V_116 , int V_117 )
{
char * V_118 ;
T_1 * V_119 = ( T_1 * ) V_115 ;
if ( V_117 == V_103 ) {
T_2 * V_120 ;
V_120 = ( T_2 * ) V_119 ;
V_118 = V_115 + sizeof( T_2 ) +
V_120 -> V_121 ;
} else
V_118 = V_115 + F_16 ( V_119 -> V_122 ) ;
F_2 ( 1 , L_8 , V_118 , V_115 ) ;
if ( V_118 >= V_116 ) {
F_36 ( 1 , L_9 ,
V_118 , V_116 , V_115 ) ;
return NULL ;
} else if ( ( ( V_117 == V_103 ) &&
( V_118 + sizeof( T_2 ) > V_116 ) )
|| ( ( V_117 != V_103 ) &&
( V_118 + sizeof( T_1 ) > V_116 ) ) ) {
F_36 ( 1 , L_10 ,
V_118 , V_116 ) ;
return NULL ;
} else
return V_118 ;
}
static void F_37 ( struct V_123 * V_124 ,
const T_5 * V_56 , bool V_125 )
{
V_124 -> V_13 = & V_56 -> V_126 [ 0 ] ;
if ( V_125 )
V_124 -> V_127 = F_34 ( V_124 -> V_13 ) ;
else
V_124 -> V_127 = F_38 ( V_124 -> V_13 , V_114 ) ;
V_124 -> V_128 = V_56 -> V_129 ;
V_124 -> V_130 = F_17 ( V_56 -> V_131 . V_132 ) ;
}
static void F_39 ( struct V_123 * V_124 ,
const T_1 * V_56 )
{
V_124 -> V_13 = & V_56 -> V_126 [ 0 ] ;
V_124 -> V_127 = F_16 ( V_56 -> V_121 ) ;
V_124 -> V_128 = V_56 -> V_133 ;
}
static void F_40 ( struct V_123 * V_124 ,
const T_6 * V_56 )
{
V_124 -> V_13 = & V_56 -> V_126 [ 0 ] ;
V_124 -> V_127 = F_16 ( V_56 -> V_121 ) ;
V_124 -> V_128 = V_56 -> V_133 ;
}
static void F_41 ( struct V_123 * V_124 ,
const T_7 * V_56 )
{
V_124 -> V_13 = & V_56 -> V_126 [ 0 ] ;
V_124 -> V_127 = F_16 ( V_56 -> V_121 ) ;
V_124 -> V_128 = V_56 -> V_133 ;
V_124 -> V_130 = F_17 ( V_56 -> V_132 ) ;
}
static void F_42 ( struct V_123 * V_124 ,
const T_8 * V_56 )
{
V_124 -> V_13 = & V_56 -> V_126 [ 0 ] ;
V_124 -> V_127 = F_16 ( V_56 -> V_121 ) ;
V_124 -> V_128 = V_56 -> V_133 ;
}
static void F_43 ( struct V_123 * V_124 ,
const T_2 * V_56 )
{
V_124 -> V_13 = & V_56 -> V_126 [ 0 ] ;
V_124 -> V_127 = V_56 -> V_121 ;
V_124 -> V_128 = V_56 -> V_129 ;
}
static int F_44 ( struct V_123 * V_124 , const void * V_56 ,
T_9 V_117 , bool V_125 )
{
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
switch ( V_117 ) {
case V_99 :
F_37 ( V_124 , V_56 , V_125 ) ;
break;
case V_106 :
F_39 ( V_124 , V_56 ) ;
break;
case V_134 :
F_40 ( V_124 , V_56 ) ;
break;
case V_105 :
F_41 ( V_124 , V_56 ) ;
break;
case V_135 :
F_42 ( V_124 , V_56 ) ;
break;
case V_103 :
F_43 ( V_124 , V_56 ) ;
break;
default:
F_2 ( 1 , L_11 , V_117 ) ;
return - V_136 ;
}
return 0 ;
}
static int F_45 ( struct V_123 * V_124 , bool V_125 )
{
int V_79 = 0 ;
if ( ! V_124 -> V_13 )
return 0 ;
if ( V_125 ) {
T_4 * V_137 = ( T_4 * ) V_124 -> V_13 ;
if ( V_124 -> V_127 == 2 ) {
if ( V_137 [ 0 ] == V_138 )
V_79 = 1 ;
} else if ( V_124 -> V_127 == 4 ) {
if ( V_137 [ 0 ] == V_138 &&
V_137 [ 1 ] == V_138 )
V_79 = 2 ;
}
} else {
if ( V_124 -> V_127 == 1 ) {
if ( V_124 -> V_13 [ 0 ] == '.' )
V_79 = 1 ;
} else if ( V_124 -> V_127 == 2 ) {
if ( V_124 -> V_13 [ 0 ] == '.' && V_124 -> V_13 [ 1 ] == '.' )
V_79 = 2 ;
}
}
return V_79 ;
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = V_1 -> V_82 . V_10 -> V_20 ;
struct V_139 * V_140 = F_6 ( V_17 ) ;
if ( V_140 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_47 ( const char * V_141 ,
struct V_3 * V_142 )
{
struct V_123 V_124 ;
int V_79 ;
V_79 = F_44 ( & V_124 , V_141 , V_142 -> V_7 . V_98 ,
V_142 -> V_7 . V_143 ) ;
if ( ! V_79 ) {
V_142 -> V_7 . V_144 = V_124 . V_13 ;
V_142 -> V_7 . V_145 = V_124 . V_127 ;
V_142 -> V_7 . V_128 = V_124 . V_128 ;
}
return V_79 ;
}
static int
F_48 ( const unsigned int V_77 , struct V_86 * V_87 ,
struct V_1 * V_1 , char * * V_141 , int * V_146 )
{
T_3 V_78 ;
int V_79 = 0 ;
int V_147 = 0 ;
T_10 V_148 ;
T_10 V_149 = V_1 -> V_95 ;
struct V_3 * V_150 = V_1 -> V_5 ;
struct V_29 * V_30 = F_24 ( V_1 -> V_82 . V_10 -> V_83 ) ;
struct V_88 * V_71 = V_87 -> V_70 -> V_71 ;
if ( ! V_71 -> V_92 -> V_93 || ! V_71 -> V_92 -> V_151 )
return - V_94 ;
if ( ( V_150 == NULL ) || ( V_141 == NULL ) || ( V_146 == NULL ) )
return - V_152 ;
* V_141 = NULL ;
V_148 = V_150 -> V_7 . V_153 -
V_150 -> V_7 . V_154 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_149 < V_150 -> V_7 . V_153 ) &&
F_46 ( V_1 ) ) || ( V_149 < V_148 ) ) {
F_2 ( 1 , L_13 ) ;
F_49 ( & V_155 ) ;
if ( ! V_150 -> V_7 . V_8 && ! V_150 -> V_6 ) {
V_150 -> V_6 = true ;
F_50 ( & V_155 ) ;
if ( V_71 -> V_92 -> V_156 )
V_71 -> V_92 -> V_156 ( V_77 , V_87 , & V_150 -> V_110 ) ;
} else
F_50 ( & V_155 ) ;
if ( V_150 -> V_7 . V_157 ) {
F_2 ( 1 , L_14 ) ;
if ( V_150 -> V_7 . V_158 )
F_51 ( V_150 -> V_7 .
V_157 ) ;
else
F_52 ( V_150 -> V_7 .
V_157 ) ;
V_150 -> V_7 . V_157 = NULL ;
}
V_79 = F_23 ( V_77 , V_1 ) ;
if ( V_79 ) {
F_2 ( 1 , L_15 ,
V_79 ) ;
return V_79 ;
}
if ( V_150 -> V_7 . V_159 )
F_47 ( V_150 -> V_7 . V_159 , V_150 ) ;
}
V_78 = V_107 | V_108 ;
if ( F_31 ( V_30 ) )
V_78 |= V_109 ;
while ( ( V_149 >= V_150 -> V_7 . V_153 ) &&
( V_79 == 0 ) && ! V_150 -> V_7 . V_8 ) {
F_2 ( 1 , L_16 ) ;
V_79 = V_71 -> V_92 -> V_151 ( V_77 , V_87 , & V_150 -> V_110 ,
V_78 ,
& V_150 -> V_7 ) ;
if ( V_150 -> V_7 . V_159 )
F_47 ( V_150 -> V_7 . V_159 , V_150 ) ;
if ( V_79 )
return - V_152 ;
}
if ( V_149 < V_150 -> V_7 . V_153 ) {
int V_160 ;
char * V_161 ;
char * V_116 = V_150 -> V_7 . V_157 +
V_71 -> V_92 -> V_162 (
V_150 -> V_7 . V_157 ) ;
V_161 = V_150 -> V_7 . V_163 ;
V_148 = V_150 -> V_7 . V_153
- V_150 -> V_7 . V_154 ;
V_147 = V_149 - V_148 ;
F_2 ( 1 , L_17 , V_147 ) ;
for ( V_160 = 0 ; ( V_160 < ( V_147 ) ) && ( V_161 != NULL ) ; V_160 ++ ) {
V_161 = F_35 ( V_161 , V_116 ,
V_150 -> V_7 . V_98 ) ;
}
if ( ( V_161 == NULL ) && ( V_160 < V_147 ) ) {
F_36 ( 1 , L_18
L_19 , V_147 ,
V_149 , V_79 ) ;
}
V_79 = 0 ;
* V_141 = V_161 ;
} else {
F_2 ( 1 , L_20 ) ;
return 0 ;
}
if ( V_147 >= V_150 -> V_7 . V_154 ) {
F_2 ( 1 , L_21 ) ;
* V_146 = 0 ;
} else
* V_146 = V_150 -> V_7 . V_154 - V_147 ;
return V_79 ;
}
static int F_53 ( char * V_164 , struct V_1 * V_1 , T_11 V_165 ,
void * V_166 , char * V_167 , unsigned int V_168 )
{
struct V_3 * V_142 = V_1 -> V_5 ;
struct V_18 * V_19 = V_1 -> V_82 . V_10 -> V_83 ;
struct V_29 * V_30 = F_24 ( V_19 ) ;
struct V_123 V_124 = { NULL , } ;
struct V_14 V_15 ;
struct V_10 * V_10 ;
struct V_12 V_13 ;
int V_79 = 0 ;
T_12 V_130 ;
V_79 = F_44 ( & V_124 , V_164 , V_142 -> V_7 . V_98 ,
V_142 -> V_7 . V_143 ) ;
if ( V_79 )
return V_79 ;
if ( V_124 . V_127 > V_168 ) {
F_36 ( 1 , L_22 ,
V_124 . V_127 ) ;
return - V_136 ;
}
if ( F_45 ( & V_124 , V_142 -> V_7 . V_143 ) )
return 0 ;
if ( V_142 -> V_7 . V_143 ) {
struct V_169 * V_170 = V_30 -> V_171 ;
V_13 . V_13 = V_167 ;
V_13 . V_25 =
F_54 ( ( char * ) V_13 . V_13 , ( T_4 * ) V_124 . V_13 ,
V_172 ,
F_55 ( V_173 , V_124 . V_127 ,
( V_173 ) V_168 ) , V_170 ,
V_30 -> V_47 &
V_174 ) ;
V_13 . V_25 -= F_56 ( V_170 ) ;
} else {
V_13 . V_13 = V_124 . V_13 ;
V_13 . V_25 = V_124 . V_127 ;
}
switch ( V_142 -> V_7 . V_98 ) {
case V_99 :
F_57 ( & V_15 ,
& ( ( T_5 * ) V_164 ) -> V_131 ,
V_30 ) ;
break;
case V_103 :
F_19 ( & V_15 ,
( T_2 * ) V_164 ,
V_30 ) ;
break;
default:
F_15 ( & V_15 ,
( T_1 * ) V_164 ,
V_30 ) ;
break;
}
if ( V_124 . V_130 && ( V_30 -> V_47 & V_104 ) ) {
V_15 . V_28 = V_124 . V_130 ;
} else {
V_15 . V_28 = F_58 ( V_19 , V_175 ) ;
F_59 ( V_30 ) ;
}
if ( ( V_30 -> V_47 & V_176 ) &&
F_60 ( & V_15 ) )
V_15 . V_54 |= V_55 ;
V_130 = F_61 ( V_15 . V_28 ) ;
V_10 = F_3 ( V_1 -> V_177 , & V_13 , & V_15 ) ;
V_79 = V_165 ( V_166 , V_13 . V_13 , V_13 . V_25 , V_1 -> V_95 , V_130 ,
V_15 . V_40 ) ;
F_9 ( V_10 ) ;
return V_79 ;
}
int F_62 ( struct V_1 * V_1 , void * V_178 , T_11 V_165 )
{
int V_79 = 0 ;
unsigned int V_77 ;
int V_160 ;
struct V_86 * V_87 ;
struct V_3 * V_81 = NULL ;
char * V_141 ;
int V_179 = 0 ;
char * V_180 = NULL ;
char * V_116 ;
unsigned int V_168 ;
V_77 = F_63 () ;
if ( V_1 -> V_5 == NULL ) {
V_79 = F_23 ( V_77 , V_1 ) ;
F_2 ( 1 , L_23 , V_79 ) ;
if ( V_79 )
goto V_181;
}
switch ( ( int ) V_1 -> V_95 ) {
case 0 :
if ( V_165 ( V_178 , L_24 , 1 , V_1 -> V_95 ,
V_1 -> V_82 . V_10 -> V_20 -> V_182 , V_41 ) < 0 ) {
F_36 ( 1 , L_25 ) ;
V_79 = - V_90 ;
break;
}
V_1 -> V_95 ++ ;
case 1 :
if ( V_165 ( V_178 , L_26 , 2 , V_1 -> V_95 ,
F_64 ( V_1 -> V_82 . V_10 ) , V_41 ) < 0 ) {
F_36 ( 1 , L_27 ) ;
V_79 = - V_90 ;
break;
}
V_1 -> V_95 ++ ;
default:
if ( V_1 -> V_5 == NULL ) {
V_79 = - V_136 ;
F_65 ( V_77 ) ;
return V_79 ;
}
V_81 = V_1 -> V_5 ;
if ( V_81 -> V_7 . V_8 ) {
if ( V_81 -> V_7 . V_9 ) {
F_2 ( 1 , L_28 ) ;
V_79 = 0 ;
break;
}
}
V_87 = F_29 ( V_81 -> V_85 ) ;
V_79 = F_48 ( V_77 , V_87 , V_1 , & V_141 ,
& V_179 ) ;
if ( V_79 ) {
F_2 ( 1 , L_29 , V_79 ) ;
goto V_181;
} else if ( V_141 != NULL ) {
F_2 ( 1 , L_30 , V_1 -> V_95 ) ;
} else {
F_2 ( 1 , L_31 ) ;
goto V_181;
}
F_2 ( 1 , L_32 ,
V_179 , V_81 -> V_7 . V_157 ) ;
V_168 = V_87 -> V_70 -> V_71 -> V_92 -> V_162 (
V_81 -> V_7 . V_157 ) ;
V_116 = V_81 -> V_7 . V_157 + V_168 ;
V_180 = F_66 ( V_172 , V_89 ) ;
if ( V_180 == NULL ) {
V_79 = - V_90 ;
break;
}
for ( V_160 = 0 ; ( V_160 < V_179 ) && ( V_79 == 0 ) ; V_160 ++ ) {
if ( V_141 == NULL ) {
F_36 ( 1 , L_33 ,
V_179 , V_160 ) ;
break;
}
V_79 = F_53 ( V_141 , V_1 , V_165 ,
V_178 , V_180 , V_168 ) ;
if ( V_79 == - V_183 ) {
V_79 = 0 ;
break;
}
V_1 -> V_95 ++ ;
if ( V_1 -> V_95 ==
V_81 -> V_7 . V_153 ) {
F_2 ( 1 , L_34 ,
V_1 -> V_95 , V_180 ) ;
F_47 ( V_141 , V_81 ) ;
break;
} else
V_141 =
F_35 ( V_141 , V_116 ,
V_81 -> V_7 . V_98 ) ;
}
F_32 ( V_180 ) ;
break;
}
V_181:
F_65 ( V_77 ) ;
return V_79 ;
}
