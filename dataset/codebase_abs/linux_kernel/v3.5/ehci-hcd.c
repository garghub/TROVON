static void
F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( F_2 ( & V_2 -> V_5 )
&& ( ( F_3 ( V_6 ) | F_3 ( V_7 ) )
& V_2 -> V_8 ) )
return;
if ( ! F_4 ( V_4 , & V_2 -> V_8 ) ) {
unsigned long V_9 ;
switch ( V_4 ) {
case V_10 :
if ( ! V_2 -> V_11 )
return;
V_9 = V_12 ;
break;
case V_7 :
V_9 = V_13 ;
break;
default:
V_9 = V_14 ;
break;
}
F_5 ( & V_2 -> V_5 , V_9 + V_15 ) ;
}
}
static int F_6 ( struct V_1 * V_2 , void T_1 * V_16 ,
T_2 V_17 , T_2 V_18 , int V_19 )
{
T_2 V_20 ;
do {
V_20 = F_7 ( V_2 , V_16 ) ;
if ( V_20 == ~ ( T_2 ) 0 )
return - V_21 ;
V_20 &= V_17 ;
if ( V_20 == V_18 )
return 0 ;
F_8 ( 1 ) ;
V_19 -- ;
} while ( V_19 > 0 );
return - V_22 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 T_1 * V_23 ;
T_2 V_24 ;
V_23 = ( T_2 T_1 * ) ( ( ( V_25 T_1 * ) V_2 -> V_26 ) + V_27 ) ;
V_24 = F_7 ( V_2 , V_23 ) ;
return ( V_24 & 3 ) == V_28 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_31 ) ;
if ( F_12 ( V_2 ) && F_9 ( V_2 ) == 0 ) {
return 0 ;
}
if ( ( V_29 & V_32 ) != 0 )
return 0 ;
V_2 -> V_33 &= ~ V_34 ;
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_29 &= ~ ( V_34 | V_35 ) ;
F_11 ( V_2 , V_29 , & V_2 -> V_26 -> V_33 ) ;
return F_6 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_32 , V_32 , 16 * 125 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
void T_1 * V_16 , T_2 V_17 , T_2 V_18 ,
int V_19 )
{
unsigned int V_36 ;
int error ;
if ( ! F_14 ( V_37 ) )
return - V_22 ;
V_36 = F_15 ( V_2 ) ;
error = F_6 ( V_2 , V_16 , V_17 , V_18 , V_19 ) ;
if ( error == - V_22 && F_15 ( V_2 ) == V_36 )
return 0 ;
return error ;
}
static int F_13 ( struct V_1 * V_2 ,
void T_1 * V_16 , T_2 V_17 , T_2 V_18 ,
int V_19 )
{
return - V_22 ;
}
static int F_16 ( struct V_1 * V_2 , void T_1 * V_16 ,
T_2 V_17 , T_2 V_18 , int V_19 )
{
int error ;
error = F_6 ( V_2 , V_16 , V_17 , V_18 , V_19 ) ;
if ( error == - V_22 )
error = F_13 ( V_2 , V_16 , V_17 , V_18 ,
V_19 ) ;
if ( error ) {
F_10 ( V_2 ) ;
V_2 -> V_38 = V_39 ;
F_17 ( V_2 , L_1 ,
V_16 , V_17 , V_18 , error ) ;
}
return error ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 T_1 * V_23 ;
T_2 V_24 ;
V_23 = ( T_2 T_1 * ) ( ( ( V_25 T_1 * ) V_2 -> V_26 ) + V_27 ) ;
V_24 = F_7 ( V_2 , V_23 ) ;
V_24 |= V_28 ;
if ( F_19 ( V_2 ) )
V_24 |= V_40 ;
F_11 ( V_2 , V_24 , V_23 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_41 ;
T_2 V_33 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_2 -> V_42 && ! F_21 () )
V_2 -> V_42 = NULL ;
V_33 |= V_43 ;
F_22 ( V_2 , L_2 , V_33 ) ;
F_11 ( V_2 , V_33 , & V_2 -> V_26 -> V_33 ) ;
V_2 -> V_38 = V_39 ;
V_2 -> V_44 = V_15 ;
V_41 = F_6 ( V_2 , & V_2 -> V_26 -> V_33 ,
V_43 , 0 , 250 * 1000 ) ;
if ( V_2 -> V_45 ) {
F_11 ( V_2 , V_46 | V_47 ,
( T_2 T_1 * ) ( ( ( V_25 * ) V_2 -> V_26 ) + V_48 ) ) ;
F_11 ( V_2 , V_49 ,
( T_2 T_1 * ) ( ( ( V_25 * ) V_2 -> V_26 ) + V_50 ) ) ;
}
if ( V_41 )
return V_41 ;
if ( F_12 ( V_2 ) )
F_18 ( V_2 ) ;
if ( V_2 -> V_42 )
F_23 () ;
V_2 -> V_51 = V_2 -> V_52 =
V_2 -> V_53 = 0 ;
return V_41 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_29 ;
#ifdef F_25
if ( V_2 -> V_38 != V_54 )
F_26 () ;
#endif
V_29 = ( V_2 -> V_33 << 10 ) & ( V_55 | V_56 ) ;
if ( F_16 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_55 | V_56 , V_29 , 16 * 125 ) )
return;
V_2 -> V_33 &= ~ ( V_57 | V_58 ) ;
F_11 ( V_2 , V_2 -> V_33 , & V_2 -> V_26 -> V_33 ) ;
F_16 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_55 | V_56 , 0 , 16 * 125 ) ;
}
static void F_27 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
unsigned long V_60 ;
F_28 ( & V_2 -> V_61 , V_60 ) ;
if ( V_2 -> V_62
&& ! F_2 ( & V_2 -> V_63 )
&& V_2 -> V_38 == V_54 ) {
T_2 V_64 , V_30 ;
V_64 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( ( V_30 & V_65 ) || ! ( V_64 & V_35 ) ) {
F_29 ( V_2 -> V_66 . V_67 ) ;
F_11 ( V_2 , V_65 , & V_2 -> V_26 -> V_30 ) ;
}
F_30 ( V_2 , L_3 ,
V_30 , V_64 ) ;
F_31 ( V_2 ) ;
}
F_32 ( & V_2 -> V_61 , V_60 ) ;
}
static void F_33 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
unsigned long V_60 ;
F_28 ( & V_2 -> V_61 , V_60 ) ;
if ( F_34 ( V_7 , & V_2 -> V_8 ) )
F_35 ( V_2 , V_2 -> V_68 ) ;
F_36 ( V_2 ) ;
F_32 ( & V_2 -> V_61 , V_60 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_69 = F_38 ( V_2 -> V_70 ) ;
while ( V_69 -- )
F_11 ( V_2 , V_71 ,
& V_2 -> V_26 -> V_72 [ V_69 ] ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_37 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_73 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_73 ) ;
}
static void F_40 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
F_42 ( & V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_63 ) ;
F_43 ( & V_2 -> V_61 ) ;
F_39 ( V_2 ) ;
F_44 ( & V_2 -> V_61 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_76 )
{
unsigned V_69 ;
if ( ! F_46 ( V_2 -> V_70 ) )
return;
F_47 ( V_2 , L_4 , V_76 ? L_5 : L_6 ) ;
for ( V_69 = F_38 ( V_2 -> V_70 ) ; V_69 > 0 ; )
( void ) F_48 ( F_49 ( V_2 ) ,
V_76 ? V_77 : V_78 ,
V_79 ,
V_69 -- , NULL , 0 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_50 ( 20 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_10 ) ;
if ( V_2 -> V_80 )
return;
V_2 -> V_80 = 1 ;
F_52 ( V_2 ) ;
if ( V_2 -> V_81 != - 1 )
F_53 ( V_2 ) ;
V_2 -> V_80 = 0 ;
if ( V_2 -> V_38 == V_54 &&
( V_2 -> V_68 -> V_82 . V_16 != NULL ||
V_2 -> V_83 != 0 ) )
F_1 ( V_2 , V_10 ) ;
}
static void F_54 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
F_47 ( V_2 , L_7 ) ;
F_42 ( & V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_63 ) ;
F_43 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_38 == V_54 )
F_24 ( V_2 ) ;
F_39 ( V_2 ) ;
F_20 ( V_2 ) ;
F_44 ( & V_2 -> V_61 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_43 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_68 )
F_36 ( V_2 ) ;
F_44 ( & V_2 -> V_61 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> V_84 == 1 )
F_58 () ;
#ifdef F_59
F_47 ( V_2 , L_8 ,
V_2 -> V_66 . V_85 , V_2 -> V_66 . error , V_2 -> V_66 . V_62 ,
V_2 -> V_66 . V_67 ) ;
F_47 ( V_2 , L_9 ,
V_2 -> V_66 . V_86 , V_2 -> V_66 . V_87 ) ;
#endif
F_60 ( V_2 , L_10 ,
F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ) ;
}
static int F_61 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
T_2 V_29 ;
int V_41 ;
T_2 V_88 ;
struct V_89 * V_90 ;
F_62 ( & V_2 -> V_61 ) ;
V_2 -> V_11 = 1 ;
F_63 ( & V_2 -> V_5 ) ;
V_2 -> V_5 . V_91 = F_33 ;
V_2 -> V_5 . V_92 = ( unsigned long ) V_2 ;
F_63 ( & V_2 -> V_63 ) ;
V_2 -> V_63 . V_91 = F_27 ;
V_2 -> V_63 . V_92 = ( unsigned long ) V_2 ;
V_88 = F_7 ( V_2 , & V_2 -> V_93 -> V_88 ) ;
V_2 -> V_94 = 100 ;
V_2 -> V_95 = V_96 ;
F_64 ( & V_2 -> V_97 ) ;
F_64 ( & V_2 -> V_98 ) ;
if ( F_65 ( V_88 ) ) {
switch ( V_99 ) {
case 0 : V_2 -> V_95 = 1024 ; break;
case 1 : V_2 -> V_95 = 512 ; break;
case 2 : V_2 -> V_95 = 256 ; break;
default: F_26 () ;
}
}
if ( ( V_41 = F_66 ( V_2 , V_100 ) ) < 0 )
return V_41 ;
if ( F_67 ( V_88 ) )
V_2 -> V_101 = 2 + 8 ;
else
V_2 -> V_101 = 2 + F_68 ( V_88 ) ;
V_2 -> V_62 = NULL ;
V_2 -> V_81 = - 1 ;
V_2 -> V_102 = - 1 ;
V_2 -> V_68 -> V_82 . V_103 = NULL ;
V_90 = V_2 -> V_68 -> V_90 ;
V_90 -> V_104 = F_69 ( V_2 , V_2 -> V_68 -> V_105 ) ;
V_90 -> V_106 = F_70 ( V_2 , V_107 ) ;
#if F_71 ( V_108 )
V_90 -> V_106 |= F_70 ( V_2 , ( 1 << 7 ) ) ;
#endif
V_90 -> V_109 = F_70 ( V_2 , V_110 ) ;
V_90 -> V_111 = F_72 ( V_2 ) ;
V_2 -> V_68 -> V_112 = V_113 ;
V_90 -> V_114 = F_73 ( V_2 , V_2 -> V_68 -> V_115 -> V_116 ) ;
if ( V_117 < 0 || V_117 > 6 )
V_117 = 0 ;
V_29 = 1 << ( 16 + V_117 ) ;
if ( F_74 ( V_88 ) ) {
V_2 -> V_118 = 1 ;
F_47 ( V_2 , L_11 ) ;
V_29 |= V_119 ;
}
if ( F_75 ( V_88 ) ) {
if ( V_120 ) {
V_120 = F_76 ( V_120 , ( unsigned ) 3 ) ;
V_29 |= V_121 ;
V_29 |= V_120 << 8 ;
}
F_47 ( V_2 , L_12 , V_120 ) ;
}
if ( F_65 ( V_88 ) ) {
V_29 &= ~ ( 3 << 2 ) ;
V_29 |= ( V_99 << 2 ) ;
}
if ( F_77 ( V_88 ) ) {
F_47 ( V_2 , L_13 ) ;
V_2 -> V_122 = 1 ;
if ( V_123 > 0xf ) {
F_47 ( V_2 , L_14 ,
V_123 ) ;
V_123 = 0 ;
}
V_29 |= V_123 << 24 ;
}
V_2 -> V_33 = V_29 ;
if ( ! ( V_75 -> V_124 -> V_60 & V_125 ) )
V_75 -> V_126 . V_127 = ~ 0 ;
return 0 ;
}
static int F_78 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
T_2 V_29 ;
T_2 V_88 ;
V_75 -> V_128 = 1 ;
F_11 ( V_2 , V_2 -> V_129 , & V_2 -> V_26 -> V_130 ) ;
F_11 ( V_2 , ( T_2 ) V_2 -> V_68 -> V_105 , & V_2 -> V_26 -> V_131 ) ;
V_88 = F_7 ( V_2 , & V_2 -> V_93 -> V_88 ) ;
if ( F_79 ( V_88 ) ) {
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_132 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_33 &= ~ ( V_133 | V_35 | V_58 | V_57 | V_43 ) ;
V_2 -> V_33 |= V_34 ;
F_11 ( V_2 , V_2 -> V_33 , & V_2 -> V_26 -> V_33 ) ;
F_22 ( V_2 , L_15 , V_2 -> V_33 ) ;
F_80 ( & V_134 ) ;
V_2 -> V_38 = V_54 ;
F_11 ( V_2 , V_135 , & V_2 -> V_26 -> V_73 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_50 ( 5 ) ;
F_81 ( & V_134 ) ;
V_2 -> V_136 = F_82 () ;
V_29 = F_83 ( V_2 , F_7 ( V_2 , & V_2 -> V_93 -> V_137 ) ) ;
F_84 ( V_2 ,
L_16 ,
( ( V_2 -> V_138 & 0xf0 ) >> 4 ) , ( V_2 -> V_138 & 0x0f ) ,
V_29 >> 8 , V_29 & 0xff ,
V_139 ? L_17 : L_18 ) ;
F_11 ( V_2 , V_140 ,
& V_2 -> V_26 -> V_31 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static int T_3 F_87 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
int V_41 ;
V_2 -> V_26 = ( void T_1 * ) V_2 -> V_93 +
F_88 ( V_2 , F_7 ( V_2 , & V_2 -> V_93 -> V_137 ) ) ;
F_89 ( V_2 , L_2 ) ;
F_90 ( V_2 , L_2 ) ;
V_2 -> V_70 = F_7 ( V_2 , & V_2 -> V_93 -> V_70 ) ;
V_2 -> V_138 = V_141 ;
V_41 = F_10 ( V_2 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_61 ( V_75 ) ;
if ( V_41 )
return V_41 ;
F_20 ( V_2 ) ;
return 0 ;
}
static T_4 F_91 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
T_2 V_30 , V_142 , V_143 = 0 , V_64 ;
int V_144 ;
F_92 ( & V_2 -> V_61 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( V_30 == ~ ( T_2 ) 0 ) {
F_47 ( V_2 , L_19 ) ;
goto V_145;
}
V_142 = V_30 & ( V_140 | V_146 ) ;
if ( ! V_142 || F_93 ( V_2 -> V_38 == V_39 ) ) {
F_94 ( & V_2 -> V_61 ) ;
return V_147 ;
}
F_11 ( V_2 , V_142 , & V_2 -> V_26 -> V_30 ) ;
V_64 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_144 = 0 ;
#ifdef F_95
F_60 ( V_2 , L_20 , V_30 ) ;
#endif
if ( F_96 ( ( V_30 & ( V_148 | V_149 ) ) != 0 ) ) {
if ( F_96 ( ( V_30 & V_149 ) == 0 ) )
F_29 ( V_2 -> V_66 . V_85 ) ;
else
F_29 ( V_2 -> V_66 . error ) ;
V_144 = 1 ;
}
if ( V_30 & V_65 ) {
if ( V_64 & V_35 )
F_47 ( V_2 , L_21 ) ;
if ( V_2 -> V_62 ) {
F_29 ( V_2 -> V_66 . V_62 ) ;
F_31 ( V_2 ) ;
} else
F_47 ( V_2 , L_22 ) ;
}
if ( V_30 & V_150 ) {
unsigned V_151 = F_38 ( V_2 -> V_70 ) ;
T_2 V_152 = 0 ;
V_143 = V_30 ;
if ( V_2 -> V_38 == V_153 )
F_97 ( V_75 ) ;
if ( V_2 -> V_118 )
V_152 = V_30 >> 16 ;
while ( V_151 -- ) {
int V_154 ;
if ( V_2 -> V_118 && ! ( V_152 & ( 1 << V_151 ) ) )
continue;
V_154 = F_7 ( V_2 ,
& V_2 -> V_26 -> V_72 [ V_151 ] ) ;
if ( V_154 & V_155 )
continue;
if ( ! ( F_34 ( V_151 , & V_2 -> V_52 ) &&
( ( V_154 & V_156 ) ||
! ( V_154 & V_157 ) ) &&
( V_154 & V_158 ) &&
V_2 -> V_159 [ V_151 ] == 0 ) )
continue;
V_2 -> V_159 [ V_151 ] = V_15 + F_98 ( 25 ) ;
F_99 ( V_151 , & V_2 -> V_53 ) ;
F_47 ( V_2 , L_23 , V_151 + 1 ) ;
F_5 ( & V_75 -> V_160 , V_2 -> V_159 [ V_151 ] ) ;
}
}
if ( F_93 ( ( V_30 & V_161 ) != 0 ) ) {
F_17 ( V_2 , L_24 ) ;
F_22 ( V_2 , L_25 , V_64 ) ;
F_60 ( V_2 , L_25 , V_30 ) ;
F_10 ( V_2 ) ;
V_145:
F_20 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_73 ) ;
F_100 ( V_75 ) ;
V_144 = 1 ;
}
if ( V_144 )
F_36 ( V_2 ) ;
F_94 ( & V_2 -> V_61 ) ;
if ( V_143 )
F_101 ( V_75 ) ;
return V_162 ;
}
static int F_102 (
struct V_74 * V_75 ,
struct V_163 * V_163 ,
T_5 V_164
) {
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_165 V_166 ;
F_64 ( & V_166 ) ;
switch ( F_103 ( V_163 -> V_167 ) ) {
case V_168 :
if ( V_163 -> V_169 > ( 16 * 1024 ) )
return - V_170 ;
default:
if ( ! F_104 ( V_2 , V_163 , & V_166 , V_164 ) )
return - V_171 ;
return F_105 ( V_2 , V_163 , & V_166 , V_164 ) ;
case V_172 :
if ( ! F_104 ( V_2 , V_163 , & V_166 , V_164 ) )
return - V_171 ;
return F_106 ( V_2 , V_163 , & V_166 , V_164 ) ;
case V_173 :
if ( V_163 -> V_174 -> V_175 == V_176 )
return F_107 ( V_2 , V_163 , V_164 ) ;
else
return F_108 ( V_2 , V_163 , V_164 ) ;
}
}
static void F_109 ( struct V_1 * V_2 , struct V_177 * V_103 )
{
if ( V_2 -> V_38 != V_54 && V_2 -> V_62 )
F_31 ( V_2 ) ;
if ( V_103 -> V_112 != V_113 ) {
if ( V_103 -> V_112 == V_178 )
V_103 -> V_179 = 1 ;
return;
}
if ( V_2 -> V_62 ) {
struct V_177 * V_180 ;
for ( V_180 = V_2 -> V_62 ;
V_180 -> V_62 ;
V_180 = V_180 -> V_62 )
continue;
V_103 -> V_112 = V_181 ;
V_180 -> V_62 = V_103 ;
} else
F_35 ( V_2 , V_103 ) ;
}
static int F_110 ( struct V_74 * V_75 , struct V_163 * V_163 , int V_30 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_177 * V_103 ;
unsigned long V_60 ;
int V_182 ;
F_28 ( & V_2 -> V_61 , V_60 ) ;
V_182 = F_111 ( V_75 , V_163 , V_30 ) ;
if ( V_182 )
goto V_18;
switch ( F_103 ( V_163 -> V_167 ) ) {
default:
V_103 = (struct V_177 * ) V_163 -> V_183 ;
if ( ! V_103 )
break;
switch ( V_103 -> V_112 ) {
case V_113 :
case V_178 :
F_109 ( V_2 , V_103 ) ;
break;
case V_184 :
case V_181 :
break;
case V_185 :
F_112 ( V_2 , V_103 ) ;
break;
}
break;
case V_172 :
V_103 = (struct V_177 * ) V_163 -> V_183 ;
if ( ! V_103 )
break;
switch ( V_103 -> V_112 ) {
case V_113 :
case V_178 :
F_113 ( V_2 , V_103 ) ;
break;
case V_185 :
F_112 ( V_2 , V_103 ) ;
break;
default:
F_47 ( V_2 , L_26 ,
V_103 , V_103 -> V_112 ) ;
goto V_18;
}
break;
case V_173 :
break;
}
V_18:
F_32 ( & V_2 -> V_61 , V_60 ) ;
return V_182 ;
}
static void
F_114 ( struct V_74 * V_75 , struct V_186 * V_187 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
unsigned long V_60 ;
struct V_177 * V_103 , * V_24 ;
V_188:
F_28 ( & V_2 -> V_61 , V_60 ) ;
V_103 = V_187 -> V_183 ;
if ( ! V_103 )
goto V_18;
if ( V_103 -> V_90 == NULL ) {
F_30 ( V_2 , L_27 ) ;
goto V_189;
}
if ( V_2 -> V_38 != V_54 )
V_103 -> V_112 = V_185 ;
switch ( V_103 -> V_112 ) {
case V_113 :
case V_178 :
for ( V_24 = V_2 -> V_68 -> V_82 . V_103 ;
V_24 && V_24 != V_103 ;
V_24 = V_24 -> V_82 . V_103 )
continue;
if ( V_24 )
F_109 ( V_2 , V_103 ) ;
case V_184 :
case V_181 :
V_189:
F_32 ( & V_2 -> V_61 , V_60 ) ;
F_115 ( 1 ) ;
goto V_188;
case V_185 :
if ( V_103 -> V_190 )
goto V_189;
if ( F_116 ( & V_103 -> V_166 ) ) {
F_117 ( V_103 ) ;
break;
}
default:
F_17 ( V_2 , L_28 ,
V_103 , V_187 -> V_191 . V_192 , V_103 -> V_112 ,
F_116 ( & V_103 -> V_166 ) ? L_18 : L_29 ) ;
break;
}
V_187 -> V_183 = NULL ;
V_18:
F_32 ( & V_2 -> V_61 , V_60 ) ;
}
static void
F_118 ( struct V_74 * V_75 , struct V_186 * V_187 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_177 * V_103 ;
int V_193 = F_119 ( & V_187 -> V_191 ) ;
int V_194 = F_120 ( & V_187 -> V_191 ) ;
int V_195 = F_121 ( & V_187 -> V_191 ) ;
unsigned long V_60 ;
if ( V_193 != V_196 && V_193 != V_197 )
return;
F_28 ( & V_2 -> V_61 , V_60 ) ;
V_103 = V_187 -> V_183 ;
if ( V_103 ) {
F_122 ( V_103 -> V_174 , V_194 , V_195 , 0 ) ;
if ( ! F_116 ( & V_103 -> V_166 ) ) {
F_123 ( 1 , L_30 ) ;
} else if ( V_103 -> V_112 == V_113 ||
V_103 -> V_112 == V_178 ) {
if ( V_193 == V_196 )
F_109 ( V_2 , V_103 ) ;
else
F_113 ( V_2 , V_103 ) ;
}
}
F_32 ( & V_2 -> V_61 , V_60 ) ;
}
static int F_124 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
return ( F_15 ( V_2 ) >> 3 ) % V_2 -> V_95 ;
}
static int T_6 F_125 ( void )
{
int V_41 = 0 ;
if ( F_126 () )
return - V_21 ;
F_127 ( V_198 L_31 V_199 L_32 , V_200 ) ;
F_99 ( V_201 , & V_202 ) ;
if ( F_34 ( V_203 , & V_202 ) ||
F_34 ( V_204 , & V_202 ) )
F_127 ( V_205 L_33
L_34 ) ;
F_128 ( L_35 ,
V_200 ,
sizeof( struct V_177 ) , sizeof( struct V_206 ) ,
sizeof( struct V_207 ) , sizeof( struct V_208 ) ) ;
#ifdef F_25
V_209 = F_129 ( L_36 , V_210 ) ;
if ( ! V_209 ) {
V_41 = - V_211 ;
goto V_212;
}
#endif
#ifdef F_130
V_41 = F_131 ( & F_130 ) ;
if ( V_41 < 0 )
goto V_213;
#endif
#ifdef F_132
V_41 = F_133 ( & F_132 ) ;
if ( V_41 < 0 )
goto V_214;
#endif
#ifdef F_134
V_41 = F_135 ( & F_134 ) ;
if ( V_41 < 0 )
goto V_215;
#endif
#ifdef F_136
V_41 = F_131 ( & F_136 ) ;
if ( V_41 < 0 )
goto V_216;
#endif
#ifdef F_137
V_41 = F_131 ( & F_137 ) ;
if ( V_41 < 0 )
goto V_217;
#endif
return V_41 ;
#ifdef F_137
V_217:
#endif
#ifdef F_136
F_138 ( & F_136 ) ;
V_216:
#endif
#ifdef F_134
F_139 ( & F_134 ) ;
V_215:
#endif
#ifdef F_132
F_140 ( & F_132 ) ;
V_214:
#endif
#ifdef F_130
F_138 ( & F_130 ) ;
V_213:
#endif
#ifdef F_25
F_141 ( V_209 ) ;
V_209 = NULL ;
V_212:
#endif
F_142 ( V_201 , & V_202 ) ;
return V_41 ;
}
static void T_7 F_143 ( void )
{
#ifdef F_137
F_138 ( & F_137 ) ;
#endif
#ifdef F_136
F_138 ( & F_136 ) ;
#endif
#ifdef F_130
F_138 ( & F_130 ) ;
#endif
#ifdef F_132
F_140 ( & F_132 ) ;
#endif
#ifdef F_134
F_139 ( & F_134 ) ;
#endif
#ifdef F_25
F_141 ( V_209 ) ;
#endif
F_142 ( V_201 , & V_202 ) ;
}
