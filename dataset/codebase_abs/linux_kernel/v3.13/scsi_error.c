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
if ( ! V_2 -> V_11 || ! V_2 -> V_12 )
return 0 ;
if ( F_11 ( V_13 ,
V_2 -> V_11 + V_2 -> V_12 ) )
return 0 ;
return 1 ;
}
int F_12 ( struct V_14 * V_15 , int V_16 )
{
struct V_1 * V_2 = V_15 -> V_17 -> V_18 ;
unsigned long V_6 ;
int V_19 = 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_8 ) )
if ( F_8 ( V_2 , V_9 ) )
goto V_20;
if ( V_2 -> V_12 && ! V_2 -> V_11 )
V_2 -> V_11 = V_13 ;
V_19 = 1 ;
V_15 -> V_21 |= V_16 ;
F_13 ( & V_15 -> V_22 , & V_2 -> V_23 ) ;
V_2 -> V_4 ++ ;
F_1 ( V_2 ) ;
V_20:
F_9 ( V_2 -> V_7 , V_6 ) ;
return V_19 ;
}
enum V_24 F_14 ( struct V_25 * V_26 )
{
struct V_14 * V_15 = V_26 -> V_27 ;
enum V_24 V_28 = V_29 ;
struct V_1 * V_18 = V_15 -> V_17 -> V_18 ;
F_15 ( V_15 ) ;
F_16 ( V_15 , V_30 ) ;
if ( V_18 -> V_12 && ! V_18 -> V_11 )
V_18 -> V_11 = V_13 ;
if ( V_18 -> V_31 -> V_32 )
V_28 = V_18 -> V_31 -> V_32 ( V_15 ) ;
else if ( V_18 -> V_33 -> V_32 )
V_28 = V_18 -> V_33 -> V_32 ( V_15 ) ;
V_15 -> V_34 |= V_35 << 16 ;
if ( F_17 ( V_28 == V_29 &&
! F_12 ( V_15 , V_36 ) ) )
V_28 = V_37 ;
return V_28 ;
}
int F_18 ( struct V_38 * V_39 )
{
int V_40 ;
F_19 ( V_39 -> V_18 -> V_41 , ! F_20 ( V_39 -> V_18 ) ) ;
V_40 = F_21 ( V_39 ) ;
F_4 ( 5 , F_5 ( L_2 , V_42 ,
V_40 ) ) ;
return V_40 ;
}
static inline void F_22 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_14 * V_15 ;
struct V_38 * V_39 ;
int V_45 = 0 ;
int V_46 = 0 ;
int V_47 = 0 ;
int V_48 = 0 ;
F_23 (sdev, shost) {
F_24 (scmd, work_q, eh_entry) {
if ( V_15 -> V_17 == V_39 ) {
++ V_45 ;
if ( V_15 -> V_21 & V_36 )
++ V_47 ;
else
++ V_46 ;
}
}
if ( V_47 || V_46 ) {
F_4 ( 3 ,
F_25 ( V_49 , V_39 ,
L_3 ,
V_42 , V_46 ,
V_47 ) ) ;
V_47 = 0 ;
V_46 = 0 ;
++ V_48 ;
}
}
F_4 ( 2 , F_5 ( L_4
L_5 ,
V_45 , V_48 ) ) ;
}
static void F_26 ( struct V_38 * V_39 )
{
V_39 -> V_50 -> V_51 = 1 ;
}
static void F_27 ( struct V_38 * V_39 ,
struct V_52 * V_53 )
{
enum V_54 V_55 = V_56 ;
if ( V_53 -> V_57 == V_58 ) {
if ( V_53 -> V_59 == 0x3f && V_53 -> V_60 == 0x03 ) {
V_55 = V_61 ;
F_25 ( V_62 , V_39 ,
L_6 ) ;
} else if ( V_53 -> V_59 == 0x3f && V_53 -> V_60 == 0x0e ) {
V_55 = V_63 ;
F_26 ( V_39 ) ;
F_25 ( V_62 , V_39 ,
L_7
L_8
L_9
L_10 ) ;
} else if ( V_53 -> V_59 == 0x3f )
F_25 ( V_62 , V_39 ,
L_7
L_11
L_9
L_12 ) ;
if ( V_53 -> V_59 == 0x38 && V_53 -> V_60 == 0x07 ) {
V_55 = V_64 ;
F_25 ( V_62 , V_39 ,
L_7
L_13
L_14 ) ;
}
if ( V_53 -> V_59 == 0x2a && V_53 -> V_60 == 0x01 ) {
V_55 = V_65 ;
F_25 ( V_62 , V_39 ,
L_15 ) ;
} else if ( V_53 -> V_59 == 0x2a && V_53 -> V_60 == 0x09 ) {
V_55 = V_66 ;
F_25 ( V_62 , V_39 ,
L_16 ) ;
} else if ( V_53 -> V_59 == 0x2a )
F_25 ( V_62 , V_39 ,
L_17 ) ;
}
if ( V_55 != V_56 ) {
F_28 ( V_55 , V_39 -> V_67 ) ;
F_29 ( & V_39 -> V_68 ) ;
}
}
static int F_30 ( struct V_14 * V_15 )
{
struct V_38 * V_39 = V_15 -> V_17 ;
struct V_52 V_53 ;
if ( ! F_31 ( V_15 , & V_53 ) )
return V_69 ;
if ( V_15 -> V_70 [ 0 ] == V_71 && V_15 -> V_72 != V_73 )
return V_74 ;
F_27 ( V_39 , & V_53 ) ;
if ( F_32 ( & V_53 ) )
return V_75 ;
if ( V_39 -> V_76 && V_39 -> V_76 -> V_77 &&
V_39 -> V_76 -> V_77 -> V_78 ) {
int V_79 ;
V_79 = V_39 -> V_76 -> V_77 -> V_78 ( V_39 , & V_53 ) ;
if ( V_79 != V_80 )
return V_79 ;
}
if ( V_53 . V_81 == 0x70 ) {
if ( V_15 -> V_82 [ 2 ] & 0xe0 )
return V_74 ;
} else {
if ( ( V_53 . V_83 > 3 ) &&
( V_15 -> V_82 [ 8 ] == 0x4 ) &&
( V_15 -> V_82 [ 11 ] & 0xe0 ) )
return V_74 ;
}
switch ( V_53 . V_57 ) {
case V_84 :
return V_74 ;
case V_85 :
return V_74 ;
case V_86 :
if ( V_53 . V_59 == 0x10 )
return V_74 ;
return V_75 ;
case V_87 :
case V_58 :
if ( V_15 -> V_17 -> V_88 ) {
if ( V_53 . V_59 != 0x28 || V_53 . V_60 != 0x00 ) {
V_15 -> V_17 -> V_88 = 0 ;
return V_75 ;
}
}
if ( V_15 -> V_17 -> V_50 -> V_51 &&
V_53 . V_59 == 0x3f && V_53 . V_60 == 0x0e )
return V_75 ;
if ( ( V_53 . V_59 == 0x04 ) && ( V_53 . V_60 == 0x01 ) )
return V_75 ;
if ( V_15 -> V_17 -> V_89 &&
( V_53 . V_59 == 0x04 ) && ( V_53 . V_60 == 0x02 ) )
return V_69 ;
return V_74 ;
case V_90 :
if ( V_53 . V_59 == 0x27 && V_53 . V_60 == 0x07 ) {
F_33 ( V_15 , V_91 ) ;
return V_74 ;
}
case V_92 :
case V_93 :
case V_94 :
case V_95 :
F_33 ( V_15 , V_96 ) ;
return V_74 ;
case V_97 :
if ( V_53 . V_59 == 0x11 ||
V_53 . V_59 == 0x13 ||
V_53 . V_59 == 0x14 ) {
F_33 ( V_15 , V_98 ) ;
return V_74 ;
}
return V_75 ;
case V_99 :
if ( V_15 -> V_17 -> V_100 )
return V_101 ;
else
F_33 ( V_15 , V_96 ) ;
case V_102 :
if ( V_53 . V_59 == 0x20 ||
V_53 . V_59 == 0x21 ||
V_53 . V_59 == 0x24 ||
V_53 . V_59 == 0x26 ) {
F_33 ( V_15 , V_96 ) ;
}
return V_74 ;
default:
return V_74 ;
}
}
static void F_34 ( struct V_38 * V_39 )
{
struct V_103 * V_104 = V_39 -> V_18 -> V_33 ;
struct V_38 * V_105 ;
if ( ! V_104 -> V_106 ||
V_39 -> V_107 >= V_39 -> V_108 )
return;
if ( F_11 ( V_13 ,
V_39 -> V_109 + V_39 -> V_110 ) )
return;
if ( F_11 ( V_13 ,
V_39 -> V_111 + V_39 -> V_110 ) )
return;
F_23 (tmp_sdev, sdev->host) {
if ( V_105 -> V_112 != V_39 -> V_112 ||
V_105 -> V_113 != V_39 -> V_113 ||
V_105 -> V_107 == V_39 -> V_108 )
continue;
V_104 -> V_106 ( V_105 , V_105 -> V_107 + 1 ,
V_114 ) ;
V_39 -> V_109 = V_13 ;
}
}
static void F_35 ( struct V_38 * V_39 )
{
struct V_103 * V_104 = V_39 -> V_18 -> V_33 ;
struct V_38 * V_105 ;
if ( ! V_104 -> V_106 )
return;
F_23 (tmp_sdev, sdev->host) {
if ( V_105 -> V_112 != V_39 -> V_112 ||
V_105 -> V_113 != V_39 -> V_113 )
continue;
V_104 -> V_106 ( V_105 , V_105 -> V_107 - 1 ,
V_115 ) ;
}
}
static int F_36 ( struct V_14 * V_15 )
{
if ( F_37 ( V_15 -> V_34 ) == V_116 ) {
return F_30 ( V_15 ) ;
}
if ( F_37 ( V_15 -> V_34 ) != V_117 )
return V_69 ;
if ( F_38 ( V_15 -> V_34 ) != V_118 )
return V_69 ;
switch ( F_39 ( V_15 -> V_34 ) ) {
case V_119 :
F_34 ( V_15 -> V_17 ) ;
case V_120 :
return V_74 ;
case V_121 :
return F_30 ( V_15 ) ;
case V_122 :
case V_123 :
case V_124 :
return V_74 ;
case V_125 :
if ( V_15 -> V_70 [ 0 ] == V_71 )
return V_74 ;
return V_69 ;
case V_126 :
F_35 ( V_15 -> V_17 ) ;
case V_127 :
return V_75 ;
default:
return V_69 ;
}
return V_69 ;
}
static void V_73 ( struct V_14 * V_15 )
{
struct V_128 * V_129 ;
F_4 ( 3 ,
F_5 ( L_18 ,
V_42 , V_15 , V_15 -> V_34 ) ) ;
V_129 = V_15 -> V_17 -> V_18 -> V_129 ;
if ( V_129 )
F_40 ( V_129 ) ;
}
static int F_41 ( struct V_14 * V_15 )
{
unsigned long V_6 ;
int V_28 ;
struct V_1 * V_18 = V_15 -> V_17 -> V_18 ;
struct V_103 * V_33 = V_18 -> V_33 ;
F_4 ( 3 , F_5 ( L_19 ,
V_42 ) ) ;
if ( ! V_33 -> V_130 )
return V_69 ;
V_28 = V_33 -> V_130 ( V_15 ) ;
if ( V_28 == V_74 ) {
if ( ! V_33 -> V_131 )
F_42 ( V_132 ) ;
F_7 ( V_18 -> V_7 , V_6 ) ;
F_43 ( V_18 , F_44 ( V_15 ) ) ;
F_9 ( V_18 -> V_7 , V_6 ) ;
}
return V_28 ;
}
static int F_45 ( struct V_14 * V_15 )
{
unsigned long V_6 ;
int V_28 ;
struct V_1 * V_18 = V_15 -> V_17 -> V_18 ;
struct V_103 * V_33 = V_18 -> V_33 ;
F_4 ( 3 , F_5 ( L_20 ,
V_42 ) ) ;
if ( ! V_33 -> V_133 )
return V_69 ;
V_28 = V_33 -> V_133 ( V_15 ) ;
if ( V_28 == V_74 ) {
if ( ! V_33 -> V_131 )
F_42 ( V_134 ) ;
F_7 ( V_18 -> V_7 , V_6 ) ;
F_43 ( V_18 , F_44 ( V_15 ) ) ;
F_9 ( V_18 -> V_7 , V_6 ) ;
}
return V_28 ;
}
static void F_46 ( struct V_38 * V_39 , void * V_135 )
{
V_39 -> V_136 = 1 ;
V_39 -> V_88 = 1 ;
}
static int F_47 ( struct V_14 * V_15 )
{
unsigned long V_6 ;
int V_28 ;
struct V_1 * V_18 = V_15 -> V_17 -> V_18 ;
struct V_103 * V_33 = V_18 -> V_33 ;
if ( ! V_33 -> V_137 )
return V_69 ;
V_28 = V_33 -> V_137 ( V_15 ) ;
if ( V_28 == V_74 ) {
F_7 ( V_18 -> V_7 , V_6 ) ;
F_48 ( F_49 ( V_15 -> V_17 ) , NULL ,
F_46 ) ;
F_9 ( V_18 -> V_7 , V_6 ) ;
}
return V_28 ;
}
static int F_50 ( struct V_14 * V_15 )
{
int V_28 ;
struct V_103 * V_33 = V_15 -> V_17 -> V_18 -> V_33 ;
if ( ! V_33 -> V_138 )
return V_69 ;
V_28 = V_33 -> V_138 ( V_15 ) ;
if ( V_28 == V_74 )
F_46 ( V_15 -> V_17 , NULL ) ;
return V_28 ;
}
static int F_51 ( struct V_103 * V_33 , struct V_14 * V_15 )
{
if ( ! V_33 -> V_139 )
return V_69 ;
return V_33 -> V_139 ( V_15 ) ;
}
static void F_52 ( struct V_14 * V_15 )
{
if ( F_51 ( V_15 -> V_17 -> V_18 -> V_33 , V_15 ) != V_74 )
if ( F_50 ( V_15 ) != V_74 )
if ( F_47 ( V_15 ) != V_74 )
if ( F_45 ( V_15 ) != V_74 )
F_41 ( V_15 ) ;
}
void F_53 ( struct V_14 * V_15 , struct V_140 * V_141 ,
unsigned char * V_70 , int V_142 , unsigned V_143 )
{
struct V_38 * V_39 = V_15 -> V_17 ;
V_141 -> V_144 = V_15 -> V_144 ;
V_141 -> V_70 = V_15 -> V_70 ;
V_141 -> V_145 = V_15 -> V_146 ;
V_141 -> V_147 = V_15 -> V_147 ;
V_141 -> V_148 = V_15 -> V_25 -> V_148 ;
V_141 -> V_34 = V_15 -> V_34 ;
V_141 -> V_149 = V_15 -> V_149 ;
V_141 -> V_150 = V_15 -> V_150 ;
V_15 -> V_150 = V_151 ;
V_15 -> V_70 = V_141 -> V_152 ;
memset ( V_15 -> V_70 , 0 , V_153 ) ;
memset ( & V_15 -> V_147 , 0 , sizeof( V_15 -> V_147 ) ) ;
V_15 -> V_25 -> V_148 = NULL ;
if ( V_143 ) {
V_15 -> V_147 . V_154 = F_54 ( unsigned , V_155 ,
V_143 ) ;
F_55 ( & V_141 -> V_156 , V_15 -> V_82 ,
V_15 -> V_147 . V_154 ) ;
V_15 -> V_147 . V_157 . V_158 = & V_141 -> V_156 ;
V_15 -> V_146 = V_159 ;
V_15 -> V_147 . V_157 . V_160 = 1 ;
V_15 -> V_70 [ 0 ] = V_161 ;
V_15 -> V_70 [ 4 ] = V_15 -> V_147 . V_154 ;
V_15 -> V_144 = F_56 ( V_15 -> V_70 [ 0 ] ) ;
} else {
V_15 -> V_146 = V_162 ;
if ( V_70 ) {
F_57 ( V_142 > V_153 ) ;
memcpy ( V_15 -> V_70 , V_70 , V_142 ) ;
V_15 -> V_144 = F_56 ( V_15 -> V_70 [ 0 ] ) ;
}
}
V_15 -> V_149 = 0 ;
if ( V_39 -> V_163 <= V_164 && V_39 -> V_163 != V_165 )
V_15 -> V_70 [ 1 ] = ( V_15 -> V_70 [ 1 ] & 0x1f ) |
( V_39 -> V_166 << 5 & 0xe0 ) ;
memset ( V_15 -> V_82 , 0 , V_155 ) ;
}
void F_58 ( struct V_14 * V_15 , struct V_140 * V_141 )
{
V_15 -> V_144 = V_141 -> V_144 ;
V_15 -> V_70 = V_141 -> V_70 ;
V_15 -> V_146 = V_141 -> V_145 ;
V_15 -> V_147 = V_141 -> V_147 ;
V_15 -> V_25 -> V_148 = V_141 -> V_148 ;
V_15 -> V_34 = V_141 -> V_34 ;
V_15 -> V_149 = V_141 -> V_149 ;
V_15 -> V_150 = V_141 -> V_150 ;
}
static int F_59 ( struct V_14 * V_15 , unsigned char * V_70 ,
int V_142 , int V_167 , unsigned V_143 )
{
struct V_38 * V_39 = V_15 -> V_17 ;
struct V_1 * V_2 = V_39 -> V_18 ;
F_60 ( V_168 ) ;
unsigned long V_169 = V_167 ;
struct V_140 V_141 ;
const unsigned long V_170 = F_61 ( 100 ) ;
int V_28 ;
V_171:
F_53 ( V_15 , & V_141 , V_70 , V_142 , V_143 ) ;
V_2 -> V_129 = & V_168 ;
F_62 ( V_15 ) ;
V_15 -> V_72 = V_73 ;
V_28 = V_2 -> V_33 -> V_172 ( V_2 , V_15 ) ;
if ( V_28 ) {
if ( V_169 > V_170 ) {
F_58 ( V_15 , & V_141 ) ;
V_169 -= V_170 ;
F_63 ( F_64 ( V_170 ) ) ;
goto V_171;
}
V_169 = 0 ;
V_28 = V_75 ;
} else {
V_169 = F_65 ( & V_168 , V_167 ) ;
}
V_2 -> V_129 = NULL ;
F_16 ( V_15 , V_28 ) ;
F_4 ( 3 ,
F_5 ( L_21 ,
V_42 , V_15 , V_169 ) ) ;
if ( V_169 ) {
V_28 = F_36 ( V_15 ) ;
F_4 ( 3 ,
F_5 ( L_22 ,
V_42 , V_28 ) ) ;
switch ( V_28 ) {
case V_74 :
case V_75 :
case V_69 :
break;
case V_101 :
V_28 = V_75 ;
break;
default:
V_28 = V_69 ;
break;
}
} else if ( ! V_28 ) {
F_52 ( V_15 ) ;
V_28 = V_69 ;
}
F_58 ( V_15 , & V_141 ) ;
if ( V_15 -> V_25 -> V_173 != V_174 ) {
struct V_175 * V_176 = F_66 ( V_15 ) ;
if ( V_176 -> V_129 )
V_28 = V_176 -> V_129 ( V_15 , V_70 , V_142 , V_28 ) ;
}
return V_28 ;
}
static int F_67 ( struct V_14 * V_15 )
{
return F_59 ( V_15 , NULL , 0 , V_15 -> V_17 -> V_177 , ~ 0 ) ;
}
void F_68 ( struct V_14 * V_15 , struct V_43 * V_178 )
{
V_15 -> V_17 -> V_18 -> V_4 -- ;
V_15 -> V_21 = 0 ;
F_69 ( & V_15 -> V_22 , V_178 ) ;
}
int F_70 ( struct V_43 * V_44 ,
struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_179 ;
struct V_1 * V_2 ;
int V_28 ;
unsigned long V_6 ;
F_71 (scmd, next, work_q, eh_entry) {
if ( ( V_15 -> V_21 & V_36 ) ||
F_72 ( V_15 ) )
continue;
V_2 = V_15 -> V_17 -> V_18 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_73 ( V_49 , V_2 ,
L_23 ,
V_42 ) ) ;
break;
}
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 2 , F_74 ( V_49 , V_15 ,
L_24 ,
V_180 -> V_181 ) ) ;
V_28 = F_67 ( V_15 ) ;
if ( V_28 != V_74 )
continue;
F_4 ( 3 , F_5 ( L_25
L_26 , V_15 ,
V_15 -> V_34 ) ) ;
F_4 ( 3 , F_75 ( L_27 , V_15 ) ) ;
V_28 = F_76 ( V_15 ) ;
if ( V_28 == V_74 )
V_15 -> V_182 = V_15 -> V_183 ;
else if ( V_28 != V_75 )
continue;
F_68 ( V_15 , V_178 ) ;
}
return F_77 ( V_44 ) ;
}
static int F_78 ( struct V_14 * V_15 )
{
static unsigned char V_184 [ 6 ] = { V_71 , 0 , 0 , 0 , 0 , 0 } ;
int V_185 = 1 , V_28 ;
V_186:
V_28 = F_59 ( V_15 , V_184 , 6 ,
V_15 -> V_17 -> V_177 , 0 ) ;
F_4 ( 3 , F_5 ( L_28 ,
V_42 , V_15 , V_28 ) ) ;
switch ( V_28 ) {
case V_75 :
if ( V_185 -- )
goto V_186;
case V_74 :
return 0 ;
default:
return 1 ;
}
}
static int F_79 ( struct V_43 * V_187 ,
struct V_43 * V_44 ,
struct V_43 * V_178 , int V_188 )
{
struct V_14 * V_15 , * V_179 ;
struct V_38 * V_39 ;
int V_189 ;
unsigned long V_6 ;
while ( ! F_77 ( V_187 ) ) {
V_15 = F_80 ( V_187 -> V_179 , struct V_14 , V_22 ) ;
V_39 = V_15 -> V_17 ;
if ( ! V_188 ) {
F_7 ( V_39 -> V_18 -> V_7 , V_6 ) ;
if ( F_10 ( V_39 -> V_18 ) ) {
F_81 ( V_187 , V_44 ) ;
F_9 ( V_39 -> V_18 -> V_7 ,
V_6 ) ;
F_4 ( 3 ,
F_73 ( V_49 , V_39 -> V_18 ,
L_29 ,
V_42 ) ) ;
break;
}
F_9 ( V_39 -> V_18 -> V_7 , V_6 ) ;
}
V_189 = ! F_21 ( V_15 -> V_17 ) ||
( V_188 && ! F_82 ( V_15 ) &&
! F_78 ( V_15 ) ) ||
! F_78 ( V_15 ) ;
F_71 (scmd, next, cmd_list, eh_entry)
if ( V_15 -> V_17 == V_39 ) {
if ( V_189 )
F_68 ( V_15 , V_178 ) ;
else
F_69 ( & V_15 -> V_22 , V_44 ) ;
}
}
return F_77 ( V_44 ) ;
}
static int F_83 ( struct V_43 * V_44 ,
struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_179 ;
F_84 ( V_190 ) ;
int V_28 ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_71 (scmd, next, work_q, eh_entry) {
if ( ! ( V_15 -> V_21 & V_36 ) )
continue;
V_2 = V_15 -> V_17 -> V_18 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( V_2 -> V_7 , V_6 ) ;
F_81 ( & V_190 , V_44 ) ;
F_4 ( 3 ,
F_73 ( V_49 , V_2 ,
L_23 ,
V_42 ) ) ;
return F_77 ( V_44 ) ;
}
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 , F_5 ( L_30
L_31 , V_180 -> V_181 ,
V_15 ) ) ;
V_28 = F_51 ( V_2 -> V_33 , V_15 ) ;
if ( V_28 == V_69 ) {
F_4 ( 3 , F_5 ( L_32
L_33
L_31 ,
V_180 -> V_181 ,
V_15 ) ) ;
F_81 ( & V_190 , V_44 ) ;
return F_77 ( V_44 ) ;
}
V_15 -> V_21 &= ~ V_36 ;
if ( V_28 == V_191 )
F_68 ( V_15 , V_178 ) ;
else
F_69 ( & V_15 -> V_22 , & V_190 ) ;
}
return F_79 ( & V_190 , V_44 , V_178 , 0 ) ;
}
static int F_82 ( struct V_14 * V_15 )
{
static unsigned char V_192 [ 6 ] = { V_193 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_15 -> V_17 -> V_89 ) {
int V_194 , V_28 = V_75 ;
for ( V_194 = 0 ; V_28 == V_75 && V_194 < 2 ; V_194 ++ )
V_28 = F_59 ( V_15 , V_192 , 6 , V_15 -> V_17 -> V_195 -> V_196 , 0 ) ;
if ( V_28 == V_74 )
return 0 ;
}
return 1 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_197 , * V_179 ;
struct V_38 * V_39 ;
unsigned long V_6 ;
F_23 (sdev, shost) {
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_73 ( V_49 , V_2 ,
L_23 ,
V_42 ) ) ;
break;
}
F_9 ( V_2 -> V_7 , V_6 ) ;
V_197 = NULL ;
F_24 (scmd, work_q, eh_entry)
if ( V_15 -> V_17 == V_39 && F_72 ( V_15 ) &&
F_30 ( V_15 ) == V_69 ) {
V_197 = V_15 ;
break;
}
if ( ! V_197 )
continue;
F_4 ( 3 , F_5 ( L_34
L_35 , V_180 -> V_181 , V_39 ) ) ;
if ( ! F_82 ( V_197 ) ) {
if ( ! F_21 ( V_39 ) ||
! F_78 ( V_197 ) ) {
F_71 (scmd, next,
work_q, eh_entry) {
if ( V_15 -> V_17 == V_39 )
F_68 ( V_15 , V_178 ) ;
}
}
} else {
F_4 ( 3 ,
F_5 ( L_36
L_35 , V_180 -> V_181 , V_39 ) ) ;
}
}
return F_77 ( V_44 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_198 , * V_179 ;
struct V_38 * V_39 ;
unsigned long V_6 ;
int V_28 ;
F_23 (sdev, shost) {
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_73 ( V_49 , V_2 ,
L_23 ,
V_42 ) ) ;
break;
}
F_9 ( V_2 -> V_7 , V_6 ) ;
V_198 = NULL ;
F_24 (scmd, work_q, eh_entry)
if ( V_15 -> V_17 == V_39 ) {
V_198 = V_15 ;
break;
}
if ( ! V_198 )
continue;
F_4 ( 3 , F_5 ( L_37
L_35 , V_180 -> V_181 ,
V_39 ) ) ;
V_28 = F_50 ( V_198 ) ;
if ( V_28 == V_74 || V_28 == V_191 ) {
if ( ! F_21 ( V_39 ) ||
V_28 == V_191 ||
! F_78 ( V_198 ) ) {
F_71 (scmd, next,
work_q, eh_entry) {
if ( V_15 -> V_17 == V_39 )
F_68 ( V_15 ,
V_178 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_38
L_39
L_31 ,
V_180 -> V_181 ,
V_39 ) ) ;
}
}
return F_77 ( V_44 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_43 * V_178 )
{
F_84 ( V_199 ) ;
F_84 ( V_190 ) ;
F_81 ( V_44 , & V_199 ) ;
while ( ! F_77 ( & V_199 ) ) {
struct V_14 * V_179 , * V_15 ;
int V_28 ;
unsigned int V_113 ;
unsigned long V_6 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( V_2 -> V_7 , V_6 ) ;
F_81 ( & V_190 , V_44 ) ;
F_81 ( & V_199 , V_44 ) ;
F_4 ( 3 ,
F_73 ( V_49 , V_2 ,
L_23 ,
V_42 ) ) ;
return F_77 ( V_44 ) ;
}
F_9 ( V_2 -> V_7 , V_6 ) ;
V_15 = F_80 ( V_199 . V_179 , struct V_14 , V_22 ) ;
V_113 = F_88 ( V_15 ) ;
F_4 ( 3 , F_5 ( L_40
L_41 ,
V_180 -> V_181 , V_113 ) ) ;
V_28 = F_47 ( V_15 ) ;
if ( V_28 != V_74 && V_28 != V_191 )
F_4 ( 3 , F_5 ( L_42
L_43
L_44 ,
V_180 -> V_181 , V_113 ) ) ;
F_71 (scmd, next, &tmp_list, eh_entry) {
if ( F_88 ( V_15 ) != V_113 )
continue;
if ( V_28 == V_74 )
F_69 ( & V_15 -> V_22 , & V_190 ) ;
else if ( V_28 == V_191 )
F_68 ( V_15 , V_178 ) ;
else
F_89 ( & V_15 -> V_22 , V_44 ) ;
}
}
return F_79 ( & V_190 , V_44 , V_178 , 0 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_200 , * V_179 ;
F_84 ( V_190 ) ;
unsigned int V_112 ;
int V_28 ;
unsigned long V_6 ;
for ( V_112 = 0 ; V_112 <= V_2 -> V_201 ; V_112 ++ ) {
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( V_2 -> V_7 , V_6 ) ;
F_81 ( & V_190 , V_44 ) ;
F_4 ( 3 ,
F_73 ( V_49 , V_2 ,
L_23 ,
V_42 ) ) ;
return F_77 ( V_44 ) ;
}
F_9 ( V_2 -> V_7 , V_6 ) ;
V_200 = NULL ;
F_24 (scmd, work_q, eh_entry) {
if ( V_112 == F_44 ( V_15 ) ) {
V_200 = V_15 ;
break;
}
}
if ( ! V_200 )
continue;
F_4 ( 3 , F_5 ( L_45
L_46 , V_180 -> V_181 ,
V_112 ) ) ;
V_28 = F_45 ( V_200 ) ;
if ( V_28 == V_74 || V_28 == V_191 ) {
F_71 (scmd, next, work_q, eh_entry) {
if ( V_112 == F_44 ( V_15 ) ) {
if ( V_28 == V_191 )
F_68 ( V_15 ,
V_178 ) ;
else
F_69 ( & V_15 -> V_22 ,
& V_190 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_47
L_48 ,
V_180 -> V_181 ,
V_112 ) ) ;
}
}
return F_79 ( & V_190 , V_44 , V_178 , 0 ) ;
}
static int F_91 ( struct V_43 * V_44 ,
struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_179 ;
F_84 ( V_190 ) ;
int V_28 ;
if ( ! F_77 ( V_44 ) ) {
V_15 = F_80 ( V_44 -> V_179 ,
struct V_14 , V_22 ) ;
F_4 ( 3 , F_5 ( L_49
, V_180 -> V_181 ) ) ;
V_28 = F_41 ( V_15 ) ;
if ( V_28 == V_74 ) {
F_81 ( V_44 , & V_190 ) ;
} else if ( V_28 == V_191 ) {
F_71 (scmd, next, work_q, eh_entry) {
F_68 ( V_15 , V_178 ) ;
}
} else {
F_4 ( 3 , F_5 ( L_50
L_51 ,
V_180 -> V_181 ) ) ;
}
}
return F_79 ( & V_190 , V_44 , V_178 , 1 ) ;
}
static void F_92 ( struct V_43 * V_44 ,
struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_179 ;
F_71 (scmd, next, work_q, eh_entry) {
F_25 ( V_49 , V_15 -> V_17 , L_52
L_53 ) ;
F_93 ( V_15 -> V_17 , V_202 ) ;
if ( V_15 -> V_21 & V_36 ) {
}
F_68 ( V_15 , V_178 ) ;
}
return;
}
int F_94 ( struct V_14 * V_15 )
{
switch ( F_37 ( V_15 -> V_34 ) ) {
case V_117 :
break;
case V_203 :
return ( V_15 -> V_25 -> V_204 & V_205 ) ;
case V_206 :
return ( V_15 -> V_25 -> V_204 & V_207 ) ;
case V_208 :
if ( F_38 ( V_15 -> V_34 ) == V_118 &&
F_39 ( V_15 -> V_34 ) == V_125 )
return 0 ;
case V_209 :
return ( V_15 -> V_25 -> V_204 & V_210 ) ;
}
switch ( F_39 ( V_15 -> V_34 ) ) {
case V_121 :
if ( V_15 -> V_25 -> V_204 & V_207 ||
V_15 -> V_25 -> V_173 == V_174 )
return 1 ;
}
return 0 ;
}
int F_76 ( struct V_14 * V_15 )
{
int V_28 ;
if ( ! F_21 ( V_15 -> V_17 ) ) {
F_4 ( 5 , F_5 ( L_54
L_55 ,
V_42 ) ) ;
return V_74 ;
}
switch ( F_37 ( V_15 -> V_34 ) ) {
case V_211 :
V_15 -> V_34 &= 0xff00ffff ;
return V_74 ;
case V_117 :
break;
case V_212 :
case V_213 :
case V_214 :
return V_74 ;
case V_209 :
goto V_215;
case V_216 :
return V_75 ;
case V_217 :
return V_101 ;
case V_218 :
goto V_215;
case V_219 :
return V_74 ;
case V_208 :
if ( F_38 ( V_15 -> V_34 ) == V_118 &&
F_39 ( V_15 -> V_34 ) == V_125 )
break;
case V_203 :
case V_206 :
goto V_215;
case V_35 :
if ( ( V_15 -> V_70 [ 0 ] == V_71 ||
V_15 -> V_70 [ 0 ] == V_220 ) ) {
return V_74 ;
} else {
return V_69 ;
}
case V_116 :
return V_74 ;
default:
return V_69 ;
}
if ( F_38 ( V_15 -> V_34 ) != V_118 )
return V_69 ;
switch ( F_39 ( V_15 -> V_34 ) ) {
case V_126 :
F_35 ( V_15 -> V_17 ) ;
case V_127 :
return V_101 ;
case V_119 :
if ( V_15 -> V_70 [ 0 ] == V_221 )
V_15 -> V_17 -> V_50 -> V_51 = 0 ;
F_34 ( V_15 -> V_17 ) ;
case V_120 :
return V_74 ;
case V_222 :
goto V_215;
case V_121 :
V_28 = F_30 ( V_15 ) ;
if ( V_28 == V_75 )
goto V_215;
return V_28 ;
case V_122 :
case V_123 :
case V_124 :
case V_223 :
return V_74 ;
case V_125 :
F_25 ( V_49 , V_15 -> V_17 ,
L_56 ) ;
F_33 ( V_15 , V_224 ) ;
return V_74 ;
default:
return V_69 ;
}
return V_69 ;
V_215:
if ( ( ++ V_15 -> V_182 ) <= V_15 -> V_183
&& ! F_94 ( V_15 ) ) {
return V_75 ;
} else {
return V_74 ;
}
}
static void F_95 ( struct V_25 * V_26 , int V_225 )
{
F_96 ( V_26 -> V_226 , V_26 ) ;
}
static void F_97 ( struct V_38 * V_39 )
{
struct V_25 * V_26 ;
V_26 = F_98 ( V_39 -> V_195 , V_227 , V_228 ) ;
V_26 -> V_229 [ 0 ] = V_230 ;
V_26 -> V_229 [ 1 ] = 0 ;
V_26 -> V_229 [ 2 ] = 0 ;
V_26 -> V_229 [ 3 ] = 0 ;
V_26 -> V_229 [ 4 ] = V_231 ;
V_26 -> V_229 [ 5 ] = 0 ;
V_26 -> V_144 = F_56 ( V_26 -> V_229 [ 0 ] ) ;
V_26 -> V_173 = V_174 ;
V_26 -> V_204 |= V_232 ;
V_26 -> V_167 = 10 * V_233 ;
V_26 -> V_182 = 5 ;
F_99 ( V_26 -> V_226 , NULL , V_26 , 1 , F_95 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
unsigned long V_6 ;
F_23 (sdev, shost) {
if ( F_21 ( V_39 ) && V_39 -> V_234 )
F_97 ( V_39 ) ;
}
F_4 ( 3 ,
F_5 ( L_57 ,
V_2 -> V_235 ) ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_236 ) )
if ( F_8 ( V_2 , V_237 ) )
F_57 ( F_8 ( V_2 , V_238 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_101 ( & V_2 -> V_41 ) ;
F_102 ( V_2 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( V_2 -> V_10 )
if ( F_8 ( V_2 , V_8 ) )
F_103 ( F_8 ( V_2 , V_9 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
}
void F_104 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_43 * V_178 )
{
if ( ! F_85 ( V_2 , V_44 , V_178 ) )
if ( ! F_86 ( V_2 , V_44 , V_178 ) )
if ( ! F_87 ( V_2 , V_44 , V_178 ) )
if ( ! F_90 ( V_2 , V_44 , V_178 ) )
if ( ! F_91 ( V_44 , V_178 ) )
F_92 ( V_44 ,
V_178 ) ;
}
void F_105 ( struct V_43 * V_178 )
{
struct V_14 * V_15 , * V_179 ;
F_71 (scmd, next, done_q, eh_entry) {
F_106 ( & V_15 -> V_22 ) ;
if ( F_21 ( V_15 -> V_17 ) &&
! F_94 ( V_15 ) &&
( ++ V_15 -> V_182 <= V_15 -> V_183 ) ) {
F_4 ( 3 , F_5 ( L_58
L_59 ,
V_180 -> V_181 ,
V_15 ) ) ;
F_107 ( V_15 , V_239 ) ;
} else {
if ( ! V_15 -> V_34 )
V_15 -> V_34 |= ( V_240 << 24 ) ;
F_4 ( 3 , F_5 ( L_60
L_61 ,
V_180 -> V_181 , V_15 ) ) ;
F_108 ( V_15 ) ;
}
}
}
static void F_109 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_84 ( V_241 ) ;
F_84 ( V_242 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
F_81 ( & V_2 -> V_23 , & V_241 ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 1 , F_22 ( V_2 , & V_241 ) ) ;
if ( ! F_70 ( & V_241 , & V_242 ) )
if ( ! F_83 ( & V_241 , & V_242 ) )
F_104 ( V_2 , & V_241 , & V_242 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( V_2 -> V_12 )
V_2 -> V_11 = 0 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_105 ( & V_242 ) ;
}
int F_110 ( void * V_135 )
{
struct V_1 * V_2 = V_135 ;
while ( ! F_111 () ) {
F_112 ( V_243 ) ;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_10 == 0 ) ||
V_2 -> V_4 != V_2 -> V_3 ) {
F_4 ( 1 ,
F_5 ( L_62 ,
V_2 -> V_235 ) ) ;
F_113 () ;
continue;
}
F_114 ( V_244 ) ;
F_4 ( 1 ,
F_5 ( L_63 ,
V_2 -> V_235 , V_2 -> V_10 ,
V_2 -> V_4 , V_2 -> V_3 ) ) ;
if ( ! V_2 -> V_245 && F_115 ( V_2 ) != 0 ) {
F_4 ( 1 ,
F_5 ( V_246 L_64
L_65 ,
V_2 -> V_235 ) ) ;
continue;
}
if ( V_2 -> V_31 -> V_247 )
V_2 -> V_31 -> V_247 ( V_2 ) ;
else
F_109 ( V_2 ) ;
F_100 ( V_2 ) ;
if ( ! V_2 -> V_245 )
F_116 ( V_2 ) ;
}
F_114 ( V_244 ) ;
F_4 ( 1 ,
F_5 ( L_66 , V_2 -> V_235 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_43 ( struct V_1 * V_2 , int V_112 )
{
struct V_38 * V_39 ;
F_117 (sdev, shost) {
if ( V_112 == F_118 ( V_39 ) )
F_46 ( V_39 , NULL ) ;
}
}
void F_119 ( struct V_1 * V_2 , int V_112 , int V_248 )
{
struct V_38 * V_39 ;
F_117 (sdev, shost) {
if ( V_112 == F_118 ( V_39 ) &&
V_248 == F_120 ( V_39 ) )
F_46 ( V_39 , NULL ) ;
}
}
static void
F_121 ( struct V_14 * V_15 )
{
}
int
F_122 ( struct V_38 * V_249 , int V_250 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 = V_249 -> V_18 ;
struct V_25 V_26 ;
unsigned long V_6 ;
int V_28 ;
if ( F_115 ( V_2 ) < 0 )
return V_69 ;
V_15 = F_123 ( V_249 , V_228 ) ;
F_124 ( NULL , & V_26 ) ;
V_15 -> V_25 = & V_26 ;
V_15 -> V_70 = V_26 . V_229 ;
V_15 -> V_72 = F_121 ;
memset ( & V_15 -> V_147 , 0 , sizeof( V_15 -> V_147 ) ) ;
V_15 -> V_144 = 0 ;
V_15 -> V_146 = V_251 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_252 = 1 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
switch ( V_250 ) {
case V_253 :
V_28 = F_50 ( V_15 ) ;
if ( V_28 == V_74 )
break;
case V_254 :
V_28 = F_47 ( V_15 ) ;
if ( V_28 == V_74 )
break;
case V_255 :
V_28 = F_45 ( V_15 ) ;
if ( V_28 == V_74 )
break;
case V_256 :
V_28 = F_41 ( V_15 ) ;
break;
default:
V_28 = V_69 ;
}
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_252 = 0 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_5 ( L_67 ,
V_42 ) ) ;
F_101 ( & V_2 -> V_41 ) ;
F_102 ( V_2 ) ;
F_125 ( V_15 ) ;
F_116 ( V_2 ) ;
return V_28 ;
}
int F_126 ( const T_1 * V_82 , int V_257 ,
struct V_52 * V_53 )
{
if ( ! V_82 || ! V_257 )
return 0 ;
memset ( V_53 , 0 , sizeof( struct V_52 ) ) ;
V_53 -> V_81 = ( V_82 [ 0 ] & 0x7f ) ;
if ( ! F_127 ( V_53 ) )
return 0 ;
if ( V_53 -> V_81 >= 0x72 ) {
if ( V_257 > 1 )
V_53 -> V_57 = ( V_82 [ 1 ] & 0xf ) ;
if ( V_257 > 2 )
V_53 -> V_59 = V_82 [ 2 ] ;
if ( V_257 > 3 )
V_53 -> V_60 = V_82 [ 3 ] ;
if ( V_257 > 7 )
V_53 -> V_83 = V_82 [ 7 ] ;
} else {
if ( V_257 > 2 )
V_53 -> V_57 = ( V_82 [ 2 ] & 0xf ) ;
if ( V_257 > 7 ) {
V_257 = ( V_257 < ( V_82 [ 7 ] + 8 ) ) ?
V_257 : ( V_82 [ 7 ] + 8 ) ;
if ( V_257 > 12 )
V_53 -> V_59 = V_82 [ 12 ] ;
if ( V_257 > 13 )
V_53 -> V_60 = V_82 [ 13 ] ;
}
}
return 1 ;
}
int F_31 ( struct V_14 * V_229 ,
struct V_52 * V_53 )
{
return F_126 ( V_229 -> V_82 ,
V_155 , V_53 ) ;
}
const T_1 * F_128 ( const T_1 * V_82 , int V_257 ,
int V_258 )
{
int V_259 , V_260 , V_261 , V_262 ;
const T_1 * V_263 ;
if ( ( V_257 < 8 ) || ( 0 == ( V_259 = V_82 [ 7 ] ) ) )
return NULL ;
if ( ( V_82 [ 0 ] < 0x72 ) || ( V_82 [ 0 ] > 0x73 ) )
return NULL ;
V_259 = ( V_259 < ( V_257 - 8 ) ) ?
V_259 : ( V_257 - 8 ) ;
V_263 = & V_82 [ 8 ] ;
for ( V_261 = 0 , V_262 = 0 ; V_262 < V_259 ; V_262 += V_261 ) {
V_263 += V_261 ;
V_260 = ( V_262 < ( V_259 - 1 ) ) ? V_263 [ 1 ] : - 1 ;
V_261 = V_260 + 2 ;
if ( V_263 [ 0 ] == V_258 )
return V_263 ;
if ( V_260 < 0 )
break;
}
return NULL ;
}
int F_129 ( const T_1 * V_82 , int V_257 ,
T_2 * V_264 )
{
int V_265 ;
const T_1 * V_266 ;
T_2 V_267 ;
if ( V_257 < 7 )
return 0 ;
switch ( V_82 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_82 [ 0 ] & 0x80 ) {
* V_264 = ( V_82 [ 3 ] << 24 ) +
( V_82 [ 4 ] << 16 ) +
( V_82 [ 5 ] << 8 ) + V_82 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_266 = F_128 ( V_82 , V_257 ,
0 ) ;
if ( V_266 && ( 0xa == V_266 [ 1 ] ) ) {
V_267 = 0 ;
for ( V_265 = 0 ; V_265 < 8 ; ++ V_265 ) {
if ( V_265 > 0 )
V_267 <<= 8 ;
V_267 |= V_266 [ 4 + V_265 ] ;
}
* V_264 = V_267 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
void F_130 ( int V_268 , T_1 * V_269 , T_1 V_270 , T_1 V_59 , T_1 V_60 )
{
if ( V_268 ) {
V_269 [ 0 ] = 0x72 ;
V_269 [ 1 ] = V_270 ;
V_269 [ 2 ] = V_59 ;
V_269 [ 3 ] = V_60 ;
V_269 [ 7 ] = 0 ;
} else {
V_269 [ 0 ] = 0x70 ;
V_269 [ 2 ] = V_270 ;
V_269 [ 7 ] = 0xa ;
V_269 [ 12 ] = V_59 ;
V_269 [ 13 ] = V_60 ;
}
}
