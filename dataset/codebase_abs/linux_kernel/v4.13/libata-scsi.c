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
static T_1 F_23 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_1 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 ;
bool V_56 ;
int V_33 = 0 ;
V_9 = F_3 ( V_29 -> V_34 ) ;
F_13 ( V_9 -> V_21 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( ! V_13 ) {
V_33 = - V_35 ;
goto V_36;
}
V_56 = V_13 -> V_16 & V_57 ;
V_36:
F_17 ( V_9 -> V_21 ) ;
return V_33 ? V_33 : snprintf ( V_4 , 20 , L_2 , V_56 ) ;
}
static T_1 F_24 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 , T_2 V_45 )
{
struct V_28 * V_29 = F_12 ( V_1 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 ;
long int V_46 ;
int V_33 ;
V_33 = F_19 ( V_4 , 10 , & V_46 ) ;
if ( V_33 )
return V_33 ;
if ( ( V_46 < 0 ) || ( V_46 > 1 ) )
return - V_20 ;
V_9 = F_3 ( V_29 -> V_34 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( F_20 ( ! V_13 ) )
return - V_35 ;
F_13 ( V_9 -> V_21 ) ;
if ( V_46 )
V_13 -> V_16 |= V_57 ;
else
V_13 -> V_16 &= ~ V_57 ;
V_13 -> V_11 -> V_52 . V_58 |= V_59 ;
V_13 -> V_11 -> V_52 . V_16 |= V_60 ;
F_8 ( V_9 ) ;
F_17 ( V_9 -> V_21 ) ;
F_25 ( V_9 ) ;
if ( V_46 ) {
F_13 ( V_9 -> V_21 ) ;
if ( ! ( V_13 -> V_16 & V_61 ) ) {
V_13 -> V_16 &= ~ V_57 ;
V_33 = - V_62 ;
}
F_17 ( V_9 -> V_21 ) ;
}
return V_33 ? V_33 : V_45 ;
}
void F_26 ( struct V_12 * V_13 , struct V_63 * V_64 ,
T_3 V_65 , T_3 V_66 , T_3 V_67 )
{
bool V_68 = ( V_13 -> V_16 & V_69 ) ;
if ( ! V_64 )
return;
V_64 -> V_70 = ( V_71 << 24 ) | V_72 ;
F_27 ( V_68 , V_64 -> V_73 , V_65 , V_66 , V_67 ) ;
}
void F_28 ( struct V_12 * V_13 ,
struct V_63 * V_64 ,
const struct V_74 * V_75 )
{
T_4 V_76 ;
if ( ! V_64 )
return;
V_76 = F_29 ( V_75 , V_13 ) ;
if ( V_76 == V_77 )
return;
F_30 ( V_64 -> V_73 ,
V_78 , V_76 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
struct V_63 * V_64 , T_5 V_79 , T_3 V_80 )
{
F_26 ( V_13 , V_64 , V_81 , 0x24 , 0x0 ) ;
F_32 ( V_64 -> V_73 , V_78 ,
V_79 , V_80 , 1 ) ;
}
static void F_33 ( struct V_12 * V_13 ,
struct V_63 * V_64 , T_5 V_79 )
{
F_26 ( V_13 , V_64 , V_81 , 0x26 , 0x0 ) ;
F_32 ( V_64 -> V_73 , V_78 ,
V_79 , 0xff , 0 ) ;
}
static T_1
F_34 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_82 -> V_83 && ( V_9 -> V_16 & V_84 ) )
return V_9 -> V_82 -> V_83 ( V_9 , V_4 , V_5 ) ;
return - V_20 ;
}
static T_1
F_35 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 -> V_82 -> V_85 && ( V_9 -> V_16 & V_84 ) )
return V_9 -> V_82 -> V_85 ( V_9 , V_4 ) ;
return - V_20 ;
}
static T_1
F_36 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return snprintf ( V_4 , 23 , L_3 , V_9 -> V_86 ) ;
}
static T_1
F_37 ( struct V_1 * V_13 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_87 = F_14 ( V_9 , V_29 ) ;
if ( V_87 && V_9 -> V_82 -> V_88 &&
( V_9 -> V_16 & V_89 ) )
return V_9 -> V_82 -> V_88 ( V_87 , V_4 ) ;
return - V_20 ;
}
static T_1
F_38 ( struct V_1 * V_13 , struct V_2 * V_3 ,
const char * V_4 , T_2 V_5 )
{
struct V_28 * V_29 = F_12 ( V_13 ) ;
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_87 = F_14 ( V_9 , V_29 ) ;
enum V_90 V_91 ;
int V_33 ;
if ( V_87 && V_9 -> V_82 -> V_92 &&
( V_9 -> V_16 & V_89 ) ) {
V_91 = F_39 ( V_4 , NULL , 0 ) ;
switch ( V_91 ) {
case V_93 : case V_94 : case V_95 :
V_33 = V_9 -> V_82 -> V_92 ( V_87 , V_91 ) ;
if ( ! V_33 )
return V_5 ;
else
return V_33 ;
}
}
return - V_20 ;
}
int F_40 ( struct V_28 * V_29 , struct V_96 * V_97 ,
T_6 V_98 , int V_99 [] )
{
V_99 [ 0 ] = 255 ;
V_99 [ 1 ] = 63 ;
F_41 ( V_98 , 255 * 63 ) ;
V_99 [ 2 ] = V_98 ;
return 0 ;
}
void F_42 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_100 < V_13 -> V_101 ) {
V_13 -> V_16 |= V_102 ;
V_13 -> V_11 -> V_52 . V_58 |= V_103 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_25 ( V_9 ) ;
}
static int F_43 ( struct V_8 * V_9 , struct V_28 * V_29 ,
void T_7 * V_104 )
{
struct V_12 * V_13 = F_14 ( V_9 , V_29 ) ;
T_5 T_7 * V_105 = V_104 ;
char V_4 [ 40 ] ;
if ( ! V_13 )
return - V_106 ;
if ( F_44 ( V_105 , V_13 -> V_107 , V_108 * sizeof( T_5 ) ) )
return - V_109 ;
F_45 ( V_13 -> V_107 , V_4 , V_110 , V_111 ) ;
if ( F_44 ( V_105 + V_110 , V_4 , V_111 ) )
return - V_109 ;
F_45 ( V_13 -> V_107 , V_4 , V_112 , V_113 ) ;
if ( F_44 ( V_105 + V_112 , V_4 , V_113 ) )
return - V_109 ;
F_45 ( V_13 -> V_107 , V_4 , V_114 , V_115 ) ;
if ( F_44 ( V_105 + V_114 , V_4 , V_115 ) )
return - V_109 ;
return 0 ;
}
int F_46 ( struct V_28 * V_116 , void T_7 * V_104 )
{
int V_33 = 0 ;
T_3 V_117 [ V_118 ] ;
T_3 args [ 4 ] , * V_119 = NULL , * V_120 = NULL ;
int V_121 = 0 ;
enum V_122 V_123 ;
struct V_124 V_125 ;
int V_126 ;
if ( V_104 == NULL )
return - V_20 ;
if ( F_47 ( args , V_104 , sizeof( args ) ) )
return - V_109 ;
V_120 = F_48 ( V_78 , V_127 ) ;
if ( ! V_120 )
return - V_128 ;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
if ( args [ 3 ] ) {
V_121 = V_129 * args [ 3 ] ;
V_119 = F_49 ( V_121 , V_130 ) ;
if ( V_119 == NULL ) {
V_33 = - V_128 ;
goto error;
}
V_117 [ 1 ] = ( 4 << 1 ) ;
V_117 [ 2 ] = 0x0e ;
V_123 = V_131 ;
} else {
V_117 [ 1 ] = ( 3 << 1 ) ;
V_117 [ 2 ] = 0x20 ;
V_123 = V_132 ;
}
V_117 [ 0 ] = V_133 ;
V_117 [ 4 ] = args [ 2 ] ;
if ( args [ 0 ] == V_134 ) {
V_117 [ 6 ] = args [ 3 ] ;
V_117 [ 8 ] = args [ 1 ] ;
V_117 [ 10 ] = 0x4f ;
V_117 [ 12 ] = 0xc2 ;
} else {
V_117 [ 6 ] = args [ 1 ] ;
}
V_117 [ 14 ] = args [ 0 ] ;
V_126 = F_50 ( V_116 , V_117 , V_123 , V_119 , V_121 ,
V_120 , & V_125 , ( 10 * V_135 ) , 5 , 0 , 0 , NULL ) ;
if ( F_51 ( V_126 ) == V_71 ) {
T_3 * V_136 = V_120 + 8 ;
V_126 &= ~ ( 0xFF << 24 ) ;
if ( V_126 & V_72 ) {
if ( V_125 . V_137 == V_138 &&
V_125 . V_66 == 0 && V_125 . V_67 == 0x1d )
V_126 &= ~ V_72 ;
}
if ( V_120 [ 0 ] == 0x72 &&
V_136 [ 0 ] == 0x09 ) {
args [ 0 ] = V_136 [ 13 ] ;
args [ 1 ] = V_136 [ 3 ] ;
args [ 2 ] = V_136 [ 5 ] ;
if ( F_44 ( V_104 , args , sizeof( args ) ) )
V_33 = - V_109 ;
}
}
if ( V_126 ) {
V_33 = - V_62 ;
goto error;
}
if ( ( V_119 )
&& F_44 ( V_104 + sizeof( args ) , V_119 , V_121 ) )
V_33 = - V_109 ;
error:
F_52 ( V_120 ) ;
F_52 ( V_119 ) ;
return V_33 ;
}
int F_53 ( struct V_28 * V_116 , void T_7 * V_104 )
{
int V_33 = 0 ;
T_3 V_117 [ V_118 ] ;
T_3 args [ 7 ] , * V_120 = NULL ;
struct V_124 V_125 ;
int V_126 ;
if ( V_104 == NULL )
return - V_20 ;
if ( F_47 ( args , V_104 , sizeof( args ) ) )
return - V_109 ;
V_120 = F_48 ( V_78 , V_127 ) ;
if ( ! V_120 )
return - V_128 ;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
V_117 [ 0 ] = V_133 ;
V_117 [ 1 ] = ( 3 << 1 ) ;
V_117 [ 2 ] = 0x20 ;
V_117 [ 4 ] = args [ 1 ] ;
V_117 [ 6 ] = args [ 2 ] ;
V_117 [ 8 ] = args [ 3 ] ;
V_117 [ 10 ] = args [ 4 ] ;
V_117 [ 12 ] = args [ 5 ] ;
V_117 [ 13 ] = args [ 6 ] & 0x4f ;
V_117 [ 14 ] = args [ 0 ] ;
V_126 = F_50 ( V_116 , V_117 , V_132 , NULL , 0 ,
V_120 , & V_125 , ( 10 * V_135 ) , 5 , 0 , 0 , NULL ) ;
if ( F_51 ( V_126 ) == V_71 ) {
T_3 * V_136 = V_120 + 8 ;
V_126 &= ~ ( 0xFF << 24 ) ;
if ( V_126 & V_72 ) {
if ( V_125 . V_137 == V_138 &&
V_125 . V_66 == 0 && V_125 . V_67 == 0x1d )
V_126 &= ~ V_72 ;
}
if ( V_120 [ 0 ] == 0x72 &&
V_136 [ 0 ] == 0x09 ) {
args [ 0 ] = V_136 [ 13 ] ;
args [ 1 ] = V_136 [ 3 ] ;
args [ 2 ] = V_136 [ 5 ] ;
args [ 3 ] = V_136 [ 7 ] ;
args [ 4 ] = V_136 [ 9 ] ;
args [ 5 ] = V_136 [ 11 ] ;
args [ 6 ] = V_136 [ 12 ] ;
if ( F_44 ( V_104 , args , sizeof( args ) ) )
V_33 = - V_109 ;
}
}
if ( V_126 ) {
V_33 = - V_62 ;
goto error;
}
error:
F_52 ( V_120 ) ;
return V_33 ;
}
static int F_54 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 & V_139 )
return 1 ;
if ( V_9 -> V_39 & V_140 )
return 1 ;
return 0 ;
}
int F_55 ( struct V_8 * V_9 , struct V_28 * V_116 ,
int V_64 , void T_7 * V_104 )
{
unsigned long V_91 ;
int V_33 = - V_20 ;
unsigned long V_16 ;
switch ( V_64 ) {
case V_141 :
F_5 ( V_9 -> V_21 , V_16 ) ;
V_91 = F_54 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
return F_56 ( V_91 , ( unsigned long T_7 * ) V_104 ) ;
case V_142 :
V_91 = ( unsigned long ) V_104 ;
V_33 = 0 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_9 -> V_39 & V_143 ) {
if ( V_91 )
V_9 -> V_39 |= V_140 ;
else
V_9 -> V_39 &= ~ V_140 ;
} else {
if ( V_91 != F_54 ( V_9 ) )
V_33 = - V_20 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
case V_144 :
return F_43 ( V_9 , V_116 , V_104 ) ;
case V_145 :
if ( ! F_57 ( V_146 ) || ! F_57 ( V_147 ) )
return - V_148 ;
return F_46 ( V_116 , V_104 ) ;
case V_149 :
if ( ! F_57 ( V_146 ) || ! F_57 ( V_147 ) )
return - V_148 ;
return F_53 ( V_116 , V_104 ) ;
default:
V_33 = - V_150 ;
break;
}
return V_33 ;
}
int F_58 ( struct V_28 * V_116 , int V_64 , void T_7 * V_104 )
{
return F_55 ( F_3 ( V_116 -> V_34 ) ,
V_116 , V_64 , V_104 ) ;
}
static struct V_151 * F_59 ( struct V_12 * V_13 ,
struct V_63 * V_64 )
{
struct V_151 * V_152 ;
V_152 = F_60 ( V_13 , V_64 -> V_153 -> V_154 ) ;
if ( V_152 ) {
V_152 -> V_155 = V_64 ;
V_152 -> V_156 = V_64 -> V_157 ;
V_152 -> V_158 = F_61 ( V_64 ) ;
V_152 -> V_159 = F_62 ( V_64 ) ;
} else {
V_64 -> V_70 = ( V_160 << 16 ) | ( V_161 << 1 ) ;
V_64 -> V_157 ( V_64 ) ;
}
return V_152 ;
}
static void F_63 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
V_152 -> V_163 = V_162 -> V_153 -> V_164 ;
V_152 -> V_165 = F_64 ( V_162 ) + V_152 -> V_163 ;
}
static void F_65 ( unsigned V_107 , struct V_74 * V_75 )
{
T_3 V_166 = V_75 -> V_167 , V_168 = V_75 -> V_169 ;
F_66 ( L_4 , V_107 , V_166 ) ;
if ( V_166 & V_170 ) {
F_67 ( L_5 ) ;
} else {
if ( V_166 & V_171 ) F_67 ( L_6 ) ;
if ( V_166 & V_172 ) F_67 ( L_7 ) ;
if ( V_166 & V_173 ) F_67 ( L_8 ) ;
if ( V_166 & V_174 ) F_67 ( L_9 ) ;
if ( V_166 & V_175 ) F_67 ( L_10 ) ;
if ( V_166 & V_176 ) F_67 ( L_11 ) ;
if ( V_166 & V_177 ) F_67 ( L_12 ) ;
F_67 ( L_13 ) ;
if ( V_168 ) {
F_66 ( L_14 , V_107 , V_168 ) ;
if ( V_168 & V_178 ) F_67 ( L_15 ) ;
if ( V_168 & V_179 ) {
if ( V_168 & V_178 )
F_67 ( L_16 ) ;
else F_67 ( L_17 ) ;
}
if ( V_168 & V_180 ) F_67 ( L_18 ) ;
if ( V_168 & V_181 ) F_67 ( L_19 ) ;
if ( V_168 & V_182 ) F_67 ( L_20 ) ;
if ( V_168 & V_183 ) F_67 ( L_21 ) ;
F_67 ( L_13 ) ;
}
}
}
static void F_68 ( unsigned V_107 , T_3 V_184 , T_3 V_185 , T_3 * V_65 ,
T_3 * V_66 , T_3 * V_67 , int V_186 )
{
int V_187 ;
static const unsigned char V_188 [] [ 4 ] = {
{ 0xd1 , V_189 , 0x00 , 0x00 } ,
{ 0xd0 , V_189 , 0x00 , 0x00 } ,
{ 0x61 , V_190 , 0x00 , 0x00 } ,
{ 0x84 , V_189 , 0x47 , 0x00 } ,
{ 0x37 , V_191 , 0x04 , 0x00 } ,
{ 0x09 , V_191 , 0x04 , 0x00 } ,
{ 0x01 , V_192 , 0x13 , 0x00 } ,
{ 0x02 , V_190 , 0x00 , 0x00 } ,
{ 0x08 , V_191 , 0x04 , 0x00 } ,
{ 0x10 , V_81 , 0x21 , 0x00 } ,
{ 0x20 , V_193 , 0x28 , 0x00 } ,
{ 0x40 , V_192 , 0x11 , 0x04 } ,
{ 0x80 , V_192 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_194 [] [ 4 ] = {
{ 0x80 , V_189 , 0x47 , 0x00 } ,
{ 0x40 , V_81 , 0x21 , 0x04 } ,
{ 0x20 , V_190 , 0x44 , 0x00 } ,
{ 0x08 , V_189 , 0x47 , 0x00 } ,
{ 0x04 , V_138 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_184 & V_170 ) {
V_185 = 0 ;
}
if ( V_185 ) {
for ( V_187 = 0 ; V_188 [ V_187 ] [ 0 ] != 0xFF ; V_187 ++ ) {
if ( ( V_188 [ V_187 ] [ 0 ] & V_185 ) ==
V_188 [ V_187 ] [ 0 ] ) {
* V_65 = V_188 [ V_187 ] [ 1 ] ;
* V_66 = V_188 [ V_187 ] [ 2 ] ;
* V_67 = V_188 [ V_187 ] [ 3 ] ;
goto V_195;
}
}
}
for ( V_187 = 0 ; V_194 [ V_187 ] [ 0 ] != 0xFF ; V_187 ++ ) {
if ( V_194 [ V_187 ] [ 0 ] & V_184 ) {
* V_65 = V_194 [ V_187 ] [ 1 ] ;
* V_66 = V_194 [ V_187 ] [ 2 ] ;
* V_67 = V_194 [ V_187 ] [ 3 ] ;
goto V_195;
}
}
* V_65 = V_189 ;
* V_66 = 0x00 ;
* V_67 = 0x00 ;
V_195:
if ( V_186 )
F_69 ( L_22 ,
V_107 , V_184 , V_185 , * V_65 , * V_66 , * V_67 ) ;
return;
}
static void F_70 ( struct V_151 * V_152 )
{
struct V_63 * V_64 = V_152 -> V_155 ;
struct V_74 * V_75 = & V_152 -> V_196 ;
unsigned char * V_197 = V_64 -> V_73 ;
unsigned char * V_136 = V_197 + 8 ;
int V_186 = V_152 -> V_9 -> V_82 -> V_198 == NULL ;
T_3 V_137 , V_66 , V_67 ;
memset ( V_197 , 0 , V_78 ) ;
V_64 -> V_70 = ( V_71 << 24 ) | V_72 ;
if ( V_152 -> V_199 ||
V_75 -> V_167 & ( V_170 | V_172 | V_177 | V_174 ) ) {
F_68 ( V_152 -> V_9 -> V_200 , V_75 -> V_167 , V_75 -> V_169 ,
& V_137 , & V_66 , & V_67 , V_186 ) ;
F_26 ( V_152 -> V_13 , V_64 , V_137 , V_66 , V_67 ) ;
} else {
F_27 ( 1 , V_64 -> V_73 ,
V_138 , 0 , 0x1D ) ;
}
if ( ( V_64 -> V_73 [ 0 ] & 0x7f ) >= 0x72 ) {
T_3 V_45 ;
V_45 = V_197 [ 7 ] ;
V_136 = ( char * ) F_71 ( V_197 , V_45 + 8 , 9 ) ;
if ( ! V_136 ) {
if ( V_78 < V_45 + 14 )
return;
V_197 [ 7 ] = V_45 + 14 ;
V_136 = V_197 + 8 + V_45 ;
}
V_136 [ 0 ] = 9 ;
V_136 [ 1 ] = 12 ;
V_136 [ 2 ] = 0x00 ;
V_136 [ 3 ] = V_75 -> V_169 ;
V_136 [ 5 ] = V_75 -> V_201 ;
V_136 [ 7 ] = V_75 -> V_202 ;
V_136 [ 9 ] = V_75 -> V_203 ;
V_136 [ 11 ] = V_75 -> V_204 ;
V_136 [ 12 ] = V_75 -> V_1 ;
V_136 [ 13 ] = V_75 -> V_167 ;
if ( V_75 -> V_16 & V_205 ) {
V_136 [ 2 ] |= 0x01 ;
V_136 [ 4 ] = V_75 -> V_206 ;
V_136 [ 6 ] = V_75 -> V_207 ;
V_136 [ 8 ] = V_75 -> V_208 ;
V_136 [ 10 ] = V_75 -> V_209 ;
}
} else {
V_136 [ 0 ] = V_75 -> V_169 ;
V_136 [ 1 ] = V_75 -> V_167 ;
V_136 [ 2 ] = V_75 -> V_1 ;
V_136 [ 3 ] = V_75 -> V_201 ;
V_136 [ 7 ] = 0 ;
if ( V_75 -> V_16 & V_205 ) {
V_136 [ 8 ] |= 0x80 ;
if ( V_75 -> V_206 )
V_136 [ 8 ] |= 0x40 ;
if ( V_75 -> V_207 || V_75 -> V_208 || V_75 -> V_209 )
V_136 [ 8 ] |= 0x20 ;
}
V_136 [ 9 ] = V_75 -> V_202 ;
V_136 [ 10 ] = V_75 -> V_203 ;
V_136 [ 11 ] = V_75 -> V_204 ;
}
}
static void F_72 ( struct V_151 * V_152 )
{
struct V_12 * V_13 = V_152 -> V_13 ;
struct V_63 * V_64 = V_152 -> V_155 ;
struct V_74 * V_75 = & V_152 -> V_196 ;
unsigned char * V_197 = V_64 -> V_73 ;
int V_186 = V_152 -> V_9 -> V_82 -> V_198 == NULL ;
T_4 V_210 ;
T_3 V_137 , V_66 , V_67 ;
memset ( V_197 , 0 , V_78 ) ;
V_64 -> V_70 = ( V_71 << 24 ) | V_72 ;
if ( F_73 ( V_13 ) ) {
F_26 ( V_13 , V_64 , V_191 , 0x04 , 0x21 ) ;
return;
}
if ( V_152 -> V_199 ||
V_75 -> V_167 & ( V_170 | V_172 | V_177 | V_174 ) ) {
F_68 ( V_152 -> V_9 -> V_200 , V_75 -> V_167 , V_75 -> V_169 ,
& V_137 , & V_66 , & V_67 , V_186 ) ;
F_26 ( V_13 , V_64 , V_137 , V_66 , V_67 ) ;
} else {
F_74 ( V_13 , L_23 ,
V_75 -> V_167 , V_152 -> V_199 ) ;
F_26 ( V_13 , V_64 , V_189 , 0 , 0 ) ;
return;
}
V_210 = F_29 ( & V_152 -> V_196 , V_13 ) ;
if ( V_210 == V_77 )
return;
F_30 ( V_197 , V_78 , V_210 ) ;
}
static void F_75 ( struct V_28 * V_29 )
{
V_29 -> V_211 = 1 ;
V_29 -> V_212 = 1 ;
V_29 -> V_213 = 1 ;
V_29 -> V_214 = 1 ;
}
static int F_76 ( struct V_153 * V_215 )
{
if ( F_77 ( ! F_78 ( V_215 ) ) )
return 0 ;
if ( ! F_79 ( V_215 ) || F_80 ( F_81 ( V_215 ) ) )
return 0 ;
return F_82 ( F_83 ( V_215 ) -> V_64 [ 0 ] ) == V_216 ;
}
static int F_84 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_217 * V_218 = V_29 -> V_217 ;
if ( ! F_85 ( V_13 -> V_107 ) )
V_13 -> V_16 |= V_37 ;
F_86 ( V_218 , V_13 -> V_219 ) ;
if ( V_13 -> V_49 == V_220 ) {
void * V_4 ;
V_29 -> V_221 = V_129 ;
F_87 ( V_218 , V_222 - 1 ) ;
V_4 = F_49 ( V_223 , V_218 -> V_224 | V_130 ) ;
if ( ! V_4 ) {
F_88 ( V_13 , L_24 ) ;
return - V_128 ;
}
F_89 ( V_218 , F_76 , V_4 , V_223 ) ;
} else {
V_29 -> V_221 = F_90 ( V_13 -> V_107 ) ;
V_29 -> V_225 = 1 ;
}
if ( V_29 -> V_221 > V_27 )
F_74 ( V_13 ,
L_25 ,
V_29 -> V_221 ) ;
F_91 ( V_218 , V_29 -> V_221 - 1 ) ;
if ( V_13 -> V_16 & V_226 )
F_92 ( V_227 , V_29 -> V_228 ) ;
if ( V_13 -> V_16 & V_229 ) {
int V_230 ;
V_230 = F_93 ( V_29 -> V_34 -> V_231 , F_94 ( V_13 -> V_107 ) ) ;
V_230 = F_93 ( V_232 - 1 , V_230 ) ;
F_95 ( V_29 , V_230 ) ;
}
F_96 ( V_218 , false ) ;
if ( V_13 -> V_16 & V_233 )
V_29 -> V_234 = 1 ;
V_13 -> V_29 = V_29 ;
return 0 ;
}
int F_97 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 = F_98 ( V_9 , V_29 ) ;
int V_33 = 0 ;
F_75 ( V_29 ) ;
if ( V_13 )
V_33 = F_84 ( V_29 , V_13 ) ;
return V_33 ;
}
void F_99 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_217 * V_218 = V_29 -> V_217 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_82 -> V_198 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_98 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_235 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_52 ( V_218 -> V_236 ) ;
V_218 -> V_236 = NULL ;
V_218 -> V_237 = 0 ;
}
int F_100 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_238 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_238 < 1 || V_238 == V_29 -> V_238 )
return V_29 -> V_238 ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_101 ( V_13 ) )
return V_29 -> V_238 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_239 ;
if ( V_238 == 1 || ! F_102 ( V_13 ) ) {
V_13 -> V_16 |= V_239 ;
V_238 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_238 = F_93 ( V_238 , V_29 -> V_34 -> V_231 ) ;
V_238 = F_93 ( V_238 , F_94 ( V_13 -> V_107 ) ) ;
V_238 = F_93 ( V_238 , V_232 - 1 ) ;
if ( V_29 -> V_238 == V_238 )
return - V_20 ;
return F_95 ( V_29 , V_238 ) ;
}
int F_103 ( struct V_28 * V_29 , int V_238 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_100 ( V_9 , V_29 , V_238 ) ;
}
static unsigned int F_104 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
struct V_74 * V_75 = & V_152 -> V_75 ;
const T_3 * V_240 = V_162 -> V_241 ;
T_5 V_242 ;
T_3 V_243 = 0xff ;
if ( V_162 -> V_244 < 5 ) {
V_242 = 4 ;
goto V_245;
}
V_75 -> V_16 |= V_246 | V_247 ;
V_75 -> V_248 = V_249 ;
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
V_75 -> V_201 = 1 ;
if ( V_152 -> V_13 -> V_16 & V_250 ) {
V_75 -> V_16 |= V_251 ;
V_75 -> V_204 = 0x0 ;
V_75 -> V_203 = 0x0 ;
V_75 -> V_202 = 0x0 ;
V_75 -> V_1 |= V_252 ;
} else {
V_75 -> V_202 = 0x1 ;
V_75 -> V_203 = 0x0 ;
V_75 -> V_204 = 0x0 ;
}
V_75 -> V_167 = V_253 ;
} else {
if ( ( V_152 -> V_9 -> V_16 & V_254 ) &&
V_255 == V_256 )
goto V_257;
if ( ( V_152 -> V_9 -> V_16 & V_258 ) &&
F_105 () )
goto V_257;
V_75 -> V_167 = V_259 ;
}
return 0 ;
V_245:
F_31 ( V_152 -> V_13 , V_162 , V_242 , V_243 ) ;
return 1 ;
V_257:
V_162 -> V_70 = V_260 ;
return 1 ;
}
static unsigned int F_106 ( struct V_151 * V_152 )
{
struct V_74 * V_75 = & V_152 -> V_75 ;
V_75 -> V_16 |= V_246 ;
V_75 -> V_248 = V_249 ;
if ( V_152 -> V_13 -> V_16 & V_261 )
V_75 -> V_167 = V_262 ;
else
V_75 -> V_167 = V_263 ;
V_152 -> V_16 |= V_264 ;
return 0 ;
}
static void F_107 ( const T_3 * V_240 , T_4 * V_265 , T_8 * V_266 )
{
T_4 V_267 = 0 ;
T_8 V_45 ;
F_108 ( L_26 ) ;
V_267 |= ( ( T_4 ) ( V_240 [ 1 ] & 0x1f ) ) << 16 ;
V_267 |= ( ( T_4 ) V_240 [ 2 ] ) << 8 ;
V_267 |= ( ( T_4 ) V_240 [ 3 ] ) ;
V_45 = V_240 [ 4 ] ;
* V_265 = V_267 ;
* V_266 = V_45 ;
}
static void F_109 ( const T_3 * V_240 , T_4 * V_265 , T_8 * V_266 )
{
T_4 V_267 = 0 ;
T_8 V_45 = 0 ;
F_108 ( L_27 ) ;
V_267 |= ( ( T_4 ) V_240 [ 2 ] ) << 24 ;
V_267 |= ( ( T_4 ) V_240 [ 3 ] ) << 16 ;
V_267 |= ( ( T_4 ) V_240 [ 4 ] ) << 8 ;
V_267 |= ( ( T_4 ) V_240 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_240 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_240 [ 8 ] ) ;
* V_265 = V_267 ;
* V_266 = V_45 ;
}
static void F_110 ( const T_3 * V_240 , T_4 * V_265 , T_8 * V_266 )
{
T_4 V_267 = 0 ;
T_8 V_45 = 0 ;
F_108 ( L_28 ) ;
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
static unsigned int F_111 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
struct V_74 * V_75 = & V_152 -> V_75 ;
struct V_12 * V_13 = V_152 -> V_13 ;
T_4 V_268 = V_152 -> V_13 -> V_100 ;
const T_3 * V_240 = V_162 -> V_241 ;
T_4 V_210 ;
T_8 V_269 ;
T_5 V_242 ;
V_75 -> V_16 |= V_247 | V_246 ;
V_75 -> V_248 = V_249 ;
if ( V_240 [ 0 ] == V_270 ) {
if ( V_162 -> V_244 < 10 ) {
V_242 = 9 ;
goto V_245;
}
F_109 ( V_240 , & V_210 , & V_269 ) ;
} else if ( V_240 [ 0 ] == V_271 ) {
if ( V_162 -> V_244 < 16 ) {
V_242 = 15 ;
goto V_245;
}
F_110 ( V_240 , & V_210 , & V_269 ) ;
} else {
V_242 = 0 ;
goto V_245;
}
if ( ! V_269 )
goto V_272;
if ( V_210 >= V_268 )
goto V_273;
if ( ( V_210 + V_269 ) > V_268 )
goto V_273;
if ( V_13 -> V_16 & V_250 ) {
V_75 -> V_16 |= V_251 ;
if ( F_112 ( V_210 , V_269 ) ) {
V_75 -> V_167 = V_253 ;
V_75 -> V_1 |= ( V_210 >> 24 ) & 0xf ;
} else if ( F_113 ( V_210 , V_269 ) ) {
if ( ! ( V_13 -> V_16 & V_274 ) )
goto V_273;
V_75 -> V_16 |= V_205 ;
V_75 -> V_167 = V_275 ;
V_75 -> V_206 = ( V_269 >> 8 ) & 0xff ;
V_75 -> V_209 = ( V_210 >> 40 ) & 0xff ;
V_75 -> V_208 = ( V_210 >> 32 ) & 0xff ;
V_75 -> V_207 = ( V_210 >> 24 ) & 0xff ;
} else
goto V_273;
V_75 -> V_201 = V_269 & 0xff ;
V_75 -> V_204 = ( V_210 >> 16 ) & 0xff ;
V_75 -> V_203 = ( V_210 >> 8 ) & 0xff ;
V_75 -> V_202 = V_210 & 0xff ;
V_75 -> V_1 |= V_252 ;
} else {
T_8 V_276 , V_277 , V_278 , V_279 ;
if ( ! F_112 ( V_210 , V_269 ) )
goto V_273;
V_279 = ( T_8 ) V_210 / V_13 -> V_280 ;
V_278 = V_279 / V_13 -> V_281 ;
V_277 = V_279 % V_13 -> V_281 ;
V_276 = ( T_8 ) V_210 % V_13 -> V_280 + 1 ;
F_114 ( L_29 ,
( T_8 ) V_210 , V_279 , V_278 , V_277 , V_276 ) ;
if ( ( V_278 >> 16 ) || ( V_277 >> 4 ) || ( V_276 >> 8 ) || ( ! V_276 ) )
goto V_273;
V_75 -> V_167 = V_253 ;
V_75 -> V_201 = V_269 & 0xff ;
V_75 -> V_202 = V_276 ;
V_75 -> V_203 = V_278 ;
V_75 -> V_204 = V_278 >> 8 ;
V_75 -> V_1 |= V_277 ;
}
return 0 ;
V_245:
F_31 ( V_152 -> V_13 , V_162 , V_242 , 0xff ) ;
return 1 ;
V_273:
F_26 ( V_152 -> V_13 , V_162 , V_81 , 0x21 , 0x0 ) ;
return 1 ;
V_272:
V_162 -> V_70 = V_260 ;
return 1 ;
}
static unsigned int F_115 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
const T_3 * V_240 = V_162 -> V_241 ;
struct V_153 * V_215 = V_162 -> V_153 ;
int V_49 = F_116 ( F_117 ( V_215 ) ) ;
unsigned int V_282 = 0 ;
T_4 V_210 ;
T_8 V_269 ;
int V_33 ;
T_5 V_242 = 0 ;
if ( V_240 [ 0 ] == V_283 || V_240 [ 0 ] == V_284 || V_240 [ 0 ] == V_285 )
V_282 |= V_286 ;
switch ( V_240 [ 0 ] ) {
case V_287 :
case V_283 :
if ( F_20 ( V_162 -> V_244 < 10 ) ) {
V_242 = 9 ;
goto V_245;
}
F_109 ( V_240 , & V_210 , & V_269 ) ;
if ( V_240 [ 1 ] & ( 1 << 3 ) )
V_282 |= V_288 ;
break;
case V_289 :
case V_284 :
if ( F_20 ( V_162 -> V_244 < 6 ) ) {
V_242 = 5 ;
goto V_245;
}
F_107 ( V_240 , & V_210 , & V_269 ) ;
if ( ! V_269 )
V_269 = 256 ;
break;
case V_290 :
case V_285 :
if ( F_20 ( V_162 -> V_244 < 16 ) ) {
V_242 = 15 ;
goto V_245;
}
F_110 ( V_240 , & V_210 , & V_269 ) ;
if ( V_240 [ 1 ] & ( 1 << 3 ) )
V_282 |= V_288 ;
break;
default:
F_114 ( L_30 ) ;
V_242 = 0 ;
goto V_245;
}
if ( ! V_269 )
goto V_272;
V_152 -> V_16 |= V_264 ;
V_152 -> V_165 = V_269 * V_162 -> V_1 -> V_221 ;
V_33 = F_118 ( & V_152 -> V_75 , V_152 -> V_13 , V_210 , V_269 , V_282 ,
V_152 -> V_154 , V_49 ) ;
if ( F_77 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_291 )
goto V_273;
V_245:
F_31 ( V_152 -> V_13 , V_162 , V_242 , 0xff ) ;
return 1 ;
V_273:
F_26 ( V_152 -> V_13 , V_162 , V_81 , 0x21 , 0x0 ) ;
return 1 ;
V_272:
V_162 -> V_70 = V_260 ;
return 1 ;
}
static void F_119 ( struct V_151 * V_152 )
{
struct V_63 * V_64 = V_152 -> V_155 ;
void (* F_120)( struct V_63 * ) = V_152 -> V_156 ;
F_121 ( V_152 ) ;
F_120 ( V_64 ) ;
}
static void F_122 ( struct V_151 * V_152 )
{
struct V_8 * V_9 = V_152 -> V_9 ;
struct V_63 * V_64 = V_152 -> V_155 ;
T_3 * V_240 = V_64 -> V_241 ;
int V_292 = ( V_152 -> V_199 != 0 ) ;
if ( ( ( V_240 [ 0 ] == V_133 ) || ( V_240 [ 0 ] == V_293 ) ) &&
( ( V_240 [ 2 ] & 0x20 ) || V_292 ) )
F_70 ( V_152 ) ;
else if ( V_152 -> V_16 & V_294 )
V_64 -> V_70 = V_72 ;
else if ( V_292 )
F_72 ( V_152 ) ;
else
V_64 -> V_70 = V_260 ;
if ( V_292 && ! V_9 -> V_82 -> V_198 )
F_65 ( V_9 -> V_200 , & V_152 -> V_196 ) ;
F_119 ( V_152 ) ;
}
static int F_123 ( struct V_12 * V_13 , struct V_63 * V_64 ,
T_9 V_295 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_151 * V_152 ;
int V_33 ;
F_108 ( L_31 ) ;
V_152 = F_59 ( V_13 , V_64 ) ;
if ( ! V_152 )
goto V_296;
if ( V_64 -> V_297 == V_131 ||
V_64 -> V_297 == V_298 ) {
if ( F_20 ( F_64 ( V_64 ) < 1 ) ) {
F_74 ( V_13 , L_32 ) ;
goto V_299;
}
F_124 ( V_152 , F_61 ( V_64 ) , F_62 ( V_64 ) ) ;
V_152 -> V_300 = V_64 -> V_297 ;
}
V_152 -> V_301 = F_122 ;
if ( V_295 ( V_152 ) )
goto V_302;
if ( V_9 -> V_82 -> V_303 ) {
if ( ( V_33 = V_9 -> V_82 -> V_303 ( V_152 ) ) )
goto V_304;
}
F_125 ( V_152 ) ;
F_108 ( L_33 ) ;
return 0 ;
V_302:
F_121 ( V_152 ) ;
V_64 -> V_157 ( V_64 ) ;
F_114 ( L_34 ) ;
return 0 ;
V_299:
F_121 ( V_152 ) ;
V_64 -> V_70 = ( V_305 << 16 ) ;
V_64 -> V_157 ( V_64 ) ;
V_296:
F_114 ( L_35 ) ;
return 0 ;
V_304:
F_121 ( V_152 ) ;
F_114 ( L_36 ) ;
if ( V_33 == V_306 )
return V_307 ;
else
return V_308 ;
}
static void * F_126 ( struct V_63 * V_64 , bool V_309 ,
unsigned long * V_16 )
{
F_5 ( & V_310 , * V_16 ) ;
memset ( V_311 , 0 , V_312 ) ;
if ( V_309 )
F_127 ( F_61 ( V_64 ) , F_62 ( V_64 ) ,
V_311 , V_312 ) ;
return V_311 ;
}
static inline void F_128 ( struct V_63 * V_64 , bool V_313 ,
unsigned long * V_16 )
{
if ( V_313 )
F_129 ( F_61 ( V_64 ) , F_62 ( V_64 ) ,
V_311 , V_312 ) ;
F_9 ( & V_310 , * V_16 ) ;
}
static unsigned int F_130 ( struct V_314 * args , T_3 * V_315 )
{
const T_3 V_316 [] = {
0x00 ,
0x60 ,
0x03 ,
0x20 ,
0x03 ,
0x00
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
95 - 4 ,
0 ,
0 ,
2
} ;
F_108 ( L_31 ) ;
if ( F_131 ( args -> V_107 ) ||
( args -> V_13 -> V_11 -> V_9 -> V_39 & V_320 ) )
V_318 [ 1 ] |= ( 1 << 7 ) ;
if ( args -> V_13 -> V_49 == V_51 ) {
V_318 [ 0 ] = V_321 ;
V_318 [ 2 ] = 0x7 ;
}
memcpy ( V_315 , V_318 , sizeof( V_318 ) ) ;
memcpy ( & V_315 [ 8 ] , L_37 , 8 ) ;
F_45 ( args -> V_107 , & V_315 [ 16 ] , V_110 , 16 ) ;
F_45 ( args -> V_107 , & V_315 [ 32 ] , V_112 + 2 , 4 ) ;
if ( strncmp ( & V_315 [ 32 ] , L_38 , 4 ) == 0 )
F_45 ( args -> V_107 , & V_315 [ 32 ] , V_112 , 4 ) ;
if ( V_315 [ 32 ] == 0 || V_315 [ 32 ] == ' ' )
memcpy ( & V_315 [ 32 ] , L_39 , 4 ) ;
if ( F_132 ( args -> V_107 ) || args -> V_13 -> V_49 == V_51 )
memcpy ( V_315 + 58 , V_317 , sizeof( V_317 ) ) ;
else
memcpy ( V_315 + 58 , V_316 , sizeof( V_316 ) ) ;
return 0 ;
}
static unsigned int F_133 ( struct V_314 * args , T_3 * V_315 )
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
static unsigned int F_134 ( struct V_314 * args , T_3 * V_315 )
{
const T_3 V_318 [] = {
0 ,
0x80 ,
0 ,
V_115 ,
} ;
memcpy ( V_315 , V_318 , sizeof( V_318 ) ) ;
F_45 ( args -> V_107 , ( unsigned char * ) & V_315 [ 4 ] ,
V_114 , V_115 ) ;
return 0 ;
}
static unsigned int F_135 ( struct V_314 * args , T_3 * V_315 )
{
const int V_325 = 68 ;
int V_326 ;
V_315 [ 1 ] = 0x83 ;
V_326 = 4 ;
V_315 [ V_326 + 0 ] = 2 ;
V_315 [ V_326 + 3 ] = V_115 ;
V_326 += 4 ;
F_45 ( args -> V_107 , ( unsigned char * ) V_315 + V_326 ,
V_114 , V_115 ) ;
V_326 += V_115 ;
V_315 [ V_326 + 0 ] = 2 ;
V_315 [ V_326 + 1 ] = 1 ;
V_315 [ V_326 + 3 ] = V_325 ;
V_326 += 4 ;
memcpy ( V_315 + V_326 , L_37 , 8 ) ;
V_326 += 8 ;
F_45 ( args -> V_107 , ( unsigned char * ) V_315 + V_326 , V_110 ,
V_111 ) ;
V_326 += V_111 ;
F_45 ( args -> V_107 , ( unsigned char * ) V_315 + V_326 , V_114 ,
V_115 ) ;
V_326 += V_115 ;
if ( F_136 ( args -> V_107 ) ) {
V_315 [ V_326 + 0 ] = 1 ;
V_315 [ V_326 + 1 ] = 3 ;
V_315 [ V_326 + 3 ] = V_327 ;
V_326 += 4 ;
F_45 ( args -> V_107 , ( unsigned char * ) V_315 + V_326 ,
V_328 , V_327 ) ;
V_326 += V_327 ;
}
V_315 [ 3 ] = V_326 - 4 ;
return 0 ;
}
static unsigned int F_137 ( struct V_314 * args , T_3 * V_315 )
{
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_315 [ 1 ] = 0x89 ;
V_315 [ 2 ] = ( 0x238 >> 8 ) ;
V_315 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_315 [ 8 ] , L_40 , 8 ) ;
memcpy ( & V_315 [ 16 ] , L_41 , 16 ) ;
memcpy ( & V_315 [ 32 ] , V_329 , 4 ) ;
V_75 . V_167 = V_171 ;
V_75 . V_202 = 0x1 ;
V_75 . V_201 = 0x1 ;
F_138 ( & V_75 , 0 , 1 , & V_315 [ 36 ] ) ;
V_315 [ 36 ] = 0x34 ;
V_315 [ 56 ] = V_330 ;
memcpy ( & V_315 [ 60 ] , & args -> V_107 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_139 ( struct V_314 * args , T_3 * V_315 )
{
T_5 V_331 ;
V_315 [ 1 ] = 0xb0 ;
V_315 [ 3 ] = 0x3c ;
V_331 = 1 << F_140 ( args -> V_107 ) ;
F_141 ( V_331 , & V_315 [ 6 ] ) ;
if ( F_142 ( args -> V_107 ) ) {
F_143 ( 65535 * V_332 , & V_315 [ 36 ] ) ;
F_144 ( 1 , & V_315 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_145 ( struct V_314 * args , T_3 * V_315 )
{
int V_333 = F_146 ( args -> V_107 ) ;
int V_334 = F_147 ( args -> V_107 ) ;
T_3 V_335 = F_132 ( args -> V_107 ) ;
V_315 [ 1 ] = 0xb1 ;
V_315 [ 3 ] = 0x3c ;
V_315 [ 4 ] = V_334 >> 8 ;
V_315 [ 5 ] = V_334 ;
V_315 [ 7 ] = V_333 ;
if ( V_335 )
V_315 [ 8 ] = ( V_335 << 4 ) ;
return 0 ;
}
static unsigned int F_148 ( struct V_314 * args , T_3 * V_315 )
{
V_315 [ 1 ] = 0xb2 ;
V_315 [ 3 ] = 0x4 ;
V_315 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_149 ( struct V_314 * args , T_3 * V_315 )
{
V_315 [ 1 ] = 0xb6 ;
V_315 [ 3 ] = 0x3C ;
if ( args -> V_13 -> V_336 & 1 )
V_315 [ 4 ] |= 1 ;
F_144 ( args -> V_13 -> V_337 , & V_315 [ 8 ] ) ;
F_144 ( args -> V_13 -> V_338 , & V_315 [ 12 ] ) ;
F_144 ( args -> V_13 -> V_339 , & V_315 [ 16 ] ) ;
return 0 ;
}
static void F_150 ( T_3 * V_340 , const T_3 * V_341 , int V_342 , bool V_343 )
{
if ( V_343 ) {
memcpy ( V_340 , V_341 , 2 ) ;
memset ( V_340 + 2 , 0 , V_342 - 2 ) ;
} else {
memcpy ( V_340 , V_341 , V_342 ) ;
}
}
static unsigned int F_151 ( T_5 * V_107 , T_3 * V_4 , bool V_343 )
{
F_150 ( V_4 , V_344 , sizeof( V_344 ) , V_343 ) ;
if ( V_343 ) {
V_4 [ 2 ] |= ( 1 << 2 ) ;
} else {
V_4 [ 2 ] |= ( F_152 ( V_107 ) << 2 ) ;
V_4 [ 12 ] |= ( ! F_153 ( V_107 ) << 5 ) ;
}
return sizeof( V_344 ) ;
}
static unsigned int F_154 ( struct V_12 * V_13 , T_3 * V_4 ,
bool V_343 )
{
F_150 ( V_4 , V_345 , sizeof( V_345 ) , V_343 ) ;
if ( V_343 ) {
V_4 [ 2 ] |= ( 1 << 2 ) ;
} else {
bool V_68 = ( V_13 -> V_16 & V_69 ) ;
V_4 [ 2 ] |= ( V_68 << 2 ) ;
}
return sizeof( V_345 ) ;
}
static unsigned int F_155 ( T_3 * V_4 , bool V_343 )
{
F_150 ( V_4 , V_346 , sizeof( V_346 ) ,
V_343 ) ;
return sizeof( V_346 ) ;
}
static int F_156 ( T_5 * V_107 )
{
unsigned char V_347 [ V_111 + 1 ] , V_348 [ V_113 + 1 ] ;
if ( ! V_349 )
return 0 ;
if ( ! F_157 ( V_107 ) )
return 0 ;
F_158 ( V_107 , V_347 , V_110 , sizeof( V_347 ) ) ;
F_158 ( V_107 , V_348 , V_112 , sizeof( V_348 ) ) ;
if ( strcmp ( V_347 , L_42 ) )
return 1 ;
if ( strcmp ( V_348 , L_43 ) )
return 1 ;
return 0 ;
}
static unsigned int F_159 ( struct V_314 * args , T_3 * V_315 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_155 = args -> V_64 -> V_241 , * V_350 = V_315 ;
const T_3 V_351 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_352 , V_353 ;
unsigned int V_354 , V_355 , V_356 ;
T_3 V_357 , V_243 = 0xff ;
T_5 V_242 ;
F_108 ( L_31 ) ;
V_356 = ( V_155 [ 0 ] == V_358 ) ;
V_354 = ! ( V_155 [ 1 ] & 0x8 ) ;
V_355 = V_155 [ 2 ] >> 6 ;
switch ( V_355 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_359;
default:
V_242 = 2 ;
V_243 = 6 ;
goto V_245;
}
if ( V_356 )
V_350 += 4 + ( V_354 ? 8 : 0 ) ;
else
V_350 += 8 + ( V_354 ? 8 : 0 ) ;
V_352 = V_155 [ 2 ] & 0x3f ;
V_353 = V_155 [ 3 ] ;
if ( V_353 && ( V_353 != V_360 ) ) {
V_242 = 3 ;
goto V_245;
}
switch( V_352 ) {
case V_361 :
V_350 += F_155 ( V_350 , V_355 == 1 ) ;
break;
case V_362 :
V_350 += F_151 ( args -> V_107 , V_350 , V_355 == 1 ) ;
break;
case V_363 :
V_350 += F_154 ( args -> V_13 , V_350 , V_355 == 1 ) ;
break;
case V_364 :
V_350 += F_155 ( V_350 , V_355 == 1 ) ;
V_350 += F_151 ( args -> V_107 , V_350 , V_355 == 1 ) ;
V_350 += F_154 ( args -> V_13 , V_350 , V_355 == 1 ) ;
break;
default:
V_242 = 2 ;
goto V_245;
}
V_357 = 0 ;
if ( F_156 ( args -> V_107 ) && ( V_13 -> V_16 & V_274 ) &&
( ! ( V_13 -> V_16 & V_365 ) || V_13 -> V_366 ) )
V_357 = 1 << 4 ;
if ( V_356 ) {
V_315 [ 0 ] = V_350 - V_315 - 1 ;
V_315 [ 2 ] |= V_357 ;
if ( V_354 ) {
V_315 [ 3 ] = sizeof( V_351 ) ;
memcpy ( V_315 + 4 , V_351 , sizeof( V_351 ) ) ;
}
} else {
unsigned int V_367 = V_350 - V_315 - 2 ;
V_315 [ 0 ] = V_367 >> 8 ;
V_315 [ 1 ] = V_367 ;
V_315 [ 3 ] |= V_357 ;
if ( V_354 ) {
V_315 [ 7 ] = sizeof( V_351 ) ;
memcpy ( V_315 + 8 , V_351 , sizeof( V_351 ) ) ;
}
}
return 0 ;
V_245:
F_31 ( V_13 , args -> V_64 , V_242 , V_243 ) ;
return 1 ;
V_359:
F_26 ( V_13 , args -> V_64 , V_81 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_160 ( struct V_314 * args , T_3 * V_315 )
{
struct V_12 * V_13 = args -> V_13 ;
T_4 V_368 = V_13 -> V_100 - 1 ;
T_8 V_221 ;
T_3 V_369 ;
T_5 V_370 ;
V_221 = F_90 ( V_13 -> V_107 ) ;
V_369 = F_140 ( V_13 -> V_107 ) ;
V_370 = F_161 ( V_13 -> V_107 , V_369 ) ;
F_108 ( L_31 ) ;
if ( args -> V_64 -> V_241 [ 0 ] == V_371 ) {
if ( V_368 >= 0xffffffffULL )
V_368 = 0xffffffff ;
V_315 [ 0 ] = V_368 >> ( 8 * 3 ) ;
V_315 [ 1 ] = V_368 >> ( 8 * 2 ) ;
V_315 [ 2 ] = V_368 >> ( 8 * 1 ) ;
V_315 [ 3 ] = V_368 ;
V_315 [ 4 ] = V_221 >> ( 8 * 3 ) ;
V_315 [ 5 ] = V_221 >> ( 8 * 2 ) ;
V_315 [ 6 ] = V_221 >> ( 8 * 1 ) ;
V_315 [ 7 ] = V_221 ;
} else {
V_315 [ 0 ] = V_368 >> ( 8 * 7 ) ;
V_315 [ 1 ] = V_368 >> ( 8 * 6 ) ;
V_315 [ 2 ] = V_368 >> ( 8 * 5 ) ;
V_315 [ 3 ] = V_368 >> ( 8 * 4 ) ;
V_315 [ 4 ] = V_368 >> ( 8 * 3 ) ;
V_315 [ 5 ] = V_368 >> ( 8 * 2 ) ;
V_315 [ 6 ] = V_368 >> ( 8 * 1 ) ;
V_315 [ 7 ] = V_368 ;
V_315 [ 8 ] = V_221 >> ( 8 * 3 ) ;
V_315 [ 9 ] = V_221 >> ( 8 * 2 ) ;
V_315 [ 10 ] = V_221 >> ( 8 * 1 ) ;
V_315 [ 11 ] = V_221 ;
V_315 [ 12 ] = 0 ;
V_315 [ 13 ] = V_369 ;
V_315 [ 14 ] = ( V_370 >> 8 ) & 0x3f ;
V_315 [ 15 ] = V_370 ;
if ( F_142 ( args -> V_107 ) &&
! ( V_13 -> V_22 & V_372 ) ) {
V_315 [ 14 ] |= 0x80 ;
if ( F_162 ( args -> V_107 ) &&
V_13 -> V_22 & V_373 ) {
F_163 ( V_13 , L_44 ) ;
V_315 [ 14 ] |= 0x40 ;
}
}
if ( F_132 ( args -> V_107 ) ||
args -> V_13 -> V_49 == V_51 )
V_315 [ 12 ] = ( 1 << 4 ) ;
}
return 0 ;
}
static unsigned int F_164 ( struct V_314 * args , T_3 * V_315 )
{
F_108 ( L_31 ) ;
V_315 [ 3 ] = 8 ;
return 0 ;
}
static void F_165 ( struct V_151 * V_152 )
{
if ( V_152 -> V_199 && ( ( V_152 -> V_199 & V_374 ) == 0 ) ) {
F_70 ( V_152 ) ;
}
F_119 ( V_152 ) ;
}
static inline int F_166 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_139 ) ;
}
static void F_167 ( struct V_151 * V_152 )
{
struct V_8 * V_9 = V_152 -> V_9 ;
struct V_63 * V_64 = V_152 -> V_155 ;
F_114 ( L_45 ) ;
memset ( V_64 -> V_73 , 0 , V_78 ) ;
#ifdef F_168
if ( V_9 -> V_82 -> V_375 )
V_9 -> V_82 -> V_375 ( V_9 , & V_152 -> V_75 ) ;
#endif
V_64 -> V_73 [ 0 ] = 0x70 ;
V_64 -> V_73 [ 2 ] = V_152 -> V_75 . V_169 >> 4 ;
F_169 ( V_152 ) ;
F_170 ( & V_152 -> V_376 , V_64 -> V_73 , V_78 ) ;
F_124 ( V_152 , & V_152 -> V_376 , 1 ) ;
V_152 -> V_300 = V_131 ;
memset ( & V_152 -> V_240 , 0 , V_152 -> V_13 -> V_377 ) ;
V_152 -> V_240 [ 0 ] = V_378 ;
V_152 -> V_240 [ 4 ] = V_78 ;
V_152 -> V_75 . V_16 |= V_247 | V_246 ;
V_152 -> V_75 . V_167 = V_379 ;
if ( F_166 ( V_9 ) ) {
V_152 -> V_75 . V_248 = V_380 ;
V_152 -> V_75 . V_169 |= V_381 ;
} else {
V_152 -> V_75 . V_248 = V_382 ;
V_152 -> V_75 . V_203 = V_78 ;
V_152 -> V_75 . V_204 = 0 ;
}
V_152 -> V_165 = V_78 ;
V_152 -> V_301 = F_165 ;
F_125 ( V_152 ) ;
F_114 ( L_33 ) ;
}
static void F_171 ( struct V_63 * V_64 )
{
T_3 V_4 [ 4 ] ;
F_127 ( F_61 ( V_64 ) , F_62 ( V_64 ) , V_4 , 4 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_129 ( F_61 ( V_64 ) , F_62 ( V_64 ) , V_4 , 4 ) ;
}
static void F_172 ( struct V_151 * V_152 )
{
struct V_63 * V_64 = V_152 -> V_155 ;
unsigned int V_199 = V_152 -> V_199 ;
F_108 ( L_46 , V_199 ) ;
if ( F_20 ( V_152 -> V_9 -> V_82 -> V_198 &&
( V_199 || V_152 -> V_16 & V_294 ) ) ) {
if ( ! ( V_152 -> V_16 & V_294 ) ) {
F_70 ( V_152 ) ;
}
if ( V_152 -> V_240 [ 0 ] == V_383 && V_152 -> V_13 -> V_29 )
V_152 -> V_13 -> V_29 -> V_384 = 0 ;
V_152 -> V_155 -> V_70 = V_72 ;
F_119 ( V_152 ) ;
return;
}
if ( F_20 ( V_199 & V_374 ) ) {
V_64 -> V_70 = V_72 ;
F_167 ( V_152 ) ;
return;
} else if ( F_20 ( V_199 ) ) {
F_70 ( V_152 ) ;
} else {
if ( V_64 -> V_241 [ 0 ] == V_385 && ( V_64 -> V_241 [ 1 ] & 0x03 ) == 0 )
F_171 ( V_64 ) ;
V_64 -> V_70 = V_260 ;
}
F_119 ( V_152 ) ;
}
static unsigned int F_173 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
struct V_12 * V_13 = V_152 -> V_13 ;
int V_386 = ( V_162 -> V_297 == V_132 ) ;
int V_387 = ! V_386 && ( V_13 -> V_16 & V_365 ) ;
unsigned int V_165 ;
memset ( V_152 -> V_240 , 0 , V_13 -> V_377 ) ;
memcpy ( V_152 -> V_240 , V_162 -> V_241 , V_162 -> V_244 ) ;
V_152 -> V_301 = F_172 ;
V_152 -> V_75 . V_16 |= V_247 | V_246 ;
if ( V_162 -> V_297 == V_298 ) {
V_152 -> V_75 . V_16 |= V_286 ;
F_114 ( L_47 ) ;
}
V_152 -> V_75 . V_167 = V_379 ;
F_63 ( V_152 ) ;
if ( ! V_386 && ! V_387 && F_174 ( V_152 ) )
V_387 = 1 ;
V_165 = F_93 ( F_175 ( V_152 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_165 & 0x1 )
V_165 ++ ;
V_152 -> V_75 . V_203 = ( V_165 & 0xFF ) ;
V_152 -> V_75 . V_204 = ( V_165 >> 8 ) ;
if ( V_386 )
V_152 -> V_75 . V_248 = V_388 ;
else if ( V_387 )
V_152 -> V_75 . V_248 = V_382 ;
else {
V_152 -> V_75 . V_248 = V_380 ;
V_152 -> V_75 . V_169 |= V_381 ;
if ( ( V_13 -> V_16 & V_389 ) &&
( V_162 -> V_297 != V_298 ) )
V_152 -> V_75 . V_169 |= V_390 ;
}
return 0 ;
}
static struct V_12 * F_176 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_177 ( V_9 ) ) {
if ( F_77 ( V_43 >= 0 &&
V_43 < F_178 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_77 ( V_43 >= 0 &&
V_43 < V_9 -> V_391 ) )
return & V_9 -> V_392 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_98 ( struct V_8 * V_9 ,
const struct V_28 * V_116 )
{
int V_43 ;
if ( ! F_177 ( V_9 ) ) {
if ( F_20 ( V_116 -> V_393 || V_116 -> V_394 ) )
return NULL ;
V_43 = V_116 -> V_107 ;
} else {
if ( F_20 ( V_116 -> V_107 || V_116 -> V_394 ) )
return NULL ;
V_43 = V_116 -> V_393 ;
}
return F_176 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_14 ( struct V_8 * V_9 , const struct V_28 * V_116 )
{
struct V_12 * V_13 = F_98 ( V_9 , V_116 ) ;
if ( F_20 ( ! V_13 || ! F_101 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_179 ( T_3 V_395 )
{
switch( ( V_395 & 0x1e ) >> 1 ) {
case 3 :
return V_249 ;
case 6 :
case 10 :
case 11 :
return V_396 ;
case 4 :
case 5 :
return V_397 ;
case 12 :
return V_398 ;
case 0 :
case 1 :
case 8 :
case 9 :
case 7 :
case 15 :
default:
break;
}
return V_399 ;
}
static unsigned int F_180 ( struct V_151 * V_152 )
{
struct V_74 * V_75 = & ( V_152 -> V_75 ) ;
struct V_63 * V_162 = V_152 -> V_155 ;
struct V_12 * V_13 = V_152 -> V_13 ;
const T_3 * V_240 = V_162 -> V_241 ;
T_5 V_242 ;
T_5 V_400 = 0 ;
if ( V_240 [ 0 ] == V_401 )
V_400 = 9 ;
V_75 -> V_248 = F_179 ( V_240 [ 1 + V_400 ] ) ;
if ( V_75 -> V_248 == V_399 ) {
V_242 = 1 ;
goto V_245;
}
if ( F_181 ( V_75 -> V_248 ) && ( V_240 [ 2 + V_400 ] & 0x3 ) == 0 )
V_75 -> V_248 = V_402 ;
V_75 -> V_16 |= V_251 ;
if ( V_240 [ 0 ] == V_133 ) {
if ( V_240 [ 1 ] & 0x01 ) {
V_75 -> V_403 = V_240 [ 3 ] ;
V_75 -> V_206 = V_240 [ 5 ] ;
V_75 -> V_207 = V_240 [ 7 ] ;
V_75 -> V_208 = V_240 [ 9 ] ;
V_75 -> V_209 = V_240 [ 11 ] ;
V_75 -> V_16 |= V_205 ;
} else
V_75 -> V_16 &= ~ V_205 ;
V_75 -> V_169 = V_240 [ 4 ] ;
V_75 -> V_201 = V_240 [ 6 ] ;
V_75 -> V_202 = V_240 [ 8 ] ;
V_75 -> V_203 = V_240 [ 10 ] ;
V_75 -> V_204 = V_240 [ 12 ] ;
V_75 -> V_1 = V_240 [ 13 ] ;
V_75 -> V_167 = V_240 [ 14 ] ;
} else if ( V_240 [ 0 ] == V_293 ) {
V_75 -> V_16 &= ~ V_205 ;
V_75 -> V_169 = V_240 [ 3 ] ;
V_75 -> V_201 = V_240 [ 4 ] ;
V_75 -> V_202 = V_240 [ 5 ] ;
V_75 -> V_203 = V_240 [ 6 ] ;
V_75 -> V_204 = V_240 [ 7 ] ;
V_75 -> V_1 = V_240 [ 8 ] ;
V_75 -> V_167 = V_240 [ 9 ] ;
} else {
if ( V_240 [ 10 ] & 0x01 ) {
V_75 -> V_403 = V_240 [ 20 ] ;
V_75 -> V_206 = V_240 [ 22 ] ;
V_75 -> V_207 = V_240 [ 16 ] ;
V_75 -> V_208 = V_240 [ 15 ] ;
V_75 -> V_209 = V_240 [ 14 ] ;
V_75 -> V_16 |= V_205 ;
} else
V_75 -> V_16 &= ~ V_205 ;
V_75 -> V_169 = V_240 [ 21 ] ;
V_75 -> V_201 = V_240 [ 23 ] ;
V_75 -> V_202 = V_240 [ 19 ] ;
V_75 -> V_203 = V_240 [ 18 ] ;
V_75 -> V_204 = V_240 [ 17 ] ;
V_75 -> V_1 = V_240 [ 24 ] ;
V_75 -> V_167 = V_240 [ 25 ] ;
V_75 -> V_404 = F_182 ( & V_240 [ 28 ] ) ;
}
if ( F_181 ( V_75 -> V_248 ) )
V_75 -> V_201 = V_152 -> V_154 << 3 ;
V_75 -> V_1 = V_13 -> V_43 ?
V_75 -> V_1 | V_405 : V_75 -> V_1 & ~ V_405 ;
switch ( V_75 -> V_167 ) {
case V_406 :
case V_407 :
case V_408 :
case V_409 :
if ( V_75 -> V_248 != V_397 || V_75 -> V_201 != 1 ) {
V_242 = 1 ;
goto V_245;
}
V_152 -> V_410 = F_64 ( V_162 ) ;
break;
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_253 :
case V_275 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_435 :
case V_436 :
V_152 -> V_410 = V_162 -> V_1 -> V_221 ;
break;
default:
V_152 -> V_410 = V_129 ;
}
V_75 -> V_16 |= V_247 | V_246 ;
if ( V_162 -> V_297 == V_298 )
V_75 -> V_16 |= V_286 ;
V_152 -> V_16 |= V_437 | V_438 ;
F_63 ( V_152 ) ;
if ( V_75 -> V_248 == V_396 && V_13 -> V_439 == 0 ) {
V_242 = 1 ;
goto V_245;
}
if ( ( V_240 [ 1 ] & 0xe0 ) && ! F_183 ( V_75 ) ) {
V_242 = 1 ;
goto V_245;
}
if ( F_183 ( V_75 ) ) {
unsigned int V_366 = 1 << ( V_240 [ 1 ] >> 5 ) ;
if ( V_366 != V_13 -> V_366 )
F_74 ( V_13 , L_48 ,
V_366 ) ;
}
if ( V_75 -> V_167 == V_440 &&
V_75 -> V_169 == V_441 ) {
V_242 = ( V_240 [ 0 ] == V_133 ) ? 4 : 3 ;
goto V_245;
}
if ( V_75 -> V_167 >= 0x5C && V_75 -> V_167 <= 0x5F && ! V_442 ) {
V_242 = ( V_240 [ 0 ] == V_133 ) ? 14 : 9 ;
goto V_245;
}
return 0 ;
V_245:
F_31 ( V_13 , V_162 , V_242 , 0xff ) ;
return 1 ;
}
static T_2 F_184 ( struct V_63 * V_64 , T_8 V_443 ,
T_4 V_444 , T_8 V_5 )
{
struct V_28 * V_445 = V_64 -> V_1 ;
T_2 V_45 = V_445 -> V_221 ;
T_2 V_446 ;
T_10 * V_4 ;
T_8 V_187 = 0 ;
unsigned long V_16 ;
F_185 ( V_45 > V_312 ) ;
if ( V_45 > V_312 )
V_45 = V_312 ;
F_5 ( & V_310 , V_16 ) ;
V_4 = ( ( void * ) V_311 ) ;
memset ( V_4 , 0 , V_45 ) ;
while ( V_187 < V_443 ) {
T_4 V_447 = V_444 |
( ( T_4 ) ( V_5 > 0xffff ? 0xffff : V_5 ) << 48 ) ;
V_4 [ V_187 ++ ] = F_186 ( V_447 ) ;
if ( V_5 <= 0xffff )
break;
V_5 -= 0xffff ;
V_444 += 0xffff ;
}
V_446 = F_129 ( F_61 ( V_64 ) , F_62 ( V_64 ) , V_4 , V_45 ) ;
F_9 ( & V_310 , V_16 ) ;
return V_446 ;
}
static unsigned int F_187 ( struct V_151 * V_152 )
{
struct V_74 * V_75 = & V_152 -> V_75 ;
struct V_63 * V_162 = V_152 -> V_155 ;
struct V_28 * V_445 = V_162 -> V_1 ;
T_2 V_45 = V_445 -> V_221 ;
struct V_12 * V_13 = V_152 -> V_13 ;
const T_3 * V_240 = V_162 -> V_241 ;
T_4 V_210 ;
T_8 V_269 ;
const T_8 V_443 = V_45 >> 3 ;
T_8 V_448 ;
T_5 V_242 ;
T_3 V_243 = 0xff ;
T_3 V_449 = V_240 [ 1 ] & 0x8 ;
if ( F_20 ( ! V_13 -> V_439 ) )
goto V_450;
if ( F_20 ( F_78 ( V_162 -> V_153 ) ) )
goto V_450;
if ( F_20 ( V_162 -> V_244 < 16 ) ) {
V_242 = 15 ;
goto V_245;
}
F_110 ( V_240 , & V_210 , & V_269 ) ;
if ( ! V_449 ||
( V_13 -> V_22 & V_372 ) ||
! F_142 ( V_13 -> V_107 ) ) {
V_242 = 1 ;
V_243 = 3 ;
goto V_245;
}
if ( V_269 > 0xffff * V_443 ) {
V_242 = 2 ;
goto V_245;
}
if ( ! F_62 ( V_162 ) )
goto V_451;
V_448 = F_184 ( V_162 , V_443 , V_210 , V_269 ) ;
if ( V_448 != V_45 )
goto V_451;
if ( F_102 ( V_13 ) && F_188 ( V_13 ) ) {
V_75 -> V_248 = V_398 ;
V_75 -> V_167 = V_452 ;
V_75 -> V_206 = V_453 & 0x1f ;
V_75 -> V_201 = V_152 -> V_154 << 3 ;
V_75 -> V_403 = ( V_448 / 512 ) >> 8 ;
V_75 -> V_169 = V_448 / 512 ;
V_75 -> V_404 = 1 ;
} else {
V_75 -> V_248 = V_396 ;
V_75 -> V_403 = 0 ;
V_75 -> V_169 = V_454 ;
V_75 -> V_206 = ( V_448 / 512 ) >> 8 ;
V_75 -> V_201 = V_448 / 512 ;
V_75 -> V_167 = V_455 ;
}
V_75 -> V_16 |= V_247 | V_246 | V_205 |
V_286 ;
F_63 ( V_152 ) ;
return 0 ;
V_245:
F_31 ( V_13 , V_162 , V_242 , V_243 ) ;
return 1 ;
V_451:
F_26 ( V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
V_450:
F_26 ( V_13 , V_162 , V_81 , 0x20 , 0x0 ) ;
return 1 ;
}
static unsigned int F_189 ( struct V_314 * args , T_3 * V_315 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_240 = args -> V_64 -> V_241 ;
T_3 V_456 = 0 ;
unsigned int V_168 = 0 ;
if ( V_240 [ 2 ] != 1 ) {
F_74 ( V_13 , L_49 , V_240 [ 2 ] ) ;
V_168 = 2 ;
goto V_457;
}
switch ( V_240 [ 3 ] ) {
case V_385 :
case V_358 :
case V_458 :
case V_371 :
case V_459 :
case V_460 :
case V_378 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
case V_465 :
case V_466 :
case V_467 :
case V_289 :
case V_287 :
case V_290 :
case V_284 :
case V_283 :
case V_285 :
case V_293 :
case V_133 :
case V_270 :
case V_271 :
case V_468 :
case V_469 :
case V_470 :
V_456 = 3 ;
break;
case V_471 :
case V_472 :
if ( F_132 ( V_13 -> V_107 ) ||
V_13 -> V_49 == V_51 )
V_456 = 3 ;
break;
case V_473 :
case V_474 :
if ( V_13 -> V_16 & V_233 )
V_456 = 3 ;
break;
default:
break;
}
V_457:
V_315 [ 1 ] = V_456 ;
return V_168 ;
}
static void F_190 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
struct V_475 V_476 ;
unsigned long V_16 ;
unsigned int V_477 = 0 ;
F_191 ( & V_476 , F_61 ( V_162 ) , F_62 ( V_162 ) ,
V_478 | V_479 ) ;
F_192 ( V_16 ) ;
while ( F_193 ( & V_476 ) ) {
unsigned int V_480 = 0 ;
if ( V_477 == 0 ) {
char * V_318 ;
T_8 V_481 ;
T_4 V_482 , V_483 ;
T_5 V_484 ;
V_318 = V_476 . V_485 ;
V_481 = F_194 ( & V_318 [ 0 ] ) ;
V_484 = F_195 ( & V_318 [ 4 ] ) ;
V_482 = F_196 ( & V_318 [ 8 ] ) ;
V_483 = F_196 ( & V_318 [ 16 ] ) ;
F_144 ( V_481 , & V_318 [ 0 ] ) ;
V_318 [ 4 ] = V_484 & 0xf ;
F_143 ( V_482 , & V_318 [ 8 ] ) ;
F_143 ( V_483 , & V_318 [ 16 ] ) ;
V_480 += 64 ;
V_477 += 64 ;
}
while ( V_480 < V_476 . V_486 ) {
char * V_487 ;
T_3 V_488 , type , V_489 , V_490 ;
T_4 V_448 , V_491 , V_492 ;
V_487 = V_476 . V_485 + V_480 ;
type = V_487 [ 0 ] & 0xf ;
V_488 = ( V_487 [ 1 ] >> 4 ) & 0xf ;
V_489 = ( V_487 [ 1 ] & 2 ) ;
V_490 = ( V_487 [ 1 ] & 1 ) ;
V_448 = F_196 ( & V_487 [ 8 ] ) ;
V_491 = F_196 ( & V_487 [ 16 ] ) ;
V_492 = F_196 ( & V_487 [ 24 ] ) ;
V_487 [ 0 ] = type ;
V_487 [ 1 ] = ( V_488 << 4 ) | V_489 | V_490 ;
F_143 ( V_448 , & V_487 [ 8 ] ) ;
F_143 ( V_491 , & V_487 [ 16 ] ) ;
F_143 ( V_492 , & V_487 [ 24 ] ) ;
F_185 ( V_480 + 64 > V_476 . V_486 ) ;
V_480 += 64 ;
V_477 += 64 ;
}
}
F_197 ( & V_476 ) ;
F_198 ( V_16 ) ;
F_122 ( V_152 ) ;
}
static unsigned int F_199 ( struct V_151 * V_152 )
{
struct V_74 * V_75 = & V_152 -> V_75 ;
struct V_63 * V_162 = V_152 -> V_155 ;
const T_3 * V_240 = V_162 -> V_241 ;
T_5 V_276 , V_242 = ( T_5 ) - 1 ;
T_3 V_493 , V_494 , V_243 = 0xff ;
T_4 V_210 ;
T_8 V_269 ;
if ( F_20 ( V_162 -> V_244 < 16 ) ) {
F_74 ( V_152 -> V_13 , L_50 ,
V_162 -> V_244 ) ;
V_242 = 15 ;
goto V_245;
}
F_110 ( V_240 , & V_210 , & V_269 ) ;
if ( V_269 != F_64 ( V_162 ) ) {
F_74 ( V_152 -> V_13 , L_51 ,
V_269 , F_64 ( V_162 ) ) ;
goto V_451;
}
V_493 = V_240 [ 1 ] & 0x1f ;
if ( V_493 != V_495 ) {
F_74 ( V_152 -> V_13 , L_52 , V_493 ) ;
V_242 = 1 ;
goto V_245;
}
if ( ( V_269 / 512 ) > 0xffff || V_269 < 512 || ( V_269 % 512 ) ) {
F_74 ( V_152 -> V_13 , L_53 , V_269 ) ;
goto V_451;
}
V_276 = V_269 / 512 ;
V_494 = V_240 [ 14 ] & 0xbf ;
if ( F_102 ( V_152 -> V_13 ) &&
F_200 ( V_152 -> V_13 ) ) {
V_75 -> V_248 = V_398 ;
V_75 -> V_167 = V_496 ;
V_75 -> V_206 = V_497 & 0x1f ;
V_75 -> V_201 = V_152 -> V_154 << 3 ;
V_75 -> V_169 = V_276 & 0xff ;
V_75 -> V_403 = ( V_276 >> 8 ) & 0xff ;
V_75 -> V_404 = V_498 | ( V_494 << 8 ) ;
} else {
V_75 -> V_167 = V_499 ;
V_75 -> V_169 = V_498 ;
V_75 -> V_248 = V_396 ;
V_75 -> V_403 = V_494 ;
V_75 -> V_206 = ( V_276 >> 8 ) & 0xff ;
V_75 -> V_201 = V_276 & 0xff ;
}
V_75 -> V_1 = V_252 ;
V_75 -> V_204 = ( V_210 >> 16 ) & 0xff ;
V_75 -> V_203 = ( V_210 >> 8 ) & 0xff ;
V_75 -> V_202 = V_210 & 0xff ;
V_75 -> V_209 = ( V_210 >> 40 ) & 0xff ;
V_75 -> V_208 = ( V_210 >> 32 ) & 0xff ;
V_75 -> V_207 = ( V_210 >> 24 ) & 0xff ;
V_75 -> V_16 |= V_247 | V_246 | V_205 ;
V_152 -> V_16 |= V_437 ;
F_63 ( V_152 ) ;
V_152 -> V_301 = F_190 ;
return 0 ;
V_245:
F_31 ( V_152 -> V_13 , V_162 , V_242 , V_243 ) ;
return 1 ;
V_451:
F_26 ( V_152 -> V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
}
static unsigned int F_201 ( struct V_151 * V_152 )
{
struct V_74 * V_75 = & V_152 -> V_75 ;
struct V_63 * V_162 = V_152 -> V_155 ;
struct V_12 * V_13 = V_152 -> V_13 ;
const T_3 * V_240 = V_162 -> V_241 ;
T_3 V_500 , V_493 ;
T_4 V_210 ;
T_8 V_269 ;
T_5 V_242 = ( T_5 ) - 1 ;
if ( F_20 ( V_162 -> V_244 < 16 ) ) {
V_242 = 15 ;
goto V_245;
}
V_493 = V_240 [ 1 ] & 0x1f ;
if ( ( V_493 != V_501 ) && ( V_493 != V_502 ) &&
( V_493 != V_503 ) && ( V_493 != V_504 ) ) {
V_242 = 1 ;
goto V_245;
}
F_110 ( V_240 , & V_210 , & V_269 ) ;
if ( V_269 ) {
goto V_451;
}
if ( V_210 > V_13 -> V_100 )
goto V_273;
V_500 = V_240 [ 14 ] & 0x1 ;
if ( F_102 ( V_152 -> V_13 ) &&
F_202 ( V_152 -> V_13 ) ) {
V_75 -> V_248 = V_402 ;
V_75 -> V_167 = V_505 ;
V_75 -> V_169 = V_506 ;
V_75 -> V_201 = V_152 -> V_154 << 3 ;
V_75 -> V_404 = V_493 | ( ( T_5 ) V_500 << 8 ) ;
} else {
V_75 -> V_248 = V_249 ;
V_75 -> V_167 = V_507 ;
V_75 -> V_169 = V_493 ;
V_75 -> V_403 = V_500 ;
}
V_75 -> V_204 = ( V_210 >> 16 ) & 0xff ;
V_75 -> V_203 = ( V_210 >> 8 ) & 0xff ;
V_75 -> V_202 = V_210 & 0xff ;
V_75 -> V_209 = ( V_210 >> 40 ) & 0xff ;
V_75 -> V_208 = ( V_210 >> 32 ) & 0xff ;
V_75 -> V_207 = ( V_210 >> 24 ) & 0xff ;
V_75 -> V_1 = V_252 ;
V_75 -> V_16 |= V_247 | V_246 | V_205 ;
return 0 ;
V_245:
F_31 ( V_152 -> V_13 , V_162 , V_242 , 0xff ) ;
return 1 ;
V_273:
F_26 ( V_152 -> V_13 , V_162 , V_81 , 0x21 , 0x00 ) ;
return 1 ;
V_451:
F_26 ( V_152 -> V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
}
static int F_203 ( struct V_151 * V_152 ,
const T_3 * V_4 , int V_45 , T_5 * V_242 )
{
struct V_74 * V_75 = & V_152 -> V_75 ;
struct V_12 * V_13 = V_152 -> V_13 ;
T_3 V_508 [ V_509 ] ;
T_3 V_510 ;
int V_187 ;
if ( V_45 != V_509 - 2 ) {
if ( V_45 < V_509 - 2 )
* V_242 = V_45 ;
else
* V_242 = V_509 - 2 ;
return - V_20 ;
}
V_510 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_151 ( V_13 -> V_107 , V_508 , false ) ;
for ( V_187 = 0 ; V_187 < V_509 - 2 ; V_187 ++ ) {
if ( V_187 == 0 )
continue;
if ( V_508 [ V_187 + 2 ] != V_4 [ V_187 ] ) {
* V_242 = V_187 ;
return - V_20 ;
}
}
V_75 -> V_16 |= V_246 | V_247 ;
V_75 -> V_248 = V_249 ;
V_75 -> V_201 = 0 ;
V_75 -> V_167 = V_440 ;
V_75 -> V_169 = V_510 ? V_511 : V_512 ;
return 0 ;
}
static int F_204 ( struct V_151 * V_152 ,
const T_3 * V_4 , int V_45 , T_5 * V_242 )
{
struct V_12 * V_13 = V_152 -> V_13 ;
T_3 V_508 [ V_513 ] ;
T_3 V_68 ;
int V_187 ;
if ( V_45 != V_513 - 2 ) {
if ( V_45 < V_513 - 2 )
* V_242 = V_45 ;
else
* V_242 = V_513 - 2 ;
return - V_20 ;
}
V_68 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_154 ( V_13 , V_508 , false ) ;
for ( V_187 = 0 ; V_187 < V_513 - 2 ; V_187 ++ ) {
if ( V_187 == 0 )
continue;
if ( V_508 [ 2 + V_187 ] != V_4 [ V_187 ] ) {
* V_242 = V_187 ;
return - V_20 ;
}
}
if ( V_68 & ( 1 << 2 ) )
V_13 -> V_16 |= V_69 ;
else
V_13 -> V_16 &= ~ V_69 ;
return 0 ;
}
static unsigned int F_205 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
const T_3 * V_240 = V_162 -> V_241 ;
const T_3 * V_350 ;
T_3 V_352 , V_353 ;
unsigned V_356 , V_514 , V_515 , V_516 ;
int V_45 ;
T_5 V_242 = ( T_5 ) - 1 ;
T_3 V_243 = 0xff ;
F_108 ( L_31 ) ;
V_356 = ( V_240 [ 0 ] == V_468 ) ;
if ( V_356 ) {
if ( V_162 -> V_244 < 5 ) {
V_242 = 4 ;
goto V_245;
}
V_45 = V_240 [ 4 ] ;
V_515 = 4 ;
} else {
if ( V_162 -> V_244 < 9 ) {
V_242 = 8 ;
goto V_245;
}
V_45 = ( V_240 [ 7 ] << 8 ) + V_240 [ 8 ] ;
V_515 = 8 ;
}
if ( ( V_240 [ 1 ] & 0x11 ) != 0x10 ) {
V_242 = 1 ;
V_243 = ( V_240 [ 1 ] & 0x01 ) ? 1 : 5 ;
goto V_245;
}
if ( ! F_62 ( V_162 ) || F_61 ( V_162 ) -> V_486 < V_45 )
goto V_451;
V_350 = F_206 ( F_207 ( F_61 ( V_162 ) ) ) ;
if ( V_45 < V_515 )
goto V_451;
if ( V_356 )
V_516 = V_350 [ 3 ] ;
else
V_516 = ( V_350 [ 6 ] << 8 ) + V_350 [ 7 ] ;
V_45 -= V_515 ;
V_350 += V_515 ;
if ( V_45 < V_516 )
goto V_451;
if ( V_516 != 0 && V_516 != 8 ) {
V_242 = ( V_356 ) ? 3 : 6 ;
V_242 += V_516 + V_515 ;
goto V_517;
}
V_45 -= V_516 ;
V_350 += V_516 ;
if ( V_45 == 0 )
goto V_257;
V_352 = V_350 [ 0 ] & 0x3f ;
if ( V_350 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_451;
V_353 = V_350 [ 1 ] ;
V_514 = ( V_350 [ 2 ] << 8 ) | V_350 [ 3 ] ;
V_350 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_451;
V_353 = 0 ;
V_514 = V_350 [ 1 ] ;
V_350 += 2 ;
V_45 -= 2 ;
}
if ( V_353 && ( V_353 != V_360 ) ) {
V_242 = ( V_350 [ 0 ] & 0x40 ) ? 1 : 0 ;
V_242 += V_515 + V_516 ;
goto V_517;
}
if ( V_514 > V_45 )
goto V_451;
switch ( V_352 ) {
case V_362 :
if ( F_203 ( V_152 , V_350 , V_514 , & V_242 ) < 0 ) {
V_242 += V_515 + V_516 ;
goto V_517;
}
break;
case V_363 :
if ( F_204 ( V_152 , V_350 , V_514 , & V_242 ) < 0 ) {
V_242 += V_515 + V_516 ;
goto V_517;
} else {
goto V_257;
}
break;
default:
V_242 = V_516 + V_515 ;
goto V_517;
}
if ( V_45 > V_514 )
goto V_517;
return 0 ;
V_245:
F_31 ( V_152 -> V_13 , V_162 , V_242 , V_243 ) ;
return 1 ;
V_517:
F_33 ( V_152 -> V_13 , V_162 , V_242 ) ;
return 1 ;
V_451:
F_26 ( V_152 -> V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
V_257:
V_162 -> V_70 = V_260 ;
return 1 ;
}
static T_3 F_208 ( T_8 V_45 , bool V_518 , bool V_519 )
{
if ( V_45 == 0 )
return V_520 ;
else if ( V_518 )
return V_519 ? V_521 : V_522 ;
else
return V_519 ? V_523 : V_524 ;
}
static unsigned int F_209 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
const T_3 * V_240 = V_162 -> V_241 ;
struct V_74 * V_75 = & V_152 -> V_75 ;
T_3 V_525 = V_240 [ 1 ] ;
bool V_518 = ( V_240 [ 0 ] == V_474 ) ;
T_5 V_526 = F_210 ( & V_240 [ 2 ] ) ;
T_8 V_45 = F_182 ( & V_240 [ 6 ] ) ;
bool V_519 = ! ( V_152 -> V_13 -> V_16 & V_365 ) ;
if ( V_525 == 0xef ) {
F_31 ( V_152 -> V_13 , V_162 , 1 , 0 ) ;
return 1 ;
}
if ( V_240 [ 4 ] & 7 ) {
if ( V_45 > 0xffff ) {
F_31 ( V_152 -> V_13 , V_162 , 6 , 0 ) ;
return 1 ;
}
} else {
if ( V_45 > 0x01fffe00 ) {
F_31 ( V_152 -> V_13 , V_162 , 6 , 0 ) ;
return 1 ;
}
V_45 = ( V_45 + 511 ) / 512 ;
}
V_75 -> V_248 = V_519 ? V_396 : V_397 ;
V_75 -> V_16 |= V_246 | V_247 | V_251 ;
if ( V_518 )
V_75 -> V_16 |= V_286 ;
V_75 -> V_167 = F_208 ( V_45 , V_518 , V_519 ) ;
V_75 -> V_169 = V_525 ;
V_75 -> V_203 = V_526 & 0xff ;
V_75 -> V_204 = V_526 >> 8 ;
if ( V_45 ) {
V_75 -> V_201 = V_45 & 0xff ;
V_75 -> V_202 = V_45 >> 8 ;
} else {
if ( ! V_518 )
V_75 -> V_204 = ( 1 << 7 ) ;
}
F_63 ( V_152 ) ;
return 0 ;
}
static unsigned int F_211 ( struct V_151 * V_152 )
{
struct V_63 * V_162 = V_152 -> V_155 ;
const T_3 * V_240 = V_162 -> V_241 ;
const T_5 V_493 = F_210 ( & V_240 [ 8 ] ) ;
if ( V_493 == V_527 )
return F_180 ( V_152 ) ;
return 1 ;
}
static inline T_9 F_212 ( struct V_12 * V_13 , T_3 V_64 )
{
switch ( V_64 ) {
case V_289 :
case V_287 :
case V_290 :
case V_284 :
case V_283 :
case V_285 :
return F_115 ;
case V_528 :
return F_187 ;
case V_461 :
if ( F_213 ( V_13 ) )
return F_106 ;
break;
case V_270 :
case V_271 :
return F_111 ;
case V_293 :
case V_133 :
return F_180 ;
case V_401 :
return F_211 ;
case V_468 :
case V_469 :
return F_205 ;
break;
case V_471 :
return F_199 ;
case V_472 :
return F_201 ;
case V_473 :
case V_474 :
if ( ! ( V_13 -> V_16 & V_233 ) )
break;
return F_209 ;
case V_470 :
return F_104 ;
}
return NULL ;
}
static inline void F_214 ( struct V_8 * V_9 ,
struct V_63 * V_64 )
{
#ifdef F_215
struct V_28 * V_116 = V_64 -> V_1 ;
F_114 ( L_54 ,
V_9 -> V_200 ,
V_116 -> V_393 , V_116 -> V_107 , V_116 -> V_394 ,
V_64 -> V_241 ) ;
#endif
}
static inline int F_216 ( struct V_63 * V_162 ,
struct V_12 * V_13 )
{
T_3 V_529 = V_162 -> V_241 [ 0 ] ;
T_9 V_295 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 || V_13 -> V_49 == V_51 ) {
if ( F_20 ( ! V_162 -> V_244 || V_162 -> V_244 > V_13 -> V_377 ) )
goto V_530;
V_295 = F_212 ( V_13 , V_529 ) ;
} else {
if ( F_20 ( ! V_162 -> V_244 ) )
goto V_530;
V_295 = NULL ;
if ( F_77 ( ( V_529 != V_133 ) || ! V_531 ) ) {
int V_45 = F_217 ( V_529 ) ;
if ( F_20 ( V_45 > V_162 -> V_244 || V_45 > V_13 -> V_377 ) )
goto V_530;
V_295 = F_173 ;
} else {
if ( F_20 ( V_162 -> V_244 > 16 ) )
goto V_530;
V_295 = F_212 ( V_13 , V_529 ) ;
}
}
if ( V_295 )
V_33 = F_123 ( V_13 , V_162 , V_295 ) ;
else
F_218 ( V_13 , V_162 ) ;
return V_33 ;
V_530:
F_114 ( L_55 ,
V_162 -> V_244 , V_529 , V_13 -> V_377 ) ;
V_162 -> V_70 = V_305 << 16 ;
V_162 -> V_157 ( V_162 ) ;
return 0 ;
}
int F_219 ( struct V_6 * V_7 , struct V_63 * V_64 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_116 = V_64 -> V_1 ;
int V_33 = 0 ;
unsigned long V_532 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_532 ) ;
F_214 ( V_9 , V_64 ) ;
V_13 = F_14 ( V_9 , V_116 ) ;
if ( F_77 ( V_13 ) )
V_33 = F_216 ( V_64 , V_13 ) ;
else {
V_64 -> V_70 = ( V_533 << 16 ) ;
V_64 -> V_157 ( V_64 ) ;
}
F_9 ( V_9 -> V_21 , V_532 ) ;
return V_33 ;
}
void F_218 ( struct V_12 * V_13 , struct V_63 * V_64 )
{
struct V_314 args ;
const T_3 * V_155 = V_64 -> V_241 ;
T_3 V_534 ;
args . V_13 = V_13 ;
args . V_107 = V_13 -> V_107 ;
args . V_64 = V_64 ;
switch( V_155 [ 0 ] ) {
case V_385 :
if ( V_155 [ 1 ] & 2 )
F_31 ( V_13 , V_64 , 1 , 0xff ) ;
else if ( ( V_155 [ 1 ] & 1 ) == 0 )
F_220 ( & args , F_130 ) ;
else switch ( V_155 [ 2 ] ) {
case 0x00 :
F_220 ( & args , F_133 ) ;
break;
case 0x80 :
F_220 ( & args , F_134 ) ;
break;
case 0x83 :
F_220 ( & args , F_135 ) ;
break;
case 0x89 :
F_220 ( & args , F_137 ) ;
break;
case 0xb0 :
F_220 ( & args , F_139 ) ;
break;
case 0xb1 :
F_220 ( & args , F_145 ) ;
break;
case 0xb2 :
F_220 ( & args , F_148 ) ;
break;
case 0xb6 :
if ( V_13 -> V_16 & V_324 ) {
F_220 ( & args , F_149 ) ;
break;
}
default:
F_31 ( V_13 , V_64 , 2 , 0xff ) ;
break;
}
break;
case V_358 :
case V_458 :
F_220 ( & args , F_159 ) ;
break;
case V_371 :
F_220 ( & args , F_160 ) ;
break;
case V_459 :
if ( ( V_155 [ 1 ] & 0x1f ) == V_535 )
F_220 ( & args , F_160 ) ;
else
F_31 ( V_13 , V_64 , 1 , 0xff ) ;
break;
case V_460 :
F_220 ( & args , F_164 ) ;
break;
case V_378 :
F_26 ( V_13 , V_64 , 0 , 0 , 0 ) ;
V_64 -> V_70 = ( V_71 << 24 ) ;
break;
case V_461 :
case V_462 :
case V_463 :
case V_464 :
case V_465 :
break;
case V_466 :
V_534 = V_155 [ 1 ] & ~ ( 1 << 3 ) ;
if ( V_534 != 0x4 || V_155 [ 3 ] || V_155 [ 4 ] )
F_31 ( V_13 , V_64 , 1 , 0xff ) ;
break;
case V_467 :
if ( V_155 [ 1 ] == V_536 )
F_220 ( & args , F_189 ) ;
else
F_31 ( V_13 , V_64 , 1 , 0xff ) ;
break;
default:
F_26 ( V_13 , V_64 , V_81 , 0x20 , 0x0 ) ;
break;
}
V_64 -> V_157 ( V_64 ) ;
}
int F_221 ( struct V_537 * V_34 , struct V_538 * V_539 )
{
int V_187 , V_33 ;
for ( V_187 = 0 ; V_187 < V_34 -> V_540 ; V_187 ++ ) {
struct V_8 * V_9 = V_34 -> V_541 [ V_187 ] ;
struct V_6 * V_7 ;
V_33 = - V_128 ;
V_7 = F_222 ( V_539 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_542;
V_7 -> V_543 = 1 ;
* (struct V_8 * * ) & V_7 -> V_544 [ 0 ] = V_9 ;
V_9 -> V_545 = V_7 ;
V_7 -> V_546 = V_547 ;
V_7 -> V_548 = V_9 -> V_200 ;
V_7 -> V_549 = 16 ;
V_7 -> V_550 = 1 ;
V_7 -> V_551 = 1 ;
V_7 -> V_552 = 32 ;
V_7 -> V_553 = 1 ;
V_33 = F_223 ( V_9 -> V_545 ,
& V_9 -> V_554 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_555;
}
return 0 ;
V_555:
F_224 ( V_34 -> V_541 [ V_187 ] -> V_545 ) ;
V_542:
while ( -- V_187 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_541 [ V_187 ] -> V_545 ;
F_225 ( V_7 ) ;
F_224 ( V_7 ) ;
}
return V_33 ;
}
void F_226 ( struct V_8 * V_9 , int V_556 )
{
int V_557 = 5 ;
struct V_12 * V_558 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_559:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_393 = 0 , V_107 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_227 ( V_11 ) )
V_107 = V_13 -> V_43 ;
else
V_393 = V_11 -> V_560 ;
V_29 = F_228 ( V_9 -> V_545 , V_393 , V_107 , 0 ,
NULL ) ;
if ( ! F_229 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_230 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_561;
}
}
V_561:
if ( ! V_11 )
return;
if ( V_556 ) {
if ( V_13 != V_558 ) {
F_231 ( 100 ) ;
V_558 = V_13 ;
goto V_559;
}
if ( -- V_557 ) {
F_231 ( 100 ) ;
goto V_559;
}
F_232 ( V_9 ,
L_56 ) ;
}
F_233 ( V_562 , & V_9 -> V_563 ,
F_234 ( V_135 ) ) ;
}
int F_235 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_236 ( V_13 -> V_29 , V_564 ) ;
return 1 ;
}
return 0 ;
}
static void F_237 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_238 ( & V_9 -> V_545 -> V_565 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_239 ( V_29 ) == 0 ) {
F_236 ( V_29 , V_564 ) ;
} else {
F_185 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_240 ( & V_9 -> V_545 -> V_565 ) ;
if ( V_29 ) {
F_163 ( V_13 , L_57 ,
F_241 ( & V_29 -> V_566 ) ) ;
F_242 ( V_29 ) ;
F_230 ( V_29 ) ;
}
}
static void F_243 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_567 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_567 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_244 ( V_13 ) )
F_245 ( V_13 ) ;
F_237 ( V_13 ) ;
}
}
void F_246 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_247 ( V_13 -> V_29 , V_227 ,
V_568 ) ;
}
void F_248 ( struct V_569 * V_570 )
{
struct V_8 * V_9 =
F_249 ( V_570 , struct V_8 , V_563 . V_570 ) ;
int V_187 ;
if ( V_9 -> V_39 & V_571 ) {
F_114 ( L_58 ) ;
return;
}
#ifdef F_250
while ( V_572 )
F_231 ( 10 ) ;
#endif
F_114 ( L_31 ) ;
F_238 ( & V_9 -> V_573 ) ;
F_243 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_392 )
for ( V_187 = 0 ; V_187 < V_574 ; V_187 ++ )
F_243 ( & V_9 -> V_392 [ V_187 ] ) ;
F_226 ( V_9 , 0 ) ;
F_240 ( & V_9 -> V_573 ) ;
F_114 ( L_33 ) ;
}
int F_251 ( struct V_6 * V_7 , unsigned int V_393 ,
unsigned int V_107 , T_4 V_394 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_82 -> V_198 )
return - V_24 ;
if ( V_394 != V_575 && V_394 )
return - V_20 ;
if ( ! F_177 ( V_9 ) ) {
if ( V_393 != V_575 && V_393 )
return - V_20 ;
V_43 = V_107 ;
} else {
if ( V_107 != V_575 && V_107 )
return - V_20 ;
V_43 = V_393 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_575 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_576 * V_577 = & V_11 -> V_52 ;
V_577 -> V_578 |= V_579 ;
V_577 -> V_58 |= V_103 ;
}
} else {
struct V_12 * V_13 = F_176 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_576 * V_577 = & V_13 -> V_11 -> V_52 ;
V_577 -> V_578 |= 1 << V_13 -> V_43 ;
V_577 -> V_58 |= V_103 ;
} else
V_33 = - V_20 ;
}
if ( V_33 == 0 ) {
F_8 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_25 ( V_9 ) ;
} else
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
}
void F_252 ( struct V_569 * V_570 )
{
struct V_8 * V_9 =
F_249 ( V_570 , struct V_8 , V_580 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_238 ( & V_9 -> V_573 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_239 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_253 ( & ( V_29 -> V_566 ) ) ;
F_230 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_240 ( & V_9 -> V_573 ) ;
}
struct V_8 * F_254 ( struct V_537 * V_34 ,
struct V_581 * V_582 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_255 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_583 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_584 = V_582 -> V_584 ;
V_9 -> V_585 = V_582 -> V_585 ;
V_9 -> V_586 = V_582 -> V_586 ;
V_9 -> V_16 |= V_582 -> V_16 ;
V_9 -> V_82 = V_582 -> V_587 ;
V_9 -> V_588 = V_589 ;
return V_9 ;
}
int F_256 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_82 -> V_198 )
V_9 -> V_39 &= ~ V_590 ;
return 0 ;
}
void F_257 ( struct V_8 * V_9 )
{
}
void F_258 ( struct V_8 * V_9 )
{
F_259 ( V_9 ) ;
}
int F_260 ( struct V_8 * V_9 )
{
return F_261 ( V_9 ) ;
}
int F_262 ( struct V_8 * V_9 )
{
int V_33 = V_9 -> V_82 -> V_591 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_200 = F_263 ( & V_592 ) ;
return 0 ;
}
void F_264 ( struct V_8 * V_9 )
{
if ( V_9 -> V_82 -> V_593 )
V_9 -> V_82 -> V_593 ( V_9 ) ;
F_52 ( V_9 ) ;
}
int F_265 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_75 ( V_29 ) ;
F_84 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_266 ( struct V_63 * V_64 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_214 ( V_9 , V_64 ) ;
if ( F_77 ( F_101 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_216 ( V_64 , V_9 -> V_11 . V_1 ) ;
else {
V_64 -> V_70 = ( V_533 << 16 ) ;
V_64 -> V_157 ( V_64 ) ;
}
return V_33 ;
}
int F_267 ( struct V_8 * V_9 )
{
unsigned int V_594 = V_9 -> V_34 -> V_595 ;
unsigned int V_187 , V_154 ;
for ( V_187 = 0 , V_154 = V_9 -> V_596 + 1 ; V_187 < V_594 ; V_187 ++ , V_154 ++ ) {
V_154 = V_154 < V_594 ? V_154 : 0 ;
if ( V_154 == V_597 )
continue;
if ( ! F_268 ( V_154 , & V_9 -> V_598 ) ) {
V_9 -> V_596 = V_154 ;
return V_154 ;
}
}
return - 1 ;
}
void F_269 ( unsigned int V_154 , struct V_8 * V_9 )
{
F_270 ( V_154 , & V_9 -> V_598 ) ;
}
