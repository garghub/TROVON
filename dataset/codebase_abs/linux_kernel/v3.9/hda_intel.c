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
static int F_118 ( struct V_19 * V_20 ,
struct V_261 * V_262 )
{
struct V_18 * V_18 = F_115 ( V_20 ) ;
T_5 V_256 ;
V_256 = F_119 ( & V_18 -> V_255 ) ;
V_256 = F_120 ( V_256 , 3 ) ;
* V_262 = F_121 ( V_256 ) ;
return 0 ;
}
static int F_122 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_263 * V_264 = V_249 -> V_264 [ V_20 -> V_238 ] ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 ;
struct V_174 * V_175 = V_20 -> V_175 ;
unsigned long V_265 ;
int V_22 ;
int V_266 ;
F_90 ( & V_2 -> V_267 ) ;
V_18 = F_106 ( V_2 , V_20 ) ;
if ( V_18 == NULL ) {
F_91 ( & V_2 -> V_267 ) ;
return - V_97 ;
}
V_175 -> V_268 = V_269 ;
V_175 -> V_268 . V_270 = V_264 -> V_270 ;
V_175 -> V_268 . V_271 = V_264 -> V_271 ;
V_175 -> V_268 . V_272 = V_264 -> V_272 ;
V_175 -> V_268 . V_273 = V_264 -> V_273 ;
F_123 ( V_175 ) ;
F_124 ( V_175 , V_274 ) ;
F_125 ( V_175 , V_275 ,
20 ,
178000000 ) ;
if ( V_2 -> V_276 )
V_266 = 128 ;
else
V_266 = 4 ;
F_126 ( V_175 , 0 , V_277 ,
V_266 ) ;
F_126 ( V_175 , 0 , V_278 ,
V_266 ) ;
F_127 ( V_249 -> V_230 ) ;
V_22 = V_264 -> V_206 . V_279 ( V_264 , V_249 -> V_230 , V_20 ) ;
if ( V_22 < 0 ) {
F_110 ( V_18 ) ;
F_128 ( V_249 -> V_230 ) ;
F_91 ( & V_2 -> V_267 ) ;
return V_22 ;
}
F_123 ( V_175 ) ;
if ( F_129 ( ! V_175 -> V_268 . V_270 ) ||
F_129 ( ! V_175 -> V_268 . V_271 ) ||
F_129 ( ! V_175 -> V_268 . V_272 ) ||
F_129 ( ! V_175 -> V_268 . V_273 ) ) {
F_110 ( V_18 ) ;
V_264 -> V_206 . V_280 ( V_264 , V_249 -> V_230 , V_20 ) ;
F_128 ( V_249 -> V_230 ) ;
F_91 ( & V_2 -> V_267 ) ;
return - V_162 ;
}
if ( V_20 -> V_238 == V_281 )
V_175 -> V_268 . V_282 &= ~ V_283 ;
F_130 ( & V_2 -> V_26 , V_265 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_146 = 0 ;
F_131 ( & V_2 -> V_26 , V_265 ) ;
V_175 -> V_13 = V_18 ;
F_132 ( V_20 ) ;
F_91 ( & V_2 -> V_267 ) ;
return 0 ;
}
static int F_133 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_263 * V_264 = V_249 -> V_264 [ V_20 -> V_238 ] ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
unsigned long V_265 ;
F_90 ( & V_2 -> V_267 ) ;
F_130 ( & V_2 -> V_26 , V_265 ) ;
V_18 -> V_20 = NULL ;
V_18 -> V_146 = 0 ;
F_131 ( & V_2 -> V_26 , V_265 ) ;
F_110 ( V_18 ) ;
V_264 -> V_206 . V_280 ( V_264 , V_249 -> V_230 , V_20 ) ;
F_128 ( V_249 -> V_230 ) ;
F_91 ( & V_2 -> V_267 ) ;
return 0 ;
}
static int F_134 ( struct V_19 * V_20 ,
struct V_284 * V_285 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
int V_286 ;
F_107 ( V_18 ) ;
if ( F_108 ( V_18 ) ) {
V_286 = - V_97 ;
goto V_287;
}
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_170 = 0 ;
V_18 -> V_166 = 0 ;
V_18 -> V_185 = 0 ;
V_286 = F_135 ( V_20 ,
F_136 ( V_285 ) ) ;
if ( V_286 < 0 )
goto V_287;
F_9 ( V_2 , V_18 , V_20 , true ) ;
V_287:
F_109 ( V_18 ) ;
return V_286 ;
}
static int F_137 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_263 * V_264 = V_249 -> V_264 [ V_20 -> V_238 ] ;
F_107 ( V_18 ) ;
if ( ! F_108 ( V_18 ) ) {
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_169 , 0 ) ;
F_83 ( V_18 , V_104 , 0 ) ;
V_18 -> V_170 = 0 ;
V_18 -> V_166 = 0 ;
V_18 -> V_185 = 0 ;
}
F_138 ( V_249 -> V_230 , V_264 , V_20 ) ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_288 = 0 ;
F_109 ( V_18 ) ;
return F_139 ( V_20 ) ;
}
static int F_140 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
struct V_263 * V_264 = V_249 -> V_264 [ V_20 -> V_238 ] ;
struct V_174 * V_175 = V_20 -> V_175 ;
unsigned int V_170 , V_166 , V_185 , V_180 ;
int V_22 ;
struct V_289 * V_290 =
F_141 ( V_249 -> V_230 , V_264 -> V_291 ) ;
unsigned short V_292 = V_290 ? V_290 -> V_292 : 0 ;
F_107 ( V_18 ) ;
if ( F_108 ( V_18 ) ) {
V_22 = - V_97 ;
goto V_287;
}
F_85 ( V_2 , V_18 ) ;
V_185 = F_142 ( V_175 -> V_177 ,
V_175 -> V_293 ,
V_175 -> V_294 ,
V_264 -> V_295 ,
V_292 ) ;
if ( ! V_185 ) {
F_14 (KERN_ERR SFX
L_30 ,
pci_name(chip->pci), runtime->rate, runtime->channels, runtime->format) ;
V_22 = - V_162 ;
goto V_287;
}
V_170 = F_143 ( V_20 ) ;
V_166 = F_144 ( V_20 ) ;
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
goto V_287;
}
V_18 -> V_296 = ( ( ( V_175 -> V_297 * 24000 ) /
V_175 -> V_177 ) * 1000 ) ;
F_86 ( V_2 , V_18 ) ;
if ( V_20 -> V_238 == V_239 )
V_18 -> V_298 = F_145 ( V_18 , V_299 ) + 1 ;
else
V_18 -> V_298 = 0 ;
V_180 = V_18 -> V_180 ;
if ( ( V_2 -> V_47 & V_48 ) &&
V_180 > V_2 -> V_243 )
V_180 -= V_2 -> V_243 ;
V_22 = F_146 ( V_249 -> V_230 , V_264 , V_180 ,
V_18 -> V_185 , V_20 ) ;
V_287:
if ( ! V_22 )
V_18 -> V_288 = 1 ;
F_109 ( V_18 ) ;
return V_22 ;
}
static int F_147 ( struct V_19 * V_20 , int V_53 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 ;
struct V_19 * V_300 ;
int V_301 = 0 , V_302 , V_303 = 0 , V_304 = 0 ;
int V_305 , V_65 ;
V_18 = F_115 ( V_20 ) ;
F_148 ( V_2 , V_18 , V_53 ) ;
if ( F_108 ( V_18 ) || ! V_18 -> V_288 )
return - V_306 ;
switch ( V_53 ) {
case V_307 :
V_301 = 1 ;
case V_308 :
case V_309 :
V_302 = 1 ;
break;
case V_310 :
case V_311 :
case V_312 :
V_302 = 0 ;
break;
default:
return - V_162 ;
}
F_149 (s, substream) {
if ( V_300 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_300 ) ;
V_304 |= 1 << V_18 -> V_112 ;
V_303 ++ ;
F_150 ( V_300 , V_20 ) ;
}
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_313 )
F_17 ( V_2 , V_314 ,
F_45 ( V_2 , V_314 ) | V_304 ) ;
else
F_17 ( V_2 , V_315 , F_45 ( V_2 , V_315 ) | V_304 ) ;
F_149 (s, substream) {
if ( V_300 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_300 ) ;
if ( V_302 ) {
V_18 -> V_316 = F_45 ( V_2 , V_250 ) ;
if ( ! V_301 )
V_18 -> V_316 -=
V_18 -> V_296 ;
F_62 ( V_2 , V_18 ) ;
} else {
F_64 ( V_2 , V_18 ) ;
}
V_18 -> V_146 = V_302 ;
}
F_75 ( & V_2 -> V_26 ) ;
if ( V_302 ) {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_305 = 0 ;
F_149 (s, substream) {
if ( V_300 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_300 ) ;
if ( ! ( F_60 ( V_18 , V_106 ) &
V_317 ) )
V_305 ++ ;
}
if ( ! V_305 )
break;
F_151 () ;
}
} else {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_305 = 0 ;
F_149 (s, substream) {
if ( V_300 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
V_18 = F_115 ( V_300 ) ;
if ( F_60 ( V_18 , V_104 ) &
V_113 )
V_305 ++ ;
}
if ( ! V_305 )
break;
F_151 () ;
}
}
F_74 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_313 )
F_17 ( V_2 , V_314 ,
F_45 ( V_2 , V_314 ) & ~ V_304 ) ;
else
F_17 ( V_2 , V_315 , F_45 ( V_2 , V_315 ) & ~ V_304 ) ;
if ( V_302 ) {
F_114 ( V_20 , 0 , 0 ) ;
if ( V_303 > 1 ) {
T_4 V_260 ;
V_18 = F_115 ( V_20 ) ;
V_260 = V_18 -> V_255 . V_260 ;
F_149 (s, substream) {
if ( V_300 -> V_196 -> V_221 != V_20 -> V_196 -> V_221 )
continue;
F_114 ( V_300 , 1 , V_260 ) ;
}
}
}
F_75 ( & V_2 -> V_26 ) ;
return 0 ;
}
static unsigned int F_152 ( struct V_1 * V_2 ,
struct V_18 * V_18 )
{
unsigned int V_318 , V_319 , V_320 ;
unsigned int V_321 , V_322 , V_323 ;
unsigned int V_298 ;
V_318 = F_87 ( V_18 , V_324 ) ;
if ( V_18 -> V_20 -> V_238 == V_239 ) {
return V_318 ;
}
V_322 = F_30 ( * V_18 -> V_116 ) ;
V_322 %= V_18 -> V_166 ;
V_298 = F_153 ( V_2 -> V_325 + V_326 ) ;
if ( V_18 -> V_111 ) {
if ( V_318 <= V_298 )
return 0 ;
V_18 -> V_111 = 0 ;
}
if ( V_318 <= V_298 )
V_319 = V_18 -> V_170 + V_318 - V_298 ;
else
V_319 = V_318 - V_298 ;
V_323 = V_319 % V_18 -> V_166 ;
V_321 = V_318 % V_18 -> V_166 ;
if ( V_321 >= V_298 )
V_320 = V_318 - V_321 ;
else if ( V_322 >= V_323 )
V_320 = V_319 - V_323 ;
else {
V_320 = V_319 - V_323 + V_18 -> V_166 ;
if ( V_320 >= V_18 -> V_170 )
V_320 = 0 ;
}
return V_320 + V_322 ;
}
static unsigned int F_154 ( struct V_1 * V_2 ,
struct V_18 * V_18 ,
bool V_327 )
{
unsigned int V_328 ;
int V_238 = V_18 -> V_20 -> V_238 ;
int V_329 = 0 ;
switch ( V_2 -> V_187 [ V_238 ] ) {
case V_188 :
V_328 = F_87 ( V_18 , V_324 ) ;
break;
case V_330 :
V_328 = F_152 ( V_2 , V_18 ) ;
break;
default:
V_328 = F_30 ( * V_18 -> V_116 ) ;
if ( V_327 && V_2 -> V_187 [ V_238 ] == V_331 ) {
if ( ! V_328 || V_328 == ( V_29 ) - 1 ) {
F_155 ( V_332
L_32
L_33 ) ;
V_2 -> V_187 [ V_238 ] = V_188 ;
V_328 = F_87 ( V_18 , V_324 ) ;
} else
V_2 -> V_187 [ V_238 ] = V_333 ;
}
break;
}
if ( V_328 >= V_18 -> V_170 )
V_328 = 0 ;
if ( V_18 -> V_20 -> V_175 &&
V_2 -> V_187 [ V_238 ] == V_333 &&
( V_2 -> V_47 & V_334 ) ) {
unsigned int V_335 = F_87 ( V_18 , V_324 ) ;
if ( V_238 == V_239 )
V_329 = V_328 - V_335 ;
else
V_329 = V_335 - V_328 ;
if ( V_329 < 0 )
V_329 += V_18 -> V_170 ;
if ( V_329 >= V_18 -> V_166 ) {
F_14 (KERN_WARNING SFX
L_34
L_35 ,
pci_name(chip->pci), delay, azx_dev->period_bytes) ;
V_329 = 0 ;
V_2 -> V_47 &= ~ V_334 ;
}
V_18 -> V_20 -> V_175 -> V_329 =
F_156 ( V_18 -> V_20 -> V_175 , V_329 ) ;
}
F_157 ( V_2 , V_18 , V_328 , V_329 ) ;
return V_328 ;
}
static T_6 F_158 ( struct V_19 * V_20 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_18 * V_18 = F_115 ( V_20 ) ;
return F_156 ( V_20 -> V_175 ,
F_154 ( V_2 , V_18 , false ) ) ;
}
static int F_76 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_29 V_336 ;
unsigned int V_328 ;
V_336 = F_45 ( V_2 , V_250 ) - V_18 -> V_316 ;
if ( V_336 < ( V_18 -> V_296 * 2 ) / 3 )
return - 1 ;
V_328 = F_154 ( V_2 , V_18 , true ) ;
if ( F_159 ( ! V_18 -> V_166 ,
L_36 ) )
return - 1 ;
if ( V_336 < ( V_18 -> V_296 * 5 ) / 4 &&
V_328 % V_18 -> V_166 > V_18 -> V_166 / 2 )
return V_171 [ V_2 -> V_172 ] ? 0 : - 1 ;
V_18 -> V_316 += V_336 ;
return 1 ;
}
static void F_160 ( struct V_337 * V_338 )
{
struct V_1 * V_2 = F_112 ( V_338 , struct V_1 , V_150 ) ;
int V_102 , V_339 , V_140 ;
if ( ! V_2 -> V_340 ) {
F_155 ( V_332
L_37
L_38 ,
V_2 -> V_221 -> V_237 ) ;
V_2 -> V_340 = 1 ;
}
for (; ; ) {
V_339 = 0 ;
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
V_339 = 0 ;
} else
V_339 ++ ;
}
F_21 ( & V_2 -> V_26 ) ;
if ( ! V_339 )
return;
F_37 ( 1 ) ;
}
}
static void F_161 ( struct V_1 * V_2 )
{
int V_102 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ )
V_2 -> V_18 [ V_102 ] . V_148 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
}
static int F_162 ( struct V_19 * V_20 ,
struct V_341 * V_7 )
{
struct V_194 * V_249 = F_113 ( V_20 ) ;
struct V_1 * V_2 = V_249 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_7 -> V_342 = F_163 ( V_7 -> V_342 ) ;
return F_164 ( V_20 , V_7 ) ;
}
static void F_165 ( struct V_343 * V_196 )
{
struct V_194 * V_249 = V_196 -> V_13 ;
if ( V_249 ) {
F_166 ( & V_249 -> V_344 ) ;
F_167 ( V_249 ) ;
}
}
static int
V_210 ( struct V_56 * V_57 , struct V_229 * V_230 ,
struct V_345 * V_346 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_343 * V_196 ;
struct V_194 * V_249 ;
int V_347 = V_346 -> V_236 ;
unsigned int V_156 ;
int V_300 , V_22 ;
F_95 (apcm, &chip->pcm_list, list) {
if ( V_249 -> V_196 -> V_236 == V_347 ) {
F_14 (KERN_ERR SFX L_39 ,
pci_name(chip->pci), pcm_dev) ;
return - V_97 ;
}
}
V_22 = F_168 ( V_2 -> V_221 , V_346 -> V_348 , V_347 ,
V_346 -> V_238 [ V_239 ] . V_349 ,
V_346 -> V_238 [ V_281 ] . V_349 ,
& V_196 ) ;
if ( V_22 < 0 )
return V_22 ;
F_169 ( V_196 -> V_348 , V_346 -> V_348 , sizeof( V_196 -> V_348 ) ) ;
V_249 = F_170 ( sizeof( * V_249 ) , V_350 ) ;
if ( V_249 == NULL )
return - V_351 ;
V_249 -> V_2 = V_2 ;
V_249 -> V_196 = V_196 ;
V_249 -> V_230 = V_230 ;
V_196 -> V_13 = V_249 ;
V_196 -> V_352 = F_165 ;
if ( V_346 -> V_353 == V_354 )
V_196 -> V_355 = V_356 ;
F_171 ( & V_249 -> V_344 , & V_2 -> V_357 ) ;
V_346 -> V_196 = V_196 ;
for ( V_300 = 0 ; V_300 < 2 ; V_300 ++ ) {
V_249 -> V_264 [ V_300 ] = & V_346 -> V_238 [ V_300 ] ;
if ( V_346 -> V_238 [ V_300 ] . V_349 )
F_172 ( V_196 , V_300 , & V_358 ) ;
}
V_156 = V_359 * 1024 ;
if ( V_156 > V_360 )
V_156 = V_360 ;
F_173 ( V_196 , V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_156 , V_360 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
return F_175 ( V_2 -> V_57 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_102 ] ;
V_18 -> V_116 = ( V_29 V_361 * ) ( V_2 -> V_116 . V_7 + V_102 * 8 ) ;
V_18 -> V_362 = V_2 -> V_325 + ( 0x20 * V_102 + 0x80 ) ;
V_18 -> V_145 = 1 << V_102 ;
V_18 -> V_112 = V_102 ;
V_18 -> V_180 = V_102 + 1 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_363 )
{
if ( F_177 ( V_2 -> V_24 -> V_77 , F_72 ,
V_2 -> V_76 ? 0 : V_364 ,
V_365 , V_2 ) ) {
F_155 ( V_82 L_40
L_41 , V_2 -> V_24 -> V_77 ) ;
if ( V_363 )
F_178 ( V_2 -> V_221 ) ;
return - 1 ;
}
V_2 -> V_77 = V_2 -> V_24 -> V_77 ;
F_179 ( V_2 -> V_24 , ! V_2 -> V_76 ) ;
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
F_180 ( struct V_1 * V_2 )
{
return & V_2 -> V_18 [ V_2 -> V_240 ] ;
}
static int V_216 ( struct V_56 * V_57 , unsigned int V_294 ,
unsigned int V_366 ,
struct V_3 * V_367 )
{
V_29 * V_158 ;
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 ;
int V_22 ;
V_18 = F_180 ( V_2 ) ;
F_107 ( V_18 ) ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_146 || V_18 -> V_368 ) {
F_21 ( & V_2 -> V_26 ) ;
V_22 = - V_97 ;
goto V_287;
}
V_18 -> V_288 = 0 ;
V_2 -> V_369 = * V_18 ;
V_18 -> V_368 = 1 ;
F_21 ( & V_2 -> V_26 ) ;
V_22 = F_12 ( V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_366 , V_367 ) ;
if ( V_22 < 0 )
goto V_370;
F_8 ( V_2 , V_367 , true ) ;
V_18 -> V_170 = V_366 ;
V_18 -> V_166 = V_366 ;
V_18 -> V_185 = V_294 ;
F_85 ( V_2 , V_18 ) ;
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_169 , 0 ) ;
V_18 -> V_160 = 0 ;
V_158 = ( V_29 * ) V_18 -> V_158 . V_7 ;
V_22 = F_79 ( V_2 , V_367 , V_18 , & V_158 , 0 , V_366 , 0 ) ;
if ( V_22 < 0 )
goto error;
F_86 ( V_2 , V_18 ) ;
F_109 ( V_18 ) ;
return V_18 -> V_180 ;
error:
F_8 ( V_2 , V_367 , false ) ;
F_181 ( V_367 ) ;
V_370:
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_244 )
* V_18 = V_2 -> V_369 ;
V_18 -> V_368 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
V_287:
F_109 ( V_18 ) ;
return V_22 ;
}
static void V_218 ( struct V_56 * V_57 , bool V_302 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_180 ( V_2 ) ;
if ( V_302 )
F_62 ( V_2 , V_18 ) ;
else
F_64 ( V_2 , V_18 ) ;
V_18 -> V_146 = V_302 ;
}
static void V_220 ( struct V_56 * V_57 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_180 ( V_2 ) ;
if ( ! V_4 -> V_7 || ! V_18 -> V_368 )
return;
F_107 ( V_18 ) ;
F_83 ( V_18 , V_168 , 0 ) ;
F_83 ( V_18 , V_169 , 0 ) ;
F_83 ( V_18 , V_104 , 0 ) ;
V_18 -> V_170 = 0 ;
V_18 -> V_166 = 0 ;
V_18 -> V_185 = 0 ;
F_8 ( V_2 , V_4 , false ) ;
F_181 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_244 )
* V_18 = V_2 -> V_369 ;
V_18 -> V_368 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
F_109 ( V_18 ) ;
}
static void V_214 ( struct V_56 * V_57 , bool V_371 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( ! ( V_2 -> V_47 & V_372 ) )
return;
if ( V_371 )
F_182 ( & V_2 -> V_24 -> V_9 ) ;
else
F_183 ( & V_2 -> V_24 -> V_9 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_90 ( & V_373 ) ;
F_185 ( & V_2 -> V_344 , & V_374 ) ;
F_91 ( & V_373 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_90 ( & V_373 ) ;
F_187 ( & V_2 -> V_344 ) ;
F_91 ( & V_373 ) ;
}
static int F_188 ( const char * V_58 , const struct V_375 * V_376 )
{
struct V_1 * V_2 ;
struct V_229 * V_202 ;
int V_377 = V_212 ;
int V_286 = F_189 ( V_58 , V_376 ) ;
if ( V_286 || V_377 == V_212 )
return V_286 ;
F_90 ( & V_373 ) ;
F_95 (chip, &card_list, list) {
if ( ! V_2 -> V_57 || V_2 -> V_91 )
continue;
F_95 (c, &chip->bus->codec_list, list)
F_190 ( V_202 ) ;
}
F_91 ( & V_373 ) ;
return 0 ;
}
static int F_191 ( struct V_236 * V_9 )
{
struct V_118 * V_24 = F_192 ( V_9 ) ;
struct V_378 * V_221 = F_193 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
struct V_194 * V_195 ;
if ( V_2 -> V_91 )
return 0 ;
F_194 ( V_221 , V_379 ) ;
F_161 ( V_2 ) ;
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
F_195 ( V_24 ) ;
F_196 ( V_24 ) ;
F_197 ( V_24 , V_380 ) ;
return 0 ;
}
static int F_198 ( struct V_236 * V_9 )
{
struct V_118 * V_24 = F_192 ( V_9 ) ;
struct V_378 * V_221 = F_193 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
if ( V_2 -> V_91 )
return 0 ;
F_197 ( V_24 , V_381 ) ;
F_199 ( V_24 ) ;
if ( F_200 ( V_24 ) < 0 ) {
F_155 ( V_82 L_42
L_41 ) ;
F_178 ( V_221 ) ;
return - V_59 ;
}
F_201 ( V_24 ) ;
if ( V_2 -> V_76 )
if ( F_202 ( V_24 ) < 0 )
V_2 -> V_76 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 )
return - V_59 ;
F_69 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
F_98 ( V_2 -> V_57 ) ;
F_194 ( V_221 , V_382 ) ;
return 0 ;
}
static int F_203 ( struct V_236 * V_9 )
{
struct V_378 * V_221 = F_193 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
F_93 ( V_2 ) ;
F_161 ( V_2 ) ;
return 0 ;
}
static int F_204 ( struct V_236 * V_9 )
{
struct V_378 * V_221 = F_193 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
F_69 ( V_2 ) ;
F_65 ( V_2 , 1 ) ;
return 0 ;
}
static int F_205 ( struct V_236 * V_9 )
{
struct V_378 * V_221 = F_193 ( V_9 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
if ( ! V_383 ||
! ( V_2 -> V_47 & V_372 ) )
return - V_97 ;
return 0 ;
}
static int F_206 ( struct V_384 * V_385 , unsigned long V_386 , void * V_17 )
{
struct V_1 * V_2 = F_112 ( V_385 , struct V_1 , V_387 ) ;
F_207 ( V_2 -> V_57 ) ;
F_93 ( V_2 ) ;
return V_388 ;
}
static void F_208 ( struct V_1 * V_2 )
{
V_2 -> V_387 . V_389 = F_206 ;
F_209 ( & V_2 -> V_387 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
if ( V_2 -> V_387 . V_389 )
F_211 ( & V_2 -> V_387 ) ;
}
static void F_212 ( struct V_118 * V_24 ,
enum V_390 V_391 )
{
struct V_378 * V_221 = F_213 ( V_24 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
bool V_91 ;
F_214 ( & V_2 -> V_392 ) ;
if ( V_2 -> V_393 )
return;
V_91 = ( V_391 == V_394 ) ;
if ( V_2 -> V_91 == V_91 )
return;
if ( ! V_2 -> V_57 ) {
V_2 -> V_91 = V_91 ;
if ( ! V_91 ) {
F_14 (KERN_INFO SFX
L_43 ,
pci_name(chip->pci)) ;
if ( F_215 ( V_2 ) < 0 ||
F_216 ( V_2 ) < 0 ) {
F_14 (KERN_ERR SFX
L_44 ,
pci_name(chip->pci)) ;
V_2 -> V_393 = true ;
}
}
} else {
F_14 (KERN_INFO SFX
L_45 , pci_name(chip->pci),
disabled ? L_46 : L_47 ) ;
if ( V_91 ) {
F_191 ( & V_24 -> V_9 ) ;
V_2 -> V_91 = true ;
if ( F_217 ( V_2 -> V_57 ) )
F_14 (KERN_WARNING SFX L_48 ,
pci_name(chip->pci)) ;
} else {
F_218 ( V_2 -> V_57 ) ;
V_2 -> V_91 = false ;
F_198 ( & V_24 -> V_9 ) ;
}
}
}
static bool F_219 ( struct V_118 * V_24 )
{
struct V_378 * V_221 = F_213 ( V_24 ) ;
struct V_1 * V_2 = V_221 -> V_13 ;
F_214 ( & V_2 -> V_392 ) ;
if ( V_2 -> V_393 )
return false ;
if ( V_2 -> V_91 || ! V_2 -> V_57 )
return true ;
if ( F_217 ( V_2 -> V_57 ) )
return false ;
F_218 ( V_2 -> V_57 ) ;
return true ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_118 * V_195 = F_221 ( V_2 -> V_24 ) ;
if ( V_195 ) {
F_14 (KERN_INFO SFX
L_49 ,
pci_name(chip->pci)) ;
V_2 -> V_395 = 1 ;
F_222 ( V_195 ) ;
}
}
static int F_223 ( struct V_1 * V_2 )
{
int V_22 ;
if ( ! V_2 -> V_395 )
return 0 ;
V_22 = F_224 ( V_2 -> V_24 , & V_396 ,
V_397 ,
V_2 -> V_57 != NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_398 = 1 ;
return 0 ;
}
static int F_225 ( struct V_1 * V_2 )
{
int V_102 ;
F_186 ( V_2 ) ;
F_210 ( V_2 ) ;
V_2 -> V_393 = 1 ;
F_226 ( & V_2 -> V_392 ) ;
if ( V_395 ( V_2 ) ) {
if ( V_2 -> V_91 && V_2 -> V_57 )
F_218 ( V_2 -> V_57 ) ;
if ( V_2 -> V_398 )
F_227 ( V_2 -> V_24 ) ;
}
if ( V_2 -> V_114 ) {
F_161 ( V_2 ) ;
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ )
F_64 ( V_2 , & V_2 -> V_18 [ V_102 ] ) ;
F_93 ( V_2 ) ;
}
if ( V_2 -> V_77 >= 0 )
F_42 ( V_2 -> V_77 , ( void * ) V_2 ) ;
if ( V_2 -> V_76 )
F_43 ( V_2 -> V_24 ) ;
if ( V_2 -> V_325 )
F_228 ( V_2 -> V_325 ) ;
if ( V_2 -> V_18 ) {
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ )
if ( V_2 -> V_18 [ V_102 ] . V_158 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_18 [ V_102 ] . V_158 , false ) ;
F_181 ( & V_2 -> V_18 [ V_102 ] . V_158 ) ;
}
}
if ( V_2 -> V_25 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_25 , false ) ;
F_181 ( & V_2 -> V_25 ) ;
}
if ( V_2 -> V_116 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_116 , false ) ;
F_181 ( & V_2 -> V_116 ) ;
}
if ( V_2 -> V_399 )
F_229 ( V_2 -> V_24 ) ;
F_195 ( V_2 -> V_24 ) ;
F_167 ( V_2 -> V_18 ) ;
#ifdef F_230
if ( V_2 -> V_400 )
F_231 ( V_2 -> V_400 ) ;
#endif
F_167 ( V_2 ) ;
return 0 ;
}
static int F_232 ( struct V_401 * V_236 )
{
return F_225 ( V_236 -> V_402 ) ;
}
static struct V_118 * F_221 ( struct V_118 * V_24 )
{
struct V_118 * V_195 ;
switch ( V_24 -> V_403 ) {
case V_404 :
case V_405 :
case V_406 :
if ( V_24 -> V_407 == 1 ) {
V_195 = F_233 ( F_234 ( V_24 -> V_57 ) ,
V_24 -> V_57 -> V_237 , 0 ) ;
if ( V_195 ) {
if ( ( V_195 -> V_408 >> 8 ) == V_409 )
return V_195 ;
F_222 ( V_195 ) ;
}
}
break;
}
return NULL ;
}
static bool F_235 ( struct V_118 * V_24 )
{
bool V_410 = false ;
struct V_118 * V_195 = F_221 ( V_24 ) ;
if ( V_195 ) {
if ( F_236 ( V_195 ) == V_394 )
V_410 = true ;
F_222 ( V_195 ) ;
}
return V_410 ;
}
static int F_237 ( struct V_1 * V_2 , int V_411 )
{
const struct V_412 * V_413 ;
switch ( V_411 ) {
case V_331 :
case V_188 :
case V_333 :
case V_330 :
case V_414 :
return V_411 ;
}
V_413 = F_238 ( V_2 -> V_24 , V_415 ) ;
if ( V_413 ) {
F_155 ( V_416
L_50
L_51 ,
V_413 -> V_417 , V_413 -> V_418 , V_413 -> V_419 ) ;
return V_413 -> V_417 ;
}
if ( V_2 -> V_47 & V_420 ) {
F_48 ( V_74 L_52 , F_41 ( V_2 -> V_24 ) ) ;
return V_330 ;
}
if ( V_2 -> V_47 & V_421 ) {
F_48 ( V_74 L_53 , F_41 ( V_2 -> V_24 ) ) ;
return V_188 ;
}
return V_331 ;
}
static void F_239 ( struct V_1 * V_2 , int V_9 )
{
const struct V_412 * V_413 ;
V_2 -> V_226 = V_422 [ V_9 ] ;
if ( V_2 -> V_226 == - 1 ) {
V_413 = F_238 ( V_2 -> V_24 , V_423 ) ;
if ( V_413 ) {
F_155 ( V_416
L_54
L_51 ,
V_413 -> V_417 , V_413 -> V_418 , V_413 -> V_419 ) ;
V_2 -> V_226 = V_413 -> V_417 ;
}
}
if ( V_2 -> V_226 != - 1 &&
( V_2 -> V_226 & V_424 ) ) {
V_2 -> V_98 = V_2 -> V_226 & 0xff ;
F_155 ( V_416 L_55 ,
V_2 -> V_98 ) ;
}
}
static void F_240 ( struct V_1 * V_2 )
{
const struct V_412 * V_413 ;
if ( V_425 >= 0 ) {
V_2 -> V_76 = ! ! V_425 ;
return;
}
V_2 -> V_76 = 1 ;
V_413 = F_238 ( V_2 -> V_24 , V_426 ) ;
if ( V_413 ) {
F_155 ( V_416
L_56 ,
V_413 -> V_418 , V_413 -> V_419 , V_413 -> V_417 ) ;
V_2 -> V_76 = V_413 -> V_417 ;
return;
}
if ( V_2 -> V_47 & V_427 ) {
F_155 ( V_416 L_57 ) ;
V_2 -> V_76 = 0 ;
}
}
static void F_241 ( struct V_1 * V_2 )
{
bool V_134 = V_2 -> V_134 ;
switch ( V_2 -> V_224 ) {
case V_428 :
if ( V_134 ) {
T_2 V_58 ;
F_67 ( V_2 -> V_24 , 0x42 , & V_58 ) ;
if ( ! ( V_58 & 0x80 ) && V_2 -> V_24 -> V_429 == 0x30 )
V_134 = false ;
}
break;
case V_430 :
V_134 = false ;
break;
case V_431 :
V_134 = false ;
break;
}
if ( V_134 != V_2 -> V_134 ) {
F_14 (KERN_INFO SFX L_58 ,
pci_name(chip->pci), snoop ? L_59 : L_60 ) ;
V_2 -> V_134 = V_134 ;
}
}
static int F_242 ( struct V_378 * V_221 , struct V_118 * V_24 ,
int V_9 , unsigned int V_47 ,
struct V_1 * * V_432 )
{
static struct V_433 V_206 = {
. V_434 = F_232 ,
} ;
struct V_1 * V_2 ;
int V_22 ;
* V_432 = NULL ;
V_22 = F_200 ( V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 = F_170 ( sizeof( * V_2 ) , V_350 ) ;
if ( ! V_2 ) {
F_14 (KERN_ERR SFX L_61 , pci_name(pci)) ;
F_195 ( V_24 ) ;
return - V_351 ;
}
F_243 ( & V_2 -> V_26 ) ;
F_244 ( & V_2 -> V_267 ) ;
V_2 -> V_221 = V_221 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_77 = - 1 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_224 = V_47 & 0xff ;
F_240 ( V_2 ) ;
V_2 -> V_172 = V_9 ;
F_245 ( & V_2 -> V_150 , F_160 ) ;
F_246 ( & V_2 -> V_357 ) ;
F_246 ( & V_2 -> V_344 ) ;
F_220 ( V_2 ) ;
F_247 ( & V_2 -> V_392 ) ;
V_2 -> V_187 [ 0 ] = V_2 -> V_187 [ 1 ] =
F_237 ( V_2 , V_187 [ V_9 ] ) ;
if ( V_2 -> V_187 [ 0 ] == V_414 ) {
V_2 -> V_187 [ 0 ] = V_188 ;
V_2 -> V_187 [ 1 ] = V_331 ;
}
F_239 ( V_2 , V_9 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_134 = V_435 ;
F_241 ( V_2 ) ;
if ( V_171 [ V_9 ] < 0 ) {
switch ( V_2 -> V_224 ) {
case V_436 :
case V_437 :
V_171 [ V_9 ] = 1 ;
break;
default:
V_171 [ V_9 ] = 32 ;
break;
}
}
V_22 = F_248 ( V_221 , V_438 , V_2 , & V_206 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_62 ,
pci_name(chip->pci)) ;
F_225 ( V_2 ) ;
return V_22 ;
}
* V_432 = V_2 ;
return 0 ;
}
static int F_215 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_172 ;
struct V_118 * V_24 = V_2 -> V_24 ;
struct V_378 * V_221 = V_2 -> V_221 ;
int V_102 , V_22 ;
unsigned short V_439 ;
#if V_440 != 64
if ( V_2 -> V_224 == V_441 ) {
T_7 V_442 ;
F_70 ( V_24 , 0x40 , & V_442 ) ;
F_71 ( V_24 , 0x40 , V_442 | 0x10 ) ;
F_249 ( V_24 , V_443 , 0 ) ;
}
#endif
V_22 = F_250 ( V_24 , L_63 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_399 = 1 ;
V_2 -> V_28 = F_251 ( V_24 , 0 ) ;
V_2 -> V_325 = F_252 ( V_24 , 0 ) ;
if ( V_2 -> V_325 == NULL ) {
F_14 (KERN_ERR SFX L_64 , pci_name(chip->pci)) ;
return - V_233 ;
}
if ( V_2 -> V_76 )
if ( F_202 ( V_24 ) < 0 )
V_2 -> V_76 = 0 ;
if ( F_44 ( V_2 , 0 ) < 0 )
return - V_97 ;
F_201 ( V_24 ) ;
F_253 ( V_2 -> V_77 ) ;
V_439 = F_27 ( V_2 , V_444 ) ;
F_40 ( V_74 L_65 , F_41 ( V_2 -> V_24 ) , V_439 ) ;
if ( V_2 -> V_24 -> V_403 == V_404 ) {
struct V_118 * V_445 ;
V_445 = F_254 ( V_404 ,
V_446 ,
NULL ) ;
if ( V_445 ) {
if ( V_445 -> V_429 < 0x30 )
V_439 &= ~ V_447 ;
F_222 ( V_445 ) ;
}
}
if ( V_2 -> V_47 & V_448 ) {
F_48 ( V_74 L_66 , F_41 ( V_2 -> V_24 ) ) ;
V_439 &= ~ V_447 ;
}
if ( V_276 >= 0 )
V_2 -> V_276 = ! ! V_276 ;
else {
if ( V_2 -> V_47 & V_449 )
V_2 -> V_276 = 0 ;
else if ( V_2 -> V_47 & V_450 )
V_2 -> V_276 = 1 ;
else
V_2 -> V_276 = 1 ;
}
if ( ( V_439 & V_447 ) && ! F_255 ( V_24 , F_256 ( 64 ) ) )
F_257 ( V_24 , F_256 ( 64 ) ) ;
else {
F_255 ( V_24 , F_256 ( 32 ) ) ;
F_257 ( V_24 , F_256 ( 32 ) ) ;
}
V_2 -> V_243 = ( V_439 >> 8 ) & 0x0f ;
V_2 -> V_241 = ( V_439 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_241 && ! V_2 -> V_243 ) {
switch ( V_2 -> V_224 ) {
case V_441 :
V_2 -> V_241 = V_451 ;
V_2 -> V_243 = V_452 ;
break;
case V_453 :
case V_430 :
V_2 -> V_241 = V_454 ;
V_2 -> V_243 = V_455 ;
break;
case V_456 :
default:
V_2 -> V_241 = V_457 ;
V_2 -> V_243 = V_458 ;
break;
}
}
V_2 -> V_242 = 0 ;
V_2 -> V_240 = V_2 -> V_243 ;
V_2 -> V_103 = V_2 -> V_241 + V_2 -> V_243 ;
V_2 -> V_18 = F_258 ( V_2 -> V_103 , sizeof( * V_2 -> V_18 ) ,
V_350 ) ;
if ( ! V_2 -> V_18 ) {
F_14 (KERN_ERR SFX L_67 , pci_name(chip->pci)) ;
return - V_351 ;
}
for ( V_102 = 0 ; V_102 < V_2 -> V_103 ; V_102 ++ ) {
F_259 ( & V_2 -> V_18 [ V_102 ] ) ;
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_459 , & V_2 -> V_18 [ V_102 ] . V_158 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_68 , pci_name(chip->pci)) ;
return - V_351 ;
}
F_8 ( V_2 , & V_2 -> V_18 [ V_102 ] . V_158 , true ) ;
}
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_2 -> V_103 * 8 , & V_2 -> V_116 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_69 , pci_name(chip->pci)) ;
return - V_351 ;
}
F_8 ( V_2 , & V_2 -> V_116 , true ) ;
V_22 = F_11 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
F_176 ( V_2 ) ;
F_69 ( V_2 ) ;
F_65 ( V_2 , ( V_460 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_98 ) {
F_14 (KERN_ERR SFX L_70 , pci_name(chip->pci)) ;
return - V_461 ;
}
strcpy ( V_221 -> V_462 , L_71 ) ;
F_169 ( V_221 -> V_463 , V_464 [ V_2 -> V_224 ] ,
sizeof( V_221 -> V_463 ) ) ;
snprintf ( V_221 -> V_465 , sizeof( V_221 -> V_465 ) ,
L_72 ,
V_221 -> V_463 , V_2 -> V_28 , V_2 -> V_77 ) ;
return 0 ;
}
static void F_260 ( struct V_1 * V_2 )
{
#ifdef F_94
struct V_229 * V_230 ;
F_95 (codec, &chip->bus->codec_list, list) {
F_128 ( V_230 ) ;
}
#endif
}
static void F_261 ( const struct V_466 * V_400 , void * V_467 )
{
struct V_378 * V_221 = V_467 ;
struct V_1 * V_2 = V_221 -> V_13 ;
struct V_118 * V_24 = V_2 -> V_24 ;
if ( ! V_400 ) {
F_14 (KERN_ERR SFX L_73 ,
pci_name(chip->pci)) ;
goto error;
}
V_2 -> V_400 = V_400 ;
if ( ! V_2 -> V_91 ) {
if ( F_216 ( V_2 ) )
goto error;
}
return;
error:
F_262 ( V_221 ) ;
F_263 ( V_24 , NULL ) ;
}
static int F_264 ( struct V_118 * V_24 ,
const struct V_468 * V_469 )
{
static int V_9 ;
struct V_378 * V_221 ;
struct V_1 * V_2 ;
bool V_470 ;
int V_22 ;
if ( V_9 >= V_471 )
return - V_461 ;
if ( ! V_472 [ V_9 ] ) {
V_9 ++ ;
return - V_473 ;
}
V_22 = F_265 ( V_112 [ V_9 ] , V_474 [ V_9 ] , V_475 , 0 , & V_221 ) ;
if ( V_22 < 0 ) {
F_14 ( V_82 L_74 ) ;
return V_22 ;
}
F_266 ( V_221 , & V_24 -> V_9 ) ;
V_22 = F_242 ( V_221 , V_24 , V_9 , V_469 -> V_476 , & V_2 ) ;
if ( V_22 < 0 )
goto V_477;
V_221 -> V_13 = V_2 ;
F_263 ( V_24 , V_221 ) ;
V_22 = F_223 ( V_2 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX
L_75 , pci_name(pci)) ;
goto V_477;
}
if ( F_235 ( V_24 ) ) {
F_14 (KERN_INFO SFX L_76 ,
pci_name(pci)) ;
F_14 (KERN_INFO SFX L_77 , pci_name(pci)) ;
V_2 -> V_91 = true ;
}
V_470 = ! V_2 -> V_91 ;
if ( V_470 ) {
V_22 = F_215 ( V_2 ) ;
if ( V_22 < 0 )
goto V_477;
}
#ifdef F_230
if ( V_478 [ V_9 ] && * V_478 [ V_9 ] ) {
F_14 (KERN_ERR SFX L_78 ,
pci_name(pci), patch[dev]) ;
V_22 = F_267 ( V_475 , true , V_478 [ V_9 ] ,
& V_24 -> V_9 , V_350 , V_221 ,
F_261 ) ;
if ( V_22 < 0 )
goto V_477;
V_470 = false ;
}
#endif
if ( V_470 ) {
V_22 = F_216 ( V_2 ) ;
if ( V_22 < 0 )
goto V_477;
}
if ( F_268 ( V_24 ) )
F_269 ( & V_24 -> V_9 ) ;
V_9 ++ ;
F_226 ( & V_2 -> V_392 ) ;
return 0 ;
V_477:
F_262 ( V_221 ) ;
F_263 ( V_24 , NULL ) ;
return V_22 ;
}
static int F_216 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_172 ;
int V_22 ;
#ifdef F_270
V_2 -> V_232 = V_232 [ V_9 ] ;
#endif
V_22 = F_100 ( V_2 , V_199 [ V_9 ] ) ;
if ( V_22 < 0 )
goto V_477;
#ifdef F_230
if ( V_2 -> V_400 ) {
V_22 = F_271 ( V_2 -> V_57 , V_2 -> V_400 -> V_156 ,
V_2 -> V_400 -> V_121 ) ;
if ( V_22 < 0 )
goto V_477;
#ifndef F_94
F_231 ( V_2 -> V_400 ) ;
V_2 -> V_400 = NULL ;
#endif
}
#endif
if ( ( V_460 [ V_9 ] & 1 ) == 0 ) {
V_22 = F_104 ( V_2 ) ;
if ( V_22 < 0 )
goto V_477;
}
V_22 = F_272 ( V_2 -> V_57 ) ;
if ( V_22 < 0 )
goto V_477;
V_22 = F_174 ( V_2 ) ;
if ( V_22 < 0 )
goto V_477;
V_22 = F_273 ( V_2 -> V_221 ) ;
if ( V_22 < 0 )
goto V_477;
V_2 -> V_146 = 1 ;
F_260 ( V_2 ) ;
F_208 ( V_2 ) ;
F_184 ( V_2 ) ;
return 0 ;
V_477:
V_2 -> V_393 = 1 ;
return V_22 ;
}
static void F_274 ( struct V_118 * V_24 )
{
struct V_378 * V_221 = F_213 ( V_24 ) ;
if ( F_268 ( V_24 ) )
F_275 ( & V_24 -> V_9 ) ;
if ( V_221 )
F_262 ( V_221 ) ;
F_263 ( V_24 , NULL ) ;
}
