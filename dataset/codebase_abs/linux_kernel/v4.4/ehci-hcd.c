static unsigned F_1 ( struct V_1 * V_2 )
{
unsigned V_3 ;
V_3 = F_2 ( V_2 , & V_2 -> V_4 -> V_5 ) ;
if ( F_3 ( ( V_3 & 7 ) == 0 ) )
V_3 = F_2 ( V_2 , & V_2 -> V_4 -> V_5 ) ;
return V_3 ;
}
static inline unsigned F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
return F_1 ( V_2 ) ;
return F_2 ( V_2 , & V_2 -> V_4 -> V_5 ) ;
}
int F_5 ( struct V_1 * V_2 , void T_1 * V_7 ,
T_2 V_8 , T_2 V_9 , int V_10 )
{
T_2 V_11 ;
do {
V_11 = F_2 ( V_2 , V_7 ) ;
if ( V_11 == ~ ( T_2 ) 0 )
return - V_12 ;
V_11 &= V_8 ;
if ( V_11 == V_9 )
return 0 ;
F_6 ( 1 ) ;
V_10 -- ;
} while ( V_10 > 0 );
return - V_13 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_2 V_14 ;
V_14 = F_2 ( V_2 , & V_2 -> V_4 -> V_15 ) ;
return ( V_14 & 3 ) == V_16 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_2 V_17 ;
F_9 ( & V_2 -> V_18 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
if ( F_11 ( V_2 ) && ! F_7 ( V_2 ) ) {
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
V_2 -> V_20 &= ~ V_21 ;
V_17 = F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_17 &= ~ ( V_21 | V_22 ) ;
F_10 ( V_2 , V_17 , & V_2 -> V_4 -> V_20 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_13 ( F_14 ( V_2 ) -> V_23 ) ;
return F_5 ( V_2 , & V_2 -> V_4 -> V_24 ,
V_25 , V_25 , 16 * 125 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 V_14 ;
V_14 = F_2 ( V_2 , & V_2 -> V_4 -> V_15 ) ;
V_14 |= V_16 ;
if ( F_16 ( V_2 ) )
V_14 |= V_26 ;
F_10 ( V_2 , V_14 , & V_2 -> V_4 -> V_15 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_27 ;
T_2 V_20 = F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
if ( V_2 -> V_28 && ! F_18 ( F_14 ( V_2 ) ) )
V_2 -> V_28 = NULL ;
V_20 |= V_29 ;
F_19 ( V_2 , L_1 , V_20 ) ;
F_10 ( V_2 , V_20 , & V_2 -> V_4 -> V_20 ) ;
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = V_33 ;
V_27 = F_5 ( V_2 , & V_2 -> V_4 -> V_20 ,
V_29 , 0 , 250 * 1000 ) ;
if ( V_2 -> V_34 ) {
F_10 ( V_2 , V_35 | V_36 ,
& V_2 -> V_4 -> V_37 ) ;
F_10 ( V_2 , V_38 , & V_2 -> V_4 -> V_39 ) ;
}
if ( V_27 )
return V_27 ;
if ( F_11 ( V_2 ) )
F_15 ( V_2 ) ;
if ( V_2 -> V_28 )
F_20 ( F_14 ( V_2 ) ) ;
V_2 -> V_40 = V_2 -> V_41 =
V_2 -> V_42 = 0 ;
return V_27 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_17 ;
if ( V_2 -> V_30 != V_43 )
return;
V_17 = ( V_2 -> V_20 << 10 ) & ( V_44 | V_45 ) ;
F_5 ( V_2 , & V_2 -> V_4 -> V_24 , V_44 | V_45 , V_17 ,
16 * 125 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_20 &= ~ ( V_46 | V_47 ) ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_5 ( V_2 , & V_2 -> V_4 -> V_24 , V_44 | V_45 , 0 ,
16 * 125 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_48 = F_23 ( V_2 -> V_49 ) ;
while ( V_48 -- ) {
F_10 ( V_2 , V_50 ,
& V_2 -> V_4 -> V_51 [ V_48 ] ) ;
F_12 ( & V_2 -> V_18 ) ;
F_24 ( V_2 , V_48 , false ) ;
F_9 ( & V_2 -> V_18 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_30 = V_31 ;
F_22 ( V_2 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_52 ) ;
F_12 ( & V_2 -> V_18 ) ;
}
static void F_26 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_55 = true ;
V_2 -> V_30 = V_56 ;
V_2 -> V_57 = 0 ;
F_12 ( & V_2 -> V_18 ) ;
F_25 ( V_2 ) ;
F_28 ( & V_2 -> V_58 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 ) {
V_2 -> V_60 = true ;
return;
}
V_2 -> V_59 = true ;
V_61:
V_2 -> V_60 = false ;
if ( V_2 -> V_62 )
F_30 ( V_2 ) ;
if ( V_2 -> V_63 > 0 )
F_31 ( V_2 ) ;
if ( V_2 -> V_64 > 0 )
F_32 ( V_2 ) ;
if ( V_2 -> V_60 )
goto V_61;
V_2 -> V_59 = false ;
F_33 ( V_2 ) ;
}
static void F_34 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
F_35 ( V_2 , L_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_57 = 0 ;
F_12 ( & V_2 -> V_18 ) ;
F_21 ( V_2 ) ;
F_25 ( V_2 ) ;
F_17 ( V_2 ) ;
F_28 ( & V_2 -> V_58 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_38 ( V_2 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_65 == 1 )
F_40 () ;
F_41 ( V_2 , L_3 ,
F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ) ;
}
static int F_42 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
T_2 V_17 ;
int V_27 ;
T_2 V_66 ;
struct V_67 * V_68 ;
F_43 ( & V_2 -> V_18 ) ;
V_2 -> V_69 = 1 ;
F_44 ( & V_2 -> V_58 , V_70 , V_71 ) ;
V_2 -> V_58 . V_72 = V_73 ;
V_2 -> V_74 = V_75 ;
V_66 = F_2 ( V_2 , & V_2 -> V_76 -> V_66 ) ;
V_2 -> V_77 = 100 ;
V_2 -> V_78 = V_79 ;
F_45 ( & V_2 -> V_80 ) ;
F_45 ( & V_2 -> V_81 ) ;
F_45 ( & V_2 -> V_82 ) ;
F_45 ( & V_2 -> V_83 ) ;
F_45 ( & V_2 -> V_84 ) ;
F_45 ( & V_2 -> V_85 ) ;
F_45 ( & V_2 -> V_86 ) ;
F_45 ( & V_2 -> V_87 ) ;
if ( F_46 ( V_66 ) ) {
switch ( V_88 ) {
case 0 : V_2 -> V_78 = 1024 ; break;
case 1 : V_2 -> V_78 = 512 ; break;
case 2 : V_2 -> V_78 = 256 ; break;
default: F_47 () ;
}
}
if ( ( V_27 = F_48 ( V_2 , V_89 ) ) < 0 )
return V_27 ;
if ( F_49 ( V_66 ) )
V_2 -> V_90 = 0 ;
else
V_2 -> V_90 = 2 + F_50 ( V_66 ) ;
V_2 -> V_91 -> V_92 . V_93 = NULL ;
V_68 = V_2 -> V_91 -> V_68 ;
V_68 -> V_94 = F_51 ( V_2 , V_2 -> V_91 -> V_95 ) ;
V_68 -> V_96 = F_52 ( V_2 , V_97 ) ;
#if F_53 ( V_98 )
V_68 -> V_96 |= F_52 ( V_2 , V_99 ) ;
#endif
V_68 -> V_100 = F_52 ( V_2 , V_101 ) ;
V_68 -> V_102 = F_54 ( V_2 ) ;
V_2 -> V_91 -> V_103 = V_104 ;
V_68 -> V_105 = F_55 ( V_2 , V_2 -> V_91 -> V_106 -> V_107 ) ;
if ( V_108 < 0 || V_108 > 6 )
V_108 = 0 ;
V_17 = 1 << ( 16 + V_108 ) ;
if ( F_56 ( V_66 ) ) {
V_2 -> V_109 = 1 ;
F_35 ( V_2 , L_4 ) ;
V_17 |= V_110 ;
}
if ( F_57 ( V_66 ) ) {
if ( V_111 ) {
V_111 = F_58 ( V_111 , ( unsigned ) 3 ) ;
V_17 |= V_112 ;
V_17 |= V_111 << 8 ;
}
F_35 ( V_2 , L_5 , V_111 ) ;
}
if ( F_46 ( V_66 ) ) {
V_17 &= ~ ( 3 << 2 ) ;
V_17 |= ( V_88 << 2 ) ;
}
V_2 -> V_20 = V_17 ;
if ( ! ( V_54 -> V_113 -> V_114 & V_115 ) )
V_54 -> V_116 . V_117 = ~ 0 ;
return 0 ;
}
static int F_59 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
T_2 V_17 ;
T_2 V_66 ;
V_54 -> V_118 = 1 ;
F_10 ( V_2 , V_2 -> V_119 , & V_2 -> V_4 -> V_120 ) ;
F_10 ( V_2 , ( T_2 ) V_2 -> V_91 -> V_95 , & V_2 -> V_4 -> V_121 ) ;
V_66 = F_2 ( V_2 , & V_2 -> V_76 -> V_66 ) ;
if ( F_60 ( V_66 ) ) {
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_122 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_20 &= ~ ( V_123 | V_22 | V_47 | V_46 | V_29 ) ;
V_2 -> V_20 |= V_21 ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_19 ( V_2 , L_6 , V_2 -> V_20 ) ;
F_61 ( & V_124 ) ;
V_2 -> V_30 = V_43 ;
F_10 ( V_2 , V_125 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
F_62 ( 5 ) ;
F_63 ( & V_124 ) ;
V_2 -> V_126 = F_64 () ;
V_17 = F_65 ( V_2 , F_2 ( V_2 , & V_2 -> V_76 -> V_127 ) ) ;
F_66 ( V_2 ,
L_7 ,
( ( V_2 -> V_128 & 0xf0 ) >> 4 ) , ( V_2 -> V_128 & 0x0f ) ,
V_17 >> 8 , V_17 & 0xff ,
V_129 ? L_8 : L_9 ) ;
F_10 ( V_2 , V_130 ,
& V_2 -> V_4 -> V_19 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
int V_27 ;
V_2 -> V_4 = ( void T_1 * ) V_2 -> V_76 +
F_70 ( V_2 , F_2 ( V_2 , & V_2 -> V_76 -> V_127 ) ) ;
F_71 ( V_2 , L_1 ) ;
F_72 ( V_2 , L_1 ) ;
V_2 -> V_49 = F_2 ( V_2 , & V_2 -> V_76 -> V_49 ) ;
V_2 -> V_128 = V_131 ;
V_27 = F_42 ( V_54 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_8 ( V_2 ) ;
if ( V_27 )
return V_27 ;
F_17 ( V_2 ) ;
return 0 ;
}
static T_3 F_73 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
T_2 V_24 , V_132 , V_133 = 0 , V_134 ;
int V_135 ;
unsigned long V_114 ;
F_74 ( & V_2 -> V_18 , V_114 ) ;
V_24 = F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ;
if ( V_24 == ~ ( T_2 ) 0 ) {
F_35 ( V_2 , L_10 ) ;
goto V_136;
}
V_132 = V_24 & ( V_130 | V_137 ) ;
if ( ! V_132 || F_3 ( V_2 -> V_30 == V_31 ) ) {
F_75 ( & V_2 -> V_18 , V_114 ) ;
return V_138 ;
}
F_10 ( V_2 , V_132 , & V_2 -> V_4 -> V_24 ) ;
V_134 = F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_135 = 0 ;
if ( F_76 ( ( V_24 & ( V_139 | V_140 ) ) != 0 ) ) {
if ( F_76 ( ( V_24 & V_140 ) == 0 ) )
F_77 ( V_2 -> V_141 . V_142 ) ;
else
F_77 ( V_2 -> V_141 . error ) ;
V_135 = 1 ;
}
if ( V_24 & V_143 ) {
V_2 -> V_57 &= ~ F_78 ( V_144 ) ;
if ( V_2 -> V_74 == V_144 )
++ V_2 -> V_74 ;
if ( V_134 & V_22 )
F_35 ( V_2 , L_11 ) ;
if ( V_2 -> V_145 )
F_77 ( V_2 -> V_141 . V_146 ) ;
F_79 ( V_2 ) ;
}
if ( V_24 & V_147 ) {
unsigned V_148 = F_23 ( V_2 -> V_49 ) ;
T_2 V_149 = ~ 0 ;
V_133 = V_24 ;
if ( V_2 -> V_30 == V_150 )
F_80 ( V_54 ) ;
if ( V_2 -> V_109 )
V_149 = V_24 >> 16 ;
while ( V_148 -- ) {
int V_151 ;
if ( ! ( V_149 & ( 1 << V_148 ) ) )
continue;
V_151 = F_2 ( V_2 ,
& V_2 -> V_4 -> V_51 [ V_148 ] ) ;
if ( V_151 & V_152 )
continue;
if ( ! ( F_81 ( V_148 , & V_2 -> V_41 ) &&
( ( V_151 & V_153 ) ||
! ( V_151 & V_154 ) ) &&
( V_151 & V_155 ) &&
V_2 -> V_156 [ V_148 ] == 0 ) )
continue;
V_2 -> V_156 [ V_148 ] = V_33 +
F_82 ( V_157 ) ;
F_83 ( V_148 , & V_2 -> V_42 ) ;
F_35 ( V_2 , L_12 , V_148 + 1 ) ;
F_84 ( & V_54 -> V_116 , V_148 ) ;
F_85 ( & V_54 -> V_158 , V_2 -> V_156 [ V_148 ] ) ;
}
}
if ( F_3 ( ( V_24 & V_159 ) != 0 ) ) {
F_86 ( V_2 , L_13 ) ;
F_19 ( V_2 , L_14 , V_134 ) ;
F_41 ( V_2 , L_14 , V_24 ) ;
V_136:
F_87 ( V_54 ) ;
V_2 -> V_55 = true ;
V_2 -> V_30 = V_56 ;
V_2 -> V_20 &= ~ ( V_21 | V_46 | V_47 ) ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
F_88 ( V_2 ) ;
V_135 = 0 ;
}
if ( V_135 )
F_29 ( V_2 ) ;
F_75 ( & V_2 -> V_18 , V_114 ) ;
if ( V_133 )
F_89 ( V_54 ) ;
return V_160 ;
}
static int F_90 (
struct V_53 * V_54 ,
struct V_161 * V_161 ,
T_4 V_162
) {
struct V_1 * V_2 = F_27 ( V_54 ) ;
struct V_163 V_164 ;
F_45 ( & V_164 ) ;
switch ( F_91 ( V_161 -> V_165 ) ) {
case V_166 :
if ( V_161 -> V_167 > ( 16 * 1024 ) )
return - V_168 ;
default:
if ( ! F_92 ( V_2 , V_161 , & V_164 , V_162 ) )
return - V_169 ;
return F_93 ( V_2 , V_161 , & V_164 , V_162 ) ;
case V_170 :
if ( ! F_92 ( V_2 , V_161 , & V_164 , V_162 ) )
return - V_169 ;
return F_94 ( V_2 , V_161 , & V_164 , V_162 ) ;
case V_171 :
if ( V_161 -> V_172 -> V_173 == V_174 )
return F_95 ( V_2 , V_161 , V_162 ) ;
else
return F_96 ( V_2 , V_161 , V_162 ) ;
}
}
static int F_97 ( struct V_53 * V_54 , struct V_161 * V_161 , int V_24 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
struct V_175 * V_93 ;
unsigned long V_114 ;
int V_176 ;
F_74 ( & V_2 -> V_18 , V_114 ) ;
V_176 = F_98 ( V_54 , V_161 , V_24 ) ;
if ( V_176 )
goto V_9;
if ( F_91 ( V_161 -> V_165 ) == V_171 ) {
} else {
V_93 = (struct V_175 * ) V_161 -> V_177 ;
V_93 -> V_178 = 1 ;
switch ( V_93 -> V_103 ) {
case V_104 :
if ( F_91 ( V_161 -> V_165 ) == V_170 )
F_99 ( V_2 , V_93 ) ;
else
F_100 ( V_2 , V_93 ) ;
break;
case V_179 :
V_93 -> V_180 = 1 ;
break;
case V_181 :
case V_182 :
break;
case V_183 :
F_101 ( V_2 , V_93 ) ;
break;
}
}
V_9:
F_75 ( & V_2 -> V_18 , V_114 ) ;
return V_176 ;
}
static void
F_102 ( struct V_53 * V_54 , struct V_184 * V_185 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
unsigned long V_114 ;
struct V_175 * V_93 ;
V_61:
F_74 ( & V_2 -> V_18 , V_114 ) ;
V_93 = V_185 -> V_177 ;
if ( ! V_93 )
goto V_9;
if ( V_93 -> V_68 == NULL ) {
struct V_186 * V_187 = V_185 -> V_177 ;
if ( ! F_103 ( & V_187 -> V_188 ) )
goto V_189;
F_104 ( V_2 , V_187 , - 1 ) ;
F_105 ( V_187 ) ;
goto V_9;
}
V_93 -> V_178 = 1 ;
switch ( V_93 -> V_103 ) {
case V_104 :
F_106 ( ! F_103 ( & V_93 -> V_164 ) ) ;
if ( F_107 ( & V_185 -> V_190 ) != V_191 )
F_100 ( V_2 , V_93 ) ;
else
F_99 ( V_2 , V_93 ) ;
case V_179 :
case V_181 :
case V_182 :
V_189:
F_75 ( & V_2 -> V_18 , V_114 ) ;
F_108 ( 1 ) ;
goto V_61;
case V_183 :
if ( V_93 -> V_192 )
goto V_189;
if ( F_103 ( & V_93 -> V_164 ) ) {
if ( V_93 -> V_193 . V_194 )
F_109 ( V_2 , V_93 , - 1 ) ;
F_110 ( V_2 , V_93 ) ;
break;
}
default:
F_86 ( V_2 , L_15 ,
V_93 , V_185 -> V_190 . V_195 , V_93 -> V_103 ,
F_103 ( & V_93 -> V_164 ) ? L_9 : L_16 ) ;
break;
}
V_9:
V_185 -> V_177 = NULL ;
F_75 ( & V_2 -> V_18 , V_114 ) ;
}
static void
F_111 ( struct V_53 * V_54 , struct V_184 * V_185 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
struct V_175 * V_93 ;
int V_196 = F_107 ( & V_185 -> V_190 ) ;
int V_197 = F_112 ( & V_185 -> V_190 ) ;
int V_198 = F_113 ( & V_185 -> V_190 ) ;
unsigned long V_114 ;
if ( V_196 != V_199 && V_196 != V_191 )
return;
F_74 ( & V_2 -> V_18 , V_114 ) ;
V_93 = V_185 -> V_177 ;
if ( V_93 ) {
if ( ! F_103 ( & V_93 -> V_164 ) ) {
F_114 ( 1 , L_17 ) ;
} else {
F_115 ( V_93 -> V_193 . V_200 , V_197 , V_198 , 0 ) ;
V_93 -> V_178 = 1 ;
if ( V_196 == V_199 )
F_100 ( V_2 , V_93 ) ;
else
F_99 ( V_2 , V_93 ) ;
}
}
F_75 ( & V_2 -> V_18 , V_114 ) ;
}
static int F_116 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
return ( F_4 ( V_2 ) >> 3 ) % V_2 -> V_78 ;
}
static void F_117 ( struct V_53 * V_54 , struct V_201 * V_200 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_118 ( V_200 ) ;
F_12 ( & V_2 -> V_18 ) ;
}
int F_119 ( struct V_53 * V_54 , bool V_202 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
if ( F_120 ( V_33 , V_2 -> V_32 ) )
F_62 ( 10 ) ;
F_121 ( V_2 , V_202 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
F_122 ( V_203 , & V_54 -> V_114 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_13 ( V_54 -> V_23 ) ;
if ( V_202 && F_123 ( V_54 ) ) {
F_124 ( V_54 , false ) ;
return - V_204 ;
}
return 0 ;
}
int F_124 ( struct V_53 * V_54 , bool V_205 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
if ( F_120 ( V_33 , V_2 -> V_32 ) )
F_62 ( 100 ) ;
F_83 ( V_203 , & V_54 -> V_114 ) ;
if ( V_2 -> V_55 )
return 0 ;
if ( F_2 ( V_2 , & V_2 -> V_4 -> V_52 ) == V_125 &&
! V_205 ) {
int V_8 = V_130 ;
F_125 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_206;
if ( ! V_54 -> V_116 . V_207 -> V_208 )
V_8 &= ~ V_147 ;
F_10 ( V_2 , V_8 , & V_2 -> V_4 -> V_19 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
V_206:
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_126 ( V_54 -> V_116 . V_207 ) ;
( void ) F_8 ( V_2 ) ;
( void ) F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_206;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , V_125 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_2 -> V_30 = V_150 ;
F_12 ( & V_2 -> V_18 ) ;
return 1 ;
}
void F_127 ( struct V_209 * V_210 ,
const struct V_211 * V_212 )
{
* V_210 = V_213 ;
if ( V_212 ) {
V_210 -> V_214 += V_212 -> V_215 ;
if ( V_212 -> V_216 )
V_210 -> V_216 = V_212 -> V_216 ;
if ( V_212 -> V_217 )
V_210 -> V_217 = V_212 -> V_217 ;
}
}
static int T_5 F_128 ( void )
{
int V_27 = 0 ;
if ( F_129 () )
return - V_12 ;
F_130 ( V_218 L_18 V_219 L_19 , V_220 ) ;
F_83 ( V_221 , & V_222 ) ;
if ( F_81 ( V_223 , & V_222 ) ||
F_81 ( V_224 , & V_222 ) )
F_130 ( V_225 L_20
L_21 ) ;
F_131 ( L_22 ,
V_220 ,
sizeof( struct V_175 ) , sizeof( struct V_226 ) ,
sizeof( struct V_227 ) , sizeof( struct V_228 ) ) ;
#ifdef F_132
V_229 = F_133 ( L_23 , V_230 ) ;
if ( ! V_229 ) {
V_27 = - V_231 ;
goto V_232;
}
#endif
#ifdef F_134
V_27 = F_135 ( & F_134 ) ;
if ( V_27 < 0 )
goto V_233;
#endif
#ifdef F_136
V_27 = F_137 ( & F_136 ) ;
if ( V_27 < 0 )
goto V_234;
#endif
#ifdef F_138
V_27 = F_135 ( & F_138 ) ;
if ( V_27 < 0 )
goto V_235;
#endif
#ifdef F_139
V_27 = F_135 ( & F_139 ) ;
if ( V_27 < 0 )
goto V_236;
#endif
return V_27 ;
#ifdef F_139
V_236:
#endif
#ifdef F_138
F_140 ( & F_138 ) ;
V_235:
#endif
#ifdef F_136
F_141 ( & F_136 ) ;
V_234:
#endif
#ifdef F_134
F_140 ( & F_134 ) ;
V_233:
#endif
#ifdef F_132
F_142 ( V_229 ) ;
V_229 = NULL ;
V_232:
#endif
F_122 ( V_221 , & V_222 ) ;
return V_27 ;
}
static void T_6 F_143 ( void )
{
#ifdef F_139
F_140 ( & F_139 ) ;
#endif
#ifdef F_138
F_140 ( & F_138 ) ;
#endif
#ifdef F_134
F_140 ( & F_134 ) ;
#endif
#ifdef F_136
F_141 ( & F_136 ) ;
#endif
#ifdef F_132
F_142 ( V_229 ) ;
#endif
F_122 ( V_221 , & V_222 ) ;
}
