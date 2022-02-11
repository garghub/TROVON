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
V_185 = F_48 ( V_182 ) * 1000 ;
V_81 = sizeof( V_184 ) ;
V_70 = F_10 ( V_115 ,
V_66 ,
& V_184 , & V_81 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_25 ,
V_105 ) ;
return V_70 ;
}
V_184 . V_186 = F_13 ( V_185 ) ;
V_70 = F_18 ( V_115 ,
V_66 ,
& V_184 , sizeof( V_184 ) ) ;
F_15 ( V_115 -> V_104 , L_26 , V_105 , V_182 , V_70 ) ;
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
V_70 = F_10 ( V_115 ,
V_66 ,
& V_184 , & V_81 ) ;
F_15 ( V_115 -> V_104 , L_27 ,
V_105 , V_70 ) ;
if ( V_70 < 0 )
return NULL ;
V_182 = F_50 ( V_5 -> V_189 . V_190 ,
F_51 ( F_9 ( V_184 . V_186 ) ) ) ;
if ( ! V_182 )
return NULL ;
if ( V_188 )
* V_188 = F_9 ( V_184 . V_188 ) ;
return V_182 ;
}
static int F_52 ( struct V_2 * V_115 , const T_2 * V_191 , int V_192 ,
T_2 V_193 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_194 V_195 ;
T_1 V_12 ;
int V_70 ;
F_15 ( V_115 -> V_104 , L_28 ,
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
V_195 . V_197 = F_13 ( sizeof( V_195 ) ) ;
V_195 . V_148 = F_13 ( V_192 ) ;
V_195 . V_193 = F_13 ( V_193 ) ;
memcpy ( & V_195 . V_198 , V_191 , V_192 ) ;
if ( V_193 == V_5 -> V_199 ) {
V_195 . V_193 |= V_200 ;
V_70 = F_41 ( V_115 , V_19 ,
V_16 ) ;
if ( V_70 )
F_28 ( V_115 -> V_104 , L_29 ,
V_70 ) ;
}
V_70 = F_18 ( V_115 ,
V_46 , & V_195 ,
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
F_15 ( V_115 -> V_104 , L_31 ,
V_105 , V_193 ) ;
return - V_71 ;
}
if ( V_192 > sizeof( V_195 . V_198 ) || V_192 < 0 ) {
F_15 ( V_115 -> V_104 , L_32 ,
V_105 , V_192 ) ;
return - V_71 ;
}
if ( V_204 & V_207 ) {
if ( ! V_202 || V_203 <= 0 ) {
F_15 ( V_115 -> V_104 , L_33 ,
V_105 ) ;
return - V_71 ;
}
if ( V_202 && V_203 > sizeof( V_195 . V_208 ) ) {
F_15 ( V_115 -> V_104 , L_34 , V_105 ) ;
return - V_71 ;
}
}
V_206 = V_201 && ! F_34 ( V_201 ) &&
! F_54 ( V_201 ) ;
if ( ( V_204 & V_209 ) && ! V_206 ) {
F_15 ( V_115 -> V_104 , L_35 ,
V_105 , V_201 ) ;
return - V_71 ;
}
F_15 ( V_115 -> V_104 , L_36 ,
V_105 , V_193 ,
! ! ( V_204 & V_210 ) ,
! ! ( V_204 & V_209 ) ,
! ! ( V_204 & V_207 ) ) ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_197 = F_13 ( sizeof( V_195 ) -
sizeof( V_195 . V_198 ) + V_192 ) ;
V_195 . V_148 = F_13 ( V_192 ) ;
V_195 . V_193 = F_13 ( V_193 ) | V_204 ;
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
V_70 = F_18 ( V_115 ,
V_53 , & V_195 ,
F_9 ( V_195 . V_197 ) ) ;
F_15 ( V_115 -> V_104 , L_37 ,
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
F_15 ( V_115 -> V_104 , L_38 , V_105 , V_212 , V_191 . V_81 ) ;
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
F_15 ( V_115 -> V_104 , L_39 ,
V_105 , V_193 , V_216 ? L_40 : L_41 ,
V_5 -> V_13 [ V_193 ] . V_81 ) ;
F_56 ( V_5 , V_193 ) ;
if ( V_216 ) {
F_57 . V_197 = F_13 ( sizeof( F_57 ) ) ;
F_57 . V_193 = F_13 ( V_193 ) ;
if ( V_141 ) {
if ( ! F_54 ( V_141 ) )
F_57 . V_193 |=
V_209 ;
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
V_215 = F_13 ( V_193 ) ;
V_70 = F_18 ( V_115 ,
V_47 ,
& V_215 , sizeof( V_215 ) ) ;
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
V_221 = V_220 = F_13 ( V_224 |
V_225 ) ;
if ( V_115 -> V_104 -> V_204 & V_226 ) {
V_220 |= F_13 ( V_227 |
V_228 ) ;
} else if ( V_115 -> V_104 -> V_204 & V_229 ) {
V_220 |= F_13 ( V_230 ) ;
}
if ( V_220 != V_221 )
goto V_231;
F_59 ( V_115 -> V_104 ) ;
V_223 = F_60 ( V_115 -> V_104 ) ;
if ( V_223 > V_5 -> V_232 ) {
V_220 |= F_13 ( V_230 ) ;
} else if ( V_223 ) {
int V_126 = 0 ;
V_222 = F_11 ( V_223 * V_142 , V_233 ) ;
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
V_70 = F_18 ( V_115 ,
V_41 ,
V_222 , V_223 * V_142 ) ;
F_17 ( V_222 ) ;
if ( V_70 == 0 )
V_220 |= F_13 ( V_234 ) ;
else
V_220 |= F_13 ( V_230 ) ;
F_15 ( V_115 -> V_104 , L_44 ,
V_223 , V_5 -> V_232 , V_70 ) ;
}
V_231:
V_70 = F_18 ( V_115 , V_31 , & V_220 ,
sizeof( V_220 ) ) ;
if ( V_70 < 0 ) {
F_28 ( V_115 -> V_104 , L_45 ,
F_9 ( V_220 ) ) ;
}
F_15 ( V_115 -> V_104 , L_46 ,
F_9 ( V_220 ) , V_70 ) ;
}
static void F_63 ( struct V_2 * V_115 ,
struct V_235 * V_236 ,
const char * V_237 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_126 , V_81 , V_238 , V_239 , V_240 ;
V_239 = V_5 -> V_189 . V_190 -> V_241 ;
V_81 = F_9 ( V_236 -> V_148 ) ;
V_238 = F_9 ( V_236 -> V_242 ) ;
V_240 = ( V_238 > 0 ) ? ( V_81 - sizeof( * V_236 ) ) / V_238 : - 1 ;
F_15 ( V_115 -> V_104 , L_47
L_48 , V_237 , V_238 , V_81 , V_240 ) ;
if ( V_238 > V_239 )
V_238 = V_239 ;
for ( V_126 = 0 ; V_126 < V_238 ; V_126 ++ ) {
T_1 * V_133 = ( T_1 * ) V_236 -> V_243 [ V_126 ] . V_244 ;
F_15 ( V_115 -> V_104 , L_49
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
V_236 -> V_148 = F_13 ( V_81 ) ;
V_236 -> V_242 = F_13 ( V_239 ) ;
V_70 = F_10 ( V_115 , V_57 ,
V_236 , & V_81 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_51
L_52 , V_105 , V_81 , V_239 , V_70 ) ;
F_17 ( V_236 ) ;
return F_66 ( V_70 ) ;
}
if ( F_9 ( V_236 -> V_242 ) > V_239 )
V_236 -> V_242 = F_13 ( V_239 ) ;
F_63 ( V_115 , V_236 , V_105 ) ;
return V_236 ;
}
static int F_67 ( struct V_2 * V_115 ,
struct V_235 * V_236 )
{
int V_70 , V_81 , V_245 ;
V_245 = F_9 ( V_236 -> V_242 ) ;
V_81 = sizeof( * V_236 ) + V_245 * sizeof( V_236 -> V_243 [ 0 ] ) ;
V_236 -> V_148 = F_13 ( V_81 ) ;
F_63 ( V_115 , V_236 , V_105 ) ;
V_70 = F_18 ( V_115 , V_57 , V_236 ,
F_9 ( V_236 -> V_148 ) ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_53
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
V_238 = F_9 ( V_236 -> V_242 ) ;
if ( V_238 > V_239 )
V_238 = V_239 ;
for ( V_126 = 0 ; V_126 < V_238 ; V_126 ++ )
if ( F_69 ( V_236 -> V_243 [ V_126 ] . V_141 ,
V_247 -> V_141 ) )
break;
if ( V_126 == V_238 ) {
F_15 ( V_115 -> V_104 , L_55 ,
V_105 , V_247 -> V_141 ) ;
V_249 = - V_217 ;
goto error;
}
for (; V_126 + 1 < V_238 ; V_126 ++ )
V_236 -> V_243 [ V_126 ] = V_236 -> V_243 [ V_126 + 1 ] ;
V_238 -- ;
V_248 = sizeof( * V_236 ) + V_238 * sizeof( V_236 -> V_243 [ 0 ] ) ;
V_236 -> V_148 = F_13 ( V_248 ) ;
V_236 -> V_242 = F_13 ( V_238 ) ;
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
V_238 = F_9 ( V_236 -> V_242 ) ;
if ( V_238 > V_239 )
V_238 = V_239 ;
for ( V_126 = 0 ; V_126 < V_238 ; V_126 ++ ) {
if ( ! F_69 ( V_236 -> V_243 [ V_126 ] . V_141 ,
V_247 -> V_141 ) )
continue;
memcpy ( V_236 -> V_243 [ V_126 ] . V_244 , V_247 -> V_244 ,
V_250 ) ;
return V_236 ;
}
if ( V_126 == V_239 ) {
F_15 ( V_115 -> V_104 , L_56 , V_105 ) ;
V_249 = - V_251 ;
goto error;
}
V_248 = sizeof( * V_236 ) + ( V_238 + 1 ) * sizeof( V_236 -> V_243 [ 0 ] ) ;
V_236 = F_71 ( V_236 , V_248 , V_96 ) ;
if ( ! V_236 ) {
V_249 = - V_97 ;
goto error;
}
V_236 -> V_148 = F_13 ( V_248 ) ;
V_236 -> V_242 = F_13 ( V_238 + 1 ) ;
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
F_15 ( V_115 -> V_104 , L_57 ,
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
F_15 ( V_115 -> V_104 , L_58 , V_105 , * V_265 ) ;
return 0 ;
}
static int F_78 ( struct V_190 * V_190 , struct V_252 * V_3 ,
struct V_266 * V_267 )
{
struct V_2 * V_115 = F_79 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_70 ;
int V_268 = V_269 ;
F_15 ( V_115 -> V_104 , L_59 ) ;
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
F_15 ( V_115 -> V_104 , L_60 ,
V_141 -> V_139 . V_149 , V_141 -> V_287 , F_9 ( V_141 -> V_148 ) ) ;
V_285 = F_9 ( V_141 -> V_148 ) ;
if ( V_285 < sizeof( struct V_276 ) +
sizeof( struct V_282 ) )
return NULL ;
V_283 = (struct V_282 * ) V_141 -> V_288 ;
V_286 = ( void * ) ( V_141 -> V_288 + sizeof( struct V_282 ) ) ;
V_284 = F_83 ( V_285 - ( int ) sizeof( * V_141 ) ,
( int ) F_9 ( V_141 -> V_289 ) ) ;
V_284 -= sizeof( struct V_282 ) ;
if ( V_284 < 0 )
return NULL ;
V_182 = F_50 ( V_5 -> V_189 . V_190 ,
F_51 ( F_9 ( V_141 -> V_184 . V_186 ) ) ) ;
if ( ! V_182 )
return NULL ;
signal = F_25 ( F_9 ( V_141 -> V_290 ) ) ;
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
* V_285 = F_9 ( V_141 -> V_148 ) ;
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
F_15 ( V_115 -> V_104 , L_61 , V_105 ) ;
V_81 = V_94 ;
V_301:
V_82 = F_65 ( V_81 , V_96 ) ;
if ( ! V_82 ) {
V_70 = - V_97 ;
goto V_302;
}
V_300 = V_81 ;
V_70 = F_10 ( V_115 , V_68 ,
V_82 , & V_300 ) ;
if ( V_70 != 0 || V_300 < sizeof( struct V_297 ) )
goto V_302;
if ( V_300 > V_81 ) {
V_81 = V_300 ;
F_17 ( V_82 ) ;
goto V_301;
}
V_81 = V_300 ;
V_298 = V_82 ;
V_238 = F_9 ( V_298 -> V_303 ) ;
V_299 = 0 ;
F_15 ( V_115 -> V_104 , L_62 , V_105 , V_81 ) ;
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
F_15 ( V_115 -> V_104 , L_63
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
F_15 ( V_115 -> V_104 , L_65 ) ;
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
F_15 ( V_115 -> V_104 , L_68 ,
V_307 -> V_139 , V_307 -> V_141 , V_308 ,
V_307 -> V_316 , V_307 -> V_310 . V_317 , V_307 -> V_152 ,
V_172 , V_171 , V_153 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_147 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_69 ,
V_70 ) ;
goto V_318;
}
V_70 = F_39 ( V_115 , V_307 -> V_310 . V_317 , V_307 -> V_152 ,
V_153 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_70 ,
V_70 ) ;
goto V_318;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_171 , V_172 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_71 ,
V_70 ) ;
goto V_318;
}
if ( V_182 ) {
V_70 = F_47 ( V_115 , V_308 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_72 ,
V_70 ) ;
goto V_318;
}
}
if ( V_307 -> V_191 && ( ( V_172 | V_171 ) & V_19 ) ) {
V_5 -> V_199 = V_307 -> V_212 ;
V_70 = F_52 ( V_115 , V_307 -> V_191 , V_307 -> V_192 , V_307 -> V_212 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_73 ,
V_70 , V_307 -> V_192 , V_307 -> V_212 ) ;
goto V_318;
}
}
if ( V_307 -> V_141 && ! F_34 ( V_307 -> V_141 ) &&
! F_54 ( V_307 -> V_141 ) ) {
V_70 = F_29 ( V_115 , V_307 -> V_141 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_74 ,
V_70 ) ;
goto V_318;
}
} else
F_30 ( V_115 ) ;
V_148 = V_307 -> V_319 ;
if ( V_148 > V_320 )
V_148 = V_320 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_148 = F_13 ( V_148 ) ;
memcpy ( V_139 . V_149 , V_307 -> V_139 , V_148 ) ;
F_96 ( V_115 ) ;
F_97 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_139 ) ;
if ( V_70 < 0 )
F_15 ( V_115 -> V_104 , L_75 , V_70 ) ;
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
F_15 ( V_115 -> V_104 , L_76 , V_321 ) ;
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
F_15 ( V_115 -> V_104 , L_77 ,
V_255 -> V_139 , V_255 -> V_141 , V_308 , V_255 -> V_316 ) ;
if ( F_33 ( V_115 ) )
F_35 ( V_115 , false ) ;
V_70 = F_37 ( V_115 , V_211 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_78 ,
V_70 ) ;
goto V_318;
}
V_70 = F_39 ( V_115 , 0 , V_152 , V_23 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_79 ,
V_70 ) ;
goto V_318;
}
F_40 ( V_115 ) ;
V_70 = F_41 ( V_115 , V_324 , V_16 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_80 ,
V_70 ) ;
goto V_318;
}
if ( V_182 ) {
V_70 = F_47 ( V_115 , V_308 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_81 ,
V_70 ) ;
goto V_318;
}
}
if ( V_255 -> V_141 && ! F_34 ( V_255 -> V_141 ) &&
! F_54 ( V_255 -> V_141 ) ) {
V_70 = F_29 ( V_115 , V_255 -> V_141 ) ;
if ( V_70 < 0 ) {
F_15 ( V_115 -> V_104 , L_82 ,
V_70 ) ;
goto V_318;
}
} else
F_30 ( V_115 ) ;
V_148 = V_255 -> V_319 ;
if ( V_148 > V_320 )
V_148 = V_320 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_148 = F_13 ( V_148 ) ;
memcpy ( V_139 . V_149 , V_255 -> V_139 , V_148 ) ;
F_97 ( V_115 ) ;
F_100 ( V_115 ) ;
V_70 = F_27 ( V_115 , & V_139 ) ;
if ( V_70 < 0 )
F_15 ( V_115 -> V_104 , L_83 ,
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
F_15 ( V_115 -> V_104 , L_84 ) ;
V_5 -> V_322 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
return F_46 ( V_115 ) ;
}
static int F_102 ( struct V_190 * V_190 , struct V_252 * V_325 ,
T_2 V_326 , bool V_171 , const T_2 * V_327 ,
struct V_328 * V_255 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_3 V_204 ;
F_15 ( V_115 -> V_104 , L_85 ,
V_105 , V_326 , V_327 , V_255 -> V_12 ) ;
switch ( V_255 -> V_12 ) {
case V_17 :
case V_18 :
return F_52 ( V_115 , V_255 -> V_191 , V_255 -> V_192 ,
V_326 ) ;
case V_15 :
case V_14 :
V_204 = 0 ;
if ( V_255 -> V_329 && V_255 -> V_203 > 0 )
V_204 |= V_207 ;
if ( V_327 )
V_204 |= V_209 |
V_210 ;
return F_53 ( V_115 , V_255 -> V_191 , V_255 -> V_192 ,
V_326 , V_327 , V_255 -> V_329 ,
V_255 -> V_203 , V_255 -> V_12 , V_204 ) ;
default:
F_15 ( V_115 -> V_104 , L_86 ,
V_105 , V_255 -> V_12 ) ;
return - V_168 ;
}
}
static int F_103 ( struct V_190 * V_190 , struct V_252 * V_325 ,
T_2 V_326 , bool V_171 , const T_2 * V_327 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
F_15 ( V_115 -> V_104 , L_87 , V_105 , V_326 , V_327 ) ;
return F_57 ( V_115 , V_326 , V_327 ) ;
}
static int F_104 ( struct V_190 * V_190 , struct V_252 * V_325 ,
T_2 V_326 , bool V_330 , bool V_331 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_213 V_191 ;
F_15 ( V_115 -> V_104 , L_88 , V_105 , V_326 ) ;
if ( V_326 >= V_196 )
return - V_217 ;
V_5 -> V_199 = V_326 ;
if ( F_3 ( V_5 , V_326 ) )
return 0 ;
V_191 = V_5 -> V_13 [ V_326 ] ;
return F_52 ( V_115 , V_191 . V_198 , V_191 . V_81 , V_326 ) ;
}
static void F_105 ( struct V_2 * V_115 ,
struct V_332 * V_333 )
{
T_3 V_334 , V_290 ;
int V_70 , V_81 ;
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
V_81 = sizeof( V_334 ) ;
V_70 = F_10 ( V_115 , V_33 , & V_334 , & V_81 ) ;
if ( V_70 == 0 ) {
V_333 -> V_335 . V_336 = F_9 ( V_334 ) / 1000 ;
V_333 -> V_337 |= V_338 ;
}
V_81 = sizeof( V_290 ) ;
V_70 = F_10 ( V_115 , V_61 ,
& V_290 , & V_81 ) ;
if ( V_70 == 0 ) {
V_333 -> signal = F_25 ( F_9 ( V_290 ) ) ;
V_333 -> V_337 |= V_339 ;
}
}
static int F_106 ( struct V_190 * V_190 , struct V_252 * V_3 ,
T_2 * V_287 , struct V_332 * V_333 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( ! F_69 ( V_5 -> V_141 , V_287 ) )
return - V_217 ;
F_105 ( V_115 , V_333 ) ;
return 0 ;
}
static int F_107 ( struct V_190 * V_190 , struct V_252 * V_3 ,
int V_11 , T_2 * V_287 , struct V_332 * V_333 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( V_11 != 0 )
return - V_217 ;
memcpy ( V_287 , V_5 -> V_141 , V_142 ) ;
F_105 ( V_115 , V_333 ) ;
return 0 ;
}
static int F_108 ( struct V_190 * V_190 , struct V_252 * V_325 ,
struct V_246 * V_247 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_235 * V_236 ;
T_1 * V_133 = ( T_1 * ) V_247 -> V_244 ;
F_15 ( V_115 -> V_104 , L_89 , V_105 ,
V_247 -> V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
V_236 = F_64 ( V_115 ) ;
if ( F_109 ( V_236 ) ) {
return F_110 ( V_236 ) ;
}
V_236 = F_70 ( V_115 , V_236 , V_247 , V_190 -> V_241 ) ;
if ( F_109 ( V_236 ) ) {
return F_110 ( V_236 ) ;
}
return F_67 ( V_115 , V_236 ) ;
}
static int F_111 ( struct V_190 * V_190 , struct V_252 * V_325 ,
struct V_246 * V_247 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_235 * V_236 ;
T_1 * V_133 = ( T_1 * ) V_247 -> V_244 ;
F_15 ( V_115 -> V_104 , L_89 , V_105 ,
V_247 -> V_141 ,
F_23 ( V_133 [ 0 ] ) , F_23 ( V_133 [ 1 ] ) ,
F_23 ( V_133 [ 2 ] ) , F_23 ( V_133 [ 3 ] ) ) ;
V_236 = F_64 ( V_115 ) ;
if ( F_109 ( V_236 ) ) {
return F_110 ( V_236 ) ;
}
V_236 = F_68 ( V_115 , V_236 , V_247 , V_190 -> V_241 ) ;
if ( F_109 ( V_236 ) ) {
return F_110 ( V_236 ) ;
}
return F_67 ( V_115 , V_236 ) ;
}
static int F_112 ( struct V_190 * V_190 , struct V_252 * V_325 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
struct V_235 V_244 ;
F_15 ( V_115 -> V_104 , L_61 , V_105 ) ;
memset ( & V_244 , 0 , sizeof( V_244 ) ) ;
V_244 . V_148 = F_13 ( sizeof( V_244 ) ) ;
V_244 . V_242 = F_13 ( 0 ) ;
return F_18 ( V_115 , V_57 ,
& V_244 , sizeof( V_244 ) ) ;
}
static int F_113 ( struct V_190 * V_190 , struct V_252 * V_3 ,
bool V_340 , int V_341 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
int V_342 ;
T_3 V_178 ;
int V_70 ;
if ( V_5 -> V_271 != V_343 )
return - V_168 ;
F_15 ( V_115 -> V_104 , L_90 , V_105 ,
V_340 ? L_91 : L_92 ,
V_341 ) ;
if ( V_340 )
V_342 = V_344 ;
else
V_342 = V_345 ;
if ( V_342 == V_5 -> V_342 )
return 0 ;
V_5 -> V_342 = V_342 ;
V_178 = F_13 ( V_342 ) ;
V_70 = F_18 ( V_115 , V_67 ,
& V_178 , sizeof( V_178 ) ) ;
F_15 ( V_115 -> V_104 , L_93 ,
V_105 , V_70 ) ;
return V_70 ;
}
static int F_114 ( struct V_190 * V_190 ,
struct V_252 * V_3 ,
T_5 V_346 , T_1 V_347 )
{
struct V_1 * V_5 = F_73 ( V_190 ) ;
V_5 -> V_348 = V_346 ;
V_5 -> V_349 = V_347 ;
V_5 -> V_350 = 0 ;
return 0 ;
}
static void F_115 ( struct V_2 * V_115 , T_2 * V_141 ,
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
T_2 V_351 [ 34 ] ;
int V_81 , V_70 , V_284 ;
V_81 = sizeof( V_290 ) ;
V_290 = 0 ;
V_70 = F_10 ( V_115 , V_61 ,
& V_290 , & V_81 ) ;
signal = F_25 ( F_9 ( V_290 ) ) ;
F_15 ( V_115 -> V_104 , L_94
L_95 , V_105 , V_70 , F_9 ( V_290 ) ,
F_25 ( F_9 ( V_290 ) ) ) ;
if ( V_145 ) {
V_280 = F_85 ( V_145 -> V_352 . V_353 ) ;
} else {
V_280 = ( V_5 -> V_179 == V_147 ) ?
V_354 : V_355 ;
}
V_182 = F_49 ( V_115 , & V_188 ) ;
if ( ! V_182 ) {
F_28 ( V_115 -> V_104 , L_96 ,
V_105 ) ;
return;
}
V_81 = sizeof( V_139 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_70 = F_10 ( V_115 , V_44 ,
& V_139 , & V_81 ) ;
F_15 ( V_115 -> V_104 , L_97
L_98 , V_105 , V_70 ,
F_9 ( V_139 . V_148 ) , V_139 . V_149 ) ;
if ( F_9 ( V_139 . V_148 ) > 32 )
V_139 . V_148 = F_13 ( 32 ) ;
V_351 [ 0 ] = V_356 ;
V_351 [ 1 ] = F_9 ( V_139 . V_148 ) ;
memcpy ( & V_351 [ 2 ] , V_139 . V_149 , F_9 ( V_139 . V_148 ) ) ;
V_284 = F_9 ( V_139 . V_148 ) + 2 ;
V_279 = 0 ;
F_15 ( V_115 -> V_104 , L_99
L_100
L_101 , V_105 , ( V_182 ? V_182 -> V_309 : - 1 ) ,
V_141 , ( T_1 ) V_279 , V_280 , V_188 , V_284 ,
V_139 . V_149 , signal ) ;
V_278 = F_86 ( V_5 -> V_189 . V_190 , V_182 , V_141 ,
V_279 , V_280 , V_188 , V_351 , V_284 ,
signal , V_96 ) ;
F_87 ( V_278 ) ;
}
static void F_116 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_144 * V_145 = NULL ;
T_2 V_141 [ V_142 ] ;
unsigned int V_357 , V_358 ;
unsigned int V_107 ;
T_2 * V_359 , * V_352 ;
int V_70 ;
bool V_360 = false ;
bool V_361 ;
if ( V_5 -> V_179 == V_147 && V_5 -> V_322 ) {
V_360 = true ;
}
V_358 = 0 ;
V_357 = 0 ;
V_359 = NULL ;
V_352 = NULL ;
if ( V_5 -> V_179 == V_147 ) {
V_145 = F_65 ( V_94 , V_96 ) ;
if ( ! V_145 ) {
F_117 ( V_362 , & V_5 -> V_363 ) ;
F_118 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
return;
}
V_70 = F_32 ( V_115 , V_145 , V_94 ) ;
if ( ! V_70 ) {
V_358 = F_9 ( V_145 -> V_364 ) ;
if ( V_358 > V_94 )
V_358 = V_94 ;
if ( V_358 != 0 ) {
V_107 = F_9 ( V_145 -> V_365 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_359 = ( T_2 * ) V_145 + V_107 ;
if ( V_107 + V_358 > V_94 )
V_358 =
V_94 - V_107 ;
}
V_357 = F_9 ( V_145 -> V_366 ) ;
if ( V_357 > V_94 )
V_357 = V_94 ;
if ( V_357 != 0 ) {
V_107 = F_9 ( V_145 -> V_367 ) ;
if ( V_107 > V_94 )
V_107 = V_94 ;
V_352 = ( T_2 * ) V_145 + V_107 ;
if ( V_107 + V_357 > V_94 )
V_357 =
V_94 - V_107 ;
}
} else {
F_17 ( V_145 ) ;
V_145 = NULL ;
}
} else if ( F_119 ( V_5 -> V_179 != V_211 ) )
return;
V_70 = F_31 ( V_115 , V_141 ) ;
if ( V_70 < 0 )
memset ( V_141 , 0 , sizeof( V_141 ) ) ;
F_15 ( V_115 -> V_104 , L_102 ,
V_141 , V_360 ? L_103 : L_104 ) ;
V_361 = false ;
F_80 ( V_115 , V_141 , & V_361 ) ;
if ( ! F_34 ( V_141 ) && ! V_361 ) {
F_115 ( V_115 , V_141 , V_145 ) ;
}
if ( V_5 -> V_179 == V_147 ) {
if ( ! V_360 )
F_120 ( V_115 -> V_104 , V_141 , V_359 ,
V_358 , V_352 ,
V_357 , 0 , V_96 ) ;
else
F_121 ( V_115 -> V_104 ,
F_49 ( V_115 , NULL ) ,
V_141 , V_359 , V_358 ,
V_352 , V_357 , V_96 ) ;
} else if ( V_5 -> V_179 == V_211 )
F_122 ( V_115 -> V_104 , V_141 , V_96 ) ;
if ( V_145 != NULL )
F_17 ( V_145 ) ;
V_5 -> V_322 = true ;
memcpy ( V_5 -> V_141 , V_141 , V_142 ) ;
F_100 ( V_115 ) ;
F_123 ( V_115 -> V_104 ) ;
}
static void F_124 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( V_5 -> V_322 ) {
V_5 -> V_322 = false ;
memset ( V_5 -> V_141 , 0 , V_142 ) ;
F_46 ( V_115 ) ;
F_125 ( V_115 -> V_104 , 0 , NULL , 0 , V_96 ) ;
}
F_126 ( V_115 -> V_104 ) ;
}
static void F_127 ( struct V_304 * V_305 )
{
struct V_1 * V_5 =
F_91 ( V_305 , struct V_1 , V_305 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
if ( F_128 ( V_362 , & V_5 -> V_363 ) )
F_116 ( V_115 ) ;
if ( F_128 ( V_368 , & V_5 -> V_363 ) )
F_124 ( V_115 ) ;
if ( F_128 ( V_369 , & V_5 -> V_363 ) )
F_58 ( V_115 ) ;
}
static void F_129 ( struct V_252 * V_3 )
{
struct V_2 * V_115 = F_79 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
if ( F_130 ( V_369 , & V_5 -> V_363 ) )
return;
F_117 ( V_369 , & V_5 -> V_363 ) ;
F_118 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
}
static void F_131 ( struct V_2 * V_115 ,
struct V_370 * V_371 ,
int V_81 )
{
T_2 * V_82 ;
const char * type ;
int V_204 , V_90 , V_372 ;
bool V_373 , V_374 ;
struct V_375 * V_376 ;
enum V_377 V_378 ;
if ( V_81 < F_132 ( struct V_370 , V_89 ) +
sizeof( struct V_375 ) ) {
F_133 ( V_115 -> V_104 , L_105 ,
V_81 ) ;
return;
}
V_82 = ( void * ) & V_371 -> V_89 . V_379 [ 0 ] ;
V_90 = V_81 - F_132 ( struct V_370 , V_89 ) ;
while ( V_90 >= sizeof( * V_376 ) ) {
V_376 = ( void * ) V_82 ;
type = L_106 ;
V_204 = F_9 ( V_376 -> V_204 ) ;
V_373 = false ;
V_374 = false ;
if ( V_204 & 0x1 )
type = L_107 ;
if ( V_204 & 0x2 )
type = L_108 ;
if ( V_204 & 0x6 ) {
V_373 = true ;
type = L_109 ;
}
if ( V_204 & 0xe ) {
V_374 = true ;
type = L_110 ;
}
F_133 ( V_115 -> V_104 , L_111 ,
type , F_9 ( V_376 -> V_204 ) ) ;
if ( V_373 ) {
V_378 = V_380 ;
V_372 = - 1 ;
F_134 ( V_115 -> V_104 ,
V_376 -> V_141 ,
V_378 , V_372 , NULL ,
V_96 ) ;
}
if ( V_374 ) {
V_378 = V_381 ;
V_372 = - 1 ;
F_134 ( V_115 -> V_104 ,
V_376 -> V_141 ,
V_378 , V_372 , NULL ,
V_96 ) ;
}
V_90 -= F_9 ( V_376 -> V_148 ) ;
V_82 += F_9 ( V_376 -> V_148 ) ;
}
}
static void F_135 ( struct V_2 * V_115 ,
struct V_370 * V_371 ,
int V_81 )
{
struct V_382 * V_383 ;
int V_384 , V_385 , V_126 ;
if ( V_81 < F_132 ( struct V_370 , V_89 ) +
sizeof( struct V_382 ) ) {
F_133 ( V_115 -> V_104 , L_112 ,
V_81 ) ;
return;
}
V_384 = F_9 ( V_371 -> V_89 . V_383 . V_386 ) *
sizeof( struct V_387 ) ;
V_385 = sizeof( struct V_382 ) + V_384 +
F_132 ( struct V_370 , V_89 ) ;
if ( V_81 < V_385 ) {
F_133 ( V_115 -> V_104 , L_113 ,
V_81 , V_385 ) ;
return;
}
V_383 = & V_371 -> V_89 . V_383 ;
F_133 ( V_115 -> V_104 , L_114 ,
F_9 ( V_383 -> V_388 ) ,
F_9 ( V_383 -> V_386 ) ) ;
if ( F_9 ( V_383 -> V_388 ) != 1 )
return;
for ( V_126 = 0 ; V_126 < F_9 ( V_383 -> V_386 ) ; V_126 ++ ) {
struct V_387 * V_389 =
& V_383 -> V_390 [ V_126 ] ;
bool V_391 = ! ! ( V_389 -> V_204 & V_392 ) ;
F_15 ( V_115 -> V_104 , L_115 ,
V_126 , F_9 ( V_389 -> V_204 ) , V_391 , V_389 -> V_141 ) ;
F_136 ( V_115 -> V_104 , V_126 , V_389 -> V_141 ,
V_391 , V_233 ) ;
}
}
static void F_137 ( struct V_2 * V_115 ,
struct V_393 * V_394 , int V_90 )
{
struct V_370 * V_371 ;
unsigned int V_81 , V_107 ;
V_107 = F_132 ( struct V_393 , V_106 ) +
F_9 ( V_394 -> V_107 ) ;
V_81 = F_9 ( V_394 -> V_148 ) ;
if ( V_81 < 8 ) {
F_133 ( V_115 -> V_104 , L_116 ,
V_81 ) ;
return;
}
if ( V_81 > V_90 || V_107 > V_90 || V_107 + V_81 > V_90 ) {
F_133 ( V_115 -> V_104 , L_117 ,
V_107 + V_81 , V_90 ) ;
return;
}
V_371 = ( void * ) ( ( T_2 * ) V_394 + V_107 ) ;
switch ( F_9 ( V_371 -> V_395 ) ) {
case V_396 :
F_133 ( V_115 -> V_104 , L_118 ,
F_9 ( V_371 -> V_89 . V_397 ) ) ;
return;
case V_398 :
F_133 ( V_115 -> V_104 , L_119 ,
F_9 ( V_371 -> V_89 . V_399 ) ) ;
return;
case V_400 :
F_131 ( V_115 , V_371 , V_81 ) ;
return;
case V_401 :
F_135 ( V_115 , V_371 , V_81 ) ;
return;
default:
F_133 ( V_115 -> V_104 , L_120 ,
F_9 ( V_371 -> V_395 ) ) ;
}
}
static void F_138 ( struct V_2 * V_115 , void * V_402 , int V_90 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
struct V_393 * V_394 = V_402 ;
switch ( F_9 ( V_394 -> V_106 ) ) {
case V_403 :
if ( V_5 -> V_103 == V_53 ) {
F_15 ( V_115 -> V_104 , L_121 ) ;
return;
}
F_96 ( V_115 ) ;
F_133 ( V_115 -> V_104 , L_122 ) ;
F_117 ( V_362 , & V_5 -> V_363 ) ;
F_118 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
break;
case V_404 :
F_133 ( V_115 -> V_104 , L_123 ) ;
F_117 ( V_368 , & V_5 -> V_363 ) ;
F_118 ( V_5 -> V_274 , & V_5 -> V_305 ) ;
break;
case V_405 :
F_137 ( V_115 , V_394 , V_90 ) ;
break;
default:
F_133 ( V_115 -> V_104 , L_124 ,
F_9 ( V_394 -> V_106 ) ) ;
break;
}
}
static int F_139 ( struct V_2 * V_115 , struct V_190 * V_190 )
{
struct {
T_3 V_303 ;
T_3 V_406 [ 8 ] ;
} V_407 ;
struct V_408 * V_409 ;
T_2 V_410 [ sizeof( * V_409 ) + sizeof( V_409 -> V_411 ) * 16 ] ;
int V_81 , V_412 , V_126 , V_413 ;
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_81 = sizeof( V_407 ) ;
V_412 = F_10 ( V_115 ,
V_58 ,
& V_407 , & V_81 ) ;
if ( V_412 >= 0 ) {
V_413 = F_9 ( V_407 . V_303 ) ;
if ( V_413 > 8 )
V_413 = 8 ;
for ( V_126 = 0 ; V_126 < V_413 ; V_126 ++ ) {
switch ( F_9 ( V_407 . V_406 [ V_126 ] ) ) {
case V_414 :
case V_415 :
V_5 -> V_409 |= V_416 ;
break;
case V_417 :
V_5 -> V_409 |= V_418 ;
break;
case V_419 :
V_5 -> V_409 |= V_420 ;
break;
}
}
}
V_409 = (struct V_408 * ) V_410 ;
V_81 = sizeof( V_410 ) ;
V_412 = F_10 ( V_115 ,
V_56 ,
V_409 , & V_81 ) ;
if ( V_412 >= 0 ) {
F_15 ( V_115 -> V_104 , L_125
L_126 ,
F_9 ( V_409 -> V_148 ) ,
F_9 ( V_409 -> V_388 ) ,
F_9 ( V_409 -> V_245 ) ,
F_9 ( V_409 -> V_421 ) ) ;
V_190 -> V_241 = F_9 ( V_409 -> V_245 ) ;
} else
V_190 -> V_241 = 0 ;
return V_412 ;
}
static void F_140 ( struct V_2 * V_115 , T_5 V_290 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
enum V_422 V_423 ;
int V_424 , V_425 , V_426 ;
if ( V_5 -> V_348 >= 0 || V_290 >= 0 )
return;
if ( V_5 -> V_179 != V_147 )
return;
V_426 = V_5 -> V_350 ;
V_424 = V_5 -> V_348 ;
V_425 = V_5 -> V_349 ;
if ( V_290 < V_424 && ( V_426 == 0 || V_290 < V_426 - V_425 ) )
V_423 = V_427 ;
else if ( V_290 > V_424 && ( V_426 == 0 || V_290 > V_426 + V_425 ) )
V_423 = V_428 ;
else
return;
V_5 -> V_350 = V_290 ;
F_141 ( V_115 -> V_104 , V_423 , V_96 ) ;
}
static void F_142 ( struct V_304 * V_305 )
{
struct V_1 * V_5 =
F_91 ( V_305 , struct V_1 ,
V_429 . V_305 ) ;
struct V_2 * V_115 = V_5 -> V_115 ;
T_3 V_290 , V_133 ;
int V_81 , V_70 , V_430 ;
int V_431 = V_432 ;
void * V_82 ;
if ( ! F_33 ( V_115 ) ) {
if ( V_5 -> V_271 == V_272 && V_5 -> V_140 &&
! V_5 -> V_270 ) {
F_80 ( V_115 , NULL , NULL ) ;
F_26 ( V_115 ) ;
}
goto V_433;
}
V_81 = sizeof( V_290 ) ;
V_70 = F_10 ( V_115 , V_61 ,
& V_290 , & V_81 ) ;
if ( V_70 == 0 ) {
V_5 -> V_434 = F_25 ( F_9 ( V_290 ) ) ;
F_140 ( V_115 , F_9 ( V_290 ) ) ;
}
F_15 ( V_115 -> V_104 , L_127 ,
V_70 , F_9 ( V_290 ) , F_25 ( F_9 ( V_290 ) ) ) ;
if ( V_5 -> V_435 > 0 && V_5 -> V_434 <= 25 ) {
V_430 = F_143 ( V_5 -> V_435 ) ;
if ( V_430 > V_432 )
V_430 = V_432 ;
else if ( V_430 <= 0 )
V_430 = 1 ;
V_431 = V_430 ;
V_133 = F_13 ( 1 ) ;
F_18 ( V_115 ,
V_51 ,
& V_133 , sizeof( V_133 ) ) ;
V_81 = V_94 ;
V_82 = F_11 ( V_81 , V_96 ) ;
if ( ! V_82 )
goto V_433;
F_10 ( V_115 ,
V_68 ,
V_82 , & V_81 ) ;
F_17 ( V_82 ) ;
}
V_433:
if ( V_431 >= V_273 )
V_431 = F_144 ( V_431 ) ;
else {
V_430 = F_144 ( V_431 ) ;
if ( abs ( V_430 - V_431 ) <= 10 )
V_431 = V_430 ;
}
F_81 ( V_5 -> V_274 , & V_5 -> V_429 ,
V_431 ) ;
}
static void F_145 ( struct V_2 * V_115 , int V_271 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
V_5 -> V_271 = V_271 ;
V_5 -> V_436 [ 0 ] = V_437 [ 0 ] ;
V_5 -> V_436 [ 1 ] = V_437 [ 1 ] ;
V_5 -> V_436 [ 2 ] = 0 ;
V_5 -> V_438 = V_439 ;
V_5 -> V_440 = V_441 ;
V_5 -> V_442 = V_443 ;
V_5 -> V_6 = V_444 ;
V_5 -> V_445 = V_446 ;
V_5 -> V_447 = V_448 ;
V_5 -> V_436 [ 0 ] = toupper ( V_5 -> V_436 [ 0 ] ) ;
V_5 -> V_436 [ 1 ] = toupper ( V_5 -> V_436 [ 1 ] ) ;
if ( ! strcmp ( V_5 -> V_436 , L_128 ) )
strcpy ( V_5 -> V_436 , L_129 ) ;
if ( V_5 -> V_442 < 0 )
V_5 -> V_442 = 0 ;
else if ( V_5 -> V_442 > 2 )
V_5 -> V_442 = 2 ;
if ( V_5 -> V_6 < 0 )
V_5 -> V_6 = 0 ;
else if ( V_5 -> V_6 > 3 )
V_5 -> V_6 = 3 ;
if ( V_5 -> V_445 < - 80 )
V_5 -> V_445 = - 80 ;
else if ( V_5 -> V_445 > - 60 )
V_5 -> V_445 = - 60 ;
if ( V_5 -> V_447 < 0 )
V_5 -> V_447 = 0 ;
else if ( V_5 -> V_447 > 2 )
V_5 -> V_447 = 2 ;
if ( V_449 < 0 )
V_5 -> V_435 = 500 ;
else
V_5 -> V_435 = V_449 ;
}
static int F_146 ( struct V_2 * V_115 )
{
F_145 ( V_115 , V_450 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_115 )
{
F_145 ( V_115 , V_272 ) ;
return 0 ;
}
static int F_148 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
char V_82 [ 8 ] ;
F_145 ( V_115 , V_343 ) ;
F_24 ( V_115 , L_130 , V_5 -> V_436 ) ;
F_24 ( V_115 , L_131 ,
V_5 -> V_438 ? L_132 : L_133 ) ;
F_24 ( V_115 , L_134 ,
V_5 -> V_440 ? L_132 : L_133 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_442 ) ;
F_24 ( V_115 , L_136 , V_82 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_6 ) ;
F_24 ( V_115 , L_137 , V_82 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_445 ) ;
F_24 ( V_115 , L_138 , V_82 ) ;
sprintf ( V_82 , L_135 , V_5 -> V_447 ) ;
F_24 ( V_115 , L_139 , V_82 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_115 , struct V_451 * V_452 )
{
struct V_190 * V_190 ;
struct V_1 * V_5 ;
int V_412 , V_81 ;
T_3 V_133 ;
V_190 = F_150 ( & V_453 , sizeof( struct V_1 ) ) ;
if ( ! V_190 )
return - V_97 ;
V_5 = F_73 ( V_190 ) ;
V_115 -> V_104 -> V_454 = & V_5 -> V_189 ;
V_5 -> V_189 . V_190 = V_190 ;
V_5 -> V_189 . V_258 = V_257 ;
V_115 -> V_4 = V_5 ;
V_5 -> V_115 = V_115 ;
F_151 ( & V_5 -> V_99 ) ;
V_5 -> V_274 = F_152 ( L_140 ) ;
F_153 ( & V_5 -> V_305 , F_127 ) ;
F_154 ( & V_5 -> V_429 , F_142 ) ;
F_154 ( & V_5 -> V_275 , F_90 ) ;
V_412 = F_155 ( V_115 , V_452 , V_455 ) ;
if ( V_412 < 0 )
goto V_456;
V_115 -> V_104 -> V_457 = & V_458 ;
V_133 = F_13 ( V_224 | V_225 ) ;
V_412 = F_18 ( V_115 ,
V_31 ,
& V_133 , sizeof( V_133 ) ) ;
V_81 = sizeof( V_133 ) ;
V_412 = F_10 ( V_115 ,
V_42 ,
& V_133 , & V_81 ) ;
V_5 -> V_232 = F_9 ( V_133 ) ;
if ( V_412 < 0 || V_5 -> V_232 < 0 )
V_5 -> V_232 = 0 ;
if ( V_5 -> V_232 > 0 )
V_115 -> V_104 -> V_204 |= V_459 ;
else
V_115 -> V_104 -> V_204 &= ~ V_459 ;
memcpy ( V_190 -> V_460 , V_115 -> V_104 -> V_461 , V_142 ) ;
V_190 -> V_462 = V_463 ;
V_190 -> V_464 = F_156 ( V_257 )
| F_156 ( V_256 ) ;
V_190 -> V_465 = 1 ;
F_139 ( V_115 , V_190 ) ;
memcpy ( V_5 -> V_466 , V_467 , sizeof( V_467 ) ) ;
memcpy ( V_5 -> V_468 , V_469 , sizeof( V_469 ) ) ;
V_5 -> V_470 . V_466 = V_5 -> V_466 ;
V_5 -> V_470 . V_471 = F_157 ( V_467 ) ;
V_5 -> V_470 . V_472 = V_5 -> V_468 ;
V_5 -> V_470 . V_473 = F_157 ( V_469 ) ;
V_190 -> V_474 [ V_475 ] = & V_5 -> V_470 ;
V_190 -> V_476 = V_477 ;
memcpy ( V_5 -> V_478 , V_479 ,
sizeof( V_479 ) ) ;
V_190 -> V_478 = V_5 -> V_478 ;
V_190 -> V_480 = F_157 ( V_479 ) ;
F_158 ( V_190 , & V_115 -> V_481 -> V_3 ) ;
if ( F_159 ( V_190 ) ) {
V_412 = - V_482 ;
goto V_456;
}
F_45 ( V_115 ) ;
V_5 -> V_342 = - 1 ;
F_74 ( V_190 ,
V_260 | V_261 ) ;
V_5 -> V_140 = false ;
F_35 ( V_115 , false ) ;
F_126 ( V_115 -> V_104 ) ;
return 0 ;
V_456:
F_160 ( & V_5 -> V_429 ) ;
F_160 ( & V_5 -> V_275 ) ;
F_161 ( & V_5 -> V_305 ) ;
F_162 ( V_5 -> V_274 ) ;
F_163 ( V_5 -> V_274 ) ;
F_164 ( V_190 ) ;
return V_412 ;
}
static void F_165 ( struct V_2 * V_115 , struct V_451 * V_452 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
F_35 ( V_115 , false ) ;
F_160 ( & V_5 -> V_429 ) ;
F_160 ( & V_5 -> V_275 ) ;
F_161 ( & V_5 -> V_305 ) ;
F_162 ( V_5 -> V_274 ) ;
F_163 ( V_5 -> V_274 ) ;
F_166 ( V_115 , V_452 ) ;
F_167 ( V_5 -> V_189 . V_190 ) ;
F_164 ( V_5 -> V_189 . V_190 ) ;
}
static int F_168 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_412 ;
F_15 ( V_115 -> V_104 , L_61 , V_105 ) ;
V_412 = F_19 ( V_115 ) ;
if ( V_412 )
F_28 ( V_115 -> V_104 , L_141 , V_412 ) ;
F_58 ( V_115 ) ;
F_81 ( V_5 -> V_274 , & V_5 -> V_429 ,
F_144 ( V_432 ) ) ;
return F_46 ( V_115 ) ;
}
static int F_169 ( struct V_2 * V_115 )
{
struct V_1 * V_5 = F_1 ( V_115 ) ;
int V_412 ;
T_3 V_220 ;
F_15 ( V_115 -> V_104 , L_61 , V_105 ) ;
V_412 = F_35 ( V_115 , false ) ;
V_5 -> V_363 = 0 ;
F_160 ( & V_5 -> V_429 ) ;
F_160 ( & V_5 -> V_275 ) ;
F_161 ( & V_5 -> V_305 ) ;
F_162 ( V_5 -> V_274 ) ;
if ( V_5 -> V_270 ) {
F_92 ( V_5 -> V_270 , true ) ;
V_5 -> V_270 = NULL ;
}
V_220 = 0 ;
F_18 ( V_115 , V_31 , & V_220 ,
sizeof( V_220 ) ) ;
return V_412 ;
}
