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
static void F_40 ( struct V_12 * V_13 ,
struct V_63 * V_64 , T_5 V_79 )
{
F_31 ( V_13 , V_64 , V_79 , 0xff ) ;
V_64 -> V_96 ( V_64 ) ;
}
int F_41 ( struct V_28 * V_29 , struct V_97 * V_98 ,
T_6 V_99 , int V_100 [] )
{
V_100 [ 0 ] = 255 ;
V_100 [ 1 ] = 63 ;
F_42 ( V_99 , 255 * 63 ) ;
V_100 [ 2 ] = V_99 ;
return 0 ;
}
void F_43 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_101 < V_13 -> V_102 ) {
V_13 -> V_16 |= V_103 ;
V_13 -> V_11 -> V_52 . V_58 |= V_104 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_25 ( V_9 ) ;
}
static int F_44 ( struct V_8 * V_9 , struct V_28 * V_29 ,
void T_7 * V_105 )
{
struct V_12 * V_13 = F_14 ( V_9 , V_29 ) ;
T_5 T_7 * V_106 = V_105 ;
char V_4 [ 40 ] ;
if ( ! V_13 )
return - V_107 ;
if ( F_45 ( V_106 , V_13 -> V_108 , V_109 * sizeof( T_5 ) ) )
return - V_110 ;
F_46 ( V_13 -> V_108 , V_4 , V_111 , V_112 ) ;
if ( F_45 ( V_106 + V_111 , V_4 , V_112 ) )
return - V_110 ;
F_46 ( V_13 -> V_108 , V_4 , V_113 , V_114 ) ;
if ( F_45 ( V_106 + V_113 , V_4 , V_114 ) )
return - V_110 ;
F_46 ( V_13 -> V_108 , V_4 , V_115 , V_116 ) ;
if ( F_45 ( V_106 + V_115 , V_4 , V_116 ) )
return - V_110 ;
return 0 ;
}
int F_47 ( struct V_28 * V_117 , void T_7 * V_105 )
{
int V_33 = 0 ;
T_3 V_118 [ V_119 ] ;
T_3 args [ 4 ] , * V_120 = NULL , * V_121 = NULL ;
int V_122 = 0 ;
enum V_123 V_124 ;
int V_125 ;
if ( V_105 == NULL )
return - V_20 ;
if ( F_48 ( args , V_105 , sizeof( args ) ) )
return - V_110 ;
V_121 = F_49 ( V_78 , V_126 ) ;
if ( ! V_121 )
return - V_127 ;
memset ( V_118 , 0 , sizeof( V_118 ) ) ;
if ( args [ 3 ] ) {
V_122 = V_128 * args [ 3 ] ;
V_120 = F_50 ( V_122 , V_129 ) ;
if ( V_120 == NULL ) {
V_33 = - V_127 ;
goto error;
}
V_118 [ 1 ] = ( 4 << 1 ) ;
V_118 [ 2 ] = 0x0e ;
V_124 = V_130 ;
} else {
V_118 [ 1 ] = ( 3 << 1 ) ;
V_118 [ 2 ] = 0x20 ;
V_124 = V_131 ;
}
V_118 [ 0 ] = V_132 ;
V_118 [ 4 ] = args [ 2 ] ;
if ( args [ 0 ] == V_133 ) {
V_118 [ 6 ] = args [ 3 ] ;
V_118 [ 8 ] = args [ 1 ] ;
V_118 [ 10 ] = 0x4f ;
V_118 [ 12 ] = 0xc2 ;
} else {
V_118 [ 6 ] = args [ 1 ] ;
}
V_118 [ 14 ] = args [ 0 ] ;
V_125 = F_51 ( V_117 , V_118 , V_124 , V_120 , V_122 ,
V_121 , ( 10 * V_134 ) , 5 , 0 , NULL ) ;
if ( F_52 ( V_125 ) == V_71 ) {
T_3 * V_135 = V_121 + 8 ;
V_125 &= ~ ( 0xFF << 24 ) ;
if ( V_125 & V_72 ) {
struct V_136 V_137 ;
F_53 ( V_121 , V_78 ,
& V_137 ) ;
if ( V_137 . V_138 == V_139 &&
V_137 . V_66 == 0 && V_137 . V_67 == 0x1d )
V_125 &= ~ V_72 ;
}
if ( V_121 [ 0 ] == 0x72 &&
V_135 [ 0 ] == 0x09 ) {
args [ 0 ] = V_135 [ 13 ] ;
args [ 1 ] = V_135 [ 3 ] ;
args [ 2 ] = V_135 [ 5 ] ;
if ( F_45 ( V_105 , args , sizeof( args ) ) )
V_33 = - V_110 ;
}
}
if ( V_125 ) {
V_33 = - V_62 ;
goto error;
}
if ( ( V_120 )
&& F_45 ( V_105 + sizeof( args ) , V_120 , V_122 ) )
V_33 = - V_110 ;
error:
F_54 ( V_121 ) ;
F_54 ( V_120 ) ;
return V_33 ;
}
int F_55 ( struct V_28 * V_117 , void T_7 * V_105 )
{
int V_33 = 0 ;
T_3 V_118 [ V_119 ] ;
T_3 args [ 7 ] , * V_121 = NULL ;
int V_125 ;
if ( V_105 == NULL )
return - V_20 ;
if ( F_48 ( args , V_105 , sizeof( args ) ) )
return - V_110 ;
V_121 = F_49 ( V_78 , V_126 ) ;
if ( ! V_121 )
return - V_127 ;
memset ( V_118 , 0 , sizeof( V_118 ) ) ;
V_118 [ 0 ] = V_132 ;
V_118 [ 1 ] = ( 3 << 1 ) ;
V_118 [ 2 ] = 0x20 ;
V_118 [ 4 ] = args [ 1 ] ;
V_118 [ 6 ] = args [ 2 ] ;
V_118 [ 8 ] = args [ 3 ] ;
V_118 [ 10 ] = args [ 4 ] ;
V_118 [ 12 ] = args [ 5 ] ;
V_118 [ 13 ] = args [ 6 ] & 0x4f ;
V_118 [ 14 ] = args [ 0 ] ;
V_125 = F_51 ( V_117 , V_118 , V_131 , NULL , 0 ,
V_121 , ( 10 * V_134 ) , 5 , 0 , NULL ) ;
if ( F_52 ( V_125 ) == V_71 ) {
T_3 * V_135 = V_121 + 8 ;
V_125 &= ~ ( 0xFF << 24 ) ;
if ( V_125 & V_72 ) {
struct V_136 V_137 ;
F_53 ( V_121 , V_78 ,
& V_137 ) ;
if ( V_137 . V_138 == V_139 &&
V_137 . V_66 == 0 && V_137 . V_67 == 0x1d )
V_125 &= ~ V_72 ;
}
if ( V_121 [ 0 ] == 0x72 &&
V_135 [ 0 ] == 0x09 ) {
args [ 0 ] = V_135 [ 13 ] ;
args [ 1 ] = V_135 [ 3 ] ;
args [ 2 ] = V_135 [ 5 ] ;
args [ 3 ] = V_135 [ 7 ] ;
args [ 4 ] = V_135 [ 9 ] ;
args [ 5 ] = V_135 [ 11 ] ;
args [ 6 ] = V_135 [ 12 ] ;
if ( F_45 ( V_105 , args , sizeof( args ) ) )
V_33 = - V_110 ;
}
}
if ( V_125 ) {
V_33 = - V_62 ;
goto error;
}
error:
F_54 ( V_121 ) ;
return V_33 ;
}
static int F_56 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 & V_140 )
return 1 ;
if ( V_9 -> V_39 & V_141 )
return 1 ;
return 0 ;
}
int F_57 ( struct V_8 * V_9 , struct V_28 * V_117 ,
int V_64 , void T_7 * V_105 )
{
unsigned long V_91 ;
int V_33 = - V_20 ;
unsigned long V_16 ;
switch ( V_64 ) {
case V_142 :
F_5 ( V_9 -> V_21 , V_16 ) ;
V_91 = F_56 ( V_9 ) ;
F_9 ( V_9 -> V_21 , V_16 ) ;
return F_58 ( V_91 , ( unsigned long T_7 * ) V_105 ) ;
case V_143 :
V_91 = ( unsigned long ) V_105 ;
V_33 = 0 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_9 -> V_39 & V_144 ) {
if ( V_91 )
V_9 -> V_39 |= V_141 ;
else
V_9 -> V_39 &= ~ V_141 ;
} else {
if ( V_91 != F_56 ( V_9 ) )
V_33 = - V_20 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
return V_33 ;
case V_145 :
return F_44 ( V_9 , V_117 , V_105 ) ;
case V_146 :
if ( ! F_59 ( V_147 ) || ! F_59 ( V_148 ) )
return - V_149 ;
return F_47 ( V_117 , V_105 ) ;
case V_150 :
if ( ! F_59 ( V_147 ) || ! F_59 ( V_148 ) )
return - V_149 ;
return F_55 ( V_117 , V_105 ) ;
default:
V_33 = - V_151 ;
break;
}
return V_33 ;
}
int F_60 ( struct V_28 * V_117 , int V_64 , void T_7 * V_105 )
{
return F_57 ( F_3 ( V_117 -> V_34 ) ,
V_117 , V_64 , V_105 ) ;
}
static struct V_152 * F_61 ( struct V_12 * V_13 ,
struct V_63 * V_64 )
{
struct V_152 * V_153 ;
V_153 = F_62 ( V_13 , V_64 -> V_154 -> V_155 ) ;
if ( V_153 ) {
V_153 -> V_156 = V_64 ;
V_153 -> V_157 = V_64 -> V_96 ;
V_153 -> V_158 = F_63 ( V_64 ) ;
V_153 -> V_159 = F_64 ( V_64 ) ;
} else {
V_64 -> V_70 = ( V_160 << 16 ) | ( V_161 << 1 ) ;
V_64 -> V_96 ( V_64 ) ;
}
return V_153 ;
}
static void F_65 ( struct V_152 * V_153 )
{
struct V_63 * V_162 = V_153 -> V_156 ;
V_153 -> V_163 = V_162 -> V_154 -> V_164 ;
V_153 -> V_165 = F_66 ( V_162 ) + V_153 -> V_163 ;
}
static void F_67 ( unsigned V_108 , struct V_74 * V_75 )
{
T_3 V_166 = V_75 -> V_167 , V_168 = V_75 -> V_169 ;
F_68 ( V_170 L_4 , V_108 , V_166 ) ;
if ( V_166 & V_171 ) {
F_68 ( L_5 ) ;
} else {
if ( V_166 & V_172 ) F_68 ( L_6 ) ;
if ( V_166 & V_173 ) F_68 ( L_7 ) ;
if ( V_166 & V_174 ) F_68 ( L_8 ) ;
if ( V_166 & V_175 ) F_68 ( L_9 ) ;
if ( V_166 & V_176 ) F_68 ( L_10 ) ;
if ( V_166 & V_177 ) F_68 ( L_11 ) ;
if ( V_166 & V_178 ) F_68 ( L_12 ) ;
F_68 ( L_13 ) ;
if ( V_168 ) {
F_68 ( V_170 L_14 , V_108 , V_168 ) ;
if ( V_168 & V_179 ) F_68 ( L_15 ) ;
if ( V_168 & V_180 ) {
if ( V_168 & V_179 )
F_68 ( L_16 ) ;
else F_68 ( L_17 ) ;
}
if ( V_168 & V_181 ) F_68 ( L_18 ) ;
if ( V_168 & V_182 ) F_68 ( L_19 ) ;
if ( V_168 & V_183 ) F_68 ( L_20 ) ;
if ( V_168 & V_184 ) F_68 ( L_21 ) ;
F_68 ( L_13 ) ;
}
}
}
static void F_69 ( unsigned V_108 , T_3 V_185 , T_3 V_186 , T_3 * V_65 ,
T_3 * V_66 , T_3 * V_67 , int V_187 )
{
int V_188 ;
static const unsigned char V_189 [] [ 4 ] = {
{ 0xd1 , V_190 , 0x00 , 0x00 } ,
{ 0xd0 , V_190 , 0x00 , 0x00 } ,
{ 0x61 , V_191 , 0x00 , 0x00 } ,
{ 0x84 , V_190 , 0x47 , 0x00 } ,
{ 0x37 , V_192 , 0x04 , 0x00 } ,
{ 0x09 , V_192 , 0x04 , 0x00 } ,
{ 0x01 , V_193 , 0x13 , 0x00 } ,
{ 0x02 , V_191 , 0x00 , 0x00 } ,
{ 0x08 , V_192 , 0x04 , 0x00 } ,
{ 0x10 , V_81 , 0x21 , 0x00 } ,
{ 0x20 , V_194 , 0x28 , 0x00 } ,
{ 0x40 , V_193 , 0x11 , 0x04 } ,
{ 0x80 , V_193 , 0x11 , 0x04 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
static const unsigned char V_195 [] [ 4 ] = {
{ 0x80 , V_190 , 0x47 , 0x00 } ,
{ 0x40 , V_81 , 0x21 , 0x04 } ,
{ 0x20 , V_191 , 0x44 , 0x00 } ,
{ 0x08 , V_190 , 0x47 , 0x00 } ,
{ 0x04 , V_139 , 0x11 , 0x00 } ,
{ 0xFF , 0xFF , 0xFF , 0xFF } ,
} ;
if ( V_185 & V_171 ) {
V_186 = 0 ;
}
if ( V_186 ) {
for ( V_188 = 0 ; V_189 [ V_188 ] [ 0 ] != 0xFF ; V_188 ++ ) {
if ( ( V_189 [ V_188 ] [ 0 ] & V_186 ) ==
V_189 [ V_188 ] [ 0 ] ) {
* V_65 = V_189 [ V_188 ] [ 1 ] ;
* V_66 = V_189 [ V_188 ] [ 2 ] ;
* V_67 = V_189 [ V_188 ] [ 3 ] ;
goto V_196;
}
}
}
for ( V_188 = 0 ; V_195 [ V_188 ] [ 0 ] != 0xFF ; V_188 ++ ) {
if ( V_195 [ V_188 ] [ 0 ] & V_185 ) {
* V_65 = V_195 [ V_188 ] [ 1 ] ;
* V_66 = V_195 [ V_188 ] [ 2 ] ;
* V_67 = V_195 [ V_188 ] [ 3 ] ;
goto V_196;
}
}
* V_65 = V_190 ;
* V_66 = 0x00 ;
* V_67 = 0x00 ;
V_196:
if ( V_187 )
F_68 ( V_197 L_22
L_23 ,
V_108 , V_185 , V_186 , * V_65 , * V_66 , * V_67 ) ;
return;
}
static void F_70 ( struct V_152 * V_153 )
{
struct V_63 * V_64 = V_153 -> V_156 ;
struct V_74 * V_75 = & V_153 -> V_198 ;
unsigned char * V_199 = V_64 -> V_73 ;
unsigned char * V_135 = V_199 + 8 ;
int V_187 = V_153 -> V_9 -> V_82 -> V_200 == NULL ;
T_3 V_138 , V_66 , V_67 ;
memset ( V_199 , 0 , V_78 ) ;
V_64 -> V_70 = ( V_71 << 24 ) | V_72 ;
if ( V_153 -> V_201 ||
V_75 -> V_167 & ( V_171 | V_173 | V_178 | V_175 ) ) {
F_69 ( V_153 -> V_9 -> V_202 , V_75 -> V_167 , V_75 -> V_169 ,
& V_138 , & V_66 , & V_67 , V_187 ) ;
F_26 ( V_153 -> V_13 , V_64 , V_138 , V_66 , V_67 ) ;
} else {
F_27 ( 1 , V_64 -> V_73 ,
V_139 , 0 , 0x1D ) ;
}
if ( ( V_64 -> V_73 [ 0 ] & 0x7f ) >= 0x72 ) {
T_3 V_45 ;
V_45 = V_199 [ 7 ] ;
V_135 = ( char * ) F_71 ( V_199 , V_45 + 8 , 9 ) ;
if ( ! V_135 ) {
if ( V_78 < V_45 + 14 )
return;
V_199 [ 7 ] = V_45 + 14 ;
V_135 = V_199 + 8 + V_45 ;
}
V_135 [ 0 ] = 9 ;
V_135 [ 1 ] = 12 ;
V_135 [ 2 ] = 0x00 ;
V_135 [ 3 ] = V_75 -> V_169 ;
V_135 [ 5 ] = V_75 -> V_203 ;
V_135 [ 7 ] = V_75 -> V_204 ;
V_135 [ 9 ] = V_75 -> V_205 ;
V_135 [ 11 ] = V_75 -> V_206 ;
V_135 [ 12 ] = V_75 -> V_1 ;
V_135 [ 13 ] = V_75 -> V_167 ;
if ( V_75 -> V_16 & V_207 ) {
V_135 [ 2 ] |= 0x01 ;
V_135 [ 4 ] = V_75 -> V_208 ;
V_135 [ 6 ] = V_75 -> V_209 ;
V_135 [ 8 ] = V_75 -> V_210 ;
V_135 [ 10 ] = V_75 -> V_211 ;
}
} else {
V_135 [ 0 ] = V_75 -> V_169 ;
V_135 [ 1 ] = V_75 -> V_167 ;
V_135 [ 2 ] = V_75 -> V_1 ;
V_135 [ 3 ] = V_75 -> V_203 ;
V_135 [ 7 ] = 0 ;
if ( V_75 -> V_16 & V_207 ) {
V_135 [ 8 ] |= 0x80 ;
if ( V_75 -> V_208 )
V_135 [ 8 ] |= 0x40 ;
if ( V_75 -> V_209 || V_75 -> V_210 || V_75 -> V_211 )
V_135 [ 8 ] |= 0x20 ;
}
V_135 [ 9 ] = V_75 -> V_204 ;
V_135 [ 10 ] = V_75 -> V_205 ;
V_135 [ 11 ] = V_75 -> V_206 ;
}
}
static void F_72 ( struct V_152 * V_153 )
{
struct V_12 * V_13 = V_153 -> V_13 ;
struct V_63 * V_64 = V_153 -> V_156 ;
struct V_74 * V_75 = & V_153 -> V_198 ;
unsigned char * V_199 = V_64 -> V_73 ;
int V_187 = V_153 -> V_9 -> V_82 -> V_200 == NULL ;
T_4 V_212 ;
T_3 V_138 , V_66 , V_67 ;
memset ( V_199 , 0 , V_78 ) ;
V_64 -> V_70 = ( V_71 << 24 ) | V_72 ;
if ( F_73 ( V_13 ) ) {
F_26 ( V_13 , V_64 , V_192 , 0x04 , 0x21 ) ;
return;
}
if ( V_153 -> V_201 ||
V_75 -> V_167 & ( V_171 | V_173 | V_178 | V_175 ) ) {
F_69 ( V_153 -> V_9 -> V_202 , V_75 -> V_167 , V_75 -> V_169 ,
& V_138 , & V_66 , & V_67 , V_187 ) ;
F_26 ( V_13 , V_64 , V_138 , V_66 , V_67 ) ;
} else {
F_74 ( V_13 , L_24 ,
V_75 -> V_167 , V_153 -> V_201 ) ;
F_26 ( V_13 , V_64 , V_190 , 0 , 0 ) ;
return;
}
V_212 = F_29 ( & V_153 -> V_198 , V_13 ) ;
if ( V_212 == V_77 )
return;
F_30 ( V_199 , V_78 , V_212 ) ;
}
static void F_75 ( struct V_28 * V_29 )
{
V_29 -> V_213 = 1 ;
V_29 -> V_214 = 1 ;
V_29 -> V_215 = 1 ;
V_29 -> V_216 = 1 ;
}
static int F_76 ( struct V_154 * V_217 )
{
if ( F_77 ( V_217 -> V_218 != V_219 ) )
return 0 ;
if ( ! F_78 ( V_217 ) || F_79 ( F_80 ( V_217 ) ) )
return 0 ;
return F_81 ( V_217 -> V_64 [ 0 ] ) == V_220 ;
}
static int F_82 ( struct V_28 * V_29 ,
struct V_12 * V_13 )
{
struct V_221 * V_222 = V_29 -> V_221 ;
if ( ! F_83 ( V_13 -> V_108 ) )
V_13 -> V_16 |= V_37 ;
F_84 ( V_222 , V_13 -> V_223 ) ;
if ( V_13 -> V_49 == V_224 ) {
void * V_4 ;
V_29 -> V_225 = V_128 ;
F_85 ( V_222 , V_226 - 1 ) ;
V_4 = F_50 ( V_227 , V_222 -> V_228 | V_129 ) ;
if ( ! V_4 ) {
F_86 ( V_13 , L_25 ) ;
return - V_127 ;
}
F_87 ( V_222 , F_76 , V_4 , V_227 ) ;
} else {
V_29 -> V_225 = F_88 ( V_13 -> V_108 ) ;
V_29 -> V_229 = 1 ;
}
if ( V_29 -> V_225 > V_27 )
F_74 ( V_13 ,
L_26 ,
V_29 -> V_225 ) ;
F_89 ( V_222 , V_29 -> V_225 - 1 ) ;
if ( V_13 -> V_16 & V_230 )
F_90 ( V_231 , V_29 -> V_232 ) ;
if ( V_13 -> V_16 & V_233 ) {
int V_234 ;
V_234 = F_91 ( V_29 -> V_34 -> V_235 , F_92 ( V_13 -> V_108 ) ) ;
V_234 = F_91 ( V_236 - 1 , V_234 ) ;
F_93 ( V_29 , V_234 ) ;
}
F_94 ( V_222 , false ) ;
V_13 -> V_29 = V_29 ;
return 0 ;
}
int F_95 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_12 * V_13 = F_96 ( V_9 , V_29 ) ;
int V_33 = 0 ;
F_75 ( V_29 ) ;
if ( V_13 )
V_33 = F_82 ( V_29 , V_13 ) ;
return V_33 ;
}
void F_97 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
struct V_221 * V_222 = V_29 -> V_221 ;
unsigned long V_16 ;
struct V_12 * V_13 ;
if ( ! V_9 -> V_82 -> V_200 )
return;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 = F_96 ( V_9 , V_29 ) ;
if ( V_13 && V_13 -> V_29 ) {
V_13 -> V_29 = NULL ;
V_13 -> V_16 |= V_237 ;
F_8 ( V_9 ) ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_54 ( V_222 -> V_238 ) ;
V_222 -> V_238 = NULL ;
V_222 -> V_239 = 0 ;
}
int F_98 ( struct V_8 * V_9 , struct V_28 * V_29 ,
int V_240 )
{
struct V_12 * V_13 ;
unsigned long V_16 ;
if ( V_240 < 1 || V_240 == V_29 -> V_240 )
return V_29 -> V_240 ;
V_13 = F_14 ( V_9 , V_29 ) ;
if ( ! V_13 || ! F_99 ( V_13 ) )
return V_29 -> V_240 ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_241 ;
if ( V_240 == 1 || ! F_100 ( V_13 ) ) {
V_13 -> V_16 |= V_241 ;
V_240 = 1 ;
}
F_9 ( V_9 -> V_21 , V_16 ) ;
V_240 = F_91 ( V_240 , V_29 -> V_34 -> V_235 ) ;
V_240 = F_91 ( V_240 , F_92 ( V_13 -> V_108 ) ) ;
V_240 = F_91 ( V_240 , V_236 - 1 ) ;
if ( V_29 -> V_240 == V_240 )
return - V_20 ;
return F_93 ( V_29 , V_240 ) ;
}
int F_101 ( struct V_28 * V_29 , int V_240 )
{
struct V_8 * V_9 = F_3 ( V_29 -> V_34 ) ;
return F_98 ( V_9 , V_29 , V_240 ) ;
}
static unsigned int F_102 ( struct V_152 * V_153 )
{
struct V_63 * V_162 = V_153 -> V_156 ;
struct V_74 * V_75 = & V_153 -> V_75 ;
const T_3 * V_242 = V_162 -> V_243 ;
T_5 V_244 ;
T_3 V_245 = 0xff ;
if ( V_162 -> V_246 < 5 ) {
V_244 = 4 ;
goto V_247;
}
V_75 -> V_16 |= V_248 | V_249 ;
V_75 -> V_250 = V_251 ;
if ( V_242 [ 1 ] & 0x1 ) {
;
}
if ( V_242 [ 4 ] & 0x2 ) {
V_244 = 4 ;
V_245 = 1 ;
goto V_247;
}
if ( ( ( V_242 [ 4 ] >> 4 ) & 0xf ) != 0 ) {
V_244 = 4 ;
V_245 = 3 ;
goto V_247;
}
if ( V_242 [ 4 ] & 0x1 ) {
V_75 -> V_203 = 1 ;
if ( V_153 -> V_13 -> V_16 & V_252 ) {
V_75 -> V_16 |= V_253 ;
V_75 -> V_206 = 0x0 ;
V_75 -> V_205 = 0x0 ;
V_75 -> V_204 = 0x0 ;
V_75 -> V_1 |= V_254 ;
} else {
V_75 -> V_204 = 0x1 ;
V_75 -> V_205 = 0x0 ;
V_75 -> V_206 = 0x0 ;
}
V_75 -> V_167 = V_255 ;
} else {
if ( ( V_153 -> V_9 -> V_16 & V_256 ) &&
V_257 == V_258 )
goto V_259;
if ( ( V_153 -> V_9 -> V_16 & V_260 ) &&
F_103 () )
goto V_259;
V_75 -> V_167 = V_261 ;
}
return 0 ;
V_247:
F_31 ( V_153 -> V_13 , V_162 , V_244 , V_245 ) ;
return 1 ;
V_259:
V_162 -> V_70 = V_262 ;
return 1 ;
}
static unsigned int F_104 ( struct V_152 * V_153 )
{
struct V_74 * V_75 = & V_153 -> V_75 ;
V_75 -> V_16 |= V_248 ;
V_75 -> V_250 = V_251 ;
if ( V_153 -> V_13 -> V_16 & V_263 )
V_75 -> V_167 = V_264 ;
else
V_75 -> V_167 = V_265 ;
V_153 -> V_16 |= V_266 ;
return 0 ;
}
static void F_105 ( const T_3 * V_242 , T_4 * V_267 , T_8 * V_268 )
{
T_4 V_269 = 0 ;
T_8 V_45 ;
F_106 ( L_27 ) ;
V_269 |= ( ( T_4 ) ( V_242 [ 1 ] & 0x1f ) ) << 16 ;
V_269 |= ( ( T_4 ) V_242 [ 2 ] ) << 8 ;
V_269 |= ( ( T_4 ) V_242 [ 3 ] ) ;
V_45 = V_242 [ 4 ] ;
* V_267 = V_269 ;
* V_268 = V_45 ;
}
static void F_107 ( const T_3 * V_242 , T_4 * V_267 , T_8 * V_268 )
{
T_4 V_269 = 0 ;
T_8 V_45 = 0 ;
F_106 ( L_28 ) ;
V_269 |= ( ( T_4 ) V_242 [ 2 ] ) << 24 ;
V_269 |= ( ( T_4 ) V_242 [ 3 ] ) << 16 ;
V_269 |= ( ( T_4 ) V_242 [ 4 ] ) << 8 ;
V_269 |= ( ( T_4 ) V_242 [ 5 ] ) ;
V_45 |= ( ( T_8 ) V_242 [ 7 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_242 [ 8 ] ) ;
* V_267 = V_269 ;
* V_268 = V_45 ;
}
static void F_108 ( const T_3 * V_242 , T_4 * V_267 , T_8 * V_268 )
{
T_4 V_269 = 0 ;
T_8 V_45 = 0 ;
F_106 ( L_29 ) ;
V_269 |= ( ( T_4 ) V_242 [ 2 ] ) << 56 ;
V_269 |= ( ( T_4 ) V_242 [ 3 ] ) << 48 ;
V_269 |= ( ( T_4 ) V_242 [ 4 ] ) << 40 ;
V_269 |= ( ( T_4 ) V_242 [ 5 ] ) << 32 ;
V_269 |= ( ( T_4 ) V_242 [ 6 ] ) << 24 ;
V_269 |= ( ( T_4 ) V_242 [ 7 ] ) << 16 ;
V_269 |= ( ( T_4 ) V_242 [ 8 ] ) << 8 ;
V_269 |= ( ( T_4 ) V_242 [ 9 ] ) ;
V_45 |= ( ( T_8 ) V_242 [ 10 ] ) << 24 ;
V_45 |= ( ( T_8 ) V_242 [ 11 ] ) << 16 ;
V_45 |= ( ( T_8 ) V_242 [ 12 ] ) << 8 ;
V_45 |= ( ( T_8 ) V_242 [ 13 ] ) ;
* V_267 = V_269 ;
* V_268 = V_45 ;
}
static unsigned int F_109 ( struct V_152 * V_153 )
{
struct V_63 * V_162 = V_153 -> V_156 ;
struct V_74 * V_75 = & V_153 -> V_75 ;
struct V_12 * V_13 = V_153 -> V_13 ;
T_4 V_270 = V_153 -> V_13 -> V_101 ;
const T_3 * V_242 = V_162 -> V_243 ;
T_4 V_212 ;
T_8 V_271 ;
T_5 V_244 ;
V_75 -> V_16 |= V_249 | V_248 ;
V_75 -> V_250 = V_251 ;
if ( V_242 [ 0 ] == V_272 ) {
if ( V_162 -> V_246 < 10 ) {
V_244 = 9 ;
goto V_247;
}
F_107 ( V_242 , & V_212 , & V_271 ) ;
} else if ( V_242 [ 0 ] == V_273 ) {
if ( V_162 -> V_246 < 16 ) {
V_244 = 15 ;
goto V_247;
}
F_108 ( V_242 , & V_212 , & V_271 ) ;
} else {
V_244 = 0 ;
goto V_247;
}
if ( ! V_271 )
goto V_274;
if ( V_212 >= V_270 )
goto V_275;
if ( ( V_212 + V_271 ) > V_270 )
goto V_275;
if ( V_13 -> V_16 & V_252 ) {
V_75 -> V_16 |= V_253 ;
if ( F_110 ( V_212 , V_271 ) ) {
V_75 -> V_167 = V_255 ;
V_75 -> V_1 |= ( V_212 >> 24 ) & 0xf ;
} else if ( F_111 ( V_212 , V_271 ) ) {
if ( ! ( V_13 -> V_16 & V_276 ) )
goto V_275;
V_75 -> V_16 |= V_207 ;
V_75 -> V_167 = V_277 ;
V_75 -> V_208 = ( V_271 >> 8 ) & 0xff ;
V_75 -> V_211 = ( V_212 >> 40 ) & 0xff ;
V_75 -> V_210 = ( V_212 >> 32 ) & 0xff ;
V_75 -> V_209 = ( V_212 >> 24 ) & 0xff ;
} else
goto V_275;
V_75 -> V_203 = V_271 & 0xff ;
V_75 -> V_206 = ( V_212 >> 16 ) & 0xff ;
V_75 -> V_205 = ( V_212 >> 8 ) & 0xff ;
V_75 -> V_204 = V_212 & 0xff ;
V_75 -> V_1 |= V_254 ;
} else {
T_8 V_278 , V_279 , V_280 , V_281 ;
if ( ! F_110 ( V_212 , V_271 ) )
goto V_275;
V_281 = ( T_8 ) V_212 / V_13 -> V_282 ;
V_280 = V_281 / V_13 -> V_283 ;
V_279 = V_281 % V_13 -> V_283 ;
V_278 = ( T_8 ) V_212 % V_13 -> V_282 + 1 ;
F_112 ( L_30 ,
( T_8 ) V_212 , V_281 , V_280 , V_279 , V_278 ) ;
if ( ( V_280 >> 16 ) || ( V_279 >> 4 ) || ( V_278 >> 8 ) || ( ! V_278 ) )
goto V_275;
V_75 -> V_167 = V_255 ;
V_75 -> V_203 = V_271 & 0xff ;
V_75 -> V_204 = V_278 ;
V_75 -> V_205 = V_280 ;
V_75 -> V_206 = V_280 >> 8 ;
V_75 -> V_1 |= V_279 ;
}
return 0 ;
V_247:
F_31 ( V_153 -> V_13 , V_162 , V_244 , 0xff ) ;
return 1 ;
V_275:
F_26 ( V_153 -> V_13 , V_162 , V_81 , 0x21 , 0x0 ) ;
return 1 ;
V_274:
V_162 -> V_70 = V_262 ;
return 1 ;
}
static unsigned int F_113 ( struct V_152 * V_153 )
{
struct V_63 * V_162 = V_153 -> V_156 ;
const T_3 * V_242 = V_162 -> V_243 ;
struct V_154 * V_217 = V_162 -> V_154 ;
int V_49 = F_114 ( F_115 ( V_217 ) ) ;
unsigned int V_284 = 0 ;
T_4 V_212 ;
T_8 V_271 ;
int V_33 ;
T_5 V_244 = 0 ;
if ( V_242 [ 0 ] == V_285 || V_242 [ 0 ] == V_286 || V_242 [ 0 ] == V_287 )
V_284 |= V_288 ;
switch ( V_242 [ 0 ] ) {
case V_289 :
case V_285 :
if ( F_20 ( V_162 -> V_246 < 10 ) ) {
V_244 = 9 ;
goto V_247;
}
F_107 ( V_242 , & V_212 , & V_271 ) ;
if ( V_242 [ 1 ] & ( 1 << 3 ) )
V_284 |= V_290 ;
break;
case V_291 :
case V_286 :
if ( F_20 ( V_162 -> V_246 < 6 ) ) {
V_244 = 5 ;
goto V_247;
}
F_105 ( V_242 , & V_212 , & V_271 ) ;
if ( ! V_271 )
V_271 = 256 ;
break;
case V_292 :
case V_287 :
if ( F_20 ( V_162 -> V_246 < 16 ) ) {
V_244 = 15 ;
goto V_247;
}
F_108 ( V_242 , & V_212 , & V_271 ) ;
if ( V_242 [ 1 ] & ( 1 << 3 ) )
V_284 |= V_290 ;
break;
default:
F_112 ( L_31 ) ;
V_244 = 0 ;
goto V_247;
}
if ( ! V_271 )
goto V_274;
V_153 -> V_16 |= V_266 ;
V_153 -> V_165 = V_271 * V_162 -> V_1 -> V_225 ;
V_33 = F_116 ( & V_153 -> V_75 , V_153 -> V_13 , V_212 , V_271 , V_284 ,
V_153 -> V_155 , V_49 ) ;
if ( F_77 ( V_33 == 0 ) )
return 0 ;
if ( V_33 == - V_293 )
goto V_275;
V_247:
F_31 ( V_153 -> V_13 , V_162 , V_244 , 0xff ) ;
return 1 ;
V_275:
F_26 ( V_153 -> V_13 , V_162 , V_81 , 0x21 , 0x0 ) ;
return 1 ;
V_274:
V_162 -> V_70 = V_262 ;
return 1 ;
}
static void F_117 ( struct V_152 * V_153 )
{
struct V_63 * V_64 = V_153 -> V_156 ;
void (* F_118)( struct V_63 * ) = V_153 -> V_157 ;
F_119 ( V_153 ) ;
F_118 ( V_64 ) ;
}
static void F_120 ( struct V_152 * V_153 )
{
struct V_8 * V_9 = V_153 -> V_9 ;
struct V_63 * V_64 = V_153 -> V_156 ;
T_3 * V_242 = V_64 -> V_243 ;
int V_294 = ( V_153 -> V_201 != 0 ) ;
if ( ( ( V_242 [ 0 ] == V_132 ) || ( V_242 [ 0 ] == V_295 ) ) &&
( ( V_242 [ 2 ] & 0x20 ) || V_294 ) )
F_70 ( V_153 ) ;
else if ( V_153 -> V_16 & V_296 )
V_64 -> V_70 = V_72 ;
else if ( V_294 )
F_72 ( V_153 ) ;
else
V_64 -> V_70 = V_262 ;
if ( V_294 && ! V_9 -> V_82 -> V_200 )
F_67 ( V_9 -> V_202 , & V_153 -> V_198 ) ;
F_117 ( V_153 ) ;
}
static int F_121 ( struct V_12 * V_13 , struct V_63 * V_64 ,
T_9 V_297 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_152 * V_153 ;
int V_33 ;
F_106 ( L_32 ) ;
V_153 = F_61 ( V_13 , V_64 ) ;
if ( ! V_153 )
goto V_298;
if ( V_64 -> V_299 == V_130 ||
V_64 -> V_299 == V_300 ) {
if ( F_20 ( F_66 ( V_64 ) < 1 ) ) {
F_74 ( V_13 , L_33 ) ;
goto V_301;
}
F_122 ( V_153 , F_63 ( V_64 ) , F_64 ( V_64 ) ) ;
V_153 -> V_302 = V_64 -> V_299 ;
}
V_153 -> V_303 = F_120 ;
if ( V_297 ( V_153 ) )
goto V_304;
if ( V_9 -> V_82 -> V_305 ) {
if ( ( V_33 = V_9 -> V_82 -> V_305 ( V_153 ) ) )
goto V_306;
}
F_123 ( V_153 ) ;
F_106 ( L_34 ) ;
return 0 ;
V_304:
F_119 ( V_153 ) ;
V_64 -> V_96 ( V_64 ) ;
F_112 ( L_35 ) ;
return 0 ;
V_301:
F_119 ( V_153 ) ;
V_64 -> V_70 = ( V_307 << 16 ) ;
V_64 -> V_96 ( V_64 ) ;
V_298:
F_112 ( L_36 ) ;
return 0 ;
V_306:
F_119 ( V_153 ) ;
F_112 ( L_37 ) ;
if ( V_33 == V_308 )
return V_309 ;
else
return V_310 ;
}
static void * F_124 ( struct V_63 * V_64 , bool V_311 ,
unsigned long * V_16 )
{
F_5 ( & V_312 , * V_16 ) ;
memset ( V_313 , 0 , V_314 ) ;
if ( V_311 )
F_125 ( F_63 ( V_64 ) , F_64 ( V_64 ) ,
V_313 , V_314 ) ;
return V_313 ;
}
static inline void F_126 ( struct V_63 * V_64 , bool V_315 ,
unsigned long * V_16 )
{
if ( V_315 )
F_127 ( F_63 ( V_64 ) , F_64 ( V_64 ) ,
V_313 , V_314 ) ;
F_9 ( & V_312 , * V_16 ) ;
}
static unsigned int F_128 ( struct V_316 * args , T_3 * V_317 )
{
const T_3 V_318 [] = {
0x00 ,
0x60 ,
0x03 ,
0x20 ,
0x03 ,
0x00
} ;
const T_3 V_319 [] = {
0x00 ,
0xA0 ,
0x06 ,
0x00 ,
0x05 ,
0xC0 ,
0x60 ,
0x24 ,
} ;
T_3 V_320 [] = {
V_321 ,
0 ,
0x5 ,
2 ,
95 - 4 ,
0 ,
0 ,
2
} ;
F_106 ( L_32 ) ;
if ( F_129 ( args -> V_108 ) ||
( args -> V_13 -> V_11 -> V_9 -> V_39 & V_322 ) )
V_320 [ 1 ] |= ( 1 << 7 ) ;
if ( args -> V_13 -> V_49 == V_51 ) {
V_320 [ 0 ] = V_323 ;
V_320 [ 2 ] = 0x7 ;
}
memcpy ( V_317 , V_320 , sizeof( V_320 ) ) ;
memcpy ( & V_317 [ 8 ] , L_38 , 8 ) ;
F_46 ( args -> V_108 , & V_317 [ 16 ] , V_111 , 16 ) ;
F_46 ( args -> V_108 , & V_317 [ 32 ] , V_113 + 2 , 4 ) ;
if ( strncmp ( & V_317 [ 32 ] , L_39 , 4 ) == 0 )
F_46 ( args -> V_108 , & V_317 [ 32 ] , V_113 , 4 ) ;
if ( V_317 [ 32 ] == 0 || V_317 [ 32 ] == ' ' )
memcpy ( & V_317 [ 32 ] , L_40 , 4 ) ;
if ( F_130 ( args -> V_108 ) || args -> V_13 -> V_49 == V_51 )
memcpy ( V_317 + 58 , V_319 , sizeof( V_319 ) ) ;
else
memcpy ( V_317 + 58 , V_318 , sizeof( V_318 ) ) ;
return 0 ;
}
static unsigned int F_131 ( struct V_316 * args , T_3 * V_317 )
{
int V_324 ;
const T_3 V_325 [] = {
0x00 ,
0x80 ,
0x83 ,
0x89 ,
0xb0 ,
0xb1 ,
0xb2 ,
0xb6 ,
} ;
V_324 = sizeof( V_325 ) ;
if ( ! ( args -> V_13 -> V_16 & V_326 ) )
V_324 -- ;
V_317 [ 3 ] = V_324 ;
memcpy ( V_317 + 4 , V_325 , V_324 ) ;
return 0 ;
}
static unsigned int F_132 ( struct V_316 * args , T_3 * V_317 )
{
const T_3 V_320 [] = {
0 ,
0x80 ,
0 ,
V_116 ,
} ;
memcpy ( V_317 , V_320 , sizeof( V_320 ) ) ;
F_46 ( args -> V_108 , ( unsigned char * ) & V_317 [ 4 ] ,
V_115 , V_116 ) ;
return 0 ;
}
static unsigned int F_133 ( struct V_316 * args , T_3 * V_317 )
{
const int V_327 = 68 ;
int V_328 ;
V_317 [ 1 ] = 0x83 ;
V_328 = 4 ;
V_317 [ V_328 + 0 ] = 2 ;
V_317 [ V_328 + 3 ] = V_116 ;
V_328 += 4 ;
F_46 ( args -> V_108 , ( unsigned char * ) V_317 + V_328 ,
V_115 , V_116 ) ;
V_328 += V_116 ;
V_317 [ V_328 + 0 ] = 2 ;
V_317 [ V_328 + 1 ] = 1 ;
V_317 [ V_328 + 3 ] = V_327 ;
V_328 += 4 ;
memcpy ( V_317 + V_328 , L_38 , 8 ) ;
V_328 += 8 ;
F_46 ( args -> V_108 , ( unsigned char * ) V_317 + V_328 , V_111 ,
V_112 ) ;
V_328 += V_112 ;
F_46 ( args -> V_108 , ( unsigned char * ) V_317 + V_328 , V_115 ,
V_116 ) ;
V_328 += V_116 ;
if ( F_134 ( args -> V_108 ) ) {
V_317 [ V_328 + 0 ] = 1 ;
V_317 [ V_328 + 1 ] = 3 ;
V_317 [ V_328 + 3 ] = V_329 ;
V_328 += 4 ;
F_46 ( args -> V_108 , ( unsigned char * ) V_317 + V_328 ,
V_330 , V_329 ) ;
V_328 += V_329 ;
}
V_317 [ 3 ] = V_328 - 4 ;
return 0 ;
}
static unsigned int F_135 ( struct V_316 * args , T_3 * V_317 )
{
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_317 [ 1 ] = 0x89 ;
V_317 [ 2 ] = ( 0x238 >> 8 ) ;
V_317 [ 3 ] = ( 0x238 & 0xff ) ;
memcpy ( & V_317 [ 8 ] , L_41 , 8 ) ;
memcpy ( & V_317 [ 16 ] , L_42 , 16 ) ;
memcpy ( & V_317 [ 32 ] , V_331 , 4 ) ;
V_75 . V_167 = V_172 ;
V_75 . V_204 = 0x1 ;
V_75 . V_203 = 0x1 ;
F_136 ( & V_75 , 0 , 1 , & V_317 [ 36 ] ) ;
V_317 [ 36 ] = 0x34 ;
V_317 [ 56 ] = V_332 ;
memcpy ( & V_317 [ 60 ] , & args -> V_108 [ 0 ] , 512 ) ;
return 0 ;
}
static unsigned int F_137 ( struct V_316 * args , T_3 * V_317 )
{
T_5 V_333 ;
V_317 [ 1 ] = 0xb0 ;
V_317 [ 3 ] = 0x3c ;
V_333 = 1 << F_138 ( args -> V_108 ) ;
F_139 ( V_333 , & V_317 [ 6 ] ) ;
if ( F_140 ( args -> V_108 ) ) {
F_141 ( 65535 * V_334 , & V_317 [ 36 ] ) ;
F_142 ( 1 , & V_317 [ 28 ] ) ;
}
return 0 ;
}
static unsigned int F_143 ( struct V_316 * args , T_3 * V_317 )
{
int V_335 = F_144 ( args -> V_108 ) ;
int V_336 = F_145 ( args -> V_108 ) ;
T_3 V_337 = F_130 ( args -> V_108 ) ;
V_317 [ 1 ] = 0xb1 ;
V_317 [ 3 ] = 0x3c ;
V_317 [ 4 ] = V_336 >> 8 ;
V_317 [ 5 ] = V_336 ;
V_317 [ 7 ] = V_335 ;
if ( V_337 )
V_317 [ 8 ] = ( V_337 << 4 ) ;
return 0 ;
}
static unsigned int F_146 ( struct V_316 * args , T_3 * V_317 )
{
V_317 [ 1 ] = 0xb2 ;
V_317 [ 3 ] = 0x4 ;
V_317 [ 5 ] = 1 << 6 ;
return 0 ;
}
static unsigned int F_147 ( struct V_316 * args , T_3 * V_317 )
{
V_317 [ 1 ] = 0xb6 ;
V_317 [ 3 ] = 0x3C ;
if ( args -> V_13 -> V_338 & 1 )
V_317 [ 4 ] |= 1 ;
F_142 ( args -> V_13 -> V_339 , & V_317 [ 8 ] ) ;
F_142 ( args -> V_13 -> V_340 , & V_317 [ 12 ] ) ;
F_142 ( args -> V_13 -> V_341 , & V_317 [ 16 ] ) ;
return 0 ;
}
static unsigned int F_148 ( struct V_316 * args , T_3 * V_317 )
{
F_106 ( L_32 ) ;
return 0 ;
}
static void F_149 ( T_3 * V_342 , const T_3 * V_343 , int V_344 , bool V_345 )
{
if ( V_345 ) {
memcpy ( V_342 , V_343 , 2 ) ;
memset ( V_342 + 2 , 0 , V_344 - 2 ) ;
} else {
memcpy ( V_342 , V_343 , V_344 ) ;
}
}
static unsigned int F_150 ( T_5 * V_108 , T_3 * V_4 , bool V_345 )
{
F_149 ( V_4 , V_346 , sizeof( V_346 ) , V_345 ) ;
if ( V_345 ) {
V_4 [ 2 ] |= ( 1 << 2 ) ;
} else {
V_4 [ 2 ] |= ( F_151 ( V_108 ) << 2 ) ;
V_4 [ 12 ] |= ( ! F_152 ( V_108 ) << 5 ) ;
}
return sizeof( V_346 ) ;
}
static unsigned int F_153 ( struct V_12 * V_13 , T_3 * V_4 ,
bool V_345 )
{
F_149 ( V_4 , V_347 , sizeof( V_347 ) , V_345 ) ;
if ( V_345 ) {
V_4 [ 2 ] |= ( 1 << 2 ) ;
} else {
bool V_68 = ( V_13 -> V_16 & V_69 ) ;
V_4 [ 2 ] |= ( V_68 << 2 ) ;
}
return sizeof( V_347 ) ;
}
static unsigned int F_154 ( T_3 * V_4 , bool V_345 )
{
F_149 ( V_4 , V_348 , sizeof( V_348 ) ,
V_345 ) ;
return sizeof( V_348 ) ;
}
static int F_155 ( T_5 * V_108 )
{
unsigned char V_349 [ V_112 + 1 ] , V_350 [ V_114 + 1 ] ;
if ( ! V_351 )
return 0 ;
if ( ! F_156 ( V_108 ) )
return 0 ;
F_157 ( V_108 , V_349 , V_111 , sizeof( V_349 ) ) ;
F_157 ( V_108 , V_350 , V_113 , sizeof( V_350 ) ) ;
if ( strcmp ( V_349 , L_43 ) )
return 1 ;
if ( strcmp ( V_350 , L_44 ) )
return 1 ;
return 0 ;
}
static unsigned int F_158 ( struct V_316 * args , T_3 * V_317 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_156 = args -> V_64 -> V_243 , * V_352 = V_317 ;
const T_3 V_353 [] = {
0 , 0 , 0 , 0 ,
0 ,
0 , 0x2 , 0x0
} ;
T_3 V_354 , V_355 ;
unsigned int V_356 , V_357 , V_358 ;
T_3 V_359 , V_245 = 0xff ;
T_5 V_244 ;
F_106 ( L_32 ) ;
V_358 = ( V_156 [ 0 ] == V_360 ) ;
V_356 = ! ( V_156 [ 1 ] & 0x8 ) ;
V_357 = V_156 [ 2 ] >> 6 ;
switch ( V_357 ) {
case 0 :
case 1 :
case 2 :
break;
case 3 :
goto V_361;
default:
V_244 = 2 ;
V_245 = 6 ;
goto V_247;
}
if ( V_358 )
V_352 += 4 + ( V_356 ? 8 : 0 ) ;
else
V_352 += 8 + ( V_356 ? 8 : 0 ) ;
V_354 = V_156 [ 2 ] & 0x3f ;
V_355 = V_156 [ 3 ] ;
if ( V_355 && ( V_355 != V_362 ) ) {
V_244 = 3 ;
goto V_247;
}
switch( V_354 ) {
case V_363 :
V_352 += F_154 ( V_352 , V_357 == 1 ) ;
break;
case V_364 :
V_352 += F_150 ( args -> V_108 , V_352 , V_357 == 1 ) ;
break;
case V_365 :
V_352 += F_153 ( args -> V_13 , V_352 , V_357 == 1 ) ;
break;
case V_366 :
V_352 += F_154 ( V_352 , V_357 == 1 ) ;
V_352 += F_150 ( args -> V_108 , V_352 , V_357 == 1 ) ;
V_352 += F_153 ( args -> V_13 , V_352 , V_357 == 1 ) ;
break;
default:
V_244 = 2 ;
goto V_247;
}
V_359 = 0 ;
if ( F_155 ( args -> V_108 ) && ( V_13 -> V_16 & V_276 ) &&
( ! ( V_13 -> V_16 & V_367 ) || V_13 -> V_368 ) )
V_359 = 1 << 4 ;
if ( V_358 ) {
V_317 [ 0 ] = V_352 - V_317 - 1 ;
V_317 [ 2 ] |= V_359 ;
if ( V_356 ) {
V_317 [ 3 ] = sizeof( V_353 ) ;
memcpy ( V_317 + 4 , V_353 , sizeof( V_353 ) ) ;
}
} else {
unsigned int V_369 = V_352 - V_317 - 2 ;
V_317 [ 0 ] = V_369 >> 8 ;
V_317 [ 1 ] = V_369 ;
V_317 [ 3 ] |= V_359 ;
if ( V_356 ) {
V_317 [ 7 ] = sizeof( V_353 ) ;
memcpy ( V_317 + 8 , V_353 , sizeof( V_353 ) ) ;
}
}
return 0 ;
V_247:
F_31 ( V_13 , args -> V_64 , V_244 , V_245 ) ;
return 1 ;
V_361:
F_26 ( V_13 , args -> V_64 , V_81 , 0x39 , 0x0 ) ;
return 1 ;
}
static unsigned int F_159 ( struct V_316 * args , T_3 * V_317 )
{
struct V_12 * V_13 = args -> V_13 ;
T_4 V_370 = V_13 -> V_101 - 1 ;
T_8 V_225 ;
T_3 V_371 ;
T_5 V_372 ;
V_225 = F_88 ( V_13 -> V_108 ) ;
V_371 = F_138 ( V_13 -> V_108 ) ;
V_372 = F_160 ( V_13 -> V_108 , V_371 ) ;
F_106 ( L_32 ) ;
if ( args -> V_64 -> V_243 [ 0 ] == V_373 ) {
if ( V_370 >= 0xffffffffULL )
V_370 = 0xffffffff ;
V_317 [ 0 ] = V_370 >> ( 8 * 3 ) ;
V_317 [ 1 ] = V_370 >> ( 8 * 2 ) ;
V_317 [ 2 ] = V_370 >> ( 8 * 1 ) ;
V_317 [ 3 ] = V_370 ;
V_317 [ 4 ] = V_225 >> ( 8 * 3 ) ;
V_317 [ 5 ] = V_225 >> ( 8 * 2 ) ;
V_317 [ 6 ] = V_225 >> ( 8 * 1 ) ;
V_317 [ 7 ] = V_225 ;
} else {
V_317 [ 0 ] = V_370 >> ( 8 * 7 ) ;
V_317 [ 1 ] = V_370 >> ( 8 * 6 ) ;
V_317 [ 2 ] = V_370 >> ( 8 * 5 ) ;
V_317 [ 3 ] = V_370 >> ( 8 * 4 ) ;
V_317 [ 4 ] = V_370 >> ( 8 * 3 ) ;
V_317 [ 5 ] = V_370 >> ( 8 * 2 ) ;
V_317 [ 6 ] = V_370 >> ( 8 * 1 ) ;
V_317 [ 7 ] = V_370 ;
V_317 [ 8 ] = V_225 >> ( 8 * 3 ) ;
V_317 [ 9 ] = V_225 >> ( 8 * 2 ) ;
V_317 [ 10 ] = V_225 >> ( 8 * 1 ) ;
V_317 [ 11 ] = V_225 ;
V_317 [ 12 ] = 0 ;
V_317 [ 13 ] = V_371 ;
V_317 [ 14 ] = ( V_372 >> 8 ) & 0x3f ;
V_317 [ 15 ] = V_372 ;
if ( F_140 ( args -> V_108 ) &&
! ( V_13 -> V_22 & V_374 ) ) {
V_317 [ 14 ] |= 0x80 ;
if ( F_161 ( args -> V_108 ) &&
V_13 -> V_22 & V_375 ) {
F_162 ( V_13 , L_45 ) ;
V_317 [ 14 ] |= 0x40 ;
}
}
if ( F_130 ( args -> V_108 ) ||
args -> V_13 -> V_49 == V_51 )
V_317 [ 12 ] = ( 1 << 4 ) ;
}
return 0 ;
}
static unsigned int F_163 ( struct V_316 * args , T_3 * V_317 )
{
F_106 ( L_32 ) ;
V_317 [ 3 ] = 8 ;
return 0 ;
}
static void F_164 ( struct V_152 * V_153 )
{
if ( V_153 -> V_201 && ( ( V_153 -> V_201 & V_376 ) == 0 ) ) {
F_70 ( V_153 ) ;
}
F_117 ( V_153 ) ;
}
static inline int F_165 ( struct V_8 * V_9 )
{
return ( V_9 -> V_16 & V_140 ) ;
}
static void F_166 ( struct V_152 * V_153 )
{
struct V_8 * V_9 = V_153 -> V_9 ;
struct V_63 * V_64 = V_153 -> V_156 ;
F_112 ( L_46 ) ;
memset ( V_64 -> V_73 , 0 , V_78 ) ;
#ifdef F_167
if ( V_9 -> V_82 -> V_377 )
V_9 -> V_82 -> V_377 ( V_9 , & V_153 -> V_75 ) ;
#endif
V_64 -> V_73 [ 0 ] = 0x70 ;
V_64 -> V_73 [ 2 ] = V_153 -> V_75 . V_169 >> 4 ;
F_168 ( V_153 ) ;
F_169 ( & V_153 -> V_378 , V_64 -> V_73 , V_78 ) ;
F_122 ( V_153 , & V_153 -> V_378 , 1 ) ;
V_153 -> V_302 = V_130 ;
memset ( & V_153 -> V_242 , 0 , V_153 -> V_13 -> V_379 ) ;
V_153 -> V_242 [ 0 ] = V_380 ;
V_153 -> V_242 [ 4 ] = V_78 ;
V_153 -> V_75 . V_16 |= V_249 | V_248 ;
V_153 -> V_75 . V_167 = V_381 ;
if ( F_165 ( V_9 ) ) {
V_153 -> V_75 . V_250 = V_382 ;
V_153 -> V_75 . V_169 |= V_383 ;
} else {
V_153 -> V_75 . V_250 = V_384 ;
V_153 -> V_75 . V_205 = V_78 ;
V_153 -> V_75 . V_206 = 0 ;
}
V_153 -> V_165 = V_78 ;
V_153 -> V_303 = F_164 ;
F_123 ( V_153 ) ;
F_112 ( L_34 ) ;
}
static void F_170 ( struct V_152 * V_153 )
{
struct V_63 * V_64 = V_153 -> V_156 ;
unsigned int V_201 = V_153 -> V_201 ;
F_106 ( L_47 , V_201 ) ;
if ( F_20 ( V_153 -> V_9 -> V_82 -> V_200 &&
( V_201 || V_153 -> V_16 & V_296 ) ) ) {
if ( ! ( V_153 -> V_16 & V_296 ) ) {
F_70 ( V_153 ) ;
}
if ( V_153 -> V_242 [ 0 ] == V_385 && V_153 -> V_13 -> V_29 )
V_153 -> V_13 -> V_29 -> V_386 = 0 ;
V_153 -> V_156 -> V_70 = V_72 ;
F_117 ( V_153 ) ;
return;
}
if ( F_20 ( V_201 & V_376 ) ) {
V_64 -> V_70 = V_72 ;
F_166 ( V_153 ) ;
return;
} else if ( F_20 ( V_201 ) ) {
F_70 ( V_153 ) ;
} else {
T_3 * V_156 = V_64 -> V_243 ;
if ( ( V_156 [ 0 ] == V_387 ) && ( ( V_156 [ 1 ] & 0x03 ) == 0 ) ) {
unsigned long V_16 ;
T_3 * V_4 ;
V_4 = F_124 ( V_64 , true , & V_16 ) ;
if ( V_4 [ 2 ] == 0 ) {
V_4 [ 2 ] = 0x5 ;
V_4 [ 3 ] = 0x32 ;
}
F_126 ( V_64 , true , & V_16 ) ;
}
V_64 -> V_70 = V_262 ;
}
F_117 ( V_153 ) ;
}
static unsigned int F_171 ( struct V_152 * V_153 )
{
struct V_63 * V_162 = V_153 -> V_156 ;
struct V_12 * V_13 = V_153 -> V_13 ;
int V_388 = ( V_162 -> V_299 == V_131 ) ;
int V_389 = ! V_388 && ( V_13 -> V_16 & V_367 ) ;
unsigned int V_165 ;
memset ( V_153 -> V_242 , 0 , V_13 -> V_379 ) ;
memcpy ( V_153 -> V_242 , V_162 -> V_243 , V_162 -> V_246 ) ;
V_153 -> V_303 = F_170 ;
V_153 -> V_75 . V_16 |= V_249 | V_248 ;
if ( V_162 -> V_299 == V_300 ) {
V_153 -> V_75 . V_16 |= V_288 ;
F_112 ( L_48 ) ;
}
V_153 -> V_75 . V_167 = V_381 ;
F_65 ( V_153 ) ;
if ( ! V_388 && ! V_389 && F_172 ( V_153 ) )
V_389 = 1 ;
V_165 = F_91 ( F_173 ( V_153 ) , ( unsigned int ) 63 * 1024 ) ;
if ( V_165 & 0x1 )
V_165 ++ ;
V_153 -> V_75 . V_205 = ( V_165 & 0xFF ) ;
V_153 -> V_75 . V_206 = ( V_165 >> 8 ) ;
if ( V_388 )
V_153 -> V_75 . V_250 = V_390 ;
else if ( V_389 )
V_153 -> V_75 . V_250 = V_384 ;
else {
V_153 -> V_75 . V_250 = V_382 ;
V_153 -> V_75 . V_169 |= V_383 ;
if ( ( V_13 -> V_16 & V_391 ) &&
( V_162 -> V_299 != V_300 ) )
V_153 -> V_75 . V_169 |= V_392 ;
}
return 0 ;
}
static struct V_12 * F_174 ( struct V_8 * V_9 , int V_43 )
{
if ( ! F_175 ( V_9 ) ) {
if ( F_77 ( V_43 < F_176 ( & V_9 -> V_11 ) ) )
return & V_9 -> V_11 . V_1 [ V_43 ] ;
} else {
if ( F_77 ( V_43 < V_9 -> V_393 ) )
return & V_9 -> V_394 [ V_43 ] . V_1 [ 0 ] ;
}
return NULL ;
}
static struct V_12 * F_96 ( struct V_8 * V_9 ,
const struct V_28 * V_117 )
{
int V_43 ;
if ( ! F_175 ( V_9 ) ) {
if ( F_20 ( V_117 -> V_395 || V_117 -> V_396 ) )
return NULL ;
V_43 = V_117 -> V_108 ;
} else {
if ( F_20 ( V_117 -> V_108 || V_117 -> V_396 ) )
return NULL ;
V_43 = V_117 -> V_395 ;
}
return F_174 ( V_9 , V_43 ) ;
}
static struct V_12 *
F_14 ( struct V_8 * V_9 , const struct V_28 * V_117 )
{
struct V_12 * V_13 = F_96 ( V_9 , V_117 ) ;
if ( F_20 ( ! V_13 || ! F_99 ( V_13 ) ) )
return NULL ;
return V_13 ;
}
static T_3
F_177 ( T_3 V_397 )
{
switch( ( V_397 & 0x1e ) >> 1 ) {
case 3 :
return V_251 ;
case 6 :
case 10 :
case 11 :
return V_398 ;
case 4 :
case 5 :
return V_399 ;
case 12 :
return V_400 ;
case 0 :
case 1 :
case 8 :
case 9 :
case 7 :
case 15 :
default:
break;
}
return V_401 ;
}
static unsigned int F_178 ( struct V_152 * V_153 )
{
struct V_74 * V_75 = & ( V_153 -> V_75 ) ;
struct V_63 * V_162 = V_153 -> V_156 ;
struct V_12 * V_13 = V_153 -> V_13 ;
const T_3 * V_242 = V_162 -> V_243 ;
T_5 V_244 ;
if ( ( V_75 -> V_250 = F_177 ( V_242 [ 1 ] ) ) == V_401 ) {
V_244 = 1 ;
goto V_247;
}
if ( F_179 ( V_75 -> V_250 ) && ( V_242 [ 2 ] & 0x3 ) == 0 )
V_75 -> V_250 = V_402 ;
V_75 -> V_16 |= V_253 ;
if ( V_242 [ 0 ] == V_132 ) {
if ( V_242 [ 1 ] & 0x01 ) {
V_75 -> V_403 = V_242 [ 3 ] ;
V_75 -> V_208 = V_242 [ 5 ] ;
V_75 -> V_209 = V_242 [ 7 ] ;
V_75 -> V_210 = V_242 [ 9 ] ;
V_75 -> V_211 = V_242 [ 11 ] ;
V_75 -> V_16 |= V_207 ;
} else
V_75 -> V_16 &= ~ V_207 ;
V_75 -> V_169 = V_242 [ 4 ] ;
V_75 -> V_203 = V_242 [ 6 ] ;
V_75 -> V_204 = V_242 [ 8 ] ;
V_75 -> V_205 = V_242 [ 10 ] ;
V_75 -> V_206 = V_242 [ 12 ] ;
V_75 -> V_1 = V_242 [ 13 ] ;
V_75 -> V_167 = V_242 [ 14 ] ;
} else {
V_75 -> V_16 &= ~ V_207 ;
V_75 -> V_169 = V_242 [ 3 ] ;
V_75 -> V_203 = V_242 [ 4 ] ;
V_75 -> V_204 = V_242 [ 5 ] ;
V_75 -> V_205 = V_242 [ 6 ] ;
V_75 -> V_206 = V_242 [ 7 ] ;
V_75 -> V_1 = V_242 [ 8 ] ;
V_75 -> V_167 = V_242 [ 9 ] ;
}
if ( F_179 ( V_75 -> V_250 ) )
V_75 -> V_203 = V_153 -> V_155 << 3 ;
V_75 -> V_1 = V_13 -> V_43 ?
V_75 -> V_1 | V_404 : V_75 -> V_1 & ~ V_404 ;
switch ( V_75 -> V_167 ) {
case V_405 :
case V_406 :
case V_407 :
case V_408 :
if ( V_75 -> V_250 != V_399 || V_75 -> V_203 != 1 ) {
V_244 = 1 ;
goto V_247;
}
V_153 -> V_409 = F_66 ( V_162 ) ;
break;
case V_410 :
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
case V_255 :
case V_277 :
case V_423 :
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
V_153 -> V_409 = V_162 -> V_1 -> V_225 ;
break;
default:
V_153 -> V_409 = V_128 ;
}
V_75 -> V_16 |= V_249 | V_248 ;
if ( V_162 -> V_299 == V_300 )
V_75 -> V_16 |= V_288 ;
V_153 -> V_16 |= V_436 | V_437 ;
F_65 ( V_153 ) ;
if ( V_75 -> V_250 == V_398 && V_13 -> V_438 == 0 ) {
V_244 = 1 ;
goto V_247;
}
if ( ( V_242 [ 1 ] & 0xe0 ) && ! F_180 ( V_75 ) ) {
V_244 = 1 ;
goto V_247;
}
if ( F_180 ( V_75 ) ) {
unsigned int V_368 = 1 << ( V_242 [ 1 ] >> 5 ) ;
if ( V_368 != V_13 -> V_368 )
F_74 ( V_13 , L_49 ,
V_368 ) ;
}
if ( V_75 -> V_167 == V_439 &&
V_75 -> V_169 == V_440 ) {
V_244 = ( V_242 [ 0 ] == V_132 ) ? 4 : 3 ;
goto V_247;
}
if ( V_75 -> V_167 >= 0x5C && V_75 -> V_167 <= 0x5F && ! V_441 ) {
V_244 = ( V_242 [ 0 ] == V_132 ) ? 14 : 9 ;
goto V_247;
}
return 0 ;
V_247:
F_31 ( V_13 , V_162 , V_244 , 0xff ) ;
return 1 ;
}
static T_2 F_181 ( struct V_63 * V_64 , T_8 V_442 ,
T_4 V_443 , T_8 V_5 )
{
struct V_28 * V_444 = V_64 -> V_1 ;
T_2 V_45 = V_444 -> V_225 ;
T_2 V_445 ;
T_10 * V_4 ;
T_8 V_188 = 0 ;
unsigned long V_16 ;
F_182 ( V_45 > V_314 ) ;
if ( V_45 > V_314 )
V_45 = V_314 ;
F_5 ( & V_312 , V_16 ) ;
V_4 = ( ( void * ) V_313 ) ;
memset ( V_4 , 0 , V_45 ) ;
while ( V_188 < V_442 ) {
T_4 V_446 = V_443 |
( ( T_4 ) ( V_5 > 0xffff ? 0xffff : V_5 ) << 48 ) ;
V_4 [ V_188 ++ ] = F_183 ( V_446 ) ;
if ( V_5 <= 0xffff )
break;
V_5 -= 0xffff ;
V_443 += 0xffff ;
}
V_445 = F_127 ( F_63 ( V_64 ) , F_64 ( V_64 ) , V_4 , V_45 ) ;
F_9 ( & V_312 , V_16 ) ;
return V_445 ;
}
static T_2 F_184 ( struct V_63 * V_64 , T_4 V_269 , T_4 V_328 )
{
struct V_28 * V_444 = V_64 -> V_1 ;
T_2 V_45 = V_444 -> V_225 ;
T_2 V_445 ;
T_5 * V_4 ;
unsigned long V_16 ;
F_5 ( & V_312 , V_16 ) ;
V_4 = ( ( void * ) V_313 ) ;
F_185 ( 0x0002 , & V_4 [ 0 ] ) ;
F_185 ( 0x0101 , & V_4 [ 1 ] ) ;
F_186 ( V_269 , & V_4 [ 2 ] ) ;
F_186 ( V_328 , & V_4 [ 6 ] ) ;
F_187 ( 0u , & V_4 [ 10 ] ) ;
F_182 ( V_45 > V_314 ) ;
if ( V_45 > V_314 )
V_45 = V_314 ;
V_445 = F_127 ( F_63 ( V_64 ) , F_64 ( V_64 ) , V_4 , V_45 ) ;
F_9 ( & V_312 , V_16 ) ;
return V_445 ;
}
static unsigned int F_188 ( struct V_152 * V_153 )
{
struct V_74 * V_75 = & V_153 -> V_75 ;
struct V_63 * V_162 = V_153 -> V_156 ;
struct V_28 * V_444 = V_162 -> V_1 ;
T_2 V_45 = V_444 -> V_225 ;
struct V_12 * V_13 = V_153 -> V_13 ;
const T_3 * V_242 = V_162 -> V_243 ;
T_4 V_212 ;
T_8 V_271 ;
const T_8 V_442 = V_45 >> 3 ;
T_8 V_447 ;
T_5 V_244 ;
T_3 V_245 = 0xff ;
T_3 V_448 = V_242 [ 1 ] & 0x8 ;
if ( F_20 ( ! V_13 -> V_438 ) )
goto V_449;
if ( F_20 ( V_162 -> V_246 < 16 ) ) {
V_244 = 15 ;
goto V_247;
}
F_108 ( V_242 , & V_212 , & V_271 ) ;
if ( V_448 ) {
if ( ( V_13 -> V_22 & V_374 ) ||
! F_140 ( V_13 -> V_108 ) ) {
V_244 = 1 ;
V_245 = 3 ;
goto V_247;
}
if ( V_271 > 0xffff * V_442 ) {
V_244 = 2 ;
goto V_247;
}
} else {
if ( ! F_189 ( V_13 -> V_108 ) ) {
V_244 = 1 ;
V_245 = 3 ;
goto V_247;
}
}
if ( ! F_64 ( V_162 ) )
goto V_450;
if ( V_448 ) {
V_447 = F_181 ( V_162 , V_442 , V_212 , V_271 ) ;
if ( V_447 != V_45 )
goto V_450;
if ( F_100 ( V_13 ) && F_190 ( V_13 ) ) {
V_75 -> V_250 = V_400 ;
V_75 -> V_167 = V_451 ;
V_75 -> V_208 = V_452 & 0x1f ;
V_75 -> V_203 = V_153 -> V_155 << 3 ;
V_75 -> V_403 = ( V_447 / 512 ) >> 8 ;
V_75 -> V_169 = V_447 / 512 ;
V_75 -> V_453 = 1 ;
} else {
V_75 -> V_250 = V_398 ;
V_75 -> V_403 = 0 ;
V_75 -> V_169 = V_454 ;
V_75 -> V_208 = ( V_447 / 512 ) >> 8 ;
V_75 -> V_203 = V_447 / 512 ;
V_75 -> V_167 = V_455 ;
}
} else {
V_447 = F_184 ( V_162 , V_212 , V_271 ) ;
if ( V_447 != V_45 )
goto V_450;
V_75 -> V_403 = 0 ;
V_75 -> V_169 = 0 ;
V_75 -> V_208 = 0 ;
V_75 -> V_203 = 1 ;
V_75 -> V_206 = 0 ;
V_75 -> V_205 = 0 ;
V_75 -> V_204 = V_261 ;
V_75 -> V_211 = 0 ;
V_75 -> V_210 = 0 ;
V_75 -> V_209 = 0 ;
V_75 -> V_1 = V_261 ;
V_75 -> V_250 = V_398 ;
V_75 -> V_167 = V_456 ;
if ( F_20 ( V_13 -> V_16 & V_367 ) )
V_75 -> V_167 = V_457 ;
}
V_75 -> V_16 |= V_249 | V_248 | V_207 |
V_288 ;
F_65 ( V_153 ) ;
return 0 ;
V_247:
F_31 ( V_13 , V_162 , V_244 , V_245 ) ;
return 1 ;
V_450:
F_26 ( V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
V_449:
F_26 ( V_13 , V_162 , V_81 , 0x20 , 0x0 ) ;
return 1 ;
}
static unsigned int F_191 ( struct V_316 * args , T_3 * V_317 )
{
struct V_12 * V_13 = args -> V_13 ;
T_3 * V_242 = args -> V_64 -> V_243 ;
T_3 V_458 = 0 ;
unsigned int V_168 = 0 ;
if ( V_242 [ 2 ] != 1 ) {
F_74 ( V_13 , L_50 , V_242 [ 2 ] ) ;
V_168 = 2 ;
goto V_459;
}
switch ( V_242 [ 3 ] ) {
case V_387 :
case V_360 :
case V_460 :
case V_373 :
case V_461 :
case V_462 :
case V_380 :
case V_463 :
case V_464 :
case V_465 :
case V_466 :
case V_467 :
case V_468 :
case V_469 :
case V_291 :
case V_289 :
case V_292 :
case V_286 :
case V_285 :
case V_287 :
case V_295 :
case V_132 :
case V_272 :
case V_273 :
case V_470 :
case V_471 :
case V_472 :
V_458 = 3 ;
break;
case V_473 :
if ( ! F_189 ( V_13 -> V_108 ) )
break;
case V_474 :
case V_475 :
if ( F_130 ( V_13 -> V_108 ) ||
V_13 -> V_49 == V_51 )
V_458 = 3 ;
break;
default:
break;
}
V_459:
V_317 [ 1 ] = V_458 ;
return V_168 ;
}
static void F_192 ( struct V_152 * V_153 )
{
struct V_63 * V_162 = V_153 -> V_156 ;
struct V_476 V_477 ;
unsigned long V_16 ;
unsigned int V_478 = 0 ;
F_193 ( & V_477 , F_63 ( V_162 ) , F_64 ( V_162 ) ,
V_479 | V_480 ) ;
F_194 ( V_16 ) ;
while ( F_195 ( & V_477 ) ) {
unsigned int V_481 = 0 ;
if ( V_478 == 0 ) {
char * V_320 ;
T_8 V_482 ;
T_4 V_483 , V_484 ;
T_5 V_485 ;
V_320 = V_477 . V_486 ;
V_482 = F_196 ( & V_320 [ 0 ] ) ;
V_485 = F_197 ( & V_320 [ 4 ] ) ;
V_483 = F_198 ( & V_320 [ 8 ] ) ;
V_484 = F_198 ( & V_320 [ 16 ] ) ;
F_142 ( V_482 , & V_320 [ 0 ] ) ;
V_320 [ 4 ] = V_485 & 0xf ;
F_141 ( V_483 , & V_320 [ 8 ] ) ;
F_141 ( V_484 , & V_320 [ 16 ] ) ;
V_481 += 64 ;
V_478 += 64 ;
}
while ( V_481 < V_477 . V_487 ) {
char * V_488 ;
T_3 V_489 , type , V_490 , V_491 ;
T_4 V_447 , V_492 , V_493 ;
V_488 = V_477 . V_486 + V_481 ;
type = V_488 [ 0 ] & 0xf ;
V_489 = ( V_488 [ 1 ] >> 4 ) & 0xf ;
V_490 = ( V_488 [ 1 ] & 2 ) ;
V_491 = ( V_488 [ 1 ] & 1 ) ;
V_447 = F_198 ( & V_488 [ 8 ] ) ;
V_492 = F_198 ( & V_488 [ 16 ] ) ;
V_493 = F_198 ( & V_488 [ 24 ] ) ;
V_488 [ 0 ] = type ;
V_488 [ 1 ] = ( V_489 << 4 ) | V_490 | V_491 ;
F_141 ( V_447 , & V_488 [ 8 ] ) ;
F_141 ( V_492 , & V_488 [ 16 ] ) ;
F_141 ( V_493 , & V_488 [ 24 ] ) ;
F_182 ( V_481 + 64 > V_477 . V_487 ) ;
V_481 += 64 ;
V_478 += 64 ;
}
}
F_199 ( & V_477 ) ;
F_200 ( V_16 ) ;
F_120 ( V_153 ) ;
}
static unsigned int F_201 ( struct V_152 * V_153 )
{
struct V_74 * V_75 = & V_153 -> V_75 ;
struct V_63 * V_162 = V_153 -> V_156 ;
const T_3 * V_242 = V_162 -> V_243 ;
T_5 V_278 , V_244 = ( T_5 ) - 1 ;
T_3 V_494 , V_495 , V_245 = 0xff ;
T_4 V_212 ;
T_8 V_271 ;
if ( F_20 ( V_162 -> V_246 < 16 ) ) {
F_74 ( V_153 -> V_13 , L_51 ,
V_162 -> V_246 ) ;
V_244 = 15 ;
goto V_247;
}
F_108 ( V_242 , & V_212 , & V_271 ) ;
if ( V_271 != F_66 ( V_162 ) ) {
F_74 ( V_153 -> V_13 , L_52 ,
V_271 , F_66 ( V_162 ) ) ;
goto V_450;
}
V_494 = V_242 [ 1 ] & 0x1f ;
if ( V_494 != V_496 ) {
F_74 ( V_153 -> V_13 , L_53 , V_494 ) ;
V_244 = 1 ;
goto V_247;
}
if ( ( V_271 / 512 ) > 0xffff || V_271 < 512 || ( V_271 % 512 ) ) {
F_74 ( V_153 -> V_13 , L_54 , V_271 ) ;
goto V_450;
}
V_278 = V_271 / 512 ;
V_495 = V_242 [ 14 ] & 0xbf ;
if ( F_100 ( V_153 -> V_13 ) &&
F_202 ( V_153 -> V_13 ) ) {
V_75 -> V_250 = V_400 ;
V_75 -> V_167 = V_497 ;
V_75 -> V_208 = V_498 & 0x1f ;
V_75 -> V_203 = V_153 -> V_155 << 3 ;
V_75 -> V_169 = V_278 & 0xff ;
V_75 -> V_403 = ( V_278 >> 8 ) & 0xff ;
V_75 -> V_453 = V_499 | ( V_495 << 8 ) ;
} else {
V_75 -> V_167 = V_500 ;
V_75 -> V_169 = V_499 ;
V_75 -> V_250 = V_398 ;
V_75 -> V_403 = V_495 ;
V_75 -> V_208 = ( V_278 >> 8 ) & 0xff ;
V_75 -> V_203 = V_278 & 0xff ;
}
V_75 -> V_1 = V_254 ;
V_75 -> V_206 = ( V_212 >> 16 ) & 0xff ;
V_75 -> V_205 = ( V_212 >> 8 ) & 0xff ;
V_75 -> V_204 = V_212 & 0xff ;
V_75 -> V_211 = ( V_212 >> 40 ) & 0xff ;
V_75 -> V_210 = ( V_212 >> 32 ) & 0xff ;
V_75 -> V_209 = ( V_212 >> 24 ) & 0xff ;
V_75 -> V_16 |= V_249 | V_248 | V_207 ;
V_153 -> V_16 |= V_436 ;
F_65 ( V_153 ) ;
V_153 -> V_303 = F_192 ;
return 0 ;
V_247:
F_31 ( V_153 -> V_13 , V_162 , V_244 , V_245 ) ;
return 1 ;
V_450:
F_26 ( V_153 -> V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
}
static unsigned int F_203 ( struct V_152 * V_153 )
{
struct V_74 * V_75 = & V_153 -> V_75 ;
struct V_63 * V_162 = V_153 -> V_156 ;
struct V_12 * V_13 = V_153 -> V_13 ;
const T_3 * V_242 = V_162 -> V_243 ;
T_3 V_501 , V_494 ;
T_4 V_212 ;
T_8 V_271 ;
T_5 V_244 = ( T_5 ) - 1 ;
if ( F_20 ( V_162 -> V_246 < 16 ) ) {
V_244 = 15 ;
goto V_247;
}
V_494 = V_242 [ 1 ] & 0x1f ;
if ( ( V_494 != V_502 ) && ( V_494 != V_503 ) &&
( V_494 != V_504 ) && ( V_494 != V_505 ) ) {
V_244 = 1 ;
goto V_247;
}
F_108 ( V_242 , & V_212 , & V_271 ) ;
if ( V_271 ) {
goto V_450;
}
if ( V_212 > V_13 -> V_101 )
goto V_275;
V_501 = V_242 [ 14 ] & 0x1 ;
if ( F_100 ( V_153 -> V_13 ) &&
F_204 ( V_153 -> V_13 ) ) {
V_75 -> V_250 = V_402 ;
V_75 -> V_167 = V_506 ;
V_75 -> V_169 = V_507 ;
V_75 -> V_203 = V_153 -> V_155 << 3 ;
V_75 -> V_453 = V_494 | ( ( T_5 ) V_501 << 8 ) ;
} else {
V_75 -> V_250 = V_251 ;
V_75 -> V_167 = V_508 ;
V_75 -> V_169 = V_494 ;
V_75 -> V_403 = V_501 ;
}
V_75 -> V_206 = ( V_212 >> 16 ) & 0xff ;
V_75 -> V_205 = ( V_212 >> 8 ) & 0xff ;
V_75 -> V_204 = V_212 & 0xff ;
V_75 -> V_211 = ( V_212 >> 40 ) & 0xff ;
V_75 -> V_210 = ( V_212 >> 32 ) & 0xff ;
V_75 -> V_209 = ( V_212 >> 24 ) & 0xff ;
V_75 -> V_1 = V_254 ;
V_75 -> V_16 |= V_249 | V_248 | V_207 ;
return 0 ;
V_247:
F_31 ( V_153 -> V_13 , V_162 , V_244 , 0xff ) ;
return 1 ;
V_275:
F_26 ( V_153 -> V_13 , V_162 , V_81 , 0x21 , 0x00 ) ;
return 1 ;
V_450:
F_26 ( V_153 -> V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
}
static int F_205 ( struct V_152 * V_153 ,
const T_3 * V_4 , int V_45 , T_5 * V_244 )
{
struct V_74 * V_75 = & V_153 -> V_75 ;
struct V_12 * V_13 = V_153 -> V_13 ;
T_3 V_509 [ V_510 ] ;
T_3 V_511 ;
int V_188 ;
if ( V_45 != V_510 - 2 ) {
if ( V_45 < V_510 - 2 )
* V_244 = V_45 ;
else
* V_244 = V_510 - 2 ;
return - V_20 ;
}
V_511 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_150 ( V_13 -> V_108 , V_509 , false ) ;
for ( V_188 = 0 ; V_188 < V_510 - 2 ; V_188 ++ ) {
if ( V_188 == 0 )
continue;
if ( V_509 [ V_188 + 2 ] != V_4 [ V_188 ] ) {
* V_244 = V_188 ;
return - V_20 ;
}
}
V_75 -> V_16 |= V_248 | V_249 ;
V_75 -> V_250 = V_251 ;
V_75 -> V_203 = 0 ;
V_75 -> V_167 = V_439 ;
V_75 -> V_169 = V_511 ? V_512 : V_513 ;
return 0 ;
}
static int F_206 ( struct V_152 * V_153 ,
const T_3 * V_4 , int V_45 , T_5 * V_244 )
{
struct V_12 * V_13 = V_153 -> V_13 ;
T_3 V_509 [ V_514 ] ;
T_3 V_68 ;
int V_188 ;
if ( V_45 != V_514 - 2 ) {
if ( V_45 < V_514 - 2 )
* V_244 = V_45 ;
else
* V_244 = V_514 - 2 ;
return - V_20 ;
}
V_68 = V_4 [ 0 ] & ( 1 << 2 ) ;
F_153 ( V_13 , V_509 , false ) ;
for ( V_188 = 0 ; V_188 < V_514 - 2 ; V_188 ++ ) {
if ( V_188 == 0 )
continue;
if ( V_509 [ 2 + V_188 ] != V_4 [ V_188 ] ) {
* V_244 = V_188 ;
return - V_20 ;
}
}
if ( V_68 & ( 1 << 2 ) )
V_13 -> V_16 |= V_69 ;
else
V_13 -> V_16 &= ~ V_69 ;
return 0 ;
}
static unsigned int F_207 ( struct V_152 * V_153 )
{
struct V_63 * V_162 = V_153 -> V_156 ;
const T_3 * V_242 = V_162 -> V_243 ;
const T_3 * V_352 ;
T_3 V_354 , V_355 ;
unsigned V_358 , V_515 , V_516 , V_517 ;
int V_45 ;
T_5 V_244 = ( T_5 ) - 1 ;
T_3 V_245 = 0xff ;
F_106 ( L_32 ) ;
V_358 = ( V_242 [ 0 ] == V_470 ) ;
if ( V_358 ) {
if ( V_162 -> V_246 < 5 ) {
V_244 = 4 ;
goto V_247;
}
V_45 = V_242 [ 4 ] ;
V_516 = 4 ;
} else {
if ( V_162 -> V_246 < 9 ) {
V_244 = 8 ;
goto V_247;
}
V_45 = ( V_242 [ 7 ] << 8 ) + V_242 [ 8 ] ;
V_516 = 8 ;
}
if ( ( V_242 [ 1 ] & 0x11 ) != 0x10 ) {
V_244 = 1 ;
V_245 = ( V_242 [ 1 ] & 0x01 ) ? 1 : 5 ;
goto V_247;
}
if ( ! F_64 ( V_162 ) || F_63 ( V_162 ) -> V_487 < V_45 )
goto V_450;
V_352 = F_208 ( F_209 ( F_63 ( V_162 ) ) ) ;
if ( V_45 < V_516 )
goto V_450;
if ( V_358 )
V_517 = V_352 [ 3 ] ;
else
V_517 = ( V_352 [ 6 ] << 8 ) + V_352 [ 7 ] ;
V_45 -= V_516 ;
V_352 += V_516 ;
if ( V_45 < V_517 )
goto V_450;
if ( V_517 != 0 && V_517 != 8 ) {
V_244 = ( V_358 ) ? 3 : 6 ;
V_244 += V_517 + V_516 ;
goto V_518;
}
V_45 -= V_517 ;
V_352 += V_517 ;
if ( V_45 == 0 )
goto V_259;
V_354 = V_352 [ 0 ] & 0x3f ;
if ( V_352 [ 0 ] & 0x40 ) {
if ( V_45 < 4 )
goto V_450;
V_355 = V_352 [ 1 ] ;
V_515 = ( V_352 [ 2 ] << 8 ) | V_352 [ 3 ] ;
V_352 += 4 ;
V_45 -= 4 ;
} else {
if ( V_45 < 2 )
goto V_450;
V_355 = 0 ;
V_515 = V_352 [ 1 ] ;
V_352 += 2 ;
V_45 -= 2 ;
}
if ( V_355 && ( V_355 != V_362 ) ) {
V_244 = ( V_352 [ 0 ] & 0x40 ) ? 1 : 0 ;
V_244 += V_516 + V_517 ;
goto V_518;
}
if ( V_515 > V_45 )
goto V_450;
switch ( V_354 ) {
case V_364 :
if ( F_205 ( V_153 , V_352 , V_515 , & V_244 ) < 0 ) {
V_244 += V_516 + V_517 ;
goto V_518;
}
break;
case V_365 :
if ( F_206 ( V_153 , V_352 , V_515 , & V_244 ) < 0 ) {
V_244 += V_516 + V_517 ;
goto V_518;
} else {
goto V_259;
}
break;
default:
V_244 = V_517 + V_516 ;
goto V_518;
}
if ( V_45 > V_515 )
goto V_518;
return 0 ;
V_247:
F_31 ( V_153 -> V_13 , V_162 , V_244 , V_245 ) ;
return 1 ;
V_518:
F_33 ( V_153 -> V_13 , V_162 , V_244 ) ;
return 1 ;
V_450:
F_26 ( V_153 -> V_13 , V_162 , V_81 , 0x1a , 0x0 ) ;
return 1 ;
V_259:
V_162 -> V_70 = V_262 ;
return 1 ;
}
static inline T_9 F_210 ( struct V_12 * V_13 , T_3 V_64 )
{
switch ( V_64 ) {
case V_291 :
case V_289 :
case V_292 :
case V_286 :
case V_285 :
case V_287 :
return F_113 ;
case V_473 :
return F_188 ;
case V_463 :
if ( F_211 ( V_13 ) )
return F_104 ;
break;
case V_272 :
case V_273 :
return F_109 ;
case V_295 :
case V_132 :
return F_178 ;
case V_470 :
case V_471 :
return F_207 ;
break;
case V_474 :
return F_201 ;
case V_475 :
return F_203 ;
case V_472 :
return F_102 ;
}
return NULL ;
}
static inline void F_212 ( struct V_8 * V_9 ,
struct V_63 * V_64 )
{
#ifdef F_213
struct V_28 * V_117 = V_64 -> V_1 ;
F_112 ( L_55 ,
V_9 -> V_202 ,
V_117 -> V_395 , V_117 -> V_108 , V_117 -> V_396 ,
V_64 -> V_243 ) ;
#endif
}
static inline int F_214 ( struct V_63 * V_162 ,
struct V_12 * V_13 )
{
T_3 V_519 = V_162 -> V_243 [ 0 ] ;
T_9 V_297 ;
int V_33 = 0 ;
if ( V_13 -> V_49 == V_50 || V_13 -> V_49 == V_51 ) {
if ( F_20 ( ! V_162 -> V_246 || V_162 -> V_246 > V_13 -> V_379 ) )
goto V_520;
V_297 = F_210 ( V_13 , V_519 ) ;
} else {
if ( F_20 ( ! V_162 -> V_246 ) )
goto V_520;
V_297 = NULL ;
if ( F_77 ( ( V_519 != V_132 ) || ! V_521 ) ) {
int V_45 = F_215 ( V_519 ) ;
if ( F_20 ( V_45 > V_162 -> V_246 || V_45 > V_13 -> V_379 ) )
goto V_520;
V_297 = F_171 ;
} else {
if ( F_20 ( V_162 -> V_246 > 16 ) )
goto V_520;
V_297 = F_210 ( V_13 , V_519 ) ;
}
}
if ( V_297 )
V_33 = F_121 ( V_13 , V_162 , V_297 ) ;
else
F_216 ( V_13 , V_162 ) ;
return V_33 ;
V_520:
F_112 ( L_56 ,
V_162 -> V_246 , V_519 , V_13 -> V_379 ) ;
V_162 -> V_70 = V_307 << 16 ;
V_162 -> V_96 ( V_162 ) ;
return 0 ;
}
int F_217 ( struct V_6 * V_7 , struct V_63 * V_64 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_28 * V_117 = V_64 -> V_1 ;
int V_33 = 0 ;
unsigned long V_522 ;
V_9 = F_3 ( V_7 ) ;
F_5 ( V_9 -> V_21 , V_522 ) ;
F_212 ( V_9 , V_64 ) ;
V_13 = F_14 ( V_9 , V_117 ) ;
if ( F_77 ( V_13 ) )
V_33 = F_214 ( V_64 , V_13 ) ;
else {
V_64 -> V_70 = ( V_523 << 16 ) ;
V_64 -> V_96 ( V_64 ) ;
}
F_9 ( V_9 -> V_21 , V_522 ) ;
return V_33 ;
}
void F_216 ( struct V_12 * V_13 , struct V_63 * V_64 )
{
struct V_316 args ;
const T_3 * V_156 = V_64 -> V_243 ;
T_3 V_524 ;
args . V_13 = V_13 ;
args . V_108 = V_13 -> V_108 ;
args . V_64 = V_64 ;
args . F_118 = V_64 -> V_96 ;
switch( V_156 [ 0 ] ) {
case V_387 :
if ( V_156 [ 1 ] & 2 )
F_40 ( V_13 , V_64 , 1 ) ;
else if ( ( V_156 [ 1 ] & 1 ) == 0 )
F_218 ( & args , F_128 ) ;
else switch ( V_156 [ 2 ] ) {
case 0x00 :
F_218 ( & args , F_131 ) ;
break;
case 0x80 :
F_218 ( & args , F_132 ) ;
break;
case 0x83 :
F_218 ( & args , F_133 ) ;
break;
case 0x89 :
F_218 ( & args , F_135 ) ;
break;
case 0xb0 :
F_218 ( & args , F_137 ) ;
break;
case 0xb1 :
F_218 ( & args , F_143 ) ;
break;
case 0xb2 :
F_218 ( & args , F_146 ) ;
break;
case 0xb6 :
if ( V_13 -> V_16 & V_326 ) {
F_218 ( & args , F_147 ) ;
break;
}
default:
F_40 ( V_13 , V_64 , 2 ) ;
break;
}
break;
case V_360 :
case V_460 :
F_218 ( & args , F_158 ) ;
break;
case V_373 :
F_218 ( & args , F_159 ) ;
break;
case V_461 :
if ( ( V_156 [ 1 ] & 0x1f ) == V_525 )
F_218 ( & args , F_159 ) ;
else
F_40 ( V_13 , V_64 , 1 ) ;
break;
case V_462 :
F_218 ( & args , F_163 ) ;
break;
case V_380 :
F_26 ( V_13 , V_64 , 0 , 0 , 0 ) ;
V_64 -> V_70 = ( V_71 << 24 ) ;
V_64 -> V_96 ( V_64 ) ;
break;
case V_463 :
case V_464 :
case V_465 :
case V_466 :
case V_467 :
F_218 ( & args , F_148 ) ;
break;
case V_468 :
V_524 = V_156 [ 1 ] & ~ ( 1 << 3 ) ;
if ( ( V_524 == 0x4 ) && ( ! V_156 [ 3 ] ) && ( ! V_156 [ 4 ] ) )
F_218 ( & args , F_148 ) ;
else
F_40 ( V_13 , V_64 , 1 ) ;
break;
case V_469 :
if ( V_156 [ 1 ] == V_526 )
F_218 ( & args , F_191 ) ;
else
F_40 ( V_13 , V_64 , 1 ) ;
break;
default:
F_26 ( V_13 , V_64 , V_81 , 0x20 , 0x0 ) ;
V_64 -> V_96 ( V_64 ) ;
break;
}
}
int F_219 ( struct V_527 * V_34 , struct V_528 * V_529 )
{
int V_188 , V_33 ;
for ( V_188 = 0 ; V_188 < V_34 -> V_530 ; V_188 ++ ) {
struct V_8 * V_9 = V_34 -> V_531 [ V_188 ] ;
struct V_6 * V_7 ;
V_33 = - V_127 ;
V_7 = F_220 ( V_529 , sizeof( struct V_8 * ) ) ;
if ( ! V_7 )
goto V_532;
V_7 -> V_533 = 1 ;
* (struct V_8 * * ) & V_7 -> V_534 [ 0 ] = V_9 ;
V_9 -> V_535 = V_7 ;
V_7 -> V_536 = V_537 ;
V_7 -> V_538 = V_9 -> V_202 ;
V_7 -> V_539 = 16 ;
V_7 -> V_540 = 1 ;
V_7 -> V_541 = 1 ;
V_7 -> V_542 = 16 ;
V_7 -> V_543 = 1 ;
V_33 = F_221 ( V_9 -> V_535 ,
& V_9 -> V_544 , V_9 -> V_34 -> V_13 ) ;
if ( V_33 )
goto V_545;
}
return 0 ;
V_545:
F_222 ( V_34 -> V_531 [ V_188 ] -> V_535 ) ;
V_532:
while ( -- V_188 >= 0 ) {
struct V_6 * V_7 = V_34 -> V_531 [ V_188 ] -> V_535 ;
F_223 ( V_7 ) ;
F_222 ( V_7 ) ;
}
return V_33 ;
}
void F_224 ( struct V_8 * V_9 , int V_546 )
{
int V_547 = 5 ;
struct V_12 * V_548 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_549:
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 ;
int V_395 = 0 , V_108 = 0 ;
if ( V_13 -> V_29 )
continue;
if ( F_225 ( V_11 ) )
V_108 = V_13 -> V_43 ;
else
V_395 = V_11 -> V_550 ;
V_29 = F_226 ( V_9 -> V_535 , V_395 , V_108 , 0 ,
NULL ) ;
if ( ! F_227 ( V_29 ) ) {
V_13 -> V_29 = V_29 ;
F_228 ( V_29 ) ;
} else {
V_13 -> V_29 = NULL ;
}
}
}
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
if ( ! V_13 -> V_29 )
goto V_551;
}
}
V_551:
if ( ! V_11 )
return;
if ( V_546 ) {
if ( V_13 != V_548 ) {
F_229 ( 100 ) ;
V_548 = V_13 ;
goto V_549;
}
if ( -- V_547 ) {
F_229 ( 100 ) ;
goto V_549;
}
F_230 ( V_9 ,
L_57 ) ;
}
F_231 ( V_552 , & V_9 -> V_553 ,
F_232 ( V_134 ) ) ;
}
int F_233 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 ) {
F_234 ( V_13 -> V_29 , V_554 ) ;
return 1 ;
}
return 0 ;
}
static void F_235 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = V_13 -> V_11 -> V_9 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
F_236 ( & V_9 -> V_535 -> V_555 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_29 = V_13 -> V_29 ;
V_13 -> V_29 = NULL ;
if ( V_29 ) {
if ( F_237 ( V_29 ) == 0 ) {
F_234 ( V_29 , V_554 ) ;
} else {
F_182 ( 1 ) ;
V_29 = NULL ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_238 ( & V_9 -> V_535 -> V_555 ) ;
if ( V_29 ) {
F_162 ( V_13 , L_58 ,
F_239 ( & V_29 -> V_556 ) ) ;
F_240 ( V_29 ) ;
F_228 ( V_29 ) ;
}
}
static void F_241 ( struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_9 ;
struct V_12 * V_13 ;
F_7 (dev, link, ALL) {
unsigned long V_16 ;
if ( ! ( V_13 -> V_16 & V_557 ) )
continue;
F_5 ( V_9 -> V_21 , V_16 ) ;
V_13 -> V_16 &= ~ V_557 ;
F_9 ( V_9 -> V_21 , V_16 ) ;
if ( F_242 ( V_13 ) )
F_243 ( V_13 ) ;
F_235 ( V_13 ) ;
}
}
void F_244 ( struct V_12 * V_13 )
{
if ( V_13 -> V_29 )
F_245 ( V_13 -> V_29 , V_231 ,
V_558 ) ;
}
void F_246 ( struct V_559 * V_560 )
{
struct V_8 * V_9 =
F_247 ( V_560 , struct V_8 , V_553 . V_560 ) ;
int V_188 ;
if ( V_9 -> V_39 & V_561 ) {
F_112 ( L_59 ) ;
return;
}
#ifdef F_248
while ( V_562 )
F_229 ( 10 ) ;
#endif
F_112 ( L_32 ) ;
F_236 ( & V_9 -> V_563 ) ;
F_241 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_394 )
for ( V_188 = 0 ; V_188 < V_564 ; V_188 ++ )
F_241 ( & V_9 -> V_394 [ V_188 ] ) ;
F_224 ( V_9 , 0 ) ;
F_238 ( & V_9 -> V_563 ) ;
F_112 ( L_34 ) ;
}
int F_249 ( struct V_6 * V_7 , unsigned int V_395 ,
unsigned int V_108 , T_4 V_396 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_16 ;
int V_43 , V_33 = 0 ;
if ( ! V_9 -> V_82 -> V_200 )
return - V_24 ;
if ( V_396 != V_565 && V_396 )
return - V_20 ;
if ( ! F_175 ( V_9 ) ) {
if ( V_395 != V_565 && V_395 )
return - V_20 ;
V_43 = V_108 ;
} else {
if ( V_108 != V_565 && V_108 )
return - V_20 ;
V_43 = V_395 ;
}
F_5 ( V_9 -> V_21 , V_16 ) ;
if ( V_43 == V_565 ) {
struct V_10 * V_11 ;
F_6 (link, ap, EDGE) {
struct V_566 * V_567 = & V_11 -> V_52 ;
V_567 -> V_568 |= V_569 ;
V_567 -> V_58 |= V_104 ;
}
} else {
struct V_12 * V_13 = F_174 ( V_9 , V_43 ) ;
if ( V_13 ) {
struct V_566 * V_567 = & V_13 -> V_11 -> V_52 ;
V_567 -> V_568 |= 1 << V_13 -> V_43 ;
V_567 -> V_58 |= V_104 ;
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
void F_250 ( struct V_559 * V_560 )
{
struct V_8 * V_9 =
F_247 ( V_560 , struct V_8 , V_570 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_16 ;
F_236 ( & V_9 -> V_563 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
F_6 (link, ap, EDGE) {
F_7 (dev, link, ENABLED) {
struct V_28 * V_29 = V_13 -> V_29 ;
if ( ! V_29 )
continue;
if ( F_237 ( V_29 ) )
continue;
F_9 ( V_9 -> V_21 , V_16 ) ;
F_251 ( & ( V_29 -> V_556 ) ) ;
F_228 ( V_29 ) ;
F_5 ( V_9 -> V_21 , V_16 ) ;
}
}
F_9 ( V_9 -> V_21 , V_16 ) ;
F_238 ( & V_9 -> V_563 ) ;
}
struct V_8 * F_252 ( struct V_527 * V_34 ,
struct V_571 * V_572 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_253 ( V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_573 = 0 ;
V_9 -> V_21 = & V_34 -> V_21 ;
V_9 -> V_574 = V_572 -> V_574 ;
V_9 -> V_575 = V_572 -> V_575 ;
V_9 -> V_576 = V_572 -> V_576 ;
V_9 -> V_16 |= V_572 -> V_16 ;
V_9 -> V_82 = V_572 -> V_577 ;
V_9 -> V_578 = V_579 ;
return V_9 ;
}
int F_254 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_82 -> V_200 )
V_9 -> V_39 &= ~ V_580 ;
return 0 ;
}
void F_255 ( struct V_8 * V_9 )
{
}
void F_256 ( struct V_8 * V_9 )
{
F_257 ( V_9 ) ;
}
int F_258 ( struct V_8 * V_9 )
{
return F_259 ( V_9 ) ;
}
int F_260 ( struct V_8 * V_9 )
{
int V_33 = V_9 -> V_82 -> V_581 ( V_9 ) ;
if ( V_33 )
return V_33 ;
V_9 -> V_202 = F_261 ( & V_582 ) ;
return 0 ;
}
void F_262 ( struct V_8 * V_9 )
{
if ( V_9 -> V_82 -> V_583 )
V_9 -> V_82 -> V_583 ( V_9 ) ;
F_54 ( V_9 ) ;
}
int F_263 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
F_75 ( V_29 ) ;
F_82 ( V_29 , V_9 -> V_11 . V_1 ) ;
return 0 ;
}
int F_264 ( struct V_63 * V_64 , struct V_8 * V_9 )
{
int V_33 = 0 ;
F_212 ( V_9 , V_64 ) ;
if ( F_77 ( F_99 ( V_9 -> V_11 . V_1 ) ) )
V_33 = F_214 ( V_64 , V_9 -> V_11 . V_1 ) ;
else {
V_64 -> V_70 = ( V_523 << 16 ) ;
V_64 -> V_96 ( V_64 ) ;
}
return V_33 ;
}
int F_265 ( struct V_8 * V_9 )
{
unsigned int V_584 = V_9 -> V_34 -> V_585 ;
unsigned int V_188 , V_155 ;
for ( V_188 = 0 , V_155 = V_9 -> V_586 + 1 ; V_188 < V_584 ; V_188 ++ , V_155 ++ ) {
V_155 = V_155 < V_584 ? V_155 : 0 ;
if ( V_155 == V_587 )
continue;
if ( ! F_266 ( V_155 , & V_9 -> V_588 ) ) {
V_9 -> V_586 = V_155 ;
return V_155 ;
}
}
return - 1 ;
}
void F_267 ( unsigned int V_155 , struct V_8 * V_9 )
{
F_268 ( V_155 , & V_9 -> V_588 ) ;
}
