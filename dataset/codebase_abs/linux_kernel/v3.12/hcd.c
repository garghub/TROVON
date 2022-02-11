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
}
else
V_122 = - V_107 ;
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
F_25 ( V_117 -> V_127 , V_134 . V_134 ) ;
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
}
V_105 = F_63 ( V_141 ) ;
if ( V_105 ) {
F_64 ( V_140 , L_14 ,
F_61 ( & V_141 -> V_50 ) , V_105 ) ;
} else {
F_7 ( & V_37 ) ;
V_12 -> V_151 = 1 ;
F_9 ( & V_37 ) ;
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
F_68 ( & V_117 -> V_49 -> V_50 ) ;
}
}
void F_69 ( struct V_116 * V_117 , int V_152 )
{
unsigned V_153 = 1 << V_152 ;
if ( V_117 -> V_154 & V_153 ) {
V_117 -> V_154 &= ~ V_153 ;
F_70 ( & V_117 -> V_49 -> V_50 ) ;
}
}
long F_71 ( int V_60 , int V_155 , int V_156 , int V_157 )
{
unsigned long V_158 ;
switch ( V_60 ) {
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
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_111 = 0 ;
F_76 ( & V_164 ) ;
if ( F_23 ( F_77 ( & V_22 -> V_165 ) ) ) {
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
if ( F_78 ( V_12 ) ) {
V_22 -> V_171 = 0 ;
F_79 ( & V_22 -> V_172 , & V_22 -> V_109 -> V_172 ) ;
} else {
V_111 = - V_173 ;
goto V_108;
}
V_108:
F_80 ( & V_164 ) ;
return V_111 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_174 * V_158 ;
F_81 (tmp, &urb->ep->urb_list) {
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
F_76 ( & V_164 ) ;
F_82 ( & V_22 -> V_172 ) ;
F_80 ( & V_164 ) ;
}
static int F_83 ( struct V_116 * V_117 ,
T_5 V_177 , T_6 * V_178 ,
void * * V_179 , T_4 V_121 ,
enum V_180 V_181 )
{
unsigned char * V_182 ;
if ( * V_179 == NULL ) {
F_84 ( 1 ) ;
return - V_183 ;
}
V_182 = F_85 ( V_117 , V_121 + sizeof( V_182 ) ,
V_177 , V_178 ) ;
if ( ! V_182 )
return - V_45 ;
F_86 ( ( unsigned long ) * V_179 ,
( unsigned long * ) ( V_182 + V_121 ) ) ;
if ( V_181 == V_184 )
memcpy ( V_182 , * V_179 , V_121 ) ;
* V_179 = V_182 ;
return 0 ;
}
static void F_87 ( struct V_116 * V_117 , T_6 * V_178 ,
void * * V_179 , T_4 V_121 ,
enum V_180 V_181 )
{
unsigned char * V_182 = * V_179 ;
V_182 = ( void * ) F_88 ( ( unsigned long * ) ( V_182 + V_121 ) ) ;
if ( V_181 == V_185 )
memcpy ( V_182 , * V_179 , V_121 ) ;
F_89 ( V_117 , V_121 + sizeof( V_182 ) , * V_179 , * V_178 ) ;
* V_179 = V_182 ;
* V_178 = 0 ;
}
void F_90 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_186 & V_187 )
F_91 ( V_12 -> V_15 . V_79 ,
V_22 -> V_188 ,
sizeof( struct V_23 ) ,
V_184 ) ;
else if ( V_22 -> V_186 & V_189 )
F_87 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_188 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_184 ) ;
V_22 -> V_186 &= ~ ( V_187 | V_189 ) ;
}
static void F_92 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_92 )
V_12 -> V_20 -> F_92 ( V_12 , V_22 ) ;
else
F_93 ( V_12 , V_22 ) ;
}
void F_93 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_180 V_181 ;
F_90 ( V_12 , V_22 ) ;
V_181 = F_94 ( V_22 ) ? V_185 : V_184 ;
if ( V_22 -> V_186 & V_190 )
F_95 ( V_12 -> V_15 . V_79 ,
V_22 -> V_191 ,
V_22 -> V_192 ,
V_181 ) ;
else if ( V_22 -> V_186 & V_193 )
F_96 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ,
V_22 -> V_42 ,
V_181 ) ;
else if ( V_22 -> V_186 & V_195 )
F_91 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ,
V_22 -> V_42 ,
V_181 ) ;
else if ( V_22 -> V_186 & V_196 )
F_87 ( V_22 -> V_50 -> V_117 ,
& V_22 -> V_194 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_181 ) ;
V_22 -> V_186 &= ~ ( V_190 | V_193 |
V_195 | V_196 ) ;
}
static int F_97 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_177 )
{
if ( V_12 -> V_20 -> F_97 )
return V_12 -> V_20 -> F_97 ( V_12 , V_22 , V_177 ) ;
else
return F_98 ( V_12 , V_22 , V_177 ) ;
}
int F_98 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_177 )
{
enum V_180 V_181 ;
int V_197 = 0 ;
if ( F_35 ( & V_22 -> V_109 -> V_110 ) ) {
if ( V_12 -> V_15 . V_198 )
return V_197 ;
if ( V_12 -> V_15 . V_199 ) {
V_22 -> V_188 = F_99 (
V_12 -> V_15 . V_79 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_184 ) ;
if ( F_100 ( V_12 -> V_15 . V_79 ,
V_22 -> V_188 ) )
return - V_200 ;
V_22 -> V_186 |= V_187 ;
} else if ( V_12 -> V_20 -> V_94 & V_201 ) {
V_197 = F_83 (
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
V_181 = F_94 ( V_22 ) ? V_185 : V_184 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_186 & V_202 ) ) {
if ( V_12 -> V_15 . V_199 ) {
if ( V_22 -> V_192 ) {
int V_7 ;
if ( F_101 ( & V_22 -> V_109 -> V_110 ) ) {
F_102 ( 1 ) ;
return - V_107 ;
}
V_7 = F_103 (
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
V_22 -> V_194 = F_104 (
V_12 -> V_15 . V_79 ,
F_105 ( V_191 ) ,
V_191 -> V_206 ,
V_22 -> V_42 ,
V_181 ) ;
if ( F_100 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ) )
V_197 = - V_200 ;
else
V_22 -> V_186 |= V_193 ;
} else {
V_22 -> V_194 = F_99 (
V_12 -> V_15 . V_79 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_181 ) ;
if ( F_100 ( V_12 -> V_15 . V_79 ,
V_22 -> V_194 ) )
V_197 = - V_200 ;
else
V_22 -> V_186 |= V_195 ;
}
} else if ( V_12 -> V_20 -> V_94 & V_201 ) {
V_197 = F_83 (
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
F_93 ( V_12 , V_22 ) ;
}
return V_197 ;
}
int F_106 ( struct V_22 * V_22 , T_5 V_177 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
F_107 ( V_22 ) ;
F_108 ( & V_22 -> V_207 ) ;
F_108 ( & V_22 -> V_50 -> V_208 ) ;
F_109 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_50 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_97 ( V_12 , V_22 , V_177 ) ;
if ( F_110 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_209 ( V_12 , V_22 , V_177 ) ;
if ( F_23 ( V_31 ) )
F_92 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_111 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_45 ( & V_22 -> V_172 ) ;
F_112 ( & V_22 -> V_207 ) ;
F_112 ( & V_22 -> V_50 -> V_208 ) ;
if ( F_77 ( & V_22 -> V_165 ) )
F_113 ( & V_210 ) ;
F_114 ( V_22 ) ;
}
return V_31 ;
}
static int F_115 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_211 ;
if ( F_1 ( V_22 -> V_50 ) )
V_211 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_211 = V_12 -> V_20 -> V_212 ( V_12 , V_22 , V_31 ) ;
}
return V_211 ;
}
int F_116 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
int V_105 = - V_175 ;
unsigned long V_94 ;
F_24 ( & V_213 , V_94 ) ;
if ( F_77 ( & V_22 -> V_207 ) > 0 ) {
V_105 = 0 ;
F_117 ( V_22 -> V_50 ) ;
}
F_27 ( & V_213 , V_94 ) ;
if ( V_105 == 0 ) {
V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
V_105 = F_115 ( V_12 , V_22 , V_31 ) ;
F_118 ( V_22 -> V_50 ) ;
}
if ( V_105 == 0 )
V_105 = - V_214 ;
else if ( V_105 != - V_175 && V_105 != - V_176 )
F_16 ( & V_22 -> V_50 -> V_50 , L_16 ,
V_22 , V_105 ) ;
return V_105 ;
}
static void F_119 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_117 ) ;
int V_31 = V_22 -> V_171 ;
unsigned long V_94 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_186 & V_215 ) &&
V_22 -> V_46 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_216 ;
F_92 ( V_12 , V_22 ) ;
F_120 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_121 ( V_22 ) ;
V_22 -> V_31 = V_31 ;
F_122 ( V_94 ) ;
V_22 -> V_217 ( V_22 ) ;
F_123 ( V_94 ) ;
F_112 ( & V_22 -> V_207 ) ;
if ( F_23 ( F_77 ( & V_22 -> V_165 ) ) )
F_113 ( & V_210 ) ;
F_114 ( V_22 ) ;
}
static void F_124 ( unsigned long V_218 )
{
struct V_219 * V_220 = (struct V_219 * ) V_218 ;
struct V_174 V_221 ;
F_7 ( & V_220 -> V_222 ) ;
V_220 -> V_223 = true ;
V_224:
F_125 ( & V_220 -> V_225 , & V_221 ) ;
F_9 ( & V_220 -> V_222 ) ;
while ( ! F_126 ( & V_221 ) ) {
struct V_22 * V_22 ;
V_22 = F_127 ( V_221 . V_226 , struct V_22 , V_172 ) ;
F_82 ( & V_22 -> V_172 ) ;
F_119 ( V_22 ) ;
}
F_7 ( & V_220 -> V_222 ) ;
if ( ! F_126 ( & V_220 -> V_225 ) )
goto V_224;
V_220 -> V_223 = false ;
F_9 ( & V_220 -> V_222 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_219 * V_220 ;
bool V_223 , V_227 ;
if ( F_110 ( ! V_22 -> V_171 ) )
V_22 -> V_171 = V_31 ;
if ( ! F_128 ( V_12 ) && ! F_1 ( V_22 -> V_50 ) ) {
F_119 ( V_22 ) ;
return;
}
if ( F_129 ( V_22 -> V_228 ) || F_130 ( V_22 -> V_228 ) ) {
V_220 = & V_12 -> V_227 ;
V_227 = true ;
} else {
V_220 = & V_12 -> V_229 ;
V_227 = false ;
}
F_76 ( & V_220 -> V_222 ) ;
F_79 ( & V_22 -> V_172 , & V_220 -> V_225 ) ;
V_223 = V_220 -> V_223 ;
F_80 ( & V_220 -> V_222 ) ;
if ( V_223 )
;
else if ( V_227 )
F_131 ( & V_220 -> V_220 ) ;
else
F_132 ( & V_220 -> V_220 ) ;
}
void F_133 ( struct V_1 * V_2 ,
struct V_230 * V_109 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_109 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
F_7 ( & V_164 ) ;
V_231:
F_134 (urb, &ep->urb_list, urb_list) {
int V_232 ;
if ( V_22 -> V_171 )
continue;
F_107 ( V_22 ) ;
V_232 = F_94 ( V_22 ) ;
F_80 ( & V_164 ) ;
F_115 ( V_12 , V_22 , - V_173 ) ;
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
F_114 ( V_22 ) ;
F_76 ( & V_164 ) ;
goto V_231;
}
F_9 ( & V_164 ) ;
while ( ! F_126 ( & V_109 -> V_172 ) ) {
F_7 ( & V_164 ) ;
V_22 = NULL ;
if ( ! F_126 ( & V_109 -> V_172 ) ) {
V_22 = F_127 ( V_109 -> V_172 . V_233 , struct V_22 ,
V_172 ) ;
F_107 ( V_22 ) ;
}
F_9 ( & V_164 ) ;
if ( V_22 ) {
F_135 ( V_22 ) ;
F_114 ( V_22 ) ;
}
}
}
int F_136 ( struct V_1 * V_2 ,
struct V_234 * V_235 ,
struct V_236 * V_237 ,
struct V_236 * V_238 )
{
int V_239 , V_240 , V_241 ;
struct V_236 * V_242 = NULL ;
int V_197 = 0 ;
struct V_11 * V_12 ;
struct V_230 * V_109 ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_243 )
return 0 ;
if ( ! V_235 && ! V_237 ) {
for ( V_240 = 1 ; V_240 < 16 ; ++ V_240 ) {
V_109 = V_2 -> V_244 [ V_240 ] ;
if ( V_109 )
V_12 -> V_20 -> V_245 ( V_12 , V_2 , V_109 ) ;
V_109 = V_2 -> V_246 [ V_240 ] ;
if ( V_109 )
V_12 -> V_20 -> V_245 ( V_12 , V_2 , V_109 ) ;
}
V_12 -> V_20 -> V_243 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_235 ) {
V_239 = V_235 -> V_110 . V_247 ;
for ( V_240 = 1 ; V_240 < 16 ; ++ V_240 ) {
V_109 = V_2 -> V_244 [ V_240 ] ;
if ( V_109 ) {
V_197 = V_12 -> V_20 -> V_245 ( V_12 , V_2 , V_109 ) ;
if ( V_197 < 0 )
goto V_248;
}
V_109 = V_2 -> V_246 [ V_240 ] ;
if ( V_109 ) {
V_197 = V_12 -> V_20 -> V_245 ( V_12 , V_2 , V_109 ) ;
if ( V_197 < 0 )
goto V_248;
}
}
for ( V_240 = 0 ; V_240 < V_239 ; ++ V_240 ) {
struct V_236 * V_249 ;
int V_250 ;
V_249 = & V_235 -> V_251 [ V_240 ] -> V_252 [ 0 ] ;
V_250 = V_249 -> V_110 . V_253 ;
V_242 = F_137 ( V_235 , V_250 , 0 ) ;
if ( ! V_242 )
V_242 = V_249 ;
for ( V_241 = 0 ; V_241 < V_242 -> V_110 . V_254 ; V_241 ++ ) {
V_197 = V_12 -> V_20 -> V_255 ( V_12 , V_2 , & V_242 -> V_256 [ V_241 ] ) ;
if ( V_197 < 0 )
goto V_248;
}
}
}
if ( V_237 && V_238 ) {
struct V_257 * V_258 = F_138 ( V_2 ,
V_237 -> V_110 . V_253 ) ;
if ( ! V_258 )
return - V_107 ;
if ( V_258 -> V_259 ) {
V_237 = F_139 ( V_258 , 0 ) ;
if ( ! V_237 )
V_237 = & V_258 -> V_252 [ 0 ] ;
}
for ( V_240 = 0 ; V_240 < V_237 -> V_110 . V_254 ; V_240 ++ ) {
V_197 = V_12 -> V_20 -> V_245 ( V_12 , V_2 ,
& V_237 -> V_256 [ V_240 ] ) ;
if ( V_197 < 0 )
goto V_248;
}
for ( V_240 = 0 ; V_240 < V_238 -> V_110 . V_254 ; V_240 ++ ) {
V_197 = V_12 -> V_20 -> V_255 ( V_12 , V_2 ,
& V_238 -> V_256 [ V_240 ] ) ;
if ( V_197 < 0 )
goto V_248;
}
}
V_197 = V_12 -> V_20 -> V_243 ( V_12 , V_2 ) ;
V_248:
if ( V_197 < 0 )
V_12 -> V_20 -> V_260 ( V_12 , V_2 ) ;
return V_197 ;
}
void F_140 ( struct V_1 * V_2 ,
struct V_230 * V_109 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_261 )
V_12 -> V_20 -> V_261 ( V_12 , V_109 ) ;
}
void F_141 ( struct V_1 * V_2 ,
struct V_230 * V_109 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( V_12 -> V_20 -> V_262 )
V_12 -> V_20 -> V_262 ( V_12 , V_109 ) ;
else {
int V_263 = F_38 ( & V_109 -> V_110 ) ;
int V_264 = F_142 ( & V_109 -> V_110 ) ;
int V_265 = F_35 ( & V_109 -> V_110 ) ;
F_143 ( V_2 , V_263 , V_264 , 0 ) ;
if ( V_265 )
F_143 ( V_2 , V_263 , ! V_264 , 0 ) ;
}
}
int F_144 ( struct V_257 * V_266 ,
struct V_230 * * V_267 , unsigned int V_268 ,
unsigned int V_269 , T_5 V_177 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_240 ;
V_50 = F_145 ( V_266 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( ! V_12 -> V_20 -> V_270 || ! V_12 -> V_20 -> V_271 )
return - V_107 ;
if ( V_50 -> V_60 != V_150 )
return - V_107 ;
for ( V_240 = 0 ; V_240 < V_268 ; V_240 ++ )
if ( ! F_146 ( & V_267 [ V_240 ] -> V_110 ) )
return - V_107 ;
return V_12 -> V_20 -> V_270 ( V_12 , V_50 , V_267 , V_268 ,
V_269 , V_177 ) ;
}
void F_147 ( struct V_257 * V_266 ,
struct V_230 * * V_267 , unsigned int V_268 ,
T_5 V_177 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_240 ;
V_50 = F_145 ( V_266 ) ;
V_12 = F_42 ( V_50 -> V_117 ) ;
if ( V_50 -> V_60 != V_150 )
return;
for ( V_240 = 0 ; V_240 < V_268 ; V_240 ++ )
if ( ! V_267 [ V_240 ] || ! F_146 ( & V_267 [ V_240 ] -> V_110 ) )
return;
V_12 -> V_20 -> V_271 ( V_12 , V_50 , V_267 , V_268 , V_177 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
F_7 ( & V_213 ) ;
F_9 ( & V_213 ) ;
}
int F_149 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_117 ) ;
if ( ! F_78 ( V_12 ) )
return - V_173 ;
return V_12 -> V_20 -> V_272 ( V_12 ) ;
}
int F_150 ( struct V_1 * V_273 , T_7 V_274 )
{
struct V_11 * V_12 = F_151 ( V_273 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_275 = V_12 -> V_276 ;
F_16 ( & V_273 -> V_50 , L_24 ,
( F_152 ( V_274 ) ? L_25 : L_20 ) ,
V_273 -> V_277 ) ;
if ( F_65 ( V_12 ) ) {
F_16 ( & V_273 -> V_50 , L_26 , L_27 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_278 ) {
V_31 = - V_168 ;
} else {
F_25 ( V_279 , & V_12 -> V_94 ) ;
V_12 -> V_276 = V_280 ;
V_31 = V_12 -> V_20 -> V_278 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_58 ( V_273 , V_281 ) ;
V_12 -> V_276 = V_282 ;
if ( V_273 -> V_277 ) {
char V_95 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_99 ( V_12 , V_95 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_273 -> V_50 , L_28 ) ;
F_153 ( V_273 , V_283 ) ;
V_31 = - V_176 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_65 ( V_12 ) ) {
F_26 ( V_279 , & V_12 -> V_94 ) ;
V_12 -> V_276 = V_275 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_273 -> V_50 , L_29 ,
L_27 , V_31 ) ;
}
return V_31 ;
}
int F_153 ( struct V_1 * V_273 , T_7 V_274 )
{
struct V_11 * V_12 = F_151 ( V_273 -> V_117 , struct V_11 , V_15 ) ;
int V_31 ;
int V_275 = V_12 -> V_276 ;
F_16 ( & V_273 -> V_50 , L_30 ,
( F_152 ( V_274 ) ? L_25 : L_20 ) ) ;
if ( F_65 ( V_12 ) ) {
F_16 ( & V_273 -> V_50 , L_26 , L_31 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_284 )
return - V_168 ;
if ( F_78 ( V_12 ) )
return 0 ;
V_12 -> V_276 = V_285 ;
V_31 = V_12 -> V_20 -> V_284 ( V_12 ) ;
F_25 ( V_286 , & V_12 -> V_94 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_287 ;
F_7 ( & V_37 ) ;
if ( ! F_65 ( V_12 ) ) {
F_58 ( V_273 , V_273 -> V_288
? V_289
: V_144 ) ;
F_26 ( V_279 , & V_12 -> V_94 ) ;
V_12 -> V_276 = V_290 ;
}
F_9 ( & V_37 ) ;
F_154 (rhdev, port1, udev) {
if ( V_2 -> V_276 != V_291 &&
! V_2 -> V_292 ) {
F_155 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_276 = V_275 ;
F_16 ( & V_273 -> V_50 , L_29 ,
L_31 , V_31 ) ;
if ( V_31 != - V_173 )
F_66 ( V_12 ) ;
}
return V_31 ;
}
static void F_156 ( struct V_293 * V_294 )
{
struct V_11 * V_12 = F_151 ( V_294 , struct V_11 , V_295 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_49 ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
}
void F_160 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_24 ( & V_37 , V_94 ) ;
if ( V_12 -> V_151 ) {
F_26 ( V_286 , & V_12 -> V_94 ) ;
F_161 ( V_296 , & V_12 -> V_295 ) ;
}
F_27 ( & V_37 , V_94 ) ;
}
int F_162 ( struct V_116 * V_117 , unsigned V_297 )
{
struct V_11 * V_12 ;
int V_31 = - V_298 ;
V_12 = F_151 ( V_117 , struct V_11 , V_15 ) ;
if ( V_297 && V_12 -> V_20 -> V_299 )
V_31 = V_12 -> V_20 -> V_299 ( V_12 , V_297 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_101 , V_102 + F_163 ( 10 ) ) ;
return V_31 ;
}
T_8 F_164 ( int V_300 , void * V_301 )
{
struct V_11 * V_12 = V_301 ;
unsigned long V_94 ;
T_8 V_111 ;
F_122 ( V_94 ) ;
if ( F_23 ( F_65 ( V_12 ) || ! F_165 ( V_12 ) ) )
V_111 = V_302 ;
else if ( V_12 -> V_20 -> V_300 ( V_12 ) == V_302 )
V_111 = V_302 ;
else
V_111 = V_303 ;
F_123 ( V_94 ) ;
return V_111 ;
}
void F_66 ( struct V_11 * V_12 )
{
unsigned long V_94 ;
F_64 ( V_12 -> V_15 . V_79 , L_32 ) ;
F_24 ( & V_37 , V_94 ) ;
F_25 ( V_279 , & V_12 -> V_94 ) ;
F_26 ( V_304 , & V_12 -> V_94 ) ;
if ( V_12 -> V_151 ) {
F_25 ( V_305 , & V_12 -> V_94 ) ;
F_58 ( V_12 -> V_15 . V_49 ,
V_291 ) ;
F_166 ( V_12 -> V_15 . V_49 ) ;
}
if ( F_167 ( V_12 ) && V_12 -> V_306 ) {
V_12 = V_12 -> V_306 ;
if ( V_12 -> V_151 ) {
F_25 ( V_305 , & V_12 -> V_94 ) ;
F_58 ( V_12 -> V_15 . V_49 ,
V_291 ) ;
F_166 ( V_12 -> V_15 . V_49 ) ;
}
}
F_27 ( & V_37 , V_94 ) ;
}
static void F_168 ( struct V_219 * V_220 )
{
F_169 ( & V_220 -> V_222 ) ;
F_45 ( & V_220 -> V_225 ) ;
F_170 ( & V_220 -> V_220 , F_124 , ( unsigned long ) V_220 ) ;
}
struct V_11 * F_171 ( const struct V_307 * V_20 ,
struct V_112 * V_50 , const char * V_16 ,
struct V_11 * V_308 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_309 , V_44 ) ;
if ( ! V_12 ) {
F_16 ( V_50 , L_33 ) ;
return NULL ;
}
if ( V_308 == NULL ) {
V_12 -> V_310 = F_172 ( sizeof( * V_12 -> V_310 ) ,
V_44 ) ;
if ( ! V_12 -> V_310 ) {
F_19 ( V_12 ) ;
F_16 ( V_50 , L_34 ) ;
return NULL ;
}
F_173 ( V_12 -> V_310 ) ;
F_174 ( V_50 , V_12 ) ;
} else {
V_12 -> V_310 = V_308 -> V_310 ;
V_12 -> V_308 = V_308 ;
V_308 -> V_308 = V_308 ;
V_12 -> V_306 = V_308 ;
V_308 -> V_306 = V_12 ;
}
F_175 ( & V_12 -> V_311 ) ;
F_44 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_79 = V_50 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_199 = ( V_50 -> V_312 != NULL ) ;
F_176 ( & V_12 -> V_101 ) ;
V_12 -> V_101 . V_313 = F_30 ;
V_12 -> V_101 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_177
F_178 ( & V_12 -> V_295 , F_156 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_60 = V_20 -> V_94 & V_314 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_35 ;
return V_12 ;
}
struct V_11 * F_179 ( const struct V_307 * V_20 ,
struct V_112 * V_50 , const char * V_16 )
{
return F_171 ( V_20 , V_50 , V_16 , NULL ) ;
}
static void F_180 ( struct V_311 * V_311 )
{
struct V_11 * V_12 = F_151 ( V_311 , struct V_11 , V_311 ) ;
if ( F_167 ( V_12 ) )
F_19 ( V_12 -> V_310 ) ;
else
V_12 -> V_306 -> V_306 = NULL ;
F_19 ( V_12 ) ;
}
struct V_11 * F_181 ( struct V_11 * V_12 )
{
if ( V_12 )
F_182 ( & V_12 -> V_311 ) ;
return V_12 ;
}
void F_183 ( struct V_11 * V_12 )
{
if ( V_12 )
F_184 ( & V_12 -> V_311 , F_180 ) ;
}
int F_167 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_308 )
return 1 ;
return V_12 == V_12 -> V_308 ;
}
int F_185 ( struct V_11 * V_12 , int V_287 )
{
if ( ! V_12 -> V_20 -> V_315 )
return V_287 ;
return V_12 -> V_20 -> V_315 ( V_12 , V_287 ) ;
}
static int F_186 ( struct V_11 * V_12 ,
unsigned int V_316 , unsigned long V_317 )
{
int V_105 ;
if ( V_12 -> V_20 -> V_300 ) {
if ( V_317 & V_318 )
V_317 &= ~ V_319 ;
snprintf ( V_12 -> V_320 , sizeof( V_12 -> V_320 ) , L_36 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_127 ) ;
V_105 = F_187 ( V_316 , & F_164 , V_317 ,
V_12 -> V_320 , V_12 ) ;
if ( V_105 != 0 ) {
F_64 ( V_12 -> V_15 . V_79 ,
L_37 ,
V_316 ) ;
return V_105 ;
}
V_12 -> V_300 = V_316 ;
F_53 ( V_12 -> V_15 . V_79 , L_38 , V_316 ,
( V_12 -> V_20 -> V_94 & V_321 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_322 ) ;
} else {
V_12 -> V_300 = 0 ;
if ( V_12 -> V_322 )
F_53 ( V_12 -> V_15 . V_79 , L_41 ,
( V_12 -> V_20 -> V_94 & V_321 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_322 ) ;
}
return 0 ;
}
int F_188 ( struct V_11 * V_12 ,
unsigned int V_316 , unsigned long V_317 )
{
int V_105 ;
struct V_1 * V_273 ;
F_53 ( V_12 -> V_15 . V_79 , L_42 , V_12 -> V_17 ) ;
if ( V_120 < 0 || V_120 > 1 )
V_12 -> V_120 = V_12 -> V_323 ? 0 : 1 ;
else
V_12 -> V_120 = V_120 ;
F_26 ( V_324 , & V_12 -> V_94 ) ;
if ( ( V_105 = F_189 ( V_12 ) ) != 0 ) {
F_16 ( V_12 -> V_15 . V_79 , L_43 ) ;
return V_105 ;
}
if ( ( V_105 = F_46 ( & V_12 -> V_15 ) ) < 0 )
goto V_325;
if ( ( V_273 = F_190 ( NULL , & V_12 -> V_15 , 0 ) ) == NULL ) {
F_64 ( V_12 -> V_15 . V_79 , L_44 ) ;
V_105 = - V_45 ;
goto V_326;
}
V_12 -> V_15 . V_49 = V_273 ;
switch ( V_12 -> V_60 ) {
case V_67 :
V_273 -> V_60 = V_162 ;
break;
case V_65 :
V_273 -> V_60 = V_163 ;
break;
case V_63 :
V_273 -> V_60 = V_327 ;
break;
case V_61 :
V_273 -> V_60 = V_150 ;
break;
default:
V_105 = - V_107 ;
goto V_328;
}
F_191 ( & V_273 -> V_50 , 1 ) ;
F_26 ( V_279 , & V_12 -> V_94 ) ;
if ( V_12 -> V_20 -> V_248 && ( V_105 = V_12 -> V_20 -> V_248 ( V_12 ) ) < 0 ) {
F_64 ( V_12 -> V_15 . V_79 , L_45 , V_105 ) ;
goto V_329;
}
V_12 -> V_96 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_79 )
&& F_15 ( & V_12 -> V_15 . V_49 -> V_50 ) )
F_16 ( V_12 -> V_15 . V_79 , L_46 ) ;
F_168 ( & V_12 -> V_227 ) ;
F_168 ( & V_12 -> V_229 ) ;
if ( F_167 ( V_12 ) && V_316 ) {
V_105 = F_186 ( V_12 , V_316 , V_317 ) ;
if ( V_105 )
goto V_330;
}
V_12 -> V_276 = V_290 ;
V_105 = V_12 -> V_20 -> V_331 ( V_12 ) ;
if ( V_105 < 0 ) {
F_64 ( V_12 -> V_15 . V_79 , L_47 , V_105 ) ;
goto V_332;
}
if ( ( V_105 = F_57 ( V_12 ) ) != 0 )
goto V_333;
V_105 = F_192 ( & V_273 -> V_50 . V_334 , & V_335 ) ;
if ( V_105 < 0 ) {
F_49 ( V_136 L_48 ,
V_105 ) ;
goto V_336;
}
if ( V_12 -> V_97 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
F_193 ( V_12 -> V_15 . V_79 ) ;
return V_105 ;
V_336:
F_25 ( V_279 , & V_12 -> V_94 ) ;
if ( F_194 ( V_12 -> V_276 ) )
V_12 -> V_276 = V_280 ;
F_7 ( & V_37 ) ;
V_12 -> V_151 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_177
F_195 ( & V_12 -> V_295 ) ;
#endif
F_47 ( & V_133 ) ;
F_196 ( & V_273 ) ;
F_51 ( & V_133 ) ;
V_333:
V_12 -> V_96 = 0 ;
F_25 ( V_305 , & V_12 -> V_94 ) ;
F_197 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_337 ( V_12 ) ;
V_12 -> V_276 = V_338 ;
F_25 ( V_305 , & V_12 -> V_94 ) ;
F_197 ( & V_12 -> V_101 ) ;
V_332:
if ( F_167 ( V_12 ) && V_12 -> V_300 > 0 )
F_198 ( V_316 , V_12 ) ;
V_330:
V_329:
V_328:
F_118 ( V_12 -> V_15 . V_49 ) ;
V_326:
F_54 ( & V_12 -> V_15 ) ;
V_325:
F_199 ( V_12 ) ;
return V_105 ;
}
void F_200 ( struct V_11 * V_12 )
{
struct V_1 * V_273 = V_12 -> V_15 . V_49 ;
F_53 ( V_12 -> V_15 . V_79 , L_49 , V_12 -> V_276 ) ;
F_117 ( V_273 ) ;
F_201 ( & V_273 -> V_50 . V_334 , & V_335 ) ;
F_25 ( V_279 , & V_12 -> V_94 ) ;
if ( F_194 ( V_12 -> V_276 ) )
V_12 -> V_276 = V_280 ;
F_16 ( V_12 -> V_15 . V_79 , L_50 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_151 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_177
F_195 ( & V_12 -> V_295 ) ;
#endif
F_47 ( & V_133 ) ;
F_196 ( & V_273 ) ;
F_51 ( & V_133 ) ;
V_12 -> V_96 = 0 ;
F_25 ( V_305 , & V_12 -> V_94 ) ;
F_197 ( & V_12 -> V_101 ) ;
V_12 -> V_20 -> V_337 ( V_12 ) ;
V_12 -> V_276 = V_338 ;
F_25 ( V_305 , & V_12 -> V_94 ) ;
F_197 ( & V_12 -> V_101 ) ;
if ( F_167 ( V_12 ) ) {
if ( V_12 -> V_300 > 0 )
F_198 ( V_12 -> V_300 , V_12 ) ;
}
F_118 ( V_12 -> V_15 . V_49 ) ;
F_54 ( & V_12 -> V_15 ) ;
F_199 ( V_12 ) ;
}
void
F_202 ( struct V_339 * V_50 )
{
struct V_11 * V_12 = F_203 ( V_50 ) ;
if ( V_12 -> V_20 -> V_340 )
V_12 -> V_20 -> V_340 ( V_12 ) ;
}
int F_204 ( struct V_341 * V_342 )
{
if ( V_343 )
return - V_176 ;
V_343 = V_342 ;
F_205 () ;
return 0 ;
}
void F_206 ( void )
{
if ( V_343 == NULL ) {
F_49 ( V_136 L_51 ) ;
return;
}
V_343 = NULL ;
F_205 () ;
}
