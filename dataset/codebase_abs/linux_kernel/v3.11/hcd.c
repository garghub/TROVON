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
case V_66 :
V_35 = V_67 ;
break;
default:
goto error;
}
V_6 = 18 ;
if ( V_12 -> V_68 )
V_38 = 1 ;
break;
case V_69 << 8 :
switch ( V_12 -> V_59 ) {
case V_60 :
V_35 = V_70 ;
V_6 = sizeof V_70 ;
break;
case V_62 :
case V_64 :
V_35 = V_71 ;
V_6 = sizeof V_71 ;
break;
case V_66 :
V_35 = V_72 ;
V_6 = sizeof V_72 ;
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
case V_73 << 8 :
goto V_74;
default:
goto error;
}
break;
case V_46 | V_75 :
V_31 [ 0 ] = 0 ;
V_6 = 1 ;
case V_52 | V_76 :
break;
case V_52 | V_77 :
F_15 ( V_12 -> V_15 . V_78 , L_2 ,
V_26 ) ;
break;
case V_79 | V_47 :
V_31 [ 0 ] = 0 ;
V_31 [ 1 ] = 0 ;
V_6 = 2 ;
case V_80 | V_53 :
case V_80 | V_54 :
F_15 ( V_12 -> V_15 . V_78 , L_3 ) ;
break;
default:
V_74:
switch ( V_25 ) {
case V_81 :
case V_82 :
V_6 = 4 ;
break;
case V_83 :
V_6 = sizeof ( struct V_84 ) ;
break;
case V_46 | V_57 :
break;
}
V_36 = V_12 -> V_20 -> V_85 ( V_12 ,
V_25 , V_26 , V_27 ,
V_31 , V_28 ) ;
if ( V_25 == V_83 )
F_16 ( V_12 -> V_15 . V_48 ,
(struct V_84 * ) V_31 ) ;
break;
error:
V_36 = - V_86 ;
}
if ( V_36 < 0 ) {
V_6 = 0 ;
if ( V_36 != - V_86 ) {
F_15 ( V_12 -> V_15 . V_78 ,
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
V_6 > F_17 ( struct V_87 ,
V_88 ) )
( (struct V_87 * ) V_29 ) -> V_88
|= V_89 ;
if ( V_38 &&
V_6 > F_17 ( struct V_90 ,
V_91 ) )
( (struct V_90 * ) V_29 ) ->
V_91 = V_92 ;
}
F_8 ( & V_39 ) ;
F_18 ( V_12 , V_22 ) ;
F_19 ( & V_39 ) ;
F_20 ( V_12 , V_22 , V_36 ) ;
F_21 ( & V_39 ) ;
F_10 ( & V_39 ) ;
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
F_24 ( & V_39 , V_94 ) ;
V_22 = V_12 -> V_98 ;
if ( V_22 ) {
F_25 ( V_100 , & V_12 -> V_94 ) ;
V_12 -> V_98 = NULL ;
V_22 -> V_45 = V_93 ;
memcpy ( V_22 -> V_30 , V_95 , V_93 ) ;
F_18 ( V_12 , V_22 ) ;
F_19 ( & V_39 ) ;
F_20 ( V_12 , V_22 , 0 ) ;
F_21 ( & V_39 ) ;
} else {
V_93 = 0 ;
F_26 ( V_100 , & V_12 -> V_94 ) ;
}
F_27 ( & V_39 , V_94 ) ;
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
unsigned V_6 = 1 + ( V_22 -> V_49 -> V_106 / 8 ) ;
F_24 ( & V_39 , V_94 ) ;
if ( V_12 -> V_98 || V_22 -> V_44 < V_6 ) {
F_15 ( V_12 -> V_15 . V_78 , L_6 ) ;
V_105 = - V_107 ;
goto V_108;
}
V_105 = F_9 ( V_12 , V_22 ) ;
if ( V_105 )
goto V_108;
V_12 -> V_98 = V_22 ;
V_22 -> V_40 = V_12 ;
if ( ! V_12 -> V_97 )
F_29 ( & V_12 -> V_101 , ( V_102 / ( V_103 / 4 ) + 1 ) * ( V_103 / 4 ) ) ;
else if ( F_32 ( V_12 ) )
F_29 ( & V_12 -> V_101 , V_102 ) ;
V_105 = 0 ;
V_108:
F_27 ( & V_39 , V_94 ) ;
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
static int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
unsigned long V_94 ;
int V_111 ;
F_24 ( & V_39 , V_94 ) ;
V_111 = F_37 ( V_12 , V_22 , V_36 ) ;
if ( V_111 )
goto V_108;
if ( F_38 ( & V_22 -> V_109 -> V_110 ) == 0 ) {
;
} else {
if ( ! V_12 -> V_97 )
F_39 ( & V_12 -> V_101 ) ;
if ( V_22 == V_12 -> V_98 ) {
V_12 -> V_98 = NULL ;
F_18 ( V_12 , V_22 ) ;
F_19 ( & V_39 ) ;
F_20 ( V_12 , V_22 , V_36 ) ;
F_21 ( & V_39 ) ;
}
}
V_108:
F_27 ( & V_39 , V_94 ) ;
return V_111 ;
}
static T_3 F_40 ( struct V_112 * V_49 ,
struct V_113 * V_114 ,
char * V_5 )
{
struct V_1 * V_115 = F_41 ( V_49 ) ;
struct V_116 * V_116 = V_115 -> V_117 ;
struct V_11 * V_11 ;
if ( V_116 == NULL )
return - V_118 ;
V_11 = F_42 ( V_116 ) ;
return snprintf ( V_5 , V_119 , L_7 , V_11 -> V_120 ) ;
}
static T_3 F_43 ( struct V_112 * V_49 ,
struct V_113 * V_114 ,
const char * V_5 , T_4 V_121 )
{
T_3 V_122 ;
unsigned V_123 ;
struct V_1 * V_115 = F_41 ( V_49 ) ;
struct V_116 * V_116 = V_115 -> V_117 ;
struct V_11 * V_11 ;
if ( V_116 == NULL )
return - V_118 ;
V_11 = F_42 ( V_116 ) ;
V_122 = sscanf ( V_5 , L_7 , & V_123 ) ;
if ( V_122 == 1 ) {
V_11 -> V_120 = V_123 ? 1 : 0 ;
V_122 = V_121 ;
}
else
V_122 = - V_107 ;
return V_122 ;
}
static void F_44 ( struct V_116 * V_117 )
{
memset ( & V_117 -> V_124 , 0 , sizeof( struct V_125 ) ) ;
V_117 -> V_126 = 1 ;
V_117 -> V_48 = NULL ;
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
V_127 = F_48 ( V_134 . V_134 , V_135 , 1 ) ;
if ( V_127 >= V_135 ) {
F_49 ( V_136 L_8 , V_137 ) ;
goto V_138;
}
F_26 ( V_127 , V_134 . V_134 ) ;
V_117 -> V_127 = V_127 ;
F_50 ( & V_117 -> V_131 , & V_139 ) ;
F_51 ( & V_133 ) ;
F_52 ( V_117 ) ;
F_53 ( V_117 -> V_78 , L_9
L_10 , V_117 -> V_127 ) ;
return 0 ;
V_138:
F_51 ( & V_133 ) ;
return V_122 ;
}
static void F_54 ( struct V_116 * V_117 )
{
F_53 ( V_117 -> V_78 , L_11 , V_117 -> V_127 ) ;
F_47 ( & V_133 ) ;
F_55 ( & V_117 -> V_131 ) ;
F_51 ( & V_133 ) ;
F_56 ( V_117 ) ;
F_25 ( V_117 -> V_127 , V_134 . V_134 ) ;
}
static int F_57 ( struct V_11 * V_12 )
{
struct V_112 * V_140 = V_12 -> V_15 . V_78 ;
struct V_1 * V_141 = V_12 -> V_15 . V_48 ;
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
F_15 ( V_140 , L_12 ,
F_61 ( & V_141 -> V_49 ) , V_105 ) ;
return ( V_105 < 0 ) ? V_105 : - V_149 ;
}
if ( V_141 -> V_59 == V_150 ) {
V_105 = F_62 ( V_141 ) ;
if ( V_105 < 0 ) {
F_51 ( & V_133 ) ;
F_15 ( V_140 , L_13 ,
F_61 ( & V_141 -> V_49 ) , V_105 ) ;
return V_105 ;
}
}
V_105 = F_63 ( V_141 ) ;
if ( V_105 ) {
F_64 ( V_140 , L_14 ,
F_61 ( & V_141 -> V_49 ) , V_105 ) ;
} else {
F_8 ( & V_39 ) ;
V_12 -> V_151 = 1 ;
F_10 ( & V_39 ) ;
if ( F_65 ( V_12 ) )
F_66 ( V_12 ) ;
}
F_51 ( & V_133 ) ;
return V_105 ;
}
void F_67 ( struct V_116 * V_117 , int V_152 )
{
unsigned V_153 = 1 << V_152 ;
if ( ! ( V_117 -> V_154 & V_153 ) ) {
V_117 -> V_154 |= V_153 ;
F_68 ( & V_117 -> V_48 -> V_49 ) ;
}
}
void F_69 ( struct V_116 * V_117 , int V_152 )
{
unsigned V_153 = 1 << V_152 ;
if ( V_117 -> V_154 & V_153 ) {
V_117 -> V_154 &= ~ V_153 ;
F_70 ( & V_117 -> V_48 -> V_49 ) ;
}
}
long F_71 ( int V_59 , int V_155 , int V_156 , int V_157 )
{
unsigned long V_158 ;
switch ( V_59 ) {
case V_159 :
if ( V_155 ) {
V_158 = ( 67667L * ( 31L + 10L * F_72 ( V_157 ) ) ) / 1000L ;
return ( 64060L + ( 2 * V_160 ) + V_161 + V_158 ) ;
} else {
V_158 = ( 66700L * ( 31L + 10L * F_72 ( V_157 ) ) ) / 1000L ;
return ( 64107L + ( 2 * V_160 ) + V_161 + V_158 ) ;
}
case V_162 :
if ( V_156 ) {
V_158 = ( 8354L * ( 31L + 10L * F_72 ( V_157 ) ) ) / 1000L ;
return ( ( ( V_155 ) ? 7268L : 6265L ) + V_161 + V_158 ) ;
} else {
V_158 = ( 8354L * ( 31L + 10L * F_72 ( V_157 ) ) ) / 1000L ;
return ( 9107L + V_161 + V_158 ) ;
}
case V_163 :
if ( V_156 )
V_158 = F_73 ( V_157 ) ;
else
V_158 = F_74 ( V_157 ) ;
return V_158 ;
default:
F_75 ( L_15 , V_137 ) ;
return - 1 ;
}
}
int F_9 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_111 = 0 ;
F_21 ( & V_164 ) ;
if ( F_23 ( F_76 ( & V_22 -> V_165 ) ) ) {
V_111 = - V_166 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_109 -> V_167 ) ) {
V_111 = - V_168 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_49 -> V_169 ) ) {
V_111 = - V_170 ;
goto V_108;
}
if ( F_77 ( V_12 ) ) {
V_22 -> V_171 = 0 ;
F_78 ( & V_22 -> V_172 , & V_22 -> V_109 -> V_172 ) ;
} else {
V_111 = - V_173 ;
goto V_108;
}
V_108:
F_19 ( & V_164 ) ;
return V_111 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_36 )
{
struct V_174 * V_158 ;
F_79 (tmp, &urb->ep->urb_list) {
if ( V_158 == & V_22 -> V_172 )
break;
}
if ( V_158 != & V_22 -> V_172 )
return - V_175 ;
if ( V_22 -> V_171 )
return - V_176 ;
V_22 -> V_171 = V_36 ;
return 0 ;
}
void F_18 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_21 ( & V_164 ) ;
F_80 ( & V_22 -> V_172 ) ;
F_19 ( & V_164 ) ;
}
static int F_81 ( struct V_116 * V_117 ,
T_5 V_177 , T_6 * V_178 ,
void * * V_179 , T_4 V_121 ,
enum V_180 V_181 )
{
unsigned char * V_182 ;
if ( * V_179 == NULL ) {
F_82 ( 1 ) ;
return - V_183 ;
}
V_182 = F_83 ( V_117 , V_121 + sizeof( V_182 ) ,
V_177 , V_178 ) ;
if ( ! V_182 )
return - V_184 ;
F_84 ( ( unsigned long ) * V_179 ,
( unsigned long * ) ( V_182 + V_121 ) ) ;
if ( V_181 == V_185 )
memcpy ( V_182 , * V_179 , V_121 ) ;
* V_179 = V_182 ;
return 0 ;
}
static void F_85 ( struct V_116 * V_117 , T_6 * V_178 ,
void * * V_179 , T_4 V_121 ,
enum V_180 V_181 )
{
unsigned char * V_182 = * V_179 ;
V_182 = ( void * ) F_86 ( ( unsigned long * ) ( V_182 + V_121 ) ) ;
if ( V_181 == V_186 )
memcpy ( V_182 , * V_179 , V_121 ) ;
F_87 ( V_117 , V_121 + sizeof( V_182 ) , * V_179 , * V_178 ) ;
* V_179 = V_182 ;
* V_178 = 0 ;
}
void F_88 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_187 & V_188 )
F_89 ( V_12 -> V_15 . V_78 ,
V_22 -> V_189 ,
sizeof( struct V_23 ) ,
V_185 ) ;
else if ( V_22 -> V_187 & V_190 )
F_85 ( V_22 -> V_49 -> V_117 ,
& V_22 -> V_189 ,
( void * * ) & V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_185 ) ;
V_22 -> V_187 &= ~ ( V_188 | V_190 ) ;
}
static void F_90 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_90 )
V_12 -> V_20 -> F_90 ( V_12 , V_22 ) ;
else
F_91 ( V_12 , V_22 ) ;
}
void F_91 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_180 V_181 ;
F_88 ( V_12 , V_22 ) ;
V_181 = F_92 ( V_22 ) ? V_186 : V_185 ;
if ( V_22 -> V_187 & V_191 )
F_93 ( V_12 -> V_15 . V_78 ,
V_22 -> V_192 ,
V_22 -> V_193 ,
V_181 ) ;
else if ( V_22 -> V_187 & V_194 )
F_94 ( V_12 -> V_15 . V_78 ,
V_22 -> V_195 ,
V_22 -> V_44 ,
V_181 ) ;
else if ( V_22 -> V_187 & V_196 )
F_89 ( V_12 -> V_15 . V_78 ,
V_22 -> V_195 ,
V_22 -> V_44 ,
V_181 ) ;
else if ( V_22 -> V_187 & V_197 )
F_85 ( V_22 -> V_49 -> V_117 ,
& V_22 -> V_195 ,
& V_22 -> V_30 ,
V_22 -> V_44 ,
V_181 ) ;
V_22 -> V_187 &= ~ ( V_191 | V_194 |
V_196 | V_197 ) ;
}
static int F_95 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_177 )
{
if ( V_12 -> V_20 -> F_95 )
return V_12 -> V_20 -> F_95 ( V_12 , V_22 , V_177 ) ;
else
return F_96 ( V_12 , V_22 , V_177 ) ;
}
int F_96 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_177 )
{
enum V_180 V_181 ;
int V_198 = 0 ;
if ( F_35 ( & V_22 -> V_109 -> V_110 ) ) {
if ( V_12 -> V_15 . V_199 )
return V_198 ;
if ( V_12 -> V_15 . V_200 ) {
V_22 -> V_189 = F_97 (
V_12 -> V_15 . V_78 ,
V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_185 ) ;
if ( F_98 ( V_12 -> V_15 . V_78 ,
V_22 -> V_189 ) )
return - V_201 ;
V_22 -> V_187 |= V_188 ;
} else if ( V_12 -> V_20 -> V_94 & V_202 ) {
V_198 = F_81 (
V_22 -> V_49 -> V_117 , V_177 ,
& V_22 -> V_189 ,
( void * * ) & V_22 -> V_41 ,
sizeof( struct V_23 ) ,
V_185 ) ;
if ( V_198 )
return V_198 ;
V_22 -> V_187 |= V_190 ;
}
}
V_181 = F_92 ( V_22 ) ? V_186 : V_185 ;
if ( V_22 -> V_44 != 0
&& ! ( V_22 -> V_187 & V_203 ) ) {
if ( V_12 -> V_15 . V_200 ) {
if ( V_22 -> V_193 ) {
int V_7 ;
if ( F_99 ( & V_22 -> V_109 -> V_110 ) ) {
F_100 ( 1 ) ;
return - V_107 ;
}
V_7 = F_101 (
V_12 -> V_15 . V_78 ,
V_22 -> V_192 ,
V_22 -> V_193 ,
V_181 ) ;
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
V_22 -> V_195 = F_102 (
V_12 -> V_15 . V_78 ,
F_103 ( V_192 ) ,
V_192 -> V_207 ,
V_22 -> V_44 ,
V_181 ) ;
if ( F_98 ( V_12 -> V_15 . V_78 ,
V_22 -> V_195 ) )
V_198 = - V_201 ;
else
V_22 -> V_187 |= V_194 ;
} else {
V_22 -> V_195 = F_97 (
V_12 -> V_15 . V_78 ,
V_22 -> V_30 ,
V_22 -> V_44 ,
V_181 ) ;
if ( F_98 ( V_12 -> V_15 . V_78 ,
V_22 -> V_195 ) )
V_198 = - V_201 ;
else
V_22 -> V_187 |= V_196 ;
}
} else if ( V_12 -> V_20 -> V_94 & V_202 ) {
V_198 = F_81 (
V_22 -> V_49 -> V_117 , V_177 ,
& V_22 -> V_195 ,
& V_22 -> V_30 ,
V_22 -> V_44 ,
V_181 ) ;
if ( V_198 == 0 )
V_22 -> V_187 |= V_197 ;
}
if ( V_198 && ( V_22 -> V_187 & ( V_188 |
V_190 ) ) )
F_91 ( V_12 , V_22 ) ;
}
return V_198 ;
}
int F_104 ( struct V_22 * V_22 , T_5 V_177 )
{
int V_36 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_49 -> V_117 ) ;
F_105 ( V_22 ) ;
F_106 ( & V_22 -> V_208 ) ;
F_106 ( & V_22 -> V_49 -> V_209 ) ;
F_107 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_49 ) ) {
V_36 = F_33 ( V_12 , V_22 ) ;
} else {
V_36 = F_95 ( V_12 , V_22 , V_177 ) ;
if ( F_108 ( V_36 == 0 ) ) {
V_36 = V_12 -> V_20 -> V_210 ( V_12 , V_22 , V_177 ) ;
if ( F_23 ( V_36 ) )
F_90 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_36 ) ) {
F_109 ( & V_12 -> V_15 , V_22 , V_36 ) ;
V_22 -> V_40 = NULL ;
F_45 ( & V_22 -> V_172 ) ;
F_110 ( & V_22 -> V_208 ) ;
F_110 ( & V_22 -> V_49 -> V_209 ) ;
if ( F_76 ( & V_22 -> V_165 ) )
F_111 ( & V_211 ) ;
F_112 ( V_22 ) ;
}
return V_36 ;
}
static int F_113 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
int V_212 ;
if ( F_1 ( V_22 -> V_49 ) )
V_212 = F_36 ( V_12 , V_22 , V_36 ) ;
else {
V_212 = V_12 -> V_20 -> V_213 ( V_12 , V_22 , V_36 ) ;
}
return V_212 ;
}
int F_114 ( struct V_22 * V_22 , int V_36 )
{
struct V_11 * V_12 ;
int V_105 = - V_175 ;
unsigned long V_94 ;
F_24 ( & V_214 , V_94 ) ;
if ( F_76 ( & V_22 -> V_208 ) > 0 ) {
V_105 = 0 ;
F_115 ( V_22 -> V_49 ) ;
}
F_27 ( & V_214 , V_94 ) ;
if ( V_105 == 0 ) {
V_12 = F_42 ( V_22 -> V_49 -> V_117 ) ;
V_105 = F_113 ( V_12 , V_22 , V_36 ) ;
F_116 ( V_22 -> V_49 ) ;
}
if ( V_105 == 0 )
V_105 = - V_215 ;
else if ( V_105 != - V_175 && V_105 != - V_176 )
F_15 ( & V_22 -> V_49 -> V_49 , L_16 ,
V_22 , V_105 ) ;
return V_105 ;
}
void F_20 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_36 )
{
V_22 -> V_40 = NULL ;
if ( F_23 ( V_22 -> V_171 ) )
V_36 = V_22 -> V_171 ;
else if ( F_23 ( ( V_22 -> V_187 & V_216 ) &&
V_22 -> V_45 < V_22 -> V_44 &&
! V_36 ) )
V_36 = - V_217 ;
F_90 ( V_12 , V_22 ) ;
F_117 ( & V_12 -> V_15 , V_22 , V_36 ) ;
F_118 ( V_22 ) ;
V_22 -> V_36 = V_36 ;
V_22 -> V_218 ( V_22 ) ;
F_110 ( & V_22 -> V_208 ) ;
if ( F_23 ( F_76 ( & V_22 -> V_165 ) ) )
F_111 ( & V_211 ) ;
F_112 ( V_22 ) ;
}
void F_119 ( struct V_1 * V_2 ,
struct V_219 * V_109 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_109 )
return;
F_7 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
F_8 ( & V_164 ) ;
V_220:
F_120 (urb, &ep->urb_list, urb_list) {
int V_221 ;
if ( V_22 -> V_171 )
continue;
F_105 ( V_22 ) ;
V_221 = F_92 ( V_22 ) ;
F_19 ( & V_164 ) ;
F_113 ( V_12 , V_22 , - V_173 ) ;
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
F_112 ( V_22 ) ;
F_21 ( & V_164 ) ;
goto V_220;
}
F_10 ( & V_164 ) ;
while ( ! F_121 ( & V_109 -> V_172 ) ) {
F_8 ( & V_164 ) ;
V_22 = NULL ;
if ( ! F_121 ( & V_109 -> V_172 ) ) {
V_22 = F_122 ( V_109 -> V_172 . V_222 , struct V_22 ,
V_172 ) ;
F_105 ( V_22 ) ;
}
F_10 ( & V_164 ) ;
if ( V_22 ) {
F_123 ( V_22 ) ;
F_112 ( V_22 ) ;
}
}
}
int F_124 ( struct V_1 * V_2 ,
struct V_223 * V_224 ,
struct V_225 * V_226 ,
struct V_225 * V_227 )
{
int V_228 , V_229 , V_230 ;
struct V_225 * V_231 = NULL ;
int V_198 = 0 ;
struct V_11 * V_12 ;
struct V_219 * V_109 ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_232 )
return 0 ;
if ( ! V_224 && ! V_226 ) {
for ( V_229 = 1 ; V_229 < 16 ; ++ V_229 ) {
V_109 = V_2 -> V_233 [ V_229 ] ;
if ( V_109 )
V_12 -> V_20 -> V_234 ( V_12 , V_2 , V_109 ) ;
V_109 = V_2 -> V_235 [ V_229 ] ;
if ( V_109 )
V_12 -> V_20 -> V_234 ( V_12 , V_2 , V_109 ) ;
}
V_12 -> V_20 -> V_232 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_224 ) {
V_228 = V_224 -> V_110 . V_236 ;
for ( V_229 = 1 ; V_229 < 16 ; ++ V_229 ) {
V_109 = V_2 -> V_233 [ V_229 ] ;
if ( V_109 ) {
V_198 = V_12 -> V_20 -> V_234 ( V_12 , V_2 , V_109 ) ;
if ( V_198 < 0 )
goto V_237;
}
V_109 = V_2 -> V_235 [ V_229 ] ;
if ( V_109 ) {
V_198 = V_12 -> V_20 -> V_234 ( V_12 , V_2 , V_109 ) ;
if ( V_198 < 0 )
goto V_237;
}
}
for ( V_229 = 0 ; V_229 < V_228 ; ++ V_229 ) {
struct V_225 * V_238 ;
int V_239 ;
V_238 = & V_224 -> V_240 [ V_229 ] -> V_241 [ 0 ] ;
V_239 = V_238 -> V_110 . V_242 ;
V_231 = F_125 ( V_224 , V_239 , 0 ) ;
if ( ! V_231 )
V_231 = V_238 ;
for ( V_230 = 0 ; V_230 < V_231 -> V_110 . V_243 ; V_230 ++ ) {
V_198 = V_12 -> V_20 -> V_244 ( V_12 , V_2 , & V_231 -> V_245 [ V_230 ] ) ;
if ( V_198 < 0 )
goto V_237;
}
}
}
if ( V_226 && V_227 ) {
struct V_246 * V_247 = F_126 ( V_2 ,
V_226 -> V_110 . V_242 ) ;
if ( ! V_247 )
return - V_107 ;
if ( V_247 -> V_248 ) {
V_226 = F_127 ( V_247 , 0 ) ;
if ( ! V_226 )
V_226 = & V_247 -> V_241 [ 0 ] ;
}
for ( V_229 = 0 ; V_229 < V_226 -> V_110 . V_243 ; V_229 ++ ) {
V_198 = V_12 -> V_20 -> V_234 ( V_12 , V_2 ,
& V_226 -> V_245 [ V_229 ] ) ;
if ( V_198 < 0 )
goto V_237;
}
for ( V_229 = 0 ; V_229 < V_227 -> V_110 . V_243 ; V_229 ++ ) {
V_198 = V_12 -> V_20 -> V_244 ( V_12 , V_2 ,
& V_227 -> V_245 [ V_229 ] ) ;
if ( V_198 < 0 )
goto V_237;
}
}
V_198 = V_12 -> V_20 -> V_232 ( V_12 , V_2 ) ;
V_237:
if ( V_198 < 0 )
V_12 -> V_20 -> V_249 ( V_12 , V_2 ) ;
return V_198 ;
}
void F_128 ( struct V_1 * V_2 ,
struct V_219 * V_109 )
{
struct V_11 * V_12 ;
F_7 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_250 )
V_12 -> V_20 -> V_250 ( V_12 , V_109 ) ;
}
void F_129 ( struct V_1 * V_2 ,
struct V_219 * V_109 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_251 )
V_12 -> V_20 -> V_251 ( V_12 , V_109 ) ;
else {
int V_252 = F_38 ( & V_109 -> V_110 ) ;
int V_253 = F_130 ( & V_109 -> V_110 ) ;
int V_254 = F_35 ( & V_109 -> V_110 ) ;
F_131 ( V_2 , V_252 , V_253 , 0 ) ;
if ( V_254 )
F_131 ( V_2 , V_252 , ! V_253 , 0 ) ;
}
}
int F_132 ( struct V_246 * V_255 ,
struct V_219 * * V_256 , unsigned int V_257 ,
unsigned int V_258 , T_5 V_177 )
{
struct V_11 * V_12 ;
struct V_1 * V_49 ;
int V_229 ;
V_49 = F_133 ( V_255 ) ;
V_12 = F_42 ( V_49 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_259 || ! V_12 -> V_20 -> V_260 )
return - V_107 ;
if ( V_49 -> V_59 != V_150 )
return - V_107 ;
for ( V_229 = 0 ; V_229 < V_257 ; V_229 ++ )
if ( ! F_134 ( & V_256 [ V_229 ] -> V_110 ) )
return - V_107 ;
return V_12 -> V_20 -> V_259 ( V_12 , V_49 , V_256 , V_257 ,
V_258 , V_177 ) ;
}
void F_135 ( struct V_246 * V_255 ,
struct V_219 * * V_256 , unsigned int V_257 ,
T_5 V_177 )
{
struct V_11 * V_12 ;
struct V_1 * V_49 ;
int V_229 ;
V_49 = F_133 ( V_255 ) ;
V_12 = F_42 ( V_49 -> V_117 ) ;
if ( V_49 -> V_59 != V_150 )
return;
for ( V_229 = 0 ; V_229 < V_257 ; V_229 ++ )
if ( ! V_256 [ V_229 ] || ! F_134 ( & V_256 [ V_229 ] -> V_110 ) )
return;
V_12 -> V_20 -> V_260 ( V_12 , V_49 , V_256 , V_257 , V_177 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
F_8 ( & V_214 ) ;
F_10 ( & V_214 ) ;
}
int F_137 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! F_77 ( V_12 ) )
return - V_173 ;
return V_12 -> V_20 -> V_261 ( V_12 ) ;
}
int F_138 ( struct V_1 * V_262 , T_7 V_263 )
{
struct V_11 * V_12 = F_139 ( V_262 -> V_117 , struct V_11 , V_15 ) ;
int V_36 ;
int V_264 = V_12 -> V_265 ;
F_15 ( & V_262 -> V_49 , L_24 ,
( F_140 ( V_263 ) ? L_25 : L_20 ) ,
V_262 -> V_266 ) ;
if ( F_65 ( V_12 ) ) {
F_15 ( & V_262 -> V_49 , L_26 , L_27 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_267 ) {
V_36 = - V_168 ;
} else {
F_25 ( V_268 , & V_12 -> V_94 ) ;
V_12 -> V_265 = V_269 ;
V_36 = V_12 -> V_20 -> V_267 ( V_12 ) ;
}
if ( V_36 == 0 ) {
F_58 ( V_262 , V_270 ) ;
V_12 -> V_265 = V_271 ;
if ( V_262 -> V_266 ) {
char V_95 [ 6 ] ;
V_36 = V_12 -> V_20 -> V_99 ( V_12 , V_95 ) ;
if ( V_36 != 0 ) {
F_15 ( & V_262 -> V_49 , L_28 ) ;
F_141 ( V_262 , V_272 ) ;
V_36 = - V_176 ;
}
}
} else {
F_8 ( & V_39 ) ;
if ( ! F_65 ( V_12 ) ) {
F_26 ( V_268 , & V_12 -> V_94 ) ;
V_12 -> V_265 = V_264 ;
}
F_10 ( & V_39 ) ;
F_15 ( & V_262 -> V_49 , L_29 ,
L_27 , V_36 ) ;
}
return V_36 ;
}
int F_141 ( struct V_1 * V_262 , T_7 V_263 )
{
struct V_11 * V_12 = F_139 ( V_262 -> V_117 , struct V_11 , V_15 ) ;
int V_36 ;
int V_264 = V_12 -> V_265 ;
F_15 ( & V_262 -> V_49 , L_30 ,
( F_140 ( V_263 ) ? L_25 : L_20 ) ) ;
if ( F_65 ( V_12 ) ) {
F_15 ( & V_262 -> V_49 , L_26 , L_31 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_273 )
return - V_168 ;
if ( F_77 ( V_12 ) )
return 0 ;
V_12 -> V_265 = V_274 ;
V_36 = V_12 -> V_20 -> V_273 ( V_12 ) ;
F_25 ( V_275 , & V_12 -> V_94 ) ;
if ( V_36 == 0 ) {
struct V_1 * V_2 ;
int V_276 ;
F_8 ( & V_39 ) ;
if ( ! F_65 ( V_12 ) ) {
F_58 ( V_262 , V_262 -> V_277
? V_278
: V_144 ) ;
F_26 ( V_268 , & V_12 -> V_94 ) ;
V_12 -> V_265 = V_279 ;
}
F_10 ( & V_39 ) ;
F_142 (rhdev, port1, udev) {
if ( V_2 -> V_265 != V_280 &&
! V_2 -> V_281 ) {
F_143 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_265 = V_264 ;
F_15 ( & V_262 -> V_49 , L_29 ,
L_31 , V_36 ) ;
if ( V_36 != - V_173 )
F_66 ( V_12 ) ;
}
return V_36 ;
}
static void F_144 ( struct V_282 * V_283 )
{
struct V_11 * V_12 = F_139 ( V_283 , struct V_11 , V_284 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_48 ;
F_145 ( V_2 ) ;
F_146 ( V_2 ) ;
F_147 ( V_2 ) ;
}
void F_148 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_24 ( & V_39 , V_94 ) ;
if ( V_12 -> V_151 ) {
F_26 ( V_275 , & V_12 -> V_94 ) ;
F_149 ( V_285 , & V_12 -> V_284 ) ;
}
F_27 ( & V_39 , V_94 ) ;
}
int F_150 ( struct V_116 * V_117 , unsigned V_286 )
{
struct V_11 * V_12 ;
int V_36 = - V_287 ;
V_12 = F_139 ( V_117 , struct V_11 , V_15 ) ;
if ( V_286 && V_12 -> V_20 -> V_288 )
V_36 = V_12 -> V_20 -> V_288 ( V_12 , V_286 ) ;
if ( V_36 == 0 )
F_29 ( & V_12 -> V_101 , V_102 + F_151 ( 10 ) ) ;
return V_36 ;
}
T_8 F_152 ( int V_289 , void * V_290 )
{
struct V_11 * V_12 = V_290 ;
unsigned long V_94 ;
T_8 V_111 ;
F_153 ( V_94 ) ;
if ( F_23 ( F_65 ( V_12 ) || ! F_154 ( V_12 ) ) )
V_111 = V_291 ;
else if ( V_12 -> V_20 -> V_289 ( V_12 ) == V_291 )
V_111 = V_291 ;
else
V_111 = V_292 ;
F_155 ( V_94 ) ;
return V_111 ;
}
void F_66 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_64 ( V_12 -> V_15 . V_78 , L_32 ) ;
F_24 ( & V_39 , V_94 ) ;
F_25 ( V_268 , & V_12 -> V_94 ) ;
F_26 ( V_293 , & V_12 -> V_94 ) ;
if ( V_12 -> V_151 ) {
F_25 ( V_294 , & V_12 -> V_94 ) ;
F_58 ( V_12 -> V_15 . V_48 ,
V_280 ) ;
F_156 ( V_12 -> V_15 . V_48 ) ;
}
if ( F_157 ( V_12 ) && V_12 -> V_295 ) {
V_12 = V_12 -> V_295 ;
if ( V_12 -> V_151 ) {
F_25 ( V_294 , & V_12 -> V_94 ) ;
F_58 ( V_12 -> V_15 . V_48 ,
V_280 ) ;
F_156 ( V_12 -> V_15 . V_48 ) ;
}
}
F_27 ( & V_39 , V_94 ) ;
}
struct V_11 * F_158 ( const struct V_296 * V_20 ,
struct V_112 * V_49 , const char * V_16 ,
struct V_11 * V_297 )
{
struct V_11 * V_12 ;
V_12 = F_159 ( sizeof( * V_12 ) + V_20 -> V_298 , V_299 ) ;
if ( ! V_12 ) {
F_15 ( V_49 , L_33 ) ;
return NULL ;
}
if ( V_297 == NULL ) {
V_12 -> V_300 = F_160 ( sizeof( * V_12 -> V_300 ) ,
V_299 ) ;
if ( ! V_12 -> V_300 ) {
F_161 ( V_12 ) ;
F_15 ( V_49 , L_34 ) ;
return NULL ;
}
F_162 ( V_12 -> V_300 ) ;
F_163 ( V_49 , V_12 ) ;
} else {
V_12 -> V_300 = V_297 -> V_300 ;
V_12 -> V_297 = V_297 ;
V_297 -> V_297 = V_297 ;
V_12 -> V_295 = V_297 ;
V_297 -> V_295 = V_12 ;
}
F_164 ( & V_12 -> V_301 ) ;
F_44 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_78 = V_49 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_200 = ( V_49 -> V_302 != NULL ) ;
F_165 ( & V_12 -> V_101 ) ;
V_12 -> V_101 . V_303 = F_30 ;
V_12 -> V_101 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_166
F_167 ( & V_12 -> V_284 , F_144 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_59 = V_20 -> V_94 & V_304 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_35 ;
return V_12 ;
}
struct V_11 * F_168 ( const struct V_296 * V_20 ,
struct V_112 * V_49 , const char * V_16 )
{
return F_158 ( V_20 , V_49 , V_16 , NULL ) ;
}
static void F_169 ( struct V_301 * V_301 )
{
struct V_11 * V_12 = F_139 ( V_301 , struct V_11 , V_301 ) ;
if ( F_157 ( V_12 ) )
F_161 ( V_12 -> V_300 ) ;
else
V_12 -> V_295 -> V_295 = NULL ;
F_161 ( V_12 ) ;
}
struct V_11 * F_170 ( struct V_11 * V_12 )
{
if ( V_12 )
F_171 ( & V_12 -> V_301 ) ;
return V_12 ;
}
void F_172 ( struct V_11 * V_12 )
{
if ( V_12 )
F_173 ( & V_12 -> V_301 , F_169 ) ;
}
int F_157 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_297 )
return 1 ;
return V_12 == V_12 -> V_297 ;
}
int F_174 ( struct V_11 * V_12 , int V_276 )
{
if ( ! V_12 -> V_20 -> V_305 )
return V_276 ;
return V_12 -> V_20 -> V_305 ( V_12 , V_276 ) ;
}
static int F_175 ( struct V_11 * V_12 ,
unsigned int V_306 , unsigned long V_307 )
{
int V_105 ;
if ( V_12 -> V_20 -> V_289 ) {
if ( V_307 & V_308 )
V_307 &= ~ V_309 ;
snprintf ( V_12 -> V_310 , sizeof( V_12 -> V_310 ) , L_36 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_127 ) ;
V_105 = F_176 ( V_306 , & F_152 , V_307 ,
V_12 -> V_310 , V_12 ) ;
if ( V_105 != 0 ) {
F_64 ( V_12 -> V_15 . V_78 ,
L_37 ,
V_306 ) ;
return V_105 ;
}
V_12 -> V_289 = V_306 ;
F_53 ( V_12 -> V_15 . V_78 , L_38 , V_306 ,
( V_12 -> V_20 -> V_94 & V_311 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_312 ) ;
} else {
V_12 -> V_289 = 0 ;
if ( V_12 -> V_312 )
F_53 ( V_12 -> V_15 . V_78 , L_41 ,
( V_12 -> V_20 -> V_94 & V_311 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_312 ) ;
}
return 0 ;
}
int F_177 ( struct V_11 * V_12 ,
unsigned int V_306 , unsigned long V_307 )
{
int V_105 ;
struct V_1 * V_262 ;
F_53 ( V_12 -> V_15 . V_78 , L_42 , V_12 -> V_17 ) ;
if ( V_120 < 0 || V_120 > 1 )
V_12 -> V_120 = V_12 -> V_313 ? 0 : 1 ;
else
V_12 -> V_120 = V_120 ;
F_26 ( V_314 , & V_12 -> V_94 ) ;
if ( ( V_105 = F_178 ( V_12 ) ) != 0 ) {
F_15 ( V_12 -> V_15 . V_78 , L_43 ) ;
return V_105 ;
}
if ( ( V_105 = F_46 ( & V_12 -> V_15 ) ) < 0 )
goto V_315;
if ( ( V_262 = F_179 ( NULL , & V_12 -> V_15 , 0 ) ) == NULL ) {
F_64 ( V_12 -> V_15 . V_78 , L_44 ) ;
V_105 = - V_184 ;
goto V_316;
}
V_12 -> V_15 . V_48 = V_262 ;
switch ( V_12 -> V_59 ) {
case V_66 :
V_262 -> V_59 = V_162 ;
break;
case V_64 :
V_262 -> V_59 = V_163 ;
break;
case V_62 :
V_262 -> V_59 = V_317 ;
break;
case V_60 :
V_262 -> V_59 = V_150 ;
break;
default:
V_105 = - V_107 ;
goto V_318;
}
F_180 ( & V_262 -> V_49 , 1 ) ;
F_26 ( V_268 , & V_12 -> V_94 ) ;
if ( V_12 -> V_20 -> V_237 && ( V_105 = V_12 -> V_20 -> V_237 ( V_12 ) ) < 0 ) {
F_64 ( V_12 -> V_15 . V_78 , L_45 ) ;
goto V_319;
}
V_12 -> V_96 = 1 ;
if ( F_14 ( V_12 -> V_15 . V_78 )
&& F_14 ( & V_12 -> V_15 . V_48 -> V_49 ) )
F_15 ( V_12 -> V_15 . V_78 , L_46 ) ;
if ( F_157 ( V_12 ) && V_306 ) {
V_105 = F_175 ( V_12 , V_306 , V_307 ) ;
if ( V_105 )
goto V_320;
}
V_12 -> V_265 = V_279 ;
V_105 = V_12 -> V_20 -> V_321 ( V_12 ) ;
if ( V_105 < 0 ) {
F_64 ( V_12 -> V_15 . V_78 , L_47 , V_105 ) ;
goto V_322;
}
if ( ( V_105 = F_57 ( V_12 ) ) != 0 )
goto V_323;
V_105 = F_181 ( & V_262 -> V_49 . V_324 , & V_325 ) ;
if ( V_105 < 0 ) {
F_49 ( V_136 L_48 ,
V_105 ) ;
goto V_326;
}
if ( V_12 -> V_97 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
F_182 ( V_12 -> V_15 . V_78 ) ;
return V_105 ;
V_326:
F_25 ( V_268 , & V_12 -> V_94 ) ;
if ( F_183 ( V_12 -> V_265 ) )
V_12 -> V_265 = V_269 ;
F_8 ( & V_39 ) ;
V_12 -> V_151 = 0 ;
F_10 ( & V_39 ) ;
#ifdef F_166
F_184 ( & V_12 -> V_284 ) ;
#endif
F_47 ( & V_133 ) ;
F_185 ( & V_262 ) ;
F_51 ( & V_133 ) ;
V_323:
V_12 -> V_96 = 0 ;
F_25 ( V_294 , & V_12 -> V_94 ) ;
F_186 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_327 ( V_12 ) ;
V_12 -> V_265 = V_328 ;
F_25 ( V_294 , & V_12 -> V_94 ) ;
F_186 ( & V_12 -> V_101 ) ;
V_322:
if ( F_157 ( V_12 ) && V_12 -> V_289 > 0 )
F_187 ( V_306 , V_12 ) ;
V_320:
V_319:
V_318:
F_116 ( V_12 -> V_15 . V_48 ) ;
V_316:
F_54 ( & V_12 -> V_15 ) ;
V_315:
F_188 ( V_12 ) ;
return V_105 ;
}
void F_189 ( struct V_11 * V_12 )
{
struct V_1 * V_262 = V_12 -> V_15 . V_48 ;
F_53 ( V_12 -> V_15 . V_78 , L_49 , V_12 -> V_265 ) ;
F_115 ( V_262 ) ;
F_190 ( & V_262 -> V_49 . V_324 , & V_325 ) ;
F_25 ( V_268 , & V_12 -> V_94 ) ;
if ( F_183 ( V_12 -> V_265 ) )
V_12 -> V_265 = V_269 ;
F_15 ( V_12 -> V_15 . V_78 , L_50 ) ;
F_8 ( & V_39 ) ;
V_12 -> V_151 = 0 ;
F_10 ( & V_39 ) ;
#ifdef F_166
F_184 ( & V_12 -> V_284 ) ;
#endif
F_47 ( & V_133 ) ;
F_185 ( & V_262 ) ;
F_51 ( & V_133 ) ;
V_12 -> V_96 = 0 ;
F_25 ( V_294 , & V_12 -> V_94 ) ;
F_186 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_327 ( V_12 ) ;
V_12 -> V_265 = V_328 ;
F_25 ( V_294 , & V_12 -> V_94 ) ;
F_186 ( & V_12 -> V_101 ) ;
if ( F_157 ( V_12 ) ) {
if ( V_12 -> V_289 > 0 )
F_187 ( V_12 -> V_289 , V_12 ) ;
}
F_116 ( V_12 -> V_15 . V_48 ) ;
F_54 ( & V_12 -> V_15 ) ;
F_188 ( V_12 ) ;
}
void
F_191 ( struct V_329 * V_49 )
{
struct V_11 * V_12 = F_192 ( V_49 ) ;
if ( V_12 -> V_20 -> V_330 )
V_12 -> V_20 -> V_330 ( V_12 ) ;
}
int F_193 ( struct V_331 * V_332 )
{
if ( V_333 )
return - V_176 ;
V_333 = V_332 ;
F_194 () ;
return 0 ;
}
void F_195 ( void )
{
if ( V_333 == NULL ) {
F_49 ( V_136 L_51 ) ;
return;
}
V_333 = NULL ;
F_194 () ;
}
