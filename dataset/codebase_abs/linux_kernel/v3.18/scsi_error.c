void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) == V_2 -> V_4 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_5 ) ;
F_5 ( 5 , F_6 ( V_6 , V_2 ,
L_1 ) ) ;
}
}
void F_7 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_9 ) == 0 ||
F_9 ( V_2 , V_10 ) == 0 ) {
V_2 -> V_11 ++ ;
F_1 ( V_2 ) ;
}
F_10 ( V_2 -> V_8 , V_7 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_12 || V_2 -> V_13 == - 1 )
return 0 ;
if ( F_12 ( V_14 , V_2 -> V_12 + V_2 -> V_13 ) &&
V_2 -> V_13 > - 1 )
return 0 ;
return 1 ;
}
void
F_13 ( struct V_15 * V_16 )
{
struct V_17 * V_18 =
F_14 ( V_16 , struct V_17 , V_19 . V_16 ) ;
struct V_20 * V_21 = V_18 -> V_22 ;
int V_23 ;
if ( F_11 ( V_21 -> V_24 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_2 ,
V_18 ) ) ;
} else {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_3 , V_18 ) ) ;
V_23 = F_16 ( V_21 -> V_24 -> V_25 , V_18 ) ;
if ( V_23 == V_26 ) {
F_17 ( V_18 , V_27 ) ;
if ( F_11 ( V_21 -> V_24 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_4
L_5
L_6 , V_18 ) ) ;
} else if ( ! F_18 ( V_18 ) &&
( ++ V_18 -> V_28 <= V_18 -> V_29 ) ) {
F_5 ( 3 ,
F_15 ( V_30 , V_18 ,
L_7
L_8 , V_18 ) ) ;
F_19 ( V_18 , V_31 ) ;
return;
} else {
F_5 ( 3 ,
F_15 ( V_30 , V_18 ,
L_9
L_8 , V_18 ) ) ;
F_20 ( V_18 ) ;
return;
}
} else {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_10 ,
V_18 , V_23 ) ) ;
}
}
if ( ! F_21 ( V_18 , 0 ) ) {
F_5 ( 3 ,
F_15 ( V_30 , V_18 ,
L_11
L_8 , V_18 ) ) ;
F_17 ( V_18 , V_27 ) ;
F_20 ( V_18 ) ;
}
}
static int
F_22 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_24 ;
unsigned long V_7 ;
if ( V_18 -> V_32 & V_33 ) {
V_18 -> V_32 &= ~ V_33 ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_12 , V_18 ) ) ;
F_23 ( F_24 ( & V_18 -> V_19 ) ) ;
return V_34 ;
}
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_25 ( V_2 ) ) {
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_13 ,
V_18 ) ) ;
return V_34 ;
}
if ( V_2 -> V_13 != - 1 && ! V_2 -> V_12 )
V_2 -> V_12 = V_14 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
V_18 -> V_32 |= V_33 ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_14 , V_18 ) ) ;
F_26 ( V_2 -> V_35 , & V_18 -> V_19 , V_36 / 100 ) ;
return V_26 ;
}
int F_21 ( struct V_17 * V_18 , int V_37 )
{
struct V_1 * V_2 = V_18 -> V_22 -> V_24 ;
unsigned long V_7 ;
int V_38 = 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_9 ) )
if ( F_9 ( V_2 , V_10 ) )
goto V_39;
if ( V_2 -> V_13 != - 1 && ! V_2 -> V_12 )
V_2 -> V_12 = V_14 ;
V_38 = 1 ;
if ( V_18 -> V_32 & V_33 )
V_37 &= ~ V_40 ;
V_18 -> V_32 |= V_37 ;
F_27 ( & V_18 -> V_41 , & V_2 -> V_42 ) ;
V_2 -> V_4 ++ ;
F_1 ( V_2 ) ;
V_39:
F_10 ( V_2 -> V_8 , V_7 ) ;
return V_38 ;
}
enum V_43 F_28 ( struct V_44 * V_45 )
{
struct V_17 * V_18 = V_45 -> V_46 ;
enum V_43 V_23 = V_47 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
F_29 ( V_18 ) ;
F_30 ( V_18 , V_48 ) ;
if ( V_24 -> V_13 != - 1 && ! V_24 -> V_12 )
V_24 -> V_12 = V_14 ;
if ( V_24 -> V_49 -> V_50 )
V_23 = V_24 -> V_49 -> V_50 ( V_18 ) ;
else if ( V_24 -> V_25 -> V_50 )
V_23 = V_24 -> V_25 -> V_50 ( V_18 ) ;
if ( V_23 == V_47 ) {
if ( ! V_24 -> V_25 -> V_51 &&
F_22 ( V_18 ) == V_26 )
return V_47 ;
F_17 ( V_18 , V_27 ) ;
if ( ! F_21 ( V_18 , V_40 ) )
V_23 = V_52 ;
}
return V_23 ;
}
int F_31 ( struct V_20 * V_21 )
{
int V_53 ;
F_32 ( V_21 -> V_24 -> V_54 , ! F_25 ( V_21 -> V_24 ) ) ;
V_53 = F_33 ( V_21 ) ;
F_5 ( 5 , F_34 ( V_6 , V_21 ,
L_15 , V_55 , V_53 ) ) ;
return V_53 ;
}
static inline void F_35 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_58 = 0 ;
int V_59 = 0 ;
int V_60 = 0 ;
int V_61 = 0 ;
F_36 (sdev, shost) {
F_37 (scmd, work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 ) {
++ V_58 ;
if ( V_18 -> V_32 & V_40 )
++ V_60 ;
else
++ V_59 ;
}
}
if ( V_60 || V_59 ) {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_16 ,
V_55 , V_59 ,
V_60 ) ) ;
V_60 = 0 ;
V_59 = 0 ;
++ V_61 ;
}
}
F_5 ( 2 , F_6 ( V_6 , V_2 ,
L_17
L_18 ,
V_58 , V_61 ) ) ;
}
static void F_38 ( struct V_20 * V_21 )
{
V_21 -> V_62 -> V_63 = 1 ;
}
static void F_39 ( struct V_20 * V_21 ,
struct V_64 * V_65 )
{
enum V_66 V_67 = V_68 ;
if ( V_65 -> V_69 == V_70 ) {
if ( V_65 -> V_71 == 0x3f && V_65 -> V_72 == 0x03 ) {
V_67 = V_73 ;
F_34 ( V_30 , V_21 ,
L_19 ) ;
} else if ( V_65 -> V_71 == 0x3f && V_65 -> V_72 == 0x0e ) {
V_67 = V_74 ;
F_38 ( V_21 ) ;
F_34 ( V_30 , V_21 ,
L_20
L_21
L_22
L_23 ) ;
} else if ( V_65 -> V_71 == 0x3f )
F_34 ( V_30 , V_21 ,
L_20
L_24
L_22
L_25 ) ;
if ( V_65 -> V_71 == 0x38 && V_65 -> V_72 == 0x07 ) {
V_67 = V_75 ;
F_34 ( V_30 , V_21 ,
L_20
L_26
L_27 ) ;
}
if ( V_65 -> V_71 == 0x2a && V_65 -> V_72 == 0x01 ) {
V_67 = V_76 ;
F_34 ( V_30 , V_21 ,
L_28 ) ;
} else if ( V_65 -> V_71 == 0x2a && V_65 -> V_72 == 0x09 ) {
V_67 = V_77 ;
F_34 ( V_30 , V_21 ,
L_29 ) ;
} else if ( V_65 -> V_71 == 0x2a )
F_34 ( V_30 , V_21 ,
L_30 ) ;
}
if ( V_67 != V_68 ) {
F_40 ( V_67 , V_21 -> V_78 ) ;
F_41 ( & V_21 -> V_79 ) ;
}
}
static int F_42 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_64 V_65 ;
if ( ! F_43 ( V_18 , & V_65 ) )
return V_34 ;
F_39 ( V_21 , & V_65 ) ;
if ( F_44 ( & V_65 ) )
return V_80 ;
if ( V_21 -> V_81 && V_21 -> V_81 -> V_82 &&
V_21 -> V_81 -> V_82 -> V_83 ) {
int V_84 ;
V_84 = V_21 -> V_81 -> V_82 -> V_83 ( V_21 , & V_65 ) ;
if ( V_84 != V_85 )
return V_84 ;
}
if ( V_18 -> V_86 [ 0 ] == V_87 && V_18 -> V_88 != V_89 )
return V_26 ;
if ( V_65 . V_90 == 0x70 ) {
if ( V_18 -> V_91 [ 2 ] & 0xe0 )
return V_26 ;
} else {
if ( ( V_65 . V_92 > 3 ) &&
( V_18 -> V_91 [ 8 ] == 0x4 ) &&
( V_18 -> V_91 [ 11 ] & 0xe0 ) )
return V_26 ;
}
switch ( V_65 . V_69 ) {
case V_93 :
return V_26 ;
case V_94 :
return V_26 ;
case V_95 :
if ( V_65 . V_71 == 0x10 )
return V_26 ;
return V_80 ;
case V_96 :
case V_70 :
if ( V_18 -> V_22 -> V_97 ) {
if ( V_65 . V_71 != 0x28 || V_65 . V_72 != 0x00 ) {
V_18 -> V_22 -> V_97 = 0 ;
return V_80 ;
}
}
if ( V_18 -> V_22 -> V_62 -> V_63 &&
V_65 . V_71 == 0x3f && V_65 . V_72 == 0x0e )
return V_80 ;
if ( ( V_65 . V_71 == 0x04 ) && ( V_65 . V_72 == 0x01 ) )
return V_80 ;
if ( V_18 -> V_22 -> V_98 &&
( V_65 . V_71 == 0x04 ) && ( V_65 . V_72 == 0x02 ) )
return V_34 ;
return V_26 ;
case V_99 :
if ( V_65 . V_71 == 0x27 && V_65 . V_72 == 0x07 ) {
F_17 ( V_18 , V_100 ) ;
return V_26 ;
}
case V_101 :
case V_102 :
case V_103 :
case V_104 :
F_17 ( V_18 , V_105 ) ;
return V_26 ;
case V_106 :
if ( V_65 . V_71 == 0x11 ||
V_65 . V_71 == 0x13 ||
V_65 . V_71 == 0x14 ) {
F_17 ( V_18 , V_107 ) ;
return V_26 ;
}
return V_80 ;
case V_108 :
if ( V_18 -> V_22 -> V_109 )
return V_110 ;
else
F_17 ( V_18 , V_105 ) ;
case V_111 :
if ( V_65 . V_71 == 0x20 ||
V_65 . V_71 == 0x21 ||
V_65 . V_71 == 0x24 ||
V_65 . V_71 == 0x26 ) {
F_17 ( V_18 , V_105 ) ;
}
return V_26 ;
default:
return V_26 ;
}
}
static void F_45 ( struct V_20 * V_21 )
{
struct V_112 * V_113 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_114 ;
if ( ! V_113 -> V_115 ||
V_21 -> V_116 >= V_21 -> V_117 )
return;
if ( F_12 ( V_14 ,
V_21 -> V_118 + V_21 -> V_119 ) )
return;
if ( F_12 ( V_14 ,
V_21 -> V_120 + V_21 -> V_119 ) )
return;
F_36 (tmp_sdev, sdev->host) {
if ( V_114 -> V_121 != V_21 -> V_121 ||
V_114 -> V_122 != V_21 -> V_122 ||
V_114 -> V_116 == V_21 -> V_117 )
continue;
V_113 -> V_115 ( V_114 , V_114 -> V_116 + 1 ,
V_123 ) ;
V_21 -> V_118 = V_14 ;
}
}
static void F_46 ( struct V_20 * V_21 )
{
struct V_112 * V_113 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_114 ;
if ( ! V_113 -> V_115 )
return;
F_36 (tmp_sdev, sdev->host) {
if ( V_114 -> V_121 != V_21 -> V_121 ||
V_114 -> V_122 != V_21 -> V_122 )
continue;
V_113 -> V_115 ( V_114 , V_114 -> V_116 - 1 ,
V_124 ) ;
}
}
static int F_47 ( struct V_17 * V_18 )
{
if ( F_48 ( V_18 -> V_125 ) == V_126 ) {
return F_42 ( V_18 ) ;
}
if ( F_48 ( V_18 -> V_125 ) != V_127 )
return V_34 ;
if ( F_49 ( V_18 -> V_125 ) != V_128 )
return V_34 ;
switch ( F_50 ( V_18 -> V_125 ) ) {
case V_129 :
F_45 ( V_18 -> V_22 ) ;
case V_130 :
return V_26 ;
case V_131 :
return F_42 ( V_18 ) ;
case V_132 :
case V_133 :
case V_134 :
return V_26 ;
case V_135 :
if ( V_18 -> V_86 [ 0 ] == V_87 )
return V_26 ;
return V_34 ;
case V_136 :
F_46 ( V_18 -> V_22 ) ;
case V_137 :
return V_80 ;
default:
return V_34 ;
}
return V_34 ;
}
static void V_89 ( struct V_17 * V_18 )
{
struct V_138 * V_139 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_31 ,
V_55 , V_18 , V_18 -> V_125 ) ) ;
V_139 = V_18 -> V_22 -> V_24 -> V_139 ;
if ( V_139 )
F_51 ( V_139 ) ;
}
static int F_52 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_112 * V_25 = V_24 -> V_25 ;
F_5 ( 3 ,
F_6 ( V_6 , V_24 , L_32 ) ) ;
if ( ! V_25 -> V_140 )
return V_34 ;
V_23 = V_25 -> V_140 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_141 )
F_53 ( V_142 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_54 ( V_24 , F_55 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_56 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_112 * V_25 = V_24 -> V_25 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_33 , V_55 ) ) ;
if ( ! V_25 -> V_143 )
return V_34 ;
V_23 = V_25 -> V_143 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_141 )
F_53 ( V_144 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_54 ( V_24 , F_55 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static void F_57 ( struct V_20 * V_21 , void * V_145 )
{
V_21 -> V_146 = 1 ;
V_21 -> V_97 = 1 ;
}
static int F_58 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_112 * V_25 = V_24 -> V_25 ;
if ( ! V_25 -> V_147 )
return V_34 ;
V_23 = V_25 -> V_147 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_8 ( V_24 -> V_8 , V_7 ) ;
F_59 ( F_60 ( V_18 -> V_22 ) , NULL ,
F_57 ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_61 ( struct V_17 * V_18 )
{
int V_23 ;
struct V_112 * V_25 = V_18 -> V_22 -> V_24 -> V_25 ;
if ( ! V_25 -> V_148 )
return V_34 ;
V_23 = V_25 -> V_148 ( V_18 ) ;
if ( V_23 == V_26 )
F_57 ( V_18 -> V_22 , NULL ) ;
return V_23 ;
}
static int F_16 ( struct V_112 * V_25 , struct V_17 * V_18 )
{
if ( ! V_25 -> V_149 )
return V_34 ;
return V_25 -> V_149 ( V_18 ) ;
}
static void F_62 ( struct V_17 * V_18 )
{
if ( F_16 ( V_18 -> V_22 -> V_24 -> V_25 , V_18 ) != V_26 )
if ( F_61 ( V_18 ) != V_26 )
if ( F_58 ( V_18 ) != V_26 )
if ( F_56 ( V_18 ) != V_26 )
F_52 ( V_18 ) ;
}
void F_63 ( struct V_17 * V_18 , struct V_150 * V_151 ,
unsigned char * V_86 , int V_152 , unsigned V_153 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
V_151 -> V_154 = V_18 -> V_154 ;
V_151 -> V_86 = V_18 -> V_86 ;
V_151 -> V_155 = V_18 -> V_156 ;
V_151 -> V_157 = V_18 -> V_157 ;
V_151 -> V_158 = V_18 -> V_44 -> V_158 ;
V_151 -> V_125 = V_18 -> V_125 ;
V_151 -> V_159 = V_18 -> V_159 ;
V_151 -> V_160 = V_18 -> V_160 ;
V_18 -> V_160 = V_161 ;
V_18 -> V_32 = 0 ;
V_18 -> V_86 = V_151 -> V_162 ;
memset ( V_18 -> V_86 , 0 , V_163 ) ;
memset ( & V_18 -> V_157 , 0 , sizeof( V_18 -> V_157 ) ) ;
V_18 -> V_44 -> V_158 = NULL ;
V_18 -> V_125 = 0 ;
if ( V_153 ) {
V_18 -> V_157 . V_164 = F_64 ( unsigned , V_165 ,
V_153 ) ;
F_65 ( & V_151 -> V_166 , V_18 -> V_91 ,
V_18 -> V_157 . V_164 ) ;
V_18 -> V_157 . V_167 . V_168 = & V_151 -> V_166 ;
V_18 -> V_156 = V_169 ;
V_18 -> V_157 . V_167 . V_170 = 1 ;
V_18 -> V_86 [ 0 ] = V_171 ;
V_18 -> V_86 [ 4 ] = V_18 -> V_157 . V_164 ;
V_18 -> V_154 = F_66 ( V_18 -> V_86 [ 0 ] ) ;
} else {
V_18 -> V_156 = V_172 ;
if ( V_86 ) {
F_23 ( V_152 > V_163 ) ;
memcpy ( V_18 -> V_86 , V_86 , V_152 ) ;
V_18 -> V_154 = F_66 ( V_18 -> V_86 [ 0 ] ) ;
}
}
V_18 -> V_159 = 0 ;
if ( V_21 -> V_173 <= V_174 && V_21 -> V_173 != V_175 )
V_18 -> V_86 [ 1 ] = ( V_18 -> V_86 [ 1 ] & 0x1f ) |
( V_21 -> V_176 << 5 & 0xe0 ) ;
memset ( V_18 -> V_91 , 0 , V_165 ) ;
}
void F_67 ( struct V_17 * V_18 , struct V_150 * V_151 )
{
V_18 -> V_154 = V_151 -> V_154 ;
V_18 -> V_86 = V_151 -> V_86 ;
V_18 -> V_156 = V_151 -> V_155 ;
V_18 -> V_157 = V_151 -> V_157 ;
V_18 -> V_44 -> V_158 = V_151 -> V_158 ;
V_18 -> V_125 = V_151 -> V_125 ;
V_18 -> V_159 = V_151 -> V_159 ;
V_18 -> V_160 = V_151 -> V_160 ;
}
static int F_68 ( struct V_17 * V_18 , unsigned char * V_86 ,
int V_152 , int V_177 , unsigned V_153 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_24 ;
F_69 ( V_178 ) ;
unsigned long V_179 = V_177 ;
struct V_150 V_151 ;
const unsigned long V_180 = F_70 ( 100 ) ;
int V_23 ;
V_181:
F_63 ( V_18 , & V_151 , V_86 , V_152 , V_153 ) ;
V_2 -> V_139 = & V_178 ;
F_71 ( V_18 ) ;
V_18 -> V_88 = V_89 ;
V_23 = V_2 -> V_25 -> V_182 ( V_2 , V_18 ) ;
if ( V_23 ) {
if ( V_179 > V_180 ) {
F_67 ( V_18 , & V_151 ) ;
V_179 -= V_180 ;
F_72 ( F_73 ( V_180 ) ) ;
goto V_181;
}
V_179 = 0 ;
V_23 = V_80 ;
} else {
V_179 = F_74 ( & V_178 , V_177 ) ;
V_23 = V_26 ;
}
V_2 -> V_139 = NULL ;
F_30 ( V_18 , V_23 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_34 ,
V_55 , V_18 , V_179 ) ) ;
if ( V_179 ) {
V_23 = F_47 ( V_18 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_35 , V_55 , V_23 ) ) ;
switch ( V_23 ) {
case V_26 :
case V_80 :
case V_34 :
break;
case V_110 :
V_23 = V_80 ;
break;
default:
V_23 = V_34 ;
break;
}
} else if ( ! V_23 ) {
F_62 ( V_18 ) ;
V_23 = V_34 ;
}
F_67 ( V_18 , & V_151 ) ;
return V_23 ;
}
static int F_75 ( struct V_17 * V_18 )
{
return F_68 ( V_18 , NULL , 0 , V_18 -> V_22 -> V_183 , ~ 0 ) ;
}
static int F_76 ( struct V_17 * V_18 , int V_23 )
{
if ( V_18 -> V_44 -> V_184 != V_185 ) {
struct V_186 * V_187 = F_77 ( V_18 ) ;
if ( V_187 -> V_139 )
V_23 = V_187 -> V_139 ( V_18 , V_23 ) ;
}
return V_23 ;
}
void F_78 ( struct V_17 * V_18 , struct V_56 * V_188 )
{
V_18 -> V_22 -> V_24 -> V_4 -- ;
V_18 -> V_32 = 0 ;
F_79 ( & V_18 -> V_41 , V_188 ) ;
}
int F_80 ( struct V_56 * V_57 ,
struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_189 ;
struct V_1 * V_2 ;
int V_23 ;
F_81 (scmd, next, work_q, eh_entry) {
if ( ( V_18 -> V_32 & V_40 ) ||
F_82 ( V_18 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_36 ,
V_55 ) ) ;
break;
}
if ( F_50 ( V_18 -> V_125 ) != V_131 )
continue;
F_5 ( 2 , F_15 ( V_6 , V_18 ,
L_37 ,
V_190 -> V_191 ) ) ;
V_23 = F_75 ( V_18 ) ;
if ( V_23 != V_26 )
continue;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_38 ,
V_18 , V_18 -> V_125 ) ) ;
F_5 ( 3 , F_83 ( L_39 , V_18 ) ) ;
V_23 = F_84 ( V_18 ) ;
if ( V_23 == V_26 )
V_18 -> V_28 = V_18 -> V_29 ;
else if ( V_23 != V_80 )
continue;
F_78 ( V_18 , V_188 ) ;
}
return F_85 ( V_57 ) ;
}
static int F_86 ( struct V_17 * V_18 )
{
static unsigned char V_192 [ 6 ] = { V_87 , 0 , 0 , 0 , 0 , 0 } ;
int V_193 = 1 , V_23 ;
V_194:
V_23 = F_68 ( V_18 , V_192 , 6 ,
V_18 -> V_22 -> V_183 , 0 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_40 , V_55 , V_18 , V_23 ) ) ;
switch ( V_23 ) {
case V_80 :
if ( V_193 -- )
goto V_194;
case V_26 :
return 0 ;
default:
return 1 ;
}
}
static int F_87 ( struct V_56 * V_195 ,
struct V_56 * V_57 ,
struct V_56 * V_188 , int V_196 )
{
struct V_17 * V_18 , * V_189 ;
struct V_20 * V_21 ;
int V_197 ;
while ( ! F_85 ( V_195 ) ) {
V_18 = F_88 ( V_195 -> V_189 , struct V_17 , V_41 ) ;
V_21 = V_18 -> V_22 ;
if ( ! V_196 ) {
if ( F_11 ( V_21 -> V_24 ) ) {
F_89 ( V_195 , V_57 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_21 -> V_24 ,
L_41 ,
V_55 ) ) ;
break;
}
}
V_197 = ! F_33 ( V_18 -> V_22 ) ||
( V_196 && ! F_90 ( V_18 ) &&
! F_86 ( V_18 ) ) ||
! F_86 ( V_18 ) ;
F_81 (scmd, next, cmd_list, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
if ( V_197 &&
( V_196 ||
F_76 ( V_18 , V_26 ) == V_26 ) )
F_78 ( V_18 , V_188 ) ;
else
F_79 ( & V_18 -> V_41 , V_57 ) ;
}
}
return F_85 ( V_57 ) ;
}
static int F_91 ( struct V_56 * V_57 ,
struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_189 ;
F_92 ( V_198 ) ;
int V_23 ;
struct V_1 * V_2 ;
F_81 (scmd, next, work_q, eh_entry) {
if ( ! ( V_18 -> V_32 & V_40 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_89 ( & V_198 , V_57 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_36 ,
V_55 ) ) ;
return F_85 ( V_57 ) ;
}
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_42 ,
V_190 -> V_191 , V_18 ) ) ;
V_23 = F_16 ( V_2 -> V_25 , V_18 ) ;
if ( V_23 == V_34 ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_43 ,
V_190 -> V_191 , V_18 ) ) ;
F_89 ( & V_198 , V_57 ) ;
return F_85 ( V_57 ) ;
}
V_18 -> V_32 &= ~ V_40 ;
if ( V_23 == V_199 )
F_78 ( V_18 , V_188 ) ;
else
F_79 ( & V_18 -> V_41 , & V_198 ) ;
}
return F_87 ( & V_198 , V_57 , V_188 , 0 ) ;
}
static int F_90 ( struct V_17 * V_18 )
{
static unsigned char V_200 [ 6 ] = { V_201 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_18 -> V_22 -> V_98 ) {
int V_202 , V_23 = V_80 ;
for ( V_202 = 0 ; V_23 == V_80 && V_202 < 2 ; V_202 ++ )
V_23 = F_68 ( V_18 , V_200 , 6 , V_18 -> V_22 -> V_203 -> V_204 , 0 ) ;
if ( V_23 == V_26 )
return 0 ;
}
return 1 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_205 , * V_189 ;
struct V_20 * V_21 ;
F_36 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_36 ,
V_55 ) ) ;
break;
}
V_205 = NULL ;
F_37 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 && F_82 ( V_18 ) &&
F_42 ( V_18 ) == V_34 ) {
V_205 = V_18 ;
break;
}
if ( ! V_205 )
continue;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_44 ,
V_190 -> V_191 , V_21 ) ) ;
if ( ! F_90 ( V_205 ) ) {
if ( ! F_33 ( V_21 ) ||
! F_86 ( V_205 ) ) {
F_81 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_76 ( V_18 , V_26 ) == V_26 )
F_78 ( V_18 , V_188 ) ;
}
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_45
L_46 , V_190 -> V_191 , V_21 ) ) ;
}
}
return F_85 ( V_57 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_206 , * V_189 ;
struct V_20 * V_21 ;
int V_23 ;
F_36 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_36 ,
V_55 ) ) ;
break;
}
V_206 = NULL ;
F_37 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
V_206 = V_18 ;
break;
}
if ( ! V_206 )
continue;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_47 ,
V_190 -> V_191 , V_21 ) ) ;
V_23 = F_61 ( V_206 ) ;
if ( V_23 == V_26 || V_23 == V_199 ) {
if ( ! F_33 ( V_21 ) ||
V_23 == V_199 ||
! F_86 ( V_206 ) ) {
F_81 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_76 ( V_18 , V_23 ) != V_34 )
F_78 ( V_18 ,
V_188 ) ;
}
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_48 ,
V_190 -> V_191 , V_21 ) ) ;
}
}
return F_85 ( V_57 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_188 )
{
F_92 ( V_207 ) ;
F_92 ( V_198 ) ;
F_89 ( V_57 , & V_207 ) ;
while ( ! F_85 ( & V_207 ) ) {
struct V_17 * V_189 , * V_18 ;
int V_23 ;
unsigned int V_122 ;
if ( F_11 ( V_2 ) ) {
F_89 ( & V_198 , V_57 ) ;
F_89 ( & V_207 , V_57 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_36 ,
V_55 ) ) ;
return F_85 ( V_57 ) ;
}
V_18 = F_88 ( V_207 . V_189 , struct V_17 , V_41 ) ;
V_122 = F_96 ( V_18 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_49 ,
V_190 -> V_191 , V_122 ) ) ;
V_23 = F_58 ( V_18 ) ;
if ( V_23 != V_26 && V_23 != V_199 )
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_50
L_51 ,
V_190 -> V_191 , V_122 ) ) ;
F_81 (scmd, next, &tmp_list, eh_entry) {
if ( F_96 ( V_18 ) != V_122 )
continue;
if ( V_23 == V_26 )
F_79 ( & V_18 -> V_41 , & V_198 ) ;
else if ( V_23 == V_199 )
F_78 ( V_18 , V_188 ) ;
else
F_97 ( & V_18 -> V_41 , V_57 ) ;
}
}
return F_87 ( & V_198 , V_57 , V_188 , 0 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_208 , * V_189 ;
F_92 ( V_198 ) ;
unsigned int V_121 ;
int V_23 ;
for ( V_121 = 0 ; V_121 <= V_2 -> V_209 ; V_121 ++ ) {
if ( F_11 ( V_2 ) ) {
F_89 ( & V_198 , V_57 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_36 ,
V_55 ) ) ;
return F_85 ( V_57 ) ;
}
V_208 = NULL ;
F_37 (scmd, work_q, eh_entry) {
if ( V_121 == F_55 ( V_18 ) ) {
V_208 = V_18 ;
break;
}
}
if ( ! V_208 )
continue;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_52 ,
V_190 -> V_191 , V_121 ) ) ;
V_23 = F_56 ( V_208 ) ;
if ( V_23 == V_26 || V_23 == V_199 ) {
F_81 (scmd, next, work_q, eh_entry) {
if ( V_121 == F_55 ( V_18 ) ) {
if ( V_23 == V_199 )
F_78 ( V_18 ,
V_188 ) ;
else
F_79 ( & V_18 -> V_41 ,
& V_198 ) ;
}
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_53 ,
V_190 -> V_191 , V_121 ) ) ;
}
}
return F_87 ( & V_198 , V_57 , V_188 , 0 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_189 ;
F_92 ( V_198 ) ;
int V_23 ;
if ( ! F_85 ( V_57 ) ) {
V_18 = F_88 ( V_57 -> V_189 ,
struct V_17 , V_41 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_54 ,
V_190 -> V_191 ) ) ;
V_23 = F_52 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_89 ( V_57 , & V_198 ) ;
} else if ( V_23 == V_199 ) {
F_81 (scmd, next, work_q, eh_entry) {
F_78 ( V_18 , V_188 ) ;
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_55 ,
V_190 -> V_191 ) ) ;
}
}
return F_87 ( & V_198 , V_57 , V_188 , 1 ) ;
}
static void F_100 ( struct V_56 * V_57 ,
struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_189 ;
F_81 (scmd, next, work_q, eh_entry) {
F_34 ( V_6 , V_18 -> V_22 , L_56
L_57 ) ;
F_101 ( V_18 -> V_22 , V_210 ) ;
if ( V_18 -> V_32 & V_40 ) {
}
F_78 ( V_18 , V_188 ) ;
}
return;
}
int F_18 ( struct V_17 * V_18 )
{
switch ( F_48 ( V_18 -> V_125 ) ) {
case V_127 :
break;
case V_27 :
goto V_211;
case V_212 :
return ( V_18 -> V_44 -> V_213 & V_214 ) ;
case V_215 :
return ( V_18 -> V_44 -> V_213 & V_216 ) ;
case V_217 :
if ( F_49 ( V_18 -> V_125 ) == V_128 &&
F_50 ( V_18 -> V_125 ) == V_135 )
return 0 ;
case V_218 :
return ( V_18 -> V_44 -> V_213 & V_219 ) ;
}
if ( F_50 ( V_18 -> V_125 ) != V_131 )
return 0 ;
V_211:
if ( V_18 -> V_44 -> V_213 & V_216 ||
V_18 -> V_44 -> V_184 == V_185 )
return 1 ;
else
return 0 ;
}
int F_84 ( struct V_17 * V_18 )
{
int V_23 ;
if ( ! F_33 ( V_18 -> V_22 ) ) {
F_5 ( 5 , F_15 ( V_6 , V_18 ,
L_58 , V_55 ) ) ;
return V_26 ;
}
switch ( F_48 ( V_18 -> V_125 ) ) {
case V_220 :
V_18 -> V_125 &= 0xff00ffff ;
return V_26 ;
case V_127 :
break;
case V_221 :
if ( V_18 -> V_32 & V_33 ) {
F_17 ( V_18 , V_27 ) ;
return V_26 ;
}
case V_222 :
case V_223 :
return V_26 ;
case V_218 :
goto V_224;
case V_225 :
return V_80 ;
case V_226 :
return V_110 ;
case V_227 :
goto V_224;
case V_228 :
return V_26 ;
case V_217 :
if ( F_49 ( V_18 -> V_125 ) == V_128 &&
F_50 ( V_18 -> V_125 ) == V_135 )
break;
case V_212 :
case V_215 :
goto V_224;
case V_27 :
if ( ( V_18 -> V_86 [ 0 ] == V_87 ||
V_18 -> V_86 [ 0 ] == V_229 ) ) {
return V_26 ;
} else {
return V_34 ;
}
case V_126 :
return V_26 ;
default:
return V_34 ;
}
if ( F_49 ( V_18 -> V_125 ) != V_128 )
return V_34 ;
switch ( F_50 ( V_18 -> V_125 ) ) {
case V_136 :
F_46 ( V_18 -> V_22 ) ;
case V_137 :
return V_110 ;
case V_129 :
if ( V_18 -> V_86 [ 0 ] == V_230 )
V_18 -> V_22 -> V_62 -> V_63 = 0 ;
F_45 ( V_18 -> V_22 ) ;
case V_130 :
return V_26 ;
case V_231 :
goto V_224;
case V_131 :
V_23 = F_42 ( V_18 ) ;
if ( V_23 == V_80 )
goto V_224;
return V_23 ;
case V_132 :
case V_133 :
case V_134 :
case V_232 :
return V_26 ;
case V_135 :
F_34 ( V_6 , V_18 -> V_22 ,
L_59 ) ;
F_17 ( V_18 , V_233 ) ;
return V_26 ;
default:
return V_34 ;
}
return V_34 ;
V_224:
if ( ( ++ V_18 -> V_28 ) <= V_18 -> V_29
&& ! F_18 ( V_18 ) ) {
return V_80 ;
} else {
return V_26 ;
}
}
static void F_102 ( struct V_44 * V_45 , int V_234 )
{
F_103 ( V_45 -> V_235 , V_45 ) ;
}
static void F_104 ( struct V_20 * V_21 )
{
struct V_44 * V_45 ;
V_45 = F_105 ( V_21 -> V_203 , V_236 , V_237 ) ;
if ( F_106 ( V_45 ) )
return;
F_107 ( V_45 ) ;
V_45 -> V_238 [ 0 ] = V_239 ;
V_45 -> V_238 [ 1 ] = 0 ;
V_45 -> V_238 [ 2 ] = 0 ;
V_45 -> V_238 [ 3 ] = 0 ;
V_45 -> V_238 [ 4 ] = V_240 ;
V_45 -> V_238 [ 5 ] = 0 ;
V_45 -> V_154 = F_66 ( V_45 -> V_238 [ 0 ] ) ;
V_45 -> V_213 |= V_241 ;
V_45 -> V_177 = 10 * V_36 ;
V_45 -> V_28 = 5 ;
F_108 ( V_45 -> V_235 , NULL , V_45 , 1 , F_102 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned long V_7 ;
F_36 (sdev, shost) {
if ( F_33 ( V_21 ) && V_21 -> V_146 && V_21 -> V_242 ) {
F_104 ( V_21 ) ;
V_21 -> V_146 = 0 ;
}
}
F_5 ( 3 ,
F_6 ( V_6 , V_2 , L_60 ) ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_243 ) )
if ( F_9 ( V_2 , V_244 ) )
F_23 ( F_9 ( V_2 , V_245 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_110 ( & V_2 -> V_54 ) ;
F_111 ( V_2 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_11 )
if ( F_9 ( V_2 , V_9 ) )
F_112 ( F_9 ( V_2 , V_10 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
}
void F_113 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_188 )
{
if ( ! F_93 ( V_2 , V_57 , V_188 ) )
if ( ! F_94 ( V_2 , V_57 , V_188 ) )
if ( ! F_95 ( V_2 , V_57 , V_188 ) )
if ( ! F_98 ( V_2 , V_57 , V_188 ) )
if ( ! F_99 ( V_2 , V_57 , V_188 ) )
F_100 ( V_57 ,
V_188 ) ;
}
void F_114 ( struct V_56 * V_188 )
{
struct V_17 * V_18 , * V_189 ;
F_81 (scmd, next, done_q, eh_entry) {
F_115 ( & V_18 -> V_41 ) ;
if ( F_33 ( V_18 -> V_22 ) &&
! F_18 ( V_18 ) &&
( ++ V_18 -> V_28 <= V_18 -> V_29 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_61 ,
V_190 -> V_191 , V_18 ) ) ;
F_19 ( V_18 , V_31 ) ;
} else {
if ( ! V_18 -> V_125 )
V_18 -> V_125 |= ( V_246 << 24 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_62 ,
V_190 -> V_191 , V_18 ) ) ;
F_20 ( V_18 ) ;
}
}
}
static void F_116 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_92 ( V_247 ) ;
F_92 ( V_248 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
F_89 ( & V_2 -> V_42 , & V_247 ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 1 , F_35 ( V_2 , & V_247 ) ) ;
if ( ! F_80 ( & V_247 , & V_248 ) )
if ( ! F_91 ( & V_247 , & V_248 ) )
F_113 ( V_2 , & V_247 , & V_248 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_13 != - 1 )
V_2 -> V_12 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_114 ( & V_248 ) ;
}
int F_117 ( void * V_145 )
{
struct V_1 * V_2 = V_145 ;
while ( ! F_118 () ) {
F_119 ( V_249 ) ;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_11 == 0 ) ||
V_2 -> V_4 != F_2 ( & V_2 -> V_3 ) ) {
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_63 ,
V_2 -> V_250 ) ) ;
F_120 () ;
continue;
}
F_121 ( V_251 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_64 ,
V_2 -> V_250 , V_2 -> V_11 ,
V_2 -> V_4 ,
F_2 ( & V_2 -> V_3 ) ) ) ;
if ( ! V_2 -> V_252 && F_122 ( V_2 ) != 0 ) {
F_5 ( 1 ,
F_123 ( V_253 L_65
L_66 ,
V_2 -> V_250 ) ) ;
continue;
}
if ( V_2 -> V_49 -> V_254 )
V_2 -> V_49 -> V_254 ( V_2 ) ;
else
F_116 ( V_2 ) ;
F_109 ( V_2 ) ;
if ( ! V_2 -> V_252 )
F_124 ( V_2 ) ;
}
F_121 ( V_251 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_67 ,
V_2 -> V_250 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_54 ( struct V_1 * V_2 , int V_121 )
{
struct V_20 * V_21 ;
F_125 (sdev, shost) {
if ( V_121 == F_126 ( V_21 ) )
F_57 ( V_21 , NULL ) ;
}
}
void F_127 ( struct V_1 * V_2 , int V_121 , int V_255 )
{
struct V_20 * V_21 ;
F_125 (sdev, shost) {
if ( V_121 == F_126 ( V_21 ) &&
V_255 == F_128 ( V_21 ) )
F_57 ( V_21 , NULL ) ;
}
}
static void
F_129 ( struct V_17 * V_18 )
{
}
int
F_130 ( struct V_20 * V_256 , int V_257 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = V_256 -> V_24 ;
struct V_44 V_45 ;
unsigned long V_7 ;
int V_23 ;
if ( F_122 ( V_2 ) < 0 )
return V_34 ;
if ( ! F_131 ( & V_256 -> V_258 ) ) {
V_23 = V_34 ;
goto V_259;
}
V_18 = F_132 ( V_256 , V_237 ) ;
if ( ! V_18 ) {
V_23 = V_34 ;
F_133 ( & V_256 -> V_258 ) ;
goto V_259;
}
F_134 ( NULL , & V_45 ) ;
V_18 -> V_44 = & V_45 ;
V_18 -> V_86 = V_45 . V_238 ;
V_18 -> V_88 = F_129 ;
memset ( & V_18 -> V_157 , 0 , sizeof( V_18 -> V_157 ) ) ;
V_18 -> V_154 = 0 ;
V_18 -> V_156 = V_260 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_261 = 1 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
switch ( V_257 ) {
case V_262 :
V_23 = F_61 ( V_18 ) ;
if ( V_23 == V_26 )
break;
case V_263 :
V_23 = F_58 ( V_18 ) ;
if ( V_23 == V_26 )
break;
case V_264 :
V_23 = F_56 ( V_18 ) ;
if ( V_23 == V_26 )
break;
case V_265 :
V_23 = F_52 ( V_18 ) ;
break;
default:
V_23 = V_34 ;
}
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_261 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_68 ) ) ;
F_110 ( & V_2 -> V_54 ) ;
F_111 ( V_2 ) ;
F_135 ( V_18 ) ;
V_259:
F_124 ( V_2 ) ;
return V_23 ;
}
int F_136 ( const T_1 * V_91 , int V_266 ,
struct V_64 * V_65 )
{
if ( ! V_91 || ! V_266 )
return 0 ;
memset ( V_65 , 0 , sizeof( struct V_64 ) ) ;
V_65 -> V_90 = ( V_91 [ 0 ] & 0x7f ) ;
if ( ! F_137 ( V_65 ) )
return 0 ;
if ( V_65 -> V_90 >= 0x72 ) {
if ( V_266 > 1 )
V_65 -> V_69 = ( V_91 [ 1 ] & 0xf ) ;
if ( V_266 > 2 )
V_65 -> V_71 = V_91 [ 2 ] ;
if ( V_266 > 3 )
V_65 -> V_72 = V_91 [ 3 ] ;
if ( V_266 > 7 )
V_65 -> V_92 = V_91 [ 7 ] ;
} else {
if ( V_266 > 2 )
V_65 -> V_69 = ( V_91 [ 2 ] & 0xf ) ;
if ( V_266 > 7 ) {
V_266 = ( V_266 < ( V_91 [ 7 ] + 8 ) ) ?
V_266 : ( V_91 [ 7 ] + 8 ) ;
if ( V_266 > 12 )
V_65 -> V_71 = V_91 [ 12 ] ;
if ( V_266 > 13 )
V_65 -> V_72 = V_91 [ 13 ] ;
}
}
return 1 ;
}
int F_43 ( struct V_17 * V_238 ,
struct V_64 * V_65 )
{
return F_136 ( V_238 -> V_91 ,
V_165 , V_65 ) ;
}
const T_1 * F_138 ( const T_1 * V_91 , int V_266 ,
int V_267 )
{
int V_268 , V_269 , V_270 , V_271 ;
const T_1 * V_272 ;
if ( ( V_266 < 8 ) || ( 0 == ( V_268 = V_91 [ 7 ] ) ) )
return NULL ;
if ( ( V_91 [ 0 ] < 0x72 ) || ( V_91 [ 0 ] > 0x73 ) )
return NULL ;
V_268 = ( V_268 < ( V_266 - 8 ) ) ?
V_268 : ( V_266 - 8 ) ;
V_272 = & V_91 [ 8 ] ;
for ( V_270 = 0 , V_271 = 0 ; V_271 < V_268 ; V_271 += V_270 ) {
V_272 += V_270 ;
V_269 = ( V_271 < ( V_268 - 1 ) ) ? V_272 [ 1 ] : - 1 ;
V_270 = V_269 + 2 ;
if ( V_272 [ 0 ] == V_267 )
return V_272 ;
if ( V_269 < 0 )
break;
}
return NULL ;
}
int F_139 ( const T_1 * V_91 , int V_266 ,
T_2 * V_273 )
{
int V_274 ;
const T_1 * V_275 ;
T_2 V_276 ;
if ( V_266 < 7 )
return 0 ;
switch ( V_91 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_91 [ 0 ] & 0x80 ) {
* V_273 = ( V_91 [ 3 ] << 24 ) +
( V_91 [ 4 ] << 16 ) +
( V_91 [ 5 ] << 8 ) + V_91 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_275 = F_138 ( V_91 , V_266 ,
0 ) ;
if ( V_275 && ( 0xa == V_275 [ 1 ] ) ) {
V_276 = 0 ;
for ( V_274 = 0 ; V_274 < 8 ; ++ V_274 ) {
if ( V_274 > 0 )
V_276 <<= 8 ;
V_276 |= V_275 [ 4 + V_274 ] ;
}
* V_273 = V_276 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
void F_140 ( int V_277 , T_1 * V_278 , T_1 V_279 , T_1 V_71 , T_1 V_72 )
{
if ( V_277 ) {
V_278 [ 0 ] = 0x72 ;
V_278 [ 1 ] = V_279 ;
V_278 [ 2 ] = V_71 ;
V_278 [ 3 ] = V_72 ;
V_278 [ 7 ] = 0 ;
} else {
V_278 [ 0 ] = 0x70 ;
V_278 [ 2 ] = V_279 ;
V_278 [ 7 ] = 0xa ;
V_278 [ 12 ] = V_71 ;
V_278 [ 13 ] = V_72 ;
}
}
