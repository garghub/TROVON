static T_1 F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_1 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
enum V_14 V_15 ;
unsigned long V_16 ;
for ( V_15 = V_17 ;
V_15 < F_4 ( V_18 ) ; V_15 ++ ) {
const char * V_19 = V_18 [ V_15 ] ;
if ( strncmp ( V_19 , V_4 , strlen ( V_19 ) ) == 0 )
break;
}
if ( V_15 == F_4 ( V_18 ) )
return - V_20 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, &ap->link, ENABLED) {
if ( V_13 -> V_22 & V_23 ) {
V_5 = - V_24 ;
goto V_25;
}
}
}
V_9 -> V_26 = V_15 ;
F_8 ( V_9 ) ;
V_25:
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_5 ;
}
static T_1 F_10 ( struct V_1 * V_13 ,
struct V_2 * V_3 , char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_26 >= F_4 ( V_18 ) )
return - V_20 ;
return snprintf ( V_4 , V_27 , L_1 ,
V_18 [ V_9 -> V_26 ] ) ;
}
static T_1 F_11 ( struct V_1 * V_1 ,
struct V_2 * V_3 , char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_1 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_30 ;
unsigned int V_31 ( V_32 ) ;
int V_33 = 0 ;
V_9 = F_3 ( V_29 -> V_34 ) ;
F_13 ( V_9 -> V_21 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( ! V_13 ) {
V_33 = - V_35 ;
goto V_36;
}
if ( V_13 -> V_16 & V_37 ) {
V_33 = - V_24 ;
goto V_36;
}
V_11 = V_13 -> V_11 ;
V_30 = V_38 ;
if ( V_9 -> V_39 & V_40 &&
V_11 -> V_41 . V_42 & ( 1 << V_13 -> V_43 ) &&
F_15 ( V_13 -> V_44 , V_30 ) )
V_32 = F_16 ( V_13 -> V_44 - V_30 ) ;
else
V_32 = 0 ;
V_36:
F_17 ( V_9 -> V_21 ) ;
return V_33 ? V_33 : snprintf ( V_4 , 20 , L_2 , V_32 ) ;
}
static T_1 F_18 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 , T_2 V_45 )
{
struct V_28 * V_29 = F_12 ( V_1 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 ;
long int V_46 ;
unsigned long V_16 ;
int V_33 ;
V_33 = F_19 ( V_4 , 10 , & V_46 ) ;
if ( V_33 )
return V_33 ;
if ( V_46 < - 2 )
return - V_20 ;
if ( V_46 > V_47 ) {
V_33 = - V_48 ;
V_46 = V_47 ;
}
V_9 = F_3 ( V_29 -> V_34 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( F_20 ( ! V_13 ) ) {
V_33 = - V_35 ;
goto V_36;
}
if ( V_13 -> V_49 != V_50 &&
V_13 -> V_49 != V_51 ) {
V_33 = - V_24 ;
goto V_36;
}
if ( V_46 >= 0 ) {
if ( V_13 -> V_16 & V_37 ) {
V_33 = - V_24 ;
goto V_36;
}
V_13 -> V_44 = F_21 ( V_38 , V_46 ) ;
V_13 -> V_11 -> V_52 . V_53 [ V_13 -> V_43 ] |= V_54 ;
F_8 ( V_9 ) ;
F_22 ( & V_9 -> V_55 ) ;
} else {
switch ( V_46 ) {
case - 1 :
V_13 -> V_16 &= ~ V_37 ;
break;
case - 2 :
V_13 -> V_16 |= V_37 ;
break;
}
}
V_36:
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ? V_33 : V_45 ;
}
void F_23 ( struct V_12 * V_13 , struct V_56 * V_57 ,
T_3 V_58 , T_3 V_59 , T_3 V_60 )
{
bool V_61 = ( V_13 -> V_16 & V_62 ) ;
if ( ! V_57 )
return;
V_57 -> V_63 = ( V_64 << 24 ) | V_65 ;
F_24 ( V_61 , V_57 -> V_66 , V_58 , V_59 , V_60 ) ;
}
void F_25 ( struct V_12 * V_13 ,
struct V_56 * V_57 ,
const struct V_67 * V_68 )
{
T_4 V_69 ;
if ( ! V_57 )
return;
V_69 = F_26 ( V_68 , V_13 ) ;
if ( V_69 == V_70 )
return;
F_27 ( V_57 -> V_66 ,
V_71 , V_69 ) ;
}
static void F_28 ( struct V_12 * V_13 ,
struct V_56 * V_57 , T_5 V_72 , T_3 V_73 )
{
F_23 ( V_13 , V_57 , V_74 , 0x24 , 0x0 ) ;
F_29 ( V_57 -> V_66 , V_71 ,
V_72 , V_73 , 1 ) ;
}
static void F_30 ( struct V_12 * V_13 ,
struct V_56 * V_57 , T_5 V_72 )
{
F_23 ( V_13 , V_57 , V_74 , 0x26 , 0x0 ) ;
F_29 ( V_57 -> V_66 , V_71 ,
V_72 , 0xff , 0 ) ;
}
static T_1
F_31 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_75 -> V_76 && ( V_9 -> V_16 & V_77 ) )
return V_9 -> V_75 -> V_76 ( V_9 , V_4 , V_5 ) ;
return - V_20 ;
}
static T_1
F_32 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_75 -> V_78 && ( V_9 -> V_16 & V_77 ) )
return V_9 -> V_75 -> V_78 ( V_9 , V_4 ) ;
return - V_20 ;
}
static T_1
F_33 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_4 , 23 , L_3 , V_9 -> V_79 ) ;
}
static T_1
F_34 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_80 = F_14 ( V_9 , V_29 ) ;
if ( V_80 && V_9 -> V_75 -> V_81 &&
( V_9 -> V_16 & V_82 ) )
return V_9 -> V_75 -> V_81 ( V_80 , V_4 ) ;
return - V_20 ;
}
static T_1
F_35 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_80 = F_14 ( V_9 , V_29 ) ;
enum V_83 V_84 ;
int V_33 ;
if ( V_80 && V_9 -> V_75 -> V_85 &&
( V_9 -> V_16 & V_82 ) ) {
V_84 = F_36 ( V_4 , NULL , 0 ) ;
switch ( V_84 ) {
case V_86 : case V_87 : case V_88 :
V_33 = V_9 -> V_75 -> V_85 ( V_80 , V_84 ) ;
if ( ! V_33 )
return V_5 ;
else
return V_33 ;
}
}
return - V_20 ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_56 * V_57 , T_5 V_72 )
{
F_28 ( V_13 , V_57 , V_72 , 0xff ) ;
V_57 -> V_89 ( V_57 ) ;
}
int F_38 ( struct V_28 * V_29 , struct V_90 * V_91 ,
T_6 V_92 , int V_93 [] )
{
V_93 [ 0 ] = 255 ;
V_93 [ 1 ] = 63 ;
F_39 ( V_92 , 255 * 63 ) ;
V_93 [ 2 ] = V_92 ;
return 0 ;
}
void F_40 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_94 < V_13 -> V_95 ) {
V_13 -> V_16 |= V_96 ;
V_13 -> V_11 -> V_52 . V_97 |= V_98 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_41 ( V_9 ) ;
}
static int F_42 ( struct V_8 * V_9 , struct V_28 * V_29 ,
void T_7 * V_99 )
{
struct V_12 * V_13 = F_14 ( V_9 , V_29 ) ;
T_5 T_7 * V_100 = V_99 ;
char V_4 [ 40 ] ;
if ( ! V_13 )
return - V_101 ;
if ( F_43 ( V_100 , V_13 -> V_102 , V_103 * sizeof( T_5 ) ) )
return - V_104 ;
F_44 ( V_13 -> V_102 , V_4 , V_105 , V_106 ) ;
if ( F_43 ( V_100 + V_105 , V_4 , V_106 ) )
return - V_104 ;
F_44 ( V_13 -> V_102 , V_4 , V_107 , V_108 ) ;
if ( F_43 ( V_100 + V_107 , V_4 , V_108 ) )
return - V_104 ;
F_44 ( V_13 -> V_102 , V_4 , V_109 , V_110 ) ;
if ( F_43 ( V_100 + V_109 , V_4 , V_110 ) )
return - V_104 ;
return 0 ;
}
int F_45 ( struct V_28 * V_111 , void T_7 * V_99 )
{
int V_33 = 0 ;
T_3 V_112 [ V_113 ] ;
T_3 args [ 4 ] , * V_114 = NULL , * V_115 = NULL ;
int V_116 = 0 ;
enum V_117 V_118 ;
int V_119 ;
if ( V_99 == NULL )
return - V_20 ;
if ( F_46 ( args , V_99 , sizeof( args ) ) )
return - V_104 ;
V_115 = F_47 ( V_71 , V_120 ) ;
if ( ! V_115 )
return - V_121 ;
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
if ( args [ 3 ] ) {
V_116 = V_122 * args [ 3 ] ;
V_114 = F_48 ( V_116 , V_123 ) ;
if ( V_114 == NULL ) {
V_33 = - V_121 ;
goto error;
}
V_112 [ 1 ] = ( 4 << 1 ) ;
V_112 [ 2 ] = 0x0e ;
V_118 = V_124 ;
} else {
V_112 [ 1 ] = ( 3 << 1 ) ;
V_112 [ 2 ] = 0x20 ;
V_118 = V_125 ;
}
V_112 [ 0 ] = V_126 ;
V_112 [ 4 ] = args [ 2 ] ;
if ( args [ 0 ] == V_127 ) {
V_112 [ 6 ] = args [ 3 ] ;
V_112 [ 8 ] = args [ 1 ] ;
V_112 [ 10 ] = 0x4f ;
V_112 [ 12 ] = 0xc2 ;
} else {
V_112 [ 6 ] = args [ 1 ] ;
}
V_112 [ 14 ] = args [ 0 ] ;
V_119 = F_49 ( V_111 , V_112 , V_118 , V_114 , V_116 ,
V_115 , ( 10 * V_128 ) , 5 , 0 , NULL ) ;
if ( F_50 ( V_119 ) == V_64 ) {
T_3 * V_129 = V_115 + 8 ;
V_119 &= ~ ( 0xFF << 24 ) ;
if ( V_119 & V_65 ) {
struct V_130 V_131 ;
F_51 ( V_115 , V_71 ,
& V_131 ) ;
if ( V_131 . V_132 == V_133 &&
V_131 . V_59 == 0 && V_131 . V_60 == 0x1d )
V_119 &= ~ V_65 ;
}
if ( V_115 [ 0 ] == 0x72 &&
V_129 [ 0 ] == 0x09 ) {
args [ 0 ] = V_129 [ 13 ] ;
args [ 1 ] = V_129 [ 3 ] ;
args [ 2 ] = V_129 [ 5 ] ;
if ( F_43 ( V_99 , args , sizeof( args ) ) )
V_33 = - V_104 ;
}
}
if ( V_119 ) {
V_33 = - V_134 ;
goto error;
}
if ( ( V_114 )
&& F_43 ( V_99 + sizeof( args ) , V_114 , V_116 ) )
V_33 = - V_104 ;
error:
F_52 ( V_115 ) ;
F_52 ( V_114 ) ;
return V_33 ;
}
int F_53 ( struct V_28 * V_111 , void T_7 * V_99 )
{
int V_33 = 0 ;
T_3 V_112 [ V_113 ] ;
T_3 args [ 7 ] , * V_115 = NULL ;
int V_119 ;
if ( V_99 == NULL )
return - V_20 ;
if ( F_46 ( args , V_99 , sizeof( args ) ) )
return - V_104 ;
V_115 = F_47 ( V_71 , V_120 ) ;
if ( ! V_115 )
return - V_121 ;
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
V_112 [ 0 ] = V_126 ;
V_112 [ 1 ] = ( 3 << 1 ) ;
V_112 [ 2 ] = 0x20 ;
V_112 [ 4 ] = args [ 1 ] ;
V_112 [ 6 ] = args [ 2 ] ;
V_112 [ 8 ] = args [ 3 ] ;
V_112 [ 10 ] = args [ 4 ] ;
V_112 [ 12 ] = args [ 5 ] ;
V_112 [ 13 ] = args [ 6 ] & 0x4f ;
V_112 [ 14 ] = args [ 0 ] ;
V_119 = F_49 ( V_111 , V_112 , V_125 , NULL , 0 ,
V_115 , ( 10 * V_128 ) , 5 , 0 , NULL ) ;
if ( F_50 ( V_119 ) == V_64 ) {
T_3 * V_129 = V_115 + 8 ;
V_119 &= ~ ( 0xFF << 24 ) ;
if ( V_119 & V_65 ) {
struct V_130 V_131 ;
F_51 ( V_115 , V_71 ,
& V_131 ) ;
if ( V_131 . V_132 == V_133 &&
V_131 . V_59 == 0 && V_131 . V_60 == 0x1d )
V_119 &= ~ V_65 ;
}
if ( V_115 [ 0 ] == 0x72 &&
V_129 [ 0 ] == 0x09 ) {
args [ 0 ] = V_129 [ 13 ] ;
args [ 1 ] = V_129 [ 3 ] ;
args [ 2 ] = V_129 [ 5 ] ;
args [ 3 ] = V_129 [ 7 ] ;
args [ 4 ] = V_129 [ 9 ] ;
args [ 5 ] = V_129 [ 11 ] ;
args [ 6 ] = V_129 [ 12 ] ;
if ( F_43 ( V_99 , args , sizeof( args ) ) )
V_33 = - V_104 ;
}
}
if ( V_119 ) {
V_33 = - V_134 ;
goto error;
}
error:
F_52 ( V_115 ) ;
return V_33 ;
}
static int F_54 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 & V_135 )
return 1 ;
if ( V_9 -> V_39 & V_136 )
return 1 ;
return 0 ;
}
int F_55 ( struct V_8 * V_9 , struct V_28 * V_111 ,
int V_57 , void T_7 * V_99 )
{
unsigned long V_84 ;
int V_33 = - V_20 ;
unsigned long V_16 ;
switch ( V_57 ) {
case V_137 :
F_5 ( V_9 -> V_21 , V_16 ) ;
V_84 = F_54 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
return F_56 ( V_84 , ( unsigned long T_7 * ) V_99 ) ;
case V_138 :
V_84 = ( unsigned long ) V_99 ;
V_33 = 0 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_9 -> V_39 & V_139 ) {
if ( V_84 )
V_9 -> V_39 |= V_136 ;
else
V_9 -> V_39 &= ~ V_136 ;
} else {
if ( V_84 != F_54 ( V_9 ) )
V_33 = - V_20 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
case V_140 :
return F_42 ( V_9 , V_111 , V_99 ) ;
case V_141 :
if ( ! F_57 ( V_142 ) || ! F_57 ( V_143 ) )
return - V_144 ;
return F_45 ( V_111 , V_99 ) ;
case V_145 :
if ( ! F_57 ( V_142 ) || ! F_57 ( V_143 ) )
return - V_144 ;
return F_53 ( V_111 , V_99 ) ;
default:
V_33 = - V_146 ;
break;
}
return V_33 ;
}
int F_58 ( struct V_28 * V_111 , int V_57 , void T_7 * V_99 )
{
return F_55 ( F_3 ( V_111 -> V_34 ) ,
V_111 , V_57 , V_99 ) ;
}
static struct V_147 * F_59 ( struct V_12 * V_13 ,
struct V_56 * V_57 )
{
struct V_147 * V_148 ;
V_148 = F_60 ( V_13 , V_57 -> V_149 -> V_150 ) ;
if ( V_148 ) {
V_148 -> V_151 = V_57 ;
V_148 -> V_152 = V_57 -> V_89 ;
V_148 -> V_153 = F_61 ( V_57 ) ;
V_148 -> V_154 = F_62 ( V_57 ) ;
} else {
V_57 -> V_63 = ( V_155 << 16 ) | ( V_156 << 1 ) ;
V_57 -> V_89 ( V_57 ) ;
}
return V_148 ;
}
static void F_63 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
V_148 -> V_158 = V_157 -> V_149 -> V_159 ;
V_148 -> V_160 = F_64 ( V_157 ) + V_148 -> V_158 ;
}
static void F_65 ( unsigned V_102 , struct V_67 * V_68 )
{
T_3 V_161 = V_68 -> V_162 , V_163 = V_68 -> V_164 ;
F_66 ( V_165 L_4 , V_102 , V_161 ) ;
if ( V_161 & V_166 ) {
F_66 ( L_5 ) ;
} else {
if ( V_161 & V_167 ) F_66 ( L_6 ) ;
if ( V_161 & V_168 ) F_66 ( L_7 ) ;
if ( V_161 & V_169 ) F_66 ( L_8 ) ;
if ( V_161 & V_170 ) F_66 ( L_9 ) ;
if ( V_161 & V_171 ) F_66 ( L_10 ) ;
if ( V_161 & V_172 ) F_66 ( L_11 ) ;
if ( V_161 & V_173 ) F_66 ( L_12 ) ;
F_66 ( L_13 ) ;
if ( V_163 ) {
F_66 ( V_165 L_14 , V_102 , V_163 ) ;
if ( V_163 & V_174 ) F_66 ( L_15 ) ;
if ( V_163 & V_175 ) {
if ( V_163 & V_174 )
F_66 ( L_16 ) ;
else F_66 ( L_17 ) ;
}
if ( V_163 & V_176 ) F_66 ( L_18 ) ;
if ( V_163 & V_177 ) F_66 ( L_19 ) ;
if ( V_163 & V_178 ) F_66 ( L_20 ) ;
if ( V_163 & V_179 ) F_66 ( L_21 ) ;
F_66 ( L_13 ) ;
}
}
}
static void F_67 ( unsigned V_102 , T_3 V_180 , T_3 V_181 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 , int V_182 )
{
int V_183 ;
static const unsigned char V_184 [] [ 4 ] = {
{ 0xd1 , V_185 , 0x00 , 0x00 } ,
{ 0xd0 , V_185 , 0x00 , 0x00 } ,
{ 0x61 , V_186 , 0x00 , 0x00 } ,
{ 0x84 , V_185 , 0x47 , 0x00 } ,
{ 0x37 , V_187 , 0x04 , 0x00 } ,
{ 0x09 , V_187 , 0x04 , 0x00 } ,
{ 0x01 , V_188 , 0x13 , 0x00 } ,
{ 0x02 , V_186 , 0x00 , 0x00 } ,
{ 0x08 , V_187 , 0x04 , 0x00 } ,
{ 0x10 , V_74 , 0x21 , 0x00 } ,
{ 0x20 , V_189 , 0x28 , 0x00 } ,
{ 0x40 , V_188 , 0x11 , 0x04 } ,
{ 0x80 , V_188 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_190 [] [ 4 ] = {
{ 0x80 , V_185 , 0x47 , 0x00 } ,
{ 0x40 , V_74 , 0x21 , 0x04 } ,
{ 0x20 , V_186 , 0x44 , 0x00 } ,
{ 0x08 , V_185 , 0x47 , 0x00 } ,
{ 0x04 , V_133 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_180 & V_166 ) {
V_181 = 0 ;
}
if ( V_181 ) {
for ( V_183 = 0 ; V_184 [ V_183 ] [ 0 ] != 0xFF ; V_183 ++ ) {
if ( ( V_184 [ V_183 ] [ 0 ] & V_181 ) ==
V_184 [ V_183 ] [ 0 ] ) {
* V_58 = V_184 [ V_183 ] [ 1 ] ;
* V_59 = V_184 [ V_183 ] [ 2 ] ;
* V_60 = V_184 [ V_183 ] [ 3 ] ;
goto V_191;
}
}
}
for ( V_183 = 0 ; V_190 [ V_183 ] [ 0 ] != 0xFF ; V_183 ++ ) {
if ( V_190 [ V_183 ] [ 0 ] & V_180 ) {
* V_58 = V_190 [ V_183 ] [ 1 ] ;
* V_59 = V_190 [ V_183 ] [ 2 ] ;
* V_60 = V_190 [ V_183 ] [ 3 ] ;
goto V_191;
}
}
* V_58 = V_185 ;
* V_59 = 0x00 ;
* V_60 = 0x00 ;
V_191:
if ( V_182 )
F_66 ( V_192 L_22
L_23 ,
V_102 , V_180 , V_181 , * V_58 , * V_59 , * V_60 ) ;
return;
}
static void F_68 ( struct V_147 * V_148 )
{
struct V_56 * V_57 = V_148 -> V_151 ;
struct V_67 * V_68 = & V_148 -> V_193 ;
unsigned char * V_194 = V_57 -> V_66 ;
unsigned char * V_129 = V_194 + 8 ;
int V_182 = V_148 -> V_9 -> V_75 -> V_195 == NULL ;
T_3 V_132 , V_59 , V_60 ;
memset ( V_194 , 0 , V_71 ) ;
V_57 -> V_63 = ( V_64 << 24 ) | V_65 ;
if ( V_148 -> V_196 ||
V_68 -> V_162 & ( V_166 | V_168 | V_173 | V_170 ) ) {
F_67 ( V_148 -> V_9 -> V_197 , V_68 -> V_162 , V_68 -> V_164 ,
& V_132 , & V_59 , & V_60 , V_182 ) ;
F_23 ( V_148 -> V_13 , V_57 , V_132 , V_59 , V_60 ) ;
} else {
F_24 ( 1 , V_57 -> V_66 ,
V_133 , 0 , 0x1D ) ;
}
if ( ( V_57 -> V_66 [ 0 ] & 0x7f ) >= 0x72 ) {
T_3 V_45 ;
V_45 = V_194 [ 7 ] ;
V_129 = ( char * ) F_69 ( V_194 , V_45 + 8 , 9 ) ;
if ( ! V_129 ) {
if ( V_71 < V_45 + 14 )
return;
V_194 [ 7 ] = V_45 + 14 ;
V_129 = V_194 + 8 + V_45 ;
}
V_129 [ 0 ] = 9 ;
V_129 [ 1 ] = 12 ;
V_129 [ 2 ] = 0x00 ;
V_129 [ 3 ] = V_68 -> V_164 ;
V_129 [ 5 ] = V_68 -> V_198 ;
V_129 [ 7 ] = V_68 -> V_199 ;
V_129 [ 9 ] = V_68 -> V_200 ;
V_129 [ 11 ] = V_68 -> V_201 ;
V_129 [ 12 ] = V_68 -> V_1 ;
V_129 [ 13 ] = V_68 -> V_162 ;
if ( V_68 -> V_16 & V_202 ) {
V_129 [ 2 ] |= 0x01 ;
V_129 [ 4 ] = V_68 -> V_203 ;
V_129 [ 6 ] = V_68 -> V_204 ;
V_129 [ 8 ] = V_68 -> V_205 ;
V_129 [ 10 ] = V_68 -> V_206 ;
}
} else {
V_129 [ 0 ] = V_68 -> V_164 ;
V_129 [ 1 ] = V_68 -> V_162 ;
V_129 [ 2 ] = V_68 -> V_1 ;
V_129 [ 3 ] = V_68 -> V_198 ;
V_129 [ 0 ] = 0 ;
if ( V_68 -> V_16 & V_202 ) {
V_129 [ 8 ] |= 0x80 ;
if ( V_68 -> V_203 )
V_129 [ 8 ] |= 0x40 ;
if ( V_68 -> V_204 || V_68 -> V_205 || V_68 -> V_206 )
V_129 [ 8 ] |= 0x20 ;
}
V_129 [ 9 ] = V_68 -> V_199 ;
V_129 [ 10 ] = V_68 -> V_200 ;
V_129 [ 11 ] = V_68 -> V_201 ;
}
}
static void F_70 ( struct V_147 * V_148 )
{
struct V_12 * V_13 = V_148 -> V_13 ;
struct V_56 * V_57 = V_148 -> V_151 ;
struct V_67 * V_68 = & V_148 -> V_193 ;
unsigned char * V_194 = V_57 -> V_66 ;
int V_182 = V_148 -> V_9 -> V_75 -> V_195 == NULL ;
T_4 V_207 ;
T_3 V_132 , V_59 , V_60 ;
memset ( V_194 , 0 , V_71 ) ;
V_57 -> V_63 = ( V_64 << 24 ) | V_65 ;
if ( F_71 ( V_13 ) ) {
F_23 ( V_13 , V_57 , V_187 , 0x04 , 0x21 ) ;
return;
}
if ( V_148 -> V_196 ||
V_68 -> V_162 & ( V_166 | V_168 | V_173 | V_170 ) ) {
F_67 ( V_148 -> V_9 -> V_197 , V_68 -> V_162 , V_68 -> V_164 ,
& V_132 , & V_59 , & V_60 , V_182 ) ;
F_23 ( V_13 , V_57 , V_132 , V_59 , V_60 ) ;
} else {
F_72 ( V_13 , L_24 ,
V_68 -> V_162 , V_148 -> V_196 ) ;
F_23 ( V_13 , V_57 , V_185 , 0 , 0 ) ;
return;
}
V_207 = F_26 ( & V_148 -> V_193 , V_13 ) ;
if ( V_207 == V_70 )
return;
F_27 ( V_194 , V_71 , V_207 ) ;
}
static void F_73 ( struct V_28 * V_29 )
{
V_29 -> V_208 = 1 ;
V_29 -> V_209 = 1 ;
V_29 -> V_210 = 1 ;
V_29 -> V_211 = 1 ;
V_29 -> V_212 = 1 ;
}
static int F_74 ( struct V_149 * V_213 )
{
if ( F_75 ( V_213 -> V_214 != V_215 ) )
return 0 ;
if ( ! F_76 ( V_213 ) || ( V_213 -> V_216 & V_217 ) )
return 0 ;
return F_77 ( V_213 -> V_57 [ 0 ] ) == V_218 ;
}
static int F_78 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_219 * V_220 = V_29 -> V_219 ;
if ( ! F_79 ( V_13 -> V_102 ) )
V_13 -> V_16 |= V_37 ;
F_80 ( V_220 , V_13 -> V_221 ) ;
if ( V_13 -> V_49 == V_222 ) {
void * V_4 ;
V_29 -> V_223 = V_122 ;
F_81 ( V_220 , V_224 - 1 ) ;
V_4 = F_48 ( V_225 , V_220 -> V_226 | V_123 ) ;
if ( ! V_4 ) {
F_82 ( V_13 , L_25 ) ;
return - V_121 ;
}
F_83 ( V_220 , F_74 , V_4 , V_225 ) ;
} else {
V_29 -> V_223 = F_84 ( V_13 -> V_102 ) ;
V_29 -> V_227 = 1 ;
}
if ( V_29 -> V_223 > V_27 )
F_72 ( V_13 ,
L_26 ,
V_29 -> V_223 ) ;
F_85 ( V_220 , V_29 -> V_223 - 1 ) ;
if ( V_13 -> V_16 & V_228 )
F_86 ( V_229 , V_29 -> V_230 ) ;
if ( V_13 -> V_16 & V_231 ) {
int V_232 ;
V_232 = F_87 ( V_29 -> V_34 -> V_233 , F_88 ( V_13 -> V_102 ) ) ;
V_232 = F_87 ( V_234 - 1 , V_232 ) ;
F_89 ( V_29 , V_232 ) ;
}
F_90 ( V_220 , false ) ;
V_13 -> V_29 = V_29 ;
return 0 ;
}
int F_91 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 = F_92 ( V_9 , V_29 ) ;
int V_33 = 0 ;
F_73 ( V_29 ) ;
if ( V_13 )
V_33 = F_78 ( V_29 , V_13 ) ;
return V_33 ;
}
void F_93 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_219 * V_220 = V_29 -> V_219 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_75 -> V_195 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_92 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_235 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_52 ( V_220 -> V_236 ) ;
V_220 -> V_236 = NULL ;
V_220 -> V_237 = 0 ;
}
int F_94 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_238 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_238 < 1 || V_238 == V_29 -> V_238 )
return V_29 -> V_238 ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_95 ( V_13 ) )
return V_29 -> V_238 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_239 ;
if ( V_238 == 1 || ! F_96 ( V_13 ) ) {
V_13 -> V_16 |= V_239 ;
V_238 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_238 = F_87 ( V_238 , V_29 -> V_34 -> V_233 ) ;
V_238 = F_87 ( V_238 , F_88 ( V_13 -> V_102 ) ) ;
V_238 = F_87 ( V_238 , V_234 - 1 ) ;
if ( V_29 -> V_238 == V_238 )
return - V_20 ;
return F_89 ( V_29 , V_238 ) ;
}
int F_97 ( struct V_28 * V_29 , int V_238 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_94 ( V_9 , V_29 , V_238 ) ;
}
static unsigned int F_98 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_67 * V_68 = & V_148 -> V_68 ;
const T_3 * V_240 = V_157 -> V_241 ;
T_5 V_242 ;
T_3 V_243 = 0xff ;
if ( V_157 -> V_244 < 5 ) {
V_242 = 4 ;
goto V_245;
}
V_68 -> V_16 |= V_246 | V_247 ;
V_68 -> V_248 = V_249 ;
if ( V_240 [ 1 ] & 0x1 ) {
;
}
if ( V_240 [ 4 ] & 0x2 ) {
V_242 = 4 ;
V_243 = 1 ;
goto V_245;
}
if ( ( ( V_240 [ 4 ] >> 4 ) & 0xf ) != 0 ) {
V_242 = 4 ;
V_243 = 3 ;
goto V_245;
}
if ( V_240 [ 4 ] & 0x1 ) {
V_68 -> V_198 = 1 ;
if ( V_148 -> V_13 -> V_16 & V_250 ) {
V_68 -> V_16 |= V_251 ;
V_68 -> V_201 = 0x0 ;
V_68 -> V_200 = 0x0 ;
V_68 -> V_199 = 0x0 ;
V_68 -> V_1 |= V_252 ;
} else {
V_68 -> V_199 = 0x1 ;
V_68 -> V_200 = 0x0 ;
V_68 -> V_201 = 0x0 ;
}
V_68 -> V_162 = V_253 ;
} else {
if ( ( V_148 -> V_9 -> V_16 & V_254 ) &&
V_255 == V_256 )
goto V_257;
if ( ( V_148 -> V_9 -> V_16 & V_258 ) &&
F_99 () )
goto V_257;
V_68 -> V_162 = V_259 ;
}
return 0 ;
V_245:
F_28 ( V_148 -> V_13 , V_157 , V_242 , V_243 ) ;
return 1 ;
V_257:
V_157 -> V_63 = V_260 ;
return 1 ;
}
static unsigned int F_100 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
V_68 -> V_16 |= V_246 ;
V_68 -> V_248 = V_249 ;
if ( V_148 -> V_13 -> V_16 & V_261 )
V_68 -> V_162 = V_262 ;
else
V_68 -> V_162 = V_263 ;
V_148 -> V_16 |= V_264 ;
return 0 ;
}
static void F_101 ( const T_3 * V_240 , T_4 * V_265 , T_8 * V_266 )
{
T_4 V_267 = 0 ;
T_8 V_45 ;
F_102 ( L_27 ) ;
V_267 |= ( ( T_4 ) ( V_240 [ 1 ] & 0x1f ) ) << 16 ;
V_267 |= ( ( T_4 ) V_240 [ 2 ] ) << 8 ;
V_267 |= ( ( T_4 ) V_240 [ 3 ] ) ;
V_45 = V_240 [ 4 ] ;
* V_265 = V_267 ;
* V_266 = V_45 ;
}
static void F_103 ( const T_3 * V_240 , T_4 * V_265 , T_8 * V_266 )
{
T_4 V_267 = 0 ;
T_8 V_45 = 0 ;
F_102 ( L_28 ) ;
V_267 |= ( ( T_4 ) V_240 [ 2 ] ) << 24 ;
V_267 |= ( ( T_4 ) V_240 [ 3 ] ) << 16 ;
V_267 |= ( ( T_4 ) V_240 [ 4 ] ) << 8 ;
V_267 |= ( ( T_4 ) V_240 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_240 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_240 [ 8 ] ) ;
* V_265 = V_267 ;
* V_266 = V_45 ;
}
static void F_104 ( const T_3 * V_240 , T_4 * V_265 , T_8 * V_266 )
{
T_4 V_267 = 0 ;
T_8 V_45 = 0 ;
F_102 ( L_29 ) ;
V_267 |= ( ( T_4 ) V_240 [ 2 ] ) << 56 ;
V_267 |= ( ( T_4 ) V_240 [ 3 ] ) << 48 ;
V_267 |= ( ( T_4 ) V_240 [ 4 ] ) << 40 ;
V_267 |= ( ( T_4 ) V_240 [ 5 ] ) << 32 ;
V_267 |= ( ( T_4 ) V_240 [ 6 ] ) << 24 ;
V_267 |= ( ( T_4 ) V_240 [ 7 ] ) << 16 ;
V_267 |= ( ( T_4 ) V_240 [ 8 ] ) << 8 ;
V_267 |= ( ( T_4 ) V_240 [ 9 ] ) ;
V_45 |= ( ( T_8 ) V_240 [ 10 ] ) << 24 ;
V_45 |= ( ( T_8 ) V_240 [ 11 ] ) << 16 ;
V_45 |= ( ( T_8 ) V_240 [ 12 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_240 [ 13 ] ) ;
* V_265 = V_267 ;
* V_266 = V_45 ;
}
static unsigned int F_105 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_12 * V_13 = V_148 -> V_13 ;
T_4 V_268 = V_148 -> V_13 -> V_94 ;
const T_3 * V_240 = V_157 -> V_241 ;
T_4 V_207 ;
T_8 V_269 ;
T_5 V_242 ;
V_68 -> V_16 |= V_247 | V_246 ;
V_68 -> V_248 = V_249 ;
if ( V_240 [ 0 ] == V_270 ) {
if ( V_157 -> V_244 < 10 ) {
V_242 = 9 ;
goto V_245;
}
F_103 ( V_240 , & V_207 , & V_269 ) ;
} else if ( V_240 [ 0 ] == V_271 ) {
if ( V_157 -> V_244 < 16 ) {
V_242 = 15 ;
goto V_245;
}
F_104 ( V_240 , & V_207 , & V_269 ) ;
} else {
V_242 = 0 ;
goto V_245;
}
if ( ! V_269 )
goto V_272;
if ( V_207 >= V_268 )
goto V_273;
if ( ( V_207 + V_269 ) > V_268 )
goto V_273;
if ( V_13 -> V_16 & V_250 ) {
V_68 -> V_16 |= V_251 ;
if ( F_106 ( V_207 , V_269 ) ) {
V_68 -> V_162 = V_253 ;
V_68 -> V_1 |= ( V_207 >> 24 ) & 0xf ;
} else if ( F_107 ( V_207 , V_269 ) ) {
if ( ! ( V_13 -> V_16 & V_274 ) )
goto V_273;
V_68 -> V_16 |= V_202 ;
V_68 -> V_162 = V_275 ;
V_68 -> V_203 = ( V_269 >> 8 ) & 0xff ;
V_68 -> V_206 = ( V_207 >> 40 ) & 0xff ;
V_68 -> V_205 = ( V_207 >> 32 ) & 0xff ;
V_68 -> V_204 = ( V_207 >> 24 ) & 0xff ;
} else
goto V_273;
V_68 -> V_198 = V_269 & 0xff ;
V_68 -> V_201 = ( V_207 >> 16 ) & 0xff ;
V_68 -> V_200 = ( V_207 >> 8 ) & 0xff ;
V_68 -> V_199 = V_207 & 0xff ;
V_68 -> V_1 |= V_252 ;
} else {
T_8 V_276 , V_277 , V_278 , V_279 ;
if ( ! F_106 ( V_207 , V_269 ) )
goto V_273;
V_279 = ( T_8 ) V_207 / V_13 -> V_280 ;
V_278 = V_279 / V_13 -> V_281 ;
V_277 = V_279 % V_13 -> V_281 ;
V_276 = ( T_8 ) V_207 % V_13 -> V_280 + 1 ;
F_108 ( L_30 ,
( T_8 ) V_207 , V_279 , V_278 , V_277 , V_276 ) ;
if ( ( V_278 >> 16 ) || ( V_277 >> 4 ) || ( V_276 >> 8 ) || ( ! V_276 ) )
goto V_273;
V_68 -> V_162 = V_253 ;
V_68 -> V_198 = V_269 & 0xff ;
V_68 -> V_199 = V_276 ;
V_68 -> V_200 = V_278 ;
V_68 -> V_201 = V_278 >> 8 ;
V_68 -> V_1 |= V_277 ;
}
return 0 ;
V_245:
F_28 ( V_148 -> V_13 , V_157 , V_242 , 0xff ) ;
return 1 ;
V_273:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x21 , 0x0 ) ;
return 1 ;
V_272:
V_157 -> V_63 = V_260 ;
return 1 ;
}
static unsigned int F_109 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
const T_3 * V_240 = V_157 -> V_241 ;
unsigned int V_282 = 0 ;
T_4 V_207 ;
T_8 V_269 ;
int V_33 ;
T_5 V_242 = 0 ;
if ( V_240 [ 0 ] == V_283 || V_240 [ 0 ] == V_284 || V_240 [ 0 ] == V_285 )
V_282 |= V_286 ;
switch ( V_240 [ 0 ] ) {
case V_287 :
case V_283 :
if ( F_20 ( V_157 -> V_244 < 10 ) ) {
V_242 = 9 ;
goto V_245;
}
F_103 ( V_240 , & V_207 , & V_269 ) ;
if ( V_240 [ 1 ] & ( 1 << 3 ) )
V_282 |= V_288 ;
break;
case V_289 :
case V_284 :
if ( F_20 ( V_157 -> V_244 < 6 ) ) {
V_242 = 5 ;
goto V_245;
}
F_101 ( V_240 , & V_207 , & V_269 ) ;
if ( ! V_269 )
V_269 = 256 ;
break;
case V_290 :
case V_285 :
if ( F_20 ( V_157 -> V_244 < 16 ) ) {
V_242 = 15 ;
goto V_245;
}
F_104 ( V_240 , & V_207 , & V_269 ) ;
if ( V_240 [ 1 ] & ( 1 << 3 ) )
V_282 |= V_288 ;
break;
default:
F_108 ( L_31 ) ;
V_242 = 0 ;
goto V_245;
}
if ( ! V_269 )
goto V_272;
V_148 -> V_16 |= V_264 ;
V_148 -> V_160 = V_269 * V_157 -> V_1 -> V_223 ;
V_33 = F_110 ( & V_148 -> V_68 , V_148 -> V_13 , V_207 , V_269 , V_282 ,
V_148 -> V_150 ) ;
if ( F_75 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_291 )
goto V_273;
V_245:
F_28 ( V_148 -> V_13 , V_157 , V_242 , 0xff ) ;
return 1 ;
V_273:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x21 , 0x0 ) ;
return 1 ;
V_272:
V_157 -> V_63 = V_260 ;
return 1 ;
}
static void F_111 ( struct V_147 * V_148 )
{
struct V_56 * V_57 = V_148 -> V_151 ;
void (* F_112)( struct V_56 * ) = V_148 -> V_152 ;
F_113 ( V_148 ) ;
F_112 ( V_57 ) ;
}
static void F_114 ( struct V_147 * V_148 )
{
struct V_8 * V_9 = V_148 -> V_9 ;
struct V_56 * V_57 = V_148 -> V_151 ;
T_3 * V_240 = V_57 -> V_241 ;
int V_292 = ( V_148 -> V_196 != 0 ) ;
if ( ( ( V_240 [ 0 ] == V_126 ) || ( V_240 [ 0 ] == V_293 ) ) &&
( ( V_240 [ 2 ] & 0x20 ) || V_292 ) )
F_68 ( V_148 ) ;
else if ( V_148 -> V_16 & V_294 )
V_57 -> V_63 = V_65 ;
else if ( V_292 )
F_70 ( V_148 ) ;
else
V_57 -> V_63 = V_260 ;
if ( V_292 && ! V_9 -> V_75 -> V_195 )
F_65 ( V_9 -> V_197 , & V_148 -> V_193 ) ;
F_111 ( V_148 ) ;
}
static int F_115 ( struct V_12 * V_13 , struct V_56 * V_57 ,
T_9 V_295 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_147 * V_148 ;
int V_33 ;
F_102 ( L_32 ) ;
V_148 = F_59 ( V_13 , V_57 ) ;
if ( ! V_148 )
goto V_296;
if ( V_57 -> V_297 == V_124 ||
V_57 -> V_297 == V_298 ) {
if ( F_20 ( F_64 ( V_57 ) < 1 ) ) {
F_72 ( V_13 , L_33 ) ;
goto V_299;
}
F_116 ( V_148 , F_61 ( V_57 ) , F_62 ( V_57 ) ) ;
V_148 -> V_300 = V_57 -> V_297 ;
}
V_148 -> V_301 = F_114 ;
if ( V_295 ( V_148 ) )
goto V_302;
if ( V_9 -> V_75 -> V_303 ) {
if ( ( V_33 = V_9 -> V_75 -> V_303 ( V_148 ) ) )
goto V_304;
}
F_117 ( V_148 ) ;
F_102 ( L_34 ) ;
return 0 ;
V_302:
F_113 ( V_148 ) ;
V_57 -> V_89 ( V_57 ) ;
F_108 ( L_35 ) ;
return 0 ;
V_299:
F_113 ( V_148 ) ;
V_57 -> V_63 = ( V_305 << 16 ) ;
V_57 -> V_89 ( V_57 ) ;
V_296:
F_108 ( L_36 ) ;
return 0 ;
V_304:
F_113 ( V_148 ) ;
F_108 ( L_37 ) ;
if ( V_33 == V_306 )
return V_307 ;
else
return V_308 ;
}
static void * F_118 ( struct V_56 * V_57 , bool V_309 ,
unsigned long * V_16 )
{
F_5 ( & V_310 , * V_16 ) ;
memset ( V_311 , 0 , V_312 ) ;
if ( V_309 )
F_119 ( F_61 ( V_57 ) , F_62 ( V_57 ) ,
V_311 , V_312 ) ;
return V_311 ;
}
static inline void F_120 ( struct V_56 * V_57 , bool V_313 ,
unsigned long * V_16 )
{
if ( V_313 )
F_121 ( F_61 ( V_57 ) , F_62 ( V_57 ) ,
V_311 , V_312 ) ;
F_9 ( & V_310 , * V_16 ) ;
}
static unsigned int F_122 ( struct V_314 * args , T_3 * V_315 )
{
const T_3 V_316 [] = {
0x00 ,
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
const T_3 V_317 [] = {
0x00 ,
0xA0 ,
0x06 ,
0x00 ,
0x05 ,
0xC0 ,
0x60 ,
0x24 ,
} ;
T_3 V_318 [] = {
V_319 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_102 ( L_32 ) ;
if ( F_123 ( args -> V_102 ) ||
( args -> V_13 -> V_11 -> V_9 -> V_39 & V_320 ) )
V_318 [ 1 ] |= ( 1 << 7 ) ;
if ( args -> V_13 -> V_49 == V_51 )
V_318 [ 0 ] = V_321 ;
memcpy ( V_315 , V_318 , sizeof( V_318 ) ) ;
memcpy ( & V_315 [ 8 ] , L_38 , 8 ) ;
F_44 ( args -> V_102 , & V_315 [ 16 ] , V_105 , 16 ) ;
F_44 ( args -> V_102 , & V_315 [ 32 ] , V_107 + 2 , 4 ) ;
if ( strncmp ( & V_315 [ 32 ] , L_39 , 4 ) == 0 )
F_44 ( args -> V_102 , & V_315 [ 32 ] , V_107 , 4 ) ;
if ( V_315 [ 32 ] == 0 || V_315 [ 32 ] == ' ' )
memcpy ( & V_315 [ 32 ] , L_40 , 4 ) ;
if ( F_124 ( args -> V_102 ) || args -> V_13 -> V_49 == V_51 )
memcpy ( V_315 + 58 , V_317 , sizeof( V_317 ) ) ;
else
memcpy ( V_315 + 58 , V_316 , sizeof( V_316 ) ) ;
return 0 ;
}
static unsigned int F_125 ( struct V_314 * args , T_3 * V_315 )
{
int V_322 ;
const T_3 V_323 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
0xb6 ,
} ;
V_322 = sizeof( V_323 ) ;
if ( ! ( args -> V_13 -> V_16 & V_324 ) )
V_322 -- ;
V_315 [ 3 ] = V_322 ;
memcpy ( V_315 + 4 , V_323 , V_322 ) ;
return 0 ;
}
static unsigned int F_126 ( struct V_314 * args , T_3 * V_315 )
{
const T_3 V_318 [] = {
0 ,
0x80 ,
0 ,
V_110 ,
} ;
memcpy ( V_315 , V_318 , sizeof( V_318 ) ) ;
F_44 ( args -> V_102 , ( unsigned char * ) & V_315 [ 4 ] ,
V_109 , V_110 ) ;
return 0 ;
}
static unsigned int F_127 ( struct V_314 * args , T_3 * V_315 )
{
const int V_325 = 68 ;
int V_326 ;
V_315 [ 1 ] = 0x83 ;
V_326 = 4 ;
V_315 [ V_326 + 0 ] = 2 ;
V_315 [ V_326 + 3 ] = V_110 ;
V_326 += 4 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_315 + V_326 ,
V_109 , V_110 ) ;
V_326 += V_110 ;
V_315 [ V_326 + 0 ] = 2 ;
V_315 [ V_326 + 1 ] = 1 ;
V_315 [ V_326 + 3 ] = V_325 ;
V_326 += 4 ;
memcpy ( V_315 + V_326 , L_38 , 8 ) ;
V_326 += 8 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_315 + V_326 , V_105 ,
V_106 ) ;
V_326 += V_106 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_315 + V_326 , V_109 ,
V_110 ) ;
V_326 += V_110 ;
if ( F_128 ( args -> V_102 ) ) {
V_315 [ V_326 + 0 ] = 1 ;
V_315 [ V_326 + 1 ] = 3 ;
V_315 [ V_326 + 3 ] = V_327 ;
V_326 += 4 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_315 + V_326 ,
V_328 , V_327 ) ;
V_326 += V_327 ;
}
V_315 [ 3 ] = V_326 - 4 ;
return 0 ;
}
static unsigned int F_129 ( struct V_314 * args , T_3 * V_315 )
{
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_315 [ 1 ] = 0x89 ;
V_315 [ 2 ] = ( 0x238 >> 8 ) ;
V_315 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_315 [ 8 ] , L_41 , 8 ) ;
memcpy ( & V_315 [ 16 ] , L_42 , 16 ) ;
memcpy ( & V_315 [ 32 ] , V_329 , 4 ) ;
V_68 . V_162 = V_167 ;
V_68 . V_199 = 0x1 ;
V_68 . V_198 = 0x1 ;
F_130 ( & V_68 , 0 , 1 , & V_315 [ 36 ] ) ;
V_315 [ 36 ] = 0x34 ;
V_315 [ 56 ] = V_330 ;
memcpy ( & V_315 [ 60 ] , & args -> V_102 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_131 ( struct V_314 * args , T_3 * V_315 )
{
T_5 V_331 ;
V_315 [ 1 ] = 0xb0 ;
V_315 [ 3 ] = 0x3c ;
V_331 = 1 << F_132 ( args -> V_102 ) ;
F_133 ( V_331 , & V_315 [ 6 ] ) ;
if ( F_134 ( args -> V_102 ) ) {
F_135 ( 65535 * 512 / 8 , & V_315 [ 36 ] ) ;
F_136 ( 1 , & V_315 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_137 ( struct V_314 * args , T_3 * V_315 )
{
int V_332 = F_138 ( args -> V_102 ) ;
int V_333 = F_139 ( args -> V_102 ) ;
T_3 V_334 = F_124 ( args -> V_102 ) ;
V_315 [ 1 ] = 0xb1 ;
V_315 [ 3 ] = 0x3c ;
V_315 [ 4 ] = V_333 >> 8 ;
V_315 [ 5 ] = V_333 ;
V_315 [ 7 ] = V_332 ;
if ( V_334 )
V_315 [ 8 ] = ( V_334 << 4 ) ;
return 0 ;
}
static unsigned int F_140 ( struct V_314 * args , T_3 * V_315 )
{
V_315 [ 1 ] = 0xb2 ;
V_315 [ 3 ] = 0x4 ;
V_315 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_141 ( struct V_314 * args , T_3 * V_315 )
{
V_315 [ 1 ] = 0xb6 ;
V_315 [ 3 ] = 0x3C ;
if ( args -> V_13 -> V_335 & 1 )
V_315 [ 4 ] |= 1 ;
F_136 ( args -> V_13 -> V_336 , & V_315 [ 8 ] ) ;
F_136 ( args -> V_13 -> V_337 , & V_315 [ 12 ] ) ;
F_136 ( args -> V_13 -> V_338 , & V_315 [ 16 ] ) ;
return 0 ;
}
static unsigned int F_142 ( struct V_314 * args , T_3 * V_315 )
{
F_102 ( L_32 ) ;
return 0 ;
}
static void F_143 ( T_3 * V_339 , const T_3 * V_340 , int V_341 , bool V_342 )
{
if ( V_342 ) {
memcpy ( V_339 , V_340 , 2 ) ;
memset ( V_339 + 2 , 0 , V_341 - 2 ) ;
} else {
memcpy ( V_339 , V_340 , V_341 ) ;
}
}
static unsigned int F_144 ( T_5 * V_102 , T_3 * V_4 , bool V_342 )
{
F_143 ( V_4 , V_343 , sizeof( V_343 ) , V_342 ) ;
if ( V_342 || F_145 ( V_102 ) )
V_4 [ 2 ] |= ( 1 << 2 ) ;
if ( ! V_342 && ! F_146 ( V_102 ) )
V_4 [ 12 ] |= ( 1 << 5 ) ;
return sizeof( V_343 ) ;
}
static unsigned int F_147 ( struct V_12 * V_13 , T_3 * V_4 ,
bool V_342 )
{
F_143 ( V_4 , V_344 , sizeof( V_344 ) , V_342 ) ;
if ( V_342 && ( V_13 -> V_16 & V_62 ) )
V_4 [ 2 ] |= ( 1 << 2 ) ;
return sizeof( V_344 ) ;
}
static unsigned int F_148 ( T_3 * V_4 , bool V_342 )
{
F_143 ( V_4 , V_345 , sizeof( V_345 ) ,
V_342 ) ;
return sizeof( V_345 ) ;
}
static int F_149 ( T_5 * V_102 )
{
unsigned char V_346 [ V_106 + 1 ] , V_347 [ V_108 + 1 ] ;
if ( ! V_348 )
return 0 ;
if ( ! F_150 ( V_102 ) )
return 0 ;
F_151 ( V_102 , V_346 , V_105 , sizeof( V_346 ) ) ;
F_151 ( V_102 , V_347 , V_107 , sizeof( V_347 ) ) ;
if ( strcmp ( V_346 , L_43 ) )
return 1 ;
if ( strcmp ( V_347 , L_44 ) )
return 1 ;
return 0 ;
}
static unsigned int F_152 ( struct V_314 * args , T_3 * V_315 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_151 = args -> V_57 -> V_241 , * V_349 = V_315 ;
const T_3 V_350 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_351 , V_352 ;
unsigned int V_353 , V_354 , V_355 ;
T_3 V_356 , V_243 = 0xff ;
T_5 V_242 ;
F_102 ( L_32 ) ;
V_355 = ( V_151 [ 0 ] == V_357 ) ;
V_353 = ! ( V_151 [ 1 ] & 0x8 ) ;
V_354 = V_151 [ 2 ] >> 6 ;
switch ( V_354 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_358;
default:
V_242 = 2 ;
V_243 = 6 ;
goto V_245;
}
if ( V_355 )
V_349 += 4 + ( V_353 ? 8 : 0 ) ;
else
V_349 += 8 + ( V_353 ? 8 : 0 ) ;
V_351 = V_151 [ 2 ] & 0x3f ;
V_352 = V_151 [ 3 ] ;
if ( V_352 && ( V_352 != V_359 ) ) {
V_242 = 3 ;
goto V_245;
}
switch( V_351 ) {
case V_360 :
V_349 += F_148 ( V_349 , V_354 == 1 ) ;
break;
case V_361 :
V_349 += F_144 ( args -> V_102 , V_349 , V_354 == 1 ) ;
break;
case V_362 :
V_349 += F_147 ( args -> V_13 , V_349 , V_354 == 1 ) ;
break;
case V_363 :
V_349 += F_148 ( V_349 , V_354 == 1 ) ;
V_349 += F_144 ( args -> V_102 , V_349 , V_354 == 1 ) ;
V_349 += F_147 ( args -> V_13 , V_349 , V_354 == 1 ) ;
break;
default:
V_242 = 2 ;
goto V_245;
}
V_356 = 0 ;
if ( F_149 ( args -> V_102 ) && ( V_13 -> V_16 & V_274 ) &&
( ! ( V_13 -> V_16 & V_364 ) || V_13 -> V_365 ) )
V_356 = 1 << 4 ;
if ( V_355 ) {
V_315 [ 0 ] = V_349 - V_315 - 1 ;
V_315 [ 2 ] |= V_356 ;
if ( V_353 ) {
V_315 [ 3 ] = sizeof( V_350 ) ;
memcpy ( V_315 + 4 , V_350 , sizeof( V_350 ) ) ;
}
} else {
unsigned int V_366 = V_349 - V_315 - 2 ;
V_315 [ 0 ] = V_366 >> 8 ;
V_315 [ 1 ] = V_366 ;
V_315 [ 3 ] |= V_356 ;
if ( V_353 ) {
V_315 [ 7 ] = sizeof( V_350 ) ;
memcpy ( V_315 + 8 , V_350 , sizeof( V_350 ) ) ;
}
}
return 0 ;
V_245:
F_28 ( V_13 , args -> V_57 , V_242 , V_243 ) ;
return 1 ;
V_358:
F_23 ( V_13 , args -> V_57 , V_74 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_153 ( struct V_314 * args , T_3 * V_315 )
{
struct V_12 * V_13 = args -> V_13 ;
T_4 V_367 = V_13 -> V_94 - 1 ;
T_8 V_223 ;
T_3 V_368 ;
T_5 V_369 ;
V_223 = F_84 ( V_13 -> V_102 ) ;
V_368 = F_132 ( V_13 -> V_102 ) ;
V_369 = F_154 ( V_13 -> V_102 , V_368 ) ;
F_102 ( L_32 ) ;
if ( args -> V_57 -> V_241 [ 0 ] == V_370 ) {
if ( V_367 >= 0xffffffffULL )
V_367 = 0xffffffff ;
V_315 [ 0 ] = V_367 >> ( 8 * 3 ) ;
V_315 [ 1 ] = V_367 >> ( 8 * 2 ) ;
V_315 [ 2 ] = V_367 >> ( 8 * 1 ) ;
V_315 [ 3 ] = V_367 ;
V_315 [ 4 ] = V_223 >> ( 8 * 3 ) ;
V_315 [ 5 ] = V_223 >> ( 8 * 2 ) ;
V_315 [ 6 ] = V_223 >> ( 8 * 1 ) ;
V_315 [ 7 ] = V_223 ;
} else {
V_315 [ 0 ] = V_367 >> ( 8 * 7 ) ;
V_315 [ 1 ] = V_367 >> ( 8 * 6 ) ;
V_315 [ 2 ] = V_367 >> ( 8 * 5 ) ;
V_315 [ 3 ] = V_367 >> ( 8 * 4 ) ;
V_315 [ 4 ] = V_367 >> ( 8 * 3 ) ;
V_315 [ 5 ] = V_367 >> ( 8 * 2 ) ;
V_315 [ 6 ] = V_367 >> ( 8 * 1 ) ;
V_315 [ 7 ] = V_367 ;
V_315 [ 8 ] = V_223 >> ( 8 * 3 ) ;
V_315 [ 9 ] = V_223 >> ( 8 * 2 ) ;
V_315 [ 10 ] = V_223 >> ( 8 * 1 ) ;
V_315 [ 11 ] = V_223 ;
V_315 [ 12 ] = 0 ;
V_315 [ 13 ] = V_368 ;
V_315 [ 14 ] = ( V_369 >> 8 ) & 0x3f ;
V_315 [ 15 ] = V_369 ;
if ( F_134 ( args -> V_102 ) &&
! ( V_13 -> V_22 & V_371 ) ) {
V_315 [ 14 ] |= 0x80 ;
if ( F_155 ( args -> V_102 ) &&
V_13 -> V_22 & V_372 ) {
F_156 ( V_13 , L_45 ) ;
V_315 [ 14 ] |= 0x40 ;
}
}
if ( F_124 ( args -> V_102 ) ||
args -> V_13 -> V_49 == V_51 )
V_315 [ 12 ] = ( 1 << 4 ) ;
}
return 0 ;
}
static unsigned int F_157 ( struct V_314 * args , T_3 * V_315 )
{
F_102 ( L_32 ) ;
V_315 [ 3 ] = 8 ;
return 0 ;
}
static void F_158 ( struct V_147 * V_148 )
{
if ( V_148 -> V_196 && ( ( V_148 -> V_196 & V_373 ) == 0 ) ) {
F_68 ( V_148 ) ;
}
F_111 ( V_148 ) ;
}
static inline int F_159 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_135 ) ;
}
static void F_160 ( struct V_147 * V_148 )
{
struct V_8 * V_9 = V_148 -> V_9 ;
struct V_56 * V_57 = V_148 -> V_151 ;
F_108 ( L_46 ) ;
memset ( V_57 -> V_66 , 0 , V_71 ) ;
#ifdef F_161
if ( V_9 -> V_75 -> V_374 )
V_9 -> V_75 -> V_374 ( V_9 , & V_148 -> V_68 ) ;
#endif
V_57 -> V_66 [ 0 ] = 0x70 ;
V_57 -> V_66 [ 2 ] = V_148 -> V_68 . V_164 >> 4 ;
F_162 ( V_148 ) ;
F_163 ( & V_148 -> V_375 , V_57 -> V_66 , V_71 ) ;
F_116 ( V_148 , & V_148 -> V_375 , 1 ) ;
V_148 -> V_300 = V_124 ;
memset ( & V_148 -> V_240 , 0 , V_148 -> V_13 -> V_376 ) ;
V_148 -> V_240 [ 0 ] = V_377 ;
V_148 -> V_240 [ 4 ] = V_71 ;
V_148 -> V_68 . V_16 |= V_247 | V_246 ;
V_148 -> V_68 . V_162 = V_378 ;
if ( F_159 ( V_9 ) ) {
V_148 -> V_68 . V_248 = V_379 ;
V_148 -> V_68 . V_164 |= V_380 ;
} else {
V_148 -> V_68 . V_248 = V_381 ;
V_148 -> V_68 . V_200 = V_71 ;
V_148 -> V_68 . V_201 = 0 ;
}
V_148 -> V_160 = V_71 ;
V_148 -> V_301 = F_158 ;
F_117 ( V_148 ) ;
F_108 ( L_34 ) ;
}
static void F_164 ( struct V_147 * V_148 )
{
struct V_56 * V_57 = V_148 -> V_151 ;
unsigned int V_196 = V_148 -> V_196 ;
F_102 ( L_47 , V_196 ) ;
if ( F_20 ( V_148 -> V_9 -> V_75 -> V_195 &&
( V_196 || V_148 -> V_16 & V_294 ) ) ) {
if ( ! ( V_148 -> V_16 & V_294 ) ) {
F_68 ( V_148 ) ;
}
if ( V_148 -> V_240 [ 0 ] == V_382 && V_148 -> V_13 -> V_29 )
V_148 -> V_13 -> V_29 -> V_383 = 0 ;
V_148 -> V_151 -> V_63 = V_65 ;
F_111 ( V_148 ) ;
return;
}
if ( F_20 ( V_196 & V_373 ) ) {
V_57 -> V_63 = V_65 ;
F_160 ( V_148 ) ;
return;
} else if ( F_20 ( V_196 ) ) {
F_68 ( V_148 ) ;
} else {
T_3 * V_151 = V_57 -> V_241 ;
if ( ( V_151 [ 0 ] == V_384 ) && ( ( V_151 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_16 ;
T_3 * V_4 ;
V_4 = F_118 ( V_57 , true , & V_16 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_120 ( V_57 , true , & V_16 ) ;
}
V_57 -> V_63 = V_260 ;
}
F_111 ( V_148 ) ;
}
static unsigned int F_165 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_12 * V_13 = V_148 -> V_13 ;
int V_385 = ( V_157 -> V_297 == V_125 ) ;
int V_386 = ! V_385 && ( V_13 -> V_16 & V_364 ) ;
unsigned int V_160 ;
memset ( V_148 -> V_240 , 0 , V_13 -> V_376 ) ;
memcpy ( V_148 -> V_240 , V_157 -> V_241 , V_157 -> V_244 ) ;
V_148 -> V_301 = F_164 ;
V_148 -> V_68 . V_16 |= V_247 | V_246 ;
if ( V_157 -> V_297 == V_298 ) {
V_148 -> V_68 . V_16 |= V_286 ;
F_108 ( L_48 ) ;
}
V_148 -> V_68 . V_162 = V_378 ;
F_63 ( V_148 ) ;
if ( ! V_385 && ! V_386 && F_166 ( V_148 ) )
V_386 = 1 ;
V_160 = F_87 ( F_167 ( V_148 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_160 & 0x1 )
V_160 ++ ;
V_148 -> V_68 . V_200 = ( V_160 & 0xFF ) ;
V_148 -> V_68 . V_201 = ( V_160 >> 8 ) ;
if ( V_385 )
V_148 -> V_68 . V_248 = V_387 ;
else if ( V_386 )
V_148 -> V_68 . V_248 = V_381 ;
else {
V_148 -> V_68 . V_248 = V_379 ;
V_148 -> V_68 . V_164 |= V_380 ;
if ( ( V_13 -> V_16 & V_388 ) &&
( V_157 -> V_297 != V_298 ) )
V_148 -> V_68 . V_164 |= V_389 ;
}
return 0 ;
}
static struct V_12 * F_168 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_169 ( V_9 ) ) {
if ( F_75 ( V_43 < F_170 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_75 ( V_43 < V_9 -> V_390 ) )
return & V_9 -> V_391 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_92 ( struct V_8 * V_9 ,
const struct V_28 * V_111 )
{
int V_43 ;
if ( ! F_169 ( V_9 ) ) {
if ( F_20 ( V_111 -> V_392 || V_111 -> V_393 ) )
return NULL ;
V_43 = V_111 -> V_102 ;
} else {
if ( F_20 ( V_111 -> V_102 || V_111 -> V_393 ) )
return NULL ;
V_43 = V_111 -> V_392 ;
}
return F_168 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_14 ( struct V_8 * V_9 , const struct V_28 * V_111 )
{
struct V_12 * V_13 = F_92 ( V_9 , V_111 ) ;
if ( F_20 ( ! V_13 || ! F_95 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_171 ( T_3 V_394 )
{
switch( ( V_394 & 0x1e ) >> 1 ) {
case 3 :
return V_249 ;
case 6 :
case 10 :
case 11 :
return V_395 ;
case 4 :
case 5 :
return V_396 ;
case 12 :
return V_397 ;
case 0 :
case 1 :
case 8 :
case 9 :
case 7 :
case 15 :
default:
break;
}
return V_398 ;
}
static unsigned int F_172 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & ( V_148 -> V_68 ) ;
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_12 * V_13 = V_148 -> V_13 ;
const T_3 * V_240 = V_157 -> V_241 ;
T_5 V_242 ;
if ( ( V_68 -> V_248 = F_171 ( V_240 [ 1 ] ) ) == V_398 ) {
V_242 = 1 ;
goto V_245;
}
V_68 -> V_16 |= V_251 ;
if ( V_240 [ 0 ] == V_126 ) {
if ( V_240 [ 1 ] & 0x01 ) {
V_68 -> V_399 = V_240 [ 3 ] ;
V_68 -> V_203 = V_240 [ 5 ] ;
V_68 -> V_204 = V_240 [ 7 ] ;
V_68 -> V_205 = V_240 [ 9 ] ;
V_68 -> V_206 = V_240 [ 11 ] ;
V_68 -> V_16 |= V_202 ;
} else
V_68 -> V_16 &= ~ V_202 ;
V_68 -> V_164 = V_240 [ 4 ] ;
V_68 -> V_198 = V_240 [ 6 ] ;
V_68 -> V_199 = V_240 [ 8 ] ;
V_68 -> V_200 = V_240 [ 10 ] ;
V_68 -> V_201 = V_240 [ 12 ] ;
V_68 -> V_1 = V_240 [ 13 ] ;
V_68 -> V_162 = V_240 [ 14 ] ;
} else {
V_68 -> V_16 &= ~ V_202 ;
V_68 -> V_164 = V_240 [ 3 ] ;
V_68 -> V_198 = V_240 [ 4 ] ;
V_68 -> V_199 = V_240 [ 5 ] ;
V_68 -> V_200 = V_240 [ 6 ] ;
V_68 -> V_201 = V_240 [ 7 ] ;
V_68 -> V_1 = V_240 [ 8 ] ;
V_68 -> V_162 = V_240 [ 9 ] ;
}
if ( V_68 -> V_248 == V_397 )
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_1 = V_13 -> V_43 ?
V_68 -> V_1 | V_400 : V_68 -> V_1 & ~ V_400 ;
switch ( V_68 -> V_162 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
if ( V_68 -> V_248 != V_396 || V_68 -> V_198 != 1 ) {
V_242 = 1 ;
goto V_245;
}
V_148 -> V_405 = F_64 ( V_157 ) ;
break;
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_253 :
case V_275 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
V_148 -> V_405 = V_157 -> V_1 -> V_223 ;
break;
default:
V_148 -> V_405 = V_122 ;
}
V_68 -> V_16 |= V_247 | V_246 ;
if ( V_157 -> V_297 == V_298 )
V_68 -> V_16 |= V_286 ;
V_148 -> V_16 |= V_432 | V_433 ;
F_63 ( V_148 ) ;
if ( V_68 -> V_248 == V_395 && V_13 -> V_434 == 0 ) {
V_242 = 1 ;
goto V_245;
}
if ( ( V_240 [ 1 ] & 0xe0 ) && ! F_173 ( V_68 ) ) {
V_242 = 1 ;
goto V_245;
}
if ( F_173 ( V_68 ) ) {
unsigned int V_365 = 1 << ( V_240 [ 1 ] >> 5 ) ;
if ( V_365 != V_13 -> V_365 )
F_72 ( V_13 , L_49 ,
V_365 ) ;
}
if ( V_68 -> V_162 == V_435 &&
V_68 -> V_164 == V_436 ) {
V_242 = ( V_240 [ 0 ] == V_126 ) ? 4 : 3 ;
goto V_245;
}
if ( V_68 -> V_162 >= 0x5C && V_68 -> V_162 <= 0x5F && ! V_437 ) {
V_242 = ( V_240 [ 0 ] == V_126 ) ? 14 : 9 ;
goto V_245;
}
return 0 ;
V_245:
F_28 ( V_13 , V_157 , V_242 , 0xff ) ;
return 1 ;
}
static unsigned int F_174 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_12 * V_13 = V_148 -> V_13 ;
const T_3 * V_240 = V_157 -> V_241 ;
T_4 V_207 ;
T_8 V_269 ;
T_8 V_438 ;
void * V_4 ;
T_5 V_242 ;
T_3 V_243 = 0xff ;
if ( F_20 ( ! V_13 -> V_434 ) )
goto V_439;
if ( F_20 ( V_157 -> V_244 < 16 ) ) {
V_242 = 15 ;
goto V_245;
}
F_104 ( V_240 , & V_207 , & V_269 ) ;
if ( F_20 ( ! ( V_240 [ 1 ] & 0x8 ) ) ) {
V_242 = 1 ;
V_243 = 3 ;
goto V_245;
}
if ( ! F_62 ( V_157 ) )
goto V_440;
V_4 = F_175 ( F_176 ( F_61 ( V_157 ) ) ) ;
V_438 = F_177 ( V_4 , 512 , V_207 , V_269 ) ;
if ( F_96 ( V_13 ) && F_178 ( V_13 ) ) {
V_68 -> V_248 = V_397 ;
V_68 -> V_162 = V_441 ;
V_68 -> V_203 = V_442 & 0x1f ;
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_399 = ( V_438 / 512 ) >> 8 ;
V_68 -> V_164 = V_438 / 512 ;
V_68 -> V_443 = 1 ;
} else {
V_68 -> V_248 = V_395 ;
V_68 -> V_399 = 0 ;
V_68 -> V_164 = V_444 ;
V_68 -> V_203 = ( V_438 / 512 ) >> 8 ;
V_68 -> V_198 = V_438 / 512 ;
V_68 -> V_162 = V_445 ;
}
V_68 -> V_16 |= V_247 | V_246 | V_202 |
V_286 ;
F_63 ( V_148 ) ;
return 0 ;
V_245:
F_28 ( V_13 , V_157 , V_242 , V_243 ) ;
return 1 ;
V_440:
F_23 ( V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
V_439:
F_23 ( V_13 , V_157 , V_74 , 0x20 , 0x0 ) ;
return 1 ;
}
static void F_179 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_446 V_447 ;
unsigned long V_16 ;
unsigned int V_448 = 0 ;
F_180 ( & V_447 , F_61 ( V_157 ) , F_62 ( V_157 ) ,
V_449 | V_450 ) ;
F_181 ( V_16 ) ;
while ( F_182 ( & V_447 ) ) {
unsigned int V_451 = 0 ;
if ( V_448 == 0 ) {
char * V_318 ;
T_8 V_452 ;
T_4 V_453 , V_454 ;
T_5 V_455 ;
V_318 = V_447 . V_456 ;
V_452 = F_183 ( & V_318 [ 0 ] ) ;
V_455 = F_184 ( & V_318 [ 4 ] ) ;
V_453 = F_185 ( & V_318 [ 8 ] ) ;
V_454 = F_185 ( & V_318 [ 16 ] ) ;
F_136 ( V_452 , & V_318 [ 0 ] ) ;
V_318 [ 4 ] = V_455 & 0xf ;
F_135 ( V_453 , & V_318 [ 8 ] ) ;
F_135 ( V_454 , & V_318 [ 16 ] ) ;
V_451 += 64 ;
V_448 += 64 ;
}
while ( V_451 < V_447 . V_457 ) {
char * V_458 ;
T_3 V_459 , type , V_460 , V_461 ;
T_4 V_438 , V_462 , V_463 ;
V_458 = V_447 . V_456 + V_451 ;
type = V_458 [ 0 ] & 0xf ;
V_459 = ( V_458 [ 1 ] >> 4 ) & 0xf ;
V_460 = ( V_458 [ 1 ] & 2 ) ;
V_461 = ( V_458 [ 1 ] & 1 ) ;
V_438 = F_185 ( & V_458 [ 8 ] ) ;
V_462 = F_185 ( & V_458 [ 16 ] ) ;
V_463 = F_185 ( & V_458 [ 24 ] ) ;
V_458 [ 0 ] = type ;
V_458 [ 1 ] = ( V_459 << 4 ) | V_460 | V_461 ;
F_135 ( V_438 , & V_458 [ 8 ] ) ;
F_135 ( V_462 , & V_458 [ 16 ] ) ;
F_135 ( V_463 , & V_458 [ 24 ] ) ;
F_186 ( V_451 + 64 > V_447 . V_457 ) ;
V_451 += 64 ;
V_448 += 64 ;
}
}
F_187 ( & V_447 ) ;
F_188 ( V_16 ) ;
F_114 ( V_148 ) ;
}
static unsigned int F_189 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_56 * V_157 = V_148 -> V_151 ;
const T_3 * V_240 = V_157 -> V_241 ;
T_5 V_276 , V_242 = ( T_5 ) - 1 ;
T_3 V_464 , V_465 , V_243 = 0xff ;
T_4 V_207 ;
T_8 V_269 ;
if ( F_20 ( V_157 -> V_244 < 16 ) ) {
F_72 ( V_148 -> V_13 , L_50 ,
V_157 -> V_244 ) ;
V_242 = 15 ;
goto V_245;
}
F_104 ( V_240 , & V_207 , & V_269 ) ;
if ( V_269 != F_64 ( V_157 ) ) {
F_72 ( V_148 -> V_13 , L_51 ,
V_269 , F_64 ( V_157 ) ) ;
goto V_440;
}
V_464 = V_240 [ 1 ] & 0x1f ;
if ( V_464 != V_466 ) {
F_72 ( V_148 -> V_13 , L_52 , V_464 ) ;
V_242 = 1 ;
goto V_245;
}
if ( ( V_269 / 512 ) > 0xffff || V_269 < 512 || ( V_269 % 512 ) ) {
F_72 ( V_148 -> V_13 , L_53 , V_269 ) ;
goto V_440;
}
V_276 = V_269 / 512 ;
V_465 = V_240 [ 14 ] ;
if ( F_96 ( V_148 -> V_13 ) &&
F_190 ( V_148 -> V_13 ) ) {
V_68 -> V_248 = V_397 ;
V_68 -> V_162 = V_467 ;
V_68 -> V_203 = V_468 & 0x1f ;
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_164 = V_276 & 0xff ;
V_68 -> V_399 = ( V_276 >> 8 ) & 0xff ;
V_68 -> V_443 = V_469 ;
} else {
V_68 -> V_162 = V_470 ;
V_68 -> V_164 = V_469 ;
V_68 -> V_248 = V_395 ;
V_68 -> V_399 = V_465 ;
V_68 -> V_203 = ( V_276 >> 8 ) & 0xff ;
V_68 -> V_198 = V_276 & 0xff ;
}
V_68 -> V_1 = V_252 ;
V_68 -> V_201 = ( V_207 >> 16 ) & 0xff ;
V_68 -> V_200 = ( V_207 >> 8 ) & 0xff ;
V_68 -> V_199 = V_207 & 0xff ;
V_68 -> V_206 = ( V_207 >> 40 ) & 0xff ;
V_68 -> V_205 = ( V_207 >> 32 ) & 0xff ;
V_68 -> V_204 = ( V_207 >> 24 ) & 0xff ;
V_68 -> V_16 |= V_247 | V_246 | V_202 ;
V_148 -> V_16 |= V_432 ;
F_63 ( V_148 ) ;
V_148 -> V_301 = F_179 ;
return 0 ;
V_245:
F_28 ( V_148 -> V_13 , V_157 , V_242 , V_243 ) ;
return 1 ;
V_440:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
}
static unsigned int F_191 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_12 * V_13 = V_148 -> V_13 ;
const T_3 * V_240 = V_157 -> V_241 ;
T_3 V_471 , V_464 ;
T_4 V_207 ;
T_8 V_269 ;
T_5 V_242 = ( T_5 ) - 1 ;
if ( F_20 ( V_157 -> V_244 < 16 ) ) {
V_242 = 15 ;
goto V_245;
}
V_464 = V_240 [ 1 ] & 0x1f ;
if ( ( V_464 != V_472 ) && ( V_464 != V_473 ) &&
( V_464 != V_474 ) && ( V_464 != V_475 ) ) {
V_242 = 1 ;
goto V_245;
}
F_104 ( V_240 , & V_207 , & V_269 ) ;
if ( V_269 ) {
goto V_440;
}
if ( V_207 > V_13 -> V_94 )
goto V_273;
V_471 = V_240 [ 14 ] & 0x1 ;
if ( F_96 ( V_148 -> V_13 ) &&
F_192 ( V_148 -> V_13 ) ) {
V_68 -> V_248 = V_397 ;
V_68 -> V_162 = V_476 ;
V_68 -> V_203 = V_477 ;
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_443 = V_464 | ( V_471 & 0x1 ) << 8 ;
} else {
V_68 -> V_248 = V_249 ;
V_68 -> V_162 = V_478 ;
V_68 -> V_164 = V_464 ;
V_68 -> V_399 = V_471 & 0x1 ;
}
V_68 -> V_201 = ( V_207 >> 16 ) & 0xff ;
V_68 -> V_200 = ( V_207 >> 8 ) & 0xff ;
V_68 -> V_199 = V_207 & 0xff ;
V_68 -> V_206 = ( V_207 >> 40 ) & 0xff ;
V_68 -> V_205 = ( V_207 >> 32 ) & 0xff ;
V_68 -> V_204 = ( V_207 >> 24 ) & 0xff ;
V_68 -> V_1 = V_252 ;
V_68 -> V_16 |= V_247 | V_246 | V_202 ;
return 0 ;
V_245:
F_28 ( V_148 -> V_13 , V_157 , V_242 , 0xff ) ;
return 1 ;
V_273:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x21 , 0x00 ) ;
return 1 ;
V_440:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
}
static int F_193 ( struct V_147 * V_148 ,
const T_3 * V_4 , int V_45 , T_5 * V_242 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_12 * V_13 = V_148 -> V_13 ;
char V_479 [ V_480 ] ;
T_3 V_481 ;
int V_183 ;
if ( V_45 != V_480 - 2 ) {
if ( V_45 < V_480 - 2 )
* V_242 = V_45 ;
else
* V_242 = V_480 - 2 ;
return - V_20 ;
}
V_481 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_144 ( V_13 -> V_102 , V_479 , false ) ;
for ( V_183 = 0 ; V_183 < V_480 - 2 ; V_183 ++ ) {
if ( V_183 == 0 )
continue;
if ( V_479 [ V_183 + 2 ] != V_4 [ V_183 ] ) {
* V_242 = V_183 ;
return - V_20 ;
}
}
V_68 -> V_16 |= V_246 | V_247 ;
V_68 -> V_248 = V_249 ;
V_68 -> V_198 = 0 ;
V_68 -> V_162 = V_435 ;
V_68 -> V_164 = V_481 ? V_482 : V_483 ;
return 0 ;
}
static int F_194 ( struct V_147 * V_148 ,
const T_3 * V_4 , int V_45 , T_5 * V_242 )
{
struct V_12 * V_13 = V_148 -> V_13 ;
char V_479 [ V_484 ] ;
T_3 V_61 ;
int V_183 ;
if ( V_45 != V_484 - 2 ) {
if ( V_45 < V_484 - 2 )
* V_242 = V_45 ;
else
* V_242 = V_484 - 2 ;
return - V_20 ;
}
V_61 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_147 ( V_13 , V_479 , false ) ;
for ( V_183 = 0 ; V_183 < V_484 - 2 ; V_183 ++ ) {
if ( V_183 == 0 )
continue;
if ( V_479 [ 2 + V_183 ] != V_4 [ V_183 ] ) {
* V_242 = V_183 ;
return - V_20 ;
}
}
if ( V_61 & ( 1 << 2 ) )
V_13 -> V_16 |= V_62 ;
else
V_13 -> V_16 &= ~ V_62 ;
V_148 -> V_151 -> V_63 = V_260 ;
V_148 -> V_151 -> V_89 ( V_148 -> V_151 ) ;
return 0 ;
}
static unsigned int F_195 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
const T_3 * V_240 = V_157 -> V_241 ;
const T_3 * V_349 ;
T_3 V_351 , V_352 ;
unsigned V_355 , V_485 , V_486 , V_487 ;
int V_45 ;
T_5 V_242 = ( T_5 ) - 1 ;
T_3 V_243 = 0xff ;
F_102 ( L_32 ) ;
V_355 = ( V_240 [ 0 ] == V_488 ) ;
if ( V_355 ) {
if ( V_157 -> V_244 < 5 ) {
V_242 = 4 ;
goto V_245;
}
V_45 = V_240 [ 4 ] ;
V_486 = 4 ;
} else {
if ( V_157 -> V_244 < 9 ) {
V_242 = 8 ;
goto V_245;
}
V_45 = ( V_240 [ 7 ] << 8 ) + V_240 [ 8 ] ;
V_486 = 8 ;
}
if ( ( V_240 [ 1 ] & 0x11 ) != 0x10 ) {
V_242 = 1 ;
V_243 = ( V_240 [ 1 ] & 0x01 ) ? 1 : 5 ;
goto V_245;
}
if ( ! F_62 ( V_157 ) || F_61 ( V_157 ) -> V_457 < V_45 )
goto V_440;
V_349 = F_175 ( F_176 ( F_61 ( V_157 ) ) ) ;
if ( V_45 < V_486 )
goto V_440;
if ( V_355 )
V_487 = V_349 [ 3 ] ;
else
V_487 = ( V_349 [ 6 ] << 8 ) + V_349 [ 7 ] ;
V_45 -= V_486 ;
V_349 += V_486 ;
if ( V_45 < V_487 )
goto V_440;
if ( V_487 != 0 && V_487 != 8 ) {
V_242 = ( V_355 ) ? 3 : 6 ;
V_242 += V_487 + V_486 ;
goto V_489;
}
V_45 -= V_487 ;
V_349 += V_487 ;
if ( V_45 == 0 )
goto V_257;
V_351 = V_349 [ 0 ] & 0x3f ;
if ( V_349 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_440;
V_352 = V_349 [ 1 ] ;
V_485 = ( V_349 [ 2 ] << 8 ) | V_349 [ 3 ] ;
V_349 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_440;
V_352 = 0 ;
V_485 = V_349 [ 1 ] ;
V_349 += 2 ;
V_45 -= 2 ;
}
if ( V_352 && ( V_352 != V_359 ) ) {
V_242 = ( V_349 [ 0 ] & 0x40 ) ? 1 : 0 ;
V_242 += V_486 + V_487 ;
goto V_489;
}
if ( V_485 > V_45 )
goto V_440;
switch ( V_351 ) {
case V_361 :
if ( F_193 ( V_148 , V_349 , V_485 , & V_242 ) < 0 ) {
V_242 += V_486 + V_487 ;
goto V_489;
}
break;
case V_362 :
if ( F_194 ( V_148 , V_349 , V_485 , & V_242 ) < 0 ) {
V_242 += V_486 + V_487 ;
goto V_489;
}
break;
default:
V_242 = V_487 + V_486 ;
goto V_489;
}
if ( V_45 > V_485 )
goto V_489;
return 0 ;
V_245:
F_28 ( V_148 -> V_13 , V_157 , V_242 , V_243 ) ;
return 1 ;
V_489:
F_30 ( V_148 -> V_13 , V_157 , V_242 ) ;
return 1 ;
V_440:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
V_257:
V_157 -> V_63 = V_260 ;
return 1 ;
}
static inline T_9 F_196 ( struct V_12 * V_13 , T_3 V_57 )
{
switch ( V_57 ) {
case V_289 :
case V_287 :
case V_290 :
case V_284 :
case V_283 :
case V_285 :
return F_109 ;
case V_490 :
return F_174 ;
case V_491 :
if ( F_197 ( V_13 ) )
return F_100 ;
break;
case V_270 :
case V_271 :
return F_105 ;
case V_293 :
case V_126 :
return F_172 ;
case V_488 :
case V_492 :
return F_195 ;
break;
case V_493 :
return F_189 ;
case V_494 :
return F_191 ;
case V_495 :
return F_98 ;
}
return NULL ;
}
static inline void F_198 ( struct V_8 * V_9 ,
struct V_56 * V_57 )
{
#ifdef F_199
struct V_28 * V_111 = V_57 -> V_1 ;
F_108 ( L_54 ,
V_9 -> V_197 ,
V_111 -> V_392 , V_111 -> V_102 , V_111 -> V_393 ,
V_57 -> V_241 ) ;
#endif
}
static inline int F_200 ( struct V_56 * V_157 ,
struct V_12 * V_13 )
{
T_3 V_496 = V_157 -> V_241 [ 0 ] ;
T_9 V_295 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 || V_13 -> V_49 == V_51 ) {
if ( F_20 ( ! V_157 -> V_244 || V_157 -> V_244 > V_13 -> V_376 ) )
goto V_497;
V_295 = F_196 ( V_13 , V_496 ) ;
} else {
if ( F_20 ( ! V_157 -> V_244 ) )
goto V_497;
V_295 = NULL ;
if ( F_75 ( ( V_496 != V_126 ) || ! V_498 ) ) {
int V_45 = F_201 ( V_496 ) ;
if ( F_20 ( V_45 > V_157 -> V_244 || V_45 > V_13 -> V_376 ) )
goto V_497;
V_295 = F_165 ;
} else {
if ( F_20 ( V_157 -> V_244 > 16 ) )
goto V_497;
V_295 = F_196 ( V_13 , V_496 ) ;
}
}
if ( V_295 )
V_33 = F_115 ( V_13 , V_157 , V_295 ) ;
else
F_202 ( V_13 , V_157 ) ;
return V_33 ;
V_497:
F_108 ( L_55 ,
V_157 -> V_244 , V_496 , V_13 -> V_376 ) ;
V_157 -> V_63 = V_305 << 16 ;
V_157 -> V_89 ( V_157 ) ;
return 0 ;
}
int F_203 ( struct V_6 * V_7 , struct V_56 * V_57 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_111 = V_57 -> V_1 ;
int V_33 = 0 ;
unsigned long V_499 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_499 ) ;
F_198 ( V_9 , V_57 ) ;
V_13 = F_14 ( V_9 , V_111 ) ;
if ( F_75 ( V_13 ) )
V_33 = F_200 ( V_57 , V_13 ) ;
else {
V_57 -> V_63 = ( V_500 << 16 ) ;
V_57 -> V_89 ( V_57 ) ;
}
F_9 ( V_9 -> V_21 , V_499 ) ;
return V_33 ;
}
void F_202 ( struct V_12 * V_13 , struct V_56 * V_57 )
{
struct V_314 args ;
const T_3 * V_151 = V_57 -> V_241 ;
T_3 V_501 ;
args . V_13 = V_13 ;
args . V_102 = V_13 -> V_102 ;
args . V_57 = V_57 ;
args . F_112 = V_57 -> V_89 ;
switch( V_151 [ 0 ] ) {
case V_502 :
F_37 ( V_13 , V_57 , 0 ) ;
break;
case V_384 :
if ( V_151 [ 1 ] & 2 )
F_37 ( V_13 , V_57 , 1 ) ;
else if ( ( V_151 [ 1 ] & 1 ) == 0 )
F_204 ( & args , F_122 ) ;
else switch ( V_151 [ 2 ] ) {
case 0x00 :
F_204 ( & args , F_125 ) ;
break;
case 0x80 :
F_204 ( & args , F_126 ) ;
break;
case 0x83 :
F_204 ( & args , F_127 ) ;
break;
case 0x89 :
F_204 ( & args , F_129 ) ;
break;
case 0xb0 :
F_204 ( & args , F_131 ) ;
break;
case 0xb1 :
F_204 ( & args , F_137 ) ;
break;
case 0xb2 :
F_204 ( & args , F_140 ) ;
break;
case 0xb6 :
if ( V_13 -> V_16 & V_324 ) {
F_204 ( & args , F_141 ) ;
break;
}
default:
F_37 ( V_13 , V_57 , 2 ) ;
break;
}
break;
case V_357 :
case V_503 :
F_204 ( & args , F_152 ) ;
break;
case V_370 :
F_204 ( & args , F_153 ) ;
break;
case V_504 :
if ( ( V_151 [ 1 ] & 0x1f ) == V_505 )
F_204 ( & args , F_153 ) ;
else
F_37 ( V_13 , V_57 , 1 ) ;
break;
case V_506 :
F_204 ( & args , F_157 ) ;
break;
case V_377 :
F_23 ( V_13 , V_57 , 0 , 0 , 0 ) ;
V_57 -> V_63 = ( V_64 << 24 ) ;
V_57 -> V_89 ( V_57 ) ;
break;
case V_491 :
case V_507 :
case V_508 :
case V_509 :
case V_510 :
F_204 ( & args , F_142 ) ;
break;
case V_511 :
V_501 = V_151 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_501 == 0x4 ) && ( ! V_151 [ 3 ] ) && ( ! V_151 [ 4 ] ) )
F_204 ( & args , F_142 ) ;
else
F_37 ( V_13 , V_57 , 1 ) ;
break;
default:
F_23 ( V_13 , V_57 , V_74 , 0x20 , 0x0 ) ;
V_57 -> V_89 ( V_57 ) ;
break;
}
}
int F_205 ( struct V_512 * V_34 , struct V_513 * V_514 )
{
int V_183 , V_33 ;
for ( V_183 = 0 ; V_183 < V_34 -> V_515 ; V_183 ++ ) {
struct V_8 * V_9 = V_34 -> V_516 [ V_183 ] ;
struct V_6 * V_7 ;
V_33 = - V_121 ;
V_7 = F_206 ( V_514 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_517;
V_7 -> V_518 = 1 ;
* (struct V_8 * * ) & V_7 -> V_519 [ 0 ] = V_9 ;
V_9 -> V_520 = V_7 ;
V_7 -> V_521 = V_522 ;
V_7 -> V_523 = V_9 -> V_197 ;
V_7 -> V_524 = 16 ;
V_7 -> V_525 = 1 ;
V_7 -> V_526 = 1 ;
V_7 -> V_527 = 16 ;
V_7 -> V_211 = 1 ;
V_7 -> V_528 = 1 ;
V_33 = F_207 ( V_9 -> V_520 ,
& V_9 -> V_529 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_530;
}
return 0 ;
V_530:
F_208 ( V_34 -> V_516 [ V_183 ] -> V_520 ) ;
V_517:
while ( -- V_183 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_516 [ V_183 ] -> V_520 ;
F_209 ( V_7 ) ;
F_208 ( V_7 ) ;
}
return V_33 ;
}
void F_210 ( struct V_8 * V_9 , int V_531 )
{
int V_532 = 5 ;
struct V_12 * V_533 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_534:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_392 = 0 , V_102 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_211 ( V_11 ) )
V_102 = V_13 -> V_43 ;
else
V_392 = V_11 -> V_535 ;
V_29 = F_212 ( V_9 -> V_520 , V_392 , V_102 , 0 ,
NULL ) ;
if ( ! F_213 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_214 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_536;
}
}
V_536:
if ( ! V_11 )
return;
if ( V_531 ) {
if ( V_13 != V_533 ) {
F_215 ( 100 ) ;
V_533 = V_13 ;
goto V_534;
}
if ( -- V_532 ) {
F_215 ( 100 ) ;
goto V_534;
}
F_216 ( V_9 ,
L_56 ) ;
}
F_217 ( V_537 , & V_9 -> V_538 ,
F_218 ( V_128 ) ) ;
}
int F_219 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_220 ( V_13 -> V_29 , V_539 ) ;
return 1 ;
}
return 0 ;
}
static void F_221 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_222 ( & V_9 -> V_520 -> V_540 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_223 ( V_29 ) == 0 ) {
F_220 ( V_29 , V_539 ) ;
} else {
F_186 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_224 ( & V_9 -> V_520 -> V_540 ) ;
if ( V_29 ) {
F_156 ( V_13 , L_57 ,
F_225 ( & V_29 -> V_541 ) ) ;
F_226 ( V_29 ) ;
F_214 ( V_29 ) ;
}
}
static void F_227 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_542 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_542 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_228 ( V_13 ) )
F_229 ( V_13 ) ;
F_221 ( V_13 ) ;
}
}
void F_230 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_231 ( V_13 -> V_29 , V_229 ,
V_543 ) ;
}
void F_232 ( struct V_544 * V_545 )
{
struct V_8 * V_9 =
F_233 ( V_545 , struct V_8 , V_538 . V_545 ) ;
int V_183 ;
if ( V_9 -> V_39 & V_546 ) {
F_108 ( L_58 ) ;
return;
}
#ifdef F_234
while ( V_547 )
F_215 ( 10 ) ;
#endif
F_108 ( L_32 ) ;
F_222 ( & V_9 -> V_548 ) ;
F_227 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_391 )
for ( V_183 = 0 ; V_183 < V_549 ; V_183 ++ )
F_227 ( & V_9 -> V_391 [ V_183 ] ) ;
F_210 ( V_9 , 0 ) ;
F_224 ( & V_9 -> V_548 ) ;
F_108 ( L_34 ) ;
}
int F_235 ( struct V_6 * V_7 , unsigned int V_392 ,
unsigned int V_102 , T_4 V_393 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_75 -> V_195 )
return - V_24 ;
if ( V_393 != V_550 && V_393 )
return - V_20 ;
if ( ! F_169 ( V_9 ) ) {
if ( V_392 != V_550 && V_392 )
return - V_20 ;
V_43 = V_102 ;
} else {
if ( V_102 != V_550 && V_102 )
return - V_20 ;
V_43 = V_392 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_550 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_551 * V_552 = & V_11 -> V_52 ;
V_552 -> V_553 |= V_554 ;
V_552 -> V_97 |= V_98 ;
}
} else {
struct V_12 * V_13 = F_168 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_551 * V_552 = & V_13 -> V_11 -> V_52 ;
V_552 -> V_553 |= 1 << V_13 -> V_43 ;
V_552 -> V_97 |= V_98 ;
} else
V_33 = - V_20 ;
}
if ( V_33 == 0 ) {
F_8 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_41 ( V_9 ) ;
} else
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
}
void F_236 ( struct V_544 * V_545 )
{
struct V_8 * V_9 =
F_233 ( V_545 , struct V_8 , V_555 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_222 ( & V_9 -> V_548 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_223 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_237 ( & ( V_29 -> V_541 ) ) ;
F_214 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_224 ( & V_9 -> V_548 ) ;
}
struct V_8 * F_238 ( struct V_512 * V_34 ,
struct V_556 * V_557 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_239 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_558 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_559 = V_557 -> V_559 ;
V_9 -> V_560 = V_557 -> V_560 ;
V_9 -> V_561 = V_557 -> V_561 ;
V_9 -> V_16 |= V_557 -> V_16 ;
V_9 -> V_75 = V_557 -> V_562 ;
V_9 -> V_563 = V_564 ;
return V_9 ;
}
int F_240 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_75 -> V_195 )
V_9 -> V_39 &= ~ V_565 ;
return 0 ;
}
void F_241 ( struct V_8 * V_9 )
{
}
void F_242 ( struct V_8 * V_9 )
{
F_243 ( V_9 ) ;
}
int F_244 ( struct V_8 * V_9 )
{
return F_245 ( V_9 ) ;
}
int F_246 ( struct V_8 * V_9 )
{
int V_33 = V_9 -> V_75 -> V_566 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_197 = F_247 ( & V_567 ) ;
return 0 ;
}
void F_248 ( struct V_8 * V_9 )
{
if ( V_9 -> V_75 -> V_568 )
V_9 -> V_75 -> V_568 ( V_9 ) ;
F_52 ( V_9 ) ;
}
int F_249 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_73 ( V_29 ) ;
F_78 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_250 ( struct V_56 * V_57 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_198 ( V_9 , V_57 ) ;
if ( F_75 ( F_95 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_200 ( V_57 , V_9 -> V_11 . V_1 ) ;
else {
V_57 -> V_63 = ( V_500 << 16 ) ;
V_57 -> V_89 ( V_57 ) ;
}
return V_33 ;
}
int F_251 ( struct V_8 * V_9 )
{
unsigned int V_569 = V_9 -> V_34 -> V_570 ;
unsigned int V_183 , V_150 ;
for ( V_183 = 0 , V_150 = V_9 -> V_571 + 1 ; V_183 < V_569 ; V_183 ++ , V_150 ++ ) {
V_150 = V_150 < V_569 ? V_150 : 0 ;
if ( V_150 == V_572 )
continue;
if ( ! F_252 ( V_150 , & V_9 -> V_573 ) ) {
V_9 -> V_571 = V_150 ;
return V_150 ;
}
}
return - 1 ;
}
void F_253 ( unsigned int V_150 , struct V_8 * V_9 )
{
F_254 ( V_150 , & V_9 -> V_573 ) ;
}
