int F_1 ( T_1 V_1 , T_1 V_2 ,
T_1 V_3 , T_1 V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_7 , V_8 ;
V_7 = V_6 -> V_9 << 16 ;
V_8 = V_6 -> V_10 << 16 ;
if ( V_3 > V_7 ||
V_1 > V_7 - V_3 ||
V_4 > V_8 ||
V_2 > V_8 - V_4 ) {
F_2 ( L_1
L_2 ,
V_3 >> 16 , ( ( V_3 & 0xffff ) * 15625 ) >> 10 ,
V_4 >> 16 , ( ( V_4 & 0xffff ) * 15625 ) >> 10 ,
V_1 >> 16 , ( ( V_1 & 0xffff ) * 15625 ) >> 10 ,
V_2 >> 16 , ( ( V_2 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_11 ;
}
return 0 ;
}
int F_3 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_14 ;
struct V_19 V_20 = {} ;
int V_21 ;
V_20 . V_22 = V_18 -> V_22 ;
V_20 . V_9 = V_18 -> V_9 ;
V_20 . V_10 = V_18 -> V_10 ;
V_20 . V_23 [ 0 ] = V_18 -> V_24 ;
V_20 . V_25 = F_4 ( V_18 -> V_26 , V_18 -> V_27 ) ;
V_20 . V_28 [ 0 ] = V_18 -> V_29 ;
V_21 = F_5 ( V_13 , & V_20 , V_16 ) ;
if ( V_21 )
return V_21 ;
V_18 -> V_22 = V_20 . V_22 ;
return 0 ;
}
static int F_6 ( const struct V_19 * V_20 )
{
T_1 V_30 = V_20 -> V_25 & ~ V_31 ;
char * V_32 ;
switch ( V_30 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
return 0 ;
default:
V_32 = F_7 ( V_20 -> V_25 ) ;
F_2 ( L_3 , V_32 ) ;
F_8 ( V_32 ) ;
return - V_93 ;
}
}
static int F_9 ( const struct V_19 * V_20 )
{
int V_21 , V_94 , V_95 , V_96 , V_97 ;
V_21 = F_6 ( V_20 ) ;
if ( V_21 ) {
char * V_32 = F_7 ( V_20 -> V_25 ) ;
F_2 ( L_4 , V_32 ) ;
F_8 ( V_32 ) ;
return V_21 ;
}
V_94 = F_10 ( V_20 -> V_25 ) ;
V_95 = F_11 ( V_20 -> V_25 ) ;
V_96 = F_12 ( V_20 -> V_25 ) ;
if ( V_20 -> V_9 == 0 || V_20 -> V_9 % V_94 ) {
F_2 ( L_5 , V_20 -> V_9 ) ;
return - V_93 ;
}
if ( V_20 -> V_10 == 0 || V_20 -> V_10 % V_95 ) {
F_2 ( L_6 , V_20 -> V_10 ) ;
return - V_93 ;
}
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ ) {
unsigned int V_9 = V_20 -> V_9 / ( V_97 != 0 ? V_94 : 1 ) ;
unsigned int V_10 = V_20 -> V_10 / ( V_97 != 0 ? V_95 : 1 ) ;
unsigned int V_98 = F_13 ( V_20 -> V_25 , V_97 ) ;
if ( ! V_20 -> V_28 [ V_97 ] ) {
F_2 ( L_7 , V_97 ) ;
return - V_93 ;
}
if ( ( V_99 ) V_9 * V_98 > V_100 )
return - V_101 ;
if ( ( V_99 ) V_10 * V_20 -> V_23 [ V_97 ] + V_20 -> V_102 [ V_97 ] > V_100 )
return - V_101 ;
if ( V_20 -> V_23 [ V_97 ] < V_9 * V_98 ) {
F_2 ( L_8 , V_20 -> V_23 [ V_97 ] , V_97 ) ;
return - V_93 ;
}
if ( V_20 -> V_103 [ V_97 ] && ! ( V_20 -> V_104 & V_105 ) ) {
F_2 ( L_9 ,
V_20 -> V_103 [ V_97 ] , V_97 ) ;
return - V_93 ;
}
switch ( V_20 -> V_103 [ V_97 ] ) {
case V_106 :
if ( V_20 -> V_25 != V_77 ||
V_9 % 128 || V_10 % 32 ||
V_20 -> V_23 [ V_97 ] % 128 ) {
F_2 ( L_10 , V_97 ) ;
return - V_93 ;
}
break;
default:
break;
}
}
for ( V_97 = V_96 ; V_97 < 4 ; V_97 ++ ) {
if ( V_20 -> V_103 [ V_97 ] ) {
F_2 ( L_11 , V_97 ) ;
return - V_93 ;
}
if ( ! ( V_20 -> V_104 & V_105 ) )
continue;
if ( V_20 -> V_28 [ V_97 ] ) {
F_2 ( L_12 , V_97 ) ;
return - V_93 ;
}
if ( V_20 -> V_23 [ V_97 ] ) {
F_2 ( L_13 , V_97 ) ;
return - V_93 ;
}
if ( V_20 -> V_102 [ V_97 ] ) {
F_2 ( L_14 , V_97 ) ;
return - V_93 ;
}
}
return 0 ;
}
struct V_5 *
F_14 ( struct V_12 * V_13 ,
const struct V_19 * V_20 ,
struct V_15 * V_16 )
{
struct V_107 * V_108 = & V_13 -> V_109 ;
struct V_5 * V_6 ;
int V_21 ;
if ( V_20 -> V_104 & ~ ( V_110 | V_105 ) ) {
F_2 ( L_15 , V_20 -> V_104 ) ;
return F_15 ( - V_93 ) ;
}
if ( ( V_108 -> V_111 > V_20 -> V_9 ) || ( V_20 -> V_9 > V_108 -> V_112 ) ) {
F_2 ( L_16 ,
V_20 -> V_9 , V_108 -> V_111 , V_108 -> V_112 ) ;
return F_15 ( - V_93 ) ;
}
if ( ( V_108 -> V_113 > V_20 -> V_10 ) || ( V_20 -> V_10 > V_108 -> V_114 ) ) {
F_2 ( L_17 ,
V_20 -> V_10 , V_108 -> V_113 , V_108 -> V_114 ) ;
return F_15 ( - V_93 ) ;
}
if ( V_20 -> V_104 & V_105 &&
! V_13 -> V_109 . V_115 ) {
F_2 ( L_18 ) ;
return F_15 ( - V_93 ) ;
}
V_21 = F_9 ( V_20 ) ;
if ( V_21 )
return F_15 ( V_21 ) ;
V_6 = V_13 -> V_109 . V_116 -> V_117 ( V_13 , V_16 , V_20 ) ;
if ( F_16 ( V_6 ) ) {
F_2 ( L_19 ) ;
return V_6 ;
}
return V_6 ;
}
int F_5 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_14 ;
struct V_5 * V_6 ;
if ( ! F_17 ( V_13 , V_118 ) )
return - V_93 ;
V_6 = F_14 ( V_13 , V_20 , V_16 ) ;
if ( F_16 ( V_6 ) )
return F_18 ( V_6 ) ;
F_2 ( L_20 , V_6 -> V_119 . V_120 ) ;
V_20 -> V_22 = V_6 -> V_119 . V_120 ;
F_19 ( & V_16 -> V_121 ) ;
F_20 ( & V_6 -> V_122 , & V_16 -> V_123 ) ;
F_21 ( & V_16 -> V_121 ) ;
return 0 ;
}
static void F_22 ( struct V_124 * V_125 )
{
struct V_126 * V_127 = F_23 ( V_125 , F_24 ( * V_127 ) , V_128 ) ;
while ( ! F_25 ( & V_127 -> V_123 ) ) {
struct V_5 * V_6 =
F_26 ( & V_127 -> V_123 , F_24 ( * V_6 ) , V_122 ) ;
F_27 ( & V_6 -> V_122 ) ;
F_28 ( V_6 ) ;
}
}
int F_29 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_5 * V_6 = NULL ;
struct V_5 * V_129 = NULL ;
T_1 * V_120 = V_14 ;
int V_130 = 0 ;
if ( ! F_17 ( V_13 , V_118 ) )
return - V_93 ;
V_6 = F_30 ( V_13 , * V_120 ) ;
if ( ! V_6 )
return - V_131 ;
F_19 ( & V_16 -> V_121 ) ;
F_31 (fbl, &file_priv->fbs, filp_head)
if ( V_6 == V_129 )
V_130 = 1 ;
if ( ! V_130 ) {
F_21 ( & V_16 -> V_121 ) ;
goto V_132;
}
F_27 ( & V_6 -> V_122 ) ;
F_21 ( & V_16 -> V_121 ) ;
F_32 ( V_6 ) ;
if ( F_33 ( V_6 ) > 1 ) {
struct V_126 V_127 ;
F_34 ( & V_127 . V_128 , F_22 ) ;
F_35 ( & V_127 . V_123 ) ;
F_36 ( & V_6 -> V_122 , & V_127 . V_123 ) ;
F_37 ( & V_127 . V_128 ) ;
F_38 ( & V_127 . V_128 ) ;
F_39 ( & V_127 . V_128 ) ;
} else
F_32 ( V_6 ) ;
return 0 ;
V_132:
F_32 ( V_6 ) ;
return - V_131 ;
}
int F_40 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_20 = V_14 ;
struct V_5 * V_6 ;
int V_21 ;
if ( ! F_17 ( V_13 , V_118 ) )
return - V_93 ;
V_6 = F_30 ( V_13 , V_20 -> V_22 ) ;
if ( ! V_6 )
return - V_131 ;
V_20 -> V_10 = V_6 -> V_10 ;
V_20 -> V_9 = V_6 -> V_9 ;
V_20 -> V_27 = V_6 -> V_27 ;
V_20 -> V_26 = V_6 -> V_133 ;
V_20 -> V_24 = V_6 -> V_23 [ 0 ] ;
if ( V_6 -> V_116 -> V_134 ) {
if ( F_41 ( V_16 ) || F_42 ( V_135 ) ||
F_43 ( V_16 ) ) {
V_21 = V_6 -> V_116 -> V_134 ( V_6 , V_16 ,
& V_20 -> V_29 ) ;
} else {
V_20 -> V_29 = 0 ;
V_21 = 0 ;
}
} else {
V_21 = - V_136 ;
}
F_32 ( V_6 ) ;
return V_21 ;
}
int F_44 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_137 T_2 * V_138 ;
struct V_137 * V_139 = NULL ;
struct V_140 * V_20 = V_14 ;
struct V_5 * V_6 ;
unsigned V_104 ;
int V_141 ;
int V_21 ;
if ( ! F_17 ( V_13 , V_118 ) )
return - V_93 ;
V_6 = F_30 ( V_13 , V_20 -> V_22 ) ;
if ( ! V_6 )
return - V_131 ;
V_141 = V_20 -> V_141 ;
V_138 = (struct V_137 T_2 * ) ( unsigned long ) V_20 -> V_138 ;
if ( ! V_141 != ! V_138 ) {
V_21 = - V_93 ;
goto V_142;
}
V_104 = V_143 & V_20 -> V_104 ;
if ( V_104 & V_144 && ( V_141 % 2 ) ) {
V_21 = - V_93 ;
goto V_142;
}
if ( V_141 && V_138 ) {
if ( V_141 < 0 || V_141 > V_145 ) {
V_21 = - V_93 ;
goto V_142;
}
V_139 = F_45 ( V_141 , sizeof( * V_139 ) , V_146 ) ;
if ( ! V_139 ) {
V_21 = - V_147 ;
goto V_142;
}
V_21 = F_46 ( V_139 , V_138 ,
V_141 * sizeof( * V_139 ) ) ;
if ( V_21 ) {
V_21 = - V_148 ;
goto V_149;
}
}
if ( V_6 -> V_116 -> V_150 ) {
V_21 = V_6 -> V_116 -> V_150 ( V_6 , V_16 , V_104 , V_20 -> V_151 ,
V_139 , V_141 ) ;
} else {
V_21 = - V_152 ;
}
V_149:
F_8 ( V_139 ) ;
V_142:
F_32 ( V_6 ) ;
return V_21 ;
}
void F_47 ( struct V_15 * V_153 )
{
struct V_5 * V_6 , * V_154 ;
struct V_126 V_127 ;
F_35 ( & V_127 . V_123 ) ;
F_48 (fb, tfb, &priv->fbs, filp_head) {
if ( F_33 ( V_6 ) > 1 ) {
F_49 ( & V_6 -> V_122 , & V_127 . V_123 ) ;
} else {
F_27 ( & V_6 -> V_122 ) ;
F_32 ( V_6 ) ;
}
}
if ( ! F_25 ( & V_127 . V_123 ) ) {
F_34 ( & V_127 . V_128 , F_22 ) ;
F_37 ( & V_127 . V_128 ) ;
F_38 ( & V_127 . V_128 ) ;
F_39 ( & V_127 . V_128 ) ;
}
}
void F_50 ( struct V_155 * V_155 )
{
struct V_5 * V_6 =
F_23 ( V_155 , struct V_5 , V_119 . V_156 ) ;
struct V_12 * V_13 = V_6 -> V_13 ;
F_51 ( V_13 , & V_6 -> V_119 ) ;
V_6 -> V_116 -> V_157 ( V_6 ) ;
}
int F_52 ( struct V_12 * V_13 , struct V_5 * V_6 ,
const struct V_158 * V_116 )
{
int V_21 ;
F_35 ( & V_6 -> V_122 ) ;
V_6 -> V_13 = V_13 ;
V_6 -> V_116 = V_116 ;
V_21 = F_53 ( V_13 , & V_6 -> V_119 , V_159 ,
false , F_50 ) ;
if ( V_21 )
goto V_160;
F_19 ( & V_13 -> V_109 . V_161 ) ;
V_13 -> V_109 . V_162 ++ ;
F_20 ( & V_6 -> V_163 , & V_13 -> V_109 . V_164 ) ;
F_21 ( & V_13 -> V_109 . V_161 ) ;
F_54 ( V_13 , & V_6 -> V_119 ) ;
V_160:
return V_21 ;
}
struct V_5 * F_30 ( struct V_12 * V_13 ,
T_1 V_120 )
{
struct V_165 * V_166 ;
struct V_5 * V_6 = NULL ;
V_166 = F_55 ( V_13 , V_120 , V_159 ) ;
if ( V_166 )
V_6 = F_56 ( V_166 ) ;
return V_6 ;
}
void F_57 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
if ( ! V_6 )
return;
V_13 = V_6 -> V_13 ;
F_51 ( V_13 , & V_6 -> V_119 ) ;
}
void F_58 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
F_19 ( & V_13 -> V_109 . V_161 ) ;
F_59 ( & V_6 -> V_163 ) ;
V_13 -> V_109 . V_162 -- ;
F_21 ( & V_13 -> V_109 . V_161 ) ;
}
void F_28 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
if ( ! V_6 )
return;
V_13 = V_6 -> V_13 ;
F_60 ( ! F_25 ( & V_6 -> V_122 ) ) ;
if ( F_33 ( V_6 ) > 1 ) {
F_61 ( V_13 ) ;
F_62 (crtc, dev) {
if ( V_168 -> V_171 -> V_6 == V_6 ) {
if ( F_63 ( V_168 ) )
F_64 ( L_21 , V_168 ) ;
}
}
F_65 (plane, dev) {
if ( V_170 -> V_6 == V_6 )
F_66 ( V_170 ) ;
}
F_67 ( V_13 ) ;
}
F_32 ( V_6 ) ;
}
