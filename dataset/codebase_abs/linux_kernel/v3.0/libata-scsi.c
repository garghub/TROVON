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
if ( V_29 || V_43 < - 2 )
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
if ( V_10 -> V_61 -> V_67 && ( V_10 -> V_13 & V_68 ) )
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
if ( V_10 -> V_61 -> V_71 && ( V_10 -> V_13 & V_68 ) ) {
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
if ( V_119 . V_120 == 0 &&
V_119 . V_55 == 0 && V_119 . V_56 == 0 )
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
V_29 = - V_121 ;
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
if ( V_119 . V_120 == 0 &&
V_119 . V_55 == 0 && V_119 . V_56 == 0 )
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
V_29 = - V_121 ;
goto error;
}
error:
F_43 ( V_102 ) ;
return V_29 ;
}
static int F_45 ( struct V_9 * V_10 )
{
if ( V_10 -> V_13 & V_122 )
return 1 ;
if ( V_10 -> V_36 & V_123 )
return 1 ;
return 0 ;
}
int F_46 ( struct V_9 * V_10 , struct V_21 * V_98 ,
int V_53 , void T_5 * V_86 )
{
int V_70 = - V_17 , V_29 = - V_17 ;
unsigned long V_13 ;
switch ( V_53 ) {
case V_124 :
F_5 ( V_10 -> V_18 , V_13 ) ;
V_70 = F_45 ( V_10 ) ;
F_7 ( V_10 -> V_18 , V_13 ) ;
if ( F_34 ( V_86 , & V_70 , 1 ) )
return - V_91 ;
return 0 ;
case V_125 :
V_70 = ( unsigned long ) V_86 ;
V_29 = 0 ;
F_5 ( V_10 -> V_18 , V_13 ) ;
if ( V_10 -> V_36 & V_126 ) {
if ( V_70 )
V_10 -> V_36 |= V_123 ;
else
V_10 -> V_36 &= ~ V_123 ;
} else {
if ( V_70 != F_45 ( V_10 ) )
V_29 = - V_17 ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
return V_29 ;
case V_127 :
return F_33 ( V_10 , V_98 , V_86 ) ;
case V_128 :
if ( ! F_47 ( V_129 ) || ! F_47 ( V_130 ) )
return - V_131 ;
return F_36 ( V_98 , V_86 ) ;
case V_132 :
if ( ! F_47 ( V_129 ) || ! F_47 ( V_130 ) )
return - V_131 ;
return F_44 ( V_98 , V_86 ) ;
default:
V_29 = - V_133 ;
break;
}
return V_29 ;
}
int F_48 ( struct V_21 * V_98 , int V_53 , void T_5 * V_86 )
{
return F_46 ( F_3 ( V_98 -> V_30 ) ,
V_98 , V_53 , V_86 ) ;
}
static struct V_134 * F_49 ( struct V_25 * V_2 ,
struct V_52 * V_53 )
{
struct V_134 * V_135 ;
V_135 = F_50 ( V_2 ) ;
if ( V_135 ) {
V_135 -> V_136 = V_53 ;
V_135 -> V_137 = V_53 -> V_76 ;
V_135 -> V_138 = F_51 ( V_53 ) ;
V_135 -> V_139 = F_52 ( V_53 ) ;
} else {
V_53 -> V_57 = ( V_140 << 16 ) | ( V_141 << 1 ) ;
V_53 -> V_76 ( V_53 ) ;
}
return V_135 ;
}
static void F_53 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
V_135 -> V_143 = V_142 -> V_144 -> V_145 ;
V_135 -> V_146 = F_54 ( V_142 ) + V_135 -> V_143 ;
}
static void F_55 ( unsigned V_89 , struct V_147 * V_148 )
{
T_3 V_149 = V_148 -> V_150 , V_151 = V_148 -> V_152 ;
F_56 ( V_153 L_4 , V_89 , V_149 ) ;
if ( V_149 & V_154 ) {
F_56 ( L_5 ) ;
} else {
if ( V_149 & 0x40 ) F_56 ( L_6 ) ;
if ( V_149 & 0x20 ) F_56 ( L_7 ) ;
if ( V_149 & 0x10 ) F_56 ( L_8 ) ;
if ( V_149 & 0x08 ) F_56 ( L_9 ) ;
if ( V_149 & 0x04 ) F_56 ( L_10 ) ;
if ( V_149 & 0x02 ) F_56 ( L_11 ) ;
if ( V_149 & 0x01 ) F_56 ( L_12 ) ;
F_56 ( L_13 ) ;
if ( V_151 ) {
F_56 ( V_153 L_14 , V_89 , V_151 ) ;
if ( V_151 & 0x04 ) F_56 ( L_15 ) ;
if ( V_151 & 0x80 ) {
if ( V_151 & 0x04 ) F_56 ( L_16 ) ;
else F_56 ( L_17 ) ;
}
if ( V_151 & 0x40 ) F_56 ( L_18 ) ;
if ( V_151 & 0x10 ) F_56 ( L_19 ) ;
if ( V_151 & 0x02 ) F_56 ( L_20 ) ;
if ( V_151 & 0x01 ) F_56 ( L_21 ) ;
F_56 ( L_13 ) ;
}
}
}
static void F_57 ( unsigned V_89 , T_3 V_155 , T_3 V_156 , T_3 * V_54 ,
T_3 * V_55 , T_3 * V_56 , int V_157 )
{
int V_158 ;
static const unsigned char V_159 [] [ 4 ] = {
{ 0xd1 , V_160 , 0x00 , 0x00 } ,
{ 0xd0 , V_160 , 0x00 , 0x00 } ,
{ 0x61 , V_161 , 0x00 , 0x00 } ,
{ 0x84 , V_160 , 0x47 , 0x00 } ,
{ 0x37 , V_162 , 0x04 , 0x00 } ,
{ 0x09 , V_162 , 0x04 , 0x00 } ,
{ 0x01 , V_163 , 0x13 , 0x00 } ,
{ 0x02 , V_161 , 0x00 , 0x00 } ,
{ 0x04 , V_160 , 0x00 , 0x00 } ,
{ 0x08 , V_162 , 0x04 , 0x00 } ,
{ 0x10 , V_160 , 0x14 , 0x00 } ,
{ 0x08 , V_162 , 0x04 , 0x00 } ,
{ 0x40 , V_163 , 0x11 , 0x04 } ,
{ 0x80 , V_163 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_164 [] [ 4 ] = {
{ 0x80 , V_160 , 0x47 , 0x00 } ,
{ 0x20 , V_161 , 0x00 , 0x00 } ,
{ 0x08 , V_160 , 0x47 , 0x00 } ,
{ 0x04 , V_165 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_155 & V_154 ) {
V_156 = 0 ;
}
if ( V_156 ) {
for ( V_158 = 0 ; V_159 [ V_158 ] [ 0 ] != 0xFF ; V_158 ++ ) {
if ( ( V_159 [ V_158 ] [ 0 ] & V_156 ) ==
V_159 [ V_158 ] [ 0 ] ) {
* V_54 = V_159 [ V_158 ] [ 1 ] ;
* V_55 = V_159 [ V_158 ] [ 2 ] ;
* V_56 = V_159 [ V_158 ] [ 3 ] ;
goto V_166;
}
}
if ( V_157 )
F_56 ( V_153 L_22
L_23 , V_89 , V_156 ) ;
}
for ( V_158 = 0 ; V_164 [ V_158 ] [ 0 ] != 0xFF ; V_158 ++ ) {
if ( V_164 [ V_158 ] [ 0 ] & V_155 ) {
* V_54 = V_164 [ V_158 ] [ 1 ] ;
* V_55 = V_164 [ V_158 ] [ 2 ] ;
* V_56 = V_164 [ V_158 ] [ 3 ] ;
goto V_166;
}
}
if ( V_157 )
F_56 ( V_153 L_22
L_24 , V_89 , V_155 ) ;
* V_54 = V_160 ;
* V_55 = 0x00 ;
* V_56 = 0x00 ;
V_166:
if ( V_157 )
F_56 ( V_167 L_25
L_26 ,
V_89 , V_155 , V_156 , * V_54 , * V_55 , * V_56 ) ;
return;
}
static void F_58 ( struct V_134 * V_135 )
{
struct V_52 * V_53 = V_135 -> V_136 ;
struct V_147 * V_148 = & V_135 -> V_168 ;
unsigned char * V_169 = V_53 -> V_60 ;
unsigned char * V_117 = V_169 + 8 ;
int V_157 = V_135 -> V_10 -> V_61 -> V_170 == NULL ;
memset ( V_169 , 0 , V_107 ) ;
V_53 -> V_57 = ( V_58 << 24 ) | V_59 ;
if ( V_135 -> V_171 ||
V_148 -> V_150 & ( V_154 | V_172 | V_173 | V_174 ) ) {
F_57 ( V_135 -> V_10 -> V_175 , V_148 -> V_150 , V_148 -> V_152 ,
& V_169 [ 1 ] , & V_169 [ 2 ] , & V_169 [ 3 ] , V_157 ) ;
V_169 [ 1 ] &= 0x0f ;
}
V_169 [ 0 ] = 0x72 ;
V_117 [ 0 ] = 0x09 ;
V_169 [ 7 ] = 14 ;
V_117 [ 1 ] = 12 ;
V_117 [ 2 ] = 0x00 ;
V_117 [ 3 ] = V_148 -> V_152 ;
V_117 [ 5 ] = V_148 -> V_176 ;
V_117 [ 7 ] = V_148 -> V_177 ;
V_117 [ 9 ] = V_148 -> V_178 ;
V_117 [ 11 ] = V_148 -> V_179 ;
V_117 [ 12 ] = V_148 -> V_1 ;
V_117 [ 13 ] = V_148 -> V_150 ;
if ( V_148 -> V_13 & V_180 ) {
V_117 [ 2 ] |= 0x01 ;
V_117 [ 4 ] = V_148 -> V_181 ;
V_117 [ 6 ] = V_148 -> V_182 ;
V_117 [ 8 ] = V_148 -> V_183 ;
V_117 [ 10 ] = V_148 -> V_184 ;
}
}
static void F_59 ( struct V_134 * V_135 )
{
struct V_25 * V_2 = V_135 -> V_2 ;
struct V_52 * V_53 = V_135 -> V_136 ;
struct V_147 * V_148 = & V_135 -> V_168 ;
unsigned char * V_169 = V_53 -> V_60 ;
unsigned char * V_117 = V_169 + 8 ;
int V_157 = V_135 -> V_10 -> V_61 -> V_170 == NULL ;
T_7 V_185 ;
memset ( V_169 , 0 , V_107 ) ;
V_53 -> V_57 = ( V_58 << 24 ) | V_59 ;
V_169 [ 0 ] = 0x72 ;
if ( V_135 -> V_171 ||
V_148 -> V_150 & ( V_154 | V_172 | V_173 | V_174 ) ) {
F_57 ( V_135 -> V_10 -> V_175 , V_148 -> V_150 , V_148 -> V_152 ,
& V_169 [ 1 ] , & V_169 [ 2 ] , & V_169 [ 3 ] , V_157 ) ;
V_169 [ 1 ] &= 0x0f ;
}
V_185 = F_60 ( & V_135 -> V_168 , V_2 ) ;
V_169 [ 7 ] = 12 ;
V_117 [ 0 ] = 0x00 ;
V_117 [ 1 ] = 10 ;
V_117 [ 2 ] |= 0x80 ;
V_117 [ 6 ] = V_185 >> 40 ;
V_117 [ 7 ] = V_185 >> 32 ;
V_117 [ 8 ] = V_185 >> 24 ;
V_117 [ 9 ] = V_185 >> 16 ;
V_117 [ 10 ] = V_185 >> 8 ;
V_117 [ 11 ] = V_185 ;
}
static void F_61 ( struct V_21 * V_22 )
{
V_22 -> V_186 = 1 ;
V_22 -> V_187 = 1 ;
V_22 -> V_188 = 1 ;
}
static int F_62 ( struct V_144 * V_189 )
{
if ( F_63 ( V_189 -> V_190 != V_191 ) )
return 0 ;
if ( ! F_64 ( V_189 ) || ( V_189 -> V_192 & V_193 ) )
return 0 ;
return F_65 ( V_189 -> V_53 [ 0 ] ) == V_194 ;
}
static int F_66 ( struct V_21 * V_22 ,
struct V_25 * V_2 )
{
struct V_195 * V_196 = V_22 -> V_195 ;
if ( ! F_67 ( V_2 -> V_89 ) )
V_2 -> V_13 |= V_33 ;
F_68 ( V_196 , V_2 -> V_197 ) ;
if ( V_2 -> V_46 == V_198 ) {
void * V_5 ;
V_22 -> V_199 = V_110 ;
F_69 ( V_196 , V_200 - 1 ) ;
V_5 = F_39 ( V_201 , V_196 -> V_202 | V_111 ) ;
if ( ! V_5 ) {
F_70 ( V_2 , V_167 ,
L_27 ) ;
return - V_109 ;
}
F_71 ( V_196 , F_62 , V_5 , V_201 ) ;
} else {
V_22 -> V_199 = F_72 ( V_2 -> V_89 ) ;
V_22 -> V_203 = 1 ;
}
if ( V_22 -> V_199 > V_20 )
F_70 ( V_2 , V_153 ,
L_28 ,
V_22 -> V_199 ) ;
F_73 ( V_196 , V_22 -> V_199 - 1 ) ;
if ( V_2 -> V_13 & V_204 )
F_74 ( V_205 , V_22 -> V_206 ) ;
if ( V_2 -> V_13 & V_207 ) {
int V_208 ;
V_208 = F_75 ( V_22 -> V_30 -> V_209 , F_76 ( V_2 -> V_89 ) ) ;
V_208 = F_75 ( V_210 - 1 , V_208 ) ;
F_77 ( V_22 , V_211 , V_208 ) ;
}
F_78 ( V_196 , false ) ;
V_2 -> V_22 = V_22 ;
return 0 ;
}
int F_79 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_25 * V_2 = F_80 ( V_10 , V_22 ) ;
int V_29 = 0 ;
F_61 ( V_22 ) ;
if ( V_2 )
V_29 = F_66 ( V_22 , V_2 ) ;
return V_29 ;
}
void F_81 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_195 * V_196 = V_22 -> V_195 ;
unsigned long V_13 ;
struct V_25 * V_2 ;
if ( ! V_10 -> V_61 -> V_170 )
return;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 = F_80 ( V_10 , V_22 ) ;
if ( V_2 && V_2 -> V_22 ) {
V_2 -> V_22 = NULL ;
V_2 -> V_13 |= V_212 ;
F_6 ( V_10 ) ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_43 ( V_196 -> V_213 ) ;
V_196 -> V_213 = NULL ;
V_196 -> V_214 = 0 ;
}
int F_82 ( struct V_21 * V_22 , int V_215 ,
int V_216 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
struct V_25 * V_2 ;
unsigned long V_13 ;
if ( V_216 != V_217 )
return - V_34 ;
if ( V_215 < 1 || V_215 == V_22 -> V_215 )
return V_22 -> V_215 ;
V_2 = F_11 ( V_10 , V_22 ) ;
if ( ! V_2 || ! F_83 ( V_2 ) )
return V_22 -> V_215 ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 -> V_13 &= ~ V_218 ;
if ( V_215 == 1 || ! F_84 ( V_2 ) ) {
V_2 -> V_13 |= V_218 ;
V_215 = 1 ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
V_215 = F_75 ( V_215 , V_22 -> V_30 -> V_209 ) ;
V_215 = F_75 ( V_215 , F_76 ( V_2 -> V_89 ) ) ;
V_215 = F_75 ( V_215 , V_210 - 1 ) ;
if ( V_22 -> V_215 == V_215 )
return - V_17 ;
F_77 ( V_22 , V_211 , V_215 ) ;
return V_215 ;
}
static unsigned int F_85 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_147 * V_148 = & V_135 -> V_148 ;
const T_3 * V_219 = V_142 -> V_220 ;
if ( V_142 -> V_221 < 5 )
goto V_222;
V_148 -> V_13 |= V_223 | V_224 ;
V_148 -> V_225 = V_226 ;
if ( V_219 [ 1 ] & 0x1 ) {
;
}
if ( V_219 [ 4 ] & 0x2 )
goto V_222;
if ( ( ( V_219 [ 4 ] >> 4 ) & 0xf ) != 0 )
goto V_222;
if ( V_219 [ 4 ] & 0x1 ) {
V_148 -> V_176 = 1 ;
if ( V_135 -> V_2 -> V_13 & V_227 ) {
V_148 -> V_13 |= V_228 ;
V_148 -> V_179 = 0x0 ;
V_148 -> V_178 = 0x0 ;
V_148 -> V_177 = 0x0 ;
V_148 -> V_1 |= V_229 ;
} else {
V_148 -> V_177 = 0x1 ;
V_148 -> V_178 = 0x0 ;
V_148 -> V_179 = 0x0 ;
}
V_148 -> V_150 = V_230 ;
} else {
if ( ( V_135 -> V_10 -> V_13 & V_231 ) &&
V_232 == V_233 )
goto V_234;
if ( ( V_135 -> V_10 -> V_13 & V_235 ) &&
F_86 () )
goto V_234;
V_148 -> V_150 = V_236 ;
}
return 0 ;
V_222:
F_20 ( V_142 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_234:
V_142 -> V_57 = V_237 ;
return 1 ;
}
static unsigned int F_87 ( struct V_134 * V_135 )
{
struct V_147 * V_148 = & V_135 -> V_148 ;
V_148 -> V_13 |= V_223 ;
V_148 -> V_225 = V_226 ;
if ( V_135 -> V_2 -> V_13 & V_238 )
V_148 -> V_150 = V_239 ;
else
V_148 -> V_150 = V_240 ;
V_135 -> V_13 |= V_241 ;
return 0 ;
}
static void F_88 ( const T_3 * V_219 , T_7 * V_242 , T_8 * V_243 )
{
T_7 V_244 = 0 ;
T_8 V_42 ;
F_89 ( L_29 ) ;
V_244 |= ( ( T_7 ) ( V_219 [ 1 ] & 0x1f ) ) << 16 ;
V_244 |= ( ( T_7 ) V_219 [ 2 ] ) << 8 ;
V_244 |= ( ( T_7 ) V_219 [ 3 ] ) ;
V_42 = V_219 [ 4 ] ;
* V_242 = V_244 ;
* V_243 = V_42 ;
}
static void F_90 ( const T_3 * V_219 , T_7 * V_242 , T_8 * V_243 )
{
T_7 V_244 = 0 ;
T_8 V_42 = 0 ;
F_89 ( L_30 ) ;
V_244 |= ( ( T_7 ) V_219 [ 2 ] ) << 24 ;
V_244 |= ( ( T_7 ) V_219 [ 3 ] ) << 16 ;
V_244 |= ( ( T_7 ) V_219 [ 4 ] ) << 8 ;
V_244 |= ( ( T_7 ) V_219 [ 5 ] ) ;
V_42 |= ( ( T_8 ) V_219 [ 7 ] ) << 8 ;
V_42 |= ( ( T_8 ) V_219 [ 8 ] ) ;
* V_242 = V_244 ;
* V_243 = V_42 ;
}
static void F_91 ( const T_3 * V_219 , T_7 * V_242 , T_8 * V_243 )
{
T_7 V_244 = 0 ;
T_8 V_42 = 0 ;
F_89 ( L_31 ) ;
V_244 |= ( ( T_7 ) V_219 [ 2 ] ) << 56 ;
V_244 |= ( ( T_7 ) V_219 [ 3 ] ) << 48 ;
V_244 |= ( ( T_7 ) V_219 [ 4 ] ) << 40 ;
V_244 |= ( ( T_7 ) V_219 [ 5 ] ) << 32 ;
V_244 |= ( ( T_7 ) V_219 [ 6 ] ) << 24 ;
V_244 |= ( ( T_7 ) V_219 [ 7 ] ) << 16 ;
V_244 |= ( ( T_7 ) V_219 [ 8 ] ) << 8 ;
V_244 |= ( ( T_7 ) V_219 [ 9 ] ) ;
V_42 |= ( ( T_8 ) V_219 [ 10 ] ) << 24 ;
V_42 |= ( ( T_8 ) V_219 [ 11 ] ) << 16 ;
V_42 |= ( ( T_8 ) V_219 [ 12 ] ) << 8 ;
V_42 |= ( ( T_8 ) V_219 [ 13 ] ) ;
* V_242 = V_244 ;
* V_243 = V_42 ;
}
static unsigned int F_92 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_147 * V_148 = & V_135 -> V_148 ;
struct V_25 * V_2 = V_135 -> V_2 ;
T_7 V_245 = V_135 -> V_2 -> V_81 ;
const T_3 * V_219 = V_142 -> V_220 ;
T_7 V_185 ;
T_8 V_246 ;
V_148 -> V_13 |= V_224 | V_223 ;
V_148 -> V_225 = V_226 ;
if ( V_219 [ 0 ] == V_247 ) {
if ( V_142 -> V_221 < 10 )
goto V_222;
F_90 ( V_219 , & V_185 , & V_246 ) ;
} else if ( V_219 [ 0 ] == V_248 ) {
if ( V_142 -> V_221 < 16 )
goto V_222;
F_91 ( V_219 , & V_185 , & V_246 ) ;
} else
goto V_222;
if ( ! V_246 )
goto V_249;
if ( V_185 >= V_245 )
goto V_250;
if ( ( V_185 + V_246 ) > V_245 )
goto V_250;
if ( V_2 -> V_13 & V_227 ) {
V_148 -> V_13 |= V_228 ;
if ( F_93 ( V_185 , V_246 ) ) {
V_148 -> V_150 = V_230 ;
V_148 -> V_1 |= ( V_185 >> 24 ) & 0xf ;
} else if ( F_94 ( V_185 , V_246 ) ) {
if ( ! ( V_2 -> V_13 & V_251 ) )
goto V_250;
V_148 -> V_13 |= V_180 ;
V_148 -> V_150 = V_252 ;
V_148 -> V_181 = ( V_246 >> 8 ) & 0xff ;
V_148 -> V_184 = ( V_185 >> 40 ) & 0xff ;
V_148 -> V_183 = ( V_185 >> 32 ) & 0xff ;
V_148 -> V_182 = ( V_185 >> 24 ) & 0xff ;
} else
goto V_250;
V_148 -> V_176 = V_246 & 0xff ;
V_148 -> V_179 = ( V_185 >> 16 ) & 0xff ;
V_148 -> V_178 = ( V_185 >> 8 ) & 0xff ;
V_148 -> V_177 = V_185 & 0xff ;
V_148 -> V_1 |= V_229 ;
} else {
T_8 V_253 , V_254 , V_255 , V_256 ;
if ( ! F_93 ( V_185 , V_246 ) )
goto V_250;
V_256 = ( T_8 ) V_185 / V_2 -> V_257 ;
V_255 = V_256 / V_2 -> V_258 ;
V_254 = V_256 % V_2 -> V_258 ;
V_253 = ( T_8 ) V_185 % V_2 -> V_257 + 1 ;
F_95 ( L_32 ,
( T_8 ) V_185 , V_256 , V_255 , V_254 , V_253 ) ;
if ( ( V_255 >> 16 ) || ( V_254 >> 4 ) || ( V_253 >> 8 ) || ( ! V_253 ) )
goto V_250;
V_148 -> V_150 = V_230 ;
V_148 -> V_176 = V_246 & 0xff ;
V_148 -> V_177 = V_253 ;
V_148 -> V_178 = V_255 ;
V_148 -> V_179 = V_255 >> 8 ;
V_148 -> V_1 |= V_254 ;
}
return 0 ;
V_222:
F_20 ( V_142 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_250:
F_20 ( V_142 , V_75 , 0x21 , 0x0 ) ;
return 1 ;
V_249:
V_142 -> V_57 = V_237 ;
return 1 ;
}
static unsigned int F_96 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
const T_3 * V_219 = V_142 -> V_220 ;
unsigned int V_259 = 0 ;
T_7 V_185 ;
T_8 V_246 ;
int V_29 ;
if ( V_219 [ 0 ] == V_260 || V_219 [ 0 ] == V_261 || V_219 [ 0 ] == V_262 )
V_259 |= V_263 ;
switch ( V_219 [ 0 ] ) {
case V_264 :
case V_260 :
if ( F_17 ( V_142 -> V_221 < 10 ) )
goto V_222;
F_90 ( V_219 , & V_185 , & V_246 ) ;
if ( F_17 ( V_219 [ 1 ] & ( 1 << 3 ) ) )
V_259 |= V_265 ;
break;
case V_266 :
case V_261 :
if ( F_17 ( V_142 -> V_221 < 6 ) )
goto V_222;
F_88 ( V_219 , & V_185 , & V_246 ) ;
if ( ! V_246 )
V_246 = 256 ;
break;
case V_267 :
case V_262 :
if ( F_17 ( V_142 -> V_221 < 16 ) )
goto V_222;
F_91 ( V_219 , & V_185 , & V_246 ) ;
if ( F_17 ( V_219 [ 1 ] & ( 1 << 3 ) ) )
V_259 |= V_265 ;
break;
default:
F_95 ( L_33 ) ;
goto V_222;
}
if ( ! V_246 )
goto V_249;
V_135 -> V_13 |= V_241 ;
V_135 -> V_146 = V_246 * V_142 -> V_1 -> V_199 ;
V_29 = F_97 ( & V_135 -> V_148 , V_135 -> V_2 , V_185 , V_246 , V_259 ,
V_135 -> V_268 ) ;
if ( F_63 ( V_29 == 0 ) )
return 0 ;
if ( V_29 == - V_269 )
goto V_250;
V_222:
F_20 ( V_142 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_250:
F_20 ( V_142 , V_75 , 0x21 , 0x0 ) ;
return 1 ;
V_249:
V_142 -> V_57 = V_237 ;
return 1 ;
}
static void F_98 ( struct V_134 * V_135 )
{
struct V_9 * V_10 = V_135 -> V_10 ;
struct V_52 * V_53 = V_135 -> V_136 ;
T_3 * V_219 = V_53 -> V_220 ;
int V_270 = ( V_135 -> V_171 != 0 ) ;
if ( ( ( V_219 [ 0 ] == V_114 ) || ( V_219 [ 0 ] == V_271 ) ) &&
( ( V_219 [ 2 ] & 0x20 ) || V_270 ) ) {
F_58 ( V_135 ) ;
} else {
if ( ! V_270 ) {
V_53 -> V_57 = V_237 ;
} else {
F_59 ( V_135 ) ;
}
}
if ( V_270 && ! V_10 -> V_61 -> V_170 )
F_55 ( V_10 -> V_175 , & V_135 -> V_168 ) ;
V_135 -> V_137 ( V_53 ) ;
F_99 ( V_135 ) ;
}
static int F_100 ( struct V_25 * V_2 , struct V_52 * V_53 ,
T_9 V_272 )
{
struct V_9 * V_10 = V_2 -> V_24 -> V_10 ;
struct V_134 * V_135 ;
int V_29 ;
F_89 ( L_34 ) ;
V_135 = F_49 ( V_2 , V_53 ) ;
if ( ! V_135 )
goto V_273;
if ( V_53 -> V_274 == V_112 ||
V_53 -> V_274 == V_275 ) {
if ( F_17 ( F_54 ( V_53 ) < 1 ) ) {
F_70 ( V_2 , V_153 ,
L_35 ) ;
goto V_276;
}
F_101 ( V_135 , F_51 ( V_53 ) , F_52 ( V_53 ) ) ;
V_135 -> V_277 = V_53 -> V_274 ;
}
V_135 -> V_278 = F_98 ;
if ( V_272 ( V_135 ) )
goto V_279;
if ( V_10 -> V_61 -> V_280 ) {
if ( ( V_29 = V_10 -> V_61 -> V_280 ( V_135 ) ) )
goto V_281;
}
F_102 ( V_135 ) ;
F_89 ( L_36 ) ;
return 0 ;
V_279:
F_99 ( V_135 ) ;
V_53 -> V_76 ( V_53 ) ;
F_95 ( L_37 ) ;
return 0 ;
V_276:
F_99 ( V_135 ) ;
V_53 -> V_57 = ( V_282 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
V_273:
F_95 ( L_38 ) ;
return 0 ;
V_281:
F_99 ( V_135 ) ;
F_95 ( L_39 ) ;
if ( V_29 == V_283 )
return V_284 ;
else
return V_285 ;
}
static void * F_103 ( struct V_52 * V_53 , bool V_286 ,
unsigned long * V_13 )
{
F_5 ( & V_287 , * V_13 ) ;
memset ( V_288 , 0 , V_289 ) ;
if ( V_286 )
F_104 ( F_51 ( V_53 ) , F_52 ( V_53 ) ,
V_288 , V_289 ) ;
return V_288 ;
}
static inline void F_105 ( struct V_52 * V_53 , bool V_290 ,
unsigned long * V_13 )
{
if ( V_290 )
F_106 ( F_51 ( V_53 ) , F_52 ( V_53 ) ,
V_288 , V_289 ) ;
F_7 ( & V_287 , * V_13 ) ;
}
static unsigned int F_107 ( struct V_291 * args , T_3 * V_292 )
{
const T_3 V_293 [] = {
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
T_3 V_294 [] = {
V_295 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_89 ( L_34 ) ;
if ( F_108 ( args -> V_89 ) )
V_294 [ 1 ] |= ( 1 << 7 ) ;
memcpy ( V_292 , V_294 , sizeof( V_294 ) ) ;
memcpy ( & V_292 [ 8 ] , L_40 , 8 ) ;
F_35 ( args -> V_89 , & V_292 [ 16 ] , V_92 , 16 ) ;
F_35 ( args -> V_89 , & V_292 [ 32 ] , V_94 , 4 ) ;
if ( V_292 [ 32 ] == 0 || V_292 [ 32 ] == ' ' )
memcpy ( & V_292 [ 32 ] , L_41 , 4 ) ;
memcpy ( V_292 + 59 , V_293 , sizeof( V_293 ) ) ;
return 0 ;
}
static unsigned int F_109 ( struct V_291 * args , T_3 * V_292 )
{
const T_3 V_296 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
} ;
V_292 [ 3 ] = sizeof( V_296 ) ;
memcpy ( V_292 + 4 , V_296 , sizeof( V_296 ) ) ;
return 0 ;
}
static unsigned int F_110 ( struct V_291 * args , T_3 * V_292 )
{
const T_3 V_294 [] = {
0 ,
0x80 ,
0 ,
V_97 ,
} ;
memcpy ( V_292 , V_294 , sizeof( V_294 ) ) ;
F_35 ( args -> V_89 , ( unsigned char * ) & V_292 [ 4 ] ,
V_96 , V_97 ) ;
return 0 ;
}
static unsigned int F_111 ( struct V_291 * args , T_3 * V_292 )
{
const int V_297 = 68 ;
int V_298 ;
V_292 [ 1 ] = 0x83 ;
V_298 = 4 ;
V_292 [ V_298 + 0 ] = 2 ;
V_292 [ V_298 + 3 ] = V_97 ;
V_298 += 4 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_292 + V_298 ,
V_96 , V_97 ) ;
V_298 += V_97 ;
V_292 [ V_298 + 0 ] = 2 ;
V_292 [ V_298 + 1 ] = 1 ;
V_292 [ V_298 + 3 ] = V_297 ;
V_298 += 4 ;
memcpy ( V_292 + V_298 , L_40 , 8 ) ;
V_298 += 8 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_292 + V_298 , V_92 ,
V_93 ) ;
V_298 += V_93 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_292 + V_298 , V_96 ,
V_97 ) ;
V_298 += V_97 ;
if ( F_112 ( args -> V_89 ) ) {
V_292 [ V_298 + 0 ] = 1 ;
V_292 [ V_298 + 1 ] = 3 ;
V_292 [ V_298 + 3 ] = V_299 ;
V_298 += 4 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_292 + V_298 ,
V_300 , V_299 ) ;
V_298 += V_299 ;
}
V_292 [ 3 ] = V_298 - 4 ;
return 0 ;
}
static unsigned int F_113 ( struct V_291 * args , T_3 * V_292 )
{
struct V_147 V_148 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_292 [ 1 ] = 0x89 ;
V_292 [ 2 ] = ( 0x238 >> 8 ) ;
V_292 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_292 [ 8 ] , L_42 , 8 ) ;
memcpy ( & V_292 [ 16 ] , L_43 , 16 ) ;
memcpy ( & V_292 [ 32 ] , V_301 , 4 ) ;
F_35 ( args -> V_89 , & V_292 [ 32 ] , V_94 , 4 ) ;
V_148 . V_150 = V_302 ;
V_148 . V_177 = 0x1 ;
V_148 . V_176 = 0x1 ;
F_114 ( & V_148 , 0 , 1 , & V_292 [ 36 ] ) ;
V_292 [ 36 ] = 0x34 ;
V_292 [ 56 ] = V_303 ;
memcpy ( & V_292 [ 60 ] , & args -> V_89 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_115 ( struct V_291 * args , T_3 * V_292 )
{
T_6 V_304 ;
V_292 [ 1 ] = 0xb0 ;
V_292 [ 3 ] = 0x3c ;
V_304 = 1 << F_116 ( args -> V_89 ) ;
F_117 ( V_304 , & V_292 [ 6 ] ) ;
if ( F_118 ( args -> V_89 ) ) {
F_119 ( 65535 * 512 / 8 , & V_292 [ 36 ] ) ;
F_120 ( 1 , & V_292 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_121 ( struct V_291 * args , T_3 * V_292 )
{
int V_305 = F_122 ( args -> V_89 ) ;
int V_306 = F_123 ( args -> V_89 ) ;
V_292 [ 1 ] = 0xb1 ;
V_292 [ 3 ] = 0x3c ;
V_292 [ 4 ] = V_306 >> 8 ;
V_292 [ 5 ] = V_306 ;
V_292 [ 7 ] = V_305 ;
return 0 ;
}
static unsigned int F_124 ( struct V_291 * args , T_3 * V_292 )
{
V_292 [ 1 ] = 0xb2 ;
V_292 [ 3 ] = 0x4 ;
V_292 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_125 ( struct V_291 * args , T_3 * V_292 )
{
F_89 ( L_34 ) ;
return 0 ;
}
static unsigned int F_126 ( T_6 * V_89 , T_3 * V_5 )
{
memcpy ( V_5 , V_307 , sizeof( V_307 ) ) ;
if ( F_127 ( V_89 ) )
V_5 [ 2 ] |= ( 1 << 2 ) ;
if ( ! F_128 ( V_89 ) )
V_5 [ 12 ] |= ( 1 << 5 ) ;
return sizeof( V_307 ) ;
}
static unsigned int F_129 ( T_3 * V_5 )
{
memcpy ( V_5 , V_308 , sizeof( V_308 ) ) ;
return sizeof( V_308 ) ;
}
static unsigned int F_130 ( T_3 * V_5 )
{
memcpy ( V_5 , V_309 , sizeof( V_309 ) ) ;
return sizeof( V_309 ) ;
}
static int F_131 ( T_6 * V_89 )
{
unsigned char V_310 [ V_93 + 1 ] , V_311 [ V_95 + 1 ] ;
if ( ! V_312 )
return 0 ;
if ( ! F_132 ( V_89 ) )
return 0 ;
F_133 ( V_89 , V_310 , V_92 , sizeof( V_310 ) ) ;
F_133 ( V_89 , V_311 , V_94 , sizeof( V_311 ) ) ;
if ( strcmp ( V_310 , L_44 ) )
return 1 ;
if ( strcmp ( V_311 , L_45 ) )
return 1 ;
return 0 ;
}
static unsigned int F_134 ( struct V_291 * args , T_3 * V_292 )
{
struct V_25 * V_2 = args -> V_2 ;
T_3 * V_136 = args -> V_53 -> V_220 , * V_313 = V_292 ;
const T_3 V_314 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_315 , V_316 ;
unsigned int V_317 , V_318 , V_319 ;
T_3 V_320 ;
F_89 ( L_34 ) ;
V_319 = ( V_136 [ 0 ] == V_321 ) ;
V_317 = ! ( V_136 [ 1 ] & 0x8 ) ;
V_318 = V_136 [ 2 ] >> 6 ;
switch ( V_318 ) {
case 0 :
break;
case 3 :
goto V_322;
case 1 :
case 2 :
default:
goto V_222;
}
if ( V_319 )
V_313 += 4 + ( V_317 ? 8 : 0 ) ;
else
V_313 += 8 + ( V_317 ? 8 : 0 ) ;
V_315 = V_136 [ 2 ] & 0x3f ;
V_316 = V_136 [ 3 ] ;
if ( V_316 && ( V_316 != V_323 ) )
goto V_222;
switch( V_315 ) {
case V_324 :
V_313 += F_130 ( V_313 ) ;
break;
case V_325 :
V_313 += F_126 ( args -> V_89 , V_313 ) ;
break;
case V_326 :
V_313 += F_129 ( V_313 ) ;
break;
case V_327 :
V_313 += F_130 ( V_313 ) ;
V_313 += F_126 ( args -> V_89 , V_313 ) ;
V_313 += F_129 ( V_313 ) ;
break;
default:
goto V_222;
}
V_320 = 0 ;
if ( F_131 ( args -> V_89 ) && ( V_2 -> V_13 & V_251 ) &&
( ! ( V_2 -> V_13 & V_328 ) || V_2 -> V_329 ) )
V_320 = 1 << 4 ;
if ( V_319 ) {
V_292 [ 0 ] = V_313 - V_292 - 1 ;
V_292 [ 2 ] |= V_320 ;
if ( V_317 ) {
V_292 [ 3 ] = sizeof( V_314 ) ;
memcpy ( V_292 + 4 , V_314 , sizeof( V_314 ) ) ;
}
} else {
unsigned int V_330 = V_313 - V_292 - 2 ;
V_292 [ 0 ] = V_330 >> 8 ;
V_292 [ 1 ] = V_330 ;
V_292 [ 3 ] |= V_320 ;
if ( V_317 ) {
V_292 [ 7 ] = sizeof( V_314 ) ;
memcpy ( V_292 + 8 , V_314 , sizeof( V_314 ) ) ;
}
}
return 0 ;
V_222:
F_20 ( args -> V_53 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_322:
F_20 ( args -> V_53 , V_75 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_135 ( struct V_291 * args , T_3 * V_292 )
{
struct V_25 * V_2 = args -> V_2 ;
T_7 V_331 = V_2 -> V_81 - 1 ;
T_8 V_199 ;
T_3 V_332 ;
T_6 V_333 ;
V_199 = F_72 ( V_2 -> V_89 ) ;
V_332 = F_116 ( V_2 -> V_89 ) ;
V_333 = F_136 ( V_2 -> V_89 , V_332 ) ;
F_89 ( L_34 ) ;
if ( args -> V_53 -> V_220 [ 0 ] == V_334 ) {
if ( V_331 >= 0xffffffffULL )
V_331 = 0xffffffff ;
V_292 [ 0 ] = V_331 >> ( 8 * 3 ) ;
V_292 [ 1 ] = V_331 >> ( 8 * 2 ) ;
V_292 [ 2 ] = V_331 >> ( 8 * 1 ) ;
V_292 [ 3 ] = V_331 ;
V_292 [ 4 ] = V_199 >> ( 8 * 3 ) ;
V_292 [ 5 ] = V_199 >> ( 8 * 2 ) ;
V_292 [ 6 ] = V_199 >> ( 8 * 1 ) ;
V_292 [ 7 ] = V_199 ;
} else {
V_292 [ 0 ] = V_331 >> ( 8 * 7 ) ;
V_292 [ 1 ] = V_331 >> ( 8 * 6 ) ;
V_292 [ 2 ] = V_331 >> ( 8 * 5 ) ;
V_292 [ 3 ] = V_331 >> ( 8 * 4 ) ;
V_292 [ 4 ] = V_331 >> ( 8 * 3 ) ;
V_292 [ 5 ] = V_331 >> ( 8 * 2 ) ;
V_292 [ 6 ] = V_331 >> ( 8 * 1 ) ;
V_292 [ 7 ] = V_331 ;
V_292 [ 8 ] = V_199 >> ( 8 * 3 ) ;
V_292 [ 9 ] = V_199 >> ( 8 * 2 ) ;
V_292 [ 10 ] = V_199 >> ( 8 * 1 ) ;
V_292 [ 11 ] = V_199 ;
V_292 [ 12 ] = 0 ;
V_292 [ 13 ] = V_332 ;
V_292 [ 14 ] = ( V_333 >> 8 ) & 0x3f ;
V_292 [ 15 ] = V_333 ;
if ( F_118 ( args -> V_89 ) ) {
V_292 [ 14 ] |= 0x80 ;
if ( F_137 ( args -> V_89 ) )
V_292 [ 14 ] |= 0x40 ;
}
}
return 0 ;
}
static unsigned int F_138 ( struct V_291 * args , T_3 * V_292 )
{
F_89 ( L_34 ) ;
V_292 [ 3 ] = 8 ;
return 0 ;
}
static void F_139 ( struct V_134 * V_135 )
{
if ( V_135 -> V_171 && ( ( V_135 -> V_171 & V_335 ) == 0 ) ) {
F_58 ( V_135 ) ;
}
V_135 -> V_137 ( V_135 -> V_136 ) ;
F_99 ( V_135 ) ;
}
static inline int F_140 ( struct V_9 * V_10 )
{
return ( V_10 -> V_13 & V_122 ) ;
}
static void F_141 ( struct V_134 * V_135 )
{
struct V_9 * V_10 = V_135 -> V_10 ;
struct V_52 * V_53 = V_135 -> V_136 ;
F_95 ( L_46 ) ;
memset ( V_53 -> V_60 , 0 , V_107 ) ;
#ifdef F_142
if ( V_10 -> V_61 -> V_336 )
V_10 -> V_61 -> V_336 ( V_10 , & V_135 -> V_148 ) ;
#endif
V_53 -> V_60 [ 0 ] = 0x70 ;
V_53 -> V_60 [ 2 ] = V_135 -> V_148 . V_152 >> 4 ;
F_143 ( V_135 ) ;
F_144 ( & V_135 -> V_337 , V_53 -> V_60 , V_107 ) ;
F_101 ( V_135 , & V_135 -> V_337 , 1 ) ;
V_135 -> V_277 = V_112 ;
memset ( & V_135 -> V_219 , 0 , V_135 -> V_2 -> V_338 ) ;
V_135 -> V_219 [ 0 ] = V_339 ;
V_135 -> V_219 [ 4 ] = V_107 ;
V_135 -> V_148 . V_13 |= V_224 | V_223 ;
V_135 -> V_148 . V_150 = V_340 ;
if ( F_140 ( V_10 ) ) {
V_135 -> V_148 . V_225 = V_341 ;
V_135 -> V_148 . V_152 |= V_342 ;
} else {
V_135 -> V_148 . V_225 = V_343 ;
V_135 -> V_148 . V_178 = V_107 ;
V_135 -> V_148 . V_179 = 0 ;
}
V_135 -> V_146 = V_107 ;
V_135 -> V_278 = F_139 ;
F_102 ( V_135 ) ;
F_95 ( L_36 ) ;
}
static void F_145 ( struct V_134 * V_135 )
{
struct V_52 * V_53 = V_135 -> V_136 ;
unsigned int V_171 = V_135 -> V_171 ;
F_89 ( L_47 , V_171 ) ;
if ( F_17 ( V_135 -> V_10 -> V_61 -> V_170 &&
( V_171 || V_135 -> V_13 & V_344 ) ) ) {
if ( ! ( V_135 -> V_13 & V_344 ) ) {
F_58 ( V_135 ) ;
}
if ( V_135 -> V_219 [ 0 ] == V_345 && V_135 -> V_2 -> V_22 )
V_135 -> V_2 -> V_22 -> V_346 = 0 ;
V_135 -> V_136 -> V_57 = V_59 ;
V_135 -> V_137 ( V_53 ) ;
F_99 ( V_135 ) ;
return;
}
if ( F_17 ( V_171 & V_335 ) ) {
V_53 -> V_57 = V_59 ;
F_141 ( V_135 ) ;
return;
} else if ( F_17 ( V_171 ) ) {
F_58 ( V_135 ) ;
} else {
T_3 * V_136 = V_53 -> V_220 ;
if ( ( V_136 [ 0 ] == V_347 ) && ( ( V_136 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_13 ;
T_3 * V_5 ;
V_5 = F_103 ( V_53 , true , & V_13 ) ;
if ( V_5 [ 2 ] == 0 ) {
V_5 [ 2 ] = 0x5 ;
V_5 [ 3 ] = 0x32 ;
}
F_105 ( V_53 , true , & V_13 ) ;
}
V_53 -> V_57 = V_237 ;
}
V_135 -> V_137 ( V_53 ) ;
F_99 ( V_135 ) ;
}
static unsigned int F_146 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_25 * V_2 = V_135 -> V_2 ;
int V_348 = ( V_142 -> V_274 == V_113 ) ;
int V_349 = ! V_348 && ( V_2 -> V_13 & V_328 ) ;
unsigned int V_146 ;
memset ( V_135 -> V_219 , 0 , V_2 -> V_338 ) ;
memcpy ( V_135 -> V_219 , V_142 -> V_220 , V_142 -> V_221 ) ;
V_135 -> V_278 = F_145 ;
V_135 -> V_148 . V_13 |= V_224 | V_223 ;
if ( V_142 -> V_274 == V_275 ) {
V_135 -> V_148 . V_13 |= V_263 ;
F_95 ( L_48 ) ;
}
V_135 -> V_148 . V_150 = V_340 ;
F_53 ( V_135 ) ;
if ( ! V_348 && ! V_349 && F_147 ( V_135 ) )
V_349 = 1 ;
V_146 = F_75 ( F_148 ( V_135 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_146 & 0x1 )
V_146 ++ ;
V_135 -> V_148 . V_178 = ( V_146 & 0xFF ) ;
V_135 -> V_148 . V_179 = ( V_146 >> 8 ) ;
if ( V_348 )
V_135 -> V_148 . V_225 = V_350 ;
else if ( V_349 )
V_135 -> V_148 . V_225 = V_343 ;
else {
V_135 -> V_148 . V_225 = V_341 ;
V_135 -> V_148 . V_152 |= V_342 ;
if ( ( V_2 -> V_13 & V_351 ) &&
( V_142 -> V_274 != V_275 ) )
V_135 -> V_148 . V_152 |= V_352 ;
}
return 0 ;
}
static struct V_25 * F_149 ( struct V_9 * V_10 , int V_40 )
{
if ( ! F_150 ( V_10 ) ) {
if ( F_63 ( V_40 < F_151 ( & V_10 -> V_24 ) ) )
return & V_10 -> V_24 . V_1 [ V_40 ] ;
} else {
if ( F_63 ( V_40 < V_10 -> V_353 ) )
return & V_10 -> V_354 [ V_40 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_25 * F_80 ( struct V_9 * V_10 ,
const struct V_21 * V_98 )
{
int V_40 ;
if ( ! F_150 ( V_10 ) ) {
if ( F_17 ( V_98 -> V_355 || V_98 -> V_356 ) )
return NULL ;
V_40 = V_98 -> V_89 ;
} else {
if ( F_17 ( V_98 -> V_89 || V_98 -> V_356 ) )
return NULL ;
V_40 = V_98 -> V_355 ;
}
return F_149 ( V_10 , V_40 ) ;
}
static struct V_25 *
F_11 ( struct V_9 * V_10 , const struct V_21 * V_98 )
{
struct V_25 * V_2 = F_80 ( V_10 , V_98 ) ;
if ( F_17 ( ! V_2 || ! F_83 ( V_2 ) ) )
return NULL ;
return V_2 ;
}
static T_3
F_152 ( T_3 V_357 )
{
switch( ( V_357 & 0x1e ) >> 1 ) {
case 3 :
return V_226 ;
case 6 :
case 10 :
case 11 :
return V_358 ;
case 4 :
case 5 :
return V_359 ;
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
return V_360 ;
}
static unsigned int F_153 ( struct V_134 * V_135 )
{
struct V_147 * V_148 = & ( V_135 -> V_148 ) ;
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_25 * V_2 = V_135 -> V_2 ;
const T_3 * V_219 = V_142 -> V_220 ;
if ( ( V_148 -> V_225 = F_152 ( V_219 [ 1 ] ) ) == V_360 )
goto V_222;
if ( V_219 [ 0 ] == V_114 ) {
if ( V_219 [ 1 ] & 0x01 ) {
V_148 -> V_361 = V_219 [ 3 ] ;
V_148 -> V_181 = V_219 [ 5 ] ;
V_148 -> V_182 = V_219 [ 7 ] ;
V_148 -> V_183 = V_219 [ 9 ] ;
V_148 -> V_184 = V_219 [ 11 ] ;
V_148 -> V_13 |= V_180 ;
} else
V_148 -> V_13 &= ~ V_180 ;
V_148 -> V_152 = V_219 [ 4 ] ;
V_148 -> V_176 = V_219 [ 6 ] ;
V_148 -> V_177 = V_219 [ 8 ] ;
V_148 -> V_178 = V_219 [ 10 ] ;
V_148 -> V_179 = V_219 [ 12 ] ;
V_148 -> V_1 = V_219 [ 13 ] ;
V_148 -> V_150 = V_219 [ 14 ] ;
} else {
V_148 -> V_13 &= ~ V_180 ;
V_148 -> V_152 = V_219 [ 3 ] ;
V_148 -> V_176 = V_219 [ 4 ] ;
V_148 -> V_177 = V_219 [ 5 ] ;
V_148 -> V_178 = V_219 [ 6 ] ;
V_148 -> V_179 = V_219 [ 7 ] ;
V_148 -> V_1 = V_219 [ 8 ] ;
V_148 -> V_150 = V_219 [ 9 ] ;
}
V_148 -> V_1 = V_2 -> V_40 ?
V_148 -> V_1 | V_362 : V_148 -> V_1 & ~ V_362 ;
switch ( V_148 -> V_150 ) {
case V_363 :
case V_364 :
case V_365 :
case V_366 :
if ( V_148 -> V_225 != V_359 || V_148 -> V_176 != 1 )
goto V_222;
V_135 -> V_367 = F_54 ( V_142 ) ;
break;
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_230 :
case V_252 :
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
case V_391 :
case V_392 :
case V_393 :
V_135 -> V_367 = V_142 -> V_1 -> V_199 ;
break;
default:
V_135 -> V_367 = V_110 ;
}
V_148 -> V_13 |= V_224 | V_223 ;
if ( V_142 -> V_274 == V_275 )
V_148 -> V_13 |= V_263 ;
V_135 -> V_13 |= V_394 | V_395 ;
F_53 ( V_135 ) ;
if ( V_148 -> V_225 == V_358 && V_2 -> V_396 == 0 )
goto V_222;
if ( ( V_219 [ 1 ] & 0xe0 ) && ! F_154 ( V_148 ) )
goto V_222;
if ( F_154 ( V_148 ) ) {
unsigned int V_329 = 1 << ( V_219 [ 1 ] >> 5 ) ;
if ( V_329 != V_2 -> V_329 )
F_70 ( V_2 , V_153 ,
L_49 ,
V_329 ) ;
}
if ( V_148 -> V_150 == V_397 &&
V_148 -> V_152 == V_398 )
goto V_222;
if ( V_148 -> V_150 >= 0x5C && V_148 -> V_150 <= 0x5F && ! V_399 )
goto V_222;
return 0 ;
V_222:
F_20 ( V_142 , V_75 , 0x24 , 0x00 ) ;
return 1 ;
}
static unsigned int F_155 ( struct V_134 * V_135 )
{
struct V_147 * V_148 = & V_135 -> V_148 ;
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_25 * V_2 = V_135 -> V_2 ;
const T_3 * V_219 = V_142 -> V_220 ;
T_7 V_185 ;
T_8 V_246 ;
T_8 V_400 ;
void * V_5 ;
if ( F_17 ( ! V_2 -> V_396 ) )
goto V_222;
if ( F_17 ( V_142 -> V_221 < 16 ) )
goto V_222;
F_91 ( V_219 , & V_185 , & V_246 ) ;
if ( F_17 ( ! ( V_219 [ 1 ] & 0x8 ) ) )
goto V_222;
if ( ! F_52 ( V_142 ) )
goto V_222;
V_5 = F_156 ( F_157 ( F_51 ( V_142 ) ) ) ;
V_400 = F_158 ( V_5 , 512 , V_185 , V_246 ) ;
V_148 -> V_225 = V_358 ;
V_148 -> V_361 = 0 ;
V_148 -> V_152 = V_401 ;
V_148 -> V_181 = ( V_400 / 512 ) >> 8 ;
V_148 -> V_176 = V_400 / 512 ;
V_148 -> V_150 = V_402 ;
V_148 -> V_13 |= V_224 | V_223 | V_180 |
V_263 ;
F_53 ( V_135 ) ;
return 0 ;
V_222:
F_20 ( V_142 , V_75 , 0x24 , 0x00 ) ;
return 1 ;
}
static inline T_9 F_159 ( struct V_25 * V_2 , T_3 V_53 )
{
switch ( V_53 ) {
case V_266 :
case V_264 :
case V_267 :
case V_261 :
case V_260 :
case V_262 :
return F_96 ;
case V_403 :
return F_155 ;
case V_404 :
if ( F_160 ( V_2 ) )
return F_87 ;
break;
case V_247 :
case V_248 :
return F_92 ;
case V_271 :
case V_114 :
return F_153 ;
case V_405 :
return F_85 ;
}
return NULL ;
}
static inline void F_161 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
#ifdef F_162
struct V_21 * V_98 = V_53 -> V_1 ;
T_3 * V_136 = V_53 -> V_220 ;
F_95 ( L_50 ,
V_10 -> V_175 ,
V_98 -> V_355 , V_98 -> V_89 , V_98 -> V_356 ,
V_136 [ 0 ] , V_136 [ 1 ] , V_136 [ 2 ] , V_136 [ 3 ] ,
V_136 [ 4 ] , V_136 [ 5 ] , V_136 [ 6 ] , V_136 [ 7 ] ,
V_136 [ 8 ] ) ;
#endif
}
static inline int F_163 ( struct V_52 * V_142 ,
struct V_25 * V_2 )
{
T_3 V_406 = V_142 -> V_220 [ 0 ] ;
T_9 V_272 ;
int V_29 = 0 ;
if ( V_2 -> V_46 == V_47 ) {
if ( F_17 ( ! V_142 -> V_221 || V_142 -> V_221 > V_2 -> V_338 ) )
goto V_407;
V_272 = F_159 ( V_2 , V_406 ) ;
} else {
if ( F_17 ( ! V_142 -> V_221 ) )
goto V_407;
V_272 = NULL ;
if ( F_63 ( ( V_406 != V_114 ) || ! V_408 ) ) {
int V_42 = F_164 ( V_406 ) ;
if ( F_17 ( V_42 > V_142 -> V_221 || V_42 > V_2 -> V_338 ) )
goto V_407;
V_272 = F_146 ;
} else {
if ( F_17 ( V_142 -> V_221 > 16 ) )
goto V_407;
V_272 = F_159 ( V_2 , V_406 ) ;
}
}
if ( V_272 )
V_29 = F_100 ( V_2 , V_142 , V_272 ) ;
else
F_165 ( V_2 , V_142 ) ;
return V_29 ;
V_407:
F_95 ( L_51 ,
V_142 -> V_221 , V_406 , V_2 -> V_338 ) ;
V_142 -> V_57 = V_282 << 16 ;
V_142 -> V_76 ( V_142 ) ;
return 0 ;
}
int F_166 ( struct V_7 * V_8 , struct V_52 * V_53 )
{
struct V_9 * V_10 ;
struct V_25 * V_2 ;
struct V_21 * V_98 = V_53 -> V_1 ;
int V_29 = 0 ;
unsigned long V_409 ;
V_10 = F_3 ( V_8 ) ;
F_5 ( V_10 -> V_18 , V_409 ) ;
F_161 ( V_10 , V_53 ) ;
V_2 = F_11 ( V_10 , V_98 ) ;
if ( F_63 ( V_2 ) )
V_29 = F_163 ( V_53 , V_2 ) ;
else {
V_53 -> V_57 = ( V_410 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
}
F_7 ( V_10 -> V_18 , V_409 ) ;
return V_29 ;
}
void F_165 ( struct V_25 * V_2 , struct V_52 * V_53 )
{
struct V_291 args ;
const T_3 * V_136 = V_53 -> V_220 ;
T_3 V_411 ;
args . V_2 = V_2 ;
args . V_89 = V_2 -> V_89 ;
args . V_53 = V_53 ;
args . V_412 = V_53 -> V_76 ;
switch( V_136 [ 0 ] ) {
case V_413 :
F_28 ( V_53 ) ;
break;
case V_347 :
if ( V_136 [ 1 ] & 2 )
F_28 ( V_53 ) ;
else if ( ( V_136 [ 1 ] & 1 ) == 0 )
F_167 ( & args , F_107 ) ;
else switch ( V_136 [ 2 ] ) {
case 0x00 :
F_167 ( & args , F_109 ) ;
break;
case 0x80 :
F_167 ( & args , F_110 ) ;
break;
case 0x83 :
F_167 ( & args , F_111 ) ;
break;
case 0x89 :
F_167 ( & args , F_113 ) ;
break;
case 0xb0 :
F_167 ( & args , F_115 ) ;
break;
case 0xb1 :
F_167 ( & args , F_121 ) ;
break;
case 0xb2 :
F_167 ( & args , F_124 ) ;
break;
default:
F_28 ( V_53 ) ;
break;
}
break;
case V_321 :
case V_414 :
F_167 ( & args , F_134 ) ;
break;
case V_415 :
case V_416 :
F_28 ( V_53 ) ;
break;
case V_334 :
F_167 ( & args , F_135 ) ;
break;
case V_417 :
if ( ( V_136 [ 1 ] & 0x1f ) == V_418 )
F_167 ( & args , F_135 ) ;
else
F_28 ( V_53 ) ;
break;
case V_419 :
F_167 ( & args , F_138 ) ;
break;
case V_339 :
F_20 ( V_53 , 0 , 0 , 0 ) ;
V_53 -> V_57 = ( V_58 << 24 ) ;
V_53 -> V_76 ( V_53 ) ;
break;
case V_404 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
F_167 ( & args , F_125 ) ;
break;
case V_424 :
V_411 = V_136 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_411 == 0x4 ) && ( ! V_136 [ 3 ] ) && ( ! V_136 [ 4 ] ) )
F_167 ( & args , F_125 ) ;
else
F_28 ( V_53 ) ;
break;
default:
F_20 ( V_53 , V_75 , 0x20 , 0x0 ) ;
V_53 -> V_76 ( V_53 ) ;
break;
}
}
int F_168 ( struct V_425 * V_30 , struct V_426 * V_427 )
{
int V_158 , V_29 ;
for ( V_158 = 0 ; V_158 < V_30 -> V_428 ; V_158 ++ ) {
struct V_9 * V_10 = V_30 -> V_429 [ V_158 ] ;
struct V_7 * V_8 ;
V_29 = - V_109 ;
V_8 = F_169 ( V_427 , sizeof( struct V_9 * ) ) ;
if ( ! V_8 )
goto V_430;
* (struct V_9 * * ) & V_8 -> V_431 [ 0 ] = V_10 ;
V_10 -> V_432 = V_8 ;
V_8 -> V_433 = V_434 ;
V_8 -> V_435 = V_10 -> V_175 ;
V_8 -> V_436 = 16 ;
V_8 -> V_437 = 1 ;
V_8 -> V_438 = 1 ;
V_8 -> V_439 = 16 ;
V_8 -> V_440 = 1 ;
V_29 = F_170 ( V_10 -> V_432 , V_10 -> V_30 -> V_2 ) ;
if ( V_29 )
goto V_441;
}
return 0 ;
V_441:
F_171 ( V_30 -> V_429 [ V_158 ] -> V_432 ) ;
V_430:
while ( -- V_158 >= 0 ) {
struct V_7 * V_8 = V_30 -> V_429 [ V_158 ] -> V_432 ;
F_172 ( V_8 ) ;
F_171 ( V_8 ) ;
}
return V_29 ;
}
void F_173 ( struct V_9 * V_10 , int V_442 )
{
int V_443 = 5 ;
struct V_25 * V_444 = NULL ;
struct V_23 * V_24 ;
struct V_25 * V_2 ;
V_445:
F_174 (link, ap, EDGE) {
F_175 (dev, link, ENABLED) {
struct V_21 * V_22 ;
int V_355 = 0 , V_89 = 0 ;
if ( V_2 -> V_22 )
continue;
if ( F_176 ( V_24 ) )
V_89 = V_2 -> V_40 ;
else
V_355 = V_24 -> V_446 ;
V_22 = F_177 ( V_10 -> V_432 , V_355 , V_89 , 0 ,
NULL ) ;
if ( ! F_178 ( V_22 ) ) {
V_2 -> V_22 = V_22 ;
F_179 ( V_22 ) ;
} else {
V_2 -> V_22 = NULL ;
}
}
}
F_174 (link, ap, EDGE) {
F_175 (dev, link, ENABLED) {
if ( ! V_2 -> V_22 )
goto V_447;
}
}
V_447:
if ( ! V_24 )
return;
if ( V_442 ) {
if ( V_2 != V_444 ) {
F_180 ( 100 ) ;
V_444 = V_2 ;
goto V_445;
}
if ( -- V_443 ) {
F_180 ( 100 ) ;
goto V_445;
}
F_181 ( V_10 , V_167 , L_52
L_53
L_54 ) ;
}
F_182 ( V_448 , & V_10 -> V_449 ,
F_183 ( V_116 ) ) ;
}
int F_184 ( struct V_25 * V_2 )
{
if ( V_2 -> V_22 ) {
F_185 ( V_2 -> V_22 , V_450 ) ;
return 1 ;
}
return 0 ;
}
static void F_186 ( struct V_25 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_24 -> V_10 ;
struct V_21 * V_22 ;
unsigned long V_13 ;
F_187 ( & V_10 -> V_432 -> V_451 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_22 = V_2 -> V_22 ;
V_2 -> V_22 = NULL ;
if ( V_22 ) {
if ( F_188 ( V_22 ) == 0 ) {
F_185 ( V_22 , V_450 ) ;
} else {
F_189 ( 1 ) ;
V_22 = NULL ;
}
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_190 ( & V_10 -> V_432 -> V_451 ) ;
if ( V_22 ) {
F_70 ( V_2 , V_452 , L_55 ,
F_191 ( & V_22 -> V_453 ) ) ;
F_192 ( V_22 ) ;
F_179 ( V_22 ) ;
}
}
static void F_193 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_10 ;
struct V_25 * V_2 ;
F_175 (dev, link, ALL) {
unsigned long V_13 ;
if ( ! ( V_2 -> V_13 & V_454 ) )
continue;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 -> V_13 &= ~ V_454 ;
F_7 ( V_10 -> V_18 , V_13 ) ;
F_186 ( V_2 ) ;
}
}
void F_194 ( struct V_25 * V_2 )
{
if ( V_2 -> V_22 )
F_195 ( V_2 -> V_22 , V_205 ,
V_455 ) ;
}
void F_196 ( struct V_456 * V_457 )
{
struct V_9 * V_10 =
F_197 ( V_457 , struct V_9 , V_449 . V_457 ) ;
int V_158 ;
if ( V_10 -> V_36 & V_458 ) {
F_95 ( L_56 ) ;
return;
}
F_95 ( L_34 ) ;
F_187 ( & V_10 -> V_459 ) ;
F_193 ( & V_10 -> V_24 ) ;
if ( V_10 -> V_354 )
for ( V_158 = 0 ; V_158 < V_460 ; V_158 ++ )
F_193 ( & V_10 -> V_354 [ V_158 ] ) ;
F_173 ( V_10 , 0 ) ;
F_190 ( & V_10 -> V_459 ) ;
F_95 ( L_36 ) ;
}
int F_198 ( struct V_7 * V_8 , unsigned int V_355 ,
unsigned int V_89 , unsigned int V_356 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_13 ;
int V_40 , V_29 = 0 ;
if ( ! V_10 -> V_61 -> V_170 )
return - V_34 ;
if ( V_356 != V_461 && V_356 )
return - V_17 ;
if ( ! F_150 ( V_10 ) ) {
if ( V_355 != V_461 && V_355 )
return - V_17 ;
V_40 = V_89 ;
} else {
if ( V_89 != V_461 && V_89 )
return - V_17 ;
V_40 = V_355 ;
}
F_5 ( V_10 -> V_18 , V_13 ) ;
if ( V_40 == V_461 ) {
struct V_23 * V_24 ;
F_174 (link, ap, EDGE) {
struct V_462 * V_463 = & V_24 -> V_48 ;
V_463 -> V_464 |= V_465 ;
V_463 -> V_84 |= V_85 ;
}
} else {
struct V_25 * V_2 = F_149 ( V_10 , V_40 ) ;
if ( V_2 ) {
struct V_462 * V_463 = & V_2 -> V_24 -> V_48 ;
V_463 -> V_464 |= 1 << V_2 -> V_40 ;
V_463 -> V_84 |= V_85 ;
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
void F_199 ( struct V_456 * V_457 )
{
struct V_9 * V_10 =
F_197 ( V_457 , struct V_9 , V_466 ) ;
struct V_23 * V_24 ;
struct V_25 * V_2 ;
unsigned long V_13 ;
F_187 ( & V_10 -> V_459 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
F_174 (link, ap, EDGE) {
F_175 (dev, link, ENABLED) {
struct V_21 * V_22 = V_2 -> V_22 ;
if ( ! V_22 )
continue;
if ( F_188 ( V_22 ) )
continue;
F_7 ( V_10 -> V_18 , V_13 ) ;
F_200 ( & ( V_22 -> V_453 ) ) ;
F_179 ( V_22 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
}
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_190 ( & V_10 -> V_459 ) ;
}
struct V_9 * F_201 ( struct V_425 * V_30 ,
struct V_467 * V_468 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_202 ( V_30 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_469 = 0 ;
V_10 -> V_18 = & V_30 -> V_18 ;
V_10 -> V_470 = V_468 -> V_470 ;
V_10 -> V_471 = V_468 -> V_471 ;
V_10 -> V_472 = V_468 -> V_472 ;
V_10 -> V_13 |= V_468 -> V_13 ;
V_10 -> V_61 = V_468 -> V_473 ;
V_10 -> V_474 = V_475 ;
return V_10 ;
}
int F_203 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_61 -> V_170 )
V_10 -> V_36 &= ~ V_476 ;
return 0 ;
}
void F_204 ( struct V_9 * V_10 )
{
}
int F_205 ( struct V_9 * V_10 )
{
int V_29 = V_10 -> V_61 -> V_477 ( V_10 ) ;
if ( ! V_29 ) {
V_10 -> V_175 = V_478 ++ ;
V_29 = F_206 ( V_10 ) ;
}
return V_29 ;
}
void F_207 ( struct V_9 * V_10 )
{
if ( V_10 -> V_61 -> V_479 )
V_10 -> V_61 -> V_479 ( V_10 ) ;
F_43 ( V_10 ) ;
}
int F_208 ( struct V_21 * V_22 , struct V_9 * V_10 )
{
F_61 ( V_22 ) ;
F_66 ( V_22 , V_10 -> V_24 . V_1 ) ;
return 0 ;
}
int F_209 ( struct V_52 * V_53 , struct V_9 * V_10 )
{
int V_29 = 0 ;
F_161 ( V_10 , V_53 ) ;
if ( F_63 ( F_83 ( V_10 -> V_24 . V_1 ) ) )
V_29 = F_163 ( V_53 , V_10 -> V_24 . V_1 ) ;
else {
V_53 -> V_57 = ( V_410 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
}
return V_29 ;
}
