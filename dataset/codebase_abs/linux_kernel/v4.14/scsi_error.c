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
F_21 ( V_18 ) ;
}
static int
F_22 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_24 ;
unsigned long V_7 ;
if ( V_18 -> V_33 & V_34 ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_11 ) ) ;
F_23 ( F_24 ( & V_18 -> V_19 ) ) ;
return V_35 ;
}
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_13 != - 1 && ! V_2 -> V_12 )
V_2 -> V_12 = V_14 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
V_18 -> V_33 |= V_34 ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 , L_12 ) ) ;
F_25 ( V_2 -> V_36 , & V_18 -> V_19 , V_37 / 100 ) ;
return V_26 ;
}
static void F_26 ( struct V_17 * V_18 )
{
if ( ! F_27 ( V_18 -> V_38 ) ) {
struct V_39 * V_40 = F_28 ( V_18 ) ;
if ( V_40 -> V_41 )
V_40 -> V_41 ( V_18 ) ;
}
}
void F_21 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_22 -> V_24 ;
unsigned long V_7 ;
int V_42 ;
F_29 ( ! V_2 -> V_5 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_9 ) ) {
V_42 = F_9 ( V_2 , V_10 ) ;
F_29 ( V_42 ) ;
}
if ( V_2 -> V_13 != - 1 && ! V_2 -> V_12 )
V_2 -> V_12 = V_14 ;
F_26 ( V_18 ) ;
F_30 ( & V_18 -> V_43 , & V_2 -> V_44 ) ;
V_2 -> V_4 ++ ;
F_1 ( V_2 ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
}
enum V_45 F_31 ( struct V_38 * V_46 )
{
struct V_17 * V_18 = F_32 ( V_46 ) ;
enum V_45 V_23 = V_47 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
F_33 ( V_18 ) ;
F_34 ( V_18 , V_48 ) ;
if ( V_24 -> V_13 != - 1 && ! V_24 -> V_12 )
V_24 -> V_12 = V_14 ;
if ( V_24 -> V_25 -> V_49 )
V_23 = V_24 -> V_25 -> V_49 ( V_18 ) ;
if ( V_23 == V_47 ) {
if ( F_22 ( V_18 ) != V_26 ) {
F_17 ( V_18 , V_27 ) ;
F_21 ( V_18 ) ;
}
}
return V_23 ;
}
int F_35 ( struct V_20 * V_21 )
{
int V_50 ;
F_36 ( V_21 -> V_24 -> V_51 , ! F_37 ( V_21 -> V_24 ) ) ;
V_50 = F_38 ( V_21 ) ;
F_5 ( 5 , F_39 ( V_6 , V_21 ,
L_13 , V_52 , V_50 ) ) ;
return V_50 ;
}
static inline void F_40 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_55 = 0 ;
int V_56 = 0 ;
int V_57 = 0 ;
int V_58 = 0 ;
F_41 (sdev, shost) {
F_42 (scmd, work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 ) {
++ V_55 ;
if ( V_18 -> V_33 & V_34 )
++ V_57 ;
else
++ V_56 ;
}
}
if ( V_57 || V_56 ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_14 ,
V_52 , V_56 ,
V_57 ) ) ;
V_57 = 0 ;
V_56 = 0 ;
++ V_58 ;
}
}
F_5 ( 2 , F_6 ( V_6 , V_2 ,
L_15
L_16 ,
V_55 , V_58 ) ) ;
}
static void F_43 ( struct V_20 * V_21 )
{
V_21 -> V_59 -> V_60 = 1 ;
}
static void F_44 ( struct V_20 * V_21 ,
struct V_61 * V_62 )
{
enum V_63 V_64 = V_65 ;
if ( V_62 -> V_66 == V_67 ) {
if ( V_62 -> V_68 == 0x3f && V_62 -> V_69 == 0x03 ) {
V_64 = V_70 ;
F_39 ( V_30 , V_21 ,
L_17 ) ;
} else if ( V_62 -> V_68 == 0x3f && V_62 -> V_69 == 0x0e ) {
V_64 = V_71 ;
F_43 ( V_21 ) ;
F_39 ( V_30 , V_21 ,
L_18
L_19
L_20
L_21 ) ;
} else if ( V_62 -> V_68 == 0x3f )
F_39 ( V_30 , V_21 ,
L_18
L_22
L_20
L_23 ) ;
if ( V_62 -> V_68 == 0x38 && V_62 -> V_69 == 0x07 ) {
V_64 = V_72 ;
F_39 ( V_30 , V_21 ,
L_18
L_24
L_25 ) ;
}
if ( V_62 -> V_68 == 0x2a && V_62 -> V_69 == 0x01 ) {
V_64 = V_73 ;
F_39 ( V_30 , V_21 ,
L_26 ) ;
} else if ( V_62 -> V_68 == 0x2a && V_62 -> V_69 == 0x06 ) {
V_64 = V_74 ;
F_39 ( V_30 , V_21 ,
L_27 ) ;
} else if ( V_62 -> V_68 == 0x2a && V_62 -> V_69 == 0x09 ) {
V_64 = V_75 ;
F_39 ( V_30 , V_21 ,
L_28 ) ;
} else if ( V_62 -> V_68 == 0x2a )
F_39 ( V_30 , V_21 ,
L_29 ) ;
}
if ( V_64 != V_65 ) {
F_45 ( V_64 , V_21 -> V_76 ) ;
F_46 ( & V_21 -> V_77 ) ;
}
}
int F_47 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_61 V_62 ;
if ( ! F_48 ( V_18 , & V_62 ) )
return V_35 ;
F_44 ( V_21 , & V_62 ) ;
if ( F_49 ( & V_62 ) )
return V_78 ;
if ( V_21 -> V_79 && V_21 -> V_79 -> V_80 ) {
int V_81 ;
V_81 = V_21 -> V_79 -> V_80 ( V_21 , & V_62 ) ;
if ( V_81 != V_82 )
return V_81 ;
}
if ( V_18 -> V_83 [ 0 ] == V_84 && V_18 -> V_85 != V_86 )
return V_26 ;
if ( V_62 . V_87 == 0x70 ) {
if ( V_18 -> V_88 [ 2 ] & 0xe0 )
return V_26 ;
} else {
if ( ( V_62 . V_89 > 3 ) &&
( V_18 -> V_88 [ 8 ] == 0x4 ) &&
( V_18 -> V_88 [ 11 ] & 0xe0 ) )
return V_26 ;
}
switch ( V_62 . V_66 ) {
case V_90 :
return V_26 ;
case V_91 :
return V_26 ;
case V_92 :
if ( V_62 . V_68 == 0x10 )
return V_26 ;
return V_78 ;
case V_93 :
case V_67 :
if ( V_18 -> V_22 -> V_94 ) {
if ( V_62 . V_68 != 0x28 || V_62 . V_69 != 0x00 ) {
V_18 -> V_22 -> V_94 = 0 ;
return V_78 ;
}
}
if ( V_18 -> V_22 -> V_59 -> V_60 &&
V_62 . V_68 == 0x3f && V_62 . V_69 == 0x0e )
return V_78 ;
if ( ( V_62 . V_68 == 0x04 ) && ( V_62 . V_69 == 0x01 ) )
return V_78 ;
if ( V_18 -> V_22 -> V_95 &&
( V_62 . V_68 == 0x04 ) && ( V_62 . V_69 == 0x02 ) )
return V_35 ;
return V_26 ;
case V_96 :
if ( V_62 . V_68 == 0x27 && V_62 . V_69 == 0x07 ) {
F_17 ( V_18 , V_97 ) ;
return V_26 ;
}
case V_98 :
case V_99 :
case V_100 :
case V_101 :
F_17 ( V_18 , V_102 ) ;
return V_26 ;
case V_103 :
if ( V_62 . V_68 == 0x11 ||
V_62 . V_68 == 0x13 ||
V_62 . V_68 == 0x14 ) {
F_17 ( V_18 , V_104 ) ;
return V_26 ;
}
return V_78 ;
case V_105 :
if ( V_18 -> V_22 -> V_106 )
return V_107 ;
else
F_17 ( V_18 , V_102 ) ;
case V_108 :
if ( V_62 . V_68 == 0x20 ||
V_62 . V_68 == 0x21 ||
V_62 . V_68 == 0x24 ||
V_62 . V_68 == 0x26 ||
V_62 . V_68 == 0x27 ) {
F_17 ( V_18 , V_102 ) ;
}
return V_26 ;
default:
return V_26 ;
}
}
static void F_50 ( struct V_20 * V_21 )
{
struct V_109 * V_110 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_111 ;
if ( ! V_110 -> V_112 ||
V_21 -> V_113 >= V_21 -> V_114 )
return;
if ( F_12 ( V_14 ,
V_21 -> V_115 + V_21 -> V_116 ) )
return;
if ( F_12 ( V_14 ,
V_21 -> V_117 + V_21 -> V_116 ) )
return;
F_41 (tmp_sdev, sdev->host) {
if ( V_111 -> V_118 != V_21 -> V_118 ||
V_111 -> V_119 != V_21 -> V_119 ||
V_111 -> V_113 == V_21 -> V_114 )
continue;
F_51 ( V_111 , V_111 -> V_113 + 1 ) ;
V_21 -> V_115 = V_14 ;
}
}
static void F_52 ( struct V_20 * V_21 )
{
struct V_109 * V_110 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_111 ;
if ( ! V_110 -> V_112 )
return;
F_41 (tmp_sdev, sdev->host) {
if ( V_111 -> V_118 != V_21 -> V_118 ||
V_111 -> V_119 != V_21 -> V_119 )
continue;
F_53 ( V_111 , V_111 -> V_113 - 1 ) ;
}
}
static int F_54 ( struct V_17 * V_18 )
{
if ( F_55 ( V_18 -> V_120 ) == V_121 ) {
return F_47 ( V_18 ) ;
}
if ( F_55 ( V_18 -> V_120 ) != V_122 )
return V_35 ;
if ( F_56 ( V_18 -> V_120 ) != V_123 )
return V_35 ;
switch ( F_57 ( V_18 -> V_120 ) ) {
case V_124 :
F_50 ( V_18 -> V_22 ) ;
case V_125 :
return V_26 ;
case V_126 :
return F_47 ( V_18 ) ;
case V_127 :
case V_128 :
case V_129 :
return V_26 ;
case V_130 :
if ( V_18 -> V_83 [ 0 ] == V_84 )
return V_26 ;
return V_35 ;
case V_131 :
F_52 ( V_18 -> V_22 ) ;
case V_132 :
return V_78 ;
default:
return V_35 ;
}
return V_35 ;
}
static void V_86 ( struct V_17 * V_18 )
{
struct V_133 * V_134 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_30 , V_52 , V_18 -> V_120 ) ) ;
V_134 = V_18 -> V_22 -> V_24 -> V_134 ;
if ( V_134 )
F_58 ( V_134 ) ;
}
static int F_59 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_109 * V_25 = V_24 -> V_25 ;
F_5 ( 3 ,
F_6 ( V_6 , V_24 , L_31 ) ) ;
if ( ! V_25 -> V_135 )
return V_35 ;
V_23 = V_25 -> V_135 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_136 )
F_60 ( V_137 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_61 ( V_24 , F_62 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_63 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_109 * V_25 = V_24 -> V_25 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_32 , V_52 ) ) ;
if ( ! V_25 -> V_138 )
return V_35 ;
V_23 = V_25 -> V_138 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_136 )
F_60 ( V_139 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_61 ( V_24 , F_62 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static void F_64 ( struct V_20 * V_21 , void * V_140 )
{
V_21 -> V_141 = 1 ;
V_21 -> V_94 = 1 ;
}
static int F_65 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_109 * V_25 = V_24 -> V_25 ;
if ( ! V_25 -> V_142 )
return V_35 ;
V_23 = V_25 -> V_142 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_8 ( V_24 -> V_8 , V_7 ) ;
F_66 ( F_67 ( V_18 -> V_22 ) , NULL ,
F_64 ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_68 ( struct V_17 * V_18 )
{
int V_23 ;
struct V_109 * V_25 = V_18 -> V_22 -> V_24 -> V_25 ;
if ( ! V_25 -> V_143 )
return V_35 ;
V_23 = V_25 -> V_143 ( V_18 ) ;
if ( V_23 == V_26 )
F_64 ( V_18 -> V_22 , NULL ) ;
return V_23 ;
}
static int F_16 ( struct V_109 * V_25 ,
struct V_17 * V_18 )
{
if ( ! V_25 -> V_144 )
return V_35 ;
return V_25 -> V_144 ( V_18 ) ;
}
static void F_69 ( struct V_17 * V_18 )
{
if ( F_16 ( V_18 -> V_22 -> V_24 -> V_25 , V_18 ) != V_26 )
if ( F_68 ( V_18 ) != V_26 )
if ( F_65 ( V_18 ) != V_26 )
if ( F_63 ( V_18 ) != V_26 )
F_59 ( V_18 ) ;
}
void F_70 ( struct V_17 * V_18 , struct V_145 * V_146 ,
unsigned char * V_83 , int V_147 , unsigned V_148 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
V_146 -> V_149 = V_18 -> V_149 ;
V_146 -> V_83 = V_18 -> V_83 ;
V_146 -> V_150 = V_18 -> V_151 ;
V_146 -> V_152 = V_18 -> V_152 ;
V_146 -> V_153 = V_18 -> V_38 -> V_153 ;
V_146 -> V_120 = V_18 -> V_120 ;
V_146 -> V_154 = V_18 -> V_154 ;
V_146 -> V_155 = V_18 -> V_155 ;
V_146 -> V_33 = V_18 -> V_33 ;
V_18 -> V_155 = V_156 ;
V_18 -> V_33 = 0 ;
V_18 -> V_83 = V_146 -> V_157 ;
memset ( V_18 -> V_83 , 0 , V_158 ) ;
memset ( & V_18 -> V_152 , 0 , sizeof( V_18 -> V_152 ) ) ;
V_18 -> V_38 -> V_153 = NULL ;
V_18 -> V_120 = 0 ;
if ( V_148 ) {
V_18 -> V_152 . V_159 = F_71 ( unsigned , V_160 ,
V_148 ) ;
F_72 ( & V_146 -> V_161 , V_18 -> V_88 ,
V_18 -> V_152 . V_159 ) ;
V_18 -> V_152 . V_162 . V_163 = & V_146 -> V_161 ;
V_18 -> V_151 = V_164 ;
V_18 -> V_152 . V_162 . V_165 = V_18 -> V_152 . V_162 . V_166 = 1 ;
V_18 -> V_83 [ 0 ] = V_167 ;
V_18 -> V_83 [ 4 ] = V_18 -> V_152 . V_159 ;
V_18 -> V_149 = F_73 ( V_18 -> V_83 [ 0 ] ) ;
} else {
V_18 -> V_151 = V_168 ;
if ( V_83 ) {
F_23 ( V_147 > V_158 ) ;
memcpy ( V_18 -> V_83 , V_83 , V_147 ) ;
V_18 -> V_149 = F_73 ( V_18 -> V_83 [ 0 ] ) ;
}
}
V_18 -> V_154 = 0 ;
if ( V_21 -> V_169 <= V_170 && V_21 -> V_169 != V_171 )
V_18 -> V_83 [ 1 ] = ( V_18 -> V_83 [ 1 ] & 0x1f ) |
( V_21 -> V_172 << 5 & 0xe0 ) ;
memset ( V_18 -> V_88 , 0 , V_160 ) ;
}
void F_74 ( struct V_17 * V_18 , struct V_145 * V_146 )
{
V_18 -> V_149 = V_146 -> V_149 ;
V_18 -> V_83 = V_146 -> V_83 ;
V_18 -> V_151 = V_146 -> V_150 ;
V_18 -> V_152 = V_146 -> V_152 ;
V_18 -> V_38 -> V_153 = V_146 -> V_153 ;
V_18 -> V_120 = V_146 -> V_120 ;
V_18 -> V_154 = V_146 -> V_154 ;
V_18 -> V_155 = V_146 -> V_155 ;
V_18 -> V_33 = V_146 -> V_33 ;
}
static int F_75 ( struct V_17 * V_18 , unsigned char * V_83 ,
int V_147 , int V_173 , unsigned V_148 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_24 ;
F_76 ( V_174 ) ;
unsigned long V_175 = V_173 ;
struct V_145 V_146 ;
const unsigned long V_176 = F_77 ( 100 ) ;
int V_23 ;
V_177:
F_70 ( V_18 , & V_146 , V_83 , V_147 , V_148 ) ;
V_2 -> V_134 = & V_174 ;
F_78 ( V_18 ) ;
V_18 -> V_85 = V_86 ;
V_23 = V_2 -> V_25 -> V_178 ( V_2 , V_18 ) ;
if ( V_23 ) {
if ( V_175 > V_176 ) {
F_74 ( V_18 , & V_146 ) ;
V_175 -= V_176 ;
F_79 ( F_80 ( V_176 ) ) ;
goto V_177;
}
V_175 = 0 ;
V_23 = V_35 ;
} else {
V_175 = F_81 ( & V_174 , V_173 ) ;
V_23 = V_26 ;
}
V_2 -> V_134 = NULL ;
F_34 ( V_18 , V_23 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_33 ,
V_52 , V_175 ) ) ;
if ( V_175 ) {
V_23 = F_54 ( V_18 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_34 , V_52 , V_23 ) ) ;
switch ( V_23 ) {
case V_26 :
case V_78 :
case V_35 :
break;
case V_107 :
V_23 = V_78 ;
break;
default:
V_23 = V_35 ;
break;
}
} else if ( V_23 != V_35 ) {
F_69 ( V_18 ) ;
V_23 = V_35 ;
}
F_74 ( V_18 , & V_146 ) ;
return V_23 ;
}
static int F_82 ( struct V_17 * V_18 )
{
return F_75 ( V_18 , NULL , 0 , V_18 -> V_22 -> V_179 , ~ 0 ) ;
}
static int F_83 ( struct V_17 * V_18 , int V_23 )
{
if ( ! F_27 ( V_18 -> V_38 ) ) {
struct V_39 * V_40 = F_28 ( V_18 ) ;
if ( V_40 -> V_134 )
V_23 = V_40 -> V_134 ( V_18 , V_23 ) ;
}
return V_23 ;
}
void F_84 ( struct V_17 * V_18 , struct V_53 * V_180 )
{
F_85 ( & V_18 -> V_43 , V_180 ) ;
}
int F_86 ( struct V_53 * V_54 ,
struct V_53 * V_180 )
{
struct V_17 * V_18 , * V_181 ;
struct V_1 * V_2 ;
int V_23 ;
F_87 (scmd, next, work_q, eh_entry) {
if ( ( V_18 -> V_33 & V_34 ) ||
F_88 ( V_18 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_35 ,
V_182 -> V_183 ) ) ;
break;
}
if ( F_57 ( V_18 -> V_120 ) != V_126 )
continue;
F_5 ( 2 , F_15 ( V_6 , V_18 ,
L_36 ,
V_182 -> V_183 ) ) ;
V_23 = F_82 ( V_18 ) ;
if ( V_23 != V_26 )
continue;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_37 , V_18 -> V_120 ) ) ;
F_5 ( 3 , F_89 ( V_18 ) ) ;
V_23 = F_90 ( V_18 ) ;
if ( V_23 == V_26 )
V_18 -> V_28 = V_18 -> V_29 ;
else if ( V_23 != V_78 )
continue;
F_84 ( V_18 , V_180 ) ;
}
return F_91 ( V_54 ) ;
}
static int F_92 ( struct V_17 * V_18 )
{
static unsigned char V_184 [ 6 ] = { V_84 , 0 , 0 , 0 , 0 , 0 } ;
int V_185 = 1 , V_23 ;
V_186:
V_23 = F_75 ( V_18 , V_184 , 6 ,
V_18 -> V_22 -> V_179 , 0 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_38 , V_52 , V_23 ) ) ;
switch ( V_23 ) {
case V_78 :
if ( V_185 -- )
goto V_186;
case V_26 :
return 0 ;
default:
return 1 ;
}
}
static int F_93 ( struct V_53 * V_187 ,
struct V_53 * V_54 ,
struct V_53 * V_180 , int V_188 )
{
struct V_17 * V_18 , * V_181 ;
struct V_20 * V_21 ;
int V_189 ;
while ( ! F_91 ( V_187 ) ) {
V_18 = F_94 ( V_187 -> V_181 , struct V_17 , V_43 ) ;
V_21 = V_18 -> V_22 ;
if ( ! V_188 ) {
if ( F_11 ( V_21 -> V_24 ) ) {
F_95 ( V_187 , V_54 ) ;
F_5 ( 3 ,
F_39 ( V_6 , V_21 ,
L_39 ,
V_182 -> V_183 ) ) ;
break;
}
}
V_189 = ! F_38 ( V_18 -> V_22 ) ||
( V_188 && ! F_96 ( V_18 ) &&
! F_92 ( V_18 ) ) ||
! F_92 ( V_18 ) ;
F_87 (scmd, next, cmd_list, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
if ( V_189 &&
( V_188 ||
F_83 ( V_18 , V_26 ) == V_26 ) )
F_84 ( V_18 , V_180 ) ;
else
F_85 ( & V_18 -> V_43 , V_54 ) ;
}
}
return F_91 ( V_54 ) ;
}
static int F_96 ( struct V_17 * V_18 )
{
static unsigned char V_190 [ 6 ] = { V_191 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_18 -> V_22 -> V_95 ) {
int V_192 , V_23 = V_78 ;
for ( V_192 = 0 ; V_23 == V_78 && V_192 < 2 ; V_192 ++ )
V_23 = F_75 ( V_18 , V_190 , 6 , V_18 -> V_22 -> V_193 -> V_194 , 0 ) ;
if ( V_23 == V_26 )
return 0 ;
}
return 1 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_53 * V_180 )
{
struct V_17 * V_18 , * V_195 , * V_181 ;
struct V_20 * V_21 ;
F_41 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_39 ( V_6 , V_21 ,
L_40 ,
V_182 -> V_183 ) ) ;
break;
}
V_195 = NULL ;
F_42 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 && F_88 ( V_18 ) &&
F_47 ( V_18 ) == V_35 ) {
V_195 = V_18 ;
break;
}
if ( ! V_195 )
continue;
F_5 ( 3 ,
F_39 ( V_6 , V_21 ,
L_41 ,
V_182 -> V_183 ) ) ;
if ( ! F_96 ( V_195 ) ) {
if ( ! F_38 ( V_21 ) ||
! F_92 ( V_195 ) ) {
F_87 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_83 ( V_18 , V_26 ) == V_26 )
F_84 ( V_18 , V_180 ) ;
}
}
} else {
F_5 ( 3 ,
F_39 ( V_6 , V_21 ,
L_42 ,
V_182 -> V_183 ) ) ;
}
}
return F_91 ( V_54 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_53 * V_180 )
{
struct V_17 * V_18 , * V_196 , * V_181 ;
struct V_20 * V_21 ;
int V_23 ;
F_41 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_39 ( V_6 , V_21 ,
L_43 ,
V_182 -> V_183 ) ) ;
break;
}
V_196 = NULL ;
F_42 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
V_196 = V_18 ;
break;
}
if ( ! V_196 )
continue;
F_5 ( 3 ,
F_39 ( V_6 , V_21 ,
L_44 , V_182 -> V_183 ) ) ;
V_23 = F_68 ( V_196 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
if ( ! F_38 ( V_21 ) ||
V_23 == V_32 ||
! F_92 ( V_196 ) ) {
F_87 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_83 ( V_18 , V_23 ) != V_35 )
F_84 ( V_18 ,
V_180 ) ;
}
}
} else {
F_5 ( 3 ,
F_39 ( V_6 , V_21 ,
L_45 , V_182 -> V_183 ) ) ;
}
}
return F_91 ( V_54 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_53 * V_180 )
{
F_100 ( V_197 ) ;
F_100 ( V_198 ) ;
F_95 ( V_54 , & V_197 ) ;
while ( ! F_91 ( & V_197 ) ) {
struct V_17 * V_181 , * V_18 ;
int V_23 ;
unsigned int V_119 ;
if ( F_11 ( V_2 ) ) {
F_95 ( & V_198 , V_54 ) ;
F_95 ( & V_197 , V_54 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_46 ,
V_182 -> V_183 ) ) ;
return F_91 ( V_54 ) ;
}
V_18 = F_94 ( V_197 . V_181 , struct V_17 , V_43 ) ;
V_119 = F_101 ( V_18 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_47 ,
V_182 -> V_183 , V_119 ) ) ;
V_23 = F_65 ( V_18 ) ;
if ( V_23 != V_26 && V_23 != V_32 )
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_48
L_49 ,
V_182 -> V_183 , V_119 ) ) ;
F_87 (scmd, next, &tmp_list, eh_entry) {
if ( F_101 ( V_18 ) != V_119 )
continue;
if ( V_23 == V_26 )
F_85 ( & V_18 -> V_43 , & V_198 ) ;
else if ( V_23 == V_32 )
F_84 ( V_18 , V_180 ) ;
else
F_102 ( & V_18 -> V_43 , V_54 ) ;
}
}
return F_93 ( & V_198 , V_54 , V_180 , 0 ) ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_53 * V_180 )
{
struct V_17 * V_18 , * V_199 , * V_181 ;
F_100 ( V_198 ) ;
unsigned int V_118 ;
int V_23 ;
for ( V_118 = 0 ; V_118 <= V_2 -> V_200 ; V_118 ++ ) {
if ( F_11 ( V_2 ) ) {
F_95 ( & V_198 , V_54 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_50 ,
V_182 -> V_183 ) ) ;
return F_91 ( V_54 ) ;
}
V_199 = NULL ;
F_42 (scmd, work_q, eh_entry) {
if ( V_118 == F_62 ( V_18 ) ) {
V_199 = V_18 ;
break;
}
}
if ( ! V_199 )
continue;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_51 ,
V_182 -> V_183 , V_118 ) ) ;
V_23 = F_63 ( V_199 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
F_87 (scmd, next, work_q, eh_entry) {
if ( V_118 == F_62 ( V_18 ) ) {
if ( V_23 == V_32 )
F_84 ( V_18 ,
V_180 ) ;
else
F_85 ( & V_18 -> V_43 ,
& V_198 ) ;
}
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_52 ,
V_182 -> V_183 , V_118 ) ) ;
}
}
return F_93 ( & V_198 , V_54 , V_180 , 0 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_53 * V_180 )
{
struct V_17 * V_18 , * V_181 ;
F_100 ( V_198 ) ;
int V_23 ;
if ( ! F_91 ( V_54 ) ) {
V_18 = F_94 ( V_54 -> V_181 ,
struct V_17 , V_43 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_53 ,
V_182 -> V_183 ) ) ;
V_23 = F_59 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_95 ( V_54 , & V_198 ) ;
} else if ( V_23 == V_32 ) {
F_87 (scmd, next, work_q, eh_entry) {
F_84 ( V_18 , V_180 ) ;
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_54 ,
V_182 -> V_183 ) ) ;
}
}
return F_93 ( & V_198 , V_54 , V_180 , 1 ) ;
}
static void F_105 ( struct V_53 * V_54 ,
struct V_53 * V_180 )
{
struct V_17 * V_18 , * V_181 ;
struct V_20 * V_21 ;
F_87 (scmd, next, work_q, eh_entry) {
F_39 ( V_6 , V_18 -> V_22 , L_55
L_56 ) ;
V_21 = V_18 -> V_22 ;
F_106 ( & V_21 -> V_201 ) ;
F_107 ( V_21 , V_202 ) ;
F_108 ( & V_21 -> V_201 ) ;
F_84 ( V_18 , V_180 ) ;
}
return;
}
int F_18 ( struct V_17 * V_18 )
{
switch ( F_55 ( V_18 -> V_120 ) ) {
case V_122 :
break;
case V_27 :
goto V_203;
case V_204 :
return ( V_18 -> V_38 -> V_205 & V_206 ) ;
case V_207 :
return ( V_18 -> V_38 -> V_205 & V_208 ) ;
case V_209 :
if ( F_56 ( V_18 -> V_120 ) == V_123 &&
F_57 ( V_18 -> V_120 ) == V_130 )
return 0 ;
case V_210 :
return ( V_18 -> V_38 -> V_205 & V_211 ) ;
}
if ( F_57 ( V_18 -> V_120 ) != V_126 )
return 0 ;
V_203:
if ( V_18 -> V_38 -> V_205 & V_208 ||
F_27 ( V_18 -> V_38 ) )
return 1 ;
else
return 0 ;
}
int F_90 ( struct V_17 * V_18 )
{
int V_23 ;
if ( ! F_38 ( V_18 -> V_22 ) ) {
F_5 ( 5 , F_15 ( V_6 , V_18 ,
L_57 , V_52 ) ) ;
return V_26 ;
}
switch ( F_55 ( V_18 -> V_120 ) ) {
case V_212 :
V_18 -> V_120 &= 0xff00ffff ;
return V_26 ;
case V_122 :
break;
case V_213 :
if ( V_18 -> V_33 & V_34 ) {
F_17 ( V_18 , V_27 ) ;
return V_26 ;
}
case V_214 :
case V_215 :
return V_26 ;
case V_210 :
goto V_216;
case V_217 :
return V_78 ;
case V_218 :
return V_107 ;
case V_219 :
goto V_216;
case V_220 :
return V_26 ;
case V_209 :
if ( F_56 ( V_18 -> V_120 ) == V_123 &&
F_57 ( V_18 -> V_120 ) == V_130 )
break;
case V_204 :
case V_207 :
goto V_216;
case V_27 :
if ( ( V_18 -> V_83 [ 0 ] == V_84 ||
V_18 -> V_83 [ 0 ] == V_221 ) ) {
return V_26 ;
} else {
return V_35 ;
}
case V_121 :
return V_26 ;
default:
return V_35 ;
}
if ( F_56 ( V_18 -> V_120 ) != V_123 )
return V_35 ;
switch ( F_57 ( V_18 -> V_120 ) ) {
case V_131 :
F_52 ( V_18 -> V_22 ) ;
case V_132 :
return V_107 ;
case V_124 :
if ( V_18 -> V_83 [ 0 ] == V_222 )
V_18 -> V_22 -> V_59 -> V_60 = 0 ;
F_50 ( V_18 -> V_22 ) ;
case V_125 :
return V_26 ;
case V_223 :
goto V_216;
case V_126 :
V_23 = F_47 ( V_18 ) ;
if ( V_23 == V_78 )
goto V_216;
return V_23 ;
case V_127 :
case V_128 :
case V_129 :
case V_224 :
return V_26 ;
case V_130 :
F_39 ( V_6 , V_18 -> V_22 ,
L_58 ) ;
F_17 ( V_18 , V_225 ) ;
return V_26 ;
default:
return V_35 ;
}
return V_35 ;
V_216:
if ( ( ++ V_18 -> V_28 ) <= V_18 -> V_29
&& ! F_18 ( V_18 ) ) {
return V_78 ;
} else {
return V_26 ;
}
}
static void F_109 ( struct V_38 * V_46 , T_1 V_226 )
{
F_110 ( V_46 -> V_227 , V_46 ) ;
}
static void F_111 ( struct V_20 * V_21 )
{
struct V_38 * V_46 ;
struct V_228 * V_229 ;
V_46 = F_112 ( V_21 -> V_193 , V_230 , V_231 ) ;
if ( F_113 ( V_46 ) )
return;
V_229 = F_114 ( V_46 ) ;
V_229 -> V_232 [ 0 ] = V_233 ;
V_229 -> V_232 [ 1 ] = 0 ;
V_229 -> V_232 [ 2 ] = 0 ;
V_229 -> V_232 [ 3 ] = 0 ;
V_229 -> V_232 [ 4 ] = V_234 ;
V_229 -> V_232 [ 5 ] = 0 ;
V_229 -> V_149 = F_73 ( V_229 -> V_232 [ 0 ] ) ;
V_46 -> V_235 |= V_236 ;
V_46 -> V_173 = 10 * V_37 ;
V_229 -> V_28 = 5 ;
F_115 ( V_46 -> V_227 , NULL , V_46 , 1 , F_109 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned long V_7 ;
F_41 (sdev, shost) {
if ( F_38 ( V_21 ) && V_21 -> V_141 && V_21 -> V_237 ) {
F_111 ( V_21 ) ;
V_21 -> V_141 = 0 ;
}
}
F_5 ( 3 ,
F_6 ( V_6 , V_2 , L_59 ) ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_238 ) )
if ( F_9 ( V_2 , V_239 ) )
F_23 ( F_9 ( V_2 , V_240 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_117 ( & V_2 -> V_51 ) ;
F_118 ( V_2 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_11 )
if ( F_9 ( V_2 , V_9 ) )
F_119 ( F_9 ( V_2 , V_10 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
}
void F_120 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_53 * V_180 )
{
if ( ! F_97 ( V_2 , V_54 , V_180 ) )
if ( ! F_98 ( V_2 , V_54 , V_180 ) )
if ( ! F_99 ( V_2 , V_54 , V_180 ) )
if ( ! F_103 ( V_2 , V_54 , V_180 ) )
if ( ! F_104 ( V_2 , V_54 , V_180 ) )
F_105 ( V_54 ,
V_180 ) ;
}
void F_121 ( struct V_53 * V_180 )
{
struct V_17 * V_18 , * V_181 ;
F_87 (scmd, next, done_q, eh_entry) {
F_122 ( & V_18 -> V_43 ) ;
if ( F_38 ( V_18 -> V_22 ) &&
! F_18 ( V_18 ) &&
( ++ V_18 -> V_28 <= V_18 -> V_29 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_60 ,
V_182 -> V_183 ) ) ;
F_19 ( V_18 , V_31 ) ;
} else {
if ( ! V_18 -> V_120 )
V_18 -> V_120 |= ( V_241 << 24 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_61 ,
V_182 -> V_183 ) ) ;
F_20 ( V_18 ) ;
}
}
}
static void F_123 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_100 ( V_242 ) ;
F_100 ( V_243 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
F_95 ( & V_2 -> V_44 , & V_242 ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 1 , F_40 ( V_2 , & V_242 ) ) ;
if ( ! F_86 ( & V_242 , & V_243 ) )
F_120 ( V_2 , & V_242 , & V_243 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_13 != - 1 )
V_2 -> V_12 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_121 ( & V_243 ) ;
}
int F_124 ( void * V_140 )
{
struct V_1 * V_2 = V_140 ;
while ( true ) {
F_125 ( V_244 ) ;
if ( F_126 () )
break;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_11 == 0 ) ||
V_2 -> V_4 != F_2 ( & V_2 -> V_3 ) ) {
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_62 ,
V_2 -> V_245 ) ) ;
F_127 () ;
continue;
}
F_128 ( V_246 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_63 ,
V_2 -> V_245 , V_2 -> V_11 ,
V_2 -> V_4 ,
F_2 ( & V_2 -> V_3 ) ) ) ;
if ( ! V_2 -> V_247 && F_129 ( V_2 ) != 0 ) {
F_5 ( 1 ,
F_6 ( V_248 , V_2 ,
L_64 ,
V_2 -> V_245 ) ) ;
continue;
}
if ( V_2 -> V_249 -> V_250 )
V_2 -> V_249 -> V_250 ( V_2 ) ;
else
F_123 ( V_2 ) ;
V_2 -> V_4 = 0 ;
F_116 ( V_2 ) ;
if ( ! V_2 -> V_247 )
F_130 ( V_2 ) ;
}
F_128 ( V_246 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_65 ,
V_2 -> V_245 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 , int V_118 )
{
struct V_20 * V_21 ;
F_131 (sdev, shost) {
if ( V_118 == F_132 ( V_21 ) )
F_64 ( V_21 , NULL ) ;
}
}
void F_133 ( struct V_1 * V_2 , int V_118 , int V_251 )
{
struct V_20 * V_21 ;
F_131 (sdev, shost) {
if ( V_118 == F_132 ( V_21 ) &&
V_251 == F_134 ( V_21 ) )
F_64 ( V_21 , NULL ) ;
}
}
static void
F_135 ( struct V_17 * V_18 )
{
}
int
F_136 ( struct V_20 * V_252 , int T_2 * V_253 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = V_252 -> V_24 ;
struct V_38 * V_229 ;
unsigned long V_7 ;
int error = 0 , V_23 , V_254 ;
if ( ! F_137 ( V_255 ) || ! F_137 ( V_256 ) )
return - V_257 ;
error = F_138 ( V_254 , V_253 ) ;
if ( error )
return error ;
if ( F_129 ( V_2 ) < 0 )
return - V_258 ;
error = - V_258 ;
V_229 = F_139 ( sizeof( struct V_38 ) + sizeof( struct V_17 ) +
V_2 -> V_25 -> V_259 , V_231 ) ;
if ( ! V_229 )
goto V_260;
F_140 ( NULL , V_229 ) ;
V_18 = (struct V_17 * ) ( V_229 + 1 ) ;
F_141 ( V_252 , V_18 ) ;
V_18 -> V_38 = V_229 ;
V_18 -> V_83 = F_114 ( V_229 ) -> V_232 ;
V_18 -> V_85 = F_135 ;
memset ( & V_18 -> V_152 , 0 , sizeof( V_18 -> V_152 ) ) ;
V_18 -> V_149 = 0 ;
V_18 -> V_151 = V_261 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_262 = 1 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
switch ( V_254 & ~ V_263 ) {
case V_264 :
V_23 = V_26 ;
break;
case V_265 :
V_23 = F_68 ( V_18 ) ;
if ( V_23 == V_26 || ( V_254 & V_263 ) )
break;
case V_266 :
V_23 = F_65 ( V_18 ) ;
if ( V_23 == V_26 || ( V_254 & V_263 ) )
break;
case V_267 :
V_23 = F_63 ( V_18 ) ;
if ( V_23 == V_26 || ( V_254 & V_263 ) )
break;
case V_268 :
V_23 = F_59 ( V_18 ) ;
if ( V_23 == V_26 )
break;
default:
V_23 = V_35 ;
break;
}
error = ( V_23 == V_26 ) ? 0 : - V_258 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_262 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_66 ) ) ;
F_117 ( & V_2 -> V_51 ) ;
F_118 ( V_2 ) ;
F_142 ( V_18 ) ;
F_143 ( V_229 ) ;
V_260:
F_130 ( V_2 ) ;
return error ;
}
bool F_48 ( const struct V_17 * V_232 ,
struct V_61 * V_62 )
{
return F_144 ( V_232 -> V_88 ,
V_160 , V_62 ) ;
}
bool F_145 ( const T_3 * V_88 , int V_269 ,
T_4 * V_270 )
{
const T_3 * V_271 ;
if ( V_269 < 7 )
return false ;
switch ( V_88 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_88 [ 0 ] & 0x80 ) {
* V_270 = F_146 ( & V_88 [ 3 ] ) ;
return true ;
}
return false ;
case 0x72 :
case 0x73 :
V_271 = F_147 ( V_88 , V_269 ,
0 ) ;
if ( V_271 && ( 0xa == V_271 [ 1 ] ) ) {
* V_270 = F_148 ( & V_271 [ 4 ] ) ;
return true ;
}
return false ;
default:
return false ;
}
}
