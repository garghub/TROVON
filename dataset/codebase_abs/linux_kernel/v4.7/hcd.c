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
case V_69 :
V_36 = V_70 ;
break;
default:
goto error;
}
V_6 = 18 ;
if ( V_12 -> V_71 )
V_33 = 1 ;
break;
case V_72 << 8 :
switch ( V_12 -> V_60 ) {
case V_61 :
case V_63 :
V_36 = V_73 ;
V_6 = sizeof V_73 ;
break;
case V_65 :
case V_67 :
V_36 = V_74 ;
V_6 = sizeof V_74 ;
break;
case V_69 :
V_36 = V_75 ;
V_6 = sizeof V_75 ;
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
case V_76 << 8 :
goto V_77;
default:
goto error;
}
break;
case V_47 | V_78 :
V_35 [ 0 ] = 0 ;
V_6 = 1 ;
case V_53 | V_79 :
break;
case V_53 | V_80 :
F_16 ( V_12 -> V_15 . V_81 , L_2 ,
V_26 ) ;
break;
case V_82 | V_48 :
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_6 = 2 ;
case V_83 | V_54 :
case V_83 | V_55 :
F_16 ( V_12 -> V_15 . V_81 , L_3 ) ;
break;
default:
V_77:
switch ( V_25 ) {
case V_84 :
V_6 = 4 ;
break;
case V_85 :
if ( V_26 == V_86 )
V_6 = 4 ;
else
V_6 = 8 ;
break;
case V_87 :
V_6 = sizeof ( struct V_43 ) ;
break;
case V_47 | V_58 :
break;
}
V_31 = V_12 -> V_20 -> V_88 ( V_12 ,
V_25 , V_26 , V_27 ,
V_35 , V_28 ) ;
if ( V_25 == V_87 )
F_17 ( V_12 -> V_15 . V_49 ,
(struct V_43 * ) V_35 ) ;
break;
error:
V_31 = - V_89 ;
}
if ( V_31 < 0 ) {
V_6 = 0 ;
if ( V_31 != - V_89 ) {
F_16 ( V_12 -> V_15 . V_81 ,
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
V_6 > F_18 ( struct V_90 ,
V_91 ) )
( (struct V_90 * ) V_29 ) -> V_91
|= V_92 ;
if ( V_33 &&
V_6 > F_18 ( struct V_93 ,
V_94 ) )
( (struct V_93 * ) V_29 ) ->
V_94 = V_95 ;
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
int V_96 ;
unsigned long V_97 ;
char V_98 [ 6 ] ;
if ( F_23 ( ! V_12 -> V_99 ) )
return;
if ( ! V_12 -> V_100 && ! V_12 -> V_101 )
return;
V_96 = V_12 -> V_20 -> V_102 ( V_12 , V_98 ) ;
if ( V_96 > 0 ) {
F_24 ( & V_37 , V_97 ) ;
V_22 = V_12 -> V_101 ;
if ( V_22 ) {
F_25 ( V_103 , & V_12 -> V_97 ) ;
V_12 -> V_101 = NULL ;
V_22 -> V_46 = V_96 ;
memcpy ( V_22 -> V_30 , V_98 , V_96 ) ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , 0 ) ;
} else {
V_96 = 0 ;
F_26 ( V_103 , & V_12 -> V_97 ) ;
}
F_27 ( & V_37 , V_97 ) ;
}
if ( V_12 -> V_100 ? F_28 ( V_12 ) :
( V_96 == 0 && V_12 -> V_101 != NULL ) )
F_29 ( & V_12 -> V_104 , ( V_105 / ( V_106 / 4 ) + 1 ) * ( V_106 / 4 ) ) ;
}
static void F_30 ( unsigned long V_107 )
{
F_22 ( (struct V_11 * ) V_107 ) ;
}
static int F_31 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_108 ;
unsigned long V_97 ;
unsigned V_6 = 1 + ( V_22 -> V_50 -> V_109 / 8 ) ;
F_24 ( & V_37 , V_97 ) ;
if ( V_12 -> V_101 || V_22 -> V_42 < V_6 ) {
F_16 ( V_12 -> V_15 . V_81 , L_6 ) ;
V_108 = - V_110 ;
goto V_111;
}
V_108 = F_8 ( V_12 , V_22 ) ;
if ( V_108 )
goto V_111;
V_12 -> V_101 = V_22 ;
V_22 -> V_38 = V_12 ;
if ( ! V_12 -> V_100 )
F_29 ( & V_12 -> V_104 , ( V_105 / ( V_106 / 4 ) + 1 ) * ( V_106 / 4 ) ) ;
else if ( F_32 ( V_12 ) )
F_29 ( & V_12 -> V_104 , V_105 ) ;
V_108 = 0 ;
V_111:
F_27 ( & V_37 , V_97 ) ;
return V_108 ;
}
static int F_33 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_34 ( & V_22 -> V_112 -> V_113 ) )
return F_31 ( V_12 , V_22 ) ;
if ( F_35 ( & V_22 -> V_112 -> V_113 ) )
return F_5 ( V_12 , V_22 ) ;
return - V_110 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
unsigned long V_97 ;
int V_114 ;
F_24 ( & V_37 , V_97 ) ;
V_114 = F_37 ( V_12 , V_22 , V_31 ) ;
if ( V_114 )
goto V_111;
if ( F_38 ( & V_22 -> V_112 -> V_113 ) == 0 ) {
;
} else {
if ( ! V_12 -> V_100 )
F_39 ( & V_12 -> V_104 ) ;
if ( V_22 == V_12 -> V_101 ) {
V_12 -> V_101 = NULL ;
F_20 ( V_12 , V_22 ) ;
F_21 ( V_12 , V_22 , V_31 ) ;
}
}
V_111:
F_27 ( & V_37 , V_97 ) ;
return V_114 ;
}
static T_3 F_40 ( struct V_115 * V_50 ,
struct V_116 * V_117 , char * V_5 )
{
struct V_1 * V_118 = F_41 ( V_50 ) ;
struct V_119 * V_119 = V_118 -> V_120 ;
struct V_11 * V_12 ;
V_12 = F_42 ( V_119 ) ;
return snprintf ( V_5 , V_121 , L_7 , ! ! F_43 ( V_12 ) ) ;
}
static T_3 F_44 ( struct V_115 * V_50 ,
struct V_116 * V_117 ,
const char * V_5 , T_4 V_122 )
{
T_3 V_123 ;
unsigned V_124 ;
struct V_1 * V_118 = F_41 ( V_50 ) ;
struct V_119 * V_119 = V_118 -> V_120 ;
struct V_11 * V_12 ;
V_12 = F_42 ( V_119 ) ;
V_123 = sscanf ( V_5 , L_7 , & V_124 ) ;
if ( V_123 == 1 ) {
if ( V_124 )
F_26 ( V_125 , & V_12 -> V_97 ) ;
else
F_25 ( V_125 , & V_12 -> V_97 ) ;
V_123 = V_122 ;
} else {
V_123 = - V_110 ;
}
return V_123 ;
}
static T_3 F_45 ( struct V_115 * V_50 ,
struct V_116 * V_117 , char * V_5 )
{
struct V_1 * V_126 = F_41 ( V_50 ) ;
struct V_11 * V_12 = F_42 ( V_126 -> V_120 ) ;
return sprintf ( V_5 , L_7 , ! ! F_46 ( V_12 ) ) ;
}
static T_3 F_47 ( struct V_115 * V_50 ,
struct V_116 * V_117 , const char * V_5 , T_4 V_127 )
{
struct V_1 * V_126 = F_41 ( V_50 ) ;
struct V_11 * V_12 = F_42 ( V_126 -> V_120 ) ;
int V_114 = V_127 ;
bool V_124 ;
if ( F_48 ( V_5 , & V_124 ) != 0 )
return - V_110 ;
if ( V_124 )
F_26 ( V_128 , & V_12 -> V_97 ) ;
else
F_25 ( V_128 , & V_12 -> V_97 ) ;
return V_114 ;
}
static void F_49 ( struct V_119 * V_120 )
{
memset ( & V_120 -> V_129 , 0 , sizeof( struct V_130 ) ) ;
V_120 -> V_131 = 1 ;
V_120 -> V_49 = NULL ;
V_120 -> V_132 = - 1 ;
V_120 -> V_133 = 0 ;
V_120 -> V_134 = 0 ;
V_120 -> V_135 = 0 ;
F_50 ( & V_120 -> V_136 ) ;
}
static int F_51 ( struct V_119 * V_120 )
{
int V_123 = - V_137 ;
int V_132 ;
F_52 ( & V_138 ) ;
V_132 = F_53 ( & V_139 , V_120 , 1 , V_140 , V_44 ) ;
if ( V_132 < 0 ) {
F_54 ( L_8 , V_141 ) ;
goto V_142;
}
V_120 -> V_132 = V_132 ;
F_55 ( & V_138 ) ;
F_56 ( V_120 ) ;
F_57 ( V_120 -> V_81 , L_9
L_10 , V_120 -> V_132 ) ;
return 0 ;
V_142:
F_55 ( & V_138 ) ;
return V_123 ;
}
static void F_58 ( struct V_119 * V_120 )
{
F_57 ( V_120 -> V_81 , L_11 , V_120 -> V_132 ) ;
F_52 ( & V_138 ) ;
F_59 ( & V_139 , V_120 -> V_132 ) ;
F_55 ( & V_138 ) ;
F_60 ( V_120 ) ;
}
static int F_61 ( struct V_11 * V_12 )
{
struct V_115 * V_143 = V_12 -> V_15 . V_81 ;
struct V_1 * V_126 = V_12 -> V_15 . V_49 ;
const int V_144 = 1 ;
int V_108 ;
V_126 -> V_144 = V_144 ;
V_126 -> V_120 -> V_131 = V_144 + 1 ;
memset ( & V_126 -> V_120 -> V_129 . V_145 , 0 ,
sizeof V_126 -> V_120 -> V_129 . V_145 ) ;
F_26 ( V_144 , V_126 -> V_120 -> V_129 . V_145 ) ;
F_62 ( V_126 , V_146 ) ;
F_52 ( & V_138 ) ;
V_126 -> V_147 . V_113 . V_148 = F_63 ( 64 ) ;
V_108 = F_64 ( V_126 , V_149 ) ;
if ( V_108 != sizeof V_126 -> V_150 ) {
F_55 ( & V_138 ) ;
F_16 ( V_143 , L_12 ,
F_65 ( & V_126 -> V_50 ) , V_108 ) ;
return ( V_108 < 0 ) ? V_108 : - V_151 ;
}
if ( F_10 ( V_126 -> V_150 . V_152 ) >= 0x0201 ) {
V_108 = F_66 ( V_126 ) ;
if ( ! V_108 ) {
V_126 -> V_153 = F_67 ( V_126 ) ;
} else if ( V_126 -> V_60 >= V_154 ) {
F_55 ( & V_138 ) ;
F_16 ( V_143 , L_13 ,
F_65 ( & V_126 -> V_50 ) , V_108 ) ;
return V_108 ;
}
}
V_108 = F_68 ( V_126 ) ;
if ( V_108 ) {
F_69 ( V_143 , L_14 ,
F_65 ( & V_126 -> V_50 ) , V_108 ) ;
} else {
F_7 ( & V_37 ) ;
V_12 -> V_155 = 1 ;
F_9 ( & V_37 ) ;
if ( F_70 ( V_12 ) )
F_71 ( V_12 ) ;
V_126 -> V_50 . V_156 = V_143 -> V_156 ;
}
F_55 ( & V_138 ) ;
return V_108 ;
}
void F_72 ( struct V_119 * V_120 , int V_157 )
{
unsigned V_158 = 1 << V_157 ;
if ( ! ( V_120 -> V_159 & V_158 ) ) {
V_120 -> V_159 |= V_158 ;
F_73 ( & V_120 -> V_49 -> V_50 ) ;
}
}
void F_74 ( struct V_119 * V_120 , int V_157 )
{
unsigned V_158 = 1 << V_157 ;
if ( V_120 -> V_159 & V_158 ) {
V_120 -> V_159 &= ~ V_158 ;
F_75 ( & V_120 -> V_49 -> V_50 ) ;
}
}
long F_76 ( int V_60 , int V_160 , int V_161 , int V_162 )
{
unsigned long V_163 ;
switch ( V_60 ) {
case V_164 :
if ( V_160 ) {
V_163 = ( 67667L * ( 31L + 10L * F_77 ( V_162 ) ) ) / 1000L ;
return 64060L + ( 2 * V_165 ) + V_166 + V_163 ;
} else {
V_163 = ( 66700L * ( 31L + 10L * F_77 ( V_162 ) ) ) / 1000L ;
return 64107L + ( 2 * V_165 ) + V_166 + V_163 ;
}
case V_167 :
if ( V_161 ) {
V_163 = ( 8354L * ( 31L + 10L * F_77 ( V_162 ) ) ) / 1000L ;
return ( ( V_160 ) ? 7268L : 6265L ) + V_166 + V_163 ;
} else {
V_163 = ( 8354L * ( 31L + 10L * F_77 ( V_162 ) ) ) / 1000L ;
return 9107L + V_166 + V_163 ;
}
case V_168 :
if ( V_161 )
V_163 = F_78 ( V_162 ) ;
else
V_163 = F_79 ( V_162 ) ;
return V_163 ;
default:
F_80 ( L_15 , V_141 ) ;
return - 1 ;
}
}
int F_8 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
int V_114 = 0 ;
F_81 ( & V_169 ) ;
if ( F_23 ( F_82 ( & V_22 -> V_170 ) ) ) {
V_114 = - V_171 ;
goto V_111;
}
if ( F_23 ( ! V_22 -> V_112 -> V_172 ) ) {
V_114 = - V_173 ;
goto V_111;
}
if ( F_23 ( ! V_22 -> V_50 -> V_174 ) ) {
V_114 = - V_175 ;
goto V_111;
}
if ( F_83 ( V_12 ) ) {
V_22 -> V_176 = 0 ;
F_84 ( & V_22 -> V_177 , & V_22 -> V_112 -> V_177 ) ;
} else {
V_114 = - V_178 ;
goto V_111;
}
V_111:
F_85 ( & V_169 ) ;
return V_114 ;
}
int F_37 ( struct V_11 * V_12 , struct V_22 * V_22 ,
int V_31 )
{
struct V_179 * V_163 ;
F_86 (tmp, &urb->ep->urb_list) {
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
F_81 ( & V_169 ) ;
F_87 ( & V_22 -> V_177 ) ;
F_85 ( & V_169 ) ;
}
static int F_88 ( struct V_119 * V_120 ,
T_5 V_182 , T_6 * V_183 ,
void * * V_184 , T_4 V_122 ,
enum V_185 V_186 )
{
unsigned char * V_187 ;
if ( * V_184 == NULL ) {
F_89 ( 1 ) ;
return - V_188 ;
}
V_187 = F_90 ( V_120 , V_122 + sizeof( V_187 ) ,
V_182 , V_183 ) ;
if ( ! V_187 )
return - V_45 ;
F_91 ( ( unsigned long ) * V_184 ,
( unsigned long * ) ( V_187 + V_122 ) ) ;
if ( V_186 == V_189 )
memcpy ( V_187 , * V_184 , V_122 ) ;
* V_184 = V_187 ;
return 0 ;
}
static void F_92 ( struct V_119 * V_120 , T_6 * V_183 ,
void * * V_184 , T_4 V_122 ,
enum V_185 V_186 )
{
unsigned char * V_187 = * V_184 ;
V_187 = ( void * ) F_93 ( ( unsigned long * ) ( V_187 + V_122 ) ) ;
if ( V_186 == V_190 )
memcpy ( V_187 , * V_184 , V_122 ) ;
F_94 ( V_120 , V_122 + sizeof( V_187 ) , * V_184 , * V_183 ) ;
* V_184 = V_187 ;
* V_183 = 0 ;
}
void F_95 ( struct V_11 * V_12 , struct V_22 * V_22 )
{
if ( F_96 ( V_191 ) &&
( V_22 -> V_192 & V_193 ) )
F_97 ( V_12 -> V_15 . V_81 ,
V_22 -> V_194 ,
sizeof( struct V_23 ) ,
V_189 ) ;
else if ( V_22 -> V_192 & V_195 )
F_92 ( V_22 -> V_50 -> V_120 ,
& V_22 -> V_194 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_189 ) ;
V_22 -> V_192 &= ~ ( V_193 | V_195 ) ;
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
enum V_185 V_186 ;
F_95 ( V_12 , V_22 ) ;
V_186 = F_100 ( V_22 ) ? V_190 : V_189 ;
if ( F_96 ( V_191 ) &&
( V_22 -> V_192 & V_196 ) )
F_101 ( V_12 -> V_15 . V_81 ,
V_22 -> V_197 ,
V_22 -> V_198 ,
V_186 ) ;
else if ( F_96 ( V_191 ) &&
( V_22 -> V_192 & V_199 ) )
F_102 ( V_12 -> V_15 . V_81 ,
V_22 -> V_200 ,
V_22 -> V_42 ,
V_186 ) ;
else if ( F_96 ( V_191 ) &&
( V_22 -> V_192 & V_201 ) )
F_97 ( V_12 -> V_15 . V_81 ,
V_22 -> V_200 ,
V_22 -> V_42 ,
V_186 ) ;
else if ( V_22 -> V_192 & V_202 )
F_92 ( V_22 -> V_50 -> V_120 ,
& V_22 -> V_200 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_186 ) ;
V_22 -> V_192 &= ~ ( V_196 | V_199 |
V_201 | V_202 ) ;
}
static int F_103 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_182 )
{
if ( V_12 -> V_20 -> F_103 )
return V_12 -> V_20 -> F_103 ( V_12 , V_22 , V_182 ) ;
else
return F_104 ( V_12 , V_22 , V_182 ) ;
}
int F_104 ( struct V_11 * V_12 , struct V_22 * V_22 ,
T_5 V_182 )
{
enum V_185 V_186 ;
int V_203 = 0 ;
if ( F_35 ( & V_22 -> V_112 -> V_113 ) ) {
if ( V_12 -> V_15 . V_204 )
return V_203 ;
if ( F_96 ( V_191 ) && V_12 -> V_15 . V_205 ) {
V_22 -> V_194 = F_105 (
V_12 -> V_15 . V_81 ,
V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_189 ) ;
if ( F_106 ( V_12 -> V_15 . V_81 ,
V_22 -> V_194 ) )
return - V_206 ;
V_22 -> V_192 |= V_193 ;
} else if ( V_12 -> V_20 -> V_97 & V_207 ) {
V_203 = F_88 (
V_22 -> V_50 -> V_120 , V_182 ,
& V_22 -> V_194 ,
( void * * ) & V_22 -> V_39 ,
sizeof( struct V_23 ) ,
V_189 ) ;
if ( V_203 )
return V_203 ;
V_22 -> V_192 |= V_195 ;
}
}
V_186 = F_100 ( V_22 ) ? V_190 : V_189 ;
if ( V_22 -> V_42 != 0
&& ! ( V_22 -> V_192 & V_208 ) ) {
if ( F_96 ( V_191 ) && V_12 -> V_15 . V_205 ) {
if ( V_22 -> V_198 ) {
int V_7 ;
if ( F_107 ( & V_22 -> V_112 -> V_113 ) ) {
F_108 ( 1 ) ;
return - V_110 ;
}
V_7 = F_109 (
V_12 -> V_15 . V_81 ,
V_22 -> V_197 ,
V_22 -> V_198 ,
V_186 ) ;
if ( V_7 <= 0 )
V_203 = - V_206 ;
else
V_22 -> V_192 |= V_196 ;
V_22 -> V_209 = V_7 ;
if ( V_7 != V_22 -> V_198 )
V_22 -> V_192 |=
V_210 ;
} else if ( V_22 -> V_197 ) {
struct V_211 * V_197 = V_22 -> V_197 ;
V_22 -> V_200 = F_110 (
V_12 -> V_15 . V_81 ,
F_111 ( V_197 ) ,
V_197 -> V_212 ,
V_22 -> V_42 ,
V_186 ) ;
if ( F_106 ( V_12 -> V_15 . V_81 ,
V_22 -> V_200 ) )
V_203 = - V_206 ;
else
V_22 -> V_192 |= V_199 ;
} else if ( F_112 ( V_22 -> V_30 ) ) {
F_113 ( 1 , L_16 ) ;
V_203 = - V_206 ;
} else {
V_22 -> V_200 = F_105 (
V_12 -> V_15 . V_81 ,
V_22 -> V_30 ,
V_22 -> V_42 ,
V_186 ) ;
if ( F_106 ( V_12 -> V_15 . V_81 ,
V_22 -> V_200 ) )
V_203 = - V_206 ;
else
V_22 -> V_192 |= V_201 ;
}
} else if ( V_12 -> V_20 -> V_97 & V_207 ) {
V_203 = F_88 (
V_22 -> V_50 -> V_120 , V_182 ,
& V_22 -> V_200 ,
& V_22 -> V_30 ,
V_22 -> V_42 ,
V_186 ) ;
if ( V_203 == 0 )
V_22 -> V_192 |= V_202 ;
}
if ( V_203 && ( V_22 -> V_192 & ( V_193 |
V_195 ) ) )
F_99 ( V_12 , V_22 ) ;
}
return V_203 ;
}
int F_114 ( struct V_22 * V_22 , T_5 V_182 )
{
int V_31 ;
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_120 ) ;
F_115 ( V_22 ) ;
F_116 ( & V_22 -> V_213 ) ;
F_116 ( & V_22 -> V_50 -> V_214 ) ;
F_117 ( & V_12 -> V_15 , V_22 ) ;
if ( F_1 ( V_22 -> V_50 ) ) {
V_31 = F_33 ( V_12 , V_22 ) ;
} else {
V_31 = F_103 ( V_12 , V_22 , V_182 ) ;
if ( F_118 ( V_31 == 0 ) ) {
V_31 = V_12 -> V_20 -> V_215 ( V_12 , V_22 , V_182 ) ;
if ( F_23 ( V_31 ) )
F_98 ( V_12 , V_22 ) ;
}
}
if ( F_23 ( V_31 ) ) {
F_119 ( & V_12 -> V_15 , V_22 , V_31 ) ;
V_22 -> V_38 = NULL ;
F_120 ( & V_22 -> V_177 ) ;
F_121 ( & V_22 -> V_213 ) ;
F_121 ( & V_22 -> V_50 -> V_214 ) ;
if ( F_82 ( & V_22 -> V_170 ) )
F_122 ( & V_216 ) ;
F_123 ( V_22 ) ;
}
return V_31 ;
}
static int F_124 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
int V_217 ;
if ( F_1 ( V_22 -> V_50 ) )
V_217 = F_36 ( V_12 , V_22 , V_31 ) ;
else {
V_217 = V_12 -> V_20 -> V_218 ( V_12 , V_22 , V_31 ) ;
}
return V_217 ;
}
int F_125 ( struct V_22 * V_22 , int V_31 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_22 -> V_50 ;
int V_108 = - V_180 ;
unsigned long V_97 ;
F_24 ( & V_219 , V_97 ) ;
if ( F_82 ( & V_22 -> V_213 ) > 0 ) {
V_108 = 0 ;
F_126 ( V_2 ) ;
}
F_27 ( & V_219 , V_97 ) ;
if ( V_108 == 0 ) {
V_12 = F_42 ( V_22 -> V_50 -> V_120 ) ;
V_108 = F_124 ( V_12 , V_22 , V_31 ) ;
if ( V_108 == 0 )
V_108 = - V_220 ;
else if ( V_108 != - V_180 && V_108 != - V_181 )
F_16 ( & V_2 -> V_50 , L_17 ,
V_22 , V_108 ) ;
F_127 ( V_2 ) ;
}
return V_108 ;
}
static void F_128 ( struct V_22 * V_22 )
{
struct V_11 * V_12 = F_42 ( V_22 -> V_50 -> V_120 ) ;
struct V_221 * V_222 = V_22 -> V_222 ;
int V_31 = V_22 -> V_176 ;
unsigned long V_97 ;
V_22 -> V_38 = NULL ;
if ( F_23 ( ( V_22 -> V_192 & V_223 ) &&
V_22 -> V_46 < V_22 -> V_42 &&
! V_31 ) )
V_31 = - V_224 ;
F_98 ( V_12 , V_22 ) ;
F_129 ( & V_12 -> V_15 , V_22 , V_31 ) ;
F_130 ( V_222 ) ;
F_131 ( V_22 ) ;
if ( F_118 ( V_31 == 0 ) )
F_132 ( V_225 ) ;
V_22 -> V_31 = V_31 ;
F_133 ( V_97 ) ;
V_22 -> V_226 ( V_22 ) ;
F_134 ( V_97 ) ;
F_135 ( V_222 ) ;
F_121 ( & V_22 -> V_213 ) ;
if ( F_23 ( F_82 ( & V_22 -> V_170 ) ) )
F_122 ( & V_216 ) ;
F_123 ( V_22 ) ;
}
static void F_136 ( unsigned long V_227 )
{
struct V_228 * V_229 = (struct V_228 * ) V_227 ;
struct V_179 V_230 ;
F_7 ( & V_229 -> V_231 ) ;
V_229 -> V_232 = true ;
V_233:
F_137 ( & V_229 -> V_234 , & V_230 ) ;
F_9 ( & V_229 -> V_231 ) ;
while ( ! F_138 ( & V_230 ) ) {
struct V_22 * V_22 ;
V_22 = F_139 ( V_230 . V_235 , struct V_22 , V_177 ) ;
F_87 ( & V_22 -> V_177 ) ;
V_229 -> V_236 = V_22 -> V_112 ;
F_128 ( V_22 ) ;
V_229 -> V_236 = NULL ;
}
F_7 ( & V_229 -> V_231 ) ;
if ( ! F_138 ( & V_229 -> V_234 ) )
goto V_233;
V_229 -> V_232 = false ;
F_9 ( & V_229 -> V_231 ) ;
}
void F_21 ( struct V_11 * V_12 , struct V_22 * V_22 , int V_31 )
{
struct V_228 * V_229 ;
bool V_232 , V_237 ;
if ( F_118 ( ! V_22 -> V_176 ) )
V_22 -> V_176 = V_31 ;
if ( ! F_140 ( V_12 ) && ! F_1 ( V_22 -> V_50 ) ) {
F_128 ( V_22 ) ;
return;
}
if ( F_141 ( V_22 -> V_238 ) || F_142 ( V_22 -> V_238 ) ) {
V_229 = & V_12 -> V_237 ;
V_237 = true ;
} else {
V_229 = & V_12 -> V_239 ;
V_237 = false ;
}
F_81 ( & V_229 -> V_231 ) ;
F_84 ( & V_22 -> V_177 , & V_229 -> V_234 ) ;
V_232 = V_229 -> V_232 ;
F_85 ( & V_229 -> V_231 ) ;
if ( V_232 )
;
else if ( V_237 )
F_143 ( & V_229 -> V_229 ) ;
else
F_144 ( & V_229 -> V_229 ) ;
}
void F_145 ( struct V_1 * V_2 ,
struct V_240 * V_112 )
{
struct V_11 * V_12 ;
struct V_22 * V_22 ;
if ( ! V_112 )
return;
F_6 () ;
V_12 = F_42 ( V_2 -> V_120 ) ;
F_7 ( & V_169 ) ;
V_241:
F_146 (urb, &ep->urb_list, urb_list) {
int V_242 ;
if ( V_22 -> V_176 )
continue;
F_115 ( V_22 ) ;
V_242 = F_100 ( V_22 ) ;
F_85 ( & V_169 ) ;
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
F_81 ( & V_169 ) ;
goto V_241;
}
F_9 ( & V_169 ) ;
while ( ! F_138 ( & V_112 -> V_177 ) ) {
F_7 ( & V_169 ) ;
V_22 = NULL ;
if ( ! F_138 ( & V_112 -> V_177 ) ) {
V_22 = F_139 ( V_112 -> V_177 . V_243 , struct V_22 ,
V_177 ) ;
F_115 ( V_22 ) ;
}
F_9 ( & V_169 ) ;
if ( V_22 ) {
F_147 ( V_22 ) ;
F_123 ( V_22 ) ;
}
}
}
int F_148 ( struct V_1 * V_2 ,
struct V_244 * V_245 ,
struct V_246 * V_247 ,
struct V_246 * V_248 )
{
int V_249 , V_250 , V_251 ;
struct V_246 * V_252 = NULL ;
int V_203 = 0 ;
struct V_11 * V_12 ;
struct V_240 * V_112 ;
V_12 = F_42 ( V_2 -> V_120 ) ;
if ( ! V_12 -> V_20 -> V_253 )
return 0 ;
if ( ! V_245 && ! V_247 ) {
for ( V_250 = 1 ; V_250 < 16 ; ++ V_250 ) {
V_112 = V_2 -> V_254 [ V_250 ] ;
if ( V_112 )
V_12 -> V_20 -> V_255 ( V_12 , V_2 , V_112 ) ;
V_112 = V_2 -> V_256 [ V_250 ] ;
if ( V_112 )
V_12 -> V_20 -> V_255 ( V_12 , V_2 , V_112 ) ;
}
V_12 -> V_20 -> V_253 ( V_12 , V_2 ) ;
return 0 ;
}
if ( V_245 ) {
V_249 = V_245 -> V_113 . V_257 ;
for ( V_250 = 1 ; V_250 < 16 ; ++ V_250 ) {
V_112 = V_2 -> V_254 [ V_250 ] ;
if ( V_112 ) {
V_203 = V_12 -> V_20 -> V_255 ( V_12 , V_2 , V_112 ) ;
if ( V_203 < 0 )
goto V_258;
}
V_112 = V_2 -> V_256 [ V_250 ] ;
if ( V_112 ) {
V_203 = V_12 -> V_20 -> V_255 ( V_12 , V_2 , V_112 ) ;
if ( V_203 < 0 )
goto V_258;
}
}
for ( V_250 = 0 ; V_250 < V_249 ; ++ V_250 ) {
struct V_246 * V_259 ;
int V_260 ;
V_259 = & V_245 -> V_261 [ V_250 ] -> V_262 [ 0 ] ;
V_260 = V_259 -> V_113 . V_263 ;
V_252 = F_149 ( V_245 , V_260 , 0 ) ;
if ( ! V_252 )
V_252 = V_259 ;
for ( V_251 = 0 ; V_251 < V_252 -> V_113 . V_264 ; V_251 ++ ) {
V_203 = V_12 -> V_20 -> V_265 ( V_12 , V_2 , & V_252 -> V_266 [ V_251 ] ) ;
if ( V_203 < 0 )
goto V_258;
}
}
}
if ( V_247 && V_248 ) {
struct V_267 * V_268 = F_150 ( V_2 ,
V_247 -> V_113 . V_263 ) ;
if ( ! V_268 )
return - V_110 ;
if ( V_268 -> V_269 ) {
V_247 = F_151 ( V_268 , 0 ) ;
if ( ! V_247 )
V_247 = & V_268 -> V_262 [ 0 ] ;
}
for ( V_250 = 0 ; V_250 < V_247 -> V_113 . V_264 ; V_250 ++ ) {
V_203 = V_12 -> V_20 -> V_255 ( V_12 , V_2 ,
& V_247 -> V_266 [ V_250 ] ) ;
if ( V_203 < 0 )
goto V_258;
}
for ( V_250 = 0 ; V_250 < V_248 -> V_113 . V_264 ; V_250 ++ ) {
V_203 = V_12 -> V_20 -> V_265 ( V_12 , V_2 ,
& V_248 -> V_266 [ V_250 ] ) ;
if ( V_203 < 0 )
goto V_258;
}
}
V_203 = V_12 -> V_20 -> V_253 ( V_12 , V_2 ) ;
V_258:
if ( V_203 < 0 )
V_12 -> V_20 -> V_270 ( V_12 , V_2 ) ;
return V_203 ;
}
void F_152 ( struct V_1 * V_2 ,
struct V_240 * V_112 )
{
struct V_11 * V_12 ;
F_6 () ;
V_12 = F_42 ( V_2 -> V_120 ) ;
if ( V_12 -> V_20 -> V_271 )
V_12 -> V_20 -> V_271 ( V_12 , V_112 ) ;
}
void F_153 ( struct V_1 * V_2 ,
struct V_240 * V_112 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_120 ) ;
if ( V_12 -> V_20 -> V_272 )
V_12 -> V_20 -> V_272 ( V_12 , V_112 ) ;
else {
int V_273 = F_38 ( & V_112 -> V_113 ) ;
int V_274 = F_154 ( & V_112 -> V_113 ) ;
int V_275 = F_35 ( & V_112 -> V_113 ) ;
F_155 ( V_2 , V_273 , V_274 , 0 ) ;
if ( V_275 )
F_155 ( V_2 , V_273 , ! V_274 , 0 ) ;
}
}
int F_156 ( struct V_267 * V_276 ,
struct V_240 * * V_277 , unsigned int V_278 ,
unsigned int V_279 , T_5 V_182 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_250 , V_203 ;
V_50 = F_157 ( V_276 ) ;
V_12 = F_42 ( V_50 -> V_120 ) ;
if ( ! V_12 -> V_20 -> V_280 || ! V_12 -> V_20 -> V_281 )
return - V_110 ;
if ( V_50 -> V_60 < V_154 )
return - V_110 ;
if ( V_50 -> V_282 < V_283 )
return - V_284 ;
for ( V_250 = 0 ; V_250 < V_278 ; V_250 ++ ) {
if ( ! F_158 ( & V_277 [ V_250 ] -> V_113 ) )
return - V_110 ;
if ( V_277 [ V_250 ] -> V_285 )
return - V_110 ;
}
V_203 = V_12 -> V_20 -> V_280 ( V_12 , V_50 , V_277 , V_278 ,
V_279 , V_182 ) ;
if ( V_203 < 0 )
return V_203 ;
for ( V_250 = 0 ; V_250 < V_278 ; V_250 ++ )
V_277 [ V_250 ] -> V_285 = V_203 ;
return V_203 ;
}
int F_159 ( struct V_267 * V_276 ,
struct V_240 * * V_277 , unsigned int V_278 ,
T_5 V_182 )
{
struct V_11 * V_12 ;
struct V_1 * V_50 ;
int V_250 , V_203 ;
V_50 = F_157 ( V_276 ) ;
V_12 = F_42 ( V_50 -> V_120 ) ;
if ( V_50 -> V_60 < V_154 )
return - V_110 ;
for ( V_250 = 0 ; V_250 < V_278 ; V_250 ++ )
if ( ! V_277 [ V_250 ] || ! V_277 [ V_250 ] -> V_285 )
return - V_110 ;
V_203 = V_12 -> V_20 -> V_281 ( V_12 , V_50 , V_277 , V_278 , V_182 ) ;
if ( V_203 < 0 )
return V_203 ;
for ( V_250 = 0 ; V_250 < V_278 ; V_250 ++ )
V_277 [ V_250 ] -> V_285 = 0 ;
return V_203 ;
}
void F_160 ( struct V_1 * V_2 )
{
F_7 ( & V_219 ) ;
F_9 ( & V_219 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_42 ( V_2 -> V_120 ) ;
if ( ! F_83 ( V_12 ) )
return - V_178 ;
return V_12 -> V_20 -> V_286 ( V_12 ) ;
}
int F_162 ( struct V_1 * V_287 , T_7 V_288 )
{
struct V_11 * V_12 = F_42 ( V_287 -> V_120 ) ;
int V_31 ;
int V_289 = V_12 -> V_282 ;
F_16 ( & V_287 -> V_50 , L_25 ,
( F_163 ( V_288 ) ? L_26 : L_21 ) ,
V_287 -> V_290 ) ;
if ( F_70 ( V_12 ) ) {
F_16 ( & V_287 -> V_50 , L_27 , L_28 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_291 ) {
V_31 = - V_173 ;
} else {
F_25 ( V_292 , & V_12 -> V_97 ) ;
V_12 -> V_282 = V_293 ;
V_31 = V_12 -> V_20 -> V_291 ( V_12 ) ;
}
if ( V_31 == 0 ) {
F_62 ( V_287 , V_294 ) ;
V_12 -> V_282 = V_295 ;
if ( V_287 -> V_290 ) {
char V_98 [ 6 ] ;
V_31 = V_12 -> V_20 -> V_102 ( V_12 , V_98 ) ;
if ( V_31 != 0 ) {
F_16 ( & V_287 -> V_50 , L_29 ) ;
F_164 ( V_287 , V_296 ) ;
V_31 = - V_181 ;
}
}
} else {
F_7 ( & V_37 ) ;
if ( ! F_70 ( V_12 ) ) {
F_26 ( V_292 , & V_12 -> V_97 ) ;
V_12 -> V_282 = V_289 ;
}
F_9 ( & V_37 ) ;
F_16 ( & V_287 -> V_50 , L_30 ,
L_28 , V_31 ) ;
}
return V_31 ;
}
int F_164 ( struct V_1 * V_287 , T_7 V_288 )
{
struct V_11 * V_12 = F_42 ( V_287 -> V_120 ) ;
int V_31 ;
int V_289 = V_12 -> V_282 ;
F_16 ( & V_287 -> V_50 , L_31 ,
( F_163 ( V_288 ) ? L_26 : L_21 ) ) ;
if ( F_70 ( V_12 ) ) {
F_16 ( & V_287 -> V_50 , L_27 , L_32 ) ;
return 0 ;
}
if ( ! V_12 -> V_20 -> V_297 )
return - V_173 ;
if ( F_83 ( V_12 ) )
return 0 ;
V_12 -> V_282 = V_298 ;
V_31 = V_12 -> V_20 -> V_297 ( V_12 ) ;
F_25 ( V_299 , & V_12 -> V_97 ) ;
if ( V_31 == 0 ) {
struct V_1 * V_2 ;
int V_300 ;
F_7 ( & V_37 ) ;
if ( ! F_70 ( V_12 ) ) {
F_62 ( V_287 , V_287 -> V_301
? V_283
: V_146 ) ;
F_26 ( V_292 , & V_12 -> V_97 ) ;
V_12 -> V_282 = V_302 ;
}
F_9 ( & V_37 ) ;
F_165 (rhdev, port1, udev) {
if ( V_2 -> V_282 != V_303 &&
! V_2 -> V_304 ) {
F_166 ( 10000 , 11000 ) ;
break;
}
}
} else {
V_12 -> V_282 = V_289 ;
F_16 ( & V_287 -> V_50 , L_30 ,
L_32 , V_31 ) ;
if ( V_31 != - V_178 )
F_71 ( V_12 ) ;
}
return V_31 ;
}
static void F_167 ( struct V_305 * V_306 )
{
struct V_11 * V_12 = F_168 ( V_306 , struct V_11 , V_307 ) ;
struct V_1 * V_2 = V_12 -> V_15 . V_49 ;
F_169 ( V_2 ) ;
}
void F_170 ( struct V_11 * V_12 )
{
unsigned long V_97 ;
F_24 ( & V_37 , V_97 ) ;
if ( V_12 -> V_155 ) {
F_26 ( V_299 , & V_12 -> V_97 ) ;
F_171 ( V_308 , & V_12 -> V_307 ) ;
}
F_27 ( & V_37 , V_97 ) ;
}
int F_172 ( struct V_119 * V_120 , unsigned V_309 )
{
struct V_11 * V_12 ;
int V_31 = - V_310 ;
V_12 = F_42 ( V_120 ) ;
if ( V_309 && V_12 -> V_20 -> V_311 )
V_31 = V_12 -> V_20 -> V_311 ( V_12 , V_309 ) ;
if ( V_31 == 0 )
F_29 ( & V_12 -> V_104 , V_105 + F_173 ( 10 ) ) ;
return V_31 ;
}
T_8 F_174 ( int V_312 , void * V_313 )
{
struct V_11 * V_12 = V_313 ;
T_8 V_114 ;
if ( F_23 ( F_70 ( V_12 ) || ! F_175 ( V_12 ) ) )
V_114 = V_314 ;
else if ( V_12 -> V_20 -> V_312 ( V_12 ) == V_314 )
V_114 = V_314 ;
else
V_114 = V_315 ;
return V_114 ;
}
void F_71 ( struct V_11 * V_12 )
{
unsigned long V_97 ;
F_69 ( V_12 -> V_15 . V_81 , L_33 ) ;
F_24 ( & V_37 , V_97 ) ;
F_25 ( V_292 , & V_12 -> V_97 ) ;
F_26 ( V_316 , & V_12 -> V_97 ) ;
if ( V_12 -> V_155 ) {
F_25 ( V_317 , & V_12 -> V_97 ) ;
F_62 ( V_12 -> V_15 . V_49 ,
V_303 ) ;
F_176 ( V_12 -> V_15 . V_49 ) ;
}
if ( F_177 ( V_12 ) && V_12 -> V_318 ) {
V_12 = V_12 -> V_318 ;
if ( V_12 -> V_155 ) {
F_25 ( V_317 , & V_12 -> V_97 ) ;
F_62 ( V_12 -> V_15 . V_49 ,
V_303 ) ;
F_176 ( V_12 -> V_15 . V_49 ) ;
}
}
F_27 ( & V_37 , V_97 ) ;
}
static void F_178 ( struct V_228 * V_229 )
{
F_179 ( & V_229 -> V_231 ) ;
F_120 ( & V_229 -> V_234 ) ;
F_180 ( & V_229 -> V_229 , F_136 , ( unsigned long ) V_229 ) ;
}
struct V_11 * F_181 ( const struct V_319 * V_20 ,
struct V_115 * V_50 , const char * V_16 ,
struct V_11 * V_320 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( sizeof( * V_12 ) + V_20 -> V_321 , V_44 ) ;
if ( ! V_12 ) {
F_16 ( V_50 , L_34 ) ;
return NULL ;
}
if ( V_320 == NULL ) {
V_12 -> V_322 = F_182 ( sizeof( * V_12 -> V_322 ) ,
V_44 ) ;
if ( ! V_12 -> V_322 ) {
F_19 ( V_12 ) ;
F_16 ( V_50 , L_35 ) ;
return NULL ;
}
F_50 ( V_12 -> V_322 ) ;
V_12 -> V_323 = F_182 ( sizeof( * V_12 -> V_323 ) ,
V_44 ) ;
if ( ! V_12 -> V_323 ) {
F_19 ( V_12 ) ;
F_16 ( V_50 , L_36 ) ;
return NULL ;
}
F_50 ( V_12 -> V_323 ) ;
F_183 ( V_50 , V_12 ) ;
} else {
F_52 ( & V_324 ) ;
V_12 -> V_322 = V_320 -> V_322 ;
V_12 -> V_323 = V_320 -> V_323 ;
V_12 -> V_320 = V_320 ;
V_320 -> V_320 = V_320 ;
V_12 -> V_318 = V_320 ;
V_320 -> V_318 = V_12 ;
F_55 ( & V_324 ) ;
}
F_184 ( & V_12 -> V_325 ) ;
F_49 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_81 = V_50 ;
V_12 -> V_15 . V_16 = V_16 ;
V_12 -> V_15 . V_205 = ( V_50 -> V_326 != NULL ) ;
F_185 ( & V_12 -> V_104 ) ;
V_12 -> V_104 . V_327 = F_30 ;
V_12 -> V_104 . V_13 = ( unsigned long ) V_12 ;
#ifdef F_186
F_187 ( & V_12 -> V_307 , F_167 ) ;
#endif
V_12 -> V_20 = V_20 ;
V_12 -> V_60 = V_20 -> V_97 & V_328 ;
V_12 -> V_17 = ( V_20 -> V_17 ) ? V_20 -> V_17 :
L_37 ;
return V_12 ;
}
struct V_11 * F_188 ( const struct V_319 * V_20 ,
struct V_115 * V_50 , const char * V_16 )
{
return F_181 ( V_20 , V_50 , V_16 , NULL ) ;
}
static void F_189 ( struct V_325 * V_325 )
{
struct V_11 * V_12 = F_168 ( V_325 , struct V_11 , V_325 ) ;
F_52 ( & V_324 ) ;
if ( V_12 -> V_318 ) {
struct V_11 * V_329 = V_12 -> V_318 ;
V_329 -> V_318 = NULL ;
V_329 -> V_320 = NULL ;
} else {
F_19 ( V_12 -> V_322 ) ;
F_19 ( V_12 -> V_323 ) ;
}
F_55 ( & V_324 ) ;
F_19 ( V_12 ) ;
}
struct V_11 * F_190 ( struct V_11 * V_12 )
{
if ( V_12 )
F_191 ( & V_12 -> V_325 ) ;
return V_12 ;
}
void F_192 ( struct V_11 * V_12 )
{
if ( V_12 )
F_193 ( & V_12 -> V_325 , F_189 ) ;
}
int F_177 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_320 )
return 1 ;
return V_12 == V_12 -> V_320 ;
}
int F_194 ( struct V_11 * V_12 , int V_300 )
{
if ( ! V_12 -> V_20 -> V_330 )
return V_300 ;
return V_12 -> V_20 -> V_330 ( V_12 , V_300 ) ;
}
static int F_195 ( struct V_11 * V_12 ,
unsigned int V_331 , unsigned long V_332 )
{
int V_108 ;
if ( V_12 -> V_20 -> V_312 ) {
snprintf ( V_12 -> V_333 , sizeof( V_12 -> V_333 ) , L_38 ,
V_12 -> V_20 -> V_21 , V_12 -> V_15 . V_132 ) ;
V_108 = F_196 ( V_331 , & F_174 , V_332 ,
V_12 -> V_333 , V_12 ) ;
if ( V_108 != 0 ) {
F_69 ( V_12 -> V_15 . V_81 ,
L_39 ,
V_331 ) ;
return V_108 ;
}
V_12 -> V_312 = V_331 ;
F_57 ( V_12 -> V_15 . V_81 , L_40 , V_331 ,
( V_12 -> V_20 -> V_97 & V_334 ) ?
L_41 : L_42 ,
( unsigned long long ) V_12 -> V_335 ) ;
} else {
V_12 -> V_312 = 0 ;
if ( V_12 -> V_335 )
F_57 ( V_12 -> V_15 . V_81 , L_43 ,
( V_12 -> V_20 -> V_97 & V_334 ) ?
L_41 : L_42 ,
( unsigned long long ) V_12 -> V_335 ) ;
}
return 0 ;
}
static void F_197 ( struct V_11 * V_12 )
{
struct V_1 * V_287 ;
F_52 ( & V_324 ) ;
V_287 = V_12 -> V_15 . V_49 ;
V_12 -> V_15 . V_49 = NULL ;
F_55 ( & V_324 ) ;
F_127 ( V_287 ) ;
}
int F_198 ( struct V_11 * V_12 ,
unsigned int V_331 , unsigned long V_332 )
{
int V_108 ;
struct V_1 * V_287 ;
if ( F_96 ( V_336 ) && ! V_12 -> V_337 ) {
struct V_337 * V_338 = F_199 ( V_12 -> V_15 . V_81 , 0 ) ;
if ( F_200 ( V_338 ) ) {
V_108 = F_201 ( V_338 ) ;
if ( V_108 == - V_339 )
return V_108 ;
} else {
V_108 = F_202 ( V_338 ) ;
if ( V_108 ) {
F_203 ( V_338 ) ;
return V_108 ;
}
V_12 -> V_337 = V_338 ;
V_12 -> V_340 = 1 ;
}
}
if ( F_96 ( V_341 ) && ! V_12 -> V_338 ) {
struct V_338 * V_338 = F_204 ( V_12 -> V_15 . V_81 , L_44 ) ;
if ( F_200 ( V_338 ) ) {
V_108 = F_201 ( V_338 ) ;
if ( V_108 == - V_339 )
goto V_342;
} else {
V_108 = F_205 ( V_338 ) ;
if ( V_108 ) {
F_206 ( V_338 ) ;
goto V_342;
}
V_108 = F_207 ( V_338 ) ;
if ( V_108 ) {
F_208 ( V_338 ) ;
F_206 ( V_338 ) ;
goto V_342;
}
V_12 -> V_338 = V_338 ;
V_12 -> V_340 = 1 ;
}
}
F_57 ( V_12 -> V_15 . V_81 , L_45 , V_12 -> V_17 ) ;
if ( V_343 < 0 || V_343 > 1 ) {
if ( V_12 -> V_344 )
F_25 ( V_125 , & V_12 -> V_97 ) ;
else
F_26 ( V_125 , & V_12 -> V_97 ) ;
} else {
if ( V_343 )
F_26 ( V_125 , & V_12 -> V_97 ) ;
else
F_25 ( V_125 , & V_12 -> V_97 ) ;
}
F_26 ( V_345 , & V_12 -> V_97 ) ;
F_26 ( V_128 , & V_12 -> V_97 ) ;
V_108 = F_209 ( V_12 ) ;
if ( V_108 != 0 ) {
F_16 ( V_12 -> V_15 . V_81 , L_46 ) ;
goto V_346;
}
V_108 = F_51 ( & V_12 -> V_15 ) ;
if ( V_108 < 0 )
goto V_347;
V_287 = F_210 ( NULL , & V_12 -> V_15 , 0 ) ;
if ( V_287 == NULL ) {
F_69 ( V_12 -> V_15 . V_81 , L_47 ) ;
V_108 = - V_45 ;
goto V_348;
}
F_52 ( & V_324 ) ;
V_12 -> V_15 . V_49 = V_287 ;
F_55 ( & V_324 ) ;
switch ( V_12 -> V_60 ) {
case V_69 :
V_287 -> V_60 = V_167 ;
break;
case V_67 :
V_287 -> V_60 = V_168 ;
break;
case V_65 :
V_287 -> V_60 = V_349 ;
break;
case V_63 :
V_287 -> V_60 = V_154 ;
break;
case V_61 :
V_287 -> V_60 = V_350 ;
break;
default:
V_108 = - V_110 ;
goto V_351;
}
F_211 ( & V_287 -> V_50 , 1 ) ;
F_26 ( V_292 , & V_12 -> V_97 ) ;
if ( V_12 -> V_20 -> V_258 ) {
V_108 = V_12 -> V_20 -> V_258 ( V_12 ) ;
if ( V_108 < 0 ) {
F_69 ( V_12 -> V_15 . V_81 , L_48 ,
V_108 ) ;
goto V_352;
}
}
V_12 -> V_99 = 1 ;
if ( F_15 ( V_12 -> V_15 . V_81 )
&& F_15 ( & V_12 -> V_15 . V_49 -> V_50 ) )
F_16 ( V_12 -> V_15 . V_81 , L_49 ) ;
F_178 ( & V_12 -> V_237 ) ;
F_178 ( & V_12 -> V_239 ) ;
if ( F_177 ( V_12 ) && V_331 ) {
V_108 = F_195 ( V_12 , V_331 , V_332 ) ;
if ( V_108 )
goto V_353;
}
V_12 -> V_282 = V_302 ;
V_108 = V_12 -> V_20 -> V_354 ( V_12 ) ;
if ( V_108 < 0 ) {
F_69 ( V_12 -> V_15 . V_81 , L_50 , V_108 ) ;
goto V_355;
}
V_108 = F_61 ( V_12 ) ;
if ( V_108 != 0 )
goto V_356;
V_108 = F_212 ( & V_287 -> V_50 . V_357 , & V_358 ) ;
if ( V_108 < 0 ) {
F_213 ( V_359 L_51 ,
V_108 ) ;
goto V_360;
}
if ( V_12 -> V_100 && F_28 ( V_12 ) )
F_22 ( V_12 ) ;
return V_108 ;
V_360:
F_25 ( V_292 , & V_12 -> V_97 ) ;
if ( F_214 ( V_12 -> V_282 ) )
V_12 -> V_282 = V_293 ;
F_7 ( & V_37 ) ;
V_12 -> V_155 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_215 ( & V_12 -> V_307 ) ;
#endif
F_52 ( & V_138 ) ;
F_216 ( & V_287 ) ;
F_55 ( & V_138 ) ;
V_356:
V_12 -> V_99 = 0 ;
F_25 ( V_317 , & V_12 -> V_97 ) ;
F_217 ( & V_12 -> V_104 ) ;
V_12 -> V_20 -> V_361 ( V_12 ) ;
V_12 -> V_282 = V_362 ;
F_25 ( V_317 , & V_12 -> V_97 ) ;
F_217 ( & V_12 -> V_104 ) ;
V_355:
if ( F_177 ( V_12 ) && V_12 -> V_312 > 0 )
F_218 ( V_331 , V_12 ) ;
V_353:
V_352:
V_351:
F_197 ( V_12 ) ;
V_348:
F_58 ( & V_12 -> V_15 ) ;
V_347:
F_219 ( V_12 ) ;
V_346:
if ( F_96 ( V_341 ) && V_12 -> V_340 && V_12 -> V_338 ) {
F_220 ( V_12 -> V_338 ) ;
F_208 ( V_12 -> V_338 ) ;
F_206 ( V_12 -> V_338 ) ;
V_12 -> V_338 = NULL ;
}
V_342:
if ( V_12 -> V_340 && V_12 -> V_337 ) {
F_221 ( V_12 -> V_337 ) ;
F_203 ( V_12 -> V_337 ) ;
V_12 -> V_337 = NULL ;
}
return V_108 ;
}
void F_222 ( struct V_11 * V_12 )
{
struct V_1 * V_287 = V_12 -> V_15 . V_49 ;
F_57 ( V_12 -> V_15 . V_81 , L_52 , V_12 -> V_282 ) ;
F_126 ( V_287 ) ;
F_223 ( & V_287 -> V_50 . V_357 , & V_358 ) ;
F_25 ( V_292 , & V_12 -> V_97 ) ;
if ( F_214 ( V_12 -> V_282 ) )
V_12 -> V_282 = V_293 ;
F_16 ( V_12 -> V_15 . V_81 , L_53 ) ;
F_7 ( & V_37 ) ;
V_12 -> V_155 = 0 ;
F_9 ( & V_37 ) ;
#ifdef F_186
F_215 ( & V_12 -> V_307 ) ;
#endif
F_52 ( & V_138 ) ;
F_216 ( & V_287 ) ;
F_55 ( & V_138 ) ;
V_12 -> V_99 = 0 ;
F_25 ( V_317 , & V_12 -> V_97 ) ;
F_217 ( & V_12 -> V_104 ) ;
V_12 -> V_20 -> V_361 ( V_12 ) ;
V_12 -> V_282 = V_362 ;
F_25 ( V_317 , & V_12 -> V_97 ) ;
F_217 ( & V_12 -> V_104 ) ;
if ( F_177 ( V_12 ) ) {
if ( V_12 -> V_312 > 0 )
F_218 ( V_12 -> V_312 , V_12 ) ;
}
F_58 ( & V_12 -> V_15 ) ;
F_219 ( V_12 ) ;
if ( F_96 ( V_341 ) && V_12 -> V_340 && V_12 -> V_338 ) {
F_220 ( V_12 -> V_338 ) ;
F_208 ( V_12 -> V_338 ) ;
F_206 ( V_12 -> V_338 ) ;
V_12 -> V_338 = NULL ;
}
if ( V_12 -> V_340 && V_12 -> V_337 ) {
F_221 ( V_12 -> V_337 ) ;
F_203 ( V_12 -> V_337 ) ;
V_12 -> V_337 = NULL ;
}
F_197 ( V_12 ) ;
}
void
F_224 ( struct V_363 * V_50 )
{
struct V_11 * V_12 = F_225 ( V_50 ) ;
if ( V_12 -> V_20 -> V_364 )
V_12 -> V_20 -> V_364 ( V_12 ) ;
}
int F_226 ( const struct V_365 * V_366 )
{
if ( V_367 )
return - V_181 ;
V_367 = V_366 ;
F_227 () ;
return 0 ;
}
void F_228 ( void )
{
if ( V_367 == NULL ) {
F_213 ( V_359 L_54 ) ;
return;
}
V_367 = NULL ;
F_227 () ;
}
