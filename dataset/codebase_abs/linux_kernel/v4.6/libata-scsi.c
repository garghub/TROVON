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
static void F_23 ( struct V_56 * V_57 , T_3 V_58 , T_3 V_59 , T_3 V_60 )
{
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
F_24 ( 0 , V_57 -> V_64 , V_58 , V_59 , V_60 ) ;
}
static T_1
F_25 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_65 -> V_66 && ( V_9 -> V_16 & V_67 ) )
return V_9 -> V_65 -> V_66 ( V_9 , V_4 , V_5 ) ;
return - V_20 ;
}
static T_1
F_26 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_65 -> V_68 && ( V_9 -> V_16 & V_67 ) )
return V_9 -> V_65 -> V_68 ( V_9 , V_4 ) ;
return - V_20 ;
}
static T_1
F_27 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_4 , 23 , L_3 , V_9 -> V_69 ) ;
}
static T_1
F_28 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_70 = F_14 ( V_9 , V_29 ) ;
if ( V_70 && V_9 -> V_65 -> V_71 &&
( V_9 -> V_16 & V_72 ) )
return V_9 -> V_65 -> V_71 ( V_70 , V_4 ) ;
return - V_20 ;
}
static T_1
F_29 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_70 = F_14 ( V_9 , V_29 ) ;
enum V_73 V_74 ;
int V_33 ;
if ( V_70 && V_9 -> V_65 -> V_75 &&
( V_9 -> V_16 & V_72 ) ) {
V_74 = F_30 ( V_4 , NULL , 0 ) ;
switch ( V_74 ) {
case V_76 : case V_77 : case V_78 :
V_33 = V_9 -> V_65 -> V_75 ( V_70 , V_74 ) ;
if ( ! V_33 )
return V_5 ;
else
return V_33 ;
}
}
return - V_20 ;
}
static void F_31 ( struct V_56 * V_57 )
{
F_23 ( V_57 , V_79 , 0x24 , 0x0 ) ;
V_57 -> V_80 ( V_57 ) ;
}
int F_32 ( struct V_28 * V_29 , struct V_81 * V_82 ,
T_4 V_83 , int V_84 [] )
{
V_84 [ 0 ] = 255 ;
V_84 [ 1 ] = 63 ;
F_33 ( V_83 , 255 * 63 ) ;
V_84 [ 2 ] = V_83 ;
return 0 ;
}
void F_34 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_85 < V_13 -> V_86 ) {
V_13 -> V_16 |= V_87 ;
V_13 -> V_11 -> V_52 . V_88 |= V_89 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_35 ( V_9 ) ;
}
static int F_36 ( struct V_8 * V_9 , struct V_28 * V_29 ,
void T_5 * V_90 )
{
struct V_12 * V_13 = F_14 ( V_9 , V_29 ) ;
T_6 T_5 * V_91 = V_90 ;
char V_4 [ 40 ] ;
if ( ! V_13 )
return - V_92 ;
if ( F_37 ( V_91 , V_13 -> V_93 , V_94 * sizeof( T_6 ) ) )
return - V_95 ;
F_38 ( V_13 -> V_93 , V_4 , V_96 , V_97 ) ;
if ( F_37 ( V_91 + V_96 , V_4 , V_97 ) )
return - V_95 ;
F_38 ( V_13 -> V_93 , V_4 , V_98 , V_99 ) ;
if ( F_37 ( V_91 + V_98 , V_4 , V_99 ) )
return - V_95 ;
F_38 ( V_13 -> V_93 , V_4 , V_100 , V_101 ) ;
if ( F_37 ( V_91 + V_100 , V_4 , V_101 ) )
return - V_95 ;
return 0 ;
}
int F_39 ( struct V_28 * V_102 , void T_5 * V_90 )
{
int V_33 = 0 ;
T_3 V_103 [ V_104 ] ;
T_3 args [ 4 ] , * V_105 = NULL , * V_106 = NULL ;
int V_107 = 0 ;
enum V_108 V_109 ;
int V_110 ;
if ( V_90 == NULL )
return - V_20 ;
if ( F_40 ( args , V_90 , sizeof( args ) ) )
return - V_95 ;
V_106 = F_41 ( V_111 , V_112 ) ;
if ( ! V_106 )
return - V_113 ;
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
if ( args [ 3 ] ) {
V_107 = V_114 * args [ 3 ] ;
V_105 = F_42 ( V_107 , V_115 ) ;
if ( V_105 == NULL ) {
V_33 = - V_113 ;
goto error;
}
V_103 [ 1 ] = ( 4 << 1 ) ;
V_103 [ 2 ] = 0x0e ;
V_109 = V_116 ;
} else {
V_103 [ 1 ] = ( 3 << 1 ) ;
V_103 [ 2 ] = 0x20 ;
V_109 = V_117 ;
}
V_103 [ 0 ] = V_118 ;
V_103 [ 4 ] = args [ 2 ] ;
if ( args [ 0 ] == V_119 ) {
V_103 [ 6 ] = args [ 3 ] ;
V_103 [ 8 ] = args [ 1 ] ;
V_103 [ 10 ] = 0x4f ;
V_103 [ 12 ] = 0xc2 ;
} else {
V_103 [ 6 ] = args [ 1 ] ;
}
V_103 [ 14 ] = args [ 0 ] ;
V_110 = F_43 ( V_102 , V_103 , V_109 , V_105 , V_107 ,
V_106 , ( 10 * V_120 ) , 5 , 0 , NULL ) ;
if ( F_44 ( V_110 ) == V_62 ) {
T_3 * V_121 = V_106 + 8 ;
V_110 &= ~ ( 0xFF << 24 ) ;
if ( V_110 & V_63 ) {
struct V_122 V_123 ;
F_45 ( V_106 , V_111 ,
& V_123 ) ;
if ( V_123 . V_124 == V_125 &&
V_123 . V_59 == 0 && V_123 . V_60 == 0x1d )
V_110 &= ~ V_63 ;
}
if ( V_106 [ 0 ] == 0x72 &&
V_121 [ 0 ] == 0x09 ) {
args [ 0 ] = V_121 [ 13 ] ;
args [ 1 ] = V_121 [ 3 ] ;
args [ 2 ] = V_121 [ 5 ] ;
if ( F_37 ( V_90 , args , sizeof( args ) ) )
V_33 = - V_95 ;
}
}
if ( V_110 ) {
V_33 = - V_126 ;
goto error;
}
if ( ( V_105 )
&& F_37 ( V_90 + sizeof( args ) , V_105 , V_107 ) )
V_33 = - V_95 ;
error:
F_46 ( V_106 ) ;
F_46 ( V_105 ) ;
return V_33 ;
}
int F_47 ( struct V_28 * V_102 , void T_5 * V_90 )
{
int V_33 = 0 ;
T_3 V_103 [ V_104 ] ;
T_3 args [ 7 ] , * V_106 = NULL ;
int V_110 ;
if ( V_90 == NULL )
return - V_20 ;
if ( F_40 ( args , V_90 , sizeof( args ) ) )
return - V_95 ;
V_106 = F_41 ( V_111 , V_112 ) ;
if ( ! V_106 )
return - V_113 ;
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
V_103 [ 0 ] = V_118 ;
V_103 [ 1 ] = ( 3 << 1 ) ;
V_103 [ 2 ] = 0x20 ;
V_103 [ 4 ] = args [ 1 ] ;
V_103 [ 6 ] = args [ 2 ] ;
V_103 [ 8 ] = args [ 3 ] ;
V_103 [ 10 ] = args [ 4 ] ;
V_103 [ 12 ] = args [ 5 ] ;
V_103 [ 13 ] = args [ 6 ] & 0x4f ;
V_103 [ 14 ] = args [ 0 ] ;
V_110 = F_43 ( V_102 , V_103 , V_117 , NULL , 0 ,
V_106 , ( 10 * V_120 ) , 5 , 0 , NULL ) ;
if ( F_44 ( V_110 ) == V_62 ) {
T_3 * V_121 = V_106 + 8 ;
V_110 &= ~ ( 0xFF << 24 ) ;
if ( V_110 & V_63 ) {
struct V_122 V_123 ;
F_45 ( V_106 , V_111 ,
& V_123 ) ;
if ( V_123 . V_124 == V_125 &&
V_123 . V_59 == 0 && V_123 . V_60 == 0x1d )
V_110 &= ~ V_63 ;
}
if ( V_106 [ 0 ] == 0x72 &&
V_121 [ 0 ] == 0x09 ) {
args [ 0 ] = V_121 [ 13 ] ;
args [ 1 ] = V_121 [ 3 ] ;
args [ 2 ] = V_121 [ 5 ] ;
args [ 3 ] = V_121 [ 7 ] ;
args [ 4 ] = V_121 [ 9 ] ;
args [ 5 ] = V_121 [ 11 ] ;
args [ 6 ] = V_121 [ 12 ] ;
if ( F_37 ( V_90 , args , sizeof( args ) ) )
V_33 = - V_95 ;
}
}
if ( V_110 ) {
V_33 = - V_126 ;
goto error;
}
error:
F_46 ( V_106 ) ;
return V_33 ;
}
static int F_48 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 & V_127 )
return 1 ;
if ( V_9 -> V_39 & V_128 )
return 1 ;
return 0 ;
}
int F_49 ( struct V_8 * V_9 , struct V_28 * V_102 ,
int V_57 , void T_5 * V_90 )
{
unsigned long V_74 ;
int V_33 = - V_20 ;
unsigned long V_16 ;
switch ( V_57 ) {
case V_129 :
F_5 ( V_9 -> V_21 , V_16 ) ;
V_74 = F_48 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
return F_50 ( V_74 , ( unsigned long T_5 * ) V_90 ) ;
case V_130 :
V_74 = ( unsigned long ) V_90 ;
V_33 = 0 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_9 -> V_39 & V_131 ) {
if ( V_74 )
V_9 -> V_39 |= V_128 ;
else
V_9 -> V_39 &= ~ V_128 ;
} else {
if ( V_74 != F_48 ( V_9 ) )
V_33 = - V_20 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
case V_132 :
return F_36 ( V_9 , V_102 , V_90 ) ;
case V_133 :
if ( ! F_51 ( V_134 ) || ! F_51 ( V_135 ) )
return - V_136 ;
return F_39 ( V_102 , V_90 ) ;
case V_137 :
if ( ! F_51 ( V_134 ) || ! F_51 ( V_135 ) )
return - V_136 ;
return F_47 ( V_102 , V_90 ) ;
default:
V_33 = - V_138 ;
break;
}
return V_33 ;
}
int F_52 ( struct V_28 * V_102 , int V_57 , void T_5 * V_90 )
{
return F_49 ( F_3 ( V_102 -> V_34 ) ,
V_102 , V_57 , V_90 ) ;
}
static struct V_139 * F_53 ( struct V_12 * V_13 ,
struct V_56 * V_57 )
{
struct V_139 * V_140 ;
V_140 = F_54 ( V_13 , V_57 -> V_141 -> V_142 ) ;
if ( V_140 ) {
V_140 -> V_143 = V_57 ;
V_140 -> V_144 = V_57 -> V_80 ;
V_140 -> V_145 = F_55 ( V_57 ) ;
V_140 -> V_146 = F_56 ( V_57 ) ;
} else {
V_57 -> V_61 = ( V_147 << 16 ) | ( V_148 << 1 ) ;
V_57 -> V_80 ( V_57 ) ;
}
return V_140 ;
}
static void F_57 ( struct V_139 * V_140 )
{
struct V_56 * V_149 = V_140 -> V_143 ;
V_140 -> V_150 = V_149 -> V_141 -> V_151 ;
V_140 -> V_152 = F_58 ( V_149 ) + V_140 -> V_150 ;
}
static void F_59 ( unsigned V_93 , struct V_153 * V_154 )
{
T_3 V_155 = V_154 -> V_156 , V_157 = V_154 -> V_158 ;
F_60 ( V_159 L_4 , V_93 , V_155 ) ;
if ( V_155 & V_160 ) {
F_60 ( L_5 ) ;
} else {
if ( V_155 & V_161 ) F_60 ( L_6 ) ;
if ( V_155 & V_162 ) F_60 ( L_7 ) ;
if ( V_155 & V_163 ) F_60 ( L_8 ) ;
if ( V_155 & V_164 ) F_60 ( L_9 ) ;
if ( V_155 & V_165 ) F_60 ( L_10 ) ;
if ( V_155 & V_166 ) F_60 ( L_11 ) ;
if ( V_155 & V_167 ) F_60 ( L_12 ) ;
F_60 ( L_13 ) ;
if ( V_157 ) {
F_60 ( V_159 L_14 , V_93 , V_157 ) ;
if ( V_157 & V_168 ) F_60 ( L_15 ) ;
if ( V_157 & V_169 ) {
if ( V_157 & V_168 )
F_60 ( L_16 ) ;
else F_60 ( L_17 ) ;
}
if ( V_157 & V_170 ) F_60 ( L_18 ) ;
if ( V_157 & V_171 ) F_60 ( L_19 ) ;
if ( V_157 & V_172 ) F_60 ( L_20 ) ;
if ( V_157 & V_173 ) F_60 ( L_21 ) ;
F_60 ( L_13 ) ;
}
}
}
static void F_61 ( unsigned V_93 , T_3 V_174 , T_3 V_175 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 , int V_176 )
{
int V_177 ;
static const unsigned char V_178 [] [ 4 ] = {
{ 0xd1 , V_179 , 0x00 , 0x00 } ,
{ 0xd0 , V_179 , 0x00 , 0x00 } ,
{ 0x61 , V_180 , 0x00 , 0x00 } ,
{ 0x84 , V_179 , 0x47 , 0x00 } ,
{ 0x37 , V_181 , 0x04 , 0x00 } ,
{ 0x09 , V_181 , 0x04 , 0x00 } ,
{ 0x01 , V_182 , 0x13 , 0x00 } ,
{ 0x02 , V_180 , 0x00 , 0x00 } ,
{ 0x08 , V_181 , 0x04 , 0x00 } ,
{ 0x10 , V_79 , 0x21 , 0x00 } ,
{ 0x20 , V_183 , 0x28 , 0x00 } ,
{ 0x40 , V_182 , 0x11 , 0x04 } ,
{ 0x80 , V_182 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_184 [] [ 4 ] = {
{ 0x80 , V_179 , 0x47 , 0x00 } ,
{ 0x40 , V_79 , 0x21 , 0x04 } ,
{ 0x20 , V_180 , 0x44 , 0x00 } ,
{ 0x08 , V_179 , 0x47 , 0x00 } ,
{ 0x04 , V_125 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_174 & V_160 ) {
V_175 = 0 ;
}
if ( V_175 ) {
for ( V_177 = 0 ; V_178 [ V_177 ] [ 0 ] != 0xFF ; V_177 ++ ) {
if ( ( V_178 [ V_177 ] [ 0 ] & V_175 ) ==
V_178 [ V_177 ] [ 0 ] ) {
* V_58 = V_178 [ V_177 ] [ 1 ] ;
* V_59 = V_178 [ V_177 ] [ 2 ] ;
* V_60 = V_178 [ V_177 ] [ 3 ] ;
goto V_185;
}
}
}
for ( V_177 = 0 ; V_184 [ V_177 ] [ 0 ] != 0xFF ; V_177 ++ ) {
if ( V_184 [ V_177 ] [ 0 ] & V_174 ) {
* V_58 = V_184 [ V_177 ] [ 1 ] ;
* V_59 = V_184 [ V_177 ] [ 2 ] ;
* V_60 = V_184 [ V_177 ] [ 3 ] ;
goto V_185;
}
}
* V_58 = V_179 ;
* V_59 = 0x00 ;
* V_60 = 0x00 ;
V_185:
if ( V_176 )
F_60 ( V_186 L_22
L_23 ,
V_93 , V_174 , V_175 , * V_58 , * V_59 , * V_60 ) ;
return;
}
static void F_62 ( struct V_139 * V_140 )
{
struct V_56 * V_57 = V_140 -> V_143 ;
struct V_153 * V_154 = & V_140 -> V_187 ;
unsigned char * V_188 = V_57 -> V_64 ;
unsigned char * V_121 = V_188 + 8 ;
int V_176 = V_140 -> V_9 -> V_65 -> V_189 == NULL ;
memset ( V_188 , 0 , V_111 ) ;
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
if ( V_140 -> V_190 ||
V_154 -> V_156 & ( V_160 | V_162 | V_167 | V_164 ) ) {
F_61 ( V_140 -> V_9 -> V_191 , V_154 -> V_156 , V_154 -> V_158 ,
& V_188 [ 1 ] , & V_188 [ 2 ] , & V_188 [ 3 ] , V_176 ) ;
V_188 [ 1 ] &= 0x0f ;
} else {
V_188 [ 1 ] = V_125 ;
V_188 [ 2 ] = 0 ;
V_188 [ 3 ] = 0x1D ;
}
V_188 [ 0 ] = 0x72 ;
V_121 [ 0 ] = 0x09 ;
V_188 [ 7 ] = 14 ;
V_121 [ 1 ] = 12 ;
V_121 [ 2 ] = 0x00 ;
V_121 [ 3 ] = V_154 -> V_158 ;
V_121 [ 5 ] = V_154 -> V_192 ;
V_121 [ 7 ] = V_154 -> V_193 ;
V_121 [ 9 ] = V_154 -> V_194 ;
V_121 [ 11 ] = V_154 -> V_195 ;
V_121 [ 12 ] = V_154 -> V_1 ;
V_121 [ 13 ] = V_154 -> V_156 ;
if ( V_154 -> V_16 & V_196 ) {
V_121 [ 2 ] |= 0x01 ;
V_121 [ 4 ] = V_154 -> V_197 ;
V_121 [ 6 ] = V_154 -> V_198 ;
V_121 [ 8 ] = V_154 -> V_199 ;
V_121 [ 10 ] = V_154 -> V_200 ;
}
}
static void F_63 ( struct V_139 * V_140 )
{
struct V_12 * V_13 = V_140 -> V_13 ;
struct V_56 * V_57 = V_140 -> V_143 ;
struct V_153 * V_154 = & V_140 -> V_187 ;
unsigned char * V_188 = V_57 -> V_64 ;
unsigned char * V_121 = V_188 + 8 ;
int V_176 = V_140 -> V_9 -> V_65 -> V_189 == NULL ;
T_7 V_201 ;
memset ( V_188 , 0 , V_111 ) ;
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
V_188 [ 0 ] = 0x72 ;
if ( V_140 -> V_190 ||
V_154 -> V_156 & ( V_160 | V_162 | V_167 | V_164 ) ) {
F_61 ( V_140 -> V_9 -> V_191 , V_154 -> V_156 , V_154 -> V_158 ,
& V_188 [ 1 ] , & V_188 [ 2 ] , & V_188 [ 3 ] , V_176 ) ;
V_188 [ 1 ] &= 0x0f ;
}
V_201 = F_64 ( & V_140 -> V_187 , V_13 ) ;
V_188 [ 7 ] = 12 ;
V_121 [ 0 ] = 0x00 ;
V_121 [ 1 ] = 10 ;
V_121 [ 2 ] |= 0x80 ;
V_121 [ 6 ] = V_201 >> 40 ;
V_121 [ 7 ] = V_201 >> 32 ;
V_121 [ 8 ] = V_201 >> 24 ;
V_121 [ 9 ] = V_201 >> 16 ;
V_121 [ 10 ] = V_201 >> 8 ;
V_121 [ 11 ] = V_201 ;
}
static void F_65 ( struct V_28 * V_29 )
{
V_29 -> V_202 = 1 ;
V_29 -> V_203 = 1 ;
V_29 -> V_204 = 1 ;
V_29 -> V_205 = 1 ;
V_29 -> V_206 = 1 ;
}
static int F_66 ( struct V_141 * V_207 )
{
if ( F_67 ( V_207 -> V_208 != V_209 ) )
return 0 ;
if ( ! F_68 ( V_207 ) || ( V_207 -> V_210 & V_211 ) )
return 0 ;
return F_69 ( V_207 -> V_57 [ 0 ] ) == V_212 ;
}
static int F_70 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_213 * V_214 = V_29 -> V_213 ;
if ( ! F_71 ( V_13 -> V_93 ) )
V_13 -> V_16 |= V_37 ;
F_72 ( V_214 , V_13 -> V_215 ) ;
if ( V_13 -> V_49 == V_216 ) {
void * V_4 ;
V_29 -> V_217 = V_114 ;
F_73 ( V_214 , V_218 - 1 ) ;
V_4 = F_42 ( V_219 , V_214 -> V_220 | V_115 ) ;
if ( ! V_4 ) {
F_74 ( V_13 , L_24 ) ;
return - V_113 ;
}
F_75 ( V_214 , F_66 , V_4 , V_219 ) ;
} else {
V_29 -> V_217 = F_76 ( V_13 -> V_93 ) ;
V_29 -> V_221 = 1 ;
}
if ( V_29 -> V_217 > V_27 )
F_77 ( V_13 ,
L_25 ,
V_29 -> V_217 ) ;
F_78 ( V_214 , V_29 -> V_217 - 1 ) ;
if ( V_13 -> V_16 & V_222 )
F_79 ( V_223 , V_29 -> V_224 ) ;
if ( V_13 -> V_16 & V_225 ) {
int V_226 ;
V_226 = F_80 ( V_29 -> V_34 -> V_227 , F_81 ( V_13 -> V_93 ) ) ;
V_226 = F_80 ( V_228 - 1 , V_226 ) ;
F_82 ( V_29 , V_226 ) ;
}
F_83 ( V_214 , false ) ;
V_13 -> V_29 = V_29 ;
return 0 ;
}
int F_84 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 = F_85 ( V_9 , V_29 ) ;
int V_33 = 0 ;
F_65 ( V_29 ) ;
if ( V_13 )
V_33 = F_70 ( V_29 , V_13 ) ;
return V_33 ;
}
void F_86 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_213 * V_214 = V_29 -> V_213 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_65 -> V_189 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_85 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_229 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_46 ( V_214 -> V_230 ) ;
V_214 -> V_230 = NULL ;
V_214 -> V_231 = 0 ;
}
int F_87 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_232 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_232 < 1 || V_232 == V_29 -> V_232 )
return V_29 -> V_232 ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_88 ( V_13 ) )
return V_29 -> V_232 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_233 ;
if ( V_232 == 1 || ! F_89 ( V_13 ) ) {
V_13 -> V_16 |= V_233 ;
V_232 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_232 = F_80 ( V_232 , V_29 -> V_34 -> V_227 ) ;
V_232 = F_80 ( V_232 , F_81 ( V_13 -> V_93 ) ) ;
V_232 = F_80 ( V_232 , V_228 - 1 ) ;
if ( V_29 -> V_232 == V_232 )
return - V_20 ;
return F_82 ( V_29 , V_232 ) ;
}
int F_90 ( struct V_28 * V_29 , int V_232 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_87 ( V_9 , V_29 , V_232 ) ;
}
static unsigned int F_91 ( struct V_139 * V_140 )
{
struct V_56 * V_149 = V_140 -> V_143 ;
struct V_153 * V_154 = & V_140 -> V_154 ;
const T_3 * V_234 = V_149 -> V_235 ;
if ( V_149 -> V_236 < 5 )
goto V_237;
V_154 -> V_16 |= V_238 | V_239 ;
V_154 -> V_240 = V_241 ;
if ( V_234 [ 1 ] & 0x1 ) {
;
}
if ( V_234 [ 4 ] & 0x2 )
goto V_237;
if ( ( ( V_234 [ 4 ] >> 4 ) & 0xf ) != 0 )
goto V_237;
if ( V_234 [ 4 ] & 0x1 ) {
V_154 -> V_192 = 1 ;
if ( V_140 -> V_13 -> V_16 & V_242 ) {
V_154 -> V_16 |= V_243 ;
V_154 -> V_195 = 0x0 ;
V_154 -> V_194 = 0x0 ;
V_154 -> V_193 = 0x0 ;
V_154 -> V_1 |= V_244 ;
} else {
V_154 -> V_193 = 0x1 ;
V_154 -> V_194 = 0x0 ;
V_154 -> V_195 = 0x0 ;
}
V_154 -> V_156 = V_245 ;
} else {
if ( ( V_140 -> V_9 -> V_16 & V_246 ) &&
V_247 == V_248 )
goto V_249;
if ( ( V_140 -> V_9 -> V_16 & V_250 ) &&
F_92 () )
goto V_249;
V_154 -> V_156 = V_251 ;
}
return 0 ;
V_237:
F_23 ( V_149 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_249:
V_149 -> V_61 = V_252 ;
return 1 ;
}
static unsigned int F_93 ( struct V_139 * V_140 )
{
struct V_153 * V_154 = & V_140 -> V_154 ;
V_154 -> V_16 |= V_238 ;
V_154 -> V_240 = V_241 ;
if ( V_140 -> V_13 -> V_16 & V_253 )
V_154 -> V_156 = V_254 ;
else
V_154 -> V_156 = V_255 ;
V_140 -> V_16 |= V_256 ;
return 0 ;
}
static void F_94 ( const T_3 * V_234 , T_7 * V_257 , T_8 * V_258 )
{
T_7 V_259 = 0 ;
T_8 V_45 ;
F_95 ( L_26 ) ;
V_259 |= ( ( T_7 ) ( V_234 [ 1 ] & 0x1f ) ) << 16 ;
V_259 |= ( ( T_7 ) V_234 [ 2 ] ) << 8 ;
V_259 |= ( ( T_7 ) V_234 [ 3 ] ) ;
V_45 = V_234 [ 4 ] ;
* V_257 = V_259 ;
* V_258 = V_45 ;
}
static void F_96 ( const T_3 * V_234 , T_7 * V_257 , T_8 * V_258 )
{
T_7 V_259 = 0 ;
T_8 V_45 = 0 ;
F_95 ( L_27 ) ;
V_259 |= ( ( T_7 ) V_234 [ 2 ] ) << 24 ;
V_259 |= ( ( T_7 ) V_234 [ 3 ] ) << 16 ;
V_259 |= ( ( T_7 ) V_234 [ 4 ] ) << 8 ;
V_259 |= ( ( T_7 ) V_234 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_234 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_234 [ 8 ] ) ;
* V_257 = V_259 ;
* V_258 = V_45 ;
}
static void F_97 ( const T_3 * V_234 , T_7 * V_257 , T_8 * V_258 )
{
T_7 V_259 = 0 ;
T_8 V_45 = 0 ;
F_95 ( L_28 ) ;
V_259 |= ( ( T_7 ) V_234 [ 2 ] ) << 56 ;
V_259 |= ( ( T_7 ) V_234 [ 3 ] ) << 48 ;
V_259 |= ( ( T_7 ) V_234 [ 4 ] ) << 40 ;
V_259 |= ( ( T_7 ) V_234 [ 5 ] ) << 32 ;
V_259 |= ( ( T_7 ) V_234 [ 6 ] ) << 24 ;
V_259 |= ( ( T_7 ) V_234 [ 7 ] ) << 16 ;
V_259 |= ( ( T_7 ) V_234 [ 8 ] ) << 8 ;
V_259 |= ( ( T_7 ) V_234 [ 9 ] ) ;
V_45 |= ( ( T_8 ) V_234 [ 10 ] ) << 24 ;
V_45 |= ( ( T_8 ) V_234 [ 11 ] ) << 16 ;
V_45 |= ( ( T_8 ) V_234 [ 12 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_234 [ 13 ] ) ;
* V_257 = V_259 ;
* V_258 = V_45 ;
}
static unsigned int F_98 ( struct V_139 * V_140 )
{
struct V_56 * V_149 = V_140 -> V_143 ;
struct V_153 * V_154 = & V_140 -> V_154 ;
struct V_12 * V_13 = V_140 -> V_13 ;
T_7 V_260 = V_140 -> V_13 -> V_85 ;
const T_3 * V_234 = V_149 -> V_235 ;
T_7 V_201 ;
T_8 V_261 ;
V_154 -> V_16 |= V_239 | V_238 ;
V_154 -> V_240 = V_241 ;
if ( V_234 [ 0 ] == V_262 ) {
if ( V_149 -> V_236 < 10 )
goto V_237;
F_96 ( V_234 , & V_201 , & V_261 ) ;
} else if ( V_234 [ 0 ] == V_263 ) {
if ( V_149 -> V_236 < 16 )
goto V_237;
F_97 ( V_234 , & V_201 , & V_261 ) ;
} else
goto V_237;
if ( ! V_261 )
goto V_264;
if ( V_201 >= V_260 )
goto V_265;
if ( ( V_201 + V_261 ) > V_260 )
goto V_265;
if ( V_13 -> V_16 & V_242 ) {
V_154 -> V_16 |= V_243 ;
if ( F_99 ( V_201 , V_261 ) ) {
V_154 -> V_156 = V_245 ;
V_154 -> V_1 |= ( V_201 >> 24 ) & 0xf ;
} else if ( F_100 ( V_201 , V_261 ) ) {
if ( ! ( V_13 -> V_16 & V_266 ) )
goto V_265;
V_154 -> V_16 |= V_196 ;
V_154 -> V_156 = V_267 ;
V_154 -> V_197 = ( V_261 >> 8 ) & 0xff ;
V_154 -> V_200 = ( V_201 >> 40 ) & 0xff ;
V_154 -> V_199 = ( V_201 >> 32 ) & 0xff ;
V_154 -> V_198 = ( V_201 >> 24 ) & 0xff ;
} else
goto V_265;
V_154 -> V_192 = V_261 & 0xff ;
V_154 -> V_195 = ( V_201 >> 16 ) & 0xff ;
V_154 -> V_194 = ( V_201 >> 8 ) & 0xff ;
V_154 -> V_193 = V_201 & 0xff ;
V_154 -> V_1 |= V_244 ;
} else {
T_8 V_268 , V_269 , V_270 , V_271 ;
if ( ! F_99 ( V_201 , V_261 ) )
goto V_265;
V_271 = ( T_8 ) V_201 / V_13 -> V_272 ;
V_270 = V_271 / V_13 -> V_273 ;
V_269 = V_271 % V_13 -> V_273 ;
V_268 = ( T_8 ) V_201 % V_13 -> V_272 + 1 ;
F_101 ( L_29 ,
( T_8 ) V_201 , V_271 , V_270 , V_269 , V_268 ) ;
if ( ( V_270 >> 16 ) || ( V_269 >> 4 ) || ( V_268 >> 8 ) || ( ! V_268 ) )
goto V_265;
V_154 -> V_156 = V_245 ;
V_154 -> V_192 = V_261 & 0xff ;
V_154 -> V_193 = V_268 ;
V_154 -> V_194 = V_270 ;
V_154 -> V_195 = V_270 >> 8 ;
V_154 -> V_1 |= V_269 ;
}
return 0 ;
V_237:
F_23 ( V_149 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_265:
F_23 ( V_149 , V_79 , 0x21 , 0x0 ) ;
return 1 ;
V_264:
V_149 -> V_61 = V_252 ;
return 1 ;
}
static unsigned int F_102 ( struct V_139 * V_140 )
{
struct V_56 * V_149 = V_140 -> V_143 ;
const T_3 * V_234 = V_149 -> V_235 ;
unsigned int V_274 = 0 ;
T_7 V_201 ;
T_8 V_261 ;
int V_33 ;
if ( V_234 [ 0 ] == V_275 || V_234 [ 0 ] == V_276 || V_234 [ 0 ] == V_277 )
V_274 |= V_278 ;
switch ( V_234 [ 0 ] ) {
case V_279 :
case V_275 :
if ( F_20 ( V_149 -> V_236 < 10 ) )
goto V_237;
F_96 ( V_234 , & V_201 , & V_261 ) ;
if ( V_234 [ 1 ] & ( 1 << 3 ) )
V_274 |= V_280 ;
break;
case V_281 :
case V_276 :
if ( F_20 ( V_149 -> V_236 < 6 ) )
goto V_237;
F_94 ( V_234 , & V_201 , & V_261 ) ;
if ( ! V_261 )
V_261 = 256 ;
break;
case V_282 :
case V_277 :
if ( F_20 ( V_149 -> V_236 < 16 ) )
goto V_237;
F_97 ( V_234 , & V_201 , & V_261 ) ;
if ( V_234 [ 1 ] & ( 1 << 3 ) )
V_274 |= V_280 ;
break;
default:
F_101 ( L_30 ) ;
goto V_237;
}
if ( ! V_261 )
goto V_264;
V_140 -> V_16 |= V_256 ;
V_140 -> V_152 = V_261 * V_149 -> V_1 -> V_217 ;
V_33 = F_103 ( & V_140 -> V_154 , V_140 -> V_13 , V_201 , V_261 , V_274 ,
V_140 -> V_142 ) ;
if ( F_67 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_283 )
goto V_265;
V_237:
F_23 ( V_149 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_265:
F_23 ( V_149 , V_79 , 0x21 , 0x0 ) ;
return 1 ;
V_264:
V_149 -> V_61 = V_252 ;
return 1 ;
}
static void F_104 ( struct V_139 * V_140 )
{
struct V_56 * V_57 = V_140 -> V_143 ;
void (* F_105)( struct V_56 * ) = V_140 -> V_144 ;
F_106 ( V_140 ) ;
F_105 ( V_57 ) ;
}
static void F_107 ( struct V_139 * V_140 )
{
struct V_8 * V_9 = V_140 -> V_9 ;
struct V_56 * V_57 = V_140 -> V_143 ;
T_3 * V_234 = V_57 -> V_235 ;
int V_284 = ( V_140 -> V_190 != 0 ) ;
if ( ( ( V_234 [ 0 ] == V_118 ) || ( V_234 [ 0 ] == V_285 ) ) &&
( ( V_234 [ 2 ] & 0x20 ) || V_284 ) )
F_62 ( V_140 ) ;
else if ( V_284 )
F_63 ( V_140 ) ;
else
V_57 -> V_61 = V_252 ;
if ( V_284 && ! V_9 -> V_65 -> V_189 )
F_59 ( V_9 -> V_191 , & V_140 -> V_187 ) ;
F_104 ( V_140 ) ;
}
static int F_108 ( struct V_12 * V_13 , struct V_56 * V_57 ,
T_9 V_286 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_139 * V_140 ;
int V_33 ;
F_95 ( L_31 ) ;
V_140 = F_53 ( V_13 , V_57 ) ;
if ( ! V_140 )
goto V_287;
if ( V_57 -> V_288 == V_116 ||
V_57 -> V_288 == V_289 ) {
if ( F_20 ( F_58 ( V_57 ) < 1 ) ) {
F_77 ( V_13 , L_32 ) ;
goto V_290;
}
F_109 ( V_140 , F_55 ( V_57 ) , F_56 ( V_57 ) ) ;
V_140 -> V_291 = V_57 -> V_288 ;
}
V_140 -> V_292 = F_107 ;
if ( V_286 ( V_140 ) )
goto V_293;
if ( V_9 -> V_65 -> V_294 ) {
if ( ( V_33 = V_9 -> V_65 -> V_294 ( V_140 ) ) )
goto V_295;
}
F_110 ( V_140 ) ;
F_95 ( L_33 ) ;
return 0 ;
V_293:
F_106 ( V_140 ) ;
V_57 -> V_80 ( V_57 ) ;
F_101 ( L_34 ) ;
return 0 ;
V_290:
F_106 ( V_140 ) ;
V_57 -> V_61 = ( V_296 << 16 ) ;
V_57 -> V_80 ( V_57 ) ;
V_287:
F_101 ( L_35 ) ;
return 0 ;
V_295:
F_106 ( V_140 ) ;
F_101 ( L_36 ) ;
if ( V_33 == V_297 )
return V_298 ;
else
return V_299 ;
}
static void * F_111 ( struct V_56 * V_57 , bool V_300 ,
unsigned long * V_16 )
{
F_5 ( & V_301 , * V_16 ) ;
memset ( V_302 , 0 , V_303 ) ;
if ( V_300 )
F_112 ( F_55 ( V_57 ) , F_56 ( V_57 ) ,
V_302 , V_303 ) ;
return V_302 ;
}
static inline void F_113 ( struct V_56 * V_57 , bool V_304 ,
unsigned long * V_16 )
{
if ( V_304 )
F_114 ( F_55 ( V_57 ) , F_56 ( V_57 ) ,
V_302 , V_303 ) ;
F_9 ( & V_301 , * V_16 ) ;
}
static unsigned int F_115 ( struct V_305 * args , T_3 * V_306 )
{
const T_3 V_307 [] = {
0x00 ,
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
const T_3 V_308 [] = {
0x00 ,
0xA0 ,
0x04 ,
0xC0 ,
0x04 ,
0x60 ,
0x60 ,
0x20 ,
} ;
T_3 V_309 [] = {
V_310 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_95 ( L_31 ) ;
if ( F_116 ( args -> V_93 ) ||
( args -> V_13 -> V_11 -> V_9 -> V_39 & V_311 ) )
V_309 [ 1 ] |= ( 1 << 7 ) ;
if ( args -> V_13 -> V_49 == V_51 ) {
V_309 [ 0 ] = V_312 ;
V_309 [ 2 ] = 0x6 ;
}
memcpy ( V_306 , V_309 , sizeof( V_309 ) ) ;
memcpy ( & V_306 [ 8 ] , L_37 , 8 ) ;
F_38 ( args -> V_93 , & V_306 [ 16 ] , V_96 , 16 ) ;
F_38 ( args -> V_93 , & V_306 [ 32 ] , V_98 + 2 , 4 ) ;
if ( strncmp ( & V_306 [ 32 ] , L_38 , 4 ) == 0 )
F_38 ( args -> V_93 , & V_306 [ 32 ] , V_98 , 4 ) ;
if ( V_306 [ 32 ] == 0 || V_306 [ 32 ] == ' ' )
memcpy ( & V_306 [ 32 ] , L_39 , 4 ) ;
if ( args -> V_13 -> V_49 == V_51 )
memcpy ( V_306 + 58 , V_308 , sizeof( V_308 ) ) ;
else
memcpy ( V_306 + 58 , V_307 , sizeof( V_307 ) ) ;
return 0 ;
}
static unsigned int F_117 ( struct V_305 * args , T_3 * V_306 )
{
const T_3 V_313 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
} ;
V_306 [ 3 ] = sizeof( V_313 ) ;
memcpy ( V_306 + 4 , V_313 , sizeof( V_313 ) ) ;
return 0 ;
}
static unsigned int F_118 ( struct V_305 * args , T_3 * V_306 )
{
const T_3 V_309 [] = {
0 ,
0x80 ,
0 ,
V_101 ,
} ;
memcpy ( V_306 , V_309 , sizeof( V_309 ) ) ;
F_38 ( args -> V_93 , ( unsigned char * ) & V_306 [ 4 ] ,
V_100 , V_101 ) ;
return 0 ;
}
static unsigned int F_119 ( struct V_305 * args , T_3 * V_306 )
{
const int V_314 = 68 ;
int V_315 ;
V_306 [ 1 ] = 0x83 ;
V_315 = 4 ;
V_306 [ V_315 + 0 ] = 2 ;
V_306 [ V_315 + 3 ] = V_101 ;
V_315 += 4 ;
F_38 ( args -> V_93 , ( unsigned char * ) V_306 + V_315 ,
V_100 , V_101 ) ;
V_315 += V_101 ;
V_306 [ V_315 + 0 ] = 2 ;
V_306 [ V_315 + 1 ] = 1 ;
V_306 [ V_315 + 3 ] = V_314 ;
V_315 += 4 ;
memcpy ( V_306 + V_315 , L_37 , 8 ) ;
V_315 += 8 ;
F_38 ( args -> V_93 , ( unsigned char * ) V_306 + V_315 , V_96 ,
V_97 ) ;
V_315 += V_97 ;
F_38 ( args -> V_93 , ( unsigned char * ) V_306 + V_315 , V_100 ,
V_101 ) ;
V_315 += V_101 ;
if ( F_120 ( args -> V_93 ) ) {
V_306 [ V_315 + 0 ] = 1 ;
V_306 [ V_315 + 1 ] = 3 ;
V_306 [ V_315 + 3 ] = V_316 ;
V_315 += 4 ;
F_38 ( args -> V_93 , ( unsigned char * ) V_306 + V_315 ,
V_317 , V_316 ) ;
V_315 += V_316 ;
}
V_306 [ 3 ] = V_315 - 4 ;
return 0 ;
}
static unsigned int F_121 ( struct V_305 * args , T_3 * V_306 )
{
struct V_153 V_154 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_306 [ 1 ] = 0x89 ;
V_306 [ 2 ] = ( 0x238 >> 8 ) ;
V_306 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_306 [ 8 ] , L_40 , 8 ) ;
memcpy ( & V_306 [ 16 ] , L_41 , 16 ) ;
memcpy ( & V_306 [ 32 ] , V_318 , 4 ) ;
V_154 . V_156 = V_161 ;
V_154 . V_193 = 0x1 ;
V_154 . V_192 = 0x1 ;
F_122 ( & V_154 , 0 , 1 , & V_306 [ 36 ] ) ;
V_306 [ 36 ] = 0x34 ;
V_306 [ 56 ] = V_319 ;
memcpy ( & V_306 [ 60 ] , & args -> V_93 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_123 ( struct V_305 * args , T_3 * V_306 )
{
T_6 V_320 ;
V_306 [ 1 ] = 0xb0 ;
V_306 [ 3 ] = 0x3c ;
V_320 = 1 << F_124 ( args -> V_93 ) ;
F_125 ( V_320 , & V_306 [ 6 ] ) ;
if ( F_126 ( args -> V_93 ) ) {
F_127 ( 65535 * 512 / 8 , & V_306 [ 36 ] ) ;
F_128 ( 1 , & V_306 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_129 ( struct V_305 * args , T_3 * V_306 )
{
int V_321 = F_130 ( args -> V_93 ) ;
int V_322 = F_131 ( args -> V_93 ) ;
V_306 [ 1 ] = 0xb1 ;
V_306 [ 3 ] = 0x3c ;
V_306 [ 4 ] = V_322 >> 8 ;
V_306 [ 5 ] = V_322 ;
V_306 [ 7 ] = V_321 ;
return 0 ;
}
static unsigned int F_132 ( struct V_305 * args , T_3 * V_306 )
{
V_306 [ 1 ] = 0xb2 ;
V_306 [ 3 ] = 0x4 ;
V_306 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_133 ( struct V_305 * args , T_3 * V_306 )
{
F_95 ( L_31 ) ;
return 0 ;
}
static void F_134 ( T_3 * V_323 , const T_3 * V_324 , int V_325 , bool V_326 )
{
if ( V_326 ) {
memcpy ( V_323 , V_324 , 2 ) ;
memset ( V_323 + 2 , 0 , V_325 - 2 ) ;
} else {
memcpy ( V_323 , V_324 , V_325 ) ;
}
}
static unsigned int F_135 ( T_6 * V_93 , T_3 * V_4 , bool V_326 )
{
F_134 ( V_4 , V_327 , sizeof( V_327 ) , V_326 ) ;
if ( V_326 || F_136 ( V_93 ) )
V_4 [ 2 ] |= ( 1 << 2 ) ;
if ( ! V_326 && ! F_137 ( V_93 ) )
V_4 [ 12 ] |= ( 1 << 5 ) ;
return sizeof( V_327 ) ;
}
static unsigned int F_138 ( T_3 * V_4 , bool V_326 )
{
F_134 ( V_4 , V_328 , sizeof( V_328 ) , V_326 ) ;
return sizeof( V_328 ) ;
}
static unsigned int F_139 ( T_3 * V_4 , bool V_326 )
{
F_134 ( V_4 , V_329 , sizeof( V_329 ) ,
V_326 ) ;
return sizeof( V_329 ) ;
}
static int F_140 ( T_6 * V_93 )
{
unsigned char V_330 [ V_97 + 1 ] , V_331 [ V_99 + 1 ] ;
if ( ! V_332 )
return 0 ;
if ( ! F_141 ( V_93 ) )
return 0 ;
F_142 ( V_93 , V_330 , V_96 , sizeof( V_330 ) ) ;
F_142 ( V_93 , V_331 , V_98 , sizeof( V_331 ) ) ;
if ( strcmp ( V_330 , L_42 ) )
return 1 ;
if ( strcmp ( V_331 , L_43 ) )
return 1 ;
return 0 ;
}
static unsigned int F_143 ( struct V_305 * args , T_3 * V_306 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_143 = args -> V_57 -> V_235 , * V_333 = V_306 ;
const T_3 V_334 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_335 , V_336 ;
unsigned int V_337 , V_338 , V_339 ;
T_3 V_340 ;
F_95 ( L_31 ) ;
V_339 = ( V_143 [ 0 ] == V_341 ) ;
V_337 = ! ( V_143 [ 1 ] & 0x8 ) ;
V_338 = V_143 [ 2 ] >> 6 ;
switch ( V_338 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_342;
default:
goto V_237;
}
if ( V_339 )
V_333 += 4 + ( V_337 ? 8 : 0 ) ;
else
V_333 += 8 + ( V_337 ? 8 : 0 ) ;
V_335 = V_143 [ 2 ] & 0x3f ;
V_336 = V_143 [ 3 ] ;
if ( V_336 && ( V_336 != V_343 ) )
goto V_237;
switch( V_335 ) {
case V_344 :
V_333 += F_139 ( V_333 , V_338 == 1 ) ;
break;
case V_345 :
V_333 += F_135 ( args -> V_93 , V_333 , V_338 == 1 ) ;
break;
case V_346 :
V_333 += F_138 ( V_333 , V_338 == 1 ) ;
break;
case V_347 :
V_333 += F_139 ( V_333 , V_338 == 1 ) ;
V_333 += F_135 ( args -> V_93 , V_333 , V_338 == 1 ) ;
V_333 += F_138 ( V_333 , V_338 == 1 ) ;
break;
default:
goto V_237;
}
V_340 = 0 ;
if ( F_140 ( args -> V_93 ) && ( V_13 -> V_16 & V_266 ) &&
( ! ( V_13 -> V_16 & V_348 ) || V_13 -> V_349 ) )
V_340 = 1 << 4 ;
if ( V_339 ) {
V_306 [ 0 ] = V_333 - V_306 - 1 ;
V_306 [ 2 ] |= V_340 ;
if ( V_337 ) {
V_306 [ 3 ] = sizeof( V_334 ) ;
memcpy ( V_306 + 4 , V_334 , sizeof( V_334 ) ) ;
}
} else {
unsigned int V_350 = V_333 - V_306 - 2 ;
V_306 [ 0 ] = V_350 >> 8 ;
V_306 [ 1 ] = V_350 ;
V_306 [ 3 ] |= V_340 ;
if ( V_337 ) {
V_306 [ 7 ] = sizeof( V_334 ) ;
memcpy ( V_306 + 8 , V_334 , sizeof( V_334 ) ) ;
}
}
return 0 ;
V_237:
F_23 ( args -> V_57 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_342:
F_23 ( args -> V_57 , V_79 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_144 ( struct V_305 * args , T_3 * V_306 )
{
struct V_12 * V_13 = args -> V_13 ;
T_7 V_351 = V_13 -> V_85 - 1 ;
T_8 V_217 ;
T_3 V_352 ;
T_6 V_353 ;
V_217 = F_76 ( V_13 -> V_93 ) ;
V_352 = F_124 ( V_13 -> V_93 ) ;
V_353 = F_145 ( V_13 -> V_93 , V_352 ) ;
F_95 ( L_31 ) ;
if ( args -> V_57 -> V_235 [ 0 ] == V_354 ) {
if ( V_351 >= 0xffffffffULL )
V_351 = 0xffffffff ;
V_306 [ 0 ] = V_351 >> ( 8 * 3 ) ;
V_306 [ 1 ] = V_351 >> ( 8 * 2 ) ;
V_306 [ 2 ] = V_351 >> ( 8 * 1 ) ;
V_306 [ 3 ] = V_351 ;
V_306 [ 4 ] = V_217 >> ( 8 * 3 ) ;
V_306 [ 5 ] = V_217 >> ( 8 * 2 ) ;
V_306 [ 6 ] = V_217 >> ( 8 * 1 ) ;
V_306 [ 7 ] = V_217 ;
} else {
V_306 [ 0 ] = V_351 >> ( 8 * 7 ) ;
V_306 [ 1 ] = V_351 >> ( 8 * 6 ) ;
V_306 [ 2 ] = V_351 >> ( 8 * 5 ) ;
V_306 [ 3 ] = V_351 >> ( 8 * 4 ) ;
V_306 [ 4 ] = V_351 >> ( 8 * 3 ) ;
V_306 [ 5 ] = V_351 >> ( 8 * 2 ) ;
V_306 [ 6 ] = V_351 >> ( 8 * 1 ) ;
V_306 [ 7 ] = V_351 ;
V_306 [ 8 ] = V_217 >> ( 8 * 3 ) ;
V_306 [ 9 ] = V_217 >> ( 8 * 2 ) ;
V_306 [ 10 ] = V_217 >> ( 8 * 1 ) ;
V_306 [ 11 ] = V_217 ;
V_306 [ 12 ] = 0 ;
V_306 [ 13 ] = V_352 ;
V_306 [ 14 ] = ( V_353 >> 8 ) & 0x3f ;
V_306 [ 15 ] = V_353 ;
if ( F_126 ( args -> V_93 ) &&
! ( V_13 -> V_22 & V_355 ) ) {
V_306 [ 14 ] |= 0x80 ;
if ( F_146 ( args -> V_93 ) &&
V_13 -> V_22 & V_356 ) {
F_147 ( V_13 , L_44 ) ;
V_306 [ 14 ] |= 0x40 ;
}
}
}
return 0 ;
}
static unsigned int F_148 ( struct V_305 * args , T_3 * V_306 )
{
F_95 ( L_31 ) ;
V_306 [ 3 ] = 8 ;
return 0 ;
}
static void F_149 ( struct V_139 * V_140 )
{
if ( V_140 -> V_190 && ( ( V_140 -> V_190 & V_357 ) == 0 ) ) {
F_62 ( V_140 ) ;
}
F_104 ( V_140 ) ;
}
static inline int F_150 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_127 ) ;
}
static void F_151 ( struct V_139 * V_140 )
{
struct V_8 * V_9 = V_140 -> V_9 ;
struct V_56 * V_57 = V_140 -> V_143 ;
F_101 ( L_45 ) ;
memset ( V_57 -> V_64 , 0 , V_111 ) ;
#ifdef F_152
if ( V_9 -> V_65 -> V_358 )
V_9 -> V_65 -> V_358 ( V_9 , & V_140 -> V_154 ) ;
#endif
V_57 -> V_64 [ 0 ] = 0x70 ;
V_57 -> V_64 [ 2 ] = V_140 -> V_154 . V_158 >> 4 ;
F_153 ( V_140 ) ;
F_154 ( & V_140 -> V_359 , V_57 -> V_64 , V_111 ) ;
F_109 ( V_140 , & V_140 -> V_359 , 1 ) ;
V_140 -> V_291 = V_116 ;
memset ( & V_140 -> V_234 , 0 , V_140 -> V_13 -> V_360 ) ;
V_140 -> V_234 [ 0 ] = V_361 ;
V_140 -> V_234 [ 4 ] = V_111 ;
V_140 -> V_154 . V_16 |= V_239 | V_238 ;
V_140 -> V_154 . V_156 = V_362 ;
if ( F_150 ( V_9 ) ) {
V_140 -> V_154 . V_240 = V_363 ;
V_140 -> V_154 . V_158 |= V_364 ;
} else {
V_140 -> V_154 . V_240 = V_365 ;
V_140 -> V_154 . V_194 = V_111 ;
V_140 -> V_154 . V_195 = 0 ;
}
V_140 -> V_152 = V_111 ;
V_140 -> V_292 = F_149 ;
F_110 ( V_140 ) ;
F_101 ( L_33 ) ;
}
static void F_155 ( struct V_139 * V_140 )
{
struct V_56 * V_57 = V_140 -> V_143 ;
unsigned int V_190 = V_140 -> V_190 ;
F_95 ( L_46 , V_190 ) ;
if ( F_20 ( V_140 -> V_9 -> V_65 -> V_189 &&
( V_190 || V_140 -> V_16 & V_366 ) ) ) {
if ( ! ( V_140 -> V_16 & V_366 ) ) {
F_62 ( V_140 ) ;
}
if ( V_140 -> V_234 [ 0 ] == V_367 && V_140 -> V_13 -> V_29 )
V_140 -> V_13 -> V_29 -> V_368 = 0 ;
V_140 -> V_143 -> V_61 = V_63 ;
F_104 ( V_140 ) ;
return;
}
if ( F_20 ( V_190 & V_357 ) ) {
V_57 -> V_61 = V_63 ;
F_151 ( V_140 ) ;
return;
} else if ( F_20 ( V_190 ) ) {
F_62 ( V_140 ) ;
} else {
T_3 * V_143 = V_57 -> V_235 ;
if ( ( V_143 [ 0 ] == V_369 ) && ( ( V_143 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_16 ;
T_3 * V_4 ;
V_4 = F_111 ( V_57 , true , & V_16 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_113 ( V_57 , true , & V_16 ) ;
}
V_57 -> V_61 = V_252 ;
}
F_104 ( V_140 ) ;
}
static unsigned int F_156 ( struct V_139 * V_140 )
{
struct V_56 * V_149 = V_140 -> V_143 ;
struct V_12 * V_13 = V_140 -> V_13 ;
int V_370 = ( V_149 -> V_288 == V_117 ) ;
int V_371 = ! V_370 && ( V_13 -> V_16 & V_348 ) ;
unsigned int V_152 ;
memset ( V_140 -> V_234 , 0 , V_13 -> V_360 ) ;
memcpy ( V_140 -> V_234 , V_149 -> V_235 , V_149 -> V_236 ) ;
V_140 -> V_292 = F_155 ;
V_140 -> V_154 . V_16 |= V_239 | V_238 ;
if ( V_149 -> V_288 == V_289 ) {
V_140 -> V_154 . V_16 |= V_278 ;
F_101 ( L_47 ) ;
}
V_140 -> V_154 . V_156 = V_362 ;
F_57 ( V_140 ) ;
if ( ! V_370 && ! V_371 && F_157 ( V_140 ) )
V_371 = 1 ;
V_152 = F_80 ( F_158 ( V_140 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_152 & 0x1 )
V_152 ++ ;
V_140 -> V_154 . V_194 = ( V_152 & 0xFF ) ;
V_140 -> V_154 . V_195 = ( V_152 >> 8 ) ;
if ( V_370 )
V_140 -> V_154 . V_240 = V_372 ;
else if ( V_371 )
V_140 -> V_154 . V_240 = V_365 ;
else {
V_140 -> V_154 . V_240 = V_363 ;
V_140 -> V_154 . V_158 |= V_364 ;
if ( ( V_13 -> V_16 & V_373 ) &&
( V_149 -> V_288 != V_289 ) )
V_140 -> V_154 . V_158 |= V_374 ;
}
return 0 ;
}
static struct V_12 * F_159 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_160 ( V_9 ) ) {
if ( F_67 ( V_43 < F_161 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_67 ( V_43 < V_9 -> V_375 ) )
return & V_9 -> V_376 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_85 ( struct V_8 * V_9 ,
const struct V_28 * V_102 )
{
int V_43 ;
if ( ! F_160 ( V_9 ) ) {
if ( F_20 ( V_102 -> V_377 || V_102 -> V_378 ) )
return NULL ;
V_43 = V_102 -> V_93 ;
} else {
if ( F_20 ( V_102 -> V_93 || V_102 -> V_378 ) )
return NULL ;
V_43 = V_102 -> V_377 ;
}
return F_159 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_14 ( struct V_8 * V_9 , const struct V_28 * V_102 )
{
struct V_12 * V_13 = F_85 ( V_9 , V_102 ) ;
if ( F_20 ( ! V_13 || ! F_88 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_162 ( T_3 V_379 )
{
switch( ( V_379 & 0x1e ) >> 1 ) {
case 3 :
return V_241 ;
case 6 :
case 10 :
case 11 :
return V_380 ;
case 4 :
case 5 :
return V_381 ;
case 12 :
return V_382 ;
case 0 :
case 1 :
case 8 :
case 9 :
case 7 :
case 15 :
default:
break;
}
return V_383 ;
}
static unsigned int F_163 ( struct V_139 * V_140 )
{
struct V_153 * V_154 = & ( V_140 -> V_154 ) ;
struct V_56 * V_149 = V_140 -> V_143 ;
struct V_12 * V_13 = V_140 -> V_13 ;
const T_3 * V_234 = V_149 -> V_235 ;
if ( ( V_154 -> V_240 = F_162 ( V_234 [ 1 ] ) ) == V_383 )
goto V_237;
V_154 -> V_16 |= V_243 ;
if ( V_234 [ 0 ] == V_118 ) {
if ( V_234 [ 1 ] & 0x01 ) {
V_154 -> V_384 = V_234 [ 3 ] ;
V_154 -> V_197 = V_234 [ 5 ] ;
V_154 -> V_198 = V_234 [ 7 ] ;
V_154 -> V_199 = V_234 [ 9 ] ;
V_154 -> V_200 = V_234 [ 11 ] ;
V_154 -> V_16 |= V_196 ;
} else
V_154 -> V_16 &= ~ V_196 ;
V_154 -> V_158 = V_234 [ 4 ] ;
V_154 -> V_192 = V_234 [ 6 ] ;
V_154 -> V_193 = V_234 [ 8 ] ;
V_154 -> V_194 = V_234 [ 10 ] ;
V_154 -> V_195 = V_234 [ 12 ] ;
V_154 -> V_1 = V_234 [ 13 ] ;
V_154 -> V_156 = V_234 [ 14 ] ;
} else {
V_154 -> V_16 &= ~ V_196 ;
V_154 -> V_158 = V_234 [ 3 ] ;
V_154 -> V_192 = V_234 [ 4 ] ;
V_154 -> V_193 = V_234 [ 5 ] ;
V_154 -> V_194 = V_234 [ 6 ] ;
V_154 -> V_195 = V_234 [ 7 ] ;
V_154 -> V_1 = V_234 [ 8 ] ;
V_154 -> V_156 = V_234 [ 9 ] ;
}
if ( V_154 -> V_240 == V_382 )
V_154 -> V_192 = V_140 -> V_142 << 3 ;
V_154 -> V_1 = V_13 -> V_43 ?
V_154 -> V_1 | V_385 : V_154 -> V_1 & ~ V_385 ;
switch ( V_154 -> V_156 ) {
case V_386 :
case V_387 :
case V_388 :
case V_389 :
if ( V_154 -> V_240 != V_381 || V_154 -> V_192 != 1 )
goto V_237;
V_140 -> V_390 = F_58 ( V_149 ) ;
break;
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_245 :
case V_267 :
case V_404 :
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
V_140 -> V_390 = V_149 -> V_1 -> V_217 ;
break;
default:
V_140 -> V_390 = V_114 ;
}
V_154 -> V_16 |= V_239 | V_238 ;
if ( V_149 -> V_288 == V_289 )
V_154 -> V_16 |= V_278 ;
V_140 -> V_16 |= V_417 | V_418 ;
F_57 ( V_140 ) ;
if ( V_154 -> V_240 == V_380 && V_13 -> V_419 == 0 )
goto V_237;
if ( ( V_234 [ 1 ] & 0xe0 ) && ! F_164 ( V_154 ) )
goto V_237;
if ( F_164 ( V_154 ) ) {
unsigned int V_349 = 1 << ( V_234 [ 1 ] >> 5 ) ;
if ( V_349 != V_13 -> V_349 )
F_77 ( V_13 , L_48 ,
V_349 ) ;
}
if ( V_154 -> V_156 == V_420 &&
V_154 -> V_158 == V_421 )
goto V_237;
if ( V_154 -> V_156 >= 0x5C && V_154 -> V_156 <= 0x5F && ! V_422 )
goto V_237;
return 0 ;
V_237:
F_23 ( V_149 , V_79 , 0x24 , 0x00 ) ;
return 1 ;
}
static unsigned int F_165 ( struct V_139 * V_140 )
{
struct V_153 * V_154 = & V_140 -> V_154 ;
struct V_56 * V_149 = V_140 -> V_143 ;
struct V_12 * V_13 = V_140 -> V_13 ;
const T_3 * V_234 = V_149 -> V_235 ;
T_7 V_201 ;
T_8 V_261 ;
T_8 V_423 ;
void * V_4 ;
if ( F_20 ( ! V_13 -> V_419 ) )
goto V_237;
if ( F_20 ( V_149 -> V_236 < 16 ) )
goto V_237;
F_97 ( V_234 , & V_201 , & V_261 ) ;
if ( F_20 ( ! ( V_234 [ 1 ] & 0x8 ) ) )
goto V_237;
if ( ! F_56 ( V_149 ) )
goto V_237;
V_4 = F_166 ( F_167 ( F_55 ( V_149 ) ) ) ;
V_423 = F_168 ( V_4 , 512 , V_201 , V_261 ) ;
if ( F_89 ( V_13 ) && F_169 ( V_13 ) ) {
V_154 -> V_240 = V_382 ;
V_154 -> V_156 = V_424 ;
V_154 -> V_197 = V_425 & 0x1f ;
V_154 -> V_192 = V_140 -> V_142 << 3 ;
V_154 -> V_384 = ( V_423 / 512 ) >> 8 ;
V_154 -> V_158 = V_423 / 512 ;
V_154 -> V_426 = 1 ;
} else {
V_154 -> V_240 = V_380 ;
V_154 -> V_384 = 0 ;
V_154 -> V_158 = V_427 ;
V_154 -> V_197 = ( V_423 / 512 ) >> 8 ;
V_154 -> V_192 = V_423 / 512 ;
V_154 -> V_156 = V_428 ;
}
V_154 -> V_16 |= V_239 | V_238 | V_196 |
V_278 ;
F_57 ( V_140 ) ;
return 0 ;
V_237:
F_23 ( V_149 , V_79 , 0x24 , 0x00 ) ;
return 1 ;
}
static int F_170 ( struct V_139 * V_140 ,
const T_3 * V_4 , int V_45 )
{
struct V_153 * V_154 = & V_140 -> V_154 ;
struct V_12 * V_13 = V_140 -> V_13 ;
char V_429 [ V_430 ] ;
T_3 V_431 ;
if ( V_45 != V_430 - 2 )
return - V_20 ;
V_431 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_135 ( V_13 -> V_93 , V_429 , false ) ;
V_429 [ 2 ] &= ~ ( 1 << 2 ) ;
V_429 [ 2 ] |= V_431 ;
if ( memcmp ( V_429 + 2 , V_4 , V_430 - 2 ) != 0 )
return - V_20 ;
V_154 -> V_16 |= V_238 | V_239 ;
V_154 -> V_240 = V_241 ;
V_154 -> V_192 = 0 ;
V_154 -> V_156 = V_420 ;
V_154 -> V_158 = V_431 ? V_432 : V_433 ;
return 0 ;
}
static unsigned int F_171 ( struct V_139 * V_140 )
{
struct V_56 * V_149 = V_140 -> V_143 ;
const T_3 * V_234 = V_149 -> V_235 ;
const T_3 * V_333 ;
T_3 V_335 , V_336 ;
unsigned V_339 , V_434 , V_435 , V_436 ;
int V_45 ;
F_95 ( L_31 ) ;
V_339 = ( V_234 [ 0 ] == V_437 ) ;
if ( V_339 ) {
if ( V_149 -> V_236 < 5 )
goto V_237;
V_45 = V_234 [ 4 ] ;
V_435 = 4 ;
} else {
if ( V_149 -> V_236 < 9 )
goto V_237;
V_45 = ( V_234 [ 7 ] << 8 ) + V_234 [ 8 ] ;
V_435 = 8 ;
}
if ( ( V_234 [ 1 ] & 0x11 ) != 0x10 )
goto V_237;
if ( ! F_56 ( V_149 ) || F_55 ( V_149 ) -> V_438 < V_45 )
goto V_439;
V_333 = F_166 ( F_167 ( F_55 ( V_149 ) ) ) ;
if ( V_45 < V_435 )
goto V_439;
if ( V_339 )
V_436 = V_333 [ 3 ] ;
else
V_436 = ( V_333 [ 6 ] << 8 ) + V_333 [ 7 ] ;
V_45 -= V_435 ;
V_333 += V_435 ;
if ( V_45 < V_436 )
goto V_439;
if ( V_436 != 0 && V_436 != 8 )
goto V_440;
V_45 -= V_436 ;
V_333 += V_436 ;
if ( V_45 == 0 )
goto V_249;
V_335 = V_333 [ 0 ] & 0x3f ;
if ( V_333 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_439;
V_336 = V_333 [ 1 ] ;
V_434 = ( V_333 [ 2 ] << 8 ) | V_333 [ 3 ] ;
V_333 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_439;
V_336 = 0 ;
V_434 = V_333 [ 1 ] ;
V_333 += 2 ;
V_45 -= 2 ;
}
if ( V_336 && ( V_336 != V_343 ) )
goto V_440;
if ( V_434 > V_45 )
goto V_439;
switch ( V_335 ) {
case V_345 :
if ( F_170 ( V_140 , V_333 , V_434 ) < 0 )
goto V_440;
break;
default:
goto V_440;
}
if ( V_45 > V_434 )
goto V_440;
return 0 ;
V_237:
F_23 ( V_149 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_440:
F_23 ( V_149 , V_79 , 0x26 , 0x0 ) ;
return 1 ;
V_439:
F_23 ( V_149 , V_79 , 0x1a , 0x0 ) ;
return 1 ;
V_249:
V_149 -> V_61 = V_252 ;
return 1 ;
}
static inline T_9 F_172 ( struct V_12 * V_13 , T_3 V_57 )
{
switch ( V_57 ) {
case V_281 :
case V_279 :
case V_282 :
case V_276 :
case V_275 :
case V_277 :
return F_102 ;
case V_441 :
return F_165 ;
case V_442 :
if ( F_173 ( V_13 ) )
return F_93 ;
break;
case V_262 :
case V_263 :
return F_98 ;
case V_285 :
case V_118 :
return F_163 ;
case V_437 :
case V_443 :
return F_171 ;
break;
case V_444 :
return F_91 ;
}
return NULL ;
}
static inline void F_174 ( struct V_8 * V_9 ,
struct V_56 * V_57 )
{
#ifdef F_175
struct V_28 * V_102 = V_57 -> V_1 ;
T_3 * V_143 = V_57 -> V_235 ;
F_101 ( L_49 ,
V_9 -> V_191 ,
V_102 -> V_377 , V_102 -> V_93 , V_102 -> V_378 ,
V_143 [ 0 ] , V_143 [ 1 ] , V_143 [ 2 ] , V_143 [ 3 ] ,
V_143 [ 4 ] , V_143 [ 5 ] , V_143 [ 6 ] , V_143 [ 7 ] ,
V_143 [ 8 ] ) ;
#endif
}
static inline int F_176 ( struct V_56 * V_149 ,
struct V_12 * V_13 )
{
T_3 V_445 = V_149 -> V_235 [ 0 ] ;
T_9 V_286 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 || V_13 -> V_49 == V_51 ) {
if ( F_20 ( ! V_149 -> V_236 || V_149 -> V_236 > V_13 -> V_360 ) )
goto V_446;
V_286 = F_172 ( V_13 , V_445 ) ;
} else {
if ( F_20 ( ! V_149 -> V_236 ) )
goto V_446;
V_286 = NULL ;
if ( F_67 ( ( V_445 != V_118 ) || ! V_447 ) ) {
int V_45 = F_177 ( V_445 ) ;
if ( F_20 ( V_45 > V_149 -> V_236 || V_45 > V_13 -> V_360 ) )
goto V_446;
V_286 = F_156 ;
} else {
if ( F_20 ( V_149 -> V_236 > 16 ) )
goto V_446;
V_286 = F_172 ( V_13 , V_445 ) ;
}
}
if ( V_286 )
V_33 = F_108 ( V_13 , V_149 , V_286 ) ;
else
F_178 ( V_13 , V_149 ) ;
return V_33 ;
V_446:
F_101 ( L_50 ,
V_149 -> V_236 , V_445 , V_13 -> V_360 ) ;
V_149 -> V_61 = V_296 << 16 ;
V_149 -> V_80 ( V_149 ) ;
return 0 ;
}
int F_179 ( struct V_6 * V_7 , struct V_56 * V_57 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_102 = V_57 -> V_1 ;
int V_33 = 0 ;
unsigned long V_448 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_448 ) ;
F_174 ( V_9 , V_57 ) ;
V_13 = F_14 ( V_9 , V_102 ) ;
if ( F_67 ( V_13 ) )
V_33 = F_176 ( V_57 , V_13 ) ;
else {
V_57 -> V_61 = ( V_449 << 16 ) ;
V_57 -> V_80 ( V_57 ) ;
}
F_9 ( V_9 -> V_21 , V_448 ) ;
return V_33 ;
}
void F_178 ( struct V_12 * V_13 , struct V_56 * V_57 )
{
struct V_305 args ;
const T_3 * V_143 = V_57 -> V_235 ;
T_3 V_450 ;
args . V_13 = V_13 ;
args . V_93 = V_13 -> V_93 ;
args . V_57 = V_57 ;
args . F_105 = V_57 -> V_80 ;
switch( V_143 [ 0 ] ) {
case V_451 :
F_31 ( V_57 ) ;
break;
case V_369 :
if ( V_143 [ 1 ] & 2 )
F_31 ( V_57 ) ;
else if ( ( V_143 [ 1 ] & 1 ) == 0 )
F_180 ( & args , F_115 ) ;
else switch ( V_143 [ 2 ] ) {
case 0x00 :
F_180 ( & args , F_117 ) ;
break;
case 0x80 :
F_180 ( & args , F_118 ) ;
break;
case 0x83 :
F_180 ( & args , F_119 ) ;
break;
case 0x89 :
F_180 ( & args , F_121 ) ;
break;
case 0xb0 :
F_180 ( & args , F_123 ) ;
break;
case 0xb1 :
F_180 ( & args , F_129 ) ;
break;
case 0xb2 :
F_180 ( & args , F_132 ) ;
break;
default:
F_31 ( V_57 ) ;
break;
}
break;
case V_341 :
case V_452 :
F_180 ( & args , F_143 ) ;
break;
case V_354 :
F_180 ( & args , F_144 ) ;
break;
case V_453 :
if ( ( V_143 [ 1 ] & 0x1f ) == V_454 )
F_180 ( & args , F_144 ) ;
else
F_31 ( V_57 ) ;
break;
case V_455 :
F_180 ( & args , F_148 ) ;
break;
case V_361 :
F_23 ( V_57 , 0 , 0 , 0 ) ;
V_57 -> V_61 = ( V_62 << 24 ) ;
V_57 -> V_80 ( V_57 ) ;
break;
case V_442 :
case V_456 :
case V_457 :
case V_458 :
case V_459 :
F_180 ( & args , F_133 ) ;
break;
case V_460 :
V_450 = V_143 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_450 == 0x4 ) && ( ! V_143 [ 3 ] ) && ( ! V_143 [ 4 ] ) )
F_180 ( & args , F_133 ) ;
else
F_31 ( V_57 ) ;
break;
default:
F_23 ( V_57 , V_79 , 0x20 , 0x0 ) ;
V_57 -> V_80 ( V_57 ) ;
break;
}
}
int F_181 ( struct V_461 * V_34 , struct V_462 * V_463 )
{
int V_177 , V_33 ;
for ( V_177 = 0 ; V_177 < V_34 -> V_464 ; V_177 ++ ) {
struct V_8 * V_9 = V_34 -> V_465 [ V_177 ] ;
struct V_6 * V_7 ;
V_33 = - V_113 ;
V_7 = F_182 ( V_463 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_466;
V_7 -> V_467 = 1 ;
* (struct V_8 * * ) & V_7 -> V_468 [ 0 ] = V_9 ;
V_9 -> V_469 = V_7 ;
V_7 -> V_470 = V_471 ;
V_7 -> V_472 = V_9 -> V_191 ;
V_7 -> V_473 = 16 ;
V_7 -> V_474 = 1 ;
V_7 -> V_475 = 1 ;
V_7 -> V_476 = 16 ;
V_7 -> V_205 = 1 ;
V_7 -> V_477 = 1 ;
V_33 = F_183 ( V_9 -> V_469 ,
& V_9 -> V_478 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_479;
}
return 0 ;
V_479:
F_184 ( V_34 -> V_465 [ V_177 ] -> V_469 ) ;
V_466:
while ( -- V_177 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_465 [ V_177 ] -> V_469 ;
F_185 ( V_7 ) ;
F_184 ( V_7 ) ;
}
return V_33 ;
}
void F_186 ( struct V_8 * V_9 , int V_480 )
{
int V_481 = 5 ;
struct V_12 * V_482 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_483:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_377 = 0 , V_93 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_187 ( V_11 ) )
V_93 = V_13 -> V_43 ;
else
V_377 = V_11 -> V_484 ;
V_29 = F_188 ( V_9 -> V_469 , V_377 , V_93 , 0 ,
NULL ) ;
if ( ! F_189 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_190 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_485;
}
}
V_485:
if ( ! V_11 )
return;
if ( V_480 ) {
if ( V_13 != V_482 ) {
F_191 ( 100 ) ;
V_482 = V_13 ;
goto V_483;
}
if ( -- V_481 ) {
F_191 ( 100 ) ;
goto V_483;
}
F_192 ( V_9 ,
L_51 ) ;
}
F_193 ( V_486 , & V_9 -> V_487 ,
F_194 ( V_120 ) ) ;
}
int F_195 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_196 ( V_13 -> V_29 , V_488 ) ;
return 1 ;
}
return 0 ;
}
static void F_197 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_198 ( & V_9 -> V_469 -> V_489 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_199 ( V_29 ) == 0 ) {
F_196 ( V_29 , V_488 ) ;
} else {
F_200 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_201 ( & V_9 -> V_469 -> V_489 ) ;
if ( V_29 ) {
F_147 ( V_13 , L_52 ,
F_202 ( & V_29 -> V_490 ) ) ;
F_203 ( V_29 ) ;
F_190 ( V_29 ) ;
}
}
static void F_204 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_491 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_491 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_205 ( V_13 ) )
F_206 ( V_13 ) ;
F_197 ( V_13 ) ;
}
}
void F_207 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_208 ( V_13 -> V_29 , V_223 ,
V_492 ) ;
}
void F_209 ( struct V_493 * V_494 )
{
struct V_8 * V_9 =
F_210 ( V_494 , struct V_8 , V_487 . V_494 ) ;
int V_177 ;
if ( V_9 -> V_39 & V_495 ) {
F_101 ( L_53 ) ;
return;
}
#ifdef F_211
while ( V_496 )
F_191 ( 10 ) ;
#endif
F_101 ( L_31 ) ;
F_198 ( & V_9 -> V_497 ) ;
F_204 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_376 )
for ( V_177 = 0 ; V_177 < V_498 ; V_177 ++ )
F_204 ( & V_9 -> V_376 [ V_177 ] ) ;
F_186 ( V_9 , 0 ) ;
F_201 ( & V_9 -> V_497 ) ;
F_101 ( L_33 ) ;
}
int F_212 ( struct V_6 * V_7 , unsigned int V_377 ,
unsigned int V_93 , T_7 V_378 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_65 -> V_189 )
return - V_24 ;
if ( V_378 != V_499 && V_378 )
return - V_20 ;
if ( ! F_160 ( V_9 ) ) {
if ( V_377 != V_499 && V_377 )
return - V_20 ;
V_43 = V_93 ;
} else {
if ( V_93 != V_499 && V_93 )
return - V_20 ;
V_43 = V_377 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_499 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_500 * V_501 = & V_11 -> V_52 ;
V_501 -> V_502 |= V_503 ;
V_501 -> V_88 |= V_89 ;
}
} else {
struct V_12 * V_13 = F_159 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_500 * V_501 = & V_13 -> V_11 -> V_52 ;
V_501 -> V_502 |= 1 << V_13 -> V_43 ;
V_501 -> V_88 |= V_89 ;
} else
V_33 = - V_20 ;
}
if ( V_33 == 0 ) {
F_8 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_35 ( V_9 ) ;
} else
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
}
void F_213 ( struct V_493 * V_494 )
{
struct V_8 * V_9 =
F_210 ( V_494 , struct V_8 , V_504 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_198 ( & V_9 -> V_497 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_199 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_214 ( & ( V_29 -> V_490 ) ) ;
F_190 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_201 ( & V_9 -> V_497 ) ;
}
struct V_8 * F_215 ( struct V_461 * V_34 ,
struct V_505 * V_506 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_216 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_507 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_508 = V_506 -> V_508 ;
V_9 -> V_509 = V_506 -> V_509 ;
V_9 -> V_510 = V_506 -> V_510 ;
V_9 -> V_16 |= V_506 -> V_16 ;
V_9 -> V_65 = V_506 -> V_511 ;
V_9 -> V_512 = V_513 ;
return V_9 ;
}
int F_217 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_65 -> V_189 )
V_9 -> V_39 &= ~ V_514 ;
return 0 ;
}
void F_218 ( struct V_8 * V_9 )
{
}
void F_219 ( struct V_8 * V_9 )
{
F_220 ( V_9 ) ;
}
int F_221 ( struct V_8 * V_9 )
{
return F_222 ( V_9 ) ;
}
int F_223 ( struct V_8 * V_9 )
{
int V_33 = V_9 -> V_65 -> V_515 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_191 = F_224 ( & V_516 ) ;
return 0 ;
}
void F_225 ( struct V_8 * V_9 )
{
if ( V_9 -> V_65 -> V_517 )
V_9 -> V_65 -> V_517 ( V_9 ) ;
F_46 ( V_9 ) ;
}
int F_226 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_65 ( V_29 ) ;
F_70 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_227 ( struct V_56 * V_57 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_174 ( V_9 , V_57 ) ;
if ( F_67 ( F_88 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_176 ( V_57 , V_9 -> V_11 . V_1 ) ;
else {
V_57 -> V_61 = ( V_449 << 16 ) ;
V_57 -> V_80 ( V_57 ) ;
}
return V_33 ;
}
int F_228 ( struct V_8 * V_9 )
{
unsigned int V_518 = V_9 -> V_34 -> V_519 ;
unsigned int V_177 , V_142 ;
for ( V_177 = 0 , V_142 = V_9 -> V_520 + 1 ; V_177 < V_518 ; V_177 ++ , V_142 ++ ) {
V_142 = V_142 < V_518 ? V_142 : 0 ;
if ( V_142 == V_521 )
continue;
if ( ! F_229 ( V_142 , & V_9 -> V_522 ) ) {
V_9 -> V_520 = V_142 ;
return V_142 ;
}
}
return - 1 ;
}
void F_230 ( unsigned int V_142 , struct V_8 * V_9 )
{
F_231 ( V_142 , & V_9 -> V_522 ) ;
}
