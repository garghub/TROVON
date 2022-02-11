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
static void F_22 ( struct V_56 * V_57 , T_3 V_58 , T_3 V_59 , T_3 V_60 )
{
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
F_23 ( 0 , V_57 -> V_64 , V_58 , V_59 , V_60 ) ;
}
static T_1
F_24 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_65 -> V_66 && ( V_9 -> V_16 & V_67 ) )
return V_9 -> V_65 -> V_66 ( V_9 , V_4 , V_5 ) ;
return - V_20 ;
}
static T_1
F_25 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_65 -> V_68 && ( V_9 -> V_16 & V_67 ) )
return V_9 -> V_65 -> V_68 ( V_9 , V_4 ) ;
return - V_20 ;
}
static T_1
F_26 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_4 , 23 , L_3 , V_9 -> V_69 ) ;
}
static T_1
F_27 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_70 = F_13 ( V_9 , V_29 ) ;
if ( V_70 && V_9 -> V_65 -> V_71 &&
( V_9 -> V_16 & V_72 ) )
return V_9 -> V_65 -> V_71 ( V_70 , V_4 ) ;
return - V_20 ;
}
static T_1
F_28 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_70 = F_13 ( V_9 , V_29 ) ;
enum V_73 V_74 ;
int V_33 ;
if ( V_70 && V_9 -> V_65 -> V_75 &&
( V_9 -> V_16 & V_72 ) ) {
V_74 = F_29 ( V_4 , NULL , 0 ) ;
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
static void F_30 ( struct V_56 * V_57 )
{
F_22 ( V_57 , V_79 , 0x24 , 0x0 ) ;
V_57 -> V_80 ( V_57 ) ;
}
int F_31 ( struct V_28 * V_29 , struct V_81 * V_82 ,
T_4 V_83 , int V_84 [] )
{
V_84 [ 0 ] = 255 ;
V_84 [ 1 ] = 63 ;
F_32 ( V_83 , 255 * 63 ) ;
V_84 [ 2 ] = V_83 ;
return 0 ;
}
void F_33 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_13 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_85 < V_13 -> V_86 ) {
V_13 -> V_16 |= V_87 ;
V_13 -> V_11 -> V_52 . V_88 |= V_89 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_34 ( V_9 ) ;
}
static int F_35 ( struct V_8 * V_9 , struct V_28 * V_29 ,
void T_5 * V_90 )
{
struct V_12 * V_13 = F_13 ( V_9 , V_29 ) ;
T_6 T_5 * V_91 = V_90 ;
char V_4 [ 40 ] ;
if ( ! V_13 )
return - V_92 ;
if ( F_36 ( V_91 , V_13 -> V_93 , V_94 * sizeof( T_6 ) ) )
return - V_95 ;
F_37 ( V_13 -> V_93 , V_4 , V_96 , V_97 ) ;
if ( F_36 ( V_91 + V_96 , V_4 , V_97 ) )
return - V_95 ;
F_37 ( V_13 -> V_93 , V_4 , V_98 , V_99 ) ;
if ( F_36 ( V_91 + V_98 , V_4 , V_99 ) )
return - V_95 ;
F_37 ( V_13 -> V_93 , V_4 , V_100 , V_101 ) ;
if ( F_36 ( V_91 + V_100 , V_4 , V_101 ) )
return - V_95 ;
return 0 ;
}
int F_38 ( struct V_28 * V_102 , void T_5 * V_90 )
{
int V_33 = 0 ;
T_3 V_103 [ V_104 ] ;
T_3 args [ 4 ] , * V_105 = NULL , * V_106 = NULL ;
int V_107 = 0 ;
enum V_108 V_109 ;
int V_110 ;
if ( V_90 == NULL )
return - V_20 ;
if ( F_39 ( args , V_90 , sizeof( args ) ) )
return - V_95 ;
V_106 = F_40 ( V_111 , V_112 ) ;
if ( ! V_106 )
return - V_113 ;
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
if ( args [ 3 ] ) {
V_107 = V_114 * args [ 3 ] ;
V_105 = F_41 ( V_107 , V_115 ) ;
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
V_110 = F_42 ( V_102 , V_103 , V_109 , V_105 , V_107 ,
V_106 , ( 10 * V_120 ) , 5 , 0 , NULL ) ;
if ( F_43 ( V_110 ) == V_62 ) {
T_3 * V_121 = V_106 + 8 ;
V_110 &= ~ ( 0xFF << 24 ) ;
if ( V_110 & V_63 ) {
struct V_122 V_123 ;
F_44 ( V_106 , V_111 ,
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
if ( F_36 ( V_90 , args , sizeof( args ) ) )
V_33 = - V_95 ;
}
}
if ( V_110 ) {
V_33 = - V_126 ;
goto error;
}
if ( ( V_105 )
&& F_36 ( V_90 + sizeof( args ) , V_105 , V_107 ) )
V_33 = - V_95 ;
error:
F_45 ( V_106 ) ;
F_45 ( V_105 ) ;
return V_33 ;
}
int F_46 ( struct V_28 * V_102 , void T_5 * V_90 )
{
int V_33 = 0 ;
T_3 V_103 [ V_104 ] ;
T_3 args [ 7 ] , * V_106 = NULL ;
int V_110 ;
if ( V_90 == NULL )
return - V_20 ;
if ( F_39 ( args , V_90 , sizeof( args ) ) )
return - V_95 ;
V_106 = F_40 ( V_111 , V_112 ) ;
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
V_110 = F_42 ( V_102 , V_103 , V_117 , NULL , 0 ,
V_106 , ( 10 * V_120 ) , 5 , 0 , NULL ) ;
if ( F_43 ( V_110 ) == V_62 ) {
T_3 * V_121 = V_106 + 8 ;
V_110 &= ~ ( 0xFF << 24 ) ;
if ( V_110 & V_63 ) {
struct V_122 V_123 ;
F_44 ( V_106 , V_111 ,
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
if ( F_36 ( V_90 , args , sizeof( args ) ) )
V_33 = - V_95 ;
}
}
if ( V_110 ) {
V_33 = - V_126 ;
goto error;
}
error:
F_45 ( V_106 ) ;
return V_33 ;
}
static int F_47 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 & V_127 )
return 1 ;
if ( V_9 -> V_39 & V_128 )
return 1 ;
return 0 ;
}
int F_48 ( struct V_8 * V_9 , struct V_28 * V_102 ,
int V_57 , void T_5 * V_90 )
{
int V_74 = - V_20 , V_33 = - V_20 ;
unsigned long V_16 ;
switch ( V_57 ) {
case V_129 :
F_5 ( V_9 -> V_21 , V_16 ) ;
V_74 = F_47 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_36 ( V_90 , & V_74 , 1 ) )
return - V_95 ;
return 0 ;
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
if ( V_74 != F_47 ( V_9 ) )
V_33 = - V_20 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
case V_132 :
return F_35 ( V_9 , V_102 , V_90 ) ;
case V_133 :
if ( ! F_49 ( V_134 ) || ! F_49 ( V_135 ) )
return - V_136 ;
return F_38 ( V_102 , V_90 ) ;
case V_137 :
if ( ! F_49 ( V_134 ) || ! F_49 ( V_135 ) )
return - V_136 ;
return F_46 ( V_102 , V_90 ) ;
default:
V_33 = - V_138 ;
break;
}
return V_33 ;
}
int F_50 ( struct V_28 * V_102 , int V_57 , void T_5 * V_90 )
{
return F_48 ( F_3 ( V_102 -> V_34 ) ,
V_102 , V_57 , V_90 ) ;
}
static struct V_139 * F_51 ( struct V_12 * V_13 ,
struct V_56 * V_57 )
{
struct V_139 * V_140 ;
V_140 = F_52 ( V_13 ) ;
if ( V_140 ) {
V_140 -> V_141 = V_57 ;
V_140 -> V_142 = V_57 -> V_80 ;
V_140 -> V_143 = F_53 ( V_57 ) ;
V_140 -> V_144 = F_54 ( V_57 ) ;
} else {
V_57 -> V_61 = ( V_145 << 16 ) | ( V_146 << 1 ) ;
V_57 -> V_80 ( V_57 ) ;
}
return V_140 ;
}
static void F_55 ( struct V_139 * V_140 )
{
struct V_56 * V_147 = V_140 -> V_141 ;
V_140 -> V_148 = V_147 -> V_149 -> V_150 ;
V_140 -> V_151 = F_56 ( V_147 ) + V_140 -> V_148 ;
}
static void F_57 ( unsigned V_93 , struct V_152 * V_153 )
{
T_3 V_154 = V_153 -> V_155 , V_156 = V_153 -> V_157 ;
F_58 ( V_158 L_4 , V_93 , V_154 ) ;
if ( V_154 & V_159 ) {
F_58 ( L_5 ) ;
} else {
if ( V_154 & 0x40 ) F_58 ( L_6 ) ;
if ( V_154 & 0x20 ) F_58 ( L_7 ) ;
if ( V_154 & 0x10 ) F_58 ( L_8 ) ;
if ( V_154 & 0x08 ) F_58 ( L_9 ) ;
if ( V_154 & 0x04 ) F_58 ( L_10 ) ;
if ( V_154 & 0x02 ) F_58 ( L_11 ) ;
if ( V_154 & 0x01 ) F_58 ( L_12 ) ;
F_58 ( L_13 ) ;
if ( V_156 ) {
F_58 ( V_158 L_14 , V_93 , V_156 ) ;
if ( V_156 & 0x04 ) F_58 ( L_15 ) ;
if ( V_156 & 0x80 ) {
if ( V_156 & 0x04 ) F_58 ( L_16 ) ;
else F_58 ( L_17 ) ;
}
if ( V_156 & 0x40 ) F_58 ( L_18 ) ;
if ( V_156 & 0x10 ) F_58 ( L_19 ) ;
if ( V_156 & 0x02 ) F_58 ( L_20 ) ;
if ( V_156 & 0x01 ) F_58 ( L_21 ) ;
F_58 ( L_13 ) ;
}
}
}
static void F_59 ( unsigned V_93 , T_3 V_160 , T_3 V_161 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 , int V_162 )
{
int V_163 ;
static const unsigned char V_164 [] [ 4 ] = {
{ 0xd1 , V_165 , 0x00 , 0x00 } ,
{ 0xd0 , V_165 , 0x00 , 0x00 } ,
{ 0x61 , V_166 , 0x00 , 0x00 } ,
{ 0x84 , V_165 , 0x47 , 0x00 } ,
{ 0x37 , V_167 , 0x04 , 0x00 } ,
{ 0x09 , V_167 , 0x04 , 0x00 } ,
{ 0x01 , V_168 , 0x13 , 0x00 } ,
{ 0x02 , V_166 , 0x00 , 0x00 } ,
{ 0x08 , V_167 , 0x04 , 0x00 } ,
{ 0x10 , V_79 , 0x21 , 0x00 } ,
{ 0x20 , V_169 , 0x28 , 0x00 } ,
{ 0x40 , V_168 , 0x11 , 0x04 } ,
{ 0x80 , V_168 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_170 [] [ 4 ] = {
{ 0x80 , V_165 , 0x47 , 0x00 } ,
{ 0x20 , V_166 , 0x44 , 0x00 } ,
{ 0x08 , V_165 , 0x47 , 0x00 } ,
{ 0x04 , V_125 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_160 & V_159 ) {
V_161 = 0 ;
}
if ( V_161 ) {
for ( V_163 = 0 ; V_164 [ V_163 ] [ 0 ] != 0xFF ; V_163 ++ ) {
if ( ( V_164 [ V_163 ] [ 0 ] & V_161 ) ==
V_164 [ V_163 ] [ 0 ] ) {
* V_58 = V_164 [ V_163 ] [ 1 ] ;
* V_59 = V_164 [ V_163 ] [ 2 ] ;
* V_60 = V_164 [ V_163 ] [ 3 ] ;
goto V_171;
}
}
}
for ( V_163 = 0 ; V_170 [ V_163 ] [ 0 ] != 0xFF ; V_163 ++ ) {
if ( V_170 [ V_163 ] [ 0 ] & V_160 ) {
* V_58 = V_170 [ V_163 ] [ 1 ] ;
* V_59 = V_170 [ V_163 ] [ 2 ] ;
* V_60 = V_170 [ V_163 ] [ 3 ] ;
goto V_171;
}
}
* V_58 = V_165 ;
* V_59 = 0x00 ;
* V_60 = 0x00 ;
V_171:
if ( V_162 )
F_58 ( V_172 L_22
L_23 ,
V_93 , V_160 , V_161 , * V_58 , * V_59 , * V_60 ) ;
return;
}
static void F_60 ( struct V_139 * V_140 )
{
struct V_56 * V_57 = V_140 -> V_141 ;
struct V_152 * V_153 = & V_140 -> V_173 ;
unsigned char * V_174 = V_57 -> V_64 ;
unsigned char * V_121 = V_174 + 8 ;
int V_162 = V_140 -> V_9 -> V_65 -> V_175 == NULL ;
memset ( V_174 , 0 , V_111 ) ;
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
if ( V_140 -> V_176 ||
V_153 -> V_155 & ( V_159 | V_177 | V_178 | V_179 ) ) {
F_59 ( V_140 -> V_9 -> V_180 , V_153 -> V_155 , V_153 -> V_157 ,
& V_174 [ 1 ] , & V_174 [ 2 ] , & V_174 [ 3 ] , V_162 ) ;
V_174 [ 1 ] &= 0x0f ;
} else {
V_174 [ 1 ] = V_125 ;
V_174 [ 2 ] = 0 ;
V_174 [ 3 ] = 0x1D ;
}
V_174 [ 0 ] = 0x72 ;
V_121 [ 0 ] = 0x09 ;
V_174 [ 7 ] = 14 ;
V_121 [ 1 ] = 12 ;
V_121 [ 2 ] = 0x00 ;
V_121 [ 3 ] = V_153 -> V_157 ;
V_121 [ 5 ] = V_153 -> V_181 ;
V_121 [ 7 ] = V_153 -> V_182 ;
V_121 [ 9 ] = V_153 -> V_183 ;
V_121 [ 11 ] = V_153 -> V_184 ;
V_121 [ 12 ] = V_153 -> V_1 ;
V_121 [ 13 ] = V_153 -> V_155 ;
if ( V_153 -> V_16 & V_185 ) {
V_121 [ 2 ] |= 0x01 ;
V_121 [ 4 ] = V_153 -> V_186 ;
V_121 [ 6 ] = V_153 -> V_187 ;
V_121 [ 8 ] = V_153 -> V_188 ;
V_121 [ 10 ] = V_153 -> V_189 ;
}
}
static void F_61 ( struct V_139 * V_140 )
{
struct V_12 * V_13 = V_140 -> V_13 ;
struct V_56 * V_57 = V_140 -> V_141 ;
struct V_152 * V_153 = & V_140 -> V_173 ;
unsigned char * V_174 = V_57 -> V_64 ;
unsigned char * V_121 = V_174 + 8 ;
int V_162 = V_140 -> V_9 -> V_65 -> V_175 == NULL ;
T_7 V_190 ;
memset ( V_174 , 0 , V_111 ) ;
V_57 -> V_61 = ( V_62 << 24 ) | V_63 ;
V_174 [ 0 ] = 0x72 ;
if ( V_140 -> V_176 ||
V_153 -> V_155 & ( V_159 | V_177 | V_178 | V_179 ) ) {
F_59 ( V_140 -> V_9 -> V_180 , V_153 -> V_155 , V_153 -> V_157 ,
& V_174 [ 1 ] , & V_174 [ 2 ] , & V_174 [ 3 ] , V_162 ) ;
V_174 [ 1 ] &= 0x0f ;
}
V_190 = F_62 ( & V_140 -> V_173 , V_13 ) ;
V_174 [ 7 ] = 12 ;
V_121 [ 0 ] = 0x00 ;
V_121 [ 1 ] = 10 ;
V_121 [ 2 ] |= 0x80 ;
V_121 [ 6 ] = V_190 >> 40 ;
V_121 [ 7 ] = V_190 >> 32 ;
V_121 [ 8 ] = V_190 >> 24 ;
V_121 [ 9 ] = V_190 >> 16 ;
V_121 [ 10 ] = V_190 >> 8 ;
V_121 [ 11 ] = V_190 ;
}
static void F_63 ( struct V_28 * V_29 )
{
V_29 -> V_191 = 1 ;
V_29 -> V_192 = 1 ;
V_29 -> V_193 = 1 ;
V_29 -> V_194 = 1 ;
V_29 -> V_195 = 1 ;
}
static int F_64 ( struct V_149 * V_196 )
{
if ( F_65 ( V_196 -> V_197 != V_198 ) )
return 0 ;
if ( ! F_66 ( V_196 ) || ( V_196 -> V_199 & V_200 ) )
return 0 ;
return F_67 ( V_196 -> V_57 [ 0 ] ) == V_201 ;
}
static int F_68 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_202 * V_203 = V_29 -> V_202 ;
if ( ! F_69 ( V_13 -> V_93 ) )
V_13 -> V_16 |= V_37 ;
F_70 ( V_203 , V_13 -> V_204 ) ;
if ( V_13 -> V_49 == V_205 ) {
void * V_4 ;
V_29 -> V_206 = V_114 ;
F_71 ( V_203 , V_207 - 1 ) ;
V_4 = F_41 ( V_208 , V_203 -> V_209 | V_115 ) ;
if ( ! V_4 ) {
F_72 ( V_13 , L_24 ) ;
return - V_113 ;
}
F_73 ( V_203 , F_64 , V_4 , V_208 ) ;
} else {
V_29 -> V_206 = F_74 ( V_13 -> V_93 ) ;
V_29 -> V_210 = 1 ;
}
if ( V_29 -> V_206 > V_27 )
F_75 ( V_13 ,
L_25 ,
V_29 -> V_206 ) ;
F_76 ( V_203 , V_29 -> V_206 - 1 ) ;
if ( V_13 -> V_16 & V_211 )
F_77 ( V_212 , V_29 -> V_213 ) ;
if ( V_13 -> V_16 & V_214 ) {
int V_215 ;
V_215 = F_78 ( V_29 -> V_34 -> V_216 , F_79 ( V_13 -> V_93 ) ) ;
V_215 = F_78 ( V_217 - 1 , V_215 ) ;
F_80 ( V_29 , V_215 ) ;
}
F_81 ( V_203 , false ) ;
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
struct V_202 * V_203 = V_29 -> V_202 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_65 -> V_175 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_83 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_218 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_45 ( V_203 -> V_219 ) ;
V_203 -> V_219 = NULL ;
V_203 -> V_220 = 0 ;
}
int F_85 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_221 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_221 < 1 || V_221 == V_29 -> V_221 )
return V_29 -> V_221 ;
V_13 = F_13 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_86 ( V_13 ) )
return V_29 -> V_221 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_222 ;
if ( V_221 == 1 || ! F_87 ( V_13 ) ) {
V_13 -> V_16 |= V_222 ;
V_221 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_221 = F_78 ( V_221 , V_29 -> V_34 -> V_216 ) ;
V_221 = F_78 ( V_221 , F_79 ( V_13 -> V_93 ) ) ;
V_221 = F_78 ( V_221 , V_217 - 1 ) ;
if ( V_29 -> V_221 == V_221 )
return - V_20 ;
return F_80 ( V_29 , V_221 ) ;
}
int F_88 ( struct V_28 * V_29 , int V_221 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_85 ( V_9 , V_29 , V_221 ) ;
}
static unsigned int F_89 ( struct V_139 * V_140 )
{
struct V_56 * V_147 = V_140 -> V_141 ;
struct V_152 * V_153 = & V_140 -> V_153 ;
const T_3 * V_223 = V_147 -> V_224 ;
if ( V_147 -> V_225 < 5 )
goto V_226;
V_153 -> V_16 |= V_227 | V_228 ;
V_153 -> V_229 = V_230 ;
if ( V_223 [ 1 ] & 0x1 ) {
;
}
if ( V_223 [ 4 ] & 0x2 )
goto V_226;
if ( ( ( V_223 [ 4 ] >> 4 ) & 0xf ) != 0 )
goto V_226;
if ( V_223 [ 4 ] & 0x1 ) {
V_153 -> V_181 = 1 ;
if ( V_140 -> V_13 -> V_16 & V_231 ) {
V_153 -> V_16 |= V_232 ;
V_153 -> V_184 = 0x0 ;
V_153 -> V_183 = 0x0 ;
V_153 -> V_182 = 0x0 ;
V_153 -> V_1 |= V_233 ;
} else {
V_153 -> V_182 = 0x1 ;
V_153 -> V_183 = 0x0 ;
V_153 -> V_184 = 0x0 ;
}
V_153 -> V_155 = V_234 ;
} else {
if ( ( V_140 -> V_9 -> V_16 & V_235 ) &&
V_236 == V_237 )
goto V_238;
if ( ( V_140 -> V_9 -> V_16 & V_239 ) &&
F_90 () )
goto V_238;
V_153 -> V_155 = V_240 ;
}
return 0 ;
V_226:
F_22 ( V_147 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_238:
V_147 -> V_61 = V_241 ;
return 1 ;
}
static unsigned int F_91 ( struct V_139 * V_140 )
{
struct V_152 * V_153 = & V_140 -> V_153 ;
V_153 -> V_16 |= V_227 ;
V_153 -> V_229 = V_230 ;
if ( V_140 -> V_13 -> V_16 & V_242 )
V_153 -> V_155 = V_243 ;
else
V_153 -> V_155 = V_244 ;
V_140 -> V_16 |= V_245 ;
return 0 ;
}
static void F_92 ( const T_3 * V_223 , T_7 * V_246 , T_8 * V_247 )
{
T_7 V_248 = 0 ;
T_8 V_45 ;
F_93 ( L_26 ) ;
V_248 |= ( ( T_7 ) ( V_223 [ 1 ] & 0x1f ) ) << 16 ;
V_248 |= ( ( T_7 ) V_223 [ 2 ] ) << 8 ;
V_248 |= ( ( T_7 ) V_223 [ 3 ] ) ;
V_45 = V_223 [ 4 ] ;
* V_246 = V_248 ;
* V_247 = V_45 ;
}
static void F_94 ( const T_3 * V_223 , T_7 * V_246 , T_8 * V_247 )
{
T_7 V_248 = 0 ;
T_8 V_45 = 0 ;
F_93 ( L_27 ) ;
V_248 |= ( ( T_7 ) V_223 [ 2 ] ) << 24 ;
V_248 |= ( ( T_7 ) V_223 [ 3 ] ) << 16 ;
V_248 |= ( ( T_7 ) V_223 [ 4 ] ) << 8 ;
V_248 |= ( ( T_7 ) V_223 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_223 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_223 [ 8 ] ) ;
* V_246 = V_248 ;
* V_247 = V_45 ;
}
static void F_95 ( const T_3 * V_223 , T_7 * V_246 , T_8 * V_247 )
{
T_7 V_248 = 0 ;
T_8 V_45 = 0 ;
F_93 ( L_28 ) ;
V_248 |= ( ( T_7 ) V_223 [ 2 ] ) << 56 ;
V_248 |= ( ( T_7 ) V_223 [ 3 ] ) << 48 ;
V_248 |= ( ( T_7 ) V_223 [ 4 ] ) << 40 ;
V_248 |= ( ( T_7 ) V_223 [ 5 ] ) << 32 ;
V_248 |= ( ( T_7 ) V_223 [ 6 ] ) << 24 ;
V_248 |= ( ( T_7 ) V_223 [ 7 ] ) << 16 ;
V_248 |= ( ( T_7 ) V_223 [ 8 ] ) << 8 ;
V_248 |= ( ( T_7 ) V_223 [ 9 ] ) ;
V_45 |= ( ( T_8 ) V_223 [ 10 ] ) << 24 ;
V_45 |= ( ( T_8 ) V_223 [ 11 ] ) << 16 ;
V_45 |= ( ( T_8 ) V_223 [ 12 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_223 [ 13 ] ) ;
* V_246 = V_248 ;
* V_247 = V_45 ;
}
static unsigned int F_96 ( struct V_139 * V_140 )
{
struct V_56 * V_147 = V_140 -> V_141 ;
struct V_152 * V_153 = & V_140 -> V_153 ;
struct V_12 * V_13 = V_140 -> V_13 ;
T_7 V_249 = V_140 -> V_13 -> V_85 ;
const T_3 * V_223 = V_147 -> V_224 ;
T_7 V_190 ;
T_8 V_250 ;
V_153 -> V_16 |= V_228 | V_227 ;
V_153 -> V_229 = V_230 ;
if ( V_223 [ 0 ] == V_251 ) {
if ( V_147 -> V_225 < 10 )
goto V_226;
F_94 ( V_223 , & V_190 , & V_250 ) ;
} else if ( V_223 [ 0 ] == V_252 ) {
if ( V_147 -> V_225 < 16 )
goto V_226;
F_95 ( V_223 , & V_190 , & V_250 ) ;
} else
goto V_226;
if ( ! V_250 )
goto V_253;
if ( V_190 >= V_249 )
goto V_254;
if ( ( V_190 + V_250 ) > V_249 )
goto V_254;
if ( V_13 -> V_16 & V_231 ) {
V_153 -> V_16 |= V_232 ;
if ( F_97 ( V_190 , V_250 ) ) {
V_153 -> V_155 = V_234 ;
V_153 -> V_1 |= ( V_190 >> 24 ) & 0xf ;
} else if ( F_98 ( V_190 , V_250 ) ) {
if ( ! ( V_13 -> V_16 & V_255 ) )
goto V_254;
V_153 -> V_16 |= V_185 ;
V_153 -> V_155 = V_256 ;
V_153 -> V_186 = ( V_250 >> 8 ) & 0xff ;
V_153 -> V_189 = ( V_190 >> 40 ) & 0xff ;
V_153 -> V_188 = ( V_190 >> 32 ) & 0xff ;
V_153 -> V_187 = ( V_190 >> 24 ) & 0xff ;
} else
goto V_254;
V_153 -> V_181 = V_250 & 0xff ;
V_153 -> V_184 = ( V_190 >> 16 ) & 0xff ;
V_153 -> V_183 = ( V_190 >> 8 ) & 0xff ;
V_153 -> V_182 = V_190 & 0xff ;
V_153 -> V_1 |= V_233 ;
} else {
T_8 V_257 , V_258 , V_259 , V_260 ;
if ( ! F_97 ( V_190 , V_250 ) )
goto V_254;
V_260 = ( T_8 ) V_190 / V_13 -> V_261 ;
V_259 = V_260 / V_13 -> V_262 ;
V_258 = V_260 % V_13 -> V_262 ;
V_257 = ( T_8 ) V_190 % V_13 -> V_261 + 1 ;
F_99 ( L_29 ,
( T_8 ) V_190 , V_260 , V_259 , V_258 , V_257 ) ;
if ( ( V_259 >> 16 ) || ( V_258 >> 4 ) || ( V_257 >> 8 ) || ( ! V_257 ) )
goto V_254;
V_153 -> V_155 = V_234 ;
V_153 -> V_181 = V_250 & 0xff ;
V_153 -> V_182 = V_257 ;
V_153 -> V_183 = V_259 ;
V_153 -> V_184 = V_259 >> 8 ;
V_153 -> V_1 |= V_258 ;
}
return 0 ;
V_226:
F_22 ( V_147 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_254:
F_22 ( V_147 , V_79 , 0x21 , 0x0 ) ;
return 1 ;
V_253:
V_147 -> V_61 = V_241 ;
return 1 ;
}
static unsigned int F_100 ( struct V_139 * V_140 )
{
struct V_56 * V_147 = V_140 -> V_141 ;
const T_3 * V_223 = V_147 -> V_224 ;
unsigned int V_263 = 0 ;
T_7 V_190 ;
T_8 V_250 ;
int V_33 ;
if ( V_223 [ 0 ] == V_264 || V_223 [ 0 ] == V_265 || V_223 [ 0 ] == V_266 )
V_263 |= V_267 ;
switch ( V_223 [ 0 ] ) {
case V_268 :
case V_264 :
if ( F_19 ( V_147 -> V_225 < 10 ) )
goto V_226;
F_94 ( V_223 , & V_190 , & V_250 ) ;
if ( V_223 [ 1 ] & ( 1 << 3 ) )
V_263 |= V_269 ;
break;
case V_270 :
case V_265 :
if ( F_19 ( V_147 -> V_225 < 6 ) )
goto V_226;
F_92 ( V_223 , & V_190 , & V_250 ) ;
if ( ! V_250 )
V_250 = 256 ;
break;
case V_271 :
case V_266 :
if ( F_19 ( V_147 -> V_225 < 16 ) )
goto V_226;
F_95 ( V_223 , & V_190 , & V_250 ) ;
if ( V_223 [ 1 ] & ( 1 << 3 ) )
V_263 |= V_269 ;
break;
default:
F_99 ( L_30 ) ;
goto V_226;
}
if ( ! V_250 )
goto V_253;
V_140 -> V_16 |= V_245 ;
V_140 -> V_151 = V_250 * V_147 -> V_1 -> V_206 ;
V_33 = F_101 ( & V_140 -> V_153 , V_140 -> V_13 , V_190 , V_250 , V_263 ,
V_140 -> V_272 ) ;
if ( F_65 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_273 )
goto V_254;
V_226:
F_22 ( V_147 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_254:
F_22 ( V_147 , V_79 , 0x21 , 0x0 ) ;
return 1 ;
V_253:
V_147 -> V_61 = V_241 ;
return 1 ;
}
static void F_102 ( struct V_139 * V_140 )
{
struct V_8 * V_9 = V_140 -> V_9 ;
struct V_56 * V_57 = V_140 -> V_141 ;
T_3 * V_223 = V_57 -> V_224 ;
int V_274 = ( V_140 -> V_176 != 0 ) ;
if ( ( ( V_223 [ 0 ] == V_118 ) || ( V_223 [ 0 ] == V_275 ) ) &&
( ( V_223 [ 2 ] & 0x20 ) || V_274 ) ) {
F_60 ( V_140 ) ;
} else {
if ( ! V_274 ) {
V_57 -> V_61 = V_241 ;
} else {
F_61 ( V_140 ) ;
}
}
if ( V_274 && ! V_9 -> V_65 -> V_175 )
F_57 ( V_9 -> V_180 , & V_140 -> V_173 ) ;
V_140 -> V_142 ( V_57 ) ;
F_103 ( V_140 ) ;
}
static int F_104 ( struct V_12 * V_13 , struct V_56 * V_57 ,
T_9 V_276 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_139 * V_140 ;
int V_33 ;
F_93 ( L_31 ) ;
V_140 = F_51 ( V_13 , V_57 ) ;
if ( ! V_140 )
goto V_277;
if ( V_57 -> V_278 == V_116 ||
V_57 -> V_278 == V_279 ) {
if ( F_19 ( F_56 ( V_57 ) < 1 ) ) {
F_75 ( V_13 , L_32 ) ;
goto V_280;
}
F_105 ( V_140 , F_53 ( V_57 ) , F_54 ( V_57 ) ) ;
V_140 -> V_281 = V_57 -> V_278 ;
}
V_140 -> V_282 = F_102 ;
if ( V_276 ( V_140 ) )
goto V_283;
if ( V_9 -> V_65 -> V_284 ) {
if ( ( V_33 = V_9 -> V_65 -> V_284 ( V_140 ) ) )
goto V_285;
}
F_106 ( V_140 ) ;
F_93 ( L_33 ) ;
return 0 ;
V_283:
F_103 ( V_140 ) ;
V_57 -> V_80 ( V_57 ) ;
F_99 ( L_34 ) ;
return 0 ;
V_280:
F_103 ( V_140 ) ;
V_57 -> V_61 = ( V_286 << 16 ) ;
V_57 -> V_80 ( V_57 ) ;
V_277:
F_99 ( L_35 ) ;
return 0 ;
V_285:
F_103 ( V_140 ) ;
F_99 ( L_36 ) ;
if ( V_33 == V_287 )
return V_288 ;
else
return V_289 ;
}
static void * F_107 ( struct V_56 * V_57 , bool V_290 ,
unsigned long * V_16 )
{
F_5 ( & V_291 , * V_16 ) ;
memset ( V_292 , 0 , V_293 ) ;
if ( V_290 )
F_108 ( F_53 ( V_57 ) , F_54 ( V_57 ) ,
V_292 , V_293 ) ;
return V_292 ;
}
static inline void F_109 ( struct V_56 * V_57 , bool V_294 ,
unsigned long * V_16 )
{
if ( V_294 )
F_110 ( F_53 ( V_57 ) , F_54 ( V_57 ) ,
V_292 , V_293 ) ;
F_9 ( & V_291 , * V_16 ) ;
}
static unsigned int F_111 ( struct V_295 * args , T_3 * V_296 )
{
const T_3 V_297 [] = {
0x00 ,
0x60 ,
0x03 ,
0x20 ,
0x02 ,
0x60
} ;
const T_3 V_298 [] = {
0x00 ,
0xA0 ,
0x04 ,
0xC0 ,
0x04 ,
0x60 ,
0x60 ,
0x20 ,
} ;
T_3 V_299 [] = {
V_300 ,
0 ,
0x5 ,
2 ,
95 - 4
} ;
F_93 ( L_31 ) ;
if ( F_112 ( args -> V_93 ) )
V_299 [ 1 ] |= ( 1 << 7 ) ;
if ( args -> V_13 -> V_49 == V_51 ) {
V_299 [ 0 ] = V_301 ;
V_299 [ 2 ] = 0x6 ;
}
memcpy ( V_296 , V_299 , sizeof( V_299 ) ) ;
memcpy ( & V_296 [ 8 ] , L_37 , 8 ) ;
F_37 ( args -> V_93 , & V_296 [ 16 ] , V_96 , 16 ) ;
F_37 ( args -> V_93 , & V_296 [ 32 ] , V_98 + 2 , 4 ) ;
if ( strncmp ( & V_296 [ 32 ] , L_38 , 4 ) == 0 )
F_37 ( args -> V_93 , & V_296 [ 32 ] , V_98 , 4 ) ;
if ( V_296 [ 32 ] == 0 || V_296 [ 32 ] == ' ' )
memcpy ( & V_296 [ 32 ] , L_39 , 4 ) ;
if ( args -> V_13 -> V_49 == V_51 )
memcpy ( V_296 + 58 , V_298 , sizeof( V_298 ) ) ;
else
memcpy ( V_296 + 58 , V_297 , sizeof( V_297 ) ) ;
return 0 ;
}
static unsigned int F_113 ( struct V_295 * args , T_3 * V_296 )
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
V_296 [ 3 ] = sizeof( V_302 ) ;
memcpy ( V_296 + 4 , V_302 , sizeof( V_302 ) ) ;
return 0 ;
}
static unsigned int F_114 ( struct V_295 * args , T_3 * V_296 )
{
const T_3 V_299 [] = {
0 ,
0x80 ,
0 ,
V_101 ,
} ;
memcpy ( V_296 , V_299 , sizeof( V_299 ) ) ;
F_37 ( args -> V_93 , ( unsigned char * ) & V_296 [ 4 ] ,
V_100 , V_101 ) ;
return 0 ;
}
static unsigned int F_115 ( struct V_295 * args , T_3 * V_296 )
{
const int V_303 = 68 ;
int V_304 ;
V_296 [ 1 ] = 0x83 ;
V_304 = 4 ;
V_296 [ V_304 + 0 ] = 2 ;
V_296 [ V_304 + 3 ] = V_101 ;
V_304 += 4 ;
F_37 ( args -> V_93 , ( unsigned char * ) V_296 + V_304 ,
V_100 , V_101 ) ;
V_304 += V_101 ;
V_296 [ V_304 + 0 ] = 2 ;
V_296 [ V_304 + 1 ] = 1 ;
V_296 [ V_304 + 3 ] = V_303 ;
V_304 += 4 ;
memcpy ( V_296 + V_304 , L_37 , 8 ) ;
V_304 += 8 ;
F_37 ( args -> V_93 , ( unsigned char * ) V_296 + V_304 , V_96 ,
V_97 ) ;
V_304 += V_97 ;
F_37 ( args -> V_93 , ( unsigned char * ) V_296 + V_304 , V_100 ,
V_101 ) ;
V_304 += V_101 ;
if ( F_116 ( args -> V_93 ) ) {
V_296 [ V_304 + 0 ] = 1 ;
V_296 [ V_304 + 1 ] = 3 ;
V_296 [ V_304 + 3 ] = V_305 ;
V_304 += 4 ;
F_37 ( args -> V_93 , ( unsigned char * ) V_296 + V_304 ,
V_306 , V_305 ) ;
V_304 += V_305 ;
}
V_296 [ 3 ] = V_304 - 4 ;
return 0 ;
}
static unsigned int F_117 ( struct V_295 * args , T_3 * V_296 )
{
struct V_152 V_153 ;
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_296 [ 1 ] = 0x89 ;
V_296 [ 2 ] = ( 0x238 >> 8 ) ;
V_296 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_296 [ 8 ] , L_40 , 8 ) ;
memcpy ( & V_296 [ 16 ] , L_41 , 16 ) ;
memcpy ( & V_296 [ 32 ] , V_307 , 4 ) ;
V_153 . V_155 = V_308 ;
V_153 . V_182 = 0x1 ;
V_153 . V_181 = 0x1 ;
F_118 ( & V_153 , 0 , 1 , & V_296 [ 36 ] ) ;
V_296 [ 36 ] = 0x34 ;
V_296 [ 56 ] = V_309 ;
memcpy ( & V_296 [ 60 ] , & args -> V_93 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_119 ( struct V_295 * args , T_3 * V_296 )
{
T_6 V_310 ;
V_296 [ 1 ] = 0xb0 ;
V_296 [ 3 ] = 0x3c ;
V_310 = 1 << F_120 ( args -> V_93 ) ;
F_121 ( V_310 , & V_296 [ 6 ] ) ;
if ( F_122 ( args -> V_93 ) ) {
F_123 ( 65535 * 512 / 8 , & V_296 [ 36 ] ) ;
F_124 ( 1 , & V_296 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_125 ( struct V_295 * args , T_3 * V_296 )
{
int V_311 = F_126 ( args -> V_93 ) ;
int V_312 = F_127 ( args -> V_93 ) ;
V_296 [ 1 ] = 0xb1 ;
V_296 [ 3 ] = 0x3c ;
V_296 [ 4 ] = V_312 >> 8 ;
V_296 [ 5 ] = V_312 ;
V_296 [ 7 ] = V_311 ;
return 0 ;
}
static unsigned int F_128 ( struct V_295 * args , T_3 * V_296 )
{
V_296 [ 1 ] = 0xb2 ;
V_296 [ 3 ] = 0x4 ;
V_296 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_129 ( struct V_295 * args , T_3 * V_296 )
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
static unsigned int F_131 ( T_6 * V_93 , T_3 * V_4 , bool V_316 )
{
F_130 ( V_4 , V_317 , sizeof( V_317 ) , V_316 ) ;
if ( V_316 || F_132 ( V_93 ) )
V_4 [ 2 ] |= ( 1 << 2 ) ;
if ( ! V_316 && ! F_133 ( V_93 ) )
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
static int F_136 ( T_6 * V_93 )
{
unsigned char V_320 [ V_97 + 1 ] , V_321 [ V_99 + 1 ] ;
if ( ! V_322 )
return 0 ;
if ( ! F_137 ( V_93 ) )
return 0 ;
F_138 ( V_93 , V_320 , V_96 , sizeof( V_320 ) ) ;
F_138 ( V_93 , V_321 , V_98 , sizeof( V_321 ) ) ;
if ( strcmp ( V_320 , L_42 ) )
return 1 ;
if ( strcmp ( V_321 , L_43 ) )
return 1 ;
return 0 ;
}
static unsigned int F_139 ( struct V_295 * args , T_3 * V_296 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_141 = args -> V_57 -> V_224 , * V_323 = V_296 ;
const T_3 V_324 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_325 , V_326 ;
unsigned int V_327 , V_328 , V_329 ;
T_3 V_330 ;
F_93 ( L_31 ) ;
V_329 = ( V_141 [ 0 ] == V_331 ) ;
V_327 = ! ( V_141 [ 1 ] & 0x8 ) ;
V_328 = V_141 [ 2 ] >> 6 ;
switch ( V_328 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_332;
default:
goto V_226;
}
if ( V_329 )
V_323 += 4 + ( V_327 ? 8 : 0 ) ;
else
V_323 += 8 + ( V_327 ? 8 : 0 ) ;
V_325 = V_141 [ 2 ] & 0x3f ;
V_326 = V_141 [ 3 ] ;
if ( V_326 && ( V_326 != V_333 ) )
goto V_226;
switch( V_325 ) {
case V_334 :
V_323 += F_135 ( V_323 , V_328 == 1 ) ;
break;
case V_335 :
V_323 += F_131 ( args -> V_93 , V_323 , V_328 == 1 ) ;
break;
case V_336 :
V_323 += F_134 ( V_323 , V_328 == 1 ) ;
break;
case V_337 :
V_323 += F_135 ( V_323 , V_328 == 1 ) ;
V_323 += F_131 ( args -> V_93 , V_323 , V_328 == 1 ) ;
V_323 += F_134 ( V_323 , V_328 == 1 ) ;
break;
default:
goto V_226;
}
V_330 = 0 ;
if ( F_136 ( args -> V_93 ) && ( V_13 -> V_16 & V_255 ) &&
( ! ( V_13 -> V_16 & V_338 ) || V_13 -> V_339 ) )
V_330 = 1 << 4 ;
if ( V_329 ) {
V_296 [ 0 ] = V_323 - V_296 - 1 ;
V_296 [ 2 ] |= V_330 ;
if ( V_327 ) {
V_296 [ 3 ] = sizeof( V_324 ) ;
memcpy ( V_296 + 4 , V_324 , sizeof( V_324 ) ) ;
}
} else {
unsigned int V_340 = V_323 - V_296 - 2 ;
V_296 [ 0 ] = V_340 >> 8 ;
V_296 [ 1 ] = V_340 ;
V_296 [ 3 ] |= V_330 ;
if ( V_327 ) {
V_296 [ 7 ] = sizeof( V_324 ) ;
memcpy ( V_296 + 8 , V_324 , sizeof( V_324 ) ) ;
}
}
return 0 ;
V_226:
F_22 ( args -> V_57 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_332:
F_22 ( args -> V_57 , V_79 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_140 ( struct V_295 * args , T_3 * V_296 )
{
struct V_12 * V_13 = args -> V_13 ;
T_7 V_341 = V_13 -> V_85 - 1 ;
T_8 V_206 ;
T_3 V_342 ;
T_6 V_343 ;
V_206 = F_74 ( V_13 -> V_93 ) ;
V_342 = F_120 ( V_13 -> V_93 ) ;
V_343 = F_141 ( V_13 -> V_93 , V_342 ) ;
F_93 ( L_31 ) ;
if ( args -> V_57 -> V_224 [ 0 ] == V_344 ) {
if ( V_341 >= 0xffffffffULL )
V_341 = 0xffffffff ;
V_296 [ 0 ] = V_341 >> ( 8 * 3 ) ;
V_296 [ 1 ] = V_341 >> ( 8 * 2 ) ;
V_296 [ 2 ] = V_341 >> ( 8 * 1 ) ;
V_296 [ 3 ] = V_341 ;
V_296 [ 4 ] = V_206 >> ( 8 * 3 ) ;
V_296 [ 5 ] = V_206 >> ( 8 * 2 ) ;
V_296 [ 6 ] = V_206 >> ( 8 * 1 ) ;
V_296 [ 7 ] = V_206 ;
} else {
V_296 [ 0 ] = V_341 >> ( 8 * 7 ) ;
V_296 [ 1 ] = V_341 >> ( 8 * 6 ) ;
V_296 [ 2 ] = V_341 >> ( 8 * 5 ) ;
V_296 [ 3 ] = V_341 >> ( 8 * 4 ) ;
V_296 [ 4 ] = V_341 >> ( 8 * 3 ) ;
V_296 [ 5 ] = V_341 >> ( 8 * 2 ) ;
V_296 [ 6 ] = V_341 >> ( 8 * 1 ) ;
V_296 [ 7 ] = V_341 ;
V_296 [ 8 ] = V_206 >> ( 8 * 3 ) ;
V_296 [ 9 ] = V_206 >> ( 8 * 2 ) ;
V_296 [ 10 ] = V_206 >> ( 8 * 1 ) ;
V_296 [ 11 ] = V_206 ;
V_296 [ 12 ] = 0 ;
V_296 [ 13 ] = V_342 ;
V_296 [ 14 ] = ( V_343 >> 8 ) & 0x3f ;
V_296 [ 15 ] = V_343 ;
if ( F_122 ( args -> V_93 ) ) {
V_296 [ 14 ] |= 0x80 ;
if ( F_142 ( args -> V_93 ) &&
V_13 -> V_22 & V_345 ) {
F_143 ( V_13 , L_44 ) ;
V_296 [ 14 ] |= 0x40 ;
}
}
}
return 0 ;
}
static unsigned int F_144 ( struct V_295 * args , T_3 * V_296 )
{
F_93 ( L_31 ) ;
V_296 [ 3 ] = 8 ;
return 0 ;
}
static void F_145 ( struct V_139 * V_140 )
{
if ( V_140 -> V_176 && ( ( V_140 -> V_176 & V_346 ) == 0 ) ) {
F_60 ( V_140 ) ;
}
V_140 -> V_142 ( V_140 -> V_141 ) ;
F_103 ( V_140 ) ;
}
static inline int F_146 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_127 ) ;
}
static void F_147 ( struct V_139 * V_140 )
{
struct V_8 * V_9 = V_140 -> V_9 ;
struct V_56 * V_57 = V_140 -> V_141 ;
F_99 ( L_45 ) ;
memset ( V_57 -> V_64 , 0 , V_111 ) ;
#ifdef F_148
if ( V_9 -> V_65 -> V_347 )
V_9 -> V_65 -> V_347 ( V_9 , & V_140 -> V_153 ) ;
#endif
V_57 -> V_64 [ 0 ] = 0x70 ;
V_57 -> V_64 [ 2 ] = V_140 -> V_153 . V_157 >> 4 ;
F_149 ( V_140 ) ;
F_150 ( & V_140 -> V_348 , V_57 -> V_64 , V_111 ) ;
F_105 ( V_140 , & V_140 -> V_348 , 1 ) ;
V_140 -> V_281 = V_116 ;
memset ( & V_140 -> V_223 , 0 , V_140 -> V_13 -> V_349 ) ;
V_140 -> V_223 [ 0 ] = V_350 ;
V_140 -> V_223 [ 4 ] = V_111 ;
V_140 -> V_153 . V_16 |= V_228 | V_227 ;
V_140 -> V_153 . V_155 = V_351 ;
if ( F_146 ( V_9 ) ) {
V_140 -> V_153 . V_229 = V_352 ;
V_140 -> V_153 . V_157 |= V_353 ;
} else {
V_140 -> V_153 . V_229 = V_354 ;
V_140 -> V_153 . V_183 = V_111 ;
V_140 -> V_153 . V_184 = 0 ;
}
V_140 -> V_151 = V_111 ;
V_140 -> V_282 = F_145 ;
F_106 ( V_140 ) ;
F_99 ( L_33 ) ;
}
static void F_151 ( struct V_139 * V_140 )
{
struct V_56 * V_57 = V_140 -> V_141 ;
unsigned int V_176 = V_140 -> V_176 ;
F_93 ( L_46 , V_176 ) ;
if ( F_19 ( V_140 -> V_9 -> V_65 -> V_175 &&
( V_176 || V_140 -> V_16 & V_355 ) ) ) {
if ( ! ( V_140 -> V_16 & V_355 ) ) {
F_60 ( V_140 ) ;
}
if ( V_140 -> V_223 [ 0 ] == V_356 && V_140 -> V_13 -> V_29 )
V_140 -> V_13 -> V_29 -> V_357 = 0 ;
V_140 -> V_141 -> V_61 = V_63 ;
V_140 -> V_142 ( V_57 ) ;
F_103 ( V_140 ) ;
return;
}
if ( F_19 ( V_176 & V_346 ) ) {
V_57 -> V_61 = V_63 ;
F_147 ( V_140 ) ;
return;
} else if ( F_19 ( V_176 ) ) {
F_60 ( V_140 ) ;
} else {
T_3 * V_141 = V_57 -> V_224 ;
if ( ( V_141 [ 0 ] == V_358 ) && ( ( V_141 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_16 ;
T_3 * V_4 ;
V_4 = F_107 ( V_57 , true , & V_16 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_109 ( V_57 , true , & V_16 ) ;
}
V_57 -> V_61 = V_241 ;
}
V_140 -> V_142 ( V_57 ) ;
F_103 ( V_140 ) ;
}
static unsigned int F_152 ( struct V_139 * V_140 )
{
struct V_56 * V_147 = V_140 -> V_141 ;
struct V_12 * V_13 = V_140 -> V_13 ;
int V_359 = ( V_147 -> V_278 == V_117 ) ;
int V_360 = ! V_359 && ( V_13 -> V_16 & V_338 ) ;
unsigned int V_151 ;
memset ( V_140 -> V_223 , 0 , V_13 -> V_349 ) ;
memcpy ( V_140 -> V_223 , V_147 -> V_224 , V_147 -> V_225 ) ;
V_140 -> V_282 = F_151 ;
V_140 -> V_153 . V_16 |= V_228 | V_227 ;
if ( V_147 -> V_278 == V_279 ) {
V_140 -> V_153 . V_16 |= V_267 ;
F_99 ( L_47 ) ;
}
V_140 -> V_153 . V_155 = V_351 ;
F_55 ( V_140 ) ;
if ( ! V_359 && ! V_360 && F_153 ( V_140 ) )
V_360 = 1 ;
V_151 = F_78 ( F_154 ( V_140 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_151 & 0x1 )
V_151 ++ ;
V_140 -> V_153 . V_183 = ( V_151 & 0xFF ) ;
V_140 -> V_153 . V_184 = ( V_151 >> 8 ) ;
if ( V_359 )
V_140 -> V_153 . V_229 = V_361 ;
else if ( V_360 )
V_140 -> V_153 . V_229 = V_354 ;
else {
V_140 -> V_153 . V_229 = V_352 ;
V_140 -> V_153 . V_157 |= V_353 ;
if ( ( V_13 -> V_16 & V_362 ) &&
( V_147 -> V_278 != V_279 ) )
V_140 -> V_153 . V_157 |= V_363 ;
}
return 0 ;
}
static struct V_12 * F_155 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_156 ( V_9 ) ) {
if ( F_65 ( V_43 < F_157 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_65 ( V_43 < V_9 -> V_364 ) )
return & V_9 -> V_365 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_83 ( struct V_8 * V_9 ,
const struct V_28 * V_102 )
{
int V_43 ;
if ( ! F_156 ( V_9 ) ) {
if ( F_19 ( V_102 -> V_366 || V_102 -> V_367 ) )
return NULL ;
V_43 = V_102 -> V_93 ;
} else {
if ( F_19 ( V_102 -> V_93 || V_102 -> V_367 ) )
return NULL ;
V_43 = V_102 -> V_366 ;
}
return F_155 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_13 ( struct V_8 * V_9 , const struct V_28 * V_102 )
{
struct V_12 * V_13 = F_83 ( V_9 , V_102 ) ;
if ( F_19 ( ! V_13 || ! F_86 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_158 ( T_3 V_368 )
{
switch( ( V_368 & 0x1e ) >> 1 ) {
case 3 :
return V_230 ;
case 6 :
case 10 :
case 11 :
return V_369 ;
case 4 :
case 5 :
return V_370 ;
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
return V_371 ;
}
static unsigned int F_159 ( struct V_139 * V_140 )
{
struct V_152 * V_153 = & ( V_140 -> V_153 ) ;
struct V_56 * V_147 = V_140 -> V_141 ;
struct V_12 * V_13 = V_140 -> V_13 ;
const T_3 * V_223 = V_147 -> V_224 ;
if ( ( V_153 -> V_229 = F_158 ( V_223 [ 1 ] ) ) == V_371 )
goto V_226;
if ( V_223 [ 0 ] == V_118 ) {
if ( V_223 [ 1 ] & 0x01 ) {
V_153 -> V_372 = V_223 [ 3 ] ;
V_153 -> V_186 = V_223 [ 5 ] ;
V_153 -> V_187 = V_223 [ 7 ] ;
V_153 -> V_188 = V_223 [ 9 ] ;
V_153 -> V_189 = V_223 [ 11 ] ;
V_153 -> V_16 |= V_185 ;
} else
V_153 -> V_16 &= ~ V_185 ;
V_153 -> V_157 = V_223 [ 4 ] ;
V_153 -> V_181 = V_223 [ 6 ] ;
V_153 -> V_182 = V_223 [ 8 ] ;
V_153 -> V_183 = V_223 [ 10 ] ;
V_153 -> V_184 = V_223 [ 12 ] ;
V_153 -> V_1 = V_223 [ 13 ] ;
V_153 -> V_155 = V_223 [ 14 ] ;
} else {
V_153 -> V_16 &= ~ V_185 ;
V_153 -> V_157 = V_223 [ 3 ] ;
V_153 -> V_181 = V_223 [ 4 ] ;
V_153 -> V_182 = V_223 [ 5 ] ;
V_153 -> V_183 = V_223 [ 6 ] ;
V_153 -> V_184 = V_223 [ 7 ] ;
V_153 -> V_1 = V_223 [ 8 ] ;
V_153 -> V_155 = V_223 [ 9 ] ;
}
V_153 -> V_1 = V_13 -> V_43 ?
V_153 -> V_1 | V_373 : V_153 -> V_1 & ~ V_373 ;
switch ( V_153 -> V_155 ) {
case V_374 :
case V_375 :
case V_376 :
case V_377 :
if ( V_153 -> V_229 != V_370 || V_153 -> V_181 != 1 )
goto V_226;
V_140 -> V_378 = F_56 ( V_147 ) ;
break;
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
case V_391 :
case V_234 :
case V_256 :
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
case V_404 :
V_140 -> V_378 = V_147 -> V_1 -> V_206 ;
break;
default:
V_140 -> V_378 = V_114 ;
}
V_153 -> V_16 |= V_228 | V_227 ;
if ( V_147 -> V_278 == V_279 )
V_153 -> V_16 |= V_267 ;
V_140 -> V_16 |= V_405 | V_406 ;
F_55 ( V_140 ) ;
if ( V_153 -> V_229 == V_369 && V_13 -> V_407 == 0 )
goto V_226;
if ( ( V_223 [ 1 ] & 0xe0 ) && ! F_160 ( V_153 ) )
goto V_226;
if ( F_160 ( V_153 ) ) {
unsigned int V_339 = 1 << ( V_223 [ 1 ] >> 5 ) ;
if ( V_339 != V_13 -> V_339 )
F_75 ( V_13 , L_48 ,
V_339 ) ;
}
if ( V_153 -> V_155 == V_408 &&
V_153 -> V_157 == V_409 )
goto V_226;
if ( V_153 -> V_155 >= 0x5C && V_153 -> V_155 <= 0x5F && ! V_410 )
goto V_226;
return 0 ;
V_226:
F_22 ( V_147 , V_79 , 0x24 , 0x00 ) ;
return 1 ;
}
static unsigned int F_161 ( struct V_139 * V_140 )
{
struct V_152 * V_153 = & V_140 -> V_153 ;
struct V_56 * V_147 = V_140 -> V_141 ;
struct V_12 * V_13 = V_140 -> V_13 ;
const T_3 * V_223 = V_147 -> V_224 ;
T_7 V_190 ;
T_8 V_250 ;
T_8 V_411 ;
void * V_4 ;
if ( F_19 ( ! V_13 -> V_407 ) )
goto V_226;
if ( F_19 ( V_147 -> V_225 < 16 ) )
goto V_226;
F_95 ( V_223 , & V_190 , & V_250 ) ;
if ( F_19 ( ! ( V_223 [ 1 ] & 0x8 ) ) )
goto V_226;
if ( ! F_54 ( V_147 ) )
goto V_226;
V_4 = F_162 ( F_163 ( F_53 ( V_147 ) ) ) ;
V_411 = F_164 ( V_4 , 512 , V_190 , V_250 ) ;
if ( F_87 ( V_13 ) && F_165 ( V_13 ) ) {
V_153 -> V_229 = V_412 ;
V_153 -> V_155 = V_413 ;
V_153 -> V_186 = V_414 & 0x1f ;
V_153 -> V_181 = V_140 -> V_272 << 3 ;
V_153 -> V_372 = ( V_411 / 512 ) >> 8 ;
V_153 -> V_157 = V_411 / 512 ;
V_153 -> V_415 = 1 ;
} else {
V_153 -> V_229 = V_369 ;
V_153 -> V_372 = 0 ;
V_153 -> V_157 = V_416 ;
V_153 -> V_186 = ( V_411 / 512 ) >> 8 ;
V_153 -> V_181 = V_411 / 512 ;
V_153 -> V_155 = V_417 ;
}
V_153 -> V_16 |= V_228 | V_227 | V_185 |
V_267 ;
F_55 ( V_140 ) ;
return 0 ;
V_226:
F_22 ( V_147 , V_79 , 0x24 , 0x00 ) ;
return 1 ;
}
static int F_166 ( struct V_139 * V_140 ,
const T_3 * V_4 , int V_45 )
{
struct V_152 * V_153 = & V_140 -> V_153 ;
struct V_12 * V_13 = V_140 -> V_13 ;
char V_418 [ V_419 ] ;
T_3 V_420 ;
if ( V_45 != V_419 - 2 )
return - V_20 ;
V_420 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_131 ( V_13 -> V_93 , V_418 , false ) ;
V_418 [ 2 ] &= ~ ( 1 << 2 ) ;
V_418 [ 2 ] |= V_420 ;
if ( memcmp ( V_418 + 2 , V_4 , V_419 - 2 ) != 0 )
return - V_20 ;
V_153 -> V_16 |= V_227 | V_228 ;
V_153 -> V_229 = V_230 ;
V_153 -> V_181 = 0 ;
V_153 -> V_155 = V_408 ;
V_153 -> V_157 = V_420 ? V_421 : V_422 ;
return 0 ;
}
static unsigned int F_167 ( struct V_139 * V_140 )
{
struct V_56 * V_147 = V_140 -> V_141 ;
const T_3 * V_223 = V_147 -> V_224 ;
const T_3 * V_323 ;
T_3 V_325 , V_326 ;
unsigned V_329 , V_423 , V_424 , V_425 ;
int V_45 ;
F_93 ( L_31 ) ;
V_329 = ( V_223 [ 0 ] == V_426 ) ;
if ( V_329 ) {
if ( V_147 -> V_225 < 5 )
goto V_226;
V_45 = V_223 [ 4 ] ;
V_424 = 4 ;
} else {
if ( V_147 -> V_225 < 9 )
goto V_226;
V_45 = ( V_223 [ 7 ] << 8 ) + V_223 [ 8 ] ;
V_424 = 8 ;
}
if ( ( V_223 [ 1 ] & 0x11 ) != 0x10 )
goto V_226;
if ( ! F_54 ( V_147 ) || F_53 ( V_147 ) -> V_427 < V_45 )
goto V_428;
V_323 = F_162 ( F_163 ( F_53 ( V_147 ) ) ) ;
if ( V_45 < V_424 )
goto V_428;
if ( V_329 )
V_425 = V_323 [ 3 ] ;
else
V_425 = ( V_323 [ 6 ] << 8 ) + V_323 [ 7 ] ;
V_45 -= V_424 ;
V_323 += V_424 ;
if ( V_45 < V_425 )
goto V_428;
if ( V_425 != 0 && V_425 != 8 )
goto V_429;
V_45 -= V_425 ;
V_323 += V_425 ;
if ( V_45 == 0 )
goto V_238;
V_325 = V_323 [ 0 ] & 0x3f ;
if ( V_323 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_428;
V_326 = V_323 [ 1 ] ;
V_423 = ( V_323 [ 2 ] << 8 ) | V_323 [ 3 ] ;
V_323 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_428;
V_326 = 0 ;
V_423 = V_323 [ 1 ] ;
V_323 += 2 ;
V_45 -= 2 ;
}
if ( V_326 && ( V_326 != V_333 ) )
goto V_429;
if ( V_423 > V_45 )
goto V_428;
switch ( V_325 ) {
case V_335 :
if ( F_166 ( V_140 , V_323 , V_423 ) < 0 )
goto V_429;
break;
default:
goto V_429;
}
if ( V_45 > V_423 )
goto V_429;
return 0 ;
V_226:
F_22 ( V_147 , V_79 , 0x24 , 0x0 ) ;
return 1 ;
V_429:
F_22 ( V_147 , V_79 , 0x26 , 0x0 ) ;
return 1 ;
V_428:
F_22 ( V_147 , V_79 , 0x1a , 0x0 ) ;
return 1 ;
V_238:
V_147 -> V_61 = V_241 ;
return 1 ;
}
static inline T_9 F_168 ( struct V_12 * V_13 , T_3 V_57 )
{
switch ( V_57 ) {
case V_270 :
case V_268 :
case V_271 :
case V_265 :
case V_264 :
case V_266 :
return F_100 ;
case V_430 :
return F_161 ;
case V_431 :
if ( F_169 ( V_13 ) )
return F_91 ;
break;
case V_251 :
case V_252 :
return F_96 ;
case V_275 :
case V_118 :
return F_159 ;
case V_426 :
case V_432 :
return F_167 ;
break;
case V_433 :
return F_89 ;
}
return NULL ;
}
static inline void F_170 ( struct V_8 * V_9 ,
struct V_56 * V_57 )
{
#ifdef F_171
struct V_28 * V_102 = V_57 -> V_1 ;
T_3 * V_141 = V_57 -> V_224 ;
F_99 ( L_49 ,
V_9 -> V_180 ,
V_102 -> V_366 , V_102 -> V_93 , V_102 -> V_367 ,
V_141 [ 0 ] , V_141 [ 1 ] , V_141 [ 2 ] , V_141 [ 3 ] ,
V_141 [ 4 ] , V_141 [ 5 ] , V_141 [ 6 ] , V_141 [ 7 ] ,
V_141 [ 8 ] ) ;
#endif
}
static inline int F_172 ( struct V_56 * V_147 ,
struct V_12 * V_13 )
{
T_3 V_434 = V_147 -> V_224 [ 0 ] ;
T_9 V_276 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 || V_13 -> V_49 == V_51 ) {
if ( F_19 ( ! V_147 -> V_225 || V_147 -> V_225 > V_13 -> V_349 ) )
goto V_435;
V_276 = F_168 ( V_13 , V_434 ) ;
} else {
if ( F_19 ( ! V_147 -> V_225 ) )
goto V_435;
V_276 = NULL ;
if ( F_65 ( ( V_434 != V_118 ) || ! V_436 ) ) {
int V_45 = F_173 ( V_434 ) ;
if ( F_19 ( V_45 > V_147 -> V_225 || V_45 > V_13 -> V_349 ) )
goto V_435;
V_276 = F_152 ;
} else {
if ( F_19 ( V_147 -> V_225 > 16 ) )
goto V_435;
V_276 = F_168 ( V_13 , V_434 ) ;
}
}
if ( V_276 )
V_33 = F_104 ( V_13 , V_147 , V_276 ) ;
else
F_174 ( V_13 , V_147 ) ;
return V_33 ;
V_435:
F_99 ( L_50 ,
V_147 -> V_225 , V_434 , V_13 -> V_349 ) ;
V_147 -> V_61 = V_286 << 16 ;
V_147 -> V_80 ( V_147 ) ;
return 0 ;
}
int F_175 ( struct V_6 * V_7 , struct V_56 * V_57 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_102 = V_57 -> V_1 ;
int V_33 = 0 ;
unsigned long V_437 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_437 ) ;
F_170 ( V_9 , V_57 ) ;
V_13 = F_13 ( V_9 , V_102 ) ;
if ( F_65 ( V_13 ) )
V_33 = F_172 ( V_57 , V_13 ) ;
else {
V_57 -> V_61 = ( V_438 << 16 ) ;
V_57 -> V_80 ( V_57 ) ;
}
F_9 ( V_9 -> V_21 , V_437 ) ;
return V_33 ;
}
void F_174 ( struct V_12 * V_13 , struct V_56 * V_57 )
{
struct V_295 args ;
const T_3 * V_141 = V_57 -> V_224 ;
T_3 V_439 ;
args . V_13 = V_13 ;
args . V_93 = V_13 -> V_93 ;
args . V_57 = V_57 ;
args . V_440 = V_57 -> V_80 ;
switch( V_141 [ 0 ] ) {
case V_441 :
F_30 ( V_57 ) ;
break;
case V_358 :
if ( V_141 [ 1 ] & 2 )
F_30 ( V_57 ) ;
else if ( ( V_141 [ 1 ] & 1 ) == 0 )
F_176 ( & args , F_111 ) ;
else switch ( V_141 [ 2 ] ) {
case 0x00 :
F_176 ( & args , F_113 ) ;
break;
case 0x80 :
F_176 ( & args , F_114 ) ;
break;
case 0x83 :
F_176 ( & args , F_115 ) ;
break;
case 0x89 :
F_176 ( & args , F_117 ) ;
break;
case 0xb0 :
F_176 ( & args , F_119 ) ;
break;
case 0xb1 :
F_176 ( & args , F_125 ) ;
break;
case 0xb2 :
F_176 ( & args , F_128 ) ;
break;
default:
F_30 ( V_57 ) ;
break;
}
break;
case V_331 :
case V_442 :
F_176 ( & args , F_139 ) ;
break;
case V_344 :
F_176 ( & args , F_140 ) ;
break;
case V_443 :
if ( ( V_141 [ 1 ] & 0x1f ) == V_444 )
F_176 ( & args , F_140 ) ;
else
F_30 ( V_57 ) ;
break;
case V_445 :
F_176 ( & args , F_144 ) ;
break;
case V_350 :
F_22 ( V_57 , 0 , 0 , 0 ) ;
V_57 -> V_61 = ( V_62 << 24 ) ;
V_57 -> V_80 ( V_57 ) ;
break;
case V_431 :
case V_446 :
case V_447 :
case V_448 :
case V_449 :
F_176 ( & args , F_129 ) ;
break;
case V_450 :
V_439 = V_141 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_439 == 0x4 ) && ( ! V_141 [ 3 ] ) && ( ! V_141 [ 4 ] ) )
F_176 ( & args , F_129 ) ;
else
F_30 ( V_57 ) ;
break;
default:
F_22 ( V_57 , V_79 , 0x20 , 0x0 ) ;
V_57 -> V_80 ( V_57 ) ;
break;
}
}
int F_177 ( struct V_451 * V_34 , struct V_452 * V_453 )
{
int V_163 , V_33 ;
for ( V_163 = 0 ; V_163 < V_34 -> V_454 ; V_163 ++ ) {
struct V_8 * V_9 = V_34 -> V_455 [ V_163 ] ;
struct V_6 * V_7 ;
V_33 = - V_113 ;
V_7 = F_178 ( V_453 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_456;
V_7 -> V_457 = 1 ;
* (struct V_8 * * ) & V_7 -> V_458 [ 0 ] = V_9 ;
V_9 -> V_459 = V_7 ;
V_7 -> V_460 = V_461 ;
V_7 -> V_462 = V_9 -> V_180 ;
V_7 -> V_463 = 16 ;
V_7 -> V_464 = 1 ;
V_7 -> V_465 = 1 ;
V_7 -> V_466 = 16 ;
V_7 -> V_194 = 1 ;
V_7 -> V_467 = 1 ;
V_33 = F_179 ( V_9 -> V_459 ,
& V_9 -> V_468 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_469;
}
return 0 ;
V_469:
F_180 ( V_34 -> V_455 [ V_163 ] -> V_459 ) ;
V_456:
while ( -- V_163 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_455 [ V_163 ] -> V_459 ;
F_181 ( V_7 ) ;
F_180 ( V_7 ) ;
}
return V_33 ;
}
void F_182 ( struct V_8 * V_9 , int V_470 )
{
int V_471 = 5 ;
struct V_12 * V_472 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_473:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_366 = 0 , V_93 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_183 ( V_11 ) )
V_93 = V_13 -> V_43 ;
else
V_366 = V_11 -> V_474 ;
V_29 = F_184 ( V_9 -> V_459 , V_366 , V_93 , 0 ,
NULL ) ;
if ( ! F_185 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_186 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_475;
}
}
V_475:
if ( ! V_11 )
return;
if ( V_470 ) {
if ( V_13 != V_472 ) {
F_187 ( 100 ) ;
V_472 = V_13 ;
goto V_473;
}
if ( -- V_471 ) {
F_187 ( 100 ) ;
goto V_473;
}
F_188 ( V_9 ,
L_51 ) ;
}
F_189 ( V_476 , & V_9 -> V_477 ,
F_190 ( V_120 ) ) ;
}
int F_191 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_192 ( V_13 -> V_29 , V_478 ) ;
return 1 ;
}
return 0 ;
}
static void F_193 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_194 ( & V_9 -> V_459 -> V_479 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_195 ( V_29 ) == 0 ) {
F_192 ( V_29 , V_478 ) ;
} else {
F_196 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_197 ( & V_9 -> V_459 -> V_479 ) ;
if ( V_29 ) {
F_143 ( V_13 , L_52 ,
F_198 ( & V_29 -> V_480 ) ) ;
F_199 ( V_29 ) ;
F_186 ( V_29 ) ;
}
}
static void F_200 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_481 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_481 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_201 ( V_13 ) )
F_202 ( V_13 ) ;
F_193 ( V_13 ) ;
}
}
void F_203 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_204 ( V_13 -> V_29 , V_212 ,
V_482 ) ;
}
void F_205 ( struct V_483 * V_484 )
{
struct V_8 * V_9 =
F_206 ( V_484 , struct V_8 , V_477 . V_484 ) ;
int V_163 ;
if ( V_9 -> V_39 & V_485 ) {
F_99 ( L_53 ) ;
return;
}
#ifdef F_207
while ( V_486 )
F_187 ( 10 ) ;
#endif
F_99 ( L_31 ) ;
F_194 ( & V_9 -> V_487 ) ;
F_200 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_365 )
for ( V_163 = 0 ; V_163 < V_488 ; V_163 ++ )
F_200 ( & V_9 -> V_365 [ V_163 ] ) ;
F_182 ( V_9 , 0 ) ;
F_197 ( & V_9 -> V_487 ) ;
F_99 ( L_33 ) ;
}
int F_208 ( struct V_6 * V_7 , unsigned int V_366 ,
unsigned int V_93 , T_7 V_367 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_65 -> V_175 )
return - V_24 ;
if ( V_367 != V_489 && V_367 )
return - V_20 ;
if ( ! F_156 ( V_9 ) ) {
if ( V_366 != V_489 && V_366 )
return - V_20 ;
V_43 = V_93 ;
} else {
if ( V_93 != V_489 && V_93 )
return - V_20 ;
V_43 = V_366 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_489 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_490 * V_491 = & V_11 -> V_52 ;
V_491 -> V_492 |= V_493 ;
V_491 -> V_88 |= V_89 ;
}
} else {
struct V_12 * V_13 = F_155 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_490 * V_491 = & V_13 -> V_11 -> V_52 ;
V_491 -> V_492 |= 1 << V_13 -> V_43 ;
V_491 -> V_88 |= V_89 ;
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
void F_209 ( struct V_483 * V_484 )
{
struct V_8 * V_9 =
F_206 ( V_484 , struct V_8 , V_494 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_194 ( & V_9 -> V_487 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_195 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_210 ( & ( V_29 -> V_480 ) ) ;
F_186 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_197 ( & V_9 -> V_487 ) ;
}
struct V_8 * F_211 ( struct V_451 * V_34 ,
struct V_495 * V_496 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_212 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_497 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_498 = V_496 -> V_498 ;
V_9 -> V_499 = V_496 -> V_499 ;
V_9 -> V_500 = V_496 -> V_500 ;
V_9 -> V_16 |= V_496 -> V_16 ;
V_9 -> V_65 = V_496 -> V_501 ;
V_9 -> V_502 = V_503 ;
return V_9 ;
}
int F_213 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_65 -> V_175 )
V_9 -> V_39 &= ~ V_504 ;
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
int V_33 = V_9 -> V_65 -> V_505 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_180 = F_220 ( & V_506 ) ;
return 0 ;
}
void F_221 ( struct V_8 * V_9 )
{
if ( V_9 -> V_65 -> V_507 )
V_9 -> V_65 -> V_507 ( V_9 ) ;
F_45 ( V_9 ) ;
}
int F_222 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_63 ( V_29 ) ;
F_68 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_223 ( struct V_56 * V_57 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_170 ( V_9 , V_57 ) ;
if ( F_65 ( F_86 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_172 ( V_57 , V_9 -> V_11 . V_1 ) ;
else {
V_57 -> V_61 = ( V_438 << 16 ) ;
V_57 -> V_80 ( V_57 ) ;
}
return V_33 ;
}
