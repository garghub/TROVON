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
if ( ! V_2 -> V_55 )
return;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_56 = true ;
V_2 -> V_30 = V_57 ;
V_2 -> V_58 = 0 ;
F_12 ( & V_2 -> V_18 ) ;
F_25 ( V_2 ) ;
F_28 ( & V_2 -> V_59 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 ) {
V_2 -> V_61 = true ;
return;
}
V_2 -> V_60 = true ;
V_62:
V_2 -> V_61 = false ;
if ( V_2 -> V_63 )
F_30 ( V_2 ) ;
if ( V_2 -> V_64 > 0 )
F_31 ( V_2 ) ;
if ( V_2 -> V_65 > 0 )
F_32 ( V_2 ) ;
if ( V_2 -> V_61 )
goto V_62;
V_2 -> V_60 = false ;
F_33 ( V_2 ) ;
}
static void F_34 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
F_35 ( V_2 , L_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_58 = 0 ;
F_12 ( & V_2 -> V_18 ) ;
F_21 ( V_2 ) ;
F_25 ( V_2 ) ;
F_17 ( V_2 ) ;
F_28 ( & V_2 -> V_59 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_38 ( V_2 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_66 == 1 )
F_40 () ;
F_41 ( V_2 , L_3 ,
F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ) ;
}
static int F_42 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
T_2 V_17 ;
int V_27 ;
T_2 V_67 ;
struct V_68 * V_69 ;
F_43 ( & V_2 -> V_18 ) ;
V_2 -> V_70 = 1 ;
F_44 ( & V_2 -> V_59 , V_71 , V_72 ) ;
V_2 -> V_59 . V_73 = V_74 ;
V_2 -> V_75 = V_76 ;
V_67 = F_2 ( V_2 , & V_2 -> V_77 -> V_67 ) ;
V_2 -> V_78 = 100 ;
V_2 -> V_79 = V_80 ;
F_45 ( & V_2 -> V_81 ) ;
F_45 ( & V_2 -> V_82 ) ;
F_45 ( & V_2 -> V_83 ) ;
F_45 ( & V_2 -> V_84 ) ;
F_45 ( & V_2 -> V_85 ) ;
F_45 ( & V_2 -> V_86 ) ;
F_45 ( & V_2 -> V_87 ) ;
F_45 ( & V_2 -> V_88 ) ;
if ( F_46 ( V_67 ) ) {
switch ( V_89 ) {
case 0 : V_2 -> V_79 = 1024 ; break;
case 1 : V_2 -> V_79 = 512 ; break;
case 2 : V_2 -> V_79 = 256 ; break;
default: F_47 () ;
}
}
if ( ( V_27 = F_48 ( V_2 , V_90 ) ) < 0 )
return V_27 ;
if ( F_49 ( V_67 ) )
V_2 -> V_91 = 0 ;
else
V_2 -> V_91 = 2 + F_50 ( V_67 ) ;
V_2 -> V_92 -> V_93 . V_94 = NULL ;
V_69 = V_2 -> V_92 -> V_69 ;
V_69 -> V_95 = F_51 ( V_2 , V_2 -> V_92 -> V_96 ) ;
V_69 -> V_97 = F_52 ( V_2 , V_98 ) ;
#if F_53 ( V_99 )
V_69 -> V_97 |= F_52 ( V_2 , V_100 ) ;
#endif
V_69 -> V_101 = F_52 ( V_2 , V_102 ) ;
V_69 -> V_103 = F_54 ( V_2 ) ;
V_2 -> V_92 -> V_104 = V_105 ;
V_69 -> V_106 = F_55 ( V_2 , V_2 -> V_92 -> V_107 -> V_108 ) ;
if ( V_109 < 0 || V_109 > 6 )
V_109 = 0 ;
V_17 = 1 << ( 16 + V_109 ) ;
if ( F_56 ( V_67 ) ) {
V_2 -> V_110 = 1 ;
F_35 ( V_2 , L_4 ) ;
V_17 |= V_111 ;
}
if ( F_57 ( V_67 ) ) {
if ( V_112 ) {
V_112 = F_58 ( V_112 , ( unsigned ) 3 ) ;
V_17 |= V_113 ;
V_17 |= V_112 << 8 ;
}
F_35 ( V_2 , L_5 , V_112 ) ;
}
if ( F_46 ( V_67 ) ) {
V_17 &= ~ ( 3 << 2 ) ;
V_17 |= ( V_89 << 2 ) ;
}
V_2 -> V_20 = V_17 ;
if ( ! ( V_54 -> V_114 -> V_115 & V_116 ) )
V_54 -> V_117 . V_118 = ~ 0 ;
V_2 -> V_119 = ~ 0 ;
return 0 ;
}
static int F_59 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
T_2 V_17 ;
T_2 V_67 ;
V_54 -> V_120 = 1 ;
F_10 ( V_2 , V_2 -> V_121 , & V_2 -> V_4 -> V_122 ) ;
F_10 ( V_2 , ( T_2 ) V_2 -> V_92 -> V_96 , & V_2 -> V_4 -> V_123 ) ;
V_67 = F_2 ( V_2 , & V_2 -> V_77 -> V_67 ) ;
if ( F_60 ( V_67 ) ) {
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_124 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_20 &= ~ ( V_125 | V_22 | V_47 | V_46 | V_29 ) ;
V_2 -> V_20 |= V_21 ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_19 ( V_2 , L_6 , V_2 -> V_20 ) ;
F_61 ( & V_126 ) ;
V_2 -> V_30 = V_43 ;
F_10 ( V_2 , V_127 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
F_62 ( 5 ) ;
F_63 ( & V_126 ) ;
V_2 -> V_128 = F_64 () ;
V_17 = F_65 ( V_2 , F_2 ( V_2 , & V_2 -> V_77 -> V_129 ) ) ;
F_66 ( V_2 ,
L_7 ,
( ( V_2 -> V_55 & 0xf0 ) >> 4 ) , ( V_2 -> V_55 & 0x0f ) ,
V_17 >> 8 , V_17 & 0xff ,
V_130 ? L_8 : L_9 ) ;
F_10 ( V_2 , V_131 ,
& V_2 -> V_4 -> V_19 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
int V_27 ;
V_2 -> V_4 = ( void T_1 * ) V_2 -> V_77 +
F_70 ( V_2 , F_2 ( V_2 , & V_2 -> V_77 -> V_129 ) ) ;
F_71 ( V_2 , L_1 ) ;
F_72 ( V_2 , L_1 ) ;
V_2 -> V_49 = F_2 ( V_2 , & V_2 -> V_77 -> V_49 ) ;
V_2 -> V_55 = V_132 ;
V_27 = F_42 ( V_54 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_8 ( V_2 ) ;
if ( V_27 ) {
F_39 ( V_2 ) ;
return V_27 ;
}
F_17 ( V_2 ) ;
return 0 ;
}
static T_3 F_73 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
T_2 V_24 , V_133 , V_134 = 0 , V_135 ;
int V_136 ;
unsigned long V_115 ;
F_74 ( & V_2 -> V_18 , V_115 ) ;
V_24 = F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ;
if ( V_24 == ~ ( T_2 ) 0 ) {
F_35 ( V_2 , L_10 ) ;
goto V_137;
}
V_133 = V_24 & ( V_131 | V_138 ) ;
if ( ! V_133 || F_3 ( V_2 -> V_30 == V_31 ) ) {
F_75 ( & V_2 -> V_18 , V_115 ) ;
return V_139 ;
}
F_10 ( V_2 , V_133 , & V_2 -> V_4 -> V_24 ) ;
V_135 = F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_136 = 0 ;
if ( F_76 ( ( V_24 & ( V_140 | V_141 ) ) != 0 ) ) {
if ( F_76 ( ( V_24 & V_141 ) == 0 ) )
F_77 ( V_2 -> V_142 . V_143 ) ;
else
F_77 ( V_2 -> V_142 . error ) ;
V_136 = 1 ;
}
if ( V_24 & V_144 ) {
V_2 -> V_58 &= ~ F_78 ( V_145 ) ;
if ( V_2 -> V_75 == V_145 )
++ V_2 -> V_75 ;
if ( V_135 & V_22 )
F_35 ( V_2 , L_11 ) ;
if ( V_2 -> V_146 )
F_77 ( V_2 -> V_142 . V_147 ) ;
F_79 ( V_2 ) ;
}
if ( V_24 & V_148 ) {
unsigned V_149 = F_23 ( V_2 -> V_49 ) ;
T_2 V_150 = ~ 0 ;
V_134 = V_24 ;
if ( V_2 -> V_30 == V_151 )
F_80 ( V_54 ) ;
if ( V_2 -> V_110 )
V_150 = V_24 >> 16 ;
while ( V_149 -- ) {
int V_152 ;
if ( ! ( V_150 & ( 1 << V_149 ) ) )
continue;
V_152 = F_2 ( V_2 ,
& V_2 -> V_4 -> V_51 [ V_149 ] ) ;
if ( V_152 & V_153 )
continue;
if ( ! ( F_81 ( V_149 , & V_2 -> V_41 ) &&
( ( V_152 & V_154 ) ||
! ( V_152 & V_155 ) ) &&
( V_152 & V_156 ) &&
V_2 -> V_157 [ V_149 ] == 0 ) )
continue;
V_2 -> V_157 [ V_149 ] = V_33 +
F_82 ( V_158 ) ;
F_83 ( V_149 , & V_2 -> V_42 ) ;
F_35 ( V_2 , L_12 , V_149 + 1 ) ;
F_84 ( & V_54 -> V_117 , V_149 ) ;
F_85 ( & V_54 -> V_159 , V_2 -> V_157 [ V_149 ] ) ;
}
}
if ( F_3 ( ( V_24 & V_160 ) != 0 ) ) {
F_86 ( V_2 , L_13 ) ;
F_19 ( V_2 , L_14 , V_135 ) ;
F_41 ( V_2 , L_14 , V_24 ) ;
V_137:
F_87 ( V_54 ) ;
V_2 -> V_56 = true ;
V_2 -> V_30 = V_57 ;
V_2 -> V_20 &= ~ ( V_21 | V_46 | V_47 ) ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
F_88 ( V_2 ) ;
V_136 = 0 ;
}
if ( V_136 )
F_29 ( V_2 ) ;
F_75 ( & V_2 -> V_18 , V_115 ) ;
if ( V_134 )
F_89 ( V_54 ) ;
return V_161 ;
}
static int F_90 (
struct V_53 * V_54 ,
struct V_162 * V_162 ,
T_4 V_163
) {
struct V_1 * V_2 = F_27 ( V_54 ) ;
struct V_164 V_165 ;
F_45 ( & V_165 ) ;
switch ( F_91 ( V_162 -> V_166 ) ) {
case V_167 :
if ( V_162 -> V_168 > ( 16 * 1024 ) )
return - V_169 ;
default:
if ( ! F_92 ( V_2 , V_162 , & V_165 , V_163 ) )
return - V_170 ;
return F_93 ( V_2 , V_162 , & V_165 , V_163 ) ;
case V_171 :
if ( ! F_92 ( V_2 , V_162 , & V_165 , V_163 ) )
return - V_170 ;
return F_94 ( V_2 , V_162 , & V_165 , V_163 ) ;
case V_172 :
if ( V_162 -> V_173 -> V_174 == V_175 )
return F_95 ( V_2 , V_162 , V_163 ) ;
else
return F_96 ( V_2 , V_162 , V_163 ) ;
}
}
static int F_97 ( struct V_53 * V_54 , struct V_162 * V_162 , int V_24 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
struct V_176 * V_94 ;
unsigned long V_115 ;
int V_177 ;
F_74 ( & V_2 -> V_18 , V_115 ) ;
V_177 = F_98 ( V_54 , V_162 , V_24 ) ;
if ( V_177 )
goto V_9;
if ( F_91 ( V_162 -> V_166 ) == V_172 ) {
} else {
V_94 = (struct V_176 * ) V_162 -> V_178 ;
V_94 -> V_179 |= V_180 ;
switch ( V_94 -> V_104 ) {
case V_105 :
if ( F_91 ( V_162 -> V_166 ) == V_171 )
F_99 ( V_2 , V_94 ) ;
else
F_100 ( V_2 , V_94 ) ;
break;
case V_181 :
V_94 -> V_182 = 1 ;
break;
case V_183 :
case V_184 :
break;
case V_185 :
F_101 ( V_2 , V_94 ) ;
break;
}
}
V_9:
F_75 ( & V_2 -> V_18 , V_115 ) ;
return V_177 ;
}
static void
F_102 ( struct V_53 * V_54 , struct V_186 * V_187 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
unsigned long V_115 ;
struct V_176 * V_94 ;
V_62:
F_74 ( & V_2 -> V_18 , V_115 ) ;
V_94 = V_187 -> V_178 ;
if ( ! V_94 )
goto V_9;
if ( V_94 -> V_69 == NULL ) {
struct V_188 * V_189 = V_187 -> V_178 ;
if ( ! F_103 ( & V_189 -> V_190 ) )
goto V_191;
F_104 ( V_2 , V_189 , - 1 ) ;
F_105 ( V_189 ) ;
goto V_9;
}
V_94 -> V_179 |= V_180 ;
switch ( V_94 -> V_104 ) {
case V_105 :
if ( F_103 ( & V_94 -> V_165 ) )
V_94 -> V_179 |= V_192 ;
else
F_106 ( 1 ) ;
if ( F_107 ( & V_187 -> V_193 ) != V_194 )
F_100 ( V_2 , V_94 ) ;
else
F_99 ( V_2 , V_94 ) ;
case V_181 :
case V_183 :
case V_184 :
V_191:
F_75 ( & V_2 -> V_18 , V_115 ) ;
F_108 ( 1 ) ;
goto V_62;
case V_185 :
if ( V_94 -> V_195 )
goto V_191;
if ( F_103 ( & V_94 -> V_165 ) ) {
if ( V_94 -> V_196 . V_197 )
F_109 ( V_2 , V_94 , - 1 ) ;
F_110 ( V_2 , V_94 ) ;
break;
}
default:
F_86 ( V_2 , L_15 ,
V_94 , V_187 -> V_193 . V_198 , V_94 -> V_104 ,
F_103 ( & V_94 -> V_165 ) ? L_9 : L_16 ) ;
break;
}
V_9:
V_187 -> V_178 = NULL ;
F_75 ( & V_2 -> V_18 , V_115 ) ;
}
static void
F_111 ( struct V_53 * V_54 , struct V_186 * V_187 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
struct V_176 * V_94 ;
int V_199 = F_107 ( & V_187 -> V_193 ) ;
int V_200 = F_112 ( & V_187 -> V_193 ) ;
int V_201 = F_113 ( & V_187 -> V_193 ) ;
unsigned long V_115 ;
if ( V_199 != V_202 && V_199 != V_194 )
return;
F_74 ( & V_2 -> V_18 , V_115 ) ;
V_94 = V_187 -> V_178 ;
if ( V_94 ) {
if ( ! F_103 ( & V_94 -> V_165 ) ) {
F_114 ( 1 , L_17 ) ;
} else {
F_115 ( V_94 -> V_196 . V_203 , V_200 , V_201 , 0 ) ;
V_94 -> V_179 |= V_180 ;
if ( V_199 == V_202 )
F_100 ( V_2 , V_94 ) ;
else
F_99 ( V_2 , V_94 ) ;
}
}
F_75 ( & V_2 -> V_18 , V_115 ) ;
}
static int F_116 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
return ( F_4 ( V_2 ) >> 3 ) % V_2 -> V_79 ;
}
static void F_117 ( struct V_53 * V_54 , struct V_204 * V_203 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_118 ( V_203 ) ;
F_12 ( & V_2 -> V_18 ) ;
}
int F_119 ( struct V_53 * V_54 , bool V_205 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
if ( F_120 ( V_33 , V_2 -> V_32 ) )
F_62 ( 10 ) ;
F_121 ( V_2 , V_205 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
F_122 ( V_206 , & V_54 -> V_115 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_13 ( V_54 -> V_23 ) ;
if ( V_205 && F_123 ( V_54 ) ) {
F_124 ( V_54 , false ) ;
return - V_207 ;
}
return 0 ;
}
int F_124 ( struct V_53 * V_54 , bool V_208 )
{
struct V_1 * V_2 = F_27 ( V_54 ) ;
if ( F_120 ( V_33 , V_2 -> V_32 ) )
F_62 ( 100 ) ;
F_83 ( V_206 , & V_54 -> V_115 ) ;
if ( V_2 -> V_56 )
return 0 ;
if ( F_2 ( V_2 , & V_2 -> V_4 -> V_52 ) == V_127 &&
! V_208 ) {
int V_8 = V_131 ;
F_125 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_56 )
goto V_209;
if ( ! V_54 -> V_117 . V_210 -> V_211 )
V_8 &= ~ V_148 ;
F_10 ( V_2 , V_8 , & V_2 -> V_4 -> V_19 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
V_209:
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_126 ( V_54 -> V_117 . V_210 ) ;
( void ) F_8 ( V_2 ) ;
( void ) F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_56 )
goto V_209;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , V_127 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_2 -> V_30 = V_151 ;
F_12 ( & V_2 -> V_18 ) ;
return 1 ;
}
void F_127 ( struct V_212 * V_213 ,
const struct V_214 * V_215 )
{
* V_213 = V_216 ;
if ( V_215 ) {
V_213 -> V_217 += V_215 -> V_218 ;
if ( V_215 -> V_219 )
V_213 -> V_219 = V_215 -> V_219 ;
if ( V_215 -> V_220 )
V_213 -> V_220 = V_215 -> V_220 ;
}
}
static int T_5 F_128 ( void )
{
int V_27 = 0 ;
if ( F_129 () )
return - V_12 ;
F_130 ( V_221 L_18 V_222 L_19 , V_223 ) ;
F_83 ( V_224 , & V_225 ) ;
if ( F_81 ( V_226 , & V_225 ) ||
F_81 ( V_227 , & V_225 ) )
F_130 ( V_228 L_20
L_21 ) ;
F_131 ( L_22 ,
V_223 ,
sizeof( struct V_176 ) , sizeof( struct V_229 ) ,
sizeof( struct V_230 ) , sizeof( struct V_231 ) ) ;
#ifdef F_132
V_232 = F_133 ( L_23 , V_233 ) ;
if ( ! V_232 ) {
V_27 = - V_234 ;
goto V_235;
}
#endif
#ifdef F_134
V_27 = F_135 ( & F_134 ) ;
if ( V_27 < 0 )
goto V_236;
#endif
#ifdef F_136
V_27 = F_137 ( & F_136 ) ;
if ( V_27 < 0 )
goto V_237;
#endif
#ifdef F_138
V_27 = F_135 ( & F_138 ) ;
if ( V_27 < 0 )
goto V_238;
#endif
#ifdef F_139
V_27 = F_135 ( & F_139 ) ;
if ( V_27 < 0 )
goto V_239;
#endif
return V_27 ;
#ifdef F_139
V_239:
#endif
#ifdef F_138
F_140 ( & F_138 ) ;
V_238:
#endif
#ifdef F_136
F_141 ( & F_136 ) ;
V_237:
#endif
#ifdef F_134
F_140 ( & F_134 ) ;
V_236:
#endif
#ifdef F_132
F_142 ( V_232 ) ;
V_232 = NULL ;
V_235:
#endif
F_122 ( V_224 , & V_225 ) ;
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
F_142 ( V_232 ) ;
#endif
F_122 ( V_224 , & V_225 ) ;
}
