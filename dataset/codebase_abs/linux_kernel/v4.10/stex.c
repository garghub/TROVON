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
static void F_27 ( struct V_2 * V_3 , int V_4 )
{
struct V_22 * V_23 ;
unsigned long V_92 ;
V_34 V_76 ;
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
for ( V_76 = 0 ; V_76 < V_3 -> V_36 -> V_94 ; V_76 ++ ) {
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( V_23 -> V_16 == NULL )
continue;
V_23 -> V_16 = NULL ;
if ( V_23 -> V_9 ) {
F_29 ( V_23 -> V_9 ) ;
V_23 -> V_9 -> V_10 = V_4 << 16 ;
V_23 -> V_9 -> V_95 ( V_23 -> V_9 ) ;
V_23 -> V_9 = NULL ;
}
}
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
}
static int
F_31 ( struct V_96 * V_97 )
{
V_97 -> V_98 = 1 ;
V_97 -> V_99 = 1 ;
F_32 ( V_97 -> V_100 , 60 * V_87 ) ;
return 0 ;
}
static int
F_33 ( struct V_8 * V_9 , void (* F_3)( struct V_8 * ) )
{
struct V_2 * V_3 ;
struct V_101 * V_36 ;
unsigned int V_70 , V_102 ;
struct V_15 * V_16 ;
V_34 V_76 ;
V_36 = V_9 -> V_72 -> V_36 ;
V_70 = V_9 -> V_72 -> V_70 ;
V_102 = V_9 -> V_72 -> V_102 ;
V_3 = (struct V_2 * ) & V_36 -> V_103 [ 0 ] ;
if ( V_3 -> V_104 == V_105 ) {
V_9 -> V_10 = V_106 ;
F_3 ( V_9 ) ;
return 0 ;
}
if ( F_34 ( V_3 -> V_104 != V_107 ) )
return V_108 ;
switch ( V_9 -> V_109 [ 0 ] ) {
case V_110 :
{
static char V_111 [ 12 ] =
{ 0 , 0x12 , 0 , 0 , 0 , 0 , 0 , 0 , 0x8 , 0xa , 0x4 , 0 } ;
unsigned char V_112 ;
V_112 = V_9 -> V_109 [ 2 ] & 0x3f ;
if ( V_112 == 0x8 || V_112 == 0x3f ) {
F_21 ( V_9 , V_111 ,
sizeof( V_111 ) ) ;
V_9 -> V_10 = V_113 << 16 | V_114 << 8 ;
F_3 ( V_9 ) ;
} else
F_2 ( V_9 , F_3 ) ;
return 0 ;
}
case V_115 :
if ( V_3 -> V_116 == V_117 || V_70 == V_36 -> V_118 - 1 ) {
F_2 ( V_9 , F_3 ) ;
return 0 ;
}
break;
case V_119 :
if ( V_70 == V_36 -> V_118 - 1 ) {
V_9 -> V_10 = V_113 << 16 | V_114 << 8 ;
F_3 ( V_9 ) ;
return 0 ;
}
break;
case V_120 :
if ( V_102 >= V_36 -> V_121 ) {
V_9 -> V_10 = V_106 << 16 ;
F_3 ( V_9 ) ;
return 0 ;
}
if ( V_70 != V_36 -> V_118 - 1 )
break;
if ( ! V_102 && ! V_9 -> V_72 -> V_83 &&
( V_9 -> V_109 [ 1 ] & V_122 ) == 0 ) {
F_21 ( V_9 , ( void * ) V_123 ,
sizeof( V_123 ) ) ;
V_9 -> V_10 = V_113 << 16 | V_114 << 8 ;
F_3 ( V_9 ) ;
} else
F_2 ( V_9 , F_3 ) ;
return 0 ;
case V_124 :
if ( V_9 -> V_109 [ 1 ] == V_125 ) {
struct V_126 V_127 ;
T_1 V_128 = sizeof( V_127 ) ;
V_127 . V_55 = V_56 ;
V_127 . V_57 = V_58 ;
V_127 . V_59 = V_60 ;
V_127 . V_61 = V_62 ;
V_127 . V_129 [ 0 ] = V_130 ;
V_127 . V_131 = V_36 -> V_118 - 1 ;
V_127 . V_132 = V_3 -> V_36 -> V_132 ;
V_128 = F_21 ( V_9 , & V_127 , V_128 ) ;
V_9 -> V_10 = sizeof( V_127 ) == V_128 ?
V_113 << 16 | V_114 << 8 :
V_133 << 16 | V_114 << 8 ;
F_3 ( V_9 ) ;
return 0 ;
}
default:
break;
}
V_9 -> V_95 = F_3 ;
V_76 = V_9 -> V_86 -> V_76 ;
if ( F_34 ( V_76 >= V_36 -> V_94 ) )
return V_108 ;
V_16 = V_3 -> V_134 ( V_3 ) ;
V_16 -> V_102 = V_102 ;
V_16 -> V_135 = V_70 ;
memcpy ( V_16 -> V_136 , V_9 -> V_109 , V_137 ) ;
if ( V_9 -> V_138 == V_139 )
V_16 -> V_140 = V_141 ;
else if ( V_9 -> V_138 == V_142 )
V_16 -> V_140 = V_143 ;
else
V_16 -> V_140 = V_144 ;
V_3 -> V_23 [ V_76 ] . V_9 = V_9 ;
V_3 -> V_23 [ V_76 ] . V_145 = V_146 ;
V_3 -> V_23 [ V_76 ] . V_13 = V_9 -> V_13 ;
if ( ! V_3 -> V_147 ( V_3 , V_16 , & V_3 -> V_23 [ V_76 ] ) ) {
V_3 -> V_23 [ V_76 ] . V_33 = 0 ;
memset ( & V_16 -> V_32 [ 0 ] , 0 , 8 ) ;
}
V_3 -> V_148 ( V_3 , V_16 , V_76 ) ;
return 0 ;
}
void F_35 ( struct V_22 * V_23 ,
struct V_1 * V_149 , unsigned int V_32 )
{
if ( V_149 -> V_150 != V_151 ) {
if ( V_23 -> V_13 != NULL )
memcpy ( V_23 -> V_13 , V_149 -> V_32 ,
F_36 ( V_32 , V_23 -> V_145 ) ) ;
return;
}
if ( V_23 -> V_9 == NULL )
return;
F_21 ( V_23 -> V_9 , V_149 -> V_32 , V_32 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_1 * V_149 )
{
if ( V_23 -> V_9 -> V_109 [ 0 ] == V_152 &&
V_149 -> V_150 != V_12 )
F_38 ( V_23 -> V_9 , F_12 ( V_23 -> V_9 ) -
F_39 ( * ( V_153 * ) & V_149 -> V_32 [ 0 ] ) ) ;
}
static void F_40 ( struct V_2 * V_3 , V_40 V_154 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_1 * V_149 ;
struct V_22 * V_23 ;
unsigned int V_155 ;
V_34 V_76 ;
if ( F_34 ( ! ( V_154 & V_156 ) ) )
return;
V_3 -> V_157 = F_24 ( V_51 + V_158 ) ;
if ( F_34 ( V_3 -> V_157 > V_3 -> V_7 ) ) {
F_41 (KERN_WARNING DRV_NAME L_1 ,
pci_name(hba->pdev)) ;
return;
}
if ( F_34 ( V_3 -> V_77 <= 0 ||
( V_3 -> V_104 == V_159 &&
V_3 -> V_116 != V_160 ) ) ) {
V_3 -> V_6 = V_3 -> V_157 ;
goto V_161;
}
while ( V_3 -> V_6 != V_3 -> V_157 ) {
V_149 = F_1 ( V_3 ) ;
V_76 = F_42 ( V_149 -> V_76 ) ;
if ( F_34 ( V_76 >= V_3 -> V_36 -> V_94 ) ) {
F_41 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_3 -> V_77 -- ;
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( F_34 ( V_3 -> V_162 == V_23 ) )
V_3 -> V_162 = NULL ;
if ( F_34 ( V_23 -> V_16 == NULL ) ) {
F_41 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_155 = V_149 -> V_163 * sizeof( V_40 ) ;
if ( F_34 ( V_155 < sizeof( * V_149 ) - V_164 ||
V_155 > sizeof( * V_149 ) ) ) {
F_41 (KERN_WARNING DRV_NAME L_4 ,
pci_name(hba->pdev)) ;
} else {
V_155 -= sizeof( * V_149 ) - V_164 ;
if ( V_155 )
F_35 ( V_23 , V_149 , V_155 ) ;
}
V_23 -> V_16 = NULL ;
V_23 -> V_165 = V_149 -> V_165 ;
V_23 -> V_150 = V_149 -> V_150 ;
if ( F_26 ( V_23 -> V_9 != NULL ) ) {
if ( V_3 -> V_116 == V_160 )
F_37 ( V_3 , V_23 , V_149 ) ;
if ( F_34 ( V_23 -> V_9 -> V_109 [ 0 ] == V_124 &&
V_23 -> V_9 -> V_109 [ 1 ] == V_166 ) )
F_18 ( V_3 , V_23 ) ;
F_29 ( V_23 -> V_9 ) ;
F_43 ( V_23 ) ;
} else
V_23 -> V_167 = 0 ;
}
V_161:
F_23 ( V_3 -> V_157 , V_51 + V_168 ) ;
F_24 ( V_51 + V_168 ) ;
}
static T_4 F_44 ( int V_69 , void * V_169 )
{
struct V_2 * V_3 = V_169 ;
void T_3 * V_51 = V_3 -> V_78 ;
V_40 V_170 ;
unsigned long V_92 ;
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
V_170 = F_24 ( V_51 + V_171 ) ;
if ( V_170 && V_170 != 0xffffffff ) {
F_23 ( V_170 , V_51 + V_171 ) ;
F_24 ( V_51 + V_171 ) ;
F_40 ( V_3 , V_170 ) ;
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
if ( F_34 ( V_170 & V_172 &&
V_3 -> V_116 == V_117 ) )
F_45 ( V_3 -> V_173 , & V_3 -> V_174 ) ;
return V_175 ;
}
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
return V_176 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_149 ;
struct V_22 * V_23 ;
V_153 * V_177 ;
unsigned int V_155 ;
int V_39 = 0 ;
V_40 V_178 ;
V_34 V_76 ;
if ( F_34 ( V_3 -> V_77 <= 0 ||
V_3 -> V_104 == V_159 ) )
return;
while ( V_39 < V_3 -> V_7 ) {
V_177 = V_3 -> V_177 + V_3 -> V_6 ;
V_178 = F_39 ( * V_177 ) ;
if ( F_34 ( ! ( V_178 & V_179 ) ) )
return;
V_149 = V_3 -> V_5 + V_3 -> V_6 ;
* V_177 = 0 ;
++ V_39 ;
++ V_3 -> V_6 ;
V_3 -> V_6 %= V_3 -> V_7 + 1 ;
V_76 = ( V_34 ) V_178 ;
if ( F_34 ( V_76 >= V_3 -> V_36 -> V_94 ) ) {
F_41 (KERN_WARNING DRV_NAME
L_2 , pci_name(hba->pdev)) ;
continue;
}
V_3 -> V_77 -- ;
V_23 = & V_3 -> V_23 [ V_76 ] ;
if ( F_34 ( V_3 -> V_162 == V_23 ) )
V_3 -> V_162 = NULL ;
if ( F_34 ( V_23 -> V_16 == NULL ) ) {
F_41 (KERN_WARNING DRV_NAME
L_3 , pci_name(hba->pdev)) ;
continue;
}
V_23 -> V_16 = NULL ;
if ( F_26 ( V_178 & V_180 ) ) {
V_23 -> V_165 = V_181 ;
V_23 -> V_150 = V_151 ;
} else {
V_23 -> V_165 = V_149 -> V_165 ;
V_23 -> V_150 = V_149 -> V_150 ;
V_155 = V_149 -> V_163 * sizeof( V_40 ) ;
if ( F_34 ( V_155 < sizeof( * V_149 ) - V_164 ||
V_155 > sizeof( * V_149 ) ) ) {
F_41 (KERN_WARNING DRV_NAME
L_4 ,
pci_name(hba->pdev)) ;
} else {
V_155 -= sizeof( * V_149 ) - V_164 ;
if ( V_155 )
F_35 ( V_23 , V_149 , V_155 ) ;
}
if ( F_26 ( V_23 -> V_9 != NULL ) )
F_37 ( V_3 , V_23 , V_149 ) ;
}
if ( F_26 ( V_23 -> V_9 != NULL ) ) {
F_29 ( V_23 -> V_9 ) ;
F_43 ( V_23 ) ;
} else
V_23 -> V_167 = 0 ;
}
}
static T_4 F_47 ( int V_69 , void * V_169 )
{
struct V_2 * V_3 = V_169 ;
void T_3 * V_51 = V_3 -> V_78 ;
V_40 V_170 ;
unsigned long V_92 ;
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
V_170 = F_24 ( V_51 + V_182 ) ;
if ( V_170 && V_170 != 0xffffffff ) {
F_23 ( V_170 , V_51 + V_183 ) ;
F_46 ( V_3 ) ;
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
if ( F_34 ( V_170 & V_184 ) )
F_45 ( V_3 -> V_173 , & V_3 -> V_174 ) ;
return V_175 ;
}
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
return V_176 ;
}
static int F_48 ( struct V_2 * V_3 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_185 * V_186 ;
T_2 V_187 ;
V_40 V_170 ;
unsigned long V_188 ;
if ( F_24 ( V_51 + V_189 ) != V_190 ) {
F_23 ( V_191 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
V_188 = V_192 ;
while ( F_24 ( V_51 + V_189 ) != V_190 ) {
if ( F_49 ( V_192 , V_188 + V_193 * V_87 ) ) {
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
V_170 = F_24 ( V_51 + V_158 ) ;
if ( ( V_170 & 0xffff0000 ) == V_194 ) {
V_170 &= 0x0000ffff ;
if ( V_3 -> V_36 -> V_94 > V_170 ) {
V_3 -> V_36 -> V_94 = V_170 ;
V_3 -> V_36 -> V_195 = V_170 ;
}
}
V_186 = (struct V_185 * ) V_3 -> V_5 ;
V_186 -> V_196 = F_15 ( V_3 -> V_88 ) ;
V_186 -> V_197 = F_10 ( V_3 -> V_19 ) ;
V_186 -> V_198 = F_10 ( V_3 -> V_20 + 1 ) ;
V_186 -> V_199 = F_10 ( sizeof( struct V_1 ) ) ;
V_186 -> V_200 = F_10 ( V_3 -> V_7 + 1 ) ;
V_186 -> V_201 = F_15 ( F_53 () ) ;
V_186 -> V_202 = V_203 ;
if ( V_3 -> V_204 ) {
V_186 -> V_204 = F_11 ( V_3 -> V_204 ) ;
V_186 -> V_205 = F_11 ( V_3 -> V_206 - V_3 -> V_204 ) ;
} else
V_186 -> V_204 = V_186 -> V_205 = 0 ;
V_187 = V_3 -> V_88 + ( V_3 -> V_20 + 1 ) * V_3 -> V_19 ;
F_23 ( V_187 , V_51 + V_79 ) ;
F_24 ( V_51 + V_79 ) ;
F_23 ( ( V_187 >> 16 ) >> 16 , V_51 + V_168 ) ;
F_24 ( V_51 + V_168 ) ;
F_23 ( ( V_187 >> 16 ) >> 16 , V_51 + V_189 ) ;
F_24 ( V_51 + V_189 ) ;
F_23 ( V_191 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
F_52 ( 10 ) ;
V_188 = V_192 ;
while ( F_24 ( V_51 + V_189 ) != V_190 ) {
if ( F_49 ( V_192 , V_188 + V_193 * V_87 ) ) {
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
F_23 ( 0 , V_51 + V_189 ) ;
F_24 ( V_51 + V_189 ) ;
F_23 ( 0 , V_51 + V_168 ) ;
F_24 ( V_51 + V_168 ) ;
F_23 ( 0 , V_51 + V_158 ) ;
F_24 ( V_51 + V_158 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 )
{
void T_3 * V_51 = V_3 -> V_78 ;
struct V_21 * V_82 ;
struct V_185 * V_186 ;
V_153 * V_177 ;
V_40 V_170 , V_207 ;
unsigned long V_188 ;
int V_208 = 0 ;
V_188 = V_192 ;
while ( ( F_24 ( V_51 + V_209 ) & V_210 ) == 0 ) {
if ( F_49 ( V_192 , V_188 + V_193 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_7 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
F_51 ( 1 ) ;
}
V_82 = (struct V_21 * ) V_3 -> V_17 ;
V_82 -> V_89 = F_15 ( V_3 -> V_88 ) ;
V_82 -> V_211 = V_212 ;
V_186 = (struct V_185 * ) ( V_82 + 1 ) ;
V_186 -> V_196 = F_15 ( V_3 -> V_88 ) ;
V_186 -> V_197 = F_10 ( V_3 -> V_19 ) ;
V_186 -> V_198 = F_10 ( V_3 -> V_20 + 1 ) ;
V_186 -> V_199 = F_10 ( sizeof( struct V_1 ) ) ;
V_186 -> V_200 = F_10 ( V_3 -> V_7 + 1 ) ;
V_186 -> V_201 = F_15 ( F_53 () ) ;
V_186 -> V_202 = V_203 ;
V_186 -> V_204 = V_186 -> V_205 = 0 ;
V_207 = ( V_3 -> V_7 + 1 ) * sizeof( V_40 ) ;
V_186 -> V_207 = F_11 ( V_207 ) ;
V_170 = F_24 ( V_51 + V_213 ) ;
V_170 &= ~ 4 ;
F_23 ( V_170 , V_51 + V_213 ) ;
F_23 ( ( V_3 -> V_88 >> 16 ) >> 16 , V_51 + V_90 ) ;
F_24 ( V_51 + V_90 ) ;
F_23 ( V_3 -> V_88 , V_51 + V_91 ) ;
F_24 ( V_51 + V_91 ) ;
V_177 = V_3 -> V_177 ;
V_188 = V_192 ;
while ( ! ( F_39 ( * V_177 ) & V_214 ) ) {
if ( F_49 ( V_192 , V_188 + V_193 * V_87 ) ) {
F_41 (KERN_ERR DRV_NAME
L_6 ,
pci_name(hba->pdev)) ;
V_208 = - 1 ;
break;
}
F_50 () ;
F_51 ( 1 ) ;
}
memset ( V_177 , 0 , V_207 ) ;
V_82 -> V_211 = 0 ;
return V_208 ;
}
static int F_55 ( struct V_2 * V_3 )
{
int V_215 ;
unsigned long V_92 ;
unsigned int V_104 ;
V_215 = ( V_3 -> V_116 == V_216 ) ?
F_54 ( V_3 ) : F_48 ( V_3 ) ;
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
V_104 = V_3 -> V_104 ;
if ( V_215 == 0 ) {
V_3 -> V_18 = 0 ;
V_3 -> V_217 = 0 ;
V_3 -> V_157 = 0 ;
V_3 -> V_6 = 0 ;
V_3 -> V_77 = 0 ;
V_3 -> V_104 = V_107 ;
} else
V_3 -> V_104 = V_218 ;
if ( V_104 == V_159 )
F_56 ( & V_3 -> V_219 ) ;
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
return V_215 ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_101 * V_36 = V_9 -> V_72 -> V_36 ;
struct V_2 * V_3 = (struct V_2 * ) V_36 -> V_103 ;
V_34 V_76 = V_9 -> V_86 -> V_76 ;
void T_3 * V_51 ;
V_40 V_170 ;
int V_10 = V_220 ;
unsigned long V_92 ;
F_58 ( V_221 , V_9 , L_8 ) ;
V_51 = V_3 -> V_78 ;
F_28 ( V_36 -> V_93 , V_92 ) ;
if ( V_76 < V_36 -> V_94 &&
V_3 -> V_23 [ V_76 ] . V_16 && V_3 -> V_23 [ V_76 ] . V_9 == V_9 )
V_3 -> V_162 = & V_3 -> V_23 [ V_76 ] ;
else
goto V_222;
if ( V_3 -> V_116 == V_216 ) {
V_170 = F_24 ( V_51 + V_182 ) ;
if ( V_170 == 0 || V_170 == 0xffffffff )
goto V_223;
F_23 ( V_170 , V_51 + V_183 ) ;
F_46 ( V_3 ) ;
} else {
V_170 = F_24 ( V_51 + V_171 ) ;
if ( V_170 == 0 || V_170 == 0xffffffff )
goto V_223;
F_23 ( V_170 , V_51 + V_171 ) ;
F_24 ( V_51 + V_171 ) ;
F_40 ( V_3 , V_170 ) ;
}
if ( V_3 -> V_162 == NULL ) {
F_41 (KERN_WARNING DRV_NAME
L_9 , pci_name(hba->pdev)) ;
goto V_222;
}
V_223:
F_29 ( V_9 ) ;
V_3 -> V_162 -> V_16 = NULL ;
V_3 -> V_162 = NULL ;
V_10 = V_224 ;
V_222:
F_30 ( V_36 -> V_93 , V_92 ) ;
return V_10 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_225 * V_63 ;
int V_30 ;
V_34 V_226 ;
V_84 V_227 ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
F_60 ( V_3 -> V_52 , V_30 * 4 ,
& V_3 -> V_52 -> V_228 [ V_30 ] ) ;
V_63 = V_3 -> V_52 -> V_63 ;
F_61 ( V_63 -> V_229 , V_230 , & V_227 ) ;
V_227 |= V_231 ;
F_62 ( V_63 -> V_229 , V_230 , V_227 ) ;
F_51 ( 100 ) ;
V_227 &= ~ V_231 ;
F_62 ( V_63 -> V_229 , V_230 , V_227 ) ;
for ( V_30 = 0 ; V_30 < V_232 ; V_30 ++ ) {
F_63 ( V_3 -> V_52 , V_233 , & V_226 ) ;
if ( V_226 != 0xffff && ( V_226 & V_234 ) )
break;
F_51 ( 1 ) ;
}
F_64 ( 5 ) ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
F_65 ( V_3 -> V_52 , V_30 * 4 ,
V_3 -> V_52 -> V_228 [ V_30 ] ) ;
}
static int F_66 ( struct V_2 * V_3 )
{
void T_3 * V_51 ;
unsigned long V_92 , V_188 ;
int V_208 = 0 ;
V_51 = V_3 -> V_78 ;
F_23 ( V_235 , V_51 + V_81 ) ;
F_24 ( V_51 + V_81 ) ;
V_188 = V_192 ;
while ( V_3 -> V_77 > 0 ) {
if ( F_49 ( V_192 , V_188 + V_236 * V_87 ) ) {
F_41 (KERN_WARNING DRV_NAME
L_10 , pci_name(hba->pdev)) ;
V_208 = - 1 ;
break;
}
F_51 ( 1 ) ;
}
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
if ( V_208 == - 1 )
V_3 -> V_104 = V_218 ;
else
V_3 -> V_104 = V_107 ;
F_56 ( & V_3 -> V_219 ) ;
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
return V_208 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_23 ( V_237 , V_3 -> V_78 + V_238 ) ;
F_24 ( V_3 -> V_78 + V_238 ) ;
F_64 ( 5 ) ;
}
static int F_68 ( struct V_2 * V_3 )
{
unsigned long V_92 ;
unsigned int V_104 = V_159 ;
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
if ( V_3 -> V_104 == V_239 ) {
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
F_41 (KERN_INFO DRV_NAME L_11 ,
pci_name(hba->pdev)) ;
return 0 ;
}
while ( V_3 -> V_104 == V_159 ) {
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
F_69 ( V_3 -> V_219 ,
V_3 -> V_104 != V_159 ,
V_193 * V_87 ) ;
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
V_104 = V_3 -> V_104 ;
}
if ( V_104 != V_159 ) {
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
return ( V_104 == V_107 ) ? 0 : - 1 ;
}
V_3 -> V_104 = V_159 ;
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
if ( V_3 -> V_116 == V_160 )
return F_66 ( V_3 ) ;
if ( V_3 -> V_116 == V_117 )
F_59 ( V_3 ) ;
else if ( V_3 -> V_116 == V_216 )
F_67 ( V_3 ) ;
F_27 ( V_3 , V_240 ) ;
if ( F_55 ( V_3 ) == 0 )
return 0 ;
F_41 (KERN_WARNING DRV_NAME L_12 ,
pci_name(hba->pdev)) ;
return - 1 ;
}
static int F_70 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) & V_9 -> V_72 -> V_36 -> V_103 [ 0 ] ;
F_71 ( V_221 , V_9 -> V_72 -> V_36 ,
L_13 ) ;
return F_68 ( V_3 ) ? V_224 : V_220 ;
}
static void F_72 ( struct V_241 * V_242 )
{
struct V_2 * V_3 = F_73 ( V_242 , struct V_2 , V_174 ) ;
F_68 ( V_3 ) ;
}
static int F_74 ( struct V_96 * V_97 ,
struct V_243 * V_244 , T_5 V_245 , int V_246 [] )
{
int V_247 = 255 , V_248 = 63 ;
if ( V_245 < 0x200000 ) {
V_247 = 64 ;
V_248 = 32 ;
}
F_75 ( V_245 , V_247 * V_248 ) ;
V_246 [ 0 ] = V_247 ;
V_246 [ 1 ] = V_248 ;
V_246 [ 2 ] = V_245 ;
return 0 ;
}
static int F_76 ( struct V_249 * V_52 )
{
int V_208 ;
if ( ! F_77 ( V_52 , F_78 ( 64 ) )
&& ! F_79 ( V_52 , F_78 ( 64 ) ) )
return 0 ;
V_208 = F_77 ( V_52 , F_78 ( 32 ) ) ;
if ( ! V_208 )
V_208 = F_79 ( V_52 , F_78 ( 32 ) ) ;
return V_208 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_249 * V_52 = V_3 -> V_52 ;
int V_4 ;
if ( V_250 ) {
V_4 = F_81 ( V_52 ) ;
if ( V_4 != 0 )
F_41 (KERN_ERR DRV_NAME
L_14 ,
pci_name(pdev), status) ;
else
V_3 -> V_251 = 1 ;
} else
V_3 -> V_251 = 0 ;
V_4 = F_82 ( V_52 -> V_69 , V_3 -> V_116 == V_216 ?
F_47 : F_44 , V_252 , V_253 , V_3 ) ;
if ( V_4 != 0 ) {
if ( V_3 -> V_251 )
F_83 ( V_52 ) ;
}
return V_4 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_249 * V_52 = V_3 -> V_52 ;
F_85 ( V_52 -> V_69 , V_3 ) ;
if ( V_3 -> V_251 )
F_83 ( V_52 ) ;
}
static int F_86 ( struct V_249 * V_52 , const struct V_254 * V_70 )
{
struct V_2 * V_3 ;
struct V_101 * V_36 ;
const struct V_255 * V_256 = NULL ;
V_40 V_257 , V_258 , V_259 ;
int V_215 ;
V_215 = F_87 ( V_52 ) ;
if ( V_215 )
return V_215 ;
F_88 ( V_52 ) ;
V_36 = F_89 ( & V_260 , sizeof( struct V_2 ) ) ;
if ( ! V_36 ) {
F_41 (KERN_ERR DRV_NAME L_15 ,
pci_name(pdev)) ;
V_215 = - V_261 ;
goto V_262;
}
V_3 = (struct V_2 * ) V_36 -> V_103 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_215 = F_90 ( V_52 , V_253 ) ;
if ( V_215 < 0 ) {
F_41 (KERN_ERR DRV_NAME L_16 ,
pci_name(pdev)) ;
goto V_263;
}
V_3 -> V_78 = F_91 ( V_52 , 0 ) ;
if ( ! V_3 -> V_78 ) {
F_41 (KERN_ERR DRV_NAME L_17 ,
pci_name(pdev)) ;
V_215 = - V_261 ;
goto V_264;
}
V_215 = F_76 ( V_52 ) ;
if ( V_215 ) {
F_41 (KERN_ERR DRV_NAME L_18 ,
pci_name(pdev)) ;
goto V_265;
}
V_3 -> V_116 = ( unsigned int ) V_70 -> V_266 ;
V_256 = & V_267 [ V_3 -> V_116 ] ;
switch ( V_70 -> V_268 ) {
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
if ( V_3 -> V_116 == V_216 )
V_3 -> V_269 = 1 ;
}
V_257 = V_259 = ( V_256 -> V_20 + 1 ) * V_256 -> V_19 ;
if ( V_3 -> V_116 == V_216 )
V_257 += ( V_256 -> V_7 + 1 ) * sizeof( V_40 ) ;
V_258 = V_257 + ( V_256 -> V_7 + 1 ) * sizeof( struct V_1 ) ;
V_3 -> V_206 = V_258 + sizeof( struct V_48 ) ;
if ( V_3 -> V_116 == V_270 ||
( V_3 -> V_116 == V_271 && ( V_52 -> V_75 & 1 ) ) ) {
V_3 -> V_204 = V_3 -> V_206 ;
V_3 -> V_206 += V_272 ;
}
V_3 -> V_17 = F_92 ( & V_52 -> V_273 ,
V_3 -> V_206 , & V_3 -> V_88 , V_274 ) ;
if ( ! V_3 -> V_17 ) {
if ( V_3 -> V_116 == V_270 ||
( V_3 -> V_116 == V_271 && ( V_52 -> V_75 & 1 ) ) ) {
F_41 (KERN_WARNING DRV_NAME
L_19 ,
pci_name(pdev)) ;
V_3 -> V_206 = V_3 -> V_204
+ V_275 ;
V_3 -> V_17 = F_92 ( & V_52 -> V_273 ,
V_3 -> V_206 , & V_3 -> V_88 , V_274 ) ;
}
if ( ! V_3 -> V_17 ) {
V_215 = - V_261 ;
F_41 (KERN_ERR DRV_NAME L_20 ,
pci_name(pdev)) ;
goto V_265;
}
}
V_3 -> V_23 = F_93 ( V_256 -> V_20 , sizeof( struct V_22 ) , V_274 ) ;
if ( ! V_3 -> V_23 ) {
V_215 = - V_261 ;
F_41 (KERN_ERR DRV_NAME L_21 ,
pci_name(pdev)) ;
goto V_276;
}
if ( V_3 -> V_116 == V_216 )
V_3 -> V_177 = ( V_153 * ) ( V_3 -> V_17 + V_259 ) ;
V_3 -> V_5 = (struct V_1 * ) ( V_3 -> V_17 + V_257 ) ;
V_3 -> V_50 = V_3 -> V_17 + V_258 ;
V_3 -> V_20 = V_256 -> V_20 ;
V_3 -> V_19 = V_256 -> V_19 ;
V_3 -> V_7 = V_256 -> V_7 ;
V_3 -> V_134 = V_256 -> V_134 ;
V_3 -> V_147 = V_256 -> V_147 ;
V_3 -> V_148 = V_256 -> V_148 ;
V_3 -> V_104 = V_239 ;
if ( V_3 -> V_116 == V_216 )
V_36 -> V_37 = 38 ;
else
V_36 -> V_37 = 32 ;
V_36 -> V_94 = V_256 -> V_20 ;
V_36 -> V_195 = V_256 -> V_20 ;
V_36 -> V_118 = V_256 -> V_118 ;
V_36 -> V_121 = V_256 -> V_121 ;
V_36 -> V_277 = V_256 -> V_277 ;
V_36 -> V_278 = V_36 -> V_132 ;
V_36 -> V_279 = V_137 ;
V_3 -> V_36 = V_36 ;
V_3 -> V_52 = V_52 ;
F_94 ( & V_3 -> V_219 ) ;
snprintf ( V_3 -> V_280 , sizeof( V_3 -> V_280 ) ,
L_22 , V_36 -> V_132 ) ;
V_3 -> V_173 = F_95 ( V_3 -> V_280 ) ;
if ( ! V_3 -> V_173 ) {
F_41 (KERN_ERR DRV_NAME L_23 ,
pci_name(pdev)) ;
V_215 = - V_261 ;
goto V_281;
}
F_96 ( & V_3 -> V_174 , F_72 ) ;
V_215 = F_80 ( V_3 ) ;
if ( V_215 ) {
F_41 (KERN_ERR DRV_NAME L_24 ,
pci_name(pdev)) ;
goto V_282;
}
V_215 = F_55 ( V_3 ) ;
if ( V_215 )
goto V_283;
F_97 ( V_52 , V_3 ) ;
V_215 = F_98 ( V_36 , & V_52 -> V_273 ) ;
if ( V_215 ) {
F_41 (KERN_ERR DRV_NAME L_25 ,
pci_name(pdev)) ;
goto V_283;
}
F_99 ( V_36 ) ;
return 0 ;
V_283:
F_84 ( V_3 ) ;
V_282:
F_100 ( V_3 -> V_173 ) ;
V_281:
F_101 ( V_3 -> V_23 ) ;
V_276:
F_102 ( & V_52 -> V_273 , V_3 -> V_206 ,
V_3 -> V_17 , V_3 -> V_88 ) ;
V_265:
F_103 ( V_3 -> V_78 ) ;
V_264:
F_104 ( V_52 ) ;
V_263:
F_105 ( V_36 ) ;
V_262:
F_106 ( V_52 ) ;
return V_215 ;
}
static void F_107 ( struct V_2 * V_3 , int V_284 )
{
struct V_15 * V_16 ;
struct V_21 * V_82 ;
unsigned long V_92 ;
unsigned long V_188 ;
V_34 V_76 = 0 ;
F_28 ( V_3 -> V_36 -> V_93 , V_92 ) ;
if ( V_3 -> V_116 == V_216 && V_3 -> V_269 == 1 )
{
if( V_284 == V_285 )
{
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
return;
}
}
V_16 = V_3 -> V_134 ( V_3 ) ;
if ( V_3 -> V_116 == V_216 ) {
V_82 = (struct V_21 * ) V_16 - 1 ;
memset ( V_82 , 0 , V_3 -> V_19 ) ;
} else
memset ( V_16 , 0 , V_3 -> V_19 ) ;
if ( ( V_3 -> V_116 == V_160 || V_3 -> V_116 == V_216 )
&& V_284 == V_286 ) {
V_16 -> V_136 [ 0 ] = V_152 ;
V_16 -> V_136 [ 1 ] = V_287 ;
V_16 -> V_136 [ 2 ] = V_288 ;
V_16 -> V_136 [ 3 ] = V_289 ;
} else if ( V_3 -> V_116 == V_216 && V_284 != V_286 ) {
V_16 -> V_136 [ 0 ] = V_152 ;
V_16 -> V_136 [ 1 ] = V_287 ;
V_16 -> V_136 [ 2 ] = V_288 ;
V_16 -> V_136 [ 3 ] = V_290 ;
V_16 -> V_136 [ 4 ] = V_284 ;
} else {
V_16 -> V_136 [ 0 ] = V_291 ;
V_16 -> V_136 [ 1 ] = V_292 ;
V_16 -> V_136 [ 2 ] = V_293 ;
}
V_3 -> V_23 [ V_76 ] . V_9 = NULL ;
V_3 -> V_23 [ V_76 ] . V_33 = 0 ;
V_3 -> V_23 [ V_76 ] . V_145 = 0 ;
V_3 -> V_23 [ V_76 ] . V_13 = NULL ;
V_3 -> V_23 [ V_76 ] . V_167 = V_294 ;
V_3 -> V_148 ( V_3 , V_16 , V_76 ) ;
F_30 ( V_3 -> V_36 -> V_93 , V_92 ) ;
V_188 = V_192 ;
while ( V_3 -> V_23 [ V_76 ] . V_167 & V_294 ) {
if ( F_49 ( V_192 , V_188 + V_236 * V_87 ) ) {
V_3 -> V_23 [ V_76 ] . V_167 = 0 ;
V_3 -> V_104 = V_295 ;
return;
}
F_51 ( 1 ) ;
}
V_3 -> V_104 = V_295 ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_84 ( V_3 ) ;
F_100 ( V_3 -> V_173 ) ;
F_103 ( V_3 -> V_78 ) ;
F_104 ( V_3 -> V_52 ) ;
F_101 ( V_3 -> V_23 ) ;
F_102 ( & V_3 -> V_52 -> V_273 , V_3 -> V_206 ,
V_3 -> V_17 , V_3 -> V_88 ) ;
}
static void F_109 ( struct V_249 * V_52 )
{
struct V_2 * V_3 = F_110 ( V_52 ) ;
V_3 -> V_104 = V_105 ;
F_27 ( V_3 , V_106 ) ;
F_111 ( V_3 -> V_36 ) ;
F_112 ( V_3 -> V_36 ) ;
F_108 ( V_3 ) ;
F_105 ( V_3 -> V_36 ) ;
F_106 ( V_52 ) ;
}
static void F_113 ( struct V_249 * V_52 )
{
struct V_2 * V_3 = F_110 ( V_52 ) ;
if ( V_3 -> V_269 == 0 )
F_107 ( V_3 , V_286 ) ;
else
F_107 ( V_3 , V_296 ) ;
}
static int F_114 ( T_6 V_297 )
{
switch ( V_297 . V_298 ) {
case V_299 :
return V_300 ;
case V_301 :
return V_302 ;
default:
return V_285 ;
}
}
static int F_115 ( struct V_249 * V_52 , T_6 V_297 )
{
struct V_2 * V_3 = F_110 ( V_52 ) ;
if ( V_3 -> V_116 == V_216 && V_3 -> V_269 == 1 )
F_107 ( V_3 , F_114 ( V_297 ) ) ;
else
F_107 ( V_3 , V_286 ) ;
return 0 ;
}
static int F_116 ( struct V_249 * V_52 )
{
struct V_2 * V_3 = F_110 ( V_52 ) ;
V_3 -> V_104 = V_239 ;
F_55 ( V_3 ) ;
return 0 ;
}
static int T_7 F_117 ( void )
{
F_41 (KERN_INFO DRV_NAME
L_26 ,
ST_DRIVER_VERSION) ;
return F_118 ( & V_303 ) ;
}
static void T_8 F_119 ( void )
{
F_120 ( & V_303 ) ;
}
