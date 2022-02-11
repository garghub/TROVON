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
return V_40 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_29 ;
#ifdef F_25
if ( V_2 -> V_37 != V_50 )
F_26 () ;
#endif
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) << 10 ;
V_29 &= V_51 | V_52 ;
if ( F_16 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_51 | V_52 , V_29 , 16 * 125 ) )
return;
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_29 &= ~ ( V_53 | V_54 | V_55 ) ;
F_11 ( V_2 , V_29 , & V_2 -> V_26 -> V_33 ) ;
F_16 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_51 | V_52 , 0 , 16 * 125 ) ;
}
static void F_27 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_57 ;
F_28 ( & V_2 -> V_58 , V_57 ) ;
if ( V_2 -> V_59
&& ! F_2 ( & V_2 -> V_60 )
&& V_2 -> V_37 == V_50 ) {
T_2 V_61 , V_30 ;
V_61 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_61 & V_54 )
F_11 ( V_2 , V_61 & ~ V_54 ,
& V_2 -> V_26 -> V_33 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( ( V_30 & V_62 ) || ! ( V_61 & V_54 ) ) {
F_29 ( V_2 -> V_63 . V_64 ) ;
F_11 ( V_2 , V_62 , & V_2 -> V_26 -> V_30 ) ;
}
F_30 ( V_2 , L_3 ,
V_30 , V_61 ) ;
F_31 ( V_2 ) ;
}
F_32 ( & V_2 -> V_58 , V_57 ) ;
}
static void F_33 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_57 ;
F_28 ( & V_2 -> V_58 , V_57 ) ;
if ( F_34 ( V_7 , & V_2 -> V_8 ) )
F_35 ( V_2 , V_2 -> V_65 ) ;
F_36 ( V_2 ) ;
F_32 ( & V_2 -> V_58 , V_57 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_66 = F_38 ( V_2 -> V_67 ) ;
while ( V_66 -- )
F_11 ( V_2 , V_68 ,
& V_2 -> V_26 -> V_69 [ V_66 ] ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_37 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_70 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_70 ) ;
}
static void F_40 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
F_42 ( & V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_60 ) ;
F_43 ( & V_2 -> V_58 ) ;
F_39 ( V_2 ) ;
F_44 ( & V_2 -> V_58 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_73 )
{
unsigned V_66 ;
if ( ! F_46 ( V_2 -> V_67 ) )
return;
F_47 ( V_2 , L_4 , V_73 ? L_5 : L_6 ) ;
for ( V_66 = F_38 ( V_2 -> V_67 ) ; V_66 > 0 ; )
( void ) F_48 ( F_49 ( V_2 ) ,
V_73 ? V_74 : V_75 ,
V_76 ,
V_66 -- , NULL , 0 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_50 ( 20 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_10 ) ;
if ( V_2 -> V_77 )
return;
V_2 -> V_77 = 1 ;
F_52 ( V_2 ) ;
if ( V_2 -> V_78 != - 1 )
F_53 ( V_2 ) ;
V_2 -> V_77 = 0 ;
if ( V_2 -> V_37 == V_50 &&
( V_2 -> V_65 -> V_79 . V_16 != NULL ||
V_2 -> V_80 != 0 ) )
F_1 ( V_2 , V_10 ) ;
}
static void F_54 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
F_47 ( V_2 , L_7 ) ;
F_42 ( & V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_60 ) ;
F_43 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_37 == V_50 )
F_24 ( V_2 ) ;
F_39 ( V_2 ) ;
F_20 ( V_2 ) ;
F_44 ( & V_2 -> V_58 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_43 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_65 )
F_36 ( V_2 ) ;
F_44 ( & V_2 -> V_58 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> V_81 == 1 )
F_58 () ;
#ifdef F_59
F_47 ( V_2 , L_8 ,
V_2 -> V_63 . V_82 , V_2 -> V_63 . error , V_2 -> V_63 . V_59 ,
V_2 -> V_63 . V_64 ) ;
F_47 ( V_2 , L_9 ,
V_2 -> V_63 . V_83 , V_2 -> V_63 . V_84 ) ;
#endif
F_60 ( V_2 , L_10 ,
F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ) ;
}
static int F_61 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
T_2 V_29 ;
int V_40 ;
T_2 V_85 ;
struct V_86 * V_87 ;
F_62 ( & V_2 -> V_58 ) ;
V_2 -> V_11 = 1 ;
F_63 ( & V_2 -> V_5 ) ;
V_2 -> V_5 . V_88 = F_33 ;
V_2 -> V_5 . V_89 = ( unsigned long ) V_2 ;
F_63 ( & V_2 -> V_60 ) ;
V_2 -> V_60 . V_88 = F_27 ;
V_2 -> V_60 . V_89 = ( unsigned long ) V_2 ;
V_85 = F_7 ( V_2 , & V_2 -> V_90 -> V_85 ) ;
V_2 -> V_91 = 100 ;
V_2 -> V_92 = V_93 ;
F_64 ( & V_2 -> V_94 ) ;
F_64 ( & V_2 -> V_95 ) ;
if ( F_65 ( V_85 ) ) {
switch ( V_96 ) {
case 0 : V_2 -> V_92 = 1024 ; break;
case 1 : V_2 -> V_92 = 512 ; break;
case 2 : V_2 -> V_92 = 256 ; break;
default: F_26 () ;
}
}
if ( ( V_40 = F_66 ( V_2 , V_97 ) ) < 0 )
return V_40 ;
if ( F_67 ( V_85 ) )
V_2 -> V_98 = 2 + 8 ;
else
V_2 -> V_98 = 2 + F_68 ( V_85 ) ;
V_2 -> V_59 = NULL ;
V_2 -> V_78 = - 1 ;
V_2 -> V_99 = - 1 ;
V_2 -> V_65 -> V_79 . V_100 = NULL ;
V_87 = V_2 -> V_65 -> V_87 ;
V_87 -> V_101 = F_69 ( V_2 , V_2 -> V_65 -> V_102 ) ;
V_87 -> V_103 = F_70 ( V_2 , V_104 ) ;
V_87 -> V_103 |= F_70 ( V_2 , ( 1 << 7 ) ) ;
V_87 -> V_105 = F_70 ( V_2 , V_106 ) ;
V_87 -> V_107 = F_71 ( V_2 ) ;
V_2 -> V_65 -> V_108 = V_109 ;
V_87 -> V_110 = F_72 ( V_2 , V_2 -> V_65 -> V_111 -> V_112 ) ;
if ( V_113 < 0 || V_113 > 6 )
V_113 = 0 ;
V_29 = 1 << ( 16 + V_113 ) ;
if ( F_73 ( V_85 ) ) {
V_2 -> V_114 = 1 ;
F_47 ( V_2 , L_11 ) ;
V_29 |= V_115 ;
}
if ( F_74 ( V_85 ) ) {
if ( V_116 ) {
V_116 = F_75 ( V_116 , ( unsigned ) 3 ) ;
V_29 |= V_117 ;
V_29 |= V_116 << 8 ;
}
F_47 ( V_2 , L_12 , V_116 ) ;
}
if ( F_65 ( V_85 ) ) {
V_29 &= ~ ( 3 << 2 ) ;
V_29 |= ( V_96 << 2 ) ;
}
if ( F_76 ( V_85 ) ) {
F_47 ( V_2 , L_13 ) ;
V_2 -> V_118 = 1 ;
if ( V_119 > 0xf ) {
F_47 ( V_2 , L_14 ,
V_119 ) ;
V_119 = 0 ;
}
V_29 |= V_119 << 24 ;
}
V_2 -> V_33 = V_29 ;
if ( ! ( V_72 -> V_120 -> V_57 & V_121 ) )
V_72 -> V_122 . V_123 = ~ 0 ;
return 0 ;
}
static int F_77 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
T_2 V_29 ;
T_2 V_85 ;
V_72 -> V_124 = 1 ;
F_11 ( V_2 , V_2 -> V_125 , & V_2 -> V_26 -> V_126 ) ;
F_11 ( V_2 , ( T_2 ) V_2 -> V_65 -> V_102 , & V_2 -> V_26 -> V_127 ) ;
V_85 = F_7 ( V_2 , & V_2 -> V_90 -> V_85 ) ;
if ( F_78 ( V_85 ) ) {
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_128 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_33 &= ~ ( V_129 | V_54 | V_55 | V_53 | V_42 ) ;
V_2 -> V_33 |= V_34 ;
F_11 ( V_2 , V_2 -> V_33 , & V_2 -> V_26 -> V_33 ) ;
F_22 ( V_2 , L_15 , V_2 -> V_33 ) ;
F_79 ( & V_130 ) ;
V_2 -> V_37 = V_50 ;
F_11 ( V_2 , V_131 , & V_2 -> V_26 -> V_70 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_50 ( 5 ) ;
F_80 ( & V_130 ) ;
V_2 -> V_132 = F_81 () ;
V_29 = F_82 ( V_2 , F_7 ( V_2 , & V_2 -> V_90 -> V_133 ) ) ;
F_83 ( V_2 ,
L_16 ,
( ( V_2 -> V_134 & 0xf0 ) >> 4 ) , ( V_2 -> V_134 & 0x0f ) ,
V_29 >> 8 , V_29 & 0xff ,
V_135 ? L_17 : L_18 ) ;
F_11 ( V_2 , V_136 ,
& V_2 -> V_26 -> V_31 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int T_3 F_86 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
int V_40 ;
V_2 -> V_26 = ( void T_1 * ) V_2 -> V_90 +
F_87 ( V_2 , F_7 ( V_2 , & V_2 -> V_90 -> V_133 ) ) ;
F_88 ( V_2 , L_2 ) ;
F_89 ( V_2 , L_2 ) ;
V_2 -> V_67 = F_7 ( V_2 , & V_2 -> V_90 -> V_67 ) ;
V_2 -> V_134 = V_137 ;
V_40 = F_10 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_61 ( V_72 ) ;
if ( V_40 )
return V_40 ;
F_20 ( V_2 ) ;
return 0 ;
}
static T_4 F_90 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
T_2 V_30 , V_138 , V_139 = 0 , V_61 ;
int V_140 ;
F_91 ( & V_2 -> V_58 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( V_30 == ~ ( T_2 ) 0 ) {
F_47 ( V_2 , L_19 ) ;
goto V_141;
}
V_138 = V_30 & V_136 ;
if ( ! V_138 || F_92 ( V_2 -> V_37 == V_38 ) ) {
F_93 ( & V_2 -> V_58 ) ;
return V_142 ;
}
F_11 ( V_2 , V_138 , & V_2 -> V_26 -> V_30 ) ;
V_61 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_140 = 0 ;
#ifdef F_94
F_60 ( V_2 , L_20 , V_30 ) ;
#endif
if ( F_95 ( ( V_30 & ( V_143 | V_144 ) ) != 0 ) ) {
if ( F_95 ( ( V_30 & V_144 ) == 0 ) )
F_29 ( V_2 -> V_63 . V_82 ) ;
else
F_29 ( V_2 -> V_63 . error ) ;
V_140 = 1 ;
}
if ( V_30 & V_62 ) {
if ( V_61 & V_54 ) {
F_11 ( V_2 , V_61 & ~ V_54 ,
& V_2 -> V_26 -> V_33 ) ;
F_47 ( V_2 , L_21 ) ;
}
if ( V_2 -> V_59 ) {
F_29 ( V_2 -> V_63 . V_59 ) ;
F_31 ( V_2 ) ;
} else
F_47 ( V_2 , L_22 ) ;
}
if ( V_30 & V_145 ) {
unsigned V_146 = F_38 ( V_2 -> V_67 ) ;
T_2 V_147 = 0 ;
V_139 = V_30 ;
if ( ! ( V_61 & V_34 ) )
F_96 ( V_72 ) ;
if ( V_2 -> V_114 )
V_147 = V_30 >> 16 ;
while ( V_146 -- ) {
int V_148 ;
if ( V_2 -> V_114 && ! ( V_147 & ( 1 << V_146 ) ) )
continue;
V_148 = F_7 ( V_2 ,
& V_2 -> V_26 -> V_69 [ V_146 ] ) ;
if ( V_148 & V_149 )
continue;
if ( ! ( F_34 ( V_146 , & V_2 -> V_150 ) &&
( ( V_148 & V_151 ) ||
! ( V_148 & V_152 ) ) &&
( V_148 & V_153 ) &&
V_2 -> V_154 [ V_146 ] == 0 ) )
continue;
V_2 -> V_154 [ V_146 ] = V_15 + F_97 ( 25 ) ;
F_47 ( V_2 , L_23 , V_146 + 1 ) ;
F_5 ( & V_72 -> V_155 , V_2 -> V_154 [ V_146 ] ) ;
}
}
if ( F_92 ( ( V_30 & V_156 ) != 0 ) ) {
F_17 ( V_2 , L_24 ) ;
F_22 ( V_2 , L_25 , V_61 ) ;
F_60 ( V_2 , L_25 , V_30 ) ;
F_10 ( V_2 ) ;
V_141:
F_20 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_70 ) ;
F_98 ( V_72 ) ;
V_140 = 1 ;
}
if ( V_140 )
F_36 ( V_2 ) ;
F_93 ( & V_2 -> V_58 ) ;
if ( V_139 )
F_99 ( V_72 ) ;
return V_157 ;
}
static int F_100 (
struct V_71 * V_72 ,
struct V_158 * V_158 ,
T_5 V_159
) {
struct V_1 * V_2 = F_41 ( V_72 ) ;
struct V_160 V_161 ;
F_64 ( & V_161 ) ;
switch ( F_101 ( V_158 -> V_162 ) ) {
case V_163 :
if ( V_158 -> V_164 > ( 16 * 1024 ) )
return - V_165 ;
default:
if ( ! F_102 ( V_2 , V_158 , & V_161 , V_159 ) )
return - V_166 ;
return F_103 ( V_2 , V_158 , & V_161 , V_159 ) ;
case V_167 :
if ( ! F_102 ( V_2 , V_158 , & V_161 , V_159 ) )
return - V_166 ;
return F_104 ( V_2 , V_158 , & V_161 , V_159 ) ;
case V_168 :
if ( V_158 -> V_169 -> V_170 == V_171 )
return F_105 ( V_2 , V_158 , V_159 ) ;
else
return F_106 ( V_2 , V_158 , V_159 ) ;
}
}
static void F_107 ( struct V_1 * V_2 , struct V_172 * V_100 )
{
if ( V_2 -> V_37 != V_50 && V_2 -> V_59 )
F_31 ( V_2 ) ;
if ( V_100 -> V_108 != V_109 ) {
if ( V_100 -> V_108 == V_173 )
V_100 -> V_174 = 1 ;
return;
}
if ( V_2 -> V_59 ) {
struct V_172 * V_175 ;
for ( V_175 = V_2 -> V_59 ;
V_175 -> V_59 ;
V_175 = V_175 -> V_59 )
continue;
V_100 -> V_108 = V_176 ;
V_175 -> V_59 = V_100 ;
} else
F_35 ( V_2 , V_100 ) ;
}
static int F_108 ( struct V_71 * V_72 , struct V_158 * V_158 , int V_30 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
struct V_172 * V_100 ;
unsigned long V_57 ;
int V_177 ;
F_28 ( & V_2 -> V_58 , V_57 ) ;
V_177 = F_109 ( V_72 , V_158 , V_30 ) ;
if ( V_177 )
goto V_18;
switch ( F_101 ( V_158 -> V_162 ) ) {
default:
V_100 = (struct V_172 * ) V_158 -> V_178 ;
if ( ! V_100 )
break;
switch ( V_100 -> V_108 ) {
case V_109 :
case V_173 :
F_107 ( V_2 , V_100 ) ;
break;
case V_179 :
case V_176 :
break;
case V_180 :
F_110 ( V_2 , V_100 ) ;
break;
}
break;
case V_167 :
V_100 = (struct V_172 * ) V_158 -> V_178 ;
if ( ! V_100 )
break;
switch ( V_100 -> V_108 ) {
case V_109 :
case V_173 :
F_111 ( V_2 , V_100 ) ;
break;
case V_180 :
F_110 ( V_2 , V_100 ) ;
break;
default:
F_47 ( V_2 , L_26 ,
V_100 , V_100 -> V_108 ) ;
goto V_18;
}
break;
case V_168 :
break;
}
V_18:
F_32 ( & V_2 -> V_58 , V_57 ) ;
return V_177 ;
}
static void
F_112 ( struct V_71 * V_72 , struct V_181 * V_182 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
unsigned long V_57 ;
struct V_172 * V_100 , * V_24 ;
V_183:
F_28 ( & V_2 -> V_58 , V_57 ) ;
V_100 = V_182 -> V_178 ;
if ( ! V_100 )
goto V_18;
if ( V_100 -> V_87 == NULL ) {
F_30 ( V_2 , L_27 ) ;
goto V_184;
}
if ( V_2 -> V_37 != V_50 )
V_100 -> V_108 = V_180 ;
switch ( V_100 -> V_108 ) {
case V_109 :
case V_173 :
for ( V_24 = V_2 -> V_65 -> V_79 . V_100 ;
V_24 && V_24 != V_100 ;
V_24 = V_24 -> V_79 . V_100 )
continue;
if ( V_24 )
F_107 ( V_2 , V_100 ) ;
case V_179 :
case V_176 :
V_184:
F_32 ( & V_2 -> V_58 , V_57 ) ;
F_113 ( 1 ) ;
goto V_183;
case V_180 :
if ( V_100 -> V_185 )
goto V_184;
if ( F_114 ( & V_100 -> V_161 ) ) {
F_115 ( V_100 ) ;
break;
}
default:
F_17 ( V_2 , L_28 ,
V_100 , V_182 -> V_186 . V_187 , V_100 -> V_108 ,
F_114 ( & V_100 -> V_161 ) ? L_18 : L_29 ) ;
break;
}
V_182 -> V_178 = NULL ;
V_18:
F_32 ( & V_2 -> V_58 , V_57 ) ;
}
static void
F_116 ( struct V_71 * V_72 , struct V_181 * V_182 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
struct V_172 * V_100 ;
int V_188 = F_117 ( & V_182 -> V_186 ) ;
int V_189 = F_118 ( & V_182 -> V_186 ) ;
int V_190 = F_119 ( & V_182 -> V_186 ) ;
unsigned long V_57 ;
if ( V_188 != V_191 && V_188 != V_192 )
return;
F_28 ( & V_2 -> V_58 , V_57 ) ;
V_100 = V_182 -> V_178 ;
if ( V_100 ) {
F_120 ( V_100 -> V_169 , V_189 , V_190 , 0 ) ;
if ( ! F_114 ( & V_100 -> V_161 ) ) {
F_121 ( 1 , L_30 ) ;
} else if ( V_100 -> V_108 == V_109 ||
V_100 -> V_108 == V_173 ) {
if ( V_188 == V_191 )
F_107 ( V_2 , V_100 ) ;
else
F_111 ( V_2 , V_100 ) ;
}
}
F_32 ( & V_2 -> V_58 , V_57 ) ;
}
static int F_122 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 ) ;
return ( F_15 ( V_2 ) >> 3 ) % V_2 -> V_92 ;
}
static int T_6 F_123 ( void )
{
int V_40 = 0 ;
if ( F_124 () )
return - V_21 ;
F_125 ( V_193 L_31 V_194 L_32 , V_195 ) ;
F_126 ( V_196 , & V_197 ) ;
if ( F_34 ( V_198 , & V_197 ) ||
F_34 ( V_199 , & V_197 ) )
F_125 ( V_200 L_33
L_34 ) ;
F_127 ( L_35 ,
V_195 ,
sizeof( struct V_172 ) , sizeof( struct V_201 ) ,
sizeof( struct V_202 ) , sizeof( struct V_203 ) ) ;
#ifdef F_25
V_204 = F_128 ( L_36 , V_205 ) ;
if ( ! V_204 ) {
V_40 = - V_206 ;
goto V_207;
}
#endif
#ifdef F_129
V_40 = F_130 ( & F_129 ) ;
if ( V_40 < 0 )
goto V_208;
#endif
#ifdef F_131
V_40 = F_132 ( & F_131 ) ;
if ( V_40 < 0 )
goto V_209;
#endif
#ifdef F_133
V_40 = F_134 ( & F_133 ) ;
if ( V_40 < 0 )
goto V_210;
#endif
#ifdef F_135
V_40 = F_130 ( & F_135 ) ;
if ( V_40 < 0 )
goto V_211;
#endif
#ifdef F_136
V_40 = F_130 ( & F_136 ) ;
if ( V_40 < 0 )
goto V_212;
#endif
return V_40 ;
#ifdef F_136
V_212:
#endif
#ifdef F_135
F_137 ( & F_135 ) ;
V_211:
#endif
#ifdef F_133
F_138 ( & F_133 ) ;
V_210:
#endif
#ifdef F_131
F_139 ( & F_131 ) ;
V_209:
#endif
#ifdef F_129
F_137 ( & F_129 ) ;
V_208:
#endif
#ifdef F_25
F_140 ( V_204 ) ;
V_204 = NULL ;
V_207:
#endif
F_141 ( V_196 , & V_197 ) ;
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
F_140 ( V_204 ) ;
#endif
F_141 ( V_196 , & V_197 ) ;
}
