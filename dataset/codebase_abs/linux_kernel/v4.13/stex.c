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
if ( V_3 -> V_90 == V_91 ) {
F_23 ( ( V_41 >> 16 ) >> 16 , V_3 -> V_78 + V_92 ) ;
F_23 ( V_41 , V_3 -> V_78 + V_93 ) ;
} else {
F_23 ( ( V_41 >> 16 ) >> 16 , V_3 -> V_78 + V_92 ) ;
F_24 ( V_3 -> V_78 + V_92 ) ;
F_23 ( V_41 , V_3 -> V_78 + V_93 ) ;
F_24 ( V_3 -> V_78 + V_93 ) ;
}
}
static void F_27 ( struct V_2 * V_3 , int V_4 )
{
struct V_22 * V_23 ;
unsigned long V_94 ;
V_34 V_76 ;
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
for ( V_76 = 0 ; V_76 < V_3 -> V_36 -> V_96 ; V_76 ++ ) {
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( V_23 -> V_16 == NULL )
continue;
V_23 -> V_16 = NULL ;
if ( V_23 -> V_9 ) {
F_29 ( V_23 -> V_9 ) ;
V_23 -> V_9 -> V_10 = V_4 << 16 ;
V_23 -> V_9 -> V_97 ( V_23 -> V_9 ) ;
V_23 -> V_9 = NULL ;
}
}
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
}
static int
F_31 ( struct V_98 * V_99 )
{
V_99 -> V_100 = 1 ;
V_99 -> V_101 = 1 ;
F_32 ( V_99 -> V_102 , 60 * V_87 ) ;
return 0 ;
}
static int
F_33 ( struct V_8 * V_9 , void (* F_3)( struct V_8 * ) )
{
struct V_2 * V_3 ;
struct V_103 * V_36 ;
unsigned int V_70 , V_104 ;
struct V_15 * V_16 ;
V_34 V_76 ;
V_36 = V_9 -> V_72 -> V_36 ;
V_70 = V_9 -> V_72 -> V_70 ;
V_104 = V_9 -> V_72 -> V_104 ;
V_3 = (struct V_2 * ) & V_36 -> V_105 [ 0 ] ;
if ( V_3 -> V_106 == V_107 ) {
V_9 -> V_10 = V_108 ;
F_3 ( V_9 ) ;
return 0 ;
}
if ( F_34 ( V_3 -> V_106 != V_109 ) )
return V_110 ;
switch ( V_9 -> V_111 [ 0 ] ) {
case V_112 :
{
static char V_113 [ 12 ] =
{ 0 , 0x12 , 0 , 0 , 0 , 0 , 0 , 0 , 0x8 , 0xa , 0x4 , 0 } ;
unsigned char V_114 ;
V_114 = V_9 -> V_111 [ 2 ] & 0x3f ;
if ( V_114 == 0x8 || V_114 == 0x3f ) {
F_21 ( V_9 , V_113 ,
sizeof( V_113 ) ) ;
V_9 -> V_10 = V_115 << 16 | V_116 << 8 ;
F_3 ( V_9 ) ;
} else
F_2 ( V_9 , F_3 ) ;
return 0 ;
}
case V_117 :
if ( V_3 -> V_90 == V_118 || V_70 == V_36 -> V_119 - 1 ) {
F_2 ( V_9 , F_3 ) ;
return 0 ;
}
break;
case V_120 :
if ( V_70 == V_36 -> V_119 - 1 ) {
V_9 -> V_10 = V_115 << 16 | V_116 << 8 ;
F_3 ( V_9 ) ;
return 0 ;
}
break;
case V_121 :
if ( V_104 >= V_36 -> V_122 ) {
V_9 -> V_10 = V_108 << 16 ;
F_3 ( V_9 ) ;
return 0 ;
}
if ( V_70 != V_36 -> V_119 - 1 )
break;
if ( ! V_104 && ! V_9 -> V_72 -> V_83 &&
( V_9 -> V_111 [ 1 ] & V_123 ) == 0 ) {
F_21 ( V_9 , ( void * ) V_124 ,
sizeof( V_124 ) ) ;
V_9 -> V_10 = V_115 << 16 | V_116 << 8 ;
F_3 ( V_9 ) ;
} else
F_2 ( V_9 , F_3 ) ;
return 0 ;
case V_125 :
if ( V_9 -> V_111 [ 1 ] == V_126 ) {
struct V_127 V_128 ;
T_1 V_129 = sizeof( V_128 ) ;
V_128 . V_55 = V_56 ;
V_128 . V_57 = V_58 ;
V_128 . V_59 = V_60 ;
V_128 . V_61 = V_62 ;
V_128 . V_130 [ 0 ] = V_131 ;
V_128 . V_132 = V_36 -> V_119 - 1 ;
V_128 . V_133 = V_3 -> V_36 -> V_133 ;
V_129 = F_21 ( V_9 , & V_128 , V_129 ) ;
V_9 -> V_10 = sizeof( V_128 ) == V_129 ?
V_115 << 16 | V_116 << 8 :
V_134 << 16 | V_116 << 8 ;
F_3 ( V_9 ) ;
return 0 ;
}
default:
break;
}
V_9 -> V_97 = F_3 ;
V_76 = V_9 -> V_86 -> V_76 ;
if ( F_34 ( V_76 >= V_36 -> V_96 ) )
return V_110 ;
V_16 = V_3 -> V_135 ( V_3 ) ;
V_16 -> V_104 = V_104 ;
V_16 -> V_136 = V_70 ;
memcpy ( V_16 -> V_137 , V_9 -> V_111 , V_138 ) ;
if ( V_9 -> V_139 == V_140 )
V_16 -> V_141 = V_142 ;
else if ( V_9 -> V_139 == V_143 )
V_16 -> V_141 = V_144 ;
else
V_16 -> V_141 = V_145 ;
V_3 -> V_23 [ V_76 ] . V_9 = V_9 ;
V_3 -> V_23 [ V_76 ] . V_146 = V_147 ;
V_3 -> V_23 [ V_76 ] . V_13 = V_9 -> V_13 ;
if ( ! V_3 -> V_148 ( V_3 , V_16 , & V_3 -> V_23 [ V_76 ] ) ) {
V_3 -> V_23 [ V_76 ] . V_33 = 0 ;
memset ( & V_16 -> V_32 [ 0 ] , 0 , 8 ) ;
}
V_3 -> V_149 ( V_3 , V_16 , V_76 ) ;
return 0 ;
}
void F_35 ( struct V_22 * V_23 ,
struct V_1 * V_150 , unsigned int V_32 )
{
if ( V_150 -> V_151 != V_152 ) {
if ( V_23 -> V_13 != NULL )
memcpy ( V_23 -> V_13 , V_150 -> V_32 ,
F_36 ( V_32 , V_23 -> V_146 ) ) ;
return;
}
if ( V_23 -> V_9 == NULL )
return;
F_21 ( V_23 -> V_9 , V_150 -> V_32 , V_32 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_1 * V_150 )
{
if ( V_23 -> V_9 -> V_111 [ 0 ] == V_153 &&
V_150 -> V_151 != V_12 )
F_38 ( V_23 -> V_9 , F_12 ( V_23 -> V_9 ) -
F_39 ( * ( V_154 * ) & V_150 -> V_32 [ 0 ] ) ) ;
}
static void F_40 ( struct V_2 * V_3 , V_40 V_155 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_1 * V_150 ;
struct V_22 * V_23 ;
unsigned int V_156 ;
V_34 V_76 ;
if ( F_34 ( ! ( V_155 & V_157 ) ) )
return;
V_3 -> V_158 = F_24 ( V_51 + V_159 ) ;
if ( F_34 ( V_3 -> V_158 > V_3 -> V_7 ) ) {
F_41 (KERN_WARNING DRV_NAME L_1 ,
pci_name(hba->pdev)) ;
return;
}
if ( F_34 ( V_3 -> V_77 <= 0 ||
( V_3 -> V_106 == V_160 &&
V_3 -> V_90 != V_161 ) ) ) {
V_3 -> V_6 = V_3 -> V_158 ;
goto V_162;
}
while ( V_3 -> V_6 != V_3 -> V_158 ) {
V_150 = F_1 ( V_3 ) ;
V_76 = F_42 ( V_150 -> V_76 ) ;
if ( F_34 ( V_76 >= V_3 -> V_36 -> V_96 ) ) {
F_41 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_3 -> V_77 -- ;
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( F_34 ( V_3 -> V_163 == V_23 ) )
V_3 -> V_163 = NULL ;
if ( F_34 ( V_23 -> V_16 == NULL ) ) {
F_41 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_156 = V_150 -> V_164 * sizeof( V_40 ) ;
if ( F_34 ( V_156 < sizeof( * V_150 ) - V_165 ||
V_156 > sizeof( * V_150 ) ) ) {
F_41 (KERN_WARNING DRV_NAME L_4 ,
pci_name(hba->pdev)) ;
} else {
V_156 -= sizeof( * V_150 ) - V_165 ;
if ( V_156 )
F_35 ( V_23 , V_150 , V_156 ) ;
}
V_23 -> V_16 = NULL ;
V_23 -> V_166 = V_150 -> V_166 ;
V_23 -> V_151 = V_150 -> V_151 ;
if ( F_26 ( V_23 -> V_9 != NULL ) ) {
if ( V_3 -> V_90 == V_161 )
F_37 ( V_3 , V_23 , V_150 ) ;
if ( F_34 ( V_23 -> V_9 -> V_111 [ 0 ] == V_125 &&
V_23 -> V_9 -> V_111 [ 1 ] == V_167 ) )
F_18 ( V_3 , V_23 ) ;
F_29 ( V_23 -> V_9 ) ;
F_43 ( V_23 ) ;
} else
V_23 -> V_168 = 0 ;
}
V_162:
F_23 ( V_3 -> V_158 , V_51 + V_169 ) ;
F_24 ( V_51 + V_169 ) ;
}
static T_4 F_44 ( int V_69 , void * V_170 )
{
struct V_2 * V_3 = V_170 ;
void T_3 * V_51 = V_3 -> V_78 ;
V_40 V_171 ;
unsigned long V_94 ;
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
V_171 = F_24 ( V_51 + V_172 ) ;
if ( V_171 && V_171 != 0xffffffff ) {
F_23 ( V_171 , V_51 + V_172 ) ;
F_24 ( V_51 + V_172 ) ;
F_40 ( V_3 , V_171 ) ;
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( F_34 ( V_171 & V_173 &&
V_3 -> V_90 == V_118 ) )
F_45 ( V_3 -> V_174 , & V_3 -> V_175 ) ;
return V_176 ;
}
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
return V_177 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_150 ;
struct V_22 * V_23 ;
V_154 * V_178 ;
unsigned int V_156 ;
int V_39 = 0 ;
V_40 V_179 ;
V_34 V_76 ;
if ( F_34 ( V_3 -> V_77 <= 0 ||
V_3 -> V_106 == V_160 ) )
return;
while ( V_39 < V_3 -> V_7 ) {
V_178 = V_3 -> V_178 + V_3 -> V_6 ;
V_179 = F_39 ( * V_178 ) ;
if ( F_34 ( ! ( V_179 & V_180 ) ) )
return;
V_150 = V_3 -> V_5 + V_3 -> V_6 ;
* V_178 = 0 ;
++ V_39 ;
++ V_3 -> V_6 ;
V_3 -> V_6 %= V_3 -> V_7 + 1 ;
V_76 = ( V_34 ) V_179 ;
if ( F_34 ( V_76 >= V_3 -> V_36 -> V_96 ) ) {
F_41 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_3 -> V_77 -- ;
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( F_34 ( V_3 -> V_163 == V_23 ) )
V_3 -> V_163 = NULL ;
if ( F_34 ( V_23 -> V_16 == NULL ) ) {
F_41 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_23 -> V_16 = NULL ;
if ( F_26 ( V_179 & V_181 ) ) {
V_23 -> V_166 = V_182 ;
V_23 -> V_151 = V_152 ;
} else {
V_23 -> V_166 = V_150 -> V_166 ;
V_23 -> V_151 = V_150 -> V_151 ;
V_156 = V_150 -> V_164 * sizeof( V_40 ) ;
if ( F_34 ( V_156 < sizeof( * V_150 ) - V_165 ||
V_156 > sizeof( * V_150 ) ) ) {
F_41 (KERN_WARNING DRV_NAME
L_4 ,
pci_name(hba->pdev)) ;
} else {
V_156 -= sizeof( * V_150 ) - V_165 ;
if ( V_156 )
F_35 ( V_23 , V_150 , V_156 ) ;
}
if ( F_26 ( V_23 -> V_9 != NULL ) )
F_37 ( V_3 , V_23 , V_150 ) ;
}
if ( F_26 ( V_23 -> V_9 != NULL ) ) {
F_29 ( V_23 -> V_9 ) ;
F_43 ( V_23 ) ;
} else
V_23 -> V_168 = 0 ;
}
}
static T_4 F_47 ( int V_69 , void * V_170 )
{
struct V_2 * V_3 = V_170 ;
void T_3 * V_51 = V_3 -> V_78 ;
V_40 V_171 ;
unsigned long V_94 ;
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( V_3 -> V_90 == V_183 ) {
V_171 = F_24 ( V_51 + V_184 ) ;
if ( V_171 && V_171 != 0xffffffff ) {
F_23 ( V_171 , V_51 + V_185 ) ;
F_46 ( V_3 ) ;
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( F_34 ( V_171 & V_186 ) )
F_45 ( V_3 -> V_174 , & V_3 -> V_175 ) ;
return V_176 ;
}
} else {
V_171 = F_24 ( V_51 + V_187 ) ;
if ( V_171 != 0xffffffff ) {
if ( V_171 != 0 ) {
F_23 ( V_171 , V_51 + V_188 ) ;
F_23 ( ( 1 << 22 ) , V_51 + V_189 ) ;
}
F_46 ( V_3 ) ;
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( F_34 ( V_171 & V_186 ) )
F_45 ( V_3 -> V_174 , & V_3 -> V_175 ) ;
return V_176 ;
}
}
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
return V_177 ;
}
static int F_48 ( struct V_2 * V_3 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_190 * V_191 ;
T_2 V_192 ;
V_40 V_171 ;
unsigned long V_193 ;
if ( F_24 ( V_51 + V_194 ) != V_195 ) {
F_23 ( V_196 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
V_193 = V_197 ;
while ( F_24 ( V_51 + V_194 ) != V_195 ) {
if ( F_49 ( V_197 , V_193 + V_198 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_5 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_50 () ;
F_51 ( 1 ) ;
}
}
F_52 ( 10 ) ;
V_171 = F_24 ( V_51 + V_159 ) ;
if ( ( V_171 & 0xffff0000 ) == V_199 ) {
V_171 &= 0x0000ffff ;
if ( V_3 -> V_36 -> V_96 > V_171 ) {
V_3 -> V_36 -> V_96 = V_171 ;
V_3 -> V_36 -> V_200 = V_171 ;
}
}
V_191 = (struct V_190 * ) V_3 -> V_5 ;
V_191 -> V_201 = F_15 ( V_3 -> V_88 ) ;
V_191 -> V_202 = F_10 ( V_3 -> V_19 ) ;
V_191 -> V_203 = F_10 ( V_3 -> V_20 + 1 ) ;
V_191 -> V_204 = F_10 ( sizeof( struct V_1 ) ) ;
V_191 -> V_205 = F_10 ( V_3 -> V_7 + 1 ) ;
V_191 -> V_206 = F_15 ( F_53 () ) ;
V_191 -> V_207 = V_208 ;
if ( V_3 -> V_209 ) {
V_191 -> V_209 = F_11 ( V_3 -> V_209 ) ;
V_191 -> V_210 = F_11 ( V_3 -> V_211 - V_3 -> V_209 ) ;
} else
V_191 -> V_209 = V_191 -> V_210 = 0 ;
V_192 = V_3 -> V_88 + ( V_3 -> V_20 + 1 ) * V_3 -> V_19 ;
F_23 ( V_192 , V_51 + V_79 ) ;
F_24 ( V_51 + V_79 ) ;
F_23 ( ( V_192 >> 16 ) >> 16 , V_51 + V_169 ) ;
F_24 ( V_51 + V_169 ) ;
F_23 ( ( V_192 >> 16 ) >> 16 , V_51 + V_194 ) ;
F_24 ( V_51 + V_194 ) ;
F_23 ( V_196 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
F_52 ( 10 ) ;
V_193 = V_197 ;
while ( F_24 ( V_51 + V_194 ) != V_195 ) {
if ( F_49 ( V_197 , V_193 + V_198 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_50 () ;
F_51 ( 1 ) ;
}
F_23 ( 0 , V_51 + V_79 ) ;
F_24 ( V_51 + V_79 ) ;
F_23 ( 0 , V_51 + V_194 ) ;
F_24 ( V_51 + V_194 ) ;
F_23 ( 0 , V_51 + V_169 ) ;
F_24 ( V_51 + V_169 ) ;
F_23 ( 0 , V_51 + V_159 ) ;
F_24 ( V_51 + V_159 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_21 * V_82 ;
struct V_190 * V_191 ;
V_154 * V_178 ;
V_40 V_171 , V_212 , V_213 , V_214 ;
unsigned long V_193 ;
int V_215 = 0 ;
V_193 = V_197 ;
if ( V_3 -> V_90 == V_183 ) {
V_214 = F_24 ( V_51 + V_216 ) ;
while ( V_214 != V_217 ) {
if ( F_49 ( V_197 , V_193 + V_198 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_7 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_51 ( 1 ) ;
V_214 = F_24 ( V_51 + V_216 ) ;
}
} else {
V_214 = F_24 ( V_51 + V_218 ) ;
while ( V_214 != V_217 ) {
if ( F_49 ( V_197 , V_193 + V_198 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_7 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_51 ( 1 ) ;
V_214 = F_24 ( V_51 + V_218 ) ;
}
}
V_82 = (struct V_21 * ) V_3 -> V_17 ;
V_82 -> V_89 = F_15 ( V_3 -> V_88 ) ;
V_82 -> V_219 = V_220 ;
V_191 = (struct V_190 * ) ( V_82 + 1 ) ;
V_191 -> V_201 = F_15 ( V_3 -> V_88 ) ;
V_191 -> V_202 = F_10 ( V_3 -> V_19 ) ;
V_191 -> V_203 = F_10 ( V_3 -> V_20 + 1 ) ;
V_191 -> V_204 = F_10 ( sizeof( struct V_1 ) ) ;
V_191 -> V_205 = F_10 ( V_3 -> V_7 + 1 ) ;
V_191 -> V_206 = F_15 ( F_53 () ) ;
V_191 -> V_207 = V_208 ;
V_191 -> V_209 = V_191 -> V_210 = 0 ;
V_212 = ( V_3 -> V_7 + 1 ) * sizeof( V_40 ) ;
V_191 -> V_212 = F_11 ( V_212 ) ;
if ( V_3 -> V_90 == V_183 ) {
V_171 = F_24 ( V_51 + V_221 ) ;
V_171 &= ~ 4 ;
F_23 ( V_171 , V_51 + V_221 ) ;
F_23 ( ( V_3 -> V_88 >> 16 ) >> 16 , V_51 + V_92 ) ;
F_24 ( V_51 + V_92 ) ;
F_23 ( V_3 -> V_88 , V_51 + V_93 ) ;
F_24 ( V_51 + V_93 ) ;
} else {
V_171 = F_24 ( V_51 + V_221 ) ;
V_171 &= ~ ( 1 << 0 ) ;
V_171 &= ~ ( 1 << 2 ) ;
F_23 ( V_171 , V_51 + V_221 ) ;
if ( V_3 -> V_222 == 0 ) {
F_23 ( ( 1 << 6 ) , V_51 + V_189 ) ;
V_3 -> V_222 = 1 ;
}
F_23 ( ( V_3 -> V_88 >> 16 ) >> 16 , V_51 + V_92 ) ;
F_23 ( V_3 -> V_88 , V_51 + V_93 ) ;
}
V_193 = V_197 ;
V_178 = V_3 -> V_178 ;
if ( V_3 -> V_90 == V_183 ) {
while ( ! ( F_39 ( * V_178 ) & V_223 ) ) {
if ( F_49 ( V_197 , V_193 + V_198 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
V_215 = - 1 ;
break;
}
F_50 () ;
F_51 ( 1 ) ;
}
} else {
V_213 = F_24 ( V_51 + V_224 + V_225 ) ;
while ( V_213 != V_223 ) {
if ( F_49 ( V_197 , V_193 + V_198 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
V_215 = - 1 ;
break;
}
F_50 () ;
F_51 ( 1 ) ;
V_213 = F_24 ( V_51 + V_224 + V_225 ) ;
}
}
memset ( V_178 , 0 , V_212 ) ;
V_82 -> V_219 = 0 ;
return V_215 ;
}
static int F_55 ( struct V_2 * V_3 )
{
int V_226 ;
unsigned long V_94 ;
unsigned int V_106 ;
if ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 )
V_226 = F_54 ( V_3 ) ;
else
V_226 = F_48 ( V_3 ) ;
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
V_106 = V_3 -> V_106 ;
if ( V_226 == 0 ) {
V_3 -> V_18 = 0 ;
V_3 -> V_227 = 0 ;
V_3 -> V_158 = 0 ;
V_3 -> V_6 = 0 ;
V_3 -> V_77 = 0 ;
V_3 -> V_106 = V_109 ;
} else
V_3 -> V_106 = V_228 ;
if ( V_106 == V_160 )
F_56 ( & V_3 -> V_229 ) ;
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
return V_226 ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_103 * V_36 = V_9 -> V_72 -> V_36 ;
struct V_2 * V_3 = (struct V_2 * ) V_36 -> V_105 ;
V_34 V_76 = V_9 -> V_86 -> V_76 ;
void T_3 * V_51 ;
V_40 V_171 ;
int V_10 = V_230 ;
unsigned long V_94 ;
F_58 ( V_231 , V_9 , L_8 ) ;
V_51 = V_3 -> V_78 ;
F_28 ( V_36 -> V_95 , V_94 ) ;
if ( V_76 < V_36 -> V_96 &&
V_3 -> V_23 [ V_76 ] . V_16 && V_3 -> V_23 [ V_76 ] . V_9 == V_9 )
V_3 -> V_163 = & V_3 -> V_23 [ V_76 ] ;
else
goto V_232;
if ( V_3 -> V_90 == V_183 ) {
V_171 = F_24 ( V_51 + V_184 ) ;
if ( V_171 == 0 || V_171 == 0xffffffff )
goto V_233;
F_23 ( V_171 , V_51 + V_185 ) ;
F_46 ( V_3 ) ;
} else if ( V_3 -> V_90 == V_91 ) {
V_171 = F_24 ( V_51 + V_187 ) ;
if ( V_171 == 0xffffffff )
goto V_233;
if ( V_171 != 0 ) {
F_23 ( V_171 , V_51 + V_188 ) ;
F_23 ( ( 1 << 22 ) , V_51 + V_189 ) ;
}
F_46 ( V_3 ) ;
} else {
V_171 = F_24 ( V_51 + V_172 ) ;
if ( V_171 == 0 || V_171 == 0xffffffff )
goto V_233;
F_23 ( V_171 , V_51 + V_172 ) ;
F_24 ( V_51 + V_172 ) ;
F_40 ( V_3 , V_171 ) ;
}
if ( V_3 -> V_163 == NULL ) {
F_41 (KERN_WARNING DRV_NAME
L_9 , pci_name(hba->pdev)) ;
goto V_232;
}
V_233:
F_29 ( V_9 ) ;
V_3 -> V_163 -> V_16 = NULL ;
V_3 -> V_163 = NULL ;
V_10 = V_234 ;
V_232:
F_30 ( V_36 -> V_95 , V_94 ) ;
return V_10 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_235 * V_63 ;
int V_30 ;
V_34 V_236 ;
V_84 V_237 ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
F_60 ( V_3 -> V_52 , V_30 * 4 ,
& V_3 -> V_52 -> V_238 [ V_30 ] ) ;
V_63 = V_3 -> V_52 -> V_63 ;
F_61 ( V_63 -> V_239 , V_240 , & V_237 ) ;
V_237 |= V_241 ;
F_62 ( V_63 -> V_239 , V_240 , V_237 ) ;
F_51 ( 100 ) ;
V_237 &= ~ V_241 ;
F_62 ( V_63 -> V_239 , V_240 , V_237 ) ;
for ( V_30 = 0 ; V_30 < V_242 ; V_30 ++ ) {
F_63 ( V_3 -> V_52 , V_243 , & V_236 ) ;
if ( V_236 != 0xffff && ( V_236 & V_244 ) )
break;
F_51 ( 1 ) ;
}
F_64 ( 5 ) ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
F_65 ( V_3 -> V_52 , V_30 * 4 ,
V_3 -> V_52 -> V_238 [ V_30 ] ) ;
}
static int F_66 ( struct V_2 * V_3 )
{
void T_3 * V_51 ;
unsigned long V_94 , V_193 ;
int V_215 = 0 ;
V_51 = V_3 -> V_78 ;
F_23 ( V_245 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
V_193 = V_197 ;
while ( V_3 -> V_77 > 0 ) {
if ( F_49 ( V_197 , V_193 + V_246 * V_87 ) ) {
F_41 (KERN_WARNING DRV_NAME
L_10 , pci_name(hba->pdev)) ;
V_215 = - 1 ;
break;
}
F_51 ( 1 ) ;
}
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( V_215 == - 1 )
V_3 -> V_106 = V_228 ;
else
V_3 -> V_106 = V_109 ;
F_56 ( & V_3 -> V_229 ) ;
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
return V_215 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_23 ( V_247 , V_3 -> V_78 + V_189 ) ;
F_24 ( V_3 -> V_78 + V_189 ) ;
F_64 ( 5 ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
F_23 ( V_247 , V_3 -> V_78 + V_189 ) ;
F_64 ( 5 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
unsigned long V_94 ;
unsigned int V_106 = V_160 ;
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( V_3 -> V_106 == V_248 ) {
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
F_41 (KERN_INFO DRV_NAME L_11 ,
pci_name(hba->pdev)) ;
return 0 ;
}
while ( V_3 -> V_106 == V_160 ) {
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
F_70 ( V_3 -> V_229 ,
V_3 -> V_106 != V_160 ,
V_198 * V_87 ) ;
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
V_106 = V_3 -> V_106 ;
}
if ( V_106 != V_160 ) {
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
return ( V_106 == V_109 ) ? 0 : - 1 ;
}
V_3 -> V_106 = V_160 ;
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( V_3 -> V_90 == V_161 )
return F_66 ( V_3 ) ;
if ( V_3 -> V_90 == V_118 )
F_59 ( V_3 ) ;
else if ( V_3 -> V_90 == V_183 )
F_67 ( V_3 ) ;
else if ( V_3 -> V_90 == V_91 )
F_68 ( V_3 ) ;
F_27 ( V_3 , V_249 ) ;
if ( F_55 ( V_3 ) == 0 )
return 0 ;
F_41 (KERN_WARNING DRV_NAME L_12 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
static int F_71 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) & V_9 -> V_72 -> V_36 -> V_105 [ 0 ] ;
F_72 ( V_231 , V_9 -> V_72 -> V_36 ,
L_13 ) ;
return F_69 ( V_3 ) ? V_234 : V_230 ;
}
static void F_73 ( struct V_250 * V_251 )
{
struct V_2 * V_3 = F_74 ( V_251 , struct V_2 , V_175 ) ;
F_69 ( V_3 ) ;
}
static int F_75 ( struct V_98 * V_99 ,
struct V_252 * V_253 , T_5 V_254 , int V_255 [] )
{
int V_256 = 255 , V_257 = 63 ;
if ( V_254 < 0x200000 ) {
V_256 = 64 ;
V_257 = 32 ;
}
F_76 ( V_254 , V_256 * V_257 ) ;
V_255 [ 0 ] = V_256 ;
V_255 [ 1 ] = V_257 ;
V_255 [ 2 ] = V_254 ;
return 0 ;
}
static int F_77 ( struct V_258 * V_52 )
{
int V_215 ;
if ( ! F_78 ( V_52 , F_79 ( 64 ) )
&& ! F_80 ( V_52 , F_79 ( 64 ) ) )
return 0 ;
V_215 = F_78 ( V_52 , F_79 ( 32 ) ) ;
if ( ! V_215 )
V_215 = F_80 ( V_52 , F_79 ( 32 ) ) ;
return V_215 ;
}
static int F_81 ( struct V_2 * V_3 )
{
struct V_258 * V_52 = V_3 -> V_52 ;
int V_4 ;
if ( V_259 || V_3 -> V_90 == V_91 ) {
V_4 = F_82 ( V_52 ) ;
if ( V_4 != 0 )
F_41 (KERN_ERR DRV_NAME
L_14 ,
pci_name(pdev), status) ;
else
V_3 -> V_260 = 1 ;
} else
V_3 -> V_260 = 0 ;
V_4 = F_83 ( V_52 -> V_69 ,
( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 ) ?
F_47 : F_44 , V_261 , V_262 , V_3 ) ;
if ( V_4 != 0 ) {
if ( V_3 -> V_260 )
F_84 ( V_52 ) ;
}
return V_4 ;
}
static void F_85 ( struct V_2 * V_3 )
{
struct V_258 * V_52 = V_3 -> V_52 ;
F_86 ( V_52 -> V_69 , V_3 ) ;
if ( V_3 -> V_260 )
F_84 ( V_52 ) ;
}
static int F_87 ( struct V_258 * V_52 , const struct V_263 * V_70 )
{
struct V_2 * V_3 ;
struct V_103 * V_36 ;
const struct V_264 * V_265 = NULL ;
V_40 V_266 , V_267 , V_268 ;
int V_226 ;
V_226 = F_88 ( V_52 ) ;
if ( V_226 )
return V_226 ;
F_89 ( V_52 ) ;
V_269 = 0 ;
F_90 ( & V_270 ) ;
V_36 = F_91 ( & V_271 , sizeof( struct V_2 ) ) ;
if ( ! V_36 ) {
F_41 (KERN_ERR DRV_NAME L_15 ,
pci_name(pdev)) ;
V_226 = - V_272 ;
goto V_273;
}
V_3 = (struct V_2 * ) V_36 -> V_105 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_226 = F_92 ( V_52 , V_262 ) ;
if ( V_226 < 0 ) {
F_41 (KERN_ERR DRV_NAME L_16 ,
pci_name(pdev)) ;
goto V_274;
}
V_3 -> V_78 = F_93 ( V_52 , 0 ) ;
if ( ! V_3 -> V_78 ) {
F_41 (KERN_ERR DRV_NAME L_17 ,
pci_name(pdev)) ;
V_226 = - V_272 ;
goto V_275;
}
V_226 = F_77 ( V_52 ) ;
if ( V_226 ) {
F_41 (KERN_ERR DRV_NAME L_18 ,
pci_name(pdev)) ;
goto V_276;
}
V_3 -> V_90 = ( unsigned int ) V_70 -> V_277 ;
V_265 = & V_278 [ V_3 -> V_90 ] ;
switch ( V_70 -> V_279 ) {
case 0x4221 :
case 0x4222 :
case 0x4223 :
case 0x4224 :
case 0x4225 :
case 0x4226 :
case 0x4227 :
case 0x4261 :
case 0x4262 :
case 0x4263 :
case 0x4264 :
case 0x4265 :
break;
default:
if ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 )
V_3 -> V_280 = 1 ;
}
V_266 = V_268 = ( V_265 -> V_20 + 1 ) * V_265 -> V_19 ;
if ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 )
V_266 += ( V_265 -> V_7 + 1 ) * sizeof( V_40 ) ;
V_267 = V_266 + ( V_265 -> V_7 + 1 ) * sizeof( struct V_1 ) ;
V_3 -> V_211 = V_267 + sizeof( struct V_48 ) ;
if ( V_3 -> V_90 == V_281 ||
( V_3 -> V_90 == V_282 && ( V_52 -> V_75 & 1 ) ) ) {
V_3 -> V_209 = V_3 -> V_211 ;
V_3 -> V_211 += V_283 ;
}
V_3 -> V_17 = F_94 ( & V_52 -> V_284 ,
V_3 -> V_211 , & V_3 -> V_88 , V_285 ) ;
if ( ! V_3 -> V_17 ) {
if ( V_3 -> V_90 == V_281 ||
( V_3 -> V_90 == V_282 && ( V_52 -> V_75 & 1 ) ) ) {
F_41 (KERN_WARNING DRV_NAME
L_19 ,
pci_name(pdev)) ;
V_3 -> V_211 = V_3 -> V_209
+ V_286 ;
V_3 -> V_17 = F_94 ( & V_52 -> V_284 ,
V_3 -> V_211 , & V_3 -> V_88 , V_285 ) ;
}
if ( ! V_3 -> V_17 ) {
V_226 = - V_272 ;
F_41 (KERN_ERR DRV_NAME L_20 ,
pci_name(pdev)) ;
goto V_276;
}
}
V_3 -> V_23 = F_95 ( V_265 -> V_20 , sizeof( struct V_22 ) , V_285 ) ;
if ( ! V_3 -> V_23 ) {
V_226 = - V_272 ;
F_41 (KERN_ERR DRV_NAME L_21 ,
pci_name(pdev)) ;
goto V_287;
}
if ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 )
V_3 -> V_178 = ( V_154 * ) ( V_3 -> V_17 + V_268 ) ;
V_3 -> V_5 = (struct V_1 * ) ( V_3 -> V_17 + V_266 ) ;
V_3 -> V_50 = V_3 -> V_17 + V_267 ;
V_3 -> V_20 = V_265 -> V_20 ;
V_3 -> V_19 = V_265 -> V_19 ;
V_3 -> V_7 = V_265 -> V_7 ;
V_3 -> V_135 = V_265 -> V_135 ;
V_3 -> V_148 = V_265 -> V_148 ;
V_3 -> V_149 = V_265 -> V_149 ;
V_3 -> V_106 = V_248 ;
V_3 -> V_222 = 0 ;
if ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 )
V_36 -> V_37 = 38 ;
else
V_36 -> V_37 = 32 ;
V_36 -> V_96 = V_265 -> V_20 ;
V_36 -> V_200 = V_265 -> V_20 ;
V_36 -> V_119 = V_265 -> V_119 ;
V_36 -> V_122 = V_265 -> V_122 ;
V_36 -> V_288 = V_265 -> V_288 ;
V_36 -> V_289 = V_36 -> V_133 ;
V_36 -> V_290 = V_138 ;
V_3 -> V_36 = V_36 ;
V_3 -> V_52 = V_52 ;
F_96 ( & V_3 -> V_229 ) ;
snprintf ( V_3 -> V_291 , sizeof( V_3 -> V_291 ) ,
L_22 , V_36 -> V_133 ) ;
V_3 -> V_174 = F_97 ( V_3 -> V_291 ) ;
if ( ! V_3 -> V_174 ) {
F_41 (KERN_ERR DRV_NAME L_23 ,
pci_name(pdev)) ;
V_226 = - V_272 ;
goto V_292;
}
F_98 ( & V_3 -> V_175 , F_73 ) ;
V_226 = F_81 ( V_3 ) ;
if ( V_226 ) {
F_41 (KERN_ERR DRV_NAME L_24 ,
pci_name(pdev)) ;
goto V_293;
}
V_226 = F_55 ( V_3 ) ;
if ( V_226 )
goto V_294;
F_99 ( V_52 , V_3 ) ;
V_226 = F_100 ( V_36 , & V_52 -> V_284 ) ;
if ( V_226 ) {
F_41 (KERN_ERR DRV_NAME L_25 ,
pci_name(pdev)) ;
goto V_294;
}
F_101 ( V_36 ) ;
return 0 ;
V_294:
F_85 ( V_3 ) ;
V_293:
F_102 ( V_3 -> V_174 ) ;
V_292:
F_103 ( V_3 -> V_23 ) ;
V_287:
F_104 ( & V_52 -> V_284 , V_3 -> V_211 ,
V_3 -> V_17 , V_3 -> V_88 ) ;
V_276:
F_105 ( V_3 -> V_78 ) ;
V_275:
F_106 ( V_52 ) ;
V_274:
F_107 ( V_36 ) ;
V_273:
F_108 ( V_52 ) ;
return V_226 ;
}
static void F_109 ( struct V_2 * V_3 , int V_295 )
{
struct V_15 * V_16 ;
struct V_21 * V_82 ;
unsigned long V_94 ;
unsigned long V_193 ;
V_34 V_76 = 0 ;
F_28 ( V_3 -> V_36 -> V_95 , V_94 ) ;
if ( ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 ) &&
V_3 -> V_280 == 1 ) {
if ( V_295 == V_296 ) {
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
return;
}
}
V_16 = V_3 -> V_135 ( V_3 ) ;
if ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 ) {
V_82 = (struct V_21 * ) V_16 - 1 ;
memset ( V_82 , 0 , V_3 -> V_19 ) ;
} else
memset ( V_16 , 0 , V_3 -> V_19 ) ;
if ( ( V_3 -> V_90 == V_161 || V_3 -> V_90 == V_183
|| V_3 -> V_90 == V_91 )
&& V_295 == V_297 ) {
V_16 -> V_137 [ 0 ] = V_153 ;
V_16 -> V_137 [ 1 ] = V_298 ;
V_16 -> V_137 [ 2 ] = V_299 ;
V_16 -> V_137 [ 3 ] = V_300 ;
} else if ( ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 )
&& V_295 != V_297 ) {
V_16 -> V_137 [ 0 ] = V_153 ;
V_16 -> V_137 [ 1 ] = V_298 ;
V_16 -> V_137 [ 2 ] = V_299 ;
V_16 -> V_137 [ 3 ] = V_301 ;
V_16 -> V_137 [ 4 ] = V_295 ;
} else {
V_16 -> V_137 [ 0 ] = V_302 ;
V_16 -> V_137 [ 1 ] = V_303 ;
V_16 -> V_137 [ 2 ] = V_304 ;
}
V_3 -> V_23 [ V_76 ] . V_9 = NULL ;
V_3 -> V_23 [ V_76 ] . V_33 = 0 ;
V_3 -> V_23 [ V_76 ] . V_146 = 0 ;
V_3 -> V_23 [ V_76 ] . V_13 = NULL ;
V_3 -> V_23 [ V_76 ] . V_168 = V_305 ;
V_3 -> V_149 ( V_3 , V_16 , V_76 ) ;
F_30 ( V_3 -> V_36 -> V_95 , V_94 ) ;
V_193 = V_197 ;
while ( V_3 -> V_23 [ V_76 ] . V_168 & V_305 ) {
if ( F_49 ( V_197 , V_193 + V_246 * V_87 ) ) {
V_3 -> V_23 [ V_76 ] . V_168 = 0 ;
V_3 -> V_106 = V_306 ;
return;
}
F_51 ( 1 ) ;
}
V_3 -> V_106 = V_306 ;
}
static void F_110 ( struct V_2 * V_3 )
{
F_85 ( V_3 ) ;
F_102 ( V_3 -> V_174 ) ;
F_105 ( V_3 -> V_78 ) ;
F_106 ( V_3 -> V_52 ) ;
F_103 ( V_3 -> V_23 ) ;
F_104 ( & V_3 -> V_52 -> V_284 , V_3 -> V_211 ,
V_3 -> V_17 , V_3 -> V_88 ) ;
}
static void F_111 ( struct V_258 * V_52 )
{
struct V_2 * V_3 = F_112 ( V_52 ) ;
V_3 -> V_106 = V_107 ;
F_27 ( V_3 , V_108 ) ;
F_113 ( V_3 -> V_36 ) ;
F_114 ( V_3 -> V_36 ) ;
F_110 ( V_3 ) ;
F_107 ( V_3 -> V_36 ) ;
F_108 ( V_52 ) ;
F_115 ( & V_270 ) ;
}
static void F_116 ( struct V_258 * V_52 )
{
struct V_2 * V_3 = F_112 ( V_52 ) ;
if ( V_3 -> V_280 == 0 ) {
F_109 ( V_3 , V_297 ) ;
} else if ( V_3 -> V_280 == 1 && V_269 ) {
F_115 ( & V_270 ) ;
F_109 ( V_3 , V_307 ) ;
} else
F_109 ( V_3 , V_308 ) ;
}
static int F_117 ( struct V_2 * V_3 , T_6 V_309 )
{
switch ( V_309 . V_310 ) {
case V_311 :
return V_312 ;
case V_313 :
V_3 -> V_222 = 0 ;
return V_314 ;
default:
return V_296 ;
}
}
static int F_118 ( struct V_258 * V_52 , T_6 V_309 )
{
struct V_2 * V_3 = F_112 ( V_52 ) ;
if ( ( V_3 -> V_90 == V_183 || V_3 -> V_90 == V_91 )
&& V_3 -> V_280 == 1 )
F_109 ( V_3 , F_117 ( V_3 , V_309 ) ) ;
else
F_109 ( V_3 , V_297 ) ;
return 0 ;
}
static int F_119 ( struct V_258 * V_52 )
{
struct V_2 * V_3 = F_112 ( V_52 ) ;
V_3 -> V_106 = V_248 ;
F_55 ( V_3 ) ;
return 0 ;
}
static int F_120 ( struct V_315 * V_316 , unsigned long V_310 , void * V_317 )
{
V_269 = 1 ;
return V_318 ;
}
static int T_7 F_121 ( void )
{
F_41 (KERN_INFO DRV_NAME
L_26 ,
ST_DRIVER_VERSION) ;
return F_122 ( & V_319 ) ;
}
static void T_8 F_123 ( void )
{
F_124 ( & V_319 ) ;
}
