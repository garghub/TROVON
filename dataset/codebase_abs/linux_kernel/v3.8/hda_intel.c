static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
if ( F_2 ( V_2 ) )
return;
if ( ! V_4 || ! V_4 -> V_7 || ! V_4 -> V_8 )
return;
#ifdef F_3
if ( V_4 -> V_9 . type == V_10 ) {
struct V_11 * V_12 = V_4 -> V_13 ;
if ( V_5 )
F_4 ( V_12 -> V_14 , V_12 -> V_6 ) ;
else
F_5 ( V_12 -> V_14 , V_12 -> V_6 ) ;
return;
}
#endif
V_6 = ( V_4 -> V_8 + V_15 - 1 ) >> V_16 ;
if ( V_5 )
F_6 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
else
F_7 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_17 ,
bool V_5 )
{
F_1 ( V_2 , V_17 , V_5 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_18 * V_18 ,
struct V_19 * V_20 , bool V_5 )
{
if ( V_18 -> V_21 != V_5 ) {
F_1 ( V_2 , F_10 ( V_20 ) , V_5 ) ;
V_18 -> V_21 = V_5 ;
}
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_17 ,
bool V_5 )
{
}
static inline void F_9 ( struct V_1 * V_2 , struct V_18 * V_18 ,
struct V_19 * V_20 , bool V_5 )
{
}
static int F_11 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_15 , & V_2 -> V_25 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_1 , pci_name(chip->pci)) ;
return V_22 ;
}
F_8 ( V_2 , & V_2 -> V_25 , true ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_26 ) ;
V_2 -> V_27 . V_28 = V_2 -> V_25 . V_28 ;
V_2 -> V_27 . V_17 = ( V_29 * ) V_2 -> V_25 . V_7 ;
F_17 ( V_2 , V_30 , ( V_29 ) V_2 -> V_27 . V_28 ) ;
F_17 ( V_2 , V_31 , F_18 ( V_2 -> V_27 . V_28 ) ) ;
F_19 ( V_2 , V_32 , 0x02 ) ;
F_20 ( V_2 , V_33 , 0 ) ;
F_20 ( V_2 , V_34 , V_35 ) ;
F_19 ( V_2 , V_36 , V_37 ) ;
V_2 -> V_38 . V_28 = V_2 -> V_25 . V_28 + 2048 ;
V_2 -> V_38 . V_17 = ( V_29 * ) ( V_2 -> V_25 . V_7 + 2048 ) ;
V_2 -> V_38 . V_39 = V_2 -> V_38 . V_40 = 0 ;
memset ( V_2 -> V_38 . V_41 , 0 , sizeof( V_2 -> V_38 . V_41 ) ) ;
F_17 ( V_2 , V_42 , ( V_29 ) V_2 -> V_38 . V_28 ) ;
F_17 ( V_2 , V_43 , F_18 ( V_2 -> V_38 . V_28 ) ) ;
F_19 ( V_2 , V_44 , 0x02 ) ;
F_20 ( V_2 , V_45 , V_46 ) ;
if ( V_2 -> V_47 & V_48 )
F_20 ( V_2 , V_49 , 0xc0 ) ;
else
F_20 ( V_2 , V_49 , 1 ) ;
F_19 ( V_2 , V_50 , V_51 | V_52 ) ;
F_21 ( & V_2 -> V_26 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_26 ) ;
F_19 ( V_2 , V_50 , 0 ) ;
F_19 ( V_2 , V_36 , 0 ) ;
F_21 ( & V_2 -> V_26 ) ;
}
static unsigned int F_23 ( V_29 V_53 )
{
unsigned int V_28 = V_53 >> 28 ;
if ( V_28 >= V_54 ) {
F_24 () ;
V_28 = 0 ;
}
return V_28 ;
}
static unsigned int F_25 ( V_29 V_55 )
{
unsigned int V_28 = V_55 & 0xf ;
if ( V_28 >= V_54 ) {
F_24 () ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_26 ( struct V_56 * V_57 , V_29 V_58 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
unsigned int V_28 = F_23 ( V_58 ) ;
unsigned int V_39 ;
F_16 ( & V_2 -> V_26 ) ;
V_39 = F_27 ( V_2 , V_33 ) ;
if ( V_39 == 0xffff ) {
F_21 ( & V_2 -> V_26 ) ;
return - 1 ;
}
V_39 ++ ;
V_39 %= V_59 ;
V_2 -> V_38 . V_41 [ V_28 ] ++ ;
V_2 -> V_27 . V_17 [ V_39 ] = F_28 ( V_58 ) ;
F_17 ( V_2 , V_33 , V_39 ) ;
F_21 ( & V_2 -> V_26 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned int V_40 , V_39 ;
unsigned int V_28 ;
V_29 V_55 , V_60 ;
V_39 = F_27 ( V_2 , V_45 ) ;
if ( V_39 == 0xffff ) {
return;
}
if ( V_39 == V_2 -> V_38 . V_39 )
return;
V_2 -> V_38 . V_39 = V_39 ;
while ( V_2 -> V_38 . V_40 != V_39 ) {
V_2 -> V_38 . V_40 ++ ;
V_2 -> V_38 . V_40 %= V_61 ;
V_40 = V_2 -> V_38 . V_40 << 1 ;
V_60 = F_30 ( V_2 -> V_38 . V_17 [ V_40 + 1 ] ) ;
V_55 = F_30 ( V_2 -> V_38 . V_17 [ V_40 ] ) ;
V_28 = F_25 ( V_60 ) ;
if ( V_60 & V_62 )
F_31 ( V_2 -> V_57 , V_55 , V_60 ) ;
else if ( V_2 -> V_38 . V_41 [ V_28 ] ) {
V_2 -> V_38 . V_55 [ V_28 ] = V_55 ;
F_32 () ;
V_2 -> V_38 . V_41 [ V_28 ] -- ;
} else
F_14 (KERN_ERR SFX L_2
L_3 ,
pci_name(chip->pci),
res, res_ex,
chip->last_cmd[addr]) ;
}
}
static unsigned int F_33 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
unsigned long V_63 ;
unsigned long V_64 ;
int V_65 = 0 ;
V_66:
V_63 = V_67 + F_34 ( 1000 ) ;
for ( V_64 = 0 ; ; V_64 ++ ) {
if ( V_2 -> V_68 || V_65 ) {
F_16 ( & V_2 -> V_26 ) ;
F_29 ( V_2 ) ;
F_21 ( & V_2 -> V_26 ) ;
}
if ( ! V_2 -> V_38 . V_41 [ V_28 ] ) {
F_35 () ;
V_57 -> V_69 = 0 ;
if ( ! V_65 )
V_2 -> V_70 = 0 ;
return V_2 -> V_38 . V_55 [ V_28 ] ;
}
if ( F_36 ( V_67 , V_63 ) )
break;
if ( V_57 -> V_71 || V_64 > 3000 )
F_37 ( 2 ) ;
else {
F_38 ( 10 ) ;
F_39 () ;
}
}
if ( ! V_2 -> V_68 && V_2 -> V_70 < 2 ) {
F_40 ( V_72 L_4
L_5 ,
F_41 ( V_2 -> V_24 ) , V_2 -> V_73 [ V_28 ] ) ;
V_65 = 1 ;
V_2 -> V_70 ++ ;
goto V_66;
}
if ( ! V_2 -> V_68 ) {
F_14 (KERN_WARNING SFX L_4
L_6 ,
pci_name(chip->pci), chip->last_cmd[addr]) ;
V_2 -> V_68 = 1 ;
goto V_66;
}
if ( V_2 -> V_74 ) {
F_14 (KERN_WARNING SFX L_7
L_8 ,
pci_name(chip->pci), chip->last_cmd[addr]) ;
F_42 ( V_2 -> V_75 , V_2 ) ;
V_2 -> V_75 = - 1 ;
F_43 ( V_2 -> V_24 ) ;
V_2 -> V_74 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 ) {
V_57 -> V_69 = 1 ;
return - 1 ;
}
goto V_66;
}
if ( V_2 -> V_76 ) {
return - 1 ;
}
V_57 -> V_69 = 1 ;
if ( V_57 -> V_77 && ! V_57 -> V_78 && ! V_57 -> V_79 ) {
V_57 -> V_78 = 1 ;
return - 1 ;
}
F_14 ( V_80 L_9
L_10 ,
V_2 -> V_73 [ V_28 ] ) ;
V_2 -> V_81 = 1 ;
V_57 -> V_78 = 0 ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_82 , F_45 ( V_2 , V_82 ) & ~ V_83 ) ;
return - 1 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_63 = 50 ;
while ( V_63 -- ) {
if ( F_27 ( V_2 , V_84 ) & V_85 ) {
V_2 -> V_38 . V_55 [ V_28 ] = F_45 ( V_2 , V_86 ) ;
return 0 ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_72 L_11 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_84 ) ) ;
V_2 -> V_38 . V_55 [ V_28 ] = - 1 ;
return - V_87 ;
}
static int F_49 ( struct V_56 * V_57 , V_29 V_58 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
unsigned int V_28 = F_23 ( V_58 ) ;
int V_63 = 50 ;
V_57 -> V_69 = 0 ;
while ( V_63 -- ) {
if ( ! ( ( F_27 ( V_2 , V_84 ) & V_88 ) ) ) {
F_20 ( V_2 , V_84 , F_27 ( V_2 , V_84 ) |
V_85 ) ;
F_17 ( V_2 , V_89 , V_58 ) ;
F_20 ( V_2 , V_84 , F_27 ( V_2 , V_84 ) |
V_88 ) ;
return F_46 ( V_2 , V_28 ) ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_72 L_12 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_84 ) , V_58 ) ;
return - V_87 ;
}
static unsigned int F_50 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
return V_2 -> V_38 . V_55 [ V_28 ] ;
}
static int F_51 ( struct V_56 * V_57 , unsigned int V_58 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( V_2 -> V_90 )
return 0 ;
V_2 -> V_73 [ F_23 ( V_58 ) ] = V_58 ;
if ( V_2 -> V_81 )
return F_49 ( V_57 , V_58 ) ;
else
return F_26 ( V_57 , V_58 ) ;
}
static unsigned int F_52 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( V_2 -> V_90 )
return 0 ;
if ( V_2 -> V_81 )
return F_50 ( V_57 , V_28 ) ;
else
return F_33 ( V_57 , V_28 ) ;
}
static int F_53 ( struct V_1 * V_2 , int V_91 )
{
unsigned long V_63 ;
if ( ! V_91 )
goto V_92;
F_19 ( V_2 , V_93 , V_94 ) ;
F_17 ( V_2 , V_82 , F_45 ( V_2 , V_82 ) & ~ V_95 ) ;
V_63 = V_67 + F_34 ( 100 ) ;
while ( F_54 ( V_2 , V_82 ) &&
F_55 ( V_67 , V_63 ) )
F_56 ( 500 , 1000 ) ;
F_56 ( 500 , 1000 ) ;
F_19 ( V_2 , V_82 , F_54 ( V_2 , V_82 ) | V_95 ) ;
V_63 = V_67 + F_34 ( 100 ) ;
while ( ! F_54 ( V_2 , V_82 ) &&
F_55 ( V_67 , V_63 ) )
F_56 ( 500 , 1000 ) ;
F_56 ( 1000 , 1200 ) ;
V_92:
if ( ! F_54 ( V_2 , V_82 ) ) {
F_48 ( V_72 L_13 , F_41 ( V_2 -> V_24 ) ) ;
return - V_96 ;
}
if ( ! V_2 -> V_81 )
F_17 ( V_2 , V_82 , F_45 ( V_2 , V_82 ) |
V_83 ) ;
if ( ! V_2 -> V_97 ) {
V_2 -> V_97 = F_27 ( V_2 , V_93 ) ;
F_40 ( V_72 L_14 , F_41 ( V_2 -> V_24 ) , V_2 -> V_97 ) ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_98 , F_45 ( V_2 , V_98 ) |
V_99 | V_100 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_101 ] ;
F_59 ( V_18 , V_103 ,
F_60 ( V_18 , V_103 ) & ~ V_104 ) ;
}
F_19 ( V_2 , V_98 , 0 ) ;
F_17 ( V_2 , V_98 , F_45 ( V_2 , V_98 ) &
~ ( V_99 | V_100 ) ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_101 ] ;
F_59 ( V_18 , V_105 , V_104 ) ;
}
F_19 ( V_2 , V_93 , V_94 ) ;
F_19 ( V_2 , V_106 , V_107 ) ;
F_17 ( V_2 , V_108 , V_99 | V_109 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_18 -> V_110 = 1 ;
F_17 ( V_2 , V_98 ,
F_45 ( V_2 , V_98 ) | ( 1 << V_18 -> V_111 ) ) ;
F_59 ( V_18 , V_103 , F_60 ( V_18 , V_103 ) |
V_112 | V_104 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_59 ( V_18 , V_103 , F_60 ( V_18 , V_103 ) &
~ ( V_112 | V_104 ) ) ;
F_59 ( V_18 , V_105 , V_104 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_63 ( V_2 , V_18 ) ;
F_17 ( V_2 , V_98 ,
F_45 ( V_2 , V_98 ) & ~ ( 1 << V_18 -> V_111 ) ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_91 )
{
if ( V_2 -> V_113 )
return;
F_53 ( V_2 , V_91 ) ;
F_61 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( ! V_2 -> V_81 )
F_15 ( V_2 ) ;
F_17 ( V_2 , V_114 , ( V_29 ) V_2 -> V_115 . V_28 ) ;
F_17 ( V_2 , V_116 , F_18 ( V_2 -> V_115 . V_28 ) ) ;
V_2 -> V_113 = 1 ;
}
static void F_66 ( struct V_117 * V_24 , unsigned int V_118 ,
unsigned char V_119 , unsigned char V_58 )
{
unsigned char V_120 ;
F_67 ( V_24 , V_118 , & V_120 ) ;
V_120 &= ~ V_119 ;
V_120 |= ( V_58 & V_119 ) ;
F_68 ( V_24 , V_118 , V_120 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_47 & V_121 ) ) {
F_40 ( V_72 L_15 , F_41 ( V_2 -> V_24 ) ) ;
F_66 ( V_2 -> V_24 , V_122 , 0x07 , 0 ) ;
}
if ( V_2 -> V_47 & V_123 ) {
F_40 ( V_72 L_16 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_66 ( V_2 -> V_24 ,
V_124 , 0x07 ,
F_2 ( V_2 ) ? V_125 : 0 ) ;
}
if ( V_2 -> V_47 & V_126 ) {
F_40 ( V_72 L_17 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_66 ( V_2 -> V_24 ,
V_127 ,
0x0f , V_128 ) ;
F_66 ( V_2 -> V_24 ,
V_129 ,
0x01 , V_130 ) ;
F_66 ( V_2 -> V_24 ,
V_131 ,
0x01 , V_130 ) ;
}
if ( V_2 -> V_47 & V_132 ) {
unsigned short V_133 ;
F_70 ( V_2 -> V_24 , V_134 , & V_133 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_133 & V_135 ) ) ||
( F_2 ( V_2 ) && ( V_133 & V_135 ) ) ) {
V_133 &= ~ V_135 ;
if ( ! F_2 ( V_2 ) )
V_133 |= V_135 ;
F_71 ( V_2 -> V_24 , V_134 , V_133 ) ;
F_70 ( V_2 -> V_24 ,
V_134 , & V_133 ) ;
}
F_40 ( V_72 L_18 ,
F_41 ( V_2 -> V_24 ) , ( V_133 & V_135 )
? L_19 : L_20 ) ;
}
}
static T_1 F_72 ( int V_75 , void * V_136 )
{
struct V_1 * V_2 = V_136 ;
struct V_18 * V_18 ;
V_29 V_137 ;
T_2 V_138 ;
int V_101 , V_139 ;
#ifdef F_73
if ( V_2 -> V_24 -> V_9 . V_140 . V_141 != V_142 )
return V_143 ;
#endif
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_90 ) {
F_75 ( & V_2 -> V_26 ) ;
return V_143 ;
}
V_137 = F_45 ( V_2 , V_108 ) ;
if ( V_137 == 0 ) {
F_75 ( & V_2 -> V_26 ) ;
return V_143 ;
}
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
V_18 = & V_2 -> V_18 [ V_101 ] ;
if ( V_137 & V_18 -> V_144 ) {
V_138 = F_60 ( V_18 , V_105 ) ;
F_59 ( V_18 , V_105 , V_104 ) ;
if ( ! V_18 -> V_20 || ! V_18 -> V_145 ||
! ( V_138 & V_146 ) )
continue;
V_139 = F_76 ( V_2 , V_18 ) ;
if ( V_139 == 1 ) {
V_18 -> V_147 = 0 ;
F_75 ( & V_2 -> V_26 ) ;
F_77 ( V_18 -> V_20 ) ;
F_74 ( & V_2 -> V_26 ) ;
} else if ( V_139 == 0 && V_2 -> V_57 && V_2 -> V_57 -> V_148 ) {
V_18 -> V_147 = 1 ;
F_78 ( V_2 -> V_57 -> V_148 ,
& V_2 -> V_149 ) ;
}
}
}
V_137 = F_54 ( V_2 , V_106 ) ;
if ( V_137 & V_107 ) {
if ( V_137 & V_150 ) {
if ( V_2 -> V_47 & V_151 )
F_38 ( 80 ) ;
F_29 ( V_2 ) ;
}
F_19 ( V_2 , V_106 , V_107 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_75 ( & V_2 -> V_26 ) ;
return V_152 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_18 * V_18 , V_29 * * V_153 ,
int V_154 , int V_155 , int V_156 )
{
V_29 * V_157 = * V_153 ;
while ( V_155 > 0 ) {
T_3 V_28 ;
int V_158 ;
if ( V_18 -> V_159 >= V_160 )
return - V_161 ;
V_28 = F_80 ( V_20 , V_154 ) ;
V_157 [ 0 ] = F_28 ( ( V_29 ) V_28 ) ;
V_157 [ 1 ] = F_28 ( F_18 ( V_28 ) ) ;
V_158 = F_81 ( V_20 , V_154 , V_155 ) ;
if ( V_2 -> V_47 & V_162 ) {
V_29 V_163 = 0x1000 - ( V_154 & 0xfff ) ;
if ( V_158 > V_163 )
V_158 = V_163 ;
}
V_157 [ 2 ] = F_28 ( V_158 ) ;
V_155 -= V_158 ;
V_157 [ 3 ] = ( V_155 || ! V_156 ) ? 0 : F_28 ( 0x01 ) ;
V_157 += 4 ;
V_18 -> V_159 ++ ;
V_154 += V_158 ;
}
* V_153 = V_157 ;
return V_154 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_18 * V_18 )
{
V_29 * V_157 ;
int V_101 , V_154 , V_164 , V_165 ;
int V_166 ;
F_83 ( V_18 , V_167 , 0 ) ;
F_83 ( V_18 , V_168 , 0 ) ;
V_165 = V_18 -> V_165 ;
V_164 = V_18 -> V_169 / V_165 ;
V_157 = ( V_29 * ) V_18 -> V_157 . V_7 ;
V_154 = 0 ;
V_18 -> V_159 = 0 ;
V_166 = V_170 [ V_2 -> V_171 ] ;
if ( ! V_18 -> V_172 && V_166 > 0 ) {
struct V_173 * V_174 = V_20 -> V_174 ;
int V_175 = V_166 ;
V_166 = ( V_166 * V_174 -> V_176 + 47999 ) / 48000 ;
if ( ! V_166 )
V_166 = V_175 ;
else
V_166 = ( ( V_166 + V_175 - 1 ) / V_175 ) *
V_175 ;
V_166 = F_84 ( V_174 , V_166 ) ;
if ( V_166 >= V_165 ) {
F_14 (KERN_WARNING SFX L_21 ,
pci_name(chip->pci), bdl_pos_adj[chip->dev_index]) ;
V_166 = 0 ;
} else {
V_154 = F_79 ( V_2 , V_20 , V_18 ,
& V_157 , V_154 , V_166 , true ) ;
if ( V_154 < 0 )
goto error;
}
} else
V_166 = 0 ;
for ( V_101 = 0 ; V_101 < V_164 ; V_101 ++ ) {
if ( V_101 == V_164 - 1 && V_166 )
V_154 = F_79 ( V_2 , V_20 , V_18 , & V_157 , V_154 ,
V_165 - V_166 , 0 ) ;
else
V_154 = F_79 ( V_2 , V_20 , V_18 , & V_157 , V_154 ,
V_165 ,
! V_18 -> V_172 ) ;
if ( V_154 < 0 )
goto error;
}
return 0 ;
error:
F_14 (KERN_ERR SFX L_22 ,
pci_name(chip->pci), azx_dev->bufsize, period_bytes) ;
return - V_161 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned char V_58 ;
int V_63 ;
F_63 ( V_2 , V_18 ) ;
F_59 ( V_18 , V_103 , F_60 ( V_18 , V_103 ) |
V_177 ) ;
F_38 ( 3 ) ;
V_63 = 300 ;
while ( ! ( ( V_58 = F_60 ( V_18 , V_103 ) ) & V_177 ) &&
-- V_63 )
;
V_58 &= ~ V_177 ;
F_59 ( V_18 , V_103 , V_58 ) ;
F_38 ( 3 ) ;
V_63 = 300 ;
while ( ( ( V_58 = F_60 ( V_18 , V_103 ) ) & V_177 ) &&
-- V_63 )
;
* V_18 -> V_115 = 0 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned int V_58 ;
F_63 ( V_2 , V_18 ) ;
V_58 = F_87 ( V_18 , V_103 ) ;
V_58 = ( V_58 & ~ V_178 ) |
( V_18 -> V_179 << V_180 ) ;
if ( ! F_2 ( V_2 ) )
V_58 |= V_181 ;
F_83 ( V_18 , V_103 , V_58 ) ;
F_83 ( V_18 , V_182 , V_18 -> V_169 ) ;
F_88 ( V_18 , V_183 , V_18 -> V_184 ) ;
F_88 ( V_18 , V_185 , V_18 -> V_159 - 1 ) ;
F_83 ( V_18 , V_167 , ( V_29 ) V_18 -> V_157 . V_28 ) ;
F_83 ( V_18 , V_168 , F_18 ( V_18 -> V_157 . V_28 ) ) ;
if ( V_2 -> V_186 [ 0 ] != V_187 ||
V_2 -> V_186 [ 1 ] != V_187 ) {
if ( ! ( F_45 ( V_2 , V_114 ) & V_188 ) )
F_17 ( V_2 , V_114 ,
( V_29 ) V_2 -> V_115 . V_28 | V_188 ) ;
}
F_83 ( V_18 , V_103 ,
F_87 ( V_18 , V_103 ) | V_104 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_53 = ( V_28 << 28 ) | ( V_189 << 20 ) |
( V_190 << 8 ) | V_191 ;
unsigned int V_55 ;
F_90 ( & V_2 -> V_57 -> V_192 ) ;
V_2 -> V_76 = 1 ;
F_51 ( V_2 -> V_57 , V_53 ) ;
V_55 = F_52 ( V_2 -> V_57 , V_28 ) ;
V_2 -> V_76 = 0 ;
F_91 ( & V_2 -> V_57 -> V_192 ) ;
if ( V_55 == - 1 )
return - V_87 ;
F_40 ( V_72 L_23 , F_41 ( V_2 -> V_24 ) , V_28 ) ;
return 0 ;
}
static void F_92 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
V_57 -> V_79 = 1 ;
F_93 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
#ifdef F_94
if ( V_2 -> V_113 ) {
struct V_193 * V_194 ;
F_95 (p, &chip->pcm_list, list)
F_96 ( V_194 -> V_195 ) ;
F_97 ( V_2 -> V_57 ) ;
F_98 ( V_2 -> V_57 ) ;
}
#endif
V_57 -> V_79 = 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_101 = V_196 [ V_2 -> V_171 ] ;
unsigned int V_197 ;
if ( V_101 == 0 )
return 0 ;
if ( V_101 < 50 || V_101 > 60000 )
V_197 = 0 ;
else
V_197 = F_34 ( V_101 ) ;
if ( V_197 == 0 )
F_14 (KERN_WARNING SFX
L_24 , i) ;
return V_197 ;
}
static int F_100 ( struct V_1 * V_2 , const char * V_198 )
{
struct V_199 V_200 ;
int V_201 , V_202 , V_22 ;
int V_203 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_13 = V_2 ;
V_200 . V_204 = V_198 ;
V_200 . V_24 = V_2 -> V_24 ;
V_200 . V_205 . V_206 = F_51 ;
V_200 . V_205 . V_207 = F_52 ;
V_200 . V_205 . V_208 = V_209 ;
V_200 . V_205 . V_210 = F_92 ;
#ifdef F_94
V_200 . V_211 = & V_211 ;
V_200 . V_205 . V_212 = V_213 ;
#endif
V_22 = F_101 ( V_2 -> V_214 , & V_200 , & V_2 -> V_57 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_2 -> V_47 & V_215 ) {
F_48 ( V_72 L_25 , F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_71 = 1 ;
}
V_202 = 0 ;
V_203 = V_216 [ V_2 -> V_217 ] ;
if ( ! V_203 )
V_203 = V_218 ;
for ( V_201 = 0 ; V_201 < V_203 ; V_201 ++ ) {
if ( ( V_2 -> V_97 & ( 1 << V_201 ) ) & V_2 -> V_219 ) {
if ( F_89 ( V_2 , V_201 ) < 0 ) {
F_14 (KERN_WARNING SFX
L_26
L_27 , pci_name(chip->pci), c) ;
V_2 -> V_97 &= ~ ( 1 << V_201 ) ;
F_93 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_47 & V_220 ) {
F_48 ( V_72 L_28 ,
F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_221 = 1 ;
V_2 -> V_57 -> V_77 = 1 ;
}
for ( V_201 = 0 ; V_201 < V_203 ; V_201 ++ ) {
if ( ( V_2 -> V_97 & ( 1 << V_201 ) ) & V_2 -> V_219 ) {
struct V_222 * V_223 ;
V_22 = F_102 ( V_2 -> V_57 , V_201 , & V_223 ) ;
if ( V_22 < 0 )
continue;
V_223 -> V_224 = F_99 ( V_2 ) ;
V_223 -> V_225 = V_2 -> V_225 ;
V_202 ++ ;
}
}
if ( ! V_202 ) {
F_14 (KERN_ERR SFX L_29 , pci_name(chip->pci)) ;
return - V_226 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_222 * V_223 ;
F_95 (codec, &chip->bus->codec_list, list) {
F_104 ( V_223 ) ;
}
return 0 ;
}
static inline struct V_18 *
F_105 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_9 , V_101 , V_227 ;
struct V_18 * V_55 = NULL ;
int V_228 = ( V_20 -> V_195 -> V_229 << 16 ) | ( V_20 -> V_230 << 2 ) |
( V_20 -> V_231 + 1 ) ;
if ( V_20 -> V_231 == V_232 ) {
V_9 = V_2 -> V_233 ;
V_227 = V_2 -> V_234 ;
} else {
V_9 = V_2 -> V_235 ;
V_227 = V_2 -> V_236 ;
}
for ( V_101 = 0 ; V_101 < V_227 ; V_101 ++ , V_9 ++ )
if ( ! V_2 -> V_18 [ V_9 ] . V_237 ) {
V_55 = & V_2 -> V_18 [ V_9 ] ;
if ( V_55 -> V_238 == V_228 )
break;
}
if ( V_55 ) {
V_55 -> V_237 = 1 ;
V_55 -> V_238 = V_228 ;
}
return V_55 ;
}
static inline void F_106 ( struct V_18 * V_18 )
{
V_18 -> V_237 = 0 ;
}
static T_4 F_107 ( const struct V_239 * V_240 )
{
struct V_18 * V_18 = F_108 ( V_240 , struct V_18 , V_241 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_1 * V_2 = V_242 -> V_2 ;
return F_45 ( V_2 , V_243 ) ;
}
static void F_110 ( struct V_19 * V_20 ,
bool V_244 , T_4 V_245 )
{
struct V_18 * V_18 = F_111 ( V_20 ) ;
struct V_246 * V_247 = & V_18 -> V_248 ;
struct V_239 * V_240 = & V_18 -> V_241 ;
T_5 V_249 ;
V_240 -> V_250 = F_107 ;
V_240 -> V_119 = F_112 ( 32 ) ;
V_240 -> V_251 = 125 ;
V_240 -> V_252 = 0 ;
V_249 = 0 ;
F_113 ( V_247 , V_240 , V_249 ) ;
if ( V_244 )
V_247 -> V_253 = V_245 ;
}
static int F_114 ( struct V_19 * V_20 ,
struct V_254 * V_255 )
{
struct V_18 * V_18 = F_111 ( V_20 ) ;
T_5 V_249 ;
V_249 = F_115 ( & V_18 -> V_248 ) ;
V_249 = F_116 ( V_249 , 3 ) ;
* V_255 = F_117 ( V_249 ) ;
return 0 ;
}
static int F_118 ( struct V_19 * V_20 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_256 * V_257 = V_242 -> V_257 [ V_20 -> V_231 ] ;
struct V_1 * V_2 = V_242 -> V_2 ;
struct V_18 * V_18 ;
struct V_173 * V_174 = V_20 -> V_174 ;
unsigned long V_258 ;
int V_22 ;
int V_259 ;
F_90 ( & V_2 -> V_260 ) ;
V_18 = F_105 ( V_2 , V_20 ) ;
if ( V_18 == NULL ) {
F_91 ( & V_2 -> V_260 ) ;
return - V_96 ;
}
V_174 -> V_261 = V_262 ;
V_174 -> V_261 . V_263 = V_257 -> V_263 ;
V_174 -> V_261 . V_264 = V_257 -> V_264 ;
V_174 -> V_261 . V_265 = V_257 -> V_265 ;
V_174 -> V_261 . V_266 = V_257 -> V_266 ;
F_119 ( V_174 ) ;
F_120 ( V_174 , V_267 ) ;
F_121 ( V_174 , V_268 ,
20 ,
178000000 ) ;
if ( V_2 -> V_269 )
V_259 = 128 ;
else
V_259 = 4 ;
F_122 ( V_174 , 0 , V_270 ,
V_259 ) ;
F_122 ( V_174 , 0 , V_271 ,
V_259 ) ;
F_123 ( V_242 -> V_223 ) ;
V_22 = V_257 -> V_205 . V_272 ( V_257 , V_242 -> V_223 , V_20 ) ;
if ( V_22 < 0 ) {
F_106 ( V_18 ) ;
F_124 ( V_242 -> V_223 ) ;
F_91 ( & V_2 -> V_260 ) ;
return V_22 ;
}
F_119 ( V_174 ) ;
if ( F_125 ( ! V_174 -> V_261 . V_263 ) ||
F_125 ( ! V_174 -> V_261 . V_264 ) ||
F_125 ( ! V_174 -> V_261 . V_265 ) ||
F_125 ( ! V_174 -> V_261 . V_266 ) ) {
F_106 ( V_18 ) ;
V_257 -> V_205 . V_273 ( V_257 , V_242 -> V_223 , V_20 ) ;
F_124 ( V_242 -> V_223 ) ;
F_91 ( & V_2 -> V_260 ) ;
return - V_161 ;
}
if ( V_20 -> V_231 == V_274 )
V_174 -> V_261 . V_275 &= ~ V_276 ;
F_126 ( & V_2 -> V_26 , V_258 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_145 = 0 ;
F_127 ( & V_2 -> V_26 , V_258 ) ;
V_174 -> V_13 = V_18 ;
F_128 ( V_20 ) ;
F_91 ( & V_2 -> V_260 ) ;
return 0 ;
}
static int F_129 ( struct V_19 * V_20 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_256 * V_257 = V_242 -> V_257 [ V_20 -> V_231 ] ;
struct V_1 * V_2 = V_242 -> V_2 ;
struct V_18 * V_18 = F_111 ( V_20 ) ;
unsigned long V_258 ;
F_90 ( & V_2 -> V_260 ) ;
F_126 ( & V_2 -> V_26 , V_258 ) ;
V_18 -> V_20 = NULL ;
V_18 -> V_145 = 0 ;
F_127 ( & V_2 -> V_26 , V_258 ) ;
F_106 ( V_18 ) ;
V_257 -> V_205 . V_273 ( V_257 , V_242 -> V_223 , V_20 ) ;
F_124 ( V_242 -> V_223 ) ;
F_91 ( & V_2 -> V_260 ) ;
return 0 ;
}
static int F_130 ( struct V_19 * V_20 ,
struct V_277 * V_278 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_1 * V_2 = V_242 -> V_2 ;
struct V_18 * V_18 = F_111 ( V_20 ) ;
int V_279 ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_169 = 0 ;
V_18 -> V_165 = 0 ;
V_18 -> V_184 = 0 ;
V_279 = F_131 ( V_20 ,
F_132 ( V_278 ) ) ;
if ( V_279 < 0 )
return V_279 ;
F_9 ( V_2 , V_18 , V_20 , true ) ;
return V_279 ;
}
static int F_133 ( struct V_19 * V_20 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_18 * V_18 = F_111 ( V_20 ) ;
struct V_1 * V_2 = V_242 -> V_2 ;
struct V_256 * V_257 = V_242 -> V_257 [ V_20 -> V_231 ] ;
F_83 ( V_18 , V_167 , 0 ) ;
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_103 , 0 ) ;
V_18 -> V_169 = 0 ;
V_18 -> V_165 = 0 ;
V_18 -> V_184 = 0 ;
F_134 ( V_242 -> V_223 , V_257 , V_20 ) ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
return F_135 ( V_20 ) ;
}
static int F_136 ( struct V_19 * V_20 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_1 * V_2 = V_242 -> V_2 ;
struct V_18 * V_18 = F_111 ( V_20 ) ;
struct V_256 * V_257 = V_242 -> V_257 [ V_20 -> V_231 ] ;
struct V_173 * V_174 = V_20 -> V_174 ;
unsigned int V_169 , V_165 , V_184 , V_179 ;
int V_22 ;
struct V_280 * V_281 =
F_137 ( V_242 -> V_223 , V_257 -> V_282 ) ;
unsigned short V_283 = V_281 ? V_281 -> V_283 : 0 ;
F_85 ( V_2 , V_18 ) ;
V_184 = F_138 ( V_174 -> V_176 ,
V_174 -> V_284 ,
V_174 -> V_285 ,
V_257 -> V_286 ,
V_283 ) ;
if ( ! V_184 ) {
F_14 (KERN_ERR SFX
L_30 ,
pci_name(chip->pci), runtime->rate, runtime->channels, runtime->format) ;
return - V_161 ;
}
V_169 = F_139 ( V_20 ) ;
V_165 = F_140 ( V_20 ) ;
F_40 ( V_72 L_31 ,
F_41 ( V_2 -> V_24 ) , V_169 , V_184 ) ;
if ( V_169 != V_18 -> V_169 ||
V_165 != V_18 -> V_165 ||
V_184 != V_18 -> V_184 ||
V_174 -> V_172 != V_18 -> V_172 ) {
V_18 -> V_169 = V_169 ;
V_18 -> V_165 = V_165 ;
V_18 -> V_184 = V_184 ;
V_18 -> V_172 = V_174 -> V_172 ;
V_22 = F_82 ( V_2 , V_20 , V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_18 -> V_287 = ( ( ( V_174 -> V_288 * 24000 ) /
V_174 -> V_176 ) * 1000 ) ;
F_86 ( V_2 , V_18 ) ;
if ( V_20 -> V_231 == V_232 )
V_18 -> V_289 = F_141 ( V_18 , V_290 ) + 1 ;
else
V_18 -> V_289 = 0 ;
V_179 = V_18 -> V_179 ;
if ( ( V_2 -> V_47 & V_48 ) &&
V_179 > V_2 -> V_236 )
V_179 -= V_2 -> V_236 ;
return F_142 ( V_242 -> V_223 , V_257 , V_179 ,
V_18 -> V_184 , V_20 ) ;
}
static int F_143 ( struct V_19 * V_20 , int V_53 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_1 * V_2 = V_242 -> V_2 ;
struct V_18 * V_18 ;
struct V_19 * V_291 ;
int V_292 = 0 , V_293 , V_294 = 0 , V_295 = 0 ;
int V_296 , V_63 ;
V_18 = F_111 ( V_20 ) ;
F_144 ( V_2 , V_18 , V_53 ) ;
switch ( V_53 ) {
case V_297 :
V_292 = 1 ;
case V_298 :
case V_299 :
V_293 = 1 ;
break;
case V_300 :
case V_301 :
case V_302 :
V_293 = 0 ;
break;
default:
return - V_161 ;
}
F_145 (s, substream) {
if ( V_291 -> V_195 -> V_214 != V_20 -> V_195 -> V_214 )
continue;
V_18 = F_111 ( V_291 ) ;
V_295 |= 1 << V_18 -> V_111 ;
V_294 ++ ;
F_146 ( V_291 , V_20 ) ;
}
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_303 )
F_17 ( V_2 , V_304 ,
F_45 ( V_2 , V_304 ) | V_295 ) ;
else
F_17 ( V_2 , V_305 , F_45 ( V_2 , V_305 ) | V_295 ) ;
F_145 (s, substream) {
if ( V_291 -> V_195 -> V_214 != V_20 -> V_195 -> V_214 )
continue;
V_18 = F_111 ( V_291 ) ;
if ( V_293 ) {
V_18 -> V_306 = F_45 ( V_2 , V_243 ) ;
if ( ! V_292 )
V_18 -> V_306 -=
V_18 -> V_287 ;
F_62 ( V_2 , V_18 ) ;
} else {
F_64 ( V_2 , V_18 ) ;
}
V_18 -> V_145 = V_293 ;
}
F_75 ( & V_2 -> V_26 ) ;
if ( V_293 ) {
for ( V_63 = 5000 ; V_63 ; V_63 -- ) {
V_296 = 0 ;
F_145 (s, substream) {
if ( V_291 -> V_195 -> V_214 != V_20 -> V_195 -> V_214 )
continue;
V_18 = F_111 ( V_291 ) ;
if ( ! ( F_60 ( V_18 , V_105 ) &
V_307 ) )
V_296 ++ ;
}
if ( ! V_296 )
break;
F_147 () ;
}
} else {
for ( V_63 = 5000 ; V_63 ; V_63 -- ) {
V_296 = 0 ;
F_145 (s, substream) {
if ( V_291 -> V_195 -> V_214 != V_20 -> V_195 -> V_214 )
continue;
V_18 = F_111 ( V_291 ) ;
if ( F_60 ( V_18 , V_103 ) &
V_112 )
V_296 ++ ;
}
if ( ! V_296 )
break;
F_147 () ;
}
}
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_303 )
F_17 ( V_2 , V_304 ,
F_45 ( V_2 , V_304 ) & ~ V_295 ) ;
else
F_17 ( V_2 , V_305 , F_45 ( V_2 , V_305 ) & ~ V_295 ) ;
if ( V_293 ) {
F_110 ( V_20 , 0 , 0 ) ;
if ( V_294 > 1 ) {
T_4 V_253 ;
V_18 = F_111 ( V_20 ) ;
V_253 = V_18 -> V_248 . V_253 ;
F_145 (s, substream) {
if ( V_291 -> V_195 -> V_214 != V_20 -> V_195 -> V_214 )
continue;
F_110 ( V_291 , 1 , V_253 ) ;
}
}
}
F_75 ( & V_2 -> V_26 ) ;
return 0 ;
}
static unsigned int F_148 ( struct V_1 * V_2 ,
struct V_18 * V_18 )
{
unsigned int V_308 , V_309 , V_310 ;
unsigned int V_311 , V_312 , V_313 ;
unsigned int V_289 ;
V_308 = F_87 ( V_18 , V_314 ) ;
if ( V_18 -> V_20 -> V_231 == V_232 ) {
return V_308 ;
}
V_312 = F_30 ( * V_18 -> V_115 ) ;
V_312 %= V_18 -> V_165 ;
V_289 = F_149 ( V_2 -> V_315 + V_316 ) ;
if ( V_18 -> V_110 ) {
if ( V_308 <= V_289 )
return 0 ;
V_18 -> V_110 = 0 ;
}
if ( V_308 <= V_289 )
V_309 = V_18 -> V_169 + V_308 - V_289 ;
else
V_309 = V_308 - V_289 ;
V_313 = V_309 % V_18 -> V_165 ;
V_311 = V_308 % V_18 -> V_165 ;
if ( V_311 >= V_289 )
V_310 = V_308 - V_311 ;
else if ( V_312 >= V_313 )
V_310 = V_309 - V_313 ;
else {
V_310 = V_309 - V_313 + V_18 -> V_165 ;
if ( V_310 >= V_18 -> V_169 )
V_310 = 0 ;
}
return V_310 + V_312 ;
}
static unsigned int F_150 ( struct V_1 * V_2 ,
struct V_18 * V_18 ,
bool V_317 )
{
unsigned int V_318 ;
int V_231 = V_18 -> V_20 -> V_231 ;
int V_319 = 0 ;
switch ( V_2 -> V_186 [ V_231 ] ) {
case V_187 :
V_318 = F_87 ( V_18 , V_314 ) ;
break;
case V_320 :
V_318 = F_148 ( V_2 , V_18 ) ;
break;
default:
V_318 = F_30 ( * V_18 -> V_115 ) ;
if ( V_317 && V_2 -> V_186 [ V_231 ] == V_321 ) {
if ( ! V_318 || V_318 == ( V_29 ) - 1 ) {
F_151 ( V_322
L_32
L_33 ) ;
V_2 -> V_186 [ V_231 ] = V_187 ;
V_318 = F_87 ( V_18 , V_314 ) ;
} else
V_2 -> V_186 [ V_231 ] = V_323 ;
}
break;
}
if ( V_318 >= V_18 -> V_169 )
V_318 = 0 ;
if ( V_18 -> V_20 -> V_174 &&
V_2 -> V_186 [ V_231 ] == V_323 &&
( V_2 -> V_47 & V_324 ) ) {
unsigned int V_325 = F_87 ( V_18 , V_314 ) ;
if ( V_231 == V_232 )
V_319 = V_318 - V_325 ;
else
V_319 = V_325 - V_318 ;
if ( V_319 < 0 )
V_319 += V_18 -> V_169 ;
if ( V_319 >= V_18 -> V_165 ) {
F_14 (KERN_WARNING SFX
L_34
L_35 ,
pci_name(chip->pci), delay, azx_dev->period_bytes) ;
V_319 = 0 ;
V_2 -> V_47 &= ~ V_324 ;
}
V_18 -> V_20 -> V_174 -> V_319 =
F_152 ( V_18 -> V_20 -> V_174 , V_319 ) ;
}
F_153 ( V_2 , V_18 , V_318 , V_319 ) ;
return V_318 ;
}
static T_6 F_154 ( struct V_19 * V_20 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_1 * V_2 = V_242 -> V_2 ;
struct V_18 * V_18 = F_111 ( V_20 ) ;
return F_152 ( V_20 -> V_174 ,
F_150 ( V_2 , V_18 , false ) ) ;
}
static int F_76 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_29 V_326 ;
unsigned int V_318 ;
V_326 = F_45 ( V_2 , V_243 ) - V_18 -> V_306 ;
if ( V_326 < ( V_18 -> V_287 * 2 ) / 3 )
return - 1 ;
V_318 = F_150 ( V_2 , V_18 , true ) ;
if ( F_155 ( ! V_18 -> V_165 ,
L_36 ) )
return - 1 ;
if ( V_326 < ( V_18 -> V_287 * 5 ) / 4 &&
V_318 % V_18 -> V_165 > V_18 -> V_165 / 2 )
return V_170 [ V_2 -> V_171 ] ? 0 : - 1 ;
V_18 -> V_306 += V_326 ;
return 1 ;
}
static void F_156 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_108 ( V_328 , struct V_1 , V_149 ) ;
int V_101 , V_329 , V_139 ;
if ( ! V_2 -> V_330 ) {
F_151 ( V_322
L_37
L_38 ,
V_2 -> V_214 -> V_230 ) ;
V_2 -> V_330 = 1 ;
}
for (; ; ) {
V_329 = 0 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_101 ] ;
if ( ! V_18 -> V_147 ||
! V_18 -> V_20 ||
! V_18 -> V_145 )
continue;
V_139 = F_76 ( V_2 , V_18 ) ;
if ( V_139 > 0 ) {
V_18 -> V_147 = 0 ;
F_75 ( & V_2 -> V_26 ) ;
F_77 ( V_18 -> V_20 ) ;
F_74 ( & V_2 -> V_26 ) ;
} else if ( V_139 < 0 ) {
V_329 = 0 ;
} else
V_329 ++ ;
}
F_21 ( & V_2 -> V_26 ) ;
if ( ! V_329 )
return;
F_37 ( 1 ) ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
int V_101 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ )
V_2 -> V_18 [ V_101 ] . V_147 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
}
static int F_158 ( struct V_19 * V_20 ,
struct V_331 * V_7 )
{
struct V_193 * V_242 = F_109 ( V_20 ) ;
struct V_1 * V_2 = V_242 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_7 -> V_332 = F_159 ( V_7 -> V_332 ) ;
return F_160 ( V_20 , V_7 ) ;
}
static void F_161 ( struct V_333 * V_195 )
{
struct V_193 * V_242 = V_195 -> V_13 ;
if ( V_242 ) {
F_162 ( & V_242 -> V_334 ) ;
F_163 ( V_242 ) ;
}
}
static int
V_209 ( struct V_56 * V_57 , struct V_222 * V_223 ,
struct V_335 * V_336 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_333 * V_195 ;
struct V_193 * V_242 ;
int V_337 = V_336 -> V_229 ;
unsigned int V_155 ;
int V_291 , V_22 ;
F_95 (apcm, &chip->pcm_list, list) {
if ( V_242 -> V_195 -> V_229 == V_337 ) {
F_14 (KERN_ERR SFX L_39 ,
pci_name(chip->pci), pcm_dev) ;
return - V_96 ;
}
}
V_22 = F_164 ( V_2 -> V_214 , V_336 -> V_338 , V_337 ,
V_336 -> V_231 [ V_232 ] . V_339 ,
V_336 -> V_231 [ V_274 ] . V_339 ,
& V_195 ) ;
if ( V_22 < 0 )
return V_22 ;
F_165 ( V_195 -> V_338 , V_336 -> V_338 , sizeof( V_195 -> V_338 ) ) ;
V_242 = F_166 ( sizeof( * V_242 ) , V_340 ) ;
if ( V_242 == NULL )
return - V_341 ;
V_242 -> V_2 = V_2 ;
V_242 -> V_195 = V_195 ;
V_242 -> V_223 = V_223 ;
V_195 -> V_13 = V_242 ;
V_195 -> V_342 = F_161 ;
if ( V_336 -> V_343 == V_344 )
V_195 -> V_345 = V_346 ;
F_167 ( & V_242 -> V_334 , & V_2 -> V_347 ) ;
V_336 -> V_195 = V_195 ;
for ( V_291 = 0 ; V_291 < 2 ; V_291 ++ ) {
V_242 -> V_257 [ V_291 ] = & V_336 -> V_231 [ V_291 ] ;
if ( V_336 -> V_231 [ V_291 ] . V_339 )
F_168 ( V_195 , V_291 , & V_348 ) ;
}
V_155 = V_349 * 1024 ;
if ( V_155 > V_350 )
V_155 = V_350 ;
F_169 ( V_195 , V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_155 , V_350 ) ;
return 0 ;
}
static int F_170 ( struct V_1 * V_2 )
{
return F_171 ( V_2 -> V_57 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_101 ] ;
V_18 -> V_115 = ( V_29 V_351 * ) ( V_2 -> V_115 . V_7 + V_101 * 8 ) ;
V_18 -> V_352 = V_2 -> V_315 + ( 0x20 * V_101 + 0x80 ) ;
V_18 -> V_144 = 1 << V_101 ;
V_18 -> V_111 = V_101 ;
V_18 -> V_179 = V_101 + 1 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_353 )
{
if ( F_173 ( V_2 -> V_24 -> V_75 , F_72 ,
V_2 -> V_74 ? 0 : V_354 ,
V_355 , V_2 ) ) {
F_151 ( V_80 L_40
L_41 , V_2 -> V_24 -> V_75 ) ;
if ( V_353 )
F_174 ( V_2 -> V_214 ) ;
return - 1 ;
}
V_2 -> V_75 = V_2 -> V_24 -> V_75 ;
F_175 ( V_2 -> V_24 , ! V_2 -> V_74 ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_113 )
return;
F_58 ( V_2 ) ;
F_61 ( V_2 ) ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_114 , 0 ) ;
F_17 ( V_2 , V_116 , 0 ) ;
V_2 -> V_113 = 0 ;
}
static void V_213 ( struct V_56 * V_57 , bool V_356 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( ! ( V_2 -> V_47 & V_357 ) )
return;
if ( V_356 )
F_176 ( & V_2 -> V_24 -> V_9 ) ;
else
F_177 ( & V_2 -> V_24 -> V_9 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
F_90 ( & V_358 ) ;
F_179 ( & V_2 -> V_334 , & V_359 ) ;
F_91 ( & V_358 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
F_90 ( & V_358 ) ;
F_181 ( & V_2 -> V_334 ) ;
F_91 ( & V_358 ) ;
}
static int F_182 ( const char * V_58 , const struct V_360 * V_361 )
{
struct V_1 * V_2 ;
struct V_222 * V_201 ;
int V_362 = V_211 ;
int V_279 = F_183 ( V_58 , V_361 ) ;
if ( V_279 || V_362 == V_211 )
return V_279 ;
F_90 ( & V_358 ) ;
F_95 (chip, &card_list, list) {
if ( ! V_2 -> V_57 || V_2 -> V_90 )
continue;
F_95 (c, &chip->bus->codec_list, list)
F_184 ( V_201 ) ;
}
F_91 ( & V_358 ) ;
return 0 ;
}
static int F_185 ( struct V_229 * V_9 )
{
struct V_117 * V_24 = F_186 ( V_9 ) ;
struct V_363 * V_214 = F_187 ( V_9 ) ;
struct V_1 * V_2 = V_214 -> V_13 ;
struct V_193 * V_194 ;
if ( V_2 -> V_90 )
return 0 ;
F_188 ( V_214 , V_364 ) ;
F_157 ( V_2 ) ;
F_95 (p, &chip->pcm_list, list)
F_96 ( V_194 -> V_195 ) ;
if ( V_2 -> V_113 )
F_97 ( V_2 -> V_57 ) ;
F_93 ( V_2 ) ;
if ( V_2 -> V_75 >= 0 ) {
F_42 ( V_2 -> V_75 , V_2 ) ;
V_2 -> V_75 = - 1 ;
}
if ( V_2 -> V_74 )
F_43 ( V_2 -> V_24 ) ;
F_189 ( V_24 ) ;
F_190 ( V_24 ) ;
F_191 ( V_24 , V_365 ) ;
return 0 ;
}
static int F_192 ( struct V_229 * V_9 )
{
struct V_117 * V_24 = F_186 ( V_9 ) ;
struct V_363 * V_214 = F_187 ( V_9 ) ;
struct V_1 * V_2 = V_214 -> V_13 ;
if ( V_2 -> V_90 )
return 0 ;
F_191 ( V_24 , V_366 ) ;
F_193 ( V_24 ) ;
if ( F_194 ( V_24 ) < 0 ) {
F_151 ( V_80 L_42
L_41 ) ;
F_174 ( V_214 ) ;
return - V_87 ;
}
F_195 ( V_24 ) ;
if ( V_2 -> V_74 )
if ( F_196 ( V_24 ) < 0 )
V_2 -> V_74 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 )
return - V_87 ;
F_69 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
F_98 ( V_2 -> V_57 ) ;
F_188 ( V_214 , V_367 ) ;
return 0 ;
}
static int F_197 ( struct V_229 * V_9 )
{
struct V_363 * V_214 = F_187 ( V_9 ) ;
struct V_1 * V_2 = V_214 -> V_13 ;
F_93 ( V_2 ) ;
F_157 ( V_2 ) ;
return 0 ;
}
static int F_198 ( struct V_229 * V_9 )
{
struct V_363 * V_214 = F_187 ( V_9 ) ;
struct V_1 * V_2 = V_214 -> V_13 ;
F_69 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
return 0 ;
}
static int F_199 ( struct V_229 * V_9 )
{
struct V_363 * V_214 = F_187 ( V_9 ) ;
struct V_1 * V_2 = V_214 -> V_13 ;
if ( ! V_368 ||
! ( V_2 -> V_47 & V_357 ) )
return - V_96 ;
return 0 ;
}
static int F_200 ( struct V_369 * V_370 , unsigned long V_371 , void * V_17 )
{
struct V_1 * V_2 = F_108 ( V_370 , struct V_1 , V_372 ) ;
F_201 ( V_2 -> V_57 ) ;
F_93 ( V_2 ) ;
return V_373 ;
}
static void F_202 ( struct V_1 * V_2 )
{
V_2 -> V_372 . V_374 = F_200 ;
F_203 ( & V_2 -> V_372 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
if ( V_2 -> V_372 . V_374 )
F_205 ( & V_2 -> V_372 ) ;
}
static void F_206 ( struct V_117 * V_24 ,
enum V_375 V_376 )
{
struct V_363 * V_214 = F_207 ( V_24 ) ;
struct V_1 * V_2 = V_214 -> V_13 ;
bool V_90 ;
F_208 ( & V_2 -> V_377 ) ;
if ( V_2 -> V_378 )
return;
V_90 = ( V_376 == V_379 ) ;
if ( V_2 -> V_90 == V_90 )
return;
if ( ! V_2 -> V_57 ) {
V_2 -> V_90 = V_90 ;
if ( ! V_90 ) {
F_14 (KERN_INFO SFX
L_43 ,
pci_name(chip->pci)) ;
if ( F_209 ( V_2 ) < 0 ||
F_210 ( V_2 ) < 0 ) {
F_14 (KERN_ERR SFX
L_44 ,
pci_name(chip->pci)) ;
V_2 -> V_378 = true ;
}
}
} else {
F_14 (KERN_INFO SFX
L_45 , pci_name(chip->pci),
disabled ? L_46 : L_47 ) ;
if ( V_90 ) {
F_185 ( & V_24 -> V_9 ) ;
V_2 -> V_90 = true ;
if ( F_211 ( V_2 -> V_57 ) )
F_14 (KERN_WARNING SFX L_48 ,
pci_name(chip->pci)) ;
} else {
F_212 ( V_2 -> V_57 ) ;
V_2 -> V_90 = false ;
F_192 ( & V_24 -> V_9 ) ;
}
}
}
static bool F_213 ( struct V_117 * V_24 )
{
struct V_363 * V_214 = F_207 ( V_24 ) ;
struct V_1 * V_2 = V_214 -> V_13 ;
F_208 ( & V_2 -> V_377 ) ;
if ( V_2 -> V_378 )
return false ;
if ( V_2 -> V_90 || ! V_2 -> V_57 )
return true ;
if ( F_211 ( V_2 -> V_57 ) )
return false ;
F_212 ( V_2 -> V_57 ) ;
return true ;
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_117 * V_194 = F_215 ( V_2 -> V_24 ) ;
if ( V_194 ) {
F_14 (KERN_INFO SFX
L_49 ,
pci_name(chip->pci)) ;
V_2 -> V_380 = 1 ;
F_216 ( V_194 ) ;
}
}
static int F_217 ( struct V_1 * V_2 )
{
int V_22 ;
if ( ! V_2 -> V_380 )
return 0 ;
V_22 = F_218 ( V_2 -> V_24 , & V_381 ,
V_382 ,
V_2 -> V_57 != NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_383 = 1 ;
return 0 ;
}
static int F_219 ( struct V_1 * V_2 )
{
int V_101 ;
F_180 ( V_2 ) ;
F_204 ( V_2 ) ;
V_2 -> V_378 = 1 ;
F_220 ( & V_2 -> V_377 ) ;
if ( V_380 ( V_2 ) ) {
if ( V_2 -> V_90 && V_2 -> V_57 )
F_212 ( V_2 -> V_57 ) ;
if ( V_2 -> V_383 )
F_221 ( V_2 -> V_24 ) ;
}
if ( V_2 -> V_113 ) {
F_157 ( V_2 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ )
F_64 ( V_2 , & V_2 -> V_18 [ V_101 ] ) ;
F_93 ( V_2 ) ;
}
if ( V_2 -> V_75 >= 0 )
F_42 ( V_2 -> V_75 , ( void * ) V_2 ) ;
if ( V_2 -> V_74 )
F_43 ( V_2 -> V_24 ) ;
if ( V_2 -> V_315 )
F_222 ( V_2 -> V_315 ) ;
if ( V_2 -> V_18 ) {
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ )
if ( V_2 -> V_18 [ V_101 ] . V_157 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_18 [ V_101 ] . V_157 , false ) ;
F_223 ( & V_2 -> V_18 [ V_101 ] . V_157 ) ;
}
}
if ( V_2 -> V_25 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_25 , false ) ;
F_223 ( & V_2 -> V_25 ) ;
}
if ( V_2 -> V_115 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_115 , false ) ;
F_223 ( & V_2 -> V_115 ) ;
}
if ( V_2 -> V_384 )
F_224 ( V_2 -> V_24 ) ;
F_189 ( V_2 -> V_24 ) ;
F_163 ( V_2 -> V_18 ) ;
#ifdef F_225
if ( V_2 -> V_385 )
F_226 ( V_2 -> V_385 ) ;
#endif
F_163 ( V_2 ) ;
return 0 ;
}
static int F_227 ( struct V_386 * V_229 )
{
return F_219 ( V_229 -> V_387 ) ;
}
static struct V_117 * F_215 ( struct V_117 * V_24 )
{
struct V_117 * V_194 ;
switch ( V_24 -> V_388 ) {
case V_389 :
case V_390 :
case V_391 :
if ( V_24 -> V_392 == 1 ) {
V_194 = F_228 ( F_229 ( V_24 -> V_57 ) ,
V_24 -> V_57 -> V_230 , 0 ) ;
if ( V_194 ) {
if ( ( V_194 -> V_393 >> 8 ) == V_394 )
return V_194 ;
F_216 ( V_194 ) ;
}
}
break;
}
return NULL ;
}
static bool F_230 ( struct V_117 * V_24 )
{
bool V_395 = false ;
struct V_117 * V_194 = F_215 ( V_24 ) ;
if ( V_194 ) {
if ( F_231 ( V_194 ) == V_379 )
V_395 = true ;
F_216 ( V_194 ) ;
}
return V_395 ;
}
static int F_232 ( struct V_1 * V_2 , int V_396 )
{
const struct V_397 * V_398 ;
switch ( V_396 ) {
case V_321 :
case V_187 :
case V_323 :
case V_320 :
case V_399 :
return V_396 ;
}
V_398 = F_233 ( V_2 -> V_24 , V_400 ) ;
if ( V_398 ) {
F_151 ( V_401
L_50
L_51 ,
V_398 -> V_402 , V_398 -> V_403 , V_398 -> V_404 ) ;
return V_398 -> V_402 ;
}
if ( V_2 -> V_47 & V_405 ) {
F_48 ( V_72 L_52 , F_41 ( V_2 -> V_24 ) ) ;
return V_320 ;
}
if ( V_2 -> V_47 & V_406 ) {
F_48 ( V_72 L_53 , F_41 ( V_2 -> V_24 ) ) ;
return V_187 ;
}
return V_321 ;
}
static void F_234 ( struct V_1 * V_2 , int V_9 )
{
const struct V_397 * V_398 ;
V_2 -> V_219 = V_407 [ V_9 ] ;
if ( V_2 -> V_219 == - 1 ) {
V_398 = F_233 ( V_2 -> V_24 , V_408 ) ;
if ( V_398 ) {
F_151 ( V_401
L_54
L_51 ,
V_398 -> V_402 , V_398 -> V_403 , V_398 -> V_404 ) ;
V_2 -> V_219 = V_398 -> V_402 ;
}
}
if ( V_2 -> V_219 != - 1 &&
( V_2 -> V_219 & V_409 ) ) {
V_2 -> V_97 = V_2 -> V_219 & 0xff ;
F_151 ( V_401 L_55 ,
V_2 -> V_97 ) ;
}
}
static void F_235 ( struct V_1 * V_2 )
{
const struct V_397 * V_398 ;
if ( V_410 >= 0 ) {
V_2 -> V_74 = ! ! V_410 ;
return;
}
V_2 -> V_74 = 1 ;
V_398 = F_233 ( V_2 -> V_24 , V_411 ) ;
if ( V_398 ) {
F_151 ( V_401
L_56 ,
V_398 -> V_403 , V_398 -> V_404 , V_398 -> V_402 ) ;
V_2 -> V_74 = V_398 -> V_402 ;
return;
}
if ( V_2 -> V_47 & V_412 ) {
F_151 ( V_401 L_57 ) ;
V_2 -> V_74 = 0 ;
}
}
static void F_236 ( struct V_1 * V_2 )
{
bool V_133 = V_2 -> V_133 ;
switch ( V_2 -> V_217 ) {
case V_413 :
if ( V_133 ) {
T_2 V_58 ;
F_67 ( V_2 -> V_24 , 0x42 , & V_58 ) ;
if ( ! ( V_58 & 0x80 ) && V_2 -> V_24 -> V_414 == 0x30 )
V_133 = false ;
}
break;
case V_415 :
V_133 = false ;
break;
}
if ( V_133 != V_2 -> V_133 ) {
F_14 (KERN_INFO SFX L_58 ,
pci_name(chip->pci), snoop ? L_59 : L_60 ) ;
V_2 -> V_133 = V_133 ;
}
}
static int F_237 ( struct V_363 * V_214 , struct V_117 * V_24 ,
int V_9 , unsigned int V_47 ,
struct V_1 * * V_416 )
{
static struct V_417 V_205 = {
. V_418 = F_227 ,
} ;
struct V_1 * V_2 ;
int V_22 ;
* V_416 = NULL ;
V_22 = F_194 ( V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 = F_166 ( sizeof( * V_2 ) , V_340 ) ;
if ( ! V_2 ) {
F_14 (KERN_ERR SFX L_61 , pci_name(pci)) ;
F_189 ( V_24 ) ;
return - V_341 ;
}
F_238 ( & V_2 -> V_26 ) ;
F_239 ( & V_2 -> V_260 ) ;
V_2 -> V_214 = V_214 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_75 = - 1 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_217 = V_47 & 0xff ;
F_235 ( V_2 ) ;
V_2 -> V_171 = V_9 ;
F_240 ( & V_2 -> V_149 , F_156 ) ;
F_241 ( & V_2 -> V_347 ) ;
F_241 ( & V_2 -> V_334 ) ;
F_214 ( V_2 ) ;
F_242 ( & V_2 -> V_377 ) ;
V_2 -> V_186 [ 0 ] = V_2 -> V_186 [ 1 ] =
F_232 ( V_2 , V_186 [ V_9 ] ) ;
if ( V_2 -> V_186 [ 0 ] == V_399 ) {
V_2 -> V_186 [ 0 ] = V_187 ;
V_2 -> V_186 [ 1 ] = V_321 ;
}
F_234 ( V_2 , V_9 ) ;
V_2 -> V_81 = V_81 ;
V_2 -> V_133 = V_419 ;
F_236 ( V_2 ) ;
if ( V_170 [ V_9 ] < 0 ) {
switch ( V_2 -> V_217 ) {
case V_420 :
case V_421 :
V_170 [ V_9 ] = 1 ;
break;
default:
V_170 [ V_9 ] = 32 ;
break;
}
}
V_22 = F_243 ( V_214 , V_422 , V_2 , & V_205 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_62 ,
pci_name(chip->pci)) ;
F_219 ( V_2 ) ;
return V_22 ;
}
* V_416 = V_2 ;
return 0 ;
}
static int F_209 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_171 ;
struct V_117 * V_24 = V_2 -> V_24 ;
struct V_363 * V_214 = V_2 -> V_214 ;
int V_101 , V_22 ;
unsigned short V_423 ;
#if V_424 != 64
if ( V_2 -> V_217 == V_425 ) {
T_7 V_426 ;
F_70 ( V_24 , 0x40 , & V_426 ) ;
F_71 ( V_24 , 0x40 , V_426 | 0x10 ) ;
F_244 ( V_24 , V_427 , 0 ) ;
}
#endif
V_22 = F_245 ( V_24 , L_63 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_384 = 1 ;
V_2 -> V_28 = F_246 ( V_24 , 0 ) ;
V_2 -> V_315 = F_247 ( V_24 , 0 ) ;
if ( V_2 -> V_315 == NULL ) {
F_14 (KERN_ERR SFX L_64 , pci_name(chip->pci)) ;
return - V_226 ;
}
if ( V_2 -> V_74 )
if ( F_196 ( V_24 ) < 0 )
V_2 -> V_74 = 0 ;
if ( F_44 ( V_2 , 0 ) < 0 )
return - V_96 ;
F_195 ( V_24 ) ;
F_248 ( V_2 -> V_75 ) ;
V_423 = F_27 ( V_2 , V_428 ) ;
F_40 ( V_72 L_65 , F_41 ( V_2 -> V_24 ) , V_423 ) ;
if ( V_2 -> V_24 -> V_388 == V_389 ) {
struct V_117 * V_429 ;
V_429 = F_249 ( V_389 ,
V_430 ,
NULL ) ;
if ( V_429 ) {
if ( V_429 -> V_414 < 0x30 )
V_423 &= ~ V_431 ;
F_216 ( V_429 ) ;
}
}
if ( V_2 -> V_47 & V_432 ) {
F_48 ( V_72 L_66 , F_41 ( V_2 -> V_24 ) ) ;
V_423 &= ~ V_431 ;
}
if ( V_269 >= 0 )
V_2 -> V_269 = ! ! V_269 ;
else {
if ( V_2 -> V_47 & V_433 )
V_2 -> V_269 = 0 ;
else if ( V_2 -> V_47 & V_434 )
V_2 -> V_269 = 1 ;
else
V_2 -> V_269 = 1 ;
}
if ( ( V_423 & V_431 ) && ! F_250 ( V_24 , F_251 ( 64 ) ) )
F_252 ( V_24 , F_251 ( 64 ) ) ;
else {
F_250 ( V_24 , F_251 ( 32 ) ) ;
F_252 ( V_24 , F_251 ( 32 ) ) ;
}
V_2 -> V_236 = ( V_423 >> 8 ) & 0x0f ;
V_2 -> V_234 = ( V_423 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_234 && ! V_2 -> V_236 ) {
switch ( V_2 -> V_217 ) {
case V_425 :
V_2 -> V_234 = V_435 ;
V_2 -> V_236 = V_436 ;
break;
case V_437 :
case V_415 :
V_2 -> V_234 = V_438 ;
V_2 -> V_236 = V_439 ;
break;
case V_440 :
default:
V_2 -> V_234 = V_441 ;
V_2 -> V_236 = V_442 ;
break;
}
}
V_2 -> V_235 = 0 ;
V_2 -> V_233 = V_2 -> V_236 ;
V_2 -> V_102 = V_2 -> V_234 + V_2 -> V_236 ;
V_2 -> V_18 = F_253 ( V_2 -> V_102 , sizeof( * V_2 -> V_18 ) ,
V_340 ) ;
if ( ! V_2 -> V_18 ) {
F_14 (KERN_ERR SFX L_67 , pci_name(chip->pci)) ;
return - V_341 ;
}
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_443 , & V_2 -> V_18 [ V_101 ] . V_157 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_68 , pci_name(chip->pci)) ;
return - V_341 ;
}
F_8 ( V_2 , & V_2 -> V_18 [ V_101 ] . V_157 , true ) ;
}
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_2 -> V_102 * 8 , & V_2 -> V_115 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_69 , pci_name(chip->pci)) ;
return - V_341 ;
}
F_8 ( V_2 , & V_2 -> V_115 , true ) ;
V_22 = F_11 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
F_172 ( V_2 ) ;
F_69 ( V_2 ) ;
F_65 ( V_2 , ( V_444 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_97 ) {
F_14 (KERN_ERR SFX L_70 , pci_name(chip->pci)) ;
return - V_445 ;
}
strcpy ( V_214 -> V_446 , L_71 ) ;
F_165 ( V_214 -> V_447 , V_448 [ V_2 -> V_217 ] ,
sizeof( V_214 -> V_447 ) ) ;
snprintf ( V_214 -> V_449 , sizeof( V_214 -> V_449 ) ,
L_72 ,
V_214 -> V_447 , V_2 -> V_28 , V_2 -> V_75 ) ;
return 0 ;
}
static void F_254 ( struct V_1 * V_2 )
{
#ifdef F_94
struct V_222 * V_223 ;
F_95 (codec, &chip->bus->codec_list, list) {
F_124 ( V_223 ) ;
}
#endif
}
static void F_255 ( const struct V_450 * V_385 , void * V_451 )
{
struct V_363 * V_214 = V_451 ;
struct V_1 * V_2 = V_214 -> V_13 ;
struct V_117 * V_24 = V_2 -> V_24 ;
if ( ! V_385 ) {
F_14 (KERN_ERR SFX L_73 ,
pci_name(chip->pci)) ;
goto error;
}
V_2 -> V_385 = V_385 ;
if ( ! V_2 -> V_90 ) {
if ( F_210 ( V_2 ) )
goto error;
}
return;
error:
F_256 ( V_214 ) ;
F_257 ( V_24 , NULL ) ;
}
static int F_258 ( struct V_117 * V_24 ,
const struct V_452 * V_453 )
{
static int V_9 ;
struct V_363 * V_214 ;
struct V_1 * V_2 ;
bool V_454 ;
int V_22 ;
if ( V_9 >= V_455 )
return - V_445 ;
if ( ! V_456 [ V_9 ] ) {
V_9 ++ ;
return - V_457 ;
}
V_22 = F_259 ( V_111 [ V_9 ] , V_458 [ V_9 ] , V_459 , 0 , & V_214 ) ;
if ( V_22 < 0 ) {
F_14 ( V_80 L_74 ) ;
return V_22 ;
}
F_260 ( V_214 , & V_24 -> V_9 ) ;
V_22 = F_237 ( V_214 , V_24 , V_9 , V_453 -> V_460 , & V_2 ) ;
if ( V_22 < 0 )
goto V_461;
V_214 -> V_13 = V_2 ;
F_257 ( V_24 , V_214 ) ;
V_22 = F_217 ( V_2 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX
L_75 , pci_name(pci)) ;
goto V_461;
}
if ( F_230 ( V_24 ) ) {
F_14 (KERN_INFO SFX L_76 ,
pci_name(pci)) ;
F_14 (KERN_INFO SFX L_77 , pci_name(pci)) ;
V_2 -> V_90 = true ;
}
V_454 = ! V_2 -> V_90 ;
if ( V_454 ) {
V_22 = F_209 ( V_2 ) ;
if ( V_22 < 0 )
goto V_461;
}
#ifdef F_225
if ( V_462 [ V_9 ] && * V_462 [ V_9 ] ) {
F_14 (KERN_ERR SFX L_78 ,
pci_name(pci), patch[dev]) ;
V_22 = F_261 ( V_459 , true , V_462 [ V_9 ] ,
& V_24 -> V_9 , V_340 , V_214 ,
F_255 ) ;
if ( V_22 < 0 )
goto V_461;
V_454 = false ;
}
#endif
if ( V_454 ) {
V_22 = F_210 ( V_2 ) ;
if ( V_22 < 0 )
goto V_461;
}
if ( F_262 ( V_24 ) )
F_263 ( & V_24 -> V_9 ) ;
V_9 ++ ;
F_220 ( & V_2 -> V_377 ) ;
return 0 ;
V_461:
F_256 ( V_214 ) ;
F_257 ( V_24 , NULL ) ;
return V_22 ;
}
static int F_210 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_171 ;
int V_22 ;
#ifdef F_264
V_2 -> V_225 = V_225 [ V_9 ] ;
#endif
V_22 = F_100 ( V_2 , V_198 [ V_9 ] ) ;
if ( V_22 < 0 )
goto V_461;
#ifdef F_225
if ( V_2 -> V_385 ) {
V_22 = F_265 ( V_2 -> V_57 , V_2 -> V_385 -> V_155 ,
V_2 -> V_385 -> V_120 ) ;
if ( V_22 < 0 )
goto V_461;
#ifndef F_94
F_226 ( V_2 -> V_385 ) ;
V_2 -> V_385 = NULL ;
#endif
}
#endif
if ( ( V_444 [ V_9 ] & 1 ) == 0 ) {
V_22 = F_103 ( V_2 ) ;
if ( V_22 < 0 )
goto V_461;
}
V_22 = F_266 ( V_2 -> V_57 ) ;
if ( V_22 < 0 )
goto V_461;
V_22 = F_170 ( V_2 ) ;
if ( V_22 < 0 )
goto V_461;
V_22 = F_267 ( V_2 -> V_214 ) ;
if ( V_22 < 0 )
goto V_461;
V_2 -> V_145 = 1 ;
F_254 ( V_2 ) ;
F_202 ( V_2 ) ;
F_178 ( V_2 ) ;
return 0 ;
V_461:
V_2 -> V_378 = 1 ;
return V_22 ;
}
static void F_268 ( struct V_117 * V_24 )
{
struct V_363 * V_214 = F_207 ( V_24 ) ;
if ( F_262 ( V_24 ) )
F_269 ( & V_24 -> V_9 ) ;
if ( V_214 )
F_256 ( V_214 ) ;
F_257 ( V_24 , NULL ) ;
}
