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
static const char * F_6 ( T_1 V_28 )
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
static const char * F_6 ( T_1 V_28 )
{
return L_1 ;
}
static int F_8 ( T_3 V_69 )
{
int V_70 = - V_71 ;
switch ( F_9 ( V_69 ) ) {
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
static int F_10 ( struct V_2 * V_3 , T_1 V_28 , void * V_80 , int * V_81 )
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
V_89 . V_82 = F_11 ( V_90 , V_96 ) ;
if ( ! V_89 . V_82 )
return - V_97 ;
} else {
V_89 . V_82 = V_5 -> V_98 ;
}
F_12 ( & V_5 -> V_99 ) ;
memset ( V_89 . V_86 , 0 , sizeof * V_89 . V_86 ) ;
V_89 . V_86 -> V_100 = F_13 ( V_101 ) ;
V_89 . V_86 -> V_102 = F_13 ( sizeof * V_89 . V_86 ) ;
V_89 . V_86 -> V_28 = F_13 ( V_28 ) ;
V_5 -> V_103 = V_28 ;
V_70 = F_14 ( V_3 , V_89 . V_84 , V_90 ) ;
V_5 -> V_103 = 0 ;
if ( V_70 < 0 )
F_15 ( V_3 -> V_104 , L_2 ,
V_105 , F_6 ( V_28 ) , V_70 ,
F_9 ( V_89 . V_88 -> V_106 ) ) ;
if ( V_70 == 0 ) {
V_91 = F_9 ( V_89 . V_88 -> V_81 ) ;
V_92 = F_9 ( V_89 . V_88 -> V_107 ) + 8 ;
if ( V_92 > V_90 ) {
F_15 ( V_3 -> V_104 , L_3
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
F_15 ( V_3 -> V_104 , L_5 ,
V_105 , F_6 ( V_28 ) ,
F_9 ( V_89 . V_88 -> V_106 ) , V_70 ) ;
}
V_108:
F_16 ( & V_5 -> V_99 ) ;
if ( V_89 . V_82 != V_5 -> V_98 )
F_17 ( V_89 . V_82 ) ;
return V_70 ;
}
static int F_18 ( struct V_2 * V_3 , T_1 V_28 , const void * V_80 ,
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
V_89 . V_82 = F_11 ( V_90 , V_96 ) ;
if ( ! V_89 . V_82 )
return - V_97 ;
} else {
V_89 . V_82 = V_5 -> V_98 ;
}
F_12 ( & V_5 -> V_99 ) ;
memset ( V_89 . V_110 , 0 , sizeof * V_89 . V_110 ) ;
V_89 . V_110 -> V_100 = F_13 ( V_113 ) ;
V_89 . V_110 -> V_102 = F_13 ( sizeof( * V_89 . V_110 ) + V_81 ) ;
V_89 . V_110 -> V_28 = F_13 ( V_28 ) ;
V_89 . V_110 -> V_81 = F_13 ( V_81 ) ;
V_89 . V_110 -> V_107 = F_13 ( sizeof( * V_89 . V_110 ) - 8 ) ;
V_89 . V_110 -> V_114 = F_13 ( 0 ) ;
memcpy ( V_89 . V_82 + sizeof( * V_89 . V_110 ) , V_80 , V_81 ) ;
V_5 -> V_103 = V_28 ;
V_70 = F_14 ( V_3 , V_89 . V_84 , V_90 ) ;
V_5 -> V_103 = 0 ;
if ( V_70 < 0 )
F_15 ( V_3 -> V_104 , L_2 ,
V_105 , F_6 ( V_28 ) , V_70 ,
F_9 ( V_89 . V_112 -> V_106 ) ) ;
if ( V_70 == 0 ) {
V_70 = F_8 ( V_89 . V_112 -> V_106 ) ;
if ( V_70 < 0 )
F_15 ( V_3 -> V_104 , L_6 ,
V_105 , F_6 ( V_28 ) ,
F_9 ( V_89 . V_112 -> V_106 ) , V_70 ) ;
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
F_12 ( & V_5 -> V_99 ) ;
V_116 = ( void * ) V_5 -> V_98 ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_100 = F_13 ( V_117 ) ;
V_116 -> V_102 = F_13 ( sizeof( * V_116 ) ) ;
V_5 -> V_103 = 0 ;
V_70 = F_14 ( V_115 , ( void * ) V_116 , V_94 ) ;
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
V_122 = F_11 ( V_124 , V_96 ) ;
if ( ! V_122 )
return - V_97 ;
#ifdef F_21
V_124 -= 12 ;
memset ( V_122 , 0xCC , V_124 + 12 ) ;
#endif
if ( V_119 == 2 )
F_15 ( V_3 -> V_104 , L_7 ,
V_118 , ( T_2 * ) V_120 ) ;
else
F_15 ( V_3 -> V_104 , L_8 ,
V_118 , * ( T_1 * ) V_120 ) ;
V_122 -> V_129 = F_13 ( sizeof( * V_122 ) ) ;
V_122 -> V_130 = F_13 ( V_125 ) ;
V_122 -> type = F_13 ( V_119 ) ;
V_122 -> V_131 = F_13 ( sizeof( * V_122 ) + V_125 ) ;
V_122 -> V_132 = F_13 ( V_123 ) ;
V_127 = ( void * ) V_122 + sizeof( * V_122 ) ;
for ( V_126 = 0 ; V_126 < V_125 / sizeof( T_4 ) ; V_126 ++ )
V_127 [ V_126 ] = F_22 ( V_118 [ V_126 ] ) ;
if ( V_119 == 2 ) {
V_127 = ( void * ) V_122 + sizeof( * V_122 ) + V_125 ;
for ( V_126 = 0 ; V_126 < V_123 / sizeof( T_4 ) ; V_126 ++ )
V_127 [ V_126 ] = F_22 ( ( ( T_2 * ) V_120 ) [ V_126 ] ) ;
} else {
V_128 = ( void * ) V_122 + sizeof( * V_122 ) + V_125 ;
* V_128 = F_13 ( * ( T_1 * ) V_120 ) ;
}
#ifdef F_21
F_15 ( V_3 -> V_104 , L_9 , V_124 ) ;
for ( V_126 = 0 ; V_126 < V_124 ; V_126 += 12 ) {
T_1 * V_133 = ( T_1 * ) ( ( T_2 * ) V_122 + V_126 ) ;
F_15 ( V_3 -> V_104 , L_10 ,
F_23 ( V_133 [ 0 ] ) ,
F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) ) ;
}
#endif
V_70 = F_18 ( V_3 , V_34 ,
V_122 , V_124 ) ;
if ( V_70 != 0 )
F_15 ( V_3 -> V_104 , L_11 ,
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
V_133 = F_13 ( 1 ) ;
return F_18 ( V_115 , V_51 , & V_133 ,
sizeof( V_133 ) ) ;
}
static int F_27 ( struct V_2 * V_115 , struct V_138 * V_139 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_70 ;
V_70 = F_18 ( V_115 , V_44 ,
V_139 , sizeof( * V_139 ) ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_12 , V_70 ) ;
return V_70 ;
}
if ( V_70 == 0 ) {
V_5 -> V_140 = true ;
F_15 ( V_115 -> V_104 , L_13 , V_105 ) ;
}
return V_70 ;
}
static int F_29 ( struct V_2 * V_115 , const T_2 * V_141 )
{
int V_70 ;
V_70 = F_18 ( V_115 , V_43 ,
V_141 , V_142 ) ;
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
V_70 = F_10 ( V_115 , V_43 ,
V_141 , & V_81 ) ;
if ( V_70 != 0 )
memset ( V_141 , 0 , V_142 ) ;
return V_70 ;
}
static int F_32 ( struct V_2 * V_115 ,
struct V_144 * V_145 , int V_81 )
{
return F_10 ( V_115 ,
V_55 ,
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
V_70 = F_18 ( V_115 ,
V_48 ,
NULL , 0 ) ;
if ( V_70 == 0 ) {
V_5 -> V_140 = false ;
F_15 ( V_115 -> V_104 , L_15 ,
V_105 ) ;
if ( V_146 )
F_36 ( 100 ) ;
}
}
if ( V_146 ) {
F_37 ( V_115 , V_147 ) ;
V_139 . V_148 = F_13 ( sizeof( V_139 . V_149 ) ) ;
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
F_15 ( V_115 -> V_104 , L_16 ,
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
V_133 = F_13 ( V_154 ) ;
V_70 = F_18 ( V_115 ,
V_49 ,
& V_133 , sizeof( V_133 ) ) ;
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
F_15 ( V_115 -> V_104 , L_18 ,
V_105 , V_5 -> V_150 ) ;
if ( V_5 -> V_150 & V_155 ||
V_5 -> V_150 & V_158 )
V_133 = F_13 ( V_169 ) ;
else
V_133 = F_13 ( V_170 ) ;
return F_18 ( V_115 ,
V_50 , & V_133 ,
sizeof( V_133 ) ) ;
}
static int F_41 ( struct V_2 * V_115 , int V_171 , int V_172 )
{
T_3 V_133 ;
int V_173 , V_70 ;
F_15 ( V_115 -> V_104 , L_19 ,
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
V_133 = F_13 ( V_173 ) ;
V_70 = F_18 ( V_115 ,
V_52 , & V_133 ,
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
F_15 ( V_115 -> V_104 , L_21 ,
V_105 , V_5 -> V_179 ) ;
V_133 = F_13 ( V_178 ) ;
V_70 = F_18 ( V_115 ,
V_45 ,
& V_133 , sizeof( V_133 ) ) ;
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
F_15 ( V_115 -> V_104 , L_23 , V_105 , V_180 ) ;
if ( V_180 < 0 || V_180 > 2347 )
V_180 = 2347 ;
V_133 = F_13 ( V_180 ) ;
return F_18 ( V_115 ,
V_64 ,
& V_133 , sizeof( V_133 ) ) ;
}
static int F_44 ( struct V_2 * V_115 , T_1 V_181 )
{
T_3 V_133 ;
F_15 ( V_115 -> V_104 , L_23 , V_105 , V_181 ) ;
if ( V_181 < 256 || V_181 > 2346 )
V_181 = 2346 ;
V_133 = F_13 ( V_181 ) ;
return F_18 ( V_115 ,
V_63 ,
& V_133 , sizeof( V_133 ) ) ;
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
F_15 ( V_115 -> V_104 , L_24 , V_105 , V_182 ) ;
if ( F_33 ( V_115 ) )
return 0 ;
V_185 = 1000 *
F_48 ( V_182 , V_186 ) ;
V_81 = sizeof( V_184 ) ;
V_70 = F_10 ( V_115 ,
V_66 ,
& V_184 , & V_81 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_25 ,
V_105 ) ;
return V_70 ;
}
V_184 . V_187 = F_13 ( V_185 ) ;
V_70 = F_18 ( V_115 ,
V_66 ,
& V_184 , sizeof( V_184 ) ) ;
F_15 ( V_115 -> V_104 , L_26 , V_105 , V_182 , V_70 ) ;
return V_70 ;
}
static struct V_188 * F_49 ( struct V_2 * V_115 ,
T_1 * V_189 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_188 * V_182 ;
struct V_183 V_184 ;
int V_81 , V_70 ;
V_81 = sizeof( V_184 ) ;
V_70 = F_10 ( V_115 ,
V_66 ,
& V_184 , & V_81 ) ;
F_15 ( V_115 -> V_104 , L_27 ,
V_105 , V_70 ) ;
if ( V_70 < 0 )
return NULL ;
V_182 = F_50 ( V_5 -> V_190 . V_191 ,
F_51 ( F_9 ( V_184 . V_187 ) ) ) ;
if ( ! V_182 )
return NULL ;
if ( V_189 )
* V_189 = F_9 ( V_184 . V_189 ) ;
return V_182 ;
}
static int F_52 ( struct V_2 * V_115 , const T_2 * V_192 , int V_193 ,
T_2 V_194 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_195 V_196 ;
T_1 V_12 ;
int V_70 ;
F_15 ( V_115 -> V_104 , L_28 ,
V_105 , V_194 , V_193 ) ;
if ( V_194 >= V_197 )
return - V_71 ;
if ( V_193 == 5 )
V_12 = V_17 ;
else if ( V_193 == 13 )
V_12 = V_18 ;
else
return - V_71 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_198 = F_13 ( sizeof( V_196 ) ) ;
V_196 . V_148 = F_13 ( V_193 ) ;
V_196 . V_194 = F_13 ( V_194 ) ;
memcpy ( & V_196 . V_199 , V_192 , V_193 ) ;
if ( V_194 == V_5 -> V_200 ) {
V_196 . V_194 |= V_201 ;
V_70 = F_41 ( V_115 , V_19 ,
V_16 ) ;
if ( V_70 )
F_28 ( V_115 -> V_104 , L_29 ,
V_70 ) ;
}
V_70 = F_18 ( V_115 ,
V_46 , & V_196 ,
sizeof( V_196 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 , L_30 ,
V_194 + 1 , V_70 ) ;
return V_70 ;
}
V_5 -> V_13 [ V_194 ] . V_81 = V_193 ;
V_5 -> V_13 [ V_194 ] . V_12 = V_12 ;
memcpy ( & V_5 -> V_13 [ V_194 ] . V_199 , V_192 , V_193 ) ;
memset ( & V_5 -> V_13 [ V_194 ] . V_141 , 0xff , V_142 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_115 , const T_2 * V_192 , int V_193 ,
T_2 V_194 , const T_2 * V_202 , const T_2 * V_203 ,
int V_204 , T_1 V_12 , T_3 V_205 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_206 V_196 ;
bool V_207 ;
int V_70 ;
if ( V_194 >= V_197 ) {
F_15 ( V_115 -> V_104 , L_31 ,
V_105 , V_194 ) ;
return - V_71 ;
}
if ( V_193 > sizeof( V_196 . V_199 ) || V_193 < 0 ) {
F_15 ( V_115 -> V_104 , L_32 ,
V_105 , V_193 ) ;
return - V_71 ;
}
if ( V_205 & V_208 ) {
if ( ! V_203 || V_204 <= 0 ) {
F_15 ( V_115 -> V_104 , L_33 ,
V_105 ) ;
return - V_71 ;
}
if ( V_203 && V_204 > sizeof( V_196 . V_209 ) ) {
F_15 ( V_115 -> V_104 , L_34 , V_105 ) ;
return - V_71 ;
}
}
V_207 = V_202 && ! F_34 ( V_202 ) &&
! F_54 ( V_202 ) ;
if ( ( V_205 & V_210 ) && ! V_207 ) {
F_15 ( V_115 -> V_104 , L_35 ,
V_105 , V_202 ) ;
return - V_71 ;
}
F_15 ( V_115 -> V_104 , L_36 ,
V_105 , V_194 ,
! ! ( V_205 & V_211 ) ,
! ! ( V_205 & V_210 ) ,
! ! ( V_205 & V_208 ) ) ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_198 = F_13 ( sizeof( V_196 ) -
sizeof( V_196 . V_199 ) + V_193 ) ;
V_196 . V_148 = F_13 ( V_193 ) ;
V_196 . V_194 = F_13 ( V_194 ) | V_205 ;
if ( V_12 == V_15 && V_193 == 32 ) {
memcpy ( V_196 . V_199 , V_192 , 16 ) ;
memcpy ( V_196 . V_199 + 16 , V_192 + 24 , 8 ) ;
memcpy ( V_196 . V_199 + 24 , V_192 + 16 , 8 ) ;
} else
memcpy ( V_196 . V_199 , V_192 , V_193 ) ;
if ( V_205 & V_208 )
memcpy ( V_196 . V_209 , V_203 , V_204 ) ;
if ( V_205 & V_210 ) {
memcpy ( V_196 . V_141 , V_202 , V_142 ) ;
} else {
if ( V_5 -> V_179 == V_212 )
memset ( V_196 . V_141 , 0xff , V_142 ) ;
else
F_31 ( V_115 , V_196 . V_141 ) ;
}
V_70 = F_18 ( V_115 ,
V_53 , & V_196 ,
F_9 ( V_196 . V_198 ) ) ;
F_15 ( V_115 -> V_104 , L_37 ,
V_105 , V_70 ) ;
if ( V_70 != 0 )
return V_70 ;
memset ( & V_5 -> V_13 [ V_194 ] , 0 , sizeof( V_5 -> V_13 [ V_194 ] ) ) ;
V_5 -> V_13 [ V_194 ] . V_81 = V_193 ;
V_5 -> V_13 [ V_194 ] . V_12 = V_12 ;
memcpy ( & V_5 -> V_13 [ V_194 ] . V_199 , V_192 , V_193 ) ;
if ( V_205 & V_210 )
memcpy ( & V_5 -> V_13 [ V_194 ] . V_141 , V_196 . V_141 , V_142 ) ;
else
memset ( & V_5 -> V_13 [ V_194 ] . V_141 , 0xff , V_142 ) ;
if ( V_205 & V_211 )
V_5 -> V_200 = V_194 ;
return 0 ;
}
static int F_55 ( struct V_2 * V_115 , T_2 V_213 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_214 V_192 ;
if ( F_3 ( V_5 , V_213 ) )
return 0 ;
V_192 = V_5 -> V_13 [ V_213 ] ;
F_15 ( V_115 -> V_104 , L_38 , V_105 , V_213 , V_192 . V_81 ) ;
if ( V_192 . V_81 == 0 )
return 0 ;
return F_52 ( V_115 , V_192 . V_199 , V_192 . V_81 , V_213 ) ;
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
static int F_57 ( struct V_2 * V_115 , T_2 V_194 , const T_2 * V_141 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_215 F_57 ;
T_3 V_216 ;
bool V_217 ;
int V_70 ;
if ( V_194 >= V_197 )
return - V_218 ;
if ( V_5 -> V_13 [ V_194 ] . V_81 == 0 )
return 0 ;
V_217 = F_3 ( V_5 , V_194 ) ;
F_15 ( V_115 -> V_104 , L_39 ,
V_105 , V_194 , V_217 ? L_40 : L_41 ,
V_5 -> V_13 [ V_194 ] . V_81 ) ;
F_56 ( V_5 , V_194 ) ;
if ( V_217 ) {
F_57 . V_198 = F_13 ( sizeof( F_57 ) ) ;
F_57 . V_194 = F_13 ( V_194 ) ;
if ( V_141 ) {
if ( ! F_54 ( V_141 ) )
F_57 . V_194 |=
V_210 ;
memcpy ( F_57 . V_141 , V_141 ,
sizeof( F_57 . V_141 ) ) ;
} else
memset ( F_57 . V_141 , 0xff ,
sizeof( F_57 . V_141 ) ) ;
V_70 = F_18 ( V_115 ,
V_54 ,
& F_57 , sizeof( F_57 ) ) ;
if ( V_70 != 0 )
return V_70 ;
} else {
V_216 = F_13 ( V_194 ) ;
V_70 = F_18 ( V_115 ,
V_47 ,
& V_216 , sizeof( V_216 ) ) ;
if ( V_70 != 0 ) {
F_28 ( V_115 -> V_104 ,
L_42 ,
V_194 , V_70 ) ;
return V_70 ;
}
}
if ( V_194 == V_5 -> V_200 )
F_41 ( V_115 , V_16 , V_16 ) ;
return 0 ;
}
static void F_58 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_219 * V_220 ;
T_3 V_221 , V_222 ;
int V_70 ;
char * V_223 = NULL ;
int V_224 ;
V_222 = V_221 = F_13 ( V_225 |
V_226 ) ;
if ( V_115 -> V_104 -> V_205 & V_227 ) {
V_221 |= F_13 ( V_228 |
V_229 ) ;
} else if ( V_115 -> V_104 -> V_205 & V_230 ) {
V_221 |= F_13 ( V_231 ) ;
}
if ( V_221 != V_222 )
goto V_232;
F_59 ( V_115 -> V_104 ) ;
V_224 = F_60 ( V_115 -> V_104 ) ;
if ( V_224 > V_5 -> V_233 ) {
V_221 |= F_13 ( V_231 ) ;
} else if ( V_224 ) {
int V_126 = 0 ;
V_223 = F_61 ( V_224 , V_142 , V_234 ) ;
if ( ! V_223 ) {
F_62 ( V_115 -> V_104 ) ;
return;
}
F_63 (ha, usbdev->net)
memcpy ( V_223 + V_126 ++ * V_142 ,
V_220 -> V_202 , V_142 ) ;
}
F_62 ( V_115 -> V_104 ) ;
if ( V_221 != V_222 )
goto V_232;
if ( V_224 ) {
V_70 = F_18 ( V_115 ,
V_41 ,
V_223 , V_224 * V_142 ) ;
F_17 ( V_223 ) ;
if ( V_70 == 0 )
V_221 |= F_13 ( V_235 ) ;
else
V_221 |= F_13 ( V_231 ) ;
F_15 ( V_115 -> V_104 , L_43 ,
V_224 , V_5 -> V_233 , V_70 ) ;
}
V_232:
V_70 = F_18 ( V_115 , V_31 , & V_221 ,
sizeof( V_221 ) ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_44 ,
F_9 ( V_221 ) ) ;
}
F_15 ( V_115 -> V_104 , L_45 ,
F_9 ( V_221 ) , V_70 ) ;
}
static void F_64 ( struct V_2 * V_115 ,
struct V_236 * V_237 ,
const char * V_238 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_126 , V_81 , V_239 , V_240 , V_241 ;
V_240 = V_5 -> V_190 . V_191 -> V_242 ;
V_81 = F_9 ( V_237 -> V_148 ) ;
V_239 = F_9 ( V_237 -> V_243 ) ;
V_241 = ( V_239 > 0 ) ? ( V_81 - sizeof( * V_237 ) ) / V_239 : - 1 ;
F_15 ( V_115 -> V_104 , L_46
L_47 , V_238 , V_239 , V_81 , V_241 ) ;
if ( V_239 > V_240 )
V_239 = V_240 ;
for ( V_126 = 0 ; V_126 < V_239 ; V_126 ++ ) {
T_1 * V_133 = ( T_1 * ) V_237 -> V_244 [ V_126 ] . V_245 ;
F_15 ( V_115 -> V_104 , L_48
L_49 ,
V_238 , V_237 -> V_244 [ V_126 ] . V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
}
}
static void F_64 ( struct V_2 * V_115 ,
struct V_236 * V_237 ,
const char * V_238 )
{
return;
}
static struct V_236 * F_65 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_236 * V_237 ;
int V_81 , V_70 , V_240 ;
V_240 = V_5 -> V_190 . V_191 -> V_242 ;
V_81 = sizeof( * V_237 ) + V_240 * sizeof( V_237 -> V_244 [ 0 ] ) ;
V_237 = F_66 ( V_81 , V_96 ) ;
if ( ! V_237 )
return F_67 ( - V_97 ) ;
V_237 -> V_148 = F_13 ( V_81 ) ;
V_237 -> V_243 = F_13 ( V_240 ) ;
V_70 = F_10 ( V_115 , V_57 ,
V_237 , & V_81 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_50
L_51 , V_105 , V_81 , V_240 , V_70 ) ;
F_17 ( V_237 ) ;
return F_67 ( V_70 ) ;
}
if ( F_9 ( V_237 -> V_243 ) > V_240 )
V_237 -> V_243 = F_13 ( V_240 ) ;
F_64 ( V_115 , V_237 , V_105 ) ;
return V_237 ;
}
static int F_68 ( struct V_2 * V_115 ,
struct V_236 * V_237 )
{
int V_70 , V_81 , V_246 ;
V_246 = F_9 ( V_237 -> V_243 ) ;
V_81 = sizeof( * V_237 ) + V_246 * sizeof( V_237 -> V_244 [ 0 ] ) ;
V_237 -> V_148 = F_13 ( V_81 ) ;
F_64 ( V_115 , V_237 , V_105 ) ;
V_70 = F_18 ( V_115 , V_57 , V_237 ,
F_9 ( V_237 -> V_148 ) ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_52
L_53 , V_105 , V_81 , V_246 , V_70 ) ;
}
F_17 ( V_237 ) ;
return V_70 ;
}
static struct V_236 * F_69 ( struct V_2 * V_115 ,
struct V_236 * V_237 ,
struct V_247 * V_248 ,
int V_240 )
{
int V_126 , V_249 , V_250 ;
unsigned int V_239 ;
V_239 = F_9 ( V_237 -> V_243 ) ;
if ( V_239 > V_240 )
V_239 = V_240 ;
for ( V_126 = 0 ; V_126 < V_239 ; V_126 ++ )
if ( F_70 ( V_237 -> V_244 [ V_126 ] . V_141 ,
V_248 -> V_141 ) )
break;
if ( V_126 == V_239 ) {
F_15 ( V_115 -> V_104 , L_54 ,
V_105 , V_248 -> V_141 ) ;
V_250 = - V_218 ;
goto error;
}
for (; V_126 + 1 < V_239 ; V_126 ++ )
V_237 -> V_244 [ V_126 ] = V_237 -> V_244 [ V_126 + 1 ] ;
V_239 -- ;
V_249 = sizeof( * V_237 ) + V_239 * sizeof( V_237 -> V_244 [ 0 ] ) ;
V_237 -> V_148 = F_13 ( V_249 ) ;
V_237 -> V_243 = F_13 ( V_239 ) ;
return V_237 ;
error:
F_17 ( V_237 ) ;
return F_67 ( V_250 ) ;
}
static struct V_236 * F_71 ( struct V_2 * V_115 ,
struct V_236 * V_237 ,
struct V_247 * V_248 ,
int V_240 )
{
struct V_236 * V_251 ;
int V_126 , V_250 , V_249 ;
unsigned int V_239 ;
V_239 = F_9 ( V_237 -> V_243 ) ;
if ( V_239 > V_240 )
V_239 = V_240 ;
for ( V_126 = 0 ; V_126 < V_239 ; V_126 ++ ) {
if ( ! F_70 ( V_237 -> V_244 [ V_126 ] . V_141 ,
V_248 -> V_141 ) )
continue;
memcpy ( V_237 -> V_244 [ V_126 ] . V_245 , V_248 -> V_245 ,
V_252 ) ;
return V_237 ;
}
if ( V_126 == V_240 ) {
F_15 ( V_115 -> V_104 , L_55 , V_105 ) ;
V_250 = - V_253 ;
goto error;
}
V_249 = sizeof( * V_237 ) + ( V_239 + 1 ) * sizeof( V_237 -> V_244 [ 0 ] ) ;
V_251 = F_72 ( V_237 , V_249 , V_96 ) ;
if ( ! V_251 ) {
V_250 = - V_97 ;
goto error;
}
V_237 = V_251 ;
V_237 -> V_148 = F_13 ( V_249 ) ;
V_237 -> V_243 = F_13 ( V_239 + 1 ) ;
memcpy ( V_237 -> V_244 [ V_239 ] . V_141 , V_248 -> V_141 , V_142 ) ;
memcpy ( V_237 -> V_244 [ V_239 ] . V_245 , V_248 -> V_245 , V_252 ) ;
return V_237 ;
error:
F_17 ( V_237 ) ;
return F_67 ( V_250 ) ;
}
static int F_73 ( struct V_191 * V_191 ,
struct V_254 * V_3 ,
enum V_255 type , T_1 * V_205 ,
struct V_256 * V_257 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_178 ;
switch ( type ) {
case V_258 :
V_178 = V_212 ;
break;
case V_259 :
V_178 = V_147 ;
break;
default:
return - V_71 ;
}
V_5 -> V_190 . V_260 = type ;
return F_37 ( V_115 , V_178 ) ;
}
static int F_75 ( struct V_191 * V_191 , T_1 V_261 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_250 ;
if ( V_261 & V_262 ) {
V_250 = F_44 ( V_115 , V_191 -> V_181 ) ;
if ( V_250 < 0 )
return V_250 ;
}
if ( V_261 & V_263 ) {
V_250 = F_43 ( V_115 , V_191 -> V_180 ) ;
if ( V_250 < 0 )
return V_250 ;
}
return 0 ;
}
static int F_76 ( struct V_191 * V_191 ,
struct V_264 * V_190 ,
enum V_265 type ,
int V_266 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_15 ( V_115 -> V_104 , L_56 ,
V_105 , type , V_266 ) ;
if ( V_266 < 0 || ( V_266 % 100 ) )
return - V_168 ;
if ( type == V_267 ||
F_77 ( V_266 ) == F_2 ( V_5 ) ) {
if ( ! V_5 -> V_140 )
F_35 ( V_115 , true ) ;
return 0 ;
}
return - V_168 ;
}
static int F_78 ( struct V_191 * V_191 ,
struct V_264 * V_190 ,
int * V_268 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
* V_268 = F_2 ( V_5 ) ;
F_15 ( V_115 -> V_104 , L_57 , V_105 , * V_268 ) ;
return 0 ;
}
static int F_79 ( struct V_191 * V_191 ,
struct V_269 * V_270 )
{
struct V_254 * V_3 = V_270 -> V_190 -> V_271 ;
struct V_2 * V_115 = F_80 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_70 ;
int V_272 = V_273 ;
F_15 ( V_115 -> V_104 , L_58 ) ;
F_81 ( V_115 , NULL , NULL ) ;
if ( V_5 -> V_274 && V_5 -> V_274 != V_270 )
return - V_79 ;
V_5 -> V_274 = V_270 ;
V_70 = F_26 ( V_115 ) ;
if ( V_70 == 0 ) {
if ( V_5 -> V_275 == V_276 )
V_272 = V_277 ;
F_82 ( V_5 -> V_278 , & V_5 -> V_279 , V_272 ) ;
}
return V_70 ;
}
static bool F_83 ( struct V_2 * V_115 ,
struct V_280 * V_141 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_188 * V_182 ;
struct V_281 * V_282 ;
T_5 signal ;
T_6 V_283 ;
T_7 V_284 ;
T_7 V_285 ;
struct V_286 * V_287 ;
int V_288 , V_289 ;
T_2 * V_290 ;
F_15 ( V_115 -> V_104 , L_59 ,
V_141 -> V_139 . V_149 , V_141 -> V_291 , F_9 ( V_141 -> V_148 ) ) ;
V_289 = F_9 ( V_141 -> V_148 ) ;
if ( V_289 < sizeof( struct V_280 ) +
sizeof( struct V_286 ) )
return NULL ;
V_287 = (struct V_286 * ) V_141 -> V_292 ;
V_290 = ( void * ) ( V_141 -> V_292 + sizeof( struct V_286 ) ) ;
V_288 = F_84 ( V_289 - ( int ) sizeof( * V_141 ) ,
( int ) F_9 ( V_141 -> V_293 ) ) ;
V_288 -= sizeof( struct V_286 ) ;
if ( V_288 < 0 )
return NULL ;
V_182 = F_50 ( V_5 -> V_190 . V_191 ,
F_51 ( F_9 ( V_141 -> V_184 . V_187 ) ) ) ;
if ( ! V_182 )
return NULL ;
signal = F_25 ( F_9 ( V_141 -> V_294 ) ) ;
V_283 = F_85 ( * ( V_295 * ) V_287 -> V_283 ) ;
V_284 = F_86 ( V_287 -> V_296 ) ;
V_285 = F_86 ( V_287 -> V_285 ) ;
V_282 = F_87 ( V_5 -> V_190 . V_191 , V_182 , V_141 -> V_291 ,
V_283 , V_284 , V_285 , V_290 , V_288 , signal ,
V_96 ) ;
F_88 ( V_5 -> V_190 . V_191 , V_282 ) ;
return ( V_282 != NULL ) ;
}
static struct V_280 * F_89 (
struct V_280 * V_141 ,
int * V_289 , void * V_82 , int V_81 )
{
void * V_297 , * V_298 ;
V_297 = ( char * ) V_82 + V_81 ;
V_298 = ( char * ) V_141 + * V_289 ;
if ( ( int ) ( V_297 - V_298 ) < sizeof( V_141 -> V_148 ) ) {
* V_289 = 0 ;
return NULL ;
} else {
V_141 = ( void * ) ( ( char * ) V_141 + * V_289 ) ;
* V_289 = F_9 ( V_141 -> V_148 ) ;
return V_141 ;
}
}
static bool F_90 ( struct V_280 * V_141 ,
int V_289 , void * V_82 , int V_81 )
{
void * V_297 , * V_298 ;
if ( ! V_141 || V_289 <= 0 || V_289 > V_81 )
return false ;
V_297 = ( char * ) V_82 + V_81 ;
V_298 = ( char * ) V_141 + V_289 ;
return ( int ) ( V_297 - V_298 ) >= 0 && ( int ) ( V_298 - V_82 ) >= 0 ;
}
static int F_81 ( struct V_2 * V_115 , T_2 * V_299 ,
bool * V_300 )
{
void * V_82 = NULL ;
struct V_301 * V_302 ;
struct V_280 * V_141 ;
int V_70 = - V_71 , V_81 , V_239 , V_289 , V_303 , V_304 ;
F_15 ( V_115 -> V_104 , L_60 , V_105 ) ;
V_81 = V_94 ;
V_305:
V_82 = F_66 ( V_81 , V_96 ) ;
if ( ! V_82 ) {
V_70 = - V_97 ;
goto V_306;
}
V_304 = V_81 ;
V_70 = F_10 ( V_115 , V_68 ,
V_82 , & V_304 ) ;
if ( V_70 != 0 || V_304 < sizeof( struct V_301 ) )
goto V_306;
if ( V_304 > V_81 ) {
V_81 = V_304 ;
F_17 ( V_82 ) ;
goto V_305;
}
V_81 = V_304 ;
V_302 = V_82 ;
V_239 = F_9 ( V_302 -> V_307 ) ;
V_303 = 0 ;
F_15 ( V_115 -> V_104 , L_61 , V_105 , V_81 ) ;
V_289 = 0 ;
V_141 = F_89 ( V_302 -> V_141 , & V_289 , V_82 , V_81 ) ;
while ( F_90 ( V_141 , V_289 , V_82 , V_81 ) ) {
if ( F_83 ( V_115 , V_141 ) && V_299 &&
V_300 ) {
if ( F_70 ( V_141 -> V_291 , V_299 ) )
* V_300 = true ;
}
V_303 ++ ;
V_141 = F_89 ( V_141 , & V_289 , V_82 , V_81 ) ;
}
F_15 ( V_115 -> V_104 , L_62
L_63 , V_105 , V_239 , V_303 ) ;
V_306:
F_17 ( V_82 ) ;
return V_70 ;
}
static void F_91 ( struct V_308 * V_309 )
{
struct V_1 * V_5 =
F_92 ( V_309 , struct V_1 , V_279 . V_309 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_70 ;
F_15 ( V_115 -> V_104 , L_64 ) ;
if ( ! V_5 -> V_274 )
return;
V_70 = F_81 ( V_115 , NULL , NULL ) ;
F_93 ( V_5 -> V_274 , V_70 < 0 ) ;
V_5 -> V_274 = NULL ;
}
static int F_94 ( struct V_191 * V_191 , struct V_254 * V_3 ,
struct V_310 * V_311 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_188 * V_182 = V_311 -> V_182 ;
struct V_138 V_139 ;
int V_171 = V_16 ;
int V_172 = V_16 ;
int V_153 = V_23 ;
int V_148 , V_126 , V_70 , V_312 = - 1 ;
if ( V_182 )
V_312 = F_95 ( V_182 -> V_313 ) ;
V_172 = F_4 ( V_311 -> V_314 . V_315 ) ;
for ( V_126 = 0 ; V_126 < V_311 -> V_314 . V_316 ; V_126 ++ )
V_171 |=
F_4 ( V_311 -> V_314 . V_317 [ V_126 ] ) ;
if ( V_311 -> V_314 . V_316 > 0 &&
V_171 == V_16 ) {
F_96 ( V_115 -> V_104 , L_65 ) ;
return - V_168 ;
}
for ( V_126 = 0 ; V_126 < V_311 -> V_314 . V_318 ; V_126 ++ )
V_153 |=
F_5 ( V_311 -> V_314 . V_319 [ V_126 ] ) ;
if ( V_311 -> V_314 . V_318 > 0 &&
V_153 == V_23 ) {
F_96 ( V_115 -> V_104 , L_66 ) ;
return - V_168 ;
}
F_15 ( V_115 -> V_104 , L_67 ,
V_311 -> V_139 , V_311 -> V_141 , V_312 ,
V_311 -> V_320 , V_311 -> V_314 . V_321 , V_311 -> V_152 ,
V_172 , V_171 , V_153 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_147 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_68 ,
V_70 ) ;
goto V_322;
}
V_70 = F_39 ( V_115 , V_311 -> V_314 . V_321 , V_311 -> V_152 ,
V_153 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_69 ,
V_70 ) ;
goto V_322;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_171 , V_172 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_70 ,
V_70 ) ;
goto V_322;
}
if ( V_182 ) {
V_70 = F_47 ( V_115 , V_312 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_71 ,
V_70 ) ;
goto V_322;
}
}
if ( V_311 -> V_192 && ( ( V_172 | V_171 ) & V_19 ) ) {
V_5 -> V_200 = V_311 -> V_213 ;
V_70 = F_52 ( V_115 , V_311 -> V_192 , V_311 -> V_193 , V_311 -> V_213 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_72 ,
V_70 , V_311 -> V_193 , V_311 -> V_213 ) ;
goto V_322;
}
}
if ( V_311 -> V_141 && ! F_34 ( V_311 -> V_141 ) &&
! F_54 ( V_311 -> V_141 ) ) {
V_70 = F_29 ( V_115 , V_311 -> V_141 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_73 ,
V_70 ) ;
goto V_322;
}
} else
F_30 ( V_115 ) ;
V_148 = V_311 -> V_323 ;
if ( V_148 > V_324 )
V_148 = V_324 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_148 = F_13 ( V_148 ) ;
memcpy ( V_139 . V_149 , V_311 -> V_139 , V_148 ) ;
F_97 ( V_115 ) ;
F_98 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_139 ) ;
if ( V_70 < 0 )
F_15 ( V_115 -> V_104 , L_74 , V_70 ) ;
return V_70 ;
V_322:
F_35 ( V_115 , true ) ;
return V_70 ;
}
static int F_99 ( struct V_191 * V_191 , struct V_254 * V_3 ,
T_7 V_325 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_15 ( V_115 -> V_104 , L_75 , V_325 ) ;
V_5 -> V_326 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
return F_46 ( V_115 ) ;
}
static int F_100 ( struct V_191 * V_191 , struct V_254 * V_3 ,
struct V_327 * V_257 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_188 * V_182 = V_257 -> V_328 . V_312 ;
struct V_138 V_139 ;
enum V_151 V_152 ;
int V_70 , V_329 , V_148 , V_312 = - 1 ;
if ( V_182 )
V_312 = F_95 ( V_182 -> V_313 ) ;
if ( V_257 -> V_320 ) {
V_152 = V_162 ;
V_329 = V_19 ;
} else {
V_152 = V_164 ;
V_329 = V_16 ;
}
F_15 ( V_115 -> V_104 , L_76 ,
V_257 -> V_139 , V_257 -> V_141 , V_312 , V_257 -> V_320 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_212 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_77 ,
V_70 ) ;
goto V_322;
}
V_70 = F_39 ( V_115 , 0 , V_152 , V_23 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_78 ,
V_70 ) ;
goto V_322;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_329 , V_16 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_79 ,
V_70 ) ;
goto V_322;
}
if ( V_182 ) {
V_70 = F_47 ( V_115 , V_312 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_80 ,
V_70 ) ;
goto V_322;
}
}
if ( V_257 -> V_141 && ! F_34 ( V_257 -> V_141 ) &&
! F_54 ( V_257 -> V_141 ) ) {
V_70 = F_29 ( V_115 , V_257 -> V_141 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_81 ,
V_70 ) ;
goto V_322;
}
} else
F_30 ( V_115 ) ;
V_148 = V_257 -> V_323 ;
if ( V_148 > V_324 )
V_148 = V_324 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_148 = F_13 ( V_148 ) ;
memcpy ( V_139 . V_149 , V_257 -> V_139 , V_148 ) ;
F_98 ( V_115 ) ;
F_101 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_139 ) ;
if ( V_70 < 0 )
F_15 ( V_115 -> V_104 , L_82 ,
V_70 ) ;
return V_70 ;
V_322:
F_35 ( V_115 , true ) ;
return V_70 ;
}
static int F_102 ( struct V_191 * V_191 , struct V_254 * V_3 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_15 ( V_115 -> V_104 , L_83 ) ;
V_5 -> V_326 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
return F_46 ( V_115 ) ;
}
static int F_103 ( struct V_191 * V_191 , struct V_254 * V_271 ,
T_2 V_330 , bool V_171 , const T_2 * V_331 ,
struct V_332 * V_257 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_3 V_205 ;
F_15 ( V_115 -> V_104 , L_84 ,
V_105 , V_330 , V_331 , V_257 -> V_12 ) ;
switch ( V_257 -> V_12 ) {
case V_17 :
case V_18 :
return F_52 ( V_115 , V_257 -> V_192 , V_257 -> V_193 ,
V_330 ) ;
case V_15 :
case V_14 :
V_205 = 0 ;
if ( V_257 -> V_333 && V_257 -> V_204 > 0 )
V_205 |= V_208 ;
if ( V_331 )
V_205 |= V_210 |
V_211 ;
return F_53 ( V_115 , V_257 -> V_192 , V_257 -> V_193 ,
V_330 , V_331 , V_257 -> V_333 ,
V_257 -> V_204 , V_257 -> V_12 , V_205 ) ;
default:
F_15 ( V_115 -> V_104 , L_85 ,
V_105 , V_257 -> V_12 ) ;
return - V_168 ;
}
}
static int F_104 ( struct V_191 * V_191 , struct V_254 * V_271 ,
T_2 V_330 , bool V_171 , const T_2 * V_331 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_15 ( V_115 -> V_104 , L_86 , V_105 , V_330 , V_331 ) ;
return F_57 ( V_115 , V_330 , V_331 ) ;
}
static int F_105 ( struct V_191 * V_191 , struct V_254 * V_271 ,
T_2 V_330 , bool V_334 , bool V_335 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_214 V_192 ;
F_15 ( V_115 -> V_104 , L_87 , V_105 , V_330 ) ;
if ( V_330 >= V_197 )
return - V_218 ;
V_5 -> V_200 = V_330 ;
if ( F_3 ( V_5 , V_330 ) )
return 0 ;
V_192 = V_5 -> V_13 [ V_330 ] ;
return F_52 ( V_115 , V_192 . V_199 , V_192 . V_81 , V_330 ) ;
}
static void F_106 ( struct V_2 * V_115 ,
struct V_336 * V_337 )
{
T_3 V_338 , V_294 ;
int V_70 , V_81 ;
memset ( V_337 , 0 , sizeof( * V_337 ) ) ;
V_81 = sizeof( V_338 ) ;
V_70 = F_10 ( V_115 , V_33 , & V_338 , & V_81 ) ;
if ( V_70 == 0 ) {
V_337 -> V_339 . V_340 = F_9 ( V_338 ) / 1000 ;
V_337 -> V_341 |= V_342 ;
}
V_81 = sizeof( V_294 ) ;
V_70 = F_10 ( V_115 , V_61 ,
& V_294 , & V_81 ) ;
if ( V_70 == 0 ) {
V_337 -> signal = F_25 ( F_9 ( V_294 ) ) ;
V_337 -> V_341 |= V_343 ;
}
}
static int F_107 ( struct V_191 * V_191 , struct V_254 * V_3 ,
T_2 * V_291 , struct V_336 * V_337 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( ! F_70 ( V_5 -> V_141 , V_291 ) )
return - V_218 ;
F_106 ( V_115 , V_337 ) ;
return 0 ;
}
static int F_108 ( struct V_191 * V_191 , struct V_254 * V_3 ,
int V_11 , T_2 * V_291 , struct V_336 * V_337 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( V_11 != 0 )
return - V_218 ;
memcpy ( V_291 , V_5 -> V_141 , V_142 ) ;
F_106 ( V_115 , V_337 ) ;
return 0 ;
}
static int F_109 ( struct V_191 * V_191 , struct V_254 * V_271 ,
struct V_247 * V_248 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_236 * V_237 ;
T_1 * V_133 = ( T_1 * ) V_248 -> V_245 ;
F_15 ( V_115 -> V_104 , L_88 , V_105 ,
V_248 -> V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
V_237 = F_65 ( V_115 ) ;
if ( F_110 ( V_237 ) ) {
return F_111 ( V_237 ) ;
}
V_237 = F_71 ( V_115 , V_237 , V_248 , V_191 -> V_242 ) ;
if ( F_110 ( V_237 ) ) {
return F_111 ( V_237 ) ;
}
return F_68 ( V_115 , V_237 ) ;
}
static int F_112 ( struct V_191 * V_191 , struct V_254 * V_271 ,
struct V_247 * V_248 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_236 * V_237 ;
T_1 * V_133 = ( T_1 * ) V_248 -> V_245 ;
F_15 ( V_115 -> V_104 , L_88 , V_105 ,
V_248 -> V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
V_237 = F_65 ( V_115 ) ;
if ( F_110 ( V_237 ) ) {
return F_111 ( V_237 ) ;
}
V_237 = F_69 ( V_115 , V_237 , V_248 , V_191 -> V_242 ) ;
if ( F_110 ( V_237 ) ) {
return F_111 ( V_237 ) ;
}
return F_68 ( V_115 , V_237 ) ;
}
static int F_113 ( struct V_191 * V_191 , struct V_254 * V_271 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_236 V_245 ;
F_15 ( V_115 -> V_104 , L_60 , V_105 ) ;
memset ( & V_245 , 0 , sizeof( V_245 ) ) ;
V_245 . V_148 = F_13 ( sizeof( V_245 ) ) ;
V_245 . V_243 = F_13 ( 0 ) ;
return F_18 ( V_115 , V_57 ,
& V_245 , sizeof( V_245 ) ) ;
}
static int F_114 ( struct V_191 * V_191 , struct V_254 * V_3 ,
bool V_344 , int V_345 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_346 ;
T_3 V_178 ;
int V_70 ;
if ( V_5 -> V_275 != V_347 )
return - V_168 ;
F_15 ( V_115 -> V_104 , L_89 , V_105 ,
V_344 ? L_90 : L_91 ,
V_345 ) ;
if ( V_344 )
V_346 = V_348 ;
else
V_346 = V_349 ;
if ( V_346 == V_5 -> V_346 )
return 0 ;
V_5 -> V_346 = V_346 ;
V_178 = F_13 ( V_346 ) ;
V_70 = F_18 ( V_115 , V_67 ,
& V_178 , sizeof( V_178 ) ) ;
F_15 ( V_115 -> V_104 , L_92 ,
V_105 , V_70 ) ;
return V_70 ;
}
static int F_115 ( struct V_191 * V_191 ,
struct V_254 * V_3 ,
T_5 V_350 , T_1 V_351 )
{
struct V_1 * V_5 = F_74 ( V_191 ) ;
V_5 -> V_352 = V_350 ;
V_5 -> V_353 = V_351 ;
V_5 -> V_354 = 0 ;
return 0 ;
}
static void F_116 ( struct V_2 * V_115 , T_2 * V_141 ,
struct V_144 * V_145 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_188 * V_182 ;
struct V_138 V_139 ;
struct V_281 * V_282 ;
T_5 signal ;
T_6 V_283 ;
T_7 V_284 ;
T_1 V_189 = 0 ;
T_3 V_294 ;
T_2 V_355 [ 34 ] ;
int V_81 , V_70 , V_288 ;
V_81 = sizeof( V_294 ) ;
V_294 = 0 ;
V_70 = F_10 ( V_115 , V_61 ,
& V_294 , & V_81 ) ;
signal = F_25 ( F_9 ( V_294 ) ) ;
F_15 ( V_115 -> V_104 , L_93
L_94 , V_105 , V_70 , F_9 ( V_294 ) ,
F_25 ( F_9 ( V_294 ) ) ) ;
if ( V_145 ) {
V_284 = F_86 ( V_145 -> V_356 . V_357 ) ;
} else {
V_284 = ( V_5 -> V_179 == V_147 ) ?
V_358 : V_359 ;
}
V_182 = F_49 ( V_115 , & V_189 ) ;
if ( ! V_182 ) {
F_28 ( V_115 -> V_104 , L_95 ,
V_105 ) ;
return;
}
V_81 = sizeof( V_139 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_70 = F_10 ( V_115 , V_44 ,
& V_139 , & V_81 ) ;
F_15 ( V_115 -> V_104 , L_96
L_97 , V_105 , V_70 ,
F_9 ( V_139 . V_148 ) , V_139 . V_149 ) ;
if ( F_9 ( V_139 . V_148 ) > 32 )
V_139 . V_148 = F_13 ( 32 ) ;
V_355 [ 0 ] = V_360 ;
V_355 [ 1 ] = F_9 ( V_139 . V_148 ) ;
memcpy ( & V_355 [ 2 ] , V_139 . V_149 , F_9 ( V_139 . V_148 ) ) ;
V_288 = F_9 ( V_139 . V_148 ) + 2 ;
V_283 = 0 ;
F_15 ( V_115 -> V_104 , L_98
L_99
L_100 , V_105 , ( V_182 ? V_182 -> V_313 : - 1 ) ,
V_141 , ( T_1 ) V_283 , V_284 , V_189 , V_288 ,
V_139 . V_149 , signal ) ;
V_282 = F_87 ( V_5 -> V_190 . V_191 , V_182 , V_141 ,
V_283 , V_284 , V_189 , V_355 , V_288 ,
signal , V_96 ) ;
F_88 ( V_5 -> V_190 . V_191 , V_282 ) ;
}
static void F_117 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_144 * V_145 = NULL ;
T_2 V_141 [ V_142 ] ;
unsigned int V_361 , V_362 ;
unsigned int V_107 ;
T_2 * V_363 , * V_356 ;
int V_70 ;
bool V_364 = false ;
bool V_365 ;
if ( V_5 -> V_179 == V_147 && V_5 -> V_326 ) {
V_364 = true ;
}
V_362 = 0 ;
V_361 = 0 ;
V_363 = NULL ;
V_356 = NULL ;
if ( V_5 -> V_179 == V_147 ) {
V_145 = F_66 ( V_94 , V_96 ) ;
if ( ! V_145 ) {
F_118 ( V_366 , & V_5 -> V_367 ) ;
F_119 ( V_5 -> V_278 , & V_5 -> V_309 ) ;
return;
}
V_70 = F_32 ( V_115 , V_145 , V_94 ) ;
if ( ! V_70 ) {
V_362 = F_9 ( V_145 -> V_368 ) ;
if ( V_362 > V_94 )
V_362 = V_94 ;
if ( V_362 != 0 ) {
V_107 = F_9 ( V_145 -> V_369 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_363 = ( T_2 * ) V_145 + V_107 ;
if ( V_107 + V_362 > V_94 )
V_362 =
V_94 - V_107 ;
}
V_361 = F_9 ( V_145 -> V_370 ) ;
if ( V_361 > V_94 )
V_361 = V_94 ;
if ( V_361 != 0 ) {
V_107 = F_9 ( V_145 -> V_371 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_356 = ( T_2 * ) V_145 + V_107 ;
if ( V_107 + V_361 > V_94 )
V_361 =
V_94 - V_107 ;
}
} else {
F_17 ( V_145 ) ;
V_145 = NULL ;
}
} else if ( F_120 ( V_5 -> V_179 != V_212 ) )
return;
V_70 = F_31 ( V_115 , V_141 ) ;
if ( V_70 < 0 )
memset ( V_141 , 0 , sizeof( V_141 ) ) ;
F_15 ( V_115 -> V_104 , L_101 ,
V_141 , V_364 ? L_102 : L_103 ) ;
V_365 = false ;
F_81 ( V_115 , V_141 , & V_365 ) ;
if ( ! F_34 ( V_141 ) && ! V_365 ) {
F_116 ( V_115 , V_141 , V_145 ) ;
}
if ( V_5 -> V_179 == V_147 ) {
if ( ! V_364 )
F_121 ( V_115 -> V_104 , V_141 , V_363 ,
V_362 , V_356 ,
V_361 , 0 , V_96 ) ;
else
F_122 ( V_115 -> V_104 ,
F_49 ( V_115 , NULL ) ,
V_141 , V_363 , V_362 ,
V_356 , V_361 , V_96 ) ;
} else if ( V_5 -> V_179 == V_212 )
F_123 ( V_115 -> V_104 , V_141 ,
F_49 ( V_115 , NULL ) ,
V_96 ) ;
F_17 ( V_145 ) ;
V_5 -> V_326 = true ;
memcpy ( V_5 -> V_141 , V_141 , V_142 ) ;
F_101 ( V_115 ) ;
F_124 ( V_115 -> V_104 ) ;
}
static void F_125 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( V_5 -> V_326 ) {
V_5 -> V_326 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
F_46 ( V_115 ) ;
F_126 ( V_115 -> V_104 , 0 , NULL , 0 , V_96 ) ;
}
F_127 ( V_115 -> V_104 ) ;
}
static void F_128 ( struct V_308 * V_309 )
{
struct V_1 * V_5 =
F_92 ( V_309 , struct V_1 , V_309 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( F_129 ( V_366 , & V_5 -> V_367 ) )
F_117 ( V_115 ) ;
if ( F_129 ( V_372 , & V_5 -> V_367 ) )
F_125 ( V_115 ) ;
if ( F_129 ( V_373 , & V_5 -> V_367 ) )
F_58 ( V_115 ) ;
}
static void F_130 ( struct V_254 * V_3 )
{
struct V_2 * V_115 = F_80 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( F_131 ( V_373 , & V_5 -> V_367 ) )
return;
F_118 ( V_373 , & V_5 -> V_367 ) ;
F_119 ( V_5 -> V_278 , & V_5 -> V_309 ) ;
}
static void F_132 ( struct V_2 * V_115 ,
struct V_374 * V_375 ,
int V_81 )
{
T_2 * V_82 ;
const char * type ;
int V_205 , V_90 , V_376 ;
bool V_377 , V_378 ;
struct V_379 * V_380 ;
enum V_381 V_382 ;
if ( V_81 < F_133 ( struct V_374 , V_89 ) +
sizeof( struct V_379 ) ) {
F_134 ( V_115 -> V_104 , L_104 ,
V_81 ) ;
return;
}
V_82 = ( void * ) & V_375 -> V_89 . V_383 [ 0 ] ;
V_90 = V_81 - F_133 ( struct V_374 , V_89 ) ;
while ( V_90 >= sizeof( * V_380 ) ) {
V_380 = ( void * ) V_82 ;
type = L_105 ;
V_205 = F_9 ( V_380 -> V_205 ) ;
V_377 = false ;
V_378 = false ;
if ( V_205 & 0x1 )
type = L_106 ;
if ( V_205 & 0x2 )
type = L_107 ;
if ( V_205 & 0x6 ) {
V_377 = true ;
type = L_108 ;
}
if ( V_205 & 0xe ) {
V_378 = true ;
type = L_109 ;
}
F_134 ( V_115 -> V_104 , L_110 ,
type , F_9 ( V_380 -> V_205 ) ) ;
if ( V_377 ) {
V_382 = V_384 ;
V_376 = - 1 ;
F_135 ( V_115 -> V_104 ,
V_380 -> V_141 ,
V_382 , V_376 , NULL ,
V_96 ) ;
}
if ( V_378 ) {
V_382 = V_385 ;
V_376 = - 1 ;
F_135 ( V_115 -> V_104 ,
V_380 -> V_141 ,
V_382 , V_376 , NULL ,
V_96 ) ;
}
V_90 -= F_9 ( V_380 -> V_148 ) ;
V_82 += F_9 ( V_380 -> V_148 ) ;
}
}
static void F_136 ( struct V_2 * V_115 ,
struct V_374 * V_375 ,
int V_81 )
{
struct V_386 * V_387 ;
int V_388 , V_389 , V_126 ;
if ( V_81 < F_133 ( struct V_374 , V_89 ) +
sizeof( struct V_386 ) ) {
F_134 ( V_115 -> V_104 , L_111 ,
V_81 ) ;
return;
}
V_388 = F_9 ( V_375 -> V_89 . V_387 . V_390 ) *
sizeof( struct V_391 ) ;
V_389 = sizeof( struct V_386 ) + V_388 +
F_133 ( struct V_374 , V_89 ) ;
if ( V_81 < V_389 ) {
F_134 ( V_115 -> V_104 , L_112 ,
V_81 , V_389 ) ;
return;
}
V_387 = & V_375 -> V_89 . V_387 ;
F_134 ( V_115 -> V_104 , L_113 ,
F_9 ( V_387 -> V_392 ) ,
F_9 ( V_387 -> V_390 ) ) ;
if ( F_9 ( V_387 -> V_392 ) != 1 )
return;
for ( V_126 = 0 ; V_126 < F_9 ( V_387 -> V_390 ) ; V_126 ++ ) {
struct V_391 * V_393 =
& V_387 -> V_394 [ V_126 ] ;
bool V_395 = ! ! ( V_393 -> V_205 & V_396 ) ;
F_15 ( V_115 -> V_104 , L_114 ,
V_126 , F_9 ( V_393 -> V_205 ) , V_395 , V_393 -> V_141 ) ;
F_137 ( V_115 -> V_104 , V_126 , V_393 -> V_141 ,
V_395 , V_234 ) ;
}
}
static void F_138 ( struct V_2 * V_115 ,
struct V_397 * V_398 , int V_90 )
{
struct V_374 * V_375 ;
unsigned int V_81 , V_107 ;
V_107 = F_133 ( struct V_397 , V_106 ) +
F_9 ( V_398 -> V_107 ) ;
V_81 = F_9 ( V_398 -> V_148 ) ;
if ( V_81 < 8 ) {
F_134 ( V_115 -> V_104 , L_115 ,
V_81 ) ;
return;
}
if ( V_81 > V_90 || V_107 > V_90 || V_107 + V_81 > V_90 ) {
F_134 ( V_115 -> V_104 , L_116 ,
V_107 + V_81 , V_90 ) ;
return;
}
V_375 = ( void * ) ( ( T_2 * ) V_398 + V_107 ) ;
switch ( F_9 ( V_375 -> V_399 ) ) {
case V_400 :
F_134 ( V_115 -> V_104 , L_117 ,
F_9 ( V_375 -> V_89 . V_401 ) ) ;
return;
case V_402 :
F_134 ( V_115 -> V_104 , L_118 ,
F_9 ( V_375 -> V_89 . V_403 ) ) ;
return;
case V_404 :
F_132 ( V_115 , V_375 , V_81 ) ;
return;
case V_405 :
F_136 ( V_115 , V_375 , V_81 ) ;
return;
default:
F_134 ( V_115 -> V_104 , L_119 ,
F_9 ( V_375 -> V_399 ) ) ;
}
}
static void F_139 ( struct V_2 * V_115 , void * V_406 , int V_90 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_397 * V_398 = V_406 ;
switch ( F_9 ( V_398 -> V_106 ) ) {
case V_407 :
if ( V_5 -> V_103 == V_53 ) {
F_15 ( V_115 -> V_104 , L_120 ) ;
return;
}
F_97 ( V_115 ) ;
F_134 ( V_115 -> V_104 , L_121 ) ;
F_118 ( V_366 , & V_5 -> V_367 ) ;
F_119 ( V_5 -> V_278 , & V_5 -> V_309 ) ;
break;
case V_408 :
F_134 ( V_115 -> V_104 , L_122 ) ;
F_118 ( V_372 , & V_5 -> V_367 ) ;
F_119 ( V_5 -> V_278 , & V_5 -> V_309 ) ;
break;
case V_409 :
F_138 ( V_115 , V_398 , V_90 ) ;
break;
default:
F_134 ( V_115 -> V_104 , L_123 ,
F_9 ( V_398 -> V_106 ) ) ;
break;
}
}
static int F_140 ( struct V_2 * V_115 , struct V_191 * V_191 )
{
struct {
T_3 V_307 ;
T_3 V_410 [ 8 ] ;
} V_411 ;
struct V_412 * V_413 ;
T_2 V_414 [ sizeof( * V_413 ) + sizeof( V_413 -> V_415 ) * 16 ] ;
int V_81 , V_416 , V_126 , V_417 ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_81 = sizeof( V_411 ) ;
V_416 = F_10 ( V_115 ,
V_58 ,
& V_411 , & V_81 ) ;
if ( V_416 >= 0 ) {
V_417 = F_9 ( V_411 . V_307 ) ;
if ( V_417 > 8 )
V_417 = 8 ;
for ( V_126 = 0 ; V_126 < V_417 ; V_126 ++ ) {
switch ( F_9 ( V_411 . V_410 [ V_126 ] ) ) {
case V_418 :
case V_419 :
V_5 -> V_413 |= V_420 ;
break;
case V_421 :
V_5 -> V_413 |= V_422 ;
break;
case V_423 :
V_5 -> V_413 |= V_424 ;
break;
}
}
}
V_413 = (struct V_412 * ) V_414 ;
V_81 = sizeof( V_414 ) ;
V_416 = F_10 ( V_115 ,
V_56 ,
V_413 , & V_81 ) ;
if ( V_416 >= 0 ) {
F_15 ( V_115 -> V_104 , L_124
L_125 ,
F_9 ( V_413 -> V_148 ) ,
F_9 ( V_413 -> V_392 ) ,
F_9 ( V_413 -> V_246 ) ,
F_9 ( V_413 -> V_425 ) ) ;
V_191 -> V_242 = F_9 ( V_413 -> V_246 ) ;
} else
V_191 -> V_242 = 0 ;
return V_416 ;
}
static void F_141 ( struct V_2 * V_115 , T_5 V_294 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
enum V_426 V_427 ;
int V_428 , V_429 , V_430 ;
if ( V_5 -> V_352 >= 0 || V_294 >= 0 )
return;
if ( V_5 -> V_179 != V_147 )
return;
V_430 = V_5 -> V_354 ;
V_428 = V_5 -> V_352 ;
V_429 = V_5 -> V_353 ;
if ( V_294 < V_428 && ( V_430 == 0 || V_294 < V_430 - V_429 ) )
V_427 = V_431 ;
else if ( V_294 > V_428 && ( V_430 == 0 || V_294 > V_430 + V_429 ) )
V_427 = V_432 ;
else
return;
V_5 -> V_354 = V_294 ;
F_142 ( V_115 -> V_104 , V_427 , V_96 ) ;
}
static void F_143 ( struct V_308 * V_309 )
{
struct V_1 * V_5 =
F_92 ( V_309 , struct V_1 ,
V_433 . V_309 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_3 V_294 , V_133 ;
int V_81 , V_70 , V_434 ;
int V_435 = V_436 ;
void * V_82 ;
if ( ! F_33 ( V_115 ) ) {
if ( V_5 -> V_275 == V_276 && V_5 -> V_140 &&
! V_5 -> V_274 ) {
F_81 ( V_115 , NULL , NULL ) ;
F_26 ( V_115 ) ;
}
goto V_437;
}
V_81 = sizeof( V_294 ) ;
V_70 = F_10 ( V_115 , V_61 ,
& V_294 , & V_81 ) ;
if ( V_70 == 0 ) {
V_5 -> V_438 = F_25 ( F_9 ( V_294 ) ) ;
F_141 ( V_115 , F_9 ( V_294 ) ) ;
}
F_15 ( V_115 -> V_104 , L_126 ,
V_70 , F_9 ( V_294 ) , F_25 ( F_9 ( V_294 ) ) ) ;
if ( V_5 -> V_439 > 0 && V_5 -> V_438 <= 25 ) {
V_434 = F_144 ( V_5 -> V_439 ) ;
if ( V_434 > V_436 )
V_434 = V_436 ;
else if ( V_434 <= 0 )
V_434 = 1 ;
V_435 = V_434 ;
V_133 = F_13 ( 1 ) ;
F_18 ( V_115 ,
V_51 ,
& V_133 , sizeof( V_133 ) ) ;
V_81 = V_94 ;
V_82 = F_11 ( V_81 , V_96 ) ;
if ( ! V_82 )
goto V_437;
F_10 ( V_115 ,
V_68 ,
V_82 , & V_81 ) ;
F_17 ( V_82 ) ;
}
V_437:
if ( V_435 >= V_277 )
V_435 = F_145 ( V_435 ) ;
else {
V_434 = F_145 ( V_435 ) ;
if ( abs ( V_434 - V_435 ) <= 10 )
V_435 = V_434 ;
}
F_82 ( V_5 -> V_278 , & V_5 -> V_433 ,
V_435 ) ;
}
static void F_146 ( struct V_2 * V_115 , int V_275 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_5 -> V_275 = V_275 ;
V_5 -> V_440 [ 0 ] = V_441 [ 0 ] ;
V_5 -> V_440 [ 1 ] = V_441 [ 1 ] ;
V_5 -> V_440 [ 2 ] = 0 ;
V_5 -> V_442 = V_443 ;
V_5 -> V_444 = V_445 ;
V_5 -> V_446 = V_447 ;
V_5 -> V_6 = V_448 ;
V_5 -> V_449 = V_450 ;
V_5 -> V_451 = V_452 ;
V_5 -> V_440 [ 0 ] = toupper ( V_5 -> V_440 [ 0 ] ) ;
V_5 -> V_440 [ 1 ] = toupper ( V_5 -> V_440 [ 1 ] ) ;
if ( ! strcmp ( V_5 -> V_440 , L_127 ) )
strcpy ( V_5 -> V_440 , L_128 ) ;
if ( V_5 -> V_446 < 0 )
V_5 -> V_446 = 0 ;
else if ( V_5 -> V_446 > 2 )
V_5 -> V_446 = 2 ;
if ( V_5 -> V_6 < 0 )
V_5 -> V_6 = 0 ;
else if ( V_5 -> V_6 > 3 )
V_5 -> V_6 = 3 ;
if ( V_5 -> V_449 < - 80 )
V_5 -> V_449 = - 80 ;
else if ( V_5 -> V_449 > - 60 )
V_5 -> V_449 = - 60 ;
if ( V_5 -> V_451 < 0 )
V_5 -> V_451 = 0 ;
else if ( V_5 -> V_451 > 2 )
V_5 -> V_451 = 2 ;
if ( V_453 < 0 )
V_5 -> V_439 = 500 ;
else
V_5 -> V_439 = V_453 ;
}
static int F_147 ( struct V_2 * V_115 )
{
F_146 ( V_115 , V_454 ) ;
return 0 ;
}
static int F_148 ( struct V_2 * V_115 )
{
F_146 ( V_115 , V_276 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
char V_82 [ 8 ] ;
F_146 ( V_115 , V_347 ) ;
F_24 ( V_115 , L_129 , V_5 -> V_440 ) ;
F_24 ( V_115 , L_130 ,
V_5 -> V_442 ? L_131 : L_132 ) ;
F_24 ( V_115 , L_133 ,
V_5 -> V_444 ? L_131 : L_132 ) ;
sprintf ( V_82 , L_134 , V_5 -> V_446 ) ;
F_24 ( V_115 , L_135 , V_82 ) ;
sprintf ( V_82 , L_134 , V_5 -> V_6 ) ;
F_24 ( V_115 , L_136 , V_82 ) ;
sprintf ( V_82 , L_134 , V_5 -> V_449 ) ;
F_24 ( V_115 , L_137 , V_82 ) ;
sprintf ( V_82 , L_134 , V_5 -> V_451 ) ;
F_24 ( V_115 , L_138 , V_82 ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_115 , struct V_455 * V_456 )
{
struct V_191 * V_191 ;
struct V_1 * V_5 ;
int V_416 , V_81 ;
T_3 V_133 ;
V_191 = F_151 ( & V_457 , sizeof( struct V_1 ) ) ;
if ( ! V_191 )
return - V_97 ;
V_5 = F_74 ( V_191 ) ;
V_115 -> V_104 -> V_458 = & V_5 -> V_190 ;
V_5 -> V_190 . V_191 = V_191 ;
V_5 -> V_190 . V_260 = V_259 ;
V_115 -> V_4 = V_5 ;
V_5 -> V_115 = V_115 ;
F_152 ( & V_5 -> V_99 ) ;
V_5 -> V_278 = F_153 ( L_139 ) ;
F_154 ( & V_5 -> V_309 , F_128 ) ;
F_155 ( & V_5 -> V_433 , F_143 ) ;
F_155 ( & V_5 -> V_279 , F_91 ) ;
V_416 = F_156 ( V_115 , V_456 , V_459 ) ;
if ( V_416 < 0 )
goto V_460;
V_115 -> V_104 -> V_461 = & V_462 ;
V_133 = F_13 ( V_225 | V_226 ) ;
V_416 = F_18 ( V_115 ,
V_31 ,
& V_133 , sizeof( V_133 ) ) ;
V_81 = sizeof( V_133 ) ;
V_416 = F_10 ( V_115 ,
V_42 ,
& V_133 , & V_81 ) ;
V_5 -> V_233 = F_9 ( V_133 ) ;
if ( V_416 < 0 || V_5 -> V_233 < 0 )
V_5 -> V_233 = 0 ;
if ( V_5 -> V_233 > 0 )
V_115 -> V_104 -> V_205 |= V_463 ;
else
V_115 -> V_104 -> V_205 &= ~ V_463 ;
memcpy ( V_191 -> V_464 , V_115 -> V_104 -> V_465 , V_142 ) ;
V_191 -> V_466 = V_467 ;
V_191 -> V_468 = F_157 ( V_259 )
| F_157 ( V_258 ) ;
V_191 -> V_469 = 1 ;
F_140 ( V_115 , V_191 ) ;
memcpy ( V_5 -> V_470 , V_471 , sizeof( V_471 ) ) ;
memcpy ( V_5 -> V_472 , V_473 , sizeof( V_473 ) ) ;
V_5 -> V_474 . V_470 = V_5 -> V_470 ;
V_5 -> V_474 . V_475 = F_158 ( V_471 ) ;
V_5 -> V_474 . V_476 = V_5 -> V_472 ;
V_5 -> V_474 . V_477 = F_158 ( V_473 ) ;
V_191 -> V_478 [ V_186 ] = & V_5 -> V_474 ;
V_191 -> V_479 = V_480 ;
memcpy ( V_5 -> V_481 , V_482 ,
sizeof( V_482 ) ) ;
V_191 -> V_481 = V_5 -> V_481 ;
V_191 -> V_483 = F_158 ( V_482 ) ;
F_159 ( V_191 , & V_115 -> V_484 -> V_3 ) ;
if ( F_160 ( V_191 ) ) {
V_416 = - V_485 ;
goto V_460;
}
F_45 ( V_115 ) ;
V_5 -> V_346 = - 1 ;
F_75 ( V_191 ,
V_262 | V_263 ) ;
V_5 -> V_140 = false ;
F_35 ( V_115 , false ) ;
F_127 ( V_115 -> V_104 ) ;
return 0 ;
V_460:
F_161 ( & V_5 -> V_433 ) ;
F_161 ( & V_5 -> V_279 ) ;
F_162 ( & V_5 -> V_309 ) ;
F_163 ( V_5 -> V_278 ) ;
F_164 ( V_5 -> V_278 ) ;
F_165 ( V_191 ) ;
return V_416 ;
}
static void F_166 ( struct V_2 * V_115 , struct V_455 * V_456 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
F_35 ( V_115 , false ) ;
F_161 ( & V_5 -> V_433 ) ;
F_161 ( & V_5 -> V_279 ) ;
F_162 ( & V_5 -> V_309 ) ;
F_163 ( V_5 -> V_278 ) ;
F_164 ( V_5 -> V_278 ) ;
F_167 ( V_115 , V_456 ) ;
F_168 ( V_5 -> V_190 . V_191 ) ;
F_165 ( V_5 -> V_190 . V_191 ) ;
}
static int F_169 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_416 ;
F_15 ( V_115 -> V_104 , L_60 , V_105 ) ;
V_416 = F_19 ( V_115 ) ;
if ( V_416 )
F_28 ( V_115 -> V_104 , L_140 , V_416 ) ;
F_58 ( V_115 ) ;
F_82 ( V_5 -> V_278 , & V_5 -> V_433 ,
F_145 ( V_436 ) ) ;
return F_46 ( V_115 ) ;
}
static int F_170 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_416 ;
T_3 V_221 ;
F_15 ( V_115 -> V_104 , L_60 , V_105 ) ;
V_416 = F_35 ( V_115 , false ) ;
V_5 -> V_367 = 0 ;
F_161 ( & V_5 -> V_433 ) ;
F_161 ( & V_5 -> V_279 ) ;
F_162 ( & V_5 -> V_309 ) ;
F_163 ( V_5 -> V_278 ) ;
if ( V_5 -> V_274 ) {
F_93 ( V_5 -> V_274 , true ) ;
V_5 -> V_274 = NULL ;
}
V_221 = 0 ;
F_18 ( V_115 , V_31 , & V_221 ,
sizeof( V_221 ) ) ;
return V_416 ;
}
