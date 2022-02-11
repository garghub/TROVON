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
int F_10 ( struct V_11 * V_12 , int V_13 )
{
struct V_1 * V_2 = V_12 -> V_14 -> V_15 ;
unsigned long V_6 ;
int V_16 = 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_8 ) )
if ( F_8 ( V_2 , V_9 ) )
goto V_17;
V_16 = 1 ;
V_12 -> V_18 |= V_13 ;
F_11 ( & V_12 -> V_19 , & V_2 -> V_20 ) ;
V_2 -> V_4 ++ ;
F_1 ( V_2 ) ;
V_17:
F_9 ( V_2 -> V_7 , V_6 ) ;
return V_16 ;
}
enum V_21 F_12 ( struct V_22 * V_23 )
{
struct V_11 * V_12 = V_23 -> V_24 ;
enum V_21 V_25 = V_26 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
F_13 ( V_12 ) ;
F_14 ( V_12 , V_27 ) ;
if ( V_15 -> V_28 -> V_29 )
V_25 = V_15 -> V_28 -> V_29 ( V_12 ) ;
else if ( V_15 -> V_30 -> V_29 )
V_25 = V_15 -> V_30 -> V_29 ( V_12 ) ;
V_12 -> V_31 |= V_32 << 16 ;
if ( F_15 ( V_25 == V_26 &&
! F_10 ( V_12 , V_33 ) ) )
V_25 = V_34 ;
return V_25 ;
}
int F_16 ( struct V_35 * V_36 )
{
int V_37 ;
F_17 ( V_36 -> V_15 -> V_38 , ! F_18 ( V_36 -> V_15 ) ) ;
V_37 = F_19 ( V_36 ) ;
F_4 ( 5 , F_5 ( L_2 , V_39 ,
V_37 ) ) ;
return V_37 ;
}
static inline void F_20 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_11 * V_12 ;
struct V_35 * V_36 ;
int V_42 = 0 ;
int V_43 = 0 ;
int V_44 = 0 ;
int V_45 = 0 ;
F_21 (sdev, shost) {
F_22 (scmd, work_q, eh_entry) {
if ( V_12 -> V_14 == V_36 ) {
++ V_42 ;
if ( V_12 -> V_18 & V_33 )
++ V_44 ;
else
++ V_43 ;
}
}
if ( V_44 || V_43 ) {
F_4 ( 3 ,
F_23 ( V_46 , V_36 ,
L_3 ,
V_39 , V_43 ,
V_44 ) ) ;
V_44 = 0 ;
V_43 = 0 ;
++ V_45 ;
}
}
F_4 ( 2 , F_5 ( L_4
L_5 ,
V_42 , V_45 ) ) ;
}
static void F_24 ( struct V_35 * V_36 )
{
V_36 -> V_47 -> V_48 = 1 ;
}
static void F_25 ( struct V_35 * V_36 ,
struct V_49 * V_50 )
{
enum V_51 V_52 = V_53 ;
if ( V_50 -> V_54 == V_55 ) {
if ( V_50 -> V_56 == 0x3f && V_50 -> V_57 == 0x03 ) {
V_52 = V_58 ;
F_23 ( V_59 , V_36 ,
L_6 ) ;
} else if ( V_50 -> V_56 == 0x3f && V_50 -> V_57 == 0x0e ) {
V_52 = V_60 ;
F_24 ( V_36 ) ;
F_23 ( V_59 , V_36 ,
L_7
L_8
L_9
L_10 ) ;
} else if ( V_50 -> V_56 == 0x3f )
F_23 ( V_59 , V_36 ,
L_7
L_11
L_9
L_12 ) ;
if ( V_50 -> V_56 == 0x38 && V_50 -> V_57 == 0x07 ) {
V_52 = V_61 ;
F_23 ( V_59 , V_36 ,
L_7
L_13
L_14 ) ;
}
if ( V_50 -> V_56 == 0x2a && V_50 -> V_57 == 0x01 ) {
V_52 = V_62 ;
F_23 ( V_59 , V_36 ,
L_15 ) ;
} else if ( V_50 -> V_56 == 0x2a && V_50 -> V_57 == 0x09 ) {
V_52 = V_63 ;
F_23 ( V_59 , V_36 ,
L_16 ) ;
} else if ( V_50 -> V_56 == 0x2a )
F_23 ( V_59 , V_36 ,
L_17 ) ;
}
if ( V_52 != V_53 ) {
F_26 ( V_52 , V_36 -> V_64 ) ;
F_27 ( & V_36 -> V_65 ) ;
}
}
static int F_28 ( struct V_11 * V_12 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
struct V_49 V_50 ;
if ( ! F_29 ( V_12 , & V_50 ) )
return V_66 ;
if ( V_12 -> V_67 [ 0 ] == V_68 && V_12 -> V_69 != V_70 )
return V_71 ;
F_25 ( V_36 , & V_50 ) ;
if ( F_30 ( & V_50 ) )
return V_72 ;
if ( V_36 -> V_73 && V_36 -> V_73 -> V_74 &&
V_36 -> V_73 -> V_74 -> V_75 ) {
int V_76 ;
V_76 = V_36 -> V_73 -> V_74 -> V_75 ( V_36 , & V_50 ) ;
if ( V_76 != V_77 )
return V_76 ;
}
if ( V_50 . V_78 == 0x70 ) {
if ( V_12 -> V_79 [ 2 ] & 0xe0 )
return V_71 ;
} else {
if ( ( V_50 . V_80 > 3 ) &&
( V_12 -> V_79 [ 8 ] == 0x4 ) &&
( V_12 -> V_79 [ 11 ] & 0xe0 ) )
return V_71 ;
}
switch ( V_50 . V_54 ) {
case V_81 :
return V_71 ;
case V_82 :
return V_71 ;
case V_83 :
if ( V_50 . V_56 == 0x10 )
return V_71 ;
return V_72 ;
case V_84 :
case V_55 :
if ( V_12 -> V_14 -> V_85 ) {
if ( V_50 . V_56 != 0x28 || V_50 . V_57 != 0x00 ) {
V_12 -> V_14 -> V_85 = 0 ;
return V_72 ;
}
}
if ( V_12 -> V_14 -> V_47 -> V_48 &&
V_50 . V_56 == 0x3f && V_50 . V_57 == 0x0e )
return V_72 ;
if ( ( V_50 . V_56 == 0x04 ) && ( V_50 . V_57 == 0x01 ) )
return V_72 ;
if ( V_12 -> V_14 -> V_86 &&
( V_50 . V_56 == 0x04 ) && ( V_50 . V_57 == 0x02 ) )
return V_66 ;
return V_71 ;
case V_87 :
if ( V_50 . V_56 == 0x27 && V_50 . V_57 == 0x07 ) {
F_31 ( V_12 , V_88 ) ;
return V_71 ;
}
case V_89 :
case V_90 :
case V_91 :
case V_92 :
F_31 ( V_12 , V_93 ) ;
return V_71 ;
case V_94 :
if ( V_50 . V_56 == 0x11 ||
V_50 . V_56 == 0x13 ||
V_50 . V_56 == 0x14 ) {
F_31 ( V_12 , V_95 ) ;
return V_71 ;
}
return V_72 ;
case V_96 :
if ( V_12 -> V_14 -> V_97 )
return V_98 ;
else
F_31 ( V_12 , V_93 ) ;
case V_99 :
if ( V_50 . V_56 == 0x20 ||
V_50 . V_56 == 0x21 ||
V_50 . V_56 == 0x24 ||
V_50 . V_56 == 0x26 ) {
F_31 ( V_12 , V_93 ) ;
}
return V_71 ;
default:
return V_71 ;
}
}
static void F_32 ( struct V_35 * V_36 )
{
struct V_100 * V_101 = V_36 -> V_15 -> V_30 ;
struct V_35 * V_102 ;
if ( ! V_101 -> V_103 ||
V_36 -> V_104 >= V_36 -> V_105 )
return;
if ( F_33 ( V_106 ,
V_36 -> V_107 + V_36 -> V_108 ) )
return;
if ( F_33 ( V_106 ,
V_36 -> V_109 + V_36 -> V_108 ) )
return;
F_21 (tmp_sdev, sdev->host) {
if ( V_102 -> V_110 != V_36 -> V_110 ||
V_102 -> V_111 != V_36 -> V_111 ||
V_102 -> V_104 == V_36 -> V_105 )
continue;
V_101 -> V_103 ( V_102 , V_102 -> V_104 + 1 ,
V_112 ) ;
V_36 -> V_107 = V_106 ;
}
}
static void F_34 ( struct V_35 * V_36 )
{
struct V_100 * V_101 = V_36 -> V_15 -> V_30 ;
struct V_35 * V_102 ;
if ( ! V_101 -> V_103 )
return;
F_21 (tmp_sdev, sdev->host) {
if ( V_102 -> V_110 != V_36 -> V_110 ||
V_102 -> V_111 != V_36 -> V_111 )
continue;
V_101 -> V_103 ( V_102 , V_102 -> V_104 - 1 ,
V_113 ) ;
}
}
static int F_35 ( struct V_11 * V_12 )
{
if ( F_36 ( V_12 -> V_31 ) == V_114 ) {
return F_28 ( V_12 ) ;
}
if ( F_36 ( V_12 -> V_31 ) != V_115 )
return V_66 ;
if ( F_37 ( V_12 -> V_31 ) != V_116 )
return V_66 ;
switch ( F_38 ( V_12 -> V_31 ) ) {
case V_117 :
F_32 ( V_12 -> V_14 ) ;
case V_118 :
return V_71 ;
case V_119 :
return F_28 ( V_12 ) ;
case V_120 :
case V_121 :
case V_122 :
return V_71 ;
case V_123 :
if ( V_12 -> V_67 [ 0 ] == V_68 )
return V_71 ;
return V_66 ;
case V_124 :
F_34 ( V_12 -> V_14 ) ;
case V_125 :
return V_72 ;
default:
return V_66 ;
}
return V_66 ;
}
static void V_70 ( struct V_11 * V_12 )
{
struct V_126 * V_127 ;
F_4 ( 3 ,
F_5 ( L_18 ,
V_39 , V_12 , V_12 -> V_31 ) ) ;
V_127 = V_12 -> V_14 -> V_15 -> V_127 ;
if ( V_127 )
F_39 ( V_127 ) ;
}
static int F_40 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_100 * V_30 = V_15 -> V_30 ;
F_4 ( 3 , F_5 ( L_19 ,
V_39 ) ) ;
if ( ! V_30 -> V_128 )
return V_66 ;
V_25 = V_30 -> V_128 ( V_12 ) ;
if ( V_25 == V_71 ) {
if ( ! V_30 -> V_129 )
F_41 ( V_130 ) ;
F_7 ( V_15 -> V_7 , V_6 ) ;
F_42 ( V_15 , F_43 ( V_12 ) ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static int F_44 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_100 * V_30 = V_15 -> V_30 ;
F_4 ( 3 , F_5 ( L_20 ,
V_39 ) ) ;
if ( ! V_30 -> V_131 )
return V_66 ;
V_25 = V_30 -> V_131 ( V_12 ) ;
if ( V_25 == V_71 ) {
if ( ! V_30 -> V_129 )
F_41 ( V_132 ) ;
F_7 ( V_15 -> V_7 , V_6 ) ;
F_42 ( V_15 , F_43 ( V_12 ) ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static void F_45 ( struct V_35 * V_36 , void * V_133 )
{
V_36 -> V_134 = 1 ;
V_36 -> V_85 = 1 ;
}
static int F_46 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_100 * V_30 = V_15 -> V_30 ;
if ( ! V_30 -> V_135 )
return V_66 ;
V_25 = V_30 -> V_135 ( V_12 ) ;
if ( V_25 == V_71 ) {
F_7 ( V_15 -> V_7 , V_6 ) ;
F_47 ( F_48 ( V_12 -> V_14 ) , NULL ,
F_45 ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static int F_49 ( struct V_11 * V_12 )
{
int V_25 ;
struct V_100 * V_30 = V_12 -> V_14 -> V_15 -> V_30 ;
if ( ! V_30 -> V_136 )
return V_66 ;
V_25 = V_30 -> V_136 ( V_12 ) ;
if ( V_25 == V_71 )
F_45 ( V_12 -> V_14 , NULL ) ;
return V_25 ;
}
static int F_50 ( struct V_100 * V_30 , struct V_11 * V_12 )
{
if ( ! V_30 -> V_137 )
return V_66 ;
return V_30 -> V_137 ( V_12 ) ;
}
static void F_51 ( struct V_11 * V_12 )
{
if ( F_50 ( V_12 -> V_14 -> V_15 -> V_30 , V_12 ) != V_71 )
if ( F_49 ( V_12 ) != V_71 )
if ( F_46 ( V_12 ) != V_71 )
if ( F_44 ( V_12 ) != V_71 )
F_40 ( V_12 ) ;
}
void F_52 ( struct V_11 * V_12 , struct V_138 * V_139 ,
unsigned char * V_67 , int V_140 , unsigned V_141 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
V_139 -> V_142 = V_12 -> V_142 ;
V_139 -> V_67 = V_12 -> V_67 ;
V_139 -> V_143 = V_12 -> V_144 ;
V_139 -> V_145 = V_12 -> V_145 ;
V_139 -> V_146 = V_12 -> V_22 -> V_146 ;
V_139 -> V_31 = V_12 -> V_31 ;
V_139 -> V_147 = V_12 -> V_147 ;
V_139 -> V_148 = V_12 -> V_148 ;
V_12 -> V_148 = V_149 ;
V_12 -> V_67 = V_139 -> V_150 ;
memset ( V_12 -> V_67 , 0 , V_151 ) ;
memset ( & V_12 -> V_145 , 0 , sizeof( V_12 -> V_145 ) ) ;
V_12 -> V_22 -> V_146 = NULL ;
if ( V_141 ) {
V_12 -> V_145 . V_152 = F_53 ( unsigned , V_153 ,
V_141 ) ;
F_54 ( & V_139 -> V_154 , V_12 -> V_79 ,
V_12 -> V_145 . V_152 ) ;
V_12 -> V_145 . V_155 . V_156 = & V_139 -> V_154 ;
V_12 -> V_144 = V_157 ;
V_12 -> V_145 . V_155 . V_158 = 1 ;
V_12 -> V_67 [ 0 ] = V_159 ;
V_12 -> V_67 [ 4 ] = V_12 -> V_145 . V_152 ;
V_12 -> V_142 = F_55 ( V_12 -> V_67 [ 0 ] ) ;
} else {
V_12 -> V_144 = V_160 ;
if ( V_67 ) {
F_56 ( V_140 > V_151 ) ;
memcpy ( V_12 -> V_67 , V_67 , V_140 ) ;
V_12 -> V_142 = F_55 ( V_12 -> V_67 [ 0 ] ) ;
}
}
V_12 -> V_147 = 0 ;
if ( V_36 -> V_161 <= V_162 && V_36 -> V_161 != V_163 )
V_12 -> V_67 [ 1 ] = ( V_12 -> V_67 [ 1 ] & 0x1f ) |
( V_36 -> V_164 << 5 & 0xe0 ) ;
memset ( V_12 -> V_79 , 0 , V_153 ) ;
}
void F_57 ( struct V_11 * V_12 , struct V_138 * V_139 )
{
V_12 -> V_142 = V_139 -> V_142 ;
V_12 -> V_67 = V_139 -> V_67 ;
V_12 -> V_144 = V_139 -> V_143 ;
V_12 -> V_145 = V_139 -> V_145 ;
V_12 -> V_22 -> V_146 = V_139 -> V_146 ;
V_12 -> V_31 = V_139 -> V_31 ;
V_12 -> V_147 = V_139 -> V_147 ;
V_12 -> V_148 = V_139 -> V_148 ;
}
static int F_58 ( struct V_11 * V_12 , unsigned char * V_67 ,
int V_140 , int V_165 , unsigned V_141 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
struct V_1 * V_2 = V_36 -> V_15 ;
F_59 ( V_166 ) ;
unsigned long V_167 = V_165 ;
struct V_138 V_139 ;
const unsigned long V_168 = F_60 ( 100 ) ;
int V_25 ;
V_169:
F_52 ( V_12 , & V_139 , V_67 , V_140 , V_141 ) ;
V_2 -> V_127 = & V_166 ;
F_61 ( V_12 ) ;
V_12 -> V_69 = V_70 ;
V_25 = V_2 -> V_30 -> V_170 ( V_2 , V_12 ) ;
if ( V_25 ) {
if ( V_167 > V_168 ) {
F_57 ( V_12 , & V_139 ) ;
V_167 -= V_168 ;
F_62 ( F_63 ( V_168 ) ) ;
goto V_169;
}
V_167 = 0 ;
V_25 = V_72 ;
} else {
V_167 = F_64 ( & V_166 , V_165 ) ;
}
V_2 -> V_127 = NULL ;
F_14 ( V_12 , V_25 ) ;
F_4 ( 3 ,
F_5 ( L_21 ,
V_39 , V_12 , V_167 ) ) ;
if ( V_167 ) {
V_25 = F_35 ( V_12 ) ;
F_4 ( 3 ,
F_5 ( L_22 ,
V_39 , V_25 ) ) ;
switch ( V_25 ) {
case V_71 :
case V_72 :
case V_66 :
break;
case V_98 :
V_25 = V_72 ;
break;
default:
V_25 = V_66 ;
break;
}
} else if ( ! V_25 ) {
F_51 ( V_12 ) ;
V_25 = V_66 ;
}
F_57 ( V_12 , & V_139 ) ;
if ( V_12 -> V_22 -> V_171 != V_172 ) {
struct V_173 * V_174 = F_65 ( V_12 ) ;
if ( V_174 -> V_127 )
V_25 = V_174 -> V_127 ( V_12 , V_67 , V_140 , V_25 ) ;
}
return V_25 ;
}
static int F_66 ( struct V_11 * V_12 )
{
return F_58 ( V_12 , NULL , 0 , V_12 -> V_14 -> V_175 , ~ 0 ) ;
}
void F_67 ( struct V_11 * V_12 , struct V_40 * V_176 )
{
V_12 -> V_14 -> V_15 -> V_4 -- ;
V_12 -> V_18 = 0 ;
F_68 ( & V_12 -> V_19 , V_176 ) ;
}
int F_69 ( struct V_40 * V_41 ,
struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_177 ;
int V_25 ;
F_70 (scmd, next, work_q, eh_entry) {
if ( ( V_12 -> V_18 & V_33 ) ||
F_71 ( V_12 ) )
continue;
F_4 ( 2 , F_72 ( V_46 , V_12 ,
L_23 ,
V_178 -> V_179 ) ) ;
V_25 = F_66 ( V_12 ) ;
if ( V_25 != V_71 )
continue;
F_4 ( 3 , F_5 ( L_24
L_25 , V_12 ,
V_12 -> V_31 ) ) ;
F_4 ( 3 , F_73 ( L_26 , V_12 ) ) ;
V_25 = F_74 ( V_12 ) ;
if ( V_25 == V_71 )
V_12 -> V_180 = V_12 -> V_181 ;
else if ( V_25 != V_72 )
continue;
F_67 ( V_12 , V_176 ) ;
}
return F_75 ( V_41 ) ;
}
static int F_76 ( struct V_11 * V_12 )
{
static unsigned char V_182 [ 6 ] = { V_68 , 0 , 0 , 0 , 0 , 0 } ;
int V_183 = 1 , V_25 ;
V_184:
V_25 = F_58 ( V_12 , V_182 , 6 ,
V_12 -> V_14 -> V_175 , 0 ) ;
F_4 ( 3 , F_5 ( L_27 ,
V_39 , V_12 , V_25 ) ) ;
switch ( V_25 ) {
case V_72 :
if ( V_183 -- )
goto V_184;
case V_71 :
return 0 ;
default:
return 1 ;
}
}
static int F_77 ( struct V_40 * V_185 ,
struct V_40 * V_41 ,
struct V_40 * V_176 , int V_186 )
{
struct V_11 * V_12 , * V_177 ;
struct V_35 * V_36 ;
int V_187 ;
while ( ! F_75 ( V_185 ) ) {
V_12 = F_78 ( V_185 -> V_177 , struct V_11 , V_19 ) ;
V_36 = V_12 -> V_14 ;
V_187 = ! F_19 ( V_12 -> V_14 ) ||
( V_186 && ! F_79 ( V_12 ) &&
! F_76 ( V_12 ) ) ||
! F_76 ( V_12 ) ;
F_70 (scmd, next, cmd_list, eh_entry)
if ( V_12 -> V_14 == V_36 ) {
if ( V_187 )
F_67 ( V_12 , V_176 ) ;
else
F_68 ( & V_12 -> V_19 , V_41 ) ;
}
}
return F_75 ( V_41 ) ;
}
static int F_80 ( struct V_40 * V_41 ,
struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_177 ;
F_81 ( V_188 ) ;
int V_25 ;
F_70 (scmd, next, work_q, eh_entry) {
if ( ! ( V_12 -> V_18 & V_33 ) )
continue;
F_4 ( 3 , F_5 ( L_28
L_29 , V_178 -> V_179 ,
V_12 ) ) ;
V_25 = F_50 ( V_12 -> V_14 -> V_15 -> V_30 , V_12 ) ;
if ( V_25 == V_71 || V_25 == V_189 ) {
V_12 -> V_18 &= ~ V_33 ;
if ( V_25 == V_189 )
F_67 ( V_12 , V_176 ) ;
else
F_68 ( & V_12 -> V_19 , & V_188 ) ;
} else
F_4 ( 3 , F_5 ( L_30
L_31
L_29 ,
V_178 -> V_179 ,
V_12 ) ) ;
}
return F_77 ( & V_188 , V_41 , V_176 , 0 ) ;
}
static int F_79 ( struct V_11 * V_12 )
{
static unsigned char V_190 [ 6 ] = { V_191 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_12 -> V_14 -> V_86 ) {
int V_192 , V_25 = V_72 ;
for ( V_192 = 0 ; V_25 == V_72 && V_192 < 2 ; V_192 ++ )
V_25 = F_58 ( V_12 , V_190 , 6 , V_12 -> V_14 -> V_193 -> V_194 , 0 ) ;
if ( V_25 == V_71 )
return 0 ;
}
return 1 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_195 , * V_177 ;
struct V_35 * V_36 ;
F_21 (sdev, shost) {
V_195 = NULL ;
F_22 (scmd, work_q, eh_entry)
if ( V_12 -> V_14 == V_36 && F_71 ( V_12 ) &&
F_28 ( V_12 ) == V_66 ) {
V_195 = V_12 ;
break;
}
if ( ! V_195 )
continue;
F_4 ( 3 , F_5 ( L_32
L_33 , V_178 -> V_179 , V_36 ) ) ;
if ( ! F_79 ( V_195 ) ) {
if ( ! F_19 ( V_36 ) ||
! F_76 ( V_195 ) ) {
F_70 (scmd, next,
work_q, eh_entry) {
if ( V_12 -> V_14 == V_36 )
F_67 ( V_12 , V_176 ) ;
}
}
} else {
F_4 ( 3 ,
F_5 ( L_34
L_33 , V_178 -> V_179 , V_36 ) ) ;
}
}
return F_75 ( V_41 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_196 , * V_177 ;
struct V_35 * V_36 ;
int V_25 ;
F_21 (sdev, shost) {
V_196 = NULL ;
F_22 (scmd, work_q, eh_entry)
if ( V_12 -> V_14 == V_36 ) {
V_196 = V_12 ;
break;
}
if ( ! V_196 )
continue;
F_4 ( 3 , F_5 ( L_35
L_33 , V_178 -> V_179 ,
V_36 ) ) ;
V_25 = F_49 ( V_196 ) ;
if ( V_25 == V_71 || V_25 == V_189 ) {
if ( ! F_19 ( V_36 ) ||
V_25 == V_189 ||
! F_76 ( V_196 ) ) {
F_70 (scmd, next,
work_q, eh_entry) {
if ( V_12 -> V_14 == V_36 )
F_67 ( V_12 ,
V_176 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_36
L_37
L_29 ,
V_178 -> V_179 ,
V_36 ) ) ;
}
}
return F_75 ( V_41 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_176 )
{
F_81 ( V_197 ) ;
F_81 ( V_188 ) ;
F_85 ( V_41 , & V_197 ) ;
while ( ! F_75 ( & V_197 ) ) {
struct V_11 * V_177 , * V_12 ;
int V_25 ;
unsigned int V_111 ;
V_12 = F_78 ( V_197 . V_177 , struct V_11 , V_19 ) ;
V_111 = F_86 ( V_12 ) ;
F_4 ( 3 , F_5 ( L_38
L_39 ,
V_178 -> V_179 , V_111 ) ) ;
V_25 = F_46 ( V_12 ) ;
if ( V_25 != V_71 && V_25 != V_189 )
F_4 ( 3 , F_5 ( L_40
L_41
L_42 ,
V_178 -> V_179 , V_111 ) ) ;
F_70 (scmd, next, &tmp_list, eh_entry) {
if ( F_86 ( V_12 ) != V_111 )
continue;
if ( V_25 == V_71 )
F_68 ( & V_12 -> V_19 , & V_188 ) ;
else if ( V_25 == V_189 )
F_67 ( V_12 , V_176 ) ;
else
F_87 ( & V_12 -> V_19 , V_41 ) ;
}
}
return F_77 ( & V_188 , V_41 , V_176 , 0 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_198 , * V_177 ;
F_81 ( V_188 ) ;
unsigned int V_110 ;
int V_25 ;
for ( V_110 = 0 ; V_110 <= V_2 -> V_199 ; V_110 ++ ) {
V_198 = NULL ;
F_22 (scmd, work_q, eh_entry) {
if ( V_110 == F_43 ( V_12 ) ) {
V_198 = V_12 ;
break;
}
}
if ( ! V_198 )
continue;
F_4 ( 3 , F_5 ( L_43
L_44 , V_178 -> V_179 ,
V_110 ) ) ;
V_25 = F_44 ( V_198 ) ;
if ( V_25 == V_71 || V_25 == V_189 ) {
F_70 (scmd, next, work_q, eh_entry) {
if ( V_110 == F_43 ( V_12 ) ) {
if ( V_25 == V_189 )
F_67 ( V_12 ,
V_176 ) ;
else
F_68 ( & V_12 -> V_19 ,
& V_188 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_45
L_46 ,
V_178 -> V_179 ,
V_110 ) ) ;
}
}
return F_77 ( & V_188 , V_41 , V_176 , 0 ) ;
}
static int F_89 ( struct V_40 * V_41 ,
struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_177 ;
F_81 ( V_188 ) ;
int V_25 ;
if ( ! F_75 ( V_41 ) ) {
V_12 = F_78 ( V_41 -> V_177 ,
struct V_11 , V_19 ) ;
F_4 ( 3 , F_5 ( L_47
, V_178 -> V_179 ) ) ;
V_25 = F_40 ( V_12 ) ;
if ( V_25 == V_71 ) {
F_85 ( V_41 , & V_188 ) ;
} else if ( V_25 == V_189 ) {
F_70 (scmd, next, work_q, eh_entry) {
F_67 ( V_12 , V_176 ) ;
}
} else {
F_4 ( 3 , F_5 ( L_48
L_49 ,
V_178 -> V_179 ) ) ;
}
}
return F_77 ( & V_188 , V_41 , V_176 , 1 ) ;
}
static void F_90 ( struct V_40 * V_41 ,
struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_177 ;
F_70 (scmd, next, work_q, eh_entry) {
F_23 ( V_46 , V_12 -> V_14 , L_50
L_51 ) ;
F_91 ( V_12 -> V_14 , V_200 ) ;
if ( V_12 -> V_18 & V_33 ) {
}
F_67 ( V_12 , V_176 ) ;
}
return;
}
int F_92 ( struct V_11 * V_12 )
{
switch ( F_36 ( V_12 -> V_31 ) ) {
case V_115 :
break;
case V_201 :
return ( V_12 -> V_22 -> V_202 & V_203 ) ;
case V_204 :
return ( V_12 -> V_22 -> V_202 & V_205 ) ;
case V_206 :
if ( F_37 ( V_12 -> V_31 ) == V_116 &&
F_38 ( V_12 -> V_31 ) == V_123 )
return 0 ;
case V_207 :
return ( V_12 -> V_22 -> V_202 & V_208 ) ;
}
switch ( F_38 ( V_12 -> V_31 ) ) {
case V_119 :
if ( V_12 -> V_22 -> V_202 & V_205 ||
V_12 -> V_22 -> V_171 == V_172 )
return 1 ;
}
return 0 ;
}
int F_74 ( struct V_11 * V_12 )
{
int V_25 ;
if ( ! F_19 ( V_12 -> V_14 ) ) {
F_4 ( 5 , F_5 ( L_52
L_53 ,
V_39 ) ) ;
return V_71 ;
}
switch ( F_36 ( V_12 -> V_31 ) ) {
case V_209 :
V_12 -> V_31 &= 0xff00ffff ;
return V_71 ;
case V_115 :
break;
case V_210 :
case V_211 :
case V_212 :
return V_71 ;
case V_207 :
goto V_213;
case V_214 :
return V_72 ;
case V_215 :
return V_98 ;
case V_216 :
goto V_213;
case V_217 :
return V_71 ;
case V_206 :
if ( F_37 ( V_12 -> V_31 ) == V_116 &&
F_38 ( V_12 -> V_31 ) == V_123 )
break;
case V_201 :
case V_204 :
goto V_213;
case V_32 :
if ( ( V_12 -> V_67 [ 0 ] == V_68 ||
V_12 -> V_67 [ 0 ] == V_218 ) ) {
return V_71 ;
} else {
return V_66 ;
}
case V_114 :
return V_71 ;
default:
return V_66 ;
}
if ( F_37 ( V_12 -> V_31 ) != V_116 )
return V_66 ;
switch ( F_38 ( V_12 -> V_31 ) ) {
case V_124 :
F_34 ( V_12 -> V_14 ) ;
case V_125 :
return V_98 ;
case V_117 :
if ( V_12 -> V_67 [ 0 ] == V_219 )
V_12 -> V_14 -> V_47 -> V_48 = 0 ;
F_32 ( V_12 -> V_14 ) ;
case V_118 :
return V_71 ;
case V_220 :
goto V_213;
case V_119 :
V_25 = F_28 ( V_12 ) ;
if ( V_25 == V_72 )
goto V_213;
return V_25 ;
case V_120 :
case V_121 :
case V_122 :
case V_221 :
return V_71 ;
case V_123 :
F_23 ( V_46 , V_12 -> V_14 ,
L_54 ) ;
F_31 ( V_12 , V_222 ) ;
return V_71 ;
default:
return V_66 ;
}
return V_66 ;
V_213:
if ( ( ++ V_12 -> V_180 ) <= V_12 -> V_181
&& ! F_92 ( V_12 ) ) {
return V_72 ;
} else {
return V_71 ;
}
}
static void F_93 ( struct V_22 * V_23 , int V_223 )
{
F_94 ( V_23 -> V_224 , V_23 ) ;
}
static void F_95 ( struct V_35 * V_36 )
{
struct V_22 * V_23 ;
V_23 = F_96 ( V_36 -> V_193 , V_225 , V_226 ) ;
V_23 -> V_227 [ 0 ] = V_228 ;
V_23 -> V_227 [ 1 ] = 0 ;
V_23 -> V_227 [ 2 ] = 0 ;
V_23 -> V_227 [ 3 ] = 0 ;
V_23 -> V_227 [ 4 ] = V_229 ;
V_23 -> V_227 [ 5 ] = 0 ;
V_23 -> V_142 = F_55 ( V_23 -> V_227 [ 0 ] ) ;
V_23 -> V_171 = V_172 ;
V_23 -> V_202 |= V_230 ;
V_23 -> V_165 = 10 * V_231 ;
V_23 -> V_180 = 5 ;
F_97 ( V_23 -> V_224 , NULL , V_23 , 1 , F_93 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
unsigned long V_6 ;
F_21 (sdev, shost) {
if ( F_19 ( V_36 ) && V_36 -> V_232 )
F_95 ( V_36 ) ;
}
F_4 ( 3 , F_5 ( L_55 ,
V_39 ) ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_233 ) )
if ( F_8 ( V_2 , V_234 ) )
F_56 ( F_8 ( V_2 , V_235 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_99 ( & V_2 -> V_38 ) ;
F_100 ( V_2 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( V_2 -> V_10 )
if ( F_8 ( V_2 , V_8 ) )
F_101 ( F_8 ( V_2 , V_9 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
}
void F_102 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_176 )
{
if ( ! F_82 ( V_2 , V_41 , V_176 ) )
if ( ! F_83 ( V_2 , V_41 , V_176 ) )
if ( ! F_84 ( V_2 , V_41 , V_176 ) )
if ( ! F_88 ( V_2 , V_41 , V_176 ) )
if ( ! F_89 ( V_41 , V_176 ) )
F_90 ( V_41 ,
V_176 ) ;
}
void F_103 ( struct V_40 * V_176 )
{
struct V_11 * V_12 , * V_177 ;
F_70 (scmd, next, done_q, eh_entry) {
F_104 ( & V_12 -> V_19 ) ;
if ( F_19 ( V_12 -> V_14 ) &&
! F_92 ( V_12 ) &&
( ++ V_12 -> V_180 <= V_12 -> V_181 ) ) {
F_4 ( 3 , F_5 ( L_56
L_57 ,
V_178 -> V_179 ,
V_12 ) ) ;
F_105 ( V_12 , V_236 ) ;
} else {
if ( ! V_12 -> V_31 )
V_12 -> V_31 |= ( V_237 << 24 ) ;
F_4 ( 3 , F_5 ( L_58
L_59 ,
V_178 -> V_179 , V_12 ) ) ;
F_106 ( V_12 ) ;
}
}
}
static void F_107 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_81 ( V_238 ) ;
F_81 ( V_239 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
F_85 ( & V_2 -> V_20 , & V_238 ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 1 , F_20 ( V_2 , & V_238 ) ) ;
if ( ! F_69 ( & V_238 , & V_239 ) )
if ( ! F_80 ( & V_238 , & V_239 ) )
F_102 ( V_2 , & V_238 , & V_239 ) ;
F_103 ( & V_239 ) ;
}
int F_108 ( void * V_133 )
{
struct V_1 * V_2 = V_133 ;
while ( ! F_109 () ) {
F_110 ( V_240 ) ;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_10 == 0 ) ||
V_2 -> V_4 != V_2 -> V_3 ) {
F_4 ( 1 ,
F_5 ( L_60 ,
V_2 -> V_241 ) ) ;
F_111 () ;
continue;
}
F_112 ( V_242 ) ;
F_4 ( 1 ,
F_5 ( L_61 ,
V_2 -> V_241 ) ) ;
if ( ! V_2 -> V_243 && F_113 ( V_2 ) != 0 ) {
F_4 ( 1 ,
F_5 ( V_244 L_62
L_63 ,
V_2 -> V_241 ) ) ;
continue;
}
if ( V_2 -> V_28 -> V_245 )
V_2 -> V_28 -> V_245 ( V_2 ) ;
else
F_107 ( V_2 ) ;
F_98 ( V_2 ) ;
if ( ! V_2 -> V_243 )
F_114 ( V_2 ) ;
}
F_112 ( V_242 ) ;
F_4 ( 1 ,
F_5 ( L_64 , V_2 -> V_241 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_42 ( struct V_1 * V_2 , int V_110 )
{
struct V_35 * V_36 ;
F_115 (sdev, shost) {
if ( V_110 == F_116 ( V_36 ) )
F_45 ( V_36 , NULL ) ;
}
}
void F_117 ( struct V_1 * V_2 , int V_110 , int V_246 )
{
struct V_35 * V_36 ;
F_115 (sdev, shost) {
if ( V_110 == F_116 ( V_36 ) &&
V_246 == F_118 ( V_36 ) )
F_45 ( V_36 , NULL ) ;
}
}
static void
F_119 ( struct V_11 * V_12 )
{
}
int
F_120 ( struct V_35 * V_247 , int V_248 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_247 -> V_15 ;
struct V_22 V_23 ;
unsigned long V_6 ;
int V_25 ;
if ( F_113 ( V_2 ) < 0 )
return V_66 ;
V_12 = F_121 ( V_247 , V_226 ) ;
F_122 ( NULL , & V_23 ) ;
V_12 -> V_22 = & V_23 ;
V_12 -> V_67 = V_23 . V_227 ;
V_12 -> V_69 = F_119 ;
memset ( & V_12 -> V_145 , 0 , sizeof( V_12 -> V_145 ) ) ;
V_12 -> V_142 = 0 ;
V_12 -> V_144 = V_249 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_250 = 1 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
switch ( V_248 ) {
case V_251 :
V_25 = F_49 ( V_12 ) ;
if ( V_25 == V_71 )
break;
case V_252 :
V_25 = F_46 ( V_12 ) ;
if ( V_25 == V_71 )
break;
case V_253 :
V_25 = F_44 ( V_12 ) ;
if ( V_25 == V_71 )
break;
case V_254 :
V_25 = F_40 ( V_12 ) ;
break;
default:
V_25 = V_66 ;
}
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_250 = 0 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_5 ( L_65 ,
V_39 ) ) ;
F_99 ( & V_2 -> V_38 ) ;
F_100 ( V_2 ) ;
F_123 ( V_12 ) ;
F_114 ( V_2 ) ;
return V_25 ;
}
int F_124 ( const T_1 * V_79 , int V_255 ,
struct V_49 * V_50 )
{
if ( ! V_79 || ! V_255 )
return 0 ;
memset ( V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 -> V_78 = ( V_79 [ 0 ] & 0x7f ) ;
if ( ! F_125 ( V_50 ) )
return 0 ;
if ( V_50 -> V_78 >= 0x72 ) {
if ( V_255 > 1 )
V_50 -> V_54 = ( V_79 [ 1 ] & 0xf ) ;
if ( V_255 > 2 )
V_50 -> V_56 = V_79 [ 2 ] ;
if ( V_255 > 3 )
V_50 -> V_57 = V_79 [ 3 ] ;
if ( V_255 > 7 )
V_50 -> V_80 = V_79 [ 7 ] ;
} else {
if ( V_255 > 2 )
V_50 -> V_54 = ( V_79 [ 2 ] & 0xf ) ;
if ( V_255 > 7 ) {
V_255 = ( V_255 < ( V_79 [ 7 ] + 8 ) ) ?
V_255 : ( V_79 [ 7 ] + 8 ) ;
if ( V_255 > 12 )
V_50 -> V_56 = V_79 [ 12 ] ;
if ( V_255 > 13 )
V_50 -> V_57 = V_79 [ 13 ] ;
}
}
return 1 ;
}
int F_29 ( struct V_11 * V_227 ,
struct V_49 * V_50 )
{
return F_124 ( V_227 -> V_79 ,
V_153 , V_50 ) ;
}
const T_1 * F_126 ( const T_1 * V_79 , int V_255 ,
int V_256 )
{
int V_257 , V_258 , V_259 , V_260 ;
const T_1 * V_261 ;
if ( ( V_255 < 8 ) || ( 0 == ( V_257 = V_79 [ 7 ] ) ) )
return NULL ;
if ( ( V_79 [ 0 ] < 0x72 ) || ( V_79 [ 0 ] > 0x73 ) )
return NULL ;
V_257 = ( V_257 < ( V_255 - 8 ) ) ?
V_257 : ( V_255 - 8 ) ;
V_261 = & V_79 [ 8 ] ;
for ( V_259 = 0 , V_260 = 0 ; V_260 < V_257 ; V_260 += V_259 ) {
V_261 += V_259 ;
V_258 = ( V_260 < ( V_257 - 1 ) ) ? V_261 [ 1 ] : - 1 ;
V_259 = V_258 + 2 ;
if ( V_261 [ 0 ] == V_256 )
return V_261 ;
if ( V_258 < 0 )
break;
}
return NULL ;
}
int F_127 ( const T_1 * V_79 , int V_255 ,
T_2 * V_262 )
{
int V_263 ;
const T_1 * V_264 ;
T_2 V_265 ;
if ( V_255 < 7 )
return 0 ;
switch ( V_79 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_79 [ 0 ] & 0x80 ) {
* V_262 = ( V_79 [ 3 ] << 24 ) +
( V_79 [ 4 ] << 16 ) +
( V_79 [ 5 ] << 8 ) + V_79 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_264 = F_126 ( V_79 , V_255 ,
0 ) ;
if ( V_264 && ( 0xa == V_264 [ 1 ] ) ) {
V_265 = 0 ;
for ( V_263 = 0 ; V_263 < 8 ; ++ V_263 ) {
if ( V_263 > 0 )
V_265 <<= 8 ;
V_265 |= V_264 [ 4 + V_263 ] ;
}
* V_262 = V_265 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
void F_128 ( int V_266 , T_1 * V_267 , T_1 V_268 , T_1 V_56 , T_1 V_57 )
{
if ( V_266 ) {
V_267 [ 0 ] = 0x72 ;
V_267 [ 1 ] = V_268 ;
V_267 [ 2 ] = V_56 ;
V_267 [ 3 ] = V_57 ;
V_267 [ 7 ] = 0 ;
} else {
V_267 [ 0 ] = 0x70 ;
V_267 [ 2 ] = V_268 ;
V_267 [ 7 ] = 0xa ;
V_267 [ 12 ] = V_56 ;
V_267 [ 13 ] = V_57 ;
}
}
