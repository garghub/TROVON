void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_2 -> V_4 ) {
F_2 ( V_2 ) ;
F_3 ( V_2 -> V_5 ) ;
F_4 ( 5 ,
F_5 ( L_1 ) ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_8 ) == 0 ||
F_8 ( V_2 , V_9 ) == 0 ) {
V_2 -> V_10 ++ ;
F_1 ( V_2 ) ;
}
F_9 ( V_2 -> V_7 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_11 || V_2 -> V_12 == - 1 )
return 0 ;
if ( F_11 ( V_13 , V_2 -> V_11 + V_2 -> V_12 ) &&
V_2 -> V_12 > - 1 )
return 0 ;
return 1 ;
}
void
F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
F_13 ( V_15 , struct V_16 , V_18 . V_15 ) ;
struct V_19 * V_20 = V_17 -> V_21 ;
int V_22 ;
if ( F_10 ( V_20 -> V_23 ) ) {
F_4 ( 3 ,
F_14 ( V_24 , V_17 ,
L_2 ,
V_17 ) ) ;
} else {
F_4 ( 3 ,
F_14 ( V_24 , V_17 ,
L_3 , V_17 ) ) ;
V_22 = F_15 ( V_20 -> V_23 -> V_25 , V_17 ) ;
if ( V_22 == V_26 ) {
V_17 -> V_27 |= V_28 << 16 ;
if ( F_10 ( V_20 -> V_23 ) ) {
F_4 ( 3 ,
F_14 ( V_24 , V_17 ,
L_4
L_5
L_6 , V_17 ) ) ;
} else if ( ! F_16 ( V_17 ) &&
( ++ V_17 -> V_29 <= V_17 -> V_30 ) ) {
F_4 ( 3 ,
F_14 ( V_31 , V_17 ,
L_7
L_8 , V_17 ) ) ;
F_17 ( V_17 , V_32 ) ;
return;
} else {
F_4 ( 3 ,
F_14 ( V_31 , V_17 ,
L_9
L_8 , V_17 ) ) ;
F_18 ( V_17 ) ;
return;
}
} else {
F_4 ( 3 ,
F_14 ( V_24 , V_17 ,
L_10 ,
V_17 , V_22 ) ) ;
}
}
if ( ! F_19 ( V_17 , 0 ) ) {
F_4 ( 3 ,
F_14 ( V_31 , V_17 ,
L_11
L_8 , V_17 ) ) ;
V_17 -> V_27 |= V_28 << 16 ;
F_18 ( V_17 ) ;
}
}
static int
F_20 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_1 * V_2 = V_20 -> V_23 ;
unsigned long V_6 ;
if ( V_17 -> V_33 & V_34 ) {
F_4 ( 3 ,
F_14 ( V_24 , V_17 ,
L_12 , V_17 ) ) ;
F_21 ( & V_17 -> V_18 ) ;
return V_35 ;
}
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_22 ( V_2 ) ) {
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_14 ( V_24 , V_17 ,
L_13 ,
V_17 ) ) ;
return V_35 ;
}
if ( V_2 -> V_12 != - 1 && ! V_2 -> V_11 )
V_2 -> V_11 = V_13 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
V_17 -> V_33 |= V_34 ;
F_4 ( 3 ,
F_14 ( V_24 , V_17 ,
L_14 , V_17 ) ) ;
F_23 ( V_2 -> V_36 , & V_17 -> V_18 , V_37 / 100 ) ;
return V_26 ;
}
int F_19 ( struct V_16 * V_17 , int V_38 )
{
struct V_1 * V_2 = V_17 -> V_21 -> V_23 ;
unsigned long V_6 ;
int V_39 = 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_8 ) )
if ( F_8 ( V_2 , V_9 ) )
goto V_40;
if ( V_2 -> V_12 != - 1 && ! V_2 -> V_11 )
V_2 -> V_11 = V_13 ;
V_39 = 1 ;
if ( V_17 -> V_33 & V_34 )
V_38 &= ~ V_41 ;
V_17 -> V_33 |= V_38 ;
F_24 ( & V_17 -> V_42 , & V_2 -> V_43 ) ;
V_2 -> V_4 ++ ;
F_1 ( V_2 ) ;
V_40:
F_9 ( V_2 -> V_7 , V_6 ) ;
return V_39 ;
}
enum V_44 F_25 ( struct V_45 * V_46 )
{
struct V_16 * V_17 = V_46 -> V_47 ;
enum V_44 V_22 = V_48 ;
struct V_1 * V_23 = V_17 -> V_21 -> V_23 ;
F_26 ( V_17 ) ;
F_27 ( V_17 , V_49 ) ;
if ( V_23 -> V_12 != - 1 && ! V_23 -> V_11 )
V_23 -> V_11 = V_13 ;
if ( V_23 -> V_50 -> V_51 )
V_22 = V_23 -> V_50 -> V_51 ( V_17 ) ;
else if ( V_23 -> V_25 -> V_51 )
V_22 = V_23 -> V_25 -> V_51 ( V_17 ) ;
if ( V_22 == V_48 && ! V_23 -> V_25 -> V_52 )
if ( F_20 ( V_17 ) == V_26 )
return V_48 ;
V_17 -> V_27 |= V_28 << 16 ;
if ( F_28 ( V_22 == V_48 &&
! F_19 ( V_17 , V_41 ) ) )
V_22 = V_53 ;
return V_22 ;
}
int F_29 ( struct V_19 * V_20 )
{
int V_54 ;
F_30 ( V_20 -> V_23 -> V_55 , ! F_22 ( V_20 -> V_23 ) ) ;
V_54 = F_31 ( V_20 ) ;
F_4 ( 5 , F_5 ( L_15 , V_56 ,
V_54 ) ) ;
return V_54 ;
}
static inline void F_32 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_16 * V_17 ;
struct V_19 * V_20 ;
int V_59 = 0 ;
int V_60 = 0 ;
int V_61 = 0 ;
int V_62 = 0 ;
F_33 (sdev, shost) {
F_34 (scmd, work_q, eh_entry) {
if ( V_17 -> V_21 == V_20 ) {
++ V_59 ;
if ( V_17 -> V_33 & V_41 )
++ V_61 ;
else
++ V_60 ;
}
}
if ( V_61 || V_60 ) {
F_4 ( 3 ,
F_35 ( V_24 , V_20 ,
L_16 ,
V_56 , V_60 ,
V_61 ) ) ;
V_61 = 0 ;
V_60 = 0 ;
++ V_62 ;
}
}
F_4 ( 2 , F_5 ( L_17
L_18 ,
V_59 , V_62 ) ) ;
}
static void F_36 ( struct V_19 * V_20 )
{
V_20 -> V_63 -> V_64 = 1 ;
}
static void F_37 ( struct V_19 * V_20 ,
struct V_65 * V_66 )
{
enum V_67 V_68 = V_69 ;
if ( V_66 -> V_70 == V_71 ) {
if ( V_66 -> V_72 == 0x3f && V_66 -> V_73 == 0x03 ) {
V_68 = V_74 ;
F_35 ( V_31 , V_20 ,
L_19 ) ;
} else if ( V_66 -> V_72 == 0x3f && V_66 -> V_73 == 0x0e ) {
V_68 = V_75 ;
F_36 ( V_20 ) ;
F_35 ( V_31 , V_20 ,
L_20
L_21
L_22
L_23 ) ;
} else if ( V_66 -> V_72 == 0x3f )
F_35 ( V_31 , V_20 ,
L_20
L_24
L_22
L_25 ) ;
if ( V_66 -> V_72 == 0x38 && V_66 -> V_73 == 0x07 ) {
V_68 = V_76 ;
F_35 ( V_31 , V_20 ,
L_20
L_26
L_27 ) ;
}
if ( V_66 -> V_72 == 0x2a && V_66 -> V_73 == 0x01 ) {
V_68 = V_77 ;
F_35 ( V_31 , V_20 ,
L_28 ) ;
} else if ( V_66 -> V_72 == 0x2a && V_66 -> V_73 == 0x09 ) {
V_68 = V_78 ;
F_35 ( V_31 , V_20 ,
L_29 ) ;
} else if ( V_66 -> V_72 == 0x2a )
F_35 ( V_31 , V_20 ,
L_30 ) ;
}
if ( V_68 != V_69 ) {
F_38 ( V_68 , V_20 -> V_79 ) ;
F_39 ( & V_20 -> V_80 ) ;
}
}
static int F_40 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_65 V_66 ;
if ( ! F_41 ( V_17 , & V_66 ) )
return V_35 ;
if ( V_17 -> V_81 [ 0 ] == V_82 && V_17 -> V_83 != V_84 )
return V_26 ;
F_37 ( V_20 , & V_66 ) ;
if ( F_42 ( & V_66 ) )
return V_85 ;
if ( V_20 -> V_86 && V_20 -> V_86 -> V_87 &&
V_20 -> V_86 -> V_87 -> V_88 ) {
int V_89 ;
V_89 = V_20 -> V_86 -> V_87 -> V_88 ( V_20 , & V_66 ) ;
if ( V_89 != V_90 )
return V_89 ;
}
if ( V_66 . V_91 == 0x70 ) {
if ( V_17 -> V_92 [ 2 ] & 0xe0 )
return V_26 ;
} else {
if ( ( V_66 . V_93 > 3 ) &&
( V_17 -> V_92 [ 8 ] == 0x4 ) &&
( V_17 -> V_92 [ 11 ] & 0xe0 ) )
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
return V_85 ;
case V_97 :
case V_71 :
if ( V_17 -> V_21 -> V_98 ) {
if ( V_66 . V_72 != 0x28 || V_66 . V_73 != 0x00 ) {
V_17 -> V_21 -> V_98 = 0 ;
return V_85 ;
}
}
if ( V_17 -> V_21 -> V_63 -> V_64 &&
V_66 . V_72 == 0x3f && V_66 . V_73 == 0x0e )
return V_85 ;
if ( ( V_66 . V_72 == 0x04 ) && ( V_66 . V_73 == 0x01 ) )
return V_85 ;
if ( V_17 -> V_21 -> V_99 &&
( V_66 . V_72 == 0x04 ) && ( V_66 . V_73 == 0x02 ) )
return V_35 ;
return V_26 ;
case V_100 :
if ( V_66 . V_72 == 0x27 && V_66 . V_73 == 0x07 ) {
F_43 ( V_17 , V_101 ) ;
return V_26 ;
}
case V_102 :
case V_103 :
case V_104 :
case V_105 :
F_43 ( V_17 , V_106 ) ;
return V_26 ;
case V_107 :
if ( V_66 . V_72 == 0x11 ||
V_66 . V_72 == 0x13 ||
V_66 . V_72 == 0x14 ) {
F_43 ( V_17 , V_108 ) ;
return V_26 ;
}
return V_85 ;
case V_109 :
if ( V_17 -> V_21 -> V_110 )
return V_111 ;
else
F_43 ( V_17 , V_106 ) ;
case V_112 :
if ( V_66 . V_72 == 0x20 ||
V_66 . V_72 == 0x21 ||
V_66 . V_72 == 0x24 ||
V_66 . V_72 == 0x26 ) {
F_43 ( V_17 , V_106 ) ;
}
return V_26 ;
default:
return V_26 ;
}
}
static void F_44 ( struct V_19 * V_20 )
{
struct V_113 * V_114 = V_20 -> V_23 -> V_25 ;
struct V_19 * V_115 ;
if ( ! V_114 -> V_116 ||
V_20 -> V_117 >= V_20 -> V_118 )
return;
if ( F_11 ( V_13 ,
V_20 -> V_119 + V_20 -> V_120 ) )
return;
if ( F_11 ( V_13 ,
V_20 -> V_121 + V_20 -> V_120 ) )
return;
F_33 (tmp_sdev, sdev->host) {
if ( V_115 -> V_122 != V_20 -> V_122 ||
V_115 -> V_123 != V_20 -> V_123 ||
V_115 -> V_117 == V_20 -> V_118 )
continue;
V_114 -> V_116 ( V_115 , V_115 -> V_117 + 1 ,
V_124 ) ;
V_20 -> V_119 = V_13 ;
}
}
static void F_45 ( struct V_19 * V_20 )
{
struct V_113 * V_114 = V_20 -> V_23 -> V_25 ;
struct V_19 * V_115 ;
if ( ! V_114 -> V_116 )
return;
F_33 (tmp_sdev, sdev->host) {
if ( V_115 -> V_122 != V_20 -> V_122 ||
V_115 -> V_123 != V_20 -> V_123 )
continue;
V_114 -> V_116 ( V_115 , V_115 -> V_117 - 1 ,
V_125 ) ;
}
}
static int F_46 ( struct V_16 * V_17 )
{
if ( F_47 ( V_17 -> V_27 ) == V_126 ) {
return F_40 ( V_17 ) ;
}
if ( F_47 ( V_17 -> V_27 ) != V_127 )
return V_35 ;
if ( F_48 ( V_17 -> V_27 ) != V_128 )
return V_35 ;
switch ( F_49 ( V_17 -> V_27 ) ) {
case V_129 :
F_44 ( V_17 -> V_21 ) ;
case V_130 :
return V_26 ;
case V_131 :
return F_40 ( V_17 ) ;
case V_132 :
case V_133 :
case V_134 :
return V_26 ;
case V_135 :
if ( V_17 -> V_81 [ 0 ] == V_82 )
return V_26 ;
return V_35 ;
case V_136 :
F_45 ( V_17 -> V_21 ) ;
case V_137 :
return V_85 ;
default:
return V_35 ;
}
return V_35 ;
}
static void V_84 ( struct V_16 * V_17 )
{
struct V_138 * V_139 ;
F_4 ( 3 ,
F_5 ( L_31 ,
V_56 , V_17 , V_17 -> V_27 ) ) ;
V_139 = V_17 -> V_21 -> V_23 -> V_139 ;
if ( V_139 )
F_50 ( V_139 ) ;
}
static int F_51 ( struct V_16 * V_17 )
{
unsigned long V_6 ;
int V_22 ;
struct V_1 * V_23 = V_17 -> V_21 -> V_23 ;
struct V_113 * V_25 = V_23 -> V_25 ;
F_4 ( 3 , F_5 ( L_32 ,
V_56 ) ) ;
if ( ! V_25 -> V_140 )
return V_35 ;
V_22 = V_25 -> V_140 ( V_17 ) ;
if ( V_22 == V_26 ) {
if ( ! V_25 -> V_141 )
F_52 ( V_142 ) ;
F_7 ( V_23 -> V_7 , V_6 ) ;
F_53 ( V_23 , F_54 ( V_17 ) ) ;
F_9 ( V_23 -> V_7 , V_6 ) ;
}
return V_22 ;
}
static int F_55 ( struct V_16 * V_17 )
{
unsigned long V_6 ;
int V_22 ;
struct V_1 * V_23 = V_17 -> V_21 -> V_23 ;
struct V_113 * V_25 = V_23 -> V_25 ;
F_4 ( 3 , F_5 ( L_33 ,
V_56 ) ) ;
if ( ! V_25 -> V_143 )
return V_35 ;
V_22 = V_25 -> V_143 ( V_17 ) ;
if ( V_22 == V_26 ) {
if ( ! V_25 -> V_141 )
F_52 ( V_144 ) ;
F_7 ( V_23 -> V_7 , V_6 ) ;
F_53 ( V_23 , F_54 ( V_17 ) ) ;
F_9 ( V_23 -> V_7 , V_6 ) ;
}
return V_22 ;
}
static void F_56 ( struct V_19 * V_20 , void * V_145 )
{
V_20 -> V_146 = 1 ;
V_20 -> V_98 = 1 ;
}
static int F_57 ( struct V_16 * V_17 )
{
unsigned long V_6 ;
int V_22 ;
struct V_1 * V_23 = V_17 -> V_21 -> V_23 ;
struct V_113 * V_25 = V_23 -> V_25 ;
if ( ! V_25 -> V_147 )
return V_35 ;
V_22 = V_25 -> V_147 ( V_17 ) ;
if ( V_22 == V_26 ) {
F_7 ( V_23 -> V_7 , V_6 ) ;
F_58 ( F_59 ( V_17 -> V_21 ) , NULL ,
F_56 ) ;
F_9 ( V_23 -> V_7 , V_6 ) ;
}
return V_22 ;
}
static int F_60 ( struct V_16 * V_17 )
{
int V_22 ;
struct V_113 * V_25 = V_17 -> V_21 -> V_23 -> V_25 ;
if ( ! V_25 -> V_148 )
return V_35 ;
V_22 = V_25 -> V_148 ( V_17 ) ;
if ( V_22 == V_26 )
F_56 ( V_17 -> V_21 , NULL ) ;
return V_22 ;
}
static int F_15 ( struct V_113 * V_25 , struct V_16 * V_17 )
{
if ( ! V_25 -> V_149 )
return V_35 ;
return V_25 -> V_149 ( V_17 ) ;
}
static void F_61 ( struct V_16 * V_17 )
{
if ( F_15 ( V_17 -> V_21 -> V_23 -> V_25 , V_17 ) != V_26 )
if ( F_60 ( V_17 ) != V_26 )
if ( F_57 ( V_17 ) != V_26 )
if ( F_55 ( V_17 ) != V_26 )
F_51 ( V_17 ) ;
}
void F_62 ( struct V_16 * V_17 , struct V_150 * V_151 ,
unsigned char * V_81 , int V_152 , unsigned V_153 )
{
struct V_19 * V_20 = V_17 -> V_21 ;
V_151 -> V_154 = V_17 -> V_154 ;
V_151 -> V_81 = V_17 -> V_81 ;
V_151 -> V_155 = V_17 -> V_156 ;
V_151 -> V_157 = V_17 -> V_157 ;
V_151 -> V_158 = V_17 -> V_45 -> V_158 ;
V_151 -> V_27 = V_17 -> V_27 ;
V_151 -> V_159 = V_17 -> V_159 ;
V_151 -> V_160 = V_17 -> V_160 ;
V_17 -> V_160 = V_161 ;
V_17 -> V_81 = V_151 -> V_162 ;
memset ( V_17 -> V_81 , 0 , V_163 ) ;
memset ( & V_17 -> V_157 , 0 , sizeof( V_17 -> V_157 ) ) ;
V_17 -> V_45 -> V_158 = NULL ;
if ( V_153 ) {
V_17 -> V_157 . V_164 = F_63 ( unsigned , V_165 ,
V_153 ) ;
F_64 ( & V_151 -> V_166 , V_17 -> V_92 ,
V_17 -> V_157 . V_164 ) ;
V_17 -> V_157 . V_167 . V_168 = & V_151 -> V_166 ;
V_17 -> V_156 = V_169 ;
V_17 -> V_157 . V_167 . V_170 = 1 ;
V_17 -> V_81 [ 0 ] = V_171 ;
V_17 -> V_81 [ 4 ] = V_17 -> V_157 . V_164 ;
V_17 -> V_154 = F_65 ( V_17 -> V_81 [ 0 ] ) ;
} else {
V_17 -> V_156 = V_172 ;
if ( V_81 ) {
F_66 ( V_152 > V_163 ) ;
memcpy ( V_17 -> V_81 , V_81 , V_152 ) ;
V_17 -> V_154 = F_65 ( V_17 -> V_81 [ 0 ] ) ;
}
}
V_17 -> V_159 = 0 ;
if ( V_20 -> V_173 <= V_174 && V_20 -> V_173 != V_175 )
V_17 -> V_81 [ 1 ] = ( V_17 -> V_81 [ 1 ] & 0x1f ) |
( V_20 -> V_176 << 5 & 0xe0 ) ;
memset ( V_17 -> V_92 , 0 , V_165 ) ;
}
void F_67 ( struct V_16 * V_17 , struct V_150 * V_151 )
{
V_17 -> V_154 = V_151 -> V_154 ;
V_17 -> V_81 = V_151 -> V_81 ;
V_17 -> V_156 = V_151 -> V_155 ;
V_17 -> V_157 = V_151 -> V_157 ;
V_17 -> V_45 -> V_158 = V_151 -> V_158 ;
V_17 -> V_27 = V_151 -> V_27 ;
V_17 -> V_159 = V_151 -> V_159 ;
V_17 -> V_160 = V_151 -> V_160 ;
}
static int F_68 ( struct V_16 * V_17 , unsigned char * V_81 ,
int V_152 , int V_177 , unsigned V_153 )
{
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_1 * V_2 = V_20 -> V_23 ;
F_69 ( V_178 ) ;
unsigned long V_179 = V_177 ;
struct V_150 V_151 ;
const unsigned long V_180 = F_70 ( 100 ) ;
int V_22 ;
V_181:
F_62 ( V_17 , & V_151 , V_81 , V_152 , V_153 ) ;
V_2 -> V_139 = & V_178 ;
F_71 ( V_17 ) ;
V_17 -> V_83 = V_84 ;
V_22 = V_2 -> V_25 -> V_182 ( V_2 , V_17 ) ;
if ( V_22 ) {
if ( V_179 > V_180 ) {
F_67 ( V_17 , & V_151 ) ;
V_179 -= V_180 ;
F_72 ( F_73 ( V_180 ) ) ;
goto V_181;
}
V_179 = 0 ;
V_22 = V_85 ;
} else {
V_179 = F_74 ( & V_178 , V_177 ) ;
}
V_2 -> V_139 = NULL ;
F_27 ( V_17 , V_22 ) ;
F_4 ( 3 ,
F_5 ( L_34 ,
V_56 , V_17 , V_179 ) ) ;
if ( V_179 ) {
V_22 = F_46 ( V_17 ) ;
F_4 ( 3 ,
F_5 ( L_35 ,
V_56 , V_22 ) ) ;
switch ( V_22 ) {
case V_26 :
case V_85 :
case V_35 :
break;
case V_111 :
V_22 = V_85 ;
break;
default:
V_22 = V_35 ;
break;
}
} else if ( ! V_22 ) {
F_61 ( V_17 ) ;
V_22 = V_35 ;
}
F_67 ( V_17 , & V_151 ) ;
return V_22 ;
}
static int F_75 ( struct V_16 * V_17 )
{
return F_68 ( V_17 , NULL , 0 , V_17 -> V_21 -> V_183 , ~ 0 ) ;
}
static int F_76 ( struct V_16 * V_17 , int V_22 )
{
if ( V_17 -> V_45 -> V_184 != V_185 ) {
struct V_186 * V_187 = F_77 ( V_17 ) ;
if ( V_187 -> V_139 )
V_22 = V_187 -> V_139 ( V_17 , V_22 ) ;
}
return V_22 ;
}
void F_78 ( struct V_16 * V_17 , struct V_57 * V_188 )
{
V_17 -> V_21 -> V_23 -> V_4 -- ;
V_17 -> V_33 = 0 ;
F_79 ( & V_17 -> V_42 , V_188 ) ;
}
int F_80 ( struct V_57 * V_58 ,
struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_189 ;
struct V_1 * V_2 ;
int V_22 ;
F_81 (scmd, next, work_q, eh_entry) {
if ( ( V_17 -> V_33 & V_41 ) ||
F_82 ( V_17 ) )
continue;
V_2 = V_17 -> V_21 -> V_23 ;
if ( F_10 ( V_2 ) ) {
F_4 ( 3 ,
F_83 ( V_24 , V_2 ,
L_36 ,
V_56 ) ) ;
break;
}
F_4 ( 2 , F_14 ( V_24 , V_17 ,
L_37 ,
V_190 -> V_191 ) ) ;
V_22 = F_75 ( V_17 ) ;
if ( V_22 != V_26 )
continue;
F_4 ( 3 , F_5 ( L_38
L_39 , V_17 ,
V_17 -> V_27 ) ) ;
F_4 ( 3 , F_84 ( L_40 , V_17 ) ) ;
V_22 = F_85 ( V_17 ) ;
if ( V_22 == V_26 )
V_17 -> V_29 = V_17 -> V_30 ;
else if ( V_22 != V_85 )
continue;
F_78 ( V_17 , V_188 ) ;
}
return F_86 ( V_58 ) ;
}
static int F_87 ( struct V_16 * V_17 )
{
static unsigned char V_192 [ 6 ] = { V_82 , 0 , 0 , 0 , 0 , 0 } ;
int V_193 = 1 , V_22 ;
V_194:
V_22 = F_68 ( V_17 , V_192 , 6 ,
V_17 -> V_21 -> V_183 , 0 ) ;
F_4 ( 3 , F_5 ( L_41 ,
V_56 , V_17 , V_22 ) ) ;
switch ( V_22 ) {
case V_85 :
if ( V_193 -- )
goto V_194;
case V_26 :
return 0 ;
default:
return 1 ;
}
}
static int F_88 ( struct V_57 * V_195 ,
struct V_57 * V_58 ,
struct V_57 * V_188 , int V_196 )
{
struct V_16 * V_17 , * V_189 ;
struct V_19 * V_20 ;
int V_197 ;
while ( ! F_86 ( V_195 ) ) {
V_17 = F_89 ( V_195 -> V_189 , struct V_16 , V_42 ) ;
V_20 = V_17 -> V_21 ;
if ( ! V_196 ) {
if ( F_10 ( V_20 -> V_23 ) ) {
F_90 ( V_195 , V_58 ) ;
F_4 ( 3 ,
F_83 ( V_24 , V_20 -> V_23 ,
L_42 ,
V_56 ) ) ;
break;
}
}
V_197 = ! F_31 ( V_17 -> V_21 ) ||
( V_196 && ! F_91 ( V_17 ) &&
! F_87 ( V_17 ) ) ||
! F_87 ( V_17 ) ;
F_81 (scmd, next, cmd_list, eh_entry)
if ( V_17 -> V_21 == V_20 ) {
if ( V_197 &&
( V_196 ||
F_76 ( V_17 , V_26 ) == V_26 ) )
F_78 ( V_17 , V_188 ) ;
else
F_79 ( & V_17 -> V_42 , V_58 ) ;
}
}
return F_86 ( V_58 ) ;
}
static int F_92 ( struct V_57 * V_58 ,
struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_189 ;
F_93 ( V_198 ) ;
int V_22 ;
struct V_1 * V_2 ;
F_81 (scmd, next, work_q, eh_entry) {
if ( ! ( V_17 -> V_33 & V_41 ) )
continue;
V_2 = V_17 -> V_21 -> V_23 ;
if ( F_10 ( V_2 ) ) {
F_90 ( & V_198 , V_58 ) ;
F_4 ( 3 ,
F_83 ( V_24 , V_2 ,
L_36 ,
V_56 ) ) ;
return F_86 ( V_58 ) ;
}
F_4 ( 3 , F_5 ( L_43
L_44 , V_190 -> V_191 ,
V_17 ) ) ;
V_22 = F_15 ( V_2 -> V_25 , V_17 ) ;
if ( V_22 == V_35 ) {
F_4 ( 3 , F_5 ( L_45
L_46
L_44 ,
V_190 -> V_191 ,
V_17 ) ) ;
F_90 ( & V_198 , V_58 ) ;
return F_86 ( V_58 ) ;
}
V_17 -> V_33 &= ~ V_41 ;
if ( V_22 == V_199 )
F_78 ( V_17 , V_188 ) ;
else
F_79 ( & V_17 -> V_42 , & V_198 ) ;
}
return F_88 ( & V_198 , V_58 , V_188 , 0 ) ;
}
static int F_91 ( struct V_16 * V_17 )
{
static unsigned char V_200 [ 6 ] = { V_201 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_17 -> V_21 -> V_99 ) {
int V_202 , V_22 = V_85 ;
for ( V_202 = 0 ; V_22 == V_85 && V_202 < 2 ; V_202 ++ )
V_22 = F_68 ( V_17 , V_200 , 6 , V_17 -> V_21 -> V_203 -> V_204 , 0 ) ;
if ( V_22 == V_26 )
return 0 ;
}
return 1 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_205 , * V_189 ;
struct V_19 * V_20 ;
F_33 (sdev, shost) {
if ( F_10 ( V_2 ) ) {
F_4 ( 3 ,
F_83 ( V_24 , V_2 ,
L_36 ,
V_56 ) ) ;
break;
}
V_205 = NULL ;
F_34 (scmd, work_q, eh_entry)
if ( V_17 -> V_21 == V_20 && F_82 ( V_17 ) &&
F_40 ( V_17 ) == V_35 ) {
V_205 = V_17 ;
break;
}
if ( ! V_205 )
continue;
F_4 ( 3 , F_5 ( L_47
L_48 , V_190 -> V_191 , V_20 ) ) ;
if ( ! F_91 ( V_205 ) ) {
if ( ! F_31 ( V_20 ) ||
! F_87 ( V_205 ) ) {
F_81 (scmd, next,
work_q, eh_entry) {
if ( V_17 -> V_21 == V_20 &&
F_76 ( V_17 , V_26 ) == V_26 )
F_78 ( V_17 , V_188 ) ;
}
}
} else {
F_4 ( 3 ,
F_5 ( L_49
L_48 , V_190 -> V_191 , V_20 ) ) ;
}
}
return F_86 ( V_58 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_206 , * V_189 ;
struct V_19 * V_20 ;
int V_22 ;
F_33 (sdev, shost) {
if ( F_10 ( V_2 ) ) {
F_4 ( 3 ,
F_83 ( V_24 , V_2 ,
L_36 ,
V_56 ) ) ;
break;
}
V_206 = NULL ;
F_34 (scmd, work_q, eh_entry)
if ( V_17 -> V_21 == V_20 ) {
V_206 = V_17 ;
break;
}
if ( ! V_206 )
continue;
F_4 ( 3 , F_5 ( L_50
L_48 , V_190 -> V_191 ,
V_20 ) ) ;
V_22 = F_60 ( V_206 ) ;
if ( V_22 == V_26 || V_22 == V_199 ) {
if ( ! F_31 ( V_20 ) ||
V_22 == V_199 ||
! F_87 ( V_206 ) ) {
F_81 (scmd, next,
work_q, eh_entry) {
if ( V_17 -> V_21 == V_20 &&
F_76 ( V_17 , V_22 ) != V_35 )
F_78 ( V_17 ,
V_188 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_51
L_52
L_44 ,
V_190 -> V_191 ,
V_20 ) ) ;
}
}
return F_86 ( V_58 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_188 )
{
F_93 ( V_207 ) ;
F_93 ( V_198 ) ;
F_90 ( V_58 , & V_207 ) ;
while ( ! F_86 ( & V_207 ) ) {
struct V_16 * V_189 , * V_17 ;
int V_22 ;
unsigned int V_123 ;
if ( F_10 ( V_2 ) ) {
F_90 ( & V_198 , V_58 ) ;
F_90 ( & V_207 , V_58 ) ;
F_4 ( 3 ,
F_83 ( V_24 , V_2 ,
L_36 ,
V_56 ) ) ;
return F_86 ( V_58 ) ;
}
V_17 = F_89 ( V_207 . V_189 , struct V_16 , V_42 ) ;
V_123 = F_97 ( V_17 ) ;
F_4 ( 3 , F_5 ( L_53
L_54 ,
V_190 -> V_191 , V_123 ) ) ;
V_22 = F_57 ( V_17 ) ;
if ( V_22 != V_26 && V_22 != V_199 )
F_4 ( 3 , F_5 ( L_55
L_56
L_57 ,
V_190 -> V_191 , V_123 ) ) ;
F_81 (scmd, next, &tmp_list, eh_entry) {
if ( F_97 ( V_17 ) != V_123 )
continue;
if ( V_22 == V_26 )
F_79 ( & V_17 -> V_42 , & V_198 ) ;
else if ( V_22 == V_199 )
F_78 ( V_17 , V_188 ) ;
else
F_98 ( & V_17 -> V_42 , V_58 ) ;
}
}
return F_88 ( & V_198 , V_58 , V_188 , 0 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_208 , * V_189 ;
F_93 ( V_198 ) ;
unsigned int V_122 ;
int V_22 ;
for ( V_122 = 0 ; V_122 <= V_2 -> V_209 ; V_122 ++ ) {
if ( F_10 ( V_2 ) ) {
F_90 ( & V_198 , V_58 ) ;
F_4 ( 3 ,
F_83 ( V_24 , V_2 ,
L_36 ,
V_56 ) ) ;
return F_86 ( V_58 ) ;
}
V_208 = NULL ;
F_34 (scmd, work_q, eh_entry) {
if ( V_122 == F_54 ( V_17 ) ) {
V_208 = V_17 ;
break;
}
}
if ( ! V_208 )
continue;
F_4 ( 3 , F_5 ( L_58
L_59 , V_190 -> V_191 ,
V_122 ) ) ;
V_22 = F_55 ( V_208 ) ;
if ( V_22 == V_26 || V_22 == V_199 ) {
F_81 (scmd, next, work_q, eh_entry) {
if ( V_122 == F_54 ( V_17 ) ) {
if ( V_22 == V_199 )
F_78 ( V_17 ,
V_188 ) ;
else
F_79 ( & V_17 -> V_42 ,
& V_198 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_60
L_61 ,
V_190 -> V_191 ,
V_122 ) ) ;
}
}
return F_88 ( & V_198 , V_58 , V_188 , 0 ) ;
}
static int F_100 ( struct V_57 * V_58 ,
struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_189 ;
F_93 ( V_198 ) ;
int V_22 ;
if ( ! F_86 ( V_58 ) ) {
V_17 = F_89 ( V_58 -> V_189 ,
struct V_16 , V_42 ) ;
F_4 ( 3 , F_5 ( L_62
, V_190 -> V_191 ) ) ;
V_22 = F_51 ( V_17 ) ;
if ( V_22 == V_26 ) {
F_90 ( V_58 , & V_198 ) ;
} else if ( V_22 == V_199 ) {
F_81 (scmd, next, work_q, eh_entry) {
F_78 ( V_17 , V_188 ) ;
}
} else {
F_4 ( 3 , F_5 ( L_63
L_64 ,
V_190 -> V_191 ) ) ;
}
}
return F_88 ( & V_198 , V_58 , V_188 , 1 ) ;
}
static void F_101 ( struct V_57 * V_58 ,
struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_189 ;
F_81 (scmd, next, work_q, eh_entry) {
F_35 ( V_24 , V_17 -> V_21 , L_65
L_66 ) ;
F_102 ( V_17 -> V_21 , V_210 ) ;
if ( V_17 -> V_33 & V_41 ) {
}
F_78 ( V_17 , V_188 ) ;
}
return;
}
int F_16 ( struct V_16 * V_17 )
{
switch ( F_47 ( V_17 -> V_27 ) ) {
case V_127 :
break;
case V_28 :
goto V_211;
case V_212 :
return ( V_17 -> V_45 -> V_213 & V_214 ) ;
case V_215 :
return ( V_17 -> V_45 -> V_213 & V_216 ) ;
case V_217 :
if ( F_48 ( V_17 -> V_27 ) == V_128 &&
F_49 ( V_17 -> V_27 ) == V_135 )
return 0 ;
case V_218 :
return ( V_17 -> V_45 -> V_213 & V_219 ) ;
}
if ( F_49 ( V_17 -> V_27 ) != V_131 )
return 0 ;
V_211:
if ( V_17 -> V_45 -> V_213 & V_216 ||
V_17 -> V_45 -> V_184 == V_185 )
return 1 ;
else
return 0 ;
}
int F_85 ( struct V_16 * V_17 )
{
int V_22 ;
if ( ! F_31 ( V_17 -> V_21 ) ) {
F_4 ( 5 , F_5 ( L_67
L_68 ,
V_56 ) ) ;
return V_26 ;
}
switch ( F_47 ( V_17 -> V_27 ) ) {
case V_220 :
V_17 -> V_27 &= 0xff00ffff ;
return V_26 ;
case V_127 :
break;
case V_221 :
if ( V_17 -> V_33 & V_34 ) {
V_17 -> V_27 |= V_28 << 16 ;
return V_26 ;
}
case V_222 :
case V_223 :
return V_26 ;
case V_218 :
goto V_224;
case V_225 :
return V_85 ;
case V_226 :
return V_111 ;
case V_227 :
goto V_224;
case V_228 :
return V_26 ;
case V_217 :
if ( F_48 ( V_17 -> V_27 ) == V_128 &&
F_49 ( V_17 -> V_27 ) == V_135 )
break;
case V_212 :
case V_215 :
goto V_224;
case V_28 :
if ( ( V_17 -> V_81 [ 0 ] == V_82 ||
V_17 -> V_81 [ 0 ] == V_229 ) ) {
return V_26 ;
} else {
return V_35 ;
}
case V_126 :
return V_26 ;
default:
return V_35 ;
}
if ( F_48 ( V_17 -> V_27 ) != V_128 )
return V_35 ;
switch ( F_49 ( V_17 -> V_27 ) ) {
case V_136 :
F_45 ( V_17 -> V_21 ) ;
case V_137 :
return V_111 ;
case V_129 :
if ( V_17 -> V_81 [ 0 ] == V_230 )
V_17 -> V_21 -> V_63 -> V_64 = 0 ;
F_44 ( V_17 -> V_21 ) ;
case V_130 :
return V_26 ;
case V_231 :
goto V_224;
case V_131 :
V_22 = F_40 ( V_17 ) ;
if ( V_22 == V_85 )
goto V_224;
return V_22 ;
case V_132 :
case V_133 :
case V_134 :
case V_232 :
return V_26 ;
case V_135 :
F_35 ( V_24 , V_17 -> V_21 ,
L_69 ) ;
F_43 ( V_17 , V_233 ) ;
return V_26 ;
default:
return V_35 ;
}
return V_35 ;
V_224:
if ( ( ++ V_17 -> V_29 ) <= V_17 -> V_30
&& ! F_16 ( V_17 ) ) {
return V_85 ;
} else {
return V_26 ;
}
}
static void F_103 ( struct V_45 * V_46 , int V_234 )
{
F_104 ( V_46 -> V_235 , V_46 ) ;
}
static void F_105 ( struct V_19 * V_20 )
{
struct V_45 * V_46 ;
V_46 = F_106 ( V_20 -> V_203 , V_236 , V_237 ) ;
V_46 -> V_238 [ 0 ] = V_239 ;
V_46 -> V_238 [ 1 ] = 0 ;
V_46 -> V_238 [ 2 ] = 0 ;
V_46 -> V_238 [ 3 ] = 0 ;
V_46 -> V_238 [ 4 ] = V_240 ;
V_46 -> V_238 [ 5 ] = 0 ;
V_46 -> V_154 = F_65 ( V_46 -> V_238 [ 0 ] ) ;
V_46 -> V_184 = V_185 ;
V_46 -> V_213 |= V_241 ;
V_46 -> V_177 = 10 * V_37 ;
V_46 -> V_29 = 5 ;
F_107 ( V_46 -> V_235 , NULL , V_46 , 1 , F_103 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
unsigned long V_6 ;
F_33 (sdev, shost) {
if ( F_31 ( V_20 ) && V_20 -> V_242 )
F_105 ( V_20 ) ;
}
F_4 ( 3 ,
F_5 ( L_70 ,
V_2 -> V_243 ) ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_244 ) )
if ( F_8 ( V_2 , V_245 ) )
F_66 ( F_8 ( V_2 , V_246 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_109 ( & V_2 -> V_55 ) ;
F_110 ( V_2 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( V_2 -> V_10 )
if ( F_8 ( V_2 , V_8 ) )
F_111 ( F_8 ( V_2 , V_9 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
}
void F_112 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_57 * V_188 )
{
if ( ! F_94 ( V_2 , V_58 , V_188 ) )
if ( ! F_95 ( V_2 , V_58 , V_188 ) )
if ( ! F_96 ( V_2 , V_58 , V_188 ) )
if ( ! F_99 ( V_2 , V_58 , V_188 ) )
if ( ! F_100 ( V_58 , V_188 ) )
F_101 ( V_58 ,
V_188 ) ;
}
void F_113 ( struct V_57 * V_188 )
{
struct V_16 * V_17 , * V_189 ;
F_81 (scmd, next, done_q, eh_entry) {
F_114 ( & V_17 -> V_42 ) ;
if ( F_31 ( V_17 -> V_21 ) &&
! F_16 ( V_17 ) &&
( ++ V_17 -> V_29 <= V_17 -> V_30 ) ) {
F_4 ( 3 , F_5 ( L_71
L_72 ,
V_190 -> V_191 ,
V_17 ) ) ;
F_17 ( V_17 , V_32 ) ;
} else {
if ( ! V_17 -> V_27 )
V_17 -> V_27 |= ( V_247 << 24 ) ;
F_4 ( 3 , F_5 ( L_73
L_74 ,
V_190 -> V_191 , V_17 ) ) ;
F_18 ( V_17 ) ;
}
}
}
static void F_115 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_93 ( V_248 ) ;
F_93 ( V_249 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
F_90 ( & V_2 -> V_43 , & V_248 ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 1 , F_32 ( V_2 , & V_248 ) ) ;
if ( ! F_80 ( & V_248 , & V_249 ) )
if ( ! F_92 ( & V_248 , & V_249 ) )
F_112 ( V_2 , & V_248 , & V_249 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( V_2 -> V_12 != - 1 )
V_2 -> V_11 = 0 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_113 ( & V_249 ) ;
}
int F_116 ( void * V_145 )
{
struct V_1 * V_2 = V_145 ;
while ( ! F_117 () ) {
F_118 ( V_250 ) ;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_10 == 0 ) ||
V_2 -> V_4 != V_2 -> V_3 ) {
F_4 ( 1 ,
F_5 ( L_75 ,
V_2 -> V_243 ) ) ;
F_119 () ;
continue;
}
F_120 ( V_251 ) ;
F_4 ( 1 ,
F_5 ( L_76 ,
V_2 -> V_243 , V_2 -> V_10 ,
V_2 -> V_4 , V_2 -> V_3 ) ) ;
if ( ! V_2 -> V_252 && F_121 ( V_2 ) != 0 ) {
F_4 ( 1 ,
F_5 ( V_253 L_77
L_78 ,
V_2 -> V_243 ) ) ;
continue;
}
if ( V_2 -> V_50 -> V_254 )
V_2 -> V_50 -> V_254 ( V_2 ) ;
else
F_115 ( V_2 ) ;
F_108 ( V_2 ) ;
if ( ! V_2 -> V_252 )
F_122 ( V_2 ) ;
}
F_120 ( V_251 ) ;
F_4 ( 1 ,
F_5 ( L_79 , V_2 -> V_243 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 , int V_122 )
{
struct V_19 * V_20 ;
F_123 (sdev, shost) {
if ( V_122 == F_124 ( V_20 ) )
F_56 ( V_20 , NULL ) ;
}
}
void F_125 ( struct V_1 * V_2 , int V_122 , int V_255 )
{
struct V_19 * V_20 ;
F_123 (sdev, shost) {
if ( V_122 == F_124 ( V_20 ) &&
V_255 == F_126 ( V_20 ) )
F_56 ( V_20 , NULL ) ;
}
}
static void
F_127 ( struct V_16 * V_17 )
{
}
int
F_128 ( struct V_19 * V_256 , int V_257 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 = V_256 -> V_23 ;
struct V_45 V_46 ;
unsigned long V_6 ;
int V_22 ;
if ( F_121 ( V_2 ) < 0 )
return V_35 ;
V_17 = F_129 ( V_256 , V_237 ) ;
F_130 ( NULL , & V_46 ) ;
V_17 -> V_45 = & V_46 ;
V_17 -> V_81 = V_46 . V_238 ;
V_17 -> V_83 = F_127 ;
memset ( & V_17 -> V_157 , 0 , sizeof( V_17 -> V_157 ) ) ;
V_17 -> V_154 = 0 ;
V_17 -> V_156 = V_258 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_259 = 1 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
switch ( V_257 ) {
case V_260 :
V_22 = F_60 ( V_17 ) ;
if ( V_22 == V_26 )
break;
case V_261 :
V_22 = F_57 ( V_17 ) ;
if ( V_22 == V_26 )
break;
case V_262 :
V_22 = F_55 ( V_17 ) ;
if ( V_22 == V_26 )
break;
case V_263 :
V_22 = F_51 ( V_17 ) ;
break;
default:
V_22 = V_35 ;
}
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_259 = 0 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_5 ( L_80 ,
V_56 ) ) ;
F_109 ( & V_2 -> V_55 ) ;
F_110 ( V_2 ) ;
F_131 ( V_17 ) ;
F_122 ( V_2 ) ;
return V_22 ;
}
int F_132 ( const T_1 * V_92 , int V_264 ,
struct V_65 * V_66 )
{
if ( ! V_92 || ! V_264 )
return 0 ;
memset ( V_66 , 0 , sizeof( struct V_65 ) ) ;
V_66 -> V_91 = ( V_92 [ 0 ] & 0x7f ) ;
if ( ! F_133 ( V_66 ) )
return 0 ;
if ( V_66 -> V_91 >= 0x72 ) {
if ( V_264 > 1 )
V_66 -> V_70 = ( V_92 [ 1 ] & 0xf ) ;
if ( V_264 > 2 )
V_66 -> V_72 = V_92 [ 2 ] ;
if ( V_264 > 3 )
V_66 -> V_73 = V_92 [ 3 ] ;
if ( V_264 > 7 )
V_66 -> V_93 = V_92 [ 7 ] ;
} else {
if ( V_264 > 2 )
V_66 -> V_70 = ( V_92 [ 2 ] & 0xf ) ;
if ( V_264 > 7 ) {
V_264 = ( V_264 < ( V_92 [ 7 ] + 8 ) ) ?
V_264 : ( V_92 [ 7 ] + 8 ) ;
if ( V_264 > 12 )
V_66 -> V_72 = V_92 [ 12 ] ;
if ( V_264 > 13 )
V_66 -> V_73 = V_92 [ 13 ] ;
}
}
return 1 ;
}
int F_41 ( struct V_16 * V_238 ,
struct V_65 * V_66 )
{
return F_132 ( V_238 -> V_92 ,
V_165 , V_66 ) ;
}
const T_1 * F_134 ( const T_1 * V_92 , int V_264 ,
int V_265 )
{
int V_266 , V_267 , V_268 , V_269 ;
const T_1 * V_270 ;
if ( ( V_264 < 8 ) || ( 0 == ( V_266 = V_92 [ 7 ] ) ) )
return NULL ;
if ( ( V_92 [ 0 ] < 0x72 ) || ( V_92 [ 0 ] > 0x73 ) )
return NULL ;
V_266 = ( V_266 < ( V_264 - 8 ) ) ?
V_266 : ( V_264 - 8 ) ;
V_270 = & V_92 [ 8 ] ;
for ( V_268 = 0 , V_269 = 0 ; V_269 < V_266 ; V_269 += V_268 ) {
V_270 += V_268 ;
V_267 = ( V_269 < ( V_266 - 1 ) ) ? V_270 [ 1 ] : - 1 ;
V_268 = V_267 + 2 ;
if ( V_270 [ 0 ] == V_265 )
return V_270 ;
if ( V_267 < 0 )
break;
}
return NULL ;
}
int F_135 ( const T_1 * V_92 , int V_264 ,
T_2 * V_271 )
{
int V_272 ;
const T_1 * V_273 ;
T_2 V_274 ;
if ( V_264 < 7 )
return 0 ;
switch ( V_92 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_92 [ 0 ] & 0x80 ) {
* V_271 = ( V_92 [ 3 ] << 24 ) +
( V_92 [ 4 ] << 16 ) +
( V_92 [ 5 ] << 8 ) + V_92 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_273 = F_134 ( V_92 , V_264 ,
0 ) ;
if ( V_273 && ( 0xa == V_273 [ 1 ] ) ) {
V_274 = 0 ;
for ( V_272 = 0 ; V_272 < 8 ; ++ V_272 ) {
if ( V_272 > 0 )
V_274 <<= 8 ;
V_274 |= V_273 [ 4 + V_272 ] ;
}
* V_271 = V_274 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
void F_136 ( int V_275 , T_1 * V_276 , T_1 V_277 , T_1 V_72 , T_1 V_73 )
{
if ( V_275 ) {
V_276 [ 0 ] = 0x72 ;
V_276 [ 1 ] = V_277 ;
V_276 [ 2 ] = V_72 ;
V_276 [ 3 ] = V_73 ;
V_276 [ 7 ] = 0 ;
} else {
V_276 [ 0 ] = 0x70 ;
V_276 [ 2 ] = V_277 ;
V_276 [ 7 ] = 0xa ;
V_276 [ 12 ] = V_72 ;
V_276 [ 13 ] = V_73 ;
}
}
