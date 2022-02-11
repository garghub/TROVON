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
static int F_24 ( struct V_11 * V_12 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
struct V_47 V_48 ;
if ( ! F_25 ( V_12 , & V_48 ) )
return V_49 ;
if ( V_12 -> V_50 [ 0 ] == V_51 && V_12 -> V_52 != V_53 )
return V_54 ;
if ( F_26 ( & V_48 ) )
return V_55 ;
if ( V_36 -> V_56 && V_36 -> V_56 -> V_57 &&
V_36 -> V_56 -> V_57 -> V_58 ) {
int V_59 ;
V_59 = V_36 -> V_56 -> V_57 -> V_58 ( V_36 , & V_48 ) ;
if ( V_59 != V_60 )
return V_59 ;
}
if ( V_48 . V_61 == 0x70 ) {
if ( V_12 -> V_62 [ 2 ] & 0xe0 )
return V_54 ;
} else {
if ( ( V_48 . V_63 > 3 ) &&
( V_12 -> V_62 [ 8 ] == 0x4 ) &&
( V_12 -> V_62 [ 11 ] & 0xe0 ) )
return V_54 ;
}
switch ( V_48 . V_64 ) {
case V_65 :
return V_54 ;
case V_66 :
return V_54 ;
case V_67 :
if ( V_48 . V_68 == 0x10 )
return V_54 ;
return V_55 ;
case V_69 :
case V_70 :
if ( V_12 -> V_14 -> V_71 ) {
if ( V_48 . V_68 != 0x28 || V_48 . V_72 != 0x00 ) {
V_12 -> V_14 -> V_71 = 0 ;
return V_55 ;
}
}
if ( ( V_48 . V_68 == 0x04 ) && ( V_48 . V_72 == 0x01 ) )
return V_55 ;
if ( V_12 -> V_14 -> V_73 &&
( V_48 . V_68 == 0x04 ) && ( V_48 . V_72 == 0x02 ) )
return V_49 ;
if ( V_48 . V_68 == 0x3f && V_48 . V_72 == 0x0e )
F_27 ( V_74 , V_12 ,
L_6
L_7
L_8
L_9 ) ;
else if ( V_48 . V_68 == 0x3f )
F_27 ( V_74 , V_12 ,
L_6
L_10
L_8
L_11 ) ;
if ( V_48 . V_68 == 0x38 && V_48 . V_72 == 0x07 )
F_27 ( V_74 , V_12 ,
L_6
L_12
L_13 ) ;
return V_54 ;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return V_80 ;
case V_81 :
if ( V_48 . V_68 == 0x11 ||
V_48 . V_68 == 0x13 ||
V_48 . V_68 == 0x14 ) {
return V_80 ;
}
return V_55 ;
case V_82 :
if ( V_12 -> V_14 -> V_83 )
return V_84 ;
else
return V_80 ;
case V_85 :
if ( V_48 . V_68 == 0x20 ||
V_48 . V_68 == 0x21 ||
V_48 . V_68 == 0x24 ||
V_48 . V_68 == 0x26 ) {
return V_80 ;
}
return V_54 ;
default:
return V_54 ;
}
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_86 * V_87 = V_36 -> V_15 -> V_30 ;
struct V_35 * V_88 ;
if ( ! V_87 -> V_89 ||
V_36 -> V_90 >= V_36 -> V_91 )
return;
if ( F_29 ( V_92 ,
V_36 -> V_93 + V_36 -> V_94 ) )
return;
if ( F_29 ( V_92 ,
V_36 -> V_95 + V_36 -> V_94 ) )
return;
F_21 (tmp_sdev, sdev->host) {
if ( V_88 -> V_96 != V_36 -> V_96 ||
V_88 -> V_97 != V_36 -> V_97 ||
V_88 -> V_90 == V_36 -> V_91 )
continue;
V_87 -> V_89 ( V_88 , V_88 -> V_90 + 1 ,
V_98 ) ;
V_36 -> V_93 = V_92 ;
}
}
static void F_30 ( struct V_35 * V_36 )
{
struct V_86 * V_87 = V_36 -> V_15 -> V_30 ;
struct V_35 * V_88 ;
if ( ! V_87 -> V_89 )
return;
F_21 (tmp_sdev, sdev->host) {
if ( V_88 -> V_96 != V_36 -> V_96 ||
V_88 -> V_97 != V_36 -> V_97 )
continue;
V_87 -> V_89 ( V_88 , V_88 -> V_90 - 1 ,
V_99 ) ;
}
}
static int F_31 ( struct V_11 * V_12 )
{
if ( F_32 ( V_12 -> V_31 ) == V_100 ) {
return F_24 ( V_12 ) ;
}
if ( F_32 ( V_12 -> V_31 ) != V_101 )
return V_49 ;
if ( F_33 ( V_12 -> V_31 ) != V_102 )
return V_49 ;
switch ( F_34 ( V_12 -> V_31 ) ) {
case V_103 :
F_28 ( V_12 -> V_14 ) ;
case V_104 :
return V_54 ;
case V_105 :
return F_24 ( V_12 ) ;
case V_106 :
case V_107 :
case V_108 :
return V_54 ;
case V_109 :
if ( V_12 -> V_50 [ 0 ] == V_51 )
return V_54 ;
return V_49 ;
case V_110 :
F_30 ( V_12 -> V_14 ) ;
case V_111 :
return V_55 ;
default:
return V_49 ;
}
return V_49 ;
}
static void V_53 ( struct V_11 * V_12 )
{
struct V_112 * V_113 ;
F_4 ( 3 ,
F_5 ( L_14 ,
V_39 , V_12 , V_12 -> V_31 ) ) ;
V_113 = V_12 -> V_14 -> V_15 -> V_113 ;
if ( V_113 )
F_35 ( V_113 ) ;
}
static int F_36 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_86 * V_30 = V_15 -> V_30 ;
F_4 ( 3 , F_5 ( L_15 ,
V_39 ) ) ;
if ( ! V_30 -> V_114 )
return V_49 ;
V_25 = V_30 -> V_114 ( V_12 ) ;
if ( V_25 == V_54 ) {
if ( ! V_30 -> V_115 )
F_37 ( V_116 ) ;
F_7 ( V_15 -> V_7 , V_6 ) ;
F_38 ( V_15 , F_39 ( V_12 ) ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static int F_40 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_86 * V_30 = V_15 -> V_30 ;
F_4 ( 3 , F_5 ( L_16 ,
V_39 ) ) ;
if ( ! V_30 -> V_117 )
return V_49 ;
V_25 = V_30 -> V_117 ( V_12 ) ;
if ( V_25 == V_54 ) {
if ( ! V_30 -> V_115 )
F_37 ( V_118 ) ;
F_7 ( V_15 -> V_7 , V_6 ) ;
F_38 ( V_15 , F_39 ( V_12 ) ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static void F_41 ( struct V_35 * V_36 , void * V_119 )
{
V_36 -> V_120 = 1 ;
V_36 -> V_71 = 1 ;
}
static int F_42 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_86 * V_30 = V_15 -> V_30 ;
if ( ! V_30 -> V_121 )
return V_49 ;
V_25 = V_30 -> V_121 ( V_12 ) ;
if ( V_25 == V_54 ) {
F_7 ( V_15 -> V_7 , V_6 ) ;
F_43 ( F_44 ( V_12 -> V_14 ) , NULL ,
F_41 ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static int F_45 ( struct V_11 * V_12 )
{
int V_25 ;
struct V_86 * V_30 = V_12 -> V_14 -> V_15 -> V_30 ;
if ( ! V_30 -> V_122 )
return V_49 ;
V_25 = V_30 -> V_122 ( V_12 ) ;
if ( V_25 == V_54 )
F_41 ( V_12 -> V_14 , NULL ) ;
return V_25 ;
}
static int F_46 ( struct V_86 * V_30 , struct V_11 * V_12 )
{
if ( ! V_30 -> V_123 )
return V_49 ;
return V_30 -> V_123 ( V_12 ) ;
}
static void F_47 ( struct V_11 * V_12 )
{
if ( F_46 ( V_12 -> V_14 -> V_15 -> V_30 , V_12 ) != V_54 )
if ( F_45 ( V_12 ) != V_54 )
if ( F_42 ( V_12 ) != V_54 )
if ( F_40 ( V_12 ) != V_54 )
F_36 ( V_12 ) ;
}
void F_48 ( struct V_11 * V_12 , struct V_124 * V_125 ,
unsigned char * V_50 , int V_126 , unsigned V_127 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
V_125 -> V_128 = V_12 -> V_128 ;
V_125 -> V_50 = V_12 -> V_50 ;
V_125 -> V_129 = V_12 -> V_130 ;
V_125 -> V_131 = V_12 -> V_131 ;
V_125 -> V_132 = V_12 -> V_22 -> V_132 ;
V_125 -> V_31 = V_12 -> V_31 ;
V_125 -> V_133 = V_12 -> V_133 ;
V_125 -> V_134 = V_12 -> V_134 ;
V_12 -> V_134 = V_135 ;
V_12 -> V_50 = V_125 -> V_136 ;
memset ( V_12 -> V_50 , 0 , V_137 ) ;
memset ( & V_12 -> V_131 , 0 , sizeof( V_12 -> V_131 ) ) ;
V_12 -> V_22 -> V_132 = NULL ;
if ( V_127 ) {
V_12 -> V_131 . V_138 = F_49 ( unsigned , V_139 ,
V_127 ) ;
F_50 ( & V_125 -> V_140 , V_12 -> V_62 ,
V_12 -> V_131 . V_138 ) ;
V_12 -> V_131 . V_141 . V_142 = & V_125 -> V_140 ;
V_12 -> V_130 = V_143 ;
V_12 -> V_131 . V_141 . V_144 = 1 ;
V_12 -> V_50 [ 0 ] = V_145 ;
V_12 -> V_50 [ 4 ] = V_12 -> V_131 . V_138 ;
V_12 -> V_128 = F_51 ( V_12 -> V_50 [ 0 ] ) ;
} else {
V_12 -> V_130 = V_146 ;
if ( V_50 ) {
F_52 ( V_126 > V_137 ) ;
memcpy ( V_12 -> V_50 , V_50 , V_126 ) ;
V_12 -> V_128 = F_51 ( V_12 -> V_50 [ 0 ] ) ;
}
}
V_12 -> V_133 = 0 ;
if ( V_36 -> V_147 <= V_148 && V_36 -> V_147 != V_149 )
V_12 -> V_50 [ 1 ] = ( V_12 -> V_50 [ 1 ] & 0x1f ) |
( V_36 -> V_150 << 5 & 0xe0 ) ;
memset ( V_12 -> V_62 , 0 , V_139 ) ;
}
void F_53 ( struct V_11 * V_12 , struct V_124 * V_125 )
{
V_12 -> V_128 = V_125 -> V_128 ;
V_12 -> V_50 = V_125 -> V_50 ;
V_12 -> V_130 = V_125 -> V_129 ;
V_12 -> V_131 = V_125 -> V_131 ;
V_12 -> V_22 -> V_132 = V_125 -> V_132 ;
V_12 -> V_31 = V_125 -> V_31 ;
V_12 -> V_133 = V_125 -> V_133 ;
V_12 -> V_134 = V_125 -> V_134 ;
}
static int F_54 ( struct V_11 * V_12 , unsigned char * V_50 ,
int V_126 , int V_151 , unsigned V_127 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
struct V_1 * V_2 = V_36 -> V_15 ;
F_55 ( V_152 ) ;
unsigned long V_153 = V_151 ;
struct V_124 V_125 ;
const unsigned long V_154 = F_56 ( 100 ) ;
int V_25 ;
V_155:
F_48 ( V_12 , & V_125 , V_50 , V_126 , V_127 ) ;
V_2 -> V_113 = & V_152 ;
F_57 ( V_12 ) ;
V_12 -> V_52 = V_53 ;
V_25 = V_2 -> V_30 -> V_156 ( V_2 , V_12 ) ;
if ( V_25 ) {
if ( V_153 > V_154 ) {
F_53 ( V_12 , & V_125 ) ;
V_153 -= V_154 ;
F_58 ( F_59 ( V_154 ) ) ;
goto V_155;
}
V_153 = 0 ;
V_25 = V_55 ;
} else {
V_153 = F_60 ( & V_152 , V_151 ) ;
}
V_2 -> V_113 = NULL ;
F_14 ( V_12 , V_25 ) ;
F_4 ( 3 ,
F_5 ( L_17 ,
V_39 , V_12 , V_153 ) ) ;
if ( V_153 ) {
V_25 = F_31 ( V_12 ) ;
F_4 ( 3 ,
F_5 ( L_18 ,
V_39 , V_25 ) ) ;
switch ( V_25 ) {
case V_54 :
case V_55 :
case V_49 :
case V_80 :
break;
case V_84 :
V_25 = V_55 ;
break;
default:
V_25 = V_49 ;
break;
}
} else if ( ! V_25 ) {
F_47 ( V_12 ) ;
V_25 = V_49 ;
}
F_53 ( V_12 , & V_125 ) ;
if ( V_12 -> V_22 -> V_157 != V_158 ) {
struct V_159 * V_160 = F_61 ( V_12 ) ;
if ( V_160 -> V_113 )
V_25 = V_160 -> V_113 ( V_12 , V_50 , V_126 , V_25 ) ;
}
return V_25 ;
}
static int F_62 ( struct V_11 * V_12 )
{
return F_54 ( V_12 , NULL , 0 , V_161 , ~ 0 ) ;
}
void F_63 ( struct V_11 * V_12 , struct V_40 * V_162 )
{
V_12 -> V_14 -> V_15 -> V_4 -- ;
V_12 -> V_18 = 0 ;
F_64 ( & V_12 -> V_19 , V_162 ) ;
}
int F_65 ( struct V_40 * V_41 ,
struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_163 ;
int V_25 ;
F_66 (scmd, next, work_q, eh_entry) {
if ( ( V_12 -> V_18 & V_33 ) ||
F_67 ( V_12 ) )
continue;
F_4 ( 2 , F_27 ( V_46 , V_12 ,
L_19 ,
V_164 -> V_165 ) ) ;
V_25 = F_62 ( V_12 ) ;
if ( V_25 != V_54 )
continue;
F_4 ( 3 , F_5 ( L_20
L_21 , V_12 ,
V_12 -> V_31 ) ) ;
F_4 ( 3 , F_68 ( L_22 , V_12 ) ) ;
V_25 = F_69 ( V_12 ) ;
if ( V_25 == V_54 )
V_12 -> V_166 = V_12 -> V_167 ;
else if ( V_25 != V_55 )
continue;
F_63 ( V_12 , V_162 ) ;
}
return F_70 ( V_41 ) ;
}
static int F_71 ( struct V_11 * V_12 )
{
static unsigned char V_168 [ 6 ] = { V_51 , 0 , 0 , 0 , 0 , 0 } ;
int V_169 = 1 , V_25 ;
V_170:
V_25 = F_54 ( V_12 , V_168 , 6 , V_161 , 0 ) ;
F_4 ( 3 , F_5 ( L_23 ,
V_39 , V_12 , V_25 ) ) ;
switch ( V_25 ) {
case V_55 :
if ( V_169 -- )
goto V_170;
case V_54 :
return 0 ;
default:
return 1 ;
}
}
static int F_72 ( struct V_40 * V_171 ,
struct V_40 * V_41 ,
struct V_40 * V_162 , int V_172 )
{
struct V_11 * V_12 , * V_163 ;
struct V_35 * V_36 ;
int V_173 ;
while ( ! F_70 ( V_171 ) ) {
V_12 = F_73 ( V_171 -> V_163 , struct V_11 , V_19 ) ;
V_36 = V_12 -> V_14 ;
V_173 = ! F_19 ( V_12 -> V_14 ) ||
( V_172 && ! F_74 ( V_12 ) &&
! F_71 ( V_12 ) ) ||
! F_71 ( V_12 ) ;
F_66 (scmd, next, cmd_list, eh_entry)
if ( V_12 -> V_14 == V_36 ) {
if ( V_173 )
F_63 ( V_12 , V_162 ) ;
else
F_64 ( & V_12 -> V_19 , V_41 ) ;
}
}
return F_70 ( V_41 ) ;
}
static int F_75 ( struct V_40 * V_41 ,
struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_163 ;
F_76 ( V_174 ) ;
int V_25 ;
F_66 (scmd, next, work_q, eh_entry) {
if ( ! ( V_12 -> V_18 & V_33 ) )
continue;
F_4 ( 3 , F_5 ( L_24
L_25 , V_164 -> V_165 ,
V_12 ) ) ;
V_25 = F_46 ( V_12 -> V_14 -> V_15 -> V_30 , V_12 ) ;
if ( V_25 == V_54 || V_25 == V_175 ) {
V_12 -> V_18 &= ~ V_33 ;
if ( V_25 == V_175 )
F_63 ( V_12 , V_162 ) ;
else
F_64 ( & V_12 -> V_19 , & V_174 ) ;
} else
F_4 ( 3 , F_5 ( L_26
L_27
L_25 ,
V_164 -> V_165 ,
V_12 ) ) ;
}
return F_72 ( & V_174 , V_41 , V_162 , 0 ) ;
}
static int F_74 ( struct V_11 * V_12 )
{
static unsigned char V_176 [ 6 ] = { V_177 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_12 -> V_14 -> V_73 ) {
int V_178 , V_25 = V_55 ;
for ( V_178 = 0 ; V_25 == V_55 && V_178 < 2 ; V_178 ++ )
V_25 = F_54 ( V_12 , V_176 , 6 , V_12 -> V_14 -> V_179 -> V_180 , 0 ) ;
if ( V_25 == V_54 )
return 0 ;
}
return 1 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_181 , * V_163 ;
struct V_35 * V_36 ;
F_21 (sdev, shost) {
V_181 = NULL ;
F_22 (scmd, work_q, eh_entry)
if ( V_12 -> V_14 == V_36 && F_67 ( V_12 ) &&
F_24 ( V_12 ) == V_49 ) {
V_181 = V_12 ;
break;
}
if ( ! V_181 )
continue;
F_4 ( 3 , F_5 ( L_28
L_29 , V_164 -> V_165 , V_36 ) ) ;
if ( ! F_74 ( V_181 ) ) {
if ( ! F_19 ( V_36 ) ||
! F_71 ( V_181 ) ) {
F_66 (scmd, next,
work_q, eh_entry) {
if ( V_12 -> V_14 == V_36 )
F_63 ( V_12 , V_162 ) ;
}
}
} else {
F_4 ( 3 ,
F_5 ( L_30
L_29 , V_164 -> V_165 , V_36 ) ) ;
}
}
return F_70 ( V_41 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_182 , * V_163 ;
struct V_35 * V_36 ;
int V_25 ;
F_21 (sdev, shost) {
V_182 = NULL ;
F_22 (scmd, work_q, eh_entry)
if ( V_12 -> V_14 == V_36 ) {
V_182 = V_12 ;
break;
}
if ( ! V_182 )
continue;
F_4 ( 3 , F_5 ( L_31
L_29 , V_164 -> V_165 ,
V_36 ) ) ;
V_25 = F_45 ( V_182 ) ;
if ( V_25 == V_54 || V_25 == V_175 ) {
if ( ! F_19 ( V_36 ) ||
V_25 == V_175 ||
! F_71 ( V_182 ) ) {
F_66 (scmd, next,
work_q, eh_entry) {
if ( V_12 -> V_14 == V_36 )
F_63 ( V_12 ,
V_162 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_32
L_33
L_25 ,
V_164 -> V_165 ,
V_36 ) ) ;
}
}
return F_70 ( V_41 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_162 )
{
F_76 ( V_183 ) ;
F_76 ( V_174 ) ;
F_80 ( V_41 , & V_183 ) ;
while ( ! F_70 ( & V_183 ) ) {
struct V_11 * V_163 , * V_12 ;
int V_25 ;
unsigned int V_97 ;
V_12 = F_73 ( V_183 . V_163 , struct V_11 , V_19 ) ;
V_97 = F_81 ( V_12 ) ;
F_4 ( 3 , F_5 ( L_34
L_35 ,
V_164 -> V_165 , V_97 ) ) ;
V_25 = F_42 ( V_12 ) ;
if ( V_25 != V_54 && V_25 != V_175 )
F_4 ( 3 , F_5 ( L_36
L_37
L_38 ,
V_164 -> V_165 , V_97 ) ) ;
F_66 (scmd, next, &tmp_list, eh_entry) {
if ( F_81 ( V_12 ) != V_97 )
continue;
if ( V_25 == V_54 )
F_64 ( & V_12 -> V_19 , & V_174 ) ;
else if ( V_25 == V_175 )
F_63 ( V_12 , V_162 ) ;
else
F_82 ( & V_12 -> V_19 , V_41 ) ;
}
}
return F_72 ( & V_174 , V_41 , V_162 , 0 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_184 , * V_163 ;
F_76 ( V_174 ) ;
unsigned int V_96 ;
int V_25 ;
for ( V_96 = 0 ; V_96 <= V_2 -> V_185 ; V_96 ++ ) {
V_184 = NULL ;
F_22 (scmd, work_q, eh_entry) {
if ( V_96 == F_39 ( V_12 ) ) {
V_184 = V_12 ;
break;
}
}
if ( ! V_184 )
continue;
F_4 ( 3 , F_5 ( L_39
L_40 , V_164 -> V_165 ,
V_96 ) ) ;
V_25 = F_40 ( V_184 ) ;
if ( V_25 == V_54 || V_25 == V_175 ) {
F_66 (scmd, next, work_q, eh_entry) {
if ( V_96 == F_39 ( V_12 ) ) {
if ( V_25 == V_175 )
F_63 ( V_12 ,
V_162 ) ;
else
F_64 ( & V_12 -> V_19 ,
& V_174 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_41
L_42 ,
V_164 -> V_165 ,
V_96 ) ) ;
}
}
return F_72 ( & V_174 , V_41 , V_162 , 0 ) ;
}
static int F_84 ( struct V_40 * V_41 ,
struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_163 ;
F_76 ( V_174 ) ;
int V_25 ;
if ( ! F_70 ( V_41 ) ) {
V_12 = F_73 ( V_41 -> V_163 ,
struct V_11 , V_19 ) ;
F_4 ( 3 , F_5 ( L_43
, V_164 -> V_165 ) ) ;
V_25 = F_36 ( V_12 ) ;
if ( V_25 == V_54 ) {
F_80 ( V_41 , & V_174 ) ;
} else if ( V_25 == V_175 ) {
F_66 (scmd, next, work_q, eh_entry) {
F_63 ( V_12 , V_162 ) ;
}
} else {
F_4 ( 3 , F_5 ( L_44
L_45 ,
V_164 -> V_165 ) ) ;
}
}
return F_72 ( & V_174 , V_41 , V_162 , 1 ) ;
}
static void F_85 ( struct V_40 * V_41 ,
struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_163 ;
F_66 (scmd, next, work_q, eh_entry) {
F_23 ( V_46 , V_12 -> V_14 , L_46
L_47 ) ;
F_86 ( V_12 -> V_14 , V_186 ) ;
if ( V_12 -> V_18 & V_33 ) {
}
F_63 ( V_12 , V_162 ) ;
}
return;
}
int F_87 ( struct V_11 * V_12 )
{
switch ( F_32 ( V_12 -> V_31 ) ) {
case V_101 :
break;
case V_187 :
return ( V_12 -> V_22 -> V_188 & V_189 ) ;
case V_190 :
return ( V_12 -> V_22 -> V_188 & V_191 ) ;
case V_192 :
if ( F_33 ( V_12 -> V_31 ) == V_102 &&
F_34 ( V_12 -> V_31 ) == V_109 )
return 0 ;
case V_193 :
return ( V_12 -> V_22 -> V_188 & V_194 ) ;
}
switch ( F_34 ( V_12 -> V_31 ) ) {
case V_105 :
if ( V_12 -> V_22 -> V_188 & V_191 ||
V_12 -> V_22 -> V_157 == V_158 )
return 1 ;
}
return 0 ;
}
int F_69 ( struct V_11 * V_12 )
{
int V_25 ;
if ( ! F_19 ( V_12 -> V_14 ) ) {
F_4 ( 5 , F_5 ( L_48
L_49 ,
V_39 ) ) ;
return V_54 ;
}
switch ( F_32 ( V_12 -> V_31 ) ) {
case V_195 :
V_12 -> V_31 &= 0xff00ffff ;
return V_54 ;
case V_101 :
break;
case V_196 :
case V_197 :
case V_198 :
return V_54 ;
case V_193 :
goto V_199;
case V_200 :
return V_55 ;
case V_201 :
return V_84 ;
case V_202 :
goto V_199;
case V_203 :
return V_54 ;
case V_192 :
if ( F_33 ( V_12 -> V_31 ) == V_102 &&
F_34 ( V_12 -> V_31 ) == V_109 )
break;
case V_187 :
case V_190 :
goto V_199;
case V_32 :
if ( ( V_12 -> V_50 [ 0 ] == V_51 ||
V_12 -> V_50 [ 0 ] == V_204 ) ) {
return V_54 ;
} else {
return V_49 ;
}
case V_100 :
return V_54 ;
default:
return V_49 ;
}
if ( F_33 ( V_12 -> V_31 ) != V_102 )
return V_49 ;
switch ( F_34 ( V_12 -> V_31 ) ) {
case V_110 :
F_30 ( V_12 -> V_14 ) ;
case V_111 :
return V_84 ;
case V_103 :
F_28 ( V_12 -> V_14 ) ;
case V_104 :
return V_54 ;
case V_205 :
goto V_199;
case V_105 :
V_25 = F_24 ( V_12 ) ;
if ( V_25 == V_55 )
goto V_199;
else if ( V_25 == V_80 ) {
F_88 ( V_12 , V_206 ) ;
V_25 = V_54 ;
}
return V_25 ;
case V_106 :
case V_107 :
case V_108 :
case V_207 :
return V_54 ;
case V_109 :
F_23 ( V_46 , V_12 -> V_14 ,
L_50 ) ;
F_88 ( V_12 , V_208 ) ;
return V_54 ;
default:
return V_49 ;
}
return V_49 ;
V_199:
if ( ( ++ V_12 -> V_166 ) <= V_12 -> V_167
&& ! F_87 ( V_12 ) ) {
return V_55 ;
} else {
return V_54 ;
}
}
static void F_89 ( struct V_22 * V_23 , int V_209 )
{
F_90 ( V_23 -> V_210 , V_23 ) ;
}
static void F_91 ( struct V_35 * V_36 )
{
struct V_22 * V_23 ;
V_23 = F_92 ( V_36 -> V_179 , V_211 , V_212 ) ;
V_23 -> V_213 [ 0 ] = V_214 ;
V_23 -> V_213 [ 1 ] = 0 ;
V_23 -> V_213 [ 2 ] = 0 ;
V_23 -> V_213 [ 3 ] = 0 ;
V_23 -> V_213 [ 4 ] = V_215 ;
V_23 -> V_213 [ 5 ] = 0 ;
V_23 -> V_128 = F_51 ( V_23 -> V_213 [ 0 ] ) ;
V_23 -> V_157 = V_158 ;
V_23 -> V_188 |= V_216 ;
V_23 -> V_151 = 10 * V_217 ;
V_23 -> V_166 = 5 ;
F_93 ( V_23 -> V_210 , NULL , V_23 , 1 , F_89 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
unsigned long V_6 ;
F_21 (sdev, shost) {
if ( F_19 ( V_36 ) && V_36 -> V_218 )
F_91 ( V_36 ) ;
}
F_4 ( 3 , F_5 ( L_51 ,
V_39 ) ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_219 ) )
if ( F_8 ( V_2 , V_220 ) )
F_52 ( F_8 ( V_2 , V_221 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_95 ( & V_2 -> V_38 ) ;
F_96 ( V_2 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( V_2 -> V_10 )
if ( F_8 ( V_2 , V_8 ) )
F_97 ( F_8 ( V_2 , V_9 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
}
void F_98 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_162 )
{
if ( ! F_77 ( V_2 , V_41 , V_162 ) )
if ( ! F_78 ( V_2 , V_41 , V_162 ) )
if ( ! F_79 ( V_2 , V_41 , V_162 ) )
if ( ! F_83 ( V_2 , V_41 , V_162 ) )
if ( ! F_84 ( V_41 , V_162 ) )
F_85 ( V_41 ,
V_162 ) ;
}
void F_99 ( struct V_40 * V_162 )
{
struct V_11 * V_12 , * V_163 ;
F_66 (scmd, next, done_q, eh_entry) {
F_100 ( & V_12 -> V_19 ) ;
if ( F_19 ( V_12 -> V_14 ) &&
! F_87 ( V_12 ) &&
( ++ V_12 -> V_166 <= V_12 -> V_167 ) ) {
F_4 ( 3 , F_5 ( L_52
L_53 ,
V_164 -> V_165 ,
V_12 ) ) ;
F_101 ( V_12 , V_222 ) ;
} else {
if ( ! V_12 -> V_31 )
V_12 -> V_31 |= ( V_223 << 24 ) ;
F_4 ( 3 , F_5 ( L_54
L_55 ,
V_164 -> V_165 , V_12 ) ) ;
F_102 ( V_12 ) ;
}
}
}
static void F_103 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_76 ( V_224 ) ;
F_76 ( V_225 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
F_80 ( & V_2 -> V_20 , & V_224 ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 1 , F_20 ( V_2 , & V_224 ) ) ;
if ( ! F_65 ( & V_224 , & V_225 ) )
if ( ! F_75 ( & V_224 , & V_225 ) )
F_98 ( V_2 , & V_224 , & V_225 ) ;
F_99 ( & V_225 ) ;
}
int F_104 ( void * V_119 )
{
struct V_1 * V_2 = V_119 ;
while ( ! F_105 () ) {
F_106 ( V_226 ) ;
if ( ( V_2 -> V_4 == 0 && V_2 -> V_10 == 0 ) ||
V_2 -> V_4 != V_2 -> V_3 ) {
F_4 ( 1 ,
F_5 ( L_56 ,
V_2 -> V_227 ) ) ;
F_107 () ;
continue;
}
F_108 ( V_228 ) ;
F_4 ( 1 ,
F_5 ( L_57 ,
V_2 -> V_227 ) ) ;
if ( ! V_2 -> V_229 && F_109 ( V_2 ) != 0 ) {
F_4 ( 1 ,
F_5 ( V_230 L_58
L_59 ,
V_2 -> V_227 ) ) ;
continue;
}
if ( V_2 -> V_28 -> V_231 )
V_2 -> V_28 -> V_231 ( V_2 ) ;
else
F_103 ( V_2 ) ;
F_94 ( V_2 ) ;
if ( ! V_2 -> V_229 )
F_110 ( V_2 ) ;
}
F_108 ( V_228 ) ;
F_4 ( 1 ,
F_5 ( L_60 , V_2 -> V_227 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 , int V_96 )
{
struct V_35 * V_36 ;
F_111 (sdev, shost) {
if ( V_96 == F_112 ( V_36 ) )
F_41 ( V_36 , NULL ) ;
}
}
void F_113 ( struct V_1 * V_2 , int V_96 , int V_232 )
{
struct V_35 * V_36 ;
F_111 (sdev, shost) {
if ( V_96 == F_112 ( V_36 ) &&
V_232 == F_114 ( V_36 ) )
F_41 ( V_36 , NULL ) ;
}
}
static void
F_115 ( struct V_11 * V_12 )
{
}
int
F_116 ( struct V_35 * V_233 , int V_234 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_233 -> V_15 ;
struct V_22 V_23 ;
unsigned long V_6 ;
int V_25 ;
if ( F_109 ( V_2 ) < 0 )
return V_49 ;
V_12 = F_117 ( V_233 , V_212 ) ;
F_118 ( NULL , & V_23 ) ;
V_12 -> V_22 = & V_23 ;
V_12 -> V_50 = V_23 . V_213 ;
V_12 -> V_52 = F_115 ;
memset ( & V_12 -> V_131 , 0 , sizeof( V_12 -> V_131 ) ) ;
V_12 -> V_128 = 0 ;
V_12 -> V_130 = V_235 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_236 = 1 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
switch ( V_234 ) {
case V_237 :
V_25 = F_45 ( V_12 ) ;
if ( V_25 == V_54 )
break;
case V_238 :
V_25 = F_42 ( V_12 ) ;
if ( V_25 == V_54 )
break;
case V_239 :
V_25 = F_40 ( V_12 ) ;
if ( V_25 == V_54 )
break;
case V_240 :
V_25 = F_36 ( V_12 ) ;
break;
default:
V_25 = V_49 ;
}
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_236 = 0 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_5 ( L_61 ,
V_39 ) ) ;
F_95 ( & V_2 -> V_38 ) ;
F_96 ( V_2 ) ;
F_119 ( V_12 ) ;
F_110 ( V_2 ) ;
return V_25 ;
}
int F_120 ( const T_1 * V_62 , int V_241 ,
struct V_47 * V_48 )
{
if ( ! V_62 || ! V_241 )
return 0 ;
memset ( V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 -> V_61 = ( V_62 [ 0 ] & 0x7f ) ;
if ( ! F_121 ( V_48 ) )
return 0 ;
if ( V_48 -> V_61 >= 0x72 ) {
if ( V_241 > 1 )
V_48 -> V_64 = ( V_62 [ 1 ] & 0xf ) ;
if ( V_241 > 2 )
V_48 -> V_68 = V_62 [ 2 ] ;
if ( V_241 > 3 )
V_48 -> V_72 = V_62 [ 3 ] ;
if ( V_241 > 7 )
V_48 -> V_63 = V_62 [ 7 ] ;
} else {
if ( V_241 > 2 )
V_48 -> V_64 = ( V_62 [ 2 ] & 0xf ) ;
if ( V_241 > 7 ) {
V_241 = ( V_241 < ( V_62 [ 7 ] + 8 ) ) ?
V_241 : ( V_62 [ 7 ] + 8 ) ;
if ( V_241 > 12 )
V_48 -> V_68 = V_62 [ 12 ] ;
if ( V_241 > 13 )
V_48 -> V_72 = V_62 [ 13 ] ;
}
}
return 1 ;
}
int F_25 ( struct V_11 * V_213 ,
struct V_47 * V_48 )
{
return F_120 ( V_213 -> V_62 ,
V_139 , V_48 ) ;
}
const T_1 * F_122 ( const T_1 * V_62 , int V_241 ,
int V_242 )
{
int V_243 , V_244 , V_245 , V_246 ;
const T_1 * V_247 ;
if ( ( V_241 < 8 ) || ( 0 == ( V_243 = V_62 [ 7 ] ) ) )
return NULL ;
if ( ( V_62 [ 0 ] < 0x72 ) || ( V_62 [ 0 ] > 0x73 ) )
return NULL ;
V_243 = ( V_243 < ( V_241 - 8 ) ) ?
V_243 : ( V_241 - 8 ) ;
V_247 = & V_62 [ 8 ] ;
for ( V_245 = 0 , V_246 = 0 ; V_246 < V_243 ; V_246 += V_245 ) {
V_247 += V_245 ;
V_244 = ( V_246 < ( V_243 - 1 ) ) ? V_247 [ 1 ] : - 1 ;
V_245 = V_244 + 2 ;
if ( V_247 [ 0 ] == V_242 )
return V_247 ;
if ( V_244 < 0 )
break;
}
return NULL ;
}
int F_123 ( const T_1 * V_62 , int V_241 ,
T_2 * V_248 )
{
int V_249 ;
const T_1 * V_250 ;
T_2 V_251 ;
if ( V_241 < 7 )
return 0 ;
switch ( V_62 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_62 [ 0 ] & 0x80 ) {
* V_248 = ( V_62 [ 3 ] << 24 ) +
( V_62 [ 4 ] << 16 ) +
( V_62 [ 5 ] << 8 ) + V_62 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_250 = F_122 ( V_62 , V_241 ,
0 ) ;
if ( V_250 && ( 0xa == V_250 [ 1 ] ) ) {
V_251 = 0 ;
for ( V_249 = 0 ; V_249 < 8 ; ++ V_249 ) {
if ( V_249 > 0 )
V_251 <<= 8 ;
V_251 |= V_250 [ 4 + V_249 ] ;
}
* V_248 = V_251 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
void F_124 ( int V_252 , T_1 * V_253 , T_1 V_254 , T_1 V_68 , T_1 V_72 )
{
if ( V_252 ) {
V_253 [ 0 ] = 0x72 ;
V_253 [ 1 ] = V_254 ;
V_253 [ 2 ] = V_68 ;
V_253 [ 3 ] = V_72 ;
V_253 [ 7 ] = 0 ;
} else {
V_253 [ 0 ] = 0x70 ;
V_253 [ 2 ] = V_254 ;
V_253 [ 7 ] = 0xa ;
V_253 [ 12 ] = V_68 ;
V_253 [ 13 ] = V_72 ;
}
}
