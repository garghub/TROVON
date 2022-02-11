static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
T_2 V_4 , T_2 V_5 , int V_6 )
{
T_2 V_7 ;
do {
V_7 = F_2 ( V_2 , V_3 ) ;
if ( V_7 == ~ ( T_2 ) 0 )
return - V_8 ;
V_7 &= V_4 ;
if ( V_7 == V_5 )
return 0 ;
F_3 ( 1 ) ;
V_6 -- ;
} while ( V_6 > 0 );
return - V_9 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_2 V_10 ;
V_10 = F_2 ( V_2 , & V_2 -> V_11 -> V_12 ) ;
return ( V_10 & 3 ) == V_13 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 V_14 ;
F_6 ( & V_2 -> V_15 ) ;
F_7 ( V_2 , 0 , & V_2 -> V_11 -> V_16 ) ;
if ( F_8 ( V_2 ) && ! F_4 ( V_2 ) ) {
F_9 ( & V_2 -> V_15 ) ;
return 0 ;
}
V_2 -> V_17 &= ~ V_18 ;
V_14 = F_2 ( V_2 , & V_2 -> V_11 -> V_17 ) ;
V_14 &= ~ ( V_18 | V_19 ) ;
F_7 ( V_2 , V_14 , & V_2 -> V_11 -> V_17 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_10 ( F_11 ( V_2 ) -> V_20 ) ;
return F_1 ( V_2 , & V_2 -> V_11 -> V_21 ,
V_22 , V_22 , 16 * 125 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_2 V_10 ;
V_10 = F_2 ( V_2 , & V_2 -> V_11 -> V_12 ) ;
V_10 |= V_13 ;
if ( F_13 ( V_2 ) )
V_10 |= V_23 ;
F_7 ( V_2 , V_10 , & V_2 -> V_11 -> V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_24 ;
T_2 V_17 = F_2 ( V_2 , & V_2 -> V_11 -> V_17 ) ;
if ( V_2 -> V_25 && ! F_15 () )
V_2 -> V_25 = NULL ;
V_17 |= V_26 ;
F_16 ( V_2 , L_1 , V_17 ) ;
F_7 ( V_2 , V_17 , & V_2 -> V_11 -> V_17 ) ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_24 = F_1 ( V_2 , & V_2 -> V_11 -> V_17 ,
V_26 , 0 , 250 * 1000 ) ;
if ( V_2 -> V_31 ) {
F_7 ( V_2 , V_32 | V_33 ,
& V_2 -> V_11 -> V_34 ) ;
F_7 ( V_2 , V_35 , & V_2 -> V_11 -> V_36 ) ;
}
if ( V_24 )
return V_24 ;
if ( F_8 ( V_2 ) )
F_12 ( V_2 ) ;
if ( V_2 -> V_25 )
F_17 () ;
V_2 -> V_37 = V_2 -> V_38 =
V_2 -> V_39 = 0 ;
return V_24 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 V_14 ;
if ( V_2 -> V_27 != V_40 )
return;
V_14 = ( V_2 -> V_17 << 10 ) & ( V_41 | V_42 ) ;
F_1 ( V_2 , & V_2 -> V_11 -> V_21 , V_41 | V_42 , V_14 , 16 * 125 ) ;
F_6 ( & V_2 -> V_15 ) ;
V_2 -> V_17 &= ~ ( V_43 | V_44 ) ;
F_7 ( V_2 , V_2 -> V_17 , & V_2 -> V_11 -> V_17 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_1 ( V_2 , & V_2 -> V_11 -> V_21 , V_41 | V_42 , 0 , 16 * 125 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_45 = F_20 ( V_2 -> V_46 ) ;
while ( V_45 -- )
F_7 ( V_2 , V_47 ,
& V_2 -> V_11 -> V_48 [ V_45 ] ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( & V_2 -> V_15 ) ;
V_2 -> V_27 = V_28 ;
F_19 ( V_2 ) ;
F_7 ( V_2 , 0 , & V_2 -> V_11 -> V_49 ) ;
F_2 ( V_2 , & V_2 -> V_11 -> V_49 ) ;
F_9 ( & V_2 -> V_15 ) ;
}
static void F_22 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
F_6 ( & V_2 -> V_15 ) ;
V_2 -> V_52 = true ;
V_2 -> V_27 = V_53 ;
V_2 -> V_54 = 0 ;
F_9 ( & V_2 -> V_15 ) ;
F_21 ( V_2 ) ;
F_24 ( & V_2 -> V_55 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_56 )
{
unsigned V_45 ;
if ( ! F_26 ( V_2 -> V_46 ) )
return;
F_27 ( V_2 , L_2 , V_56 ? L_3 : L_4 ) ;
for ( V_45 = F_20 ( V_2 -> V_46 ) ; V_45 > 0 ; )
( void ) F_28 ( F_11 ( V_2 ) ,
V_56 ? V_57 : V_58 ,
V_59 ,
V_45 -- , NULL , 0 ) ;
F_2 ( V_2 , & V_2 -> V_11 -> V_17 ) ;
F_29 ( 20 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 ) {
V_2 -> V_61 = true ;
return;
}
V_2 -> V_60 = true ;
V_62:
V_2 -> V_61 = false ;
if ( V_2 -> V_63 )
F_31 ( V_2 ) ;
if ( V_2 -> V_64 > 0 )
F_32 ( V_2 ) ;
if ( V_2 -> V_65 > 0 )
F_33 ( V_2 ) ;
if ( V_2 -> V_61 )
goto V_62;
V_2 -> V_60 = false ;
F_34 ( V_2 ) ;
}
static void F_35 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
F_27 ( V_2 , L_5 ) ;
F_6 ( & V_2 -> V_15 ) ;
V_2 -> V_54 = 0 ;
F_9 ( & V_2 -> V_15 ) ;
F_18 ( V_2 ) ;
F_21 ( V_2 ) ;
F_14 ( V_2 ) ;
F_24 ( & V_2 -> V_55 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_38 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_66 == 1 )
F_40 () ;
#ifdef F_41
F_27 ( V_2 , L_6 ,
V_2 -> V_67 . V_68 , V_2 -> V_67 . error , V_2 -> V_67 . V_69 ,
V_2 -> V_67 . V_70 ) ;
F_27 ( V_2 , L_7 ,
V_2 -> V_67 . V_71 , V_2 -> V_67 . V_72 ) ;
#endif
F_42 ( V_2 , L_8 ,
F_2 ( V_2 , & V_2 -> V_11 -> V_21 ) ) ;
}
static int F_43 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
T_2 V_14 ;
int V_24 ;
T_2 V_73 ;
struct V_74 * V_75 ;
F_44 ( & V_2 -> V_15 ) ;
V_2 -> V_76 = 1 ;
F_45 ( & V_2 -> V_55 , V_77 , V_78 ) ;
V_2 -> V_55 . V_79 = V_80 ;
V_2 -> V_81 = V_82 ;
V_73 = F_2 ( V_2 , & V_2 -> V_83 -> V_73 ) ;
V_2 -> V_84 = 100 ;
V_2 -> V_85 = V_86 ;
F_46 ( & V_2 -> V_87 ) ;
F_46 ( & V_2 -> V_88 ) ;
F_46 ( & V_2 -> V_89 ) ;
if ( F_47 ( V_73 ) ) {
switch ( V_90 ) {
case 0 : V_2 -> V_85 = 1024 ; break;
case 1 : V_2 -> V_85 = 512 ; break;
case 2 : V_2 -> V_85 = 256 ; break;
default: F_48 () ;
}
}
if ( ( V_24 = F_49 ( V_2 , V_91 ) ) < 0 )
return V_24 ;
if ( F_50 ( V_73 ) )
V_2 -> V_92 = 2 + 8 ;
else
V_2 -> V_92 = 2 + F_51 ( V_73 ) ;
V_2 -> V_93 -> V_94 . V_95 = NULL ;
V_75 = V_2 -> V_93 -> V_75 ;
V_75 -> V_96 = F_52 ( V_2 , V_2 -> V_93 -> V_97 ) ;
V_75 -> V_98 = F_53 ( V_2 , V_99 ) ;
#if F_54 ( V_100 )
V_75 -> V_98 |= F_53 ( V_2 , V_101 ) ;
#endif
V_75 -> V_102 = F_53 ( V_2 , V_103 ) ;
V_75 -> V_104 = F_55 ( V_2 ) ;
V_2 -> V_93 -> V_105 = V_106 ;
V_75 -> V_107 = F_56 ( V_2 , V_2 -> V_93 -> V_108 -> V_109 ) ;
if ( V_110 < 0 || V_110 > 6 )
V_110 = 0 ;
V_14 = 1 << ( 16 + V_110 ) ;
if ( F_57 ( V_73 ) ) {
V_2 -> V_111 = 1 ;
F_27 ( V_2 , L_9 ) ;
V_14 |= V_112 ;
}
if ( F_58 ( V_73 ) ) {
if ( V_113 ) {
V_113 = F_59 ( V_113 , ( unsigned ) 3 ) ;
V_14 |= V_114 ;
V_14 |= V_113 << 8 ;
}
F_27 ( V_2 , L_10 , V_113 ) ;
}
if ( F_47 ( V_73 ) ) {
V_14 &= ~ ( 3 << 2 ) ;
V_14 |= ( V_90 << 2 ) ;
}
if ( F_60 ( V_73 ) ) {
F_27 ( V_2 , L_11 ) ;
V_2 -> V_115 = 1 ;
if ( V_116 > 0xf ) {
F_27 ( V_2 , L_12 ,
V_116 ) ;
V_116 = 0 ;
}
V_14 |= V_116 << 24 ;
}
V_2 -> V_17 = V_14 ;
if ( ! ( V_51 -> V_117 -> V_118 & V_119 ) )
V_51 -> V_120 . V_121 = ~ 0 ;
return 0 ;
}
static int F_61 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
T_2 V_14 ;
T_2 V_73 ;
V_51 -> V_122 = 1 ;
F_7 ( V_2 , V_2 -> V_123 , & V_2 -> V_11 -> V_124 ) ;
F_7 ( V_2 , ( T_2 ) V_2 -> V_93 -> V_97 , & V_2 -> V_11 -> V_125 ) ;
V_73 = F_2 ( V_2 , & V_2 -> V_83 -> V_73 ) ;
if ( F_62 ( V_73 ) ) {
F_7 ( V_2 , 0 , & V_2 -> V_11 -> V_126 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_17 &= ~ ( V_127 | V_19 | V_44 | V_43 | V_26 ) ;
V_2 -> V_17 |= V_18 ;
F_7 ( V_2 , V_2 -> V_17 , & V_2 -> V_11 -> V_17 ) ;
F_16 ( V_2 , L_13 , V_2 -> V_17 ) ;
F_63 ( & V_128 ) ;
V_2 -> V_27 = V_40 ;
F_7 ( V_2 , V_129 , & V_2 -> V_11 -> V_49 ) ;
F_2 ( V_2 , & V_2 -> V_11 -> V_17 ) ;
F_29 ( 5 ) ;
F_64 ( & V_128 ) ;
V_2 -> V_130 = F_65 () ;
V_14 = F_66 ( V_2 , F_2 ( V_2 , & V_2 -> V_83 -> V_131 ) ) ;
F_67 ( V_2 ,
L_14 ,
( ( V_2 -> V_132 & 0xf0 ) >> 4 ) , ( V_2 -> V_132 & 0x0f ) ,
V_14 >> 8 , V_14 & 0xff ,
V_133 ? L_15 : L_16 ) ;
F_7 ( V_2 , V_134 ,
& V_2 -> V_11 -> V_16 ) ;
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
int V_24 ;
V_2 -> V_11 = ( void T_1 * ) V_2 -> V_83 +
F_71 ( V_2 , F_2 ( V_2 , & V_2 -> V_83 -> V_131 ) ) ;
F_72 ( V_2 , L_1 ) ;
F_73 ( V_2 , L_1 ) ;
V_2 -> V_46 = F_2 ( V_2 , & V_2 -> V_83 -> V_46 ) ;
V_2 -> V_132 = V_135 ;
V_24 = F_43 ( V_51 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_5 ( V_2 ) ;
if ( V_24 )
return V_24 ;
if ( F_8 ( V_2 ) )
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static T_3 F_74 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
T_2 V_21 , V_136 , V_137 = 0 , V_138 ;
int V_139 ;
F_75 ( & V_2 -> V_15 ) ;
V_21 = F_2 ( V_2 , & V_2 -> V_11 -> V_21 ) ;
if ( V_21 == ~ ( T_2 ) 0 ) {
F_27 ( V_2 , L_17 ) ;
goto V_140;
}
V_136 = V_21 & ( V_134 | V_141 ) ;
if ( ! V_136 || F_76 ( V_2 -> V_27 == V_28 ) ) {
F_77 ( & V_2 -> V_15 ) ;
return V_142 ;
}
F_7 ( V_2 , V_136 , & V_2 -> V_11 -> V_21 ) ;
V_138 = F_2 ( V_2 , & V_2 -> V_11 -> V_17 ) ;
V_139 = 0 ;
#ifdef F_78
F_42 ( V_2 , L_18 , V_21 ) ;
#endif
if ( F_79 ( ( V_21 & ( V_143 | V_144 ) ) != 0 ) ) {
if ( F_79 ( ( V_21 & V_144 ) == 0 ) )
F_80 ( V_2 -> V_67 . V_68 ) ;
else
F_80 ( V_2 -> V_67 . error ) ;
V_139 = 1 ;
}
if ( V_21 & V_145 ) {
V_2 -> V_54 &= ~ F_81 ( V_146 ) ;
if ( V_2 -> V_81 == V_146 )
++ V_2 -> V_81 ;
if ( V_138 & V_19 )
F_27 ( V_2 , L_19 ) ;
if ( V_2 -> V_147 ) {
F_80 ( V_2 -> V_67 . V_69 ) ;
F_82 ( V_2 ) ;
} else
F_27 ( V_2 , L_20 ) ;
}
if ( V_21 & V_148 ) {
unsigned V_149 = F_20 ( V_2 -> V_46 ) ;
T_2 V_150 = 0 ;
V_137 = V_21 ;
if ( V_2 -> V_27 == V_151 )
F_83 ( V_51 ) ;
if ( V_2 -> V_111 )
V_150 = V_21 >> 16 ;
while ( V_149 -- ) {
int V_152 ;
if ( V_2 -> V_111 && ! ( V_150 & ( 1 << V_149 ) ) )
continue;
V_152 = F_2 ( V_2 ,
& V_2 -> V_11 -> V_48 [ V_149 ] ) ;
if ( V_152 & V_153 )
continue;
if ( ! ( F_84 ( V_149 , & V_2 -> V_38 ) &&
( ( V_152 & V_154 ) ||
! ( V_152 & V_155 ) ) &&
( V_152 & V_156 ) &&
V_2 -> V_157 [ V_149 ] == 0 ) )
continue;
V_2 -> V_157 [ V_149 ] = V_30 + F_85 ( 25 ) ;
F_86 ( V_149 , & V_2 -> V_39 ) ;
F_27 ( V_2 , L_21 , V_149 + 1 ) ;
F_87 ( & V_51 -> V_158 , V_2 -> V_157 [ V_149 ] ) ;
}
}
if ( F_76 ( ( V_21 & V_159 ) != 0 ) ) {
F_88 ( V_2 , L_22 ) ;
F_16 ( V_2 , L_23 , V_138 ) ;
F_42 ( V_2 , L_23 , V_21 ) ;
V_140:
F_89 ( V_51 ) ;
V_2 -> V_52 = true ;
V_2 -> V_27 = V_53 ;
V_2 -> V_17 &= ~ ( V_18 | V_43 | V_44 ) ;
F_7 ( V_2 , V_2 -> V_17 , & V_2 -> V_11 -> V_17 ) ;
F_7 ( V_2 , 0 , & V_2 -> V_11 -> V_16 ) ;
F_90 ( V_2 ) ;
V_139 = 0 ;
}
if ( V_139 )
F_30 ( V_2 ) ;
F_77 ( & V_2 -> V_15 ) ;
if ( V_137 )
F_91 ( V_51 ) ;
return V_160 ;
}
static int F_92 (
struct V_50 * V_51 ,
struct V_161 * V_161 ,
T_4 V_162
) {
struct V_1 * V_2 = F_23 ( V_51 ) ;
struct V_163 V_164 ;
F_46 ( & V_164 ) ;
switch ( F_93 ( V_161 -> V_165 ) ) {
case V_166 :
if ( V_161 -> V_167 > ( 16 * 1024 ) )
return - V_168 ;
default:
if ( ! F_94 ( V_2 , V_161 , & V_164 , V_162 ) )
return - V_169 ;
return F_95 ( V_2 , V_161 , & V_164 , V_162 ) ;
case V_170 :
if ( ! F_94 ( V_2 , V_161 , & V_164 , V_162 ) )
return - V_169 ;
return F_96 ( V_2 , V_161 , & V_164 , V_162 ) ;
case V_171 :
if ( V_161 -> V_172 -> V_173 == V_174 )
return F_97 ( V_2 , V_161 , V_162 ) ;
else
return F_98 ( V_2 , V_161 , V_162 ) ;
}
}
static int F_99 ( struct V_50 * V_51 , struct V_161 * V_161 , int V_21 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
struct V_175 * V_95 ;
unsigned long V_118 ;
int V_176 ;
F_100 ( & V_2 -> V_15 , V_118 ) ;
V_176 = F_101 ( V_51 , V_161 , V_21 ) ;
if ( V_176 )
goto V_5;
switch ( F_93 ( V_161 -> V_165 ) ) {
default:
V_95 = (struct V_175 * ) V_161 -> V_177 ;
if ( ! V_95 )
break;
switch ( V_95 -> V_105 ) {
case V_106 :
case V_178 :
F_102 ( V_2 , V_95 ) ;
break;
case V_179 :
case V_180 :
break;
case V_181 :
F_103 ( V_2 , V_95 ) ;
break;
}
break;
case V_170 :
V_95 = (struct V_175 * ) V_161 -> V_177 ;
if ( ! V_95 )
break;
switch ( V_95 -> V_105 ) {
case V_106 :
case V_178 :
F_104 ( V_2 , V_95 ) ;
break;
case V_181 :
F_103 ( V_2 , V_95 ) ;
break;
default:
F_27 ( V_2 , L_24 ,
V_95 , V_95 -> V_105 ) ;
goto V_5;
}
break;
case V_171 :
break;
}
V_5:
F_105 ( & V_2 -> V_15 , V_118 ) ;
return V_176 ;
}
static void
F_106 ( struct V_50 * V_51 , struct V_182 * V_183 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
unsigned long V_118 ;
struct V_175 * V_95 , * V_10 ;
V_62:
F_100 ( & V_2 -> V_15 , V_118 ) ;
V_95 = V_183 -> V_177 ;
if ( ! V_95 )
goto V_5;
if ( V_95 -> V_75 == NULL ) {
struct V_184 * V_185 = V_183 -> V_177 ;
if ( ! F_107 ( & V_185 -> V_186 ) )
goto V_187;
F_108 ( V_185 ) ;
goto V_5;
}
if ( V_2 -> V_27 < V_40 )
V_95 -> V_105 = V_181 ;
switch ( V_95 -> V_105 ) {
case V_106 :
case V_178 :
for ( V_10 = V_2 -> V_93 -> V_94 . V_95 ;
V_10 && V_10 != V_95 ;
V_10 = V_10 -> V_94 . V_95 )
continue;
if ( V_10 )
F_102 ( V_2 , V_95 ) ;
case V_179 :
case V_180 :
V_187:
F_105 ( & V_2 -> V_15 , V_118 ) ;
F_109 ( 1 ) ;
goto V_62;
case V_181 :
if ( V_95 -> V_188 )
goto V_187;
if ( F_107 ( & V_95 -> V_164 ) ) {
F_110 ( V_2 , V_95 ) ;
break;
}
default:
F_88 ( V_2 , L_25 ,
V_95 , V_183 -> V_189 . V_190 , V_95 -> V_105 ,
F_107 ( & V_95 -> V_164 ) ? L_16 : L_26 ) ;
break;
}
V_5:
V_183 -> V_177 = NULL ;
F_105 ( & V_2 -> V_15 , V_118 ) ;
}
static void
F_111 ( struct V_50 * V_51 , struct V_182 * V_183 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
struct V_175 * V_95 ;
int V_191 = F_112 ( & V_183 -> V_189 ) ;
int V_192 = F_113 ( & V_183 -> V_189 ) ;
int V_193 = F_114 ( & V_183 -> V_189 ) ;
unsigned long V_118 ;
if ( V_191 != V_194 && V_191 != V_195 )
return;
F_100 ( & V_2 -> V_15 , V_118 ) ;
V_95 = V_183 -> V_177 ;
if ( V_95 ) {
F_115 ( V_95 -> V_172 , V_192 , V_193 , 0 ) ;
if ( ! F_107 ( & V_95 -> V_164 ) ) {
F_116 ( 1 , L_27 ) ;
} else if ( V_95 -> V_105 == V_106 ||
V_95 -> V_105 == V_178 ) {
if ( V_191 == V_194 )
F_102 ( V_2 , V_95 ) ;
else
F_104 ( V_2 , V_95 ) ;
}
}
F_105 ( & V_2 -> V_15 , V_118 ) ;
}
static int F_117 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
return ( F_118 ( V_2 ) >> 3 ) % V_2 -> V_85 ;
}
static int T_5 F_119 ( struct V_50 * V_51 , bool V_196 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
if ( F_120 ( V_30 , V_2 -> V_29 ) )
F_29 ( 10 ) ;
F_121 ( V_2 , V_196 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_7 ( V_2 , 0 , & V_2 -> V_11 -> V_16 ) ;
( void ) F_2 ( V_2 , & V_2 -> V_11 -> V_16 ) ;
F_122 ( V_197 , & V_51 -> V_118 ) ;
F_9 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int T_5 F_123 ( struct V_50 * V_51 , bool V_198 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
if ( F_120 ( V_30 , V_2 -> V_29 ) )
F_29 ( 100 ) ;
F_86 ( V_197 , & V_51 -> V_118 ) ;
if ( V_2 -> V_52 )
return 0 ;
if ( F_2 ( V_2 , & V_2 -> V_11 -> V_49 ) == V_129 &&
! V_198 ) {
int V_4 = V_134 ;
F_124 ( V_2 ) ;
F_6 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_52 )
goto V_199;
if ( ! V_51 -> V_120 . V_200 -> V_201 )
V_4 &= ~ V_148 ;
F_7 ( V_2 , V_4 , & V_2 -> V_11 -> V_16 ) ;
F_2 ( V_2 , & V_2 -> V_11 -> V_16 ) ;
V_199:
F_9 ( & V_2 -> V_15 ) ;
return 0 ;
}
F_125 ( V_51 -> V_120 . V_200 ) ;
( void ) F_5 ( V_2 ) ;
( void ) F_14 ( V_2 ) ;
F_6 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_52 )
goto V_199;
F_7 ( V_2 , V_2 -> V_17 , & V_2 -> V_11 -> V_17 ) ;
F_7 ( V_2 , V_129 , & V_2 -> V_11 -> V_49 ) ;
F_2 ( V_2 , & V_2 -> V_11 -> V_17 ) ;
V_2 -> V_27 = V_151 ;
F_9 ( & V_2 -> V_15 ) ;
F_25 ( V_2 , 1 ) ;
return 1 ;
}
static int T_6 F_126 ( void )
{
int V_24 = 0 ;
if ( F_127 () )
return - V_8 ;
F_128 ( V_202 L_28 V_203 L_29 , V_204 ) ;
F_86 ( V_205 , & V_206 ) ;
if ( F_84 ( V_207 , & V_206 ) ||
F_84 ( V_208 , & V_206 ) )
F_128 ( V_209 L_30
L_31 ) ;
F_129 ( L_32 ,
V_204 ,
sizeof( struct V_175 ) , sizeof( struct V_210 ) ,
sizeof( struct V_211 ) , sizeof( struct V_212 ) ) ;
#ifdef F_130
V_213 = F_131 ( L_33 , V_214 ) ;
if ( ! V_213 ) {
V_24 = - V_215 ;
goto V_216;
}
#endif
#ifdef F_132
V_24 = F_133 ( & F_132 ) ;
if ( V_24 < 0 )
goto V_217;
#endif
#ifdef F_134
V_24 = F_135 ( & F_134 ) ;
if ( V_24 < 0 )
goto V_218;
#endif
#ifdef F_136
V_24 = F_137 ( & F_136 ) ;
if ( V_24 < 0 )
goto V_219;
#endif
#ifdef F_138
V_24 = F_133 ( & F_138 ) ;
if ( V_24 < 0 )
goto V_220;
#endif
#ifdef F_139
V_24 = F_133 ( & F_139 ) ;
if ( V_24 < 0 )
goto V_221;
#endif
return V_24 ;
#ifdef F_139
V_221:
#endif
#ifdef F_138
F_140 ( & F_138 ) ;
V_220:
#endif
#ifdef F_136
F_141 ( & F_136 ) ;
V_219:
#endif
#ifdef F_134
F_142 ( & F_134 ) ;
V_218:
#endif
#ifdef F_132
F_140 ( & F_132 ) ;
V_217:
#endif
#ifdef F_130
F_143 ( V_213 ) ;
V_213 = NULL ;
V_216:
#endif
F_122 ( V_205 , & V_206 ) ;
return V_24 ;
}
static void T_7 F_144 ( void )
{
#ifdef F_139
F_140 ( & F_139 ) ;
#endif
#ifdef F_138
F_140 ( & F_138 ) ;
#endif
#ifdef F_132
F_140 ( & F_132 ) ;
#endif
#ifdef F_134
F_142 ( & F_134 ) ;
#endif
#ifdef F_136
F_141 ( & F_136 ) ;
#endif
#ifdef F_130
F_143 ( V_213 ) ;
#endif
F_122 ( V_205 , & V_206 ) ;
}
