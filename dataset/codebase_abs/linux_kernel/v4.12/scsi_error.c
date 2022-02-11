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
struct V_17 * V_18 = V_46 -> V_47 ;
enum V_45 V_23 = V_48 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
F_32 ( V_18 ) ;
F_33 ( V_18 , V_49 ) ;
if ( V_24 -> V_13 != - 1 && ! V_24 -> V_12 )
V_24 -> V_12 = V_14 ;
if ( V_24 -> V_25 -> V_50 )
V_23 = V_24 -> V_25 -> V_50 ( V_18 ) ;
if ( V_23 == V_48 ) {
if ( F_22 ( V_18 ) != V_26 ) {
F_17 ( V_18 , V_27 ) ;
F_21 ( V_18 ) ;
}
}
return V_23 ;
}
int F_34 ( struct V_20 * V_21 )
{
int V_51 ;
F_35 ( V_21 -> V_24 -> V_52 , ! F_36 ( V_21 -> V_24 ) ) ;
V_51 = F_37 ( V_21 ) ;
F_5 ( 5 , F_38 ( V_6 , V_21 ,
L_13 , V_53 , V_51 ) ) ;
return V_51 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_17 * V_18 ;
struct V_20 * V_21 ;
int V_56 = 0 ;
int V_57 = 0 ;
int V_58 = 0 ;
int V_59 = 0 ;
F_40 (sdev, shost) {
F_41 (scmd, work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 ) {
++ V_56 ;
if ( V_18 -> V_33 & V_34 )
++ V_58 ;
else
++ V_57 ;
}
}
if ( V_58 || V_57 ) {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_14 ,
V_53 , V_57 ,
V_58 ) ) ;
V_58 = 0 ;
V_57 = 0 ;
++ V_59 ;
}
}
F_5 ( 2 , F_6 ( V_6 , V_2 ,
L_15
L_16 ,
V_56 , V_59 ) ) ;
}
static void F_42 ( struct V_20 * V_21 )
{
V_21 -> V_60 -> V_61 = 1 ;
}
static void F_43 ( struct V_20 * V_21 ,
struct V_62 * V_63 )
{
enum V_64 V_65 = V_66 ;
if ( V_63 -> V_67 == V_68 ) {
if ( V_63 -> V_69 == 0x3f && V_63 -> V_70 == 0x03 ) {
V_65 = V_71 ;
F_38 ( V_30 , V_21 ,
L_17 ) ;
} else if ( V_63 -> V_69 == 0x3f && V_63 -> V_70 == 0x0e ) {
V_65 = V_72 ;
F_42 ( V_21 ) ;
F_38 ( V_30 , V_21 ,
L_18
L_19
L_20
L_21 ) ;
} else if ( V_63 -> V_69 == 0x3f )
F_38 ( V_30 , V_21 ,
L_18
L_22
L_20
L_23 ) ;
if ( V_63 -> V_69 == 0x38 && V_63 -> V_70 == 0x07 ) {
V_65 = V_73 ;
F_38 ( V_30 , V_21 ,
L_18
L_24
L_25 ) ;
}
if ( V_63 -> V_69 == 0x2a && V_63 -> V_70 == 0x01 ) {
V_65 = V_74 ;
F_38 ( V_30 , V_21 ,
L_26 ) ;
} else if ( V_63 -> V_69 == 0x2a && V_63 -> V_70 == 0x06 ) {
V_65 = V_75 ;
F_38 ( V_30 , V_21 ,
L_27 ) ;
} else if ( V_63 -> V_69 == 0x2a && V_63 -> V_70 == 0x09 ) {
V_65 = V_76 ;
F_38 ( V_30 , V_21 ,
L_28 ) ;
} else if ( V_63 -> V_69 == 0x2a )
F_38 ( V_30 , V_21 ,
L_29 ) ;
}
if ( V_65 != V_66 ) {
F_44 ( V_65 , V_21 -> V_77 ) ;
F_45 ( & V_21 -> V_78 ) ;
}
}
int F_46 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_62 V_63 ;
if ( ! F_47 ( V_18 , & V_63 ) )
return V_35 ;
F_43 ( V_21 , & V_63 ) ;
if ( F_48 ( & V_63 ) )
return V_79 ;
if ( V_21 -> V_80 && V_21 -> V_80 -> V_81 ) {
int V_82 ;
V_82 = V_21 -> V_80 -> V_81 ( V_21 , & V_63 ) ;
if ( V_82 != V_83 )
return V_82 ;
}
if ( V_18 -> V_84 [ 0 ] == V_85 && V_18 -> V_86 != V_87 )
return V_26 ;
if ( V_63 . V_88 == 0x70 ) {
if ( V_18 -> V_89 [ 2 ] & 0xe0 )
return V_26 ;
} else {
if ( ( V_63 . V_90 > 3 ) &&
( V_18 -> V_89 [ 8 ] == 0x4 ) &&
( V_18 -> V_89 [ 11 ] & 0xe0 ) )
return V_26 ;
}
switch ( V_63 . V_67 ) {
case V_91 :
return V_26 ;
case V_92 :
return V_26 ;
case V_93 :
if ( V_63 . V_69 == 0x10 )
return V_26 ;
return V_79 ;
case V_94 :
case V_68 :
if ( V_18 -> V_22 -> V_95 ) {
if ( V_63 . V_69 != 0x28 || V_63 . V_70 != 0x00 ) {
V_18 -> V_22 -> V_95 = 0 ;
return V_79 ;
}
}
if ( V_18 -> V_22 -> V_60 -> V_61 &&
V_63 . V_69 == 0x3f && V_63 . V_70 == 0x0e )
return V_79 ;
if ( ( V_63 . V_69 == 0x04 ) && ( V_63 . V_70 == 0x01 ) )
return V_79 ;
if ( V_18 -> V_22 -> V_96 &&
( V_63 . V_69 == 0x04 ) && ( V_63 . V_70 == 0x02 ) )
return V_35 ;
return V_26 ;
case V_97 :
if ( V_63 . V_69 == 0x27 && V_63 . V_70 == 0x07 ) {
F_17 ( V_18 , V_98 ) ;
return V_26 ;
}
case V_99 :
case V_100 :
case V_101 :
case V_102 :
F_17 ( V_18 , V_103 ) ;
return V_26 ;
case V_104 :
if ( V_63 . V_69 == 0x11 ||
V_63 . V_69 == 0x13 ||
V_63 . V_69 == 0x14 ) {
F_17 ( V_18 , V_105 ) ;
return V_26 ;
}
return V_79 ;
case V_106 :
if ( V_18 -> V_22 -> V_107 )
return V_108 ;
else
F_17 ( V_18 , V_103 ) ;
case V_109 :
if ( V_63 . V_69 == 0x20 ||
V_63 . V_69 == 0x21 ||
V_63 . V_69 == 0x24 ||
V_63 . V_69 == 0x26 ) {
F_17 ( V_18 , V_103 ) ;
}
return V_26 ;
default:
return V_26 ;
}
}
static void F_49 ( struct V_20 * V_21 )
{
struct V_110 * V_111 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_112 ;
if ( ! V_111 -> V_113 ||
V_21 -> V_114 >= V_21 -> V_115 )
return;
if ( F_12 ( V_14 ,
V_21 -> V_116 + V_21 -> V_117 ) )
return;
if ( F_12 ( V_14 ,
V_21 -> V_118 + V_21 -> V_117 ) )
return;
F_40 (tmp_sdev, sdev->host) {
if ( V_112 -> V_119 != V_21 -> V_119 ||
V_112 -> V_120 != V_21 -> V_120 ||
V_112 -> V_114 == V_21 -> V_115 )
continue;
F_50 ( V_112 , V_112 -> V_114 + 1 ) ;
V_21 -> V_116 = V_14 ;
}
}
static void F_51 ( struct V_20 * V_21 )
{
struct V_110 * V_111 = V_21 -> V_24 -> V_25 ;
struct V_20 * V_112 ;
if ( ! V_111 -> V_113 )
return;
F_40 (tmp_sdev, sdev->host) {
if ( V_112 -> V_119 != V_21 -> V_119 ||
V_112 -> V_120 != V_21 -> V_120 )
continue;
F_52 ( V_112 , V_112 -> V_114 - 1 ) ;
}
}
static int F_53 ( struct V_17 * V_18 )
{
if ( F_54 ( V_18 -> V_121 ) == V_122 ) {
return F_46 ( V_18 ) ;
}
if ( F_54 ( V_18 -> V_121 ) != V_123 )
return V_35 ;
if ( F_55 ( V_18 -> V_121 ) != V_124 )
return V_35 ;
switch ( F_56 ( V_18 -> V_121 ) ) {
case V_125 :
F_49 ( V_18 -> V_22 ) ;
case V_126 :
return V_26 ;
case V_127 :
return F_46 ( V_18 ) ;
case V_128 :
case V_129 :
case V_130 :
return V_26 ;
case V_131 :
if ( V_18 -> V_84 [ 0 ] == V_85 )
return V_26 ;
return V_35 ;
case V_132 :
F_51 ( V_18 -> V_22 ) ;
case V_133 :
return V_79 ;
default:
return V_35 ;
}
return V_35 ;
}
static void V_87 ( struct V_17 * V_18 )
{
struct V_134 * V_135 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_30 , V_53 , V_18 -> V_121 ) ) ;
V_135 = V_18 -> V_22 -> V_24 -> V_135 ;
if ( V_135 )
F_57 ( V_135 ) ;
}
static int F_58 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_110 * V_25 = V_24 -> V_25 ;
F_5 ( 3 ,
F_6 ( V_6 , V_24 , L_31 ) ) ;
if ( ! V_25 -> V_136 )
return V_35 ;
V_23 = V_25 -> V_136 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_137 )
F_59 ( V_138 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_60 ( V_24 , F_61 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_62 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_110 * V_25 = V_24 -> V_25 ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_32 , V_53 ) ) ;
if ( ! V_25 -> V_139 )
return V_35 ;
V_23 = V_25 -> V_139 ( V_18 ) ;
if ( V_23 == V_26 ) {
if ( ! V_25 -> V_137 )
F_59 ( V_140 ) ;
F_8 ( V_24 -> V_8 , V_7 ) ;
F_60 ( V_24 , F_61 ( V_18 ) ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static void F_63 ( struct V_20 * V_21 , void * V_141 )
{
V_21 -> V_142 = 1 ;
V_21 -> V_95 = 1 ;
}
static int F_64 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
int V_23 ;
struct V_1 * V_24 = V_18 -> V_22 -> V_24 ;
struct V_110 * V_25 = V_24 -> V_25 ;
if ( ! V_25 -> V_143 )
return V_35 ;
V_23 = V_25 -> V_143 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_8 ( V_24 -> V_8 , V_7 ) ;
F_65 ( F_66 ( V_18 -> V_22 ) , NULL ,
F_63 ) ;
F_10 ( V_24 -> V_8 , V_7 ) ;
}
return V_23 ;
}
static int F_67 ( struct V_17 * V_18 )
{
int V_23 ;
struct V_110 * V_25 = V_18 -> V_22 -> V_24 -> V_25 ;
if ( ! V_25 -> V_144 )
return V_35 ;
V_23 = V_25 -> V_144 ( V_18 ) ;
if ( V_23 == V_26 )
F_63 ( V_18 -> V_22 , NULL ) ;
return V_23 ;
}
static int F_16 ( struct V_110 * V_25 ,
struct V_17 * V_18 )
{
if ( ! V_25 -> V_145 )
return V_35 ;
return V_25 -> V_145 ( V_18 ) ;
}
static void F_68 ( struct V_17 * V_18 )
{
if ( F_16 ( V_18 -> V_22 -> V_24 -> V_25 , V_18 ) != V_26 )
if ( F_67 ( V_18 ) != V_26 )
if ( F_64 ( V_18 ) != V_26 )
if ( F_62 ( V_18 ) != V_26 )
F_58 ( V_18 ) ;
}
void F_69 ( struct V_17 * V_18 , struct V_146 * V_147 ,
unsigned char * V_84 , int V_148 , unsigned V_149 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
V_147 -> V_150 = V_18 -> V_150 ;
V_147 -> V_84 = V_18 -> V_84 ;
V_147 -> V_151 = V_18 -> V_152 ;
V_147 -> V_153 = V_18 -> V_153 ;
V_147 -> V_154 = V_18 -> V_38 -> V_154 ;
V_147 -> V_121 = V_18 -> V_121 ;
V_147 -> V_155 = V_18 -> V_155 ;
V_147 -> V_156 = V_18 -> V_156 ;
V_147 -> V_33 = V_18 -> V_33 ;
V_18 -> V_156 = V_157 ;
V_18 -> V_33 = 0 ;
V_18 -> V_84 = V_147 -> V_158 ;
memset ( V_18 -> V_84 , 0 , V_159 ) ;
memset ( & V_18 -> V_153 , 0 , sizeof( V_18 -> V_153 ) ) ;
V_18 -> V_38 -> V_154 = NULL ;
V_18 -> V_121 = 0 ;
if ( V_149 ) {
V_18 -> V_153 . V_160 = F_70 ( unsigned , V_161 ,
V_149 ) ;
F_71 ( & V_147 -> V_162 , V_18 -> V_89 ,
V_18 -> V_153 . V_160 ) ;
V_18 -> V_153 . V_163 . V_164 = & V_147 -> V_162 ;
V_18 -> V_152 = V_165 ;
V_18 -> V_153 . V_163 . V_166 = V_18 -> V_153 . V_163 . V_167 = 1 ;
V_18 -> V_84 [ 0 ] = V_168 ;
V_18 -> V_84 [ 4 ] = V_18 -> V_153 . V_160 ;
V_18 -> V_150 = F_72 ( V_18 -> V_84 [ 0 ] ) ;
} else {
V_18 -> V_152 = V_169 ;
if ( V_84 ) {
F_23 ( V_148 > V_159 ) ;
memcpy ( V_18 -> V_84 , V_84 , V_148 ) ;
V_18 -> V_150 = F_72 ( V_18 -> V_84 [ 0 ] ) ;
}
}
V_18 -> V_155 = 0 ;
if ( V_21 -> V_170 <= V_171 && V_21 -> V_170 != V_172 )
V_18 -> V_84 [ 1 ] = ( V_18 -> V_84 [ 1 ] & 0x1f ) |
( V_21 -> V_173 << 5 & 0xe0 ) ;
memset ( V_18 -> V_89 , 0 , V_161 ) ;
}
void F_73 ( struct V_17 * V_18 , struct V_146 * V_147 )
{
V_18 -> V_150 = V_147 -> V_150 ;
V_18 -> V_84 = V_147 -> V_84 ;
V_18 -> V_152 = V_147 -> V_151 ;
V_18 -> V_153 = V_147 -> V_153 ;
V_18 -> V_38 -> V_154 = V_147 -> V_154 ;
V_18 -> V_121 = V_147 -> V_121 ;
V_18 -> V_155 = V_147 -> V_155 ;
V_18 -> V_156 = V_147 -> V_156 ;
V_18 -> V_33 = V_147 -> V_33 ;
}
static int F_74 ( struct V_17 * V_18 , unsigned char * V_84 ,
int V_148 , int V_174 , unsigned V_149 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_24 ;
F_75 ( V_175 ) ;
unsigned long V_176 = V_174 ;
struct V_146 V_147 ;
const unsigned long V_177 = F_76 ( 100 ) ;
int V_23 ;
V_178:
F_69 ( V_18 , & V_147 , V_84 , V_148 , V_149 ) ;
V_2 -> V_135 = & V_175 ;
F_77 ( V_18 ) ;
V_18 -> V_86 = V_87 ;
V_23 = V_2 -> V_25 -> V_179 ( V_2 , V_18 ) ;
if ( V_23 ) {
if ( V_176 > V_177 ) {
F_73 ( V_18 , & V_147 ) ;
V_176 -= V_177 ;
F_78 ( F_79 ( V_177 ) ) ;
goto V_178;
}
V_176 = 0 ;
V_23 = V_35 ;
} else {
V_176 = F_80 ( & V_175 , V_174 ) ;
V_23 = V_26 ;
}
V_2 -> V_135 = NULL ;
F_33 ( V_18 , V_23 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_33 ,
V_53 , V_176 ) ) ;
if ( V_176 ) {
V_23 = F_53 ( V_18 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_34 , V_53 , V_23 ) ) ;
switch ( V_23 ) {
case V_26 :
case V_79 :
case V_35 :
break;
case V_108 :
V_23 = V_79 ;
break;
default:
V_23 = V_35 ;
break;
}
} else if ( V_23 != V_35 ) {
F_68 ( V_18 ) ;
V_23 = V_35 ;
}
F_73 ( V_18 , & V_147 ) ;
return V_23 ;
}
static int F_81 ( struct V_17 * V_18 )
{
return F_74 ( V_18 , NULL , 0 , V_18 -> V_22 -> V_180 , ~ 0 ) ;
}
static int F_82 ( struct V_17 * V_18 , int V_23 )
{
if ( ! F_27 ( V_18 -> V_38 ) ) {
struct V_39 * V_40 = F_28 ( V_18 ) ;
if ( V_40 -> V_135 )
V_23 = V_40 -> V_135 ( V_18 , V_23 ) ;
}
return V_23 ;
}
void F_83 ( struct V_17 * V_18 , struct V_54 * V_181 )
{
F_84 ( & V_18 -> V_43 , V_181 ) ;
}
int F_85 ( struct V_54 * V_55 ,
struct V_54 * V_181 )
{
struct V_17 * V_18 , * V_182 ;
struct V_1 * V_2 ;
int V_23 ;
F_86 (scmd, next, work_q, eh_entry) {
if ( ( V_18 -> V_33 & V_34 ) ||
F_87 ( V_18 ) )
continue;
V_2 = V_18 -> V_22 -> V_24 ;
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_35 ,
V_183 -> V_184 ) ) ;
break;
}
if ( F_56 ( V_18 -> V_121 ) != V_127 )
continue;
F_5 ( 2 , F_15 ( V_6 , V_18 ,
L_36 ,
V_183 -> V_184 ) ) ;
V_23 = F_81 ( V_18 ) ;
if ( V_23 != V_26 )
continue;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_37 , V_18 -> V_121 ) ) ;
F_5 ( 3 , F_88 ( V_18 ) ) ;
V_23 = F_89 ( V_18 ) ;
if ( V_23 == V_26 )
V_18 -> V_28 = V_18 -> V_29 ;
else if ( V_23 != V_79 )
continue;
F_83 ( V_18 , V_181 ) ;
}
return F_90 ( V_55 ) ;
}
static int F_91 ( struct V_17 * V_18 )
{
static unsigned char V_185 [ 6 ] = { V_85 , 0 , 0 , 0 , 0 , 0 } ;
int V_186 = 1 , V_23 ;
V_187:
V_23 = F_74 ( V_18 , V_185 , 6 ,
V_18 -> V_22 -> V_180 , 0 ) ;
F_5 ( 3 , F_15 ( V_6 , V_18 ,
L_38 , V_53 , V_23 ) ) ;
switch ( V_23 ) {
case V_79 :
if ( V_186 -- )
goto V_187;
case V_26 :
return 0 ;
default:
return 1 ;
}
}
static int F_92 ( struct V_54 * V_188 ,
struct V_54 * V_55 ,
struct V_54 * V_181 , int V_189 )
{
struct V_17 * V_18 , * V_182 ;
struct V_20 * V_21 ;
int V_190 ;
while ( ! F_90 ( V_188 ) ) {
V_18 = F_93 ( V_188 -> V_182 , struct V_17 , V_43 ) ;
V_21 = V_18 -> V_22 ;
if ( ! V_189 ) {
if ( F_11 ( V_21 -> V_24 ) ) {
F_94 ( V_188 , V_55 ) ;
F_5 ( 3 ,
F_38 ( V_6 , V_21 ,
L_39 ,
V_183 -> V_184 ) ) ;
break;
}
}
V_190 = ! F_37 ( V_18 -> V_22 ) ||
( V_189 && ! F_95 ( V_18 ) &&
! F_91 ( V_18 ) ) ||
! F_91 ( V_18 ) ;
F_86 (scmd, next, cmd_list, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
if ( V_190 &&
( V_189 ||
F_82 ( V_18 , V_26 ) == V_26 ) )
F_83 ( V_18 , V_181 ) ;
else
F_84 ( & V_18 -> V_43 , V_55 ) ;
}
}
return F_90 ( V_55 ) ;
}
static int F_95 ( struct V_17 * V_18 )
{
static unsigned char V_191 [ 6 ] = { V_192 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_18 -> V_22 -> V_96 ) {
int V_193 , V_23 = V_79 ;
for ( V_193 = 0 ; V_23 == V_79 && V_193 < 2 ; V_193 ++ )
V_23 = F_74 ( V_18 , V_191 , 6 , V_18 -> V_22 -> V_194 -> V_195 , 0 ) ;
if ( V_23 == V_26 )
return 0 ;
}
return 1 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_181 )
{
struct V_17 * V_18 , * V_196 , * V_182 ;
struct V_20 * V_21 ;
F_40 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_38 ( V_6 , V_21 ,
L_40 ,
V_183 -> V_184 ) ) ;
break;
}
V_196 = NULL ;
F_41 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 && F_87 ( V_18 ) &&
F_46 ( V_18 ) == V_35 ) {
V_196 = V_18 ;
break;
}
if ( ! V_196 )
continue;
F_5 ( 3 ,
F_38 ( V_6 , V_21 ,
L_41 ,
V_183 -> V_184 ) ) ;
if ( ! F_95 ( V_196 ) ) {
if ( ! F_37 ( V_21 ) ||
! F_91 ( V_196 ) ) {
F_86 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_82 ( V_18 , V_26 ) == V_26 )
F_83 ( V_18 , V_181 ) ;
}
}
} else {
F_5 ( 3 ,
F_38 ( V_6 , V_21 ,
L_42 ,
V_183 -> V_184 ) ) ;
}
}
return F_90 ( V_55 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_181 )
{
struct V_17 * V_18 , * V_197 , * V_182 ;
struct V_20 * V_21 ;
int V_23 ;
F_40 (sdev, shost) {
if ( F_11 ( V_2 ) ) {
F_5 ( 3 ,
F_38 ( V_6 , V_21 ,
L_43 ,
V_183 -> V_184 ) ) ;
break;
}
V_197 = NULL ;
F_41 (scmd, work_q, eh_entry)
if ( V_18 -> V_22 == V_21 ) {
V_197 = V_18 ;
break;
}
if ( ! V_197 )
continue;
F_5 ( 3 ,
F_38 ( V_6 , V_21 ,
L_44 , V_183 -> V_184 ) ) ;
V_23 = F_67 ( V_197 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
if ( ! F_37 ( V_21 ) ||
V_23 == V_32 ||
! F_91 ( V_197 ) ) {
F_86 (scmd, next,
work_q, eh_entry) {
if ( V_18 -> V_22 == V_21 &&
F_82 ( V_18 , V_23 ) != V_35 )
F_83 ( V_18 ,
V_181 ) ;
}
}
} else {
F_5 ( 3 ,
F_38 ( V_6 , V_21 ,
L_45 , V_183 -> V_184 ) ) ;
}
}
return F_90 ( V_55 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_181 )
{
F_99 ( V_198 ) ;
F_99 ( V_199 ) ;
F_94 ( V_55 , & V_198 ) ;
while ( ! F_90 ( & V_198 ) ) {
struct V_17 * V_182 , * V_18 ;
int V_23 ;
unsigned int V_120 ;
if ( F_11 ( V_2 ) ) {
F_94 ( & V_199 , V_55 ) ;
F_94 ( & V_198 , V_55 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_46 ,
V_183 -> V_184 ) ) ;
return F_90 ( V_55 ) ;
}
V_18 = F_93 ( V_198 . V_182 , struct V_17 , V_43 ) ;
V_120 = F_100 ( V_18 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_47 ,
V_183 -> V_184 , V_120 ) ) ;
V_23 = F_64 ( V_18 ) ;
if ( V_23 != V_26 && V_23 != V_32 )
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_48
L_49 ,
V_183 -> V_184 , V_120 ) ) ;
F_86 (scmd, next, &tmp_list, eh_entry) {
if ( F_100 ( V_18 ) != V_120 )
continue;
if ( V_23 == V_26 )
F_84 ( & V_18 -> V_43 , & V_199 ) ;
else if ( V_23 == V_32 )
F_83 ( V_18 , V_181 ) ;
else
F_101 ( & V_18 -> V_43 , V_55 ) ;
}
}
return F_92 ( & V_199 , V_55 , V_181 , 0 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_181 )
{
struct V_17 * V_18 , * V_200 , * V_182 ;
F_99 ( V_199 ) ;
unsigned int V_119 ;
int V_23 ;
for ( V_119 = 0 ; V_119 <= V_2 -> V_201 ; V_119 ++ ) {
if ( F_11 ( V_2 ) ) {
F_94 ( & V_199 , V_55 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_50 ,
V_183 -> V_184 ) ) ;
return F_90 ( V_55 ) ;
}
V_200 = NULL ;
F_41 (scmd, work_q, eh_entry) {
if ( V_119 == F_61 ( V_18 ) ) {
V_200 = V_18 ;
break;
}
}
if ( ! V_200 )
continue;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_51 ,
V_183 -> V_184 , V_119 ) ) ;
V_23 = F_62 ( V_200 ) ;
if ( V_23 == V_26 || V_23 == V_32 ) {
F_86 (scmd, next, work_q, eh_entry) {
if ( V_119 == F_61 ( V_18 ) ) {
if ( V_23 == V_32 )
F_83 ( V_18 ,
V_181 ) ;
else
F_84 ( & V_18 -> V_43 ,
& V_199 ) ;
}
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_52 ,
V_183 -> V_184 , V_119 ) ) ;
}
}
return F_92 ( & V_199 , V_55 , V_181 , 0 ) ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_181 )
{
struct V_17 * V_18 , * V_182 ;
F_99 ( V_199 ) ;
int V_23 ;
if ( ! F_90 ( V_55 ) ) {
V_18 = F_93 ( V_55 -> V_182 ,
struct V_17 , V_43 ) ;
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_53 ,
V_183 -> V_184 ) ) ;
V_23 = F_58 ( V_18 ) ;
if ( V_23 == V_26 ) {
F_94 ( V_55 , & V_199 ) ;
} else if ( V_23 == V_32 ) {
F_86 (scmd, next, work_q, eh_entry) {
F_83 ( V_18 , V_181 ) ;
}
} else {
F_5 ( 3 ,
F_6 ( V_6 , V_2 ,
L_54 ,
V_183 -> V_184 ) ) ;
}
}
return F_92 ( & V_199 , V_55 , V_181 , 1 ) ;
}
static void F_104 ( struct V_54 * V_55 ,
struct V_54 * V_181 )
{
struct V_17 * V_18 , * V_182 ;
F_86 (scmd, next, work_q, eh_entry) {
F_38 ( V_6 , V_18 -> V_22 , L_55
L_56 ) ;
F_105 ( V_18 -> V_22 , V_202 ) ;
F_83 ( V_18 , V_181 ) ;
}
return;
}
int F_18 ( struct V_17 * V_18 )
{
switch ( F_54 ( V_18 -> V_121 ) ) {
case V_123 :
break;
case V_27 :
goto V_203;
case V_204 :
return ( V_18 -> V_38 -> V_205 & V_206 ) ;
case V_207 :
return ( V_18 -> V_38 -> V_205 & V_208 ) ;
case V_209 :
if ( F_55 ( V_18 -> V_121 ) == V_124 &&
F_56 ( V_18 -> V_121 ) == V_131 )
return 0 ;
case V_210 :
return ( V_18 -> V_38 -> V_205 & V_211 ) ;
}
if ( F_56 ( V_18 -> V_121 ) != V_127 )
return 0 ;
V_203:
if ( V_18 -> V_38 -> V_205 & V_208 ||
F_27 ( V_18 -> V_38 ) )
return 1 ;
else
return 0 ;
}
int F_89 ( struct V_17 * V_18 )
{
int V_23 ;
if ( ! F_37 ( V_18 -> V_22 ) ) {
F_5 ( 5 , F_15 ( V_6 , V_18 ,
L_57 , V_53 ) ) ;
return V_26 ;
}
switch ( F_54 ( V_18 -> V_121 ) ) {
case V_212 :
V_18 -> V_121 &= 0xff00ffff ;
return V_26 ;
case V_123 :
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
return V_79 ;
case V_218 :
return V_108 ;
case V_219 :
goto V_216;
case V_220 :
return V_26 ;
case V_209 :
if ( F_55 ( V_18 -> V_121 ) == V_124 &&
F_56 ( V_18 -> V_121 ) == V_131 )
break;
case V_204 :
case V_207 :
goto V_216;
case V_27 :
if ( ( V_18 -> V_84 [ 0 ] == V_85 ||
V_18 -> V_84 [ 0 ] == V_221 ) ) {
return V_26 ;
} else {
return V_35 ;
}
case V_122 :
return V_26 ;
default:
return V_35 ;
}
if ( F_55 ( V_18 -> V_121 ) != V_124 )
return V_35 ;
switch ( F_56 ( V_18 -> V_121 ) ) {
case V_132 :
F_51 ( V_18 -> V_22 ) ;
case V_133 :
return V_108 ;
case V_125 :
if ( V_18 -> V_84 [ 0 ] == V_222 )
V_18 -> V_22 -> V_60 -> V_61 = 0 ;
F_49 ( V_18 -> V_22 ) ;
case V_126 :
return V_26 ;
case V_223 :
goto V_216;
case V_127 :
V_23 = F_46 ( V_18 ) ;
if ( V_23 == V_79 )
goto V_216;
return V_23 ;
case V_128 :
case V_129 :
case V_130 :
case V_224 :
return V_26 ;
case V_131 :
F_38 ( V_6 , V_18 -> V_22 ,
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
return V_79 ;
} else {
return V_26 ;
}
}
static void F_106 ( struct V_38 * V_46 , int V_226 )
{
F_107 ( V_46 -> V_227 , V_46 ) ;
}
static void F_108 ( struct V_20 * V_21 )
{
struct V_38 * V_46 ;
struct V_228 * V_229 ;
V_46 = F_109 ( V_21 -> V_194 , V_230 , V_231 ) ;
if ( F_110 ( V_46 ) )
return;
V_229 = F_111 ( V_46 ) ;
F_112 ( V_46 ) ;
V_229 -> V_232 [ 0 ] = V_233 ;
V_229 -> V_232 [ 1 ] = 0 ;
V_229 -> V_232 [ 2 ] = 0 ;
V_229 -> V_232 [ 3 ] = 0 ;
V_229 -> V_232 [ 4 ] = V_234 ;
V_229 -> V_232 [ 5 ] = 0 ;
V_229 -> V_150 = F_72 ( V_229 -> V_232 [ 0 ] ) ;
V_46 -> V_235 |= V_236 ;
V_46 -> V_174 = 10 * V_37 ;
V_229 -> V_28 = 5 ;
F_113 ( V_46 -> V_227 , NULL , V_46 , 1 , F_106 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned long V_7 ;
F_40 (sdev, shost) {
if ( F_37 ( V_21 ) && V_21 -> V_142 && V_21 -> V_237 ) {
F_108 ( V_21 ) ;
V_21 -> V_142 = 0 ;
}
}
F_5 ( 3 ,
F_6 ( V_6 , V_2 , L_59 ) ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( F_9 ( V_2 , V_238 ) )
if ( F_9 ( V_2 , V_239 ) )
F_23 ( F_9 ( V_2 , V_240 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_115 ( & V_2 -> V_52 ) ;
F_116 ( V_2 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_11 )
if ( F_9 ( V_2 , V_9 ) )
F_117 ( F_9 ( V_2 , V_10 ) ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
}
void F_118 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_181 )
{
if ( ! F_96 ( V_2 , V_55 , V_181 ) )
if ( ! F_97 ( V_2 , V_55 , V_181 ) )
if ( ! F_98 ( V_2 , V_55 , V_181 ) )
if ( ! F_102 ( V_2 , V_55 , V_181 ) )
if ( ! F_103 ( V_2 , V_55 , V_181 ) )
F_104 ( V_55 ,
V_181 ) ;
}
void F_119 ( struct V_54 * V_181 )
{
struct V_17 * V_18 , * V_182 ;
F_86 (scmd, next, done_q, eh_entry) {
F_120 ( & V_18 -> V_43 ) ;
if ( F_37 ( V_18 -> V_22 ) &&
! F_18 ( V_18 ) &&
( ++ V_18 -> V_28 <= V_18 -> V_29 ) ) {
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_60 ,
V_183 -> V_184 ) ) ;
F_19 ( V_18 , V_31 ) ;
} else {
if ( ! V_18 -> V_121 )
V_18 -> V_121 |= ( V_241 << 24 ) ;
F_5 ( 3 ,
F_15 ( V_6 , V_18 ,
L_61 ,
V_183 -> V_184 ) ) ;
F_20 ( V_18 ) ;
}
}
}
static void F_121 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_99 ( V_242 ) ;
F_99 ( V_243 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
F_94 ( & V_2 -> V_44 , & V_242 ) ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_5 ( 1 , F_39 ( V_2 , & V_242 ) ) ;
if ( ! F_85 ( & V_242 , & V_243 ) )
F_118 ( V_2 , & V_242 , & V_243 ) ;
F_8 ( V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_13 != - 1 )
V_2 -> V_12 = 0 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
F_119 ( & V_243 ) ;
}
int F_122 ( void * V_141 )
{
struct V_1 * V_2 = V_141 ;
while ( true ) {
F_123 ( V_244 ) ;
if ( F_124 () )
break;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_11 == 0 ) ||
V_2 -> V_4 != F_2 ( & V_2 -> V_3 ) ) {
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_62 ,
V_2 -> V_245 ) ) ;
F_125 () ;
continue;
}
F_126 ( V_246 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_63 ,
V_2 -> V_245 , V_2 -> V_11 ,
V_2 -> V_4 ,
F_2 ( & V_2 -> V_3 ) ) ) ;
if ( ! V_2 -> V_247 && F_127 ( V_2 ) != 0 ) {
F_5 ( 1 ,
F_6 ( V_248 , V_2 ,
L_64 ,
V_2 -> V_245 ) ) ;
continue;
}
if ( V_2 -> V_249 -> V_250 )
V_2 -> V_249 -> V_250 ( V_2 ) ;
else
F_121 ( V_2 ) ;
V_2 -> V_4 = 0 ;
F_114 ( V_2 ) ;
if ( ! V_2 -> V_247 )
F_128 ( V_2 ) ;
}
F_126 ( V_246 ) ;
F_5 ( 1 ,
F_6 ( V_6 , V_2 ,
L_65 ,
V_2 -> V_245 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 , int V_119 )
{
struct V_20 * V_21 ;
F_129 (sdev, shost) {
if ( V_119 == F_130 ( V_21 ) )
F_63 ( V_21 , NULL ) ;
}
}
void F_131 ( struct V_1 * V_2 , int V_119 , int V_251 )
{
struct V_20 * V_21 ;
F_129 (sdev, shost) {
if ( V_119 == F_130 ( V_21 ) &&
V_251 == F_132 ( V_21 ) )
F_63 ( V_21 , NULL ) ;
}
}
static void
F_133 ( struct V_17 * V_18 )
{
}
int
F_134 ( struct V_20 * V_252 , int T_1 * V_253 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = V_252 -> V_24 ;
struct V_38 * V_229 ;
unsigned long V_7 ;
int error = 0 , V_23 , V_254 ;
if ( ! F_135 ( V_255 ) || ! F_135 ( V_256 ) )
return - V_257 ;
error = F_136 ( V_254 , V_253 ) ;
if ( error )
return error ;
if ( F_127 ( V_2 ) < 0 )
return - V_258 ;
error = - V_258 ;
V_229 = F_137 ( sizeof( struct V_38 ) + sizeof( struct V_17 ) +
V_2 -> V_25 -> V_259 , V_231 ) ;
if ( ! V_229 )
goto V_260;
F_138 ( NULL , V_229 ) ;
V_18 = (struct V_17 * ) ( V_229 + 1 ) ;
F_139 ( V_252 , V_18 ) ;
V_18 -> V_38 = V_229 ;
V_18 -> V_84 = F_111 ( V_229 ) -> V_232 ;
V_18 -> V_86 = F_133 ;
memset ( & V_18 -> V_153 , 0 , sizeof( V_18 -> V_153 ) ) ;
V_18 -> V_150 = 0 ;
V_18 -> V_152 = V_261 ;
F_8 ( V_2 -> V_8 , V_7 ) ;
V_2 -> V_262 = 1 ;
F_10 ( V_2 -> V_8 , V_7 ) ;
switch ( V_254 & ~ V_263 ) {
case V_264 :
V_23 = V_26 ;
break;
case V_265 :
V_23 = F_67 ( V_18 ) ;
if ( V_23 == V_26 || ( V_254 & V_263 ) )
break;
case V_266 :
V_23 = F_64 ( V_18 ) ;
if ( V_23 == V_26 || ( V_254 & V_263 ) )
break;
case V_267 :
V_23 = F_62 ( V_18 ) ;
if ( V_23 == V_26 || ( V_254 & V_263 ) )
break;
case V_268 :
V_23 = F_58 ( V_18 ) ;
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
F_115 ( & V_2 -> V_52 ) ;
F_116 ( V_2 ) ;
F_140 ( V_18 ) ;
F_141 ( V_229 ) ;
V_260:
F_128 ( V_2 ) ;
return error ;
}
bool F_47 ( const struct V_17 * V_232 ,
struct V_62 * V_63 )
{
return F_142 ( V_232 -> V_89 ,
V_161 , V_63 ) ;
}
bool F_143 ( const T_2 * V_89 , int V_269 ,
T_3 * V_270 )
{
const T_2 * V_271 ;
if ( V_269 < 7 )
return false ;
switch ( V_89 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_89 [ 0 ] & 0x80 ) {
* V_270 = F_144 ( & V_89 [ 3 ] ) ;
return true ;
}
return false ;
case 0x72 :
case 0x73 :
V_271 = F_145 ( V_89 , V_269 ,
0 ) ;
if ( V_271 && ( 0xa == V_271 [ 1 ] ) ) {
* V_270 = F_146 ( & V_271 [ 4 ] ) ;
return true ;
}
return false ;
default:
return false ;
}
}
