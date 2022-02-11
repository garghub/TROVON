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
unsigned long V_16 , V_30 ;
unsigned int V_31 ( V_32 ) ;
int V_33 = 0 ;
V_9 = F_3 ( V_29 -> V_34 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_13 ( V_9 , V_29 ) ;
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
F_14 ( V_13 -> V_44 , V_30 ) )
V_32 = F_15 ( V_13 -> V_44 - V_30 ) ;
else
V_32 = 0 ;
V_36:
F_16 ( V_9 -> V_21 ) ;
return V_33 ? V_33 : snprintf ( V_4 , 20 , L_2 , V_32 ) ;
}
static T_1 F_17 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 , T_2 V_45 )
{
struct V_28 * V_29 = F_12 ( V_1 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 ;
long int V_46 ;
unsigned long V_16 ;
int V_33 ;
V_33 = F_18 ( V_4 , 10 , & V_46 ) ;
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
V_13 = F_13 ( V_9 , V_29 ) ;
if ( F_19 ( ! V_13 ) ) {
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
V_13 -> V_44 = F_20 ( V_38 , V_46 ) ;
V_13 -> V_11 -> V_52 . V_53 [ V_13 -> V_43 ] |= V_54 ;
F_8 ( V_9 ) ;
F_21 ( & V_9 -> V_55 ) ;
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
void F_22 ( struct V_56 * V_57 , T_3 V_58 , T_3 V_59 , T_3 V_60 )
{
if ( ! V_57 )
return;
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
F_23 ( 0 , V_57 -> V_64 , V_58 , V_59 , V_60 ) ;
}
void F_24 ( struct V_56 * V_57 ,
const struct V_65 * V_66 )
{
T_4 V_67 ;
if ( ! V_57 )
return;
V_67 = F_25 ( V_66 , NULL ) ;
F_26 ( V_57 -> V_64 , V_67 ) ;
}
static T_1
F_27 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_68 -> V_69 && ( V_9 -> V_16 & V_70 ) )
return V_9 -> V_68 -> V_69 ( V_9 , V_4 , V_5 ) ;
return - V_20 ;
}
static T_1
F_28 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_68 -> V_71 && ( V_9 -> V_16 & V_70 ) )
return V_9 -> V_68 -> V_71 ( V_9 , V_4 ) ;
return - V_20 ;
}
static T_1
F_29 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_4 , 23 , L_3 , V_9 -> V_72 ) ;
}
static T_1
F_30 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_73 = F_13 ( V_9 , V_29 ) ;
if ( V_73 && V_9 -> V_68 -> V_74 &&
( V_9 -> V_16 & V_75 ) )
return V_9 -> V_68 -> V_74 ( V_73 , V_4 ) ;
return - V_20 ;
}
static T_1
F_31 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_73 = F_13 ( V_9 , V_29 ) ;
enum V_76 V_77 ;
int V_33 ;
if ( V_73 && V_9 -> V_68 -> V_78 &&
( V_9 -> V_16 & V_75 ) ) {
V_77 = F_32 ( V_4 , NULL , 0 ) ;
switch ( V_77 ) {
case V_79 : case V_80 : case V_81 :
V_33 = V_9 -> V_68 -> V_78 ( V_73 , V_77 ) ;
if ( ! V_33 )
return V_5 ;
else
return V_33 ;
}
}
return - V_20 ;
}
static void F_33 ( struct V_56 * V_57 )
{
F_22 ( V_57 , V_82 , 0x24 , 0x0 ) ;
V_57 -> V_83 ( V_57 ) ;
}
int F_34 ( struct V_28 * V_29 , struct V_84 * V_85 ,
T_5 V_86 , int V_87 [] )
{
V_87 [ 0 ] = 255 ;
V_87 [ 1 ] = 63 ;
F_35 ( V_86 , 255 * 63 ) ;
V_87 [ 2 ] = V_86 ;
return 0 ;
}
void F_36 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_13 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_88 < V_13 -> V_89 ) {
V_13 -> V_16 |= V_90 ;
V_13 -> V_11 -> V_52 . V_91 |= V_92 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_37 ( V_9 ) ;
}
static int F_38 ( struct V_8 * V_9 , struct V_28 * V_29 ,
void T_6 * V_93 )
{
struct V_12 * V_13 = F_13 ( V_9 , V_29 ) ;
T_7 T_6 * V_94 = V_93 ;
char V_4 [ 40 ] ;
if ( ! V_13 )
return - V_95 ;
if ( F_39 ( V_94 , V_13 -> V_96 , V_97 * sizeof( T_7 ) ) )
return - V_98 ;
F_40 ( V_13 -> V_96 , V_4 , V_99 , V_100 ) ;
if ( F_39 ( V_94 + V_99 , V_4 , V_100 ) )
return - V_98 ;
F_40 ( V_13 -> V_96 , V_4 , V_101 , V_102 ) ;
if ( F_39 ( V_94 + V_101 , V_4 , V_102 ) )
return - V_98 ;
F_40 ( V_13 -> V_96 , V_4 , V_103 , V_104 ) ;
if ( F_39 ( V_94 + V_103 , V_4 , V_104 ) )
return - V_98 ;
return 0 ;
}
int F_41 ( struct V_28 * V_105 , void T_6 * V_93 )
{
int V_33 = 0 ;
T_3 V_106 [ V_107 ] ;
T_3 args [ 4 ] , * V_108 = NULL , * V_109 = NULL ;
int V_110 = 0 ;
enum V_111 V_112 ;
int V_113 ;
if ( V_93 == NULL )
return - V_20 ;
if ( F_42 ( args , V_93 , sizeof( args ) ) )
return - V_98 ;
V_109 = F_43 ( V_114 , V_115 ) ;
if ( ! V_109 )
return - V_116 ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
if ( args [ 3 ] ) {
V_110 = V_117 * args [ 3 ] ;
V_108 = F_44 ( V_110 , V_118 ) ;
if ( V_108 == NULL ) {
V_33 = - V_116 ;
goto error;
}
V_106 [ 1 ] = ( 4 << 1 ) ;
V_106 [ 2 ] = 0x0e ;
V_112 = V_119 ;
} else {
V_106 [ 1 ] = ( 3 << 1 ) ;
V_106 [ 2 ] = 0x20 ;
V_112 = V_120 ;
}
V_106 [ 0 ] = V_121 ;
V_106 [ 4 ] = args [ 2 ] ;
if ( args [ 0 ] == V_122 ) {
V_106 [ 6 ] = args [ 3 ] ;
V_106 [ 8 ] = args [ 1 ] ;
V_106 [ 10 ] = 0x4f ;
V_106 [ 12 ] = 0xc2 ;
} else {
V_106 [ 6 ] = args [ 1 ] ;
}
V_106 [ 14 ] = args [ 0 ] ;
V_113 = F_45 ( V_105 , V_106 , V_112 , V_108 , V_110 ,
V_109 , ( 10 * V_123 ) , 5 , 0 , NULL ) ;
if ( F_46 ( V_113 ) == V_62 ) {
T_3 * V_124 = V_109 + 8 ;
V_113 &= ~ ( 0xFF << 24 ) ;
if ( V_113 & V_63 ) {
struct V_125 V_126 ;
F_47 ( V_109 , V_114 ,
& V_126 ) ;
if ( V_126 . V_127 == V_128 &&
V_126 . V_59 == 0 && V_126 . V_60 == 0x1d )
V_113 &= ~ V_63 ;
}
if ( V_109 [ 0 ] == 0x72 &&
V_124 [ 0 ] == 0x09 ) {
args [ 0 ] = V_124 [ 13 ] ;
args [ 1 ] = V_124 [ 3 ] ;
args [ 2 ] = V_124 [ 5 ] ;
if ( F_39 ( V_93 , args , sizeof( args ) ) )
V_33 = - V_98 ;
}
}
if ( V_113 ) {
V_33 = - V_129 ;
goto error;
}
if ( ( V_108 )
&& F_39 ( V_93 + sizeof( args ) , V_108 , V_110 ) )
V_33 = - V_98 ;
error:
F_48 ( V_109 ) ;
F_48 ( V_108 ) ;
return V_33 ;
}
int F_49 ( struct V_28 * V_105 , void T_6 * V_93 )
{
int V_33 = 0 ;
T_3 V_106 [ V_107 ] ;
T_3 args [ 7 ] , * V_109 = NULL ;
int V_113 ;
if ( V_93 == NULL )
return - V_20 ;
if ( F_42 ( args , V_93 , sizeof( args ) ) )
return - V_98 ;
V_109 = F_43 ( V_114 , V_115 ) ;
if ( ! V_109 )
return - V_116 ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
V_106 [ 0 ] = V_121 ;
V_106 [ 1 ] = ( 3 << 1 ) ;
V_106 [ 2 ] = 0x20 ;
V_106 [ 4 ] = args [ 1 ] ;
V_106 [ 6 ] = args [ 2 ] ;
V_106 [ 8 ] = args [ 3 ] ;
V_106 [ 10 ] = args [ 4 ] ;
V_106 [ 12 ] = args [ 5 ] ;
V_106 [ 13 ] = args [ 6 ] & 0x4f ;
V_106 [ 14 ] = args [ 0 ] ;
V_113 = F_45 ( V_105 , V_106 , V_120 , NULL , 0 ,
V_109 , ( 10 * V_123 ) , 5 , 0 , NULL ) ;
if ( F_46 ( V_113 ) == V_62 ) {
T_3 * V_124 = V_109 + 8 ;
V_113 &= ~ ( 0xFF << 24 ) ;
if ( V_113 & V_63 ) {
struct V_125 V_126 ;
F_47 ( V_109 , V_114 ,
& V_126 ) ;
if ( V_126 . V_127 == V_128 &&
V_126 . V_59 == 0 && V_126 . V_60 == 0x1d )
V_113 &= ~ V_63 ;
}
if ( V_109 [ 0 ] == 0x72 &&
V_124 [ 0 ] == 0x09 ) {
args [ 0 ] = V_124 [ 13 ] ;
args [ 1 ] = V_124 [ 3 ] ;
args [ 2 ] = V_124 [ 5 ] ;
args [ 3 ] = V_124 [ 7 ] ;
args [ 4 ] = V_124 [ 9 ] ;
args [ 5 ] = V_124 [ 11 ] ;
args [ 6 ] = V_124 [ 12 ] ;
if ( F_39 ( V_93 , args , sizeof( args ) ) )
V_33 = - V_98 ;
}
}
if ( V_113 ) {
V_33 = - V_129 ;
goto error;
}
error:
F_48 ( V_109 ) ;
return V_33 ;
}
static int F_50 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 & V_130 )
return 1 ;
if ( V_9 -> V_39 & V_131 )
return 1 ;
return 0 ;
}
int F_51 ( struct V_8 * V_9 , struct V_28 * V_105 ,
int V_57 , void T_6 * V_93 )
{
int V_77 = - V_20 , V_33 = - V_20 ;
unsigned long V_16 ;
switch ( V_57 ) {
case V_132 :
F_5 ( V_9 -> V_21 , V_16 ) ;
V_77 = F_50 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_39 ( V_93 , & V_77 , 1 ) )
return - V_98 ;
return 0 ;
case V_133 :
V_77 = ( unsigned long ) V_93 ;
V_33 = 0 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_9 -> V_39 & V_134 ) {
if ( V_77 )
V_9 -> V_39 |= V_131 ;
else
V_9 -> V_39 &= ~ V_131 ;
} else {
if ( V_77 != F_50 ( V_9 ) )
V_33 = - V_20 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
case V_135 :
return F_38 ( V_9 , V_105 , V_93 ) ;
case V_136 :
if ( ! F_52 ( V_137 ) || ! F_52 ( V_138 ) )
return - V_139 ;
return F_41 ( V_105 , V_93 ) ;
case V_140 :
if ( ! F_52 ( V_137 ) || ! F_52 ( V_138 ) )
return - V_139 ;
return F_49 ( V_105 , V_93 ) ;
default:
V_33 = - V_141 ;
break;
}
return V_33 ;
}
int F_53 ( struct V_28 * V_105 , int V_57 , void T_6 * V_93 )
{
return F_51 ( F_3 ( V_105 -> V_34 ) ,
V_105 , V_57 , V_93 ) ;
}
static struct V_142 * F_54 ( struct V_12 * V_13 ,
struct V_56 * V_57 )
{
struct V_142 * V_143 ;
V_143 = F_55 ( V_13 , V_57 -> V_144 -> V_145 ) ;
if ( V_143 ) {
V_143 -> V_146 = V_57 ;
V_143 -> V_147 = V_57 -> V_83 ;
V_143 -> V_148 = F_56 ( V_57 ) ;
V_143 -> V_149 = F_57 ( V_57 ) ;
} else {
V_57 -> V_61 = ( V_150 << 16 ) | ( V_151 << 1 ) ;
V_57 -> V_83 ( V_57 ) ;
}
return V_143 ;
}
static void F_58 ( struct V_142 * V_143 )
{
struct V_56 * V_152 = V_143 -> V_146 ;
V_143 -> V_153 = V_152 -> V_144 -> V_154 ;
V_143 -> V_155 = F_59 ( V_152 ) + V_143 -> V_153 ;
}
static void F_60 ( unsigned V_96 , struct V_65 * V_66 )
{
T_3 V_156 = V_66 -> V_157 , V_158 = V_66 -> V_159 ;
F_61 ( V_160 L_4 , V_96 , V_156 ) ;
if ( V_156 & V_161 ) {
F_61 ( L_5 ) ;
} else {
if ( V_156 & V_162 ) F_61 ( L_6 ) ;
if ( V_156 & V_163 ) F_61 ( L_7 ) ;
if ( V_156 & V_164 ) F_61 ( L_8 ) ;
if ( V_156 & V_165 ) F_61 ( L_9 ) ;
if ( V_156 & V_166 ) F_61 ( L_10 ) ;
if ( V_156 & V_167 ) F_61 ( L_11 ) ;
if ( V_156 & V_168 ) F_61 ( L_12 ) ;
F_61 ( L_13 ) ;
if ( V_158 ) {
F_61 ( V_160 L_14 , V_96 , V_158 ) ;
if ( V_158 & V_169 ) F_61 ( L_15 ) ;
if ( V_158 & V_170 ) {
if ( V_158 & V_169 )
F_61 ( L_16 ) ;
else F_61 ( L_17 ) ;
}
if ( V_158 & V_171 ) F_61 ( L_18 ) ;
if ( V_158 & V_172 ) F_61 ( L_19 ) ;
if ( V_158 & V_173 ) F_61 ( L_20 ) ;
if ( V_158 & V_174 ) F_61 ( L_21 ) ;
F_61 ( L_13 ) ;
}
}
}
static void F_62 ( unsigned V_96 , T_3 V_175 , T_3 V_176 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 , int V_177 )
{
int V_178 ;
static const unsigned char V_179 [] [ 4 ] = {
{ 0xd1 , V_180 , 0x00 , 0x00 } ,
{ 0xd0 , V_180 , 0x00 , 0x00 } ,
{ 0x61 , V_181 , 0x00 , 0x00 } ,
{ 0x84 , V_180 , 0x47 , 0x00 } ,
{ 0x37 , V_182 , 0x04 , 0x00 } ,
{ 0x09 , V_182 , 0x04 , 0x00 } ,
{ 0x01 , V_183 , 0x13 , 0x00 } ,
{ 0x02 , V_181 , 0x00 , 0x00 } ,
{ 0x08 , V_182 , 0x04 , 0x00 } ,
{ 0x10 , V_82 , 0x21 , 0x00 } ,
{ 0x20 , V_184 , 0x28 , 0x00 } ,
{ 0x40 , V_183 , 0x11 , 0x04 } ,
{ 0x80 , V_183 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_185 [] [ 4 ] = {
{ 0x80 , V_180 , 0x47 , 0x00 } ,
{ 0x40 , V_82 , 0x21 , 0x04 } ,
{ 0x20 , V_181 , 0x44 , 0x00 } ,
{ 0x08 , V_180 , 0x47 , 0x00 } ,
{ 0x04 , V_128 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_175 & V_161 ) {
V_176 = 0 ;
}
if ( V_176 ) {
for ( V_178 = 0 ; V_179 [ V_178 ] [ 0 ] != 0xFF ; V_178 ++ ) {
if ( ( V_179 [ V_178 ] [ 0 ] & V_176 ) ==
V_179 [ V_178 ] [ 0 ] ) {
* V_58 = V_179 [ V_178 ] [ 1 ] ;
* V_59 = V_179 [ V_178 ] [ 2 ] ;
* V_60 = V_179 [ V_178 ] [ 3 ] ;
goto V_186;
}
}
}
for ( V_178 = 0 ; V_185 [ V_178 ] [ 0 ] != 0xFF ; V_178 ++ ) {
if ( V_185 [ V_178 ] [ 0 ] & V_175 ) {
* V_58 = V_185 [ V_178 ] [ 1 ] ;
* V_59 = V_185 [ V_178 ] [ 2 ] ;
* V_60 = V_185 [ V_178 ] [ 3 ] ;
goto V_186;
}
}
* V_58 = V_180 ;
* V_59 = 0x00 ;
* V_60 = 0x00 ;
V_186:
if ( V_177 )
F_61 ( V_187 L_22
L_23 ,
V_96 , V_175 , V_176 , * V_58 , * V_59 , * V_60 ) ;
return;
}
static void F_63 ( struct V_142 * V_143 )
{
struct V_56 * V_57 = V_143 -> V_146 ;
struct V_65 * V_66 = & V_143 -> V_188 ;
unsigned char * V_189 = V_57 -> V_64 ;
unsigned char * V_124 = V_189 + 8 ;
int V_177 = V_143 -> V_9 -> V_68 -> V_190 == NULL ;
memset ( V_189 , 0 , V_114 ) ;
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
if ( V_143 -> V_191 ||
V_66 -> V_157 & ( V_161 | V_163 | V_168 | V_165 ) ) {
F_62 ( V_143 -> V_9 -> V_192 , V_66 -> V_157 , V_66 -> V_159 ,
& V_189 [ 1 ] , & V_189 [ 2 ] , & V_189 [ 3 ] , V_177 ) ;
V_189 [ 1 ] &= 0x0f ;
} else {
V_189 [ 1 ] = V_128 ;
V_189 [ 2 ] = 0 ;
V_189 [ 3 ] = 0x1D ;
}
V_189 [ 0 ] = 0x72 ;
V_124 [ 0 ] = 0x09 ;
V_189 [ 7 ] = 14 ;
V_124 [ 1 ] = 12 ;
V_124 [ 2 ] = 0x00 ;
V_124 [ 3 ] = V_66 -> V_159 ;
V_124 [ 5 ] = V_66 -> V_193 ;
V_124 [ 7 ] = V_66 -> V_194 ;
V_124 [ 9 ] = V_66 -> V_195 ;
V_124 [ 11 ] = V_66 -> V_196 ;
V_124 [ 12 ] = V_66 -> V_1 ;
V_124 [ 13 ] = V_66 -> V_157 ;
if ( V_66 -> V_16 & V_197 ) {
V_124 [ 2 ] |= 0x01 ;
V_124 [ 4 ] = V_66 -> V_198 ;
V_124 [ 6 ] = V_66 -> V_199 ;
V_124 [ 8 ] = V_66 -> V_200 ;
V_124 [ 10 ] = V_66 -> V_201 ;
}
}
static void F_64 ( struct V_142 * V_143 )
{
struct V_12 * V_13 = V_143 -> V_13 ;
struct V_56 * V_57 = V_143 -> V_146 ;
struct V_65 * V_66 = & V_143 -> V_188 ;
unsigned char * V_189 = V_57 -> V_64 ;
unsigned char * V_124 = V_189 + 8 ;
int V_177 = V_143 -> V_9 -> V_68 -> V_190 == NULL ;
T_4 V_202 ;
memset ( V_189 , 0 , V_114 ) ;
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
V_189 [ 0 ] = 0x72 ;
if ( V_143 -> V_191 ||
V_66 -> V_157 & ( V_161 | V_163 | V_168 | V_165 ) ) {
F_62 ( V_143 -> V_9 -> V_192 , V_66 -> V_157 , V_66 -> V_159 ,
& V_189 [ 1 ] , & V_189 [ 2 ] , & V_189 [ 3 ] , V_177 ) ;
V_189 [ 1 ] &= 0x0f ;
}
V_202 = F_25 ( & V_143 -> V_188 , V_13 ) ;
V_189 [ 7 ] = 12 ;
V_124 [ 0 ] = 0x00 ;
V_124 [ 1 ] = 10 ;
V_124 [ 2 ] |= 0x80 ;
V_124 [ 6 ] = V_202 >> 40 ;
V_124 [ 7 ] = V_202 >> 32 ;
V_124 [ 8 ] = V_202 >> 24 ;
V_124 [ 9 ] = V_202 >> 16 ;
V_124 [ 10 ] = V_202 >> 8 ;
V_124 [ 11 ] = V_202 ;
}
static void F_65 ( struct V_28 * V_29 )
{
V_29 -> V_203 = 1 ;
V_29 -> V_204 = 1 ;
V_29 -> V_205 = 1 ;
V_29 -> V_206 = 1 ;
V_29 -> V_207 = 1 ;
}
static int F_66 ( struct V_144 * V_208 )
{
if ( F_67 ( V_208 -> V_209 != V_210 ) )
return 0 ;
if ( ! F_68 ( V_208 ) || ( V_208 -> V_211 & V_212 ) )
return 0 ;
return F_69 ( V_208 -> V_57 [ 0 ] ) == V_213 ;
}
static int F_70 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_214 * V_215 = V_29 -> V_214 ;
if ( ! F_71 ( V_13 -> V_96 ) )
V_13 -> V_16 |= V_37 ;
F_72 ( V_215 , V_13 -> V_216 ) ;
if ( V_13 -> V_49 == V_217 ) {
void * V_4 ;
V_29 -> V_218 = V_117 ;
F_73 ( V_215 , V_219 - 1 ) ;
V_4 = F_44 ( V_220 , V_215 -> V_221 | V_118 ) ;
if ( ! V_4 ) {
F_74 ( V_13 , L_24 ) ;
return - V_116 ;
}
F_75 ( V_215 , F_66 , V_4 , V_220 ) ;
} else {
V_29 -> V_218 = F_76 ( V_13 -> V_96 ) ;
V_29 -> V_222 = 1 ;
}
if ( V_29 -> V_218 > V_27 )
F_77 ( V_13 ,
L_25 ,
V_29 -> V_218 ) ;
F_78 ( V_215 , V_29 -> V_218 - 1 ) ;
if ( V_13 -> V_16 & V_223 )
F_79 ( V_224 , V_29 -> V_225 ) ;
if ( V_13 -> V_16 & V_226 ) {
int V_227 ;
V_227 = F_80 ( V_29 -> V_34 -> V_228 , F_81 ( V_13 -> V_96 ) ) ;
V_227 = F_80 ( V_229 - 1 , V_227 ) ;
F_82 ( V_29 , V_227 ) ;
}
F_83 ( V_215 , false ) ;
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
struct V_214 * V_215 = V_29 -> V_214 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_68 -> V_190 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_85 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_230 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_48 ( V_215 -> V_231 ) ;
V_215 -> V_231 = NULL ;
V_215 -> V_232 = 0 ;
}
int F_87 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_233 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_233 < 1 || V_233 == V_29 -> V_233 )
return V_29 -> V_233 ;
V_13 = F_13 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_88 ( V_13 ) )
return V_29 -> V_233 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_234 ;
if ( V_233 == 1 || ! F_89 ( V_13 ) ) {
V_13 -> V_16 |= V_234 ;
V_233 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_233 = F_80 ( V_233 , V_29 -> V_34 -> V_228 ) ;
V_233 = F_80 ( V_233 , F_81 ( V_13 -> V_96 ) ) ;
V_233 = F_80 ( V_233 , V_229 - 1 ) ;
if ( V_29 -> V_233 == V_233 )
return - V_20 ;
return F_82 ( V_29 , V_233 ) ;
}
int F_90 ( struct V_28 * V_29 , int V_233 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_87 ( V_9 , V_29 , V_233 ) ;
}
static unsigned int F_91 ( struct V_142 * V_143 )
{
struct V_56 * V_152 = V_143 -> V_146 ;
struct V_65 * V_66 = & V_143 -> V_66 ;
const T_3 * V_235 = V_152 -> V_236 ;
if ( V_152 -> V_237 < 5 )
goto V_238;
V_66 -> V_16 |= V_239 | V_240 ;
V_66 -> V_241 = V_242 ;
if ( V_235 [ 1 ] & 0x1 ) {
;
}
if ( V_235 [ 4 ] & 0x2 )
goto V_238;
if ( ( ( V_235 [ 4 ] >> 4 ) & 0xf ) != 0 )
goto V_238;
if ( V_235 [ 4 ] & 0x1 ) {
V_66 -> V_193 = 1 ;
if ( V_143 -> V_13 -> V_16 & V_243 ) {
V_66 -> V_16 |= V_244 ;
V_66 -> V_196 = 0x0 ;
V_66 -> V_195 = 0x0 ;
V_66 -> V_194 = 0x0 ;
V_66 -> V_1 |= V_245 ;
} else {
V_66 -> V_194 = 0x1 ;
V_66 -> V_195 = 0x0 ;
V_66 -> V_196 = 0x0 ;
}
V_66 -> V_157 = V_246 ;
} else {
if ( ( V_143 -> V_9 -> V_16 & V_247 ) &&
V_248 == V_249 )
goto V_250;
if ( ( V_143 -> V_9 -> V_16 & V_251 ) &&
F_92 () )
goto V_250;
V_66 -> V_157 = V_252 ;
}
return 0 ;
V_238:
F_22 ( V_152 , V_82 , 0x24 , 0x0 ) ;
return 1 ;
V_250:
V_152 -> V_61 = V_253 ;
return 1 ;
}
static unsigned int F_93 ( struct V_142 * V_143 )
{
struct V_65 * V_66 = & V_143 -> V_66 ;
V_66 -> V_16 |= V_239 ;
V_66 -> V_241 = V_242 ;
if ( V_143 -> V_13 -> V_16 & V_254 )
V_66 -> V_157 = V_255 ;
else
V_66 -> V_157 = V_256 ;
V_143 -> V_16 |= V_257 ;
return 0 ;
}
static void F_94 ( const T_3 * V_235 , T_4 * V_258 , T_8 * V_259 )
{
T_4 V_260 = 0 ;
T_8 V_45 ;
F_95 ( L_26 ) ;
V_260 |= ( ( T_4 ) ( V_235 [ 1 ] & 0x1f ) ) << 16 ;
V_260 |= ( ( T_4 ) V_235 [ 2 ] ) << 8 ;
V_260 |= ( ( T_4 ) V_235 [ 3 ] ) ;
V_45 = V_235 [ 4 ] ;
* V_258 = V_260 ;
* V_259 = V_45 ;
}
static void F_96 ( const T_3 * V_235 , T_4 * V_258 , T_8 * V_259 )
{
T_4 V_260 = 0 ;
T_8 V_45 = 0 ;
F_95 ( L_27 ) ;
V_260 |= ( ( T_4 ) V_235 [ 2 ] ) << 24 ;
V_260 |= ( ( T_4 ) V_235 [ 3 ] ) << 16 ;
V_260 |= ( ( T_4 ) V_235 [ 4 ] ) << 8 ;
V_260 |= ( ( T_4 ) V_235 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_235 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_235 [ 8 ] ) ;
* V_258 = V_260 ;
* V_259 = V_45 ;
}
static void F_97 ( const T_3 * V_235 , T_4 * V_258 , T_8 * V_259 )
{
T_4 V_260 = 0 ;
T_8 V_45 = 0 ;
F_95 ( L_28 ) ;
V_260 |= ( ( T_4 ) V_235 [ 2 ] ) << 56 ;
V_260 |= ( ( T_4 ) V_235 [ 3 ] ) << 48 ;
V_260 |= ( ( T_4 ) V_235 [ 4 ] ) << 40 ;
V_260 |= ( ( T_4 ) V_235 [ 5 ] ) << 32 ;
V_260 |= ( ( T_4 ) V_235 [ 6 ] ) << 24 ;
V_260 |= ( ( T_4 ) V_235 [ 7 ] ) << 16 ;
V_260 |= ( ( T_4 ) V_235 [ 8 ] ) << 8 ;
V_260 |= ( ( T_4 ) V_235 [ 9 ] ) ;
V_45 |= ( ( T_8 ) V_235 [ 10 ] ) << 24 ;
V_45 |= ( ( T_8 ) V_235 [ 11 ] ) << 16 ;
V_45 |= ( ( T_8 ) V_235 [ 12 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_235 [ 13 ] ) ;
* V_258 = V_260 ;
* V_259 = V_45 ;
}
static unsigned int F_98 ( struct V_142 * V_143 )
{
struct V_56 * V_152 = V_143 -> V_146 ;
struct V_65 * V_66 = & V_143 -> V_66 ;
struct V_12 * V_13 = V_143 -> V_13 ;
T_4 V_261 = V_143 -> V_13 -> V_88 ;
const T_3 * V_235 = V_152 -> V_236 ;
T_4 V_202 ;
T_8 V_262 ;
V_66 -> V_16 |= V_240 | V_239 ;
V_66 -> V_241 = V_242 ;
if ( V_235 [ 0 ] == V_263 ) {
if ( V_152 -> V_237 < 10 )
goto V_238;
F_96 ( V_235 , & V_202 , & V_262 ) ;
} else if ( V_235 [ 0 ] == V_264 ) {
if ( V_152 -> V_237 < 16 )
goto V_238;
F_97 ( V_235 , & V_202 , & V_262 ) ;
} else
goto V_238;
if ( ! V_262 )
goto V_265;
if ( V_202 >= V_261 )
goto V_266;
if ( ( V_202 + V_262 ) > V_261 )
goto V_266;
if ( V_13 -> V_16 & V_243 ) {
V_66 -> V_16 |= V_244 ;
if ( F_99 ( V_202 , V_262 ) ) {
V_66 -> V_157 = V_246 ;
V_66 -> V_1 |= ( V_202 >> 24 ) & 0xf ;
} else if ( F_100 ( V_202 , V_262 ) ) {
if ( ! ( V_13 -> V_16 & V_267 ) )
goto V_266;
V_66 -> V_16 |= V_197 ;
V_66 -> V_157 = V_268 ;
V_66 -> V_198 = ( V_262 >> 8 ) & 0xff ;
V_66 -> V_201 = ( V_202 >> 40 ) & 0xff ;
V_66 -> V_200 = ( V_202 >> 32 ) & 0xff ;
V_66 -> V_199 = ( V_202 >> 24 ) & 0xff ;
} else
goto V_266;
V_66 -> V_193 = V_262 & 0xff ;
V_66 -> V_196 = ( V_202 >> 16 ) & 0xff ;
V_66 -> V_195 = ( V_202 >> 8 ) & 0xff ;
V_66 -> V_194 = V_202 & 0xff ;
V_66 -> V_1 |= V_245 ;
} else {
T_8 V_269 , V_270 , V_271 , V_272 ;
if ( ! F_99 ( V_202 , V_262 ) )
goto V_266;
V_272 = ( T_8 ) V_202 / V_13 -> V_273 ;
V_271 = V_272 / V_13 -> V_274 ;
V_270 = V_272 % V_13 -> V_274 ;
V_269 = ( T_8 ) V_202 % V_13 -> V_273 + 1 ;
F_101 ( L_29 ,
( T_8 ) V_202 , V_272 , V_271 , V_270 , V_269 ) ;
if ( ( V_271 >> 16 ) || ( V_270 >> 4 ) || ( V_269 >> 8 ) || ( ! V_269 ) )
goto V_266;
V_66 -> V_157 = V_246 ;
V_66 -> V_193 = V_262 & 0xff ;
V_66 -> V_194 = V_269 ;
V_66 -> V_195 = V_271 ;
V_66 -> V_196 = V_271 >> 8 ;
V_66 -> V_1 |= V_270 ;
}
return 0 ;
V_238:
F_22 ( V_152 , V_82 , 0x24 , 0x0 ) ;
return 1 ;
V_266:
F_22 ( V_152 , V_82 , 0x21 , 0x0 ) ;
return 1 ;
V_265:
V_152 -> V_61 = V_253 ;
return 1 ;
}
static unsigned int F_102 ( struct V_142 * V_143 )
{
struct V_56 * V_152 = V_143 -> V_146 ;
const T_3 * V_235 = V_152 -> V_236 ;
unsigned int V_275 = 0 ;
T_4 V_202 ;
T_8 V_262 ;
int V_33 ;
if ( V_235 [ 0 ] == V_276 || V_235 [ 0 ] == V_277 || V_235 [ 0 ] == V_278 )
V_275 |= V_279 ;
switch ( V_235 [ 0 ] ) {
case V_280 :
case V_276 :
if ( F_19 ( V_152 -> V_237 < 10 ) )
goto V_238;
F_96 ( V_235 , & V_202 , & V_262 ) ;
if ( V_235 [ 1 ] & ( 1 << 3 ) )
V_275 |= V_281 ;
break;
case V_282 :
case V_277 :
if ( F_19 ( V_152 -> V_237 < 6 ) )
goto V_238;
F_94 ( V_235 , & V_202 , & V_262 ) ;
if ( ! V_262 )
V_262 = 256 ;
break;
case V_283 :
case V_278 :
if ( F_19 ( V_152 -> V_237 < 16 ) )
goto V_238;
F_97 ( V_235 , & V_202 , & V_262 ) ;
if ( V_235 [ 1 ] & ( 1 << 3 ) )
V_275 |= V_281 ;
break;
default:
F_101 ( L_30 ) ;
goto V_238;
}
if ( ! V_262 )
goto V_265;
V_143 -> V_16 |= V_257 ;
V_143 -> V_155 = V_262 * V_152 -> V_1 -> V_218 ;
V_33 = F_103 ( & V_143 -> V_66 , V_143 -> V_13 , V_202 , V_262 , V_275 ,
V_143 -> V_145 ) ;
if ( F_67 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_284 )
goto V_266;
V_238:
F_22 ( V_152 , V_82 , 0x24 , 0x0 ) ;
return 1 ;
V_266:
F_22 ( V_152 , V_82 , 0x21 , 0x0 ) ;
return 1 ;
V_265:
V_152 -> V_61 = V_253 ;
return 1 ;
}
static void F_104 ( struct V_142 * V_143 )
{
struct V_8 * V_9 = V_143 -> V_9 ;
struct V_56 * V_57 = V_143 -> V_146 ;
T_3 * V_235 = V_57 -> V_236 ;
int V_285 = ( V_143 -> V_191 != 0 ) ;
if ( ( ( V_235 [ 0 ] == V_121 ) || ( V_235 [ 0 ] == V_286 ) ) &&
( ( V_235 [ 2 ] & 0x20 ) || V_285 ) ) {
F_63 ( V_143 ) ;
} else {
if ( V_143 -> V_16 & V_287 ) {
V_57 -> V_61 = V_63 ;
} else if ( ! V_285 ) {
V_57 -> V_61 = V_253 ;
} else {
F_64 ( V_143 ) ;
}
}
if ( V_285 && ! V_9 -> V_68 -> V_190 )
F_60 ( V_9 -> V_192 , & V_143 -> V_188 ) ;
V_143 -> V_147 ( V_57 ) ;
F_105 ( V_143 ) ;
}
static int F_106 ( struct V_12 * V_13 , struct V_56 * V_57 ,
T_9 V_288 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_142 * V_143 ;
int V_33 ;
F_95 ( L_31 ) ;
V_143 = F_54 ( V_13 , V_57 ) ;
if ( ! V_143 )
goto V_289;
if ( V_57 -> V_290 == V_119 ||
V_57 -> V_290 == V_291 ) {
if ( F_19 ( F_59 ( V_57 ) < 1 ) ) {
F_77 ( V_13 , L_32 ) ;
goto V_292;
}
F_107 ( V_143 , F_56 ( V_57 ) , F_57 ( V_57 ) ) ;
V_143 -> V_293 = V_57 -> V_290 ;
}
V_143 -> V_294 = F_104 ;
if ( V_288 ( V_143 ) )
goto V_295;
if ( V_9 -> V_68 -> V_296 ) {
if ( ( V_33 = V_9 -> V_68 -> V_296 ( V_143 ) ) )
goto V_297;
}
F_108 ( V_143 ) ;
F_95 ( L_33 ) ;
return 0 ;
V_295:
F_105 ( V_143 ) ;
V_57 -> V_83 ( V_57 ) ;
F_101 ( L_34 ) ;
return 0 ;
V_292:
F_105 ( V_143 ) ;
V_57 -> V_61 = ( V_298 << 16 ) ;
V_57 -> V_83 ( V_57 ) ;
V_289:
F_101 ( L_35 ) ;
return 0 ;
V_297:
F_105 ( V_143 ) ;
F_101 ( L_36 ) ;
if ( V_33 == V_299 )
return V_300 ;
else
return V_301 ;
}
static void * F_109 ( struct V_56 * V_57 , bool V_302 ,
unsigned long * V_16 )
{
F_5 ( & V_303 , * V_16 ) ;
memset ( V_304 , 0 , V_305 ) ;
if ( V_302 )
F_110 ( F_56 ( V_57 ) , F_57 ( V_57 ) ,
V_304 , V_305 ) ;
return V_304 ;
}
static inline void F_111 ( struct V_56 * V_57 , bool V_306 ,
unsigned long * V_16 )
{
if ( V_306 )
F_112 ( F_56 ( V_57 ) , F_57 ( V_57 ) ,
V_304 , V_305 ) ;
F_9 ( & V_303 , * V_16 ) ;
}
static unsigned int F_113 ( struct V_307 * args , T_3 * V_308 )
{
const T_3 V_309 [] = {
0x00 ,
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
const T_3 V_310 [] = {
0x00 ,
0xA0 ,
0x04 ,
0xC0 ,
0x04 ,
0x60 ,
0x60 ,
0x20 ,
} ;
T_3 V_311 [] = {
V_312 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_95 ( L_31 ) ;
if ( F_114 ( args -> V_96 ) )
V_311 [ 1 ] |= ( 1 << 7 ) ;
if ( args -> V_13 -> V_49 == V_51 ) {
V_311 [ 0 ] = V_313 ;
V_311 [ 2 ] = 0x6 ;
}
memcpy ( V_308 , V_311 , sizeof( V_311 ) ) ;
memcpy ( & V_308 [ 8 ] , L_37 , 8 ) ;
F_40 ( args -> V_96 , & V_308 [ 16 ] , V_99 , 16 ) ;
F_40 ( args -> V_96 , & V_308 [ 32 ] , V_101 + 2 , 4 ) ;
if ( strncmp ( & V_308 [ 32 ] , L_38 , 4 ) == 0 )
F_40 ( args -> V_96 , & V_308 [ 32 ] , V_101 , 4 ) ;
if ( V_308 [ 32 ] == 0 || V_308 [ 32 ] == ' ' )
memcpy ( & V_308 [ 32 ] , L_39 , 4 ) ;
if ( args -> V_13 -> V_49 == V_51 )
memcpy ( V_308 + 58 , V_310 , sizeof( V_310 ) ) ;
else
memcpy ( V_308 + 58 , V_309 , sizeof( V_309 ) ) ;
return 0 ;
}
static unsigned int F_115 ( struct V_307 * args , T_3 * V_308 )
{
const T_3 V_314 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
} ;
V_308 [ 3 ] = sizeof( V_314 ) ;
memcpy ( V_308 + 4 , V_314 , sizeof( V_314 ) ) ;
return 0 ;
}
static unsigned int F_116 ( struct V_307 * args , T_3 * V_308 )
{
const T_3 V_311 [] = {
0 ,
0x80 ,
0 ,
V_104 ,
} ;
memcpy ( V_308 , V_311 , sizeof( V_311 ) ) ;
F_40 ( args -> V_96 , ( unsigned char * ) & V_308 [ 4 ] ,
V_103 , V_104 ) ;
return 0 ;
}
static unsigned int F_117 ( struct V_307 * args , T_3 * V_308 )
{
const int V_315 = 68 ;
int V_316 ;
V_308 [ 1 ] = 0x83 ;
V_316 = 4 ;
V_308 [ V_316 + 0 ] = 2 ;
V_308 [ V_316 + 3 ] = V_104 ;
V_316 += 4 ;
F_40 ( args -> V_96 , ( unsigned char * ) V_308 + V_316 ,
V_103 , V_104 ) ;
V_316 += V_104 ;
V_308 [ V_316 + 0 ] = 2 ;
V_308 [ V_316 + 1 ] = 1 ;
V_308 [ V_316 + 3 ] = V_315 ;
V_316 += 4 ;
memcpy ( V_308 + V_316 , L_37 , 8 ) ;
V_316 += 8 ;
F_40 ( args -> V_96 , ( unsigned char * ) V_308 + V_316 , V_99 ,
V_100 ) ;
V_316 += V_100 ;
F_40 ( args -> V_96 , ( unsigned char * ) V_308 + V_316 , V_103 ,
V_104 ) ;
V_316 += V_104 ;
if ( F_118 ( args -> V_96 ) ) {
V_308 [ V_316 + 0 ] = 1 ;
V_308 [ V_316 + 1 ] = 3 ;
V_308 [ V_316 + 3 ] = V_317 ;
V_316 += 4 ;
F_40 ( args -> V_96 , ( unsigned char * ) V_308 + V_316 ,
V_318 , V_317 ) ;
V_316 += V_317 ;
}
V_308 [ 3 ] = V_316 - 4 ;
return 0 ;
}
static unsigned int F_119 ( struct V_307 * args , T_3 * V_308 )
{
struct V_65 V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_308 [ 1 ] = 0x89 ;
V_308 [ 2 ] = ( 0x238 >> 8 ) ;
V_308 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_308 [ 8 ] , L_40 , 8 ) ;
memcpy ( & V_308 [ 16 ] , L_41 , 16 ) ;
memcpy ( & V_308 [ 32 ] , V_319 , 4 ) ;
V_66 . V_157 = V_162 ;
V_66 . V_194 = 0x1 ;
V_66 . V_193 = 0x1 ;
F_120 ( & V_66 , 0 , 1 , & V_308 [ 36 ] ) ;
V_308 [ 36 ] = 0x34 ;
V_308 [ 56 ] = V_320 ;
memcpy ( & V_308 [ 60 ] , & args -> V_96 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_121 ( struct V_307 * args , T_3 * V_308 )
{
T_7 V_321 ;
V_308 [ 1 ] = 0xb0 ;
V_308 [ 3 ] = 0x3c ;
V_321 = 1 << F_122 ( args -> V_96 ) ;
F_123 ( V_321 , & V_308 [ 6 ] ) ;
if ( F_124 ( args -> V_96 ) ) {
F_125 ( 65535 * 512 / 8 , & V_308 [ 36 ] ) ;
F_126 ( 1 , & V_308 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_127 ( struct V_307 * args , T_3 * V_308 )
{
int V_322 = F_128 ( args -> V_96 ) ;
int V_323 = F_129 ( args -> V_96 ) ;
V_308 [ 1 ] = 0xb1 ;
V_308 [ 3 ] = 0x3c ;
V_308 [ 4 ] = V_323 >> 8 ;
V_308 [ 5 ] = V_323 ;
V_308 [ 7 ] = V_322 ;
return 0 ;
}
static unsigned int F_130 ( struct V_307 * args , T_3 * V_308 )
{
V_308 [ 1 ] = 0xb2 ;
V_308 [ 3 ] = 0x4 ;
V_308 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_131 ( struct V_307 * args , T_3 * V_308 )
{
F_95 ( L_31 ) ;
return 0 ;
}
static void F_132 ( T_3 * V_324 , const T_3 * V_325 , int V_326 , bool V_327 )
{
if ( V_327 ) {
memcpy ( V_324 , V_325 , 2 ) ;
memset ( V_324 + 2 , 0 , V_326 - 2 ) ;
} else {
memcpy ( V_324 , V_325 , V_326 ) ;
}
}
static unsigned int F_133 ( T_7 * V_96 , T_3 * V_4 , bool V_327 )
{
F_132 ( V_4 , V_328 , sizeof( V_328 ) , V_327 ) ;
if ( V_327 || F_134 ( V_96 ) )
V_4 [ 2 ] |= ( 1 << 2 ) ;
if ( ! V_327 && ! F_135 ( V_96 ) )
V_4 [ 12 ] |= ( 1 << 5 ) ;
return sizeof( V_328 ) ;
}
static unsigned int F_136 ( T_3 * V_4 , bool V_327 )
{
F_132 ( V_4 , V_329 , sizeof( V_329 ) , V_327 ) ;
return sizeof( V_329 ) ;
}
static unsigned int F_137 ( T_3 * V_4 , bool V_327 )
{
F_132 ( V_4 , V_330 , sizeof( V_330 ) ,
V_327 ) ;
return sizeof( V_330 ) ;
}
static int F_138 ( T_7 * V_96 )
{
unsigned char V_331 [ V_100 + 1 ] , V_332 [ V_102 + 1 ] ;
if ( ! V_333 )
return 0 ;
if ( ! F_139 ( V_96 ) )
return 0 ;
F_140 ( V_96 , V_331 , V_99 , sizeof( V_331 ) ) ;
F_140 ( V_96 , V_332 , V_101 , sizeof( V_332 ) ) ;
if ( strcmp ( V_331 , L_42 ) )
return 1 ;
if ( strcmp ( V_332 , L_43 ) )
return 1 ;
return 0 ;
}
static unsigned int F_141 ( struct V_307 * args , T_3 * V_308 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_146 = args -> V_57 -> V_236 , * V_334 = V_308 ;
const T_3 V_335 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_336 , V_337 ;
unsigned int V_338 , V_339 , V_340 ;
T_3 V_341 ;
F_95 ( L_31 ) ;
V_340 = ( V_146 [ 0 ] == V_342 ) ;
V_338 = ! ( V_146 [ 1 ] & 0x8 ) ;
V_339 = V_146 [ 2 ] >> 6 ;
switch ( V_339 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_343;
default:
goto V_238;
}
if ( V_340 )
V_334 += 4 + ( V_338 ? 8 : 0 ) ;
else
V_334 += 8 + ( V_338 ? 8 : 0 ) ;
V_336 = V_146 [ 2 ] & 0x3f ;
V_337 = V_146 [ 3 ] ;
if ( V_337 && ( V_337 != V_344 ) )
goto V_238;
switch( V_336 ) {
case V_345 :
V_334 += F_137 ( V_334 , V_339 == 1 ) ;
break;
case V_346 :
V_334 += F_133 ( args -> V_96 , V_334 , V_339 == 1 ) ;
break;
case V_347 :
V_334 += F_136 ( V_334 , V_339 == 1 ) ;
break;
case V_348 :
V_334 += F_137 ( V_334 , V_339 == 1 ) ;
V_334 += F_133 ( args -> V_96 , V_334 , V_339 == 1 ) ;
V_334 += F_136 ( V_334 , V_339 == 1 ) ;
break;
default:
goto V_238;
}
V_341 = 0 ;
if ( F_138 ( args -> V_96 ) && ( V_13 -> V_16 & V_267 ) &&
( ! ( V_13 -> V_16 & V_349 ) || V_13 -> V_350 ) )
V_341 = 1 << 4 ;
if ( V_340 ) {
V_308 [ 0 ] = V_334 - V_308 - 1 ;
V_308 [ 2 ] |= V_341 ;
if ( V_338 ) {
V_308 [ 3 ] = sizeof( V_335 ) ;
memcpy ( V_308 + 4 , V_335 , sizeof( V_335 ) ) ;
}
} else {
unsigned int V_351 = V_334 - V_308 - 2 ;
V_308 [ 0 ] = V_351 >> 8 ;
V_308 [ 1 ] = V_351 ;
V_308 [ 3 ] |= V_341 ;
if ( V_338 ) {
V_308 [ 7 ] = sizeof( V_335 ) ;
memcpy ( V_308 + 8 , V_335 , sizeof( V_335 ) ) ;
}
}
return 0 ;
V_238:
F_22 ( args -> V_57 , V_82 , 0x24 , 0x0 ) ;
return 1 ;
V_343:
F_22 ( args -> V_57 , V_82 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_142 ( struct V_307 * args , T_3 * V_308 )
{
struct V_12 * V_13 = args -> V_13 ;
T_4 V_352 = V_13 -> V_88 - 1 ;
T_8 V_218 ;
T_3 V_353 ;
T_7 V_354 ;
V_218 = F_76 ( V_13 -> V_96 ) ;
V_353 = F_122 ( V_13 -> V_96 ) ;
V_354 = F_143 ( V_13 -> V_96 , V_353 ) ;
F_95 ( L_31 ) ;
if ( args -> V_57 -> V_236 [ 0 ] == V_355 ) {
if ( V_352 >= 0xffffffffULL )
V_352 = 0xffffffff ;
V_308 [ 0 ] = V_352 >> ( 8 * 3 ) ;
V_308 [ 1 ] = V_352 >> ( 8 * 2 ) ;
V_308 [ 2 ] = V_352 >> ( 8 * 1 ) ;
V_308 [ 3 ] = V_352 ;
V_308 [ 4 ] = V_218 >> ( 8 * 3 ) ;
V_308 [ 5 ] = V_218 >> ( 8 * 2 ) ;
V_308 [ 6 ] = V_218 >> ( 8 * 1 ) ;
V_308 [ 7 ] = V_218 ;
} else {
V_308 [ 0 ] = V_352 >> ( 8 * 7 ) ;
V_308 [ 1 ] = V_352 >> ( 8 * 6 ) ;
V_308 [ 2 ] = V_352 >> ( 8 * 5 ) ;
V_308 [ 3 ] = V_352 >> ( 8 * 4 ) ;
V_308 [ 4 ] = V_352 >> ( 8 * 3 ) ;
V_308 [ 5 ] = V_352 >> ( 8 * 2 ) ;
V_308 [ 6 ] = V_352 >> ( 8 * 1 ) ;
V_308 [ 7 ] = V_352 ;
V_308 [ 8 ] = V_218 >> ( 8 * 3 ) ;
V_308 [ 9 ] = V_218 >> ( 8 * 2 ) ;
V_308 [ 10 ] = V_218 >> ( 8 * 1 ) ;
V_308 [ 11 ] = V_218 ;
V_308 [ 12 ] = 0 ;
V_308 [ 13 ] = V_353 ;
V_308 [ 14 ] = ( V_354 >> 8 ) & 0x3f ;
V_308 [ 15 ] = V_354 ;
if ( F_124 ( args -> V_96 ) ) {
V_308 [ 14 ] |= 0x80 ;
if ( F_144 ( args -> V_96 ) &&
V_13 -> V_22 & V_356 ) {
F_145 ( V_13 , L_44 ) ;
V_308 [ 14 ] |= 0x40 ;
}
}
}
return 0 ;
}
static unsigned int F_146 ( struct V_307 * args , T_3 * V_308 )
{
F_95 ( L_31 ) ;
V_308 [ 3 ] = 8 ;
return 0 ;
}
static void F_147 ( struct V_142 * V_143 )
{
if ( V_143 -> V_191 && ( ( V_143 -> V_191 & V_357 ) == 0 ) ) {
F_63 ( V_143 ) ;
}
V_143 -> V_147 ( V_143 -> V_146 ) ;
F_105 ( V_143 ) ;
}
static inline int F_148 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_130 ) ;
}
static void F_149 ( struct V_142 * V_143 )
{
struct V_8 * V_9 = V_143 -> V_9 ;
struct V_56 * V_57 = V_143 -> V_146 ;
F_101 ( L_45 ) ;
memset ( V_57 -> V_64 , 0 , V_114 ) ;
#ifdef F_150
if ( V_9 -> V_68 -> V_358 )
V_9 -> V_68 -> V_358 ( V_9 , & V_143 -> V_66 ) ;
#endif
V_57 -> V_64 [ 0 ] = 0x70 ;
V_57 -> V_64 [ 2 ] = V_143 -> V_66 . V_159 >> 4 ;
F_151 ( V_143 ) ;
F_152 ( & V_143 -> V_359 , V_57 -> V_64 , V_114 ) ;
F_107 ( V_143 , & V_143 -> V_359 , 1 ) ;
V_143 -> V_293 = V_119 ;
memset ( & V_143 -> V_235 , 0 , V_143 -> V_13 -> V_360 ) ;
V_143 -> V_235 [ 0 ] = V_361 ;
V_143 -> V_235 [ 4 ] = V_114 ;
V_143 -> V_66 . V_16 |= V_240 | V_239 ;
V_143 -> V_66 . V_157 = V_362 ;
if ( F_148 ( V_9 ) ) {
V_143 -> V_66 . V_241 = V_363 ;
V_143 -> V_66 . V_159 |= V_364 ;
} else {
V_143 -> V_66 . V_241 = V_365 ;
V_143 -> V_66 . V_195 = V_114 ;
V_143 -> V_66 . V_196 = 0 ;
}
V_143 -> V_155 = V_114 ;
V_143 -> V_294 = F_147 ;
F_108 ( V_143 ) ;
F_101 ( L_33 ) ;
}
static void F_153 ( struct V_142 * V_143 )
{
struct V_56 * V_57 = V_143 -> V_146 ;
unsigned int V_191 = V_143 -> V_191 ;
F_95 ( L_46 , V_191 ) ;
if ( F_19 ( V_143 -> V_9 -> V_68 -> V_190 &&
( V_191 || V_143 -> V_16 & V_287 ) ) ) {
if ( ! ( V_143 -> V_16 & V_287 ) ) {
F_63 ( V_143 ) ;
}
if ( V_143 -> V_235 [ 0 ] == V_366 && V_143 -> V_13 -> V_29 )
V_143 -> V_13 -> V_29 -> V_367 = 0 ;
V_143 -> V_146 -> V_61 = V_63 ;
V_143 -> V_147 ( V_57 ) ;
F_105 ( V_143 ) ;
return;
}
if ( F_19 ( V_191 & V_357 ) ) {
V_57 -> V_61 = V_63 ;
F_149 ( V_143 ) ;
return;
} else if ( F_19 ( V_191 ) ) {
F_63 ( V_143 ) ;
} else {
T_3 * V_146 = V_57 -> V_236 ;
if ( ( V_146 [ 0 ] == V_368 ) && ( ( V_146 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_16 ;
T_3 * V_4 ;
V_4 = F_109 ( V_57 , true , & V_16 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_111 ( V_57 , true , & V_16 ) ;
}
V_57 -> V_61 = V_253 ;
}
V_143 -> V_147 ( V_57 ) ;
F_105 ( V_143 ) ;
}
static unsigned int F_154 ( struct V_142 * V_143 )
{
struct V_56 * V_152 = V_143 -> V_146 ;
struct V_12 * V_13 = V_143 -> V_13 ;
int V_369 = ( V_152 -> V_290 == V_120 ) ;
int V_370 = ! V_369 && ( V_13 -> V_16 & V_349 ) ;
unsigned int V_155 ;
memset ( V_143 -> V_235 , 0 , V_13 -> V_360 ) ;
memcpy ( V_143 -> V_235 , V_152 -> V_236 , V_152 -> V_237 ) ;
V_143 -> V_294 = F_153 ;
V_143 -> V_66 . V_16 |= V_240 | V_239 ;
if ( V_152 -> V_290 == V_291 ) {
V_143 -> V_66 . V_16 |= V_279 ;
F_101 ( L_47 ) ;
}
V_143 -> V_66 . V_157 = V_362 ;
F_58 ( V_143 ) ;
if ( ! V_369 && ! V_370 && F_155 ( V_143 ) )
V_370 = 1 ;
V_155 = F_80 ( F_156 ( V_143 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_155 & 0x1 )
V_155 ++ ;
V_143 -> V_66 . V_195 = ( V_155 & 0xFF ) ;
V_143 -> V_66 . V_196 = ( V_155 >> 8 ) ;
if ( V_369 )
V_143 -> V_66 . V_241 = V_371 ;
else if ( V_370 )
V_143 -> V_66 . V_241 = V_365 ;
else {
V_143 -> V_66 . V_241 = V_363 ;
V_143 -> V_66 . V_159 |= V_364 ;
if ( ( V_13 -> V_16 & V_372 ) &&
( V_152 -> V_290 != V_291 ) )
V_143 -> V_66 . V_159 |= V_373 ;
}
return 0 ;
}
static struct V_12 * F_157 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_158 ( V_9 ) ) {
if ( F_67 ( V_43 < F_159 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_67 ( V_43 < V_9 -> V_374 ) )
return & V_9 -> V_375 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_85 ( struct V_8 * V_9 ,
const struct V_28 * V_105 )
{
int V_43 ;
if ( ! F_158 ( V_9 ) ) {
if ( F_19 ( V_105 -> V_376 || V_105 -> V_377 ) )
return NULL ;
V_43 = V_105 -> V_96 ;
} else {
if ( F_19 ( V_105 -> V_96 || V_105 -> V_377 ) )
return NULL ;
V_43 = V_105 -> V_376 ;
}
return F_157 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_13 ( struct V_8 * V_9 , const struct V_28 * V_105 )
{
struct V_12 * V_13 = F_85 ( V_9 , V_105 ) ;
if ( F_19 ( ! V_13 || ! F_88 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_160 ( T_3 V_378 )
{
switch( ( V_378 & 0x1e ) >> 1 ) {
case 3 :
return V_242 ;
case 6 :
case 10 :
case 11 :
return V_379 ;
case 4 :
case 5 :
return V_380 ;
case 0 :
case 1 :
case 8 :
case 9 :
case 7 :
case 12 :
case 15 :
default:
break;
}
return V_381 ;
}
static unsigned int F_161 ( struct V_142 * V_143 )
{
struct V_65 * V_66 = & ( V_143 -> V_66 ) ;
struct V_56 * V_152 = V_143 -> V_146 ;
struct V_12 * V_13 = V_143 -> V_13 ;
const T_3 * V_235 = V_152 -> V_236 ;
if ( ( V_66 -> V_241 = F_160 ( V_235 [ 1 ] ) ) == V_381 )
goto V_238;
if ( V_235 [ 0 ] == V_121 ) {
if ( V_235 [ 1 ] & 0x01 ) {
V_66 -> V_382 = V_235 [ 3 ] ;
V_66 -> V_198 = V_235 [ 5 ] ;
V_66 -> V_199 = V_235 [ 7 ] ;
V_66 -> V_200 = V_235 [ 9 ] ;
V_66 -> V_201 = V_235 [ 11 ] ;
V_66 -> V_16 |= V_197 ;
} else
V_66 -> V_16 &= ~ V_197 ;
V_66 -> V_159 = V_235 [ 4 ] ;
V_66 -> V_193 = V_235 [ 6 ] ;
V_66 -> V_194 = V_235 [ 8 ] ;
V_66 -> V_195 = V_235 [ 10 ] ;
V_66 -> V_196 = V_235 [ 12 ] ;
V_66 -> V_1 = V_235 [ 13 ] ;
V_66 -> V_157 = V_235 [ 14 ] ;
} else {
V_66 -> V_16 &= ~ V_197 ;
V_66 -> V_159 = V_235 [ 3 ] ;
V_66 -> V_193 = V_235 [ 4 ] ;
V_66 -> V_194 = V_235 [ 5 ] ;
V_66 -> V_195 = V_235 [ 6 ] ;
V_66 -> V_196 = V_235 [ 7 ] ;
V_66 -> V_1 = V_235 [ 8 ] ;
V_66 -> V_157 = V_235 [ 9 ] ;
}
V_66 -> V_1 = V_13 -> V_43 ?
V_66 -> V_1 | V_383 : V_66 -> V_1 & ~ V_383 ;
switch ( V_66 -> V_157 ) {
case V_384 :
case V_385 :
case V_386 :
case V_387 :
if ( V_66 -> V_241 != V_380 || V_66 -> V_193 != 1 )
goto V_238;
V_143 -> V_388 = F_59 ( V_152 ) ;
break;
case V_389 :
case V_390 :
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
case V_246 :
case V_268 :
case V_402 :
case V_403 :
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
V_143 -> V_388 = V_152 -> V_1 -> V_218 ;
break;
default:
V_143 -> V_388 = V_117 ;
}
V_66 -> V_16 |= V_240 | V_239 ;
if ( V_152 -> V_290 == V_291 )
V_66 -> V_16 |= V_279 ;
V_143 -> V_16 |= V_415 | V_416 ;
F_58 ( V_143 ) ;
if ( V_66 -> V_241 == V_379 && V_13 -> V_417 == 0 )
goto V_238;
if ( ( V_235 [ 1 ] & 0xe0 ) && ! F_162 ( V_66 ) )
goto V_238;
if ( F_162 ( V_66 ) ) {
unsigned int V_350 = 1 << ( V_235 [ 1 ] >> 5 ) ;
if ( V_350 != V_13 -> V_350 )
F_77 ( V_13 , L_48 ,
V_350 ) ;
}
if ( V_66 -> V_157 == V_418 &&
V_66 -> V_159 == V_419 )
goto V_238;
if ( V_66 -> V_157 >= 0x5C && V_66 -> V_157 <= 0x5F && ! V_420 )
goto V_238;
return 0 ;
V_238:
F_22 ( V_152 , V_82 , 0x24 , 0x00 ) ;
return 1 ;
}
static unsigned int F_163 ( struct V_142 * V_143 )
{
struct V_65 * V_66 = & V_143 -> V_66 ;
struct V_56 * V_152 = V_143 -> V_146 ;
struct V_12 * V_13 = V_143 -> V_13 ;
const T_3 * V_235 = V_152 -> V_236 ;
T_4 V_202 ;
T_8 V_262 ;
T_8 V_421 ;
void * V_4 ;
if ( F_19 ( ! V_13 -> V_417 ) )
goto V_238;
if ( F_19 ( V_152 -> V_237 < 16 ) )
goto V_238;
F_97 ( V_235 , & V_202 , & V_262 ) ;
if ( F_19 ( ! ( V_235 [ 1 ] & 0x8 ) ) )
goto V_238;
if ( ! F_57 ( V_152 ) )
goto V_238;
V_4 = F_164 ( F_165 ( F_56 ( V_152 ) ) ) ;
V_421 = F_166 ( V_4 , 512 , V_202 , V_262 ) ;
if ( F_89 ( V_13 ) && F_167 ( V_13 ) ) {
V_66 -> V_241 = V_422 ;
V_66 -> V_157 = V_423 ;
V_66 -> V_198 = V_424 & 0x1f ;
V_66 -> V_193 = V_143 -> V_145 << 3 ;
V_66 -> V_382 = ( V_421 / 512 ) >> 8 ;
V_66 -> V_159 = V_421 / 512 ;
V_66 -> V_425 = 1 ;
} else {
V_66 -> V_241 = V_379 ;
V_66 -> V_382 = 0 ;
V_66 -> V_159 = V_426 ;
V_66 -> V_198 = ( V_421 / 512 ) >> 8 ;
V_66 -> V_193 = V_421 / 512 ;
V_66 -> V_157 = V_427 ;
}
V_66 -> V_16 |= V_240 | V_239 | V_197 |
V_279 ;
F_58 ( V_143 ) ;
return 0 ;
V_238:
F_22 ( V_152 , V_82 , 0x24 , 0x00 ) ;
return 1 ;
}
static int F_168 ( struct V_142 * V_143 ,
const T_3 * V_4 , int V_45 )
{
struct V_65 * V_66 = & V_143 -> V_66 ;
struct V_12 * V_13 = V_143 -> V_13 ;
char V_428 [ V_429 ] ;
T_3 V_430 ;
if ( V_45 != V_429 - 2 )
return - V_20 ;
V_430 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_133 ( V_13 -> V_96 , V_428 , false ) ;
V_428 [ 2 ] &= ~ ( 1 << 2 ) ;
V_428 [ 2 ] |= V_430 ;
if ( memcmp ( V_428 + 2 , V_4 , V_429 - 2 ) != 0 )
return - V_20 ;
V_66 -> V_16 |= V_239 | V_240 ;
V_66 -> V_241 = V_242 ;
V_66 -> V_193 = 0 ;
V_66 -> V_157 = V_418 ;
V_66 -> V_159 = V_430 ? V_431 : V_432 ;
return 0 ;
}
static unsigned int F_169 ( struct V_142 * V_143 )
{
struct V_56 * V_152 = V_143 -> V_146 ;
const T_3 * V_235 = V_152 -> V_236 ;
const T_3 * V_334 ;
T_3 V_336 , V_337 ;
unsigned V_340 , V_433 , V_434 , V_435 ;
int V_45 ;
F_95 ( L_31 ) ;
V_340 = ( V_235 [ 0 ] == V_436 ) ;
if ( V_340 ) {
if ( V_152 -> V_237 < 5 )
goto V_238;
V_45 = V_235 [ 4 ] ;
V_434 = 4 ;
} else {
if ( V_152 -> V_237 < 9 )
goto V_238;
V_45 = ( V_235 [ 7 ] << 8 ) + V_235 [ 8 ] ;
V_434 = 8 ;
}
if ( ( V_235 [ 1 ] & 0x11 ) != 0x10 )
goto V_238;
if ( ! F_57 ( V_152 ) || F_56 ( V_152 ) -> V_437 < V_45 )
goto V_438;
V_334 = F_164 ( F_165 ( F_56 ( V_152 ) ) ) ;
if ( V_45 < V_434 )
goto V_438;
if ( V_340 )
V_435 = V_334 [ 3 ] ;
else
V_435 = ( V_334 [ 6 ] << 8 ) + V_334 [ 7 ] ;
V_45 -= V_434 ;
V_334 += V_434 ;
if ( V_45 < V_435 )
goto V_438;
if ( V_435 != 0 && V_435 != 8 )
goto V_439;
V_45 -= V_435 ;
V_334 += V_435 ;
if ( V_45 == 0 )
goto V_250;
V_336 = V_334 [ 0 ] & 0x3f ;
if ( V_334 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_438;
V_337 = V_334 [ 1 ] ;
V_433 = ( V_334 [ 2 ] << 8 ) | V_334 [ 3 ] ;
V_334 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_438;
V_337 = 0 ;
V_433 = V_334 [ 1 ] ;
V_334 += 2 ;
V_45 -= 2 ;
}
if ( V_337 && ( V_337 != V_344 ) )
goto V_439;
if ( V_433 > V_45 )
goto V_438;
switch ( V_336 ) {
case V_346 :
if ( F_168 ( V_143 , V_334 , V_433 ) < 0 )
goto V_439;
break;
default:
goto V_439;
}
if ( V_45 > V_433 )
goto V_439;
return 0 ;
V_238:
F_22 ( V_152 , V_82 , 0x24 , 0x0 ) ;
return 1 ;
V_439:
F_22 ( V_152 , V_82 , 0x26 , 0x0 ) ;
return 1 ;
V_438:
F_22 ( V_152 , V_82 , 0x1a , 0x0 ) ;
return 1 ;
V_250:
V_152 -> V_61 = V_253 ;
return 1 ;
}
static inline T_9 F_170 ( struct V_12 * V_13 , T_3 V_57 )
{
switch ( V_57 ) {
case V_282 :
case V_280 :
case V_283 :
case V_277 :
case V_276 :
case V_278 :
return F_102 ;
case V_440 :
return F_163 ;
case V_441 :
if ( F_171 ( V_13 ) )
return F_93 ;
break;
case V_263 :
case V_264 :
return F_98 ;
case V_286 :
case V_121 :
return F_161 ;
case V_436 :
case V_442 :
return F_169 ;
break;
case V_443 :
return F_91 ;
}
return NULL ;
}
static inline void F_172 ( struct V_8 * V_9 ,
struct V_56 * V_57 )
{
#ifdef F_173
struct V_28 * V_105 = V_57 -> V_1 ;
T_3 * V_146 = V_57 -> V_236 ;
F_101 ( L_49 ,
V_9 -> V_192 ,
V_105 -> V_376 , V_105 -> V_96 , V_105 -> V_377 ,
V_146 [ 0 ] , V_146 [ 1 ] , V_146 [ 2 ] , V_146 [ 3 ] ,
V_146 [ 4 ] , V_146 [ 5 ] , V_146 [ 6 ] , V_146 [ 7 ] ,
V_146 [ 8 ] ) ;
#endif
}
static inline int F_174 ( struct V_56 * V_152 ,
struct V_12 * V_13 )
{
T_3 V_444 = V_152 -> V_236 [ 0 ] ;
T_9 V_288 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 || V_13 -> V_49 == V_51 ) {
if ( F_19 ( ! V_152 -> V_237 || V_152 -> V_237 > V_13 -> V_360 ) )
goto V_445;
V_288 = F_170 ( V_13 , V_444 ) ;
} else {
if ( F_19 ( ! V_152 -> V_237 ) )
goto V_445;
V_288 = NULL ;
if ( F_67 ( ( V_444 != V_121 ) || ! V_446 ) ) {
int V_45 = F_175 ( V_444 ) ;
if ( F_19 ( V_45 > V_152 -> V_237 || V_45 > V_13 -> V_360 ) )
goto V_445;
V_288 = F_154 ;
} else {
if ( F_19 ( V_152 -> V_237 > 16 ) )
goto V_445;
V_288 = F_170 ( V_13 , V_444 ) ;
}
}
if ( V_288 )
V_33 = F_106 ( V_13 , V_152 , V_288 ) ;
else
F_176 ( V_13 , V_152 ) ;
return V_33 ;
V_445:
F_101 ( L_50 ,
V_152 -> V_237 , V_444 , V_13 -> V_360 ) ;
V_152 -> V_61 = V_298 << 16 ;
V_152 -> V_83 ( V_152 ) ;
return 0 ;
}
int F_177 ( struct V_6 * V_7 , struct V_56 * V_57 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_105 = V_57 -> V_1 ;
int V_33 = 0 ;
unsigned long V_447 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_447 ) ;
F_172 ( V_9 , V_57 ) ;
V_13 = F_13 ( V_9 , V_105 ) ;
if ( F_67 ( V_13 ) )
V_33 = F_174 ( V_57 , V_13 ) ;
else {
V_57 -> V_61 = ( V_448 << 16 ) ;
V_57 -> V_83 ( V_57 ) ;
}
F_9 ( V_9 -> V_21 , V_447 ) ;
return V_33 ;
}
void F_176 ( struct V_12 * V_13 , struct V_56 * V_57 )
{
struct V_307 args ;
const T_3 * V_146 = V_57 -> V_236 ;
T_3 V_449 ;
args . V_13 = V_13 ;
args . V_96 = V_13 -> V_96 ;
args . V_57 = V_57 ;
args . V_450 = V_57 -> V_83 ;
switch( V_146 [ 0 ] ) {
case V_451 :
F_33 ( V_57 ) ;
break;
case V_368 :
if ( V_146 [ 1 ] & 2 )
F_33 ( V_57 ) ;
else if ( ( V_146 [ 1 ] & 1 ) == 0 )
F_178 ( & args , F_113 ) ;
else switch ( V_146 [ 2 ] ) {
case 0x00 :
F_178 ( & args , F_115 ) ;
break;
case 0x80 :
F_178 ( & args , F_116 ) ;
break;
case 0x83 :
F_178 ( & args , F_117 ) ;
break;
case 0x89 :
F_178 ( & args , F_119 ) ;
break;
case 0xb0 :
F_178 ( & args , F_121 ) ;
break;
case 0xb1 :
F_178 ( & args , F_127 ) ;
break;
case 0xb2 :
F_178 ( & args , F_130 ) ;
break;
default:
F_33 ( V_57 ) ;
break;
}
break;
case V_342 :
case V_452 :
F_178 ( & args , F_141 ) ;
break;
case V_355 :
F_178 ( & args , F_142 ) ;
break;
case V_453 :
if ( ( V_146 [ 1 ] & 0x1f ) == V_454 )
F_178 ( & args , F_142 ) ;
else
F_33 ( V_57 ) ;
break;
case V_455 :
F_178 ( & args , F_146 ) ;
break;
case V_361 :
F_22 ( V_57 , 0 , 0 , 0 ) ;
V_57 -> V_61 = ( V_62 << 24 ) ;
V_57 -> V_83 ( V_57 ) ;
break;
case V_441 :
case V_456 :
case V_457 :
case V_458 :
case V_459 :
F_178 ( & args , F_131 ) ;
break;
case V_460 :
V_449 = V_146 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_449 == 0x4 ) && ( ! V_146 [ 3 ] ) && ( ! V_146 [ 4 ] ) )
F_178 ( & args , F_131 ) ;
else
F_33 ( V_57 ) ;
break;
default:
F_22 ( V_57 , V_82 , 0x20 , 0x0 ) ;
V_57 -> V_83 ( V_57 ) ;
break;
}
}
int F_179 ( struct V_461 * V_34 , struct V_462 * V_463 )
{
int V_178 , V_33 ;
for ( V_178 = 0 ; V_178 < V_34 -> V_464 ; V_178 ++ ) {
struct V_8 * V_9 = V_34 -> V_465 [ V_178 ] ;
struct V_6 * V_7 ;
V_33 = - V_116 ;
V_7 = F_180 ( V_463 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_466;
V_7 -> V_467 = 1 ;
* (struct V_8 * * ) & V_7 -> V_468 [ 0 ] = V_9 ;
V_9 -> V_469 = V_7 ;
V_7 -> V_470 = V_471 ;
V_7 -> V_472 = V_9 -> V_192 ;
V_7 -> V_473 = 16 ;
V_7 -> V_474 = 1 ;
V_7 -> V_475 = 1 ;
V_7 -> V_476 = 16 ;
V_7 -> V_206 = 1 ;
V_7 -> V_477 = 1 ;
if ( F_181 ( V_7 , V_34 -> V_478 ) )
goto V_479;
V_33 = F_182 ( V_9 -> V_469 ,
& V_9 -> V_480 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_479;
}
return 0 ;
V_479:
F_183 ( V_34 -> V_465 [ V_178 ] -> V_469 ) ;
V_466:
while ( -- V_178 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_465 [ V_178 ] -> V_469 ;
F_184 ( V_7 ) ;
F_183 ( V_7 ) ;
}
return V_33 ;
}
void F_185 ( struct V_8 * V_9 , int V_481 )
{
int V_482 = 5 ;
struct V_12 * V_483 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_484:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_376 = 0 , V_96 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_186 ( V_11 ) )
V_96 = V_13 -> V_43 ;
else
V_376 = V_11 -> V_485 ;
V_29 = F_187 ( V_9 -> V_469 , V_376 , V_96 , 0 ,
NULL ) ;
if ( ! F_188 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_189 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_486;
}
}
V_486:
if ( ! V_11 )
return;
if ( V_481 ) {
if ( V_13 != V_483 ) {
F_190 ( 100 ) ;
V_483 = V_13 ;
goto V_484;
}
if ( -- V_482 ) {
F_190 ( 100 ) ;
goto V_484;
}
F_191 ( V_9 ,
L_51 ) ;
}
F_192 ( V_487 , & V_9 -> V_488 ,
F_193 ( V_123 ) ) ;
}
int F_194 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_195 ( V_13 -> V_29 , V_489 ) ;
return 1 ;
}
return 0 ;
}
static void F_196 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_197 ( & V_9 -> V_469 -> V_490 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_198 ( V_29 ) == 0 ) {
F_195 ( V_29 , V_489 ) ;
} else {
F_199 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_200 ( & V_9 -> V_469 -> V_490 ) ;
if ( V_29 ) {
F_145 ( V_13 , L_52 ,
F_201 ( & V_29 -> V_491 ) ) ;
F_202 ( V_29 ) ;
F_189 ( V_29 ) ;
}
}
static void F_203 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_492 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_492 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_204 ( V_13 ) )
F_205 ( V_13 ) ;
F_196 ( V_13 ) ;
}
}
void F_206 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_207 ( V_13 -> V_29 , V_224 ,
V_493 ) ;
}
void F_208 ( struct V_494 * V_495 )
{
struct V_8 * V_9 =
F_209 ( V_495 , struct V_8 , V_488 . V_495 ) ;
int V_178 ;
if ( V_9 -> V_39 & V_496 ) {
F_101 ( L_53 ) ;
return;
}
#ifdef F_210
while ( V_497 )
F_190 ( 10 ) ;
#endif
F_101 ( L_31 ) ;
F_197 ( & V_9 -> V_498 ) ;
F_203 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_375 )
for ( V_178 = 0 ; V_178 < V_499 ; V_178 ++ )
F_203 ( & V_9 -> V_375 [ V_178 ] ) ;
F_185 ( V_9 , 0 ) ;
F_200 ( & V_9 -> V_498 ) ;
F_101 ( L_33 ) ;
}
int F_211 ( struct V_6 * V_7 , unsigned int V_376 ,
unsigned int V_96 , T_4 V_377 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_68 -> V_190 )
return - V_24 ;
if ( V_377 != V_500 && V_377 )
return - V_20 ;
if ( ! F_158 ( V_9 ) ) {
if ( V_376 != V_500 && V_376 )
return - V_20 ;
V_43 = V_96 ;
} else {
if ( V_96 != V_500 && V_96 )
return - V_20 ;
V_43 = V_376 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_500 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_501 * V_502 = & V_11 -> V_52 ;
V_502 -> V_503 |= V_504 ;
V_502 -> V_91 |= V_92 ;
}
} else {
struct V_12 * V_13 = F_157 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_501 * V_502 = & V_13 -> V_11 -> V_52 ;
V_502 -> V_503 |= 1 << V_13 -> V_43 ;
V_502 -> V_91 |= V_92 ;
} else
V_33 = - V_20 ;
}
if ( V_33 == 0 ) {
F_8 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_37 ( V_9 ) ;
} else
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
}
void F_212 ( struct V_494 * V_495 )
{
struct V_8 * V_9 =
F_209 ( V_495 , struct V_8 , V_505 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_197 ( & V_9 -> V_498 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_198 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_213 ( & ( V_29 -> V_491 ) ) ;
F_189 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_200 ( & V_9 -> V_498 ) ;
}
struct V_8 * F_214 ( struct V_461 * V_34 ,
struct V_506 * V_507 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_215 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_508 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_509 = V_507 -> V_509 ;
V_9 -> V_510 = V_507 -> V_510 ;
V_9 -> V_511 = V_507 -> V_511 ;
V_9 -> V_16 |= V_507 -> V_16 ;
V_9 -> V_68 = V_507 -> V_512 ;
V_9 -> V_513 = V_514 ;
return V_9 ;
}
int F_216 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_68 -> V_190 )
V_9 -> V_39 &= ~ V_515 ;
return 0 ;
}
void F_217 ( struct V_8 * V_9 )
{
}
void F_218 ( struct V_8 * V_9 )
{
F_219 ( V_9 ) ;
}
int F_220 ( struct V_8 * V_9 )
{
return F_221 ( V_9 ) ;
}
int F_222 ( struct V_8 * V_9 )
{
int V_33 = V_9 -> V_68 -> V_516 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_192 = F_223 ( & V_517 ) ;
return 0 ;
}
void F_224 ( struct V_8 * V_9 )
{
if ( V_9 -> V_68 -> V_518 )
V_9 -> V_68 -> V_518 ( V_9 ) ;
F_48 ( V_9 ) ;
}
int F_225 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_65 ( V_29 ) ;
F_70 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_226 ( struct V_56 * V_57 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_172 ( V_9 , V_57 ) ;
if ( F_67 ( F_88 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_174 ( V_57 , V_9 -> V_11 . V_1 ) ;
else {
V_57 -> V_61 = ( V_448 << 16 ) ;
V_57 -> V_83 ( V_57 ) ;
}
return V_33 ;
}
int F_227 ( struct V_8 * V_9 )
{
unsigned int V_519 = V_9 -> V_34 -> V_478 ;
unsigned int V_178 , V_145 ;
for ( V_178 = 0 , V_145 = V_9 -> V_520 + 1 ; V_178 < V_519 ; V_178 ++ , V_145 ++ ) {
V_145 = V_145 < V_519 ? V_145 : 0 ;
if ( V_145 == V_521 )
continue;
if ( ! F_228 ( V_145 , & V_9 -> V_522 ) ) {
V_9 -> V_520 = V_145 ;
return V_145 ;
}
}
return - 1 ;
}
void F_229 ( unsigned int V_145 , struct V_8 * V_9 )
{
F_230 ( V_145 , & V_9 -> V_522 ) ;
}
