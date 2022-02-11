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
unsigned int V_39 , V_40 ;
F_16 ( & V_2 -> V_26 ) ;
V_39 = F_27 ( V_2 , V_33 ) ;
if ( V_39 == 0xffff ) {
F_21 ( & V_2 -> V_26 ) ;
return - V_59 ;
}
V_39 ++ ;
V_39 %= V_60 ;
V_40 = F_27 ( V_2 , V_34 ) ;
if ( V_39 == V_40 ) {
F_21 ( & V_2 -> V_26 ) ;
return - V_61 ;
}
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
V_29 V_55 , V_62 ;
V_39 = F_27 ( V_2 , V_45 ) ;
if ( V_39 == 0xffff ) {
return;
}
if ( V_39 == V_2 -> V_38 . V_39 )
return;
V_2 -> V_38 . V_39 = V_39 ;
while ( V_2 -> V_38 . V_40 != V_39 ) {
V_2 -> V_38 . V_40 ++ ;
V_2 -> V_38 . V_40 %= V_63 ;
V_40 = V_2 -> V_38 . V_40 << 1 ;
V_62 = F_30 ( V_2 -> V_38 . V_17 [ V_40 + 1 ] ) ;
V_55 = F_30 ( V_2 -> V_38 . V_17 [ V_40 ] ) ;
V_28 = F_25 ( V_62 ) ;
if ( V_62 & V_64 )
F_31 ( V_2 -> V_57 , V_55 , V_62 ) ;
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
unsigned long V_65 ;
unsigned long V_66 ;
int V_67 = 0 ;
V_68:
V_65 = V_69 + F_34 ( 1000 ) ;
for ( V_66 = 0 ; ; V_66 ++ ) {
if ( V_2 -> V_70 || V_67 ) {
F_16 ( & V_2 -> V_26 ) ;
F_29 ( V_2 ) ;
F_21 ( & V_2 -> V_26 ) ;
}
if ( ! V_2 -> V_38 . V_41 [ V_28 ] ) {
F_35 () ;
V_57 -> V_71 = 0 ;
if ( ! V_67 )
V_2 -> V_72 = 0 ;
return V_2 -> V_38 . V_55 [ V_28 ] ;
}
if ( F_36 ( V_69 , V_65 ) )
break;
if ( V_57 -> V_73 || V_66 > 3000 )
F_37 ( 2 ) ;
else {
F_38 ( 10 ) ;
F_39 () ;
}
}
if ( ! V_2 -> V_70 && V_2 -> V_72 < 2 ) {
F_40 ( V_74 L_4
L_5 ,
F_41 ( V_2 -> V_24 ) , V_2 -> V_75 [ V_28 ] ) ;
V_67 = 1 ;
V_2 -> V_72 ++ ;
goto V_68;
}
if ( ! V_2 -> V_70 ) {
F_14 (KERN_WARNING SFX L_4
L_6 ,
pci_name(chip->pci), chip->last_cmd[addr]) ;
V_2 -> V_70 = 1 ;
goto V_68;
}
if ( V_2 -> V_76 ) {
F_14 (KERN_WARNING SFX L_7
L_8 ,
pci_name(chip->pci), chip->last_cmd[addr]) ;
F_42 ( V_2 -> V_77 , V_2 ) ;
V_2 -> V_77 = - 1 ;
F_43 ( V_2 -> V_24 ) ;
V_2 -> V_76 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 ) {
V_57 -> V_71 = 1 ;
return - 1 ;
}
goto V_68;
}
if ( V_2 -> V_78 ) {
return - 1 ;
}
V_57 -> V_71 = 1 ;
if ( V_57 -> V_79 && ! V_57 -> V_80 && ! V_57 -> V_81 ) {
V_57 -> V_80 = 1 ;
return - 1 ;
}
F_14 ( V_82 L_9
L_10 ,
V_2 -> V_75 [ V_28 ] ) ;
V_2 -> V_83 = 1 ;
V_57 -> V_80 = 0 ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_84 , F_45 ( V_2 , V_84 ) & ~ V_85 ) ;
return - 1 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_65 = 50 ;
while ( V_65 -- ) {
if ( F_27 ( V_2 , V_86 ) & V_87 ) {
V_2 -> V_38 . V_55 [ V_28 ] = F_45 ( V_2 , V_88 ) ;
return 0 ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_74 L_11 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_86 ) ) ;
V_2 -> V_38 . V_55 [ V_28 ] = - 1 ;
return - V_59 ;
}
static int F_49 ( struct V_56 * V_57 , V_29 V_58 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
unsigned int V_28 = F_23 ( V_58 ) ;
int V_65 = 50 ;
V_57 -> V_71 = 0 ;
while ( V_65 -- ) {
if ( ! ( ( F_27 ( V_2 , V_86 ) & V_89 ) ) ) {
F_20 ( V_2 , V_86 , F_27 ( V_2 , V_86 ) |
V_87 ) ;
F_17 ( V_2 , V_90 , V_58 ) ;
F_20 ( V_2 , V_86 , F_27 ( V_2 , V_86 ) |
V_89 ) ;
return F_46 ( V_2 , V_28 ) ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_74 L_12 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_86 ) , V_58 ) ;
return - V_59 ;
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
if ( V_2 -> V_91 )
return 0 ;
V_2 -> V_75 [ F_23 ( V_58 ) ] = V_58 ;
if ( V_2 -> V_83 )
return F_49 ( V_57 , V_58 ) ;
else
return F_26 ( V_57 , V_58 ) ;
}
static unsigned int F_52 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( V_2 -> V_91 )
return 0 ;
if ( V_2 -> V_83 )
return F_50 ( V_57 , V_28 ) ;
else
return F_33 ( V_57 , V_28 ) ;
}
static int F_53 ( struct V_1 * V_2 , int V_92 )
{
unsigned long V_65 ;
if ( ! V_92 )
goto V_93;
F_19 ( V_2 , V_94 , V_95 ) ;
F_17 ( V_2 , V_84 , F_45 ( V_2 , V_84 ) & ~ V_96 ) ;
V_65 = V_69 + F_34 ( 100 ) ;
while ( F_54 ( V_2 , V_84 ) &&
F_55 ( V_69 , V_65 ) )
F_56 ( 500 , 1000 ) ;
F_56 ( 500 , 1000 ) ;
F_19 ( V_2 , V_84 , F_54 ( V_2 , V_84 ) | V_96 ) ;
V_65 = V_69 + F_34 ( 100 ) ;
while ( ! F_54 ( V_2 , V_84 ) &&
F_55 ( V_69 , V_65 ) )
F_56 ( 500 , 1000 ) ;
F_56 ( 1000 , 1200 ) ;
V_93:
if ( ! F_54 ( V_2 , V_84 ) ) {
F_48 ( V_74 L_13 , F_41 ( V_2 -> V_24 ) ) ;
return - V_97 ;
}
if ( ! V_2 -> V_83 )
F_17 ( V_2 , V_84 , F_45 ( V_2 , V_84 ) |
V_85 ) ;
if ( ! V_2 -> V_98 ) {
V_2 -> V_98 = F_27 ( V_2 , V_94 ) ;
F_40 ( V_74 L_14 , F_41 ( V_2 -> V_24 ) , V_2 -> V_98 ) ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_99 , F_45 ( V_2 , V_99 ) |
V_100 | V_101 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_102 ] ;
F_59 ( V_18 , V_104 ,
F_60 ( V_18 , V_104 ) & ~ V_105 ) ;
}
F_19 ( V_2 , V_99 , 0 ) ;
F_17 ( V_2 , V_99 , F_45 ( V_2 , V_99 ) &
~ ( V_100 | V_101 ) ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_102 ] ;
F_59 ( V_18 , V_106 , V_105 ) ;
}
F_19 ( V_2 , V_94 , V_95 ) ;
F_19 ( V_2 , V_107 , V_108 ) ;
F_17 ( V_2 , V_109 , V_100 | V_110 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_18 -> V_111 = 1 ;
F_17 ( V_2 , V_99 ,
F_45 ( V_2 , V_99 ) | ( 1 << V_18 -> V_112 ) ) ;
F_59 ( V_18 , V_104 , F_60 ( V_18 , V_104 ) |
V_113 | V_105 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_59 ( V_18 , V_104 , F_60 ( V_18 , V_104 ) &
~ ( V_113 | V_105 ) ) ;
F_59 ( V_18 , V_106 , V_105 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_63 ( V_2 , V_18 ) ;
F_17 ( V_2 , V_99 ,
F_45 ( V_2 , V_99 ) & ~ ( 1 << V_18 -> V_112 ) ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_92 )
{
if ( V_2 -> V_114 )
return;
F_53 ( V_2 , V_92 ) ;
F_61 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( ! V_2 -> V_83 )
F_15 ( V_2 ) ;
F_17 ( V_2 , V_115 , ( V_29 ) V_2 -> V_116 . V_28 ) ;
F_17 ( V_2 , V_117 , F_18 ( V_2 -> V_116 . V_28 ) ) ;
V_2 -> V_114 = 1 ;
}
static void F_66 ( struct V_118 * V_24 , unsigned int V_119 ,
unsigned char V_120 , unsigned char V_58 )
{
unsigned char V_121 ;
F_67 ( V_24 , V_119 , & V_121 ) ;
V_121 &= ~ V_120 ;
V_121 |= ( V_58 & V_120 ) ;
F_68 ( V_24 , V_119 , V_121 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_47 & V_122 ) ) {
F_40 ( V_74 L_15 , F_41 ( V_2 -> V_24 ) ) ;
F_66 ( V_2 -> V_24 , V_123 , 0x07 , 0 ) ;
}
if ( V_2 -> V_47 & V_124 ) {
F_40 ( V_74 L_16 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_66 ( V_2 -> V_24 ,
V_125 , 0x07 ,
F_2 ( V_2 ) ? V_126 : 0 ) ;
}
if ( V_2 -> V_47 & V_127 ) {
F_40 ( V_74 L_17 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_66 ( V_2 -> V_24 ,
V_128 ,
0x0f , V_129 ) ;
F_66 ( V_2 -> V_24 ,
V_130 ,
0x01 , V_131 ) ;
F_66 ( V_2 -> V_24 ,
V_132 ,
0x01 , V_131 ) ;
}
if ( V_2 -> V_47 & V_133 ) {
unsigned short V_134 ;
F_70 ( V_2 -> V_24 , V_135 , & V_134 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_134 & V_136 ) ) ||
( F_2 ( V_2 ) && ( V_134 & V_136 ) ) ) {
V_134 &= ~ V_136 ;
if ( ! F_2 ( V_2 ) )
V_134 |= V_136 ;
F_71 ( V_2 -> V_24 , V_135 , V_134 ) ;
F_70 ( V_2 -> V_24 ,
V_135 , & V_134 ) ;
}
F_40 ( V_74 L_18 ,
F_41 ( V_2 -> V_24 ) , ( V_134 & V_136 )
? L_19 : L_20 ) ;
}
}
static T_1 F_72 ( int V_77 , void * V_137 )
{
struct V_1 * V_2 = V_137 ;
struct V_18 * V_18 ;
V_29 V_138 ;
T_2 V_139 ;
int V_102 , V_140 ;
#ifdef F_73
if ( V_2 -> V_24 -> V_9 . V_141 . V_142 != V_143 )
return V_144 ;
#endif
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_91 ) {
F_75 ( & V_2 -> V_26 ) ;
return V_144 ;
}
V_138 = F_45 ( V_2 , V_109 ) ;
if ( V_138 == 0 ) {
F_75 ( & V_2 -> V_26 ) ;
return V_144 ;
}
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
V_18 = & V_2 -> V_18 [ V_102 ] ;
if ( V_138 & V_18 -> V_145 ) {
V_139 = F_60 ( V_18 , V_106 ) ;
F_59 ( V_18 , V_106 , V_105 ) ;
if ( ! V_18 -> V_20 || ! V_18 -> V_146 ||
! ( V_139 & V_147 ) )
continue;
V_140 = F_76 ( V_2 , V_18 ) ;
if ( V_140 == 1 ) {
V_18 -> V_148 = 0 ;
F_75 ( & V_2 -> V_26 ) ;
F_77 ( V_18 -> V_20 ) ;
F_74 ( & V_2 -> V_26 ) ;
} else if ( V_140 == 0 && V_2 -> V_57 && V_2 -> V_57 -> V_149 ) {
V_18 -> V_148 = 1 ;
F_78 ( V_2 -> V_57 -> V_149 ,
& V_2 -> V_150 ) ;
}
}
}
V_138 = F_54 ( V_2 , V_107 ) ;
if ( V_138 & V_108 ) {
if ( V_138 & V_151 ) {
if ( V_2 -> V_47 & V_152 )
F_38 ( 80 ) ;
F_29 ( V_2 ) ;
}
F_19 ( V_2 , V_107 , V_108 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_75 ( & V_2 -> V_26 ) ;
return V_153 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_18 , V_29 * * V_154 ,
int V_155 , int V_156 , int V_157 )
{
V_29 * V_158 = * V_154 ;
while ( V_156 > 0 ) {
T_3 V_28 ;
int V_159 ;
if ( V_18 -> V_160 >= V_161 )
return - V_162 ;
V_28 = F_80 ( V_4 , V_155 ) ;
V_158 [ 0 ] = F_28 ( ( V_29 ) V_28 ) ;
V_158 [ 1 ] = F_28 ( F_18 ( V_28 ) ) ;
V_159 = F_81 ( V_4 , V_155 , V_156 ) ;
if ( V_2 -> V_47 & V_163 ) {
V_29 V_164 = 0x1000 - ( V_155 & 0xfff ) ;
if ( V_159 > V_164 )
V_159 = V_164 ;
}
V_158 [ 2 ] = F_28 ( V_159 ) ;
V_156 -= V_159 ;
V_158 [ 3 ] = ( V_156 || ! V_157 ) ? 0 : F_28 ( 0x01 ) ;
V_158 += 4 ;
V_18 -> V_160 ++ ;
V_155 += V_159 ;
}
* V_154 = V_158 ;
return V_155 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_18 * V_18 )
{
V_29 * V_158 ;
int V_102 , V_155 , V_165 , V_166 ;
int V_167 ;
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_169 , 0 ) ;
V_166 = V_18 -> V_166 ;
V_165 = V_18 -> V_170 / V_166 ;
V_158 = ( V_29 * ) V_18 -> V_158 . V_7 ;
V_155 = 0 ;
V_18 -> V_160 = 0 ;
V_167 = V_171 [ V_2 -> V_172 ] ;
if ( ! V_18 -> V_173 && V_167 > 0 ) {
struct V_174 * V_175 = V_20 -> V_175 ;
int V_176 = V_167 ;
V_167 = ( V_167 * V_175 -> V_177 + 47999 ) / 48000 ;
if ( ! V_167 )
V_167 = V_176 ;
else
V_167 = ( ( V_167 + V_176 - 1 ) / V_176 ) *
V_176 ;
V_167 = F_84 ( V_175 , V_167 ) ;
if ( V_167 >= V_166 ) {
F_14 (KERN_WARNING SFX L_21 ,
pci_name(chip->pci), bdl_pos_adj[chip->dev_index]) ;
V_167 = 0 ;
} else {
V_155 = F_79 ( V_2 , F_10 ( V_20 ) ,
V_18 ,
& V_158 , V_155 , V_167 , true ) ;
if ( V_155 < 0 )
goto error;
}
} else
V_167 = 0 ;
for ( V_102 = 0 ; V_102 < V_165 ; V_102 ++ ) {
if ( V_102 == V_165 - 1 && V_167 )
V_155 = F_79 ( V_2 , F_10 ( V_20 ) ,
V_18 , & V_158 , V_155 ,
V_166 - V_167 , 0 ) ;
else
V_155 = F_79 ( V_2 , F_10 ( V_20 ) ,
V_18 , & V_158 , V_155 ,
V_166 ,
! V_18 -> V_173 ) ;
if ( V_155 < 0 )
goto error;
}
return 0 ;
error:
F_14 (KERN_ERR SFX L_22 ,
pci_name(chip->pci), azx_dev->bufsize, period_bytes) ;
return - V_162 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned char V_58 ;
int V_65 ;
F_63 ( V_2 , V_18 ) ;
F_59 ( V_18 , V_104 , F_60 ( V_18 , V_104 ) |
V_178 ) ;
F_38 ( 3 ) ;
V_65 = 300 ;
while ( ! ( ( V_58 = F_60 ( V_18 , V_104 ) ) & V_178 ) &&
-- V_65 )
;
V_58 &= ~ V_178 ;
F_59 ( V_18 , V_104 , V_58 ) ;
F_38 ( 3 ) ;
V_65 = 300 ;
while ( ( ( V_58 = F_60 ( V_18 , V_104 ) ) & V_178 ) &&
-- V_65 )
;
* V_18 -> V_116 = 0 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned int V_58 ;
F_63 ( V_2 , V_18 ) ;
V_58 = F_87 ( V_18 , V_104 ) ;
V_58 = ( V_58 & ~ V_179 ) |
( V_18 -> V_180 << V_181 ) ;
if ( ! F_2 ( V_2 ) )
V_58 |= V_182 ;
F_83 ( V_18 , V_104 , V_58 ) ;
F_83 ( V_18 , V_183 , V_18 -> V_170 ) ;
F_88 ( V_18 , V_184 , V_18 -> V_185 ) ;
F_88 ( V_18 , V_186 , V_18 -> V_160 - 1 ) ;
F_83 ( V_18 , V_168 , ( V_29 ) V_18 -> V_158 . V_28 ) ;
F_83 ( V_18 , V_169 , F_18 ( V_18 -> V_158 . V_28 ) ) ;
if ( V_2 -> V_187 [ 0 ] != V_188 ||
V_2 -> V_187 [ 1 ] != V_188 ) {
if ( ! ( F_45 ( V_2 , V_115 ) & V_189 ) )
F_17 ( V_2 , V_115 ,
( V_29 ) V_2 -> V_116 . V_28 | V_189 ) ;
}
F_83 ( V_18 , V_104 ,
F_87 ( V_18 , V_104 ) | V_105 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_53 = ( V_28 << 28 ) | ( V_190 << 20 ) |
( V_191 << 8 ) | V_192 ;
unsigned int V_55 ;
F_90 ( & V_2 -> V_57 -> V_193 ) ;
V_2 -> V_78 = 1 ;
F_51 ( V_2 -> V_57 , V_53 ) ;
V_55 = F_52 ( V_2 -> V_57 , V_28 ) ;
V_2 -> V_78 = 0 ;
F_91 ( & V_2 -> V_57 -> V_193 ) ;
if ( V_55 == - 1 )
return - V_59 ;
F_40 ( V_74 L_23 , F_41 ( V_2 -> V_24 ) , V_28 ) ;
return 0 ;
}
static void F_92 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
V_57 -> V_81 = 1 ;
F_93 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
#ifdef F_94
if ( V_2 -> V_114 ) {
struct V_194 * V_195 ;
F_95 (p, &chip->pcm_list, list)
F_96 ( V_195 -> V_196 ) ;
F_97 ( V_2 -> V_57 ) ;
F_98 ( V_2 -> V_57 ) ;
}
#endif
V_57 -> V_81 = 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_102 = V_197 [ V_2 -> V_172 ] ;
unsigned int V_198 ;
if ( V_102 == 0 )
return 0 ;
if ( V_102 < 50 || V_102 > 60000 )
V_198 = 0 ;
else
V_198 = F_34 ( V_102 ) ;
if ( V_198 == 0 )
F_14 (KERN_WARNING SFX
L_24 , i) ;
return V_198 ;
}
static int F_100 ( struct V_1 * V_2 , const char * V_199 )
{
struct V_200 V_201 ;
int V_202 , V_203 , V_22 ;
int V_204 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_13 = V_2 ;
V_201 . V_205 = V_199 ;
V_201 . V_24 = V_2 -> V_24 ;
V_201 . V_206 . V_207 = F_51 ;
V_201 . V_206 . V_208 = F_52 ;
V_201 . V_206 . V_209 = V_210 ;
V_201 . V_206 . V_211 = F_92 ;
#ifdef F_94
V_201 . V_212 = & V_212 ;
V_201 . V_206 . V_213 = V_214 ;
#endif
#ifdef F_101
V_201 . V_206 . V_215 = V_216 ;
V_201 . V_206 . V_217 = V_218 ;
V_201 . V_206 . V_219 = V_220 ;
#endif
V_22 = F_102 ( V_2 -> V_221 , & V_201 , & V_2 -> V_57 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_2 -> V_47 & V_222 ) {
F_48 ( V_74 L_25 , F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_73 = 1 ;
}
V_203 = 0 ;
V_204 = V_223 [ V_2 -> V_224 ] ;
if ( ! V_204 )
V_204 = V_225 ;
for ( V_202 = 0 ; V_202 < V_204 ; V_202 ++ ) {
if ( ( V_2 -> V_98 & ( 1 << V_202 ) ) & V_2 -> V_226 ) {
if ( F_89 ( V_2 , V_202 ) < 0 ) {
F_14 (KERN_WARNING SFX
L_26
L_27 , pci_name(chip->pci), c) ;
V_2 -> V_98 &= ~ ( 1 << V_202 ) ;
F_93 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_47 & V_227 ) {
F_48 ( V_74 L_28 ,
F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_228 = 1 ;
V_2 -> V_57 -> V_79 = 1 ;
}
for ( V_202 = 0 ; V_202 < V_204 ; V_202 ++ ) {
if ( ( V_2 -> V_98 & ( 1 << V_202 ) ) & V_2 -> V_226 ) {
struct V_229 * V_230 ;
V_22 = F_103 ( V_2 -> V_57 , V_202 , & V_230 ) ;
if ( V_22 < 0 )
continue;
V_230 -> V_231 = F_99 ( V_2 ) ;
V_230 -> V_232 = V_2 -> V_232 ;
V_203 ++ ;
}
}
if ( ! V_203 ) {
F_14 (KERN_ERR SFX L_29 , pci_name(chip->pci)) ;
return - V_233 ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_229 * V_230 ;
F_95 (codec, &chip->bus->codec_list, list) {
F_105 ( V_230 ) ;
}
return 0 ;
}
static inline struct V_18 *
F_106 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_9 , V_102 , V_234 ;
struct V_18 * V_55 = NULL ;
int V_235 = ( V_20 -> V_196 -> V_236 << 16 ) | ( V_20 -> V_237 << 2 ) |
( V_20 -> V_238 + 1 ) ;
if ( V_20 -> V_238 == V_239 ) {
V_9 = V_2 -> V_240 ;
V_234 = V_2 -> V_241 ;
} else {
V_9 = V_2 -> V_242 ;
V_234 = V_2 -> V_243 ;
}
for ( V_102 = 0 ; V_102 < V_234 ; V_102 ++ , V_9 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_9 ] ;
F_107 ( V_18 ) ;
if ( ! V_18 -> V_244 && ! F_108 ( V_18 ) ) {
V_55 = V_18 ;
if ( V_55 -> V_245 == V_235 ) {
V_55 -> V_244 = 1 ;
V_55 -> V_245 = V_235 ;
F_109 ( V_18 ) ;
return V_18 ;
}
}
F_109 ( V_18 ) ;
}
if ( V_55 ) {
F_107 ( V_55 ) ;
V_55 -> V_244 = 1 ;
V_55 -> V_245 = V_235 ;
F_109 ( V_55 ) ;
}
return V_55 ;
}
static inline void F_110 ( struct V_18 * V_18 )
{
V_18 -> V_244 = 0 ;
}
static T_4 F_111 ( const struct V_246 * V_247 )
{
struct V_18 * V_18 = F_112 ( V_247 , struct V_18 , V_248 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
return F_45 ( V_2 , V_250 ) ;
}
static void F_114 ( struct V_19 * V_20 ,
bool V_251 , T_4 V_252 )
{
struct V_18 * V_18 = F_115 ( V_20 ) ;
struct V_253 * V_254 = & V_18 -> V_255 ;
struct V_246 * V_247 = & V_18 -> V_248 ;
T_5 V_256 ;
V_247 -> V_257 = F_111 ;
V_247 -> V_120 = F_116 ( 32 ) ;
V_247 -> V_258 = 125 ;
V_247 -> V_259 = 0 ;
V_256 = 0 ;
F_117 ( V_254 , V_247 , V_256 ) ;
if ( V_251 )
V_254 -> V_260 = V_252 ;
}
static T_5 F_118 ( struct V_19 * V_20 ,
T_5 V_256 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_261 * V_262 = V_249 -> V_262 [ V_20 -> V_238 ] ;
T_5 V_263 , V_264 ;
if ( ! V_262 -> V_206 . V_265 )
return V_256 ;
V_263 = V_262 -> V_206 . V_265 ( V_262 , V_249 -> V_230 , V_20 ) ;
V_264 = F_119 ( V_263 * 1000000000LL ,
V_20 -> V_175 -> V_177 ) ;
if ( V_20 -> V_238 == V_266 )
return V_256 + V_264 ;
return ( V_256 > V_264 ) ? V_256 - V_264 : 0 ;
}
static int F_120 ( struct V_19 * V_20 ,
struct V_267 * V_268 )
{
struct V_18 * V_18 = F_115 ( V_20 ) ;
T_5 V_256 ;
V_256 = F_121 ( & V_18 -> V_255 ) ;
V_256 = F_119 ( V_256 , 3 ) ;
V_256 = F_118 ( V_20 , V_256 ) ;
* V_268 = F_122 ( V_256 ) ;
return 0 ;
}
static int F_123 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_261 * V_262 = V_249 -> V_262 [ V_20 -> V_238 ] ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 ;
struct V_174 * V_175 = V_20 -> V_175 ;
unsigned long V_269 ;
int V_22 ;
int V_270 ;
F_90 ( & V_2 -> V_271 ) ;
V_18 = F_106 ( V_2 , V_20 ) ;
if ( V_18 == NULL ) {
F_91 ( & V_2 -> V_271 ) ;
return - V_97 ;
}
V_175 -> V_272 = V_273 ;
V_175 -> V_272 . V_274 = V_262 -> V_274 ;
V_175 -> V_272 . V_275 = V_262 -> V_275 ;
V_175 -> V_272 . V_276 = V_262 -> V_276 ;
V_175 -> V_272 . V_277 = V_262 -> V_277 ;
F_124 ( V_175 ) ;
F_125 ( V_175 , V_278 ) ;
F_126 ( V_175 , V_279 ,
20 ,
178000000 ) ;
if ( V_2 -> V_280 )
V_270 = 128 ;
else
V_270 = 4 ;
F_127 ( V_175 , 0 , V_281 ,
V_270 ) ;
F_127 ( V_175 , 0 , V_282 ,
V_270 ) ;
F_128 ( V_249 -> V_230 ) ;
V_22 = V_262 -> V_206 . V_283 ( V_262 , V_249 -> V_230 , V_20 ) ;
if ( V_22 < 0 ) {
F_110 ( V_18 ) ;
F_129 ( V_249 -> V_230 ) ;
F_91 ( & V_2 -> V_271 ) ;
return V_22 ;
}
F_124 ( V_175 ) ;
if ( F_130 ( ! V_175 -> V_272 . V_274 ) ||
F_130 ( ! V_175 -> V_272 . V_275 ) ||
F_130 ( ! V_175 -> V_272 . V_276 ) ||
F_130 ( ! V_175 -> V_272 . V_277 ) ) {
F_110 ( V_18 ) ;
V_262 -> V_206 . V_284 ( V_262 , V_249 -> V_230 , V_20 ) ;
F_129 ( V_249 -> V_230 ) ;
F_91 ( & V_2 -> V_271 ) ;
return - V_162 ;
}
if ( V_20 -> V_238 == V_266 )
V_175 -> V_272 . V_285 &= ~ V_286 ;
F_131 ( & V_2 -> V_26 , V_269 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_146 = 0 ;
F_132 ( & V_2 -> V_26 , V_269 ) ;
V_175 -> V_13 = V_18 ;
F_133 ( V_20 ) ;
F_91 ( & V_2 -> V_271 ) ;
return 0 ;
}
static int F_134 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_261 * V_262 = V_249 -> V_262 [ V_20 -> V_238 ] ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
unsigned long V_269 ;
F_90 ( & V_2 -> V_271 ) ;
F_131 ( & V_2 -> V_26 , V_269 ) ;
V_18 -> V_20 = NULL ;
V_18 -> V_146 = 0 ;
F_132 ( & V_2 -> V_26 , V_269 ) ;
F_110 ( V_18 ) ;
V_262 -> V_206 . V_284 ( V_262 , V_249 -> V_230 , V_20 ) ;
F_129 ( V_249 -> V_230 ) ;
F_91 ( & V_2 -> V_271 ) ;
return 0 ;
}
static int F_135 ( struct V_19 * V_20 ,
struct V_287 * V_288 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
int V_289 ;
F_107 ( V_18 ) ;
if ( F_108 ( V_18 ) ) {
V_289 = - V_97 ;
goto V_290;
}
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_170 = 0 ;
V_18 -> V_166 = 0 ;
V_18 -> V_185 = 0 ;
V_289 = F_136 ( V_20 ,
F_137 ( V_288 ) ) ;
if ( V_289 < 0 )
goto V_290;
F_9 ( V_2 , V_18 , V_20 , true ) ;
V_290:
F_109 ( V_18 ) ;
return V_289 ;
}
static int F_138 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_261 * V_262 = V_249 -> V_262 [ V_20 -> V_238 ] ;
F_107 ( V_18 ) ;
if ( ! F_108 ( V_18 ) ) {
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_169 , 0 ) ;
F_83 ( V_18 , V_104 , 0 ) ;
V_18 -> V_170 = 0 ;
V_18 -> V_166 = 0 ;
V_18 -> V_185 = 0 ;
}
F_139 ( V_249 -> V_230 , V_262 , V_20 ) ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_291 = 0 ;
F_109 ( V_18 ) ;
return F_140 ( V_20 ) ;
}
static int F_141 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
struct V_261 * V_262 = V_249 -> V_262 [ V_20 -> V_238 ] ;
struct V_174 * V_175 = V_20 -> V_175 ;
unsigned int V_170 , V_166 , V_185 , V_180 ;
int V_22 ;
struct V_292 * V_293 =
F_142 ( V_249 -> V_230 , V_262 -> V_294 ) ;
unsigned short V_295 = V_293 ? V_293 -> V_295 : 0 ;
F_107 ( V_18 ) ;
if ( F_108 ( V_18 ) ) {
V_22 = - V_97 ;
goto V_290;
}
F_85 ( V_2 , V_18 ) ;
V_185 = F_143 ( V_175 -> V_177 ,
V_175 -> V_296 ,
V_175 -> V_297 ,
V_262 -> V_298 ,
V_295 ) ;
if ( ! V_185 ) {
F_14 (KERN_ERR SFX
L_30 ,
pci_name(chip->pci), runtime->rate, runtime->channels, runtime->format) ;
V_22 = - V_162 ;
goto V_290;
}
V_170 = F_144 ( V_20 ) ;
V_166 = F_145 ( V_20 ) ;
F_40 ( V_74 L_31 ,
F_41 ( V_2 -> V_24 ) , V_170 , V_185 ) ;
if ( V_170 != V_18 -> V_170 ||
V_166 != V_18 -> V_166 ||
V_185 != V_18 -> V_185 ||
V_175 -> V_173 != V_18 -> V_173 ) {
V_18 -> V_170 = V_170 ;
V_18 -> V_166 = V_166 ;
V_18 -> V_185 = V_185 ;
V_18 -> V_173 = V_175 -> V_173 ;
V_22 = F_82 ( V_2 , V_20 , V_18 ) ;
if ( V_22 < 0 )
goto V_290;
}
V_18 -> V_299 = ( ( ( V_175 -> V_300 * 24000 ) /
V_175 -> V_177 ) * 1000 ) ;
F_86 ( V_2 , V_18 ) ;
if ( V_20 -> V_238 == V_239 )
V_18 -> V_301 = F_146 ( V_18 , V_302 ) + 1 ;
else
V_18 -> V_301 = 0 ;
V_180 = V_18 -> V_180 ;
if ( ( V_2 -> V_47 & V_48 ) &&
V_180 > V_2 -> V_243 )
V_180 -= V_2 -> V_243 ;
V_22 = F_147 ( V_249 -> V_230 , V_262 , V_180 ,
V_18 -> V_185 , V_20 ) ;
V_290:
if ( ! V_22 )
V_18 -> V_291 = 1 ;
F_109 ( V_18 ) ;
return V_22 ;
}
static int F_148 ( struct V_19 * V_20 , int V_53 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 ;
struct V_19 * V_303 ;
int V_304 = 0 , V_305 , V_306 = 0 , V_307 = 0 ;
int V_308 , V_65 ;
V_18 = F_115 ( V_20 ) ;
F_149 ( V_2 , V_18 , V_53 ) ;
if ( F_108 ( V_18 ) || ! V_18 -> V_291 )
return - V_309 ;
switch ( V_53 ) {
case V_310 :
V_304 = 1 ;
case V_311 :
case V_312 :
V_305 = 1 ;
break;
case V_313 :
case V_314 :
case V_315 :
V_305 = 0 ;
break;
default:
return - V_162 ;
}
F_150 (s, substream) {
if ( V_303 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_303 ) ;
V_307 |= 1 << V_18 -> V_112 ;
V_306 ++ ;
F_151 ( V_303 , V_20 ) ;
}
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_316 )
F_17 ( V_2 , V_317 ,
F_45 ( V_2 , V_317 ) | V_307 ) ;
else
F_17 ( V_2 , V_318 , F_45 ( V_2 , V_318 ) | V_307 ) ;
F_150 (s, substream) {
if ( V_303 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_303 ) ;
if ( V_305 ) {
V_18 -> V_319 = F_45 ( V_2 , V_250 ) ;
if ( ! V_304 )
V_18 -> V_319 -=
V_18 -> V_299 ;
F_62 ( V_2 , V_18 ) ;
} else {
F_64 ( V_2 , V_18 ) ;
}
V_18 -> V_146 = V_305 ;
}
F_75 ( & V_2 -> V_26 ) ;
if ( V_305 ) {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_308 = 0 ;
F_150 (s, substream) {
if ( V_303 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_303 ) ;
if ( ! ( F_60 ( V_18 , V_106 ) &
V_320 ) )
V_308 ++ ;
}
if ( ! V_308 )
break;
F_152 () ;
}
} else {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_308 = 0 ;
F_150 (s, substream) {
if ( V_303 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_303 ) ;
if ( F_60 ( V_18 , V_104 ) &
V_113 )
V_308 ++ ;
}
if ( ! V_308 )
break;
F_152 () ;
}
}
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_316 )
F_17 ( V_2 , V_317 ,
F_45 ( V_2 , V_317 ) & ~ V_307 ) ;
else
F_17 ( V_2 , V_318 , F_45 ( V_2 , V_318 ) & ~ V_307 ) ;
if ( V_305 ) {
F_114 ( V_20 , 0 , 0 ) ;
if ( V_306 > 1 ) {
T_4 V_260 ;
V_18 = F_115 ( V_20 ) ;
V_260 = V_18 -> V_255 . V_260 ;
F_150 (s, substream) {
if ( V_303 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
F_114 ( V_303 , 1 , V_260 ) ;
}
}
}
F_75 ( & V_2 -> V_26 ) ;
return 0 ;
}
static unsigned int F_153 ( struct V_1 * V_2 ,
struct V_18 * V_18 )
{
unsigned int V_321 , V_322 , V_323 ;
unsigned int V_324 , V_325 , V_326 ;
unsigned int V_301 ;
V_321 = F_87 ( V_18 , V_327 ) ;
if ( V_18 -> V_20 -> V_238 == V_239 ) {
return V_321 ;
}
V_325 = F_30 ( * V_18 -> V_116 ) ;
V_325 %= V_18 -> V_166 ;
V_301 = F_154 ( V_2 -> V_328 + V_329 ) ;
if ( V_18 -> V_111 ) {
if ( V_321 <= V_301 )
return 0 ;
V_18 -> V_111 = 0 ;
}
if ( V_321 <= V_301 )
V_322 = V_18 -> V_170 + V_321 - V_301 ;
else
V_322 = V_321 - V_301 ;
V_326 = V_322 % V_18 -> V_166 ;
V_324 = V_321 % V_18 -> V_166 ;
if ( V_324 >= V_301 )
V_323 = V_321 - V_324 ;
else if ( V_325 >= V_326 )
V_323 = V_322 - V_326 ;
else {
V_323 = V_322 - V_326 + V_18 -> V_166 ;
if ( V_323 >= V_18 -> V_170 )
V_323 = 0 ;
}
return V_323 + V_325 ;
}
static unsigned int F_155 ( struct V_1 * V_2 ,
struct V_18 * V_18 ,
bool V_330 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_194 * V_249 = F_113 ( V_20 ) ;
unsigned int V_331 ;
int V_238 = V_20 -> V_238 ;
struct V_261 * V_262 = V_249 -> V_262 [ V_238 ] ;
int V_332 = 0 ;
switch ( V_2 -> V_187 [ V_238 ] ) {
case V_188 :
V_331 = F_87 ( V_18 , V_327 ) ;
break;
case V_333 :
V_331 = F_153 ( V_2 , V_18 ) ;
break;
default:
V_331 = F_30 ( * V_18 -> V_116 ) ;
if ( V_330 && V_2 -> V_187 [ V_238 ] == V_334 ) {
if ( ! V_331 || V_331 == ( V_29 ) - 1 ) {
F_156 ( V_335
L_32
L_33 ) ;
V_2 -> V_187 [ V_238 ] = V_188 ;
V_331 = F_87 ( V_18 , V_327 ) ;
} else
V_2 -> V_187 [ V_238 ] = V_336 ;
}
break;
}
if ( V_331 >= V_18 -> V_170 )
V_331 = 0 ;
if ( V_20 -> V_175 &&
V_2 -> V_187 [ V_238 ] == V_336 &&
( V_2 -> V_47 & V_337 ) ) {
unsigned int V_338 = F_87 ( V_18 , V_327 ) ;
if ( V_238 == V_239 )
V_332 = V_331 - V_338 ;
else
V_332 = V_338 - V_331 ;
if ( V_332 < 0 )
V_332 += V_18 -> V_170 ;
if ( V_332 >= V_18 -> V_166 ) {
F_14 (KERN_WARNING SFX
L_34
L_35 ,
pci_name(chip->pci), delay, azx_dev->period_bytes) ;
V_332 = 0 ;
V_2 -> V_47 &= ~ V_337 ;
}
V_332 = F_157 ( V_20 -> V_175 , V_332 ) ;
}
if ( V_20 -> V_175 ) {
if ( V_262 -> V_206 . V_265 )
V_332 += V_262 -> V_206 . V_265 ( V_262 , V_249 -> V_230 ,
V_20 ) ;
V_20 -> V_175 -> V_332 = V_332 ;
}
F_158 ( V_2 , V_18 , V_331 , V_332 ) ;
return V_331 ;
}
static T_6 F_159 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
return F_157 ( V_20 -> V_175 ,
F_155 ( V_2 , V_18 , false ) ) ;
}
static int F_76 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_29 V_339 ;
unsigned int V_331 ;
V_339 = F_45 ( V_2 , V_250 ) - V_18 -> V_319 ;
if ( V_339 < ( V_18 -> V_299 * 2 ) / 3 )
return - 1 ;
V_331 = F_155 ( V_2 , V_18 , true ) ;
if ( F_160 ( ! V_18 -> V_166 ,
L_36 ) )
return - 1 ;
if ( V_339 < ( V_18 -> V_299 * 5 ) / 4 &&
V_331 % V_18 -> V_166 > V_18 -> V_166 / 2 )
return V_171 [ V_2 -> V_172 ] ? 0 : - 1 ;
V_18 -> V_319 += V_339 ;
return 1 ;
}
static void F_161 ( struct V_340 * V_341 )
{
struct V_1 * V_2 = F_112 ( V_341 , struct V_1 , V_150 ) ;
int V_102 , V_342 , V_140 ;
if ( ! V_2 -> V_343 ) {
F_156 ( V_335
L_37
L_38 ,
V_2 -> V_221 -> V_237 ) ;
V_2 -> V_343 = 1 ;
}
for (; ; ) {
V_342 = 0 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_102 ] ;
if ( ! V_18 -> V_148 ||
! V_18 -> V_20 ||
! V_18 -> V_146 )
continue;
V_140 = F_76 ( V_2 , V_18 ) ;
if ( V_140 > 0 ) {
V_18 -> V_148 = 0 ;
F_75 ( & V_2 -> V_26 ) ;
F_77 ( V_18 -> V_20 ) ;
F_74 ( & V_2 -> V_26 ) ;
} else if ( V_140 < 0 ) {
V_342 = 0 ;
} else
V_342 ++ ;
}
F_21 ( & V_2 -> V_26 ) ;
if ( ! V_342 )
return;
F_37 ( 1 ) ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
int V_102 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ )
V_2 -> V_18 [ V_102 ] . V_148 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
}
static int F_163 ( struct V_19 * V_20 ,
struct V_344 * V_7 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_7 -> V_345 = F_164 ( V_7 -> V_345 ) ;
return F_165 ( V_20 , V_7 ) ;
}
static void F_166 ( struct V_346 * V_196 )
{
struct V_194 * V_249 = V_196 -> V_13 ;
if ( V_249 ) {
F_167 ( & V_249 -> V_347 ) ;
F_168 ( V_249 ) ;
}
}
static int
V_210 ( struct V_56 * V_57 , struct V_229 * V_230 ,
struct V_348 * V_349 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_346 * V_196 ;
struct V_194 * V_249 ;
int V_350 = V_349 -> V_236 ;
unsigned int V_156 ;
int V_303 , V_22 ;
F_95 (apcm, &chip->pcm_list, list) {
if ( V_249 -> V_196 -> V_236 == V_350 ) {
F_14 (KERN_ERR SFX L_39 ,
pci_name(chip->pci), pcm_dev) ;
return - V_97 ;
}
}
V_22 = F_169 ( V_2 -> V_221 , V_349 -> V_351 , V_350 ,
V_349 -> V_238 [ V_239 ] . V_352 ,
V_349 -> V_238 [ V_266 ] . V_352 ,
& V_196 ) ;
if ( V_22 < 0 )
return V_22 ;
F_170 ( V_196 -> V_351 , V_349 -> V_351 , sizeof( V_196 -> V_351 ) ) ;
V_249 = F_171 ( sizeof( * V_249 ) , V_353 ) ;
if ( V_249 == NULL )
return - V_354 ;
V_249 -> V_2 = V_2 ;
V_249 -> V_196 = V_196 ;
V_249 -> V_230 = V_230 ;
V_196 -> V_13 = V_249 ;
V_196 -> V_355 = F_166 ;
if ( V_349 -> V_356 == V_357 )
V_196 -> V_358 = V_359 ;
F_172 ( & V_249 -> V_347 , & V_2 -> V_360 ) ;
V_349 -> V_196 = V_196 ;
for ( V_303 = 0 ; V_303 < 2 ; V_303 ++ ) {
V_249 -> V_262 [ V_303 ] = & V_349 -> V_238 [ V_303 ] ;
if ( V_349 -> V_238 [ V_303 ] . V_352 )
F_173 ( V_196 , V_303 , & V_361 ) ;
}
V_156 = V_362 * 1024 ;
if ( V_156 > V_363 )
V_156 = V_363 ;
F_174 ( V_196 , V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_156 , V_363 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
return F_176 ( V_2 -> V_57 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_102 ] ;
V_18 -> V_116 = ( V_29 V_364 * ) ( V_2 -> V_116 . V_7 + V_102 * 8 ) ;
V_18 -> V_365 = V_2 -> V_328 + ( 0x20 * V_102 + 0x80 ) ;
V_18 -> V_145 = 1 << V_102 ;
V_18 -> V_112 = V_102 ;
V_18 -> V_180 = V_102 + 1 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_366 )
{
if ( F_178 ( V_2 -> V_24 -> V_77 , F_72 ,
V_2 -> V_76 ? 0 : V_367 ,
V_368 , V_2 ) ) {
F_156 ( V_82 L_40
L_41 , V_2 -> V_24 -> V_77 ) ;
if ( V_366 )
F_179 ( V_2 -> V_221 ) ;
return - 1 ;
}
V_2 -> V_77 = V_2 -> V_24 -> V_77 ;
F_180 ( V_2 -> V_24 , ! V_2 -> V_76 ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_114 )
return;
F_58 ( V_2 ) ;
F_61 ( V_2 ) ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_115 , 0 ) ;
F_17 ( V_2 , V_117 , 0 ) ;
V_2 -> V_114 = 0 ;
}
static struct V_18 *
F_181 ( struct V_1 * V_2 )
{
return & V_2 -> V_18 [ V_2 -> V_240 ] ;
}
static int V_216 ( struct V_56 * V_57 , unsigned int V_297 ,
unsigned int V_369 ,
struct V_3 * V_370 )
{
V_29 * V_158 ;
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 ;
int V_22 ;
V_18 = F_181 ( V_2 ) ;
F_107 ( V_18 ) ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_146 || V_18 -> V_371 ) {
F_21 ( & V_2 -> V_26 ) ;
V_22 = - V_97 ;
goto V_290;
}
V_18 -> V_291 = 0 ;
V_2 -> V_372 = * V_18 ;
V_18 -> V_371 = 1 ;
F_21 ( & V_2 -> V_26 ) ;
V_22 = F_12 ( V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_369 , V_370 ) ;
if ( V_22 < 0 )
goto V_373;
F_8 ( V_2 , V_370 , true ) ;
V_18 -> V_170 = V_369 ;
V_18 -> V_166 = V_369 ;
V_18 -> V_185 = V_297 ;
F_85 ( V_2 , V_18 ) ;
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_169 , 0 ) ;
V_18 -> V_160 = 0 ;
V_158 = ( V_29 * ) V_18 -> V_158 . V_7 ;
V_22 = F_79 ( V_2 , V_370 , V_18 , & V_158 , 0 , V_369 , 0 ) ;
if ( V_22 < 0 )
goto error;
F_86 ( V_2 , V_18 ) ;
F_109 ( V_18 ) ;
return V_18 -> V_180 ;
error:
F_8 ( V_2 , V_370 , false ) ;
F_182 ( V_370 ) ;
V_373:
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_244 )
* V_18 = V_2 -> V_372 ;
V_18 -> V_371 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
V_290:
F_109 ( V_18 ) ;
return V_22 ;
}
static void V_218 ( struct V_56 * V_57 , bool V_305 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_181 ( V_2 ) ;
if ( V_305 )
F_62 ( V_2 , V_18 ) ;
else
F_64 ( V_2 , V_18 ) ;
V_18 -> V_146 = V_305 ;
}
static void V_220 ( struct V_56 * V_57 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_181 ( V_2 ) ;
if ( ! V_4 -> V_7 || ! V_18 -> V_371 )
return;
F_107 ( V_18 ) ;
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_169 , 0 ) ;
F_83 ( V_18 , V_104 , 0 ) ;
V_18 -> V_170 = 0 ;
V_18 -> V_166 = 0 ;
V_18 -> V_185 = 0 ;
F_8 ( V_2 , V_4 , false ) ;
F_182 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_244 )
* V_18 = V_2 -> V_372 ;
V_18 -> V_371 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
F_109 ( V_18 ) ;
}
static void V_214 ( struct V_56 * V_57 , bool V_374 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( ! ( V_2 -> V_47 & V_375 ) )
return;
if ( V_374 )
F_183 ( & V_2 -> V_24 -> V_9 ) ;
else
F_184 ( & V_2 -> V_24 -> V_9 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
F_90 ( & V_376 ) ;
F_186 ( & V_2 -> V_347 , & V_377 ) ;
F_91 ( & V_376 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_90 ( & V_376 ) ;
F_188 ( & V_2 -> V_347 ) ;
F_91 ( & V_376 ) ;
}
static int F_189 ( const char * V_58 , const struct V_378 * V_379 )
{
struct V_1 * V_2 ;
struct V_229 * V_202 ;
int V_380 = V_212 ;
int V_289 = F_190 ( V_58 , V_379 ) ;
if ( V_289 || V_380 == V_212 )
return V_289 ;
F_90 ( & V_376 ) ;
F_95 (chip, &card_list, list) {
if ( ! V_2 -> V_57 || V_2 -> V_91 )
continue;
F_95 (c, &chip->bus->codec_list, list)
F_191 ( V_202 ) ;
}
F_91 ( & V_376 ) ;
return 0 ;
}
static int F_192 ( struct V_236 * V_9 )
{
struct V_118 * V_24 = F_193 ( V_9 ) ;
struct V_381 * V_221 = F_194 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
struct V_194 * V_195 ;
if ( V_2 -> V_91 )
return 0 ;
F_195 ( V_221 , V_382 ) ;
F_162 ( V_2 ) ;
F_95 (p, &chip->pcm_list, list)
F_96 ( V_195 -> V_196 ) ;
if ( V_2 -> V_114 )
F_97 ( V_2 -> V_57 ) ;
F_93 ( V_2 ) ;
if ( V_2 -> V_77 >= 0 ) {
F_42 ( V_2 -> V_77 , V_2 ) ;
V_2 -> V_77 = - 1 ;
}
if ( V_2 -> V_76 )
F_43 ( V_2 -> V_24 ) ;
F_196 ( V_24 ) ;
F_197 ( V_24 ) ;
F_198 ( V_24 , V_383 ) ;
return 0 ;
}
static int F_199 ( struct V_236 * V_9 )
{
struct V_118 * V_24 = F_193 ( V_9 ) ;
struct V_381 * V_221 = F_194 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
if ( V_2 -> V_91 )
return 0 ;
F_198 ( V_24 , V_384 ) ;
F_200 ( V_24 ) ;
if ( F_201 ( V_24 ) < 0 ) {
F_156 ( V_82 L_42
L_41 ) ;
F_179 ( V_221 ) ;
return - V_59 ;
}
F_202 ( V_24 ) ;
if ( V_2 -> V_76 )
if ( F_203 ( V_24 ) < 0 )
V_2 -> V_76 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 )
return - V_59 ;
F_69 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
F_98 ( V_2 -> V_57 ) ;
F_195 ( V_221 , V_385 ) ;
return 0 ;
}
static int F_204 ( struct V_236 * V_9 )
{
struct V_381 * V_221 = F_194 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
F_93 ( V_2 ) ;
F_162 ( V_2 ) ;
return 0 ;
}
static int F_205 ( struct V_236 * V_9 )
{
struct V_381 * V_221 = F_194 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
F_69 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
return 0 ;
}
static int F_206 ( struct V_236 * V_9 )
{
struct V_381 * V_221 = F_194 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
if ( ! V_386 ||
! ( V_2 -> V_47 & V_375 ) )
return - V_97 ;
return 0 ;
}
static int F_207 ( struct V_387 * V_388 , unsigned long V_389 , void * V_17 )
{
struct V_1 * V_2 = F_112 ( V_388 , struct V_1 , V_390 ) ;
F_208 ( V_2 -> V_57 ) ;
F_93 ( V_2 ) ;
return V_391 ;
}
static void F_209 ( struct V_1 * V_2 )
{
V_2 -> V_390 . V_392 = F_207 ;
F_210 ( & V_2 -> V_390 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
if ( V_2 -> V_390 . V_392 )
F_212 ( & V_2 -> V_390 ) ;
}
static void F_213 ( struct V_118 * V_24 ,
enum V_393 V_394 )
{
struct V_381 * V_221 = F_214 ( V_24 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
bool V_91 ;
F_215 ( & V_2 -> V_395 ) ;
if ( V_2 -> V_396 )
return;
V_91 = ( V_394 == V_397 ) ;
if ( V_2 -> V_91 == V_91 )
return;
if ( ! V_2 -> V_57 ) {
V_2 -> V_91 = V_91 ;
if ( ! V_91 ) {
F_14 (KERN_INFO SFX
L_43 ,
pci_name(chip->pci)) ;
if ( F_216 ( V_2 ) < 0 ||
F_217 ( V_2 ) < 0 ) {
F_14 (KERN_ERR SFX
L_44 ,
pci_name(chip->pci)) ;
V_2 -> V_396 = true ;
}
}
} else {
F_14 (KERN_INFO SFX
L_45 , pci_name(chip->pci),
disabled ? L_46 : L_47 ) ;
if ( V_91 ) {
F_192 ( & V_24 -> V_9 ) ;
V_2 -> V_91 = true ;
if ( F_218 ( V_2 -> V_57 ) )
F_14 (KERN_WARNING SFX L_48 ,
pci_name(chip->pci)) ;
} else {
F_219 ( V_2 -> V_57 ) ;
V_2 -> V_91 = false ;
F_199 ( & V_24 -> V_9 ) ;
}
}
}
static bool F_220 ( struct V_118 * V_24 )
{
struct V_381 * V_221 = F_214 ( V_24 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
F_215 ( & V_2 -> V_395 ) ;
if ( V_2 -> V_396 )
return false ;
if ( V_2 -> V_91 || ! V_2 -> V_57 )
return true ;
if ( F_218 ( V_2 -> V_57 ) )
return false ;
F_219 ( V_2 -> V_57 ) ;
return true ;
}
static void F_221 ( struct V_1 * V_2 )
{
struct V_118 * V_195 = F_222 ( V_2 -> V_24 ) ;
if ( V_195 ) {
F_14 (KERN_INFO SFX
L_49 ,
pci_name(chip->pci)) ;
V_2 -> V_398 = 1 ;
F_223 ( V_195 ) ;
}
}
static int F_224 ( struct V_1 * V_2 )
{
int V_22 ;
if ( ! V_2 -> V_398 )
return 0 ;
V_22 = F_225 ( V_2 -> V_24 , & V_399 ,
V_400 ,
V_2 -> V_57 != NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_401 = 1 ;
return 0 ;
}
static int F_226 ( struct V_1 * V_2 )
{
int V_102 ;
F_187 ( V_2 ) ;
F_211 ( V_2 ) ;
V_2 -> V_396 = 1 ;
F_227 ( & V_2 -> V_395 ) ;
if ( V_398 ( V_2 ) ) {
if ( V_2 -> V_91 && V_2 -> V_57 )
F_219 ( V_2 -> V_57 ) ;
if ( V_2 -> V_401 )
F_228 ( V_2 -> V_24 ) ;
}
if ( V_2 -> V_114 ) {
F_162 ( V_2 ) ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ )
F_64 ( V_2 , & V_2 -> V_18 [ V_102 ] ) ;
F_93 ( V_2 ) ;
}
if ( V_2 -> V_77 >= 0 )
F_42 ( V_2 -> V_77 , ( void * ) V_2 ) ;
if ( V_2 -> V_76 )
F_43 ( V_2 -> V_24 ) ;
if ( V_2 -> V_328 )
F_229 ( V_2 -> V_328 ) ;
if ( V_2 -> V_18 ) {
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ )
if ( V_2 -> V_18 [ V_102 ] . V_158 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_18 [ V_102 ] . V_158 , false ) ;
F_182 ( & V_2 -> V_18 [ V_102 ] . V_158 ) ;
}
}
if ( V_2 -> V_25 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_25 , false ) ;
F_182 ( & V_2 -> V_25 ) ;
}
if ( V_2 -> V_116 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_116 , false ) ;
F_182 ( & V_2 -> V_116 ) ;
}
if ( V_2 -> V_402 )
F_230 ( V_2 -> V_24 ) ;
F_196 ( V_2 -> V_24 ) ;
F_168 ( V_2 -> V_18 ) ;
#ifdef F_231
if ( V_2 -> V_403 )
F_232 ( V_2 -> V_403 ) ;
#endif
F_168 ( V_2 ) ;
return 0 ;
}
static int F_233 ( struct V_404 * V_236 )
{
return F_226 ( V_236 -> V_405 ) ;
}
static struct V_118 * F_222 ( struct V_118 * V_24 )
{
struct V_118 * V_195 ;
switch ( V_24 -> V_406 ) {
case V_407 :
case V_408 :
case V_409 :
if ( V_24 -> V_410 == 1 ) {
V_195 = F_234 ( F_235 ( V_24 -> V_57 ) ,
V_24 -> V_57 -> V_237 , 0 ) ;
if ( V_195 ) {
if ( ( V_195 -> V_411 >> 8 ) == V_412 )
return V_195 ;
F_223 ( V_195 ) ;
}
}
break;
}
return NULL ;
}
static bool F_236 ( struct V_118 * V_24 )
{
bool V_413 = false ;
struct V_118 * V_195 = F_222 ( V_24 ) ;
if ( V_195 ) {
if ( F_237 ( V_195 ) == V_397 )
V_413 = true ;
F_223 ( V_195 ) ;
}
return V_413 ;
}
static int F_238 ( struct V_1 * V_2 , int V_414 )
{
const struct V_415 * V_416 ;
switch ( V_414 ) {
case V_334 :
case V_188 :
case V_336 :
case V_333 :
case V_417 :
return V_414 ;
}
V_416 = F_239 ( V_2 -> V_24 , V_418 ) ;
if ( V_416 ) {
F_156 ( V_419
L_50
L_51 ,
V_416 -> V_420 , V_416 -> V_421 , V_416 -> V_422 ) ;
return V_416 -> V_420 ;
}
if ( V_2 -> V_47 & V_423 ) {
F_48 ( V_74 L_52 , F_41 ( V_2 -> V_24 ) ) ;
return V_333 ;
}
if ( V_2 -> V_47 & V_424 ) {
F_48 ( V_74 L_53 , F_41 ( V_2 -> V_24 ) ) ;
return V_188 ;
}
return V_334 ;
}
static void F_240 ( struct V_1 * V_2 , int V_9 )
{
const struct V_415 * V_416 ;
V_2 -> V_226 = V_425 [ V_9 ] ;
if ( V_2 -> V_226 == - 1 ) {
V_416 = F_239 ( V_2 -> V_24 , V_426 ) ;
if ( V_416 ) {
F_156 ( V_419
L_54
L_51 ,
V_416 -> V_420 , V_416 -> V_421 , V_416 -> V_422 ) ;
V_2 -> V_226 = V_416 -> V_420 ;
}
}
if ( V_2 -> V_226 != - 1 &&
( V_2 -> V_226 & V_427 ) ) {
V_2 -> V_98 = V_2 -> V_226 & 0xff ;
F_156 ( V_419 L_55 ,
V_2 -> V_98 ) ;
}
}
static void F_241 ( struct V_1 * V_2 )
{
const struct V_415 * V_416 ;
if ( V_428 >= 0 ) {
V_2 -> V_76 = ! ! V_428 ;
return;
}
V_2 -> V_76 = 1 ;
V_416 = F_239 ( V_2 -> V_24 , V_429 ) ;
if ( V_416 ) {
F_156 ( V_419
L_56 ,
V_416 -> V_421 , V_416 -> V_422 , V_416 -> V_420 ) ;
V_2 -> V_76 = V_416 -> V_420 ;
return;
}
if ( V_2 -> V_47 & V_430 ) {
F_156 ( V_419 L_57 ) ;
V_2 -> V_76 = 0 ;
}
}
static void F_242 ( struct V_1 * V_2 )
{
bool V_134 = V_2 -> V_134 ;
switch ( V_2 -> V_224 ) {
case V_431 :
if ( V_134 ) {
T_2 V_58 ;
F_67 ( V_2 -> V_24 , 0x42 , & V_58 ) ;
if ( ! ( V_58 & 0x80 ) && V_2 -> V_24 -> V_432 == 0x30 )
V_134 = false ;
}
break;
case V_433 :
V_134 = false ;
break;
case V_434 :
V_134 = false ;
break;
}
if ( V_134 != V_2 -> V_134 ) {
F_14 (KERN_INFO SFX L_58 ,
pci_name(chip->pci), snoop ? L_59 : L_60 ) ;
V_2 -> V_134 = V_134 ;
}
}
static int F_243 ( struct V_381 * V_221 , struct V_118 * V_24 ,
int V_9 , unsigned int V_47 ,
struct V_1 * * V_435 )
{
static struct V_436 V_206 = {
. V_437 = F_233 ,
} ;
struct V_1 * V_2 ;
int V_22 ;
* V_435 = NULL ;
V_22 = F_201 ( V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 = F_171 ( sizeof( * V_2 ) , V_353 ) ;
if ( ! V_2 ) {
F_14 (KERN_ERR SFX L_61 , pci_name(pci)) ;
F_196 ( V_24 ) ;
return - V_354 ;
}
F_244 ( & V_2 -> V_26 ) ;
F_245 ( & V_2 -> V_271 ) ;
V_2 -> V_221 = V_221 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_77 = - 1 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_224 = V_47 & 0xff ;
F_241 ( V_2 ) ;
V_2 -> V_172 = V_9 ;
F_246 ( & V_2 -> V_150 , F_161 ) ;
F_247 ( & V_2 -> V_360 ) ;
F_247 ( & V_2 -> V_347 ) ;
F_221 ( V_2 ) ;
F_248 ( & V_2 -> V_395 ) ;
V_2 -> V_187 [ 0 ] = V_2 -> V_187 [ 1 ] =
F_238 ( V_2 , V_187 [ V_9 ] ) ;
if ( V_2 -> V_187 [ 0 ] == V_417 ) {
V_2 -> V_187 [ 0 ] = V_188 ;
V_2 -> V_187 [ 1 ] = V_334 ;
}
F_240 ( V_2 , V_9 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_134 = V_438 ;
F_242 ( V_2 ) ;
if ( V_171 [ V_9 ] < 0 ) {
switch ( V_2 -> V_224 ) {
case V_439 :
case V_440 :
V_171 [ V_9 ] = 1 ;
break;
default:
V_171 [ V_9 ] = 32 ;
break;
}
}
V_22 = F_249 ( V_221 , V_441 , V_2 , & V_206 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_62 ,
pci_name(chip->pci)) ;
F_226 ( V_2 ) ;
return V_22 ;
}
* V_435 = V_2 ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_172 ;
struct V_118 * V_24 = V_2 -> V_24 ;
struct V_381 * V_221 = V_2 -> V_221 ;
int V_102 , V_22 ;
unsigned short V_442 ;
#if V_443 != 64
if ( V_2 -> V_224 == V_444 ) {
T_7 V_445 ;
F_70 ( V_24 , 0x40 , & V_445 ) ;
F_71 ( V_24 , 0x40 , V_445 | 0x10 ) ;
F_250 ( V_24 , V_446 , 0 ) ;
}
#endif
V_22 = F_251 ( V_24 , L_63 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_402 = 1 ;
V_2 -> V_28 = F_252 ( V_24 , 0 ) ;
V_2 -> V_328 = F_253 ( V_24 , 0 ) ;
if ( V_2 -> V_328 == NULL ) {
F_14 (KERN_ERR SFX L_64 , pci_name(chip->pci)) ;
return - V_233 ;
}
if ( V_2 -> V_76 )
if ( F_203 ( V_24 ) < 0 )
V_2 -> V_76 = 0 ;
if ( F_44 ( V_2 , 0 ) < 0 )
return - V_97 ;
F_202 ( V_24 ) ;
F_254 ( V_2 -> V_77 ) ;
V_442 = F_27 ( V_2 , V_447 ) ;
F_40 ( V_74 L_65 , F_41 ( V_2 -> V_24 ) , V_442 ) ;
if ( V_2 -> V_24 -> V_406 == V_407 ) {
struct V_118 * V_448 ;
V_448 = F_255 ( V_407 ,
V_449 ,
NULL ) ;
if ( V_448 ) {
if ( V_448 -> V_432 < 0x30 )
V_442 &= ~ V_450 ;
F_223 ( V_448 ) ;
}
}
if ( V_2 -> V_47 & V_451 ) {
F_48 ( V_74 L_66 , F_41 ( V_2 -> V_24 ) ) ;
V_442 &= ~ V_450 ;
}
if ( V_280 >= 0 )
V_2 -> V_280 = ! ! V_280 ;
else {
if ( V_2 -> V_47 & V_452 )
V_2 -> V_280 = 0 ;
else if ( V_2 -> V_47 & V_453 )
V_2 -> V_280 = 1 ;
else
V_2 -> V_280 = 1 ;
}
if ( ( V_442 & V_450 ) && ! F_256 ( V_24 , F_257 ( 64 ) ) )
F_258 ( V_24 , F_257 ( 64 ) ) ;
else {
F_256 ( V_24 , F_257 ( 32 ) ) ;
F_258 ( V_24 , F_257 ( 32 ) ) ;
}
V_2 -> V_243 = ( V_442 >> 8 ) & 0x0f ;
V_2 -> V_241 = ( V_442 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_241 && ! V_2 -> V_243 ) {
switch ( V_2 -> V_224 ) {
case V_444 :
V_2 -> V_241 = V_454 ;
V_2 -> V_243 = V_455 ;
break;
case V_456 :
case V_433 :
V_2 -> V_241 = V_457 ;
V_2 -> V_243 = V_458 ;
break;
case V_459 :
default:
V_2 -> V_241 = V_460 ;
V_2 -> V_243 = V_461 ;
break;
}
}
V_2 -> V_242 = 0 ;
V_2 -> V_240 = V_2 -> V_243 ;
V_2 -> V_103 = V_2 -> V_241 + V_2 -> V_243 ;
V_2 -> V_18 = F_259 ( V_2 -> V_103 , sizeof( * V_2 -> V_18 ) ,
V_353 ) ;
if ( ! V_2 -> V_18 ) {
F_14 (KERN_ERR SFX L_67 , pci_name(chip->pci)) ;
return - V_354 ;
}
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
F_260 ( & V_2 -> V_18 [ V_102 ] ) ;
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_462 , & V_2 -> V_18 [ V_102 ] . V_158 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_68 , pci_name(chip->pci)) ;
return - V_354 ;
}
F_8 ( V_2 , & V_2 -> V_18 [ V_102 ] . V_158 , true ) ;
}
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_2 -> V_103 * 8 , & V_2 -> V_116 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_69 , pci_name(chip->pci)) ;
return - V_354 ;
}
F_8 ( V_2 , & V_2 -> V_116 , true ) ;
V_22 = F_11 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
F_177 ( V_2 ) ;
F_69 ( V_2 ) ;
F_65 ( V_2 , ( V_463 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_98 ) {
F_14 (KERN_ERR SFX L_70 , pci_name(chip->pci)) ;
return - V_464 ;
}
strcpy ( V_221 -> V_465 , L_71 ) ;
F_170 ( V_221 -> V_466 , V_467 [ V_2 -> V_224 ] ,
sizeof( V_221 -> V_466 ) ) ;
snprintf ( V_221 -> V_468 , sizeof( V_221 -> V_468 ) ,
L_72 ,
V_221 -> V_466 , V_2 -> V_28 , V_2 -> V_77 ) ;
return 0 ;
}
static void F_261 ( struct V_1 * V_2 )
{
#ifdef F_94
struct V_229 * V_230 ;
F_95 (codec, &chip->bus->codec_list, list) {
F_129 ( V_230 ) ;
}
#endif
}
static void F_262 ( const struct V_469 * V_403 , void * V_470 )
{
struct V_381 * V_221 = V_470 ;
struct V_1 * V_2 = V_221 -> V_13 ;
struct V_118 * V_24 = V_2 -> V_24 ;
if ( ! V_403 ) {
F_14 (KERN_ERR SFX L_73 ,
pci_name(chip->pci)) ;
goto error;
}
V_2 -> V_403 = V_403 ;
if ( ! V_2 -> V_91 ) {
if ( F_217 ( V_2 ) )
goto error;
}
return;
error:
F_263 ( V_221 ) ;
F_264 ( V_24 , NULL ) ;
}
static int F_265 ( struct V_118 * V_24 ,
const struct V_471 * V_472 )
{
static int V_9 ;
struct V_381 * V_221 ;
struct V_1 * V_2 ;
bool V_473 ;
int V_22 ;
if ( V_9 >= V_474 )
return - V_464 ;
if ( ! V_475 [ V_9 ] ) {
V_9 ++ ;
return - V_476 ;
}
V_22 = F_266 ( V_112 [ V_9 ] , V_477 [ V_9 ] , V_478 , 0 , & V_221 ) ;
if ( V_22 < 0 ) {
F_14 ( V_82 L_74 ) ;
return V_22 ;
}
F_267 ( V_221 , & V_24 -> V_9 ) ;
V_22 = F_243 ( V_221 , V_24 , V_9 , V_472 -> V_479 , & V_2 ) ;
if ( V_22 < 0 )
goto V_480;
V_221 -> V_13 = V_2 ;
F_264 ( V_24 , V_221 ) ;
V_22 = F_224 ( V_2 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX
L_75 , pci_name(pci)) ;
goto V_480;
}
if ( F_236 ( V_24 ) ) {
F_14 (KERN_INFO SFX L_76 ,
pci_name(pci)) ;
F_14 (KERN_INFO SFX L_77 , pci_name(pci)) ;
V_2 -> V_91 = true ;
}
V_473 = ! V_2 -> V_91 ;
if ( V_473 ) {
V_22 = F_216 ( V_2 ) ;
if ( V_22 < 0 )
goto V_480;
}
#ifdef F_231
if ( V_481 [ V_9 ] && * V_481 [ V_9 ] ) {
F_14 (KERN_ERR SFX L_78 ,
pci_name(pci), patch[dev]) ;
V_22 = F_268 ( V_478 , true , V_481 [ V_9 ] ,
& V_24 -> V_9 , V_353 , V_221 ,
F_262 ) ;
if ( V_22 < 0 )
goto V_480;
V_473 = false ;
}
#endif
if ( V_473 ) {
V_22 = F_217 ( V_2 ) ;
if ( V_22 < 0 )
goto V_480;
}
if ( F_269 ( V_24 ) )
F_270 ( & V_24 -> V_9 ) ;
V_9 ++ ;
F_227 ( & V_2 -> V_395 ) ;
return 0 ;
V_480:
F_263 ( V_221 ) ;
F_264 ( V_24 , NULL ) ;
return V_22 ;
}
static int F_217 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_172 ;
int V_22 ;
#ifdef F_271
V_2 -> V_232 = V_232 [ V_9 ] ;
#endif
V_22 = F_100 ( V_2 , V_199 [ V_9 ] ) ;
if ( V_22 < 0 )
goto V_480;
#ifdef F_231
if ( V_2 -> V_403 ) {
V_22 = F_272 ( V_2 -> V_57 , V_2 -> V_403 -> V_156 ,
V_2 -> V_403 -> V_121 ) ;
if ( V_22 < 0 )
goto V_480;
#ifndef F_94
F_232 ( V_2 -> V_403 ) ;
V_2 -> V_403 = NULL ;
#endif
}
#endif
if ( ( V_463 [ V_9 ] & 1 ) == 0 ) {
V_22 = F_104 ( V_2 ) ;
if ( V_22 < 0 )
goto V_480;
}
V_22 = F_273 ( V_2 -> V_57 ) ;
if ( V_22 < 0 )
goto V_480;
V_22 = F_175 ( V_2 ) ;
if ( V_22 < 0 )
goto V_480;
V_22 = F_274 ( V_2 -> V_221 ) ;
if ( V_22 < 0 )
goto V_480;
V_2 -> V_146 = 1 ;
F_261 ( V_2 ) ;
F_209 ( V_2 ) ;
F_185 ( V_2 ) ;
return 0 ;
V_480:
V_2 -> V_396 = 1 ;
return V_22 ;
}
static void F_275 ( struct V_118 * V_24 )
{
struct V_381 * V_221 = F_214 ( V_24 ) ;
if ( F_269 ( V_24 ) )
F_276 ( & V_24 -> V_9 ) ;
if ( V_221 )
F_263 ( V_221 ) ;
F_264 ( V_24 , NULL ) ;
}
