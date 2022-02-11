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
if ( V_116 == NULL )
return - V_118 ;
V_11 = F_42 ( V_116 ) ;
return snprintf ( V_5 , V_119 , L_7 , V_11 -> V_120 ) ;
}
static T_3 F_43 ( struct V_112 * V_50 ,
struct V_113 * V_114 ,
const char * V_5 , T_4 V_121 )
{
T_3 V_122 ;
unsigned V_123 ;
struct V_1 * V_115 = F_41 ( V_50 ) ;
struct V_116 * V_116 = V_115 -> V_117 ;
struct V_11 * V_11 ;
if ( V_116 == NULL )
return - V_118 ;
V_11 = F_42 ( V_116 ) ;
V_122 = sscanf ( V_5 , L_7 , & V_123 ) ;
if ( V_122 == 1 ) {
V_11 -> V_120 = V_123 ? 1 : 0 ;
V_122 = V_121 ;
} else {
V_122 = - V_107 ;
}
return V_122 ;
}
static void F_44 ( struct V_116 * V_117 )
{
memset ( & V_117 -> V_124 , 0 , sizeof( struct V_125 ) ) ;
V_117 -> V_126 = 1 ;
V_117 -> V_49 = NULL ;
V_117 -> V_127 = - 1 ;
V_117 -> V_128 = 0 ;
V_117 -> V_129 = 0 ;
V_117 -> V_130 = 0 ;
F_45 ( & V_117 -> V_131 ) ;
}
static int F_46 ( struct V_116 * V_117 )
{
int V_122 = - V_132 ;
int V_127 ;
F_47 ( & V_133 ) ;
V_127 = F_48 ( V_134 , V_135 , 1 ) ;
if ( V_127 >= V_135 ) {
F_49 ( V_136 L_8 , V_137 ) ;
goto V_138;
}
F_26 ( V_127 , V_134 ) ;
V_117 -> V_127 = V_127 ;
F_50 ( & V_117 -> V_131 , & V_139 ) ;
F_51 ( & V_133 ) ;
F_52 ( V_117 ) ;
F_53 ( V_117 -> V_79 , L_9
L_10 , V_117 -> V_127 ) ;
return 0 ;
V_138:
F_51 ( & V_133 ) ;
return V_122 ;
}
static void F_54 ( struct V_116 * V_117 )
{
F_53 ( V_117 -> V_79 , L_11 , V_117 -> V_127 ) ;
F_47 ( & V_133 ) ;
F_55 ( & V_117 -> V_131 ) ;
F_51 ( & V_133 ) ;
F_56 ( V_117 ) ;
F_25 ( V_117 -> V_127 , V_134 ) ;
}
static int F_57 ( struct V_11 * V_12 )
{
struct V_112 * V_140 = V_12 -> V_15 . V_79 ;
struct V_1 * V_141 = V_12 -> V_15 . V_49 ;
const int V_142 = 1 ;
int V_105 ;
V_141 -> V_142 = V_142 ;
V_141 -> V_117 -> V_126 = V_142 + 1 ;
memset ( & V_141 -> V_117 -> V_124 . V_143 , 0 ,
sizeof V_141 -> V_117 -> V_124 . V_143 ) ;
F_26 ( V_142 , V_141 -> V_117 -> V_124 . V_143 ) ;
F_58 ( V_141 , V_144 ) ;
F_47 ( & V_133 ) ;
V_141 -> V_145 . V_110 . V_146 = F_59 ( 64 ) ;
V_105 = F_60 ( V_141 , V_147 ) ;
if ( V_105 != sizeof V_141 -> V_148 ) {
F_51 ( & V_133 ) ;
F_16 ( V_140 , L_12 ,
F_61 ( & V_141 -> V_50 ) , V_105 ) ;
return ( V_105 < 0 ) ? V_105 : - V_149 ;
}
if ( V_141 -> V_60 == V_150 ) {
V_105 = F_62 ( V_141 ) ;
if ( V_105 < 0 ) {
F_51 ( & V_133 ) ;
F_16 ( V_140 , L_13 ,
F_61 ( & V_141 -> V_50 ) , V_105 ) ;
return V_105 ;
}
V_141 -> V_151 = F_63 ( V_141 ) ;
}
V_105 = F_64 ( V_141 ) ;
if ( V_105 ) {
F_65 ( V_140 , L_14 ,
F_61 ( & V_141 -> V_50 ) , V_105 ) ;
} else {
F_7 ( & V_37 ) ;
V_12 -> V_152 = 1 ;
F_9 ( & V_37 ) ;
if ( F_66 ( V_12 ) )
F_67 ( V_12 ) ;
}
F_51 ( & V_133 ) ;
return V_105 ;
}
void F_68 ( struct V_116 * V_117 , int V_153 )
{
unsigned V_154 = 1 << V_153 ;
if ( ! ( V_117 -> V_155 & V_154 ) ) {
V_117 -> V_155 |= V_154 ;
F_69 ( & V_117 -> V_49 -> V_50 ) ;
}
}
void F_70 ( struct V_116 * V_117 , int V_153 )
{
unsigned V_154 = 1 << V_153 ;
if ( V_117 -> V_155 & V_154 ) {
V_117 -> V_155 &= ~ V_154 ;
F_71 ( & V_117 -> V_49 -> V_50 ) ;
}
}
long F_72 ( int V_60 , int V_156 , int V_157 , int V_158 )
{
unsigned long V_159 ;
switch ( V_60 ) {
case V_160 :
if ( V_156 ) {
V_159 = ( 67667L * ( 31L + 10L * F_73 ( V_158 ) ) ) / 1000L ;
return 64060L + ( 2 * V_161 ) + V_162 + V_159 ;
} else {
V_159 = ( 66700L * ( 31L + 10L * F_73 ( V_158 ) ) ) / 1000L ;
return 64107L + ( 2 * V_161 ) + V_162 + V_159 ;
}
case V_163 :
if ( V_157 ) {
V_159 = ( 8354L * ( 31L + 10L * F_73 ( V_158 ) ) ) / 1000L ;
return ( ( V_156 ) ? 7268L : 6265L ) + V_162 + V_159 ;
} else {
V_159 = ( 8354L * ( 31L + 10L * F_73 ( V_158 ) ) ) / 1000L ;
return 9107L + V_162 + V_159 ;
}
case V_164 :
if ( V_157 )
V_159 = F_74 ( V_158 ) ;
else
V_159 = F_75 ( V_158 ) ;
return V_159 ;
default:
F_76 ( L_15 , V_137 ) ;
return - 1 ;
}
}
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_111 = 0 ;
F_77 ( & V_165 ) ;
if ( F_23 ( F_78 ( & V_22 -> V_166 ) ) ) {
V_111 = - V_167 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_109 -> V_168 ) ) {
V_111 = - V_169 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_50 -> V_170 ) ) {
V_111 = - V_171 ;
goto V_108;
}
if ( F_79 ( V_12 ) ) {
V_22 -> V_172 = 0 ;
F_80 ( & V_22 -> V_173 , & V_22 -> V_109 -> V_173 ) ;
} else {
V_111 = - V_174 ;
goto V_108;
}
V_108:
F_81 ( & V_165 ) ;
return V_111 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_175 * V_159 ;
F_82 (tmp, &urb->ep->urb_list) {
if ( V_159 == & V_22 -> V_173 )
break;
}
if ( V_159 != & V_22 -> V_173 )
return - V_176 ;
if ( V_22 -> V_172 )
return - V_177 ;
V_22 -> V_172 = V_31 ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_77 ( & V_165 ) ;
F_83 ( & V_22 -> V_173 ) ;
F_81 ( & V_165 ) ;
}
static int F_84 ( struct V_116 * V_117 ,
T_5 V_178 , T_6 * V_179 ,
void * * V_180 , T_4 V_121 ,
enum V_181 V_182 )
{
unsigned char * V_183 ;
if ( * V_180 == NULL ) {
F_85 ( 1 ) ;
return - V_184 ;
}
V_183 = F_86 ( V_117 , V_121 + sizeof( V_183 ) ,
V_178 , V_179 ) ;
if ( ! V_183 )
return - V_45 ;
F_87 ( ( unsigned long ) * V_180 ,
( unsigned long * ) ( V_183 + V_121 ) ) ;
if ( V_182 == V_185 )
memcpy ( V_183 , * V_180 , V_121 ) ;
* V_180 = V_183 ;
return 0 ;
}
static void F_88 ( struct V_116 * V_117 , T_6 * V_179 ,
void * * V_180 , T_4 V_121 ,
enum V_181 V_182 )
{
unsigned char * V_183 = * V_180 ;
V_183 = ( void * ) F_89 ( ( unsigned long * ) ( V_183 + V_121 ) ) ;
if ( V_182 == V_186 )
memcpy ( V_183 , * V_180 , V_121 ) ;
F_90 ( V_117 , V_121 + sizeof( V_183 ) , * V_180 , * V_179 ) ;
* V_180 = V_183 ;
* V_179 = 0 ;
}
void F_91 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_187 & V_188 )
F_92 ( V_12 -> V_15 . V_79 ,
V_22 -> V_189 ,
sizeof( struct V_23 ) ,
V_185 ) ;
else if ( V_22 -> V_187 & V_190 )
F_88 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_189 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_185 ) ;
V_22 -> V_187 &= ~ ( V_188 | V_190 ) ;
}
static void F_93 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_93 )
V_12 -> V_20 -> F_93 ( V_12 , V_22 ) ;
else
F_94 ( V_12 , V_22 ) ;
}
void F_94 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_181 V_182 ;
F_91 ( V_12 , V_22 ) ;
V_182 = F_95 ( V_22 ) ? V_186 : V_185 ;
if ( V_22 -> V_187 & V_191 )
F_96 ( V_12 -> V_15 . V_79 ,
V_22 -> V_192 ,
V_22 -> V_193 ,
V_182 ) ;
else if ( V_22 -> V_187 & V_194 )
F_97 ( V_12 -> V_15 . V_79 ,
V_22 -> V_195 ,
V_22 -> V_42 ,
V_182 ) ;
else if ( V_22 -> V_187 & V_196 )
F_92 ( V_12 -> V_15 . V_79 ,
V_22 -> V_195 ,
V_22 -> V_42 ,
V_182 ) ;
else if ( V_22 -> V_187 & V_197 )
F_88 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_195 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_182 ) ;
V_22 -> V_187 &= ~ ( V_191 | V_194 |
V_196 | V_197 ) ;
}
static int F_98 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_178 )
{
if ( V_12 -> V_20 -> F_98 )
return V_12 -> V_20 -> F_98 ( V_12 , V_22 , V_178 ) ;
else
return F_99 ( V_12 , V_22 , V_178 ) ;
}
int F_99 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_178 )
{
enum V_181 V_182 ;
int V_198 = 0 ;
if ( F_35 ( & V_22 -> V_109 -> V_110 ) ) {
if ( V_12 -> V_15 . V_199 )
return V_198 ;
if ( V_12 -> V_15 . V_200 ) {
V_22 -> V_189 = F_100 (
V_12 -> V_15 . V_79 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_185 ) ;
if ( F_101 ( V_12 -> V_15 . V_79 ,
V_22 -> V_189 ) )
return - V_201 ;
V_22 -> V_187 |= V_188 ;
} else if ( V_12 -> V_20 -> V_94 & V_202 ) {
V_198 = F_84 (
V_22 -> V_50 -> V_117 , V_178 ,
& V_22 -> V_189 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_185 ) ;
if ( V_198 )
return V_198 ;
V_22 -> V_187 |= V_190 ;
}
}
V_182 = F_95 ( V_22 ) ? V_186 : V_185 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_187 & V_203 ) ) {
if ( V_12 -> V_15 . V_200 ) {
if ( V_22 -> V_193 ) {
int V_7 ;
if ( F_102 ( & V_22 -> V_109 -> V_110 ) ) {
F_103 ( 1 ) ;
return - V_107 ;
}
V_7 = F_104 (
V_12 -> V_15 . V_79 ,
V_22 -> V_192 ,
V_22 -> V_193 ,
V_182 ) ;
if ( V_7 <= 0 )
V_198 = - V_201 ;
else
V_22 -> V_187 |= V_191 ;
V_22 -> V_204 = V_7 ;
if ( V_7 != V_22 -> V_193 )
V_22 -> V_187 |=
V_205 ;
} else if ( V_22 -> V_192 ) {
struct V_206 * V_192 = V_22 -> V_192 ;
V_22 -> V_195 = F_105 (
V_12 -> V_15 . V_79 ,
F_106 ( V_192 ) ,
V_192 -> V_207 ,
V_22 -> V_42 ,
V_182 ) ;
if ( F_101 ( V_12 -> V_15 . V_79 ,
V_22 -> V_195 ) )
V_198 = - V_201 ;
else
V_22 -> V_187 |= V_194 ;
} else {
V_22 -> V_195 = F_100 (
V_12 -> V_15 . V_79 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_182 ) ;
if ( F_101 ( V_12 -> V_15 . V_79 ,
V_22 -> V_195 ) )
V_198 = - V_201 ;
else
V_22 -> V_187 |= V_196 ;
}
} else if ( V_12 -> V_20 -> V_94 & V_202 ) {
V_198 = F_84 (
V_22 -> V_50 -> V_117 , V_178 ,
& V_22 -> V_195 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_182 ) ;
if ( V_198 == 0 )
V_22 -> V_187 |= V_197 ;
}
if ( V_198 && ( V_22 -> V_187 & ( V_188 |
V_190 ) ) )
F_94 ( V_12 , V_22 ) ;
}
return V_198 ;
}
int F_107 ( struct V_22 * V_22 , T_5 V_178 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
F_108 ( V_22 ) ;
F_109 ( & V_22 -> V_208 ) ;
F_109 ( & V_22 -> V_50 -> V_209 ) ;
F_110 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_50 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_98 ( V_12 , V_22 , V_178 ) ;
if ( F_111 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_210 ( V_12 , V_22 , V_178 ) ;
if ( F_23 ( V_31 ) )
F_93 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_112 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_45 ( & V_22 -> V_173 ) ;
F_113 ( & V_22 -> V_208 ) ;
F_113 ( & V_22 -> V_50 -> V_209 ) ;
if ( F_78 ( & V_22 -> V_166 ) )
F_114 ( & V_211 ) ;
F_115 ( V_22 ) ;
}
return V_31 ;
}
static int F_116 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_212 ;
if ( F_1 ( V_22 -> V_50 ) )
V_212 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_212 = V_12 -> V_20 -> V_213 ( V_12 , V_22 , V_31 ) ;
}
return V_212 ;
}
int F_117 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
int V_105 = - V_176 ;
unsigned long V_94 ;
F_24 ( & V_214 , V_94 ) ;
if ( F_78 ( & V_22 -> V_208 ) > 0 ) {
V_105 = 0 ;
F_118 ( V_22 -> V_50 ) ;
}
F_27 ( & V_214 , V_94 ) ;
if ( V_105 == 0 ) {
V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
V_105 = F_116 ( V_12 , V_22 , V_31 ) ;
F_119 ( V_22 -> V_50 ) ;
}
if ( V_105 == 0 )
V_105 = - V_215 ;
else if ( V_105 != - V_176 && V_105 != - V_177 )
F_16 ( & V_22 -> V_50 -> V_50 , L_16 ,
V_22 , V_105 ) ;
return V_105 ;
}
static void F_120 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
struct V_216 * V_217 = V_22 -> V_217 ;
int V_31 = V_22 -> V_172 ;
unsigned long V_94 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_187 & V_218 ) &&
V_22 -> V_46 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_219 ;
F_93 ( V_12 , V_22 ) ;
F_121 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_122 ( V_217 ) ;
F_123 ( V_22 ) ;
V_22 -> V_31 = V_31 ;
F_124 ( V_94 ) ;
V_22 -> V_220 ( V_22 ) ;
F_125 ( V_94 ) ;
F_126 ( V_217 ) ;
F_113 ( & V_22 -> V_208 ) ;
if ( F_23 ( F_78 ( & V_22 -> V_166 ) ) )
F_114 ( & V_211 ) ;
F_115 ( V_22 ) ;
}
static void F_127 ( unsigned long V_221 )
{
struct V_222 * V_223 = (struct V_222 * ) V_221 ;
struct V_175 V_224 ;
F_7 ( & V_223 -> V_225 ) ;
V_223 -> V_226 = true ;
V_227:
F_128 ( & V_223 -> V_228 , & V_224 ) ;
F_9 ( & V_223 -> V_225 ) ;
while ( ! F_129 ( & V_224 ) ) {
struct V_22 * V_22 ;
V_22 = F_130 ( V_224 . V_229 , struct V_22 , V_173 ) ;
F_83 ( & V_22 -> V_173 ) ;
V_223 -> V_230 = V_22 -> V_109 ;
F_120 ( V_22 ) ;
V_223 -> V_230 = NULL ;
}
F_7 ( & V_223 -> V_225 ) ;
if ( ! F_129 ( & V_223 -> V_228 ) )
goto V_227;
V_223 -> V_226 = false ;
F_9 ( & V_223 -> V_225 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_222 * V_223 ;
bool V_226 , V_231 ;
if ( F_111 ( ! V_22 -> V_172 ) )
V_22 -> V_172 = V_31 ;
if ( ! F_131 ( V_12 ) && ! F_1 ( V_22 -> V_50 ) ) {
F_120 ( V_22 ) ;
return;
}
if ( F_132 ( V_22 -> V_232 ) || F_133 ( V_22 -> V_232 ) ) {
V_223 = & V_12 -> V_231 ;
V_231 = true ;
} else {
V_223 = & V_12 -> V_233 ;
V_231 = false ;
}
F_77 ( & V_223 -> V_225 ) ;
F_80 ( & V_22 -> V_173 , & V_223 -> V_228 ) ;
V_226 = V_223 -> V_226 ;
F_81 ( & V_223 -> V_225 ) ;
if ( V_226 )
;
else if ( V_231 )
F_134 ( & V_223 -> V_223 ) ;
else
F_135 ( & V_223 -> V_223 ) ;
}
void F_136 ( struct V_1 * V_2 ,
struct V_234 * V_109 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_109 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
F_7 ( & V_165 ) ;
V_235:
F_137 (urb, &ep->urb_list, urb_list) {
int V_236 ;
if ( V_22 -> V_172 )
continue;
F_108 ( V_22 ) ;
V_236 = F_95 ( V_22 ) ;
F_81 ( & V_165 ) ;
F_116 ( V_12 , V_22 , - V_174 ) ;
F_16 (hcd->self.controller,
L_17 ,
urb, usb_endpoint_num(&ep->desc),
is_in ? L_18 : L_19 ,
({ char *s;
switch (usb_endpoint_type(&ep->desc)) {
case USB_ENDPOINT_XFER_CONTROL:
s = L_20; break;
case USB_ENDPOINT_XFER_BULK:
s = L_21; break;
case USB_ENDPOINT_XFER_INT:
s = L_22; break;
default:
s = L_23; break;
};
s;
})) ;
F_115 ( V_22 ) ;
F_77 ( & V_165 ) ;
goto V_235;
}
F_9 ( & V_165 ) ;
while ( ! F_129 ( & V_109 -> V_173 ) ) {
F_7 ( & V_165 ) ;
V_22 = NULL ;
if ( ! F_129 ( & V_109 -> V_173 ) ) {
V_22 = F_130 ( V_109 -> V_173 . V_237 , struct V_22 ,
V_173 ) ;
F_108 ( V_22 ) ;
}
F_9 ( & V_165 ) ;
if ( V_22 ) {
F_138 ( V_22 ) ;
F_115 ( V_22 ) ;
}
}
}
int F_139 ( struct V_1 * V_2 ,
struct V_238 * V_239 ,
struct V_240 * V_241 ,
struct V_240 * V_242 )
{
int V_243 , V_244 , V_245 ;
struct V_240 * V_246 = NULL ;
int V_198 = 0 ;
struct V_11 * V_12 ;
struct V_234 * V_109 ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_247 )
return 0 ;
if ( ! V_239 && ! V_241 ) {
for ( V_244 = 1 ; V_244 < 16 ; ++ V_244 ) {
V_109 = V_2 -> V_248 [ V_244 ] ;
if ( V_109 )
V_12 -> V_20 -> V_249 ( V_12 , V_2 , V_109 ) ;
V_109 = V_2 -> V_250 [ V_244 ] ;
if ( V_109 )
V_12 -> V_20 -> V_249 ( V_12 , V_2 , V_109 ) ;
}
V_12 -> V_20 -> V_247 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_239 ) {
V_243 = V_239 -> V_110 . V_251 ;
for ( V_244 = 1 ; V_244 < 16 ; ++ V_244 ) {
V_109 = V_2 -> V_248 [ V_244 ] ;
if ( V_109 ) {
V_198 = V_12 -> V_20 -> V_249 ( V_12 , V_2 , V_109 ) ;
if ( V_198 < 0 )
goto V_252;
}
V_109 = V_2 -> V_250 [ V_244 ] ;
if ( V_109 ) {
V_198 = V_12 -> V_20 -> V_249 ( V_12 , V_2 , V_109 ) ;
if ( V_198 < 0 )
goto V_252;
}
}
for ( V_244 = 0 ; V_244 < V_243 ; ++ V_244 ) {
struct V_240 * V_253 ;
int V_254 ;
V_253 = & V_239 -> V_255 [ V_244 ] -> V_256 [ 0 ] ;
V_254 = V_253 -> V_110 . V_257 ;
V_246 = F_140 ( V_239 , V_254 , 0 ) ;
if ( ! V_246 )
V_246 = V_253 ;
for ( V_245 = 0 ; V_245 < V_246 -> V_110 . V_258 ; V_245 ++ ) {
V_198 = V_12 -> V_20 -> V_259 ( V_12 , V_2 , & V_246 -> V_260 [ V_245 ] ) ;
if ( V_198 < 0 )
goto V_252;
}
}
}
if ( V_241 && V_242 ) {
struct V_261 * V_262 = F_141 ( V_2 ,
V_241 -> V_110 . V_257 ) ;
if ( ! V_262 )
return - V_107 ;
if ( V_262 -> V_263 ) {
V_241 = F_142 ( V_262 , 0 ) ;
if ( ! V_241 )
V_241 = & V_262 -> V_256 [ 0 ] ;
}
for ( V_244 = 0 ; V_244 < V_241 -> V_110 . V_258 ; V_244 ++ ) {
V_198 = V_12 -> V_20 -> V_249 ( V_12 , V_2 ,
& V_241 -> V_260 [ V_244 ] ) ;
if ( V_198 < 0 )
goto V_252;
}
for ( V_244 = 0 ; V_244 < V_242 -> V_110 . V_258 ; V_244 ++ ) {
V_198 = V_12 -> V_20 -> V_259 ( V_12 , V_2 ,
& V_242 -> V_260 [ V_244 ] ) ;
if ( V_198 < 0 )
goto V_252;
}
}
V_198 = V_12 -> V_20 -> V_247 ( V_12 , V_2 ) ;
V_252:
if ( V_198 < 0 )
V_12 -> V_20 -> V_264 ( V_12 , V_2 ) ;
return V_198 ;
}
void F_143 ( struct V_1 * V_2 ,
struct V_234 * V_109 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_265 )
V_12 -> V_20 -> V_265 ( V_12 , V_109 ) ;
}
void F_144 ( struct V_1 * V_2 ,
struct V_234 * V_109 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_266 )
V_12 -> V_20 -> V_266 ( V_12 , V_109 ) ;
else {
int V_267 = F_38 ( & V_109 -> V_110 ) ;
int V_268 = F_145 ( & V_109 -> V_110 ) ;
int V_269 = F_35 ( & V_109 -> V_110 ) ;
F_146 ( V_2 , V_267 , V_268 , 0 ) ;
if ( V_269 )
F_146 ( V_2 , V_267 , ! V_268 , 0 ) ;
}
}
int F_147 ( struct V_261 * V_270 ,
struct V_234 * * V_271 , unsigned int V_272 ,
unsigned int V_273 , T_5 V_178 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_244 ;
V_50 = F_148 ( V_270 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_274 || ! V_12 -> V_20 -> V_275 )
return - V_107 ;
if ( V_50 -> V_60 != V_150 )
return - V_107 ;
for ( V_244 = 0 ; V_244 < V_272 ; V_244 ++ )
if ( ! F_149 ( & V_271 [ V_244 ] -> V_110 ) )
return - V_107 ;
return V_12 -> V_20 -> V_274 ( V_12 , V_50 , V_271 , V_272 ,
V_273 , V_178 ) ;
}
int F_150 ( struct V_261 * V_270 ,
struct V_234 * * V_271 , unsigned int V_272 ,
T_5 V_178 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_244 ;
V_50 = F_148 ( V_270 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( V_50 -> V_60 != V_150 )
return - V_107 ;
for ( V_244 = 0 ; V_244 < V_272 ; V_244 ++ )
if ( ! V_271 [ V_244 ] || ! F_149 ( & V_271 [ V_244 ] -> V_110 ) )
return - V_107 ;
return V_12 -> V_20 -> V_275 ( V_12 , V_50 , V_271 , V_272 , V_178 ) ;
}
void F_151 ( struct V_1 * V_2 )
{
F_7 ( & V_214 ) ;
F_9 ( & V_214 ) ;
}
int F_152 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! F_79 ( V_12 ) )
return - V_174 ;
return V_12 -> V_20 -> V_276 ( V_12 ) ;
}
int F_153 ( struct V_1 * V_277 , T_7 V_278 )
{
struct V_11 * V_12 = F_154 ( V_277 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_279 = V_12 -> V_280 ;
F_16 ( & V_277 -> V_50 , L_24 ,
( F_155 ( V_278 ) ? L_25 : L_20 ) ,
V_277 -> V_281 ) ;
if ( F_66 ( V_12 ) ) {
F_16 ( & V_277 -> V_50 , L_26 , L_27 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_282 ) {
V_31 = - V_169 ;
} else {
F_25 ( V_283 , & V_12 -> V_94 ) ;
V_12 -> V_280 = V_284 ;
V_31 = V_12 -> V_20 -> V_282 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_58 ( V_277 , V_285 ) ;
V_12 -> V_280 = V_286 ;
if ( V_277 -> V_281 ) {
char V_95 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_99 ( V_12 , V_95 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_277 -> V_50 , L_28 ) ;
F_156 ( V_277 , V_287 ) ;
V_31 = - V_177 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_66 ( V_12 ) ) {
F_26 ( V_283 , & V_12 -> V_94 ) ;
V_12 -> V_280 = V_279 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_277 -> V_50 , L_29 ,
L_27 , V_31 ) ;
}
return V_31 ;
}
int F_156 ( struct V_1 * V_277 , T_7 V_278 )
{
struct V_11 * V_12 = F_154 ( V_277 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_279 = V_12 -> V_280 ;
F_16 ( & V_277 -> V_50 , L_30 ,
( F_155 ( V_278 ) ? L_25 : L_20 ) ) ;
if ( F_66 ( V_12 ) ) {
F_16 ( & V_277 -> V_50 , L_26 , L_31 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_288 )
return - V_169 ;
if ( F_79 ( V_12 ) )
return 0 ;
V_12 -> V_280 = V_289 ;
V_31 = V_12 -> V_20 -> V_288 ( V_12 ) ;
F_25 ( V_290 , & V_12 -> V_94 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_291 ;
F_7 ( & V_37 ) ;
if ( ! F_66 ( V_12 ) ) {
F_58 ( V_277 , V_277 -> V_292
? V_293
: V_144 ) ;
F_26 ( V_283 , & V_12 -> V_94 ) ;
V_12 -> V_280 = V_294 ;
}
F_9 ( & V_37 ) ;
F_157 (rhdev, port1, udev) {
if ( V_2 -> V_280 != V_295 &&
! V_2 -> V_296 ) {
F_158 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_280 = V_279 ;
F_16 ( & V_277 -> V_50 , L_29 ,
L_31 , V_31 ) ;
if ( V_31 != - V_174 )
F_67 ( V_12 ) ;
}
return V_31 ;
}
static void F_159 ( struct V_297 * V_298 )
{
struct V_11 * V_12 = F_154 ( V_298 , struct V_11 , V_299 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_49 ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
F_162 ( V_2 ) ;
}
void F_163 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_24 ( & V_37 , V_94 ) ;
if ( V_12 -> V_152 ) {
F_26 ( V_290 , & V_12 -> V_94 ) ;
F_164 ( V_300 , & V_12 -> V_299 ) ;
}
F_27 ( & V_37 , V_94 ) ;
}
int F_165 ( struct V_116 * V_117 , unsigned V_301 )
{
struct V_11 * V_12 ;
int V_31 = - V_302 ;
V_12 = F_154 ( V_117 , struct V_11 , V_15 ) ;
if ( V_301 && V_12 -> V_20 -> V_303 )
V_31 = V_12 -> V_20 -> V_303 ( V_12 , V_301 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_101 , V_102 + F_166 ( 10 ) ) ;
return V_31 ;
}
T_8 F_167 ( int V_304 , void * V_305 )
{
struct V_11 * V_12 = V_305 ;
T_8 V_111 ;
if ( F_23 ( F_66 ( V_12 ) || ! F_168 ( V_12 ) ) )
V_111 = V_306 ;
else if ( V_12 -> V_20 -> V_304 ( V_12 ) == V_306 )
V_111 = V_306 ;
else
V_111 = V_307 ;
return V_111 ;
}
void F_67 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_65 ( V_12 -> V_15 . V_79 , L_32 ) ;
F_24 ( & V_37 , V_94 ) ;
F_25 ( V_283 , & V_12 -> V_94 ) ;
F_26 ( V_308 , & V_12 -> V_94 ) ;
if ( V_12 -> V_152 ) {
F_25 ( V_309 , & V_12 -> V_94 ) ;
F_58 ( V_12 -> V_15 . V_49 ,
V_295 ) ;
F_169 ( V_12 -> V_15 . V_49 ) ;
}
if ( F_170 ( V_12 ) && V_12 -> V_310 ) {
V_12 = V_12 -> V_310 ;
if ( V_12 -> V_152 ) {
F_25 ( V_309 , & V_12 -> V_94 ) ;
F_58 ( V_12 -> V_15 . V_49 ,
V_295 ) ;
F_169 ( V_12 -> V_15 . V_49 ) ;
}
}
F_27 ( & V_37 , V_94 ) ;
}
static void F_171 ( struct V_222 * V_223 )
{
F_172 ( & V_223 -> V_225 ) ;
F_45 ( & V_223 -> V_228 ) ;
F_173 ( & V_223 -> V_223 , F_127 , ( unsigned long ) V_223 ) ;
}
struct V_11 * F_174 ( const struct V_311 * V_20 ,
struct V_112 * V_50 , const char * V_16 ,
struct V_11 * V_312 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_313 , V_44 ) ;
if ( ! V_12 ) {
F_16 ( V_50 , L_33 ) ;
return NULL ;
}
if ( V_312 == NULL ) {
V_12 -> V_314 = F_175 ( sizeof( * V_12 -> V_314 ) ,
V_44 ) ;
if ( ! V_12 -> V_314 ) {
F_19 ( V_12 ) ;
F_16 ( V_50 , L_34 ) ;
return NULL ;
}
F_176 ( V_12 -> V_314 ) ;
F_177 ( V_50 , V_12 ) ;
} else {
V_12 -> V_314 = V_312 -> V_314 ;
V_12 -> V_312 = V_312 ;
V_312 -> V_312 = V_312 ;
V_12 -> V_310 = V_312 ;
V_312 -> V_310 = V_12 ;
}
F_178 ( & V_12 -> V_315 ) ;
F_44 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_79 = V_50 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_200 = ( V_50 -> V_316 != NULL ) ;
F_179 ( & V_12 -> V_101 ) ;
V_12 -> V_101 . V_317 = F_30 ;
V_12 -> V_101 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_180
F_181 ( & V_12 -> V_299 , F_159 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_60 = V_20 -> V_94 & V_318 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_35 ;
return V_12 ;
}
struct V_11 * F_182 ( const struct V_311 * V_20 ,
struct V_112 * V_50 , const char * V_16 )
{
return F_174 ( V_20 , V_50 , V_16 , NULL ) ;
}
static void F_183 ( struct V_315 * V_315 )
{
struct V_11 * V_12 = F_154 ( V_315 , struct V_11 , V_315 ) ;
if ( F_170 ( V_12 ) )
F_19 ( V_12 -> V_314 ) ;
else
V_12 -> V_310 -> V_310 = NULL ;
F_19 ( V_12 ) ;
}
struct V_11 * F_184 ( struct V_11 * V_12 )
{
if ( V_12 )
F_185 ( & V_12 -> V_315 ) ;
return V_12 ;
}
void F_186 ( struct V_11 * V_12 )
{
if ( V_12 )
F_187 ( & V_12 -> V_315 , F_183 ) ;
}
int F_170 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_312 )
return 1 ;
return V_12 == V_12 -> V_312 ;
}
int F_188 ( struct V_11 * V_12 , int V_291 )
{
if ( ! V_12 -> V_20 -> V_319 )
return V_291 ;
return V_12 -> V_20 -> V_319 ( V_12 , V_291 ) ;
}
static int F_189 ( struct V_11 * V_12 ,
unsigned int V_320 , unsigned long V_321 )
{
int V_105 ;
if ( V_12 -> V_20 -> V_304 ) {
snprintf ( V_12 -> V_322 , sizeof( V_12 -> V_322 ) , L_36 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_127 ) ;
V_105 = F_190 ( V_320 , & F_167 , V_321 ,
V_12 -> V_322 , V_12 ) ;
if ( V_105 != 0 ) {
F_65 ( V_12 -> V_15 . V_79 ,
L_37 ,
V_320 ) ;
return V_105 ;
}
V_12 -> V_304 = V_320 ;
F_53 ( V_12 -> V_15 . V_79 , L_38 , V_320 ,
( V_12 -> V_20 -> V_94 & V_323 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_324 ) ;
} else {
V_12 -> V_304 = 0 ;
if ( V_12 -> V_324 )
F_53 ( V_12 -> V_15 . V_79 , L_41 ,
( V_12 -> V_20 -> V_94 & V_323 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_324 ) ;
}
return 0 ;
}
int F_191 ( struct V_11 * V_12 ,
unsigned int V_320 , unsigned long V_321 )
{
int V_105 ;
struct V_1 * V_277 ;
F_53 ( V_12 -> V_15 . V_79 , L_42 , V_12 -> V_17 ) ;
if ( V_120 < 0 || V_120 > 1 )
V_12 -> V_120 = V_12 -> V_325 ? 0 : 1 ;
else
V_12 -> V_120 = V_120 ;
F_26 ( V_326 , & V_12 -> V_94 ) ;
if ( ( V_105 = F_192 ( V_12 ) ) != 0 ) {
F_16 ( V_12 -> V_15 . V_79 , L_43 ) ;
return V_105 ;
}
if ( ( V_105 = F_46 ( & V_12 -> V_15 ) ) < 0 )
goto V_327;
if ( ( V_277 = F_193 ( NULL , & V_12 -> V_15 , 0 ) ) == NULL ) {
F_65 ( V_12 -> V_15 . V_79 , L_44 ) ;
V_105 = - V_45 ;
goto V_328;
}
V_12 -> V_15 . V_49 = V_277 ;
switch ( V_12 -> V_60 ) {
case V_67 :
V_277 -> V_60 = V_163 ;
break;
case V_65 :
V_277 -> V_60 = V_164 ;
break;
case V_63 :
V_277 -> V_60 = V_329 ;
break;
case V_61 :
V_277 -> V_60 = V_150 ;
break;
default:
V_105 = - V_107 ;
goto V_330;
}
F_194 ( & V_277 -> V_50 , 1 ) ;
F_26 ( V_283 , & V_12 -> V_94 ) ;
if ( V_12 -> V_20 -> V_252 && ( V_105 = V_12 -> V_20 -> V_252 ( V_12 ) ) < 0 ) {
F_65 ( V_12 -> V_15 . V_79 , L_45 , V_105 ) ;
goto V_331;
}
V_12 -> V_96 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_79 )
&& F_15 ( & V_12 -> V_15 . V_49 -> V_50 ) )
F_16 ( V_12 -> V_15 . V_79 , L_46 ) ;
F_171 ( & V_12 -> V_231 ) ;
F_171 ( & V_12 -> V_233 ) ;
if ( F_170 ( V_12 ) && V_320 ) {
V_105 = F_189 ( V_12 , V_320 , V_321 ) ;
if ( V_105 )
goto V_332;
}
V_12 -> V_280 = V_294 ;
V_105 = V_12 -> V_20 -> V_333 ( V_12 ) ;
if ( V_105 < 0 ) {
F_65 ( V_12 -> V_15 . V_79 , L_47 , V_105 ) ;
goto V_334;
}
if ( ( V_105 = F_57 ( V_12 ) ) != 0 )
goto V_335;
V_105 = F_195 ( & V_277 -> V_50 . V_336 , & V_337 ) ;
if ( V_105 < 0 ) {
F_49 ( V_136 L_48 ,
V_105 ) ;
goto V_338;
}
if ( V_12 -> V_97 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
F_196 ( V_12 -> V_15 . V_79 ) ;
return V_105 ;
V_338:
F_25 ( V_283 , & V_12 -> V_94 ) ;
if ( F_197 ( V_12 -> V_280 ) )
V_12 -> V_280 = V_284 ;
F_7 ( & V_37 ) ;
V_12 -> V_152 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_180
F_198 ( & V_12 -> V_299 ) ;
#endif
F_47 ( & V_133 ) ;
F_199 ( & V_277 ) ;
F_51 ( & V_133 ) ;
V_335:
V_12 -> V_96 = 0 ;
F_25 ( V_309 , & V_12 -> V_94 ) ;
F_200 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_339 ( V_12 ) ;
V_12 -> V_280 = V_340 ;
F_25 ( V_309 , & V_12 -> V_94 ) ;
F_200 ( & V_12 -> V_101 ) ;
V_334:
if ( F_170 ( V_12 ) && V_12 -> V_304 > 0 )
F_201 ( V_320 , V_12 ) ;
V_332:
V_331:
V_330:
F_119 ( V_12 -> V_15 . V_49 ) ;
V_328:
F_54 ( & V_12 -> V_15 ) ;
V_327:
F_202 ( V_12 ) ;
return V_105 ;
}
void F_203 ( struct V_11 * V_12 )
{
struct V_1 * V_277 = V_12 -> V_15 . V_49 ;
F_53 ( V_12 -> V_15 . V_79 , L_49 , V_12 -> V_280 ) ;
F_118 ( V_277 ) ;
F_204 ( & V_277 -> V_50 . V_336 , & V_337 ) ;
F_25 ( V_283 , & V_12 -> V_94 ) ;
if ( F_197 ( V_12 -> V_280 ) )
V_12 -> V_280 = V_284 ;
F_16 ( V_12 -> V_15 . V_79 , L_50 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_152 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_180
F_198 ( & V_12 -> V_299 ) ;
#endif
F_47 ( & V_133 ) ;
F_199 ( & V_277 ) ;
F_51 ( & V_133 ) ;
V_12 -> V_96 = 0 ;
F_25 ( V_309 , & V_12 -> V_94 ) ;
F_200 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_339 ( V_12 ) ;
V_12 -> V_280 = V_340 ;
F_25 ( V_309 , & V_12 -> V_94 ) ;
F_200 ( & V_12 -> V_101 ) ;
if ( F_170 ( V_12 ) ) {
if ( V_12 -> V_304 > 0 )
F_201 ( V_12 -> V_304 , V_12 ) ;
}
F_119 ( V_12 -> V_15 . V_49 ) ;
F_54 ( & V_12 -> V_15 ) ;
F_202 ( V_12 ) ;
}
void
F_205 ( struct V_341 * V_50 )
{
struct V_11 * V_12 = F_206 ( V_50 ) ;
if ( V_12 -> V_20 -> V_342 )
V_12 -> V_20 -> V_342 ( V_12 ) ;
}
int F_207 ( struct V_343 * V_344 )
{
if ( V_345 )
return - V_177 ;
V_345 = V_344 ;
F_208 () ;
return 0 ;
}
void F_209 ( void )
{
if ( V_345 == NULL ) {
F_49 ( V_136 L_51 ) ;
return;
}
V_345 = NULL ;
F_208 () ;
}
