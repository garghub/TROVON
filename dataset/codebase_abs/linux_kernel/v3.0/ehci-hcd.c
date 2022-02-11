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
V_9 = F_5 ( V_14 * V_15 , 1000 ) + 1 ;
break;
}
F_6 ( & V_2 -> V_5 , V_9 + V_16 ) ;
}
}
static int F_7 ( struct V_1 * V_2 , void T_1 * V_17 ,
T_2 V_18 , T_2 V_19 , int V_20 )
{
T_2 V_21 ;
do {
V_21 = F_8 ( V_2 , V_17 ) ;
if ( V_21 == ~ ( T_2 ) 0 )
return - V_22 ;
V_21 &= V_18 ;
if ( V_21 == V_19 )
return 0 ;
F_9 ( 1 ) ;
V_20 -- ;
} while ( V_20 > 0 );
return - V_23 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 T_1 * V_24 ;
T_2 V_25 ;
V_24 = ( T_2 T_1 * ) ( ( ( V_26 T_1 * ) V_2 -> V_27 ) + V_28 ) ;
V_25 = F_8 ( V_2 , V_24 ) ;
return ( V_25 & 3 ) == V_29 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 V_30 = F_8 ( V_2 , & V_2 -> V_27 -> V_31 ) ;
F_12 ( V_2 , 0 , & V_2 -> V_27 -> V_32 ) ;
if ( F_13 ( V_2 ) && F_10 ( V_2 ) == 0 ) {
return 0 ;
}
if ( ( V_30 & V_33 ) != 0 )
return 0 ;
V_30 = F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) ;
V_30 &= ~ V_35 ;
F_12 ( V_2 , V_30 , & V_2 -> V_27 -> V_34 ) ;
return F_7 ( V_2 , & V_2 -> V_27 -> V_31 ,
V_33 , V_33 , 16 * 125 ) ;
}
static int F_14 ( struct V_1 * V_2 , void T_1 * V_17 ,
T_2 V_18 , T_2 V_19 , int V_20 )
{
int error ;
error = F_7 ( V_2 , V_17 , V_18 , V_19 , V_20 ) ;
if ( error ) {
F_11 ( V_2 ) ;
F_15 ( V_2 ) -> V_36 = V_37 ;
F_16 ( V_2 , L_1 ,
V_17 , V_18 , V_19 , error ) ;
}
return error ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_2 T_1 * V_24 ;
T_2 V_25 ;
V_24 = ( T_2 T_1 * ) ( ( ( V_26 T_1 * ) V_2 -> V_27 ) + V_28 ) ;
V_25 = F_8 ( V_2 , V_24 ) ;
V_25 |= V_29 ;
if ( F_18 ( V_2 ) )
V_25 |= V_38 ;
F_12 ( V_2 , V_25 , V_24 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_39 ;
T_2 V_34 = F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) ;
if ( V_2 -> V_40 && ! F_20 () )
V_2 -> V_40 = NULL ;
V_34 |= V_41 ;
F_21 ( V_2 , L_2 , V_34 ) ;
F_12 ( V_2 , V_34 , & V_2 -> V_27 -> V_34 ) ;
F_15 ( V_2 ) -> V_36 = V_37 ;
V_2 -> V_42 = V_16 ;
V_39 = F_7 ( V_2 , & V_2 -> V_27 -> V_34 ,
V_41 , 0 , 250 * 1000 ) ;
if ( V_2 -> V_43 ) {
F_12 ( V_2 , V_44 | V_45 ,
( T_2 T_1 * ) ( ( ( V_26 * ) V_2 -> V_27 ) + V_46 ) ) ;
F_12 ( V_2 , V_47 ,
( T_2 T_1 * ) ( ( ( V_26 * ) V_2 -> V_27 ) + V_48 ) ) ;
}
if ( V_39 )
return V_39 ;
if ( F_13 ( V_2 ) )
F_17 ( V_2 ) ;
if ( V_2 -> V_40 )
F_22 () ;
return V_39 ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_2 V_30 ;
#ifdef F_24
if ( ! F_25 ( F_15 ( V_2 ) -> V_36 ) )
F_26 () ;
#endif
V_30 = F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) << 10 ;
V_30 &= V_49 | V_50 ;
if ( F_14 ( V_2 , & V_2 -> V_27 -> V_31 ,
V_49 | V_50 , V_30 , 16 * 125 ) )
return;
V_30 = F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) ;
V_30 &= ~ ( V_51 | V_52 | V_53 ) ;
F_12 ( V_2 , V_30 , & V_2 -> V_27 -> V_34 ) ;
F_14 ( V_2 , & V_2 -> V_27 -> V_31 ,
V_49 | V_50 , 0 , 16 * 125 ) ;
}
static void F_27 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
unsigned long V_55 ;
F_28 ( & V_2 -> V_56 , V_55 ) ;
if ( V_2 -> V_57
&& ! F_2 ( & V_2 -> V_58 )
&& F_25 ( F_15 ( V_2 ) -> V_36 ) ) {
T_2 V_59 , V_31 ;
V_59 = F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) ;
if ( V_59 & V_52 )
F_12 ( V_2 , V_59 & ~ V_52 ,
& V_2 -> V_27 -> V_34 ) ;
V_31 = F_8 ( V_2 , & V_2 -> V_27 -> V_31 ) ;
if ( ( V_31 & V_60 ) || ! ( V_59 & V_52 ) ) {
F_29 ( V_2 -> V_61 . V_62 ) ;
F_12 ( V_2 , V_60 , & V_2 -> V_27 -> V_31 ) ;
}
F_30 ( V_2 , L_3 ,
V_31 , V_59 ) ;
F_31 ( V_2 ) ;
}
F_32 ( & V_2 -> V_56 , V_55 ) ;
}
static void F_33 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
unsigned long V_55 ;
F_28 ( & V_2 -> V_56 , V_55 ) ;
if ( F_34 ( V_7 , & V_2 -> V_8 ) )
F_35 ( V_2 , V_2 -> V_63 ) ;
F_36 ( V_2 ) ;
F_32 ( & V_2 -> V_56 , V_55 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_64 = F_38 ( V_2 -> V_65 ) ;
while ( V_64 -- )
F_12 ( V_2 , V_66 ,
& V_2 -> V_27 -> V_67 [ V_64 ] ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_37 ( V_2 ) ;
F_12 ( V_2 , 0 , & V_2 -> V_27 -> V_68 ) ;
F_8 ( V_2 , & V_2 -> V_27 -> V_68 ) ;
}
static void F_40 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
F_42 ( & V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_58 ) ;
F_43 ( & V_2 -> V_56 ) ;
F_39 ( V_2 ) ;
F_44 ( & V_2 -> V_56 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_71 )
{
unsigned V_64 ;
if ( ! F_46 ( V_2 -> V_65 ) )
return;
F_47 ( V_2 , L_4 , V_71 ? L_5 : L_6 ) ;
for ( V_64 = F_38 ( V_2 -> V_65 ) ; V_64 > 0 ; )
( void ) F_48 ( F_15 ( V_2 ) ,
V_71 ? V_72 : V_73 ,
V_74 ,
V_64 -- , NULL , 0 ) ;
F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) ;
F_49 ( 20 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_50 ( V_2 , V_10 ) ;
if ( V_2 -> V_75 )
return;
V_2 -> V_75 = 1 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_76 != - 1 )
F_52 ( V_2 ) ;
V_2 -> V_75 = 0 ;
if ( F_25 ( F_15 ( V_2 ) -> V_36 ) &&
( V_2 -> V_63 -> V_77 . V_17 != NULL ||
V_2 -> V_78 != 0 ) )
F_1 ( V_2 , V_10 ) ;
}
static void F_53 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
F_47 ( V_2 , L_7 ) ;
F_42 ( & V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_58 ) ;
F_43 ( & V_2 -> V_56 ) ;
if ( F_25 ( V_70 -> V_36 ) )
F_23 ( V_2 ) ;
F_39 ( V_2 ) ;
F_19 ( V_2 ) ;
F_44 ( & V_2 -> V_56 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_43 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_63 )
F_36 ( V_2 ) ;
F_44 ( & V_2 -> V_56 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_79 == 1 )
F_57 () ;
#ifdef F_58
F_47 ( V_2 , L_8 ,
V_2 -> V_61 . V_80 , V_2 -> V_61 . error , V_2 -> V_61 . V_57 ,
V_2 -> V_61 . V_62 ) ;
F_47 ( V_2 , L_9 ,
V_2 -> V_61 . V_81 , V_2 -> V_61 . V_82 ) ;
#endif
F_59 ( V_2 , L_10 ,
F_8 ( V_2 , & V_2 -> V_27 -> V_31 ) ) ;
}
static int F_60 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
T_2 V_30 ;
int V_39 ;
T_2 V_83 ;
struct V_84 * V_85 ;
F_61 ( & V_2 -> V_56 ) ;
V_2 -> V_11 = 1 ;
F_62 ( & V_2 -> V_5 ) ;
V_2 -> V_5 . V_86 = F_33 ;
V_2 -> V_5 . V_87 = ( unsigned long ) V_2 ;
F_62 ( & V_2 -> V_58 ) ;
V_2 -> V_58 . V_86 = F_27 ;
V_2 -> V_58 . V_87 = ( unsigned long ) V_2 ;
V_83 = F_8 ( V_2 , & V_2 -> V_88 -> V_83 ) ;
V_2 -> V_89 = V_90 ;
F_63 ( & V_2 -> V_91 ) ;
F_63 ( & V_2 -> V_92 ) ;
if ( F_64 ( V_83 ) ) {
switch ( V_93 ) {
case 0 : V_2 -> V_89 = 1024 ; break;
case 1 : V_2 -> V_89 = 512 ; break;
case 2 : V_2 -> V_89 = 256 ; break;
default: F_26 () ;
}
}
if ( ( V_39 = F_65 ( V_2 , V_94 ) ) < 0 )
return V_39 ;
if ( F_66 ( V_83 ) )
V_2 -> V_95 = 2 + 8 ;
else
V_2 -> V_95 = 2 + F_67 ( V_83 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_76 = - 1 ;
V_2 -> V_96 = - 1 ;
V_2 -> V_63 -> V_77 . V_97 = NULL ;
V_85 = V_2 -> V_63 -> V_85 ;
V_85 -> V_98 = F_68 ( V_2 , V_2 -> V_63 -> V_99 ) ;
V_85 -> V_100 = F_69 ( V_2 , V_101 ) ;
V_85 -> V_102 = F_69 ( V_2 , V_103 ) ;
V_85 -> V_104 = F_70 ( V_2 ) ;
V_2 -> V_63 -> V_105 = V_106 ;
V_85 -> V_107 = F_71 ( V_2 , V_2 -> V_63 -> V_108 -> V_109 ) ;
if ( V_110 < 0 || V_110 > 6 )
V_110 = 0 ;
V_30 = 1 << ( 16 + V_110 ) ;
if ( F_72 ( V_83 ) ) {
V_2 -> V_111 = 1 ;
F_47 ( V_2 , L_11 ) ;
V_30 |= V_112 ;
}
if ( F_73 ( V_83 ) ) {
if ( V_113 ) {
V_113 = F_74 ( V_113 , ( unsigned ) 3 ) ;
V_30 |= V_114 ;
V_30 |= V_113 << 8 ;
}
F_47 ( V_2 , L_12 , V_113 ) ;
}
if ( F_64 ( V_83 ) ) {
V_30 &= ~ ( 3 << 2 ) ;
V_30 |= ( V_93 << 2 ) ;
}
if ( F_75 ( V_83 ) ) {
F_47 ( V_2 , L_13 ) ;
V_2 -> V_115 = 1 ;
if ( V_116 > 0xf ) {
F_47 ( V_2 , L_14 ,
V_116 ) ;
V_116 = 0 ;
}
V_30 |= V_116 << 24 ;
}
V_2 -> V_34 = V_30 ;
if ( ! ( V_70 -> V_117 -> V_55 & V_118 ) )
V_70 -> V_119 . V_120 = ~ 0 ;
return 0 ;
}
static int F_76 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
int V_39 ;
T_2 V_30 ;
T_2 V_83 ;
V_70 -> V_121 = 1 ;
if ( ! F_13 ( V_2 ) && ( V_39 = F_19 ( V_2 ) ) != 0 ) {
F_56 ( V_2 ) ;
return V_39 ;
}
F_12 ( V_2 , V_2 -> V_122 , & V_2 -> V_27 -> V_123 ) ;
F_12 ( V_2 , ( T_2 ) V_2 -> V_63 -> V_99 , & V_2 -> V_27 -> V_124 ) ;
V_83 = F_8 ( V_2 , & V_2 -> V_88 -> V_83 ) ;
if ( F_77 ( V_83 ) ) {
F_12 ( V_2 , 0 , & V_2 -> V_27 -> V_125 ) ;
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
V_2 -> V_34 &= ~ ( V_126 | V_52 | V_53 | V_51 | V_41 ) ;
V_2 -> V_34 |= V_35 ;
F_12 ( V_2 , V_2 -> V_34 , & V_2 -> V_27 -> V_34 ) ;
F_21 ( V_2 , L_15 , V_2 -> V_34 ) ;
F_78 ( & V_127 ) ;
V_70 -> V_36 = V_128 ;
F_12 ( V_2 , V_129 , & V_2 -> V_27 -> V_68 ) ;
F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) ;
F_49 ( 5 ) ;
F_79 ( & V_127 ) ;
V_2 -> V_130 = F_80 () ;
V_30 = F_81 ( V_2 , F_8 ( V_2 , & V_2 -> V_88 -> V_131 ) ) ;
F_82 ( V_2 ,
L_16 ,
( ( V_2 -> V_132 & 0xf0 ) >> 4 ) , ( V_2 -> V_132 & 0x0f ) ,
V_30 >> 8 , V_30 & 0xff ,
V_133 ? L_17 : L_18 ) ;
F_12 ( V_2 , V_134 ,
& V_2 -> V_27 -> V_32 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static T_3 F_85 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
T_2 V_31 , V_135 , V_136 = 0 , V_59 ;
int V_137 ;
F_86 ( & V_2 -> V_56 ) ;
V_31 = F_8 ( V_2 , & V_2 -> V_27 -> V_31 ) ;
if ( V_31 == ~ ( T_2 ) 0 ) {
F_47 ( V_2 , L_19 ) ;
goto V_138;
}
V_135 = V_31 & V_134 ;
if ( ! V_135 || F_87 ( V_70 -> V_36 == V_37 ) ) {
F_88 ( & V_2 -> V_56 ) ;
return V_139 ;
}
F_12 ( V_2 , V_135 , & V_2 -> V_27 -> V_31 ) ;
V_59 = F_8 ( V_2 , & V_2 -> V_27 -> V_34 ) ;
V_137 = 0 ;
#ifdef F_89
F_59 ( V_2 , L_20 , V_31 ) ;
#endif
if ( F_90 ( ( V_31 & ( V_140 | V_141 ) ) != 0 ) ) {
if ( F_90 ( ( V_31 & V_141 ) == 0 ) )
F_29 ( V_2 -> V_61 . V_80 ) ;
else
F_29 ( V_2 -> V_61 . error ) ;
V_137 = 1 ;
}
if ( V_31 & V_60 ) {
if ( V_59 & V_52 ) {
F_12 ( V_2 , V_59 & ~ V_52 ,
& V_2 -> V_27 -> V_34 ) ;
F_47 ( V_2 , L_21 ) ;
}
if ( V_2 -> V_57 ) {
F_29 ( V_2 -> V_61 . V_57 ) ;
F_31 ( V_2 ) ;
} else
F_47 ( V_2 , L_22 ) ;
}
if ( V_31 & V_142 ) {
unsigned V_143 = F_38 ( V_2 -> V_65 ) ;
T_2 V_144 = 0 ;
V_136 = V_31 ;
if ( ! ( V_59 & V_35 ) )
F_91 ( V_70 ) ;
if ( V_2 -> V_111 )
V_144 = V_31 >> 16 ;
while ( V_143 -- ) {
int V_145 ;
if ( V_2 -> V_111 && ! ( V_144 & ( 1 << V_143 ) ) )
continue;
V_145 = F_8 ( V_2 ,
& V_2 -> V_27 -> V_67 [ V_143 ] ) ;
if ( V_145 & V_146 )
continue;
if ( ! ( F_34 ( V_143 , & V_2 -> V_147 ) &&
( ( V_145 & V_148 ) ||
! ( V_145 & V_149 ) ) &&
( V_145 & V_150 ) &&
V_2 -> V_151 [ V_143 ] == 0 ) )
continue;
V_2 -> V_151 [ V_143 ] = V_16 + F_92 ( 25 ) ;
F_47 ( V_2 , L_23 , V_143 + 1 ) ;
F_6 ( & V_70 -> V_152 , V_2 -> V_151 [ V_143 ] ) ;
}
}
if ( F_87 ( ( V_31 & V_153 ) != 0 ) ) {
F_16 ( V_2 , L_24 ) ;
F_21 ( V_2 , L_25 , V_59 ) ;
F_59 ( V_2 , L_25 , V_31 ) ;
F_11 ( V_2 ) ;
V_138:
F_19 ( V_2 ) ;
F_12 ( V_2 , 0 , & V_2 -> V_27 -> V_68 ) ;
F_93 ( V_70 ) ;
V_137 = 1 ;
}
if ( V_137 )
F_36 ( V_2 ) ;
F_88 ( & V_2 -> V_56 ) ;
if ( V_136 )
F_94 ( V_70 ) ;
return V_154 ;
}
static int F_95 (
struct V_69 * V_70 ,
struct V_155 * V_155 ,
T_4 V_156
) {
struct V_1 * V_2 = F_41 ( V_70 ) ;
struct V_157 V_158 ;
F_63 ( & V_158 ) ;
switch ( F_96 ( V_155 -> V_159 ) ) {
case V_160 :
if ( V_155 -> V_161 > ( 16 * 1024 ) )
return - V_162 ;
default:
if ( ! F_97 ( V_2 , V_155 , & V_158 , V_156 ) )
return - V_163 ;
return F_98 ( V_2 , V_155 , & V_158 , V_156 ) ;
case V_164 :
if ( ! F_97 ( V_2 , V_155 , & V_158 , V_156 ) )
return - V_163 ;
return F_99 ( V_2 , V_155 , & V_158 , V_156 ) ;
case V_165 :
if ( V_155 -> V_166 -> V_167 == V_168 )
return F_100 ( V_2 , V_155 , V_156 ) ;
else
return F_101 ( V_2 , V_155 , V_156 ) ;
}
}
static void F_102 ( struct V_1 * V_2 , struct V_169 * V_97 )
{
if ( ! F_25 ( F_15 ( V_2 ) -> V_36 ) && V_2 -> V_57 )
F_31 ( V_2 ) ;
if ( V_97 -> V_105 != V_106 ) {
if ( V_97 -> V_105 == V_170 )
V_97 -> V_171 = 1 ;
return;
}
if ( V_2 -> V_57 ) {
struct V_169 * V_172 ;
for ( V_172 = V_2 -> V_57 ;
V_172 -> V_57 ;
V_172 = V_172 -> V_57 )
continue;
V_97 -> V_105 = V_173 ;
V_172 -> V_57 = V_97 ;
} else
F_35 ( V_2 , V_97 ) ;
}
static int F_103 ( struct V_69 * V_70 , struct V_155 * V_155 , int V_31 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
struct V_169 * V_97 ;
unsigned long V_55 ;
int V_174 ;
F_28 ( & V_2 -> V_56 , V_55 ) ;
V_174 = F_104 ( V_70 , V_155 , V_31 ) ;
if ( V_174 )
goto V_19;
switch ( F_96 ( V_155 -> V_159 ) ) {
default:
V_97 = (struct V_169 * ) V_155 -> V_175 ;
if ( ! V_97 )
break;
switch ( V_97 -> V_105 ) {
case V_106 :
case V_170 :
F_102 ( V_2 , V_97 ) ;
break;
case V_176 :
case V_173 :
break;
case V_177 :
F_105 ( V_2 , V_97 ) ;
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
F_106 ( V_2 , V_97 ) ;
break;
case V_177 :
F_105 ( V_2 , V_97 ) ;
break;
default:
F_47 ( V_2 , L_26 ,
V_97 , V_97 -> V_105 ) ;
goto V_19;
}
break;
case V_165 :
break;
}
V_19:
F_32 ( & V_2 -> V_56 , V_55 ) ;
return V_174 ;
}
static void
F_107 ( struct V_69 * V_70 , struct V_178 * V_179 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
unsigned long V_55 ;
struct V_169 * V_97 , * V_25 ;
V_180:
F_28 ( & V_2 -> V_56 , V_55 ) ;
V_97 = V_179 -> V_175 ;
if ( ! V_97 )
goto V_19;
if ( V_97 -> V_85 == NULL ) {
F_30 ( V_2 , L_27 ) ;
goto V_181;
}
if ( ! F_25 ( V_70 -> V_36 ) )
V_97 -> V_105 = V_177 ;
switch ( V_97 -> V_105 ) {
case V_106 :
case V_170 :
for ( V_25 = V_2 -> V_63 -> V_77 . V_97 ;
V_25 && V_25 != V_97 ;
V_25 = V_25 -> V_77 . V_97 )
continue;
if ( V_25 )
F_102 ( V_2 , V_97 ) ;
case V_176 :
case V_173 :
V_181:
F_32 ( & V_2 -> V_56 , V_55 ) ;
F_108 ( 1 ) ;
goto V_180;
case V_177 :
if ( V_97 -> V_182 )
goto V_181;
if ( F_109 ( & V_97 -> V_158 ) ) {
F_110 ( V_97 ) ;
break;
}
default:
F_16 ( V_2 , L_28 ,
V_97 , V_179 -> V_183 . V_184 , V_97 -> V_105 ,
F_109 ( & V_97 -> V_158 ) ? L_18 : L_29 ) ;
break;
}
V_179 -> V_175 = NULL ;
V_19:
F_32 ( & V_2 -> V_56 , V_55 ) ;
}
static void
F_111 ( struct V_69 * V_70 , struct V_178 * V_179 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
struct V_169 * V_97 ;
int V_185 = F_112 ( & V_179 -> V_183 ) ;
int V_186 = F_113 ( & V_179 -> V_183 ) ;
int V_187 = F_114 ( & V_179 -> V_183 ) ;
unsigned long V_55 ;
if ( V_185 != V_188 && V_185 != V_189 )
return;
F_28 ( & V_2 -> V_56 , V_55 ) ;
V_97 = V_179 -> V_175 ;
if ( V_97 ) {
F_115 ( V_97 -> V_166 , V_186 , V_187 , 0 ) ;
if ( ! F_109 ( & V_97 -> V_158 ) ) {
F_116 ( 1 , L_30 ) ;
} else if ( V_97 -> V_105 == V_106 ||
V_97 -> V_105 == V_170 ) {
if ( V_185 == V_188 )
F_102 ( V_2 , V_97 ) ;
else
F_106 ( V_2 , V_97 ) ;
}
}
F_32 ( & V_2 -> V_56 , V_55 ) ;
}
static int F_117 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_41 ( V_70 ) ;
return ( F_8 ( V_2 , & V_2 -> V_27 -> V_190 ) >> 3 ) %
V_2 -> V_89 ;
}
static int T_5 F_118 ( void )
{
int V_39 = 0 ;
if ( F_119 () )
return - V_22 ;
F_120 ( V_191 L_31 V_192 L_32 , V_193 ) ;
F_121 ( V_194 , & V_195 ) ;
if ( F_34 ( V_196 , & V_195 ) ||
F_34 ( V_197 , & V_195 ) )
F_120 ( V_198 L_33
L_34 ) ;
F_122 ( L_35 ,
V_193 ,
sizeof( struct V_169 ) , sizeof( struct V_199 ) ,
sizeof( struct V_200 ) , sizeof( struct V_201 ) ) ;
#ifdef F_24
V_202 = F_123 ( L_36 , V_203 ) ;
if ( ! V_202 ) {
V_39 = - V_204 ;
goto V_205;
}
#endif
#ifdef F_124
V_39 = F_125 ( & F_124 ) ;
if ( V_39 < 0 )
goto V_206;
#endif
#ifdef F_126
V_39 = F_127 ( & F_126 ) ;
if ( V_39 < 0 )
goto V_207;
#endif
#ifdef F_128
V_39 = F_129 ( & F_128 ) ;
if ( V_39 < 0 )
goto V_208;
#endif
#ifdef F_130
V_39 = F_125 ( & F_130 ) ;
if ( V_39 < 0 )
goto V_209;
#endif
#ifdef F_131
V_39 = F_125 ( & F_131 ) ;
if ( V_39 < 0 )
goto V_210;
#endif
return V_39 ;
#ifdef F_131
V_210:
#endif
#ifdef F_130
F_132 ( & F_130 ) ;
V_209:
#endif
#ifdef F_128
F_133 ( & F_128 ) ;
V_208:
#endif
#ifdef F_126
F_134 ( & F_126 ) ;
V_207:
#endif
#ifdef F_124
F_132 ( & F_124 ) ;
V_206:
#endif
#ifdef F_24
F_135 ( V_202 ) ;
V_202 = NULL ;
V_205:
#endif
F_136 ( V_194 , & V_195 ) ;
return V_39 ;
}
static void T_6 F_137 ( void )
{
#ifdef F_131
F_132 ( & F_131 ) ;
#endif
#ifdef F_130
F_132 ( & F_130 ) ;
#endif
#ifdef F_124
F_132 ( & F_124 ) ;
#endif
#ifdef F_126
F_134 ( & F_126 ) ;
#endif
#ifdef F_128
F_133 ( & F_128 ) ;
#endif
#ifdef F_24
F_135 ( V_202 ) ;
#endif
F_136 ( V_194 , & V_195 ) ;
}
