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
if ( ! V_21 || ! V_21 -> V_22 ) {
V_15 -> V_23 = V_24 ;
V_15 -> V_25 = V_24 ;
return;
}
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 , V_27 ,
V_28 ) ;
V_18 = F_6 ( V_21 -> V_22 , V_21 -> V_26 , V_29 ) ;
V_16 = F_7 ( V_18 , V_30 , V_31 ) ;
V_18 = F_6 ( V_21 -> V_22 , V_21 -> V_26 , V_32 ) ;
V_17 = F_8 ( V_18 , V_33 ) ;
V_19 = F_8 ( V_18 , V_34 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 , V_27 ,
V_35 ) ;
switch ( V_16 ) {
case 0x0 :
V_15 -> V_23 = V_36 ;
break;
case 0x1 :
V_15 -> V_23 = V_37 ;
break;
case 0x3 :
V_15 -> V_23 = V_38 ;
break;
default:
V_15 -> V_23 = V_24 ;
break;
}
if ( ! V_19 )
V_15 -> V_25 = V_24 ;
else if ( V_17 )
V_15 -> V_25 = V_37 ;
else
V_15 -> V_25 = V_36 ;
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
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_27 , 2 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
21 , 0x1046 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
9 , 0x1F00 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
0 , 0x9140 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
0 , 0x9140 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
22 , 0xFA ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
1 , 0x418 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
7 , 0x20C ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
22 , 0 ) ;
V_82 = ( T_3 ) F_6 ( V_21 -> V_22 , V_21 -> V_26 ,
F_18 ) ;
V_82 |= F_19 ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
F_18 , V_82 ) ;
} else {
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
22 , 0xFA ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
1 , 0x400 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
7 , 0x200 ) ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
22 , 0 ) ;
V_82 = ( T_3 ) F_6 ( V_21 -> V_22 , V_21 -> V_26 ,
F_18 ) ;
V_82 &= ~ F_19 ;
( void ) F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
F_18 , V_82 ) ;
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
if ( ( V_21 ) && ( ! V_21 -> V_83 ) )
V_39 = F_17 ( V_21 , 0x1 ) ;
break;
case V_88 :
if ( ( V_8 -> V_11 -> V_12 -> V_89 ) &&
( V_4 -> V_9 -> V_53 != V_57 ) )
V_39 = V_8 -> V_11 -> V_12 -> V_89 ( V_8 , V_86 , 0x1 ) ;
break;
case V_90 :
if ( V_8 -> V_11 -> V_12 -> V_89 )
V_39 = V_8 -> V_11 -> V_12 -> V_89 ( V_8 , V_86 , 0x1 ) ;
break;
case V_91 :
if ( ( V_21 ) && ( ! V_21 -> V_83 ) )
V_39 |= F_17 ( V_21 , 0x0 ) ;
if ( V_8 -> V_11 -> V_12 -> V_89 ) {
if ( V_4 -> V_9 -> V_53 != V_57 )
V_39 |= V_8 -> V_11 -> V_12 -> V_89 ( V_8 ,
V_88 , 0x0 ) ;
V_39 |= V_8 -> V_11 -> V_12 -> V_89 ( V_8 ,
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
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_96 * V_102 ;
unsigned int V_103 ;
int V_104 ;
T_1 V_105 ;
char V_106 [ 33 ] ;
if ( ! V_95 ) {
V_103 = V_97 -> V_107 ;
memset ( V_97 -> V_108 , 0xFF , V_103 ) ;
V_103 &= ~ 1ul ;
memset ( & V_97 -> V_108 [ V_103 / 2 ] , 0xAA , V_103 / 2 - 1 ) ;
memset ( & V_97 -> V_108 [ V_103 / 2 + 10 ] , 0xBE ,
V_103 / 2 - 11 ) ;
memset ( & V_97 -> V_108 [ V_103 / 2 + 12 ] , 0xAF ,
V_103 / 2 - 13 ) ;
return;
}
V_99 = V_95 -> V_99 ;
V_84 = V_95 -> V_109 . V_11 ;
if ( F_28 ( V_99 ) ) {
V_101 = F_29 ( V_84 , V_95 -> V_110 ) ;
F_30 ( V_101 ) ;
return;
}
V_103 = V_97 -> V_107 ;
V_103 &= ~ 1ul ;
V_102 = F_31 ( V_97 , V_111 ) ;
F_32 ( V_97 ) ;
V_97 = V_102 ;
V_104 = 0 ;
if ( * ( V_97 -> V_108 + 10 ) == 0xFF ) {
if ( ( * ( V_97 -> V_108 + V_103 / 2 + 10 ) == 0xBE ) &&
( * ( V_97 -> V_108 + V_103 / 2 + 12 ) == 0xAF ) )
V_104 = 1 ;
}
if ( V_104 ) {
V_84 -> V_112 . V_113 ++ ;
V_84 -> V_112 . V_114 += V_97 -> V_107 ;
} else {
V_84 -> V_112 . V_115 ++ ;
for ( V_105 = 0 ; V_105 < V_97 -> V_107 ; V_105 ++ ) {
snprintf ( V_106 + V_105 % 16 * 2 , 3 ,
L_3 , * ( V_97 -> V_108 + V_105 ) ) ;
if ( ( V_105 % 16 == 15 ) || ( V_105 == V_97 -> V_107 - 1 ) )
F_33 ( L_4 , V_106 ) ;
}
}
F_32 ( V_97 ) ;
}
static int F_34 ( struct V_3 * V_4 ,
int V_116 , int V_117 , int V_118 )
{
int V_105 , V_39 ;
struct V_94 * V_95 ;
struct V_1 * V_84 = V_4 -> V_119 ;
unsigned long V_113 = V_84 -> V_112 . V_113 ;
unsigned long V_114 = V_84 -> V_112 . V_114 ;
unsigned long V_115 = V_84 -> V_112 . V_115 ;
for ( V_105 = V_116 ; V_105 <= V_117 ; V_105 ++ ) {
V_95 = & V_4 -> V_95 [ V_105 ] ;
( void ) V_95 -> V_120 ( V_95 ,
V_118 , F_27 ) ;
}
V_39 = ( int ) ( V_84 -> V_112 . V_113 - V_113 ) ;
V_84 -> V_112 . V_113 = V_113 ;
V_84 -> V_112 . V_114 = V_114 ;
V_84 -> V_112 . V_115 = V_115 ;
return V_39 ;
}
static int F_35 ( struct V_1 * V_84 ,
enum V_85 V_92 )
{
#define F_36 1
#define F_37 0
#define F_38 128
#define F_39 1
#define F_40 2
#define F_41 3
#define F_42 4
struct V_3 * V_4 = F_2 ( V_84 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_105 , V_121 , V_122 , V_123 , V_124 = 0 ;
unsigned int V_125 ;
T_4 V_126 ;
struct V_96 * V_97 ;
V_125 = F_38 ;
V_97 = F_43 ( V_125 , V_127 ) ;
if ( ! V_97 )
return F_39 ;
( void ) F_44 ( V_97 , V_125 ) ;
F_27 ( NULL , V_97 ) ;
V_97 -> V_128 = F_37 ;
V_122 = 1 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
V_123 = 0 ;
for ( V_105 = 0 ; V_105 < F_36 ; V_105 ++ ) {
( void ) F_45 ( V_97 ) ;
V_126 = ( T_4 ) F_46 (
V_84 , V_97 ,
& F_47 ( V_4 , V_97 -> V_128 ) ) ;
if ( V_126 == V_129 )
V_123 ++ ;
else
break;
}
if ( V_123 != F_36 ) {
V_124 = F_40 ;
F_48 ( V_4 -> V_11 , L_5 ,
V_130 [ V_92 ] , V_123 ,
F_36 ) ;
break;
}
F_24 ( 100 ) ;
V_123 = F_34 ( V_4 ,
V_8 -> V_131 , V_8 -> V_131 * 2 - 1 ,
F_36 ) ;
if ( V_123 != F_36 ) {
V_124 = F_41 ;
F_48 ( V_4 -> V_11 , L_6 ,
V_130 [ V_92 ] , V_123 ,
F_36 ) ;
break;
}
( void ) F_34 ( V_4 ,
F_37 , F_37 ,
F_36 ) ;
}
F_49 ( V_97 ) ;
return V_124 ;
}
static int F_50 ( struct V_1 * V_84 )
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
F_51 ( V_4 -> V_10 ) ;
if ( V_8 -> V_11 -> V_12 -> V_132 )
V_8 -> V_11 -> V_12 -> V_132 ( V_8 ) ;
F_52 ( 10000 , 20000 ) ;
( void ) F_34 ( V_4 , 0 , V_8 -> V_131 - 1 , 256 ) ;
F_22 ( V_84 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_84 ,
struct V_133 * V_134 , T_5 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_84 ) ;
bool V_135 = F_14 ( V_84 ) ;
#define F_54 3
int V_136 [ F_54 ] [ 2 ] ;
int V_105 ;
int V_137 = 0 ;
V_136 [ 0 ] [ 0 ] = V_88 ;
V_136 [ 0 ] [ 1 ] = ( V_4 -> V_9 -> V_53 != V_57 ) ;
V_136 [ 1 ] [ 0 ] = V_90 ;
V_136 [ 1 ] [ 1 ] = 1 ;
V_136 [ 2 ] [ 0 ] = V_87 ;
V_136 [ 2 ] [ 1 ] = ( ( ! ! ( V_4 -> V_9 -> V_138 ) ) &&
( V_4 -> V_9 -> V_53 != V_57 ) ) ;
if ( V_134 -> V_139 == V_140 ) {
F_55 ( V_141 , & V_4 -> V_142 ) ;
if ( V_135 )
( void ) F_56 ( V_84 ) ;
for ( V_105 = 0 ; V_105 < F_54 ; V_105 ++ ) {
if ( ! V_136 [ V_105 ] [ 1 ] )
continue;
V_108 [ V_137 ] = F_21 ( V_84 ,
(enum V_85 ) V_136 [ V_105 ] [ 0 ] ) ;
if ( ! V_108 [ V_137 ] ) {
V_108 [ V_137 ] = F_35 (
V_84 , (enum V_85 ) V_136 [ V_105 ] [ 0 ] ) ;
( void ) F_50 ( V_84 ) ;
}
if ( V_108 [ V_137 ] )
V_134 -> V_139 |= V_143 ;
V_137 ++ ;
}
F_22 ( V_4 -> V_119 ) ;
F_57 ( V_141 , & V_4 -> V_142 ) ;
if ( V_135 )
( void ) F_58 ( V_84 ) ;
}
( void ) F_59 ( 4 * 1000 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
assert ( V_4 ) ;
strncpy ( V_145 -> V_146 , V_147 ,
sizeof( V_145 -> V_146 ) ) ;
V_145 -> V_146 [ sizeof( V_145 -> V_146 ) - 1 ] = '\0' ;
strncpy ( V_145 -> V_148 , V_149 , sizeof( V_145 -> V_148 ) ) ;
V_145 -> V_148 [ sizeof( V_145 -> V_148 ) - 1 ] = '\0' ;
strncpy ( V_145 -> V_150 , V_4 -> V_11 -> V_22 -> V_151 ,
sizeof( V_145 -> V_150 ) ) ;
V_145 -> V_150 [ V_152 - 1 ] = '\0' ;
strncpy ( V_145 -> V_153 , L_8 , V_154 ) ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_155 * V_156 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_157 * V_12 ;
struct V_158 * V_159 ;
T_1 V_160 = 0 ;
V_159 = V_4 -> V_9 -> V_161 [ 0 ] ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_162 )
V_12 -> V_162 ( V_159 , & V_160 ) ;
V_156 -> V_163 = V_160 ;
V_156 -> V_164 = V_160 ;
V_156 -> V_165 = V_159 -> V_166 . V_167 ;
V_156 -> V_168 = V_159 -> V_169 . V_167 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_170 * V_156 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_157 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_171 )
V_12 -> V_171 ( V_4 -> V_9 , & V_156 -> V_46 ,
& V_156 -> V_172 , & V_156 -> V_173 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_170 * V_156 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_157 * V_12 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_8 = V_4 -> V_9 ;
V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_174 )
return - V_42 ;
return V_12 -> V_174 ( V_4 -> V_9 , V_156 -> V_46 ,
V_156 -> V_172 , V_156 -> V_173 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_157 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_176 -> V_177 = 1 ;
V_176 -> V_178 = 1 ;
if ( ( ! V_12 -> V_179 ) ||
( ! V_12 -> V_180 ) )
return - V_42 ;
V_12 -> V_179 ( V_4 -> V_9 ,
& V_176 -> V_181 ,
& V_176 -> V_182 ) ;
V_12 -> V_180 (
V_4 -> V_9 ,
& V_176 -> V_183 ,
& V_176 -> V_184 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_157 * V_12 ;
int V_39 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_176 -> V_181 != V_176 -> V_182 )
return - V_45 ;
if ( V_176 -> V_184 != V_176 -> V_183 )
return - V_45 ;
if ( ( ! V_12 -> V_185 ) ||
( ! V_12 -> V_186 ) )
return - V_42 ;
V_12 -> V_185 ( V_4 -> V_9 ,
V_176 -> V_182 ) ;
V_39 = V_12 -> V_186 (
V_4 -> V_9 ,
V_176 -> V_184 ) ;
return V_39 ;
}
void F_66 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_188 -> V_189 = V_4 -> V_9 -> V_131 ;
V_188 -> V_190 = V_4 -> V_9 -> V_131 ;
V_188 -> V_191 = V_4 -> V_9 -> V_131 ;
V_188 -> V_192 = V_4 -> V_9 -> V_131 ;
}
void F_67 ( struct V_1 * V_119 ,
struct V_193 * V_112 , T_5 * V_108 )
{
T_5 * V_194 = V_108 ;
struct V_3 * V_4 = F_2 ( V_119 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
const struct V_195 * V_196 ;
struct V_195 V_197 ;
if ( ! V_8 -> V_11 -> V_12 -> V_198 || ! V_8 -> V_11 -> V_12 -> V_199 ) {
F_10 ( V_119 , L_9 ) ;
return;
}
V_8 -> V_11 -> V_12 -> V_199 ( V_8 , & V_119 -> V_112 ) ;
V_196 = F_68 ( V_119 , & V_197 ) ;
V_194 [ 0 ] = V_196 -> V_113 ;
V_194 [ 1 ] = V_196 -> V_200 ;
V_194 [ 2 ] = V_196 -> V_114 ;
V_194 [ 3 ] = V_196 -> V_201 ;
V_194 [ 4 ] = V_196 -> V_202 ;
V_194 [ 5 ] = V_196 -> V_203 ;
V_194 [ 6 ] = V_196 -> V_204 ;
V_194 [ 7 ] = V_196 -> V_205 ;
V_194 [ 8 ] = V_196 -> V_206 ;
V_194 [ 9 ] = V_196 -> V_207 ;
V_194 [ 10 ] = V_196 -> V_208 ;
V_194 [ 11 ] = V_196 -> V_209 ;
V_194 [ 12 ] = V_196 -> V_115 ;
V_194 [ 13 ] = V_196 -> V_210 ;
V_194 [ 14 ] = V_196 -> V_211 ;
V_194 [ 15 ] = V_196 -> V_212 ;
V_194 [ 16 ] = V_196 -> V_213 ;
V_194 [ 17 ] = V_196 -> V_214 ;
V_194 [ 18 ] = V_196 -> V_215 ;
V_194 [ 19 ] = V_196 -> V_216 ;
V_194 [ 20 ] = V_196 -> V_217 ;
V_194 [ 21 ] = V_196 -> V_218 ;
V_194 [ 22 ] = V_196 -> V_219 ;
V_194 [ 23 ] = V_119 -> V_204 . V_220 ;
V_194 [ 24 ] = V_119 -> V_205 . V_220 ;
V_194 [ 25 ] = V_4 -> V_221 ;
V_8 -> V_11 -> V_12 -> V_198 ( V_8 , & V_194 [ 26 ] ) ;
}
void F_69 ( struct V_1 * V_119 , T_1 V_222 , T_2 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_119 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
char * V_106 = ( char * ) V_108 ;
if ( ! V_8 -> V_11 -> V_12 -> V_223 ) {
F_10 ( V_119 , L_10 ) ;
return;
}
if ( V_222 == V_224 ) {
if ( V_4 -> V_9 -> V_53 != V_57 ) {
memcpy ( V_106 , V_130 [ V_88 ] ,
V_225 ) ;
V_106 += V_225 ;
}
memcpy ( V_106 , V_130 [ V_90 ] ,
V_225 ) ;
V_106 += V_225 ;
if ( ( V_4 -> V_10 ) && ( ! V_4 -> V_10 -> V_83 ) )
memcpy ( V_106 , V_130 [ V_87 ] ,
V_225 ) ;
} else {
snprintf ( V_106 , V_225 , L_11 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_12 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_13 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_14 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_15 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_16 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_17 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_18 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_19 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_20 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_21 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_22 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_23 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_24 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_25 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_26 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_27 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_28 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_29 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_30 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_31 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_32 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_33 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_34 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_35 ) ;
V_106 = V_106 + V_225 ;
snprintf ( V_106 , V_225 , L_36 ) ;
V_106 = V_106 + V_225 ;
V_8 -> V_11 -> V_12 -> V_223 ( V_8 , V_222 , ( T_2 * ) V_106 ) ;
}
}
int F_70 ( struct V_1 * V_119 , int V_222 )
{
struct V_3 * V_4 = F_2 ( V_119 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_157 * V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_226 ) {
F_10 ( V_119 , L_37 ) ;
return - V_227 ;
}
if ( V_222 == V_224 ) {
T_1 V_228 = ( sizeof( V_130 ) / V_225 ) ;
if ( V_4 -> V_9 -> V_53 == V_57 )
V_228 -- ;
if ( ( ! V_4 -> V_10 ) || ( V_4 -> V_10 -> V_83 ) )
V_228 -- ;
return V_228 ;
} else {
return ( V_229 + V_12 -> V_226 ( V_8 , V_222 ) ) ;
}
}
int F_71 ( struct V_1 * V_119 , int V_230 )
{
int V_18 ;
struct V_3 * V_4 = F_2 ( V_119 ) ;
struct V_20 * V_21 = V_4 -> V_10 ;
if ( ! V_21 -> V_22 ) {
F_10 ( V_119 , L_38 ) ;
return - V_45 ;
}
V_18 = F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_27 , V_231 ) ;
V_18 = F_5 ( V_21 -> V_22 , V_21 -> V_26 , V_232 ,
V_230 ) ;
V_18 = F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_27 , V_35 ) ;
if ( V_18 ) {
F_10 ( V_119 , L_39 ) ;
return V_18 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_119 , enum V_233 V_142 )
{
struct V_3 * V_4 = F_2 ( V_119 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_20 * V_21 = V_4 -> V_10 ;
int V_39 ;
if ( V_21 )
switch ( V_142 ) {
case V_234 :
V_39 = F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_27 ,
V_231 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_235 = ( T_3 ) F_6 ( V_21 -> V_22 ,
V_21 -> V_26 ,
V_232 ) ;
V_39 = F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_27 ,
V_35 ) ;
if ( V_39 )
return V_39 ;
return 2 ;
case V_236 :
V_39 = F_71 ( V_119 , V_237 ) ;
if ( V_39 )
return V_39 ;
break;
case V_238 :
V_39 = F_71 ( V_119 , V_239 ) ;
if ( V_39 )
return V_39 ;
break;
case V_240 :
V_39 = F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_27 ,
V_231 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_232 , V_4 -> V_235 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_5 ( V_21 -> V_22 , V_21 -> V_26 ,
V_27 ,
V_35 ) ;
if ( V_39 )
return V_39 ;
break;
default:
return - V_45 ;
}
else
switch ( V_142 ) {
case V_234 :
return V_8 -> V_11 -> V_12 -> V_241 ( V_8 , V_242 ) ;
case V_236 :
return V_8 -> V_11 -> V_12 -> V_241 ( V_8 , V_243 ) ;
case V_238 :
return V_8 -> V_11 -> V_12 -> V_241 ( V_8 , V_244 ) ;
case V_240 :
return V_8 -> V_11 -> V_12 -> V_241 ( V_8 , V_245 ) ;
default:
return - V_45 ;
}
return 0 ;
}
void F_73 ( struct V_1 * V_2 , struct V_246 * V_15 ,
void * V_108 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_157 * V_12 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_15 -> V_146 = V_247 ;
if ( ! V_12 -> V_248 ) {
F_10 ( V_2 , L_40 ) ;
return;
}
V_12 -> V_248 ( V_4 -> V_9 , V_108 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_1 V_249 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_157 * V_12 ;
assert ( V_4 || V_4 -> V_9 ) ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_12 -> V_250 ) {
F_10 ( V_2 , L_41 ) ;
return - V_227 ;
}
V_249 = V_12 -> V_250 ( V_4 -> V_9 ) ;
if ( V_249 > 0 )
return V_249 * sizeof( T_1 ) ;
else
return V_249 ;
}
static int F_75 ( struct V_1 * V_119 )
{
int V_39 = 0 ;
struct V_3 * V_4 = F_2 ( V_119 ) ;
struct V_20 * V_10 = V_4 -> V_10 ;
if ( F_14 ( V_119 ) ) {
if ( V_10 )
V_39 = F_76 ( V_10 ) ;
}
return V_39 ;
}
void F_77 ( struct V_1 * V_84 )
{
V_84 -> V_251 = & V_252 ;
}
