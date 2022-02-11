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
static bool F_3 ( struct V_1 * V_5 , T_2 V_11 )
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
static const char * F_6 ( T_3 V_28 )
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
static const char * F_6 ( T_3 V_28 )
{
return L_1 ;
}
static int F_8 ( T_3 V_69 )
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
static int F_9 ( struct V_2 * V_3 , T_3 V_28 , void * V_80 , int * V_81 )
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
static int F_18 ( struct V_2 * V_3 , T_3 V_28 , const void * V_80 ,
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
T_4 * V_127 ;
T_3 * V_128 ;
if ( V_119 == 0 )
V_123 = sizeof( T_3 ) ;
else if ( V_119 == 2 )
V_123 = strlen ( V_120 ) * sizeof( T_4 ) ;
else
return - V_71 ;
V_125 = strlen ( V_118 ) * sizeof( T_4 ) ;
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
V_118 , ( T_2 * ) V_120 ) ;
else
F_14 ( V_3 -> V_104 , L_8 ,
V_118 , * ( T_1 * ) V_120 ) ;
V_122 -> V_129 = F_12 ( sizeof( * V_122 ) ) ;
V_122 -> V_130 = F_12 ( V_125 ) ;
V_122 -> type = F_12 ( V_119 ) ;
V_122 -> V_131 = F_12 ( sizeof( * V_122 ) + V_125 ) ;
V_122 -> V_132 = F_12 ( V_123 ) ;
V_127 = ( void * ) V_122 + sizeof( * V_122 ) ;
for ( V_126 = 0 ; V_126 < V_125 / sizeof( T_4 ) ; V_126 ++ )
V_127 [ V_126 ] = F_22 ( V_118 [ V_126 ] ) ;
if ( V_119 == 2 ) {
V_127 = ( void * ) V_122 + sizeof( * V_122 ) + V_125 ;
for ( V_126 = 0 ; V_126 < V_123 / sizeof( T_4 ) ; V_126 ++ )
V_127 [ V_126 ] = F_22 ( ( ( T_2 * ) V_120 ) [ V_126 ] ) ;
} else {
V_128 = ( void * ) V_122 + sizeof( * V_122 ) + V_125 ;
* V_128 = F_12 ( * ( T_1 * ) V_120 ) ;
}
#ifdef F_21
F_14 ( V_3 -> V_104 , L_9 , V_124 ) ;
for ( V_126 = 0 ; V_126 < V_124 ; V_126 += 12 ) {
T_1 * V_133 = ( T_1 * ) ( ( T_2 * ) V_122 + V_126 ) ;
F_14 ( V_3 -> V_104 , L_10 ,
F_23 ( V_133 [ 0 ] ) ,
F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) ) ;
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
static int F_25 ( int V_134 )
{
int V_135 = 100 * ( V_134 - V_136 ) / ( V_137 - V_136 ) ;
return V_135 >= 0 ? ( V_135 <= 100 ? V_135 : 100 ) : 0 ;
}
static int F_26 ( struct V_2 * V_115 )
{
T_3 V_133 ;
V_133 = F_12 ( 1 ) ;
return F_18 ( V_115 , V_51 , & V_133 ,
sizeof( V_133 ) ) ;
}
static int F_27 ( struct V_2 * V_115 , struct V_138 * V_139 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_70 ;
V_70 = F_18 ( V_115 , V_44 , V_139 , sizeof( * V_139 ) ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_12 , V_70 ) ;
return V_70 ;
}
if ( V_70 == 0 ) {
V_5 -> V_140 = true ;
F_14 ( V_115 -> V_104 , L_13 , V_105 ) ;
}
return V_70 ;
}
static int F_29 ( struct V_2 * V_115 , const T_2 * V_141 )
{
int V_70 ;
V_70 = F_18 ( V_115 , V_43 , V_141 , V_142 ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_14 ,
V_141 , V_70 ) ;
return V_70 ;
}
return V_70 ;
}
static int F_30 ( struct V_2 * V_115 )
{
static const T_2 V_143 [ V_142 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
return F_29 ( V_115 , V_143 ) ;
}
static int F_31 ( struct V_2 * V_115 , T_2 V_141 [ V_142 ] )
{
int V_70 , V_81 ;
V_81 = V_142 ;
V_70 = F_9 ( V_115 , V_43 , V_141 , & V_81 ) ;
if ( V_70 != 0 )
memset ( V_141 , 0 , V_142 ) ;
return V_70 ;
}
static int F_32 ( struct V_2 * V_115 ,
struct V_144 * V_145 , int V_81 )
{
return F_9 ( V_115 , V_55 ,
V_145 , & V_81 ) ;
}
static bool F_33 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
T_2 V_141 [ V_142 ] ;
int V_70 ;
if ( ! V_5 -> V_140 )
return false ;
V_70 = F_31 ( V_115 , V_141 ) ;
return ( V_70 == 0 && ! F_34 ( V_141 ) ) ;
}
static int F_35 ( struct V_2 * V_115 , bool V_146 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_138 V_139 ;
int V_126 , V_70 = 0 ;
if ( V_5 -> V_140 ) {
V_70 = F_18 ( V_115 , V_48 , NULL , 0 ) ;
if ( V_70 == 0 ) {
V_5 -> V_140 = false ;
F_14 ( V_115 -> V_104 , L_15 ,
V_105 ) ;
if ( V_146 )
F_36 ( 100 ) ;
}
}
if ( V_146 ) {
F_37 ( V_115 , V_147 ) ;
V_139 . V_148 = F_12 ( sizeof( V_139 . V_149 ) ) ;
F_38 ( & V_139 . V_149 [ 2 ] , sizeof( V_139 . V_149 ) - 2 ) ;
V_139 . V_149 [ 0 ] = 0x1 ;
V_139 . V_149 [ 1 ] = 0xff ;
for ( V_126 = 2 ; V_126 < sizeof( V_139 . V_149 ) ; V_126 ++ )
V_139 . V_149 [ V_126 ] = 0x1 + ( V_139 . V_149 [ V_126 ] * 0xfe / 0xff ) ;
V_70 = F_27 ( V_115 , & V_139 ) ;
}
return V_70 ;
}
static int F_39 ( struct V_2 * V_115 , T_1 V_150 ,
enum V_151 V_152 , int V_153 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
T_3 V_133 ;
int V_154 , V_70 ;
F_14 ( V_115 -> V_104 , L_16 ,
V_105 , V_150 , V_152 , V_153 ) ;
if ( V_150 & V_155 ) {
if ( V_153 & V_25 )
V_154 = V_156 ;
else
V_154 = V_157 ;
} else if ( V_150 & V_158 ) {
if ( V_153 & V_25 )
V_154 = V_159 ;
else if ( V_153 & V_27 )
V_154 = V_160 ;
else
V_154 = V_161 ;
} else if ( V_152 == V_162 )
V_154 = V_163 ;
else if ( V_152 == V_164 )
V_154 = V_165 ;
else if ( V_152 == V_166 )
V_154 = V_167 ;
else
return - V_168 ;
V_133 = F_12 ( V_154 ) ;
V_70 = F_18 ( V_115 , V_49 , & V_133 ,
sizeof( V_133 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_17 ,
V_70 ) ;
return V_70 ;
}
V_5 -> V_150 = V_150 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
T_3 V_133 ;
F_14 ( V_115 -> V_104 , L_18 ,
V_105 , V_5 -> V_150 ) ;
if ( V_5 -> V_150 & V_155 ||
V_5 -> V_150 & V_158 )
V_133 = F_12 ( V_169 ) ;
else
V_133 = F_12 ( V_170 ) ;
return F_18 ( V_115 , V_50 , & V_133 ,
sizeof( V_133 ) ) ;
}
static int F_41 ( struct V_2 * V_115 , int V_171 , int V_172 )
{
T_3 V_133 ;
int V_173 , V_70 ;
F_14 ( V_115 -> V_104 , L_19 ,
V_105 , V_171 , V_172 ) ;
if ( V_171 & V_21 )
V_173 = V_174 ;
else if ( V_171 & V_20 )
V_173 = V_175 ;
else if ( V_171 & V_19 )
V_173 = V_176 ;
else if ( V_172 & V_21 )
V_173 = V_174 ;
else if ( V_172 & V_20 )
V_173 = V_175 ;
else
V_173 = V_177 ;
V_133 = F_12 ( V_173 ) ;
V_70 = F_18 ( V_115 , V_52 , & V_133 ,
sizeof( V_133 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_20 ,
V_70 ) ;
return V_70 ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_115 , int V_178 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
T_3 V_133 ;
int V_70 ;
F_14 ( V_115 -> V_104 , L_21 ,
V_105 , V_5 -> V_179 ) ;
V_133 = F_12 ( V_178 ) ;
V_70 = F_18 ( V_115 , V_45 , & V_133 ,
sizeof( V_133 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_22 ,
V_70 ) ;
return V_70 ;
}
F_42 ( V_115 ) ;
V_5 -> V_179 = V_178 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_115 , T_1 V_180 )
{
T_3 V_133 ;
F_14 ( V_115 -> V_104 , L_23 , V_105 , V_180 ) ;
if ( V_180 < 0 || V_180 > 2347 )
V_180 = 2347 ;
V_133 = F_12 ( V_180 ) ;
return F_18 ( V_115 , V_64 , & V_133 ,
sizeof( V_133 ) ) ;
}
static int F_44 ( struct V_2 * V_115 , T_1 V_181 )
{
T_3 V_133 ;
F_14 ( V_115 -> V_104 , L_23 , V_105 , V_181 ) ;
if ( V_181 < 256 || V_181 > 2346 )
V_181 = 2346 ;
V_133 = F_12 ( V_181 ) ;
return F_18 ( V_115 , V_63 , & V_133 ,
sizeof( V_133 ) ) ;
}
static void F_45 ( struct V_2 * V_115 )
{
F_37 ( V_115 , V_147 ) ;
F_39 ( V_115 , 0 , V_164 ,
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
static int F_47 ( struct V_2 * V_115 , int V_182 )
{
struct V_183 V_184 ;
unsigned int V_185 ;
int V_81 , V_70 ;
F_14 ( V_115 -> V_104 , L_24 , V_105 , V_182 ) ;
if ( F_33 ( V_115 ) )
return 0 ;
V_185 = F_48 ( V_182 ) * 1000 ;
V_81 = sizeof( V_184 ) ;
V_70 = F_9 ( V_115 , V_66 , & V_184 , & V_81 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_25 ,
V_105 ) ;
return V_70 ;
}
V_184 . V_186 = F_12 ( V_185 ) ;
V_70 = F_18 ( V_115 , V_66 , & V_184 ,
sizeof( V_184 ) ) ;
F_14 ( V_115 -> V_104 , L_26 , V_105 , V_182 , V_70 ) ;
return V_70 ;
}
static struct V_187 * F_49 ( struct V_2 * V_115 ,
T_1 * V_188 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_187 * V_182 ;
struct V_183 V_184 ;
int V_81 , V_70 ;
V_81 = sizeof( V_184 ) ;
V_70 = F_9 ( V_115 , V_66 , & V_184 , & V_81 ) ;
F_14 ( V_115 -> V_104 , L_27 ,
V_105 , V_70 ) ;
if ( V_70 < 0 )
return NULL ;
V_182 = F_50 ( V_5 -> V_189 . V_190 ,
F_51 ( F_15 ( V_184 . V_186 ) ) ) ;
if ( ! V_182 )
return NULL ;
if ( V_188 )
* V_188 = F_15 ( V_184 . V_188 ) ;
return V_182 ;
}
static int F_52 ( struct V_2 * V_115 , const T_2 * V_191 , int V_192 ,
T_2 V_193 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_194 V_195 ;
T_1 V_12 ;
int V_70 ;
F_14 ( V_115 -> V_104 , L_28 ,
V_105 , V_193 , V_192 ) ;
if ( V_193 >= V_196 )
return - V_71 ;
if ( V_192 == 5 )
V_12 = V_17 ;
else if ( V_192 == 13 )
V_12 = V_18 ;
else
return - V_71 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_197 = F_12 ( sizeof( V_195 ) ) ;
V_195 . V_148 = F_12 ( V_192 ) ;
V_195 . V_193 = F_12 ( V_193 ) ;
memcpy ( & V_195 . V_198 , V_191 , V_192 ) ;
if ( V_193 == V_5 -> V_199 ) {
V_195 . V_193 |= V_200 ;
V_70 = F_41 ( V_115 , V_19 ,
V_16 ) ;
if ( V_70 )
F_28 ( V_115 -> V_104 , L_29 ,
V_70 ) ;
}
V_70 = F_18 ( V_115 , V_46 , & V_195 ,
sizeof( V_195 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_30 ,
V_193 + 1 , V_70 ) ;
return V_70 ;
}
V_5 -> V_13 [ V_193 ] . V_81 = V_192 ;
V_5 -> V_13 [ V_193 ] . V_12 = V_12 ;
memcpy ( & V_5 -> V_13 [ V_193 ] . V_198 , V_191 , V_192 ) ;
memset ( & V_5 -> V_13 [ V_193 ] . V_141 , 0xff , V_142 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_115 , const T_2 * V_191 , int V_192 ,
T_2 V_193 , const T_2 * V_201 , const T_2 * V_202 ,
int V_203 , T_1 V_12 , T_3 V_204 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_205 V_195 ;
bool V_206 ;
int V_70 ;
if ( V_193 >= V_196 ) {
F_14 ( V_115 -> V_104 , L_31 ,
V_105 , V_193 ) ;
return - V_71 ;
}
if ( V_192 > sizeof( V_195 . V_198 ) || V_192 < 0 ) {
F_14 ( V_115 -> V_104 , L_32 ,
V_105 , V_192 ) ;
return - V_71 ;
}
if ( V_204 & V_207 ) {
if ( ! V_202 || V_203 <= 0 ) {
F_14 ( V_115 -> V_104 , L_33 ,
V_105 ) ;
return - V_71 ;
}
if ( V_202 && V_203 > sizeof( V_195 . V_208 ) ) {
F_14 ( V_115 -> V_104 , L_34 , V_105 ) ;
return - V_71 ;
}
}
V_206 = V_201 && ! F_34 ( V_201 ) &&
! F_54 ( V_201 ) ;
if ( ( V_204 & V_209 ) && ! V_206 ) {
F_14 ( V_115 -> V_104 , L_35 ,
V_105 , V_201 ) ;
return - V_71 ;
}
F_14 ( V_115 -> V_104 , L_36 ,
V_105 , V_193 ,
! ! ( V_204 & V_210 ) ,
! ! ( V_204 & V_209 ) ,
! ! ( V_204 & V_207 ) ) ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_197 = F_12 ( sizeof( V_195 ) -
sizeof( V_195 . V_198 ) + V_192 ) ;
V_195 . V_148 = F_12 ( V_192 ) ;
V_195 . V_193 = F_12 ( V_193 ) | V_204 ;
if ( V_12 == V_15 && V_192 == 32 ) {
memcpy ( V_195 . V_198 , V_191 , 16 ) ;
memcpy ( V_195 . V_198 + 16 , V_191 + 24 , 8 ) ;
memcpy ( V_195 . V_198 + 24 , V_191 + 16 , 8 ) ;
} else
memcpy ( V_195 . V_198 , V_191 , V_192 ) ;
if ( V_204 & V_207 )
memcpy ( V_195 . V_208 , V_202 , V_203 ) ;
if ( V_204 & V_209 ) {
memcpy ( V_195 . V_141 , V_201 , V_142 ) ;
} else {
if ( V_5 -> V_179 == V_211 )
memset ( V_195 . V_141 , 0xff , V_142 ) ;
else
F_31 ( V_115 , V_195 . V_141 ) ;
}
V_70 = F_18 ( V_115 , V_53 , & V_195 ,
F_15 ( V_195 . V_197 ) ) ;
F_14 ( V_115 -> V_104 , L_37 ,
V_105 , V_70 ) ;
if ( V_70 != 0 )
return V_70 ;
memset ( & V_5 -> V_13 [ V_193 ] , 0 , sizeof( V_5 -> V_13 [ V_193 ] ) ) ;
V_5 -> V_13 [ V_193 ] . V_81 = V_192 ;
V_5 -> V_13 [ V_193 ] . V_12 = V_12 ;
memcpy ( & V_5 -> V_13 [ V_193 ] . V_198 , V_191 , V_192 ) ;
if ( V_204 & V_209 )
memcpy ( & V_5 -> V_13 [ V_193 ] . V_141 , V_195 . V_141 , V_142 ) ;
else
memset ( & V_5 -> V_13 [ V_193 ] . V_141 , 0xff , V_142 ) ;
if ( V_204 & V_210 )
V_5 -> V_199 = V_193 ;
return 0 ;
}
static int F_55 ( struct V_2 * V_115 , T_2 V_212 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_213 V_191 ;
if ( F_3 ( V_5 , V_212 ) )
return 0 ;
V_191 = V_5 -> V_13 [ V_212 ] ;
F_14 ( V_115 -> V_104 , L_38 , V_105 , V_212 , V_191 . V_81 ) ;
if ( V_191 . V_81 == 0 )
return 0 ;
return F_52 ( V_115 , V_191 . V_198 , V_191 . V_81 , V_212 ) ;
}
static void F_42 ( struct V_2 * V_115 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < 4 ; V_126 ++ )
F_55 ( V_115 , V_126 ) ;
}
static void F_56 ( struct V_1 * V_5 , T_2 V_11 )
{
memset ( & V_5 -> V_13 [ V_11 ] , 0 , sizeof( V_5 -> V_13 [ V_11 ] ) ) ;
}
static int F_57 ( struct V_2 * V_115 , T_2 V_193 , const T_2 * V_141 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_214 F_57 ;
T_3 V_215 ;
bool V_216 ;
int V_70 ;
if ( V_193 >= V_196 )
return - V_217 ;
if ( V_5 -> V_13 [ V_193 ] . V_81 == 0 )
return 0 ;
V_216 = F_3 ( V_5 , V_193 ) ;
F_14 ( V_115 -> V_104 , L_39 ,
V_105 , V_193 , V_216 ? L_40 : L_41 ,
V_5 -> V_13 [ V_193 ] . V_81 ) ;
F_56 ( V_5 , V_193 ) ;
if ( V_216 ) {
F_57 . V_197 = F_12 ( sizeof( F_57 ) ) ;
F_57 . V_193 = F_12 ( V_193 ) ;
if ( V_141 ) {
if ( ! F_54 ( V_141 ) )
F_57 . V_193 |=
V_209 ;
memcpy ( F_57 . V_141 , V_141 ,
sizeof( F_57 . V_141 ) ) ;
} else
memset ( F_57 . V_141 , 0xff ,
sizeof( F_57 . V_141 ) ) ;
V_70 = F_18 ( V_115 , V_54 , & F_57 ,
sizeof( F_57 ) ) ;
if ( V_70 != 0 )
return V_70 ;
} else {
V_215 = F_12 ( V_193 ) ;
V_70 = F_18 ( V_115 , V_47 , & V_215 ,
sizeof( V_215 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 ,
L_42 ,
V_193 , V_70 ) ;
return V_70 ;
}
}
if ( V_193 == V_5 -> V_199 )
F_41 ( V_115 , V_16 , V_16 ) ;
return 0 ;
}
static void F_58 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_218 * V_219 ;
T_3 V_220 , V_221 ;
int V_70 ;
char * V_222 = NULL ;
int V_223 ;
V_221 = V_220 = V_224 |
V_225 ;
if ( V_115 -> V_104 -> V_204 & V_226 ) {
V_220 |= V_227 |
V_228 ;
} else if ( V_115 -> V_104 -> V_204 & V_229 ) {
V_220 |= V_230 ;
}
if ( V_220 != V_221 )
goto V_231;
F_59 ( V_115 -> V_104 ) ;
V_223 = F_60 ( V_115 -> V_104 ) ;
if ( V_223 > V_5 -> V_232 ) {
V_220 |= V_230 ;
} else if ( V_223 ) {
int V_126 = 0 ;
V_222 = F_10 ( V_223 * V_142 , V_233 ) ;
if ( ! V_222 ) {
F_28 ( V_115 -> V_104 ,
L_43 ,
V_223 * V_142 ) ;
F_61 ( V_115 -> V_104 ) ;
return;
}
F_62 (ha, usbdev->net)
memcpy ( V_222 + V_126 ++ * V_142 ,
V_219 -> V_201 , V_142 ) ;
}
F_61 ( V_115 -> V_104 ) ;
if ( V_220 != V_221 )
goto V_231;
if ( V_223 ) {
V_70 = F_18 ( V_115 , V_41 , V_222 ,
V_223 * V_142 ) ;
F_17 ( V_222 ) ;
if ( V_70 == 0 )
V_220 |= V_234 ;
else
V_220 |= V_230 ;
F_14 ( V_115 -> V_104 , L_44 ,
V_223 , V_5 -> V_232 , V_70 ) ;
}
V_231:
V_70 = F_18 ( V_115 , V_31 , & V_220 ,
sizeof( V_220 ) ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_45 ,
F_15 ( V_220 ) ) ;
}
F_14 ( V_115 -> V_104 , L_46 ,
F_15 ( V_220 ) , V_70 ) ;
}
static void F_63 ( struct V_2 * V_115 ,
struct V_235 * V_236 ,
const char * V_237 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_126 , V_81 , V_238 , V_239 , V_240 ;
V_239 = V_5 -> V_189 . V_190 -> V_241 ;
V_81 = F_15 ( V_236 -> V_148 ) ;
V_238 = F_15 ( V_236 -> V_242 ) ;
V_240 = ( V_238 > 0 ) ? ( V_81 - sizeof( * V_236 ) ) / V_238 : - 1 ;
F_14 ( V_115 -> V_104 , L_47
L_48 , V_237 , V_238 , V_81 , V_240 ) ;
if ( V_238 > V_239 )
V_238 = V_239 ;
for ( V_126 = 0 ; V_126 < V_238 ; V_126 ++ ) {
T_1 * V_133 = ( T_1 * ) V_236 -> V_243 [ V_126 ] . V_244 ;
F_14 ( V_115 -> V_104 , L_49
L_50 ,
V_237 , V_236 -> V_243 [ V_126 ] . V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
}
}
static void F_63 ( struct V_2 * V_115 ,
struct V_235 * V_236 ,
const char * V_237 )
{
return;
}
static struct V_235 * F_64 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_235 * V_236 ;
int V_81 , V_70 , V_239 ;
V_239 = V_5 -> V_189 . V_190 -> V_241 ;
V_81 = sizeof( * V_236 ) + V_239 * sizeof( V_236 -> V_243 [ 0 ] ) ;
V_236 = F_65 ( V_81 , V_96 ) ;
if ( ! V_236 )
return F_66 ( - V_97 ) ;
V_236 -> V_148 = F_12 ( V_81 ) ;
V_236 -> V_242 = F_12 ( V_239 ) ;
V_70 = F_9 ( V_115 , V_57 , V_236 , & V_81 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_51
L_52 , V_105 , V_81 , V_239 , V_70 ) ;
F_17 ( V_236 ) ;
return F_66 ( V_70 ) ;
}
if ( F_15 ( V_236 -> V_242 ) > V_239 )
V_236 -> V_242 = F_12 ( V_239 ) ;
F_63 ( V_115 , V_236 , V_105 ) ;
return V_236 ;
}
static int F_67 ( struct V_2 * V_115 ,
struct V_235 * V_236 )
{
int V_70 , V_81 , V_245 ;
V_245 = F_15 ( V_236 -> V_242 ) ;
V_81 = sizeof( * V_236 ) + V_245 * sizeof( V_236 -> V_243 [ 0 ] ) ;
V_236 -> V_148 = F_12 ( V_81 ) ;
F_63 ( V_115 , V_236 , V_105 ) ;
V_70 = F_18 ( V_115 , V_57 , V_236 ,
F_15 ( V_236 -> V_148 ) ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_53
L_54 , V_105 , V_81 , V_245 , V_70 ) ;
}
F_17 ( V_236 ) ;
return V_70 ;
}
static struct V_235 * F_68 ( struct V_2 * V_115 ,
struct V_235 * V_236 ,
struct V_246 * V_247 ,
int V_239 )
{
int V_126 , V_248 , V_249 ;
unsigned int V_238 ;
V_238 = F_15 ( V_236 -> V_242 ) ;
if ( V_238 > V_239 )
V_238 = V_239 ;
for ( V_126 = 0 ; V_126 < V_238 ; V_126 ++ )
if ( ! F_69 ( V_236 -> V_243 [ V_126 ] . V_141 ,
V_247 -> V_141 ) )
break;
if ( V_126 == V_238 ) {
F_14 ( V_115 -> V_104 , L_55 ,
V_105 , V_247 -> V_141 ) ;
V_249 = - V_217 ;
goto error;
}
for (; V_126 + 1 < V_238 ; V_126 ++ )
V_236 -> V_243 [ V_126 ] = V_236 -> V_243 [ V_126 + 1 ] ;
V_238 -- ;
V_248 = sizeof( * V_236 ) + V_238 * sizeof( V_236 -> V_243 [ 0 ] ) ;
V_236 -> V_148 = F_12 ( V_248 ) ;
V_236 -> V_242 = F_12 ( V_238 ) ;
return V_236 ;
error:
F_17 ( V_236 ) ;
return F_66 ( V_249 ) ;
}
static struct V_235 * F_70 ( struct V_2 * V_115 ,
struct V_235 * V_236 ,
struct V_246 * V_247 ,
int V_239 )
{
int V_126 , V_249 , V_248 ;
unsigned int V_238 ;
V_238 = F_15 ( V_236 -> V_242 ) ;
if ( V_238 > V_239 )
V_238 = V_239 ;
for ( V_126 = 0 ; V_126 < V_238 ; V_126 ++ ) {
if ( F_69 ( V_236 -> V_243 [ V_126 ] . V_141 ,
V_247 -> V_141 ) )
continue;
memcpy ( V_236 -> V_243 [ V_126 ] . V_244 , V_247 -> V_244 ,
V_250 ) ;
return V_236 ;
}
if ( V_126 == V_239 ) {
F_14 ( V_115 -> V_104 , L_56 , V_105 ) ;
V_249 = - V_251 ;
goto error;
}
V_248 = sizeof( * V_236 ) + ( V_238 + 1 ) * sizeof( V_236 -> V_243 [ 0 ] ) ;
V_236 = F_71 ( V_236 , V_248 , V_96 ) ;
if ( ! V_236 ) {
V_249 = - V_97 ;
goto error;
}
V_236 -> V_148 = F_12 ( V_248 ) ;
V_236 -> V_242 = F_12 ( V_238 + 1 ) ;
memcpy ( V_236 -> V_243 [ V_238 ] . V_141 , V_247 -> V_141 , V_142 ) ;
memcpy ( V_236 -> V_243 [ V_238 ] . V_244 , V_247 -> V_244 , V_250 ) ;
return V_236 ;
error:
F_17 ( V_236 ) ;
return F_66 ( V_249 ) ;
}
static int F_72 ( struct V_190 * V_190 ,
struct V_252 * V_3 ,
enum V_253 type , T_1 * V_204 ,
struct V_254 * V_255 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_178 ;
switch ( type ) {
case V_256 :
V_178 = V_211 ;
break;
case V_257 :
V_178 = V_147 ;
break;
default:
return - V_71 ;
}
V_5 -> V_189 . V_258 = type ;
return F_37 ( V_115 , V_178 ) ;
}
static int F_74 ( struct V_190 * V_190 , T_1 V_259 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_249 ;
if ( V_259 & V_260 ) {
V_249 = F_44 ( V_115 , V_190 -> V_181 ) ;
if ( V_249 < 0 )
return V_249 ;
}
if ( V_259 & V_261 ) {
V_249 = F_43 ( V_115 , V_190 -> V_180 ) ;
if ( V_249 < 0 )
return V_249 ;
}
return 0 ;
}
static int F_75 ( struct V_190 * V_190 ,
enum V_262 type ,
int V_263 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_57 ,
V_105 , type , V_263 ) ;
if ( V_263 < 0 || ( V_263 % 100 ) )
return - V_168 ;
if ( type == V_264 ||
F_76 ( V_263 ) == F_2 ( V_5 ) ) {
if ( ! V_5 -> V_140 )
F_35 ( V_115 , true ) ;
return 0 ;
}
return - V_168 ;
}
static int F_77 ( struct V_190 * V_190 , int * V_265 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
* V_265 = F_2 ( V_5 ) ;
F_14 ( V_115 -> V_104 , L_58 , V_105 , * V_265 ) ;
return 0 ;
}
static int F_78 ( struct V_190 * V_190 , struct V_252 * V_3 ,
struct V_266 * V_267 )
{
struct V_2 * V_115 = F_79 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_70 ;
int V_268 = V_269 ;
F_14 ( V_115 -> V_104 , L_59 ) ;
F_80 ( V_115 , NULL , NULL ) ;
if ( ! V_267 )
return - V_71 ;
if ( V_5 -> V_270 && V_5 -> V_270 != V_267 )
return - V_79 ;
V_5 -> V_270 = V_267 ;
V_70 = F_26 ( V_115 ) ;
if ( V_70 == 0 ) {
if ( V_5 -> V_271 == V_272 )
V_268 = V_273 ;
F_81 ( V_5 -> V_274 , & V_5 -> V_275 , V_268 ) ;
}
return V_70 ;
}
static bool F_82 ( struct V_2 * V_115 ,
struct V_276 * V_141 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_187 * V_182 ;
struct V_277 * V_278 ;
T_5 signal ;
T_6 V_279 ;
T_7 V_280 ;
T_7 V_281 ;
struct V_282 * V_283 ;
int V_284 , V_285 ;
T_2 * V_286 ;
F_14 ( V_115 -> V_104 , L_60 ,
V_141 -> V_139 . V_149 , V_141 -> V_287 , F_15 ( V_141 -> V_148 ) ) ;
V_285 = F_15 ( V_141 -> V_148 ) ;
if ( V_285 < sizeof( struct V_276 ) +
sizeof( struct V_282 ) )
return NULL ;
V_283 = (struct V_282 * ) V_141 -> V_288 ;
V_286 = ( void * ) ( V_141 -> V_288 + sizeof( struct V_282 ) ) ;
V_284 = F_83 ( V_285 - ( int ) sizeof( * V_141 ) ,
( int ) F_15 ( V_141 -> V_289 ) ) ;
V_284 -= sizeof( struct V_282 ) ;
if ( V_284 < 0 )
return NULL ;
V_182 = F_50 ( V_5 -> V_189 . V_190 ,
F_51 ( F_15 ( V_141 -> V_184 . V_186 ) ) ) ;
if ( ! V_182 )
return NULL ;
signal = F_25 ( F_15 ( V_141 -> V_290 ) ) ;
V_279 = F_84 ( * ( V_291 * ) V_283 -> V_279 ) ;
V_280 = F_85 ( V_283 -> V_292 ) ;
V_281 = F_85 ( V_283 -> V_281 ) ;
V_278 = F_86 ( V_5 -> V_189 . V_190 , V_182 , V_141 -> V_287 ,
V_279 , V_280 , V_281 , V_286 , V_284 , signal ,
V_96 ) ;
F_87 ( V_278 ) ;
return ( V_278 != NULL ) ;
}
static struct V_276 * F_88 (
struct V_276 * V_141 ,
int * V_285 , void * V_82 , int V_81 )
{
void * V_293 , * V_294 ;
V_293 = ( char * ) V_82 + V_81 ;
V_294 = ( char * ) V_141 + * V_285 ;
if ( ( int ) ( V_293 - V_294 ) < sizeof( V_141 -> V_148 ) ) {
* V_285 = 0 ;
return NULL ;
} else {
V_141 = ( void * ) ( ( char * ) V_141 + * V_285 ) ;
* V_285 = F_15 ( V_141 -> V_148 ) ;
return V_141 ;
}
}
static bool F_89 ( struct V_276 * V_141 ,
int V_285 , void * V_82 , int V_81 )
{
void * V_293 , * V_294 ;
if ( ! V_141 || V_285 <= 0 || V_285 > V_81 )
return false ;
V_293 = ( char * ) V_82 + V_81 ;
V_294 = ( char * ) V_141 + V_285 ;
return ( int ) ( V_293 - V_294 ) >= 0 && ( int ) ( V_294 - V_82 ) >= 0 ;
}
static int F_80 ( struct V_2 * V_115 , T_2 * V_295 ,
bool * V_296 )
{
void * V_82 = NULL ;
struct V_297 * V_298 ;
struct V_276 * V_141 ;
int V_70 = - V_71 , V_81 , V_238 , V_285 , V_299 , V_300 ;
F_14 ( V_115 -> V_104 , L_61 , V_105 ) ;
V_81 = V_94 ;
V_301:
V_82 = F_65 ( V_81 , V_96 ) ;
if ( ! V_82 ) {
V_70 = - V_97 ;
goto V_302;
}
V_300 = V_81 ;
V_70 = F_9 ( V_115 , V_68 , V_82 , & V_300 ) ;
if ( V_70 != 0 || V_300 < sizeof( struct V_297 ) )
goto V_302;
if ( V_300 > V_81 ) {
V_81 = V_300 ;
F_17 ( V_82 ) ;
goto V_301;
}
V_81 = V_300 ;
V_298 = V_82 ;
V_238 = F_15 ( V_298 -> V_303 ) ;
V_299 = 0 ;
F_14 ( V_115 -> V_104 , L_62 , V_105 , V_81 ) ;
V_285 = 0 ;
V_141 = F_88 ( V_298 -> V_141 , & V_285 , V_82 , V_81 ) ;
while ( F_89 ( V_141 , V_285 , V_82 , V_81 ) ) {
if ( F_82 ( V_115 , V_141 ) && V_295 &&
V_296 ) {
if ( F_69 ( V_141 -> V_287 , V_295 ) )
* V_296 = true ;
}
V_299 ++ ;
V_141 = F_88 ( V_141 , & V_285 , V_82 , V_81 ) ;
}
F_14 ( V_115 -> V_104 , L_63
L_64 , V_105 , V_238 , V_299 ) ;
V_302:
F_17 ( V_82 ) ;
return V_70 ;
}
static void F_90 ( struct V_304 * V_305 )
{
struct V_1 * V_5 =
F_91 ( V_305 , struct V_1 , V_275 . V_305 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_70 ;
F_14 ( V_115 -> V_104 , L_65 ) ;
if ( ! V_5 -> V_270 )
return;
V_70 = F_80 ( V_115 , NULL , NULL ) ;
F_92 ( V_5 -> V_270 , V_70 < 0 ) ;
V_5 -> V_270 = NULL ;
}
static int F_93 ( struct V_190 * V_190 , struct V_252 * V_3 ,
struct V_306 * V_307 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_187 * V_182 = V_307 -> V_182 ;
struct V_138 V_139 ;
int V_171 = V_16 ;
int V_172 = V_16 ;
int V_153 = V_23 ;
int V_148 , V_126 , V_70 , V_308 = - 1 ;
if ( V_182 )
V_308 = F_94 ( V_182 -> V_309 ) ;
V_172 = F_4 ( V_307 -> V_310 . V_311 ) ;
for ( V_126 = 0 ; V_126 < V_307 -> V_310 . V_312 ; V_126 ++ )
V_171 |=
F_4 ( V_307 -> V_310 . V_313 [ V_126 ] ) ;
if ( V_307 -> V_310 . V_312 > 0 &&
V_171 == V_16 ) {
F_95 ( V_115 -> V_104 , L_66 ) ;
return - V_168 ;
}
for ( V_126 = 0 ; V_126 < V_307 -> V_310 . V_314 ; V_126 ++ )
V_153 |=
F_5 ( V_307 -> V_310 . V_315 [ V_126 ] ) ;
if ( V_307 -> V_310 . V_314 > 0 &&
V_153 == V_23 ) {
F_95 ( V_115 -> V_104 , L_67 ) ;
return - V_168 ;
}
F_14 ( V_115 -> V_104 , L_68 ,
V_307 -> V_139 , V_307 -> V_141 , V_308 ,
V_307 -> V_316 , V_307 -> V_310 . V_317 , V_307 -> V_152 ,
V_172 , V_171 , V_153 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_147 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_69 ,
V_70 ) ;
goto V_318;
}
V_70 = F_39 ( V_115 , V_307 -> V_310 . V_317 , V_307 -> V_152 ,
V_153 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_70 ,
V_70 ) ;
goto V_318;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_171 , V_172 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_71 ,
V_70 ) ;
goto V_318;
}
if ( V_182 ) {
V_70 = F_47 ( V_115 , V_308 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_72 ,
V_70 ) ;
goto V_318;
}
}
if ( V_307 -> V_191 && ( ( V_172 | V_171 ) & V_19 ) ) {
V_5 -> V_199 = V_307 -> V_212 ;
V_70 = F_52 ( V_115 , V_307 -> V_191 , V_307 -> V_192 , V_307 -> V_212 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_73 ,
V_70 , V_307 -> V_192 , V_307 -> V_212 ) ;
goto V_318;
}
}
if ( V_307 -> V_141 && ! F_34 ( V_307 -> V_141 ) &&
! F_54 ( V_307 -> V_141 ) ) {
V_70 = F_29 ( V_115 , V_307 -> V_141 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_74 ,
V_70 ) ;
goto V_318;
}
} else
F_30 ( V_115 ) ;
V_148 = V_307 -> V_319 ;
if ( V_148 > V_320 )
V_148 = V_320 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_148 = F_12 ( V_148 ) ;
memcpy ( V_139 . V_149 , V_307 -> V_139 , V_148 ) ;
F_96 ( V_115 ) ;
F_97 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_139 ) ;
if ( V_70 < 0 )
F_14 ( V_115 -> V_104 , L_75 , V_70 ) ;
return V_70 ;
V_318:
F_35 ( V_115 , true ) ;
return V_70 ;
}
static int F_98 ( struct V_190 * V_190 , struct V_252 * V_3 ,
T_7 V_321 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_76 , V_321 ) ;
V_5 -> V_322 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
return F_46 ( V_115 ) ;
}
static int F_99 ( struct V_190 * V_190 , struct V_252 * V_3 ,
struct V_323 * V_255 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_187 * V_182 = V_255 -> V_182 ;
struct V_138 V_139 ;
enum V_151 V_152 ;
int V_70 , V_324 , V_148 , V_308 = - 1 ;
if ( V_182 )
V_308 = F_94 ( V_182 -> V_309 ) ;
if ( V_255 -> V_316 ) {
V_152 = V_162 ;
V_324 = V_19 ;
} else {
V_152 = V_164 ;
V_324 = V_16 ;
}
F_14 ( V_115 -> V_104 , L_77 ,
V_255 -> V_139 , V_255 -> V_141 , V_308 , V_255 -> V_316 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_211 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_78 ,
V_70 ) ;
goto V_318;
}
V_70 = F_39 ( V_115 , 0 , V_152 , V_23 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_79 ,
V_70 ) ;
goto V_318;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_324 , V_16 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_80 ,
V_70 ) ;
goto V_318;
}
if ( V_182 ) {
V_70 = F_47 ( V_115 , V_308 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_81 ,
V_70 ) ;
goto V_318;
}
}
if ( V_255 -> V_141 && ! F_34 ( V_255 -> V_141 ) &&
! F_54 ( V_255 -> V_141 ) ) {
V_70 = F_29 ( V_115 , V_255 -> V_141 ) ;
if ( V_70 < 0 ) {
F_14 ( V_115 -> V_104 , L_82 ,
V_70 ) ;
goto V_318;
}
} else
F_30 ( V_115 ) ;
V_148 = V_255 -> V_319 ;
if ( V_148 > V_320 )
V_148 = V_320 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_148 = F_12 ( V_148 ) ;
memcpy ( V_139 . V_149 , V_255 -> V_139 , V_148 ) ;
F_97 ( V_115 ) ;
F_100 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_139 ) ;
if ( V_70 < 0 )
F_14 ( V_115 -> V_104 , L_83 ,
V_70 ) ;
return V_70 ;
V_318:
F_35 ( V_115 , true ) ;
return V_70 ;
}
static int F_101 ( struct V_190 * V_190 , struct V_252 * V_3 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_84 ) ;
V_5 -> V_322 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
return F_46 ( V_115 ) ;
}
static int F_102 ( struct V_190 * V_190 , struct V_252 * V_325 ,
struct V_187 * V_308 , enum V_326 V_327 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
return F_47 ( V_115 ,
F_94 ( V_308 -> V_309 ) ) ;
}
static int F_103 ( struct V_190 * V_190 , struct V_252 * V_325 ,
T_2 V_328 , bool V_171 , const T_2 * V_329 ,
struct V_330 * V_255 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_3 V_204 ;
F_14 ( V_115 -> V_104 , L_85 ,
V_105 , V_328 , V_329 , V_255 -> V_12 ) ;
switch ( V_255 -> V_12 ) {
case V_17 :
case V_18 :
return F_52 ( V_115 , V_255 -> V_191 , V_255 -> V_192 ,
V_328 ) ;
case V_15 :
case V_14 :
V_204 = 0 ;
if ( V_255 -> V_331 && V_255 -> V_203 > 0 )
V_204 |= V_207 ;
if ( V_329 )
V_204 |= V_209 |
V_210 ;
return F_53 ( V_115 , V_255 -> V_191 , V_255 -> V_192 ,
V_328 , V_329 , V_255 -> V_331 ,
V_255 -> V_203 , V_255 -> V_12 , V_204 ) ;
default:
F_14 ( V_115 -> V_104 , L_86 ,
V_105 , V_255 -> V_12 ) ;
return - V_168 ;
}
}
static int F_104 ( struct V_190 * V_190 , struct V_252 * V_325 ,
T_2 V_328 , bool V_171 , const T_2 * V_329 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_14 ( V_115 -> V_104 , L_87 , V_105 , V_328 , V_329 ) ;
return F_57 ( V_115 , V_328 , V_329 ) ;
}
static int F_105 ( struct V_190 * V_190 , struct V_252 * V_325 ,
T_2 V_328 , bool V_332 , bool V_333 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_213 V_191 ;
F_14 ( V_115 -> V_104 , L_88 , V_105 , V_328 ) ;
if ( V_328 >= V_196 )
return - V_217 ;
V_5 -> V_199 = V_328 ;
if ( F_3 ( V_5 , V_328 ) )
return 0 ;
V_191 = V_5 -> V_13 [ V_328 ] ;
return F_52 ( V_115 , V_191 . V_198 , V_191 . V_81 , V_328 ) ;
}
static void F_106 ( struct V_2 * V_115 ,
struct V_334 * V_335 )
{
T_3 V_336 , V_290 ;
int V_70 , V_81 ;
memset ( V_335 , 0 , sizeof( * V_335 ) ) ;
V_81 = sizeof( V_336 ) ;
V_70 = F_9 ( V_115 , V_33 , & V_336 , & V_81 ) ;
if ( V_70 == 0 ) {
V_335 -> V_337 . V_338 = F_15 ( V_336 ) / 1000 ;
V_335 -> V_339 |= V_340 ;
}
V_81 = sizeof( V_290 ) ;
V_70 = F_9 ( V_115 , V_61 , & V_290 , & V_81 ) ;
if ( V_70 == 0 ) {
V_335 -> signal = F_25 ( F_15 ( V_290 ) ) ;
V_335 -> V_339 |= V_341 ;
}
}
static int F_107 ( struct V_190 * V_190 , struct V_252 * V_3 ,
T_2 * V_287 , struct V_334 * V_335 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( F_69 ( V_5 -> V_141 , V_287 ) )
return - V_217 ;
F_106 ( V_115 , V_335 ) ;
return 0 ;
}
static int F_108 ( struct V_190 * V_190 , struct V_252 * V_3 ,
int V_11 , T_2 * V_287 , struct V_334 * V_335 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( V_11 != 0 )
return - V_217 ;
memcpy ( V_287 , V_5 -> V_141 , V_142 ) ;
F_106 ( V_115 , V_335 ) ;
return 0 ;
}
static int F_109 ( struct V_190 * V_190 , struct V_252 * V_325 ,
struct V_246 * V_247 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_235 * V_236 ;
T_1 * V_133 = ( T_1 * ) V_247 -> V_244 ;
F_14 ( V_115 -> V_104 , L_89 , V_105 ,
V_247 -> V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
V_236 = F_64 ( V_115 ) ;
if ( F_110 ( V_236 ) ) {
return F_111 ( V_236 ) ;
}
V_236 = F_70 ( V_115 , V_236 , V_247 , V_190 -> V_241 ) ;
if ( F_110 ( V_236 ) ) {
return F_111 ( V_236 ) ;
}
return F_67 ( V_115 , V_236 ) ;
}
static int F_112 ( struct V_190 * V_190 , struct V_252 * V_325 ,
struct V_246 * V_247 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_235 * V_236 ;
T_1 * V_133 = ( T_1 * ) V_247 -> V_244 ;
F_14 ( V_115 -> V_104 , L_89 , V_105 ,
V_247 -> V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
V_236 = F_64 ( V_115 ) ;
if ( F_110 ( V_236 ) ) {
return F_111 ( V_236 ) ;
}
V_236 = F_68 ( V_115 , V_236 , V_247 , V_190 -> V_241 ) ;
if ( F_110 ( V_236 ) ) {
return F_111 ( V_236 ) ;
}
return F_67 ( V_115 , V_236 ) ;
}
static int F_113 ( struct V_190 * V_190 , struct V_252 * V_325 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_235 V_244 ;
F_14 ( V_115 -> V_104 , L_61 , V_105 ) ;
memset ( & V_244 , 0 , sizeof( V_244 ) ) ;
V_244 . V_148 = F_12 ( sizeof( V_244 ) ) ;
V_244 . V_242 = F_12 ( 0 ) ;
return F_18 ( V_115 , V_57 , & V_244 , sizeof( V_244 ) ) ;
}
static int F_114 ( struct V_190 * V_190 , struct V_252 * V_3 ,
bool V_342 , int V_343 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_344 ;
T_3 V_178 ;
int V_70 ;
if ( V_5 -> V_271 != V_345 )
return - V_168 ;
F_14 ( V_115 -> V_104 , L_90 , V_105 ,
V_342 ? L_91 : L_92 ,
V_343 ) ;
if ( V_342 )
V_344 = V_346 ;
else
V_344 = V_347 ;
if ( V_344 == V_5 -> V_344 )
return 0 ;
V_5 -> V_344 = V_344 ;
V_178 = F_12 ( V_344 ) ;
V_70 = F_18 ( V_115 , V_67 , & V_178 , sizeof( V_178 ) ) ;
F_14 ( V_115 -> V_104 , L_93 ,
V_105 , V_70 ) ;
return V_70 ;
}
static int F_115 ( struct V_190 * V_190 ,
struct V_252 * V_3 ,
T_5 V_348 , T_1 V_349 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
V_5 -> V_350 = V_348 ;
V_5 -> V_351 = V_349 ;
V_5 -> V_352 = 0 ;
return 0 ;
}
static void F_116 ( struct V_2 * V_115 , T_2 * V_141 ,
struct V_144 * V_145 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_187 * V_182 ;
struct V_138 V_139 ;
struct V_277 * V_278 ;
T_5 signal ;
T_6 V_279 ;
T_7 V_280 ;
T_1 V_188 = 0 ;
T_3 V_290 ;
T_2 V_353 [ 34 ] ;
int V_81 , V_70 , V_284 ;
V_81 = sizeof( V_290 ) ;
V_290 = 0 ;
V_70 = F_9 ( V_115 , V_61 , & V_290 , & V_81 ) ;
signal = F_25 ( F_15 ( V_290 ) ) ;
F_14 ( V_115 -> V_104 , L_94
L_95 , V_105 , V_70 , F_15 ( V_290 ) ,
F_25 ( F_15 ( V_290 ) ) ) ;
if ( V_145 ) {
V_280 = F_85 ( V_145 -> V_354 . V_355 ) ;
} else {
V_280 = ( V_5 -> V_179 == V_147 ) ?
V_356 : V_357 ;
}
V_182 = F_49 ( V_115 , & V_188 ) ;
if ( ! V_182 ) {
F_28 ( V_115 -> V_104 , L_96 ,
V_105 ) ;
return;
}
V_81 = sizeof( V_139 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_70 = F_9 ( V_115 , V_44 , & V_139 , & V_81 ) ;
F_14 ( V_115 -> V_104 , L_97
L_98 , V_105 , V_70 ,
F_15 ( V_139 . V_148 ) , V_139 . V_149 ) ;
if ( F_15 ( V_139 . V_148 ) > 32 )
V_139 . V_148 = F_12 ( 32 ) ;
V_353 [ 0 ] = V_358 ;
V_353 [ 1 ] = F_15 ( V_139 . V_148 ) ;
memcpy ( & V_353 [ 2 ] , V_139 . V_149 , F_15 ( V_139 . V_148 ) ) ;
V_284 = F_15 ( V_139 . V_148 ) + 2 ;
V_279 = 0 ;
F_14 ( V_115 -> V_104 , L_99
L_100
L_101 , V_105 , ( V_182 ? V_182 -> V_309 : - 1 ) ,
V_141 , ( T_1 ) V_279 , V_280 , V_188 , V_284 ,
V_139 . V_149 , signal ) ;
V_278 = F_86 ( V_5 -> V_189 . V_190 , V_182 , V_141 ,
V_279 , V_280 , V_188 , V_353 , V_284 ,
signal , V_96 ) ;
F_87 ( V_278 ) ;
}
static void F_117 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_144 * V_145 = NULL ;
T_2 V_141 [ V_142 ] ;
unsigned int V_359 , V_360 ;
unsigned int V_107 ;
T_2 * V_361 , * V_354 ;
int V_70 ;
bool V_362 = false ;
bool V_363 ;
if ( V_5 -> V_179 == V_147 && V_5 -> V_322 ) {
V_362 = true ;
}
V_360 = 0 ;
V_359 = 0 ;
V_361 = NULL ;
V_354 = NULL ;
if ( V_5 -> V_179 == V_147 ) {
V_145 = F_65 ( V_94 , V_96 ) ;
if ( ! V_145 ) {
F_118 ( V_364 , & V_5 -> V_365 ) ;
F_119 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
return;
}
V_70 = F_32 ( V_115 , V_145 , V_94 ) ;
if ( ! V_70 ) {
V_360 = F_15 ( V_145 -> V_366 ) ;
if ( V_360 > V_94 )
V_360 = V_94 ;
if ( V_360 != 0 ) {
V_107 = F_15 ( V_145 -> V_367 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_361 = ( T_2 * ) V_145 + V_107 ;
if ( V_107 + V_360 > V_94 )
V_360 =
V_94 - V_107 ;
}
V_359 = F_15 ( V_145 -> V_368 ) ;
if ( V_359 > V_94 )
V_359 = V_94 ;
if ( V_359 != 0 ) {
V_107 = F_15 ( V_145 -> V_369 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_354 = ( T_2 * ) V_145 + V_107 ;
if ( V_107 + V_359 > V_94 )
V_359 =
V_94 - V_107 ;
}
} else {
F_17 ( V_145 ) ;
V_145 = NULL ;
}
} else if ( F_120 ( V_5 -> V_179 != V_211 ) )
return;
V_70 = F_31 ( V_115 , V_141 ) ;
if ( V_70 < 0 )
memset ( V_141 , 0 , sizeof( V_141 ) ) ;
F_14 ( V_115 -> V_104 , L_102 ,
V_141 , V_362 ? L_103 : L_104 ) ;
V_363 = false ;
F_80 ( V_115 , V_141 , & V_363 ) ;
if ( ! F_34 ( V_141 ) && ! V_363 ) {
F_116 ( V_115 , V_141 , V_145 ) ;
}
if ( V_5 -> V_179 == V_147 ) {
if ( ! V_362 )
F_121 ( V_115 -> V_104 , V_141 , V_361 ,
V_360 , V_354 ,
V_359 , 0 , V_96 ) ;
else
F_122 ( V_115 -> V_104 ,
F_49 ( V_115 , NULL ) ,
V_141 , V_361 , V_360 ,
V_354 , V_359 , V_96 ) ;
} else if ( V_5 -> V_179 == V_211 )
F_123 ( V_115 -> V_104 , V_141 , V_96 ) ;
if ( V_145 != NULL )
F_17 ( V_145 ) ;
V_5 -> V_322 = true ;
memcpy ( V_5 -> V_141 , V_141 , V_142 ) ;
F_100 ( V_115 ) ;
F_124 ( V_115 -> V_104 ) ;
}
static void F_125 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( V_5 -> V_322 ) {
V_5 -> V_322 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
F_46 ( V_115 ) ;
F_126 ( V_115 -> V_104 , 0 , NULL , 0 , V_96 ) ;
}
F_127 ( V_115 -> V_104 ) ;
}
static void F_128 ( struct V_304 * V_305 )
{
struct V_1 * V_5 =
F_91 ( V_305 , struct V_1 , V_305 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( F_129 ( V_364 , & V_5 -> V_365 ) )
F_117 ( V_115 ) ;
if ( F_129 ( V_370 , & V_5 -> V_365 ) )
F_125 ( V_115 ) ;
if ( F_129 ( V_371 , & V_5 -> V_365 ) )
F_58 ( V_115 ) ;
}
static void F_130 ( struct V_252 * V_3 )
{
struct V_2 * V_115 = F_79 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( F_131 ( V_371 , & V_5 -> V_365 ) )
return;
F_118 ( V_371 , & V_5 -> V_365 ) ;
F_119 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
}
static void F_132 ( struct V_2 * V_115 ,
struct V_372 * V_373 ,
int V_81 )
{
T_2 * V_82 ;
const char * type ;
int V_204 , V_90 , V_374 ;
bool V_375 , V_376 ;
struct V_377 * V_378 ;
enum V_379 V_380 ;
if ( V_81 < F_133 ( struct V_372 , V_89 ) +
sizeof( struct V_377 ) ) {
F_134 ( V_115 -> V_104 , L_105 ,
V_81 ) ;
return;
}
V_82 = ( void * ) & V_373 -> V_89 . V_381 [ 0 ] ;
V_90 = V_81 - F_133 ( struct V_372 , V_89 ) ;
while ( V_90 >= sizeof( * V_378 ) ) {
V_378 = ( void * ) V_82 ;
type = L_106 ;
V_204 = F_15 ( V_378 -> V_204 ) ;
V_375 = false ;
V_376 = false ;
if ( V_204 & 0x1 )
type = L_107 ;
if ( V_204 & 0x2 )
type = L_108 ;
if ( V_204 & 0x6 ) {
V_375 = true ;
type = L_109 ;
}
if ( V_204 & 0xe ) {
V_376 = true ;
type = L_110 ;
}
F_134 ( V_115 -> V_104 , L_111 ,
type , F_15 ( V_378 -> V_204 ) ) ;
if ( V_375 ) {
V_380 = V_382 ;
V_374 = - 1 ;
F_135 ( V_115 -> V_104 ,
V_378 -> V_141 ,
V_380 , V_374 , NULL ,
V_96 ) ;
}
if ( V_376 ) {
V_380 = V_383 ;
V_374 = - 1 ;
F_135 ( V_115 -> V_104 ,
V_378 -> V_141 ,
V_380 , V_374 , NULL ,
V_96 ) ;
}
V_90 -= F_15 ( V_378 -> V_148 ) ;
V_82 += F_15 ( V_378 -> V_148 ) ;
}
}
static void F_136 ( struct V_2 * V_115 ,
struct V_372 * V_373 ,
int V_81 )
{
struct V_384 * V_385 ;
int V_386 , V_387 , V_126 ;
if ( V_81 < F_133 ( struct V_372 , V_89 ) +
sizeof( struct V_384 ) ) {
F_134 ( V_115 -> V_104 , L_112 ,
V_81 ) ;
return;
}
V_386 = F_15 ( V_373 -> V_89 . V_385 . V_388 ) *
sizeof( struct V_389 ) ;
V_387 = sizeof( struct V_384 ) + V_386 +
F_133 ( struct V_372 , V_89 ) ;
if ( V_81 < V_387 ) {
F_134 ( V_115 -> V_104 , L_113 ,
V_81 , V_387 ) ;
return;
}
V_385 = & V_373 -> V_89 . V_385 ;
F_134 ( V_115 -> V_104 , L_114 ,
F_15 ( V_385 -> V_390 ) ,
F_15 ( V_385 -> V_388 ) ) ;
if ( F_15 ( V_385 -> V_390 ) != 1 )
return;
for ( V_126 = 0 ; V_126 < F_15 ( V_385 -> V_388 ) ; V_126 ++ ) {
struct V_389 * V_391 =
& V_385 -> V_392 [ V_126 ] ;
bool V_393 = ! ! ( V_391 -> V_204 & V_394 ) ;
F_14 ( V_115 -> V_104 , L_115 ,
V_126 , F_15 ( V_391 -> V_204 ) , V_393 , V_391 -> V_141 ) ;
F_137 ( V_115 -> V_104 , V_126 , V_391 -> V_141 ,
V_393 , V_233 ) ;
}
}
static void F_138 ( struct V_2 * V_115 ,
struct V_395 * V_396 , int V_90 )
{
struct V_372 * V_373 ;
unsigned int V_81 , V_107 ;
V_107 = F_133 ( struct V_395 , V_106 ) +
F_15 ( V_396 -> V_107 ) ;
V_81 = F_15 ( V_396 -> V_148 ) ;
if ( V_81 < 8 ) {
F_134 ( V_115 -> V_104 , L_116 ,
V_81 ) ;
return;
}
if ( V_81 > V_90 || V_107 > V_90 || V_107 + V_81 > V_90 ) {
F_134 ( V_115 -> V_104 , L_117 ,
V_107 + V_81 , V_90 ) ;
return;
}
V_373 = ( void * ) ( ( T_2 * ) V_396 + V_107 ) ;
switch ( F_15 ( V_373 -> V_397 ) ) {
case V_398 :
F_134 ( V_115 -> V_104 , L_118 ,
F_15 ( V_373 -> V_89 . V_399 ) ) ;
return;
case V_400 :
F_134 ( V_115 -> V_104 , L_119 ,
F_15 ( V_373 -> V_89 . V_401 ) ) ;
return;
case V_402 :
F_132 ( V_115 , V_373 , V_81 ) ;
return;
case V_403 :
F_136 ( V_115 , V_373 , V_81 ) ;
return;
default:
F_134 ( V_115 -> V_104 , L_120 ,
F_15 ( V_373 -> V_397 ) ) ;
}
}
static void F_139 ( struct V_2 * V_115 , void * V_404 , int V_90 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_395 * V_396 = V_404 ;
switch ( V_396 -> V_106 ) {
case V_405 :
if ( V_5 -> V_103 == V_53 ) {
F_14 ( V_115 -> V_104 , L_121 ) ;
return;
}
F_96 ( V_115 ) ;
F_134 ( V_115 -> V_104 , L_122 ) ;
F_118 ( V_364 , & V_5 -> V_365 ) ;
F_119 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
break;
case V_406 :
F_134 ( V_115 -> V_104 , L_123 ) ;
F_118 ( V_370 , & V_5 -> V_365 ) ;
F_119 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
break;
case V_407 :
F_138 ( V_115 , V_396 , V_90 ) ;
break;
default:
F_134 ( V_115 -> V_104 , L_124 ,
F_15 ( V_396 -> V_106 ) ) ;
break;
}
}
static int F_140 ( struct V_2 * V_115 , struct V_190 * V_190 )
{
struct {
T_3 V_303 ;
T_3 V_408 [ 8 ] ;
} V_409 ;
struct V_410 * V_411 ;
T_2 V_412 [ sizeof( * V_411 ) + sizeof( V_411 -> V_413 ) * 16 ] ;
int V_81 , V_414 , V_126 , V_415 ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_81 = sizeof( V_409 ) ;
V_414 = F_9 ( V_115 , V_58 ,
& V_409 , & V_81 ) ;
if ( V_414 >= 0 ) {
V_415 = F_15 ( V_409 . V_303 ) ;
if ( V_415 > 8 )
V_415 = 8 ;
for ( V_126 = 0 ; V_126 < V_415 ; V_126 ++ ) {
switch ( F_15 ( V_409 . V_408 [ V_126 ] ) ) {
case V_416 :
case V_417 :
V_5 -> V_411 |= V_418 ;
break;
case V_419 :
V_5 -> V_411 |= V_420 ;
break;
case V_421 :
V_5 -> V_411 |= V_422 ;
break;
}
}
}
V_411 = (struct V_410 * ) V_412 ;
V_81 = sizeof( V_412 ) ;
V_414 = F_9 ( V_115 , V_56 , V_411 , & V_81 ) ;
if ( V_414 >= 0 ) {
F_14 ( V_115 -> V_104 , L_125
L_126 ,
F_15 ( V_411 -> V_148 ) ,
F_15 ( V_411 -> V_390 ) ,
F_15 ( V_411 -> V_245 ) ,
F_15 ( V_411 -> V_423 ) ) ;
V_190 -> V_241 = F_15 ( V_411 -> V_245 ) ;
} else
V_190 -> V_241 = 0 ;
return V_414 ;
}
static void F_141 ( struct V_2 * V_115 , T_5 V_290 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
enum V_424 V_425 ;
int V_426 , V_427 , V_428 ;
if ( V_5 -> V_350 >= 0 || V_290 >= 0 )
return;
if ( V_5 -> V_179 != V_147 )
return;
V_428 = V_5 -> V_352 ;
V_426 = V_5 -> V_350 ;
V_427 = V_5 -> V_351 ;
if ( V_290 < V_426 && ( V_428 == 0 || V_290 < V_428 - V_427 ) )
V_425 = V_429 ;
else if ( V_290 > V_426 && ( V_428 == 0 || V_290 > V_428 + V_427 ) )
V_425 = V_430 ;
else
return;
V_5 -> V_352 = V_290 ;
F_142 ( V_115 -> V_104 , V_425 , V_96 ) ;
}
static void F_143 ( struct V_304 * V_305 )
{
struct V_1 * V_5 =
F_91 ( V_305 , struct V_1 ,
V_431 . V_305 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_3 V_290 , V_133 ;
int V_81 , V_70 , V_432 ;
int V_433 = V_434 ;
void * V_82 ;
if ( ! F_33 ( V_115 ) ) {
if ( V_5 -> V_271 == V_272 && V_5 -> V_140 &&
! V_5 -> V_270 ) {
F_80 ( V_115 , NULL , NULL ) ;
F_26 ( V_115 ) ;
}
goto V_435;
}
V_81 = sizeof( V_290 ) ;
V_70 = F_9 ( V_115 , V_61 , & V_290 , & V_81 ) ;
if ( V_70 == 0 ) {
V_5 -> V_436 = F_25 ( F_15 ( V_290 ) ) ;
F_141 ( V_115 , F_15 ( V_290 ) ) ;
}
F_14 ( V_115 -> V_104 , L_127 ,
V_70 , F_15 ( V_290 ) , F_25 ( F_15 ( V_290 ) ) ) ;
if ( V_5 -> V_437 > 0 && V_5 -> V_436 <= 25 ) {
V_432 = F_144 ( V_5 -> V_437 ) ;
if ( V_432 > V_434 )
V_432 = V_434 ;
else if ( V_432 <= 0 )
V_432 = 1 ;
V_433 = V_432 ;
V_133 = F_12 ( 1 ) ;
F_18 ( V_115 , V_51 , & V_133 ,
sizeof( V_133 ) ) ;
V_81 = V_94 ;
V_82 = F_10 ( V_81 , V_96 ) ;
if ( ! V_82 )
goto V_435;
F_9 ( V_115 , V_68 , V_82 , & V_81 ) ;
F_17 ( V_82 ) ;
}
V_435:
if ( V_433 >= V_273 )
V_433 = F_145 ( V_433 ) ;
else {
V_432 = F_145 ( V_433 ) ;
if ( abs ( V_432 - V_433 ) <= 10 )
V_433 = V_432 ;
}
F_81 ( V_5 -> V_274 , & V_5 -> V_431 ,
V_433 ) ;
}
static void F_146 ( struct V_2 * V_115 , int V_271 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_5 -> V_271 = V_271 ;
V_5 -> V_438 [ 0 ] = V_439 [ 0 ] ;
V_5 -> V_438 [ 1 ] = V_439 [ 1 ] ;
V_5 -> V_438 [ 2 ] = 0 ;
V_5 -> V_440 = V_441 ;
V_5 -> V_442 = V_443 ;
V_5 -> V_444 = V_445 ;
V_5 -> V_6 = V_446 ;
V_5 -> V_447 = V_448 ;
V_5 -> V_449 = V_450 ;
V_5 -> V_438 [ 0 ] = toupper ( V_5 -> V_438 [ 0 ] ) ;
V_5 -> V_438 [ 1 ] = toupper ( V_5 -> V_438 [ 1 ] ) ;
if ( ! strcmp ( V_5 -> V_438 , L_128 ) )
strcpy ( V_5 -> V_438 , L_129 ) ;
if ( V_5 -> V_444 < 0 )
V_5 -> V_444 = 0 ;
else if ( V_5 -> V_444 > 2 )
V_5 -> V_444 = 2 ;
if ( V_5 -> V_6 < 0 )
V_5 -> V_6 = 0 ;
else if ( V_5 -> V_6 > 3 )
V_5 -> V_6 = 3 ;
if ( V_5 -> V_447 < - 80 )
V_5 -> V_447 = - 80 ;
else if ( V_5 -> V_447 > - 60 )
V_5 -> V_447 = - 60 ;
if ( V_5 -> V_449 < 0 )
V_5 -> V_449 = 0 ;
else if ( V_5 -> V_449 > 2 )
V_5 -> V_449 = 2 ;
if ( V_451 < 0 )
V_5 -> V_437 = 500 ;
else
V_5 -> V_437 = V_451 ;
}
static int F_147 ( struct V_2 * V_115 )
{
F_146 ( V_115 , V_452 ) ;
return 0 ;
}
static int F_148 ( struct V_2 * V_115 )
{
F_146 ( V_115 , V_272 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
char V_82 [ 8 ] ;
F_146 ( V_115 , V_345 ) ;
F_24 ( V_115 , L_130 , V_5 -> V_438 ) ;
F_24 ( V_115 , L_131 ,
V_5 -> V_440 ? L_132 : L_133 ) ;
F_24 ( V_115 , L_134 ,
V_5 -> V_442 ? L_132 : L_133 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_444 ) ;
F_24 ( V_115 , L_136 , V_82 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_6 ) ;
F_24 ( V_115 , L_137 , V_82 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_447 ) ;
F_24 ( V_115 , L_138 , V_82 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_449 ) ;
F_24 ( V_115 , L_139 , V_82 ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_115 , struct V_453 * V_454 )
{
struct V_190 * V_190 ;
struct V_1 * V_5 ;
int V_414 , V_81 ;
T_3 V_133 ;
V_190 = F_151 ( & V_455 , sizeof( struct V_1 ) ) ;
if ( ! V_190 )
return - V_97 ;
V_5 = F_73 ( V_190 ) ;
V_115 -> V_104 -> V_456 = & V_5 -> V_189 ;
V_5 -> V_189 . V_190 = V_190 ;
V_5 -> V_189 . V_258 = V_257 ;
V_115 -> V_4 = V_5 ;
V_5 -> V_115 = V_115 ;
F_152 ( & V_5 -> V_99 ) ;
V_5 -> V_274 = F_153 ( L_140 ) ;
F_154 ( & V_5 -> V_305 , F_128 ) ;
F_155 ( & V_5 -> V_431 , F_143 ) ;
F_155 ( & V_5 -> V_275 , F_90 ) ;
V_414 = F_156 ( V_115 , V_454 , V_457 ) ;
if ( V_414 < 0 )
goto V_458;
V_115 -> V_104 -> V_459 = & V_460 ;
V_133 = V_224 | V_225 ;
V_414 = F_18 ( V_115 , V_31 , & V_133 ,
sizeof( V_133 ) ) ;
V_81 = sizeof( V_133 ) ;
V_414 = F_9 ( V_115 , V_42 , & V_133 ,
& V_81 ) ;
V_5 -> V_232 = F_15 ( V_133 ) ;
if ( V_414 < 0 || V_5 -> V_232 < 0 )
V_5 -> V_232 = 0 ;
if ( V_5 -> V_232 > 0 )
V_115 -> V_104 -> V_204 |= V_461 ;
else
V_115 -> V_104 -> V_204 &= ~ V_461 ;
memcpy ( V_190 -> V_462 , V_115 -> V_104 -> V_463 , V_142 ) ;
V_190 -> V_464 = V_465 ;
V_190 -> V_466 = F_157 ( V_257 )
| F_157 ( V_256 ) ;
V_190 -> V_467 = 1 ;
F_140 ( V_115 , V_190 ) ;
memcpy ( V_5 -> V_468 , V_469 , sizeof( V_469 ) ) ;
memcpy ( V_5 -> V_470 , V_471 , sizeof( V_471 ) ) ;
V_5 -> V_472 . V_468 = V_5 -> V_468 ;
V_5 -> V_472 . V_473 = F_158 ( V_469 ) ;
V_5 -> V_472 . V_474 = V_5 -> V_470 ;
V_5 -> V_472 . V_475 = F_158 ( V_471 ) ;
V_190 -> V_476 [ V_477 ] = & V_5 -> V_472 ;
V_190 -> V_478 = V_479 ;
memcpy ( V_5 -> V_480 , V_481 ,
sizeof( V_481 ) ) ;
V_190 -> V_480 = V_5 -> V_480 ;
V_190 -> V_482 = F_158 ( V_481 ) ;
F_159 ( V_190 , & V_115 -> V_483 -> V_3 ) ;
if ( F_160 ( V_190 ) ) {
V_414 = - V_484 ;
goto V_458;
}
F_45 ( V_115 ) ;
V_5 -> V_344 = - 1 ;
F_74 ( V_190 ,
V_260 | V_261 ) ;
V_5 -> V_140 = false ;
F_35 ( V_115 , false ) ;
F_127 ( V_115 -> V_104 ) ;
return 0 ;
V_458:
F_161 ( & V_5 -> V_431 ) ;
F_161 ( & V_5 -> V_275 ) ;
F_162 ( & V_5 -> V_305 ) ;
F_163 ( V_5 -> V_274 ) ;
F_164 ( V_5 -> V_274 ) ;
F_165 ( V_190 ) ;
return V_414 ;
}
static void F_166 ( struct V_2 * V_115 , struct V_453 * V_454 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
F_35 ( V_115 , false ) ;
F_161 ( & V_5 -> V_431 ) ;
F_161 ( & V_5 -> V_275 ) ;
F_162 ( & V_5 -> V_305 ) ;
F_163 ( V_5 -> V_274 ) ;
F_164 ( V_5 -> V_274 ) ;
F_167 ( V_115 , V_454 ) ;
F_168 ( V_5 -> V_189 . V_190 ) ;
F_165 ( V_5 -> V_189 . V_190 ) ;
}
static int F_169 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_414 ;
F_14 ( V_115 -> V_104 , L_61 , V_105 ) ;
V_414 = F_19 ( V_115 ) ;
if ( V_414 )
F_28 ( V_115 -> V_104 , L_141 , V_414 ) ;
F_58 ( V_115 ) ;
F_81 ( V_5 -> V_274 , & V_5 -> V_431 ,
F_145 ( V_434 ) ) ;
return F_46 ( V_115 ) ;
}
static int F_170 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_414 ;
T_3 V_220 ;
F_14 ( V_115 -> V_104 , L_61 , V_105 ) ;
V_414 = F_35 ( V_115 , false ) ;
V_5 -> V_365 = 0 ;
F_161 ( & V_5 -> V_431 ) ;
F_161 ( & V_5 -> V_275 ) ;
F_162 ( & V_5 -> V_305 ) ;
F_163 ( V_5 -> V_274 ) ;
if ( V_5 -> V_270 ) {
F_92 ( V_5 -> V_270 , true ) ;
V_5 -> V_270 = NULL ;
}
V_220 = 0 ;
F_18 ( V_115 , V_31 , & V_220 ,
sizeof( V_220 ) ) ;
return V_414 ;
}
