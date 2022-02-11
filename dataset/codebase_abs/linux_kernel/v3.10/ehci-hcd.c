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
F_45 ( & V_2 -> V_89 ) ;
F_45 ( & V_2 -> V_90 ) ;
F_45 ( & V_2 -> V_91 ) ;
if ( F_46 ( V_72 ) ) {
switch ( V_92 ) {
case 0 : V_2 -> V_84 = 1024 ; break;
case 1 : V_2 -> V_84 = 512 ; break;
case 2 : V_2 -> V_84 = 256 ; break;
default: F_47 () ;
}
}
if ( ( V_27 = F_48 ( V_2 , V_93 ) ) < 0 )
return V_27 ;
if ( F_49 ( V_72 ) )
V_2 -> V_94 = 0 ;
else
V_2 -> V_94 = 2 + F_50 ( V_72 ) ;
V_2 -> V_95 -> V_96 . V_97 = NULL ;
V_74 = V_2 -> V_95 -> V_74 ;
V_74 -> V_98 = F_51 ( V_2 , V_2 -> V_95 -> V_99 ) ;
V_74 -> V_100 = F_52 ( V_2 , V_101 ) ;
#if F_53 ( V_102 )
V_74 -> V_100 |= F_52 ( V_2 , V_103 ) ;
#endif
V_74 -> V_104 = F_52 ( V_2 , V_105 ) ;
V_74 -> V_106 = F_54 ( V_2 ) ;
V_2 -> V_95 -> V_107 = V_108 ;
V_74 -> V_109 = F_55 ( V_2 , V_2 -> V_95 -> V_110 -> V_111 ) ;
if ( V_112 < 0 || V_112 > 6 )
V_112 = 0 ;
V_17 = 1 << ( 16 + V_112 ) ;
if ( F_56 ( V_72 ) ) {
V_2 -> V_113 = 1 ;
F_34 ( V_2 , L_6 ) ;
V_17 |= V_114 ;
}
if ( F_57 ( V_72 ) ) {
if ( V_115 ) {
V_115 = F_58 ( V_115 , ( unsigned ) 3 ) ;
V_17 |= V_116 ;
V_17 |= V_115 << 8 ;
}
F_34 ( V_2 , L_7 , V_115 ) ;
}
if ( F_46 ( V_72 ) ) {
V_17 &= ~ ( 3 << 2 ) ;
V_17 |= ( V_92 << 2 ) ;
}
V_2 -> V_20 = V_17 ;
if ( ! ( V_54 -> V_117 -> V_118 & V_119 ) )
V_54 -> V_120 . V_121 = ~ 0 ;
return 0 ;
}
static int F_59 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_17 ;
T_2 V_72 ;
V_54 -> V_122 = 1 ;
F_10 ( V_2 , V_2 -> V_123 , & V_2 -> V_4 -> V_124 ) ;
F_10 ( V_2 , ( T_2 ) V_2 -> V_95 -> V_99 , & V_2 -> V_4 -> V_125 ) ;
V_72 = F_2 ( V_2 , & V_2 -> V_82 -> V_72 ) ;
if ( F_60 ( V_72 ) ) {
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_126 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_20 &= ~ ( V_127 | V_22 | V_47 | V_46 | V_29 ) ;
V_2 -> V_20 |= V_21 ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_19 ( V_2 , L_8 , V_2 -> V_20 ) ;
F_61 ( & V_128 ) ;
V_2 -> V_30 = V_43 ;
F_10 ( V_2 , V_129 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
F_62 ( 5 ) ;
F_63 ( & V_128 ) ;
V_2 -> V_130 = F_64 () ;
V_17 = F_65 ( V_2 , F_2 ( V_2 , & V_2 -> V_82 -> V_131 ) ) ;
F_66 ( V_2 ,
L_9 ,
( ( V_2 -> V_132 & 0xf0 ) >> 4 ) , ( V_2 -> V_132 & 0x0f ) ,
V_17 >> 8 , V_17 & 0xff ,
V_133 ? L_10 : L_11 ) ;
F_10 ( V_2 , V_134 ,
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
F_70 ( V_2 , F_2 ( V_2 , & V_2 -> V_82 -> V_131 ) ) ;
F_71 ( V_2 , L_1 ) ;
F_72 ( V_2 , L_1 ) ;
V_2 -> V_49 = F_2 ( V_2 , & V_2 -> V_82 -> V_49 ) ;
V_2 -> V_132 = V_135 ;
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
struct V_1 * V_2 = F_26 ( V_54 ) ;
T_2 V_24 , V_136 , V_137 = 0 , V_138 ;
int V_139 ;
F_74 ( & V_2 -> V_18 ) ;
V_24 = F_2 ( V_2 , & V_2 -> V_4 -> V_24 ) ;
if ( V_24 == ~ ( T_2 ) 0 ) {
F_34 ( V_2 , L_12 ) ;
goto V_140;
}
V_136 = V_24 & ( V_134 | V_141 ) ;
if ( ! V_136 || F_3 ( V_2 -> V_30 == V_31 ) ) {
F_75 ( & V_2 -> V_18 ) ;
return V_142 ;
}
F_10 ( V_2 , V_136 , & V_2 -> V_4 -> V_24 ) ;
V_138 = F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_139 = 0 ;
#ifdef F_76
F_41 ( V_2 , L_13 , V_24 ) ;
#endif
if ( F_77 ( ( V_24 & ( V_143 | V_144 ) ) != 0 ) ) {
if ( F_77 ( ( V_24 & V_144 ) == 0 ) )
F_78 ( V_2 -> V_66 . V_67 ) ;
else
F_78 ( V_2 -> V_66 . error ) ;
V_139 = 1 ;
}
if ( V_24 & V_145 ) {
V_2 -> V_57 &= ~ F_79 ( V_146 ) ;
if ( V_2 -> V_80 == V_146 )
++ V_2 -> V_80 ;
if ( V_138 & V_22 )
F_34 ( V_2 , L_14 ) ;
if ( V_2 -> V_147 )
F_78 ( V_2 -> V_66 . V_68 ) ;
F_80 ( V_2 ) ;
}
if ( V_24 & V_148 ) {
unsigned V_149 = F_23 ( V_2 -> V_49 ) ;
T_2 V_150 = ~ 0 ;
V_137 = V_24 ;
if ( V_2 -> V_30 == V_151 )
F_81 ( V_54 ) ;
if ( V_2 -> V_113 )
V_150 = V_24 >> 16 ;
while ( V_149 -- ) {
int V_152 ;
if ( ! ( V_150 & ( 1 << V_149 ) ) )
continue;
V_152 = F_2 ( V_2 ,
& V_2 -> V_4 -> V_51 [ V_149 ] ) ;
if ( V_152 & V_153 )
continue;
if ( ! ( F_82 ( V_149 , & V_2 -> V_41 ) &&
( ( V_152 & V_154 ) ||
! ( V_152 & V_155 ) ) &&
( V_152 & V_156 ) &&
V_2 -> V_157 [ V_149 ] == 0 ) )
continue;
V_2 -> V_157 [ V_149 ] = V_33 + F_83 ( 25 ) ;
F_84 ( V_149 , & V_2 -> V_42 ) ;
F_34 ( V_2 , L_15 , V_149 + 1 ) ;
F_85 ( & V_54 -> V_120 , V_149 ) ;
F_86 ( & V_54 -> V_158 , V_2 -> V_157 [ V_149 ] ) ;
}
}
if ( F_3 ( ( V_24 & V_159 ) != 0 ) ) {
F_87 ( V_2 , L_16 ) ;
F_19 ( V_2 , L_17 , V_138 ) ;
F_41 ( V_2 , L_17 , V_24 ) ;
V_140:
F_88 ( V_54 ) ;
V_2 -> V_55 = true ;
V_2 -> V_30 = V_56 ;
V_2 -> V_20 &= ~ ( V_21 | V_46 | V_47 ) ;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
F_89 ( V_2 ) ;
V_139 = 0 ;
}
if ( V_139 )
F_28 ( V_2 ) ;
F_75 ( & V_2 -> V_18 ) ;
if ( V_137 )
F_90 ( V_54 ) ;
return V_160 ;
}
static int F_91 (
struct V_53 * V_54 ,
struct V_161 * V_161 ,
T_4 V_162
) {
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_163 V_164 ;
F_45 ( & V_164 ) ;
switch ( F_92 ( V_161 -> V_165 ) ) {
case V_166 :
if ( V_161 -> V_167 > ( 16 * 1024 ) )
return - V_168 ;
default:
if ( ! F_93 ( V_2 , V_161 , & V_164 , V_162 ) )
return - V_169 ;
return F_94 ( V_2 , V_161 , & V_164 , V_162 ) ;
case V_170 :
if ( ! F_93 ( V_2 , V_161 , & V_164 , V_162 ) )
return - V_169 ;
return F_95 ( V_2 , V_161 , & V_164 , V_162 ) ;
case V_171 :
if ( V_161 -> V_172 -> V_173 == V_174 )
return F_96 ( V_2 , V_161 , V_162 ) ;
else
return F_97 ( V_2 , V_161 , V_162 ) ;
}
}
static int F_98 ( struct V_53 * V_54 , struct V_161 * V_161 , int V_24 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_175 * V_97 ;
unsigned long V_118 ;
int V_176 ;
F_99 ( & V_2 -> V_18 , V_118 ) ;
V_176 = F_100 ( V_54 , V_161 , V_24 ) ;
if ( V_176 )
goto V_9;
if ( F_92 ( V_161 -> V_165 ) == V_171 ) {
} else {
V_97 = (struct V_175 * ) V_161 -> V_177 ;
V_97 -> V_178 = 1 ;
switch ( V_97 -> V_107 ) {
case V_108 :
if ( F_92 ( V_161 -> V_165 ) == V_170 )
F_101 ( V_2 , V_97 ) ;
else
F_102 ( V_2 , V_97 ) ;
break;
case V_179 :
V_97 -> V_180 = 1 ;
break;
case V_181 :
case V_182 :
break;
case V_183 :
F_103 ( V_2 , V_97 ) ;
break;
}
}
V_9:
F_104 ( & V_2 -> V_18 , V_118 ) ;
return V_176 ;
}
static void
F_105 ( struct V_53 * V_54 , struct V_184 * V_185 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
unsigned long V_118 ;
struct V_175 * V_97 , * V_14 ;
V_61:
F_99 ( & V_2 -> V_18 , V_118 ) ;
V_97 = V_185 -> V_177 ;
if ( ! V_97 )
goto V_9;
if ( V_97 -> V_74 == NULL ) {
struct V_186 * V_187 = V_185 -> V_177 ;
if ( ! F_106 ( & V_187 -> V_188 ) )
goto V_189;
F_107 ( V_187 ) ;
goto V_9;
}
V_97 -> V_178 = 1 ;
if ( V_2 -> V_30 < V_43 )
V_97 -> V_107 = V_183 ;
switch ( V_97 -> V_107 ) {
case V_108 :
case V_179 :
for ( V_14 = V_2 -> V_95 -> V_96 . V_97 ;
V_14 && V_14 != V_97 ;
V_14 = V_14 -> V_96 . V_97 )
continue;
if ( V_14 )
F_102 ( V_2 , V_97 ) ;
case V_181 :
case V_182 :
V_189:
F_104 ( & V_2 -> V_18 , V_118 ) ;
F_108 ( 1 ) ;
goto V_61;
case V_183 :
if ( V_97 -> V_190 )
goto V_189;
if ( F_106 ( & V_97 -> V_164 ) ) {
F_109 ( V_2 , V_97 ) ;
break;
}
default:
F_87 ( V_2 , L_18 ,
V_97 , V_185 -> V_191 . V_192 , V_97 -> V_107 ,
F_106 ( & V_97 -> V_164 ) ? L_11 : L_19 ) ;
break;
}
V_9:
V_185 -> V_177 = NULL ;
F_104 ( & V_2 -> V_18 , V_118 ) ;
}
static void
F_110 ( struct V_53 * V_54 , struct V_184 * V_185 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
struct V_175 * V_97 ;
int V_193 = F_111 ( & V_185 -> V_191 ) ;
int V_194 = F_112 ( & V_185 -> V_191 ) ;
int V_195 = F_113 ( & V_185 -> V_191 ) ;
unsigned long V_118 ;
if ( V_193 != V_196 && V_193 != V_197 )
return;
F_99 ( & V_2 -> V_18 , V_118 ) ;
V_97 = V_185 -> V_177 ;
if ( V_97 ) {
F_114 ( V_97 -> V_172 , V_194 , V_195 , 0 ) ;
if ( ! F_106 ( & V_97 -> V_164 ) ) {
F_115 ( 1 , L_20 ) ;
} else {
V_97 -> V_178 = 1 ;
if ( V_193 == V_196 )
F_102 ( V_2 , V_97 ) ;
else
F_101 ( V_2 , V_97 ) ;
}
}
F_104 ( & V_2 -> V_18 , V_118 ) ;
}
static int F_116 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
return ( F_4 ( V_2 ) >> 3 ) % V_2 -> V_84 ;
}
int F_117 ( struct V_53 * V_54 , bool V_198 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
if ( F_118 ( V_33 , V_2 -> V_32 ) )
F_62 ( 10 ) ;
F_119 ( V_2 , V_198 ) ;
F_9 ( & V_2 -> V_18 ) ;
F_10 ( V_2 , 0 , & V_2 -> V_4 -> V_19 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
F_120 ( V_199 , & V_54 -> V_118 ) ;
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
int F_121 ( struct V_53 * V_54 , bool V_200 )
{
struct V_1 * V_2 = F_26 ( V_54 ) ;
if ( F_118 ( V_33 , V_2 -> V_32 ) )
F_62 ( 100 ) ;
F_84 ( V_199 , & V_54 -> V_118 ) ;
if ( V_2 -> V_55 )
return 0 ;
if ( F_2 ( V_2 , & V_2 -> V_4 -> V_52 ) == V_129 &&
! V_200 ) {
int V_8 = V_134 ;
F_122 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_201;
if ( ! V_54 -> V_120 . V_202 -> V_203 )
V_8 &= ~ V_148 ;
F_10 ( V_2 , V_8 , & V_2 -> V_4 -> V_19 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_19 ) ;
V_201:
F_12 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_123 ( V_54 -> V_120 . V_202 ) ;
( void ) F_8 ( V_2 ) ;
( void ) F_17 ( V_2 ) ;
F_9 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_55 )
goto V_201;
F_10 ( V_2 , V_2 -> V_20 , & V_2 -> V_4 -> V_20 ) ;
F_10 ( V_2 , V_129 , & V_2 -> V_4 -> V_52 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_20 ) ;
V_2 -> V_30 = V_151 ;
F_12 ( & V_2 -> V_18 ) ;
return 1 ;
}
void F_124 ( struct V_204 * V_205 ,
const struct V_206 * V_207 )
{
* V_205 = V_208 ;
if ( V_207 ) {
V_205 -> V_209 += V_207 -> V_210 ;
if ( V_207 -> V_211 )
V_205 -> V_211 = V_207 -> V_211 ;
}
}
static int T_5 F_125 ( void )
{
int V_27 = 0 ;
if ( F_126 () )
return - V_12 ;
F_127 ( V_212 L_21 V_213 L_22 , V_214 ) ;
F_84 ( V_215 , & V_216 ) ;
if ( F_82 ( V_217 , & V_216 ) ||
F_82 ( V_218 , & V_216 ) )
F_127 ( V_219 L_23
L_24 ) ;
F_128 ( L_25 ,
V_214 ,
sizeof( struct V_175 ) , sizeof( struct V_220 ) ,
sizeof( struct V_221 ) , sizeof( struct V_222 ) ) ;
#ifdef F_129
V_223 = F_130 ( L_26 , V_224 ) ;
if ( ! V_223 ) {
V_27 = - V_225 ;
goto V_226;
}
#endif
#ifdef F_131
V_27 = F_132 ( & F_131 ) ;
if ( V_27 < 0 )
goto V_227;
#endif
#ifdef F_133
V_27 = F_134 ( & F_133 ) ;
if ( V_27 < 0 )
goto V_228;
#endif
#ifdef F_135
V_27 = F_132 ( & F_135 ) ;
if ( V_27 < 0 )
goto V_229;
#endif
#ifdef F_136
V_27 = F_132 ( & F_136 ) ;
if ( V_27 < 0 )
goto V_230;
#endif
return V_27 ;
#ifdef F_136
V_230:
#endif
#ifdef F_135
F_137 ( & F_135 ) ;
V_229:
#endif
#ifdef F_133
F_138 ( & F_133 ) ;
V_228:
#endif
#ifdef F_131
F_137 ( & F_131 ) ;
V_227:
#endif
#ifdef F_129
F_139 ( V_223 ) ;
V_223 = NULL ;
V_226:
#endif
F_120 ( V_215 , & V_216 ) ;
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
F_139 ( V_223 ) ;
#endif
F_120 ( V_215 , & V_216 ) ;
}
