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
V_96 -> V_98 = 1 ;
F_30 ( V_96 -> V_99 , 60 * V_90 ) ;
return 0 ;
}
static int
F_31 ( struct V_11 * V_12 , void (* F_6)( struct V_11 * ) )
{
struct V_5 * V_6 ;
struct V_100 * V_39 ;
unsigned int V_73 , V_101 ;
struct V_18 * V_19 ;
V_37 V_79 ;
V_39 = V_12 -> V_75 -> V_39 ;
V_73 = V_12 -> V_75 -> V_73 ;
V_101 = V_12 -> V_75 -> V_101 ;
V_6 = (struct V_5 * ) & V_39 -> V_102 [ 0 ] ;
if ( F_32 ( V_6 -> V_103 == V_104 ) )
return V_105 ;
switch ( V_12 -> V_106 [ 0 ] ) {
case V_107 :
{
static char V_108 [ 12 ] =
{ 0 , 0x12 , 0 , 0 , 0 , 0 , 0 , 0 , 0x8 , 0xa , 0x4 , 0 } ;
unsigned char V_109 ;
V_109 = V_12 -> V_106 [ 2 ] & 0x3f ;
if ( V_109 == 0x8 || V_109 == 0x3f ) {
F_23 ( V_12 , V_108 ,
sizeof( V_108 ) ) ;
V_12 -> V_13 = V_110 << 16 | V_111 << 8 ;
F_6 ( V_12 ) ;
} else
F_5 ( V_12 , F_6 ) ;
return 0 ;
}
case V_112 :
if ( V_6 -> V_113 == V_114 || V_73 == V_39 -> V_115 - 1 ) {
F_5 ( V_12 , F_6 ) ;
return 0 ;
}
break;
case V_116 :
if ( V_73 == V_39 -> V_115 - 1 ) {
V_12 -> V_13 = V_110 << 16 | V_111 << 8 ;
F_6 ( V_12 ) ;
return 0 ;
}
break;
case V_117 :
if ( V_101 >= V_39 -> V_118 ) {
V_12 -> V_13 = V_119 << 16 ;
F_6 ( V_12 ) ;
return 0 ;
}
if ( V_73 != V_39 -> V_115 - 1 )
break;
if ( ! V_101 && ! V_12 -> V_75 -> V_86 &&
( V_12 -> V_106 [ 1 ] & V_120 ) == 0 ) {
F_23 ( V_12 , ( void * ) V_121 ,
sizeof( V_121 ) ) ;
V_12 -> V_13 = V_110 << 16 | V_111 << 8 ;
F_6 ( V_12 ) ;
} else
F_5 ( V_12 , F_6 ) ;
return 0 ;
case V_122 :
if ( V_12 -> V_106 [ 1 ] == V_123 ) {
struct V_124 V_125 ;
T_2 V_126 = sizeof( V_125 ) ;
V_125 . V_58 = V_59 ;
V_125 . V_60 = V_61 ;
V_125 . V_62 = V_63 ;
V_125 . V_64 = V_65 ;
V_125 . V_127 [ 0 ] = V_128 ;
V_125 . V_129 = V_39 -> V_115 - 1 ;
V_125 . V_130 = V_6 -> V_39 -> V_130 ;
V_126 = F_23 ( V_12 , & V_125 , V_126 ) ;
V_12 -> V_13 = sizeof( V_125 ) == V_126 ?
V_110 << 16 | V_111 << 8 :
V_131 << 16 | V_111 << 8 ;
F_6 ( V_12 ) ;
return 0 ;
}
default:
break;
}
V_12 -> V_132 = F_6 ;
V_79 = V_12 -> V_89 -> V_79 ;
if ( F_32 ( V_79 >= V_39 -> V_133 ) )
return V_105 ;
V_19 = V_6 -> V_134 ( V_6 ) ;
V_19 -> V_101 = V_101 ;
V_19 -> V_135 = V_73 ;
memcpy ( V_19 -> V_136 , V_12 -> V_106 , V_137 ) ;
if ( V_12 -> V_138 == V_139 )
V_19 -> V_140 = V_141 ;
else if ( V_12 -> V_138 == V_142 )
V_19 -> V_140 = V_143 ;
else
V_19 -> V_140 = V_144 ;
V_6 -> V_26 [ V_79 ] . V_12 = V_12 ;
V_6 -> V_26 [ V_79 ] . V_145 = V_146 ;
V_6 -> V_26 [ V_79 ] . V_16 = V_12 -> V_16 ;
if ( ! V_6 -> V_147 ( V_6 , V_19 , & V_6 -> V_26 [ V_79 ] ) ) {
V_6 -> V_26 [ V_79 ] . V_36 = 0 ;
memset ( & V_19 -> V_35 [ 0 ] , 0 , 8 ) ;
}
V_6 -> V_148 ( V_6 , V_19 , V_79 ) ;
return 0 ;
}
void F_33 ( struct V_25 * V_26 ,
struct V_4 * V_149 , unsigned int V_35 )
{
if ( V_149 -> V_150 != V_151 ) {
if ( V_26 -> V_16 != NULL )
memcpy ( V_26 -> V_16 , V_149 -> V_35 ,
F_34 ( V_35 , V_26 -> V_145 ) ) ;
return;
}
if ( V_26 -> V_12 == NULL )
return;
F_23 ( V_26 -> V_12 , V_149 -> V_35 , V_35 ) ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_25 * V_26 , struct V_4 * V_149 )
{
if ( V_26 -> V_12 -> V_106 [ 0 ] == V_152 &&
V_149 -> V_150 != V_15 )
F_36 ( V_26 -> V_12 , F_15 ( V_26 -> V_12 ) -
F_37 ( * ( V_153 * ) & V_149 -> V_35 [ 0 ] ) ) ;
}
static void F_38 ( struct V_5 * V_6 , V_43 V_154 )
{
void T_4 * V_54 = V_6 -> V_81 ;
struct V_4 * V_149 ;
struct V_25 * V_26 ;
unsigned int V_155 ;
V_37 V_79 ;
if ( F_32 ( ! ( V_154 & V_156 ) ) )
return;
V_6 -> V_157 = F_26 ( V_54 + V_158 ) ;
if ( F_32 ( V_6 -> V_157 > V_6 -> V_10 ) ) {
F_39 (KERN_WARNING DRV_NAME L_1 ,
pci_name(hba->pdev)) ;
return;
}
if ( F_32 ( V_6 -> V_80 <= 0 ||
( V_6 -> V_103 == V_104 &&
V_6 -> V_113 != V_159 ) ) ) {
V_6 -> V_9 = V_6 -> V_157 ;
goto V_160;
}
while ( V_6 -> V_9 != V_6 -> V_157 ) {
V_149 = F_4 ( V_6 ) ;
V_79 = F_40 ( V_149 -> V_79 ) ;
if ( F_32 ( V_79 >= V_6 -> V_39 -> V_133 ) ) {
F_39 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_6 -> V_80 -- ;
V_26 = & V_6 -> V_26 [ V_79 ] ;
if ( F_32 ( V_6 -> V_161 == V_26 ) )
V_6 -> V_161 = NULL ;
if ( F_32 ( V_26 -> V_19 == NULL ) ) {
F_39 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_155 = V_149 -> V_162 * sizeof( V_43 ) ;
if ( F_32 ( V_155 < sizeof( * V_149 ) - V_163 ||
V_155 > sizeof( * V_149 ) ) ) {
F_39 (KERN_WARNING DRV_NAME L_4 ,
pci_name(hba->pdev)) ;
} else {
V_155 -= sizeof( * V_149 ) - V_163 ;
if ( V_155 )
F_33 ( V_26 , V_149 , V_155 ) ;
}
V_26 -> V_19 = NULL ;
V_26 -> V_164 = V_149 -> V_164 ;
V_26 -> V_150 = V_149 -> V_150 ;
if ( F_28 ( V_26 -> V_12 != NULL ) ) {
if ( V_6 -> V_113 == V_159 )
F_35 ( V_6 , V_26 , V_149 ) ;
if ( F_32 ( V_26 -> V_12 -> V_106 [ 0 ] == V_122 &&
V_26 -> V_12 -> V_106 [ 1 ] == V_165 ) )
F_20 ( V_6 , V_26 ) ;
F_41 ( V_26 -> V_12 ) ;
F_42 ( V_26 ) ;
} else
V_26 -> V_166 = 0 ;
}
V_160:
F_25 ( V_6 -> V_157 , V_54 + V_167 ) ;
F_26 ( V_54 + V_167 ) ;
}
static T_5 F_43 ( int V_72 , void * V_168 )
{
struct V_5 * V_6 = V_168 ;
void T_4 * V_54 = V_6 -> V_81 ;
V_43 V_169 ;
unsigned long V_170 ;
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
V_169 = F_26 ( V_54 + V_172 ) ;
if ( V_169 && V_169 != 0xffffffff ) {
F_25 ( V_169 , V_54 + V_172 ) ;
F_26 ( V_54 + V_172 ) ;
F_38 ( V_6 , V_169 ) ;
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
if ( F_32 ( V_169 & V_173 &&
V_6 -> V_113 == V_114 ) )
F_46 ( V_6 -> V_174 , & V_6 -> V_175 ) ;
return V_176 ;
}
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
return V_177 ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_4 * V_149 ;
struct V_25 * V_26 ;
V_153 * V_178 ;
unsigned int V_155 ;
int V_42 = 0 ;
V_43 V_179 ;
V_37 V_79 ;
if ( F_32 ( V_6 -> V_80 <= 0 ||
V_6 -> V_103 == V_104 ) )
return;
while ( V_42 < V_6 -> V_10 ) {
V_178 = V_6 -> V_178 + V_6 -> V_9 ;
V_179 = F_37 ( * V_178 ) ;
if ( F_32 ( ! ( V_179 & V_180 ) ) )
return;
V_149 = V_6 -> V_8 + V_6 -> V_9 ;
* V_178 = 0 ;
++ V_42 ;
++ V_6 -> V_9 ;
V_6 -> V_9 %= V_6 -> V_10 + 1 ;
V_79 = ( V_37 ) V_179 ;
if ( F_32 ( V_79 >= V_6 -> V_39 -> V_133 ) ) {
F_39 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_6 -> V_80 -- ;
V_26 = & V_6 -> V_26 [ V_79 ] ;
if ( F_32 ( V_6 -> V_161 == V_26 ) )
V_6 -> V_161 = NULL ;
if ( F_32 ( V_26 -> V_19 == NULL ) ) {
F_39 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_26 -> V_19 = NULL ;
if ( F_28 ( V_179 & V_181 ) ) {
V_26 -> V_164 = V_182 ;
V_26 -> V_150 = V_151 ;
} else {
V_26 -> V_164 = V_149 -> V_164 ;
V_26 -> V_150 = V_149 -> V_150 ;
V_155 = V_149 -> V_162 * sizeof( V_43 ) ;
if ( F_32 ( V_155 < sizeof( * V_149 ) - V_163 ||
V_155 > sizeof( * V_149 ) ) ) {
F_39 (KERN_WARNING DRV_NAME
L_4 ,
pci_name(hba->pdev)) ;
} else {
V_155 -= sizeof( * V_149 ) - V_163 ;
if ( V_155 )
F_33 ( V_26 , V_149 , V_155 ) ;
}
if ( F_28 ( V_26 -> V_12 != NULL ) )
F_35 ( V_6 , V_26 , V_149 ) ;
}
if ( F_28 ( V_26 -> V_12 != NULL ) ) {
F_41 ( V_26 -> V_12 ) ;
F_42 ( V_26 ) ;
} else
V_26 -> V_166 = 0 ;
}
}
static T_5 F_48 ( int V_72 , void * V_168 )
{
struct V_5 * V_6 = V_168 ;
void T_4 * V_54 = V_6 -> V_81 ;
V_43 V_169 ;
unsigned long V_170 ;
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
V_169 = F_26 ( V_54 + V_183 ) ;
if ( V_169 && V_169 != 0xffffffff ) {
F_25 ( V_169 , V_54 + V_184 ) ;
F_47 ( V_6 ) ;
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
if ( F_32 ( V_169 & V_185 ) )
F_46 ( V_6 -> V_174 , & V_6 -> V_175 ) ;
return V_176 ;
}
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
return V_177 ;
}
static int F_49 ( struct V_5 * V_6 )
{
void T_4 * V_54 = V_6 -> V_81 ;
struct V_186 * V_187 ;
T_3 V_188 ;
V_43 V_169 ;
unsigned long V_189 ;
if ( F_26 ( V_54 + V_190 ) != V_191 ) {
F_25 ( V_192 , V_54 + V_84 ) ;
F_26 ( V_54 + V_84 ) ;
V_189 = V_193 ;
while ( F_26 ( V_54 + V_190 ) != V_191 ) {
if ( F_50 ( V_193 , V_189 + V_194 * V_90 ) ) {
F_39 (KERN_ERR DRV_NAME
L_5 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_51 () ;
F_52 ( 1 ) ;
}
}
F_53 ( 10 ) ;
V_169 = F_26 ( V_54 + V_158 ) ;
if ( ( V_169 & 0xffff0000 ) == V_195 ) {
V_169 &= 0x0000ffff ;
if ( V_6 -> V_39 -> V_133 > V_169 ) {
V_6 -> V_39 -> V_133 = V_169 ;
V_6 -> V_39 -> V_196 = V_169 ;
}
}
V_187 = (struct V_186 * ) V_6 -> V_8 ;
V_187 -> V_197 = F_3 ( V_6 -> V_91 ) ;
V_187 -> V_198 = F_13 ( V_6 -> V_22 ) ;
V_187 -> V_199 = F_13 ( V_6 -> V_23 + 1 ) ;
V_187 -> V_200 = F_13 ( sizeof( struct V_4 ) ) ;
V_187 -> V_201 = F_13 ( V_6 -> V_10 + 1 ) ;
F_1 ( & V_187 -> V_202 ) ;
V_187 -> V_203 = V_204 ;
if ( V_6 -> V_205 ) {
V_187 -> V_205 = F_14 ( V_6 -> V_205 ) ;
V_187 -> V_206 = F_14 ( V_6 -> V_207 - V_6 -> V_205 ) ;
} else
V_187 -> V_205 = V_187 -> V_206 = 0 ;
V_188 = V_6 -> V_91 + ( V_6 -> V_23 + 1 ) * V_6 -> V_22 ;
F_25 ( V_188 , V_54 + V_82 ) ;
F_26 ( V_54 + V_82 ) ;
F_25 ( ( V_188 >> 16 ) >> 16 , V_54 + V_167 ) ;
F_26 ( V_54 + V_167 ) ;
F_25 ( ( V_188 >> 16 ) >> 16 , V_54 + V_190 ) ;
F_26 ( V_54 + V_190 ) ;
F_25 ( V_192 , V_54 + V_84 ) ;
F_26 ( V_54 + V_84 ) ;
F_53 ( 10 ) ;
V_189 = V_193 ;
while ( F_26 ( V_54 + V_190 ) != V_191 ) {
if ( F_50 ( V_193 , V_189 + V_194 * V_90 ) ) {
F_39 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_51 () ;
F_52 ( 1 ) ;
}
F_25 ( 0 , V_54 + V_82 ) ;
F_26 ( V_54 + V_82 ) ;
F_25 ( 0 , V_54 + V_190 ) ;
F_26 ( V_54 + V_190 ) ;
F_25 ( 0 , V_54 + V_167 ) ;
F_26 ( V_54 + V_167 ) ;
F_25 ( 0 , V_54 + V_158 ) ;
F_26 ( V_54 + V_158 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
void T_4 * V_54 = V_6 -> V_81 ;
struct V_24 * V_85 ;
struct V_186 * V_187 ;
V_153 * V_178 ;
V_43 V_169 , V_208 ;
unsigned long V_189 ;
int V_209 = 0 ;
V_189 = V_193 ;
while ( ( F_26 ( V_54 + V_210 ) & V_211 ) == 0 ) {
if ( F_50 ( V_193 , V_189 + V_194 * V_90 ) ) {
F_39 (KERN_ERR DRV_NAME
L_7 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_52 ( 1 ) ;
}
V_85 = (struct V_24 * ) V_6 -> V_20 ;
V_85 -> V_92 = F_3 ( V_6 -> V_91 ) ;
V_85 -> V_212 = V_213 ;
V_187 = (struct V_186 * ) ( V_85 + 1 ) ;
V_187 -> V_197 = F_3 ( V_6 -> V_91 ) ;
V_187 -> V_198 = F_13 ( V_6 -> V_22 ) ;
V_187 -> V_199 = F_13 ( V_6 -> V_23 + 1 ) ;
V_187 -> V_200 = F_13 ( sizeof( struct V_4 ) ) ;
V_187 -> V_201 = F_13 ( V_6 -> V_10 + 1 ) ;
F_1 ( & V_187 -> V_202 ) ;
V_187 -> V_203 = V_204 ;
V_187 -> V_205 = V_187 -> V_206 = 0 ;
V_208 = ( V_6 -> V_10 + 1 ) * sizeof( V_43 ) ;
V_187 -> V_208 = F_14 ( V_208 ) ;
V_169 = F_26 ( V_54 + V_214 ) ;
V_169 &= ~ 4 ;
F_25 ( V_169 , V_54 + V_214 ) ;
F_25 ( ( V_6 -> V_91 >> 16 ) >> 16 , V_54 + V_93 ) ;
F_26 ( V_54 + V_93 ) ;
F_25 ( V_6 -> V_91 , V_54 + V_94 ) ;
F_26 ( V_54 + V_94 ) ;
V_178 = V_6 -> V_178 ;
V_189 = V_193 ;
while ( ! ( F_37 ( * V_178 ) & V_215 ) ) {
if ( F_50 ( V_193 , V_189 + V_194 * V_90 ) ) {
F_39 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
V_209 = - 1 ;
break;
}
F_51 () ;
F_52 ( 1 ) ;
}
memset ( V_178 , 0 , V_208 ) ;
V_85 -> V_212 = 0 ;
return V_209 ;
}
static int F_55 ( struct V_5 * V_6 )
{
int V_216 ;
unsigned long V_170 ;
unsigned int V_103 ;
V_216 = ( V_6 -> V_113 == V_217 ) ?
F_54 ( V_6 ) : F_49 ( V_6 ) ;
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
V_103 = V_6 -> V_103 ;
if ( V_216 == 0 ) {
V_6 -> V_21 = 0 ;
V_6 -> V_218 = 0 ;
V_6 -> V_157 = 0 ;
V_6 -> V_9 = 0 ;
V_6 -> V_80 = 0 ;
V_6 -> V_103 = V_219 ;
} else
V_6 -> V_103 = V_220 ;
if ( V_103 == V_104 )
F_56 ( & V_6 -> V_221 ) ;
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
return V_216 ;
}
static int F_57 ( struct V_11 * V_12 )
{
struct V_100 * V_39 = V_12 -> V_75 -> V_39 ;
struct V_5 * V_6 = (struct V_5 * ) V_39 -> V_102 ;
V_37 V_79 = V_12 -> V_89 -> V_79 ;
void T_4 * V_54 ;
V_43 V_169 ;
int V_13 = V_222 ;
unsigned long V_170 ;
F_58 ( V_223 , V_12 , L_8 ) ;
V_54 = V_6 -> V_81 ;
F_44 ( V_39 -> V_171 , V_170 ) ;
if ( V_79 < V_39 -> V_133 &&
V_6 -> V_26 [ V_79 ] . V_19 && V_6 -> V_26 [ V_79 ] . V_12 == V_12 )
V_6 -> V_161 = & V_6 -> V_26 [ V_79 ] ;
else
goto V_224;
if ( V_6 -> V_113 == V_217 ) {
V_169 = F_26 ( V_54 + V_183 ) ;
if ( V_169 == 0 || V_169 == 0xffffffff )
goto V_225;
F_25 ( V_169 , V_54 + V_184 ) ;
F_47 ( V_6 ) ;
} else {
V_169 = F_26 ( V_54 + V_172 ) ;
if ( V_169 == 0 || V_169 == 0xffffffff )
goto V_225;
F_25 ( V_169 , V_54 + V_172 ) ;
F_26 ( V_54 + V_172 ) ;
F_38 ( V_6 , V_169 ) ;
}
if ( V_6 -> V_161 == NULL ) {
F_39 (KERN_WARNING DRV_NAME
L_9 , pci_name(hba->pdev)) ;
goto V_224;
}
V_225:
F_41 ( V_12 ) ;
V_6 -> V_161 -> V_19 = NULL ;
V_6 -> V_161 = NULL ;
V_13 = V_226 ;
V_224:
F_45 ( V_39 -> V_171 , V_170 ) ;
return V_13 ;
}
static void F_59 ( struct V_5 * V_6 )
{
struct V_227 * V_66 ;
int V_33 ;
V_37 V_228 ;
V_87 V_229 ;
for ( V_33 = 0 ; V_33 < 16 ; V_33 ++ )
F_60 ( V_6 -> V_55 , V_33 * 4 ,
& V_6 -> V_55 -> V_230 [ V_33 ] ) ;
V_66 = V_6 -> V_55 -> V_66 ;
F_61 ( V_66 -> V_231 , V_232 , & V_229 ) ;
V_229 |= V_233 ;
F_62 ( V_66 -> V_231 , V_232 , V_229 ) ;
F_52 ( 100 ) ;
V_229 &= ~ V_233 ;
F_62 ( V_66 -> V_231 , V_232 , V_229 ) ;
for ( V_33 = 0 ; V_33 < V_234 ; V_33 ++ ) {
F_63 ( V_6 -> V_55 , V_235 , & V_228 ) ;
if ( V_228 != 0xffff && ( V_228 & V_236 ) )
break;
F_52 ( 1 ) ;
}
F_64 ( 5 ) ;
for ( V_33 = 0 ; V_33 < 16 ; V_33 ++ )
F_65 ( V_6 -> V_55 , V_33 * 4 ,
V_6 -> V_55 -> V_230 [ V_33 ] ) ;
}
static int F_66 ( struct V_5 * V_6 )
{
void T_4 * V_54 ;
unsigned long V_170 , V_189 ;
int V_209 = 0 ;
V_54 = V_6 -> V_81 ;
F_25 ( V_237 , V_54 + V_84 ) ;
F_26 ( V_54 + V_84 ) ;
V_189 = V_193 ;
while ( V_6 -> V_80 > 0 ) {
if ( F_50 ( V_193 , V_189 + V_238 * V_90 ) ) {
F_39 (KERN_WARNING DRV_NAME
L_10 , pci_name(hba->pdev)) ;
V_209 = - 1 ;
break;
}
F_52 ( 1 ) ;
}
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
if ( V_209 == - 1 )
V_6 -> V_103 = V_220 ;
else
V_6 -> V_103 = V_219 ;
F_56 ( & V_6 -> V_221 ) ;
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
return V_209 ;
}
static void F_67 ( struct V_5 * V_6 )
{
F_25 ( V_239 , V_6 -> V_81 + V_240 ) ;
F_26 ( V_6 -> V_81 + V_240 ) ;
F_64 ( 5 ) ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_25 * V_26 ;
unsigned long V_170 ;
unsigned int V_103 = V_104 ;
V_37 V_79 ;
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
if ( V_6 -> V_103 == V_241 ) {
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
F_39 (KERN_INFO DRV_NAME L_11 ,
pci_name(hba->pdev)) ;
return 0 ;
}
while ( V_6 -> V_103 == V_104 ) {
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
F_69 ( V_6 -> V_221 ,
V_6 -> V_103 != V_104 ,
V_194 * V_90 ) ;
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
V_103 = V_6 -> V_103 ;
}
if ( V_103 != V_104 ) {
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
return ( V_103 == V_219 ) ? 0 : - 1 ;
}
V_6 -> V_103 = V_104 ;
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
if ( V_6 -> V_113 == V_159 )
return F_66 ( V_6 ) ;
if ( V_6 -> V_113 == V_114 )
F_59 ( V_6 ) ;
else if ( V_6 -> V_113 == V_217 )
F_67 ( V_6 ) ;
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
for ( V_79 = 0 ; V_79 < V_6 -> V_39 -> V_133 ; V_79 ++ ) {
V_26 = & V_6 -> V_26 [ V_79 ] ;
if ( V_26 -> V_19 == NULL )
continue;
V_26 -> V_19 = NULL ;
if ( V_26 -> V_12 ) {
F_41 ( V_26 -> V_12 ) ;
V_26 -> V_12 -> V_13 = V_242 << 16 ;
V_26 -> V_12 -> V_132 ( V_26 -> V_12 ) ;
V_26 -> V_12 = NULL ;
}
}
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
if ( F_55 ( V_6 ) == 0 )
return 0 ;
F_39 (KERN_WARNING DRV_NAME L_12 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
static int F_70 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) & V_12 -> V_75 -> V_39 -> V_102 [ 0 ] ;
F_71 ( V_223 , V_12 -> V_75 -> V_39 ,
L_13 ) ;
return F_68 ( V_6 ) ? V_226 : V_222 ;
}
static void F_72 ( struct V_243 * V_244 )
{
struct V_5 * V_6 = F_73 ( V_244 , struct V_5 , V_175 ) ;
F_68 ( V_6 ) ;
}
static int F_74 ( struct V_95 * V_96 ,
struct V_245 * V_246 , T_6 V_247 , int V_248 [] )
{
int V_249 = 255 , V_250 = 63 ;
if ( V_247 < 0x200000 ) {
V_249 = 64 ;
V_250 = 32 ;
}
F_75 ( V_247 , V_249 * V_250 ) ;
V_248 [ 0 ] = V_249 ;
V_248 [ 1 ] = V_250 ;
V_248 [ 2 ] = V_247 ;
return 0 ;
}
static int F_76 ( struct V_251 * V_55 )
{
int V_209 ;
if ( ! F_77 ( V_55 , F_78 ( 64 ) )
&& ! F_79 ( V_55 , F_78 ( 64 ) ) )
return 0 ;
V_209 = F_77 ( V_55 , F_78 ( 32 ) ) ;
if ( ! V_209 )
V_209 = F_79 ( V_55 , F_78 ( 32 ) ) ;
return V_209 ;
}
static int F_80 ( struct V_5 * V_6 )
{
struct V_251 * V_55 = V_6 -> V_55 ;
int V_7 ;
if ( V_252 ) {
V_7 = F_81 ( V_55 ) ;
if ( V_7 != 0 )
F_39 (KERN_ERR DRV_NAME
L_14 ,
pci_name(pdev), status) ;
else
V_6 -> V_253 = 1 ;
} else
V_6 -> V_253 = 0 ;
V_7 = F_82 ( V_55 -> V_72 , V_6 -> V_113 == V_217 ?
F_48 : F_43 , V_254 , V_255 , V_6 ) ;
if ( V_7 != 0 ) {
if ( V_6 -> V_253 )
F_83 ( V_55 ) ;
}
return V_7 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_251 * V_55 = V_6 -> V_55 ;
F_85 ( V_55 -> V_72 , V_6 ) ;
if ( V_6 -> V_253 )
F_83 ( V_55 ) ;
}
static int F_86 ( struct V_251 * V_55 , const struct V_256 * V_73 )
{
struct V_5 * V_6 ;
struct V_100 * V_39 ;
const struct V_257 * V_258 = NULL ;
V_43 V_259 , V_260 , V_261 ;
int V_216 ;
V_216 = F_87 ( V_55 ) ;
if ( V_216 )
return V_216 ;
F_88 ( V_55 ) ;
V_39 = F_89 ( & V_262 , sizeof( struct V_5 ) ) ;
if ( ! V_39 ) {
F_39 (KERN_ERR DRV_NAME L_15 ,
pci_name(pdev)) ;
V_216 = - V_263 ;
goto V_264;
}
V_6 = (struct V_5 * ) V_39 -> V_102 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_216 = F_90 ( V_55 , V_255 ) ;
if ( V_216 < 0 ) {
F_39 (KERN_ERR DRV_NAME L_16 ,
pci_name(pdev)) ;
goto V_265;
}
V_6 -> V_81 = F_91 ( V_55 , 0 ) ;
if ( ! V_6 -> V_81 ) {
F_39 (KERN_ERR DRV_NAME L_17 ,
pci_name(pdev)) ;
V_216 = - V_263 ;
goto V_266;
}
V_216 = F_76 ( V_55 ) ;
if ( V_216 ) {
F_39 (KERN_ERR DRV_NAME L_18 ,
pci_name(pdev)) ;
goto V_267;
}
V_6 -> V_113 = ( unsigned int ) V_73 -> V_268 ;
V_258 = & V_269 [ V_6 -> V_113 ] ;
V_259 = V_261 = ( V_258 -> V_23 + 1 ) * V_258 -> V_22 ;
if ( V_6 -> V_113 == V_217 )
V_259 += ( V_258 -> V_10 + 1 ) * sizeof( V_43 ) ;
V_260 = V_259 + ( V_258 -> V_10 + 1 ) * sizeof( struct V_4 ) ;
V_6 -> V_207 = V_260 + sizeof( struct V_51 ) ;
if ( V_6 -> V_113 == V_270 ||
( V_6 -> V_113 == V_271 && ( V_55 -> V_78 & 1 ) ) ) {
V_6 -> V_205 = V_6 -> V_207 ;
V_6 -> V_207 += V_272 ;
}
V_6 -> V_20 = F_92 ( & V_55 -> V_273 ,
V_6 -> V_207 , & V_6 -> V_91 , V_274 ) ;
if ( ! V_6 -> V_20 ) {
if ( V_6 -> V_113 == V_270 ||
( V_6 -> V_113 == V_271 && ( V_55 -> V_78 & 1 ) ) ) {
F_39 (KERN_WARNING DRV_NAME
L_19 ,
pci_name(pdev)) ;
V_6 -> V_207 = V_6 -> V_205
+ V_275 ;
V_6 -> V_20 = F_92 ( & V_55 -> V_273 ,
V_6 -> V_207 , & V_6 -> V_91 , V_274 ) ;
}
if ( ! V_6 -> V_20 ) {
V_216 = - V_263 ;
F_39 (KERN_ERR DRV_NAME L_20 ,
pci_name(pdev)) ;
goto V_267;
}
}
V_6 -> V_26 = F_93 ( V_258 -> V_23 , sizeof( struct V_25 ) , V_274 ) ;
if ( ! V_6 -> V_26 ) {
V_216 = - V_263 ;
F_39 (KERN_ERR DRV_NAME L_21 ,
pci_name(pdev)) ;
goto V_276;
}
if ( V_6 -> V_113 == V_217 )
V_6 -> V_178 = ( V_153 * ) ( V_6 -> V_20 + V_261 ) ;
V_6 -> V_8 = (struct V_4 * ) ( V_6 -> V_20 + V_259 ) ;
V_6 -> V_53 = V_6 -> V_20 + V_260 ;
V_6 -> V_23 = V_258 -> V_23 ;
V_6 -> V_22 = V_258 -> V_22 ;
V_6 -> V_10 = V_258 -> V_10 ;
V_6 -> V_134 = V_258 -> V_134 ;
V_6 -> V_147 = V_258 -> V_147 ;
V_6 -> V_148 = V_258 -> V_148 ;
V_6 -> V_103 = V_241 ;
if ( V_6 -> V_113 == V_217 )
V_39 -> V_40 = 38 ;
else
V_39 -> V_40 = 32 ;
V_39 -> V_133 = V_258 -> V_23 ;
V_39 -> V_196 = V_258 -> V_23 ;
V_39 -> V_115 = V_258 -> V_115 ;
V_39 -> V_118 = V_258 -> V_118 ;
V_39 -> V_277 = V_258 -> V_277 ;
V_39 -> V_278 = V_39 -> V_130 ;
V_39 -> V_279 = V_137 ;
V_6 -> V_39 = V_39 ;
V_6 -> V_55 = V_55 ;
F_94 ( & V_6 -> V_221 ) ;
snprintf ( V_6 -> V_280 , sizeof( V_6 -> V_280 ) ,
L_22 , V_39 -> V_130 ) ;
V_6 -> V_174 = F_95 ( V_6 -> V_280 ) ;
if ( ! V_6 -> V_174 ) {
F_39 (KERN_ERR DRV_NAME L_23 ,
pci_name(pdev)) ;
V_216 = - V_263 ;
goto V_281;
}
F_96 ( & V_6 -> V_175 , F_72 ) ;
V_216 = F_80 ( V_6 ) ;
if ( V_216 ) {
F_39 (KERN_ERR DRV_NAME L_24 ,
pci_name(pdev)) ;
goto V_282;
}
V_216 = F_55 ( V_6 ) ;
if ( V_216 )
goto V_283;
V_216 = F_97 ( V_39 , V_39 -> V_133 ) ;
if ( V_216 ) {
F_39 (KERN_ERR DRV_NAME L_25 ,
pci_name(pdev)) ;
goto V_283;
}
F_98 ( V_55 , V_6 ) ;
V_216 = F_99 ( V_39 , & V_55 -> V_273 ) ;
if ( V_216 ) {
F_39 (KERN_ERR DRV_NAME L_26 ,
pci_name(pdev)) ;
goto V_283;
}
F_100 ( V_39 ) ;
return 0 ;
V_283:
F_84 ( V_6 ) ;
V_282:
F_101 ( V_6 -> V_174 ) ;
V_281:
F_102 ( V_6 -> V_26 ) ;
V_276:
F_103 ( & V_55 -> V_273 , V_6 -> V_207 ,
V_6 -> V_20 , V_6 -> V_91 ) ;
V_267:
F_104 ( V_6 -> V_81 ) ;
V_266:
F_105 ( V_55 ) ;
V_265:
F_106 ( V_39 ) ;
V_264:
F_107 ( V_55 ) ;
return V_216 ;
}
static void F_108 ( struct V_5 * V_6 )
{
struct V_18 * V_19 ;
struct V_24 * V_85 ;
unsigned long V_170 ;
unsigned long V_189 ;
V_37 V_79 = 0 ;
F_44 ( V_6 -> V_39 -> V_171 , V_170 ) ;
V_19 = V_6 -> V_134 ( V_6 ) ;
if ( V_6 -> V_113 == V_217 ) {
V_85 = (struct V_24 * ) V_19 - 1 ;
memset ( V_85 , 0 , V_6 -> V_22 ) ;
} else
memset ( V_19 , 0 , V_6 -> V_22 ) ;
if ( V_6 -> V_113 == V_159 || V_6 -> V_113 == V_217 ) {
V_19 -> V_136 [ 0 ] = V_152 ;
V_19 -> V_136 [ 1 ] = V_284 ;
V_19 -> V_136 [ 2 ] = V_285 ;
V_19 -> V_136 [ 3 ] = V_286 ;
} else {
V_19 -> V_136 [ 0 ] = V_287 ;
V_19 -> V_136 [ 1 ] = V_288 ;
V_19 -> V_136 [ 2 ] = V_289 ;
}
V_6 -> V_26 [ V_79 ] . V_12 = NULL ;
V_6 -> V_26 [ V_79 ] . V_36 = 0 ;
V_6 -> V_26 [ V_79 ] . V_145 = 0 ;
V_6 -> V_26 [ V_79 ] . V_16 = NULL ;
V_6 -> V_26 [ V_79 ] . V_166 = V_290 ;
V_6 -> V_148 ( V_6 , V_19 , V_79 ) ;
F_45 ( V_6 -> V_39 -> V_171 , V_170 ) ;
V_189 = V_193 ;
while ( V_6 -> V_26 [ V_79 ] . V_166 & V_290 ) {
if ( F_50 ( V_193 , V_189 + V_238 * V_90 ) ) {
V_6 -> V_26 [ V_79 ] . V_166 = 0 ;
return;
}
F_52 ( 1 ) ;
}
}
static void F_109 ( struct V_5 * V_6 )
{
F_84 ( V_6 ) ;
F_101 ( V_6 -> V_174 ) ;
F_104 ( V_6 -> V_81 ) ;
F_105 ( V_6 -> V_55 ) ;
F_102 ( V_6 -> V_26 ) ;
F_103 ( & V_6 -> V_55 -> V_273 , V_6 -> V_207 ,
V_6 -> V_20 , V_6 -> V_91 ) ;
}
static void F_110 ( struct V_251 * V_55 )
{
struct V_5 * V_6 = F_111 ( V_55 ) ;
F_112 ( V_6 -> V_39 ) ;
F_108 ( V_6 ) ;
F_109 ( V_6 ) ;
F_106 ( V_6 -> V_39 ) ;
F_107 ( V_55 ) ;
}
static void F_113 ( struct V_251 * V_55 )
{
struct V_5 * V_6 = F_111 ( V_55 ) ;
F_108 ( V_6 ) ;
}
static int T_7 F_114 ( void )
{
F_39 (KERN_INFO DRV_NAME
L_27 ,
ST_DRIVER_VERSION) ;
return F_115 ( & V_291 ) ;
}
static void T_8 F_116 ( void )
{
F_117 ( & V_291 ) ;
}
