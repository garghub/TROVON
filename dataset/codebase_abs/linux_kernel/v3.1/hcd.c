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
T_1 V_31 [ sizeof ( struct V_32 ) ]
V_33 ( ( F_6 ( 4 ) ) ) ;
const T_1 * V_34 = V_31 ;
unsigned V_6 = 0 ;
int V_35 ;
T_1 V_36 = 0 ;
T_1 V_37 = 0 ;
F_7 () ;
F_8 ( & V_38 ) ;
V_35 = F_9 ( V_12 , V_22 ) ;
F_10 ( & V_38 ) ;
if ( V_35 )
return V_35 ;
V_22 -> V_39 = V_12 ;
V_24 = (struct V_23 * ) V_22 -> V_40 ;
V_25 = ( V_24 -> V_41 << 8 ) | V_24 -> V_42 ;
V_26 = F_11 ( V_24 -> V_26 ) ;
V_27 = F_11 ( V_24 -> V_27 ) ;
V_28 = F_11 ( V_24 -> V_28 ) ;
if ( V_28 > V_22 -> V_43 )
goto error;
V_22 -> V_44 = 0 ;
switch ( V_25 ) {
case V_45 | V_46 :
V_31 [ 0 ] = ( F_12 ( & V_12 -> V_15 . V_47 -> V_48 )
<< V_49 )
| ( 1 << V_50 ) ;
V_31 [ 1 ] = 0 ;
V_6 = 2 ;
break;
case V_51 | V_52 :
if ( V_26 == V_49 )
F_13 ( & V_12 -> V_15 . V_47 -> V_48 , 0 ) ;
else
goto error;
break;
case V_51 | V_53 :
if ( F_14 ( & V_12 -> V_15 . V_47 -> V_48 )
&& V_26 == V_49 )
F_13 ( & V_12 -> V_15 . V_47 -> V_48 , 1 ) ;
else
goto error;
break;
case V_45 | V_54 :
V_31 [ 0 ] = 1 ;
V_6 = 1 ;
case V_51 | V_55 :
break;
case V_45 | V_56 :
switch ( V_26 & 0xff00 ) {
case V_57 << 8 :
switch ( V_12 -> V_58 ) {
case V_59 :
V_34 = V_60 ;
break;
case V_61 :
V_34 = V_62 ;
break;
case V_63 :
V_34 = V_64 ;
break;
default:
goto error;
}
V_6 = 18 ;
if ( V_12 -> V_65 )
V_37 = 1 ;
break;
case V_66 << 8 :
switch ( V_12 -> V_58 ) {
case V_59 :
V_34 = V_67 ;
V_6 = sizeof V_67 ;
break;
case V_61 :
V_34 = V_68 ;
V_6 = sizeof V_68 ;
break;
case V_63 :
V_34 = V_69 ;
V_6 = sizeof V_69 ;
break;
default:
goto error;
}
if ( F_14 ( & V_12 -> V_15 . V_47 -> V_48 ) )
V_36 = 1 ;
break;
case V_9 << 8 :
if ( ( V_26 & 0xff ) < 4 )
V_22 -> V_44 = F_3 ( V_26 & 0xff ,
V_12 , V_29 , V_28 ) ;
else
goto error;
break;
default:
goto error;
}
break;
case V_45 | V_70 :
V_31 [ 0 ] = 0 ;
V_6 = 1 ;
case V_51 | V_71 :
break;
case V_51 | V_72 :
F_15 ( V_12 -> V_15 . V_73 , L_2 ,
V_26 ) ;
break;
case V_74 | V_46 :
V_31 [ 0 ] = 0 ;
V_31 [ 1 ] = 0 ;
V_6 = 2 ;
case V_75 | V_52 :
case V_75 | V_53 :
F_15 ( V_12 -> V_15 . V_73 , L_3 ) ;
break;
default:
switch ( V_25 ) {
case V_76 :
case V_77 :
V_6 = 4 ;
break;
case V_78 :
V_6 = sizeof ( struct V_32 ) ;
break;
}
V_35 = V_12 -> V_20 -> V_79 ( V_12 ,
V_25 , V_26 , V_27 ,
V_31 , V_28 ) ;
break;
error:
V_35 = - V_80 ;
}
if ( V_35 ) {
V_6 = 0 ;
if ( V_35 != - V_80 ) {
F_15 ( V_12 -> V_15 . V_73 ,
L_4
L_5 ,
V_25 , V_26 , V_27 ,
V_28 , V_35 ) ;
}
}
if ( V_6 ) {
if ( V_22 -> V_43 < V_6 )
V_6 = V_22 -> V_43 ;
V_22 -> V_44 = V_6 ;
memcpy ( V_29 , V_34 , V_6 ) ;
if ( V_36 &&
V_6 > F_16 ( struct V_81 ,
V_82 ) )
( (struct V_81 * ) V_29 ) -> V_82
|= V_83 ;
if ( V_37 &&
V_6 > F_16 ( struct V_84 ,
V_85 ) )
( (struct V_84 * ) V_29 ) ->
V_85 = 1 ;
}
F_8 ( & V_38 ) ;
F_17 ( V_12 , V_22 ) ;
F_18 ( & V_38 ) ;
F_19 ( V_12 , V_22 , V_35 ) ;
F_20 ( & V_38 ) ;
F_10 ( & V_38 ) ;
return 0 ;
}
void F_21 ( struct V_11 * V_12 )
{
struct V_22 * V_22 ;
int V_86 ;
unsigned long V_87 ;
char V_88 [ 6 ] ;
if ( F_22 ( ! V_12 -> V_89 ) )
return;
if ( ! V_12 -> V_90 && ! V_12 -> V_91 )
return;
V_86 = V_12 -> V_20 -> V_92 ( V_12 , V_88 ) ;
if ( V_86 > 0 ) {
F_23 ( & V_38 , V_87 ) ;
V_22 = V_12 -> V_91 ;
if ( V_22 ) {
F_24 ( V_93 , & V_12 -> V_87 ) ;
V_12 -> V_91 = NULL ;
V_22 -> V_44 = V_86 ;
memcpy ( V_22 -> V_30 , V_88 , V_86 ) ;
F_17 ( V_12 , V_22 ) ;
F_18 ( & V_38 ) ;
F_19 ( V_12 , V_22 , 0 ) ;
F_20 ( & V_38 ) ;
} else {
V_86 = 0 ;
F_25 ( V_93 , & V_12 -> V_87 ) ;
}
F_26 ( & V_38 , V_87 ) ;
}
if ( V_12 -> V_90 ? F_27 ( V_12 ) :
( V_86 == 0 && V_12 -> V_91 != NULL ) )
F_28 ( & V_12 -> V_94 , ( V_95 / ( V_96 / 4 ) + 1 ) * ( V_96 / 4 ) ) ;
}
static void F_29 ( unsigned long V_97 )
{
F_21 ( (struct V_11 * ) V_97 ) ;
}
static int F_30 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_98 ;
unsigned long V_87 ;
unsigned V_6 = 1 + ( V_22 -> V_48 -> V_99 / 8 ) ;
F_23 ( & V_38 , V_87 ) ;
if ( V_12 -> V_91 || V_22 -> V_43 < V_6 ) {
F_15 ( V_12 -> V_15 . V_73 , L_6 ) ;
V_98 = - V_100 ;
goto V_101;
}
V_98 = F_9 ( V_12 , V_22 ) ;
if ( V_98 )
goto V_101;
V_12 -> V_91 = V_22 ;
V_22 -> V_39 = V_12 ;
if ( ! V_12 -> V_90 )
F_28 ( & V_12 -> V_94 , ( V_95 / ( V_96 / 4 ) + 1 ) * ( V_96 / 4 ) ) ;
else if ( F_31 ( V_12 ) )
F_28 ( & V_12 -> V_94 , V_95 ) ;
V_98 = 0 ;
V_101:
F_26 ( & V_38 , V_87 ) ;
return V_98 ;
}
static int F_32 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_33 ( & V_22 -> V_102 -> V_103 ) )
return F_30 ( V_12 , V_22 ) ;
if ( F_34 ( & V_22 -> V_102 -> V_103 ) )
return F_5 ( V_12 , V_22 ) ;
return - V_100 ;
}
static int F_35 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_35 )
{
unsigned long V_87 ;
int V_104 ;
F_23 ( & V_38 , V_87 ) ;
V_104 = F_36 ( V_12 , V_22 , V_35 ) ;
if ( V_104 )
goto V_101;
if ( F_37 ( & V_22 -> V_102 -> V_103 ) == 0 ) {
;
} else {
if ( ! V_12 -> V_90 )
F_38 ( & V_12 -> V_94 ) ;
if ( V_22 == V_12 -> V_91 ) {
V_12 -> V_91 = NULL ;
F_17 ( V_12 , V_22 ) ;
F_18 ( & V_38 ) ;
F_19 ( V_12 , V_22 , V_35 ) ;
F_20 ( & V_38 ) ;
}
}
V_101:
F_26 ( & V_38 , V_87 ) ;
return V_104 ;
}
static T_3 F_39 ( struct V_105 * V_48 ,
struct V_106 * V_107 ,
char * V_5 )
{
struct V_1 * V_108 = F_40 ( V_48 ) ;
struct V_109 * V_109 = V_108 -> V_110 ;
struct V_11 * V_11 ;
if ( V_109 == NULL )
return - V_111 ;
V_11 = F_41 ( V_109 ) ;
return snprintf ( V_5 , V_112 , L_7 , V_11 -> V_113 ) ;
}
static T_3 F_42 ( struct V_105 * V_48 ,
struct V_106 * V_107 ,
const char * V_5 , T_4 V_114 )
{
T_3 V_115 ;
unsigned V_116 ;
struct V_1 * V_108 = F_40 ( V_48 ) ;
struct V_109 * V_109 = V_108 -> V_110 ;
struct V_11 * V_11 ;
if ( V_109 == NULL )
return - V_111 ;
V_11 = F_41 ( V_109 ) ;
V_115 = sscanf ( V_5 , L_7 , & V_116 ) ;
if ( V_115 == 1 ) {
V_11 -> V_113 = V_116 ? 1 : 0 ;
V_115 = V_114 ;
}
else
V_115 = - V_100 ;
return V_115 ;
}
static void F_43 ( struct V_109 * V_110 )
{
memset ( & V_110 -> V_117 , 0 , sizeof( struct V_118 ) ) ;
V_110 -> V_119 = 1 ;
V_110 -> V_47 = NULL ;
V_110 -> V_120 = - 1 ;
V_110 -> V_121 = 0 ;
V_110 -> V_122 = 0 ;
V_110 -> V_123 = 0 ;
F_44 ( & V_110 -> V_124 ) ;
}
static int F_45 ( struct V_109 * V_110 )
{
int V_115 = - V_125 ;
int V_120 ;
F_46 ( & V_126 ) ;
V_120 = F_47 ( V_127 . V_127 , V_128 , 1 ) ;
if ( V_120 >= V_128 ) {
F_48 ( V_129 L_8 , V_130 ) ;
goto V_131;
}
F_25 ( V_120 , V_127 . V_127 ) ;
V_110 -> V_120 = V_120 ;
F_49 ( & V_110 -> V_124 , & V_132 ) ;
F_50 ( & V_126 ) ;
F_51 ( V_110 ) ;
F_52 ( V_110 -> V_73 , L_9
L_10 , V_110 -> V_120 ) ;
return 0 ;
V_131:
F_50 ( & V_126 ) ;
return V_115 ;
}
static void F_53 ( struct V_109 * V_110 )
{
F_52 ( V_110 -> V_73 , L_11 , V_110 -> V_120 ) ;
F_46 ( & V_126 ) ;
F_54 ( & V_110 -> V_124 ) ;
F_50 ( & V_126 ) ;
F_55 ( V_110 ) ;
F_24 ( V_110 -> V_120 , V_127 . V_127 ) ;
}
static int F_56 ( struct V_11 * V_12 )
{
struct V_105 * V_133 = V_12 -> V_15 . V_73 ;
struct V_1 * V_134 = V_12 -> V_15 . V_47 ;
const int V_135 = 1 ;
int V_98 ;
V_134 -> V_135 = V_135 ;
V_134 -> V_110 -> V_119 = V_135 + 1 ;
memset ( & V_134 -> V_110 -> V_117 . V_136 , 0 ,
sizeof V_134 -> V_110 -> V_117 . V_136 ) ;
F_25 ( V_135 , V_134 -> V_110 -> V_117 . V_136 ) ;
F_57 ( V_134 , V_137 ) ;
F_46 ( & V_126 ) ;
V_134 -> V_138 . V_103 . V_139 = F_58 ( 64 ) ;
V_98 = F_59 ( V_134 , V_140 ) ;
if ( V_98 != sizeof V_134 -> V_141 ) {
F_50 ( & V_126 ) ;
F_15 ( V_133 , L_12 ,
F_60 ( & V_134 -> V_48 ) , V_98 ) ;
return ( V_98 < 0 ) ? V_98 : - V_142 ;
}
V_98 = F_61 ( V_134 ) ;
if ( V_98 ) {
F_62 ( V_133 , L_13 ,
F_60 ( & V_134 -> V_48 ) , V_98 ) ;
}
F_50 ( & V_126 ) ;
if ( V_98 == 0 ) {
F_8 ( & V_38 ) ;
V_12 -> V_143 = 1 ;
F_10 ( & V_38 ) ;
if ( F_63 ( V_12 ) )
F_64 ( V_12 ) ;
}
return V_98 ;
}
long F_65 ( int V_58 , int V_144 , int V_145 , int V_146 )
{
unsigned long V_147 ;
switch ( V_58 ) {
case V_148 :
if ( V_144 ) {
V_147 = ( 67667L * ( 31L + 10L * F_66 ( V_146 ) ) ) / 1000L ;
return ( 64060L + ( 2 * V_149 ) + V_150 + V_147 ) ;
} else {
V_147 = ( 66700L * ( 31L + 10L * F_66 ( V_146 ) ) ) / 1000L ;
return ( 64107L + ( 2 * V_149 ) + V_150 + V_147 ) ;
}
case V_151 :
if ( V_145 ) {
V_147 = ( 8354L * ( 31L + 10L * F_66 ( V_146 ) ) ) / 1000L ;
return ( ( ( V_144 ) ? 7268L : 6265L ) + V_150 + V_147 ) ;
} else {
V_147 = ( 8354L * ( 31L + 10L * F_66 ( V_146 ) ) ) / 1000L ;
return ( 9107L + V_150 + V_147 ) ;
}
case V_152 :
if ( V_145 )
V_147 = F_67 ( V_146 ) ;
else
V_147 = F_68 ( V_146 ) ;
return V_147 ;
default:
F_69 ( L_14 , V_130 ) ;
return - 1 ;
}
}
int F_9 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_104 = 0 ;
F_20 ( & V_153 ) ;
if ( F_22 ( F_70 ( & V_22 -> V_154 ) ) ) {
V_104 = - V_155 ;
goto V_101;
}
if ( F_22 ( ! V_22 -> V_102 -> V_156 ) ) {
V_104 = - V_157 ;
goto V_101;
}
if ( F_22 ( ! V_22 -> V_48 -> V_158 ) ) {
V_104 = - V_159 ;
goto V_101;
}
if ( F_71 ( V_12 ) ) {
V_22 -> V_160 = 0 ;
F_72 ( & V_22 -> V_161 , & V_22 -> V_102 -> V_161 ) ;
} else {
V_104 = - V_162 ;
goto V_101;
}
V_101:
F_18 ( & V_153 ) ;
return V_104 ;
}
int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_35 )
{
struct V_163 * V_147 ;
F_73 (tmp, &urb->ep->urb_list) {
if ( V_147 == & V_22 -> V_161 )
break;
}
if ( V_147 != & V_22 -> V_161 )
return - V_164 ;
if ( V_22 -> V_160 )
return - V_165 ;
V_22 -> V_160 = V_35 ;
if ( ! F_74 ( V_12 ) && ! F_1 ( V_22 -> V_48 ) ) {
F_75 ( V_12 -> V_15 . V_73 , L_15
L_16 ) ;
F_25 ( V_166 , & V_12 -> V_87 ) ;
if ( V_12 -> V_167 )
F_25 ( V_166 , & V_12 -> V_167 -> V_87 ) ;
}
return 0 ;
}
void F_17 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_20 ( & V_153 ) ;
F_76 ( & V_22 -> V_161 ) ;
F_18 ( & V_153 ) ;
}
static int F_77 ( struct V_109 * V_110 ,
T_5 V_168 , T_6 * V_169 ,
void * * V_170 , T_4 V_114 ,
enum V_171 V_172 )
{
unsigned char * V_173 ;
if ( * V_170 == NULL ) {
F_78 ( 1 ) ;
return - V_174 ;
}
V_173 = F_79 ( V_110 , V_114 + sizeof( V_173 ) ,
V_168 , V_169 ) ;
if ( ! V_173 )
return - V_175 ;
F_80 ( ( unsigned long ) * V_170 ,
( unsigned long * ) ( V_173 + V_114 ) ) ;
if ( V_172 == V_176 )
memcpy ( V_173 , * V_170 , V_114 ) ;
* V_170 = V_173 ;
return 0 ;
}
static void F_81 ( struct V_109 * V_110 , T_6 * V_169 ,
void * * V_170 , T_4 V_114 ,
enum V_171 V_172 )
{
unsigned char * V_173 = * V_170 ;
V_173 = ( void * ) F_82 ( ( unsigned long * ) ( V_173 + V_114 ) ) ;
if ( V_172 == V_177 )
memcpy ( V_173 , * V_170 , V_114 ) ;
F_83 ( V_110 , V_114 + sizeof( V_173 ) , * V_170 , * V_169 ) ;
* V_170 = V_173 ;
* V_169 = 0 ;
}
void F_84 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_178 & V_179 )
F_85 ( V_12 -> V_15 . V_73 ,
V_22 -> V_180 ,
sizeof( struct V_23 ) ,
V_176 ) ;
else if ( V_22 -> V_178 & V_181 )
F_81 ( V_22 -> V_48 -> V_110 ,
& V_22 -> V_180 ,
( void * * ) & V_22 -> V_40 ,
sizeof( struct V_23 ) ,
V_176 ) ;
V_22 -> V_178 &= ~ ( V_179 | V_181 ) ;
}
static void F_86 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_86 )
V_12 -> V_20 -> F_86 ( V_12 , V_22 ) ;
else
F_87 ( V_12 , V_22 ) ;
}
void F_87 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_171 V_172 ;
F_84 ( V_12 , V_22 ) ;
V_172 = F_88 ( V_22 ) ? V_177 : V_176 ;
if ( V_22 -> V_178 & V_182 )
F_89 ( V_12 -> V_15 . V_73 ,
V_22 -> V_183 ,
V_22 -> V_184 ,
V_172 ) ;
else if ( V_22 -> V_178 & V_185 )
F_90 ( V_12 -> V_15 . V_73 ,
V_22 -> V_186 ,
V_22 -> V_43 ,
V_172 ) ;
else if ( V_22 -> V_178 & V_187 )
F_85 ( V_12 -> V_15 . V_73 ,
V_22 -> V_186 ,
V_22 -> V_43 ,
V_172 ) ;
else if ( V_22 -> V_178 & V_188 )
F_81 ( V_22 -> V_48 -> V_110 ,
& V_22 -> V_186 ,
& V_22 -> V_30 ,
V_22 -> V_43 ,
V_172 ) ;
V_22 -> V_178 &= ~ ( V_182 | V_185 |
V_187 | V_188 ) ;
}
static int F_91 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_168 )
{
if ( V_12 -> V_20 -> F_91 )
return V_12 -> V_20 -> F_91 ( V_12 , V_22 , V_168 ) ;
else
return F_92 ( V_12 , V_22 , V_168 ) ;
}
int F_92 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_168 )
{
enum V_171 V_172 ;
int V_189 = 0 ;
if ( F_34 ( & V_22 -> V_102 -> V_103 ) ) {
if ( V_12 -> V_15 . V_190 )
return V_189 ;
if ( V_12 -> V_15 . V_191 ) {
V_22 -> V_180 = F_93 (
V_12 -> V_15 . V_73 ,
V_22 -> V_40 ,
sizeof( struct V_23 ) ,
V_176 ) ;
if ( F_94 ( V_12 -> V_15 . V_73 ,
V_22 -> V_180 ) )
return - V_192 ;
V_22 -> V_178 |= V_179 ;
} else if ( V_12 -> V_20 -> V_87 & V_193 ) {
V_189 = F_77 (
V_22 -> V_48 -> V_110 , V_168 ,
& V_22 -> V_180 ,
( void * * ) & V_22 -> V_40 ,
sizeof( struct V_23 ) ,
V_176 ) ;
if ( V_189 )
return V_189 ;
V_22 -> V_178 |= V_181 ;
}
}
V_172 = F_88 ( V_22 ) ? V_177 : V_176 ;
if ( V_22 -> V_43 != 0
&& ! ( V_22 -> V_178 & V_194 ) ) {
if ( V_12 -> V_15 . V_191 ) {
if ( V_22 -> V_184 ) {
int V_7 = F_95 (
V_12 -> V_15 . V_73 ,
V_22 -> V_183 ,
V_22 -> V_184 ,
V_172 ) ;
if ( V_7 <= 0 )
V_189 = - V_192 ;
else
V_22 -> V_178 |= V_182 ;
if ( V_7 != V_22 -> V_184 ) {
V_22 -> V_184 = V_7 ;
V_22 -> V_178 |=
V_195 ;
}
} else if ( V_22 -> V_183 ) {
struct V_196 * V_183 = V_22 -> V_183 ;
V_22 -> V_186 = F_96 (
V_12 -> V_15 . V_73 ,
F_97 ( V_183 ) ,
V_183 -> V_197 ,
V_22 -> V_43 ,
V_172 ) ;
if ( F_94 ( V_12 -> V_15 . V_73 ,
V_22 -> V_186 ) )
V_189 = - V_192 ;
else
V_22 -> V_178 |= V_185 ;
} else {
V_22 -> V_186 = F_93 (
V_12 -> V_15 . V_73 ,
V_22 -> V_30 ,
V_22 -> V_43 ,
V_172 ) ;
if ( F_94 ( V_12 -> V_15 . V_73 ,
V_22 -> V_186 ) )
V_189 = - V_192 ;
else
V_22 -> V_178 |= V_187 ;
}
} else if ( V_12 -> V_20 -> V_87 & V_193 ) {
V_189 = F_77 (
V_22 -> V_48 -> V_110 , V_168 ,
& V_22 -> V_186 ,
& V_22 -> V_30 ,
V_22 -> V_43 ,
V_172 ) ;
if ( V_189 == 0 )
V_22 -> V_178 |= V_188 ;
}
if ( V_189 && ( V_22 -> V_178 & ( V_179 |
V_181 ) ) )
F_87 ( V_12 , V_22 ) ;
}
return V_189 ;
}
int F_98 ( struct V_22 * V_22 , T_5 V_168 )
{
int V_35 ;
struct V_11 * V_12 = F_41 ( V_22 -> V_48 -> V_110 ) ;
F_99 ( V_22 ) ;
F_100 ( & V_22 -> V_198 ) ;
F_100 ( & V_22 -> V_48 -> V_199 ) ;
F_101 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_48 ) ) {
V_35 = F_32 ( V_12 , V_22 ) ;
} else {
V_35 = F_91 ( V_12 , V_22 , V_168 ) ;
if ( F_102 ( V_35 == 0 ) ) {
V_35 = V_12 -> V_20 -> V_200 ( V_12 , V_22 , V_168 ) ;
if ( F_22 ( V_35 ) )
F_86 ( V_12 , V_22 ) ;
}
}
if ( F_22 ( V_35 ) ) {
F_103 ( & V_12 -> V_15 , V_22 , V_35 ) ;
V_22 -> V_39 = NULL ;
F_44 ( & V_22 -> V_161 ) ;
F_104 ( & V_22 -> V_198 ) ;
F_104 ( & V_22 -> V_48 -> V_199 ) ;
if ( F_70 ( & V_22 -> V_154 ) )
F_105 ( & V_201 ) ;
F_106 ( V_22 ) ;
}
return V_35 ;
}
static int F_107 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_35 )
{
int V_202 ;
if ( F_1 ( V_22 -> V_48 ) )
V_202 = F_35 ( V_12 , V_22 , V_35 ) ;
else {
V_202 = V_12 -> V_20 -> V_203 ( V_12 , V_22 , V_35 ) ;
}
return V_202 ;
}
int F_108 ( struct V_22 * V_22 , int V_35 )
{
struct V_11 * V_12 ;
int V_98 = - V_164 ;
unsigned long V_87 ;
F_23 ( & V_204 , V_87 ) ;
if ( F_70 ( & V_22 -> V_198 ) > 0 ) {
V_98 = 0 ;
F_109 ( V_22 -> V_48 ) ;
}
F_26 ( & V_204 , V_87 ) ;
if ( V_98 == 0 ) {
V_12 = F_41 ( V_22 -> V_48 -> V_110 ) ;
V_98 = F_107 ( V_12 , V_22 , V_35 ) ;
F_110 ( V_22 -> V_48 ) ;
}
if ( V_98 == 0 )
V_98 = - V_205 ;
else if ( V_98 != - V_164 && V_98 != - V_165 )
F_15 ( & V_22 -> V_48 -> V_48 , L_17 ,
V_22 , V_98 ) ;
return V_98 ;
}
void F_19 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_35 )
{
V_22 -> V_39 = NULL ;
if ( F_22 ( V_22 -> V_160 ) )
V_35 = V_22 -> V_160 ;
else if ( F_22 ( ( V_22 -> V_178 & V_206 ) &&
V_22 -> V_44 < V_22 -> V_43 &&
! V_35 ) )
V_35 = - V_207 ;
F_86 ( V_12 , V_22 ) ;
F_111 ( & V_12 -> V_15 , V_22 , V_35 ) ;
F_112 ( V_22 ) ;
V_22 -> V_35 = V_35 ;
V_22 -> V_208 ( V_22 ) ;
F_104 ( & V_22 -> V_198 ) ;
if ( F_22 ( F_70 ( & V_22 -> V_154 ) ) )
F_105 ( & V_201 ) ;
F_106 ( V_22 ) ;
}
void F_113 ( struct V_1 * V_2 ,
struct V_209 * V_102 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_102 )
return;
F_7 () ;
V_12 = F_41 ( V_2 -> V_110 ) ;
F_8 ( & V_153 ) ;
V_210:
F_114 (urb, &ep->urb_list, urb_list) {
int V_211 ;
if ( V_22 -> V_160 )
continue;
F_99 ( V_22 ) ;
V_211 = F_88 ( V_22 ) ;
F_18 ( & V_153 ) ;
F_107 ( V_12 , V_22 , - V_162 ) ;
F_15 (hcd->self.controller,
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
F_106 ( V_22 ) ;
F_20 ( & V_153 ) ;
goto V_210;
}
F_10 ( & V_153 ) ;
while ( ! F_115 ( & V_102 -> V_161 ) ) {
F_8 ( & V_153 ) ;
V_22 = NULL ;
if ( ! F_115 ( & V_102 -> V_161 ) ) {
V_22 = F_116 ( V_102 -> V_161 . V_212 , struct V_22 ,
V_161 ) ;
F_99 ( V_22 ) ;
}
F_10 ( & V_153 ) ;
if ( V_22 ) {
F_117 ( V_22 ) ;
F_106 ( V_22 ) ;
}
}
}
int F_118 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
struct V_215 * V_216 ,
struct V_215 * V_217 )
{
int V_218 , V_219 , V_220 ;
struct V_215 * V_221 = NULL ;
int V_189 = 0 ;
struct V_11 * V_12 ;
struct V_209 * V_102 ;
V_12 = F_41 ( V_2 -> V_110 ) ;
if ( ! V_12 -> V_20 -> V_222 )
return 0 ;
if ( ! V_214 && ! V_216 ) {
for ( V_219 = 1 ; V_219 < 16 ; ++ V_219 ) {
V_102 = V_2 -> V_223 [ V_219 ] ;
if ( V_102 )
V_12 -> V_20 -> V_224 ( V_12 , V_2 , V_102 ) ;
V_102 = V_2 -> V_225 [ V_219 ] ;
if ( V_102 )
V_12 -> V_20 -> V_224 ( V_12 , V_2 , V_102 ) ;
}
V_12 -> V_20 -> V_222 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_214 ) {
V_218 = V_214 -> V_103 . V_226 ;
for ( V_219 = 1 ; V_219 < 16 ; ++ V_219 ) {
V_102 = V_2 -> V_223 [ V_219 ] ;
if ( V_102 ) {
V_189 = V_12 -> V_20 -> V_224 ( V_12 , V_2 , V_102 ) ;
if ( V_189 < 0 )
goto V_227;
}
V_102 = V_2 -> V_225 [ V_219 ] ;
if ( V_102 ) {
V_189 = V_12 -> V_20 -> V_224 ( V_12 , V_2 , V_102 ) ;
if ( V_189 < 0 )
goto V_227;
}
}
for ( V_219 = 0 ; V_219 < V_218 ; ++ V_219 ) {
struct V_215 * V_228 ;
int V_229 ;
V_228 = & V_214 -> V_230 [ V_219 ] -> V_231 [ 0 ] ;
V_229 = V_228 -> V_103 . V_232 ;
V_221 = F_119 ( V_214 , V_229 , 0 ) ;
if ( ! V_221 )
V_221 = V_228 ;
for ( V_220 = 0 ; V_220 < V_221 -> V_103 . V_233 ; V_220 ++ ) {
V_189 = V_12 -> V_20 -> V_234 ( V_12 , V_2 , & V_221 -> V_235 [ V_220 ] ) ;
if ( V_189 < 0 )
goto V_227;
}
}
}
if ( V_216 && V_217 ) {
struct V_236 * V_237 = F_120 ( V_2 ,
V_216 -> V_103 . V_232 ) ;
if ( ! V_237 )
return - V_100 ;
if ( V_237 -> V_238 ) {
V_216 = F_121 ( V_237 , 0 ) ;
if ( ! V_216 )
V_216 = & V_237 -> V_231 [ 0 ] ;
}
for ( V_219 = 0 ; V_219 < V_216 -> V_103 . V_233 ; V_219 ++ ) {
V_189 = V_12 -> V_20 -> V_224 ( V_12 , V_2 ,
& V_216 -> V_235 [ V_219 ] ) ;
if ( V_189 < 0 )
goto V_227;
}
for ( V_219 = 0 ; V_219 < V_217 -> V_103 . V_233 ; V_219 ++ ) {
V_189 = V_12 -> V_20 -> V_234 ( V_12 , V_2 ,
& V_217 -> V_235 [ V_219 ] ) ;
if ( V_189 < 0 )
goto V_227;
}
}
V_189 = V_12 -> V_20 -> V_222 ( V_12 , V_2 ) ;
V_227:
if ( V_189 < 0 )
V_12 -> V_20 -> V_239 ( V_12 , V_2 ) ;
return V_189 ;
}
void F_122 ( struct V_1 * V_2 ,
struct V_209 * V_102 )
{
struct V_11 * V_12 ;
F_7 () ;
V_12 = F_41 ( V_2 -> V_110 ) ;
if ( V_12 -> V_20 -> V_240 )
V_12 -> V_20 -> V_240 ( V_12 , V_102 ) ;
}
void F_123 ( struct V_1 * V_2 ,
struct V_209 * V_102 )
{
struct V_11 * V_12 = F_41 ( V_2 -> V_110 ) ;
if ( V_12 -> V_20 -> V_241 )
V_12 -> V_20 -> V_241 ( V_12 , V_102 ) ;
else {
int V_242 = F_37 ( & V_102 -> V_103 ) ;
int V_243 = F_124 ( & V_102 -> V_103 ) ;
int V_244 = F_34 ( & V_102 -> V_103 ) ;
F_125 ( V_2 , V_242 , V_243 , 0 ) ;
if ( V_244 )
F_125 ( V_2 , V_242 , ! V_243 , 0 ) ;
}
}
int F_126 ( struct V_236 * V_245 ,
struct V_209 * * V_246 , unsigned int V_247 ,
unsigned int V_248 , T_5 V_168 )
{
struct V_11 * V_12 ;
struct V_1 * V_48 ;
int V_219 ;
V_48 = F_127 ( V_245 ) ;
V_12 = F_41 ( V_48 -> V_110 ) ;
if ( ! V_12 -> V_20 -> V_249 || ! V_12 -> V_20 -> V_250 )
return - V_100 ;
if ( V_48 -> V_58 != V_251 )
return - V_100 ;
for ( V_219 = 0 ; V_219 < V_247 ; V_219 ++ )
if ( ! F_128 ( & V_246 [ V_219 ] -> V_103 ) )
return - V_100 ;
return V_12 -> V_20 -> V_249 ( V_12 , V_48 , V_246 , V_247 ,
V_248 , V_168 ) ;
}
void F_129 ( struct V_236 * V_245 ,
struct V_209 * * V_246 , unsigned int V_247 ,
T_5 V_168 )
{
struct V_11 * V_12 ;
struct V_1 * V_48 ;
int V_219 ;
V_48 = F_127 ( V_245 ) ;
V_12 = F_41 ( V_48 -> V_110 ) ;
if ( V_48 -> V_58 != V_251 )
return;
for ( V_219 = 0 ; V_219 < V_247 ; V_219 ++ )
if ( ! V_246 [ V_219 ] || ! F_128 ( & V_246 [ V_219 ] -> V_103 ) )
return;
V_12 -> V_20 -> V_250 ( V_12 , V_48 , V_246 , V_247 , V_168 ) ;
}
void F_130 ( struct V_1 * V_2 )
{
F_8 ( & V_204 ) ;
F_10 ( & V_204 ) ;
}
int F_131 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_41 ( V_2 -> V_110 ) ;
if ( ! F_71 ( V_12 ) )
return - V_162 ;
return V_12 -> V_20 -> V_252 ( V_12 ) ;
}
int F_132 ( struct V_1 * V_253 , T_7 V_254 )
{
struct V_11 * V_12 = F_133 ( V_253 -> V_110 , struct V_11 , V_15 ) ;
int V_35 ;
int V_255 = V_12 -> V_256 ;
F_15 ( & V_253 -> V_48 , L_25 ,
( V_254 . V_257 & V_258 ? L_26 : L_21 ) , L_27 ) ;
if ( F_63 ( V_12 ) ) {
F_15 ( & V_253 -> V_48 , L_28 , L_27 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_259 ) {
V_35 = - V_157 ;
} else {
F_24 ( V_260 , & V_12 -> V_87 ) ;
V_12 -> V_256 = V_261 ;
V_35 = V_12 -> V_20 -> V_259 ( V_12 ) ;
}
if ( V_35 == 0 ) {
F_57 ( V_253 , V_262 ) ;
V_12 -> V_256 = V_263 ;
} else {
F_8 ( & V_38 ) ;
if ( ! F_63 ( V_12 ) ) {
F_25 ( V_260 , & V_12 -> V_87 ) ;
V_12 -> V_256 = V_255 ;
}
F_10 ( & V_38 ) ;
F_15 ( & V_253 -> V_48 , L_29 ,
L_27 , V_35 ) ;
}
return V_35 ;
}
int F_134 ( struct V_1 * V_253 , T_7 V_254 )
{
struct V_11 * V_12 = F_133 ( V_253 -> V_110 , struct V_11 , V_15 ) ;
int V_35 ;
int V_255 = V_12 -> V_256 ;
F_15 ( & V_253 -> V_48 , L_30 ,
( V_254 . V_257 & V_258 ? L_26 : L_21 ) , L_31 ) ;
if ( F_63 ( V_12 ) ) {
F_15 ( & V_253 -> V_48 , L_28 , L_31 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_264 )
return - V_157 ;
if ( F_71 ( V_12 ) )
return 0 ;
V_12 -> V_256 = V_265 ;
V_35 = V_12 -> V_20 -> V_264 ( V_12 ) ;
F_24 ( V_266 , & V_12 -> V_87 ) ;
if ( V_35 == 0 ) {
F_135 ( 10 ) ;
F_8 ( & V_38 ) ;
if ( ! F_63 ( V_12 ) ) {
F_57 ( V_253 , V_253 -> V_267
? V_268
: V_137 ) ;
F_25 ( V_260 , & V_12 -> V_87 ) ;
V_12 -> V_256 = V_269 ;
}
F_10 ( & V_38 ) ;
} else {
V_12 -> V_256 = V_255 ;
F_15 ( & V_253 -> V_48 , L_29 ,
L_31 , V_35 ) ;
if ( V_35 != - V_162 )
F_64 ( V_12 ) ;
}
return V_35 ;
}
static void F_136 ( struct V_270 * V_271 )
{
struct V_11 * V_12 = F_133 ( V_271 , struct V_11 , V_272 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_47 ;
F_137 ( V_2 ) ;
F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
}
void F_140 ( struct V_11 * V_12 )
{
unsigned long V_87 ;
F_23 ( & V_38 , V_87 ) ;
if ( V_12 -> V_143 ) {
F_25 ( V_266 , & V_12 -> V_87 ) ;
F_141 ( V_273 , & V_12 -> V_272 ) ;
}
F_26 ( & V_38 , V_87 ) ;
}
int F_142 ( struct V_109 * V_110 , unsigned V_274 )
{
struct V_11 * V_12 ;
int V_35 = - V_275 ;
V_12 = F_133 ( V_110 , struct V_11 , V_15 ) ;
if ( V_274 && V_12 -> V_20 -> V_276 )
V_35 = V_12 -> V_20 -> V_276 ( V_12 , V_274 ) ;
if ( V_35 == 0 )
F_28 ( & V_12 -> V_94 , V_95 + F_143 ( 10 ) ) ;
return V_35 ;
}
T_8 F_144 ( int V_277 , void * V_278 )
{
struct V_11 * V_12 = V_278 ;
unsigned long V_87 ;
T_8 V_104 ;
F_145 ( V_87 ) ;
if ( F_22 ( F_63 ( V_12 ) || ! F_146 ( V_12 ) ) ) {
V_104 = V_279 ;
} else if ( V_12 -> V_20 -> V_277 ( V_12 ) == V_279 ) {
V_104 = V_279 ;
} else {
F_25 ( V_166 , & V_12 -> V_87 ) ;
if ( V_12 -> V_167 )
F_25 ( V_166 , & V_12 -> V_167 -> V_87 ) ;
V_104 = V_280 ;
}
F_147 ( V_87 ) ;
return V_104 ;
}
void F_64 ( struct V_11 * V_12 )
{
unsigned long V_87 ;
F_62 ( V_12 -> V_15 . V_73 , L_32 ) ;
F_23 ( & V_38 , V_87 ) ;
F_24 ( V_260 , & V_12 -> V_87 ) ;
F_25 ( V_281 , & V_12 -> V_87 ) ;
if ( V_12 -> V_143 ) {
F_24 ( V_282 , & V_12 -> V_87 ) ;
F_57 ( V_12 -> V_15 . V_47 ,
V_283 ) ;
F_148 ( V_12 -> V_15 . V_47 ) ;
}
if ( F_149 ( V_12 ) && V_12 -> V_167 ) {
V_12 = V_12 -> V_167 ;
if ( V_12 -> V_143 ) {
F_24 ( V_282 , & V_12 -> V_87 ) ;
F_57 ( V_12 -> V_15 . V_47 ,
V_283 ) ;
F_148 ( V_12 -> V_15 . V_47 ) ;
}
}
F_26 ( & V_38 , V_87 ) ;
}
struct V_11 * F_150 ( const struct V_284 * V_20 ,
struct V_105 * V_48 , const char * V_16 ,
struct V_11 * V_285 )
{
struct V_11 * V_12 ;
V_12 = F_151 ( sizeof( * V_12 ) + V_20 -> V_286 , V_287 ) ;
if ( ! V_12 ) {
F_15 ( V_48 , L_33 ) ;
return NULL ;
}
if ( V_285 == NULL ) {
V_12 -> V_288 = F_152 ( sizeof( * V_12 -> V_288 ) ,
V_287 ) ;
if ( ! V_12 -> V_288 ) {
F_153 ( V_12 ) ;
F_15 ( V_48 , L_34 ) ;
return NULL ;
}
F_154 ( V_12 -> V_288 ) ;
F_155 ( V_48 , V_12 ) ;
} else {
V_12 -> V_288 = V_285 -> V_288 ;
V_12 -> V_285 = V_285 ;
V_285 -> V_285 = V_285 ;
V_12 -> V_167 = V_285 ;
V_285 -> V_167 = V_12 ;
}
F_156 ( & V_12 -> V_289 ) ;
F_43 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_73 = V_48 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_191 = ( V_48 -> V_290 != NULL ) ;
F_157 ( & V_12 -> V_94 ) ;
V_12 -> V_94 . V_291 = F_29 ;
V_12 -> V_94 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_158
F_159 ( & V_12 -> V_272 , F_136 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_58 = V_20 -> V_87 & V_292 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_35 ;
return V_12 ;
}
struct V_11 * F_160 ( const struct V_284 * V_20 ,
struct V_105 * V_48 , const char * V_16 )
{
return F_150 ( V_20 , V_48 , V_16 , NULL ) ;
}
static void F_161 ( struct V_289 * V_289 )
{
struct V_11 * V_12 = F_133 ( V_289 , struct V_11 , V_289 ) ;
if ( F_149 ( V_12 ) )
F_153 ( V_12 -> V_288 ) ;
else
V_12 -> V_167 -> V_167 = NULL ;
F_153 ( V_12 ) ;
}
struct V_11 * F_162 ( struct V_11 * V_12 )
{
if ( V_12 )
F_163 ( & V_12 -> V_289 ) ;
return V_12 ;
}
void F_164 ( struct V_11 * V_12 )
{
if ( V_12 )
F_165 ( & V_12 -> V_289 , F_161 ) ;
}
int F_149 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_285 )
return 1 ;
return V_12 == V_12 -> V_285 ;
}
static int F_166 ( struct V_11 * V_12 ,
unsigned int V_293 , unsigned long V_294 )
{
int V_98 ;
if ( V_12 -> V_20 -> V_277 ) {
if ( V_294 & V_295 )
V_294 &= ~ V_296 ;
snprintf ( V_12 -> V_297 , sizeof( V_12 -> V_297 ) , L_36 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_120 ) ;
V_98 = F_167 ( V_293 , & F_144 , V_294 ,
V_12 -> V_297 , V_12 ) ;
if ( V_98 != 0 ) {
F_62 ( V_12 -> V_15 . V_73 ,
L_37 ,
V_293 ) ;
return V_98 ;
}
V_12 -> V_277 = V_293 ;
F_52 ( V_12 -> V_15 . V_73 , L_38 , V_293 ,
( V_12 -> V_20 -> V_87 & V_298 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_299 ) ;
} else {
V_12 -> V_277 = - 1 ;
if ( V_12 -> V_299 )
F_52 ( V_12 -> V_15 . V_73 , L_41 ,
( V_12 -> V_20 -> V_87 & V_298 ) ?
L_39 : L_40 ,
( unsigned long long ) V_12 -> V_299 ) ;
}
return 0 ;
}
int F_168 ( struct V_11 * V_12 ,
unsigned int V_293 , unsigned long V_294 )
{
int V_98 ;
struct V_1 * V_253 ;
F_52 ( V_12 -> V_15 . V_73 , L_42 , V_12 -> V_17 ) ;
if ( V_113 < 0 || V_113 > 1 )
V_12 -> V_113 = V_12 -> V_300 ? 0 : 1 ;
else
V_12 -> V_113 = V_113 ;
F_25 ( V_301 , & V_12 -> V_87 ) ;
if ( ( V_98 = F_169 ( V_12 ) ) != 0 ) {
F_15 ( V_12 -> V_15 . V_73 , L_43 ) ;
return V_98 ;
}
if ( ( V_98 = F_45 ( & V_12 -> V_15 ) ) < 0 )
goto V_302;
if ( ( V_253 = F_170 ( NULL , & V_12 -> V_15 , 0 ) ) == NULL ) {
F_62 ( V_12 -> V_15 . V_73 , L_44 ) ;
V_98 = - V_175 ;
goto V_303;
}
V_12 -> V_15 . V_47 = V_253 ;
switch ( V_12 -> V_58 ) {
case V_63 :
V_253 -> V_58 = V_151 ;
break;
case V_61 :
V_253 -> V_58 = V_152 ;
break;
case V_59 :
V_253 -> V_58 = V_251 ;
break;
default:
V_98 = - V_100 ;
goto V_304;
}
F_171 ( & V_253 -> V_48 , 1 ) ;
F_25 ( V_260 , & V_12 -> V_87 ) ;
if ( V_12 -> V_20 -> V_227 && ( V_98 = V_12 -> V_20 -> V_227 ( V_12 ) ) < 0 ) {
F_62 ( V_12 -> V_15 . V_73 , L_45 ) ;
goto V_305;
}
V_12 -> V_89 = 1 ;
if ( F_14 ( V_12 -> V_15 . V_73 )
&& F_14 ( & V_12 -> V_15 . V_47 -> V_48 ) )
F_15 ( V_12 -> V_15 . V_73 , L_46 ) ;
if ( F_149 ( V_12 ) ) {
V_98 = F_166 ( V_12 , V_293 , V_294 ) ;
if ( V_98 )
goto V_306;
}
V_12 -> V_256 = V_269 ;
V_98 = V_12 -> V_20 -> V_307 ( V_12 ) ;
if ( V_98 < 0 ) {
F_62 ( V_12 -> V_15 . V_73 , L_47 , V_98 ) ;
goto V_308;
}
V_253 -> V_309 = F_172 ( 500u , V_12 -> V_310 ) ;
if ( ( V_98 = F_56 ( V_12 ) ) != 0 )
goto V_311;
V_98 = F_173 ( & V_253 -> V_48 . V_312 , & V_313 ) ;
if ( V_98 < 0 ) {
F_48 ( V_129 L_48 ,
V_98 ) ;
goto V_314;
}
if ( V_12 -> V_90 && F_27 ( V_12 ) )
F_21 ( V_12 ) ;
return V_98 ;
V_314:
F_24 ( V_260 , & V_12 -> V_87 ) ;
if ( F_174 ( V_12 -> V_256 ) )
V_12 -> V_256 = V_261 ;
F_8 ( & V_38 ) ;
V_12 -> V_143 = 0 ;
F_10 ( & V_38 ) ;
#ifdef F_158
F_175 ( & V_12 -> V_272 ) ;
#endif
F_46 ( & V_126 ) ;
F_176 ( & V_253 ) ;
F_50 ( & V_126 ) ;
V_311:
V_12 -> V_89 = 0 ;
F_24 ( V_282 , & V_12 -> V_87 ) ;
F_177 ( & V_12 -> V_94 ) ;
V_12 -> V_20 -> V_315 ( V_12 ) ;
V_12 -> V_256 = V_316 ;
F_24 ( V_282 , & V_12 -> V_87 ) ;
F_177 ( & V_12 -> V_94 ) ;
V_308:
if ( F_149 ( V_12 ) && V_12 -> V_277 >= 0 )
F_178 ( V_293 , V_12 ) ;
V_306:
V_305:
V_304:
F_110 ( V_12 -> V_15 . V_47 ) ;
V_303:
F_53 ( & V_12 -> V_15 ) ;
V_302:
F_179 ( V_12 ) ;
return V_98 ;
}
void F_180 ( struct V_11 * V_12 )
{
struct V_1 * V_253 = V_12 -> V_15 . V_47 ;
F_52 ( V_12 -> V_15 . V_73 , L_49 , V_12 -> V_256 ) ;
F_109 ( V_253 ) ;
F_181 ( & V_253 -> V_48 . V_312 , & V_313 ) ;
F_24 ( V_260 , & V_12 -> V_87 ) ;
if ( F_174 ( V_12 -> V_256 ) )
V_12 -> V_256 = V_261 ;
F_15 ( V_12 -> V_15 . V_73 , L_50 ) ;
F_8 ( & V_38 ) ;
V_12 -> V_143 = 0 ;
F_10 ( & V_38 ) ;
#ifdef F_158
F_175 ( & V_12 -> V_272 ) ;
#endif
F_46 ( & V_126 ) ;
F_176 ( & V_253 ) ;
F_50 ( & V_126 ) ;
V_12 -> V_89 = 0 ;
F_24 ( V_282 , & V_12 -> V_87 ) ;
F_177 ( & V_12 -> V_94 ) ;
V_12 -> V_20 -> V_315 ( V_12 ) ;
V_12 -> V_256 = V_316 ;
F_24 ( V_282 , & V_12 -> V_87 ) ;
F_177 ( & V_12 -> V_94 ) ;
if ( F_149 ( V_12 ) ) {
if ( V_12 -> V_277 >= 0 )
F_178 ( V_12 -> V_277 , V_12 ) ;
}
F_110 ( V_12 -> V_15 . V_47 ) ;
F_53 ( & V_12 -> V_15 ) ;
F_179 ( V_12 ) ;
}
void
F_182 ( struct V_317 * V_48 )
{
struct V_11 * V_12 = F_183 ( V_48 ) ;
if ( V_12 -> V_20 -> V_318 )
V_12 -> V_20 -> V_318 ( V_12 ) ;
}
int F_184 ( struct V_319 * V_320 )
{
if ( V_321 )
return - V_165 ;
V_321 = V_320 ;
F_185 () ;
return 0 ;
}
void F_186 ( void )
{
if ( V_321 == NULL ) {
F_48 ( V_129 L_51 ) ;
return;
}
V_321 = NULL ;
F_185 () ;
}
