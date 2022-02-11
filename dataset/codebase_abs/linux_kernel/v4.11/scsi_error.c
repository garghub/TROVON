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
L_2 ) ) ;
} else {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_3 ) ) ;
V_23 = F_16 ( V_21 -> V_24 -> V_25 , V_18 ) ;
if ( V_23 == V_26 ) {
F_17 ( V_18 , V_27 ) ;
if ( F_11 ( V_21 -> V_24 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_4
L_5 ) ) ;
} else if ( ! F_18 ( V_18 ) &&
( ++ V_18 -> V_28 <= V_18 -> V_29 ) ) {
F_5 ( 3 ,
F_15 ( V_30 , V_18 ,
L_6 ) ) ;
F_19 ( V_18 , V_31 ) ;
return;
} else {
F_5 ( 3 ,
F_15 ( V_30 , V_18 ,
L_7 ) ) ;
F_20 ( V_18 ) ;
return;
}
} else {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_8 ,
( V_23 == V_32 ) ?
L_9 : L_10 ) ) ;
}
}
if ( ! F_21 ( V_18 , 0 ) ) {
F_5 ( 3 ,
F_15 ( V_30 , V_18 ,
L_11 ) ) ;
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
if ( V_18 -> V_33 & V_34 ) {
V_18 -> V_33 &= ~ V_34 ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_12 ) ) ;
F_23 ( F_24 ( & V_18 -> V_19 ) ) ;
return V_35 ;
}
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_25 ( V_2 ) ) {
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_13 ) ) ;
return V_35 ;
}
if ( V_2 -> V_13 != - 1 && ! V_2 -> V_12 )
V_2 -> V_12 = V_14 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
V_18 -> V_33 |= V_34 ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 , L_14 ) ) ;
F_26 ( V_2 -> V_36 , & V_18 -> V_19 , V_37 / 100 ) ;
return V_26 ;
}
int F_21 ( struct V_17 * V_18 , int V_38 )
{
struct V_1 * V_2 = V_18 -> V_22 -> V_24 ;
unsigned long V_7 ;
int V_39 = 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_9 ) )
if ( F_9 ( V_2 , V_10 ) )
goto V_40;
if ( V_2 -> V_13 != - 1 && ! V_2 -> V_12 )
V_2 -> V_12 = V_14 ;
V_39 = 1 ;
if ( V_18 -> V_33 & V_34 )
V_38 &= ~ V_41 ;
V_18 -> V_33 |= V_38 ;
F_27 ( & V_18 -> V_42 , & V_2 -> V_43 ) ;
V_2 -> V_4 ++ ;
F_1 ( V_2 ) ;
V_40:
F_10 ( V_2 -> V_8 , V_7 ) ;
return V_39 ;
}
enum V_44 F_28 ( struct V_45 * V_46 )
{
struct V_17 * V_18 = V_46 -> V_47 ;
enum V_44 V_23 = V_48 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
F_29 ( V_18 ) ;
F_30 ( V_18 , V_49 ) ;
if ( V_24 -> V_13 != - 1 && ! V_24 -> V_12 )
V_24 -> V_12 = V_14 ;
if ( V_24 -> V_25 -> V_50 )
V_23 = V_24 -> V_25 -> V_50 ( V_18 ) ;
if ( V_23 == V_48 ) {
if ( ! V_24 -> V_25 -> V_51 &&
F_22 ( V_18 ) == V_26 )
return V_48 ;
F_17 ( V_18 , V_27 ) ;
if ( ! F_21 ( V_18 , V_41 ) )
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
if ( V_18 -> V_33 & V_41 )
++ V_60 ;
else
++ V_59 ;
}
}
if ( V_60 || V_59 ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
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
} else if ( V_65 -> V_71 == 0x2a && V_65 -> V_72 == 0x06 ) {
V_67 = V_77 ;
F_34 ( V_30 , V_21 ,
L_29 ) ;
} else if ( V_65 -> V_71 == 0x2a && V_65 -> V_72 == 0x09 ) {
V_67 = V_78 ;
F_34 ( V_30 , V_21 ,
L_30 ) ;
} else if ( V_65 -> V_71 == 0x2a )
F_34 ( V_30 , V_21 ,
L_31 ) ;
}
if ( V_67 != V_68 ) {
F_40 ( V_67 , V_21 -> V_79 ) ;
F_41 ( & V_21 -> V_80 ) ;
}
}
int F_42 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_64 V_65 ;
if ( ! F_43 ( V_18 , & V_65 ) )
return V_35 ;
F_39 ( V_21 , & V_65 ) ;
if ( F_44 ( & V_65 ) )
return V_81 ;
if ( V_21 -> V_82 && V_21 -> V_82 -> V_83 ) {
int V_84 ;
V_84 = V_21 -> V_82 -> V_83 ( V_21 , & V_65 ) ;
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
return V_81 ;
case V_96 :
case V_70 :
if ( V_18 -> V_22 -> V_97 ) {
if ( V_65 . V_71 != 0x28 || V_65 . V_72 != 0x00 ) {
V_18 -> V_22 -> V_97 = 0 ;
return V_81 ;
}
}
if ( V_18 -> V_22 -> V_62 -> V_63 &&
V_65 . V_71 == 0x3f && V_65 . V_72 == 0x0e )
return V_81 ;
if ( ( V_65 . V_71 == 0x04 ) && ( V_65 . V_72 == 0x01 ) )
return V_81 ;
if ( V_18 -> V_22 -> V_98 &&
( V_65 . V_71 == 0x04 ) && ( V_65 . V_72 == 0x02 ) )
return V_35 ;
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
return V_81 ;
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
F_46 ( V_114 , V_114 -> V_116 + 1 ) ;
V_21 -> V_118 = V_14 ;
}
}
static void F_47 ( struct V_20 * V_21 )
{
struct V_112 * V_113 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_114 ;
if ( ! V_113 -> V_115 )
return;
F_36 (tmp_sdev, sdev->host) {
if ( V_114 -> V_121 != V_21 -> V_121 ||
V_114 -> V_122 != V_21 -> V_122 )
continue;
F_48 ( V_114 , V_114 -> V_116 - 1 ) ;
}
}
static int F_49 ( struct V_17 * V_18 )
{
if ( F_50 ( V_18 -> V_123 ) == V_124 ) {
return F_42 ( V_18 ) ;
}
if ( F_50 ( V_18 -> V_123 ) != V_125 )
return V_35 ;
if ( F_51 ( V_18 -> V_123 ) != V_126 )
return V_35 ;
switch ( F_52 ( V_18 -> V_123 ) ) {
case V_127 :
F_45 ( V_18 -> V_22 ) ;
case V_128 :
return V_26 ;
case V_129 :
return F_42 ( V_18 ) ;
case V_130 :
case V_131 :
case V_132 :
return V_26 ;
case V_133 :
if ( V_18 -> V_86 [ 0 ] == V_87 )
return V_26 ;
return V_35 ;
case V_134 :
F_47 ( V_18 -> V_22 ) ;
case V_135 :
return V_81 ;
default:
return V_35 ;
}
return V_35 ;
}
static void V_89 ( struct V_17 * V_18 )
{
struct V_136 * V_137 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_32 , V_55 , V_18 -> V_123 ) ) ;
V_137 = V_18 -> V_22 -> V_24 -> V_137 ;
if ( V_137 )
F_53 ( V_137 ) ;
}
static int F_54 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_112 * V_25 = V_24 -> V_25 ;
F_5 ( 3 ,
F_6 ( V_6 , V_24 , L_33 ) ) ;
if ( ! V_25 -> V_138 )
return V_35 ;
V_23 = V_25 -> V_138 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_139 )
F_55 ( V_140 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_56 ( V_24 , F_57 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_58 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_112 * V_25 = V_24 -> V_25 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_34 , V_55 ) ) ;
if ( ! V_25 -> V_141 )
return V_35 ;
V_23 = V_25 -> V_141 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_139 )
F_55 ( V_142 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_56 ( V_24 , F_57 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static void F_59 ( struct V_20 * V_21 , void * V_143 )
{
V_21 -> V_144 = 1 ;
V_21 -> V_97 = 1 ;
}
static int F_60 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_112 * V_25 = V_24 -> V_25 ;
if ( ! V_25 -> V_145 )
return V_35 ;
V_23 = V_25 -> V_145 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_8 ( V_24 -> V_8 , V_7 ) ;
F_61 ( F_62 ( V_18 -> V_22 ) , NULL ,
F_59 ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_63 ( struct V_17 * V_18 )
{
int V_23 ;
struct V_112 * V_25 = V_18 -> V_22 -> V_24 -> V_25 ;
if ( ! V_25 -> V_146 )
return V_35 ;
V_23 = V_25 -> V_146 ( V_18 ) ;
if ( V_23 == V_26 )
F_59 ( V_18 -> V_22 , NULL ) ;
return V_23 ;
}
static int F_16 ( struct V_112 * V_25 ,
struct V_17 * V_18 )
{
if ( ! V_25 -> V_147 )
return V_35 ;
return V_25 -> V_147 ( V_18 ) ;
}
static void F_64 ( struct V_17 * V_18 )
{
if ( F_16 ( V_18 -> V_22 -> V_24 -> V_25 , V_18 ) != V_26 )
if ( F_63 ( V_18 ) != V_26 )
if ( F_60 ( V_18 ) != V_26 )
if ( F_58 ( V_18 ) != V_26 )
F_54 ( V_18 ) ;
}
void F_65 ( struct V_17 * V_18 , struct V_148 * V_149 ,
unsigned char * V_86 , int V_150 , unsigned V_151 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
V_149 -> V_152 = V_18 -> V_152 ;
V_149 -> V_86 = V_18 -> V_86 ;
V_149 -> V_153 = V_18 -> V_154 ;
V_149 -> V_155 = V_18 -> V_155 ;
V_149 -> V_156 = V_18 -> V_45 -> V_156 ;
V_149 -> V_123 = V_18 -> V_123 ;
V_149 -> V_157 = V_18 -> V_157 ;
V_149 -> V_158 = V_18 -> V_158 ;
V_18 -> V_158 = V_159 ;
V_18 -> V_33 = 0 ;
V_18 -> V_86 = V_149 -> V_160 ;
memset ( V_18 -> V_86 , 0 , V_161 ) ;
memset ( & V_18 -> V_155 , 0 , sizeof( V_18 -> V_155 ) ) ;
V_18 -> V_45 -> V_156 = NULL ;
V_18 -> V_123 = 0 ;
if ( V_151 ) {
V_18 -> V_155 . V_162 = F_66 ( unsigned , V_163 ,
V_151 ) ;
F_67 ( & V_149 -> V_164 , V_18 -> V_91 ,
V_18 -> V_155 . V_162 ) ;
V_18 -> V_155 . V_165 . V_166 = & V_149 -> V_164 ;
V_18 -> V_154 = V_167 ;
V_18 -> V_155 . V_165 . V_168 = V_18 -> V_155 . V_165 . V_169 = 1 ;
V_18 -> V_86 [ 0 ] = V_170 ;
V_18 -> V_86 [ 4 ] = V_18 -> V_155 . V_162 ;
V_18 -> V_152 = F_68 ( V_18 -> V_86 [ 0 ] ) ;
} else {
V_18 -> V_154 = V_171 ;
if ( V_86 ) {
F_23 ( V_150 > V_161 ) ;
memcpy ( V_18 -> V_86 , V_86 , V_150 ) ;
V_18 -> V_152 = F_68 ( V_18 -> V_86 [ 0 ] ) ;
}
}
V_18 -> V_157 = 0 ;
if ( V_21 -> V_172 <= V_173 && V_21 -> V_172 != V_174 )
V_18 -> V_86 [ 1 ] = ( V_18 -> V_86 [ 1 ] & 0x1f ) |
( V_21 -> V_175 << 5 & 0xe0 ) ;
memset ( V_18 -> V_91 , 0 , V_163 ) ;
}
void F_69 ( struct V_17 * V_18 , struct V_148 * V_149 )
{
V_18 -> V_152 = V_149 -> V_152 ;
V_18 -> V_86 = V_149 -> V_86 ;
V_18 -> V_154 = V_149 -> V_153 ;
V_18 -> V_155 = V_149 -> V_155 ;
V_18 -> V_45 -> V_156 = V_149 -> V_156 ;
V_18 -> V_123 = V_149 -> V_123 ;
V_18 -> V_157 = V_149 -> V_157 ;
V_18 -> V_158 = V_149 -> V_158 ;
}
static int F_70 ( struct V_17 * V_18 , unsigned char * V_86 ,
int V_150 , int V_176 , unsigned V_151 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_24 ;
F_71 ( V_177 ) ;
unsigned long V_178 = V_176 ;
struct V_148 V_149 ;
const unsigned long V_179 = F_72 ( 100 ) ;
int V_23 ;
V_180:
F_65 ( V_18 , & V_149 , V_86 , V_150 , V_151 ) ;
V_2 -> V_137 = & V_177 ;
F_73 ( V_18 ) ;
V_18 -> V_88 = V_89 ;
V_23 = V_2 -> V_25 -> V_181 ( V_2 , V_18 ) ;
if ( V_23 ) {
if ( V_178 > V_179 ) {
F_69 ( V_18 , & V_149 ) ;
V_178 -= V_179 ;
F_74 ( F_75 ( V_179 ) ) ;
goto V_180;
}
V_178 = 0 ;
V_23 = V_35 ;
} else {
V_178 = F_76 ( & V_177 , V_176 ) ;
V_23 = V_26 ;
}
V_2 -> V_137 = NULL ;
F_30 ( V_18 , V_23 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_35 ,
V_55 , V_178 ) ) ;
if ( V_178 ) {
V_23 = F_49 ( V_18 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_36 , V_55 , V_23 ) ) ;
switch ( V_23 ) {
case V_26 :
case V_81 :
case V_35 :
break;
case V_110 :
V_23 = V_81 ;
break;
default:
V_23 = V_35 ;
break;
}
} else if ( V_23 != V_35 ) {
F_64 ( V_18 ) ;
V_23 = V_35 ;
}
F_69 ( V_18 , & V_149 ) ;
return V_23 ;
}
static int F_77 ( struct V_17 * V_18 )
{
return F_70 ( V_18 , NULL , 0 , V_18 -> V_22 -> V_182 , ~ 0 ) ;
}
static int F_78 ( struct V_17 * V_18 , int V_23 )
{
if ( ! F_79 ( V_18 -> V_45 ) ) {
struct V_183 * V_184 = F_80 ( V_18 ) ;
if ( V_184 -> V_137 )
V_23 = V_184 -> V_137 ( V_18 , V_23 ) ;
}
return V_23 ;
}
void F_81 ( struct V_17 * V_18 , struct V_56 * V_185 )
{
V_18 -> V_33 = 0 ;
F_82 ( & V_18 -> V_42 , V_185 ) ;
}
int F_83 ( struct V_56 * V_57 ,
struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_186 ;
struct V_1 * V_2 ;
int V_23 ;
F_84 (scmd, next, work_q, eh_entry) {
if ( ( V_18 -> V_33 & V_41 ) ||
( V_18 -> V_33 & V_34 ) ||
F_85 ( V_18 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_37 ,
V_187 -> V_188 ) ) ;
break;
}
if ( F_52 ( V_18 -> V_123 ) != V_129 )
continue;
F_5 ( 2 , F_15 ( V_6 , V_18 ,
L_38 ,
V_187 -> V_188 ) ) ;
V_23 = F_77 ( V_18 ) ;
if ( V_23 != V_26 )
continue;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_39 , V_18 -> V_123 ) ) ;
F_5 ( 3 , F_86 ( V_18 ) ) ;
V_23 = F_87 ( V_18 ) ;
if ( V_23 == V_26 )
V_18 -> V_28 = V_18 -> V_29 ;
else if ( V_23 != V_81 )
continue;
F_81 ( V_18 , V_185 ) ;
}
return F_88 ( V_57 ) ;
}
static int F_89 ( struct V_17 * V_18 )
{
static unsigned char V_189 [ 6 ] = { V_87 , 0 , 0 , 0 , 0 , 0 } ;
int V_190 = 1 , V_23 ;
V_191:
V_23 = F_70 ( V_18 , V_189 , 6 ,
V_18 -> V_22 -> V_182 , 0 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_40 , V_55 , V_23 ) ) ;
switch ( V_23 ) {
case V_81 :
if ( V_190 -- )
goto V_191;
case V_26 :
return 0 ;
default:
return 1 ;
}
}
static int F_90 ( struct V_56 * V_192 ,
struct V_56 * V_57 ,
struct V_56 * V_185 , int V_193 )
{
struct V_17 * V_18 , * V_186 ;
struct V_20 * V_21 ;
int V_194 ;
while ( ! F_88 ( V_192 ) ) {
V_18 = F_91 ( V_192 -> V_186 , struct V_17 , V_42 ) ;
V_21 = V_18 -> V_22 ;
if ( ! V_193 ) {
if ( F_11 ( V_21 -> V_24 ) ) {
F_92 ( V_192 , V_57 ) ;
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_41 ,
V_187 -> V_188 ) ) ;
break;
}
}
V_194 = ! F_33 ( V_18 -> V_22 ) ||
( V_193 && ! F_93 ( V_18 ) &&
! F_89 ( V_18 ) ) ||
! F_89 ( V_18 ) ;
F_84 (scmd, next, cmd_list, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
if ( V_194 &&
( V_193 ||
F_78 ( V_18 , V_26 ) == V_26 ) )
F_81 ( V_18 , V_185 ) ;
else
F_82 ( & V_18 -> V_42 , V_57 ) ;
}
}
return F_88 ( V_57 ) ;
}
static int F_94 ( struct V_56 * V_57 ,
struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_186 ;
F_95 ( V_195 ) ;
int V_23 ;
struct V_1 * V_2 ;
F_84 (scmd, next, work_q, eh_entry) {
if ( ! ( V_18 -> V_33 & V_41 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_92 ( & V_195 , V_57 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_42 ,
V_187 -> V_188 ) ) ;
return F_88 ( V_57 ) ;
}
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_43 , V_187 -> V_188 ) ) ;
V_23 = F_16 ( V_2 -> V_25 , V_18 ) ;
if ( V_23 == V_35 ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_44 ,
V_187 -> V_188 ) ) ;
F_92 ( & V_195 , V_57 ) ;
return F_88 ( V_57 ) ;
}
V_18 -> V_33 &= ~ V_41 ;
if ( V_23 == V_32 )
F_81 ( V_18 , V_185 ) ;
else
F_82 ( & V_18 -> V_42 , & V_195 ) ;
}
return F_90 ( & V_195 , V_57 , V_185 , 0 ) ;
}
static int F_93 ( struct V_17 * V_18 )
{
static unsigned char V_196 [ 6 ] = { V_197 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_18 -> V_22 -> V_98 ) {
int V_198 , V_23 = V_81 ;
for ( V_198 = 0 ; V_23 == V_81 && V_198 < 2 ; V_198 ++ )
V_23 = F_70 ( V_18 , V_196 , 6 , V_18 -> V_22 -> V_199 -> V_200 , 0 ) ;
if ( V_23 == V_26 )
return 0 ;
}
return 1 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_201 , * V_186 ;
struct V_20 * V_21 ;
F_36 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_45 ,
V_187 -> V_188 ) ) ;
break;
}
V_201 = NULL ;
F_37 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 && F_85 ( V_18 ) &&
F_42 ( V_18 ) == V_35 ) {
V_201 = V_18 ;
break;
}
if ( ! V_201 )
continue;
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_46 ,
V_187 -> V_188 ) ) ;
if ( ! F_93 ( V_201 ) ) {
if ( ! F_33 ( V_21 ) ||
! F_89 ( V_201 ) ) {
F_84 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_78 ( V_18 , V_26 ) == V_26 )
F_81 ( V_18 , V_185 ) ;
}
}
} else {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_47 ,
V_187 -> V_188 ) ) ;
}
}
return F_88 ( V_57 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_202 , * V_186 ;
struct V_20 * V_21 ;
int V_23 ;
F_36 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_48 ,
V_187 -> V_188 ) ) ;
break;
}
V_202 = NULL ;
F_37 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
V_202 = V_18 ;
break;
}
if ( ! V_202 )
continue;
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_49 , V_187 -> V_188 ) ) ;
V_23 = F_63 ( V_202 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
if ( ! F_33 ( V_21 ) ||
V_23 == V_32 ||
! F_89 ( V_202 ) ) {
F_84 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_78 ( V_18 , V_23 ) != V_35 )
F_81 ( V_18 ,
V_185 ) ;
}
}
} else {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_50 , V_187 -> V_188 ) ) ;
}
}
return F_88 ( V_57 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_185 )
{
F_95 ( V_203 ) ;
F_95 ( V_195 ) ;
F_92 ( V_57 , & V_203 ) ;
while ( ! F_88 ( & V_203 ) ) {
struct V_17 * V_186 , * V_18 ;
int V_23 ;
unsigned int V_122 ;
if ( F_11 ( V_2 ) ) {
F_92 ( & V_195 , V_57 ) ;
F_92 ( & V_203 , V_57 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_51 ,
V_187 -> V_188 ) ) ;
return F_88 ( V_57 ) ;
}
V_18 = F_91 ( V_203 . V_186 , struct V_17 , V_42 ) ;
V_122 = F_99 ( V_18 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_52 ,
V_187 -> V_188 , V_122 ) ) ;
V_23 = F_60 ( V_18 ) ;
if ( V_23 != V_26 && V_23 != V_32 )
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_53
L_54 ,
V_187 -> V_188 , V_122 ) ) ;
F_84 (scmd, next, &tmp_list, eh_entry) {
if ( F_99 ( V_18 ) != V_122 )
continue;
if ( V_23 == V_26 )
F_82 ( & V_18 -> V_42 , & V_195 ) ;
else if ( V_23 == V_32 )
F_81 ( V_18 , V_185 ) ;
else
F_100 ( & V_18 -> V_42 , V_57 ) ;
}
}
return F_90 ( & V_195 , V_57 , V_185 , 0 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_204 , * V_186 ;
F_95 ( V_195 ) ;
unsigned int V_121 ;
int V_23 ;
for ( V_121 = 0 ; V_121 <= V_2 -> V_205 ; V_121 ++ ) {
if ( F_11 ( V_2 ) ) {
F_92 ( & V_195 , V_57 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_55 ,
V_187 -> V_188 ) ) ;
return F_88 ( V_57 ) ;
}
V_204 = NULL ;
F_37 (scmd, work_q, eh_entry) {
if ( V_121 == F_57 ( V_18 ) ) {
V_204 = V_18 ;
break;
}
}
if ( ! V_204 )
continue;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_56 ,
V_187 -> V_188 , V_121 ) ) ;
V_23 = F_58 ( V_204 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
F_84 (scmd, next, work_q, eh_entry) {
if ( V_121 == F_57 ( V_18 ) ) {
if ( V_23 == V_32 )
F_81 ( V_18 ,
V_185 ) ;
else
F_82 ( & V_18 -> V_42 ,
& V_195 ) ;
}
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_57 ,
V_187 -> V_188 , V_121 ) ) ;
}
}
return F_90 ( & V_195 , V_57 , V_185 , 0 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_186 ;
F_95 ( V_195 ) ;
int V_23 ;
if ( ! F_88 ( V_57 ) ) {
V_18 = F_91 ( V_57 -> V_186 ,
struct V_17 , V_42 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_58 ,
V_187 -> V_188 ) ) ;
V_23 = F_54 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_92 ( V_57 , & V_195 ) ;
} else if ( V_23 == V_32 ) {
F_84 (scmd, next, work_q, eh_entry) {
F_81 ( V_18 , V_185 ) ;
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_59 ,
V_187 -> V_188 ) ) ;
}
}
return F_90 ( & V_195 , V_57 , V_185 , 1 ) ;
}
static void F_103 ( struct V_56 * V_57 ,
struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_186 ;
F_84 (scmd, next, work_q, eh_entry) {
F_34 ( V_6 , V_18 -> V_22 , L_60
L_61 ) ;
F_104 ( V_18 -> V_22 , V_206 ) ;
if ( V_18 -> V_33 & V_41 ) {
}
F_81 ( V_18 , V_185 ) ;
}
return;
}
int F_18 ( struct V_17 * V_18 )
{
switch ( F_50 ( V_18 -> V_123 ) ) {
case V_125 :
break;
case V_27 :
goto V_207;
case V_208 :
return ( V_18 -> V_45 -> V_209 & V_210 ) ;
case V_211 :
return ( V_18 -> V_45 -> V_209 & V_212 ) ;
case V_213 :
if ( F_51 ( V_18 -> V_123 ) == V_126 &&
F_52 ( V_18 -> V_123 ) == V_133 )
return 0 ;
case V_214 :
return ( V_18 -> V_45 -> V_209 & V_215 ) ;
}
if ( F_52 ( V_18 -> V_123 ) != V_129 )
return 0 ;
V_207:
if ( V_18 -> V_45 -> V_209 & V_212 ||
F_79 ( V_18 -> V_45 ) )
return 1 ;
else
return 0 ;
}
int F_87 ( struct V_17 * V_18 )
{
int V_23 ;
if ( ! F_33 ( V_18 -> V_22 ) ) {
F_5 ( 5 , F_15 ( V_6 , V_18 ,
L_62 , V_55 ) ) ;
return V_26 ;
}
switch ( F_50 ( V_18 -> V_123 ) ) {
case V_216 :
V_18 -> V_123 &= 0xff00ffff ;
return V_26 ;
case V_125 :
break;
case V_217 :
if ( V_18 -> V_33 & V_34 ) {
F_17 ( V_18 , V_27 ) ;
return V_26 ;
}
case V_218 :
case V_219 :
return V_26 ;
case V_214 :
goto V_220;
case V_221 :
return V_81 ;
case V_222 :
return V_110 ;
case V_223 :
goto V_220;
case V_224 :
return V_26 ;
case V_213 :
if ( F_51 ( V_18 -> V_123 ) == V_126 &&
F_52 ( V_18 -> V_123 ) == V_133 )
break;
case V_208 :
case V_211 :
goto V_220;
case V_27 :
if ( ( V_18 -> V_86 [ 0 ] == V_87 ||
V_18 -> V_86 [ 0 ] == V_225 ) ) {
return V_26 ;
} else {
return V_35 ;
}
case V_124 :
return V_26 ;
default:
return V_35 ;
}
if ( F_51 ( V_18 -> V_123 ) != V_126 )
return V_35 ;
switch ( F_52 ( V_18 -> V_123 ) ) {
case V_134 :
F_47 ( V_18 -> V_22 ) ;
case V_135 :
return V_110 ;
case V_127 :
if ( V_18 -> V_86 [ 0 ] == V_226 )
V_18 -> V_22 -> V_62 -> V_63 = 0 ;
F_45 ( V_18 -> V_22 ) ;
case V_128 :
return V_26 ;
case V_227 :
goto V_220;
case V_129 :
V_23 = F_42 ( V_18 ) ;
if ( V_23 == V_81 )
goto V_220;
return V_23 ;
case V_130 :
case V_131 :
case V_132 :
case V_228 :
return V_26 ;
case V_133 :
F_34 ( V_6 , V_18 -> V_22 ,
L_63 ) ;
F_17 ( V_18 , V_229 ) ;
return V_26 ;
default:
return V_35 ;
}
return V_35 ;
V_220:
if ( ( ++ V_18 -> V_28 ) <= V_18 -> V_29
&& ! F_18 ( V_18 ) ) {
return V_81 ;
} else {
return V_26 ;
}
}
static void F_105 ( struct V_45 * V_46 , int V_230 )
{
F_106 ( V_46 -> V_231 , V_46 ) ;
}
static void F_107 ( struct V_20 * V_21 )
{
struct V_45 * V_46 ;
struct V_232 * V_233 ;
V_46 = F_108 ( V_21 -> V_199 , V_234 , V_235 ) ;
if ( F_109 ( V_46 ) )
return;
V_233 = F_110 ( V_46 ) ;
F_111 ( V_46 ) ;
V_233 -> V_236 [ 0 ] = V_237 ;
V_233 -> V_236 [ 1 ] = 0 ;
V_233 -> V_236 [ 2 ] = 0 ;
V_233 -> V_236 [ 3 ] = 0 ;
V_233 -> V_236 [ 4 ] = V_238 ;
V_233 -> V_236 [ 5 ] = 0 ;
V_233 -> V_152 = F_68 ( V_233 -> V_236 [ 0 ] ) ;
V_46 -> V_239 |= V_240 ;
V_46 -> V_176 = 10 * V_37 ;
V_46 -> V_28 = 5 ;
F_112 ( V_46 -> V_231 , NULL , V_46 , 1 , F_105 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned long V_7 ;
F_36 (sdev, shost) {
if ( F_33 ( V_21 ) && V_21 -> V_144 && V_21 -> V_241 ) {
F_107 ( V_21 ) ;
V_21 -> V_144 = 0 ;
}
}
F_5 ( 3 ,
F_6 ( V_6 , V_2 , L_64 ) ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_242 ) )
if ( F_9 ( V_2 , V_243 ) )
F_23 ( F_9 ( V_2 , V_244 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_114 ( & V_2 -> V_54 ) ;
F_115 ( V_2 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_11 )
if ( F_9 ( V_2 , V_9 ) )
F_116 ( F_9 ( V_2 , V_10 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
}
void F_117 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_56 * V_185 )
{
if ( ! F_96 ( V_2 , V_57 , V_185 ) )
if ( ! F_97 ( V_2 , V_57 , V_185 ) )
if ( ! F_98 ( V_2 , V_57 , V_185 ) )
if ( ! F_101 ( V_2 , V_57 , V_185 ) )
if ( ! F_102 ( V_2 , V_57 , V_185 ) )
F_103 ( V_57 ,
V_185 ) ;
}
void F_118 ( struct V_56 * V_185 )
{
struct V_17 * V_18 , * V_186 ;
F_84 (scmd, next, done_q, eh_entry) {
F_119 ( & V_18 -> V_42 ) ;
if ( F_33 ( V_18 -> V_22 ) &&
! F_18 ( V_18 ) &&
( ++ V_18 -> V_28 <= V_18 -> V_29 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_65 ,
V_187 -> V_188 ) ) ;
F_19 ( V_18 , V_31 ) ;
} else {
if ( ! V_18 -> V_123 )
V_18 -> V_123 |= ( V_245 << 24 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_66 ,
V_187 -> V_188 ) ) ;
F_20 ( V_18 ) ;
}
}
}
static void F_120 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_95 ( V_246 ) ;
F_95 ( V_247 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
F_92 ( & V_2 -> V_43 , & V_246 ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 1 , F_35 ( V_2 , & V_246 ) ) ;
if ( ! F_83 ( & V_246 , & V_247 ) )
if ( ! F_94 ( & V_246 , & V_247 ) )
F_117 ( V_2 , & V_246 , & V_247 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_13 != - 1 )
V_2 -> V_12 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_118 ( & V_247 ) ;
}
int F_121 ( void * V_143 )
{
struct V_1 * V_2 = V_143 ;
while ( true ) {
F_122 ( V_248 ) ;
if ( F_123 () )
break;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_11 == 0 ) ||
V_2 -> V_4 != F_2 ( & V_2 -> V_3 ) ) {
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_67 ,
V_2 -> V_249 ) ) ;
F_124 () ;
continue;
}
F_125 ( V_250 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_68 ,
V_2 -> V_249 , V_2 -> V_11 ,
V_2 -> V_4 ,
F_2 ( & V_2 -> V_3 ) ) ) ;
if ( ! V_2 -> V_251 && F_126 ( V_2 ) != 0 ) {
F_5 ( 1 ,
F_6 ( V_252 , V_2 ,
L_69 ,
V_2 -> V_249 ) ) ;
continue;
}
if ( V_2 -> V_253 -> V_254 )
V_2 -> V_253 -> V_254 ( V_2 ) ;
else
F_120 ( V_2 ) ;
V_2 -> V_4 = 0 ;
F_113 ( V_2 ) ;
if ( ! V_2 -> V_251 )
F_127 ( V_2 ) ;
}
F_125 ( V_250 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_70 ,
V_2 -> V_249 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 , int V_121 )
{
struct V_20 * V_21 ;
F_128 (sdev, shost) {
if ( V_121 == F_129 ( V_21 ) )
F_59 ( V_21 , NULL ) ;
}
}
void F_130 ( struct V_1 * V_2 , int V_121 , int V_255 )
{
struct V_20 * V_21 ;
F_128 (sdev, shost) {
if ( V_121 == F_129 ( V_21 ) &&
V_255 == F_131 ( V_21 ) )
F_59 ( V_21 , NULL ) ;
}
}
static void
F_132 ( struct V_17 * V_18 )
{
}
int
F_133 ( struct V_20 * V_256 , int T_1 * V_257 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = V_256 -> V_24 ;
struct V_45 * V_233 ;
unsigned long V_7 ;
int error = 0 , V_23 , V_258 ;
if ( ! F_134 ( V_259 ) || ! F_134 ( V_260 ) )
return - V_261 ;
error = F_135 ( V_258 , V_257 ) ;
if ( error )
return error ;
if ( F_126 ( V_2 ) < 0 )
return - V_262 ;
error = - V_262 ;
V_233 = F_136 ( sizeof( struct V_45 ) + sizeof( struct V_17 ) +
V_2 -> V_25 -> V_263 , V_235 ) ;
if ( ! V_233 )
goto V_264;
F_137 ( NULL , V_233 ) ;
V_18 = (struct V_17 * ) ( V_233 + 1 ) ;
F_138 ( V_256 , V_18 ) ;
V_18 -> V_45 = V_233 ;
V_18 -> V_86 = F_110 ( V_233 ) -> V_236 ;
V_18 -> V_88 = F_132 ;
memset ( & V_18 -> V_155 , 0 , sizeof( V_18 -> V_155 ) ) ;
V_18 -> V_152 = 0 ;
V_18 -> V_154 = V_265 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_266 = 1 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
switch ( V_258 & ~ V_267 ) {
case V_268 :
V_23 = V_26 ;
break;
case V_269 :
V_23 = F_63 ( V_18 ) ;
if ( V_23 == V_26 || ( V_258 & V_267 ) )
break;
case V_270 :
V_23 = F_60 ( V_18 ) ;
if ( V_23 == V_26 || ( V_258 & V_267 ) )
break;
case V_271 :
V_23 = F_58 ( V_18 ) ;
if ( V_23 == V_26 || ( V_258 & V_267 ) )
break;
case V_272 :
V_23 = F_54 ( V_18 ) ;
if ( V_23 == V_26 )
break;
default:
V_23 = V_35 ;
break;
}
error = ( V_23 == V_26 ) ? 0 : - V_262 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_266 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_71 ) ) ;
F_114 ( & V_2 -> V_54 ) ;
F_115 ( V_2 ) ;
F_139 ( V_18 ) ;
F_140 ( V_233 ) ;
V_264:
F_127 ( V_2 ) ;
return error ;
}
bool F_43 ( const struct V_17 * V_236 ,
struct V_64 * V_65 )
{
return F_141 ( V_236 -> V_91 ,
V_163 , V_65 ) ;
}
int F_142 ( const T_2 * V_91 , int V_273 ,
T_3 * V_274 )
{
int V_275 ;
const T_2 * V_276 ;
T_3 V_277 ;
if ( V_273 < 7 )
return 0 ;
switch ( V_91 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_91 [ 0 ] & 0x80 ) {
* V_274 = ( V_91 [ 3 ] << 24 ) +
( V_91 [ 4 ] << 16 ) +
( V_91 [ 5 ] << 8 ) + V_91 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_276 = F_143 ( V_91 , V_273 ,
0 ) ;
if ( V_276 && ( 0xa == V_276 [ 1 ] ) ) {
V_277 = 0 ;
for ( V_275 = 0 ; V_275 < 8 ; ++ V_275 ) {
if ( V_275 > 0 )
V_277 <<= 8 ;
V_277 |= V_276 [ 4 + V_275 ] ;
}
* V_274 = V_277 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
