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
if ( ! V_57 -> V_74 )
return - 1 ;
if ( ! V_2 -> V_70 && V_2 -> V_72 < 2 ) {
F_40 ( V_75 L_4
L_5 ,
F_41 ( V_2 -> V_24 ) , V_2 -> V_76 [ V_28 ] ) ;
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
if ( V_2 -> V_77 ) {
F_14 (KERN_WARNING SFX L_7
L_8 ,
pci_name(chip->pci), chip->last_cmd[addr]) ;
F_42 ( V_2 -> V_78 , V_2 ) ;
V_2 -> V_78 = - 1 ;
F_43 ( V_2 -> V_24 ) ;
V_2 -> V_77 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 ) {
V_57 -> V_71 = 1 ;
return - 1 ;
}
goto V_68;
}
if ( V_2 -> V_79 ) {
return - 1 ;
}
V_57 -> V_71 = 1 ;
if ( V_57 -> V_80 && ! V_57 -> V_81 && ! V_57 -> V_82 ) {
V_57 -> V_81 = 1 ;
return - 1 ;
}
F_14 ( V_83 L_9
L_10 ,
V_2 -> V_76 [ V_28 ] ) ;
V_2 -> V_84 = 1 ;
V_57 -> V_81 = 0 ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_85 , F_45 ( V_2 , V_85 ) & ~ V_86 ) ;
return - 1 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_65 = 50 ;
while ( V_65 -- ) {
if ( F_27 ( V_2 , V_87 ) & V_88 ) {
V_2 -> V_38 . V_55 [ V_28 ] = F_45 ( V_2 , V_89 ) ;
return 0 ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_75 L_11 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_87 ) ) ;
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
if ( ! ( ( F_27 ( V_2 , V_87 ) & V_90 ) ) ) {
F_20 ( V_2 , V_87 , F_27 ( V_2 , V_87 ) |
V_88 ) ;
F_17 ( V_2 , V_91 , V_58 ) ;
F_20 ( V_2 , V_87 , F_27 ( V_2 , V_87 ) |
V_90 ) ;
return F_46 ( V_2 , V_28 ) ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_75 L_12 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_87 ) , V_58 ) ;
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
if ( V_2 -> V_92 )
return 0 ;
V_2 -> V_76 [ F_23 ( V_58 ) ] = V_58 ;
if ( V_2 -> V_84 )
return F_49 ( V_57 , V_58 ) ;
else
return F_26 ( V_57 , V_58 ) ;
}
static unsigned int F_52 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( V_2 -> V_92 )
return 0 ;
if ( V_2 -> V_84 )
return F_50 ( V_57 , V_28 ) ;
else
return F_33 ( V_57 , V_28 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned long V_65 ;
F_17 ( V_2 , V_85 , F_45 ( V_2 , V_85 ) & ~ V_93 ) ;
V_65 = V_69 + F_34 ( 100 ) ;
while ( ( F_54 ( V_2 , V_85 ) & V_93 ) &&
F_55 ( V_69 , V_65 ) )
F_56 ( 500 , 1000 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned long V_65 ;
F_19 ( V_2 , V_85 , F_54 ( V_2 , V_85 ) | V_93 ) ;
V_65 = V_69 + F_34 ( 100 ) ;
while ( ! F_54 ( V_2 , V_85 ) &&
F_55 ( V_69 , V_65 ) )
F_56 ( 500 , 1000 ) ;
}
static int F_58 ( struct V_1 * V_2 , int V_94 )
{
if ( ! V_94 )
goto V_95;
F_20 ( V_2 , V_96 , V_97 ) ;
F_53 ( V_2 ) ;
F_56 ( 500 , 1000 ) ;
F_57 ( V_2 ) ;
F_56 ( 1000 , 1200 ) ;
V_95:
if ( ! F_54 ( V_2 , V_85 ) ) {
F_48 ( V_75 L_13 , F_41 ( V_2 -> V_24 ) ) ;
return - V_98 ;
}
if ( ! V_2 -> V_84 )
F_17 ( V_2 , V_85 , F_45 ( V_2 , V_85 ) |
V_86 ) ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = F_27 ( V_2 , V_96 ) ;
F_40 ( V_75 L_14 , F_41 ( V_2 -> V_24 ) , V_2 -> V_99 ) ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_100 , F_45 ( V_2 , V_100 ) |
V_101 | V_102 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
F_61 ( V_18 , V_105 ,
F_62 ( V_18 , V_105 ) & ~ V_106 ) ;
}
F_19 ( V_2 , V_100 , 0 ) ;
F_17 ( V_2 , V_100 , F_45 ( V_2 , V_100 ) &
~ ( V_101 | V_102 ) ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
F_61 ( V_18 , V_107 , V_106 ) ;
}
F_20 ( V_2 , V_96 , V_97 ) ;
F_19 ( V_2 , V_108 , V_109 ) ;
F_17 ( V_2 , V_110 , V_101 | V_111 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_18 -> V_112 = 1 ;
F_17 ( V_2 , V_100 ,
F_45 ( V_2 , V_100 ) | ( 1 << V_18 -> V_113 ) ) ;
F_61 ( V_18 , V_105 , F_62 ( V_18 , V_105 ) |
V_114 | V_106 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_61 ( V_18 , V_105 , F_62 ( V_18 , V_105 ) &
~ ( V_114 | V_106 ) ) ;
F_61 ( V_18 , V_107 , V_106 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_65 ( V_2 , V_18 ) ;
F_17 ( V_2 , V_100 ,
F_45 ( V_2 , V_100 ) & ~ ( 1 << V_18 -> V_113 ) ) ;
}
static void F_67 ( struct V_1 * V_2 , int V_94 )
{
if ( V_2 -> V_115 )
return;
F_58 ( V_2 , V_94 ) ;
F_63 ( V_2 ) ;
F_59 ( V_2 ) ;
if ( ! V_2 -> V_84 )
F_15 ( V_2 ) ;
F_17 ( V_2 , V_116 , ( V_29 ) V_2 -> V_117 . V_28 ) ;
F_17 ( V_2 , V_118 , F_18 ( V_2 -> V_117 . V_28 ) ) ;
V_2 -> V_115 = 1 ;
}
static void F_68 ( struct V_119 * V_24 , unsigned int V_120 ,
unsigned char V_121 , unsigned char V_58 )
{
unsigned char V_122 ;
F_69 ( V_24 , V_120 , & V_122 ) ;
V_122 &= ~ V_121 ;
V_122 |= ( V_58 & V_121 ) ;
F_70 ( V_24 , V_120 , V_122 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_47 & V_123 ) ) {
F_40 ( V_75 L_15 , F_41 ( V_2 -> V_24 ) ) ;
F_68 ( V_2 -> V_24 , V_124 , 0x07 , 0 ) ;
}
if ( V_2 -> V_47 & V_125 ) {
F_40 ( V_75 L_16 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_68 ( V_2 -> V_24 ,
V_126 , 0x07 ,
F_2 ( V_2 ) ? V_127 : 0 ) ;
}
if ( V_2 -> V_47 & V_128 ) {
F_40 ( V_75 L_17 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_68 ( V_2 -> V_24 ,
V_129 ,
0x0f , V_130 ) ;
F_68 ( V_2 -> V_24 ,
V_131 ,
0x01 , V_132 ) ;
F_68 ( V_2 -> V_24 ,
V_133 ,
0x01 , V_132 ) ;
}
if ( V_2 -> V_47 & V_134 ) {
unsigned short V_135 ;
F_72 ( V_2 -> V_24 , V_136 , & V_135 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_135 & V_137 ) ) ||
( F_2 ( V_2 ) && ( V_135 & V_137 ) ) ) {
V_135 &= ~ V_137 ;
if ( ! F_2 ( V_2 ) )
V_135 |= V_137 ;
F_73 ( V_2 -> V_24 , V_136 , V_135 ) ;
F_72 ( V_2 -> V_24 ,
V_136 , & V_135 ) ;
}
F_40 ( V_75 L_18 ,
F_41 ( V_2 -> V_24 ) , ( V_135 & V_137 )
? L_19 : L_20 ) ;
}
}
static T_1 F_74 ( int V_78 , void * V_138 )
{
struct V_1 * V_2 = V_138 ;
struct V_18 * V_18 ;
V_29 V_139 ;
T_2 V_140 ;
int V_103 , V_141 ;
#ifdef F_75
if ( V_2 -> V_47 & V_142 )
if ( V_2 -> V_24 -> V_9 . V_143 . V_144 != V_145 )
return V_146 ;
#endif
F_76 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_92 ) {
F_77 ( & V_2 -> V_26 ) ;
return V_146 ;
}
V_139 = F_45 ( V_2 , V_110 ) ;
if ( V_139 == 0 || V_139 == 0xffffffff ) {
F_77 ( & V_2 -> V_26 ) ;
return V_146 ;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
V_18 = & V_2 -> V_18 [ V_103 ] ;
if ( V_139 & V_18 -> V_147 ) {
V_140 = F_62 ( V_18 , V_107 ) ;
F_61 ( V_18 , V_107 , V_106 ) ;
if ( ! V_18 -> V_20 || ! V_18 -> V_148 ||
! ( V_140 & V_149 ) )
continue;
V_141 = F_78 ( V_2 , V_18 ) ;
if ( V_141 == 1 ) {
V_18 -> V_150 = 0 ;
F_77 ( & V_2 -> V_26 ) ;
F_79 ( V_18 -> V_20 ) ;
F_76 ( & V_2 -> V_26 ) ;
} else if ( V_141 == 0 && V_2 -> V_57 && V_2 -> V_57 -> V_151 ) {
V_18 -> V_150 = 1 ;
F_80 ( V_2 -> V_57 -> V_151 ,
& V_2 -> V_152 ) ;
}
}
}
V_139 = F_54 ( V_2 , V_108 ) ;
if ( V_139 & V_109 ) {
if ( V_139 & V_153 ) {
if ( V_2 -> V_47 & V_154 )
F_38 ( 80 ) ;
F_29 ( V_2 ) ;
}
F_19 ( V_2 , V_108 , V_109 ) ;
}
#if 0
if (azx_readw(chip, STATESTS) & 0x04)
azx_writew(chip, STATESTS, 0x04);
#endif
F_77 ( & V_2 -> V_26 ) ;
return V_155 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_18 , V_29 * * V_156 ,
int V_157 , int V_158 , int V_159 )
{
V_29 * V_160 = * V_156 ;
while ( V_158 > 0 ) {
T_3 V_28 ;
int V_161 ;
if ( V_18 -> V_162 >= V_163 )
return - V_164 ;
V_28 = F_82 ( V_4 , V_157 ) ;
V_160 [ 0 ] = F_28 ( ( V_29 ) V_28 ) ;
V_160 [ 1 ] = F_28 ( F_18 ( V_28 ) ) ;
V_161 = F_83 ( V_4 , V_157 , V_158 ) ;
if ( V_2 -> V_47 & V_165 ) {
V_29 V_166 = 0x1000 - ( V_157 & 0xfff ) ;
if ( V_161 > V_166 )
V_161 = V_166 ;
}
V_160 [ 2 ] = F_28 ( V_161 ) ;
V_158 -= V_161 ;
V_160 [ 3 ] = ( V_158 || ! V_159 ) ? 0 : F_28 ( 0x01 ) ;
V_160 += 4 ;
V_18 -> V_162 ++ ;
V_157 += V_161 ;
}
* V_156 = V_160 ;
return V_157 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_18 * V_18 )
{
V_29 * V_160 ;
int V_103 , V_157 , V_167 , V_168 ;
int V_169 ;
F_85 ( V_18 , V_170 , 0 ) ;
F_85 ( V_18 , V_171 , 0 ) ;
V_168 = V_18 -> V_168 ;
V_167 = V_18 -> V_172 / V_168 ;
V_160 = ( V_29 * ) V_18 -> V_160 . V_7 ;
V_157 = 0 ;
V_18 -> V_162 = 0 ;
V_169 = V_173 [ V_2 -> V_174 ] ;
if ( ! V_18 -> V_175 && V_169 > 0 ) {
struct V_176 * V_177 = V_20 -> V_177 ;
int V_178 = V_169 ;
V_169 = ( V_169 * V_177 -> V_179 + 47999 ) / 48000 ;
if ( ! V_169 )
V_169 = V_178 ;
else
V_169 = ( ( V_169 + V_178 - 1 ) / V_178 ) *
V_178 ;
V_169 = F_86 ( V_177 , V_169 ) ;
if ( V_169 >= V_168 ) {
F_14 (KERN_WARNING SFX L_21 ,
pci_name(chip->pci), bdl_pos_adj[chip->dev_index]) ;
V_169 = 0 ;
} else {
V_157 = F_81 ( V_2 , F_10 ( V_20 ) ,
V_18 ,
& V_160 , V_157 , V_169 , true ) ;
if ( V_157 < 0 )
goto error;
}
} else
V_169 = 0 ;
for ( V_103 = 0 ; V_103 < V_167 ; V_103 ++ ) {
if ( V_103 == V_167 - 1 && V_169 )
V_157 = F_81 ( V_2 , F_10 ( V_20 ) ,
V_18 , & V_160 , V_157 ,
V_168 - V_169 , 0 ) ;
else
V_157 = F_81 ( V_2 , F_10 ( V_20 ) ,
V_18 , & V_160 , V_157 ,
V_168 ,
! V_18 -> V_175 ) ;
if ( V_157 < 0 )
goto error;
}
return 0 ;
error:
F_14 (KERN_ERR SFX L_22 ,
pci_name(chip->pci), azx_dev->bufsize, period_bytes) ;
return - V_164 ;
}
static void F_87 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned char V_58 ;
int V_65 ;
F_65 ( V_2 , V_18 ) ;
F_61 ( V_18 , V_105 , F_62 ( V_18 , V_105 ) |
V_180 ) ;
F_38 ( 3 ) ;
V_65 = 300 ;
while ( ! ( ( V_58 = F_62 ( V_18 , V_105 ) ) & V_180 ) &&
-- V_65 )
;
V_58 &= ~ V_180 ;
F_61 ( V_18 , V_105 , V_58 ) ;
F_38 ( 3 ) ;
V_65 = 300 ;
while ( ( ( V_58 = F_62 ( V_18 , V_105 ) ) & V_180 ) &&
-- V_65 )
;
* V_18 -> V_117 = 0 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned int V_58 ;
F_65 ( V_2 , V_18 ) ;
V_58 = F_89 ( V_18 , V_105 ) ;
V_58 = ( V_58 & ~ V_181 ) |
( V_18 -> V_182 << V_183 ) ;
if ( ! F_2 ( V_2 ) )
V_58 |= V_184 ;
F_85 ( V_18 , V_105 , V_58 ) ;
F_85 ( V_18 , V_185 , V_18 -> V_172 ) ;
F_90 ( V_18 , V_186 , V_18 -> V_187 ) ;
F_90 ( V_18 , V_188 , V_18 -> V_162 - 1 ) ;
F_85 ( V_18 , V_170 , ( V_29 ) V_18 -> V_160 . V_28 ) ;
F_85 ( V_18 , V_171 , F_18 ( V_18 -> V_160 . V_28 ) ) ;
if ( V_2 -> V_189 [ 0 ] != V_190 ||
V_2 -> V_189 [ 1 ] != V_190 ) {
if ( ! ( F_45 ( V_2 , V_116 ) & V_191 ) )
F_17 ( V_2 , V_116 ,
( V_29 ) V_2 -> V_117 . V_28 | V_191 ) ;
}
F_85 ( V_18 , V_105 ,
F_89 ( V_18 , V_105 ) | V_106 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_53 = ( V_28 << 28 ) | ( V_192 << 20 ) |
( V_193 << 8 ) | V_194 ;
unsigned int V_55 ;
F_92 ( & V_2 -> V_57 -> V_195 ) ;
V_2 -> V_79 = 1 ;
F_51 ( V_2 -> V_57 , V_53 ) ;
V_55 = F_52 ( V_2 -> V_57 , V_28 ) ;
V_2 -> V_79 = 0 ;
F_93 ( & V_2 -> V_57 -> V_195 ) ;
if ( V_55 == - 1 )
return - V_59 ;
F_40 ( V_75 L_23 , F_41 ( V_2 -> V_24 ) , V_28 ) ;
return 0 ;
}
static void F_94 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
V_57 -> V_82 = 1 ;
F_95 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
#ifdef F_96
if ( V_2 -> V_115 ) {
struct V_196 * V_197 ;
F_97 (p, &chip->pcm_list, list)
F_98 ( V_197 -> V_198 ) ;
F_99 ( V_2 -> V_57 ) ;
F_100 ( V_2 -> V_57 ) ;
}
#endif
V_57 -> V_82 = 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_103 = V_199 [ V_2 -> V_174 ] ;
unsigned int V_200 ;
if ( V_103 == 0 )
return 0 ;
if ( V_103 < 50 || V_103 > 60000 )
V_200 = 0 ;
else
V_200 = F_34 ( V_103 ) ;
if ( V_200 == 0 )
F_14 (KERN_WARNING SFX
L_24 , i) ;
return V_200 ;
}
static int F_102 ( struct V_1 * V_2 , const char * V_201 )
{
struct V_202 V_203 ;
int V_204 , V_205 , V_22 ;
int V_206 ;
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_203 . V_13 = V_2 ;
V_203 . V_207 = V_201 ;
V_203 . V_24 = V_2 -> V_24 ;
V_203 . V_208 . V_209 = F_51 ;
V_203 . V_208 . V_210 = F_52 ;
V_203 . V_208 . V_211 = V_212 ;
V_203 . V_208 . V_213 = F_94 ;
#ifdef F_96
V_203 . V_214 = & V_214 ;
V_203 . V_208 . V_215 = V_216 ;
#endif
#ifdef F_103
V_203 . V_208 . V_217 = V_218 ;
V_203 . V_208 . V_219 = V_220 ;
V_203 . V_208 . V_221 = V_222 ;
#endif
V_22 = F_104 ( V_2 -> V_223 , & V_203 , & V_2 -> V_57 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_2 -> V_47 & V_224 ) {
F_48 ( V_75 L_25 , F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_73 = 1 ;
}
V_205 = 0 ;
V_206 = V_225 [ V_2 -> V_226 ] ;
if ( ! V_206 )
V_206 = V_227 ;
for ( V_204 = 0 ; V_204 < V_206 ; V_204 ++ ) {
if ( ( V_2 -> V_99 & ( 1 << V_204 ) ) & V_2 -> V_228 ) {
if ( F_91 ( V_2 , V_204 ) < 0 ) {
F_14 (KERN_WARNING SFX
L_26
L_27 , pci_name(chip->pci), c) ;
V_2 -> V_99 &= ~ ( 1 << V_204 ) ;
F_95 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_47 & V_229 ) {
F_48 ( V_75 L_28 ,
F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_230 = 1 ;
V_2 -> V_57 -> V_80 = 1 ;
}
for ( V_204 = 0 ; V_204 < V_206 ; V_204 ++ ) {
if ( ( V_2 -> V_99 & ( 1 << V_204 ) ) & V_2 -> V_228 ) {
struct V_231 * V_232 ;
V_22 = F_105 ( V_2 -> V_57 , V_204 , & V_232 ) ;
if ( V_22 < 0 )
continue;
V_232 -> V_233 = F_101 ( V_2 ) ;
V_232 -> V_234 = V_2 -> V_234 ;
V_205 ++ ;
}
}
if ( ! V_205 ) {
F_14 (KERN_ERR SFX L_29 , pci_name(chip->pci)) ;
return - V_235 ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_231 * V_232 ;
F_97 (codec, &chip->bus->codec_list, list) {
F_107 ( V_232 ) ;
}
return 0 ;
}
static inline struct V_18 *
F_108 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_9 , V_103 , V_236 ;
struct V_18 * V_55 = NULL ;
int V_237 = ( V_20 -> V_198 -> V_238 << 16 ) | ( V_20 -> V_239 << 2 ) |
( V_20 -> V_240 + 1 ) ;
if ( V_20 -> V_240 == V_241 ) {
V_9 = V_2 -> V_242 ;
V_236 = V_2 -> V_243 ;
} else {
V_9 = V_2 -> V_244 ;
V_236 = V_2 -> V_245 ;
}
for ( V_103 = 0 ; V_103 < V_236 ; V_103 ++ , V_9 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_9 ] ;
F_109 ( V_18 ) ;
if ( ! V_18 -> V_246 && ! F_110 ( V_18 ) ) {
V_55 = V_18 ;
if ( V_55 -> V_247 == V_237 ) {
V_55 -> V_246 = 1 ;
V_55 -> V_247 = V_237 ;
F_111 ( V_18 ) ;
return V_18 ;
}
}
F_111 ( V_18 ) ;
}
if ( V_55 ) {
F_109 ( V_55 ) ;
V_55 -> V_246 = 1 ;
V_55 -> V_247 = V_237 ;
F_111 ( V_55 ) ;
}
return V_55 ;
}
static inline void F_112 ( struct V_18 * V_18 )
{
V_18 -> V_246 = 0 ;
}
static T_4 F_113 ( const struct V_248 * V_249 )
{
struct V_18 * V_18 = F_114 ( V_249 , struct V_18 , V_250 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_251 -> V_2 ;
return F_45 ( V_2 , V_252 ) ;
}
static void F_116 ( struct V_19 * V_20 ,
bool V_253 , T_4 V_254 )
{
struct V_18 * V_18 = F_117 ( V_20 ) ;
struct V_255 * V_256 = & V_18 -> V_257 ;
struct V_248 * V_249 = & V_18 -> V_250 ;
T_5 V_258 ;
V_249 -> V_259 = F_113 ;
V_249 -> V_121 = F_118 ( 32 ) ;
V_249 -> V_260 = 125 ;
V_249 -> V_261 = 0 ;
V_258 = 0 ;
F_119 ( V_256 , V_249 , V_258 ) ;
if ( V_253 )
V_256 -> V_262 = V_254 ;
}
static T_5 F_120 ( struct V_19 * V_20 ,
T_5 V_258 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_263 * V_264 = V_251 -> V_264 [ V_20 -> V_240 ] ;
T_5 V_265 , V_266 ;
if ( ! V_264 -> V_208 . V_267 )
return V_258 ;
V_265 = V_264 -> V_208 . V_267 ( V_264 , V_251 -> V_232 , V_20 ) ;
V_266 = F_121 ( V_265 * 1000000000LL ,
V_20 -> V_177 -> V_179 ) ;
if ( V_20 -> V_240 == V_268 )
return V_258 + V_266 ;
return ( V_258 > V_266 ) ? V_258 - V_266 : 0 ;
}
static int F_122 ( struct V_19 * V_20 ,
struct V_269 * V_270 )
{
struct V_18 * V_18 = F_117 ( V_20 ) ;
T_5 V_258 ;
V_258 = F_123 ( & V_18 -> V_257 ) ;
V_258 = F_121 ( V_258 , 3 ) ;
V_258 = F_120 ( V_20 , V_258 ) ;
* V_270 = F_124 ( V_258 ) ;
return 0 ;
}
static int F_125 ( struct V_19 * V_20 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_263 * V_264 = V_251 -> V_264 [ V_20 -> V_240 ] ;
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_18 * V_18 ;
struct V_176 * V_177 = V_20 -> V_177 ;
unsigned long V_271 ;
int V_22 ;
int V_272 ;
F_92 ( & V_2 -> V_273 ) ;
V_18 = F_108 ( V_2 , V_20 ) ;
if ( V_18 == NULL ) {
F_93 ( & V_2 -> V_273 ) ;
return - V_98 ;
}
V_177 -> V_274 = V_275 ;
V_177 -> V_274 . V_276 = V_264 -> V_276 ;
V_177 -> V_274 . V_277 = V_264 -> V_277 ;
V_177 -> V_274 . V_278 = V_264 -> V_278 ;
V_177 -> V_274 . V_279 = V_264 -> V_279 ;
F_126 ( V_177 ) ;
F_127 ( V_177 , V_280 ) ;
F_128 ( V_177 , V_281 ,
20 ,
178000000 ) ;
if ( V_2 -> V_282 )
V_272 = 128 ;
else
V_272 = 4 ;
F_129 ( V_177 , 0 , V_283 ,
V_272 ) ;
F_129 ( V_177 , 0 , V_284 ,
V_272 ) ;
F_130 ( V_251 -> V_232 ) ;
V_22 = V_264 -> V_208 . V_285 ( V_264 , V_251 -> V_232 , V_20 ) ;
if ( V_22 < 0 ) {
F_112 ( V_18 ) ;
F_131 ( V_251 -> V_232 ) ;
F_93 ( & V_2 -> V_273 ) ;
return V_22 ;
}
F_126 ( V_177 ) ;
if ( F_132 ( ! V_177 -> V_274 . V_276 ) ||
F_132 ( ! V_177 -> V_274 . V_277 ) ||
F_132 ( ! V_177 -> V_274 . V_278 ) ||
F_132 ( ! V_177 -> V_274 . V_279 ) ) {
F_112 ( V_18 ) ;
V_264 -> V_208 . V_286 ( V_264 , V_251 -> V_232 , V_20 ) ;
F_131 ( V_251 -> V_232 ) ;
F_93 ( & V_2 -> V_273 ) ;
return - V_164 ;
}
if ( V_20 -> V_240 == V_268 )
V_177 -> V_274 . V_287 &= ~ V_288 ;
F_133 ( & V_2 -> V_26 , V_271 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_148 = 0 ;
F_134 ( & V_2 -> V_26 , V_271 ) ;
V_177 -> V_13 = V_18 ;
F_135 ( V_20 ) ;
F_93 ( & V_2 -> V_273 ) ;
return 0 ;
}
static int F_136 ( struct V_19 * V_20 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_263 * V_264 = V_251 -> V_264 [ V_20 -> V_240 ] ;
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
unsigned long V_271 ;
F_92 ( & V_2 -> V_273 ) ;
F_133 ( & V_2 -> V_26 , V_271 ) ;
V_18 -> V_20 = NULL ;
V_18 -> V_148 = 0 ;
F_134 ( & V_2 -> V_26 , V_271 ) ;
F_112 ( V_18 ) ;
V_264 -> V_208 . V_286 ( V_264 , V_251 -> V_232 , V_20 ) ;
F_131 ( V_251 -> V_232 ) ;
F_93 ( & V_2 -> V_273 ) ;
return 0 ;
}
static int F_137 ( struct V_19 * V_20 ,
struct V_289 * V_290 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
int V_291 ;
F_109 ( V_18 ) ;
if ( F_110 ( V_18 ) ) {
V_291 = - V_98 ;
goto V_292;
}
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_172 = 0 ;
V_18 -> V_168 = 0 ;
V_18 -> V_187 = 0 ;
V_291 = F_138 ( V_20 ,
F_139 ( V_290 ) ) ;
if ( V_291 < 0 )
goto V_292;
F_9 ( V_2 , V_18 , V_20 , true ) ;
V_292:
F_111 ( V_18 ) ;
return V_291 ;
}
static int F_140 ( struct V_19 * V_20 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_263 * V_264 = V_251 -> V_264 [ V_20 -> V_240 ] ;
F_109 ( V_18 ) ;
if ( ! F_110 ( V_18 ) ) {
F_85 ( V_18 , V_170 , 0 ) ;
F_85 ( V_18 , V_171 , 0 ) ;
F_85 ( V_18 , V_105 , 0 ) ;
V_18 -> V_172 = 0 ;
V_18 -> V_168 = 0 ;
V_18 -> V_187 = 0 ;
}
F_141 ( V_251 -> V_232 , V_264 , V_20 ) ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_293 = 0 ;
F_111 ( V_18 ) ;
return F_142 ( V_20 ) ;
}
static int F_143 ( struct V_19 * V_20 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
struct V_263 * V_264 = V_251 -> V_264 [ V_20 -> V_240 ] ;
struct V_176 * V_177 = V_20 -> V_177 ;
unsigned int V_172 , V_168 , V_187 , V_182 ;
int V_22 ;
struct V_294 * V_295 =
F_144 ( V_251 -> V_232 , V_264 -> V_296 ) ;
unsigned short V_297 = V_295 ? V_295 -> V_297 : 0 ;
F_109 ( V_18 ) ;
if ( F_110 ( V_18 ) ) {
V_22 = - V_98 ;
goto V_292;
}
F_87 ( V_2 , V_18 ) ;
V_187 = F_145 ( V_177 -> V_179 ,
V_177 -> V_298 ,
V_177 -> V_299 ,
V_264 -> V_300 ,
V_297 ) ;
if ( ! V_187 ) {
F_14 (KERN_ERR SFX
L_30 ,
pci_name(chip->pci), runtime->rate, runtime->channels, runtime->format) ;
V_22 = - V_164 ;
goto V_292;
}
V_172 = F_146 ( V_20 ) ;
V_168 = F_147 ( V_20 ) ;
F_40 ( V_75 L_31 ,
F_41 ( V_2 -> V_24 ) , V_172 , V_187 ) ;
if ( V_172 != V_18 -> V_172 ||
V_168 != V_18 -> V_168 ||
V_187 != V_18 -> V_187 ||
V_177 -> V_175 != V_18 -> V_175 ) {
V_18 -> V_172 = V_172 ;
V_18 -> V_168 = V_168 ;
V_18 -> V_187 = V_187 ;
V_18 -> V_175 = V_177 -> V_175 ;
V_22 = F_84 ( V_2 , V_20 , V_18 ) ;
if ( V_22 < 0 )
goto V_292;
}
V_18 -> V_301 = ( ( ( V_177 -> V_302 * 24000 ) /
V_177 -> V_179 ) * 1000 ) ;
F_88 ( V_2 , V_18 ) ;
if ( V_20 -> V_240 == V_241 )
V_18 -> V_303 = F_148 ( V_18 , V_304 ) + 1 ;
else
V_18 -> V_303 = 0 ;
V_182 = V_18 -> V_182 ;
if ( ( V_2 -> V_47 & V_48 ) &&
V_182 > V_2 -> V_245 )
V_182 -= V_2 -> V_245 ;
V_22 = F_149 ( V_251 -> V_232 , V_264 , V_182 ,
V_18 -> V_187 , V_20 ) ;
V_292:
if ( ! V_22 )
V_18 -> V_293 = 1 ;
F_111 ( V_18 ) ;
return V_22 ;
}
static int F_150 ( struct V_19 * V_20 , int V_53 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_18 * V_18 ;
struct V_19 * V_305 ;
int V_306 = 0 , V_307 , V_308 = 0 , V_309 = 0 ;
int V_310 , V_65 ;
V_18 = F_117 ( V_20 ) ;
F_151 ( V_2 , V_18 , V_53 ) ;
if ( F_110 ( V_18 ) || ! V_18 -> V_293 )
return - V_311 ;
switch ( V_53 ) {
case V_312 :
V_306 = 1 ;
case V_313 :
case V_314 :
V_307 = 1 ;
break;
case V_315 :
case V_316 :
case V_317 :
V_307 = 0 ;
break;
default:
return - V_164 ;
}
F_152 (s, substream) {
if ( V_305 -> V_198 -> V_223 != V_20 -> V_198 -> V_223 )
continue;
V_18 = F_117 ( V_305 ) ;
V_309 |= 1 << V_18 -> V_113 ;
V_308 ++ ;
F_153 ( V_305 , V_20 ) ;
}
F_76 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_318 )
F_17 ( V_2 , V_319 ,
F_45 ( V_2 , V_319 ) | V_309 ) ;
else
F_17 ( V_2 , V_320 , F_45 ( V_2 , V_320 ) | V_309 ) ;
F_152 (s, substream) {
if ( V_305 -> V_198 -> V_223 != V_20 -> V_198 -> V_223 )
continue;
V_18 = F_117 ( V_305 ) ;
if ( V_307 ) {
V_18 -> V_321 = F_45 ( V_2 , V_252 ) ;
if ( ! V_306 )
V_18 -> V_321 -=
V_18 -> V_301 ;
F_64 ( V_2 , V_18 ) ;
} else {
F_66 ( V_2 , V_18 ) ;
}
V_18 -> V_148 = V_307 ;
}
F_77 ( & V_2 -> V_26 ) ;
if ( V_307 ) {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_310 = 0 ;
F_152 (s, substream) {
if ( V_305 -> V_198 -> V_223 != V_20 -> V_198 -> V_223 )
continue;
V_18 = F_117 ( V_305 ) ;
if ( ! ( F_62 ( V_18 , V_107 ) &
V_322 ) )
V_310 ++ ;
}
if ( ! V_310 )
break;
F_154 () ;
}
} else {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_310 = 0 ;
F_152 (s, substream) {
if ( V_305 -> V_198 -> V_223 != V_20 -> V_198 -> V_223 )
continue;
V_18 = F_117 ( V_305 ) ;
if ( F_62 ( V_18 , V_105 ) &
V_114 )
V_310 ++ ;
}
if ( ! V_310 )
break;
F_154 () ;
}
}
F_76 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_318 )
F_17 ( V_2 , V_319 ,
F_45 ( V_2 , V_319 ) & ~ V_309 ) ;
else
F_17 ( V_2 , V_320 , F_45 ( V_2 , V_320 ) & ~ V_309 ) ;
if ( V_307 ) {
F_116 ( V_20 , 0 , 0 ) ;
if ( V_308 > 1 ) {
T_4 V_262 ;
V_18 = F_117 ( V_20 ) ;
V_262 = V_18 -> V_257 . V_262 ;
F_152 (s, substream) {
if ( V_305 -> V_198 -> V_223 != V_20 -> V_198 -> V_223 )
continue;
F_116 ( V_305 , 1 , V_262 ) ;
}
}
}
F_77 ( & V_2 -> V_26 ) ;
return 0 ;
}
static unsigned int F_155 ( struct V_1 * V_2 ,
struct V_18 * V_18 )
{
unsigned int V_323 , V_324 , V_325 ;
unsigned int V_326 , V_327 , V_328 ;
unsigned int V_303 ;
V_323 = F_89 ( V_18 , V_329 ) ;
if ( V_18 -> V_20 -> V_240 == V_241 ) {
return V_323 ;
}
V_327 = F_30 ( * V_18 -> V_117 ) ;
V_327 %= V_18 -> V_168 ;
V_303 = F_156 ( V_2 -> V_330 + V_331 ) ;
if ( V_18 -> V_112 ) {
if ( V_323 <= V_303 )
return 0 ;
V_18 -> V_112 = 0 ;
}
if ( V_323 <= V_303 )
V_324 = V_18 -> V_172 + V_323 - V_303 ;
else
V_324 = V_323 - V_303 ;
V_328 = V_324 % V_18 -> V_168 ;
V_326 = V_323 % V_18 -> V_168 ;
if ( V_326 >= V_303 )
V_325 = V_323 - V_326 ;
else if ( V_327 >= V_328 )
V_325 = V_324 - V_328 ;
else {
V_325 = V_324 - V_328 + V_18 -> V_168 ;
if ( V_325 >= V_18 -> V_172 )
V_325 = 0 ;
}
return V_325 + V_327 ;
}
static unsigned int F_157 ( struct V_1 * V_2 ,
struct V_18 * V_18 ,
bool V_332 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_196 * V_251 = F_115 ( V_20 ) ;
unsigned int V_333 ;
int V_240 = V_20 -> V_240 ;
struct V_263 * V_264 = V_251 -> V_264 [ V_240 ] ;
int V_334 = 0 ;
switch ( V_2 -> V_189 [ V_240 ] ) {
case V_190 :
V_333 = F_89 ( V_18 , V_329 ) ;
break;
case V_335 :
V_333 = F_155 ( V_2 , V_18 ) ;
break;
default:
V_333 = F_30 ( * V_18 -> V_117 ) ;
if ( V_332 && V_2 -> V_189 [ V_240 ] == V_336 ) {
if ( ! V_333 || V_333 == ( V_29 ) - 1 ) {
F_158 ( V_337
L_32
L_33 ) ;
V_2 -> V_189 [ V_240 ] = V_190 ;
V_333 = F_89 ( V_18 , V_329 ) ;
} else
V_2 -> V_189 [ V_240 ] = V_338 ;
}
break;
}
if ( V_333 >= V_18 -> V_172 )
V_333 = 0 ;
if ( V_20 -> V_177 &&
V_2 -> V_189 [ V_240 ] == V_338 &&
( V_2 -> V_47 & V_339 ) ) {
unsigned int V_340 = F_89 ( V_18 , V_329 ) ;
if ( V_240 == V_241 )
V_334 = V_333 - V_340 ;
else
V_334 = V_340 - V_333 ;
if ( V_334 < 0 )
V_334 += V_18 -> V_172 ;
if ( V_334 >= V_18 -> V_168 ) {
F_14 (KERN_WARNING SFX
L_34
L_35 ,
pci_name(chip->pci), delay, azx_dev->period_bytes) ;
V_334 = 0 ;
V_2 -> V_47 &= ~ V_339 ;
}
V_334 = F_159 ( V_20 -> V_177 , V_334 ) ;
}
if ( V_20 -> V_177 ) {
if ( V_264 -> V_208 . V_267 )
V_334 += V_264 -> V_208 . V_267 ( V_264 , V_251 -> V_232 ,
V_20 ) ;
V_20 -> V_177 -> V_334 = V_334 ;
}
F_160 ( V_2 , V_18 , V_333 , V_334 ) ;
return V_333 ;
}
static T_6 F_161 ( struct V_19 * V_20 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
return F_159 ( V_20 -> V_177 ,
F_157 ( V_2 , V_18 , false ) ) ;
}
static int F_78 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_29 V_341 ;
unsigned int V_333 ;
V_341 = F_45 ( V_2 , V_252 ) - V_18 -> V_321 ;
if ( V_341 < ( V_18 -> V_301 * 2 ) / 3 )
return - 1 ;
V_333 = F_157 ( V_2 , V_18 , true ) ;
if ( F_162 ( ! V_18 -> V_168 ,
L_36 ) )
return - 1 ;
if ( V_341 < ( V_18 -> V_301 * 5 ) / 4 &&
V_333 % V_18 -> V_168 > V_18 -> V_168 / 2 )
return V_173 [ V_2 -> V_174 ] ? 0 : - 1 ;
V_18 -> V_321 += V_341 ;
return 1 ;
}
static void F_163 ( struct V_342 * V_343 )
{
struct V_1 * V_2 = F_114 ( V_343 , struct V_1 , V_152 ) ;
int V_103 , V_344 , V_141 ;
if ( ! V_2 -> V_345 ) {
F_158 ( V_337
L_37
L_38 ,
V_2 -> V_223 -> V_239 ) ;
V_2 -> V_345 = 1 ;
}
for (; ; ) {
V_344 = 0 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
if ( ! V_18 -> V_150 ||
! V_18 -> V_20 ||
! V_18 -> V_148 )
continue;
V_141 = F_78 ( V_2 , V_18 ) ;
if ( V_141 > 0 ) {
V_18 -> V_150 = 0 ;
F_77 ( & V_2 -> V_26 ) ;
F_79 ( V_18 -> V_20 ) ;
F_76 ( & V_2 -> V_26 ) ;
} else if ( V_141 < 0 ) {
V_344 = 0 ;
} else
V_344 ++ ;
}
F_21 ( & V_2 -> V_26 ) ;
if ( ! V_344 )
return;
F_37 ( 1 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
int V_103 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ )
V_2 -> V_18 [ V_103 ] . V_150 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
}
static int F_165 ( struct V_19 * V_20 ,
struct V_346 * V_7 )
{
struct V_196 * V_251 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_251 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_7 -> V_347 = F_166 ( V_7 -> V_347 ) ;
return F_167 ( V_20 , V_7 ) ;
}
static void F_168 ( struct V_348 * V_198 )
{
struct V_196 * V_251 = V_198 -> V_13 ;
if ( V_251 ) {
F_169 ( & V_251 -> V_349 ) ;
F_170 ( V_251 ) ;
}
}
static int
V_212 ( struct V_56 * V_57 , struct V_231 * V_232 ,
struct V_350 * V_351 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_348 * V_198 ;
struct V_196 * V_251 ;
int V_352 = V_351 -> V_238 ;
unsigned int V_158 ;
int V_305 , V_22 ;
F_97 (apcm, &chip->pcm_list, list) {
if ( V_251 -> V_198 -> V_238 == V_352 ) {
F_14 (KERN_ERR SFX L_39 ,
pci_name(chip->pci), pcm_dev) ;
return - V_98 ;
}
}
V_22 = F_171 ( V_2 -> V_223 , V_351 -> V_353 , V_352 ,
V_351 -> V_240 [ V_241 ] . V_354 ,
V_351 -> V_240 [ V_268 ] . V_354 ,
& V_198 ) ;
if ( V_22 < 0 )
return V_22 ;
F_172 ( V_198 -> V_353 , V_351 -> V_353 , sizeof( V_198 -> V_353 ) ) ;
V_251 = F_173 ( sizeof( * V_251 ) , V_355 ) ;
if ( V_251 == NULL )
return - V_356 ;
V_251 -> V_2 = V_2 ;
V_251 -> V_198 = V_198 ;
V_251 -> V_232 = V_232 ;
V_198 -> V_13 = V_251 ;
V_198 -> V_357 = F_168 ;
if ( V_351 -> V_358 == V_359 )
V_198 -> V_360 = V_361 ;
F_174 ( & V_251 -> V_349 , & V_2 -> V_362 ) ;
V_351 -> V_198 = V_198 ;
for ( V_305 = 0 ; V_305 < 2 ; V_305 ++ ) {
V_251 -> V_264 [ V_305 ] = & V_351 -> V_240 [ V_305 ] ;
if ( V_351 -> V_240 [ V_305 ] . V_354 )
F_175 ( V_198 , V_305 , & V_363 ) ;
}
V_158 = V_364 * 1024 ;
if ( V_158 > V_365 )
V_158 = V_365 ;
F_176 ( V_198 , V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_158 , V_365 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
return F_178 ( V_2 -> V_57 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
V_18 -> V_117 = ( V_29 V_366 * ) ( V_2 -> V_117 . V_7 + V_103 * 8 ) ;
V_18 -> V_367 = V_2 -> V_330 + ( 0x20 * V_103 + 0x80 ) ;
V_18 -> V_147 = 1 << V_103 ;
V_18 -> V_113 = V_103 ;
V_18 -> V_182 = V_103 + 1 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_368 )
{
if ( F_180 ( V_2 -> V_24 -> V_78 , F_74 ,
V_2 -> V_77 ? 0 : V_369 ,
V_370 , V_2 ) ) {
F_158 ( V_83 L_40
L_41 , V_2 -> V_24 -> V_78 ) ;
if ( V_368 )
F_181 ( V_2 -> V_223 ) ;
return - 1 ;
}
V_2 -> V_78 = V_2 -> V_24 -> V_78 ;
F_182 ( V_2 -> V_24 , ! V_2 -> V_77 ) ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_115 )
return;
F_60 ( V_2 ) ;
F_63 ( V_2 ) ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_116 , 0 ) ;
F_17 ( V_2 , V_118 , 0 ) ;
V_2 -> V_115 = 0 ;
}
static struct V_18 *
F_183 ( struct V_1 * V_2 )
{
return & V_2 -> V_18 [ V_2 -> V_242 ] ;
}
static int V_218 ( struct V_56 * V_57 , unsigned int V_299 ,
unsigned int V_371 ,
struct V_3 * V_372 )
{
V_29 * V_160 ;
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 ;
int V_22 ;
V_18 = F_183 ( V_2 ) ;
F_109 ( V_18 ) ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_148 || V_18 -> V_373 ) {
F_21 ( & V_2 -> V_26 ) ;
V_22 = - V_98 ;
goto V_292;
}
V_18 -> V_293 = 0 ;
V_2 -> V_374 = * V_18 ;
V_18 -> V_373 = 1 ;
F_21 ( & V_2 -> V_26 ) ;
V_22 = F_12 ( V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_371 , V_372 ) ;
if ( V_22 < 0 )
goto V_375;
F_8 ( V_2 , V_372 , true ) ;
V_18 -> V_172 = V_371 ;
V_18 -> V_168 = V_371 ;
V_18 -> V_187 = V_299 ;
F_87 ( V_2 , V_18 ) ;
F_85 ( V_18 , V_170 , 0 ) ;
F_85 ( V_18 , V_171 , 0 ) ;
V_18 -> V_162 = 0 ;
V_160 = ( V_29 * ) V_18 -> V_160 . V_7 ;
V_22 = F_81 ( V_2 , V_372 , V_18 , & V_160 , 0 , V_371 , 0 ) ;
if ( V_22 < 0 )
goto error;
F_88 ( V_2 , V_18 ) ;
F_111 ( V_18 ) ;
return V_18 -> V_182 ;
error:
F_8 ( V_2 , V_372 , false ) ;
F_184 ( V_372 ) ;
V_375:
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_246 )
* V_18 = V_2 -> V_374 ;
V_18 -> V_373 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
V_292:
F_111 ( V_18 ) ;
return V_22 ;
}
static void V_220 ( struct V_56 * V_57 , bool V_307 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_183 ( V_2 ) ;
if ( V_307 )
F_64 ( V_2 , V_18 ) ;
else
F_66 ( V_2 , V_18 ) ;
V_18 -> V_148 = V_307 ;
}
static void V_222 ( struct V_56 * V_57 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_183 ( V_2 ) ;
if ( ! V_4 -> V_7 || ! V_18 -> V_373 )
return;
F_109 ( V_18 ) ;
F_85 ( V_18 , V_170 , 0 ) ;
F_85 ( V_18 , V_171 , 0 ) ;
F_85 ( V_18 , V_105 , 0 ) ;
V_18 -> V_172 = 0 ;
V_18 -> V_168 = 0 ;
V_18 -> V_187 = 0 ;
F_8 ( V_2 , V_4 , false ) ;
F_184 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_246 )
* V_18 = V_2 -> V_374 ;
V_18 -> V_373 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
F_111 ( V_18 ) ;
}
static void V_216 ( struct V_56 * V_57 , bool V_376 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( ! ( V_2 -> V_47 & V_142 ) )
return;
if ( V_376 )
F_185 ( & V_2 -> V_24 -> V_9 ) ;
else
F_186 ( & V_2 -> V_24 -> V_9 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_92 ( & V_377 ) ;
F_188 ( & V_2 -> V_349 , & V_378 ) ;
F_93 ( & V_377 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_92 ( & V_377 ) ;
F_190 ( & V_2 -> V_349 ) ;
F_93 ( & V_377 ) ;
}
static int F_191 ( const char * V_58 , const struct V_379 * V_380 )
{
struct V_1 * V_2 ;
struct V_231 * V_204 ;
int V_381 = V_214 ;
int V_291 = F_192 ( V_58 , V_380 ) ;
if ( V_291 || V_381 == V_214 )
return V_291 ;
F_92 ( & V_377 ) ;
F_97 (chip, &card_list, list) {
if ( ! V_2 -> V_57 || V_2 -> V_92 )
continue;
F_97 (c, &chip->bus->codec_list, list)
F_193 ( V_204 ) ;
}
F_93 ( & V_377 ) ;
return 0 ;
}
static int F_194 ( struct V_238 * V_9 )
{
struct V_119 * V_24 = F_195 ( V_9 ) ;
struct V_382 * V_223 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_223 -> V_13 ;
struct V_196 * V_197 ;
if ( V_2 -> V_92 )
return 0 ;
F_197 ( V_223 , V_383 ) ;
F_164 ( V_2 ) ;
F_97 (p, &chip->pcm_list, list)
F_98 ( V_197 -> V_198 ) ;
if ( V_2 -> V_115 )
F_99 ( V_2 -> V_57 ) ;
F_95 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_78 >= 0 ) {
F_42 ( V_2 -> V_78 , V_2 ) ;
V_2 -> V_78 = - 1 ;
}
if ( V_2 -> V_77 )
F_43 ( V_2 -> V_24 ) ;
F_198 ( V_24 ) ;
F_199 ( V_24 ) ;
F_200 ( V_24 , V_384 ) ;
if ( V_2 -> V_47 & V_385 )
F_201 ( false ) ;
return 0 ;
}
static int F_202 ( struct V_238 * V_9 )
{
struct V_119 * V_24 = F_195 ( V_9 ) ;
struct V_382 * V_223 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_223 -> V_13 ;
if ( V_2 -> V_92 )
return 0 ;
if ( V_2 -> V_47 & V_385 )
F_201 ( true ) ;
F_200 ( V_24 , V_386 ) ;
F_203 ( V_24 ) ;
if ( F_204 ( V_24 ) < 0 ) {
F_158 ( V_83 L_42
L_41 ) ;
F_181 ( V_223 ) ;
return - V_59 ;
}
F_205 ( V_24 ) ;
if ( V_2 -> V_77 )
if ( F_206 ( V_24 ) < 0 )
V_2 -> V_77 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 )
return - V_59 ;
F_71 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
F_100 ( V_2 -> V_57 ) ;
F_197 ( V_223 , V_387 ) ;
return 0 ;
}
static int F_207 ( struct V_238 * V_9 )
{
struct V_382 * V_223 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_223 -> V_13 ;
if ( V_2 -> V_92 )
return 0 ;
if ( ! ( V_2 -> V_47 & V_142 ) )
return 0 ;
F_20 ( V_2 , V_388 , F_27 ( V_2 , V_388 ) |
V_97 ) ;
F_95 ( V_2 ) ;
F_53 ( V_2 ) ;
F_164 ( V_2 ) ;
if ( V_2 -> V_47 & V_385 )
F_201 ( false ) ;
return 0 ;
}
static int F_208 ( struct V_238 * V_9 )
{
struct V_382 * V_223 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_223 -> V_13 ;
struct V_56 * V_57 ;
struct V_231 * V_232 ;
int V_139 ;
if ( V_2 -> V_92 )
return 0 ;
if ( ! ( V_2 -> V_47 & V_142 ) )
return 0 ;
if ( V_2 -> V_47 & V_385 )
F_201 ( true ) ;
V_139 = F_27 ( V_2 , V_96 ) ;
F_71 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
V_57 = V_2 -> V_57 ;
if ( V_139 && V_57 ) {
F_97 (codec, &bus->codec_list, list)
if ( V_139 & ( 1 << V_232 -> V_28 ) )
F_209 ( V_232 -> V_57 -> V_151 ,
& V_232 -> V_389 , V_232 -> V_233 ) ;
}
F_20 ( V_2 , V_388 , F_27 ( V_2 , V_388 ) &
~ V_97 ) ;
return 0 ;
}
static int F_210 ( struct V_238 * V_9 )
{
struct V_382 * V_223 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_223 -> V_13 ;
if ( V_2 -> V_92 )
return 0 ;
if ( ! V_390 ||
! ( V_2 -> V_47 & V_142 ) )
return - V_98 ;
return 0 ;
}
static int F_211 ( struct V_391 * V_392 , unsigned long V_393 , void * V_17 )
{
struct V_1 * V_2 = F_114 ( V_392 , struct V_1 , V_394 ) ;
F_212 ( V_2 -> V_57 ) ;
F_95 ( V_2 ) ;
return V_395 ;
}
static void F_213 ( struct V_1 * V_2 )
{
V_2 -> V_394 . V_396 = F_211 ;
F_214 ( & V_2 -> V_394 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
if ( V_2 -> V_394 . V_396 )
F_216 ( & V_2 -> V_394 ) ;
}
static void F_217 ( struct V_119 * V_24 ,
enum V_397 V_398 )
{
struct V_382 * V_223 = F_218 ( V_24 ) ;
struct V_1 * V_2 = V_223 -> V_13 ;
bool V_92 ;
F_219 ( & V_2 -> V_399 ) ;
if ( V_2 -> V_400 )
return;
V_92 = ( V_398 == V_401 ) ;
if ( V_2 -> V_92 == V_92 )
return;
if ( ! V_2 -> V_57 ) {
V_2 -> V_92 = V_92 ;
if ( ! V_92 ) {
F_14 (KERN_INFO SFX
L_43 ,
pci_name(chip->pci)) ;
if ( F_220 ( V_2 ) < 0 ) {
F_14 (KERN_ERR SFX
L_44 ,
pci_name(chip->pci)) ;
V_2 -> V_400 = true ;
}
}
} else {
F_14 (KERN_INFO SFX
L_45 , pci_name(chip->pci),
disabled ? L_46 : L_47 ) ;
if ( V_92 ) {
F_221 ( & V_24 -> V_9 ) ;
F_194 ( & V_24 -> V_9 ) ;
V_24 -> V_402 = V_403 ;
V_2 -> V_92 = true ;
if ( F_222 ( V_2 -> V_57 ) )
F_14 (KERN_WARNING SFX L_48 ,
pci_name(chip->pci)) ;
} else {
F_223 ( V_2 -> V_57 ) ;
F_224 ( & V_24 -> V_9 ) ;
V_2 -> V_92 = false ;
F_202 ( & V_24 -> V_9 ) ;
}
}
}
static bool F_225 ( struct V_119 * V_24 )
{
struct V_382 * V_223 = F_218 ( V_24 ) ;
struct V_1 * V_2 = V_223 -> V_13 ;
F_219 ( & V_2 -> V_399 ) ;
if ( V_2 -> V_400 )
return false ;
if ( V_2 -> V_92 || ! V_2 -> V_57 )
return true ;
if ( F_222 ( V_2 -> V_57 ) )
return false ;
F_223 ( V_2 -> V_57 ) ;
return true ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_119 * V_197 = F_227 ( V_2 -> V_24 ) ;
if ( V_197 ) {
F_14 (KERN_INFO SFX
L_49 ,
pci_name(chip->pci)) ;
V_2 -> V_404 = 1 ;
F_228 ( V_197 ) ;
}
}
static int F_229 ( struct V_1 * V_2 )
{
int V_22 ;
if ( ! V_2 -> V_404 )
return 0 ;
V_22 = F_230 ( V_2 -> V_24 , & V_405 ,
V_406 ,
V_2 -> V_57 != NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_407 = 1 ;
F_231 ( & V_2 -> V_24 -> V_9 , & V_2 -> V_408 ) ;
return 0 ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_119 * V_24 = V_2 -> V_24 ;
int V_103 ;
if ( ( V_2 -> V_47 & V_142 )
&& V_2 -> V_148 )
F_224 ( & V_24 -> V_9 ) ;
F_189 ( V_2 ) ;
F_215 ( V_2 ) ;
V_2 -> V_400 = 1 ;
F_233 ( & V_2 -> V_399 ) ;
if ( V_404 ( V_2 ) ) {
if ( V_2 -> V_92 && V_2 -> V_57 )
F_223 ( V_2 -> V_57 ) ;
if ( V_2 -> V_407 )
F_234 ( V_2 -> V_24 ) ;
}
if ( V_2 -> V_115 ) {
F_164 ( V_2 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ )
F_66 ( V_2 , & V_2 -> V_18 [ V_103 ] ) ;
F_95 ( V_2 ) ;
}
if ( V_2 -> V_78 >= 0 )
F_42 ( V_2 -> V_78 , ( void * ) V_2 ) ;
if ( V_2 -> V_77 )
F_43 ( V_2 -> V_24 ) ;
if ( V_2 -> V_330 )
F_235 ( V_2 -> V_330 ) ;
if ( V_2 -> V_18 ) {
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ )
if ( V_2 -> V_18 [ V_103 ] . V_160 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_18 [ V_103 ] . V_160 , false ) ;
F_184 ( & V_2 -> V_18 [ V_103 ] . V_160 ) ;
}
}
if ( V_2 -> V_25 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_25 , false ) ;
F_184 ( & V_2 -> V_25 ) ;
}
if ( V_2 -> V_117 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_117 , false ) ;
F_184 ( & V_2 -> V_117 ) ;
}
if ( V_2 -> V_409 )
F_236 ( V_2 -> V_24 ) ;
F_198 ( V_2 -> V_24 ) ;
F_170 ( V_2 -> V_18 ) ;
#ifdef F_237
if ( V_2 -> V_410 )
F_238 ( V_2 -> V_410 ) ;
#endif
if ( V_2 -> V_47 & V_385 ) {
F_201 ( false ) ;
F_239 () ;
}
F_170 ( V_2 ) ;
return 0 ;
}
static int F_240 ( struct V_411 * V_238 )
{
return F_232 ( V_238 -> V_412 ) ;
}
static struct V_119 * F_227 ( struct V_119 * V_24 )
{
struct V_119 * V_197 ;
switch ( V_24 -> V_413 ) {
case V_414 :
case V_415 :
case V_416 :
if ( V_24 -> V_417 == 1 ) {
V_197 = F_241 ( F_242 ( V_24 -> V_57 ) ,
V_24 -> V_57 -> V_239 , 0 ) ;
if ( V_197 ) {
if ( ( V_197 -> V_418 >> 8 ) == V_419 )
return V_197 ;
F_228 ( V_197 ) ;
}
}
break;
}
return NULL ;
}
static bool F_243 ( struct V_119 * V_24 )
{
bool V_420 = false ;
struct V_119 * V_197 = F_227 ( V_24 ) ;
if ( V_197 ) {
if ( F_244 ( V_197 ) == V_401 )
V_420 = true ;
F_228 ( V_197 ) ;
}
return V_420 ;
}
static int F_245 ( struct V_1 * V_2 , int V_421 )
{
const struct V_422 * V_423 ;
switch ( V_421 ) {
case V_336 :
case V_190 :
case V_338 :
case V_335 :
case V_424 :
return V_421 ;
}
V_423 = F_246 ( V_2 -> V_24 , V_425 ) ;
if ( V_423 ) {
F_158 ( V_426
L_50
L_51 ,
V_423 -> V_427 , V_423 -> V_428 , V_423 -> V_429 ) ;
return V_423 -> V_427 ;
}
if ( V_2 -> V_47 & V_430 ) {
F_48 ( V_75 L_52 , F_41 ( V_2 -> V_24 ) ) ;
return V_335 ;
}
if ( V_2 -> V_47 & V_431 ) {
F_48 ( V_75 L_53 , F_41 ( V_2 -> V_24 ) ) ;
return V_190 ;
}
return V_336 ;
}
static void F_247 ( struct V_1 * V_2 , int V_9 )
{
const struct V_422 * V_423 ;
V_2 -> V_228 = V_432 [ V_9 ] ;
if ( V_2 -> V_228 == - 1 ) {
V_423 = F_246 ( V_2 -> V_24 , V_433 ) ;
if ( V_423 ) {
F_158 ( V_426
L_54
L_51 ,
V_423 -> V_427 , V_423 -> V_428 , V_423 -> V_429 ) ;
V_2 -> V_228 = V_423 -> V_427 ;
}
}
if ( V_2 -> V_228 != - 1 &&
( V_2 -> V_228 & V_434 ) ) {
V_2 -> V_99 = V_2 -> V_228 & 0xff ;
F_158 ( V_426 L_55 ,
V_2 -> V_99 ) ;
}
}
static void F_248 ( struct V_1 * V_2 )
{
const struct V_422 * V_423 ;
if ( V_435 >= 0 ) {
V_2 -> V_77 = ! ! V_435 ;
return;
}
V_2 -> V_77 = 1 ;
V_423 = F_246 ( V_2 -> V_24 , V_436 ) ;
if ( V_423 ) {
F_158 ( V_426
L_56 ,
V_423 -> V_428 , V_423 -> V_429 , V_423 -> V_427 ) ;
V_2 -> V_77 = V_423 -> V_427 ;
return;
}
if ( V_2 -> V_47 & V_437 ) {
F_158 ( V_426 L_57 ) ;
V_2 -> V_77 = 0 ;
}
}
static void F_249 ( struct V_1 * V_2 )
{
bool V_135 = V_2 -> V_135 ;
switch ( V_2 -> V_226 ) {
case V_438 :
if ( V_135 ) {
T_2 V_58 ;
F_69 ( V_2 -> V_24 , 0x42 , & V_58 ) ;
if ( ! ( V_58 & 0x80 ) && V_2 -> V_24 -> V_439 == 0x30 )
V_135 = false ;
}
break;
case V_440 :
V_135 = false ;
break;
case V_441 :
V_135 = false ;
break;
}
if ( V_135 != V_2 -> V_135 ) {
F_14 (KERN_INFO SFX L_58 ,
pci_name(chip->pci), snoop ? L_59 : L_60 ) ;
V_2 -> V_135 = V_135 ;
}
}
static void F_250 ( struct V_342 * V_343 )
{
F_220 ( F_114 ( V_343 , struct V_1 , V_442 ) ) ;
}
static int F_251 ( struct V_382 * V_223 , struct V_119 * V_24 ,
int V_9 , unsigned int V_47 ,
struct V_1 * * V_443 )
{
static struct V_444 V_208 = {
. V_445 = F_240 ,
} ;
struct V_1 * V_2 ;
int V_22 ;
* V_443 = NULL ;
V_22 = F_204 ( V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 = F_173 ( sizeof( * V_2 ) , V_355 ) ;
if ( ! V_2 ) {
F_14 (KERN_ERR SFX L_61 , pci_name(pci)) ;
F_198 ( V_24 ) ;
return - V_356 ;
}
F_252 ( & V_2 -> V_26 ) ;
F_253 ( & V_2 -> V_273 ) ;
V_2 -> V_223 = V_223 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_78 = - 1 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_226 = V_47 & 0xff ;
F_248 ( V_2 ) ;
V_2 -> V_174 = V_9 ;
F_254 ( & V_2 -> V_152 , F_163 ) ;
F_255 ( & V_2 -> V_362 ) ;
F_255 ( & V_2 -> V_349 ) ;
F_226 ( V_2 ) ;
F_256 ( & V_2 -> V_399 ) ;
V_2 -> V_189 [ 0 ] = V_2 -> V_189 [ 1 ] =
F_245 ( V_2 , V_189 [ V_9 ] ) ;
if ( V_2 -> V_189 [ 0 ] == V_424 ) {
V_2 -> V_189 [ 0 ] = V_190 ;
V_2 -> V_189 [ 1 ] = V_336 ;
}
F_247 ( V_2 , V_9 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_135 = V_446 ;
F_249 ( V_2 ) ;
if ( V_173 [ V_9 ] < 0 ) {
switch ( V_2 -> V_226 ) {
case V_447 :
case V_448 :
V_173 [ V_9 ] = 1 ;
break;
default:
V_173 [ V_9 ] = 32 ;
break;
}
}
V_22 = F_257 ( V_223 , V_449 , V_2 , & V_208 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_62 ,
pci_name(chip->pci)) ;
F_232 ( V_2 ) ;
return V_22 ;
}
#ifdef F_258
F_254 ( & V_2 -> V_442 , F_250 ) ;
#endif
* V_443 = V_2 ;
return 0 ;
}
static int F_259 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_174 ;
struct V_119 * V_24 = V_2 -> V_24 ;
struct V_382 * V_223 = V_2 -> V_223 ;
int V_103 , V_22 ;
unsigned short V_450 ;
#if V_451 != 64
if ( V_2 -> V_226 == V_452 ) {
T_7 V_453 ;
F_72 ( V_24 , 0x40 , & V_453 ) ;
F_73 ( V_24 , 0x40 , V_453 | 0x10 ) ;
F_260 ( V_24 , V_454 , 0 ) ;
}
#endif
V_22 = F_261 ( V_24 , L_63 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_409 = 1 ;
V_2 -> V_28 = F_262 ( V_24 , 0 ) ;
V_2 -> V_330 = F_263 ( V_24 , 0 ) ;
if ( V_2 -> V_330 == NULL ) {
F_14 (KERN_ERR SFX L_64 , pci_name(chip->pci)) ;
return - V_235 ;
}
if ( V_2 -> V_77 )
if ( F_206 ( V_24 ) < 0 )
V_2 -> V_77 = 0 ;
if ( F_44 ( V_2 , 0 ) < 0 )
return - V_98 ;
F_205 ( V_24 ) ;
F_264 ( V_2 -> V_78 ) ;
V_450 = F_27 ( V_2 , V_455 ) ;
F_40 ( V_75 L_65 , F_41 ( V_2 -> V_24 ) , V_450 ) ;
if ( V_2 -> V_24 -> V_413 == V_414 ) {
struct V_119 * V_456 ;
V_456 = F_265 ( V_414 ,
V_457 ,
NULL ) ;
if ( V_456 ) {
if ( V_456 -> V_439 < 0x30 )
V_450 &= ~ V_458 ;
F_228 ( V_456 ) ;
}
}
if ( V_2 -> V_47 & V_459 ) {
F_48 ( V_75 L_66 , F_41 ( V_2 -> V_24 ) ) ;
V_450 &= ~ V_458 ;
}
if ( V_282 >= 0 )
V_2 -> V_282 = ! ! V_282 ;
else {
if ( V_2 -> V_47 & V_460 )
V_2 -> V_282 = 0 ;
else if ( V_2 -> V_47 & V_461 )
V_2 -> V_282 = 1 ;
else
V_2 -> V_282 = 1 ;
}
if ( ( V_450 & V_458 ) && ! F_266 ( V_24 , F_267 ( 64 ) ) )
F_268 ( V_24 , F_267 ( 64 ) ) ;
else {
F_266 ( V_24 , F_267 ( 32 ) ) ;
F_268 ( V_24 , F_267 ( 32 ) ) ;
}
V_2 -> V_245 = ( V_450 >> 8 ) & 0x0f ;
V_2 -> V_243 = ( V_450 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_243 && ! V_2 -> V_245 ) {
switch ( V_2 -> V_226 ) {
case V_452 :
V_2 -> V_243 = V_462 ;
V_2 -> V_245 = V_463 ;
break;
case V_464 :
case V_440 :
V_2 -> V_243 = V_465 ;
V_2 -> V_245 = V_466 ;
break;
case V_467 :
default:
V_2 -> V_243 = V_468 ;
V_2 -> V_245 = V_469 ;
break;
}
}
V_2 -> V_244 = 0 ;
V_2 -> V_242 = V_2 -> V_245 ;
V_2 -> V_104 = V_2 -> V_243 + V_2 -> V_245 ;
V_2 -> V_18 = F_269 ( V_2 -> V_104 , sizeof( * V_2 -> V_18 ) ,
V_355 ) ;
if ( ! V_2 -> V_18 ) {
F_14 (KERN_ERR SFX L_67 , pci_name(chip->pci)) ;
return - V_356 ;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
F_270 ( & V_2 -> V_18 [ V_103 ] ) ;
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_470 , & V_2 -> V_18 [ V_103 ] . V_160 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_68 , pci_name(chip->pci)) ;
return - V_356 ;
}
F_8 ( V_2 , & V_2 -> V_18 [ V_103 ] . V_160 , true ) ;
}
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_2 -> V_104 * 8 , & V_2 -> V_117 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_69 , pci_name(chip->pci)) ;
return - V_356 ;
}
F_8 ( V_2 , & V_2 -> V_117 , true ) ;
V_22 = F_11 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
F_179 ( V_2 ) ;
F_71 ( V_2 ) ;
F_67 ( V_2 , ( V_471 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_99 ) {
F_14 (KERN_ERR SFX L_70 , pci_name(chip->pci)) ;
return - V_472 ;
}
strcpy ( V_223 -> V_473 , L_71 ) ;
F_172 ( V_223 -> V_474 , V_475 [ V_2 -> V_226 ] ,
sizeof( V_223 -> V_474 ) ) ;
snprintf ( V_223 -> V_476 , sizeof( V_223 -> V_476 ) ,
L_72 ,
V_223 -> V_474 , V_2 -> V_28 , V_2 -> V_78 ) ;
return 0 ;
}
static void F_271 ( struct V_1 * V_2 )
{
#ifdef F_96
struct V_231 * V_232 ;
F_97 (codec, &chip->bus->codec_list, list) {
F_131 ( V_232 ) ;
}
#endif
}
static void F_272 ( const struct V_477 * V_410 , void * V_478 )
{
struct V_382 * V_223 = V_478 ;
struct V_1 * V_2 = V_223 -> V_13 ;
struct V_119 * V_24 = V_2 -> V_24 ;
if ( ! V_410 ) {
F_14 (KERN_ERR SFX L_73 ,
pci_name(chip->pci)) ;
goto error;
}
V_2 -> V_410 = V_410 ;
if ( ! V_2 -> V_92 ) {
if ( F_220 ( V_2 ) )
goto error;
}
return;
error:
F_273 ( V_223 ) ;
F_274 ( V_24 , NULL ) ;
}
static int F_275 ( struct V_119 * V_24 ,
const struct V_479 * V_480 )
{
static int V_9 ;
struct V_382 * V_223 ;
struct V_1 * V_2 ;
bool V_481 ;
int V_22 ;
if ( V_9 >= V_482 )
return - V_472 ;
if ( ! V_483 [ V_9 ] ) {
V_9 ++ ;
return - V_484 ;
}
V_22 = F_276 ( V_113 [ V_9 ] , V_485 [ V_9 ] , V_486 , 0 , & V_223 ) ;
if ( V_22 < 0 ) {
F_14 ( V_83 L_74 ) ;
return V_22 ;
}
F_277 ( V_223 , & V_24 -> V_9 ) ;
V_22 = F_251 ( V_223 , V_24 , V_9 , V_480 -> V_487 , & V_2 ) ;
if ( V_22 < 0 )
goto V_488;
V_223 -> V_13 = V_2 ;
F_274 ( V_24 , V_223 ) ;
V_22 = F_229 ( V_2 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX
L_75 , pci_name(pci)) ;
goto V_488;
}
if ( F_243 ( V_24 ) ) {
F_14 (KERN_INFO SFX L_76 ,
pci_name(pci)) ;
F_14 (KERN_INFO SFX L_77 , pci_name(pci)) ;
V_2 -> V_92 = true ;
}
V_481 = ! V_2 -> V_92 ;
#ifdef F_237
if ( V_489 [ V_9 ] && * V_489 [ V_9 ] ) {
F_14 (KERN_ERR SFX L_78 ,
pci_name(pci), patch[dev]) ;
V_22 = F_278 ( V_486 , true , V_489 [ V_9 ] ,
& V_24 -> V_9 , V_355 , V_223 ,
F_272 ) ;
if ( V_22 < 0 )
goto V_488;
V_481 = false ;
}
#endif
if ( V_481 && ( V_2 -> V_47 & V_385 ) ) {
#ifdef F_258
V_481 = false ;
F_279 ( & V_2 -> V_442 ) ;
#else
F_14 (KERN_ERR SFX L_79 ) ;
#endif
}
if ( V_481 ) {
V_22 = F_220 ( V_2 ) ;
if ( V_22 < 0 )
goto V_488;
}
V_9 ++ ;
F_233 ( & V_2 -> V_399 ) ;
return 0 ;
V_488:
F_273 ( V_223 ) ;
return V_22 ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_119 * V_24 = V_2 -> V_24 ;
int V_9 = V_2 -> V_174 ;
int V_22 ;
if ( V_2 -> V_47 & V_385 ) {
#ifdef F_258
V_22 = F_280 () ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_80 ) ;
goto V_488;
}
#endif
F_201 ( true ) ;
}
V_22 = F_259 ( V_2 ) ;
if ( V_22 < 0 )
goto V_488;
#ifdef F_281
V_2 -> V_234 = V_234 [ V_9 ] ;
#endif
V_22 = F_102 ( V_2 , V_201 [ V_9 ] ) ;
if ( V_22 < 0 )
goto V_488;
#ifdef F_237
if ( V_2 -> V_410 ) {
V_22 = F_282 ( V_2 -> V_57 , V_2 -> V_410 -> V_158 ,
V_2 -> V_410 -> V_122 ) ;
if ( V_22 < 0 )
goto V_488;
#ifndef F_96
F_238 ( V_2 -> V_410 ) ;
V_2 -> V_410 = NULL ;
#endif
}
#endif
if ( ( V_471 [ V_9 ] & 1 ) == 0 ) {
V_22 = F_106 ( V_2 ) ;
if ( V_22 < 0 )
goto V_488;
}
V_22 = F_283 ( V_2 -> V_57 ) ;
if ( V_22 < 0 )
goto V_488;
V_22 = F_177 ( V_2 ) ;
if ( V_22 < 0 )
goto V_488;
V_22 = F_284 ( V_2 -> V_223 ) ;
if ( V_22 < 0 )
goto V_488;
V_2 -> V_148 = 1 ;
F_271 ( V_2 ) ;
F_213 ( V_2 ) ;
F_187 ( V_2 ) ;
if ( ( V_2 -> V_47 & V_142 ) || V_2 -> V_404 )
F_285 ( & V_24 -> V_9 ) ;
return 0 ;
V_488:
V_2 -> V_400 = 1 ;
return V_22 ;
}
static void F_286 ( struct V_119 * V_24 )
{
struct V_382 * V_223 = F_218 ( V_24 ) ;
if ( V_223 )
F_273 ( V_223 ) ;
}
