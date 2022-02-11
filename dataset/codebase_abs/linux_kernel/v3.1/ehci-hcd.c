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
F_14 ( V_2 ) -> V_35 = V_36 ;
F_15 ( V_2 , L_1 ,
V_16 , V_17 , V_18 , error ) ;
}
return error ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 T_1 * V_23 ;
T_2 V_24 ;
V_23 = ( T_2 T_1 * ) ( ( ( V_25 T_1 * ) V_2 -> V_26 ) + V_27 ) ;
V_24 = F_7 ( V_2 , V_23 ) ;
V_24 |= V_28 ;
if ( F_17 ( V_2 ) )
V_24 |= V_37 ;
F_11 ( V_2 , V_24 , V_23 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_38 ;
T_2 V_33 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_2 -> V_39 && ! F_19 () )
V_2 -> V_39 = NULL ;
V_33 |= V_40 ;
F_20 ( V_2 , L_2 , V_33 ) ;
F_11 ( V_2 , V_33 , & V_2 -> V_26 -> V_33 ) ;
F_14 ( V_2 ) -> V_35 = V_36 ;
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
F_16 ( V_2 ) ;
if ( V_2 -> V_39 )
F_21 () ;
return V_38 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_29 ;
#ifdef F_23
if ( ! F_24 ( F_14 ( V_2 ) -> V_35 ) )
F_25 () ;
#endif
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) << 10 ;
V_29 &= V_48 | V_49 ;
if ( F_13 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_48 | V_49 , V_29 , 16 * 125 ) )
return;
V_29 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_29 &= ~ ( V_50 | V_51 | V_52 ) ;
F_11 ( V_2 , V_29 , & V_2 -> V_26 -> V_33 ) ;
F_13 ( V_2 , & V_2 -> V_26 -> V_30 ,
V_48 | V_49 , 0 , 16 * 125 ) ;
}
static void F_26 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
unsigned long V_54 ;
F_27 ( & V_2 -> V_55 , V_54 ) ;
if ( V_2 -> V_56
&& ! F_2 ( & V_2 -> V_57 )
&& F_24 ( F_14 ( V_2 ) -> V_35 ) ) {
T_2 V_58 , V_30 ;
V_58 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
if ( V_58 & V_51 )
F_11 ( V_2 , V_58 & ~ V_51 ,
& V_2 -> V_26 -> V_33 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( ( V_30 & V_59 ) || ! ( V_58 & V_51 ) ) {
F_28 ( V_2 -> V_60 . V_61 ) ;
F_11 ( V_2 , V_59 , & V_2 -> V_26 -> V_30 ) ;
}
F_29 ( V_2 , L_3 ,
V_30 , V_58 ) ;
F_30 ( V_2 ) ;
}
F_31 ( & V_2 -> V_55 , V_54 ) ;
}
static void F_32 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
unsigned long V_54 ;
F_27 ( & V_2 -> V_55 , V_54 ) ;
if ( F_33 ( V_7 , & V_2 -> V_8 ) )
F_34 ( V_2 , V_2 -> V_62 ) ;
F_35 ( V_2 ) ;
F_31 ( & V_2 -> V_55 , V_54 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_63 = F_37 ( V_2 -> V_64 ) ;
while ( V_63 -- )
F_11 ( V_2 , V_65 ,
& V_2 -> V_26 -> V_66 [ V_63 ] ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_36 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_67 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_67 ) ;
}
static void F_39 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
F_41 ( & V_2 -> V_5 ) ;
F_41 ( & V_2 -> V_57 ) ;
F_42 ( & V_2 -> V_55 ) ;
F_38 ( V_2 ) ;
F_43 ( & V_2 -> V_55 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_70 )
{
unsigned V_63 ;
if ( ! F_45 ( V_2 -> V_64 ) )
return;
F_46 ( V_2 , L_4 , V_70 ? L_5 : L_6 ) ;
for ( V_63 = F_37 ( V_2 -> V_64 ) ; V_63 > 0 ; )
( void ) F_47 ( F_14 ( V_2 ) ,
V_70 ? V_71 : V_72 ,
V_73 ,
V_63 -- , NULL , 0 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_48 ( 20 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_10 ) ;
if ( V_2 -> V_74 )
return;
V_2 -> V_74 = 1 ;
F_50 ( V_2 ) ;
if ( V_2 -> V_75 != - 1 )
F_51 ( V_2 ) ;
V_2 -> V_74 = 0 ;
if ( F_24 ( F_14 ( V_2 ) -> V_35 ) &&
( V_2 -> V_62 -> V_76 . V_16 != NULL ||
V_2 -> V_77 != 0 ) )
F_1 ( V_2 , V_10 ) ;
}
static void F_52 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
F_46 ( V_2 , L_7 ) ;
F_41 ( & V_2 -> V_5 ) ;
F_41 ( & V_2 -> V_57 ) ;
F_42 ( & V_2 -> V_55 ) ;
if ( F_24 ( V_69 -> V_35 ) )
F_22 ( V_2 ) ;
F_38 ( V_2 ) ;
F_18 ( V_2 ) ;
F_43 ( & V_2 -> V_55 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_42 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_62 )
F_35 ( V_2 ) ;
F_43 ( & V_2 -> V_55 ) ;
F_55 ( V_2 ) ;
if ( V_2 -> V_78 == 1 )
F_56 () ;
#ifdef F_57
F_46 ( V_2 , L_8 ,
V_2 -> V_60 . V_79 , V_2 -> V_60 . error , V_2 -> V_60 . V_56 ,
V_2 -> V_60 . V_61 ) ;
F_46 ( V_2 , L_9 ,
V_2 -> V_60 . V_80 , V_2 -> V_60 . V_81 ) ;
#endif
F_58 ( V_2 , L_10 ,
F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ) ;
}
static int F_59 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
T_2 V_29 ;
int V_38 ;
T_2 V_82 ;
struct V_83 * V_84 ;
F_60 ( & V_2 -> V_55 ) ;
V_2 -> V_11 = 1 ;
F_61 ( & V_2 -> V_5 ) ;
V_2 -> V_5 . V_85 = F_32 ;
V_2 -> V_5 . V_86 = ( unsigned long ) V_2 ;
F_61 ( & V_2 -> V_57 ) ;
V_2 -> V_57 . V_85 = F_26 ;
V_2 -> V_57 . V_86 = ( unsigned long ) V_2 ;
V_82 = F_7 ( V_2 , & V_2 -> V_87 -> V_82 ) ;
V_2 -> V_88 = 100 ;
V_2 -> V_89 = V_90 ;
F_62 ( & V_2 -> V_91 ) ;
F_62 ( & V_2 -> V_92 ) ;
if ( F_63 ( V_82 ) ) {
switch ( V_93 ) {
case 0 : V_2 -> V_89 = 1024 ; break;
case 1 : V_2 -> V_89 = 512 ; break;
case 2 : V_2 -> V_89 = 256 ; break;
default: F_25 () ;
}
}
if ( ( V_38 = F_64 ( V_2 , V_94 ) ) < 0 )
return V_38 ;
if ( F_65 ( V_82 ) )
V_2 -> V_95 = 2 + 8 ;
else
V_2 -> V_95 = 2 + F_66 ( V_82 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_75 = - 1 ;
V_2 -> V_96 = - 1 ;
V_2 -> V_62 -> V_76 . V_97 = NULL ;
V_84 = V_2 -> V_62 -> V_84 ;
V_84 -> V_98 = F_67 ( V_2 , V_2 -> V_62 -> V_99 ) ;
V_84 -> V_100 = F_68 ( V_2 , V_101 ) ;
V_84 -> V_102 = F_68 ( V_2 , V_103 ) ;
V_84 -> V_104 = F_69 ( V_2 ) ;
V_2 -> V_62 -> V_105 = V_106 ;
V_84 -> V_107 = F_70 ( V_2 , V_2 -> V_62 -> V_108 -> V_109 ) ;
if ( V_110 < 0 || V_110 > 6 )
V_110 = 0 ;
V_29 = 1 << ( 16 + V_110 ) ;
if ( F_71 ( V_82 ) ) {
V_2 -> V_111 = 1 ;
F_46 ( V_2 , L_11 ) ;
V_29 |= V_112 ;
}
if ( F_72 ( V_82 ) ) {
if ( V_113 ) {
V_113 = F_73 ( V_113 , ( unsigned ) 3 ) ;
V_29 |= V_114 ;
V_29 |= V_113 << 8 ;
}
F_46 ( V_2 , L_12 , V_113 ) ;
}
if ( F_63 ( V_82 ) ) {
V_29 &= ~ ( 3 << 2 ) ;
V_29 |= ( V_93 << 2 ) ;
}
if ( F_74 ( V_82 ) ) {
F_46 ( V_2 , L_13 ) ;
V_2 -> V_115 = 1 ;
if ( V_116 > 0xf ) {
F_46 ( V_2 , L_14 ,
V_116 ) ;
V_116 = 0 ;
}
V_29 |= V_116 << 24 ;
}
V_2 -> V_33 = V_29 ;
if ( ! ( V_69 -> V_117 -> V_54 & V_118 ) )
V_69 -> V_119 . V_120 = ~ 0 ;
return 0 ;
}
static int F_75 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
int V_38 ;
T_2 V_29 ;
T_2 V_82 ;
V_69 -> V_121 = 1 ;
if ( ! F_12 ( V_2 ) && ( V_38 = F_18 ( V_2 ) ) != 0 ) {
F_55 ( V_2 ) ;
return V_38 ;
}
F_11 ( V_2 , V_2 -> V_122 , & V_2 -> V_26 -> V_123 ) ;
F_11 ( V_2 , ( T_2 ) V_2 -> V_62 -> V_99 , & V_2 -> V_26 -> V_124 ) ;
V_82 = F_7 ( V_2 , & V_2 -> V_87 -> V_82 ) ;
if ( F_76 ( V_82 ) ) {
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_125 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_33 &= ~ ( V_126 | V_51 | V_52 | V_50 | V_40 ) ;
V_2 -> V_33 |= V_34 ;
F_11 ( V_2 , V_2 -> V_33 , & V_2 -> V_26 -> V_33 ) ;
F_20 ( V_2 , L_15 , V_2 -> V_33 ) ;
F_77 ( & V_127 ) ;
V_69 -> V_35 = V_128 ;
F_11 ( V_2 , V_129 , & V_2 -> V_26 -> V_67 ) ;
F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
F_48 ( 5 ) ;
F_78 ( & V_127 ) ;
V_2 -> V_130 = F_79 () ;
V_29 = F_80 ( V_2 , F_7 ( V_2 , & V_2 -> V_87 -> V_131 ) ) ;
F_81 ( V_2 ,
L_16 ,
( ( V_2 -> V_132 & 0xf0 ) >> 4 ) , ( V_2 -> V_132 & 0x0f ) ,
V_29 >> 8 , V_29 & 0xff ,
V_133 ? L_17 : L_18 ) ;
F_11 ( V_2 , V_134 ,
& V_2 -> V_26 -> V_31 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static T_3 F_84 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
T_2 V_30 , V_135 , V_136 = 0 , V_58 ;
int V_137 ;
F_85 ( & V_2 -> V_55 ) ;
V_30 = F_7 ( V_2 , & V_2 -> V_26 -> V_30 ) ;
if ( V_30 == ~ ( T_2 ) 0 ) {
F_46 ( V_2 , L_19 ) ;
goto V_138;
}
V_135 = V_30 & V_134 ;
if ( ! V_135 || F_86 ( V_69 -> V_35 == V_36 ) ) {
F_87 ( & V_2 -> V_55 ) ;
return V_139 ;
}
F_11 ( V_2 , V_135 , & V_2 -> V_26 -> V_30 ) ;
V_58 = F_7 ( V_2 , & V_2 -> V_26 -> V_33 ) ;
V_137 = 0 ;
#ifdef F_88
F_58 ( V_2 , L_20 , V_30 ) ;
#endif
if ( F_89 ( ( V_30 & ( V_140 | V_141 ) ) != 0 ) ) {
if ( F_89 ( ( V_30 & V_141 ) == 0 ) )
F_28 ( V_2 -> V_60 . V_79 ) ;
else
F_28 ( V_2 -> V_60 . error ) ;
V_137 = 1 ;
}
if ( V_30 & V_59 ) {
if ( V_58 & V_51 ) {
F_11 ( V_2 , V_58 & ~ V_51 ,
& V_2 -> V_26 -> V_33 ) ;
F_46 ( V_2 , L_21 ) ;
}
if ( V_2 -> V_56 ) {
F_28 ( V_2 -> V_60 . V_56 ) ;
F_30 ( V_2 ) ;
} else
F_46 ( V_2 , L_22 ) ;
}
if ( V_30 & V_142 ) {
unsigned V_143 = F_37 ( V_2 -> V_64 ) ;
T_2 V_144 = 0 ;
V_136 = V_30 ;
if ( ! ( V_58 & V_34 ) )
F_90 ( V_69 ) ;
if ( V_2 -> V_111 )
V_144 = V_30 >> 16 ;
while ( V_143 -- ) {
int V_145 ;
if ( V_2 -> V_111 && ! ( V_144 & ( 1 << V_143 ) ) )
continue;
V_145 = F_7 ( V_2 ,
& V_2 -> V_26 -> V_66 [ V_143 ] ) ;
if ( V_145 & V_146 )
continue;
if ( ! ( F_33 ( V_143 , & V_2 -> V_147 ) &&
( ( V_145 & V_148 ) ||
! ( V_145 & V_149 ) ) &&
( V_145 & V_150 ) &&
V_2 -> V_151 [ V_143 ] == 0 ) )
continue;
V_2 -> V_151 [ V_143 ] = V_15 + F_91 ( 25 ) ;
F_46 ( V_2 , L_23 , V_143 + 1 ) ;
F_5 ( & V_69 -> V_152 , V_2 -> V_151 [ V_143 ] ) ;
}
}
if ( F_86 ( ( V_30 & V_153 ) != 0 ) ) {
F_15 ( V_2 , L_24 ) ;
F_20 ( V_2 , L_25 , V_58 ) ;
F_58 ( V_2 , L_25 , V_30 ) ;
F_10 ( V_2 ) ;
V_138:
F_18 ( V_2 ) ;
F_11 ( V_2 , 0 , & V_2 -> V_26 -> V_67 ) ;
F_92 ( V_69 ) ;
V_137 = 1 ;
}
if ( V_137 )
F_35 ( V_2 ) ;
F_87 ( & V_2 -> V_55 ) ;
if ( V_136 )
F_93 ( V_69 ) ;
return V_154 ;
}
static int F_94 (
struct V_68 * V_69 ,
struct V_155 * V_155 ,
T_4 V_156
) {
struct V_1 * V_2 = F_40 ( V_69 ) ;
struct V_157 V_158 ;
F_62 ( & V_158 ) ;
switch ( F_95 ( V_155 -> V_159 ) ) {
case V_160 :
if ( V_155 -> V_161 > ( 16 * 1024 ) )
return - V_162 ;
default:
if ( ! F_96 ( V_2 , V_155 , & V_158 , V_156 ) )
return - V_163 ;
return F_97 ( V_2 , V_155 , & V_158 , V_156 ) ;
case V_164 :
if ( ! F_96 ( V_2 , V_155 , & V_158 , V_156 ) )
return - V_163 ;
return F_98 ( V_2 , V_155 , & V_158 , V_156 ) ;
case V_165 :
if ( V_155 -> V_166 -> V_167 == V_168 )
return F_99 ( V_2 , V_155 , V_156 ) ;
else
return F_100 ( V_2 , V_155 , V_156 ) ;
}
}
static void F_101 ( struct V_1 * V_2 , struct V_169 * V_97 )
{
if ( ! F_24 ( F_14 ( V_2 ) -> V_35 ) && V_2 -> V_56 )
F_30 ( V_2 ) ;
if ( V_97 -> V_105 != V_106 ) {
if ( V_97 -> V_105 == V_170 )
V_97 -> V_171 = 1 ;
return;
}
if ( V_2 -> V_56 ) {
struct V_169 * V_172 ;
for ( V_172 = V_2 -> V_56 ;
V_172 -> V_56 ;
V_172 = V_172 -> V_56 )
continue;
V_97 -> V_105 = V_173 ;
V_172 -> V_56 = V_97 ;
} else
F_34 ( V_2 , V_97 ) ;
}
static int F_102 ( struct V_68 * V_69 , struct V_155 * V_155 , int V_30 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
struct V_169 * V_97 ;
unsigned long V_54 ;
int V_174 ;
F_27 ( & V_2 -> V_55 , V_54 ) ;
V_174 = F_103 ( V_69 , V_155 , V_30 ) ;
if ( V_174 )
goto V_18;
switch ( F_95 ( V_155 -> V_159 ) ) {
default:
V_97 = (struct V_169 * ) V_155 -> V_175 ;
if ( ! V_97 )
break;
switch ( V_97 -> V_105 ) {
case V_106 :
case V_170 :
F_101 ( V_2 , V_97 ) ;
break;
case V_176 :
case V_173 :
break;
case V_177 :
F_104 ( V_2 , V_97 ) ;
break;
}
break;
case V_164 :
V_97 = (struct V_169 * ) V_155 -> V_175 ;
if ( ! V_97 )
break;
switch ( V_97 -> V_105 ) {
case V_106 :
case V_170 :
F_105 ( V_2 , V_97 ) ;
break;
case V_177 :
F_104 ( V_2 , V_97 ) ;
break;
default:
F_46 ( V_2 , L_26 ,
V_97 , V_97 -> V_105 ) ;
goto V_18;
}
break;
case V_165 :
break;
}
V_18:
F_31 ( & V_2 -> V_55 , V_54 ) ;
return V_174 ;
}
static void
F_106 ( struct V_68 * V_69 , struct V_178 * V_179 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
unsigned long V_54 ;
struct V_169 * V_97 , * V_24 ;
V_180:
F_27 ( & V_2 -> V_55 , V_54 ) ;
V_97 = V_179 -> V_175 ;
if ( ! V_97 )
goto V_18;
if ( V_97 -> V_84 == NULL ) {
F_29 ( V_2 , L_27 ) ;
goto V_181;
}
if ( ! F_24 ( V_69 -> V_35 ) )
V_97 -> V_105 = V_177 ;
switch ( V_97 -> V_105 ) {
case V_106 :
case V_170 :
for ( V_24 = V_2 -> V_62 -> V_76 . V_97 ;
V_24 && V_24 != V_97 ;
V_24 = V_24 -> V_76 . V_97 )
continue;
if ( V_24 )
F_101 ( V_2 , V_97 ) ;
case V_176 :
case V_173 :
V_181:
F_31 ( & V_2 -> V_55 , V_54 ) ;
F_107 ( 1 ) ;
goto V_180;
case V_177 :
if ( V_97 -> V_182 )
goto V_181;
if ( F_108 ( & V_97 -> V_158 ) ) {
F_109 ( V_97 ) ;
break;
}
default:
F_15 ( V_2 , L_28 ,
V_97 , V_179 -> V_183 . V_184 , V_97 -> V_105 ,
F_108 ( & V_97 -> V_158 ) ? L_18 : L_29 ) ;
break;
}
V_179 -> V_175 = NULL ;
V_18:
F_31 ( & V_2 -> V_55 , V_54 ) ;
}
static void
F_110 ( struct V_68 * V_69 , struct V_178 * V_179 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
struct V_169 * V_97 ;
int V_185 = F_111 ( & V_179 -> V_183 ) ;
int V_186 = F_112 ( & V_179 -> V_183 ) ;
int V_187 = F_113 ( & V_179 -> V_183 ) ;
unsigned long V_54 ;
if ( V_185 != V_188 && V_185 != V_189 )
return;
F_27 ( & V_2 -> V_55 , V_54 ) ;
V_97 = V_179 -> V_175 ;
if ( V_97 ) {
F_114 ( V_97 -> V_166 , V_186 , V_187 , 0 ) ;
if ( ! F_108 ( & V_97 -> V_158 ) ) {
F_115 ( 1 , L_30 ) ;
} else if ( V_97 -> V_105 == V_106 ||
V_97 -> V_105 == V_170 ) {
if ( V_185 == V_188 )
F_101 ( V_2 , V_97 ) ;
else
F_105 ( V_2 , V_97 ) ;
}
}
F_31 ( & V_2 -> V_55 , V_54 ) ;
}
static int F_116 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_40 ( V_69 ) ;
return ( F_7 ( V_2 , & V_2 -> V_26 -> V_190 ) >> 3 ) %
V_2 -> V_89 ;
}
static int T_5 F_117 ( void )
{
int V_38 = 0 ;
if ( F_118 () )
return - V_21 ;
F_119 ( V_191 L_31 V_192 L_32 , V_193 ) ;
F_120 ( V_194 , & V_195 ) ;
if ( F_33 ( V_196 , & V_195 ) ||
F_33 ( V_197 , & V_195 ) )
F_119 ( V_198 L_33
L_34 ) ;
F_121 ( L_35 ,
V_193 ,
sizeof( struct V_169 ) , sizeof( struct V_199 ) ,
sizeof( struct V_200 ) , sizeof( struct V_201 ) ) ;
#ifdef F_23
V_202 = F_122 ( L_36 , V_203 ) ;
if ( ! V_202 ) {
V_38 = - V_204 ;
goto V_205;
}
#endif
#ifdef F_123
V_38 = F_124 ( & F_123 ) ;
if ( V_38 < 0 )
goto V_206;
#endif
#ifdef F_125
V_38 = F_126 ( & F_125 ) ;
if ( V_38 < 0 )
goto V_207;
#endif
#ifdef F_127
V_38 = F_128 ( & F_127 ) ;
if ( V_38 < 0 )
goto V_208;
#endif
#ifdef F_129
V_38 = F_124 ( & F_129 ) ;
if ( V_38 < 0 )
goto V_209;
#endif
#ifdef F_130
V_38 = F_124 ( & F_130 ) ;
if ( V_38 < 0 )
goto V_210;
#endif
return V_38 ;
#ifdef F_130
V_210:
#endif
#ifdef F_129
F_131 ( & F_129 ) ;
V_209:
#endif
#ifdef F_127
F_132 ( & F_127 ) ;
V_208:
#endif
#ifdef F_125
F_133 ( & F_125 ) ;
V_207:
#endif
#ifdef F_123
F_131 ( & F_123 ) ;
V_206:
#endif
#ifdef F_23
F_134 ( V_202 ) ;
V_202 = NULL ;
V_205:
#endif
F_135 ( V_194 , & V_195 ) ;
return V_38 ;
}
static void T_6 F_136 ( void )
{
#ifdef F_130
F_131 ( & F_130 ) ;
#endif
#ifdef F_129
F_131 ( & F_129 ) ;
#endif
#ifdef F_123
F_131 ( & F_123 ) ;
#endif
#ifdef F_125
F_133 ( & F_125 ) ;
#endif
#ifdef F_127
F_132 ( & F_127 ) ;
#endif
#ifdef F_23
F_134 ( V_202 ) ;
#endif
F_135 ( V_194 , & V_195 ) ;
}
