int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {
. V_2 = V_2 ,
} ;
return F_2 ( & V_4 ) ;
}
int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
F_4 ( V_6 ) ;
F_5 (crtc, dev)
if ( V_2 -> V_8 ) {
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
goto V_9;
}
V_9:
F_6 ( V_6 ) ;
return V_7 ;
}
static unsigned int F_7 ( struct V_5 * V_6 )
{
unsigned int V_10 = 0 ;
struct V_1 * V_11 ;
F_5 (tmp, dev) {
V_10 ++ ;
}
return V_10 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
F_5 (crtc, dev) {
if ( V_2 -> V_12 -> V_13 )
V_7 = V_2 -> V_12 -> V_13 ( V_2 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_5 (crtc, dev) {
if ( V_2 -> V_12 -> V_14 )
V_2 -> V_12 -> V_14 ( V_2 ) ;
}
}
int F_10 ( struct V_5 * V_6 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_15 * V_17 ,
const struct V_18 * V_12 ,
const char * V_19 , ... )
{
struct V_20 * V_21 = & V_6 -> V_22 ;
int V_7 ;
F_11 ( V_16 && V_16 -> type != V_23 ) ;
F_11 ( V_17 && V_17 -> type != V_24 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_12 = V_12 ;
F_12 ( & V_2 -> V_25 ) ;
F_13 ( & V_2 -> V_26 ) ;
F_14 ( & V_2 -> V_27 ) ;
V_7 = F_15 ( V_6 , & V_2 -> V_28 , V_29 ) ;
if ( V_7 )
return V_7 ;
if ( V_19 ) {
T_1 V_30 ;
va_start ( V_30 , V_19 ) ;
V_2 -> V_19 = F_16 ( V_31 , V_19 , V_30 ) ;
va_end ( V_30 ) ;
} else {
V_2 -> V_19 = F_17 ( V_31 , L_1 ,
F_7 ( V_6 ) ) ;
}
if ( ! V_2 -> V_19 ) {
F_18 ( V_6 , & V_2 -> V_28 ) ;
return - V_32 ;
}
V_2 -> V_28 . V_33 = & V_2 -> V_33 ;
F_19 ( & V_2 -> V_34 , & V_21 -> V_35 ) ;
V_2 -> V_36 = V_21 -> V_37 ++ ;
V_2 -> V_16 = V_16 ;
V_2 -> V_17 = V_17 ;
if ( V_16 )
V_16 -> V_38 = 1 << F_20 ( V_2 ) ;
if ( V_17 )
V_17 -> V_38 = 1 << F_20 ( V_2 ) ;
if ( F_21 ( V_6 , V_39 ) ) {
F_22 ( & V_2 -> V_28 , V_21 -> V_40 , 0 ) ;
F_22 ( & V_2 -> V_28 , V_21 -> V_41 , 0 ) ;
}
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_24 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
F_25 ( & V_2 -> V_27 ) ;
F_18 ( V_6 , & V_2 -> V_28 ) ;
F_26 ( & V_2 -> V_34 ) ;
V_6 -> V_22 . V_37 -- ;
F_11 ( V_2 -> V_43 && ! V_2 -> V_12 -> V_44 ) ;
if ( V_2 -> V_43 && V_2 -> V_12 -> V_44 )
V_2 -> V_12 -> V_44 ( V_2 , V_2 -> V_43 ) ;
F_24 ( V_2 -> V_19 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
int F_27 ( struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_28 ( V_6 ) ;
if ( V_7 )
goto V_45;
V_7 = F_8 ( V_6 ) ;
if ( V_7 )
goto V_46;
V_7 = F_29 ( V_6 ) ;
if ( V_7 )
goto V_47;
V_7 = F_30 ( V_6 ) ;
if ( V_7 )
goto V_48;
return 0 ;
V_48:
F_31 ( V_6 ) ;
V_47:
F_9 ( V_6 ) ;
V_46:
F_32 ( V_6 ) ;
V_45:
return V_7 ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( V_6 ) ;
F_31 ( V_6 ) ;
F_9 ( V_6 ) ;
F_32 ( V_6 ) ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_49 * V_50 ;
int V_7 ;
V_7 = F_36 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_50 = F_37 ( V_6 , V_51 ,
L_2 , V_52 ,
F_38 ( V_52 ) ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_53 = V_50 ;
V_50 = F_39 ( V_6 , V_54 ,
L_3 , 0 , V_55 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_56 = V_50 ;
V_50 = F_39 ( V_6 , V_54 ,
L_4 , 0 , V_55 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_57 = V_50 ;
V_50 = F_39 ( V_6 , V_54 ,
L_5 , 0 , V_55 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_58 = V_50 ;
V_50 = F_39 ( V_6 , V_54 ,
L_6 , 0 , V_55 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_59 = V_50 ;
V_50 = F_40 ( V_6 , V_54 ,
L_7 , V_60 , V_61 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_62 = V_50 ;
V_50 = F_40 ( V_6 , V_54 ,
L_8 , V_60 , V_61 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_63 = V_50 ;
V_50 = F_39 ( V_6 , V_54 ,
L_9 , 0 , V_61 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_64 = V_50 ;
V_50 = F_39 ( V_6 , V_54 ,
L_10 , 0 , V_61 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_65 = V_50 ;
V_50 = F_41 ( V_6 , V_54 ,
L_11 , V_66 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_67 = V_50 ;
V_50 = F_41 ( V_6 , V_54 ,
L_12 , V_29 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_68 = V_50 ;
V_50 = F_42 ( V_6 , V_54 ,
L_13 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_40 = V_50 ;
V_50 = F_43 ( V_6 ,
V_54 | V_69 ,
L_14 , 0 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_41 = V_50 ;
V_50 = F_43 ( V_6 ,
V_69 ,
L_15 , 0 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_70 = V_50 ;
V_50 = F_39 ( V_6 ,
V_51 ,
L_16 , 0 , V_55 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_71 = V_50 ;
V_50 = F_43 ( V_6 ,
V_69 ,
L_17 , 0 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_72 = V_50 ;
V_50 = F_43 ( V_6 ,
V_69 ,
L_18 , 0 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_73 = V_50 ;
V_50 = F_39 ( V_6 ,
V_51 ,
L_19 , 0 , V_55 ) ;
if ( ! V_50 )
return - V_32 ;
V_6 -> V_22 . V_74 = V_50 ;
return 0 ;
}
int F_44 ( struct V_5 * V_6 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = V_75 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
int V_7 = 0 ;
int V_88 = 0 ;
int V_89 = 0 ;
int V_90 = 0 ;
int V_91 = 0 ;
int V_92 = 0 ;
T_2 T_3 * V_93 ;
T_2 T_3 * V_94 ;
T_2 T_3 * V_95 ;
T_2 T_3 * V_96 ;
if ( ! F_21 ( V_6 , V_97 ) )
return - V_98 ;
F_45 ( & V_77 -> V_99 ) ;
F_46 (lh, &file_priv->fbs)
V_90 ++ ;
if ( V_79 -> V_100 >= V_90 ) {
V_92 = 0 ;
V_93 = ( T_2 T_3 * ) ( unsigned long ) V_79 -> V_101 ;
F_47 (fb, &file_priv->fbs, filp_head) {
if ( F_48 ( V_83 -> V_28 . V_102 , V_93 + V_92 ) ) {
F_49 ( & V_77 -> V_99 ) ;
return - V_103 ;
}
V_92 ++ ;
}
}
V_79 -> V_100 = V_90 ;
F_49 ( & V_77 -> V_99 ) ;
F_45 ( & V_6 -> V_22 . V_27 ) ;
F_5 (crtc, dev)
V_89 ++ ;
F_50 (connector, dev)
V_88 ++ ;
F_51 (encoder, dev)
V_91 ++ ;
V_79 -> V_104 = V_6 -> V_22 . V_104 ;
V_79 -> V_105 = V_6 -> V_22 . V_105 ;
V_79 -> V_106 = V_6 -> V_22 . V_106 ;
V_79 -> V_107 = V_6 -> V_22 . V_107 ;
if ( V_79 -> V_108 >= V_89 ) {
V_92 = 0 ;
V_94 = ( T_2 T_3 * ) ( unsigned long ) V_79 -> V_109 ;
F_5 (crtc, dev) {
if ( F_48 ( V_2 -> V_28 . V_102 , V_94 + V_92 ) ) {
V_7 = - V_103 ;
goto V_9;
}
V_92 ++ ;
}
}
V_79 -> V_108 = V_89 ;
if ( V_79 -> V_110 >= V_91 ) {
V_92 = 0 ;
V_96 = ( T_2 T_3 * ) ( unsigned long ) V_79 -> V_111 ;
F_51 (encoder, dev) {
if ( F_48 ( V_87 -> V_28 . V_102 , V_96 +
V_92 ) ) {
V_7 = - V_103 ;
goto V_9;
}
V_92 ++ ;
}
}
V_79 -> V_110 = V_91 ;
if ( V_79 -> V_112 >= V_88 ) {
V_92 = 0 ;
V_95 = ( T_2 T_3 * ) ( unsigned long ) V_79 -> V_113 ;
F_50 (connector, dev) {
if ( F_48 ( V_85 -> V_28 . V_102 ,
V_95 + V_92 ) ) {
V_7 = - V_103 ;
goto V_9;
}
V_92 ++ ;
}
}
V_79 -> V_112 = V_88 ;
V_9:
F_49 ( & V_6 -> V_22 . V_27 ) ;
return V_7 ;
}
int F_52 ( struct V_5 * V_6 ,
void * V_75 , struct V_76 * V_77 )
{
struct V_114 * V_115 = V_75 ;
struct V_1 * V_2 ;
if ( ! F_21 ( V_6 , V_97 ) )
return - V_98 ;
V_2 = F_53 ( V_6 , V_115 -> V_94 ) ;
if ( ! V_2 )
return - V_116 ;
F_54 ( V_2 , V_2 -> V_16 ) ;
V_115 -> V_117 = V_2 -> V_117 ;
if ( V_2 -> V_16 -> V_83 )
V_115 -> V_93 = V_2 -> V_16 -> V_83 -> V_28 . V_102 ;
else
V_115 -> V_93 = 0 ;
if ( V_2 -> V_43 ) {
V_115 -> V_118 = V_2 -> V_16 -> V_43 -> V_119 >> 16 ;
V_115 -> V_120 = V_2 -> V_16 -> V_43 -> V_121 >> 16 ;
if ( V_2 -> V_43 -> V_122 ) {
F_55 ( & V_115 -> V_123 , & V_2 -> V_43 -> V_123 ) ;
V_115 -> V_124 = 1 ;
} else {
V_115 -> V_124 = 0 ;
}
} else {
V_115 -> V_118 = V_2 -> V_118 ;
V_115 -> V_120 = V_2 -> V_120 ;
if ( V_2 -> V_8 ) {
F_55 ( & V_115 -> V_123 , & V_2 -> V_123 ) ;
V_115 -> V_124 = 1 ;
} else {
V_115 -> V_124 = 0 ;
}
}
F_56 ( V_2 ) ;
return 0 ;
}
int F_2 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_82 * V_83 ;
struct V_1 * V_11 ;
int V_7 ;
F_5 (tmp, crtc->dev)
V_11 -> V_16 -> V_125 = V_11 -> V_16 -> V_83 ;
V_83 = V_4 -> V_83 ;
V_7 = V_2 -> V_12 -> V_126 ( V_4 ) ;
if ( V_7 == 0 ) {
V_2 -> V_16 -> V_2 = V_2 ;
V_2 -> V_16 -> V_83 = V_83 ;
}
F_5 (tmp, crtc->dev) {
if ( V_11 -> V_16 -> V_83 )
F_57 ( V_11 -> V_16 -> V_83 ) ;
if ( V_11 -> V_16 -> V_125 )
F_58 ( V_11 -> V_16 -> V_125 ) ;
V_11 -> V_16 -> V_125 = NULL ;
}
return V_7 ;
}
void F_59 ( const struct V_127 * V_123 ,
int * V_128 , int * V_129 )
{
struct V_127 V_130 ;
F_60 ( & V_130 , V_123 ) ;
F_61 ( & V_130 , V_131 ) ;
* V_128 = V_130 . V_132 ;
* V_129 = V_130 . V_133 ;
}
int F_62 ( const struct V_1 * V_2 ,
int V_118 , int V_120 ,
const struct V_127 * V_123 ,
const struct V_82 * V_83 )
{
int V_128 , V_129 ;
F_59 ( V_123 , & V_128 , & V_129 ) ;
if ( V_2 -> V_43 &&
V_2 -> V_16 -> V_43 -> V_134 & ( V_135 |
V_136 ) )
F_63 ( V_128 , V_129 ) ;
return F_64 ( V_118 << 16 , V_120 << 16 ,
V_128 << 16 , V_129 << 16 ,
V_83 ) ;
}
int F_65 ( struct V_5 * V_6 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_20 * V_21 = & V_6 -> V_22 ;
struct V_114 * V_137 = V_75 ;
struct V_1 * V_2 ;
struct V_84 * * V_138 = NULL , * V_85 ;
struct V_82 * V_83 = NULL ;
struct V_127 * V_123 = NULL ;
struct V_3 V_4 ;
T_2 T_3 * V_139 ;
int V_7 ;
int V_140 ;
if ( ! F_21 ( V_6 , V_97 ) )
return - V_98 ;
if ( V_137 -> V_118 & 0xffff0000 || V_137 -> V_120 & 0xffff0000 )
return - V_141 ;
F_4 ( V_6 ) ;
V_2 = F_53 ( V_6 , V_137 -> V_94 ) ;
if ( ! V_2 ) {
F_66 ( L_20 , V_137 -> V_94 ) ;
V_7 = - V_116 ;
goto V_9;
}
F_66 ( L_21 , V_2 -> V_28 . V_102 , V_2 -> V_19 ) ;
if ( V_137 -> V_124 ) {
if ( V_137 -> V_93 == - 1 ) {
if ( ! V_2 -> V_16 -> V_83 ) {
F_66 ( L_22 ) ;
V_7 = - V_98 ;
goto V_9;
}
V_83 = V_2 -> V_16 -> V_83 ;
F_57 ( V_83 ) ;
} else {
V_83 = F_67 ( V_6 , V_137 -> V_93 ) ;
if ( ! V_83 ) {
F_66 ( L_23 ,
V_137 -> V_93 ) ;
V_7 = - V_116 ;
goto V_9;
}
}
V_123 = F_68 ( V_6 ) ;
if ( ! V_123 ) {
V_7 = - V_32 ;
goto V_9;
}
V_7 = F_69 ( V_123 , & V_137 -> V_123 ) ;
if ( V_7 ) {
F_66 ( L_24 ) ;
goto V_9;
}
if ( ! V_2 -> V_16 -> V_142 ) {
V_7 = F_70 ( V_2 -> V_16 ,
V_83 -> V_143 ) ;
if ( V_7 ) {
char * V_144 = F_71 ( V_83 -> V_143 ) ;
F_66 ( L_25 , V_144 ) ;
F_24 ( V_144 ) ;
goto V_9;
}
}
V_7 = F_62 ( V_2 , V_137 -> V_118 , V_137 -> V_120 ,
V_123 , V_83 ) ;
if ( V_7 )
goto V_9;
}
if ( V_137 -> V_112 == 0 && V_123 ) {
F_66 ( L_26 ) ;
V_7 = - V_98 ;
goto V_9;
}
if ( V_137 -> V_112 > 0 && ( ! V_123 || ! V_83 ) ) {
F_66 ( L_27 ,
V_137 -> V_112 ) ;
V_7 = - V_98 ;
goto V_9;
}
if ( V_137 -> V_112 > 0 ) {
T_4 V_145 ;
if ( V_137 -> V_112 > V_21 -> V_146 ) {
V_7 = - V_98 ;
goto V_9;
}
V_138 = F_72 ( V_137 -> V_112 ,
sizeof( struct V_84 * ) ,
V_31 ) ;
if ( ! V_138 ) {
V_7 = - V_32 ;
goto V_9;
}
for ( V_140 = 0 ; V_140 < V_137 -> V_112 ; V_140 ++ ) {
V_138 [ V_140 ] = NULL ;
V_139 = ( T_2 T_3 * ) ( unsigned long ) V_137 -> V_139 ;
if ( F_73 ( V_145 , & V_139 [ V_140 ] ) ) {
V_7 = - V_103 ;
goto V_9;
}
V_85 = F_74 ( V_6 , V_145 ) ;
if ( ! V_85 ) {
F_66 ( L_28 ,
V_145 ) ;
V_7 = - V_116 ;
goto V_9;
}
F_66 ( L_29 ,
V_85 -> V_28 . V_102 ,
V_85 -> V_19 ) ;
V_138 [ V_140 ] = V_85 ;
}
}
V_4 . V_2 = V_2 ;
V_4 . V_118 = V_137 -> V_118 ;
V_4 . V_120 = V_137 -> V_120 ;
V_4 . V_123 = V_123 ;
V_4 . V_147 = V_138 ;
V_4 . V_148 = V_137 -> V_112 ;
V_4 . V_83 = V_83 ;
V_7 = F_2 ( & V_4 ) ;
V_9:
if ( V_83 )
F_58 ( V_83 ) ;
if ( V_138 ) {
for ( V_140 = 0 ; V_140 < V_137 -> V_112 ; V_140 ++ ) {
if ( V_138 [ V_140 ] )
F_75 ( V_138 [ V_140 ] ) ;
}
}
F_24 ( V_138 ) ;
F_76 ( V_6 , V_123 ) ;
F_6 ( V_6 ) ;
return V_7 ;
}
int F_77 ( struct V_149 * V_150 ,
struct V_49 * V_151 ,
T_5 V_152 )
{
int V_7 = - V_98 ;
struct V_1 * V_2 = F_78 ( V_150 ) ;
if ( V_2 -> V_12 -> V_153 )
V_7 = V_2 -> V_12 -> V_153 ( V_2 , V_151 , V_152 ) ;
if ( ! V_7 )
F_79 ( V_150 , V_151 , V_152 ) ;
return V_7 ;
}
void F_80 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_15 * V_154 ;
struct V_86 * V_87 ;
struct V_84 * V_85 ;
F_81 (plane, dev)
if ( V_154 -> V_12 -> V_155 )
V_154 -> V_12 -> V_155 ( V_154 ) ;
F_5 (crtc, dev)
if ( V_2 -> V_12 -> V_155 )
V_2 -> V_12 -> V_155 ( V_2 ) ;
F_51 (encoder, dev)
if ( V_87 -> V_12 -> V_155 )
V_87 -> V_12 -> V_155 ( V_87 ) ;
F_45 ( & V_6 -> V_22 . V_27 ) ;
F_50 (connector, dev)
if ( V_85 -> V_12 -> V_155 )
V_85 -> V_12 -> V_155 ( V_85 ) ;
F_49 ( & V_6 -> V_22 . V_27 ) ;
}
int F_82 ( struct V_5 * V_6 ,
void * V_75 , struct V_76 * V_77 )
{
struct V_156 * args = V_75 ;
T_4 V_157 , V_158 , V_159 ;
if ( ! V_6 -> V_160 -> V_161 )
return - V_162 ;
if ( ! args -> V_163 || ! args -> V_164 || ! args -> V_165 )
return - V_98 ;
V_157 = F_83 ( args -> V_165 , 8 ) ;
if ( ! V_157 || V_157 > 0xffffffffU / args -> V_163 )
return - V_98 ;
V_158 = V_157 * args -> V_163 ;
if ( args -> V_164 > 0xffffffffU / V_158 )
return - V_98 ;
V_159 = args -> V_164 * V_158 ;
if ( F_84 ( V_159 ) == 0 )
return - V_98 ;
args -> V_166 = 0 ;
args -> V_167 = 0 ;
args -> V_159 = 0 ;
return V_6 -> V_160 -> V_161 ( V_77 , V_6 , args ) ;
}
int F_85 ( struct V_5 * V_6 ,
void * V_75 , struct V_76 * V_77 )
{
struct V_168 * args = V_75 ;
if ( ! V_6 -> V_160 -> V_169 )
return - V_162 ;
return V_6 -> V_160 -> V_169 ( V_77 , V_6 , args -> V_166 , & args -> V_170 ) ;
}
int F_86 ( struct V_5 * V_6 ,
void * V_75 , struct V_76 * V_77 )
{
struct V_171 * args = V_75 ;
if ( ! V_6 -> V_160 -> V_172 )
return - V_162 ;
return V_6 -> V_160 -> V_172 ( V_77 , V_6 , args -> V_166 ) ;
}
void F_87 ( struct V_5 * V_6 )
{
F_88 ( & V_6 -> V_22 . V_27 ) ;
F_14 ( & V_6 -> V_22 . V_173 ) ;
F_88 ( & V_6 -> V_22 . V_174 ) ;
F_88 ( & V_6 -> V_22 . V_175 ) ;
F_88 ( & V_6 -> V_22 . V_176 ) ;
F_12 ( & V_6 -> V_22 . V_177 ) ;
F_12 ( & V_6 -> V_22 . V_35 ) ;
F_12 ( & V_6 -> V_22 . V_178 ) ;
F_12 ( & V_6 -> V_22 . V_179 ) ;
F_12 ( & V_6 -> V_22 . V_180 ) ;
F_12 ( & V_6 -> V_22 . V_181 ) ;
F_12 ( & V_6 -> V_22 . V_182 ) ;
F_89 ( & V_6 -> V_22 . V_183 ) ;
F_89 ( & V_6 -> V_22 . V_184 ) ;
F_90 ( & V_6 -> V_22 . V_185 ) ;
F_4 ( V_6 ) ;
F_35 ( V_6 ) ;
F_6 ( V_6 ) ;
V_6 -> V_22 . V_186 = 0 ;
V_6 -> V_22 . V_146 = 0 ;
V_6 -> V_22 . V_37 = 0 ;
V_6 -> V_22 . V_187 = 0 ;
V_6 -> V_22 . V_188 = 0 ;
V_6 -> V_22 . V_189 = 0 ;
}
void F_91 ( struct V_5 * V_6 )
{
struct V_84 * V_85 , * V_190 ;
struct V_1 * V_2 , * V_191 ;
struct V_86 * V_87 , * V_192 ;
struct V_82 * V_83 , * V_193 ;
struct V_49 * V_151 , * V_194 ;
struct V_195 * V_196 , * V_197 ;
struct V_15 * V_154 , * V_198 ;
F_92 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_87 -> V_12 -> V_199 ( V_87 ) ;
}
F_92 (connector, ot,
&dev->mode_config.connector_list, head) {
V_85 -> V_12 -> V_199 ( V_85 ) ;
}
F_92 (property, pt, &dev->mode_config.property_list,
head) {
F_93 ( V_6 , V_151 ) ;
}
F_92 (plane, plt, &dev->mode_config.plane_list,
head) {
V_154 -> V_12 -> V_199 ( V_154 ) ;
}
F_92 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_2 -> V_12 -> V_199 ( V_2 ) ;
}
F_92 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_94 ( V_196 ) ;
}
F_11 ( ! F_95 ( & V_6 -> V_22 . V_177 ) ) ;
F_92 (fb, fbt, &dev->mode_config.fb_list, head) {
F_96 ( & V_83 -> V_28 . V_200 ) ;
}
F_97 ( & V_6 -> V_22 . V_185 ) ;
F_98 ( & V_6 -> V_22 . V_184 ) ;
F_98 ( & V_6 -> V_22 . V_183 ) ;
F_25 ( & V_6 -> V_22 . V_173 ) ;
}
static void F_99 ( struct V_201 * V_201 )
{
struct V_202 * V_203 = F_100 ( V_201 , struct V_202 , V_200 ) ;
struct V_5 * V_6 = V_203 -> V_6 ;
F_45 ( & V_6 -> V_22 . V_174 ) ;
F_101 ( & V_6 -> V_22 . V_184 , V_203 -> V_102 ) ;
F_49 ( & V_6 -> V_22 . V_174 ) ;
F_24 ( V_203 ) ;
}
void F_102 ( struct V_5 * V_6 ,
struct V_202 * V_203 )
{
F_103 ( & V_203 -> V_200 , F_99 ) ;
}
struct V_202 * F_104 ( struct V_5 * V_6 ,
char V_204 [ 8 ] )
{
struct V_202 * V_203 ;
int V_102 ;
F_45 ( & V_6 -> V_22 . V_174 ) ;
F_105 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_203 -> V_205 , V_204 , 8 ) ) {
if ( ! F_106 ( & V_203 -> V_200 ) )
V_203 = NULL ;
F_49 ( & V_6 -> V_22 . V_174 ) ;
return V_203 ;
}
}
F_49 ( & V_6 -> V_22 . V_174 ) ;
return NULL ;
}
struct V_202 * F_107 ( struct V_5 * V_6 ,
char V_204 [ 8 ] )
{
struct V_202 * V_203 ;
int V_7 ;
V_203 = F_108 ( sizeof( * V_203 ) , V_31 ) ;
if ( ! V_203 )
return F_109 ( - V_32 ) ;
F_110 ( & V_203 -> V_200 ) ;
memcpy ( V_203 -> V_205 , V_204 , 8 ) ;
V_203 -> V_6 = V_6 ;
F_45 ( & V_6 -> V_22 . V_174 ) ;
V_7 = F_111 ( & V_6 -> V_22 . V_184 , V_203 , 1 , 0 , V_31 ) ;
if ( V_7 >= 0 ) {
V_203 -> V_102 = V_7 ;
} else {
F_24 ( V_203 ) ;
V_203 = F_109 ( V_7 ) ;
}
F_49 ( & V_6 -> V_22 . V_174 ) ;
return V_203 ;
}
