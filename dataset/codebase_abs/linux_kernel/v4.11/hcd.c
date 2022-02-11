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
if ( ! V_35 ) {
V_31 = - V_45 ;
goto V_46;
}
V_36 = V_35 ;
V_22 -> V_47 = 0 ;
switch ( V_25 ) {
case V_48 | V_49 :
V_35 [ 0 ] = ( F_13 ( & V_12 -> V_15 . V_50 -> V_51 )
<< V_52 )
| ( 1 << V_53 ) ;
V_35 [ 1 ] = 0 ;
V_6 = 2 ;
break;
case V_54 | V_55 :
if ( V_26 == V_52 )
F_14 ( & V_12 -> V_15 . V_50 -> V_51 , 0 ) ;
else
goto error;
break;
case V_54 | V_56 :
if ( F_15 ( & V_12 -> V_15 . V_50 -> V_51 )
&& V_26 == V_52 )
F_14 ( & V_12 -> V_15 . V_50 -> V_51 , 1 ) ;
else
goto error;
break;
case V_48 | V_57 :
V_35 [ 0 ] = 1 ;
V_6 = 1 ;
case V_54 | V_58 :
break;
case V_48 | V_59 :
switch ( V_26 & 0xff00 ) {
case V_60 << 8 :
switch ( V_12 -> V_61 ) {
case V_62 :
V_36 = V_63 ;
break;
case V_64 :
V_36 = V_65 ;
break;
case V_66 :
V_36 = V_67 ;
break;
case V_68 :
V_36 = V_69 ;
break;
case V_70 :
V_36 = V_71 ;
break;
default:
goto error;
}
V_6 = 18 ;
if ( V_12 -> V_72 )
V_33 = 1 ;
break;
case V_73 << 8 :
switch ( V_12 -> V_61 ) {
case V_62 :
case V_64 :
V_36 = V_74 ;
V_6 = sizeof V_74 ;
break;
case V_66 :
case V_68 :
V_36 = V_75 ;
V_6 = sizeof V_75 ;
break;
case V_70 :
V_36 = V_76 ;
V_6 = sizeof V_76 ;
break;
default:
goto error;
}
if ( F_15 ( & V_12 -> V_15 . V_50 -> V_51 ) )
V_32 = 1 ;
break;
case V_9 << 8 :
if ( ( V_26 & 0xff ) < 4 )
V_22 -> V_47 = F_3 ( V_26 & 0xff ,
V_12 , V_29 , V_28 ) ;
else
goto error;
break;
case V_77 << 8 :
goto V_78;
default:
goto error;
}
break;
case V_48 | V_79 :
V_35 [ 0 ] = 0 ;
V_6 = 1 ;
case V_54 | V_80 :
break;
case V_54 | V_81 :
F_16 ( V_12 -> V_15 . V_82 , L_2 ,
V_26 ) ;
break;
case V_83 | V_49 :
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_6 = 2 ;
case V_84 | V_55 :
case V_84 | V_56 :
F_16 ( V_12 -> V_15 . V_82 , L_3 ) ;
break;
default:
V_78:
switch ( V_25 ) {
case V_85 :
V_6 = 4 ;
break;
case V_86 :
if ( V_26 == V_87 )
V_6 = 4 ;
else
V_6 = 8 ;
break;
case V_88 :
V_6 = sizeof ( struct V_43 ) ;
break;
case V_48 | V_59 :
break;
}
V_31 = V_12 -> V_20 -> V_89 ( V_12 ,
V_25 , V_26 , V_27 ,
V_35 , V_28 ) ;
if ( V_25 == V_88 )
F_17 ( V_12 -> V_15 . V_50 ,
(struct V_43 * ) V_35 ) ;
break;
error:
V_31 = - V_90 ;
}
if ( V_31 < 0 ) {
V_6 = 0 ;
if ( V_31 != - V_90 ) {
F_16 ( V_12 -> V_15 . V_82 ,
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
V_22 -> V_47 = V_6 ;
memcpy ( V_29 , V_36 , V_6 ) ;
if ( V_32 &&
V_6 > F_18 ( struct V_91 ,
V_92 ) )
( (struct V_91 * ) V_29 ) -> V_92
|= V_93 ;
if ( V_33 &&
V_6 > F_18 ( struct V_94 ,
V_95 ) )
( (struct V_94 * ) V_29 ) ->
V_95 = V_96 ;
}
F_19 ( V_35 ) ;
V_46:
F_7 ( & V_37 ) ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , V_31 ) ;
F_9 ( & V_37 ) ;
return 0 ;
}
void F_22 ( struct V_11 * V_12 )
{
struct V_22 * V_22 ;
int V_97 ;
unsigned long V_98 ;
char V_99 [ 6 ] ;
if ( F_23 ( ! V_12 -> V_100 ) )
return;
if ( ! V_12 -> V_101 && ! V_12 -> V_102 )
return;
V_97 = V_12 -> V_20 -> V_103 ( V_12 , V_99 ) ;
if ( V_97 > 0 ) {
F_24 ( & V_37 , V_98 ) ;
V_22 = V_12 -> V_102 ;
if ( V_22 ) {
F_25 ( V_104 , & V_12 -> V_98 ) ;
V_12 -> V_102 = NULL ;
V_22 -> V_47 = V_97 ;
memcpy ( V_22 -> V_30 , V_99 , V_97 ) ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , 0 ) ;
} else {
V_97 = 0 ;
F_26 ( V_104 , & V_12 -> V_98 ) ;
}
F_27 ( & V_37 , V_98 ) ;
}
if ( V_12 -> V_101 ? F_28 ( V_12 ) :
( V_97 == 0 && V_12 -> V_102 != NULL ) )
F_29 ( & V_12 -> V_105 , ( V_106 / ( V_107 / 4 ) + 1 ) * ( V_107 / 4 ) ) ;
}
static void F_30 ( unsigned long V_108 )
{
F_22 ( (struct V_11 * ) V_108 ) ;
}
static int F_31 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_109 ;
unsigned long V_98 ;
unsigned V_6 = 1 + ( V_22 -> V_51 -> V_110 / 8 ) ;
F_24 ( & V_37 , V_98 ) ;
if ( V_12 -> V_102 || V_22 -> V_42 < V_6 ) {
F_16 ( V_12 -> V_15 . V_82 , L_6 ) ;
V_109 = - V_111 ;
goto V_112;
}
V_109 = F_8 ( V_12 , V_22 ) ;
if ( V_109 )
goto V_112;
V_12 -> V_102 = V_22 ;
V_22 -> V_38 = V_12 ;
if ( ! V_12 -> V_101 )
F_29 ( & V_12 -> V_105 , ( V_106 / ( V_107 / 4 ) + 1 ) * ( V_107 / 4 ) ) ;
else if ( F_32 ( V_12 ) )
F_29 ( & V_12 -> V_105 , V_106 ) ;
V_109 = 0 ;
V_112:
F_27 ( & V_37 , V_98 ) ;
return V_109 ;
}
static int F_33 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_34 ( & V_22 -> V_113 -> V_114 ) )
return F_31 ( V_12 , V_22 ) ;
if ( F_35 ( & V_22 -> V_113 -> V_114 ) )
return F_5 ( V_12 , V_22 ) ;
return - V_111 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
unsigned long V_98 ;
int V_115 ;
F_24 ( & V_37 , V_98 ) ;
V_115 = F_37 ( V_12 , V_22 , V_31 ) ;
if ( V_115 )
goto V_112;
if ( F_38 ( & V_22 -> V_113 -> V_114 ) == 0 ) {
;
} else {
if ( ! V_12 -> V_101 )
F_39 ( & V_12 -> V_105 ) ;
if ( V_22 == V_12 -> V_102 ) {
V_12 -> V_102 = NULL ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , V_31 ) ;
}
}
V_112:
F_27 ( & V_37 , V_98 ) ;
return V_115 ;
}
static T_3 F_40 ( struct V_116 * V_51 ,
struct V_117 * V_118 , char * V_5 )
{
struct V_1 * V_119 = F_41 ( V_51 ) ;
struct V_120 * V_120 = V_119 -> V_121 ;
struct V_11 * V_12 ;
V_12 = F_42 ( V_120 ) ;
return snprintf ( V_5 , V_122 , L_7 , ! ! F_43 ( V_12 ) ) ;
}
static T_3 F_44 ( struct V_116 * V_51 ,
struct V_117 * V_118 ,
const char * V_5 , T_4 V_123 )
{
T_3 V_124 ;
unsigned V_125 ;
struct V_1 * V_119 = F_41 ( V_51 ) ;
struct V_120 * V_120 = V_119 -> V_121 ;
struct V_11 * V_12 ;
V_12 = F_42 ( V_120 ) ;
V_124 = sscanf ( V_5 , L_7 , & V_125 ) ;
if ( V_124 == 1 ) {
if ( V_125 )
F_26 ( V_126 , & V_12 -> V_98 ) ;
else
F_25 ( V_126 , & V_12 -> V_98 ) ;
V_124 = V_123 ;
} else {
V_124 = - V_111 ;
}
return V_124 ;
}
static T_3 F_45 ( struct V_116 * V_51 ,
struct V_117 * V_118 , char * V_5 )
{
struct V_1 * V_127 = F_41 ( V_51 ) ;
struct V_11 * V_12 = F_42 ( V_127 -> V_121 ) ;
return sprintf ( V_5 , L_7 , ! ! F_46 ( V_12 ) ) ;
}
static T_3 F_47 ( struct V_116 * V_51 ,
struct V_117 * V_118 , const char * V_5 , T_4 V_128 )
{
struct V_1 * V_127 = F_41 ( V_51 ) ;
struct V_11 * V_12 = F_42 ( V_127 -> V_121 ) ;
int V_115 = V_128 ;
bool V_125 ;
if ( F_48 ( V_5 , & V_125 ) != 0 )
return - V_111 ;
if ( V_125 )
F_26 ( V_129 , & V_12 -> V_98 ) ;
else
F_25 ( V_129 , & V_12 -> V_98 ) ;
return V_115 ;
}
static void F_49 ( struct V_120 * V_121 )
{
memset ( & V_121 -> V_130 , 0 , sizeof( struct V_131 ) ) ;
V_121 -> V_132 = 1 ;
V_121 -> V_50 = NULL ;
V_121 -> V_133 = - 1 ;
V_121 -> V_134 = 0 ;
V_121 -> V_135 = 0 ;
V_121 -> V_136 = 0 ;
F_50 ( & V_121 -> V_137 ) ;
}
static int F_51 ( struct V_120 * V_121 )
{
int V_124 = - V_138 ;
int V_133 ;
F_52 ( & V_139 ) ;
V_133 = F_53 ( & V_140 , V_121 , 1 , V_141 , V_44 ) ;
if ( V_133 < 0 ) {
F_54 ( L_8 , V_142 ) ;
goto V_143;
}
V_121 -> V_133 = V_133 ;
F_55 ( & V_139 ) ;
F_56 ( V_121 ) ;
F_57 ( V_121 -> V_82 , L_9
L_10 , V_121 -> V_133 ) ;
return 0 ;
V_143:
F_55 ( & V_139 ) ;
return V_124 ;
}
static void F_58 ( struct V_120 * V_121 )
{
F_57 ( V_121 -> V_82 , L_11 , V_121 -> V_133 ) ;
F_52 ( & V_139 ) ;
F_59 ( & V_140 , V_121 -> V_133 ) ;
F_55 ( & V_139 ) ;
F_60 ( V_121 ) ;
}
static int F_61 ( struct V_11 * V_12 )
{
struct V_116 * V_144 = V_12 -> V_15 . V_82 ;
struct V_1 * V_127 = V_12 -> V_15 . V_50 ;
const int V_145 = 1 ;
int V_109 ;
V_127 -> V_145 = V_145 ;
V_127 -> V_121 -> V_132 = V_145 + 1 ;
memset ( & V_127 -> V_121 -> V_130 . V_146 , 0 ,
sizeof V_127 -> V_121 -> V_130 . V_146 ) ;
F_26 ( V_145 , V_127 -> V_121 -> V_130 . V_146 ) ;
F_62 ( V_127 , V_147 ) ;
F_52 ( & V_139 ) ;
V_127 -> V_148 . V_114 . V_149 = F_63 ( 64 ) ;
V_109 = F_64 ( V_127 , V_150 ) ;
if ( V_109 != sizeof V_127 -> V_151 ) {
F_55 ( & V_139 ) ;
F_16 ( V_144 , L_12 ,
F_65 ( & V_127 -> V_51 ) , V_109 ) ;
return ( V_109 < 0 ) ? V_109 : - V_152 ;
}
if ( F_10 ( V_127 -> V_151 . V_153 ) >= 0x0201 ) {
V_109 = F_66 ( V_127 ) ;
if ( ! V_109 ) {
V_127 -> V_154 = F_67 ( V_127 ) ;
} else if ( V_127 -> V_61 >= V_155 ) {
F_55 ( & V_139 ) ;
F_16 ( V_144 , L_13 ,
F_65 ( & V_127 -> V_51 ) , V_109 ) ;
return V_109 ;
}
}
V_109 = F_68 ( V_127 ) ;
if ( V_109 ) {
F_69 ( V_144 , L_14 ,
F_65 ( & V_127 -> V_51 ) , V_109 ) ;
} else {
F_7 ( & V_37 ) ;
V_12 -> V_156 = 1 ;
F_9 ( & V_37 ) ;
if ( F_70 ( V_12 ) )
F_71 ( V_12 ) ;
V_127 -> V_51 . V_157 = V_144 -> V_157 ;
}
F_55 ( & V_139 ) ;
return V_109 ;
}
void F_72 ( struct V_120 * V_121 , int V_158 )
{
unsigned V_159 = 1 << V_158 ;
if ( ! ( V_121 -> V_160 & V_159 ) ) {
V_121 -> V_160 |= V_159 ;
F_73 ( & V_121 -> V_50 -> V_51 ) ;
}
}
void F_74 ( struct V_120 * V_121 , int V_158 )
{
unsigned V_159 = 1 << V_158 ;
if ( V_121 -> V_160 & V_159 ) {
V_121 -> V_160 &= ~ V_159 ;
F_75 ( & V_121 -> V_50 -> V_51 ) ;
}
}
long F_76 ( int V_61 , int V_161 , int V_162 , int V_163 )
{
unsigned long V_164 ;
switch ( V_61 ) {
case V_165 :
if ( V_161 ) {
V_164 = ( 67667L * ( 31L + 10L * F_77 ( V_163 ) ) ) / 1000L ;
return 64060L + ( 2 * V_166 ) + V_167 + V_164 ;
} else {
V_164 = ( 66700L * ( 31L + 10L * F_77 ( V_163 ) ) ) / 1000L ;
return 64107L + ( 2 * V_166 ) + V_167 + V_164 ;
}
case V_168 :
if ( V_162 ) {
V_164 = ( 8354L * ( 31L + 10L * F_77 ( V_163 ) ) ) / 1000L ;
return ( ( V_161 ) ? 7268L : 6265L ) + V_167 + V_164 ;
} else {
V_164 = ( 8354L * ( 31L + 10L * F_77 ( V_163 ) ) ) / 1000L ;
return 9107L + V_167 + V_164 ;
}
case V_169 :
if ( V_162 )
V_164 = F_78 ( V_163 ) ;
else
V_164 = F_79 ( V_163 ) ;
return V_164 ;
default:
F_80 ( L_15 , V_142 ) ;
return - 1 ;
}
}
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_115 = 0 ;
F_81 ( & V_170 ) ;
if ( F_23 ( F_82 ( & V_22 -> V_171 ) ) ) {
V_115 = - V_172 ;
goto V_112;
}
if ( F_23 ( ! V_22 -> V_113 -> V_173 ) ) {
V_115 = - V_174 ;
goto V_112;
}
if ( F_23 ( ! V_22 -> V_51 -> V_175 ) ) {
V_115 = - V_176 ;
goto V_112;
}
if ( F_83 ( V_12 ) ) {
V_22 -> V_177 = 0 ;
F_84 ( & V_22 -> V_178 , & V_22 -> V_113 -> V_178 ) ;
} else {
V_115 = - V_179 ;
goto V_112;
}
V_112:
F_85 ( & V_170 ) ;
return V_115 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_180 * V_164 ;
F_86 (tmp, &urb->ep->urb_list) {
if ( V_164 == & V_22 -> V_178 )
break;
}
if ( V_164 != & V_22 -> V_178 )
return - V_181 ;
if ( V_22 -> V_177 )
return - V_182 ;
V_22 -> V_177 = V_31 ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_81 ( & V_170 ) ;
F_87 ( & V_22 -> V_178 ) ;
F_85 ( & V_170 ) ;
}
static int F_88 ( struct V_120 * V_121 ,
T_5 V_183 , T_6 * V_184 ,
void * * V_185 , T_4 V_123 ,
enum V_186 V_187 )
{
unsigned char * V_188 ;
if ( * V_185 == NULL ) {
F_89 ( 1 ) ;
return - V_189 ;
}
V_188 = F_90 ( V_121 , V_123 + sizeof( V_188 ) ,
V_183 , V_184 ) ;
if ( ! V_188 )
return - V_45 ;
F_91 ( ( unsigned long ) * V_185 ,
( unsigned long * ) ( V_188 + V_123 ) ) ;
if ( V_187 == V_190 )
memcpy ( V_188 , * V_185 , V_123 ) ;
* V_185 = V_188 ;
return 0 ;
}
static void F_92 ( struct V_120 * V_121 , T_6 * V_184 ,
void * * V_185 , T_4 V_123 ,
enum V_186 V_187 )
{
unsigned char * V_188 = * V_185 ;
V_188 = ( void * ) F_93 ( ( unsigned long * ) ( V_188 + V_123 ) ) ;
if ( V_187 == V_191 )
memcpy ( V_188 , * V_185 , V_123 ) ;
F_94 ( V_121 , V_123 + sizeof( V_188 ) , * V_185 , * V_184 ) ;
* V_185 = V_188 ;
* V_184 = 0 ;
}
void F_95 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_96 ( V_192 ) &&
( V_22 -> V_193 & V_194 ) )
F_97 ( V_12 -> V_15 . V_82 ,
V_22 -> V_195 ,
sizeof( struct V_23 ) ,
V_190 ) ;
else if ( V_22 -> V_193 & V_196 )
F_92 ( V_22 -> V_51 -> V_121 ,
& V_22 -> V_195 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_190 ) ;
V_22 -> V_193 &= ~ ( V_194 | V_196 ) ;
}
static void F_98 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_98 )
V_12 -> V_20 -> F_98 ( V_12 , V_22 ) ;
else
F_99 ( V_12 , V_22 ) ;
}
void F_99 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_186 V_187 ;
F_95 ( V_12 , V_22 ) ;
V_187 = F_100 ( V_22 ) ? V_191 : V_190 ;
if ( F_96 ( V_192 ) &&
( V_22 -> V_193 & V_197 ) )
F_101 ( V_12 -> V_15 . V_82 ,
V_22 -> V_198 ,
V_22 -> V_199 ,
V_187 ) ;
else if ( F_96 ( V_192 ) &&
( V_22 -> V_193 & V_200 ) )
F_102 ( V_12 -> V_15 . V_82 ,
V_22 -> V_201 ,
V_22 -> V_42 ,
V_187 ) ;
else if ( F_96 ( V_192 ) &&
( V_22 -> V_193 & V_202 ) )
F_97 ( V_12 -> V_15 . V_82 ,
V_22 -> V_201 ,
V_22 -> V_42 ,
V_187 ) ;
else if ( V_22 -> V_193 & V_203 )
F_92 ( V_22 -> V_51 -> V_121 ,
& V_22 -> V_201 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_187 ) ;
V_22 -> V_193 &= ~ ( V_197 | V_200 |
V_202 | V_203 ) ;
}
static int F_103 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_183 )
{
if ( V_12 -> V_20 -> F_103 )
return V_12 -> V_20 -> F_103 ( V_12 , V_22 , V_183 ) ;
else
return F_104 ( V_12 , V_22 , V_183 ) ;
}
int F_104 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_183 )
{
enum V_186 V_187 ;
int V_204 = 0 ;
if ( F_35 ( & V_22 -> V_113 -> V_114 ) ) {
if ( V_12 -> V_15 . V_205 )
return V_204 ;
if ( F_96 ( V_192 ) && V_12 -> V_15 . V_206 ) {
V_22 -> V_195 = F_105 (
V_12 -> V_15 . V_82 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_190 ) ;
if ( F_106 ( V_12 -> V_15 . V_82 ,
V_22 -> V_195 ) )
return - V_207 ;
V_22 -> V_193 |= V_194 ;
} else if ( V_12 -> V_20 -> V_98 & V_208 ) {
V_204 = F_88 (
V_22 -> V_51 -> V_121 , V_183 ,
& V_22 -> V_195 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_190 ) ;
if ( V_204 )
return V_204 ;
V_22 -> V_193 |= V_196 ;
}
}
V_187 = F_100 ( V_22 ) ? V_191 : V_190 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_193 & V_209 ) ) {
if ( F_96 ( V_192 ) && V_12 -> V_15 . V_206 ) {
if ( V_22 -> V_199 ) {
int V_7 ;
if ( F_107 ( & V_22 -> V_113 -> V_114 ) ) {
F_108 ( 1 ) ;
return - V_111 ;
}
V_7 = F_109 (
V_12 -> V_15 . V_82 ,
V_22 -> V_198 ,
V_22 -> V_199 ,
V_187 ) ;
if ( V_7 <= 0 )
V_204 = - V_207 ;
else
V_22 -> V_193 |= V_197 ;
V_22 -> V_210 = V_7 ;
if ( V_7 != V_22 -> V_199 )
V_22 -> V_193 |=
V_211 ;
} else if ( V_22 -> V_198 ) {
struct V_212 * V_198 = V_22 -> V_198 ;
V_22 -> V_201 = F_110 (
V_12 -> V_15 . V_82 ,
F_111 ( V_198 ) ,
V_198 -> V_213 ,
V_22 -> V_42 ,
V_187 ) ;
if ( F_106 ( V_12 -> V_15 . V_82 ,
V_22 -> V_201 ) )
V_204 = - V_207 ;
else
V_22 -> V_193 |= V_200 ;
} else if ( F_112 ( V_22 -> V_30 ) ) {
F_113 ( 1 , L_16 ) ;
V_204 = - V_207 ;
} else {
V_22 -> V_201 = F_105 (
V_12 -> V_15 . V_82 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_187 ) ;
if ( F_106 ( V_12 -> V_15 . V_82 ,
V_22 -> V_201 ) )
V_204 = - V_207 ;
else
V_22 -> V_193 |= V_202 ;
}
} else if ( V_12 -> V_20 -> V_98 & V_208 ) {
V_204 = F_88 (
V_22 -> V_51 -> V_121 , V_183 ,
& V_22 -> V_201 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_187 ) ;
if ( V_204 == 0 )
V_22 -> V_193 |= V_203 ;
}
if ( V_204 && ( V_22 -> V_193 & ( V_194 |
V_196 ) ) )
F_99 ( V_12 , V_22 ) ;
}
return V_204 ;
}
int F_114 ( struct V_22 * V_22 , T_5 V_183 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_51 -> V_121 ) ;
F_115 ( V_22 ) ;
F_116 ( & V_22 -> V_214 ) ;
F_116 ( & V_22 -> V_51 -> V_215 ) ;
F_117 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_51 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_103 ( V_12 , V_22 , V_183 ) ;
if ( F_118 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_216 ( V_12 , V_22 , V_183 ) ;
if ( F_23 ( V_31 ) )
F_98 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_119 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_120 ( & V_22 -> V_178 ) ;
F_121 ( & V_22 -> V_214 ) ;
F_121 ( & V_22 -> V_51 -> V_215 ) ;
if ( F_82 ( & V_22 -> V_171 ) )
F_122 ( & V_217 ) ;
F_123 ( V_22 ) ;
}
return V_31 ;
}
static int F_124 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_218 ;
if ( F_1 ( V_22 -> V_51 ) )
V_218 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_218 = V_12 -> V_20 -> V_219 ( V_12 , V_22 , V_31 ) ;
}
return V_218 ;
}
int F_125 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_22 -> V_51 ;
int V_109 = - V_181 ;
unsigned long V_98 ;
F_24 ( & V_220 , V_98 ) ;
if ( F_82 ( & V_22 -> V_214 ) > 0 ) {
V_109 = 0 ;
F_126 ( V_2 ) ;
}
F_27 ( & V_220 , V_98 ) ;
if ( V_109 == 0 ) {
V_12 = F_42 ( V_22 -> V_51 -> V_121 ) ;
V_109 = F_124 ( V_12 , V_22 , V_31 ) ;
if ( V_109 == 0 )
V_109 = - V_221 ;
else if ( V_109 != - V_181 && V_109 != - V_182 )
F_16 ( & V_2 -> V_51 , L_17 ,
V_22 , V_109 ) ;
F_127 ( V_2 ) ;
}
return V_109 ;
}
static void F_128 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_51 -> V_121 ) ;
struct V_222 * V_223 = V_22 -> V_223 ;
int V_31 = V_22 -> V_177 ;
unsigned long V_98 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_193 & V_224 ) &&
V_22 -> V_47 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_225 ;
F_98 ( V_12 , V_22 ) ;
F_129 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_130 ( V_223 ) ;
F_131 ( V_22 ) ;
if ( F_118 ( V_31 == 0 ) )
F_132 ( V_226 ) ;
V_22 -> V_31 = V_31 ;
F_133 ( V_98 ) ;
V_22 -> V_227 ( V_22 ) ;
F_134 ( V_98 ) ;
F_135 ( V_223 ) ;
F_121 ( & V_22 -> V_214 ) ;
if ( F_23 ( F_82 ( & V_22 -> V_171 ) ) )
F_122 ( & V_217 ) ;
F_123 ( V_22 ) ;
}
static void F_136 ( unsigned long V_228 )
{
struct V_229 * V_230 = (struct V_229 * ) V_228 ;
struct V_180 V_231 ;
F_7 ( & V_230 -> V_232 ) ;
V_230 -> V_233 = true ;
V_234:
F_137 ( & V_230 -> V_235 , & V_231 ) ;
F_9 ( & V_230 -> V_232 ) ;
while ( ! F_138 ( & V_231 ) ) {
struct V_22 * V_22 ;
V_22 = F_139 ( V_231 . V_236 , struct V_22 , V_178 ) ;
F_87 ( & V_22 -> V_178 ) ;
V_230 -> V_237 = V_22 -> V_113 ;
F_128 ( V_22 ) ;
V_230 -> V_237 = NULL ;
}
F_7 ( & V_230 -> V_232 ) ;
if ( ! F_138 ( & V_230 -> V_235 ) )
goto V_234;
V_230 -> V_233 = false ;
F_9 ( & V_230 -> V_232 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_229 * V_230 ;
bool V_233 , V_238 ;
if ( F_118 ( ! V_22 -> V_177 ) )
V_22 -> V_177 = V_31 ;
if ( ! F_140 ( V_12 ) && ! F_1 ( V_22 -> V_51 ) ) {
F_128 ( V_22 ) ;
return;
}
if ( F_141 ( V_22 -> V_239 ) || F_142 ( V_22 -> V_239 ) ) {
V_230 = & V_12 -> V_238 ;
V_238 = true ;
} else {
V_230 = & V_12 -> V_240 ;
V_238 = false ;
}
F_81 ( & V_230 -> V_232 ) ;
F_84 ( & V_22 -> V_178 , & V_230 -> V_235 ) ;
V_233 = V_230 -> V_233 ;
F_85 ( & V_230 -> V_232 ) ;
if ( V_233 )
;
else if ( V_238 )
F_143 ( & V_230 -> V_230 ) ;
else
F_144 ( & V_230 -> V_230 ) ;
}
void F_145 ( struct V_1 * V_2 ,
struct V_241 * V_113 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_113 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_121 ) ;
F_7 ( & V_170 ) ;
V_242:
F_146 (urb, &ep->urb_list, urb_list) {
int V_243 ;
if ( V_22 -> V_177 )
continue;
F_115 ( V_22 ) ;
V_243 = F_100 ( V_22 ) ;
F_85 ( & V_170 ) ;
F_124 ( V_12 , V_22 , - V_179 ) ;
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
F_123 ( V_22 ) ;
F_81 ( & V_170 ) ;
goto V_242;
}
F_9 ( & V_170 ) ;
while ( ! F_138 ( & V_113 -> V_178 ) ) {
F_7 ( & V_170 ) ;
V_22 = NULL ;
if ( ! F_138 ( & V_113 -> V_178 ) ) {
V_22 = F_139 ( V_113 -> V_178 . V_244 , struct V_22 ,
V_178 ) ;
F_115 ( V_22 ) ;
}
F_9 ( & V_170 ) ;
if ( V_22 ) {
F_147 ( V_22 ) ;
F_123 ( V_22 ) ;
}
}
}
int F_148 ( struct V_1 * V_2 ,
struct V_245 * V_246 ,
struct V_247 * V_248 ,
struct V_247 * V_249 )
{
int V_250 , V_251 , V_252 ;
struct V_247 * V_253 = NULL ;
int V_204 = 0 ;
struct V_11 * V_12 ;
struct V_241 * V_113 ;
V_12 = F_42 ( V_2 -> V_121 ) ;
if ( ! V_12 -> V_20 -> V_254 )
return 0 ;
if ( ! V_246 && ! V_248 ) {
for ( V_251 = 1 ; V_251 < 16 ; ++ V_251 ) {
V_113 = V_2 -> V_255 [ V_251 ] ;
if ( V_113 )
V_12 -> V_20 -> V_256 ( V_12 , V_2 , V_113 ) ;
V_113 = V_2 -> V_257 [ V_251 ] ;
if ( V_113 )
V_12 -> V_20 -> V_256 ( V_12 , V_2 , V_113 ) ;
}
V_12 -> V_20 -> V_254 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_246 ) {
V_250 = V_246 -> V_114 . V_258 ;
for ( V_251 = 1 ; V_251 < 16 ; ++ V_251 ) {
V_113 = V_2 -> V_255 [ V_251 ] ;
if ( V_113 ) {
V_204 = V_12 -> V_20 -> V_256 ( V_12 , V_2 , V_113 ) ;
if ( V_204 < 0 )
goto V_259;
}
V_113 = V_2 -> V_257 [ V_251 ] ;
if ( V_113 ) {
V_204 = V_12 -> V_20 -> V_256 ( V_12 , V_2 , V_113 ) ;
if ( V_204 < 0 )
goto V_259;
}
}
for ( V_251 = 0 ; V_251 < V_250 ; ++ V_251 ) {
struct V_247 * V_260 ;
int V_261 ;
V_260 = & V_246 -> V_262 [ V_251 ] -> V_263 [ 0 ] ;
V_261 = V_260 -> V_114 . V_264 ;
V_253 = F_149 ( V_246 , V_261 , 0 ) ;
if ( ! V_253 )
V_253 = V_260 ;
for ( V_252 = 0 ; V_252 < V_253 -> V_114 . V_265 ; V_252 ++ ) {
V_204 = V_12 -> V_20 -> V_266 ( V_12 , V_2 , & V_253 -> V_267 [ V_252 ] ) ;
if ( V_204 < 0 )
goto V_259;
}
}
}
if ( V_248 && V_249 ) {
struct V_268 * V_269 = F_150 ( V_2 ,
V_248 -> V_114 . V_264 ) ;
if ( ! V_269 )
return - V_111 ;
if ( V_269 -> V_270 ) {
V_248 = F_151 ( V_269 , 0 ) ;
if ( ! V_248 )
V_248 = & V_269 -> V_263 [ 0 ] ;
}
for ( V_251 = 0 ; V_251 < V_248 -> V_114 . V_265 ; V_251 ++ ) {
V_204 = V_12 -> V_20 -> V_256 ( V_12 , V_2 ,
& V_248 -> V_267 [ V_251 ] ) ;
if ( V_204 < 0 )
goto V_259;
}
for ( V_251 = 0 ; V_251 < V_249 -> V_114 . V_265 ; V_251 ++ ) {
V_204 = V_12 -> V_20 -> V_266 ( V_12 , V_2 ,
& V_249 -> V_267 [ V_251 ] ) ;
if ( V_204 < 0 )
goto V_259;
}
}
V_204 = V_12 -> V_20 -> V_254 ( V_12 , V_2 ) ;
V_259:
if ( V_204 < 0 )
V_12 -> V_20 -> V_271 ( V_12 , V_2 ) ;
return V_204 ;
}
void F_152 ( struct V_1 * V_2 ,
struct V_241 * V_113 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_121 ) ;
if ( V_12 -> V_20 -> V_272 )
V_12 -> V_20 -> V_272 ( V_12 , V_113 ) ;
}
void F_153 ( struct V_1 * V_2 ,
struct V_241 * V_113 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_121 ) ;
if ( V_12 -> V_20 -> V_273 )
V_12 -> V_20 -> V_273 ( V_12 , V_113 ) ;
else {
int V_274 = F_38 ( & V_113 -> V_114 ) ;
int V_275 = F_154 ( & V_113 -> V_114 ) ;
int V_276 = F_35 ( & V_113 -> V_114 ) ;
F_155 ( V_2 , V_274 , V_275 , 0 ) ;
if ( V_276 )
F_155 ( V_2 , V_274 , ! V_275 , 0 ) ;
}
}
int F_156 ( struct V_268 * V_277 ,
struct V_241 * * V_278 , unsigned int V_279 ,
unsigned int V_280 , T_5 V_183 )
{
struct V_11 * V_12 ;
struct V_1 * V_51 ;
int V_251 , V_204 ;
V_51 = F_157 ( V_277 ) ;
V_12 = F_42 ( V_51 -> V_121 ) ;
if ( ! V_12 -> V_20 -> V_281 || ! V_12 -> V_20 -> V_282 )
return - V_111 ;
if ( V_51 -> V_61 < V_155 )
return - V_111 ;
if ( V_51 -> V_283 < V_284 )
return - V_285 ;
for ( V_251 = 0 ; V_251 < V_279 ; V_251 ++ ) {
if ( ! F_158 ( & V_278 [ V_251 ] -> V_114 ) )
return - V_111 ;
if ( V_278 [ V_251 ] -> V_286 )
return - V_111 ;
}
V_204 = V_12 -> V_20 -> V_281 ( V_12 , V_51 , V_278 , V_279 ,
V_280 , V_183 ) ;
if ( V_204 < 0 )
return V_204 ;
for ( V_251 = 0 ; V_251 < V_279 ; V_251 ++ )
V_278 [ V_251 ] -> V_286 = V_204 ;
return V_204 ;
}
int F_159 ( struct V_268 * V_277 ,
struct V_241 * * V_278 , unsigned int V_279 ,
T_5 V_183 )
{
struct V_11 * V_12 ;
struct V_1 * V_51 ;
int V_251 , V_204 ;
V_51 = F_157 ( V_277 ) ;
V_12 = F_42 ( V_51 -> V_121 ) ;
if ( V_51 -> V_61 < V_155 )
return - V_111 ;
for ( V_251 = 0 ; V_251 < V_279 ; V_251 ++ )
if ( ! V_278 [ V_251 ] || ! V_278 [ V_251 ] -> V_286 )
return - V_111 ;
V_204 = V_12 -> V_20 -> V_282 ( V_12 , V_51 , V_278 , V_279 , V_183 ) ;
if ( V_204 < 0 )
return V_204 ;
for ( V_251 = 0 ; V_251 < V_279 ; V_251 ++ )
V_278 [ V_251 ] -> V_286 = 0 ;
return V_204 ;
}
void F_160 ( struct V_1 * V_2 )
{
F_7 ( & V_220 ) ;
F_9 ( & V_220 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_121 ) ;
if ( ! F_83 ( V_12 ) )
return - V_179 ;
return V_12 -> V_20 -> V_287 ( V_12 ) ;
}
int F_162 ( struct V_1 * V_288 , T_7 V_289 )
{
struct V_11 * V_12 = F_42 ( V_288 -> V_121 ) ;
int V_31 ;
int V_290 = V_12 -> V_283 ;
F_16 ( & V_288 -> V_51 , L_25 ,
( F_163 ( V_289 ) ? L_26 : L_21 ) ,
V_288 -> V_291 ) ;
if ( F_70 ( V_12 ) ) {
F_16 ( & V_288 -> V_51 , L_27 , L_28 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_292 ) {
V_31 = - V_174 ;
} else {
F_25 ( V_293 , & V_12 -> V_98 ) ;
V_12 -> V_283 = V_294 ;
V_31 = V_12 -> V_20 -> V_292 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_62 ( V_288 , V_295 ) ;
V_12 -> V_283 = V_296 ;
if ( V_288 -> V_291 ) {
char V_99 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_103 ( V_12 , V_99 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_288 -> V_51 , L_29 ) ;
F_164 ( V_288 , V_297 ) ;
V_31 = - V_182 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_70 ( V_12 ) ) {
F_26 ( V_293 , & V_12 -> V_98 ) ;
V_12 -> V_283 = V_290 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_288 -> V_51 , L_30 ,
L_28 , V_31 ) ;
}
return V_31 ;
}
int F_164 ( struct V_1 * V_288 , T_7 V_289 )
{
struct V_11 * V_12 = F_42 ( V_288 -> V_121 ) ;
int V_31 ;
int V_290 = V_12 -> V_283 ;
F_16 ( & V_288 -> V_51 , L_31 ,
( F_163 ( V_289 ) ? L_26 : L_21 ) ) ;
if ( F_70 ( V_12 ) ) {
F_16 ( & V_288 -> V_51 , L_27 , L_32 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_298 )
return - V_174 ;
if ( F_83 ( V_12 ) )
return 0 ;
V_12 -> V_283 = V_299 ;
V_31 = V_12 -> V_20 -> V_298 ( V_12 ) ;
F_25 ( V_300 , & V_12 -> V_98 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_301 ;
F_7 ( & V_37 ) ;
if ( ! F_70 ( V_12 ) ) {
F_62 ( V_288 , V_288 -> V_302
? V_284
: V_147 ) ;
F_26 ( V_293 , & V_12 -> V_98 ) ;
V_12 -> V_283 = V_303 ;
}
F_9 ( & V_37 ) ;
F_165 (rhdev, port1, udev) {
if ( V_2 -> V_283 != V_304 &&
! V_2 -> V_305 ) {
F_166 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_283 = V_290 ;
F_16 ( & V_288 -> V_51 , L_30 ,
L_32 , V_31 ) ;
if ( V_31 != - V_179 )
F_71 ( V_12 ) ;
}
return V_31 ;
}
static void F_167 ( struct V_306 * V_307 )
{
struct V_11 * V_12 = F_168 ( V_307 , struct V_11 , V_308 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_50 ;
F_169 ( V_2 ) ;
}
void F_170 ( struct V_11 * V_12 )
{
unsigned long V_98 ;
F_24 ( & V_37 , V_98 ) ;
if ( V_12 -> V_156 ) {
F_26 ( V_300 , & V_12 -> V_98 ) ;
F_171 ( V_309 , & V_12 -> V_308 ) ;
}
F_27 ( & V_37 , V_98 ) ;
}
int F_172 ( struct V_120 * V_121 , unsigned V_310 )
{
struct V_11 * V_12 ;
int V_31 = - V_311 ;
V_12 = F_42 ( V_121 ) ;
if ( V_310 && V_12 -> V_20 -> V_312 )
V_31 = V_12 -> V_20 -> V_312 ( V_12 , V_310 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_105 , V_106 + F_173 ( 10 ) ) ;
return V_31 ;
}
T_8 F_174 ( int V_313 , void * V_314 )
{
struct V_11 * V_12 = V_314 ;
T_8 V_115 ;
if ( F_23 ( F_70 ( V_12 ) || ! F_175 ( V_12 ) ) )
V_115 = V_315 ;
else if ( V_12 -> V_20 -> V_313 ( V_12 ) == V_315 )
V_115 = V_315 ;
else
V_115 = V_316 ;
return V_115 ;
}
void F_71 ( struct V_11 * V_12 )
{
unsigned long V_98 ;
F_69 ( V_12 -> V_15 . V_82 , L_33 ) ;
F_24 ( & V_37 , V_98 ) ;
F_25 ( V_293 , & V_12 -> V_98 ) ;
F_26 ( V_317 , & V_12 -> V_98 ) ;
if ( V_12 -> V_156 ) {
F_25 ( V_318 , & V_12 -> V_98 ) ;
F_62 ( V_12 -> V_15 . V_50 ,
V_304 ) ;
F_176 ( V_12 -> V_15 . V_50 ) ;
}
if ( F_177 ( V_12 ) && V_12 -> V_319 ) {
V_12 = V_12 -> V_319 ;
if ( V_12 -> V_156 ) {
F_25 ( V_318 , & V_12 -> V_98 ) ;
F_62 ( V_12 -> V_15 . V_50 ,
V_304 ) ;
F_176 ( V_12 -> V_15 . V_50 ) ;
}
}
F_27 ( & V_37 , V_98 ) ;
}
static void F_178 ( struct V_229 * V_230 )
{
F_179 ( & V_230 -> V_232 ) ;
F_120 ( & V_230 -> V_235 ) ;
F_180 ( & V_230 -> V_230 , F_136 , ( unsigned long ) V_230 ) ;
}
struct V_11 * F_181 ( const struct V_320 * V_20 ,
struct V_116 * V_51 , const char * V_16 ,
struct V_11 * V_321 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_322 , V_44 ) ;
if ( ! V_12 )
return NULL ;
if ( V_321 == NULL ) {
V_12 -> V_323 = F_182 ( sizeof( * V_12 -> V_323 ) ,
V_44 ) ;
if ( ! V_12 -> V_323 ) {
F_19 ( V_12 ) ;
F_16 ( V_51 , L_34 ) ;
return NULL ;
}
F_50 ( V_12 -> V_323 ) ;
V_12 -> V_324 = F_182 ( sizeof( * V_12 -> V_324 ) ,
V_44 ) ;
if ( ! V_12 -> V_324 ) {
F_19 ( V_12 ) ;
F_16 ( V_51 , L_35 ) ;
return NULL ;
}
F_50 ( V_12 -> V_324 ) ;
F_183 ( V_51 , V_12 ) ;
} else {
F_52 ( & V_325 ) ;
V_12 -> V_323 = V_321 -> V_323 ;
V_12 -> V_324 = V_321 -> V_324 ;
V_12 -> V_321 = V_321 ;
V_321 -> V_321 = V_321 ;
V_12 -> V_319 = V_321 ;
V_321 -> V_319 = V_12 ;
F_55 ( & V_325 ) ;
}
F_184 ( & V_12 -> V_326 ) ;
F_49 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_82 = V_51 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_206 = ( V_51 -> V_327 != NULL ) ;
F_185 ( & V_12 -> V_105 ) ;
V_12 -> V_105 . V_328 = F_30 ;
V_12 -> V_105 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_186
F_187 ( & V_12 -> V_308 , F_167 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_61 = V_20 -> V_98 & V_329 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_36 ;
return V_12 ;
}
struct V_11 * F_188 ( const struct V_320 * V_20 ,
struct V_116 * V_51 , const char * V_16 )
{
return F_181 ( V_20 , V_51 , V_16 , NULL ) ;
}
static void F_189 ( struct V_326 * V_326 )
{
struct V_11 * V_12 = F_168 ( V_326 , struct V_11 , V_326 ) ;
F_52 ( & V_325 ) ;
if ( V_12 -> V_319 ) {
struct V_11 * V_330 = V_12 -> V_319 ;
V_330 -> V_319 = NULL ;
V_330 -> V_321 = NULL ;
} else {
F_19 ( V_12 -> V_323 ) ;
F_19 ( V_12 -> V_324 ) ;
}
F_55 ( & V_325 ) ;
F_19 ( V_12 ) ;
}
struct V_11 * F_190 ( struct V_11 * V_12 )
{
if ( V_12 )
F_191 ( & V_12 -> V_326 ) ;
return V_12 ;
}
void F_192 ( struct V_11 * V_12 )
{
if ( V_12 )
F_193 ( & V_12 -> V_326 , F_189 ) ;
}
int F_177 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_321 )
return 1 ;
return V_12 == V_12 -> V_321 ;
}
int F_194 ( struct V_11 * V_12 , int V_301 )
{
if ( ! V_12 -> V_20 -> V_331 )
return V_301 ;
return V_12 -> V_20 -> V_331 ( V_12 , V_301 ) ;
}
static int F_195 ( struct V_11 * V_12 ,
unsigned int V_332 , unsigned long V_333 )
{
int V_109 ;
if ( V_12 -> V_20 -> V_313 ) {
snprintf ( V_12 -> V_334 , sizeof( V_12 -> V_334 ) , L_37 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_133 ) ;
V_109 = F_196 ( V_332 , & F_174 , V_333 ,
V_12 -> V_334 , V_12 ) ;
if ( V_109 != 0 ) {
F_69 ( V_12 -> V_15 . V_82 ,
L_38 ,
V_332 ) ;
return V_109 ;
}
V_12 -> V_313 = V_332 ;
F_57 ( V_12 -> V_15 . V_82 , L_39 , V_332 ,
( V_12 -> V_20 -> V_98 & V_335 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_336 ) ;
} else {
V_12 -> V_313 = 0 ;
if ( V_12 -> V_336 )
F_57 ( V_12 -> V_15 . V_82 , L_42 ,
( V_12 -> V_20 -> V_98 & V_335 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_336 ) ;
}
return 0 ;
}
static void F_197 ( struct V_11 * V_12 )
{
struct V_1 * V_288 ;
F_52 ( & V_325 ) ;
V_288 = V_12 -> V_15 . V_50 ;
V_12 -> V_15 . V_50 = NULL ;
F_55 ( & V_325 ) ;
F_127 ( V_288 ) ;
}
int F_198 ( struct V_11 * V_12 ,
unsigned int V_332 , unsigned long V_333 )
{
int V_109 ;
struct V_1 * V_288 ;
if ( F_96 ( V_337 ) && ! V_12 -> V_338 ) {
struct V_338 * V_339 = F_199 ( V_12 -> V_15 . V_82 , 0 ) ;
if ( F_200 ( V_339 ) ) {
V_109 = F_201 ( V_339 ) ;
if ( V_109 == - V_340 )
return V_109 ;
} else {
V_109 = F_202 ( V_339 ) ;
if ( V_109 ) {
F_203 ( V_339 ) ;
return V_109 ;
}
V_12 -> V_338 = V_339 ;
V_12 -> V_341 = 1 ;
}
}
if ( F_96 ( V_342 ) && ! V_12 -> V_339 ) {
struct V_339 * V_339 = F_204 ( V_12 -> V_15 . V_82 , L_43 ) ;
if ( F_200 ( V_339 ) ) {
V_109 = F_201 ( V_339 ) ;
if ( V_109 == - V_340 )
goto V_343;
} else {
V_109 = F_205 ( V_339 ) ;
if ( V_109 ) {
F_206 ( V_339 ) ;
goto V_343;
}
V_109 = F_207 ( V_339 ) ;
if ( V_109 ) {
F_208 ( V_339 ) ;
F_206 ( V_339 ) ;
goto V_343;
}
V_12 -> V_339 = V_339 ;
V_12 -> V_341 = 1 ;
}
}
F_57 ( V_12 -> V_15 . V_82 , L_44 , V_12 -> V_17 ) ;
if ( V_344 < 0 || V_344 > 1 ) {
if ( V_12 -> V_345 )
F_25 ( V_126 , & V_12 -> V_98 ) ;
else
F_26 ( V_126 , & V_12 -> V_98 ) ;
} else {
if ( V_344 )
F_26 ( V_126 , & V_12 -> V_98 ) ;
else
F_25 ( V_126 , & V_12 -> V_98 ) ;
}
F_26 ( V_346 , & V_12 -> V_98 ) ;
F_26 ( V_129 , & V_12 -> V_98 ) ;
V_109 = F_209 ( V_12 ) ;
if ( V_109 != 0 ) {
F_16 ( V_12 -> V_15 . V_82 , L_45 ) ;
goto V_347;
}
V_109 = F_51 ( & V_12 -> V_15 ) ;
if ( V_109 < 0 )
goto V_348;
V_288 = F_210 ( NULL , & V_12 -> V_15 , 0 ) ;
if ( V_288 == NULL ) {
F_69 ( V_12 -> V_15 . V_82 , L_46 ) ;
V_109 = - V_45 ;
goto V_349;
}
F_52 ( & V_325 ) ;
V_12 -> V_15 . V_50 = V_288 ;
F_55 ( & V_325 ) ;
switch ( V_12 -> V_61 ) {
case V_70 :
V_288 -> V_61 = V_168 ;
break;
case V_68 :
V_288 -> V_61 = V_169 ;
break;
case V_66 :
V_288 -> V_61 = V_350 ;
break;
case V_64 :
V_288 -> V_61 = V_155 ;
break;
case V_62 :
V_288 -> V_61 = V_351 ;
break;
default:
V_109 = - V_111 ;
goto V_352;
}
F_211 ( & V_288 -> V_51 , 1 ) ;
F_26 ( V_293 , & V_12 -> V_98 ) ;
if ( V_12 -> V_20 -> V_259 ) {
V_109 = V_12 -> V_20 -> V_259 ( V_12 ) ;
if ( V_109 < 0 ) {
F_69 ( V_12 -> V_15 . V_82 , L_47 ,
V_109 ) ;
goto V_353;
}
}
V_12 -> V_100 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_82 )
&& F_15 ( & V_12 -> V_15 . V_50 -> V_51 ) )
F_16 ( V_12 -> V_15 . V_82 , L_48 ) ;
F_178 ( & V_12 -> V_238 ) ;
F_178 ( & V_12 -> V_240 ) ;
if ( F_177 ( V_12 ) && V_332 ) {
V_109 = F_195 ( V_12 , V_332 , V_333 ) ;
if ( V_109 )
goto V_354;
}
V_12 -> V_283 = V_303 ;
V_109 = V_12 -> V_20 -> V_355 ( V_12 ) ;
if ( V_109 < 0 ) {
F_69 ( V_12 -> V_15 . V_82 , L_49 , V_109 ) ;
goto V_356;
}
V_109 = F_61 ( V_12 ) ;
if ( V_109 != 0 )
goto V_357;
V_109 = F_212 ( & V_288 -> V_51 . V_358 , & V_359 ) ;
if ( V_109 < 0 ) {
F_213 ( V_360 L_50 ,
V_109 ) ;
goto V_361;
}
if ( V_12 -> V_101 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
return V_109 ;
V_361:
F_25 ( V_293 , & V_12 -> V_98 ) ;
if ( F_214 ( V_12 -> V_283 ) )
V_12 -> V_283 = V_294 ;
F_7 ( & V_37 ) ;
V_12 -> V_156 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_215 ( & V_12 -> V_308 ) ;
#endif
F_52 ( & V_139 ) ;
F_216 ( & V_288 ) ;
F_55 ( & V_139 ) ;
V_357:
V_12 -> V_100 = 0 ;
F_25 ( V_318 , & V_12 -> V_98 ) ;
F_217 ( & V_12 -> V_105 ) ;
V_12 -> V_20 -> V_362 ( V_12 ) ;
V_12 -> V_283 = V_363 ;
F_25 ( V_318 , & V_12 -> V_98 ) ;
F_217 ( & V_12 -> V_105 ) ;
V_356:
if ( F_177 ( V_12 ) && V_12 -> V_313 > 0 )
F_218 ( V_332 , V_12 ) ;
V_354:
V_353:
V_352:
F_197 ( V_12 ) ;
V_349:
F_58 ( & V_12 -> V_15 ) ;
V_348:
F_219 ( V_12 ) ;
V_347:
if ( F_96 ( V_342 ) && V_12 -> V_341 && V_12 -> V_339 ) {
F_220 ( V_12 -> V_339 ) ;
F_208 ( V_12 -> V_339 ) ;
F_206 ( V_12 -> V_339 ) ;
V_12 -> V_339 = NULL ;
}
V_343:
if ( V_12 -> V_341 && V_12 -> V_338 ) {
F_221 ( V_12 -> V_338 ) ;
F_203 ( V_12 -> V_338 ) ;
V_12 -> V_338 = NULL ;
}
return V_109 ;
}
void F_222 ( struct V_11 * V_12 )
{
struct V_1 * V_288 = V_12 -> V_15 . V_50 ;
F_57 ( V_12 -> V_15 . V_82 , L_51 , V_12 -> V_283 ) ;
F_126 ( V_288 ) ;
F_223 ( & V_288 -> V_51 . V_358 , & V_359 ) ;
F_25 ( V_293 , & V_12 -> V_98 ) ;
if ( F_214 ( V_12 -> V_283 ) )
V_12 -> V_283 = V_294 ;
F_16 ( V_12 -> V_15 . V_82 , L_52 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_156 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_215 ( & V_12 -> V_308 ) ;
#endif
F_52 ( & V_139 ) ;
F_216 ( & V_288 ) ;
F_55 ( & V_139 ) ;
V_12 -> V_100 = 0 ;
F_25 ( V_318 , & V_12 -> V_98 ) ;
F_217 ( & V_12 -> V_105 ) ;
V_12 -> V_20 -> V_362 ( V_12 ) ;
V_12 -> V_283 = V_363 ;
F_25 ( V_318 , & V_12 -> V_98 ) ;
F_217 ( & V_12 -> V_105 ) ;
if ( F_177 ( V_12 ) ) {
if ( V_12 -> V_313 > 0 )
F_218 ( V_12 -> V_313 , V_12 ) ;
}
F_58 ( & V_12 -> V_15 ) ;
F_219 ( V_12 ) ;
if ( F_96 ( V_342 ) && V_12 -> V_341 && V_12 -> V_339 ) {
F_220 ( V_12 -> V_339 ) ;
F_208 ( V_12 -> V_339 ) ;
F_206 ( V_12 -> V_339 ) ;
V_12 -> V_339 = NULL ;
}
if ( V_12 -> V_341 && V_12 -> V_338 ) {
F_221 ( V_12 -> V_338 ) ;
F_203 ( V_12 -> V_338 ) ;
V_12 -> V_338 = NULL ;
}
F_197 ( V_12 ) ;
V_12 -> V_98 = 0 ;
}
void
F_224 ( struct V_364 * V_51 )
{
struct V_11 * V_12 = F_225 ( V_51 ) ;
if ( V_12 -> V_20 -> V_365 )
V_12 -> V_20 -> V_365 ( V_12 ) ;
}
int F_226 ( const struct V_366 * V_367 )
{
if ( V_368 )
return - V_182 ;
V_368 = V_367 ;
F_227 () ;
return 0 ;
}
void F_228 ( void )
{
if ( V_368 == NULL ) {
F_213 ( V_360 L_53 ) ;
return;
}
V_368 = NULL ;
F_227 () ;
}
