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
V_22 -> V_189 = 1 ;
V_22 -> V_190 = 1 ;
}
static int F_62 ( struct V_144 * V_191 )
{
if ( F_63 ( V_191 -> V_192 != V_193 ) )
return 0 ;
if ( ! F_64 ( V_191 ) || ( V_191 -> V_194 & V_195 ) )
return 0 ;
return F_65 ( V_191 -> V_53 [ 0 ] ) == V_196 ;
}
static int F_66 ( struct V_21 * V_22 ,
struct V_25 * V_2 )
{
struct V_197 * V_198 = V_22 -> V_197 ;
if ( ! F_67 ( V_2 -> V_89 ) )
V_2 -> V_13 |= V_33 ;
F_68 ( V_198 , V_2 -> V_199 ) ;
if ( V_2 -> V_46 == V_200 ) {
void * V_5 ;
V_22 -> V_201 = V_110 ;
F_69 ( V_198 , V_202 - 1 ) ;
V_5 = F_39 ( V_203 , V_198 -> V_204 | V_111 ) ;
if ( ! V_5 ) {
F_70 ( V_2 , L_27 ) ;
return - V_109 ;
}
F_71 ( V_198 , F_62 , V_5 , V_203 ) ;
} else {
V_22 -> V_201 = F_72 ( V_2 -> V_89 ) ;
V_22 -> V_205 = 1 ;
}
if ( V_22 -> V_201 > V_20 )
F_73 ( V_2 ,
L_28 ,
V_22 -> V_201 ) ;
F_74 ( V_198 , V_22 -> V_201 - 1 ) ;
if ( V_2 -> V_13 & V_206 )
F_75 ( V_207 , V_22 -> V_208 ) ;
if ( V_2 -> V_13 & V_209 ) {
int V_210 ;
V_210 = F_76 ( V_22 -> V_30 -> V_211 , F_77 ( V_2 -> V_89 ) ) ;
V_210 = F_76 ( V_212 - 1 , V_210 ) ;
F_78 ( V_22 , V_213 , V_210 ) ;
}
F_79 ( V_198 , false ) ;
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
struct V_197 * V_198 = V_22 -> V_197 ;
unsigned long V_13 ;
struct V_25 * V_2 ;
if ( ! V_10 -> V_61 -> V_170 )
return;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 = F_81 ( V_10 , V_22 ) ;
if ( V_2 && V_2 -> V_22 ) {
V_2 -> V_22 = NULL ;
V_2 -> V_13 |= V_214 ;
F_6 ( V_10 ) ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_43 ( V_198 -> V_215 ) ;
V_198 -> V_215 = NULL ;
V_198 -> V_216 = 0 ;
}
int F_83 ( struct V_9 * V_10 , struct V_21 * V_22 ,
int V_217 , int V_218 )
{
struct V_25 * V_2 ;
unsigned long V_13 ;
if ( V_218 != V_219 )
return - V_34 ;
if ( V_217 < 1 || V_217 == V_22 -> V_217 )
return V_22 -> V_217 ;
V_2 = F_11 ( V_10 , V_22 ) ;
if ( ! V_2 || ! F_84 ( V_2 ) )
return V_22 -> V_217 ;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 -> V_13 &= ~ V_220 ;
if ( V_217 == 1 || ! F_85 ( V_2 ) ) {
V_2 -> V_13 |= V_220 ;
V_217 = 1 ;
}
F_7 ( V_10 -> V_18 , V_13 ) ;
V_217 = F_76 ( V_217 , V_22 -> V_30 -> V_211 ) ;
V_217 = F_76 ( V_217 , F_77 ( V_2 -> V_89 ) ) ;
V_217 = F_76 ( V_217 , V_212 - 1 ) ;
if ( V_22 -> V_217 == V_217 )
return - V_17 ;
F_78 ( V_22 , V_213 , V_217 ) ;
return V_217 ;
}
int F_86 ( struct V_21 * V_22 , int V_217 ,
int V_218 )
{
struct V_9 * V_10 = F_3 ( V_22 -> V_30 ) ;
return F_83 ( V_10 , V_22 , V_217 , V_218 ) ;
}
static unsigned int F_87 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_147 * V_148 = & V_135 -> V_148 ;
const T_3 * V_221 = V_142 -> V_222 ;
if ( V_142 -> V_223 < 5 )
goto V_224;
V_148 -> V_13 |= V_225 | V_226 ;
V_148 -> V_227 = V_228 ;
if ( V_221 [ 1 ] & 0x1 ) {
;
}
if ( V_221 [ 4 ] & 0x2 )
goto V_224;
if ( ( ( V_221 [ 4 ] >> 4 ) & 0xf ) != 0 )
goto V_224;
if ( V_221 [ 4 ] & 0x1 ) {
V_148 -> V_176 = 1 ;
if ( V_135 -> V_2 -> V_13 & V_229 ) {
V_148 -> V_13 |= V_230 ;
V_148 -> V_179 = 0x0 ;
V_148 -> V_178 = 0x0 ;
V_148 -> V_177 = 0x0 ;
V_148 -> V_1 |= V_231 ;
} else {
V_148 -> V_177 = 0x1 ;
V_148 -> V_178 = 0x0 ;
V_148 -> V_179 = 0x0 ;
}
V_148 -> V_150 = V_232 ;
} else {
if ( ( V_135 -> V_10 -> V_13 & V_233 ) &&
V_234 == V_235 )
goto V_236;
if ( ( V_135 -> V_10 -> V_13 & V_237 ) &&
F_88 () )
goto V_236;
V_148 -> V_150 = V_238 ;
}
return 0 ;
V_224:
F_20 ( V_142 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_236:
V_142 -> V_57 = V_239 ;
return 1 ;
}
static unsigned int F_89 ( struct V_134 * V_135 )
{
struct V_147 * V_148 = & V_135 -> V_148 ;
V_148 -> V_13 |= V_225 ;
V_148 -> V_227 = V_228 ;
if ( V_135 -> V_2 -> V_13 & V_240 )
V_148 -> V_150 = V_241 ;
else
V_148 -> V_150 = V_242 ;
V_135 -> V_13 |= V_243 ;
return 0 ;
}
static void F_90 ( const T_3 * V_221 , T_7 * V_244 , T_8 * V_245 )
{
T_7 V_246 = 0 ;
T_8 V_42 ;
F_91 ( L_29 ) ;
V_246 |= ( ( T_7 ) ( V_221 [ 1 ] & 0x1f ) ) << 16 ;
V_246 |= ( ( T_7 ) V_221 [ 2 ] ) << 8 ;
V_246 |= ( ( T_7 ) V_221 [ 3 ] ) ;
V_42 = V_221 [ 4 ] ;
* V_244 = V_246 ;
* V_245 = V_42 ;
}
static void F_92 ( const T_3 * V_221 , T_7 * V_244 , T_8 * V_245 )
{
T_7 V_246 = 0 ;
T_8 V_42 = 0 ;
F_91 ( L_30 ) ;
V_246 |= ( ( T_7 ) V_221 [ 2 ] ) << 24 ;
V_246 |= ( ( T_7 ) V_221 [ 3 ] ) << 16 ;
V_246 |= ( ( T_7 ) V_221 [ 4 ] ) << 8 ;
V_246 |= ( ( T_7 ) V_221 [ 5 ] ) ;
V_42 |= ( ( T_8 ) V_221 [ 7 ] ) << 8 ;
V_42 |= ( ( T_8 ) V_221 [ 8 ] ) ;
* V_244 = V_246 ;
* V_245 = V_42 ;
}
static void F_93 ( const T_3 * V_221 , T_7 * V_244 , T_8 * V_245 )
{
T_7 V_246 = 0 ;
T_8 V_42 = 0 ;
F_91 ( L_31 ) ;
V_246 |= ( ( T_7 ) V_221 [ 2 ] ) << 56 ;
V_246 |= ( ( T_7 ) V_221 [ 3 ] ) << 48 ;
V_246 |= ( ( T_7 ) V_221 [ 4 ] ) << 40 ;
V_246 |= ( ( T_7 ) V_221 [ 5 ] ) << 32 ;
V_246 |= ( ( T_7 ) V_221 [ 6 ] ) << 24 ;
V_246 |= ( ( T_7 ) V_221 [ 7 ] ) << 16 ;
V_246 |= ( ( T_7 ) V_221 [ 8 ] ) << 8 ;
V_246 |= ( ( T_7 ) V_221 [ 9 ] ) ;
V_42 |= ( ( T_8 ) V_221 [ 10 ] ) << 24 ;
V_42 |= ( ( T_8 ) V_221 [ 11 ] ) << 16 ;
V_42 |= ( ( T_8 ) V_221 [ 12 ] ) << 8 ;
V_42 |= ( ( T_8 ) V_221 [ 13 ] ) ;
* V_244 = V_246 ;
* V_245 = V_42 ;
}
static unsigned int F_94 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_147 * V_148 = & V_135 -> V_148 ;
struct V_25 * V_2 = V_135 -> V_2 ;
T_7 V_247 = V_135 -> V_2 -> V_81 ;
const T_3 * V_221 = V_142 -> V_222 ;
T_7 V_185 ;
T_8 V_248 ;
V_148 -> V_13 |= V_226 | V_225 ;
V_148 -> V_227 = V_228 ;
if ( V_221 [ 0 ] == V_249 ) {
if ( V_142 -> V_223 < 10 )
goto V_224;
F_92 ( V_221 , & V_185 , & V_248 ) ;
} else if ( V_221 [ 0 ] == V_250 ) {
if ( V_142 -> V_223 < 16 )
goto V_224;
F_93 ( V_221 , & V_185 , & V_248 ) ;
} else
goto V_224;
if ( ! V_248 )
goto V_251;
if ( V_185 >= V_247 )
goto V_252;
if ( ( V_185 + V_248 ) > V_247 )
goto V_252;
if ( V_2 -> V_13 & V_229 ) {
V_148 -> V_13 |= V_230 ;
if ( F_95 ( V_185 , V_248 ) ) {
V_148 -> V_150 = V_232 ;
V_148 -> V_1 |= ( V_185 >> 24 ) & 0xf ;
} else if ( F_96 ( V_185 , V_248 ) ) {
if ( ! ( V_2 -> V_13 & V_253 ) )
goto V_252;
V_148 -> V_13 |= V_180 ;
V_148 -> V_150 = V_254 ;
V_148 -> V_181 = ( V_248 >> 8 ) & 0xff ;
V_148 -> V_184 = ( V_185 >> 40 ) & 0xff ;
V_148 -> V_183 = ( V_185 >> 32 ) & 0xff ;
V_148 -> V_182 = ( V_185 >> 24 ) & 0xff ;
} else
goto V_252;
V_148 -> V_176 = V_248 & 0xff ;
V_148 -> V_179 = ( V_185 >> 16 ) & 0xff ;
V_148 -> V_178 = ( V_185 >> 8 ) & 0xff ;
V_148 -> V_177 = V_185 & 0xff ;
V_148 -> V_1 |= V_231 ;
} else {
T_8 V_255 , V_256 , V_257 , V_258 ;
if ( ! F_95 ( V_185 , V_248 ) )
goto V_252;
V_258 = ( T_8 ) V_185 / V_2 -> V_259 ;
V_257 = V_258 / V_2 -> V_260 ;
V_256 = V_258 % V_2 -> V_260 ;
V_255 = ( T_8 ) V_185 % V_2 -> V_259 + 1 ;
F_97 ( L_32 ,
( T_8 ) V_185 , V_258 , V_257 , V_256 , V_255 ) ;
if ( ( V_257 >> 16 ) || ( V_256 >> 4 ) || ( V_255 >> 8 ) || ( ! V_255 ) )
goto V_252;
V_148 -> V_150 = V_232 ;
V_148 -> V_176 = V_248 & 0xff ;
V_148 -> V_177 = V_255 ;
V_148 -> V_178 = V_257 ;
V_148 -> V_179 = V_257 >> 8 ;
V_148 -> V_1 |= V_256 ;
}
return 0 ;
V_224:
F_20 ( V_142 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_252:
F_20 ( V_142 , V_75 , 0x21 , 0x0 ) ;
return 1 ;
V_251:
V_142 -> V_57 = V_239 ;
return 1 ;
}
static unsigned int F_98 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
const T_3 * V_221 = V_142 -> V_222 ;
unsigned int V_261 = 0 ;
T_7 V_185 ;
T_8 V_248 ;
int V_29 ;
if ( V_221 [ 0 ] == V_262 || V_221 [ 0 ] == V_263 || V_221 [ 0 ] == V_264 )
V_261 |= V_265 ;
switch ( V_221 [ 0 ] ) {
case V_266 :
case V_262 :
if ( F_17 ( V_142 -> V_223 < 10 ) )
goto V_224;
F_92 ( V_221 , & V_185 , & V_248 ) ;
if ( V_221 [ 1 ] & ( 1 << 3 ) )
V_261 |= V_267 ;
break;
case V_268 :
case V_263 :
if ( F_17 ( V_142 -> V_223 < 6 ) )
goto V_224;
F_90 ( V_221 , & V_185 , & V_248 ) ;
if ( ! V_248 )
V_248 = 256 ;
break;
case V_269 :
case V_264 :
if ( F_17 ( V_142 -> V_223 < 16 ) )
goto V_224;
F_93 ( V_221 , & V_185 , & V_248 ) ;
if ( V_221 [ 1 ] & ( 1 << 3 ) )
V_261 |= V_267 ;
break;
default:
F_97 ( L_33 ) ;
goto V_224;
}
if ( ! V_248 )
goto V_251;
V_135 -> V_13 |= V_243 ;
V_135 -> V_146 = V_248 * V_142 -> V_1 -> V_201 ;
V_29 = F_99 ( & V_135 -> V_148 , V_135 -> V_2 , V_185 , V_248 , V_261 ,
V_135 -> V_270 ) ;
if ( F_63 ( V_29 == 0 ) )
return 0 ;
if ( V_29 == - V_271 )
goto V_252;
V_224:
F_20 ( V_142 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_252:
F_20 ( V_142 , V_75 , 0x21 , 0x0 ) ;
return 1 ;
V_251:
V_142 -> V_57 = V_239 ;
return 1 ;
}
static void F_100 ( struct V_134 * V_135 )
{
struct V_9 * V_10 = V_135 -> V_10 ;
struct V_52 * V_53 = V_135 -> V_136 ;
T_3 * V_221 = V_53 -> V_222 ;
int V_272 = ( V_135 -> V_171 != 0 ) ;
if ( ( ( V_221 [ 0 ] == V_114 ) || ( V_221 [ 0 ] == V_273 ) ) &&
( ( V_221 [ 2 ] & 0x20 ) || V_272 ) ) {
F_58 ( V_135 ) ;
} else {
if ( ! V_272 ) {
V_53 -> V_57 = V_239 ;
} else {
F_59 ( V_135 ) ;
}
}
if ( V_272 && ! V_10 -> V_61 -> V_170 )
F_55 ( V_10 -> V_175 , & V_135 -> V_168 ) ;
V_135 -> V_137 ( V_53 ) ;
F_101 ( V_135 ) ;
}
static int F_102 ( struct V_25 * V_2 , struct V_52 * V_53 ,
T_9 V_274 )
{
struct V_9 * V_10 = V_2 -> V_24 -> V_10 ;
struct V_134 * V_135 ;
int V_29 ;
F_91 ( L_34 ) ;
V_135 = F_49 ( V_2 , V_53 ) ;
if ( ! V_135 )
goto V_275;
if ( V_53 -> V_276 == V_112 ||
V_53 -> V_276 == V_277 ) {
if ( F_17 ( F_54 ( V_53 ) < 1 ) ) {
F_73 ( V_2 , L_35 ) ;
goto V_278;
}
F_103 ( V_135 , F_51 ( V_53 ) , F_52 ( V_53 ) ) ;
V_135 -> V_279 = V_53 -> V_276 ;
}
V_135 -> V_280 = F_100 ;
if ( V_274 ( V_135 ) )
goto V_281;
if ( V_10 -> V_61 -> V_282 ) {
if ( ( V_29 = V_10 -> V_61 -> V_282 ( V_135 ) ) )
goto V_283;
}
F_104 ( V_135 ) ;
F_91 ( L_36 ) ;
return 0 ;
V_281:
F_101 ( V_135 ) ;
V_53 -> V_76 ( V_53 ) ;
F_97 ( L_37 ) ;
return 0 ;
V_278:
F_101 ( V_135 ) ;
V_53 -> V_57 = ( V_284 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
V_275:
F_97 ( L_38 ) ;
return 0 ;
V_283:
F_101 ( V_135 ) ;
F_97 ( L_39 ) ;
if ( V_29 == V_285 )
return V_286 ;
else
return V_287 ;
}
static void * F_105 ( struct V_52 * V_53 , bool V_288 ,
unsigned long * V_13 )
{
F_5 ( & V_289 , * V_13 ) ;
memset ( V_290 , 0 , V_291 ) ;
if ( V_288 )
F_106 ( F_51 ( V_53 ) , F_52 ( V_53 ) ,
V_290 , V_291 ) ;
return V_290 ;
}
static inline void F_107 ( struct V_52 * V_53 , bool V_292 ,
unsigned long * V_13 )
{
if ( V_292 )
F_108 ( F_51 ( V_53 ) , F_52 ( V_53 ) ,
V_290 , V_291 ) ;
F_7 ( & V_289 , * V_13 ) ;
}
static unsigned int F_109 ( struct V_293 * args , T_3 * V_294 )
{
const T_3 V_295 [] = {
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
T_3 V_296 [] = {
V_297 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_91 ( L_34 ) ;
if ( F_110 ( args -> V_89 ) )
V_296 [ 1 ] |= ( 1 << 7 ) ;
memcpy ( V_294 , V_296 , sizeof( V_296 ) ) ;
memcpy ( & V_294 [ 8 ] , L_40 , 8 ) ;
F_35 ( args -> V_89 , & V_294 [ 16 ] , V_92 , 16 ) ;
F_35 ( args -> V_89 , & V_294 [ 32 ] , V_94 , 4 ) ;
if ( V_294 [ 32 ] == 0 || V_294 [ 32 ] == ' ' )
memcpy ( & V_294 [ 32 ] , L_41 , 4 ) ;
memcpy ( V_294 + 59 , V_295 , sizeof( V_295 ) ) ;
return 0 ;
}
static unsigned int F_111 ( struct V_293 * args , T_3 * V_294 )
{
const T_3 V_298 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
} ;
V_294 [ 3 ] = sizeof( V_298 ) ;
memcpy ( V_294 + 4 , V_298 , sizeof( V_298 ) ) ;
return 0 ;
}
static unsigned int F_112 ( struct V_293 * args , T_3 * V_294 )
{
const T_3 V_296 [] = {
0 ,
0x80 ,
0 ,
V_97 ,
} ;
memcpy ( V_294 , V_296 , sizeof( V_296 ) ) ;
F_35 ( args -> V_89 , ( unsigned char * ) & V_294 [ 4 ] ,
V_96 , V_97 ) ;
return 0 ;
}
static unsigned int F_113 ( struct V_293 * args , T_3 * V_294 )
{
const int V_299 = 68 ;
int V_300 ;
V_294 [ 1 ] = 0x83 ;
V_300 = 4 ;
V_294 [ V_300 + 0 ] = 2 ;
V_294 [ V_300 + 3 ] = V_97 ;
V_300 += 4 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_294 + V_300 ,
V_96 , V_97 ) ;
V_300 += V_97 ;
V_294 [ V_300 + 0 ] = 2 ;
V_294 [ V_300 + 1 ] = 1 ;
V_294 [ V_300 + 3 ] = V_299 ;
V_300 += 4 ;
memcpy ( V_294 + V_300 , L_40 , 8 ) ;
V_300 += 8 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_294 + V_300 , V_92 ,
V_93 ) ;
V_300 += V_93 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_294 + V_300 , V_96 ,
V_97 ) ;
V_300 += V_97 ;
if ( F_114 ( args -> V_89 ) ) {
V_294 [ V_300 + 0 ] = 1 ;
V_294 [ V_300 + 1 ] = 3 ;
V_294 [ V_300 + 3 ] = V_301 ;
V_300 += 4 ;
F_35 ( args -> V_89 , ( unsigned char * ) V_294 + V_300 ,
V_302 , V_301 ) ;
V_300 += V_301 ;
}
V_294 [ 3 ] = V_300 - 4 ;
return 0 ;
}
static unsigned int F_115 ( struct V_293 * args , T_3 * V_294 )
{
struct V_147 V_148 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_294 [ 1 ] = 0x89 ;
V_294 [ 2 ] = ( 0x238 >> 8 ) ;
V_294 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_294 [ 8 ] , L_42 , 8 ) ;
memcpy ( & V_294 [ 16 ] , L_43 , 16 ) ;
memcpy ( & V_294 [ 32 ] , V_303 , 4 ) ;
F_35 ( args -> V_89 , & V_294 [ 32 ] , V_94 , 4 ) ;
V_148 . V_150 = V_304 ;
V_148 . V_177 = 0x1 ;
V_148 . V_176 = 0x1 ;
F_116 ( & V_148 , 0 , 1 , & V_294 [ 36 ] ) ;
V_294 [ 36 ] = 0x34 ;
V_294 [ 56 ] = V_305 ;
memcpy ( & V_294 [ 60 ] , & args -> V_89 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_117 ( struct V_293 * args , T_3 * V_294 )
{
T_6 V_306 ;
V_294 [ 1 ] = 0xb0 ;
V_294 [ 3 ] = 0x3c ;
V_306 = 1 << F_118 ( args -> V_89 ) ;
F_119 ( V_306 , & V_294 [ 6 ] ) ;
if ( F_120 ( args -> V_89 ) ) {
F_121 ( 65535 * 512 / 8 , & V_294 [ 36 ] ) ;
F_122 ( 1 , & V_294 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_123 ( struct V_293 * args , T_3 * V_294 )
{
int V_307 = F_124 ( args -> V_89 ) ;
int V_308 = F_125 ( args -> V_89 ) ;
V_294 [ 1 ] = 0xb1 ;
V_294 [ 3 ] = 0x3c ;
V_294 [ 4 ] = V_308 >> 8 ;
V_294 [ 5 ] = V_308 ;
V_294 [ 7 ] = V_307 ;
return 0 ;
}
static unsigned int F_126 ( struct V_293 * args , T_3 * V_294 )
{
V_294 [ 1 ] = 0xb2 ;
V_294 [ 3 ] = 0x4 ;
V_294 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_127 ( struct V_293 * args , T_3 * V_294 )
{
F_91 ( L_34 ) ;
return 0 ;
}
static void F_128 ( T_3 * V_309 , const T_3 * V_310 , int V_311 , bool V_312 )
{
if ( V_312 ) {
memcpy ( V_309 , V_310 , 2 ) ;
memset ( V_309 + 2 , 0 , V_311 - 2 ) ;
} else {
memcpy ( V_309 , V_310 , V_311 ) ;
}
}
static unsigned int F_129 ( T_6 * V_89 , T_3 * V_5 , bool V_312 )
{
F_128 ( V_5 , V_313 , sizeof( V_313 ) , V_312 ) ;
if ( V_312 || F_130 ( V_89 ) )
V_5 [ 2 ] |= ( 1 << 2 ) ;
if ( ! V_312 && ! F_131 ( V_89 ) )
V_5 [ 12 ] |= ( 1 << 5 ) ;
return sizeof( V_313 ) ;
}
static unsigned int F_132 ( T_3 * V_5 , bool V_312 )
{
F_128 ( V_5 , V_314 , sizeof( V_314 ) , V_312 ) ;
return sizeof( V_314 ) ;
}
static unsigned int F_133 ( T_3 * V_5 , bool V_312 )
{
F_128 ( V_5 , V_315 , sizeof( V_315 ) ,
V_312 ) ;
return sizeof( V_315 ) ;
}
static int F_134 ( T_6 * V_89 )
{
unsigned char V_316 [ V_93 + 1 ] , V_317 [ V_95 + 1 ] ;
if ( ! V_318 )
return 0 ;
if ( ! F_135 ( V_89 ) )
return 0 ;
F_136 ( V_89 , V_316 , V_92 , sizeof( V_316 ) ) ;
F_136 ( V_89 , V_317 , V_94 , sizeof( V_317 ) ) ;
if ( strcmp ( V_316 , L_44 ) )
return 1 ;
if ( strcmp ( V_317 , L_45 ) )
return 1 ;
return 0 ;
}
static unsigned int F_137 ( struct V_293 * args , T_3 * V_294 )
{
struct V_25 * V_2 = args -> V_2 ;
T_3 * V_136 = args -> V_53 -> V_222 , * V_319 = V_294 ;
const T_3 V_320 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_321 , V_322 ;
unsigned int V_323 , V_324 , V_325 ;
T_3 V_326 ;
F_91 ( L_34 ) ;
V_325 = ( V_136 [ 0 ] == V_327 ) ;
V_323 = ! ( V_136 [ 1 ] & 0x8 ) ;
V_324 = V_136 [ 2 ] >> 6 ;
switch ( V_324 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_328;
default:
goto V_224;
}
if ( V_325 )
V_319 += 4 + ( V_323 ? 8 : 0 ) ;
else
V_319 += 8 + ( V_323 ? 8 : 0 ) ;
V_321 = V_136 [ 2 ] & 0x3f ;
V_322 = V_136 [ 3 ] ;
if ( V_322 && ( V_322 != V_329 ) )
goto V_224;
switch( V_321 ) {
case V_330 :
V_319 += F_133 ( V_319 , V_324 == 1 ) ;
break;
case V_331 :
V_319 += F_129 ( args -> V_89 , V_319 , V_324 == 1 ) ;
break;
case V_332 :
V_319 += F_132 ( V_319 , V_324 == 1 ) ;
break;
case V_333 :
V_319 += F_133 ( V_319 , V_324 == 1 ) ;
V_319 += F_129 ( args -> V_89 , V_319 , V_324 == 1 ) ;
V_319 += F_132 ( V_319 , V_324 == 1 ) ;
break;
default:
goto V_224;
}
V_326 = 0 ;
if ( F_134 ( args -> V_89 ) && ( V_2 -> V_13 & V_253 ) &&
( ! ( V_2 -> V_13 & V_334 ) || V_2 -> V_335 ) )
V_326 = 1 << 4 ;
if ( V_325 ) {
V_294 [ 0 ] = V_319 - V_294 - 1 ;
V_294 [ 2 ] |= V_326 ;
if ( V_323 ) {
V_294 [ 3 ] = sizeof( V_320 ) ;
memcpy ( V_294 + 4 , V_320 , sizeof( V_320 ) ) ;
}
} else {
unsigned int V_336 = V_319 - V_294 - 2 ;
V_294 [ 0 ] = V_336 >> 8 ;
V_294 [ 1 ] = V_336 ;
V_294 [ 3 ] |= V_326 ;
if ( V_323 ) {
V_294 [ 7 ] = sizeof( V_320 ) ;
memcpy ( V_294 + 8 , V_320 , sizeof( V_320 ) ) ;
}
}
return 0 ;
V_224:
F_20 ( args -> V_53 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_328:
F_20 ( args -> V_53 , V_75 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_138 ( struct V_293 * args , T_3 * V_294 )
{
struct V_25 * V_2 = args -> V_2 ;
T_7 V_337 = V_2 -> V_81 - 1 ;
T_8 V_201 ;
T_3 V_338 ;
T_6 V_339 ;
V_201 = F_72 ( V_2 -> V_89 ) ;
V_338 = F_118 ( V_2 -> V_89 ) ;
V_339 = F_139 ( V_2 -> V_89 , V_338 ) ;
F_91 ( L_34 ) ;
if ( args -> V_53 -> V_222 [ 0 ] == V_340 ) {
if ( V_337 >= 0xffffffffULL )
V_337 = 0xffffffff ;
V_294 [ 0 ] = V_337 >> ( 8 * 3 ) ;
V_294 [ 1 ] = V_337 >> ( 8 * 2 ) ;
V_294 [ 2 ] = V_337 >> ( 8 * 1 ) ;
V_294 [ 3 ] = V_337 ;
V_294 [ 4 ] = V_201 >> ( 8 * 3 ) ;
V_294 [ 5 ] = V_201 >> ( 8 * 2 ) ;
V_294 [ 6 ] = V_201 >> ( 8 * 1 ) ;
V_294 [ 7 ] = V_201 ;
} else {
V_294 [ 0 ] = V_337 >> ( 8 * 7 ) ;
V_294 [ 1 ] = V_337 >> ( 8 * 6 ) ;
V_294 [ 2 ] = V_337 >> ( 8 * 5 ) ;
V_294 [ 3 ] = V_337 >> ( 8 * 4 ) ;
V_294 [ 4 ] = V_337 >> ( 8 * 3 ) ;
V_294 [ 5 ] = V_337 >> ( 8 * 2 ) ;
V_294 [ 6 ] = V_337 >> ( 8 * 1 ) ;
V_294 [ 7 ] = V_337 ;
V_294 [ 8 ] = V_201 >> ( 8 * 3 ) ;
V_294 [ 9 ] = V_201 >> ( 8 * 2 ) ;
V_294 [ 10 ] = V_201 >> ( 8 * 1 ) ;
V_294 [ 11 ] = V_201 ;
V_294 [ 12 ] = 0 ;
V_294 [ 13 ] = V_338 ;
V_294 [ 14 ] = ( V_339 >> 8 ) & 0x3f ;
V_294 [ 15 ] = V_339 ;
if ( F_120 ( args -> V_89 ) ) {
V_294 [ 14 ] |= 0x80 ;
if ( F_140 ( args -> V_89 ) )
V_294 [ 14 ] |= 0x40 ;
}
}
return 0 ;
}
static unsigned int F_141 ( struct V_293 * args , T_3 * V_294 )
{
F_91 ( L_34 ) ;
V_294 [ 3 ] = 8 ;
return 0 ;
}
static void F_142 ( struct V_134 * V_135 )
{
if ( V_135 -> V_171 && ( ( V_135 -> V_171 & V_341 ) == 0 ) ) {
F_58 ( V_135 ) ;
}
V_135 -> V_137 ( V_135 -> V_136 ) ;
F_101 ( V_135 ) ;
}
static inline int F_143 ( struct V_9 * V_10 )
{
return ( V_10 -> V_13 & V_122 ) ;
}
static void F_144 ( struct V_134 * V_135 )
{
struct V_9 * V_10 = V_135 -> V_10 ;
struct V_52 * V_53 = V_135 -> V_136 ;
F_97 ( L_46 ) ;
memset ( V_53 -> V_60 , 0 , V_107 ) ;
#ifdef F_145
if ( V_10 -> V_61 -> V_342 )
V_10 -> V_61 -> V_342 ( V_10 , & V_135 -> V_148 ) ;
#endif
V_53 -> V_60 [ 0 ] = 0x70 ;
V_53 -> V_60 [ 2 ] = V_135 -> V_148 . V_152 >> 4 ;
F_146 ( V_135 ) ;
F_147 ( & V_135 -> V_343 , V_53 -> V_60 , V_107 ) ;
F_103 ( V_135 , & V_135 -> V_343 , 1 ) ;
V_135 -> V_279 = V_112 ;
memset ( & V_135 -> V_221 , 0 , V_135 -> V_2 -> V_344 ) ;
V_135 -> V_221 [ 0 ] = V_345 ;
V_135 -> V_221 [ 4 ] = V_107 ;
V_135 -> V_148 . V_13 |= V_226 | V_225 ;
V_135 -> V_148 . V_150 = V_346 ;
if ( F_143 ( V_10 ) ) {
V_135 -> V_148 . V_227 = V_347 ;
V_135 -> V_148 . V_152 |= V_348 ;
} else {
V_135 -> V_148 . V_227 = V_349 ;
V_135 -> V_148 . V_178 = V_107 ;
V_135 -> V_148 . V_179 = 0 ;
}
V_135 -> V_146 = V_107 ;
V_135 -> V_280 = F_142 ;
F_104 ( V_135 ) ;
F_97 ( L_36 ) ;
}
static void F_148 ( struct V_134 * V_135 )
{
struct V_52 * V_53 = V_135 -> V_136 ;
unsigned int V_171 = V_135 -> V_171 ;
F_91 ( L_47 , V_171 ) ;
if ( F_17 ( V_135 -> V_10 -> V_61 -> V_170 &&
( V_171 || V_135 -> V_13 & V_350 ) ) ) {
if ( ! ( V_135 -> V_13 & V_350 ) ) {
F_58 ( V_135 ) ;
}
if ( V_135 -> V_221 [ 0 ] == V_351 && V_135 -> V_2 -> V_22 )
V_135 -> V_2 -> V_22 -> V_352 = 0 ;
V_135 -> V_136 -> V_57 = V_59 ;
V_135 -> V_137 ( V_53 ) ;
F_101 ( V_135 ) ;
return;
}
if ( F_17 ( V_171 & V_341 ) ) {
V_53 -> V_57 = V_59 ;
F_144 ( V_135 ) ;
return;
} else if ( F_17 ( V_171 ) ) {
F_58 ( V_135 ) ;
} else {
T_3 * V_136 = V_53 -> V_222 ;
if ( ( V_136 [ 0 ] == V_353 ) && ( ( V_136 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_13 ;
T_3 * V_5 ;
V_5 = F_105 ( V_53 , true , & V_13 ) ;
if ( V_5 [ 2 ] == 0 ) {
V_5 [ 2 ] = 0x5 ;
V_5 [ 3 ] = 0x32 ;
}
F_107 ( V_53 , true , & V_13 ) ;
}
V_53 -> V_57 = V_239 ;
}
V_135 -> V_137 ( V_53 ) ;
F_101 ( V_135 ) ;
}
static unsigned int F_149 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_25 * V_2 = V_135 -> V_2 ;
int V_354 = ( V_142 -> V_276 == V_113 ) ;
int V_355 = ! V_354 && ( V_2 -> V_13 & V_334 ) ;
unsigned int V_146 ;
memset ( V_135 -> V_221 , 0 , V_2 -> V_344 ) ;
memcpy ( V_135 -> V_221 , V_142 -> V_222 , V_142 -> V_223 ) ;
V_135 -> V_280 = F_148 ;
V_135 -> V_148 . V_13 |= V_226 | V_225 ;
if ( V_142 -> V_276 == V_277 ) {
V_135 -> V_148 . V_13 |= V_265 ;
F_97 ( L_48 ) ;
}
V_135 -> V_148 . V_150 = V_346 ;
F_53 ( V_135 ) ;
if ( ! V_354 && ! V_355 && F_150 ( V_135 ) )
V_355 = 1 ;
V_146 = F_76 ( F_151 ( V_135 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_146 & 0x1 )
V_146 ++ ;
V_135 -> V_148 . V_178 = ( V_146 & 0xFF ) ;
V_135 -> V_148 . V_179 = ( V_146 >> 8 ) ;
if ( V_354 )
V_135 -> V_148 . V_227 = V_356 ;
else if ( V_355 )
V_135 -> V_148 . V_227 = V_349 ;
else {
V_135 -> V_148 . V_227 = V_347 ;
V_135 -> V_148 . V_152 |= V_348 ;
if ( ( V_2 -> V_13 & V_357 ) &&
( V_142 -> V_276 != V_277 ) )
V_135 -> V_148 . V_152 |= V_358 ;
}
return 0 ;
}
static struct V_25 * F_152 ( struct V_9 * V_10 , int V_40 )
{
if ( ! F_153 ( V_10 ) ) {
if ( F_63 ( V_40 < F_154 ( & V_10 -> V_24 ) ) )
return & V_10 -> V_24 . V_1 [ V_40 ] ;
} else {
if ( F_63 ( V_40 < V_10 -> V_359 ) )
return & V_10 -> V_360 [ V_40 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_25 * F_81 ( struct V_9 * V_10 ,
const struct V_21 * V_98 )
{
int V_40 ;
if ( ! F_153 ( V_10 ) ) {
if ( F_17 ( V_98 -> V_361 || V_98 -> V_362 ) )
return NULL ;
V_40 = V_98 -> V_89 ;
} else {
if ( F_17 ( V_98 -> V_89 || V_98 -> V_362 ) )
return NULL ;
V_40 = V_98 -> V_361 ;
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
F_155 ( T_3 V_363 )
{
switch( ( V_363 & 0x1e ) >> 1 ) {
case 3 :
return V_228 ;
case 6 :
case 10 :
case 11 :
return V_364 ;
case 4 :
case 5 :
return V_365 ;
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
return V_366 ;
}
static unsigned int F_156 ( struct V_134 * V_135 )
{
struct V_147 * V_148 = & ( V_135 -> V_148 ) ;
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_25 * V_2 = V_135 -> V_2 ;
const T_3 * V_221 = V_142 -> V_222 ;
if ( ( V_148 -> V_227 = F_155 ( V_221 [ 1 ] ) ) == V_366 )
goto V_224;
if ( V_221 [ 0 ] == V_114 ) {
if ( V_221 [ 1 ] & 0x01 ) {
V_148 -> V_367 = V_221 [ 3 ] ;
V_148 -> V_181 = V_221 [ 5 ] ;
V_148 -> V_182 = V_221 [ 7 ] ;
V_148 -> V_183 = V_221 [ 9 ] ;
V_148 -> V_184 = V_221 [ 11 ] ;
V_148 -> V_13 |= V_180 ;
} else
V_148 -> V_13 &= ~ V_180 ;
V_148 -> V_152 = V_221 [ 4 ] ;
V_148 -> V_176 = V_221 [ 6 ] ;
V_148 -> V_177 = V_221 [ 8 ] ;
V_148 -> V_178 = V_221 [ 10 ] ;
V_148 -> V_179 = V_221 [ 12 ] ;
V_148 -> V_1 = V_221 [ 13 ] ;
V_148 -> V_150 = V_221 [ 14 ] ;
} else {
V_148 -> V_13 &= ~ V_180 ;
V_148 -> V_152 = V_221 [ 3 ] ;
V_148 -> V_176 = V_221 [ 4 ] ;
V_148 -> V_177 = V_221 [ 5 ] ;
V_148 -> V_178 = V_221 [ 6 ] ;
V_148 -> V_179 = V_221 [ 7 ] ;
V_148 -> V_1 = V_221 [ 8 ] ;
V_148 -> V_150 = V_221 [ 9 ] ;
}
V_148 -> V_1 = V_2 -> V_40 ?
V_148 -> V_1 | V_368 : V_148 -> V_1 & ~ V_368 ;
switch ( V_148 -> V_150 ) {
case V_369 :
case V_370 :
case V_371 :
case V_372 :
if ( V_148 -> V_227 != V_365 || V_148 -> V_176 != 1 )
goto V_224;
V_135 -> V_373 = F_54 ( V_142 ) ;
break;
case V_374 :
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
case V_232 :
case V_254 :
case V_387 :
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
V_135 -> V_373 = V_142 -> V_1 -> V_201 ;
break;
default:
V_135 -> V_373 = V_110 ;
}
V_148 -> V_13 |= V_226 | V_225 ;
if ( V_142 -> V_276 == V_277 )
V_148 -> V_13 |= V_265 ;
V_135 -> V_13 |= V_400 | V_401 ;
F_53 ( V_135 ) ;
if ( V_148 -> V_227 == V_364 && V_2 -> V_402 == 0 )
goto V_224;
if ( ( V_221 [ 1 ] & 0xe0 ) && ! F_157 ( V_148 ) )
goto V_224;
if ( F_157 ( V_148 ) ) {
unsigned int V_335 = 1 << ( V_221 [ 1 ] >> 5 ) ;
if ( V_335 != V_2 -> V_335 )
F_73 ( V_2 , L_49 ,
V_335 ) ;
}
if ( V_148 -> V_150 == V_403 &&
V_148 -> V_152 == V_404 )
goto V_224;
if ( V_148 -> V_150 >= 0x5C && V_148 -> V_150 <= 0x5F && ! V_405 )
goto V_224;
return 0 ;
V_224:
F_20 ( V_142 , V_75 , 0x24 , 0x00 ) ;
return 1 ;
}
static unsigned int F_158 ( struct V_134 * V_135 )
{
struct V_147 * V_148 = & V_135 -> V_148 ;
struct V_52 * V_142 = V_135 -> V_136 ;
struct V_25 * V_2 = V_135 -> V_2 ;
const T_3 * V_221 = V_142 -> V_222 ;
T_7 V_185 ;
T_8 V_248 ;
T_8 V_406 ;
void * V_5 ;
if ( F_17 ( ! V_2 -> V_402 ) )
goto V_224;
if ( F_17 ( V_142 -> V_223 < 16 ) )
goto V_224;
F_93 ( V_221 , & V_185 , & V_248 ) ;
if ( F_17 ( ! ( V_221 [ 1 ] & 0x8 ) ) )
goto V_224;
if ( ! F_52 ( V_142 ) )
goto V_224;
V_5 = F_159 ( F_160 ( F_51 ( V_142 ) ) ) ;
V_406 = F_161 ( V_5 , 512 , V_185 , V_248 ) ;
V_148 -> V_227 = V_364 ;
V_148 -> V_367 = 0 ;
V_148 -> V_152 = V_407 ;
V_148 -> V_181 = ( V_406 / 512 ) >> 8 ;
V_148 -> V_176 = V_406 / 512 ;
V_148 -> V_150 = V_408 ;
V_148 -> V_13 |= V_226 | V_225 | V_180 |
V_265 ;
F_53 ( V_135 ) ;
return 0 ;
V_224:
F_20 ( V_142 , V_75 , 0x24 , 0x00 ) ;
return 1 ;
}
static int F_162 ( struct V_134 * V_135 ,
const T_3 * V_5 , int V_42 )
{
struct V_147 * V_148 = & V_135 -> V_148 ;
struct V_25 * V_2 = V_135 -> V_2 ;
char V_409 [ V_410 ] ;
T_3 V_411 ;
if ( V_42 != V_410 - 2 )
return - V_17 ;
V_411 = V_5 [ 0 ] & ( 1 << 2 ) ;
F_129 ( V_2 -> V_89 , V_409 , false ) ;
V_409 [ 2 ] &= ~ ( 1 << 2 ) ;
V_409 [ 2 ] |= V_411 ;
if ( memcmp ( V_409 + 2 , V_5 , V_410 - 2 ) != 0 )
return - V_17 ;
V_148 -> V_13 |= V_225 | V_226 ;
V_148 -> V_227 = V_228 ;
V_148 -> V_176 = 0 ;
V_148 -> V_150 = V_403 ;
V_148 -> V_152 = V_411 ? V_412 : V_413 ;
return 0 ;
}
static unsigned int F_163 ( struct V_134 * V_135 )
{
struct V_52 * V_142 = V_135 -> V_136 ;
const T_3 * V_221 = V_142 -> V_222 ;
const T_3 * V_319 ;
T_3 V_321 , V_322 ;
unsigned V_325 , V_414 , V_415 , V_416 ;
int V_42 ;
F_91 ( L_34 ) ;
V_325 = ( V_221 [ 0 ] == V_417 ) ;
if ( V_325 ) {
if ( V_142 -> V_223 < 5 )
goto V_224;
V_42 = V_221 [ 4 ] ;
V_415 = 4 ;
} else {
if ( V_142 -> V_223 < 9 )
goto V_224;
V_42 = ( V_221 [ 7 ] << 8 ) + V_221 [ 8 ] ;
V_415 = 8 ;
}
if ( ( V_221 [ 1 ] & 0x11 ) != 0x10 )
goto V_224;
if ( ! F_52 ( V_142 ) || F_51 ( V_142 ) -> V_418 < V_42 )
goto V_419;
V_319 = F_159 ( F_160 ( F_51 ( V_142 ) ) ) ;
if ( V_42 < V_415 )
goto V_419;
if ( V_325 )
V_416 = V_319 [ 3 ] ;
else
V_416 = ( V_319 [ 6 ] << 8 ) + V_319 [ 7 ] ;
V_42 -= V_415 ;
V_319 += V_415 ;
if ( V_42 < V_416 )
goto V_419;
if ( V_416 != 0 && V_416 != 8 )
goto V_420;
V_42 -= V_416 ;
V_319 += V_416 ;
if ( V_42 == 0 )
goto V_236;
V_321 = V_319 [ 0 ] & 0x3f ;
if ( V_319 [ 0 ] & 0x40 ) {
if ( V_42 < 4 )
goto V_419;
V_322 = V_319 [ 1 ] ;
V_414 = ( V_319 [ 2 ] << 8 ) | V_319 [ 3 ] ;
V_319 += 4 ;
V_42 -= 4 ;
} else {
if ( V_42 < 2 )
goto V_419;
V_322 = 0 ;
V_414 = V_319 [ 1 ] ;
V_319 += 2 ;
V_42 -= 2 ;
}
if ( V_322 && ( V_322 != V_329 ) )
goto V_420;
if ( V_414 > V_42 )
goto V_419;
switch ( V_321 ) {
case V_331 :
if ( F_162 ( V_135 , V_319 , V_414 ) < 0 )
goto V_420;
break;
default:
goto V_420;
}
if ( V_42 > V_414 )
goto V_420;
return 0 ;
V_224:
F_20 ( V_142 , V_75 , 0x24 , 0x0 ) ;
return 1 ;
V_420:
F_20 ( V_142 , V_75 , 0x26 , 0x0 ) ;
return 1 ;
V_419:
F_20 ( V_142 , V_75 , 0x1a , 0x0 ) ;
return 1 ;
V_236:
V_142 -> V_57 = V_239 ;
return 1 ;
}
static inline T_9 F_164 ( struct V_25 * V_2 , T_3 V_53 )
{
switch ( V_53 ) {
case V_268 :
case V_266 :
case V_269 :
case V_263 :
case V_262 :
case V_264 :
return F_98 ;
case V_421 :
return F_158 ;
case V_422 :
if ( F_165 ( V_2 ) )
return F_89 ;
break;
case V_249 :
case V_250 :
return F_94 ;
case V_273 :
case V_114 :
return F_156 ;
case V_417 :
case V_423 :
return F_163 ;
break;
case V_424 :
return F_87 ;
}
return NULL ;
}
static inline void F_166 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
#ifdef F_167
struct V_21 * V_98 = V_53 -> V_1 ;
T_3 * V_136 = V_53 -> V_222 ;
F_97 ( L_50 ,
V_10 -> V_175 ,
V_98 -> V_361 , V_98 -> V_89 , V_98 -> V_362 ,
V_136 [ 0 ] , V_136 [ 1 ] , V_136 [ 2 ] , V_136 [ 3 ] ,
V_136 [ 4 ] , V_136 [ 5 ] , V_136 [ 6 ] , V_136 [ 7 ] ,
V_136 [ 8 ] ) ;
#endif
}
static inline int F_168 ( struct V_52 * V_142 ,
struct V_25 * V_2 )
{
T_3 V_425 = V_142 -> V_222 [ 0 ] ;
T_9 V_274 ;
int V_29 = 0 ;
if ( V_2 -> V_46 == V_47 ) {
if ( F_17 ( ! V_142 -> V_223 || V_142 -> V_223 > V_2 -> V_344 ) )
goto V_426;
V_274 = F_164 ( V_2 , V_425 ) ;
} else {
if ( F_17 ( ! V_142 -> V_223 ) )
goto V_426;
V_274 = NULL ;
if ( F_63 ( ( V_425 != V_114 ) || ! V_427 ) ) {
int V_42 = F_169 ( V_425 ) ;
if ( F_17 ( V_42 > V_142 -> V_223 || V_42 > V_2 -> V_344 ) )
goto V_426;
V_274 = F_149 ;
} else {
if ( F_17 ( V_142 -> V_223 > 16 ) )
goto V_426;
V_274 = F_164 ( V_2 , V_425 ) ;
}
}
if ( V_274 )
V_29 = F_102 ( V_2 , V_142 , V_274 ) ;
else
F_170 ( V_2 , V_142 ) ;
return V_29 ;
V_426:
F_97 ( L_51 ,
V_142 -> V_223 , V_425 , V_2 -> V_344 ) ;
V_142 -> V_57 = V_284 << 16 ;
V_142 -> V_76 ( V_142 ) ;
return 0 ;
}
int F_171 ( struct V_7 * V_8 , struct V_52 * V_53 )
{
struct V_9 * V_10 ;
struct V_25 * V_2 ;
struct V_21 * V_98 = V_53 -> V_1 ;
int V_29 = 0 ;
unsigned long V_428 ;
V_10 = F_3 ( V_8 ) ;
F_5 ( V_10 -> V_18 , V_428 ) ;
F_166 ( V_10 , V_53 ) ;
V_2 = F_11 ( V_10 , V_98 ) ;
if ( F_63 ( V_2 ) )
V_29 = F_168 ( V_53 , V_2 ) ;
else {
V_53 -> V_57 = ( V_429 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
}
F_7 ( V_10 -> V_18 , V_428 ) ;
return V_29 ;
}
void F_170 ( struct V_25 * V_2 , struct V_52 * V_53 )
{
struct V_293 args ;
const T_3 * V_136 = V_53 -> V_222 ;
T_3 V_430 ;
args . V_2 = V_2 ;
args . V_89 = V_2 -> V_89 ;
args . V_53 = V_53 ;
args . V_431 = V_53 -> V_76 ;
switch( V_136 [ 0 ] ) {
case V_432 :
F_28 ( V_53 ) ;
break;
case V_353 :
if ( V_136 [ 1 ] & 2 )
F_28 ( V_53 ) ;
else if ( ( V_136 [ 1 ] & 1 ) == 0 )
F_172 ( & args , F_109 ) ;
else switch ( V_136 [ 2 ] ) {
case 0x00 :
F_172 ( & args , F_111 ) ;
break;
case 0x80 :
F_172 ( & args , F_112 ) ;
break;
case 0x83 :
F_172 ( & args , F_113 ) ;
break;
case 0x89 :
F_172 ( & args , F_115 ) ;
break;
case 0xb0 :
F_172 ( & args , F_117 ) ;
break;
case 0xb1 :
F_172 ( & args , F_123 ) ;
break;
case 0xb2 :
F_172 ( & args , F_126 ) ;
break;
default:
F_28 ( V_53 ) ;
break;
}
break;
case V_327 :
case V_433 :
F_172 ( & args , F_137 ) ;
break;
case V_340 :
F_172 ( & args , F_138 ) ;
break;
case V_434 :
if ( ( V_136 [ 1 ] & 0x1f ) == V_435 )
F_172 ( & args , F_138 ) ;
else
F_28 ( V_53 ) ;
break;
case V_436 :
F_172 ( & args , F_141 ) ;
break;
case V_345 :
F_20 ( V_53 , 0 , 0 , 0 ) ;
V_53 -> V_57 = ( V_58 << 24 ) ;
V_53 -> V_76 ( V_53 ) ;
break;
case V_422 :
case V_437 :
case V_438 :
case V_439 :
case V_440 :
F_172 ( & args , F_127 ) ;
break;
case V_441 :
V_430 = V_136 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_430 == 0x4 ) && ( ! V_136 [ 3 ] ) && ( ! V_136 [ 4 ] ) )
F_172 ( & args , F_127 ) ;
else
F_28 ( V_53 ) ;
break;
default:
F_20 ( V_53 , V_75 , 0x20 , 0x0 ) ;
V_53 -> V_76 ( V_53 ) ;
break;
}
}
int F_173 ( struct V_442 * V_30 , struct V_443 * V_444 )
{
int V_158 , V_29 ;
for ( V_158 = 0 ; V_158 < V_30 -> V_445 ; V_158 ++ ) {
struct V_9 * V_10 = V_30 -> V_446 [ V_158 ] ;
struct V_7 * V_8 ;
V_29 = - V_109 ;
V_8 = F_174 ( V_444 , sizeof( struct V_9 * ) ) ;
if ( ! V_8 )
goto V_447;
V_8 -> V_448 = 1 ;
* (struct V_9 * * ) & V_8 -> V_449 [ 0 ] = V_10 ;
V_10 -> V_450 = V_8 ;
V_8 -> V_451 = V_452 ;
V_8 -> V_453 = V_10 -> V_175 ;
V_8 -> V_454 = 16 ;
V_8 -> V_455 = 1 ;
V_8 -> V_456 = 1 ;
V_8 -> V_457 = 16 ;
V_8 -> V_458 = 1 ;
V_29 = F_175 ( V_10 -> V_450 ,
& V_10 -> V_459 , V_10 -> V_30 -> V_2 ) ;
if ( V_29 )
goto V_460;
}
return 0 ;
V_460:
F_176 ( V_30 -> V_446 [ V_158 ] -> V_450 ) ;
V_447:
while ( -- V_158 >= 0 ) {
struct V_7 * V_8 = V_30 -> V_446 [ V_158 ] -> V_450 ;
F_177 ( V_8 ) ;
F_176 ( V_8 ) ;
}
return V_29 ;
}
void F_178 ( struct V_9 * V_10 , int V_461 )
{
int V_462 = 5 ;
struct V_25 * V_463 = NULL ;
struct V_23 * V_24 ;
struct V_25 * V_2 ;
V_464:
F_179 (link, ap, EDGE) {
F_180 (dev, link, ENABLED) {
struct V_21 * V_22 ;
int V_361 = 0 , V_89 = 0 ;
if ( V_2 -> V_22 )
continue;
if ( F_181 ( V_24 ) )
V_89 = V_2 -> V_40 ;
else
V_361 = V_24 -> V_465 ;
V_22 = F_182 ( V_10 -> V_450 , V_361 , V_89 , 0 ,
NULL ) ;
if ( ! F_183 ( V_22 ) ) {
V_2 -> V_22 = V_22 ;
F_184 ( V_22 ) ;
F_185 ( V_2 ) ;
} else {
V_2 -> V_22 = NULL ;
}
}
}
F_179 (link, ap, EDGE) {
F_180 (dev, link, ENABLED) {
if ( ! V_2 -> V_22 )
goto V_466;
}
}
V_466:
if ( ! V_24 )
return;
if ( V_461 ) {
if ( V_2 != V_463 ) {
F_186 ( 100 ) ;
V_463 = V_2 ;
goto V_464;
}
if ( -- V_462 ) {
F_186 ( 100 ) ;
goto V_464;
}
F_187 ( V_10 ,
L_52 ) ;
}
F_188 ( V_467 , & V_10 -> V_468 ,
F_189 ( V_116 ) ) ;
}
int F_190 ( struct V_25 * V_2 )
{
if ( V_2 -> V_22 ) {
F_191 ( V_2 -> V_22 , V_469 ) ;
return 1 ;
}
return 0 ;
}
static void F_192 ( struct V_25 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_24 -> V_10 ;
struct V_21 * V_22 ;
unsigned long V_13 ;
F_193 ( & V_10 -> V_450 -> V_470 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
F_194 ( V_2 ) ;
V_22 = V_2 -> V_22 ;
V_2 -> V_22 = NULL ;
if ( V_22 ) {
if ( F_195 ( V_22 ) == 0 ) {
F_191 ( V_22 , V_469 ) ;
} else {
F_196 ( 1 ) ;
V_22 = NULL ;
}
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_197 ( & V_10 -> V_450 -> V_470 ) ;
if ( V_22 ) {
F_198 ( V_2 , L_53 ,
F_199 ( & V_22 -> V_471 ) ) ;
F_200 ( V_22 ) ;
F_184 ( V_22 ) ;
}
}
static void F_201 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_10 ;
struct V_25 * V_2 ;
F_180 (dev, link, ALL) {
unsigned long V_13 ;
if ( ! ( V_2 -> V_13 & V_472 ) )
continue;
F_5 ( V_10 -> V_18 , V_13 ) ;
V_2 -> V_13 &= ~ V_472 ;
F_7 ( V_10 -> V_18 , V_13 ) ;
F_192 ( V_2 ) ;
}
}
void F_202 ( struct V_25 * V_2 )
{
if ( V_2 -> V_22 )
F_203 ( V_2 -> V_22 , V_207 ,
V_473 ) ;
}
void F_204 ( struct V_474 * V_475 )
{
struct V_9 * V_10 =
F_205 ( V_475 , struct V_9 , V_468 . V_475 ) ;
int V_158 ;
if ( V_10 -> V_36 & V_476 ) {
F_97 ( L_54 ) ;
return;
}
F_97 ( L_34 ) ;
F_193 ( & V_10 -> V_477 ) ;
F_201 ( & V_10 -> V_24 ) ;
if ( V_10 -> V_360 )
for ( V_158 = 0 ; V_158 < V_478 ; V_158 ++ )
F_201 ( & V_10 -> V_360 [ V_158 ] ) ;
F_178 ( V_10 , 0 ) ;
F_197 ( & V_10 -> V_477 ) ;
F_97 ( L_36 ) ;
}
int F_206 ( struct V_7 * V_8 , unsigned int V_361 ,
unsigned int V_89 , unsigned int V_362 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_13 ;
int V_40 , V_29 = 0 ;
if ( ! V_10 -> V_61 -> V_170 )
return - V_34 ;
if ( V_362 != V_479 && V_362 )
return - V_17 ;
if ( ! F_153 ( V_10 ) ) {
if ( V_361 != V_479 && V_361 )
return - V_17 ;
V_40 = V_89 ;
} else {
if ( V_89 != V_479 && V_89 )
return - V_17 ;
V_40 = V_361 ;
}
F_5 ( V_10 -> V_18 , V_13 ) ;
if ( V_40 == V_479 ) {
struct V_23 * V_24 ;
F_179 (link, ap, EDGE) {
struct V_480 * V_481 = & V_24 -> V_48 ;
V_481 -> V_482 |= V_483 ;
V_481 -> V_84 |= V_85 ;
}
} else {
struct V_25 * V_2 = F_152 ( V_10 , V_40 ) ;
if ( V_2 ) {
struct V_480 * V_481 = & V_2 -> V_24 -> V_48 ;
V_481 -> V_482 |= 1 << V_2 -> V_40 ;
V_481 -> V_84 |= V_85 ;
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
void F_207 ( struct V_474 * V_475 )
{
struct V_9 * V_10 =
F_205 ( V_475 , struct V_9 , V_484 ) ;
struct V_23 * V_24 ;
struct V_25 * V_2 ;
unsigned long V_13 ;
F_193 ( & V_10 -> V_477 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
F_179 (link, ap, EDGE) {
F_180 (dev, link, ENABLED) {
struct V_21 * V_22 = V_2 -> V_22 ;
if ( ! V_22 )
continue;
if ( F_195 ( V_22 ) )
continue;
F_7 ( V_10 -> V_18 , V_13 ) ;
F_208 ( & ( V_22 -> V_471 ) ) ;
F_184 ( V_22 ) ;
F_5 ( V_10 -> V_18 , V_13 ) ;
}
}
F_7 ( V_10 -> V_18 , V_13 ) ;
F_197 ( & V_10 -> V_477 ) ;
}
struct V_9 * F_209 ( struct V_442 * V_30 ,
struct V_485 * V_486 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_210 ( V_30 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_487 = 0 ;
V_10 -> V_18 = & V_30 -> V_18 ;
V_10 -> V_488 = V_486 -> V_488 ;
V_10 -> V_489 = V_486 -> V_489 ;
V_10 -> V_490 = V_486 -> V_490 ;
V_10 -> V_13 |= V_486 -> V_13 ;
V_10 -> V_61 = V_486 -> V_491 ;
V_10 -> V_492 = V_493 ;
return V_10 ;
}
int F_211 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_61 -> V_170 )
V_10 -> V_36 &= ~ V_494 ;
return 0 ;
}
void F_212 ( struct V_9 * V_10 )
{
}
void F_213 ( struct V_9 * V_10 )
{
F_214 ( V_10 ) ;
}
int F_215 ( struct V_9 * V_10 )
{
return F_216 ( V_10 ) ;
}
int F_217 ( struct V_9 * V_10 )
{
int V_29 = V_10 -> V_61 -> V_495 ( V_10 ) ;
if ( V_29 )
return V_29 ;
V_10 -> V_175 = F_218 ( & V_496 ) ;
return 0 ;
}
void F_219 ( struct V_9 * V_10 )
{
if ( V_10 -> V_61 -> V_497 )
V_10 -> V_61 -> V_497 ( V_10 ) ;
F_43 ( V_10 ) ;
}
int F_220 ( struct V_21 * V_22 , struct V_9 * V_10 )
{
F_61 ( V_22 ) ;
F_66 ( V_22 , V_10 -> V_24 . V_1 ) ;
return 0 ;
}
int F_221 ( struct V_52 * V_53 , struct V_9 * V_10 )
{
int V_29 = 0 ;
F_166 ( V_10 , V_53 ) ;
if ( F_63 ( F_84 ( V_10 -> V_24 . V_1 ) ) )
V_29 = F_168 ( V_53 , V_10 -> V_24 . V_1 ) ;
else {
V_53 -> V_57 = ( V_429 << 16 ) ;
V_53 -> V_76 ( V_53 ) ;
}
return V_29 ;
}
