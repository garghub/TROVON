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
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_29 &= ~ V_34 ;
F_11 ( V_2 , V_29 , & V_2 -> V_26 -> V_33 ) ;
return F_6 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_32 , V_32 , 16 * 125 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
void T_1 * V_16 , T_2 V_17 , T_2 V_18 ,
int V_19 )
{
unsigned int V_35 ;
int error ;
if ( ! F_14 ( V_36 ) )
return - V_22 ;
V_35 = F_15 ( V_2 ) ;
error = F_6 ( V_2 , V_16 , V_17 , V_18 , V_19 ) ;
if ( error == - V_22 && F_15 ( V_2 ) == V_35 )
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
V_2 -> V_37 = V_38 ;
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
V_24 |= V_39 ;
F_11 ( V_2 , V_24 , V_23 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_40 ;
T_2 V_33 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_2 -> V_41 && ! F_21 () )
V_2 -> V_41 = NULL ;
V_33 |= V_42 ;
F_22 ( V_2 , L_2 , V_33 ) ;
F_11 ( V_2 , V_33 , & V_2 -> V_26 -> V_33 ) ;
V_2 -> V_37 = V_38 ;
V_2 -> V_43 = V_15 ;
V_40 = F_6 ( V_2 , & V_2 -> V_26 -> V_33 ,
V_42 , 0 , 250 * 1000 ) ;
if ( V_2 -> V_44 ) {
F_11 ( V_2 , V_45 | V_46 ,
( T_2 T_1 * ) ( ( ( V_25 * ) V_2 -> V_26 ) + V_47 ) ) ;
F_11 ( V_2 , V_48 ,
( T_2 T_1 * ) ( ( ( V_25 * ) V_2 -> V_26 ) + V_49 ) ) ;
}
if ( V_40 )
return V_40 ;
if ( F_12 ( V_2 ) )
F_18 ( V_2 ) ;
if ( V_2 -> V_41 )
F_23 () ;
V_2 -> V_50 = V_2 -> V_51 =
V_2 -> V_52 = 0 ;
return V_40 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_29 ;
#ifdef F_25
if ( V_2 -> V_37 != V_53 )
F_26 () ;
#endif
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) << 10 ;
V_29 &= V_54 | V_55 ;
if ( F_16 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_54 | V_55 , V_29 , 16 * 125 ) )
return;
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_29 &= ~ ( V_56 | V_57 | V_58 ) ;
F_11 ( V_2 , V_29 , & V_2 -> V_26 -> V_33 ) ;
F_16 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_54 | V_55 , 0 , 16 * 125 ) ;
}
static void F_27 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
unsigned long V_60 ;
F_28 ( & V_2 -> V_61 , V_60 ) ;
if ( V_2 -> V_62
&& ! F_2 ( & V_2 -> V_63 )
&& V_2 -> V_37 == V_53 ) {
T_2 V_64 , V_30 ;
V_64 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_64 & V_57 )
F_11 ( V_2 , V_64 & ~ V_57 ,
& V_2 -> V_26 -> V_33 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( ( V_30 & V_65 ) || ! ( V_64 & V_57 ) ) {
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
if ( V_2 -> V_37 == V_53 &&
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
if ( V_2 -> V_37 == V_53 )
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
int V_40 ;
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
if ( ( V_40 = F_66 ( V_2 , V_100 ) ) < 0 )
return V_40 ;
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
V_90 -> V_106 |= F_70 ( V_2 , ( 1 << 7 ) ) ;
V_90 -> V_108 = F_70 ( V_2 , V_109 ) ;
V_90 -> V_110 = F_71 ( V_2 ) ;
V_2 -> V_68 -> V_111 = V_112 ;
V_90 -> V_113 = F_72 ( V_2 , V_2 -> V_68 -> V_114 -> V_115 ) ;
if ( V_116 < 0 || V_116 > 6 )
V_116 = 0 ;
V_29 = 1 << ( 16 + V_116 ) ;
if ( F_73 ( V_88 ) ) {
V_2 -> V_117 = 1 ;
F_47 ( V_2 , L_11 ) ;
V_29 |= V_118 ;
}
if ( F_74 ( V_88 ) ) {
if ( V_119 ) {
V_119 = F_75 ( V_119 , ( unsigned ) 3 ) ;
V_29 |= V_120 ;
V_29 |= V_119 << 8 ;
}
F_47 ( V_2 , L_12 , V_119 ) ;
}
if ( F_65 ( V_88 ) ) {
V_29 &= ~ ( 3 << 2 ) ;
V_29 |= ( V_99 << 2 ) ;
}
if ( F_76 ( V_88 ) ) {
F_47 ( V_2 , L_13 ) ;
V_2 -> V_121 = 1 ;
if ( V_122 > 0xf ) {
F_47 ( V_2 , L_14 ,
V_122 ) ;
V_122 = 0 ;
}
V_29 |= V_122 << 24 ;
}
V_2 -> V_33 = V_29 ;
if ( ! ( V_75 -> V_123 -> V_60 & V_124 ) )
V_75 -> V_125 . V_126 = ~ 0 ;
return 0 ;
}
static int F_77 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
T_2 V_29 ;
T_2 V_88 ;
V_75 -> V_127 = 1 ;
F_11 ( V_2 , V_2 -> V_128 , & V_2 -> V_26 -> V_129 ) ;
F_11 ( V_2 , ( T_2 ) V_2 -> V_68 -> V_105 , & V_2 -> V_26 -> V_130 ) ;
V_88 = F_7 ( V_2 , & V_2 -> V_93 -> V_88 ) ;
if ( F_78 ( V_88 ) ) {
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_131 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_33 &= ~ ( V_132 | V_57 | V_58 | V_56 | V_42 ) ;
V_2 -> V_33 |= V_34 ;
F_11 ( V_2 , V_2 -> V_33 , & V_2 -> V_26 -> V_33 ) ;
F_22 ( V_2 , L_15 , V_2 -> V_33 ) ;
F_79 ( & V_133 ) ;
V_2 -> V_37 = V_53 ;
F_11 ( V_2 , V_134 , & V_2 -> V_26 -> V_73 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_50 ( 5 ) ;
F_80 ( & V_133 ) ;
V_2 -> V_135 = F_81 () ;
V_29 = F_82 ( V_2 , F_7 ( V_2 , & V_2 -> V_93 -> V_136 ) ) ;
F_83 ( V_2 ,
L_16 ,
( ( V_2 -> V_137 & 0xf0 ) >> 4 ) , ( V_2 -> V_137 & 0x0f ) ,
V_29 >> 8 , V_29 & 0xff ,
V_138 ? L_17 : L_18 ) ;
F_11 ( V_2 , V_139 ,
& V_2 -> V_26 -> V_31 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int T_3 F_86 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
int V_40 ;
V_2 -> V_26 = ( void T_1 * ) V_2 -> V_93 +
F_87 ( V_2 , F_7 ( V_2 , & V_2 -> V_93 -> V_136 ) ) ;
F_88 ( V_2 , L_2 ) ;
F_89 ( V_2 , L_2 ) ;
V_2 -> V_70 = F_7 ( V_2 , & V_2 -> V_93 -> V_70 ) ;
V_2 -> V_137 = V_140 ;
V_40 = F_10 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_61 ( V_75 ) ;
if ( V_40 )
return V_40 ;
F_20 ( V_2 ) ;
return 0 ;
}
static T_4 F_90 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
T_2 V_30 , V_141 , V_142 = 0 , V_64 ;
int V_143 ;
F_91 ( & V_2 -> V_61 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( V_30 == ~ ( T_2 ) 0 ) {
F_47 ( V_2 , L_19 ) ;
goto V_144;
}
V_141 = V_30 & ( V_139 | V_145 ) ;
if ( ! V_141 || F_92 ( V_2 -> V_37 == V_38 ) ) {
F_93 ( & V_2 -> V_61 ) ;
return V_146 ;
}
F_11 ( V_2 , V_141 , & V_2 -> V_26 -> V_30 ) ;
V_64 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_143 = 0 ;
#ifdef F_94
F_60 ( V_2 , L_20 , V_30 ) ;
#endif
if ( F_95 ( ( V_30 & ( V_147 | V_148 ) ) != 0 ) ) {
if ( F_95 ( ( V_30 & V_148 ) == 0 ) )
F_29 ( V_2 -> V_66 . V_85 ) ;
else
F_29 ( V_2 -> V_66 . error ) ;
V_143 = 1 ;
}
if ( V_30 & V_65 ) {
if ( V_64 & V_57 ) {
F_11 ( V_2 , V_64 & ~ V_57 ,
& V_2 -> V_26 -> V_33 ) ;
F_47 ( V_2 , L_21 ) ;
}
if ( V_2 -> V_62 ) {
F_29 ( V_2 -> V_66 . V_62 ) ;
F_31 ( V_2 ) ;
} else
F_47 ( V_2 , L_22 ) ;
}
if ( V_30 & V_149 ) {
unsigned V_150 = F_38 ( V_2 -> V_70 ) ;
T_2 V_151 = 0 ;
V_142 = V_30 ;
if ( V_2 -> V_37 == V_152 )
F_96 ( V_75 ) ;
if ( V_2 -> V_117 )
V_151 = V_30 >> 16 ;
while ( V_150 -- ) {
int V_153 ;
if ( V_2 -> V_117 && ! ( V_151 & ( 1 << V_150 ) ) )
continue;
V_153 = F_7 ( V_2 ,
& V_2 -> V_26 -> V_72 [ V_150 ] ) ;
if ( V_153 & V_154 )
continue;
if ( ! ( F_34 ( V_150 , & V_2 -> V_51 ) &&
( ( V_153 & V_155 ) ||
! ( V_153 & V_156 ) ) &&
( V_153 & V_157 ) &&
V_2 -> V_158 [ V_150 ] == 0 ) )
continue;
V_2 -> V_158 [ V_150 ] = V_15 + F_97 ( 25 ) ;
F_98 ( V_150 , & V_2 -> V_52 ) ;
F_47 ( V_2 , L_23 , V_150 + 1 ) ;
F_5 ( & V_75 -> V_159 , V_2 -> V_158 [ V_150 ] ) ;
}
}
if ( F_92 ( ( V_30 & V_160 ) != 0 ) ) {
F_17 ( V_2 , L_24 ) ;
F_22 ( V_2 , L_25 , V_64 ) ;
F_60 ( V_2 , L_25 , V_30 ) ;
F_10 ( V_2 ) ;
V_144:
F_20 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_73 ) ;
F_99 ( V_75 ) ;
V_143 = 1 ;
}
if ( V_143 )
F_36 ( V_2 ) ;
F_93 ( & V_2 -> V_61 ) ;
if ( V_142 )
F_100 ( V_75 ) ;
return V_161 ;
}
static int F_101 (
struct V_74 * V_75 ,
struct V_162 * V_162 ,
T_5 V_163
) {
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_164 V_165 ;
F_64 ( & V_165 ) ;
switch ( F_102 ( V_162 -> V_166 ) ) {
case V_167 :
if ( V_162 -> V_168 > ( 16 * 1024 ) )
return - V_169 ;
default:
if ( ! F_103 ( V_2 , V_162 , & V_165 , V_163 ) )
return - V_170 ;
return F_104 ( V_2 , V_162 , & V_165 , V_163 ) ;
case V_171 :
if ( ! F_103 ( V_2 , V_162 , & V_165 , V_163 ) )
return - V_170 ;
return F_105 ( V_2 , V_162 , & V_165 , V_163 ) ;
case V_172 :
if ( V_162 -> V_173 -> V_174 == V_175 )
return F_106 ( V_2 , V_162 , V_163 ) ;
else
return F_107 ( V_2 , V_162 , V_163 ) ;
}
}
static void F_108 ( struct V_1 * V_2 , struct V_176 * V_103 )
{
if ( V_2 -> V_37 != V_53 && V_2 -> V_62 )
F_31 ( V_2 ) ;
if ( V_103 -> V_111 != V_112 ) {
if ( V_103 -> V_111 == V_177 )
V_103 -> V_178 = 1 ;
return;
}
if ( V_2 -> V_62 ) {
struct V_176 * V_179 ;
for ( V_179 = V_2 -> V_62 ;
V_179 -> V_62 ;
V_179 = V_179 -> V_62 )
continue;
V_103 -> V_111 = V_180 ;
V_179 -> V_62 = V_103 ;
} else
F_35 ( V_2 , V_103 ) ;
}
static int F_109 ( struct V_74 * V_75 , struct V_162 * V_162 , int V_30 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_176 * V_103 ;
unsigned long V_60 ;
int V_181 ;
F_28 ( & V_2 -> V_61 , V_60 ) ;
V_181 = F_110 ( V_75 , V_162 , V_30 ) ;
if ( V_181 )
goto V_18;
switch ( F_102 ( V_162 -> V_166 ) ) {
default:
V_103 = (struct V_176 * ) V_162 -> V_182 ;
if ( ! V_103 )
break;
switch ( V_103 -> V_111 ) {
case V_112 :
case V_177 :
F_108 ( V_2 , V_103 ) ;
break;
case V_183 :
case V_180 :
break;
case V_184 :
F_111 ( V_2 , V_103 ) ;
break;
}
break;
case V_171 :
V_103 = (struct V_176 * ) V_162 -> V_182 ;
if ( ! V_103 )
break;
switch ( V_103 -> V_111 ) {
case V_112 :
case V_177 :
F_112 ( V_2 , V_103 ) ;
break;
case V_184 :
F_111 ( V_2 , V_103 ) ;
break;
default:
F_47 ( V_2 , L_26 ,
V_103 , V_103 -> V_111 ) ;
goto V_18;
}
break;
case V_172 :
break;
}
V_18:
F_32 ( & V_2 -> V_61 , V_60 ) ;
return V_181 ;
}
static void
F_113 ( struct V_74 * V_75 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
unsigned long V_60 ;
struct V_176 * V_103 , * V_24 ;
V_187:
F_28 ( & V_2 -> V_61 , V_60 ) ;
V_103 = V_186 -> V_182 ;
if ( ! V_103 )
goto V_18;
if ( V_103 -> V_90 == NULL ) {
F_30 ( V_2 , L_27 ) ;
goto V_188;
}
if ( V_2 -> V_37 != V_53 )
V_103 -> V_111 = V_184 ;
switch ( V_103 -> V_111 ) {
case V_112 :
case V_177 :
for ( V_24 = V_2 -> V_68 -> V_82 . V_103 ;
V_24 && V_24 != V_103 ;
V_24 = V_24 -> V_82 . V_103 )
continue;
if ( V_24 )
F_108 ( V_2 , V_103 ) ;
case V_183 :
case V_180 :
V_188:
F_32 ( & V_2 -> V_61 , V_60 ) ;
F_114 ( 1 ) ;
goto V_187;
case V_184 :
if ( V_103 -> V_189 )
goto V_188;
if ( F_115 ( & V_103 -> V_165 ) ) {
F_116 ( V_103 ) ;
break;
}
default:
F_17 ( V_2 , L_28 ,
V_103 , V_186 -> V_190 . V_191 , V_103 -> V_111 ,
F_115 ( & V_103 -> V_165 ) ? L_18 : L_29 ) ;
break;
}
V_186 -> V_182 = NULL ;
V_18:
F_32 ( & V_2 -> V_61 , V_60 ) ;
}
static void
F_117 ( struct V_74 * V_75 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_176 * V_103 ;
int V_192 = F_118 ( & V_186 -> V_190 ) ;
int V_193 = F_119 ( & V_186 -> V_190 ) ;
int V_194 = F_120 ( & V_186 -> V_190 ) ;
unsigned long V_60 ;
if ( V_192 != V_195 && V_192 != V_196 )
return;
F_28 ( & V_2 -> V_61 , V_60 ) ;
V_103 = V_186 -> V_182 ;
if ( V_103 ) {
F_121 ( V_103 -> V_173 , V_193 , V_194 , 0 ) ;
if ( ! F_115 ( & V_103 -> V_165 ) ) {
F_122 ( 1 , L_30 ) ;
} else if ( V_103 -> V_111 == V_112 ||
V_103 -> V_111 == V_177 ) {
if ( V_192 == V_195 )
F_108 ( V_2 , V_103 ) ;
else
F_112 ( V_2 , V_103 ) ;
}
}
F_32 ( & V_2 -> V_61 , V_60 ) ;
}
static int F_123 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
return ( F_15 ( V_2 ) >> 3 ) % V_2 -> V_95 ;
}
static int T_6 F_124 ( void )
{
int V_40 = 0 ;
if ( F_125 () )
return - V_21 ;
F_126 ( V_197 L_31 V_198 L_32 , V_199 ) ;
F_98 ( V_200 , & V_201 ) ;
if ( F_34 ( V_202 , & V_201 ) ||
F_34 ( V_203 , & V_201 ) )
F_126 ( V_204 L_33
L_34 ) ;
F_127 ( L_35 ,
V_199 ,
sizeof( struct V_176 ) , sizeof( struct V_205 ) ,
sizeof( struct V_206 ) , sizeof( struct V_207 ) ) ;
#ifdef F_25
V_208 = F_128 ( L_36 , V_209 ) ;
if ( ! V_208 ) {
V_40 = - V_210 ;
goto V_211;
}
#endif
#ifdef F_129
V_40 = F_130 ( & F_129 ) ;
if ( V_40 < 0 )
goto V_212;
#endif
#ifdef F_131
V_40 = F_132 ( & F_131 ) ;
if ( V_40 < 0 )
goto V_213;
#endif
#ifdef F_133
V_40 = F_134 ( & F_133 ) ;
if ( V_40 < 0 )
goto V_214;
#endif
#ifdef F_135
V_40 = F_130 ( & F_135 ) ;
if ( V_40 < 0 )
goto V_215;
#endif
#ifdef F_136
V_40 = F_130 ( & F_136 ) ;
if ( V_40 < 0 )
goto V_216;
#endif
return V_40 ;
#ifdef F_136
V_216:
#endif
#ifdef F_135
F_137 ( & F_135 ) ;
V_215:
#endif
#ifdef F_133
F_138 ( & F_133 ) ;
V_214:
#endif
#ifdef F_131
F_139 ( & F_131 ) ;
V_213:
#endif
#ifdef F_129
F_137 ( & F_129 ) ;
V_212:
#endif
#ifdef F_25
F_140 ( V_208 ) ;
V_208 = NULL ;
V_211:
#endif
F_141 ( V_200 , & V_201 ) ;
return V_40 ;
}
static void T_7 F_142 ( void )
{
#ifdef F_136
F_137 ( & F_136 ) ;
#endif
#ifdef F_135
F_137 ( & F_135 ) ;
#endif
#ifdef F_129
F_137 ( & F_129 ) ;
#endif
#ifdef F_131
F_139 ( & F_131 ) ;
#endif
#ifdef F_133
F_138 ( & F_133 ) ;
#endif
#ifdef F_25
F_140 ( V_208 ) ;
#endif
F_141 ( V_200 , & V_201 ) ;
}
