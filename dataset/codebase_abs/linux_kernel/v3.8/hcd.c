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
if ( V_139 -> V_59 == V_148 ) {
V_103 = F_61 ( V_139 ) ;
if ( V_103 < 0 ) {
F_50 ( & V_131 ) ;
F_15 ( V_138 , L_13 ,
F_60 ( & V_139 -> V_49 ) , V_103 ) ;
return V_103 ;
}
}
V_103 = F_62 ( V_139 ) ;
if ( V_103 ) {
F_63 ( V_138 , L_14 ,
F_60 ( & V_139 -> V_49 ) , V_103 ) ;
} else {
F_8 ( & V_39 ) ;
V_12 -> V_149 = 1 ;
F_10 ( & V_39 ) ;
if ( F_64 ( V_12 ) )
F_65 ( V_12 ) ;
}
F_50 ( & V_131 ) ;
return V_103 ;
}
void F_66 ( struct V_114 * V_115 , int V_150 )
{
unsigned V_151 = 1 << V_150 ;
if ( ! ( V_115 -> V_152 & V_151 ) ) {
V_115 -> V_152 |= V_151 ;
F_67 ( & V_115 -> V_48 -> V_49 ) ;
}
}
void F_68 ( struct V_114 * V_115 , int V_150 )
{
unsigned V_151 = 1 << V_150 ;
if ( V_115 -> V_152 & V_151 ) {
V_115 -> V_152 &= ~ V_151 ;
F_69 ( & V_115 -> V_48 -> V_49 ) ;
}
}
long F_70 ( int V_59 , int V_153 , int V_154 , int V_155 )
{
unsigned long V_156 ;
switch ( V_59 ) {
case V_157 :
if ( V_153 ) {
V_156 = ( 67667L * ( 31L + 10L * F_71 ( V_155 ) ) ) / 1000L ;
return ( 64060L + ( 2 * V_158 ) + V_159 + V_156 ) ;
} else {
V_156 = ( 66700L * ( 31L + 10L * F_71 ( V_155 ) ) ) / 1000L ;
return ( 64107L + ( 2 * V_158 ) + V_159 + V_156 ) ;
}
case V_160 :
if ( V_154 ) {
V_156 = ( 8354L * ( 31L + 10L * F_71 ( V_155 ) ) ) / 1000L ;
return ( ( ( V_153 ) ? 7268L : 6265L ) + V_159 + V_156 ) ;
} else {
V_156 = ( 8354L * ( 31L + 10L * F_71 ( V_155 ) ) ) / 1000L ;
return ( 9107L + V_159 + V_156 ) ;
}
case V_161 :
if ( V_154 )
V_156 = F_72 ( V_155 ) ;
else
V_156 = F_73 ( V_155 ) ;
return V_156 ;
default:
F_74 ( L_15 , V_135 ) ;
return - 1 ;
}
}
int F_9 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_109 = 0 ;
F_20 ( & V_162 ) ;
if ( F_22 ( F_75 ( & V_22 -> V_163 ) ) ) {
V_109 = - V_164 ;
goto V_106;
}
if ( F_22 ( ! V_22 -> V_107 -> V_165 ) ) {
V_109 = - V_166 ;
goto V_106;
}
if ( F_22 ( ! V_22 -> V_49 -> V_167 ) ) {
V_109 = - V_168 ;
goto V_106;
}
if ( F_76 ( V_12 ) ) {
V_22 -> V_169 = 0 ;
F_77 ( & V_22 -> V_170 , & V_22 -> V_107 -> V_170 ) ;
} else {
V_109 = - V_171 ;
goto V_106;
}
V_106:
F_18 ( & V_162 ) ;
return V_109 ;
}
int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_36 )
{
struct V_172 * V_156 ;
F_78 (tmp, &urb->ep->urb_list) {
if ( V_156 == & V_22 -> V_170 )
break;
}
if ( V_156 != & V_22 -> V_170 )
return - V_173 ;
if ( V_22 -> V_169 )
return - V_174 ;
V_22 -> V_169 = V_36 ;
return 0 ;
}
void F_17 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_20 ( & V_162 ) ;
F_79 ( & V_22 -> V_170 ) ;
F_18 ( & V_162 ) ;
}
static int F_80 ( struct V_114 * V_115 ,
T_5 V_175 , T_6 * V_176 ,
void * * V_177 , T_4 V_119 ,
enum V_178 V_179 )
{
unsigned char * V_180 ;
if ( * V_177 == NULL ) {
F_81 ( 1 ) ;
return - V_181 ;
}
V_180 = F_82 ( V_115 , V_119 + sizeof( V_180 ) ,
V_175 , V_176 ) ;
if ( ! V_180 )
return - V_182 ;
F_83 ( ( unsigned long ) * V_177 ,
( unsigned long * ) ( V_180 + V_119 ) ) ;
if ( V_179 == V_183 )
memcpy ( V_180 , * V_177 , V_119 ) ;
* V_177 = V_180 ;
return 0 ;
}
static void F_84 ( struct V_114 * V_115 , T_6 * V_176 ,
void * * V_177 , T_4 V_119 ,
enum V_178 V_179 )
{
unsigned char * V_180 = * V_177 ;
V_180 = ( void * ) F_85 ( ( unsigned long * ) ( V_180 + V_119 ) ) ;
if ( V_179 == V_184 )
memcpy ( V_180 , * V_177 , V_119 ) ;
F_86 ( V_115 , V_119 + sizeof( V_180 ) , * V_177 , * V_176 ) ;
* V_177 = V_180 ;
* V_176 = 0 ;
}
void F_87 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_185 & V_186 )
F_88 ( V_12 -> V_15 . V_76 ,
V_22 -> V_187 ,
sizeof( struct V_23 ) ,
V_183 ) ;
else if ( V_22 -> V_185 & V_188 )
F_84 ( V_22 -> V_49 -> V_115 ,
& V_22 -> V_187 ,
( void * * ) & V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_183 ) ;
V_22 -> V_185 &= ~ ( V_186 | V_188 ) ;
}
static void F_89 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_89 )
V_12 -> V_20 -> F_89 ( V_12 , V_22 ) ;
else
F_90 ( V_12 , V_22 ) ;
}
void F_90 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_178 V_179 ;
F_87 ( V_12 , V_22 ) ;
V_179 = F_91 ( V_22 ) ? V_184 : V_183 ;
if ( V_22 -> V_185 & V_189 )
F_92 ( V_12 -> V_15 . V_76 ,
V_22 -> V_190 ,
V_22 -> V_191 ,
V_179 ) ;
else if ( V_22 -> V_185 & V_192 )
F_93 ( V_12 -> V_15 . V_76 ,
V_22 -> V_193 ,
V_22 -> V_44 ,
V_179 ) ;
else if ( V_22 -> V_185 & V_194 )
F_88 ( V_12 -> V_15 . V_76 ,
V_22 -> V_193 ,
V_22 -> V_44 ,
V_179 ) ;
else if ( V_22 -> V_185 & V_195 )
F_84 ( V_22 -> V_49 -> V_115 ,
& V_22 -> V_193 ,
& V_22 -> V_30 ,
V_22 -> V_44 ,
V_179 ) ;
V_22 -> V_185 &= ~ ( V_189 | V_192 |
V_194 | V_195 ) ;
}
static int F_94 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_175 )
{
if ( V_12 -> V_20 -> F_94 )
return V_12 -> V_20 -> F_94 ( V_12 , V_22 , V_175 ) ;
else
return F_95 ( V_12 , V_22 , V_175 ) ;
}
int F_95 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_175 )
{
enum V_178 V_179 ;
int V_196 = 0 ;
if ( F_34 ( & V_22 -> V_107 -> V_108 ) ) {
if ( V_12 -> V_15 . V_197 )
return V_196 ;
if ( V_12 -> V_15 . V_198 ) {
V_22 -> V_187 = F_96 (
V_12 -> V_15 . V_76 ,
V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_183 ) ;
if ( F_97 ( V_12 -> V_15 . V_76 ,
V_22 -> V_187 ) )
return - V_199 ;
V_22 -> V_185 |= V_186 ;
} else if ( V_12 -> V_20 -> V_92 & V_200 ) {
V_196 = F_80 (
V_22 -> V_49 -> V_115 , V_175 ,
& V_22 -> V_187 ,
( void * * ) & V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_183 ) ;
if ( V_196 )
return V_196 ;
V_22 -> V_185 |= V_188 ;
}
}
V_179 = F_91 ( V_22 ) ? V_184 : V_183 ;
if ( V_22 -> V_44 != 0
&& ! ( V_22 -> V_185 & V_201 ) ) {
if ( V_12 -> V_15 . V_198 ) {
if ( V_22 -> V_191 ) {
int V_7 ;
if ( F_98 ( & V_22 -> V_107 -> V_108 ) ) {
F_99 ( 1 ) ;
return - V_105 ;
}
V_7 = F_100 (
V_12 -> V_15 . V_76 ,
V_22 -> V_190 ,
V_22 -> V_191 ,
V_179 ) ;
if ( V_7 <= 0 )
V_196 = - V_199 ;
else
V_22 -> V_185 |= V_189 ;
V_22 -> V_202 = V_7 ;
if ( V_7 != V_22 -> V_191 )
V_22 -> V_185 |=
V_203 ;
} else if ( V_22 -> V_190 ) {
struct V_204 * V_190 = V_22 -> V_190 ;
V_22 -> V_193 = F_101 (
V_12 -> V_15 . V_76 ,
F_102 ( V_190 ) ,
V_190 -> V_205 ,
V_22 -> V_44 ,
V_179 ) ;
if ( F_97 ( V_12 -> V_15 . V_76 ,
V_22 -> V_193 ) )
V_196 = - V_199 ;
else
V_22 -> V_185 |= V_192 ;
} else {
V_22 -> V_193 = F_96 (
V_12 -> V_15 . V_76 ,
V_22 -> V_30 ,
V_22 -> V_44 ,
V_179 ) ;
if ( F_97 ( V_12 -> V_15 . V_76 ,
V_22 -> V_193 ) )
V_196 = - V_199 ;
else
V_22 -> V_185 |= V_194 ;
}
} else if ( V_12 -> V_20 -> V_92 & V_200 ) {
V_196 = F_80 (
V_22 -> V_49 -> V_115 , V_175 ,
& V_22 -> V_193 ,
& V_22 -> V_30 ,
V_22 -> V_44 ,
V_179 ) ;
if ( V_196 == 0 )
V_22 -> V_185 |= V_195 ;
}
if ( V_196 && ( V_22 -> V_185 & ( V_186 |
V_188 ) ) )
F_90 ( V_12 , V_22 ) ;
}
return V_196 ;
}
int F_103 ( struct V_22 * V_22 , T_5 V_175 )
{
int V_36 ;
struct V_11 * V_12 = F_41 ( V_22 -> V_49 -> V_115 ) ;
F_104 ( V_22 ) ;
F_105 ( & V_22 -> V_206 ) ;
F_105 ( & V_22 -> V_49 -> V_207 ) ;
F_106 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_49 ) ) {
V_36 = F_32 ( V_12 , V_22 ) ;
} else {
V_36 = F_94 ( V_12 , V_22 , V_175 ) ;
if ( F_107 ( V_36 == 0 ) ) {
V_36 = V_12 -> V_20 -> V_208 ( V_12 , V_22 , V_175 ) ;
if ( F_22 ( V_36 ) )
F_89 ( V_12 , V_22 ) ;
}
}
if ( F_22 ( V_36 ) ) {
F_108 ( & V_12 -> V_15 , V_22 , V_36 ) ;
V_22 -> V_40 = NULL ;
F_44 ( & V_22 -> V_170 ) ;
F_109 ( & V_22 -> V_206 ) ;
F_109 ( & V_22 -> V_49 -> V_207 ) ;
if ( F_75 ( & V_22 -> V_163 ) )
F_110 ( & V_209 ) ;
F_111 ( V_22 ) ;
}
return V_36 ;
}
static int F_112 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
int V_210 ;
if ( F_1 ( V_22 -> V_49 ) )
V_210 = F_35 ( V_12 , V_22 , V_36 ) ;
else {
V_210 = V_12 -> V_20 -> V_211 ( V_12 , V_22 , V_36 ) ;
}
return V_210 ;
}
int F_113 ( struct V_22 * V_22 , int V_36 )
{
struct V_11 * V_12 ;
int V_103 = - V_173 ;
unsigned long V_92 ;
F_23 ( & V_212 , V_92 ) ;
if ( F_75 ( & V_22 -> V_206 ) > 0 ) {
V_103 = 0 ;
F_114 ( V_22 -> V_49 ) ;
}
F_26 ( & V_212 , V_92 ) ;
if ( V_103 == 0 ) {
V_12 = F_41 ( V_22 -> V_49 -> V_115 ) ;
V_103 = F_112 ( V_12 , V_22 , V_36 ) ;
F_115 ( V_22 -> V_49 ) ;
}
if ( V_103 == 0 )
V_103 = - V_213 ;
else if ( V_103 != - V_173 && V_103 != - V_174 )
F_15 ( & V_22 -> V_49 -> V_49 , L_16 ,
V_22 , V_103 ) ;
return V_103 ;
}
void F_19 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
V_22 -> V_40 = NULL ;
if ( F_22 ( V_22 -> V_169 ) )
V_36 = V_22 -> V_169 ;
else if ( F_22 ( ( V_22 -> V_185 & V_214 ) &&
V_22 -> V_45 < V_22 -> V_44 &&
! V_36 ) )
V_36 = - V_215 ;
F_89 ( V_12 , V_22 ) ;
F_116 ( & V_12 -> V_15 , V_22 , V_36 ) ;
F_117 ( V_22 ) ;
V_22 -> V_36 = V_36 ;
V_22 -> V_216 ( V_22 ) ;
F_109 ( & V_22 -> V_206 ) ;
if ( F_22 ( F_75 ( & V_22 -> V_163 ) ) )
F_110 ( & V_209 ) ;
F_111 ( V_22 ) ;
}
void F_118 ( struct V_1 * V_2 ,
struct V_217 * V_107 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_107 )
return;
F_7 () ;
V_12 = F_41 ( V_2 -> V_115 ) ;
F_8 ( & V_162 ) ;
V_218:
F_119 (urb, &ep->urb_list, urb_list) {
int V_219 ;
if ( V_22 -> V_169 )
continue;
F_104 ( V_22 ) ;
V_219 = F_91 ( V_22 ) ;
F_18 ( & V_162 ) ;
F_112 ( V_12 , V_22 , - V_171 ) ;
F_15 (hcd->self.controller,
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
F_111 ( V_22 ) ;
F_20 ( & V_162 ) ;
goto V_218;
}
F_10 ( & V_162 ) ;
while ( ! F_120 ( & V_107 -> V_170 ) ) {
F_8 ( & V_162 ) ;
V_22 = NULL ;
if ( ! F_120 ( & V_107 -> V_170 ) ) {
V_22 = F_121 ( V_107 -> V_170 . V_220 , struct V_22 ,
V_170 ) ;
F_104 ( V_22 ) ;
}
F_10 ( & V_162 ) ;
if ( V_22 ) {
F_122 ( V_22 ) ;
F_111 ( V_22 ) ;
}
}
}
int F_123 ( struct V_1 * V_2 ,
struct V_221 * V_222 ,
struct V_223 * V_224 ,
struct V_223 * V_225 )
{
int V_226 , V_227 , V_228 ;
struct V_223 * V_229 = NULL ;
int V_196 = 0 ;
struct V_11 * V_12 ;
struct V_217 * V_107 ;
V_12 = F_41 ( V_2 -> V_115 ) ;
if ( ! V_12 -> V_20 -> V_230 )
return 0 ;
if ( ! V_222 && ! V_224 ) {
for ( V_227 = 1 ; V_227 < 16 ; ++ V_227 ) {
V_107 = V_2 -> V_231 [ V_227 ] ;
if ( V_107 )
V_12 -> V_20 -> V_232 ( V_12 , V_2 , V_107 ) ;
V_107 = V_2 -> V_233 [ V_227 ] ;
if ( V_107 )
V_12 -> V_20 -> V_232 ( V_12 , V_2 , V_107 ) ;
}
V_12 -> V_20 -> V_230 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_222 ) {
V_226 = V_222 -> V_108 . V_234 ;
for ( V_227 = 1 ; V_227 < 16 ; ++ V_227 ) {
V_107 = V_2 -> V_231 [ V_227 ] ;
if ( V_107 ) {
V_196 = V_12 -> V_20 -> V_232 ( V_12 , V_2 , V_107 ) ;
if ( V_196 < 0 )
goto V_235;
}
V_107 = V_2 -> V_233 [ V_227 ] ;
if ( V_107 ) {
V_196 = V_12 -> V_20 -> V_232 ( V_12 , V_2 , V_107 ) ;
if ( V_196 < 0 )
goto V_235;
}
}
for ( V_227 = 0 ; V_227 < V_226 ; ++ V_227 ) {
struct V_223 * V_236 ;
int V_237 ;
V_236 = & V_222 -> V_238 [ V_227 ] -> V_239 [ 0 ] ;
V_237 = V_236 -> V_108 . V_240 ;
V_229 = F_124 ( V_222 , V_237 , 0 ) ;
if ( ! V_229 )
V_229 = V_236 ;
for ( V_228 = 0 ; V_228 < V_229 -> V_108 . V_241 ; V_228 ++ ) {
V_196 = V_12 -> V_20 -> V_242 ( V_12 , V_2 , & V_229 -> V_243 [ V_228 ] ) ;
if ( V_196 < 0 )
goto V_235;
}
}
}
if ( V_224 && V_225 ) {
struct V_244 * V_245 = F_125 ( V_2 ,
V_224 -> V_108 . V_240 ) ;
if ( ! V_245 )
return - V_105 ;
if ( V_245 -> V_246 ) {
V_224 = F_126 ( V_245 , 0 ) ;
if ( ! V_224 )
V_224 = & V_245 -> V_239 [ 0 ] ;
}
for ( V_227 = 0 ; V_227 < V_224 -> V_108 . V_241 ; V_227 ++ ) {
V_196 = V_12 -> V_20 -> V_232 ( V_12 , V_2 ,
& V_224 -> V_243 [ V_227 ] ) ;
if ( V_196 < 0 )
goto V_235;
}
for ( V_227 = 0 ; V_227 < V_225 -> V_108 . V_241 ; V_227 ++ ) {
V_196 = V_12 -> V_20 -> V_242 ( V_12 , V_2 ,
& V_225 -> V_243 [ V_227 ] ) ;
if ( V_196 < 0 )
goto V_235;
}
}
V_196 = V_12 -> V_20 -> V_230 ( V_12 , V_2 ) ;
V_235:
if ( V_196 < 0 )
V_12 -> V_20 -> V_247 ( V_12 , V_2 ) ;
return V_196 ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_217 * V_107 )
{
struct V_11 * V_12 ;
F_7 () ;
V_12 = F_41 ( V_2 -> V_115 ) ;
if ( V_12 -> V_20 -> V_248 )
V_12 -> V_20 -> V_248 ( V_12 , V_107 ) ;
}
void F_128 ( struct V_1 * V_2 ,
struct V_217 * V_107 )
{
struct V_11 * V_12 = F_41 ( V_2 -> V_115 ) ;
if ( V_12 -> V_20 -> V_249 )
V_12 -> V_20 -> V_249 ( V_12 , V_107 ) ;
else {
int V_250 = F_37 ( & V_107 -> V_108 ) ;
int V_251 = F_129 ( & V_107 -> V_108 ) ;
int V_252 = F_34 ( & V_107 -> V_108 ) ;
F_130 ( V_2 , V_250 , V_251 , 0 ) ;
if ( V_252 )
F_130 ( V_2 , V_250 , ! V_251 , 0 ) ;
}
}
int F_131 ( struct V_244 * V_253 ,
struct V_217 * * V_254 , unsigned int V_255 ,
unsigned int V_256 , T_5 V_175 )
{
struct V_11 * V_12 ;
struct V_1 * V_49 ;
int V_227 ;
V_49 = F_132 ( V_253 ) ;
V_12 = F_41 ( V_49 -> V_115 ) ;
if ( ! V_12 -> V_20 -> V_257 || ! V_12 -> V_20 -> V_258 )
return - V_105 ;
if ( V_49 -> V_59 != V_148 )
return - V_105 ;
for ( V_227 = 0 ; V_227 < V_255 ; V_227 ++ )
if ( ! F_133 ( & V_254 [ V_227 ] -> V_108 ) )
return - V_105 ;
return V_12 -> V_20 -> V_257 ( V_12 , V_49 , V_254 , V_255 ,
V_256 , V_175 ) ;
}
void F_134 ( struct V_244 * V_253 ,
struct V_217 * * V_254 , unsigned int V_255 ,
T_5 V_175 )
{
struct V_11 * V_12 ;
struct V_1 * V_49 ;
int V_227 ;
V_49 = F_132 ( V_253 ) ;
V_12 = F_41 ( V_49 -> V_115 ) ;
if ( V_49 -> V_59 != V_148 )
return;
for ( V_227 = 0 ; V_227 < V_255 ; V_227 ++ )
if ( ! V_254 [ V_227 ] || ! F_133 ( & V_254 [ V_227 ] -> V_108 ) )
return;
V_12 -> V_20 -> V_258 ( V_12 , V_49 , V_254 , V_255 , V_175 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
F_8 ( & V_212 ) ;
F_10 ( & V_212 ) ;
}
int F_136 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_41 ( V_2 -> V_115 ) ;
if ( ! F_76 ( V_12 ) )
return - V_171 ;
return V_12 -> V_20 -> V_259 ( V_12 ) ;
}
int F_137 ( struct V_1 * V_260 , T_7 V_261 )
{
struct V_11 * V_12 = F_138 ( V_260 -> V_115 , struct V_11 , V_15 ) ;
int V_36 ;
int V_262 = V_12 -> V_263 ;
F_15 ( & V_260 -> V_49 , L_24 ,
( F_139 ( V_261 ) ? L_25 : L_20 ) ,
V_260 -> V_264 ) ;
if ( F_64 ( V_12 ) ) {
F_15 ( & V_260 -> V_49 , L_26 , L_27 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_265 ) {
V_36 = - V_166 ;
} else {
F_24 ( V_266 , & V_12 -> V_92 ) ;
V_12 -> V_263 = V_267 ;
V_36 = V_12 -> V_20 -> V_265 ( V_12 ) ;
}
if ( V_36 == 0 ) {
F_57 ( V_260 , V_268 ) ;
V_12 -> V_263 = V_269 ;
if ( V_260 -> V_264 ) {
char V_93 [ 6 ] ;
V_36 = V_12 -> V_20 -> V_97 ( V_12 , V_93 ) ;
if ( V_36 != 0 ) {
F_15 ( & V_260 -> V_49 , L_28 ) ;
F_140 ( V_260 , V_270 ) ;
V_36 = - V_174 ;
}
}
} else {
F_8 ( & V_39 ) ;
if ( ! F_64 ( V_12 ) ) {
F_25 ( V_266 , & V_12 -> V_92 ) ;
V_12 -> V_263 = V_262 ;
}
F_10 ( & V_39 ) ;
F_15 ( & V_260 -> V_49 , L_29 ,
L_27 , V_36 ) ;
}
return V_36 ;
}
int F_140 ( struct V_1 * V_260 , T_7 V_261 )
{
struct V_11 * V_12 = F_138 ( V_260 -> V_115 , struct V_11 , V_15 ) ;
int V_36 ;
int V_262 = V_12 -> V_263 ;
F_15 ( & V_260 -> V_49 , L_30 ,
( F_139 ( V_261 ) ? L_25 : L_20 ) ) ;
if ( F_64 ( V_12 ) ) {
F_15 ( & V_260 -> V_49 , L_26 , L_31 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_271 )
return - V_166 ;
if ( F_76 ( V_12 ) )
return 0 ;
V_12 -> V_263 = V_272 ;
V_36 = V_12 -> V_20 -> V_271 ( V_12 ) ;
F_24 ( V_273 , & V_12 -> V_92 ) ;
if ( V_36 == 0 ) {
struct V_1 * V_2 ;
int V_274 ;
F_8 ( & V_39 ) ;
if ( ! F_64 ( V_12 ) ) {
F_57 ( V_260 , V_260 -> V_275
? V_276
: V_142 ) ;
F_25 ( V_266 , & V_12 -> V_92 ) ;
V_12 -> V_263 = V_277 ;
}
F_10 ( & V_39 ) ;
F_141 (rhdev, port1, udev) {
if ( V_2 -> V_263 != V_278 &&
! V_2 -> V_279 ) {
F_142 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_263 = V_262 ;
F_15 ( & V_260 -> V_49 , L_29 ,
L_31 , V_36 ) ;
if ( V_36 != - V_171 )
F_65 ( V_12 ) ;
}
return V_36 ;
}
static void F_143 ( struct V_280 * V_281 )
{
struct V_11 * V_12 = F_138 ( V_281 , struct V_11 , V_282 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_48 ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
F_146 ( V_2 ) ;
}
void F_147 ( struct V_11 * V_12 )
{
unsigned long V_92 ;
F_23 ( & V_39 , V_92 ) ;
if ( V_12 -> V_149 ) {
F_25 ( V_273 , & V_12 -> V_92 ) ;
F_148 ( V_283 , & V_12 -> V_282 ) ;
}
F_26 ( & V_39 , V_92 ) ;
}
int F_149 ( struct V_114 * V_115 , unsigned V_284 )
{
struct V_11 * V_12 ;
int V_36 = - V_285 ;
V_12 = F_138 ( V_115 , struct V_11 , V_15 ) ;
if ( V_284 && V_12 -> V_20 -> V_286 )
V_36 = V_12 -> V_20 -> V_286 ( V_12 , V_284 ) ;
if ( V_36 == 0 )
F_28 ( & V_12 -> V_99 , V_100 + F_150 ( 10 ) ) ;
return V_36 ;
}
T_8 F_151 ( int V_287 , void * V_288 )
{
struct V_11 * V_12 = V_288 ;
unsigned long V_92 ;
T_8 V_109 ;
F_152 ( V_92 ) ;
if ( F_22 ( F_64 ( V_12 ) || ! F_153 ( V_12 ) ) )
V_109 = V_289 ;
else if ( V_12 -> V_20 -> V_287 ( V_12 ) == V_289 )
V_109 = V_289 ;
else
V_109 = V_290 ;
F_154 ( V_92 ) ;
return V_109 ;
}
void F_65 ( struct V_11 * V_12 )
{
unsigned long V_92 ;
F_63 ( V_12 -> V_15 . V_76 , L_32 ) ;
F_23 ( & V_39 , V_92 ) ;
F_24 ( V_266 , & V_12 -> V_92 ) ;
F_25 ( V_291 , & V_12 -> V_92 ) ;
if ( V_12 -> V_149 ) {
F_24 ( V_292 , & V_12 -> V_92 ) ;
F_57 ( V_12 -> V_15 . V_48 ,
V_278 ) ;
F_155 ( V_12 -> V_15 . V_48 ) ;
}
if ( F_156 ( V_12 ) && V_12 -> V_293 ) {
V_12 = V_12 -> V_293 ;
if ( V_12 -> V_149 ) {
F_24 ( V_292 , & V_12 -> V_92 ) ;
F_57 ( V_12 -> V_15 . V_48 ,
V_278 ) ;
F_155 ( V_12 -> V_15 . V_48 ) ;
}
}
F_26 ( & V_39 , V_92 ) ;
}
struct V_11 * F_157 ( const struct V_294 * V_20 ,
struct V_110 * V_49 , const char * V_16 ,
struct V_11 * V_295 )
{
struct V_11 * V_12 ;
V_12 = F_158 ( sizeof( * V_12 ) + V_20 -> V_296 , V_297 ) ;
if ( ! V_12 ) {
F_15 ( V_49 , L_33 ) ;
return NULL ;
}
if ( V_295 == NULL ) {
V_12 -> V_298 = F_159 ( sizeof( * V_12 -> V_298 ) ,
V_297 ) ;
if ( ! V_12 -> V_298 ) {
F_160 ( V_12 ) ;
F_15 ( V_49 , L_34 ) ;
return NULL ;
}
F_161 ( V_12 -> V_298 ) ;
F_162 ( V_49 , V_12 ) ;
} else {
V_12 -> V_298 = V_295 -> V_298 ;
V_12 -> V_295 = V_295 ;
V_295 -> V_295 = V_295 ;
V_12 -> V_293 = V_295 ;
V_295 -> V_293 = V_12 ;
}
F_163 ( & V_12 -> V_299 ) ;
F_43 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_76 = V_49 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_198 = ( V_49 -> V_300 != NULL ) ;
F_164 ( & V_12 -> V_99 ) ;
V_12 -> V_99 . V_301 = F_29 ;
V_12 -> V_99 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_165
F_166 ( & V_12 -> V_282 , F_143 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_59 = V_20 -> V_92 & V_302 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_35 ;
return V_12 ;
}
struct V_11 * F_167 ( const struct V_294 * V_20 ,
struct V_110 * V_49 , const char * V_16 )
{
return F_157 ( V_20 , V_49 , V_16 , NULL ) ;
}
static void F_168 ( struct V_299 * V_299 )
{
struct V_11 * V_12 = F_138 ( V_299 , struct V_11 , V_299 ) ;
if ( F_156 ( V_12 ) )
F_160 ( V_12 -> V_298 ) ;
else
V_12 -> V_293 -> V_293 = NULL ;
F_160 ( V_12 ) ;
}
struct V_11 * F_169 ( struct V_11 * V_12 )
{
if ( V_12 )
F_170 ( & V_12 -> V_299 ) ;
return V_12 ;
}
void F_171 ( struct V_11 * V_12 )
{
if ( V_12 )
F_172 ( & V_12 -> V_299 , F_168 ) ;
}
int F_156 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_295 )
return 1 ;
return V_12 == V_12 -> V_295 ;
}
static int F_173 ( struct V_11 * V_12 ,
unsigned int V_303 , unsigned long V_304 )
{
int V_103 ;
if ( V_12 -> V_20 -> V_287 ) {
if ( V_304 & V_305 )
V_304 &= ~ V_306 ;
snprintf ( V_12 -> V_307 , sizeof( V_12 -> V_307 ) , L_36 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_125 ) ;
V_103 = F_174 ( V_303 , & F_151 , V_304 ,
V_12 -> V_307 , V_12 ) ;
if ( V_103 != 0 ) {
F_63 ( V_12 -> V_15 . V_76 ,
L_37 ,
V_303 ) ;
return V_103 ;
}
V_12 -> V_287 = V_303 ;
F_52 ( V_12 -> V_15 . V_76 , L_38 , V_303 ,
( V_12 -> V_20 -> V_92 & V_308 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_309 ) ;
} else {
V_12 -> V_287 = 0 ;
if ( V_12 -> V_309 )
F_52 ( V_12 -> V_15 . V_76 , L_41 ,
( V_12 -> V_20 -> V_92 & V_308 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_309 ) ;
}
return 0 ;
}
int F_175 ( struct V_11 * V_12 ,
unsigned int V_303 , unsigned long V_304 )
{
int V_103 ;
struct V_1 * V_260 ;
F_52 ( V_12 -> V_15 . V_76 , L_42 , V_12 -> V_17 ) ;
if ( V_118 < 0 || V_118 > 1 )
V_12 -> V_118 = V_12 -> V_310 ? 0 : 1 ;
else
V_12 -> V_118 = V_118 ;
F_25 ( V_311 , & V_12 -> V_92 ) ;
if ( ( V_103 = F_176 ( V_12 ) ) != 0 ) {
F_15 ( V_12 -> V_15 . V_76 , L_43 ) ;
return V_103 ;
}
if ( ( V_103 = F_45 ( & V_12 -> V_15 ) ) < 0 )
goto V_312;
if ( ( V_260 = F_177 ( NULL , & V_12 -> V_15 , 0 ) ) == NULL ) {
F_63 ( V_12 -> V_15 . V_76 , L_44 ) ;
V_103 = - V_182 ;
goto V_313;
}
V_12 -> V_15 . V_48 = V_260 ;
switch ( V_12 -> V_59 ) {
case V_64 :
V_260 -> V_59 = V_160 ;
break;
case V_62 :
V_260 -> V_59 = V_161 ;
break;
case V_60 :
V_260 -> V_59 = V_148 ;
break;
default:
V_103 = - V_105 ;
goto V_314;
}
F_178 ( & V_260 -> V_49 , 1 ) ;
F_25 ( V_266 , & V_12 -> V_92 ) ;
if ( V_12 -> V_20 -> V_235 && ( V_103 = V_12 -> V_20 -> V_235 ( V_12 ) ) < 0 ) {
F_63 ( V_12 -> V_15 . V_76 , L_45 ) ;
goto V_315;
}
V_12 -> V_94 = 1 ;
if ( F_14 ( V_12 -> V_15 . V_76 )
&& F_14 ( & V_12 -> V_15 . V_48 -> V_49 ) )
F_15 ( V_12 -> V_15 . V_76 , L_46 ) ;
if ( F_156 ( V_12 ) && V_303 ) {
V_103 = F_173 ( V_12 , V_303 , V_304 ) ;
if ( V_103 )
goto V_316;
}
V_12 -> V_263 = V_277 ;
V_103 = V_12 -> V_20 -> V_317 ( V_12 ) ;
if ( V_103 < 0 ) {
F_63 ( V_12 -> V_15 . V_76 , L_47 , V_103 ) ;
goto V_318;
}
V_260 -> V_319 = F_179 ( 500u , V_12 -> V_320 ) ;
if ( ( V_103 = F_56 ( V_12 ) ) != 0 )
goto V_321;
V_103 = F_180 ( & V_260 -> V_49 . V_322 , & V_323 ) ;
if ( V_103 < 0 ) {
F_48 ( V_134 L_48 ,
V_103 ) ;
goto V_324;
}
if ( V_12 -> V_95 && F_27 ( V_12 ) )
F_21 ( V_12 ) ;
F_181 ( V_12 -> V_15 . V_76 ) ;
return V_103 ;
V_324:
F_24 ( V_266 , & V_12 -> V_92 ) ;
if ( F_182 ( V_12 -> V_263 ) )
V_12 -> V_263 = V_267 ;
F_8 ( & V_39 ) ;
V_12 -> V_149 = 0 ;
F_10 ( & V_39 ) ;
#ifdef F_165
F_183 ( & V_12 -> V_282 ) ;
#endif
F_46 ( & V_131 ) ;
F_184 ( & V_260 ) ;
F_50 ( & V_131 ) ;
V_321:
V_12 -> V_94 = 0 ;
F_24 ( V_292 , & V_12 -> V_92 ) ;
F_185 ( & V_12 -> V_99 ) ;
V_12 -> V_20 -> V_325 ( V_12 ) ;
V_12 -> V_263 = V_326 ;
F_24 ( V_292 , & V_12 -> V_92 ) ;
F_185 ( & V_12 -> V_99 ) ;
V_318:
if ( F_156 ( V_12 ) && V_12 -> V_287 > 0 )
F_186 ( V_303 , V_12 ) ;
V_316:
V_315:
V_314:
F_115 ( V_12 -> V_15 . V_48 ) ;
V_313:
F_53 ( & V_12 -> V_15 ) ;
V_312:
F_187 ( V_12 ) ;
return V_103 ;
}
void F_188 ( struct V_11 * V_12 )
{
struct V_1 * V_260 = V_12 -> V_15 . V_48 ;
F_52 ( V_12 -> V_15 . V_76 , L_49 , V_12 -> V_263 ) ;
F_114 ( V_260 ) ;
F_189 ( & V_260 -> V_49 . V_322 , & V_323 ) ;
F_24 ( V_266 , & V_12 -> V_92 ) ;
if ( F_182 ( V_12 -> V_263 ) )
V_12 -> V_263 = V_267 ;
F_15 ( V_12 -> V_15 . V_76 , L_50 ) ;
F_8 ( & V_39 ) ;
V_12 -> V_149 = 0 ;
F_10 ( & V_39 ) ;
#ifdef F_165
F_183 ( & V_12 -> V_282 ) ;
#endif
F_46 ( & V_131 ) ;
F_184 ( & V_260 ) ;
F_50 ( & V_131 ) ;
V_12 -> V_94 = 0 ;
F_24 ( V_292 , & V_12 -> V_92 ) ;
F_185 ( & V_12 -> V_99 ) ;
V_12 -> V_20 -> V_325 ( V_12 ) ;
V_12 -> V_263 = V_326 ;
F_24 ( V_292 , & V_12 -> V_92 ) ;
F_185 ( & V_12 -> V_99 ) ;
if ( F_156 ( V_12 ) ) {
if ( V_12 -> V_287 > 0 )
F_186 ( V_12 -> V_287 , V_12 ) ;
}
F_115 ( V_12 -> V_15 . V_48 ) ;
F_53 ( & V_12 -> V_15 ) ;
F_187 ( V_12 ) ;
}
void
F_190 ( struct V_327 * V_49 )
{
struct V_11 * V_12 = F_191 ( V_49 ) ;
if ( V_12 -> V_20 -> V_328 )
V_12 -> V_20 -> V_328 ( V_12 ) ;
}
int F_192 ( struct V_329 * V_330 )
{
if ( V_331 )
return - V_174 ;
V_331 = V_330 ;
F_193 () ;
return 0 ;
}
void F_194 ( void )
{
if ( V_331 == NULL ) {
F_48 ( V_134 L_51 ) ;
return;
}
V_331 = NULL ;
F_193 () ;
}
