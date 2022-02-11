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
if ( V_13 -> V_49 != V_50 ) {
V_33 = - V_24 ;
goto V_36;
}
if ( V_46 >= 0 ) {
if ( V_13 -> V_16 & V_37 ) {
V_33 = - V_24 ;
goto V_36;
}
V_13 -> V_44 = F_20 ( V_38 , V_46 ) ;
V_13 -> V_11 -> V_51 . V_52 [ V_13 -> V_43 ] |= V_53 ;
F_8 ( V_9 ) ;
F_21 ( & V_9 -> V_54 ) ;
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
static void F_22 ( struct V_55 * V_56 , T_3 V_57 , T_3 V_58 , T_3 V_59 )
{
V_56 -> V_60 = ( V_61 << 24 ) | V_62 ;
F_23 ( 0 , V_56 -> V_63 , V_57 , V_58 , V_59 ) ;
}
static T_1
F_24 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_64 -> V_65 && ( V_9 -> V_16 & V_66 ) )
return V_9 -> V_64 -> V_65 ( V_9 , V_4 , V_5 ) ;
return - V_20 ;
}
static T_1
F_25 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_64 -> V_67 && ( V_9 -> V_16 & V_66 ) )
return V_9 -> V_64 -> V_67 ( V_9 , V_4 ) ;
return - V_20 ;
}
static T_1
F_26 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_4 , 23 , L_3 , V_9 -> V_68 ) ;
}
static T_1
F_27 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_69 = F_13 ( V_9 , V_29 ) ;
if ( V_69 && V_9 -> V_64 -> V_70 &&
( V_9 -> V_16 & V_71 ) )
return V_9 -> V_64 -> V_70 ( V_69 , V_4 ) ;
return - V_20 ;
}
static T_1
F_28 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_69 = F_13 ( V_9 , V_29 ) ;
enum V_72 V_73 ;
int V_33 ;
if ( V_69 && V_9 -> V_64 -> V_74 &&
( V_9 -> V_16 & V_71 ) ) {
V_73 = F_29 ( V_4 , NULL , 0 ) ;
switch ( V_73 ) {
case V_75 : case V_76 : case V_77 :
V_33 = V_9 -> V_64 -> V_74 ( V_69 , V_73 ) ;
if ( ! V_33 )
return V_5 ;
else
return V_33 ;
}
}
return - V_20 ;
}
static void F_30 ( struct V_55 * V_56 )
{
F_22 ( V_56 , V_78 , 0x24 , 0x0 ) ;
V_56 -> V_79 ( V_56 ) ;
}
int F_31 ( struct V_28 * V_29 , struct V_80 * V_81 ,
T_4 V_82 , int V_83 [] )
{
V_83 [ 0 ] = 255 ;
V_83 [ 1 ] = 63 ;
F_32 ( V_82 , 255 * 63 ) ;
V_83 [ 2 ] = V_82 ;
return 0 ;
}
void F_33 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_13 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_84 < V_13 -> V_85 ) {
V_13 -> V_16 |= V_86 ;
V_13 -> V_11 -> V_51 . V_87 |= V_88 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_34 ( V_9 ) ;
}
static int F_35 ( struct V_8 * V_9 , struct V_28 * V_29 ,
void T_5 * V_89 )
{
struct V_12 * V_13 = F_13 ( V_9 , V_29 ) ;
T_6 T_5 * V_90 = V_89 ;
char V_4 [ 40 ] ;
if ( ! V_13 )
return - V_91 ;
if ( F_36 ( V_90 , V_13 -> V_92 , V_93 * sizeof( T_6 ) ) )
return - V_94 ;
F_37 ( V_13 -> V_92 , V_4 , V_95 , V_96 ) ;
if ( F_36 ( V_90 + V_95 , V_4 , V_96 ) )
return - V_94 ;
F_37 ( V_13 -> V_92 , V_4 , V_97 , V_98 ) ;
if ( F_36 ( V_90 + V_97 , V_4 , V_98 ) )
return - V_94 ;
F_37 ( V_13 -> V_92 , V_4 , V_99 , V_100 ) ;
if ( F_36 ( V_90 + V_99 , V_4 , V_100 ) )
return - V_94 ;
return 0 ;
}
int F_38 ( struct V_28 * V_101 , void T_5 * V_89 )
{
int V_33 = 0 ;
T_3 V_102 [ V_103 ] ;
T_3 args [ 4 ] , * V_104 = NULL , * V_105 = NULL ;
int V_106 = 0 ;
enum V_107 V_108 ;
int V_109 ;
if ( V_89 == NULL )
return - V_20 ;
if ( F_39 ( args , V_89 , sizeof( args ) ) )
return - V_94 ;
V_105 = F_40 ( V_110 , V_111 ) ;
if ( ! V_105 )
return - V_112 ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
if ( args [ 3 ] ) {
V_106 = V_113 * args [ 3 ] ;
V_104 = F_41 ( V_106 , V_114 ) ;
if ( V_104 == NULL ) {
V_33 = - V_112 ;
goto error;
}
V_102 [ 1 ] = ( 4 << 1 ) ;
V_102 [ 2 ] = 0x0e ;
V_108 = V_115 ;
} else {
V_102 [ 1 ] = ( 3 << 1 ) ;
V_102 [ 2 ] = 0x20 ;
V_108 = V_116 ;
}
V_102 [ 0 ] = V_117 ;
V_102 [ 4 ] = args [ 2 ] ;
if ( args [ 0 ] == V_118 ) {
V_102 [ 6 ] = args [ 3 ] ;
V_102 [ 8 ] = args [ 1 ] ;
V_102 [ 10 ] = 0x4f ;
V_102 [ 12 ] = 0xc2 ;
} else {
V_102 [ 6 ] = args [ 1 ] ;
}
V_102 [ 14 ] = args [ 0 ] ;
V_109 = F_42 ( V_101 , V_102 , V_108 , V_104 , V_106 ,
V_105 , ( 10 * V_119 ) , 5 , 0 , NULL ) ;
if ( F_43 ( V_109 ) == V_61 ) {
T_3 * V_120 = V_105 + 8 ;
V_109 &= ~ ( 0xFF << 24 ) ;
if ( V_109 & V_62 ) {
struct V_121 V_122 ;
F_44 ( V_105 , V_110 ,
& V_122 ) ;
if ( V_122 . V_123 == V_124 &&
V_122 . V_58 == 0 && V_122 . V_59 == 0x1d )
V_109 &= ~ V_62 ;
}
if ( V_105 [ 0 ] == 0x72 &&
V_120 [ 0 ] == 0x09 ) {
args [ 0 ] = V_120 [ 13 ] ;
args [ 1 ] = V_120 [ 3 ] ;
args [ 2 ] = V_120 [ 5 ] ;
if ( F_36 ( V_89 , args , sizeof( args ) ) )
V_33 = - V_94 ;
}
}
if ( V_109 ) {
V_33 = - V_125 ;
goto error;
}
if ( ( V_104 )
&& F_36 ( V_89 + sizeof( args ) , V_104 , V_106 ) )
V_33 = - V_94 ;
error:
F_45 ( V_105 ) ;
F_45 ( V_104 ) ;
return V_33 ;
}
int F_46 ( struct V_28 * V_101 , void T_5 * V_89 )
{
int V_33 = 0 ;
T_3 V_102 [ V_103 ] ;
T_3 args [ 7 ] , * V_105 = NULL ;
int V_109 ;
if ( V_89 == NULL )
return - V_20 ;
if ( F_39 ( args , V_89 , sizeof( args ) ) )
return - V_94 ;
V_105 = F_40 ( V_110 , V_111 ) ;
if ( ! V_105 )
return - V_112 ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
V_102 [ 0 ] = V_117 ;
V_102 [ 1 ] = ( 3 << 1 ) ;
V_102 [ 2 ] = 0x20 ;
V_102 [ 4 ] = args [ 1 ] ;
V_102 [ 6 ] = args [ 2 ] ;
V_102 [ 8 ] = args [ 3 ] ;
V_102 [ 10 ] = args [ 4 ] ;
V_102 [ 12 ] = args [ 5 ] ;
V_102 [ 13 ] = args [ 6 ] & 0x4f ;
V_102 [ 14 ] = args [ 0 ] ;
V_109 = F_42 ( V_101 , V_102 , V_116 , NULL , 0 ,
V_105 , ( 10 * V_119 ) , 5 , 0 , NULL ) ;
if ( F_43 ( V_109 ) == V_61 ) {
T_3 * V_120 = V_105 + 8 ;
V_109 &= ~ ( 0xFF << 24 ) ;
if ( V_109 & V_62 ) {
struct V_121 V_122 ;
F_44 ( V_105 , V_110 ,
& V_122 ) ;
if ( V_122 . V_123 == V_124 &&
V_122 . V_58 == 0 && V_122 . V_59 == 0x1d )
V_109 &= ~ V_62 ;
}
if ( V_105 [ 0 ] == 0x72 &&
V_120 [ 0 ] == 0x09 ) {
args [ 0 ] = V_120 [ 13 ] ;
args [ 1 ] = V_120 [ 3 ] ;
args [ 2 ] = V_120 [ 5 ] ;
args [ 3 ] = V_120 [ 7 ] ;
args [ 4 ] = V_120 [ 9 ] ;
args [ 5 ] = V_120 [ 11 ] ;
args [ 6 ] = V_120 [ 12 ] ;
if ( F_36 ( V_89 , args , sizeof( args ) ) )
V_33 = - V_94 ;
}
}
if ( V_109 ) {
V_33 = - V_125 ;
goto error;
}
error:
F_45 ( V_105 ) ;
return V_33 ;
}
static int F_47 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 & V_126 )
return 1 ;
if ( V_9 -> V_39 & V_127 )
return 1 ;
return 0 ;
}
int F_48 ( struct V_8 * V_9 , struct V_28 * V_101 ,
int V_56 , void T_5 * V_89 )
{
int V_73 = - V_20 , V_33 = - V_20 ;
unsigned long V_16 ;
switch ( V_56 ) {
case V_128 :
F_5 ( V_9 -> V_21 , V_16 ) ;
V_73 = F_47 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_36 ( V_89 , & V_73 , 1 ) )
return - V_94 ;
return 0 ;
case V_129 :
V_73 = ( unsigned long ) V_89 ;
V_33 = 0 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_9 -> V_39 & V_130 ) {
if ( V_73 )
V_9 -> V_39 |= V_127 ;
else
V_9 -> V_39 &= ~ V_127 ;
} else {
if ( V_73 != F_47 ( V_9 ) )
V_33 = - V_20 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
case V_131 :
return F_35 ( V_9 , V_101 , V_89 ) ;
case V_132 :
if ( ! F_49 ( V_133 ) || ! F_49 ( V_134 ) )
return - V_135 ;
return F_38 ( V_101 , V_89 ) ;
case V_136 :
if ( ! F_49 ( V_133 ) || ! F_49 ( V_134 ) )
return - V_135 ;
return F_46 ( V_101 , V_89 ) ;
default:
V_33 = - V_137 ;
break;
}
return V_33 ;
}
int F_50 ( struct V_28 * V_101 , int V_56 , void T_5 * V_89 )
{
return F_48 ( F_3 ( V_101 -> V_34 ) ,
V_101 , V_56 , V_89 ) ;
}
static struct V_138 * F_51 ( struct V_12 * V_13 ,
struct V_55 * V_56 )
{
struct V_138 * V_139 ;
V_139 = F_52 ( V_13 ) ;
if ( V_139 ) {
V_139 -> V_140 = V_56 ;
V_139 -> V_141 = V_56 -> V_79 ;
V_139 -> V_142 = F_53 ( V_56 ) ;
V_139 -> V_143 = F_54 ( V_56 ) ;
} else {
V_56 -> V_60 = ( V_144 << 16 ) | ( V_145 << 1 ) ;
V_56 -> V_79 ( V_56 ) ;
}
return V_139 ;
}
static void F_55 ( struct V_138 * V_139 )
{
struct V_55 * V_146 = V_139 -> V_140 ;
V_139 -> V_147 = V_146 -> V_148 -> V_149 ;
V_139 -> V_150 = F_56 ( V_146 ) + V_139 -> V_147 ;
}
static void F_57 ( unsigned V_92 , struct V_151 * V_152 )
{
T_3 V_153 = V_152 -> V_154 , V_155 = V_152 -> V_156 ;
F_58 ( V_157 L_4 , V_92 , V_153 ) ;
if ( V_153 & V_158 ) {
F_58 ( L_5 ) ;
} else {
if ( V_153 & 0x40 ) F_58 ( L_6 ) ;
if ( V_153 & 0x20 ) F_58 ( L_7 ) ;
if ( V_153 & 0x10 ) F_58 ( L_8 ) ;
if ( V_153 & 0x08 ) F_58 ( L_9 ) ;
if ( V_153 & 0x04 ) F_58 ( L_10 ) ;
if ( V_153 & 0x02 ) F_58 ( L_11 ) ;
if ( V_153 & 0x01 ) F_58 ( L_12 ) ;
F_58 ( L_13 ) ;
if ( V_155 ) {
F_58 ( V_157 L_14 , V_92 , V_155 ) ;
if ( V_155 & 0x04 ) F_58 ( L_15 ) ;
if ( V_155 & 0x80 ) {
if ( V_155 & 0x04 ) F_58 ( L_16 ) ;
else F_58 ( L_17 ) ;
}
if ( V_155 & 0x40 ) F_58 ( L_18 ) ;
if ( V_155 & 0x10 ) F_58 ( L_19 ) ;
if ( V_155 & 0x02 ) F_58 ( L_20 ) ;
if ( V_155 & 0x01 ) F_58 ( L_21 ) ;
F_58 ( L_13 ) ;
}
}
}
static void F_59 ( unsigned V_92 , T_3 V_159 , T_3 V_160 , T_3 * V_57 ,
T_3 * V_58 , T_3 * V_59 , int V_161 )
{
int V_162 ;
static const unsigned char V_163 [] [ 4 ] = {
{ 0xd1 , V_164 , 0x00 , 0x00 } ,
{ 0xd0 , V_164 , 0x00 , 0x00 } ,
{ 0x61 , V_165 , 0x00 , 0x00 } ,
{ 0x84 , V_164 , 0x47 , 0x00 } ,
{ 0x37 , V_166 , 0x04 , 0x00 } ,
{ 0x09 , V_166 , 0x04 , 0x00 } ,
{ 0x01 , V_167 , 0x13 , 0x00 } ,
{ 0x02 , V_165 , 0x00 , 0x00 } ,
{ 0x08 , V_166 , 0x04 , 0x00 } ,
{ 0x10 , V_78 , 0x21 , 0x00 } ,
{ 0x20 , V_168 , 0x28 , 0x00 } ,
{ 0x40 , V_167 , 0x11 , 0x04 } ,
{ 0x80 , V_167 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_169 [] [ 4 ] = {
{ 0x80 , V_164 , 0x47 , 0x00 } ,
{ 0x20 , V_165 , 0x44 , 0x00 } ,
{ 0x08 , V_164 , 0x47 , 0x00 } ,
{ 0x04 , V_124 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_159 & V_158 ) {
V_160 = 0 ;
}
if ( V_160 ) {
for ( V_162 = 0 ; V_163 [ V_162 ] [ 0 ] != 0xFF ; V_162 ++ ) {
if ( ( V_163 [ V_162 ] [ 0 ] & V_160 ) ==
V_163 [ V_162 ] [ 0 ] ) {
* V_57 = V_163 [ V_162 ] [ 1 ] ;
* V_58 = V_163 [ V_162 ] [ 2 ] ;
* V_59 = V_163 [ V_162 ] [ 3 ] ;
goto V_170;
}
}
}
for ( V_162 = 0 ; V_169 [ V_162 ] [ 0 ] != 0xFF ; V_162 ++ ) {
if ( V_169 [ V_162 ] [ 0 ] & V_159 ) {
* V_57 = V_169 [ V_162 ] [ 1 ] ;
* V_58 = V_169 [ V_162 ] [ 2 ] ;
* V_59 = V_169 [ V_162 ] [ 3 ] ;
goto V_170;
}
}
* V_57 = V_164 ;
* V_58 = 0x00 ;
* V_59 = 0x00 ;
V_170:
if ( V_161 )
F_58 ( V_171 L_22
L_23 ,
V_92 , V_159 , V_160 , * V_57 , * V_58 , * V_59 ) ;
return;
}
static void F_60 ( struct V_138 * V_139 )
{
struct V_55 * V_56 = V_139 -> V_140 ;
struct V_151 * V_152 = & V_139 -> V_172 ;
unsigned char * V_173 = V_56 -> V_63 ;
unsigned char * V_120 = V_173 + 8 ;
int V_161 = V_139 -> V_9 -> V_64 -> V_174 == NULL ;
memset ( V_173 , 0 , V_110 ) ;
V_56 -> V_60 = ( V_61 << 24 ) | V_62 ;
if ( V_139 -> V_175 ||
V_152 -> V_154 & ( V_158 | V_176 | V_177 | V_178 ) ) {
F_59 ( V_139 -> V_9 -> V_179 , V_152 -> V_154 , V_152 -> V_156 ,
& V_173 [ 1 ] , & V_173 [ 2 ] , & V_173 [ 3 ] , V_161 ) ;
V_173 [ 1 ] &= 0x0f ;
} else {
V_173 [ 1 ] = V_124 ;
V_173 [ 2 ] = 0 ;
V_173 [ 3 ] = 0x1D ;
}
V_173 [ 0 ] = 0x72 ;
V_120 [ 0 ] = 0x09 ;
V_173 [ 7 ] = 14 ;
V_120 [ 1 ] = 12 ;
V_120 [ 2 ] = 0x00 ;
V_120 [ 3 ] = V_152 -> V_156 ;
V_120 [ 5 ] = V_152 -> V_180 ;
V_120 [ 7 ] = V_152 -> V_181 ;
V_120 [ 9 ] = V_152 -> V_182 ;
V_120 [ 11 ] = V_152 -> V_183 ;
V_120 [ 12 ] = V_152 -> V_1 ;
V_120 [ 13 ] = V_152 -> V_154 ;
if ( V_152 -> V_16 & V_184 ) {
V_120 [ 2 ] |= 0x01 ;
V_120 [ 4 ] = V_152 -> V_185 ;
V_120 [ 6 ] = V_152 -> V_186 ;
V_120 [ 8 ] = V_152 -> V_187 ;
V_120 [ 10 ] = V_152 -> V_188 ;
}
}
static void F_61 ( struct V_138 * V_139 )
{
struct V_12 * V_13 = V_139 -> V_13 ;
struct V_55 * V_56 = V_139 -> V_140 ;
struct V_151 * V_152 = & V_139 -> V_172 ;
unsigned char * V_173 = V_56 -> V_63 ;
unsigned char * V_120 = V_173 + 8 ;
int V_161 = V_139 -> V_9 -> V_64 -> V_174 == NULL ;
T_7 V_189 ;
memset ( V_173 , 0 , V_110 ) ;
V_56 -> V_60 = ( V_61 << 24 ) | V_62 ;
V_173 [ 0 ] = 0x72 ;
if ( V_139 -> V_175 ||
V_152 -> V_154 & ( V_158 | V_176 | V_177 | V_178 ) ) {
F_59 ( V_139 -> V_9 -> V_179 , V_152 -> V_154 , V_152 -> V_156 ,
& V_173 [ 1 ] , & V_173 [ 2 ] , & V_173 [ 3 ] , V_161 ) ;
V_173 [ 1 ] &= 0x0f ;
}
V_189 = F_62 ( & V_139 -> V_172 , V_13 ) ;
V_173 [ 7 ] = 12 ;
V_120 [ 0 ] = 0x00 ;
V_120 [ 1 ] = 10 ;
V_120 [ 2 ] |= 0x80 ;
V_120 [ 6 ] = V_189 >> 40 ;
V_120 [ 7 ] = V_189 >> 32 ;
V_120 [ 8 ] = V_189 >> 24 ;
V_120 [ 9 ] = V_189 >> 16 ;
V_120 [ 10 ] = V_189 >> 8 ;
V_120 [ 11 ] = V_189 ;
}
static void F_63 ( struct V_28 * V_29 )
{
V_29 -> V_190 = 1 ;
V_29 -> V_191 = 1 ;
V_29 -> V_192 = 1 ;
V_29 -> V_193 = 1 ;
V_29 -> V_194 = 1 ;
}
static int F_64 ( struct V_148 * V_195 )
{
if ( F_65 ( V_195 -> V_196 != V_197 ) )
return 0 ;
if ( ! F_66 ( V_195 ) || ( V_195 -> V_198 & V_199 ) )
return 0 ;
return F_67 ( V_195 -> V_56 [ 0 ] ) == V_200 ;
}
static int F_68 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_201 * V_202 = V_29 -> V_201 ;
if ( ! F_69 ( V_13 -> V_92 ) )
V_13 -> V_16 |= V_37 ;
F_70 ( V_202 , V_13 -> V_203 ) ;
if ( V_13 -> V_49 == V_204 ) {
void * V_4 ;
V_29 -> V_205 = V_113 ;
F_71 ( V_202 , V_206 - 1 ) ;
V_4 = F_41 ( V_207 , V_202 -> V_208 | V_114 ) ;
if ( ! V_4 ) {
F_72 ( V_13 , L_24 ) ;
return - V_112 ;
}
F_73 ( V_202 , F_64 , V_4 , V_207 ) ;
} else {
V_29 -> V_205 = F_74 ( V_13 -> V_92 ) ;
V_29 -> V_209 = 1 ;
}
if ( V_29 -> V_205 > V_27 )
F_75 ( V_13 ,
L_25 ,
V_29 -> V_205 ) ;
F_76 ( V_202 , V_29 -> V_205 - 1 ) ;
if ( V_13 -> V_16 & V_210 )
F_77 ( V_211 , V_29 -> V_212 ) ;
if ( V_13 -> V_16 & V_213 ) {
int V_214 ;
V_214 = F_78 ( V_29 -> V_34 -> V_215 , F_79 ( V_13 -> V_92 ) ) ;
V_214 = F_78 ( V_216 - 1 , V_214 ) ;
F_80 ( V_29 , V_217 , V_214 ) ;
}
F_81 ( V_202 , false ) ;
V_13 -> V_29 = V_29 ;
return 0 ;
}
int F_82 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 = F_83 ( V_9 , V_29 ) ;
int V_33 = 0 ;
F_63 ( V_29 ) ;
if ( V_13 )
V_33 = F_68 ( V_29 , V_13 ) ;
return V_33 ;
}
void F_84 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_201 * V_202 = V_29 -> V_201 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_64 -> V_174 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_83 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_218 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_45 ( V_202 -> V_219 ) ;
V_202 -> V_219 = NULL ;
V_202 -> V_220 = 0 ;
}
int F_85 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_221 , int V_222 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_222 != V_223 )
return - V_24 ;
if ( V_221 < 1 || V_221 == V_29 -> V_221 )
return V_29 -> V_221 ;
V_13 = F_13 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_86 ( V_13 ) )
return V_29 -> V_221 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_224 ;
if ( V_221 == 1 || ! F_87 ( V_13 ) ) {
V_13 -> V_16 |= V_224 ;
V_221 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_221 = F_78 ( V_221 , V_29 -> V_34 -> V_215 ) ;
V_221 = F_78 ( V_221 , F_79 ( V_13 -> V_92 ) ) ;
V_221 = F_78 ( V_221 , V_216 - 1 ) ;
if ( V_29 -> V_221 == V_221 )
return - V_20 ;
F_80 ( V_29 , V_217 , V_221 ) ;
return V_221 ;
}
int F_88 ( struct V_28 * V_29 , int V_221 ,
int V_222 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_85 ( V_9 , V_29 , V_221 , V_222 ) ;
}
static unsigned int F_89 ( struct V_138 * V_139 )
{
struct V_55 * V_146 = V_139 -> V_140 ;
struct V_151 * V_152 = & V_139 -> V_152 ;
const T_3 * V_225 = V_146 -> V_226 ;
if ( V_146 -> V_227 < 5 )
goto V_228;
V_152 -> V_16 |= V_229 | V_230 ;
V_152 -> V_231 = V_232 ;
if ( V_225 [ 1 ] & 0x1 ) {
;
}
if ( V_225 [ 4 ] & 0x2 )
goto V_228;
if ( ( ( V_225 [ 4 ] >> 4 ) & 0xf ) != 0 )
goto V_228;
if ( V_225 [ 4 ] & 0x1 ) {
V_152 -> V_180 = 1 ;
if ( V_139 -> V_13 -> V_16 & V_233 ) {
V_152 -> V_16 |= V_234 ;
V_152 -> V_183 = 0x0 ;
V_152 -> V_182 = 0x0 ;
V_152 -> V_181 = 0x0 ;
V_152 -> V_1 |= V_235 ;
} else {
V_152 -> V_181 = 0x1 ;
V_152 -> V_182 = 0x0 ;
V_152 -> V_183 = 0x0 ;
}
V_152 -> V_154 = V_236 ;
} else {
if ( ( V_139 -> V_9 -> V_16 & V_237 ) &&
V_238 == V_239 )
goto V_240;
if ( ( V_139 -> V_9 -> V_16 & V_241 ) &&
F_90 () )
goto V_240;
V_152 -> V_154 = V_242 ;
}
return 0 ;
V_228:
F_22 ( V_146 , V_78 , 0x24 , 0x0 ) ;
return 1 ;
V_240:
V_146 -> V_60 = V_243 ;
return 1 ;
}
static unsigned int F_91 ( struct V_138 * V_139 )
{
struct V_151 * V_152 = & V_139 -> V_152 ;
V_152 -> V_16 |= V_229 ;
V_152 -> V_231 = V_232 ;
if ( V_139 -> V_13 -> V_16 & V_244 )
V_152 -> V_154 = V_245 ;
else
V_152 -> V_154 = V_246 ;
V_139 -> V_16 |= V_247 ;
return 0 ;
}
static void F_92 ( const T_3 * V_225 , T_7 * V_248 , T_8 * V_249 )
{
T_7 V_250 = 0 ;
T_8 V_45 ;
F_93 ( L_26 ) ;
V_250 |= ( ( T_7 ) ( V_225 [ 1 ] & 0x1f ) ) << 16 ;
V_250 |= ( ( T_7 ) V_225 [ 2 ] ) << 8 ;
V_250 |= ( ( T_7 ) V_225 [ 3 ] ) ;
V_45 = V_225 [ 4 ] ;
* V_248 = V_250 ;
* V_249 = V_45 ;
}
static void F_94 ( const T_3 * V_225 , T_7 * V_248 , T_8 * V_249 )
{
T_7 V_250 = 0 ;
T_8 V_45 = 0 ;
F_93 ( L_27 ) ;
V_250 |= ( ( T_7 ) V_225 [ 2 ] ) << 24 ;
V_250 |= ( ( T_7 ) V_225 [ 3 ] ) << 16 ;
V_250 |= ( ( T_7 ) V_225 [ 4 ] ) << 8 ;
V_250 |= ( ( T_7 ) V_225 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_225 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_225 [ 8 ] ) ;
* V_248 = V_250 ;
* V_249 = V_45 ;
}
static void F_95 ( const T_3 * V_225 , T_7 * V_248 , T_8 * V_249 )
{
T_7 V_250 = 0 ;
T_8 V_45 = 0 ;
F_93 ( L_28 ) ;
V_250 |= ( ( T_7 ) V_225 [ 2 ] ) << 56 ;
V_250 |= ( ( T_7 ) V_225 [ 3 ] ) << 48 ;
V_250 |= ( ( T_7 ) V_225 [ 4 ] ) << 40 ;
V_250 |= ( ( T_7 ) V_225 [ 5 ] ) << 32 ;
V_250 |= ( ( T_7 ) V_225 [ 6 ] ) << 24 ;
V_250 |= ( ( T_7 ) V_225 [ 7 ] ) << 16 ;
V_250 |= ( ( T_7 ) V_225 [ 8 ] ) << 8 ;
V_250 |= ( ( T_7 ) V_225 [ 9 ] ) ;
V_45 |= ( ( T_8 ) V_225 [ 10 ] ) << 24 ;
V_45 |= ( ( T_8 ) V_225 [ 11 ] ) << 16 ;
V_45 |= ( ( T_8 ) V_225 [ 12 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_225 [ 13 ] ) ;
* V_248 = V_250 ;
* V_249 = V_45 ;
}
static unsigned int F_96 ( struct V_138 * V_139 )
{
struct V_55 * V_146 = V_139 -> V_140 ;
struct V_151 * V_152 = & V_139 -> V_152 ;
struct V_12 * V_13 = V_139 -> V_13 ;
T_7 V_251 = V_139 -> V_13 -> V_84 ;
const T_3 * V_225 = V_146 -> V_226 ;
T_7 V_189 ;
T_8 V_252 ;
V_152 -> V_16 |= V_230 | V_229 ;
V_152 -> V_231 = V_232 ;
if ( V_225 [ 0 ] == V_253 ) {
if ( V_146 -> V_227 < 10 )
goto V_228;
F_94 ( V_225 , & V_189 , & V_252 ) ;
} else if ( V_225 [ 0 ] == V_254 ) {
if ( V_146 -> V_227 < 16 )
goto V_228;
F_95 ( V_225 , & V_189 , & V_252 ) ;
} else
goto V_228;
if ( ! V_252 )
goto V_255;
if ( V_189 >= V_251 )
goto V_256;
if ( ( V_189 + V_252 ) > V_251 )
goto V_256;
if ( V_13 -> V_16 & V_233 ) {
V_152 -> V_16 |= V_234 ;
if ( F_97 ( V_189 , V_252 ) ) {
V_152 -> V_154 = V_236 ;
V_152 -> V_1 |= ( V_189 >> 24 ) & 0xf ;
} else if ( F_98 ( V_189 , V_252 ) ) {
if ( ! ( V_13 -> V_16 & V_257 ) )
goto V_256;
V_152 -> V_16 |= V_184 ;
V_152 -> V_154 = V_258 ;
V_152 -> V_185 = ( V_252 >> 8 ) & 0xff ;
V_152 -> V_188 = ( V_189 >> 40 ) & 0xff ;
V_152 -> V_187 = ( V_189 >> 32 ) & 0xff ;
V_152 -> V_186 = ( V_189 >> 24 ) & 0xff ;
} else
goto V_256;
V_152 -> V_180 = V_252 & 0xff ;
V_152 -> V_183 = ( V_189 >> 16 ) & 0xff ;
V_152 -> V_182 = ( V_189 >> 8 ) & 0xff ;
V_152 -> V_181 = V_189 & 0xff ;
V_152 -> V_1 |= V_235 ;
} else {
T_8 V_259 , V_260 , V_261 , V_262 ;
if ( ! F_97 ( V_189 , V_252 ) )
goto V_256;
V_262 = ( T_8 ) V_189 / V_13 -> V_263 ;
V_261 = V_262 / V_13 -> V_264 ;
V_260 = V_262 % V_13 -> V_264 ;
V_259 = ( T_8 ) V_189 % V_13 -> V_263 + 1 ;
F_99 ( L_29 ,
( T_8 ) V_189 , V_262 , V_261 , V_260 , V_259 ) ;
if ( ( V_261 >> 16 ) || ( V_260 >> 4 ) || ( V_259 >> 8 ) || ( ! V_259 ) )
goto V_256;
V_152 -> V_154 = V_236 ;
V_152 -> V_180 = V_252 & 0xff ;
V_152 -> V_181 = V_259 ;
V_152 -> V_182 = V_261 ;
V_152 -> V_183 = V_261 >> 8 ;
V_152 -> V_1 |= V_260 ;
}
return 0 ;
V_228:
F_22 ( V_146 , V_78 , 0x24 , 0x0 ) ;
return 1 ;
V_256:
F_22 ( V_146 , V_78 , 0x21 , 0x0 ) ;
return 1 ;
V_255:
V_146 -> V_60 = V_243 ;
return 1 ;
}
static unsigned int F_100 ( struct V_138 * V_139 )
{
struct V_55 * V_146 = V_139 -> V_140 ;
const T_3 * V_225 = V_146 -> V_226 ;
unsigned int V_265 = 0 ;
T_7 V_189 ;
T_8 V_252 ;
int V_33 ;
if ( V_225 [ 0 ] == V_266 || V_225 [ 0 ] == V_267 || V_225 [ 0 ] == V_268 )
V_265 |= V_269 ;
switch ( V_225 [ 0 ] ) {
case V_270 :
case V_266 :
if ( F_19 ( V_146 -> V_227 < 10 ) )
goto V_228;
F_94 ( V_225 , & V_189 , & V_252 ) ;
if ( V_225 [ 1 ] & ( 1 << 3 ) )
V_265 |= V_271 ;
break;
case V_272 :
case V_267 :
if ( F_19 ( V_146 -> V_227 < 6 ) )
goto V_228;
F_92 ( V_225 , & V_189 , & V_252 ) ;
if ( ! V_252 )
V_252 = 256 ;
break;
case V_273 :
case V_268 :
if ( F_19 ( V_146 -> V_227 < 16 ) )
goto V_228;
F_95 ( V_225 , & V_189 , & V_252 ) ;
if ( V_225 [ 1 ] & ( 1 << 3 ) )
V_265 |= V_271 ;
break;
default:
F_99 ( L_30 ) ;
goto V_228;
}
if ( ! V_252 )
goto V_255;
V_139 -> V_16 |= V_247 ;
V_139 -> V_150 = V_252 * V_146 -> V_1 -> V_205 ;
V_33 = F_101 ( & V_139 -> V_152 , V_139 -> V_13 , V_189 , V_252 , V_265 ,
V_139 -> V_274 ) ;
if ( F_65 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_275 )
goto V_256;
V_228:
F_22 ( V_146 , V_78 , 0x24 , 0x0 ) ;
return 1 ;
V_256:
F_22 ( V_146 , V_78 , 0x21 , 0x0 ) ;
return 1 ;
V_255:
V_146 -> V_60 = V_243 ;
return 1 ;
}
static void F_102 ( struct V_138 * V_139 )
{
struct V_8 * V_9 = V_139 -> V_9 ;
struct V_55 * V_56 = V_139 -> V_140 ;
T_3 * V_225 = V_56 -> V_226 ;
int V_276 = ( V_139 -> V_175 != 0 ) ;
if ( ( ( V_225 [ 0 ] == V_117 ) || ( V_225 [ 0 ] == V_277 ) ) &&
( ( V_225 [ 2 ] & 0x20 ) || V_276 ) ) {
F_60 ( V_139 ) ;
} else {
if ( ! V_276 ) {
V_56 -> V_60 = V_243 ;
} else {
F_61 ( V_139 ) ;
}
}
if ( V_276 && ! V_9 -> V_64 -> V_174 )
F_57 ( V_9 -> V_179 , & V_139 -> V_172 ) ;
V_139 -> V_141 ( V_56 ) ;
F_103 ( V_139 ) ;
}
static int F_104 ( struct V_12 * V_13 , struct V_55 * V_56 ,
T_9 V_278 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_138 * V_139 ;
int V_33 ;
F_93 ( L_31 ) ;
V_139 = F_51 ( V_13 , V_56 ) ;
if ( ! V_139 )
goto V_279;
if ( V_56 -> V_280 == V_115 ||
V_56 -> V_280 == V_281 ) {
if ( F_19 ( F_56 ( V_56 ) < 1 ) ) {
F_75 ( V_13 , L_32 ) ;
goto V_282;
}
F_105 ( V_139 , F_53 ( V_56 ) , F_54 ( V_56 ) ) ;
V_139 -> V_283 = V_56 -> V_280 ;
}
V_139 -> V_284 = F_102 ;
if ( V_278 ( V_139 ) )
goto V_285;
if ( V_9 -> V_64 -> V_286 ) {
if ( ( V_33 = V_9 -> V_64 -> V_286 ( V_139 ) ) )
goto V_287;
}
F_106 ( V_139 ) ;
F_93 ( L_33 ) ;
return 0 ;
V_285:
F_103 ( V_139 ) ;
V_56 -> V_79 ( V_56 ) ;
F_99 ( L_34 ) ;
return 0 ;
V_282:
F_103 ( V_139 ) ;
V_56 -> V_60 = ( V_288 << 16 ) ;
V_56 -> V_79 ( V_56 ) ;
V_279:
F_99 ( L_35 ) ;
return 0 ;
V_287:
F_103 ( V_139 ) ;
F_99 ( L_36 ) ;
if ( V_33 == V_289 )
return V_290 ;
else
return V_291 ;
}
static void * F_107 ( struct V_55 * V_56 , bool V_292 ,
unsigned long * V_16 )
{
F_5 ( & V_293 , * V_16 ) ;
memset ( V_294 , 0 , V_295 ) ;
if ( V_292 )
F_108 ( F_53 ( V_56 ) , F_54 ( V_56 ) ,
V_294 , V_295 ) ;
return V_294 ;
}
static inline void F_109 ( struct V_55 * V_56 , bool V_296 ,
unsigned long * V_16 )
{
if ( V_296 )
F_110 ( F_53 ( V_56 ) , F_54 ( V_56 ) ,
V_294 , V_295 ) ;
F_9 ( & V_293 , * V_16 ) ;
}
static unsigned int F_111 ( struct V_297 * args , T_3 * V_298 )
{
const T_3 V_299 [] = {
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
T_3 V_300 [] = {
V_301 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_93 ( L_31 ) ;
if ( F_112 ( args -> V_92 ) )
V_300 [ 1 ] |= ( 1 << 7 ) ;
memcpy ( V_298 , V_300 , sizeof( V_300 ) ) ;
memcpy ( & V_298 [ 8 ] , L_37 , 8 ) ;
F_37 ( args -> V_92 , & V_298 [ 16 ] , V_95 , 16 ) ;
F_37 ( args -> V_92 , & V_298 [ 32 ] , V_97 , 4 ) ;
if ( V_298 [ 32 ] == 0 || V_298 [ 32 ] == ' ' )
memcpy ( & V_298 [ 32 ] , L_38 , 4 ) ;
memcpy ( V_298 + 59 , V_299 , sizeof( V_299 ) ) ;
return 0 ;
}
static unsigned int F_113 ( struct V_297 * args , T_3 * V_298 )
{
const T_3 V_302 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
} ;
V_298 [ 3 ] = sizeof( V_302 ) ;
memcpy ( V_298 + 4 , V_302 , sizeof( V_302 ) ) ;
return 0 ;
}
static unsigned int F_114 ( struct V_297 * args , T_3 * V_298 )
{
const T_3 V_300 [] = {
0 ,
0x80 ,
0 ,
V_100 ,
} ;
memcpy ( V_298 , V_300 , sizeof( V_300 ) ) ;
F_37 ( args -> V_92 , ( unsigned char * ) & V_298 [ 4 ] ,
V_99 , V_100 ) ;
return 0 ;
}
static unsigned int F_115 ( struct V_297 * args , T_3 * V_298 )
{
const int V_303 = 68 ;
int V_304 ;
V_298 [ 1 ] = 0x83 ;
V_304 = 4 ;
V_298 [ V_304 + 0 ] = 2 ;
V_298 [ V_304 + 3 ] = V_100 ;
V_304 += 4 ;
F_37 ( args -> V_92 , ( unsigned char * ) V_298 + V_304 ,
V_99 , V_100 ) ;
V_304 += V_100 ;
V_298 [ V_304 + 0 ] = 2 ;
V_298 [ V_304 + 1 ] = 1 ;
V_298 [ V_304 + 3 ] = V_303 ;
V_304 += 4 ;
memcpy ( V_298 + V_304 , L_37 , 8 ) ;
V_304 += 8 ;
F_37 ( args -> V_92 , ( unsigned char * ) V_298 + V_304 , V_95 ,
V_96 ) ;
V_304 += V_96 ;
F_37 ( args -> V_92 , ( unsigned char * ) V_298 + V_304 , V_99 ,
V_100 ) ;
V_304 += V_100 ;
if ( F_116 ( args -> V_92 ) ) {
V_298 [ V_304 + 0 ] = 1 ;
V_298 [ V_304 + 1 ] = 3 ;
V_298 [ V_304 + 3 ] = V_305 ;
V_304 += 4 ;
F_37 ( args -> V_92 , ( unsigned char * ) V_298 + V_304 ,
V_306 , V_305 ) ;
V_304 += V_305 ;
}
V_298 [ 3 ] = V_304 - 4 ;
return 0 ;
}
static unsigned int F_117 ( struct V_297 * args , T_3 * V_298 )
{
struct V_151 V_152 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_298 [ 1 ] = 0x89 ;
V_298 [ 2 ] = ( 0x238 >> 8 ) ;
V_298 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_298 [ 8 ] , L_39 , 8 ) ;
memcpy ( & V_298 [ 16 ] , L_40 , 16 ) ;
memcpy ( & V_298 [ 32 ] , V_307 , 4 ) ;
V_152 . V_154 = V_308 ;
V_152 . V_181 = 0x1 ;
V_152 . V_180 = 0x1 ;
F_118 ( & V_152 , 0 , 1 , & V_298 [ 36 ] ) ;
V_298 [ 36 ] = 0x34 ;
V_298 [ 56 ] = V_309 ;
memcpy ( & V_298 [ 60 ] , & args -> V_92 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_119 ( struct V_297 * args , T_3 * V_298 )
{
T_6 V_310 ;
V_298 [ 1 ] = 0xb0 ;
V_298 [ 3 ] = 0x3c ;
V_310 = 1 << F_120 ( args -> V_92 ) ;
F_121 ( V_310 , & V_298 [ 6 ] ) ;
if ( F_122 ( args -> V_92 ) ) {
F_123 ( 65535 * 512 / 8 , & V_298 [ 36 ] ) ;
F_124 ( 1 , & V_298 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_125 ( struct V_297 * args , T_3 * V_298 )
{
int V_311 = F_126 ( args -> V_92 ) ;
int V_312 = F_127 ( args -> V_92 ) ;
V_298 [ 1 ] = 0xb1 ;
V_298 [ 3 ] = 0x3c ;
V_298 [ 4 ] = V_312 >> 8 ;
V_298 [ 5 ] = V_312 ;
V_298 [ 7 ] = V_311 ;
return 0 ;
}
static unsigned int F_128 ( struct V_297 * args , T_3 * V_298 )
{
V_298 [ 1 ] = 0xb2 ;
V_298 [ 3 ] = 0x4 ;
V_298 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_129 ( struct V_297 * args , T_3 * V_298 )
{
F_93 ( L_31 ) ;
return 0 ;
}
static void F_130 ( T_3 * V_313 , const T_3 * V_314 , int V_315 , bool V_316 )
{
if ( V_316 ) {
memcpy ( V_313 , V_314 , 2 ) ;
memset ( V_313 + 2 , 0 , V_315 - 2 ) ;
} else {
memcpy ( V_313 , V_314 , V_315 ) ;
}
}
static unsigned int F_131 ( T_6 * V_92 , T_3 * V_4 , bool V_316 )
{
F_130 ( V_4 , V_317 , sizeof( V_317 ) , V_316 ) ;
if ( V_316 || F_132 ( V_92 ) )
V_4 [ 2 ] |= ( 1 << 2 ) ;
if ( ! V_316 && ! F_133 ( V_92 ) )
V_4 [ 12 ] |= ( 1 << 5 ) ;
return sizeof( V_317 ) ;
}
static unsigned int F_134 ( T_3 * V_4 , bool V_316 )
{
F_130 ( V_4 , V_318 , sizeof( V_318 ) , V_316 ) ;
return sizeof( V_318 ) ;
}
static unsigned int F_135 ( T_3 * V_4 , bool V_316 )
{
F_130 ( V_4 , V_319 , sizeof( V_319 ) ,
V_316 ) ;
return sizeof( V_319 ) ;
}
static int F_136 ( T_6 * V_92 )
{
unsigned char V_320 [ V_96 + 1 ] , V_321 [ V_98 + 1 ] ;
if ( ! V_322 )
return 0 ;
if ( ! F_137 ( V_92 ) )
return 0 ;
F_138 ( V_92 , V_320 , V_95 , sizeof( V_320 ) ) ;
F_138 ( V_92 , V_321 , V_97 , sizeof( V_321 ) ) ;
if ( strcmp ( V_320 , L_41 ) )
return 1 ;
if ( strcmp ( V_321 , L_42 ) )
return 1 ;
return 0 ;
}
static unsigned int F_139 ( struct V_297 * args , T_3 * V_298 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_140 = args -> V_56 -> V_226 , * V_323 = V_298 ;
const T_3 V_324 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_325 , V_326 ;
unsigned int V_327 , V_328 , V_329 ;
T_3 V_330 ;
F_93 ( L_31 ) ;
V_329 = ( V_140 [ 0 ] == V_331 ) ;
V_327 = ! ( V_140 [ 1 ] & 0x8 ) ;
V_328 = V_140 [ 2 ] >> 6 ;
switch ( V_328 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_332;
default:
goto V_228;
}
if ( V_329 )
V_323 += 4 + ( V_327 ? 8 : 0 ) ;
else
V_323 += 8 + ( V_327 ? 8 : 0 ) ;
V_325 = V_140 [ 2 ] & 0x3f ;
V_326 = V_140 [ 3 ] ;
if ( V_326 && ( V_326 != V_333 ) )
goto V_228;
switch( V_325 ) {
case V_334 :
V_323 += F_135 ( V_323 , V_328 == 1 ) ;
break;
case V_335 :
V_323 += F_131 ( args -> V_92 , V_323 , V_328 == 1 ) ;
break;
case V_336 :
V_323 += F_134 ( V_323 , V_328 == 1 ) ;
break;
case V_337 :
V_323 += F_135 ( V_323 , V_328 == 1 ) ;
V_323 += F_131 ( args -> V_92 , V_323 , V_328 == 1 ) ;
V_323 += F_134 ( V_323 , V_328 == 1 ) ;
break;
default:
goto V_228;
}
V_330 = 0 ;
if ( F_136 ( args -> V_92 ) && ( V_13 -> V_16 & V_257 ) &&
( ! ( V_13 -> V_16 & V_338 ) || V_13 -> V_339 ) )
V_330 = 1 << 4 ;
if ( V_329 ) {
V_298 [ 0 ] = V_323 - V_298 - 1 ;
V_298 [ 2 ] |= V_330 ;
if ( V_327 ) {
V_298 [ 3 ] = sizeof( V_324 ) ;
memcpy ( V_298 + 4 , V_324 , sizeof( V_324 ) ) ;
}
} else {
unsigned int V_340 = V_323 - V_298 - 2 ;
V_298 [ 0 ] = V_340 >> 8 ;
V_298 [ 1 ] = V_340 ;
V_298 [ 3 ] |= V_330 ;
if ( V_327 ) {
V_298 [ 7 ] = sizeof( V_324 ) ;
memcpy ( V_298 + 8 , V_324 , sizeof( V_324 ) ) ;
}
}
return 0 ;
V_228:
F_22 ( args -> V_56 , V_78 , 0x24 , 0x0 ) ;
return 1 ;
V_332:
F_22 ( args -> V_56 , V_78 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_140 ( struct V_297 * args , T_3 * V_298 )
{
struct V_12 * V_13 = args -> V_13 ;
T_7 V_341 = V_13 -> V_84 - 1 ;
T_8 V_205 ;
T_3 V_342 ;
T_6 V_343 ;
V_205 = F_74 ( V_13 -> V_92 ) ;
V_342 = F_120 ( V_13 -> V_92 ) ;
V_343 = F_141 ( V_13 -> V_92 , V_342 ) ;
F_93 ( L_31 ) ;
if ( args -> V_56 -> V_226 [ 0 ] == V_344 ) {
if ( V_341 >= 0xffffffffULL )
V_341 = 0xffffffff ;
V_298 [ 0 ] = V_341 >> ( 8 * 3 ) ;
V_298 [ 1 ] = V_341 >> ( 8 * 2 ) ;
V_298 [ 2 ] = V_341 >> ( 8 * 1 ) ;
V_298 [ 3 ] = V_341 ;
V_298 [ 4 ] = V_205 >> ( 8 * 3 ) ;
V_298 [ 5 ] = V_205 >> ( 8 * 2 ) ;
V_298 [ 6 ] = V_205 >> ( 8 * 1 ) ;
V_298 [ 7 ] = V_205 ;
} else {
V_298 [ 0 ] = V_341 >> ( 8 * 7 ) ;
V_298 [ 1 ] = V_341 >> ( 8 * 6 ) ;
V_298 [ 2 ] = V_341 >> ( 8 * 5 ) ;
V_298 [ 3 ] = V_341 >> ( 8 * 4 ) ;
V_298 [ 4 ] = V_341 >> ( 8 * 3 ) ;
V_298 [ 5 ] = V_341 >> ( 8 * 2 ) ;
V_298 [ 6 ] = V_341 >> ( 8 * 1 ) ;
V_298 [ 7 ] = V_341 ;
V_298 [ 8 ] = V_205 >> ( 8 * 3 ) ;
V_298 [ 9 ] = V_205 >> ( 8 * 2 ) ;
V_298 [ 10 ] = V_205 >> ( 8 * 1 ) ;
V_298 [ 11 ] = V_205 ;
V_298 [ 12 ] = 0 ;
V_298 [ 13 ] = V_342 ;
V_298 [ 14 ] = ( V_343 >> 8 ) & 0x3f ;
V_298 [ 15 ] = V_343 ;
if ( F_122 ( args -> V_92 ) ) {
V_298 [ 14 ] |= 0x80 ;
if ( F_142 ( args -> V_92 ) )
V_298 [ 14 ] |= 0x40 ;
}
}
return 0 ;
}
static unsigned int F_143 ( struct V_297 * args , T_3 * V_298 )
{
F_93 ( L_31 ) ;
V_298 [ 3 ] = 8 ;
return 0 ;
}
static void F_144 ( struct V_138 * V_139 )
{
if ( V_139 -> V_175 && ( ( V_139 -> V_175 & V_345 ) == 0 ) ) {
F_60 ( V_139 ) ;
}
V_139 -> V_141 ( V_139 -> V_140 ) ;
F_103 ( V_139 ) ;
}
static inline int F_145 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_126 ) ;
}
static void F_146 ( struct V_138 * V_139 )
{
struct V_8 * V_9 = V_139 -> V_9 ;
struct V_55 * V_56 = V_139 -> V_140 ;
F_99 ( L_43 ) ;
memset ( V_56 -> V_63 , 0 , V_110 ) ;
#ifdef F_147
if ( V_9 -> V_64 -> V_346 )
V_9 -> V_64 -> V_346 ( V_9 , & V_139 -> V_152 ) ;
#endif
V_56 -> V_63 [ 0 ] = 0x70 ;
V_56 -> V_63 [ 2 ] = V_139 -> V_152 . V_156 >> 4 ;
F_148 ( V_139 ) ;
F_149 ( & V_139 -> V_347 , V_56 -> V_63 , V_110 ) ;
F_105 ( V_139 , & V_139 -> V_347 , 1 ) ;
V_139 -> V_283 = V_115 ;
memset ( & V_139 -> V_225 , 0 , V_139 -> V_13 -> V_348 ) ;
V_139 -> V_225 [ 0 ] = V_349 ;
V_139 -> V_225 [ 4 ] = V_110 ;
V_139 -> V_152 . V_16 |= V_230 | V_229 ;
V_139 -> V_152 . V_154 = V_350 ;
if ( F_145 ( V_9 ) ) {
V_139 -> V_152 . V_231 = V_351 ;
V_139 -> V_152 . V_156 |= V_352 ;
} else {
V_139 -> V_152 . V_231 = V_353 ;
V_139 -> V_152 . V_182 = V_110 ;
V_139 -> V_152 . V_183 = 0 ;
}
V_139 -> V_150 = V_110 ;
V_139 -> V_284 = F_144 ;
F_106 ( V_139 ) ;
F_99 ( L_33 ) ;
}
static void F_150 ( struct V_138 * V_139 )
{
struct V_55 * V_56 = V_139 -> V_140 ;
unsigned int V_175 = V_139 -> V_175 ;
F_93 ( L_44 , V_175 ) ;
if ( F_19 ( V_139 -> V_9 -> V_64 -> V_174 &&
( V_175 || V_139 -> V_16 & V_354 ) ) ) {
if ( ! ( V_139 -> V_16 & V_354 ) ) {
F_60 ( V_139 ) ;
}
if ( V_139 -> V_225 [ 0 ] == V_355 && V_139 -> V_13 -> V_29 )
V_139 -> V_13 -> V_29 -> V_356 = 0 ;
V_139 -> V_140 -> V_60 = V_62 ;
V_139 -> V_141 ( V_56 ) ;
F_103 ( V_139 ) ;
return;
}
if ( F_19 ( V_175 & V_345 ) ) {
V_56 -> V_60 = V_62 ;
F_146 ( V_139 ) ;
return;
} else if ( F_19 ( V_175 ) ) {
F_60 ( V_139 ) ;
} else {
T_3 * V_140 = V_56 -> V_226 ;
if ( ( V_140 [ 0 ] == V_357 ) && ( ( V_140 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_16 ;
T_3 * V_4 ;
V_4 = F_107 ( V_56 , true , & V_16 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_109 ( V_56 , true , & V_16 ) ;
}
V_56 -> V_60 = V_243 ;
}
V_139 -> V_141 ( V_56 ) ;
F_103 ( V_139 ) ;
}
static unsigned int F_151 ( struct V_138 * V_139 )
{
struct V_55 * V_146 = V_139 -> V_140 ;
struct V_12 * V_13 = V_139 -> V_13 ;
int V_358 = ( V_146 -> V_280 == V_116 ) ;
int V_359 = ! V_358 && ( V_13 -> V_16 & V_338 ) ;
unsigned int V_150 ;
memset ( V_139 -> V_225 , 0 , V_13 -> V_348 ) ;
memcpy ( V_139 -> V_225 , V_146 -> V_226 , V_146 -> V_227 ) ;
V_139 -> V_284 = F_150 ;
V_139 -> V_152 . V_16 |= V_230 | V_229 ;
if ( V_146 -> V_280 == V_281 ) {
V_139 -> V_152 . V_16 |= V_269 ;
F_99 ( L_45 ) ;
}
V_139 -> V_152 . V_154 = V_350 ;
F_55 ( V_139 ) ;
if ( ! V_358 && ! V_359 && F_152 ( V_139 ) )
V_359 = 1 ;
V_150 = F_78 ( F_153 ( V_139 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_150 & 0x1 )
V_150 ++ ;
V_139 -> V_152 . V_182 = ( V_150 & 0xFF ) ;
V_139 -> V_152 . V_183 = ( V_150 >> 8 ) ;
if ( V_358 )
V_139 -> V_152 . V_231 = V_360 ;
else if ( V_359 )
V_139 -> V_152 . V_231 = V_353 ;
else {
V_139 -> V_152 . V_231 = V_351 ;
V_139 -> V_152 . V_156 |= V_352 ;
if ( ( V_13 -> V_16 & V_361 ) &&
( V_146 -> V_280 != V_281 ) )
V_139 -> V_152 . V_156 |= V_362 ;
}
return 0 ;
}
static struct V_12 * F_154 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_155 ( V_9 ) ) {
if ( F_65 ( V_43 < F_156 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_65 ( V_43 < V_9 -> V_363 ) )
return & V_9 -> V_364 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_83 ( struct V_8 * V_9 ,
const struct V_28 * V_101 )
{
int V_43 ;
if ( ! F_155 ( V_9 ) ) {
if ( F_19 ( V_101 -> V_365 || V_101 -> V_366 ) )
return NULL ;
V_43 = V_101 -> V_92 ;
} else {
if ( F_19 ( V_101 -> V_92 || V_101 -> V_366 ) )
return NULL ;
V_43 = V_101 -> V_365 ;
}
return F_154 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_13 ( struct V_8 * V_9 , const struct V_28 * V_101 )
{
struct V_12 * V_13 = F_83 ( V_9 , V_101 ) ;
if ( F_19 ( ! V_13 || ! F_86 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_157 ( T_3 V_367 )
{
switch( ( V_367 & 0x1e ) >> 1 ) {
case 3 :
return V_232 ;
case 6 :
case 10 :
case 11 :
return V_368 ;
case 4 :
case 5 :
return V_369 ;
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
return V_370 ;
}
static unsigned int F_158 ( struct V_138 * V_139 )
{
struct V_151 * V_152 = & ( V_139 -> V_152 ) ;
struct V_55 * V_146 = V_139 -> V_140 ;
struct V_12 * V_13 = V_139 -> V_13 ;
const T_3 * V_225 = V_146 -> V_226 ;
if ( ( V_152 -> V_231 = F_157 ( V_225 [ 1 ] ) ) == V_370 )
goto V_228;
if ( V_225 [ 0 ] == V_117 ) {
if ( V_225 [ 1 ] & 0x01 ) {
V_152 -> V_371 = V_225 [ 3 ] ;
V_152 -> V_185 = V_225 [ 5 ] ;
V_152 -> V_186 = V_225 [ 7 ] ;
V_152 -> V_187 = V_225 [ 9 ] ;
V_152 -> V_188 = V_225 [ 11 ] ;
V_152 -> V_16 |= V_184 ;
} else
V_152 -> V_16 &= ~ V_184 ;
V_152 -> V_156 = V_225 [ 4 ] ;
V_152 -> V_180 = V_225 [ 6 ] ;
V_152 -> V_181 = V_225 [ 8 ] ;
V_152 -> V_182 = V_225 [ 10 ] ;
V_152 -> V_183 = V_225 [ 12 ] ;
V_152 -> V_1 = V_225 [ 13 ] ;
V_152 -> V_154 = V_225 [ 14 ] ;
} else {
V_152 -> V_16 &= ~ V_184 ;
V_152 -> V_156 = V_225 [ 3 ] ;
V_152 -> V_180 = V_225 [ 4 ] ;
V_152 -> V_181 = V_225 [ 5 ] ;
V_152 -> V_182 = V_225 [ 6 ] ;
V_152 -> V_183 = V_225 [ 7 ] ;
V_152 -> V_1 = V_225 [ 8 ] ;
V_152 -> V_154 = V_225 [ 9 ] ;
}
V_152 -> V_1 = V_13 -> V_43 ?
V_152 -> V_1 | V_372 : V_152 -> V_1 & ~ V_372 ;
switch ( V_152 -> V_154 ) {
case V_373 :
case V_374 :
case V_375 :
case V_376 :
if ( V_152 -> V_231 != V_369 || V_152 -> V_180 != 1 )
goto V_228;
V_139 -> V_377 = F_56 ( V_146 ) ;
break;
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_236 :
case V_258 :
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
V_139 -> V_377 = V_146 -> V_1 -> V_205 ;
break;
default:
V_139 -> V_377 = V_113 ;
}
V_152 -> V_16 |= V_230 | V_229 ;
if ( V_146 -> V_280 == V_281 )
V_152 -> V_16 |= V_269 ;
V_139 -> V_16 |= V_404 | V_405 ;
F_55 ( V_139 ) ;
if ( V_152 -> V_231 == V_368 && V_13 -> V_406 == 0 )
goto V_228;
if ( ( V_225 [ 1 ] & 0xe0 ) && ! F_159 ( V_152 ) )
goto V_228;
if ( F_159 ( V_152 ) ) {
unsigned int V_339 = 1 << ( V_225 [ 1 ] >> 5 ) ;
if ( V_339 != V_13 -> V_339 )
F_75 ( V_13 , L_46 ,
V_339 ) ;
}
if ( V_152 -> V_154 == V_407 &&
V_152 -> V_156 == V_408 )
goto V_228;
if ( V_152 -> V_154 >= 0x5C && V_152 -> V_154 <= 0x5F && ! V_409 )
goto V_228;
return 0 ;
V_228:
F_22 ( V_146 , V_78 , 0x24 , 0x00 ) ;
return 1 ;
}
static unsigned int F_160 ( struct V_138 * V_139 )
{
struct V_151 * V_152 = & V_139 -> V_152 ;
struct V_55 * V_146 = V_139 -> V_140 ;
struct V_12 * V_13 = V_139 -> V_13 ;
const T_3 * V_225 = V_146 -> V_226 ;
T_7 V_189 ;
T_8 V_252 ;
T_8 V_410 ;
void * V_4 ;
if ( F_19 ( ! V_13 -> V_406 ) )
goto V_228;
if ( F_19 ( V_146 -> V_227 < 16 ) )
goto V_228;
F_95 ( V_225 , & V_189 , & V_252 ) ;
if ( F_19 ( ! ( V_225 [ 1 ] & 0x8 ) ) )
goto V_228;
if ( ! F_54 ( V_146 ) )
goto V_228;
V_4 = F_161 ( F_162 ( F_53 ( V_146 ) ) ) ;
V_410 = F_163 ( V_4 , 512 , V_189 , V_252 ) ;
if ( F_87 ( V_13 ) && F_164 ( V_13 ) ) {
V_152 -> V_231 = V_411 ;
V_152 -> V_154 = V_412 ;
V_152 -> V_185 = V_413 & 0x1f ;
V_152 -> V_180 = V_139 -> V_274 << 3 ;
V_152 -> V_371 = ( V_410 / 512 ) >> 8 ;
V_152 -> V_156 = V_410 / 512 ;
V_152 -> V_414 = 1 ;
} else {
V_152 -> V_231 = V_368 ;
V_152 -> V_371 = 0 ;
V_152 -> V_156 = V_415 ;
V_152 -> V_185 = ( V_410 / 512 ) >> 8 ;
V_152 -> V_180 = V_410 / 512 ;
V_152 -> V_154 = V_416 ;
}
V_152 -> V_16 |= V_230 | V_229 | V_184 |
V_269 ;
F_55 ( V_139 ) ;
return 0 ;
V_228:
F_22 ( V_146 , V_78 , 0x24 , 0x00 ) ;
return 1 ;
}
static int F_165 ( struct V_138 * V_139 ,
const T_3 * V_4 , int V_45 )
{
struct V_151 * V_152 = & V_139 -> V_152 ;
struct V_12 * V_13 = V_139 -> V_13 ;
char V_417 [ V_418 ] ;
T_3 V_419 ;
if ( V_45 != V_418 - 2 )
return - V_20 ;
V_419 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_131 ( V_13 -> V_92 , V_417 , false ) ;
V_417 [ 2 ] &= ~ ( 1 << 2 ) ;
V_417 [ 2 ] |= V_419 ;
if ( memcmp ( V_417 + 2 , V_4 , V_418 - 2 ) != 0 )
return - V_20 ;
V_152 -> V_16 |= V_229 | V_230 ;
V_152 -> V_231 = V_232 ;
V_152 -> V_180 = 0 ;
V_152 -> V_154 = V_407 ;
V_152 -> V_156 = V_419 ? V_420 : V_421 ;
return 0 ;
}
static unsigned int F_166 ( struct V_138 * V_139 )
{
struct V_55 * V_146 = V_139 -> V_140 ;
const T_3 * V_225 = V_146 -> V_226 ;
const T_3 * V_323 ;
T_3 V_325 , V_326 ;
unsigned V_329 , V_422 , V_423 , V_424 ;
int V_45 ;
F_93 ( L_31 ) ;
V_329 = ( V_225 [ 0 ] == V_425 ) ;
if ( V_329 ) {
if ( V_146 -> V_227 < 5 )
goto V_228;
V_45 = V_225 [ 4 ] ;
V_423 = 4 ;
} else {
if ( V_146 -> V_227 < 9 )
goto V_228;
V_45 = ( V_225 [ 7 ] << 8 ) + V_225 [ 8 ] ;
V_423 = 8 ;
}
if ( ( V_225 [ 1 ] & 0x11 ) != 0x10 )
goto V_228;
if ( ! F_54 ( V_146 ) || F_53 ( V_146 ) -> V_426 < V_45 )
goto V_427;
V_323 = F_161 ( F_162 ( F_53 ( V_146 ) ) ) ;
if ( V_45 < V_423 )
goto V_427;
if ( V_329 )
V_424 = V_323 [ 3 ] ;
else
V_424 = ( V_323 [ 6 ] << 8 ) + V_323 [ 7 ] ;
V_45 -= V_423 ;
V_323 += V_423 ;
if ( V_45 < V_424 )
goto V_427;
if ( V_424 != 0 && V_424 != 8 )
goto V_428;
V_45 -= V_424 ;
V_323 += V_424 ;
if ( V_45 == 0 )
goto V_240;
V_325 = V_323 [ 0 ] & 0x3f ;
if ( V_323 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_427;
V_326 = V_323 [ 1 ] ;
V_422 = ( V_323 [ 2 ] << 8 ) | V_323 [ 3 ] ;
V_323 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_427;
V_326 = 0 ;
V_422 = V_323 [ 1 ] ;
V_323 += 2 ;
V_45 -= 2 ;
}
if ( V_326 && ( V_326 != V_333 ) )
goto V_428;
if ( V_422 > V_45 )
goto V_427;
switch ( V_325 ) {
case V_335 :
if ( F_165 ( V_139 , V_323 , V_422 ) < 0 )
goto V_428;
break;
default:
goto V_428;
}
if ( V_45 > V_422 )
goto V_428;
return 0 ;
V_228:
F_22 ( V_146 , V_78 , 0x24 , 0x0 ) ;
return 1 ;
V_428:
F_22 ( V_146 , V_78 , 0x26 , 0x0 ) ;
return 1 ;
V_427:
F_22 ( V_146 , V_78 , 0x1a , 0x0 ) ;
return 1 ;
V_240:
V_146 -> V_60 = V_243 ;
return 1 ;
}
static inline T_9 F_167 ( struct V_12 * V_13 , T_3 V_56 )
{
switch ( V_56 ) {
case V_272 :
case V_270 :
case V_273 :
case V_267 :
case V_266 :
case V_268 :
return F_100 ;
case V_429 :
return F_160 ;
case V_430 :
if ( F_168 ( V_13 ) )
return F_91 ;
break;
case V_253 :
case V_254 :
return F_96 ;
case V_277 :
case V_117 :
return F_158 ;
case V_425 :
case V_431 :
return F_166 ;
break;
case V_432 :
return F_89 ;
}
return NULL ;
}
static inline void F_169 ( struct V_8 * V_9 ,
struct V_55 * V_56 )
{
#ifdef F_170
struct V_28 * V_101 = V_56 -> V_1 ;
T_3 * V_140 = V_56 -> V_226 ;
F_99 ( L_47 ,
V_9 -> V_179 ,
V_101 -> V_365 , V_101 -> V_92 , V_101 -> V_366 ,
V_140 [ 0 ] , V_140 [ 1 ] , V_140 [ 2 ] , V_140 [ 3 ] ,
V_140 [ 4 ] , V_140 [ 5 ] , V_140 [ 6 ] , V_140 [ 7 ] ,
V_140 [ 8 ] ) ;
#endif
}
static inline int F_171 ( struct V_55 * V_146 ,
struct V_12 * V_13 )
{
T_3 V_433 = V_146 -> V_226 [ 0 ] ;
T_9 V_278 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 ) {
if ( F_19 ( ! V_146 -> V_227 || V_146 -> V_227 > V_13 -> V_348 ) )
goto V_434;
V_278 = F_167 ( V_13 , V_433 ) ;
} else {
if ( F_19 ( ! V_146 -> V_227 ) )
goto V_434;
V_278 = NULL ;
if ( F_65 ( ( V_433 != V_117 ) || ! V_435 ) ) {
int V_45 = F_172 ( V_433 ) ;
if ( F_19 ( V_45 > V_146 -> V_227 || V_45 > V_13 -> V_348 ) )
goto V_434;
V_278 = F_151 ;
} else {
if ( F_19 ( V_146 -> V_227 > 16 ) )
goto V_434;
V_278 = F_167 ( V_13 , V_433 ) ;
}
}
if ( V_278 )
V_33 = F_104 ( V_13 , V_146 , V_278 ) ;
else
F_173 ( V_13 , V_146 ) ;
return V_33 ;
V_434:
F_99 ( L_48 ,
V_146 -> V_227 , V_433 , V_13 -> V_348 ) ;
V_146 -> V_60 = V_288 << 16 ;
V_146 -> V_79 ( V_146 ) ;
return 0 ;
}
int F_174 ( struct V_6 * V_7 , struct V_55 * V_56 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_101 = V_56 -> V_1 ;
int V_33 = 0 ;
unsigned long V_436 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_436 ) ;
F_169 ( V_9 , V_56 ) ;
V_13 = F_13 ( V_9 , V_101 ) ;
if ( F_65 ( V_13 ) )
V_33 = F_171 ( V_56 , V_13 ) ;
else {
V_56 -> V_60 = ( V_437 << 16 ) ;
V_56 -> V_79 ( V_56 ) ;
}
F_9 ( V_9 -> V_21 , V_436 ) ;
return V_33 ;
}
void F_173 ( struct V_12 * V_13 , struct V_55 * V_56 )
{
struct V_297 args ;
const T_3 * V_140 = V_56 -> V_226 ;
T_3 V_438 ;
args . V_13 = V_13 ;
args . V_92 = V_13 -> V_92 ;
args . V_56 = V_56 ;
args . V_439 = V_56 -> V_79 ;
switch( V_140 [ 0 ] ) {
case V_440 :
F_30 ( V_56 ) ;
break;
case V_357 :
if ( V_140 [ 1 ] & 2 )
F_30 ( V_56 ) ;
else if ( ( V_140 [ 1 ] & 1 ) == 0 )
F_175 ( & args , F_111 ) ;
else switch ( V_140 [ 2 ] ) {
case 0x00 :
F_175 ( & args , F_113 ) ;
break;
case 0x80 :
F_175 ( & args , F_114 ) ;
break;
case 0x83 :
F_175 ( & args , F_115 ) ;
break;
case 0x89 :
F_175 ( & args , F_117 ) ;
break;
case 0xb0 :
F_175 ( & args , F_119 ) ;
break;
case 0xb1 :
F_175 ( & args , F_125 ) ;
break;
case 0xb2 :
F_175 ( & args , F_128 ) ;
break;
default:
F_30 ( V_56 ) ;
break;
}
break;
case V_331 :
case V_441 :
F_175 ( & args , F_139 ) ;
break;
case V_344 :
F_175 ( & args , F_140 ) ;
break;
case V_442 :
if ( ( V_140 [ 1 ] & 0x1f ) == V_443 )
F_175 ( & args , F_140 ) ;
else
F_30 ( V_56 ) ;
break;
case V_444 :
F_175 ( & args , F_143 ) ;
break;
case V_349 :
F_22 ( V_56 , 0 , 0 , 0 ) ;
V_56 -> V_60 = ( V_61 << 24 ) ;
V_56 -> V_79 ( V_56 ) ;
break;
case V_430 :
case V_445 :
case V_446 :
case V_447 :
case V_448 :
F_175 ( & args , F_129 ) ;
break;
case V_449 :
V_438 = V_140 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_438 == 0x4 ) && ( ! V_140 [ 3 ] ) && ( ! V_140 [ 4 ] ) )
F_175 ( & args , F_129 ) ;
else
F_30 ( V_56 ) ;
break;
default:
F_22 ( V_56 , V_78 , 0x20 , 0x0 ) ;
V_56 -> V_79 ( V_56 ) ;
break;
}
}
int F_176 ( struct V_450 * V_34 , struct V_451 * V_452 )
{
int V_162 , V_33 ;
for ( V_162 = 0 ; V_162 < V_34 -> V_453 ; V_162 ++ ) {
struct V_8 * V_9 = V_34 -> V_454 [ V_162 ] ;
struct V_6 * V_7 ;
V_33 = - V_112 ;
V_7 = F_177 ( V_452 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_455;
V_7 -> V_456 = 1 ;
* (struct V_8 * * ) & V_7 -> V_457 [ 0 ] = V_9 ;
V_9 -> V_458 = V_7 ;
V_7 -> V_459 = V_460 ;
V_7 -> V_461 = V_9 -> V_179 ;
V_7 -> V_462 = 16 ;
V_7 -> V_463 = 1 ;
V_7 -> V_464 = 1 ;
V_7 -> V_465 = 16 ;
V_7 -> V_193 = 1 ;
V_7 -> V_466 = 1 ;
V_33 = F_178 ( V_9 -> V_458 ,
& V_9 -> V_467 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_468;
}
return 0 ;
V_468:
F_179 ( V_34 -> V_454 [ V_162 ] -> V_458 ) ;
V_455:
while ( -- V_162 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_454 [ V_162 ] -> V_458 ;
F_180 ( V_7 ) ;
F_179 ( V_7 ) ;
}
return V_33 ;
}
void F_181 ( struct V_8 * V_9 , int V_469 )
{
int V_470 = 5 ;
struct V_12 * V_471 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_472:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_365 = 0 , V_92 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_182 ( V_11 ) )
V_92 = V_13 -> V_43 ;
else
V_365 = V_11 -> V_473 ;
V_29 = F_183 ( V_9 -> V_458 , V_365 , V_92 , 0 ,
NULL ) ;
if ( ! F_184 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_185 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_474;
}
}
V_474:
if ( ! V_11 )
return;
if ( V_469 ) {
if ( V_13 != V_471 ) {
F_186 ( 100 ) ;
V_471 = V_13 ;
goto V_472;
}
if ( -- V_470 ) {
F_186 ( 100 ) ;
goto V_472;
}
F_187 ( V_9 ,
L_49 ) ;
}
F_188 ( V_475 , & V_9 -> V_476 ,
F_189 ( V_119 ) ) ;
}
int F_190 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_191 ( V_13 -> V_29 , V_477 ) ;
return 1 ;
}
return 0 ;
}
static void F_192 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_193 ( & V_9 -> V_458 -> V_478 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_194 ( V_29 ) == 0 ) {
F_191 ( V_29 , V_477 ) ;
} else {
F_195 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_196 ( & V_9 -> V_458 -> V_478 ) ;
if ( V_29 ) {
F_197 ( V_13 , L_50 ,
F_198 ( & V_29 -> V_479 ) ) ;
F_199 ( V_29 ) ;
F_185 ( V_29 ) ;
}
}
static void F_200 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_480 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_480 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_201 ( V_13 ) )
F_202 ( V_13 ) ;
F_192 ( V_13 ) ;
}
}
void F_203 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_204 ( V_13 -> V_29 , V_211 ,
V_481 ) ;
}
void F_205 ( struct V_482 * V_483 )
{
struct V_8 * V_9 =
F_206 ( V_483 , struct V_8 , V_476 . V_483 ) ;
int V_162 ;
if ( V_9 -> V_39 & V_484 ) {
F_99 ( L_51 ) ;
return;
}
#ifdef F_207
while ( V_485 )
F_186 ( 10 ) ;
#endif
F_99 ( L_31 ) ;
F_193 ( & V_9 -> V_486 ) ;
F_200 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_364 )
for ( V_162 = 0 ; V_162 < V_487 ; V_162 ++ )
F_200 ( & V_9 -> V_364 [ V_162 ] ) ;
F_181 ( V_9 , 0 ) ;
F_196 ( & V_9 -> V_486 ) ;
F_99 ( L_33 ) ;
}
int F_208 ( struct V_6 * V_7 , unsigned int V_365 ,
unsigned int V_92 , unsigned int V_366 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_64 -> V_174 )
return - V_24 ;
if ( V_366 != V_488 && V_366 )
return - V_20 ;
if ( ! F_155 ( V_9 ) ) {
if ( V_365 != V_488 && V_365 )
return - V_20 ;
V_43 = V_92 ;
} else {
if ( V_92 != V_488 && V_92 )
return - V_20 ;
V_43 = V_365 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_488 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_489 * V_490 = & V_11 -> V_51 ;
V_490 -> V_491 |= V_492 ;
V_490 -> V_87 |= V_88 ;
}
} else {
struct V_12 * V_13 = F_154 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_489 * V_490 = & V_13 -> V_11 -> V_51 ;
V_490 -> V_491 |= 1 << V_13 -> V_43 ;
V_490 -> V_87 |= V_88 ;
} else
V_33 = - V_20 ;
}
if ( V_33 == 0 ) {
F_8 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_34 ( V_9 ) ;
} else
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
}
void F_209 ( struct V_482 * V_483 )
{
struct V_8 * V_9 =
F_206 ( V_483 , struct V_8 , V_493 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_193 ( & V_9 -> V_486 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_194 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_210 ( & ( V_29 -> V_479 ) ) ;
F_185 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_196 ( & V_9 -> V_486 ) ;
}
struct V_8 * F_211 ( struct V_450 * V_34 ,
struct V_494 * V_495 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_212 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_496 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_497 = V_495 -> V_497 ;
V_9 -> V_498 = V_495 -> V_498 ;
V_9 -> V_499 = V_495 -> V_499 ;
V_9 -> V_16 |= V_495 -> V_16 ;
V_9 -> V_64 = V_495 -> V_500 ;
V_9 -> V_501 = V_502 ;
return V_9 ;
}
int F_213 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_64 -> V_174 )
V_9 -> V_39 &= ~ V_503 ;
return 0 ;
}
void F_214 ( struct V_8 * V_9 )
{
}
void F_215 ( struct V_8 * V_9 )
{
F_216 ( V_9 ) ;
}
int F_217 ( struct V_8 * V_9 )
{
return F_218 ( V_9 ) ;
}
int F_219 ( struct V_8 * V_9 )
{
int V_33 = V_9 -> V_64 -> V_504 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_179 = F_220 ( & V_505 ) ;
return 0 ;
}
void F_221 ( struct V_8 * V_9 )
{
if ( V_9 -> V_64 -> V_506 )
V_9 -> V_64 -> V_506 ( V_9 ) ;
F_45 ( V_9 ) ;
}
int F_222 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_63 ( V_29 ) ;
F_68 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_223 ( struct V_55 * V_56 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_169 ( V_9 , V_56 ) ;
if ( F_65 ( F_86 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_171 ( V_56 , V_9 -> V_11 . V_1 ) ;
else {
V_56 -> V_60 = ( V_437 << 16 ) ;
V_56 -> V_79 ( V_56 ) ;
}
return V_33 ;
}
