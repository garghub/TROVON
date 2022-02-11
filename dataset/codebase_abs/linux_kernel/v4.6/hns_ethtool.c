static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = V_4 -> V_6 ;
struct V_7 * V_8 ;
assert ( V_4 && V_4 -> V_9 ) ;
V_8 = V_4 -> V_9 ;
if ( V_4 -> V_10 ) {
if ( ! F_3 ( V_4 -> V_10 ) )
V_5 = V_4 -> V_10 -> V_6 ;
else
V_5 = 0 ;
}
if ( V_8 -> V_11 && V_8 -> V_11 -> V_12 && V_8 -> V_11 -> V_12 -> V_13 )
V_5 = V_5 && V_8 -> V_11 -> V_12 -> V_13 ( V_8 ) ;
else
V_5 = 0 ;
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_16 , V_17 , V_18 , V_19 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_4 -> V_10 ;
if ( ! V_21 || ! V_21 -> V_22 . V_23 ) {
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = V_25 ;
return;
}
F_5 ( V_21 , V_27 , V_28 ) ;
V_18 = F_6 ( V_21 , V_29 ) ;
V_16 = F_7 ( V_18 , V_30 , V_31 ) ;
V_18 = F_6 ( V_21 , V_32 ) ;
V_17 = F_8 ( V_18 , V_33 ) ;
V_19 = F_8 ( V_18 , V_34 ) ;
F_5 ( V_21 , V_27 , V_35 ) ;
switch ( V_16 ) {
case 0x0 :
V_15 -> V_24 = V_36 ;
break;
case 0x1 :
V_15 -> V_24 = V_37 ;
break;
case 0x3 :
V_15 -> V_24 = V_38 ;
break;
default:
V_15 -> V_24 = V_25 ;
break;
}
if ( ! V_19 )
V_15 -> V_26 = V_25 ;
else if ( V_17 )
V_15 -> V_26 = V_37 ;
else
V_15 -> V_26 = V_36 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_5 ;
int V_39 ;
T_2 V_40 ;
T_3 V_41 ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_42 ;
V_8 = V_4 -> V_9 ;
if ( ! V_8 -> V_11 || ! V_8 -> V_11 -> V_12 || ! V_8 -> V_11 -> V_12 -> V_43 )
return - V_42 ;
V_39 = V_8 -> V_11 -> V_12 -> V_43 ( V_8 , NULL , & V_41 , & V_40 ) ;
if ( V_39 < 0 ) {
F_10 ( V_2 , L_1 , V_44 ) ;
return - V_45 ;
}
V_15 -> V_46 = false ;
F_11 ( V_15 , V_41 ) ;
V_15 -> V_40 = V_40 ;
if ( V_4 -> V_10 )
( void ) F_12 ( V_4 -> V_10 , V_15 ) ;
V_5 = F_1 ( V_2 ) ;
if ( ! V_5 ) {
F_11 ( V_15 , ( T_1 ) V_47 ) ;
V_15 -> V_40 = V_48 ;
}
if ( V_15 -> V_46 )
V_15 -> V_49 |= V_50 ;
V_15 -> V_51 |= V_8 -> V_52 ;
if ( V_8 -> V_53 == V_54 ) {
V_15 -> V_51 |= V_55 ;
V_15 -> V_49 |= V_56 ;
} else if ( V_8 -> V_53 == V_57 ) {
V_15 -> V_51 |= V_58 ;
V_15 -> V_49 |= V_59 ;
}
if ( V_8 -> V_60 == V_61 ) {
V_15 -> V_62 = V_63 ;
V_15 -> V_51 |= V_64 ;
} else {
V_15 -> V_62 = V_65 ;
}
V_15 -> V_66 = V_67 ;
V_15 -> V_68 = ( V_69 | V_70 ) ;
F_4 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_41 ;
if ( ! F_14 ( V_2 ) )
return - V_42 ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_9 -> V_11 ||
! V_4 -> V_9 -> V_11 -> V_12 )
return - V_71 ;
V_8 = V_4 -> V_9 ;
V_41 = F_15 ( V_15 ) ;
if ( V_8 -> V_53 == V_57 ) {
if ( V_15 -> V_46 == V_72 || V_41 != V_73 ||
V_15 -> V_40 != V_74 )
return - V_45 ;
} else if ( V_8 -> V_53 == V_54 ) {
if ( ! V_4 -> V_10 && V_15 -> V_46 == V_72 )
return - V_45 ;
if ( V_41 == V_75 && V_15 -> V_40 == V_76 )
return - V_45 ;
if ( V_4 -> V_10 )
return F_16 ( V_4 -> V_10 , V_15 ) ;
if ( ( V_41 != V_77 && V_41 != V_78 &&
V_41 != V_75 ) || ( V_15 -> V_40 != V_76 &&
V_15 -> V_40 != V_74 ) )
return - V_45 ;
} else {
F_10 ( V_2 , L_2 ) ;
return - V_79 ;
}
if ( V_8 -> V_11 -> V_12 -> V_80 ) {
V_8 -> V_11 -> V_12 -> V_80 ( V_8 , ( int ) V_41 , V_15 -> V_40 ) ;
return 0 ;
}
F_10 ( V_2 , L_2 ) ;
return - V_79 ;
}
static int F_17 ( struct V_20 * V_21 , T_2 V_81 )
{
#define F_18 0
#define F_19 BIT(14)
T_3 V_82 = 0 ;
if ( V_21 -> V_83 )
return - V_79 ;
if ( V_81 ) {
F_5 ( V_21 , V_27 , 2 ) ;
F_5 ( V_21 , 21 , 0x1046 ) ;
F_5 ( V_21 , 9 , 0x1F00 ) ;
F_5 ( V_21 , 0 , 0x9140 ) ;
F_5 ( V_21 , 0 , 0x9140 ) ;
F_5 ( V_21 , 22 , 0xFA ) ;
F_5 ( V_21 , 1 , 0x418 ) ;
F_5 ( V_21 , 7 , 0x20C ) ;
F_5 ( V_21 , 22 , 0 ) ;
V_82 = F_6 ( V_21 , F_18 ) ;
V_82 |= F_19 ;
F_5 ( V_21 , F_18 , V_82 ) ;
} else {
F_5 ( V_21 , 22 , 0xFA ) ;
F_5 ( V_21 , 1 , 0x400 ) ;
F_5 ( V_21 , 7 , 0x200 ) ;
F_5 ( V_21 , 22 , 0 ) ;
V_82 = F_6 ( V_21 , F_18 ) ;
V_82 &= ~ F_19 ;
F_5 ( V_21 , F_18 , V_82 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_84 ,
enum V_85 V_86 )
{
int V_39 = 0 ;
struct V_3 * V_4 = F_2 ( V_84 ) ;
struct V_20 * V_21 = V_4 -> V_10 ;
struct V_7 * V_8 = V_4 -> V_9 ;
switch ( V_86 ) {
case V_87 :
if ( ( V_21 ) && ( ! V_21 -> V_83 ) ) {
V_39 = F_17 ( V_21 , 0x1 ) ;
V_39 |= V_8 -> V_11 -> V_12 -> V_88 ( V_8 , V_86 , 0x1 ) ;
}
break;
case V_89 :
if ( ( V_8 -> V_11 -> V_12 -> V_88 ) &&
( V_4 -> V_9 -> V_53 != V_57 ) )
V_39 = V_8 -> V_11 -> V_12 -> V_88 ( V_8 , V_86 , 0x1 ) ;
break;
case V_90 :
if ( V_8 -> V_11 -> V_12 -> V_88 )
V_39 = V_8 -> V_11 -> V_12 -> V_88 ( V_8 , V_86 , 0x1 ) ;
break;
case V_91 :
if ( ( V_21 ) && ( ! V_21 -> V_83 ) )
V_39 |= F_17 ( V_21 , 0x0 ) ;
if ( V_8 -> V_11 -> V_12 -> V_88 ) {
if ( V_4 -> V_9 -> V_53 != V_57 )
V_39 |= V_8 -> V_11 -> V_12 -> V_88 ( V_8 ,
V_89 , 0x0 ) ;
V_39 |= V_8 -> V_11 -> V_12 -> V_88 ( V_8 ,
V_90 , 0x0 ) ;
}
break;
default:
V_39 = - V_45 ;
break;
}
return V_39 ;
}
static int F_21 ( struct V_1 * V_84 ,
enum V_85 V_92 )
{
struct V_3 * V_4 = F_2 ( V_84 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_41 , V_40 ;
int V_39 ;
F_22 ( V_84 ) ;
if ( V_4 -> V_10 ) {
F_23 ( V_4 -> V_10 ) ;
F_24 ( 100 ) ;
V_39 = F_25 ( V_84 , V_8 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_20 ( V_84 , V_92 ) ;
if ( V_39 )
return V_39 ;
F_24 ( 100 ) ;
V_39 = V_8 -> V_11 -> V_12 -> V_93 ? V_8 -> V_11 -> V_12 -> V_93 ( V_8 ) : 0 ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_10 )
F_26 ( V_4 -> V_10 ) ;
if ( V_4 -> V_9 -> V_53 != V_57 )
V_41 = 1000 ;
else
V_41 = 10000 ;
V_40 = 1 ;
V_8 -> V_11 -> V_12 -> V_80 ( V_8 , V_41 , V_40 ) ;
return 0 ;
}
static void F_27 ( struct V_94 * V_95 ,
struct V_96 * V_97 )
{
struct V_1 * V_84 ;
struct V_3 * V_4 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_96 * V_102 ;
unsigned int V_103 ;
int V_104 ;
T_1 V_105 ;
char V_106 [ 33 ] ;
if ( ! V_95 ) {
V_84 = V_97 -> V_11 ;
V_4 = F_2 ( V_84 ) ;
V_103 = V_97 -> V_107 ;
memset ( V_97 -> V_108 , 0xFF , V_103 ) ;
if ( ( ! F_28 ( V_4 -> V_109 ) ) &&
( V_4 -> V_9 -> V_60 == V_61 ) ) {
memcpy ( V_97 -> V_108 , V_84 -> V_110 , 6 ) ;
V_97 -> V_108 [ 5 ] += 0x1f ;
}
V_103 &= ~ 1ul ;
memset ( & V_97 -> V_108 [ V_103 / 2 ] , 0xAA , V_103 / 2 - 1 ) ;
memset ( & V_97 -> V_108 [ V_103 / 2 + 10 ] , 0xBE ,
V_103 / 2 - 11 ) ;
memset ( & V_97 -> V_108 [ V_103 / 2 + 12 ] , 0xAF ,
V_103 / 2 - 13 ) ;
return;
}
V_99 = V_95 -> V_99 ;
V_84 = V_95 -> V_111 . V_11 ;
if ( F_29 ( V_99 ) ) {
V_101 = F_30 ( V_84 , V_95 -> V_112 ) ;
F_31 ( V_101 ) ;
return;
}
V_103 = V_97 -> V_107 ;
V_103 &= ~ 1ul ;
V_102 = F_32 ( V_97 , V_113 ) ;
F_33 ( V_97 ) ;
V_97 = V_102 ;
V_104 = 0 ;
if ( * ( V_97 -> V_108 + 10 ) == 0xFF ) {
if ( ( * ( V_97 -> V_108 + V_103 / 2 + 10 ) == 0xBE ) &&
( * ( V_97 -> V_108 + V_103 / 2 + 12 ) == 0xAF ) )
V_104 = 1 ;
}
if ( V_104 ) {
V_84 -> V_114 . V_115 ++ ;
V_84 -> V_114 . V_116 += V_97 -> V_107 ;
} else {
V_84 -> V_114 . V_117 ++ ;
for ( V_105 = 0 ; V_105 < V_97 -> V_107 ; V_105 ++ ) {
snprintf ( V_106 + V_105 % 16 * 2 , 3 ,
L_3 , * ( V_97 -> V_108 + V_105 ) ) ;
if ( ( V_105 % 16 == 15 ) || ( V_105 == V_97 -> V_107 - 1 ) )
F_34 ( L_4 , V_106 ) ;
}
}
F_33 ( V_97 ) ;
}
static int F_35 ( struct V_3 * V_4 ,
int V_118 , int V_119 , int V_120 )
{
int V_105 , V_39 ;
struct V_94 * V_95 ;
struct V_1 * V_84 = V_4 -> V_121 ;
unsigned long V_115 = V_84 -> V_114 . V_115 ;
unsigned long V_116 = V_84 -> V_114 . V_116 ;
unsigned long V_117 = V_84 -> V_114 . V_117 ;
for ( V_105 = V_118 ; V_105 <= V_119 ; V_105 ++ ) {
V_95 = & V_4 -> V_95 [ V_105 ] ;
( void ) V_95 -> V_122 ( V_95 ,
V_120 , F_27 ) ;
}
V_39 = ( int ) ( V_84 -> V_114 . V_115 - V_115 ) ;
V_84 -> V_114 . V_115 = V_115 ;
V_84 -> V_114 . V_116 = V_116 ;
V_84 -> V_114 . V_117 = V_117 ;
return V_39 ;
}
static int F_36 ( struct V_1 * V_84 ,
enum V_85 V_92 )
{
#define F_37 1
#define F_38 0
#define F_39 128
#define F_40 1
#define F_41 2
#define F_42 3
#define F_43 4
struct V_3 * V_4 = F_2 ( V_84 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_105 , V_123 , V_124 , V_125 , V_126 = 0 ;
unsigned int V_127 ;
T_4 V_128 ;
struct V_96 * V_97 ;
V_127 = F_39 ;
V_97 = F_44 ( V_127 , V_129 ) ;
if ( ! V_97 )
return F_40 ;
( void ) F_45 ( V_97 , V_127 ) ;
V_97 -> V_11 = V_84 ;
F_27 ( NULL , V_97 ) ;
V_97 -> V_130 = F_38 ;
V_124 = 1 ;
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ ) {
V_125 = 0 ;
for ( V_105 = 0 ; V_105 < F_37 ; V_105 ++ ) {
( void ) F_46 ( V_97 ) ;
V_128 = ( T_4 ) F_47 (
V_84 , V_97 ,
& F_48 ( V_4 , V_97 -> V_130 ) ) ;
if ( V_128 == V_131 )
V_125 ++ ;
else
break;
}
if ( V_125 != F_37 ) {
V_126 = F_41 ;
F_49 ( V_4 -> V_11 , L_5 ,
V_132 [ V_92 ] , V_125 ,
F_37 ) ;
break;
}
F_24 ( 100 ) ;
V_125 = F_35 ( V_4 ,
V_8 -> V_133 , V_8 -> V_133 * 2 - 1 ,
F_37 ) ;
if ( V_125 != F_37 ) {
V_126 = F_42 ;
F_49 ( V_4 -> V_11 , L_6 ,
V_132 [ V_92 ] , V_125 ,
F_37 ) ;
break;
}
( void ) F_35 ( V_4 ,
F_38 , F_38 ,
F_37 ) ;
}
F_50 ( V_97 ) ;
return V_126 ;
}
static int F_51 ( struct V_1 * V_84 )
{
struct V_3 * V_4 = F_2 ( V_84 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_39 ;
V_39 = F_20 ( V_84 , V_91 ) ;
if ( V_39 )
F_10 ( V_84 , L_7 ,
V_44 ,
V_39 ) ;
if ( V_4 -> V_10 )
F_52 ( V_4 -> V_10 ) ;
if ( V_8 -> V_11 -> V_12 -> V_134 )
V_8 -> V_11 -> V_12 -> V_134 ( V_8 ) ;
F_53 ( 10000 , 20000 ) ;
( void ) F_35 ( V_4 , 0 , V_8 -> V_133 - 1 , 256 ) ;
F_22 ( V_84 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_84 ,
struct V_135 * V_136 , T_5 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_84 ) ;
bool V_137 = F_14 ( V_84 ) ;
#define F_55 3
int V_138 [ F_55 ] [ 2 ] ;
int V_105 ;
int V_139 = 0 ;
V_138 [ 0 ] [ 0 ] = V_89 ;
V_138 [ 0 ] [ 1 ] = ( V_4 -> V_9 -> V_53 != V_57 ) ;
V_138 [ 1 ] [ 0 ] = V_90 ;
V_138 [ 1 ] [ 1 ] = 1 ;
V_138 [ 2 ] [ 0 ] = V_87 ;
V_138 [ 2 ] [ 1 ] = ( ( ! ! ( V_4 -> V_9 -> V_140 ) ) &&
( V_4 -> V_9 -> V_53 != V_57 ) ) ;
if ( V_136 -> V_141 == V_142 ) {
F_56 ( V_143 , & V_4 -> V_144 ) ;
if ( V_137 )
( void ) F_57 ( V_84 ) ;
for ( V_105 = 0 ; V_105 < F_55 ; V_105 ++ ) {
if ( ! V_138 [ V_105 ] [ 1 ] )
continue;
V_108 [ V_139 ] = F_21 ( V_84 ,
(enum V_85 ) V_138 [ V_105 ] [ 0 ] ) ;
if ( ! V_108 [ V_139 ] ) {
V_108 [ V_139 ] = F_36 (
V_84 , (enum V_85 ) V_138 [ V_105 ] [ 0 ] ) ;
( void ) F_51 ( V_84 ) ;
}
if ( V_108 [ V_139 ] )
V_136 -> V_141 |= V_145 ;
V_139 ++ ;
}
F_22 ( V_4 -> V_121 ) ;
F_58 ( V_143 , & V_4 -> V_144 ) ;
if ( V_137 )
( void ) F_59 ( V_84 ) ;
}
( void ) F_60 ( 4 * 1000 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
assert ( V_4 ) ;
strncpy ( V_147 -> V_148 , V_149 ,
sizeof( V_147 -> V_148 ) ) ;
V_147 -> V_148 [ sizeof( V_147 -> V_148 ) - 1 ] = '\0' ;
strncpy ( V_147 -> V_150 , V_151 , sizeof( V_147 -> V_150 ) ) ;
V_147 -> V_150 [ sizeof( V_147 -> V_150 ) - 1 ] = '\0' ;
strncpy ( V_147 -> V_152 , V_4 -> V_11 -> V_23 -> V_153 ,
sizeof( V_147 -> V_152 ) ) ;
V_147 -> V_152 [ V_154 - 1 ] = '\0' ;
strncpy ( V_147 -> V_155 , L_8 , V_156 ) ;
V_147 -> V_157 = 0 ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_160 * V_12 ;
struct V_161 * V_162 ;
T_1 V_163 = 0 ;
V_162 = V_4 -> V_9 -> V_164 [ 0 ] ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_165 )
V_12 -> V_165 ( V_162 , & V_163 ) ;
V_159 -> V_166 = V_163 ;
V_159 -> V_167 = V_163 ;
V_159 -> V_168 = V_162 -> V_169 . V_170 ;
V_159 -> V_171 = V_162 -> V_172 . V_170 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_173 * V_159 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_160 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_174 )
V_12 -> V_174 ( V_4 -> V_9 , & V_159 -> V_46 ,
& V_159 -> V_175 , & V_159 -> V_176 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_173 * V_159 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_160 * V_12 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_8 = V_4 -> V_9 ;
V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_177 )
return - V_42 ;
return V_12 -> V_177 ( V_4 -> V_9 , V_159 -> V_46 ,
V_159 -> V_175 , V_159 -> V_176 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_178 * V_179 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_160 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_179 -> V_180 = 1 ;
V_179 -> V_181 = 1 ;
if ( ( ! V_12 -> V_182 ) ||
( ! V_12 -> V_183 ) )
return - V_42 ;
V_12 -> V_182 ( V_4 -> V_9 ,
& V_179 -> V_184 ,
& V_179 -> V_185 ) ;
V_12 -> V_183 (
V_4 -> V_9 ,
& V_179 -> V_186 ,
& V_179 -> V_187 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_178 * V_179 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_160 * V_12 ;
int V_39 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_179 -> V_184 != V_179 -> V_185 )
return - V_45 ;
if ( V_179 -> V_187 != V_179 -> V_186 )
return - V_45 ;
if ( ( ! V_12 -> V_188 ) ||
( ! V_12 -> V_189 ) )
return - V_42 ;
V_39 = V_12 -> V_188 ( V_4 -> V_9 ,
V_179 -> V_185 ) ;
if ( V_39 )
return V_39 ;
V_39 = V_12 -> V_189 (
V_4 -> V_9 ,
V_179 -> V_187 ) ;
return V_39 ;
}
void F_67 ( struct V_1 * V_2 , struct V_190 * V_191 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_191 -> V_192 = V_4 -> V_9 -> V_133 ;
V_191 -> V_193 = V_4 -> V_9 -> V_133 ;
V_191 -> V_194 = V_4 -> V_9 -> V_133 ;
V_191 -> V_195 = V_4 -> V_9 -> V_133 ;
}
void F_68 ( struct V_1 * V_121 ,
struct V_196 * V_114 , T_5 * V_108 )
{
T_5 * V_197 = V_108 ;
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
const struct V_198 * V_199 ;
struct V_198 V_200 ;
if ( ! V_8 -> V_11 -> V_12 -> V_201 || ! V_8 -> V_11 -> V_12 -> V_202 ) {
F_10 ( V_121 , L_9 ) ;
return;
}
V_8 -> V_11 -> V_12 -> V_202 ( V_8 , & V_121 -> V_114 ) ;
V_199 = F_69 ( V_121 , & V_200 ) ;
V_197 [ 0 ] = V_199 -> V_115 ;
V_197 [ 1 ] = V_199 -> V_203 ;
V_197 [ 2 ] = V_199 -> V_116 ;
V_197 [ 3 ] = V_199 -> V_204 ;
V_197 [ 4 ] = V_199 -> V_205 ;
V_197 [ 5 ] = V_199 -> V_206 ;
V_197 [ 6 ] = V_199 -> V_207 ;
V_197 [ 7 ] = V_199 -> V_208 ;
V_197 [ 8 ] = V_199 -> V_209 ;
V_197 [ 9 ] = V_199 -> V_210 ;
V_197 [ 10 ] = V_199 -> V_211 ;
V_197 [ 11 ] = V_199 -> V_212 ;
V_197 [ 12 ] = V_199 -> V_117 ;
V_197 [ 13 ] = V_199 -> V_213 ;
V_197 [ 14 ] = V_199 -> V_214 ;
V_197 [ 15 ] = V_199 -> V_215 ;
V_197 [ 16 ] = V_199 -> V_216 ;
V_197 [ 17 ] = V_199 -> V_217 ;
V_197 [ 18 ] = V_199 -> V_218 ;
V_197 [ 19 ] = V_199 -> V_219 ;
V_197 [ 20 ] = V_199 -> V_220 ;
V_197 [ 21 ] = V_199 -> V_221 ;
V_197 [ 22 ] = V_199 -> V_222 ;
V_197 [ 23 ] = V_121 -> V_207 . V_223 ;
V_197 [ 24 ] = V_121 -> V_208 . V_223 ;
V_197 [ 25 ] = V_4 -> V_224 ;
V_8 -> V_11 -> V_12 -> V_201 ( V_8 , & V_197 [ 26 ] ) ;
}
void F_70 ( struct V_1 * V_121 , T_1 V_225 , T_2 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
char * V_106 = ( char * ) V_108 ;
if ( ! V_8 -> V_11 -> V_12 -> V_226 ) {
F_10 ( V_121 , L_10 ) ;
return;
}
if ( V_225 == V_227 ) {
if ( V_4 -> V_9 -> V_53 != V_57 ) {
memcpy ( V_106 , V_132 [ V_89 ] ,
V_228 ) ;
V_106 += V_228 ;
}
memcpy ( V_106 , V_132 [ V_90 ] ,
V_228 ) ;
V_106 += V_228 ;
if ( ( V_4 -> V_10 ) && ( ! V_4 -> V_10 -> V_83 ) )
memcpy ( V_106 , V_132 [ V_87 ] ,
V_228 ) ;
} else {
snprintf ( V_106 , V_228 , L_11 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_12 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_13 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_14 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_15 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_16 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_17 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_18 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_19 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_20 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_21 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_22 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_23 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_24 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_25 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_26 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_27 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_28 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_29 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_30 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_31 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_32 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_33 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_34 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_35 ) ;
V_106 = V_106 + V_228 ;
snprintf ( V_106 , V_228 , L_36 ) ;
V_106 = V_106 + V_228 ;
V_8 -> V_11 -> V_12 -> V_226 ( V_8 , V_225 , ( T_2 * ) V_106 ) ;
}
}
int F_71 ( struct V_1 * V_121 , int V_225 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_160 * V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_229 ) {
F_10 ( V_121 , L_37 ) ;
return - V_230 ;
}
if ( V_225 == V_227 ) {
T_1 V_231 = ( sizeof( V_132 ) / V_228 ) ;
if ( V_4 -> V_9 -> V_53 == V_57 )
V_231 -- ;
if ( ( ! V_4 -> V_10 ) || ( V_4 -> V_10 -> V_83 ) )
V_231 -- ;
return V_231 ;
} else {
return ( V_232 + V_12 -> V_229 ( V_8 , V_225 ) ) ;
}
}
int F_72 ( struct V_1 * V_121 , int V_233 )
{
int V_18 ;
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_20 * V_21 = V_4 -> V_10 ;
V_18 = F_5 ( V_21 , V_27 , V_234 ) ;
V_18 |= F_5 ( V_21 , V_235 , V_233 ) ;
V_18 |= F_5 ( V_21 , V_27 , V_35 ) ;
if ( V_18 ) {
F_10 ( V_121 , L_38 ) ;
return V_18 ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_121 , enum V_236 V_144 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_20 * V_21 = V_4 -> V_10 ;
int V_39 ;
if ( V_21 )
switch ( V_144 ) {
case V_237 :
V_39 = F_5 ( V_21 , V_27 ,
V_234 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_238 = F_6 ( V_21 , V_235 ) ;
V_39 = F_5 ( V_21 , V_27 ,
V_35 ) ;
if ( V_39 )
return V_39 ;
return 2 ;
case V_239 :
V_39 = F_72 ( V_121 , V_240 ) ;
if ( V_39 )
return V_39 ;
break;
case V_241 :
V_39 = F_72 ( V_121 , V_242 ) ;
if ( V_39 )
return V_39 ;
break;
case V_243 :
V_39 = F_5 ( V_21 , V_27 ,
V_234 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_5 ( V_21 , V_235 ,
V_4 -> V_238 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_5 ( V_21 , V_27 ,
V_35 ) ;
if ( V_39 )
return V_39 ;
break;
default:
return - V_45 ;
}
else
switch ( V_144 ) {
case V_237 :
return V_8 -> V_11 -> V_12 -> V_244 ( V_8 , V_245 ) ;
case V_239 :
return V_8 -> V_11 -> V_12 -> V_244 ( V_8 , V_246 ) ;
case V_241 :
return V_8 -> V_11 -> V_12 -> V_244 ( V_8 , V_247 ) ;
case V_243 :
return V_8 -> V_11 -> V_12 -> V_244 ( V_8 , V_248 ) ;
default:
return - V_45 ;
}
return 0 ;
}
void F_74 ( struct V_1 * V_2 , struct V_249 * V_15 ,
void * V_108 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_160 * V_12 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_15 -> V_148 = V_250 ;
if ( ! V_12 -> V_251 ) {
F_10 ( V_2 , L_39 ) ;
return;
}
V_12 -> V_251 ( V_4 -> V_9 , V_108 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_1 V_252 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_160 * V_12 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_12 -> V_253 ) {
F_10 ( V_2 , L_40 ) ;
return - V_230 ;
}
V_252 = V_12 -> V_253 ( V_4 -> V_9 ) ;
if ( V_252 > 0 )
return V_252 * sizeof( T_1 ) ;
else
return V_252 ;
}
static int F_76 ( struct V_1 * V_121 )
{
int V_39 = 0 ;
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_20 * V_10 = V_4 -> V_10 ;
if ( F_14 ( V_121 ) ) {
if ( V_10 )
V_39 = F_77 ( V_10 ) ;
}
return V_39 ;
}
static T_1
F_78 ( struct V_1 * V_121 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_160 * V_12 ;
if ( F_28 ( V_4 -> V_109 ) ) {
F_10 ( V_121 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_254 ( V_4 -> V_9 ) ;
}
static T_1
F_79 ( struct V_1 * V_121 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_160 * V_12 ;
if ( F_28 ( V_4 -> V_109 ) ) {
F_10 ( V_121 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_255 ( V_4 -> V_9 ) ;
}
static int
F_80 ( struct V_1 * V_121 , T_1 * V_256 , T_2 * V_257 , T_2 * V_258 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_160 * V_12 ;
if ( F_28 ( V_4 -> V_109 ) ) {
F_10 ( V_121 ,
L_41 ) ;
return - V_230 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_256 )
return 0 ;
return V_12 -> V_259 ( V_4 -> V_9 , V_256 , V_257 , V_258 ) ;
}
static int
F_81 ( struct V_1 * V_121 , const T_1 * V_256 , const T_2 * V_257 ,
const T_2 V_258 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
struct V_160 * V_12 ;
if ( F_28 ( V_4 -> V_109 ) ) {
F_10 ( V_121 ,
L_41 ) ;
return - V_230 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_257 ||
( V_258 != V_260 && V_258 != V_261 ) )
return - V_230 ;
if ( ! V_256 )
return 0 ;
return V_12 -> V_262 ( V_4 -> V_9 , V_256 , V_257 , V_258 ) ;
}
static int F_82 ( struct V_1 * V_121 ,
struct V_263 * V_15 ,
T_1 * V_264 )
{
struct V_3 * V_4 = F_2 ( V_121 ) ;
switch ( V_15 -> V_15 ) {
case V_265 :
V_15 -> V_108 = V_4 -> V_9 -> V_133 ;
break;
default:
return - V_230 ;
}
return 0 ;
}
void F_83 ( struct V_1 * V_84 )
{
V_84 -> V_266 = & V_267 ;
}
