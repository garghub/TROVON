static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 ;
struct V_7 * V_13 ;
struct V_14 * V_15 ;
unsigned int V_16 ;
F_2 ( V_17 , L_1 ,
& V_6 -> V_18 , & V_6 -> V_19 ) ;
F_3 (nesdev, &nes_dev_list, list) {
F_2 ( V_17 , L_2 ,
V_12 , V_12 -> V_13 [ 0 ] -> V_20 ) ;
V_13 = V_12 -> V_13 [ 0 ] ;
V_15 = F_4 ( V_13 ) ;
V_16 = F_5 ( V_13 ) &&
( V_13 -> V_21 == V_8 ) ;
if ( ( V_13 == V_8 ) || V_16 ) {
if ( V_15 -> V_22 == 0 ) {
F_2 ( V_17 , L_3
L_4 ,
V_13 -> V_20 ) ;
return V_23 ;
}
switch ( V_3 ) {
case V_24 :
F_2 ( V_17 , L_5 ) ;
F_6 ( V_12 ,
V_25 + ( 0x10 * F_7 ( V_12 -> V_26 -> V_27 ) ) , 0 ) ;
F_8 ( V_13 , V_13 -> V_28 ,
F_9 ( V_15 -> V_29 ) , V_30 ) ;
V_15 -> V_29 = 0 ;
if ( V_16 )
continue;
else
return V_23 ;
break;
case V_31 :
F_2 ( V_17 , L_6 ) ;
if ( V_15 -> V_29 != 0 ) {
F_2 ( V_17 , L_7 ) ;
return V_23 ;
}
case V_32 :
if ( V_13 -> V_21 )
V_15 -> V_29 =
( (struct V_33 * ) V_13 -> V_21 -> V_34 ) -> V_35 -> V_18 ;
else
V_15 -> V_29 = V_6 -> V_18 ;
F_6 ( V_12 ,
V_25 + ( 0x10 * F_7 ( V_12 -> V_26 -> V_27 ) ) ,
F_9 ( V_15 -> V_29 ) ) ;
F_8 ( V_13 , V_13 -> V_28 ,
F_9 ( V_15 -> V_29 ) , V_36 ) ;
if ( V_16 )
continue;
else
return V_23 ;
break;
default:
break;
}
}
}
return V_37 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_38 * V_39 = V_4 ;
struct V_11 * V_12 ;
struct V_7 * V_13 ;
struct V_14 * V_15 ;
switch ( V_3 ) {
case V_40 :
F_3 (nesdev, &nes_dev_list, list) {
V_13 = V_12 -> V_13 [ 0 ] ;
V_15 = F_4 ( V_13 ) ;
if ( V_13 == V_39 -> V_10 ) {
if ( V_15 -> V_22 == 0 ) {
F_2 ( V_17 , L_8 ,
V_13 -> V_20 ) ;
} else {
if ( V_39 -> V_41 & V_42 ) {
F_8 ( V_39 -> V_10 , V_39 -> V_43 ,
F_9 ( * ( V_44 * ) V_39 -> V_45 ) , V_36 ) ;
} else {
F_8 ( V_39 -> V_10 , V_39 -> V_43 ,
F_9 ( * ( V_44 * ) V_39 -> V_45 ) , V_30 ) ;
}
}
return V_23 ;
}
}
break;
default:
F_2 ( V_17 , L_9 , V_3 ) ;
break;
}
return V_37 ;
}
void F_11 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
V_49 = F_12 ( V_47 ) ;
F_2 ( V_50 , L_10 ,
V_47 -> V_51 , F_13 ( & V_49 -> V_52 ) ) ;
F_14 ( & V_49 -> V_52 ) ;
}
static void F_15 ( struct V_11 * V_12 , struct V_53 * V_54 )
{
unsigned long V_55 ;
struct V_48 * V_49 = V_54 -> V_56 ;
struct V_57 * V_58 = V_12 -> V_58 ;
F_14 ( & V_59 ) ;
if ( V_49 -> V_60 ) {
F_16 ( V_12 -> V_26 , V_49 -> V_61 ,
V_49 -> V_62 . V_63 , V_49 -> V_62 . V_64 ) ;
F_17 ( & V_58 -> V_65 , V_55 ) ;
V_58 -> V_66 ++ ;
F_18 ( & V_58 -> V_65 , V_55 ) ;
F_16 ( V_12 -> V_26 , 256 , V_49 -> V_60 , V_49 -> V_67 ) ;
V_49 -> V_60 = NULL ;
} else {
F_16 ( V_12 -> V_26 , V_49 -> V_61 ,
V_49 -> V_62 . V_68 , V_49 -> V_62 . V_69 ) ;
}
F_19 ( V_58 , V_58 -> V_70 , V_49 -> V_62 . V_71 ) ;
V_58 -> V_72 [ V_49 -> V_62 . V_71 - V_73 ] = NULL ;
F_20 ( V_49 -> V_74 ) ;
}
void F_21 ( struct V_46 * V_47 )
{
T_1 V_75 ;
struct V_48 * V_49 ;
struct V_14 * V_15 = F_22 ( V_47 -> V_76 ) ;
struct V_11 * V_12 = V_15 -> V_12 ;
struct V_77 * V_78 ;
struct V_53 * V_54 ;
T_2 V_79 ;
V_49 = F_12 ( V_47 ) ;
if ( F_13 ( & V_49 -> V_52 ) == 0 ) {
F_23 (KERN_INFO PFX L_11 ,
__func__, ibqp->qp_num, nesqp->last_aeq) ;
F_24 () ;
}
if ( F_25 ( & V_49 -> V_52 ) ) {
if ( V_49 -> V_80 )
F_26 ( V_12 , V_49 ) ;
V_54 = F_27 ( V_12 ) ;
if ( V_54 == NULL ) {
F_2 ( V_50 , L_12 ) ;
return;
}
V_54 -> V_81 = 0 ;
V_54 -> V_82 = 1 ;
V_54 -> V_83 = F_15 ;
V_54 -> V_56 = V_49 ;
V_78 = & V_54 -> V_78 ;
F_28 ( V_78 , V_12 ) ;
V_79 = V_84 | V_85 ;
if ( V_49 -> V_86 ) {
V_79 |= V_87 ;
V_49 -> V_86 = 0 ;
}
F_29 ( V_78 -> V_88 , V_89 , V_79 ) ;
F_29 ( V_78 -> V_88 , V_90 , V_49 -> V_62 . V_71 ) ;
V_75 = ( T_1 ) V_49 -> V_91 ;
F_30 ( V_78 -> V_88 , V_92 , V_75 ) ;
F_31 ( V_12 , V_54 ) ;
}
}
struct V_46 * F_32 ( struct V_93 * V_76 , int V_94 )
{
struct V_14 * V_15 = F_22 ( V_76 ) ;
struct V_11 * V_12 = V_15 -> V_12 ;
struct V_57 * V_58 = V_12 -> V_58 ;
if ( ( V_94 < V_73 ) || ( V_94 >= ( V_73 + V_58 -> V_95 ) ) )
return NULL ;
return & V_58 -> V_72 [ V_94 - V_73 ] -> V_47 ;
}
static void F_33 ( struct V_7 * V_13 )
{
F_2 ( V_96 , L_13 ,
V_13 -> V_20 , V_13 -> V_28 , V_13 -> V_97 ) ;
}
static T_3 F_34 ( int V_97 , void * V_98 )
{
struct V_11 * V_12 = (struct V_11 * ) V_98 ;
int V_99 = 0 ;
T_2 V_100 ;
T_2 V_101 ;
T_2 V_102 ;
T_2 V_103 ;
T_2 V_104 ;
if ( V_12 -> V_105 ) {
V_99 = 1 ;
} else {
if ( F_35 ( V_12 -> V_58 -> V_106 == V_107 ) ) {
V_100 = F_36 ( V_12 -> V_108 + V_109 ) ;
if ( V_100 & 0x80000000 ) {
V_102 = F_36 ( V_12 -> V_108 + V_110 ) ;
V_101 = V_12 -> V_101 ;
if ( V_102 & V_101 ) {
if ( ( V_102 & V_101 ) & ( ~ ( V_111 | V_112 ) ) ) {
V_99 = 1 ;
} else {
if ( ( ( V_102 & V_101 ) & V_111 ) == V_111 ) {
V_104 = F_36 ( V_12 -> V_108 + V_113 ) ;
if ( ( V_104 & V_12 -> V_114 ) != 0 ) {
V_99 = 1 ;
}
}
if ( ( ( ( V_102 & V_101 ) & V_112 ) == V_112 ) &&
( V_99 == 0 ) ) {
V_103 = F_36 ( V_12 -> V_108 + V_115 ) ;
if ( ( V_103 & V_12 -> V_116 ) != 0 ) {
V_99 = 1 ;
}
}
}
if ( V_99 ) {
F_37 ( V_12 -> V_108 + V_109 , V_100 & ( ~ 0x80000000 ) ) ;
V_100 = F_36 ( V_12 -> V_108 + V_109 ) ;
V_12 -> V_102 = V_102 ;
V_12 -> V_117 = 1 ;
}
}
}
} else {
V_99 = F_36 ( V_12 -> V_108 + V_118 ) ;
}
}
if ( V_99 ) {
if ( F_38 ( V_12 ) == 0 ) {
F_39 ( & V_12 -> V_119 ) ;
}
return V_120 ;
} else {
return V_121 ;
}
}
static int F_40 ( struct V_122 * V_26 , const struct V_123 * V_124 )
{
struct V_7 * V_13 = NULL ;
struct V_11 * V_12 = NULL ;
int V_125 = 0 ;
void T_4 * V_126 = NULL ;
T_5 V_106 ;
assert ( V_26 != NULL ) ;
assert ( V_124 != NULL ) ;
F_23 (KERN_INFO PFX L_14 ,
DRV_VERSION, pci_name(pcidev)) ;
V_125 = F_41 ( V_26 ) ;
if ( V_125 ) {
F_23 (KERN_ERR PFX L_15 , pci_name(pcidev)) ;
goto V_127;
}
F_2 ( V_96 , L_16 ,
( long unsigned int ) F_42 ( V_26 , V_128 ) ,
( long unsigned int ) F_43 ( V_26 , V_128 ) ) ;
F_2 ( V_96 , L_17 ,
( long unsigned int ) F_42 ( V_26 , V_129 ) ,
( long unsigned int ) F_43 ( V_26 , V_129 ) ) ;
if ( ! ( F_44 ( V_26 , V_128 ) & V_130 ) ||
! ( F_44 ( V_26 , V_129 ) & V_130 ) ) {
F_23 (KERN_ERR PFX L_18 ) ;
V_125 = - V_131 ;
goto V_132;
}
V_125 = F_45 ( V_26 , V_133 ) ;
if ( V_125 ) {
F_23 (KERN_ERR PFX L_19 , pci_name(pcidev)) ;
goto V_132;
}
if ( ( sizeof( V_134 ) > 4 ) ) {
V_125 = F_46 ( V_26 , F_47 ( 64 ) ) ;
if ( V_125 < 0 ) {
F_23 (KERN_ERR PFX L_20 ) ;
goto V_135;
}
V_125 = F_48 ( V_26 , F_47 ( 64 ) ) ;
if ( V_125 ) {
F_23 (KERN_ERR PFX L_21 ) ;
goto V_135;
}
} else {
V_125 = F_46 ( V_26 , F_47 ( 32 ) ) ;
if ( V_125 < 0 ) {
F_23 (KERN_ERR PFX L_22 ) ;
goto V_135;
}
V_125 = F_48 ( V_26 , F_47 ( 32 ) ) ;
if ( V_125 ) {
F_23 (KERN_ERR PFX L_23 ) ;
goto V_135;
}
}
F_49 ( V_26 ) ;
V_12 = F_50 ( sizeof( struct V_11 ) , V_136 ) ;
if ( ! V_12 ) {
F_23 (KERN_ERR PFX L_24 , pci_name(pcidev)) ;
V_125 = - V_137 ;
goto V_135;
}
F_2 ( V_96 , L_25 , V_12 ) ;
V_12 -> V_26 = V_26 ;
F_51 ( V_26 , V_12 ) ;
F_52 ( V_26 , 0x0008 , & V_106 ) ;
F_2 ( V_96 , L_26 , V_106 ) ;
F_53 ( & V_12 -> V_138 ) ;
V_126 = F_54 ( F_42 ( V_26 , V_128 ) ,
F_43 ( V_26 , V_128 ) ) ;
if ( V_126 == NULL ) {
F_23 (KERN_ERR PFX L_27 ) ;
V_125 = - V_139 ;
goto V_140;
}
V_12 -> V_108 = V_126 ;
V_12 -> V_141 = 0x50 + ( F_7 ( V_26 -> V_27 ) * 8 ) + V_126 ;
F_37 ( V_12 -> V_108 + V_109 , 0x7fffffff ) ;
if ( V_142 & V_143 ) {
if ( ! F_55 ( V_12 -> V_26 ) ) {
V_12 -> V_105 = 1 ;
F_2 ( V_96 , L_28 ,
F_56 ( V_26 ) ) ;
} else {
F_2 ( V_96 , L_29 ,
F_56 ( V_26 ) ) ;
}
} else {
F_2 ( V_96 , L_30 ,
F_56 ( V_26 ) ) ;
}
V_12 -> V_144 = F_42 ( V_12 -> V_26 , V_128 ) ;
V_12 -> V_145 = F_42 ( V_12 -> V_26 , V_129 ) ;
V_12 -> V_58 = F_57 ( V_12 , V_106 ) ;
if ( ! V_12 -> V_58 ) {
F_23 (KERN_ERR PFX L_31 ) ;
V_125 = - V_137 ;
goto V_146;
}
V_12 -> V_58 -> V_147 = V_148 ;
V_12 -> V_58 -> V_149 = V_149 ;
V_12 -> V_150 = 1 ;
V_12 -> V_151 = V_12 -> V_58 -> V_151 ;
if ( V_12 -> V_58 -> V_152 [ 0 ] == V_153 ) {
switch ( F_7 ( V_12 -> V_26 -> V_27 ) %
V_12 -> V_58 -> V_154 ) {
case 1 :
V_12 -> V_155 = 2 ;
break;
case 2 :
V_12 -> V_155 = 1 ;
break;
case 3 :
V_12 -> V_155 = 3 ;
break;
case 0 :
default:
V_12 -> V_155 = 0 ;
}
} else {
V_12 -> V_155 = F_7 ( V_12 -> V_26 -> V_27 ) %
V_12 -> V_58 -> V_154 ;
}
if ( ( V_156 ||
( ( V_12 -> V_58 -> V_152 [ 0 ] == V_157 ) &&
( V_106 == V_158 ) ) ) &&
( F_58 ( V_26 ) > 256 ) ) {
if ( F_59 ( V_26 , 256 ) )
F_23 (KERN_ERR PFX L_32
L_33 ) ;
else
F_2 ( V_96 , L_34
L_33 ) ;
}
F_60 ( & V_12 -> V_119 , V_159 , ( unsigned long ) V_12 ) ;
if ( F_61 ( V_12 ) ) {
V_125 = - V_131 ;
goto V_160;
}
F_37 ( V_12 -> V_108 + V_161 , V_162 |
F_7 ( V_12 -> V_26 -> V_27 ) ) ;
F_36 ( V_12 -> V_108 + V_161 ) ;
V_12 -> V_101 = ( 0x101 << F_7 ( V_12 -> V_26 -> V_27 ) ) |
( 1 << ( F_7 ( V_12 -> V_26 -> V_27 ) + 16 ) ) ;
if ( F_7 ( V_12 -> V_26 -> V_27 ) < 4 ) {
V_12 -> V_101 |= ( 1 << ( F_7 ( V_12 -> V_155 ) + 24 ) ) ;
}
if ( F_7 ( V_12 -> V_26 -> V_27 ) == 0 ) {
V_12 -> V_116 = V_163 | V_164 ;
V_12 -> V_101 |= V_112 ;
} else {
V_12 -> V_116 = 0 ;
}
V_12 -> V_116 |= ( 1 << ( F_7 ( V_12 -> V_26 -> V_27 ) + 16 ) ) ;
F_6 ( V_12 , V_165 , 0 ) ;
F_6 ( V_12 , V_166 , 0 ) ;
F_6 ( V_12 , V_167 , 0x00001265 ) ;
F_6 ( V_12 , V_168 , 0x18021804 ) ;
F_6 ( V_12 , V_169 , 0x17801790 ) ;
V_12 -> V_114 = 0x101 << F_7 ( V_12 -> V_26 -> V_27 ) ;
V_12 -> V_58 -> V_114 |= V_12 -> V_114 ;
F_2 ( V_96 , L_35 ,
F_7 ( V_12 -> V_26 -> V_27 ) ,
V_12 -> V_114 , V_12 -> V_58 -> V_114 ) ;
F_37 ( V_12 -> V_108 + V_170 , ~ ( V_12 -> V_116 ) ) ;
F_62 ( & V_12 -> V_171 , & V_172 ) ;
V_125 = F_63 ( V_26 -> V_97 , F_34 , V_173 , V_133 , V_12 ) ;
if ( V_125 ) {
F_23 (KERN_ERR PFX L_36 ,
pci_name(pcidev), pcidev->irq) ;
goto V_174;
}
F_37 ( V_12 -> V_108 + V_109 , ~ V_12 -> V_101 ) ;
if ( V_175 == 0 ) {
F_64 ( & V_176 ) ;
F_65 ( & V_177 ) ;
}
V_175 ++ ;
F_66 ( & V_12 -> V_178 , V_179 ) ;
if ( ( V_13 = F_67 ( V_12 , V_126 ) ) == NULL )
goto V_180;
V_125 = F_68 ( V_13 ) ;
if ( V_125 ) {
F_23 (KERN_ERR PFX L_37 , ret) ;
F_69 ( V_13 ) ;
goto V_180;
}
F_33 ( V_13 ) ;
V_12 -> V_181 ++ ;
V_12 -> V_58 -> V_181 ++ ;
F_23 (KERN_INFO PFX L_38 ,
pci_name(pcidev)) ;
return 0 ;
V_180:
F_23 (KERN_ERR PFX L_39 ) ;
while ( V_12 -> V_181 > 0 ) {
V_12 -> V_181 -- ;
V_12 -> V_58 -> V_181 -- ;
F_70 ( V_12 -> V_13 [ V_12 -> V_181 ] ) ;
F_69 ( V_12 -> V_13 [ V_12 -> V_181 ] ) ;
}
F_2 ( V_96 , L_40 ,
V_12 -> V_181 , V_12 -> V_58 -> V_181 ) ;
V_175 -- ;
if ( V_175 == 0 ) {
F_71 ( & V_177 ) ;
F_72 ( & V_176 ) ;
}
F_73 ( & V_12 -> V_171 ) ;
F_74 ( V_12 ) ;
V_174:
F_23 (KERN_ERR PFX L_41 ) ;
F_75 ( V_26 -> V_97 , V_12 ) ;
if ( V_12 -> V_105 ) {
F_76 ( V_26 ) ;
}
V_160:
F_23 (KERN_ERR PFX L_42 ) ;
F_77 ( & V_12 -> V_119 ) ;
F_78 ( V_12 -> V_58 ) ;
V_146:
F_23 (KERN_ERR PFX L_43 ) ;
F_79 ( V_12 -> V_108 ) ;
V_140:
F_23 (KERN_ERR PFX L_44 ) ;
F_20 ( V_12 ) ;
V_135:
F_80 ( V_26 ) ;
V_132:
F_81 ( V_26 ) ;
V_127:
return V_125 ;
}
static void F_82 ( struct V_122 * V_26 )
{
struct V_11 * V_12 = F_83 ( V_26 ) ;
struct V_7 * V_13 ;
int V_182 = 0 ;
unsigned long V_55 ;
if ( V_12 -> V_181 ) {
V_13 = V_12 -> V_13 [ V_182 ] ;
if ( V_13 ) {
F_84 ( V_13 ) ;
F_70 ( V_13 ) ;
F_69 ( V_13 ) ;
V_12 -> V_13 [ V_182 ] = NULL ;
V_12 -> V_181 -- ;
V_12 -> V_58 -> V_181 -- ;
}
}
V_175 -- ;
if ( V_175 == 0 ) {
F_71 ( & V_177 ) ;
F_72 ( & V_176 ) ;
}
F_73 ( & V_12 -> V_171 ) ;
F_74 ( V_12 ) ;
F_75 ( V_26 -> V_97 , V_12 ) ;
F_77 ( & V_12 -> V_119 ) ;
F_17 ( & V_12 -> V_58 -> V_183 , V_55 ) ;
if ( V_12 -> V_184 ) {
F_18 ( & V_12 -> V_58 -> V_183 , V_55 ) ;
F_85 ( & V_12 -> V_178 ) ;
} else {
F_18 ( & V_12 -> V_58 -> V_183 , V_55 ) ;
}
F_78 ( V_12 -> V_58 ) ;
if ( V_12 -> V_105 ) {
F_76 ( V_26 ) ;
}
F_79 ( V_12 -> V_108 ) ;
F_20 ( V_12 ) ;
F_80 ( V_26 ) ;
F_81 ( V_26 ) ;
F_51 ( V_26 , NULL ) ;
}
static T_6 F_86 ( struct V_185 * V_186 , char * V_187 )
{
unsigned int V_27 = 0xffffffff ;
unsigned char V_188 = 0xff ;
unsigned int V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_27 = V_12 -> V_26 -> V_27 ;
V_188 = V_12 -> V_26 -> V_191 -> V_192 ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_45 , V_188 , V_27 ) ;
}
static T_6 F_87 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
V_190 = F_88 ( V_195 , & V_195 , 10 ) ;
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_90 ( struct V_185 * V_186 , char * V_187 )
{
T_2 V_196 = 0xdead ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_196 = F_36 ( V_12 -> V_108 + V_197 ) ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_46 , V_196 ) ;
}
static T_6 F_91 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
T_2 V_198 ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' ) {
V_198 = F_88 ( V_195 , & V_195 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
F_37 ( V_12 -> V_108 + V_197 , V_198 ) ;
break;
}
V_189 ++ ;
}
}
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_92 ( struct V_185 * V_186 , char * V_187 )
{
T_2 V_199 = 0xdead ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_199 = F_36 ( V_12 -> V_108 + V_200 ) ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_46 , V_199 ) ;
}
static T_6 F_93 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
T_2 V_198 ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' ) {
V_198 = F_88 ( V_195 , & V_195 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
F_37 ( V_12 -> V_108 + V_200 , V_198 ) ;
break;
}
V_189 ++ ;
}
}
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_94 ( struct V_185 * V_186 , char * V_187 )
{
T_2 V_201 = 0xdead ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_201 = F_36 ( V_12 -> V_108 + V_202 ) ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_46 , V_201 ) ;
}
static T_6 F_95 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
T_2 V_198 ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' ) {
V_198 = F_88 ( V_195 , & V_195 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
F_37 ( V_12 -> V_108 + V_202 , V_198 ) ;
break;
}
V_189 ++ ;
}
}
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_96 ( struct V_185 * V_186 , char * V_187 )
{
T_2 V_203 = 0xdead ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_203 = F_36 ( V_12 -> V_108 + V_204 ) ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_46 , V_203 ) ;
}
static T_6 F_97 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
T_2 V_198 ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' ) {
V_198 = F_88 ( V_195 , & V_195 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
F_37 ( V_12 -> V_108 + V_204 , V_198 ) ;
break;
}
V_189 ++ ;
}
}
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_98 ( struct V_185 * V_186 , char * V_187 )
{
return snprintf ( V_187 , V_193 , L_46 , V_205 ) ;
}
static T_6 F_99 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' )
V_205 = F_88 ( V_195 , & V_195 , 16 ) ;
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_100 ( struct V_185 * V_186 , char * V_187 )
{
T_2 V_206 = 0xdead ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_206 = F_36 ( V_12 -> V_108 + V_205 ) ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_46 , V_206 ) ;
}
static T_6 F_101 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
T_2 V_198 ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' ) {
V_198 = F_88 ( V_195 , & V_195 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
F_37 ( V_12 -> V_108 + V_205 , V_198 ) ;
break;
}
V_189 ++ ;
}
}
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_102 ( struct V_185 * V_186 , char * V_187 )
{
return snprintf ( V_187 , V_193 , L_46 , V_207 ) ;
}
static T_6 F_103 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' )
V_207 = F_88 ( V_195 , & V_195 , 16 ) ;
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_104 ( struct V_185 * V_186 , char * V_187 )
{
T_2 V_208 = 0xdead ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_208 = F_105 ( V_12 , V_207 ) ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_46 , V_208 ) ;
}
static T_6 F_106 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
char * V_195 = ( char * ) V_187 ;
T_2 V_198 ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
if ( V_195 [ 1 ] == 'x' || V_195 [ 1 ] == 'X' || V_195 [ 0 ] == 'x' || V_195 [ 0 ] == 'X' ) {
V_198 = F_88 ( V_195 , & V_195 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
F_6 ( V_12 , V_207 , V_198 ) ;
break;
}
V_189 ++ ;
}
}
return F_89 ( V_187 , V_194 ) ;
}
static T_6 F_107 ( struct V_185 * V_186 , char * V_187 )
{
T_2 V_209 = 0xdead ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_209 = V_12 -> V_58 -> V_149 ;
break;
}
V_189 ++ ;
}
return snprintf ( V_187 , V_193 , L_47 , V_209 ) ;
}
static T_6 F_108 ( struct V_185 * V_186 ,
const char * V_187 , T_7 V_194 )
{
unsigned long V_209 ;
T_2 V_210 ;
T_2 V_189 = 0 ;
struct V_11 * V_12 ;
if ( F_109 ( V_187 , 0 , & V_209 ) < 0 )
return - V_211 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_189 == V_190 ) {
V_12 -> V_58 -> V_149 = V_209 ;
V_210 = F_105 ( V_12 ,
V_212 ) ;
F_6 ( V_12 , V_212 ,
( ( V_209 << 1 ) |
( V_210 & 0x00000001 ) ) ) ;
break;
}
V_189 ++ ;
}
return F_89 ( V_187 , V_194 ) ;
}
static int F_110 ( struct V_213 * V_214 )
{
int error ;
error = F_111 ( & V_214 -> V_215 , & V_216 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_217 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_218 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_219 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_220 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_221 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_222 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_223 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_224 ) ;
error |= F_111 ( & V_214 -> V_215 , & V_225 ) ;
return error ;
}
static void F_112 ( struct V_213 * V_214 )
{
F_113 ( & V_214 -> V_215 , & V_216 ) ;
F_113 ( & V_214 -> V_215 , & V_217 ) ;
F_113 ( & V_214 -> V_215 , & V_218 ) ;
F_113 ( & V_214 -> V_215 , & V_219 ) ;
F_113 ( & V_214 -> V_215 , & V_220 ) ;
F_113 ( & V_214 -> V_215 , & V_221 ) ;
F_113 ( & V_214 -> V_215 , & V_222 ) ;
F_113 ( & V_214 -> V_215 , & V_223 ) ;
F_113 ( & V_214 -> V_215 , & V_224 ) ;
F_113 ( & V_214 -> V_215 , & V_225 ) ;
}
static int T_8 F_114 ( void )
{
int V_226 ;
int V_227 ;
V_226 = F_115 () ;
if ( V_226 ) {
F_23 (KERN_ERR PFX L_48 ) ;
return V_226 ;
}
V_226 = F_116 ( & V_228 ) ;
if ( V_226 >= 0 ) {
V_227 = F_110 ( & V_228 ) ;
if ( V_227 < 0 )
F_23 (KERN_ERR PFX L_49 ) ;
}
return V_226 ;
}
static void T_9 F_117 ( void )
{
F_118 () ;
F_112 ( & V_228 ) ;
F_119 ( & V_228 ) ;
}
