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
T_1 V_31 [ V_32 + V_33 ]
V_34 ( ( F_6 ( 4 ) ) ) ;
const T_1 * V_35 = V_31 ;
unsigned V_6 = 0 ;
int V_36 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
F_7 () ;
F_8 ( & V_39 ) ;
V_36 = F_9 ( V_12 , V_22 ) ;
F_10 ( & V_39 ) ;
if ( V_36 )
return V_36 ;
V_22 -> V_40 = V_12 ;
V_24 = (struct V_23 * ) V_22 -> V_41 ;
V_25 = ( V_24 -> V_42 << 8 ) | V_24 -> V_43 ;
V_26 = F_11 ( V_24 -> V_26 ) ;
V_27 = F_11 ( V_24 -> V_27 ) ;
V_28 = F_11 ( V_24 -> V_28 ) ;
if ( V_28 > V_22 -> V_44 )
goto error;
V_22 -> V_45 = 0 ;
switch ( V_25 ) {
case V_46 | V_47 :
V_31 [ 0 ] = ( F_12 ( & V_12 -> V_15 . V_48 -> V_49 )
<< V_50 )
| ( 1 << V_51 ) ;
V_31 [ 1 ] = 0 ;
V_6 = 2 ;
break;
case V_52 | V_53 :
if ( V_26 == V_50 )
F_13 ( & V_12 -> V_15 . V_48 -> V_49 , 0 ) ;
else
goto error;
break;
case V_52 | V_54 :
if ( F_14 ( & V_12 -> V_15 . V_48 -> V_49 )
&& V_26 == V_50 )
F_13 ( & V_12 -> V_15 . V_48 -> V_49 , 1 ) ;
else
goto error;
break;
case V_46 | V_55 :
V_31 [ 0 ] = 1 ;
V_6 = 1 ;
case V_52 | V_56 :
break;
case V_46 | V_57 :
switch ( V_26 & 0xff00 ) {
case V_58 << 8 :
switch ( V_12 -> V_59 ) {
case V_60 :
V_35 = V_61 ;
break;
case V_62 :
V_35 = V_63 ;
break;
case V_64 :
V_35 = V_65 ;
break;
default:
goto error;
}
V_6 = 18 ;
if ( V_12 -> V_66 )
V_38 = 1 ;
break;
case V_67 << 8 :
switch ( V_12 -> V_59 ) {
case V_60 :
V_35 = V_68 ;
V_6 = sizeof V_68 ;
break;
case V_62 :
V_35 = V_69 ;
V_6 = sizeof V_69 ;
break;
case V_64 :
V_35 = V_70 ;
V_6 = sizeof V_70 ;
break;
default:
goto error;
}
if ( F_14 ( & V_12 -> V_15 . V_48 -> V_49 ) )
V_37 = 1 ;
break;
case V_9 << 8 :
if ( ( V_26 & 0xff ) < 4 )
V_22 -> V_45 = F_3 ( V_26 & 0xff ,
V_12 , V_29 , V_28 ) ;
else
goto error;
break;
case V_71 << 8 :
goto V_72;
default:
goto error;
}
break;
case V_46 | V_73 :
V_31 [ 0 ] = 0 ;
V_6 = 1 ;
case V_52 | V_74 :
break;
case V_52 | V_75 :
F_15 ( V_12 -> V_15 . V_76 , L_2 ,
V_26 ) ;
break;
case V_77 | V_47 :
V_31 [ 0 ] = 0 ;
V_31 [ 1 ] = 0 ;
V_6 = 2 ;
case V_78 | V_53 :
case V_78 | V_54 :
F_15 ( V_12 -> V_15 . V_76 , L_3 ) ;
break;
default:
V_72:
switch ( V_25 ) {
case V_79 :
case V_80 :
V_6 = 4 ;
break;
case V_81 :
V_6 = sizeof ( struct V_82 ) ;
break;
case V_46 | V_57 :
break;
}
V_36 = V_12 -> V_20 -> V_83 ( V_12 ,
V_25 , V_26 , V_27 ,
V_31 , V_28 ) ;
break;
error:
V_36 = - V_84 ;
}
if ( V_36 < 0 ) {
V_6 = 0 ;
if ( V_36 != - V_84 ) {
F_15 ( V_12 -> V_15 . V_76 ,
L_4
L_5 ,
V_25 , V_26 , V_27 ,
V_28 , V_36 ) ;
}
} else if ( V_36 > 0 ) {
V_6 = V_36 ;
V_36 = 0 ;
}
if ( V_6 ) {
if ( V_22 -> V_44 < V_6 )
V_6 = V_22 -> V_44 ;
V_22 -> V_45 = V_6 ;
memcpy ( V_29 , V_35 , V_6 ) ;
if ( V_37 &&
V_6 > F_16 ( struct V_85 ,
V_86 ) )
( (struct V_85 * ) V_29 ) -> V_86
|= V_87 ;
if ( V_38 &&
V_6 > F_16 ( struct V_88 ,
V_89 ) )
( (struct V_88 * ) V_29 ) ->
V_89 = V_90 ;
}
F_8 ( & V_39 ) ;
F_17 ( V_12 , V_22 ) ;
F_18 ( & V_39 ) ;
F_19 ( V_12 , V_22 , V_36 ) ;
F_20 ( & V_39 ) ;
F_10 ( & V_39 ) ;
return 0 ;
}
void F_21 ( struct V_11 * V_12 )
{
struct V_22 * V_22 ;
int V_91 ;
unsigned long V_92 ;
char V_93 [ 6 ] ;
if ( F_22 ( ! V_12 -> V_94 ) )
return;
if ( ! V_12 -> V_95 && ! V_12 -> V_96 )
return;
V_91 = V_12 -> V_20 -> V_97 ( V_12 , V_93 ) ;
if ( V_91 > 0 ) {
F_23 ( & V_39 , V_92 ) ;
V_22 = V_12 -> V_96 ;
if ( V_22 ) {
F_24 ( V_98 , & V_12 -> V_92 ) ;
V_12 -> V_96 = NULL ;
V_22 -> V_45 = V_91 ;
memcpy ( V_22 -> V_30 , V_93 , V_91 ) ;
F_17 ( V_12 , V_22 ) ;
F_18 ( & V_39 ) ;
F_19 ( V_12 , V_22 , 0 ) ;
F_20 ( & V_39 ) ;
} else {
V_91 = 0 ;
F_25 ( V_98 , & V_12 -> V_92 ) ;
}
F_26 ( & V_39 , V_92 ) ;
}
if ( V_12 -> V_95 ? F_27 ( V_12 ) :
( V_91 == 0 && V_12 -> V_96 != NULL ) )
F_28 ( & V_12 -> V_99 , ( V_100 / ( V_101 / 4 ) + 1 ) * ( V_101 / 4 ) ) ;
}
static void F_29 ( unsigned long V_102 )
{
F_21 ( (struct V_11 * ) V_102 ) ;
}
static int F_30 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_103 ;
unsigned long V_92 ;
unsigned V_6 = 1 + ( V_22 -> V_49 -> V_104 / 8 ) ;
F_23 ( & V_39 , V_92 ) ;
if ( V_12 -> V_96 || V_22 -> V_44 < V_6 ) {
F_15 ( V_12 -> V_15 . V_76 , L_6 ) ;
V_103 = - V_105 ;
goto V_106;
}
V_103 = F_9 ( V_12 , V_22 ) ;
if ( V_103 )
goto V_106;
V_12 -> V_96 = V_22 ;
V_22 -> V_40 = V_12 ;
if ( ! V_12 -> V_95 )
F_28 ( & V_12 -> V_99 , ( V_100 / ( V_101 / 4 ) + 1 ) * ( V_101 / 4 ) ) ;
else if ( F_31 ( V_12 ) )
F_28 ( & V_12 -> V_99 , V_100 ) ;
V_103 = 0 ;
V_106:
F_26 ( & V_39 , V_92 ) ;
return V_103 ;
}
static int F_32 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_33 ( & V_22 -> V_107 -> V_108 ) )
return F_30 ( V_12 , V_22 ) ;
if ( F_34 ( & V_22 -> V_107 -> V_108 ) )
return F_5 ( V_12 , V_22 ) ;
return - V_105 ;
}
static int F_35 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
unsigned long V_92 ;
int V_109 ;
F_23 ( & V_39 , V_92 ) ;
V_109 = F_36 ( V_12 , V_22 , V_36 ) ;
if ( V_109 )
goto V_106;
if ( F_37 ( & V_22 -> V_107 -> V_108 ) == 0 ) {
;
} else {
if ( ! V_12 -> V_95 )
F_38 ( & V_12 -> V_99 ) ;
if ( V_22 == V_12 -> V_96 ) {
V_12 -> V_96 = NULL ;
F_17 ( V_12 , V_22 ) ;
F_18 ( & V_39 ) ;
F_19 ( V_12 , V_22 , V_36 ) ;
F_20 ( & V_39 ) ;
}
}
V_106:
F_26 ( & V_39 , V_92 ) ;
return V_109 ;
}
static T_3 F_39 ( struct V_110 * V_49 ,
struct V_111 * V_112 ,
char * V_5 )
{
struct V_1 * V_113 = F_40 ( V_49 ) ;
struct V_114 * V_114 = V_113 -> V_115 ;
struct V_11 * V_11 ;
if ( V_114 == NULL )
return - V_116 ;
V_11 = F_41 ( V_114 ) ;
return snprintf ( V_5 , V_117 , L_7 , V_11 -> V_118 ) ;
}
static T_3 F_42 ( struct V_110 * V_49 ,
struct V_111 * V_112 ,
const char * V_5 , T_4 V_119 )
{
T_3 V_120 ;
unsigned V_121 ;
struct V_1 * V_113 = F_40 ( V_49 ) ;
struct V_114 * V_114 = V_113 -> V_115 ;
struct V_11 * V_11 ;
if ( V_114 == NULL )
return - V_116 ;
V_11 = F_41 ( V_114 ) ;
V_120 = sscanf ( V_5 , L_7 , & V_121 ) ;
if ( V_120 == 1 ) {
V_11 -> V_118 = V_121 ? 1 : 0 ;
V_120 = V_119 ;
}
else
V_120 = - V_105 ;
return V_120 ;
}
static void F_43 ( struct V_114 * V_115 )
{
memset ( & V_115 -> V_122 , 0 , sizeof( struct V_123 ) ) ;
V_115 -> V_124 = 1 ;
V_115 -> V_48 = NULL ;
V_115 -> V_125 = - 1 ;
V_115 -> V_126 = 0 ;
V_115 -> V_127 = 0 ;
V_115 -> V_128 = 0 ;
F_44 ( & V_115 -> V_129 ) ;
}
static int F_45 ( struct V_114 * V_115 )
{
int V_120 = - V_130 ;
int V_125 ;
F_46 ( & V_131 ) ;
V_125 = F_47 ( V_132 . V_132 , V_133 , 1 ) ;
if ( V_125 >= V_133 ) {
F_48 ( V_134 L_8 , V_135 ) ;
goto V_136;
}
F_25 ( V_125 , V_132 . V_132 ) ;
V_115 -> V_125 = V_125 ;
F_49 ( & V_115 -> V_129 , & V_137 ) ;
F_50 ( & V_131 ) ;
F_51 ( V_115 ) ;
F_52 ( V_115 -> V_76 , L_9
L_10 , V_115 -> V_125 ) ;
return 0 ;
V_136:
F_50 ( & V_131 ) ;
return V_120 ;
}
static void F_53 ( struct V_114 * V_115 )
{
F_52 ( V_115 -> V_76 , L_11 , V_115 -> V_125 ) ;
F_46 ( & V_131 ) ;
F_54 ( & V_115 -> V_129 ) ;
F_50 ( & V_131 ) ;
F_55 ( V_115 ) ;
F_24 ( V_115 -> V_125 , V_132 . V_132 ) ;
}
static int F_56 ( struct V_11 * V_12 )
{
struct V_110 * V_138 = V_12 -> V_15 . V_76 ;
struct V_1 * V_139 = V_12 -> V_15 . V_48 ;
const int V_140 = 1 ;
int V_103 ;
V_139 -> V_140 = V_140 ;
V_139 -> V_115 -> V_124 = V_140 + 1 ;
memset ( & V_139 -> V_115 -> V_122 . V_141 , 0 ,
sizeof V_139 -> V_115 -> V_122 . V_141 ) ;
F_25 ( V_140 , V_139 -> V_115 -> V_122 . V_141 ) ;
F_57 ( V_139 , V_142 ) ;
F_46 ( & V_131 ) ;
V_139 -> V_143 . V_108 . V_144 = F_58 ( 64 ) ;
V_103 = F_59 ( V_139 , V_145 ) ;
if ( V_103 != sizeof V_139 -> V_146 ) {
F_50 ( & V_131 ) ;
F_15 ( V_138 , L_12 ,
F_60 ( & V_139 -> V_49 ) , V_103 ) ;
return ( V_103 < 0 ) ? V_103 : - V_147 ;
}
V_103 = F_61 ( V_139 ) ;
if ( V_103 ) {
F_62 ( V_138 , L_13 ,
F_60 ( & V_139 -> V_49 ) , V_103 ) ;
}
F_50 ( & V_131 ) ;
if ( V_103 == 0 ) {
F_8 ( & V_39 ) ;
V_12 -> V_148 = 1 ;
F_10 ( & V_39 ) ;
if ( F_63 ( V_12 ) )
F_64 ( V_12 ) ;
}
return V_103 ;
}
long F_65 ( int V_59 , int V_149 , int V_150 , int V_151 )
{
unsigned long V_152 ;
switch ( V_59 ) {
case V_153 :
if ( V_149 ) {
V_152 = ( 67667L * ( 31L + 10L * F_66 ( V_151 ) ) ) / 1000L ;
return ( 64060L + ( 2 * V_154 ) + V_155 + V_152 ) ;
} else {
V_152 = ( 66700L * ( 31L + 10L * F_66 ( V_151 ) ) ) / 1000L ;
return ( 64107L + ( 2 * V_154 ) + V_155 + V_152 ) ;
}
case V_156 :
if ( V_150 ) {
V_152 = ( 8354L * ( 31L + 10L * F_66 ( V_151 ) ) ) / 1000L ;
return ( ( ( V_149 ) ? 7268L : 6265L ) + V_155 + V_152 ) ;
} else {
V_152 = ( 8354L * ( 31L + 10L * F_66 ( V_151 ) ) ) / 1000L ;
return ( 9107L + V_155 + V_152 ) ;
}
case V_157 :
if ( V_150 )
V_152 = F_67 ( V_151 ) ;
else
V_152 = F_68 ( V_151 ) ;
return V_152 ;
default:
F_69 ( L_14 , V_135 ) ;
return - 1 ;
}
}
int F_9 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_109 = 0 ;
F_20 ( & V_158 ) ;
if ( F_22 ( F_70 ( & V_22 -> V_159 ) ) ) {
V_109 = - V_160 ;
goto V_106;
}
if ( F_22 ( ! V_22 -> V_107 -> V_161 ) ) {
V_109 = - V_162 ;
goto V_106;
}
if ( F_22 ( ! V_22 -> V_49 -> V_163 ) ) {
V_109 = - V_164 ;
goto V_106;
}
if ( F_71 ( V_12 ) ) {
V_22 -> V_165 = 0 ;
F_72 ( & V_22 -> V_166 , & V_22 -> V_107 -> V_166 ) ;
} else {
V_109 = - V_167 ;
goto V_106;
}
V_106:
F_18 ( & V_158 ) ;
return V_109 ;
}
int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_36 )
{
struct V_168 * V_152 ;
F_73 (tmp, &urb->ep->urb_list) {
if ( V_152 == & V_22 -> V_166 )
break;
}
if ( V_152 != & V_22 -> V_166 )
return - V_169 ;
if ( V_22 -> V_165 )
return - V_170 ;
V_22 -> V_165 = V_36 ;
return 0 ;
}
void F_17 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_20 ( & V_158 ) ;
F_74 ( & V_22 -> V_166 ) ;
F_18 ( & V_158 ) ;
}
static int F_75 ( struct V_114 * V_115 ,
T_5 V_171 , T_6 * V_172 ,
void * * V_173 , T_4 V_119 ,
enum V_174 V_175 )
{
unsigned char * V_176 ;
if ( * V_173 == NULL ) {
F_76 ( 1 ) ;
return - V_177 ;
}
V_176 = F_77 ( V_115 , V_119 + sizeof( V_176 ) ,
V_171 , V_172 ) ;
if ( ! V_176 )
return - V_178 ;
F_78 ( ( unsigned long ) * V_173 ,
( unsigned long * ) ( V_176 + V_119 ) ) ;
if ( V_175 == V_179 )
memcpy ( V_176 , * V_173 , V_119 ) ;
* V_173 = V_176 ;
return 0 ;
}
static void F_79 ( struct V_114 * V_115 , T_6 * V_172 ,
void * * V_173 , T_4 V_119 ,
enum V_174 V_175 )
{
unsigned char * V_176 = * V_173 ;
V_176 = ( void * ) F_80 ( ( unsigned long * ) ( V_176 + V_119 ) ) ;
if ( V_175 == V_180 )
memcpy ( V_176 , * V_173 , V_119 ) ;
F_81 ( V_115 , V_119 + sizeof( V_176 ) , * V_173 , * V_172 ) ;
* V_173 = V_176 ;
* V_172 = 0 ;
}
void F_82 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_181 & V_182 )
F_83 ( V_12 -> V_15 . V_76 ,
V_22 -> V_183 ,
sizeof( struct V_23 ) ,
V_179 ) ;
else if ( V_22 -> V_181 & V_184 )
F_79 ( V_22 -> V_49 -> V_115 ,
& V_22 -> V_183 ,
( void * * ) & V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_179 ) ;
V_22 -> V_181 &= ~ ( V_182 | V_184 ) ;
}
static void F_84 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_84 )
V_12 -> V_20 -> F_84 ( V_12 , V_22 ) ;
else
F_85 ( V_12 , V_22 ) ;
}
void F_85 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_174 V_175 ;
F_82 ( V_12 , V_22 ) ;
V_175 = F_86 ( V_22 ) ? V_180 : V_179 ;
if ( V_22 -> V_181 & V_185 )
F_87 ( V_12 -> V_15 . V_76 ,
V_22 -> V_186 ,
V_22 -> V_187 ,
V_175 ) ;
else if ( V_22 -> V_181 & V_188 )
F_88 ( V_12 -> V_15 . V_76 ,
V_22 -> V_189 ,
V_22 -> V_44 ,
V_175 ) ;
else if ( V_22 -> V_181 & V_190 )
F_83 ( V_12 -> V_15 . V_76 ,
V_22 -> V_189 ,
V_22 -> V_44 ,
V_175 ) ;
else if ( V_22 -> V_181 & V_191 )
F_79 ( V_22 -> V_49 -> V_115 ,
& V_22 -> V_189 ,
& V_22 -> V_30 ,
V_22 -> V_44 ,
V_175 ) ;
V_22 -> V_181 &= ~ ( V_185 | V_188 |
V_190 | V_191 ) ;
}
static int F_89 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_171 )
{
if ( V_12 -> V_20 -> F_89 )
return V_12 -> V_20 -> F_89 ( V_12 , V_22 , V_171 ) ;
else
return F_90 ( V_12 , V_22 , V_171 ) ;
}
int F_90 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_171 )
{
enum V_174 V_175 ;
int V_192 = 0 ;
if ( F_34 ( & V_22 -> V_107 -> V_108 ) ) {
if ( V_12 -> V_15 . V_193 )
return V_192 ;
if ( V_12 -> V_15 . V_194 ) {
V_22 -> V_183 = F_91 (
V_12 -> V_15 . V_76 ,
V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_179 ) ;
if ( F_92 ( V_12 -> V_15 . V_76 ,
V_22 -> V_183 ) )
return - V_195 ;
V_22 -> V_181 |= V_182 ;
} else if ( V_12 -> V_20 -> V_92 & V_196 ) {
V_192 = F_75 (
V_22 -> V_49 -> V_115 , V_171 ,
& V_22 -> V_183 ,
( void * * ) & V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_179 ) ;
if ( V_192 )
return V_192 ;
V_22 -> V_181 |= V_184 ;
}
}
V_175 = F_86 ( V_22 ) ? V_180 : V_179 ;
if ( V_22 -> V_44 != 0
&& ! ( V_22 -> V_181 & V_197 ) ) {
if ( V_12 -> V_15 . V_194 ) {
if ( V_22 -> V_187 ) {
int V_7 = F_93 (
V_12 -> V_15 . V_76 ,
V_22 -> V_186 ,
V_22 -> V_187 ,
V_175 ) ;
if ( V_7 <= 0 )
V_192 = - V_195 ;
else
V_22 -> V_181 |= V_185 ;
V_22 -> V_198 = V_7 ;
if ( V_7 != V_22 -> V_187 )
V_22 -> V_181 |=
V_199 ;
} else if ( V_22 -> V_186 ) {
struct V_200 * V_186 = V_22 -> V_186 ;
V_22 -> V_189 = F_94 (
V_12 -> V_15 . V_76 ,
F_95 ( V_186 ) ,
V_186 -> V_201 ,
V_22 -> V_44 ,
V_175 ) ;
if ( F_92 ( V_12 -> V_15 . V_76 ,
V_22 -> V_189 ) )
V_192 = - V_195 ;
else
V_22 -> V_181 |= V_188 ;
} else {
V_22 -> V_189 = F_91 (
V_12 -> V_15 . V_76 ,
V_22 -> V_30 ,
V_22 -> V_44 ,
V_175 ) ;
if ( F_92 ( V_12 -> V_15 . V_76 ,
V_22 -> V_189 ) )
V_192 = - V_195 ;
else
V_22 -> V_181 |= V_190 ;
}
} else if ( V_12 -> V_20 -> V_92 & V_196 ) {
V_192 = F_75 (
V_22 -> V_49 -> V_115 , V_171 ,
& V_22 -> V_189 ,
& V_22 -> V_30 ,
V_22 -> V_44 ,
V_175 ) ;
if ( V_192 == 0 )
V_22 -> V_181 |= V_191 ;
}
if ( V_192 && ( V_22 -> V_181 & ( V_182 |
V_184 ) ) )
F_85 ( V_12 , V_22 ) ;
}
return V_192 ;
}
int F_96 ( struct V_22 * V_22 , T_5 V_171 )
{
int V_36 ;
struct V_11 * V_12 = F_41 ( V_22 -> V_49 -> V_115 ) ;
F_97 ( V_22 ) ;
F_98 ( & V_22 -> V_202 ) ;
F_98 ( & V_22 -> V_49 -> V_203 ) ;
F_99 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_49 ) ) {
V_36 = F_32 ( V_12 , V_22 ) ;
} else {
V_36 = F_89 ( V_12 , V_22 , V_171 ) ;
if ( F_100 ( V_36 == 0 ) ) {
V_36 = V_12 -> V_20 -> V_204 ( V_12 , V_22 , V_171 ) ;
if ( F_22 ( V_36 ) )
F_84 ( V_12 , V_22 ) ;
}
}
if ( F_22 ( V_36 ) ) {
F_101 ( & V_12 -> V_15 , V_22 , V_36 ) ;
V_22 -> V_40 = NULL ;
F_44 ( & V_22 -> V_166 ) ;
F_102 ( & V_22 -> V_202 ) ;
F_102 ( & V_22 -> V_49 -> V_203 ) ;
if ( F_70 ( & V_22 -> V_159 ) )
F_103 ( & V_205 ) ;
F_104 ( V_22 ) ;
}
return V_36 ;
}
static int F_105 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
int V_206 ;
if ( F_1 ( V_22 -> V_49 ) )
V_206 = F_35 ( V_12 , V_22 , V_36 ) ;
else {
V_206 = V_12 -> V_20 -> V_207 ( V_12 , V_22 , V_36 ) ;
}
return V_206 ;
}
int F_106 ( struct V_22 * V_22 , int V_36 )
{
struct V_11 * V_12 ;
int V_103 = - V_169 ;
unsigned long V_92 ;
F_23 ( & V_208 , V_92 ) ;
if ( F_70 ( & V_22 -> V_202 ) > 0 ) {
V_103 = 0 ;
F_107 ( V_22 -> V_49 ) ;
}
F_26 ( & V_208 , V_92 ) ;
if ( V_103 == 0 ) {
V_12 = F_41 ( V_22 -> V_49 -> V_115 ) ;
V_103 = F_105 ( V_12 , V_22 , V_36 ) ;
F_108 ( V_22 -> V_49 ) ;
}
if ( V_103 == 0 )
V_103 = - V_209 ;
else if ( V_103 != - V_169 && V_103 != - V_170 )
F_15 ( & V_22 -> V_49 -> V_49 , L_15 ,
V_22 , V_103 ) ;
return V_103 ;
}
void F_19 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
V_22 -> V_40 = NULL ;
if ( F_22 ( V_22 -> V_165 ) )
V_36 = V_22 -> V_165 ;
else if ( F_22 ( ( V_22 -> V_181 & V_210 ) &&
V_22 -> V_45 < V_22 -> V_44 &&
! V_36 ) )
V_36 = - V_211 ;
F_84 ( V_12 , V_22 ) ;
F_109 ( & V_12 -> V_15 , V_22 , V_36 ) ;
F_110 ( V_22 ) ;
V_22 -> V_36 = V_36 ;
V_22 -> V_212 ( V_22 ) ;
F_102 ( & V_22 -> V_202 ) ;
if ( F_22 ( F_70 ( & V_22 -> V_159 ) ) )
F_103 ( & V_205 ) ;
F_104 ( V_22 ) ;
}
void F_111 ( struct V_1 * V_2 ,
struct V_213 * V_107 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_107 )
return;
F_7 () ;
V_12 = F_41 ( V_2 -> V_115 ) ;
F_8 ( & V_158 ) ;
V_214:
F_112 (urb, &ep->urb_list, urb_list) {
int V_215 ;
if ( V_22 -> V_165 )
continue;
F_97 ( V_22 ) ;
V_215 = F_86 ( V_22 ) ;
F_18 ( & V_158 ) ;
F_105 ( V_12 , V_22 , - V_167 ) ;
F_15 (hcd->self.controller,
L_16 ,
urb, usb_endpoint_num(&ep->desc),
is_in ? L_17 : L_18 ,
({ char *s;
switch (usb_endpoint_type(&ep->desc)) {
case USB_ENDPOINT_XFER_CONTROL:
s = L_19; break;
case USB_ENDPOINT_XFER_BULK:
s = L_20; break;
case USB_ENDPOINT_XFER_INT:
s = L_21; break;
default:
s = L_22; break;
};
s;
})) ;
F_104 ( V_22 ) ;
F_20 ( & V_158 ) ;
goto V_214;
}
F_10 ( & V_158 ) ;
while ( ! F_113 ( & V_107 -> V_166 ) ) {
F_8 ( & V_158 ) ;
V_22 = NULL ;
if ( ! F_113 ( & V_107 -> V_166 ) ) {
V_22 = F_114 ( V_107 -> V_166 . V_216 , struct V_22 ,
V_166 ) ;
F_97 ( V_22 ) ;
}
F_10 ( & V_158 ) ;
if ( V_22 ) {
F_115 ( V_22 ) ;
F_104 ( V_22 ) ;
}
}
}
int F_116 ( struct V_1 * V_2 ,
struct V_217 * V_218 ,
struct V_219 * V_220 ,
struct V_219 * V_221 )
{
int V_222 , V_223 , V_224 ;
struct V_219 * V_225 = NULL ;
int V_192 = 0 ;
struct V_11 * V_12 ;
struct V_213 * V_107 ;
V_12 = F_41 ( V_2 -> V_115 ) ;
if ( ! V_12 -> V_20 -> V_226 )
return 0 ;
if ( ! V_218 && ! V_220 ) {
for ( V_223 = 1 ; V_223 < 16 ; ++ V_223 ) {
V_107 = V_2 -> V_227 [ V_223 ] ;
if ( V_107 )
V_12 -> V_20 -> V_228 ( V_12 , V_2 , V_107 ) ;
V_107 = V_2 -> V_229 [ V_223 ] ;
if ( V_107 )
V_12 -> V_20 -> V_228 ( V_12 , V_2 , V_107 ) ;
}
V_12 -> V_20 -> V_226 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_218 ) {
V_222 = V_218 -> V_108 . V_230 ;
for ( V_223 = 1 ; V_223 < 16 ; ++ V_223 ) {
V_107 = V_2 -> V_227 [ V_223 ] ;
if ( V_107 ) {
V_192 = V_12 -> V_20 -> V_228 ( V_12 , V_2 , V_107 ) ;
if ( V_192 < 0 )
goto V_231;
}
V_107 = V_2 -> V_229 [ V_223 ] ;
if ( V_107 ) {
V_192 = V_12 -> V_20 -> V_228 ( V_12 , V_2 , V_107 ) ;
if ( V_192 < 0 )
goto V_231;
}
}
for ( V_223 = 0 ; V_223 < V_222 ; ++ V_223 ) {
struct V_219 * V_232 ;
int V_233 ;
V_232 = & V_218 -> V_234 [ V_223 ] -> V_235 [ 0 ] ;
V_233 = V_232 -> V_108 . V_236 ;
V_225 = F_117 ( V_218 , V_233 , 0 ) ;
if ( ! V_225 )
V_225 = V_232 ;
for ( V_224 = 0 ; V_224 < V_225 -> V_108 . V_237 ; V_224 ++ ) {
V_192 = V_12 -> V_20 -> V_238 ( V_12 , V_2 , & V_225 -> V_239 [ V_224 ] ) ;
if ( V_192 < 0 )
goto V_231;
}
}
}
if ( V_220 && V_221 ) {
struct V_240 * V_241 = F_118 ( V_2 ,
V_220 -> V_108 . V_236 ) ;
if ( ! V_241 )
return - V_105 ;
if ( V_241 -> V_242 ) {
V_220 = F_119 ( V_241 , 0 ) ;
if ( ! V_220 )
V_220 = & V_241 -> V_235 [ 0 ] ;
}
for ( V_223 = 0 ; V_223 < V_220 -> V_108 . V_237 ; V_223 ++ ) {
V_192 = V_12 -> V_20 -> V_228 ( V_12 , V_2 ,
& V_220 -> V_239 [ V_223 ] ) ;
if ( V_192 < 0 )
goto V_231;
}
for ( V_223 = 0 ; V_223 < V_221 -> V_108 . V_237 ; V_223 ++ ) {
V_192 = V_12 -> V_20 -> V_238 ( V_12 , V_2 ,
& V_221 -> V_239 [ V_223 ] ) ;
if ( V_192 < 0 )
goto V_231;
}
}
V_192 = V_12 -> V_20 -> V_226 ( V_12 , V_2 ) ;
V_231:
if ( V_192 < 0 )
V_12 -> V_20 -> V_243 ( V_12 , V_2 ) ;
return V_192 ;
}
void F_120 ( struct V_1 * V_2 ,
struct V_213 * V_107 )
{
struct V_11 * V_12 ;
F_7 () ;
V_12 = F_41 ( V_2 -> V_115 ) ;
if ( V_12 -> V_20 -> V_244 )
V_12 -> V_20 -> V_244 ( V_12 , V_107 ) ;
}
void F_121 ( struct V_1 * V_2 ,
struct V_213 * V_107 )
{
struct V_11 * V_12 = F_41 ( V_2 -> V_115 ) ;
if ( V_12 -> V_20 -> V_245 )
V_12 -> V_20 -> V_245 ( V_12 , V_107 ) ;
else {
int V_246 = F_37 ( & V_107 -> V_108 ) ;
int V_247 = F_122 ( & V_107 -> V_108 ) ;
int V_248 = F_34 ( & V_107 -> V_108 ) ;
F_123 ( V_2 , V_246 , V_247 , 0 ) ;
if ( V_248 )
F_123 ( V_2 , V_246 , ! V_247 , 0 ) ;
}
}
int F_124 ( struct V_240 * V_249 ,
struct V_213 * * V_250 , unsigned int V_251 ,
unsigned int V_252 , T_5 V_171 )
{
struct V_11 * V_12 ;
struct V_1 * V_49 ;
int V_223 ;
V_49 = F_125 ( V_249 ) ;
V_12 = F_41 ( V_49 -> V_115 ) ;
if ( ! V_12 -> V_20 -> V_253 || ! V_12 -> V_20 -> V_254 )
return - V_105 ;
if ( V_49 -> V_59 != V_255 )
return - V_105 ;
for ( V_223 = 0 ; V_223 < V_251 ; V_223 ++ )
if ( ! F_126 ( & V_250 [ V_223 ] -> V_108 ) )
return - V_105 ;
return V_12 -> V_20 -> V_253 ( V_12 , V_49 , V_250 , V_251 ,
V_252 , V_171 ) ;
}
void F_127 ( struct V_240 * V_249 ,
struct V_213 * * V_250 , unsigned int V_251 ,
T_5 V_171 )
{
struct V_11 * V_12 ;
struct V_1 * V_49 ;
int V_223 ;
V_49 = F_125 ( V_249 ) ;
V_12 = F_41 ( V_49 -> V_115 ) ;
if ( V_49 -> V_59 != V_255 )
return;
for ( V_223 = 0 ; V_223 < V_251 ; V_223 ++ )
if ( ! V_250 [ V_223 ] || ! F_126 ( & V_250 [ V_223 ] -> V_108 ) )
return;
V_12 -> V_20 -> V_254 ( V_12 , V_49 , V_250 , V_251 , V_171 ) ;
}
void F_128 ( struct V_1 * V_2 )
{
F_8 ( & V_208 ) ;
F_10 ( & V_208 ) ;
}
int F_129 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_41 ( V_2 -> V_115 ) ;
if ( ! F_71 ( V_12 ) )
return - V_167 ;
return V_12 -> V_20 -> V_256 ( V_12 ) ;
}
int F_130 ( struct V_1 * V_257 , T_7 V_258 )
{
struct V_11 * V_12 = F_131 ( V_257 -> V_115 , struct V_11 , V_15 ) ;
int V_36 ;
int V_259 = V_12 -> V_260 ;
F_15 ( & V_257 -> V_49 , L_23 ,
( F_132 ( V_258 ) ? L_24 : L_19 ) ,
V_257 -> V_261 ) ;
if ( F_63 ( V_12 ) ) {
F_15 ( & V_257 -> V_49 , L_25 , L_26 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_262 ) {
V_36 = - V_162 ;
} else {
F_24 ( V_263 , & V_12 -> V_92 ) ;
V_12 -> V_260 = V_264 ;
V_36 = V_12 -> V_20 -> V_262 ( V_12 ) ;
}
if ( V_36 == 0 ) {
F_57 ( V_257 , V_265 ) ;
V_12 -> V_260 = V_266 ;
} else {
F_8 ( & V_39 ) ;
if ( ! F_63 ( V_12 ) ) {
F_25 ( V_263 , & V_12 -> V_92 ) ;
V_12 -> V_260 = V_259 ;
}
F_10 ( & V_39 ) ;
F_15 ( & V_257 -> V_49 , L_27 ,
L_26 , V_36 ) ;
}
return V_36 ;
}
int F_133 ( struct V_1 * V_257 , T_7 V_258 )
{
struct V_11 * V_12 = F_131 ( V_257 -> V_115 , struct V_11 , V_15 ) ;
int V_36 ;
int V_259 = V_12 -> V_260 ;
F_15 ( & V_257 -> V_49 , L_28 ,
( F_132 ( V_258 ) ? L_24 : L_19 ) ) ;
if ( F_63 ( V_12 ) ) {
F_15 ( & V_257 -> V_49 , L_25 , L_29 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_267 )
return - V_162 ;
if ( F_71 ( V_12 ) )
return 0 ;
V_12 -> V_260 = V_268 ;
V_36 = V_12 -> V_20 -> V_267 ( V_12 ) ;
F_24 ( V_269 , & V_12 -> V_92 ) ;
if ( V_36 == 0 ) {
F_134 ( 10 ) ;
F_8 ( & V_39 ) ;
if ( ! F_63 ( V_12 ) ) {
F_57 ( V_257 , V_257 -> V_270
? V_271
: V_142 ) ;
F_25 ( V_263 , & V_12 -> V_92 ) ;
V_12 -> V_260 = V_272 ;
}
F_10 ( & V_39 ) ;
} else {
V_12 -> V_260 = V_259 ;
F_15 ( & V_257 -> V_49 , L_27 ,
L_29 , V_36 ) ;
if ( V_36 != - V_167 )
F_64 ( V_12 ) ;
}
return V_36 ;
}
static void F_135 ( struct V_273 * V_274 )
{
struct V_11 * V_12 = F_131 ( V_274 , struct V_11 , V_275 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_48 ;
F_136 ( V_2 ) ;
F_137 ( V_2 ) ;
F_138 ( V_2 ) ;
}
void F_139 ( struct V_11 * V_12 )
{
unsigned long V_92 ;
F_23 ( & V_39 , V_92 ) ;
if ( V_12 -> V_148 ) {
F_25 ( V_269 , & V_12 -> V_92 ) ;
F_140 ( V_276 , & V_12 -> V_275 ) ;
}
F_26 ( & V_39 , V_92 ) ;
}
int F_141 ( struct V_114 * V_115 , unsigned V_277 )
{
struct V_11 * V_12 ;
int V_36 = - V_278 ;
V_12 = F_131 ( V_115 , struct V_11 , V_15 ) ;
if ( V_277 && V_12 -> V_20 -> V_279 )
V_36 = V_12 -> V_20 -> V_279 ( V_12 , V_277 ) ;
if ( V_36 == 0 )
F_28 ( & V_12 -> V_99 , V_100 + F_142 ( 10 ) ) ;
return V_36 ;
}
T_8 F_143 ( int V_280 , void * V_281 )
{
struct V_11 * V_12 = V_281 ;
unsigned long V_92 ;
T_8 V_109 ;
F_144 ( V_92 ) ;
if ( F_22 ( F_63 ( V_12 ) || ! F_145 ( V_12 ) ) )
V_109 = V_282 ;
else if ( V_12 -> V_20 -> V_280 ( V_12 ) == V_282 )
V_109 = V_282 ;
else
V_109 = V_283 ;
F_146 ( V_92 ) ;
return V_109 ;
}
void F_64 ( struct V_11 * V_12 )
{
unsigned long V_92 ;
F_62 ( V_12 -> V_15 . V_76 , L_30 ) ;
F_23 ( & V_39 , V_92 ) ;
F_24 ( V_263 , & V_12 -> V_92 ) ;
F_25 ( V_284 , & V_12 -> V_92 ) ;
if ( V_12 -> V_148 ) {
F_24 ( V_285 , & V_12 -> V_92 ) ;
F_57 ( V_12 -> V_15 . V_48 ,
V_286 ) ;
F_147 ( V_12 -> V_15 . V_48 ) ;
}
if ( F_148 ( V_12 ) && V_12 -> V_287 ) {
V_12 = V_12 -> V_287 ;
if ( V_12 -> V_148 ) {
F_24 ( V_285 , & V_12 -> V_92 ) ;
F_57 ( V_12 -> V_15 . V_48 ,
V_286 ) ;
F_147 ( V_12 -> V_15 . V_48 ) ;
}
}
F_26 ( & V_39 , V_92 ) ;
}
struct V_11 * F_149 ( const struct V_288 * V_20 ,
struct V_110 * V_49 , const char * V_16 ,
struct V_11 * V_289 )
{
struct V_11 * V_12 ;
V_12 = F_150 ( sizeof( * V_12 ) + V_20 -> V_290 , V_291 ) ;
if ( ! V_12 ) {
F_15 ( V_49 , L_31 ) ;
return NULL ;
}
if ( V_289 == NULL ) {
V_12 -> V_292 = F_151 ( sizeof( * V_12 -> V_292 ) ,
V_291 ) ;
if ( ! V_12 -> V_292 ) {
F_152 ( V_12 ) ;
F_15 ( V_49 , L_32 ) ;
return NULL ;
}
F_153 ( V_12 -> V_292 ) ;
F_154 ( V_49 , V_12 ) ;
} else {
V_12 -> V_292 = V_289 -> V_292 ;
V_12 -> V_289 = V_289 ;
V_289 -> V_289 = V_289 ;
V_12 -> V_287 = V_289 ;
V_289 -> V_287 = V_12 ;
}
F_155 ( & V_12 -> V_293 ) ;
F_43 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_76 = V_49 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_194 = ( V_49 -> V_294 != NULL ) ;
F_156 ( & V_12 -> V_99 ) ;
V_12 -> V_99 . V_295 = F_29 ;
V_12 -> V_99 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_157
F_158 ( & V_12 -> V_275 , F_135 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_59 = V_20 -> V_92 & V_296 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_33 ;
return V_12 ;
}
struct V_11 * F_159 ( const struct V_288 * V_20 ,
struct V_110 * V_49 , const char * V_16 )
{
return F_149 ( V_20 , V_49 , V_16 , NULL ) ;
}
static void F_160 ( struct V_293 * V_293 )
{
struct V_11 * V_12 = F_131 ( V_293 , struct V_11 , V_293 ) ;
if ( F_148 ( V_12 ) )
F_152 ( V_12 -> V_292 ) ;
else
V_12 -> V_287 -> V_287 = NULL ;
F_152 ( V_12 ) ;
}
struct V_11 * F_161 ( struct V_11 * V_12 )
{
if ( V_12 )
F_162 ( & V_12 -> V_293 ) ;
return V_12 ;
}
void F_163 ( struct V_11 * V_12 )
{
if ( V_12 )
F_164 ( & V_12 -> V_293 , F_160 ) ;
}
int F_148 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_289 )
return 1 ;
return V_12 == V_12 -> V_289 ;
}
static int F_165 ( struct V_11 * V_12 ,
unsigned int V_297 , unsigned long V_298 )
{
int V_103 ;
if ( V_12 -> V_20 -> V_280 ) {
if ( V_298 & V_299 )
V_298 &= ~ V_300 ;
snprintf ( V_12 -> V_301 , sizeof( V_12 -> V_301 ) , L_34 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_125 ) ;
V_103 = F_166 ( V_297 , & F_143 , V_298 ,
V_12 -> V_301 , V_12 ) ;
if ( V_103 != 0 ) {
F_62 ( V_12 -> V_15 . V_76 ,
L_35 ,
V_297 ) ;
return V_103 ;
}
V_12 -> V_280 = V_297 ;
F_52 ( V_12 -> V_15 . V_76 , L_36 , V_297 ,
( V_12 -> V_20 -> V_92 & V_302 ) ?
L_37 : L_38 ,
( unsigned long long ) V_12 -> V_303 ) ;
} else {
V_12 -> V_280 = - 1 ;
if ( V_12 -> V_303 )
F_52 ( V_12 -> V_15 . V_76 , L_39 ,
( V_12 -> V_20 -> V_92 & V_302 ) ?
L_37 : L_38 ,
( unsigned long long ) V_12 -> V_303 ) ;
}
return 0 ;
}
int F_167 ( struct V_11 * V_12 ,
unsigned int V_297 , unsigned long V_298 )
{
int V_103 ;
struct V_1 * V_257 ;
F_52 ( V_12 -> V_15 . V_76 , L_40 , V_12 -> V_17 ) ;
if ( V_118 < 0 || V_118 > 1 )
V_12 -> V_118 = V_12 -> V_304 ? 0 : 1 ;
else
V_12 -> V_118 = V_118 ;
F_25 ( V_305 , & V_12 -> V_92 ) ;
if ( ( V_103 = F_168 ( V_12 ) ) != 0 ) {
F_15 ( V_12 -> V_15 . V_76 , L_41 ) ;
return V_103 ;
}
if ( ( V_103 = F_45 ( & V_12 -> V_15 ) ) < 0 )
goto V_306;
if ( ( V_257 = F_169 ( NULL , & V_12 -> V_15 , 0 ) ) == NULL ) {
F_62 ( V_12 -> V_15 . V_76 , L_42 ) ;
V_103 = - V_178 ;
goto V_307;
}
V_12 -> V_15 . V_48 = V_257 ;
switch ( V_12 -> V_59 ) {
case V_64 :
V_257 -> V_59 = V_156 ;
break;
case V_62 :
V_257 -> V_59 = V_157 ;
break;
case V_60 :
V_257 -> V_59 = V_255 ;
break;
default:
V_103 = - V_105 ;
goto V_308;
}
F_170 ( & V_257 -> V_49 , 1 ) ;
F_25 ( V_263 , & V_12 -> V_92 ) ;
if ( V_12 -> V_20 -> V_231 && ( V_103 = V_12 -> V_20 -> V_231 ( V_12 ) ) < 0 ) {
F_62 ( V_12 -> V_15 . V_76 , L_43 ) ;
goto V_309;
}
V_12 -> V_94 = 1 ;
if ( F_14 ( V_12 -> V_15 . V_76 )
&& F_14 ( & V_12 -> V_15 . V_48 -> V_49 ) )
F_15 ( V_12 -> V_15 . V_76 , L_44 ) ;
if ( F_148 ( V_12 ) && V_297 ) {
V_103 = F_165 ( V_12 , V_297 , V_298 ) ;
if ( V_103 )
goto V_310;
}
V_12 -> V_260 = V_272 ;
V_103 = V_12 -> V_20 -> V_311 ( V_12 ) ;
if ( V_103 < 0 ) {
F_62 ( V_12 -> V_15 . V_76 , L_45 , V_103 ) ;
goto V_312;
}
V_257 -> V_313 = F_171 ( 500u , V_12 -> V_314 ) ;
if ( ( V_103 = F_56 ( V_12 ) ) != 0 )
goto V_315;
V_103 = F_172 ( & V_257 -> V_49 . V_316 , & V_317 ) ;
if ( V_103 < 0 ) {
F_48 ( V_134 L_46 ,
V_103 ) ;
goto V_318;
}
if ( V_12 -> V_95 && F_27 ( V_12 ) )
F_21 ( V_12 ) ;
F_173 ( V_12 -> V_15 . V_76 ) ;
return V_103 ;
V_318:
F_24 ( V_263 , & V_12 -> V_92 ) ;
if ( F_174 ( V_12 -> V_260 ) )
V_12 -> V_260 = V_264 ;
F_8 ( & V_39 ) ;
V_12 -> V_148 = 0 ;
F_10 ( & V_39 ) ;
#ifdef F_157
F_175 ( & V_12 -> V_275 ) ;
#endif
F_46 ( & V_131 ) ;
F_176 ( & V_257 ) ;
F_50 ( & V_131 ) ;
V_315:
V_12 -> V_94 = 0 ;
F_24 ( V_285 , & V_12 -> V_92 ) ;
F_177 ( & V_12 -> V_99 ) ;
V_12 -> V_20 -> V_319 ( V_12 ) ;
V_12 -> V_260 = V_320 ;
F_24 ( V_285 , & V_12 -> V_92 ) ;
F_177 ( & V_12 -> V_99 ) ;
V_312:
if ( F_148 ( V_12 ) && V_12 -> V_280 >= 0 )
F_178 ( V_297 , V_12 ) ;
V_310:
V_309:
V_308:
F_108 ( V_12 -> V_15 . V_48 ) ;
V_307:
F_53 ( & V_12 -> V_15 ) ;
V_306:
F_179 ( V_12 ) ;
return V_103 ;
}
void F_180 ( struct V_11 * V_12 )
{
struct V_1 * V_257 = V_12 -> V_15 . V_48 ;
F_52 ( V_12 -> V_15 . V_76 , L_47 , V_12 -> V_260 ) ;
F_107 ( V_257 ) ;
F_181 ( & V_257 -> V_49 . V_316 , & V_317 ) ;
F_24 ( V_263 , & V_12 -> V_92 ) ;
if ( F_174 ( V_12 -> V_260 ) )
V_12 -> V_260 = V_264 ;
F_15 ( V_12 -> V_15 . V_76 , L_48 ) ;
F_8 ( & V_39 ) ;
V_12 -> V_148 = 0 ;
F_10 ( & V_39 ) ;
#ifdef F_157
F_175 ( & V_12 -> V_275 ) ;
#endif
F_46 ( & V_131 ) ;
F_176 ( & V_257 ) ;
F_50 ( & V_131 ) ;
V_12 -> V_94 = 0 ;
F_24 ( V_285 , & V_12 -> V_92 ) ;
F_177 ( & V_12 -> V_99 ) ;
V_12 -> V_20 -> V_319 ( V_12 ) ;
V_12 -> V_260 = V_320 ;
F_24 ( V_285 , & V_12 -> V_92 ) ;
F_177 ( & V_12 -> V_99 ) ;
if ( F_148 ( V_12 ) ) {
if ( V_12 -> V_280 >= 0 )
F_178 ( V_12 -> V_280 , V_12 ) ;
}
F_108 ( V_12 -> V_15 . V_48 ) ;
F_53 ( & V_12 -> V_15 ) ;
F_179 ( V_12 ) ;
}
void
F_182 ( struct V_321 * V_49 )
{
struct V_11 * V_12 = F_183 ( V_49 ) ;
if ( V_12 -> V_20 -> V_322 )
V_12 -> V_20 -> V_322 ( V_12 ) ;
}
int F_184 ( struct V_323 * V_324 )
{
if ( V_325 )
return - V_170 ;
V_325 = V_324 ;
F_185 () ;
return 0 ;
}
void F_186 ( void )
{
if ( V_325 == NULL ) {
F_48 ( V_134 L_49 ) ;
return;
}
V_325 = NULL ;
F_185 () ;
}
