static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 + V_3 -> V_6 ;
++ V_3 -> V_6 ;
V_3 -> V_6 %= V_3 -> V_7 + 1 ;
return V_4 ;
}
static void F_2 ( struct V_8 * V_9 ,
void (* F_3)( struct V_8 * ) )
{
V_9 -> V_10 = ( V_11 << 24 ) | V_12 ;
F_4 ( 0 , V_9 -> V_13 , V_14 , 0x24 ,
0x0 ) ;
F_3 ( V_9 ) ;
}
static struct V_15 * F_5 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = V_3 -> V_17 + V_3 -> V_18 * V_3 -> V_19 ;
++ V_3 -> V_18 ;
V_3 -> V_18 %= V_3 -> V_20 + 1 ;
return V_16 ;
}
static struct V_15 * F_6 ( struct V_2 * V_3 )
{
return (struct V_15 * ) ( V_3 -> V_17 +
V_3 -> V_18 * V_3 -> V_19 + sizeof( struct V_21 ) ) ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_15 * V_16 , struct V_22 * V_23 )
{
struct V_8 * V_9 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 , V_31 ;
V_9 = V_23 -> V_9 ;
V_31 = F_8 ( V_9 ) ;
F_9 ( V_31 < 0 ) ;
if ( V_31 ) {
V_27 = (struct V_26 * ) V_16 -> V_32 ;
V_23 -> V_33 = V_31 ;
V_27 -> V_33 = F_10 ( ( V_34 ) V_31 ) ;
V_27 -> V_35 = F_10 ( V_3 -> V_36 -> V_37 ) ;
V_27 -> V_38 = F_11 ( F_12 ( V_9 ) ) ;
V_29 = (struct V_28 * ) ( V_27 + 1 ) ;
F_13 (cmd, sg, nseg, i) {
V_29 [ V_30 ] . V_39 = F_11 ( ( V_40 ) F_14 ( V_25 ) ) ;
V_29 [ V_30 ] . V_41 = F_15 ( F_16 ( V_25 ) ) ;
V_29 [ V_30 ] . V_42 = V_43 | V_44 ;
}
V_29 [ -- V_30 ] . V_42 |= V_45 ;
}
return V_31 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_15 * V_16 , struct V_22 * V_23 )
{
struct V_8 * V_9 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_46 * V_29 ;
int V_30 , V_31 ;
V_9 = V_23 -> V_9 ;
V_31 = F_8 ( V_9 ) ;
F_9 ( V_31 < 0 ) ;
if ( V_31 ) {
V_27 = (struct V_26 * ) V_16 -> V_32 ;
V_23 -> V_33 = V_31 ;
V_27 -> V_33 = F_10 ( ( V_34 ) V_31 ) ;
V_27 -> V_35 = F_10 ( V_3 -> V_36 -> V_37 ) ;
V_27 -> V_38 = F_11 ( F_12 ( V_9 ) ) ;
V_29 = (struct V_46 * ) ( V_27 + 1 ) ;
F_13 (cmd, sg, nseg, i) {
V_29 [ V_30 ] . V_39 = F_11 ( ( V_40 ) F_14 ( V_25 ) ) ;
V_29 [ V_30 ] . V_41 =
F_11 ( F_16 ( V_25 ) & 0xffffffff ) ;
V_29 [ V_30 ] . V_47 =
F_11 ( ( F_16 ( V_25 ) >> 16 ) >> 16 ) ;
}
}
return V_31 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_22 * V_23 )
{
struct V_48 * V_49 ;
T_1 V_39 = sizeof( struct V_48 ) ;
V_49 = V_3 -> V_50 ;
F_19 ( V_23 -> V_9 , V_49 , V_39 ) ;
memset ( V_49 -> V_51 , 0 , sizeof( V_40 ) * 6 ) ;
* ( unsigned long * ) ( V_49 -> V_51 ) = F_20 ( V_3 -> V_52 , 0 ) ;
V_49 -> V_53 = 0 ;
V_49 -> V_54 . V_55 = V_56 ;
V_49 -> V_54 . V_57 = V_58 ;
V_49 -> V_54 . V_59 = V_60 ;
V_49 -> V_54 . V_61 = V_62 ;
V_49 -> V_63 = V_3 -> V_52 -> V_63 -> V_64 ;
V_49 -> V_65 = V_3 -> V_52 -> V_66 ;
V_49 -> V_67 = 0 ;
V_49 -> V_68 = V_3 -> V_52 -> V_69 ;
V_49 -> V_70 = V_3 -> V_52 -> V_71 << 16 | V_3 -> V_52 -> V_72 ;
V_49 -> V_73 =
V_3 -> V_52 -> V_74 << 16 | V_3 -> V_52 -> V_75 ;
F_21 ( V_23 -> V_9 , V_49 , V_39 ) ;
}
static void
F_22 ( struct V_2 * V_3 , struct V_15 * V_16 , V_34 V_76 )
{
V_16 -> V_76 = F_10 ( V_76 ) ;
V_3 -> V_23 [ V_76 ] . V_16 = V_16 ;
V_3 -> V_77 ++ ;
F_23 ( V_3 -> V_18 , V_3 -> V_78 + V_79 ) ;
F_23 ( V_80 , V_3 -> V_78 + V_81 ) ;
F_24 ( V_3 -> V_78 + V_81 ) ;
}
static void
F_25 ( struct V_2 * V_3 , struct V_15 * V_16 , V_34 V_76 )
{
struct V_8 * V_9 ;
struct V_21 * V_82 ;
T_2 V_41 ;
V_16 -> V_76 = F_10 ( V_76 ) ;
V_3 -> V_23 [ V_76 ] . V_16 = V_16 ;
V_3 -> V_77 ++ ;
V_9 = V_3 -> V_23 [ V_76 ] . V_9 ;
V_82 = (struct V_21 * ) V_16 - 1 ;
if ( F_26 ( V_9 ) ) {
V_82 -> V_83 = ( V_84 ) V_9 -> V_72 -> V_83 ;
V_82 -> V_85 = F_10 ( V_9 -> V_86 -> V_85 / V_87 ) ;
}
V_41 = V_3 -> V_88 + V_3 -> V_18 * V_3 -> V_19 ;
V_41 += ( V_3 -> V_23 [ V_76 ] . V_33 + 4 ) / 11 ;
V_82 -> V_89 = F_15 ( V_41 ) ;
++ V_3 -> V_18 ;
V_3 -> V_18 %= V_3 -> V_20 + 1 ;
F_23 ( ( V_41 >> 16 ) >> 16 , V_3 -> V_78 + V_90 ) ;
F_24 ( V_3 -> V_78 + V_90 ) ;
F_23 ( V_41 , V_3 -> V_78 + V_91 ) ;
F_24 ( V_3 -> V_78 + V_91 ) ;
}
static int
F_27 ( struct V_92 * V_93 )
{
V_93 -> V_94 = 1 ;
V_93 -> V_95 = 1 ;
F_28 ( V_93 -> V_96 , 60 * V_87 ) ;
return 0 ;
}
static int
F_29 ( struct V_8 * V_9 , void (* F_3)( struct V_8 * ) )
{
struct V_2 * V_3 ;
struct V_97 * V_36 ;
unsigned int V_70 , V_98 ;
struct V_15 * V_16 ;
V_34 V_76 ;
V_36 = V_9 -> V_72 -> V_36 ;
V_70 = V_9 -> V_72 -> V_70 ;
V_98 = V_9 -> V_72 -> V_98 ;
V_3 = (struct V_2 * ) & V_36 -> V_99 [ 0 ] ;
if ( F_30 ( V_3 -> V_100 == V_101 ) )
return V_102 ;
switch ( V_9 -> V_103 [ 0 ] ) {
case V_104 :
{
static char V_105 [ 12 ] =
{ 0 , 0x12 , 0 , 0 , 0 , 0 , 0 , 0 , 0x8 , 0xa , 0x4 , 0 } ;
unsigned char V_106 ;
V_106 = V_9 -> V_103 [ 2 ] & 0x3f ;
if ( V_106 == 0x8 || V_106 == 0x3f ) {
F_21 ( V_9 , V_105 ,
sizeof( V_105 ) ) ;
V_9 -> V_10 = V_107 << 16 | V_108 << 8 ;
F_3 ( V_9 ) ;
} else
F_2 ( V_9 , F_3 ) ;
return 0 ;
}
case V_109 :
if ( V_3 -> V_110 == V_111 || V_70 == V_36 -> V_112 - 1 ) {
F_2 ( V_9 , F_3 ) ;
return 0 ;
}
break;
case V_113 :
if ( V_70 == V_36 -> V_112 - 1 ) {
V_9 -> V_10 = V_107 << 16 | V_108 << 8 ;
F_3 ( V_9 ) ;
return 0 ;
}
break;
case V_114 :
if ( V_98 >= V_36 -> V_115 ) {
V_9 -> V_10 = V_116 << 16 ;
F_3 ( V_9 ) ;
return 0 ;
}
if ( V_70 != V_36 -> V_112 - 1 )
break;
if ( ! V_98 && ! V_9 -> V_72 -> V_83 &&
( V_9 -> V_103 [ 1 ] & V_117 ) == 0 ) {
F_21 ( V_9 , ( void * ) V_118 ,
sizeof( V_118 ) ) ;
V_9 -> V_10 = V_107 << 16 | V_108 << 8 ;
F_3 ( V_9 ) ;
} else
F_2 ( V_9 , F_3 ) ;
return 0 ;
case V_119 :
if ( V_9 -> V_103 [ 1 ] == V_120 ) {
struct V_121 V_122 ;
T_1 V_123 = sizeof( V_122 ) ;
V_122 . V_55 = V_56 ;
V_122 . V_57 = V_58 ;
V_122 . V_59 = V_60 ;
V_122 . V_61 = V_62 ;
V_122 . V_124 [ 0 ] = V_125 ;
V_122 . V_126 = V_36 -> V_112 - 1 ;
V_122 . V_127 = V_3 -> V_36 -> V_127 ;
V_123 = F_21 ( V_9 , & V_122 , V_123 ) ;
V_9 -> V_10 = sizeof( V_122 ) == V_123 ?
V_107 << 16 | V_108 << 8 :
V_128 << 16 | V_108 << 8 ;
F_3 ( V_9 ) ;
return 0 ;
}
default:
break;
}
V_9 -> V_129 = F_3 ;
V_76 = V_9 -> V_86 -> V_76 ;
if ( F_30 ( V_76 >= V_36 -> V_130 ) )
return V_102 ;
V_16 = V_3 -> V_131 ( V_3 ) ;
V_16 -> V_98 = V_98 ;
V_16 -> V_132 = V_70 ;
memcpy ( V_16 -> V_133 , V_9 -> V_103 , V_134 ) ;
if ( V_9 -> V_135 == V_136 )
V_16 -> V_137 = V_138 ;
else if ( V_9 -> V_135 == V_139 )
V_16 -> V_137 = V_140 ;
else
V_16 -> V_137 = V_141 ;
V_3 -> V_23 [ V_76 ] . V_9 = V_9 ;
V_3 -> V_23 [ V_76 ] . V_142 = V_143 ;
V_3 -> V_23 [ V_76 ] . V_13 = V_9 -> V_13 ;
if ( ! V_3 -> V_144 ( V_3 , V_16 , & V_3 -> V_23 [ V_76 ] ) ) {
V_3 -> V_23 [ V_76 ] . V_33 = 0 ;
memset ( & V_16 -> V_32 [ 0 ] , 0 , 8 ) ;
}
V_3 -> V_145 ( V_3 , V_16 , V_76 ) ;
return 0 ;
}
void F_31 ( struct V_22 * V_23 ,
struct V_1 * V_146 , unsigned int V_32 )
{
if ( V_146 -> V_147 != V_148 ) {
if ( V_23 -> V_13 != NULL )
memcpy ( V_23 -> V_13 , V_146 -> V_32 ,
F_32 ( V_32 , V_23 -> V_142 ) ) ;
return;
}
if ( V_23 -> V_9 == NULL )
return;
F_21 ( V_23 -> V_9 , V_146 -> V_32 , V_32 ) ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_1 * V_146 )
{
if ( V_23 -> V_9 -> V_103 [ 0 ] == V_149 &&
V_146 -> V_147 != V_12 )
F_34 ( V_23 -> V_9 , F_12 ( V_23 -> V_9 ) -
F_35 ( * ( V_150 * ) & V_146 -> V_32 [ 0 ] ) ) ;
}
static void F_36 ( struct V_2 * V_3 , V_40 V_151 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_1 * V_146 ;
struct V_22 * V_23 ;
unsigned int V_152 ;
V_34 V_76 ;
if ( F_30 ( ! ( V_151 & V_153 ) ) )
return;
V_3 -> V_154 = F_24 ( V_51 + V_155 ) ;
if ( F_30 ( V_3 -> V_154 > V_3 -> V_7 ) ) {
F_37 (KERN_WARNING DRV_NAME L_1 ,
pci_name(hba->pdev)) ;
return;
}
if ( F_30 ( V_3 -> V_77 <= 0 ||
( V_3 -> V_100 == V_101 &&
V_3 -> V_110 != V_156 ) ) ) {
V_3 -> V_6 = V_3 -> V_154 ;
goto V_157;
}
while ( V_3 -> V_6 != V_3 -> V_154 ) {
V_146 = F_1 ( V_3 ) ;
V_76 = F_38 ( V_146 -> V_76 ) ;
if ( F_30 ( V_76 >= V_3 -> V_36 -> V_130 ) ) {
F_37 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_3 -> V_77 -- ;
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( F_30 ( V_3 -> V_158 == V_23 ) )
V_3 -> V_158 = NULL ;
if ( F_30 ( V_23 -> V_16 == NULL ) ) {
F_37 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_152 = V_146 -> V_159 * sizeof( V_40 ) ;
if ( F_30 ( V_152 < sizeof( * V_146 ) - V_160 ||
V_152 > sizeof( * V_146 ) ) ) {
F_37 (KERN_WARNING DRV_NAME L_4 ,
pci_name(hba->pdev)) ;
} else {
V_152 -= sizeof( * V_146 ) - V_160 ;
if ( V_152 )
F_31 ( V_23 , V_146 , V_152 ) ;
}
V_23 -> V_16 = NULL ;
V_23 -> V_161 = V_146 -> V_161 ;
V_23 -> V_147 = V_146 -> V_147 ;
if ( F_26 ( V_23 -> V_9 != NULL ) ) {
if ( V_3 -> V_110 == V_156 )
F_33 ( V_3 , V_23 , V_146 ) ;
if ( F_30 ( V_23 -> V_9 -> V_103 [ 0 ] == V_119 &&
V_23 -> V_9 -> V_103 [ 1 ] == V_162 ) )
F_18 ( V_3 , V_23 ) ;
F_39 ( V_23 -> V_9 ) ;
F_40 ( V_23 ) ;
} else
V_23 -> V_163 = 0 ;
}
V_157:
F_23 ( V_3 -> V_154 , V_51 + V_164 ) ;
F_24 ( V_51 + V_164 ) ;
}
static T_4 F_41 ( int V_69 , void * V_165 )
{
struct V_2 * V_3 = V_165 ;
void T_3 * V_51 = V_3 -> V_78 ;
V_40 V_166 ;
unsigned long V_167 ;
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
V_166 = F_24 ( V_51 + V_169 ) ;
if ( V_166 && V_166 != 0xffffffff ) {
F_23 ( V_166 , V_51 + V_169 ) ;
F_24 ( V_51 + V_169 ) ;
F_36 ( V_3 , V_166 ) ;
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
if ( F_30 ( V_166 & V_170 &&
V_3 -> V_110 == V_111 ) )
F_44 ( V_3 -> V_171 , & V_3 -> V_172 ) ;
return V_173 ;
}
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
return V_174 ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_146 ;
struct V_22 * V_23 ;
V_150 * V_175 ;
unsigned int V_152 ;
int V_39 = 0 ;
V_40 V_176 ;
V_34 V_76 ;
if ( F_30 ( V_3 -> V_77 <= 0 ||
V_3 -> V_100 == V_101 ) )
return;
while ( V_39 < V_3 -> V_7 ) {
V_175 = V_3 -> V_175 + V_3 -> V_6 ;
V_176 = F_35 ( * V_175 ) ;
if ( F_30 ( ! ( V_176 & V_177 ) ) )
return;
V_146 = V_3 -> V_5 + V_3 -> V_6 ;
* V_175 = 0 ;
++ V_39 ;
++ V_3 -> V_6 ;
V_3 -> V_6 %= V_3 -> V_7 + 1 ;
V_76 = ( V_34 ) V_176 ;
if ( F_30 ( V_76 >= V_3 -> V_36 -> V_130 ) ) {
F_37 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_3 -> V_77 -- ;
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( F_30 ( V_3 -> V_158 == V_23 ) )
V_3 -> V_158 = NULL ;
if ( F_30 ( V_23 -> V_16 == NULL ) ) {
F_37 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_23 -> V_16 = NULL ;
if ( F_26 ( V_176 & V_178 ) ) {
V_23 -> V_161 = V_179 ;
V_23 -> V_147 = V_148 ;
} else {
V_23 -> V_161 = V_146 -> V_161 ;
V_23 -> V_147 = V_146 -> V_147 ;
V_152 = V_146 -> V_159 * sizeof( V_40 ) ;
if ( F_30 ( V_152 < sizeof( * V_146 ) - V_160 ||
V_152 > sizeof( * V_146 ) ) ) {
F_37 (KERN_WARNING DRV_NAME
L_4 ,
pci_name(hba->pdev)) ;
} else {
V_152 -= sizeof( * V_146 ) - V_160 ;
if ( V_152 )
F_31 ( V_23 , V_146 , V_152 ) ;
}
if ( F_26 ( V_23 -> V_9 != NULL ) )
F_33 ( V_3 , V_23 , V_146 ) ;
}
if ( F_26 ( V_23 -> V_9 != NULL ) ) {
F_39 ( V_23 -> V_9 ) ;
F_40 ( V_23 ) ;
} else
V_23 -> V_163 = 0 ;
}
}
static T_4 F_46 ( int V_69 , void * V_165 )
{
struct V_2 * V_3 = V_165 ;
void T_3 * V_51 = V_3 -> V_78 ;
V_40 V_166 ;
unsigned long V_167 ;
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
V_166 = F_24 ( V_51 + V_180 ) ;
if ( V_166 && V_166 != 0xffffffff ) {
F_23 ( V_166 , V_51 + V_181 ) ;
F_45 ( V_3 ) ;
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
if ( F_30 ( V_166 & V_182 ) )
F_44 ( V_3 -> V_171 , & V_3 -> V_172 ) ;
return V_173 ;
}
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
return V_174 ;
}
static int F_47 ( struct V_2 * V_3 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_183 * V_184 ;
T_2 V_185 ;
V_40 V_166 ;
unsigned long V_186 ;
if ( F_24 ( V_51 + V_187 ) != V_188 ) {
F_23 ( V_189 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
V_186 = V_190 ;
while ( F_24 ( V_51 + V_187 ) != V_188 ) {
if ( F_48 ( V_190 , V_186 + V_191 * V_87 ) ) {
F_37 (KERN_ERR DRV_NAME
L_5 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_49 () ;
F_50 ( 1 ) ;
}
}
F_51 ( 10 ) ;
V_166 = F_24 ( V_51 + V_155 ) ;
if ( ( V_166 & 0xffff0000 ) == V_192 ) {
V_166 &= 0x0000ffff ;
if ( V_3 -> V_36 -> V_130 > V_166 ) {
V_3 -> V_36 -> V_130 = V_166 ;
V_3 -> V_36 -> V_193 = V_166 ;
}
}
V_184 = (struct V_183 * ) V_3 -> V_5 ;
V_184 -> V_194 = F_15 ( V_3 -> V_88 ) ;
V_184 -> V_195 = F_10 ( V_3 -> V_19 ) ;
V_184 -> V_196 = F_10 ( V_3 -> V_20 + 1 ) ;
V_184 -> V_197 = F_10 ( sizeof( struct V_1 ) ) ;
V_184 -> V_198 = F_10 ( V_3 -> V_7 + 1 ) ;
V_184 -> V_199 = F_15 ( F_52 () ) ;
V_184 -> V_200 = V_201 ;
if ( V_3 -> V_202 ) {
V_184 -> V_202 = F_11 ( V_3 -> V_202 ) ;
V_184 -> V_203 = F_11 ( V_3 -> V_204 - V_3 -> V_202 ) ;
} else
V_184 -> V_202 = V_184 -> V_203 = 0 ;
V_185 = V_3 -> V_88 + ( V_3 -> V_20 + 1 ) * V_3 -> V_19 ;
F_23 ( V_185 , V_51 + V_79 ) ;
F_24 ( V_51 + V_79 ) ;
F_23 ( ( V_185 >> 16 ) >> 16 , V_51 + V_164 ) ;
F_24 ( V_51 + V_164 ) ;
F_23 ( ( V_185 >> 16 ) >> 16 , V_51 + V_187 ) ;
F_24 ( V_51 + V_187 ) ;
F_23 ( V_189 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
F_51 ( 10 ) ;
V_186 = V_190 ;
while ( F_24 ( V_51 + V_187 ) != V_188 ) {
if ( F_48 ( V_190 , V_186 + V_191 * V_87 ) ) {
F_37 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_49 () ;
F_50 ( 1 ) ;
}
F_23 ( 0 , V_51 + V_79 ) ;
F_24 ( V_51 + V_79 ) ;
F_23 ( 0 , V_51 + V_187 ) ;
F_24 ( V_51 + V_187 ) ;
F_23 ( 0 , V_51 + V_164 ) ;
F_24 ( V_51 + V_164 ) ;
F_23 ( 0 , V_51 + V_155 ) ;
F_24 ( V_51 + V_155 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_21 * V_82 ;
struct V_183 * V_184 ;
V_150 * V_175 ;
V_40 V_166 , V_205 ;
unsigned long V_186 ;
int V_206 = 0 ;
V_186 = V_190 ;
while ( ( F_24 ( V_51 + V_207 ) & V_208 ) == 0 ) {
if ( F_48 ( V_190 , V_186 + V_191 * V_87 ) ) {
F_37 (KERN_ERR DRV_NAME
L_7 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_50 ( 1 ) ;
}
V_82 = (struct V_21 * ) V_3 -> V_17 ;
V_82 -> V_89 = F_15 ( V_3 -> V_88 ) ;
V_82 -> V_209 = V_210 ;
V_184 = (struct V_183 * ) ( V_82 + 1 ) ;
V_184 -> V_194 = F_15 ( V_3 -> V_88 ) ;
V_184 -> V_195 = F_10 ( V_3 -> V_19 ) ;
V_184 -> V_196 = F_10 ( V_3 -> V_20 + 1 ) ;
V_184 -> V_197 = F_10 ( sizeof( struct V_1 ) ) ;
V_184 -> V_198 = F_10 ( V_3 -> V_7 + 1 ) ;
V_184 -> V_199 = F_15 ( F_52 () ) ;
V_184 -> V_200 = V_201 ;
V_184 -> V_202 = V_184 -> V_203 = 0 ;
V_205 = ( V_3 -> V_7 + 1 ) * sizeof( V_40 ) ;
V_184 -> V_205 = F_11 ( V_205 ) ;
V_166 = F_24 ( V_51 + V_211 ) ;
V_166 &= ~ 4 ;
F_23 ( V_166 , V_51 + V_211 ) ;
F_23 ( ( V_3 -> V_88 >> 16 ) >> 16 , V_51 + V_90 ) ;
F_24 ( V_51 + V_90 ) ;
F_23 ( V_3 -> V_88 , V_51 + V_91 ) ;
F_24 ( V_51 + V_91 ) ;
V_175 = V_3 -> V_175 ;
V_186 = V_190 ;
while ( ! ( F_35 ( * V_175 ) & V_212 ) ) {
if ( F_48 ( V_190 , V_186 + V_191 * V_87 ) ) {
F_37 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
V_206 = - 1 ;
break;
}
F_49 () ;
F_50 ( 1 ) ;
}
memset ( V_175 , 0 , V_205 ) ;
V_82 -> V_209 = 0 ;
return V_206 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_213 ;
unsigned long V_167 ;
unsigned int V_100 ;
V_213 = ( V_3 -> V_110 == V_214 ) ?
F_53 ( V_3 ) : F_47 ( V_3 ) ;
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
V_100 = V_3 -> V_100 ;
if ( V_213 == 0 ) {
V_3 -> V_18 = 0 ;
V_3 -> V_215 = 0 ;
V_3 -> V_154 = 0 ;
V_3 -> V_6 = 0 ;
V_3 -> V_77 = 0 ;
V_3 -> V_100 = V_216 ;
} else
V_3 -> V_100 = V_217 ;
if ( V_100 == V_101 )
F_55 ( & V_3 -> V_218 ) ;
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
return V_213 ;
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_97 * V_36 = V_9 -> V_72 -> V_36 ;
struct V_2 * V_3 = (struct V_2 * ) V_36 -> V_99 ;
V_34 V_76 = V_9 -> V_86 -> V_76 ;
void T_3 * V_51 ;
V_40 V_166 ;
int V_10 = V_219 ;
unsigned long V_167 ;
F_57 ( V_220 , V_9 , L_8 ) ;
V_51 = V_3 -> V_78 ;
F_42 ( V_36 -> V_168 , V_167 ) ;
if ( V_76 < V_36 -> V_130 &&
V_3 -> V_23 [ V_76 ] . V_16 && V_3 -> V_23 [ V_76 ] . V_9 == V_9 )
V_3 -> V_158 = & V_3 -> V_23 [ V_76 ] ;
else
goto V_221;
if ( V_3 -> V_110 == V_214 ) {
V_166 = F_24 ( V_51 + V_180 ) ;
if ( V_166 == 0 || V_166 == 0xffffffff )
goto V_222;
F_23 ( V_166 , V_51 + V_181 ) ;
F_45 ( V_3 ) ;
} else {
V_166 = F_24 ( V_51 + V_169 ) ;
if ( V_166 == 0 || V_166 == 0xffffffff )
goto V_222;
F_23 ( V_166 , V_51 + V_169 ) ;
F_24 ( V_51 + V_169 ) ;
F_36 ( V_3 , V_166 ) ;
}
if ( V_3 -> V_158 == NULL ) {
F_37 (KERN_WARNING DRV_NAME
L_9 , pci_name(hba->pdev)) ;
goto V_221;
}
V_222:
F_39 ( V_9 ) ;
V_3 -> V_158 -> V_16 = NULL ;
V_3 -> V_158 = NULL ;
V_10 = V_223 ;
V_221:
F_43 ( V_36 -> V_168 , V_167 ) ;
return V_10 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_224 * V_63 ;
int V_30 ;
V_34 V_225 ;
V_84 V_226 ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
F_59 ( V_3 -> V_52 , V_30 * 4 ,
& V_3 -> V_52 -> V_227 [ V_30 ] ) ;
V_63 = V_3 -> V_52 -> V_63 ;
F_60 ( V_63 -> V_228 , V_229 , & V_226 ) ;
V_226 |= V_230 ;
F_61 ( V_63 -> V_228 , V_229 , V_226 ) ;
F_50 ( 100 ) ;
V_226 &= ~ V_230 ;
F_61 ( V_63 -> V_228 , V_229 , V_226 ) ;
for ( V_30 = 0 ; V_30 < V_231 ; V_30 ++ ) {
F_62 ( V_3 -> V_52 , V_232 , & V_225 ) ;
if ( V_225 != 0xffff && ( V_225 & V_233 ) )
break;
F_50 ( 1 ) ;
}
F_63 ( 5 ) ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
F_64 ( V_3 -> V_52 , V_30 * 4 ,
V_3 -> V_52 -> V_227 [ V_30 ] ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
void T_3 * V_51 ;
unsigned long V_167 , V_186 ;
int V_206 = 0 ;
V_51 = V_3 -> V_78 ;
F_23 ( V_234 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
V_186 = V_190 ;
while ( V_3 -> V_77 > 0 ) {
if ( F_48 ( V_190 , V_186 + V_235 * V_87 ) ) {
F_37 (KERN_WARNING DRV_NAME
L_10 , pci_name(hba->pdev)) ;
V_206 = - 1 ;
break;
}
F_50 ( 1 ) ;
}
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
if ( V_206 == - 1 )
V_3 -> V_100 = V_217 ;
else
V_3 -> V_100 = V_216 ;
F_55 ( & V_3 -> V_218 ) ;
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
return V_206 ;
}
static void F_66 ( struct V_2 * V_3 )
{
F_23 ( V_236 , V_3 -> V_78 + V_237 ) ;
F_24 ( V_3 -> V_78 + V_237 ) ;
F_63 ( 5 ) ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_22 * V_23 ;
unsigned long V_167 ;
unsigned int V_100 = V_101 ;
V_34 V_76 ;
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
if ( V_3 -> V_100 == V_238 ) {
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
F_37 (KERN_INFO DRV_NAME L_11 ,
pci_name(hba->pdev)) ;
return 0 ;
}
while ( V_3 -> V_100 == V_101 ) {
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
F_68 ( V_3 -> V_218 ,
V_3 -> V_100 != V_101 ,
V_191 * V_87 ) ;
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
V_100 = V_3 -> V_100 ;
}
if ( V_100 != V_101 ) {
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
return ( V_100 == V_216 ) ? 0 : - 1 ;
}
V_3 -> V_100 = V_101 ;
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
if ( V_3 -> V_110 == V_156 )
return F_65 ( V_3 ) ;
if ( V_3 -> V_110 == V_111 )
F_58 ( V_3 ) ;
else if ( V_3 -> V_110 == V_214 )
F_66 ( V_3 ) ;
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
for ( V_76 = 0 ; V_76 < V_3 -> V_36 -> V_130 ; V_76 ++ ) {
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( V_23 -> V_16 == NULL )
continue;
V_23 -> V_16 = NULL ;
if ( V_23 -> V_9 ) {
F_39 ( V_23 -> V_9 ) ;
V_23 -> V_9 -> V_10 = V_239 << 16 ;
V_23 -> V_9 -> V_129 ( V_23 -> V_9 ) ;
V_23 -> V_9 = NULL ;
}
}
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
if ( F_54 ( V_3 ) == 0 )
return 0 ;
F_37 (KERN_WARNING DRV_NAME L_12 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
static int F_69 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) & V_9 -> V_72 -> V_36 -> V_99 [ 0 ] ;
F_70 ( V_220 , V_9 -> V_72 -> V_36 ,
L_13 ) ;
return F_67 ( V_3 ) ? V_223 : V_219 ;
}
static void F_71 ( struct V_240 * V_241 )
{
struct V_2 * V_3 = F_72 ( V_241 , struct V_2 , V_172 ) ;
F_67 ( V_3 ) ;
}
static int F_73 ( struct V_92 * V_93 ,
struct V_242 * V_243 , T_5 V_244 , int V_245 [] )
{
int V_246 = 255 , V_247 = 63 ;
if ( V_244 < 0x200000 ) {
V_246 = 64 ;
V_247 = 32 ;
}
F_74 ( V_244 , V_246 * V_247 ) ;
V_245 [ 0 ] = V_246 ;
V_245 [ 1 ] = V_247 ;
V_245 [ 2 ] = V_244 ;
return 0 ;
}
static int F_75 ( struct V_248 * V_52 )
{
int V_206 ;
if ( ! F_76 ( V_52 , F_77 ( 64 ) )
&& ! F_78 ( V_52 , F_77 ( 64 ) ) )
return 0 ;
V_206 = F_76 ( V_52 , F_77 ( 32 ) ) ;
if ( ! V_206 )
V_206 = F_78 ( V_52 , F_77 ( 32 ) ) ;
return V_206 ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_248 * V_52 = V_3 -> V_52 ;
int V_4 ;
if ( V_249 ) {
V_4 = F_80 ( V_52 ) ;
if ( V_4 != 0 )
F_37 (KERN_ERR DRV_NAME
L_14 ,
pci_name(pdev), status) ;
else
V_3 -> V_250 = 1 ;
} else
V_3 -> V_250 = 0 ;
V_4 = F_81 ( V_52 -> V_69 , V_3 -> V_110 == V_214 ?
F_46 : F_41 , V_251 , V_252 , V_3 ) ;
if ( V_4 != 0 ) {
if ( V_3 -> V_250 )
F_82 ( V_52 ) ;
}
return V_4 ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_248 * V_52 = V_3 -> V_52 ;
F_84 ( V_52 -> V_69 , V_3 ) ;
if ( V_3 -> V_250 )
F_82 ( V_52 ) ;
}
static int F_85 ( struct V_248 * V_52 , const struct V_253 * V_70 )
{
struct V_2 * V_3 ;
struct V_97 * V_36 ;
const struct V_254 * V_255 = NULL ;
V_40 V_256 , V_257 , V_258 ;
int V_213 ;
V_213 = F_86 ( V_52 ) ;
if ( V_213 )
return V_213 ;
F_87 ( V_52 ) ;
V_36 = F_88 ( & V_259 , sizeof( struct V_2 ) ) ;
if ( ! V_36 ) {
F_37 (KERN_ERR DRV_NAME L_15 ,
pci_name(pdev)) ;
V_213 = - V_260 ;
goto V_261;
}
V_3 = (struct V_2 * ) V_36 -> V_99 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_213 = F_89 ( V_52 , V_252 ) ;
if ( V_213 < 0 ) {
F_37 (KERN_ERR DRV_NAME L_16 ,
pci_name(pdev)) ;
goto V_262;
}
V_3 -> V_78 = F_90 ( V_52 , 0 ) ;
if ( ! V_3 -> V_78 ) {
F_37 (KERN_ERR DRV_NAME L_17 ,
pci_name(pdev)) ;
V_213 = - V_260 ;
goto V_263;
}
V_213 = F_75 ( V_52 ) ;
if ( V_213 ) {
F_37 (KERN_ERR DRV_NAME L_18 ,
pci_name(pdev)) ;
goto V_264;
}
V_3 -> V_110 = ( unsigned int ) V_70 -> V_265 ;
V_255 = & V_266 [ V_3 -> V_110 ] ;
V_256 = V_258 = ( V_255 -> V_20 + 1 ) * V_255 -> V_19 ;
if ( V_3 -> V_110 == V_214 )
V_256 += ( V_255 -> V_7 + 1 ) * sizeof( V_40 ) ;
V_257 = V_256 + ( V_255 -> V_7 + 1 ) * sizeof( struct V_1 ) ;
V_3 -> V_204 = V_257 + sizeof( struct V_48 ) ;
if ( V_3 -> V_110 == V_267 ||
( V_3 -> V_110 == V_268 && ( V_52 -> V_75 & 1 ) ) ) {
V_3 -> V_202 = V_3 -> V_204 ;
V_3 -> V_204 += V_269 ;
}
V_3 -> V_17 = F_91 ( & V_52 -> V_270 ,
V_3 -> V_204 , & V_3 -> V_88 , V_271 ) ;
if ( ! V_3 -> V_17 ) {
if ( V_3 -> V_110 == V_267 ||
( V_3 -> V_110 == V_268 && ( V_52 -> V_75 & 1 ) ) ) {
F_37 (KERN_WARNING DRV_NAME
L_19 ,
pci_name(pdev)) ;
V_3 -> V_204 = V_3 -> V_202
+ V_272 ;
V_3 -> V_17 = F_91 ( & V_52 -> V_270 ,
V_3 -> V_204 , & V_3 -> V_88 , V_271 ) ;
}
if ( ! V_3 -> V_17 ) {
V_213 = - V_260 ;
F_37 (KERN_ERR DRV_NAME L_20 ,
pci_name(pdev)) ;
goto V_264;
}
}
V_3 -> V_23 = F_92 ( V_255 -> V_20 , sizeof( struct V_22 ) , V_271 ) ;
if ( ! V_3 -> V_23 ) {
V_213 = - V_260 ;
F_37 (KERN_ERR DRV_NAME L_21 ,
pci_name(pdev)) ;
goto V_273;
}
if ( V_3 -> V_110 == V_214 )
V_3 -> V_175 = ( V_150 * ) ( V_3 -> V_17 + V_258 ) ;
V_3 -> V_5 = (struct V_1 * ) ( V_3 -> V_17 + V_256 ) ;
V_3 -> V_50 = V_3 -> V_17 + V_257 ;
V_3 -> V_20 = V_255 -> V_20 ;
V_3 -> V_19 = V_255 -> V_19 ;
V_3 -> V_7 = V_255 -> V_7 ;
V_3 -> V_131 = V_255 -> V_131 ;
V_3 -> V_144 = V_255 -> V_144 ;
V_3 -> V_145 = V_255 -> V_145 ;
V_3 -> V_100 = V_238 ;
if ( V_3 -> V_110 == V_214 )
V_36 -> V_37 = 38 ;
else
V_36 -> V_37 = 32 ;
V_36 -> V_130 = V_255 -> V_20 ;
V_36 -> V_193 = V_255 -> V_20 ;
V_36 -> V_112 = V_255 -> V_112 ;
V_36 -> V_115 = V_255 -> V_115 ;
V_36 -> V_274 = V_255 -> V_274 ;
V_36 -> V_275 = V_36 -> V_127 ;
V_36 -> V_276 = V_134 ;
V_3 -> V_36 = V_36 ;
V_3 -> V_52 = V_52 ;
F_93 ( & V_3 -> V_218 ) ;
snprintf ( V_3 -> V_277 , sizeof( V_3 -> V_277 ) ,
L_22 , V_36 -> V_127 ) ;
V_3 -> V_171 = F_94 ( V_3 -> V_277 ) ;
if ( ! V_3 -> V_171 ) {
F_37 (KERN_ERR DRV_NAME L_23 ,
pci_name(pdev)) ;
V_213 = - V_260 ;
goto V_278;
}
F_95 ( & V_3 -> V_172 , F_71 ) ;
V_213 = F_79 ( V_3 ) ;
if ( V_213 ) {
F_37 (KERN_ERR DRV_NAME L_24 ,
pci_name(pdev)) ;
goto V_279;
}
V_213 = F_54 ( V_3 ) ;
if ( V_213 )
goto V_280;
F_96 ( V_52 , V_3 ) ;
V_213 = F_97 ( V_36 , & V_52 -> V_270 ) ;
if ( V_213 ) {
F_37 (KERN_ERR DRV_NAME L_25 ,
pci_name(pdev)) ;
goto V_280;
}
F_98 ( V_36 ) ;
return 0 ;
V_280:
F_83 ( V_3 ) ;
V_279:
F_99 ( V_3 -> V_171 ) ;
V_278:
F_100 ( V_3 -> V_23 ) ;
V_273:
F_101 ( & V_52 -> V_270 , V_3 -> V_204 ,
V_3 -> V_17 , V_3 -> V_88 ) ;
V_264:
F_102 ( V_3 -> V_78 ) ;
V_263:
F_103 ( V_52 ) ;
V_262:
F_104 ( V_36 ) ;
V_261:
F_105 ( V_52 ) ;
return V_213 ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
struct V_21 * V_82 ;
unsigned long V_167 ;
unsigned long V_186 ;
V_34 V_76 = 0 ;
F_42 ( V_3 -> V_36 -> V_168 , V_167 ) ;
V_16 = V_3 -> V_131 ( V_3 ) ;
if ( V_3 -> V_110 == V_214 ) {
V_82 = (struct V_21 * ) V_16 - 1 ;
memset ( V_82 , 0 , V_3 -> V_19 ) ;
} else
memset ( V_16 , 0 , V_3 -> V_19 ) ;
if ( V_3 -> V_110 == V_156 || V_3 -> V_110 == V_214 ) {
V_16 -> V_133 [ 0 ] = V_149 ;
V_16 -> V_133 [ 1 ] = V_281 ;
V_16 -> V_133 [ 2 ] = V_282 ;
V_16 -> V_133 [ 3 ] = V_283 ;
} else {
V_16 -> V_133 [ 0 ] = V_284 ;
V_16 -> V_133 [ 1 ] = V_285 ;
V_16 -> V_133 [ 2 ] = V_286 ;
}
V_3 -> V_23 [ V_76 ] . V_9 = NULL ;
V_3 -> V_23 [ V_76 ] . V_33 = 0 ;
V_3 -> V_23 [ V_76 ] . V_142 = 0 ;
V_3 -> V_23 [ V_76 ] . V_13 = NULL ;
V_3 -> V_23 [ V_76 ] . V_163 = V_287 ;
V_3 -> V_145 ( V_3 , V_16 , V_76 ) ;
F_43 ( V_3 -> V_36 -> V_168 , V_167 ) ;
V_186 = V_190 ;
while ( V_3 -> V_23 [ V_76 ] . V_163 & V_287 ) {
if ( F_48 ( V_190 , V_186 + V_235 * V_87 ) ) {
V_3 -> V_23 [ V_76 ] . V_163 = 0 ;
return;
}
F_50 ( 1 ) ;
}
}
static void F_107 ( struct V_2 * V_3 )
{
F_83 ( V_3 ) ;
F_99 ( V_3 -> V_171 ) ;
F_102 ( V_3 -> V_78 ) ;
F_103 ( V_3 -> V_52 ) ;
F_100 ( V_3 -> V_23 ) ;
F_101 ( & V_3 -> V_52 -> V_270 , V_3 -> V_204 ,
V_3 -> V_17 , V_3 -> V_88 ) ;
}
static void F_108 ( struct V_248 * V_52 )
{
struct V_2 * V_3 = F_109 ( V_52 ) ;
F_110 ( V_3 -> V_36 ) ;
F_106 ( V_3 ) ;
F_107 ( V_3 ) ;
F_104 ( V_3 -> V_36 ) ;
F_105 ( V_52 ) ;
}
static void F_111 ( struct V_248 * V_52 )
{
struct V_2 * V_3 = F_109 ( V_52 ) ;
F_106 ( V_3 ) ;
}
static int T_6 F_112 ( void )
{
F_37 (KERN_INFO DRV_NAME
L_26 ,
ST_DRIVER_VERSION) ;
return F_113 ( & V_288 ) ;
}
static void T_7 F_114 ( void )
{
F_115 ( & V_288 ) ;
}
