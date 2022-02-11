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
if ( F_15 ( V_25 == V_26 &&
! F_10 ( V_12 , V_31 ) ) ) {
V_12 -> V_32 |= V_33 << 16 ;
V_25 = V_34 ;
}
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
if ( V_12 -> V_18 & V_31 )
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
if ( F_26 ( & V_48 ) )
return V_50 ;
if ( V_36 -> V_51 && V_36 -> V_51 -> V_52 &&
V_36 -> V_51 -> V_52 -> V_53 ) {
int V_54 ;
V_54 = V_36 -> V_51 -> V_52 -> V_53 ( V_36 , & V_48 ) ;
if ( V_54 != V_55 )
return V_54 ;
}
if ( V_48 . V_56 == 0x70 ) {
if ( V_12 -> V_57 [ 2 ] & 0xe0 )
return V_58 ;
} else {
if ( ( V_48 . V_59 > 3 ) &&
( V_12 -> V_57 [ 8 ] == 0x4 ) &&
( V_12 -> V_57 [ 11 ] & 0xe0 ) )
return V_58 ;
}
switch ( V_48 . V_60 ) {
case V_61 :
return V_58 ;
case V_62 :
return V_58 ;
case V_63 :
if ( V_48 . V_64 == 0x10 )
return V_58 ;
return V_50 ;
case V_65 :
case V_66 :
if ( V_12 -> V_14 -> V_67 ) {
if ( V_48 . V_64 != 0x28 || V_48 . V_68 != 0x00 ) {
V_12 -> V_14 -> V_67 = 0 ;
return V_50 ;
}
}
if ( ( V_48 . V_64 == 0x04 ) && ( V_48 . V_68 == 0x01 ) )
return V_50 ;
if ( V_12 -> V_14 -> V_69 &&
( V_48 . V_64 == 0x04 ) && ( V_48 . V_68 == 0x02 ) )
return V_49 ;
if ( V_48 . V_64 == 0x3f && V_48 . V_68 == 0x0e )
F_27 ( V_70 , V_12 ,
L_6
L_7
L_8
L_9 ) ;
else if ( V_48 . V_64 == 0x3f )
F_27 ( V_70 , V_12 ,
L_6
L_10
L_8
L_11 ) ;
if ( V_48 . V_64 == 0x38 && V_48 . V_68 == 0x07 )
F_27 ( V_70 , V_12 ,
L_6
L_12
L_13 ) ;
return V_58 ;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
return V_76 ;
case V_77 :
if ( V_48 . V_64 == 0x11 ||
V_48 . V_64 == 0x13 ||
V_48 . V_64 == 0x14 ) {
return V_76 ;
}
return V_50 ;
case V_78 :
if ( V_12 -> V_14 -> V_79 )
return V_80 ;
else
return V_76 ;
case V_81 :
default:
return V_58 ;
}
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_82 * V_83 = V_36 -> V_15 -> V_30 ;
struct V_35 * V_84 ;
if ( ! V_83 -> V_85 ||
V_36 -> V_86 >= V_36 -> V_87 )
return;
if ( F_29 ( V_88 ,
V_36 -> V_89 + V_36 -> V_90 ) )
return;
if ( F_29 ( V_88 ,
V_36 -> V_91 + V_36 -> V_90 ) )
return;
F_21 (tmp_sdev, sdev->host) {
if ( V_84 -> V_92 != V_36 -> V_92 ||
V_84 -> V_93 != V_36 -> V_93 ||
V_84 -> V_86 == V_36 -> V_87 )
continue;
V_83 -> V_85 ( V_84 , V_84 -> V_86 + 1 ,
V_94 ) ;
V_36 -> V_89 = V_88 ;
}
}
static void F_30 ( struct V_35 * V_36 )
{
struct V_82 * V_83 = V_36 -> V_15 -> V_30 ;
struct V_35 * V_84 ;
if ( ! V_83 -> V_85 )
return;
F_21 (tmp_sdev, sdev->host) {
if ( V_84 -> V_92 != V_36 -> V_92 ||
V_84 -> V_93 != V_36 -> V_93 )
continue;
V_83 -> V_85 ( V_84 , V_84 -> V_86 - 1 ,
V_95 ) ;
}
}
static int F_31 ( struct V_11 * V_12 )
{
if ( F_32 ( V_12 -> V_32 ) == V_96 ) {
return F_24 ( V_12 ) ;
}
if ( F_32 ( V_12 -> V_32 ) != V_97 )
return V_49 ;
if ( F_33 ( V_12 -> V_32 ) != V_98 )
return V_49 ;
switch ( F_34 ( V_12 -> V_32 ) ) {
case V_99 :
F_28 ( V_12 -> V_14 ) ;
case V_100 :
return V_58 ;
case V_101 :
return F_24 ( V_12 ) ;
case V_102 :
case V_103 :
case V_104 :
return V_58 ;
case V_105 :
if ( V_12 -> V_106 [ 0 ] == V_107 )
return V_58 ;
return V_49 ;
case V_108 :
F_30 ( V_12 -> V_14 ) ;
case V_109 :
return V_50 ;
default:
return V_49 ;
}
return V_49 ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_110 * V_111 ;
F_4 ( 3 ,
F_5 ( L_14 ,
V_39 , V_12 , V_12 -> V_32 ) ) ;
V_111 = V_12 -> V_14 -> V_15 -> V_111 ;
if ( V_111 )
F_36 ( V_111 ) ;
}
static int F_37 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_82 * V_30 = V_15 -> V_30 ;
F_4 ( 3 , F_5 ( L_15 ,
V_39 ) ) ;
if ( ! V_30 -> V_112 )
return V_49 ;
V_25 = V_30 -> V_112 ( V_12 ) ;
if ( V_25 == V_58 ) {
if ( ! V_30 -> V_113 )
F_38 ( V_114 ) ;
F_7 ( V_15 -> V_7 , V_6 ) ;
F_39 ( V_15 , F_40 ( V_12 ) ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static int F_41 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_82 * V_30 = V_15 -> V_30 ;
F_4 ( 3 , F_5 ( L_16 ,
V_39 ) ) ;
if ( ! V_30 -> V_115 )
return V_49 ;
V_25 = V_30 -> V_115 ( V_12 ) ;
if ( V_25 == V_58 ) {
if ( ! V_30 -> V_113 )
F_38 ( V_116 ) ;
F_7 ( V_15 -> V_7 , V_6 ) ;
F_39 ( V_15 , F_40 ( V_12 ) ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static void F_42 ( struct V_35 * V_36 , void * V_117 )
{
V_36 -> V_118 = 1 ;
V_36 -> V_67 = 1 ;
}
static int F_43 ( struct V_11 * V_12 )
{
unsigned long V_6 ;
int V_25 ;
struct V_1 * V_15 = V_12 -> V_14 -> V_15 ;
struct V_82 * V_30 = V_15 -> V_30 ;
if ( ! V_30 -> V_119 )
return V_49 ;
V_25 = V_30 -> V_119 ( V_12 ) ;
if ( V_25 == V_58 ) {
F_7 ( V_15 -> V_7 , V_6 ) ;
F_44 ( F_45 ( V_12 -> V_14 ) , NULL ,
F_42 ) ;
F_9 ( V_15 -> V_7 , V_6 ) ;
}
return V_25 ;
}
static int F_46 ( struct V_11 * V_12 )
{
int V_25 ;
struct V_82 * V_30 = V_12 -> V_14 -> V_15 -> V_30 ;
if ( ! V_30 -> V_120 )
return V_49 ;
V_25 = V_30 -> V_120 ( V_12 ) ;
if ( V_25 == V_58 )
F_42 ( V_12 -> V_14 , NULL ) ;
return V_25 ;
}
static int F_47 ( struct V_82 * V_30 , struct V_11 * V_12 )
{
if ( ! V_30 -> V_121 )
return V_49 ;
return V_30 -> V_121 ( V_12 ) ;
}
static void F_48 ( struct V_11 * V_12 )
{
if ( F_47 ( V_12 -> V_14 -> V_15 -> V_30 , V_12 ) != V_58 )
if ( F_46 ( V_12 ) != V_58 )
if ( F_43 ( V_12 ) != V_58 )
if ( F_41 ( V_12 ) != V_58 )
F_37 ( V_12 ) ;
}
void F_49 ( struct V_11 * V_12 , struct V_122 * V_123 ,
unsigned char * V_106 , int V_124 , unsigned V_125 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
V_123 -> V_126 = V_12 -> V_126 ;
V_123 -> V_106 = V_12 -> V_106 ;
V_123 -> V_127 = V_12 -> V_128 ;
V_123 -> V_129 = V_12 -> V_129 ;
V_123 -> V_130 = V_12 -> V_22 -> V_130 ;
V_123 -> V_32 = V_12 -> V_32 ;
V_123 -> V_131 = V_12 -> V_131 ;
V_123 -> V_132 = V_12 -> V_132 ;
V_12 -> V_132 = V_133 ;
V_12 -> V_106 = V_123 -> V_134 ;
memset ( V_12 -> V_106 , 0 , V_135 ) ;
memset ( & V_12 -> V_129 , 0 , sizeof( V_12 -> V_129 ) ) ;
V_12 -> V_22 -> V_130 = NULL ;
if ( V_125 ) {
V_12 -> V_129 . V_136 = F_50 ( unsigned , V_137 ,
V_125 ) ;
F_51 ( & V_123 -> V_138 , V_12 -> V_57 ,
V_12 -> V_129 . V_136 ) ;
V_12 -> V_129 . V_139 . V_140 = & V_123 -> V_138 ;
V_12 -> V_128 = V_141 ;
V_12 -> V_129 . V_139 . V_142 = 1 ;
V_12 -> V_106 [ 0 ] = V_143 ;
V_12 -> V_106 [ 4 ] = V_12 -> V_129 . V_136 ;
V_12 -> V_126 = F_52 ( V_12 -> V_106 [ 0 ] ) ;
} else {
V_12 -> V_128 = V_144 ;
if ( V_106 ) {
F_53 ( V_124 > V_135 ) ;
memcpy ( V_12 -> V_106 , V_106 , V_124 ) ;
V_12 -> V_126 = F_52 ( V_12 -> V_106 [ 0 ] ) ;
}
}
V_12 -> V_131 = 0 ;
if ( V_36 -> V_145 <= V_146 && V_36 -> V_145 != V_147 )
V_12 -> V_106 [ 1 ] = ( V_12 -> V_106 [ 1 ] & 0x1f ) |
( V_36 -> V_148 << 5 & 0xe0 ) ;
memset ( V_12 -> V_57 , 0 , V_137 ) ;
}
void F_54 ( struct V_11 * V_12 , struct V_122 * V_123 )
{
V_12 -> V_126 = V_123 -> V_126 ;
V_12 -> V_106 = V_123 -> V_106 ;
V_12 -> V_128 = V_123 -> V_127 ;
V_12 -> V_129 = V_123 -> V_129 ;
V_12 -> V_22 -> V_130 = V_123 -> V_130 ;
V_12 -> V_32 = V_123 -> V_32 ;
V_12 -> V_131 = V_123 -> V_131 ;
V_12 -> V_132 = V_123 -> V_132 ;
}
static int F_55 ( struct V_11 * V_12 , unsigned char * V_106 ,
int V_124 , int V_149 , unsigned V_125 )
{
struct V_35 * V_36 = V_12 -> V_14 ;
struct V_1 * V_2 = V_36 -> V_15 ;
F_56 ( V_150 ) ;
unsigned long V_151 ;
struct V_122 V_123 ;
int V_25 ;
F_49 ( V_12 , & V_123 , V_106 , V_124 , V_125 ) ;
V_2 -> V_111 = & V_150 ;
F_57 ( V_12 ) ;
V_12 -> V_152 = F_35 ;
V_2 -> V_30 -> V_153 ( V_2 , V_12 ) ;
V_151 = F_58 ( & V_150 , V_149 ) ;
V_2 -> V_111 = NULL ;
F_14 ( V_12 , V_58 ) ;
F_4 ( 3 ,
F_5 ( L_17 ,
V_39 , V_12 , V_151 ) ) ;
if ( V_151 ) {
V_25 = F_31 ( V_12 ) ;
F_4 ( 3 ,
F_5 ( L_18 ,
V_39 , V_25 ) ) ;
switch ( V_25 ) {
case V_58 :
case V_50 :
case V_49 :
case V_76 :
break;
case V_80 :
V_25 = V_50 ;
break;
default:
V_25 = V_49 ;
break;
}
} else {
F_48 ( V_12 ) ;
V_25 = V_49 ;
}
F_54 ( V_12 , & V_123 ) ;
return V_25 ;
}
static int F_59 ( struct V_11 * V_12 )
{
return F_55 ( V_12 , NULL , 0 , V_154 , ~ 0 ) ;
}
void F_60 ( struct V_11 * V_12 , struct V_40 * V_155 )
{
V_12 -> V_14 -> V_15 -> V_4 -- ;
V_12 -> V_18 = 0 ;
F_61 ( & V_12 -> V_19 , V_155 ) ;
}
int F_62 ( struct V_40 * V_41 ,
struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_156 ;
int V_25 ;
F_63 (scmd, next, work_q, eh_entry) {
if ( ( V_12 -> V_18 & V_31 ) ||
F_64 ( V_12 ) )
continue;
F_4 ( 2 , F_27 ( V_46 , V_12 ,
L_19 ,
V_157 -> V_158 ) ) ;
V_25 = F_59 ( V_12 ) ;
if ( V_25 != V_58 )
continue;
F_4 ( 3 , F_5 ( L_20
L_21 , V_12 ,
V_12 -> V_32 ) ) ;
F_4 ( 3 , F_65 ( L_22 , V_12 ) ) ;
V_25 = F_66 ( V_12 ) ;
if ( V_25 == V_58 )
V_12 -> V_159 = V_12 -> V_160 ;
else if ( V_25 != V_50 )
continue;
F_60 ( V_12 , V_155 ) ;
}
return F_67 ( V_41 ) ;
}
static int F_68 ( struct V_11 * V_12 )
{
static unsigned char V_161 [ 6 ] = { V_107 , 0 , 0 , 0 , 0 , 0 } ;
int V_162 = 1 , V_25 ;
V_163:
V_25 = F_55 ( V_12 , V_161 , 6 , V_154 , 0 ) ;
F_4 ( 3 , F_5 ( L_23 ,
V_39 , V_12 , V_25 ) ) ;
switch ( V_25 ) {
case V_50 :
if ( V_162 -- )
goto V_163;
case V_58 :
return 0 ;
default:
return 1 ;
}
}
static int F_69 ( struct V_40 * V_164 ,
struct V_40 * V_41 ,
struct V_40 * V_155 , int V_165 )
{
struct V_11 * V_12 , * V_156 ;
struct V_35 * V_36 ;
int V_166 ;
while ( ! F_67 ( V_164 ) ) {
V_12 = F_70 ( V_164 -> V_156 , struct V_11 , V_19 ) ;
V_36 = V_12 -> V_14 ;
V_166 = ! F_19 ( V_12 -> V_14 ) ||
( V_165 && ! F_71 ( V_12 ) &&
! F_68 ( V_12 ) ) ||
! F_68 ( V_12 ) ;
F_63 (scmd, next, cmd_list, eh_entry)
if ( V_12 -> V_14 == V_36 ) {
if ( V_166 )
F_60 ( V_12 , V_155 ) ;
else
F_61 ( & V_12 -> V_19 , V_41 ) ;
}
}
return F_67 ( V_41 ) ;
}
static int F_72 ( struct V_40 * V_41 ,
struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_156 ;
F_73 ( V_167 ) ;
int V_25 ;
F_63 (scmd, next, work_q, eh_entry) {
if ( ! ( V_12 -> V_18 & V_31 ) )
continue;
F_4 ( 3 , F_5 ( L_24
L_25 , V_157 -> V_158 ,
V_12 ) ) ;
V_25 = F_47 ( V_12 -> V_14 -> V_15 -> V_30 , V_12 ) ;
if ( V_25 == V_58 || V_25 == V_168 ) {
V_12 -> V_18 &= ~ V_31 ;
if ( V_25 == V_168 )
F_60 ( V_12 , V_155 ) ;
else
F_61 ( & V_12 -> V_19 , & V_167 ) ;
} else
F_4 ( 3 , F_5 ( L_26
L_27
L_25 ,
V_157 -> V_158 ,
V_12 ) ) ;
}
return F_69 ( & V_167 , V_41 , V_155 , 0 ) ;
}
static int F_71 ( struct V_11 * V_12 )
{
static unsigned char V_169 [ 6 ] = { V_170 , 0 , 0 , 0 , 1 , 0 } ;
if ( V_12 -> V_14 -> V_69 ) {
int V_171 , V_25 = V_50 ;
for ( V_171 = 0 ; V_25 == V_50 && V_171 < 2 ; V_171 ++ )
V_25 = F_55 ( V_12 , V_169 , 6 , V_12 -> V_14 -> V_172 -> V_173 , 0 ) ;
if ( V_25 == V_58 )
return 0 ;
}
return 1 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_174 , * V_156 ;
struct V_35 * V_36 ;
F_21 (sdev, shost) {
V_174 = NULL ;
F_22 (scmd, work_q, eh_entry)
if ( V_12 -> V_14 == V_36 && F_64 ( V_12 ) &&
F_24 ( V_12 ) == V_49 ) {
V_174 = V_12 ;
break;
}
if ( ! V_174 )
continue;
F_4 ( 3 , F_5 ( L_28
L_29 , V_157 -> V_158 , V_36 ) ) ;
if ( ! F_71 ( V_174 ) ) {
if ( ! F_19 ( V_36 ) ||
! F_68 ( V_174 ) ) {
F_63 (scmd, next,
work_q, eh_entry) {
if ( V_12 -> V_14 == V_36 )
F_60 ( V_12 , V_155 ) ;
}
}
} else {
F_4 ( 3 ,
F_5 ( L_30
L_29 , V_157 -> V_158 , V_36 ) ) ;
}
}
return F_67 ( V_41 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_175 , * V_156 ;
struct V_35 * V_36 ;
int V_25 ;
F_21 (sdev, shost) {
V_175 = NULL ;
F_22 (scmd, work_q, eh_entry)
if ( V_12 -> V_14 == V_36 ) {
V_175 = V_12 ;
break;
}
if ( ! V_175 )
continue;
F_4 ( 3 , F_5 ( L_31
L_29 , V_157 -> V_158 ,
V_36 ) ) ;
V_25 = F_46 ( V_175 ) ;
if ( V_25 == V_58 || V_25 == V_168 ) {
if ( ! F_19 ( V_36 ) ||
V_25 == V_168 ||
! F_68 ( V_175 ) ) {
F_63 (scmd, next,
work_q, eh_entry) {
if ( V_12 -> V_14 == V_36 )
F_60 ( V_12 ,
V_155 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_32
L_33
L_25 ,
V_157 -> V_158 ,
V_36 ) ) ;
}
}
return F_67 ( V_41 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_155 )
{
F_73 ( V_176 ) ;
F_73 ( V_167 ) ;
F_77 ( V_41 , & V_176 ) ;
while ( ! F_67 ( & V_176 ) ) {
struct V_11 * V_156 , * V_12 ;
int V_25 ;
unsigned int V_93 ;
V_12 = F_70 ( V_176 . V_156 , struct V_11 , V_19 ) ;
V_93 = F_78 ( V_12 ) ;
F_4 ( 3 , F_5 ( L_34
L_35 ,
V_157 -> V_158 , V_93 ) ) ;
V_25 = F_43 ( V_12 ) ;
if ( V_25 != V_58 && V_25 != V_168 )
F_4 ( 3 , F_5 ( L_36
L_37
L_38 ,
V_157 -> V_158 , V_93 ) ) ;
F_63 (scmd, next, &tmp_list, eh_entry) {
if ( F_78 ( V_12 ) != V_93 )
continue;
if ( V_25 == V_58 )
F_61 ( & V_12 -> V_19 , & V_167 ) ;
else if ( V_25 == V_168 )
F_60 ( V_12 , V_155 ) ;
else
F_79 ( & V_12 -> V_19 , V_41 ) ;
}
}
return F_69 ( & V_167 , V_41 , V_155 , 0 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_177 , * V_156 ;
F_73 ( V_167 ) ;
unsigned int V_92 ;
int V_25 ;
for ( V_92 = 0 ; V_92 <= V_2 -> V_178 ; V_92 ++ ) {
V_177 = NULL ;
F_22 (scmd, work_q, eh_entry) {
if ( V_92 == F_40 ( V_12 ) ) {
V_177 = V_12 ;
break;
}
}
if ( ! V_177 )
continue;
F_4 ( 3 , F_5 ( L_39
L_40 , V_157 -> V_158 ,
V_92 ) ) ;
V_25 = F_41 ( V_177 ) ;
if ( V_25 == V_58 || V_25 == V_168 ) {
F_63 (scmd, next, work_q, eh_entry) {
if ( V_92 == F_40 ( V_12 ) ) {
if ( V_25 == V_168 )
F_60 ( V_12 ,
V_155 ) ;
else
F_61 ( & V_12 -> V_19 ,
& V_167 ) ;
}
}
} else {
F_4 ( 3 , F_5 ( L_41
L_42 ,
V_157 -> V_158 ,
V_92 ) ) ;
}
}
return F_69 ( & V_167 , V_41 , V_155 , 0 ) ;
}
static int F_81 ( struct V_40 * V_41 ,
struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_156 ;
F_73 ( V_167 ) ;
int V_25 ;
if ( ! F_67 ( V_41 ) ) {
V_12 = F_70 ( V_41 -> V_156 ,
struct V_11 , V_19 ) ;
F_4 ( 3 , F_5 ( L_43
, V_157 -> V_158 ) ) ;
V_25 = F_37 ( V_12 ) ;
if ( V_25 == V_58 ) {
F_77 ( V_41 , & V_167 ) ;
} else if ( V_25 == V_168 ) {
F_63 (scmd, next, work_q, eh_entry) {
F_60 ( V_12 , V_155 ) ;
}
} else {
F_4 ( 3 , F_5 ( L_44
L_45 ,
V_157 -> V_158 ) ) ;
}
}
return F_69 ( & V_167 , V_41 , V_155 , 1 ) ;
}
static void F_82 ( struct V_40 * V_41 ,
struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_156 ;
F_63 (scmd, next, work_q, eh_entry) {
F_23 ( V_46 , V_12 -> V_14 , L_46
L_47 ) ;
F_83 ( V_12 -> V_14 , V_179 ) ;
if ( V_12 -> V_18 & V_31 ) {
}
F_60 ( V_12 , V_155 ) ;
}
return;
}
int F_84 ( struct V_11 * V_12 )
{
switch ( F_32 ( V_12 -> V_32 ) ) {
case V_97 :
break;
case V_180 :
return ( V_12 -> V_22 -> V_181 & V_182 ) ;
case V_183 :
return ( V_12 -> V_22 -> V_181 & V_184 ) ;
case V_185 :
if ( F_33 ( V_12 -> V_32 ) == V_98 &&
F_34 ( V_12 -> V_32 ) == V_105 )
return 0 ;
case V_186 :
return ( V_12 -> V_22 -> V_181 & V_187 ) ;
}
switch ( F_34 ( V_12 -> V_32 ) ) {
case V_101 :
if ( V_12 -> V_22 -> V_181 & V_184 ||
V_12 -> V_22 -> V_188 == V_189 )
return 1 ;
}
return 0 ;
}
int F_66 ( struct V_11 * V_12 )
{
int V_25 ;
if ( ! F_19 ( V_12 -> V_14 ) ) {
F_4 ( 5 , F_5 ( L_48
L_49 ,
V_39 ) ) ;
return V_58 ;
}
switch ( F_32 ( V_12 -> V_32 ) ) {
case V_190 :
V_12 -> V_32 &= 0xff00ffff ;
return V_58 ;
case V_97 :
break;
case V_191 :
case V_192 :
case V_193 :
return V_58 ;
case V_186 :
goto V_194;
case V_195 :
return V_50 ;
case V_196 :
return V_80 ;
case V_197 :
goto V_194;
case V_198 :
return V_58 ;
case V_185 :
if ( F_33 ( V_12 -> V_32 ) == V_98 &&
F_34 ( V_12 -> V_32 ) == V_105 )
break;
case V_180 :
case V_183 :
goto V_194;
case V_33 :
if ( ( V_12 -> V_106 [ 0 ] == V_107 ||
V_12 -> V_106 [ 0 ] == V_199 ) ) {
return V_58 ;
} else {
return V_49 ;
}
case V_96 :
return V_58 ;
default:
return V_49 ;
}
if ( F_33 ( V_12 -> V_32 ) != V_98 )
return V_49 ;
switch ( F_34 ( V_12 -> V_32 ) ) {
case V_108 :
F_30 ( V_12 -> V_14 ) ;
case V_109 :
return V_80 ;
case V_99 :
F_28 ( V_12 -> V_14 ) ;
case V_100 :
return V_58 ;
case V_200 :
goto V_194;
case V_101 :
V_25 = F_24 ( V_12 ) ;
if ( V_25 == V_50 )
goto V_194;
else if ( V_25 == V_76 ) {
V_12 -> V_32 |= ( V_201 << 16 ) ;
V_25 = V_58 ;
}
return V_25 ;
case V_102 :
case V_103 :
case V_104 :
case V_202 :
return V_58 ;
case V_105 :
F_23 ( V_46 , V_12 -> V_14 ,
L_50 ) ;
V_12 -> V_32 |= ( V_203 << 16 ) ;
return V_58 ;
default:
return V_49 ;
}
return V_49 ;
V_194:
if ( ( ++ V_12 -> V_159 ) <= V_12 -> V_160
&& ! F_84 ( V_12 ) ) {
return V_50 ;
} else {
return V_58 ;
}
}
static void F_85 ( struct V_22 * V_23 , int V_204 )
{
F_86 ( V_23 -> V_205 , V_23 ) ;
}
static void F_87 ( struct V_35 * V_36 )
{
struct V_22 * V_23 ;
V_23 = F_88 ( V_36 -> V_172 , V_206 , V_207 ) ;
V_23 -> V_208 [ 0 ] = V_209 ;
V_23 -> V_208 [ 1 ] = 0 ;
V_23 -> V_208 [ 2 ] = 0 ;
V_23 -> V_208 [ 3 ] = 0 ;
V_23 -> V_208 [ 4 ] = V_210 ;
V_23 -> V_208 [ 5 ] = 0 ;
V_23 -> V_126 = F_52 ( V_23 -> V_208 [ 0 ] ) ;
V_23 -> V_188 = V_189 ;
V_23 -> V_181 |= V_211 ;
V_23 -> V_149 = 10 * V_212 ;
V_23 -> V_159 = 5 ;
F_89 ( V_23 -> V_205 , NULL , V_23 , 1 , F_85 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
unsigned long V_6 ;
F_21 (sdev, shost) {
if ( F_19 ( V_36 ) && V_36 -> V_213 )
F_87 ( V_36 ) ;
}
F_4 ( 3 , F_5 ( L_51 ,
V_39 ) ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
if ( F_8 ( V_2 , V_214 ) )
if ( F_8 ( V_2 , V_215 ) )
F_53 ( F_8 ( V_2 , V_216 ) ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_91 ( & V_2 -> V_38 ) ;
F_92 ( V_2 ) ;
}
void F_93 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_40 * V_155 )
{
if ( ! F_74 ( V_2 , V_41 , V_155 ) )
if ( ! F_75 ( V_2 , V_41 , V_155 ) )
if ( ! F_76 ( V_2 , V_41 , V_155 ) )
if ( ! F_80 ( V_2 , V_41 , V_155 ) )
if ( ! F_81 ( V_41 , V_155 ) )
F_82 ( V_41 ,
V_155 ) ;
}
void F_94 ( struct V_40 * V_155 )
{
struct V_11 * V_12 , * V_156 ;
F_63 (scmd, next, done_q, eh_entry) {
F_95 ( & V_12 -> V_19 ) ;
if ( F_19 ( V_12 -> V_14 ) &&
! F_84 ( V_12 ) &&
( ++ V_12 -> V_159 <= V_12 -> V_160 ) ) {
F_4 ( 3 , F_5 ( L_52
L_53 ,
V_157 -> V_158 ,
V_12 ) ) ;
F_96 ( V_12 , V_217 ) ;
} else {
if ( ! V_12 -> V_32 )
V_12 -> V_32 |= ( V_218 << 24 ) ;
F_4 ( 3 , F_5 ( L_54
L_55 ,
V_157 -> V_158 , V_12 ) ) ;
F_97 ( V_12 ) ;
}
}
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_73 ( V_219 ) ;
F_73 ( V_220 ) ;
F_7 ( V_2 -> V_7 , V_6 ) ;
F_77 ( & V_2 -> V_20 , & V_219 ) ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 1 , F_20 ( V_2 , & V_219 ) ) ;
if ( ! F_62 ( & V_219 , & V_220 ) )
if ( ! F_72 ( & V_219 , & V_220 ) )
F_93 ( V_2 , & V_219 , & V_220 ) ;
F_94 ( & V_220 ) ;
}
int F_99 ( void * V_117 )
{
struct V_1 * V_2 = V_117 ;
F_100 ( V_221 ) ;
while ( ! F_101 () ) {
if ( ( V_2 -> V_4 == 0 && V_2 -> V_10 == 0 ) ||
V_2 -> V_4 != V_2 -> V_3 ) {
F_4 ( 1 ,
F_5 ( L_56 ,
V_2 -> V_222 ) ) ;
F_102 () ;
F_100 ( V_221 ) ;
continue;
}
F_103 ( V_223 ) ;
F_4 ( 1 ,
F_5 ( L_57 ,
V_2 -> V_222 ) ) ;
if ( F_104 ( V_2 ) != 0 ) {
F_4 ( 1 ,
F_5 ( V_224 L_58
L_59 ,
V_2 -> V_222 ) ) ;
continue;
}
if ( V_2 -> V_28 -> V_225 )
V_2 -> V_28 -> V_225 ( V_2 ) ;
else
F_98 ( V_2 ) ;
F_90 ( V_2 ) ;
F_105 ( V_2 ) ;
F_100 ( V_221 ) ;
}
F_103 ( V_223 ) ;
F_4 ( 1 ,
F_5 ( L_60 , V_2 -> V_222 ) ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 , int V_92 )
{
struct V_35 * V_36 ;
F_106 (sdev, shost) {
if ( V_92 == F_107 ( V_36 ) )
F_42 ( V_36 , NULL ) ;
}
}
void F_108 ( struct V_1 * V_2 , int V_92 , int V_226 )
{
struct V_35 * V_36 ;
F_106 (sdev, shost) {
if ( V_92 == F_107 ( V_36 ) &&
V_226 == F_109 ( V_36 ) )
F_42 ( V_36 , NULL ) ;
}
}
static void
F_110 ( struct V_11 * V_12 )
{
}
int
F_111 ( struct V_35 * V_227 , int V_228 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = V_227 -> V_15 ;
struct V_22 V_23 ;
unsigned long V_6 ;
int V_25 ;
if ( F_104 ( V_2 ) < 0 )
return V_49 ;
V_12 = F_112 ( V_227 , V_207 ) ;
F_113 ( NULL , & V_23 ) ;
V_12 -> V_22 = & V_23 ;
V_12 -> V_106 = V_23 . V_208 ;
V_12 -> V_152 = F_110 ;
memset ( & V_12 -> V_129 , 0 , sizeof( V_12 -> V_129 ) ) ;
V_12 -> V_126 = 0 ;
V_12 -> V_128 = V_229 ;
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_230 = 1 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
switch ( V_228 ) {
case V_231 :
V_25 = F_46 ( V_12 ) ;
if ( V_25 == V_58 )
break;
case V_232 :
V_25 = F_43 ( V_12 ) ;
if ( V_25 == V_58 )
break;
case V_233 :
V_25 = F_41 ( V_12 ) ;
if ( V_25 == V_58 )
break;
case V_234 :
V_25 = F_37 ( V_12 ) ;
break;
default:
V_25 = V_49 ;
}
F_7 ( V_2 -> V_7 , V_6 ) ;
V_2 -> V_230 = 0 ;
F_9 ( V_2 -> V_7 , V_6 ) ;
F_4 ( 3 ,
F_5 ( L_61 ,
V_39 ) ) ;
F_91 ( & V_2 -> V_38 ) ;
F_92 ( V_2 ) ;
F_114 ( V_12 ) ;
F_105 ( V_2 ) ;
return V_25 ;
}
int F_115 ( const T_1 * V_57 , int V_235 ,
struct V_47 * V_48 )
{
if ( ! V_57 || ! V_235 )
return 0 ;
memset ( V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 -> V_56 = ( V_57 [ 0 ] & 0x7f ) ;
if ( ! F_116 ( V_48 ) )
return 0 ;
if ( V_48 -> V_56 >= 0x72 ) {
if ( V_235 > 1 )
V_48 -> V_60 = ( V_57 [ 1 ] & 0xf ) ;
if ( V_235 > 2 )
V_48 -> V_64 = V_57 [ 2 ] ;
if ( V_235 > 3 )
V_48 -> V_68 = V_57 [ 3 ] ;
if ( V_235 > 7 )
V_48 -> V_59 = V_57 [ 7 ] ;
} else {
if ( V_235 > 2 )
V_48 -> V_60 = ( V_57 [ 2 ] & 0xf ) ;
if ( V_235 > 7 ) {
V_235 = ( V_235 < ( V_57 [ 7 ] + 8 ) ) ?
V_235 : ( V_57 [ 7 ] + 8 ) ;
if ( V_235 > 12 )
V_48 -> V_64 = V_57 [ 12 ] ;
if ( V_235 > 13 )
V_48 -> V_68 = V_57 [ 13 ] ;
}
}
return 1 ;
}
int F_25 ( struct V_11 * V_208 ,
struct V_47 * V_48 )
{
return F_115 ( V_208 -> V_57 ,
V_137 , V_48 ) ;
}
const T_1 * F_117 ( const T_1 * V_57 , int V_235 ,
int V_236 )
{
int V_237 , V_238 , V_239 , V_240 ;
const T_1 * V_241 ;
if ( ( V_235 < 8 ) || ( 0 == ( V_237 = V_57 [ 7 ] ) ) )
return NULL ;
if ( ( V_57 [ 0 ] < 0x72 ) || ( V_57 [ 0 ] > 0x73 ) )
return NULL ;
V_237 = ( V_237 < ( V_235 - 8 ) ) ?
V_237 : ( V_235 - 8 ) ;
V_241 = & V_57 [ 8 ] ;
for ( V_239 = 0 , V_240 = 0 ; V_240 < V_237 ; V_240 += V_239 ) {
V_241 += V_239 ;
V_238 = ( V_240 < ( V_237 - 1 ) ) ? V_241 [ 1 ] : - 1 ;
V_239 = V_238 + 2 ;
if ( V_241 [ 0 ] == V_236 )
return V_241 ;
if ( V_238 < 0 )
break;
}
return NULL ;
}
int F_118 ( const T_1 * V_57 , int V_235 ,
T_2 * V_242 )
{
int V_243 ;
const T_1 * V_244 ;
T_2 V_245 ;
if ( V_235 < 7 )
return 0 ;
switch ( V_57 [ 0 ] & 0x7f ) {
case 0x70 :
case 0x71 :
if ( V_57 [ 0 ] & 0x80 ) {
* V_242 = ( V_57 [ 3 ] << 24 ) +
( V_57 [ 4 ] << 16 ) +
( V_57 [ 5 ] << 8 ) + V_57 [ 6 ] ;
return 1 ;
} else
return 0 ;
case 0x72 :
case 0x73 :
V_244 = F_117 ( V_57 , V_235 ,
0 ) ;
if ( V_244 && ( 0xa == V_244 [ 1 ] ) ) {
V_245 = 0 ;
for ( V_243 = 0 ; V_243 < 8 ; ++ V_243 ) {
if ( V_243 > 0 )
V_245 <<= 8 ;
V_245 |= V_244 [ 4 + V_243 ] ;
}
* V_242 = V_245 ;
return 1 ;
} else
return 0 ;
default:
return 0 ;
}
}
void F_119 ( int V_246 , T_1 * V_247 , T_1 V_248 , T_1 V_64 , T_1 V_68 )
{
if ( V_246 ) {
V_247 [ 0 ] = 0x72 ;
V_247 [ 1 ] = V_248 ;
V_247 [ 2 ] = V_64 ;
V_247 [ 3 ] = V_68 ;
V_247 [ 7 ] = 0 ;
} else {
V_247 [ 0 ] = 0x70 ;
V_247 [ 2 ] = V_248 ;
V_247 [ 7 ] = 0xa ;
V_247 [ 12 ] = V_64 ;
V_247 [ 13 ] = V_68 ;
}
}
