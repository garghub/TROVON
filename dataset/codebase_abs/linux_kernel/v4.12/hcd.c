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
struct V_116 * V_145 = V_12 -> V_15 . V_145 ;
struct V_1 * V_127 = V_12 -> V_15 . V_50 ;
const int V_146 = 1 ;
int V_109 ;
V_127 -> V_146 = V_146 ;
V_127 -> V_121 -> V_132 = V_146 + 1 ;
memset ( & V_127 -> V_121 -> V_130 . V_147 , 0 ,
sizeof V_127 -> V_121 -> V_130 . V_147 ) ;
F_26 ( V_146 , V_127 -> V_121 -> V_130 . V_147 ) ;
F_62 ( V_127 , V_148 ) ;
F_52 ( & V_139 ) ;
V_127 -> V_149 . V_114 . V_150 = F_63 ( 64 ) ;
V_109 = F_64 ( V_127 , V_151 ) ;
if ( V_109 != sizeof V_127 -> V_152 ) {
F_55 ( & V_139 ) ;
F_16 ( V_144 , L_12 ,
F_65 ( & V_127 -> V_51 ) , V_109 ) ;
return ( V_109 < 0 ) ? V_109 : - V_153 ;
}
if ( F_10 ( V_127 -> V_152 . V_154 ) >= 0x0201 ) {
V_109 = F_66 ( V_127 ) ;
if ( ! V_109 ) {
V_127 -> V_155 = F_67 ( V_127 ) ;
} else if ( V_127 -> V_61 >= V_156 ) {
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
V_12 -> V_157 = 1 ;
F_9 ( & V_37 ) ;
if ( F_70 ( V_12 ) )
F_71 ( V_12 ) ;
V_127 -> V_51 . V_158 = V_145 -> V_158 ;
}
F_55 ( & V_139 ) ;
return V_109 ;
}
void F_72 ( struct V_120 * V_121 , int V_159 )
{
unsigned V_160 = 1 << V_159 ;
if ( ! ( V_121 -> V_161 & V_160 ) ) {
V_121 -> V_161 |= V_160 ;
F_73 ( & V_121 -> V_50 -> V_51 ) ;
}
}
void F_74 ( struct V_120 * V_121 , int V_159 )
{
unsigned V_160 = 1 << V_159 ;
if ( V_121 -> V_161 & V_160 ) {
V_121 -> V_161 &= ~ V_160 ;
F_75 ( & V_121 -> V_50 -> V_51 ) ;
}
}
long F_76 ( int V_61 , int V_162 , int V_163 , int V_164 )
{
unsigned long V_165 ;
switch ( V_61 ) {
case V_166 :
if ( V_162 ) {
V_165 = ( 67667L * ( 31L + 10L * F_77 ( V_164 ) ) ) / 1000L ;
return 64060L + ( 2 * V_167 ) + V_168 + V_165 ;
} else {
V_165 = ( 66700L * ( 31L + 10L * F_77 ( V_164 ) ) ) / 1000L ;
return 64107L + ( 2 * V_167 ) + V_168 + V_165 ;
}
case V_169 :
if ( V_163 ) {
V_165 = ( 8354L * ( 31L + 10L * F_77 ( V_164 ) ) ) / 1000L ;
return ( ( V_162 ) ? 7268L : 6265L ) + V_168 + V_165 ;
} else {
V_165 = ( 8354L * ( 31L + 10L * F_77 ( V_164 ) ) ) / 1000L ;
return 9107L + V_168 + V_165 ;
}
case V_170 :
if ( V_163 )
V_165 = F_78 ( V_164 ) ;
else
V_165 = F_79 ( V_164 ) ;
return V_165 ;
default:
F_80 ( L_15 , V_142 ) ;
return - 1 ;
}
}
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_115 = 0 ;
F_81 ( & V_171 ) ;
if ( F_23 ( F_82 ( & V_22 -> V_172 ) ) ) {
V_115 = - V_173 ;
goto V_112;
}
if ( F_23 ( ! V_22 -> V_113 -> V_174 ) ) {
V_115 = - V_175 ;
goto V_112;
}
if ( F_23 ( ! V_22 -> V_51 -> V_176 ) ) {
V_115 = - V_177 ;
goto V_112;
}
if ( F_83 ( V_12 ) ) {
V_22 -> V_178 = 0 ;
F_84 ( & V_22 -> V_179 , & V_22 -> V_113 -> V_179 ) ;
} else {
V_115 = - V_180 ;
goto V_112;
}
V_112:
F_85 ( & V_171 ) ;
return V_115 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_181 * V_165 ;
F_86 (tmp, &urb->ep->urb_list) {
if ( V_165 == & V_22 -> V_179 )
break;
}
if ( V_165 != & V_22 -> V_179 )
return - V_182 ;
if ( V_22 -> V_178 )
return - V_183 ;
V_22 -> V_178 = V_31 ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_81 ( & V_171 ) ;
F_87 ( & V_22 -> V_179 ) ;
F_85 ( & V_171 ) ;
}
static int F_88 ( struct V_120 * V_121 ,
T_5 V_184 , T_6 * V_185 ,
void * * V_186 , T_4 V_123 ,
enum V_187 V_188 )
{
unsigned char * V_189 ;
if ( * V_186 == NULL ) {
F_89 ( 1 ) ;
return - V_190 ;
}
V_189 = F_90 ( V_121 , V_123 + sizeof( V_189 ) ,
V_184 , V_185 ) ;
if ( ! V_189 )
return - V_45 ;
F_91 ( ( unsigned long ) * V_186 ,
( unsigned long * ) ( V_189 + V_123 ) ) ;
if ( V_188 == V_191 )
memcpy ( V_189 , * V_186 , V_123 ) ;
* V_186 = V_189 ;
return 0 ;
}
static void F_92 ( struct V_120 * V_121 , T_6 * V_185 ,
void * * V_186 , T_4 V_123 ,
enum V_187 V_188 )
{
unsigned char * V_189 = * V_186 ;
V_189 = ( void * ) F_93 ( ( unsigned long * ) ( V_189 + V_123 ) ) ;
if ( V_188 == V_192 )
memcpy ( V_189 , * V_186 , V_123 ) ;
F_94 ( V_121 , V_123 + sizeof( V_189 ) , * V_186 , * V_185 ) ;
* V_186 = V_189 ;
* V_185 = 0 ;
}
void F_95 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_96 ( V_193 ) &&
( V_22 -> V_194 & V_195 ) )
F_97 ( V_12 -> V_15 . V_145 ,
V_22 -> V_196 ,
sizeof( struct V_23 ) ,
V_191 ) ;
else if ( V_22 -> V_194 & V_197 )
F_92 ( V_22 -> V_51 -> V_121 ,
& V_22 -> V_196 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_191 ) ;
V_22 -> V_194 &= ~ ( V_195 | V_197 ) ;
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
enum V_187 V_188 ;
F_95 ( V_12 , V_22 ) ;
V_188 = F_100 ( V_22 ) ? V_192 : V_191 ;
if ( F_96 ( V_193 ) &&
( V_22 -> V_194 & V_198 ) )
F_101 ( V_12 -> V_15 . V_145 ,
V_22 -> V_199 ,
V_22 -> V_200 ,
V_188 ) ;
else if ( F_96 ( V_193 ) &&
( V_22 -> V_194 & V_201 ) )
F_102 ( V_12 -> V_15 . V_145 ,
V_22 -> V_202 ,
V_22 -> V_42 ,
V_188 ) ;
else if ( F_96 ( V_193 ) &&
( V_22 -> V_194 & V_203 ) )
F_97 ( V_12 -> V_15 . V_145 ,
V_22 -> V_202 ,
V_22 -> V_42 ,
V_188 ) ;
else if ( V_22 -> V_194 & V_204 )
F_92 ( V_22 -> V_51 -> V_121 ,
& V_22 -> V_202 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_188 ) ;
V_22 -> V_194 &= ~ ( V_198 | V_201 |
V_203 | V_204 ) ;
}
static int F_103 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_184 )
{
if ( V_12 -> V_20 -> F_103 )
return V_12 -> V_20 -> F_103 ( V_12 , V_22 , V_184 ) ;
else
return F_104 ( V_12 , V_22 , V_184 ) ;
}
int F_104 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_184 )
{
enum V_187 V_188 ;
int V_205 = 0 ;
if ( F_35 ( & V_22 -> V_113 -> V_114 ) ) {
if ( V_12 -> V_15 . V_206 )
return V_205 ;
if ( F_96 ( V_193 ) && V_12 -> V_15 . V_207 ) {
V_22 -> V_196 = F_105 (
V_12 -> V_15 . V_145 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_191 ) ;
if ( F_106 ( V_12 -> V_15 . V_145 ,
V_22 -> V_196 ) )
return - V_208 ;
V_22 -> V_194 |= V_195 ;
} else if ( V_12 -> V_20 -> V_98 & V_209 ) {
V_205 = F_88 (
V_22 -> V_51 -> V_121 , V_184 ,
& V_22 -> V_196 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_191 ) ;
if ( V_205 )
return V_205 ;
V_22 -> V_194 |= V_197 ;
}
}
V_188 = F_100 ( V_22 ) ? V_192 : V_191 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_194 & V_210 ) ) {
if ( F_96 ( V_193 ) && V_12 -> V_15 . V_207 ) {
if ( V_22 -> V_200 ) {
int V_7 ;
if ( F_107 ( & V_22 -> V_113 -> V_114 ) ) {
F_108 ( 1 ) ;
return - V_111 ;
}
V_7 = F_109 (
V_12 -> V_15 . V_145 ,
V_22 -> V_199 ,
V_22 -> V_200 ,
V_188 ) ;
if ( V_7 <= 0 )
V_205 = - V_208 ;
else
V_22 -> V_194 |= V_198 ;
V_22 -> V_211 = V_7 ;
if ( V_7 != V_22 -> V_200 )
V_22 -> V_194 |=
V_212 ;
} else if ( V_22 -> V_199 ) {
struct V_213 * V_199 = V_22 -> V_199 ;
V_22 -> V_202 = F_110 (
V_12 -> V_15 . V_145 ,
F_111 ( V_199 ) ,
V_199 -> V_214 ,
V_22 -> V_42 ,
V_188 ) ;
if ( F_106 ( V_12 -> V_15 . V_145 ,
V_22 -> V_202 ) )
V_205 = - V_208 ;
else
V_22 -> V_194 |= V_201 ;
} else if ( F_112 ( V_22 -> V_30 ) ) {
F_113 ( 1 , L_16 ) ;
V_205 = - V_208 ;
} else {
V_22 -> V_202 = F_105 (
V_12 -> V_15 . V_145 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_188 ) ;
if ( F_106 ( V_12 -> V_15 . V_145 ,
V_22 -> V_202 ) )
V_205 = - V_208 ;
else
V_22 -> V_194 |= V_203 ;
}
} else if ( V_12 -> V_20 -> V_98 & V_209 ) {
V_205 = F_88 (
V_22 -> V_51 -> V_121 , V_184 ,
& V_22 -> V_202 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_188 ) ;
if ( V_205 == 0 )
V_22 -> V_194 |= V_204 ;
}
if ( V_205 && ( V_22 -> V_194 & ( V_195 |
V_197 ) ) )
F_99 ( V_12 , V_22 ) ;
}
return V_205 ;
}
int F_114 ( struct V_22 * V_22 , T_5 V_184 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_51 -> V_121 ) ;
F_115 ( V_22 ) ;
F_116 ( & V_22 -> V_215 ) ;
F_116 ( & V_22 -> V_51 -> V_216 ) ;
F_117 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_51 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_103 ( V_12 , V_22 , V_184 ) ;
if ( F_118 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_217 ( V_12 , V_22 , V_184 ) ;
if ( F_23 ( V_31 ) )
F_98 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_119 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_120 ( & V_22 -> V_179 ) ;
F_121 ( & V_22 -> V_215 ) ;
F_121 ( & V_22 -> V_51 -> V_216 ) ;
if ( F_82 ( & V_22 -> V_172 ) )
F_122 ( & V_218 ) ;
F_123 ( V_22 ) ;
}
return V_31 ;
}
static int F_124 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_219 ;
if ( F_1 ( V_22 -> V_51 ) )
V_219 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_219 = V_12 -> V_20 -> V_220 ( V_12 , V_22 , V_31 ) ;
}
return V_219 ;
}
int F_125 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_22 -> V_51 ;
int V_109 = - V_182 ;
unsigned long V_98 ;
F_24 ( & V_221 , V_98 ) ;
if ( F_82 ( & V_22 -> V_215 ) > 0 ) {
V_109 = 0 ;
F_126 ( V_2 ) ;
}
F_27 ( & V_221 , V_98 ) ;
if ( V_109 == 0 ) {
V_12 = F_42 ( V_22 -> V_51 -> V_121 ) ;
V_109 = F_124 ( V_12 , V_22 , V_31 ) ;
if ( V_109 == 0 )
V_109 = - V_222 ;
else if ( V_109 != - V_182 && V_109 != - V_183 )
F_16 ( & V_2 -> V_51 , L_17 ,
V_22 , V_109 ) ;
F_127 ( V_2 ) ;
}
return V_109 ;
}
static void F_128 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_51 -> V_121 ) ;
struct V_223 * V_224 = V_22 -> V_224 ;
int V_31 = V_22 -> V_178 ;
unsigned long V_98 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_194 & V_225 ) &&
V_22 -> V_47 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_226 ;
F_98 ( V_12 , V_22 ) ;
F_129 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_130 ( V_224 ) ;
F_131 ( V_22 ) ;
if ( F_118 ( V_31 == 0 ) )
F_132 ( V_227 ) ;
V_22 -> V_31 = V_31 ;
F_133 ( V_98 ) ;
V_22 -> V_228 ( V_22 ) ;
F_134 ( V_98 ) ;
F_135 ( V_224 ) ;
F_121 ( & V_22 -> V_215 ) ;
if ( F_23 ( F_82 ( & V_22 -> V_172 ) ) )
F_122 ( & V_218 ) ;
F_123 ( V_22 ) ;
}
static void F_136 ( unsigned long V_229 )
{
struct V_230 * V_231 = (struct V_230 * ) V_229 ;
struct V_181 V_232 ;
F_7 ( & V_231 -> V_233 ) ;
V_231 -> V_234 = true ;
V_235:
F_137 ( & V_231 -> V_236 , & V_232 ) ;
F_9 ( & V_231 -> V_233 ) ;
while ( ! F_138 ( & V_232 ) ) {
struct V_22 * V_22 ;
V_22 = F_139 ( V_232 . V_237 , struct V_22 , V_179 ) ;
F_87 ( & V_22 -> V_179 ) ;
V_231 -> V_238 = V_22 -> V_113 ;
F_128 ( V_22 ) ;
V_231 -> V_238 = NULL ;
}
F_7 ( & V_231 -> V_233 ) ;
if ( ! F_138 ( & V_231 -> V_236 ) )
goto V_235;
V_231 -> V_234 = false ;
F_9 ( & V_231 -> V_233 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_230 * V_231 ;
bool V_234 , V_239 ;
if ( F_118 ( ! V_22 -> V_178 ) )
V_22 -> V_178 = V_31 ;
if ( ! F_140 ( V_12 ) && ! F_1 ( V_22 -> V_51 ) ) {
F_128 ( V_22 ) ;
return;
}
if ( F_141 ( V_22 -> V_240 ) || F_142 ( V_22 -> V_240 ) ) {
V_231 = & V_12 -> V_239 ;
V_239 = true ;
} else {
V_231 = & V_12 -> V_241 ;
V_239 = false ;
}
F_81 ( & V_231 -> V_233 ) ;
F_84 ( & V_22 -> V_179 , & V_231 -> V_236 ) ;
V_234 = V_231 -> V_234 ;
F_85 ( & V_231 -> V_233 ) ;
if ( V_234 )
;
else if ( V_239 )
F_143 ( & V_231 -> V_231 ) ;
else
F_144 ( & V_231 -> V_231 ) ;
}
void F_145 ( struct V_1 * V_2 ,
struct V_242 * V_113 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_113 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_121 ) ;
F_7 ( & V_171 ) ;
V_243:
F_146 (urb, &ep->urb_list, urb_list) {
int V_244 ;
if ( V_22 -> V_178 )
continue;
F_115 ( V_22 ) ;
V_244 = F_100 ( V_22 ) ;
F_85 ( & V_171 ) ;
F_124 ( V_12 , V_22 , - V_180 ) ;
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
F_81 ( & V_171 ) ;
goto V_243;
}
F_9 ( & V_171 ) ;
while ( ! F_138 ( & V_113 -> V_179 ) ) {
F_7 ( & V_171 ) ;
V_22 = NULL ;
if ( ! F_138 ( & V_113 -> V_179 ) ) {
V_22 = F_139 ( V_113 -> V_179 . V_245 , struct V_22 ,
V_179 ) ;
F_115 ( V_22 ) ;
}
F_9 ( & V_171 ) ;
if ( V_22 ) {
F_147 ( V_22 ) ;
F_123 ( V_22 ) ;
}
}
}
int F_148 ( struct V_1 * V_2 ,
struct V_246 * V_247 ,
struct V_248 * V_249 ,
struct V_248 * V_250 )
{
int V_251 , V_252 , V_253 ;
struct V_248 * V_254 = NULL ;
int V_205 = 0 ;
struct V_11 * V_12 ;
struct V_242 * V_113 ;
V_12 = F_42 ( V_2 -> V_121 ) ;
if ( ! V_12 -> V_20 -> V_255 )
return 0 ;
if ( ! V_247 && ! V_249 ) {
for ( V_252 = 1 ; V_252 < 16 ; ++ V_252 ) {
V_113 = V_2 -> V_256 [ V_252 ] ;
if ( V_113 )
V_12 -> V_20 -> V_257 ( V_12 , V_2 , V_113 ) ;
V_113 = V_2 -> V_258 [ V_252 ] ;
if ( V_113 )
V_12 -> V_20 -> V_257 ( V_12 , V_2 , V_113 ) ;
}
V_12 -> V_20 -> V_255 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_247 ) {
V_251 = V_247 -> V_114 . V_259 ;
for ( V_252 = 1 ; V_252 < 16 ; ++ V_252 ) {
V_113 = V_2 -> V_256 [ V_252 ] ;
if ( V_113 ) {
V_205 = V_12 -> V_20 -> V_257 ( V_12 , V_2 , V_113 ) ;
if ( V_205 < 0 )
goto V_260;
}
V_113 = V_2 -> V_258 [ V_252 ] ;
if ( V_113 ) {
V_205 = V_12 -> V_20 -> V_257 ( V_12 , V_2 , V_113 ) ;
if ( V_205 < 0 )
goto V_260;
}
}
for ( V_252 = 0 ; V_252 < V_251 ; ++ V_252 ) {
struct V_248 * V_261 ;
int V_262 ;
V_261 = & V_247 -> V_263 [ V_252 ] -> V_264 [ 0 ] ;
V_262 = V_261 -> V_114 . V_265 ;
V_254 = F_149 ( V_247 , V_262 , 0 ) ;
if ( ! V_254 )
V_254 = V_261 ;
for ( V_253 = 0 ; V_253 < V_254 -> V_114 . V_266 ; V_253 ++ ) {
V_205 = V_12 -> V_20 -> V_267 ( V_12 , V_2 , & V_254 -> V_268 [ V_253 ] ) ;
if ( V_205 < 0 )
goto V_260;
}
}
}
if ( V_249 && V_250 ) {
struct V_269 * V_270 = F_150 ( V_2 ,
V_249 -> V_114 . V_265 ) ;
if ( ! V_270 )
return - V_111 ;
if ( V_270 -> V_271 ) {
V_249 = F_151 ( V_270 , 0 ) ;
if ( ! V_249 )
V_249 = & V_270 -> V_264 [ 0 ] ;
}
for ( V_252 = 0 ; V_252 < V_249 -> V_114 . V_266 ; V_252 ++ ) {
V_205 = V_12 -> V_20 -> V_257 ( V_12 , V_2 ,
& V_249 -> V_268 [ V_252 ] ) ;
if ( V_205 < 0 )
goto V_260;
}
for ( V_252 = 0 ; V_252 < V_250 -> V_114 . V_266 ; V_252 ++ ) {
V_205 = V_12 -> V_20 -> V_267 ( V_12 , V_2 ,
& V_250 -> V_268 [ V_252 ] ) ;
if ( V_205 < 0 )
goto V_260;
}
}
V_205 = V_12 -> V_20 -> V_255 ( V_12 , V_2 ) ;
V_260:
if ( V_205 < 0 )
V_12 -> V_20 -> V_272 ( V_12 , V_2 ) ;
return V_205 ;
}
void F_152 ( struct V_1 * V_2 ,
struct V_242 * V_113 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_121 ) ;
if ( V_12 -> V_20 -> V_273 )
V_12 -> V_20 -> V_273 ( V_12 , V_113 ) ;
}
void F_153 ( struct V_1 * V_2 ,
struct V_242 * V_113 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_121 ) ;
if ( V_12 -> V_20 -> V_274 )
V_12 -> V_20 -> V_274 ( V_12 , V_113 ) ;
else {
int V_275 = F_38 ( & V_113 -> V_114 ) ;
int V_276 = F_154 ( & V_113 -> V_114 ) ;
int V_277 = F_35 ( & V_113 -> V_114 ) ;
F_155 ( V_2 , V_275 , V_276 , 0 ) ;
if ( V_277 )
F_155 ( V_2 , V_275 , ! V_276 , 0 ) ;
}
}
int F_156 ( struct V_269 * V_278 ,
struct V_242 * * V_279 , unsigned int V_280 ,
unsigned int V_281 , T_5 V_184 )
{
struct V_11 * V_12 ;
struct V_1 * V_51 ;
int V_252 , V_205 ;
V_51 = F_157 ( V_278 ) ;
V_12 = F_42 ( V_51 -> V_121 ) ;
if ( ! V_12 -> V_20 -> V_282 || ! V_12 -> V_20 -> V_283 )
return - V_111 ;
if ( V_51 -> V_61 < V_156 )
return - V_111 ;
if ( V_51 -> V_284 < V_285 )
return - V_286 ;
for ( V_252 = 0 ; V_252 < V_280 ; V_252 ++ ) {
if ( ! F_158 ( & V_279 [ V_252 ] -> V_114 ) )
return - V_111 ;
if ( V_279 [ V_252 ] -> V_287 )
return - V_111 ;
}
V_205 = V_12 -> V_20 -> V_282 ( V_12 , V_51 , V_279 , V_280 ,
V_281 , V_184 ) ;
if ( V_205 < 0 )
return V_205 ;
for ( V_252 = 0 ; V_252 < V_280 ; V_252 ++ )
V_279 [ V_252 ] -> V_287 = V_205 ;
return V_205 ;
}
int F_159 ( struct V_269 * V_278 ,
struct V_242 * * V_279 , unsigned int V_280 ,
T_5 V_184 )
{
struct V_11 * V_12 ;
struct V_1 * V_51 ;
int V_252 , V_205 ;
V_51 = F_157 ( V_278 ) ;
V_12 = F_42 ( V_51 -> V_121 ) ;
if ( V_51 -> V_61 < V_156 )
return - V_111 ;
for ( V_252 = 0 ; V_252 < V_280 ; V_252 ++ )
if ( ! V_279 [ V_252 ] || ! V_279 [ V_252 ] -> V_287 )
return - V_111 ;
V_205 = V_12 -> V_20 -> V_283 ( V_12 , V_51 , V_279 , V_280 , V_184 ) ;
if ( V_205 < 0 )
return V_205 ;
for ( V_252 = 0 ; V_252 < V_280 ; V_252 ++ )
V_279 [ V_252 ] -> V_287 = 0 ;
return V_205 ;
}
void F_160 ( struct V_1 * V_2 )
{
F_7 ( & V_221 ) ;
F_9 ( & V_221 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_121 ) ;
if ( ! F_83 ( V_12 ) )
return - V_180 ;
return V_12 -> V_20 -> V_288 ( V_12 ) ;
}
int F_162 ( struct V_1 * V_289 , T_7 V_290 )
{
struct V_11 * V_12 = F_42 ( V_289 -> V_121 ) ;
int V_31 ;
int V_291 = V_12 -> V_284 ;
F_16 ( & V_289 -> V_51 , L_25 ,
( F_163 ( V_290 ) ? L_26 : L_21 ) ,
V_289 -> V_292 ) ;
if ( F_70 ( V_12 ) ) {
F_16 ( & V_289 -> V_51 , L_27 , L_28 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_293 ) {
V_31 = - V_175 ;
} else {
F_25 ( V_294 , & V_12 -> V_98 ) ;
V_12 -> V_284 = V_295 ;
V_31 = V_12 -> V_20 -> V_293 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_62 ( V_289 , V_296 ) ;
V_12 -> V_284 = V_297 ;
if ( V_289 -> V_292 ) {
char V_99 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_103 ( V_12 , V_99 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_289 -> V_51 , L_29 ) ;
F_164 ( V_289 , V_298 ) ;
V_31 = - V_183 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_70 ( V_12 ) ) {
F_26 ( V_294 , & V_12 -> V_98 ) ;
V_12 -> V_284 = V_291 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_289 -> V_51 , L_30 ,
L_28 , V_31 ) ;
}
return V_31 ;
}
int F_164 ( struct V_1 * V_289 , T_7 V_290 )
{
struct V_11 * V_12 = F_42 ( V_289 -> V_121 ) ;
int V_31 ;
int V_291 = V_12 -> V_284 ;
F_16 ( & V_289 -> V_51 , L_31 ,
( F_163 ( V_290 ) ? L_26 : L_21 ) ) ;
if ( F_70 ( V_12 ) ) {
F_16 ( & V_289 -> V_51 , L_27 , L_32 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_299 )
return - V_175 ;
if ( F_83 ( V_12 ) )
return 0 ;
V_12 -> V_284 = V_300 ;
V_31 = V_12 -> V_20 -> V_299 ( V_12 ) ;
F_25 ( V_301 , & V_12 -> V_98 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_302 ;
F_7 ( & V_37 ) ;
if ( ! F_70 ( V_12 ) ) {
F_62 ( V_289 , V_289 -> V_303
? V_285
: V_148 ) ;
F_26 ( V_294 , & V_12 -> V_98 ) ;
V_12 -> V_284 = V_304 ;
}
F_9 ( & V_37 ) ;
F_165 (rhdev, port1, udev) {
if ( V_2 -> V_284 != V_305 &&
! V_2 -> V_306 ) {
F_166 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_284 = V_291 ;
F_16 ( & V_289 -> V_51 , L_30 ,
L_32 , V_31 ) ;
if ( V_31 != - V_180 )
F_71 ( V_12 ) ;
}
return V_31 ;
}
static void F_167 ( struct V_307 * V_308 )
{
struct V_11 * V_12 = F_168 ( V_308 , struct V_11 , V_309 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_50 ;
F_169 ( V_2 ) ;
}
void F_170 ( struct V_11 * V_12 )
{
unsigned long V_98 ;
F_24 ( & V_37 , V_98 ) ;
if ( V_12 -> V_157 ) {
F_26 ( V_301 , & V_12 -> V_98 ) ;
F_171 ( V_310 , & V_12 -> V_309 ) ;
}
F_27 ( & V_37 , V_98 ) ;
}
int F_172 ( struct V_120 * V_121 , unsigned V_311 )
{
struct V_11 * V_12 ;
int V_31 = - V_312 ;
V_12 = F_42 ( V_121 ) ;
if ( V_311 && V_12 -> V_20 -> V_313 )
V_31 = V_12 -> V_20 -> V_313 ( V_12 , V_311 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_105 , V_106 + F_173 ( 10 ) ) ;
return V_31 ;
}
T_8 F_174 ( int V_314 , void * V_315 )
{
struct V_11 * V_12 = V_315 ;
T_8 V_115 ;
if ( F_23 ( F_70 ( V_12 ) || ! F_175 ( V_12 ) ) )
V_115 = V_316 ;
else if ( V_12 -> V_20 -> V_314 ( V_12 ) == V_316 )
V_115 = V_316 ;
else
V_115 = V_317 ;
return V_115 ;
}
void F_71 ( struct V_11 * V_12 )
{
unsigned long V_98 ;
F_69 ( V_12 -> V_15 . V_82 , L_33 ) ;
F_24 ( & V_37 , V_98 ) ;
F_25 ( V_294 , & V_12 -> V_98 ) ;
F_26 ( V_318 , & V_12 -> V_98 ) ;
if ( V_12 -> V_157 ) {
F_25 ( V_319 , & V_12 -> V_98 ) ;
F_62 ( V_12 -> V_15 . V_50 ,
V_305 ) ;
F_176 ( V_12 -> V_15 . V_50 ) ;
}
if ( F_177 ( V_12 ) && V_12 -> V_320 ) {
V_12 = V_12 -> V_320 ;
if ( V_12 -> V_157 ) {
F_25 ( V_319 , & V_12 -> V_98 ) ;
F_62 ( V_12 -> V_15 . V_50 ,
V_305 ) ;
F_176 ( V_12 -> V_15 . V_50 ) ;
}
}
F_27 ( & V_37 , V_98 ) ;
}
static void F_178 ( struct V_230 * V_231 )
{
F_179 ( & V_231 -> V_233 ) ;
F_120 ( & V_231 -> V_236 ) ;
F_180 ( & V_231 -> V_231 , F_136 , ( unsigned long ) V_231 ) ;
}
struct V_11 * F_181 ( const struct V_321 * V_20 ,
struct V_116 * V_145 , struct V_116 * V_51 , const char * V_16 ,
struct V_11 * V_322 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_323 , V_44 ) ;
if ( ! V_12 )
return NULL ;
if ( V_322 == NULL ) {
V_12 -> V_324 = F_182 ( sizeof( * V_12 -> V_324 ) ,
V_44 ) ;
if ( ! V_12 -> V_324 ) {
F_19 ( V_12 ) ;
F_16 ( V_51 , L_34 ) ;
return NULL ;
}
F_50 ( V_12 -> V_324 ) ;
V_12 -> V_325 = F_182 ( sizeof( * V_12 -> V_325 ) ,
V_44 ) ;
if ( ! V_12 -> V_325 ) {
F_19 ( V_12 -> V_324 ) ;
F_19 ( V_12 ) ;
F_16 ( V_51 , L_35 ) ;
return NULL ;
}
F_50 ( V_12 -> V_325 ) ;
F_183 ( V_51 , V_12 ) ;
} else {
F_52 ( & V_326 ) ;
V_12 -> V_324 = V_322 -> V_324 ;
V_12 -> V_325 = V_322 -> V_325 ;
V_12 -> V_322 = V_322 ;
V_322 -> V_322 = V_322 ;
V_12 -> V_320 = V_322 ;
V_322 -> V_320 = V_12 ;
F_55 ( & V_326 ) ;
}
F_184 ( & V_12 -> V_327 ) ;
F_49 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_82 = V_51 ;
V_12 -> V_15 . V_145 = V_145 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_207 = ( V_145 -> V_328 != NULL ) ;
F_185 ( & V_12 -> V_105 ) ;
V_12 -> V_105 . V_329 = F_30 ;
V_12 -> V_105 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_186
F_187 ( & V_12 -> V_309 , F_167 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_61 = V_20 -> V_98 & V_330 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_36 ;
return V_12 ;
}
struct V_11 * F_188 ( const struct V_321 * V_20 ,
struct V_116 * V_51 , const char * V_16 ,
struct V_11 * V_322 )
{
return F_181 ( V_20 , V_51 , V_51 , V_16 , V_322 ) ;
}
struct V_11 * F_189 ( const struct V_321 * V_20 ,
struct V_116 * V_51 , const char * V_16 )
{
return F_181 ( V_20 , V_51 , V_51 , V_16 , NULL ) ;
}
static void F_190 ( struct V_327 * V_327 )
{
struct V_11 * V_12 = F_168 ( V_327 , struct V_11 , V_327 ) ;
F_52 ( & V_326 ) ;
if ( V_12 -> V_320 ) {
struct V_11 * V_331 = V_12 -> V_320 ;
V_331 -> V_320 = NULL ;
V_331 -> V_322 = NULL ;
} else {
F_19 ( V_12 -> V_324 ) ;
F_19 ( V_12 -> V_325 ) ;
}
F_55 ( & V_326 ) ;
F_19 ( V_12 ) ;
}
struct V_11 * F_191 ( struct V_11 * V_12 )
{
if ( V_12 )
F_192 ( & V_12 -> V_327 ) ;
return V_12 ;
}
void F_193 ( struct V_11 * V_12 )
{
if ( V_12 )
F_194 ( & V_12 -> V_327 , F_190 ) ;
}
int F_177 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_322 )
return 1 ;
return V_12 == V_12 -> V_322 ;
}
int F_195 ( struct V_11 * V_12 , int V_302 )
{
if ( ! V_12 -> V_20 -> V_332 )
return V_302 ;
return V_12 -> V_20 -> V_332 ( V_12 , V_302 ) ;
}
static int F_196 ( struct V_11 * V_12 ,
unsigned int V_333 , unsigned long V_334 )
{
int V_109 ;
if ( V_12 -> V_20 -> V_314 ) {
snprintf ( V_12 -> V_335 , sizeof( V_12 -> V_335 ) , L_37 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_133 ) ;
V_109 = F_197 ( V_333 , & F_174 , V_334 ,
V_12 -> V_335 , V_12 ) ;
if ( V_109 != 0 ) {
F_69 ( V_12 -> V_15 . V_82 ,
L_38 ,
V_333 ) ;
return V_109 ;
}
V_12 -> V_314 = V_333 ;
F_57 ( V_12 -> V_15 . V_82 , L_39 , V_333 ,
( V_12 -> V_20 -> V_98 & V_336 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_337 ) ;
} else {
V_12 -> V_314 = 0 ;
if ( V_12 -> V_337 )
F_57 ( V_12 -> V_15 . V_82 , L_42 ,
( V_12 -> V_20 -> V_98 & V_336 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_337 ) ;
}
return 0 ;
}
static void F_198 ( struct V_11 * V_12 )
{
struct V_1 * V_289 ;
F_52 ( & V_326 ) ;
V_289 = V_12 -> V_15 . V_50 ;
V_12 -> V_15 . V_50 = NULL ;
F_55 ( & V_326 ) ;
F_127 ( V_289 ) ;
}
int F_199 ( struct V_11 * V_12 ,
unsigned int V_333 , unsigned long V_334 )
{
int V_109 ;
struct V_1 * V_289 ;
if ( F_96 ( V_338 ) && ! V_12 -> V_339 ) {
struct V_339 * V_340 = F_200 ( V_12 -> V_15 . V_145 , 0 ) ;
if ( F_201 ( V_340 ) ) {
V_109 = F_202 ( V_340 ) ;
if ( V_109 == - V_341 )
return V_109 ;
} else {
V_109 = F_203 ( V_340 ) ;
if ( V_109 ) {
F_204 ( V_340 ) ;
return V_109 ;
}
V_12 -> V_339 = V_340 ;
V_12 -> V_342 = 1 ;
}
}
if ( F_96 ( V_343 ) && ! V_12 -> V_340 ) {
struct V_340 * V_340 = F_205 ( V_12 -> V_15 . V_145 , L_43 ) ;
if ( F_201 ( V_340 ) ) {
V_109 = F_202 ( V_340 ) ;
if ( V_109 == - V_341 )
goto V_344;
} else {
V_109 = F_206 ( V_340 ) ;
if ( V_109 ) {
F_207 ( V_340 ) ;
goto V_344;
}
V_109 = F_208 ( V_340 ) ;
if ( V_109 ) {
F_209 ( V_340 ) ;
F_207 ( V_340 ) ;
goto V_344;
}
V_12 -> V_340 = V_340 ;
V_12 -> V_342 = 1 ;
}
}
F_57 ( V_12 -> V_15 . V_82 , L_44 , V_12 -> V_17 ) ;
if ( V_345 < 0 || V_345 > 1 ) {
if ( V_12 -> V_346 )
F_25 ( V_126 , & V_12 -> V_98 ) ;
else
F_26 ( V_126 , & V_12 -> V_98 ) ;
} else {
if ( V_345 )
F_26 ( V_126 , & V_12 -> V_98 ) ;
else
F_25 ( V_126 , & V_12 -> V_98 ) ;
}
F_26 ( V_347 , & V_12 -> V_98 ) ;
F_26 ( V_129 , & V_12 -> V_98 ) ;
V_109 = F_210 ( V_12 ) ;
if ( V_109 != 0 ) {
F_16 ( V_12 -> V_15 . V_145 , L_45 ) ;
goto V_348;
}
V_109 = F_51 ( & V_12 -> V_15 ) ;
if ( V_109 < 0 )
goto V_349;
V_289 = F_211 ( NULL , & V_12 -> V_15 , 0 ) ;
if ( V_289 == NULL ) {
F_69 ( V_12 -> V_15 . V_145 , L_46 ) ;
V_109 = - V_45 ;
goto V_350;
}
F_52 ( & V_326 ) ;
V_12 -> V_15 . V_50 = V_289 ;
F_55 ( & V_326 ) ;
switch ( V_12 -> V_61 ) {
case V_70 :
V_289 -> V_61 = V_169 ;
break;
case V_68 :
V_289 -> V_61 = V_170 ;
break;
case V_66 :
V_289 -> V_61 = V_351 ;
break;
case V_64 :
V_289 -> V_61 = V_156 ;
break;
case V_62 :
V_289 -> V_61 = V_352 ;
break;
default:
V_109 = - V_111 ;
goto V_353;
}
F_212 ( & V_289 -> V_51 , 1 ) ;
F_26 ( V_294 , & V_12 -> V_98 ) ;
if ( V_12 -> V_20 -> V_260 ) {
V_109 = V_12 -> V_20 -> V_260 ( V_12 ) ;
if ( V_109 < 0 ) {
F_69 ( V_12 -> V_15 . V_82 , L_47 ,
V_109 ) ;
goto V_354;
}
}
V_12 -> V_100 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_82 )
&& F_15 ( & V_12 -> V_15 . V_50 -> V_51 ) )
F_16 ( V_12 -> V_15 . V_82 , L_48 ) ;
F_178 ( & V_12 -> V_239 ) ;
F_178 ( & V_12 -> V_241 ) ;
if ( F_177 ( V_12 ) && V_333 ) {
V_109 = F_196 ( V_12 , V_333 , V_334 ) ;
if ( V_109 )
goto V_355;
}
V_12 -> V_284 = V_304 ;
V_109 = V_12 -> V_20 -> V_356 ( V_12 ) ;
if ( V_109 < 0 ) {
F_69 ( V_12 -> V_15 . V_82 , L_49 , V_109 ) ;
goto V_357;
}
V_109 = F_61 ( V_12 ) ;
if ( V_109 != 0 )
goto V_358;
V_109 = F_213 ( & V_289 -> V_51 . V_359 , & V_360 ) ;
if ( V_109 < 0 ) {
F_214 ( V_361 L_50 ,
V_109 ) ;
goto V_362;
}
if ( V_12 -> V_101 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
return V_109 ;
V_362:
F_25 ( V_294 , & V_12 -> V_98 ) ;
if ( F_215 ( V_12 -> V_284 ) )
V_12 -> V_284 = V_295 ;
F_7 ( & V_37 ) ;
V_12 -> V_157 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_216 ( & V_12 -> V_309 ) ;
#endif
F_52 ( & V_139 ) ;
F_217 ( & V_289 ) ;
F_55 ( & V_139 ) ;
V_358:
V_12 -> V_100 = 0 ;
F_25 ( V_319 , & V_12 -> V_98 ) ;
F_218 ( & V_12 -> V_105 ) ;
V_12 -> V_20 -> V_363 ( V_12 ) ;
V_12 -> V_284 = V_364 ;
F_25 ( V_319 , & V_12 -> V_98 ) ;
F_218 ( & V_12 -> V_105 ) ;
V_357:
if ( F_177 ( V_12 ) && V_12 -> V_314 > 0 )
F_219 ( V_333 , V_12 ) ;
V_355:
V_354:
V_353:
F_198 ( V_12 ) ;
V_350:
F_58 ( & V_12 -> V_15 ) ;
V_349:
F_220 ( V_12 ) ;
V_348:
if ( F_96 ( V_343 ) && V_12 -> V_342 && V_12 -> V_340 ) {
F_221 ( V_12 -> V_340 ) ;
F_209 ( V_12 -> V_340 ) ;
F_207 ( V_12 -> V_340 ) ;
V_12 -> V_340 = NULL ;
}
V_344:
if ( V_12 -> V_342 && V_12 -> V_339 ) {
F_222 ( V_12 -> V_339 ) ;
F_204 ( V_12 -> V_339 ) ;
V_12 -> V_339 = NULL ;
}
return V_109 ;
}
void F_223 ( struct V_11 * V_12 )
{
struct V_1 * V_289 = V_12 -> V_15 . V_50 ;
F_57 ( V_12 -> V_15 . V_82 , L_51 , V_12 -> V_284 ) ;
F_126 ( V_289 ) ;
F_224 ( & V_289 -> V_51 . V_359 , & V_360 ) ;
F_25 ( V_294 , & V_12 -> V_98 ) ;
if ( F_215 ( V_12 -> V_284 ) )
V_12 -> V_284 = V_295 ;
F_16 ( V_12 -> V_15 . V_82 , L_52 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_157 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_216 ( & V_12 -> V_309 ) ;
#endif
F_52 ( & V_139 ) ;
F_217 ( & V_289 ) ;
F_55 ( & V_139 ) ;
V_12 -> V_100 = 0 ;
F_25 ( V_319 , & V_12 -> V_98 ) ;
F_218 ( & V_12 -> V_105 ) ;
V_12 -> V_20 -> V_363 ( V_12 ) ;
V_12 -> V_284 = V_364 ;
F_25 ( V_319 , & V_12 -> V_98 ) ;
F_218 ( & V_12 -> V_105 ) ;
if ( F_177 ( V_12 ) ) {
if ( V_12 -> V_314 > 0 )
F_219 ( V_12 -> V_314 , V_12 ) ;
}
F_58 ( & V_12 -> V_15 ) ;
F_220 ( V_12 ) ;
if ( F_96 ( V_343 ) && V_12 -> V_342 && V_12 -> V_340 ) {
F_221 ( V_12 -> V_340 ) ;
F_209 ( V_12 -> V_340 ) ;
F_207 ( V_12 -> V_340 ) ;
V_12 -> V_340 = NULL ;
}
if ( V_12 -> V_342 && V_12 -> V_339 ) {
F_222 ( V_12 -> V_339 ) ;
F_204 ( V_12 -> V_339 ) ;
V_12 -> V_339 = NULL ;
}
F_198 ( V_12 ) ;
V_12 -> V_98 = 0 ;
}
void
F_225 ( struct V_365 * V_51 )
{
struct V_11 * V_12 = F_226 ( V_51 ) ;
if ( V_12 -> V_20 -> V_366 )
V_12 -> V_20 -> V_366 ( V_12 ) ;
}
int F_227 ( const struct V_367 * V_368 )
{
if ( V_369 )
return - V_183 ;
V_369 = V_368 ;
F_228 () ;
return 0 ;
}
void F_229 ( void )
{
if ( V_369 == NULL ) {
F_214 ( V_361 L_53 ) ;
return;
}
V_369 = NULL ;
F_228 () ;
}
