static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static T_1 F_2 ( struct V_1 * V_5 )
{
switch ( V_5 -> V_6 ) {
default:
case 3 :
return V_7 ;
case 2 :
return V_8 ;
case 1 :
return V_9 ;
case 0 :
return V_10 ;
}
}
static bool F_3 ( struct V_1 * V_5 , int V_11 )
{
int V_12 = V_5 -> V_13 [ V_11 ] . V_12 ;
return ( V_12 == V_14 ||
V_12 == V_15 ) ;
}
static int F_4 ( T_1 V_12 )
{
switch ( V_12 ) {
default:
return V_16 ;
case V_17 :
case V_18 :
return V_19 ;
case V_15 :
return V_20 ;
case V_14 :
return V_21 ;
}
}
static int F_5 ( T_1 V_22 )
{
switch ( V_22 ) {
default:
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
}
}
static const char * F_6 ( T_2 V_28 )
{
switch ( V_28 ) {
#define F_7 ( V_28 ) case oid: return(#oid)
F_7 ( V_29 ) ;
F_7 ( V_30 ) ;
F_7 ( V_31 ) ;
F_7 ( V_32 ) ;
F_7 ( V_33 ) ;
F_7 ( V_34 ) ;
F_7 ( V_35 ) ;
F_7 ( V_36 ) ;
F_7 ( V_37 ) ;
F_7 ( V_38 ) ;
F_7 ( V_39 ) ;
F_7 ( V_40 ) ;
F_7 ( V_41 ) ;
F_7 ( V_42 ) ;
F_7 ( V_43 ) ;
F_7 ( V_44 ) ;
F_7 ( V_45 ) ;
F_7 ( V_46 ) ;
F_7 ( V_47 ) ;
F_7 ( V_48 ) ;
F_7 ( V_49 ) ;
F_7 ( V_50 ) ;
F_7 ( V_51 ) ;
F_7 ( V_52 ) ;
F_7 ( V_53 ) ;
F_7 ( V_54 ) ;
F_7 ( V_55 ) ;
F_7 ( V_56 ) ;
F_7 ( V_57 ) ;
F_7 ( V_58 ) ;
F_7 ( V_59 ) ;
F_7 ( V_60 ) ;
F_7 ( V_61 ) ;
F_7 ( V_62 ) ;
F_7 ( V_63 ) ;
F_7 ( V_64 ) ;
F_7 ( V_65 ) ;
F_7 ( V_66 ) ;
F_7 ( V_67 ) ;
F_7 ( V_68 ) ;
#undef F_7
}
return L_1 ;
}
static const char * F_6 ( T_2 V_28 )
{
return L_1 ;
}
static int F_8 ( T_2 V_69 )
{
int V_70 = - V_71 ;
switch ( V_69 ) {
case V_72 :
V_70 = 0 ;
break;
case V_73 :
case V_74 :
V_70 = - V_71 ;
break;
case V_75 :
V_70 = - V_76 ;
break;
case V_77 :
case V_78 :
V_70 = - V_79 ;
break;
}
return V_70 ;
}
static int F_9 ( struct V_2 * V_3 , T_2 V_28 , void * V_80 , int * V_81 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
union {
void * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
} V_89 ;
int V_70 , V_90 ;
int V_91 , V_92 , V_93 ;
V_90 = * V_81 + sizeof( * V_89 . V_86 ) ;
if ( V_90 < V_94 )
V_90 = V_94 ;
if ( V_90 > V_95 ) {
V_89 . V_82 = F_10 ( V_90 , V_96 ) ;
if ( ! V_89 . V_82 )
return - V_97 ;
} else {
V_89 . V_82 = V_5 -> V_98 ;
}
F_11 ( & V_5 -> V_99 ) ;
memset ( V_89 . V_86 , 0 , sizeof * V_89 . V_86 ) ;
V_89 . V_86 -> V_100 = V_101 ;
V_89 . V_86 -> V_102 = F_12 ( sizeof * V_89 . V_86 ) ;
V_89 . V_86 -> V_28 = V_28 ;
V_5 -> V_103 = V_28 ;
V_70 = F_13 ( V_3 , V_89 . V_84 , V_90 ) ;
V_5 -> V_103 = 0 ;
if ( V_70 < 0 )
F_14 ( V_3 -> V_104 , L_2 ,
V_105 , F_6 ( V_28 ) , V_70 ,
F_15 ( V_89 . V_88 -> V_106 ) ) ;
if ( V_70 == 0 ) {
V_91 = F_15 ( V_89 . V_88 -> V_81 ) ;
V_92 = F_15 ( V_89 . V_88 -> V_107 ) + 8 ;
if ( V_92 > V_90 ) {
F_14 ( V_3 -> V_104 , L_3
L_4 , V_105 ,
F_6 ( V_28 ) , V_92 , V_90 ) ;
V_70 = - V_71 ;
goto V_108;
}
if ( ( V_91 + V_92 ) > V_90 ) {
V_93 = V_90 - V_92 ;
} else {
V_93 = V_91 ;
}
if ( V_93 > * V_81 )
V_93 = * V_81 ;
memcpy ( V_80 , V_89 . V_82 + V_92 , V_93 ) ;
* V_81 = V_91 ;
V_70 = F_8 ( V_89 . V_88 -> V_106 ) ;
if ( V_70 < 0 )
F_14 ( V_3 -> V_104 , L_5 ,
V_105 , F_6 ( V_28 ) ,
F_15 ( V_89 . V_88 -> V_106 ) , V_70 ) ;
}
V_108:
F_16 ( & V_5 -> V_99 ) ;
if ( V_89 . V_82 != V_5 -> V_98 )
F_17 ( V_89 . V_82 ) ;
return V_70 ;
}
static int F_18 ( struct V_2 * V_3 , T_2 V_28 , const void * V_80 ,
int V_81 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
union {
void * V_82 ;
struct V_83 * V_84 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
} V_89 ;
int V_70 , V_90 ;
V_90 = V_81 + sizeof( * V_89 . V_110 ) ;
if ( V_90 < V_94 )
V_90 = V_94 ;
if ( V_90 > V_95 ) {
V_89 . V_82 = F_10 ( V_90 , V_96 ) ;
if ( ! V_89 . V_82 )
return - V_97 ;
} else {
V_89 . V_82 = V_5 -> V_98 ;
}
F_11 ( & V_5 -> V_99 ) ;
memset ( V_89 . V_110 , 0 , sizeof * V_89 . V_110 ) ;
V_89 . V_110 -> V_100 = V_113 ;
V_89 . V_110 -> V_102 = F_12 ( sizeof( * V_89 . V_110 ) + V_81 ) ;
V_89 . V_110 -> V_28 = V_28 ;
V_89 . V_110 -> V_81 = F_12 ( V_81 ) ;
V_89 . V_110 -> V_107 = F_12 ( sizeof( * V_89 . V_110 ) - 8 ) ;
V_89 . V_110 -> V_114 = F_12 ( 0 ) ;
memcpy ( V_89 . V_82 + sizeof( * V_89 . V_110 ) , V_80 , V_81 ) ;
V_5 -> V_103 = V_28 ;
V_70 = F_13 ( V_3 , V_89 . V_84 , V_90 ) ;
V_5 -> V_103 = 0 ;
if ( V_70 < 0 )
F_14 ( V_3 -> V_104 , L_2 ,
V_105 , F_6 ( V_28 ) , V_70 ,
F_15 ( V_89 . V_112 -> V_106 ) ) ;
if ( V_70 == 0 ) {
V_70 = F_8 ( V_89 . V_112 -> V_106 ) ;
if ( V_70 < 0 )
F_14 ( V_3 -> V_104 , L_6 ,
V_105 , F_6 ( V_28 ) ,
F_15 ( V_89 . V_112 -> V_106 ) , V_70 ) ;
}
F_16 ( & V_5 -> V_99 ) ;
if ( V_89 . V_82 != V_5 -> V_98 )
F_17 ( V_89 . V_82 ) ;
return V_70 ;
}
static int F_19 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct F_19 * V_116 ;
int V_70 ;
F_11 ( & V_5 -> V_99 ) ;
V_116 = ( void * ) V_5 -> V_98 ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_100 = V_117 ;
V_116 -> V_102 = F_12 ( sizeof( * V_116 ) ) ;
V_5 -> V_103 = 0 ;
V_70 = F_13 ( V_115 , ( void * ) V_116 , V_94 ) ;
F_16 ( & V_5 -> V_99 ) ;
if ( V_70 < 0 )
return V_70 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , char * V_118 ,
int V_119 , void * V_120 )
{
struct V_121 * V_122 ;
int V_123 , V_124 , V_125 , V_70 , V_126 ;
T_3 * V_127 ;
T_2 * V_128 ;
if ( V_119 == 0 )
V_123 = sizeof( T_2 ) ;
else if ( V_119 == 2 )
V_123 = strlen ( V_120 ) * sizeof( T_3 ) ;
else
return - V_71 ;
V_125 = strlen ( V_118 ) * sizeof( T_3 ) ;
V_124 = sizeof( * V_122 ) + V_125 + V_123 ;
#ifdef F_21
V_124 += 12 ;
#endif
V_122 = F_10 ( V_124 , V_96 ) ;
if ( ! V_122 )
return - V_97 ;
#ifdef F_21
V_124 -= 12 ;
memset ( V_122 , 0xCC , V_124 + 12 ) ;
#endif
if ( V_119 == 2 )
F_14 ( V_3 -> V_104 , L_7 ,
V_118 , ( V_129 * ) V_120 ) ;
else
F_14 ( V_3 -> V_104 , L_8 ,
V_118 , * ( T_1 * ) V_120 ) ;
V_122 -> V_130 = F_12 ( sizeof( * V_122 ) ) ;
V_122 -> V_131 = F_12 ( V_125 ) ;
V_122 -> type = F_12 ( V_119 ) ;
V_122 -> V_132 = F_12 ( sizeof( * V_122 ) + V_125 ) ;
V_122 -> V_133 = F_12 ( V_123 ) ;
V_127 = ( void * ) V_122 + sizeof( * V_122 ) ;
for ( V_126 = 0 ; V_126 < V_125 / sizeof( T_3 ) ; V_126 ++ )
V_127 [ V_126 ] = F_22 ( V_118 [ V_126 ] ) ;
if ( V_119 == 2 ) {
V_127 = ( void * ) V_122 + sizeof( * V_122 ) + V_125 ;
for ( V_126 = 0 ; V_126 < V_123 / sizeof( T_3 ) ; V_126 ++ )
V_127 [ V_126 ] = F_22 ( ( ( V_129 * ) V_120 ) [ V_126 ] ) ;
} else {
V_128 = ( void * ) V_122 + sizeof( * V_122 ) + V_125 ;
* V_128 = F_12 ( * ( T_1 * ) V_120 ) ;
}
#ifdef F_21
F_14 ( V_3 -> V_104 , L_9 , V_124 ) ;
for ( V_126 = 0 ; V_126 < V_124 ; V_126 += 12 ) {
T_1 * V_134 = ( T_1 * ) ( ( V_129 * ) V_122 + V_126 ) ;
F_14 ( V_3 -> V_104 , L_10 ,
F_23 ( V_134 [ 0 ] ) ,
F_23 ( V_134 [ 1 ] ) ,
F_23 ( V_134 [ 2 ] ) ) ;
}
#endif
V_70 = F_18 ( V_3 , V_34 ,
V_122 , V_124 ) ;
if ( V_70 != 0 )
F_14 ( V_3 -> V_104 , L_11 ,
V_70 ) ;
F_17 ( V_122 ) ;
return V_70 ;
}
static int F_24 ( struct V_2 * V_3 ,
char * V_118 , char * V_120 )
{
return F_20 ( V_3 , V_118 , 2 , V_120 ) ;
}
static int F_25 ( int V_135 )
{
int V_136 = 100 * ( V_135 - V_137 ) / ( V_138 - V_137 ) ;
return V_136 >= 0 ? ( V_136 <= 100 ? V_136 : 100 ) : 0 ;
}
static int F_26 ( struct V_2 * V_115 )
{
T_2 V_134 ;
V_134 = F_12 ( 1 ) ;
return F_18 ( V_115 , V_51 , & V_134 ,
sizeof( V_134 ) ) ;
}
static int F_27 ( struct V_2 * V_115 , struct V_139 * V_140 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_70 ;
V_70 = F_18 ( V_115 , V_44 , V_140 , sizeof( * V_140 ) ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_12 , V_70 ) ;
return V_70 ;
}
if ( V_70 == 0 ) {
V_5 -> V_141 = true ;
F_14 ( V_115 -> V_104 , L_13 , V_105 ) ;
}
return V_70 ;
}
static int F_29 ( struct V_2 * V_115 , const V_129 * V_142 )
{
int V_70 ;
V_70 = F_18 ( V_115 , V_43 , V_142 , V_143 ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_14 ,
V_142 , V_70 ) ;
return V_70 ;
}
return V_70 ;
}
static int F_30 ( struct V_2 * V_115 )
{
static const V_129 V_144 [ V_143 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
return F_29 ( V_115 , V_144 ) ;
}
static int F_31 ( struct V_2 * V_115 , V_129 V_142 [ V_143 ] )
{
int V_70 , V_81 ;
V_81 = V_143 ;
V_70 = F_9 ( V_115 , V_43 , V_142 , & V_81 ) ;
if ( V_70 != 0 )
memset ( V_142 , 0 , V_143 ) ;
return V_70 ;
}
static int F_32 ( struct V_2 * V_115 ,
struct V_145 * V_146 , int V_81 )
{
return F_9 ( V_115 , V_55 ,
V_146 , & V_81 ) ;
}
static bool F_33 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_129 V_142 [ V_143 ] ;
int V_70 ;
if ( ! V_5 -> V_141 )
return false ;
V_70 = F_31 ( V_115 , V_142 ) ;
return ( V_70 == 0 && ! F_34 ( V_142 ) ) ;
}
static int F_35 ( struct V_2 * V_115 , bool V_147 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_139 V_140 ;
int V_126 , V_70 = 0 ;
if ( V_5 -> V_141 ) {
V_70 = F_18 ( V_115 , V_48 , NULL , 0 ) ;
if ( V_70 == 0 ) {
V_5 -> V_141 = false ;
F_14 ( V_115 -> V_104 , L_15 ,
V_105 ) ;
if ( V_147 )
F_36 ( 100 ) ;
}
}
if ( V_147 ) {
F_37 ( V_115 , V_148 ) ;
V_140 . V_149 = F_12 ( sizeof( V_140 . V_150 ) ) ;
F_38 ( & V_140 . V_150 [ 2 ] , sizeof( V_140 . V_150 ) - 2 ) ;
V_140 . V_150 [ 0 ] = 0x1 ;
V_140 . V_150 [ 1 ] = 0xff ;
for ( V_126 = 2 ; V_126 < sizeof( V_140 . V_150 ) ; V_126 ++ )
V_140 . V_150 [ V_126 ] = 0x1 + ( V_140 . V_150 [ V_126 ] * 0xfe / 0xff ) ;
V_70 = F_27 ( V_115 , & V_140 ) ;
}
return V_70 ;
}
static int F_39 ( struct V_2 * V_115 , T_1 V_151 ,
enum V_152 V_153 , int V_154 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
T_2 V_134 ;
int V_155 , V_70 ;
F_14 ( V_115 -> V_104 , L_16 ,
V_105 , V_151 , V_153 , V_154 ) ;
if ( V_151 & V_156 ) {
if ( V_154 & V_25 )
V_155 = V_157 ;
else
V_155 = V_158 ;
} else if ( V_151 & V_159 ) {
if ( V_154 & V_25 )
V_155 = V_160 ;
else if ( V_154 & V_27 )
V_155 = V_161 ;
else
V_155 = V_162 ;
} else if ( V_153 == V_163 )
V_155 = V_164 ;
else if ( V_153 == V_165 )
V_155 = V_166 ;
else if ( V_153 == V_167 )
V_155 = V_168 ;
else
return - V_169 ;
V_134 = F_12 ( V_155 ) ;
V_70 = F_18 ( V_115 , V_49 , & V_134 ,
sizeof( V_134 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_17 ,
V_70 ) ;
return V_70 ;
}
V_5 -> V_151 = V_151 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
T_2 V_134 ;
F_14 ( V_115 -> V_104 , L_18 ,
V_105 , V_5 -> V_151 ) ;
if ( V_5 -> V_151 & V_156 ||
V_5 -> V_151 & V_159 )
V_134 = F_12 ( V_170 ) ;
else
V_134 = F_12 ( V_171 ) ;
return F_18 ( V_115 , V_50 , & V_134 ,
sizeof( V_134 ) ) ;
}
static int F_41 ( struct V_2 * V_115 , int V_172 , int V_173 )
{
T_2 V_134 ;
int V_174 , V_70 ;
F_14 ( V_115 -> V_104 , L_19 ,
V_105 , V_172 , V_173 ) ;
if ( V_172 & V_21 )
V_174 = V_175 ;
else if ( V_172 & V_20 )
V_174 = V_176 ;
else if ( V_172 & V_19 )
V_174 = V_177 ;
else if ( V_173 & V_21 )
V_174 = V_175 ;
else if ( V_173 & V_20 )
V_174 = V_176 ;
else
V_174 = V_178 ;
V_134 = F_12 ( V_174 ) ;
V_70 = F_18 ( V_115 , V_52 , & V_134 ,
sizeof( V_134 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_20 ,
V_70 ) ;
return V_70 ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_115 , int V_179 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
T_2 V_134 ;
int V_70 ;
F_14 ( V_115 -> V_104 , L_21 ,
V_105 , V_5 -> V_180 ) ;
V_134 = F_12 ( V_179 ) ;
V_70 = F_18 ( V_115 , V_45 , & V_134 ,
sizeof( V_134 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_22 ,
V_70 ) ;
return V_70 ;
}
F_42 ( V_115 ) ;
V_5 -> V_180 = V_179 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_115 , T_1 V_181 )
{
T_2 V_134 ;
F_14 ( V_115 -> V_104 , L_23 , V_105 , V_181 ) ;
if ( V_181 < 0 || V_181 > 2347 )
V_181 = 2347 ;
V_134 = F_12 ( V_181 ) ;
return F_18 ( V_115 , V_64 , & V_134 ,
sizeof( V_134 ) ) ;
}
static int F_44 ( struct V_2 * V_115 , T_1 V_182 )
{
T_2 V_134 ;
F_14 ( V_115 -> V_104 , L_23 , V_105 , V_182 ) ;
if ( V_182 < 256 || V_182 > 2346 )
V_182 = 2346 ;
V_134 = F_12 ( V_182 ) ;
return F_18 ( V_115 , V_63 , & V_134 ,
sizeof( V_134 ) ) ;
}
static void F_45 ( struct V_2 * V_115 )
{
F_37 ( V_115 , V_148 ) ;
F_39 ( V_115 , 0 , V_165 ,
V_23 ) ;
F_40 ( V_115 ) ;
F_41 ( V_115 , V_16 , V_16 ) ;
}
static int F_46 ( struct V_2 * V_115 )
{
int V_70 ;
V_70 = F_35 ( V_115 , true ) ;
F_45 ( V_115 ) ;
return V_70 ;
}
static int F_47 ( struct V_2 * V_115 , int V_183 )
{
struct V_184 V_185 ;
unsigned int V_186 ;
int V_81 , V_70 ;
F_14 ( V_115 -> V_104 , L_24 , V_105 , V_183 ) ;
if ( F_33 ( V_115 ) )
return 0 ;
V_186 = F_48 ( V_183 ) * 1000 ;
V_81 = sizeof( V_185 ) ;
V_70 = F_9 ( V_115 , V_66 , & V_185 , & V_81 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_25 ,
V_105 ) ;
return V_70 ;
}
V_185 . V_187 = F_12 ( V_186 ) ;
V_70 = F_18 ( V_115 , V_66 , & V_185 ,
sizeof( V_185 ) ) ;
F_14 ( V_115 -> V_104 , L_26 , V_105 , V_183 , V_70 ) ;
return V_70 ;
}
static int F_49 ( struct V_2 * V_115 , const V_129 * V_188 , int V_189 ,
int V_190 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_191 V_192 ;
T_1 V_12 ;
int V_70 ;
F_14 ( V_115 -> V_104 , L_27 ,
V_105 , V_190 , V_189 ) ;
if ( ( V_189 != 5 && V_189 != 13 ) || V_190 < 0 || V_190 > 3 )
return - V_71 ;
if ( V_189 == 5 )
V_12 = V_17 ;
else
V_12 = V_18 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 . V_193 = F_12 ( sizeof( V_192 ) ) ;
V_192 . V_149 = F_12 ( V_189 ) ;
V_192 . V_190 = F_12 ( V_190 ) ;
memcpy ( & V_192 . V_194 , V_188 , V_189 ) ;
if ( V_190 == V_5 -> V_195 ) {
V_192 . V_190 |= V_196 ;
V_70 = F_41 ( V_115 , V_19 ,
V_16 ) ;
if ( V_70 )
F_28 ( V_115 -> V_104 , L_28 ,
V_70 ) ;
}
V_70 = F_18 ( V_115 , V_46 , & V_192 ,
sizeof( V_192 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_29 ,
V_190 + 1 , V_70 ) ;
return V_70 ;
}
V_5 -> V_13 [ V_190 ] . V_81 = V_189 ;
V_5 -> V_13 [ V_190 ] . V_12 = V_12 ;
memcpy ( & V_5 -> V_13 [ V_190 ] . V_194 , V_188 , V_189 ) ;
memset ( & V_5 -> V_13 [ V_190 ] . V_142 , 0xff , V_143 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_115 , const V_129 * V_188 , int V_189 ,
int V_190 , const V_129 * V_197 , const V_129 * V_198 ,
int V_199 , T_1 V_12 , T_2 V_200 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_201 V_192 ;
bool V_202 ;
int V_70 ;
if ( V_190 < 0 || V_190 >= 4 ) {
F_14 ( V_115 -> V_104 , L_30 ,
V_105 , V_190 ) ;
return - V_71 ;
}
if ( V_189 > sizeof( V_192 . V_194 ) || V_189 < 0 ) {
F_14 ( V_115 -> V_104 , L_31 ,
V_105 , V_189 ) ;
return - V_71 ;
}
if ( V_200 & V_203 ) {
if ( ! V_198 || V_199 <= 0 ) {
F_14 ( V_115 -> V_104 , L_32 ,
V_105 ) ;
return - V_71 ;
}
if ( V_198 && V_199 > sizeof( V_192 . V_204 ) ) {
F_14 ( V_115 -> V_104 , L_33 , V_105 ) ;
return - V_71 ;
}
}
V_202 = V_197 && ! F_34 ( V_197 ) &&
! F_51 ( V_197 ) ;
if ( ( V_200 & V_205 ) && ! V_202 ) {
F_14 ( V_115 -> V_104 , L_34 ,
V_105 , V_197 ) ;
return - V_71 ;
}
F_14 ( V_115 -> V_104 , L_35 ,
V_105 , V_190 ,
! ! ( V_200 & V_206 ) ,
! ! ( V_200 & V_205 ) ,
! ! ( V_200 & V_203 ) ) ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 . V_193 = F_12 ( sizeof( V_192 ) -
sizeof( V_192 . V_194 ) + V_189 ) ;
V_192 . V_149 = F_12 ( V_189 ) ;
V_192 . V_190 = F_12 ( V_190 ) | V_200 ;
if ( V_12 == V_15 && V_189 == 32 ) {
memcpy ( V_192 . V_194 , V_188 , 16 ) ;
memcpy ( V_192 . V_194 + 16 , V_188 + 24 , 8 ) ;
memcpy ( V_192 . V_194 + 24 , V_188 + 16 , 8 ) ;
} else
memcpy ( V_192 . V_194 , V_188 , V_189 ) ;
if ( V_200 & V_203 )
memcpy ( V_192 . V_204 , V_198 , V_199 ) ;
if ( V_200 & V_205 ) {
memcpy ( V_192 . V_142 , V_197 , V_143 ) ;
} else {
if ( V_5 -> V_180 == V_207 )
memset ( V_192 . V_142 , 0xff , V_143 ) ;
else
F_31 ( V_115 , V_192 . V_142 ) ;
}
V_70 = F_18 ( V_115 , V_53 , & V_192 ,
F_15 ( V_192 . V_193 ) ) ;
F_14 ( V_115 -> V_104 , L_36 ,
V_105 , V_70 ) ;
if ( V_70 != 0 )
return V_70 ;
memset ( & V_5 -> V_13 [ V_190 ] , 0 , sizeof( V_5 -> V_13 [ V_190 ] ) ) ;
V_5 -> V_13 [ V_190 ] . V_81 = V_189 ;
V_5 -> V_13 [ V_190 ] . V_12 = V_12 ;
memcpy ( & V_5 -> V_13 [ V_190 ] . V_194 , V_188 , V_189 ) ;
if ( V_200 & V_205 )
memcpy ( & V_5 -> V_13 [ V_190 ] . V_142 , V_192 . V_142 , V_143 ) ;
else
memset ( & V_5 -> V_13 [ V_190 ] . V_142 , 0xff , V_143 ) ;
if ( V_200 & V_206 )
V_5 -> V_195 = V_190 ;
return 0 ;
}
static int F_52 ( struct V_2 * V_115 , int V_208 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_209 V_188 ;
if ( F_3 ( V_5 , V_208 ) )
return 0 ;
V_188 = V_5 -> V_13 [ V_208 ] ;
F_14 ( V_115 -> V_104 , L_37 , V_105 , V_208 , V_188 . V_81 ) ;
if ( V_188 . V_81 == 0 )
return 0 ;
return F_49 ( V_115 , V_188 . V_194 , V_188 . V_81 , V_208 ) ;
}
static void F_42 ( struct V_2 * V_115 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < 4 ; V_126 ++ )
F_52 ( V_115 , V_126 ) ;
}
static void F_53 ( struct V_1 * V_5 , int V_11 )
{
memset ( & V_5 -> V_13 [ V_11 ] , 0 , sizeof( V_5 -> V_13 [ V_11 ] ) ) ;
}
static int F_54 ( struct V_2 * V_115 , int V_190 , const V_129 * V_142 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_210 F_54 ;
T_2 V_211 ;
bool V_212 ;
int V_70 ;
if ( V_5 -> V_13 [ V_190 ] . V_81 == 0 )
return 0 ;
V_212 = F_3 ( V_5 , V_190 ) ;
F_14 ( V_115 -> V_104 , L_38 ,
V_105 , V_190 , V_212 ? L_39 : L_40 ,
V_5 -> V_13 [ V_190 ] . V_81 ) ;
F_53 ( V_5 , V_190 ) ;
if ( V_212 ) {
F_54 . V_193 = F_12 ( sizeof( F_54 ) ) ;
F_54 . V_190 = F_12 ( V_190 ) ;
if ( V_142 ) {
if ( ! F_51 ( V_142 ) )
F_54 . V_190 |=
V_205 ;
memcpy ( F_54 . V_142 , V_142 ,
sizeof( F_54 . V_142 ) ) ;
} else
memset ( F_54 . V_142 , 0xff ,
sizeof( F_54 . V_142 ) ) ;
V_70 = F_18 ( V_115 , V_54 , & F_54 ,
sizeof( F_54 ) ) ;
if ( V_70 != 0 )
return V_70 ;
} else {
V_211 = F_12 ( V_190 ) ;
V_70 = F_18 ( V_115 , V_47 , & V_211 ,
sizeof( V_211 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 ,
L_41 ,
V_190 , V_70 ) ;
return V_70 ;
}
}
if ( V_190 == V_5 -> V_195 )
F_41 ( V_115 , V_16 , V_16 ) ;
return 0 ;
}
static void F_55 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_213 * V_214 ;
T_2 V_215 , V_216 ;
int V_70 ;
char * V_217 = NULL ;
int V_218 ;
V_216 = V_215 = V_219 |
V_220 ;
if ( V_115 -> V_104 -> V_200 & V_221 ) {
V_215 |= V_222 |
V_223 ;
} else if ( V_115 -> V_104 -> V_200 & V_224 ) {
V_215 |= V_225 ;
}
if ( V_215 != V_216 )
goto V_226;
F_56 ( V_115 -> V_104 ) ;
V_218 = F_57 ( V_115 -> V_104 ) ;
if ( V_218 > V_5 -> V_227 ) {
V_215 |= V_225 ;
} else if ( V_218 ) {
int V_126 = 0 ;
V_217 = F_10 ( V_218 * V_143 , V_228 ) ;
if ( ! V_217 ) {
F_28 ( V_115 -> V_104 ,
L_42 ,
V_218 * V_143 ) ;
F_58 ( V_115 -> V_104 ) ;
return;
}
F_59 (ha, usbdev->net)
memcpy ( V_217 + V_126 ++ * V_143 ,
V_214 -> V_197 , V_143 ) ;
}
F_58 ( V_115 -> V_104 ) ;
if ( V_215 != V_216 )
goto V_226;
if ( V_218 ) {
V_70 = F_18 ( V_115 , V_41 , V_217 ,
V_218 * V_143 ) ;
F_17 ( V_217 ) ;
if ( V_70 == 0 )
V_215 |= V_229 ;
else
V_215 |= V_225 ;
F_14 ( V_115 -> V_104 , L_43 ,
V_218 , V_5 -> V_227 , V_70 ) ;
}
V_226:
V_70 = F_18 ( V_115 , V_31 , & V_215 ,
sizeof( V_215 ) ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_44 ,
F_15 ( V_215 ) ) ;
}
F_14 ( V_115 -> V_104 , L_45 ,
F_15 ( V_215 ) , V_70 ) ;
}
static void F_60 ( struct V_2 * V_115 ,
struct V_230 * V_231 ,
const char * V_232 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_126 , V_81 , V_233 , V_234 , V_235 ;
V_234 = V_5 -> V_236 . V_237 -> V_238 ;
V_81 = F_15 ( V_231 -> V_149 ) ;
V_233 = F_15 ( V_231 -> V_239 ) ;
V_235 = ( V_233 > 0 ) ? ( V_81 - sizeof( * V_231 ) ) / V_233 : - 1 ;
F_14 ( V_115 -> V_104 , L_46
L_47 , V_232 , V_233 , V_81 , V_235 ) ;
if ( V_233 > V_234 )
V_233 = V_234 ;
for ( V_126 = 0 ; V_126 < V_233 ; V_126 ++ ) {
T_1 * V_134 = ( T_1 * ) V_231 -> V_240 [ V_126 ] . V_241 ;
F_14 ( V_115 -> V_104 , L_48
L_49 ,
V_232 , V_231 -> V_240 [ V_126 ] . V_142 ,
F_23 ( V_134 [ 0 ] ) , F_23 ( V_134 [ 1 ] ) ,
F_23 ( V_134 [ 2 ] ) , F_23 ( V_134 [ 3 ] ) ) ;
}
}
static void F_60 ( struct V_2 * V_115 ,
struct V_230 * V_231 ,
const char * V_232 )
{
return;
}
static struct V_230 * F_61 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_230 * V_231 ;
int V_81 , V_70 , V_234 ;
V_234 = V_5 -> V_236 . V_237 -> V_238 ;
V_81 = sizeof( * V_231 ) + V_234 * sizeof( V_231 -> V_240 [ 0 ] ) ;
V_231 = F_62 ( V_81 , V_96 ) ;
if ( ! V_231 )
return F_63 ( - V_97 ) ;
V_231 -> V_149 = F_12 ( V_81 ) ;
V_231 -> V_239 = F_12 ( V_234 ) ;
V_70 = F_9 ( V_115 , V_57 , V_231 , & V_81 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_50
L_51 , V_105 , V_81 , V_234 , V_70 ) ;
F_17 ( V_231 ) ;
return F_63 ( V_70 ) ;
}
if ( F_15 ( V_231 -> V_239 ) > V_234 )
V_231 -> V_239 = F_12 ( V_234 ) ;
F_60 ( V_115 , V_231 , V_105 ) ;
return V_231 ;
}
static int F_64 ( struct V_2 * V_115 ,
struct V_230 * V_231 )
{
int V_70 , V_81 , V_242 ;
V_242 = F_15 ( V_231 -> V_239 ) ;
V_81 = sizeof( * V_231 ) + V_242 * sizeof( V_231 -> V_240 [ 0 ] ) ;
V_231 -> V_149 = F_12 ( V_81 ) ;
F_60 ( V_115 , V_231 , V_105 ) ;
V_70 = F_18 ( V_115 , V_57 , V_231 ,
F_15 ( V_231 -> V_149 ) ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_52
L_53 , V_105 , V_81 , V_242 , V_70 ) ;
}
F_17 ( V_231 ) ;
return V_70 ;
}
static struct V_230 * F_65 ( struct V_2 * V_115 ,
struct V_230 * V_231 ,
struct V_243 * V_244 ,
int V_234 )
{
int V_126 , V_81 , V_233 , V_245 , V_246 ;
V_81 = F_15 ( V_231 -> V_149 ) ;
V_233 = F_15 ( V_231 -> V_239 ) ;
if ( V_233 > V_234 )
V_233 = V_234 ;
for ( V_126 = 0 ; V_126 < V_233 ; V_126 ++ )
if ( ! F_66 ( V_231 -> V_240 [ V_126 ] . V_142 ,
V_244 -> V_142 ) )
break;
if ( V_126 == V_233 ) {
F_14 ( V_115 -> V_104 , L_54 ,
V_105 , V_244 -> V_142 ) ;
V_246 = - V_247 ;
goto error;
}
for (; V_126 + 1 < V_233 ; V_126 ++ )
V_231 -> V_240 [ V_126 ] = V_231 -> V_240 [ V_126 + 1 ] ;
V_233 -- ;
V_245 = sizeof( * V_231 ) + V_233 * sizeof( V_231 -> V_240 [ 0 ] ) ;
V_231 -> V_149 = F_12 ( V_245 ) ;
V_231 -> V_239 = F_12 ( V_233 ) ;
return V_231 ;
error:
F_17 ( V_231 ) ;
return F_63 ( V_246 ) ;
}
static struct V_230 * F_67 ( struct V_2 * V_115 ,
struct V_230 * V_231 ,
struct V_243 * V_244 ,
int V_234 )
{
int V_126 , V_246 , V_81 , V_233 , V_245 ;
V_81 = F_15 ( V_231 -> V_149 ) ;
V_233 = F_15 ( V_231 -> V_239 ) ;
if ( V_233 > V_234 )
V_233 = V_234 ;
for ( V_126 = 0 ; V_126 < V_233 ; V_126 ++ ) {
if ( F_66 ( V_231 -> V_240 [ V_126 ] . V_142 ,
V_244 -> V_142 ) )
continue;
memcpy ( V_231 -> V_240 [ V_126 ] . V_241 , V_244 -> V_241 ,
V_248 ) ;
return V_231 ;
}
if ( V_126 == V_234 ) {
F_14 ( V_115 -> V_104 , L_55 , V_105 ) ;
V_246 = - V_249 ;
goto error;
}
V_245 = sizeof( * V_231 ) + ( V_233 + 1 ) * sizeof( V_231 -> V_240 [ 0 ] ) ;
V_231 = F_68 ( V_231 , V_245 , V_96 ) ;
if ( ! V_231 ) {
V_246 = - V_97 ;
goto error;
}
V_231 -> V_149 = F_12 ( V_245 ) ;
V_231 -> V_239 = F_12 ( V_233 + 1 ) ;
memcpy ( V_231 -> V_240 [ V_233 ] . V_142 , V_244 -> V_142 , V_143 ) ;
memcpy ( V_231 -> V_240 [ V_233 ] . V_241 , V_244 -> V_241 , V_248 ) ;
return V_231 ;
error:
F_17 ( V_231 ) ;
return F_63 ( V_246 ) ;
}
static int F_69 ( struct V_237 * V_237 ,
struct V_250 * V_3 ,
enum V_251 type , T_1 * V_200 ,
struct V_252 * V_253 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_179 ;
switch ( type ) {
case V_254 :
V_179 = V_207 ;
break;
case V_255 :
V_179 = V_148 ;
break;
default:
return - V_71 ;
}
V_5 -> V_236 . V_256 = type ;
return F_37 ( V_115 , V_179 ) ;
}
static int F_71 ( struct V_237 * V_237 , T_1 V_257 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_246 ;
if ( V_257 & V_258 ) {
V_246 = F_44 ( V_115 , V_237 -> V_182 ) ;
if ( V_246 < 0 )
return V_246 ;
}
if ( V_257 & V_259 ) {
V_246 = F_43 ( V_115 , V_237 -> V_181 ) ;
if ( V_246 < 0 )
return V_246 ;
}
return 0 ;
}
static int F_72 ( struct V_237 * V_237 ,
enum V_260 type ,
int V_261 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_56 ,
V_105 , type , V_261 ) ;
if ( V_261 < 0 || ( V_261 % 100 ) )
return - V_169 ;
if ( type == V_262 ||
F_73 ( V_261 ) == F_2 ( V_5 ) ) {
if ( ! V_5 -> V_141 )
F_35 ( V_115 , true ) ;
return 0 ;
}
return - V_169 ;
}
static int F_74 ( struct V_237 * V_237 , int * V_263 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
* V_263 = F_2 ( V_5 ) ;
F_14 ( V_115 -> V_104 , L_57 , V_105 , * V_263 ) ;
return 0 ;
}
static int F_75 ( struct V_237 * V_237 , struct V_250 * V_3 ,
struct V_264 * V_265 )
{
struct V_2 * V_115 = F_76 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_70 ;
int V_266 = V_267 ;
F_14 ( V_115 -> V_104 , L_58 ) ;
F_77 ( V_115 , NULL , NULL ) ;
if ( ! V_265 )
return - V_71 ;
if ( V_5 -> V_268 && V_5 -> V_268 != V_265 )
return - V_79 ;
V_5 -> V_268 = V_265 ;
V_70 = F_26 ( V_115 ) ;
if ( V_70 == 0 ) {
if ( V_5 -> V_269 == V_270 )
V_266 = V_271 ;
F_78 ( V_5 -> V_272 , & V_5 -> V_273 , V_266 ) ;
}
return V_70 ;
}
static struct V_274 * F_79 ( struct V_2 * V_115 ,
struct V_275 * V_142 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_276 * V_183 ;
T_4 signal ;
T_5 V_277 ;
T_6 V_278 ;
T_6 V_279 ;
struct V_280 * V_281 ;
int V_282 , V_283 ;
V_129 * V_284 ;
F_14 ( V_115 -> V_104 , L_59 ,
V_142 -> V_140 . V_150 , V_142 -> V_285 , F_15 ( V_142 -> V_149 ) ) ;
V_283 = F_15 ( V_142 -> V_149 ) ;
if ( V_283 < sizeof( struct V_275 ) +
sizeof( struct V_280 ) )
return NULL ;
V_281 = (struct V_280 * ) V_142 -> V_286 ;
V_284 = ( void * ) ( V_142 -> V_286 + sizeof( struct V_280 ) ) ;
V_282 = F_80 ( V_283 - ( int ) sizeof( * V_142 ) ,
( int ) F_15 ( V_142 -> V_287 ) ) ;
V_282 -= sizeof( struct V_280 ) ;
if ( V_282 < 0 )
return NULL ;
V_183 = F_81 ( V_5 -> V_236 . V_237 ,
F_82 ( F_15 ( V_142 -> V_185 . V_187 ) ) ) ;
if ( ! V_183 )
return NULL ;
signal = F_25 ( F_15 ( V_142 -> V_288 ) ) ;
V_277 = F_83 ( * ( V_289 * ) V_281 -> V_277 ) ;
V_278 = F_84 ( V_281 -> V_290 ) ;
V_279 = F_84 ( V_281 -> V_279 ) ;
return F_85 ( V_5 -> V_236 . V_237 , V_183 , V_142 -> V_285 ,
V_277 , V_278 , V_279 , V_284 , V_282 , signal ,
V_96 ) ;
}
static struct V_275 * F_86 (
struct V_275 * V_142 ,
int * V_283 , void * V_82 , int V_81 )
{
void * V_291 , * V_292 ;
V_291 = ( char * ) V_82 + V_81 ;
V_292 = ( char * ) V_142 + * V_283 ;
if ( ( int ) ( V_291 - V_292 ) < sizeof( V_142 -> V_149 ) ) {
* V_283 = 0 ;
return NULL ;
} else {
V_142 = ( void * ) ( ( char * ) V_142 + * V_283 ) ;
* V_283 = F_15 ( V_142 -> V_149 ) ;
return V_142 ;
}
}
static bool F_87 ( struct V_275 * V_142 ,
int V_283 , void * V_82 , int V_81 )
{
void * V_291 , * V_292 ;
if ( ! V_142 || V_283 <= 0 || V_283 > V_81 )
return false ;
V_291 = ( char * ) V_82 + V_81 ;
V_292 = ( char * ) V_142 + V_283 ;
return ( int ) ( V_291 - V_292 ) >= 0 && ( int ) ( V_292 - V_82 ) >= 0 ;
}
static int F_77 ( struct V_2 * V_115 , V_129 * V_293 ,
bool * V_294 )
{
void * V_82 = NULL ;
struct V_295 * V_296 ;
struct V_275 * V_142 ;
int V_70 = - V_71 , V_81 , V_233 , V_283 , V_297 , V_298 ;
F_14 ( V_115 -> V_104 , L_60 , V_105 ) ;
V_81 = V_94 ;
V_299:
V_82 = F_62 ( V_81 , V_96 ) ;
if ( ! V_82 ) {
V_70 = - V_97 ;
goto V_300;
}
V_298 = V_81 ;
V_70 = F_9 ( V_115 , V_68 , V_82 , & V_298 ) ;
if ( V_70 != 0 || V_298 < sizeof( struct V_295 ) )
goto V_300;
if ( V_298 > V_81 ) {
V_81 = V_298 ;
F_17 ( V_82 ) ;
goto V_299;
}
V_81 = V_298 ;
V_296 = V_82 ;
V_233 = F_15 ( V_296 -> V_301 ) ;
V_297 = 0 ;
F_14 ( V_115 -> V_104 , L_61 , V_105 , V_81 ) ;
V_283 = 0 ;
V_142 = F_86 ( V_296 -> V_142 , & V_283 , V_82 , V_81 ) ;
while ( F_87 ( V_142 , V_283 , V_82 , V_81 ) ) {
if ( F_79 ( V_115 , V_142 ) && V_293 &&
V_294 ) {
if ( F_66 ( V_142 -> V_285 , V_293 ) )
* V_294 = true ;
}
V_297 ++ ;
V_142 = F_86 ( V_142 , & V_283 , V_82 , V_81 ) ;
}
F_14 ( V_115 -> V_104 , L_62
L_63 , V_105 , V_233 , V_297 ) ;
V_300:
F_17 ( V_82 ) ;
return V_70 ;
}
static void F_88 ( struct V_302 * V_303 )
{
struct V_1 * V_5 =
F_89 ( V_303 , struct V_1 , V_273 . V_303 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_70 ;
F_14 ( V_115 -> V_104 , L_64 ) ;
if ( ! V_5 -> V_268 )
return;
V_70 = F_77 ( V_115 , NULL , NULL ) ;
F_90 ( V_5 -> V_268 , V_70 < 0 ) ;
V_5 -> V_268 = NULL ;
}
static int F_91 ( struct V_237 * V_237 , struct V_250 * V_3 ,
struct V_304 * V_305 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_276 * V_183 = V_305 -> V_183 ;
struct V_139 V_140 ;
int V_172 = V_16 ;
int V_173 = V_16 ;
int V_154 = V_23 ;
int V_149 , V_126 , V_70 , V_306 = - 1 ;
if ( V_183 )
V_306 = F_92 ( V_183 -> V_307 ) ;
V_173 = F_4 ( V_305 -> V_308 . V_309 ) ;
for ( V_126 = 0 ; V_126 < V_305 -> V_308 . V_310 ; V_126 ++ )
V_172 |=
F_4 ( V_305 -> V_308 . V_311 [ V_126 ] ) ;
if ( V_305 -> V_308 . V_310 > 0 &&
V_172 == V_16 ) {
F_93 ( V_115 -> V_104 , L_65 ) ;
return - V_169 ;
}
for ( V_126 = 0 ; V_126 < V_305 -> V_308 . V_312 ; V_126 ++ )
V_154 |=
F_5 ( V_305 -> V_308 . V_313 [ V_126 ] ) ;
if ( V_305 -> V_308 . V_312 > 0 &&
V_154 == V_23 ) {
F_93 ( V_115 -> V_104 , L_66 ) ;
return - V_169 ;
}
F_14 ( V_115 -> V_104 , L_67 ,
V_305 -> V_140 , V_305 -> V_142 , V_306 ,
V_305 -> V_314 , V_305 -> V_308 . V_315 , V_305 -> V_153 ,
V_173 , V_172 , V_154 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_148 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_68 ,
V_70 ) ;
goto V_316;
}
V_70 = F_39 ( V_115 , V_305 -> V_308 . V_315 , V_305 -> V_153 ,
V_154 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_69 ,
V_70 ) ;
goto V_316;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_172 , V_173 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_70 ,
V_70 ) ;
goto V_316;
}
if ( V_183 ) {
V_70 = F_47 ( V_115 , V_306 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_71 ,
V_70 ) ;
goto V_316;
}
}
if ( V_305 -> V_188 && ( ( V_173 | V_172 ) & V_19 ) ) {
V_5 -> V_195 = V_305 -> V_208 ;
V_70 = F_49 ( V_115 , V_305 -> V_188 , V_305 -> V_189 , V_305 -> V_208 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_72 ,
V_70 , V_305 -> V_189 , V_305 -> V_208 ) ;
goto V_316;
}
}
if ( V_305 -> V_142 && ! F_34 ( V_305 -> V_142 ) &&
! F_51 ( V_305 -> V_142 ) ) {
V_70 = F_29 ( V_115 , V_305 -> V_142 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_73 ,
V_70 ) ;
goto V_316;
}
} else
F_30 ( V_115 ) ;
V_149 = V_305 -> V_317 ;
if ( V_149 > V_318 )
V_149 = V_318 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_149 = F_12 ( V_149 ) ;
memcpy ( V_140 . V_150 , V_305 -> V_140 , V_149 ) ;
F_94 ( V_115 ) ;
F_95 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_140 ) ;
if ( V_70 < 0 )
F_14 ( V_115 -> V_104 , L_74 , V_70 ) ;
return V_70 ;
V_316:
F_35 ( V_115 , true ) ;
return V_70 ;
}
static int F_96 ( struct V_237 * V_237 , struct V_250 * V_3 ,
T_6 V_319 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_75 , V_319 ) ;
V_5 -> V_320 = false ;
memset ( V_5 -> V_142 , 0 , V_143 ) ;
return F_46 ( V_115 ) ;
}
static int F_97 ( struct V_237 * V_237 , struct V_250 * V_3 ,
struct V_321 * V_253 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_276 * V_183 = V_253 -> V_183 ;
struct V_139 V_140 ;
enum V_152 V_153 ;
int V_70 , V_322 , V_149 , V_306 = - 1 ;
if ( V_183 )
V_306 = F_92 ( V_183 -> V_307 ) ;
if ( V_253 -> V_314 ) {
V_153 = V_163 ;
V_322 = V_19 ;
} else {
V_153 = V_165 ;
V_322 = V_16 ;
}
F_14 ( V_115 -> V_104 , L_76 ,
V_253 -> V_140 , V_253 -> V_142 , V_306 , V_253 -> V_314 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_207 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_77 ,
V_70 ) ;
goto V_316;
}
V_70 = F_39 ( V_115 , 0 , V_153 , V_23 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_78 ,
V_70 ) ;
goto V_316;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_322 , V_16 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_79 ,
V_70 ) ;
goto V_316;
}
if ( V_183 ) {
V_70 = F_47 ( V_115 , V_306 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_80 ,
V_70 ) ;
goto V_316;
}
}
if ( V_253 -> V_142 && ! F_34 ( V_253 -> V_142 ) &&
! F_51 ( V_253 -> V_142 ) ) {
V_70 = F_29 ( V_115 , V_253 -> V_142 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_81 ,
V_70 ) ;
goto V_316;
}
} else
F_30 ( V_115 ) ;
V_149 = V_253 -> V_317 ;
if ( V_149 > V_318 )
V_149 = V_318 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_149 = F_12 ( V_149 ) ;
memcpy ( V_140 . V_150 , V_253 -> V_140 , V_149 ) ;
F_95 ( V_115 ) ;
F_98 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_140 ) ;
if ( V_70 < 0 )
F_14 ( V_115 -> V_104 , L_82 ,
V_70 ) ;
return V_70 ;
V_316:
F_35 ( V_115 , true ) ;
return V_70 ;
}
static int F_99 ( struct V_237 * V_237 , struct V_250 * V_3 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_83 ) ;
V_5 -> V_320 = false ;
memset ( V_5 -> V_142 , 0 , V_143 ) ;
return F_46 ( V_115 ) ;
}
static int F_100 ( struct V_237 * V_237 , struct V_250 * V_323 ,
struct V_276 * V_306 , enum V_324 V_325 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
return F_47 ( V_115 ,
F_92 ( V_306 -> V_307 ) ) ;
}
static int F_101 ( struct V_237 * V_237 , struct V_250 * V_323 ,
V_129 V_326 , bool V_172 , const V_129 * V_327 ,
struct V_328 * V_253 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_2 V_200 ;
F_14 ( V_115 -> V_104 , L_84 ,
V_105 , V_326 , V_327 , V_253 -> V_12 ) ;
switch ( V_253 -> V_12 ) {
case V_17 :
case V_18 :
return F_49 ( V_115 , V_253 -> V_188 , V_253 -> V_189 ,
V_326 ) ;
case V_15 :
case V_14 :
V_200 = 0 ;
if ( V_253 -> V_329 && V_253 -> V_199 > 0 )
V_200 |= V_203 ;
if ( V_327 )
V_200 |= V_205 |
V_206 ;
return F_50 ( V_115 , V_253 -> V_188 , V_253 -> V_189 ,
V_326 , V_327 , V_253 -> V_329 ,
V_253 -> V_199 , V_253 -> V_12 , V_200 ) ;
default:
F_14 ( V_115 -> V_104 , L_85 ,
V_105 , V_253 -> V_12 ) ;
return - V_169 ;
}
}
static int F_102 ( struct V_237 * V_237 , struct V_250 * V_323 ,
V_129 V_326 , bool V_172 , const V_129 * V_327 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_86 , V_105 , V_326 , V_327 ) ;
return F_54 ( V_115 , V_326 , V_327 ) ;
}
static int F_103 ( struct V_237 * V_237 , struct V_250 * V_323 ,
V_129 V_326 , bool V_330 , bool V_331 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_209 V_188 ;
F_14 ( V_115 -> V_104 , L_87 , V_105 , V_326 ) ;
V_5 -> V_195 = V_326 ;
if ( F_3 ( V_5 , V_326 ) )
return 0 ;
V_188 = V_5 -> V_13 [ V_326 ] ;
return F_49 ( V_115 , V_188 . V_194 , V_188 . V_81 , V_326 ) ;
}
static void F_104 ( struct V_2 * V_115 ,
struct V_332 * V_333 )
{
T_2 V_334 , V_288 ;
int V_70 , V_81 ;
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
V_81 = sizeof( V_334 ) ;
V_70 = F_9 ( V_115 , V_33 , & V_334 , & V_81 ) ;
if ( V_70 == 0 ) {
V_333 -> V_335 . V_336 = F_15 ( V_334 ) / 1000 ;
V_333 -> V_337 |= V_338 ;
}
V_81 = sizeof( V_288 ) ;
V_70 = F_9 ( V_115 , V_61 , & V_288 , & V_81 ) ;
if ( V_70 == 0 ) {
V_333 -> signal = F_25 ( F_15 ( V_288 ) ) ;
V_333 -> V_337 |= V_339 ;
}
}
static int F_105 ( struct V_237 * V_237 , struct V_250 * V_3 ,
V_129 * V_285 , struct V_332 * V_333 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( F_66 ( V_5 -> V_142 , V_285 ) )
return - V_247 ;
F_104 ( V_115 , V_333 ) ;
return 0 ;
}
static int F_106 ( struct V_237 * V_237 , struct V_250 * V_3 ,
int V_11 , V_129 * V_285 , struct V_332 * V_333 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( V_11 != 0 )
return - V_247 ;
memcpy ( V_285 , V_5 -> V_142 , V_143 ) ;
F_104 ( V_115 , V_333 ) ;
return 0 ;
}
static int F_107 ( struct V_237 * V_237 , struct V_250 * V_323 ,
struct V_243 * V_244 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_230 * V_231 ;
T_1 * V_134 = ( T_1 * ) V_244 -> V_241 ;
F_14 ( V_115 -> V_104 , L_88 , V_105 ,
V_244 -> V_142 ,
F_23 ( V_134 [ 0 ] ) , F_23 ( V_134 [ 1 ] ) ,
F_23 ( V_134 [ 2 ] ) , F_23 ( V_134 [ 3 ] ) ) ;
V_231 = F_61 ( V_115 ) ;
if ( F_108 ( V_231 ) ) {
return F_109 ( V_231 ) ;
}
V_231 = F_67 ( V_115 , V_231 , V_244 , V_237 -> V_238 ) ;
if ( F_108 ( V_231 ) ) {
return F_109 ( V_231 ) ;
}
return F_64 ( V_115 , V_231 ) ;
}
static int F_110 ( struct V_237 * V_237 , struct V_250 * V_323 ,
struct V_243 * V_244 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_230 * V_231 ;
T_1 * V_134 = ( T_1 * ) V_244 -> V_241 ;
F_14 ( V_115 -> V_104 , L_88 , V_105 ,
V_244 -> V_142 ,
F_23 ( V_134 [ 0 ] ) , F_23 ( V_134 [ 1 ] ) ,
F_23 ( V_134 [ 2 ] ) , F_23 ( V_134 [ 3 ] ) ) ;
V_231 = F_61 ( V_115 ) ;
if ( F_108 ( V_231 ) ) {
return F_109 ( V_231 ) ;
}
V_231 = F_65 ( V_115 , V_231 , V_244 , V_237 -> V_238 ) ;
if ( F_108 ( V_231 ) ) {
return F_109 ( V_231 ) ;
}
return F_64 ( V_115 , V_231 ) ;
}
static int F_111 ( struct V_237 * V_237 , struct V_250 * V_323 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_230 V_241 ;
F_14 ( V_115 -> V_104 , L_60 , V_105 ) ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_149 = F_12 ( sizeof( V_241 ) ) ;
V_241 . V_239 = F_12 ( 0 ) ;
return F_18 ( V_115 , V_57 , & V_241 , sizeof( V_241 ) ) ;
}
static int F_112 ( struct V_237 * V_237 , struct V_250 * V_3 ,
bool V_340 , int V_341 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_342 ;
T_2 V_179 ;
int V_70 ;
if ( V_5 -> V_269 != V_343 )
return - V_169 ;
F_14 ( V_115 -> V_104 , L_89 , V_105 ,
V_340 ? L_90 : L_91 ,
V_341 ) ;
if ( V_340 )
V_342 = V_344 ;
else
V_342 = V_345 ;
if ( V_342 == V_5 -> V_342 )
return 0 ;
V_5 -> V_342 = V_342 ;
V_179 = F_12 ( V_342 ) ;
V_70 = F_18 ( V_115 , V_67 , & V_179 , sizeof( V_179 ) ) ;
F_14 ( V_115 -> V_104 , L_92 ,
V_105 , V_70 ) ;
return V_70 ;
}
static int F_113 ( struct V_237 * V_237 ,
struct V_250 * V_3 ,
T_4 V_346 , T_1 V_347 )
{
struct V_1 * V_5 = F_70 ( V_237 ) ;
V_5 -> V_348 = V_346 ;
V_5 -> V_349 = V_347 ;
V_5 -> V_350 = 0 ;
return 0 ;
}
static void F_114 ( struct V_2 * V_115 , V_129 * V_142 ,
struct V_145 * V_146 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_276 * V_183 ;
struct V_184 V_185 ;
struct V_139 V_140 ;
T_4 signal ;
T_5 V_277 ;
T_6 V_278 ;
T_6 V_279 ;
T_2 V_288 ;
V_129 V_351 [ 34 ] ;
int V_81 , V_70 , V_282 ;
V_81 = sizeof( V_288 ) ;
V_288 = 0 ;
V_70 = F_9 ( V_115 , V_61 , & V_288 , & V_81 ) ;
signal = F_25 ( F_15 ( V_288 ) ) ;
F_14 ( V_115 -> V_104 , L_93
L_94 , V_105 , V_70 , F_15 ( V_288 ) ,
F_25 ( F_15 ( V_288 ) ) ) ;
if ( V_146 ) {
V_278 = F_84 ( V_146 -> V_352 . V_353 ) ;
} else {
V_278 = ( V_5 -> V_180 == V_148 ) ?
V_354 : V_355 ;
}
V_81 = sizeof( V_185 ) ;
V_70 = F_9 ( V_115 , V_66 , & V_185 , & V_81 ) ;
F_14 ( V_115 -> V_104 , L_95 ,
V_105 , V_70 ) ;
if ( V_70 >= 0 ) {
V_279 = F_84 ( V_185 . V_356 ) ;
V_183 = F_81 ( V_5 -> V_236 . V_237 ,
F_82 ( F_15 ( V_185 . V_187 ) ) ) ;
if ( ! V_183 ) {
F_28 ( V_115 -> V_104 , L_96
L_53 , V_105 ) ;
return;
}
} else {
F_28 ( V_115 -> V_104 , L_97 ,
V_105 ) ;
return;
}
V_81 = sizeof( V_140 ) ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_70 = F_9 ( V_115 , V_44 , & V_140 , & V_81 ) ;
F_14 ( V_115 -> V_104 , L_98
L_99 , V_105 , V_70 ,
F_15 ( V_140 . V_149 ) , V_140 . V_150 ) ;
if ( F_15 ( V_140 . V_149 ) > 32 )
V_140 . V_149 = F_12 ( 32 ) ;
V_351 [ 0 ] = V_357 ;
V_351 [ 1 ] = F_15 ( V_140 . V_149 ) ;
memcpy ( & V_351 [ 2 ] , V_140 . V_150 , F_15 ( V_140 . V_149 ) ) ;
V_282 = F_15 ( V_140 . V_149 ) + 2 ;
V_277 = 0 ;
F_14 ( V_115 -> V_104 , L_100
L_101
L_102 , V_105 , ( V_183 ? V_183 -> V_307 : - 1 ) ,
V_142 , ( T_1 ) V_277 , V_278 , V_279 , V_282 ,
V_140 . V_150 , signal ) ;
F_85 ( V_5 -> V_236 . V_237 , V_183 , V_142 ,
V_277 , V_278 , V_279 , V_351 , V_282 ,
signal , V_96 ) ;
}
static void F_115 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_145 * V_146 = NULL ;
V_129 V_142 [ V_143 ] ;
int V_358 , V_359 ;
V_129 * V_360 , * V_352 ;
int V_70 , V_107 ;
bool V_361 = false ;
bool V_362 ;
if ( V_5 -> V_180 == V_148 && V_5 -> V_320 ) {
V_361 = true ;
}
V_359 = 0 ;
V_358 = 0 ;
V_360 = NULL ;
V_352 = NULL ;
if ( V_5 -> V_180 == V_148 ) {
V_146 = F_62 ( V_94 , V_96 ) ;
if ( ! V_146 ) {
F_116 ( V_363 , & V_5 -> V_364 ) ;
F_117 ( V_5 -> V_272 , & V_5 -> V_303 ) ;
return;
}
V_70 = F_32 ( V_115 , V_146 , V_94 ) ;
if ( ! V_70 ) {
V_359 = F_15 ( V_146 -> V_365 ) ;
if ( V_359 > 0 ) {
V_107 = F_15 ( V_146 -> V_366 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_360 = ( V_129 * ) V_146 + V_107 ;
if ( V_107 + V_359 > V_94 )
V_359 =
V_94 - V_107 ;
}
V_358 = F_15 ( V_146 -> V_367 ) ;
if ( V_358 > 0 ) {
V_107 = F_15 ( V_146 -> V_368 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_352 = ( V_129 * ) V_146 + V_107 ;
if ( V_107 + V_358 > V_94 )
V_358 =
V_94 - V_107 ;
}
} else {
F_17 ( V_146 ) ;
V_146 = NULL ;
}
} else if ( F_118 ( V_5 -> V_180 != V_207 ) )
return;
V_70 = F_31 ( V_115 , V_142 ) ;
if ( V_70 < 0 )
memset ( V_142 , 0 , sizeof( V_142 ) ) ;
F_14 ( V_115 -> V_104 , L_103 ,
V_142 , V_361 ? L_104 : L_105 ) ;
V_362 = false ;
F_77 ( V_115 , V_142 , & V_362 ) ;
if ( ! F_34 ( V_142 ) && ! V_362 ) {
F_114 ( V_115 , V_142 , V_146 ) ;
}
if ( V_5 -> V_180 == V_148 ) {
if ( ! V_361 )
F_119 ( V_115 -> V_104 , V_142 , V_360 ,
V_359 , V_352 ,
V_358 , 0 , V_96 ) ;
else
F_120 ( V_115 -> V_104 , NULL , V_142 ,
V_360 , V_359 ,
V_352 , V_358 , V_96 ) ;
} else if ( V_5 -> V_180 == V_207 )
F_121 ( V_115 -> V_104 , V_142 , V_96 ) ;
if ( V_146 != NULL )
F_17 ( V_146 ) ;
V_5 -> V_320 = true ;
memcpy ( V_5 -> V_142 , V_142 , V_143 ) ;
F_98 ( V_115 ) ;
F_122 ( V_115 -> V_104 ) ;
}
static void F_123 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( V_5 -> V_320 ) {
V_5 -> V_320 = false ;
memset ( V_5 -> V_142 , 0 , V_143 ) ;
F_46 ( V_115 ) ;
F_124 ( V_115 -> V_104 , 0 , NULL , 0 , V_96 ) ;
}
F_125 ( V_115 -> V_104 ) ;
}
static void F_126 ( struct V_302 * V_303 )
{
struct V_1 * V_5 =
F_89 ( V_303 , struct V_1 , V_303 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( F_127 ( V_363 , & V_5 -> V_364 ) )
F_115 ( V_115 ) ;
if ( F_127 ( V_369 , & V_5 -> V_364 ) )
F_123 ( V_115 ) ;
if ( F_127 ( V_370 , & V_5 -> V_364 ) )
F_55 ( V_115 ) ;
}
static void F_128 ( struct V_250 * V_3 )
{
struct V_2 * V_115 = F_76 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( F_129 ( V_370 , & V_5 -> V_364 ) )
return;
F_116 ( V_370 , & V_5 -> V_364 ) ;
F_117 ( V_5 -> V_272 , & V_5 -> V_303 ) ;
}
static void F_130 ( struct V_2 * V_115 ,
struct V_371 * V_372 ,
int V_81 )
{
V_129 * V_82 ;
const char * type ;
int V_200 , V_90 , V_373 ;
bool V_374 , V_375 ;
struct V_376 * V_377 ;
enum V_378 V_379 ;
if ( V_81 < F_131 ( struct V_371 , V_89 ) +
sizeof( struct V_376 ) ) {
F_132 ( V_115 -> V_104 , L_106 ,
V_81 ) ;
return;
}
V_82 = ( void * ) & V_372 -> V_89 . V_380 [ 0 ] ;
V_90 = V_81 - F_131 ( struct V_371 , V_89 ) ;
while ( V_90 >= sizeof( * V_377 ) ) {
V_377 = ( void * ) V_82 ;
type = L_107 ;
V_200 = F_15 ( V_377 -> V_200 ) ;
V_374 = false ;
V_375 = false ;
if ( V_200 & 0x1 )
type = L_108 ;
if ( V_200 & 0x2 )
type = L_109 ;
if ( V_200 & 0x6 ) {
V_374 = true ;
type = L_110 ;
}
if ( V_200 & 0xe ) {
V_375 = true ;
type = L_111 ;
}
F_132 ( V_115 -> V_104 , L_112 ,
type , F_15 ( V_377 -> V_200 ) ) ;
if ( V_374 ) {
V_379 = V_381 ;
V_373 = - 1 ;
F_133 ( V_115 -> V_104 ,
V_377 -> V_142 ,
V_379 , V_373 , NULL ,
V_96 ) ;
}
if ( V_375 ) {
V_379 = V_382 ;
V_373 = - 1 ;
F_133 ( V_115 -> V_104 ,
V_377 -> V_142 ,
V_379 , V_373 , NULL ,
V_96 ) ;
}
V_90 -= F_15 ( V_377 -> V_149 ) ;
V_82 += F_15 ( V_377 -> V_149 ) ;
}
}
static void F_134 ( struct V_2 * V_115 ,
struct V_371 * V_372 ,
int V_81 )
{
struct V_383 * V_384 ;
int V_385 , V_386 , V_126 ;
if ( V_81 < F_131 ( struct V_371 , V_89 ) +
sizeof( struct V_383 ) ) {
F_132 ( V_115 -> V_104 , L_113 ,
V_81 ) ;
return;
}
V_385 = F_15 ( V_372 -> V_89 . V_384 . V_387 ) *
sizeof( struct V_388 ) ;
V_386 = sizeof( struct V_383 ) + V_385 +
F_131 ( struct V_371 , V_89 ) ;
if ( V_81 < V_386 ) {
F_132 ( V_115 -> V_104 , L_114 ,
V_81 , V_386 ) ;
return;
}
V_384 = & V_372 -> V_89 . V_384 ;
F_132 ( V_115 -> V_104 , L_115 ,
F_15 ( V_384 -> V_389 ) ,
F_15 ( V_384 -> V_387 ) ) ;
if ( F_15 ( V_384 -> V_389 ) != 1 )
return;
for ( V_126 = 0 ; V_126 < F_15 ( V_384 -> V_387 ) ; V_126 ++ ) {
struct V_388 * V_390 =
& V_384 -> V_391 [ V_126 ] ;
F_14 ( V_115 -> V_104 , L_116 ,
V_126 , F_15 ( V_390 -> V_200 ) , V_390 -> V_142 ) ;
#if 0
struct iw_pmkid_cand pcand;
union iwreq_data wrqu;
memset(&pcand, 0, sizeof(pcand));
if (le32_to_cpu(cand->flags) & 0x01)
pcand.flags |= IW_PMKID_CAND_PREAUTH;
pcand.index = i;
memcpy(pcand.bssid.sa_data, cand->bssid, ETH_ALEN);
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = sizeof(pcand);
wireless_send_event(usbdev->net, IWEVPMKIDCAND, &wrqu,
(u8 *)&pcand);
#endif
}
}
static void F_135 ( struct V_2 * V_115 ,
struct V_392 * V_393 , int V_90 )
{
struct V_371 * V_372 ;
int V_81 , V_107 ;
V_107 = F_131 ( struct V_392 , V_106 ) +
F_15 ( V_393 -> V_107 ) ;
V_81 = F_15 ( V_393 -> V_149 ) ;
if ( V_81 < 8 ) {
F_132 ( V_115 -> V_104 , L_117 ,
V_81 ) ;
return;
}
if ( V_107 + V_81 > V_90 ) {
F_132 ( V_115 -> V_104 , L_118 ,
V_107 + V_81 , V_90 ) ;
return;
}
V_372 = ( void * ) ( ( V_129 * ) V_393 + V_107 ) ;
switch ( F_15 ( V_372 -> V_394 ) ) {
case V_395 :
F_132 ( V_115 -> V_104 , L_119 ,
F_15 ( V_372 -> V_89 . V_396 ) ) ;
return;
case V_397 :
F_132 ( V_115 -> V_104 , L_120 ,
F_15 ( V_372 -> V_89 . V_398 ) ) ;
return;
case V_399 :
F_130 ( V_115 , V_372 , V_81 ) ;
return;
case V_400 :
F_134 ( V_115 , V_372 , V_81 ) ;
return;
default:
F_132 ( V_115 -> V_104 , L_121 ,
F_15 ( V_372 -> V_394 ) ) ;
}
}
static void F_136 ( struct V_2 * V_115 , void * V_401 , int V_90 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_392 * V_393 = V_401 ;
switch ( V_393 -> V_106 ) {
case V_402 :
if ( V_5 -> V_103 == V_53 ) {
F_14 ( V_115 -> V_104 , L_122 ) ;
return;
}
F_94 ( V_115 ) ;
F_132 ( V_115 -> V_104 , L_123 ) ;
F_116 ( V_363 , & V_5 -> V_364 ) ;
F_117 ( V_5 -> V_272 , & V_5 -> V_303 ) ;
break;
case V_403 :
F_132 ( V_115 -> V_104 , L_124 ) ;
F_116 ( V_369 , & V_5 -> V_364 ) ;
F_117 ( V_5 -> V_272 , & V_5 -> V_303 ) ;
break;
case V_404 :
F_135 ( V_115 , V_393 , V_90 ) ;
break;
default:
F_132 ( V_115 -> V_104 , L_125 ,
F_15 ( V_393 -> V_106 ) ) ;
break;
}
}
static int F_137 ( struct V_2 * V_115 , struct V_237 * V_237 )
{
struct {
T_2 V_301 ;
T_2 V_405 [ 8 ] ;
} V_406 ;
struct V_407 * V_408 ;
V_129 V_409 [ sizeof( * V_408 ) + sizeof( V_408 -> V_410 ) * 16 ] ;
int V_81 , V_411 , V_126 , V_412 ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_81 = sizeof( V_406 ) ;
V_411 = F_9 ( V_115 , V_58 ,
& V_406 , & V_81 ) ;
if ( V_411 >= 0 ) {
V_412 = F_15 ( V_406 . V_301 ) ;
if ( V_412 > 8 )
V_412 = 8 ;
for ( V_126 = 0 ; V_126 < V_412 ; V_126 ++ ) {
switch ( F_15 ( V_406 . V_405 [ V_126 ] ) ) {
case V_413 :
case V_414 :
V_5 -> V_408 |= V_415 ;
break;
case V_416 :
V_5 -> V_408 |= V_417 ;
break;
case V_418 :
V_5 -> V_408 |= V_419 ;
break;
}
}
}
V_408 = (struct V_407 * ) V_409 ;
V_81 = sizeof( V_409 ) ;
V_411 = F_9 ( V_115 , V_56 , V_408 , & V_81 ) ;
if ( V_411 >= 0 ) {
F_14 ( V_115 -> V_104 , L_126
L_127 ,
F_15 ( V_408 -> V_149 ) ,
F_15 ( V_408 -> V_389 ) ,
F_15 ( V_408 -> V_242 ) ,
F_15 ( V_408 -> V_420 ) ) ;
V_237 -> V_238 = F_15 ( V_408 -> V_242 ) ;
} else
V_237 -> V_238 = 0 ;
return V_411 ;
}
static void F_138 ( struct V_2 * V_115 , T_4 V_288 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
enum V_421 V_422 ;
int V_423 , V_424 , V_425 ;
if ( V_5 -> V_348 >= 0 || V_288 >= 0 )
return;
if ( V_5 -> V_180 != V_148 )
return;
V_425 = V_5 -> V_350 ;
V_423 = V_5 -> V_348 ;
V_424 = V_5 -> V_349 ;
if ( V_288 < V_423 && ( V_425 == 0 || V_288 < V_425 - V_424 ) )
V_422 = V_426 ;
else if ( V_288 > V_423 && ( V_425 == 0 || V_288 > V_425 + V_424 ) )
V_422 = V_427 ;
else
return;
V_5 -> V_350 = V_288 ;
F_139 ( V_115 -> V_104 , V_422 , V_96 ) ;
}
static void F_140 ( struct V_302 * V_303 )
{
struct V_1 * V_5 =
F_89 ( V_303 , struct V_1 ,
V_428 . V_303 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_2 V_288 , V_134 ;
int V_81 , V_70 , V_429 ;
int V_430 = V_431 ;
void * V_82 ;
if ( ! F_33 ( V_115 ) ) {
if ( V_5 -> V_269 == V_270 && V_5 -> V_141 &&
! V_5 -> V_268 ) {
F_77 ( V_115 , NULL , NULL ) ;
F_26 ( V_115 ) ;
}
goto V_432;
}
V_81 = sizeof( V_288 ) ;
V_70 = F_9 ( V_115 , V_61 , & V_288 , & V_81 ) ;
if ( V_70 == 0 ) {
V_5 -> V_433 = F_25 ( F_15 ( V_288 ) ) ;
F_138 ( V_115 , F_15 ( V_288 ) ) ;
}
F_14 ( V_115 -> V_104 , L_128 ,
V_70 , F_15 ( V_288 ) , F_25 ( F_15 ( V_288 ) ) ) ;
if ( V_5 -> V_434 > 0 && V_5 -> V_433 <= 25 ) {
V_429 = F_141 ( V_5 -> V_434 ) ;
if ( V_429 > V_431 )
V_429 = V_431 ;
else if ( V_429 <= 0 )
V_429 = 1 ;
V_430 = V_429 ;
V_134 = F_12 ( 1 ) ;
F_18 ( V_115 , V_51 , & V_134 ,
sizeof( V_134 ) ) ;
V_81 = V_94 ;
V_82 = F_10 ( V_81 , V_96 ) ;
if ( ! V_82 )
goto V_432;
F_9 ( V_115 , V_68 , V_82 , & V_81 ) ;
F_17 ( V_82 ) ;
}
V_432:
if ( V_430 >= V_271 )
V_430 = F_142 ( V_430 ) ;
else {
V_429 = F_142 ( V_430 ) ;
if ( abs ( V_429 - V_430 ) <= 10 )
V_430 = V_429 ;
}
F_78 ( V_5 -> V_272 , & V_5 -> V_428 ,
V_430 ) ;
}
static void F_143 ( struct V_2 * V_115 , int V_269 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_5 -> V_269 = V_269 ;
V_5 -> V_435 [ 0 ] = V_436 [ 0 ] ;
V_5 -> V_435 [ 1 ] = V_436 [ 1 ] ;
V_5 -> V_435 [ 2 ] = 0 ;
V_5 -> V_437 = V_438 ;
V_5 -> V_439 = V_440 ;
V_5 -> V_441 = V_442 ;
V_5 -> V_6 = V_443 ;
V_5 -> V_444 = V_445 ;
V_5 -> V_446 = V_447 ;
V_5 -> V_435 [ 0 ] = toupper ( V_5 -> V_435 [ 0 ] ) ;
V_5 -> V_435 [ 1 ] = toupper ( V_5 -> V_435 [ 1 ] ) ;
if ( ! strcmp ( V_5 -> V_435 , L_129 ) )
strcpy ( V_5 -> V_435 , L_130 ) ;
if ( V_5 -> V_441 < 0 )
V_5 -> V_441 = 0 ;
else if ( V_5 -> V_441 > 2 )
V_5 -> V_441 = 2 ;
if ( V_5 -> V_6 < 0 )
V_5 -> V_6 = 0 ;
else if ( V_5 -> V_6 > 3 )
V_5 -> V_6 = 3 ;
if ( V_5 -> V_444 < - 80 )
V_5 -> V_444 = - 80 ;
else if ( V_5 -> V_444 > - 60 )
V_5 -> V_444 = - 60 ;
if ( V_5 -> V_446 < 0 )
V_5 -> V_446 = 0 ;
else if ( V_5 -> V_446 > 2 )
V_5 -> V_446 = 2 ;
if ( V_448 < 0 )
V_5 -> V_434 = 500 ;
else
V_5 -> V_434 = V_448 ;
}
static int F_144 ( struct V_2 * V_115 )
{
F_143 ( V_115 , V_449 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_115 )
{
F_143 ( V_115 , V_270 ) ;
return 0 ;
}
static int F_146 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
char V_82 [ 8 ] ;
F_143 ( V_115 , V_343 ) ;
F_24 ( V_115 , L_131 , V_5 -> V_435 ) ;
F_24 ( V_115 , L_132 ,
V_5 -> V_437 ? L_133 : L_134 ) ;
F_24 ( V_115 , L_135 ,
V_5 -> V_439 ? L_133 : L_134 ) ;
sprintf ( V_82 , L_136 , V_5 -> V_441 ) ;
F_24 ( V_115 , L_137 , V_82 ) ;
sprintf ( V_82 , L_136 , V_5 -> V_6 ) ;
F_24 ( V_115 , L_138 , V_82 ) ;
sprintf ( V_82 , L_136 , V_5 -> V_444 ) ;
F_24 ( V_115 , L_139 , V_82 ) ;
sprintf ( V_82 , L_136 , V_5 -> V_446 ) ;
F_24 ( V_115 , L_140 , V_82 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_115 , struct V_450 * V_451 )
{
struct V_237 * V_237 ;
struct V_1 * V_5 ;
int V_411 , V_81 ;
T_2 V_134 ;
V_237 = F_148 ( & V_452 , sizeof( struct V_1 ) ) ;
if ( ! V_237 )
return - V_97 ;
V_5 = F_70 ( V_237 ) ;
V_115 -> V_104 -> V_453 = & V_5 -> V_236 ;
V_5 -> V_236 . V_237 = V_237 ;
V_5 -> V_236 . V_256 = V_255 ;
V_115 -> V_4 = V_5 ;
V_5 -> V_115 = V_115 ;
F_149 ( & V_5 -> V_99 ) ;
V_5 -> V_272 = F_150 ( L_141 ) ;
F_151 ( & V_5 -> V_303 , F_126 ) ;
F_152 ( & V_5 -> V_428 , F_140 ) ;
F_152 ( & V_5 -> V_273 , F_88 ) ;
V_411 = F_153 ( V_115 , V_451 , V_454 ) ;
if ( V_411 < 0 )
goto V_455;
V_115 -> V_104 -> V_456 = & V_457 ;
V_134 = V_219 | V_220 ;
V_411 = F_18 ( V_115 , V_31 , & V_134 ,
sizeof( V_134 ) ) ;
V_81 = sizeof( V_134 ) ;
V_411 = F_9 ( V_115 , V_42 , & V_134 ,
& V_81 ) ;
V_5 -> V_227 = F_15 ( V_134 ) ;
if ( V_411 < 0 || V_5 -> V_227 < 0 )
V_5 -> V_227 = 0 ;
if ( V_5 -> V_227 > 0 )
V_115 -> V_104 -> V_200 |= V_458 ;
else
V_115 -> V_104 -> V_200 &= ~ V_458 ;
memcpy ( V_237 -> V_459 , V_115 -> V_104 -> V_460 , V_143 ) ;
V_237 -> V_461 = V_462 ;
V_237 -> V_463 = F_154 ( V_255 )
| F_154 ( V_254 ) ;
V_237 -> V_464 = 1 ;
F_137 ( V_115 , V_237 ) ;
memcpy ( V_5 -> V_465 , V_466 , sizeof( V_466 ) ) ;
memcpy ( V_5 -> V_467 , V_468 , sizeof( V_468 ) ) ;
V_5 -> V_469 . V_465 = V_5 -> V_465 ;
V_5 -> V_469 . V_470 = F_155 ( V_466 ) ;
V_5 -> V_469 . V_471 = V_5 -> V_467 ;
V_5 -> V_469 . V_472 = F_155 ( V_468 ) ;
V_237 -> V_473 [ V_474 ] = & V_5 -> V_469 ;
V_237 -> V_475 = V_476 ;
memcpy ( V_5 -> V_477 , V_478 ,
sizeof( V_478 ) ) ;
V_237 -> V_477 = V_5 -> V_477 ;
V_237 -> V_479 = F_155 ( V_478 ) ;
F_156 ( V_237 , & V_115 -> V_480 -> V_3 ) ;
if ( F_157 ( V_237 ) ) {
V_411 = - V_481 ;
goto V_455;
}
F_45 ( V_115 ) ;
V_5 -> V_342 = - 1 ;
F_71 ( V_237 ,
V_258 | V_259 ) ;
V_5 -> V_141 = false ;
F_35 ( V_115 , false ) ;
F_125 ( V_115 -> V_104 ) ;
return 0 ;
V_455:
F_158 ( & V_5 -> V_428 ) ;
F_158 ( & V_5 -> V_273 ) ;
F_159 ( & V_5 -> V_303 ) ;
F_160 ( V_5 -> V_272 ) ;
F_161 ( V_5 -> V_272 ) ;
F_162 ( V_237 ) ;
return V_411 ;
}
static void F_163 ( struct V_2 * V_115 , struct V_450 * V_451 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
F_35 ( V_115 , false ) ;
F_158 ( & V_5 -> V_428 ) ;
F_158 ( & V_5 -> V_273 ) ;
F_159 ( & V_5 -> V_303 ) ;
F_160 ( V_5 -> V_272 ) ;
F_161 ( V_5 -> V_272 ) ;
F_164 ( V_115 , V_451 ) ;
F_165 ( V_5 -> V_236 . V_237 ) ;
F_162 ( V_5 -> V_236 . V_237 ) ;
}
static int F_166 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_411 ;
F_14 ( V_115 -> V_104 , L_60 , V_105 ) ;
V_411 = F_19 ( V_115 ) ;
if ( V_411 )
F_28 ( V_115 -> V_104 , L_142 , V_411 ) ;
F_55 ( V_115 ) ;
F_78 ( V_5 -> V_272 , & V_5 -> V_428 ,
F_142 ( V_431 ) ) ;
return F_46 ( V_115 ) ;
}
static int F_167 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_411 ;
T_2 V_215 ;
F_14 ( V_115 -> V_104 , L_60 , V_105 ) ;
V_411 = F_35 ( V_115 , false ) ;
V_5 -> V_364 = 0 ;
F_158 ( & V_5 -> V_428 ) ;
F_158 ( & V_5 -> V_273 ) ;
F_159 ( & V_5 -> V_303 ) ;
F_160 ( V_5 -> V_272 ) ;
if ( V_5 -> V_268 ) {
F_90 ( V_5 -> V_268 , true ) ;
V_5 -> V_268 = NULL ;
}
V_215 = 0 ;
F_18 ( V_115 , V_31 , & V_215 ,
sizeof( V_215 ) ) ;
return V_411 ;
}
static int T_7 F_168 ( void )
{
return F_169 ( & V_482 ) ;
}
static void T_8 F_170 ( void )
{
F_171 ( & V_482 ) ;
}
