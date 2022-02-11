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
V_129 [ 7 ] = 0 ;
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
}
static int F_74 ( struct V_149 * V_212 )
{
if ( F_75 ( V_212 -> V_213 != V_214 ) )
return 0 ;
if ( ! F_76 ( V_212 ) || F_77 ( F_78 ( V_212 ) ) )
return 0 ;
return F_79 ( V_212 -> V_57 [ 0 ] ) == V_215 ;
}
static int F_80 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_216 * V_217 = V_29 -> V_216 ;
if ( ! F_81 ( V_13 -> V_102 ) )
V_13 -> V_16 |= V_37 ;
F_82 ( V_217 , V_13 -> V_218 ) ;
if ( V_13 -> V_49 == V_219 ) {
void * V_4 ;
V_29 -> V_220 = V_122 ;
F_83 ( V_217 , V_221 - 1 ) ;
V_4 = F_48 ( V_222 , V_217 -> V_223 | V_123 ) ;
if ( ! V_4 ) {
F_84 ( V_13 , L_25 ) ;
return - V_121 ;
}
F_85 ( V_217 , F_74 , V_4 , V_222 ) ;
} else {
V_29 -> V_220 = F_86 ( V_13 -> V_102 ) ;
V_29 -> V_224 = 1 ;
}
if ( V_29 -> V_220 > V_27 )
F_72 ( V_13 ,
L_26 ,
V_29 -> V_220 ) ;
F_87 ( V_217 , V_29 -> V_220 - 1 ) ;
if ( V_13 -> V_16 & V_225 )
F_88 ( V_226 , V_29 -> V_227 ) ;
if ( V_13 -> V_16 & V_228 ) {
int V_229 ;
V_229 = F_89 ( V_29 -> V_34 -> V_230 , F_90 ( V_13 -> V_102 ) ) ;
V_229 = F_89 ( V_231 - 1 , V_229 ) ;
F_91 ( V_29 , V_229 ) ;
}
F_92 ( V_217 , false ) ;
V_13 -> V_29 = V_29 ;
return 0 ;
}
int F_93 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 = F_94 ( V_9 , V_29 ) ;
int V_33 = 0 ;
F_73 ( V_29 ) ;
if ( V_13 )
V_33 = F_80 ( V_29 , V_13 ) ;
return V_33 ;
}
void F_95 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_216 * V_217 = V_29 -> V_216 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_75 -> V_195 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_94 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_232 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_52 ( V_217 -> V_233 ) ;
V_217 -> V_233 = NULL ;
V_217 -> V_234 = 0 ;
}
int F_96 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_235 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_235 < 1 || V_235 == V_29 -> V_235 )
return V_29 -> V_235 ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_97 ( V_13 ) )
return V_29 -> V_235 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_236 ;
if ( V_235 == 1 || ! F_98 ( V_13 ) ) {
V_13 -> V_16 |= V_236 ;
V_235 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_235 = F_89 ( V_235 , V_29 -> V_34 -> V_230 ) ;
V_235 = F_89 ( V_235 , F_90 ( V_13 -> V_102 ) ) ;
V_235 = F_89 ( V_235 , V_231 - 1 ) ;
if ( V_29 -> V_235 == V_235 )
return - V_20 ;
return F_91 ( V_29 , V_235 ) ;
}
int F_99 ( struct V_28 * V_29 , int V_235 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_96 ( V_9 , V_29 , V_235 ) ;
}
static unsigned int F_100 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_67 * V_68 = & V_148 -> V_68 ;
const T_3 * V_237 = V_157 -> V_238 ;
T_5 V_239 ;
T_3 V_240 = 0xff ;
if ( V_157 -> V_241 < 5 ) {
V_239 = 4 ;
goto V_242;
}
V_68 -> V_16 |= V_243 | V_244 ;
V_68 -> V_245 = V_246 ;
if ( V_237 [ 1 ] & 0x1 ) {
;
}
if ( V_237 [ 4 ] & 0x2 ) {
V_239 = 4 ;
V_240 = 1 ;
goto V_242;
}
if ( ( ( V_237 [ 4 ] >> 4 ) & 0xf ) != 0 ) {
V_239 = 4 ;
V_240 = 3 ;
goto V_242;
}
if ( V_237 [ 4 ] & 0x1 ) {
V_68 -> V_198 = 1 ;
if ( V_148 -> V_13 -> V_16 & V_247 ) {
V_68 -> V_16 |= V_248 ;
V_68 -> V_201 = 0x0 ;
V_68 -> V_200 = 0x0 ;
V_68 -> V_199 = 0x0 ;
V_68 -> V_1 |= V_249 ;
} else {
V_68 -> V_199 = 0x1 ;
V_68 -> V_200 = 0x0 ;
V_68 -> V_201 = 0x0 ;
}
V_68 -> V_162 = V_250 ;
} else {
if ( ( V_148 -> V_9 -> V_16 & V_251 ) &&
V_252 == V_253 )
goto V_254;
if ( ( V_148 -> V_9 -> V_16 & V_255 ) &&
F_101 () )
goto V_254;
V_68 -> V_162 = V_256 ;
}
return 0 ;
V_242:
F_28 ( V_148 -> V_13 , V_157 , V_239 , V_240 ) ;
return 1 ;
V_254:
V_157 -> V_63 = V_257 ;
return 1 ;
}
static unsigned int F_102 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
V_68 -> V_16 |= V_243 ;
V_68 -> V_245 = V_246 ;
if ( V_148 -> V_13 -> V_16 & V_258 )
V_68 -> V_162 = V_259 ;
else
V_68 -> V_162 = V_260 ;
V_148 -> V_16 |= V_261 ;
return 0 ;
}
static void F_103 ( const T_3 * V_237 , T_4 * V_262 , T_8 * V_263 )
{
T_4 V_264 = 0 ;
T_8 V_45 ;
F_104 ( L_27 ) ;
V_264 |= ( ( T_4 ) ( V_237 [ 1 ] & 0x1f ) ) << 16 ;
V_264 |= ( ( T_4 ) V_237 [ 2 ] ) << 8 ;
V_264 |= ( ( T_4 ) V_237 [ 3 ] ) ;
V_45 = V_237 [ 4 ] ;
* V_262 = V_264 ;
* V_263 = V_45 ;
}
static void F_105 ( const T_3 * V_237 , T_4 * V_262 , T_8 * V_263 )
{
T_4 V_264 = 0 ;
T_8 V_45 = 0 ;
F_104 ( L_28 ) ;
V_264 |= ( ( T_4 ) V_237 [ 2 ] ) << 24 ;
V_264 |= ( ( T_4 ) V_237 [ 3 ] ) << 16 ;
V_264 |= ( ( T_4 ) V_237 [ 4 ] ) << 8 ;
V_264 |= ( ( T_4 ) V_237 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_237 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_237 [ 8 ] ) ;
* V_262 = V_264 ;
* V_263 = V_45 ;
}
static void F_106 ( const T_3 * V_237 , T_4 * V_262 , T_8 * V_263 )
{
T_4 V_264 = 0 ;
T_8 V_45 = 0 ;
F_104 ( L_29 ) ;
V_264 |= ( ( T_4 ) V_237 [ 2 ] ) << 56 ;
V_264 |= ( ( T_4 ) V_237 [ 3 ] ) << 48 ;
V_264 |= ( ( T_4 ) V_237 [ 4 ] ) << 40 ;
V_264 |= ( ( T_4 ) V_237 [ 5 ] ) << 32 ;
V_264 |= ( ( T_4 ) V_237 [ 6 ] ) << 24 ;
V_264 |= ( ( T_4 ) V_237 [ 7 ] ) << 16 ;
V_264 |= ( ( T_4 ) V_237 [ 8 ] ) << 8 ;
V_264 |= ( ( T_4 ) V_237 [ 9 ] ) ;
V_45 |= ( ( T_8 ) V_237 [ 10 ] ) << 24 ;
V_45 |= ( ( T_8 ) V_237 [ 11 ] ) << 16 ;
V_45 |= ( ( T_8 ) V_237 [ 12 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_237 [ 13 ] ) ;
* V_262 = V_264 ;
* V_263 = V_45 ;
}
static unsigned int F_107 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_12 * V_13 = V_148 -> V_13 ;
T_4 V_265 = V_148 -> V_13 -> V_94 ;
const T_3 * V_237 = V_157 -> V_238 ;
T_4 V_207 ;
T_8 V_266 ;
T_5 V_239 ;
V_68 -> V_16 |= V_244 | V_243 ;
V_68 -> V_245 = V_246 ;
if ( V_237 [ 0 ] == V_267 ) {
if ( V_157 -> V_241 < 10 ) {
V_239 = 9 ;
goto V_242;
}
F_105 ( V_237 , & V_207 , & V_266 ) ;
} else if ( V_237 [ 0 ] == V_268 ) {
if ( V_157 -> V_241 < 16 ) {
V_239 = 15 ;
goto V_242;
}
F_106 ( V_237 , & V_207 , & V_266 ) ;
} else {
V_239 = 0 ;
goto V_242;
}
if ( ! V_266 )
goto V_269;
if ( V_207 >= V_265 )
goto V_270;
if ( ( V_207 + V_266 ) > V_265 )
goto V_270;
if ( V_13 -> V_16 & V_247 ) {
V_68 -> V_16 |= V_248 ;
if ( F_108 ( V_207 , V_266 ) ) {
V_68 -> V_162 = V_250 ;
V_68 -> V_1 |= ( V_207 >> 24 ) & 0xf ;
} else if ( F_109 ( V_207 , V_266 ) ) {
if ( ! ( V_13 -> V_16 & V_271 ) )
goto V_270;
V_68 -> V_16 |= V_202 ;
V_68 -> V_162 = V_272 ;
V_68 -> V_203 = ( V_266 >> 8 ) & 0xff ;
V_68 -> V_206 = ( V_207 >> 40 ) & 0xff ;
V_68 -> V_205 = ( V_207 >> 32 ) & 0xff ;
V_68 -> V_204 = ( V_207 >> 24 ) & 0xff ;
} else
goto V_270;
V_68 -> V_198 = V_266 & 0xff ;
V_68 -> V_201 = ( V_207 >> 16 ) & 0xff ;
V_68 -> V_200 = ( V_207 >> 8 ) & 0xff ;
V_68 -> V_199 = V_207 & 0xff ;
V_68 -> V_1 |= V_249 ;
} else {
T_8 V_273 , V_274 , V_275 , V_276 ;
if ( ! F_108 ( V_207 , V_266 ) )
goto V_270;
V_276 = ( T_8 ) V_207 / V_13 -> V_277 ;
V_275 = V_276 / V_13 -> V_278 ;
V_274 = V_276 % V_13 -> V_278 ;
V_273 = ( T_8 ) V_207 % V_13 -> V_277 + 1 ;
F_110 ( L_30 ,
( T_8 ) V_207 , V_276 , V_275 , V_274 , V_273 ) ;
if ( ( V_275 >> 16 ) || ( V_274 >> 4 ) || ( V_273 >> 8 ) || ( ! V_273 ) )
goto V_270;
V_68 -> V_162 = V_250 ;
V_68 -> V_198 = V_266 & 0xff ;
V_68 -> V_199 = V_273 ;
V_68 -> V_200 = V_275 ;
V_68 -> V_201 = V_275 >> 8 ;
V_68 -> V_1 |= V_274 ;
}
return 0 ;
V_242:
F_28 ( V_148 -> V_13 , V_157 , V_239 , 0xff ) ;
return 1 ;
V_270:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x21 , 0x0 ) ;
return 1 ;
V_269:
V_157 -> V_63 = V_257 ;
return 1 ;
}
static unsigned int F_111 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
const T_3 * V_237 = V_157 -> V_238 ;
unsigned int V_279 = 0 ;
T_4 V_207 ;
T_8 V_266 ;
int V_33 ;
T_5 V_239 = 0 ;
if ( V_237 [ 0 ] == V_280 || V_237 [ 0 ] == V_281 || V_237 [ 0 ] == V_282 )
V_279 |= V_283 ;
switch ( V_237 [ 0 ] ) {
case V_284 :
case V_280 :
if ( F_20 ( V_157 -> V_241 < 10 ) ) {
V_239 = 9 ;
goto V_242;
}
F_105 ( V_237 , & V_207 , & V_266 ) ;
if ( V_237 [ 1 ] & ( 1 << 3 ) )
V_279 |= V_285 ;
break;
case V_286 :
case V_281 :
if ( F_20 ( V_157 -> V_241 < 6 ) ) {
V_239 = 5 ;
goto V_242;
}
F_103 ( V_237 , & V_207 , & V_266 ) ;
if ( ! V_266 )
V_266 = 256 ;
break;
case V_287 :
case V_282 :
if ( F_20 ( V_157 -> V_241 < 16 ) ) {
V_239 = 15 ;
goto V_242;
}
F_106 ( V_237 , & V_207 , & V_266 ) ;
if ( V_237 [ 1 ] & ( 1 << 3 ) )
V_279 |= V_285 ;
break;
default:
F_110 ( L_31 ) ;
V_239 = 0 ;
goto V_242;
}
if ( ! V_266 )
goto V_269;
V_148 -> V_16 |= V_261 ;
V_148 -> V_160 = V_266 * V_157 -> V_1 -> V_220 ;
V_33 = F_112 ( & V_148 -> V_68 , V_148 -> V_13 , V_207 , V_266 , V_279 ,
V_148 -> V_150 ) ;
if ( F_75 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_288 )
goto V_270;
V_242:
F_28 ( V_148 -> V_13 , V_157 , V_239 , 0xff ) ;
return 1 ;
V_270:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x21 , 0x0 ) ;
return 1 ;
V_269:
V_157 -> V_63 = V_257 ;
return 1 ;
}
static void F_113 ( struct V_147 * V_148 )
{
struct V_56 * V_57 = V_148 -> V_151 ;
void (* F_114)( struct V_56 * ) = V_148 -> V_152 ;
F_115 ( V_148 ) ;
F_114 ( V_57 ) ;
}
static void F_116 ( struct V_147 * V_148 )
{
struct V_8 * V_9 = V_148 -> V_9 ;
struct V_56 * V_57 = V_148 -> V_151 ;
T_3 * V_237 = V_57 -> V_238 ;
int V_289 = ( V_148 -> V_196 != 0 ) ;
if ( ( ( V_237 [ 0 ] == V_126 ) || ( V_237 [ 0 ] == V_290 ) ) &&
( ( V_237 [ 2 ] & 0x20 ) || V_289 ) )
F_68 ( V_148 ) ;
else if ( V_148 -> V_16 & V_291 )
V_57 -> V_63 = V_65 ;
else if ( V_289 )
F_70 ( V_148 ) ;
else
V_57 -> V_63 = V_257 ;
if ( V_289 && ! V_9 -> V_75 -> V_195 )
F_65 ( V_9 -> V_197 , & V_148 -> V_193 ) ;
F_113 ( V_148 ) ;
}
static int F_117 ( struct V_12 * V_13 , struct V_56 * V_57 ,
T_9 V_292 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_147 * V_148 ;
int V_33 ;
F_104 ( L_32 ) ;
V_148 = F_59 ( V_13 , V_57 ) ;
if ( ! V_148 )
goto V_293;
if ( V_57 -> V_294 == V_124 ||
V_57 -> V_294 == V_295 ) {
if ( F_20 ( F_64 ( V_57 ) < 1 ) ) {
F_72 ( V_13 , L_33 ) ;
goto V_296;
}
F_118 ( V_148 , F_61 ( V_57 ) , F_62 ( V_57 ) ) ;
V_148 -> V_297 = V_57 -> V_294 ;
}
V_148 -> V_298 = F_116 ;
if ( V_292 ( V_148 ) )
goto V_299;
if ( V_9 -> V_75 -> V_300 ) {
if ( ( V_33 = V_9 -> V_75 -> V_300 ( V_148 ) ) )
goto V_301;
}
F_119 ( V_148 ) ;
F_104 ( L_34 ) ;
return 0 ;
V_299:
F_115 ( V_148 ) ;
V_57 -> V_89 ( V_57 ) ;
F_110 ( L_35 ) ;
return 0 ;
V_296:
F_115 ( V_148 ) ;
V_57 -> V_63 = ( V_302 << 16 ) ;
V_57 -> V_89 ( V_57 ) ;
V_293:
F_110 ( L_36 ) ;
return 0 ;
V_301:
F_115 ( V_148 ) ;
F_110 ( L_37 ) ;
if ( V_33 == V_303 )
return V_304 ;
else
return V_305 ;
}
static void * F_120 ( struct V_56 * V_57 , bool V_306 ,
unsigned long * V_16 )
{
F_5 ( & V_307 , * V_16 ) ;
memset ( V_308 , 0 , V_309 ) ;
if ( V_306 )
F_121 ( F_61 ( V_57 ) , F_62 ( V_57 ) ,
V_308 , V_309 ) ;
return V_308 ;
}
static inline void F_122 ( struct V_56 * V_57 , bool V_310 ,
unsigned long * V_16 )
{
if ( V_310 )
F_123 ( F_61 ( V_57 ) , F_62 ( V_57 ) ,
V_308 , V_309 ) ;
F_9 ( & V_307 , * V_16 ) ;
}
static unsigned int F_124 ( struct V_311 * args , T_3 * V_312 )
{
const T_3 V_313 [] = {
0x00 ,
0x60 ,
0x03 ,
0x20 ,
0x03 ,
0x00
} ;
const T_3 V_314 [] = {
0x00 ,
0xA0 ,
0x06 ,
0x00 ,
0x05 ,
0xC0 ,
0x60 ,
0x24 ,
} ;
T_3 V_315 [] = {
V_316 ,
0 ,
0x5 ,
2 ,
95 - 4 ,
0 ,
0 ,
2
} ;
F_104 ( L_32 ) ;
if ( F_125 ( args -> V_102 ) ||
( args -> V_13 -> V_11 -> V_9 -> V_39 & V_317 ) )
V_315 [ 1 ] |= ( 1 << 7 ) ;
if ( args -> V_13 -> V_49 == V_51 ) {
V_315 [ 0 ] = V_318 ;
V_315 [ 2 ] = 0x7 ;
}
memcpy ( V_312 , V_315 , sizeof( V_315 ) ) ;
memcpy ( & V_312 [ 8 ] , L_38 , 8 ) ;
F_44 ( args -> V_102 , & V_312 [ 16 ] , V_105 , 16 ) ;
F_44 ( args -> V_102 , & V_312 [ 32 ] , V_107 + 2 , 4 ) ;
if ( strncmp ( & V_312 [ 32 ] , L_39 , 4 ) == 0 )
F_44 ( args -> V_102 , & V_312 [ 32 ] , V_107 , 4 ) ;
if ( V_312 [ 32 ] == 0 || V_312 [ 32 ] == ' ' )
memcpy ( & V_312 [ 32 ] , L_40 , 4 ) ;
if ( F_126 ( args -> V_102 ) || args -> V_13 -> V_49 == V_51 )
memcpy ( V_312 + 58 , V_314 , sizeof( V_314 ) ) ;
else
memcpy ( V_312 + 58 , V_313 , sizeof( V_313 ) ) ;
return 0 ;
}
static unsigned int F_127 ( struct V_311 * args , T_3 * V_312 )
{
int V_319 ;
const T_3 V_320 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
0xb6 ,
} ;
V_319 = sizeof( V_320 ) ;
if ( ! ( args -> V_13 -> V_16 & V_321 ) )
V_319 -- ;
V_312 [ 3 ] = V_319 ;
memcpy ( V_312 + 4 , V_320 , V_319 ) ;
return 0 ;
}
static unsigned int F_128 ( struct V_311 * args , T_3 * V_312 )
{
const T_3 V_315 [] = {
0 ,
0x80 ,
0 ,
V_110 ,
} ;
memcpy ( V_312 , V_315 , sizeof( V_315 ) ) ;
F_44 ( args -> V_102 , ( unsigned char * ) & V_312 [ 4 ] ,
V_109 , V_110 ) ;
return 0 ;
}
static unsigned int F_129 ( struct V_311 * args , T_3 * V_312 )
{
const int V_322 = 68 ;
int V_323 ;
V_312 [ 1 ] = 0x83 ;
V_323 = 4 ;
V_312 [ V_323 + 0 ] = 2 ;
V_312 [ V_323 + 3 ] = V_110 ;
V_323 += 4 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_312 + V_323 ,
V_109 , V_110 ) ;
V_323 += V_110 ;
V_312 [ V_323 + 0 ] = 2 ;
V_312 [ V_323 + 1 ] = 1 ;
V_312 [ V_323 + 3 ] = V_322 ;
V_323 += 4 ;
memcpy ( V_312 + V_323 , L_38 , 8 ) ;
V_323 += 8 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_312 + V_323 , V_105 ,
V_106 ) ;
V_323 += V_106 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_312 + V_323 , V_109 ,
V_110 ) ;
V_323 += V_110 ;
if ( F_130 ( args -> V_102 ) ) {
V_312 [ V_323 + 0 ] = 1 ;
V_312 [ V_323 + 1 ] = 3 ;
V_312 [ V_323 + 3 ] = V_324 ;
V_323 += 4 ;
F_44 ( args -> V_102 , ( unsigned char * ) V_312 + V_323 ,
V_325 , V_324 ) ;
V_323 += V_324 ;
}
V_312 [ 3 ] = V_323 - 4 ;
return 0 ;
}
static unsigned int F_131 ( struct V_311 * args , T_3 * V_312 )
{
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_312 [ 1 ] = 0x89 ;
V_312 [ 2 ] = ( 0x238 >> 8 ) ;
V_312 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_312 [ 8 ] , L_41 , 8 ) ;
memcpy ( & V_312 [ 16 ] , L_42 , 16 ) ;
memcpy ( & V_312 [ 32 ] , V_326 , 4 ) ;
V_68 . V_162 = V_167 ;
V_68 . V_199 = 0x1 ;
V_68 . V_198 = 0x1 ;
F_132 ( & V_68 , 0 , 1 , & V_312 [ 36 ] ) ;
V_312 [ 36 ] = 0x34 ;
V_312 [ 56 ] = V_327 ;
memcpy ( & V_312 [ 60 ] , & args -> V_102 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_133 ( struct V_311 * args , T_3 * V_312 )
{
T_5 V_328 ;
V_312 [ 1 ] = 0xb0 ;
V_312 [ 3 ] = 0x3c ;
V_328 = 1 << F_134 ( args -> V_102 ) ;
F_135 ( V_328 , & V_312 [ 6 ] ) ;
if ( F_136 ( args -> V_102 ) ) {
F_137 ( 65535 * V_329 , & V_312 [ 36 ] ) ;
F_138 ( 1 , & V_312 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_139 ( struct V_311 * args , T_3 * V_312 )
{
int V_330 = F_140 ( args -> V_102 ) ;
int V_331 = F_141 ( args -> V_102 ) ;
T_3 V_332 = F_126 ( args -> V_102 ) ;
V_312 [ 1 ] = 0xb1 ;
V_312 [ 3 ] = 0x3c ;
V_312 [ 4 ] = V_331 >> 8 ;
V_312 [ 5 ] = V_331 ;
V_312 [ 7 ] = V_330 ;
if ( V_332 )
V_312 [ 8 ] = ( V_332 << 4 ) ;
return 0 ;
}
static unsigned int F_142 ( struct V_311 * args , T_3 * V_312 )
{
V_312 [ 1 ] = 0xb2 ;
V_312 [ 3 ] = 0x4 ;
V_312 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_143 ( struct V_311 * args , T_3 * V_312 )
{
V_312 [ 1 ] = 0xb6 ;
V_312 [ 3 ] = 0x3C ;
if ( args -> V_13 -> V_333 & 1 )
V_312 [ 4 ] |= 1 ;
F_138 ( args -> V_13 -> V_334 , & V_312 [ 8 ] ) ;
F_138 ( args -> V_13 -> V_335 , & V_312 [ 12 ] ) ;
F_138 ( args -> V_13 -> V_336 , & V_312 [ 16 ] ) ;
return 0 ;
}
static unsigned int F_144 ( struct V_311 * args , T_3 * V_312 )
{
F_104 ( L_32 ) ;
return 0 ;
}
static void F_145 ( T_3 * V_337 , const T_3 * V_338 , int V_339 , bool V_340 )
{
if ( V_340 ) {
memcpy ( V_337 , V_338 , 2 ) ;
memset ( V_337 + 2 , 0 , V_339 - 2 ) ;
} else {
memcpy ( V_337 , V_338 , V_339 ) ;
}
}
static unsigned int F_146 ( T_5 * V_102 , T_3 * V_4 , bool V_340 )
{
F_145 ( V_4 , V_341 , sizeof( V_341 ) , V_340 ) ;
if ( V_340 ) {
V_4 [ 2 ] |= ( 1 << 2 ) ;
} else {
V_4 [ 2 ] |= ( F_147 ( V_102 ) << 2 ) ;
V_4 [ 12 ] |= ( ! F_148 ( V_102 ) << 5 ) ;
}
return sizeof( V_341 ) ;
}
static unsigned int F_149 ( struct V_12 * V_13 , T_3 * V_4 ,
bool V_340 )
{
F_145 ( V_4 , V_342 , sizeof( V_342 ) , V_340 ) ;
if ( V_340 ) {
V_4 [ 2 ] |= ( 1 << 2 ) ;
} else {
bool V_61 = ( V_13 -> V_16 & V_62 ) ;
V_4 [ 2 ] |= ( V_61 << 2 ) ;
}
return sizeof( V_342 ) ;
}
static unsigned int F_150 ( T_3 * V_4 , bool V_340 )
{
F_145 ( V_4 , V_343 , sizeof( V_343 ) ,
V_340 ) ;
return sizeof( V_343 ) ;
}
static int F_151 ( T_5 * V_102 )
{
unsigned char V_344 [ V_106 + 1 ] , V_345 [ V_108 + 1 ] ;
if ( ! V_346 )
return 0 ;
if ( ! F_152 ( V_102 ) )
return 0 ;
F_153 ( V_102 , V_344 , V_105 , sizeof( V_344 ) ) ;
F_153 ( V_102 , V_345 , V_107 , sizeof( V_345 ) ) ;
if ( strcmp ( V_344 , L_43 ) )
return 1 ;
if ( strcmp ( V_345 , L_44 ) )
return 1 ;
return 0 ;
}
static unsigned int F_154 ( struct V_311 * args , T_3 * V_312 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_151 = args -> V_57 -> V_238 , * V_347 = V_312 ;
const T_3 V_348 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_349 , V_350 ;
unsigned int V_351 , V_352 , V_353 ;
T_3 V_354 , V_240 = 0xff ;
T_5 V_239 ;
F_104 ( L_32 ) ;
V_353 = ( V_151 [ 0 ] == V_355 ) ;
V_351 = ! ( V_151 [ 1 ] & 0x8 ) ;
V_352 = V_151 [ 2 ] >> 6 ;
switch ( V_352 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_356;
default:
V_239 = 2 ;
V_240 = 6 ;
goto V_242;
}
if ( V_353 )
V_347 += 4 + ( V_351 ? 8 : 0 ) ;
else
V_347 += 8 + ( V_351 ? 8 : 0 ) ;
V_349 = V_151 [ 2 ] & 0x3f ;
V_350 = V_151 [ 3 ] ;
if ( V_350 && ( V_350 != V_357 ) ) {
V_239 = 3 ;
goto V_242;
}
switch( V_349 ) {
case V_358 :
V_347 += F_150 ( V_347 , V_352 == 1 ) ;
break;
case V_359 :
V_347 += F_146 ( args -> V_102 , V_347 , V_352 == 1 ) ;
break;
case V_360 :
V_347 += F_149 ( args -> V_13 , V_347 , V_352 == 1 ) ;
break;
case V_361 :
V_347 += F_150 ( V_347 , V_352 == 1 ) ;
V_347 += F_146 ( args -> V_102 , V_347 , V_352 == 1 ) ;
V_347 += F_149 ( args -> V_13 , V_347 , V_352 == 1 ) ;
break;
default:
V_239 = 2 ;
goto V_242;
}
V_354 = 0 ;
if ( F_151 ( args -> V_102 ) && ( V_13 -> V_16 & V_271 ) &&
( ! ( V_13 -> V_16 & V_362 ) || V_13 -> V_363 ) )
V_354 = 1 << 4 ;
if ( V_353 ) {
V_312 [ 0 ] = V_347 - V_312 - 1 ;
V_312 [ 2 ] |= V_354 ;
if ( V_351 ) {
V_312 [ 3 ] = sizeof( V_348 ) ;
memcpy ( V_312 + 4 , V_348 , sizeof( V_348 ) ) ;
}
} else {
unsigned int V_364 = V_347 - V_312 - 2 ;
V_312 [ 0 ] = V_364 >> 8 ;
V_312 [ 1 ] = V_364 ;
V_312 [ 3 ] |= V_354 ;
if ( V_351 ) {
V_312 [ 7 ] = sizeof( V_348 ) ;
memcpy ( V_312 + 8 , V_348 , sizeof( V_348 ) ) ;
}
}
return 0 ;
V_242:
F_28 ( V_13 , args -> V_57 , V_239 , V_240 ) ;
return 1 ;
V_356:
F_23 ( V_13 , args -> V_57 , V_74 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_155 ( struct V_311 * args , T_3 * V_312 )
{
struct V_12 * V_13 = args -> V_13 ;
T_4 V_365 = V_13 -> V_94 - 1 ;
T_8 V_220 ;
T_3 V_366 ;
T_5 V_367 ;
V_220 = F_86 ( V_13 -> V_102 ) ;
V_366 = F_134 ( V_13 -> V_102 ) ;
V_367 = F_156 ( V_13 -> V_102 , V_366 ) ;
F_104 ( L_32 ) ;
if ( args -> V_57 -> V_238 [ 0 ] == V_368 ) {
if ( V_365 >= 0xffffffffULL )
V_365 = 0xffffffff ;
V_312 [ 0 ] = V_365 >> ( 8 * 3 ) ;
V_312 [ 1 ] = V_365 >> ( 8 * 2 ) ;
V_312 [ 2 ] = V_365 >> ( 8 * 1 ) ;
V_312 [ 3 ] = V_365 ;
V_312 [ 4 ] = V_220 >> ( 8 * 3 ) ;
V_312 [ 5 ] = V_220 >> ( 8 * 2 ) ;
V_312 [ 6 ] = V_220 >> ( 8 * 1 ) ;
V_312 [ 7 ] = V_220 ;
} else {
V_312 [ 0 ] = V_365 >> ( 8 * 7 ) ;
V_312 [ 1 ] = V_365 >> ( 8 * 6 ) ;
V_312 [ 2 ] = V_365 >> ( 8 * 5 ) ;
V_312 [ 3 ] = V_365 >> ( 8 * 4 ) ;
V_312 [ 4 ] = V_365 >> ( 8 * 3 ) ;
V_312 [ 5 ] = V_365 >> ( 8 * 2 ) ;
V_312 [ 6 ] = V_365 >> ( 8 * 1 ) ;
V_312 [ 7 ] = V_365 ;
V_312 [ 8 ] = V_220 >> ( 8 * 3 ) ;
V_312 [ 9 ] = V_220 >> ( 8 * 2 ) ;
V_312 [ 10 ] = V_220 >> ( 8 * 1 ) ;
V_312 [ 11 ] = V_220 ;
V_312 [ 12 ] = 0 ;
V_312 [ 13 ] = V_366 ;
V_312 [ 14 ] = ( V_367 >> 8 ) & 0x3f ;
V_312 [ 15 ] = V_367 ;
if ( F_136 ( args -> V_102 ) &&
! ( V_13 -> V_22 & V_369 ) ) {
V_312 [ 14 ] |= 0x80 ;
if ( F_157 ( args -> V_102 ) &&
V_13 -> V_22 & V_370 ) {
F_158 ( V_13 , L_45 ) ;
V_312 [ 14 ] |= 0x40 ;
}
}
if ( F_126 ( args -> V_102 ) ||
args -> V_13 -> V_49 == V_51 )
V_312 [ 12 ] = ( 1 << 4 ) ;
}
return 0 ;
}
static unsigned int F_159 ( struct V_311 * args , T_3 * V_312 )
{
F_104 ( L_32 ) ;
V_312 [ 3 ] = 8 ;
return 0 ;
}
static void F_160 ( struct V_147 * V_148 )
{
if ( V_148 -> V_196 && ( ( V_148 -> V_196 & V_371 ) == 0 ) ) {
F_68 ( V_148 ) ;
}
F_113 ( V_148 ) ;
}
static inline int F_161 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_135 ) ;
}
static void F_162 ( struct V_147 * V_148 )
{
struct V_8 * V_9 = V_148 -> V_9 ;
struct V_56 * V_57 = V_148 -> V_151 ;
F_110 ( L_46 ) ;
memset ( V_57 -> V_66 , 0 , V_71 ) ;
#ifdef F_163
if ( V_9 -> V_75 -> V_372 )
V_9 -> V_75 -> V_372 ( V_9 , & V_148 -> V_68 ) ;
#endif
V_57 -> V_66 [ 0 ] = 0x70 ;
V_57 -> V_66 [ 2 ] = V_148 -> V_68 . V_164 >> 4 ;
F_164 ( V_148 ) ;
F_165 ( & V_148 -> V_373 , V_57 -> V_66 , V_71 ) ;
F_118 ( V_148 , & V_148 -> V_373 , 1 ) ;
V_148 -> V_297 = V_124 ;
memset ( & V_148 -> V_237 , 0 , V_148 -> V_13 -> V_374 ) ;
V_148 -> V_237 [ 0 ] = V_375 ;
V_148 -> V_237 [ 4 ] = V_71 ;
V_148 -> V_68 . V_16 |= V_244 | V_243 ;
V_148 -> V_68 . V_162 = V_376 ;
if ( F_161 ( V_9 ) ) {
V_148 -> V_68 . V_245 = V_377 ;
V_148 -> V_68 . V_164 |= V_378 ;
} else {
V_148 -> V_68 . V_245 = V_379 ;
V_148 -> V_68 . V_200 = V_71 ;
V_148 -> V_68 . V_201 = 0 ;
}
V_148 -> V_160 = V_71 ;
V_148 -> V_298 = F_160 ;
F_119 ( V_148 ) ;
F_110 ( L_34 ) ;
}
static void F_166 ( struct V_147 * V_148 )
{
struct V_56 * V_57 = V_148 -> V_151 ;
unsigned int V_196 = V_148 -> V_196 ;
F_104 ( L_47 , V_196 ) ;
if ( F_20 ( V_148 -> V_9 -> V_75 -> V_195 &&
( V_196 || V_148 -> V_16 & V_291 ) ) ) {
if ( ! ( V_148 -> V_16 & V_291 ) ) {
F_68 ( V_148 ) ;
}
if ( V_148 -> V_237 [ 0 ] == V_380 && V_148 -> V_13 -> V_29 )
V_148 -> V_13 -> V_29 -> V_381 = 0 ;
V_148 -> V_151 -> V_63 = V_65 ;
F_113 ( V_148 ) ;
return;
}
if ( F_20 ( V_196 & V_371 ) ) {
V_57 -> V_63 = V_65 ;
F_162 ( V_148 ) ;
return;
} else if ( F_20 ( V_196 ) ) {
F_68 ( V_148 ) ;
} else {
T_3 * V_151 = V_57 -> V_238 ;
if ( ( V_151 [ 0 ] == V_382 ) && ( ( V_151 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_16 ;
T_3 * V_4 ;
V_4 = F_120 ( V_57 , true , & V_16 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_122 ( V_57 , true , & V_16 ) ;
}
V_57 -> V_63 = V_257 ;
}
F_113 ( V_148 ) ;
}
static unsigned int F_167 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_12 * V_13 = V_148 -> V_13 ;
int V_383 = ( V_157 -> V_294 == V_125 ) ;
int V_384 = ! V_383 && ( V_13 -> V_16 & V_362 ) ;
unsigned int V_160 ;
memset ( V_148 -> V_237 , 0 , V_13 -> V_374 ) ;
memcpy ( V_148 -> V_237 , V_157 -> V_238 , V_157 -> V_241 ) ;
V_148 -> V_298 = F_166 ;
V_148 -> V_68 . V_16 |= V_244 | V_243 ;
if ( V_157 -> V_294 == V_295 ) {
V_148 -> V_68 . V_16 |= V_283 ;
F_110 ( L_48 ) ;
}
V_148 -> V_68 . V_162 = V_376 ;
F_63 ( V_148 ) ;
if ( ! V_383 && ! V_384 && F_168 ( V_148 ) )
V_384 = 1 ;
V_160 = F_89 ( F_169 ( V_148 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_160 & 0x1 )
V_160 ++ ;
V_148 -> V_68 . V_200 = ( V_160 & 0xFF ) ;
V_148 -> V_68 . V_201 = ( V_160 >> 8 ) ;
if ( V_383 )
V_148 -> V_68 . V_245 = V_385 ;
else if ( V_384 )
V_148 -> V_68 . V_245 = V_379 ;
else {
V_148 -> V_68 . V_245 = V_377 ;
V_148 -> V_68 . V_164 |= V_378 ;
if ( ( V_13 -> V_16 & V_386 ) &&
( V_157 -> V_294 != V_295 ) )
V_148 -> V_68 . V_164 |= V_387 ;
}
return 0 ;
}
static struct V_12 * F_170 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_171 ( V_9 ) ) {
if ( F_75 ( V_43 < F_172 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_75 ( V_43 < V_9 -> V_388 ) )
return & V_9 -> V_389 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_94 ( struct V_8 * V_9 ,
const struct V_28 * V_111 )
{
int V_43 ;
if ( ! F_171 ( V_9 ) ) {
if ( F_20 ( V_111 -> V_390 || V_111 -> V_391 ) )
return NULL ;
V_43 = V_111 -> V_102 ;
} else {
if ( F_20 ( V_111 -> V_102 || V_111 -> V_391 ) )
return NULL ;
V_43 = V_111 -> V_390 ;
}
return F_170 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_14 ( struct V_8 * V_9 , const struct V_28 * V_111 )
{
struct V_12 * V_13 = F_94 ( V_9 , V_111 ) ;
if ( F_20 ( ! V_13 || ! F_97 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_173 ( T_3 V_392 )
{
switch( ( V_392 & 0x1e ) >> 1 ) {
case 3 :
return V_246 ;
case 6 :
case 10 :
case 11 :
return V_393 ;
case 4 :
case 5 :
return V_394 ;
case 12 :
return V_395 ;
case 0 :
case 1 :
case 8 :
case 9 :
case 7 :
case 15 :
default:
break;
}
return V_396 ;
}
static unsigned int F_174 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & ( V_148 -> V_68 ) ;
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_12 * V_13 = V_148 -> V_13 ;
const T_3 * V_237 = V_157 -> V_238 ;
T_5 V_239 ;
if ( ( V_68 -> V_245 = F_173 ( V_237 [ 1 ] ) ) == V_396 ) {
V_239 = 1 ;
goto V_242;
}
if ( F_175 ( V_68 -> V_245 ) && ( V_237 [ 2 ] & 0x3 ) == 0 )
V_68 -> V_245 = V_397 ;
V_68 -> V_16 |= V_248 ;
if ( V_237 [ 0 ] == V_126 ) {
if ( V_237 [ 1 ] & 0x01 ) {
V_68 -> V_398 = V_237 [ 3 ] ;
V_68 -> V_203 = V_237 [ 5 ] ;
V_68 -> V_204 = V_237 [ 7 ] ;
V_68 -> V_205 = V_237 [ 9 ] ;
V_68 -> V_206 = V_237 [ 11 ] ;
V_68 -> V_16 |= V_202 ;
} else
V_68 -> V_16 &= ~ V_202 ;
V_68 -> V_164 = V_237 [ 4 ] ;
V_68 -> V_198 = V_237 [ 6 ] ;
V_68 -> V_199 = V_237 [ 8 ] ;
V_68 -> V_200 = V_237 [ 10 ] ;
V_68 -> V_201 = V_237 [ 12 ] ;
V_68 -> V_1 = V_237 [ 13 ] ;
V_68 -> V_162 = V_237 [ 14 ] ;
} else {
V_68 -> V_16 &= ~ V_202 ;
V_68 -> V_164 = V_237 [ 3 ] ;
V_68 -> V_198 = V_237 [ 4 ] ;
V_68 -> V_199 = V_237 [ 5 ] ;
V_68 -> V_200 = V_237 [ 6 ] ;
V_68 -> V_201 = V_237 [ 7 ] ;
V_68 -> V_1 = V_237 [ 8 ] ;
V_68 -> V_162 = V_237 [ 9 ] ;
}
if ( F_175 ( V_68 -> V_245 ) )
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_1 = V_13 -> V_43 ?
V_68 -> V_1 | V_399 : V_68 -> V_1 & ~ V_399 ;
switch ( V_68 -> V_162 ) {
case V_400 :
case V_401 :
case V_402 :
case V_403 :
if ( V_68 -> V_245 != V_394 || V_68 -> V_198 != 1 ) {
V_239 = 1 ;
goto V_242;
}
V_148 -> V_404 = F_64 ( V_157 ) ;
break;
case V_405 :
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
case V_250 :
case V_272 :
case V_418 :
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
V_148 -> V_404 = V_157 -> V_1 -> V_220 ;
break;
default:
V_148 -> V_404 = V_122 ;
}
V_68 -> V_16 |= V_244 | V_243 ;
if ( V_157 -> V_294 == V_295 )
V_68 -> V_16 |= V_283 ;
V_148 -> V_16 |= V_431 | V_432 ;
F_63 ( V_148 ) ;
if ( V_68 -> V_245 == V_393 && V_13 -> V_433 == 0 ) {
V_239 = 1 ;
goto V_242;
}
if ( ( V_237 [ 1 ] & 0xe0 ) && ! F_176 ( V_68 ) ) {
V_239 = 1 ;
goto V_242;
}
if ( F_176 ( V_68 ) ) {
unsigned int V_363 = 1 << ( V_237 [ 1 ] >> 5 ) ;
if ( V_363 != V_13 -> V_363 )
F_72 ( V_13 , L_49 ,
V_363 ) ;
}
if ( V_68 -> V_162 == V_434 &&
V_68 -> V_164 == V_435 ) {
V_239 = ( V_237 [ 0 ] == V_126 ) ? 4 : 3 ;
goto V_242;
}
if ( V_68 -> V_162 >= 0x5C && V_68 -> V_162 <= 0x5F && ! V_436 ) {
V_239 = ( V_237 [ 0 ] == V_126 ) ? 14 : 9 ;
goto V_242;
}
return 0 ;
V_242:
F_28 ( V_13 , V_157 , V_239 , 0xff ) ;
return 1 ;
}
static T_2 F_177 ( struct V_56 * V_57 , T_8 V_437 ,
T_4 V_438 , T_8 V_5 )
{
struct V_28 * V_439 = V_57 -> V_1 ;
T_2 V_45 = V_439 -> V_220 ;
T_2 V_440 ;
T_10 * V_4 ;
T_8 V_183 = 0 ;
unsigned long V_16 ;
F_178 ( V_45 > V_309 ) ;
if ( V_45 > V_309 )
V_45 = V_309 ;
F_5 ( & V_307 , V_16 ) ;
V_4 = ( ( void * ) V_308 ) ;
memset ( V_4 , 0 , V_45 ) ;
while ( V_183 < V_437 ) {
T_4 V_441 = V_438 |
( ( T_4 ) ( V_5 > 0xffff ? 0xffff : V_5 ) << 48 ) ;
V_4 [ V_183 ++ ] = F_179 ( V_441 ) ;
if ( V_5 <= 0xffff )
break;
V_5 -= 0xffff ;
V_438 += 0xffff ;
}
V_440 = F_123 ( F_61 ( V_57 ) , F_62 ( V_57 ) , V_4 , V_45 ) ;
F_9 ( & V_307 , V_16 ) ;
return V_440 ;
}
static T_2 F_180 ( struct V_56 * V_57 , T_4 V_264 , T_4 V_323 )
{
struct V_28 * V_439 = V_57 -> V_1 ;
T_2 V_45 = V_439 -> V_220 ;
T_2 V_440 ;
T_5 * V_4 ;
unsigned long V_16 ;
F_5 ( & V_307 , V_16 ) ;
V_4 = ( ( void * ) V_308 ) ;
F_181 ( 0x0002 , & V_4 [ 0 ] ) ;
F_181 ( 0x0101 , & V_4 [ 1 ] ) ;
F_182 ( V_264 , & V_4 [ 2 ] ) ;
F_182 ( V_323 , & V_4 [ 6 ] ) ;
F_183 ( 0u , & V_4 [ 10 ] ) ;
F_178 ( V_45 > V_309 ) ;
if ( V_45 > V_309 )
V_45 = V_309 ;
V_440 = F_123 ( F_61 ( V_57 ) , F_62 ( V_57 ) , V_4 , V_45 ) ;
F_9 ( & V_307 , V_16 ) ;
return V_440 ;
}
static unsigned int F_184 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_28 * V_439 = V_157 -> V_1 ;
T_2 V_45 = V_439 -> V_220 ;
struct V_12 * V_13 = V_148 -> V_13 ;
const T_3 * V_237 = V_157 -> V_238 ;
T_4 V_207 ;
T_8 V_266 ;
const T_8 V_437 = V_45 >> 3 ;
T_8 V_442 ;
T_5 V_239 ;
T_3 V_240 = 0xff ;
T_3 V_443 = V_237 [ 1 ] & 0x8 ;
if ( F_20 ( ! V_13 -> V_433 ) )
goto V_444;
if ( F_20 ( V_157 -> V_241 < 16 ) ) {
V_239 = 15 ;
goto V_242;
}
F_106 ( V_237 , & V_207 , & V_266 ) ;
if ( V_443 ) {
if ( ( V_13 -> V_22 & V_369 ) ||
! F_136 ( V_13 -> V_102 ) ) {
V_239 = 1 ;
V_240 = 3 ;
goto V_242;
}
if ( V_266 > 0xffff * V_437 ) {
V_239 = 2 ;
goto V_242;
}
} else {
if ( ! F_185 ( V_13 -> V_102 ) ) {
V_239 = 1 ;
V_240 = 3 ;
goto V_242;
}
}
if ( ! F_62 ( V_157 ) )
goto V_445;
if ( V_443 ) {
V_442 = F_177 ( V_157 , V_437 , V_207 , V_266 ) ;
if ( V_442 != V_45 )
goto V_445;
if ( F_98 ( V_13 ) && F_186 ( V_13 ) ) {
V_68 -> V_245 = V_395 ;
V_68 -> V_162 = V_446 ;
V_68 -> V_203 = V_447 & 0x1f ;
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_398 = ( V_442 / 512 ) >> 8 ;
V_68 -> V_164 = V_442 / 512 ;
V_68 -> V_448 = 1 ;
} else {
V_68 -> V_245 = V_393 ;
V_68 -> V_398 = 0 ;
V_68 -> V_164 = V_449 ;
V_68 -> V_203 = ( V_442 / 512 ) >> 8 ;
V_68 -> V_198 = V_442 / 512 ;
V_68 -> V_162 = V_450 ;
}
} else {
V_442 = F_180 ( V_157 , V_207 , V_266 ) ;
if ( V_442 != V_45 )
goto V_445;
V_68 -> V_398 = 0 ;
V_68 -> V_164 = 0 ;
V_68 -> V_203 = 0 ;
V_68 -> V_198 = 1 ;
V_68 -> V_201 = 0 ;
V_68 -> V_200 = 0 ;
V_68 -> V_199 = V_256 ;
V_68 -> V_206 = 0 ;
V_68 -> V_205 = 0 ;
V_68 -> V_204 = 0 ;
V_68 -> V_1 = V_256 ;
V_68 -> V_245 = V_393 ;
V_68 -> V_162 = V_451 ;
if ( F_20 ( V_13 -> V_16 & V_362 ) )
V_68 -> V_162 = V_452 ;
}
V_68 -> V_16 |= V_244 | V_243 | V_202 |
V_283 ;
F_63 ( V_148 ) ;
return 0 ;
V_242:
F_28 ( V_13 , V_157 , V_239 , V_240 ) ;
return 1 ;
V_445:
F_23 ( V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
V_444:
F_23 ( V_13 , V_157 , V_74 , 0x20 , 0x0 ) ;
return 1 ;
}
static unsigned int F_187 ( struct V_311 * args , T_3 * V_312 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_237 = args -> V_57 -> V_238 ;
T_3 V_453 = 0 ;
unsigned int V_163 = 0 ;
if ( V_237 [ 2 ] != 1 ) {
F_72 ( V_13 , L_50 , V_237 [ 2 ] ) ;
V_163 = 2 ;
goto V_454;
}
switch ( V_237 [ 3 ] ) {
case V_382 :
case V_355 :
case V_455 :
case V_368 :
case V_456 :
case V_457 :
case V_375 :
case V_458 :
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
case V_286 :
case V_284 :
case V_287 :
case V_281 :
case V_280 :
case V_282 :
case V_290 :
case V_126 :
case V_267 :
case V_268 :
case V_465 :
case V_466 :
case V_467 :
V_453 = 3 ;
break;
case V_468 :
if ( ! F_185 ( V_13 -> V_102 ) )
break;
case V_469 :
case V_470 :
if ( F_126 ( V_13 -> V_102 ) ||
V_13 -> V_49 == V_51 )
V_453 = 3 ;
break;
default:
break;
}
V_454:
V_312 [ 1 ] = V_453 ;
return V_163 ;
}
static void F_188 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_471 V_472 ;
unsigned long V_16 ;
unsigned int V_473 = 0 ;
F_189 ( & V_472 , F_61 ( V_157 ) , F_62 ( V_157 ) ,
V_474 | V_475 ) ;
F_190 ( V_16 ) ;
while ( F_191 ( & V_472 ) ) {
unsigned int V_476 = 0 ;
if ( V_473 == 0 ) {
char * V_315 ;
T_8 V_477 ;
T_4 V_478 , V_479 ;
T_5 V_480 ;
V_315 = V_472 . V_481 ;
V_477 = F_192 ( & V_315 [ 0 ] ) ;
V_480 = F_193 ( & V_315 [ 4 ] ) ;
V_478 = F_194 ( & V_315 [ 8 ] ) ;
V_479 = F_194 ( & V_315 [ 16 ] ) ;
F_138 ( V_477 , & V_315 [ 0 ] ) ;
V_315 [ 4 ] = V_480 & 0xf ;
F_137 ( V_478 , & V_315 [ 8 ] ) ;
F_137 ( V_479 , & V_315 [ 16 ] ) ;
V_476 += 64 ;
V_473 += 64 ;
}
while ( V_476 < V_472 . V_482 ) {
char * V_483 ;
T_3 V_484 , type , V_485 , V_486 ;
T_4 V_442 , V_487 , V_488 ;
V_483 = V_472 . V_481 + V_476 ;
type = V_483 [ 0 ] & 0xf ;
V_484 = ( V_483 [ 1 ] >> 4 ) & 0xf ;
V_485 = ( V_483 [ 1 ] & 2 ) ;
V_486 = ( V_483 [ 1 ] & 1 ) ;
V_442 = F_194 ( & V_483 [ 8 ] ) ;
V_487 = F_194 ( & V_483 [ 16 ] ) ;
V_488 = F_194 ( & V_483 [ 24 ] ) ;
V_483 [ 0 ] = type ;
V_483 [ 1 ] = ( V_484 << 4 ) | V_485 | V_486 ;
F_137 ( V_442 , & V_483 [ 8 ] ) ;
F_137 ( V_487 , & V_483 [ 16 ] ) ;
F_137 ( V_488 , & V_483 [ 24 ] ) ;
F_178 ( V_476 + 64 > V_472 . V_482 ) ;
V_476 += 64 ;
V_473 += 64 ;
}
}
F_195 ( & V_472 ) ;
F_196 ( V_16 ) ;
F_116 ( V_148 ) ;
}
static unsigned int F_197 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_56 * V_157 = V_148 -> V_151 ;
const T_3 * V_237 = V_157 -> V_238 ;
T_5 V_273 , V_239 = ( T_5 ) - 1 ;
T_3 V_489 , V_490 , V_240 = 0xff ;
T_4 V_207 ;
T_8 V_266 ;
if ( F_20 ( V_157 -> V_241 < 16 ) ) {
F_72 ( V_148 -> V_13 , L_51 ,
V_157 -> V_241 ) ;
V_239 = 15 ;
goto V_242;
}
F_106 ( V_237 , & V_207 , & V_266 ) ;
if ( V_266 != F_64 ( V_157 ) ) {
F_72 ( V_148 -> V_13 , L_52 ,
V_266 , F_64 ( V_157 ) ) ;
goto V_445;
}
V_489 = V_237 [ 1 ] & 0x1f ;
if ( V_489 != V_491 ) {
F_72 ( V_148 -> V_13 , L_53 , V_489 ) ;
V_239 = 1 ;
goto V_242;
}
if ( ( V_266 / 512 ) > 0xffff || V_266 < 512 || ( V_266 % 512 ) ) {
F_72 ( V_148 -> V_13 , L_54 , V_266 ) ;
goto V_445;
}
V_273 = V_266 / 512 ;
V_490 = V_237 [ 14 ] & 0xbf ;
if ( F_98 ( V_148 -> V_13 ) &&
F_198 ( V_148 -> V_13 ) ) {
V_68 -> V_245 = V_395 ;
V_68 -> V_162 = V_492 ;
V_68 -> V_203 = V_493 & 0x1f ;
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_164 = V_273 & 0xff ;
V_68 -> V_398 = ( V_273 >> 8 ) & 0xff ;
V_68 -> V_448 = V_494 | ( V_490 << 8 ) ;
} else {
V_68 -> V_162 = V_495 ;
V_68 -> V_164 = V_494 ;
V_68 -> V_245 = V_393 ;
V_68 -> V_398 = V_490 ;
V_68 -> V_203 = ( V_273 >> 8 ) & 0xff ;
V_68 -> V_198 = V_273 & 0xff ;
}
V_68 -> V_1 = V_249 ;
V_68 -> V_201 = ( V_207 >> 16 ) & 0xff ;
V_68 -> V_200 = ( V_207 >> 8 ) & 0xff ;
V_68 -> V_199 = V_207 & 0xff ;
V_68 -> V_206 = ( V_207 >> 40 ) & 0xff ;
V_68 -> V_205 = ( V_207 >> 32 ) & 0xff ;
V_68 -> V_204 = ( V_207 >> 24 ) & 0xff ;
V_68 -> V_16 |= V_244 | V_243 | V_202 ;
V_148 -> V_16 |= V_431 ;
F_63 ( V_148 ) ;
V_148 -> V_298 = F_188 ;
return 0 ;
V_242:
F_28 ( V_148 -> V_13 , V_157 , V_239 , V_240 ) ;
return 1 ;
V_445:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
}
static unsigned int F_199 ( struct V_147 * V_148 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_56 * V_157 = V_148 -> V_151 ;
struct V_12 * V_13 = V_148 -> V_13 ;
const T_3 * V_237 = V_157 -> V_238 ;
T_3 V_496 , V_489 ;
T_4 V_207 ;
T_8 V_266 ;
T_5 V_239 = ( T_5 ) - 1 ;
if ( F_20 ( V_157 -> V_241 < 16 ) ) {
V_239 = 15 ;
goto V_242;
}
V_489 = V_237 [ 1 ] & 0x1f ;
if ( ( V_489 != V_497 ) && ( V_489 != V_498 ) &&
( V_489 != V_499 ) && ( V_489 != V_500 ) ) {
V_239 = 1 ;
goto V_242;
}
F_106 ( V_237 , & V_207 , & V_266 ) ;
if ( V_266 ) {
goto V_445;
}
if ( V_207 > V_13 -> V_94 )
goto V_270;
V_496 = V_237 [ 14 ] & 0x1 ;
if ( F_98 ( V_148 -> V_13 ) &&
F_200 ( V_148 -> V_13 ) ) {
V_68 -> V_245 = V_397 ;
V_68 -> V_162 = V_501 ;
V_68 -> V_164 = V_502 ;
V_68 -> V_198 = V_148 -> V_150 << 3 ;
V_68 -> V_448 = V_489 | ( ( T_5 ) V_496 << 8 ) ;
} else {
V_68 -> V_245 = V_246 ;
V_68 -> V_162 = V_503 ;
V_68 -> V_164 = V_489 ;
V_68 -> V_398 = V_496 ;
}
V_68 -> V_201 = ( V_207 >> 16 ) & 0xff ;
V_68 -> V_200 = ( V_207 >> 8 ) & 0xff ;
V_68 -> V_199 = V_207 & 0xff ;
V_68 -> V_206 = ( V_207 >> 40 ) & 0xff ;
V_68 -> V_205 = ( V_207 >> 32 ) & 0xff ;
V_68 -> V_204 = ( V_207 >> 24 ) & 0xff ;
V_68 -> V_1 = V_249 ;
V_68 -> V_16 |= V_244 | V_243 | V_202 ;
return 0 ;
V_242:
F_28 ( V_148 -> V_13 , V_157 , V_239 , 0xff ) ;
return 1 ;
V_270:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x21 , 0x00 ) ;
return 1 ;
V_445:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
}
static int F_201 ( struct V_147 * V_148 ,
const T_3 * V_4 , int V_45 , T_5 * V_239 )
{
struct V_67 * V_68 = & V_148 -> V_68 ;
struct V_12 * V_13 = V_148 -> V_13 ;
T_3 V_504 [ V_505 ] ;
T_3 V_506 ;
int V_183 ;
if ( V_45 != V_505 - 2 ) {
if ( V_45 < V_505 - 2 )
* V_239 = V_45 ;
else
* V_239 = V_505 - 2 ;
return - V_20 ;
}
V_506 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_146 ( V_13 -> V_102 , V_504 , false ) ;
for ( V_183 = 0 ; V_183 < V_505 - 2 ; V_183 ++ ) {
if ( V_183 == 0 )
continue;
if ( V_504 [ V_183 + 2 ] != V_4 [ V_183 ] ) {
* V_239 = V_183 ;
return - V_20 ;
}
}
V_68 -> V_16 |= V_243 | V_244 ;
V_68 -> V_245 = V_246 ;
V_68 -> V_198 = 0 ;
V_68 -> V_162 = V_434 ;
V_68 -> V_164 = V_506 ? V_507 : V_508 ;
return 0 ;
}
static int F_202 ( struct V_147 * V_148 ,
const T_3 * V_4 , int V_45 , T_5 * V_239 )
{
struct V_12 * V_13 = V_148 -> V_13 ;
T_3 V_504 [ V_509 ] ;
T_3 V_61 ;
int V_183 ;
if ( V_45 != V_509 - 2 ) {
if ( V_45 < V_509 - 2 )
* V_239 = V_45 ;
else
* V_239 = V_509 - 2 ;
return - V_20 ;
}
V_61 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_149 ( V_13 , V_504 , false ) ;
for ( V_183 = 0 ; V_183 < V_509 - 2 ; V_183 ++ ) {
if ( V_183 == 0 )
continue;
if ( V_504 [ 2 + V_183 ] != V_4 [ V_183 ] ) {
* V_239 = V_183 ;
return - V_20 ;
}
}
if ( V_61 & ( 1 << 2 ) )
V_13 -> V_16 |= V_62 ;
else
V_13 -> V_16 &= ~ V_62 ;
return 0 ;
}
static unsigned int F_203 ( struct V_147 * V_148 )
{
struct V_56 * V_157 = V_148 -> V_151 ;
const T_3 * V_237 = V_157 -> V_238 ;
const T_3 * V_347 ;
T_3 V_349 , V_350 ;
unsigned V_353 , V_510 , V_511 , V_512 ;
int V_45 ;
T_5 V_239 = ( T_5 ) - 1 ;
T_3 V_240 = 0xff ;
F_104 ( L_32 ) ;
V_353 = ( V_237 [ 0 ] == V_465 ) ;
if ( V_353 ) {
if ( V_157 -> V_241 < 5 ) {
V_239 = 4 ;
goto V_242;
}
V_45 = V_237 [ 4 ] ;
V_511 = 4 ;
} else {
if ( V_157 -> V_241 < 9 ) {
V_239 = 8 ;
goto V_242;
}
V_45 = ( V_237 [ 7 ] << 8 ) + V_237 [ 8 ] ;
V_511 = 8 ;
}
if ( ( V_237 [ 1 ] & 0x11 ) != 0x10 ) {
V_239 = 1 ;
V_240 = ( V_237 [ 1 ] & 0x01 ) ? 1 : 5 ;
goto V_242;
}
if ( ! F_62 ( V_157 ) || F_61 ( V_157 ) -> V_482 < V_45 )
goto V_445;
V_347 = F_204 ( F_205 ( F_61 ( V_157 ) ) ) ;
if ( V_45 < V_511 )
goto V_445;
if ( V_353 )
V_512 = V_347 [ 3 ] ;
else
V_512 = ( V_347 [ 6 ] << 8 ) + V_347 [ 7 ] ;
V_45 -= V_511 ;
V_347 += V_511 ;
if ( V_45 < V_512 )
goto V_445;
if ( V_512 != 0 && V_512 != 8 ) {
V_239 = ( V_353 ) ? 3 : 6 ;
V_239 += V_512 + V_511 ;
goto V_513;
}
V_45 -= V_512 ;
V_347 += V_512 ;
if ( V_45 == 0 )
goto V_254;
V_349 = V_347 [ 0 ] & 0x3f ;
if ( V_347 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_445;
V_350 = V_347 [ 1 ] ;
V_510 = ( V_347 [ 2 ] << 8 ) | V_347 [ 3 ] ;
V_347 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_445;
V_350 = 0 ;
V_510 = V_347 [ 1 ] ;
V_347 += 2 ;
V_45 -= 2 ;
}
if ( V_350 && ( V_350 != V_357 ) ) {
V_239 = ( V_347 [ 0 ] & 0x40 ) ? 1 : 0 ;
V_239 += V_511 + V_512 ;
goto V_513;
}
if ( V_510 > V_45 )
goto V_445;
switch ( V_349 ) {
case V_359 :
if ( F_201 ( V_148 , V_347 , V_510 , & V_239 ) < 0 ) {
V_239 += V_511 + V_512 ;
goto V_513;
}
break;
case V_360 :
if ( F_202 ( V_148 , V_347 , V_510 , & V_239 ) < 0 ) {
V_239 += V_511 + V_512 ;
goto V_513;
} else {
goto V_254;
}
break;
default:
V_239 = V_512 + V_511 ;
goto V_513;
}
if ( V_45 > V_510 )
goto V_513;
return 0 ;
V_242:
F_28 ( V_148 -> V_13 , V_157 , V_239 , V_240 ) ;
return 1 ;
V_513:
F_30 ( V_148 -> V_13 , V_157 , V_239 ) ;
return 1 ;
V_445:
F_23 ( V_148 -> V_13 , V_157 , V_74 , 0x1a , 0x0 ) ;
return 1 ;
V_254:
V_157 -> V_63 = V_257 ;
return 1 ;
}
static inline T_9 F_206 ( struct V_12 * V_13 , T_3 V_57 )
{
switch ( V_57 ) {
case V_286 :
case V_284 :
case V_287 :
case V_281 :
case V_280 :
case V_282 :
return F_111 ;
case V_468 :
return F_184 ;
case V_458 :
if ( F_207 ( V_13 ) )
return F_102 ;
break;
case V_267 :
case V_268 :
return F_107 ;
case V_290 :
case V_126 :
return F_174 ;
case V_465 :
case V_466 :
return F_203 ;
break;
case V_469 :
return F_197 ;
case V_470 :
return F_199 ;
case V_467 :
return F_100 ;
}
return NULL ;
}
static inline void F_208 ( struct V_8 * V_9 ,
struct V_56 * V_57 )
{
#ifdef F_209
struct V_28 * V_111 = V_57 -> V_1 ;
F_110 ( L_55 ,
V_9 -> V_197 ,
V_111 -> V_390 , V_111 -> V_102 , V_111 -> V_391 ,
V_57 -> V_238 ) ;
#endif
}
static inline int F_210 ( struct V_56 * V_157 ,
struct V_12 * V_13 )
{
T_3 V_514 = V_157 -> V_238 [ 0 ] ;
T_9 V_292 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 || V_13 -> V_49 == V_51 ) {
if ( F_20 ( ! V_157 -> V_241 || V_157 -> V_241 > V_13 -> V_374 ) )
goto V_515;
V_292 = F_206 ( V_13 , V_514 ) ;
} else {
if ( F_20 ( ! V_157 -> V_241 ) )
goto V_515;
V_292 = NULL ;
if ( F_75 ( ( V_514 != V_126 ) || ! V_516 ) ) {
int V_45 = F_211 ( V_514 ) ;
if ( F_20 ( V_45 > V_157 -> V_241 || V_45 > V_13 -> V_374 ) )
goto V_515;
V_292 = F_167 ;
} else {
if ( F_20 ( V_157 -> V_241 > 16 ) )
goto V_515;
V_292 = F_206 ( V_13 , V_514 ) ;
}
}
if ( V_292 )
V_33 = F_117 ( V_13 , V_157 , V_292 ) ;
else
F_212 ( V_13 , V_157 ) ;
return V_33 ;
V_515:
F_110 ( L_56 ,
V_157 -> V_241 , V_514 , V_13 -> V_374 ) ;
V_157 -> V_63 = V_302 << 16 ;
V_157 -> V_89 ( V_157 ) ;
return 0 ;
}
int F_213 ( struct V_6 * V_7 , struct V_56 * V_57 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_111 = V_57 -> V_1 ;
int V_33 = 0 ;
unsigned long V_517 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_517 ) ;
F_208 ( V_9 , V_57 ) ;
V_13 = F_14 ( V_9 , V_111 ) ;
if ( F_75 ( V_13 ) )
V_33 = F_210 ( V_57 , V_13 ) ;
else {
V_57 -> V_63 = ( V_518 << 16 ) ;
V_57 -> V_89 ( V_57 ) ;
}
F_9 ( V_9 -> V_21 , V_517 ) ;
return V_33 ;
}
void F_212 ( struct V_12 * V_13 , struct V_56 * V_57 )
{
struct V_311 args ;
const T_3 * V_151 = V_57 -> V_238 ;
T_3 V_519 ;
args . V_13 = V_13 ;
args . V_102 = V_13 -> V_102 ;
args . V_57 = V_57 ;
args . F_114 = V_57 -> V_89 ;
switch( V_151 [ 0 ] ) {
case V_382 :
if ( V_151 [ 1 ] & 2 )
F_37 ( V_13 , V_57 , 1 ) ;
else if ( ( V_151 [ 1 ] & 1 ) == 0 )
F_214 ( & args , F_124 ) ;
else switch ( V_151 [ 2 ] ) {
case 0x00 :
F_214 ( & args , F_127 ) ;
break;
case 0x80 :
F_214 ( & args , F_128 ) ;
break;
case 0x83 :
F_214 ( & args , F_129 ) ;
break;
case 0x89 :
F_214 ( & args , F_131 ) ;
break;
case 0xb0 :
F_214 ( & args , F_133 ) ;
break;
case 0xb1 :
F_214 ( & args , F_139 ) ;
break;
case 0xb2 :
F_214 ( & args , F_142 ) ;
break;
case 0xb6 :
if ( V_13 -> V_16 & V_321 ) {
F_214 ( & args , F_143 ) ;
break;
}
default:
F_37 ( V_13 , V_57 , 2 ) ;
break;
}
break;
case V_355 :
case V_455 :
F_214 ( & args , F_154 ) ;
break;
case V_368 :
F_214 ( & args , F_155 ) ;
break;
case V_456 :
if ( ( V_151 [ 1 ] & 0x1f ) == V_520 )
F_214 ( & args , F_155 ) ;
else
F_37 ( V_13 , V_57 , 1 ) ;
break;
case V_457 :
F_214 ( & args , F_159 ) ;
break;
case V_375 :
F_23 ( V_13 , V_57 , 0 , 0 , 0 ) ;
V_57 -> V_63 = ( V_64 << 24 ) ;
V_57 -> V_89 ( V_57 ) ;
break;
case V_458 :
case V_459 :
case V_460 :
case V_461 :
case V_462 :
F_214 ( & args , F_144 ) ;
break;
case V_463 :
V_519 = V_151 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_519 == 0x4 ) && ( ! V_151 [ 3 ] ) && ( ! V_151 [ 4 ] ) )
F_214 ( & args , F_144 ) ;
else
F_37 ( V_13 , V_57 , 1 ) ;
break;
case V_464 :
if ( V_151 [ 1 ] == V_521 )
F_214 ( & args , F_187 ) ;
else
F_37 ( V_13 , V_57 , 1 ) ;
break;
default:
F_23 ( V_13 , V_57 , V_74 , 0x20 , 0x0 ) ;
V_57 -> V_89 ( V_57 ) ;
break;
}
}
int F_215 ( struct V_522 * V_34 , struct V_523 * V_524 )
{
int V_183 , V_33 ;
for ( V_183 = 0 ; V_183 < V_34 -> V_525 ; V_183 ++ ) {
struct V_8 * V_9 = V_34 -> V_526 [ V_183 ] ;
struct V_6 * V_7 ;
V_33 = - V_121 ;
V_7 = F_216 ( V_524 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_527;
V_7 -> V_528 = 1 ;
* (struct V_8 * * ) & V_7 -> V_529 [ 0 ] = V_9 ;
V_9 -> V_530 = V_7 ;
V_7 -> V_531 = V_532 ;
V_7 -> V_533 = V_9 -> V_197 ;
V_7 -> V_534 = 16 ;
V_7 -> V_535 = 1 ;
V_7 -> V_536 = 1 ;
V_7 -> V_537 = 16 ;
V_7 -> V_538 = 1 ;
V_33 = F_217 ( V_9 -> V_530 ,
& V_9 -> V_539 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_540;
}
return 0 ;
V_540:
F_218 ( V_34 -> V_526 [ V_183 ] -> V_530 ) ;
V_527:
while ( -- V_183 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_526 [ V_183 ] -> V_530 ;
F_219 ( V_7 ) ;
F_218 ( V_7 ) ;
}
return V_33 ;
}
void F_220 ( struct V_8 * V_9 , int V_541 )
{
int V_542 = 5 ;
struct V_12 * V_543 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_544:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_390 = 0 , V_102 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_221 ( V_11 ) )
V_102 = V_13 -> V_43 ;
else
V_390 = V_11 -> V_545 ;
V_29 = F_222 ( V_9 -> V_530 , V_390 , V_102 , 0 ,
NULL ) ;
if ( ! F_223 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_224 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_546;
}
}
V_546:
if ( ! V_11 )
return;
if ( V_541 ) {
if ( V_13 != V_543 ) {
F_225 ( 100 ) ;
V_543 = V_13 ;
goto V_544;
}
if ( -- V_542 ) {
F_225 ( 100 ) ;
goto V_544;
}
F_226 ( V_9 ,
L_57 ) ;
}
F_227 ( V_547 , & V_9 -> V_548 ,
F_228 ( V_128 ) ) ;
}
int F_229 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_230 ( V_13 -> V_29 , V_549 ) ;
return 1 ;
}
return 0 ;
}
static void F_231 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_232 ( & V_9 -> V_530 -> V_550 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_233 ( V_29 ) == 0 ) {
F_230 ( V_29 , V_549 ) ;
} else {
F_178 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_234 ( & V_9 -> V_530 -> V_550 ) ;
if ( V_29 ) {
F_158 ( V_13 , L_58 ,
F_235 ( & V_29 -> V_551 ) ) ;
F_236 ( V_29 ) ;
F_224 ( V_29 ) ;
}
}
static void F_237 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_552 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_552 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_238 ( V_13 ) )
F_239 ( V_13 ) ;
F_231 ( V_13 ) ;
}
}
void F_240 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_241 ( V_13 -> V_29 , V_226 ,
V_553 ) ;
}
void F_242 ( struct V_554 * V_555 )
{
struct V_8 * V_9 =
F_243 ( V_555 , struct V_8 , V_548 . V_555 ) ;
int V_183 ;
if ( V_9 -> V_39 & V_556 ) {
F_110 ( L_59 ) ;
return;
}
#ifdef F_244
while ( V_557 )
F_225 ( 10 ) ;
#endif
F_110 ( L_32 ) ;
F_232 ( & V_9 -> V_558 ) ;
F_237 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_389 )
for ( V_183 = 0 ; V_183 < V_559 ; V_183 ++ )
F_237 ( & V_9 -> V_389 [ V_183 ] ) ;
F_220 ( V_9 , 0 ) ;
F_234 ( & V_9 -> V_558 ) ;
F_110 ( L_34 ) ;
}
int F_245 ( struct V_6 * V_7 , unsigned int V_390 ,
unsigned int V_102 , T_4 V_391 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_75 -> V_195 )
return - V_24 ;
if ( V_391 != V_560 && V_391 )
return - V_20 ;
if ( ! F_171 ( V_9 ) ) {
if ( V_390 != V_560 && V_390 )
return - V_20 ;
V_43 = V_102 ;
} else {
if ( V_102 != V_560 && V_102 )
return - V_20 ;
V_43 = V_390 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_560 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_561 * V_562 = & V_11 -> V_52 ;
V_562 -> V_563 |= V_564 ;
V_562 -> V_97 |= V_98 ;
}
} else {
struct V_12 * V_13 = F_170 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_561 * V_562 = & V_13 -> V_11 -> V_52 ;
V_562 -> V_563 |= 1 << V_13 -> V_43 ;
V_562 -> V_97 |= V_98 ;
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
void F_246 ( struct V_554 * V_555 )
{
struct V_8 * V_9 =
F_243 ( V_555 , struct V_8 , V_565 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_232 ( & V_9 -> V_558 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_233 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_247 ( & ( V_29 -> V_551 ) ) ;
F_224 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_234 ( & V_9 -> V_558 ) ;
}
struct V_8 * F_248 ( struct V_522 * V_34 ,
struct V_566 * V_567 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_249 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_568 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_569 = V_567 -> V_569 ;
V_9 -> V_570 = V_567 -> V_570 ;
V_9 -> V_571 = V_567 -> V_571 ;
V_9 -> V_16 |= V_567 -> V_16 ;
V_9 -> V_75 = V_567 -> V_572 ;
V_9 -> V_573 = V_574 ;
return V_9 ;
}
int F_250 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_75 -> V_195 )
V_9 -> V_39 &= ~ V_575 ;
return 0 ;
}
void F_251 ( struct V_8 * V_9 )
{
}
void F_252 ( struct V_8 * V_9 )
{
F_253 ( V_9 ) ;
}
int F_254 ( struct V_8 * V_9 )
{
return F_255 ( V_9 ) ;
}
int F_256 ( struct V_8 * V_9 )
{
int V_33 = V_9 -> V_75 -> V_576 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_197 = F_257 ( & V_577 ) ;
return 0 ;
}
void F_258 ( struct V_8 * V_9 )
{
if ( V_9 -> V_75 -> V_578 )
V_9 -> V_75 -> V_578 ( V_9 ) ;
F_52 ( V_9 ) ;
}
int F_259 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_73 ( V_29 ) ;
F_80 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_260 ( struct V_56 * V_57 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_208 ( V_9 , V_57 ) ;
if ( F_75 ( F_97 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_210 ( V_57 , V_9 -> V_11 . V_1 ) ;
else {
V_57 -> V_63 = ( V_518 << 16 ) ;
V_57 -> V_89 ( V_57 ) ;
}
return V_33 ;
}
int F_261 ( struct V_8 * V_9 )
{
unsigned int V_579 = V_9 -> V_34 -> V_580 ;
unsigned int V_183 , V_150 ;
for ( V_183 = 0 , V_150 = V_9 -> V_581 + 1 ; V_183 < V_579 ; V_183 ++ , V_150 ++ ) {
V_150 = V_150 < V_579 ? V_150 : 0 ;
if ( V_150 == V_582 )
continue;
if ( ! F_262 ( V_150 , & V_9 -> V_583 ) ) {
V_9 -> V_581 = V_150 ;
return V_150 ;
}
}
return - 1 ;
}
void F_263 ( unsigned int V_150 , struct V_8 * V_9 )
{
F_264 ( V_150 , & V_9 -> V_583 ) ;
}
