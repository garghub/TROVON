static inline void F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned long V_4 )
{
F_2 ( L_1 , V_3 , V_4 ) ;
F_3 ( V_3 , V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
F_2 ( L_2 , V_3 , V_4 ) ;
F_5 ( V_3 , V_4 ) ;
}
static inline unsigned long F_6 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
unsigned long V_3 ;
V_3 = F_7 ( V_4 ) ;
F_2 ( L_3 , V_3 , V_4 ) ;
return V_3 ;
}
static inline unsigned char F_8 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
unsigned char V_3 ;
V_3 = F_9 ( V_4 ) ;
F_2 ( L_4 , V_3 , V_4 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = NULL ;
int V_9 , V_10 ;
struct V_11 * V_12 ;
F_11 ( L_5 ) ;
if ( F_12 ( V_2 , sizeof( struct V_13 ) ) < 0 )
return - V_14 ;
F_13 (pci_device) {
if ( V_8 -> V_15 == V_16 ) {
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ ) {
if ( V_18 [ V_10 ] . V_19 ==
V_8 -> V_20 ) {
if ( ( V_6 -> V_21 [ 0 ] != 0 )
|| ( V_6 -> V_21 [ 1 ] != 0 ) ) {
if ( V_8 -> V_22 -> V_23 !=
V_6 -> V_21 [ 0 ]
||
F_14 ( V_8 -> V_24 )
!= V_6 -> V_21 [ 1 ] ) {
continue;
}
}
V_2 -> V_25 = V_18 + V_10 ;
V_12 =
(struct V_11 * )
V_2 -> V_25 ;
V_26 -> V_27 = V_8 ;
goto V_28;
}
}
}
}
F_15 ( V_29
L_6
L_7 ,
V_2 -> V_30 , V_6 -> V_21 [ 0 ] , V_6 -> V_21 [ 1 ] ) ;
return - V_31 ;
V_28:
F_15 ( V_32
L_6
L_8 ,
V_2 -> V_30 , V_18 [ V_10 ] . V_33 , V_8 -> V_22 -> V_23 ,
F_14 ( V_8 -> V_24 ) ) ;
V_2 -> V_34 = V_12 -> V_33 ;
V_9 = F_16 ( V_8 , V_2 -> V_34 ) ;
if ( V_9 ) {
F_15 ( V_29
L_9
L_10 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_17 ( V_2 , V_8 ) ;
if ( V_9 ) {
F_15 ( V_29
L_6
L_11 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_18 ( V_2 , V_8 ) ;
if ( V_9 ) {
F_15 ( V_29
L_6
L_12 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_19 ( V_2 ) ;
if ( V_9 ) {
F_15 ( V_29
L_6
L_13 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_20 ( V_2 ) ;
if ( V_9 ) {
F_15 ( V_29
L_6
L_14 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_21 ( V_2 ) ;
if ( V_9 ) {
F_15 ( V_29
L_6
L_15 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_22 ( V_2 ) ;
if ( V_9 ) {
F_15 ( V_29
L_6
L_16 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_23 ( V_2 ) ;
if ( V_9 ) {
F_15 ( V_29
L_6
L_17 , V_2 -> V_30 ) ;
return V_9 ;
}
V_9 = F_24 ( V_2 ) ;
if ( V_9 ) {
F_15 ( V_29
L_18 ,
V_2 -> V_30 ) ;
return V_9 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_7 * V_27 )
{
F_11 ( L_19 ) ;
V_26 -> V_35 = F_25 ( V_27 , 1 ) ;
if ( V_26 -> V_35 == 0 ) {
F_15 ( V_29
L_20
L_21 , V_2 -> V_30 ) ;
return - V_31 ;
}
V_26 -> V_36 = F_26 ( V_27 , 1 ) ;
V_26 -> V_37 = F_25 ( V_27 , 2 ) ;
if ( V_26 -> V_37 == 0 ) {
F_15 ( V_29
L_20
L_22 , V_2 -> V_30 ) ;
return - V_31 ;
}
V_26 -> V_38 = F_26 ( V_27 , 2 ) ;
V_26 -> V_39 = F_25 ( V_27 , 3 ) ;
if ( V_26 -> V_39 == 0 ) {
F_15 ( V_29
L_20
L_23 , V_2 -> V_30 ) ;
return - V_31 ;
}
V_26 -> V_40 = F_26 ( V_27 , 3 ) ;
V_26 -> V_41 = F_25 ( V_27 , 5 ) ;
if ( V_26 -> V_41 == 0 ) {
F_15 ( V_29
L_20
L_24 , V_2 -> V_30 ) ;
return - V_31 ;
}
V_26 -> V_42 = F_26 ( V_27 , 5 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_7 * V_27 )
{
int V_9 ;
F_11 ( L_25 ) ;
V_9 = F_27 ( V_27 , 0x2C , & V_26 -> V_43 ) ;
if ( V_9 != V_44 )
return V_9 ;
V_9 = F_28 ( V_27 , 0x08 , & V_26 -> V_45 ) ;
if ( V_9 != V_44 )
return V_9 ;
V_26 -> V_46 = V_27 -> V_15 ;
V_26 -> V_19 = V_27 -> V_20 ;
V_26 -> V_47 = V_27 -> V_47 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_10 ;
F_11 ( L_26 ) ;
for ( V_10 = 0 ; V_10 < V_48 -> V_49 . V_50 ; V_10 ++ ) {
V_26 -> V_51 [ V_10 ] . V_47 = V_26 -> V_47 ;
switch ( V_10 ) {
case 0 :
V_26 -> V_51 [ V_10 ] . V_52 =
V_26 -> V_37 + V_53 ;
V_26 -> V_51 [ V_10 ] . V_54 =
V_26 -> V_37 + V_55 ;
V_26 -> V_51 [ V_10 ] . V_56 =
V_26 -> V_37 + V_57 ;
V_26 -> V_51 [ V_10 ] . V_58 =
V_26 -> V_37 + V_59 ;
V_26 -> V_51 [ V_10 ] . V_60 =
V_26 -> V_37 + V_61 ;
V_26 -> V_51 [ V_10 ] . V_62 =
V_26 -> V_37 + V_63 ;
V_26 -> V_51 [ V_10 ] . V_64 =
V_26 -> V_37 + V_65 ;
break;
case 1 :
V_26 -> V_51 [ V_10 ] . V_52 =
V_26 -> V_37 + V_66 ;
V_26 -> V_51 [ V_10 ] . V_54 =
V_26 -> V_37 + V_67 ;
V_26 -> V_51 [ V_10 ] . V_56 =
V_26 -> V_37 + V_68 ;
V_26 -> V_51 [ V_10 ] . V_58 =
V_26 -> V_37 + V_69 ;
V_26 -> V_51 [ V_10 ] . V_60 =
V_26 -> V_37 + V_70 ;
V_26 -> V_51 [ V_10 ] . V_62 =
V_26 -> V_37 + V_63 ;
V_26 -> V_51 [ V_10 ] . V_64 =
V_26 -> V_37 + V_65 ;
break;
case 2 :
V_26 -> V_51 [ V_10 ] . V_52 =
V_26 -> V_37 + V_71 ;
V_26 -> V_51 [ V_10 ] . V_54 =
V_26 -> V_37 + V_72 ;
V_26 -> V_51 [ V_10 ] . V_56 =
V_26 -> V_37 + V_73 ;
V_26 -> V_51 [ V_10 ] . V_58 =
V_26 -> V_37 + V_74 ;
V_26 -> V_51 [ V_10 ] . V_60 =
V_26 -> V_37 + V_75 ;
V_26 -> V_51 [ V_10 ] . V_62 =
V_26 -> V_37 + V_63 ;
V_26 -> V_51 [ V_10 ] . V_64 =
V_26 -> V_37 + V_65 ;
break;
case 3 :
V_26 -> V_51 [ V_10 ] . V_52 =
V_26 -> V_37 + V_76 ;
V_26 -> V_51 [ V_10 ] . V_54 =
V_26 -> V_37 + V_77 ;
V_26 -> V_51 [ V_10 ] . V_56 =
V_26 -> V_37 + V_78 ;
V_26 -> V_51 [ V_10 ] . V_58 =
V_26 -> V_37 + V_79 ;
V_26 -> V_51 [ V_10 ] . V_60 =
V_26 -> V_37 + V_80 ;
V_26 -> V_51 [ V_10 ] . V_62 =
V_26 -> V_37 + V_63 ;
V_26 -> V_51 [ V_10 ] . V_64 =
V_26 -> V_37 + V_65 ;
break;
default:
break;
}
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_11 ( L_27 ) ;
V_26 -> V_81 . V_47 = V_26 -> V_47 ;
V_26 -> V_81 . V_52 = V_26 -> V_37 + V_82 ;
V_26 -> V_81 . V_54 =
V_26 -> V_37 + V_83 ;
V_26 -> V_81 . V_84 =
V_26 -> V_37 + V_85 ;
V_26 -> V_81 . V_86 = V_26 -> V_37 + V_87 ;
V_26 -> V_81 . V_88 =
V_26 -> V_37 + V_89 ;
V_26 -> V_81 . V_90 =
V_26 -> V_37 + V_91 ;
V_26 -> V_81 . V_92 =
V_26 -> V_37 + V_93 ;
V_26 -> V_81 . V_94 =
V_26 -> V_37 + V_95 ;
V_26 -> V_81 . V_96 =
V_26 -> V_37 + V_97 ;
V_26 -> V_81 . V_98 =
V_26 -> V_37 + V_99 ;
V_26 -> V_81 . V_100 = V_26 -> V_37 + V_101 ;
V_26 -> V_81 . V_62 =
V_26 -> V_37 + V_63 ;
V_26 -> V_81 . V_102 =
V_26 -> V_37 + V_103 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_11 ( L_28 ) ;
V_26 -> V_104 . V_105 = V_26 -> V_37 + V_106 ;
V_26 -> V_104 . V_52 = V_26 -> V_37 + V_107 ;
V_26 -> V_104 . V_108 =
V_26 -> V_37 + V_109 ;
V_26 -> V_104 . V_110 =
V_26 -> V_37 + V_111 ;
V_26 -> V_104 . V_112 =
V_26 -> V_37 + V_113 ;
V_26 -> V_104 . V_114 =
V_26 -> V_37 + V_115 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_11 ( L_29 ) ;
V_26 -> V_116 . V_52 = V_26 -> V_39 + V_117 ;
V_26 -> V_116 . V_118 =
V_26 -> V_39 + V_119 ;
V_26 -> V_116 . V_120 =
V_26 -> V_39 + V_121 ;
V_26 -> V_116 . V_122 =
V_26 -> V_39 + V_123 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
T_2 V_124 ;
int V_125 = 0 ;
int V_126 = 0 ;
F_11 ( L_30 ) ;
F_29 ( & V_124 ) ;
F_5 ( 0x10 , V_26 -> V_35 + V_127 ) ;
V_3 = F_7 ( V_26 -> V_35 + V_128 ) ;
V_3 |= 0x100 ;
F_5 ( V_3 , V_26 -> V_35 + V_128 ) ;
F_9 ( V_26 -> V_41 + 0xC8 ) ;
F_30 ( 20 ) ;
if ( ! ( F_7 ( V_26 -> V_35 + V_127 ) & 0x20 ) ) {
F_15 ( V_29
L_31
L_32 , V_2 -> V_30 ) ;
return - V_129 ;
}
V_3 = F_7 ( V_26 -> V_35 + V_128 ) ;
V_3 &= ~ 0x100 ;
F_5 ( V_3 , V_26 -> V_35 + V_128 ) ;
if ( V_130 ) {
F_31 ( V_2 , L_33
L_34 ) ;
return - V_129 ;
} else {
V_126 = ( V_131 [ 0 ] << 24 ) + ( V_131 [ 1 ] << 16 ) +
( V_131 [ 2 ] << 8 ) + V_131 [ 3 ] ;
F_30 ( 10 ) ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
F_3 ( V_131 [ 16 + V_125 ] , V_26 -> V_41 ) ;
F_30 ( 10 ) ;
if ( F_7 ( V_26 -> V_35 + V_128 ) & 0x20 ) {
F_15 ( V_29
L_31
L_35 ,
V_2 -> V_30 , V_125 ) ;
return - V_129 ;
}
}
}
if ( F_7 ( V_26 -> V_35 + V_128 ) & 0x4 ) {
} else {
F_15 ( V_29
L_31
L_36 , V_2 -> V_30 ) ;
F_15 ( V_29
L_31
L_37 , V_2 -> V_30 ) ;
return - V_129 ;
}
V_3 = F_7 ( V_26 -> V_35 + V_128 ) ;
V_3 |= 0x100 ;
F_5 ( V_3 , V_26 -> V_35 + V_128 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned long V_132 ;
F_11 ( L_38 ) ;
V_132 = F_6 ( V_2 , V_26 -> V_35 + V_128 ) ;
V_132 |= 0x40000000 ;
F_4 ( V_2 , V_132 , V_26 -> V_35 + V_128 ) ;
V_132 &= ~ 0x40000000 ;
F_4 ( V_2 , V_132 , V_26 -> V_35 + V_128 ) ;
F_4 ( V_2 , 0x8000 ,
V_26 -> V_37 + V_59 ) ;
F_4 ( V_2 , 0x8000 ,
V_26 -> V_37 + V_69 ) ;
F_4 ( V_2 , 0x8000 ,
V_26 -> V_37 + V_74 ) ;
F_4 ( V_2 , 0x8000 ,
V_26 -> V_37 + V_79 ) ;
F_4 ( V_2 ,
V_133 | V_134 ,
V_26 -> V_37 + V_82 ) ;
F_4 ( V_2 ,
V_135 | V_136 ,
V_26 -> V_37 + V_53 ) ;
F_4 ( V_2 ,
V_135 | V_136 ,
V_26 -> V_37 + V_66 ) ;
F_4 ( V_2 ,
V_135 | V_136 ,
V_26 -> V_37 + V_71 ) ;
F_4 ( V_2 ,
V_135 | V_136 ,
V_26 -> V_37 + V_76 ) ;
F_4 ( V_2 , 0x43 , V_26 -> V_35 + V_127 ) ;
F_4 ( V_2 , V_137 ,
V_26 -> V_37 + V_138 ) ;
if ( ! ( F_6 ( V_2 , V_26 -> V_37 + V_106 ) & 0x1 ) ) {
F_4 ( V_2 , 0x1 ,
V_26 -> V_37 + V_107 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_139 * V_140 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
int V_144 = F_33 ( V_142 -> V_145 ) ;
int V_146 = F_34 ( V_142 -> V_145 ) ;
int V_147 = F_35 ( V_142 -> V_145 ) ;
unsigned long V_148 = 0 ;
unsigned long V_149 ;
long V_150 ;
F_11 ( L_39 ) ;
if ( V_142 -> V_151 == 0 ) {
return 0 ;
} else if ( V_142 -> V_151 > 1 ) {
F_15 ( V_29
L_40
L_41 , V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
switch ( V_146 ) {
case 0 :
V_148 |= V_153 ;
break;
case 1 :
V_148 |= V_154 ;
break;
case 2 :
V_148 |= V_155 ;
break;
case 3 :
V_148 |= V_156 ;
break;
default:
F_15 ( V_29
L_40
L_42 , V_2 -> V_30 ) ;
return - V_152 ;
}
switch ( V_147 ) {
case V_157 :
case V_158 :
if ( V_144 >= V_48 -> V_159 . V_50 ) {
F_15 ( V_29
L_40
L_43 , V_2 -> V_30 ) ;
return - V_152 ;
}
V_148 |= V_160 | V_144 ;
break;
case V_161 :
if ( V_146 == 0 || V_146 == 1 ) {
F_15 ( V_29
L_40
L_44 ,
V_2 -> V_30 ) ;
return - V_152 ;
}
if ( V_144 >= V_48 -> V_159 . V_162 ) {
F_15 ( V_29
L_40
L_43 , V_2 -> V_30 ) ;
return - V_152 ;
}
V_148 |= V_163 | V_144 ;
break;
default:
F_15 ( V_29
L_40
L_45 , V_2 -> V_30 ) ;
return - V_152 ;
}
V_148 |= V_164 ;
V_149 = F_6 ( V_2 , V_26 -> V_81 . V_52 ) ;
V_149 &= ~ ( V_165 |
V_166 |
V_134 | V_133 ) ;
F_4 ( V_2 , V_149 , V_26 -> V_81 . V_52 ) ;
V_149 &= ~ ( V_167 | V_168 |
V_169 ) ;
F_4 ( V_2 , V_149 , V_26 -> V_81 . V_52 ) ;
V_149 |= V_165 | V_166 ;
F_4 ( V_2 , V_149 , V_26 -> V_81 . V_52 ) ;
F_4 ( V_2 , V_148 , V_26 -> V_81 . V_84 ) ;
F_4 ( V_2 , V_170 , V_26 -> V_81 . V_88 ) ;
F_4 ( V_2 , V_170 ,
V_26 -> V_81 . V_90 ) ;
F_6 ( V_2 , V_26 -> V_81 . V_100 ) ;
F_30 ( 10 ) ;
if ( !
( F_6 ( V_2 , V_26 -> V_81 . V_54 ) &
V_171 ) ) {
F_15 ( V_29
L_40
L_46 , V_2 -> V_30 ) ;
return - V_129 ;
}
V_150 = F_6 ( V_2 , V_26 -> V_81 . V_86 ) & 0xFFFF ;
V_143 [ 0 ] = V_150 ^ 0x8000 ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_139 * V_172 )
{
unsigned long V_149 ;
F_11 ( L_47 ) ;
V_149 = F_6 ( V_2 , V_26 -> V_81 . V_52 ) ;
V_149 &= ~ ( V_134 | V_133 ) ;
F_4 ( V_2 , V_149 , V_26 -> V_81 . V_52 ) ;
F_4 ( V_2 , 0x0 , V_26 -> V_81 . V_52 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_139 * V_172 , struct V_173 * V_174 )
{
int V_147 ;
int V_10 ;
F_11 ( L_48 ) ;
if ( ! V_174 -> V_175 ) {
F_15 ( V_29
L_49
L_50 , V_2 -> V_30 ) ;
return - V_152 ;
}
if ( V_174 -> V_175 > V_176 ) {
F_15 ( V_29
L_49
L_51 , V_2 -> V_30 ) ;
return - V_152 ;
}
if ( ! V_174 -> V_177 ) {
F_15 ( V_29
L_49
L_52 , V_2 -> V_30 ) ;
return - V_178 ;
}
V_147 = F_35 ( V_174 -> V_177 [ 0 ] ) ;
for ( V_10 = 0 ; V_10 < V_174 -> V_175 ; V_10 ++ ) {
if ( F_35 ( V_174 -> V_177 [ V_10 ] ) != V_147 ) {
F_15 ( V_29
L_49
L_53 ,
V_2 -> V_30 ) ;
return - V_152 ;
}
}
if ( V_147 == V_179 ) {
for ( V_10 = 0 ; V_10 < V_174 -> V_175 ; V_10 ++ ) {
if ( F_33 ( V_174 -> V_177 [ V_10 ] ) >=
V_48 -> V_159 . V_162 ) {
F_15 ( V_29
L_54
L_55 , V_2 -> V_30 ) ;
return - V_152 ;
}
}
} else {
for ( V_10 = 0 ; V_10 < V_174 -> V_175 ; V_10 ++ ) {
if ( F_33 ( V_174 -> V_177 [ V_10 ] ) >= V_48 -> V_159 . V_50 ) {
F_15 ( V_29
L_49
L_56 , V_2 -> V_30 ) ;
return - V_152 ;
}
}
}
if ( V_147 == V_179 ) {
for ( V_10 = 0 ; V_10 < V_174 -> V_175 ; V_10 ++ ) {
if ( F_34 ( V_174 -> V_177 [ V_10 ] ) != 1 &&
F_34 ( V_174 -> V_177 [ V_10 ] ) != 2 ) {
F_15 ( V_29
L_49
L_57
L_58 ,
V_2 -> V_30 ) ;
return - V_152 ;
}
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_173 * V_174 ,
unsigned int * V_180 ,
unsigned int * V_181 , unsigned int * V_182 )
{
int V_183 ;
F_11 ( L_59 ) ;
* V_180 = 0 ;
* V_181 = 0 ;
* V_182 = 0 ;
F_39 ( L_60 , V_174 -> V_184 ) ;
F_39 ( L_61 ,
V_174 -> V_185 ) ;
F_39 ( L_62 , V_174 -> V_186 ) ;
if ( V_174 -> V_184 ) {
* V_180 = ( V_174 -> V_184 * 33 ) / 1000 ;
V_183 = ( V_174 -> V_184 * 33 ) % 1000 ;
if ( V_174 -> V_187 & V_188 ) {
if ( V_183 > 33 )
( * V_180 ) ++ ;
} else if ( V_174 -> V_187 & V_189 ) {
if ( V_183 )
( * V_180 ) ++ ;
}
}
if ( V_174 -> V_185 ) {
* V_181 = ( V_174 -> V_185 * 33 ) / 1000 ;
V_183 = ( V_174 -> V_185 * 33 ) % 1000 ;
if ( V_174 -> V_187 & V_188 ) {
if ( V_183 > 33 )
( * V_181 ) ++ ;
} else if ( V_174 -> V_187 & V_189 ) {
if ( V_183 )
( * V_181 ) ++ ;
}
}
if ( V_174 -> V_186 ) {
* V_182 = ( V_174 -> V_186 * 33 ) / 1000 ;
V_183 = ( V_174 -> V_186 * 33 ) % 1000 ;
if ( V_174 -> V_187 & V_188 ) {
if ( V_183 > 33 )
( * V_182 ) ++ ;
} else if ( V_174 -> V_187 & V_189 ) {
if ( V_183 )
( * V_182 ) ++ ;
}
}
F_39 ( L_63 , * V_180 ) ;
F_39 ( L_64 , * V_181 ) ;
F_39 ( L_65 , * V_182 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned int V_180 ,
unsigned int V_181 , unsigned int V_182 )
{
F_11 ( L_66 ) ;
F_4 ( V_2 , V_180 - 1 ,
V_26 -> V_81 . V_96 ) ;
F_4 ( V_2 , 0x0 , V_26 -> V_81 . V_98 ) ;
if ( V_181 ) {
F_4 ( V_2 , V_181 - 1 ,
V_26 -> V_81 . V_92 ) ;
F_4 ( V_2 , 0x0 , V_26 -> V_81 . V_94 ) ;
}
F_4 ( V_2 , V_182 - 1 , V_26 -> V_81 . V_90 ) ;
F_4 ( V_2 , V_182 - 1 , V_26 -> V_81 . V_88 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_173 * V_174 ,
unsigned int V_180 ,
unsigned int V_181 , unsigned int V_182 )
{
unsigned long V_149 = 0 ;
F_11 ( L_67 ) ;
F_40 ( V_2 , V_180 , V_181 , V_182 ) ;
F_4 ( V_2 , V_149 , V_26 -> V_81 . V_52 ) ;
if ( ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_193 &&
V_174 -> V_194 == V_193 ) ||
( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_195 &&
V_174 -> V_194 == V_193 ) ) {
V_149 = V_168 |
V_165 |
V_166 ;
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_191 &&
V_174 -> V_194 == V_193 ) {
V_149 = V_169 |
V_165 |
V_166 ;
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_191 &&
V_174 -> V_194 == V_191 ) {
V_149 = V_167 |
V_168 |
V_165 |
V_166 ;
} else {
V_149 = V_167 |
V_165 |
V_166 ;
}
if ( V_174 -> V_196 == V_197 ) {
F_4 ( V_2 , V_174 -> V_175 * V_174 -> V_198 ,
V_26 -> V_81 . V_102 ) ;
V_149 |= V_199 | V_200 ;
} else if ( V_174 -> V_196 == V_201 &&
V_174 -> V_202 == V_197 ) {
F_4 ( V_2 , V_174 -> V_203 ,
V_26 -> V_81 . V_102 ) ;
V_149 |= V_199 | V_200 ;
} else {
V_149 |= V_199 ;
}
F_4 ( V_2 , V_149 , V_26 -> V_81 . V_52 ) ;
F_42 ( V_2 , V_172 , V_174 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_139 * V_172 , struct V_173 * V_174 )
{
unsigned int V_148 ;
unsigned int V_144 ;
unsigned int V_146 ;
unsigned int V_147 ;
int V_10 ;
F_11 ( L_68 ) ;
for ( V_10 = 0 ; V_10 < V_174 -> V_175 ; V_10 ++ ) {
V_144 = F_33 ( V_174 -> V_177 [ V_10 ] ) ;
V_146 = F_34 ( V_174 -> V_177 [ V_10 ] ) ;
V_147 = F_35 ( V_174 -> V_177 [ V_10 ] ) ;
V_148 = V_144 ;
if ( V_146 == 0 )
V_148 |= V_153 ;
else if ( V_146 == 1 )
V_148 |= V_154 ;
else if ( V_146 == 2 )
V_148 |= V_155 ;
else
V_148 |= V_156 ;
if ( V_147 == V_179 )
V_148 |= V_163 ;
else
V_148 |= V_160 ;
F_4 ( V_2 , V_148 , V_26 -> V_81 . V_84 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_139 * V_172 )
{
int V_204 ;
unsigned int V_180 = 0 ;
unsigned int V_181 = 0 ;
unsigned int V_182 = 0 ;
struct V_173 * V_174 = & V_172 -> V_205 -> V_174 ;
F_11 ( L_69 ) ;
V_204 = F_36 ( V_2 , V_172 ) ;
if ( V_204 )
return V_204 ;
V_204 = F_38 ( V_2 ,
V_172 , V_174 , & V_180 , & V_181 , & V_182 ) ;
if ( V_204 )
return V_204 ;
V_204 = F_41 ( V_2 , V_172 , V_174 , V_180 , V_181 , V_182 ) ;
if ( V_204 )
return V_204 ;
F_6 ( V_2 , V_26 -> V_81 . V_100 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_173 * V_174 )
{
unsigned int V_180 ;
unsigned int V_182 ;
unsigned int V_181 ;
int V_204 = 0 ;
F_11 ( L_70 ) ;
F_39 ( L_71 , V_174 -> V_206 ) ;
F_39 ( L_72 , V_174 -> V_187 ) ;
F_39 ( L_73 ,
V_174 -> V_190 ) ;
F_39 ( L_74 ,
V_174 -> V_184 ) ;
F_39 ( L_75 ,
V_174 -> V_192 ) ;
F_39 ( L_76 ,
V_174 -> V_185 ) ;
F_39 ( L_77 ,
V_174 -> V_194 ) ;
F_39 ( L_78 ,
V_174 -> V_186 ) ;
F_39 ( L_79 ,
V_174 -> V_202 ) ;
F_39 ( L_80 ,
V_174 -> V_203 ) ;
F_39 ( L_81 ,
V_174 -> V_196 ) ;
F_39 ( L_82 , V_174 -> V_198 ) ;
F_39 ( L_83 ,
( unsigned int ) V_174 -> V_177 ) ;
F_39 ( L_84 ,
V_174 -> V_175 ) ;
V_174 -> V_187 &= V_188 | V_189 | V_207 ;
F_38 ( V_2 , V_172 , V_174 , & V_180 , & V_181 , & V_182 ) ;
switch ( V_174 -> V_190 ) {
case V_208 :
case V_191 :
break;
case V_209 :
V_174 -> V_190 &= V_208 | V_191 ;
V_204 ++ ;
break;
default:
F_15 ( V_29
L_85
L_86 , V_2 -> V_30 ) ;
V_174 -> V_190 = V_208 ;
V_204 ++ ;
}
switch ( V_174 -> V_192 ) {
case V_195 :
case V_193 :
case V_191 :
break;
case V_209 :
V_174 -> V_192 &= V_195 | V_193 | V_191 ;
V_204 ++ ;
break;
default:
F_15 ( V_29
L_85
L_87 , V_2 -> V_30 ) ;
V_174 -> V_192 = V_195 ;
V_204 ++ ;
}
switch ( V_174 -> V_194 ) {
case V_193 :
case V_191 :
break;
case V_209 :
V_174 -> V_194 &= V_193 | V_191 ;
V_204 ++ ;
break;
default:
F_15 ( V_29
L_85
L_88 , V_2 -> V_30 ) ;
V_174 -> V_194 = V_193 ;
V_204 ++ ;
}
switch ( V_174 -> V_202 ) {
case V_201 :
case V_197 :
break;
case V_209 :
V_174 -> V_202 &= V_201 | V_197 ;
V_204 ++ ;
break;
default:
F_15 ( V_29
L_85
L_89 , V_2 -> V_30 ) ;
V_174 -> V_202 = V_201 ;
V_204 ++ ;
}
switch ( V_174 -> V_196 ) {
case V_201 :
case V_197 :
break;
case V_209 :
V_174 -> V_196 &= V_201 | V_197 ;
V_204 ++ ;
break;
default:
F_15 ( V_29
L_85
L_90 , V_2 -> V_30 ) ;
V_174 -> V_196 = V_201 ;
V_204 ++ ;
}
if ( V_204 )
return 1 ;
if ( V_174 -> V_190 == V_208 &&
V_174 -> V_192 == V_193 &&
V_174 -> V_194 == V_193 ) {
} else if ( V_174 -> V_190 == V_208 &&
V_174 -> V_192 == V_195 &&
V_174 -> V_194 == V_193 ) {
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_193 &&
V_174 -> V_194 == V_193 ) {
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_195 &&
V_174 -> V_194 == V_193 ) {
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_191 &&
V_174 -> V_194 == V_193 ) {
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_191 &&
V_174 -> V_194 == V_191 ) {
} else {
F_15 ( V_29
L_85
L_91 , V_2 -> V_30 ) ;
V_174 -> V_190 = V_208 ;
V_174 -> V_192 = V_195 ;
V_174 -> V_194 = V_193 ;
V_204 ++ ;
}
if ( V_174 -> V_196 == V_201 && V_174 -> V_202 == V_201 ) {
} else if ( V_174 -> V_196 == V_197 &&
V_174 -> V_202 == V_201 ) {
} else if ( V_174 -> V_196 == V_201 &&
V_174 -> V_202 == V_197 ) {
} else if ( V_174 -> V_196 == V_197 &&
V_174 -> V_202 == V_197 ) {
} else {
F_15 ( V_29
L_85
L_92 , V_2 -> V_30 ) ;
V_174 -> V_196 = V_201 ;
V_174 -> V_202 = V_201 ;
V_204 ++ ;
}
if ( V_204 )
return 2 ;
if ( V_174 -> V_175 < 1 ) {
F_15 ( V_29
L_85
L_93 , V_2 -> V_30 ) ;
V_174 -> V_175 = 1 ;
V_204 ++ ;
}
if ( V_180 < 66 ) {
F_15 ( V_29
L_85
L_94 , V_2 -> V_30 ) ;
V_174 -> V_184 = 2000 ;
V_204 ++ ;
}
if ( V_181 && V_181 < 67 ) {
F_15 ( V_29
L_85
L_95 , V_2 -> V_30 ) ;
V_174 -> V_185 = 2031 ;
V_204 ++ ;
}
if ( V_182 < 66 ) {
F_15 ( V_29
L_85
L_96 , V_2 -> V_30 ) ;
V_174 -> V_186 = 2000 ;
V_204 ++ ;
}
if ( V_204 )
return 3 ;
if ( V_174 -> V_190 == V_208 &&
V_174 -> V_192 == V_193 &&
V_174 -> V_194 == V_193 ) {
if ( V_180 < V_170 ) {
F_15 ( V_29
L_85
L_97 , V_2 -> V_30 ) ;
V_174 -> V_184 = 2000 ;
V_204 ++ ;
}
if ( V_182 < V_170 ) {
F_15 ( V_29
L_85
L_98 , V_2 -> V_30 ) ;
V_174 -> V_186 = 2000 ;
V_204 ++ ;
}
if ( V_181 <= V_174 -> V_175 * V_182 ) {
F_15 ( V_29
L_85
L_99 , V_2 -> V_30 ) ;
V_174 -> V_203 = 2000 * V_174 -> V_175 + 31 ;
V_204 ++ ;
}
} else if ( V_174 -> V_190 == V_208 &&
V_174 -> V_192 == V_195 &&
V_174 -> V_194 == V_193 ) {
if ( V_180 < V_170 ) {
F_15 ( V_29
L_85
L_97 , V_2 -> V_30 ) ;
V_174 -> V_184 = 2000 ;
V_204 ++ ;
}
if ( V_182 < V_170 ) {
F_15 ( V_29
L_85
L_98 , V_2 -> V_30 ) ;
V_174 -> V_186 = 2000 ;
V_204 ++ ;
}
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_193 &&
V_174 -> V_194 == V_193 ) {
if ( V_180 < V_170 ) {
F_15 ( V_29
L_85
L_97 , V_2 -> V_30 ) ;
V_174 -> V_184 = 2000 ;
V_204 ++ ;
}
if ( V_182 < V_170 ) {
F_15 ( V_29
L_85
L_98 , V_2 -> V_30 ) ;
V_174 -> V_186 = 2000 ;
V_204 ++ ;
}
if ( V_181 <= V_174 -> V_175 * V_182 ) {
F_15 ( V_29
L_85
L_99 , V_2 -> V_30 ) ;
V_174 -> V_203 = 2000 * V_174 -> V_175 + 31 ;
V_204 ++ ;
}
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_195 &&
V_174 -> V_194 == V_193 ) {
if ( V_180 < V_170 ) {
F_15 ( V_29
L_85
L_97 , V_2 -> V_30 ) ;
V_174 -> V_184 = 2000 ;
V_204 ++ ;
}
if ( V_182 < V_170 ) {
F_15 ( V_29
L_85
L_98 , V_2 -> V_30 ) ;
V_174 -> V_186 = 2000 ;
V_204 ++ ;
}
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_191 &&
V_174 -> V_194 == V_193 ) {
if ( V_180 < V_170 ) {
F_15 ( V_29
L_85
L_97 , V_2 -> V_30 ) ;
V_174 -> V_184 = 2000 ;
V_204 ++ ;
}
if ( V_182 < V_170 ) {
F_15 ( V_29
L_85
L_98 , V_2 -> V_30 ) ;
V_174 -> V_186 = 2000 ;
V_204 ++ ;
}
} else if ( V_174 -> V_190 == V_191 &&
V_174 -> V_192 == V_191 &&
V_174 -> V_194 == V_191 ) {
if ( V_180 < V_170 ) {
F_15 ( V_29
L_85
L_97 , V_2 -> V_30 ) ;
V_174 -> V_184 = 2000 ;
V_204 ++ ;
}
}
if ( V_174 -> V_196 == V_197 ) {
if ( V_174 -> V_198 == 0 ) {
F_15 ( V_29
L_85
L_100 , V_2 -> V_30 ) ;
V_174 -> V_198 = 1 ;
V_204 ++ ;
}
}
if ( V_174 -> V_202 == V_197 ) {
if ( V_174 -> V_203 == 0 ) {
F_15 ( V_29
L_85
L_99 , V_2 -> V_30 ) ;
V_174 -> V_203 = 1 ;
V_204 ++ ;
}
}
if ( V_204 )
return 4 ;
if ( F_37 ( V_2 , V_172 , V_174 ) )
return 5 ;
return 0 ;
}
static T_3 F_45 ( int V_47 , void * V_210 )
{
unsigned int V_149 ;
struct V_1 * V_2 = V_210 ;
struct V_139 * V_172 = V_2 -> V_211 ;
struct V_212 * V_81 = & V_26 -> V_81 ;
int V_10 ;
int V_213 = 0 ;
long V_150 ;
F_46 ( L_101 ) ;
if ( ! V_2 -> V_214 ) {
F_46 ( L_102 ) ;
return V_215 ;
}
V_172 -> V_205 -> V_216 = 0 ;
if ( V_47 != V_81 -> V_47 ) {
F_15 ( V_29
L_103
L_104 , V_2 -> V_30 , V_47 ) ;
return V_217 ;
}
if ( F_6 ( V_2 ,
V_81 -> V_62 ) &
V_218 ) {
F_46
( L_105 ) ;
V_149 = F_6 ( V_2 , V_81 -> V_52 ) ;
if ( ! ( V_149 & V_219 ) &&
! ( V_149 & V_220 ) &&
( V_149 & V_171 ) ) {
F_46 ( L_106 ) ;
V_213 = V_221 ;
V_149 |= V_133 ;
V_149 &= ~ ( V_199 |
V_200 ) ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
V_172 -> V_205 -> V_216 |= V_222 | V_223 ;
F_15 ( V_29
L_103
L_107 , V_2 -> V_30 ) ;
} else if ( ( V_149 & V_219 )
&& ! ( V_149 & V_220 )
&& ( V_149 & V_171 ) ) {
F_46 ( L_108 ) ;
V_172 -> V_205 -> V_216 |= V_224 ;
V_213 = V_221 / 2 ;
} else {
F_15 ( V_29
L_103
L_109 , V_2 -> V_30 ) ;
V_213 = 0 ;
V_149 |= V_133 ;
V_149 &= ~ ( V_199 |
V_200 ) ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
V_172 -> V_205 -> V_216 |= V_222 | V_223 ;
F_15 ( V_29
L_103
L_110 , V_2 -> V_30 ) ;
}
F_46 ( L_111 , V_213 ) ;
for ( V_10 = 0 ; V_10 < V_213 ; V_10 ++ ) {
V_150 = F_7 ( V_81 -> V_86 ) & 0xFFFF ;
V_150 ^= 0x8000 ;
if ( ! F_47 ( V_172 -> V_205 , V_150 ) ) {
V_149 |= V_133 ;
V_149 &= ~ ( V_199 |
V_200 ) ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
V_172 -> V_205 -> V_216 |= V_225 ;
F_15 ( V_29
L_103
L_112 , V_2 -> V_30 ) ;
break;
}
}
F_46 ( L_113 ) ;
V_149 |= V_226 ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
V_149 &= ~ V_226 ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
}
if ( F_6 ( V_2 ,
V_81 -> V_62 ) & V_227 ) {
F_46
( L_114 ) ;
V_172 -> V_205 -> V_216 |= V_224 | V_223 ;
V_149 = F_6 ( V_2 , V_81 -> V_52 ) ;
V_149 |= V_133 ;
V_149 &= ~ ( V_199 | V_200 ) ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
while ( F_7 ( V_81 -> V_52 ) & V_171 ) {
V_150 = F_7 ( V_81 -> V_86 ) & 0xFFFF ;
V_150 ^= 0x8000 ;
if ( ! F_47 ( V_172 -> V_205 , V_150 ) ) {
F_15 ( V_29
L_103
L_112 , V_2 -> V_30 ) ;
V_172 -> V_205 -> V_216 |= V_225 ;
break;
}
}
F_46
( L_115 ) ;
V_149 |= V_228 ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
V_149 &= ~ V_228 ;
F_4 ( V_2 , V_149 , V_81 -> V_52 ) ;
}
F_46 ( L_116 , V_172 -> V_205 -> V_216 ) ;
if ( V_172 -> V_205 -> V_216 )
F_48 ( V_2 , V_172 ) ;
return V_217 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
int V_144 = F_33 ( V_142 -> V_145 ) ;
int V_146 = F_34 ( V_142 -> V_145 ) ;
int V_147 = F_35 ( V_142 -> V_145 ) ;
unsigned long V_149 ;
F_11 ( L_117 ) ;
if ( V_142 -> V_151 == 0 ) {
return 0 ;
} else if ( V_142 -> V_151 > 1 ) {
F_15 ( V_29
L_118
L_41 , V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
if ( V_144 >= V_48 -> V_49 . V_50 ) {
F_15 ( V_29
L_118
L_119 , V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
if ( V_146 != 0 ) {
F_15 ( V_29
L_118
L_120 , V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
if ( V_147 != V_157 && V_147 != V_158 ) {
F_15 ( V_29
L_118
L_121 , V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
V_149 = F_6 ( V_2 , V_26 -> V_51 [ V_144 ] . V_52 ) ;
V_149 |= V_135 ;
F_4 ( V_2 , V_149 , V_26 -> V_51 [ V_144 ] . V_52 ) ;
F_4 ( V_2 , 0x0 , V_26 -> V_51 [ V_144 ] . V_52 ) ;
F_4 ( V_2 , V_143 [ 0 ] , V_26 -> V_51 [ V_144 ] . V_58 ) ;
V_26 -> V_51 [ V_144 ] . V_229 = V_143 [ 0 ] ;
return 1 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
int V_144 = F_33 ( V_142 -> V_145 ) ;
if ( V_142 -> V_151 == 0 ) {
return 0 ;
} else if ( V_142 -> V_151 > 1 ) {
F_15
( L_122
L_123 , V_2 -> V_30 ) ;
return - V_152 ;
}
V_143 [ 0 ] = V_26 -> V_51 [ V_144 ] . V_229 ;
return 1 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
F_11 ( L_124 ) ;
if ( V_142 -> V_151 == 0 )
return 0 ;
if ( V_142 -> V_151 != 2 ) {
F_15
( L_125
L_123 , V_2 -> V_30 ) ;
return - V_152 ;
}
if ( V_143 [ 0 ] ) {
if ( ( V_172 -> V_230 & V_143 [ 0 ] ) != V_143 [ 0 ] )
return - V_129 ;
V_172 -> V_231 &= ~ V_143 [ 0 ] ;
V_172 -> V_231 |= V_143 [ 0 ] & V_143 [ 1 ] ;
F_4 ( V_2 , ( V_172 -> V_231 >> 0 ) & 0xFF ,
V_26 -> V_104 . V_108 ) ;
F_4 ( V_2 , ( V_172 -> V_231 >> 8 ) & 0xFF ,
V_26 -> V_104 . V_110 ) ;
F_4 ( V_2 , ( V_172 -> V_231 >> 16 ) & 0xFF ,
V_26 -> V_104 . V_112 ) ;
F_4 ( V_2 , ( V_172 -> V_231 >> 24 ) & 0xFF ,
V_26 -> V_104 . V_114 ) ;
}
V_143 [ 1 ] =
( ( F_6 ( V_2 , V_26 -> V_104 . V_108 ) & 0xFF ) << 0 ) |
( ( F_6 ( V_2 , V_26 -> V_104 . V_110 ) & 0xFF ) << 8 ) |
( ( F_6 ( V_2 , V_26 -> V_104 . V_112 ) & 0xFF ) << 16 ) |
( ( F_6 ( V_2 , V_26 -> V_104 . V_114 ) & 0xFF ) << 24 ) ;
return 2 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
unsigned long V_149 ;
int V_144 = F_33 ( V_142 -> V_145 ) ;
F_11 ( L_126 ) ;
switch ( V_143 [ 0 ] ) {
default:
return - V_152 ;
case V_232 :
V_143 [ 1 ] =
( V_172 -> V_230 & ( 1 << V_144 ) ) ? V_233 : V_234 ;
return V_142 -> V_151 ;
case V_235 :
case V_236 :
break;
}
V_149 = F_6 ( V_2 , V_26 -> V_104 . V_52 ) ;
if ( V_143 [ 0 ] == V_236 ) {
if ( V_144 < 8 ) {
V_172 -> V_230 |= 0xFF ;
V_149 &= ~ ( V_237 |
V_238 ) ;
V_149 |= V_237 ;
} else if ( V_144 < 16 ) {
if ( ! F_6 ( V_2 , V_26 -> V_104 . V_105 ) )
return - V_31 ;
V_172 -> V_230 |= 0xFF00 ;
V_149 &= ~ ( V_239 |
V_240 ) ;
V_149 |= V_239 ;
} else if ( V_144 < 24 ) {
V_172 -> V_230 |= 0xFF0000 ;
V_149 &= ~ ( V_241 |
V_242 ) ;
V_149 |= V_241 ;
} else if ( V_144 < 32 ) {
V_172 -> V_230 |= 0xFF000000 ;
V_149 &= ~ ( V_243 |
V_244 ) ;
V_149 |= V_243 ;
} else {
return - V_152 ;
}
} else {
if ( V_144 < 8 ) {
if ( ! F_6 ( V_2 , V_26 -> V_104 . V_105 ) )
return - V_31 ;
V_172 -> V_230 &= ~ 0xFF ;
V_149 &= ~ ( V_237 |
V_238 ) ;
} else if ( V_144 < 16 ) {
V_172 -> V_230 &= ~ 0xFF00 ;
V_149 &= ~ ( V_239 |
V_240 ) ;
} else if ( V_144 < 24 ) {
V_172 -> V_230 &= ~ 0xFF0000 ;
V_149 &= ~ ( V_241 |
V_242 ) ;
} else if ( V_144 < 32 ) {
V_172 -> V_230 &= ~ 0xFF000000 ;
V_149 &= ~ ( V_243 |
V_244 ) ;
} else {
return - V_152 ;
}
}
F_4 ( V_2 , V_149 , V_26 -> V_104 . V_52 ) ;
return 1 ;
}
static int F_53 ( struct V_1 * V_2 , unsigned int V_245 )
{
F_11 ( L_127 ) ;
switch ( V_245 ) {
case 0 :
F_1 ( V_2 , 0x30 , V_26 -> V_116 . V_52 ) ;
F_1 ( V_2 , 0x00 , V_26 -> V_116 . V_118 ) ;
F_1 ( V_2 , 0x00 , V_26 -> V_116 . V_118 ) ;
break;
case 1 :
F_1 ( V_2 , 0x70 , V_26 -> V_116 . V_52 ) ;
F_1 ( V_2 , 0x00 , V_26 -> V_116 . V_120 ) ;
F_1 ( V_2 , 0x00 , V_26 -> V_116 . V_120 ) ;
break;
case 2 :
F_1 ( V_2 , 0xB0 , V_26 -> V_116 . V_52 ) ;
F_1 ( V_2 , 0x00 , V_26 -> V_116 . V_122 ) ;
F_1 ( V_2 , 0x00 , V_26 -> V_116 . V_122 ) ;
break;
default:
F_15 ( V_29
L_128 ,
V_2 -> V_30 ) ;
return - V_152 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_245 ,
unsigned int V_246 )
{
int V_149 = 0 ;
F_11 ( L_129 ) ;
switch ( V_245 ) {
case 0 :
V_149 |= V_247 ;
break;
case 1 :
V_149 |= V_248 ;
break;
case 2 :
V_149 |= V_249 ;
break;
default:
F_15 ( V_29
L_130 ,
V_2 -> V_30 ) ;
return - V_152 ;
}
switch ( V_246 ) {
case 0 :
V_149 |= V_250 ;
break;
case 1 :
V_149 |= V_251 ;
break;
case 2 :
V_149 |= V_252 ;
break;
case 3 :
V_149 |= V_253 ;
break;
case 4 :
V_149 |= V_254 ;
break;
case 5 :
V_149 |= V_255 ;
break;
default:
F_15 ( V_29
L_131 ,
V_2 -> V_30 ) ;
return - V_152 ;
}
V_149 |= 0x30 ;
F_1 ( V_2 , V_149 , V_26 -> V_116 . V_52 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
int V_204 ;
F_11 ( L_132 ) ;
switch ( V_143 [ 0 ] ) {
case V_256 :
if ( V_142 -> V_151 != 1 ) {
F_15 ( V_29
L_133
L_134 ,
V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
V_204 = F_53 ( V_2 , V_142 -> V_145 ) ;
if ( V_204 )
return V_204 ;
break;
case V_257 :
if ( V_142 -> V_151 != 2 ) {
F_15 ( V_29
L_133
L_134 ,
V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
V_204 = F_54 ( V_2 , V_142 -> V_145 , V_143 [ 1 ] ) ;
if ( V_204 )
return V_204 ;
break;
default:
F_15 ( V_29
L_133
L_135 , V_2 -> V_30 ) ;
return - V_152 ;
}
return 2 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
unsigned short V_149 ;
F_11 ( L_136 ) ;
if ( V_142 -> V_151 == 0 )
return 0 ;
if ( V_142 -> V_151 > 1 ) {
F_15 ( V_29
L_137
L_41 ,
V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
switch ( V_142 -> V_145 ) {
case 0 :
V_149 = F_8 ( V_2 , V_26 -> V_116 . V_118 ) ;
V_143 [ 0 ] = V_149 ;
V_149 = F_8 ( V_2 , V_26 -> V_116 . V_118 ) ;
V_143 [ 0 ] |= V_149 << 8 ;
break;
case 1 :
V_149 = F_8 ( V_2 , V_26 -> V_116 . V_120 ) ;
V_143 [ 0 ] = V_149 ;
V_149 = F_8 ( V_2 , V_26 -> V_116 . V_120 ) ;
V_143 [ 0 ] |= V_149 << 8 ;
break;
case 2 :
V_149 = F_8 ( V_2 , V_26 -> V_116 . V_122 ) ;
V_143 [ 0 ] = V_149 ;
V_149 = F_8 ( V_2 , V_26 -> V_116 . V_122 ) ;
V_143 [ 0 ] |= V_149 << 8 ;
break;
default:
F_15 ( V_29
L_137
L_119 ,
V_2 -> V_30 , V_142 -> V_145 ) ;
return - V_152 ;
}
return 1 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_139 * V_172 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
unsigned short V_149 ;
F_11 ( L_138 ) ;
if ( V_142 -> V_151 == 0 ) {
return 0 ;
} else if ( V_142 -> V_151 > 1 ) {
F_15 ( V_29
L_139
L_41 ,
V_2 -> V_30 , V_142 -> V_151 ) ;
return - V_152 ;
}
switch ( V_142 -> V_145 ) {
case 0 :
V_149 = V_143 [ 0 ] & 0xFF ;
F_1 ( V_2 , V_149 , V_26 -> V_116 . V_118 ) ;
V_149 = ( V_143 [ 0 ] >> 8 ) & 0xFF ;
F_1 ( V_2 , V_149 , V_26 -> V_116 . V_118 ) ;
break;
case 1 :
V_149 = V_143 [ 0 ] & 0xFF ;
F_1 ( V_2 , V_149 , V_26 -> V_116 . V_120 ) ;
V_149 = ( V_143 [ 0 ] >> 8 ) & 0xFF ;
F_1 ( V_2 , V_149 , V_26 -> V_116 . V_120 ) ;
break;
case 2 :
V_149 = V_143 [ 0 ] & 0xFF ;
F_1 ( V_2 , V_149 , V_26 -> V_116 . V_122 ) ;
V_149 = ( V_143 [ 0 ] >> 8 ) & 0xFF ;
F_1 ( V_2 , V_149 , V_26 -> V_116 . V_122 ) ;
break;
default:
F_15 ( V_29
L_139
L_119 ,
V_2 -> V_30 , V_142 -> V_145 ) ;
return - V_152 ;
}
return 1 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_139 * V_172 ;
int V_9 ;
F_11 ( L_140 ) ;
V_9 = F_10 ( V_2 , V_6 ) ;
if ( V_9 )
return V_9 ;
if ( F_59 ( V_2 , 4 ) < 0 )
return - V_14 ;
V_172 = V_2 -> V_211 + 0 ;
if ( V_48 -> V_159 . V_50 ) {
V_172 -> type = V_258 ;
V_172 -> V_259 =
V_260 | V_261 | V_262 | V_179 ;
V_172 -> V_263 = V_48 -> V_159 . V_50 ;
V_172 -> V_264 = 0xFFFF ;
V_172 -> V_265 = V_176 ;
V_172 -> V_266 = & V_267 ;
V_172 -> V_268 = F_32 ;
if ( V_26 -> V_47 > 0 ) {
if ( F_60 ( V_26 -> V_47 , F_45 ,
V_269 , L_141 , V_2 ) ) {
F_15
( L_142
L_143 , V_2 -> V_30 ) ;
} else {
V_2 -> V_270 = V_172 ;
V_172 -> V_259 |= V_271 ;
V_172 -> V_272 = F_36 ;
V_172 -> V_273 = F_44 ;
V_172 -> V_274 = F_43 ;
}
} else {
F_15 ( V_275
L_142
L_144 , V_2 -> V_30 ) ;
}
} else {
V_172 -> type = V_276 ;
}
V_172 = V_2 -> V_211 + 1 ;
if ( V_48 -> V_49 . V_50 ) {
V_172 -> type = V_277 ;
V_172 -> V_259 = V_278 | V_261 | V_262 ;
V_172 -> V_263 = V_48 -> V_49 . V_50 ;
V_172 -> V_264 = 0xFFFF ;
V_172 -> V_266 = & V_279 ;
V_172 -> V_280 = F_49 ;
V_172 -> V_268 = F_50 ;
} else {
V_172 -> type = V_276 ;
}
V_172 = V_2 -> V_211 + 2 ;
if ( V_48 -> V_281 . V_50 ) {
V_172 -> type = V_282 ;
V_172 -> V_259 = V_260 | V_283 ;
V_172 -> V_263 = V_48 -> V_281 . V_50 * 8 ;
V_172 -> V_264 = 1 ;
V_172 -> V_266 = & V_284 ;
V_172 -> V_285 = F_51 ;
V_172 -> V_286 = F_52 ;
} else {
V_172 -> type = V_276 ;
}
if ( ! F_6 ( V_2 , V_26 -> V_104 . V_105 ) ) {
V_172 -> V_230 |= 0xFF ;
F_4 ( V_2 , V_237 ,
V_26 -> V_104 . V_105 ) ;
}
V_172 = V_2 -> V_211 + 3 ;
if ( V_48 -> V_287 . V_50 ) {
V_172 -> type = V_288 ;
V_172 -> V_259 = V_260 | V_283 ;
V_172 -> V_263 = V_48 -> V_287 . V_50 ;
V_172 -> V_264 = 0xFFFF ;
V_172 -> V_268 = F_56 ;
V_172 -> V_280 = F_57 ;
V_172 -> V_286 = F_55 ;
} else {
V_172 -> type = V_276 ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_26 ) {
if ( V_26 -> V_27 ) {
F_24 ( V_2 ) ;
if ( V_26 -> V_35 )
F_62 ( V_26 -> V_27 ) ;
F_63 ( V_26 -> V_27 ) ;
}
}
}
static int T_4 F_64 ( struct V_7 * V_2 ,
const struct V_289 * V_290 )
{
return F_65 ( V_2 , & V_291 ) ;
}
static void T_5 F_66 ( struct V_7 * V_2 )
{
F_67 ( V_2 ) ;
}
