static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
enum V_11 V_12 ;
unsigned long V_13 ;
for ( V_12 = V_14 ;
V_12 < F_4 ( V_15 ) ; V_12 ++ ) {
const char * V_16 = V_15 [ V_12 ] ;
if ( strncmp ( V_16 , V_5 , strlen ( V_16 ) ) == 0 )
break;
}
if ( V_12 == F_4 ( V_15 ) )
return - V_17 ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_10 -> V_19 = V_12 ;
F_6 ( V_10 ) ;
F_7 ( V_10 -> V_18 , V_13 ) ;
return V_6 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
if ( V_10 -> V_19 >= F_4 ( V_15 ) )
return - V_17 ;
return snprintf ( V_5 , V_20 , L_1 ,
V_15 [ V_10 -> V_19 ] ) ;
}
static T_1 F_9 ( struct V_1 * V_1 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_21 * V_22 = F_10 ( V_1 ) ;
struct V_9 * V_10 ;
struct V_23 * V_24 ;
struct V_25 * V_2 ;
unsigned long V_13 , V_26 ;
unsigned int V_27 ( V_28 ) ;
int V_29 = 0 ;
V_10 = F_3 ( V_22 -> V_30 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 = F_11 ( V_10 , V_22 ) ;
if ( ! V_2 ) {
V_29 = - V_31 ;
goto V_32;
}
if ( V_2 -> V_13 & V_33 ) {
V_29 = - V_34 ;
goto V_32;
}
V_24 = V_2 -> V_24 ;
V_26 = V_35 ;
if ( V_10 -> V_36 & V_37 &&
V_24 -> V_38 . V_39 & ( 1 << V_2 -> V_40 ) &&
F_12 ( V_2 -> V_41 , V_26 ) )
V_28 = F_13 ( V_2 -> V_41 - V_26 ) ;
else
V_28 = 0 ;
V_32:
F_14 ( V_10 -> V_18 ) ;
return V_29 ? V_29 : snprintf ( V_5 , 20 , L_2 , V_28 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_42 )
{
struct V_21 * V_22 = F_10 ( V_1 ) ;
struct V_9 * V_10 ;
struct V_25 * V_2 ;
long int V_43 ;
unsigned long V_13 ;
int V_29 ;
V_29 = F_16 ( V_5 , 10 , & V_43 ) ;
if ( V_29 )
return V_29 ;
if ( V_43 < - 2 )
return - V_17 ;
if ( V_43 > V_44 ) {
V_29 = - V_45 ;
V_43 = V_44 ;
}
V_10 = F_3 ( V_22 -> V_30 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 = F_11 ( V_10 , V_22 ) ;
if ( F_17 ( ! V_2 ) ) {
V_29 = - V_31 ;
goto V_32;
}
if ( V_2 -> V_46 != V_47 ) {
V_29 = - V_34 ;
goto V_32;
}
if ( V_43 >= 0 ) {
if ( V_2 -> V_13 & V_33 ) {
V_29 = - V_34 ;
goto V_32;
}
V_2 -> V_41 = F_18 ( V_35 , V_43 ) ;
V_2 -> V_24 -> V_48 . V_49 [ V_2 -> V_40 ] |= V_50 ;
F_6 ( V_10 ) ;
F_19 ( & V_10 -> V_51 ) ;
} else {
switch ( V_43 ) {
case - 1 :
V_2 -> V_13 &= ~ V_33 ;
break;
case - 2 :
V_2 -> V_13 |= V_33 ;
break;
}
}
V_32:
F_7 ( V_10 -> V_18 , V_13 ) ;
return V_29 ? V_29 : V_42 ;
}
static void F_20 ( struct V_52 * V_53 , T_3 V_54 , T_3 V_55 , T_3 V_56 )
{
V_53 -> V_57 = ( V_58 << 24 ) | V_59 ;
F_21 ( 0 , V_53 -> V_60 , V_54 , V_55 , V_56 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
if ( V_10 -> V_61 -> V_62 && ( V_10 -> V_13 & V_63 ) )
return V_10 -> V_61 -> V_62 ( V_10 , V_5 , V_6 ) ;
return - V_17 ;
}
static T_1
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
if ( V_10 -> V_61 -> V_64 && ( V_10 -> V_13 & V_63 ) )
return V_10 -> V_61 -> V_64 ( V_10 , V_5 ) ;
return - V_17 ;
}
static T_1
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return snprintf ( V_5 , 23 , L_3 , V_10 -> V_65 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_25 * V_66 = F_11 ( V_10 , V_22 ) ;
if ( V_66 && V_10 -> V_61 -> V_67 &&
( V_10 -> V_13 & V_68 ) )
return V_10 -> V_61 -> V_67 ( V_66 , V_5 ) ;
return - V_17 ;
}
static T_1
F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_25 * V_66 = F_11 ( V_10 , V_22 ) ;
enum V_69 V_70 ;
int V_29 ;
if ( V_66 && V_10 -> V_61 -> V_71 &&
( V_10 -> V_13 & V_68 ) ) {
V_70 = F_27 ( V_5 , NULL , 0 ) ;
switch ( V_70 ) {
case V_72 : case V_73 : case V_74 :
V_29 = V_10 -> V_61 -> V_71 ( V_66 , V_70 ) ;
if ( ! V_29 )
return V_6 ;
else
return V_29 ;
}
}
return - V_17 ;
}
static void F_28 ( struct V_52 * V_53 )
{
F_20 ( V_53 , V_75 , 0x24 , 0x0 ) ;
V_53 -> V_76 ( V_53 ) ;
}
int F_29 ( struct V_21 * V_22 , struct V_77 * V_78 ,
T_4 V_79 , int V_80 [] )
{
V_80 [ 0 ] = 255 ;
V_80 [ 1 ] = 63 ;
F_30 ( V_79 , 255 * 63 ) ;
V_80 [ 2 ] = V_79 ;
return 0 ;
}
void F_31 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_25 * V_2 ;
unsigned long V_13 ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 = F_11 ( V_10 , V_22 ) ;
if ( V_2 && V_2 -> V_81 < V_2 -> V_82 ) {
V_2 -> V_13 |= V_83 ;
V_2 -> V_24 -> V_48 . V_84 |= V_85 ;
F_6 ( V_10 ) ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_32 ( V_10 ) ;
}
static int F_33 ( struct V_9 * V_10 , struct V_21 * V_22 ,
void T_5 * V_86 )
{
struct V_25 * V_2 = F_11 ( V_10 , V_22 ) ;
T_6 T_5 * V_87 = V_86 ;
char V_5 [ 40 ] ;
if ( ! V_2 )
return - V_88 ;
if ( F_34 ( V_87 , V_2 -> V_89 , V_90 * sizeof( T_6 ) ) )
return - V_91 ;
F_35 ( V_2 -> V_89 , V_5 , V_92 , V_93 ) ;
if ( F_34 ( V_87 + V_92 , V_5 , V_93 ) )
return - V_91 ;
F_35 ( V_2 -> V_89 , V_5 , V_94 , V_95 ) ;
if ( F_34 ( V_87 + V_94 , V_5 , V_95 ) )
return - V_91 ;
F_35 ( V_2 -> V_89 , V_5 , V_96 , V_97 ) ;
if ( F_34 ( V_87 + V_96 , V_5 , V_97 ) )
return - V_91 ;
return 0 ;
}
int F_36 ( struct V_21 * V_98 , void T_5 * V_86 )
{
int V_29 = 0 ;
T_3 V_99 [ V_100 ] ;
T_3 args [ 4 ] , * V_101 = NULL , * V_102 = NULL ;
int V_103 = 0 ;
enum V_104 V_105 ;
int V_106 ;
if ( V_86 == NULL )
return - V_17 ;
if ( F_37 ( args , V_86 , sizeof( args ) ) )
return - V_91 ;
V_102 = F_38 ( V_107 , V_108 ) ;
if ( ! V_102 )
return - V_109 ;
memset ( V_99 , 0 , sizeof( V_99 ) ) ;
if ( args [ 3 ] ) {
V_103 = V_110 * args [ 3 ] ;
V_101 = F_39 ( V_103 , V_111 ) ;
if ( V_101 == NULL ) {
V_29 = - V_109 ;
goto error;
}
V_99 [ 1 ] = ( 4 << 1 ) ;
V_99 [ 2 ] = 0x0e ;
V_105 = V_112 ;
} else {
V_99 [ 1 ] = ( 3 << 1 ) ;
V_99 [ 2 ] = 0x20 ;
V_105 = V_113 ;
}
V_99 [ 0 ] = V_114 ;
V_99 [ 4 ] = args [ 2 ] ;
if ( args [ 0 ] == V_115 ) {
V_99 [ 6 ] = args [ 3 ] ;
V_99 [ 8 ] = args [ 1 ] ;
V_99 [ 10 ] = 0x4f ;
V_99 [ 12 ] = 0xc2 ;
} else {
V_99 [ 6 ] = args [ 1 ] ;
}
V_99 [ 14 ] = args [ 0 ] ;
V_106 = F_40 ( V_98 , V_99 , V_105 , V_101 , V_103 ,
V_102 , ( 10 * V_116 ) , 5 , 0 , NULL ) ;
if ( F_41 ( V_106 ) == V_58 ) {
T_3 * V_117 = V_102 + 8 ;
V_106 &= ~ ( 0xFF << 24 ) ;
if ( V_106 & V_59 ) {
struct V_118 V_119 ;
F_42 ( V_102 , V_107 ,
& V_119 ) ;
if ( V_119 . V_120 == V_121 &&
V_119 . V_55 == 0 && V_119 . V_56 == 0x1d )
V_106 &= ~ V_59 ;
}
if ( V_102 [ 0 ] == 0x72 &&
V_117 [ 0 ] == 0x09 ) {
args [ 0 ] = V_117 [ 13 ] ;
args [ 1 ] = V_117 [ 3 ] ;
args [ 2 ] = V_117 [ 5 ] ;
if ( F_34 ( V_86 , args , sizeof( args ) ) )
V_29 = - V_91 ;
}
}
if ( V_106 ) {
V_29 = - V_122 ;
goto error;
}
if ( ( V_101 )
&& F_34 ( V_86 + sizeof( args ) , V_101 , V_103 ) )
V_29 = - V_91 ;
error:
F_43 ( V_102 ) ;
F_43 ( V_101 ) ;
return V_29 ;
}
int F_44 ( struct V_21 * V_98 , void T_5 * V_86 )
{
int V_29 = 0 ;
T_3 V_99 [ V_100 ] ;
T_3 args [ 7 ] , * V_102 = NULL ;
int V_106 ;
if ( V_86 == NULL )
return - V_17 ;
if ( F_37 ( args , V_86 , sizeof( args ) ) )
return - V_91 ;
V_102 = F_38 ( V_107 , V_108 ) ;
if ( ! V_102 )
return - V_109 ;
memset ( V_99 , 0 , sizeof( V_99 ) ) ;
V_99 [ 0 ] = V_114 ;
V_99 [ 1 ] = ( 3 << 1 ) ;
V_99 [ 2 ] = 0x20 ;
V_99 [ 4 ] = args [ 1 ] ;
V_99 [ 6 ] = args [ 2 ] ;
V_99 [ 8 ] = args [ 3 ] ;
V_99 [ 10 ] = args [ 4 ] ;
V_99 [ 12 ] = args [ 5 ] ;
V_99 [ 13 ] = args [ 6 ] & 0x4f ;
V_99 [ 14 ] = args [ 0 ] ;
V_106 = F_40 ( V_98 , V_99 , V_113 , NULL , 0 ,
V_102 , ( 10 * V_116 ) , 5 , 0 , NULL ) ;
if ( F_41 ( V_106 ) == V_58 ) {
T_3 * V_117 = V_102 + 8 ;
V_106 &= ~ ( 0xFF << 24 ) ;
if ( V_106 & V_59 ) {
struct V_118 V_119 ;
F_42 ( V_102 , V_107 ,
& V_119 ) ;
if ( V_119 . V_120 == V_121 &&
V_119 . V_55 == 0 && V_119 . V_56 == 0x1d )
V_106 &= ~ V_59 ;
}
if ( V_102 [ 0 ] == 0x72 &&
V_117 [ 0 ] == 0x09 ) {
args [ 0 ] = V_117 [ 13 ] ;
args [ 1 ] = V_117 [ 3 ] ;
args [ 2 ] = V_117 [ 5 ] ;
args [ 3 ] = V_117 [ 7 ] ;
args [ 4 ] = V_117 [ 9 ] ;
args [ 5 ] = V_117 [ 11 ] ;
args [ 6 ] = V_117 [ 12 ] ;
if ( F_34 ( V_86 , args , sizeof( args ) ) )
V_29 = - V_91 ;
}
}
if ( V_106 ) {
V_29 = - V_122 ;
goto error;
}
error:
F_43 ( V_102 ) ;
return V_29 ;
}
static int F_45 ( struct V_9 * V_10 )
{
if ( V_10 -> V_13 & V_123 )
return 1 ;
if ( V_10 -> V_36 & V_124 )
return 1 ;
return 0 ;
}
int F_46 ( struct V_9 * V_10 , struct V_21 * V_98 ,
int V_53 , void T_5 * V_86 )
{
int V_70 = - V_17 , V_29 = - V_17 ;
unsigned long V_13 ;
switch ( V_53 ) {
case V_125 :
F_5 ( V_10 -> V_18 , V_13 ) ;
V_70 = F_45 ( V_10 ) ;
F_7 ( V_10 -> V_18 , V_13 ) ;
if ( F_34 ( V_86 , & V_70 , 1 ) )
return - V_91 ;
return 0 ;
case V_126 :
V_70 = ( unsigned long ) V_86 ;
V_29 = 0 ;
F_5 ( V_10 -> V_18 , V_13 ) ;
if ( V_10 -> V_36 & V_127 ) {
if ( V_70 )
V_10 -> V_36 |= V_124 ;
else
V_10 -> V_36 &= ~ V_124 ;
} else {
if ( V_70 != F_45 ( V_10 ) )
V_29 = - V_17 ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
return V_29 ;
case V_128 :
return F_33 ( V_10 , V_98 , V_86 ) ;
case V_129 :
if ( ! F_47 ( V_130 ) || ! F_47 ( V_131 ) )
return - V_132 ;
return F_36 ( V_98 , V_86 ) ;
case V_133 :
if ( ! F_47 ( V_130 ) || ! F_47 ( V_131 ) )
return - V_132 ;
return F_44 ( V_98 , V_86 ) ;
default:
V_29 = - V_134 ;
break;
}
return V_29 ;
}
int F_48 ( struct V_21 * V_98 , int V_53 , void T_5 * V_86 )
{
return F_46 ( F_3 ( V_98 -> V_30 ) ,
V_98 , V_53 , V_86 ) ;
}
static struct V_135 * F_49 ( struct V_25 * V_2 ,
struct V_52 * V_53 )
{
struct V_135 * V_136 ;
V_136 = F_50 ( V_2 ) ;
if ( V_136 ) {
V_136 -> V_137 = V_53 ;
V_136 -> V_138 = V_53 -> V_76 ;
V_136 -> V_139 = F_51 ( V_53 ) ;
V_136 -> V_140 = F_52 ( V_53 ) ;
} else {
V_53 -> V_57 = ( V_141 << 16 ) | ( V_142 << 1 ) ;
V_53 -> V_76 ( V_53 ) ;
}
return V_136 ;
}
static void F_53 ( struct V_135 * V_136 )
{
struct V_52 * V_143 = V_136 -> V_137 ;
V_136 -> V_144 = V_143 -> V_145 -> V_146 ;
V_136 -> V_147 = F_54 ( V_143 ) + V_136 -> V_144 ;
}
static void F_55 ( unsigned V_89 , struct V_148 * V_149 )
{
T_3 V_150 = V_149 -> V_151 , V_152 = V_149 -> V_153 ;
F_56 ( V_154 L_4 , V_89 , V_150 ) ;
if ( V_150 & V_155 ) {
F_56 ( L_5 ) ;
} else {
if ( V_150 & 0x40 ) F_56 ( L_6 ) ;
if ( V_150 & 0x20 ) F_56 ( L_7 ) ;
if ( V_150 & 0x10 ) F_56 ( L_8 ) ;
if ( V_150 & 0x08 ) F_56 ( L_9 ) ;
if ( V_150 & 0x04 ) F_56 ( L_10 ) ;
if ( V_150 & 0x02 ) F_56 ( L_11 ) ;
if ( V_150 & 0x01 ) F_56 ( L_12 ) ;
F_56 ( L_13 ) ;
if ( V_152 ) {
F_56 ( V_154 L_14 , V_89 , V_152 ) ;
if ( V_152 & 0x04 ) F_56 ( L_15 ) ;
if ( V_152 & 0x80 ) {
if ( V_152 & 0x04 ) F_56 ( L_16 ) ;
else F_56 ( L_17 ) ;
}
if ( V_152 & 0x40 ) F_56 ( L_18 ) ;
if ( V_152 & 0x10 ) F_56 ( L_19 ) ;
if ( V_152 & 0x02 ) F_56 ( L_20 ) ;
if ( V_152 & 0x01 ) F_56 ( L_21 ) ;
F_56 ( L_13 ) ;
}
}
}
static void F_57 ( unsigned V_89 , T_3 V_156 , T_3 V_157 , T_3 * V_54 ,
T_3 * V_55 , T_3 * V_56 , int V_158 )
{
int V_159 ;
static const unsigned char V_160 [] [ 4 ] = {
{ 0xd1 , V_161 , 0x00 , 0x00 } ,
{ 0xd0 , V_161 , 0x00 , 0x00 } ,
{ 0x61 , V_162 , 0x00 , 0x00 } ,
{ 0x84 , V_161 , 0x47 , 0x00 } ,
{ 0x37 , V_163 , 0x04 , 0x00 } ,
{ 0x09 , V_163 , 0x04 , 0x00 } ,
{ 0x01 , V_164 , 0x13 , 0x00 } ,
{ 0x02 , V_162 , 0x00 , 0x00 } ,
{ 0x08 , V_163 , 0x04 , 0x00 } ,
{ 0x10 , V_75 , 0x21 , 0x00 } ,
{ 0x20 , V_165 , 0x28 , 0x00 } ,
{ 0x40 , V_164 , 0x11 , 0x04 } ,
{ 0x80 , V_164 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_166 [] [ 4 ] = {
{ 0x80 , V_161 , 0x47 , 0x00 } ,
{ 0x20 , V_162 , 0x44 , 0x00 } ,
{ 0x08 , V_161 , 0x47 , 0x00 } ,
{ 0x04 , V_121 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_156 & V_155 ) {
V_157 = 0 ;
}
if ( V_157 ) {
for ( V_159 = 0 ; V_160 [ V_159 ] [ 0 ] != 0xFF ; V_159 ++ ) {
if ( ( V_160 [ V_159 ] [ 0 ] & V_157 ) ==
V_160 [ V_159 ] [ 0 ] ) {
* V_54 = V_160 [ V_159 ] [ 1 ] ;
* V_55 = V_160 [ V_159 ] [ 2 ] ;
* V_56 = V_160 [ V_159 ] [ 3 ] ;
goto V_167;
}
}
}
for ( V_159 = 0 ; V_166 [ V_159 ] [ 0 ] != 0xFF ; V_159 ++ ) {
if ( V_166 [ V_159 ] [ 0 ] & V_156 ) {
* V_54 = V_166 [ V_159 ] [ 1 ] ;
* V_55 = V_166 [ V_159 ] [ 2 ] ;
* V_56 = V_166 [ V_159 ] [ 3 ] ;
goto V_167;
}
}
* V_54 = V_161 ;
* V_55 = 0x00 ;
* V_56 = 0x00 ;
V_167:
if ( V_158 )
F_56 ( V_168 L_22
L_23 ,
V_89 , V_156 , V_157 , * V_54 , * V_55 , * V_56 ) ;
return;
}
static void F_58 ( struct V_135 * V_136 )
{
struct V_52 * V_53 = V_136 -> V_137 ;
struct V_148 * V_149 = & V_136 -> V_169 ;
unsigned char * V_170 = V_53 -> V_60 ;
unsigned char * V_117 = V_170 + 8 ;
int V_158 = V_136 -> V_10 -> V_61 -> V_171 == NULL ;
memset ( V_170 , 0 , V_107 ) ;
V_53 -> V_57 = ( V_58 << 24 ) | V_59 ;
if ( V_136 -> V_172 ||
V_149 -> V_151 & ( V_155 | V_173 | V_174 | V_175 ) ) {
F_57 ( V_136 -> V_10 -> V_176 , V_149 -> V_151 , V_149 -> V_153 ,
& V_170 [ 1 ] , & V_170 [ 2 ] , & V_170 [ 3 ] , V_158 ) ;
V_170 [ 1 ] &= 0x0f ;
} else {
V_170 [ 1 ] = V_121 ;
V_170 [ 2 ] = 0 ;
V_170 [ 3 ] = 0x1D ;
}
V_170 [ 0 ] = 0x72 ;
V_117 [ 0 ] = 0x09 ;
V_170 [ 7 ] = 14 ;
V_117 [ 1 ] = 12 ;
V_117 [ 2 ] = 0x00 ;
V_117 [ 3 ] = V_149 -> V_153 ;
V_117 [ 5 ] = V_149 -> V_177 ;
V_117 [ 7 ] = V_149 -> V_178 ;
V_117 [ 9 ] = V_149 -> V_179 ;
V_117 [ 11 ] = V_149 -> V_180 ;
V_117 [ 12 ] = V_149 -> V_1 ;
V_117 [ 13 ] = V_149 -> V_151 ;
if ( V_149 -> V_13 & V_181 ) {
V_117 [ 2 ] |= 0x01 ;
V_117 [ 4 ] = V_149 -> V_182 ;
V_117 [ 6 ] = V_149 -> V_183 ;
V_117 [ 8 ] = V_149 -> V_184 ;
V_117 [ 10 ] = V_149 -> V_185 ;
}
}
static void F_59 ( struct V_135 * V_136 )
{
struct V_25 * V_2 = V_136 -> V_2 ;
struct V_52 * V_53 = V_136 -> V_137 ;
struct V_148 * V_149 = & V_136 -> V_169 ;
unsigned char * V_170 = V_53 -> V_60 ;
unsigned char * V_117 = V_170 + 8 ;
int V_158 = V_136 -> V_10 -> V_61 -> V_171 == NULL ;
T_7 V_186 ;
memset ( V_170 , 0 , V_107 ) ;
V_53 -> V_57 = ( V_58 << 24 ) | V_59 ;
V_170 [ 0 ] = 0x72 ;
if ( V_136 -> V_172 ||
V_149 -> V_151 & ( V_155 | V_173 | V_174 | V_175 ) ) {
F_57 ( V_136 -> V_10 -> V_176 , V_149 -> V_151 , V_149 -> V_153 ,
& V_170 [ 1 ] , & V_170 [ 2 ] , & V_170 [ 3 ] , V_158 ) ;
V_170 [ 1 ] &= 0x0f ;
}
V_186 = F_60 ( & V_136 -> V_169 , V_2 ) ;
V_170 [ 7 ] = 12 ;
V_117 [ 0 ] = 0x00 ;
V_117 [ 1 ] = 10 ;
V_117 [ 2 ] |= 0x80 ;
V_117 [ 6 ] = V_186 >> 40 ;
V_117 [ 7 ] = V_186 >> 32 ;
V_117 [ 8 ] = V_186 >> 24 ;
V_117 [ 9 ] = V_186 >> 16 ;
V_117 [ 10 ] = V_186 >> 8 ;
V_117 [ 11 ] = V_186 ;
}
static void F_61 ( struct V_21 * V_22 )
{
V_22 -> V_187 = 1 ;
V_22 -> V_188 = 1 ;
V_22 -> V_189 = 1 ;
V_22 -> V_190 = 1 ;
V_22 -> V_191 = 1 ;
}
static int F_62 ( struct V_145 * V_192 )
{
if ( F_63 ( V_192 -> V_193 != V_194 ) )
return 0 ;
if ( ! F_64 ( V_192 ) || ( V_192 -> V_195 & V_196 ) )
return 0 ;
return F_65 ( V_192 -> V_53 [ 0 ] ) == V_197 ;
}
static int F_66 ( struct V_21 * V_22 ,
struct V_25 * V_2 )
{
struct V_198 * V_199 = V_22 -> V_198 ;
if ( ! F_67 ( V_2 -> V_89 ) )
V_2 -> V_13 |= V_33 ;
F_68 ( V_199 , V_2 -> V_200 ) ;
if ( V_2 -> V_46 == V_201 ) {
void * V_5 ;
V_22 -> V_202 = V_110 ;
F_69 ( V_199 , V_203 - 1 ) ;
V_5 = F_39 ( V_204 , V_199 -> V_205 | V_111 ) ;
if ( ! V_5 ) {
F_70 ( V_2 , L_24 ) ;
return - V_109 ;
}
F_71 ( V_199 , F_62 , V_5 , V_204 ) ;
} else {
V_22 -> V_202 = F_72 ( V_2 -> V_89 ) ;
V_22 -> V_206 = 1 ;
}
if ( V_22 -> V_202 > V_20 )
F_73 ( V_2 ,
L_25 ,
V_22 -> V_202 ) ;
F_74 ( V_199 , V_22 -> V_202 - 1 ) ;
if ( V_2 -> V_13 & V_207 )
F_75 ( V_208 , V_22 -> V_209 ) ;
if ( V_2 -> V_13 & V_210 ) {
int V_211 ;
V_211 = F_76 ( V_22 -> V_30 -> V_212 , F_77 ( V_2 -> V_89 ) ) ;
V_211 = F_76 ( V_213 - 1 , V_211 ) ;
F_78 ( V_22 , V_214 , V_211 ) ;
}
F_79 ( V_199 , false ) ;
V_2 -> V_22 = V_22 ;
return 0 ;
}
int F_80 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_25 * V_2 = F_81 ( V_10 , V_22 ) ;
int V_29 = 0 ;
F_61 ( V_22 ) ;
if ( V_2 )
V_29 = F_66 ( V_22 , V_2 ) ;
return V_29 ;
}
void F_82 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_198 * V_199 = V_22 -> V_198 ;
unsigned long V_13 ;
struct V_25 * V_2 ;
if ( ! V_10 -> V_61 -> V_171 )
return;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 = F_81 ( V_10 , V_22 ) ;
if ( V_2 && V_2 -> V_22 ) {
V_2 -> V_22 = NULL ;
V_2 -> V_13 |= V_215 ;
F_6 ( V_10 ) ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_43 ( V_199 -> V_216 ) ;
V_199 -> V_216 = NULL ;
V_199 -> V_217 = 0 ;
}
int F_83 ( struct V_9 * V_10 , struct V_21 * V_22 ,
int V_218 , int V_219 )
{
struct V_25 * V_2 ;
unsigned long V_13 ;
if ( V_219 != V_220 )
return - V_34 ;
if ( V_218 < 1 || V_218 == V_22 -> V_218 )
return V_22 -> V_218 ;
V_2 = F_11 ( V_10 , V_22 ) ;
if ( ! V_2 || ! F_84 ( V_2 ) )
return V_22 -> V_218 ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 -> V_13 &= ~ V_221 ;
if ( V_218 == 1 || ! F_85 ( V_2 ) ) {
V_2 -> V_13 |= V_221 ;
V_218 = 1 ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
V_218 = F_76 ( V_218 , V_22 -> V_30 -> V_212 ) ;
V_218 = F_76 ( V_218 , F_77 ( V_2 -> V_89 ) ) ;
V_218 = F_76 ( V_218 , V_213 - 1 ) ;
if ( V_22 -> V_218 == V_218 )
return - V_17 ;
F_78 ( V_22 , V_214 , V_218 ) ;
return V_218 ;
}
int F_86 ( struct V_21 * V_22 , int V_218 ,
int V_219 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
return F_83 ( V_10 , V_22 , V_218 , V_219 ) ;
}
static unsigned int F_87 ( struct V_135 * V_136 )
{
struct V_52 * V_143 = V_136 -> V_137 ;
struct V_148 * V_149 = & V_136 -> V_149 ;
const T_3 * V_222 = V_143 -> V_223 ;
if ( V_143 -> V_224 < 5 )
goto V_225;
V_149 -> V_13 |= V_226 | V_227 ;
V_149 -> V_228 = V_229 ;
if ( V_222 [ 1 ] & 0x1 ) {
;
}
if ( V_222 [ 4 ] & 0x2 )
goto V_225;
if ( ( ( V_222 [ 4 ] >> 4 ) & 0xf ) != 0 )
goto V_225;
if ( V_222 [ 4 ] & 0x1 ) {
V_149 -> V_177 = 1 ;
if ( V_136 -> V_2 -> V_13 & V_230 ) {
V_149 -> V_13 |= V_231 ;
V_149 -> V_180 = 0x0 ;
V_149 -> V_179 = 0x0 ;
V_149 -> V_178 = 0x0 ;
V_149 -> V_1 |= V_232 ;
} else {
V_149 -> V_178 = 0x1 ;
V_149 -> V_179 = 0x0 ;
V_149 -> V_180 = 0x0 ;
}
V_149 -> V_151 = V_233 ;
} else {
if ( ( V_136 -> V_10 -> V_13 & V_234 ) &&
V_235 == V_236 )
goto V_237;
if ( ( V_136 -> V_10 -> V_13 & V_238 ) &&
F_88 () )
goto V_237;
V_149 -> V_151 = V_239 ;
}
return 0 ;
V_225:
F_20 ( V_143 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_237:
V_143 -> V_57 = V_240 ;
return 1 ;
}
static unsigned int F_89 ( struct V_135 * V_136 )
{
struct V_148 * V_149 = & V_136 -> V_149 ;
V_149 -> V_13 |= V_226 ;
V_149 -> V_228 = V_229 ;
if ( V_136 -> V_2 -> V_13 & V_241 )
V_149 -> V_151 = V_242 ;
else
V_149 -> V_151 = V_243 ;
V_136 -> V_13 |= V_244 ;
return 0 ;
}
static void F_90 ( const T_3 * V_222 , T_7 * V_245 , T_8 * V_246 )
{
T_7 V_247 = 0 ;
T_8 V_42 ;
F_91 ( L_26 ) ;
V_247 |= ( ( T_7 ) ( V_222 [ 1 ] & 0x1f ) ) << 16 ;
V_247 |= ( ( T_7 ) V_222 [ 2 ] ) << 8 ;
V_247 |= ( ( T_7 ) V_222 [ 3 ] ) ;
V_42 = V_222 [ 4 ] ;
* V_245 = V_247 ;
* V_246 = V_42 ;
}
static void F_92 ( const T_3 * V_222 , T_7 * V_245 , T_8 * V_246 )
{
T_7 V_247 = 0 ;
T_8 V_42 = 0 ;
F_91 ( L_27 ) ;
V_247 |= ( ( T_7 ) V_222 [ 2 ] ) << 24 ;
V_247 |= ( ( T_7 ) V_222 [ 3 ] ) << 16 ;
V_247 |= ( ( T_7 ) V_222 [ 4 ] ) << 8 ;
V_247 |= ( ( T_7 ) V_222 [ 5 ] ) ;
V_42 |= ( ( T_8 ) V_222 [ 7 ] ) << 8 ;
V_42 |= ( ( T_8 ) V_222 [ 8 ] ) ;
* V_245 = V_247 ;
* V_246 = V_42 ;
}
static void F_93 ( const T_3 * V_222 , T_7 * V_245 , T_8 * V_246 )
{
T_7 V_247 = 0 ;
T_8 V_42 = 0 ;
F_91 ( L_28 ) ;
V_247 |= ( ( T_7 ) V_222 [ 2 ] ) << 56 ;
V_247 |= ( ( T_7 ) V_222 [ 3 ] ) << 48 ;
V_247 |= ( ( T_7 ) V_222 [ 4 ] ) << 40 ;
V_247 |= ( ( T_7 ) V_222 [ 5 ] ) << 32 ;
V_247 |= ( ( T_7 ) V_222 [ 6 ] ) << 24 ;
V_247 |= ( ( T_7 ) V_222 [ 7 ] ) << 16 ;
V_247 |= ( ( T_7 ) V_222 [ 8 ] ) << 8 ;
V_247 |= ( ( T_7 ) V_222 [ 9 ] ) ;
V_42 |= ( ( T_8 ) V_222 [ 10 ] ) << 24 ;
V_42 |= ( ( T_8 ) V_222 [ 11 ] ) << 16 ;
V_42 |= ( ( T_8 ) V_222 [ 12 ] ) << 8 ;
V_42 |= ( ( T_8 ) V_222 [ 13 ] ) ;
* V_245 = V_247 ;
* V_246 = V_42 ;
}
static unsigned int F_94 ( struct V_135 * V_136 )
{
struct V_52 * V_143 = V_136 -> V_137 ;
struct V_148 * V_149 = & V_136 -> V_149 ;
struct V_25 * V_2 = V_136 -> V_2 ;
T_7 V_248 = V_136 -> V_2 -> V_81 ;
const T_3 * V_222 = V_143 -> V_223 ;
T_7 V_186 ;
T_8 V_249 ;
V_149 -> V_13 |= V_227 | V_226 ;
V_149 -> V_228 = V_229 ;
if ( V_222 [ 0 ] == V_250 ) {
if ( V_143 -> V_224 < 10 )
goto V_225;
F_92 ( V_222 , & V_186 , & V_249 ) ;
} else if ( V_222 [ 0 ] == V_251 ) {
if ( V_143 -> V_224 < 16 )
goto V_225;
F_93 ( V_222 , & V_186 , & V_249 ) ;
} else
goto V_225;
if ( ! V_249 )
goto V_252;
if ( V_186 >= V_248 )
goto V_253;
if ( ( V_186 + V_249 ) > V_248 )
goto V_253;
if ( V_2 -> V_13 & V_230 ) {
V_149 -> V_13 |= V_231 ;
if ( F_95 ( V_186 , V_249 ) ) {
V_149 -> V_151 = V_233 ;
V_149 -> V_1 |= ( V_186 >> 24 ) & 0xf ;
} else if ( F_96 ( V_186 , V_249 ) ) {
if ( ! ( V_2 -> V_13 & V_254 ) )
goto V_253;
V_149 -> V_13 |= V_181 ;
V_149 -> V_151 = V_255 ;
V_149 -> V_182 = ( V_249 >> 8 ) & 0xff ;
V_149 -> V_185 = ( V_186 >> 40 ) & 0xff ;
V_149 -> V_184 = ( V_186 >> 32 ) & 0xff ;
V_149 -> V_183 = ( V_186 >> 24 ) & 0xff ;
} else
goto V_253;
V_149 -> V_177 = V_249 & 0xff ;
V_149 -> V_180 = ( V_186 >> 16 ) & 0xff ;
V_149 -> V_179 = ( V_186 >> 8 ) & 0xff ;
V_149 -> V_178 = V_186 & 0xff ;
V_149 -> V_1 |= V_232 ;
} else {
T_8 V_256 , V_257 , V_258 , V_259 ;
if ( ! F_95 ( V_186 , V_249 ) )
goto V_253;
V_259 = ( T_8 ) V_186 / V_2 -> V_260 ;
V_258 = V_259 / V_2 -> V_261 ;
V_257 = V_259 % V_2 -> V_261 ;
V_256 = ( T_8 ) V_186 % V_2 -> V_260 + 1 ;
F_97 ( L_29 ,
( T_8 ) V_186 , V_259 , V_258 , V_257 , V_256 ) ;
if ( ( V_258 >> 16 ) || ( V_257 >> 4 ) || ( V_256 >> 8 ) || ( ! V_256 ) )
goto V_253;
V_149 -> V_151 = V_233 ;
V_149 -> V_177 = V_249 & 0xff ;
V_149 -> V_178 = V_256 ;
V_149 -> V_179 = V_258 ;
V_149 -> V_180 = V_258 >> 8 ;
V_149 -> V_1 |= V_257 ;
}
return 0 ;
V_225:
F_20 ( V_143 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_253:
F_20 ( V_143 , V_75 , 0x21 , 0x0 ) ;
return 1 ;
V_252:
V_143 -> V_57 = V_240 ;
return 1 ;
}
static unsigned int F_98 ( struct V_135 * V_136 )
{
struct V_52 * V_143 = V_136 -> V_137 ;
const T_3 * V_222 = V_143 -> V_223 ;
unsigned int V_262 = 0 ;
T_7 V_186 ;
T_8 V_249 ;
int V_29 ;
if ( V_222 [ 0 ] == V_263 || V_222 [ 0 ] == V_264 || V_222 [ 0 ] == V_265 )
V_262 |= V_266 ;
switch ( V_222 [ 0 ] ) {
case V_267 :
case V_263 :
if ( F_17 ( V_143 -> V_224 < 10 ) )
goto V_225;
F_92 ( V_222 , & V_186 , & V_249 ) ;
if ( V_222 [ 1 ] & ( 1 << 3 ) )
V_262 |= V_268 ;
break;
case V_269 :
case V_264 :
if ( F_17 ( V_143 -> V_224 < 6 ) )
goto V_225;
F_90 ( V_222 , & V_186 , & V_249 ) ;
if ( ! V_249 )
V_249 = 256 ;
break;
case V_270 :
case V_265 :
if ( F_17 ( V_143 -> V_224 < 16 ) )
goto V_225;
F_93 ( V_222 , & V_186 , & V_249 ) ;
if ( V_222 [ 1 ] & ( 1 << 3 ) )
V_262 |= V_268 ;
break;
default:
F_97 ( L_30 ) ;
goto V_225;
}
if ( ! V_249 )
goto V_252;
V_136 -> V_13 |= V_244 ;
V_136 -> V_147 = V_249 * V_143 -> V_1 -> V_202 ;
V_29 = F_99 ( & V_136 -> V_149 , V_136 -> V_2 , V_186 , V_249 , V_262 ,
V_136 -> V_271 ) ;
if ( F_63 ( V_29 == 0 ) )
return 0 ;
if ( V_29 == - V_272 )
goto V_253;
V_225:
F_20 ( V_143 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_253:
F_20 ( V_143 , V_75 , 0x21 , 0x0 ) ;
return 1 ;
V_252:
V_143 -> V_57 = V_240 ;
return 1 ;
}
static void F_100 ( struct V_135 * V_136 )
{
struct V_9 * V_10 = V_136 -> V_10 ;
struct V_52 * V_53 = V_136 -> V_137 ;
T_3 * V_222 = V_53 -> V_223 ;
int V_273 = ( V_136 -> V_172 != 0 ) ;
if ( ( ( V_222 [ 0 ] == V_114 ) || ( V_222 [ 0 ] == V_274 ) ) &&
( ( V_222 [ 2 ] & 0x20 ) || V_273 ) ) {
F_58 ( V_136 ) ;
} else {
if ( ! V_273 ) {
V_53 -> V_57 = V_240 ;
} else {
F_59 ( V_136 ) ;
}
}
if ( V_273 && ! V_10 -> V_61 -> V_171 )
F_55 ( V_10 -> V_176 , & V_136 -> V_169 ) ;
V_136 -> V_138 ( V_53 ) ;
F_101 ( V_136 ) ;
}
static int F_102 ( struct V_25 * V_2 , struct V_52 * V_53 ,
T_9 V_275 )
{
struct V_9 * V_10 = V_2 -> V_24 -> V_10 ;
struct V_135 * V_136 ;
int V_29 ;
F_91 ( L_31 ) ;
V_136 = F_49 ( V_2 , V_53 ) ;
if ( ! V_136 )
goto V_276;
if ( V_53 -> V_277 == V_112 ||
V_53 -> V_277 == V_278 ) {
if ( F_17 ( F_54 ( V_53 ) < 1 ) ) {
F_73 ( V_2 , L_32 ) ;
goto V_279;
}
F_103 ( V_136 , F_51 ( V_53 ) , F_52 ( V_53 ) ) ;
V_136 -> V_280 = V_53 -> V_277 ;
}
V_136 -> V_281 = F_100 ;
if ( V_275 ( V_136 ) )
goto V_282;
if ( V_10 -> V_61 -> V_283 ) {
if ( ( V_29 = V_10 -> V_61 -> V_283 ( V_136 ) ) )
goto V_284;
}
F_104 ( V_136 ) ;
F_91 ( L_33 ) ;
return 0 ;
V_282:
F_101 ( V_136 ) ;
V_53 -> V_76 ( V_53 ) ;
F_97 ( L_34 ) ;
return 0 ;
V_279:
F_101 ( V_136 ) ;
V_53 -> V_57 = ( V_285 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
V_276:
F_97 ( L_35 ) ;
return 0 ;
V_284:
F_101 ( V_136 ) ;
F_97 ( L_36 ) ;
if ( V_29 == V_286 )
return V_287 ;
else
return V_288 ;
}
static void * F_105 ( struct V_52 * V_53 , bool V_289 ,
unsigned long * V_13 )
{
F_5 ( & V_290 , * V_13 ) ;
memset ( V_291 , 0 , V_292 ) ;
if ( V_289 )
F_106 ( F_51 ( V_53 ) , F_52 ( V_53 ) ,
V_291 , V_292 ) ;
return V_291 ;
}
static inline void F_107 ( struct V_52 * V_53 , bool V_293 ,
unsigned long * V_13 )
{
if ( V_293 )
F_108 ( F_51 ( V_53 ) , F_52 ( V_53 ) ,
V_291 , V_292 ) ;
F_7 ( & V_290 , * V_13 ) ;
}
static unsigned int F_109 ( struct V_294 * args , T_3 * V_295 )
{
const T_3 V_296 [] = {
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
T_3 V_297 [] = {
V_298 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_91 ( L_31 ) ;
if ( F_110 ( args -> V_89 ) )
V_297 [ 1 ] |= ( 1 << 7 ) ;
memcpy ( V_295 , V_297 , sizeof( V_297 ) ) ;
memcpy ( & V_295 [ 8 ] , L_37 , 8 ) ;
F_35 ( args -> V_89 , & V_295 [ 16 ] , V_92 , 16 ) ;
F_35 ( args -> V_89 , & V_295 [ 32 ] , V_94 , 4 ) ;
if ( V_295 [ 32 ] == 0 || V_295 [ 32 ] == ' ' )
memcpy ( & V_295 [ 32 ] , L_38 , 4 ) ;
memcpy ( V_295 + 59 , V_296 , sizeof( V_296 ) ) ;
return 0 ;
}
static unsigned int F_111 ( struct V_294 * args , T_3 * V_295 )
{
const T_3 V_299 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
} ;
V_295 [ 3 ] = sizeof( V_299 ) ;
memcpy ( V_295 + 4 , V_299 , sizeof( V_299 ) ) ;
return 0 ;
}
static unsigned int F_112 ( struct V_294 * args , T_3 * V_295 )
{
const T_3 V_297 [] = {
0 ,
0x80 ,
0 ,
V_97 ,
} ;
memcpy ( V_295 , V_297 , sizeof( V_297 ) ) ;
F_35 ( args -> V_89 , ( unsigned char * ) & V_295 [ 4 ] ,
V_96 , V_97 ) ;
return 0 ;
}
static unsigned int F_113 ( struct V_294 * args , T_3 * V_295 )
{
const int V_300 = 68 ;
int V_301 ;
V_295 [ 1 ] = 0x83 ;
V_301 = 4 ;
V_295 [ V_301 + 0 ] = 2 ;
V_295 [ V_301 + 3 ] = V_97 ;
V_301 += 4 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_295 + V_301 ,
V_96 , V_97 ) ;
V_301 += V_97 ;
V_295 [ V_301 + 0 ] = 2 ;
V_295 [ V_301 + 1 ] = 1 ;
V_295 [ V_301 + 3 ] = V_300 ;
V_301 += 4 ;
memcpy ( V_295 + V_301 , L_37 , 8 ) ;
V_301 += 8 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_295 + V_301 , V_92 ,
V_93 ) ;
V_301 += V_93 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_295 + V_301 , V_96 ,
V_97 ) ;
V_301 += V_97 ;
if ( F_114 ( args -> V_89 ) ) {
V_295 [ V_301 + 0 ] = 1 ;
V_295 [ V_301 + 1 ] = 3 ;
V_295 [ V_301 + 3 ] = V_302 ;
V_301 += 4 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_295 + V_301 ,
V_303 , V_302 ) ;
V_301 += V_302 ;
}
V_295 [ 3 ] = V_301 - 4 ;
return 0 ;
}
static unsigned int F_115 ( struct V_294 * args , T_3 * V_295 )
{
struct V_148 V_149 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_295 [ 1 ] = 0x89 ;
V_295 [ 2 ] = ( 0x238 >> 8 ) ;
V_295 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_295 [ 8 ] , L_39 , 8 ) ;
memcpy ( & V_295 [ 16 ] , L_40 , 16 ) ;
memcpy ( & V_295 [ 32 ] , V_304 , 4 ) ;
V_149 . V_151 = V_305 ;
V_149 . V_178 = 0x1 ;
V_149 . V_177 = 0x1 ;
F_116 ( & V_149 , 0 , 1 , & V_295 [ 36 ] ) ;
V_295 [ 36 ] = 0x34 ;
V_295 [ 56 ] = V_306 ;
memcpy ( & V_295 [ 60 ] , & args -> V_89 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_117 ( struct V_294 * args , T_3 * V_295 )
{
T_6 V_307 ;
V_295 [ 1 ] = 0xb0 ;
V_295 [ 3 ] = 0x3c ;
V_307 = 1 << F_118 ( args -> V_89 ) ;
F_119 ( V_307 , & V_295 [ 6 ] ) ;
if ( F_120 ( args -> V_89 ) ) {
F_121 ( 65535 * 512 / 8 , & V_295 [ 36 ] ) ;
F_122 ( 1 , & V_295 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_123 ( struct V_294 * args , T_3 * V_295 )
{
int V_308 = F_124 ( args -> V_89 ) ;
int V_309 = F_125 ( args -> V_89 ) ;
V_295 [ 1 ] = 0xb1 ;
V_295 [ 3 ] = 0x3c ;
V_295 [ 4 ] = V_309 >> 8 ;
V_295 [ 5 ] = V_309 ;
V_295 [ 7 ] = V_308 ;
return 0 ;
}
static unsigned int F_126 ( struct V_294 * args , T_3 * V_295 )
{
V_295 [ 1 ] = 0xb2 ;
V_295 [ 3 ] = 0x4 ;
V_295 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_127 ( struct V_294 * args , T_3 * V_295 )
{
F_91 ( L_31 ) ;
return 0 ;
}
static void F_128 ( T_3 * V_310 , const T_3 * V_311 , int V_312 , bool V_313 )
{
if ( V_313 ) {
memcpy ( V_310 , V_311 , 2 ) ;
memset ( V_310 + 2 , 0 , V_312 - 2 ) ;
} else {
memcpy ( V_310 , V_311 , V_312 ) ;
}
}
static unsigned int F_129 ( T_6 * V_89 , T_3 * V_5 , bool V_313 )
{
F_128 ( V_5 , V_314 , sizeof( V_314 ) , V_313 ) ;
if ( V_313 || F_130 ( V_89 ) )
V_5 [ 2 ] |= ( 1 << 2 ) ;
if ( ! V_313 && ! F_131 ( V_89 ) )
V_5 [ 12 ] |= ( 1 << 5 ) ;
return sizeof( V_314 ) ;
}
static unsigned int F_132 ( T_3 * V_5 , bool V_313 )
{
F_128 ( V_5 , V_315 , sizeof( V_315 ) , V_313 ) ;
return sizeof( V_315 ) ;
}
static unsigned int F_133 ( T_3 * V_5 , bool V_313 )
{
F_128 ( V_5 , V_316 , sizeof( V_316 ) ,
V_313 ) ;
return sizeof( V_316 ) ;
}
static int F_134 ( T_6 * V_89 )
{
unsigned char V_317 [ V_93 + 1 ] , V_318 [ V_95 + 1 ] ;
if ( ! V_319 )
return 0 ;
if ( ! F_135 ( V_89 ) )
return 0 ;
F_136 ( V_89 , V_317 , V_92 , sizeof( V_317 ) ) ;
F_136 ( V_89 , V_318 , V_94 , sizeof( V_318 ) ) ;
if ( strcmp ( V_317 , L_41 ) )
return 1 ;
if ( strcmp ( V_318 , L_42 ) )
return 1 ;
return 0 ;
}
static unsigned int F_137 ( struct V_294 * args , T_3 * V_295 )
{
struct V_25 * V_2 = args -> V_2 ;
T_3 * V_137 = args -> V_53 -> V_223 , * V_320 = V_295 ;
const T_3 V_321 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_322 , V_323 ;
unsigned int V_324 , V_325 , V_326 ;
T_3 V_327 ;
F_91 ( L_31 ) ;
V_326 = ( V_137 [ 0 ] == V_328 ) ;
V_324 = ! ( V_137 [ 1 ] & 0x8 ) ;
V_325 = V_137 [ 2 ] >> 6 ;
switch ( V_325 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_329;
default:
goto V_225;
}
if ( V_326 )
V_320 += 4 + ( V_324 ? 8 : 0 ) ;
else
V_320 += 8 + ( V_324 ? 8 : 0 ) ;
V_322 = V_137 [ 2 ] & 0x3f ;
V_323 = V_137 [ 3 ] ;
if ( V_323 && ( V_323 != V_330 ) )
goto V_225;
switch( V_322 ) {
case V_331 :
V_320 += F_133 ( V_320 , V_325 == 1 ) ;
break;
case V_332 :
V_320 += F_129 ( args -> V_89 , V_320 , V_325 == 1 ) ;
break;
case V_333 :
V_320 += F_132 ( V_320 , V_325 == 1 ) ;
break;
case V_334 :
V_320 += F_133 ( V_320 , V_325 == 1 ) ;
V_320 += F_129 ( args -> V_89 , V_320 , V_325 == 1 ) ;
V_320 += F_132 ( V_320 , V_325 == 1 ) ;
break;
default:
goto V_225;
}
V_327 = 0 ;
if ( F_134 ( args -> V_89 ) && ( V_2 -> V_13 & V_254 ) &&
( ! ( V_2 -> V_13 & V_335 ) || V_2 -> V_336 ) )
V_327 = 1 << 4 ;
if ( V_326 ) {
V_295 [ 0 ] = V_320 - V_295 - 1 ;
V_295 [ 2 ] |= V_327 ;
if ( V_324 ) {
V_295 [ 3 ] = sizeof( V_321 ) ;
memcpy ( V_295 + 4 , V_321 , sizeof( V_321 ) ) ;
}
} else {
unsigned int V_337 = V_320 - V_295 - 2 ;
V_295 [ 0 ] = V_337 >> 8 ;
V_295 [ 1 ] = V_337 ;
V_295 [ 3 ] |= V_327 ;
if ( V_324 ) {
V_295 [ 7 ] = sizeof( V_321 ) ;
memcpy ( V_295 + 8 , V_321 , sizeof( V_321 ) ) ;
}
}
return 0 ;
V_225:
F_20 ( args -> V_53 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_329:
F_20 ( args -> V_53 , V_75 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_138 ( struct V_294 * args , T_3 * V_295 )
{
struct V_25 * V_2 = args -> V_2 ;
T_7 V_338 = V_2 -> V_81 - 1 ;
T_8 V_202 ;
T_3 V_339 ;
T_6 V_340 ;
V_202 = F_72 ( V_2 -> V_89 ) ;
V_339 = F_118 ( V_2 -> V_89 ) ;
V_340 = F_139 ( V_2 -> V_89 , V_339 ) ;
F_91 ( L_31 ) ;
if ( args -> V_53 -> V_223 [ 0 ] == V_341 ) {
if ( V_338 >= 0xffffffffULL )
V_338 = 0xffffffff ;
V_295 [ 0 ] = V_338 >> ( 8 * 3 ) ;
V_295 [ 1 ] = V_338 >> ( 8 * 2 ) ;
V_295 [ 2 ] = V_338 >> ( 8 * 1 ) ;
V_295 [ 3 ] = V_338 ;
V_295 [ 4 ] = V_202 >> ( 8 * 3 ) ;
V_295 [ 5 ] = V_202 >> ( 8 * 2 ) ;
V_295 [ 6 ] = V_202 >> ( 8 * 1 ) ;
V_295 [ 7 ] = V_202 ;
} else {
V_295 [ 0 ] = V_338 >> ( 8 * 7 ) ;
V_295 [ 1 ] = V_338 >> ( 8 * 6 ) ;
V_295 [ 2 ] = V_338 >> ( 8 * 5 ) ;
V_295 [ 3 ] = V_338 >> ( 8 * 4 ) ;
V_295 [ 4 ] = V_338 >> ( 8 * 3 ) ;
V_295 [ 5 ] = V_338 >> ( 8 * 2 ) ;
V_295 [ 6 ] = V_338 >> ( 8 * 1 ) ;
V_295 [ 7 ] = V_338 ;
V_295 [ 8 ] = V_202 >> ( 8 * 3 ) ;
V_295 [ 9 ] = V_202 >> ( 8 * 2 ) ;
V_295 [ 10 ] = V_202 >> ( 8 * 1 ) ;
V_295 [ 11 ] = V_202 ;
V_295 [ 12 ] = 0 ;
V_295 [ 13 ] = V_339 ;
V_295 [ 14 ] = ( V_340 >> 8 ) & 0x3f ;
V_295 [ 15 ] = V_340 ;
if ( F_120 ( args -> V_89 ) ) {
V_295 [ 14 ] |= 0x80 ;
if ( F_140 ( args -> V_89 ) )
V_295 [ 14 ] |= 0x40 ;
}
}
return 0 ;
}
static unsigned int F_141 ( struct V_294 * args , T_3 * V_295 )
{
F_91 ( L_31 ) ;
V_295 [ 3 ] = 8 ;
return 0 ;
}
static void F_142 ( struct V_135 * V_136 )
{
if ( V_136 -> V_172 && ( ( V_136 -> V_172 & V_342 ) == 0 ) ) {
F_58 ( V_136 ) ;
}
V_136 -> V_138 ( V_136 -> V_137 ) ;
F_101 ( V_136 ) ;
}
static inline int F_143 ( struct V_9 * V_10 )
{
return ( V_10 -> V_13 & V_123 ) ;
}
static void F_144 ( struct V_135 * V_136 )
{
struct V_9 * V_10 = V_136 -> V_10 ;
struct V_52 * V_53 = V_136 -> V_137 ;
F_97 ( L_43 ) ;
memset ( V_53 -> V_60 , 0 , V_107 ) ;
#ifdef F_145
if ( V_10 -> V_61 -> V_343 )
V_10 -> V_61 -> V_343 ( V_10 , & V_136 -> V_149 ) ;
#endif
V_53 -> V_60 [ 0 ] = 0x70 ;
V_53 -> V_60 [ 2 ] = V_136 -> V_149 . V_153 >> 4 ;
F_146 ( V_136 ) ;
F_147 ( & V_136 -> V_344 , V_53 -> V_60 , V_107 ) ;
F_103 ( V_136 , & V_136 -> V_344 , 1 ) ;
V_136 -> V_280 = V_112 ;
memset ( & V_136 -> V_222 , 0 , V_136 -> V_2 -> V_345 ) ;
V_136 -> V_222 [ 0 ] = V_346 ;
V_136 -> V_222 [ 4 ] = V_107 ;
V_136 -> V_149 . V_13 |= V_227 | V_226 ;
V_136 -> V_149 . V_151 = V_347 ;
if ( F_143 ( V_10 ) ) {
V_136 -> V_149 . V_228 = V_348 ;
V_136 -> V_149 . V_153 |= V_349 ;
} else {
V_136 -> V_149 . V_228 = V_350 ;
V_136 -> V_149 . V_179 = V_107 ;
V_136 -> V_149 . V_180 = 0 ;
}
V_136 -> V_147 = V_107 ;
V_136 -> V_281 = F_142 ;
F_104 ( V_136 ) ;
F_97 ( L_33 ) ;
}
static void F_148 ( struct V_135 * V_136 )
{
struct V_52 * V_53 = V_136 -> V_137 ;
unsigned int V_172 = V_136 -> V_172 ;
F_91 ( L_44 , V_172 ) ;
if ( F_17 ( V_136 -> V_10 -> V_61 -> V_171 &&
( V_172 || V_136 -> V_13 & V_351 ) ) ) {
if ( ! ( V_136 -> V_13 & V_351 ) ) {
F_58 ( V_136 ) ;
}
if ( V_136 -> V_222 [ 0 ] == V_352 && V_136 -> V_2 -> V_22 )
V_136 -> V_2 -> V_22 -> V_353 = 0 ;
V_136 -> V_137 -> V_57 = V_59 ;
V_136 -> V_138 ( V_53 ) ;
F_101 ( V_136 ) ;
return;
}
if ( F_17 ( V_172 & V_342 ) ) {
V_53 -> V_57 = V_59 ;
F_144 ( V_136 ) ;
return;
} else if ( F_17 ( V_172 ) ) {
F_58 ( V_136 ) ;
} else {
T_3 * V_137 = V_53 -> V_223 ;
if ( ( V_137 [ 0 ] == V_354 ) && ( ( V_137 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_13 ;
T_3 * V_5 ;
V_5 = F_105 ( V_53 , true , & V_13 ) ;
if ( V_5 [ 2 ] == 0 ) {
V_5 [ 2 ] = 0x5 ;
V_5 [ 3 ] = 0x32 ;
}
F_107 ( V_53 , true , & V_13 ) ;
}
V_53 -> V_57 = V_240 ;
}
V_136 -> V_138 ( V_53 ) ;
F_101 ( V_136 ) ;
}
static unsigned int F_149 ( struct V_135 * V_136 )
{
struct V_52 * V_143 = V_136 -> V_137 ;
struct V_25 * V_2 = V_136 -> V_2 ;
int V_355 = ( V_143 -> V_277 == V_113 ) ;
int V_356 = ! V_355 && ( V_2 -> V_13 & V_335 ) ;
unsigned int V_147 ;
memset ( V_136 -> V_222 , 0 , V_2 -> V_345 ) ;
memcpy ( V_136 -> V_222 , V_143 -> V_223 , V_143 -> V_224 ) ;
V_136 -> V_281 = F_148 ;
V_136 -> V_149 . V_13 |= V_227 | V_226 ;
if ( V_143 -> V_277 == V_278 ) {
V_136 -> V_149 . V_13 |= V_266 ;
F_97 ( L_45 ) ;
}
V_136 -> V_149 . V_151 = V_347 ;
F_53 ( V_136 ) ;
if ( ! V_355 && ! V_356 && F_150 ( V_136 ) )
V_356 = 1 ;
V_147 = F_76 ( F_151 ( V_136 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_147 & 0x1 )
V_147 ++ ;
V_136 -> V_149 . V_179 = ( V_147 & 0xFF ) ;
V_136 -> V_149 . V_180 = ( V_147 >> 8 ) ;
if ( V_355 )
V_136 -> V_149 . V_228 = V_357 ;
else if ( V_356 )
V_136 -> V_149 . V_228 = V_350 ;
else {
V_136 -> V_149 . V_228 = V_348 ;
V_136 -> V_149 . V_153 |= V_349 ;
if ( ( V_2 -> V_13 & V_358 ) &&
( V_143 -> V_277 != V_278 ) )
V_136 -> V_149 . V_153 |= V_359 ;
}
return 0 ;
}
static struct V_25 * F_152 ( struct V_9 * V_10 , int V_40 )
{
if ( ! F_153 ( V_10 ) ) {
if ( F_63 ( V_40 < F_154 ( & V_10 -> V_24 ) ) )
return & V_10 -> V_24 . V_1 [ V_40 ] ;
} else {
if ( F_63 ( V_40 < V_10 -> V_360 ) )
return & V_10 -> V_361 [ V_40 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_25 * F_81 ( struct V_9 * V_10 ,
const struct V_21 * V_98 )
{
int V_40 ;
if ( ! F_153 ( V_10 ) ) {
if ( F_17 ( V_98 -> V_362 || V_98 -> V_363 ) )
return NULL ;
V_40 = V_98 -> V_89 ;
} else {
if ( F_17 ( V_98 -> V_89 || V_98 -> V_363 ) )
return NULL ;
V_40 = V_98 -> V_362 ;
}
return F_152 ( V_10 , V_40 ) ;
}
static struct V_25 *
F_11 ( struct V_9 * V_10 , const struct V_21 * V_98 )
{
struct V_25 * V_2 = F_81 ( V_10 , V_98 ) ;
if ( F_17 ( ! V_2 || ! F_84 ( V_2 ) ) )
return NULL ;
return V_2 ;
}
static T_3
F_155 ( T_3 V_364 )
{
switch( ( V_364 & 0x1e ) >> 1 ) {
case 3 :
return V_229 ;
case 6 :
case 10 :
case 11 :
return V_365 ;
case 4 :
case 5 :
return V_366 ;
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
return V_367 ;
}
static unsigned int F_156 ( struct V_135 * V_136 )
{
struct V_148 * V_149 = & ( V_136 -> V_149 ) ;
struct V_52 * V_143 = V_136 -> V_137 ;
struct V_25 * V_2 = V_136 -> V_2 ;
const T_3 * V_222 = V_143 -> V_223 ;
if ( ( V_149 -> V_228 = F_155 ( V_222 [ 1 ] ) ) == V_367 )
goto V_225;
if ( V_222 [ 0 ] == V_114 ) {
if ( V_222 [ 1 ] & 0x01 ) {
V_149 -> V_368 = V_222 [ 3 ] ;
V_149 -> V_182 = V_222 [ 5 ] ;
V_149 -> V_183 = V_222 [ 7 ] ;
V_149 -> V_184 = V_222 [ 9 ] ;
V_149 -> V_185 = V_222 [ 11 ] ;
V_149 -> V_13 |= V_181 ;
} else
V_149 -> V_13 &= ~ V_181 ;
V_149 -> V_153 = V_222 [ 4 ] ;
V_149 -> V_177 = V_222 [ 6 ] ;
V_149 -> V_178 = V_222 [ 8 ] ;
V_149 -> V_179 = V_222 [ 10 ] ;
V_149 -> V_180 = V_222 [ 12 ] ;
V_149 -> V_1 = V_222 [ 13 ] ;
V_149 -> V_151 = V_222 [ 14 ] ;
} else {
V_149 -> V_13 &= ~ V_181 ;
V_149 -> V_153 = V_222 [ 3 ] ;
V_149 -> V_177 = V_222 [ 4 ] ;
V_149 -> V_178 = V_222 [ 5 ] ;
V_149 -> V_179 = V_222 [ 6 ] ;
V_149 -> V_180 = V_222 [ 7 ] ;
V_149 -> V_1 = V_222 [ 8 ] ;
V_149 -> V_151 = V_222 [ 9 ] ;
}
V_149 -> V_1 = V_2 -> V_40 ?
V_149 -> V_1 | V_369 : V_149 -> V_1 & ~ V_369 ;
switch ( V_149 -> V_151 ) {
case V_370 :
case V_371 :
case V_372 :
case V_373 :
if ( V_149 -> V_228 != V_366 || V_149 -> V_177 != 1 )
goto V_225;
V_136 -> V_374 = F_54 ( V_143 ) ;
break;
case V_375 :
case V_376 :
case V_377 :
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
case V_233 :
case V_255 :
case V_388 :
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
V_136 -> V_374 = V_143 -> V_1 -> V_202 ;
break;
default:
V_136 -> V_374 = V_110 ;
}
V_149 -> V_13 |= V_227 | V_226 ;
if ( V_143 -> V_277 == V_278 )
V_149 -> V_13 |= V_266 ;
V_136 -> V_13 |= V_401 | V_402 ;
F_53 ( V_136 ) ;
if ( V_149 -> V_228 == V_365 && V_2 -> V_403 == 0 )
goto V_225;
if ( ( V_222 [ 1 ] & 0xe0 ) && ! F_157 ( V_149 ) )
goto V_225;
if ( F_157 ( V_149 ) ) {
unsigned int V_336 = 1 << ( V_222 [ 1 ] >> 5 ) ;
if ( V_336 != V_2 -> V_336 )
F_73 ( V_2 , L_46 ,
V_336 ) ;
}
if ( V_149 -> V_151 == V_404 &&
V_149 -> V_153 == V_405 )
goto V_225;
if ( V_149 -> V_151 >= 0x5C && V_149 -> V_151 <= 0x5F && ! V_406 )
goto V_225;
return 0 ;
V_225:
F_20 ( V_143 , V_75 , 0x24 , 0x00 ) ;
return 1 ;
}
static unsigned int F_158 ( struct V_135 * V_136 )
{
struct V_148 * V_149 = & V_136 -> V_149 ;
struct V_52 * V_143 = V_136 -> V_137 ;
struct V_25 * V_2 = V_136 -> V_2 ;
const T_3 * V_222 = V_143 -> V_223 ;
T_7 V_186 ;
T_8 V_249 ;
T_8 V_407 ;
void * V_5 ;
if ( F_17 ( ! V_2 -> V_403 ) )
goto V_225;
if ( F_17 ( V_143 -> V_224 < 16 ) )
goto V_225;
F_93 ( V_222 , & V_186 , & V_249 ) ;
if ( F_17 ( ! ( V_222 [ 1 ] & 0x8 ) ) )
goto V_225;
if ( ! F_52 ( V_143 ) )
goto V_225;
V_5 = F_159 ( F_160 ( F_51 ( V_143 ) ) ) ;
V_407 = F_161 ( V_5 , 512 , V_186 , V_249 ) ;
if ( F_85 ( V_2 ) && F_162 ( V_2 ) ) {
V_149 -> V_228 = V_408 ;
V_149 -> V_151 = V_409 ;
V_149 -> V_182 = V_410 & 0x1f ;
V_149 -> V_177 = V_136 -> V_271 << 3 ;
V_149 -> V_368 = ( V_407 / 512 ) >> 8 ;
V_149 -> V_153 = V_407 / 512 ;
V_149 -> V_411 = 1 ;
} else {
V_149 -> V_228 = V_365 ;
V_149 -> V_368 = 0 ;
V_149 -> V_153 = V_412 ;
V_149 -> V_182 = ( V_407 / 512 ) >> 8 ;
V_149 -> V_177 = V_407 / 512 ;
V_149 -> V_151 = V_413 ;
}
V_149 -> V_13 |= V_227 | V_226 | V_181 |
V_266 ;
F_53 ( V_136 ) ;
return 0 ;
V_225:
F_20 ( V_143 , V_75 , 0x24 , 0x00 ) ;
return 1 ;
}
static int F_163 ( struct V_135 * V_136 ,
const T_3 * V_5 , int V_42 )
{
struct V_148 * V_149 = & V_136 -> V_149 ;
struct V_25 * V_2 = V_136 -> V_2 ;
char V_414 [ V_415 ] ;
T_3 V_416 ;
if ( V_42 != V_415 - 2 )
return - V_17 ;
V_416 = V_5 [ 0 ] & ( 1 << 2 ) ;
F_129 ( V_2 -> V_89 , V_414 , false ) ;
V_414 [ 2 ] &= ~ ( 1 << 2 ) ;
V_414 [ 2 ] |= V_416 ;
if ( memcmp ( V_414 + 2 , V_5 , V_415 - 2 ) != 0 )
return - V_17 ;
V_149 -> V_13 |= V_226 | V_227 ;
V_149 -> V_228 = V_229 ;
V_149 -> V_177 = 0 ;
V_149 -> V_151 = V_404 ;
V_149 -> V_153 = V_416 ? V_417 : V_418 ;
return 0 ;
}
static unsigned int F_164 ( struct V_135 * V_136 )
{
struct V_52 * V_143 = V_136 -> V_137 ;
const T_3 * V_222 = V_143 -> V_223 ;
const T_3 * V_320 ;
T_3 V_322 , V_323 ;
unsigned V_326 , V_419 , V_420 , V_421 ;
int V_42 ;
F_91 ( L_31 ) ;
V_326 = ( V_222 [ 0 ] == V_422 ) ;
if ( V_326 ) {
if ( V_143 -> V_224 < 5 )
goto V_225;
V_42 = V_222 [ 4 ] ;
V_420 = 4 ;
} else {
if ( V_143 -> V_224 < 9 )
goto V_225;
V_42 = ( V_222 [ 7 ] << 8 ) + V_222 [ 8 ] ;
V_420 = 8 ;
}
if ( ( V_222 [ 1 ] & 0x11 ) != 0x10 )
goto V_225;
if ( ! F_52 ( V_143 ) || F_51 ( V_143 ) -> V_423 < V_42 )
goto V_424;
V_320 = F_159 ( F_160 ( F_51 ( V_143 ) ) ) ;
if ( V_42 < V_420 )
goto V_424;
if ( V_326 )
V_421 = V_320 [ 3 ] ;
else
V_421 = ( V_320 [ 6 ] << 8 ) + V_320 [ 7 ] ;
V_42 -= V_420 ;
V_320 += V_420 ;
if ( V_42 < V_421 )
goto V_424;
if ( V_421 != 0 && V_421 != 8 )
goto V_425;
V_42 -= V_421 ;
V_320 += V_421 ;
if ( V_42 == 0 )
goto V_237;
V_322 = V_320 [ 0 ] & 0x3f ;
if ( V_320 [ 0 ] & 0x40 ) {
if ( V_42 < 4 )
goto V_424;
V_323 = V_320 [ 1 ] ;
V_419 = ( V_320 [ 2 ] << 8 ) | V_320 [ 3 ] ;
V_320 += 4 ;
V_42 -= 4 ;
} else {
if ( V_42 < 2 )
goto V_424;
V_323 = 0 ;
V_419 = V_320 [ 1 ] ;
V_320 += 2 ;
V_42 -= 2 ;
}
if ( V_323 && ( V_323 != V_330 ) )
goto V_425;
if ( V_419 > V_42 )
goto V_424;
switch ( V_322 ) {
case V_332 :
if ( F_163 ( V_136 , V_320 , V_419 ) < 0 )
goto V_425;
break;
default:
goto V_425;
}
if ( V_42 > V_419 )
goto V_425;
return 0 ;
V_225:
F_20 ( V_143 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_425:
F_20 ( V_143 , V_75 , 0x26 , 0x0 ) ;
return 1 ;
V_424:
F_20 ( V_143 , V_75 , 0x1a , 0x0 ) ;
return 1 ;
V_237:
V_143 -> V_57 = V_240 ;
return 1 ;
}
static inline T_9 F_165 ( struct V_25 * V_2 , T_3 V_53 )
{
switch ( V_53 ) {
case V_269 :
case V_267 :
case V_270 :
case V_264 :
case V_263 :
case V_265 :
return F_98 ;
case V_426 :
return F_158 ;
case V_427 :
if ( F_166 ( V_2 ) )
return F_89 ;
break;
case V_250 :
case V_251 :
return F_94 ;
case V_274 :
case V_114 :
return F_156 ;
case V_422 :
case V_428 :
return F_164 ;
break;
case V_429 :
return F_87 ;
}
return NULL ;
}
static inline void F_167 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
#ifdef F_168
struct V_21 * V_98 = V_53 -> V_1 ;
T_3 * V_137 = V_53 -> V_223 ;
F_97 ( L_47 ,
V_10 -> V_176 ,
V_98 -> V_362 , V_98 -> V_89 , V_98 -> V_363 ,
V_137 [ 0 ] , V_137 [ 1 ] , V_137 [ 2 ] , V_137 [ 3 ] ,
V_137 [ 4 ] , V_137 [ 5 ] , V_137 [ 6 ] , V_137 [ 7 ] ,
V_137 [ 8 ] ) ;
#endif
}
static inline int F_169 ( struct V_52 * V_143 ,
struct V_25 * V_2 )
{
T_3 V_430 = V_143 -> V_223 [ 0 ] ;
T_9 V_275 ;
int V_29 = 0 ;
if ( V_2 -> V_46 == V_47 ) {
if ( F_17 ( ! V_143 -> V_224 || V_143 -> V_224 > V_2 -> V_345 ) )
goto V_431;
V_275 = F_165 ( V_2 , V_430 ) ;
} else {
if ( F_17 ( ! V_143 -> V_224 ) )
goto V_431;
V_275 = NULL ;
if ( F_63 ( ( V_430 != V_114 ) || ! V_432 ) ) {
int V_42 = F_170 ( V_430 ) ;
if ( F_17 ( V_42 > V_143 -> V_224 || V_42 > V_2 -> V_345 ) )
goto V_431;
V_275 = F_149 ;
} else {
if ( F_17 ( V_143 -> V_224 > 16 ) )
goto V_431;
V_275 = F_165 ( V_2 , V_430 ) ;
}
}
if ( V_275 )
V_29 = F_102 ( V_2 , V_143 , V_275 ) ;
else
F_171 ( V_2 , V_143 ) ;
return V_29 ;
V_431:
F_97 ( L_48 ,
V_143 -> V_224 , V_430 , V_2 -> V_345 ) ;
V_143 -> V_57 = V_285 << 16 ;
V_143 -> V_76 ( V_143 ) ;
return 0 ;
}
int F_172 ( struct V_7 * V_8 , struct V_52 * V_53 )
{
struct V_9 * V_10 ;
struct V_25 * V_2 ;
struct V_21 * V_98 = V_53 -> V_1 ;
int V_29 = 0 ;
unsigned long V_433 ;
V_10 = F_3 ( V_8 ) ;
F_5 ( V_10 -> V_18 , V_433 ) ;
F_167 ( V_10 , V_53 ) ;
V_2 = F_11 ( V_10 , V_98 ) ;
if ( F_63 ( V_2 ) )
V_29 = F_169 ( V_53 , V_2 ) ;
else {
V_53 -> V_57 = ( V_434 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
}
F_7 ( V_10 -> V_18 , V_433 ) ;
return V_29 ;
}
void F_171 ( struct V_25 * V_2 , struct V_52 * V_53 )
{
struct V_294 args ;
const T_3 * V_137 = V_53 -> V_223 ;
T_3 V_435 ;
args . V_2 = V_2 ;
args . V_89 = V_2 -> V_89 ;
args . V_53 = V_53 ;
args . V_436 = V_53 -> V_76 ;
switch( V_137 [ 0 ] ) {
case V_437 :
F_28 ( V_53 ) ;
break;
case V_354 :
if ( V_137 [ 1 ] & 2 )
F_28 ( V_53 ) ;
else if ( ( V_137 [ 1 ] & 1 ) == 0 )
F_173 ( & args , F_109 ) ;
else switch ( V_137 [ 2 ] ) {
case 0x00 :
F_173 ( & args , F_111 ) ;
break;
case 0x80 :
F_173 ( & args , F_112 ) ;
break;
case 0x83 :
F_173 ( & args , F_113 ) ;
break;
case 0x89 :
F_173 ( & args , F_115 ) ;
break;
case 0xb0 :
F_173 ( & args , F_117 ) ;
break;
case 0xb1 :
F_173 ( & args , F_123 ) ;
break;
case 0xb2 :
F_173 ( & args , F_126 ) ;
break;
default:
F_28 ( V_53 ) ;
break;
}
break;
case V_328 :
case V_438 :
F_173 ( & args , F_137 ) ;
break;
case V_341 :
F_173 ( & args , F_138 ) ;
break;
case V_439 :
if ( ( V_137 [ 1 ] & 0x1f ) == V_440 )
F_173 ( & args , F_138 ) ;
else
F_28 ( V_53 ) ;
break;
case V_441 :
F_173 ( & args , F_141 ) ;
break;
case V_346 :
F_20 ( V_53 , 0 , 0 , 0 ) ;
V_53 -> V_57 = ( V_58 << 24 ) ;
V_53 -> V_76 ( V_53 ) ;
break;
case V_427 :
case V_442 :
case V_443 :
case V_444 :
case V_445 :
F_173 ( & args , F_127 ) ;
break;
case V_446 :
V_435 = V_137 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_435 == 0x4 ) && ( ! V_137 [ 3 ] ) && ( ! V_137 [ 4 ] ) )
F_173 ( & args , F_127 ) ;
else
F_28 ( V_53 ) ;
break;
default:
F_20 ( V_53 , V_75 , 0x20 , 0x0 ) ;
V_53 -> V_76 ( V_53 ) ;
break;
}
}
int F_174 ( struct V_447 * V_30 , struct V_448 * V_449 )
{
int V_159 , V_29 ;
for ( V_159 = 0 ; V_159 < V_30 -> V_450 ; V_159 ++ ) {
struct V_9 * V_10 = V_30 -> V_451 [ V_159 ] ;
struct V_7 * V_8 ;
V_29 = - V_109 ;
V_8 = F_175 ( V_449 , sizeof( struct V_9 * ) ) ;
if ( ! V_8 )
goto V_452;
V_8 -> V_453 = 1 ;
* (struct V_9 * * ) & V_8 -> V_454 [ 0 ] = V_10 ;
V_10 -> V_455 = V_8 ;
V_8 -> V_456 = V_457 ;
V_8 -> V_458 = V_10 -> V_176 ;
V_8 -> V_459 = 16 ;
V_8 -> V_460 = 1 ;
V_8 -> V_461 = 1 ;
V_8 -> V_462 = 16 ;
V_8 -> V_463 = 1 ;
V_29 = F_176 ( V_10 -> V_455 ,
& V_10 -> V_464 , V_10 -> V_30 -> V_2 ) ;
if ( V_29 )
goto V_465;
}
return 0 ;
V_465:
F_177 ( V_30 -> V_451 [ V_159 ] -> V_455 ) ;
V_452:
while ( -- V_159 >= 0 ) {
struct V_7 * V_8 = V_30 -> V_451 [ V_159 ] -> V_455 ;
F_178 ( V_8 ) ;
F_177 ( V_8 ) ;
}
return V_29 ;
}
void F_179 ( struct V_9 * V_10 , int V_466 )
{
int V_467 = 5 ;
struct V_25 * V_468 = NULL ;
struct V_23 * V_24 ;
struct V_25 * V_2 ;
V_469:
F_180 (link, ap, EDGE) {
F_181 (dev, link, ENABLED) {
struct V_21 * V_22 ;
int V_362 = 0 , V_89 = 0 ;
if ( V_2 -> V_22 )
continue;
if ( F_182 ( V_24 ) )
V_89 = V_2 -> V_40 ;
else
V_362 = V_24 -> V_470 ;
V_22 = F_183 ( V_10 -> V_455 , V_362 , V_89 , 0 ,
NULL ) ;
if ( ! F_184 ( V_22 ) ) {
V_2 -> V_22 = V_22 ;
F_185 ( V_22 ) ;
} else {
V_2 -> V_22 = NULL ;
}
}
}
F_180 (link, ap, EDGE) {
F_181 (dev, link, ENABLED) {
if ( ! V_2 -> V_22 )
goto V_471;
}
}
V_471:
if ( ! V_24 )
return;
if ( V_466 ) {
if ( V_2 != V_468 ) {
F_186 ( 100 ) ;
V_468 = V_2 ;
goto V_469;
}
if ( -- V_467 ) {
F_186 ( 100 ) ;
goto V_469;
}
F_187 ( V_10 ,
L_49 ) ;
}
F_188 ( V_472 , & V_10 -> V_473 ,
F_189 ( V_116 ) ) ;
}
int F_190 ( struct V_25 * V_2 )
{
if ( V_2 -> V_22 ) {
F_191 ( V_2 -> V_22 , V_474 ) ;
return 1 ;
}
return 0 ;
}
static void F_192 ( struct V_25 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_24 -> V_10 ;
struct V_21 * V_22 ;
unsigned long V_13 ;
F_193 ( & V_10 -> V_455 -> V_475 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_22 = V_2 -> V_22 ;
V_2 -> V_22 = NULL ;
if ( V_22 ) {
if ( F_194 ( V_22 ) == 0 ) {
F_191 ( V_22 , V_474 ) ;
} else {
F_195 ( 1 ) ;
V_22 = NULL ;
}
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_196 ( & V_10 -> V_455 -> V_475 ) ;
if ( V_22 ) {
F_197 ( V_2 , L_50 ,
F_198 ( & V_22 -> V_476 ) ) ;
F_199 ( V_22 ) ;
F_185 ( V_22 ) ;
}
}
static void F_200 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_10 ;
struct V_25 * V_2 ;
F_181 (dev, link, ALL) {
unsigned long V_13 ;
if ( ! ( V_2 -> V_13 & V_477 ) )
continue;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 -> V_13 &= ~ V_477 ;
F_7 ( V_10 -> V_18 , V_13 ) ;
if ( F_201 ( V_2 ) )
F_202 ( V_2 ) ;
F_192 ( V_2 ) ;
}
}
void F_203 ( struct V_25 * V_2 )
{
if ( V_2 -> V_22 )
F_204 ( V_2 -> V_22 , V_208 ,
V_478 ) ;
}
void F_205 ( struct V_479 * V_480 )
{
struct V_9 * V_10 =
F_206 ( V_480 , struct V_9 , V_473 . V_480 ) ;
int V_159 ;
if ( V_10 -> V_36 & V_481 ) {
F_97 ( L_51 ) ;
return;
}
F_97 ( L_31 ) ;
F_193 ( & V_10 -> V_482 ) ;
F_200 ( & V_10 -> V_24 ) ;
if ( V_10 -> V_361 )
for ( V_159 = 0 ; V_159 < V_483 ; V_159 ++ )
F_200 ( & V_10 -> V_361 [ V_159 ] ) ;
F_179 ( V_10 , 0 ) ;
F_196 ( & V_10 -> V_482 ) ;
F_97 ( L_33 ) ;
}
int F_207 ( struct V_7 * V_8 , unsigned int V_362 ,
unsigned int V_89 , unsigned int V_363 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_13 ;
int V_40 , V_29 = 0 ;
if ( ! V_10 -> V_61 -> V_171 )
return - V_34 ;
if ( V_363 != V_484 && V_363 )
return - V_17 ;
if ( ! F_153 ( V_10 ) ) {
if ( V_362 != V_484 && V_362 )
return - V_17 ;
V_40 = V_89 ;
} else {
if ( V_89 != V_484 && V_89 )
return - V_17 ;
V_40 = V_362 ;
}
F_5 ( V_10 -> V_18 , V_13 ) ;
if ( V_40 == V_484 ) {
struct V_23 * V_24 ;
F_180 (link, ap, EDGE) {
struct V_485 * V_486 = & V_24 -> V_48 ;
V_486 -> V_487 |= V_488 ;
V_486 -> V_84 |= V_85 ;
}
} else {
struct V_25 * V_2 = F_152 ( V_10 , V_40 ) ;
if ( V_2 ) {
struct V_485 * V_486 = & V_2 -> V_24 -> V_48 ;
V_486 -> V_487 |= 1 << V_2 -> V_40 ;
V_486 -> V_84 |= V_85 ;
} else
V_29 = - V_17 ;
}
if ( V_29 == 0 ) {
F_6 ( V_10 ) ;
F_7 ( V_10 -> V_18 , V_13 ) ;
F_32 ( V_10 ) ;
} else
F_7 ( V_10 -> V_18 , V_13 ) ;
return V_29 ;
}
void F_208 ( struct V_479 * V_480 )
{
struct V_9 * V_10 =
F_206 ( V_480 , struct V_9 , V_489 ) ;
struct V_23 * V_24 ;
struct V_25 * V_2 ;
unsigned long V_13 ;
F_193 ( & V_10 -> V_482 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
F_180 (link, ap, EDGE) {
F_181 (dev, link, ENABLED) {
struct V_21 * V_22 = V_2 -> V_22 ;
if ( ! V_22 )
continue;
if ( F_194 ( V_22 ) )
continue;
F_7 ( V_10 -> V_18 , V_13 ) ;
F_209 ( & ( V_22 -> V_476 ) ) ;
F_185 ( V_22 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
}
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_196 ( & V_10 -> V_482 ) ;
}
struct V_9 * F_210 ( struct V_447 * V_30 ,
struct V_490 * V_491 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_211 ( V_30 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_492 = 0 ;
V_10 -> V_18 = & V_30 -> V_18 ;
V_10 -> V_493 = V_491 -> V_493 ;
V_10 -> V_494 = V_491 -> V_494 ;
V_10 -> V_495 = V_491 -> V_495 ;
V_10 -> V_13 |= V_491 -> V_13 ;
V_10 -> V_61 = V_491 -> V_496 ;
V_10 -> V_497 = V_498 ;
return V_10 ;
}
int F_212 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_61 -> V_171 )
V_10 -> V_36 &= ~ V_499 ;
return 0 ;
}
void F_213 ( struct V_9 * V_10 )
{
}
void F_214 ( struct V_9 * V_10 )
{
F_215 ( V_10 ) ;
}
int F_216 ( struct V_9 * V_10 )
{
return F_217 ( V_10 ) ;
}
int F_218 ( struct V_9 * V_10 )
{
int V_29 = V_10 -> V_61 -> V_500 ( V_10 ) ;
if ( V_29 )
return V_29 ;
V_10 -> V_176 = F_219 ( & V_501 ) ;
return 0 ;
}
void F_220 ( struct V_9 * V_10 )
{
if ( V_10 -> V_61 -> V_502 )
V_10 -> V_61 -> V_502 ( V_10 ) ;
F_43 ( V_10 ) ;
}
int F_221 ( struct V_21 * V_22 , struct V_9 * V_10 )
{
F_61 ( V_22 ) ;
F_66 ( V_22 , V_10 -> V_24 . V_1 ) ;
return 0 ;
}
int F_222 ( struct V_52 * V_53 , struct V_9 * V_10 )
{
int V_29 = 0 ;
F_167 ( V_10 , V_53 ) ;
if ( F_63 ( F_84 ( V_10 -> V_24 . V_1 ) ) )
V_29 = F_169 ( V_53 , V_10 -> V_24 . V_1 ) ;
else {
V_53 -> V_57 = ( V_434 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
}
return V_29 ;
}
