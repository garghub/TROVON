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
static int F_17 ( struct V_1 * V_2 )
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
while ( V_48 -- )
F_10 ( V_2 , V_50 ,
& V_2 -> V_4 -> V_51 [ V_48 ] ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_30 = V_31 ;
F_22 ( V_2 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_52 ) ;
F_12 ( & V_2 -> V_18 ) ;
}
static void F_25 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_55 = true ;
V_2 -> V_30 = V_56 ;
V_2 -> V_57 = 0 ;
F_12 ( & V_2 -> V_18 ) ;
F_24 ( V_2 ) ;
F_27 ( & V_2 -> V_58 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 ) {
V_2 -> V_60 = true ;
return;
}
V_2 -> V_59 = true ;
V_61:
V_2 -> V_60 = false ;
if ( V_2 -> V_62 )
F_29 ( V_2 ) ;
if ( V_2 -> V_63 > 0 )
F_30 ( V_2 ) ;
if ( V_2 -> V_64 > 0 )
F_31 ( V_2 ) ;
if ( V_2 -> V_60 )
goto V_61;
V_2 -> V_59 = false ;
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
F_34 ( V_2 , L_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_57 = 0 ;
F_12 ( & V_2 -> V_18 ) ;
F_21 ( V_2 ) ;
F_24 ( V_2 ) ;
F_17 ( V_2 ) ;
F_27 ( & V_2 -> V_58 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_37 ( V_2 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_38 ( V_2 ) ;
if ( V_2 -> V_65 == 1 )
F_39 () ;
F_40 ( V_2 , L_3 ,
F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ) ;
}
static int F_41 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_17 ;
int V_27 ;
T_2 V_66 ;
struct V_67 * V_68 ;
F_42 ( & V_2 -> V_18 ) ;
V_2 -> V_69 = 1 ;
F_43 ( & V_2 -> V_58 , V_70 , V_71 ) ;
V_2 -> V_58 . V_72 = V_73 ;
V_2 -> V_74 = V_75 ;
V_66 = F_2 ( V_2 , & V_2 -> V_76 -> V_66 ) ;
V_2 -> V_77 = 100 ;
V_2 -> V_78 = V_79 ;
F_44 ( & V_2 -> V_80 ) ;
F_44 ( & V_2 -> V_81 ) ;
F_44 ( & V_2 -> V_82 ) ;
F_44 ( & V_2 -> V_83 ) ;
F_44 ( & V_2 -> V_84 ) ;
F_44 ( & V_2 -> V_85 ) ;
F_44 ( & V_2 -> V_86 ) ;
if ( F_45 ( V_66 ) ) {
switch ( V_87 ) {
case 0 : V_2 -> V_78 = 1024 ; break;
case 1 : V_2 -> V_78 = 512 ; break;
case 2 : V_2 -> V_78 = 256 ; break;
default: F_46 () ;
}
}
if ( ( V_27 = F_47 ( V_2 , V_88 ) ) < 0 )
return V_27 ;
if ( F_48 ( V_66 ) )
V_2 -> V_89 = 0 ;
else
V_2 -> V_89 = 2 + F_49 ( V_66 ) ;
V_2 -> V_90 -> V_91 . V_92 = NULL ;
V_68 = V_2 -> V_90 -> V_68 ;
V_68 -> V_93 = F_50 ( V_2 , V_2 -> V_90 -> V_94 ) ;
V_68 -> V_95 = F_51 ( V_2 , V_96 ) ;
#if F_52 ( V_97 )
V_68 -> V_95 |= F_51 ( V_2 , V_98 ) ;
#endif
V_68 -> V_99 = F_51 ( V_2 , V_100 ) ;
V_68 -> V_101 = F_53 ( V_2 ) ;
V_2 -> V_90 -> V_102 = V_103 ;
V_68 -> V_104 = F_54 ( V_2 , V_2 -> V_90 -> V_105 -> V_106 ) ;
if ( V_107 < 0 || V_107 > 6 )
V_107 = 0 ;
V_17 = 1 << ( 16 + V_107 ) ;
if ( F_55 ( V_66 ) ) {
V_2 -> V_108 = 1 ;
F_34 ( V_2 , L_4 ) ;
V_17 |= V_109 ;
}
if ( F_56 ( V_66 ) ) {
if ( V_110 ) {
V_110 = F_57 ( V_110 , ( unsigned ) 3 ) ;
V_17 |= V_111 ;
V_17 |= V_110 << 8 ;
}
F_34 ( V_2 , L_5 , V_110 ) ;
}
if ( F_45 ( V_66 ) ) {
V_17 &= ~ ( 3 << 2 ) ;
V_17 |= ( V_87 << 2 ) ;
}
V_2 -> V_20 = V_17 ;
if ( ! ( V_54 -> V_112 -> V_113 & V_114 ) )
V_54 -> V_115 . V_116 = ~ 0 ;
return 0 ;
}
static int F_58 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_17 ;
T_2 V_66 ;
V_54 -> V_117 = 1 ;
F_10 ( V_2 , V_2 -> V_118 , & V_2 -> V_4 -> V_119 ) ;
F_10 ( V_2 , ( T_2 ) V_2 -> V_90 -> V_94 , & V_2 -> V_4 -> V_120 ) ;
V_66 = F_2 ( V_2 , & V_2 -> V_76 -> V_66 ) ;
if ( F_59 ( V_66 ) ) {
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_121 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_20 &= ~ ( V_122 | V_22 | V_47 | V_46 | V_29 ) ;
V_2 -> V_20 |= V_21 ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_19 ( V_2 , L_6 , V_2 -> V_20 ) ;
F_60 ( & V_123 ) ;
V_2 -> V_30 = V_43 ;
F_10 ( V_2 , V_124 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
F_61 ( 5 ) ;
F_62 ( & V_123 ) ;
V_2 -> V_125 = F_63 () ;
V_17 = F_64 ( V_2 , F_2 ( V_2 , & V_2 -> V_76 -> V_126 ) ) ;
F_65 ( V_2 ,
L_7 ,
( ( V_2 -> V_127 & 0xf0 ) >> 4 ) , ( V_2 -> V_127 & 0x0f ) ,
V_17 >> 8 , V_17 & 0xff ,
V_128 ? L_8 : L_9 ) ;
F_10 ( V_2 , V_129 ,
& V_2 -> V_4 -> V_19 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
int F_68 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
int V_27 ;
V_2 -> V_4 = ( void T_1 * ) V_2 -> V_76 +
F_69 ( V_2 , F_2 ( V_2 , & V_2 -> V_76 -> V_126 ) ) ;
F_70 ( V_2 , L_1 ) ;
F_71 ( V_2 , L_1 ) ;
V_2 -> V_49 = F_2 ( V_2 , & V_2 -> V_76 -> V_49 ) ;
V_2 -> V_127 = V_130 ;
V_27 = F_41 ( V_54 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_8 ( V_2 ) ;
if ( V_27 )
return V_27 ;
F_17 ( V_2 ) ;
return 0 ;
}
static T_3 F_72 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_24 , V_131 , V_132 = 0 , V_133 ;
int V_134 ;
F_73 ( & V_2 -> V_18 ) ;
V_24 = F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ;
if ( V_24 == ~ ( T_2 ) 0 ) {
F_34 ( V_2 , L_10 ) ;
goto V_135;
}
V_131 = V_24 & ( V_129 | V_136 ) ;
if ( ! V_131 || F_3 ( V_2 -> V_30 == V_31 ) ) {
F_74 ( & V_2 -> V_18 ) ;
return V_137 ;
}
F_10 ( V_2 , V_131 , & V_2 -> V_4 -> V_24 ) ;
V_133 = F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_134 = 0 ;
#ifdef F_75
F_40 ( V_2 , L_11 , V_24 ) ;
#endif
if ( F_76 ( ( V_24 & ( V_138 | V_139 ) ) != 0 ) ) {
if ( F_76 ( ( V_24 & V_139 ) == 0 ) )
F_77 ( V_2 -> V_140 . V_141 ) ;
else
F_77 ( V_2 -> V_140 . error ) ;
V_134 = 1 ;
}
if ( V_24 & V_142 ) {
V_2 -> V_57 &= ~ F_78 ( V_143 ) ;
if ( V_2 -> V_74 == V_143 )
++ V_2 -> V_74 ;
if ( V_133 & V_22 )
F_34 ( V_2 , L_12 ) ;
if ( V_2 -> V_144 )
F_77 ( V_2 -> V_140 . V_145 ) ;
F_79 ( V_2 ) ;
}
if ( V_24 & V_146 ) {
unsigned V_147 = F_23 ( V_2 -> V_49 ) ;
T_2 V_148 = ~ 0 ;
V_132 = V_24 ;
if ( V_2 -> V_30 == V_149 )
F_80 ( V_54 ) ;
if ( V_2 -> V_108 )
V_148 = V_24 >> 16 ;
while ( V_147 -- ) {
int V_150 ;
if ( ! ( V_148 & ( 1 << V_147 ) ) )
continue;
V_150 = F_2 ( V_2 ,
& V_2 -> V_4 -> V_51 [ V_147 ] ) ;
if ( V_150 & V_151 )
continue;
if ( ! ( F_81 ( V_147 , & V_2 -> V_41 ) &&
( ( V_150 & V_152 ) ||
! ( V_150 & V_153 ) ) &&
( V_150 & V_154 ) &&
V_2 -> V_155 [ V_147 ] == 0 ) )
continue;
V_2 -> V_155 [ V_147 ] = V_33 + F_82 ( 25 ) ;
F_83 ( V_147 , & V_2 -> V_42 ) ;
F_34 ( V_2 , L_13 , V_147 + 1 ) ;
F_84 ( & V_54 -> V_115 , V_147 ) ;
F_85 ( & V_54 -> V_156 , V_2 -> V_155 [ V_147 ] ) ;
}
}
if ( F_3 ( ( V_24 & V_157 ) != 0 ) ) {
F_86 ( V_2 , L_14 ) ;
F_19 ( V_2 , L_15 , V_133 ) ;
F_40 ( V_2 , L_15 , V_24 ) ;
V_135:
F_87 ( V_54 ) ;
V_2 -> V_55 = true ;
V_2 -> V_30 = V_56 ;
V_2 -> V_20 &= ~ ( V_21 | V_46 | V_47 ) ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
F_88 ( V_2 ) ;
V_134 = 0 ;
}
if ( V_134 )
F_28 ( V_2 ) ;
F_74 ( & V_2 -> V_18 ) ;
if ( V_132 )
F_89 ( V_54 ) ;
return V_158 ;
}
static int F_90 (
struct V_53 * V_54 ,
struct V_159 * V_159 ,
T_4 V_160
) {
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_161 V_162 ;
F_44 ( & V_162 ) ;
switch ( F_91 ( V_159 -> V_163 ) ) {
case V_164 :
if ( V_159 -> V_165 > ( 16 * 1024 ) )
return - V_166 ;
default:
if ( ! F_92 ( V_2 , V_159 , & V_162 , V_160 ) )
return - V_167 ;
return F_93 ( V_2 , V_159 , & V_162 , V_160 ) ;
case V_168 :
if ( ! F_92 ( V_2 , V_159 , & V_162 , V_160 ) )
return - V_167 ;
return F_94 ( V_2 , V_159 , & V_162 , V_160 ) ;
case V_169 :
if ( V_159 -> V_170 -> V_171 == V_172 )
return F_95 ( V_2 , V_159 , V_160 ) ;
else
return F_96 ( V_2 , V_159 , V_160 ) ;
}
}
static int F_97 ( struct V_53 * V_54 , struct V_159 * V_159 , int V_24 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_173 * V_92 ;
unsigned long V_113 ;
int V_174 ;
F_98 ( & V_2 -> V_18 , V_113 ) ;
V_174 = F_99 ( V_54 , V_159 , V_24 ) ;
if ( V_174 )
goto V_9;
if ( F_91 ( V_159 -> V_163 ) == V_169 ) {
} else {
V_92 = (struct V_173 * ) V_159 -> V_175 ;
V_92 -> V_176 = 1 ;
switch ( V_92 -> V_102 ) {
case V_103 :
if ( F_91 ( V_159 -> V_163 ) == V_168 )
F_100 ( V_2 , V_92 ) ;
else
F_101 ( V_2 , V_92 ) ;
break;
case V_177 :
V_92 -> V_178 = 1 ;
break;
case V_179 :
case V_180 :
break;
case V_181 :
F_102 ( V_2 , V_92 ) ;
break;
}
}
V_9:
F_103 ( & V_2 -> V_18 , V_113 ) ;
return V_174 ;
}
static void
F_104 ( struct V_53 * V_54 , struct V_182 * V_183 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
unsigned long V_113 ;
struct V_173 * V_92 ;
V_61:
F_98 ( & V_2 -> V_18 , V_113 ) ;
V_92 = V_183 -> V_175 ;
if ( ! V_92 )
goto V_9;
if ( V_92 -> V_68 == NULL ) {
struct V_184 * V_185 = V_183 -> V_175 ;
if ( ! F_105 ( & V_185 -> V_186 ) )
goto V_187;
F_106 ( V_185 ) ;
goto V_9;
}
V_92 -> V_176 = 1 ;
if ( V_2 -> V_30 < V_43 )
V_92 -> V_102 = V_181 ;
switch ( V_92 -> V_102 ) {
case V_103 :
F_107 ( ! F_105 ( & V_92 -> V_162 ) ) ;
if ( F_108 ( & V_183 -> V_188 ) != V_189 )
F_101 ( V_2 , V_92 ) ;
else
F_100 ( V_2 , V_92 ) ;
case V_177 :
case V_179 :
case V_180 :
V_187:
F_103 ( & V_2 -> V_18 , V_113 ) ;
F_109 ( 1 ) ;
goto V_61;
case V_181 :
if ( V_92 -> V_190 )
goto V_187;
if ( F_105 ( & V_92 -> V_162 ) ) {
F_110 ( V_2 , V_92 ) ;
break;
}
default:
F_86 ( V_2 , L_16 ,
V_92 , V_183 -> V_188 . V_191 , V_92 -> V_102 ,
F_105 ( & V_92 -> V_162 ) ? L_9 : L_17 ) ;
break;
}
V_9:
V_183 -> V_175 = NULL ;
F_103 ( & V_2 -> V_18 , V_113 ) ;
}
static void
F_111 ( struct V_53 * V_54 , struct V_182 * V_183 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_173 * V_92 ;
int V_192 = F_108 ( & V_183 -> V_188 ) ;
int V_193 = F_112 ( & V_183 -> V_188 ) ;
int V_194 = F_113 ( & V_183 -> V_188 ) ;
unsigned long V_113 ;
if ( V_192 != V_195 && V_192 != V_189 )
return;
F_98 ( & V_2 -> V_18 , V_113 ) ;
V_92 = V_183 -> V_175 ;
if ( V_92 ) {
F_114 ( V_92 -> V_170 , V_193 , V_194 , 0 ) ;
if ( ! F_105 ( & V_92 -> V_162 ) ) {
F_115 ( 1 , L_18 ) ;
} else {
V_92 -> V_176 = 1 ;
if ( V_192 == V_195 )
F_101 ( V_2 , V_92 ) ;
else
F_100 ( V_2 , V_92 ) ;
}
}
F_103 ( & V_2 -> V_18 , V_113 ) ;
}
static int F_116 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
return ( F_4 ( V_2 ) >> 3 ) % V_2 -> V_78 ;
}
int F_117 ( struct V_53 * V_54 , bool V_196 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
if ( F_118 ( V_33 , V_2 -> V_32 ) )
F_61 ( 10 ) ;
F_119 ( V_2 , V_196 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
F_120 ( V_197 , & V_54 -> V_113 ) ;
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
int F_121 ( struct V_53 * V_54 , bool V_198 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
if ( F_118 ( V_33 , V_2 -> V_32 ) )
F_61 ( 100 ) ;
F_83 ( V_197 , & V_54 -> V_113 ) ;
if ( V_2 -> V_55 )
return 0 ;
if ( F_2 ( V_2 , & V_2 -> V_4 -> V_52 ) == V_124 &&
! V_198 ) {
int V_8 = V_129 ;
F_122 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_199;
if ( ! V_54 -> V_115 . V_200 -> V_201 )
V_8 &= ~ V_146 ;
F_10 ( V_2 , V_8 , & V_2 -> V_4 -> V_19 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
V_199:
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_123 ( V_54 -> V_115 . V_200 ) ;
( void ) F_8 ( V_2 ) ;
( void ) F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_199;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , V_124 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_2 -> V_30 = V_149 ;
F_12 ( & V_2 -> V_18 ) ;
return 1 ;
}
void F_124 ( struct V_202 * V_203 ,
const struct V_204 * V_205 )
{
* V_203 = V_206 ;
if ( V_205 ) {
V_203 -> V_207 += V_205 -> V_208 ;
if ( V_205 -> V_209 )
V_203 -> V_209 = V_205 -> V_209 ;
}
}
static int T_5 F_125 ( void )
{
int V_27 = 0 ;
if ( F_126 () )
return - V_12 ;
F_127 ( V_210 L_19 V_211 L_20 , V_212 ) ;
F_83 ( V_213 , & V_214 ) ;
if ( F_81 ( V_215 , & V_214 ) ||
F_81 ( V_216 , & V_214 ) )
F_127 ( V_217 L_21
L_22 ) ;
F_128 ( L_23 ,
V_212 ,
sizeof( struct V_173 ) , sizeof( struct V_218 ) ,
sizeof( struct V_219 ) , sizeof( struct V_220 ) ) ;
#if F_52 ( V_221 ) || F_52 ( V_222 )
V_223 = F_129 ( L_24 , V_224 ) ;
if ( ! V_223 ) {
V_27 = - V_225 ;
goto V_226;
}
#endif
#ifdef F_130
V_27 = F_131 ( & F_130 ) ;
if ( V_27 < 0 )
goto V_227;
#endif
#ifdef F_132
V_27 = F_133 ( & F_132 ) ;
if ( V_27 < 0 )
goto V_228;
#endif
#ifdef F_134
V_27 = F_131 ( & F_134 ) ;
if ( V_27 < 0 )
goto V_229;
#endif
#ifdef F_135
V_27 = F_131 ( & F_135 ) ;
if ( V_27 < 0 )
goto V_230;
#endif
return V_27 ;
#ifdef F_135
V_230:
#endif
#ifdef F_134
F_136 ( & F_134 ) ;
V_229:
#endif
#ifdef F_132
F_137 ( & F_132 ) ;
V_228:
#endif
#ifdef F_130
F_136 ( & F_130 ) ;
V_227:
#endif
#if F_52 ( V_221 ) || F_52 ( V_222 )
F_138 ( V_223 ) ;
V_223 = NULL ;
V_226:
#endif
F_120 ( V_213 , & V_214 ) ;
return V_27 ;
}
static void T_6 F_139 ( void )
{
#ifdef F_135
F_136 ( & F_135 ) ;
#endif
#ifdef F_134
F_136 ( & F_134 ) ;
#endif
#ifdef F_130
F_136 ( & F_130 ) ;
#endif
#ifdef F_132
F_137 ( & F_132 ) ;
#endif
#if F_52 ( V_221 ) || F_52 ( V_222 )
F_138 ( V_223 ) ;
#endif
F_120 ( V_213 , & V_214 ) ;
}
