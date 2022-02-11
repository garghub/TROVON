static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = V_4 -> V_6 ;
struct V_7 * V_8 ;
V_8 = V_4 -> V_9 ;
if ( V_2 -> V_10 ) {
if ( ! F_3 ( V_2 -> V_10 ) )
V_5 = V_2 -> V_10 -> V_6 ;
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
struct V_20 * V_21 = V_2 -> V_10 ;
if ( ! V_21 || ! V_21 -> V_22 . V_23 ) {
V_15 -> V_24 . V_25 = V_26 ;
V_15 -> V_24 . V_27 = V_26 ;
return;
}
F_5 ( V_21 , V_28 , V_29 ) ;
V_18 = F_6 ( V_21 , V_30 ) ;
V_16 = F_7 ( V_18 , V_31 , V_32 ) ;
V_18 = F_6 ( V_21 , V_33 ) ;
V_17 = F_8 ( V_18 , V_34 ) ;
V_19 = F_8 ( V_18 , V_35 ) ;
F_5 ( V_21 , V_28 , V_36 ) ;
switch ( V_16 ) {
case 0x0 :
V_15 -> V_24 . V_25 = V_37 ;
break;
case 0x1 :
V_15 -> V_24 . V_25 = V_38 ;
break;
case 0x3 :
V_15 -> V_24 . V_25 = V_39 ;
break;
default:
V_15 -> V_24 . V_25 = V_26 ;
break;
}
if ( ! V_19 )
V_15 -> V_24 . V_27 = V_26 ;
else if ( V_17 )
V_15 -> V_24 . V_27 = V_38 ;
else
V_15 -> V_24 . V_27 = V_37 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_5 ;
int V_40 ;
T_2 V_41 ;
T_3 V_42 ;
T_1 V_43 , V_44 ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_45 ;
V_8 = V_4 -> V_9 ;
if ( ! V_8 -> V_11 || ! V_8 -> V_11 -> V_12 || ! V_8 -> V_11 -> V_12 -> V_46 )
return - V_45 ;
V_40 = V_8 -> V_11 -> V_12 -> V_46 ( V_8 , NULL , & V_42 , & V_41 ) ;
if ( V_40 < 0 ) {
F_10 ( V_2 , L_1 , V_47 ) ;
return - V_48 ;
}
F_11 ( & V_43 ,
V_15 -> V_49 . V_43 ) ;
F_11 ( & V_44 ,
V_15 -> V_49 . V_44 ) ;
V_15 -> V_24 . V_50 = false ;
V_15 -> V_24 . V_42 = V_42 ;
V_15 -> V_24 . V_41 = V_41 ;
if ( V_2 -> V_10 )
( void ) F_12 ( V_2 -> V_10 , V_15 ) ;
V_5 = F_1 ( V_2 ) ;
if ( ! V_5 ) {
V_15 -> V_24 . V_42 = ( T_1 ) V_51 ;
V_15 -> V_24 . V_41 = V_52 ;
}
if ( V_15 -> V_24 . V_50 )
V_44 |= V_53 ;
V_43 |= V_8 -> V_54 ;
if ( V_8 -> V_55 == V_56 ) {
V_43 |= V_57 ;
V_44 |= V_58 ;
} else if ( V_8 -> V_55 == V_59 ) {
V_43 |= V_60 ;
V_44 |= V_61 ;
}
switch ( V_8 -> V_62 ) {
case V_63 :
V_15 -> V_24 . V_64 = V_65 ;
break;
case V_66 :
V_15 -> V_24 . V_64 = V_67 ;
break;
case V_68 :
default:
break;
}
if ( ! ( F_13 ( V_4 -> V_69 ) && V_8 -> V_70 == V_71 ) )
V_43 |= V_72 ;
F_14 ( V_15 -> V_49 . V_43 ,
V_43 ) ;
F_14 ( V_15 -> V_49 . V_44 ,
V_44 ) ;
V_15 -> V_24 . V_73 = V_74 | V_75 ;
F_4 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_42 ;
if ( ! F_16 ( V_2 ) )
return - V_45 ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_9 -> V_11 ||
! V_4 -> V_9 -> V_11 -> V_12 )
return - V_76 ;
V_8 = V_4 -> V_9 ;
V_42 = V_15 -> V_24 . V_42 ;
if ( V_8 -> V_55 == V_59 ) {
if ( V_15 -> V_24 . V_50 == V_77 ||
V_42 != V_78 ||
V_15 -> V_24 . V_41 != V_79 )
return - V_48 ;
} else if ( V_8 -> V_55 == V_56 ) {
if ( ! V_2 -> V_10 && V_15 -> V_24 . V_50 == V_77 )
return - V_48 ;
if ( V_42 == V_80 && V_15 -> V_24 . V_41 == V_81 )
return - V_48 ;
if ( V_2 -> V_10 )
return F_17 ( V_2 -> V_10 , V_15 ) ;
if ( ( V_42 != V_82 && V_42 != V_83 &&
V_42 != V_80 ) || ( V_15 -> V_24 . V_41 != V_81 &&
V_15 -> V_24 . V_41 != V_79 ) )
return - V_48 ;
} else {
F_10 ( V_2 , L_2 ) ;
return - V_84 ;
}
if ( V_8 -> V_11 -> V_12 -> V_85 ) {
V_8 -> V_11 -> V_12 -> V_85 ( V_8 , ( int ) V_42 , V_15 -> V_24 . V_41 ) ;
return 0 ;
}
F_10 ( V_2 , L_2 ) ;
return - V_84 ;
}
static int F_18 ( struct V_20 * V_21 , T_2 V_86 )
{
#define F_19 0
#define F_20 BIT(11)
#define F_21 BIT(14)
T_3 V_87 = 0 ;
if ( V_21 -> V_88 )
return - V_84 ;
if ( V_86 ) {
F_5 ( V_21 , V_28 , 2 ) ;
F_5 ( V_21 , 21 , 0x1046 ) ;
F_5 ( V_21 , V_28 , 0 ) ;
F_5 ( V_21 , 9 , 0x1F00 ) ;
F_5 ( V_21 , 0 , 0x9140 ) ;
F_5 ( V_21 , 0 , 0x9140 ) ;
F_5 ( V_21 , V_28 , 0xFA ) ;
F_5 ( V_21 , 1 , 0x418 ) ;
F_5 ( V_21 , 7 , 0x20C ) ;
F_5 ( V_21 , V_28 , 1 ) ;
V_87 = F_6 ( V_21 , F_19 ) ;
V_87 &= ~ F_20 ;
F_5 ( V_21 , F_19 , V_87 ) ;
F_5 ( V_21 , V_28 , 0 ) ;
V_87 = F_6 ( V_21 , F_19 ) ;
V_87 |= F_21 ;
V_87 &= ~ F_20 ;
F_5 ( V_21 , F_19 , V_87 ) ;
} else {
F_5 ( V_21 , V_28 , 0xFA ) ;
F_5 ( V_21 , 1 , 0x400 ) ;
F_5 ( V_21 , 7 , 0x200 ) ;
F_5 ( V_21 , V_28 , 1 ) ;
V_87 = F_6 ( V_21 , F_19 ) ;
V_87 |= F_20 ;
F_5 ( V_21 , F_19 , V_87 ) ;
F_5 ( V_21 , V_28 , 0 ) ;
F_5 ( V_21 , 9 , 0xF00 ) ;
V_87 = F_6 ( V_21 , F_19 ) ;
V_87 &= ~ F_21 ;
V_87 |= F_20 ;
F_5 ( V_21 , F_19 , V_87 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_89 ,
enum V_90 V_91 )
{
int V_40 = 0 ;
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_20 * V_21 = V_89 -> V_10 ;
struct V_7 * V_8 = V_4 -> V_9 ;
switch ( V_91 ) {
case V_92 :
if ( ( V_21 ) && ( ! V_21 -> V_88 ) ) {
V_40 = F_18 ( V_21 , 0x1 ) ;
V_40 |= V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
}
break;
case V_94 :
if ( ( V_8 -> V_11 -> V_12 -> V_93 ) &&
( V_4 -> V_9 -> V_55 != V_59 ) )
V_40 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
break;
case V_95 :
if ( V_8 -> V_11 -> V_12 -> V_93 )
V_40 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
break;
case V_96 :
if ( ( V_21 ) && ( ! V_21 -> V_88 ) )
V_40 |= F_18 ( V_21 , 0x0 ) ;
if ( V_8 -> V_11 -> V_12 -> V_93 ) {
if ( V_4 -> V_9 -> V_55 != V_59 )
V_40 |= V_8 -> V_11 -> V_12 -> V_93 ( V_8 ,
V_94 , 0x0 ) ;
V_40 |= V_8 -> V_11 -> V_12 -> V_93 ( V_8 ,
V_95 , 0x0 ) ;
}
break;
default:
V_40 = - V_48 ;
break;
}
if ( ! V_40 ) {
if ( V_91 == V_96 )
V_8 -> V_11 -> V_12 -> V_97 (
V_8 , V_89 -> V_98 & V_99 ) ;
else
V_8 -> V_11 -> V_12 -> V_97 ( V_8 , 1 ) ;
}
return V_40 ;
}
static int F_23 ( struct V_1 * V_89 ,
enum V_90 V_100 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_42 , V_41 ;
int V_40 ;
F_24 ( V_89 ) ;
V_40 = F_22 ( V_89 , V_100 ) ;
if ( V_40 )
return V_40 ;
F_25 ( 200 ) ;
V_40 = V_8 -> V_11 -> V_12 -> V_101 ? V_8 -> V_11 -> V_12 -> V_101 ( V_8 ) : 0 ;
if ( V_40 )
return V_40 ;
if ( V_4 -> V_9 -> V_55 != V_59 )
V_42 = 1000 ;
else
V_42 = 10000 ;
V_41 = 1 ;
V_8 -> V_11 -> V_12 -> V_85 ( V_8 , V_42 , V_41 ) ;
return 0 ;
}
static void F_26 ( struct V_102 * V_103 ,
struct V_104 * V_105 )
{
struct V_1 * V_89 ;
struct V_3 * V_4 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_104 * V_110 ;
unsigned int V_111 ;
int V_112 ;
T_1 V_113 ;
char V_114 [ 33 ] ;
if ( ! V_103 ) {
V_89 = V_105 -> V_11 ;
V_4 = F_2 ( V_89 ) ;
V_111 = V_105 -> V_115 ;
memset ( V_105 -> V_116 , 0xFF , V_111 ) ;
if ( ( ! F_13 ( V_4 -> V_69 ) ) &&
( V_4 -> V_9 -> V_70 == V_117 ) ) {
memcpy ( V_105 -> V_116 , V_89 -> V_118 , 6 ) ;
V_105 -> V_116 [ 5 ] += 0x1f ;
}
V_111 &= ~ 1ul ;
memset ( & V_105 -> V_116 [ V_111 / 2 ] , 0xAA , V_111 / 2 - 1 ) ;
memset ( & V_105 -> V_116 [ V_111 / 2 + 10 ] , 0xBE ,
V_111 / 2 - 11 ) ;
memset ( & V_105 -> V_116 [ V_111 / 2 + 12 ] , 0xAF ,
V_111 / 2 - 13 ) ;
return;
}
V_107 = V_103 -> V_107 ;
V_89 = V_103 -> V_119 . V_11 ;
if ( F_27 ( V_107 ) ) {
V_109 = F_28 ( V_89 , V_103 -> V_120 ) ;
F_29 ( V_109 ) ;
return;
}
V_111 = V_105 -> V_115 ;
V_111 &= ~ 1ul ;
V_110 = F_30 ( V_105 , V_121 ) ;
F_31 ( V_105 ) ;
V_105 = V_110 ;
V_112 = 0 ;
if ( * ( V_105 -> V_116 + 10 ) == 0xFF ) {
if ( ( * ( V_105 -> V_116 + V_111 / 2 + 10 ) == 0xBE ) &&
( * ( V_105 -> V_116 + V_111 / 2 + 12 ) == 0xAF ) )
V_112 = 1 ;
}
if ( V_112 ) {
V_89 -> V_122 . V_123 ++ ;
V_89 -> V_122 . V_124 += V_105 -> V_115 ;
} else {
V_89 -> V_122 . V_125 ++ ;
for ( V_113 = 0 ; V_113 < V_105 -> V_115 ; V_113 ++ ) {
snprintf ( V_114 + V_113 % 16 * 2 , 3 ,
L_3 , * ( V_105 -> V_116 + V_113 ) ) ;
if ( ( V_113 % 16 == 15 ) || ( V_113 == V_105 -> V_115 - 1 ) )
F_32 ( L_4 , V_114 ) ;
}
}
F_31 ( V_105 ) ;
}
static int F_33 ( struct V_3 * V_4 ,
int V_126 , int V_127 , int V_128 )
{
int V_113 , V_40 ;
struct V_102 * V_103 ;
struct V_1 * V_89 = V_4 -> V_129 ;
unsigned long V_123 = V_89 -> V_122 . V_123 ;
unsigned long V_124 = V_89 -> V_122 . V_124 ;
unsigned long V_125 = V_89 -> V_122 . V_125 ;
for ( V_113 = V_126 ; V_113 <= V_127 ; V_113 ++ ) {
V_103 = & V_4 -> V_103 [ V_113 ] ;
( void ) V_103 -> V_130 ( V_103 ,
V_128 , F_26 ) ;
}
V_40 = ( int ) ( V_89 -> V_122 . V_123 - V_123 ) ;
V_89 -> V_122 . V_123 = V_123 ;
V_89 -> V_122 . V_124 = V_124 ;
V_89 -> V_122 . V_125 = V_125 ;
return V_40 ;
}
static int F_34 ( struct V_1 * V_89 ,
enum V_90 V_100 )
{
#define F_35 1
#define F_36 0
#define F_37 128
#define F_38 1
#define F_39 2
#define F_40 3
#define F_41 4
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_113 , V_131 , V_132 , V_133 , V_134 = 0 ;
unsigned int V_135 ;
T_4 V_136 ;
struct V_104 * V_105 ;
V_135 = F_37 ;
V_105 = F_42 ( V_135 , V_137 ) ;
if ( ! V_105 )
return F_38 ;
( void ) F_43 ( V_105 , V_135 ) ;
V_105 -> V_11 = V_89 ;
F_26 ( NULL , V_105 ) ;
V_105 -> V_138 = F_36 ;
V_132 = 1 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
V_133 = 0 ;
for ( V_113 = 0 ; V_113 < F_35 ; V_113 ++ ) {
( void ) F_44 ( V_105 ) ;
V_136 = ( T_4 ) F_45 (
V_89 , V_105 ,
& F_46 ( V_4 , V_105 -> V_138 ) ) ;
if ( V_136 == V_139 )
V_133 ++ ;
else
break;
}
if ( V_133 != F_35 ) {
V_134 = F_39 ;
F_47 ( V_4 -> V_11 , L_5 ,
V_140 [ V_100 ] , V_133 ,
F_35 ) ;
break;
}
F_25 ( 100 ) ;
V_133 = F_33 ( V_4 ,
V_8 -> V_141 , V_8 -> V_141 * 2 - 1 ,
F_35 ) ;
if ( V_133 != F_35 ) {
V_134 = F_40 ;
F_47 ( V_4 -> V_11 , L_6 ,
V_140 [ V_100 ] , V_133 ,
F_35 ) ;
break;
}
( void ) F_33 ( V_4 ,
F_36 , F_36 ,
F_35 ) ;
}
F_48 ( V_105 ) ;
return V_134 ;
}
static int F_49 ( struct V_1 * V_89 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_40 ;
V_40 = F_22 ( V_89 , V_96 ) ;
if ( V_40 )
F_10 ( V_89 , L_7 ,
V_47 ,
V_40 ) ;
if ( V_8 -> V_11 -> V_12 -> V_142 )
V_8 -> V_11 -> V_12 -> V_142 ( V_8 ) ;
F_50 ( 10000 , 20000 ) ;
( void ) F_33 ( V_4 , 0 , V_8 -> V_141 - 1 , 256 ) ;
F_24 ( V_89 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_89 ,
struct V_143 * V_144 , T_5 * V_116 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
bool V_145 = F_16 ( V_89 ) ;
#define F_52 3
int V_146 [ F_52 ] [ 2 ] ;
int V_113 ;
int V_147 = 0 ;
V_146 [ 0 ] [ 0 ] = V_94 ;
V_146 [ 0 ] [ 1 ] = ( V_4 -> V_9 -> V_55 != V_59 ) ;
V_146 [ 1 ] [ 0 ] = V_95 ;
V_146 [ 1 ] [ 1 ] = 1 ;
V_146 [ 2 ] [ 0 ] = V_92 ;
V_146 [ 2 ] [ 1 ] = ( ( ! ! ( V_4 -> V_9 -> V_21 ) ) &&
( V_4 -> V_9 -> V_55 != V_59 ) ) ;
if ( V_144 -> V_98 == V_148 ) {
F_53 ( V_149 , & V_4 -> V_150 ) ;
if ( V_145 )
( void ) F_54 ( V_89 ) ;
for ( V_113 = 0 ; V_113 < F_52 ; V_113 ++ ) {
if ( ! V_146 [ V_113 ] [ 1 ] )
continue;
V_116 [ V_147 ] = F_23 ( V_89 ,
(enum V_90 ) V_146 [ V_113 ] [ 0 ] ) ;
if ( ! V_116 [ V_147 ] ) {
V_116 [ V_147 ] = F_34 (
V_89 , (enum V_90 ) V_146 [ V_113 ] [ 0 ] ) ;
( void ) F_49 ( V_89 ) ;
}
if ( V_116 [ V_147 ] )
V_144 -> V_98 |= V_151 ;
V_147 ++ ;
}
F_24 ( V_4 -> V_129 ) ;
F_55 ( V_149 , & V_4 -> V_150 ) ;
if ( V_145 )
( void ) F_56 ( V_89 ) ;
}
( void ) F_57 ( 4 * 1000 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
strncpy ( V_153 -> V_154 , V_155 ,
sizeof( V_153 -> V_154 ) ) ;
V_153 -> V_154 [ sizeof( V_153 -> V_154 ) - 1 ] = '\0' ;
strncpy ( V_153 -> V_156 , V_157 , sizeof( V_153 -> V_156 ) ) ;
V_153 -> V_156 [ sizeof( V_153 -> V_156 ) - 1 ] = '\0' ;
strncpy ( V_153 -> V_158 , V_4 -> V_11 -> V_23 -> V_159 ,
sizeof( V_153 -> V_158 ) ) ;
V_153 -> V_158 [ V_160 - 1 ] = '\0' ;
strncpy ( V_153 -> V_161 , L_8 , V_162 ) ;
V_153 -> V_163 = 0 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_164 * V_165 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_12 ;
struct V_167 * V_168 ;
T_1 V_169 = 0 ;
V_168 = V_4 -> V_9 -> V_170 [ 0 ] ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_171 )
V_12 -> V_171 ( V_168 , & V_169 ) ;
V_165 -> V_172 = V_169 ;
V_165 -> V_173 = V_169 ;
V_165 -> V_174 = V_168 -> V_175 . V_176 ;
V_165 -> V_177 = V_168 -> V_178 . V_176 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_179 * V_165 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_180 )
V_12 -> V_180 ( V_4 -> V_9 , & V_165 -> V_50 ,
& V_165 -> V_181 , & V_165 -> V_182 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_179 * V_165 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_166 * V_12 ;
V_8 = V_4 -> V_9 ;
V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_183 )
return - V_45 ;
return V_12 -> V_183 ( V_4 -> V_9 , V_165 -> V_50 ,
V_165 -> V_181 , V_165 -> V_182 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_184 * V_185 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_185 -> V_186 = 1 ;
V_185 -> V_187 = 1 ;
if ( ( ! V_12 -> V_188 ) ||
( ! V_12 -> V_189 ) )
return - V_45 ;
V_12 -> V_188 ( V_4 -> V_9 ,
& V_185 -> V_190 ,
& V_185 -> V_191 ) ;
V_12 -> V_189 (
V_4 -> V_9 ,
& V_185 -> V_192 ,
& V_185 -> V_193 ) ;
V_12 -> V_194 ( V_4 -> V_9 ,
& V_185 -> V_195 ,
& V_185 -> V_196 ,
& V_185 -> V_197 ,
& V_185 -> V_198 ,
& V_185 -> V_199 ,
& V_185 -> V_200 ,
& V_185 -> V_201 ,
& V_185 -> V_202 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_184 * V_185 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_12 ;
int V_203 , V_204 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_185 -> V_190 != V_185 -> V_191 )
return - V_48 ;
if ( ( ! V_12 -> V_205 ) ||
( ! V_12 -> V_206 ) )
return - V_45 ;
V_203 = V_12 -> V_205 ( V_4 -> V_9 ,
V_185 -> V_191 ) ;
V_204 = V_12 -> V_206 ( V_4 -> V_9 ,
V_185 -> V_192 ,
V_185 -> V_193 ) ;
if ( V_203 || V_204 )
return - V_48 ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 , struct V_207 * V_208 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_208 -> V_209 = V_4 -> V_9 -> V_141 ;
V_208 -> V_210 = V_4 -> V_9 -> V_141 ;
V_208 -> V_211 = V_4 -> V_9 -> V_141 ;
V_208 -> V_212 = V_4 -> V_9 -> V_141 ;
}
void F_65 ( struct V_1 * V_129 ,
struct V_213 * V_122 , T_5 * V_116 )
{
T_5 * V_214 = V_116 ;
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
const struct V_215 * V_216 ;
struct V_215 V_217 ;
if ( ! V_8 -> V_11 -> V_12 -> V_218 || ! V_8 -> V_11 -> V_12 -> V_219 ) {
F_10 ( V_129 , L_9 ) ;
return;
}
V_8 -> V_11 -> V_12 -> V_219 ( V_8 , & V_129 -> V_122 ) ;
V_216 = F_66 ( V_129 , & V_217 ) ;
V_214 [ 0 ] = V_216 -> V_123 ;
V_214 [ 1 ] = V_216 -> V_220 ;
V_214 [ 2 ] = V_216 -> V_124 ;
V_214 [ 3 ] = V_216 -> V_221 ;
V_214 [ 4 ] = V_216 -> V_222 ;
V_214 [ 5 ] = V_216 -> V_223 ;
V_214 [ 6 ] = V_216 -> V_224 ;
V_214 [ 7 ] = V_216 -> V_225 ;
V_214 [ 8 ] = V_216 -> V_226 ;
V_214 [ 9 ] = V_216 -> V_227 ;
V_214 [ 10 ] = V_216 -> V_228 ;
V_214 [ 11 ] = V_216 -> V_229 ;
V_214 [ 12 ] = V_216 -> V_125 ;
V_214 [ 13 ] = V_216 -> V_230 ;
V_214 [ 14 ] = V_216 -> V_231 ;
V_214 [ 15 ] = V_216 -> V_232 ;
V_214 [ 16 ] = V_216 -> V_233 ;
V_214 [ 17 ] = V_216 -> V_234 ;
V_214 [ 18 ] = V_216 -> V_235 ;
V_214 [ 19 ] = V_216 -> V_236 ;
V_214 [ 20 ] = V_216 -> V_237 ;
V_214 [ 21 ] = V_216 -> V_238 ;
V_214 [ 22 ] = V_216 -> V_239 ;
V_214 [ 23 ] = V_129 -> V_224 . V_240 ;
V_214 [ 24 ] = V_129 -> V_225 . V_240 ;
V_214 [ 25 ] = V_4 -> V_241 ;
V_8 -> V_11 -> V_12 -> V_218 ( V_8 , & V_214 [ 26 ] ) ;
}
void F_67 ( struct V_1 * V_129 , T_1 V_242 , T_2 * V_116 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
char * V_114 = ( char * ) V_116 ;
if ( ! V_8 -> V_11 -> V_12 -> V_243 ) {
F_10 ( V_129 , L_10 ) ;
return;
}
if ( V_242 == V_244 ) {
if ( V_4 -> V_9 -> V_55 != V_59 ) {
memcpy ( V_114 , V_140 [ V_94 ] ,
V_245 ) ;
V_114 += V_245 ;
}
memcpy ( V_114 , V_140 [ V_95 ] ,
V_245 ) ;
V_114 += V_245 ;
if ( ( V_129 -> V_10 ) && ( ! V_129 -> V_10 -> V_88 ) )
memcpy ( V_114 , V_140 [ V_92 ] ,
V_245 ) ;
} else {
snprintf ( V_114 , V_245 , L_11 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_12 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_13 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_14 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_15 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_16 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_17 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_18 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_19 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_20 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_21 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_22 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_23 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_24 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_25 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_26 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_27 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_28 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_29 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_30 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_31 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_32 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_33 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_34 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_35 ) ;
V_114 = V_114 + V_245 ;
snprintf ( V_114 , V_245 , L_36 ) ;
V_114 = V_114 + V_245 ;
V_8 -> V_11 -> V_12 -> V_243 ( V_8 , V_242 , ( T_2 * ) V_114 ) ;
}
}
int F_68 ( struct V_1 * V_129 , int V_242 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_166 * V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_246 ) {
F_10 ( V_129 , L_37 ) ;
return - V_247 ;
}
if ( V_242 == V_244 ) {
T_1 V_248 = ( sizeof( V_140 ) / V_245 ) ;
if ( V_4 -> V_9 -> V_55 == V_59 )
V_248 -- ;
if ( ( ! V_129 -> V_10 ) || ( V_129 -> V_10 -> V_88 ) )
V_248 -- ;
return V_248 ;
} else {
return ( V_249 + V_12 -> V_246 ( V_8 , V_242 ) ) ;
}
}
int F_69 ( struct V_1 * V_129 , int V_250 )
{
int V_18 ;
struct V_20 * V_21 = V_129 -> V_10 ;
V_18 = F_5 ( V_21 , V_28 , V_251 ) ;
V_18 |= F_5 ( V_21 , V_252 , V_250 ) ;
V_18 |= F_5 ( V_21 , V_28 , V_36 ) ;
if ( V_18 ) {
F_10 ( V_129 , L_38 ) ;
return V_18 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_129 , enum V_253 V_150 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_20 * V_21 = V_129 -> V_10 ;
int V_40 ;
if ( V_21 )
switch ( V_150 ) {
case V_254 :
V_40 = F_5 ( V_21 , V_28 ,
V_251 ) ;
if ( V_40 )
return V_40 ;
V_4 -> V_255 = F_6 ( V_21 , V_252 ) ;
V_40 = F_5 ( V_21 , V_28 ,
V_36 ) ;
if ( V_40 )
return V_40 ;
return 2 ;
case V_256 :
V_40 = F_69 ( V_129 , V_257 ) ;
if ( V_40 )
return V_40 ;
break;
case V_258 :
V_40 = F_69 ( V_129 , V_259 ) ;
if ( V_40 )
return V_40 ;
break;
case V_260 :
V_40 = F_5 ( V_21 , V_28 ,
V_251 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_5 ( V_21 , V_252 ,
V_4 -> V_255 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_5 ( V_21 , V_28 ,
V_36 ) ;
if ( V_40 )
return V_40 ;
break;
default:
return - V_48 ;
}
else
switch ( V_150 ) {
case V_254 :
return V_8 -> V_11 -> V_12 -> V_261 ( V_8 , V_262 ) ;
case V_256 :
return V_8 -> V_11 -> V_12 -> V_261 ( V_8 , V_263 ) ;
case V_258 :
return V_8 -> V_11 -> V_12 -> V_261 ( V_8 , V_264 ) ;
case V_260 :
return V_8 -> V_11 -> V_12 -> V_261 ( V_8 , V_265 ) ;
default:
return - V_48 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 , struct V_266 * V_15 ,
void * V_116 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_15 -> V_154 = V_267 ;
if ( ! V_12 -> V_268 ) {
F_10 ( V_2 , L_39 ) ;
return;
}
V_12 -> V_268 ( V_4 -> V_9 , V_116 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_1 V_269 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_12 -> V_270 ) {
F_10 ( V_2 , L_40 ) ;
return - V_247 ;
}
V_269 = V_12 -> V_270 ( V_4 -> V_9 ) ;
if ( V_269 > 0 )
return V_269 * sizeof( T_1 ) ;
else
return V_269 ;
}
static int F_73 ( struct V_1 * V_129 )
{
int V_40 = 0 ;
struct V_20 * V_271 = V_129 -> V_10 ;
if ( F_16 ( V_129 ) ) {
if ( V_271 && V_271 -> V_50 == V_77 )
V_40 = F_74 ( V_271 ) ;
}
return V_40 ;
}
static T_1
F_75 ( struct V_1 * V_129 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_166 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_129 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_272 ( V_4 -> V_9 ) ;
}
static T_1
F_76 ( struct V_1 * V_129 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_166 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_129 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_273 ( V_4 -> V_9 ) ;
}
static int
F_77 ( struct V_1 * V_129 , T_1 * V_274 , T_2 * V_275 , T_2 * V_276 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_166 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_129 ,
L_41 ) ;
return - V_247 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_274 )
return 0 ;
return V_12 -> V_277 ( V_4 -> V_9 , V_274 , V_275 , V_276 ) ;
}
static int
F_78 ( struct V_1 * V_129 , const T_1 * V_274 , const T_2 * V_275 ,
const T_2 V_276 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
struct V_166 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_129 ,
L_41 ) ;
return - V_247 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_276 != V_278 && V_276 != V_279 ) {
F_10 ( V_129 , L_42 ) ;
return - V_247 ;
}
return V_12 -> V_280 ( V_4 -> V_9 , V_274 , V_275 , V_276 ) ;
}
static int F_79 ( struct V_1 * V_129 ,
struct V_281 * V_15 ,
T_1 * V_282 )
{
struct V_3 * V_4 = F_2 ( V_129 ) ;
switch ( V_15 -> V_15 ) {
case V_283 :
V_15 -> V_116 = V_4 -> V_9 -> V_141 ;
break;
default:
return - V_247 ;
}
return 0 ;
}
void F_80 ( struct V_1 * V_89 )
{
V_89 -> V_284 = & V_285 ;
}
