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
static int F_5 ( struct V_1 * V_2 , void T_1 * V_7 ,
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
F_5 ( V_2 , & V_2 -> V_4 -> V_24 , V_44 | V_45 , V_17 , 16 * 125 ) ;
F_9 ( & V_2 -> V_18 ) ;
V_2 -> V_20 &= ~ ( V_46 | V_47 ) ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_5 ( V_2 , & V_2 -> V_4 -> V_24 , V_44 | V_45 , 0 , 16 * 125 ) ;
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
#ifdef F_40
F_34 ( V_2 , L_3 ,
V_2 -> V_66 . V_67 , V_2 -> V_66 . error , V_2 -> V_66 . V_68 ,
V_2 -> V_66 . V_69 ) ;
F_34 ( V_2 , L_4 ,
V_2 -> V_66 . V_70 , V_2 -> V_66 . V_71 ) ;
#endif
F_41 ( V_2 , L_5 ,
F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ) ;
}
static int F_42 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_17 ;
int V_27 ;
T_2 V_72 ;
struct V_73 * V_74 ;
F_43 ( & V_2 -> V_18 ) ;
V_2 -> V_75 = 1 ;
F_44 ( & V_2 -> V_58 , V_76 , V_77 ) ;
V_2 -> V_58 . V_78 = V_79 ;
V_2 -> V_80 = V_81 ;
V_72 = F_2 ( V_2 , & V_2 -> V_82 -> V_72 ) ;
V_2 -> V_83 = 100 ;
V_2 -> V_84 = V_85 ;
F_45 ( & V_2 -> V_86 ) ;
F_45 ( & V_2 -> V_87 ) ;
F_45 ( & V_2 -> V_88 ) ;
if ( F_46 ( V_72 ) ) {
switch ( V_89 ) {
case 0 : V_2 -> V_84 = 1024 ; break;
case 1 : V_2 -> V_84 = 512 ; break;
case 2 : V_2 -> V_84 = 256 ; break;
default: F_47 () ;
}
}
if ( ( V_27 = F_48 ( V_2 , V_90 ) ) < 0 )
return V_27 ;
if ( F_49 ( V_72 ) )
V_2 -> V_91 = 0 ;
else
V_2 -> V_91 = 2 + F_50 ( V_72 ) ;
V_2 -> V_92 -> V_93 . V_94 = NULL ;
V_74 = V_2 -> V_92 -> V_74 ;
V_74 -> V_95 = F_51 ( V_2 , V_2 -> V_92 -> V_96 ) ;
V_74 -> V_97 = F_52 ( V_2 , V_98 ) ;
#if F_53 ( V_99 )
V_74 -> V_97 |= F_52 ( V_2 , V_100 ) ;
#endif
V_74 -> V_101 = F_52 ( V_2 , V_102 ) ;
V_74 -> V_103 = F_54 ( V_2 ) ;
V_2 -> V_92 -> V_104 = V_105 ;
V_74 -> V_106 = F_55 ( V_2 , V_2 -> V_92 -> V_107 -> V_108 ) ;
if ( V_109 < 0 || V_109 > 6 )
V_109 = 0 ;
V_17 = 1 << ( 16 + V_109 ) ;
if ( F_56 ( V_72 ) ) {
V_2 -> V_110 = 1 ;
F_34 ( V_2 , L_6 ) ;
V_17 |= V_111 ;
}
if ( F_57 ( V_72 ) ) {
if ( V_112 ) {
V_112 = F_58 ( V_112 , ( unsigned ) 3 ) ;
V_17 |= V_113 ;
V_17 |= V_112 << 8 ;
}
F_34 ( V_2 , L_7 , V_112 ) ;
}
if ( F_46 ( V_72 ) ) {
V_17 &= ~ ( 3 << 2 ) ;
V_17 |= ( V_89 << 2 ) ;
}
V_2 -> V_20 = V_17 ;
if ( ! ( V_54 -> V_114 -> V_115 & V_116 ) )
V_54 -> V_117 . V_118 = ~ 0 ;
return 0 ;
}
static int F_59 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_17 ;
T_2 V_72 ;
V_54 -> V_119 = 1 ;
F_10 ( V_2 , V_2 -> V_120 , & V_2 -> V_4 -> V_121 ) ;
F_10 ( V_2 , ( T_2 ) V_2 -> V_92 -> V_96 , & V_2 -> V_4 -> V_122 ) ;
V_72 = F_2 ( V_2 , & V_2 -> V_82 -> V_72 ) ;
if ( F_60 ( V_72 ) ) {
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_123 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_20 &= ~ ( V_124 | V_22 | V_47 | V_46 | V_29 ) ;
V_2 -> V_20 |= V_21 ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_19 ( V_2 , L_8 , V_2 -> V_20 ) ;
F_61 ( & V_125 ) ;
V_2 -> V_30 = V_43 ;
F_10 ( V_2 , V_126 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
F_62 ( 5 ) ;
F_63 ( & V_125 ) ;
V_2 -> V_127 = F_64 () ;
V_17 = F_65 ( V_2 , F_2 ( V_2 , & V_2 -> V_82 -> V_128 ) ) ;
F_66 ( V_2 ,
L_9 ,
( ( V_2 -> V_129 & 0xf0 ) >> 4 ) , ( V_2 -> V_129 & 0x0f ) ,
V_17 >> 8 , V_17 & 0xff ,
V_130 ? L_10 : L_11 ) ;
F_10 ( V_2 , V_131 ,
& V_2 -> V_4 -> V_19 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
int V_27 ;
V_2 -> V_4 = ( void T_1 * ) V_2 -> V_82 +
F_70 ( V_2 , F_2 ( V_2 , & V_2 -> V_82 -> V_128 ) ) ;
F_71 ( V_2 , L_1 ) ;
F_72 ( V_2 , L_1 ) ;
V_2 -> V_49 = F_2 ( V_2 , & V_2 -> V_82 -> V_49 ) ;
V_2 -> V_129 = V_132 ;
V_27 = F_42 ( V_54 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_8 ( V_2 ) ;
if ( V_27 )
return V_27 ;
if ( F_11 ( V_2 ) )
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static T_3 F_73 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_24 , V_133 , V_134 = 0 , V_135 ;
int V_136 ;
F_74 ( & V_2 -> V_18 ) ;
V_24 = F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ;
if ( V_24 == ~ ( T_2 ) 0 ) {
F_34 ( V_2 , L_12 ) ;
goto V_137;
}
V_133 = V_24 & ( V_131 | V_138 ) ;
if ( ! V_133 || F_3 ( V_2 -> V_30 == V_31 ) ) {
F_75 ( & V_2 -> V_18 ) ;
return V_139 ;
}
F_10 ( V_2 , V_133 , & V_2 -> V_4 -> V_24 ) ;
V_135 = F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_136 = 0 ;
#ifdef F_76
F_41 ( V_2 , L_13 , V_24 ) ;
#endif
if ( F_77 ( ( V_24 & ( V_140 | V_141 ) ) != 0 ) ) {
if ( F_77 ( ( V_24 & V_141 ) == 0 ) )
F_78 ( V_2 -> V_66 . V_67 ) ;
else
F_78 ( V_2 -> V_66 . error ) ;
V_136 = 1 ;
}
if ( V_24 & V_142 ) {
V_2 -> V_57 &= ~ F_79 ( V_143 ) ;
if ( V_2 -> V_80 == V_143 )
++ V_2 -> V_80 ;
if ( V_135 & V_22 )
F_34 ( V_2 , L_14 ) ;
if ( V_2 -> V_144 ) {
F_78 ( V_2 -> V_66 . V_68 ) ;
F_80 ( V_2 ) ;
} else
F_34 ( V_2 , L_15 ) ;
}
if ( V_24 & V_145 ) {
unsigned V_146 = F_23 ( V_2 -> V_49 ) ;
T_2 V_147 = 0 ;
V_134 = V_24 ;
if ( V_2 -> V_30 == V_148 )
F_81 ( V_54 ) ;
if ( V_2 -> V_110 )
V_147 = V_24 >> 16 ;
while ( V_146 -- ) {
int V_149 ;
if ( V_2 -> V_110 && ! ( V_147 & ( 1 << V_146 ) ) )
continue;
V_149 = F_2 ( V_2 ,
& V_2 -> V_4 -> V_51 [ V_146 ] ) ;
if ( V_149 & V_150 )
continue;
if ( ! ( F_82 ( V_146 , & V_2 -> V_41 ) &&
( ( V_149 & V_151 ) ||
! ( V_149 & V_152 ) ) &&
( V_149 & V_153 ) &&
V_2 -> V_154 [ V_146 ] == 0 ) )
continue;
V_2 -> V_154 [ V_146 ] = V_33 + F_83 ( 25 ) ;
F_84 ( V_146 , & V_2 -> V_42 ) ;
F_34 ( V_2 , L_16 , V_146 + 1 ) ;
F_85 ( & V_54 -> V_117 , V_146 ) ;
F_86 ( & V_54 -> V_155 , V_2 -> V_154 [ V_146 ] ) ;
}
}
if ( F_3 ( ( V_24 & V_156 ) != 0 ) ) {
F_87 ( V_2 , L_17 ) ;
F_19 ( V_2 , L_18 , V_135 ) ;
F_41 ( V_2 , L_18 , V_24 ) ;
V_137:
F_88 ( V_54 ) ;
V_2 -> V_55 = true ;
V_2 -> V_30 = V_56 ;
V_2 -> V_20 &= ~ ( V_21 | V_46 | V_47 ) ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
F_89 ( V_2 ) ;
V_136 = 0 ;
}
if ( V_136 )
F_28 ( V_2 ) ;
F_75 ( & V_2 -> V_18 ) ;
if ( V_134 )
F_90 ( V_54 ) ;
return V_157 ;
}
static int F_91 (
struct V_53 * V_54 ,
struct V_158 * V_158 ,
T_4 V_159
) {
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_160 V_161 ;
F_45 ( & V_161 ) ;
switch ( F_92 ( V_158 -> V_162 ) ) {
case V_163 :
if ( V_158 -> V_164 > ( 16 * 1024 ) )
return - V_165 ;
default:
if ( ! F_93 ( V_2 , V_158 , & V_161 , V_159 ) )
return - V_166 ;
return F_94 ( V_2 , V_158 , & V_161 , V_159 ) ;
case V_167 :
if ( ! F_93 ( V_2 , V_158 , & V_161 , V_159 ) )
return - V_166 ;
return F_95 ( V_2 , V_158 , & V_161 , V_159 ) ;
case V_168 :
if ( V_158 -> V_169 -> V_170 == V_171 )
return F_96 ( V_2 , V_158 , V_159 ) ;
else
return F_97 ( V_2 , V_158 , V_159 ) ;
}
}
static int F_98 ( struct V_53 * V_54 , struct V_158 * V_158 , int V_24 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_172 * V_94 ;
unsigned long V_115 ;
int V_173 ;
F_99 ( & V_2 -> V_18 , V_115 ) ;
V_173 = F_100 ( V_54 , V_158 , V_24 ) ;
if ( V_173 )
goto V_9;
switch ( F_92 ( V_158 -> V_162 ) ) {
default:
V_94 = (struct V_172 * ) V_158 -> V_174 ;
if ( ! V_94 )
break;
switch ( V_94 -> V_104 ) {
case V_105 :
case V_175 :
F_101 ( V_2 , V_94 ) ;
break;
case V_176 :
case V_177 :
break;
case V_178 :
F_102 ( V_2 , V_94 ) ;
break;
}
break;
case V_167 :
V_94 = (struct V_172 * ) V_158 -> V_174 ;
if ( ! V_94 )
break;
switch ( V_94 -> V_104 ) {
case V_105 :
case V_175 :
F_103 ( V_2 , V_94 ) ;
break;
case V_178 :
F_102 ( V_2 , V_94 ) ;
break;
default:
F_34 ( V_2 , L_19 ,
V_94 , V_94 -> V_104 ) ;
goto V_9;
}
break;
case V_168 :
break;
}
V_9:
F_104 ( & V_2 -> V_18 , V_115 ) ;
return V_173 ;
}
static void
F_105 ( struct V_53 * V_54 , struct V_179 * V_180 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
unsigned long V_115 ;
struct V_172 * V_94 , * V_14 ;
V_61:
F_99 ( & V_2 -> V_18 , V_115 ) ;
V_94 = V_180 -> V_174 ;
if ( ! V_94 )
goto V_9;
if ( V_94 -> V_74 == NULL ) {
struct V_181 * V_182 = V_180 -> V_174 ;
if ( ! F_106 ( & V_182 -> V_183 ) )
goto V_184;
F_107 ( V_182 ) ;
goto V_9;
}
if ( V_2 -> V_30 < V_43 )
V_94 -> V_104 = V_178 ;
switch ( V_94 -> V_104 ) {
case V_105 :
case V_175 :
for ( V_14 = V_2 -> V_92 -> V_93 . V_94 ;
V_14 && V_14 != V_94 ;
V_14 = V_14 -> V_93 . V_94 )
continue;
if ( V_14 )
F_101 ( V_2 , V_94 ) ;
case V_176 :
case V_177 :
V_184:
F_104 ( & V_2 -> V_18 , V_115 ) ;
F_108 ( 1 ) ;
goto V_61;
case V_178 :
if ( V_94 -> V_185 )
goto V_184;
if ( F_106 ( & V_94 -> V_161 ) ) {
F_109 ( V_2 , V_94 ) ;
break;
}
default:
F_87 ( V_2 , L_20 ,
V_94 , V_180 -> V_186 . V_187 , V_94 -> V_104 ,
F_106 ( & V_94 -> V_161 ) ? L_11 : L_21 ) ;
break;
}
V_9:
V_180 -> V_174 = NULL ;
F_104 ( & V_2 -> V_18 , V_115 ) ;
}
static void
F_110 ( struct V_53 * V_54 , struct V_179 * V_180 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_172 * V_94 ;
int V_188 = F_111 ( & V_180 -> V_186 ) ;
int V_189 = F_112 ( & V_180 -> V_186 ) ;
int V_190 = F_113 ( & V_180 -> V_186 ) ;
unsigned long V_115 ;
if ( V_188 != V_191 && V_188 != V_192 )
return;
F_99 ( & V_2 -> V_18 , V_115 ) ;
V_94 = V_180 -> V_174 ;
if ( V_94 ) {
F_114 ( V_94 -> V_169 , V_189 , V_190 , 0 ) ;
if ( ! F_106 ( & V_94 -> V_161 ) ) {
F_115 ( 1 , L_22 ) ;
} else if ( V_94 -> V_104 == V_105 ||
V_94 -> V_104 == V_175 ) {
if ( V_188 == V_191 )
F_101 ( V_2 , V_94 ) ;
else
F_103 ( V_2 , V_94 ) ;
}
}
F_104 ( & V_2 -> V_18 , V_115 ) ;
}
static int F_116 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
return ( F_4 ( V_2 ) >> 3 ) % V_2 -> V_84 ;
}
int F_117 ( struct V_53 * V_54 , bool V_193 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
if ( F_118 ( V_33 , V_2 -> V_32 ) )
F_62 ( 10 ) ;
F_119 ( V_2 , V_193 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
F_120 ( V_194 , & V_54 -> V_115 ) ;
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
int F_121 ( struct V_53 * V_54 , bool V_195 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
if ( F_118 ( V_33 , V_2 -> V_32 ) )
F_62 ( 100 ) ;
F_84 ( V_194 , & V_54 -> V_115 ) ;
if ( V_2 -> V_55 )
return 0 ;
if ( F_2 ( V_2 , & V_2 -> V_4 -> V_52 ) == V_126 &&
! V_195 ) {
int V_8 = V_131 ;
F_122 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_196;
if ( ! V_54 -> V_117 . V_197 -> V_198 )
V_8 &= ~ V_145 ;
F_10 ( V_2 , V_8 , & V_2 -> V_4 -> V_19 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
V_196:
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_123 ( V_54 -> V_117 . V_197 ) ;
( void ) F_8 ( V_2 ) ;
( void ) F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_196;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , V_126 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_2 -> V_30 = V_148 ;
F_12 ( & V_2 -> V_18 ) ;
return 1 ;
}
void F_124 ( struct V_199 * V_200 ,
const struct V_201 * V_202 )
{
* V_200 = V_203 ;
if ( V_202 ) {
V_200 -> V_204 += V_202 -> V_205 ;
if ( V_202 -> V_206 )
V_200 -> V_206 = V_202 -> V_206 ;
}
}
static int T_5 F_125 ( void )
{
int V_27 = 0 ;
if ( F_126 () )
return - V_12 ;
F_127 ( V_207 L_23 V_208 L_24 , V_209 ) ;
F_84 ( V_210 , & V_211 ) ;
if ( F_82 ( V_212 , & V_211 ) ||
F_82 ( V_213 , & V_211 ) )
F_127 ( V_214 L_25
L_26 ) ;
F_128 ( L_27 ,
V_209 ,
sizeof( struct V_172 ) , sizeof( struct V_215 ) ,
sizeof( struct V_216 ) , sizeof( struct V_217 ) ) ;
#ifdef F_129
V_218 = F_130 ( L_28 , V_219 ) ;
if ( ! V_218 ) {
V_27 = - V_220 ;
goto V_221;
}
#endif
#ifdef F_131
V_27 = F_132 ( & F_131 ) ;
if ( V_27 < 0 )
goto V_222;
#endif
#ifdef F_133
V_27 = F_134 ( & F_133 ) ;
if ( V_27 < 0 )
goto V_223;
#endif
#ifdef F_135
V_27 = F_132 ( & F_135 ) ;
if ( V_27 < 0 )
goto V_224;
#endif
#ifdef F_136
V_27 = F_132 ( & F_136 ) ;
if ( V_27 < 0 )
goto V_225;
#endif
return V_27 ;
#ifdef F_136
V_225:
#endif
#ifdef F_135
F_137 ( & F_135 ) ;
V_224:
#endif
#ifdef F_133
F_138 ( & F_133 ) ;
V_223:
#endif
#ifdef F_131
F_137 ( & F_131 ) ;
V_222:
#endif
#ifdef F_129
F_139 ( V_218 ) ;
V_218 = NULL ;
V_221:
#endif
F_120 ( V_210 , & V_211 ) ;
return V_27 ;
}
static void T_6 F_140 ( void )
{
#ifdef F_136
F_137 ( & F_136 ) ;
#endif
#ifdef F_135
F_137 ( & F_135 ) ;
#endif
#ifdef F_131
F_137 ( & F_131 ) ;
#endif
#ifdef F_133
F_138 ( & F_133 ) ;
#endif
#ifdef F_129
F_139 ( V_218 ) ;
#endif
F_120 ( V_210 , & V_211 ) ;
}
