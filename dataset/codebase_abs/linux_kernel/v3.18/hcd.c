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
if ( V_141 -> V_60 == V_150 ) {
V_105 = F_63 ( V_141 ) ;
if ( V_105 < 0 ) {
F_52 ( & V_133 ) ;
F_16 ( V_140 , L_13 ,
F_62 ( & V_141 -> V_50 ) , V_105 ) ;
return V_105 ;
}
}
V_105 = F_64 ( V_141 ) ;
if ( V_105 ) {
F_65 ( V_140 , L_14 ,
F_62 ( & V_141 -> V_50 ) , V_105 ) ;
} else {
F_7 ( & V_37 ) ;
V_12 -> V_151 = 1 ;
F_9 ( & V_37 ) ;
if ( F_66 ( V_12 ) )
F_67 ( V_12 ) ;
}
F_52 ( & V_133 ) ;
return V_105 ;
}
void F_68 ( struct V_116 * V_117 , int V_152 )
{
unsigned V_153 = 1 << V_152 ;
if ( ! ( V_117 -> V_154 & V_153 ) ) {
V_117 -> V_154 |= V_153 ;
F_69 ( & V_117 -> V_49 -> V_50 ) ;
}
}
void F_70 ( struct V_116 * V_117 , int V_152 )
{
unsigned V_153 = 1 << V_152 ;
if ( V_117 -> V_154 & V_153 ) {
V_117 -> V_154 &= ~ V_153 ;
F_71 ( & V_117 -> V_49 -> V_50 ) ;
}
}
long F_72 ( int V_60 , int V_155 , int V_156 , int V_157 )
{
unsigned long V_158 ;
switch ( V_60 ) {
case V_159 :
if ( V_155 ) {
V_158 = ( 67667L * ( 31L + 10L * F_73 ( V_157 ) ) ) / 1000L ;
return 64060L + ( 2 * V_160 ) + V_161 + V_158 ;
} else {
V_158 = ( 66700L * ( 31L + 10L * F_73 ( V_157 ) ) ) / 1000L ;
return 64107L + ( 2 * V_160 ) + V_161 + V_158 ;
}
case V_162 :
if ( V_156 ) {
V_158 = ( 8354L * ( 31L + 10L * F_73 ( V_157 ) ) ) / 1000L ;
return ( ( V_155 ) ? 7268L : 6265L ) + V_161 + V_158 ;
} else {
V_158 = ( 8354L * ( 31L + 10L * F_73 ( V_157 ) ) ) / 1000L ;
return 9107L + V_161 + V_158 ;
}
case V_163 :
if ( V_156 )
V_158 = F_74 ( V_157 ) ;
else
V_158 = F_75 ( V_157 ) ;
return V_158 ;
default:
F_76 ( L_15 , V_137 ) ;
return - 1 ;
}
}
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_111 = 0 ;
F_77 ( & V_164 ) ;
if ( F_23 ( F_78 ( & V_22 -> V_165 ) ) ) {
V_111 = - V_166 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_109 -> V_167 ) ) {
V_111 = - V_168 ;
goto V_108;
}
if ( F_23 ( ! V_22 -> V_50 -> V_169 ) ) {
V_111 = - V_170 ;
goto V_108;
}
if ( F_79 ( V_12 ) ) {
V_22 -> V_171 = 0 ;
F_80 ( & V_22 -> V_172 , & V_22 -> V_109 -> V_172 ) ;
} else {
V_111 = - V_173 ;
goto V_108;
}
V_108:
F_81 ( & V_164 ) ;
return V_111 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_174 * V_158 ;
F_82 (tmp, &urb->ep->urb_list) {
if ( V_158 == & V_22 -> V_172 )
break;
}
if ( V_158 != & V_22 -> V_172 )
return - V_175 ;
if ( V_22 -> V_171 )
return - V_176 ;
V_22 -> V_171 = V_31 ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_77 ( & V_164 ) ;
F_83 ( & V_22 -> V_172 ) ;
F_81 ( & V_164 ) ;
}
static int F_84 ( struct V_116 * V_117 ,
T_5 V_177 , T_6 * V_178 ,
void * * V_179 , T_4 V_120 ,
enum V_180 V_181 )
{
unsigned char * V_182 ;
if ( * V_179 == NULL ) {
F_85 ( 1 ) ;
return - V_183 ;
}
V_182 = F_86 ( V_117 , V_120 + sizeof( V_182 ) ,
V_177 , V_178 ) ;
if ( ! V_182 )
return - V_45 ;
F_87 ( ( unsigned long ) * V_179 ,
( unsigned long * ) ( V_182 + V_120 ) ) ;
if ( V_181 == V_184 )
memcpy ( V_182 , * V_179 , V_120 ) ;
* V_179 = V_182 ;
return 0 ;
}
static void F_88 ( struct V_116 * V_117 , T_6 * V_178 ,
void * * V_179 , T_4 V_120 ,
enum V_180 V_181 )
{
unsigned char * V_182 = * V_179 ;
V_182 = ( void * ) F_89 ( ( unsigned long * ) ( V_182 + V_120 ) ) ;
if ( V_181 == V_185 )
memcpy ( V_182 , * V_179 , V_120 ) ;
F_90 ( V_117 , V_120 + sizeof( V_182 ) , * V_179 , * V_178 ) ;
* V_179 = V_182 ;
* V_178 = 0 ;
}
void F_91 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_186 & V_187 )
F_92 ( V_12 -> V_15 . V_79 ,
V_22 -> V_188 ,
sizeof( struct V_23 ) ,
V_184 ) ;
else if ( V_22 -> V_186 & V_189 )
F_88 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_188 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_184 ) ;
V_22 -> V_186 &= ~ ( V_187 | V_189 ) ;
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
enum V_180 V_181 ;
F_91 ( V_12 , V_22 ) ;
V_181 = F_95 ( V_22 ) ? V_185 : V_184 ;
if ( V_22 -> V_186 & V_190 )
F_96 ( V_12 -> V_15 . V_79 ,
V_22 -> V_191 ,
V_22 -> V_192 ,
V_181 ) ;
else if ( V_22 -> V_186 & V_193 )
F_97 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ,
V_22 -> V_42 ,
V_181 ) ;
else if ( V_22 -> V_186 & V_195 )
F_92 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ,
V_22 -> V_42 ,
V_181 ) ;
else if ( V_22 -> V_186 & V_196 )
F_88 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_194 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_181 ) ;
V_22 -> V_186 &= ~ ( V_190 | V_193 |
V_195 | V_196 ) ;
}
static int F_98 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_177 )
{
if ( V_12 -> V_20 -> F_98 )
return V_12 -> V_20 -> F_98 ( V_12 , V_22 , V_177 ) ;
else
return F_99 ( V_12 , V_22 , V_177 ) ;
}
int F_99 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_177 )
{
enum V_180 V_181 ;
int V_197 = 0 ;
if ( F_35 ( & V_22 -> V_109 -> V_110 ) ) {
if ( V_12 -> V_15 . V_198 )
return V_197 ;
if ( V_12 -> V_15 . V_199 ) {
V_22 -> V_188 = F_100 (
V_12 -> V_15 . V_79 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_184 ) ;
if ( F_101 ( V_12 -> V_15 . V_79 ,
V_22 -> V_188 ) )
return - V_200 ;
V_22 -> V_186 |= V_187 ;
} else if ( V_12 -> V_20 -> V_94 & V_201 ) {
V_197 = F_84 (
V_22 -> V_50 -> V_117 , V_177 ,
& V_22 -> V_188 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_184 ) ;
if ( V_197 )
return V_197 ;
V_22 -> V_186 |= V_189 ;
}
}
V_181 = F_95 ( V_22 ) ? V_185 : V_184 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_186 & V_202 ) ) {
if ( V_12 -> V_15 . V_199 ) {
if ( V_22 -> V_192 ) {
int V_7 ;
if ( F_102 ( & V_22 -> V_109 -> V_110 ) ) {
F_103 ( 1 ) ;
return - V_107 ;
}
V_7 = F_104 (
V_12 -> V_15 . V_79 ,
V_22 -> V_191 ,
V_22 -> V_192 ,
V_181 ) ;
if ( V_7 <= 0 )
V_197 = - V_200 ;
else
V_22 -> V_186 |= V_190 ;
V_22 -> V_203 = V_7 ;
if ( V_7 != V_22 -> V_192 )
V_22 -> V_186 |=
V_204 ;
} else if ( V_22 -> V_191 ) {
struct V_205 * V_191 = V_22 -> V_191 ;
V_22 -> V_194 = F_105 (
V_12 -> V_15 . V_79 ,
F_106 ( V_191 ) ,
V_191 -> V_206 ,
V_22 -> V_42 ,
V_181 ) ;
if ( F_101 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ) )
V_197 = - V_200 ;
else
V_22 -> V_186 |= V_193 ;
} else if ( F_107 ( V_22 -> V_30 ) ) {
F_108 ( 1 , L_16 ) ;
V_197 = - V_200 ;
} else {
V_22 -> V_194 = F_100 (
V_12 -> V_15 . V_79 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_181 ) ;
if ( F_101 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ) )
V_197 = - V_200 ;
else
V_22 -> V_186 |= V_195 ;
}
} else if ( V_12 -> V_20 -> V_94 & V_201 ) {
V_197 = F_84 (
V_22 -> V_50 -> V_117 , V_177 ,
& V_22 -> V_194 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_181 ) ;
if ( V_197 == 0 )
V_22 -> V_186 |= V_196 ;
}
if ( V_197 && ( V_22 -> V_186 & ( V_187 |
V_189 ) ) )
F_94 ( V_12 , V_22 ) ;
}
return V_197 ;
}
int F_109 ( struct V_22 * V_22 , T_5 V_177 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
F_110 ( V_22 ) ;
F_111 ( & V_22 -> V_207 ) ;
F_111 ( & V_22 -> V_50 -> V_208 ) ;
F_112 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_50 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_98 ( V_12 , V_22 , V_177 ) ;
if ( F_113 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_209 ( V_12 , V_22 , V_177 ) ;
if ( F_23 ( V_31 ) )
F_93 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_114 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_46 ( & V_22 -> V_172 ) ;
F_115 ( & V_22 -> V_207 ) ;
F_115 ( & V_22 -> V_50 -> V_208 ) ;
if ( F_78 ( & V_22 -> V_165 ) )
F_116 ( & V_210 ) ;
F_117 ( V_22 ) ;
}
return V_31 ;
}
static int F_118 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_211 ;
if ( F_1 ( V_22 -> V_50 ) )
V_211 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_211 = V_12 -> V_20 -> V_212 ( V_12 , V_22 , V_31 ) ;
}
return V_211 ;
}
int F_119 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
int V_105 = - V_175 ;
unsigned long V_94 ;
F_24 ( & V_213 , V_94 ) ;
if ( F_78 ( & V_22 -> V_207 ) > 0 ) {
V_105 = 0 ;
F_120 ( V_22 -> V_50 ) ;
}
F_27 ( & V_213 , V_94 ) ;
if ( V_105 == 0 ) {
V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
V_105 = F_118 ( V_12 , V_22 , V_31 ) ;
F_121 ( V_22 -> V_50 ) ;
}
if ( V_105 == 0 )
V_105 = - V_214 ;
else if ( V_105 != - V_175 && V_105 != - V_176 )
F_16 ( & V_22 -> V_50 -> V_50 , L_17 ,
V_22 , V_105 ) ;
return V_105 ;
}
static void F_122 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
struct V_215 * V_216 = V_22 -> V_216 ;
int V_31 = V_22 -> V_171 ;
unsigned long V_94 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_186 & V_217 ) &&
V_22 -> V_46 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_218 ;
F_93 ( V_12 , V_22 ) ;
F_123 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_124 ( V_216 ) ;
F_125 ( V_22 ) ;
if ( F_113 ( V_31 == 0 ) )
F_126 ( V_219 ) ;
V_22 -> V_31 = V_31 ;
F_127 ( V_94 ) ;
V_22 -> V_220 ( V_22 ) ;
F_128 ( V_94 ) ;
F_129 ( V_216 ) ;
F_115 ( & V_22 -> V_207 ) ;
if ( F_23 ( F_78 ( & V_22 -> V_165 ) ) )
F_116 ( & V_210 ) ;
F_117 ( V_22 ) ;
}
static void F_130 ( unsigned long V_221 )
{
struct V_222 * V_223 = (struct V_222 * ) V_221 ;
struct V_174 V_224 ;
F_7 ( & V_223 -> V_225 ) ;
V_223 -> V_226 = true ;
V_227:
F_131 ( & V_223 -> V_228 , & V_224 ) ;
F_9 ( & V_223 -> V_225 ) ;
while ( ! F_132 ( & V_224 ) ) {
struct V_22 * V_22 ;
V_22 = F_133 ( V_224 . V_229 , struct V_22 , V_172 ) ;
F_83 ( & V_22 -> V_172 ) ;
V_223 -> V_230 = V_22 -> V_109 ;
F_122 ( V_22 ) ;
V_223 -> V_230 = NULL ;
}
F_7 ( & V_223 -> V_225 ) ;
if ( ! F_132 ( & V_223 -> V_228 ) )
goto V_227;
V_223 -> V_226 = false ;
F_9 ( & V_223 -> V_225 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_222 * V_223 ;
bool V_226 , V_231 ;
if ( F_113 ( ! V_22 -> V_171 ) )
V_22 -> V_171 = V_31 ;
if ( ! F_134 ( V_12 ) && ! F_1 ( V_22 -> V_50 ) ) {
F_122 ( V_22 ) ;
return;
}
if ( F_135 ( V_22 -> V_232 ) || F_136 ( V_22 -> V_232 ) ) {
V_223 = & V_12 -> V_231 ;
V_231 = true ;
} else {
V_223 = & V_12 -> V_233 ;
V_231 = false ;
}
F_77 ( & V_223 -> V_225 ) ;
F_80 ( & V_22 -> V_172 , & V_223 -> V_228 ) ;
V_226 = V_223 -> V_226 ;
F_81 ( & V_223 -> V_225 ) ;
if ( V_226 )
;
else if ( V_231 )
F_137 ( & V_223 -> V_223 ) ;
else
F_138 ( & V_223 -> V_223 ) ;
}
void F_139 ( struct V_1 * V_2 ,
struct V_234 * V_109 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_109 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
F_7 ( & V_164 ) ;
V_235:
F_140 (urb, &ep->urb_list, urb_list) {
int V_236 ;
if ( V_22 -> V_171 )
continue;
F_110 ( V_22 ) ;
V_236 = F_95 ( V_22 ) ;
F_81 ( & V_164 ) ;
F_118 ( V_12 , V_22 , - V_173 ) ;
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
F_117 ( V_22 ) ;
F_77 ( & V_164 ) ;
goto V_235;
}
F_9 ( & V_164 ) ;
while ( ! F_132 ( & V_109 -> V_172 ) ) {
F_7 ( & V_164 ) ;
V_22 = NULL ;
if ( ! F_132 ( & V_109 -> V_172 ) ) {
V_22 = F_133 ( V_109 -> V_172 . V_237 , struct V_22 ,
V_172 ) ;
F_110 ( V_22 ) ;
}
F_9 ( & V_164 ) ;
if ( V_22 ) {
F_141 ( V_22 ) ;
F_117 ( V_22 ) ;
}
}
}
int F_142 ( struct V_1 * V_2 ,
struct V_238 * V_239 ,
struct V_240 * V_241 ,
struct V_240 * V_242 )
{
int V_243 , V_244 , V_245 ;
struct V_240 * V_246 = NULL ;
int V_197 = 0 ;
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
V_197 = V_12 -> V_20 -> V_249 ( V_12 , V_2 , V_109 ) ;
if ( V_197 < 0 )
goto V_252;
}
V_109 = V_2 -> V_250 [ V_244 ] ;
if ( V_109 ) {
V_197 = V_12 -> V_20 -> V_249 ( V_12 , V_2 , V_109 ) ;
if ( V_197 < 0 )
goto V_252;
}
}
for ( V_244 = 0 ; V_244 < V_243 ; ++ V_244 ) {
struct V_240 * V_253 ;
int V_254 ;
V_253 = & V_239 -> V_255 [ V_244 ] -> V_256 [ 0 ] ;
V_254 = V_253 -> V_110 . V_257 ;
V_246 = F_143 ( V_239 , V_254 , 0 ) ;
if ( ! V_246 )
V_246 = V_253 ;
for ( V_245 = 0 ; V_245 < V_246 -> V_110 . V_258 ; V_245 ++ ) {
V_197 = V_12 -> V_20 -> V_259 ( V_12 , V_2 , & V_246 -> V_260 [ V_245 ] ) ;
if ( V_197 < 0 )
goto V_252;
}
}
}
if ( V_241 && V_242 ) {
struct V_261 * V_262 = F_144 ( V_2 ,
V_241 -> V_110 . V_257 ) ;
if ( ! V_262 )
return - V_107 ;
if ( V_262 -> V_263 ) {
V_241 = F_145 ( V_262 , 0 ) ;
if ( ! V_241 )
V_241 = & V_262 -> V_256 [ 0 ] ;
}
for ( V_244 = 0 ; V_244 < V_241 -> V_110 . V_258 ; V_244 ++ ) {
V_197 = V_12 -> V_20 -> V_249 ( V_12 , V_2 ,
& V_241 -> V_260 [ V_244 ] ) ;
if ( V_197 < 0 )
goto V_252;
}
for ( V_244 = 0 ; V_244 < V_242 -> V_110 . V_258 ; V_244 ++ ) {
V_197 = V_12 -> V_20 -> V_259 ( V_12 , V_2 ,
& V_242 -> V_260 [ V_244 ] ) ;
if ( V_197 < 0 )
goto V_252;
}
}
V_197 = V_12 -> V_20 -> V_247 ( V_12 , V_2 ) ;
V_252:
if ( V_197 < 0 )
V_12 -> V_20 -> V_264 ( V_12 , V_2 ) ;
return V_197 ;
}
void F_146 ( struct V_1 * V_2 ,
struct V_234 * V_109 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_265 )
V_12 -> V_20 -> V_265 ( V_12 , V_109 ) ;
}
void F_147 ( struct V_1 * V_2 ,
struct V_234 * V_109 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_266 )
V_12 -> V_20 -> V_266 ( V_12 , V_109 ) ;
else {
int V_267 = F_38 ( & V_109 -> V_110 ) ;
int V_268 = F_148 ( & V_109 -> V_110 ) ;
int V_269 = F_35 ( & V_109 -> V_110 ) ;
F_149 ( V_2 , V_267 , V_268 , 0 ) ;
if ( V_269 )
F_149 ( V_2 , V_267 , ! V_268 , 0 ) ;
}
}
int F_150 ( struct V_261 * V_270 ,
struct V_234 * * V_271 , unsigned int V_272 ,
unsigned int V_273 , T_5 V_177 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_244 , V_197 ;
V_50 = F_151 ( V_270 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_274 || ! V_12 -> V_20 -> V_275 )
return - V_107 ;
if ( V_50 -> V_60 != V_150 )
return - V_107 ;
if ( V_50 -> V_276 < V_277 )
return - V_278 ;
for ( V_244 = 0 ; V_244 < V_272 ; V_244 ++ ) {
if ( ! F_152 ( & V_271 [ V_244 ] -> V_110 ) )
return - V_107 ;
if ( V_271 [ V_244 ] -> V_279 )
return - V_107 ;
}
V_197 = V_12 -> V_20 -> V_274 ( V_12 , V_50 , V_271 , V_272 ,
V_273 , V_177 ) ;
if ( V_197 < 0 )
return V_197 ;
for ( V_244 = 0 ; V_244 < V_272 ; V_244 ++ )
V_271 [ V_244 ] -> V_279 = V_197 ;
return V_197 ;
}
int F_153 ( struct V_261 * V_270 ,
struct V_234 * * V_271 , unsigned int V_272 ,
T_5 V_177 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_244 , V_197 ;
V_50 = F_151 ( V_270 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( V_50 -> V_60 != V_150 )
return - V_107 ;
for ( V_244 = 0 ; V_244 < V_272 ; V_244 ++ )
if ( ! V_271 [ V_244 ] || ! V_271 [ V_244 ] -> V_279 )
return - V_107 ;
V_197 = V_12 -> V_20 -> V_275 ( V_12 , V_50 , V_271 , V_272 , V_177 ) ;
if ( V_197 < 0 )
return V_197 ;
for ( V_244 = 0 ; V_244 < V_272 ; V_244 ++ )
V_271 [ V_244 ] -> V_279 = 0 ;
return V_197 ;
}
void F_154 ( struct V_1 * V_2 )
{
F_7 ( & V_213 ) ;
F_9 ( & V_213 ) ;
}
int F_155 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! F_79 ( V_12 ) )
return - V_173 ;
return V_12 -> V_20 -> V_280 ( V_12 ) ;
}
int F_156 ( struct V_1 * V_281 , T_7 V_282 )
{
struct V_11 * V_12 = F_157 ( V_281 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_283 = V_12 -> V_276 ;
F_16 ( & V_281 -> V_50 , L_25 ,
( F_158 ( V_282 ) ? L_26 : L_21 ) ,
V_281 -> V_284 ) ;
if ( F_66 ( V_12 ) ) {
F_16 ( & V_281 -> V_50 , L_27 , L_28 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_285 ) {
V_31 = - V_168 ;
} else {
F_25 ( V_286 , & V_12 -> V_94 ) ;
V_12 -> V_276 = V_287 ;
V_31 = V_12 -> V_20 -> V_285 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_59 ( V_281 , V_288 ) ;
V_12 -> V_276 = V_289 ;
if ( V_281 -> V_284 ) {
char V_95 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_99 ( V_12 , V_95 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_281 -> V_50 , L_29 ) ;
F_159 ( V_281 , V_290 ) ;
V_31 = - V_176 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_66 ( V_12 ) ) {
F_26 ( V_286 , & V_12 -> V_94 ) ;
V_12 -> V_276 = V_283 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_281 -> V_50 , L_30 ,
L_28 , V_31 ) ;
}
return V_31 ;
}
int F_159 ( struct V_1 * V_281 , T_7 V_282 )
{
struct V_11 * V_12 = F_157 ( V_281 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_283 = V_12 -> V_276 ;
F_16 ( & V_281 -> V_50 , L_31 ,
( F_158 ( V_282 ) ? L_26 : L_21 ) ) ;
if ( F_66 ( V_12 ) ) {
F_16 ( & V_281 -> V_50 , L_27 , L_32 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_291 )
return - V_168 ;
if ( F_79 ( V_12 ) )
return 0 ;
V_12 -> V_276 = V_292 ;
V_31 = V_12 -> V_20 -> V_291 ( V_12 ) ;
F_25 ( V_293 , & V_12 -> V_94 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_294 ;
F_7 ( & V_37 ) ;
if ( ! F_66 ( V_12 ) ) {
F_59 ( V_281 , V_281 -> V_295
? V_277
: V_144 ) ;
F_26 ( V_286 , & V_12 -> V_94 ) ;
V_12 -> V_276 = V_296 ;
}
F_9 ( & V_37 ) ;
F_160 (rhdev, port1, udev) {
if ( V_2 -> V_276 != V_297 &&
! V_2 -> V_298 ) {
F_161 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_276 = V_283 ;
F_16 ( & V_281 -> V_50 , L_30 ,
L_32 , V_31 ) ;
if ( V_31 != - V_173 )
F_67 ( V_12 ) ;
}
return V_31 ;
}
static void F_162 ( struct V_299 * V_300 )
{
struct V_11 * V_12 = F_157 ( V_300 , struct V_11 , V_301 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_49 ;
F_163 ( V_2 ) ;
}
void F_164 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_24 ( & V_37 , V_94 ) ;
if ( V_12 -> V_151 ) {
F_26 ( V_293 , & V_12 -> V_94 ) ;
F_165 ( V_302 , & V_12 -> V_301 ) ;
}
F_27 ( & V_37 , V_94 ) ;
}
int F_166 ( struct V_116 * V_117 , unsigned V_303 )
{
struct V_11 * V_12 ;
int V_31 = - V_304 ;
V_12 = F_157 ( V_117 , struct V_11 , V_15 ) ;
if ( V_303 && V_12 -> V_20 -> V_305 )
V_31 = V_12 -> V_20 -> V_305 ( V_12 , V_303 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_101 , V_102 + F_167 ( 10 ) ) ;
return V_31 ;
}
T_8 F_168 ( int V_306 , void * V_307 )
{
struct V_11 * V_12 = V_307 ;
T_8 V_111 ;
if ( F_23 ( F_66 ( V_12 ) || ! F_169 ( V_12 ) ) )
V_111 = V_308 ;
else if ( V_12 -> V_20 -> V_306 ( V_12 ) == V_308 )
V_111 = V_308 ;
else
V_111 = V_309 ;
return V_111 ;
}
void F_67 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_65 ( V_12 -> V_15 . V_79 , L_33 ) ;
F_24 ( & V_37 , V_94 ) ;
F_25 ( V_286 , & V_12 -> V_94 ) ;
F_26 ( V_310 , & V_12 -> V_94 ) ;
if ( V_12 -> V_151 ) {
F_25 ( V_311 , & V_12 -> V_94 ) ;
F_59 ( V_12 -> V_15 . V_49 ,
V_297 ) ;
F_170 ( V_12 -> V_15 . V_49 ) ;
}
if ( F_171 ( V_12 ) && V_12 -> V_312 ) {
V_12 = V_12 -> V_312 ;
if ( V_12 -> V_151 ) {
F_25 ( V_311 , & V_12 -> V_94 ) ;
F_59 ( V_12 -> V_15 . V_49 ,
V_297 ) ;
F_170 ( V_12 -> V_15 . V_49 ) ;
}
}
F_27 ( & V_37 , V_94 ) ;
}
static void F_172 ( struct V_222 * V_223 )
{
F_173 ( & V_223 -> V_225 ) ;
F_46 ( & V_223 -> V_228 ) ;
F_174 ( & V_223 -> V_223 , F_130 , ( unsigned long ) V_223 ) ;
}
struct V_11 * F_175 ( const struct V_313 * V_20 ,
struct V_112 * V_50 , const char * V_16 ,
struct V_11 * V_314 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_315 , V_44 ) ;
if ( ! V_12 ) {
F_16 ( V_50 , L_34 ) ;
return NULL ;
}
if ( V_314 == NULL ) {
V_12 -> V_316 = F_176 ( sizeof( * V_12 -> V_316 ) ,
V_44 ) ;
if ( ! V_12 -> V_316 ) {
F_19 ( V_12 ) ;
F_16 ( V_50 , L_35 ) ;
return NULL ;
}
F_45 ( V_12 -> V_316 ) ;
F_177 ( V_50 , V_12 ) ;
} else {
F_48 ( & V_317 ) ;
V_12 -> V_316 = V_314 -> V_316 ;
V_12 -> V_314 = V_314 ;
V_314 -> V_314 = V_314 ;
V_12 -> V_312 = V_314 ;
V_314 -> V_312 = V_12 ;
F_52 ( & V_317 ) ;
}
F_178 ( & V_12 -> V_318 ) ;
F_44 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_79 = V_50 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_199 = ( V_50 -> V_319 != NULL ) ;
F_179 ( & V_12 -> V_101 ) ;
V_12 -> V_101 . V_320 = F_30 ;
V_12 -> V_101 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_180
F_181 ( & V_12 -> V_301 , F_162 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_60 = V_20 -> V_94 & V_321 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_36 ;
return V_12 ;
}
struct V_11 * F_182 ( const struct V_313 * V_20 ,
struct V_112 * V_50 , const char * V_16 )
{
return F_175 ( V_20 , V_50 , V_16 , NULL ) ;
}
static void F_183 ( struct V_318 * V_318 )
{
struct V_11 * V_12 = F_157 ( V_318 , struct V_11 , V_318 ) ;
F_48 ( & V_317 ) ;
if ( F_171 ( V_12 ) )
F_19 ( V_12 -> V_316 ) ;
if ( V_12 -> V_312 ) {
struct V_11 * V_322 = V_12 -> V_312 ;
V_322 -> V_312 = NULL ;
if ( V_322 -> V_314 == V_12 )
V_322 -> V_314 = NULL ;
}
F_52 ( & V_317 ) ;
F_19 ( V_12 ) ;
}
struct V_11 * F_184 ( struct V_11 * V_12 )
{
if ( V_12 )
F_185 ( & V_12 -> V_318 ) ;
return V_12 ;
}
void F_186 ( struct V_11 * V_12 )
{
if ( V_12 )
F_187 ( & V_12 -> V_318 , F_183 ) ;
}
int F_171 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_314 )
return 1 ;
return V_12 == V_12 -> V_314 ;
}
int F_188 ( struct V_11 * V_12 , int V_294 )
{
if ( ! V_12 -> V_20 -> V_323 )
return V_294 ;
return V_12 -> V_20 -> V_323 ( V_12 , V_294 ) ;
}
static int F_189 ( struct V_11 * V_12 ,
unsigned int V_324 , unsigned long V_325 )
{
int V_105 ;
if ( V_12 -> V_20 -> V_306 ) {
snprintf ( V_12 -> V_326 , sizeof( V_12 -> V_326 ) , L_37 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_126 ) ;
V_105 = F_190 ( V_324 , & F_168 , V_325 ,
V_12 -> V_326 , V_12 ) ;
if ( V_105 != 0 ) {
F_65 ( V_12 -> V_15 . V_79 ,
L_38 ,
V_324 ) ;
return V_105 ;
}
V_12 -> V_306 = V_324 ;
F_54 ( V_12 -> V_15 . V_79 , L_39 , V_324 ,
( V_12 -> V_20 -> V_94 & V_327 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_328 ) ;
} else {
V_12 -> V_306 = 0 ;
if ( V_12 -> V_328 )
F_54 ( V_12 -> V_15 . V_79 , L_42 ,
( V_12 -> V_20 -> V_94 & V_327 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_328 ) ;
}
return 0 ;
}
static void F_191 ( struct V_11 * V_12 )
{
struct V_1 * V_281 ;
F_48 ( & V_317 ) ;
V_281 = V_12 -> V_15 . V_49 ;
V_12 -> V_15 . V_49 = NULL ;
F_52 ( & V_317 ) ;
F_121 ( V_281 ) ;
}
int F_192 ( struct V_11 * V_12 ,
unsigned int V_324 , unsigned long V_325 )
{
int V_105 ;
struct V_1 * V_281 ;
if ( F_193 ( V_329 ) && ! V_12 -> V_330 ) {
struct V_330 * V_331 = F_194 ( V_12 -> V_15 . V_79 , 0 ) ;
if ( F_195 ( V_331 ) ) {
V_105 = F_196 ( V_331 ) ;
if ( V_105 == - V_332 )
return V_105 ;
} else {
V_105 = F_197 ( V_331 ) ;
if ( V_105 ) {
F_198 ( V_331 ) ;
return V_105 ;
}
V_12 -> V_330 = V_331 ;
V_12 -> V_333 = 1 ;
}
}
if ( F_193 ( V_334 ) ) {
struct V_331 * V_331 = F_199 ( V_12 -> V_15 . V_79 , L_43 ) ;
if ( F_195 ( V_331 ) ) {
V_105 = F_196 ( V_331 ) ;
if ( V_105 == - V_332 )
goto V_335;
} else {
V_105 = F_200 ( V_331 ) ;
if ( V_105 ) {
F_201 ( V_331 ) ;
goto V_335;
}
V_105 = F_202 ( V_331 ) ;
if ( V_105 ) {
F_203 ( V_331 ) ;
F_201 ( V_331 ) ;
goto V_335;
}
V_12 -> V_331 = V_331 ;
}
}
F_54 ( V_12 -> V_15 . V_79 , L_44 , V_12 -> V_17 ) ;
if ( V_119 < 0 || V_119 > 1 )
V_12 -> V_119 = V_12 -> V_336 ? 0 : 1 ;
else
V_12 -> V_119 = V_119 ;
F_26 ( V_337 , & V_12 -> V_94 ) ;
if ( ( V_105 = F_204 ( V_12 ) ) != 0 ) {
F_16 ( V_12 -> V_15 . V_79 , L_45 ) ;
goto V_338;
}
if ( ( V_105 = F_47 ( & V_12 -> V_15 ) ) < 0 )
goto V_339;
if ( ( V_281 = F_205 ( NULL , & V_12 -> V_15 , 0 ) ) == NULL ) {
F_65 ( V_12 -> V_15 . V_79 , L_46 ) ;
V_105 = - V_45 ;
goto V_340;
}
F_48 ( & V_317 ) ;
V_12 -> V_15 . V_49 = V_281 ;
F_52 ( & V_317 ) ;
switch ( V_12 -> V_60 ) {
case V_67 :
V_281 -> V_60 = V_162 ;
break;
case V_65 :
V_281 -> V_60 = V_163 ;
break;
case V_63 :
V_281 -> V_60 = V_341 ;
break;
case V_61 :
V_281 -> V_60 = V_150 ;
break;
default:
V_105 = - V_107 ;
goto V_342;
}
F_206 ( & V_281 -> V_50 , 1 ) ;
F_26 ( V_286 , & V_12 -> V_94 ) ;
if ( V_12 -> V_20 -> V_252 && ( V_105 = V_12 -> V_20 -> V_252 ( V_12 ) ) < 0 ) {
F_65 ( V_12 -> V_15 . V_79 , L_47 , V_105 ) ;
goto V_343;
}
V_12 -> V_96 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_79 )
&& F_15 ( & V_12 -> V_15 . V_49 -> V_50 ) )
F_16 ( V_12 -> V_15 . V_79 , L_48 ) ;
F_172 ( & V_12 -> V_231 ) ;
F_172 ( & V_12 -> V_233 ) ;
if ( F_171 ( V_12 ) && V_324 ) {
V_105 = F_189 ( V_12 , V_324 , V_325 ) ;
if ( V_105 )
goto V_344;
}
V_12 -> V_276 = V_296 ;
V_105 = V_12 -> V_20 -> V_345 ( V_12 ) ;
if ( V_105 < 0 ) {
F_65 ( V_12 -> V_15 . V_79 , L_49 , V_105 ) ;
goto V_346;
}
if ( ( V_105 = F_58 ( V_12 ) ) != 0 )
goto V_347;
V_105 = F_207 ( & V_281 -> V_50 . V_348 , & V_349 ) ;
if ( V_105 < 0 ) {
F_50 ( V_136 L_50 ,
V_105 ) ;
goto V_350;
}
if ( V_12 -> V_97 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
return V_105 ;
V_350:
F_25 ( V_286 , & V_12 -> V_94 ) ;
if ( F_208 ( V_12 -> V_276 ) )
V_12 -> V_276 = V_287 ;
F_7 ( & V_37 ) ;
V_12 -> V_151 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_180
F_209 ( & V_12 -> V_301 ) ;
#endif
F_48 ( & V_133 ) ;
F_210 ( & V_281 ) ;
F_52 ( & V_133 ) ;
V_347:
V_12 -> V_96 = 0 ;
F_25 ( V_311 , & V_12 -> V_94 ) ;
F_211 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_351 ( V_12 ) ;
V_12 -> V_276 = V_352 ;
F_25 ( V_311 , & V_12 -> V_94 ) ;
F_211 ( & V_12 -> V_101 ) ;
V_346:
if ( F_171 ( V_12 ) && V_12 -> V_306 > 0 )
F_212 ( V_324 , V_12 ) ;
V_344:
V_343:
V_342:
F_191 ( V_12 ) ;
V_340:
F_55 ( & V_12 -> V_15 ) ;
V_339:
F_213 ( V_12 ) ;
V_338:
if ( F_193 ( V_334 ) && V_12 -> V_331 ) {
F_214 ( V_12 -> V_331 ) ;
F_203 ( V_12 -> V_331 ) ;
F_201 ( V_12 -> V_331 ) ;
V_12 -> V_331 = NULL ;
}
V_335:
if ( V_12 -> V_333 && V_12 -> V_330 ) {
F_215 ( V_12 -> V_330 ) ;
F_198 ( V_12 -> V_330 ) ;
V_12 -> V_330 = NULL ;
}
return V_105 ;
}
void F_216 ( struct V_11 * V_12 )
{
struct V_1 * V_281 = V_12 -> V_15 . V_49 ;
F_54 ( V_12 -> V_15 . V_79 , L_51 , V_12 -> V_276 ) ;
F_120 ( V_281 ) ;
F_217 ( & V_281 -> V_50 . V_348 , & V_349 ) ;
F_25 ( V_286 , & V_12 -> V_94 ) ;
if ( F_208 ( V_12 -> V_276 ) )
V_12 -> V_276 = V_287 ;
F_16 ( V_12 -> V_15 . V_79 , L_52 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_151 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_180
F_209 ( & V_12 -> V_301 ) ;
#endif
F_48 ( & V_133 ) ;
F_210 ( & V_281 ) ;
F_52 ( & V_133 ) ;
V_12 -> V_96 = 0 ;
F_25 ( V_311 , & V_12 -> V_94 ) ;
F_211 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_351 ( V_12 ) ;
V_12 -> V_276 = V_352 ;
F_25 ( V_311 , & V_12 -> V_94 ) ;
F_211 ( & V_12 -> V_101 ) ;
if ( F_171 ( V_12 ) ) {
if ( V_12 -> V_306 > 0 )
F_212 ( V_12 -> V_306 , V_12 ) ;
}
F_55 ( & V_12 -> V_15 ) ;
F_213 ( V_12 ) ;
if ( F_193 ( V_334 ) && V_12 -> V_331 ) {
F_214 ( V_12 -> V_331 ) ;
F_203 ( V_12 -> V_331 ) ;
F_201 ( V_12 -> V_331 ) ;
V_12 -> V_331 = NULL ;
}
if ( V_12 -> V_333 && V_12 -> V_330 ) {
F_215 ( V_12 -> V_330 ) ;
F_198 ( V_12 -> V_330 ) ;
V_12 -> V_330 = NULL ;
}
F_191 ( V_12 ) ;
}
void
F_218 ( struct V_353 * V_50 )
{
struct V_11 * V_12 = F_219 ( V_50 ) ;
if ( V_12 -> V_20 -> V_354 )
V_12 -> V_20 -> V_354 ( V_12 ) ;
}
int F_220 ( struct V_355 * V_356 )
{
if ( V_357 )
return - V_176 ;
V_357 = V_356 ;
F_221 () ;
return 0 ;
}
void F_222 ( void )
{
if ( V_357 == NULL ) {
F_50 ( V_136 L_53 ) ;
return;
}
V_357 = NULL ;
F_221 () ;
}
