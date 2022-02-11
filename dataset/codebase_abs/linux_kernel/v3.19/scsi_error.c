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
L_10 , V_18 ,
( V_23 == V_32 ) ?
L_11 : L_12 ) ) ;
}
}
if ( ! F_21 ( V_18 , 0 ) ) {
F_5 ( 3 ,
F_15 ( V_30 , V_18 ,
L_13
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
if ( V_18 -> V_33 & V_34 ) {
V_18 -> V_33 &= ~ V_34 ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_14 , V_18 ) ) ;
F_23 ( F_24 ( & V_18 -> V_19 ) ) ;
return V_35 ;
}
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_25 ( V_2 ) ) {
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_15 ,
V_18 ) ) ;
return V_35 ;
}
if ( V_2 -> V_13 != - 1 && ! V_2 -> V_12 )
V_2 -> V_12 = V_14 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
V_18 -> V_33 |= V_34 ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_16 , V_18 ) ) ;
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
if ( V_24 -> V_50 -> V_51 )
V_23 = V_24 -> V_50 -> V_51 ( V_18 ) ;
else if ( V_24 -> V_25 -> V_51 )
V_23 = V_24 -> V_25 -> V_51 ( V_18 ) ;
if ( V_23 == V_48 ) {
if ( ! V_24 -> V_25 -> V_52 &&
F_22 ( V_18 ) == V_26 )
return V_48 ;
F_17 ( V_18 , V_27 ) ;
if ( ! F_21 ( V_18 , V_41 ) )
V_23 = V_53 ;
}
return V_23 ;
}
int F_31 ( struct V_20 * V_21 )
{
int V_54 ;
F_32 ( V_21 -> V_24 -> V_55 , ! F_25 ( V_21 -> V_24 ) ) ;
V_54 = F_33 ( V_21 ) ;
F_5 ( 5 , F_34 ( V_6 , V_21 ,
L_17 , V_56 , V_54 ) ) ;
return V_54 ;
}
static inline void F_35 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_59 = 0 ;
int V_60 = 0 ;
int V_61 = 0 ;
int V_62 = 0 ;
F_36 (sdev, shost) {
F_37 (scmd, work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 ) {
++ V_59 ;
if ( V_18 -> V_33 & V_41 )
++ V_61 ;
else
++ V_60 ;
}
}
if ( V_61 || V_60 ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_18 ,
V_56 , V_60 ,
V_61 ) ) ;
V_61 = 0 ;
V_60 = 0 ;
++ V_62 ;
}
}
F_5 ( 2 , F_6 ( V_6 , V_2 ,
L_19
L_20 ,
V_59 , V_62 ) ) ;
}
static void F_38 ( struct V_20 * V_21 )
{
V_21 -> V_63 -> V_64 = 1 ;
}
static void F_39 ( struct V_20 * V_21 ,
struct V_65 * V_66 )
{
enum V_67 V_68 = V_69 ;
if ( V_66 -> V_70 == V_71 ) {
if ( V_66 -> V_72 == 0x3f && V_66 -> V_73 == 0x03 ) {
V_68 = V_74 ;
F_34 ( V_30 , V_21 ,
L_21 ) ;
} else if ( V_66 -> V_72 == 0x3f && V_66 -> V_73 == 0x0e ) {
V_68 = V_75 ;
F_38 ( V_21 ) ;
F_34 ( V_30 , V_21 ,
L_22
L_23
L_24
L_25 ) ;
} else if ( V_66 -> V_72 == 0x3f )
F_34 ( V_30 , V_21 ,
L_22
L_26
L_24
L_27 ) ;
if ( V_66 -> V_72 == 0x38 && V_66 -> V_73 == 0x07 ) {
V_68 = V_76 ;
F_34 ( V_30 , V_21 ,
L_22
L_28
L_29 ) ;
}
if ( V_66 -> V_72 == 0x2a && V_66 -> V_73 == 0x01 ) {
V_68 = V_77 ;
F_34 ( V_30 , V_21 ,
L_30 ) ;
} else if ( V_66 -> V_72 == 0x2a && V_66 -> V_73 == 0x09 ) {
V_68 = V_78 ;
F_34 ( V_30 , V_21 ,
L_31 ) ;
} else if ( V_66 -> V_72 == 0x2a )
F_34 ( V_30 , V_21 ,
L_32 ) ;
}
if ( V_68 != V_69 ) {
F_40 ( V_68 , V_21 -> V_79 ) ;
F_41 ( & V_21 -> V_80 ) ;
}
}
static int F_42 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_65 V_66 ;
if ( ! F_43 ( V_18 , & V_66 ) )
return V_35 ;
F_39 ( V_21 , & V_66 ) ;
if ( F_44 ( & V_66 ) )
return V_81 ;
if ( V_21 -> V_82 && V_21 -> V_82 -> V_83 &&
V_21 -> V_82 -> V_83 -> V_84 ) {
int V_85 ;
V_85 = V_21 -> V_82 -> V_83 -> V_84 ( V_21 , & V_66 ) ;
if ( V_85 != V_86 )
return V_85 ;
}
if ( V_18 -> V_87 [ 0 ] == V_88 && V_18 -> V_89 != V_90 )
return V_26 ;
if ( V_66 . V_91 == 0x70 ) {
if ( V_18 -> V_92 [ 2 ] & 0xe0 )
return V_26 ;
} else {
if ( ( V_66 . V_93 > 3 ) &&
( V_18 -> V_92 [ 8 ] == 0x4 ) &&
( V_18 -> V_92 [ 11 ] & 0xe0 ) )
return V_26 ;
}
switch ( V_66 . V_70 ) {
case V_94 :
return V_26 ;
case V_95 :
return V_26 ;
case V_96 :
if ( V_66 . V_72 == 0x10 )
return V_26 ;
return V_81 ;
case V_97 :
case V_71 :
if ( V_18 -> V_22 -> V_98 ) {
if ( V_66 . V_72 != 0x28 || V_66 . V_73 != 0x00 ) {
V_18 -> V_22 -> V_98 = 0 ;
return V_81 ;
}
}
if ( V_18 -> V_22 -> V_63 -> V_64 &&
V_66 . V_72 == 0x3f && V_66 . V_73 == 0x0e )
return V_81 ;
if ( ( V_66 . V_72 == 0x04 ) && ( V_66 . V_73 == 0x01 ) )
return V_81 ;
if ( V_18 -> V_22 -> V_99 &&
( V_66 . V_72 == 0x04 ) && ( V_66 . V_73 == 0x02 ) )
return V_35 ;
return V_26 ;
case V_100 :
if ( V_66 . V_72 == 0x27 && V_66 . V_73 == 0x07 ) {
F_17 ( V_18 , V_101 ) ;
return V_26 ;
}
case V_102 :
case V_103 :
case V_104 :
case V_105 :
F_17 ( V_18 , V_106 ) ;
return V_26 ;
case V_107 :
if ( V_66 . V_72 == 0x11 ||
V_66 . V_72 == 0x13 ||
V_66 . V_72 == 0x14 ) {
F_17 ( V_18 , V_108 ) ;
return V_26 ;
}
return V_81 ;
case V_109 :
if ( V_18 -> V_22 -> V_110 )
return V_111 ;
else
F_17 ( V_18 , V_106 ) ;
case V_112 :
if ( V_66 . V_72 == 0x20 ||
V_66 . V_72 == 0x21 ||
V_66 . V_72 == 0x24 ||
V_66 . V_72 == 0x26 ) {
F_17 ( V_18 , V_106 ) ;
}
return V_26 ;
default:
return V_26 ;
}
}
static void F_45 ( struct V_20 * V_21 )
{
struct V_113 * V_114 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_115 ;
if ( ! V_114 -> V_116 ||
V_21 -> V_117 >= V_21 -> V_118 )
return;
if ( F_12 ( V_14 ,
V_21 -> V_119 + V_21 -> V_120 ) )
return;
if ( F_12 ( V_14 ,
V_21 -> V_121 + V_21 -> V_120 ) )
return;
F_36 (tmp_sdev, sdev->host) {
if ( V_115 -> V_122 != V_21 -> V_122 ||
V_115 -> V_123 != V_21 -> V_123 ||
V_115 -> V_117 == V_21 -> V_118 )
continue;
F_46 ( V_115 , V_115 -> V_117 + 1 ) ;
V_21 -> V_119 = V_14 ;
}
}
static void F_47 ( struct V_20 * V_21 )
{
struct V_113 * V_114 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_115 ;
if ( ! V_114 -> V_116 )
return;
F_36 (tmp_sdev, sdev->host) {
if ( V_115 -> V_122 != V_21 -> V_122 ||
V_115 -> V_123 != V_21 -> V_123 )
continue;
F_48 ( V_115 , V_115 -> V_117 - 1 ) ;
}
}
static int F_49 ( struct V_17 * V_18 )
{
if ( F_50 ( V_18 -> V_124 ) == V_125 ) {
return F_42 ( V_18 ) ;
}
if ( F_50 ( V_18 -> V_124 ) != V_126 )
return V_35 ;
if ( F_51 ( V_18 -> V_124 ) != V_127 )
return V_35 ;
switch ( F_52 ( V_18 -> V_124 ) ) {
case V_128 :
F_45 ( V_18 -> V_22 ) ;
case V_129 :
return V_26 ;
case V_130 :
return F_42 ( V_18 ) ;
case V_131 :
case V_132 :
case V_133 :
return V_26 ;
case V_134 :
if ( V_18 -> V_87 [ 0 ] == V_88 )
return V_26 ;
return V_35 ;
case V_135 :
F_47 ( V_18 -> V_22 ) ;
case V_136 :
return V_81 ;
default:
return V_35 ;
}
return V_35 ;
}
static void V_90 ( struct V_17 * V_18 )
{
struct V_137 * V_138 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_33 ,
V_56 , V_18 , V_18 -> V_124 ) ) ;
V_138 = V_18 -> V_22 -> V_24 -> V_138 ;
if ( V_138 )
F_53 ( V_138 ) ;
}
static int F_54 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_113 * V_25 = V_24 -> V_25 ;
F_5 ( 3 ,
F_6 ( V_6 , V_24 , L_34 ) ) ;
if ( ! V_25 -> V_139 )
return V_35 ;
V_23 = V_25 -> V_139 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_140 )
F_55 ( V_141 ) ;
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
struct V_113 * V_25 = V_24 -> V_25 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_35 , V_56 ) ) ;
if ( ! V_25 -> V_142 )
return V_35 ;
V_23 = V_25 -> V_142 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_140 )
F_55 ( V_143 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_56 ( V_24 , F_57 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static void F_59 ( struct V_20 * V_21 , void * V_144 )
{
V_21 -> V_145 = 1 ;
V_21 -> V_98 = 1 ;
}
static int F_60 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_113 * V_25 = V_24 -> V_25 ;
if ( ! V_25 -> V_146 )
return V_35 ;
V_23 = V_25 -> V_146 ( V_18 ) ;
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
struct V_113 * V_25 = V_18 -> V_22 -> V_24 -> V_25 ;
if ( ! V_25 -> V_147 )
return V_35 ;
V_23 = V_25 -> V_147 ( V_18 ) ;
if ( V_23 == V_26 )
F_59 ( V_18 -> V_22 , NULL ) ;
return V_23 ;
}
static int F_16 ( struct V_113 * V_25 ,
struct V_17 * V_18 )
{
if ( ! V_25 -> V_148 )
return V_35 ;
return V_25 -> V_148 ( V_18 ) ;
}
static void F_64 ( struct V_17 * V_18 )
{
if ( F_16 ( V_18 -> V_22 -> V_24 -> V_25 , V_18 ) != V_26 )
if ( F_63 ( V_18 ) != V_26 )
if ( F_60 ( V_18 ) != V_26 )
if ( F_58 ( V_18 ) != V_26 )
F_54 ( V_18 ) ;
}
void F_65 ( struct V_17 * V_18 , struct V_149 * V_150 ,
unsigned char * V_87 , int V_151 , unsigned V_152 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
V_150 -> V_153 = V_18 -> V_153 ;
V_150 -> V_87 = V_18 -> V_87 ;
V_150 -> V_154 = V_18 -> V_155 ;
V_150 -> V_156 = V_18 -> V_156 ;
V_150 -> V_157 = V_18 -> V_45 -> V_157 ;
V_150 -> V_124 = V_18 -> V_124 ;
V_150 -> V_158 = V_18 -> V_158 ;
V_150 -> V_159 = V_18 -> V_159 ;
V_18 -> V_159 = V_160 ;
V_18 -> V_33 = 0 ;
V_18 -> V_87 = V_150 -> V_161 ;
memset ( V_18 -> V_87 , 0 , V_162 ) ;
memset ( & V_18 -> V_156 , 0 , sizeof( V_18 -> V_156 ) ) ;
V_18 -> V_45 -> V_157 = NULL ;
V_18 -> V_124 = 0 ;
if ( V_152 ) {
V_18 -> V_156 . V_163 = F_66 ( unsigned , V_164 ,
V_152 ) ;
F_67 ( & V_150 -> V_165 , V_18 -> V_92 ,
V_18 -> V_156 . V_163 ) ;
V_18 -> V_156 . V_166 . V_167 = & V_150 -> V_165 ;
V_18 -> V_155 = V_168 ;
V_18 -> V_156 . V_166 . V_169 = 1 ;
V_18 -> V_87 [ 0 ] = V_170 ;
V_18 -> V_87 [ 4 ] = V_18 -> V_156 . V_163 ;
V_18 -> V_153 = F_68 ( V_18 -> V_87 [ 0 ] ) ;
} else {
V_18 -> V_155 = V_171 ;
if ( V_87 ) {
F_23 ( V_151 > V_162 ) ;
memcpy ( V_18 -> V_87 , V_87 , V_151 ) ;
V_18 -> V_153 = F_68 ( V_18 -> V_87 [ 0 ] ) ;
}
}
V_18 -> V_158 = 0 ;
if ( V_21 -> V_172 <= V_173 && V_21 -> V_172 != V_174 )
V_18 -> V_87 [ 1 ] = ( V_18 -> V_87 [ 1 ] & 0x1f ) |
( V_21 -> V_175 << 5 & 0xe0 ) ;
memset ( V_18 -> V_92 , 0 , V_164 ) ;
}
void F_69 ( struct V_17 * V_18 , struct V_149 * V_150 )
{
V_18 -> V_153 = V_150 -> V_153 ;
V_18 -> V_87 = V_150 -> V_87 ;
V_18 -> V_155 = V_150 -> V_154 ;
V_18 -> V_156 = V_150 -> V_156 ;
V_18 -> V_45 -> V_157 = V_150 -> V_157 ;
V_18 -> V_124 = V_150 -> V_124 ;
V_18 -> V_158 = V_150 -> V_158 ;
V_18 -> V_159 = V_150 -> V_159 ;
}
static int F_70 ( struct V_17 * V_18 , unsigned char * V_87 ,
int V_151 , int V_176 , unsigned V_152 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_24 ;
F_71 ( V_177 ) ;
unsigned long V_178 = V_176 ;
struct V_149 V_150 ;
const unsigned long V_179 = F_72 ( 100 ) ;
int V_23 ;
V_180:
F_65 ( V_18 , & V_150 , V_87 , V_151 , V_152 ) ;
V_2 -> V_138 = & V_177 ;
F_73 ( V_18 ) ;
V_18 -> V_89 = V_90 ;
V_23 = V_2 -> V_25 -> V_181 ( V_2 , V_18 ) ;
if ( V_23 ) {
if ( V_178 > V_179 ) {
F_69 ( V_18 , & V_150 ) ;
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
V_2 -> V_138 = NULL ;
F_30 ( V_18 , V_23 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_36 ,
V_56 , V_18 , V_178 ) ) ;
if ( V_178 ) {
V_23 = F_49 ( V_18 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_37 , V_56 , V_23 ) ) ;
switch ( V_23 ) {
case V_26 :
case V_81 :
case V_35 :
break;
case V_111 :
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
F_69 ( V_18 , & V_150 ) ;
return V_23 ;
}
static int F_77 ( struct V_17 * V_18 )
{
return F_70 ( V_18 , NULL , 0 , V_18 -> V_22 -> V_182 , ~ 0 ) ;
}
static int F_78 ( struct V_17 * V_18 , int V_23 )
{
if ( V_18 -> V_45 -> V_183 != V_184 ) {
struct V_185 * V_186 = F_79 ( V_18 ) ;
if ( V_186 -> V_138 )
V_23 = V_186 -> V_138 ( V_18 , V_23 ) ;
}
return V_23 ;
}
void F_80 ( struct V_17 * V_18 , struct V_57 * V_187 )
{
V_18 -> V_22 -> V_24 -> V_4 -- ;
V_18 -> V_33 = 0 ;
F_81 ( & V_18 -> V_42 , V_187 ) ;
}
int F_82 ( struct V_57 * V_58 ,
struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_188 ;
struct V_1 * V_2 ;
int V_23 ;
F_83 (scmd, next, work_q, eh_entry) {
if ( ( V_18 -> V_33 & V_41 ) ||
F_84 ( V_18 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_38 ,
V_189 -> V_190 ) ) ;
break;
}
if ( F_52 ( V_18 -> V_124 ) != V_130 )
continue;
F_5 ( 2 , F_15 ( V_6 , V_18 ,
L_39 ,
V_189 -> V_190 ) ) ;
V_23 = F_77 ( V_18 ) ;
if ( V_23 != V_26 )
continue;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_40 ,
V_18 , V_18 -> V_124 ) ) ;
F_5 ( 3 , F_85 ( V_18 ) ) ;
V_23 = F_86 ( V_18 ) ;
if ( V_23 == V_26 )
V_18 -> V_28 = V_18 -> V_29 ;
else if ( V_23 != V_81 )
continue;
F_80 ( V_18 , V_187 ) ;
}
return F_87 ( V_58 ) ;
}
static int F_88 ( struct V_17 * V_18 )
{
static unsigned char V_191 [ 6 ] = { V_88 , 0 , 0 , 0 , 0 , 0 } ;
int V_192 = 1 , V_23 ;
V_193:
V_23 = F_70 ( V_18 , V_191 , 6 ,
V_18 -> V_22 -> V_182 , 0 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_41 , V_56 , V_18 , V_23 ) ) ;
switch ( V_23 ) {
case V_81 :
if ( V_192 -- )
goto V_193;
case V_26 :
return 0 ;
default:
return 1 ;
}
}
static int F_89 ( struct V_57 * V_194 ,
struct V_57 * V_58 ,
struct V_57 * V_187 , int V_195 )
{
struct V_17 * V_18 , * V_188 ;
struct V_20 * V_21 ;
int V_196 ;
while ( ! F_87 ( V_194 ) ) {
V_18 = F_90 ( V_194 -> V_188 , struct V_17 , V_42 ) ;
V_21 = V_18 -> V_22 ;
if ( ! V_195 ) {
if ( F_11 ( V_21 -> V_24 ) ) {
F_91 ( V_194 , V_58 ) ;
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_42 ,
V_189 -> V_190 ) ) ;
break;
}
}
V_196 = ! F_33 ( V_18 -> V_22 ) ||
( V_195 && ! F_92 ( V_18 ) &&
! F_88 ( V_18 ) ) ||
! F_88 ( V_18 ) ;
F_83 (scmd, next, cmd_list, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
if ( V_196 &&
( V_195 ||
F_78 ( V_18 , V_26 ) == V_26 ) )
F_80 ( V_18 , V_187 ) ;
else
F_81 ( & V_18 -> V_42 , V_58 ) ;
}
}
return F_87 ( V_58 ) ;
}
static int F_93 ( struct V_57 * V_58 ,
struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_188 ;
F_94 ( V_197 ) ;
int V_23 ;
struct V_1 * V_2 ;
F_83 (scmd, next, work_q, eh_entry) {
if ( ! ( V_18 -> V_33 & V_41 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_91 ( & V_197 , V_58 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_43 ,
V_189 -> V_190 ) ) ;
return F_87 ( V_58 ) ;
}
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_44 , V_189 -> V_190 ) ) ;
V_23 = F_16 ( V_2 -> V_25 , V_18 ) ;
if ( V_23 == V_35 ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_45 ,
V_189 -> V_190 ) ) ;
F_91 ( & V_197 , V_58 ) ;
return F_87 ( V_58 ) ;
}
V_18 -> V_33 &= ~ V_41 ;
if ( V_23 == V_32 )
F_80 ( V_18 , V_187 ) ;
else
F_81 ( & V_18 -> V_42 , & V_197 ) ;
}
return F_89 ( & V_197 , V_58 , V_187 , 0 ) ;
}
static int F_92 ( struct V_17 * V_18 )
{
static unsigned char V_198 [ 6 ] = { V_199 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_18 -> V_22 -> V_99 ) {
int V_200 , V_23 = V_81 ;
for ( V_200 = 0 ; V_23 == V_81 && V_200 < 2 ; V_200 ++ )
V_23 = F_70 ( V_18 , V_198 , 6 , V_18 -> V_22 -> V_201 -> V_202 , 0 ) ;
if ( V_23 == V_26 )
return 0 ;
}
return 1 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_203 , * V_188 ;
struct V_20 * V_21 ;
F_36 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_46 ,
V_189 -> V_190 ) ) ;
break;
}
V_203 = NULL ;
F_37 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 && F_84 ( V_18 ) &&
F_42 ( V_18 ) == V_35 ) {
V_203 = V_18 ;
break;
}
if ( ! V_203 )
continue;
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_47 ,
V_189 -> V_190 ) ) ;
if ( ! F_92 ( V_203 ) ) {
if ( ! F_33 ( V_21 ) ||
! F_88 ( V_203 ) ) {
F_83 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_78 ( V_18 , V_26 ) == V_26 )
F_80 ( V_18 , V_187 ) ;
}
}
} else {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_48 ,
V_189 -> V_190 ) ) ;
}
}
return F_87 ( V_58 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_204 , * V_188 ;
struct V_20 * V_21 ;
int V_23 ;
F_36 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_49 ,
V_189 -> V_190 ) ) ;
break;
}
V_204 = NULL ;
F_37 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
V_204 = V_18 ;
break;
}
if ( ! V_204 )
continue;
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_50 , V_189 -> V_190 ) ) ;
V_23 = F_63 ( V_204 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
if ( ! F_33 ( V_21 ) ||
V_23 == V_32 ||
! F_88 ( V_204 ) ) {
F_83 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_78 ( V_18 , V_23 ) != V_35 )
F_80 ( V_18 ,
V_187 ) ;
}
}
} else {
F_5 ( 3 ,
F_34 ( V_6 , V_21 ,
L_51 , V_189 -> V_190 ) ) ;
}
}
return F_87 ( V_58 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_187 )
{
F_94 ( V_205 ) ;
F_94 ( V_197 ) ;
F_91 ( V_58 , & V_205 ) ;
while ( ! F_87 ( & V_205 ) ) {
struct V_17 * V_188 , * V_18 ;
int V_23 ;
unsigned int V_123 ;
if ( F_11 ( V_2 ) ) {
F_91 ( & V_197 , V_58 ) ;
F_91 ( & V_205 , V_58 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_52 ,
V_189 -> V_190 ) ) ;
return F_87 ( V_58 ) ;
}
V_18 = F_90 ( V_205 . V_188 , struct V_17 , V_42 ) ;
V_123 = F_98 ( V_18 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_53 ,
V_189 -> V_190 , V_123 ) ) ;
V_23 = F_60 ( V_18 ) ;
if ( V_23 != V_26 && V_23 != V_32 )
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_54
L_55 ,
V_189 -> V_190 , V_123 ) ) ;
F_83 (scmd, next, &tmp_list, eh_entry) {
if ( F_98 ( V_18 ) != V_123 )
continue;
if ( V_23 == V_26 )
F_81 ( & V_18 -> V_42 , & V_197 ) ;
else if ( V_23 == V_32 )
F_80 ( V_18 , V_187 ) ;
else
F_99 ( & V_18 -> V_42 , V_58 ) ;
}
}
return F_89 ( & V_197 , V_58 , V_187 , 0 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_206 , * V_188 ;
F_94 ( V_197 ) ;
unsigned int V_122 ;
int V_23 ;
for ( V_122 = 0 ; V_122 <= V_2 -> V_207 ; V_122 ++ ) {
if ( F_11 ( V_2 ) ) {
F_91 ( & V_197 , V_58 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_56 ,
V_189 -> V_190 ) ) ;
return F_87 ( V_58 ) ;
}
V_206 = NULL ;
F_37 (scmd, work_q, eh_entry) {
if ( V_122 == F_57 ( V_18 ) ) {
V_206 = V_18 ;
break;
}
}
if ( ! V_206 )
continue;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_57 ,
V_189 -> V_190 , V_122 ) ) ;
V_23 = F_58 ( V_206 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
F_83 (scmd, next, work_q, eh_entry) {
if ( V_122 == F_57 ( V_18 ) ) {
if ( V_23 == V_32 )
F_80 ( V_18 ,
V_187 ) ;
else
F_81 ( & V_18 -> V_42 ,
& V_197 ) ;
}
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_58 ,
V_189 -> V_190 , V_122 ) ) ;
}
}
return F_89 ( & V_197 , V_58 , V_187 , 0 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_188 ;
F_94 ( V_197 ) ;
int V_23 ;
if ( ! F_87 ( V_58 ) ) {
V_18 = F_90 ( V_58 -> V_188 ,
struct V_17 , V_42 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_59 ,
V_189 -> V_190 ) ) ;
V_23 = F_54 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_91 ( V_58 , & V_197 ) ;
} else if ( V_23 == V_32 ) {
F_83 (scmd, next, work_q, eh_entry) {
F_80 ( V_18 , V_187 ) ;
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_60 ,
V_189 -> V_190 ) ) ;
}
}
return F_89 ( & V_197 , V_58 , V_187 , 1 ) ;
}
static void F_102 ( struct V_57 * V_58 ,
struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_188 ;
F_83 (scmd, next, work_q, eh_entry) {
F_34 ( V_6 , V_18 -> V_22 , L_61
L_62 ) ;
F_103 ( V_18 -> V_22 , V_208 ) ;
if ( V_18 -> V_33 & V_41 ) {
}
F_80 ( V_18 , V_187 ) ;
}
return;
}
int F_18 ( struct V_17 * V_18 )
{
switch ( F_50 ( V_18 -> V_124 ) ) {
case V_126 :
break;
case V_27 :
goto V_209;
case V_210 :
return ( V_18 -> V_45 -> V_211 & V_212 ) ;
case V_213 :
return ( V_18 -> V_45 -> V_211 & V_214 ) ;
case V_215 :
if ( F_51 ( V_18 -> V_124 ) == V_127 &&
F_52 ( V_18 -> V_124 ) == V_134 )
return 0 ;
case V_216 :
return ( V_18 -> V_45 -> V_211 & V_217 ) ;
}
if ( F_52 ( V_18 -> V_124 ) != V_130 )
return 0 ;
V_209:
if ( V_18 -> V_45 -> V_211 & V_214 ||
V_18 -> V_45 -> V_183 == V_184 )
return 1 ;
else
return 0 ;
}
int F_86 ( struct V_17 * V_18 )
{
int V_23 ;
if ( ! F_33 ( V_18 -> V_22 ) ) {
F_5 ( 5 , F_15 ( V_6 , V_18 ,
L_63 , V_56 ) ) ;
return V_26 ;
}
switch ( F_50 ( V_18 -> V_124 ) ) {
case V_218 :
V_18 -> V_124 &= 0xff00ffff ;
return V_26 ;
case V_126 :
break;
case V_219 :
if ( V_18 -> V_33 & V_34 ) {
F_17 ( V_18 , V_27 ) ;
return V_26 ;
}
case V_220 :
case V_221 :
return V_26 ;
case V_216 :
goto V_222;
case V_223 :
return V_81 ;
case V_224 :
return V_111 ;
case V_225 :
goto V_222;
case V_226 :
return V_26 ;
case V_215 :
if ( F_51 ( V_18 -> V_124 ) == V_127 &&
F_52 ( V_18 -> V_124 ) == V_134 )
break;
case V_210 :
case V_213 :
goto V_222;
case V_27 :
if ( ( V_18 -> V_87 [ 0 ] == V_88 ||
V_18 -> V_87 [ 0 ] == V_227 ) ) {
return V_26 ;
} else {
return V_35 ;
}
case V_125 :
return V_26 ;
default:
return V_35 ;
}
if ( F_51 ( V_18 -> V_124 ) != V_127 )
return V_35 ;
switch ( F_52 ( V_18 -> V_124 ) ) {
case V_135 :
F_47 ( V_18 -> V_22 ) ;
case V_136 :
return V_111 ;
case V_128 :
if ( V_18 -> V_87 [ 0 ] == V_228 )
V_18 -> V_22 -> V_63 -> V_64 = 0 ;
F_45 ( V_18 -> V_22 ) ;
case V_129 :
return V_26 ;
case V_229 :
goto V_222;
case V_130 :
V_23 = F_42 ( V_18 ) ;
if ( V_23 == V_81 )
goto V_222;
return V_23 ;
case V_131 :
case V_132 :
case V_133 :
case V_230 :
return V_26 ;
case V_134 :
F_34 ( V_6 , V_18 -> V_22 ,
L_64 ) ;
F_17 ( V_18 , V_231 ) ;
return V_26 ;
default:
return V_35 ;
}
return V_35 ;
V_222:
if ( ( ++ V_18 -> V_28 ) <= V_18 -> V_29
&& ! F_18 ( V_18 ) ) {
return V_81 ;
} else {
return V_26 ;
}
}
static void F_104 ( struct V_45 * V_46 , int V_232 )
{
F_105 ( V_46 -> V_233 , V_46 ) ;
}
static void F_106 ( struct V_20 * V_21 )
{
struct V_45 * V_46 ;
V_46 = F_107 ( V_21 -> V_201 , V_234 , V_235 ) ;
if ( F_108 ( V_46 ) )
return;
F_109 ( V_46 ) ;
V_46 -> V_236 [ 0 ] = V_237 ;
V_46 -> V_236 [ 1 ] = 0 ;
V_46 -> V_236 [ 2 ] = 0 ;
V_46 -> V_236 [ 3 ] = 0 ;
V_46 -> V_236 [ 4 ] = V_238 ;
V_46 -> V_236 [ 5 ] = 0 ;
V_46 -> V_153 = F_68 ( V_46 -> V_236 [ 0 ] ) ;
V_46 -> V_211 |= V_239 ;
V_46 -> V_176 = 10 * V_37 ;
V_46 -> V_28 = 5 ;
F_110 ( V_46 -> V_233 , NULL , V_46 , 1 , F_104 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned long V_7 ;
F_36 (sdev, shost) {
if ( F_33 ( V_21 ) && V_21 -> V_145 && V_21 -> V_240 ) {
F_106 ( V_21 ) ;
V_21 -> V_145 = 0 ;
}
}
F_5 ( 3 ,
F_6 ( V_6 , V_2 , L_65 ) ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_241 ) )
if ( F_9 ( V_2 , V_242 ) )
F_23 ( F_9 ( V_2 , V_243 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_112 ( & V_2 -> V_55 ) ;
F_113 ( V_2 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_11 )
if ( F_9 ( V_2 , V_9 ) )
F_114 ( F_9 ( V_2 , V_10 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
}
void F_115 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_187 )
{
if ( ! F_95 ( V_2 , V_58 , V_187 ) )
if ( ! F_96 ( V_2 , V_58 , V_187 ) )
if ( ! F_97 ( V_2 , V_58 , V_187 ) )
if ( ! F_100 ( V_2 , V_58 , V_187 ) )
if ( ! F_101 ( V_2 , V_58 , V_187 ) )
F_102 ( V_58 ,
V_187 ) ;
}
void F_116 ( struct V_57 * V_187 )
{
struct V_17 * V_18 , * V_188 ;
F_83 (scmd, next, done_q, eh_entry) {
F_117 ( & V_18 -> V_42 ) ;
if ( F_33 ( V_18 -> V_22 ) &&
! F_18 ( V_18 ) &&
( ++ V_18 -> V_28 <= V_18 -> V_29 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_66 ,
V_189 -> V_190 , V_18 ) ) ;
F_19 ( V_18 , V_31 ) ;
} else {
if ( ! V_18 -> V_124 )
V_18 -> V_124 |= ( V_244 << 24 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_67 ,
V_189 -> V_190 , V_18 ) ) ;
F_20 ( V_18 ) ;
}
}
}
static void F_118 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_94 ( V_245 ) ;
F_94 ( V_246 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
F_91 ( & V_2 -> V_43 , & V_245 ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 1 , F_35 ( V_2 , & V_245 ) ) ;
if ( ! F_82 ( & V_245 , & V_246 ) )
if ( ! F_93 ( & V_245 , & V_246 ) )
F_115 ( V_2 , & V_245 , & V_246 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_13 != - 1 )
V_2 -> V_12 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_116 ( & V_246 ) ;
}
int F_119 ( void * V_144 )
{
struct V_1 * V_2 = V_144 ;
while ( ! F_120 () ) {
F_121 ( V_247 ) ;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_11 == 0 ) ||
V_2 -> V_4 != F_2 ( & V_2 -> V_3 ) ) {
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_68 ,
V_2 -> V_248 ) ) ;
F_122 () ;
continue;
}
F_123 ( V_249 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_69 ,
V_2 -> V_248 , V_2 -> V_11 ,
V_2 -> V_4 ,
F_2 ( & V_2 -> V_3 ) ) ) ;
if ( ! V_2 -> V_250 && F_124 ( V_2 ) != 0 ) {
F_5 ( 1 ,
F_6 ( V_251 , V_2 ,
L_70 ,
V_2 -> V_248 ) ) ;
continue;
}
if ( V_2 -> V_50 -> V_252 )
V_2 -> V_50 -> V_252 ( V_2 ) ;
else
F_118 ( V_2 ) ;
F_111 ( V_2 ) ;
if ( ! V_2 -> V_250 )
F_125 ( V_2 ) ;
}
F_123 ( V_249 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_71 ,
V_2 -> V_248 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 , int V_122 )
{
struct V_20 * V_21 ;
F_126 (sdev, shost) {
if ( V_122 == F_127 ( V_21 ) )
F_59 ( V_21 , NULL ) ;
}
}
void F_128 ( struct V_1 * V_2 , int V_122 , int V_253 )
{
struct V_20 * V_21 ;
F_126 (sdev, shost) {
if ( V_122 == F_127 ( V_21 ) &&
V_253 == F_129 ( V_21 ) )
F_59 ( V_21 , NULL ) ;
}
}
static void
F_130 ( struct V_17 * V_18 )
{
}
int
F_131 ( struct V_20 * V_254 , int T_1 * V_255 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = V_254 -> V_24 ;
struct V_45 V_46 ;
unsigned long V_7 ;
int error = 0 , V_23 , V_256 ;
if ( ! F_132 ( V_257 ) || ! F_132 ( V_258 ) )
return - V_259 ;
error = F_133 ( V_256 , V_255 ) ;
if ( error )
return error ;
if ( F_124 ( V_2 ) < 0 )
return - V_260 ;
error = - V_260 ;
V_18 = F_134 ( V_254 , V_235 ) ;
if ( ! V_18 )
goto V_261;
F_135 ( NULL , & V_46 ) ;
V_18 -> V_45 = & V_46 ;
V_18 -> V_87 = V_46 . V_236 ;
V_18 -> V_89 = F_130 ;
memset ( & V_18 -> V_156 , 0 , sizeof( V_18 -> V_156 ) ) ;
V_18 -> V_153 = 0 ;
V_18 -> V_155 = V_262 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_263 = 1 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
switch ( V_256 & ~ V_264 ) {
case V_265 :
V_23 = V_26 ;
break;
case V_266 :
V_23 = F_63 ( V_18 ) ;
if ( V_23 == V_26 || ( V_256 & V_264 ) )
break;
case V_267 :
V_23 = F_60 ( V_18 ) ;
if ( V_23 == V_26 || ( V_256 & V_264 ) )
break;
case V_268 :
V_23 = F_58 ( V_18 ) ;
if ( V_23 == V_26 || ( V_256 & V_264 ) )
break;
case V_269 :
V_23 = F_54 ( V_18 ) ;
if ( V_23 == V_26 )
break;
default:
V_23 = V_35 ;
break;
}
error = ( V_23 == V_26 ) ? 0 : - V_260 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_263 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_72 ) ) ;
F_112 ( & V_2 -> V_55 ) ;
F_113 ( V_2 ) ;
F_136 ( V_18 ) ;
V_261:
F_125 ( V_2 ) ;
return error ;
}
bool F_137 ( const T_2 * V_92 , int V_270 ,
struct V_65 * V_66 )
{
if ( ! V_92 || ! V_270 )
return false ;
memset ( V_66 , 0 , sizeof( struct V_65 ) ) ;
V_66 -> V_91 = ( V_92 [ 0 ] & 0x7f ) ;
if ( ! F_138 ( V_66 ) )
return false ;
if ( V_66 -> V_91 >= 0x72 ) {
if ( V_270 > 1 )
V_66 -> V_70 = ( V_92 [ 1 ] & 0xf ) ;
if ( V_270 > 2 )
V_66 -> V_72 = V_92 [ 2 ] ;
if ( V_270 > 3 )
V_66 -> V_73 = V_92 [ 3 ] ;
if ( V_270 > 7 )
V_66 -> V_93 = V_92 [ 7 ] ;
} else {
if ( V_270 > 2 )
V_66 -> V_70 = ( V_92 [ 2 ] & 0xf ) ;
if ( V_270 > 7 ) {
V_270 = ( V_270 < ( V_92 [ 7 ] + 8 ) ) ?
V_270 : ( V_92 [ 7 ] + 8 ) ;
if ( V_270 > 12 )
V_66 -> V_72 = V_92 [ 12 ] ;
if ( V_270 > 13 )
V_66 -> V_73 = V_92 [ 13 ] ;
}
}
return true ;
}
bool F_43 ( const struct V_17 * V_236 ,
struct V_65 * V_66 )
{
return F_137 ( V_236 -> V_92 ,
V_164 , V_66 ) ;
}
const T_2 * F_139 ( const T_2 * V_92 , int V_270 ,
int V_271 )
{
int V_272 , V_273 , V_274 , V_275 ;
const T_2 * V_276 ;
if ( ( V_270 < 8 ) || ( 0 == ( V_272 = V_92 [ 7 ] ) ) )
return NULL ;
if ( ( V_92 [ 0 ] < 0x72 ) || ( V_92 [ 0 ] > 0x73 ) )
return NULL ;
V_272 = ( V_272 < ( V_270 - 8 ) ) ?
V_272 : ( V_270 - 8 ) ;
V_276 = & V_92 [ 8 ] ;
for ( V_274 = 0 , V_275 = 0 ; V_275 < V_272 ; V_275 += V_274 ) {
V_276 += V_274 ;
V_273 = ( V_275 < ( V_272 - 1 ) ) ? V_276 [ 1 ] : - 1 ;
V_274 = V_273 + 2 ;
if ( V_276 [ 0 ] == V_271 )
return V_276 ;
if ( V_273 < 0 )
break;
}
return NULL ;
}
int F_140 ( const T_2 * V_92 , int V_270 ,
T_3 * V_277 )
{
int V_278 ;
const T_2 * V_279 ;
T_3 V_280 ;
if ( V_270 < 7 )
return 0 ;
switch ( V_92 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_92 [ 0 ] & 0x80 ) {
* V_277 = ( V_92 [ 3 ] << 24 ) +
( V_92 [ 4 ] << 16 ) +
( V_92 [ 5 ] << 8 ) + V_92 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_279 = F_139 ( V_92 , V_270 ,
0 ) ;
if ( V_279 && ( 0xa == V_279 [ 1 ] ) ) {
V_280 = 0 ;
for ( V_278 = 0 ; V_278 < 8 ; ++ V_278 ) {
if ( V_278 > 0 )
V_280 <<= 8 ;
V_280 |= V_279 [ 4 + V_278 ] ;
}
* V_277 = V_280 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
void F_141 ( int V_281 , T_2 * V_282 , T_2 V_283 , T_2 V_72 , T_2 V_73 )
{
if ( V_281 ) {
V_282 [ 0 ] = 0x72 ;
V_282 [ 1 ] = V_283 ;
V_282 [ 2 ] = V_72 ;
V_282 [ 3 ] = V_73 ;
V_282 [ 7 ] = 0 ;
} else {
V_282 [ 0 ] = 0x70 ;
V_282 [ 2 ] = V_283 ;
V_282 [ 7 ] = 0xa ;
V_282 [ 12 ] = V_72 ;
V_282 [ 13 ] = V_73 ;
}
}
