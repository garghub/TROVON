static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 + V_3 ) ;
F_3 ( L_1 , V_2 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_4 )
{
F_3 ( L_1 , V_2 , V_3 , V_4 ) ;
F_5 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_2 ( V_2 -> V_5 + V_3 ) ;
}
static inline T_2 F_6 ( struct V_1 * V_2 , unsigned V_6 )
{
T_2 V_4 ;
F_7 ( V_2 -> V_7 , V_6 , & V_4 ) ;
F_3 ( L_2 , V_2 , V_6 , V_4 ) ;
return V_4 ;
}
static inline T_3 F_8 ( struct V_1 * V_2 , unsigned V_6 )
{
T_3 V_4 ;
F_9 ( V_2 -> V_7 , V_6 , & V_4 ) ;
F_3 ( L_3 , V_2 , V_6 , V_4 ) ;
return V_4 ;
}
static inline T_1 F_10 ( struct V_1 * V_2 , unsigned V_6 )
{
T_1 V_4 ;
F_11 ( V_2 -> V_7 , V_6 , & V_4 ) ;
F_3 ( L_1 , V_2 , V_6 , V_4 ) ;
return V_4 ;
}
static inline void F_12 ( struct V_1 * V_2 , unsigned V_6 , T_2 V_4 )
{
F_3 ( L_2 , V_2 , V_6 , V_4 ) ;
F_13 ( V_2 -> V_7 , V_6 , V_4 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , unsigned V_6 , T_3 V_4 )
{
F_3 ( L_3 , V_2 , V_6 , V_4 ) ;
F_15 ( V_2 -> V_7 , V_6 , V_4 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , unsigned V_6 , T_1 V_4 )
{
F_3 ( L_1 , V_2 , V_6 , V_4 ) ;
F_17 ( V_2 -> V_7 , V_6 , V_4 ) ;
}
static inline T_2 F_18 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_4 = F_19 ( V_2 -> V_5 + 0x800 + V_3 ) ;
F_3 ( L_2 , V_2 , V_3 , V_4 ) ;
return V_4 ;
}
static inline T_2 F_20 ( struct V_1 * V_2 , unsigned V_3 )
{
T_3 V_4 ;
V_4 = F_19 ( V_2 -> V_5 + 0x800 + V_3 ) ;
V_4 |= F_19 ( V_2 -> V_5 + 0x800 + V_3 + 1 ) << 8 ;
F_3 ( L_3 , V_2 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_21 ( struct V_1 * V_2 , unsigned V_3 , T_2 V_4 )
{
F_3 ( L_2 , V_2 , V_3 , V_4 ) ;
F_22 ( V_4 , V_2 -> V_5 + 0x800 + V_3 ) ;
F_19 ( V_2 -> V_5 + 0x800 + V_3 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned V_3 , T_3 V_4 )
{
F_3 ( L_3 , V_2 , V_3 , V_4 ) ;
F_22 ( V_4 , V_2 -> V_5 + 0x800 + V_3 ) ;
F_22 ( V_4 >> 8 , V_2 -> V_5 + 0x800 + V_3 + 1 ) ;
F_19 ( V_2 -> V_5 + 0x800 + V_3 ) ;
F_19 ( V_2 -> V_5 + 0x800 + V_3 + 1 ) ;
}
static T_4 F_24 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_7 = F_25 ( V_9 ) ;
struct V_1 * V_2 = F_26 ( V_7 ) ;
int V_6 = 0 , V_14 ;
V_6 = snprintf ( V_12 , V_15 , L_4 ) ;
for ( V_14 = 0 ; V_14 < 0x24 ; V_14 += 4 ) {
unsigned V_4 ;
if ( ! ( V_14 & 15 ) )
V_6 += snprintf ( V_12 + V_6 , V_15 - V_6 , L_5 , V_14 ) ;
V_4 = F_1 ( V_2 , V_14 ) ;
V_6 += snprintf ( V_12 + V_6 , V_15 - V_6 , L_6 , V_4 ) ;
}
V_6 += snprintf ( V_12 + V_6 , V_15 - V_6 , L_7 ) ;
for ( V_14 = 0 ; V_14 < 0x45 ; V_14 ++ ) {
unsigned char V_4 ;
if ( ! ( V_14 & 7 ) ) {
if ( V_14 & 8 ) {
memcpy ( V_12 + V_6 , L_8 , 2 ) ;
V_6 += 2 ;
} else
V_6 += snprintf ( V_12 + V_6 , V_15 - V_6 , L_5 , V_14 ) ;
}
V_4 = F_18 ( V_2 , V_14 ) ;
V_6 += snprintf ( V_12 + V_6 , V_15 - V_6 , L_9 , V_4 ) ;
}
V_12 [ V_6 ++ ] = '\n' ;
return V_6 ;
}
static int F_27 ( struct V_16 * V_17 , unsigned int * V_18 )
{
struct V_1 * V_2 = F_28 ( V_17 , struct V_1 , V_2 ) ;
unsigned int V_4 ;
T_1 V_19 = F_1 ( V_2 , V_20 ) ;
V_4 = ( V_19 & V_21 ) ? V_22 : 0 ;
V_4 |= ( V_19 & V_23 ) ? V_24 : 0 ;
V_4 |= ( V_19 & ( V_25 | V_21 | V_23 | V_26 ) ) ? 0 : V_27 ;
V_4 |= ( V_19 & ( V_28 | V_29 ) ) ? V_27 : 0 ;
if ( V_19 & V_30 ) {
V_4 |= V_31 ;
V_4 |= ( V_19 & V_32 ) ? V_33 : 0 ;
V_4 |= ( V_19 & ( V_28 | V_29 ) ) ? 0 : V_34 ;
V_4 |= ( V_19 & V_35 ) ? V_36 | V_37 : 0 ;
} else if ( V_19 & V_38 ) {
T_2 V_39 = F_18 ( V_2 , V_40 ) ;
V_4 |= ( ( V_39 & V_41 ) == V_41 ) ? V_34 : 0 ;
if ( F_18 ( V_2 , V_42 ) & V_43 ) {
V_4 |= ( V_39 & V_44 ) ? 0 : V_33 ;
} else {
V_4 |= ( V_39 & V_45 ) ? 0 : V_46 ;
V_4 |= ( V_39 & V_47 ) ? 0 : V_48 ;
}
V_4 |= ( V_39 & V_49 ) ? V_50 : 0 ;
V_4 |= ( V_39 & V_51 ) ? V_37 : 0 ;
V_4 |= ( V_39 & V_52 ) ? V_36 : 0 ;
}
* V_18 = V_4 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , T_5 * V_19 )
{
if ( ! ( F_1 ( V_2 , V_20 ) & V_30 ) &&
( V_2 -> V_53 & V_54 ) ) {
T_2 V_3 , V_55 ;
V_3 = V_55 = F_18 ( V_2 , V_56 ) ;
V_3 &= ~ ( V_57 | V_58 | V_59 ) ;
if ( V_2 -> V_53 & V_60 ) {
switch ( V_19 -> V_61 ) {
case 33 :
V_3 |= V_62 ;
break;
case 50 :
V_3 |= V_63 ;
break;
default:
V_3 = 0 ;
break;
}
switch ( V_19 -> V_64 ) {
case 33 :
case 50 :
V_3 |= V_65 ;
break;
case 120 :
V_3 |= V_66 ;
break;
}
} else {
switch ( V_19 -> V_61 ) {
case 50 :
V_3 |= V_63 ;
break;
default:
V_3 = 0 ;
break;
}
switch ( V_19 -> V_64 ) {
case 50 :
V_3 |= V_65 | V_67 ;
break;
case 120 :
V_3 |= V_66 | V_68 ;
break;
}
}
if ( V_3 != V_55 )
F_21 ( V_2 , V_56 , V_3 ) ;
} else {
T_1 V_3 = 0 ;
switch ( V_19 -> V_61 ) {
case 33 :
V_3 = V_69 ;
break;
case 50 :
V_3 = V_70 ;
break;
default:
V_3 = 0 ;
break;
}
switch ( V_19 -> V_64 ) {
case 33 :
V_3 |= V_71 ;
break;
case 50 :
V_3 |= V_72 ;
break;
case 120 :
V_3 |= V_73 ;
break;
}
if ( V_3 != F_1 ( V_2 , V_74 ) )
F_4 ( V_2 , V_74 , V_3 ) ;
}
}
static int F_30 ( struct V_16 * V_17 , T_5 * V_19 )
{
struct V_1 * V_2 = F_28 ( V_17 , struct V_1 , V_2 ) ;
T_3 V_75 ;
if ( V_19 -> V_61 == 0 )
F_29 ( V_2 , V_19 ) ;
V_2 -> V_76 = V_19 -> V_76 ;
V_75 = F_8 ( V_2 , V_77 ) & ~ ( V_78 | V_79 ) ;
if ( F_1 ( V_2 , V_20 ) & V_30 ) {
T_2 V_80 ;
V_75 |= ( V_19 -> V_53 & V_81 ) ? V_78 : 0 ;
V_80 = F_18 ( V_2 , V_42 ) ;
V_80 = ( V_80 & ~ 0xf ) ;
if ( ! V_2 -> V_7 -> V_82 ) {
V_80 |= V_2 -> V_83 ? V_2 -> V_83 : V_19 -> V_76 ;
V_75 |= V_79 ;
}
F_21 ( V_2 , V_42 , V_80 ) ;
} else {
T_2 V_3 ;
V_3 = F_18 ( V_2 , V_42 ) & ( V_84 | V_85 ) ;
V_3 |= ( V_19 -> V_53 & V_81 ) ? 0 : V_86 ;
V_3 |= ( V_19 -> V_53 & V_87 ) ? V_43 : 0 ;
if ( V_19 -> V_76 != V_2 -> V_7 -> V_82 ) {
V_3 |= V_19 -> V_76 ;
V_75 |= V_79 ;
}
F_21 ( V_2 , V_42 , V_3 ) ;
V_3 = F_18 ( V_2 , V_56 ) & ( V_57 | V_58 ) ;
V_3 |= V_88 ;
if ( V_19 -> V_53 & V_89 )
V_3 |= V_90 ;
if ( V_19 -> V_53 & V_91 )
V_3 |= V_92 ;
if ( F_18 ( V_2 , V_56 ) != V_3 )
F_21 ( V_2 , V_56 , V_3 ) ;
V_3 = F_18 ( V_2 , V_93 ) ;
V_3 &= V_94 ;
V_3 |= V_95 ;
if ( V_19 -> V_53 & V_87 ) {
if ( V_19 -> V_96 & V_33 )
V_3 |= V_97 ;
} else {
if ( V_19 -> V_96 & V_46 )
V_3 |= V_98 ;
if ( V_19 -> V_96 & V_48 )
V_3 |= V_99 ;
if ( V_19 -> V_96 & V_37 )
V_3 |= V_100 ;
}
F_21 ( V_2 , V_93 , V_3 ) ;
F_18 ( V_2 , V_101 ) ;
if ( V_17 -> V_102 )
V_17 -> V_102 ( V_17 , V_19 -> V_53 & V_103 ) ;
}
F_14 ( V_2 , V_77 , V_75 ) ;
F_4 ( V_2 , V_104 , - 1 ) ;
F_4 ( V_2 , V_105 , V_106 ) ;
if ( V_19 -> V_61 != 0 )
F_29 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 , struct V_107 * V_108 )
{
struct V_1 * V_2 = F_28 ( V_17 , struct V_1 , V_2 ) ;
int V_109 ;
unsigned char V_110 , V_111 , V_112 ;
V_109 = V_108 -> V_109 ;
if ( V_109 > 1 )
return - V_113 ;
V_112 = F_32 ( V_109 ) ;
V_111 = F_18 ( V_2 , V_114 ) ;
if ( V_111 & V_112 ) {
V_111 &= ~ V_112 ;
F_21 ( V_2 , V_114 , V_111 ) ;
}
F_23 ( V_2 , F_33 ( V_109 ) + V_115 , V_108 -> V_116 ) ;
F_23 ( V_2 , F_33 ( V_109 ) + V_117 , V_108 -> V_118 ) ;
V_110 = F_18 ( V_2 , V_119 ) & ~ F_34 ( V_109 ) ;
if ( V_108 -> V_53 & V_120 )
V_110 |= F_35 ( V_109 ) ;
if ( V_108 -> V_53 & V_121 )
V_110 |= F_36 ( V_109 ) ;
if ( V_108 -> V_53 & V_122 )
V_110 |= F_37 ( V_109 ) ;
F_21 ( V_2 , V_119 , V_110 ) ;
if ( V_108 -> V_53 & V_123 )
F_21 ( V_2 , V_114 , V_111 | V_112 ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 , struct V_124 * V_125 )
{
struct V_1 * V_2 = F_28 ( V_17 , struct V_1 , V_2 ) ;
struct V_126 V_127 ;
int V_109 ;
unsigned char V_111 , V_112 ;
unsigned int V_116 , V_118 , V_128 ;
unsigned short V_129 ;
F_39 ( V_2 -> V_7 , & V_127 , V_125 -> V_130 ) ;
V_109 = V_125 -> V_109 ;
V_116 = V_127 . V_116 ;
V_118 = V_127 . V_131 ;
V_128 = V_125 -> V_128 ;
if ( V_109 > 4 || V_116 > V_118 || ( ( V_116 ^ V_118 ) >> 24 ) ||
( V_128 >> 26 ) || V_125 -> V_132 > 1000 )
return - V_113 ;
V_112 = F_40 ( V_109 ) ;
V_111 = F_18 ( V_2 , V_114 ) ;
if ( V_111 & V_112 ) {
V_111 &= ~ V_112 ;
F_21 ( V_2 , V_114 , V_111 ) ;
}
F_21 ( V_2 , F_41 ( V_109 ) , V_116 >> 24 ) ;
V_129 = ( V_116 >> 12 ) & 0x0fff ;
if ( V_125 -> V_53 & V_121 )
V_129 |= V_133 ;
if ( V_125 -> V_53 & V_120 )
V_129 |= V_134 ;
F_23 ( V_2 , F_42 ( V_109 ) + V_115 , V_129 ) ;
V_129 = ( V_118 >> 12 ) & 0x0fff ;
switch ( F_43 ( V_125 -> V_132 ) ) {
case 0 :
break;
case 1 :
V_129 |= V_135 ;
break;
case 2 :
V_129 |= V_136 ;
break;
default:
V_129 |= V_136 | V_135 ;
break;
}
F_23 ( V_2 , F_42 ( V_109 ) + V_117 , V_129 ) ;
V_129 = ( ( V_128 - V_116 ) >> 12 ) & 0x3fff ;
if ( V_125 -> V_53 & V_137 )
V_129 |= V_138 ;
if ( V_125 -> V_53 & V_139 )
V_129 |= V_140 ;
F_23 ( V_2 , F_42 ( V_109 ) + V_141 , V_129 ) ;
if ( V_125 -> V_53 & V_123 )
F_21 ( V_2 , V_114 , V_111 | V_112 ) ;
return 0 ;
}
static T_6 F_44 ( int V_82 , void * V_142 )
{
unsigned int V_143 ;
struct V_1 * V_2 = (struct V_1 * ) V_142 ;
T_2 V_144 ;
T_1 V_145 ;
V_145 = F_1 ( V_2 , V_104 ) ;
F_4 ( V_2 , V_104 , V_145 ) ;
V_144 = F_18 ( V_2 , V_101 ) ;
if ( ! ( V_145 || V_144 ) )
return V_146 ;
V_143 = ( V_145 & ( V_147 | V_148 ) ) ? V_34 : 0 ;
V_143 |= ( V_144 & V_95 ) ? V_34 : 0 ;
if ( F_18 ( V_2 , V_42 ) & V_43 ) {
V_143 |= ( V_144 & V_97 ) ? V_33 : 0 ;
} else {
V_143 |= ( V_144 & V_98 ) ? V_46 : 0 ;
V_143 |= ( V_144 & V_99 ) ? V_48 : 0 ;
V_143 |= ( V_144 & V_100 ) ? V_37 : 0 ;
}
if ( V_143 )
F_45 ( & V_2 -> V_2 , V_143 ) ;
return V_149 ;
}
static void F_46 ( unsigned long V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_150 ;
F_44 ( 0 , ( void * ) V_2 ) ;
V_2 -> V_151 . V_152 = V_153 + V_154 ;
F_47 ( & V_2 -> V_151 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_155 V_130 = { . V_116 = 0 , . V_131 = 0x0fff } ;
V_107 V_108 = { 0 , 0 , 0 , 0 , 1 } ;
V_124 V_125 = { . V_130 = & V_130 , } ;
F_30 ( & V_2 -> V_2 , & V_156 ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
V_108 . V_109 = V_14 ;
F_31 ( & V_2 -> V_2 , & V_108 ) ;
}
for ( V_14 = 0 ; V_14 < 5 ; V_14 ++ ) {
V_125 . V_109 = V_14 ;
F_38 ( & V_2 -> V_2 , & V_125 ) ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
T_1 V_19 ;
V_19 = F_1 ( V_2 , V_20 ) ;
if ( ! ( V_19 & ( V_25 | V_21 | V_23 | V_26 ) ) ||
( V_19 & ( V_28 | V_29 | V_157 | V_158 ) ) ||
( ( V_19 & ( V_38 | V_30 ) ) == ( V_38 | V_30 ) ) )
F_4 ( V_2 , V_159 , V_160 ) ;
}
static int F_50 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_28 ( V_17 , struct V_1 , V_2 ) ;
F_21 ( V_2 , V_161 , 0x00 ) ;
F_21 ( V_2 , V_162 , 0x00 ) ;
F_49 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( V_2 -> type && V_2 -> type -> V_163 )
V_2 -> type -> V_163 ( V_2 ) ;
F_4 ( V_2 , V_105 , V_106 ) ;
return 0 ;
}
static int F_51 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_28 ( V_17 , struct V_1 , V_2 ) ;
F_4 ( V_2 , V_105 , 0x0 ) ;
return 0 ;
}
static int F_52 ( struct V_155 * V_164 , struct V_155 * V_130 ,
T_1 V_165 )
{
T_1 V_166 , V_167 , V_116 , V_131 ;
if ( V_130 -> V_53 & V_168 ) {
V_166 = 1024 ;
V_167 = V_169 ;
V_116 = V_170 ;
V_131 = ~ 0U ;
} else {
unsigned long V_171 = V_164 -> V_131 - V_164 -> V_116 ;
int V_14 ;
V_167 = V_172 ;
if ( V_167 > V_171 / 8 ) {
V_167 = ( V_171 + 1 ) / 8 ;
V_14 = 0 ;
while ( ( V_167 /= 2 ) != 0 )
V_14 ++ ;
V_167 = 1 << V_14 ;
}
if ( V_167 < V_165 )
V_167 = V_165 ;
V_166 = V_167 ;
V_116 = V_173 ;
V_131 = ~ 0U ;
}
do {
if ( F_53 ( V_164 , V_130 , V_167 , V_116 , V_131 , V_166 ,
NULL , NULL ) == 0 ) {
return 1 ;
}
V_167 = V_167 / 2 ;
V_166 = V_167 ;
} while ( V_167 >= V_165 );
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_155 * V_130 ,
T_1 V_165 )
{
struct V_155 * V_164 ;
int V_14 ;
F_55 (socket->dev->bus, root, i) {
if ( ! V_164 )
continue;
if ( ( V_130 -> V_53 ^ V_164 -> V_53 ) &
( V_168 | V_174 | V_175 ) )
continue;
if ( F_52 ( V_164 , V_130 , V_165 ) )
return 1 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int V_176 , unsigned type , int V_177 , int V_178 )
{
struct V_13 * V_7 = V_2 -> V_7 ;
struct V_155 * V_130 ;
struct V_126 V_127 ;
unsigned V_179 ;
V_130 = V_7 -> V_155 + V_180 + V_176 ;
if ( V_130 -> V_181 )
return 0 ;
V_179 = ~ 0xfff ;
if ( type & V_168 )
V_179 = ~ 3 ;
V_130 -> V_182 = V_7 -> V_183 -> V_182 ;
V_130 -> V_53 = type ;
V_127 . V_116 = F_10 ( V_2 , V_177 ) & V_179 ;
V_127 . V_131 = F_10 ( V_2 , V_178 ) | ~ V_179 ;
if ( V_127 . V_116 && V_127 . V_131 > V_127 . V_116 && ! V_184 ) {
F_57 ( V_7 , V_130 , & V_127 ) ;
if ( F_58 ( V_7 , V_180 + V_176 ) == 0 )
return 0 ;
F_59 ( V_185 , & V_7 -> V_7 ,
L_10
L_11 ,
V_176 ) ;
}
if ( type & V_168 ) {
if ( ( F_54 ( V_2 , V_130 , V_169 ) ) ||
( F_54 ( V_2 , V_130 , V_186 ) ) ||
( F_54 ( V_2 , V_130 , V_187 ) ) )
return 1 ;
} else {
if ( type & V_175 ) {
if ( ( F_54 ( V_2 , V_130 , V_172 ) ) ||
( F_54 ( V_2 , V_130 , V_188 ) ) ||
( F_54 ( V_2 , V_130 , V_189 ) ) )
return 1 ;
V_130 -> V_53 = V_174 ;
}
if ( ( F_54 ( V_2 , V_130 , V_172 ) ) ||
( F_54 ( V_2 , V_130 , V_188 ) ) ||
( F_54 ( V_2 , V_130 , V_189 ) ) )
return 1 ;
}
F_59 ( V_185 , & V_7 -> V_7 ,
L_12 ,
type ) ;
V_130 -> V_116 = V_130 -> V_131 = V_130 -> V_53 = 0 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_190 = 0 ;
V_190 += F_56 ( V_2 , 0 , V_168 ,
V_191 , V_192 ) ;
V_190 += F_56 ( V_2 , 1 , V_168 ,
V_193 , V_194 ) ;
V_190 += F_56 ( V_2 , 2 , V_174 | V_175 ,
V_195 , V_196 ) ;
V_190 += F_56 ( V_2 , 3 , V_174 ,
V_197 , V_198 ) ;
if ( V_190 )
F_61 ( V_2 -> V_7 -> V_183 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
struct V_155 * V_130 ;
V_130 = V_2 -> V_7 -> V_155 + V_180 + V_14 ;
if ( V_130 -> V_116 != 0 && V_130 -> V_131 != 0 )
F_63 ( V_130 ) ;
V_130 -> V_116 = V_130 -> V_131 = V_130 -> V_53 = 0 ;
}
}
static void T_7 F_64 ( struct V_13 * V_7 )
{
struct V_1 * V_17 = F_26 ( V_7 ) ;
F_65 ( & V_7 -> V_7 , & V_199 ) ;
F_66 ( & V_17 -> V_2 ) ;
F_4 ( V_17 , V_105 , 0x0 ) ;
F_21 ( V_17 , V_93 , 0 ) ;
if ( V_17 -> V_83 )
F_67 ( V_17 -> V_83 , V_17 ) ;
else
F_68 ( & V_17 -> V_151 ) ;
if ( V_17 -> V_5 )
F_69 ( V_17 -> V_5 ) ;
F_62 ( V_17 ) ;
F_70 ( V_7 ) ;
F_71 ( V_7 ) ;
F_72 ( V_7 , NULL ) ;
}
static unsigned int F_73 ( struct V_1 * V_2 , T_1 V_200 )
{
int V_14 ;
unsigned long V_4 ;
T_1 V_179 ;
T_2 V_3 ;
F_4 ( V_2 , V_104 , - 1 ) ;
F_4 ( V_2 , V_105 , V_201 ) ;
V_3 = F_18 ( V_2 , V_93 ) ;
F_21 ( V_2 , V_93 , 0 ) ;
V_4 = F_74 () & V_200 ;
for ( V_14 = 1 ; V_14 < 16 ; V_14 ++ ) {
if ( ! ( ( V_4 >> V_14 ) & 1 ) )
continue;
F_21 ( V_2 , V_93 , V_97 | ( V_14 << 4 ) ) ;
F_4 ( V_2 , V_159 , V_202 ) ;
F_75 ( 100 ) ;
F_4 ( V_2 , V_104 , - 1 ) ;
}
F_4 ( V_2 , V_105 , 0 ) ;
F_21 ( V_2 , V_93 , V_3 ) ;
V_179 = F_76 ( V_4 ) & 0xffff ;
return V_179 ;
}
static T_6 F_77 ( int V_82 , void * V_142 )
{
struct V_1 * V_2 = (struct V_1 * ) V_142 ;
T_2 V_144 ;
T_1 V_145 ;
V_145 = F_1 ( V_2 , V_104 ) ;
F_4 ( V_2 , V_104 , - 1 ) ;
V_144 = F_18 ( V_2 , V_101 ) ;
if ( V_145 || V_144 ) {
V_2 -> V_203 = 1 ;
return V_149 ;
}
return V_146 ;
}
static int F_78 ( struct V_1 * V_2 )
{
T_2 V_3 = 0 ;
if ( ! V_2 -> V_83 )
return - 1 ;
V_2 -> V_203 = 0 ;
if ( F_79 ( V_2 -> V_83 , F_77 , V_204 , L_13 , V_2 ) ) {
F_59 ( V_205 , & V_2 -> V_7 -> V_7 ,
L_14 ) ;
return - 1 ;
}
if ( ! V_2 -> V_7 -> V_82 )
V_3 = F_18 ( V_2 , V_93 ) ;
F_21 ( V_2 , V_93 , V_3 | V_97 ) ;
F_4 ( V_2 , V_104 , - 1 ) ;
F_4 ( V_2 , V_105 , V_201 ) ;
F_4 ( V_2 , V_159 , V_202 ) ;
F_80 ( 100 ) ;
F_4 ( V_2 , V_105 , 0 ) ;
F_21 ( V_2 , V_93 , V_3 ) ;
F_4 ( V_2 , V_104 , - 1 ) ;
F_18 ( V_2 , V_101 ) ;
F_67 ( V_2 -> V_83 , V_2 ) ;
return ( int ) V_2 -> V_203 ;
}
static void F_81 ( struct V_1 * V_2 , T_1 V_200 )
{
V_2 -> V_2 . V_206 = V_2 -> V_83 ;
if ( V_207 )
V_2 -> V_2 . V_208 = F_73 ( V_2 , V_200 ) ;
else
V_2 -> V_2 . V_208 = 0 ;
F_59 ( V_185 , & V_2 -> V_7 -> V_7 ,
L_15 ,
V_2 -> V_2 . V_208 , V_2 -> V_83 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
T_3 V_75 ;
struct V_13 * V_7 = V_2 -> V_7 ;
struct V_126 V_127 ;
F_39 ( V_2 -> V_7 , & V_127 , & V_7 -> V_155 [ 0 ] ) ;
F_16 ( V_2 , V_209 , 0 ) ;
F_16 ( V_2 , V_210 , V_127 . V_116 ) ;
F_14 ( V_2 , V_211 ,
V_212 |
V_213 |
V_214 |
V_215 ) ;
F_12 ( V_2 , V_216 , V_217 / 4 ) ;
F_12 ( V_2 , V_218 , 168 ) ;
F_16 ( V_2 , V_219 ,
( 176 << 24 ) |
( ( unsigned int ) V_7 -> V_183 -> V_220 . V_131 << 16 ) |
( ( unsigned int ) V_7 -> V_183 -> V_220 . V_116 << 8 ) |
V_7 -> V_183 -> V_221 ) ;
V_75 = F_8 ( V_2 , V_77 ) ;
V_75 &= ~ ( V_78 | V_222 | V_223 | V_224 ) ;
V_75 |= V_225 | V_226 ;
F_14 ( V_2 , V_77 , V_75 ) ;
}
static void F_83 ( struct V_227 * V_228 )
{
struct V_229 * V_230 ;
unsigned char V_231 ;
struct V_227 * V_232 = V_228 -> V_181 ;
if ( V_232 -> V_220 . V_131 >= V_228 -> V_220 . V_131 )
return;
if ( ! V_232 -> V_181 )
return;
V_231 = V_232 -> V_181 -> V_220 . V_131 ;
F_84 (tmp, &bridge_to_fix->parent->children) {
struct V_227 * V_233 = F_85 ( V_230 ) ;
if ( V_233 -> V_220 . V_116 > V_232 -> V_220 . V_131
&& V_233 -> V_220 . V_116 <= V_231 )
V_231 = V_233 -> V_220 . V_116 - 1 ;
}
if ( V_228 -> V_220 . V_131 > V_231 )
F_59 ( V_205 , & V_228 -> V_7 ,
L_16
L_17 , V_231 ) ;
if ( V_232 -> V_220 . V_131 < V_231 ) {
unsigned char V_234 =
F_86 ( int , V_228 -> V_220 . V_131 , V_231 ) ;
F_59 ( V_185 , & V_232 -> V_7 ,
L_18
L_19 ,
V_232 -> V_235 ,
( int ) V_232 -> V_220 . V_131 , V_234 ) ;
V_232 -> V_220 . V_131 = V_234 ;
F_13 ( V_232 -> V_236 ,
V_237 , V_232 -> V_220 . V_131 ) ;
}
}
static int T_8 F_87 ( struct V_13 * V_7 , const struct V_238 * V_239 )
{
struct V_1 * V_2 ;
int V_240 ;
if ( ! V_7 -> V_183 ) {
F_59 ( V_241 , & V_7 -> V_7 , L_20
L_21 ) ;
return - V_242 ;
}
V_2 = F_88 ( sizeof( struct V_1 ) , V_243 ) ;
if ( ! V_2 )
return - V_244 ;
V_2 -> V_2 . V_245 = & V_246 ;
V_2 -> V_2 . V_247 = & V_248 ;
V_2 -> V_2 . V_7 . V_181 = & V_7 -> V_7 ;
V_2 -> V_2 . V_249 = V_2 ;
V_2 -> V_2 . V_250 = V_251 ;
V_2 -> V_2 . V_252 = V_253 | V_254 ;
V_2 -> V_2 . V_255 = 0x1000 ;
V_2 -> V_2 . V_256 = V_7 ;
V_2 -> V_7 = V_7 ;
F_72 ( V_7 , V_2 ) ;
if ( F_89 ( V_7 ) ) {
V_240 = - V_257 ;
goto free;
}
V_240 = F_90 ( V_7 , L_22 ) ;
if ( V_240 )
goto V_258;
if ( ! F_91 ( V_7 , 0 ) ) {
F_59 ( V_241 , & V_7 -> V_7 , L_23 ) ;
V_240 = - V_242 ;
goto V_259;
}
V_2 -> V_5 = F_92 ( F_91 ( V_7 , 0 ) , 0x1000 ) ;
if ( ! V_2 -> V_5 ) {
V_240 = - V_244 ;
goto V_259;
}
F_59 ( V_185 , & V_7 -> V_7 , L_24 ,
V_7 -> V_260 , V_7 -> V_261 ) ;
F_82 ( V_2 ) ;
F_4 ( V_2 , V_105 , 0x0 ) ;
F_60 ( V_2 ) ;
V_2 -> V_83 = V_7 -> V_82 ;
if ( V_239 -> V_249 != V_262 &&
V_239 -> V_249 < F_93 ( V_263 ) ) {
V_2 -> type = & V_263 [ V_239 -> V_249 ] ;
V_240 = V_2 -> type -> V_264 ( V_2 ) ;
if ( V_240 < 0 )
goto V_265;
}
if ( ! V_2 -> V_83 || F_79 ( V_2 -> V_83 , F_44 , V_204 , L_13 , V_2 ) ) {
V_2 -> V_83 = 0 ;
F_94 ( & V_2 -> V_151 ) ;
V_2 -> V_151 . V_266 = F_46 ;
V_2 -> V_151 . V_150 = ( unsigned long ) V_2 ;
V_2 -> V_151 . V_152 = V_153 + V_154 ;
F_47 ( & V_2 -> V_151 ) ;
F_59 ( V_185 , & V_7 -> V_7 ,
L_25
L_26 ) ;
F_59 ( V_185 , & V_7 -> V_7 ,
L_27
L_28 ) ;
} else {
V_2 -> V_2 . V_252 |= V_267 ;
}
F_49 ( V_2 ) ;
F_81 ( V_2 , V_268 ) ;
F_59 ( V_185 , & V_7 -> V_7 ,
L_29 , F_1 ( V_2 , V_20 ) ) ;
F_83 ( V_7 -> V_183 ) ;
V_240 = F_95 ( & V_2 -> V_2 ) ;
if ( V_240 == 0 ) {
V_240 = F_96 ( & V_7 -> V_7 , & V_199 ) ;
if ( V_240 == 0 )
goto V_269;
F_66 ( & V_2 -> V_2 ) ;
}
V_265:
F_69 ( V_2 -> V_5 ) ;
V_259:
F_70 ( V_7 ) ;
V_258:
F_71 ( V_7 ) ;
free:
F_97 ( V_2 ) ;
V_269:
return V_240 ;
}
static int F_98 ( struct V_8 * V_7 )
{
struct V_13 * V_270 = F_25 ( V_7 ) ;
struct V_1 * V_2 = F_26 ( V_270 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> type && V_2 -> type -> V_271 )
V_2 -> type -> V_271 ( V_2 ) ;
F_99 ( V_270 ) ;
F_11 ( V_270 , 16 * 4 , & V_2 -> V_272 [ 0 ] ) ;
F_11 ( V_270 , 17 * 4 , & V_2 -> V_272 [ 1 ] ) ;
F_71 ( V_270 ) ;
return 0 ;
}
static int F_100 ( struct V_8 * V_7 )
{
struct V_13 * V_270 = F_25 ( V_7 ) ;
struct V_1 * V_2 = F_26 ( V_270 ) ;
int V_240 ;
if ( ! V_2 )
return 0 ;
F_17 ( V_270 , 16 * 4 , V_2 -> V_272 [ 0 ] ) ;
F_17 ( V_270 , 17 * 4 , V_2 -> V_272 [ 1 ] ) ;
V_240 = F_89 ( V_270 ) ;
if ( V_240 )
return V_240 ;
F_101 ( V_270 ) ;
if ( V_2 -> type && V_2 -> type -> V_273 )
V_2 -> type -> V_273 ( V_2 ) ;
return 0 ;
}
static int T_9 F_102 ( void )
{
return F_103 ( & V_274 ) ;
}
static void T_10 F_104 ( void )
{
F_105 ( & V_274 ) ;
}
