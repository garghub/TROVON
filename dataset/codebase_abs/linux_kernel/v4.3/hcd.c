static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == NULL ) ;
}
static unsigned
F_2 ( char const * V_4 , T_1 * V_5 , unsigned V_6 )
{
unsigned V_7 , V_8 = 2 + 2 * strlen ( V_4 ) ;
if ( V_8 > 254 )
V_8 = 254 ;
if ( V_6 > V_8 )
V_6 = V_8 ;
V_8 += V_9 << 8 ;
V_7 = V_6 ;
while ( V_7 -- ) {
* V_5 ++ = V_8 ;
if ( ! V_7 -- )
break;
* V_5 ++ = V_8 >> 8 ;
V_8 = ( unsigned char ) * V_4 ++ ;
}
return V_6 ;
}
static unsigned
F_3 ( int V_10 , struct V_11 const * V_12 , T_1 * V_13 , unsigned V_6 )
{
char V_5 [ 100 ] ;
char const * V_4 ;
static char const V_14 [ 4 ] = { 4 , V_9 , 0x09 , 0x04 } ;
switch ( V_10 ) {
case 0 :
if ( V_6 > 4 )
V_6 = 4 ;
memcpy ( V_13 , V_14 , V_6 ) ;
return V_6 ;
case 1 :
V_4 = V_12 -> V_15 . V_16 ;
break;
case 2 :
V_4 = V_12 -> V_17 ;
break;
case 3 :
snprintf ( V_5 , sizeof V_5 , L_1 , F_4 () -> V_18 ,
F_4 () -> V_19 , V_12 -> V_20 -> V_21 ) ;
V_4 = V_5 ;
break;
default:
return 0 ;
}
return F_2 ( V_4 , V_13 , V_6 ) ;
}
static int F_5 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
struct V_23 * V_24 ;
T_2 V_25 , V_26 , V_27 , V_28 ;
T_1 * V_29 = V_22 -> V_30 ;
unsigned V_6 = 0 ;
int V_31 ;
T_1 V_32 = 0 ;
T_1 V_33 = 0 ;
T_2 V_34 ;
T_1 * V_35 = NULL ;
const T_1 * V_36 ;
F_6 () ;
F_7 ( & V_37 ) ;
V_31 = F_8 ( V_12 , V_22 ) ;
F_9 ( & V_37 ) ;
if ( V_31 )
return V_31 ;
V_22 -> V_38 = V_12 ;
V_24 = (struct V_23 * ) V_22 -> V_39 ;
V_25 = ( V_24 -> V_40 << 8 ) | V_24 -> V_41 ;
V_26 = F_10 ( V_24 -> V_26 ) ;
V_27 = F_10 ( V_24 -> V_27 ) ;
V_28 = F_10 ( V_24 -> V_28 ) ;
if ( V_28 > V_22 -> V_42 )
goto error;
V_34 = F_11 ( T_2 , sizeof( struct V_43 ) , V_28 ) ;
V_35 = F_12 ( V_34 , V_44 ) ;
if ( ! V_35 )
return - V_45 ;
V_36 = V_35 ;
V_22 -> V_46 = 0 ;
switch ( V_25 ) {
case V_47 | V_48 :
V_35 [ 0 ] = ( F_13 ( & V_12 -> V_15 . V_49 -> V_50 )
<< V_51 )
| ( 1 << V_52 ) ;
V_35 [ 1 ] = 0 ;
V_6 = 2 ;
break;
case V_53 | V_54 :
if ( V_26 == V_51 )
F_14 ( & V_12 -> V_15 . V_49 -> V_50 , 0 ) ;
else
goto error;
break;
case V_53 | V_55 :
if ( F_15 ( & V_12 -> V_15 . V_49 -> V_50 )
&& V_26 == V_51 )
F_14 ( & V_12 -> V_15 . V_49 -> V_50 , 1 ) ;
else
goto error;
break;
case V_47 | V_56 :
V_35 [ 0 ] = 1 ;
V_6 = 1 ;
case V_53 | V_57 :
break;
case V_47 | V_58 :
switch ( V_26 & 0xff00 ) {
case V_59 << 8 :
switch ( V_12 -> V_60 ) {
case V_61 :
V_36 = V_62 ;
break;
case V_63 :
V_36 = V_64 ;
break;
case V_65 :
V_36 = V_66 ;
break;
case V_67 :
V_36 = V_68 ;
break;
default:
goto error;
}
V_6 = 18 ;
if ( V_12 -> V_69 )
V_33 = 1 ;
break;
case V_70 << 8 :
switch ( V_12 -> V_60 ) {
case V_61 :
V_36 = V_71 ;
V_6 = sizeof V_71 ;
break;
case V_63 :
case V_65 :
V_36 = V_72 ;
V_6 = sizeof V_72 ;
break;
case V_67 :
V_36 = V_73 ;
V_6 = sizeof V_73 ;
break;
default:
goto error;
}
if ( F_15 ( & V_12 -> V_15 . V_49 -> V_50 ) )
V_32 = 1 ;
break;
case V_9 << 8 :
if ( ( V_26 & 0xff ) < 4 )
V_22 -> V_46 = F_3 ( V_26 & 0xff ,
V_12 , V_29 , V_28 ) ;
else
goto error;
break;
case V_74 << 8 :
goto V_75;
default:
goto error;
}
break;
case V_47 | V_76 :
V_35 [ 0 ] = 0 ;
V_6 = 1 ;
case V_53 | V_77 :
break;
case V_53 | V_78 :
F_16 ( V_12 -> V_15 . V_79 , L_2 ,
V_26 ) ;
break;
case V_80 | V_48 :
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_6 = 2 ;
case V_81 | V_54 :
case V_81 | V_55 :
F_16 ( V_12 -> V_15 . V_79 , L_3 ) ;
break;
default:
V_75:
switch ( V_25 ) {
case V_82 :
case V_83 :
V_6 = 4 ;
break;
case V_84 :
V_6 = sizeof ( struct V_43 ) ;
break;
case V_47 | V_58 :
break;
}
V_31 = V_12 -> V_20 -> V_85 ( V_12 ,
V_25 , V_26 , V_27 ,
V_35 , V_28 ) ;
if ( V_25 == V_84 )
F_17 ( V_12 -> V_15 . V_49 ,
(struct V_43 * ) V_35 ) ;
break;
error:
V_31 = - V_86 ;
}
if ( V_31 < 0 ) {
V_6 = 0 ;
if ( V_31 != - V_86 ) {
F_16 ( V_12 -> V_15 . V_79 ,
L_4
L_5 ,
V_25 , V_26 , V_27 ,
V_28 , V_31 ) ;
}
} else if ( V_31 > 0 ) {
V_6 = V_31 ;
V_31 = 0 ;
}
if ( V_6 ) {
if ( V_22 -> V_42 < V_6 )
V_6 = V_22 -> V_42 ;
V_22 -> V_46 = V_6 ;
memcpy ( V_29 , V_36 , V_6 ) ;
if ( V_32 &&
V_6 > F_18 ( struct V_87 ,
V_88 ) )
( (struct V_87 * ) V_29 ) -> V_88
|= V_89 ;
if ( V_33 &&
V_6 > F_18 ( struct V_90 ,
V_91 ) )
( (struct V_90 * ) V_29 ) ->
V_91 = V_92 ;
}
F_19 ( V_35 ) ;
F_7 ( & V_37 ) ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , V_31 ) ;
F_9 ( & V_37 ) ;
return 0 ;
}
void F_22 ( struct V_11 * V_12 )
{
struct V_22 * V_22 ;
int V_93 ;
unsigned long V_94 ;
char V_95 [ 6 ] ;
if ( F_23 ( ! V_12 -> V_96 ) )
return;
if ( ! V_12 -> V_97 && ! V_12 -> V_98 )
return;
V_93 = V_12 -> V_20 -> V_99 ( V_12 , V_95 ) ;
if ( V_93 > 0 ) {
F_24 ( & V_37 , V_94 ) ;
V_22 = V_12 -> V_98 ;
if ( V_22 ) {
F_25 ( V_100 , & V_12 -> V_94 ) ;
V_12 -> V_98 = NULL ;
V_22 -> V_46 = V_93 ;
memcpy ( V_22 -> V_30 , V_95 , V_93 ) ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , 0 ) ;
} else {
V_93 = 0 ;
F_26 ( V_100 , & V_12 -> V_94 ) ;
}
F_27 ( & V_37 , V_94 ) ;
}
if ( V_12 -> V_97 ? F_28 ( V_12 ) :
( V_93 == 0 && V_12 -> V_98 != NULL ) )
F_29 ( & V_12 -> V_101 , ( V_102 / ( V_103 / 4 ) + 1 ) * ( V_103 / 4 ) ) ;
}
static void F_30 ( unsigned long V_104 )
{
F_22 ( (struct V_11 * ) V_104 ) ;
}
static int F_31 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_105 ;
unsigned long V_94 ;
unsigned V_6 = 1 + ( V_22 -> V_50 -> V_106 / 8 ) ;
F_24 ( & V_37 , V_94 ) ;
if ( V_12 -> V_98 || V_22 -> V_42 < V_6 ) {
F_16 ( V_12 -> V_15 . V_79 , L_6 ) ;
V_105 = - V_107 ;
goto V_108;
}
V_105 = F_8 ( V_12 , V_22 ) ;
if ( V_105 )
goto V_108;
V_12 -> V_98 = V_22 ;
V_22 -> V_38 = V_12 ;
if ( ! V_12 -> V_97 )
F_29 ( & V_12 -> V_101 , ( V_102 / ( V_103 / 4 ) + 1 ) * ( V_103 / 4 ) ) ;
else if ( F_32 ( V_12 ) )
F_29 ( & V_12 -> V_101 , V_102 ) ;
V_105 = 0 ;
V_108:
F_27 ( & V_37 , V_94 ) ;
return V_105 ;
}
static int F_33 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_34 ( & V_22 -> V_109 -> V_110 ) )
return F_31 ( V_12 , V_22 ) ;
if ( F_35 ( & V_22 -> V_109 -> V_110 ) )
return F_5 ( V_12 , V_22 ) ;
return - V_107 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
unsigned long V_94 ;
int V_111 ;
F_24 ( & V_37 , V_94 ) ;
V_111 = F_37 ( V_12 , V_22 , V_31 ) ;
if ( V_111 )
goto V_108;
if ( F_38 ( & V_22 -> V_109 -> V_110 ) == 0 ) {
;
} else {
if ( ! V_12 -> V_97 )
F_39 ( & V_12 -> V_101 ) ;
if ( V_22 == V_12 -> V_98 ) {
V_12 -> V_98 = NULL ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , V_31 ) ;
}
}
V_108:
F_27 ( & V_37 , V_94 ) ;
return V_111 ;
}
static T_3 F_40 ( struct V_112 * V_50 ,
struct V_113 * V_114 , char * V_5 )
{
struct V_1 * V_115 = F_41 ( V_50 ) ;
struct V_116 * V_116 = V_115 -> V_117 ;
struct V_11 * V_11 ;
V_11 = F_42 ( V_116 ) ;
return snprintf ( V_5 , V_118 , L_7 , V_11 -> V_119 ) ;
}
static T_3 F_43 ( struct V_112 * V_50 ,
struct V_113 * V_114 ,
const char * V_5 , T_4 V_120 )
{
T_3 V_121 ;
unsigned V_122 ;
struct V_1 * V_115 = F_41 ( V_50 ) ;
struct V_116 * V_116 = V_115 -> V_117 ;
struct V_11 * V_11 ;
V_11 = F_42 ( V_116 ) ;
V_121 = sscanf ( V_5 , L_7 , & V_122 ) ;
if ( V_121 == 1 ) {
V_11 -> V_119 = V_122 ? 1 : 0 ;
V_121 = V_120 ;
} else {
V_121 = - V_107 ;
}
return V_121 ;
}
static void F_44 ( struct V_116 * V_117 )
{
memset ( & V_117 -> V_123 , 0 , sizeof( struct V_124 ) ) ;
V_117 -> V_125 = 1 ;
V_117 -> V_49 = NULL ;
V_117 -> V_126 = - 1 ;
V_117 -> V_127 = 0 ;
V_117 -> V_128 = 0 ;
V_117 -> V_129 = 0 ;
F_45 ( & V_117 -> V_130 ) ;
F_46 ( & V_117 -> V_131 ) ;
}
static int F_47 ( struct V_116 * V_117 )
{
int V_121 = - V_132 ;
int V_126 ;
F_48 ( & V_133 ) ;
V_126 = F_49 ( V_134 , V_135 , 1 ) ;
if ( V_126 >= V_135 ) {
F_50 ( V_136 L_8 , V_137 ) ;
goto V_138;
}
F_26 ( V_126 , V_134 ) ;
V_117 -> V_126 = V_126 ;
F_51 ( & V_117 -> V_131 , & V_139 ) ;
F_52 ( & V_133 ) ;
F_53 ( V_117 ) ;
F_54 ( V_117 -> V_79 , L_9
L_10 , V_117 -> V_126 ) ;
return 0 ;
V_138:
F_52 ( & V_133 ) ;
return V_121 ;
}
static void F_55 ( struct V_116 * V_117 )
{
F_54 ( V_117 -> V_79 , L_11 , V_117 -> V_126 ) ;
F_48 ( & V_133 ) ;
F_56 ( & V_117 -> V_131 ) ;
F_52 ( & V_133 ) ;
F_57 ( V_117 ) ;
F_25 ( V_117 -> V_126 , V_134 ) ;
}
static int F_58 ( struct V_11 * V_12 )
{
struct V_112 * V_140 = V_12 -> V_15 . V_79 ;
struct V_1 * V_141 = V_12 -> V_15 . V_49 ;
const int V_142 = 1 ;
int V_105 ;
V_141 -> V_142 = V_142 ;
V_141 -> V_117 -> V_125 = V_142 + 1 ;
memset ( & V_141 -> V_117 -> V_123 . V_143 , 0 ,
sizeof V_141 -> V_117 -> V_123 . V_143 ) ;
F_26 ( V_142 , V_141 -> V_117 -> V_123 . V_143 ) ;
F_59 ( V_141 , V_144 ) ;
F_48 ( & V_133 ) ;
V_141 -> V_145 . V_110 . V_146 = F_60 ( 64 ) ;
V_105 = F_61 ( V_141 , V_147 ) ;
if ( V_105 != sizeof V_141 -> V_148 ) {
F_52 ( & V_133 ) ;
F_16 ( V_140 , L_12 ,
F_62 ( & V_141 -> V_50 ) , V_105 ) ;
return ( V_105 < 0 ) ? V_105 : - V_149 ;
}
if ( F_10 ( V_141 -> V_148 . V_150 ) >= 0x0201 ) {
V_105 = F_63 ( V_141 ) ;
if ( ! V_105 ) {
V_141 -> V_151 = F_64 ( V_141 ) ;
} else if ( V_141 -> V_60 == V_152 ) {
F_52 ( & V_133 ) ;
F_16 ( V_140 , L_13 ,
F_62 ( & V_141 -> V_50 ) , V_105 ) ;
return V_105 ;
}
}
V_105 = F_65 ( V_141 ) ;
if ( V_105 ) {
F_66 ( V_140 , L_14 ,
F_62 ( & V_141 -> V_50 ) , V_105 ) ;
} else {
F_7 ( & V_37 ) ;
V_12 -> V_153 = 1 ;
F_9 ( & V_37 ) ;
if ( F_67 ( V_12 ) )
F_68 ( V_12 ) ;
}
F_52 ( & V_133 ) ;
return V_105 ;
}
void F_69 ( struct V_116 * V_117 , int V_154 )
{
unsigned V_155 = 1 << V_154 ;
if ( ! ( V_117 -> V_156 & V_155 ) ) {
V_117 -> V_156 |= V_155 ;
F_70 ( & V_117 -> V_49 -> V_50 ) ;
}
}
void F_71 ( struct V_116 * V_117 , int V_154 )
{
unsigned V_155 = 1 << V_154 ;
if ( V_117 -> V_156 & V_155 ) {
V_117 -> V_156 &= ~ V_155 ;
F_72 ( & V_117 -> V_49 -> V_50 ) ;
}
}
long F_73 ( int V_60 , int V_157 , int V_158 , int V_159 )
{
unsigned long V_160 ;
switch ( V_60 ) {
case V_161 :
if ( V_157 ) {
V_160 = ( 67667L * ( 31L + 10L * F_74 ( V_159 ) ) ) / 1000L ;
return 64060L + ( 2 * V_162 ) + V_163 + V_160 ;
} else {
V_160 = ( 66700L * ( 31L + 10L * F_74 ( V_159 ) ) ) / 1000L ;
return 64107L + ( 2 * V_162 ) + V_163 + V_160 ;
}
case V_164 :
if ( V_158 ) {
V_160 = ( 8354L * ( 31L + 10L * F_74 ( V_159 ) ) ) / 1000L ;
return ( ( V_157 ) ? 7268L : 6265L ) + V_163 + V_160 ;
} else {
V_160 = ( 8354L * ( 31L + 10L * F_74 ( V_159 ) ) ) / 1000L ;
return 9107L + V_163 + V_160 ;
}
case V_165 :
if ( V_158 )
V_160 = F_75 ( V_159 ) ;
else
V_160 = F_76 ( V_159 ) ;
return V_160 ;
default:
F_77 ( L_15 , V_137 ) ;
return - 1 ;
}
}
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_111 = 0 ;
F_78 ( & V_166 ) ;
if ( F_23 ( F_79 ( & V_22 -> V_167 ) ) ) {
V_111 = - V_168 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_109 -> V_169 ) ) {
V_111 = - V_170 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_50 -> V_171 ) ) {
V_111 = - V_172 ;
goto V_108;
}
if ( F_80 ( V_12 ) ) {
V_22 -> V_173 = 0 ;
F_81 ( & V_22 -> V_174 , & V_22 -> V_109 -> V_174 ) ;
} else {
V_111 = - V_175 ;
goto V_108;
}
V_108:
F_82 ( & V_166 ) ;
return V_111 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_176 * V_160 ;
F_83 (tmp, &urb->ep->urb_list) {
if ( V_160 == & V_22 -> V_174 )
break;
}
if ( V_160 != & V_22 -> V_174 )
return - V_177 ;
if ( V_22 -> V_173 )
return - V_178 ;
V_22 -> V_173 = V_31 ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_78 ( & V_166 ) ;
F_84 ( & V_22 -> V_174 ) ;
F_82 ( & V_166 ) ;
}
static int F_85 ( struct V_116 * V_117 ,
T_5 V_179 , T_6 * V_180 ,
void * * V_181 , T_4 V_120 ,
enum V_182 V_183 )
{
unsigned char * V_184 ;
if ( * V_181 == NULL ) {
F_86 ( 1 ) ;
return - V_185 ;
}
V_184 = F_87 ( V_117 , V_120 + sizeof( V_184 ) ,
V_179 , V_180 ) ;
if ( ! V_184 )
return - V_45 ;
F_88 ( ( unsigned long ) * V_181 ,
( unsigned long * ) ( V_184 + V_120 ) ) ;
if ( V_183 == V_186 )
memcpy ( V_184 , * V_181 , V_120 ) ;
* V_181 = V_184 ;
return 0 ;
}
static void F_89 ( struct V_116 * V_117 , T_6 * V_180 ,
void * * V_181 , T_4 V_120 ,
enum V_182 V_183 )
{
unsigned char * V_184 = * V_181 ;
V_184 = ( void * ) F_90 ( ( unsigned long * ) ( V_184 + V_120 ) ) ;
if ( V_183 == V_187 )
memcpy ( V_184 , * V_181 , V_120 ) ;
F_91 ( V_117 , V_120 + sizeof( V_184 ) , * V_181 , * V_180 ) ;
* V_181 = V_184 ;
* V_180 = 0 ;
}
void F_92 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_188 & V_189 )
F_93 ( V_12 -> V_15 . V_79 ,
V_22 -> V_190 ,
sizeof( struct V_23 ) ,
V_186 ) ;
else if ( V_22 -> V_188 & V_191 )
F_89 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_190 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_186 ) ;
V_22 -> V_188 &= ~ ( V_189 | V_191 ) ;
}
static void F_94 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_94 )
V_12 -> V_20 -> F_94 ( V_12 , V_22 ) ;
else
F_95 ( V_12 , V_22 ) ;
}
void F_95 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_182 V_183 ;
F_92 ( V_12 , V_22 ) ;
V_183 = F_96 ( V_22 ) ? V_187 : V_186 ;
if ( V_22 -> V_188 & V_192 )
F_97 ( V_12 -> V_15 . V_79 ,
V_22 -> V_193 ,
V_22 -> V_194 ,
V_183 ) ;
else if ( V_22 -> V_188 & V_195 )
F_98 ( V_12 -> V_15 . V_79 ,
V_22 -> V_196 ,
V_22 -> V_42 ,
V_183 ) ;
else if ( V_22 -> V_188 & V_197 )
F_93 ( V_12 -> V_15 . V_79 ,
V_22 -> V_196 ,
V_22 -> V_42 ,
V_183 ) ;
else if ( V_22 -> V_188 & V_198 )
F_89 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_196 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_183 ) ;
V_22 -> V_188 &= ~ ( V_192 | V_195 |
V_197 | V_198 ) ;
}
static int F_99 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_179 )
{
if ( V_12 -> V_20 -> F_99 )
return V_12 -> V_20 -> F_99 ( V_12 , V_22 , V_179 ) ;
else
return F_100 ( V_12 , V_22 , V_179 ) ;
}
int F_100 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_179 )
{
enum V_182 V_183 ;
int V_199 = 0 ;
if ( F_35 ( & V_22 -> V_109 -> V_110 ) ) {
if ( V_12 -> V_15 . V_200 )
return V_199 ;
if ( V_12 -> V_15 . V_201 ) {
V_22 -> V_190 = F_101 (
V_12 -> V_15 . V_79 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_186 ) ;
if ( F_102 ( V_12 -> V_15 . V_79 ,
V_22 -> V_190 ) )
return - V_202 ;
V_22 -> V_188 |= V_189 ;
} else if ( V_12 -> V_20 -> V_94 & V_203 ) {
V_199 = F_85 (
V_22 -> V_50 -> V_117 , V_179 ,
& V_22 -> V_190 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_186 ) ;
if ( V_199 )
return V_199 ;
V_22 -> V_188 |= V_191 ;
}
}
V_183 = F_96 ( V_22 ) ? V_187 : V_186 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_188 & V_204 ) ) {
if ( V_12 -> V_15 . V_201 ) {
if ( V_22 -> V_194 ) {
int V_7 ;
if ( F_103 ( & V_22 -> V_109 -> V_110 ) ) {
F_104 ( 1 ) ;
return - V_107 ;
}
V_7 = F_105 (
V_12 -> V_15 . V_79 ,
V_22 -> V_193 ,
V_22 -> V_194 ,
V_183 ) ;
if ( V_7 <= 0 )
V_199 = - V_202 ;
else
V_22 -> V_188 |= V_192 ;
V_22 -> V_205 = V_7 ;
if ( V_7 != V_22 -> V_194 )
V_22 -> V_188 |=
V_206 ;
} else if ( V_22 -> V_193 ) {
struct V_207 * V_193 = V_22 -> V_193 ;
V_22 -> V_196 = F_106 (
V_12 -> V_15 . V_79 ,
F_107 ( V_193 ) ,
V_193 -> V_208 ,
V_22 -> V_42 ,
V_183 ) ;
if ( F_102 ( V_12 -> V_15 . V_79 ,
V_22 -> V_196 ) )
V_199 = - V_202 ;
else
V_22 -> V_188 |= V_195 ;
} else if ( F_108 ( V_22 -> V_30 ) ) {
F_109 ( 1 , L_16 ) ;
V_199 = - V_202 ;
} else {
V_22 -> V_196 = F_101 (
V_12 -> V_15 . V_79 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_183 ) ;
if ( F_102 ( V_12 -> V_15 . V_79 ,
V_22 -> V_196 ) )
V_199 = - V_202 ;
else
V_22 -> V_188 |= V_197 ;
}
} else if ( V_12 -> V_20 -> V_94 & V_203 ) {
V_199 = F_85 (
V_22 -> V_50 -> V_117 , V_179 ,
& V_22 -> V_196 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_183 ) ;
if ( V_199 == 0 )
V_22 -> V_188 |= V_198 ;
}
if ( V_199 && ( V_22 -> V_188 & ( V_189 |
V_191 ) ) )
F_95 ( V_12 , V_22 ) ;
}
return V_199 ;
}
int F_110 ( struct V_22 * V_22 , T_5 V_179 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
F_111 ( V_22 ) ;
F_112 ( & V_22 -> V_209 ) ;
F_112 ( & V_22 -> V_50 -> V_210 ) ;
F_113 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_50 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_99 ( V_12 , V_22 , V_179 ) ;
if ( F_114 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_211 ( V_12 , V_22 , V_179 ) ;
if ( F_23 ( V_31 ) )
F_94 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_115 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_46 ( & V_22 -> V_174 ) ;
F_116 ( & V_22 -> V_209 ) ;
F_116 ( & V_22 -> V_50 -> V_210 ) ;
if ( F_79 ( & V_22 -> V_167 ) )
F_117 ( & V_212 ) ;
F_118 ( V_22 ) ;
}
return V_31 ;
}
static int F_119 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_213 ;
if ( F_1 ( V_22 -> V_50 ) )
V_213 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_213 = V_12 -> V_20 -> V_214 ( V_12 , V_22 , V_31 ) ;
}
return V_213 ;
}
int F_120 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_22 -> V_50 ;
int V_105 = - V_177 ;
unsigned long V_94 ;
F_24 ( & V_215 , V_94 ) ;
if ( F_79 ( & V_22 -> V_209 ) > 0 ) {
V_105 = 0 ;
F_121 ( V_2 ) ;
}
F_27 ( & V_215 , V_94 ) ;
if ( V_105 == 0 ) {
V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
V_105 = F_119 ( V_12 , V_22 , V_31 ) ;
if ( V_105 == 0 )
V_105 = - V_216 ;
else if ( V_105 != - V_177 && V_105 != - V_178 )
F_16 ( & V_2 -> V_50 , L_17 ,
V_22 , V_105 ) ;
F_122 ( V_2 ) ;
}
return V_105 ;
}
static void F_123 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
struct V_217 * V_218 = V_22 -> V_218 ;
int V_31 = V_22 -> V_173 ;
unsigned long V_94 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_188 & V_219 ) &&
V_22 -> V_46 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_220 ;
F_94 ( V_12 , V_22 ) ;
F_124 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_125 ( V_218 ) ;
F_126 ( V_22 ) ;
if ( F_114 ( V_31 == 0 ) )
F_127 ( V_221 ) ;
V_22 -> V_31 = V_31 ;
F_128 ( V_94 ) ;
V_22 -> V_222 ( V_22 ) ;
F_129 ( V_94 ) ;
F_130 ( V_218 ) ;
F_116 ( & V_22 -> V_209 ) ;
if ( F_23 ( F_79 ( & V_22 -> V_167 ) ) )
F_117 ( & V_212 ) ;
F_118 ( V_22 ) ;
}
static void F_131 ( unsigned long V_223 )
{
struct V_224 * V_225 = (struct V_224 * ) V_223 ;
struct V_176 V_226 ;
F_7 ( & V_225 -> V_227 ) ;
V_225 -> V_228 = true ;
V_229:
F_132 ( & V_225 -> V_230 , & V_226 ) ;
F_9 ( & V_225 -> V_227 ) ;
while ( ! F_133 ( & V_226 ) ) {
struct V_22 * V_22 ;
V_22 = F_134 ( V_226 . V_231 , struct V_22 , V_174 ) ;
F_84 ( & V_22 -> V_174 ) ;
V_225 -> V_232 = V_22 -> V_109 ;
F_123 ( V_22 ) ;
V_225 -> V_232 = NULL ;
}
F_7 ( & V_225 -> V_227 ) ;
if ( ! F_133 ( & V_225 -> V_230 ) )
goto V_229;
V_225 -> V_228 = false ;
F_9 ( & V_225 -> V_227 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_224 * V_225 ;
bool V_228 , V_233 ;
if ( F_114 ( ! V_22 -> V_173 ) )
V_22 -> V_173 = V_31 ;
if ( ! F_135 ( V_12 ) && ! F_1 ( V_22 -> V_50 ) ) {
F_123 ( V_22 ) ;
return;
}
if ( F_136 ( V_22 -> V_234 ) || F_137 ( V_22 -> V_234 ) ) {
V_225 = & V_12 -> V_233 ;
V_233 = true ;
} else {
V_225 = & V_12 -> V_235 ;
V_233 = false ;
}
F_78 ( & V_225 -> V_227 ) ;
F_81 ( & V_22 -> V_174 , & V_225 -> V_230 ) ;
V_228 = V_225 -> V_228 ;
F_82 ( & V_225 -> V_227 ) ;
if ( V_228 )
;
else if ( V_233 )
F_138 ( & V_225 -> V_225 ) ;
else
F_139 ( & V_225 -> V_225 ) ;
}
void F_140 ( struct V_1 * V_2 ,
struct V_236 * V_109 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_109 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
F_7 ( & V_166 ) ;
V_237:
F_141 (urb, &ep->urb_list, urb_list) {
int V_238 ;
if ( V_22 -> V_173 )
continue;
F_111 ( V_22 ) ;
V_238 = F_96 ( V_22 ) ;
F_82 ( & V_166 ) ;
F_119 ( V_12 , V_22 , - V_175 ) ;
F_16 (hcd->self.controller,
L_18 ,
urb, usb_endpoint_num(&ep->desc),
is_in ? L_19 : L_20 ,
({ char *s;
switch (usb_endpoint_type(&ep->desc)) {
case USB_ENDPOINT_XFER_CONTROL:
s = L_21; break;
case USB_ENDPOINT_XFER_BULK:
s = L_22; break;
case USB_ENDPOINT_XFER_INT:
s = L_23; break;
default:
s = L_24; break;
};
s;
})) ;
F_118 ( V_22 ) ;
F_78 ( & V_166 ) ;
goto V_237;
}
F_9 ( & V_166 ) ;
while ( ! F_133 ( & V_109 -> V_174 ) ) {
F_7 ( & V_166 ) ;
V_22 = NULL ;
if ( ! F_133 ( & V_109 -> V_174 ) ) {
V_22 = F_134 ( V_109 -> V_174 . V_239 , struct V_22 ,
V_174 ) ;
F_111 ( V_22 ) ;
}
F_9 ( & V_166 ) ;
if ( V_22 ) {
F_142 ( V_22 ) ;
F_118 ( V_22 ) ;
}
}
}
int F_143 ( struct V_1 * V_2 ,
struct V_240 * V_241 ,
struct V_242 * V_243 ,
struct V_242 * V_244 )
{
int V_245 , V_246 , V_247 ;
struct V_242 * V_248 = NULL ;
int V_199 = 0 ;
struct V_11 * V_12 ;
struct V_236 * V_109 ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_249 )
return 0 ;
if ( ! V_241 && ! V_243 ) {
for ( V_246 = 1 ; V_246 < 16 ; ++ V_246 ) {
V_109 = V_2 -> V_250 [ V_246 ] ;
if ( V_109 )
V_12 -> V_20 -> V_251 ( V_12 , V_2 , V_109 ) ;
V_109 = V_2 -> V_252 [ V_246 ] ;
if ( V_109 )
V_12 -> V_20 -> V_251 ( V_12 , V_2 , V_109 ) ;
}
V_12 -> V_20 -> V_249 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_241 ) {
V_245 = V_241 -> V_110 . V_253 ;
for ( V_246 = 1 ; V_246 < 16 ; ++ V_246 ) {
V_109 = V_2 -> V_250 [ V_246 ] ;
if ( V_109 ) {
V_199 = V_12 -> V_20 -> V_251 ( V_12 , V_2 , V_109 ) ;
if ( V_199 < 0 )
goto V_254;
}
V_109 = V_2 -> V_252 [ V_246 ] ;
if ( V_109 ) {
V_199 = V_12 -> V_20 -> V_251 ( V_12 , V_2 , V_109 ) ;
if ( V_199 < 0 )
goto V_254;
}
}
for ( V_246 = 0 ; V_246 < V_245 ; ++ V_246 ) {
struct V_242 * V_255 ;
int V_256 ;
V_255 = & V_241 -> V_257 [ V_246 ] -> V_258 [ 0 ] ;
V_256 = V_255 -> V_110 . V_259 ;
V_248 = F_144 ( V_241 , V_256 , 0 ) ;
if ( ! V_248 )
V_248 = V_255 ;
for ( V_247 = 0 ; V_247 < V_248 -> V_110 . V_260 ; V_247 ++ ) {
V_199 = V_12 -> V_20 -> V_261 ( V_12 , V_2 , & V_248 -> V_262 [ V_247 ] ) ;
if ( V_199 < 0 )
goto V_254;
}
}
}
if ( V_243 && V_244 ) {
struct V_263 * V_264 = F_145 ( V_2 ,
V_243 -> V_110 . V_259 ) ;
if ( ! V_264 )
return - V_107 ;
if ( V_264 -> V_265 ) {
V_243 = F_146 ( V_264 , 0 ) ;
if ( ! V_243 )
V_243 = & V_264 -> V_258 [ 0 ] ;
}
for ( V_246 = 0 ; V_246 < V_243 -> V_110 . V_260 ; V_246 ++ ) {
V_199 = V_12 -> V_20 -> V_251 ( V_12 , V_2 ,
& V_243 -> V_262 [ V_246 ] ) ;
if ( V_199 < 0 )
goto V_254;
}
for ( V_246 = 0 ; V_246 < V_244 -> V_110 . V_260 ; V_246 ++ ) {
V_199 = V_12 -> V_20 -> V_261 ( V_12 , V_2 ,
& V_244 -> V_262 [ V_246 ] ) ;
if ( V_199 < 0 )
goto V_254;
}
}
V_199 = V_12 -> V_20 -> V_249 ( V_12 , V_2 ) ;
V_254:
if ( V_199 < 0 )
V_12 -> V_20 -> V_266 ( V_12 , V_2 ) ;
return V_199 ;
}
void F_147 ( struct V_1 * V_2 ,
struct V_236 * V_109 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_267 )
V_12 -> V_20 -> V_267 ( V_12 , V_109 ) ;
}
void F_148 ( struct V_1 * V_2 ,
struct V_236 * V_109 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_268 )
V_12 -> V_20 -> V_268 ( V_12 , V_109 ) ;
else {
int V_269 = F_38 ( & V_109 -> V_110 ) ;
int V_270 = F_149 ( & V_109 -> V_110 ) ;
int V_271 = F_35 ( & V_109 -> V_110 ) ;
F_150 ( V_2 , V_269 , V_270 , 0 ) ;
if ( V_271 )
F_150 ( V_2 , V_269 , ! V_270 , 0 ) ;
}
}
int F_151 ( struct V_263 * V_272 ,
struct V_236 * * V_273 , unsigned int V_274 ,
unsigned int V_275 , T_5 V_179 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_246 , V_199 ;
V_50 = F_152 ( V_272 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_276 || ! V_12 -> V_20 -> V_277 )
return - V_107 ;
if ( V_50 -> V_60 != V_152 )
return - V_107 ;
if ( V_50 -> V_278 < V_279 )
return - V_280 ;
for ( V_246 = 0 ; V_246 < V_274 ; V_246 ++ ) {
if ( ! F_153 ( & V_273 [ V_246 ] -> V_110 ) )
return - V_107 ;
if ( V_273 [ V_246 ] -> V_281 )
return - V_107 ;
}
V_199 = V_12 -> V_20 -> V_276 ( V_12 , V_50 , V_273 , V_274 ,
V_275 , V_179 ) ;
if ( V_199 < 0 )
return V_199 ;
for ( V_246 = 0 ; V_246 < V_274 ; V_246 ++ )
V_273 [ V_246 ] -> V_281 = V_199 ;
return V_199 ;
}
int F_154 ( struct V_263 * V_272 ,
struct V_236 * * V_273 , unsigned int V_274 ,
T_5 V_179 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_246 , V_199 ;
V_50 = F_152 ( V_272 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( V_50 -> V_60 != V_152 )
return - V_107 ;
for ( V_246 = 0 ; V_246 < V_274 ; V_246 ++ )
if ( ! V_273 [ V_246 ] || ! V_273 [ V_246 ] -> V_281 )
return - V_107 ;
V_199 = V_12 -> V_20 -> V_277 ( V_12 , V_50 , V_273 , V_274 , V_179 ) ;
if ( V_199 < 0 )
return V_199 ;
for ( V_246 = 0 ; V_246 < V_274 ; V_246 ++ )
V_273 [ V_246 ] -> V_281 = 0 ;
return V_199 ;
}
void F_155 ( struct V_1 * V_2 )
{
F_7 ( & V_215 ) ;
F_9 ( & V_215 ) ;
}
int F_156 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! F_80 ( V_12 ) )
return - V_175 ;
return V_12 -> V_20 -> V_282 ( V_12 ) ;
}
int F_157 ( struct V_1 * V_283 , T_7 V_284 )
{
struct V_11 * V_12 = F_158 ( V_283 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_285 = V_12 -> V_278 ;
F_16 ( & V_283 -> V_50 , L_25 ,
( F_159 ( V_284 ) ? L_26 : L_21 ) ,
V_283 -> V_286 ) ;
if ( F_67 ( V_12 ) ) {
F_16 ( & V_283 -> V_50 , L_27 , L_28 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_287 ) {
V_31 = - V_170 ;
} else {
F_25 ( V_288 , & V_12 -> V_94 ) ;
V_12 -> V_278 = V_289 ;
V_31 = V_12 -> V_20 -> V_287 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_59 ( V_283 , V_290 ) ;
V_12 -> V_278 = V_291 ;
if ( V_283 -> V_286 ) {
char V_95 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_99 ( V_12 , V_95 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_283 -> V_50 , L_29 ) ;
F_160 ( V_283 , V_292 ) ;
V_31 = - V_178 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_67 ( V_12 ) ) {
F_26 ( V_288 , & V_12 -> V_94 ) ;
V_12 -> V_278 = V_285 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_283 -> V_50 , L_30 ,
L_28 , V_31 ) ;
}
return V_31 ;
}
int F_160 ( struct V_1 * V_283 , T_7 V_284 )
{
struct V_11 * V_12 = F_158 ( V_283 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_285 = V_12 -> V_278 ;
F_16 ( & V_283 -> V_50 , L_31 ,
( F_159 ( V_284 ) ? L_26 : L_21 ) ) ;
if ( F_67 ( V_12 ) ) {
F_16 ( & V_283 -> V_50 , L_27 , L_32 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_293 )
return - V_170 ;
if ( F_80 ( V_12 ) )
return 0 ;
V_12 -> V_278 = V_294 ;
V_31 = V_12 -> V_20 -> V_293 ( V_12 ) ;
F_25 ( V_295 , & V_12 -> V_94 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_296 ;
F_7 ( & V_37 ) ;
if ( ! F_67 ( V_12 ) ) {
F_59 ( V_283 , V_283 -> V_297
? V_279
: V_144 ) ;
F_26 ( V_288 , & V_12 -> V_94 ) ;
V_12 -> V_278 = V_298 ;
}
F_9 ( & V_37 ) ;
F_161 (rhdev, port1, udev) {
if ( V_2 -> V_278 != V_299 &&
! V_2 -> V_300 ) {
F_162 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_278 = V_285 ;
F_16 ( & V_283 -> V_50 , L_30 ,
L_32 , V_31 ) ;
if ( V_31 != - V_175 )
F_68 ( V_12 ) ;
}
return V_31 ;
}
static void F_163 ( struct V_301 * V_302 )
{
struct V_11 * V_12 = F_158 ( V_302 , struct V_11 , V_303 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_49 ;
F_164 ( V_2 ) ;
}
void F_165 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_24 ( & V_37 , V_94 ) ;
if ( V_12 -> V_153 ) {
F_26 ( V_295 , & V_12 -> V_94 ) ;
F_166 ( V_304 , & V_12 -> V_303 ) ;
}
F_27 ( & V_37 , V_94 ) ;
}
int F_167 ( struct V_116 * V_117 , unsigned V_305 )
{
struct V_11 * V_12 ;
int V_31 = - V_306 ;
V_12 = F_158 ( V_117 , struct V_11 , V_15 ) ;
if ( V_305 && V_12 -> V_20 -> V_307 )
V_31 = V_12 -> V_20 -> V_307 ( V_12 , V_305 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_101 , V_102 + F_168 ( 10 ) ) ;
return V_31 ;
}
T_8 F_169 ( int V_308 , void * V_309 )
{
struct V_11 * V_12 = V_309 ;
T_8 V_111 ;
if ( F_23 ( F_67 ( V_12 ) || ! F_170 ( V_12 ) ) )
V_111 = V_310 ;
else if ( V_12 -> V_20 -> V_308 ( V_12 ) == V_310 )
V_111 = V_310 ;
else
V_111 = V_311 ;
return V_111 ;
}
void F_68 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_66 ( V_12 -> V_15 . V_79 , L_33 ) ;
F_24 ( & V_37 , V_94 ) ;
F_25 ( V_288 , & V_12 -> V_94 ) ;
F_26 ( V_312 , & V_12 -> V_94 ) ;
if ( V_12 -> V_153 ) {
F_25 ( V_313 , & V_12 -> V_94 ) ;
F_59 ( V_12 -> V_15 . V_49 ,
V_299 ) ;
F_171 ( V_12 -> V_15 . V_49 ) ;
}
if ( F_172 ( V_12 ) && V_12 -> V_314 ) {
V_12 = V_12 -> V_314 ;
if ( V_12 -> V_153 ) {
F_25 ( V_313 , & V_12 -> V_94 ) ;
F_59 ( V_12 -> V_15 . V_49 ,
V_299 ) ;
F_171 ( V_12 -> V_15 . V_49 ) ;
}
}
F_27 ( & V_37 , V_94 ) ;
}
static void F_173 ( struct V_224 * V_225 )
{
F_174 ( & V_225 -> V_227 ) ;
F_46 ( & V_225 -> V_230 ) ;
F_175 ( & V_225 -> V_225 , F_131 , ( unsigned long ) V_225 ) ;
}
struct V_11 * F_176 ( const struct V_315 * V_20 ,
struct V_112 * V_50 , const char * V_16 ,
struct V_11 * V_316 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_317 , V_44 ) ;
if ( ! V_12 ) {
F_16 ( V_50 , L_34 ) ;
return NULL ;
}
if ( V_316 == NULL ) {
V_12 -> V_318 = F_177 ( sizeof( * V_12 -> V_318 ) ,
V_44 ) ;
if ( ! V_12 -> V_318 ) {
F_19 ( V_12 ) ;
F_16 ( V_50 , L_35 ) ;
return NULL ;
}
F_45 ( V_12 -> V_318 ) ;
F_178 ( V_50 , V_12 ) ;
} else {
F_48 ( & V_319 ) ;
V_12 -> V_318 = V_316 -> V_318 ;
V_12 -> V_316 = V_316 ;
V_316 -> V_316 = V_316 ;
V_12 -> V_314 = V_316 ;
V_316 -> V_314 = V_12 ;
F_52 ( & V_319 ) ;
}
F_179 ( & V_12 -> V_320 ) ;
F_44 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_79 = V_50 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_201 = ( V_50 -> V_321 != NULL ) ;
F_180 ( & V_12 -> V_101 ) ;
V_12 -> V_101 . V_322 = F_30 ;
V_12 -> V_101 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_181
F_182 ( & V_12 -> V_303 , F_163 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_60 = V_20 -> V_94 & V_323 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_36 ;
return V_12 ;
}
struct V_11 * F_183 ( const struct V_315 * V_20 ,
struct V_112 * V_50 , const char * V_16 )
{
return F_176 ( V_20 , V_50 , V_16 , NULL ) ;
}
static void F_184 ( struct V_320 * V_320 )
{
struct V_11 * V_12 = F_158 ( V_320 , struct V_11 , V_320 ) ;
F_48 ( & V_319 ) ;
if ( F_172 ( V_12 ) )
F_19 ( V_12 -> V_318 ) ;
if ( V_12 -> V_314 ) {
struct V_11 * V_324 = V_12 -> V_314 ;
V_324 -> V_314 = NULL ;
if ( V_324 -> V_316 == V_12 )
V_324 -> V_316 = NULL ;
}
F_52 ( & V_319 ) ;
F_19 ( V_12 ) ;
}
struct V_11 * F_185 ( struct V_11 * V_12 )
{
if ( V_12 )
F_186 ( & V_12 -> V_320 ) ;
return V_12 ;
}
void F_187 ( struct V_11 * V_12 )
{
if ( V_12 )
F_188 ( & V_12 -> V_320 , F_184 ) ;
}
int F_172 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_316 )
return 1 ;
return V_12 == V_12 -> V_316 ;
}
int F_189 ( struct V_11 * V_12 , int V_296 )
{
if ( ! V_12 -> V_20 -> V_325 )
return V_296 ;
return V_12 -> V_20 -> V_325 ( V_12 , V_296 ) ;
}
static int F_190 ( struct V_11 * V_12 ,
unsigned int V_326 , unsigned long V_327 )
{
int V_105 ;
if ( V_12 -> V_20 -> V_308 ) {
snprintf ( V_12 -> V_328 , sizeof( V_12 -> V_328 ) , L_37 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_126 ) ;
V_105 = F_191 ( V_326 , & F_169 , V_327 ,
V_12 -> V_328 , V_12 ) ;
if ( V_105 != 0 ) {
F_66 ( V_12 -> V_15 . V_79 ,
L_38 ,
V_326 ) ;
return V_105 ;
}
V_12 -> V_308 = V_326 ;
F_54 ( V_12 -> V_15 . V_79 , L_39 , V_326 ,
( V_12 -> V_20 -> V_94 & V_329 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_330 ) ;
} else {
V_12 -> V_308 = 0 ;
if ( V_12 -> V_330 )
F_54 ( V_12 -> V_15 . V_79 , L_42 ,
( V_12 -> V_20 -> V_94 & V_329 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_330 ) ;
}
return 0 ;
}
static void F_192 ( struct V_11 * V_12 )
{
struct V_1 * V_283 ;
F_48 ( & V_319 ) ;
V_283 = V_12 -> V_15 . V_49 ;
V_12 -> V_15 . V_49 = NULL ;
F_52 ( & V_319 ) ;
F_122 ( V_283 ) ;
}
int F_193 ( struct V_11 * V_12 ,
unsigned int V_326 , unsigned long V_327 )
{
int V_105 ;
struct V_1 * V_283 ;
if ( F_194 ( V_331 ) && ! V_12 -> V_332 ) {
struct V_332 * V_333 = F_195 ( V_12 -> V_15 . V_79 , 0 ) ;
if ( F_196 ( V_333 ) ) {
V_105 = F_197 ( V_333 ) ;
if ( V_105 == - V_334 )
return V_105 ;
} else {
V_105 = F_198 ( V_333 ) ;
if ( V_105 ) {
F_199 ( V_333 ) ;
return V_105 ;
}
V_12 -> V_332 = V_333 ;
V_12 -> V_335 = 1 ;
}
}
if ( F_194 ( V_336 ) && ! V_12 -> V_333 ) {
struct V_333 * V_333 = F_200 ( V_12 -> V_15 . V_79 , L_43 ) ;
if ( F_196 ( V_333 ) ) {
V_105 = F_197 ( V_333 ) ;
if ( V_105 == - V_334 )
goto V_337;
} else {
V_105 = F_201 ( V_333 ) ;
if ( V_105 ) {
F_202 ( V_333 ) ;
goto V_337;
}
V_105 = F_203 ( V_333 ) ;
if ( V_105 ) {
F_204 ( V_333 ) ;
F_202 ( V_333 ) ;
goto V_337;
}
V_12 -> V_333 = V_333 ;
V_12 -> V_335 = 1 ;
}
}
F_54 ( V_12 -> V_15 . V_79 , L_44 , V_12 -> V_17 ) ;
if ( V_119 < 0 || V_119 > 1 )
V_12 -> V_119 = V_12 -> V_338 ? 0 : 1 ;
else
V_12 -> V_119 = V_119 ;
F_26 ( V_339 , & V_12 -> V_94 ) ;
V_105 = F_205 ( V_12 ) ;
if ( V_105 != 0 ) {
F_16 ( V_12 -> V_15 . V_79 , L_45 ) ;
goto V_340;
}
V_105 = F_47 ( & V_12 -> V_15 ) ;
if ( V_105 < 0 )
goto V_341;
V_283 = F_206 ( NULL , & V_12 -> V_15 , 0 ) ;
if ( V_283 == NULL ) {
F_66 ( V_12 -> V_15 . V_79 , L_46 ) ;
V_105 = - V_45 ;
goto V_342;
}
F_48 ( & V_319 ) ;
V_12 -> V_15 . V_49 = V_283 ;
F_52 ( & V_319 ) ;
switch ( V_12 -> V_60 ) {
case V_67 :
V_283 -> V_60 = V_164 ;
break;
case V_65 :
V_283 -> V_60 = V_165 ;
break;
case V_63 :
V_283 -> V_60 = V_343 ;
break;
case V_61 :
V_283 -> V_60 = V_152 ;
break;
default:
V_105 = - V_107 ;
goto V_344;
}
F_207 ( & V_283 -> V_50 , 1 ) ;
F_26 ( V_288 , & V_12 -> V_94 ) ;
if ( V_12 -> V_20 -> V_254 ) {
V_105 = V_12 -> V_20 -> V_254 ( V_12 ) ;
if ( V_105 < 0 ) {
F_66 ( V_12 -> V_15 . V_79 , L_47 ,
V_105 ) ;
goto V_345;
}
}
V_12 -> V_96 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_79 )
&& F_15 ( & V_12 -> V_15 . V_49 -> V_50 ) )
F_16 ( V_12 -> V_15 . V_79 , L_48 ) ;
F_173 ( & V_12 -> V_233 ) ;
F_173 ( & V_12 -> V_235 ) ;
if ( F_172 ( V_12 ) && V_326 ) {
V_105 = F_190 ( V_12 , V_326 , V_327 ) ;
if ( V_105 )
goto V_346;
}
V_12 -> V_278 = V_298 ;
V_105 = V_12 -> V_20 -> V_347 ( V_12 ) ;
if ( V_105 < 0 ) {
F_66 ( V_12 -> V_15 . V_79 , L_49 , V_105 ) ;
goto V_348;
}
V_105 = F_58 ( V_12 ) ;
if ( V_105 != 0 )
goto V_349;
V_105 = F_208 ( & V_283 -> V_50 . V_350 , & V_351 ) ;
if ( V_105 < 0 ) {
F_50 ( V_136 L_50 ,
V_105 ) ;
goto V_352;
}
if ( V_12 -> V_97 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
return V_105 ;
V_352:
F_25 ( V_288 , & V_12 -> V_94 ) ;
if ( F_209 ( V_12 -> V_278 ) )
V_12 -> V_278 = V_289 ;
F_7 ( & V_37 ) ;
V_12 -> V_153 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_181
F_210 ( & V_12 -> V_303 ) ;
#endif
F_48 ( & V_133 ) ;
F_211 ( & V_283 ) ;
F_52 ( & V_133 ) ;
V_349:
V_12 -> V_96 = 0 ;
F_25 ( V_313 , & V_12 -> V_94 ) ;
F_212 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_353 ( V_12 ) ;
V_12 -> V_278 = V_354 ;
F_25 ( V_313 , & V_12 -> V_94 ) ;
F_212 ( & V_12 -> V_101 ) ;
V_348:
if ( F_172 ( V_12 ) && V_12 -> V_308 > 0 )
F_213 ( V_326 , V_12 ) ;
V_346:
V_345:
V_344:
F_192 ( V_12 ) ;
V_342:
F_55 ( & V_12 -> V_15 ) ;
V_341:
F_214 ( V_12 ) ;
V_340:
if ( F_194 ( V_336 ) && V_12 -> V_335 && V_12 -> V_333 ) {
F_215 ( V_12 -> V_333 ) ;
F_204 ( V_12 -> V_333 ) ;
F_202 ( V_12 -> V_333 ) ;
V_12 -> V_333 = NULL ;
}
V_337:
if ( V_12 -> V_335 && V_12 -> V_332 ) {
F_216 ( V_12 -> V_332 ) ;
F_199 ( V_12 -> V_332 ) ;
V_12 -> V_332 = NULL ;
}
return V_105 ;
}
void F_217 ( struct V_11 * V_12 )
{
struct V_1 * V_283 = V_12 -> V_15 . V_49 ;
F_54 ( V_12 -> V_15 . V_79 , L_51 , V_12 -> V_278 ) ;
F_121 ( V_283 ) ;
F_218 ( & V_283 -> V_50 . V_350 , & V_351 ) ;
F_25 ( V_288 , & V_12 -> V_94 ) ;
if ( F_209 ( V_12 -> V_278 ) )
V_12 -> V_278 = V_289 ;
F_16 ( V_12 -> V_15 . V_79 , L_52 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_153 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_181
F_210 ( & V_12 -> V_303 ) ;
#endif
F_48 ( & V_133 ) ;
F_211 ( & V_283 ) ;
F_52 ( & V_133 ) ;
V_12 -> V_96 = 0 ;
F_25 ( V_313 , & V_12 -> V_94 ) ;
F_212 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_353 ( V_12 ) ;
V_12 -> V_278 = V_354 ;
F_25 ( V_313 , & V_12 -> V_94 ) ;
F_212 ( & V_12 -> V_101 ) ;
if ( F_172 ( V_12 ) ) {
if ( V_12 -> V_308 > 0 )
F_213 ( V_12 -> V_308 , V_12 ) ;
}
F_55 ( & V_12 -> V_15 ) ;
F_214 ( V_12 ) ;
if ( F_194 ( V_336 ) && V_12 -> V_335 && V_12 -> V_333 ) {
F_215 ( V_12 -> V_333 ) ;
F_204 ( V_12 -> V_333 ) ;
F_202 ( V_12 -> V_333 ) ;
V_12 -> V_333 = NULL ;
}
if ( V_12 -> V_335 && V_12 -> V_332 ) {
F_216 ( V_12 -> V_332 ) ;
F_199 ( V_12 -> V_332 ) ;
V_12 -> V_332 = NULL ;
}
F_192 ( V_12 ) ;
}
void
F_219 ( struct V_355 * V_50 )
{
struct V_11 * V_12 = F_220 ( V_50 ) ;
if ( V_12 -> V_20 -> V_356 )
V_12 -> V_20 -> V_356 ( V_12 ) ;
}
int F_221 ( struct V_357 * V_358 )
{
if ( V_359 )
return - V_178 ;
V_359 = V_358 ;
F_222 () ;
return 0 ;
}
void F_223 ( void )
{
if ( V_359 == NULL ) {
F_50 ( V_136 L_53 ) ;
return;
}
V_359 = NULL ;
F_222 () ;
}
