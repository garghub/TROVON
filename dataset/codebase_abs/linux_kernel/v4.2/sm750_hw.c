int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
V_5 = 0 ;
V_2 -> V_8 = F_3 ( V_4 , 1 ) ;
V_2 -> V_9 = F_4 ( 2 ) ;
F_5 ( L_1 , V_2 -> V_8 ) ;
if( ( V_5 = F_6 ( V_4 , 1 , L_2 ) ) )
{
F_7 ( L_3 ) ;
goto exit;
}
V_2 -> V_10 = F_8 ( V_2 -> V_8 , V_2 -> V_9 ) ;
if( ! V_2 -> V_10 ) {
F_7 ( L_4 ) ;
V_5 = - V_11 ;
goto exit;
} else{
F_5 ( L_5 , V_2 -> V_10 ) ;
}
V_2 -> V_12 . V_13 = V_2 -> V_10 + V_14 ;
V_2 -> V_12 . V_15 = V_2 -> V_10 + V_16 ;
F_9 ( V_2 -> V_10 , V_2 -> V_17 , V_2 -> V_18 ) ;
V_2 -> V_19 = F_3 ( V_4 , 0 ) ;
V_2 -> V_20 = F_10 ( V_2 ) ;
F_5 ( L_6 ,
V_2 -> V_19 , V_2 -> V_20 ) ;
#if 0
if((ret = pci_request_region(pdev, 0, _moduleName_)))
{
pr_err("Can not request PCI regions.\n");
goto exit;
}
#endif
V_2 -> V_21 = F_11 ( V_2 -> V_19 , V_2 -> V_20 ) ;
if( ! V_2 -> V_21 ) {
F_7 ( L_7 ) ;
V_5 = - V_11 ;
goto exit;
} else{
F_5 ( L_8 , V_2 -> V_21 ) ;
}
exit:
return V_5 ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 ;
V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
V_23 = & V_7 -> V_24 . V_25 ;
if( V_23 -> V_26 == 0 )
V_23 -> V_26 = ( F_13 () == V_27 ) ?
V_28 :
V_29 ;
if( V_23 -> V_30 == 0 )
V_23 -> V_30 = V_23 -> V_26 ;
if( V_23 -> V_31 == 0 )
V_23 -> V_31 = V_23 -> V_26 / 3 ;
F_14 ( ( V_32 * ) & V_7 -> V_24 . V_25 ) ;
if( V_2 -> V_17 == 0x718 ) {
F_15 ( V_33 ,
F_16 ( F_17 ( V_33 ) , V_33 , V_34 , V_35 ) ) ;
}
#if 0
ddk750_initDVIDisp();
#endif
if( F_13 () != V_27 )
{
if( V_7 -> V_24 . V_36 ) {
F_15 ( V_37 ,
F_16 ( F_17 ( V_37 ) ,
V_37 ,
V_38 , V_39 ) ) ;
F_15 ( V_33 ,
F_16 ( F_17 ( V_33 ) ,
V_33 ,
V_40 , V_41 ) ) ;
} else{
F_15 ( V_37 ,
F_16 ( F_17 ( V_37 ) ,
V_37 ,
V_38 , V_35 ) ) ;
F_15 ( V_33 ,
F_16 ( F_17 ( V_33 ) ,
V_33 ,
V_40 , V_42 ) ) ;
}
switch ( V_7 -> V_24 . V_43 ) {
case V_44 :
case V_45 :
case V_46 :
F_15 ( V_47 ,
F_18 ( F_17 ( V_47 ) ,
V_47 ,
V_48 ,
V_7 -> V_24 . V_43 ) ) ;
break;
}
} else{
F_19 ( 0 , 1 ) ;
if ( F_20 ( 0xec , 0x4a ) == 0x95 )
{
F_5 ( L_9 ) ;
F_21 ( 0xec , 0x1d , 0x16 ) ;
F_21 ( 0xec , 0x21 , 0x9 ) ;
F_21 ( 0xec , 0x49 , 0xC0 ) ;
F_5 ( L_10 ) ;
}
}
if( ! V_2 -> V_49 ) {
F_22 ( V_2 ) ;
}
return 0 ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_23 () ;
return V_5 ;
}
int F_24 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
return 0 ;
}
int F_25 ( struct V_50 * V_51 ,
struct V_52 * V_53 , struct V_54 * V_55 )
{
int V_5 ;
T_2 V_56 ;
int V_57 ;
V_5 = 0 ;
V_56 = 0 ;
V_57 = * V_51 -> V_57 ;
if( F_13 () != V_27 ) {
if( V_57 == V_58 ) {
F_5 ( L_11 ) ;
if( V_51 -> V_59 & V_60 )
V_56 |= V_61 ;
if( V_51 -> V_59 & V_62 )
V_56 |= V_63 ;
} else{
F_5 ( L_12 ) ;
if( V_51 -> V_59 & V_60 )
V_56 |= V_64 ;
if( V_51 -> V_59 & V_62 )
V_56 |= V_65 ;
}
F_26 ( V_56 ) ;
} else{
T_3 V_66 ;
V_66 = F_17 ( V_67 ) ;
V_66 |= 0xf ;
F_15 ( V_67 , V_66 ) ;
}
F_5 ( L_13 ) ;
return V_5 ;
}
void F_27 ( struct V_50 * V_51 )
{
return;
}
int F_28 ( struct V_68 * V_69 , struct V_52 * V_53 )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_69 , struct V_70 , V_69 ) -> V_2 ;
switch ( V_53 -> V_71 ) {
case 8 :
case 16 :
break;
case 32 :
if ( V_2 -> V_18 == V_72 ) {
F_29 ( L_14 ) ;
return - V_73 ;
}
break;
default:
return - V_73 ;
}
return 0 ;
}
int F_30 ( struct V_68 * V_69 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
int V_5 , V_74 ;
T_3 V_66 ;
T_4 V_75 ;
T_5 clock ;
struct V_1 * V_2 ;
struct V_70 * V_76 ;
V_5 = 0 ;
V_76 = F_2 ( V_69 , struct V_70 , V_69 ) ;
V_2 = V_76 -> V_2 ;
#if 1
if( ! V_2 -> V_49 ) {
switch( V_53 -> V_71 ) {
case 8 :
V_74 = 0 ;
break;
case 16 :
V_74 = 1 ;
break;
case 32 :
default:
V_74 = 2 ;
break;
}
F_31 ( & V_2 -> V_12 , V_74 ) ;
}
#endif
V_75 . V_77 = F_32 ( V_53 -> V_78 ) ;
V_75 . V_79 = ( V_53 -> V_80 & V_81 ) ? V_82 : V_83 ;
V_75 . V_84 = ( V_53 -> V_80 & V_85 ) ? V_82 : V_83 ;
V_75 . V_86 = ( V_53 -> V_80 & V_87 ) ? V_82 : V_83 ;
V_75 . V_88 = V_53 -> V_89 ;
V_75 . V_90 = V_53 -> V_91 ;
V_75 . V_92 = V_53 -> V_89 + V_53 -> V_93 ;
V_75 . V_94 = V_53 -> V_89 + V_53 -> V_95 + V_53 -> V_93 + V_53 -> V_91 ;
V_75 . V_96 = V_53 -> V_97 ;
V_75 . V_98 = V_53 -> V_99 ;
V_75 . V_100 = V_53 -> V_97 + V_53 -> V_101 ;
V_75 . V_102 = V_53 -> V_97 + V_53 -> V_103 + V_53 -> V_101 + V_53 -> V_99 ;
if( V_69 -> V_57 != V_104 )
clock = V_105 ;
else
clock = V_106 ;
F_29 ( L_15 , V_75 . V_77 ) ;
V_5 = F_33 ( & V_75 , clock ) ;
if( V_5 ) {
F_7 ( L_16 ) ;
goto exit;
}
if( V_69 -> V_57 != V_104 ) {
F_15 ( V_107 ,
F_16 ( 0 , V_107 , V_108 , V_109 ) |
F_16 ( 0 , V_107 , V_110 , V_111 ) |
F_18 ( 0 , V_107 , V_112 , V_69 -> V_113 ) ) ;
V_66 = V_53 -> V_89 * ( V_53 -> V_71 >> 3 ) ;
V_66 = F_34 ( V_69 -> V_114 , V_66 ) ;
F_15 ( V_115 ,
F_18 ( 0 , V_115 , V_116 , V_66 ) |
F_18 ( 0 , V_115 , V_117 , V_55 -> V_118 ) ) ;
F_15 ( V_119 ,
F_18 ( 0 , V_119 , V_116 , V_53 -> V_89 - 1 ) |
F_18 ( 0 , V_119 , V_120 , V_53 -> V_121 ) ) ;
F_15 ( V_122 ,
F_18 ( 0 , V_122 , V_123 , V_53 -> V_124 - 1 ) |
F_18 ( 0 , V_122 , V_125 , V_53 -> V_126 ) ) ;
F_15 ( V_127 , 0 ) ;
F_15 ( V_128 ,
F_18 ( 0 , V_128 , V_129 , V_53 -> V_97 - 1 ) |
F_18 ( 0 , V_128 , V_130 , V_53 -> V_89 - 1 ) ) ;
V_66 = F_17 ( V_47 ) ;
F_15 ( V_47 ,
F_18 ( V_66 ,
V_47 , V_131 ,
( V_53 -> V_71 >> 4 )
) ) ;
} else{
F_15 ( V_132 , V_69 -> V_113 ) ;
V_66 = V_53 -> V_89 * ( V_53 -> V_71 >> 3 ) ;
V_66 = F_34 ( V_69 -> V_114 , V_66 ) ;
F_15 ( V_133 ,
F_18 ( 0 , V_133 , V_116 , V_66 ) |
F_18 ( 0 , V_133 , V_117 , V_55 -> V_118 ) ) ;
V_66 = F_17 ( V_134 ) ;
V_66 = F_18 ( V_66 , V_134 , V_131 , V_53 -> V_71 >> 4 ) ;
F_15 ( V_134 , V_66 ) ;
}
exit:
return V_5 ;
}
void F_35 ( struct V_68 * V_69 )
{
return;
}
int F_36 ( struct V_68 * V_69 , T_6 V_135 ,
T_6 V_136 , T_6 V_137 , T_6 V_138 )
{
static unsigned int V_139 [] = { V_140 , V_141 } ;
F_15 ( V_139 [ V_69 -> V_57 ] + V_135 * 4 , ( V_136 << 16 ) | ( V_137 << 8 ) | V_138 ) ;
return 0 ;
}
int F_37 ( struct V_50 * V_51 , int V_142 ) {
int V_143 , V_144 ;
switch( V_142 )
{
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_146 :
#else
case V_147 :
#endif
V_143 = V_148 ;
V_144 = V_149 ;
break;
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_150 :
V_143 = V_148 ;
V_144 = V_151 ;
break;
#endif
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_152 :
#else
case V_153 :
#endif
V_143 = V_154 ;
V_144 = V_151 ;
break;
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_155 :
#else
case V_156 :
#endif
V_143 = V_157 ;
V_144 = V_151 ;
break;
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_158 :
#else
case V_159 :
#endif
V_143 = V_160 ;
V_144 = V_151 ;
break;
default:
return - V_73 ;
}
if( V_51 -> V_59 & V_62 ) {
F_15 ( V_134 , F_18 ( F_17 ( V_134 ) , V_134 , V_40 , V_143 ) ) ;
F_15 ( V_134 , F_18 ( F_17 ( V_134 ) , V_134 , V_161 , V_144 ) ) ;
}
return 0 ;
}
int F_39 ( struct V_50 * V_51 , int V_142 )
{
unsigned int V_143 , V_162 , V_144 ;
V_143 = V_162 = V_144 = 0 ;
switch ( V_142 )
{
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_146 :
#else
case V_147 :
#endif
F_5 ( L_17 ) ;
V_143 = V_163 ;
V_162 = V_164 ;
V_144 = V_149 ;
break;
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_150 :
F_5 ( L_18 ) ;
V_143 = V_163 ;
V_162 = V_165 ;
V_144 = V_151 ;
break;
#endif
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_152 :
#else
case V_153 :
#endif
V_143 = V_166 ;
V_162 = V_165 ;
V_144 = V_151 ;
break;
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_155 :
#else
case V_156 :
#endif
V_143 = V_167 ;
V_162 = V_165 ;
V_144 = V_151 ;
break;
#if V_145 >= F_38 ( 2 , 6 , 10 )
case V_158 :
#else
case V_159 :
#endif
V_143 = V_168 ;
V_162 = V_165 ;
V_144 = V_151 ;
break;
}
if( V_51 -> V_59 & V_62 ) {
F_15 ( V_33 , F_18 ( F_17 ( V_33 ) , V_33 , V_40 , V_143 ) ) ;
F_15 ( V_134 , F_18 ( F_17 ( V_134 ) , V_134 , V_161 , V_144 ) ) ;
}
if( V_51 -> V_59 & V_60 ) {
F_15 ( V_47 , F_18 ( F_17 ( V_47 ) , V_47 , V_169 , V_162 ) ) ;
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
T_3 V_66 ;
F_40 ( 1 ) ;
if( F_13 () == V_27 ) {
V_66 = F_17 ( V_170 ) ;
V_66 = F_16 ( V_66 , V_170 , V_171 , V_35 ) ;
F_15 ( V_170 , V_66 ) ;
V_66 = F_17 ( V_170 ) ;
V_66 = F_16 ( V_66 , V_170 , V_171 , V_39 ) ;
F_15 ( V_170 , V_66 ) ;
} else{
V_66 = F_17 ( V_33 ) ;
V_66 = F_16 ( V_66 , V_33 , V_171 , V_35 ) ;
F_15 ( V_33 , V_66 ) ;
V_66 = F_17 ( V_33 ) ;
V_66 = F_16 ( V_66 , V_33 , V_171 , V_39 ) ;
F_15 ( V_33 , V_66 ) ;
}
V_2 -> V_12 . V_172 ( & V_2 -> V_12 ) ;
}
int F_41 ( void )
{
int V_173 = 0x10000000 ;
while( V_173 -- ) {
unsigned int V_174 = F_17 ( V_175 ) ;
if( ( F_42 ( V_174 , V_175 , V_176 ) == V_177 ) &&
( F_42 ( V_174 , V_175 , V_178 ) == V_179 ) &&
( F_42 ( V_174 , V_175 , V_180 ) == V_181 ) )
{
return 0 ;
}
}
return - 1 ;
}
int F_43 ( void )
{
int V_173 = 0x10000000 ;
while( V_173 -- ) {
unsigned int V_174 = F_17 ( V_33 ) ;
if( ( F_42 ( V_174 , V_33 , V_176 ) == V_182 ) &&
( F_42 ( V_174 , V_33 , V_178 ) == V_183 ) &&
( F_42 ( V_174 , V_33 , V_180 ) == V_184 ) )
{
return 0 ;
}
}
return - 1 ;
}
int F_44 ( struct V_68 * V_69 ,
const struct V_52 * V_53 ,
const struct V_185 * V_186 )
{
T_7 V_187 ;
if ( ( V_53 -> V_121 + V_53 -> V_89 > V_53 -> V_188 ) ||
( V_53 -> V_126 + V_53 -> V_97 > V_53 -> V_124 ) ) {
return - V_73 ;
}
V_187 = V_53 -> V_126 * V_186 -> V_55 . V_118 +
( ( V_53 -> V_121 * V_53 -> V_71 ) >> 3 ) ;
V_187 += V_69 -> V_113 ;
if ( V_69 -> V_57 == V_58 ) {
F_15 ( V_107 ,
F_18 ( F_17 ( V_107 ) ,
V_107 , V_112 , V_187 ) ) ;
} else {
F_15 ( V_132 ,
F_18 ( F_17 ( V_132 ) ,
V_132 , V_112 , V_187 ) ) ;
}
return 0 ;
}
