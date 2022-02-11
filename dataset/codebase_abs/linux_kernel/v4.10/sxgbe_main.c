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
return 0 ;
V_120:
F_43 ( V_15 , V_115 * sizeof( struct V_116 ) ,
V_114 -> V_94 , V_114 -> V_117 ) ;
return - V_103 ;
}
static void F_44 ( struct V_106 * V_15 , struct V_98 * V_99 ,
int V_122 )
{
F_43 ( V_15 , V_122 * sizeof( struct V_95 ) ,
V_99 -> V_88 , V_99 -> V_123 ) ;
F_45 ( V_99 -> V_105 ) ;
F_45 ( V_99 -> V_104 ) ;
}
static int F_46 ( struct V_13 * V_15 , T_2 V_113 ,
struct V_98 * V_99 , int V_122 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
int V_124 ;
unsigned int V_125 = 0 ;
unsigned int V_16 = 0 ;
V_125 = F_47 ( V_15 -> V_126 + V_127 + V_128 + V_129 , 8 ) ;
F_48 ( V_4 , V_130 , V_15 , L_10 , V_70 , V_125 ) ;
if ( V_99 == NULL ) {
F_27 ( V_15 , L_11 ) ;
return - V_103 ;
}
V_99 -> V_113 = V_113 ;
V_99 -> V_88 = F_41 ( V_4 -> V_106 ,
V_122 * sizeof( struct V_95 ) ,
& V_99 -> V_123 , V_102 ) ;
if ( V_99 -> V_88 == NULL )
return - V_103 ;
V_99 -> V_105 = F_49 ( V_122 ,
sizeof( V_119 ) , V_102 ) ;
if ( ! V_99 -> V_105 ) {
V_16 = - V_103 ;
goto V_131;
}
V_99 -> V_104 = F_49 ( V_122 ,
sizeof( struct V_100 * ) , V_102 ) ;
if ( ! V_99 -> V_104 ) {
V_16 = - V_103 ;
goto V_132;
}
for ( V_124 = 0 ; V_124 < V_122 ; V_124 ++ ) {
struct V_95 * V_96 ;
V_96 = V_99 -> V_88 + V_124 ;
V_16 = F_31 ( V_15 , V_96 , V_124 ,
V_125 , V_99 ) ;
if ( V_16 )
goto V_133;
}
V_99 -> V_134 = 0 ;
V_99 -> V_135 = ( unsigned int ) ( V_124 - V_122 ) ;
V_4 -> V_97 = V_125 ;
return 0 ;
V_133:
while ( -- V_124 >= 0 ) {
struct V_95 * V_96 ;
V_96 = V_99 -> V_88 + V_124 ;
F_36 ( V_15 , V_96 , V_124 , V_125 , V_99 ) ;
}
F_45 ( V_99 -> V_104 ) ;
V_132:
F_45 ( V_99 -> V_105 ) ;
V_131:
F_43 ( V_4 -> V_106 ,
V_122 * sizeof( struct V_95 ) ,
V_99 -> V_88 , V_99 -> V_123 ) ;
return V_16 ;
}
static void F_50 ( struct V_106 * V_15 , struct V_42 * V_114 ,
int V_115 )
{
F_43 ( V_15 , V_115 * sizeof( struct V_116 ) ,
V_114 -> V_94 , V_114 -> V_117 ) ;
}
static int F_51 ( struct V_13 * V_136 )
{
int V_137 , V_16 ;
struct V_3 * V_4 = F_19 ( V_136 ) ;
int V_115 = V_4 -> V_81 ;
int V_122 = V_4 -> V_83 ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
V_16 = F_39 ( V_4 -> V_106 , V_137 ,
V_4 -> V_93 [ V_137 ] , V_115 ) ;
if ( V_16 ) {
F_40 ( & V_136 -> V_15 , L_12 ) ;
goto V_138;
}
V_4 -> V_93 [ V_137 ] -> V_139 = V_4 ;
}
F_52 (SXGBE_RX_QUEUES, queue_num) {
V_16 = F_46 ( V_136 , V_137 ,
V_4 -> V_87 [ V_137 ] , V_122 ) ;
if ( V_16 ) {
F_27 ( V_136 , L_13 ) ;
goto V_140;
}
V_4 -> V_87 [ V_137 ] -> V_139 = V_4 ;
}
F_30 ( V_4 ) ;
return 0 ;
V_138:
while ( V_137 -- )
F_50 ( V_4 -> V_106 , V_4 -> V_93 [ V_137 ] , V_115 ) ;
return V_16 ;
V_140:
while ( V_137 -- )
F_44 ( V_4 -> V_106 , V_4 -> V_87 [ V_137 ] , V_122 ) ;
return V_16 ;
}
static void F_53 ( struct V_42 * V_141 )
{
int V_142 ;
struct V_3 * V_4 = V_141 -> V_139 ;
int V_115 = V_4 -> V_81 ;
for ( V_142 = 0 ; V_142 < V_115 ; V_142 ++ ) {
struct V_116 * V_143 = V_141 -> V_94 + V_142 ;
if ( V_141 -> V_118 [ V_142 ] )
F_38 ( V_4 -> V_106 ,
V_141 -> V_118 [ V_142 ] ,
V_4 -> V_6 -> V_85 -> V_144 ( V_143 ) ,
V_145 ) ;
F_35 ( V_141 -> V_121 [ V_142 ] ) ;
V_141 -> V_121 [ V_142 ] = NULL ;
V_141 -> V_118 [ V_142 ] = 0 ;
}
}
static void F_54 ( struct V_3 * V_4 )
{
int V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_146 = V_4 -> V_93 [ V_137 ] ;
F_53 ( V_146 ) ;
}
}
static void F_55 ( struct V_3 * V_4 )
{
int V_137 ;
int V_115 = V_4 -> V_81 ;
int V_122 = V_4 -> V_83 ;
F_54 ( V_4 ) ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
F_50 ( V_4 -> V_106 , V_4 -> V_93 [ V_137 ] , V_115 ) ;
}
F_52 (SXGBE_RX_QUEUES, queue_num) {
F_44 ( V_4 -> V_106 , V_4 -> V_87 [ V_137 ] , V_122 ) ;
}
}
static int F_56 ( struct V_3 * V_4 )
{
int V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
V_4 -> V_93 [ V_137 ] = F_57 ( V_4 -> V_106 ,
sizeof( struct V_42 ) , V_102 ) ;
if ( ! V_4 -> V_93 [ V_137 ] )
return - V_103 ;
}
return 0 ;
}
static int F_58 ( struct V_3 * V_4 )
{
int V_137 ;
F_52 (SXGBE_RX_QUEUES, queue_num) {
V_4 -> V_87 [ V_137 ] = F_57 ( V_4 -> V_106 ,
sizeof( struct V_98 ) , V_102 ) ;
if ( ! V_4 -> V_87 [ V_137 ] )
return - V_103 ;
}
return 0 ;
}
static void F_59 ( struct V_3 * V_4 )
{
int V_137 ;
if ( F_60 ( V_4 -> V_63 -> V_147 ) ) {
F_52 (priv->hw_cap.tx_mtl_queues, queue_num)
V_4 -> V_6 -> V_148 -> V_149 ( V_4 -> V_9 , V_137 ,
V_150 ) ;
V_4 -> V_151 = V_150 ;
F_52 (priv->hw_cap.rx_mtl_queues, queue_num)
V_4 -> V_6 -> V_148 -> V_152 ( V_4 -> V_9 , V_137 ,
V_150 ) ;
V_4 -> V_153 = V_150 ;
} else if ( F_2 ( V_4 -> V_63 -> V_154 ) ) {
F_52 (priv->hw_cap.tx_mtl_queues, queue_num)
V_4 -> V_6 -> V_148 -> V_149 ( V_4 -> V_9 , V_137 ,
V_4 -> V_151 ) ;
F_52 (priv->hw_cap.rx_mtl_queues, queue_num)
V_4 -> V_6 -> V_148 -> V_152 ( V_4 -> V_9 , V_137 ,
V_4 -> V_153 ) ;
} else {
F_61 ( L_14 , V_70 ) ;
}
}
static void F_62 ( struct V_42 * V_146 )
{
struct V_3 * V_4 = V_146 -> V_139 ;
unsigned int V_115 = V_4 -> V_81 ;
struct V_155 * V_156 ;
T_2 V_113 = V_146 -> V_113 ;
V_156 = F_63 ( V_4 -> V_15 , V_113 ) ;
F_64 ( V_156 , F_65 () ) ;
V_4 -> V_157 . V_158 ++ ;
while ( V_146 -> V_45 != V_146 -> V_46 ) {
unsigned int V_159 = V_146 -> V_45 % V_115 ;
struct V_100 * V_101 = V_146 -> V_121 [ V_159 ] ;
struct V_116 * V_96 ;
V_96 = V_146 -> V_94 + V_159 ;
if ( V_4 -> V_6 -> V_85 -> V_160 ( V_96 ) )
break;
if ( F_66 ( V_4 ) )
F_67 ( L_15 ,
V_70 , V_146 -> V_46 , V_146 -> V_45 ) ;
if ( F_60 ( V_146 -> V_118 [ V_159 ] ) ) {
F_38 ( V_4 -> V_106 ,
V_146 -> V_118 [ V_159 ] ,
V_4 -> V_6 -> V_85 -> V_144 ( V_96 ) ,
V_145 ) ;
V_146 -> V_118 [ V_159 ] = 0 ;
}
if ( F_60 ( V_101 ) ) {
F_68 ( V_101 ) ;
V_146 -> V_121 [ V_159 ] = NULL ;
}
V_4 -> V_6 -> V_85 -> V_161 ( V_96 ) ;
V_146 -> V_45 ++ ;
}
if ( F_2 ( F_69 ( V_156 ) &&
F_17 ( V_146 , V_115 ) > F_70 ( V_4 ) ) ) {
if ( F_66 ( V_4 ) )
F_67 ( L_16 , V_70 ) ;
F_71 ( V_156 ) ;
}
F_72 ( V_156 ) ;
}
static void F_73 ( struct V_3 * const V_4 )
{
T_2 V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_146 = V_4 -> V_93 [ V_137 ] ;
F_62 ( V_146 ) ;
}
if ( ( V_4 -> V_24 ) && ( ! V_4 -> V_5 ) ) {
F_3 ( V_4 ) ;
F_7 ( & V_4 -> V_11 , F_8 ( V_1 ) ) ;
}
}
static void F_74 ( struct V_3 * V_4 , int V_137 )
{
struct V_42 * V_114 = V_4 -> V_93 [ V_137 ] ;
struct V_155 * V_156 = F_63 ( V_4 -> V_15 ,
V_137 ) ;
F_75 ( V_156 ) ;
V_4 -> V_6 -> V_162 -> V_163 ( V_4 -> V_9 , V_137 ) ;
F_53 ( V_114 ) ;
V_114 -> V_46 = 0 ;
V_114 -> V_45 = 0 ;
V_4 -> V_6 -> V_162 -> V_164 ( V_4 -> V_9 , V_137 ) ;
V_4 -> V_15 -> V_165 . V_166 ++ ;
F_71 ( V_156 ) ;
}
static void F_76 ( struct V_3 * V_4 )
{
int V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num)
F_74 ( V_4 , V_137 ) ;
}
static int F_77 ( struct V_3 * const V_4 )
{
int V_167 = 0 ;
struct V_168 * V_169 = & V_4 -> V_17 ;
V_167 = V_4 -> V_6 -> V_7 -> V_170 ( V_4 -> V_9 , 0 ) ;
if ( V_167 ) {
V_169 -> V_171 =
F_78 ( V_167 ) ;
V_169 -> V_172 = F_79 ( V_167 ) ;
V_169 -> V_173 = F_80 ( V_167 ) ;
V_169 -> V_174 =
F_81 ( V_167 ) ;
V_169 -> V_175 =
F_82 ( V_167 ) ;
V_169 -> V_176 = F_83 ( V_167 ) ;
V_169 -> V_177 = F_84 ( V_167 ) ;
V_169 -> V_178 = F_85 ( V_167 ) ;
V_169 -> V_18 = F_86 ( V_167 ) ;
}
V_167 = V_4 -> V_6 -> V_7 -> V_170 ( V_4 -> V_9 , 1 ) ;
if ( V_167 ) {
V_169 -> V_179 = F_87 ( V_167 ) ;
V_169 -> V_180 = F_88 ( V_167 ) ;
V_169 -> V_181 = F_88 ( V_167 ) ;
V_169 -> V_182 = F_89 ( V_167 ) ;
V_169 -> V_183 = F_90 ( V_167 ) ;
V_169 -> V_184 = F_91 ( V_167 ) ;
V_169 -> V_185 = F_92 ( V_167 ) ;
V_169 -> V_186 = F_93 ( V_167 ) ;
V_169 -> V_187 = F_94 ( V_167 ) ;
V_169 -> V_188 = F_95 ( V_167 ) ;
}
V_167 = V_4 -> V_6 -> V_7 -> V_170 ( V_4 -> V_9 , 2 ) ;
if ( V_167 ) {
V_169 -> V_189 = F_96 ( V_167 ) ;
V_169 -> V_190 = F_97 ( V_167 ) ;
V_169 -> V_191 = F_98 ( V_167 ) ;
V_169 -> V_192 = F_99 ( V_167 ) ;
V_169 -> V_193 = F_100 ( V_167 ) ;
V_169 -> V_194 = F_101 ( V_167 ) ;
}
return V_167 ;
}
static void F_102 ( struct V_3 * V_4 )
{
if ( ! F_103 ( V_4 -> V_15 -> V_195 ) ) {
V_4 -> V_6 -> V_7 -> V_196 ( ( void V_197 * )
V_4 -> V_9 ,
V_4 -> V_15 -> V_195 , 0 ) ;
if ( ! F_103 ( V_4 -> V_15 -> V_195 ) )
F_104 ( V_4 -> V_15 ) ;
}
F_105 ( V_4 -> V_106 , L_17 ,
V_4 -> V_15 -> V_195 ) ;
}
static int F_106 ( struct V_3 * V_4 )
{
int V_198 = V_199 , V_200 = 0 , V_201 = 0 ;
int V_137 ;
if ( V_4 -> V_63 -> V_202 ) {
V_198 = V_4 -> V_63 -> V_202 -> V_198 ;
V_200 = V_4 -> V_63 -> V_202 -> V_200 ;
V_201 = V_4 -> V_63 -> V_202 -> V_201 ;
}
F_52 (SXGBE_TX_QUEUES, queue_num)
V_4 -> V_6 -> V_162 -> V_203 ( V_4 -> V_9 , V_137 ,
V_200 , V_198 ,
( V_4 -> V_93 [ V_137 ] ) -> V_117 ,
( V_4 -> V_87 [ V_137 ] ) -> V_123 ,
V_4 -> V_81 , V_4 -> V_83 ) ;
return V_4 -> V_6 -> V_162 -> V_204 ( V_4 -> V_9 , V_200 , V_201 ) ;
}
static void F_107 ( struct V_3 * V_4 )
{
int V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
V_4 -> V_6 -> V_148 -> V_205 ( V_4 -> V_9 , V_137 ,
V_4 -> V_17 . V_206 ) ;
V_4 -> V_6 -> V_148 -> V_207 ( V_4 -> V_9 , V_137 ) ;
}
}
static void F_108 ( struct V_3 * V_4 )
{
int V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num)
V_4 -> V_6 -> V_148 -> V_208 ( V_4 -> V_9 , V_137 ) ;
}
static void F_109 ( unsigned long V_107 )
{
struct V_42 * V_96 = (struct V_42 * ) V_107 ;
F_62 ( V_96 ) ;
}
static void F_110 ( struct V_3 * V_4 )
{
T_2 V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_96 = V_4 -> V_93 [ V_137 ] ;
V_96 -> V_209 = V_210 ;
V_96 -> V_211 = V_212 ;
F_11 ( & V_96 -> V_213 , F_109 ,
( unsigned long ) & V_4 -> V_93 [ V_137 ] ) ;
V_96 -> V_213 . V_21 = F_111 ( V_96 -> V_211 ) ;
F_12 ( & V_96 -> V_213 ) ;
}
}
static void F_112 ( struct V_3 * V_4 )
{
T_2 V_137 ;
F_52 (SXGBE_TX_QUEUES, queue_num) {
struct V_42 * V_96 = V_4 -> V_93 [ V_137 ] ;
F_5 ( & V_96 -> V_213 ) ;
}
}
static int F_113 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
int V_16 , V_137 ;
F_114 ( V_4 -> V_28 ) ;
F_102 ( V_4 ) ;
V_16 = F_23 ( V_15 ) ;
if ( V_16 ) {
F_27 ( V_15 , L_18 ,
V_70 , V_16 ) ;
goto V_214;
}
V_4 -> V_81 = F_115 ( V_215 ) ;
V_4 -> V_83 = F_115 ( V_216 ) ;
V_4 -> V_97 = F_115 ( V_217 ) ;
V_4 -> V_151 = V_218 ;
V_4 -> V_153 = V_218 ;
F_51 ( V_15 ) ;
V_16 = F_106 ( V_4 ) ;
if ( V_16 < 0 ) {
F_27 ( V_15 , L_19 , V_70 ) ;
goto V_219;
}
F_107 ( V_4 ) ;
V_4 -> V_6 -> V_7 -> V_220 ( V_4 -> V_9 , V_15 -> V_195 , 0 ) ;
V_4 -> V_6 -> V_7 -> V_221 ( V_4 -> V_9 ) ;
F_52 (SXGBE_RX_QUEUES, queue_num) {
V_4 -> V_6 -> V_7 -> V_222 ( V_4 -> V_9 , V_137 ) ;
}
V_16 = F_116 ( V_4 -> V_106 , V_4 -> V_223 , V_224 ,
V_225 , V_15 -> V_226 , V_15 ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_20 ,
V_70 , V_4 -> V_223 , V_16 ) ;
goto V_219;
}
if ( V_4 -> V_227 != V_15 -> V_223 ) {
V_16 = F_116 ( V_4 -> V_106 , V_4 -> V_227 ,
V_224 ,
V_225 , V_15 -> V_226 , V_15 ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_21 ,
V_70 , V_4 -> V_227 , V_16 ) ;
goto V_219;
}
}
F_52 (SXGBE_TX_QUEUES, queue_num) {
V_16 = F_116 ( V_4 -> V_106 ,
( V_4 -> V_93 [ V_137 ] ) -> V_228 ,
V_229 , 0 ,
V_15 -> V_226 , V_4 -> V_93 [ V_137 ] ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_22 ,
V_70 , V_4 -> V_223 , V_16 ) ;
goto V_219;
}
}
F_52 (SXGBE_RX_QUEUES, queue_num) {
V_16 = F_116 ( V_4 -> V_106 ,
( V_4 -> V_87 [ V_137 ] ) -> V_228 ,
V_230 , 0 ,
V_15 -> V_226 , V_4 -> V_87 [ V_137 ] ) ;
if ( F_2 ( V_16 < 0 ) ) {
F_27 ( V_15 , L_22 ,
V_70 , V_4 -> V_223 , V_16 ) ;
goto V_219;
}
}
V_4 -> V_6 -> V_7 -> V_231 ( V_4 -> V_9 , true ) ;
V_4 -> V_6 -> V_7 -> V_232 ( V_4 -> V_9 , true ) ;
F_59 ( V_4 ) ;
memset ( & V_4 -> V_157 , 0 , sizeof( struct V_233 ) ) ;
V_4 -> V_157 . V_234 = V_4 -> V_151 ;
V_4 -> V_157 . V_235 = V_4 -> V_153 ;
F_24 ( V_15 , L_23 ) ;
V_4 -> V_6 -> V_162 -> V_236 ( V_4 -> V_9 , V_91 ) ;
V_4 -> V_6 -> V_162 -> V_237 ( V_4 -> V_9 , V_84 ) ;
if ( V_15 -> V_19 )
F_117 ( V_15 -> V_19 ) ;
F_110 ( V_4 ) ;
if ( ( V_4 -> V_89 ) && ( V_4 -> V_6 -> V_162 -> V_238 ) ) {
V_4 -> V_239 = V_240 ;
V_4 -> V_6 -> V_162 -> V_238 ( V_4 -> V_9 , V_240 ) ;
}
V_4 -> V_23 = V_2 ;
V_4 -> V_24 = F_9 ( V_4 ) ;
F_118 ( & V_4 -> V_241 ) ;
F_119 ( V_15 ) ;
return 0 ;
V_219:
F_55 ( V_4 ) ;
if ( V_15 -> V_19 )
F_29 ( V_15 -> V_19 ) ;
V_214:
F_120 ( V_4 -> V_28 ) ;
return V_16 ;
}
static int F_121 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
if ( V_4 -> V_24 )
F_5 ( & V_4 -> V_11 ) ;
if ( V_15 -> V_19 ) {
F_122 ( V_15 -> V_19 ) ;
F_29 ( V_15 -> V_19 ) ;
}
F_123 ( V_15 ) ;
F_124 ( & V_4 -> V_241 ) ;
F_112 ( V_4 ) ;
V_4 -> V_6 -> V_162 -> V_242 ( V_4 -> V_9 , V_91 ) ;
V_4 -> V_6 -> V_162 -> V_243 ( V_4 -> V_9 , V_84 ) ;
F_108 ( V_4 ) ;
F_55 ( V_4 ) ;
V_4 -> V_6 -> V_7 -> V_231 ( V_4 -> V_9 , false ) ;
V_4 -> V_6 -> V_7 -> V_232 ( V_4 -> V_9 , false ) ;
F_120 ( V_4 -> V_28 ) ;
return 0 ;
}
static void F_125 ( struct V_3 * V_4 ,
struct V_116 * V_244 ,
struct V_100 * V_101 )
{
unsigned int V_245 , V_246 ;
V_246 = F_126 ( V_101 ) ;
V_245 = F_127 ( V_101 ) + V_246 ;
V_244 -> V_247 = F_33 ( V_4 -> V_106 , V_101 -> V_107 ,
V_245 , V_145 ) ;
if ( F_34 ( V_4 -> V_106 , V_244 -> V_247 ) )
F_61 ( L_24 , V_70 ) ;
V_244 -> V_248 . V_249 . V_244 = 1 ;
V_4 -> V_6 -> V_85 -> V_250 ( V_244 , 1 , V_245 ,
V_246 ,
V_101 -> V_251 - V_245 ) ;
}
static T_3 F_128 ( struct V_100 * V_101 , struct V_13 * V_15 )
{
unsigned int V_159 , V_252 ;
int V_253 = 0 ;
struct V_155 * V_156 ;
unsigned V_254 = F_129 ( V_101 ) ;
struct V_3 * V_4 = F_19 ( V_15 ) ;
unsigned int V_115 = V_4 -> V_81 ;
struct V_42 * V_146 = V_4 -> V_93 [ V_254 ] ;
struct V_116 * V_255 , * V_244 ;
struct V_256 * V_257 = NULL ;
int V_258 = F_130 ( V_101 ) -> V_258 ;
int V_259 = F_131 ( V_101 ) ;
int V_260 = 0 ;
T_4 V_261 = F_130 ( V_101 ) -> V_262 ;
T_1 V_263 = 0 ;
V_156 = F_63 ( V_15 , V_254 ) ;
if ( F_2 ( F_132 ( V_101 ) && V_146 -> V_264 != V_261 ) )
V_263 = 1 ;
if ( F_2 ( F_133 ( V_101 ) ||
( ( F_130 ( V_101 ) -> V_265 & V_266 ) &&
V_146 -> V_267 ) ) )
V_263 = 1 ;
if ( V_4 -> V_5 )
F_4 ( V_4 ) ;
if ( F_2 ( F_17 ( V_146 , V_115 ) < V_258 + 1 ) ) {
if ( ! F_69 ( V_156 ) ) {
F_75 ( V_156 ) ;
F_27 ( V_15 , L_25 ,
V_70 , V_254 ) ;
}
return V_268 ;
}
V_159 = V_146 -> V_46 % V_115 ;
V_255 = V_146 -> V_94 + V_159 ;
V_244 = V_255 ;
if ( V_263 )
V_257 = (struct V_256 * ) V_244 ;
V_146 -> V_121 [ V_159 ] = V_101 ;
if ( ! V_260 ) {
if ( F_60 ( F_132 ( V_101 ) ) ) {
if ( F_2 ( V_146 -> V_264 != V_261 ) ) {
V_4 -> V_6 -> V_85 -> V_269 (
V_257 , V_261 ) ;
V_4 -> V_6 -> V_85 -> V_270 (
V_257 ) ;
V_4 -> V_6 -> V_85 -> V_271 (
V_257 ) ;
V_4 -> V_6 -> V_85 -> V_272 (
V_257 ) ;
V_4 -> V_6 -> V_85 -> V_273 (
V_257 ) ;
V_159 = ( ++ V_146 -> V_46 ) % V_115 ;
V_244 = V_146 -> V_94 + V_159 ;
V_146 -> V_264 = V_261 ;
}
F_125 ( V_4 , V_244 , V_101 ) ;
} else {
V_255 -> V_247 = F_33 ( V_4 -> V_106 ,
V_101 -> V_107 , V_259 , V_145 ) ;
if ( F_34 ( V_4 -> V_106 , V_255 -> V_247 ) )
F_27 ( V_15 , L_24 ,
V_70 ) ;
V_4 -> V_6 -> V_85 -> V_274 ( V_255 , 1 , V_259 ,
V_259 , V_253 ) ;
}
}
for ( V_252 = 0 ; V_252 < V_258 ; V_252 ++ ) {
const T_5 * V_275 = & F_130 ( V_101 ) -> V_276 [ V_252 ] ;
int V_251 = F_134 ( V_275 ) ;
V_159 = ( ++ V_146 -> V_46 ) % V_115 ;
V_255 = V_146 -> V_94 + V_159 ;
V_255 -> V_247 = F_135 ( V_4 -> V_106 , V_275 , 0 , V_251 ,
V_145 ) ;
V_146 -> V_118 [ V_159 ] = V_255 -> V_247 ;
V_146 -> V_121 [ V_159 ] = NULL ;
V_4 -> V_6 -> V_85 -> V_274 ( V_255 , 0 , V_251 ,
V_251 , V_253 ) ;
F_136 () ;
V_4 -> V_6 -> V_85 -> V_277 ( V_255 ) ;
}
V_4 -> V_6 -> V_85 -> V_278 ( V_255 ) ;
F_136 () ;
V_146 -> V_279 += V_258 + 1 ;
if ( V_146 -> V_279 > V_146 -> V_209 ) {
V_4 -> V_6 -> V_85 -> V_280 ( V_255 ) ;
V_4 -> V_157 . V_281 ++ ;
F_7 ( & V_146 -> V_213 ,
F_111 ( V_146 -> V_211 ) ) ;
} else {
V_146 -> V_279 = 0 ;
}
V_4 -> V_6 -> V_85 -> V_277 ( V_244 ) ;
F_136 () ;
V_146 -> V_46 ++ ;
F_48 ( V_4 , V_282 , V_15 , L_26 ,
V_70 , V_146 -> V_46 % V_115 ,
V_146 -> V_45 % V_115 , V_159 ,
V_244 , V_258 ) ;
if ( F_2 ( F_17 ( V_146 , V_115 ) <= ( V_283 + 1 ) ) ) {
F_48 ( V_4 , V_6 , V_15 , L_27 ,
V_70 ) ;
F_75 ( V_156 ) ;
}
V_15 -> V_165 . V_284 += V_101 -> V_251 ;
if ( F_2 ( ( F_130 ( V_101 ) -> V_265 & V_266 ) &&
V_146 -> V_267 ) ) {
F_130 ( V_101 ) -> V_265 |= V_285 ;
V_4 -> V_6 -> V_85 -> V_286 ( V_244 ) ;
}
if ( ! V_146 -> V_267 )
F_137 ( V_101 ) ;
V_4 -> V_6 -> V_162 -> V_287 ( V_4 -> V_9 , V_254 ) ;
return V_288 ;
}
static void F_138 ( struct V_3 * V_4 )
{
unsigned int V_82 = V_4 -> V_83 ;
int V_125 = V_4 -> V_97 ;
T_2 V_289 = V_4 -> V_290 ;
for (; V_4 -> V_87 [ V_289 ] -> V_134 - V_4 -> V_87 [ V_289 ] -> V_135 > 0 ;
V_4 -> V_87 [ V_289 ] -> V_135 ++ ) {
unsigned int V_159 = V_4 -> V_87 [ V_289 ] -> V_135 % V_82 ;
struct V_95 * V_96 ;
V_96 = V_4 -> V_87 [ V_289 ] -> V_88 + V_159 ;
if ( F_60 ( V_4 -> V_87 [ V_289 ] -> V_104 [ V_159 ] == NULL ) ) {
struct V_100 * V_101 ;
V_101 = F_139 ( V_4 -> V_15 , V_125 ) ;
if ( F_2 ( V_101 == NULL ) )
break;
V_4 -> V_87 [ V_289 ] -> V_104 [ V_159 ] = V_101 ;
V_4 -> V_87 [ V_289 ] -> V_105 [ V_159 ] =
F_33 ( V_4 -> V_106 , V_101 -> V_107 , V_125 ,
V_108 ) ;
V_96 -> V_110 . V_111 . V_112 =
V_4 -> V_87 [ V_289 ] -> V_105 [ V_159 ] ;
}
F_136 () ;
V_4 -> V_6 -> V_85 -> V_291 ( V_96 ) ;
V_4 -> V_6 -> V_85 -> V_292 ( V_96 ) ;
F_136 () ;
}
}
static int F_140 ( struct V_3 * V_4 , int V_293 )
{
T_2 V_289 = V_4 -> V_290 ;
unsigned int V_82 = V_4 -> V_83 ;
unsigned int V_159 = V_4 -> V_87 [ V_289 ] -> V_134 ;
unsigned int V_294 = 0 ;
unsigned int V_295 = 0 ;
int V_296 ;
int V_297 ;
while ( V_295 < V_293 ) {
struct V_95 * V_96 ;
struct V_100 * V_101 ;
int V_298 ;
V_96 = V_4 -> V_87 [ V_289 ] -> V_88 + V_159 ;
if ( V_4 -> V_6 -> V_85 -> V_299 ( V_96 ) )
break;
V_295 ++ ;
V_294 = ( ++ V_4 -> V_87 [ V_289 ] -> V_134 ) % V_82 ;
F_141 ( V_4 -> V_87 [ V_289 ] -> V_88 + V_294 ) ;
V_297 = V_4 -> V_6 -> V_85 -> V_300 ( V_96 , & V_4 -> V_157 ,
& V_296 ) ;
if ( F_2 ( V_297 < 0 ) ) {
V_159 = V_294 ;
continue;
}
if ( F_2 ( ! V_4 -> V_301 ) )
V_296 = V_302 ;
V_101 = V_4 -> V_87 [ V_289 ] -> V_104 [ V_159 ] ;
if ( F_2 ( ! V_101 ) )
F_27 ( V_4 -> V_15 , L_28 ) ;
F_141 ( V_101 -> V_107 - V_129 ) ;
V_4 -> V_87 [ V_289 ] -> V_104 [ V_159 ] = NULL ;
V_298 = V_4 -> V_6 -> V_85 -> V_303 ( V_96 ) ;
F_142 ( V_101 , V_298 ) ;
V_101 -> V_304 = V_296 ;
if ( V_296 == V_302 )
F_143 ( V_101 ) ;
else
F_144 ( & V_4 -> V_241 , V_101 ) ;
V_159 = V_294 ;
}
F_138 ( V_4 ) ;
return V_295 ;
}
static int F_145 ( struct V_305 * V_241 , int V_306 )
{
struct V_3 * V_4 = F_146 ( V_241 ,
struct V_3 , V_241 ) ;
int V_307 = 0 ;
T_2 V_289 = V_4 -> V_290 ;
V_4 -> V_157 . V_308 ++ ;
F_73 ( V_4 ) ;
V_307 = F_140 ( V_4 , V_306 ) ;
if ( V_307 < V_306 ) {
F_147 ( V_241 ) ;
V_4 -> V_6 -> V_162 -> V_309 ( V_4 -> V_9 , V_289 ) ;
}
return V_307 ;
}
static void F_148 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
F_76 ( V_4 ) ;
}
static T_6 V_224 ( int V_223 , void * V_310 )
{
struct V_13 * V_311 = (struct V_13 * ) V_310 ;
struct V_3 * V_4 = F_19 ( V_311 ) ;
int V_297 ;
V_297 = V_4 -> V_6 -> V_7 -> V_312 ( V_4 -> V_9 , & V_4 -> V_157 ) ;
if ( V_297 & V_313 ) {
V_4 -> V_157 . V_314 ++ ;
V_4 -> V_5 = true ;
}
if ( V_297 & V_315 ) {
V_4 -> V_157 . V_316 ++ ;
V_4 -> V_5 = false ;
}
if ( V_297 & V_317 )
V_4 -> V_157 . V_318 ++ ;
if ( V_297 & V_319 )
V_4 -> V_157 . V_320 ++ ;
return V_321 ;
}
static T_6 V_229 ( int V_223 , void * V_310 )
{
int V_297 ;
struct V_42 * V_93 = (struct V_42 * ) V_310 ;
struct V_3 * V_4 = V_93 -> V_139 ;
V_297 = V_4 -> V_6 -> V_162 -> V_322 ( V_4 -> V_9 , V_93 -> V_113 ,
& V_4 -> V_157 ) ;
if ( F_60 ( ( V_297 & V_323 ) ) )
F_149 ( & V_4 -> V_241 ) ;
if ( F_2 ( ( V_297 & V_324 ) ) )
F_74 ( V_4 , V_93 -> V_113 ) ;
if ( F_2 ( ( V_297 & V_325 ) &&
( V_4 -> V_151 != V_150 ) &&
( V_4 -> V_151 < 512 ) ) ) {
V_4 -> V_151 += ( V_4 -> V_151 < 128 ) ? 32 : 64 ;
V_4 -> V_6 -> V_148 -> V_149 ( V_4 -> V_9 ,
V_93 -> V_113 , V_4 -> V_151 ) ;
V_4 -> V_157 . V_234 = V_4 -> V_151 ;
}
return V_321 ;
}
static T_6 V_230 ( int V_223 , void * V_310 )
{
int V_297 ;
struct V_98 * V_87 = (struct V_98 * ) V_310 ;
struct V_3 * V_4 = V_87 -> V_139 ;
V_297 = V_4 -> V_6 -> V_162 -> V_326 ( V_4 -> V_9 , V_87 -> V_113 ,
& V_4 -> V_157 ) ;
if ( F_60 ( ( V_297 & V_327 ) && ( F_150 ( & V_4 -> V_241 ) ) ) ) {
V_4 -> V_6 -> V_162 -> V_328 ( V_4 -> V_9 , V_87 -> V_113 ) ;
F_151 ( & V_4 -> V_241 ) ;
}
if ( F_2 ( ( V_297 & V_329 ) &&
( V_4 -> V_153 != V_150 ) &&
( V_4 -> V_153 < 128 ) ) ) {
V_4 -> V_153 += 32 ;
V_4 -> V_6 -> V_148 -> V_152 ( V_4 -> V_9 ,
V_87 -> V_113 , V_4 -> V_153 ) ;
V_4 -> V_157 . V_235 = V_4 -> V_153 ;
}
return V_321 ;
}
static inline T_7 F_152 ( void V_197 * V_9 , int V_330 , int V_331 )
{
T_7 V_332 = F_153 ( V_9 + V_330 ) ;
V_332 |= ( ( T_7 ) F_153 ( V_9 + V_331 ) ) << 32 ;
return V_332 ;
}
static struct V_333 * F_154 ( struct V_13 * V_15 ,
struct V_333 * V_165 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
void V_197 * V_9 = V_4 -> V_9 ;
T_7 V_295 ;
F_155 ( & V_4 -> V_334 ) ;
F_156 ( V_335 , V_9 + V_336 ) ;
V_165 -> V_337 = F_152 ( V_9 ,
V_338 ,
V_339 ) ;
V_165 -> V_340 = F_152 ( V_9 ,
V_341 ,
V_342 ) ;
V_165 -> V_343 = F_152 ( V_9 ,
V_344 ,
V_345 ) ;
V_165 -> V_346 = F_152 ( V_9 ,
V_347 ,
V_348 ) ;
V_165 -> V_349 = F_152 ( V_9 ,
V_350 ,
V_351 ) ;
V_165 -> V_352 = F_152 ( V_9 ,
V_353 ,
V_354 ) ;
V_165 -> V_284 = F_152 ( V_9 ,
V_355 ,
V_356 ) ;
V_295 = F_152 ( V_9 , V_357 ,
V_358 ) ;
V_165 -> V_166 = F_152 ( V_9 , V_359 ,
V_360 ) ;
V_165 -> V_166 = V_295 - V_165 -> V_166 ;
V_165 -> V_361 = V_295 ;
V_165 -> V_362 = F_152 ( V_9 , V_363 ,
V_364 ) ;
F_156 ( 0 , V_9 + V_336 ) ;
F_157 ( & V_4 -> V_334 ) ;
return V_165 ;
}
static int F_158 ( struct V_13 * V_15 ,
T_8 V_169 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
T_8 V_365 = V_15 -> V_169 ^ V_169 ;
if ( V_365 & V_366 ) {
if ( V_169 & V_366 ) {
V_4 -> V_6 -> V_7 -> V_367 ( V_4 -> V_9 ) ;
V_4 -> V_301 = true ;
} else {
V_4 -> V_6 -> V_7 -> V_368 ( V_4 -> V_9 ) ;
V_4 -> V_301 = false ;
}
}
return 0 ;
}
static int F_159 ( struct V_13 * V_15 , int V_369 )
{
V_15 -> V_126 = V_369 ;
if ( ! F_160 ( V_15 ) )
return 0 ;
F_121 ( V_15 ) ;
return F_113 ( V_15 ) ;
}
static void F_161 ( void V_197 * V_9 , unsigned char * V_370 ,
unsigned int V_371 )
{
unsigned long V_107 ;
V_107 = ( V_370 [ 5 ] << 8 ) | V_370 [ 4 ] ;
F_156 ( V_107 | V_372 , V_9 + F_162 ( V_371 ) ) ;
V_107 = ( V_370 [ 3 ] << 24 ) | ( V_370 [ 2 ] << 16 ) | ( V_370 [ 1 ] << 8 ) | V_370 [ 0 ] ;
F_156 ( V_107 , V_9 + F_163 ( V_371 ) ) ;
}
static void F_164 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
void V_197 * V_9 = ( void V_197 * ) V_4 -> V_9 ;
unsigned int V_373 = 0 ;
T_1 V_374 [ 2 ] ;
struct V_375 * V_376 ;
int V_377 = 1 ;
F_24 ( V_15 , L_29 ,
V_70 , F_165 ( V_15 ) , F_166 ( V_15 ) ) ;
if ( V_15 -> V_378 & V_379 ) {
V_373 = V_380 ;
} else if ( ( F_165 ( V_15 ) > V_381 ) ||
( V_15 -> V_378 & V_382 ) ) {
V_373 = V_383 ;
F_156 ( 0xffffffff , V_9 + V_384 ) ;
F_156 ( 0xffffffff , V_9 + V_385 ) ;
} else if ( ! F_167 ( V_15 ) ) {
V_373 = V_386 ;
memset ( V_374 , 0 , sizeof( V_374 ) ) ;
F_168 (ha, dev) {
int V_387 = F_169 ( ~ F_170 ( ~ 0 , V_376 -> V_370 , 6 ) ) >> 26 ;
V_374 [ V_387 >> 5 ] |= 1 << ( V_387 & 31 ) ;
}
F_156 ( V_374 [ 0 ] , V_9 + V_385 ) ;
F_156 ( V_374 [ 1 ] , V_9 + V_384 ) ;
}
if ( F_166 ( V_15 ) > V_388 )
V_373 |= V_380 ;
else {
F_171 (ha, dev) {
F_161 ( V_9 , V_376 -> V_370 , V_377 ) ;
V_377 ++ ;
}
}
#ifdef F_172
V_373 |= V_389 ;
#endif
F_156 ( V_373 , V_9 + V_390 ) ;
F_24 ( V_15 , L_30 ,
F_153 ( V_9 + V_390 ) ,
F_153 ( V_9 + V_384 ) ,
F_153 ( V_9 + V_385 ) ) ;
}
static void F_173 ( struct V_13 * V_15 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
F_174 ( V_4 -> V_223 ) ;
V_230 ( V_4 -> V_223 , V_15 ) ;
F_175 ( V_4 -> V_223 ) ;
}
static int F_176 ( struct V_13 * V_15 , struct V_391 * V_392 , int V_393 )
{
int V_16 = - V_394 ;
if ( ! F_160 ( V_15 ) )
return - V_109 ;
switch ( V_393 ) {
case V_395 :
case V_396 :
case V_397 :
if ( ! V_15 -> V_19 )
return - V_109 ;
V_16 = F_177 ( V_15 -> V_19 , V_392 , V_393 ) ;
break;
default:
break;
}
return V_16 ;
}
static void F_178 ( struct V_398 * const V_399 )
{
V_399 -> V_7 = F_179 () ;
V_399 -> V_85 = F_180 () ;
V_399 -> V_162 = F_181 () ;
V_399 -> V_148 = F_182 () ;
V_399 -> V_400 . V_370 = V_401 ;
V_399 -> V_400 . V_107 = V_402 ;
V_399 -> V_26 . V_403 = 0 ;
V_399 -> V_26 . V_404 = 0 ;
V_399 -> V_26 . V_49 = V_51 ;
}
static int F_183 ( struct V_3 * const V_4 )
{
T_1 V_405 ;
V_4 -> V_6 = F_184 ( sizeof( * V_4 -> V_6 ) , V_102 ) ;
if( ! V_4 -> V_6 )
return - V_103 ;
F_178 ( V_4 -> V_6 ) ;
V_405 = V_4 -> V_6 -> V_7 -> V_406 ( V_4 -> V_9 ) ;
V_4 -> V_6 -> V_407 = ( V_405 & 0x00ff0000 ) >> 16 ;
V_4 -> V_6 -> V_408 = ( V_405 & 0x000000ff ) ;
F_13 ( L_31 ,
V_4 -> V_6 -> V_407 , V_4 -> V_6 -> V_408 ) ;
if ( ! F_77 ( V_4 ) )
F_13 ( L_32 ) ;
if ( V_4 -> V_17 . V_174 )
F_13 ( L_33 ) ;
if ( V_4 -> V_17 . V_175 )
F_13 ( L_34 ) ;
return 0 ;
}
static int F_185 ( void V_197 * V_370 )
{
int V_409 = 10 ;
F_156 ( V_410 , V_370 + V_411 ) ;
while ( V_409 -- ) {
if ( ! ( F_153 ( V_370 + V_411 ) &
V_410 ) )
break;
F_186 ( 10 ) ;
}
if ( V_409 < 0 )
return - V_412 ;
return 0 ;
}
struct V_3 * F_187 ( struct V_106 * V_106 ,
struct V_413 * V_414 ,
void V_197 * V_370 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_16 ;
T_2 V_137 ;
V_14 = F_188 ( sizeof( struct V_3 ) ,
V_91 , V_84 ) ;
if ( ! V_14 )
return NULL ;
F_189 ( V_14 , V_106 ) ;
V_4 = F_19 ( V_14 ) ;
V_4 -> V_106 = V_106 ;
V_4 -> V_15 = V_14 ;
F_190 ( V_14 ) ;
V_4 -> V_63 = V_414 ;
V_4 -> V_9 = V_370 ;
V_16 = F_185 ( V_4 -> V_9 ) ;
if ( V_16 )
goto V_415;
F_1 () ;
V_16 = F_183 ( V_4 ) ;
if ( V_16 )
goto V_415;
V_16 = F_56 ( V_4 ) ;
if ( V_16 )
goto V_416;
V_16 = F_58 ( V_4 ) ;
if ( V_16 )
goto V_416;
V_14 -> V_417 = & V_418 ;
V_14 -> V_419 = V_420 | V_421 | V_422 |
V_366 | V_423 | V_424 |
V_425 ;
V_14 -> V_169 |= V_14 -> V_419 | V_426 ;
V_14 -> V_427 = F_191 ( V_428 ) ;
V_14 -> V_429 |= V_430 ;
V_14 -> V_431 = V_432 ;
V_14 -> V_433 = V_434 ;
V_4 -> V_435 = F_192 ( V_436 , V_437 ) ;
if ( V_4 -> V_17 . V_184 ) {
F_52 (SXGBE_TX_QUEUES, queue_num) {
V_4 -> V_6 -> V_162 -> V_438 ( V_4 -> V_9 , V_137 ) ;
}
}
if ( V_4 -> V_17 . V_175 ) {
V_4 -> V_6 -> V_7 -> V_367 ( V_4 -> V_9 ) ;
V_4 -> V_301 = true ;
}
V_4 -> V_439 = 1 ;
V_4 -> V_440 = 1 ;
if ( ! V_4 -> V_63 -> V_441 ) {
V_4 -> V_89 = 1 ;
F_13 ( L_35 ) ;
}
F_193 ( V_14 , & V_4 -> V_241 , F_145 , 64 ) ;
F_194 ( & V_4 -> V_334 ) ;
V_4 -> V_28 = F_195 ( V_4 -> V_106 , V_442 ) ;
if ( F_26 ( V_4 -> V_28 ) ) {
F_196 ( V_14 , L_36 ,
V_70 ) ;
goto V_443;
}
if ( ! V_4 -> V_63 -> V_30 )
F_15 ( V_4 ) ;
else
V_4 -> V_30 = V_4 -> V_63 -> V_30 ;
V_16 = F_197 ( V_14 ) ;
if ( V_16 < 0 ) {
F_24 ( V_14 , L_37 ,
V_70 , V_4 -> V_63 -> V_61 ) ;
goto V_444;
}
V_16 = F_198 ( V_14 ) ;
if ( V_16 ) {
F_61 ( L_38 , V_70 , V_16 ) ;
goto V_445;
}
F_102 ( V_4 ) ;
return V_4 ;
V_445:
F_199 ( V_14 ) ;
V_444:
F_200 ( V_4 -> V_28 ) ;
V_443:
F_201 ( & V_4 -> V_241 ) ;
V_416:
F_45 ( V_4 -> V_6 ) ;
V_415:
F_202 ( V_14 ) ;
return NULL ;
}
int F_203 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_19 ( V_14 ) ;
T_2 V_137 ;
F_204 ( V_14 , L_39 , V_70 ) ;
F_52 (SXGBE_RX_QUEUES, queue_num) {
V_4 -> V_6 -> V_7 -> V_446 ( V_4 -> V_9 , V_137 ) ;
}
V_4 -> V_6 -> V_162 -> V_243 ( V_4 -> V_9 , V_84 ) ;
V_4 -> V_6 -> V_162 -> V_242 ( V_4 -> V_9 , V_91 ) ;
V_4 -> V_6 -> V_7 -> V_231 ( V_4 -> V_9 , false ) ;
V_4 -> V_6 -> V_7 -> V_232 ( V_4 -> V_9 , false ) ;
F_205 ( V_14 ) ;
F_199 ( V_14 ) ;
F_200 ( V_4 -> V_28 ) ;
F_201 ( & V_4 -> V_241 ) ;
F_45 ( V_4 -> V_6 ) ;
F_202 ( V_14 ) ;
return 0 ;
}
int F_206 ( struct V_13 * V_14 )
{
return 0 ;
}
int F_207 ( struct V_13 * V_14 )
{
return 0 ;
}
int F_208 ( struct V_13 * V_14 )
{
return - V_447 ;
}
int F_209 ( struct V_13 * V_14 )
{
return - V_447 ;
}
static int T_9 F_210 ( void )
{
int V_16 ;
V_16 = F_211 () ;
if ( V_16 )
goto V_448;
return 0 ;
V_448:
F_61 ( L_40 ) ;
return V_16 ;
}
static void T_10 F_212 ( void )
{
F_213 () ;
}
static int T_9 F_214 ( char * V_449 )
{
char * V_450 ;
if ( ! V_449 || ! * V_449 )
return - V_109 ;
while ( ( V_450 = F_215 ( & V_449 , L_41 ) ) != NULL ) {
if ( ! strncmp ( V_450 , L_42 , 6 ) ) {
if ( F_216 ( V_450 + 10 , 0 , & V_1 ) )
goto V_448;
}
}
return 0 ;
V_448:
F_61 ( L_43 , V_70 ) ;
return - V_109 ;
}
