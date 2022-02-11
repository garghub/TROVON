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
default:
goto error;
}
V_6 = 18 ;
if ( V_12 -> V_70 )
V_33 = 1 ;
break;
case V_71 << 8 :
switch ( V_12 -> V_60 ) {
case V_61 :
case V_62 :
V_36 = V_72 ;
V_6 = sizeof V_72 ;
break;
case V_64 :
case V_66 :
V_36 = V_73 ;
V_6 = sizeof V_73 ;
break;
case V_68 :
V_36 = V_74 ;
V_6 = sizeof V_74 ;
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
case V_75 << 8 :
goto V_76;
default:
goto error;
}
break;
case V_47 | V_77 :
V_35 [ 0 ] = 0 ;
V_6 = 1 ;
case V_53 | V_78 :
break;
case V_53 | V_79 :
F_16 ( V_12 -> V_15 . V_80 , L_2 ,
V_26 ) ;
break;
case V_81 | V_48 :
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_6 = 2 ;
case V_82 | V_54 :
case V_82 | V_55 :
F_16 ( V_12 -> V_15 . V_80 , L_3 ) ;
break;
default:
V_76:
switch ( V_25 ) {
case V_83 :
case V_84 :
V_6 = 4 ;
break;
case V_85 :
V_6 = sizeof ( struct V_43 ) ;
break;
case V_47 | V_58 :
break;
}
V_31 = V_12 -> V_20 -> V_86 ( V_12 ,
V_25 , V_26 , V_27 ,
V_35 , V_28 ) ;
if ( V_25 == V_85 )
F_17 ( V_12 -> V_15 . V_49 ,
(struct V_43 * ) V_35 ) ;
break;
error:
V_31 = - V_87 ;
}
if ( V_31 < 0 ) {
V_6 = 0 ;
if ( V_31 != - V_87 ) {
F_16 ( V_12 -> V_15 . V_80 ,
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
V_6 > F_18 ( struct V_88 ,
V_89 ) )
( (struct V_88 * ) V_29 ) -> V_89
|= V_90 ;
if ( V_33 &&
V_6 > F_18 ( struct V_91 ,
V_92 ) )
( (struct V_91 * ) V_29 ) ->
V_92 = V_93 ;
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
int V_94 ;
unsigned long V_95 ;
char V_96 [ 6 ] ;
if ( F_23 ( ! V_12 -> V_97 ) )
return;
if ( ! V_12 -> V_98 && ! V_12 -> V_99 )
return;
V_94 = V_12 -> V_20 -> V_100 ( V_12 , V_96 ) ;
if ( V_94 > 0 ) {
F_24 ( & V_37 , V_95 ) ;
V_22 = V_12 -> V_99 ;
if ( V_22 ) {
F_25 ( V_101 , & V_12 -> V_95 ) ;
V_12 -> V_99 = NULL ;
V_22 -> V_46 = V_94 ;
memcpy ( V_22 -> V_30 , V_96 , V_94 ) ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , 0 ) ;
} else {
V_94 = 0 ;
F_26 ( V_101 , & V_12 -> V_95 ) ;
}
F_27 ( & V_37 , V_95 ) ;
}
if ( V_12 -> V_98 ? F_28 ( V_12 ) :
( V_94 == 0 && V_12 -> V_99 != NULL ) )
F_29 ( & V_12 -> V_102 , ( V_103 / ( V_104 / 4 ) + 1 ) * ( V_104 / 4 ) ) ;
}
static void F_30 ( unsigned long V_105 )
{
F_22 ( (struct V_11 * ) V_105 ) ;
}
static int F_31 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_106 ;
unsigned long V_95 ;
unsigned V_6 = 1 + ( V_22 -> V_50 -> V_107 / 8 ) ;
F_24 ( & V_37 , V_95 ) ;
if ( V_12 -> V_99 || V_22 -> V_42 < V_6 ) {
F_16 ( V_12 -> V_15 . V_80 , L_6 ) ;
V_106 = - V_108 ;
goto V_109;
}
V_106 = F_8 ( V_12 , V_22 ) ;
if ( V_106 )
goto V_109;
V_12 -> V_99 = V_22 ;
V_22 -> V_38 = V_12 ;
if ( ! V_12 -> V_98 )
F_29 ( & V_12 -> V_102 , ( V_103 / ( V_104 / 4 ) + 1 ) * ( V_104 / 4 ) ) ;
else if ( F_32 ( V_12 ) )
F_29 ( & V_12 -> V_102 , V_103 ) ;
V_106 = 0 ;
V_109:
F_27 ( & V_37 , V_95 ) ;
return V_106 ;
}
static int F_33 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_34 ( & V_22 -> V_110 -> V_111 ) )
return F_31 ( V_12 , V_22 ) ;
if ( F_35 ( & V_22 -> V_110 -> V_111 ) )
return F_5 ( V_12 , V_22 ) ;
return - V_108 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
unsigned long V_95 ;
int V_112 ;
F_24 ( & V_37 , V_95 ) ;
V_112 = F_37 ( V_12 , V_22 , V_31 ) ;
if ( V_112 )
goto V_109;
if ( F_38 ( & V_22 -> V_110 -> V_111 ) == 0 ) {
;
} else {
if ( ! V_12 -> V_98 )
F_39 ( & V_12 -> V_102 ) ;
if ( V_22 == V_12 -> V_99 ) {
V_12 -> V_99 = NULL ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , V_31 ) ;
}
}
V_109:
F_27 ( & V_37 , V_95 ) ;
return V_112 ;
}
static T_3 F_40 ( struct V_113 * V_50 ,
struct V_114 * V_115 , char * V_5 )
{
struct V_1 * V_116 = F_41 ( V_50 ) ;
struct V_117 * V_117 = V_116 -> V_118 ;
struct V_11 * V_12 ;
V_12 = F_42 ( V_117 ) ;
return snprintf ( V_5 , V_119 , L_7 , ! ! F_43 ( V_12 ) ) ;
}
static T_3 F_44 ( struct V_113 * V_50 ,
struct V_114 * V_115 ,
const char * V_5 , T_4 V_120 )
{
T_3 V_121 ;
unsigned V_122 ;
struct V_1 * V_116 = F_41 ( V_50 ) ;
struct V_117 * V_117 = V_116 -> V_118 ;
struct V_11 * V_12 ;
V_12 = F_42 ( V_117 ) ;
V_121 = sscanf ( V_5 , L_7 , & V_122 ) ;
if ( V_121 == 1 ) {
if ( V_122 )
F_26 ( V_123 , & V_12 -> V_95 ) ;
else
F_25 ( V_123 , & V_12 -> V_95 ) ;
V_121 = V_120 ;
} else {
V_121 = - V_108 ;
}
return V_121 ;
}
static T_3 F_45 ( struct V_113 * V_50 ,
struct V_114 * V_115 , char * V_5 )
{
struct V_1 * V_124 = F_41 ( V_50 ) ;
struct V_11 * V_12 = F_42 ( V_124 -> V_118 ) ;
return sprintf ( V_5 , L_7 , ! ! F_46 ( V_12 ) ) ;
}
static T_3 F_47 ( struct V_113 * V_50 ,
struct V_114 * V_115 , const char * V_5 , T_4 V_125 )
{
struct V_1 * V_124 = F_41 ( V_50 ) ;
struct V_11 * V_12 = F_42 ( V_124 -> V_118 ) ;
int V_112 = V_125 ;
bool V_122 ;
if ( F_48 ( V_5 , & V_122 ) != 0 )
return - V_108 ;
if ( V_122 )
F_26 ( V_126 , & V_12 -> V_95 ) ;
else
F_25 ( V_126 , & V_12 -> V_95 ) ;
return V_112 ;
}
static void F_49 ( struct V_117 * V_118 )
{
memset ( & V_118 -> V_127 , 0 , sizeof( struct V_128 ) ) ;
V_118 -> V_129 = 1 ;
V_118 -> V_49 = NULL ;
V_118 -> V_130 = - 1 ;
V_118 -> V_131 = 0 ;
V_118 -> V_132 = 0 ;
V_118 -> V_133 = 0 ;
F_50 ( & V_118 -> V_134 ) ;
F_51 ( & V_118 -> V_135 ) ;
}
static int F_52 ( struct V_117 * V_118 )
{
int V_121 = - V_136 ;
int V_130 ;
F_53 ( & V_137 ) ;
V_130 = F_54 ( V_138 , V_139 , 1 ) ;
if ( V_130 >= V_139 ) {
F_55 ( V_140 L_8 , V_141 ) ;
goto V_142;
}
F_26 ( V_130 , V_138 ) ;
V_118 -> V_130 = V_130 ;
F_56 ( & V_118 -> V_135 , & V_143 ) ;
F_57 ( & V_137 ) ;
F_58 ( V_118 ) ;
F_59 ( V_118 -> V_80 , L_9
L_10 , V_118 -> V_130 ) ;
return 0 ;
V_142:
F_57 ( & V_137 ) ;
return V_121 ;
}
static void F_60 ( struct V_117 * V_118 )
{
F_59 ( V_118 -> V_80 , L_11 , V_118 -> V_130 ) ;
F_53 ( & V_137 ) ;
F_61 ( & V_118 -> V_135 ) ;
F_57 ( & V_137 ) ;
F_62 ( V_118 ) ;
F_25 ( V_118 -> V_130 , V_138 ) ;
}
static int F_63 ( struct V_11 * V_12 )
{
struct V_113 * V_144 = V_12 -> V_15 . V_80 ;
struct V_1 * V_124 = V_12 -> V_15 . V_49 ;
const int V_145 = 1 ;
int V_106 ;
V_124 -> V_145 = V_145 ;
V_124 -> V_118 -> V_129 = V_145 + 1 ;
memset ( & V_124 -> V_118 -> V_127 . V_146 , 0 ,
sizeof V_124 -> V_118 -> V_127 . V_146 ) ;
F_26 ( V_145 , V_124 -> V_118 -> V_127 . V_146 ) ;
F_64 ( V_124 , V_147 ) ;
F_53 ( & V_137 ) ;
V_124 -> V_148 . V_111 . V_149 = F_65 ( 64 ) ;
V_106 = F_66 ( V_124 , V_150 ) ;
if ( V_106 != sizeof V_124 -> V_151 ) {
F_57 ( & V_137 ) ;
F_16 ( V_144 , L_12 ,
F_67 ( & V_124 -> V_50 ) , V_106 ) ;
return ( V_106 < 0 ) ? V_106 : - V_152 ;
}
if ( F_10 ( V_124 -> V_151 . V_153 ) >= 0x0201 ) {
V_106 = F_68 ( V_124 ) ;
if ( ! V_106 ) {
V_124 -> V_154 = F_69 ( V_124 ) ;
} else if ( V_124 -> V_60 == V_155 ) {
F_57 ( & V_137 ) ;
F_16 ( V_144 , L_13 ,
F_67 ( & V_124 -> V_50 ) , V_106 ) ;
return V_106 ;
}
}
V_106 = F_70 ( V_124 ) ;
if ( V_106 ) {
F_71 ( V_144 , L_14 ,
F_67 ( & V_124 -> V_50 ) , V_106 ) ;
} else {
F_7 ( & V_37 ) ;
V_12 -> V_156 = 1 ;
F_9 ( & V_37 ) ;
if ( F_72 ( V_12 ) )
F_73 ( V_12 ) ;
}
F_57 ( & V_137 ) ;
return V_106 ;
}
void F_74 ( struct V_117 * V_118 , int V_157 )
{
unsigned V_158 = 1 << V_157 ;
if ( ! ( V_118 -> V_159 & V_158 ) ) {
V_118 -> V_159 |= V_158 ;
F_75 ( & V_118 -> V_49 -> V_50 ) ;
}
}
void F_76 ( struct V_117 * V_118 , int V_157 )
{
unsigned V_158 = 1 << V_157 ;
if ( V_118 -> V_159 & V_158 ) {
V_118 -> V_159 &= ~ V_158 ;
F_77 ( & V_118 -> V_49 -> V_50 ) ;
}
}
long F_78 ( int V_60 , int V_160 , int V_161 , int V_162 )
{
unsigned long V_163 ;
switch ( V_60 ) {
case V_164 :
if ( V_160 ) {
V_163 = ( 67667L * ( 31L + 10L * F_79 ( V_162 ) ) ) / 1000L ;
return 64060L + ( 2 * V_165 ) + V_166 + V_163 ;
} else {
V_163 = ( 66700L * ( 31L + 10L * F_79 ( V_162 ) ) ) / 1000L ;
return 64107L + ( 2 * V_165 ) + V_166 + V_163 ;
}
case V_167 :
if ( V_161 ) {
V_163 = ( 8354L * ( 31L + 10L * F_79 ( V_162 ) ) ) / 1000L ;
return ( ( V_160 ) ? 7268L : 6265L ) + V_166 + V_163 ;
} else {
V_163 = ( 8354L * ( 31L + 10L * F_79 ( V_162 ) ) ) / 1000L ;
return 9107L + V_166 + V_163 ;
}
case V_168 :
if ( V_161 )
V_163 = F_80 ( V_162 ) ;
else
V_163 = F_81 ( V_162 ) ;
return V_163 ;
default:
F_82 ( L_15 , V_141 ) ;
return - 1 ;
}
}
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_112 = 0 ;
F_83 ( & V_169 ) ;
if ( F_23 ( F_84 ( & V_22 -> V_170 ) ) ) {
V_112 = - V_171 ;
goto V_109;
}
if ( F_23 ( ! V_22 -> V_110 -> V_172 ) ) {
V_112 = - V_173 ;
goto V_109;
}
if ( F_23 ( ! V_22 -> V_50 -> V_174 ) ) {
V_112 = - V_175 ;
goto V_109;
}
if ( F_85 ( V_12 ) ) {
V_22 -> V_176 = 0 ;
F_86 ( & V_22 -> V_177 , & V_22 -> V_110 -> V_177 ) ;
} else {
V_112 = - V_178 ;
goto V_109;
}
V_109:
F_87 ( & V_169 ) ;
return V_112 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_179 * V_163 ;
F_88 (tmp, &urb->ep->urb_list) {
if ( V_163 == & V_22 -> V_177 )
break;
}
if ( V_163 != & V_22 -> V_177 )
return - V_180 ;
if ( V_22 -> V_176 )
return - V_181 ;
V_22 -> V_176 = V_31 ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
F_83 ( & V_169 ) ;
F_89 ( & V_22 -> V_177 ) ;
F_87 ( & V_169 ) ;
}
static int F_90 ( struct V_117 * V_118 ,
T_5 V_182 , T_6 * V_183 ,
void * * V_184 , T_4 V_120 ,
enum V_185 V_186 )
{
unsigned char * V_187 ;
if ( * V_184 == NULL ) {
F_91 ( 1 ) ;
return - V_188 ;
}
V_187 = F_92 ( V_118 , V_120 + sizeof( V_187 ) ,
V_182 , V_183 ) ;
if ( ! V_187 )
return - V_45 ;
F_93 ( ( unsigned long ) * V_184 ,
( unsigned long * ) ( V_187 + V_120 ) ) ;
if ( V_186 == V_189 )
memcpy ( V_187 , * V_184 , V_120 ) ;
* V_184 = V_187 ;
return 0 ;
}
static void F_94 ( struct V_117 * V_118 , T_6 * V_183 ,
void * * V_184 , T_4 V_120 ,
enum V_185 V_186 )
{
unsigned char * V_187 = * V_184 ;
V_187 = ( void * ) F_95 ( ( unsigned long * ) ( V_187 + V_120 ) ) ;
if ( V_186 == V_190 )
memcpy ( V_187 , * V_184 , V_120 ) ;
F_96 ( V_118 , V_120 + sizeof( V_187 ) , * V_184 , * V_183 ) ;
* V_184 = V_187 ;
* V_183 = 0 ;
}
void F_97 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_22 -> V_191 & V_192 )
F_98 ( V_12 -> V_15 . V_80 ,
V_22 -> V_193 ,
sizeof( struct V_23 ) ,
V_189 ) ;
else if ( V_22 -> V_191 & V_194 )
F_94 ( V_22 -> V_50 -> V_118 ,
& V_22 -> V_193 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_189 ) ;
V_22 -> V_191 &= ~ ( V_192 | V_194 ) ;
}
static void F_99 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( V_12 -> V_20 -> F_99 )
V_12 -> V_20 -> F_99 ( V_12 , V_22 ) ;
else
F_100 ( V_12 , V_22 ) ;
}
void F_100 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
enum V_185 V_186 ;
F_97 ( V_12 , V_22 ) ;
V_186 = F_101 ( V_22 ) ? V_190 : V_189 ;
if ( V_22 -> V_191 & V_195 )
F_102 ( V_12 -> V_15 . V_80 ,
V_22 -> V_196 ,
V_22 -> V_197 ,
V_186 ) ;
else if ( V_22 -> V_191 & V_198 )
F_103 ( V_12 -> V_15 . V_80 ,
V_22 -> V_199 ,
V_22 -> V_42 ,
V_186 ) ;
else if ( V_22 -> V_191 & V_200 )
F_98 ( V_12 -> V_15 . V_80 ,
V_22 -> V_199 ,
V_22 -> V_42 ,
V_186 ) ;
else if ( V_22 -> V_191 & V_201 )
F_94 ( V_22 -> V_50 -> V_118 ,
& V_22 -> V_199 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_186 ) ;
V_22 -> V_191 &= ~ ( V_195 | V_198 |
V_200 | V_201 ) ;
}
static int F_104 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_182 )
{
if ( V_12 -> V_20 -> F_104 )
return V_12 -> V_20 -> F_104 ( V_12 , V_22 , V_182 ) ;
else
return F_105 ( V_12 , V_22 , V_182 ) ;
}
int F_105 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_182 )
{
enum V_185 V_186 ;
int V_202 = 0 ;
if ( F_35 ( & V_22 -> V_110 -> V_111 ) ) {
if ( V_12 -> V_15 . V_203 )
return V_202 ;
if ( V_12 -> V_15 . V_204 ) {
V_22 -> V_193 = F_106 (
V_12 -> V_15 . V_80 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_189 ) ;
if ( F_107 ( V_12 -> V_15 . V_80 ,
V_22 -> V_193 ) )
return - V_205 ;
V_22 -> V_191 |= V_192 ;
} else if ( V_12 -> V_20 -> V_95 & V_206 ) {
V_202 = F_90 (
V_22 -> V_50 -> V_118 , V_182 ,
& V_22 -> V_193 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_189 ) ;
if ( V_202 )
return V_202 ;
V_22 -> V_191 |= V_194 ;
}
}
V_186 = F_101 ( V_22 ) ? V_190 : V_189 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_191 & V_207 ) ) {
if ( V_12 -> V_15 . V_204 ) {
if ( V_22 -> V_197 ) {
int V_7 ;
if ( F_108 ( & V_22 -> V_110 -> V_111 ) ) {
F_109 ( 1 ) ;
return - V_108 ;
}
V_7 = F_110 (
V_12 -> V_15 . V_80 ,
V_22 -> V_196 ,
V_22 -> V_197 ,
V_186 ) ;
if ( V_7 <= 0 )
V_202 = - V_205 ;
else
V_22 -> V_191 |= V_195 ;
V_22 -> V_208 = V_7 ;
if ( V_7 != V_22 -> V_197 )
V_22 -> V_191 |=
V_209 ;
} else if ( V_22 -> V_196 ) {
struct V_210 * V_196 = V_22 -> V_196 ;
V_22 -> V_199 = F_111 (
V_12 -> V_15 . V_80 ,
F_112 ( V_196 ) ,
V_196 -> V_211 ,
V_22 -> V_42 ,
V_186 ) ;
if ( F_107 ( V_12 -> V_15 . V_80 ,
V_22 -> V_199 ) )
V_202 = - V_205 ;
else
V_22 -> V_191 |= V_198 ;
} else if ( F_113 ( V_22 -> V_30 ) ) {
F_114 ( 1 , L_16 ) ;
V_202 = - V_205 ;
} else {
V_22 -> V_199 = F_106 (
V_12 -> V_15 . V_80 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_186 ) ;
if ( F_107 ( V_12 -> V_15 . V_80 ,
V_22 -> V_199 ) )
V_202 = - V_205 ;
else
V_22 -> V_191 |= V_200 ;
}
} else if ( V_12 -> V_20 -> V_95 & V_206 ) {
V_202 = F_90 (
V_22 -> V_50 -> V_118 , V_182 ,
& V_22 -> V_199 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_186 ) ;
if ( V_202 == 0 )
V_22 -> V_191 |= V_201 ;
}
if ( V_202 && ( V_22 -> V_191 & ( V_192 |
V_194 ) ) )
F_100 ( V_12 , V_22 ) ;
}
return V_202 ;
}
int F_115 ( struct V_22 * V_22 , T_5 V_182 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_118 ) ;
F_116 ( V_22 ) ;
F_117 ( & V_22 -> V_212 ) ;
F_117 ( & V_22 -> V_50 -> V_213 ) ;
F_118 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_50 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_104 ( V_12 , V_22 , V_182 ) ;
if ( F_119 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_214 ( V_12 , V_22 , V_182 ) ;
if ( F_23 ( V_31 ) )
F_99 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_120 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_51 ( & V_22 -> V_177 ) ;
F_121 ( & V_22 -> V_212 ) ;
F_121 ( & V_22 -> V_50 -> V_213 ) ;
if ( F_84 ( & V_22 -> V_170 ) )
F_122 ( & V_215 ) ;
F_123 ( V_22 ) ;
}
return V_31 ;
}
static int F_124 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_216 ;
if ( F_1 ( V_22 -> V_50 ) )
V_216 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_216 = V_12 -> V_20 -> V_217 ( V_12 , V_22 , V_31 ) ;
}
return V_216 ;
}
int F_125 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_22 -> V_50 ;
int V_106 = - V_180 ;
unsigned long V_95 ;
F_24 ( & V_218 , V_95 ) ;
if ( F_84 ( & V_22 -> V_212 ) > 0 ) {
V_106 = 0 ;
F_126 ( V_2 ) ;
}
F_27 ( & V_218 , V_95 ) ;
if ( V_106 == 0 ) {
V_12 = F_42 ( V_22 -> V_50 -> V_118 ) ;
V_106 = F_124 ( V_12 , V_22 , V_31 ) ;
if ( V_106 == 0 )
V_106 = - V_219 ;
else if ( V_106 != - V_180 && V_106 != - V_181 )
F_16 ( & V_2 -> V_50 , L_17 ,
V_22 , V_106 ) ;
F_127 ( V_2 ) ;
}
return V_106 ;
}
static void F_128 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_118 ) ;
struct V_220 * V_221 = V_22 -> V_221 ;
int V_31 = V_22 -> V_176 ;
unsigned long V_95 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_191 & V_222 ) &&
V_22 -> V_46 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_223 ;
F_99 ( V_12 , V_22 ) ;
F_129 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_130 ( V_221 ) ;
F_131 ( V_22 ) ;
if ( F_119 ( V_31 == 0 ) )
F_132 ( V_224 ) ;
V_22 -> V_31 = V_31 ;
F_133 ( V_95 ) ;
V_22 -> V_225 ( V_22 ) ;
F_134 ( V_95 ) ;
F_135 ( V_221 ) ;
F_121 ( & V_22 -> V_212 ) ;
if ( F_23 ( F_84 ( & V_22 -> V_170 ) ) )
F_122 ( & V_215 ) ;
F_123 ( V_22 ) ;
}
static void F_136 ( unsigned long V_226 )
{
struct V_227 * V_228 = (struct V_227 * ) V_226 ;
struct V_179 V_229 ;
F_7 ( & V_228 -> V_230 ) ;
V_228 -> V_231 = true ;
V_232:
F_137 ( & V_228 -> V_233 , & V_229 ) ;
F_9 ( & V_228 -> V_230 ) ;
while ( ! F_138 ( & V_229 ) ) {
struct V_22 * V_22 ;
V_22 = F_139 ( V_229 . V_234 , struct V_22 , V_177 ) ;
F_89 ( & V_22 -> V_177 ) ;
V_228 -> V_235 = V_22 -> V_110 ;
F_128 ( V_22 ) ;
V_228 -> V_235 = NULL ;
}
F_7 ( & V_228 -> V_230 ) ;
if ( ! F_138 ( & V_228 -> V_233 ) )
goto V_232;
V_228 -> V_231 = false ;
F_9 ( & V_228 -> V_230 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_227 * V_228 ;
bool V_231 , V_236 ;
if ( F_119 ( ! V_22 -> V_176 ) )
V_22 -> V_176 = V_31 ;
if ( ! F_140 ( V_12 ) && ! F_1 ( V_22 -> V_50 ) ) {
F_128 ( V_22 ) ;
return;
}
if ( F_141 ( V_22 -> V_237 ) || F_142 ( V_22 -> V_237 ) ) {
V_228 = & V_12 -> V_236 ;
V_236 = true ;
} else {
V_228 = & V_12 -> V_238 ;
V_236 = false ;
}
F_83 ( & V_228 -> V_230 ) ;
F_86 ( & V_22 -> V_177 , & V_228 -> V_233 ) ;
V_231 = V_228 -> V_231 ;
F_87 ( & V_228 -> V_230 ) ;
if ( V_231 )
;
else if ( V_236 )
F_143 ( & V_228 -> V_228 ) ;
else
F_144 ( & V_228 -> V_228 ) ;
}
void F_145 ( struct V_1 * V_2 ,
struct V_239 * V_110 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_110 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_118 ) ;
F_7 ( & V_169 ) ;
V_240:
F_146 (urb, &ep->urb_list, urb_list) {
int V_241 ;
if ( V_22 -> V_176 )
continue;
F_116 ( V_22 ) ;
V_241 = F_101 ( V_22 ) ;
F_87 ( & V_169 ) ;
F_124 ( V_12 , V_22 , - V_178 ) ;
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
F_83 ( & V_169 ) ;
goto V_240;
}
F_9 ( & V_169 ) ;
while ( ! F_138 ( & V_110 -> V_177 ) ) {
F_7 ( & V_169 ) ;
V_22 = NULL ;
if ( ! F_138 ( & V_110 -> V_177 ) ) {
V_22 = F_139 ( V_110 -> V_177 . V_242 , struct V_22 ,
V_177 ) ;
F_116 ( V_22 ) ;
}
F_9 ( & V_169 ) ;
if ( V_22 ) {
F_147 ( V_22 ) ;
F_123 ( V_22 ) ;
}
}
}
int F_148 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 ,
struct V_245 * V_247 )
{
int V_248 , V_249 , V_250 ;
struct V_245 * V_251 = NULL ;
int V_202 = 0 ;
struct V_11 * V_12 ;
struct V_239 * V_110 ;
V_12 = F_42 ( V_2 -> V_118 ) ;
if ( ! V_12 -> V_20 -> V_252 )
return 0 ;
if ( ! V_244 && ! V_246 ) {
for ( V_249 = 1 ; V_249 < 16 ; ++ V_249 ) {
V_110 = V_2 -> V_253 [ V_249 ] ;
if ( V_110 )
V_12 -> V_20 -> V_254 ( V_12 , V_2 , V_110 ) ;
V_110 = V_2 -> V_255 [ V_249 ] ;
if ( V_110 )
V_12 -> V_20 -> V_254 ( V_12 , V_2 , V_110 ) ;
}
V_12 -> V_20 -> V_252 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_244 ) {
V_248 = V_244 -> V_111 . V_256 ;
for ( V_249 = 1 ; V_249 < 16 ; ++ V_249 ) {
V_110 = V_2 -> V_253 [ V_249 ] ;
if ( V_110 ) {
V_202 = V_12 -> V_20 -> V_254 ( V_12 , V_2 , V_110 ) ;
if ( V_202 < 0 )
goto V_257;
}
V_110 = V_2 -> V_255 [ V_249 ] ;
if ( V_110 ) {
V_202 = V_12 -> V_20 -> V_254 ( V_12 , V_2 , V_110 ) ;
if ( V_202 < 0 )
goto V_257;
}
}
for ( V_249 = 0 ; V_249 < V_248 ; ++ V_249 ) {
struct V_245 * V_258 ;
int V_259 ;
V_258 = & V_244 -> V_260 [ V_249 ] -> V_261 [ 0 ] ;
V_259 = V_258 -> V_111 . V_262 ;
V_251 = F_149 ( V_244 , V_259 , 0 ) ;
if ( ! V_251 )
V_251 = V_258 ;
for ( V_250 = 0 ; V_250 < V_251 -> V_111 . V_263 ; V_250 ++ ) {
V_202 = V_12 -> V_20 -> V_264 ( V_12 , V_2 , & V_251 -> V_265 [ V_250 ] ) ;
if ( V_202 < 0 )
goto V_257;
}
}
}
if ( V_246 && V_247 ) {
struct V_266 * V_267 = F_150 ( V_2 ,
V_246 -> V_111 . V_262 ) ;
if ( ! V_267 )
return - V_108 ;
if ( V_267 -> V_268 ) {
V_246 = F_151 ( V_267 , 0 ) ;
if ( ! V_246 )
V_246 = & V_267 -> V_261 [ 0 ] ;
}
for ( V_249 = 0 ; V_249 < V_246 -> V_111 . V_263 ; V_249 ++ ) {
V_202 = V_12 -> V_20 -> V_254 ( V_12 , V_2 ,
& V_246 -> V_265 [ V_249 ] ) ;
if ( V_202 < 0 )
goto V_257;
}
for ( V_249 = 0 ; V_249 < V_247 -> V_111 . V_263 ; V_249 ++ ) {
V_202 = V_12 -> V_20 -> V_264 ( V_12 , V_2 ,
& V_247 -> V_265 [ V_249 ] ) ;
if ( V_202 < 0 )
goto V_257;
}
}
V_202 = V_12 -> V_20 -> V_252 ( V_12 , V_2 ) ;
V_257:
if ( V_202 < 0 )
V_12 -> V_20 -> V_269 ( V_12 , V_2 ) ;
return V_202 ;
}
void F_152 ( struct V_1 * V_2 ,
struct V_239 * V_110 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_118 ) ;
if ( V_12 -> V_20 -> V_270 )
V_12 -> V_20 -> V_270 ( V_12 , V_110 ) ;
}
void F_153 ( struct V_1 * V_2 ,
struct V_239 * V_110 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_118 ) ;
if ( V_12 -> V_20 -> V_271 )
V_12 -> V_20 -> V_271 ( V_12 , V_110 ) ;
else {
int V_272 = F_38 ( & V_110 -> V_111 ) ;
int V_273 = F_154 ( & V_110 -> V_111 ) ;
int V_274 = F_35 ( & V_110 -> V_111 ) ;
F_155 ( V_2 , V_272 , V_273 , 0 ) ;
if ( V_274 )
F_155 ( V_2 , V_272 , ! V_273 , 0 ) ;
}
}
int F_156 ( struct V_266 * V_275 ,
struct V_239 * * V_276 , unsigned int V_277 ,
unsigned int V_278 , T_5 V_182 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_249 , V_202 ;
V_50 = F_157 ( V_275 ) ;
V_12 = F_42 ( V_50 -> V_118 ) ;
if ( ! V_12 -> V_20 -> V_279 || ! V_12 -> V_20 -> V_280 )
return - V_108 ;
if ( V_50 -> V_60 != V_155 )
return - V_108 ;
if ( V_50 -> V_281 < V_282 )
return - V_283 ;
for ( V_249 = 0 ; V_249 < V_277 ; V_249 ++ ) {
if ( ! F_158 ( & V_276 [ V_249 ] -> V_111 ) )
return - V_108 ;
if ( V_276 [ V_249 ] -> V_284 )
return - V_108 ;
}
V_202 = V_12 -> V_20 -> V_279 ( V_12 , V_50 , V_276 , V_277 ,
V_278 , V_182 ) ;
if ( V_202 < 0 )
return V_202 ;
for ( V_249 = 0 ; V_249 < V_277 ; V_249 ++ )
V_276 [ V_249 ] -> V_284 = V_202 ;
return V_202 ;
}
int F_159 ( struct V_266 * V_275 ,
struct V_239 * * V_276 , unsigned int V_277 ,
T_5 V_182 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_249 , V_202 ;
V_50 = F_157 ( V_275 ) ;
V_12 = F_42 ( V_50 -> V_118 ) ;
if ( V_50 -> V_60 != V_155 )
return - V_108 ;
for ( V_249 = 0 ; V_249 < V_277 ; V_249 ++ )
if ( ! V_276 [ V_249 ] || ! V_276 [ V_249 ] -> V_284 )
return - V_108 ;
V_202 = V_12 -> V_20 -> V_280 ( V_12 , V_50 , V_276 , V_277 , V_182 ) ;
if ( V_202 < 0 )
return V_202 ;
for ( V_249 = 0 ; V_249 < V_277 ; V_249 ++ )
V_276 [ V_249 ] -> V_284 = 0 ;
return V_202 ;
}
void F_160 ( struct V_1 * V_2 )
{
F_7 ( & V_218 ) ;
F_9 ( & V_218 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_118 ) ;
if ( ! F_85 ( V_12 ) )
return - V_178 ;
return V_12 -> V_20 -> V_285 ( V_12 ) ;
}
int F_162 ( struct V_1 * V_286 , T_7 V_287 )
{
struct V_11 * V_12 = F_163 ( V_286 -> V_118 , struct V_11 , V_15 ) ;
int V_31 ;
int V_288 = V_12 -> V_281 ;
F_16 ( & V_286 -> V_50 , L_25 ,
( F_164 ( V_287 ) ? L_26 : L_21 ) ,
V_286 -> V_289 ) ;
if ( F_72 ( V_12 ) ) {
F_16 ( & V_286 -> V_50 , L_27 , L_28 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_290 ) {
V_31 = - V_173 ;
} else {
F_25 ( V_291 , & V_12 -> V_95 ) ;
V_12 -> V_281 = V_292 ;
V_31 = V_12 -> V_20 -> V_290 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_64 ( V_286 , V_293 ) ;
V_12 -> V_281 = V_294 ;
if ( V_286 -> V_289 ) {
char V_96 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_100 ( V_12 , V_96 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_286 -> V_50 , L_29 ) ;
F_165 ( V_286 , V_295 ) ;
V_31 = - V_181 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_72 ( V_12 ) ) {
F_26 ( V_291 , & V_12 -> V_95 ) ;
V_12 -> V_281 = V_288 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_286 -> V_50 , L_30 ,
L_28 , V_31 ) ;
}
return V_31 ;
}
int F_165 ( struct V_1 * V_286 , T_7 V_287 )
{
struct V_11 * V_12 = F_163 ( V_286 -> V_118 , struct V_11 , V_15 ) ;
int V_31 ;
int V_288 = V_12 -> V_281 ;
F_16 ( & V_286 -> V_50 , L_31 ,
( F_164 ( V_287 ) ? L_26 : L_21 ) ) ;
if ( F_72 ( V_12 ) ) {
F_16 ( & V_286 -> V_50 , L_27 , L_32 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_296 )
return - V_173 ;
if ( F_85 ( V_12 ) )
return 0 ;
V_12 -> V_281 = V_297 ;
V_31 = V_12 -> V_20 -> V_296 ( V_12 ) ;
F_25 ( V_298 , & V_12 -> V_95 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_299 ;
F_7 ( & V_37 ) ;
if ( ! F_72 ( V_12 ) ) {
F_64 ( V_286 , V_286 -> V_300
? V_282
: V_147 ) ;
F_26 ( V_291 , & V_12 -> V_95 ) ;
V_12 -> V_281 = V_301 ;
}
F_9 ( & V_37 ) ;
F_166 (rhdev, port1, udev) {
if ( V_2 -> V_281 != V_302 &&
! V_2 -> V_303 ) {
F_167 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_281 = V_288 ;
F_16 ( & V_286 -> V_50 , L_30 ,
L_32 , V_31 ) ;
if ( V_31 != - V_178 )
F_73 ( V_12 ) ;
}
return V_31 ;
}
static void F_168 ( struct V_304 * V_305 )
{
struct V_11 * V_12 = F_163 ( V_305 , struct V_11 , V_306 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_49 ;
F_169 ( V_2 ) ;
}
void F_170 ( struct V_11 * V_12 )
{
unsigned long V_95 ;
F_24 ( & V_37 , V_95 ) ;
if ( V_12 -> V_156 ) {
F_26 ( V_298 , & V_12 -> V_95 ) ;
F_171 ( V_307 , & V_12 -> V_306 ) ;
}
F_27 ( & V_37 , V_95 ) ;
}
int F_172 ( struct V_117 * V_118 , unsigned V_308 )
{
struct V_11 * V_12 ;
int V_31 = - V_309 ;
V_12 = F_163 ( V_118 , struct V_11 , V_15 ) ;
if ( V_308 && V_12 -> V_20 -> V_310 )
V_31 = V_12 -> V_20 -> V_310 ( V_12 , V_308 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_102 , V_103 + F_173 ( 10 ) ) ;
return V_31 ;
}
T_8 F_174 ( int V_311 , void * V_312 )
{
struct V_11 * V_12 = V_312 ;
T_8 V_112 ;
if ( F_23 ( F_72 ( V_12 ) || ! F_175 ( V_12 ) ) )
V_112 = V_313 ;
else if ( V_12 -> V_20 -> V_311 ( V_12 ) == V_313 )
V_112 = V_313 ;
else
V_112 = V_314 ;
return V_112 ;
}
void F_73 ( struct V_11 * V_12 )
{
unsigned long V_95 ;
F_71 ( V_12 -> V_15 . V_80 , L_33 ) ;
F_24 ( & V_37 , V_95 ) ;
F_25 ( V_291 , & V_12 -> V_95 ) ;
F_26 ( V_315 , & V_12 -> V_95 ) ;
if ( V_12 -> V_156 ) {
F_25 ( V_316 , & V_12 -> V_95 ) ;
F_64 ( V_12 -> V_15 . V_49 ,
V_302 ) ;
F_176 ( V_12 -> V_15 . V_49 ) ;
}
if ( F_177 ( V_12 ) && V_12 -> V_317 ) {
V_12 = V_12 -> V_317 ;
if ( V_12 -> V_156 ) {
F_25 ( V_316 , & V_12 -> V_95 ) ;
F_64 ( V_12 -> V_15 . V_49 ,
V_302 ) ;
F_176 ( V_12 -> V_15 . V_49 ) ;
}
}
F_27 ( & V_37 , V_95 ) ;
}
static void F_178 ( struct V_227 * V_228 )
{
F_179 ( & V_228 -> V_230 ) ;
F_51 ( & V_228 -> V_233 ) ;
F_180 ( & V_228 -> V_228 , F_136 , ( unsigned long ) V_228 ) ;
}
struct V_11 * F_181 ( const struct V_318 * V_20 ,
struct V_113 * V_50 , const char * V_16 ,
struct V_11 * V_319 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_320 , V_44 ) ;
if ( ! V_12 ) {
F_16 ( V_50 , L_34 ) ;
return NULL ;
}
if ( V_319 == NULL ) {
V_12 -> V_321 = F_182 ( sizeof( * V_12 -> V_321 ) ,
V_44 ) ;
if ( ! V_12 -> V_321 ) {
F_19 ( V_12 ) ;
F_16 ( V_50 , L_35 ) ;
return NULL ;
}
F_50 ( V_12 -> V_321 ) ;
F_183 ( V_50 , V_12 ) ;
} else {
F_53 ( & V_322 ) ;
V_12 -> V_321 = V_319 -> V_321 ;
V_12 -> V_319 = V_319 ;
V_319 -> V_319 = V_319 ;
V_12 -> V_317 = V_319 ;
V_319 -> V_317 = V_12 ;
F_57 ( & V_322 ) ;
}
F_184 ( & V_12 -> V_323 ) ;
F_49 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_80 = V_50 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_204 = ( V_50 -> V_324 != NULL ) ;
F_185 ( & V_12 -> V_102 ) ;
V_12 -> V_102 . V_325 = F_30 ;
V_12 -> V_102 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_186
F_187 ( & V_12 -> V_306 , F_168 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_60 = V_20 -> V_95 & V_326 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_36 ;
return V_12 ;
}
struct V_11 * F_188 ( const struct V_318 * V_20 ,
struct V_113 * V_50 , const char * V_16 )
{
return F_181 ( V_20 , V_50 , V_16 , NULL ) ;
}
static void F_189 ( struct V_323 * V_323 )
{
struct V_11 * V_12 = F_163 ( V_323 , struct V_11 , V_323 ) ;
F_53 ( & V_322 ) ;
if ( F_177 ( V_12 ) )
F_19 ( V_12 -> V_321 ) ;
if ( V_12 -> V_317 ) {
struct V_11 * V_327 = V_12 -> V_317 ;
V_327 -> V_317 = NULL ;
if ( V_327 -> V_319 == V_12 )
V_327 -> V_319 = NULL ;
}
F_57 ( & V_322 ) ;
F_19 ( V_12 ) ;
}
struct V_11 * F_190 ( struct V_11 * V_12 )
{
if ( V_12 )
F_191 ( & V_12 -> V_323 ) ;
return V_12 ;
}
void F_192 ( struct V_11 * V_12 )
{
if ( V_12 )
F_193 ( & V_12 -> V_323 , F_189 ) ;
}
int F_177 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_319 )
return 1 ;
return V_12 == V_12 -> V_319 ;
}
int F_194 ( struct V_11 * V_12 , int V_299 )
{
if ( ! V_12 -> V_20 -> V_328 )
return V_299 ;
return V_12 -> V_20 -> V_328 ( V_12 , V_299 ) ;
}
static int F_195 ( struct V_11 * V_12 ,
unsigned int V_329 , unsigned long V_330 )
{
int V_106 ;
if ( V_12 -> V_20 -> V_311 ) {
snprintf ( V_12 -> V_331 , sizeof( V_12 -> V_331 ) , L_37 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_130 ) ;
V_106 = F_196 ( V_329 , & F_174 , V_330 ,
V_12 -> V_331 , V_12 ) ;
if ( V_106 != 0 ) {
F_71 ( V_12 -> V_15 . V_80 ,
L_38 ,
V_329 ) ;
return V_106 ;
}
V_12 -> V_311 = V_329 ;
F_59 ( V_12 -> V_15 . V_80 , L_39 , V_329 ,
( V_12 -> V_20 -> V_95 & V_332 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_333 ) ;
} else {
V_12 -> V_311 = 0 ;
if ( V_12 -> V_333 )
F_59 ( V_12 -> V_15 . V_80 , L_42 ,
( V_12 -> V_20 -> V_95 & V_332 ) ?
L_40 : L_41 ,
( unsigned long long ) V_12 -> V_333 ) ;
}
return 0 ;
}
static void F_197 ( struct V_11 * V_12 )
{
struct V_1 * V_286 ;
F_53 ( & V_322 ) ;
V_286 = V_12 -> V_15 . V_49 ;
V_12 -> V_15 . V_49 = NULL ;
F_57 ( & V_322 ) ;
F_127 ( V_286 ) ;
}
int F_198 ( struct V_11 * V_12 ,
unsigned int V_329 , unsigned long V_330 )
{
int V_106 ;
struct V_1 * V_286 ;
if ( F_199 ( V_334 ) && ! V_12 -> V_335 ) {
struct V_335 * V_336 = F_200 ( V_12 -> V_15 . V_80 , 0 ) ;
if ( F_201 ( V_336 ) ) {
V_106 = F_202 ( V_336 ) ;
if ( V_106 == - V_337 )
return V_106 ;
} else {
V_106 = F_203 ( V_336 ) ;
if ( V_106 ) {
F_204 ( V_336 ) ;
return V_106 ;
}
V_12 -> V_335 = V_336 ;
V_12 -> V_338 = 1 ;
}
}
if ( F_199 ( V_339 ) && ! V_12 -> V_336 ) {
struct V_336 * V_336 = F_205 ( V_12 -> V_15 . V_80 , L_43 ) ;
if ( F_201 ( V_336 ) ) {
V_106 = F_202 ( V_336 ) ;
if ( V_106 == - V_337 )
goto V_340;
} else {
V_106 = F_206 ( V_336 ) ;
if ( V_106 ) {
F_207 ( V_336 ) ;
goto V_340;
}
V_106 = F_208 ( V_336 ) ;
if ( V_106 ) {
F_209 ( V_336 ) ;
F_207 ( V_336 ) ;
goto V_340;
}
V_12 -> V_336 = V_336 ;
V_12 -> V_338 = 1 ;
}
}
F_59 ( V_12 -> V_15 . V_80 , L_44 , V_12 -> V_17 ) ;
if ( V_341 < 0 || V_341 > 1 ) {
if ( V_12 -> V_342 )
F_25 ( V_123 , & V_12 -> V_95 ) ;
else
F_26 ( V_123 , & V_12 -> V_95 ) ;
} else {
if ( V_341 )
F_26 ( V_123 , & V_12 -> V_95 ) ;
else
F_25 ( V_123 , & V_12 -> V_95 ) ;
}
F_26 ( V_343 , & V_12 -> V_95 ) ;
F_26 ( V_126 , & V_12 -> V_95 ) ;
V_106 = F_210 ( V_12 ) ;
if ( V_106 != 0 ) {
F_16 ( V_12 -> V_15 . V_80 , L_45 ) ;
goto V_344;
}
V_106 = F_52 ( & V_12 -> V_15 ) ;
if ( V_106 < 0 )
goto V_345;
V_286 = F_211 ( NULL , & V_12 -> V_15 , 0 ) ;
if ( V_286 == NULL ) {
F_71 ( V_12 -> V_15 . V_80 , L_46 ) ;
V_106 = - V_45 ;
goto V_346;
}
F_53 ( & V_322 ) ;
V_12 -> V_15 . V_49 = V_286 ;
F_57 ( & V_322 ) ;
switch ( V_12 -> V_60 ) {
case V_68 :
V_286 -> V_60 = V_167 ;
break;
case V_66 :
V_286 -> V_60 = V_168 ;
break;
case V_64 :
V_286 -> V_60 = V_347 ;
break;
case V_62 :
case V_61 :
V_286 -> V_60 = V_155 ;
break;
default:
V_106 = - V_108 ;
goto V_348;
}
F_212 ( & V_286 -> V_50 , 1 ) ;
F_26 ( V_291 , & V_12 -> V_95 ) ;
if ( V_12 -> V_20 -> V_257 ) {
V_106 = V_12 -> V_20 -> V_257 ( V_12 ) ;
if ( V_106 < 0 ) {
F_71 ( V_12 -> V_15 . V_80 , L_47 ,
V_106 ) ;
goto V_349;
}
}
V_12 -> V_97 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_80 )
&& F_15 ( & V_12 -> V_15 . V_49 -> V_50 ) )
F_16 ( V_12 -> V_15 . V_80 , L_48 ) ;
F_178 ( & V_12 -> V_236 ) ;
F_178 ( & V_12 -> V_238 ) ;
if ( F_177 ( V_12 ) && V_329 ) {
V_106 = F_195 ( V_12 , V_329 , V_330 ) ;
if ( V_106 )
goto V_350;
}
V_12 -> V_281 = V_301 ;
V_106 = V_12 -> V_20 -> V_351 ( V_12 ) ;
if ( V_106 < 0 ) {
F_71 ( V_12 -> V_15 . V_80 , L_49 , V_106 ) ;
goto V_352;
}
V_106 = F_63 ( V_12 ) ;
if ( V_106 != 0 )
goto V_353;
V_106 = F_213 ( & V_286 -> V_50 . V_354 , & V_355 ) ;
if ( V_106 < 0 ) {
F_55 ( V_140 L_50 ,
V_106 ) ;
goto V_356;
}
if ( V_12 -> V_98 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
return V_106 ;
V_356:
F_25 ( V_291 , & V_12 -> V_95 ) ;
if ( F_214 ( V_12 -> V_281 ) )
V_12 -> V_281 = V_292 ;
F_7 ( & V_37 ) ;
V_12 -> V_156 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_215 ( & V_12 -> V_306 ) ;
#endif
F_53 ( & V_137 ) ;
F_216 ( & V_286 ) ;
F_57 ( & V_137 ) ;
V_353:
V_12 -> V_97 = 0 ;
F_25 ( V_316 , & V_12 -> V_95 ) ;
F_217 ( & V_12 -> V_102 ) ;
V_12 -> V_20 -> V_357 ( V_12 ) ;
V_12 -> V_281 = V_358 ;
F_25 ( V_316 , & V_12 -> V_95 ) ;
F_217 ( & V_12 -> V_102 ) ;
V_352:
if ( F_177 ( V_12 ) && V_12 -> V_311 > 0 )
F_218 ( V_329 , V_12 ) ;
V_350:
V_349:
V_348:
F_197 ( V_12 ) ;
V_346:
F_60 ( & V_12 -> V_15 ) ;
V_345:
F_219 ( V_12 ) ;
V_344:
if ( F_199 ( V_339 ) && V_12 -> V_338 && V_12 -> V_336 ) {
F_220 ( V_12 -> V_336 ) ;
F_209 ( V_12 -> V_336 ) ;
F_207 ( V_12 -> V_336 ) ;
V_12 -> V_336 = NULL ;
}
V_340:
if ( V_12 -> V_338 && V_12 -> V_335 ) {
F_221 ( V_12 -> V_335 ) ;
F_204 ( V_12 -> V_335 ) ;
V_12 -> V_335 = NULL ;
}
return V_106 ;
}
void F_222 ( struct V_11 * V_12 )
{
struct V_1 * V_286 = V_12 -> V_15 . V_49 ;
F_59 ( V_12 -> V_15 . V_80 , L_51 , V_12 -> V_281 ) ;
F_126 ( V_286 ) ;
F_223 ( & V_286 -> V_50 . V_354 , & V_355 ) ;
F_25 ( V_291 , & V_12 -> V_95 ) ;
if ( F_214 ( V_12 -> V_281 ) )
V_12 -> V_281 = V_292 ;
F_16 ( V_12 -> V_15 . V_80 , L_52 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_156 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_215 ( & V_12 -> V_306 ) ;
#endif
F_53 ( & V_137 ) ;
F_216 ( & V_286 ) ;
F_57 ( & V_137 ) ;
V_12 -> V_97 = 0 ;
F_25 ( V_316 , & V_12 -> V_95 ) ;
F_217 ( & V_12 -> V_102 ) ;
V_12 -> V_20 -> V_357 ( V_12 ) ;
V_12 -> V_281 = V_358 ;
F_25 ( V_316 , & V_12 -> V_95 ) ;
F_217 ( & V_12 -> V_102 ) ;
if ( F_177 ( V_12 ) ) {
if ( V_12 -> V_311 > 0 )
F_218 ( V_12 -> V_311 , V_12 ) ;
}
F_60 ( & V_12 -> V_15 ) ;
F_219 ( V_12 ) ;
if ( F_199 ( V_339 ) && V_12 -> V_338 && V_12 -> V_336 ) {
F_220 ( V_12 -> V_336 ) ;
F_209 ( V_12 -> V_336 ) ;
F_207 ( V_12 -> V_336 ) ;
V_12 -> V_336 = NULL ;
}
if ( V_12 -> V_338 && V_12 -> V_335 ) {
F_221 ( V_12 -> V_335 ) ;
F_204 ( V_12 -> V_335 ) ;
V_12 -> V_335 = NULL ;
}
F_197 ( V_12 ) ;
}
void
F_224 ( struct V_359 * V_50 )
{
struct V_11 * V_12 = F_225 ( V_50 ) ;
if ( V_12 -> V_20 -> V_360 )
V_12 -> V_20 -> V_360 ( V_12 ) ;
}
int F_226 ( const struct V_361 * V_362 )
{
if ( V_363 )
return - V_181 ;
V_363 = V_362 ;
F_227 () ;
return 0 ;
}
void F_228 ( void )
{
if ( V_363 == NULL ) {
F_55 ( V_140 L_53 ) ;
return;
}
V_363 = NULL ;
F_227 () ;
}
