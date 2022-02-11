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
static int F_13 ( struct V_1 * V_2 , void T_1 * V_16 ,
T_2 V_17 , T_2 V_18 , int V_19 )
{
int error ;
error = F_6 ( V_2 , V_16 , V_17 , V_18 , V_19 ) ;
if ( error ) {
F_10 ( V_2 ) ;
V_2 -> V_35 = V_36 ;
F_14 ( V_2 , L_1 ,
V_16 , V_17 , V_18 , error ) ;
}
return error ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 T_1 * V_23 ;
T_2 V_24 ;
V_23 = ( T_2 T_1 * ) ( ( ( V_25 T_1 * ) V_2 -> V_26 ) + V_27 ) ;
V_24 = F_7 ( V_2 , V_23 ) ;
V_24 |= V_28 ;
if ( F_16 ( V_2 ) )
V_24 |= V_37 ;
F_11 ( V_2 , V_24 , V_23 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_38 ;
T_2 V_33 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_2 -> V_39 && ! F_18 () )
V_2 -> V_39 = NULL ;
V_33 |= V_40 ;
F_19 ( V_2 , L_2 , V_33 ) ;
F_11 ( V_2 , V_33 , & V_2 -> V_26 -> V_33 ) ;
V_2 -> V_35 = V_36 ;
V_2 -> V_41 = V_15 ;
V_38 = F_6 ( V_2 , & V_2 -> V_26 -> V_33 ,
V_40 , 0 , 250 * 1000 ) ;
if ( V_2 -> V_42 ) {
F_11 ( V_2 , V_43 | V_44 ,
( T_2 T_1 * ) ( ( ( V_25 * ) V_2 -> V_26 ) + V_45 ) ) ;
F_11 ( V_2 , V_46 ,
( T_2 T_1 * ) ( ( ( V_25 * ) V_2 -> V_26 ) + V_47 ) ) ;
}
if ( V_38 )
return V_38 ;
if ( F_12 ( V_2 ) )
F_15 ( V_2 ) ;
if ( V_2 -> V_39 )
F_20 () ;
return V_38 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_29 ;
#ifdef F_22
if ( V_2 -> V_35 != V_48 )
F_23 () ;
#endif
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) << 10 ;
V_29 &= V_49 | V_50 ;
if ( F_13 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_49 | V_50 , V_29 , 16 * 125 ) )
return;
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_29 &= ~ ( V_51 | V_52 | V_53 ) ;
F_11 ( V_2 , V_29 , & V_2 -> V_26 -> V_33 ) ;
F_13 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_49 | V_50 , 0 , 16 * 125 ) ;
}
static void F_24 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
unsigned long V_55 ;
F_25 ( & V_2 -> V_56 , V_55 ) ;
if ( V_2 -> V_57
&& ! F_2 ( & V_2 -> V_58 )
&& V_2 -> V_35 == V_48 ) {
T_2 V_59 , V_30 ;
V_59 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_59 & V_52 )
F_11 ( V_2 , V_59 & ~ V_52 ,
& V_2 -> V_26 -> V_33 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( ( V_30 & V_60 ) || ! ( V_59 & V_52 ) ) {
F_26 ( V_2 -> V_61 . V_62 ) ;
F_11 ( V_2 , V_60 , & V_2 -> V_26 -> V_30 ) ;
}
F_27 ( V_2 , L_3 ,
V_30 , V_59 ) ;
F_28 ( V_2 ) ;
}
F_29 ( & V_2 -> V_56 , V_55 ) ;
}
static void F_30 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
unsigned long V_55 ;
F_25 ( & V_2 -> V_56 , V_55 ) ;
if ( F_31 ( V_7 , & V_2 -> V_8 ) )
F_32 ( V_2 , V_2 -> V_63 ) ;
F_33 ( V_2 ) ;
F_29 ( & V_2 -> V_56 , V_55 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_64 = F_35 ( V_2 -> V_65 ) ;
while ( V_64 -- )
F_11 ( V_2 , V_66 ,
& V_2 -> V_26 -> V_67 [ V_64 ] ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_34 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_68 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_68 ) ;
}
static void F_37 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
F_39 ( & V_2 -> V_5 ) ;
F_39 ( & V_2 -> V_58 ) ;
F_40 ( & V_2 -> V_56 ) ;
F_36 ( V_2 ) ;
F_41 ( & V_2 -> V_56 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_71 )
{
unsigned V_64 ;
if ( ! F_43 ( V_2 -> V_65 ) )
return;
F_44 ( V_2 , L_4 , V_71 ? L_5 : L_6 ) ;
for ( V_64 = F_35 ( V_2 -> V_65 ) ; V_64 > 0 ; )
( void ) F_45 ( F_46 ( V_2 ) ,
V_71 ? V_72 : V_73 ,
V_74 ,
V_64 -- , NULL , 0 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_47 ( 20 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_48 ( V_2 , V_10 ) ;
if ( V_2 -> V_75 )
return;
V_2 -> V_75 = 1 ;
F_49 ( V_2 ) ;
if ( V_2 -> V_76 != - 1 )
F_50 ( V_2 ) ;
V_2 -> V_75 = 0 ;
if ( V_2 -> V_35 == V_48 &&
( V_2 -> V_63 -> V_77 . V_16 != NULL ||
V_2 -> V_78 != 0 ) )
F_1 ( V_2 , V_10 ) ;
}
static void F_51 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
F_44 ( V_2 , L_7 ) ;
F_39 ( & V_2 -> V_5 ) ;
F_39 ( & V_2 -> V_58 ) ;
F_40 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_35 == V_48 )
F_21 ( V_2 ) ;
F_36 ( V_2 ) ;
F_17 ( V_2 ) ;
F_41 ( & V_2 -> V_56 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_40 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_63 )
F_33 ( V_2 ) ;
F_41 ( & V_2 -> V_56 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_79 == 1 )
F_55 () ;
#ifdef F_56
F_44 ( V_2 , L_8 ,
V_2 -> V_61 . V_80 , V_2 -> V_61 . error , V_2 -> V_61 . V_57 ,
V_2 -> V_61 . V_62 ) ;
F_44 ( V_2 , L_9 ,
V_2 -> V_61 . V_81 , V_2 -> V_61 . V_82 ) ;
#endif
F_57 ( V_2 , L_10 ,
F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ) ;
}
static int F_58 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
T_2 V_29 ;
int V_38 ;
T_2 V_83 ;
struct V_84 * V_85 ;
F_59 ( & V_2 -> V_56 ) ;
V_2 -> V_11 = 1 ;
F_60 ( & V_2 -> V_5 ) ;
V_2 -> V_5 . V_86 = F_30 ;
V_2 -> V_5 . V_87 = ( unsigned long ) V_2 ;
F_60 ( & V_2 -> V_58 ) ;
V_2 -> V_58 . V_86 = F_24 ;
V_2 -> V_58 . V_87 = ( unsigned long ) V_2 ;
V_83 = F_7 ( V_2 , & V_2 -> V_88 -> V_83 ) ;
V_2 -> V_89 = 100 ;
V_2 -> V_90 = V_91 ;
F_61 ( & V_2 -> V_92 ) ;
F_61 ( & V_2 -> V_93 ) ;
if ( F_62 ( V_83 ) ) {
switch ( V_94 ) {
case 0 : V_2 -> V_90 = 1024 ; break;
case 1 : V_2 -> V_90 = 512 ; break;
case 2 : V_2 -> V_90 = 256 ; break;
default: F_23 () ;
}
}
if ( ( V_38 = F_63 ( V_2 , V_95 ) ) < 0 )
return V_38 ;
if ( F_64 ( V_83 ) )
V_2 -> V_96 = 2 + 8 ;
else
V_2 -> V_96 = 2 + F_65 ( V_83 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_76 = - 1 ;
V_2 -> V_97 = - 1 ;
V_2 -> V_63 -> V_77 . V_98 = NULL ;
V_85 = V_2 -> V_63 -> V_85 ;
V_85 -> V_99 = F_66 ( V_2 , V_2 -> V_63 -> V_100 ) ;
V_85 -> V_101 = F_67 ( V_2 , V_102 ) ;
V_85 -> V_103 = F_67 ( V_2 , V_104 ) ;
V_85 -> V_105 = F_68 ( V_2 ) ;
V_2 -> V_63 -> V_106 = V_107 ;
V_85 -> V_108 = F_69 ( V_2 , V_2 -> V_63 -> V_109 -> V_110 ) ;
if ( V_111 < 0 || V_111 > 6 )
V_111 = 0 ;
V_29 = 1 << ( 16 + V_111 ) ;
if ( F_70 ( V_83 ) ) {
V_2 -> V_112 = 1 ;
F_44 ( V_2 , L_11 ) ;
V_29 |= V_113 ;
}
if ( F_71 ( V_83 ) ) {
if ( V_114 ) {
V_114 = F_72 ( V_114 , ( unsigned ) 3 ) ;
V_29 |= V_115 ;
V_29 |= V_114 << 8 ;
}
F_44 ( V_2 , L_12 , V_114 ) ;
}
if ( F_62 ( V_83 ) ) {
V_29 &= ~ ( 3 << 2 ) ;
V_29 |= ( V_94 << 2 ) ;
}
if ( F_73 ( V_83 ) ) {
F_44 ( V_2 , L_13 ) ;
V_2 -> V_116 = 1 ;
if ( V_117 > 0xf ) {
F_44 ( V_2 , L_14 ,
V_117 ) ;
V_117 = 0 ;
}
V_29 |= V_117 << 24 ;
}
V_2 -> V_33 = V_29 ;
if ( ! ( V_70 -> V_118 -> V_55 & V_119 ) )
V_70 -> V_120 . V_121 = ~ 0 ;
return 0 ;
}
static int F_74 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
int V_38 ;
T_2 V_29 ;
T_2 V_83 ;
V_70 -> V_122 = 1 ;
if ( ! F_12 ( V_2 ) && ( V_38 = F_17 ( V_2 ) ) != 0 ) {
F_54 ( V_2 ) ;
return V_38 ;
}
F_11 ( V_2 , V_2 -> V_123 , & V_2 -> V_26 -> V_124 ) ;
F_11 ( V_2 , ( T_2 ) V_2 -> V_63 -> V_100 , & V_2 -> V_26 -> V_125 ) ;
V_83 = F_7 ( V_2 , & V_2 -> V_88 -> V_83 ) ;
if ( F_75 ( V_83 ) ) {
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_126 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_33 &= ~ ( V_127 | V_52 | V_53 | V_51 | V_40 ) ;
V_2 -> V_33 |= V_34 ;
F_11 ( V_2 , V_2 -> V_33 , & V_2 -> V_26 -> V_33 ) ;
F_19 ( V_2 , L_15 , V_2 -> V_33 ) ;
F_76 ( & V_128 ) ;
V_2 -> V_35 = V_48 ;
F_11 ( V_2 , V_129 , & V_2 -> V_26 -> V_68 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_47 ( 5 ) ;
F_77 ( & V_128 ) ;
V_2 -> V_130 = F_78 () ;
V_29 = F_79 ( V_2 , F_7 ( V_2 , & V_2 -> V_88 -> V_131 ) ) ;
F_80 ( V_2 ,
L_16 ,
( ( V_2 -> V_132 & 0xf0 ) >> 4 ) , ( V_2 -> V_132 & 0x0f ) ,
V_29 >> 8 , V_29 & 0xff ,
V_133 ? L_17 : L_18 ) ;
F_11 ( V_2 , V_134 ,
& V_2 -> V_26 -> V_31 ) ;
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int T_3 F_83 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
int V_38 ;
V_2 -> V_26 = ( void T_1 * ) V_2 -> V_88 +
F_84 ( V_2 , F_7 ( V_2 , & V_2 -> V_88 -> V_131 ) ) ;
F_85 ( V_2 , L_2 ) ;
F_86 ( V_2 , L_2 ) ;
V_2 -> V_65 = F_7 ( V_2 , & V_2 -> V_88 -> V_65 ) ;
V_2 -> V_132 = V_135 ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_58 ( V_70 ) ;
if ( V_38 )
return V_38 ;
F_17 ( V_2 ) ;
return 0 ;
}
static T_4 F_87 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
T_2 V_30 , V_136 , V_137 = 0 , V_59 ;
int V_138 ;
F_88 ( & V_2 -> V_56 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( V_30 == ~ ( T_2 ) 0 ) {
F_44 ( V_2 , L_19 ) ;
goto V_139;
}
V_136 = V_30 & V_134 ;
if ( ! V_136 || F_89 ( V_2 -> V_35 == V_36 ) ) {
F_90 ( & V_2 -> V_56 ) ;
return V_140 ;
}
F_11 ( V_2 , V_136 , & V_2 -> V_26 -> V_30 ) ;
V_59 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_138 = 0 ;
#ifdef F_91
F_57 ( V_2 , L_20 , V_30 ) ;
#endif
if ( F_92 ( ( V_30 & ( V_141 | V_142 ) ) != 0 ) ) {
if ( F_92 ( ( V_30 & V_142 ) == 0 ) )
F_26 ( V_2 -> V_61 . V_80 ) ;
else
F_26 ( V_2 -> V_61 . error ) ;
V_138 = 1 ;
}
if ( V_30 & V_60 ) {
if ( V_59 & V_52 ) {
F_11 ( V_2 , V_59 & ~ V_52 ,
& V_2 -> V_26 -> V_33 ) ;
F_44 ( V_2 , L_21 ) ;
}
if ( V_2 -> V_57 ) {
F_26 ( V_2 -> V_61 . V_57 ) ;
F_28 ( V_2 ) ;
} else
F_44 ( V_2 , L_22 ) ;
}
if ( V_30 & V_143 ) {
unsigned V_144 = F_35 ( V_2 -> V_65 ) ;
T_2 V_145 = 0 ;
V_137 = V_30 ;
if ( ! ( V_59 & V_34 ) )
F_93 ( V_70 ) ;
if ( V_2 -> V_112 )
V_145 = V_30 >> 16 ;
while ( V_144 -- ) {
int V_146 ;
if ( V_2 -> V_112 && ! ( V_145 & ( 1 << V_144 ) ) )
continue;
V_146 = F_7 ( V_2 ,
& V_2 -> V_26 -> V_67 [ V_144 ] ) ;
if ( V_146 & V_147 )
continue;
if ( ! ( F_31 ( V_144 , & V_2 -> V_148 ) &&
( ( V_146 & V_149 ) ||
! ( V_146 & V_150 ) ) &&
( V_146 & V_151 ) &&
V_2 -> V_152 [ V_144 ] == 0 ) )
continue;
V_2 -> V_152 [ V_144 ] = V_15 + F_94 ( 25 ) ;
F_44 ( V_2 , L_23 , V_144 + 1 ) ;
F_5 ( & V_70 -> V_153 , V_2 -> V_152 [ V_144 ] ) ;
}
}
if ( F_89 ( ( V_30 & V_154 ) != 0 ) ) {
F_14 ( V_2 , L_24 ) ;
F_19 ( V_2 , L_25 , V_59 ) ;
F_57 ( V_2 , L_25 , V_30 ) ;
F_10 ( V_2 ) ;
V_139:
F_17 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_68 ) ;
F_95 ( V_70 ) ;
V_138 = 1 ;
}
if ( V_138 )
F_33 ( V_2 ) ;
F_90 ( & V_2 -> V_56 ) ;
if ( V_137 )
F_96 ( V_70 ) ;
return V_155 ;
}
static int F_97 (
struct V_69 * V_70 ,
struct V_156 * V_156 ,
T_5 V_157
) {
struct V_1 * V_2 = F_38 ( V_70 ) ;
struct V_158 V_159 ;
F_61 ( & V_159 ) ;
switch ( F_98 ( V_156 -> V_160 ) ) {
case V_161 :
if ( V_156 -> V_162 > ( 16 * 1024 ) )
return - V_163 ;
default:
if ( ! F_99 ( V_2 , V_156 , & V_159 , V_157 ) )
return - V_164 ;
return F_100 ( V_2 , V_156 , & V_159 , V_157 ) ;
case V_165 :
if ( ! F_99 ( V_2 , V_156 , & V_159 , V_157 ) )
return - V_164 ;
return F_101 ( V_2 , V_156 , & V_159 , V_157 ) ;
case V_166 :
if ( V_156 -> V_167 -> V_168 == V_169 )
return F_102 ( V_2 , V_156 , V_157 ) ;
else
return F_103 ( V_2 , V_156 , V_157 ) ;
}
}
static void F_104 ( struct V_1 * V_2 , struct V_170 * V_98 )
{
if ( V_2 -> V_35 != V_48 && V_2 -> V_57 )
F_28 ( V_2 ) ;
if ( V_98 -> V_106 != V_107 ) {
if ( V_98 -> V_106 == V_171 )
V_98 -> V_172 = 1 ;
return;
}
if ( V_2 -> V_57 ) {
struct V_170 * V_173 ;
for ( V_173 = V_2 -> V_57 ;
V_173 -> V_57 ;
V_173 = V_173 -> V_57 )
continue;
V_98 -> V_106 = V_174 ;
V_173 -> V_57 = V_98 ;
} else
F_32 ( V_2 , V_98 ) ;
}
static int F_105 ( struct V_69 * V_70 , struct V_156 * V_156 , int V_30 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
struct V_170 * V_98 ;
unsigned long V_55 ;
int V_175 ;
F_25 ( & V_2 -> V_56 , V_55 ) ;
V_175 = F_106 ( V_70 , V_156 , V_30 ) ;
if ( V_175 )
goto V_18;
switch ( F_98 ( V_156 -> V_160 ) ) {
default:
V_98 = (struct V_170 * ) V_156 -> V_176 ;
if ( ! V_98 )
break;
switch ( V_98 -> V_106 ) {
case V_107 :
case V_171 :
F_104 ( V_2 , V_98 ) ;
break;
case V_177 :
case V_174 :
break;
case V_178 :
F_107 ( V_2 , V_98 ) ;
break;
}
break;
case V_165 :
V_98 = (struct V_170 * ) V_156 -> V_176 ;
if ( ! V_98 )
break;
switch ( V_98 -> V_106 ) {
case V_107 :
case V_171 :
F_108 ( V_2 , V_98 ) ;
break;
case V_178 :
F_107 ( V_2 , V_98 ) ;
break;
default:
F_44 ( V_2 , L_26 ,
V_98 , V_98 -> V_106 ) ;
goto V_18;
}
break;
case V_166 :
break;
}
V_18:
F_29 ( & V_2 -> V_56 , V_55 ) ;
return V_175 ;
}
static void
F_109 ( struct V_69 * V_70 , struct V_179 * V_180 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
unsigned long V_55 ;
struct V_170 * V_98 , * V_24 ;
V_181:
F_25 ( & V_2 -> V_56 , V_55 ) ;
V_98 = V_180 -> V_176 ;
if ( ! V_98 )
goto V_18;
if ( V_98 -> V_85 == NULL ) {
F_27 ( V_2 , L_27 ) ;
goto V_182;
}
if ( V_2 -> V_35 != V_48 )
V_98 -> V_106 = V_178 ;
switch ( V_98 -> V_106 ) {
case V_107 :
case V_171 :
for ( V_24 = V_2 -> V_63 -> V_77 . V_98 ;
V_24 && V_24 != V_98 ;
V_24 = V_24 -> V_77 . V_98 )
continue;
if ( V_24 )
F_104 ( V_2 , V_98 ) ;
case V_177 :
case V_174 :
V_182:
F_29 ( & V_2 -> V_56 , V_55 ) ;
F_110 ( 1 ) ;
goto V_181;
case V_178 :
if ( V_98 -> V_183 )
goto V_182;
if ( F_111 ( & V_98 -> V_159 ) ) {
F_112 ( V_98 ) ;
break;
}
default:
F_14 ( V_2 , L_28 ,
V_98 , V_180 -> V_184 . V_185 , V_98 -> V_106 ,
F_111 ( & V_98 -> V_159 ) ? L_18 : L_29 ) ;
break;
}
V_180 -> V_176 = NULL ;
V_18:
F_29 ( & V_2 -> V_56 , V_55 ) ;
}
static void
F_113 ( struct V_69 * V_70 , struct V_179 * V_180 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
struct V_170 * V_98 ;
int V_186 = F_114 ( & V_180 -> V_184 ) ;
int V_187 = F_115 ( & V_180 -> V_184 ) ;
int V_188 = F_116 ( & V_180 -> V_184 ) ;
unsigned long V_55 ;
if ( V_186 != V_189 && V_186 != V_190 )
return;
F_25 ( & V_2 -> V_56 , V_55 ) ;
V_98 = V_180 -> V_176 ;
if ( V_98 ) {
F_117 ( V_98 -> V_167 , V_187 , V_188 , 0 ) ;
if ( ! F_111 ( & V_98 -> V_159 ) ) {
F_118 ( 1 , L_30 ) ;
} else if ( V_98 -> V_106 == V_107 ||
V_98 -> V_106 == V_171 ) {
if ( V_186 == V_189 )
F_104 ( V_2 , V_98 ) ;
else
F_108 ( V_2 , V_98 ) ;
}
}
F_29 ( & V_2 -> V_56 , V_55 ) ;
}
static int F_119 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_38 ( V_70 ) ;
return ( F_120 ( V_2 ) >> 3 ) % V_2 -> V_90 ;
}
static int T_6 F_121 ( void )
{
int V_38 = 0 ;
if ( F_122 () )
return - V_21 ;
F_123 ( V_191 L_31 V_192 L_32 , V_193 ) ;
F_124 ( V_194 , & V_195 ) ;
if ( F_31 ( V_196 , & V_195 ) ||
F_31 ( V_197 , & V_195 ) )
F_123 ( V_198 L_33
L_34 ) ;
F_125 ( L_35 ,
V_193 ,
sizeof( struct V_170 ) , sizeof( struct V_199 ) ,
sizeof( struct V_200 ) , sizeof( struct V_201 ) ) ;
#ifdef F_22
V_202 = F_126 ( L_36 , V_203 ) ;
if ( ! V_202 ) {
V_38 = - V_204 ;
goto V_205;
}
#endif
#ifdef F_127
V_38 = F_128 ( & F_127 ) ;
if ( V_38 < 0 )
goto V_206;
#endif
#ifdef F_129
V_38 = F_130 ( & F_129 ) ;
if ( V_38 < 0 )
goto V_207;
#endif
#ifdef F_131
V_38 = F_132 ( & F_131 ) ;
if ( V_38 < 0 )
goto V_208;
#endif
#ifdef F_133
V_38 = F_128 ( & F_133 ) ;
if ( V_38 < 0 )
goto V_209;
#endif
#ifdef F_134
V_38 = F_128 ( & F_134 ) ;
if ( V_38 < 0 )
goto V_210;
#endif
return V_38 ;
#ifdef F_134
V_210:
#endif
#ifdef F_133
F_135 ( & F_133 ) ;
V_209:
#endif
#ifdef F_131
F_136 ( & F_131 ) ;
V_208:
#endif
#ifdef F_129
F_137 ( & F_129 ) ;
V_207:
#endif
#ifdef F_127
F_135 ( & F_127 ) ;
V_206:
#endif
#ifdef F_22
F_138 ( V_202 ) ;
V_202 = NULL ;
V_205:
#endif
F_139 ( V_194 , & V_195 ) ;
return V_38 ;
}
static void T_7 F_140 ( void )
{
#ifdef F_134
F_135 ( & F_134 ) ;
#endif
#ifdef F_133
F_135 ( & F_133 ) ;
#endif
#ifdef F_127
F_135 ( & F_127 ) ;
#endif
#ifdef F_129
F_137 ( & F_129 ) ;
#endif
#ifdef F_131
F_136 ( & F_131 ) ;
#endif
#ifdef F_22
F_138 ( V_202 ) ;
#endif
F_139 ( V_194 , & V_195 ) ;
}
