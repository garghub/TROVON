static void F_1 ( T_1 * time )
{
struct V_1 V_2 ;
F_2 ( & V_2 ) ;
* time = F_3 ( V_2 . V_3 ) ;
}
static struct V_4 * F_4 ( struct V_5 * V_6 )
{
struct V_4 * V_7 = V_6 -> V_8 + V_6 -> V_9 ;
++ V_6 -> V_9 ;
V_6 -> V_9 %= V_6 -> V_10 + 1 ;
return V_7 ;
}
static void F_5 ( struct V_11 * V_12 ,
void (* F_6)( struct V_11 * ) )
{
V_12 -> V_13 = ( V_14 << 24 ) | V_15 ;
F_7 ( 0 , V_12 -> V_16 , V_17 , 0x24 ,
0x0 ) ;
F_6 ( V_12 ) ;
}
static struct V_18 * F_8 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 + V_6 -> V_21 * V_6 -> V_22 ;
++ V_6 -> V_21 ;
V_6 -> V_21 %= V_6 -> V_23 + 1 ;
return V_19 ;
}
static struct V_18 * F_9 ( struct V_5 * V_6 )
{
return (struct V_18 * ) ( V_6 -> V_20 +
V_6 -> V_21 * V_6 -> V_22 + sizeof( struct V_24 ) ) ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_18 * V_19 , struct V_25 * V_26 )
{
struct V_11 * V_12 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_33 , V_34 ;
V_12 = V_26 -> V_12 ;
V_34 = F_11 ( V_12 ) ;
F_12 ( V_34 < 0 ) ;
if ( V_34 ) {
V_30 = (struct V_29 * ) V_19 -> V_35 ;
V_26 -> V_36 = V_34 ;
V_30 -> V_36 = F_13 ( ( V_37 ) V_34 ) ;
V_30 -> V_38 = F_13 ( V_6 -> V_39 -> V_40 ) ;
V_30 -> V_41 = F_14 ( F_15 ( V_12 ) ) ;
V_32 = (struct V_31 * ) ( V_30 + 1 ) ;
F_16 (cmd, sg, nseg, i) {
V_32 [ V_33 ] . V_42 = F_14 ( ( V_43 ) F_17 ( V_28 ) ) ;
V_32 [ V_33 ] . V_44 = F_3 ( F_18 ( V_28 ) ) ;
V_32 [ V_33 ] . V_45 = V_46 | V_47 ;
}
V_32 [ -- V_33 ] . V_45 |= V_48 ;
}
return V_34 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_18 * V_19 , struct V_25 * V_26 )
{
struct V_11 * V_12 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_49 * V_32 ;
int V_33 , V_34 ;
V_12 = V_26 -> V_12 ;
V_34 = F_11 ( V_12 ) ;
F_12 ( V_34 < 0 ) ;
if ( V_34 ) {
V_30 = (struct V_29 * ) V_19 -> V_35 ;
V_26 -> V_36 = V_34 ;
V_30 -> V_36 = F_13 ( ( V_37 ) V_34 ) ;
V_30 -> V_38 = F_13 ( V_6 -> V_39 -> V_40 ) ;
V_30 -> V_41 = F_14 ( F_15 ( V_12 ) ) ;
V_32 = (struct V_49 * ) ( V_30 + 1 ) ;
F_16 (cmd, sg, nseg, i) {
V_32 [ V_33 ] . V_42 = F_14 ( ( V_43 ) F_17 ( V_28 ) ) ;
V_32 [ V_33 ] . V_44 =
F_14 ( F_18 ( V_28 ) & 0xffffffff ) ;
V_32 [ V_33 ] . V_50 =
F_14 ( ( F_18 ( V_28 ) >> 16 ) >> 16 ) ;
}
}
return V_34 ;
}
static void F_20 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
struct V_51 * V_52 ;
T_2 V_42 = sizeof( struct V_51 ) ;
V_52 = V_6 -> V_53 ;
F_21 ( V_26 -> V_12 , V_52 , V_42 ) ;
memset ( V_52 -> V_54 , 0 , sizeof( V_43 ) * 6 ) ;
* ( unsigned long * ) ( V_52 -> V_54 ) = F_22 ( V_6 -> V_55 , 0 ) ;
V_52 -> V_56 = 0 ;
V_52 -> V_57 . V_58 = V_59 ;
V_52 -> V_57 . V_60 = V_61 ;
V_52 -> V_57 . V_62 = V_63 ;
V_52 -> V_57 . V_64 = V_65 ;
V_52 -> V_66 = V_6 -> V_55 -> V_66 -> V_67 ;
V_52 -> V_68 = V_6 -> V_55 -> V_69 ;
V_52 -> V_70 = 0 ;
V_52 -> V_71 = V_6 -> V_55 -> V_72 ;
V_52 -> V_73 = V_6 -> V_55 -> V_74 << 16 | V_6 -> V_55 -> V_75 ;
V_52 -> V_76 =
V_6 -> V_55 -> V_77 << 16 | V_6 -> V_55 -> V_78 ;
F_23 ( V_26 -> V_12 , V_52 , V_42 ) ;
}
static void
F_24 ( struct V_5 * V_6 , struct V_18 * V_19 , V_37 V_79 )
{
V_19 -> V_79 = F_13 ( V_79 ) ;
V_6 -> V_26 [ V_79 ] . V_19 = V_19 ;
V_6 -> V_80 ++ ;
F_25 ( V_6 -> V_21 , V_6 -> V_81 + V_82 ) ;
F_25 ( V_83 , V_6 -> V_81 + V_84 ) ;
F_26 ( V_6 -> V_81 + V_84 ) ;
}
static void
F_27 ( struct V_5 * V_6 , struct V_18 * V_19 , V_37 V_79 )
{
struct V_11 * V_12 ;
struct V_24 * V_85 ;
T_3 V_44 ;
V_19 -> V_79 = F_13 ( V_79 ) ;
V_6 -> V_26 [ V_79 ] . V_19 = V_19 ;
V_6 -> V_80 ++ ;
V_12 = V_6 -> V_26 [ V_79 ] . V_12 ;
V_85 = (struct V_24 * ) V_19 - 1 ;
if ( F_28 ( V_12 ) ) {
V_85 -> V_86 = ( V_87 ) V_12 -> V_75 -> V_86 ;
V_85 -> V_88 = F_13 ( V_12 -> V_89 -> V_88 / V_90 ) ;
}
V_44 = V_6 -> V_91 + V_6 -> V_21 * V_6 -> V_22 ;
V_44 += ( V_6 -> V_26 [ V_79 ] . V_36 + 4 ) / 11 ;
V_85 -> V_92 = F_3 ( V_44 ) ;
++ V_6 -> V_21 ;
V_6 -> V_21 %= V_6 -> V_23 + 1 ;
F_25 ( ( V_44 >> 16 ) >> 16 , V_6 -> V_81 + V_93 ) ;
F_26 ( V_6 -> V_81 + V_93 ) ;
F_25 ( V_44 , V_6 -> V_81 + V_94 ) ;
F_26 ( V_6 -> V_81 + V_94 ) ;
}
static int
F_29 ( struct V_95 * V_96 )
{
V_96 -> V_97 = 1 ;
F_30 ( V_96 , V_96 -> V_39 -> V_98 ) ;
return 0 ;
}
static int
F_31 ( struct V_95 * V_96 )
{
V_96 -> V_99 = 1 ;
V_96 -> V_100 = 1 ;
F_32 ( V_96 -> V_101 , 60 * V_90 ) ;
V_96 -> V_97 = 1 ;
return 0 ;
}
static void
F_33 ( struct V_95 * V_96 )
{
F_34 ( V_96 , 1 ) ;
}
static int
F_35 ( struct V_11 * V_12 , void (* F_6)( struct V_11 * ) )
{
struct V_5 * V_6 ;
struct V_102 * V_39 ;
unsigned int V_73 , V_103 ;
struct V_18 * V_19 ;
V_37 V_79 ;
V_39 = V_12 -> V_75 -> V_39 ;
V_73 = V_12 -> V_75 -> V_73 ;
V_103 = V_12 -> V_75 -> V_103 ;
V_6 = (struct V_5 * ) & V_39 -> V_104 [ 0 ] ;
if ( F_36 ( V_6 -> V_105 == V_106 ) )
return V_107 ;
switch ( V_12 -> V_108 [ 0 ] ) {
case V_109 :
{
static char V_110 [ 12 ] =
{ 0 , 0x12 , 0 , 0 , 0 , 0 , 0 , 0 , 0x8 , 0xa , 0x4 , 0 } ;
unsigned char V_111 ;
V_111 = V_12 -> V_108 [ 2 ] & 0x3f ;
if ( V_111 == 0x8 || V_111 == 0x3f ) {
F_23 ( V_12 , V_110 ,
sizeof( V_110 ) ) ;
V_12 -> V_13 = V_112 << 16 | V_113 << 8 ;
F_6 ( V_12 ) ;
} else
F_5 ( V_12 , F_6 ) ;
return 0 ;
}
case V_114 :
if ( V_6 -> V_115 == V_116 || V_73 == V_39 -> V_117 - 1 ) {
F_5 ( V_12 , F_6 ) ;
return 0 ;
}
break;
case V_118 :
if ( V_73 == V_39 -> V_117 - 1 ) {
V_12 -> V_13 = V_112 << 16 | V_113 << 8 ;
F_6 ( V_12 ) ;
return 0 ;
}
break;
case V_119 :
if ( V_103 >= V_39 -> V_120 ) {
V_12 -> V_13 = V_121 << 16 ;
F_6 ( V_12 ) ;
return 0 ;
}
if ( V_73 != V_39 -> V_117 - 1 )
break;
if ( ! V_103 && ! V_12 -> V_75 -> V_86 &&
( V_12 -> V_108 [ 1 ] & V_122 ) == 0 ) {
F_23 ( V_12 , ( void * ) V_123 ,
sizeof( V_123 ) ) ;
V_12 -> V_13 = V_112 << 16 | V_113 << 8 ;
F_6 ( V_12 ) ;
} else
F_5 ( V_12 , F_6 ) ;
return 0 ;
case V_124 :
if ( V_12 -> V_108 [ 1 ] == V_125 ) {
struct V_126 V_127 ;
T_2 V_128 = sizeof( V_127 ) ;
V_127 . V_58 = V_59 ;
V_127 . V_60 = V_61 ;
V_127 . V_62 = V_63 ;
V_127 . V_64 = V_65 ;
V_127 . V_129 [ 0 ] = V_130 ;
V_127 . V_131 = V_39 -> V_117 - 1 ;
V_127 . V_132 = V_6 -> V_39 -> V_132 ;
V_128 = F_23 ( V_12 , & V_127 , V_128 ) ;
V_12 -> V_13 = sizeof( V_127 ) == V_128 ?
V_112 << 16 | V_113 << 8 :
V_133 << 16 | V_113 << 8 ;
F_6 ( V_12 ) ;
return 0 ;
}
default:
break;
}
V_12 -> V_134 = F_6 ;
V_79 = V_12 -> V_89 -> V_79 ;
if ( F_36 ( V_79 >= V_39 -> V_98 ) )
return V_107 ;
V_19 = V_6 -> V_135 ( V_6 ) ;
V_19 -> V_103 = V_103 ;
V_19 -> V_136 = V_73 ;
memcpy ( V_19 -> V_137 , V_12 -> V_108 , V_138 ) ;
if ( V_12 -> V_139 == V_140 )
V_19 -> V_141 = V_142 ;
else if ( V_12 -> V_139 == V_143 )
V_19 -> V_141 = V_144 ;
else
V_19 -> V_141 = V_145 ;
V_6 -> V_26 [ V_79 ] . V_12 = V_12 ;
V_6 -> V_26 [ V_79 ] . V_146 = V_147 ;
V_6 -> V_26 [ V_79 ] . V_16 = V_12 -> V_16 ;
if ( ! V_6 -> V_148 ( V_6 , V_19 , & V_6 -> V_26 [ V_79 ] ) ) {
V_6 -> V_26 [ V_79 ] . V_36 = 0 ;
memset ( & V_19 -> V_35 [ 0 ] , 0 , 8 ) ;
}
V_6 -> V_149 ( V_6 , V_19 , V_79 ) ;
return 0 ;
}
void F_37 ( struct V_25 * V_26 ,
struct V_4 * V_150 , unsigned int V_35 )
{
if ( V_150 -> V_151 != V_152 ) {
if ( V_26 -> V_16 != NULL )
memcpy ( V_26 -> V_16 , V_150 -> V_35 ,
F_38 ( V_35 , V_26 -> V_146 ) ) ;
return;
}
if ( V_26 -> V_12 == NULL )
return;
F_23 ( V_26 -> V_12 , V_150 -> V_35 , V_35 ) ;
}
static void F_39 ( struct V_5 * V_6 ,
struct V_25 * V_26 , struct V_4 * V_150 )
{
if ( V_26 -> V_12 -> V_108 [ 0 ] == V_153 &&
V_150 -> V_151 != V_15 )
F_40 ( V_26 -> V_12 , F_15 ( V_26 -> V_12 ) -
F_41 ( * ( V_154 * ) & V_150 -> V_35 [ 0 ] ) ) ;
}
static void F_42 ( struct V_5 * V_6 , V_43 V_155 )
{
void T_4 * V_54 = V_6 -> V_81 ;
struct V_4 * V_150 ;
struct V_25 * V_26 ;
unsigned int V_156 ;
V_37 V_79 ;
if ( F_36 ( ! ( V_155 & V_157 ) ) )
return;
V_6 -> V_158 = F_26 ( V_54 + V_159 ) ;
if ( F_36 ( V_6 -> V_158 > V_6 -> V_10 ) ) {
F_43 (KERN_WARNING DRV_NAME L_1 ,
pci_name(hba->pdev)) ;
return;
}
if ( F_36 ( V_6 -> V_80 <= 0 ||
( V_6 -> V_105 == V_106 &&
V_6 -> V_115 != V_160 ) ) ) {
V_6 -> V_9 = V_6 -> V_158 ;
goto V_161;
}
while ( V_6 -> V_9 != V_6 -> V_158 ) {
V_150 = F_4 ( V_6 ) ;
V_79 = F_44 ( V_150 -> V_79 ) ;
if ( F_36 ( V_79 >= V_6 -> V_39 -> V_98 ) ) {
F_43 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_6 -> V_80 -- ;
V_26 = & V_6 -> V_26 [ V_79 ] ;
if ( F_36 ( V_6 -> V_162 == V_26 ) )
V_6 -> V_162 = NULL ;
if ( F_36 ( V_26 -> V_19 == NULL ) ) {
F_43 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_156 = V_150 -> V_163 * sizeof( V_43 ) ;
if ( F_36 ( V_156 < sizeof( * V_150 ) - V_164 ||
V_156 > sizeof( * V_150 ) ) ) {
F_43 (KERN_WARNING DRV_NAME L_4 ,
pci_name(hba->pdev)) ;
} else {
V_156 -= sizeof( * V_150 ) - V_164 ;
if ( V_156 )
F_37 ( V_26 , V_150 , V_156 ) ;
}
V_26 -> V_19 = NULL ;
V_26 -> V_165 = V_150 -> V_165 ;
V_26 -> V_151 = V_150 -> V_151 ;
if ( F_28 ( V_26 -> V_12 != NULL ) ) {
if ( V_6 -> V_115 == V_160 )
F_39 ( V_6 , V_26 , V_150 ) ;
if ( F_36 ( V_26 -> V_12 -> V_108 [ 0 ] == V_124 &&
V_26 -> V_12 -> V_108 [ 1 ] == V_166 ) )
F_20 ( V_6 , V_26 ) ;
F_45 ( V_26 -> V_12 ) ;
F_46 ( V_26 ) ;
} else
V_26 -> V_167 = 0 ;
}
V_161:
F_25 ( V_6 -> V_158 , V_54 + V_168 ) ;
F_26 ( V_54 + V_168 ) ;
}
static T_5 F_47 ( int V_72 , void * V_169 )
{
struct V_5 * V_6 = V_169 ;
void T_4 * V_54 = V_6 -> V_81 ;
V_43 V_170 ;
unsigned long V_171 ;
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
V_170 = F_26 ( V_54 + V_173 ) ;
if ( V_170 && V_170 != 0xffffffff ) {
F_25 ( V_170 , V_54 + V_173 ) ;
F_26 ( V_54 + V_173 ) ;
F_42 ( V_6 , V_170 ) ;
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
if ( F_36 ( V_170 & V_174 &&
V_6 -> V_115 == V_116 ) )
F_50 ( V_6 -> V_175 , & V_6 -> V_176 ) ;
return V_177 ;
}
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
return V_178 ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_4 * V_150 ;
struct V_25 * V_26 ;
V_154 * V_179 ;
unsigned int V_156 ;
int V_42 = 0 ;
V_43 V_180 ;
V_37 V_79 ;
if ( F_36 ( V_6 -> V_80 <= 0 ||
V_6 -> V_105 == V_106 ) )
return;
while ( V_42 < V_6 -> V_10 ) {
V_179 = V_6 -> V_179 + V_6 -> V_9 ;
V_180 = F_41 ( * V_179 ) ;
if ( F_36 ( ! ( V_180 & V_181 ) ) )
return;
V_150 = V_6 -> V_8 + V_6 -> V_9 ;
* V_179 = 0 ;
++ V_42 ;
++ V_6 -> V_9 ;
V_6 -> V_9 %= V_6 -> V_10 + 1 ;
V_79 = ( V_37 ) V_180 ;
if ( F_36 ( V_79 >= V_6 -> V_39 -> V_98 ) ) {
F_43 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_6 -> V_80 -- ;
V_26 = & V_6 -> V_26 [ V_79 ] ;
if ( F_36 ( V_6 -> V_162 == V_26 ) )
V_6 -> V_162 = NULL ;
if ( F_36 ( V_26 -> V_19 == NULL ) ) {
F_43 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_26 -> V_19 = NULL ;
if ( F_28 ( V_180 & V_182 ) ) {
V_26 -> V_165 = V_183 ;
V_26 -> V_151 = V_152 ;
} else {
V_26 -> V_165 = V_150 -> V_165 ;
V_26 -> V_151 = V_150 -> V_151 ;
V_156 = V_150 -> V_163 * sizeof( V_43 ) ;
if ( F_36 ( V_156 < sizeof( * V_150 ) - V_164 ||
V_156 > sizeof( * V_150 ) ) ) {
F_43 (KERN_WARNING DRV_NAME
L_4 ,
pci_name(hba->pdev)) ;
} else {
V_156 -= sizeof( * V_150 ) - V_164 ;
if ( V_156 )
F_37 ( V_26 , V_150 , V_156 ) ;
}
if ( F_28 ( V_26 -> V_12 != NULL ) )
F_39 ( V_6 , V_26 , V_150 ) ;
}
if ( F_28 ( V_26 -> V_12 != NULL ) ) {
F_45 ( V_26 -> V_12 ) ;
F_46 ( V_26 ) ;
} else
V_26 -> V_167 = 0 ;
}
}
static T_5 F_52 ( int V_72 , void * V_169 )
{
struct V_5 * V_6 = V_169 ;
void T_4 * V_54 = V_6 -> V_81 ;
V_43 V_170 ;
unsigned long V_171 ;
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
V_170 = F_26 ( V_54 + V_184 ) ;
if ( V_170 && V_170 != 0xffffffff ) {
F_25 ( V_170 , V_54 + V_185 ) ;
F_51 ( V_6 ) ;
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
if ( F_36 ( V_170 & V_186 ) )
F_50 ( V_6 -> V_175 , & V_6 -> V_176 ) ;
return V_177 ;
}
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
return V_178 ;
}
static int F_53 ( struct V_5 * V_6 )
{
void T_4 * V_54 = V_6 -> V_81 ;
struct V_187 * V_188 ;
T_3 V_189 ;
V_43 V_170 ;
unsigned long V_190 ;
if ( F_26 ( V_54 + V_191 ) != V_192 ) {
F_25 ( V_193 , V_54 + V_84 ) ;
F_26 ( V_54 + V_84 ) ;
V_190 = V_194 ;
while ( F_26 ( V_54 + V_191 ) != V_192 ) {
if ( F_54 ( V_194 , V_190 + V_195 * V_90 ) ) {
F_43 (KERN_ERR DRV_NAME
L_5 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_55 () ;
F_56 ( 1 ) ;
}
}
F_57 ( 10 ) ;
V_170 = F_26 ( V_54 + V_159 ) ;
if ( ( V_170 & 0xffff0000 ) == V_196 ) {
V_170 &= 0x0000ffff ;
if ( V_6 -> V_39 -> V_98 > V_170 ) {
V_6 -> V_39 -> V_98 = V_170 ;
V_6 -> V_39 -> V_197 = V_170 ;
}
}
V_188 = (struct V_187 * ) V_6 -> V_8 ;
V_188 -> V_198 = F_3 ( V_6 -> V_91 ) ;
V_188 -> V_199 = F_13 ( V_6 -> V_22 ) ;
V_188 -> V_200 = F_13 ( V_6 -> V_23 + 1 ) ;
V_188 -> V_201 = F_13 ( sizeof( struct V_4 ) ) ;
V_188 -> V_202 = F_13 ( V_6 -> V_10 + 1 ) ;
F_1 ( & V_188 -> V_203 ) ;
V_188 -> V_204 = V_205 ;
if ( V_6 -> V_206 ) {
V_188 -> V_206 = F_14 ( V_6 -> V_206 ) ;
V_188 -> V_207 = F_14 ( V_6 -> V_208 - V_6 -> V_206 ) ;
} else
V_188 -> V_206 = V_188 -> V_207 = 0 ;
V_189 = V_6 -> V_91 + ( V_6 -> V_23 + 1 ) * V_6 -> V_22 ;
F_25 ( V_189 , V_54 + V_82 ) ;
F_26 ( V_54 + V_82 ) ;
F_25 ( ( V_189 >> 16 ) >> 16 , V_54 + V_168 ) ;
F_26 ( V_54 + V_168 ) ;
F_25 ( ( V_189 >> 16 ) >> 16 , V_54 + V_191 ) ;
F_26 ( V_54 + V_191 ) ;
F_25 ( V_193 , V_54 + V_84 ) ;
F_26 ( V_54 + V_84 ) ;
F_57 ( 10 ) ;
V_190 = V_194 ;
while ( F_26 ( V_54 + V_191 ) != V_192 ) {
if ( F_54 ( V_194 , V_190 + V_195 * V_90 ) ) {
F_43 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_55 () ;
F_56 ( 1 ) ;
}
F_25 ( 0 , V_54 + V_82 ) ;
F_26 ( V_54 + V_82 ) ;
F_25 ( 0 , V_54 + V_191 ) ;
F_26 ( V_54 + V_191 ) ;
F_25 ( 0 , V_54 + V_168 ) ;
F_26 ( V_54 + V_168 ) ;
F_25 ( 0 , V_54 + V_159 ) ;
F_26 ( V_54 + V_159 ) ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 )
{
void T_4 * V_54 = V_6 -> V_81 ;
struct V_24 * V_85 ;
struct V_187 * V_188 ;
V_154 * V_179 ;
V_43 V_170 , V_209 ;
unsigned long V_190 ;
int V_210 = 0 ;
V_190 = V_194 ;
while ( ( F_26 ( V_54 + V_211 ) & V_212 ) == 0 ) {
if ( F_54 ( V_194 , V_190 + V_195 * V_90 ) ) {
F_43 (KERN_ERR DRV_NAME
L_7 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_56 ( 1 ) ;
}
V_85 = (struct V_24 * ) V_6 -> V_20 ;
V_85 -> V_92 = F_3 ( V_6 -> V_91 ) ;
V_85 -> V_213 = V_214 ;
V_188 = (struct V_187 * ) ( V_85 + 1 ) ;
V_188 -> V_198 = F_3 ( V_6 -> V_91 ) ;
V_188 -> V_199 = F_13 ( V_6 -> V_22 ) ;
V_188 -> V_200 = F_13 ( V_6 -> V_23 + 1 ) ;
V_188 -> V_201 = F_13 ( sizeof( struct V_4 ) ) ;
V_188 -> V_202 = F_13 ( V_6 -> V_10 + 1 ) ;
F_1 ( & V_188 -> V_203 ) ;
V_188 -> V_204 = V_205 ;
V_188 -> V_206 = V_188 -> V_207 = 0 ;
V_209 = ( V_6 -> V_10 + 1 ) * sizeof( V_43 ) ;
V_188 -> V_209 = F_14 ( V_209 ) ;
V_170 = F_26 ( V_54 + V_215 ) ;
V_170 &= ~ 4 ;
F_25 ( V_170 , V_54 + V_215 ) ;
F_25 ( ( V_6 -> V_91 >> 16 ) >> 16 , V_54 + V_93 ) ;
F_26 ( V_54 + V_93 ) ;
F_25 ( V_6 -> V_91 , V_54 + V_94 ) ;
F_26 ( V_54 + V_94 ) ;
V_179 = V_6 -> V_179 ;
V_190 = V_194 ;
while ( ! ( F_41 ( * V_179 ) & V_216 ) ) {
if ( F_54 ( V_194 , V_190 + V_195 * V_90 ) ) {
F_43 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
V_210 = - 1 ;
break;
}
F_55 () ;
F_56 ( 1 ) ;
}
memset ( V_179 , 0 , V_209 ) ;
V_85 -> V_213 = 0 ;
return V_210 ;
}
static int F_59 ( struct V_5 * V_6 )
{
int V_217 ;
unsigned long V_171 ;
unsigned int V_105 ;
V_217 = ( V_6 -> V_115 == V_218 ) ?
F_58 ( V_6 ) : F_53 ( V_6 ) ;
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
V_105 = V_6 -> V_105 ;
if ( V_217 == 0 ) {
V_6 -> V_21 = 0 ;
V_6 -> V_219 = 0 ;
V_6 -> V_158 = 0 ;
V_6 -> V_9 = 0 ;
V_6 -> V_80 = 0 ;
V_6 -> V_105 = V_220 ;
} else
V_6 -> V_105 = V_221 ;
if ( V_105 == V_106 )
F_60 ( & V_6 -> V_222 ) ;
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
return V_217 ;
}
static int F_61 ( struct V_11 * V_12 )
{
struct V_102 * V_39 = V_12 -> V_75 -> V_39 ;
struct V_5 * V_6 = (struct V_5 * ) V_39 -> V_104 ;
V_37 V_79 = V_12 -> V_89 -> V_79 ;
void T_4 * V_54 ;
V_43 V_170 ;
int V_13 = V_223 ;
unsigned long V_171 ;
F_43 (KERN_INFO DRV_NAME
L_8 , pci_name(hba->pdev)) ;
F_62 ( V_12 ) ;
V_54 = V_6 -> V_81 ;
F_48 ( V_39 -> V_172 , V_171 ) ;
if ( V_79 < V_39 -> V_98 &&
V_6 -> V_26 [ V_79 ] . V_19 && V_6 -> V_26 [ V_79 ] . V_12 == V_12 )
V_6 -> V_162 = & V_6 -> V_26 [ V_79 ] ;
else
goto V_224;
if ( V_6 -> V_115 == V_218 ) {
V_170 = F_26 ( V_54 + V_184 ) ;
if ( V_170 == 0 || V_170 == 0xffffffff )
goto V_225;
F_25 ( V_170 , V_54 + V_185 ) ;
F_51 ( V_6 ) ;
} else {
V_170 = F_26 ( V_54 + V_173 ) ;
if ( V_170 == 0 || V_170 == 0xffffffff )
goto V_225;
F_25 ( V_170 , V_54 + V_173 ) ;
F_26 ( V_54 + V_173 ) ;
F_42 ( V_6 , V_170 ) ;
}
if ( V_6 -> V_162 == NULL ) {
F_43 (KERN_WARNING DRV_NAME
L_9 , pci_name(hba->pdev)) ;
goto V_224;
}
V_225:
F_45 ( V_12 ) ;
V_6 -> V_162 -> V_19 = NULL ;
V_6 -> V_162 = NULL ;
V_13 = V_226 ;
V_224:
F_49 ( V_39 -> V_172 , V_171 ) ;
return V_13 ;
}
static void F_63 ( struct V_5 * V_6 )
{
struct V_227 * V_66 ;
int V_33 ;
V_37 V_228 ;
V_87 V_229 ;
for ( V_33 = 0 ; V_33 < 16 ; V_33 ++ )
F_64 ( V_6 -> V_55 , V_33 * 4 ,
& V_6 -> V_55 -> V_230 [ V_33 ] ) ;
V_66 = V_6 -> V_55 -> V_66 ;
F_65 ( V_66 -> V_231 , V_232 , & V_229 ) ;
V_229 |= V_233 ;
F_66 ( V_66 -> V_231 , V_232 , V_229 ) ;
F_56 ( 100 ) ;
V_229 &= ~ V_233 ;
F_66 ( V_66 -> V_231 , V_232 , V_229 ) ;
for ( V_33 = 0 ; V_33 < V_234 ; V_33 ++ ) {
F_67 ( V_6 -> V_55 , V_235 , & V_228 ) ;
if ( V_228 != 0xffff && ( V_228 & V_236 ) )
break;
F_56 ( 1 ) ;
}
F_68 ( 5 ) ;
for ( V_33 = 0 ; V_33 < 16 ; V_33 ++ )
F_69 ( V_6 -> V_55 , V_33 * 4 ,
V_6 -> V_55 -> V_230 [ V_33 ] ) ;
}
static int F_70 ( struct V_5 * V_6 )
{
void T_4 * V_54 ;
unsigned long V_171 , V_190 ;
int V_210 = 0 ;
V_54 = V_6 -> V_81 ;
F_25 ( V_237 , V_54 + V_84 ) ;
F_26 ( V_54 + V_84 ) ;
V_190 = V_194 ;
while ( V_6 -> V_80 > 0 ) {
if ( F_54 ( V_194 , V_190 + V_238 * V_90 ) ) {
F_43 (KERN_WARNING DRV_NAME
L_10 , pci_name(hba->pdev)) ;
V_210 = - 1 ;
break;
}
F_56 ( 1 ) ;
}
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
if ( V_210 == - 1 )
V_6 -> V_105 = V_221 ;
else
V_6 -> V_105 = V_220 ;
F_60 ( & V_6 -> V_222 ) ;
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
return V_210 ;
}
static void F_71 ( struct V_5 * V_6 )
{
F_25 ( V_239 , V_6 -> V_81 + V_240 ) ;
F_26 ( V_6 -> V_81 + V_240 ) ;
F_68 ( 5 ) ;
}
static int F_72 ( struct V_5 * V_6 )
{
struct V_25 * V_26 ;
unsigned long V_171 ;
unsigned int V_105 = V_106 ;
V_37 V_79 ;
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
if ( V_6 -> V_105 == V_241 ) {
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
F_43 (KERN_INFO DRV_NAME L_11 ,
pci_name(hba->pdev)) ;
return 0 ;
}
while ( V_6 -> V_105 == V_106 ) {
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
F_73 ( V_6 -> V_222 ,
V_6 -> V_105 != V_106 ,
V_195 * V_90 ) ;
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
V_105 = V_6 -> V_105 ;
}
if ( V_105 != V_106 ) {
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
return ( V_105 == V_220 ) ? 0 : - 1 ;
}
V_6 -> V_105 = V_106 ;
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
if ( V_6 -> V_115 == V_160 )
return F_70 ( V_6 ) ;
if ( V_6 -> V_115 == V_116 )
F_63 ( V_6 ) ;
else if ( V_6 -> V_115 == V_218 )
F_71 ( V_6 ) ;
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
for ( V_79 = 0 ; V_79 < V_6 -> V_39 -> V_98 ; V_79 ++ ) {
V_26 = & V_6 -> V_26 [ V_79 ] ;
if ( V_26 -> V_19 == NULL )
continue;
V_26 -> V_19 = NULL ;
if ( V_26 -> V_12 ) {
F_45 ( V_26 -> V_12 ) ;
V_26 -> V_12 -> V_13 = V_242 << 16 ;
V_26 -> V_12 -> V_134 ( V_26 -> V_12 ) ;
V_26 -> V_12 = NULL ;
}
}
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
if ( F_59 ( V_6 ) == 0 )
return 0 ;
F_43 (KERN_WARNING DRV_NAME L_12 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
static int F_74 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) & V_12 -> V_75 -> V_39 -> V_104 [ 0 ] ;
F_43 (KERN_INFO DRV_NAME
L_13 , pci_name(hba->pdev)) ;
F_62 ( V_12 ) ;
return F_72 ( V_6 ) ? V_226 : V_223 ;
}
static void F_75 ( struct V_243 * V_244 )
{
struct V_5 * V_6 = F_76 ( V_244 , struct V_5 , V_176 ) ;
F_72 ( V_6 ) ;
}
static int F_77 ( struct V_95 * V_96 ,
struct V_245 * V_246 , T_6 V_247 , int V_248 [] )
{
int V_249 = 255 , V_250 = 63 ;
if ( V_247 < 0x200000 ) {
V_249 = 64 ;
V_250 = 32 ;
}
F_78 ( V_247 , V_249 * V_250 ) ;
V_248 [ 0 ] = V_249 ;
V_248 [ 1 ] = V_250 ;
V_248 [ 2 ] = V_247 ;
return 0 ;
}
static int F_79 ( struct V_251 * V_55 )
{
int V_210 ;
if ( ! F_80 ( V_55 , F_81 ( 64 ) )
&& ! F_82 ( V_55 , F_81 ( 64 ) ) )
return 0 ;
V_210 = F_80 ( V_55 , F_81 ( 32 ) ) ;
if ( ! V_210 )
V_210 = F_82 ( V_55 , F_81 ( 32 ) ) ;
return V_210 ;
}
static int F_83 ( struct V_5 * V_6 )
{
struct V_251 * V_55 = V_6 -> V_55 ;
int V_7 ;
if ( V_252 ) {
V_7 = F_84 ( V_55 ) ;
if ( V_7 != 0 )
F_43 (KERN_ERR DRV_NAME
L_14 ,
pci_name(pdev), status) ;
else
V_6 -> V_253 = 1 ;
} else
V_6 -> V_253 = 0 ;
V_7 = F_85 ( V_55 -> V_72 , V_6 -> V_115 == V_218 ?
F_52 : F_47 , V_254 , V_255 , V_6 ) ;
if ( V_7 != 0 ) {
if ( V_6 -> V_253 )
F_86 ( V_55 ) ;
}
return V_7 ;
}
static void F_87 ( struct V_5 * V_6 )
{
struct V_251 * V_55 = V_6 -> V_55 ;
F_88 ( V_55 -> V_72 , V_6 ) ;
if ( V_6 -> V_253 )
F_86 ( V_55 ) ;
}
static int F_89 ( struct V_251 * V_55 , const struct V_256 * V_73 )
{
struct V_5 * V_6 ;
struct V_102 * V_39 ;
const struct V_257 * V_258 = NULL ;
V_43 V_259 , V_260 , V_261 ;
int V_217 ;
V_217 = F_90 ( V_55 ) ;
if ( V_217 )
return V_217 ;
F_91 ( V_55 ) ;
V_39 = F_92 ( & V_262 , sizeof( struct V_5 ) ) ;
if ( ! V_39 ) {
F_43 (KERN_ERR DRV_NAME L_15 ,
pci_name(pdev)) ;
V_217 = - V_263 ;
goto V_264;
}
V_6 = (struct V_5 * ) V_39 -> V_104 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_217 = F_93 ( V_55 , V_255 ) ;
if ( V_217 < 0 ) {
F_43 (KERN_ERR DRV_NAME L_16 ,
pci_name(pdev)) ;
goto V_265;
}
V_6 -> V_81 = F_94 ( V_55 , 0 ) ;
if ( ! V_6 -> V_81 ) {
F_43 (KERN_ERR DRV_NAME L_17 ,
pci_name(pdev)) ;
V_217 = - V_263 ;
goto V_266;
}
V_217 = F_79 ( V_55 ) ;
if ( V_217 ) {
F_43 (KERN_ERR DRV_NAME L_18 ,
pci_name(pdev)) ;
goto V_267;
}
V_6 -> V_115 = ( unsigned int ) V_73 -> V_268 ;
V_258 = & V_269 [ V_6 -> V_115 ] ;
V_259 = V_261 = ( V_258 -> V_23 + 1 ) * V_258 -> V_22 ;
if ( V_6 -> V_115 == V_218 )
V_259 += ( V_258 -> V_10 + 1 ) * sizeof( V_43 ) ;
V_260 = V_259 + ( V_258 -> V_10 + 1 ) * sizeof( struct V_4 ) ;
V_6 -> V_208 = V_260 + sizeof( struct V_51 ) ;
if ( V_6 -> V_115 == V_270 ||
( V_6 -> V_115 == V_271 && ( V_55 -> V_78 & 1 ) ) ) {
V_6 -> V_206 = V_6 -> V_208 ;
V_6 -> V_208 += V_272 ;
}
V_6 -> V_20 = F_95 ( & V_55 -> V_273 ,
V_6 -> V_208 , & V_6 -> V_91 , V_274 ) ;
if ( ! V_6 -> V_20 ) {
if ( V_6 -> V_115 == V_270 ||
( V_6 -> V_115 == V_271 && ( V_55 -> V_78 & 1 ) ) ) {
F_43 (KERN_WARNING DRV_NAME
L_19 ,
pci_name(pdev)) ;
V_6 -> V_208 = V_6 -> V_206
+ V_275 ;
V_6 -> V_20 = F_95 ( & V_55 -> V_273 ,
V_6 -> V_208 , & V_6 -> V_91 , V_274 ) ;
}
if ( ! V_6 -> V_20 ) {
V_217 = - V_263 ;
F_43 (KERN_ERR DRV_NAME L_20 ,
pci_name(pdev)) ;
goto V_267;
}
}
V_6 -> V_26 = F_96 ( V_258 -> V_23 , sizeof( struct V_25 ) , V_274 ) ;
if ( ! V_6 -> V_26 ) {
V_217 = - V_263 ;
F_43 (KERN_ERR DRV_NAME L_21 ,
pci_name(pdev)) ;
goto V_276;
}
if ( V_6 -> V_115 == V_218 )
V_6 -> V_179 = ( V_154 * ) ( V_6 -> V_20 + V_261 ) ;
V_6 -> V_8 = (struct V_4 * ) ( V_6 -> V_20 + V_259 ) ;
V_6 -> V_53 = V_6 -> V_20 + V_260 ;
V_6 -> V_23 = V_258 -> V_23 ;
V_6 -> V_22 = V_258 -> V_22 ;
V_6 -> V_10 = V_258 -> V_10 ;
V_6 -> V_135 = V_258 -> V_135 ;
V_6 -> V_148 = V_258 -> V_148 ;
V_6 -> V_149 = V_258 -> V_149 ;
V_6 -> V_105 = V_241 ;
if ( V_6 -> V_115 == V_218 )
V_39 -> V_40 = 38 ;
else
V_39 -> V_40 = 32 ;
V_39 -> V_98 = V_258 -> V_23 ;
V_39 -> V_197 = V_258 -> V_23 ;
V_39 -> V_117 = V_258 -> V_117 ;
V_39 -> V_120 = V_258 -> V_120 ;
V_39 -> V_277 = V_258 -> V_277 ;
V_39 -> V_278 = V_39 -> V_132 ;
V_39 -> V_279 = V_138 ;
V_6 -> V_39 = V_39 ;
V_6 -> V_55 = V_55 ;
F_97 ( & V_6 -> V_222 ) ;
snprintf ( V_6 -> V_280 , sizeof( V_6 -> V_280 ) ,
L_22 , V_39 -> V_132 ) ;
V_6 -> V_175 = F_98 ( V_6 -> V_280 ) ;
if ( ! V_6 -> V_175 ) {
F_43 (KERN_ERR DRV_NAME L_23 ,
pci_name(pdev)) ;
V_217 = - V_263 ;
goto V_281;
}
F_99 ( & V_6 -> V_176 , F_75 ) ;
V_217 = F_83 ( V_6 ) ;
if ( V_217 ) {
F_43 (KERN_ERR DRV_NAME L_24 ,
pci_name(pdev)) ;
goto V_282;
}
V_217 = F_59 ( V_6 ) ;
if ( V_217 )
goto V_283;
V_217 = F_100 ( V_39 , V_39 -> V_98 ) ;
if ( V_217 ) {
F_43 (KERN_ERR DRV_NAME L_25 ,
pci_name(pdev)) ;
goto V_283;
}
F_101 ( V_55 , V_6 ) ;
V_217 = F_102 ( V_39 , & V_55 -> V_273 ) ;
if ( V_217 ) {
F_43 (KERN_ERR DRV_NAME L_26 ,
pci_name(pdev)) ;
goto V_283;
}
F_103 ( V_39 ) ;
return 0 ;
V_283:
F_87 ( V_6 ) ;
V_282:
F_104 ( V_6 -> V_175 ) ;
V_281:
F_105 ( V_6 -> V_26 ) ;
V_276:
F_106 ( & V_55 -> V_273 , V_6 -> V_208 ,
V_6 -> V_20 , V_6 -> V_91 ) ;
V_267:
F_107 ( V_6 -> V_81 ) ;
V_266:
F_108 ( V_55 ) ;
V_265:
F_109 ( V_39 ) ;
V_264:
F_110 ( V_55 ) ;
return V_217 ;
}
static void F_111 ( struct V_5 * V_6 )
{
struct V_18 * V_19 ;
struct V_24 * V_85 ;
unsigned long V_171 ;
unsigned long V_190 ;
V_37 V_79 = 0 ;
F_48 ( V_6 -> V_39 -> V_172 , V_171 ) ;
V_19 = V_6 -> V_135 ( V_6 ) ;
if ( V_6 -> V_115 == V_218 ) {
V_85 = (struct V_24 * ) V_19 - 1 ;
memset ( V_85 , 0 , V_6 -> V_22 ) ;
} else
memset ( V_19 , 0 , V_6 -> V_22 ) ;
if ( V_6 -> V_115 == V_160 || V_6 -> V_115 == V_218 ) {
V_19 -> V_137 [ 0 ] = V_153 ;
V_19 -> V_137 [ 1 ] = V_284 ;
V_19 -> V_137 [ 2 ] = V_285 ;
V_19 -> V_137 [ 3 ] = V_286 ;
} else {
V_19 -> V_137 [ 0 ] = V_287 ;
V_19 -> V_137 [ 1 ] = V_288 ;
V_19 -> V_137 [ 2 ] = V_289 ;
}
V_6 -> V_26 [ V_79 ] . V_12 = NULL ;
V_6 -> V_26 [ V_79 ] . V_36 = 0 ;
V_6 -> V_26 [ V_79 ] . V_146 = 0 ;
V_6 -> V_26 [ V_79 ] . V_16 = NULL ;
V_6 -> V_26 [ V_79 ] . V_167 = V_290 ;
V_6 -> V_149 ( V_6 , V_19 , V_79 ) ;
F_49 ( V_6 -> V_39 -> V_172 , V_171 ) ;
V_190 = V_194 ;
while ( V_6 -> V_26 [ V_79 ] . V_167 & V_290 ) {
if ( F_54 ( V_194 , V_190 + V_238 * V_90 ) ) {
V_6 -> V_26 [ V_79 ] . V_167 = 0 ;
return;
}
F_56 ( 1 ) ;
}
}
static void F_112 ( struct V_5 * V_6 )
{
F_87 ( V_6 ) ;
F_104 ( V_6 -> V_175 ) ;
F_107 ( V_6 -> V_81 ) ;
F_108 ( V_6 -> V_55 ) ;
F_105 ( V_6 -> V_26 ) ;
F_106 ( & V_6 -> V_55 -> V_273 , V_6 -> V_208 ,
V_6 -> V_20 , V_6 -> V_91 ) ;
}
static void F_113 ( struct V_251 * V_55 )
{
struct V_5 * V_6 = F_114 ( V_55 ) ;
F_115 ( V_6 -> V_39 ) ;
F_111 ( V_6 ) ;
F_112 ( V_6 ) ;
F_109 ( V_6 -> V_39 ) ;
F_110 ( V_55 ) ;
}
static void F_116 ( struct V_251 * V_55 )
{
struct V_5 * V_6 = F_114 ( V_55 ) ;
F_111 ( V_6 ) ;
}
static int T_7 F_117 ( void )
{
F_43 (KERN_INFO DRV_NAME
L_27 ,
ST_DRIVER_VERSION) ;
return F_118 ( & V_291 ) ;
}
static void T_8 F_119 ( void )
{
F_120 ( & V_291 ) ;
}
