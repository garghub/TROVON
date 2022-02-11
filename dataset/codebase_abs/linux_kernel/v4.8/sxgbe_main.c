static void F_1 ( void )
{
if ( F_2 ( V_1 < 0 ) )
V_1 = V_2 ;
}
static void F_3 ( const struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 )
V_4 -> V_6 -> V_7 -> V_8 ( V_4 -> V_9 ) ;
}
void F_4 ( struct V_3 * const V_4 )
{
V_4 -> V_6 -> V_7 -> V_10 ( V_4 -> V_9 ) ;
F_5 ( & V_4 -> V_11 ) ;
V_4 -> V_5 = false ;
}
static void F_6 ( unsigned long V_12 )
{
struct V_3 * V_4 = (struct V_3 * ) V_12 ;
F_3 ( V_4 ) ;
F_7 ( & V_4 -> V_11 , F_8 ( V_1 ) ) ;
}
bool F_9 ( struct V_3 * const V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
bool V_16 = false ;
if ( V_4 -> V_17 . V_18 ) {
if ( F_10 ( V_14 -> V_19 , 1 ) )
return false ;
V_4 -> V_20 = 1 ;
F_11 ( & V_4 -> V_11 , F_6 ,
( unsigned long ) V_4 ) ;
V_4 -> V_11 . V_21 = F_8 ( V_1 ) ;
F_12 ( & V_4 -> V_11 ) ;
V_4 -> V_6 -> V_7 -> V_22 ( V_4 -> V_9 ,
V_2 ,
V_4 -> V_23 ) ;
F_13 ( L_1 ) ;
V_16 = true ;
}
return V_16 ;
}
static void F_14 ( const struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 ;
if ( V_4 -> V_24 )
V_4 -> V_6 -> V_7 -> V_25 ( V_4 -> V_9 , V_14 -> V_19 -> V_26 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
T_1 V_27 = F_16 ( V_4 -> V_28 ) ;
if ( V_27 < V_29 )
V_4 -> V_30 = V_31 ;
else if ( V_27 <= V_32 )
V_4 -> V_30 = V_33 ;
else if ( V_27 <= V_34 )
V_4 -> V_30 = V_35 ;
else if ( V_27 <= V_36 )
V_4 -> V_30 = V_37 ;
else if ( V_27 <= V_38 )
V_4 -> V_30 = V_39 ;
else if ( V_27 <= V_40 )
V_4 -> V_30 = V_41 ;
}
static inline T_1 F_17 ( struct V_42 * V_43 , int V_44 )
{
return V_43 -> V_45 + V_44 - V_43 -> V_46 - 1 ;
}
static void F_18 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
struct V_47 * V_19 = V_15 -> V_19 ;
T_2 V_48 = 0 ;
T_2 V_49 = 0xff ;
if ( ! V_19 )
return;
if ( V_19 -> V_26 ) {
if ( V_19 -> V_49 != V_4 -> V_49 ) {
V_48 = 1 ;
switch ( V_19 -> V_49 ) {
case V_50 :
V_49 = V_51 ;
break;
case V_52 :
V_49 = V_53 ;
break;
case V_54 :
V_49 = V_55 ;
break;
default:
F_20 ( V_4 , V_26 , V_15 ,
L_2 ,
V_19 -> V_49 ) ;
}
V_4 -> V_49 = V_19 -> V_49 ;
V_4 -> V_6 -> V_7 -> V_56 ( V_4 -> V_9 , V_49 ) ;
}
if ( ! V_4 -> V_57 ) {
V_48 = 1 ;
V_4 -> V_57 = 1 ;
}
} else if ( V_4 -> V_57 ) {
V_48 = 1 ;
V_4 -> V_57 = 0 ;
V_4 -> V_49 = V_58 ;
}
if ( V_48 & F_21 ( V_4 ) )
F_22 ( V_19 ) ;
F_14 ( V_4 ) ;
}
static int F_23 ( struct V_13 * V_14 )
{
char V_59 [ V_60 + 3 ] ;
char V_61 [ V_60 ] ;
struct V_47 * V_19 ;
struct V_3 * V_4 = F_19 ( V_14 ) ;
int V_62 = V_4 -> V_63 -> V_64 ;
V_4 -> V_57 = 0 ;
V_4 -> V_49 = V_58 ;
V_4 -> V_65 = V_66 ;
if ( V_4 -> V_63 -> V_67 )
snprintf ( V_61 , V_60 , L_3 ,
V_4 -> V_63 -> V_67 , V_4 -> V_63 -> V_61 ) ;
else
snprintf ( V_61 , V_60 , L_4 ,
V_4 -> V_63 -> V_61 ) ;
snprintf ( V_59 , V_60 + 3 , V_68 , V_61 ,
V_4 -> V_63 -> V_69 ) ;
F_24 ( V_14 , L_5 , V_70 , V_59 ) ;
V_19 = F_25 ( V_14 , V_59 , & F_18 , V_62 ) ;
if ( F_26 ( V_19 ) ) {
F_27 ( V_14 , L_6 ) ;
return F_28 ( V_19 ) ;
}
if ( ( V_62 == V_71 ) ||
( V_62 == V_72 ) )
V_19 -> V_73 &= ~ ( V_74 |
V_75 ) ;
if ( V_19 -> V_76 == 0 ) {
F_29 ( V_19 ) ;
return - V_77 ;
}
F_24 ( V_14 , L_7 ,
V_70 , V_19 -> V_76 , V_19 -> V_26 ) ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
int V_78 , V_79 ;
unsigned int V_80 = V_4 -> V_81 ;
unsigned int V_82 = V_4 -> V_83 ;
for ( V_79 = 0 ; V_79 < V_84 ; V_79 ++ ) {
for ( V_78 = 0 ; V_78 < V_82 ; V_78 ++ )
V_4 -> V_6 -> V_85 -> V_86 ( & V_4 -> V_87 [ V_79 ] -> V_88 [ V_78 ] ,
V_4 -> V_89 , V_4 -> V_90 ,
( V_78 == V_82 - 1 ) ) ;
}
for ( V_79 = 0 ; V_79 < V_91 ; V_79 ++ ) {
for ( V_78 = 0 ; V_78 < V_80 ; V_78 ++ )
V_4 -> V_6 -> V_85 -> V_92 ( & V_4 -> V_93 [ V_79 ] -> V_94 [ V_78 ] ) ;
}
}
static int F_31 ( struct V_13 * V_15 ,
struct V_95 * V_96 , int V_78 ,
unsigned int V_97 ,
struct V_98 * V_99 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
struct V_100 * V_101 ;
V_101 = F_32 ( V_15 , V_97 , V_102 ) ;
if ( ! V_101 )
return - V_103 ;
V_99 -> V_104 [ V_78 ] = V_101 ;
V_99 -> V_105 [ V_78 ] = F_33 ( V_4 -> V_106 , V_101 -> V_107 ,
V_97 , V_108 ) ;
if ( F_34 ( V_4 -> V_106 , V_99 -> V_105 [ V_78 ] ) ) {
F_27 ( V_15 , L_8 , V_70 ) ;
F_35 ( V_101 ) ;
return - V_109 ;
}
V_96 -> V_110 . V_111 . V_112 = V_99 -> V_105 [ V_78 ] ;
return 0 ;
}
static void F_36 ( struct V_13 * V_15 ,
struct V_95 * V_96 , int V_78 ,
unsigned int V_97 ,
struct V_98 * V_99 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
F_37 ( V_99 -> V_104 [ V_78 ] ) ;
F_38 ( V_4 -> V_106 , V_99 -> V_105 [ V_78 ] ,
V_97 , V_108 ) ;
}
static int F_39 ( struct V_106 * V_15 , T_2 V_113 ,
struct V_42 * V_114 , int V_115 )
{
if ( ! V_114 ) {
F_40 ( V_15 , L_9 ) ;
return - V_103 ;
}
V_114 -> V_94 = F_41 ( V_15 ,
V_115 * sizeof( struct V_116 ) ,
& V_114 -> V_117 , V_102 ) ;
if ( ! V_114 -> V_94 )
return - V_103 ;
V_114 -> V_118 = F_42 ( V_15 , V_115 ,
sizeof( V_119 ) , V_102 ) ;
if ( ! V_114 -> V_118 )
goto V_120;
V_114 -> V_121 = F_42 ( V_15 , V_115 ,
sizeof( struct V_100 * ) , V_102 ) ;
if ( ! V_114 -> V_121 )
goto V_120;
V_114 -> V_113 = V_113 ;
V_114 -> V_45 = 0 ;
V_114 -> V_46 = 0 ;
F_43 ( & V_114 -> V_122 ) ;
return 0 ;
V_120:
F_44 ( V_15 , V_115 * sizeof( struct V_116 ) ,
V_114 -> V_94 , V_114 -> V_117 ) ;
return - V_103 ;
}
static void F_45 ( struct V_106 * V_15 , struct V_98 * V_99 ,
int V_123 )
{
F_44 ( V_15 , V_123 * sizeof( struct V_95 ) ,
V_99 -> V_88 , V_99 -> V_124 ) ;
F_46 ( V_99 -> V_105 ) ;
F_46 ( V_99 -> V_104 ) ;
}
static int F_47 ( struct V_13 * V_15 , T_2 V_113 ,
struct V_98 * V_99 , int V_123 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
int V_125 ;
unsigned int V_126 = 0 ;
unsigned int V_16 = 0 ;
V_126 = F_48 ( V_15 -> V_127 + V_128 + V_129 + V_130 , 8 ) ;
F_49 ( V_4 , V_131 , V_15 , L_10 , V_70 , V_126 ) ;
if ( V_99 == NULL ) {
F_27 ( V_15 , L_11 ) ;
return - V_103 ;
}
V_99 -> V_113 = V_113 ;
V_99 -> V_88 = F_41 ( V_4 -> V_106 ,
V_123 * sizeof( struct V_95 ) ,
& V_99 -> V_124 , V_102 ) ;
if ( V_99 -> V_88 == NULL )
return - V_103 ;
V_99 -> V_105 = F_50 ( V_123 ,
sizeof( V_119 ) , V_102 ) ;
if ( ! V_99 -> V_105 ) {
V_16 = - V_103 ;
goto V_132;
}
V_99 -> V_104 = F_50 ( V_123 ,
sizeof( struct V_100 * ) , V_102 ) ;
if ( ! V_99 -> V_104 ) {
V_16 = - V_103 ;
goto V_133;
}
for ( V_125 = 0 ; V_125 < V_123 ; V_125 ++ ) {
struct V_95 * V_96 ;
V_96 = V_99 -> V_88 + V_125 ;
V_16 = F_31 ( V_15 , V_96 , V_125 ,
V_126 , V_99 ) ;
if ( V_16 )
goto V_134;
}
V_99 -> V_135 = 0 ;
V_99 -> V_136 = ( unsigned int ) ( V_125 - V_123 ) ;
V_4 -> V_97 = V_126 ;
return 0 ;
V_134:
while ( -- V_125 >= 0 ) {
struct V_95 * V_96 ;
V_96 = V_99 -> V_88 + V_125 ;
F_36 ( V_15 , V_96 , V_125 , V_126 , V_99 ) ;
}
F_46 ( V_99 -> V_104 ) ;
V_133:
F_46 ( V_99 -> V_105 ) ;
V_132:
F_44 ( V_4 -> V_106 ,
V_123 * sizeof( struct V_95 ) ,
V_99 -> V_88 , V_99 -> V_124 ) ;
return V_16 ;
}
static void F_51 ( struct V_106 * V_15 , struct V_42 * V_114 ,
int V_115 )
{
F_44 ( V_15 , V_115 * sizeof( struct V_116 ) ,
V_114 -> V_94 , V_114 -> V_117 ) ;
}
static int F_52 ( struct V_13 * V_137 )
{
int V_138 , V_16 ;
struct V_3 * V_4 = F_19 ( V_137 ) ;
int V_115 = V_4 -> V_81 ;
int V_123 = V_4 -> V_83 ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
V_16 = F_39 ( V_4 -> V_106 , V_138 ,
V_4 -> V_93 [ V_138 ] , V_115 ) ;
if ( V_16 ) {
F_40 ( & V_137 -> V_15 , L_12 ) ;
goto V_139;
}
V_4 -> V_93 [ V_138 ] -> V_140 = V_4 ;
}
F_53 (SXGBE_RX_QUEUES, queue_num) {
V_16 = F_47 ( V_137 , V_138 ,
V_4 -> V_87 [ V_138 ] , V_123 ) ;
if ( V_16 ) {
F_27 ( V_137 , L_13 ) ;
goto V_141;
}
V_4 -> V_87 [ V_138 ] -> V_140 = V_4 ;
}
F_30 ( V_4 ) ;
return 0 ;
V_139:
while ( V_138 -- )
F_51 ( V_4 -> V_106 , V_4 -> V_93 [ V_138 ] , V_115 ) ;
return V_16 ;
V_141:
while ( V_138 -- )
F_45 ( V_4 -> V_106 , V_4 -> V_87 [ V_138 ] , V_123 ) ;
return V_16 ;
}
static void F_54 ( struct V_42 * V_142 )
{
int V_143 ;
struct V_3 * V_4 = V_142 -> V_140 ;
int V_115 = V_4 -> V_81 ;
for ( V_143 = 0 ; V_143 < V_115 ; V_143 ++ ) {
struct V_116 * V_144 = V_142 -> V_94 + V_143 ;
if ( V_142 -> V_118 [ V_143 ] )
F_38 ( V_4 -> V_106 ,
V_142 -> V_118 [ V_143 ] ,
V_4 -> V_6 -> V_85 -> V_145 ( V_144 ) ,
V_146 ) ;
F_35 ( V_142 -> V_121 [ V_143 ] ) ;
V_142 -> V_121 [ V_143 ] = NULL ;
V_142 -> V_118 [ V_143 ] = 0 ;
}
}
static void F_55 ( struct V_3 * V_4 )
{
int V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_147 = V_4 -> V_93 [ V_138 ] ;
F_54 ( V_147 ) ;
}
}
static void F_56 ( struct V_3 * V_4 )
{
int V_138 ;
int V_115 = V_4 -> V_81 ;
int V_123 = V_4 -> V_83 ;
F_55 ( V_4 ) ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
F_51 ( V_4 -> V_106 , V_4 -> V_93 [ V_138 ] , V_115 ) ;
}
F_53 (SXGBE_RX_QUEUES, queue_num) {
F_45 ( V_4 -> V_106 , V_4 -> V_87 [ V_138 ] , V_123 ) ;
}
}
static int F_57 ( struct V_3 * V_4 )
{
int V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
V_4 -> V_93 [ V_138 ] = F_58 ( V_4 -> V_106 ,
sizeof( struct V_42 ) , V_102 ) ;
if ( ! V_4 -> V_93 [ V_138 ] )
return - V_103 ;
}
return 0 ;
}
static int F_59 ( struct V_3 * V_4 )
{
int V_138 ;
F_53 (SXGBE_RX_QUEUES, queue_num) {
V_4 -> V_87 [ V_138 ] = F_58 ( V_4 -> V_106 ,
sizeof( struct V_98 ) , V_102 ) ;
if ( ! V_4 -> V_87 [ V_138 ] )
return - V_103 ;
}
return 0 ;
}
static void F_60 ( struct V_3 * V_4 )
{
int V_138 ;
if ( F_61 ( V_4 -> V_63 -> V_148 ) ) {
F_53 (priv->hw_cap.tx_mtl_queues, queue_num)
V_4 -> V_6 -> V_149 -> V_150 ( V_4 -> V_9 , V_138 ,
V_151 ) ;
V_4 -> V_152 = V_151 ;
F_53 (priv->hw_cap.rx_mtl_queues, queue_num)
V_4 -> V_6 -> V_149 -> V_153 ( V_4 -> V_9 , V_138 ,
V_151 ) ;
V_4 -> V_154 = V_151 ;
} else if ( F_2 ( V_4 -> V_63 -> V_155 ) ) {
F_53 (priv->hw_cap.tx_mtl_queues, queue_num)
V_4 -> V_6 -> V_149 -> V_150 ( V_4 -> V_9 , V_138 ,
V_4 -> V_152 ) ;
F_53 (priv->hw_cap.rx_mtl_queues, queue_num)
V_4 -> V_6 -> V_149 -> V_153 ( V_4 -> V_9 , V_138 ,
V_4 -> V_154 ) ;
} else {
F_62 ( L_14 , V_70 ) ;
}
}
static void F_63 ( struct V_42 * V_147 )
{
struct V_3 * V_4 = V_147 -> V_140 ;
unsigned int V_115 = V_4 -> V_81 ;
struct V_156 * V_157 ;
T_2 V_113 = V_147 -> V_113 ;
V_157 = F_64 ( V_4 -> V_15 , V_113 ) ;
F_65 ( & V_147 -> V_122 ) ;
V_4 -> V_158 . V_159 ++ ;
while ( V_147 -> V_45 != V_147 -> V_46 ) {
unsigned int V_160 = V_147 -> V_45 % V_115 ;
struct V_100 * V_101 = V_147 -> V_121 [ V_160 ] ;
struct V_116 * V_96 ;
V_96 = V_147 -> V_94 + V_160 ;
if ( V_4 -> V_6 -> V_85 -> V_161 ( V_96 ) )
break;
if ( F_66 ( V_4 ) )
F_67 ( L_15 ,
V_70 , V_147 -> V_46 , V_147 -> V_45 ) ;
if ( F_61 ( V_147 -> V_118 [ V_160 ] ) ) {
F_38 ( V_4 -> V_106 ,
V_147 -> V_118 [ V_160 ] ,
V_4 -> V_6 -> V_85 -> V_145 ( V_96 ) ,
V_146 ) ;
V_147 -> V_118 [ V_160 ] = 0 ;
}
if ( F_61 ( V_101 ) ) {
F_68 ( V_101 ) ;
V_147 -> V_121 [ V_160 ] = NULL ;
}
V_4 -> V_6 -> V_85 -> V_162 ( V_96 ) ;
V_147 -> V_45 ++ ;
}
if ( F_2 ( F_69 ( V_157 ) &&
F_17 ( V_147 , V_115 ) > F_70 ( V_4 ) ) ) {
F_71 ( V_4 -> V_15 ) ;
if ( F_69 ( V_157 ) &&
F_17 ( V_147 , V_115 ) > F_70 ( V_4 ) ) {
if ( F_66 ( V_4 ) )
F_67 ( L_16 , V_70 ) ;
F_72 ( V_157 ) ;
}
F_73 ( V_4 -> V_15 ) ;
}
F_74 ( & V_147 -> V_122 ) ;
}
static void F_75 ( struct V_3 * const V_4 )
{
T_2 V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_147 = V_4 -> V_93 [ V_138 ] ;
F_63 ( V_147 ) ;
}
if ( ( V_4 -> V_24 ) && ( ! V_4 -> V_5 ) ) {
F_3 ( V_4 ) ;
F_7 ( & V_4 -> V_11 , F_8 ( V_1 ) ) ;
}
}
static void F_76 ( struct V_3 * V_4 , int V_138 )
{
struct V_42 * V_114 = V_4 -> V_93 [ V_138 ] ;
struct V_156 * V_157 = F_64 ( V_4 -> V_15 ,
V_138 ) ;
F_77 ( V_157 ) ;
V_4 -> V_6 -> V_163 -> V_164 ( V_4 -> V_9 , V_138 ) ;
F_54 ( V_114 ) ;
V_114 -> V_46 = 0 ;
V_114 -> V_45 = 0 ;
V_4 -> V_6 -> V_163 -> V_165 ( V_4 -> V_9 , V_138 ) ;
V_4 -> V_15 -> V_166 . V_167 ++ ;
F_72 ( V_157 ) ;
}
static void F_78 ( struct V_3 * V_4 )
{
int V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num)
F_76 ( V_4 , V_138 ) ;
}
static int F_79 ( struct V_3 * const V_4 )
{
int V_168 = 0 ;
struct V_169 * V_170 = & V_4 -> V_17 ;
V_168 = V_4 -> V_6 -> V_7 -> V_171 ( V_4 -> V_9 , 0 ) ;
if ( V_168 ) {
V_170 -> V_172 =
F_80 ( V_168 ) ;
V_170 -> V_173 = F_81 ( V_168 ) ;
V_170 -> V_174 = F_82 ( V_168 ) ;
V_170 -> V_175 =
F_83 ( V_168 ) ;
V_170 -> V_176 =
F_84 ( V_168 ) ;
V_170 -> V_177 = F_85 ( V_168 ) ;
V_170 -> V_178 = F_86 ( V_168 ) ;
V_170 -> V_179 = F_87 ( V_168 ) ;
V_170 -> V_18 = F_88 ( V_168 ) ;
}
V_168 = V_4 -> V_6 -> V_7 -> V_171 ( V_4 -> V_9 , 1 ) ;
if ( V_168 ) {
V_170 -> V_180 = F_89 ( V_168 ) ;
V_170 -> V_181 = F_90 ( V_168 ) ;
V_170 -> V_182 = F_90 ( V_168 ) ;
V_170 -> V_183 = F_91 ( V_168 ) ;
V_170 -> V_184 = F_92 ( V_168 ) ;
V_170 -> V_185 = F_93 ( V_168 ) ;
V_170 -> V_186 = F_94 ( V_168 ) ;
V_170 -> V_187 = F_95 ( V_168 ) ;
V_170 -> V_188 = F_96 ( V_168 ) ;
V_170 -> V_189 = F_97 ( V_168 ) ;
}
V_168 = V_4 -> V_6 -> V_7 -> V_171 ( V_4 -> V_9 , 2 ) ;
if ( V_168 ) {
V_170 -> V_190 = F_98 ( V_168 ) ;
V_170 -> V_191 = F_99 ( V_168 ) ;
V_170 -> V_192 = F_100 ( V_168 ) ;
V_170 -> V_193 = F_101 ( V_168 ) ;
V_170 -> V_194 = F_102 ( V_168 ) ;
V_170 -> V_195 = F_103 ( V_168 ) ;
}
return V_168 ;
}
static void F_104 ( struct V_3 * V_4 )
{
if ( ! F_105 ( V_4 -> V_15 -> V_196 ) ) {
V_4 -> V_6 -> V_7 -> V_197 ( ( void V_198 * )
V_4 -> V_9 ,
V_4 -> V_15 -> V_196 , 0 ) ;
if ( ! F_105 ( V_4 -> V_15 -> V_196 ) )
F_106 ( V_4 -> V_15 ) ;
}
F_107 ( V_4 -> V_106 , L_17 ,
V_4 -> V_15 -> V_196 ) ;
}
static int F_108 ( struct V_3 * V_4 )
{
int V_199 = V_200 , V_201 = 0 , V_202 = 0 ;
int V_138 ;
if ( V_4 -> V_63 -> V_203 ) {
V_199 = V_4 -> V_63 -> V_203 -> V_199 ;
V_201 = V_4 -> V_63 -> V_203 -> V_201 ;
V_202 = V_4 -> V_63 -> V_203 -> V_202 ;
}
F_53 (SXGBE_TX_QUEUES, queue_num)
V_4 -> V_6 -> V_163 -> V_204 ( V_4 -> V_9 , V_138 ,
V_201 , V_199 ,
( V_4 -> V_93 [ V_138 ] ) -> V_117 ,
( V_4 -> V_87 [ V_138 ] ) -> V_124 ,
V_4 -> V_81 , V_4 -> V_83 ) ;
return V_4 -> V_6 -> V_163 -> V_205 ( V_4 -> V_9 , V_201 , V_202 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
int V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
V_4 -> V_6 -> V_149 -> V_206 ( V_4 -> V_9 , V_138 ,
V_4 -> V_17 . V_207 ) ;
V_4 -> V_6 -> V_149 -> V_208 ( V_4 -> V_9 , V_138 ) ;
}
}
static void F_110 ( struct V_3 * V_4 )
{
int V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num)
V_4 -> V_6 -> V_149 -> V_209 ( V_4 -> V_9 , V_138 ) ;
}
static void F_111 ( unsigned long V_107 )
{
struct V_42 * V_96 = (struct V_42 * ) V_107 ;
F_63 ( V_96 ) ;
}
static void F_112 ( struct V_3 * V_4 )
{
T_2 V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_96 = V_4 -> V_93 [ V_138 ] ;
V_96 -> V_210 = V_211 ;
V_96 -> V_212 = V_213 ;
F_11 ( & V_96 -> V_214 , F_111 ,
( unsigned long ) & V_4 -> V_93 [ V_138 ] ) ;
V_96 -> V_214 . V_21 = F_113 ( V_96 -> V_212 ) ;
F_12 ( & V_96 -> V_214 ) ;
}
}
static void F_114 ( struct V_3 * V_4 )
{
T_2 V_138 ;
F_53 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_96 = V_4 -> V_93 [ V_138 ] ;
F_5 ( & V_96 -> V_214 ) ;
}
}
static int F_115 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
int V_16 , V_138 ;
F_116 ( V_4 -> V_28 ) ;
F_104 ( V_4 ) ;
V_16 = F_23 ( V_15 ) ;
if ( V_16 ) {
F_27 ( V_15 , L_18 ,
V_70 , V_16 ) ;
goto V_215;
}
V_4 -> V_81 = F_117 ( V_216 ) ;
V_4 -> V_83 = F_117 ( V_217 ) ;
V_4 -> V_97 = F_117 ( V_218 ) ;
V_4 -> V_152 = V_219 ;
V_4 -> V_154 = V_219 ;
F_52 ( V_15 ) ;
V_16 = F_108 ( V_4 ) ;
if ( V_16 < 0 ) {
F_27 ( V_15 , L_19 , V_70 ) ;
goto V_220;
}
F_109 ( V_4 ) ;
V_4 -> V_6 -> V_7 -> V_221 ( V_4 -> V_9 , V_15 -> V_196 , 0 ) ;
V_4 -> V_6 -> V_7 -> V_222 ( V_4 -> V_9 ) ;
F_53 (SXGBE_RX_QUEUES, queue_num) {
V_4 -> V_6 -> V_7 -> V_223 ( V_4 -> V_9 , V_138 ) ;
}
V_16 = F_118 ( V_4 -> V_106 , V_4 -> V_224 , V_225 ,
V_226 , V_15 -> V_227 , V_15 ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_20 ,
V_70 , V_4 -> V_224 , V_16 ) ;
goto V_220;
}
if ( V_4 -> V_228 != V_15 -> V_224 ) {
V_16 = F_118 ( V_4 -> V_106 , V_4 -> V_228 ,
V_225 ,
V_226 , V_15 -> V_227 , V_15 ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_21 ,
V_70 , V_4 -> V_228 , V_16 ) ;
goto V_220;
}
}
F_53 (SXGBE_TX_QUEUES, queue_num) {
V_16 = F_118 ( V_4 -> V_106 ,
( V_4 -> V_93 [ V_138 ] ) -> V_229 ,
V_230 , 0 ,
V_15 -> V_227 , V_4 -> V_93 [ V_138 ] ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_22 ,
V_70 , V_4 -> V_224 , V_16 ) ;
goto V_220;
}
}
F_53 (SXGBE_RX_QUEUES, queue_num) {
V_16 = F_118 ( V_4 -> V_106 ,
( V_4 -> V_87 [ V_138 ] ) -> V_229 ,
V_231 , 0 ,
V_15 -> V_227 , V_4 -> V_87 [ V_138 ] ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_22 ,
V_70 , V_4 -> V_224 , V_16 ) ;
goto V_220;
}
}
V_4 -> V_6 -> V_7 -> V_232 ( V_4 -> V_9 , true ) ;
V_4 -> V_6 -> V_7 -> V_233 ( V_4 -> V_9 , true ) ;
F_60 ( V_4 ) ;
memset ( & V_4 -> V_158 , 0 , sizeof( struct V_234 ) ) ;
V_4 -> V_158 . V_235 = V_4 -> V_152 ;
V_4 -> V_158 . V_236 = V_4 -> V_154 ;
F_24 ( V_15 , L_23 ) ;
V_4 -> V_6 -> V_163 -> V_237 ( V_4 -> V_9 , V_91 ) ;
V_4 -> V_6 -> V_163 -> V_238 ( V_4 -> V_9 , V_84 ) ;
if ( V_15 -> V_19 )
F_119 ( V_15 -> V_19 ) ;
F_112 ( V_4 ) ;
if ( ( V_4 -> V_89 ) && ( V_4 -> V_6 -> V_163 -> V_239 ) ) {
V_4 -> V_240 = V_241 ;
V_4 -> V_6 -> V_163 -> V_239 ( V_4 -> V_9 , V_241 ) ;
}
V_4 -> V_23 = V_2 ;
V_4 -> V_24 = F_9 ( V_4 ) ;
F_120 ( & V_4 -> V_242 ) ;
F_121 ( V_15 ) ;
return 0 ;
V_220:
F_56 ( V_4 ) ;
if ( V_15 -> V_19 )
F_29 ( V_15 -> V_19 ) ;
V_215:
F_122 ( V_4 -> V_28 ) ;
return V_16 ;
}
static int F_123 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
if ( V_4 -> V_24 )
F_5 ( & V_4 -> V_11 ) ;
if ( V_15 -> V_19 ) {
F_124 ( V_15 -> V_19 ) ;
F_29 ( V_15 -> V_19 ) ;
}
F_125 ( V_15 ) ;
F_126 ( & V_4 -> V_242 ) ;
F_114 ( V_4 ) ;
V_4 -> V_6 -> V_163 -> V_243 ( V_4 -> V_9 , V_91 ) ;
V_4 -> V_6 -> V_163 -> V_244 ( V_4 -> V_9 , V_84 ) ;
F_110 ( V_4 ) ;
F_56 ( V_4 ) ;
V_4 -> V_6 -> V_7 -> V_232 ( V_4 -> V_9 , false ) ;
V_4 -> V_6 -> V_7 -> V_233 ( V_4 -> V_9 , false ) ;
F_122 ( V_4 -> V_28 ) ;
return 0 ;
}
static void F_127 ( struct V_3 * V_4 ,
struct V_116 * V_245 ,
struct V_100 * V_101 )
{
unsigned int V_246 , V_247 ;
V_247 = F_128 ( V_101 ) ;
V_246 = F_129 ( V_101 ) + V_247 ;
V_245 -> V_248 = F_33 ( V_4 -> V_106 , V_101 -> V_107 ,
V_246 , V_146 ) ;
if ( F_34 ( V_4 -> V_106 , V_245 -> V_248 ) )
F_62 ( L_24 , V_70 ) ;
V_245 -> V_249 . V_250 . V_245 = 1 ;
V_4 -> V_6 -> V_85 -> V_251 ( V_245 , 1 , V_246 ,
V_247 ,
V_101 -> V_252 - V_246 ) ;
}
static T_3 F_130 ( struct V_100 * V_101 , struct V_13 * V_15 )
{
unsigned int V_160 , V_253 ;
int V_254 = 0 ;
struct V_156 * V_157 ;
unsigned V_255 = F_131 ( V_101 ) ;
struct V_3 * V_4 = F_19 ( V_15 ) ;
unsigned int V_115 = V_4 -> V_81 ;
struct V_42 * V_147 = V_4 -> V_93 [ V_255 ] ;
struct V_116 * V_256 , * V_245 ;
struct V_257 * V_258 = NULL ;
int V_259 = F_132 ( V_101 ) -> V_259 ;
int V_260 = F_133 ( V_101 ) ;
int V_261 = 0 ;
T_4 V_262 = F_132 ( V_101 ) -> V_263 ;
T_1 V_264 = 0 ;
V_157 = F_64 ( V_15 , V_255 ) ;
if ( F_2 ( F_134 ( V_101 ) && V_147 -> V_265 != V_262 ) )
V_264 = 1 ;
if ( F_2 ( F_135 ( V_101 ) ||
( ( F_132 ( V_101 ) -> V_266 & V_267 ) &&
V_147 -> V_268 ) ) )
V_264 = 1 ;
F_65 ( & V_147 -> V_122 ) ;
if ( V_4 -> V_5 )
F_4 ( V_4 ) ;
if ( F_2 ( F_17 ( V_147 , V_115 ) < V_259 + 1 ) ) {
if ( ! F_69 ( V_157 ) ) {
F_77 ( V_157 ) ;
F_27 ( V_15 , L_25 ,
V_70 , V_255 ) ;
}
F_74 ( & V_147 -> V_122 ) ;
return V_269 ;
}
V_160 = V_147 -> V_46 % V_115 ;
V_256 = V_147 -> V_94 + V_160 ;
V_245 = V_256 ;
if ( V_264 )
V_258 = (struct V_257 * ) V_245 ;
V_147 -> V_121 [ V_160 ] = V_101 ;
if ( ! V_261 ) {
if ( F_61 ( F_134 ( V_101 ) ) ) {
if ( F_2 ( V_147 -> V_265 != V_262 ) ) {
V_4 -> V_6 -> V_85 -> V_270 (
V_258 , V_262 ) ;
V_4 -> V_6 -> V_85 -> V_271 (
V_258 ) ;
V_4 -> V_6 -> V_85 -> V_272 (
V_258 ) ;
V_4 -> V_6 -> V_85 -> V_273 (
V_258 ) ;
V_4 -> V_6 -> V_85 -> V_274 (
V_258 ) ;
V_160 = ( ++ V_147 -> V_46 ) % V_115 ;
V_245 = V_147 -> V_94 + V_160 ;
V_147 -> V_265 = V_262 ;
}
F_127 ( V_4 , V_245 , V_101 ) ;
} else {
V_256 -> V_248 = F_33 ( V_4 -> V_106 ,
V_101 -> V_107 , V_260 , V_146 ) ;
if ( F_34 ( V_4 -> V_106 , V_256 -> V_248 ) )
F_27 ( V_15 , L_24 ,
V_70 ) ;
V_4 -> V_6 -> V_85 -> V_275 ( V_256 , 1 , V_260 ,
V_260 , V_254 ) ;
}
}
for ( V_253 = 0 ; V_253 < V_259 ; V_253 ++ ) {
const T_5 * V_276 = & F_132 ( V_101 ) -> V_277 [ V_253 ] ;
int V_252 = F_136 ( V_276 ) ;
V_160 = ( ++ V_147 -> V_46 ) % V_115 ;
V_256 = V_147 -> V_94 + V_160 ;
V_256 -> V_248 = F_137 ( V_4 -> V_106 , V_276 , 0 , V_252 ,
V_146 ) ;
V_147 -> V_118 [ V_160 ] = V_256 -> V_248 ;
V_147 -> V_121 [ V_160 ] = NULL ;
V_4 -> V_6 -> V_85 -> V_275 ( V_256 , 0 , V_252 ,
V_252 , V_254 ) ;
F_138 () ;
V_4 -> V_6 -> V_85 -> V_278 ( V_256 ) ;
}
V_4 -> V_6 -> V_85 -> V_279 ( V_256 ) ;
F_138 () ;
V_147 -> V_280 += V_259 + 1 ;
if ( V_147 -> V_280 > V_147 -> V_210 ) {
V_4 -> V_6 -> V_85 -> V_281 ( V_256 ) ;
V_4 -> V_158 . V_282 ++ ;
F_7 ( & V_147 -> V_214 ,
F_113 ( V_147 -> V_212 ) ) ;
} else {
V_147 -> V_280 = 0 ;
}
V_4 -> V_6 -> V_85 -> V_278 ( V_245 ) ;
F_138 () ;
V_147 -> V_46 ++ ;
F_49 ( V_4 , V_283 , V_15 , L_26 ,
V_70 , V_147 -> V_46 % V_115 ,
V_147 -> V_45 % V_115 , V_160 ,
V_245 , V_259 ) ;
if ( F_2 ( F_17 ( V_147 , V_115 ) <= ( V_284 + 1 ) ) ) {
F_49 ( V_4 , V_6 , V_15 , L_27 ,
V_70 ) ;
F_77 ( V_157 ) ;
}
V_15 -> V_166 . V_285 += V_101 -> V_252 ;
if ( F_2 ( ( F_132 ( V_101 ) -> V_266 & V_267 ) &&
V_147 -> V_268 ) ) {
F_132 ( V_101 ) -> V_266 |= V_286 ;
V_4 -> V_6 -> V_85 -> V_287 ( V_245 ) ;
}
if ( ! V_147 -> V_268 )
F_139 ( V_101 ) ;
V_4 -> V_6 -> V_163 -> V_288 ( V_4 -> V_9 , V_255 ) ;
F_74 ( & V_147 -> V_122 ) ;
return V_289 ;
}
static void F_140 ( struct V_3 * V_4 )
{
unsigned int V_82 = V_4 -> V_83 ;
int V_126 = V_4 -> V_97 ;
T_2 V_290 = V_4 -> V_291 ;
for (; V_4 -> V_87 [ V_290 ] -> V_135 - V_4 -> V_87 [ V_290 ] -> V_136 > 0 ;
V_4 -> V_87 [ V_290 ] -> V_136 ++ ) {
unsigned int V_160 = V_4 -> V_87 [ V_290 ] -> V_136 % V_82 ;
struct V_95 * V_96 ;
V_96 = V_4 -> V_87 [ V_290 ] -> V_88 + V_160 ;
if ( F_61 ( V_4 -> V_87 [ V_290 ] -> V_104 [ V_160 ] == NULL ) ) {
struct V_100 * V_101 ;
V_101 = F_141 ( V_4 -> V_15 , V_126 ) ;
if ( F_2 ( V_101 == NULL ) )
break;
V_4 -> V_87 [ V_290 ] -> V_104 [ V_160 ] = V_101 ;
V_4 -> V_87 [ V_290 ] -> V_105 [ V_160 ] =
F_33 ( V_4 -> V_106 , V_101 -> V_107 , V_126 ,
V_108 ) ;
V_96 -> V_110 . V_111 . V_112 =
V_4 -> V_87 [ V_290 ] -> V_105 [ V_160 ] ;
}
F_138 () ;
V_4 -> V_6 -> V_85 -> V_292 ( V_96 ) ;
V_4 -> V_6 -> V_85 -> V_293 ( V_96 ) ;
F_138 () ;
}
}
static int F_142 ( struct V_3 * V_4 , int V_294 )
{
T_2 V_290 = V_4 -> V_291 ;
unsigned int V_82 = V_4 -> V_83 ;
unsigned int V_160 = V_4 -> V_87 [ V_290 ] -> V_135 ;
unsigned int V_295 = 0 ;
unsigned int V_296 = 0 ;
int V_297 ;
int V_298 ;
while ( V_296 < V_294 ) {
struct V_95 * V_96 ;
struct V_100 * V_101 ;
int V_299 ;
V_96 = V_4 -> V_87 [ V_290 ] -> V_88 + V_160 ;
if ( V_4 -> V_6 -> V_85 -> V_300 ( V_96 ) )
break;
V_296 ++ ;
V_295 = ( ++ V_4 -> V_87 [ V_290 ] -> V_135 ) % V_82 ;
F_143 ( V_4 -> V_87 [ V_290 ] -> V_88 + V_295 ) ;
V_298 = V_4 -> V_6 -> V_85 -> V_301 ( V_96 , & V_4 -> V_158 ,
& V_297 ) ;
if ( F_2 ( V_298 < 0 ) ) {
V_160 = V_295 ;
continue;
}
if ( F_2 ( ! V_4 -> V_302 ) )
V_297 = V_303 ;
V_101 = V_4 -> V_87 [ V_290 ] -> V_104 [ V_160 ] ;
if ( F_2 ( ! V_101 ) )
F_27 ( V_4 -> V_15 , L_28 ) ;
F_143 ( V_101 -> V_107 - V_130 ) ;
V_4 -> V_87 [ V_290 ] -> V_104 [ V_160 ] = NULL ;
V_299 = V_4 -> V_6 -> V_85 -> V_304 ( V_96 ) ;
F_144 ( V_101 , V_299 ) ;
V_101 -> V_305 = V_297 ;
if ( V_297 == V_303 )
F_145 ( V_101 ) ;
else
F_146 ( & V_4 -> V_242 , V_101 ) ;
V_160 = V_295 ;
}
F_140 ( V_4 ) ;
return V_296 ;
}
static int F_147 ( struct V_306 * V_242 , int V_307 )
{
struct V_3 * V_4 = F_148 ( V_242 ,
struct V_3 , V_242 ) ;
int V_308 = 0 ;
T_2 V_290 = V_4 -> V_291 ;
V_4 -> V_158 . V_309 ++ ;
F_75 ( V_4 ) ;
V_308 = F_142 ( V_4 , V_307 ) ;
if ( V_308 < V_307 ) {
F_149 ( V_242 ) ;
V_4 -> V_6 -> V_163 -> V_310 ( V_4 -> V_9 , V_290 ) ;
}
return V_308 ;
}
static void F_150 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
F_78 ( V_4 ) ;
}
static T_6 V_225 ( int V_224 , void * V_311 )
{
struct V_13 * V_312 = (struct V_13 * ) V_311 ;
struct V_3 * V_4 = F_19 ( V_312 ) ;
int V_298 ;
V_298 = V_4 -> V_6 -> V_7 -> V_313 ( V_4 -> V_9 , & V_4 -> V_158 ) ;
if ( V_298 & V_314 ) {
V_4 -> V_158 . V_315 ++ ;
V_4 -> V_5 = true ;
}
if ( V_298 & V_316 ) {
V_4 -> V_158 . V_317 ++ ;
V_4 -> V_5 = false ;
}
if ( V_298 & V_318 )
V_4 -> V_158 . V_319 ++ ;
if ( V_298 & V_320 )
V_4 -> V_158 . V_321 ++ ;
return V_322 ;
}
static T_6 V_230 ( int V_224 , void * V_311 )
{
int V_298 ;
struct V_42 * V_93 = (struct V_42 * ) V_311 ;
struct V_3 * V_4 = V_93 -> V_140 ;
V_298 = V_4 -> V_6 -> V_163 -> V_323 ( V_4 -> V_9 , V_93 -> V_113 ,
& V_4 -> V_158 ) ;
if ( F_61 ( ( V_298 & V_324 ) ) )
F_151 ( & V_4 -> V_242 ) ;
if ( F_2 ( ( V_298 & V_325 ) ) )
F_76 ( V_4 , V_93 -> V_113 ) ;
if ( F_2 ( ( V_298 & V_326 ) &&
( V_4 -> V_152 != V_151 ) &&
( V_4 -> V_152 < 512 ) ) ) {
V_4 -> V_152 += ( V_4 -> V_152 < 128 ) ? 32 : 64 ;
V_4 -> V_6 -> V_149 -> V_150 ( V_4 -> V_9 ,
V_93 -> V_113 , V_4 -> V_152 ) ;
V_4 -> V_158 . V_235 = V_4 -> V_152 ;
}
return V_322 ;
}
static T_6 V_231 ( int V_224 , void * V_311 )
{
int V_298 ;
struct V_98 * V_87 = (struct V_98 * ) V_311 ;
struct V_3 * V_4 = V_87 -> V_140 ;
V_298 = V_4 -> V_6 -> V_163 -> V_327 ( V_4 -> V_9 , V_87 -> V_113 ,
& V_4 -> V_158 ) ;
if ( F_61 ( ( V_298 & V_328 ) && ( F_152 ( & V_4 -> V_242 ) ) ) ) {
V_4 -> V_6 -> V_163 -> V_329 ( V_4 -> V_9 , V_87 -> V_113 ) ;
F_153 ( & V_4 -> V_242 ) ;
}
if ( F_2 ( ( V_298 & V_330 ) &&
( V_4 -> V_154 != V_151 ) &&
( V_4 -> V_154 < 128 ) ) ) {
V_4 -> V_154 += 32 ;
V_4 -> V_6 -> V_149 -> V_153 ( V_4 -> V_9 ,
V_87 -> V_113 , V_4 -> V_154 ) ;
V_4 -> V_158 . V_236 = V_4 -> V_154 ;
}
return V_322 ;
}
static inline T_7 F_154 ( void V_198 * V_9 , int V_331 , int V_332 )
{
T_7 V_333 = F_155 ( V_9 + V_331 ) ;
V_333 |= ( ( T_7 ) F_155 ( V_9 + V_332 ) ) << 32 ;
return V_333 ;
}
static struct V_334 * F_156 ( struct V_13 * V_15 ,
struct V_334 * V_166 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
void V_198 * V_9 = V_4 -> V_9 ;
T_7 V_296 ;
F_65 ( & V_4 -> V_335 ) ;
F_157 ( V_336 , V_9 + V_337 ) ;
V_166 -> V_338 = F_154 ( V_9 ,
V_339 ,
V_340 ) ;
V_166 -> V_341 = F_154 ( V_9 ,
V_342 ,
V_343 ) ;
V_166 -> V_344 = F_154 ( V_9 ,
V_345 ,
V_346 ) ;
V_166 -> V_347 = F_154 ( V_9 ,
V_348 ,
V_349 ) ;
V_166 -> V_350 = F_154 ( V_9 ,
V_351 ,
V_352 ) ;
V_166 -> V_353 = F_154 ( V_9 ,
V_354 ,
V_355 ) ;
V_166 -> V_285 = F_154 ( V_9 ,
V_356 ,
V_357 ) ;
V_296 = F_154 ( V_9 , V_358 ,
V_359 ) ;
V_166 -> V_167 = F_154 ( V_9 , V_360 ,
V_361 ) ;
V_166 -> V_167 = V_296 - V_166 -> V_167 ;
V_166 -> V_362 = V_296 ;
V_166 -> V_363 = F_154 ( V_9 , V_364 ,
V_365 ) ;
F_157 ( 0 , V_9 + V_337 ) ;
F_74 ( & V_4 -> V_335 ) ;
return V_166 ;
}
static int F_158 ( struct V_13 * V_15 ,
T_8 V_170 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
T_8 V_366 = V_15 -> V_170 ^ V_170 ;
if ( V_366 & V_367 ) {
if ( V_170 & V_367 ) {
V_4 -> V_6 -> V_7 -> V_368 ( V_4 -> V_9 ) ;
V_4 -> V_302 = true ;
} else {
V_4 -> V_6 -> V_7 -> V_369 ( V_4 -> V_9 ) ;
V_4 -> V_302 = false ;
}
}
return 0 ;
}
static int F_159 ( struct V_13 * V_15 , int V_370 )
{
if ( V_370 < V_371 || ( V_370 > V_372 ) ) {
F_27 ( V_15 , L_29 ,
V_371 , V_372 ) ;
return - V_109 ;
}
if ( V_15 -> V_127 == V_370 )
return 0 ;
V_15 -> V_127 = V_370 ;
if ( ! F_160 ( V_15 ) )
return 0 ;
F_123 ( V_15 ) ;
return F_115 ( V_15 ) ;
}
static void F_161 ( void V_198 * V_9 , unsigned char * V_373 ,
unsigned int V_374 )
{
unsigned long V_107 ;
V_107 = ( V_373 [ 5 ] << 8 ) | V_373 [ 4 ] ;
F_157 ( V_107 | V_375 , V_9 + F_162 ( V_374 ) ) ;
V_107 = ( V_373 [ 3 ] << 24 ) | ( V_373 [ 2 ] << 16 ) | ( V_373 [ 1 ] << 8 ) | V_373 [ 0 ] ;
F_157 ( V_107 , V_9 + F_163 ( V_374 ) ) ;
}
static void F_164 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
void V_198 * V_9 = ( void V_198 * ) V_4 -> V_9 ;
unsigned int V_376 = 0 ;
T_1 V_377 [ 2 ] ;
struct V_378 * V_379 ;
int V_380 = 1 ;
F_24 ( V_15 , L_30 ,
V_70 , F_165 ( V_15 ) , F_166 ( V_15 ) ) ;
if ( V_15 -> V_381 & V_382 ) {
V_376 = V_383 ;
} else if ( ( F_165 ( V_15 ) > V_384 ) ||
( V_15 -> V_381 & V_385 ) ) {
V_376 = V_386 ;
F_157 ( 0xffffffff , V_9 + V_387 ) ;
F_157 ( 0xffffffff , V_9 + V_388 ) ;
} else if ( ! F_167 ( V_15 ) ) {
V_376 = V_389 ;
memset ( V_377 , 0 , sizeof( V_377 ) ) ;
F_168 (ha, dev) {
int V_390 = F_169 ( ~ F_170 ( ~ 0 , V_379 -> V_373 , 6 ) ) >> 26 ;
V_377 [ V_390 >> 5 ] |= 1 << ( V_390 & 31 ) ;
}
F_157 ( V_377 [ 0 ] , V_9 + V_388 ) ;
F_157 ( V_377 [ 1 ] , V_9 + V_387 ) ;
}
if ( F_166 ( V_15 ) > V_391 )
V_376 |= V_383 ;
else {
F_171 (ha, dev) {
F_161 ( V_9 , V_379 -> V_373 , V_380 ) ;
V_380 ++ ;
}
}
#ifdef F_172
V_376 |= V_392 ;
#endif
F_157 ( V_376 , V_9 + V_393 ) ;
F_24 ( V_15 , L_31 ,
F_155 ( V_9 + V_393 ) ,
F_155 ( V_9 + V_387 ) ,
F_155 ( V_9 + V_388 ) ) ;
}
static void F_173 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
F_174 ( V_4 -> V_224 ) ;
V_231 ( V_4 -> V_224 , V_15 ) ;
F_175 ( V_4 -> V_224 ) ;
}
static int F_176 ( struct V_13 * V_15 , struct V_394 * V_395 , int V_396 )
{
int V_16 = - V_397 ;
if ( ! F_160 ( V_15 ) )
return - V_109 ;
switch ( V_396 ) {
case V_398 :
case V_399 :
case V_400 :
if ( ! V_15 -> V_19 )
return - V_109 ;
V_16 = F_177 ( V_15 -> V_19 , V_395 , V_396 ) ;
break;
default:
break;
}
return V_16 ;
}
static void F_178 ( struct V_401 * const V_402 )
{
V_402 -> V_7 = F_179 () ;
V_402 -> V_85 = F_180 () ;
V_402 -> V_163 = F_181 () ;
V_402 -> V_149 = F_182 () ;
V_402 -> V_403 . V_373 = V_404 ;
V_402 -> V_403 . V_107 = V_405 ;
V_402 -> V_26 . V_406 = 0 ;
V_402 -> V_26 . V_407 = 0 ;
V_402 -> V_26 . V_49 = V_51 ;
}
static int F_183 ( struct V_3 * const V_4 )
{
T_1 V_408 ;
V_4 -> V_6 = F_184 ( sizeof( * V_4 -> V_6 ) , V_102 ) ;
if( ! V_4 -> V_6 )
return - V_103 ;
F_178 ( V_4 -> V_6 ) ;
V_408 = V_4 -> V_6 -> V_7 -> V_409 ( V_4 -> V_9 ) ;
V_4 -> V_6 -> V_410 = ( V_408 & 0x00ff0000 ) >> 16 ;
V_4 -> V_6 -> V_411 = ( V_408 & 0x000000ff ) ;
F_13 ( L_32 ,
V_4 -> V_6 -> V_410 , V_4 -> V_6 -> V_411 ) ;
if ( ! F_79 ( V_4 ) )
F_13 ( L_33 ) ;
if ( V_4 -> V_17 . V_175 )
F_13 ( L_34 ) ;
if ( V_4 -> V_17 . V_176 )
F_13 ( L_35 ) ;
return 0 ;
}
static int F_185 ( void V_198 * V_373 )
{
int V_412 = 10 ;
F_157 ( V_413 , V_373 + V_414 ) ;
while ( V_412 -- ) {
if ( ! ( F_155 ( V_373 + V_414 ) &
V_413 ) )
break;
F_186 ( 10 ) ;
}
if ( V_412 < 0 )
return - V_415 ;
return 0 ;
}
struct V_3 * F_187 ( struct V_106 * V_106 ,
struct V_416 * V_417 ,
void V_198 * V_373 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_16 ;
T_2 V_138 ;
V_14 = F_188 ( sizeof( struct V_3 ) ,
V_91 , V_84 ) ;
if ( ! V_14 )
return NULL ;
F_189 ( V_14 , V_106 ) ;
V_4 = F_19 ( V_14 ) ;
V_4 -> V_106 = V_106 ;
V_4 -> V_15 = V_14 ;
F_190 ( V_14 ) ;
V_4 -> V_63 = V_417 ;
V_4 -> V_9 = V_373 ;
V_16 = F_185 ( V_4 -> V_9 ) ;
if ( V_16 )
goto V_418;
F_1 () ;
V_16 = F_183 ( V_4 ) ;
if ( V_16 )
goto V_418;
V_16 = F_57 ( V_4 ) ;
if ( V_16 )
goto V_419;
V_16 = F_59 ( V_4 ) ;
if ( V_16 )
goto V_419;
V_14 -> V_420 = & V_421 ;
V_14 -> V_422 = V_423 | V_424 | V_425 |
V_367 | V_426 | V_427 |
V_428 ;
V_14 -> V_170 |= V_14 -> V_422 | V_429 ;
V_14 -> V_430 = F_191 ( V_431 ) ;
V_14 -> V_432 |= V_433 ;
V_4 -> V_434 = F_192 ( V_435 , V_436 ) ;
if ( V_4 -> V_17 . V_185 ) {
F_53 (SXGBE_TX_QUEUES, queue_num) {
V_4 -> V_6 -> V_163 -> V_437 ( V_4 -> V_9 , V_138 ) ;
}
}
if ( V_4 -> V_17 . V_176 ) {
V_4 -> V_6 -> V_7 -> V_368 ( V_4 -> V_9 ) ;
V_4 -> V_302 = true ;
}
V_4 -> V_438 = 1 ;
V_4 -> V_439 = 1 ;
if ( ! V_4 -> V_63 -> V_440 ) {
V_4 -> V_89 = 1 ;
F_13 ( L_36 ) ;
}
F_193 ( V_14 , & V_4 -> V_242 , F_147 , 64 ) ;
F_43 ( & V_4 -> V_335 ) ;
V_4 -> V_28 = F_194 ( V_4 -> V_106 , V_441 ) ;
if ( F_26 ( V_4 -> V_28 ) ) {
F_195 ( V_14 , L_37 ,
V_70 ) ;
goto V_442;
}
if ( ! V_4 -> V_63 -> V_30 )
F_15 ( V_4 ) ;
else
V_4 -> V_30 = V_4 -> V_63 -> V_30 ;
V_16 = F_196 ( V_14 ) ;
if ( V_16 < 0 ) {
F_24 ( V_14 , L_38 ,
V_70 , V_4 -> V_63 -> V_61 ) ;
goto V_443;
}
V_16 = F_197 ( V_14 ) ;
if ( V_16 ) {
F_62 ( L_39 , V_70 , V_16 ) ;
goto V_444;
}
F_104 ( V_4 ) ;
return V_4 ;
V_444:
F_198 ( V_14 ) ;
V_443:
F_199 ( V_4 -> V_28 ) ;
V_442:
F_200 ( & V_4 -> V_242 ) ;
V_419:
F_46 ( V_4 -> V_6 ) ;
V_418:
F_201 ( V_14 ) ;
return NULL ;
}
int F_202 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_19 ( V_14 ) ;
T_2 V_138 ;
F_203 ( V_14 , L_40 , V_70 ) ;
F_53 (SXGBE_RX_QUEUES, queue_num) {
V_4 -> V_6 -> V_7 -> V_445 ( V_4 -> V_9 , V_138 ) ;
}
V_4 -> V_6 -> V_163 -> V_244 ( V_4 -> V_9 , V_84 ) ;
V_4 -> V_6 -> V_163 -> V_243 ( V_4 -> V_9 , V_91 ) ;
V_4 -> V_6 -> V_7 -> V_232 ( V_4 -> V_9 , false ) ;
V_4 -> V_6 -> V_7 -> V_233 ( V_4 -> V_9 , false ) ;
F_204 ( V_14 ) ;
F_198 ( V_14 ) ;
F_199 ( V_4 -> V_28 ) ;
F_200 ( & V_4 -> V_242 ) ;
F_46 ( V_4 -> V_6 ) ;
F_201 ( V_14 ) ;
return 0 ;
}
int F_205 ( struct V_13 * V_14 )
{
return 0 ;
}
int F_206 ( struct V_13 * V_14 )
{
return 0 ;
}
int F_207 ( struct V_13 * V_14 )
{
return - V_446 ;
}
int F_208 ( struct V_13 * V_14 )
{
return - V_446 ;
}
static int T_9 F_209 ( void )
{
int V_16 ;
V_16 = F_210 () ;
if ( V_16 )
goto V_447;
return 0 ;
V_447:
F_62 ( L_41 ) ;
return V_16 ;
}
static void T_10 F_211 ( void )
{
F_212 () ;
}
static int T_9 F_213 ( char * V_448 )
{
char * V_449 ;
if ( ! V_448 || ! * V_448 )
return - V_109 ;
while ( ( V_449 = F_214 ( & V_448 , L_42 ) ) != NULL ) {
if ( ! strncmp ( V_449 , L_43 , 6 ) ) {
if ( F_215 ( V_449 + 10 , 0 , & V_1 ) )
goto V_447;
}
}
return 0 ;
V_447:
F_62 ( L_44 , V_70 ) ;
return - V_109 ;
}
