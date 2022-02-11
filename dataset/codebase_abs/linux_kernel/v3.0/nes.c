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
V_54 = F_26 ( V_12 ) ;
if ( V_54 == NULL ) {
F_2 ( V_50 , L_12 ) ;
return;
}
V_54 -> V_80 = 0 ;
V_54 -> V_81 = 1 ;
V_54 -> V_82 = F_15 ;
V_54 -> V_56 = V_49 ;
V_78 = & V_54 -> V_78 ;
F_27 ( V_78 , V_12 ) ;
V_79 = V_83 | V_84 ;
if ( V_49 -> V_85 ) {
V_79 |= V_86 ;
V_49 -> V_85 = 0 ;
}
F_28 ( V_78 -> V_87 , V_88 , V_79 ) ;
F_28 ( V_78 -> V_87 , V_89 , V_49 -> V_62 . V_71 ) ;
V_75 = ( T_1 ) V_49 -> V_90 ;
F_29 ( V_78 -> V_87 , V_91 , V_75 ) ;
F_30 ( V_12 , V_54 ) ;
}
}
struct V_46 * F_31 ( struct V_92 * V_76 , int V_93 )
{
struct V_14 * V_15 = F_22 ( V_76 ) ;
struct V_11 * V_12 = V_15 -> V_12 ;
struct V_57 * V_58 = V_12 -> V_58 ;
if ( ( V_93 < V_73 ) || ( V_93 >= ( V_73 + V_58 -> V_94 ) ) )
return NULL ;
return & V_58 -> V_72 [ V_93 - V_73 ] -> V_47 ;
}
static void F_32 ( struct V_7 * V_13 )
{
F_2 ( V_95 , L_13 ,
V_13 -> V_20 , V_13 -> V_28 , V_13 -> V_96 ) ;
}
static T_3 F_33 ( int V_96 , void * V_97 )
{
struct V_11 * V_12 = (struct V_11 * ) V_97 ;
int V_98 = 0 ;
T_2 V_99 ;
T_2 V_100 ;
T_2 V_101 ;
T_2 V_102 ;
T_2 V_103 ;
if ( V_12 -> V_104 ) {
V_98 = 1 ;
} else {
if ( F_34 ( V_12 -> V_58 -> V_105 == V_106 ) ) {
V_99 = F_35 ( V_12 -> V_107 + V_108 ) ;
if ( V_99 & 0x80000000 ) {
V_101 = F_35 ( V_12 -> V_107 + V_109 ) ;
V_100 = V_12 -> V_100 ;
if ( V_101 & V_100 ) {
if ( ( V_101 & V_100 ) & ( ~ ( V_110 | V_111 ) ) ) {
V_98 = 1 ;
} else {
if ( ( ( V_101 & V_100 ) & V_110 ) == V_110 ) {
V_103 = F_35 ( V_12 -> V_107 + V_112 ) ;
if ( ( V_103 & V_12 -> V_113 ) != 0 ) {
V_98 = 1 ;
}
}
if ( ( ( ( V_101 & V_100 ) & V_111 ) == V_111 ) &&
( V_98 == 0 ) ) {
V_102 = F_35 ( V_12 -> V_107 + V_114 ) ;
if ( ( V_102 & V_12 -> V_115 ) != 0 ) {
V_98 = 1 ;
}
}
}
if ( V_98 ) {
F_36 ( V_12 -> V_107 + V_108 , V_99 & ( ~ 0x80000000 ) ) ;
V_99 = F_35 ( V_12 -> V_107 + V_108 ) ;
V_12 -> V_101 = V_101 ;
V_12 -> V_116 = 1 ;
}
}
}
} else {
V_98 = F_35 ( V_12 -> V_107 + V_117 ) ;
}
}
if ( V_98 ) {
if ( F_37 ( V_12 ) == 0 ) {
F_38 ( & V_12 -> V_118 ) ;
}
return V_119 ;
} else {
return V_120 ;
}
}
static int T_4 F_39 ( struct V_121 * V_26 , const struct V_122 * V_123 )
{
struct V_7 * V_13 = NULL ;
struct V_11 * V_12 = NULL ;
int V_124 = 0 ;
void T_5 * V_125 = NULL ;
T_6 V_105 ;
assert ( V_26 != NULL ) ;
assert ( V_123 != NULL ) ;
F_23 (KERN_INFO PFX L_14 ,
DRV_VERSION, pci_name(pcidev)) ;
V_124 = F_40 ( V_26 ) ;
if ( V_124 ) {
F_23 (KERN_ERR PFX L_15 , pci_name(pcidev)) ;
goto V_126;
}
F_2 ( V_95 , L_16 ,
( long unsigned int ) F_41 ( V_26 , V_127 ) ,
( long unsigned int ) F_42 ( V_26 , V_127 ) ) ;
F_2 ( V_95 , L_17 ,
( long unsigned int ) F_41 ( V_26 , V_128 ) ,
( long unsigned int ) F_42 ( V_26 , V_128 ) ) ;
if ( ! ( F_43 ( V_26 , V_127 ) & V_129 ) ||
! ( F_43 ( V_26 , V_128 ) & V_129 ) ) {
F_23 (KERN_ERR PFX L_18 ) ;
V_124 = - V_130 ;
goto V_131;
}
V_124 = F_44 ( V_26 , V_132 ) ;
if ( V_124 ) {
F_23 (KERN_ERR PFX L_19 , pci_name(pcidev)) ;
goto V_131;
}
if ( ( sizeof( V_133 ) > 4 ) ) {
V_124 = F_45 ( V_26 , F_46 ( 64 ) ) ;
if ( V_124 < 0 ) {
F_23 (KERN_ERR PFX L_20 ) ;
goto V_134;
}
V_124 = F_47 ( V_26 , F_46 ( 64 ) ) ;
if ( V_124 ) {
F_23 (KERN_ERR PFX L_21 ) ;
goto V_134;
}
} else {
V_124 = F_45 ( V_26 , F_46 ( 32 ) ) ;
if ( V_124 < 0 ) {
F_23 (KERN_ERR PFX L_22 ) ;
goto V_134;
}
V_124 = F_47 ( V_26 , F_46 ( 32 ) ) ;
if ( V_124 ) {
F_23 (KERN_ERR PFX L_23 ) ;
goto V_134;
}
}
F_48 ( V_26 ) ;
V_12 = F_49 ( sizeof( struct V_11 ) , V_135 ) ;
if ( ! V_12 ) {
F_23 (KERN_ERR PFX L_24 , pci_name(pcidev)) ;
V_124 = - V_136 ;
goto V_134;
}
F_2 ( V_95 , L_25 , V_12 ) ;
V_12 -> V_26 = V_26 ;
F_50 ( V_26 , V_12 ) ;
F_51 ( V_26 , 0x0008 , & V_105 ) ;
F_2 ( V_95 , L_26 , V_105 ) ;
F_52 ( & V_12 -> V_137 ) ;
V_125 = F_53 ( F_41 ( V_26 , V_127 ) ,
F_42 ( V_26 , V_127 ) ) ;
if ( V_125 == NULL ) {
F_23 (KERN_ERR PFX L_27 ) ;
V_124 = - V_138 ;
goto V_139;
}
V_12 -> V_107 = V_125 ;
V_12 -> V_140 = 0x50 + ( F_7 ( V_26 -> V_27 ) * 8 ) + V_125 ;
F_36 ( V_12 -> V_107 + V_108 , 0x7fffffff ) ;
if ( V_141 & V_142 ) {
if ( ! F_54 ( V_12 -> V_26 ) ) {
V_12 -> V_104 = 1 ;
F_2 ( V_95 , L_28 ,
F_55 ( V_26 ) ) ;
} else {
F_2 ( V_95 , L_29 ,
F_55 ( V_26 ) ) ;
}
} else {
F_2 ( V_95 , L_30 ,
F_55 ( V_26 ) ) ;
}
V_12 -> V_143 = F_41 ( V_12 -> V_26 , V_127 ) ;
V_12 -> V_144 = F_41 ( V_12 -> V_26 , V_128 ) ;
V_12 -> V_58 = F_56 ( V_12 , V_105 ) ;
if ( ! V_12 -> V_58 ) {
F_23 (KERN_ERR PFX L_31 ) ;
V_124 = - V_136 ;
goto V_145;
}
V_12 -> V_58 -> V_146 = V_147 ;
V_12 -> V_58 -> V_148 = V_148 ;
V_12 -> V_149 = 1 ;
V_12 -> V_150 = V_12 -> V_58 -> V_150 ;
if ( V_12 -> V_58 -> V_151 [ 0 ] == V_152 ) {
switch ( F_7 ( V_12 -> V_26 -> V_27 ) %
V_12 -> V_58 -> V_153 ) {
case 1 :
V_12 -> V_154 = 2 ;
break;
case 2 :
V_12 -> V_154 = 1 ;
break;
case 3 :
V_12 -> V_154 = 3 ;
break;
case 0 :
default:
V_12 -> V_154 = 0 ;
}
} else {
V_12 -> V_154 = F_7 ( V_12 -> V_26 -> V_27 ) %
V_12 -> V_58 -> V_153 ;
}
if ( ( V_155 ||
( ( V_12 -> V_58 -> V_151 [ 0 ] == V_156 ) &&
( V_105 == V_157 ) ) ) &&
( F_57 ( V_26 ) > 256 ) ) {
if ( F_58 ( V_26 , 256 ) )
F_23 (KERN_ERR PFX L_32
L_33 ) ;
else
F_2 ( V_95 , L_34
L_33 ) ;
}
F_59 ( & V_12 -> V_118 , V_158 , ( unsigned long ) V_12 ) ;
if ( F_60 ( V_12 ) ) {
V_124 = - V_130 ;
goto V_159;
}
F_36 ( V_12 -> V_107 + V_160 , V_161 |
F_7 ( V_12 -> V_26 -> V_27 ) ) ;
F_35 ( V_12 -> V_107 + V_160 ) ;
V_12 -> V_100 = ( 0x101 << F_7 ( V_12 -> V_26 -> V_27 ) ) |
( 1 << ( F_7 ( V_12 -> V_26 -> V_27 ) + 16 ) ) ;
if ( F_7 ( V_12 -> V_26 -> V_27 ) < 4 ) {
V_12 -> V_100 |= ( 1 << ( F_7 ( V_12 -> V_154 ) + 24 ) ) ;
}
if ( F_7 ( V_12 -> V_26 -> V_27 ) == 0 ) {
V_12 -> V_115 = V_162 | V_163 ;
V_12 -> V_100 |= V_111 ;
} else {
V_12 -> V_115 = 0 ;
}
V_12 -> V_115 |= ( 1 << ( F_7 ( V_12 -> V_26 -> V_27 ) + 16 ) ) ;
F_6 ( V_12 , V_164 , 0 ) ;
F_6 ( V_12 , V_165 , 0 ) ;
F_6 ( V_12 , V_166 , 0x00001265 ) ;
F_6 ( V_12 , V_167 , 0x18021804 ) ;
F_6 ( V_12 , V_168 , 0x17801790 ) ;
V_12 -> V_113 = 0x101 << F_7 ( V_12 -> V_26 -> V_27 ) ;
V_12 -> V_58 -> V_113 |= V_12 -> V_113 ;
F_2 ( V_95 , L_35 ,
F_7 ( V_12 -> V_26 -> V_27 ) ,
V_12 -> V_113 , V_12 -> V_58 -> V_113 ) ;
F_36 ( V_12 -> V_107 + V_169 , ~ ( V_12 -> V_115 ) ) ;
F_61 ( & V_12 -> V_170 , & V_171 ) ;
V_124 = F_62 ( V_26 -> V_96 , F_33 , V_172 , V_132 , V_12 ) ;
if ( V_124 ) {
F_23 (KERN_ERR PFX L_36 ,
pci_name(pcidev), pcidev->irq) ;
goto V_173;
}
F_36 ( V_12 -> V_107 + V_108 , ~ V_12 -> V_100 ) ;
if ( V_174 == 0 ) {
F_63 ( & V_175 ) ;
F_64 ( & V_176 ) ;
}
V_174 ++ ;
F_65 ( & V_12 -> V_177 , V_178 ) ;
if ( ( V_13 = F_66 ( V_12 , V_125 ) ) == NULL )
goto V_179;
V_124 = F_67 ( V_13 ) ;
if ( V_124 ) {
F_23 (KERN_ERR PFX L_37 , ret) ;
F_68 ( V_13 ) ;
goto V_179;
}
F_32 ( V_13 ) ;
V_12 -> V_180 ++ ;
V_12 -> V_58 -> V_180 ++ ;
F_23 (KERN_INFO PFX L_38 ,
pci_name(pcidev)) ;
return 0 ;
V_179:
F_23 (KERN_ERR PFX L_39 ) ;
while ( V_12 -> V_180 > 0 ) {
V_12 -> V_180 -- ;
V_12 -> V_58 -> V_180 -- ;
F_69 ( V_12 -> V_13 [ V_12 -> V_180 ] ) ;
F_68 ( V_12 -> V_13 [ V_12 -> V_180 ] ) ;
}
F_2 ( V_95 , L_40 ,
V_12 -> V_180 , V_12 -> V_58 -> V_180 ) ;
V_174 -- ;
if ( V_174 == 0 ) {
F_70 ( & V_176 ) ;
F_71 ( & V_175 ) ;
}
F_72 ( & V_12 -> V_170 ) ;
F_73 ( V_12 ) ;
V_173:
F_23 (KERN_ERR PFX L_41 ) ;
F_74 ( V_26 -> V_96 , V_12 ) ;
if ( V_12 -> V_104 ) {
F_75 ( V_26 ) ;
}
V_159:
F_23 (KERN_ERR PFX L_42 ) ;
F_76 ( & V_12 -> V_118 ) ;
F_77 ( V_12 -> V_58 ) ;
V_145:
F_23 (KERN_ERR PFX L_43 ) ;
F_78 ( V_12 -> V_107 ) ;
V_139:
F_23 (KERN_ERR PFX L_44 ) ;
F_20 ( V_12 ) ;
V_134:
F_79 ( V_26 ) ;
V_131:
F_80 ( V_26 ) ;
V_126:
return V_124 ;
}
static void T_7 F_81 ( struct V_121 * V_26 )
{
struct V_11 * V_12 = F_82 ( V_26 ) ;
struct V_7 * V_13 ;
int V_181 = 0 ;
unsigned long V_55 ;
if ( V_12 -> V_180 ) {
V_13 = V_12 -> V_13 [ V_181 ] ;
if ( V_13 ) {
F_83 ( V_13 ) ;
F_69 ( V_13 ) ;
F_68 ( V_13 ) ;
V_12 -> V_13 [ V_181 ] = NULL ;
V_12 -> V_180 -- ;
V_12 -> V_58 -> V_180 -- ;
}
}
V_174 -- ;
if ( V_174 == 0 ) {
F_70 ( & V_176 ) ;
F_71 ( & V_175 ) ;
}
F_72 ( & V_12 -> V_170 ) ;
F_73 ( V_12 ) ;
F_74 ( V_26 -> V_96 , V_12 ) ;
F_76 ( & V_12 -> V_118 ) ;
F_17 ( & V_12 -> V_58 -> V_182 , V_55 ) ;
if ( V_12 -> V_183 ) {
F_18 ( & V_12 -> V_58 -> V_182 , V_55 ) ;
F_84 ( & V_12 -> V_177 ) ;
} else {
F_18 ( & V_12 -> V_58 -> V_182 , V_55 ) ;
}
F_77 ( V_12 -> V_58 ) ;
if ( V_12 -> V_104 ) {
F_75 ( V_26 ) ;
}
F_78 ( V_12 -> V_107 ) ;
F_20 ( V_12 ) ;
F_79 ( V_26 ) ;
F_80 ( V_26 ) ;
F_50 ( V_26 , NULL ) ;
}
static T_8 F_85 ( struct V_184 * V_185 , char * V_186 )
{
unsigned int V_27 = 0xffffffff ;
unsigned char V_187 = 0xff ;
unsigned int V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_27 = V_12 -> V_26 -> V_27 ;
V_187 = V_12 -> V_26 -> V_190 -> V_191 ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_45 , V_187 , V_27 ) ;
}
static T_8 F_86 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
V_189 = F_87 ( V_194 , & V_194 , 10 ) ;
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_89 ( struct V_184 * V_185 , char * V_186 )
{
T_2 V_195 = 0xdead ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_195 = F_35 ( V_12 -> V_107 + V_196 ) ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_46 , V_195 ) ;
}
static T_8 F_90 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
T_2 V_197 ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' ) {
V_197 = F_87 ( V_194 , & V_194 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
F_36 ( V_12 -> V_107 + V_196 , V_197 ) ;
break;
}
V_188 ++ ;
}
}
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_91 ( struct V_184 * V_185 , char * V_186 )
{
T_2 V_198 = 0xdead ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_198 = F_35 ( V_12 -> V_107 + V_199 ) ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_46 , V_198 ) ;
}
static T_8 F_92 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
T_2 V_197 ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' ) {
V_197 = F_87 ( V_194 , & V_194 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
F_36 ( V_12 -> V_107 + V_199 , V_197 ) ;
break;
}
V_188 ++ ;
}
}
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_93 ( struct V_184 * V_185 , char * V_186 )
{
T_2 V_200 = 0xdead ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_200 = F_35 ( V_12 -> V_107 + V_201 ) ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_46 , V_200 ) ;
}
static T_8 F_94 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
T_2 V_197 ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' ) {
V_197 = F_87 ( V_194 , & V_194 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
F_36 ( V_12 -> V_107 + V_201 , V_197 ) ;
break;
}
V_188 ++ ;
}
}
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_95 ( struct V_184 * V_185 , char * V_186 )
{
T_2 V_202 = 0xdead ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_202 = F_35 ( V_12 -> V_107 + V_203 ) ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_46 , V_202 ) ;
}
static T_8 F_96 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
T_2 V_197 ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' ) {
V_197 = F_87 ( V_194 , & V_194 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
F_36 ( V_12 -> V_107 + V_203 , V_197 ) ;
break;
}
V_188 ++ ;
}
}
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_97 ( struct V_184 * V_185 , char * V_186 )
{
return snprintf ( V_186 , V_192 , L_46 , V_204 ) ;
}
static T_8 F_98 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' )
V_204 = F_87 ( V_194 , & V_194 , 16 ) ;
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_99 ( struct V_184 * V_185 , char * V_186 )
{
T_2 V_205 = 0xdead ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_205 = F_35 ( V_12 -> V_107 + V_204 ) ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_46 , V_205 ) ;
}
static T_8 F_100 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
T_2 V_197 ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' ) {
V_197 = F_87 ( V_194 , & V_194 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
F_36 ( V_12 -> V_107 + V_204 , V_197 ) ;
break;
}
V_188 ++ ;
}
}
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_101 ( struct V_184 * V_185 , char * V_186 )
{
return snprintf ( V_186 , V_192 , L_46 , V_206 ) ;
}
static T_8 F_102 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' )
V_206 = F_87 ( V_194 , & V_194 , 16 ) ;
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_103 ( struct V_184 * V_185 , char * V_186 )
{
T_2 V_207 = 0xdead ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_207 = F_104 ( V_12 , V_206 ) ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_46 , V_207 ) ;
}
static T_8 F_105 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
char * V_194 = ( char * ) V_186 ;
T_2 V_197 ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
if ( V_194 [ 1 ] == 'x' || V_194 [ 1 ] == 'X' || V_194 [ 0 ] == 'x' || V_194 [ 0 ] == 'X' ) {
V_197 = F_87 ( V_194 , & V_194 , 16 ) ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
F_6 ( V_12 , V_206 , V_197 ) ;
break;
}
V_188 ++ ;
}
}
return F_88 ( V_186 , V_193 ) ;
}
static T_8 F_106 ( struct V_184 * V_185 , char * V_186 )
{
T_2 V_208 = 0xdead ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_208 = V_12 -> V_58 -> V_148 ;
break;
}
V_188 ++ ;
}
return snprintf ( V_186 , V_192 , L_47 , V_208 ) ;
}
static T_8 F_107 ( struct V_184 * V_185 ,
const char * V_186 , T_9 V_193 )
{
unsigned long V_208 ;
T_2 V_209 ;
T_2 V_188 = 0 ;
struct V_11 * V_12 ;
if ( F_108 ( V_186 , 0 , & V_208 ) < 0 )
return - V_210 ;
F_3 (nesdev, &nes_dev_list, list) {
if ( V_188 == V_189 ) {
V_12 -> V_58 -> V_148 = V_208 ;
V_209 = F_104 ( V_12 ,
V_211 ) ;
F_6 ( V_12 , V_211 ,
( ( V_208 << 1 ) |
( V_209 & 0x00000001 ) ) ) ;
break;
}
V_188 ++ ;
}
return F_88 ( V_186 , V_193 ) ;
}
static int F_109 ( struct V_212 * V_213 )
{
int error ;
error = F_110 ( & V_213 -> V_214 , & V_215 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_216 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_217 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_218 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_219 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_220 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_221 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_222 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_223 ) ;
error |= F_110 ( & V_213 -> V_214 , & V_224 ) ;
return error ;
}
static void F_111 ( struct V_212 * V_213 )
{
F_112 ( & V_213 -> V_214 , & V_215 ) ;
F_112 ( & V_213 -> V_214 , & V_216 ) ;
F_112 ( & V_213 -> V_214 , & V_217 ) ;
F_112 ( & V_213 -> V_214 , & V_218 ) ;
F_112 ( & V_213 -> V_214 , & V_219 ) ;
F_112 ( & V_213 -> V_214 , & V_220 ) ;
F_112 ( & V_213 -> V_214 , & V_221 ) ;
F_112 ( & V_213 -> V_214 , & V_222 ) ;
F_112 ( & V_213 -> V_214 , & V_223 ) ;
F_112 ( & V_213 -> V_214 , & V_224 ) ;
}
static int T_10 F_113 ( void )
{
int V_225 ;
int V_226 ;
V_225 = F_114 () ;
if ( V_225 ) {
F_23 (KERN_ERR PFX L_48 ) ;
return V_225 ;
}
V_225 = F_115 ( & V_227 ) ;
if ( V_225 >= 0 ) {
V_226 = F_109 ( & V_227 ) ;
if ( V_226 < 0 )
F_23 (KERN_ERR PFX L_49 ) ;
}
return V_225 ;
}
static void T_11 F_116 ( void )
{
F_117 () ;
F_111 ( & V_227 ) ;
F_118 ( & V_227 ) ;
}
